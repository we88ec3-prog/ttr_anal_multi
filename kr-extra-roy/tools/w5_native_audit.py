#!/usr/bin/env python3
"""W5 KR original BIN read-only targeted native-source validation.
Limited to byte windows & reward jump table, not complete CFG/FULL-PASS.
No game execution, mutation, network, or negative/load tests.
"""
from pathlib import Path
import argparse,struct,hashlib,json
SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
# Native instruction windows at reviewed boundaries. All VA map only through .text.
WINDOWS = {
 0x504D96:'8d 4b ff',0x504D99:'83 f9 05',0x504D9E:'ff 24 8d 54 55 50 00',
 0x504DE2:'89 84 24 e4 00 00 00',0x504DEB:'89 84 24 e8 00 00 00',
 0x504DF4:'89 84 24 ec 00 00 00',0x504DFD:'89 84 24 e0 00 00 00',
 0x504E06:'89 84 24 f0 00 00 00',0x504E0F:'89 84 24 f4 00 00 00',
 0x502DBA:'83 7f 08 03',0x502DD0:'8d 45 dc',0x502DE8:'e8 53 d4 ff ff',
 0x503403:'8b 45 08',0x50340D:'8d be b0 5e 00 00',0x503413:'e8 c8 80 f4 ff',
 0x503425:'e8 16 ce ff ff',0x5021A2:'8b 8b b4 5e 00 00',0x5021D1:'8b 5c 24 10',
 0x44AA53:'ba 01 00 00 00',0x500652:'8b 50 24',0x500690:'0f b7 18',
 0x5B6E60:'55 8b ec',0x5B6F61:'6a 03',
 0x4B8923:'8b 4d 0c',0x4B8992:'0f b6 07',0x4E2767:'0f b6 47 2e',
 0x4D4154:'c7 46 5c 01 00 00 00',0x4B89F7:'6a 03',0x4B8ADB:'6a 02',
 0x61C7C0:'55 8b ec',0x61C900:'0f b7 74 4a 04',0x61CA4A:'8b 11 8b 82 9c 01 00 00',
 0x61CA52:'6a 01 56 57 ff d0'
}
JUMPS={1:0x504DE2,2:0x504DF4,3:0x504DEB,4:0x504DFD,5:0x504E06,6:0x504E0F}
QUEST_REWARD_RECORD_OFFSETS={1:0x80,2:0x88,3:0x84,4:0x7C,5:0x8C,6:0x90}

def audit(path):
 d=Path(path).read_bytes()
 assert len(d)==12472320, 'Unexpected size'
 assert hashlib.sha256(d).hexdigest()==SHA, 'Unexpected KR BIN'
 assert d[:2]==b'MZ'
 nt=struct.unpack_from('<I',d,0x3c)[0]
 assert d[nt:nt+4]==b'PE\0\0'
 assert struct.unpack_from('<H',d,nt+4)[0]==0x14c
 assert struct.unpack_from('<I',d,nt+24+28)[0]==0x400000
 n=struct.unpack_from('<H',d,nt+6)[0]
 sec=nt+24+struct.unpack_from('<H',d,nt+20)[0]
 sh={}
 for i in range(n):
  p=sec+i*40
  key=d[p:p+8].split(b'\0')[0].decode('ascii')
  sh[key]=struct.unpack_from('<IIII',d,p+8)
 assert sh['.text']==(0x7D01F0,0x1000,0x7D0200,0x400)
 for va,hexbytes in WINDOWS.items():
  off=va-0x400C00
  expected=bytes.fromhex(hexbytes)
  assert d[off:off+len(expected)]==expected, hex(va)
 jump_results={}
 for ty,tgt in JUMPS.items():
  v=struct.unpack_from('<I',d,0x505554-0x400C00+4*(ty-1))[0]
  assert v==tgt, ('reward-target',ty,hex(v))
  jump_results[str(ty)]={'target':hex(v),'quest_record_offset':hex(QUEST_REWARD_RECORD_OFFSETS[ty])}
 return {'result':'PASS','input_sha256':SHA,'limited_native_byte_windows':len(WINDOWS),
         'reward_table_cases':len(JUMPS),'reward_type_mapping':jump_results,
         'role_full_header_bytes':65,'role_record_stride_bytes':53,
         'role_delta_header_bytes':2,
         'notes':'Read-only native bytes only; no character recruitment or skill/equipment acquisition wire proven.'}
if __name__=='__main__':
 a=argparse.ArgumentParser(description=__doc__)
 a.add_argument('original_bin',type=Path)
 x=a.parse_args()
 print(json.dumps(audit(x.original_bin),ensure_ascii=False,indent=2))
