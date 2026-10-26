"""Read frozen per-function review status. Does not execute target or analysis tools."""
import argparse,gzip,json,pathlib,re
def main():
    ap=argparse.ArgumentParser();ap.add_argument('address',nargs='?');ap.add_argument('--summary',action='store_true');args=ap.parse_args()
    root=pathlib.Path(__file__).resolve().parent.parent;batch=root/'shared/integrations/T01-BULK-20261026-02'
    if args.summary:print((batch/'summary.json').read_text(encoding='utf-8'));return
    if not args.address or not re.fullmatch(r'0[xX][0-9a-fA-F]+',args.address):ap.error('Provide a hexadecimal VA, or --summary')
    address=hex(int(args.address,16))
    with gzip.open(batch/'review-status.jsonl.gz','rt',encoding='utf-8') as stream:
        for line in stream:
            row=json.loads(line)
            if row['address']==address:print(json.dumps(row,ensure_ascii=False,indent=2));return
    print(json.dumps({'address':address,'status':'not-in-frozen-bulk-upload'}));raise SystemExit(2)
if __name__=='__main__':main()
