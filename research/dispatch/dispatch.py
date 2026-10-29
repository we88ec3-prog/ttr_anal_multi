#!/usr/bin/env python3
"""S00 RR dispatch, derived Task inboxes and locally recorded transitions.

Does NOT wake an Agent or publish a claim. Changes need reviewed Git commits.
"""
import argparse
import datetime as dt
import hashlib
import json
import re
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
REGISTRY="research/requests/index.json"
TASKS=tuple(f"T{i:02d}" for i in range(1,17))
PRIORITIES={"P0":0,"P1":1,"P2":2,"P3":3}
STATUS={"QUEUED":"PENDING","CLAIMED":"ACTIVE","IN_PROGRESS":"ACTIVE",
        "SUBMITTED":"ACTIVE","IN_REVIEW":"ACTIVE","NEEDS_REVISION":"ACTIVE",
        "BLOCKED":"BLOCKED","ACCEPTED":"RESOLVED","CANCELLED":"CANCELLED"}
NEXT={"QUEUED":{"CLAIMED","CANCELLED"},"CLAIMED":{"IN_PROGRESS","BLOCKED"},
      "IN_PROGRESS":{"SUBMITTED","BLOCKED"},"SUBMITTED":{"IN_REVIEW","NEEDS_REVISION"},
      "IN_REVIEW":{"ACCEPTED","NEEDS_REVISION","BLOCKED"},
      "NEEDS_REVISION":{"CLAIMED","BLOCKED"},"BLOCKED":{"QUEUED","CANCELLED"},
      "ACCEPTED":set(),"CANCELLED":set()}
SHA1=re.compile(r"[0-9a-f]{40}\Z")
ID=re.compile(r"RR-\d{4,}\Z")
BOOT_MARKER="<!-- S00-DISPATCH-BOOTSTRAP:v1 -->"

def read(root):
    return json.loads((root/REGISTRY).read_text(encoding="utf-8"))

def safe_file(root,path):
    if not isinstance(path,str) or not path or path.startswith("/"):
        return None
    p=(root/path).resolve()
    return p if p.is_relative_to(root.resolve()) and p.is_file() else None

def blob_sha(content):
    return hashlib.sha1(b"blob "+str(len(content)).encode()+b"\x00"+content).hexdigest()

def valid_date(s):
    try:
        return isinstance(s,str) and dt.date.fromisoformat(s).isoformat()==s
    except (ValueError,TypeError):
        return False

def inbox_text(task,rows):
    if task=="T01":
        rows=[r for r in rows if r["dispatch"]["state"] in {"SUBMITTED","IN_REVIEW"}]
        intro="這是 S00 回報待審提示；與 T01 原稿 FULL-PASS、退回通知及歷史台帳分離。"
    else:
        rows=[r for r in rows if r["owner_task"]==task and r["dispatch"]["state"] not in {"ACCEPTED","CANCELLED"}]
        intro="開工前先讀 origin/main 的本頁和 RR 台帳；只有已在 main 公開的認領才是跨 Agent 可見。"
    rows.sort(key=lambda r:(PRIORITIES[r["dispatch"]["priority"]],r["id"]))
    lines=[f"# {task} — S00 研究收件箱（生成檔）","",
           "> 由 research/dispatch/dispatch.py sync 自唯一的 research/requests/index.json 產生，禁止手改本頁。",
           "",intro,"","[唯一 RR 台帳](../../requests/index.json)｜[流程規則](../README.md)",""]
    if not rows:
        lines.append("目前無待處理的 S00 研究請求。")
    else:
        lines+=["| ID | 優先 | 狀態 | 主責 | GAP | 研究問題 |",
                "| --- | --- | --- | --- | --- | --- |"]
        for r in rows:
            title=r["title"].replace("|","/").replace("\n"," ")
            d=r["dispatch"]
            lines.append(f'| {r["id"]} | {d["priority"]} | {d["state"]} | {r["owner_task"]} | {", ".join(r["gap_ids"])} | {title} |')
    lines+=["","新請求不會自動喚醒另一個對話；GitHub 提交/合併後才可供不同 Agent 檢視、認領與回報。",""]
    return "\n".join(lines)

def expected_inboxes(rows):
    return {f"research/dispatch/inbox/{task}.md":inbox_text(task,rows) for task in TASKS}

def sync(root,rows):
    for rel,body in expected_inboxes(rows).items():
        fp=root/rel
        fp.parent.mkdir(parents=True,exist_ok=True)
        fp.write_text(body,encoding="utf-8")

def validate(root=ROOT,boot=True):
    errors=[]
    try:
        data=read(root)
        gaps={g["id"] for g in json.loads((root/"design/gaps/index.json").read_text(encoding="utf-8"))["items"]}
    except (OSError,ValueError,KeyError,TypeError) as e:
        return [f"cannot read RR/GAP registry: {e}"]
    if data.get("schema")!="s00-research-request-index-v1" or not isinstance(data.get("items"),list):
        return ["invalid RR registry schema"]
    rows=data["items"]
    seen=set()
    for r in rows:
        if not isinstance(r,dict):
            errors.append("non-object RR")
            continue
        rid=r.get("id")
        if not isinstance(rid,str) or not ID.fullmatch(rid) or rid in seen:
            errors.append(f"invalid/duplicate RR ID {rid}")
            continue
        seen.add(rid)
        if r.get("owner_task") not in TASKS[1:]:
            errors.append(f"{rid}: invalid owner_task")
        if not isinstance(r.get("gap_ids"),list) or not r["gap_ids"] or any(g not in gaps for g in r["gap_ids"]):
            errors.append(f"{rid}: invalid GAP link")
        d=r.get("dispatch")
        if not isinstance(d,dict) or d.get("state") not in STATUS:
            errors.append(f"{rid}: missing/invalid dispatch state")
            continue
        state=d["state"]
        if r.get("status")!=STATUS[state]:
            errors.append(f"{rid}: status disagrees with dispatch state")
        if d.get("priority") not in PRIORITIES:
            errors.append(f"{rid}: missing/invalid priority")
        if not isinstance(d.get("acceptance_criteria"),str) or not d["acceptance_criteria"].strip():
            errors.append(f"{rid}: acceptance criteria required")
        old=None
        events=d.get("events")
        if not isinstance(events,list) or not events:
            errors.append(f"{rid}: transition audit history required")
            continue
        for i,ev in enumerate(events):
            if not isinstance(ev,dict) or ev.get("from")!=old:
                errors.append(f"{rid}: audit chain broken at event {i}")
                break
            nxt=ev.get("to")
            if nxt not in STATUS or (i==0 and nxt!="QUEUED") or (i>0 and nxt not in NEXT[old]):
                errors.append(f"{rid}: forbidden history transition at {i}")
                break
            if not ev.get("actor") or not ev.get("note") or not valid_date(ev.get("date")):
                errors.append(f"{rid}: incomplete event at {i}")
            old=nxt
        if old!=state:
            errors.append(f"{rid}: state differs from history")
        if state not in {"QUEUED","CANCELLED"}:
            c=d.get("claim")
            if not isinstance(c,dict) or not c.get("actor") or not c.get("branch") or not SHA1.fullmatch(c.get("base_commit","")) or not valid_date(c.get("date")):
                errors.append(f"{rid}: claim actor/branch/base SHA/date required")
        if state in {"SUBMITTED","IN_REVIEW","NEEDS_REVISION","ACCEPTED"}:
            sub=d.get("submission")
            if not isinstance(sub,dict) or not sub.get("summary") or not SHA1.fullmatch(sub.get("report_blob_sha","")):
                errors.append(f"{rid}: submission report metadata missing")
            else:
                fp=safe_file(root,sub.get("report_path"))
                if fp is None or blob_sha(fp.read_bytes())!=sub["report_blob_sha"]:
                    errors.append(f"{rid}: missing/modified submission report")
        if state=="ACCEPTED":
            review=d.get("review")
            if not isinstance(review,dict) or review.get("actor")!="S00" or not review.get("note") or not review.get("outcome_refs"):
                errors.append(f"{rid}: final S00 decision and outcomes required")
    if boot:
        for path,body in expected_inboxes(rows).items():
            fp=safe_file(root,path)
            if fp is None or fp.read_text(encoding="utf-8")!=body:
                errors.append(f"{path}: missing or stale generated inbox")
        for task in TASKS:
            path=f"kr/tasks/{task}/README.md"
            fp=safe_file(root,path)
            if fp is None:
                errors.append(f"{path}: not found")
            else:
                t=fp.read_text(encoding="utf-8")
                if BOOT_MARKER not in t or f"research/dispatch/inbox/{task}.md" not in t:
                    errors.append(f"{path}: missing dispatch bootstrap")
        fp=safe_file(root,"AGENTS.md")
        if fp is None or BOOT_MARKER not in fp.read_text(encoding="utf-8"):
            errors.append("AGENTS.md: missing global startup rule")
    return errors

def transition(root,rid,state,actor,date,note,branch=None,base=None,report=None,outcomes=None):
    data=read(root)
    rows=[x for x in data["items"] if x.get("id")==rid]
    if len(rows)!=1:
        raise ValueError(f"unknown/duplicate RR {rid}")
    r=rows[0]
    d=r["dispatch"]
    old=d["state"]
    if state not in NEXT.get(old,set()):
        raise ValueError(f"illegal transition {old} -> {state}")
    if not actor or not note or not valid_date(date):
        raise ValueError("actor/note/YYYY-MM-DD required")
    if state=="CLAIMED":
        if not branch or not base or not SHA1.fullmatch(base):
            raise ValueError("claim requires unique work branch and current main base SHA")
        d["claim"]={"actor":actor,"branch":branch,"base_commit":base,"date":date}
        if old=="NEEDS_REVISION":
            d["submission"]=None
    if state in {"IN_PROGRESS","SUBMITTED"} and actor!=d["claim"]["actor"]:
        raise ValueError("only claimant can start or submit")
    if state=="SUBMITTED":
        p=safe_file(root,report)
        if p is None:
            raise ValueError("report path must exist in checkout")
        d["submission"]={"report_path":report,"report_blob_sha":blob_sha(p.read_bytes()),
                         "date":date,"summary":note}
    if state in {"IN_REVIEW","NEEDS_REVISION"} and actor not in {"S00","T01"}:
        raise ValueError("only reviewer S00/T01 can review")
    if state=="ACCEPTED":
        if actor!="S00" or not outcomes:
            raise ValueError("final acceptance requires S00 and published SPEC/CLM/GAP/TEST refs")
    if state in {"ACCEPTED","NEEDS_REVISION"}:
        d["review"]={"actor":actor,"date":date,"decision":state,
                     "note":note,"outcome_refs":outcomes or []}
    d["state"]=state
    r["status"]=STATUS[state]
    d["events"].append({"from":old,"to":state,"actor":actor,"date":date,"note":note})
    (root/REGISTRY).write_text(json.dumps(data,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")
    sync(root,data["items"])

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root",type=Path,default=ROOT)
    sub=parser.add_subparsers(dest="command",required=True)
    sub.add_parser("check")
    sub.add_parser("sync")
    show=sub.add_parser("show")
    show.add_argument("task",choices=TASKS)
    tr=sub.add_parser("transition")
    tr.add_argument("request")
    tr.add_argument("state",choices=sorted(STATUS))
    tr.add_argument("--actor",required=True)
    tr.add_argument("--date",default=dt.date.today().isoformat())
    tr.add_argument("--note",required=True)
    tr.add_argument("--branch")
    tr.add_argument("--base")
    tr.add_argument("--report")
    tr.add_argument("--outcome",action="append")
    args=parser.parse_args()
    root=args.root.resolve()
    if args.command=="check":
        problems=validate(root)
        for e in problems:print("ERROR:",e)
        if problems:raise SystemExit(1)
        print("S00 dispatch checks OK (not an Agent wakeup or native verification)")
    elif args.command=="sync":
        sync(root,read(root)["items"])
        print("Generated inboxes; review diff before publication")
    elif args.command=="show":
        print(inbox_text(args.task,read(root)["items"]),end="")
    elif args.command=="transition":
        transition(root,args.request,args.state,args.actor,args.date,args.note,
                   branch=args.branch,base=args.base,report=args.report,outcomes=args.outcome)
        print(f"{args.request} -> {args.state}; commit/merge required for cross-Agent visibility")
if __name__=="__main__":main()
