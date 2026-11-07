"""Translation-only v7: repair two direct skill-description paths, new files only.
Uses approved v5 display text plus fourteen ID/level-matched Taiwan text repairs.
Never launches/attaches the game, changes gameplay values, or rewrites existing resources.
"""
from pathlib import Path
import hashlib,json,re,struct,sys,xml.etree.ElementTree as ET
from xml.sax.saxutils import escape
R=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
from build_zh_tw_v3_text_resources import index_xml,valid_text
from check_zh_tw_v3_glyphs import cmap
sha=lambda b:hashlib.sha256(b).hexdigest()
PINS={
 'Tartaros.ip-zh-tw-v6.exe':'3b1605c2d231704f9e0fefc7bc27a45e9b5759d71e94e944736adb4481053148',
 'TC_UI/Table.story-zh-tw-v5.stp':'aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae'}
TC_SHA='d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84'
SPECS=[
 {'old':'Table/SkillExplainTable.xml','new':'TC_UI/SkillExplainText7.xml','member':'Table/skillexplaintable.xml','offset':0x80d5ec,
  'root':'SKILLEXPLAINTABLE','rowTag':'SKILL','key':'no','ids':[243],
  'v5Sha256':'0ab7aa30d5fa59b691732c27f1dfe20a5eb5e02c1bed2eb685a4dd6f37e5a70a'},
 {'old':'Table/PracticeExplainTable.xml','new':'TC_UI/PracticeDescription7.xml','member':'Table/PracticeExplainTable.xml','offset':0x80d3ec,
  'root':'PRACTICEEXPLAIN','rowTag':'PRACTICE','key':'ID','ids':[146,148,152,181,*range(199,208)],
  'v5Sha256':'34c6f174d1b37c99573d079a3f312ea805f0735c052cef3c66023c99bfc5db33'}]

def row_bytes(raw,node):
 end=raw.index(b'>',node['close_start'])+1
 return raw[node['start']:end]

def repair_text(raw,donor,spec):
 before=index_xml(raw);other=index_xml(donor)
 edits=[];expected_attrs={};expected_text={};accepted=[]
 for ident in spec['ids']:
  matches=[(path,n) for path,n in before.items() if n['tag']==spec['rowTag'] and n['attrs'].get(spec['key'])==str(ident)]
  assert len(matches)==1,('Ambiguous original row',ident)
  base,node=matches[0];assert base in other and other[base]['tag']==node['tag']
  paths=[k for k in before if k[:len(base)]==base];donor_paths=[k for k in other if k[:len(base)]==base]
  assert set(paths)==set(donor_paths),('ID/level shape mismatch',ident)
  changed=[]
  for path in paths:
   old,new=before[path],other[path]
   assert old['tag']==new['tag'] and old['children']==new['children']
   a=dict(old['attrs']);b=dict(new['attrs'])
   if path==base and old['tag']=='PRACTICE':a.pop('NAME',None);b.pop('NAME',None)
   assert a==b,('Nontext attribute mismatch',ident,path)
   if path==base and old['tag']=='PRACTICE' and old['attrs'].get('NAME')!=new['attrs'].get('NAME'):
    value=new['attrs'].get('NAME','');assert value.strip() and valid_text(old['attrs'].get('NAME',''),value) is None
    opening=raw[old['start']:old['open_end']]
    pattern=rb'(\bNAME=)(["\'])(.*?)\2'
    def replace(m):return m[1]+m[2]+escape(value,{'"':'&quot;',"'":'&apos;'}).encode('utf-8')+m[2]
    replaced,count=re.subn(pattern,replace,opening);assert count==1
    edits.append((old['start'],old['open_end'],replaced))
    expected_attrs[path]={**old['attrs'],'NAME':value};changed.append({'field':'NAME','path':repr(path)})
   if old['text'].strip()!=new['text'].strip():
    assert old['children']==0 and old['tag'].lower() in {'explain','level'},('Non-display text mismatch',ident,path)
    assert valid_text(old['text'],new['text']) is None,('Unsafe display text',ident,path)
    edits.append((old['open_end'],old['close_start'],escape(new['text']).encode('utf-8')))
    expected_text[path]=new['text'];changed.append({'field':'TEXT','path':repr(path)})
  assert changed,('No residual text repair',ident)
  accepted.append({'id':ident,'old_v5_raw_row_sha256':sha(row_bytes(raw,node)),
   'taiwan_raw_row_sha256':sha(row_bytes(donor,other[base])),'identity_and_level_shape_equal':True,'changed_display_fields':changed})
 result=raw
 for start,end,data in sorted(edits,reverse=True):result=result[:start]+data+result[end:]
 after=index_xml(result);assert before.keys()==after.keys()
 for path,old in before.items():
  new=after[path]
  assert new['attrs']==expected_attrs.get(path,old['attrs']) and new['text']==expected_text.get(path,old['text']) and new['children']==old['children']
 parsed=ET.fromstring(result);display=''.join(parsed.itertext())+''.join(n.get('NAME','') for n in parsed)
 assert not re.search('[\uac00-\ud7af]',display),'Residual displayed Hangul still present'
 return result,accepted,{'attribute_fields_changed':len(expected_attrs),'text_fields_changed':len(expected_text),
                         'all_ids_levels_nontext_fields_and_unselected_rows_preserved':True}

def description_coverage(payloads):
 skill=ET.fromstring(payloads[0]);practice=ET.fromstring(payloads[1]);results=[]
 for category,root,key,ids in [('isilia_V_descriptions',skill,'no',[67,68,69]),
                             ('all_role_phase_active_descriptions',skill,'no',list(range(2541,2550))),
                             ('isilia_V_and_matrix_practices',practice,'ID',[63,64,193,202]),
                             ('all_role_phase_practice_descriptions',practice,'ID',list(range(199,208)))]:
  for ident in ids:
   nodes=[n for n in root if n.get(key)==str(ident)];assert len(nodes)==1
   n=nodes[0];text=' '.join(n.itertext())+' '+n.get('NAME','')
   assert not re.search('[\uac00-\ud7af]',text) and re.search('[\u3400-\u9fff]',text)
   results.append({'category':category,'id':ident,'row_sha256':sha(ET.tostring(n,encoding='utf-8')),'contains_han':True,'contains_hangul':False})
 return results

def build():
 for name,digest in PINS.items():assert sha((R/name).read_bytes())==digest,('Pinned input mismatch',name)
 tcpath=R.parent/'tc_workspace/Table.stp';assert sha(tcpath.read_bytes())==TC_SHA
 outputs=['Tartaros.ip-zh-tw-v7.exe',*[s['new'] for s in SPECS]]
 assert all(not (R/n).exists() for n in outputs),'Refuse existing game outputs'
 directories=[R,R/'TC_UI',R/'UI',R/'UI/Font',R/'TC_UI/Font',R/'Map/Minimap']
 protected={str(p.relative_to(R)):sha(p.read_bytes()) for d in directories if d.is_dir() for p in d.iterdir()
            if p.is_file() and p.suffix.lower() in {'.exe','.bin','.dll','.stp','.flu','.gms','.ttf','.xml','.cfg','.ini','.mmt'}}
 print('Protected existing runtime/resource files:',len(protected),flush=True)
 external={str(tcpath):sha(tcpath.read_bytes())}
 raw=(R/outputs[0].replace('v7.exe','v6.exe')).read_bytes();image=bytearray(raw);allowed=set();patches=[]
 approved=Archive(R/'TC_UI/Table.story-zh-tw-v5.stp');tc=Archive(tcpath);payloads=[];repairs=[]
 for s in SPECS:
  old,new=s['old'].encode(),s['new'].encode();at=s['offset']
  assert len(old)==len(new) and raw.count(old+b'\0')==1 and raw[at:at+len(old)+1]==old+b'\0'
  assert new+b'\0' not in raw
  image[at:at+len(old)]=new;allowed.update(range(at,at+len(old)))
  patches.append({'offset':hex(at),'before':s['old'],'after':s['new'],'equal_length_bytes':len(old)})
  original=approved.read(s['member']);donor=tc.read(s['member']);assert sha(original)==s['v5Sha256'] and ET.fromstring(original).tag==s['root']
  modified,accepted,scope=repair_text(original,donor,s);payloads.append(modified)
  repairs.append({'member':s['member'],'source_v5_sha256':sha(original),'source_taiwan_member_sha256':sha(donor),
   'output_sha256':sha(modified),'accepted_rows':accepted,'rejected_rows':[],'scope':scope})
 diff=[i for i,(a,b) in enumerate(zip(raw,image)) if a!=b];assert len(raw)==len(image) and set(diff)<=allowed
 pe=struct.unpack_from('<I',raw,60)[0];headers=struct.unpack_from('<I',raw,pe+24+60)[0];assert raw[:headers]==image[:headers]
 section_count=struct.unpack_from('<H',raw,pe+6)[0];optional=struct.unpack_from('<H',raw,pe+20)[0];table=pe+24+optional;sections=[]
 for i in range(section_count):
  at=table+i*40;name=raw[at:at+8].rstrip(b'\0').decode('ascii');size,ptr=struct.unpack_from('<II',raw,at+16);flags=struct.unpack_from('<I',raw,at+36)[0]
  if flags&0x20:assert raw[ptr:ptr+size]==image[ptr:ptr+size],'Code section changed'
  sections.append({'name':name,'raw_offset':hex(ptr),'raw_bytes':size,'code':bool(flags&0x20),'unchanged':raw[ptr:ptr+size]==image[ptr:ptr+size]})
 for dependency in [b'TC_UI/Table.story-zh-tw-v5\0',b'UI/Fnt4.stp\0',b'TC_UI/ActorName6.xml\0',b'TC_UI/NpcName6.xml\0']:assert dependency in image
 coverage=description_coverage(payloads)
 texts=''.join(' '.join(ET.fromstring(b).itertext())+' '+''.join(n.get('NAME','') for n in ET.fromstring(b)) for b in payloads)
 needed={ord(c) for c in texts if not c.isspace() and ord(c)>31};fonts=[]
 for n in ['v4jh.ttf','v4jhbd.ttf']:
  missing=needed-cmap(R/'UI/Font'/n);fonts.append({'font':'UI/Font/'+n,'sha256':sha((R/'UI/Font'/n).read_bytes()),'required_display_codepoints':len(needed),'missing_count':len(missing),'missing_codepoints':['U+%04X'%v for v in sorted(missing)]})
  assert not missing,'Translated descriptions require uncovered glyphs'
 for name,data in zip(outputs,[bytes(image),*payloads]):
  with (R/name).open('xb') as f:f.write(data)
 assert all(sha((R/n).read_bytes())==h for n,h in protected.items()),'Existing runtime/resource file changed'
 assert all(sha(Path(n).read_bytes())==h for n,h in external.items()),'External source archive changed'
 manifest={'schema':'tartaros-zh-tw-v7-build-v1','authorization':'User standing authorization for translation companion additions/repairs; root requested skill/Tab/V text fixes; preserve old versions and report completion.',
  'source_exe_sha256':PINS['Tartaros.ip-zh-tw-v6.exe'],'source_v5_table_sha256':PINS['TC_UI/Table.story-zh-tw-v5.stp'],'source_taiwan_table_sha256':TC_SHA,
  'path_patches':patches,'actual_diff_offsets_vs_v6':[hex(i) for i in diff],'actual_diff_count':len(diff),'exe_size_unchanged':True,'pe_headers_unchanged':True,'sections':sections,
  'outputs':[{'path':n,'bytes':(R/n).stat().st_size,'sha256':sha((R/n).read_bytes())} for n in outputs],
  'xml_repair_scope':repairs,'special_description_coverage':coverage,'font_coverage':fonts,'fonts_modified':False,
  'preserved_existing_files':protected,'all_existing_files_unchanged':True,'preserved_external_sources':external,
  'game_executed_or_attached':False,'runtime':'PENDING_USER','launch':'Direct v7 EXE from original game root; existing v5 Table, v4 fonts and v6 NPC XML remain dependencies.',
  'limitations':['Two statically located direct readers patched; actual in-game tooltip/caches still require human testing.','Text uses Taiwan localization while KR gameplay/stat structures remain; this patch does not reconcile every gameplay balance or tooltip numerical semantic.','No physical Tab/V key behavior or Server ability is changed by this translation.','No chat-help or unrelated resources changed.']}
 e=R/'CLIENT/evidence/20261107-variant-v7';e.mkdir(parents=True,exist_ok=True)
 (e/'build-manifest.json').write_bytes((json.dumps(manifest,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
 print(json.dumps({k:manifest[k] for k in ['outputs','actual_diff_count','exe_size_unchanged','pe_headers_unchanged','font_coverage','all_existing_files_unchanged','runtime']},ensure_ascii=False))
if __name__=='__main__':build()
