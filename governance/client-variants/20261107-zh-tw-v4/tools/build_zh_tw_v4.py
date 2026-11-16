"""Build the user-authorized v4 in the existing game root; never launch it.
Only five new output files. Existing runtime/resources must remain byte-identical.
Requires the pinned local v3 resources, stp_resources.py and v3 font pack utility.
"""
from pathlib import Path
import sys, hashlib, json, re, struct
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'anal'))
from stp_resources import Archive
from build_zh_tw_v3_font import pack_overlay
sha = lambda b: hashlib.sha256(b).hexdigest()
PINS = {
 'Tartaros.ip-zh-tw-only-v2.exe': '6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c',
 'CLIENT/build/zh-tw-v3/Tartaros.zh-tw-v3.exe': 'f1a23ee3c410e4261aef5eddcb9b4bacbe185cfff50d83155d2c3842bf088cee',
 'CLIENT/build/zh-tw-v3/TC_UI/Table.story-zh-tw-v3.stp': '2a5f74af1f779879ffd2bd0a051178f3d5e8ddbf214113c36fad6c0ed93ebaf5',
 'CLIENT/build/zh-tw-v3/UI/Font.stp': '865f5d150c3d71110996f98e2bd8e7835ec917c2ccffccda171356624447b22f',
 'CLIENT/build/zh-tw-v3/UI/Font/msjh.ttf': 'a68f9bad944da2a8bdf22f3e37548c467c79f585a59dd6b448a3c0a1a268a8b6',
 'CLIENT/build/zh-tw-v3/UI/Font/msjhbd.ttf': 'd1d331318ef89b68e7477dd2d6a2f9c5024b1592cb7784dc285b1215f5f19a7a',
}

def build():
 for name, expected in PINS.items():
  assert sha((ROOT/name).read_bytes()) == expected, 'Input identity mismatch: '+name
 outputs = ['Tartaros.ip-zh-tw-v4.exe','TC_UI/Table.story-zh-tw-v4.stp',
            'UI/Fnt4.stp','UI/Font/v4jh.ttf','UI/Font/v4jhbd.ttf']
 assert all(not (ROOT/name).exists() for name in outputs), 'New outputs must not exist'
 # Snapshot all baseline executable/library/archive/config/font files in relevant directories.
 protected = sorted({p for directory in [ROOT,ROOT/'UI',ROOT/'UI/Font',ROOT/'TC_UI',ROOT/'TC_UI/Font']
                     for p in directory.iterdir() if p.is_file() and p.suffix.lower() in
                     {'.exe','.bin','.dll','.stp','.flu','.gms','.cfg','.ini','.ttf'}})
 before = {str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in protected}
 base = (ROOT/'Tartaros.ip-zh-tw-only-v2.exe').read_bytes()
 v3 = (ROOT/'CLIENT/build/zh-tw-v3/Tartaros.zh-tw-v3.exe').read_bytes()
 age_diff = [i for i,(a,b) in enumerate(zip(base,v3)) if a!=b]
 assert len(base)==len(v3) and age_diff==[0xc2981,0xc298c]
 image=bytearray(v3);patches=[];allowed=set(age_diff)
 for old,new in [(b'UI/Font.stp',b'UI/Fnt4.stp'),
                 (b'TC_UI/Table.story-zh-tw-v3',b'TC_UI/Table.story-zh-tw-v4')]:
  assert len(old)==len(new) and image.count(old+b'\0')==1
  offset=image.index(old+b'\0');image[offset:offset+len(old)]=new
  patches.append({'offset':hex(offset),'before':old.decode(),'after':new.decode()})
  allowed.update(range(offset,offset+len(old)))
 diff=[i for i,(a,b) in enumerate(zip(base,image)) if a!=b]
 assert len(base)==len(image) and set(diff)<=allowed
 font_source=ROOT/'CLIENT/build/zh-tw-v3/UI/Font.stp';archive=Archive(font_source)
 member='Font/Chinese(Taiwan).FFT';original=archive.read(member)
 modified=original
 for old,new in [(b'./UI/Font/msjh.ttf',b'./UI/Font/v4jh.ttf'),
                 (b'./UI/Font/msjhbd.ttf',b'./UI/Font/v4jhbd.ttf')]:
  assert modified.count(old)==1
  modified=modified.replace(old,new)
 assert re.findall(rb'<FONTITEM\b[^>]*>',original)==re.findall(rb'<FONTITEM\b[^>]*>',modified)
 font_bytes=pack_overlay(archive,{member:modified})
 data={outputs[0]:bytes(image),outputs[1]:(ROOT/'CLIENT/build/zh-tw-v3/TC_UI/Table.story-zh-tw-v3.stp').read_bytes(),
       outputs[2]:font_bytes,outputs[3]:(ROOT/'CLIENT/build/zh-tw-v3/UI/Font/msjh.ttf').read_bytes(),
       outputs[4]:(ROOT/'CLIENT/build/zh-tw-v3/UI/Font/msjhbd.ttf').read_bytes()}
 for name,payload in data.items():
  with (ROOT/name).open('xb') as f:f.write(payload)
 check=Archive(ROOT/outputs[2]);assert check.files==archive.files
 for name in archive.files:
  assert check.read(name)==(modified if name==member else archive.read(name))
 for path,digest in before.items():assert sha((ROOT/path).read_bytes())==digest,'Existing file changed: '+path
 report={'authorization':'User explicitly approved v4, Taiwan text plus Korean-fallback fonts, new files only in original game root.',
         'base_exe_sha256':PINS['Tartaros.ip-zh-tw-only-v2.exe'],'inputs':PINS,
         'outputs':[{'path':name,'bytes':len(payload),'sha256':sha(payload)} for name,payload in data.items()],
         'path_patches':patches,'age_patch_offsets':[hex(i) for i in age_diff],
         'changed_offsets_vs_v2':[hex(i) for i in diff],'exe_size_unchanged':True,
         'protected_existing_files':before,'all_existing_files_unchanged':True,
         'font_members_checked':len(archive.files),'font_item_count':len(re.findall(rb'<FONTITEM\b[^>]*>',original)),
         'runtime_assets':'Existing root runtime, fcs.flu, pack.gms and original asset directories; no profile copies or junctions.',
         'launcher':'Tartaros.ip-zh-tw-v4.exe','working_directory':str(ROOT),'runtime_result':'PENDING_USER',
         'translation_limitations':'Taiwan display text only; KR gameplay values preserved. Known unmatched fields keep original language.'}
 evidence=ROOT/'CLIENT/evidence/20261107-variant-v4';evidence.mkdir(parents=True,exist_ok=True)
 (evidence/'build-manifest.json').write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
 print(json.dumps({k:v for k,v in report.items() if k not in ['protected_existing_files','inputs']}))
if __name__=='__main__':build()
