"""Read STPD indexes and EX XML payloads without modifying game archives.

Native format references:715480/715C60 index;7188D0 block table;
72F424..72F54A EX key generation and zlib decompression.
"""
from pathlib import Path
import struct,zlib
def ex_decode(data):
    if data[:2]!=b'EX':return data
    mode=data[2];compressed,expanded,offset=struct.unpack_from('<III',data,4)
    assert mode in (0,1) and offset>=16 and offset+compressed<=len(data)
    payload=data[offset:offset+compressed]
    if mode:
        key=[0x30,0xe7]
        for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
        payload=bytes(v^key[i%1024] for i,v in enumerate(payload))
    result=zlib.decompress(payload)
    assert len(result)==expanded
    return result
class Archive:
    def __init__(self,path):
        self.path=Path(path);raw=self.path.read_bytes();assert raw[:4]==b'STPD'
        self.data=bytes(v^255 for v in raw);self.files={}
        index=struct.unpack_from('<I',self.data,4)[0]
        # STPI tag itself stays unencoded, the tree begins after its4+4 header.
        assert raw[index:index+4]==b'STPI'
        pos=index+8
        def node(parent):
            nonlocal pos
            length=struct.unpack_from('<H',self.data,pos)[0];pos+=2
            name=self.data[pos:pos+length].decode('ascii').rstrip('\0');pos+=length
            kind=self.data[pos];pos+=1
            path='/'.join(filter(None,(parent,name)))
            if kind in (1,2):
                count=struct.unpack_from('<I',self.data,pos)[0];pos+=12
                for _ in range(count):node(path)
            elif kind==0:
                _,ident=struct.unpack_from('<II',self.data,pos);pos+=16
                self.files[path]=ident
            else:raise ValueError((path,kind))
        node('');assert pos==len(self.data),(pos,len(self.data))
        table=struct.unpack_from('>I',self.data,12)[0]
        count=struct.unpack_from('<I',self.data,table)[0]
        self.blocks={}
        for i in range(count):
            ident,size,first,last=struct.unpack_from('<4I',self.data,table+4+i*32)
            assert ident not in self.blocks
            self.blocks[ident]=(size,first,last)
    def read(self,path):
        size,first,last=self.blocks[self.files[path]]
        assert last>=first and size<=(last-first+1)*1024
        start=16+first*1024
        return ex_decode(self.data[start:start+size])
