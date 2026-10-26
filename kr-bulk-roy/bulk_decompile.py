"""Explicitly authorized static bulk acquisition. No target execution or semantic acceptance."""
from pathlib import Path
import json,hashlib,subprocess,threading,queue,time,os,datetime,struct,shutil,sys
BASE=Path(__file__).resolve().parent;ROOT=BASE.parent;T06=ROOT/'kr-temp-roy/T06'
TARGET=ROOT.parent/'Tartaros.bin';SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';OUT=BASE/SHA
RAW=OUT/'raw';FUN=OUT/'functions'
for d in [OUT,RAW,FUN]:d.mkdir(parents=True,exist_ok=True)
SERVER=Path('C:/Users/we88e/AppData/Local/npm-cache/_npx/ad9a3fdbcad992c6/node_modules/rea-agents/scripts/rea.mjs')
RUN=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S%f')
q=queue.Queue();seq=0;process=None;opened=False;current={};stats={'inventory':0,'queued':0,'succeeded':0,'failed':0,'seeded':0,'skipped_external_thunk_or_nontext':0};allowed={'open_binary','list_procedures','batch_decompile','close_binary','export_evidence_bundle'}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,v):
 t=p.with_name(p.name+'.tmp');t.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');os.replace(t,p)
def journal(v):
 with (OUT/'journal.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps({'at_utc':now(),**v},ensure_ascii=False)+'\n')
def status(state,**extra):dump(OUT/'status.json',{'state':state,'updated_at_utc':now(),'source_sha256':SHA,'target':str(TARGET),'authority':'shipped static tool output; unreviewed / 待整合','server_pid':process.pid if process else None,'current':current,'counts':stats,**extra})
def unpack(r):
 if isinstance(r.get('structuredContent'),dict):return r['structuredContent']
 texts=[x['text'] for x in r.get('content',[]) if x.get('type')=='text']
 if len(texts)==1:
  try:return json.loads(texts[0])
  except json.JSONDecodeError:pass
 return r
def pump():
 for line in process.stdout:
  try:q.put(json.loads(line))
  except json.JSONDecodeError:journal({'event':'unparsed_stdout','prefix':line[:200]})
 q.put({'_eof':True})
def send(v):process.stdin.write(json.dumps(v,separators=(',',':'))+'\n');process.stdin.flush()
def rpc(method,params,timeout=1800):
 global seq
 seq+=1;rid=seq;send({'jsonrpc':'2.0','id':rid,'method':method,'params':params});deadline=time.monotonic()+timeout
 while True:
  remaining=deadline-time.monotonic()
  if remaining<=0:raise TimeoutError('RPC deadline '+method)
  try:m=q.get(timeout=min(remaining,15))
  except queue.Empty:
   if process.poll() is not None:raise RuntimeError('REA exited '+str(process.returncode))
   status('running');continue
  if m.get('_eof'):raise RuntimeError('REA stdout closed')
  if m.get('id')==rid:
   if 'error' in m:raise RuntimeError(json.dumps(m['error']))
   return m['result']
  if 'method' in m and 'id' in m:send({'jsonrpc':'2.0','id':m['id'],'error':{'code':-32601,'message':'Static acquisition does not provide sampling or external actions'}})
def call(name,args,label):
 assert name in allowed;current.clear();current.update(tool=name,label=label,started_at_utc=now());status('running');journal({'event':'request_started','tool':name,'label':label,'arguments':args})
 result=rpc('tools/call',{'name':name,'arguments':args});value=unpack(result);p=RAW/(RUN+'-'+label+'.json');dump(p,value);journal({'event':'request_saved','tool':name,'label':label,'path':str(p.relative_to(OUT)),'sha256':sha(p),'is_error':bool(result.get('isError'))})
 if result.get('isError'):
  error=value.get('error',{});limits=error.get('details',{}).get('reported_limits',{});eid=limits.get('evidence_id')
  if error.get('code')=='resource_constraint' and limits.get('boundary')=='mcp-response' and isinstance(eid,str) and name!='export_evidence_bundle':
   # Follow the provider's explicit remediation while its retained result is still live.
   export_path=RAW/(RUN+'-'+label+'-retained-bundle.json');call('export_evidence_bundle',{'path':str(export_path)},label+'-export');bundle=json.loads(export_path.read_text(encoding='utf-8'));records=bundle.get('records',[]);matches=[r for r in records if r.get('evidence_id')==eid];assert len(matches)==1
   value=matches[0];assert value.get('operation')==name;complete=RAW/(RUN+'-'+label+'-complete.json');dump(complete,value);journal({'event':'transport_limit_recovered_from_local_export','tool':name,'evidence_id':eid,'export_path':export_path.relative_to(OUT).as_posix(),'export_sha256':sha(export_path),'complete_path':complete.relative_to(OUT).as_posix(),'complete_sha256':sha(complete)});p=complete
  else:raise RuntimeError('Saved REA error: '+label)
 subject=value.get('subject',{});digest=subject.get('digest',{}).get('sha256',subject.get('sha256'))
 if digest is not None:assert digest==SHA
 return value,p
def nr(v):return v.get('normalized_result',v.get('result',v))
def append_index(r):
 with (OUT/'index.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(r,ensure_ascii=False)+'\n')
done=set()
if (OUT/'index.jsonl').exists():
 for line in (OUT/'index.jsonl').read_text(encoding='utf-8').splitlines():
  r=json.loads(line)
  if r.get('status')=='ok':
   p=OUT/r['pseudocode_path'];assert sha(p)==r['pseudocode_sha256'];done.add(r['address'])
stats['succeeded']=len(done)
assert sha(TARGET)==SHA
dump(OUT/'target.json',{'path':str(TARGET),'sha256':SHA,'bytes':TARGET.stat().st_size,'authority':'User-authorized bulk static acquisition; not semantic review','scope':'Enumerated .text procedures excluding provider-marked external/thunk; skipped inventory saved','tool_versions':{'REA':'6.5.0','Ghidra':'12.1.4'},'batch_size':16})
# Reuse verified existing dossiers without re-decompiling them.
for status_path in sorted((T06/'evidence').glob('*session-status.json')):
 try:records=json.loads(status_path.read_text(encoding='utf-8'))['completed']
 except (ValueError,KeyError):continue
 for record in records:
  if record.get('tool')!='analyze_function' or record.get('is_error'):continue
  p=T06/record['path']
  if sha(p)!=record['sha256']:raise RuntimeError('Changed seed Evidence '+str(p))
  v=json.loads(p.read_text(encoding='utf-8'));n=v.get('normalized_result',{});address=n.get('procedure',{}).get('address');code=n.get('pseudocode')
  if v.get('subject',{}).get('digest',{}).get('sha256')!=SHA or not address or not isinstance(code,str) or not code or address in done:continue
  dest=FUN/(address+'.c');dest.write_text(code,encoding='utf-8');append_index({'address':address,'status':'ok','authority':'unreviewed bulk copy; original task review status separate','source_sha256':SHA,'seed_evidence':str(p.relative_to(ROOT)),'seed_evidence_sha256':record['sha256'],'pseudocode_path':dest.relative_to(OUT).as_posix(),'pseudocode_sha256':sha(dest)});done.add(address);stats['seeded']+=1;stats['succeeded']+=1
status('queued_waiting_for_story2_close')
while True:
 p=T06/'evidence/story2-session-status.json'
 try:s=json.loads(p.read_text(encoding='utf-8'))
 except (OSError,ValueError):s={}
 if s.get('state')=='closed':break
 if s.get('state')=='error':status('blocked_previous_session_error');raise SystemExit('Previous session error requires review')
 time.sleep(5)
def build_queue(value):
 assert value['operation']=='list_procedures' and value['subject']['digest']['sha256']==SHA
 assert value['provider']['id']=='ghidra' and value['provider']['version']=='12.1.4'
 items=nr(value);assert isinstance(items,list)
 raw=TARGET.read_bytes();pe=struct.unpack_from('<I',raw,60)[0];count=struct.unpack_from('<H',raw,pe+6)[0];sz=struct.unpack_from('<H',raw,pe+20)[0];sections=[]
 for i in range(count):
  at=pe+24+sz+i*40;name=raw[at:at+8].rstrip(b'\0');virtual_size,va,rawsize,ptr=struct.unpack_from('<IIII',raw,at+8)
  if name==b'.text':sections.append((0x400000+va,0x400000+va+virtual_size))
 cat=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'));known={e['va']:e['primary_task'] for e in cat['entities'] if e['version']=='kr'};eligible=[];skipped=[]
 for item in items:
  address=item['address'];cls=item.get('procedure') or {};inside=False
  if address.startswith('0x'):
   try:inside=any(lo<=int(address,16)<hi for lo,hi in sections)
   except ValueError:pass
  if cls.get('external') or cls.get('thunk') or not inside:skipped.append(item)
  else:eligible.append(item)
 eligible.sort(key=lambda x:(0 if known.get(x['address'])=='T06' else 1 if x['address'] in known else 2,int(x['address'],16)));dump(OUT/'skipped-inventory.json',{'items':skipped,'reason':'provider external/thunk, nondefault address space or outside original.text; not success'});addresses=list(dict.fromkeys(x['address'] for x in eligible if x['address'] not in done));dump(OUT/'queue.json',{'source_sha256':SHA,'addresses':addresses,'known_semantic_ownership':known,'ownership_effect':'None: raw acquisition only'});stats.update(inventory=len(items),queued=len(addresses),skipped_external_thunk_or_nontext=len(skipped));return addresses
assert sha(TARGET)==SHA
try:
 cached=None;manifest_path=OUT/'inventory-manifest.json'
 if manifest_path.exists():
  manifest=json.loads(manifest_path.read_text(encoding='utf-8'));p=(OUT/manifest['path']).resolve();assert p.is_relative_to(OUT.resolve()) and sha(p)==manifest['sha256'];assert manifest['source_sha256']==SHA;cached=json.loads(p.read_text(encoding='utf-8'));addresses=build_queue(cached);journal({'event':'verified_inventory_reused','path':manifest['path'],'sha256':manifest['sha256'],'entries':stats['inventory']})
 if '--preflight-only' in sys.argv:
  assert cached is not None;status('preflight_ready',first_addresses=addresses[:16]);raise SystemExit(0)
 env=os.environ.copy();env['GHIDRA_INSTALL_DIR']='E:/Tools/ghidra_12.1.4_PUBLIC';env['REA_GHIDRA_STARTUP_TIMEOUT_MS']='900000'
 stderr=(OUT/(RUN+'-server.stderr.txt')).open('w',encoding='utf-8');process=subprocess.Popen(['node',str(SERVER),'--mcp'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=stderr,text=True,encoding='utf-8',env=env,bufsize=1);threading.Thread(target=pump,daemon=True).start()
 init=rpc('initialize',{'protocolVersion':'2025-06-18','capabilities':{},'clientInfo':{'name':'kr-roy-bulk-static-acquisition','version':'1.0'}});dump(OUT/'server-info.json',init);send({'jsonrpc':'2.0','method':'notifications/initialized','params':{}});inventory=rpc('tools/list',{});advertised={t['name'] for t in inventory['tools']};assert allowed<=advertised
 value,p=call('open_binary',{'path':str(TARGET),'provider_id':'ghidra'},'open');assert value['result']['sha256']==SHA;opened=True
 if cached is None:
  value,p=call('list_procedures',{},'procedure-inventory');dump(manifest_path,{'source_sha256':SHA,'path':p.relative_to(OUT).as_posix(),'sha256':sha(p),'analysis_profile_digest':(value.get('analysis_profile') or {}).get('digest')});addresses=build_queue(value)
 status('running')
 for begin in range(0,len(addresses),16):
  if shutil.disk_usage(OUT).free<256*1024*1024:raise RuntimeError('Output filesystem below256MiB free; saved partial work')
  selected=addresses[begin:begin+16];label='batch-'+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S%f')+'-'+str(begin);value,p=call('batch_decompile',{'addresses':selected},label);result=nr(value)
  if not isinstance(result,dict) or not isinstance(result.get('items'),list):raise RuntimeError('Unexpected batch schema; raw saved')
  returned=result['items'];assert [r['address'] for r in returned]==selected
  for item in returned:
   address=item['address'];row={'address':address,'status':item['status'],'source_sha256':SHA,'authority':'unreviewed static output / 待整合','batch_path':p.relative_to(OUT).as_posix(),'batch_sha256':sha(p),'procedure':item.get('procedure')}
   if item['status']=='ok':
    code=item['pseudocode'];assert isinstance(code,str);dest=FUN/(address+'.c');dest.write_text(code,encoding='utf-8');row.update(pseudocode_path=dest.relative_to(OUT).as_posix(),pseudocode_sha256=sha(dest));done.add(address);stats['succeeded']+=1
   else:row['error']=item.get('error');stats['failed']+=1
   append_index(row)
  current.clear();status('running',completed_queue_items=begin+len(selected));journal({'event':'batch_indexed','label':label,'items':len(returned),'counts':dict(stats)})
 call('close_binary',{},'close');opened=False;current.clear();status('acquisition_complete_review_unverified',remaining_queue_items=0)
except BaseException as exc:
 if isinstance(exc,SystemExit) and exc.code==0:raise
 journal({'event':'worker_error','error':str(exc)})
 if opened:
  try:call('close_binary',{},'error-close');opened=False
  except Exception as close_error:journal({'event':'close_error','error':str(close_error)})
 current.clear();status('error',error=str(exc),native_session_closed=not opened)
 raise
finally:
 if process:
  try:process.stdin.close();process.wait(timeout=15)
  except Exception:process.terminate();process.wait(timeout=15)
 try:stderr.close()
 except Exception:pass
