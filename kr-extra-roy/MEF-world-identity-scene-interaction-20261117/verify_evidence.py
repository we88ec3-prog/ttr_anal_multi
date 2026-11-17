#!/usr/bin/env python3
"""Read-only bounded world/scene evidence verification.
Requires Python 3 and GNU objdump. No game, Lua, Server, network or Git writes.
The models are explicitly derived, not execution of native Client code.
"""
from __future__ import annotations
import argparse, hashlib, importlib.util, json, re, struct, subprocess, sys, unittest
from pathlib import Path
import xml.etree.ElementTree as ET
import io

EXPECTED_BIN = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
EXPECTED_READER = "14cb262d8abfaabadcf3160d9cf4e404587dca8b4273175de3a1549170f1c9dd"
EVENT_SHA = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
def require(value, message):
    if not value: raise ValueError(message)
def digest(data): return hashlib.sha256(data).hexdigest()
def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    require(spec and spec.loader, "Unable to load reviewed inspection module")
    mod = importlib.util.module_from_spec(spec)
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod
class PE:
    def __init__(self, path):
        self.b = Path(path).read_bytes()
        require(digest(self.b)==EXPECTED_BIN, "Wrong original KR BIN")
        b=self.b; require(b[:2]==b"MZ","MZ")
        pe=struct.unpack_from("<I",b,0x3c)[0]
        require(b[pe:pe+4]==b"PE\0\0","PE")
        require(struct.unpack_from("<H",b,pe+4)[0]==0x14c,"i386")
        opt=pe+24; require(struct.unpack_from("<H",b,opt)[0]==0x10b,"PE32")
        self.base=struct.unpack_from("<I",b,opt+28)[0]
        require(self.base==0x400000,"image base")
        first=opt+struct.unpack_from("<H",b,pe+20)[0]
        self.sections=[]
        for i in range(struct.unpack_from("<H",b,pe+6)[0]):
            o=first+i*40
            name=b[o:o+8].rstrip(b"\0").decode("ascii")
            vs,rva,n,raw=struct.unpack_from("<IIII",b,o+8)
            self.sections.append(dict(name=name,va=self.base+rva,virtual_size=vs,raw_size=n,raw=raw))
    def raw(self, va, n=1):
        ss=[s for s in self.sections if s["va"]<=va and va+n<=s["va"]+s["raw_size"]]
        require(len(ss)==1,f"not uniquely raw backed {va:#x}+{n}")
        return ss[0]["raw"]+va-ss[0]["va"]
    def at(self,va,n):o=self.raw(va,n);return self.b[o:o+n]
    def u32(self,va):return struct.unpack("<I",self.at(va,4))[0]
    def cstr(self,va):
        raw=self.raw(va);end=self.b.index(0,raw)
        return self.b[raw:end].decode("ascii")
    def e8_candidates(self,target):
        s=next(s for s in self.sections if s["name"]==".text")
        data=self.b[s["raw"]:s["raw"]+s["raw_size"]];hits=[];off=0
        while True:
            off=data.find(b"\xe8",off)
            if off<0: break
            if off+5<=len(data):
                va=s["va"]+off
                if va+5+struct.unpack_from("<i",data,off+1)[0]==target:hits.append(hex(va))
            off+=1
        return hits
    def literals(self,target):
        needle=struct.pack("<I",target);hits=[]
        for s in self.sections:
            if s["name"] not in (".text",".rdata",".data"):continue
            data=self.b[s["raw"]:s["raw"]+s["raw_size"]];off=0
            while True:
                off=data.find(needle,off)
                if off<0:break
                hits.append([s["name"],hex(s["va"]+off)]);off+=1
        return hits
def disassemble(path, start, end):
    text=subprocess.check_output(["objdump","-D","-Mintel","--insn-width=16",
       "--start-address="+hex(start),"--stop-address="+hex(end+15),str(path)],text=True)
    instructions=[]
    pattern=re.compile(r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)")
    for line in text.splitlines():
        m=pattern.match(line)
        if not m:continue
        va=int(m[1],16)
        if start<=va<end:
            instructions.append(dict(va=hex(va),hex=bytes.fromhex(m[2]).hex(),asm=m[3].strip()))
    cursor=start
    for ins in instructions:
        require(int(ins["va"],16)==cursor,"instruction gap")
        require("(bad)" not in ins["asm"] and ".byte" not in ins["asm"],"invalid/truncated instruction")
        cursor+=len(bytes.fromhex(ins["hex"]))
    require(cursor==end,"window ends inside an instruction")
    return instructions

def run(args):
    require(not sys.flags.optimize,"Do not use -O")
    sys.dont_write_bytecode=True
    e=args.evidence_dir
    native=json.loads((e/"native-evidence.json").read_text(encoding="utf-8"))
    resources=json.loads((e/"resource-evidence.json").read_text(encoding="utf-8"))
    pe=PE(args.bin)
    require(native["binary_sha256"]==EXPECTED_BIN,"manifest BIN")
    asm=[];count=0
    for w in native["windows"]:
        va,end=int(w["va"],16),int(w["end"],16);n=end-va
        require(n==w["bytes"] and pe.raw(va,n)==int(w["raw"],16),"window mapping "+w["id"])
        require(digest(pe.at(va,n))==w["sha256"],"window digest "+w["id"])
        ins=disassemble(args.bin,va,end)
        require(len(ins)==w["decoded_instructions"],"instruction count "+w["id"])
        count+=len(ins)
        asm.append(f'\n; {w["id"]} {w["va"]}..{w["end"]} raw={w["raw"]} SHA256={w["sha256"]}\n')
        asm.extend(f'{i["va"]:12} {i["hex"]:32} {i["asm"]}\n' for i in ins)
    require("".join(asm)==(e/"native-evidence.asm").read_text(encoding="utf-8"),"readable ASM differs")
    for rec in native["anchors"]+native["data"]:
        va=int(rec["va"],16);raw=bytes.fromhex(rec["hex"])
        require(pe.raw(va,len(raw))==int(rec["raw"],16),"anchor mapping")
        require(pe.at(va,len(raw))==raw,"anchor bytes "+rec["id"])
        if "rtti_name" in rec:
            col=pe.u32(va-4);td=pe.u32(col+12)
            require(col==int(rec["rtti_col"],16) and td==int(rec["rtti_type_descriptor_va"],16) and td+8==int(rec["rtti_name_va"],16),"RTTI pointers")
            require(pe.cstr(td+8)==rec["rtti_name"],"RTTI name")
    for target,hits in native["direct_xref_scope"].items():
        require(pe.e8_candidates(int(target,16))==hits,"bounded E8 candidates "+target)
    for target,hits in native["literal_xref_scope"].items():
        require(pe.literals(int(target,16))==hits,"bounded literal candidates "+target)

    # Actual selected transfer/binding relationships, not name-only checks.
    calls=[(0x4a0b25,0x4df510),(0x4b2557,0x4df510),(0x4aa057,0x4dfbc0),
           (0x4b2ac2,0x4dfbc0),(0x4b253a,0x5449a0),(0x4df787,0x7c1e00),
           (0x4df9c7,0x4df1a0),(0x4df9fa,0x56cd10),(0x563d45,0x7c1e00),
           (0x56435c,0x7c1e00)]
    for site,target in calls:
        raw=pe.at(site,5)
        require(raw[0]==0xe8 and site+5+struct.unpack_from("<i",raw,1)[0]==target,"call relation "+hex(site))
    slots=[(0xc0c9dc,0,0x4d18d0),(0xc0c9dc,0x14,0x4d1f80),
           (0xc0ca64,8,0x4ca060),(0xc077cc,4,0x4cb590),(0xc077cc,8,0x4cb710),
           (0xc0705c,0x2c,0x4230f0),(0xc073b4,0x2c,0x4c4910),
           (0xc0fac4,0x14,0x545210),(0xc0fa14,0x14,0x547750),
           (0xc0fac4,0x1c,0x545290),(0xc0fa14,0x1c,0x545290)]
    for table,slot,target in slots:
        require(pe.u32(table+slot)==target,"vtable target")
    require(pe.at(0x4ab598,2)==bytes.fromhex("c705") and
            pe.u32(0x4ab59a)==0xfe1868 and pe.u32(0x4ab59e)==0x4a9fe0,"DeleteObject native registrar")
    require(pe.u32(0xf7de04)==1001,"local counter initial")
    # Data-only parser is hash-pinned before importing it.
    reader_path=e/"stp_reader.py";require(digest(reader_path.read_bytes())==EXPECTED_READER,"reviewed reader")
    reader=load_module("reviewed_world_scene_reader",reader_path)
    archives={"Table.stp":reader.STP(args.table_stp),"Event.stp":reader.STP(args.event_stp),
              "BoundMap.stp":reader.STP(args.boundmap_stp)}
    require(archives["Event.stp"].sha==EVENT_SHA,"Event identity")
    for r in resources["records"]:
        member=r["member"];data,actual=archives[member["carrier"]].get(member["path"])
        require(actual==member,"exact selected member identity "+member["path"])
        if "selected_rows" in r:
            tree=ET.fromstring(data)
            for selected in r["selected_rows"]:
                hits=[x for x in tree.iter() if all(x.attrib.get(k)==v for k,v in selected.items())]
                require(len(hits)==1,"selected XML row "+str(selected))
        if "prefix_hex" in r:require(data.startswith(bytes.fromhex(r["prefix_hex"])),"BND prefix")
    require(len(archives["Table.stp"].files)==resources["table_members_checked"],"Table index count")
    require(len(archives["Event.stp"].files)==resources["event_members_checked"],"Event index count")
    exact=[]
    for name in resources["mapflow_cluster_reference_names"]:
        for carrier in ("Table.stp","Event.stp"):
            for member in archives[carrier].files:
                if member.rsplit("/",1)[-1]==name:exact.append([carrier,member])
    require(exact==resources["exact_reference_members_in_attached_table_event"],"bounded reference filename search")
    model=load_module("world_scene_synthetic_models",e/"model_checks.py")
    log=io.StringIO()
    result=unittest.TextTestRunner(stream=log,verbosity=0).run(unittest.defaultTestLoader.loadTestsFromModule(model))
    require(result.wasSuccessful(),"synthetic model check failure: "+log.getvalue())
    return dict(
        status="PASS",scope="Original identities, bounded native bytes/decoding, specific dataflow anchors and selected resource attributes",
        original_bin_sha256=EXPECTED_BIN,native_windows=len(native["windows"]),
        native_interval_bytes=sum(x["bytes"] for x in native["windows"]),decoded_instructions=count,
        anchors=len(native["anchors"]),data_windows=len(native["data"]),selected_vtable_relations=len(slots),
        selected_direct_call_relations=len(calls),bounded_xref_targets=len(native["direct_xref_scope"]),
        literal_xref_targets=len(native["literal_xref_scope"]),selected_resource_members=len(resources["records"]),
        synthetic_model_tests=result.testsRun,
        client_executed=False,lua_executed=False,server_executed=False,
        ordinary_world_event_to_lua_closed=False,official_mef_grammar_proved=False,
        limits=["Selected interval validation, not whole-program semantic proof or T01 FULL-PASS",
                "Synthetic models verify only stated derived arithmetic/order, not native execution",
                "Resource identifiers do not establish legal spawn/portal or runtime successful loading",
                "Inherited Git pins were read through connector, not refetched by this offline verifier",
                "No live packet/Client/Server/gameplay acceptance"])
def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--bin",type=Path,required=True)
    p.add_argument("--table-stp",type=Path,required=True)
    p.add_argument("--event-stp",type=Path,required=True)
    p.add_argument("--boundmap-stp",type=Path,required=True)
    p.add_argument("--evidence-dir",type=Path,default=Path(__file__).resolve().parent)
    args=p.parse_args()
    print(json.dumps(run(args),ensure_ascii=False,indent=2))
if __name__=="__main__":
    try:main()
    except (ValueError,AssertionError,OSError,KeyError,struct.error,subprocess.CalledProcessError) as exc:
        print("FAIL: "+str(exc),file=sys.stderr)
        raise SystemExit(1)
