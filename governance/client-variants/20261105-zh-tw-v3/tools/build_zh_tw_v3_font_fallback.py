"""Keep Taiwan glyphs primary; add only uncovered visible KR fallback glyphs.
Private output font copies only. Requires fonttools==4.55.3 in tools/deps.
"""
from pathlib import Path
import sys,json,hashlib
R=Path(__file__).resolve().parents[2];sys.path.insert(0,str(Path(__file__).parent/'deps'))
from fontTools.ttLib import TTFont
from fontTools import subset
from fontTools.merge import Merger
from fontTools.ttLib.scaleUpem import scale_upem
sha=lambda b:hashlib.sha256(b).hexdigest()
D=R/'CLIENT/build/zh-tw-v3-resources/font';D.mkdir(parents=True,exist_ok=True)
required={ord(c) for c in (R/'CLIENT/evidence/20261105-variant-text/glyphs-all-visible-fields.txt').read_text(encoding='utf-8-sig') if not c.isspace()}
reports=[]
def dehint(f):
 for name in ['fpgm','prep','cvt ','LTSH','VDMX','hdmx','DSIG','gasp']:
  if name in f:del f[name]
 if 'glyf' in f:
  for g in f['glyf'].glyphs.values():g.removeHinting()
 # Keep horizontal UI font metrics, avoid unsupported mixed vertical tables.
 for name in ['vhea','vmtx']:
  if name in f:del f[name]
for regular,bold in [(True,False),(False,True)]:
 name='msjhbd.ttf' if bold else 'msjh.ttf';fallback='NanumGothicBold.ttf' if bold else 'NanumGothic.ttf'
 primary=TTFont(R/'TC_UI/Font'/name,recalcTimestamp=False);original_times=(primary['head'].created,primary['head'].modified);existing=primary.getBestCmap();missing=required-set(existing)
 other=TTFont(R/'UI/Font'/fallback,recalcTimestamp=False);assert missing<=set(other.getBestCmap()),'KR fallback lacks required glyphs'
 opts=subset.Options();opts.hinting=False;opts.layout_features=[];opts.recalc_timestamp=False
 s=subset.Subsetter(options=opts);s.populate(unicodes=missing);s.subset(other)
 scale_upem(other,primary['head'].unitsPerEm);dehint(primary);dehint(other)
 for table in ['GDEF','GPOS','GSUB']:
  if table in other:del other[table]
 pf=D/(name+'.primary.ttf');ff=D/(name+'.fallback.ttf');primary.save(pf);other.save(ff);primary.close();other.close()
 merged=Merger().merge([str(pf),str(ff)]);merged.recalcTimestamp=False
 merged['head'].created,merged['head'].modified=original_times
 out=D/name;merged.save(out);merged.close()
 check=TTFont(out);assert required<=set(check.getBestCmap());base=TTFont(R/'TC_UI/Font'/name)
 # All Taiwan cmap codepoints and horizontal advances survive, including CJK.
 for cp,g in base.getBestCmap().items():
  mg=check.getBestCmap()[cp];assert check['hmtx'][mg]==base['hmtx'][g],hex(cp)
 reports.append({'font':name,'taiwan_source_sha256':sha((R/'TC_UI/Font'/name).read_bytes()),'kr_fallback_source_sha256':sha((R/'UI/Font'/fallback).read_bytes()),'output_sha256':sha(out.read_bytes()),'added_fallback_codepoints':len(missing),'required_codepoints':len(required),'missing_after_merge':0,'taiwan_horizontal_metrics_preserved':True,'hinting':'Removed in private merged copy; vector glyphs retained','runtime':'PENDING_USER'})
 check.close();base.close()
(R/'CLIENT/evidence/20261105-variant-font/fallback-manifest.json').write_text(json.dumps(reports,indent=2)+'\n',encoding='utf-8');print(json.dumps(reports))
