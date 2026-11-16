"""Offline TrueType Unicode cmap coverage; does not execute or install fonts."""
from pathlib import Path
import struct,json,argparse
R=Path(__file__).resolve().parents[2]

def cmap(path):
 b=path.read_bytes();n=struct.unpack_from('>H',b,4)[0]
 tables={b[12+16*i:16+16*i]:struct.unpack_from('>II',b,20+16*i) for i in range(n)}
 o,l=tables[b'cmap'];num=struct.unpack_from('>H',b,o+2)[0];result=set()
 for i in range(num):
  platform,encoding,rel=struct.unpack_from('>HHI',b,o+4+8*i)
  if platform not in (0,3):continue
  s=o+rel;fmt=struct.unpack_from('>H',b,s)[0]
  if fmt==4:
   length=struct.unpack_from('>H',b,s+2)[0];segments=struct.unpack_from('>H',b,s+6)[0]//2
   ends=s+14;starts=ends+2*segments+2;deltas=starts+2*segments;ranges=deltas+2*segments
   for j in range(segments):
    end=struct.unpack_from('>H',b,ends+2*j)[0];start=struct.unpack_from('>H',b,starts+2*j)[0];delta=struct.unpack_from('>h',b,deltas+2*j)[0];ro=struct.unpack_from('>H',b,ranges+2*j)[0]
    for cp in range(start,min(end,65534)+1):
     if ro:
      at=ranges+2*j+ro+2*(cp-start);assert s<=at<s+length
      g=struct.unpack_from('>H',b,at)[0];glyph=(g+delta)&65535 if g else 0
     else:glyph=(cp+delta)&65535
     if glyph:result.add(cp)
  elif fmt==12:
   groups=struct.unpack_from('>I',b,s+12)[0]
   for j in range(groups):
    first,last,glyph=struct.unpack_from('>III',b,s+16+12*j)
    result.update(range(first+(glyph==0),last+1))
 return result

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--glyphs',type=Path,required=True);a=p.parse_args()
 needed={ord(c) for c in a.glyphs.read_text(encoding='utf-8-sig') if not c.isspace() and ord(c)>31}
 fonts=[]
 for n in ['msjh.ttf','msjhbd.ttf']:
  codes=cmap(R/'TC_UI/Font'/n);missing=sorted(needed-codes)
  fonts.append({'font':n,'glyphs_required':len(needed),'glyphs_present':len(needed&codes),'missing_count':len(missing),'missing_codepoints':['U+%04X'%x for x in missing]})
 out=R/'CLIENT/evidence/20261105-variant-font/glyph-coverage.json';out.write_text(json.dumps(fonts,indent=2)+'\n',encoding='utf-8');print(json.dumps(fonts))
