"""Bounded offline cache-consumer audit. Reuses pinned bulk C and selected original bytes.
Does not start a decompiler/provider, execute/attach a target, or alter Client/Server inputs.
"""
from pathlib import Path
import argparse,bisect,hashlib,json,re,struct,subprocess,sys
parser=argparse.ArgumentParser();parser.add_argument('--workspace-root',type=Path,default=Path(__file__).resolve().parents[4]);args=parser.parse_args()
R=args.workspace_root.resolve();D=Path(__file__).parent
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
B=R/'anal-multi/kr-bulk-roy'/TARGET;F=B/'functions'
sys.path.insert(0,str(R/'anal'))
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
pe=PE(R/'Tartaros.bin');assert sha(pe.data)==TARGET
index_rows=[json.loads(l) for l in (B/'index.jsonl').read_text(encoding='utf-8').splitlines()]
index={int(x['address'],16):x for x in index_rows if x.get('status')=='ok'};starts=sorted(index)
addresses=[0x825f70,0x825fa0,0x826280,0x4e46d0,0x4e48a0,0x549980,0x54ae70,0x548d20,0x54f270,
 0x530530,0x5305c0,0x530650,0x4704c0,0x5cd520,0x617b70,0x61b0b0,0x61e4a0,0x81a8e0]
sources=[]
for addr in addresses:
 meta=index[addr];path=F/f'0x{addr:x}.c';data=path.read_bytes();assert sha(data)==meta['pseudocode_sha256']
 sources.append({'address':hex(addr),'path':str(path.relative_to(R)).replace('\\','/'),'sha256':sha(data),
  'bulk_source_sha256':meta['source_sha256'],'raw_batch_path':meta['batch_path'],'raw_batch_sha256':meta['batch_sha256'],
  'authority':'SAVED_UNREVIEWED_DECOMPILATION_WITH_BOUNDED_BYTE_CORROBORATION_ONLY'})
md=Cs(CS_ARCH_X86,CS_MODE_32)
verified_ranges={}
for addr in [0x825f70,0x825fa0,0x4e46d0,0x4e48a0,0x549980,0x61e4a0]:
 end=starts[bisect.bisect_right(starts,addr)];size=end-addr;raw=pe.read(addr,size)
 assert size<0x2000
 instructions=list(md.disasm(raw,addr));verified_ranges[addr]=instructions
 (D/f'{addr:x}-bounded.txt').write_bytes(('\n'.join(f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in instructions)+'\n').encode('utf-8'))
 sources.append({'kind':'BOUNDED_ORIGINAL_INSTRUCTIONS','address':hex(addr),'bytes':size,'sha256':sha(raw),'next_saved_function':hex(end)})
refs=[]
for s in pe.sections:
 if not s['flags']&0x20000000:continue
 for op in [0xe8,0xe9]:
  pos=s['raw'];end=pos+s['size']
  while True:
   pos=pe.data.find(bytes([op]),pos,end-4)
   if pos<0:break
   site=pe.va(pos);target=site+5+struct.unpack_from('<i',pe.data,pos+1)[0]
   if target in [0x825f70,0x825fa0]:
    parent=starts[bisect.bisect_right(starts,site)-1]
    match=next((i for i in verified_ranges.get(parent,[]) if i.address==site),None)
    valid=match is not None and match.mnemonic in ['call','jmp'] and match.op_str==hex(target)
    refs.append({'site':hex(site),'target':hex(target),'source_function':hex(parent),'kind':'call' if op==0xe8 else 'jmp','instruction_boundary_verified':valid})
   pos+=1
assert len(refs)==4 and all(r['instruction_boundary_verified'] for r in refs)
# Search saved text only. The generic 826280 map helper is not a skill-specific xref.
queries={}
for target in [0x825f70,0x825fa0,0x549980]:
 pattern=f'FUN_{target:08x}'
 result=subprocess.run(['rg','-l',pattern,str(F),'-g','*.c'],capture_output=True,text=True,encoding='utf-8',check=True)
 found=sorted(Path(x) for x in result.stdout.splitlines())
 queries[hex(target)]={'pattern':pattern,'matched_sources':[str(x.relative_to(R)).replace('\\','/') for x in found],
                       'callee_definition_included':True,'search_completed':True}
result={'schema':'tartaros-skill-cache-consumer-audit-v1','target_sha256':TARGET,
 'direct_refs':refs,'saved_text_queries':queries,
 'positive_findings':[
  {'id':'CACHE4-COST-ABI','source':'0x549980','claim':'The cache word+4 is zero-extended and passed in EAX to530530/5305C0/530650; activeID is ECX. Both query paths use+4, not+6.',
   'instruction_sites':['0x549af2','0x549afc','0x549afe','0x549b00','0x549b05','0x549b13','0x549b15','0x549b17','0x549b1c','0x549b2c','0x549b2e','0x549b30','0x549b69','0x549b77','0x549b80','0x549b8e','0x549b97','0x549ba7']},
  {'id':'CACHE6-MAX-BOOKKEEPING','source':'0x825fa0','claim':'The exact word+6 read826114 and write826123 implement MAX(existingScriptLevel,modifier+8); the initial record DWORD+4=0x10000 initializes word+6=1. This is a writer/bookkeeping read, not a presentation consumer.'},
  {'id':'QUERY-NO-PRESENTATION','source':'0x549980 ->0x54ae70','claim':'549980 checks resource affordability and54F270 availability and returns0/1 to its wrapper. No cache+6 action/script/motion or packet field is supplied in this bounded path.'}],
 'inline_cache_reader_scope':[
  {'source':'0x4704c0','use':'Caches word+4 as a byte skill level in UI cells; no identified cache+6 use.'},
  {'source':'0x5cd520','use':'Loads cache word+4 for cost getters, active IDs and UI vtable+1A4 updates; no identified cache+6 use.'},
  {'source':'0x617b70','use':'Tests cache word+4 nonzero to set editor availability flag+110; no identified cache+6 use.'},
  {'source':'0x61b0b0','use':'Iterates hero+1D4 map; forwards word+4 to61AED0 learned-skill UI; no identified cache+6 use.'},
  {'source':'0x61e4a0','use':'Forwards active DWORD0 and low byte+4 to UI vtable+19C; no identified cache+6 use.'}],
 'conclusion':'NO_NEW_ACTIVE_TO_MOTION_BRIDGE; remaining scriptLevel+6 presentation consumer remains unresolved.',
 'limitations':['Saved text and selected instruction ranges do not prove whole-program field-use absence or indirect-call closure.',
  'Generic map helper826280 callers include unrelated structures; not all are hero skill-cache readers.',
  'No official Server motion mapping, learned-level animation thresholds, new skill unlock, Client execution or semantic FULL-PASS follows from these findings.',
  'An earlier sequential full-folder Python filter was canceled; completed rg queries and explicit selected-source reads are the retained search boundary.']}
(D/'source-identities.json').write_bytes((json.dumps(sources,indent=2)+'\n').encode('utf-8'))
(D/'findings.json').write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
print(json.dumps({'sources':len(sources),'verified_direct_refs':len(refs),'query_matches':{k:len(v['matched_sources']) for k,v in queries.items()},'conclusion':result['conclusion']}))

# Small publication windows; full selected disassembly remains a local working artifact.
def publication_window(source,ranges):
 rows=[]
 for lo,hi in ranges:
  rows.append(f"# verified original instruction window {lo:#x}..{hi:#x}")
  for line in (D/source).read_text(encoding="utf-8").splitlines():
   try:addr=int(line.split(" ",1)[0],16)
   except ValueError:continue
   if lo<=addr<hi:rows.append(line)
 return "\n".join(rows)+"\n"
(D/"cache-cost-abi-windows.txt").write_bytes(publication_window("549980-bounded.txt",[(0x549ade,0x549b35),(0x549b51,0x549bb0),(0x549c03,0x549c51)]).encode("utf-8"))
(D/"cache-scriptlevel-max-windows.txt").write_bytes(publication_window("825fa0-bounded.txt",[(0x826000,0x826023),(0x82610d,0x826127)]).encode("utf-8"))
sections=[]
for ref in refs:
 addr=int(ref["site"],16);source=ref["source_function"][2:]+"-bounded.txt"
 sections.append(f"# {ref['source_function']} -> {ref['target']}; decoded from function entry before selecting this view")
 sections.append(publication_window(source,[(addr-18,addr+12)]))
(D/"direct-call-boundaries.txt").write_bytes(("\n".join(sections)+"\n").encode("utf-8"))
