"""Native hyperlink fallback: artifact HYPERLINK exports an unimplemented error.
Only designated link cells/metadata are touched; calculation formulas stay intact.
"""
from pathlib import Path
import json,zipfile,xml.etree.ElementTree as E,urllib.parse,hashlib,sys,os
M='http://schemas.openxmlformats.org/spreadsheetml/2006/main'
R='http://schemas.openxmlformats.org/officeDocument/2006/relationships'
P='http://schemas.openxmlformats.org/package/2006/relationships'
def encode(root,default):
 E.register_namespace('',default);E.register_namespace('r',R);return E.tostring(root,encoding='utf-8',xml_declaration=True)
def patch(file,specs):
 tmp=file.with_suffix('.navigation.xlsx')
 with zipfile.ZipFile(file) as z:
  changed={}
  for index,links in specs.items():
   sheetpath=f'xl/worksheets/sheet{index}.xml';root=E.fromstring(z.read(sheetpath));data=root.find('{'+M+'}sheetData')
   cells={c.get('r'):c for row in data for c in row}
   hl=root.find('{'+M+'}hyperlinks')
   if hl is None:
    hl=E.Element('{'+M+'}hyperlinks');tags=['printOptions','pageMargins','pageSetup','headerFooter','rowBreaks','colBreaks','customProperties','cellWatches','ignoredErrors','smartTags','drawing','legacyDrawing','legacyDrawingHF','picture','oleObjects','controls','webPublishItems','tableParts','extLst']
    at=next((n for n,e in enumerate(root) if e.tag.split('}')[-1] in tags),len(root));root.insert(at,hl)
   relpath=f'xl/worksheets/_rels/sheet{index}.xml.rels';rels=E.fromstring(z.read(relpath)) if relpath in z.namelist() else E.Element('{'+P+'}Relationships')
   for address,label,target,external in links:
    c=cells.get(address)
    if c is None:
     rownum=''.join(x for x in address if x.isdigit());row=next((r for r in data if r.get('r')==rownum),None)
     if row is None:row=E.SubElement(data,'{'+M+'}row',{'r':rownum})
     c=E.SubElement(row,'{'+M+'}c',{'r':address});cells[address]=c
    oldf=c.find('{'+M+'}f')
    if oldf is not None:assert (oldf.text or '').startswith('HYPERLINK('),'Do not replace a calculation formula'
    for child in list(c):c.remove(child)
    c.set('t','inlineStr');E.SubElement(E.SubElement(c,'{'+M+'}is'),'{'+M+'}t').text=label
    for existing in list(hl):
     if existing.get('ref')==address:hl.remove(existing)
    attrs={'ref':address,'display':label}
    if external:
     rid='S00Navigation'+address
     for existing in list(rels):
      if existing.get('Id')==rid:rels.remove(existing)
     E.SubElement(rels,'{'+P+'}Relationship',{'Id':rid,'Type':R+'/hyperlink','Target':urllib.parse.quote(target),'TargetMode':'External'});attrs['{'+R+'}id']=rid
    else:attrs['location']=target
    E.SubElement(hl,'{'+M+'}hyperlink',attrs)
   changed[sheetpath]=encode(root,M)
   if len(rels):changed[relpath]=encode(rels,P)
  with zipfile.ZipFile(tmp,'w') as out:
   for info in z.infolist():out.writestr(info,changed.pop(info.filename,z.read(info.filename)))
   for name,raw in changed.items():out.writestr(name,raw,compress_type=zipfile.ZIP_DEFLATED)
 os.replace(tmp,file)
def main():
 root=Path(sys.argv[1]);plan=json.loads((root/'plan.json').read_text(encoding='utf-8'));manifest=json.loads((root/'build-manifest.json').read_text(encoding='utf-8'))
 for f in plan['features']:
  if '--master-only' in sys.argv:continue
  file=root/f['file']
  with zipfile.ZipFile(file) as z:tabs=list(E.fromstring(z.read('xl/workbook.xml')).find('{'+M+'}sheets'))
  links={1:[]}
  for n,it in enumerate(f['items'],2):
   name=tabs[n-1].get('name').replace("'","''")
   links[1].append(('B'+str(n+7),it['title'],"'"+name+"'!A1",False));links[n]=[('A6','回功能總表',"'功能總表'!A1",False)]
  patch(file,links)
  next(v for v in manifest['files'] if v['id']==f['id'])['sha256']=hashlib.sha256(file.read_bytes()).hexdigest()
 master=root/'00_開發功能總表.xlsx'
 with zipfile.ZipFile(master) as z:
  shared=[''.join(e.itertext()) for e in E.fromstring(z.read('xl/sharedStrings.xml'))] if 'xl/sharedStrings.xml' in z.namelist() else []
  rows={}
  for row in E.fromstring(z.read('xl/worksheets/sheet1.xml')).find('{'+M+'}sheetData'):
   for c in row:
    if c.get('r')=='A'+row.get('r'):
     v=c.find('{'+M+'}v');value=v.text if v is not None else ''.join(c.itertext())
     if c.get('t')=='s':value=shared[int(value)]
     rows[value]=row.get('r')
 patch(master,{1:[('K'+rows[f['id']],'開啟功能表',f['file'],True) for f in plan['features']]})
 manifest['navigation']='Native OOXML hyperlink metadata; unsupported HYPERLINK formulas replaced only at designated navigation cells.'
 manifest['master_sha256']=hashlib.sha256(master.read_bytes()).hexdigest()
 (root/'build-manifest.json').write_bytes((json.dumps(manifest,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
 print('Native links installed; calculation formulas preserved in '+('1 master' if '--master-only' in sys.argv else str(len(plan['features'])+1)+' books')+'.')
if __name__=='__main__':main()
