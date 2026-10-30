#!/usr/bin/env python3
"""E71 RR-0010: read-only KR PE source checks; NOT original Server wire or Client runtime.
usage: python E71-RR0010-verify.py Tartaros.bin
"""
import sys,struct,hashlib,json
from pathlib import Path
p=Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b=p.read_bytes()
expected='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==expected
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\0\0'
assert struct.unpack_from('<H',b,pe+24)[0]==0x10b
n=struct.unpack_from('<H',b,pe+6)[0];offset=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sections={}
for i in range(n):
    off=offset+40*i;name=b[off:off+8].split(b'\0')[0].decode()
    size,va,rawsize,raw=struct.unpack_from('<IIII',b,off+8)
    sections[name]=(va+0x400000,size,rawsize,raw)
def read(va,n):
    for name,(v,size,rawsize,off) in sections.items():
        if v<=va and va+n<=v+rawsize:return b[off+va-v:off+va-v+n]
    raise ValueError('VA outside PE raw-backed sections: '+hex(va))
def u32(va):return struct.unpack('<I',read(va,4))[0]
def rtti(vptr):
    col=u32(vptr-4);typ=u32(col+12)
    return read(typ+8,96).split(b'\0')[0].decode('ascii')
def direct(target):
    v,vs,sz,off=sections['.text'];data=b[off:off+sz]
    return [v+i for i in range(len(data)-4) if data[i]==0xe8 and v+i+5+struct.unpack_from('<i',data,i+1)[0]==target]
def rawhex(va,text):return read(va,len(bytes.fromhex(text)))==bytes.fromhex(text)
checks={}
def ck(name,ok):
    checks[name]=bool(ok)
    if not ok:raise AssertionError(name)
ck('source PE32 .text mapping',sections['.text'][0]==0x401000 and sections['.text'][3]==0x400)
ck('CEmploy RTTI native',rtti(0xC3F024)=='.?AVCEmployNewCharacter@FUI@@')
ck('CCharChange RTTI native',rtti(0xC33C74)=='.?AVCCharChangeDialog@FUI@@')
ck('CEmploy local event vtable slot87',u32(0xC3F024+87*4)==0x6BF2A0)
ck('shared event vtable slot80',u32(0xC3F024+80*4)==u32(0xC33C74+80*4)==0x65D550)
ck('CEmploy click event0x578',rawhex(0x6BF2A6,'81781078050000'))
ck('CEmploy click source control +D0',rawhex(0x6BF2B2,'8b8ed0000000') and rawhex(0x6BF2BB,'3b5120'))
ck('CEmploy branch based Client+5F4C',rawhex(0x6BF2C0,'e8db58d4ff') and rawhex(0x6BF2C5,'83b84c5f000001'))
ck('CEmploy else path calls 0x4A38D0',rawhex(0x6BF2F5,'e88653d5ff') and rawhex(0x6BF2FA,'e8d145deff'))
ck('CEmploy alternate UI-only path',rawhex(0x6BF2CE,'e85dbfddff') and rawhex(0x6BF2D5,'e806080000') and rawhex(0x6BF2DF,'e82cc2ecff'))
ck('0x33 sender opcode store',rawhex(0x4A38DB,'b833000000') and rawhex(0x4A38E0,'668945fe'))
ck('0x33 sender Conn gate',rawhex(0x4A38D4,'833d98a7fb0000') and rawhex(0x4A38E4,'7515'))
ck('0x33 sender length2 slot0',rawhex(0x4A38F1,'6a02') and rawhex(0x4A38F6,'50') and rawhex(0x4A38F7,'6a00') and rawhex(0x4A38F9,'ffd2'))
ck('0x33 sender direct-call footprint',direct(0x4A38D0)==[0x6BF2FA])
ck('0x21 variable builder opcode store',rawhex(0x4A3A0A,'b821000000') and rawhex(0x4A3A0F,'668985e8efffff'))
ck('0x21 two user subbyte input',rawhex(0x4A3A07,'8a4d08') and rawhex(0x4A3A16,'8a450c'))
ck('0x21 vector element selector',rawhex(0x4A3A68,'8b06') and rawhex(0x4A3A6A,'0fb608'))
ck('0x21 TLV 3/103 size',rawhex(0x4A3A73,'8d4a67') and rawhex(0x4A3A7E,'6a67') and rawhex(0x4A3A99,'8d4a03'))
ck('0x21 0x1000 cap',rawhex(0x4A3A76,'81f900100000') and rawhex(0x4A3A9C,'81f900100000'))
ck('0x21 send via virtual v10',rawhex(0x4A3B18,'8b01') and rawhex(0x4A3B1A,'8b4010') and rawhex(0x4A3B27,'ffd0'))
ck('0x21 direct caller plural',direct(0x4A39F0)==[0x45D018,0x577988,0x5FF6E4,0x60049B,0x6004ED,0x600AE3,0x6010F2,0x6092B4,0x60AB5A,0x651F64,0x8FEA9F])
ck('0x21 world action 5FF6 state gate',rawhex(0x5FF6A4,'817f14a7060000') and rawhex(0x5FF6E4,'e80743eaff'))
ck('0x27 dedicated builder request opcode',rawhex(0x4A373E,'b927000000') and rawhex(0x4A3743,'66898df8efffff'))
ck('0x27 bounded single caller',direct(0x4A3720)==[0x682A3F] and rawhex(0x682A3F,'e8dc0ce2ff'))
ck('select existing role is 0x42 separately',direct(0x4A3B80)==[0x5F47F5,0x5F48F7,0x673EAA])
ck('S2C first layer table default',rawhex(0x4B7DC0,'b8002dfd00') and rawhex(0x4B7DD0,'8950fc') and rawhex(0x4B7DD5,'83c008'))
ck('S2C first layer command2 override',rawhex(0x4B7DDF,'c7050c2dfd00007f4b00'))
ck('S2C first layer 0x33 not overridden in init',bytes.fromhex('942efd00') not in read(0x4B7DC0,0x100))
ck('S2C first-layer default requires active scene',rawhex(0x4B7EC3,'83b9ac5e000000') and rawhex(0x4B7ED2,'8b01'))
ck('roster 65+53n N0 branch',rawhex(0x4B8926,'83f941') and rawhex(0x4B894A,'85c9') and rawhex(0x4B894C,'0f84ce000000'))
ck('roster row name flag and 53B stride',rawhex(0x4B89AD,'e89eb70100') and rawhex(0x4D4154,'c7465c01000000') and rawhex(0x4B8A0E,'83c735'))
ck('roster result common post',rawhex(0x4B8A60,'66a34042f900') and rawhex(0x4B8A9C,'e80fd50200'))
ck('CEmploy lazy init not roster direct callee',direct(0x5AB020)==[0x5AAD11,0x5C30FD])
ck('CEmploy cached constructor',rawhex(0x5AB2E4,'c70724f0c300') and rawhex(0x5AB2F1,'c746041b010000'))
assert len(checks)==34,len(checks)
print(json.dumps({'source_sha256':expected,'assertions':len(checks),'passed':all(checks.values()),'checks':checks,'client_runtime_tested':False,'original_server_capture':False,'create_request_reply_pair_confirmed':False,'direct_callers':{hex(t):[hex(v) for v in direct(t)] for t in [0x4A38D0,0x4A39F0,0x4A3720,0x4A3B80,0x5AB020]}},ensure_ascii=False,indent=2))
