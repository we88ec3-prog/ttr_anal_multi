#!/usr/bin/env python3
"""R14 read-only original evidence checks, not game/Lua/Server execution.
STPD/Lua inspection adapted from the repository's pinned R2 parser:
kr-extra-roy/MEF-parser-executor-storage-20261114/verify_evidence.py
blob 8e6e3c51c55a0bb155f05165b496d7d519fb7b7e.
Requires Python 3 and GNU objdump. No network or repository mutation.
Assertions are intentional; optimized Python is rejected.
"""
import argparse, re, subprocess, sys
import xml.etree.ElementTree as ET
if sys.flags.optimize:
    raise RuntimeError("Run without Python -O: assertions are validation checks")
from pathlib import Path
import struct,zlib,hashlib,json

def sha(b):return hashlib.sha256(b).hexdigest()
def ex_decode(data):
 if data[:2]!=b'EX':return data
 mode=data[2];n,size,off=struct.unpack_from('<III',data,4)
 assert mode in (0,1) and off>=16 and off+n<=len(data)
 payload=data[off:off+n]
 if mode:
  key=[0x30,0xe7]
  for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
  payload=bytes(v^key[i%1024] for i,v in enumerate(payload))
 result=zlib.decompress(payload);assert len(result)==size
 return result
class STP:
 def __init__(self,path):
  self.path=Path(path);raw=self.path.read_bytes();assert raw[:4]==b'STPD'
  self.sha=sha(raw);self.b=bytes(x^255 for x in raw);b=self.b;idx=struct.unpack_from('<I',b,4)[0]
  assert raw[idx:idx+4]==b'STPI';p=idx+8;self.files={}
  def node(parent):
   nonlocal p
   n=struct.unpack_from('<H',b,p)[0];p+=2
   name=b[p:p+n].decode('ascii').rstrip('\0');p+=n;kind=b[p];p+=1;path='/'.join(filter(None,[parent,name]))
   if kind in (1,2):
    count=struct.unpack_from('<I',b,p)[0];p+=12
    for _ in range(count):node(path)
   elif kind==0:
    _,ident=struct.unpack_from('<II',b,p);p+=16;self.files[path]=ident
   else:raise ValueError(kind)
  node('');assert p==len(b)
  table=struct.unpack_from('>I',b,12)[0];n=struct.unpack_from('<I',b,table)[0]
  self.blocks={}
  for i in range(n):
   ident,size,first,last=struct.unpack_from('<4I',b,table+4+i*32);self.blocks[ident]=(size,first,last)
 def get(self,name):
  ident=self.files[name];size,first,last=self.blocks[ident];off=16+first*1024
  assert size<=(last-first+1)*1024
  raw=self.b[off:off+size];decoded=ex_decode(raw)
  return decoded,dict(carrier=self.path.name,carrier_sha256=self.sha,path=name,block_id=ident,stored_offset=off,stored_length=size,first_block=first,last_block=last,stored_sha256=sha(raw),decoded_length=len(decoded),decoded_sha256=sha(decoded),prefix=decoded[:12].hex())

def lua(data):
 assert data[:12].hex()=='1b4c75615100010404040800'
 pos=12;protos=[]
 def take(fmt):
  nonlocal pos
  r=struct.unpack_from('<'+fmt,data,pos);pos+=struct.calcsize('<'+fmt);return r
 def string():
  nonlocal pos
  n=take('I')[0]
  if not n:return None
  assert pos+n<=len(data) and data[pos+n-1]==0
  s=data[pos:pos+n-1].decode('utf-8',errors='backslashreplace');pos+=n;return s
 def proto(parent):
  nonlocal pos
  i=len(protos);p=dict(index=i,parent=parent,start=pos);protos.append(p)
  p['source']=string();p['first'],p['last']=take('II');p['nups'],p['params'],p['vararg'],p['stack']=take('BBBB')
  n=take('I')[0];p['code_offset']=pos;p['words']=list(take('I'*n));p['constants']=[]
  for _ in range(take('I')[0]):
   t=take('B')[0]
   v=None if t==0 else bool(take('B')[0]) if t==1 else take('d')[0] if t==3 else string() if t==4 else (_ for _ in ()).throw(ValueError(t))
   p['constants'].append(v)
  p['children']=[proto(i) for _ in range(take('I')[0])]
  p['lines']=list(take('I'*take('I')[0]));p['locals']=[]
  for _ in range(take('I')[0]):
   name=string();a,z=take('II');p['locals'].append(dict(name=name,start=a,end=z))
  p['upvalue_names']=[string() for _ in range(take('I')[0])];p['end']=pos
  return i
 proto(None);assert pos==len(data);return protos

BIN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
EVENT_SHA = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
TABLE_SHA = "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"

def edge_state(old, current):
    return ((old | 0x40) >> 6) if old != current else ((old >> 6) & 2)

def candidate(enabled, mode, latch, inside, press):
    # Derived finite-state model of 544730, not execution of the original code.
    if not enabled: return 0, 0, latch
    if (mode == 0 and press == 0) or not inside:
        changed = int(mode == 0 or latch != 0 or inside)
        return 0, changed, 0
    return 1, int(latch == 0), 1

def run(args):
    folder = Path(__file__).resolve().parent
    ne = json.loads((folder/'native-evidence.json').read_text())
    revidence = json.loads((folder/'resource-evidence.json').read_text())
    b=Path(args.bin).read_bytes()
    assert sha(b)==BIN_SHA==ne['binary_sha256'], 'KR BIN identity'
    pe=struct.unpack_from('<I',b,0x3c)[0]
    assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\0\0'
    assert struct.unpack_from('<H',b,pe+4)[0]==0x14c
    opt=pe+24;assert struct.unpack_from('<H',b,opt)[0]==0x10b
    base=struct.unpack_from('<I',b,opt+28)[0];assert base==0x400000
    ss=opt+struct.unpack_from('<H',b,pe+20)[0];sections=[]
    for i in range(struct.unpack_from('<H',b,pe+6)[0]):
        vs,rva,size,raw=struct.unpack_from('<IIII',b,ss+i*40+8)
        sections.append((base+rva,size,raw))
    def offset(va,size):
        matches=[r+va-v for v,n,r in sections if v<=va and va+size<=v+n]
        assert len(matches)==1, ('raw mapping',hex(va));return matches[0]
    def at(va,size):
        pos=offset(va,size);return b[pos:pos+size]
    def u32(va):return struct.unpack('<I',at(va,4))[0]
    starts=set();total_instructions=0
    for name,va,raw,size,h,count in ne['windows']:
        a=int(va,0);end=a+size
        assert offset(a,size)==int(raw,0) and sha(at(a,size))==h, name
        text=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',
              '--start-address='+hex(a),'--stop-address='+hex(end),args.bin],text=True)
        rows=[]
        for line in text.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if m: rows.append((int(m[1],16),bytes.fromhex(m[2]),m[3]))
        cursor=a
        for v,code,asm in rows:
            assert v==cursor and at(v,len(code))==code and '(bad)' not in asm, name
            starts.add(v);cursor+=len(code)
        assert cursor==end and len(rows)==count, name
        total_instructions+=len(rows)
    for name,va,raw,code in ne['anchors']+ne['data']:
        a=int(va,0);code=bytes.fromhex(code)
        assert offset(a,len(code))==int(raw,0) and at(a,len(code))==code, name
        if [name,va,raw,code.hex()] in ne['anchors']: assert a in starts, name
    for va,s in ne['strings']:
        expected=s.encode('ascii')+b'\0';assert at(int(va,0),len(expected))==expected, s
    for site,target in ne['calls']:
        a=int(site,0);code=at(a,5)
        assert a in starts and code[0]==0xe8
        assert a+5+struct.unpack_from('<i',code,1)[0]==int(target,0),site
    assert u32(0xc0fb1c+0x2c)==0x548cb0
    assert u32(0xc0f7fc+0x64)==0x544070
    assert at(0x5443dd,6)==bytes.fromhex('8b0da4a7fb00')
    assert at(0x5443e3,11)==bytes.fromhex('c78481b400000001000000')
    assert at(0x548cde,7)==bytes.fromhex('80b8e107000001')
    assert 0x7e1-0x7d4==13 and (0xdc-0xb4)//4==10
    tables={'Event.stp':STP(args.event),'Table.stp':STP(args.table)}
    assert tables['Event.stp'].sha==EVENT_SHA and tables['Table.stp'].sha==TABLE_SHA
    lua_words=0;slices=0;counts={}
    for record in revidence['resources']:
        m=record['member'];decoded,actual=tables[m['carrier']].get(m['path'])
        assert actual==m, m['path']
        if 'slices' in record:
            ps=lua(decoded);assert len(ps)==record['prototype_count']
            counts[m['path']]=len(ps)
            for item in record['slices']:
                p=ps[item['prototype']];a=item['pc_begin'];z=item['pc_end']
                assert [f'{w:08x}' for w in p['words'][a:z]]==item['words']
                for k,v in item['constants'].items():assert p['constants'][int(k)]==v
                lua_words+=z-a;slices+=1
        else:
            root=ET.fromstring(decoded)
            if m['path'].endswith('TutCheckPointList.xml'):
                actual=[{k:x.attrib[k] for k in ('id','active')}for x in root.iter('CheckPoint')]
                assert all('category' not in x.attrib for x in root.iter('CheckPoint'))
                assert actual==record['selected_attributes']
            else:
                actual=[dict(type=t.attrib,row=x.attrib)for t in root.iter('Type')
                        for x in t.iter('Key')if x.get('MapButton')=='13']
                assert actual==record['selected_attributes'] and root.get('DefaultType')=='0'
    edge_cases=[(0,0,0),(0,128,1),(128,128,2),(128,0,3)]
    for old,new,want in edge_cases: assert edge_state(old,new)==want
    cases=[((0,1,1,True,0),(0,0,1)),((1,1,0,True,0),(1,1,1)),
           ((1,1,1,True,0),(1,0,1)),((1,1,1,False,0),(0,1,0)),
           ((1,0,0,True,0),(0,1,0)),((1,0,0,True,1),(1,1,1)),
           ((1,0,1,True,0),(0,1,0)),((1,1,0,False,0),(0,0,0))]
    for inputs,want in cases: assert candidate(*inputs)==want
    # Two overlapping auto candidates both latch before winner dispatch; no original VM is run.
    flags=[candidate(1,1,0,True,0) for _ in range(2)]
    assert flags==[(1,1,1),(1,1,1)]
    assert [candidate(1,1,x[2],True,0)for x in flags]==[(1,0,1),(1,0,1)]
    return dict(status='PASS',scope='Original identity, bounded bytes/decoding, selected Lua/XML structure and derived state-model checks',
       original_bin_sha256=BIN_SHA,native_windows=len(ne['windows']),
       native_window_bytes=sum(x[3]for x in ne['windows']),decoded_instructions=total_instructions,
       byte_anchors=len(ne['anchors']),data_windows=len(ne['data']),strings=len(ne['strings']),
       direct_calls=len(ne['calls']),selected_members=len(revidence['resources']),
       lua_prototypes=counts,selected_lua_slices=slices,selected_lua_words=lua_words,
       synthetic_edge_cases=len(edge_cases),synthetic_candidate_cases=len(cases),synthetic_overlap_cases=1,
       client_executed=False,lua_executed=False,server_executed=False,
       limits=['Not T01 FULL-PASS, formal semantic proof or gameplay acceptance',
               'Synthetic models are derived checks, not original Client execution',
               'Official MEF first loader/grammar remains unproved',
               'Tutorial controller/context only; not an ordinary-world event API'])

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--bin',required=True);p.add_argument('--event',required=True);p.add_argument('--table',required=True)
    print(json.dumps(run(p.parse_args()),ensure_ascii=False,indent=2))
