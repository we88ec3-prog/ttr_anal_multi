# -*- coding: utf-8 -*-
"""S00: Tartaros KR 單檔單 Sheet 工作台增量更新工具。

資料來源：本機已同步 main 的 ttr_anal_multi （可另指定 Server checkout）。
只讀 GitHub checkout 內的 JSON/Markdown，寫入本機 XLSX，不做 git branch/commit/push。
依 ID upsert，不刪舊列、不卡行號、不覆蓋人工備註；每次留下 JSON 差異日誌及原檔備份。
使用 artifact_tool，無 openpyxl/pandas。

範例:
  python S00_Excel_增量更新.py --workbooks ./分類工作台 --analysis-dir ./ttr_anal_multi --server-dir ./ttr_server_roy
"""
from __future__ import annotations
import argparse, json, os, re, shutil, subprocess
from datetime import datetime
from pathlib import Path
from collections import Counter
from artifact_tool import Blob, SpreadsheetFile
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

def make_dashboard(folder,sha,server_sha):
 counts={}
 for file,id_col in [('09_研究請求.xlsx',0),('10_Server需求.xlsx',0),('11_規格索引.xlsx',0),('12_缺口索引.xlsx',0),
          ('08_研究證據.xlsx',0),('15_來源清單.xlsx',0),('02_封包總表.xlsx',0),('03_封包欄位.xlsx',0),
          ('05_Server開發.xlsx',0),('14_Server待辦.xlsx',0)]:
  path=folder/file
  if not path.exists():continue
  w=SpreadsheetFile.import_xlsx(Blob.load(str(path)));s=w.worksheets.get_item_at(0)
  values=s.get_range('A6:A2000').values
  counts[file]=sum(bool(r[0]) for r in values)
 def c(f):return counts.get(f,'')
 return [
 ['研究請求 RR',c('09_研究請求.xlsx'),'09_研究請求.xlsx','RR 狀態仍以 GitHub 唯一台帳為準'],
 ['Server 需求 REQ',c('10_Server需求.xlsx'),'10_Server需求.xlsx','不要把 CANDIDATE 當已批准'],
 ['SPEC',c('11_規格索引.xlsx'),'11_規格索引.xlsx','不自動升 STABLE'],
 ['GAP',c('12_缺口索引.xlsx'),'12_缺口索引.xlsx','不要自動關閉 GAP'],
 ['研究證據 CLM',c('08_研究證據.xlsx'),'08_研究證據.xlsx','逐筆保留 evidence_level'],
 ['原始來源 SRC',c('15_來源清單.xlsx'),'15_來源清單.xlsx','REGISTERED 非語意驗證'],
 ['已收錄封包候選',c('02_封包總表.xlsx'),'02_封包總表.xlsx','不是全部原版封包'],
 ['已收錄欄位',c('03_封包欄位.xlsx'),'03_封包欄位.xlsx','不是全部欄位'],
 ['Server 元件',c('05_Server開發.xlsx'),'05_Server開發.xlsx','程式碼實作與 Client 實測分開'],
 ['Server 後續 SFD',c('14_Server待辦.xlsx'),'14_Server待辦.xlsx','Server-only，與 RR 不同'],
 ['分析 main SHA',sha,'17_版本來源.xlsx','本次 Git checkout HEAD；需由 S00 確認等於最新 main'],
 ['Server HEAD SHA',server_sha or '未提供','17_版本來源.xlsx','需由 S00 確認等於最新 main'],
 ]

def xlcol(k):
 res=''
 while k:
  k,i=divmod(k-1,26);res=chr(i+65)+res
 return res

def merge_existing(filename,records,updates,changes,backup_dir):
 """更新現有 workbook 的 record rows；不重建 workbook，也不刪除未知 ID。"""
 if not filename.exists():raise FileNotFoundError(f'找不到既有分類檔，為避免資料遺失不會自動重建：{filename}')
 w=SpreadsheetFile.import_xlsx(Blob.load(str(filename)));sheet=w.worksheets.get_item_at(0)
 n=len(records[0]) if records else 0
 if n==0:return 0
 hdr=sheet.get_range(f'A5:{xlcol(n)}5').values[0]
 if len(hdr)!=n or not hdr[0]:raise ValueError(f'欄位 schema 錯誤：{filename.name}')
 # 只讀現有資料；穩定 ID 而非行號決定更新目標。
 key_cells=sheet.get_range('A6:A2400').values
 last=max((i for i,r in enumerate(key_cells,6) if r[0] not in (None,'')),default=5)
 existing_rows=sheet.get_range(f'A6:{xlcol(n)}{last}').values if last>=6 else []
 active=[list(r) for r in existing_rows if r[0] not in (None,'')]
 index={str(r[0]):i for i,r in enumerate(active)}
 changed=0
 for row in records:
  ident=str(row[0]);new=list(row)
  if ident in index:
   pos=index[ident];old=active[pos];
   for j,value in enumerate(new):
    if value is None:continue  # 預設不碰既有人工摘要與備註欄。
    value=str(value) if isinstance(value,(list,dict)) else value
    if old[j] != value:
     changes.append({'file':filename.name,'id':ident,'field':hdr[j],'old':str(old[j] or '')[:1600], 'new':str(value or '')[:1600]})
     old[j]=value;changed+=1
  else:
   active.append([v if v is not None else '' for v in new]);index[ident]=len(active)-1;changed+=1
   changes.append({'file':filename.name,'id':ident,'action':'NEW_RECORD'})
 if changed:
  backup=backup_dir/filename.name;shutil.copy2(filename,backup)
  sheet.tables.delete_all()
  sheet.get_range(f'A6:{xlcol(n)}{5+len(active)}').values=active
  sheet.tables.add(f'A5:{xlcol(n)}{5+len(active)}',True,'TblUpdated'+re.sub('[^A-Za-z0-9]','',filename.stem))
  temp=filename.with_suffix('.tmp.xlsx');SpreadsheetFile.export_xlsx(w).save(str(temp));os.replace(temp,filename)
  print('UPDATED',filename.name,'records',len(active),'changed fields',changed,flush=True)
 else:print('UNCHANGED',filename.name,'records',len(active),flush=True)
 return changed

def main():
 p=argparse.ArgumentParser(description='按正式 GitHub 台帳增量編輯每分類單Sheet Excel；不更動 GitHub')
 p.add_argument('--workbooks',required=True,type=Path,help='分類 Excel 所在資料夾')
 p.add_argument('--analysis-dir',required=True,type=Path,help='已同步 main 的 ttr_anal_multi checkout')
 p.add_argument('--server-dir',type=Path,help='可選，已同步 main 的 ttr_server_roy checkout')
 p.add_argument('--require-main',action='store_true',help='非 main 分支時拒絕執行（預設只警告）')
 args=p.parse_args();root=args.analysis_dir.resolve();folder=args.workbooks.resolve();server=args.server_dir.resolve() if args.server_dir else None
 if not folder.is_dir() or not root.is_dir():p.error('工作簿目錄或分析 checkout 不存在')
 sha=rev(root);br=branch(root)
 if br!='main':
  if args.require_main:p.error(f'分析 checkout 不是 main（{br}），停止更新')
  print('WARNING: 分析 checkout 不在 main：',br)
 ssha=rev(server) if server else None
 print('Analysis',sha,'branch',br,'Server',ssha or 'not supplied',flush=True)
 # 預先全部讀取/驗證官方來源，避免寫入中途因檔案缺失留下跨檔不一致。
 idx={
  '08_研究證據.xlsx':make_clm(read_json(root,'research/claims/index.json')['items'],sha),
  '15_來源清單.xlsx':make_src(read_json(root,'research/intake/index.json')['items'],sha),
  '09_研究請求.xlsx':make_rr(read_json(root,'research/requests/index.json')['items'],sha),
  '10_Server需求.xlsx':make_req(read_json(root,'design/requirements/index.json')['items'],sha),
  '11_規格索引.xlsx':make_spec(read_json(root,'spec/spec-index.json')['items'],sha),
  '12_缺口索引.xlsx':make_gap(read_json(root,'design/gaps/index.json')['items'],sha),
  '06_測試驗收.xlsx':make_tests(read_json(root,'conformance/test-index.json')['items'],sha),
  '13_研究Task.xlsx':make_task(root,sha),
 }
 if server:
  sf=make_sfd(server,ssha)
  if sf is not None:idx['14_Server待辦.xlsx']=sf
 for fn,r in idx.items():
  keys=[x[0] for x in r]
  if len(keys)!=len(set(keys)):raise ValueError('來源檔有重複主鍵 '+fn)
  if not (folder/fn).exists():raise FileNotFoundError(folder/fn)
 timestamp=datetime.now().strftime('%Y%m%d-%H%M%S');backup_dir=folder/'backup'/timestamp;backup_dir.mkdir(parents=True,exist_ok=True)
 changes=[];total=0
 for fn,rows in idx.items():total+=merge_existing(folder/fn,rows,None,changes,backup_dir)
 # 00 資料欄位為 A5:D5；同步統計不依賴跨檔 Excel 公式。
 if (folder/'00_儀表板.xlsx').exists():
  dash=make_dashboard(folder,sha,ssha)
  total+=merge_existing(folder/'00_儀表板.xlsx',dash,None,changes,backup_dir)
 # 更新 17 的來源基準 SHA，但保留原本其他來源證據與使用者備註。
 if (folder/'17_版本來源.xlsx').exists():
  book=SpreadsheetFile.import_xlsx(Blob.load(str(folder/'17_版本來源.xlsx')));s=book.worksheets.get_item_at(0)
  old=s.get_range('A6:H100').values
  for j,r in enumerate(old,6):
   if r[0]=='權威' and r[1]=='分析與 Server 設計':
    if r[4]!=sha:s.get_range(f'E{j}').values=[[sha]]
   if r[0]=='權威' and r[1]=='Server 程式' and ssha:
    if r[4]!=ssha:s.get_range(f'E{j}').values=[[ssha]]
  filepath=folder/'17_版本來源.xlsx';temp=filepath.with_suffix('.tmp.xlsx')
  if not (backup_dir/filepath.name).exists():shutil.copy2(filepath,backup_dir/filepath.name)
  SpreadsheetFile.export_xlsx(book).save(str(temp));os.replace(temp,filepath)
 log={'timestamp':timestamp,'analysis_sha':sha,'analysis_branch':br,'server_sha':ssha,'changed_cells_or_records':total,
   'changes':changes,'notes':('更新現有 Excel、保留人工備註；01 功能摘要/02 封包候選/03 欄位/04 流程/05 Server 開發/07 資源不從本次官方索引臆造新的內容。','正式 RR/REQ/CLM/SRC/TEST 以 GitHub 權威為準，不自動升證據或驗收。')}
 (folder/'update-history').mkdir(exist_ok=True)
 outfile=folder/'update-history'/(timestamp+'.json');outfile.write_text(json.dumps(log,ensure_ascii=False,indent=2),encoding='utf-8')
 print('FINISHED',total,'change entries',len(changes),'log',outfile,flush=True)

if __name__=='__main__':main()
