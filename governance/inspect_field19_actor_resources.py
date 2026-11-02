"""Read-only selected Field19 actor/ABF metadata; no AI or collision policy inference."""
import argparse,hashlib,json,xml.etree.ElementTree as ET
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode
TABLE="ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c"
BASE="1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957"
PINS={1001:("00_HokyPoky","3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633"),1009:("01_Moose","d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b"),1004:("01_Nepenths","6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71")}
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument("--workspace",type=Path,required=True);p.add_argument("--output",type=Path,required=True);a=p.parse_args();assert not a.output.exists()
 table=decode(members((a.workspace/"Table.stp").read_bytes(),TABLE,["Table/_ActorList.xml"])["Table/_ActorList.xml"])
 tree=ET.fromstring(table.decode("utf-8-sig"));rows=[]
 for model,(file,pin) in PINS.items():
  actor=tree.find(f".//ACTOR[@ID='{model}'][@PRE='1']");assert actor is not None and actor.get("FILE")==file
  name="Mon/"+file+".abf";raw=decode(members((a.workspace/"Character/Mon/Base.stp").read_bytes(),BASE,[name])[name]);assert hashlib.sha256(raw).hexdigest()==pin
  tr=ET.fromstring(raw.decode("euc-kr"));animations=[]
  for motion in [1,4,6,7,9,101]:
   anim=tr.find(f".//Animation[@ID='{motion}']");assert anim is not None
   animations.append(dict(attributes=anim.attrib,effects=[e.attrib for e in anim.findall("Effect")]))
  rows.append(dict(model=model,actor_fields_without_localized_name={k:v for k,v in actor.attrib.items() if k!="NAME"},abf_member=name,abf_sha256=pin,character=tr.find("Character").attrib,animations=animations))
 assert [r["actor_fields_without_localized_name"]["SCALE"] for r in rows]==["110","100","100"]
 assert [x["attributes"]["File"] for x in rows[2]["animations"] if x["attributes"]["ID"] in ["4","6"]]==["Nepenths_WAIT01.gb3"]*2
 result=dict(classification="PINNED_SELECTED_ACTOR_RESOURCE_FACTS_NOT_AI_RULES",table_carrier_sha256=TABLE,actor_table_sha256=hashlib.sha256(table).hexdigest(),base_carrier_sha256=BASE,actors=rows,limits=["Motion101 attack and7 death exist; no runtime proof, clip length, damage timestamp, skill/balance or authoritative hit radius recovered.","Raw SCALE retained; no unverified units conversion.","Nepenths4/6 referenceWAIT rather thanMOVE; stationary Server prototype is a deliberate policy, not proof of all original AI.","No collision volume or enemy skill table was resolved in this selected ABF inspection.","No full asset existence/compatibility claim and no Client execution or resource modification."])
 a.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n",encoding="utf-8");print(json.dumps(dict(actors=len(rows),validated_motion_slots=18,stationary_candidate_model=1004)))
if __name__=="__main__":main()
