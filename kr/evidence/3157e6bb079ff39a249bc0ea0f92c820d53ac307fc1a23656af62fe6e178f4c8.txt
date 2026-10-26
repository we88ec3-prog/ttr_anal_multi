"""Validate retained REA/Ghidra evidence against original bytes; no target execution."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib, json, platform, re, struct, sys
ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
EV = HERE/'evidence'
sys.path.insert(0,str(ROOT/'anal/python_deps'))
import capstone
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
load=lambda p:json.loads(p.read_text(encoding='utf-8-sig'))
def save(p,x):p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
BASE='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
b=(ROOT/'Tartaros.bin').read_bytes();assert sha(b)==BASE
p=EV/'native-4df510.json';raw=p.read_bytes();record=load(p)
assert record['subject']['digest']['sha256']==BASE
d=record['raw_result']['value'];assert d['procedure']['address']=='0x4df510'
pe=struct.unpack_from('<I',b,0x3c)[0];opt=pe+24
base=struct.unpack_from('<I',b,opt+28)[0];st=opt+struct.unpack_from('<H',b,pe+20)[0]
sections=[struct.unpack_from('<8sIIIIIIHHI',b,st+i*40) for i in range(struct.unpack_from('<H',b,pe+6)[0])]
def off(va):
    rva=va-base
    for s in sections:
        if s[2]<=rva<s[2]+s[3]:return s[4]+rva-s[2]
    raise AssertionError(hex(va))
start=0x4df510;end=0x4dfa9d;data=b[off(start):off(start)+end-start]
ins=list(Cs(CS_ARCH_X86,CS_MODE_32).disasm(data,start))
assert sum(x.size for x in ins)==len(data)
by={x.address:x for x in ins}
assert set(by)=={int(x.split(':')[0],16) for x in d['assembly']}
assert by[0x4df53e].mnemonic=='cmp' and by[0x4df541].mnemonic=='je'
assert by[0x4df541].op_str=='0x4dfa13'
assert by[0x4df54e].mnemonic=='mov' and by[0x4df54e].op_str=='dword ptr [eax + 0x48], esi'
edges={}
for x in ins:
    nxt=x.address+x.size
    if x.mnemonic.startswith('ret'):dest=[]
    elif x.mnemonic=='jmp':dest=[int(x.op_str,16)]
    elif x.mnemonic.startswith('j'):dest=[int(x.op_str,16),nxt]
    else:dest=[nxt] if nxt<end else []
    assert all(y in by for y in dest),(hex(x.address),dest)
    edges[x.address]=dest
def reachable(entry, blocked=()):
    seen=set();todo=[entry]
    while todo:
        x=todo.pop()
        if x in seen or x in blocked:continue
        seen.add(x);todo.extend(edges[x])
    return seen
same=reachable(0x4dfa13)
loadsites=[0x4df58d,0x4df62a,0x4df787,0x4df9b4,0x4df9c7]
assert not set(loadsites)&same
assert {x for x in same if by[x].mnemonic.startswith('ret')}=={0x4dfa9a}
assert not (set(loadsites)&reachable(0x4df547,blocked={0x4df54e}))
calls=[{'va':hex(x),'target':by[x].op_str} for x in sorted(same) if by[x].mnemonic=='call']
assert {x['target'] for x in calls}=={'0x6d8e50','0x89231a','0x6d9430','0x6d9580'}
selected=[]
for x in ins:
    if x.address in same or x.address in [0x4df538,0x4df53b,0x4df53e,0x4df541,0x4df54e,*loadsites,0x4df775,0x4df777]:
        selected.append({'va':hex(x.address),'file_offset':off(x.address),'bytes':x.bytes.hex(),'instruction':x.mnemonic+' '+x.op_str})
now=datetime.now(timezone.utc).isoformat()
result={'id':'T06-roy-map-repeat-branch-v1','status':'待整合','at':now,'source_sha256':BASE,'module':'Tartaros.bin',
 'address_range':['0x4df510..0x4dfa9c','same-selector entry0x4dfa13','cache write0x4df54e'],
 'tool_version':{'primary':'retained REA6.5.0/Ghidra12.1.4','python':platform.python_version(),'capstone':capstone.__version__},
 'primary_evidence':{'path':'evidence/native-4df510.json','sha256':sha(raw),'evidence_id':record['evidence_id']},
 'verification':{'whole_body_bytes':len(data),'body_sha256':sha(data),'instruction_addresses_equal_retained_Ghidra':True,'same_selector_nodes':len(same),'same_selector_calls':calls,'same_selector_return':'0x4dfa9a','skipped_local_calls':[hex(x) for x in loadsites],'cache_write_dominates_loadsites_in_normal_local_CFG':True},
 'instructions':selected,
 'observed':['DWORD comparison at4DF53E jumps to4DFA13 when cached selector matches.',
             'Same-selector local path cannot reach the three4F7DF0 resource lookup calls, model call7C1E00 or bound call4DF1A0 in this function.',
             'Changed-selector path writes cache+48 at4DF54E before the first lookup; write dominates these local loadsites in normal intraprocedural CFG.'],
 'inference':['Repeated0012 with the same selector cannot be relied on to traverse these explicit model/BOUND reload calls in4DF510.',
              'A packet-only transition/retry design must account for cached selector and scene lifecycle; sending duplicates is not an independently proven reload mechanism.',
              'Cache assignment is not proof of successful loading; no rollback/failure or readiness policy is derived.'],
 'conditions':['Exact source SHA; original target bytes; same-selector comparison assumes caller passes the expected map-manager object; calls treated as normally returning.'],
 'limits':['Callees6D9430/6D9580 side effects not reanalyzed; no claim that all possible indirect resource activity is absent.',
           'Exception edges, callback reentrancy, external writes to cache and subsequent caller behavior are outside this local graph.',
           'T07 reset preceding0012 remains a referenced dependency, not newly reanalyzed.',
           'Town1/2 mapping, successful load, actors/spawn and runtime playability remain unverified; target not run.']}
save(EV/'map-repeat-branch-v1.json',result)
with (HERE/'findings.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(result,ensure_ascii=False)+'\n')
with (HERE/'PACKET-RESTORATION-CONTRACT.md').open('a',encoding='utf-8') as f:
    f.write('\n## 重送相同 Map selector 的限制（待整合）\n\n'
      '原始4DF510在4DF53E比較manager+48的DWORD；相同時跳4DFA13，局部正常流程不經MAP/BOUND查詢、7C1E00模型呼叫或4DF1A0碰撞呼叫。不同時4DF54E先更新快取，再查資源。故不能把重送相同0012視為已證的完整重新載入手段，也不能把快取值已更新視為載入成功。\n\n'
      '原始bytes、完整函式指令位址比對、same-ID可達指令與calls見evidence/map-repeat-branch-v1.json。此結論只限函式內顯式路徑，不排除被呼叫helper的間接作用、例外或caller行為；未觀察到runtime失敗或重試。T07 scene/reset順序仍待其主責證據。\n')
c=load(HERE/'changes.json');c['pending'].append('map-repeat-branch-v1.json and packet-contract same-selector note: exact-byte/local-CFG verification pending bounded integration; not full retry or playability acceptance');c['updated_at']=now;save(HERE/'changes.json',c)
pr=load(HERE/'progress.json');pr.update(updated_at=now,active_tool='None; original-byte/local-CFG check complete',running_jobs=[],next_action='Check formal integration acceptance for bounded same-selector path finding; retain T07 lifecycle dependency. Seek own-scope unresolved resource/name resolver evidence only when it can narrow two-town loading, no repeated producer or foreign controller analysis.');pr['last_native_query']={'review':'evidence/map-repeat-branch-v1.json','saved':True};save(HERE/'progress.json',pr)
with (HERE/'CHECKPOINT.md').open('a',encoding='utf-8') as f:
    f.write('\n## 同Map重送分支核對 '+now+'\n前goal turn為progress（跨任務初始化依賴已落檔）。本輪重新核對原BIN SHA、retained REA4DF510完整1421bytes及Ghidra指令位址集合，獨立CFG證明同selector分支不經函式內顯式MAP/BOUND/model載入呼叫；changed分支先寫cache+48。evidence/map-repeat-branch-v1.json已保存原始指令bytes／可達calls與限制，PACKET-RESTORATION-CONTRACT.md已追加待整合註記。\n這不是「同ID完全無作用」或「失敗後一定無法重試」結論，helper間接作用與例外未展開。兩村正式配對／spawn／T07順序／runtime仍未完成。原件唯讀，未啟動或附加。\n最後工具為Python原始bytes/CFG獨立驗證，成功並已保存；無執行中工具。新項目待整合，正式168artifact/13claim/1correction不變。下一次先檢查有界same-selector發現可否按T06既有驗收增量整合，再找能縮小兩村載入缺口的own-scope資源resolver依據；不重查已排除config/story producer，不展開foreign scene核心。\n')
print(json.dumps({'status':'pass','body_bytes':len(data),'same_selector_nodes':len(same),'same_selector_calls':calls,'evidence':'map-repeat-branch-v1.json'}))
