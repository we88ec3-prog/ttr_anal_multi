"""Project retained EMF metadata without rereading unchanged archive indexes."""
import json,hashlib
from pathlib import Path
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent
x=json.loads((D/'resource-audit.json').read_text(encoding='utf-8-sig'));p=R/'anal/T10-desktop-20261028/repo/kr-temp-roy/T06/evidence/town-fcs-exact-archive-path-join-v1.json';old=json.loads(p.read_text(encoding='utf-8-sig'));emf=[]
for row in old['rows']:
 for rec in row['record_paths']:
  for hit in rec['full_path_casefold_index_matches']:
   if hit['member'].casefold().endswith('.emf'):
    carr=next(a for a in old['archives'] if a['path']==hit['archive']);current=[a for a in x['archiveInventory'] if a['archive'].replace('\\','/')==hit['archive'] and a['root']=='working']
    emf.append({'sourceDocument':row['document'],'member':hit['member'],'archive':hit['archive'],'decodedSha256':hit['decoded_sha256'],'priorCarrierSha256':carr['sha256'],'currentCarrierSha256':current[0]['currentSha256'] if current else None,'identityStillEqual':bool(current and current[0]['currentSha256']==carr['sha256'])})
r={'retainedEvidencePath':str(p.relative_to(R)),'retainedEvidenceSha256':hashlib.sha256(p.read_bytes()).hexdigest(),'emfReferences':emf,'lightNamedCarriers':[a for a in x['archiveInventory'] if 'light' in a['archive'].casefold()],'limitations':['EMF payloads are not MEF samples; no renaming or MEF semantics inferred.','Retained EMF proof is historical carrier/member metadata, no new index read.','No Light-named carrier in this narrow inventory is not proof of missing lighting files or embedded lighting domain.']}
(D/'domain-separation.json').write_bytes((json.dumps(r,ensure_ascii=False,indent=2)+'\n').encode())
print('retained EMF references',len(emf))
