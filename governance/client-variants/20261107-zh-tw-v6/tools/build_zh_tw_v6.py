"""Approved translation-only v6: force two NPC readers to private loose XML.
Creates three new files in original game root; never runs/attaches game.
"""
from pathlib import Path
import sys,struct,hashlib,json,xml.etree.ElementTree as ET
R=Path(__file__).resolve().parents[2];sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def build():
 source=R/'Tartaros.ip-zh-tw-v5.exe';table=R/'TC_UI/Table.story-zh-tw-v5.stp'
 assert sha(source)=='e8933203b03379bee6813082bb016fd14ffd42eac151c246bcd02fe8f203d5ea'
 assert sha(table)=='aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae'
 outputs=['Tartaros.ip-zh-tw-v6.exe','TC_UI/ActorName6.xml','TC_UI/NpcName6.xml']
 assert all(not (R/n).exists() for n in outputs),'Refuse existing game outputs'
 protected={str(p.relative_to(R)):sha(p) for d in [R,R/'TC_UI',R/'UI',R/'UI/Font',R/'TC_UI/Font']
            for p in d.iterdir() if p.is_file() and p.suffix.lower() in {'.exe','.bin','.dll','.stp','.flu','.gms','.ttf','.xml'}}
 raw=source.read_bytes();b=bytearray(raw);patches=[];allowed=set()
 for old,new,expected in [(b'Table/_ActorList.xml',b'TC_UI/ActorName6.xml',0x80ba40),
                          (b'Table/NPCTable.xml',b'TC_UI/NpcName6.xml',0x80d1e4)]:
  assert len(old)==len(new) and b.count(old+b'\0')==1
  at=b.index(old+b'\0');assert at==expected;b[at:at+len(old)]=new
  patches.append({'offset':hex(at),'before':old.decode(),'after':new.decode()});allowed.update(range(at,at+len(old)))
 diff=[i for i,(x,y) in enumerate(zip(raw,b)) if x!=y];assert len(raw)==len(b) and set(diff)<=allowed
 pe=struct.unpack_from('<I',raw,60)[0];headers=struct.unpack_from('<I',raw,pe+24+60)[0];assert raw[:headers]==b[:headers]
 assert b'TC_UI/Table.story-zh-tw-v5\0' in b and b'UI/Fnt4.stp\0' in b
 a=Archive(table);members=['Table/_ActorList.xml','Table/npctable.xml'];payloads=[a.read(n) for n in members]
 assert ET.fromstring(payloads[0]).tag=='ACTORLIST' and ET.fromstring(payloads[1]).tag=='NPCTABLE'
 for name,data in zip(outputs,[bytes(b),*payloads]):
  with (R/name).open('xb') as f:f.write(data)
 assert all(sha(R/n)==h for n,h in protected.items()),'Existing source/resource changed'
 result={'authorization':'User approved direct production of translation companion files, report changes after completion; preserve original/old versions.',
         'source_exe_sha256':sha(source),'source_table_sha256':sha(table),'path_patches':patches,
         'diff_vs_v5':[hex(i) for i in diff],'pe_headers_unchanged':True,
         'outputs':[{'path':n,'bytes':(R/n).stat().st_size,'sha256':sha(R/n)} for n in outputs],
         'xml_source_members':members,'xml_exact_v5_member_copies':True,
         'preserved_existing_files':protected,'all_existing_files_unchanged':True,
         'runtime':'PENDING_USER','game_executed_or_attached':False,
         'limitations':'Candidate direct-file path repair, not original compatibility. Existing untranslated/ambiguous NPC and glyph limitations retained; no new translation text or fonts.'}
 e=R/'CLIENT/evidence/20261107-variant-v6';e.mkdir(parents=True,exist_ok=True)
 (e/'build-manifest.json').write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
 print(json.dumps({k:v for k,v in result.items() if k!='preserved_existing_files'}))
if __name__=='__main__':build()
