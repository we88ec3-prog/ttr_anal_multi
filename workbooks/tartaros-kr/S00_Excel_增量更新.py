# -*- coding: utf-8 -*-
"""S00: Tartaros KR 單檔單 Sheet 工作台增量更新工具。

資料來源：本機已同步 main 的 ttr_anal_multi （可另指定 Server checkout）。
只讀 GitHub checkout 內的 JSON/Markdown，寫入本機 XLSX，不做 git branch/commit/push。
依 ID upsert，不刪舊列、不卡行號、不覆蓋人工備註；每次留下 JSON 差異日誌及原檔備份。
使用 bundled @oai/artifact-tool JavaScript，無 openpyxl/pandas；先暫存，再獨立驗證發布。

範例:
  python S00_Excel_增量更新.py --workbooks ./分類工作台 --analysis-dir ./ttr_anal_multi --server-dir ./ttr_server_roy
"""
from __future__ import annotations
import argparse, json, os, re, shutil, subprocess
from datetime import datetime
from pathlib import Path
ANALYSIS_REPO='we88ec3-prog/ttr_anal_multi'
SERVER_REPO='we88ec3-prog/ttr_server_roy'

def flatten(v,sep=' | '):
 if v is None:return ''
 if isinstance(v,(list,tuple)):
  return sep.join(map(str,v))
 return str(v)

def url(repo,sha,path):
 return f'https://github.com/{repo}/blob/{sha}/{path}' if path else ''

def read_json(root,path):
 filename=root/path
 if not filename.is_file():
  raise FileNotFoundError(f'找不到官方台帳：{filename}')
 return json.loads(filename.read_text(encoding='utf-8'))

def rev(root):
 try:
  p=subprocess.run(['git','-C',str(root),'rev-parse','HEAD'],capture_output=True,text=True,check=True)
  return p.stdout.strip()
 except Exception as exc:
  raise RuntimeError(f'{root} 不是可核對 SHA 的 Git checkout，請先檢查 main。') from exc

def branch(root):
 try:return subprocess.run(['git','-C',str(root),'branch','--show-current'],capture_output=True,text=True,check=True).stdout.strip()
 except Exception:return '?'

def make_clm(items,sha):
 rows=[]
 for v in items:
  ident=v['id'];p=v.get('source_file','')
  rows.append([ident,v.get('client_version','kr').upper(),ident.split('-')[1],v.get('evidence_level',''),
   v.get('evidence_scope',''),v.get('assertion',''),flatten(v.get('limitations')),
   v.get('source_intake_id',''),p,v.get('source_blob_sha',''),flatten(v.get('affected_spec_ids'),' '),
   v.get('native_review_ref') or v.get('review_ref') or '',None,url(ANALYSIS_REPO,sha,p),url(ANALYSIS_REPO,sha,'research/claims/index.json'),None])
 return rows

def make_src(items,sha):
 rows=[]
 for v in items:
  p=v.get('source_file','')
  rows.append([v['id'],v.get('client_version','kr').upper(),v.get('integration_status',''),p,
   v.get('source_blob_sha',''),v.get('source_sha256',''),flatten(v.get('claim_ids'),' '),
   v.get('original_document_review_status',''),flatten(v.get('conflict_disposition')),
   flatten(v.get('limitations')),url(ANALYSIS_REPO,sha,p),url(ANALYSIS_REPO,sha,'research/intake/index.json'),None])
 return rows

def make_rr(items,sha):
 r=[]
 for v in items:
  disp=v.get('dispatch') or {};sub=disp.get('submission') or {};path=sub.get('report_path') or ''
  r.append([v['id'],v.get('title',''),v.get('client_version',''),v.get('owner_task',''),
   disp.get('state',''),disp.get('priority',''),v.get('status',''),flatten(v.get('gap_ids'),' '),
   path,url(ANALYSIS_REPO,sha,path),url(ANALYSIS_REPO,sha,'research/requests/index.json')])
 return r

def make_req(items,sha):
 return [[v['id'],v.get('title',''),v.get('client_version',''),v.get('priority',''),v.get('status',''),
   v.get('need',''),flatten(v.get('rr_ids'),' '),flatten(v.get('gap_ids'),' '),flatten(v.get('spec_ids'),' '),
   flatten(v.get('claim_ids'),' '),url(ANALYSIS_REPO,sha,'design/requirements/index.json')] for v in items]

def make_spec(items,sha):
 return [[v['id'],v.get('title',''),v.get('client_version',''),v.get('module',''),v.get('maturity',''),
   v.get('contract_status',''),flatten(v.get('source_tasks'),' '),flatten(v.get('gap_ids'),' '),
   flatten(v.get('test_ids'),' '),url(ANALYSIS_REPO,sha,v.get('spec_path',''))] for v in items]

def make_gap(items,sha):
 return [[v['id'],v.get('title',''),v.get('client_version',''),v.get('type',''),v.get('priority',''),
    v.get('status',''),v.get('owner_task',''),flatten(v.get('affected_spec_ids'),' '),
    v.get('resolution_criteria',''),url(ANALYSIS_REPO,sha,'design/gaps/index.json')] for v in items]

def make_task(root,sha):
 rows=[]
 for n in range(1,17):
  ident=f'T{n:02d}';p=f'kr/tasks/{ident}/task.json';v=read_json(root,p)
  rows.append([ident,v.get('title',''),'KR',v.get('owner',''),v.get('state',''),str(v.get('native_complete','')).lower(),
   v.get('scope',''),url(ANALYSIS_REPO,sha,p),url(ANALYSIS_REPO,sha,f'kr/tasks/{ident}/README.md')])
 return rows

def make_tests(items,sha):
 r=[]
 for v in items:
  r.append([v['id'],'正式 TEST',v.get('client_version',''),v.get('title',''),v.get('status',''),
      '未於本次更新中執行','離線 synthetic/既有正式 contract，不代表原版 Client 可玩','',
      flatten(v.get('spec_ids'),' '),flatten(v.get('source_claim_ids'),' '),
      url(ANALYSIS_REPO,sha,v.get('test_path','')),url(ANALYSIS_REPO,sha,'conformance/test-index.json')])
 return r

def make_sfd(server_root,sha):
 if not server_root:return None
 p=server_root/'docs/server-followups/index.md'
 if not p.exists():return None
 rows=[]
 for line in p.read_text(encoding='utf-8').splitlines():
  if not re.match(r'^\| \[SFD-\d{4}\]',line):continue
  cols=[s.strip() for s in line.strip().strip('|').split('|')]
  if len(cols)<6:continue
  m=re.match(r'\[([^\]]+)\]\(([^)]+)\)',cols[0]);
  if not m:continue
  ident,basename=m.groups();path='docs/server-followups/'+basename
  rows.append([ident,cols[1],cols[2],cols[3],cols[4],url(SERVER_REPO,sha,path),
   url(SERVER_REPO,sha,'docs/server-followups/index.md')])
 return rows

# Runtime writer is the bundled @oai/artifact-tool JavaScript implementation.
# Existing reader mappings remain above; every source field is additionally
# preserved losslessly in typed JSON columns, split below Excel's cell limit.
def main():
 import tempfile, sys
 p=argparse.ArgumentParser(description=__doc__)
 p.add_argument('--workbooks',required=True,type=Path)
 p.add_argument('--analysis-dir',required=True,type=Path)
 p.add_argument('--server-dir',required=True,type=Path)
 p.add_argument('--require-main',action='store_true')
 p.add_argument('--node',default=os.environ.get('TARTAROS_WORKBOOK_NODE','node'))
 p.add_argument('--runner-dir',required=True,type=Path,help='Conversation directory with a junction to bundled node_modules')
 a=p.parse_args();root=a.analysis_dir.resolve();server=a.server_dir.resolve();folder=a.workbooks.resolve()
 sha=rev(root);ssha=rev(server)
 for repo in (root,server):
  if branch(repo)!='main':p.error(f'Only main checkout is supported: {repo}')
  remote=subprocess.run(['git','-C',str(repo),'rev-parse','origin/main'],capture_output=True,text=True,check=True).stdout.strip()
  if rev(repo)!=remote:p.error(f'HEAD differs from fetched origin/main: {repo}')
 records={
  '08_研究證據.xlsx':('research/claims/index.json',make_clm),
  '15_來源清單.xlsx':('research/intake/index.json',make_src),
  '09_研究請求.xlsx':('research/requests/index.json',make_rr),
  '10_Server需求.xlsx':('design/requirements/index.json',make_req),
  '11_規格索引.xlsx':('spec/spec-index.json',make_spec),
  '12_缺口索引.xlsx':('design/gaps/index.json',make_gap),
  '06_測試驗收.xlsx':('conformance/test-index.json',make_tests),
 }
 jobs=[]
 for filename,(path,maker) in records.items():
  data=read_json(root,path)['items']
  data=[v for v in data if v.get('client_version') in (None,'kr')]
  jobs.append(dict(file=filename,rows=maker(data,sha),source_records=data,source_path=path))
 tasks=[read_json(root,f'kr/tasks/T{i:02d}/task.json') for i in range(1,17)]
 jobs.append(dict(file='13_研究Task.xlsx',rows=make_task(root,sha),source_records=tasks,source_path='kr/tasks/Txx/task.json'))
 sf=make_sfd(server,ssha)
 if sf is None:raise FileNotFoundError('Server follow-up index missing')
 raw_sfd=[]
 for row in sf:
  path=row[5].split('/blob/'+ssha+'/')[1]
  text=(server/path).read_text(encoding='utf-8')
  raw_sfd.append(dict(id=row[0],status=row[1],priority=row[2],milestone=row[3],title=row[4],source_path=path,document=text))
 jobs.append(dict(file='14_Server待辦.xlsx',rows=sf,source_records=raw_sfd,source_path='docs/server-followups/index.md'))
 for job in jobs:
  ids=[str(v['id']) for v in job['source_records']]
  if len(ids)!=len(set(ids)):raise ValueError('Duplicate source IDs: '+job['file'])
  if not (folder/job['file']).is_file():raise FileNotFoundError(job['file'])
  if len(ids)!=len(job['rows']):raise ValueError('Row count mismatch')
  keys=sorted(set().union(*(v.keys() for v in job['source_records'])))
  fields=[]
  for key in keys:
   count=max(1,max((len(json.dumps(v.get(key),ensure_ascii=False,separators=(',',':')).encode('utf-16-le'))//2 + 29999)//30000 for v in job['source_records']))
   fields.append(dict(key=key,parts=count))
  job['fields']=fields
  job['field_values']=[[json.dumps(v.get(f['key']),ensure_ascii=False,separators=(',',':')) if f['key'] in v else '' for f in fields] for v in job['source_records']]
 stamp=datetime.now().astimezone().strftime('%Y%m%d-%H%M%S')
 plan=dict(schema='s00-full-field-sync-v2',timestamp=stamp,analysis_sha=sha,server_sha=ssha,analysis_dir=str(root),server_dir=str(server),folder=str(folder),jobs=jobs)
 run=a.runner_dir.resolve();run.mkdir(parents=True,exist_ok=True)
 planfile=run/'sync-plan.json';planfile.write_text(json.dumps(plan,ensure_ascii=False,indent=2),encoding='utf-8')
 writer=run/'S00_workbook_writer.mjs';shutil.copy2(Path(__file__).with_name('S00_workbook_writer.mjs'),writer)
 subprocess.run([a.node,str(writer),str(planfile)],check=True)
 print('Sync prepared and exported. Verify saved files and manual preservation before Git submission.')

if __name__=='__main__':main()
