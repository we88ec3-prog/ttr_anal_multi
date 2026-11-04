"""Independent OOXML checks for every functional page and cached progress total."""
from pathlib import Path
import argparse,json,zipfile,xml.etree.ElementTree as E,math,hashlib,urllib.parse
N={'m':'http://schemas.openxmlformats.org/spreadsheetml/2006/main'}
def book(p):
 z=zipfile.ZipFile(p);ss=[]
 if 'xl/sharedStrings.xml' in z.namelist():ss=[''.join(x.itertext()) for x in E.fromstring(z.read('xl/sharedStrings.xml'))]
 sheets=list(E.fromstring(z.read('xl/workbook.xml')).find('m:sheets',N));return z,ss,sheets
def sheet(z,ss,n):
 root=E.fromstring(z.read(f'xl/worksheets/sheet{n}.xml'));cells={};forms={}
 for c in root.findall('.//m:sheetData/m:row/m:c',N):
  v=c.find('m:v',N);t=c.get('t');val=v.text if v is not None else ''
  assert t!='e',('Excel formula error',c.get('r'),val)
  if t=='s':val=ss[int(val)]
  elif t=='inlineStr':val=''.join(c.find('m:is',N).itertext())
  elif val and t not in ('str','b'):
   try:val=float(val)
   except ValueError:pass
  cells[c.get('r')]=val
  f=c.find('m:f',N)
  if f is not None:forms[c.get('r')]=f.text or ''
 return cells,forms,root
def equal(a,b):assert isinstance(a,(int,float)) and math.isclose(a,b,abs_tol=1e-9),(a,b)
def main():
 a=argparse.ArgumentParser();a.add_argument('root',type=Path);args=a.parse_args();root=args.root
 p=json.loads((root/'plan.json').read_text(encoding='utf-8'));manifest=json.loads((root/'build-manifest.json').read_text(encoding='utf-8'))
 totals={};pages=0;steps=0
 for f in p['features']:
  z,ss,tabs=book(root/f['file']);assert len(tabs)==len(f['items'])+1
  assert tabs[0].get('name')=='功能總表';summary,summaryf,summaryxml=sheet(z,ss,1)
  counts=[0,0,0,0]
  for n,it in enumerate(f['items'],2):
   c,form,xml=sheet(z,ss,n);local=[0,0,0,0]
   back=xml.find("m:hyperlinks/m:hyperlink[@ref='A6']",N)
   assert back is not None and back.get('location')=="'功能總表'!A1",'Missing return navigation'
   for j,st in enumerate(it['steps'],9):
    assert c.get('A'+str(j))==st['id'];assert c.get('B'+str(j))==st['name'];assert c.get('C'+str(j))==st['kind']
    dev=c.get('D'+str(j));test=c.get('E'+str(j));assert dev in ['待分析','分析中','待開發','開發中','已實作','不列分母'];assert test in ['未測','合成通過','通過','部分通過','未通過','待改善']
    if st['kind']=='開發':local[0]+=1;local[1]+=dev=='已實作'
    if st['kind']=='工作副本人測':local[3]+=1;local[2]+=test=='通過'
    steps+=1
   for key,value in zip(['B4','D4','D5','B5'],local):equal(c.get(key),value)
   equal(c.get('F4'),local[1]/local[0] if local[0] else 0);equal(c.get('F5'),local[2]/local[3] if local[3] else 0)
   r=n+7
   link=summaryxml.find(f"m:hyperlinks/m:hyperlink[@ref='B{r}']",N)
   assert link is not None and link.get('location')=="'"+tabs[n-1].get('name').replace("'","''")+"'!A1"
   for key,value in zip(['C','D','F','G'],local):equal(summary.get(key+str(r)),value)
   assert c.get('I4') not in ['',None]
   dv=xml.find('m:dataValidations',N);assert dv is not None and len(dv)==2
   counts=[a+b for a,b in zip(counts,local)];pages+=1
  for key,value in zip(['B4','D4','D5','B5'],counts):equal(summary.get(key),value)
  equal(summary.get('F4'),counts[1]/counts[0] if counts[0] else 0);equal(summary.get('F5'),counts[2]/counts[3] if counts[3] else 0)
  totals[f['id']]=counts;z.close()
 z,ss,tabs=book(root/'00_開發功能總表.xlsx');assert len(tabs)==1;c,form,masterxml=sheet(z,ss,1)
 rels={e.get('Id'):e.get('Target') for e in E.fromstring(z.read('xl/worksheets/_rels/sheet1.xml.rels'))}
 for n,f in enumerate(p['features'],9):
  assert c.get('A'+str(n))==f['id']
  for key,value in zip(['C','D','F','G'],totals[f['id']]):equal(c.get(key+str(n)),value)
  assert c.get('K'+str(n))=='開啟功能表'
  link=masterxml.find(f"m:hyperlinks/m:hyperlink[@ref='K{n}']",N)
  assert link is not None
  rid=link.get('{http://schemas.openxmlformats.org/officeDocument/2006/relationships}id')
  assert urllib.parse.unquote(rels[rid])==f['file'] and (root/f['file']).is_file()
 combined=[sum(x[i] for x in totals.values()) for i in range(4)]
 for key,value in zip(['B4','D4','D5','B5'],combined):equal(c.get(key),value)
 z.close()
 report={'feature_workbooks':len(p['features']),'master_workbooks':1,'detail_pages':pages,'step_rows':steps,
         'development_steps':combined[0],'implemented_steps':combined[1],'working_copy_pass_targets':combined[2],'working_copy_targets':combined[3],
         'all_child_summary_and_master_cached_totals_match':True,'formula_errors':0,
         'coverage':'Every sheet: IDs, defined rows, status values, formulas and totals; every child dropdown and navigation. Visual previews are separate.',
         'source_scope':'Current resource-based plan, not original game complete feature enumeration.'}
 (root/'verification.json').write_bytes((json.dumps(report,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
 print(json.dumps(report,ensure_ascii=False))
if __name__=='__main__':main()
