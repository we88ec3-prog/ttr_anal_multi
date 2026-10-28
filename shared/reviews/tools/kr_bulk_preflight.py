#!/usr/bin/env python3
"""Read-only preflight: do not confuse a non-empty index with a valid snapshot."""
import argparse, hashlib, json, pathlib, re
SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
ADDRESS=re.compile(r'0[xX][0-9a-fA-F]+\Z')
def check(root, expected_rows=111054):
    base=pathlib.Path(root).resolve()/'kr-bulk-roy'/SHA
    index=base/'index.jsonl'
    result=dict(schema='kr-bulk-preflight-v2',source_sha256=SHA,index_exists=index.is_file(),index_sha256=None,index_bytes=None,rows=0,unique_addresses=0,malformed_rows=0,source_sha_mismatch=0,invalid_addresses=0,duplicate_addresses=0,expected_rows=expected_rows,ready_for_full_audit=False,status='BLOCKED_NO_COMPLETE_INDEX')
    if not index.is_file():return result
    if not (base/'functions').is_dir() or not (base/'raw').is_dir():
        result['status']='BLOCKED_MISSING_DIRECTORY';return result
    seen=set(); h=hashlib.sha256()
    with index.open('rb') as f:
        for line in f:
            h.update(line);result['rows']+=1
            try: row=json.loads(line)
            except (UnicodeDecodeError,json.JSONDecodeError):
                result['malformed_rows']+=1;continue
            if not isinstance(row,dict):result['malformed_rows']+=1;continue
            address=row.get('address')
            if not isinstance(address,str) or not ADDRESS.fullmatch(address):
                result['invalid_addresses']+=1
            elif address in seen:result['duplicate_addresses']+=1
            else:seen.add(address)
            if row.get('source_sha256') != SHA:result['source_sha_mismatch']+=1
    result['index_sha256']=h.hexdigest();result['index_bytes']=index.stat().st_size
    result['unique_addresses']=len(seen)
    if not result['index_bytes']:result['status']='BLOCKED_EMPTY_INDEX'
    elif any(result[x] for x in ['malformed_rows','source_sha_mismatch','invalid_addresses','duplicate_addresses']):result['status']='BLOCKED_INDEX_STRUCTURE_ISSUES'
    elif expected_rows is not None and result['rows']!=expected_rows:result['status']='BLOCKED_UNEXPECTED_ROW_COUNT'
    else:result['ready_for_full_audit']=True;result['status']='PREFLIGHT_ONLY_READY_FOR_FULL_AUDIT'
    return result

def main():
    p=argparse.ArgumentParser();p.add_argument('repository_root');p.add_argument('--output');p.add_argument('--expected-rows',type=int,default=111054)
    a=p.parse_args();result=check(a.repository_root,a.expected_rows);s=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if a.output:pathlib.Path(a.output).write_text(s,encoding='utf-8')
    print(s,end='');return 0 if result['ready_for_full_audit'] else 2
if __name__=='__main__':raise SystemExit(main())
