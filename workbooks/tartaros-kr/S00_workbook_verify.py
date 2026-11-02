from pathlib import Path
import json,zipfile,xml.etree.ElementTree as E,hashlib,sys,shutil,os
ROOT=Path(sys.argv[1]).resolve()
plan=json.loads((ROOT/'sync-plan.json').read_text(encoding='utf-8'))
result=json.loads((ROOT/'sync-result.json').read_text(encoding='utf-8'))
NS={'m':'http://schemas.openxmlformats.org/spreadsheetml/2006/main'}
def read(p):
 with zipfile.ZipFile(p) as z:
  ss=[]
  if 'xl/sharedStrings.xml' in z.namelist():
   ss=[''.join(n.itertext()) for n in E.fromstring(z.read('xl/sharedStrings.xml'))]
  sheets=E.fromstring(z.read('xl/workbook.xml')).find('m:sheets',NS)
  assert len(sheets)==1
  x=E.fromstring(z.read('xl/worksheets/sheet1.xml')); cells={};formulas={}
  for c in x.findall('.//m:sheetData/m:row/m:c',NS):
   typ=c.get('t');v=c.find('m:v',NS);value=v.text if v is not None else ''
   if typ=='s':value=ss[int(value)]
   elif typ=='inlineStr':value=''.join(c.find('m:is',NS).itertext())
   elif typ=='b':value=value=='1'
   elif value and typ not in ('str','e'):
    try:value=float(value);value=int(value) if value.is_integer() else value
    except ValueError:pass
   if value!='':cells[c.get('r')]=value
   f=c.find('m:f',NS)
   if f is not None:formulas[c.get('r')]=E.tostring(f,encoding='unicode')
  tables={n:E.fromstring(z.read(n)) for n in z.namelist() if n.startswith('xl/tables/') and n.endswith('.xml')}
  return cells,formulas,x,tables
def rc(a):
 import re
 c,r=re.fullmatch('([A-Z]+)([0-9]+)',a).groups();return c,int(r)
def col(n):
 s=''
 while n:n,i=divmod(n-1,26);s=chr(65+i)+s
 return s
jobs={j['file']:j for j in plan['jobs']}
changes={}
for x in result['changes']:changes.setdefault(x['file'],{})[x['cell']]=x
reports=[]
for item in result['pending']:
 # Preserve legacy table identity while using the current engine for all cell edits.
 if item.get('originalTableName'):
  out=Path(item['output']);tmp=out.with_suffix('.identity.xlsx')
  with zipfile.ZipFile(out) as src,zipfile.ZipFile(tmp,'w') as dst:
   for info in src.infolist():
    raw=src.read(info.filename)
    if info.filename.startswith('xl/tables/') and info.filename.endswith('.xml'):
     name=item['originalTableName'].encode('utf-8')
     raw=raw.replace(b'name="S00SyncTable"',b'name="'+name+b'"').replace(b'displayName="S00SyncTable"',b'displayName="'+name+b'"')
    dst.writestr(info,raw)
  os.replace(tmp,out)
 before,bf,bx,bt=read(item['input']);after,af,ax,at=read(item['output'])
 assert bf==af,(item['file'],'formula mutation')
 allowed=changes.get(item['file'],{})
 differences={a for a in set(before)|set(after) if before.get(a,'')!=after.get(a,'')}
 unexpected=differences-set(allowed)
 assert not unexpected,(item['file'],'unexpected cells',list(unexpected)[:8])
 for a,change in allowed.items():assert after.get(a,'')==(change['new'] if change['new'] is not None else ''),(item['file'],a,'wrong saved value')
 for a,value in before.items():
  c,r=rc(a)
  if c=='A' and r>=6:assert after.get(a)==value,(item['file'],'ID moved',a)
 assert len(bt)==len(at)==1
 oldtable=next(iter(bt.values()));newtable=next(iter(at.values()))
 assert oldtable.get('name')==newtable.get('name')
 with zipfile.ZipFile(item['input']) as oldzip,zipfile.ZipFile(item['output']) as newzip:
  oldstyles=E.fromstring(oldzip.read('xl/styles.xml'));newstyles=E.fromstring(newzip.read('xl/styles.xml'))
  for oldpart in oldstyles:
   newpart=newstyles.find(oldpart.tag)
   assert newpart is not None and len(newpart)>=len(oldpart)
   assert all(E.tostring(a)==E.tostring(b) for a,b in zip(oldpart,newpart)),(item['file'],'existing style definition changed')
  oldcellstyles={c.get('r'):c.get('s','0') for c in bx.findall('.//m:sheetData/m:row/m:c',NS)}
  newcellstyles={c.get('r'):c.get('s','0') for c in ax.findall('.//m:sheetData/m:row/m:c',NS)}
  for cell,style in oldcellstyles.items():
   column,_=rc(cell)
   if cell in before and not str(before.get(column+'5','')).startswith('正式JSON:') and before.get(column+'5')!='來源同步狀態':
    assert newcellstyles.get(cell,'0')==style,(item['file'],'original column cell style changed',cell)
 # Native sheet controls must survive the export, not just displayed values.
 for tag in ['mergeCells','sheetViews','sheetProtection','dataValidations','conditionalFormatting']:
  old=[E.tostring(x,encoding='unicode') for x in bx.findall('m:'+tag,NS)]
  new=[E.tostring(x,encoding='unicode') for x in ax.findall('m:'+tag,NS)]
  # Attribute defaults/namespaces may normalize; report separately below.
  assert old==new,(item['file'],'unexpected native sheet control change',tag)
 if item['file'] in jobs:
  j=jobs[item['file']];headers={v:rc(a)[0] for a,v in after.items() if rc(a)[1]==5}
  index={str(v):rc(a)[1] for a,v in after.items() if rc(a)[0]=='A' and rc(a)[1]>=6}
  source=j['source_records']
  if j['source_path'].endswith('index.json'):
   actual=json.loads((Path(plan['analysis_dir'])/j['source_path']).read_text(encoding='utf-8'))['items']
   actual=[v for v in actual if v.get('client_version') in (None,'kr')];assert actual==source
  elif j['file']=='13_研究Task.xlsx':
   actual=[json.loads((Path(plan['analysis_dir'])/f'kr/tasks/T{i:02d}/task.json').read_text(encoding='utf-8')) for i in range(1,17)]
   assert actual==source
  elif j['file']=='14_Server待辦.xlsx':
   for row in source:assert (Path(plan['server_dir'])/row['source_path']).read_text(encoding='utf-8')==row['document']
  for record in source:
   for f in j['fields']:
    text=''
    for part in range(f['parts']):
     h='正式JSON:'+f['key']+(f" ({part+1}/{f['parts']})" if f['parts']>1 else '')
     text+=str(after.get(headers[h]+str(index[str(record['id'])]),''))
    if f['key'] in record:assert json.loads(text)==record[f['key']],(item['file'],record['id'],f['key'])
    else:assert text==''
 reports.append({'file':item['file'],'verified_source_records':len(jobs.get(item['file'],{}).get('source_records',[])),
                 'changed_cells':len(differences),'manual_and_unplanned_cells_preserved':True,'existing_ID_rows_preserved':True})
print(json.dumps(reports,ensure_ascii=False))
(ROOT/'saved-file-verification.json').write_text(json.dumps(reports,ensure_ascii=False,indent=2),encoding='utf-8')

if '--promote' in sys.argv:
 history=Path(plan['folder'])/'update-history'
 if (history/(plan['timestamp']+'.json')).exists():
  raise RuntimeError('This run was already promoted; original backups must not be overwritten.')
 # All exports and all preservation assertions succeeded before any replacement.
 backup=Path(result['backup']);backup.mkdir(parents=True,exist_ok=True)
 hashes=[]
 for item in result['pending']:
  src=Path(item['input']);out=Path(item['output'])
  hashes.append({'file':item['file'],'before_sha256':hashlib.sha256(src.read_bytes()).hexdigest(),'after_sha256':hashlib.sha256(out.read_bytes()).hexdigest()})
  shutil.copy2(src,backup/item['file'])
 for item in result['pending']:
  src=Path(item['input']);tmp=src.with_suffix('.sync.xlsx')
  shutil.copy2(item['output'],tmp);os.replace(tmp,src)
 history.mkdir(exist_ok=True)
 receipt={'schema':'s00-full-field-sync-v2','timestamp':plan['timestamp'],
          'analysis_main':plan['analysis_sha'],'server_main':plan['server_sha'],
          'coverage':[{'file':j['file'],'source_path':j['source_path'],'record_count':len(j['source_records']),
                      'field_keys':[f['key'] for f in j['fields']],'split_fields':[f for f in j['fields'] if f['parts']>1]} for j in plan['jobs']],
          'verification':reports,'files':hashes,'changes':result['changes'],
          'limits':['Formal data view only; no maturity, acceptance, runtime or official-backend status promoted.',
                    'Packet/field universe remains incomplete. Source absent/null values are preserved without invention.',
                    'Version-neutral Server requirements are included; explicit TC data is excluded.',
                    'Supplemental JSON columns preserve complete source fields; long cells split at30000 UTF16 units.']}
 (history/(plan['timestamp']+'.json')).write_text(json.dumps(receipt,ensure_ascii=False,indent=2),encoding='utf-8')
 print('PROMOTED',len(hashes),'existing workbooks; backups retained; receipt',history/(plan['timestamp']+'.json'))
