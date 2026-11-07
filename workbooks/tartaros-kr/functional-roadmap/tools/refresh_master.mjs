// Update only cached cross-file counts in the existing master; keep manual notes.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {FileBlob,SpreadsheetFile} from '@oai/artifact-tool';
const root=path.resolve(process.argv[2]);
const plan=JSON.parse(await fs.readFile(path.join(root,'plan.json'),'utf8'));
const master=await SpreadsheetFile.importXlsx(await FileBlob.load(path.join(root,'00_開發功能總表.xlsx')));
const summary=master.worksheets.getItemAt(0),grid=summary.getUsedRange().values;
const index=new Map(grid.slice(8).map((r,i)=>[r[0],i+8]));
const records=[];
for(const f of plan.features){
 const w=await SpreadsheetFile.importXlsx(await FileBlob.load(path.join(root,f.file)));w.recalculate();
 const s=w.worksheets.getItemAt(0);
 const counts=[s.getRange('B4').values[0][0],s.getRange('D4').values[0][0],s.getRange('D5').values[0][0],s.getRange('B5').values[0][0]];
 if(counts.some(v=>typeof v!=='number'||v<0)||counts[1]>counts[0]||counts[2]>counts[3])throw Error('Invalid counts '+f.id);
 const row=index.get(f.id);if(row===undefined)throw Error('Master ID missing '+f.id);
 for(const [n,col] of [2,3,5,6].entries())summary.getCell(row,col).values=[[counts[n]]];
 records.push({id:f.id,development_steps:counts[0],implemented:counts[1],human_pass:counts[2],human_targets:counts[3],file_sha256:crypto.createHash('sha256').update(await fs.readFile(path.join(root,f.file))).digest('hex')});
}
summary.getRange('A3').values=[['最後彙整（台北）：'+new Intl.DateTimeFormat('sv-SE',{timeZone:'Asia/Taipei',dateStyle:'short',timeStyle:'short'}).format(new Date())]];
// Optional current-milestone text; do not leave a superseded launch goal above
// otherwise refreshed statistics. Unspecified text/manual notes stay intact.
if(process.argv[4])summary.getRange('A7').values=[[process.argv[4]]];
master.recalculate();
const target=path.join(root,'00_開發功能總表.xlsx'),backup=path.join(root,'backup','master-'+Date.now());
await fs.mkdir(backup,{recursive:true});await fs.copyFile(target,path.join(backup,'00_開發功能總表.xlsx'));
const tmp=target+'.tmp.xlsx';await(await SpreadsheetFile.exportXlsx(master)).save(tmp);await fs.rename(tmp,target);
execFileSync(process.argv[3]||'python',[fileURLToPath(new URL('./add_navigation.py',import.meta.url)),root,'--master-only'],{stdio:'inherit'});
await fs.writeFile(path.join(root,'last-refresh.json'),JSON.stringify({at_utc:new Date().toISOString(),records,manual_notes_preserved:true},null,2));
console.log('Refreshed '+records.length+' feature counts; manual notes preserved.');
