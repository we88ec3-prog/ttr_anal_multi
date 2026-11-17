from pathlib import Path
import struct,hashlib,json,subprocess,re,datetime,argparse,sys
parser=argparse.ArgumentParser(description='Re-read the exact T01 bounded original native windows without executing Client.')
parser.add_argument('--repo',type=Path,required=True);parser.add_argument('--bin',type=Path,required=True);parser.add_argument('--out',type=Path,required=True)
args=parser.parse_args();repo=args.repo.resolve();out=args.out.resolve();binary=args.bin.resolve()
if sys.flags.optimize:raise ValueError('Use Python without -O; assertions must remain active')
if out==binary.parent or out.is_relative_to(binary.parent):raise ValueError('Output cannot be written into the original-source directory')
out.mkdir(parents=True,exist_ok=True);b=binary.read_bytes()
sha=lambda x:hashlib.sha256(x).hexdigest()
assert sha(b)=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
nt=struct.unpack_from('<I',b,0x3c)[0];assert b[nt:nt+4]==b'PE\0\0'
opt=nt+24;machine,count=struct.unpack_from('<HH',b,nt+4);opt_size=struct.unpack_from('<H',b,nt+20)[0];base=struct.unpack_from('<I',b,opt+28)[0]
assert machine==0x14c and struct.unpack_from('<H',b,opt)[0]==0x10b
sections=[]
for i in range(count):
 p=opt+opt_size+40*i; vs,rva,rs,raw=struct.unpack_from('<IIII',b,p+8);sections.append({'name':b[p:p+8].rstrip(b'\0').decode(),'rva':rva,'virtual_size':vs,'raw_size':rs,'raw':raw})
def offset(va):
 rva=va-base
 for s in sections:
  if s['rva']<=rva<s['rva']+s['raw_size']:return s['raw']+rva-s['rva'],s['name']
 raise ValueError(hex(va))
prefix='kr-extra-roy/'
selections=[
 (prefix+'MEF-comprehensive-contracts-20261117/abi/native-evidence.json','windows',['F_0056A100','F_0056A430','F_006F50F0']),
 (prefix+'MEF-control-flow-20261116/supervisor/native-windows.json','records',['vm_call','precall']),
 (prefix+'MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json','windows',['F_00565600','F_006FDCB0','F_006FDC30','F_006FDD90','F_006FDD10']),
 (prefix+'MEF-comprehensive-contracts-20261117/reuse/native-evidence.json','windows',['q_flying_create','q_flying_cancel']),
 (prefix+'MEF-comprehensive-contracts-20261117/reuse-followup/native-evidence.json','windows',['q_create_actor','q_actor_immediate_init','actor_doll_init','doll_request']),
 (prefix+'MEF-control-flow-20261116/world/native-windows.json','windows',['flying_fade_constructor','flying_image_load']),
 (prefix+'MEF-feature-lifecycle-20261117/native-evidence.json','windows',['flying_lifecycle','flying_manager_tick','flying_alive','flying_release','flying_deleting_dtor']),
 (prefix+'MEF-P0-content-contracts-20261117/execution-lifecycle/native-evidence.json','windows',['N01_doll_release_before_actor_delete','N05_string_assign'])]
records=[];listing=[]
for path,key,ids in selections:
 raw_source=(repo/path).read_bytes();expected_source=subprocess.check_output(['git','show','534746f194a889ebb34dda7471c2ae62d30a1dd1:'+path],cwd=repo);assert raw_source==expected_source
 dataset=json.loads(raw_source);lookup={r['id']:r for r in dataset[key]}
 blob=subprocess.check_output(['git','rev-parse','534746f194a889ebb34dda7471c2ae62d30a1dd1:'+path],cwd=repo,text=True).strip()
 for ident in ids:
  row=lookup[ident];a=int(row['va'],16);z=int(row.get('end_exclusive',row.get('end')),16);off,section=offset(a);raw=b[off:off+z-a]
  assert sha(raw)==row['sha256']
  cmd=['objdump','-d','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z),str(binary)]
  text=subprocess.check_output(cmd,text=True);decoded=[]
  for line in text.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s*\t([0-9a-f ]+)\t(.+)$',line)
   if m:decoded.append({'va':hex(int(m[1],16)),'bytes':bytes.fromhex(m[2]).hex(),'asm':m[3].strip()})
  cursor=a
  for inst in decoded:
   assert int(inst['va'],16)==cursor;cursor+=len(bytes.fromhex(inst['bytes']))
   assert '(bad)'not in inst['asm'] and '.byte'not in inst['asm']
  assert cursor==z and b''.join(bytes.fromhex(i['bytes'])for i in decoded)==raw
  records.append({'id':ident,'source_file':path,'source_blob_sha':blob,'va':hex(a),'end_exclusive':hex(z),'raw_offset':hex(off),'section':section,'length':len(raw),'sha256':sha(raw),'instruction_count':len(decoded),'instructions':decoded})
  listing.append('; '+ident+' source='+path+' blob='+blob+'\n; VA '+hex(a)+' raw '+hex(off)+' SHA256 '+sha(raw)+'\n'+ '\n'.join(i['va']+' '+i['bytes'].ljust(32)+' '+i['asm']for i in decoded))
result={'review':'T01-R2-selected-native-windows','reviewed_at':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=8))).isoformat(),'target_sha256':sha(b),'target_bytes':len(b),'pe_machine':hex(machine),'image_base':hex(base),'sections':sections,'windows':records,'instruction_count':sum(r['instruction_count']for r in records),'window_bytes':sum(r['length']for r in records),'scope':'Independent PE mapping and fresh objdump boundary/byte verification for manually reviewed bounded claims; not whole-function semantic certification or FULL-PASS.'}
(out/'native-review.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n');(out/'native-review.asm').write_text('\n\n'.join(listing)+'\n')
print(json.dumps({'windows':len(records),'bytes':result['window_bytes'],'instructions':result['instruction_count'],'all_matched':True}))
