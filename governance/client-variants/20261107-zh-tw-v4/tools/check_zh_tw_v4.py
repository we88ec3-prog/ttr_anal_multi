"""Read-only independent static checks for the approved root-directory v4."""
from pathlib import Path
import hashlib,json,struct,re,sys
from xml.etree import ElementTree as ET
R=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
from check_zh_tw_v3_glyphs import cmap
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def check():
 m=json.loads((R/'CLIENT/evidence/20261107-variant-v4/build-manifest.json').read_text(encoding='utf-8-sig'))
 base=(R/'Tartaros.ip-zh-tw-only-v2.exe').read_bytes();v4=(R/'Tartaros.ip-zh-tw-v4.exe').read_bytes()
 assert len(v4)==len(base)
 actual={i for i,(a,b) in enumerate(zip(base,v4)) if a!=b}
 assert actual=={0xc2981,0xc298c,0x83f170,0x83f171,0x83f172,0xbe8a19}
 pe=struct.unpack_from('<I',base,60)[0];size=struct.unpack_from('<I',base,pe+24+60)[0]
 assert v4[:size]==base[:size], 'PE headers/sections changed'
 assert v4[0x83f16c:0x83f16c+len(b'UI/Fnt4.stp\0')]==b'UI/Fnt4.stp\0'
 assert v4[0xbe8a00:0xbe8a00+len(b'TC_UI/Table.story-zh-tw-v4\0')]==b'TC_UI/Table.story-zh-tw-v4\0'
 for output in m['outputs']:assert sha(R/output['path'])==output['sha256']
 for name,digest in m['protected_existing_files'].items():assert sha(R/name)==digest
 assert (R/'TC_UI/Table.story-zh-tw-v4.stp').read_bytes()==(R/'CLIENT/build/zh-tw-v3/TC_UI/Table.story-zh-tw-v3.stp').read_bytes()
 a=Archive(R/'UI/Fnt4.stp');b=Archive(R/'CLIENT/build/zh-tw-v3/UI/Font.stp')
 assert a.files==b.files;changed=[]
 for name in a.files:
  if a.read(name)!=b.read(name):changed.append(name)
 assert changed==['Font/Chinese(Taiwan).FFT']
 old=b.read(changed[0]);new=a.read(changed[0])
 expected=old.replace(b'./UI/Font/msjh.ttf',b'./UI/Font/v4jh.ttf').replace(b'./UI/Font/msjhbd.ttf',b'./UI/Font/v4jhbd.ttf')
 assert new==expected and len(re.findall(rb'<FONTITEM\b',new))==86
 needed={ord(c) for c in (R/'CLIENT/evidence/20261105-variant-text/glyphs-all-visible-fields.txt').read_text(encoding='utf-8-sig') if not c.isspace()}
 fonts=[]
 for name in ['v4jh.ttf','v4jhbd.ttf']:
  present=cmap(R/'UI/Font'/name);missing=needed-present;assert not missing
  fonts.append({'font':name,'required':len(needed),'missing':len(missing)})
 for name in ['fcs.flu','pack.gms','G-Blender_1642N5mt_dx32.DLL']:
  assert name in m['protected_existing_files'] and (R/name).is_file()
 result={'status':'PASS_STATIC_ONLY','changed_exe_bytes':len(actual),'pe_headers_unchanged':True,
         'protected_existing_files_verified':len(m['protected_existing_files']),
         'font_item_count':86,'font_coverage':fonts,'translation_archive_matches_approved_v3':True,
         'runtime':'PENDING_USER','game_executed_or_attached':False}
 p=R/'CLIENT/evidence/20261107-variant-v4/independent-check.json'
 p.write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'));print(json.dumps(result))
if __name__=='__main__':check()
