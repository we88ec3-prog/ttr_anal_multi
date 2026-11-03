"""Offline native checkpoint portal/step producer and pinned resource facts."""
import argparse,hashlib,json,struct,sys,xml.etree.ElementTree as ET,zlib
from pathlib import Path
from verify_working_copy_login_ranges import mapped,ORIGINAL
from inspect_tutorial_bounds_resource import members,ARCHIVE_SHA
from inspect_first_tutorial_cluster import decode
TABLE="ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c"
PORTAL_SHA="3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56"
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument("--binary",required=True,type=Path);p.add_argument("--workspace",required=True,type=Path);p.add_argument("--capstone-path",required=True,type=Path);p.add_argument("--output",required=True,type=Path);a=p.parse_args();assert not a.output.exists()
 sha,read=mapped(a.binary);assert sha==ORIGINAL;sys.path.insert(0,str(a.capstone_path));import capstone
 md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);windows=[];ops={}
 for st,en in [(0x543700,0x543b2a),(0x544020,0x544067),(0x544070,0x544726),(0x544730,0x5447ef),(0x544a00,0x544b60),(0x547f90,0x54802f),(0x4f7730,0x4f7a08)]:
  raw=read(st,en-st);ins=list(md.disasm(raw,st));assert sum(i.size for i in ins)==len(raw) and ins[-1].mnemonic=="ret"
  bounds={i.address for i in ins}
  for i in ins:
   if i.mnemonic.startswith("j") and i.op_str.startswith("0x"):
    t=int(i.op_str,16)
    if st<=t<en:assert t in bounds
  rows=[dict(va=hex(i.address),op=i.mnemonic+" "+i.op_str) for i in ins];ops.update({r["va"]:r["op"] for r in rows});windows.append(dict(start=hex(st),end_exclusive=hex(en),sha256=hashlib.sha256(raw).hexdigest(),instructions=rows))
 expected={"0x543768":"mov dword ptr [ebx + 0x100], eax","0x543772":"mov dword ptr [ebx], 0xc0f7fc","0x543892":"fmul qword ptr [0xc55ba8]","0x543a4a":"shl edx, 0x10","0x543a4d":"or edx, ecx","0x543a5a":"call 0x4f7cc0","0x54402d":"mov dx, word ptr [eax + 0xf4]","0x544034":"mov ax, word ptr [eax + 0xf6]","0x54403b":"mov ecx, 0x1c","0x544059":"push 6","0x54470e":"call 0x544020","0x544739":"cmp byte ptr [ecx + 0x105], 0","0x54479a":"cmp dword ptr [ecx + 0x100], 0","0x5447a1":"jne 0x5447ce","0x5447a3":"cmp dword ptr [ebp + 0x10], 0","0x544aa1":"call 0x544730","0x544b28":"mov edx, dword ptr [eax + 0x64]","0x548018":"call 0x544a00","0x4f78e5":"shl edx, 0x10","0x4f78e8":"or edx, ecx"}
 assert all(ops[k]==v for k,v in expected.items());assert struct.unpack("<I",read(0xc0f7fc+0x64,4))[0]==0x544070
 factor=struct.unpack("<d",read(0xc55ba8,8))[0];assert abs(factor-.8)<1e-7
 name="Table/_PortalList.xml";raw=decode(members((a.workspace/"Table.stp").read_bytes(),TABLE,[name])[name]);assert hashlib.sha256(raw).hexdigest()==PORTAL_SHA
 portal=ET.fromstring(raw.decode("utf-8-sig"));selected=[e.attrib for e in portal if e.get("ID")=="0"]
 assert selected==[{"ID":"0","STATE":"1","FILE":"A_Zone_BasisTeleportA01.eff"},{"ID":"0","STATE":"0","FILE":"A_Zone_BasisTeleportB01.eff"}]
 points=[]
 for key,n,xy in [(1,"BoundMap/scenario_pathofpindus01.bnd",(430,385)),(2,"BoundMap/scenario_pathofpindus02.bnd",(391,369))]:
  d=decode(members((a.workspace/"Map/BoundMap.stp").read_bytes(),ARCHIVE_SHA,[n])[n]);x,y=xy
  values=[]
  for i in range(2):
   off,comp,expanded,count=struct.unpack_from("<4I",d,0x34+i*16);l=zlib.decompress(d[off:off+comp]);assert len(l)==expanded==count*4;values.append(struct.unpack_from("<I",l,(y*768+x)*4)[0])
  assert values==[0,0]
  points.append(dict(map=190+key,key_server_candidate=key,xy=list(xy),layer_values=values,s2c27_source_shaped_example_not_capture=struct.pack("<HHbBfffBB",0x27,key,0,1,x,y,5,1,0).hex(),c2s1c_source_shaped_example_not_capture=struct.pack("<HHH",0x1c,0,key).hex()))
 result=dict(classification="BOUNDED_PORTAL_CONSUMER_AND_INTENT_PRODUCER_NOT_OFFICIAL_GATE_POLICY",target_sha256=sha,native_windows=windows,exact_instruction_assertions=len(expected)+1,portal_table=dict(carrier_sha256=TABLE,member=name,sha256=PORTAL_SHA,selected_effect_rows=selected),category0_radius_factor=factor,candidate_portals=points,limits=["Opcode27 layout/registration reuses prior S00-SQUARE-NPC-INTERACTION proof; collection replacement requires publishing all intended checkpoints together.","Category0 selects portal visual path and6B1C intent; keys1/2,coordinates,radius5 and gate-after-win are Server reconstruction based on human request, not official MEF placements.","Automatic1 removes action-key prerequisite in544730; radius still strictly distance<wireRadius*.8 and input/control global conditions apply.","Effect filename reference proven; complete resource-dependency availability and actual visual/runtime trigger not verified.","Server must independently require currentnode authoritativewin/current ownedpose inrange before committing transition.1C alone is not success,ACK or teleport authority.","No Client execution,network,resource modification or negative/deferred tests."])
 a.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n",encoding="utf-8");print(json.dumps(dict(native_windows=len(windows),assertions=len(expected)+1,portal_candidates=len(points))))
if __name__=="__main__":main()
