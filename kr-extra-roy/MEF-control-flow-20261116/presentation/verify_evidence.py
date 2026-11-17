#!/usr/bin/env python3
"""Read-only original-byte, pinned Git source and bounded contract checks.

No network, Git mutation, Lua/client/server execution, compilation or resource
extraction. Only --output may write a verification-result JSON.
"""
import argparse, hashlib, json, os, re, struct, subprocess, sys
from pathlib import Path
sys.dont_write_bytecode=True

def check(value, reason):
    if not value: raise ValueError(reason)
def sha(b): return hashlib.sha256(b).hexdigest()
def blob(b): return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def load(p): return json.loads(p.read_text())

class PE:
    def __init__(self,path,identity):
        self.path=path;self.b=path.read_bytes()
        check(len(self.b)==identity['size'] and sha(self.b)==identity['sha256'],'Original BIN identity')
        p=struct.unpack_from('<I',self.b,0x3c)[0]
        check(self.b[p:p+4]==b'PE\0\0' and struct.unpack_from('<H',self.b,p+4)[0]==0x14c,'PE i386')
        check(struct.unpack_from('<H',self.b,p+24)[0]==0x10b,'PE32 optional header')
        n=struct.unpack_from('<H',self.b,p+6)[0];opt=struct.unpack_from('<H',self.b,p+20)[0]
        self.base=struct.unpack_from('<I',self.b,p+52)[0]
        check(self.base==int(identity['imagebase'],0),'Image base')
        self.sections=[]
        for i in range(n):
            q=p+24+opt+40*i;vs,rva,rs,raw=struct.unpack_from('<4I',self.b,q+8)
            self.sections.append((self.b[q:q+8].rstrip(b'\0').decode(),self.base+rva,rs,raw))
    def raw(self,a,n):
        for _,start,size,raw in self.sections:
            if start<=a and a+n<=start+size:return raw+a-start
        raise ValueError('VA is not raw-backed: '+hex(a))
    def at(self,a,n):
        p=self.raw(a,n);return self.b[p:p+n]
    def u32(self,a):return struct.unpack('<I',self.at(a,4))[0]
    def string(self,a):
        p=self.raw(a,1);end=self.b.index(0,p,p+512);return self.b[p:end].decode('ascii')
    def disasm(self,a,e):
        out=subprocess.run(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(e+15),str(self.path)],capture_output=True,text=True,check=True).stdout
        rows=[]
        for line in out.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if m and int(m[1],16)<e:
                v=int(m[1],16);b=bytes.fromhex(m[2]);rows.append(dict(va=hex(v),raw=hex(self.raw(v,len(b))),hex=b.hex(),asm=m[3].strip()))
        return rows

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',type=Path,required=True);ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--output',type=Path)
    a=ap.parse_args();e=a.evidence_dir
    native=load(e/'native-windows.json');ass=load(e/'native-assertions.json');sources=load(e/'source-manifest.json');c=load(e/'contracts.json')
    pe=PE(a.bin,native['binary']);ins={};codes=0
    lines=['; MEF R10 presentation: verified native excerpts, end-exclusive VA windows.','; Code/data are separate. No inferred C signatures used as the native proof.']
    for r in native['records']:
        start=int(r['va'],0);end=int(r['end'],0);b=pe.at(start,r['length'])
        check(end-start==len(b) and pe.raw(start,len(b))==int(r['raw'],0),'Raw mapping '+r['id'])
        check(b.hex()==r['hex'] and sha(b)==r['sha256'],'Original bytes '+r['id'])
        lines+=['',f"; {r['id']} [{r['va']},{r['end']}) raw={r['raw']} sha256={r['sha256']} {r['role']}"]
        if r['kind']=='code':
            actual=pe.disasm(start,end);check(actual==r['instructions'],'Fresh disassembly '+r['id']);cursor=start
            for i in actual:
                v=int(i['va'],0);check(v==cursor and '(bad)' not in i['asm'],'Continuous instruction '+r['id']);cursor+=len(bytes.fromhex(i['hex']));ins[v]=i
            check(cursor==end,'Final full instruction '+r['id']);codes+=1
            lines += [f"{i['va']:<10} {i['hex']:<34} {i['asm']}" for i in actual]
        else:lines.append('; DATA '+r['hex'])
    check((e/'native-windows.asm').read_text()=='\n'.join(lines)+'\n','ASM agrees with verified native records')
    for r in ass['anchors']:
        v=int(r['va'],0);check(v in ins and ins[v]['hex']==r['hex'] and ins[v]['asm']==r['asm'],'Original instruction anchor '+r['va'])
    for r in ass['relcalls']:
        v=int(r['callsite'],0);b=pe.at(v,5)
        check(v in ins and b[0]==0xe8 and v+5+struct.unpack('<i',b[1:])[0]==int(r['target'],0),'Decoded direct call '+r['callsite'])
    for r in ass['tables']:
        v=int(r['va'],0);check([hex(pe.u32(v+4*i)) for i in range(len(r['targets']))]==r['targets'],'Original table '+r['id'])
    for r in ass['strings']:check(pe.string(int(r['va'],0))==r['text'],'Original string '+r['id'])
    for r in ass['reused_q_bindings']:
        call=int(r['callsite'],0);b=pe.at(call,5)
        check(b[0]==0xe8 and call+5+struct.unpack('<i',b[1:])[0]==int(r['registrar'],0),'Q initializer edge')
        for store in r['stores']:
            v=int(store['va'],0)
            check(pe.at(v,2)==b'\xc7\x05' and pe.u32(v+2)==int(store['slot'],0) and pe.u32(v+6)==int(store['value'],0),'Q registered target immediate')
        for name in r['strings']:
            v=int(name['va'],0)
            check(pe.at(v,1) in (b'\x68',b'\xbf') and pe.u32(v+1)==int(name['ptr'],0) and pe.string(int(name['ptr'],0))==name['value'],'Q binding name immediate')
        for cb in r['callbacks']:
            v=int(cb['va'],0);check(pe.at(v,1)==b'\x68' and pe.u32(v+1)==int(cb['callback'],0),'Q closure immediate')
    check(pe.at(0xc55890,8).hex()=='000000a09999c93f' and struct.unpack('<d',pe.at(0xc55890,8))[0]==0.20000000298023224,'Original actor slow factor, exact widened float value')
    check(pe.u32(0xc0fd44)==0xc6cae8 and pe.u32(0xc0fd1c)==0xc6cb34,'Vtable COL predecessor')
    check(pe.u32(0xc6cae8+12)==0xf7f794 and pe.u32(0xc6cb34+12)==0xf7f7cc,'RTTI type descriptors')
    check([pe.u32(0x560158+4*i) for i in range(6)]==[0x5600ad,0x5600da,0x56014f,0x560105,0x560114,0x560123],'Native sepia phase dispatch')
    check(pe.at(0x560107,6).hex()=='c70305000000' and pe.at(0x560116,6).hex()=='c70306000000' and pe.at(0x560149,6).hex()=='c70200000000','Native phase4/5/6 successor stores')
    check(ins[0x5624e7]['asm']=='xor    esi,esi' and ins[0x56251e]['asm']=='cmp    DWORD PTR [edi+0x28],esi','Stop active guard with proved zero register')
    check(ins[0x562521]['asm']=='je     0x562891' and ins[0x56288c]['asm']=='call   0x561db0','Stop inactive bypass and final End')
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0')
    def git(*cmd):return subprocess.run(['git','-c','remote.origin.promisor=false',*cmd],cwd=a.repo,env=env,capture_output=True,check=True).stdout
    for r in sources['references']:
        b=git('show',r['commit']+':'+r['path'])
        check(git('rev-parse',r['commit']+':'+r['path']).decode().strip()==r['blob'],'Pinned commit/path/blob')
        check(len(b)==r['bytes'] and sha(b)==r['sha256'] and blob(b)==r['blob'],'Pinned source content '+r['path'])
    old='kr-extra-roy/MEF-runtime-contracts-20261115/input-lifecycle/tables.json'
    pin=next(r for r in sources['references'] if r['path']==old)
    bindings=json.loads(git('show',pin['commit']+':'+old))['q_regular_bindings']
    check(all(r in bindings for r in ass['reused_q_bindings']),'Selected Q bindings agree with independently published evidence')
    check(c['deployable_resource'] is False and c['runtime_execution_performed'] is False,'Static/design classification')
    check(c['end_stop']['end_performs_stop_bulk_cleanup'] is False and c['end_stop']['stop_bulk_requires_active'] is True and c['end_stop']['end_then_stop_repairs_all_presentation'] is False,'End/Stop distinction retained')
    check(c['camera_override']['restore_and_erase_precede_label_comparison'] is True and c['camera_override']['unconditional_repeated_pop_is_safe'] is False,'Non-idempotent camera ownership retained')
    check(c['camera_works']['supplies_ordinary_lua_pump'] is False and c['camera_works']['detach_pops_camera_override'] is False,'Camera owner/pump distinction retained')
    check(c['map_backup']['nested_load_preserves_all_prior_maps'] is False and c['map_backup']['restore_maplist_receiver_is_trigger_root_FB74C0'] is False,'Map backup/root distinction retained')
    check(c['world_presentation']['end_slow_guarantees_all_world_time_normal'] is False and c['world_presentation']['server_time_control'] is False,'Independent world/time owners retained')
    check(c['sepia']['subsequent_native_update_phases']==[5,6,0] and c['sepia']['native_updates_to_phase_zero']==3 and c['sepia']['end_request_is_synchronous_visual_completion'] is False,'Asynchronous sepia completion retained')
    check(c['conditional_cleanup_order'][-1]['step']=='end_once' and len(c['design_results'])==6,'Cleanup/result separation')
    files={p.name:dict(bytes=p.stat().st_size,sha256=sha(p.read_bytes())) for p in sorted(e.iterdir()) if p.is_file() and p.name!='verification-result.json'}
    result=dict(status='PASS',validation_kind='Read-only original bytes, native decoding, pinned sources and bounded contract consistency; no native semantic certification, runtime/gameplay or T01 FULL-PASS',native_records=len(native['records']),native_code_windows=codes,native_bytes=sum(r['length'] for r in native['records']),native_instructions=sum(len(r.get('instructions',[])) for r in native['records']),instruction_anchors=len(ass['anchors']),rel32_calls=len(ass['relcalls']),native_tables=len(ass['tables']),native_strings=len(ass['strings']),reused_q_bindings=len(ass['reused_q_bindings']),source_pins=len(sources['references']),original_sha256=sha(pe.b),files=files)
    text=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if a.output:a.output.write_text(text)
    print(text,end='')

if __name__=='__main__':main()
