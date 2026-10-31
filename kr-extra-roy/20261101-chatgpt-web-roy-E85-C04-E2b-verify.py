#!/usr/bin/env python3
"""RR1/4/6/7 / C04-E2b: KR native bounded source audit plus synthetic C2S vectors.
Usage: python -B E85-C04-E2b-verify.py /path/Tartaros.bin
No Client execution, network, packet capture or credential logging.
"""
import sys,hashlib,struct,json
from pathlib import Path
p=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin'); b=p.read_bytes()
H='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==H and len(b)==12472320
pe=struct.unpack_from('<I',b,0x3c)[0];assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\x00\x00'
sections={};off=pe+24+struct.unpack_from('<H',b,pe+20)[0]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
 t=off+40*i;name=b[t:t+8].split(b'\x00')[0].decode();vs,va,rawsize,raw=struct.unpack_from('<IIII',b,t+8);sections[name]=(0x400000+va,vs,rawsize,raw)
def read(va,n):
 for name,(start,vs,sz,raw) in sections.items():
  if start<=va and va+n<=start+sz:return b[raw+va-start:raw+va-start+n]
 raise ValueError(f'outside mapped raw {va:x}')
def dword(a):return struct.unpack('<I',read(a,4))[0]
def hx(a,s):return read(a,len(bytes.fromhex(s)))==bytes.fromhex(s)
def cal(a,target):return read(a,1)==b'\xe8' and a+5+struct.unpack('<i',read(a+1,4))[0]==target
checks=[]
def ck(n,val):
 checks.append((n,bool(val)))
 if not val:raise AssertionError(n)
ck('PE sections',sections['.text'][:3]==(0x401000,0x7d01f0,0x7d0200))
ck('manager vtable exact base',all(dword(0xc51748+i*4)==v for i,v in enumerate((0x806670,0x806cf0,0x806850,0x8068b0,0x8069a0,0x806a00,0x806ad0,0x806f60,0x806f80,0x806fc0,0x807090))))
for a,s,desc in [
 (0x495751,'6a026a0168df20000052','key1 connect lane2 slot1 port8415'),
 (0x49575b,'ffd0','key1 Connect indirect vtable+0x18'),
 (0x49575d,'8bf0','key1 conn returned'),
 (0x49575f,'3bf7','key1 null gate'),
 (0x495781,'8b0d54a8fb00','key1 recv-registration owner'),
 (0x49578f,'68f4010000','key1 Sleep500'),
 (0x495794,'89b360bf0000','key1 stores client+BF60'),
 (0x4956b8,'397d10','key1 optional shutdown flag'),
 (0x4956f7,'6a0157ffd2','key0 shutdown key gate'),
 (0x495707,'6a016a02ffd2','key2 shutdown'),
 (0x6d6508,'e803f1dbff','key1 caller 6D6508'),
 (0x6d65c8,'e843f0dbff','key1 caller 6D65C8'),
 (0x6d6563,'6a38','key1 caller first candidate len 56'),
 (0x6d6683,'6a68','key1 caller alternate len104'),
 (0x6d6340,'c7400852000000','mode object init 0x52'),
 (0x440793,'8b4108','auth mode object+8'),
 (0x440796,'83f852','mode52 E8 branch'),
 (0x4407cb,'83f854','mode54/other F branch'),
 (0x4a34fc,'6a70','E8 login app112'),
 (0x4a3503,'6a01','E8 login to slot1'),
 (0x4a32b6,'68d6000000','0F login app214'),
 (0x4a32c2,'6a01','0F login slot1'),
 (0x8069b1,'8d4e18','queue manager key map+18'),
 (0x8069d7,'85c0','manager queue zero len special return'),
 (0x8069eb,'e8e0f6ffff','manager queue to 8060D0'),
 (0x8060fa,'81bea4a000002c010000','queue throttle A0A4<=300'),
 (0x80615b,'81fb00100000','queue <=4096 check'),
 (0x80616c,'e85f7a0900','queue payload memcpy'),
 (0x806174,'895f04','queue stores actual len when <=4096'),
 (0x8061e6,'8b8674a00000','framer queue head A074'),
 (0x8061f6,'8b7b08','framer payload node'),
 (0x8061f9,'8b5704','framer payload length'),
 (0x805d02,'c6862ca0000002','fresh conn mode byte2'),
 (0x806202,'0fbe862ca00000','mode byte read signed'),
 (0x806218,'7415','mode 0 raw'),
 (0x806223,'e808160000','mode nonzero encode BBB'),
 (0x80622a,'7523','successful BBB bypasses raw'),
 (0x80623a,'e831180000','fallback raw 1A68'),
 (0x806246,'0f8458010000','failed two writers preserves queue'),
 (0x806275,'ff8e78a00000','successful frame queue count dec'),
 (0x807887,'3d00100000','BBB max n+6 4096'),
 (0x8078a2,'81fa00400000','BBB cumulative <=16384'),
 (0x8078ff,'8ad0','BBB first byte original in AL'),
 (0x807901,'80f2b6','BBB XOR seed B6'),
 (0x8079ef,'668b85f8efffff','BBB plaintext checksum read'),
 (0x8079f8,'66894104','BBB checksum header+4'),
 (0x804ac8,'83beaca0000000','pump connected state A0AC'),
 (0x804ad6,'e8c5160000','pump calls framer'),
 (0x804b21,'83be28a0000000','pump frame TX A028'),
 (0x804b2e,'8b86b8a00000','pump A0B8 in flight gate'),
 (0x804b4a,'8b520c','pump vtable+0C WSASend'),
 (0x804b52,'8d8620500000','send data starts conn+5020'),
 (0x805228,'e8730f0000','alternate pump framer'),
 (0x8052ac,'ffd2','alternate pump manager WSASend'),
 (0x8068d1,'83bea8a0000000','WSASend closing gate'),
 (0x8068de,'8d8650a00000','WSASend OVERLAPPED+ A050'),
 (0x8068f7,'8d4814','WSABUF +A064'),
 (0x806912,'ff15b825bd00','WSASend IAT'),
 (0x80692d,'81ffe5030000','WSA_IO_PENDING=997'),
 (0x806968,'ff158422bd00','pending count increment'),
 (0x806981,'ff158422bd00','sync success count increment'),
 (0x806b25,'8b4514','Connect lane arg'),
 (0x806b33,'898380a00000','Conn+A080 lane writer'),
 (0x806b54,'8b450c','Connect port arg'),
 (0x806b65,'ff15a825bd00','htons ordinal9'),
 (0x806b8c,'ff15c425bd00','connect ordinal4'),
 (0x806c87,'ff157822bd00','IOCP bind'),
 (0x806e08,'e8330d0000','IOCP receive parser 807B40'),
 (0x807bd4,'0fb74b02','inbound marker read'),
 (0x807d66,'66394b04','inbound BBB checksum compare'),
 (0x804b5a,'ffd2','pump manager send virtual'),
 ]:ck(desc,hx(a,s))
ck('frame mode literal direct references', [hex(0x401000+i) for i in range(len(b[0x400:0x7d0600])-3) if b[0x400+i:0x404+i]==bytes.fromhex('2ca00000')]==['0x805d04','0x806205'])
# encoded payload vs framed wire (synthetic, NOT captured KR traffic)
def enc(data):
 assert 0<len(data)<=4090
 return struct.pack('<HHH',len(data),0xbbb,sum(data)&65535)+bytes([data[0]^0xb6]+[data[i]^data[i-1] for i in range(1,len(data))])
def dec(data):
 n,m,c=struct.unpack_from('<HHH',data)
 assert m==0xbbb and 0<n<=4090 and len(data)==6+n
 out=bytearray();last=0xb6
 for x in data[6:]:last=x^last;out.append(last)
 assert sum(out)&65535==c
 return bytes(out)
for n in (1,2,4,56,57,112,214,4090):
 data=bytes((i*13+5)%256 for i in range(n))
 ck(f'synthetic BBB {n} roundtrip',dec(enc(data))==data)
ck('synthetic BBB sample',enc(bytes.fromhex('0100'))==bytes.fromhex('0200bb0b0100b701'))
bad=bytearray(enc(b'abc'));bad[4]^=1
try:dec(bad);bad_ok=False
except AssertionError:bad_ok=True
ck('bad checksum actually rejected in synthetic decoder',bad_ok)
ck('synthetic 1A68 sample',struct.pack('<HH',2,0x1a68)+b'\x01\x00'==bytes.fromhex('0200681a0100'))
for n in (0,4090,4091,4092,4093):
 allowed=(n>0 and n+6<=4096,n>0 and n+4<=4096)
 ck(f'writer length transition {n}',allowed=={0:(False,False),4090:(True,True),4091:(False,True),4092:(False,True),4093:(False,False)}[n])
print(json.dumps({'bin_sha256':H,'checks':len(checks),'result':'PASS','scope':'KR Client bounded source bytes plus explicit SYNTHETIC tests; NOT runtime, original Server, or T01 full pass'}))
