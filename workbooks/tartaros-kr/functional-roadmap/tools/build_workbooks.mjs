import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {pathToFileURL} from 'node:url';
import {Workbook,SpreadsheetFile,FileBlob} from '@oai/artifact-tool';
export const colors={navy:'#233B53',teal:'#267D8C',pale:'#EAF3F5',ink:'#203344',gray:'#60758A'};
const xlstr=s=>String(s).replaceAll('"','""');
const headers=['項次／ID','子功能／任務','開發子項','已實作','開發完成度','人測通過','人測項目','實測通過率','目前狀態','下一步'];
export function stats(f){return f.items.reduce((a,i)=>{for(const s of i.steps){if(s.kind==='開發'){a.dev++;if(s.dev==='已實作')a.done++;}if(s.kind==='工作副本人測'){a.tests++;if(s.test==='通過')a.pass++;}}return a;},{dev:0,done:0,tests:0,pass:0});}
function base(s,title,note,lastCol='J'){
 s.showGridLines=false;s.getRange(`A1:${lastCol}5`).format.font={name:'Arial',size:10,color:colors.ink};
 s.getRange('A1').values=[[title]];s.getRange('A1').format.font={name:'Arial',size:16,bold:true,color:colors.navy};
 s.getRange('A2').values=[[note]];s.getRange('A2').format.font={size:10,color:colors.gray};
 s.getRange(`A1:${lastCol}2`).format.rowHeight=26;
 s.freezePanes.freezeRows(8);s.freezePanes.freezeColumns(2);
}
function metrics(s,last,devCol='C',doneCol='D',passCol='F',testCol='G'){
 s.getRange('A4:F5').values=[['開發子項',null,'已實作',null,'開發完成度',null],['人測項目',null,'工作副本通過',null,'實測通過率',null]];
 s.getRange('B4').formulas=[[`=SUM(${devCol}9:${devCol}${last})`]];
 s.getRange('D4').formulas=[[`=SUM(${doneCol}9:${doneCol}${last})`]];
 s.getRange('F4').formulas=[['=IF(B4=0,0,D4/B4)']];
 s.getRange('B5').formulas=[[`=SUM(${testCol}9:${testCol}${last})`]];
 s.getRange('D5').formulas=[[`=SUM(${passCol}9:${passCol}${last})`]];
 s.getRange('F5').formulas=[['=IF(B5=0,0,D5/B5)']];
 s.getRange('A4:F5').format.fill=colors.pale;s.getRange('A4:F5').format.rowHeight=27;
 s.getRange('F4:F5').setNumberFormat('0.0%');
}
function table(s,range,name){const t=s.tables.add(range,true,name);t.style='TableStyleMedium2';return t;}
function tableStyle(s,last,cols){
 s.getRange(`A8:${cols}${last}`).format.font={name:'Arial',size:10,color:colors.ink};
 s.getRange(`A8:${cols}8`).format.fill=colors.navy;s.getRange(`A8:${cols}8`).format.font={bold:true,color:'#FFFFFF',size:10};
 s.getRange(`A8:${cols}8`).format.rowHeight=30;s.getRange(`A8:${cols}${last}`).format.verticalAlignment='center';
 s.getRange(`A9:${cols}${last}`).format.rowHeight=30;
}
function overview(w,f){
 const s=w.worksheets.add('功能總表');
 base(s,f.title,'開發＝已實作子項／開發子項；人測＝工作副本通過／人測項目。資源已找到不算完成。');
 const last=8+f.items.length;s.getRange('A8:J8').values=[headers];
 const rows=f.items.map((i,n)=>[i.id,i.title,null,null,null,null,null,null,null,i.note||'先完成子頁中的待分析／待開發項。']);
 s.getRange(`A9:J${last}`).values=rows;
 metrics(s,last);table(s,`A8:J${last}`,'FeatureSummary');tableStyle(s,last,'J');
 s.getRange(`A8:A${last}`).format.columnWidthPx=160;s.getRange(`B8:B${last}`).format.columnWidthPx=330;
 s.getRange(`C8:D${last}`).format.columnWidthPx=90;s.getRange(`E8:H${last}`).format.columnWidthPx=115;
 s.getRange(`I8:I${last}`).format.columnWidthPx=145;s.getRange(`J8:J${last}`).format.columnWidthPx=380;
 s.getRange(`B9:B${last}`).format.wrapText=true;s.getRange(`J9:J${last}`).format.wrapText=true;
 s.getRange(`A9:J${last}`).format.rowHeight=44;s.getRange(`E9:E${last}`).setNumberFormat('0.0%');s.getRange(`H9:H${last}`).setNumberFormat('0.0%');
 s.getRange('A7').values=[[`優先：${f.priority}｜${f.scope}`]];
 return s;
}
function sheetName(i,n){const q=i.meta.QuestID,sk=i.meta.SkillID,mon=i.meta.ActorID;return q?`${String(n+1).padStart(2,'0')}_Q${q}`:sk?`技能${sk}`:mon?`怪物${mon}_P${i.meta.PRE}`:`${String(n+1).padStart(2,'0')}_${i.title.slice(0,22)}`;}
function detail(w,f,i,n){
 const name=sheetName(i,n).replace(/[\[\]:*?/\\]/g,'_').slice(0,31),s=w.worksheets.add(name);
 const label=i.meta.QuestID?`任務第${n+1}個（Quest${i.meta.QuestID}）`:(i.meta.SkillID?`技能${i.meta.SkillID}`:i.title);
 base(s,label,'先修改下方子步驟狀態；上方數字及功能總表會自動更新。','F');
 const meta=Object.entries(i.meta).filter(([k])=>!['資源','來源層級數'].includes(k)).map(([k,v])=>k+'：'+(Array.isArray(v)?v.join('、'):v)).join('；');
 s.getRange('A3').values=[[meta.slice(0,170)||f.scope]];s.getRange('A3').format.font={size:9,color:colors.gray};
 s.getRange('A8:F8').values=[['步驟ID','子步驟／要完成的事','統計類型','開發狀態','驗證結果','下一步／限制']];
 const last=8+i.steps.length;s.getRange(`A9:F${last}`).values=i.steps.map(st=>[st.id,st.name,st.kind,st.dev,st.test,st.next]);
 s.getRange('A4:F5').values=[['開發子項',null,'已實作',null,'開發完成度',null],['人測項目',null,'工作副本通過',null,'實測通過率',null]];
 s.getRange('B4').formulas=[[`=COUNTIFS(C9:C${last},"開發")`]];
 s.getRange('D4').formulas=[[`=COUNTIFS(C9:C${last},"開發",D9:D${last},"已實作")`]];
 s.getRange('F4').formulas=[['=IF(B4=0,0,D4/B4)']];
 s.getRange('B5').formulas=[[`=COUNTIFS(C9:C${last},"工作副本人測")`]];
 s.getRange('D5').formulas=[[`=COUNTIFS(C9:C${last},"工作副本人測",E9:E${last},"通過")`]];
 s.getRange('F5').formulas=[['=IF(B5=0,0,D5/B5)']];
 s.getRange('H4').values=[['整體狀態']];s.getRange('I4').formulas=[[`=IF(B4=0,"待盤點",IF(D4=B4,"已實作",IF(COUNTIFS(D9:D${last},"開發中")>0,"開發中",IF(COUNTIFS(D9:D${last},"分析中")>0,"分析中",IF(D4>0,"部分已實作","待分析")))))`]];
 s.getRange('A4:F5').format.fill=colors.pale;s.getRange('A4:F5').format.rowHeight=27;s.getRange('F4:F5').setNumberFormat('0.0%');
 s.getRange('A7').values=[['原版驗收另列；合成通過不會增加工作副本人測通過數。']];
 s.getRange('A6').values=[['回功能總表']];
 table(s,`A8:F${last}`,'Steps'+String(n+1));tableStyle(s,last,'F');
 const widths=[205,330,135,135,135,420];for(let c=0;c<6;c++)s.getRangeByIndexes(7,c,last-7,1).format.columnWidthPx=widths[c];
 s.getRange(`B9:B${last}`).format.wrapText=true;s.getRange(`F9:F${last}`).format.wrapText=true;s.getRange(`A9:F${last}`).format.rowHeight=48;
 s.getRange(`D9:D${last}`).dataValidation={rule:{type:'list',values:['待分析','分析中','待開發','開發中','已實作','不列分母']}};
 s.getRange(`E9:E${last}`).dataValidation={rule:{type:'list',values:['未測','合成通過','通過','部分通過','未通過','待改善']}};
 s.getRange(`D9:E${last}`).format.fill='#FFF5D6';
 s.getRange(`D9:D${last}`).conditionalFormats.add('containsText',{text:'已實作',format:{fill:'#DBEEDC',font:{color:'#1F5130'}}});
 s.getRange(`E9:E${last}`).conditionalFormats.add('cellIs',{operator:'equal',formula:'"通過"',format:{fill:'#DBEEDC',font:{color:'#1F5130'}}});
 const source=f.category==='主線與內容'||i.steps.some(x=>x.test==='通過')?'既有人測／Server候選證據；詳見README與plan.json的版本。':'原始資源引用／S00規劃；資料存在不代表已實作。';
 s.getRange(`A${last+2}`).values=[[source]];s.getRange(`A${last+3}`).values=[[i.note||'尚未逐項驗收，請保留未知條件。']];
 return {s,name,last};
}
async function save(w,file){w.recalculate();await(await SpreadsheetFile.exportXlsx(w)).save(file);}
export async function makeMaster(plan,out,records){
 const w=Workbook.create(),s=w.worksheets.add('開發總表');
 base(s,'Tartaros KR 功能開發總表','依玩家功能看規劃。跨檔統計須執行更新工具；此為最近一次彙整，不是假設所有工作簿即時連動。');
 s.getRange('A3').values=[['最後彙整（台北）：'+new Intl.DateTimeFormat('sv-SE',{timeZone:'Asia/Taipei',dateStyle:'short',timeStyle:'short'}).format(new Date())]];
 const last=8+plan.features.length;
 s.getRange('A8:L8').values=[['功能ID','預計開發功能','開發子項','已實作','開發完成度','人測通過','人測項目','實測通過率','優先','分類','功能檔','人工備註']];
 s.getRange(`A9:L${last}`).values=plan.features.map(f=>{const a=records[f.id];return[f.id,f.title,a.dev,a.done,null,a.pass,a.tests,null,f.priority,f.category,f.file,''];});
 for(let r=9;r<=last;r++){
  s.getRange(`E${r}`).formulas=[[`=IF(C${r}=0,0,D${r}/C${r})`]];
  s.getRange(`H${r}`).formulas=[[`=IF(G${r}=0,0,F${r}/G${r})`]];
  s.getRange(`K${r}`).values=[['開啟功能表']];
 }
 metrics(s,last);table(s,`A8:L${last}`,'Roadmap');tableStyle(s,last,'L');
 const widths=[95,295,90,90,115,90,90,115,85,140,410,250];for(let c=0;c<12;c++)s.getRangeByIndexes(7,c,last-7,1).format.columnWidthPx=widths[c];
 s.getRange('A7').values=[['進度＝目前已列子項比例，非工時估算。先完成新帳號正常進入馮德斯村；後續功能不代表現在安排測試。']];
 s.getRange(`E9:E${last}`).setNumberFormat('0.0%');s.getRange(`H9:H${last}`).setNumberFormat('0.0%');
 s.getRange(`B9:B${last}`).format.wrapText=true;s.getRange(`A9:L${last}`).format.rowHeight=34;
 await save(w,path.join(out,'00_開發功能總表.xlsx'));return w;
}
async function main(){
 const planPath=process.argv[2],out=process.argv[3],preview=process.argv[4];
 const raw=await fs.readFile(planPath,'utf8'),plan=JSON.parse(raw),sha=crypto.createHash('sha256').update(raw).digest('hex');
 await fs.mkdir(out,{recursive:true});await fs.mkdir(preview,{recursive:true});
 const progressFile=path.join(preview,'build-progress.json');let progress={plan_sha256:sha,files:[],stats:{}};
 try{progress=JSON.parse(await fs.readFile(progressFile,'utf8'));if(progress.plan_sha256!==sha)throw Error('Plan changed during build');}catch(e){if(e.code!=='ENOENT')throw e;}
 for(const f of plan.features){
  const file=path.join(out,f.file),expected=stats(f),done=progress.files.find(x=>x.id===f.id);
  if(done){const bytes=await fs.readFile(file);if(crypto.createHash('sha256').update(bytes).digest('hex')!==done.sha256)throw Error('Existing generated file changed '+f.id);continue;}
  try{await fs.access(file);throw Error('Refusing to overwrite existing workbook '+file);}catch(e){if(e.code!=='ENOENT')throw e;}
  const w=Workbook.create(),s=overview(w,f);const tabs=[];
  for(let n=0;n<f.items.length;n++){
   const d=detail(w,f,f.items[n],n);tabs.push(d);
   const r=9+n,q="'"+d.name+"'!";
   s.getRange('B'+r).values=[[f.items[n].title]];
   for(const [target,source] of [['C','B4'],['D','D4'],['F','D5'],['G','B5'],['I','I4']])s.getRange(target+r).formulas=[['='+q+source]];
   s.getRange('E'+r).formulas=[[`=IF(C${r}=0,0,D${r}/C${r})`]];
   s.getRange('H'+r).formulas=[[`=IF(G${r}=0,0,F${r}/G${r})`]];
  }
  w.recalculate();
  const actual={dev:s.getRange('B4').values[0][0],done:s.getRange('D4').values[0][0],tests:s.getRange('B5').values[0][0],pass:s.getRange('D5').values[0][0]};
  if(JSON.stringify(actual)!==JSON.stringify(expected))throw Error('Formula totals mismatch '+f.id+' '+JSON.stringify(actual)+' '+JSON.stringify(expected));
  // Every child is checked by its actual summary formulas before export.
  for(let n=0;n<tabs.length;n++){
   const a=stats({items:[f.items[n]]}),d=tabs[n].s;
   if(d.getRange('B4').values[0][0]!==a.dev||d.getRange('D4').values[0][0]!==a.done||d.getRange('D5').values[0][0]!==a.pass)throw Error('Child totals '+f.id+' '+n);
  }
  const png=await w.render({sheetName:s.name,range:'A1:J12',scale:0.8});await fs.writeFile(path.join(preview,f.id+'-summary.png'),new Uint8Array(await png.arrayBuffer()));
  const child=tabs[0];const p=await w.render({sheetName:child.name,range:'A1:F'+Math.min(child.last+3,30),scale:0.8});await fs.writeFile(path.join(preview,f.id+'-detail.png'),new Uint8Array(await p.arrayBuffer()));
  await save(w,file);
  const bytes=await fs.readFile(file);progress.files.push({id:f.id,file:f.file,sheets:1+tabs.length,sha256:crypto.createHash('sha256').update(bytes).digest('hex')});progress.stats[f.id]=actual;
  await fs.writeFile(progressFile,JSON.stringify(progress,null,2));
  console.log(JSON.stringify({feature:f.id,items:tabs.length,completed:progress.files.length,total:plan.features.length}));
 }
 const master=await makeMaster(plan,out,progress.stats);const p=await master.render({sheetName:'開發總表',range:'A1:J14',scale:0.8});await fs.writeFile(path.join(preview,'master.png'),new Uint8Array(await p.arrayBuffer()));
 await fs.writeFile(path.join(out,'build-manifest.json'),JSON.stringify({...progress,recorded_date:plan.recorded_date,source_analysis_main:plan.source_analysis_main},null,2));
 console.log('FINISHED '+progress.files.length+' feature books and master');
}
if(process.argv[1]&&import.meta.url===pathToFileURL(process.argv[1]).href)main().catch(e=>{console.error(e.message);process.exitCode=1;});
