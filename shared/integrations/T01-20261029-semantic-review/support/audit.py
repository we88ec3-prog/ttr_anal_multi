import pathlib,json,hashlib,zipfile,sys,struct,re,subprocess,collections
import os
W=pathlib.Path(__file__).resolve().parent
R=W.parents[3]
if os.environ.get('T01_CAPSTONE_ROOT'):sys.path.insert(0,os.environ['T01_CAPSTONE_ROOT'])
from capstone import Cs,CS_ARCH_X86,CS_MODE_32,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
B=pathlib.Path(os.environ.get('T01_TARGET','E:/Tartaros/workspace/Tartaros.bin')).read_bytes()
H=hashlib.sha256(B).hexdigest();assert H=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',B,0x3c)[0];n=struct.unpack_from('<H',B,pe+6)[0];opt=pe+24;ib=struct.unpack_from('<I',B,opt+28)[0];st=opt+struct.unpack_from('<H',B,pe+20)[0]
sections=[]
for k in range(n):
    p=st+k*40;vs,rva,size,raw=struct.unpack_from('<IIII',B,p+8);sections.append(dict(name=B[p:p+8].rstrip(b'\0').decode(),va=ib+rva,virtual_size=vs,raw_size=size,raw=raw))
def offset(a):
    for s in sections:
        if s['va']<=a<s['va']+s['raw_size']:return s['raw']+a-s['va']
    raise ValueError(hex(a))
def data(a,n):o=offset(a);return B[o:o+n]
md=Cs(CS_ARCH_X86,CS_MODE_32);md.detail=True
def cfg(entry):
    todo=[entry];seen={};edges=[];external=[]
    while todo:
        a=todo.pop()
        if a in seen:continue
        if not entry<=a<entry+0x20000:external.append(hex(a));continue
        ins=next(md.disasm(data(a,15),a,count=1),None)
        if ins is None:raise ValueError(('decode',hex(a)))
        row=dict(va=hex(a),raw=hex(offset(a)),bytes=ins.bytes.hex(' '),mnemonic=ins.mnemonic,operands=ins.op_str,size=ins.size);seen[a]=row
        fall=a+ins.size
        if ins.group(CS_GRP_RET) or ins.mnemonic in ['int3','ud2','hlt']:continue
        if ins.group(CS_GRP_JUMP):
            if ins.operands and ins.operands[0].type==2:
                target=ins.operands[0].imm;edges.append([hex(a),hex(target),'branch']);todo.append(target)
            else:row['unresolved_indirect_jump']=True
            if ins.mnemonic!='jmp':todo.append(fall);edges.append([hex(a),hex(fall),'fallthrough'])
        else:
            if ins.group(CS_GRP_CALL):row['call_target']=hex(ins.operands[0].imm) if ins.operands[0].type==2 else 'indirect'
            todo.append(fall)
        if len(seen)>10000:raise ValueError('CFG limit')
    overlaps=[]
    for a,row in seen.items():
        for q in range(a+1,a+row['size']):
            if q in seen:overlaps.append([hex(a),hex(q)])
    return dict(entry=hex(entry),instructions=[seen[a] for a in sorted(seen)],branch_edges=edges,external_tail_branches=external,overlaps=overlaps,coverage='recursive reachable decoding; calls not recursively expanded; EH/indirect targets separately reviewed')
def save(p,obj):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
if __name__=='__main__':
    for x in sys.argv[1:]:
        a=int(x,16);d=cfg(a);save(W/'cfg'/f'{a:08x}.json',d)
        print(x,len(d['instructions']),'instructions',len(d['overlaps']),'overlaps')
    save(W/'identity.json',dict(path='E:/Tartaros/workspace/Tartaros.bin',sha256=H,bytes=len(B),image_base=hex(ib),sections=sections,decoder='Capstone 5.0.6, bundled Ghidra debugger wheel'))
