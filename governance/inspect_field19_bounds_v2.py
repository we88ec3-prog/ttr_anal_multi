"""Read-only pinned Field19 BNDv2 layout and native loader qualification."""
import argparse, hashlib, json, struct, sys, zlib
from pathlib import Path
from inspect_tutorial_bounds_resource import members, ARCHIVE_SHA
from inspect_first_tutorial_cluster import decode
from verify_working_copy_login_ranges import mapped, ORIGINAL
PINS={
 "BoundMap/scenario_pathofpindus01.bnd":"adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58",
 "BoundMap/scenario_pathofpindus02.bnd":"89cc3d4b77d3cf0cdf64d45f610d7b987c704bc268881c13396e1375a2234fff"}
def main():
 p=argparse.ArgumentParser(description=__doc__)
 p.add_argument("--binary",type=Path,required=True);p.add_argument("--archive",type=Path,required=True)
 p.add_argument("--capstone-path",type=Path,required=True);p.add_argument("--output",type=Path,required=True)
 a=p.parse_args();assert not a.output.exists()
 sha,read=mapped(a.binary);assert sha==ORIGINAL
 sys.path.insert(0,str(a.capstone_path));import capstone
 md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
 windows=[];ops={}
 for start,end in [(0x830040,0x8300cd),(0x82f3f0,0x82f429),(0x82f660,0x82f84e)]:
  raw=read(start,end-start);ins=list(md.disasm(raw,start));assert sum(i.size for i in ins)==len(raw) and ins[-1].mnemonic=="ret"
  bounds={i.address for i in ins}
  for i in ins:
   if i.mnemonic.startswith("j") and i.op_str.startswith("0x"):
    target=int(i.op_str,16)
    if start<=target<end:assert target in bounds
  rows=[dict(va=hex(i.address),op=i.mnemonic+" "+i.op_str) for i in ins]
  ops.update({r["va"]:r["op"] for r in rows})
  windows.append(dict(start=hex(start),end_exclusive=hex(end),sha256=hashlib.sha256(raw).hexdigest(),instructions=rows))
 expected={"0x830082":"push 0x34","0x830095":"cmp dword ptr [ebp - 0x18], 3","0x83009a":"je 0x8300b5","0x83009e":"call 0x82f660","0x8300b6":"call 0x82f850","0x82f3f0":"mov dword ptr [esi + 0x20], 2","0x82f3f7":"lea eax, [esi + 0x34]","0x82f410":"add eax, 0x10","0x82f6c0":"push 0x234","0x82f815":"add esi, 0x10","0x82f81e":"cmp eax, 0x20"}
 assert all(ops[k]==v for k,v in expected.items())
 records=[]
 for (name,raw),center in zip(members(a.archive.read_bytes(),ARCHIVE_SHA,PINS).items(),[(418,385),(379,369)]):
  d=decode(raw,max_expanded=8000000);assert hashlib.sha256(d).hexdigest()==PINS[name]
  assert d[:21]==b"MapTool Reinforce 1.0" and struct.unpack_from("<IIIff",d,0x20)==(2,768,768,768.,768.)
  cursor=0x234;layers=[];entries=[]
  for i in range(32):
   off,compressed,expanded,count=struct.unpack_from("<4I",d,0x34+i*16)
   if not count:continue
   assert i<2 and off==cursor and expanded==768*768*4 and count==768*768
   dec=zlib.decompressobj();layer=dec.decompress(d[off:off+compressed]);assert dec.eof and not dec.unused_data and len(layer)==expanded
   layers.append(layer);entries.append(dict(layer=i,offset=off,compressed=compressed,expanded=expanded,cells=count,decoded_sha256=hashlib.sha256(layer).hexdigest()))
   cursor+=compressed
  assert len(layers)==2 and cursor==len(d)
  x,y=center;assert all(struct.unpack_from("<I",l,((y+dy)*768+x+dx)*4)[0]==0 for l in layers for dy in range(-15,16) for dx in range(-15,16))
  records.append(dict(member=name,sha256=PINS[name],bytes=len(d),header_version=2,width=768,height=768,world_width=768,world_height=768,layers=entries,server_chosen_clear_center=list(center),clear_square_radius=15))
 result=dict(classification="PINNED_STATIC_RESOURCE_AND_BOUNDED_NATIVE_LOADER_NOT_OFFICIAL_SPAWN",target_sha256=sha,carrier_sha256=ARCHIVE_SHA,native_windows=windows,exact_instruction_assertions=len(expected),resources=records,limits=["Native830040 routes version3 to82F850; other versions use82F660. This does not admit arbitrary unknown resource versions.","Only these two exact pins are qualified for Server v2 support; bytes never rewritten.","First two static DWORD layers interpreted as existing candidate zero-clear policy; dynamic MEF barriers and runtime height are not modeled.","Chosen centers are deterministic Server reconstruction spawn candidates, not official spawn or chart coordinates.","No game process, network, resources mutation or actual Client compatibility result."])
 a.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")
 print(json.dumps(dict(resources=len(records),native_windows=len(windows),instruction_assertions=len(expected),clear_centers=[r["server_chosen_clear_center"] for r in records])))
if __name__=="__main__":main()
