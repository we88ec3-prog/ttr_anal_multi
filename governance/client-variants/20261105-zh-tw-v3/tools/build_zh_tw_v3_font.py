"""Build a separate Taiwan-font archive, retaining every KR font item/size.
No original asset or executable is modified. No target execution.
"""
from pathlib import Path
import sys,re,struct,zlib,hashlib,json
from xml.sax.saxutils import quoteattr
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'anal'))
from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()

def pack_overlay(source,changed):
 oldtable=struct.unpack_from('>I',source.data,12)[0];oldindex=struct.unpack_from('<I',source.data,4)[0]
 count=struct.unpack_from('<I',source.data,oldtable)[0];byid={v:k for k,v in source.files.items()}
 data=bytearray(source.data[:16]);entries=[]
 for i in range(count):
  row=bytearray(source.data[oldtable+4+i*32:oldtable+4+(i+1)*32]);ident,size,first,last=struct.unpack_from('<4I',row)
  name=byid[ident]
  if name in changed:
   payload=changed[name];compressed=zlib.compress(payload)
   block=b'EX\0\0'+struct.pack('<III',len(compressed),len(payload),16)+compressed
  else:block=source.data[16+first*1024:16+first*1024+size]
  begin=(len(data)-16)//1024;blocks=(len(block)+1023)//1024
  data.extend(block);data.extend(bytes(blocks*1024-len(block)))
  struct.pack_into('<4I',row,0,ident,len(block),begin,begin+blocks-1);row[16:32]=hashlib.md5(block).digest();entries.append(row)
 table=len(data);data.extend(struct.pack('<I',count)+b''.join(entries));index=len(data);data.extend(source.data[oldindex:])
 struct.pack_into('>I',data,12,table);struct.pack_into('<I',data,4,index)
 packed=bytearray(x^255 for x in data);packed[:4]=b'STPD';packed[index:index+4]=b'STPI';return bytes(packed)

def write_once(path,data):
 path.parent.mkdir(parents=True,exist_ok=True)
 if path.exists():assert path.read_bytes()==data,f'Refusing different existing output: {path}'
 else:path.write_bytes(data)

def build():
 source=ROOT/'UI/Font.stp';tc=ROOT/'TC_UI/Font.stp';a=Archive(source)
 # Preserve KR codes, every size, bold flags and all other member bytes.
 # Bind supplied Taiwan font files directly, rather than rely on OS substitution.
 member='Font/Chinese(Taiwan).FFT';original=a.read(member)
 def change(m):
  tag=m.group().decode('utf-8');code=re.search(r'Code="([^"]+)"',tag).group(1)
  assert code in ('NANUMGOTHIC_REGULAR','NANUMGOTHIC_BOLD')
  path='./UI/Font/msjhbd.ttf' if code.endswith('_BOLD') else './UI/Font/msjh.ttf'
  tag=re.sub(r'\bName="[^"]*"','Name="Microsoft JhengHei"',tag)
  tag=re.sub(r'Path="[^"]*"','Path='+quoteattr(path),tag)
  assert path in tag
  return tag.encode('utf-8')
 modified,n=re.subn(rb'<FONTTYPE\b[^>]*>',change,original);assert n==2
 output=ROOT/'CLIENT/build/zh-tw-v3-resources/Font.stp';packed=pack_overlay(a,{member:modified});write_once(output,packed)
 verify=Archive(output);assert verify.files==a.files
 for name in a.files:assert verify.read(name)==(modified if name==member else a.read(name))
 # Compare XML item rows byte-for-byte; only two declaration tags may differ.
 assert re.findall(rb'<FONTITEM\b[^>]*>',modified)==re.findall(rb'<FONTITEM\b[^>]*>',original)
 assert re.findall(rb'ClassName="[^"]*"',modified)==re.findall(rb'ClassName="[^"]*"',original)
 fonts=[]
 for name in ['msjh.ttf','msjhbd.ttf']:
  font=ROOT/'TC_UI/Font'/name;official=ROOT.parent/'tc_workspace/UI/Font'/name
  data=font.read_bytes();assert data==official.read_bytes(),'Taiwan font mismatch'
  fonts.append({'file':name,'sha256':sha(data),'bytes':len(data)})
 report={'base_font_archive_sha256':sha(source.read_bytes()),'taiwan_font_archive_sha256':sha(tc.read_bytes()),'output_sha256':sha(packed),'modified_member':member,'font_declarations_changed':n,'font_items_preserved':len(re.findall(rb'<FONTITEM\b[^>]*>',original)),'fonts':fonts,'rendering':'PENDING_USER','original_files_modified':False}
 dest=ROOT/'CLIENT/evidence/20261105-variant-font/font-manifest.json';dest.parent.mkdir(parents=True,exist_ok=True);dest.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8');print(json.dumps(report))
if __name__=='__main__':build()
