#!/usr/bin/env python3
"""Recompute this bounded data-only analysis without executing game code."""
from __future__ import annotations
import argparse
import ast
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import sys
sys.dont_write_bytecode=True
import audit

HERE=Path(__file__).resolve().parent

def strict_json(path):
    def unique(pairs):
        d={}
        for k,v in pairs:
            audit.require(k not in d,"duplicate JSON key: "+k);d[k]=v
        return d
    return json.loads(path.read_text(),object_pairs_hook=unique,parse_constant=lambda x:(_ for _ in ()).throw(ValueError(x)))

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo",type=Path,required=True);ap.add_argument("--sources",type=Path,required=True)
    ap.add_argument("--supplemental",type=Path,required=True);ap.add_argument("--receipt",type=Path)
    a=ap.parse_args();require=audit.require
    for p in HERE.glob("*.json"):strict_json(p)
    for p in HERE.glob("*.py"):ast.parse(p.read_text(),filename=p.name)
    actual=audit.audit(a.repo,a.sources,a.supplemental);native=audit.native_audit(a.repo,a.sources)
    require(actual==strict_json(HERE/"data-evidence.json"),"derived original-data evidence differs")
    require(native==strict_json(HERE/"native-evidence.json"),"bounded native replay differs")
    require((HERE/"native-evidence.asm").read_text()==audit.render_native_asm(native),"human-readable ASM differs from original-byte replay")
    contracts=strict_json(HERE/"contracts.json");scenes=actual["q119_scenes"];journey=actual["server_journey"]
    require([s["scene"] for s in scenes]==[1,2,3,4,5],"five separate Q119 selectors required")
    require([s["static_parse"]["body_call_count"] for s in scenes]==[16,33,46,48,33],"Q119 full body coverage changed")
    require(all(s["static_parse"]["unconsumed_tokens"]==0 for s in scenes),"unconsumed scene input")
    required_order=["RevPhase4","RevPhase3","RevPhase2","Q.DeleteAllObject","RestoreMap","RevPhase1"]
    require(all(s["cleanup_call_order"]==required_order for s in scenes),"selected original cleanup order changed")
    require([n["map"] for n in journey["nodes"]]==[632,633,634,635],"normal journey map order")
    require([n["source_node"] for n in journey["nodes"]]==[4,3,2,1],"original chart and Server ordinal conflated")
    require([n["portal"]["preRegisterClosed"] for n in journey["nodes"]]==[False,False,False,True],"portal publication policy differs across the four nodes")
    require(contracts["portal_policy_by_node"]==[{"node":n["node"],"map":n["map"],"key":n["portal"]["key"],"preRegisterClosed":n["portal"]["preRegisterClosed"]} for n in journey["nodes"]],"authored portal contract differs from source candidate")
    require(journey["nodes"][3]["entry_scenes"]==[3] and journey["nodes"][3]["clear_scenes"]==[4] and journey["return_scenes"]==[5],"entry/clear/return conflated")
    require(journey["nodes"][3]["encounter_models"]==[1001,1001,1001,1022],"candidate boss changed")
    require(scenes[2]["models"][0]["model"]==1086,"Q model/source domain changed")
    positions=[p for m in journey["maps"] for p in m["static_server_bound_check"]["positions"]]
    require(len(positions)==21 and all(p["can_stand_static"] for p in positions),"selected static stand checks")
    require(all(m["static_server_bound_check"]["spawn_portal_4neighbor_distance_cells"]==12 for m in journey["maps"]),"static route evidence changed")
    family_ids={"camera","sound","images","book_tutorial","world_npc_services","interaction_points","scene_minimap"}
    require({f["id"] for f in contracts["families"]}==set(actual["family_examples"])==family_ids,"family coverage")
    for f in contracts["families"]:
        require(all(f.get(k) for k in ["data_pointer","acquire","complete","exit","resources","server","native"]),"incomplete family contract: "+f["id"])
    require(len(contracts["journey"])==10,"normal journey scope")
    require(set(s for step in contracts["journey"] for s in step["scenes"])=={1,2,3,4,5},"not all original scenes connected")
    for step in contracts["journey"]:
        require(all(step.get(k) for k in ["selectors","wire","entry","completion","server_requirement"]),"incomplete journey step")
    point=actual["family_examples"]["interaction_points"]
    require(point["selected"]["id"]=="1" and point["native_category"]==4 and point["effect_references"][0]["effectId"]=="98", "typed tutorial point/effect join")
    require(point["effect_declaration"]["File"]=="A_Zone_TutorialZone01.eff","invented effect filename")
    shop=actual["family_examples"]["world_npc_services"]
    require(shop["shop"]["NO"]=="2" and shop["shop"]["NPC"]=="10030" and shop["npc"]["TYPE"]=="12", "shop identity join")
    require(shop["first_product_matches"][0]["PRODUCT"]=="2614" and shop["first_product_matches"][0]["ITEM"]=="2607", "product/item identities conflated")
    require(not shop["npc_model"]["rows"],"service NPC visual source assumption changed")
    schema=json.loads(audit.git(a.repo,"show",audit.BASE+":design/scenario-content/local-scenario-definition.schema.json"))
    require(schema["$defs"]["rule"]["properties"]["event"]["enum"]==["Entry","GroupCleared","InteractZ"],"external schema event surface changed")
    require(schema["$defs"]["rule"]["properties"]["action"]["enum"]==["SpawnGroup","UnlockPortal","NextNode","Result"],"external schema action surface changed")
    require(not contracts["status"]["deployable_ready"] and not contracts["native_mef_grammar_recovered"],"unsupported readiness promotion")
    require(all(r["status"]=="CANDIDATE" for r in actual["existing_server_requirements"]),"unreviewed formal requirement status")
    h=audit.load_helper(a.repo,strict_json(HERE/"source-manifest.json"))
    bad=["function T() if TRUE then wait(1) end end Register(T)","function T() x=1 end Register(T)","function T() PlayMusic(x..'a') end Register(T)","function T() wait(1) end Register(T) wait(2)"]
    rejected=0
    for text in bad:
        try:audit.whole_function(text,h)
        except (ValueError,IndexError):rejected+=1
    require(rejected==len(bad),"analysis recognizer accepted unsupported source")
    artifacts=[]
    for p in sorted(HERE.iterdir()):
        if p.is_file() and p.name not in ["verification-result.json"]:
            b=p.read_bytes();artifacts.append({"file":p.name,"bytes":len(b),"sha256":audit.sha(b)})
    result={"schema":"MEF_P1_JOURNEY_FAMILY_VERIFICATION_V1","result":"PASS","utc":datetime.now(timezone.utc).isoformat(),
        "baseline":audit.BASE,"source_pins":len(strict_json(HERE/"source-manifest.json")["git_sources"]),"original_carriers":7,
        "original_STP_members":len(actual["members"]),"original_ZIP_members":len(actual["zip_members"]),"q119_scenes":5,"whole_scene_body_calls":sum(s["static_parse"]["body_call_count"] for s in scenes),
        "camera_members":sum(len(s["cameras"])for s in scenes),"selected_talk_rows":sum(len(t["rows"])for s in scenes for t in s["talk_scenes"]),
        "family_contracts":7,"journey_steps":10,"bound_position_checks":len(positions),"bound_route_checks":4,
        "reused_native_windows":len(native["reused"]),"new_native_windows":len(native["new"]),"new_native_bytes":sum(n["bytes"]for n in native["new"]),
        "analyzer_negative_cases":rejected,"artifacts":artifacts,
        "executed":{"client":False,"server":False,"lua":False,"archive_programs":False},"meaning":"bounded static data and evidence replay; not native grammar, T01 FULL-PASS, deployment or gameplay acceptance"}
    if a.receipt:
        receipt=a.receipt.resolve()
        for root in [a.sources.resolve(),a.supplemental.resolve()]:require(receipt!=root and root not in receipt.parents,"receipt overlaps originals")
        require(a.repo.resolve() not in receipt.parents or receipt.parent==HERE,"repository receipt path outside owned package")
        require(not a.receipt.is_symlink(),"receipt must not follow symlink")
        audit.dump(receipt,result)
    print(json.dumps({k:v for k,v in result.items() if k!="artifacts"},ensure_ascii=False,indent=2))

if __name__=="__main__":main()
