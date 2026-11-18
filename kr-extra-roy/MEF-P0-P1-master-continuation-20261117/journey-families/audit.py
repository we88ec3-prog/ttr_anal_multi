#!/usr/bin/env python3
"""Read-only original-data joins for the Q119 journey and seven MEF families.

This reads STPD/XML/text and PE bytes; it never runs a Client, Server, Lua,
archived program, or original resource. Only explicitly selected derived
facts are emitted. Complete decoded members are never written.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict, deque
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import zipfile
import zlib

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = "5ed4833b805949fabe260aea77e3fe0fd8e86bfa"
HELPER = "kr-extra-roy/MEF-comprehensive-contracts-20261117/resources/resource_audit.py"
PHASES = {"Phase1", "Phase2", "Phase3", "Phase4", "RevPhase1", "RevPhase2", "RevPhase3", "RevPhase4"}
CALLS = PHASES | {"SetTransitionType", "SetFinalMusic", "HideOriginalObjs", "LoadMap", "MoveCamera", "RotCamera", "CreateObject", "PlayMusic", "PlayCamera", "PlayCameraNoWait", "wait", "WalkObject", "WaitForObjectsStop", "AniObject", "OpenTalkScene", "Q.DeleteAllObject", "RestoreMap", "PlaySound", "WarpObject", "RotateObject", "FlyingObject", "DoProlog", "FadeOut", "FadeIn"}

def sha(b): return hashlib.sha256(b).hexdigest()
def require(x, msg):
    if not x: raise ValueError(msg)
def dump(p, obj):
    require(not p.is_symlink(), "output must not follow a symlink")
    p.write_text(json.dumps(obj, ensure_ascii=False, indent=2)+"\n", encoding="utf-8")
def git(repo, *args):
    return subprocess.check_output(["git", "-C", str(repo), *args], env={**__import__('os').environ, "GIT_NO_LAZY_FETCH":"1", "GIT_OPTIONAL_LOCKS":"0"})

def load_helper(repo, manifest):
    p = next(x for x in manifest["git_sources"] if x["path"] == HELPER)
    b = git(repo, "show", p["commit"]+":"+p["path"])
    require(sha(b) == p["sha256"], "pinned analysis helper mismatch")
    path = repo/HELPER
    require(path.read_bytes() == b, "worktree helper differs from pinned Git object")
    spec = importlib.util.spec_from_file_location("p1_resource_helper", path)
    h = importlib.util.module_from_spec(spec); spec.loader.exec_module(h)
    return h

def whole_function(text, h):
    """Strict whole-file recognizer for selected literal straight-line scenes."""
    ts=h.lua_tokens(text); i=0
    def take(raw=None, kind=None):
        nonlocal i
        require(i < len(ts), "unexpected end of selected scene")
        t=ts[i]; i+=1
        require((raw is None or t["raw"]==raw) and (kind is None or t["kind"]==kind), "unsupported scene token "+t["raw"])
        return t
    take("function"); name=take(kind="name")["raw"]; take("(");take(")")
    rows=[]
    while i < len(ts) and ts[i]["raw"]!="end":
        first=take(kind="name"); fn=first["raw"]
        if ts[i]["raw"]==".": take("."); fn+="."+take(kind="name")["raw"]
        require(fn in CALLS,"unreviewed selected scene call "+fn)
        take("(");args=[];part=[]
        while True:
            t=take()
            if t["kind"]=="symbol" and t["raw"] in [",",")"]:
                if part:
                    value=h.literal(part)
                    require(not isinstance(value,dict) or "unresolved_expression" not in value, "nonliteral argument")
                    args.append(value);part=[]
                else: require(t["raw"]==")" and not args,"empty argument")
                if t["raw"]==")":break
            else:part.append(t)
        rows.append({"function":fn,"line":first["line"],"args":args,"call_sha256":sha(text[first["start"]:t["end"]].encode())})
        if i<len(ts) and ts[i]["raw"]==";":take(";")
    take("end");take("Register");take("(");take(name);take(")")
    require(i==len(ts),"trailing unconsumed scene tokens")
    return name, rows, len(ts)

def pe_sections(b):
    pe=struct.unpack_from("<I",b,60)[0];require(b[pe:pe+4]==b"PE\0\0","not PE")
    machine,n=struct.unpack_from("<HH",b,pe+4);require(machine==0x14c,"not i386")
    opt=pe+24;require(struct.unpack_from("<H",b,opt)[0]==0x10b,"not PE32")
    image=struct.unpack_from("<I",b,opt+28)[0];sec=opt+struct.unpack_from("<H",b,pe+20)[0]
    rows=[]
    for j in range(n):
        o=sec+40*j;vs,va,rs,raw=struct.unpack_from("<4I",b,o+8)
        rows.append({"name":b[o:o+8].rstrip(b"\0").decode(),"va":image+va,"raw":raw,"raw_size":rs,"virtual_size":vs})
    return image, rows

def map_va(sections,va,n):
    hits=[s for s in sections if s["va"]<=va and va+n<=s["va"]+s["raw_size"]]
    require(len(hits)==1,"VA outside a unique raw-backed section")
    return hits[0]["raw"]+va-hits[0]["va"]

def disasm(binary,start,end):
    out=subprocess.check_output(["objdump","-d","-Mintel","--insn-width=16",f"--start-address={start}",f"--stop-address={end}",str(binary)],text=True)
    rows=[]
    for line in out.splitlines():
        m=re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )*[0-9a-f]{2})\s+(.+)$",line)
        if m: rows.append({"va":hex(int(m[1],16)),"hex":m[2].replace(" ",""),"asm":m[3].strip()})
    p=start
    for r in rows:
        require(int(r["va"],16)==p,"instruction coverage gap")
        p+=len(bytes.fromhex(r["hex"]))
    require(p==end,"partial terminal instruction")
    return rows

def static_bound_check(b,node):
    """Reapply published Server static layer0/1 policy, not a Client simulation."""
    require(b[:21]==b"MapTool Reinforce 1.0","unsupported bound signature")
    version,w,h,wx,wy=struct.unpack_from("<IIIff",b,0x20)
    require(version in (0,2) and 0<w<=2048 and 0<h<=2048 and wx>0 and wy>0,"unsupported bound header")
    blocked=bytearray(w*h);cursor=0x234;layers=[]
    for i in range(32):
        off,n,expanded,count=struct.unpack_from("<4I",b,0x34+16*i)
        if not count:continue
        require(i in (0,1) and off==cursor and count==w*h and expanded==count*4,"unsupported nonstatic layer")
        z=zlib.decompressobj();raw=z.decompress(b[off:off+n]);require(z.eof and not z.unused_data and len(raw)==expanded,"invalid compressed bound layer")
        for j,(v,) in enumerate(struct.iter_unpack("<I",raw)):
            if v:blocked[j]=1
        layers.append({"layer":i,"expanded_sha256":sha(raw),"expanded_bytes":len(raw)});cursor+=n
    require([r["layer"] for r in layers]==[0,1] and cursor==len(b),"bound trailing data or layer order")
    positions=[("spawn",node["spawn"]),("portal",node["portal"])]+[("encounter_"+str(i),n) for i,n in enumerate(node["encounters"])]
    checked=[]
    for label,p in positions:
        x,y=p["x"],p["y"];inside=0<=x<wx and 0<=y<wy
        cx,cy=(int(x*w/wx),int(y*h/wy)) if inside else (-1,-1)
        checked.append({"role":label,"x":x,"y":y,"cell":[cx,cy],"can_stand_static":bool(inside and blocked[cy*w+cx]==0)})
    start=tuple(checked[0]["cell"]);goal=tuple(checked[1]["cell"]);q=deque([(start,0)]);seen={start};distance=None
    if checked[0]["can_stand_static"] and checked[1]["can_stand_static"]:
        while q:
            (x,y),dist=q.popleft()
            if (x,y)==goal:distance=dist;break
            for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                v=(x+dx,y+dy)
                if 0<=v[0]<w and 0<=v[1]<h and not blocked[v[1]*w+v[0]] and v not in seen:seen.add(v);q.append((v,dist+1))
    return {"policy":"SERVER_STATIC_LAYER0_1_NONZERO_UNION_NOT_NATIVE_MEF","version":version,"width":w,"height":h,"world_width":wx,"world_height":wy,"layers":layers,"positions":checked,"spawn_portal_4neighbor_distance_cells":distance,"dynamic_obstacles_and_actor_radius_verified":False}

def audit(repo,sources,supplemental):
    require(not sys.flags.optimize,"run without -O")
    manifest=json.loads((HERE/"source-manifest.json").read_text())
    for p in manifest["git_sources"]:
        b=git(repo,"show",p["commit"]+":"+p["path"])
        require(len(b)==p["bytes"] and sha(b)==p["sha256"],"source pin mismatch: "+p["path"])
        require(git(repo,"rev-parse",p["commit"]+":"+p["path"]).decode().strip()==p["blob"],"blob mismatch")
    for p in manifest["originals"]:
        b=((sources if p["group"]=="project_sources" else supplemental)/p["file"]).read_bytes()
        require(len(b)==p["bytes"] and sha(b)==p["sha256"],"original mismatch: "+p["file"])
    h=load_helper(repo,manifest);STP=h.load_stp_reader(repo)
    archives={n:STP(sources/n) for n in ["06-Event.stp","07-Table.stp","10-BoundMap.stp","11-Master.stp"]}
    archives["Base.stp"]=STP(supplemental/"Base.stp")
    used={}
    def read(carrier,member):
        b,m=archives[carrier].get(member);used[carrier+":"+member]=m;return b
    def xml(carrier,member):return h.xml_root(read(carrier,member))
    inventory=[(c,n) for c,a in archives.items() for n in a.files]
    with zipfile.ZipFile(supplemental/"Tartaros-Web-AI-W1-W2-W3-input.zip") as z:
        zlocal=[n for n in z.namelist() if n.startswith("local-resources/") and not n.endswith("/")]
        inventory.extend(("Tartaros-Web-AI-W1-W2-W3-input.zip",n.removeprefix("local-resources/")) for n in zlocal)
        zip_members=[];zip_xml={}
        for name in ["local-resources/Field/MapFlow/CHART_scenario_chicken_01.xml","local-resources/Field/Cluster/CLUST_scenario_chicken_01.xml"]:
            bb=z.read(name);zi=z.getinfo(name);zip_xml[name]=h.xml_root(bb)
            zip_members.append({"member":name,"bytes":len(bb),"sha256":sha(bb),"header_offset":zi.header_offset,"CRC32":zi.CRC,"compressed_bytes":zi.compress_size})
    def lookup(path=None,basename=None):
        return {"requested":path,"basename":basename,"exact":[{"carrier":c,"member":n} for c,n in inventory if path is not None and n==path],
            "casefold":[{"carrier":c,"member":n} for c,n in inventory if path is not None and h.ascii_key(n)==h.ascii_key(path)],
            "basename_candidates":[{"carrier":c,"member":n} for c,n in inventory if basename is not None and h.ascii_key(n.rsplit("/",1)[-1])==h.ascii_key(basename)],
            "runtime_selected":False}
    sr=xml("06-Event.stp","Event/SceneList.xml")
    maps=xml("07-Table.stp","Table/_MapList.xml")
    actors=xml("07-Table.stp","Table/_ActorList.xml")
    talk=xml("07-Table.stp","Table/ScenarioTalkTable.xml")
    sets=xml("07-Table.stp","Table/TalkTableSet.xml")
    # Prior P0 covered only Q119/3's five selected text rows. The new Q119/2,
    # /4 and /5 keys need a bounded duplicate check against active tables.
    # Only matching keys are indexed; full XML stays in memory, and only
    # contributor-member metadata is emitted. This is not a new all-talk export.
    selected_keys=set()
    for n in h.elements(talk,"Scenario"):
        if h.attrs(n).get("id")=="12":
            selected_keys.update(int(h.attrs(t)["talk"]) for t in h.elements(n,"Talk") if "talk" in h.attrs(t))
    alltexts=defaultdict(list)
    for order,s in enumerate(h.elements(sets,"set")):
        member=h.attrs(s)["path"]
        # Read active source tables in memory, save metadata only if selected.
        b,m=archives["07-Table.stp"].get(member)
        for ri,n in enumerate(h.elements(h.xml_root(b),"talk")):
            a=h.attrs(n)
            if "id" not in a or int(a["id"]) not in selected_keys:continue
            used["07-Table.stp:"+member]=m
            text="".join(n.itertext())
            alltexts[int(a["id"])].append({"member":member,"set_ordinal":order,"row_ordinal":ri,"attributes":dict(n.attrib),"text_chars":len(text),"text_sha256":sha(text.encode())})
    def actor_rows(model):
        found=[]
        for ci,cat in enumerate(actors):
            if h.ascii_key(cat.tag)!="objcategory":continue
            ca=h.attrs(cat)
            for ri,n in enumerate(cat):
                a=h.attrs(n)
                if a.get("id")!=str(model):continue
                found.append({"category":int(ca["id"]),"category_ordinal":ci,"row_ordinal":ri,"attributes":dict(n.attrib),"admitted":int(ca["id"])!=3})
        eff=[r for r in found if r["admitted"]]
        return {"model":model,"rows":found,"effective_file":(eff[-1]["attributes"].get("FILE") if eff else None),"binding_status":"catalog only; exact CHA_ABF entry and mounted source still required"}
    scenes=[]
    for idx in range(1,6):
        selectors=[dict(n.attrib) for n in sr.iter() if h.attrs(n).get("questidx")=="119" and h.attrs(n).get("sceneidx")==str(idx)]
        require(len(selectors)==1,"Q119 SceneList selector ambiguity")
        func=selectors[0]["funcName"];member="Event/Sequences/"+func+".seq"
        text=read("06-Event.stp",member).decode("utf-8-sig")
        name,calls,tcount=whole_function(text,h);require(name==func,"Register mismatch")
        camera=[];dialogs=[];models=[]
        for c in calls:
            a=c["args"];fn=c["function"]
            if fn in ["PlayCamera","PlayCameraNoWait"]:
                cm="Event/CameraWorks/"+a[0];cr=xml("06-Event.stp",cm)
                frames=[{"framepos":h.attrs(n)["framepos"],"position":dict(next(iter(h.elements(n,"position"))).attrib),"pivot":dict(next(iter(h.elements(n,"pivot"))).attrib)} for n in h.elements(cr,"keyframe")]
                camera.append({"line":c["line"],"member":cm,"helper":fn,"arguments":a,"keyframe_count":len(frames),"frame_positions":[f["framepos"] for f in frames],"first_frame":frames[0],"last_frame":frames[-1]})
            if fn=="OpenTalkScene":
                matches=[n for n in talk.iter() if h.attrs(n).get("id")==str(a[0]) and h.attrs(n).get("scene")==str(a[1])]
                require(len(matches)==1,"talk selector not unique")
                dr=[]
                for n in h.elements(matches[0],"Talk"):
                    at=h.attrs(n);key=int(at["talk"]);tx=alltexts[key];require(len(tx)==1,"text key does not resolve uniquely")
                    dr.append({"attributes":dict(n.attrib),"text":tx[0]})
                dialogs.append({"line":c["line"],"scenario":a[0],"scene":a[1],"rows":dr})
        for model in sorted({int(c["args"][1]) for c in calls if c["function"]=="CreateObject"}):
            r=actor_rows(model)
            if r["effective_file"]:r["descriptor_candidates"]=lookup(basename=r["effective_file"]+".abf")
            r["slots"]=[int(c["args"][0]) for c in calls if c["function"]=="CreateObject" and int(c["args"][1])==model]
            models.append(r)
        scenes.append({"quest":119,"scene":idx,"selector":selectors[0],"sequence":member,
            "static_parse":{"body_call_count":len(calls),"token_count":tcount,"unconsumed_tokens":0,"executed":False},
            "calls":[{"ordinal":i,"line":c["line"],"function":c["function"],"arity":len(c["args"]),"call_sha256":c["call_sha256"]} for i,c in enumerate(calls)],
            "resource_calls":[c for c in calls if c["function"] in ["LoadMap","SetFinalMusic","PlayMusic","PlaySound"]],
            "models":models,"cameras":camera,"talk_scenes":dialogs,
            "cleanup_call_order":[c["function"] for c in calls if c["function"].startswith("RevPhase") or c["function"] in ["Q.DeleteAllObject","RestoreMap"]]})
    descriptors=[]
    for model in sorted({m["model"] for s in scenes for m in s["models"]}):
        row=next(m for s in scenes for m in s["models"] if m["model"]==model)
        found=[r for r in row["descriptor_candidates"]["basename_candidates"] if r["carrier"]=="Base.stp"]
        if len(found)!=1:continue
        member=found[0]["member"];dr=xml("Base.stp",member);char=h.elements(dr,"Character");require(len(char)==1,"descriptor Character ambiguity")
        descriptors.append({"model":model,"member":member,"character_attributes":dict(char[0].attrib),"animation_count":len(h.elements(char[0],"Animation")),"animation_ids":[int(h.attrs(n)["id"]) for n in h.elements(char[0],"Animation")],"texture_declarations":[dict(n.attrib)for n in h.elements(char[0],"Texture")],"runtime_selection_proven":False,"payloads_loaded":False})
    # Family examples: actual original fields, not authored demonstration IDs.
    sound=xml("07-Table.stp","Table/_Sound.xml")
    sound_list=read("07-Table.stp","Table/_SoundList.txt").decode("utf-8")
    sound_rows=[dict(n.attrib) for n in h.elements(sound,"Sound") if h.attrs(n).get("file")=="Scene/bodyfall.wav"]
    aisen="Event/Sequences/Aisen_01_After.seq";at=read("06-Event.stp",aisen).decode("utf-8-sig")
    _,acalls,_=whole_function(at,h)
    images=[c for c in acalls if c["function"]=="FlyingObject"]
    require(len(images)==1,"selected original FlyingObject count")
    prolog=xml("07-Table.stp","Table/Prolog.xml")
    pro=[n for n in h.elements(prolog,"Prolog") if h.attrs(n).get("idx")=="19"]
    require(len(pro)==1,"Prolog19 ambiguity")
    pro_rows=[]
    for i,n in enumerate(h.elements(pro[0],"Dialog")):
        lines=["".join(x.itertext()) for x in h.elements(n,"Line")]
        pro_rows.append({"ordinal":i,"picture":h.attrs(n)["picturepath"],"line_count":len(lines),"text_sha256":[sha(x.encode()) for x in lines]})
    book=read("07-Table.stp","Table/Book.txt").decode("ascii").split()
    require(len(book)==6,"Book config changed")
    points=xml("07-Table.stp","Table/TutCheckPointList.xml")
    point=[dict(n.attrib) for n in points if h.attrs(n).get("id")=="1"];require(len(point)==1,"point1 ambiguity")
    categories=xml("07-Table.stp","Table/EffectCategoryMapper.xml");category=[n for n in h.elements(categories,"Category") if h.attrs(n).get("name")==point[0]["effect"]];require(len(category)==1,"effect category ambiguity")
    effectrefs=[dict(n.attrib)for n in h.elements(category[0],"Effect")];require(len(effectrefs)==1,"selected TUTPOINT effect changes")
    effecttable=xml("07-Table.stp","Table/EffectList.xml");effects=[dict(n.attrib)for n in h.elements(effecttable,"Effect") if h.attrs(n).get("idx")==effectrefs[0]["effectId"]];require(len(effects)==1,"effect id not unique")
    shops=xml("07-Table.stp","Table/ShopInfo.xml");npcs=xml("07-Table.stp","Table/npctable.xml")
    shop=[n for n in shops if h.attrs(n).get("no")=="2"];require(len(shop)==1,"shop2 ambiguity")
    products=[dict(n.attrib) for n in h.elements(shop[0],"PRODUCT")]
    npc=[n for n in npcs if h.attrs(n).get("id")=="10030"];require(len(npc)==1,"NPC10030 ambiguity")
    product_table=xml("07-Table.stp","Table/Product.xml")
    product=[dict(n.attrib) for n in product_table.iter() if h.attrs(n).get("product")==products[0]["NO"]]
    require(len(product)==1,"product declaration does not resolve uniquely")
    questxml=xml("07-Table.stp","Table/QuestInfo.xml");questrow=[n for n in h.elements(questxml,"Quest") if h.attrs(n).get("id")=="119"];require(len(questrow)==1,"Quest119 ambiguity")
    nextquest=[n for n in h.elements(questxml,"Quest") if h.attrs(n).get("id")=="120"];require(len(nextquest)==1,"Quest120 ambiguity")
    case=xml("07-Table.stp","Table/_CaseList.xml");caserow=[dict(n.attrib) for n in case if h.attrs(n).get("id")=="107"];require(len(caserow)==1,"Case107 ambiguity")
    town=xml("07-Table.stp","Table/_TownList.xml");townrow=[n for n in town if h.attrs(n).get("id")=="1"];require(len(townrow)==1,"Town1 ambiguity")
    chart=zip_xml["local-resources/Field/MapFlow/CHART_scenario_chicken_01.xml"]
    clusters=zip_xml["local-resources/Field/Cluster/CLUST_scenario_chicken_01.xml"]
    links=h.elements(chart,"NodeLink");require(len(links)==1,"chart NodeLink ambiguity")
    chart_link_path=[int(h.attrs(n)["id"]) for n in h.elements(links[0],"Node")]
    require(chart_link_path==[4,3,2,1],"selected original node link changed")
    story=json.loads(git(repo,"show",BASE+":governance/client-variants/20261107-town2-mainline/resources/alsmeer-full-mainline-content-candidate.json"))
    q=next(q for q in story["quests"] if q["quest"]==119)
    ext=json.loads(git(repo,"show",BASE+":design/scenario-content/story-q119-clear-scene.scenario.json"))
    reqs=json.loads(git(repo,"show",BASE+":design/requirements/index.json"))
    selected_reqs=[{k:r.get(k) for k in ["id","title","priority","status"]}for r in reqs["items"] if r["id"] in ["REQ-0010","REQ-0016","REQ-0017","REQ-0018","REQ-0019","REQ-0021"]]
    definition=next(d for d in ext["definitions"] if d["id"]=="story-quest-119")
    require(len(q["scenario"]["nodes"])==len(definition["nodes"])==4,"Q119 node count")
    maprows=[];nodes=[]
    for i,(sn,dn) in enumerate(zip(q["scenario"]["nodes"],definition["nodes"]),1):
        require(sn["map"]==dn["map"],"candidate/external map mismatch")
        mr=[dict(n.attrib) for n in maps if h.attrs(n).get("id")==str(sn["map"])];require(len(mr)==1,"MapList key ambiguity")
        bname="BoundMap/"+mr[0]["BOUND"]+".bnd";bb=read("10-BoundMap.stp",bname)
        maprows.append({"row":mr[0],"bound_member":bname,"bound_bytes":len(bb),"bound_sha256":sha(bb),"static_server_bound_check":static_bound_check(bb,dn),"graphics":lookup(basename=mr[0]["MAP"]+".fld"),"minimap":lookup("Map/Minimap/"+mr[0]["BOUND"]+".mmt",mr[0]["BOUND"]+".mmt"),"trigger_is_loader_proof":False})
        cn=[n for nl in h.elements(chart,"NodeList") for n in nl if h.attrs(n).get("id")==str(sn["sourceNode"])];require(len(cn)==1,"source chart node ambiguity")
        cm=[dict(n.attrib)for n in h.elements(cn[0],"Map")];require(len(cm)==1 and int(cm[0]["id"])==sn["map"],"source chart map mismatch")
        cl=[n for n in h.elements(clusters,"CLUSTER") if h.attrs(n).get("id")==str(sn["selectedCluster"])];require(len(cl)==1,"source cluster ambiguity")
        objects=[dict(n.attrib)for n in h.elements(cl[0],"OBJECT")];expanded=[int(o["ID"]) for o in objects for _ in range(int(o["COUNT"]))];require(expanded==sn["encounterModels"],"candidate cluster model list mismatch")
        nodes.append({"node":i,"source_node":sn["sourceNode"],"source_chart_node":dict(cn[0].attrib),"source_chart_map":cm[0],"map":sn["map"],"cluster":sn["selectedCluster"],"source_cluster_objects":objects,"encounter_models":sn["encounterModels"],"entry_scenes":sn["enterScenes"],"clear_scenes":sn["clearScenes"],"rules":dn["rules"],"spawn":dn["spawn"],"portal":dn["portal"],"authority":"SERVER_RECONSTRUCTION_NOT_NATIVE_MEF"})
    master=[]
    for virtual in ["Event","Table","Character/Mon","Character/Npc","Character/Obj","Image/Prologue","Map/MiniMap","Synopsis","Field","Effect"]:
        member="Master0z/"+virtual+"/AttachedPackage"
        raw=read("11-Master.stp",member).decode("ascii")
        master.append({"member":member,"virtual_directory":virtual,"declared_carrier":raw.replace("\\","/")+".stp","meaning":"declared mount; does not prove carrier installation, cache winner, or payload success"})
    evidence={"schema":"MEF_P1_REAL_DATA_JOINS_V1","source_baseline":BASE,
        "inventory":{"archive_counts":{c:len(a.files) for c,a in archives.items()},"zip_local_members":len(zlocal),"scope":"only supplied indexes; no claim about a complete installation"},
        "q119_scenes":scenes,"available_q119_model_descriptors":descriptors,"server_journey":{"quest":119,"npc":q["npc"],"intro_scenes":q["introScenes"],"return_scenes":q["returnScenes"],"return_town":q["returnTown"],"field":q["scenario"]["field"],"case":q["scenario"]["case"],"formation_token":q["formationToken"],"original_quest":{"attributes":dict(questrow[0].attrib),"demands":[dict(n.attrib)for n in h.elements(questrow[0],"Demand")],"reward_types_uninterpreted":[dict(n.attrib)for n in h.elements(questrow[0],"Reward")]},"following_quest":{"attributes":dict(nextquest[0].attrib),"demands":[dict(n.attrib)for n in h.elements(nextquest[0],"Demand")]},"original_case":caserow[0],"source_chart_link_path":chart_link_path,"town1_npc_roster":[int(h.attrs(n)["id"])for n in h.elements(townrow[0],"NPC")],"nodes":nodes,"maps":maprows},"existing_server_requirements":selected_reqs,
        "family_examples":{"camera":{"scene":"Q119/2","selected":scenes[1]["cameras"][0]},
            "sound":{"scene":"Q119/4","path":"Sound/Scene/bodyfall.wav","declarations":sound_rows,"payload":lookup("Sound/Scene/bodyfall.wav","bodyfall.wav"),"BGM003_soundlist_rows":[line for line in sound_list.splitlines() if line.split()[-1:]==["Sound/BGM003.ogg"]]},
            "images":{"sequence":aisen,"call":images[0],"payload":lookup(images[0]["args"][0],"Aisen00_1.dds"),"conditional_packed_candidate":lookup("Image/Prologue/Aisen00_1.etf","Aisen00_1.etf"),"packed_candidate_scope":"same-round master-resource-closure independently proves image/Prolog 737D40 original-existence probe and conditional .etf rewrite; not fallback on arbitrary original decode failure","prolog19":{"dialogs":pro_rows,"unique_pictures":sorted({x["picture"] for x in pro_rows})}},
            "book_tutorial":{"config":"Table/Book.txt","position":[float(x) for x in book[:3]],"angles_or_native_second_vector":[float(x) for x in book[3:]],"fixed_model_requests":[lookup(f"Synopsis/book{i:02d}.gb3",f"book{i:02d}.gb3") for i in range(1,5)],"integer_argument_selects_book":False},
            "world_npc_services":{"shop":dict(shop[0].attrib),"product_count":len(products),"first_product_declaration":products[0],"first_product_matches":product,"npc":dict(npc[0].attrib),"talkset_count":len(h.elements(npc[0],"TALKSET")),"npc_model":actor_rows(10030),"return_scene_world_appearance_candidate":actor_rows(10047)},
            "interaction_points":{"source":"Table/TutCheckPointList.xml","selected":point[0],"native_category":4,"status_identity":{"category":4,"key":1},"effect_category":dict(category[0].attrib),"effect_subcategories":[dict(n.attrib)for n in h.elements(category[0],"SubCategory")],"effect_references":effectrefs,"effect_declaration":effects[0],"effect_payload":lookup(basename=effects[0]["File"])},
            "scene_minimap":{"map":maprows[0],"marker_candidates":[lookup("Map/Minimap/fieldMinimap.mmm"),lookup("Map/Minimap/townMinimap.mmm"),lookup("Map/Minimap/minimapSymbols.eif")]}},
        "master_mount_declarations":master,"members":[used[k] for k in sorted(used)],"zip_members":zip_members,"client_executed":False,"lua_executed":False,"server_executed":False,"playability_verified":False}
    return evidence

def native_audit(repo,sources):
    spec=json.loads((HERE/"native-selection.json").read_text());binary=sources/"02-Tartaros.bin";b=binary.read_bytes();image,sections=pe_sections(b)
    rows=[]
    for item in spec["reused"]:
        obj=json.loads(git(repo,"show",BASE+":"+item["path"]))
        records=obj.get("windows",obj.get("records",[]))
        record=next(r for r in records if r["id"]==item["id"])
        va=int(record.get("va",record.get("start")),16);n=record.get("length",record.get("bytes"))
        if n is None:n=int(record.get("end",record.get("end_exclusive")),16)-va
        off=map_va(sections,va,n);body=b[off:off+n]
        require(sha(body)==record["sha256"],"native source window differs: "+item["id"])
        if "hex" in record:require(body.hex()==record["hex"],"native stored bytes differ")
        rows.append({"source_path":item["path"],"source_id":item["id"],"va":hex(va),"raw":off,"bytes":n,"sha256":sha(body),"scope":"reused bounded native window, independently matched to original PE bytes"})
    fresh=[]
    for item in spec["new"]:
        start=int(item["start"],16);end=int(item["end"],16);off=map_va(sections,start,end-start);body=b[off:off+end-start]
        row={**item,"raw":off,"bytes":len(body),"sha256":sha(body),"hex":body.hex()}
        if item["kind"]=="code":row["instructions"]=disasm(binary,start,end)
        else: row["ascii"]=body.decode("ascii")
        fresh.append(row)
    return {"schema":"MEF_P1_BOUNDED_NATIVE_V1","binary_sha256":sha(b),"image_base":hex(image),"reused":rows,"new":fresh,"scope":"selected paths only; no global negative proof, original code never executed"}

def render_native_asm(native):
    lines=["; P1 new bounded original-code windows. Reused windows remain in pinned publications.","; BIN SHA256 "+native["binary_sha256"]]
    for n in native["new"]:
        lines += ["", "; "+n["id"]+" | "+n["claim"], "; VA "+n["start"]+".."+n["end"]+" raw "+hex(n["raw"])+" SHA256 "+n["sha256"]]
        lines += [(r["va"]+"  "+r["hex"].ljust(32)+"  "+r["asm"]) for r in n.get("instructions",[])] if n["kind"]=="code" else ["db "+n["hex"]]
    return "\n".join(lines)+"\n"

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("--repo",type=Path,required=True);ap.add_argument("--sources",type=Path,required=True);ap.add_argument("--supplemental",type=Path,required=True);ap.add_argument("--output",type=Path,required=True)
    a=ap.parse_args();out=a.output.resolve()
    for root in [a.sources.resolve(),a.supplemental.resolve()]:require(out!=root and root not in out.parents and out not in root.parents,"output overlaps originals")
    require(a.repo.resolve() not in out.parents or out==HERE,"repository output restricted to owned package")
    evidence=audit(a.repo,a.sources,a.supplemental);native=native_audit(a.repo,a.sources)
    out.mkdir(parents=True,exist_ok=True);dump(out/"data-evidence.json",evidence);dump(out/"native-evidence.json",native)
    asm=out/"native-evidence.asm";require(not asm.is_symlink(),"ASM output must not follow a symlink");asm.write_text(render_native_asm(native))
    print(json.dumps({"result":"PASS","scenes":len(evidence["q119_scenes"]),"family_examples":len(evidence["family_examples"]),"original_members":len(evidence["members"]),"reused_native_windows":len(native["reused"]),"new_native_windows":len(native["new"]),"output":str(out)},ensure_ascii=False))
if __name__=="__main__":main()
