"""Assemble a reversible client variant in a separate working directory.
Uses the SHA-pinned v2 image, reviewed age patch JSON, text/font overlays.
Creates junctions only for static asset directories. Never launches the game.
"""
from pathlib import Path
import argparse,hashlib,json,os,shutil,subprocess,base64,struct
P=argparse.ArgumentParser();P.add_argument('--workspace-root',type=Path,default=Path(r'E:\Tartaros\workspace'));P.add_argument('--age-patch',type=Path,required=True);args=P.parse_args()
R=args.workspace_root.resolve();D=R/'CLIENT/build/zh-tw-v3';E=R/'CLIENT/evidence/20261105-variant-build';E.mkdir(parents=True,exist_ok=True);D.mkdir(parents=True,exist_ok=True)
sha=lambda b:hashlib.sha256(b).hexdigest()
source=R/'Tartaros.ip-zh-tw-only-v2.exe';b=bytearray(source.read_bytes())
assert sha(b)=='6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c'
patch=json.loads(args.age_patch.read_text(encoding='utf-8-sig'))
assert patch['source_sha256']==sha(b)

def write_once(p,data):
 p.parent.mkdir(parents=True,exist_ok=True)
 if p.exists():assert p.read_bytes()==data,f'Refuse different existing output: {p}'
 else:p.write_bytes(data)

def copy_once(src,dst):write_once(dst,src.read_bytes())

pe=struct.unpack_from('<I',b,60)[0];opt=pe+24;table=opt+struct.unpack_from('<H',b,pe+20)[0];count=struct.unpack_from('<H',b,pe+6)[0];imagebase=struct.unpack_from('<I',b,opt+28)[0]
sections=[struct.unpack_from('<8sIIIIIIHHI',b,table+40*i) for i in range(count)]
def offset(va):
 for section in sections:
  if imagebase+section[2]<=va<imagebase+section[2]+section[3]:return section[4]+va-imagebase-section[2]
 raise ValueError('VA outside raw sections')
# Patch schema accepts exact reviewed VA/before/after byte sequences only.
changes=patch['patches'];allowed=set()
for row in changes:
 va=int(row['va'],0) if isinstance(row['va'],str) else row['va'];q=offset(va);before=bytes.fromhex(row['before']);after=bytes.fromhex(row['after'])
 assert before and len(before)==len(after) and b[q:q+len(before)]==before,'Before bytes mismatch'
 b[q:q+len(after)]=after;allowed.update(range(q,q+len(after)))
# No PE layout or old IP/translation code changes are needed.
assert len(b)==source.stat().st_size
original=source.read_bytes();diff=[i for i,(x,y) in enumerate(zip(original,b)) if x!=y];assert set(diff)<=allowed
exe=D/'Tartaros.zh-tw-v3.exe';write_once(exe,b)
# All ordinary runtime files are private copies; game logs/config stay local.
files=[]
for src in R.iterdir():
 if src.is_file() and src.suffix.lower() in {'.dll','.ini','.lua','.xml','.scn','.cfg','.dat','.stp','.flu','.gms'}:
  copy_once(src,D/src.name);files.append({'name':src.name,'sha256':sha(src.read_bytes())})
for name in ['Character','Effect','Emblem','Image','Map','Material','Sound']:
 src=R/name;dst=D/name
 assert src.is_dir() and src.resolve().is_relative_to(R)
 if dst.exists():assert dst.resolve()==src.resolve(),'Unexpected existing asset directory'
 else:
  def quote(s):return "'"+str(s).replace("'","''")+"'"
  command='New-Item -ItemType Junction -Path '+quote(dst)+' -Target '+quote(src)+' | Out-Null'
  encoded=base64.b64encode(command.encode('utf-16le')).decode()
  subprocess.run(['powershell.exe','-NoProfile','-NonInteractive','-EncodedCommand',encoded],check=True,creationflags=0x08000000)
 assert dst.resolve()==src.resolve()
# Render state package is required for alpha blending/test and materials.
assert (D/'pack.gms').read_bytes()==(R/'pack.gms').read_bytes(),'Render-state package must match baseline'
# Native716440 silently skips registration when this file is absent.
registry=(D/'fcs.flu').read_bytes();groups,entries=struct.unpack_from('<II',registry)
assert len(registry)==8+groups*0x158+entries*0x218,'Invalid resource registry layout'
assert registry==(R/'fcs.flu').read_bytes(),'Resource registry must match baseline'
# UI is an ordinary separate directory. Only its Font.stp is replaced.
for src in (R/'UI').iterdir():
 if src.is_file() and src.suffix.lower()=='.stp' and src.name!='Font.stp':copy_once(src,D/'UI'/src.name)
for src in (R/'UI/Font').iterdir():
 if src.is_file():copy_once(src,D/'UI/Font'/src.name)
for name in ['msjh.ttf','msjhbd.ttf']:copy_once(R/'CLIENT/build/zh-tw-v3-resources/font'/name,D/'UI/Font'/name)
copy_once(R/'CLIENT/build/zh-tw-v3-resources/Font.stp',D/'UI/Font.stp')
copy_once(R/'TC_UI/StringTable.stp',D/'TC_UI/StringTable.stp')
copy_once(R/'CLIENT/build/zh-tw-v3-resources/Table.story-zh-tw-v3.stp',D/'TC_UI/Table.story-zh-tw-v3.stp')
# Existing .tctext/.tcui logical paths remain valid relative to this new cwd.
for value in ['TC_UI/Table.story-zh-tw-v3','TC_UI/StringTable']:
 assert value.encode('ascii') in b,'Required existing archive redirect missing'
launcher=R/'CLIENT/build/Open-Tartaros-zh-tw-v3.cmd'
write_once(launcher,('@echo off\r\ncd /d "'+str(D)+'"\r\nstart "" "'+str(exe)+'"\r\n').encode('ascii'))
report={'source_sha256':sha(original),'output_sha256':sha(b),'output_executable':str(exe),'working_directory':str(D),'launcher':str(launcher),'patch_file_sha256':sha(args.age_patch.read_bytes()),'changed_executable_bytes':len(diff),'changed_file_offsets':[hex(i) for i in diff],'base_runtime_files':files,'font_files':[{'name':n,'sha256':sha((D/'UI/Font'/n).read_bytes())} for n in ['msjh.ttf','msjhbd.ttf']],'font_archive_sha256':sha((D/'UI/Font.stp').read_bytes()),'table_archive_sha256':sha((D/'TC_UI/Table.story-zh-tw-v3.stp').read_bytes()),'runtime_verified':False,'original_exe_unchanged':sha(source.read_bytes())==sha(original),'original_assets_modified':False}
(E/'build-manifest.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:v for k,v in report.items() if k!='base_runtime_files'}))
