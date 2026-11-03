import fs from 'node:fs/promises';
import path from 'node:path';
import {FileBlob,SpreadsheetFile} from '@oai/artifact-tool';

const plan=JSON.parse(await fs.readFile(process.argv[2],'utf8'));
const folder=plan.folder, run=path.dirname(process.argv[2]);
const backup=path.join(folder,'backup',plan.timestamp);
const stage=path.join(run,'staged',plan.timestamp);
await fs.mkdir(backup,{recursive:true}); await fs.mkdir(stage,{recursive:true});
const changes=[], results=[], pending=[];
function col(n){let s='';for(;n;n=Math.floor((n-1)/26))s=String.fromCharCode(65+(n-1)%26)+s;return s;}
function eq(a,b){return (a??'')===(b??'');}
async function edit(file, rows, fields=[], fieldValues=[]){
 const input=path.join(folder,file);
 const w=await SpreadsheetFile.importXlsx(await FileBlob.load(input));
 if(w.worksheets.items.length!==1)throw Error(file+': expected exactly one sheet');
 const s=w.worksheets.getItemAt(0), grid=s.getUsedRange().values;
 const oldHeaders=grid[4]??[], headers=[...oldHeaders];
 let last=5; const index=new Map();
 for(let r=5;r<grid.length;r++)if(grid[r]?.[0]!==null && grid[r]?.[0]!==undefined && grid[r]?.[0]!==''){
  const key=String(grid[r][0]);if(index.has(key))throw Error(file+': duplicate existing ID '+key);
  index.set(key,r);last=Math.max(last,r+1);
 }
 let changed=0;
 function set(r,c,value,id){
  if(typeof value==='string' && value.length>32767)throw Error('Cell overflow '+file+' '+id);
  const old=grid[r]?.[c]??null;
  if(eq(old,value))return;
  // Values beginning '=' are literal source content, never executable formulas.
  s.getCell(r,c).values=[[typeof value==='string'&&value.startsWith('=')?"'"+value:value]];
  changes.push({file,id,cell:col(c+1)+(r+1),field:headers[c]??'',old,new:value});
  grid[r]??=[];grid[r][c]=value;changed++;
 }
 const extra=[];
 for(const f of fields){
  const positions=[];
  for(let part=0;part<f.parts;part++){
   const name='正式JSON:'+f.key+(f.parts>1?` (${part+1}/${f.parts})`:'');
   let c=headers.indexOf(name);if(c<0){c=headers.length;headers.push(name);}
   positions.push(c);set(4,c,name,'HEADER');
  }extra.push(positions);
 }
 for(let i=0;i<rows.length;i++){
  const row=rows[i],id=String(row[0]);let r=index.get(id);
  if(r===undefined){r=last++;index.set(id,r);}
  row.forEach((v,c)=>{if(v!==null && v!==undefined)set(r,c,v,id);});
  for(let f=0;f<extra.length;f++)for(let part=0;part<extra[f].length;part++)
   set(r,extra[f][part],fieldValues[i][f].slice(part*30000,(part+1)*30000),id);
 }
 const sourceIds=new Set(rows.map(r=>String(r[0])));
 const missing=[...index.keys()].filter(id=>!sourceIds.has(id));
 if(fields.length && missing.length){
  let c=headers.indexOf('來源同步狀態');if(c<0){c=headers.length;headers.push('來源同步狀態');set(4,c,'來源同步狀態','HEADER');}
  const prefix=String(rows[0]?.[0]??'').split('-')[0];
  for(const id of missing){
   const formal=file==='13_研究Task.xlsx'?/^T\d+$/.test(id):id.startsWith(prefix+'-');
   set(index.get(id),c,formal?'來源已不見／需核對':'人工記錄／本次不自動同步',id);
  }
 }
 if(changed || fields.length){
  const tables=s.tables.items.map(t=>({name:t.name,style:t.style,showHeaders:t.showHeaders,showFilterButton:t.showFilterButton,showBandedColumns:t.showBandedColumns,showTotals:t.showTotals}));
  if(tables.length!==1)throw Error(file+': expected one existing table');
  if(fields.length){
   // Formal JSON columns can be separated by retained human columns.
   // Format each owned column, never the bounding span across those notes.
   for(const c of extra.flat()){
    const letter=col(c+1),area=s.getRange(`${letter}5:${letter}${last}`);
    area.format.columnWidthPx=240;area.format.wrapText=true;area.format.verticalAlignment='top';
    const header=s.getRange(`${letter}5`);
    header.format.fill='#087789';header.format.font={bold:true,color:'#FFFFFF',size:10};
   }
  }
  s.tables.items[0].delete();
  // Some legacy names (e.g. Tbl15) look like cell references to the current
  // engine. Use a temporary export name; the promotion verifier restores the
  // original OOXML table name without touching data, styles or references.
  const t=s.tables.add(`A5:${col(headers.length)}${last}`,true,'S00SyncTable');
  t.style=tables[0].style;t.showFilterButton=tables[0].showFilterButton;
  t.showBandedColumns=tables[0].showBandedColumns;t.showTotals=tables[0].showTotals;
  w.recalculate();
  // Verify every declared machine field, including split long values, in memory.
  for(let i=0;i<rows.length;i++)for(let f=0;f<extra.length;f++){
   const r=index.get(String(rows[i][0]));
   const got=extra[f].map(c=>s.getCell(r,c).values[0][0]??'').join('');
   if(got!==fieldValues[i][f])throw Error('Field verification failed '+file+' '+rows[i][0]+' '+fields[f].key);
  }
  const errors=await w.inspect({kind:'match',searchTerm:'#REF!|#DIV/0!|#VALUE!|#NAME\\?|#NUM!|#SPILL!|#CALC!',options:{useRegex:true,maxResults:10},maxChars:1500});
  const output=path.join(stage,file);await (await SpreadsheetFile.exportXlsx(w)).save(output);
  const preview=await w.render({sheetName:s.name,range:'A5:F8',scale:1});
  await fs.writeFile(path.join(stage,file+'.png'),new Uint8Array(await preview.arrayBuffer()));
  pending.push({input,output,file,originalTableName:tables[0].name});
  results.push({file,source_records:rows.length,retained_records:index.size,columns:headers.length,changed_cells:changed,missing_source_ids:missing,formula_scan:errors.ndjson});
 }else results.push({file,source_records:rows.length,changed_cells:0});
 console.log(JSON.stringify({file,sourceRecords:rows.length,changedCells:changed}));
}
for(const job of plan.jobs)await edit(job.file,job.rows,job.fields,job.field_values);
const counts=Object.fromEntries(plan.jobs.map(j=>[j.file,j.rows.length]));
// Existing dashboard labels are stable keys; unrelated rows are retained.
const labels={'09_研究請求.xlsx':'研究請求 RR','10_Server需求.xlsx':'Server 需求 REQ','11_規格索引.xlsx':'SPEC','12_缺口索引.xlsx':'GAP','08_研究證據.xlsx':'研究證據 CLM','15_來源清單.xlsx':'原始來源 SRC','14_Server待辦.xlsx':'Server 後續 SFD'};
const dash=[];
for(const [file,label] of Object.entries(labels))dash.push([label,counts[file],file,null]);
dash.push(['分析 main SHA',plan.analysis_sha,'17_版本來源.xlsx',null],['Server HEAD SHA',plan.server_sha,'17_版本來源.xlsx',null]);
await edit('00_儀表板.xlsx',dash);
// Version register: update only matching authority rows, preserve dates/notes.
const vw=await SpreadsheetFile.importXlsx(await FileBlob.load(path.join(folder,'17_版本來源.xlsx')));
const vs=vw.worksheets.getItemAt(0), versions=[];
for(const row of vs.getUsedRange().values.slice(5)){
 if(row[0]==='權威' && ['分析與 Server 設計','Server 程式'].includes(row[1])){
  const copy=row.map((v,i)=>i===4?(row[1]==='Server 程式'?plan.server_sha:plan.analysis_sha):null);
  // Composite display keys are not unique in column A; direct bounded update.
  const values=vs.getUsedRange().values;const r=values.findIndex(x=>x[0]===row[0]&&x[1]===row[1]);
  if(!eq(row[4],copy[4])){vs.getCell(r,4).values=[[copy[4]]];changes.push({file:'17_版本來源.xlsx',id:row[1],cell:'E'+(r+1),old:row[4],new:copy[4]});}
 }
}
vw.recalculate();
const versionOut=path.join(stage,'17_版本來源.xlsx');await(await SpreadsheetFile.exportXlsx(vw)).save(versionOut);
pending.push({input:path.join(folder,'17_版本來源.xlsx'),output:versionOut,file:'17_版本來源.xlsx'});
// Staging is intentional: independent saved-file verification precedes promotion.
const log={...plan,jobs:undefined,results,changes,pending,backup,stage};
await fs.writeFile(path.join(run,'sync-result.json'),JSON.stringify(log,null,2));
console.log('STAGED: independent saved-file verification required before promotion');
