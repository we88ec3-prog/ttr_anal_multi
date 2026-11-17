#!/usr/bin/env python3
"""Verify the pinned normal-binding ABI against original KR bytes, offline."""
from pathlib import Path
import argparse,collections,json,re,struct,sys
sys.dont_write_bytecode=True
from native_support import PE,need,sha
HERE=Path(__file__).resolve().parent

def run(binary):
 pe=PE(binary);e=json.loads((HERE/'native-evidence.json').read_text());c=json.loads((HERE/'abi-contracts.json').read_text());windows={w['id']:w for w in e['windows']};count=0
 for w in windows.values():
  a=int(w['va'],16);z=int(w['end_exclusive'],16);b=pe.at(a,z-a)
  need(z-a==w['size']and pe.raw(a)==int(w['raw'],16)and b.hex()==w['hex']and sha(b)==w['sha256'],'Raw window '+w['id'])
  rows=pe.decode(a,z);need(rows==w['instructions'],'Instruction decoding '+w['id']);cursor=a
  for x in rows:
   need(int(x['va'],16)==cursor and '(bad)'not in x['asm'],'Instruction boundary '+w['id']);cursor+=len(bytes.fromhex(x['hex']))
  need(cursor==z,'Endpoint '+w['id']);count+=len(rows)
 seen=set();new=0;query=0
 for r in c['bindings']:
  need(r['name']not in seen,'Unique name');seen.add(r['name'])
  reg=int(r['registrar'],16);slot=int(r['slot'],16);native=int(r['native'],16);cl=int(r['closure'],16)
  need(struct.unpack('<I',pe.at(reg+26,4))[0]==slot and struct.unpack('<I',pe.at(reg+30,4))[0]==native and struct.unpack('<I',pe.at(reg+106,4))[0]==cl,'Registrar tuple '+r['name'])
  nameva=struct.unpack('<I',pe.at(reg+89,4))[0];raw=pe.raw(nameva);name=pe.b[raw:pe.b.index(0,raw)].decode('ascii')
  need(name==r['name'].split('.',1)[1],'Native name '+r['name'])
  w=windows[r['evidence_records'][0]];need(int(w['va'],16)==cl,'Closure pointer');calls=[]
  for x in w['instructions']:
   b=bytes.fromhex(x['hex']);v=int(x['va'],16)
   if len(b)==5 and b[0]==0xe8:calls.append(v+5+struct.unpack('<i',b[1:])[0])
  want=[]if r['marshaller']is None else[int(r['marshaller'],16)];need(calls==want,'Marshaller transfer '+r['name'])
  need(any(x['asm']=='mov    eax,0x1'for x in w['instructions'])and r['closure_result_count']==1,'Lua result count')
  out=windows[r['evidence_records'][1]]if r['marshaller']in('0x4a2a70','0x4acf90','0x56b590')else w
  pushes=[x['va']for x in out['instructions']if re.match(r'add\s+DWORD PTR \[e[a-z]{2}\+0x8\],0x10$',x['asm'])]
  need(pushes==r['output_evidence']and bool(pushes)==r['produces_new_lua_value'],'Output producer '+r['name'])
  need(r['relative_stack_indices']==list(range(-r['argument_count'],0))and len(r['argument_kinds'])==r['argument_count'],'Arity index shape')
  if pushes:new+=1;query+=r['name']!='lb.DoFile'
 for x in c['marshaller_checks']:
  w=windows['F_'+format(int(x['marshaller'],16),'08X')];ii=w['instructions']
  intsites=[r['va']for r in ii if r['asm'].startswith('fistp ')];strings=[r['va']for r in ii if r['asm']=='call   0x6fb5d0'];floats=[r['va']for r in ii if r['asm'].startswith('fstp   DWORD')];truth=[r['va']for r in ii if r['asm']=='cmp    edx,0x1']
  need(intsites==x['integer_conversion_sites']and len(intsites)==x['argument_kinds'].count('integer32'),'Integer conversions')
  need(strings==x['string_conversion_sites']and len(strings)==x['argument_kinds'].count('string'),'String conversions')
  need(floats==x['float_store_sites']and truth==x['truthiness_check_sites'],'Float/truthiness anchors')
  need(len(floats)==2*x['argument_kinds'].count('float32')+(1 if x['marshaller']=='0x56b590'else 0),'Float input/output stores')
  n=len(x['argument_kinds']);expected_i=[j-n for j,k in enumerate(x['argument_kinds'])if k=='integer32'][::-1];expected_f=[j-n for j,k in enumerate(x['argument_kinds'])if k=='float32'][::-1]
  need([q['index']for q in x['integer_input_reads']]==expected_i and [q['index']for q in x['float_input_reads']]==expected_f,'Exact numeric input positions')
  instruction_map={q['va']:q['asm']for q in ii}
  for q in x['integer_input_reads']:
   need(instruction_map[q['reader_call']]=='call   0x6f50f0','Index reader call')
   raw_index=int(instruction_map[q['constant_site']].split(',0x')[1],16);signed=raw_index-(1<<32)if raw_index>0x7fffffff else raw_index
   need(signed==q['index'],'Integer index immediate')
  for q in x['float_input_reads']:
   if 'top_adjust'in q:need(instruction_map[q['top_adjust']]=='sub    eax,0x10'and instruction_map[q['tag_read']]=='mov    ecx,DWORD PTR [eax+0x8]'and q['index']==-1,'Last float input')
   else:
    displacement=int(re.search(r'-0x([0-9a-f]+)',instruction_map[q['tag_read']])[1],16);need(-(displacement+8)//16==q['index']and displacement%16==8,'Float tag position')
  if 'lua_truthiness'in x['argument_kinds']:need(x['marshaller']=='0x6be090'and truth==['0x6be0b6'],'Truthiness exception')
 need(len(seen)==121 and new==17 and query==16,'Coverage partition')
 return dict(status='PASS',scope='Original-byte identity, decoded windows, registered tuples, ABI conversion and value-producer evidence; not gameplay or whole-program semantic certification',binary_sha256=e['source_bin_sha256'],bindings=len(seen),marshallers=len(c['marshaller_checks']),new_numeric_value_producers=new,observation_queries=query,no_new_binding_value=121-new,native_windows=len(windows),native_bytes=sum(w['size']for w in windows.values()),decoded_instructions=count,client_executed=False,lua_executed=False,server_executed=False)
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--bin',required=True,type=Path);a=p.parse_args();print(json.dumps(run(a.bin),ensure_ascii=False,indent=2))
