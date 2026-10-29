"""Serialize the line-referenced manual claim and complete-block decisions."""
import pathlib,json,hashlib,collections
D=pathlib.Path(__file__).resolve().parent
A=json.loads((D/'source-codeblock-audit.json').read_text(encoding='utf-8'))
def claim(cid,lines,statement,decision,evidence,limits=None):
    return dict(id=cid,source_lines=lines,statement=statement,verdict=decision,evidence=evidence,limits=limits or [])
M={
53:[
claim('053-I1',[4,5],'KR原件SHA、PE.text VA401000/raw400，VA→raw限本節為減400C00。','PASS',['source-codeblock-audit.json:binary_sha256/sections']),
claim('053-C1',[11,11],'本.text內FB9004完整4-byte literal恰七次。','PASS',['source-codeblock-audit.json:literal_fb9004_positions'],['只枚舉byte pattern，不是alias或CFG全覆蓋。']),
claim('053-C2',[17,23],'七項raw/VA pair全相符；其所在有效指令分別為讀、直接DWORD清零、indexed byte清零。','PASS',['source-codeblock-audit.json:literal_fb9004_positions','cfg/00548730.json:548957','cfg/006d0750.json:6D080F→6D0875','cfg/006d1a70.json:6D1B00→6D1B02','cfg/006d4a30.json:6D4A93/6D4A9C,6D4B69/6D4B6B,6D4CAE','cfg/006d4ce0.json:6D4D93/6D4D98'],['VA54895A等是operand literal位置，非opcode起點。表中6D4CB0是ordinary indexed clear的operand；「特殊域相鄰」不能改稱特殊node writer。']),
claim('053-C3',[11,25],'七次literal盤點不排除非零writer，也不是完整CFG或runtime。','PASS_SCOPE_LIMIT',['The census matches only one4-byte literal; base+offset/alias instructions do not require this literal.','Source explicit limitation atline25']),
claim('053-C4',[268,268],'泛稱所有列出直接讀寫/call已確認。','NEEDS_SCOPE_CLARIFICATION',['source-codeblock-audit.json:sources[0].blocks[0]:lines32..33','README.md:053 presentation arbitration'],['首窗bad/錯位inc及明示尾端.byte不是native正向證據。原稿line25已提醒需正確邊界，故不將此視窗當新行為錯誤。']),
claim('053-L1',[269,280],'receiver實例、非零writer、Z/V/動畫/queue/cancel等仍未證，後續研究只是建議。','RETAINED_UNKNOWN_NOT_A_POSITIVE_NATIVE_CLAIM',['Original source lines269..280']),
],
55:[
claim('055-I1',[4,5],'同SHA KR及本節PE映射。','PASS',['source-codeblock-audit.json:binary_sha256/sections']),
claim('055-C1',[11,11],'特殊域使用FDF630相關樹，查找結果payload+10以byte讀取/清零。','PASS',['cfg/006d4a30.json:6D4C23..6D4C7C','cfg/006d4ce0.json:6D4D05..6D4D5D','cfg/0082ef00.json'],['有效容器與helper正常返回；不推型別符號、插入非零來源或任意ID安全。']),
claim('055-C2',[11,11],'6D4C7C只在result!=FDF634 sentinel時寫byte0。','PASS',['cfg/006d4a30.json:6D4C6C call82EF00;6D4C71 load;6D4C74 compare;6D4C7A je6D4CB5;6D4C7C store0']),
claim('055-C3',[11,11],'特殊樹node+10與普通域FB9004+index的儲存/讀取介面不同，寫0不能推導非零來源。','PASS',['cfg/006d4ce0.json:unsigned special interval vs guardedordinary index<=39; node+10 vs FB9004+ESI','cfg/006d4a30.json:6D4C7C vs6D4CAE'],['這不是對任意非特殊ESI的無alias/安全性證明；clear路徑無<=39 guard，不能由reader搬用。']),
claim('055-C4',[244,244],'泛稱列出的直接讀寫/call指令已確認。','NEEDS_SCOPE_CLARIFICATION',['source-codeblock-audit.json:sources[1].blocks[0]:source18..26','source-codeblock-audit.json:sources[1].blocks[3]:source194'],['視窗頭錯位與尾端明示截斷需分開。LOCK PUSH6D4D40來自前一LEA immediate的F0，不是本reader路徑指令。不能把整篇當全文FULL_PASS。']),
claim('055-L1',[245,256],'精確類別/receiver、非零writer及玩家動作仍未知；不替換歷史結論。','RETAINED_UNKNOWN_NOT_A_POSITIVE_NATIVE_CLAIM',['Original source lines245..256']),
],
56:[
claim('056-I1',[4,5],'同SHA KR及本節PE映射。','PASS',['source-codeblock-audit.json:binary_sha256/sections']),
claim('056-C1',[11,15],'59624E及59643F是直接CALL6D4CE0，完整.text E8字節候選僅此兩處。','PASS',['source-codeblock-audit.json:direct_E8_candidates_to_6d4ce0','cfg/005961c0.json:59624E/59643F'],['完整candidate census僅對E8 rel32編碼，不涵蓋indirect/tail。兩處本身另外由entry5961C0可達CFG確認有效邊界。']),
claim('056-C2',[11,11],'該路徑消費鍵狀態並有vtable+EC/F0周邊多態呼叫；receiver實例/玩家攻擊語意尚不確定。','PASS',['cfg/005961c0.json:596245 ESI=EDI;59624E reader;596267 phase1;5962BC phase3;596275 EC;5962CE F0;596411 ESI=node+8;59643F reader;596456 EC;5964B5 F0','cfg/006d4ce0.json:ESI indexed/tree byte return'],['只證register/byte/virtual offset；不證具體override或attack/cancel。']),
claim('056-C3',[278,278],'泛稱所列直接讀寫/call指令皆已確認。','NEEDS_SCOPE_CLARIFICATION',['source-codeblock-audit.json:sources[2].blocks[2]:source209..220'],['第三窗596430..451的線性解碼含假CALL596441→F8DC6459；與同篇第二窗正確59643F CALL6D4CE0重疊，不能同時當成此rooted CFG的native指令。']),
claim('056-L1',[279,290],'精確receiver、writer、動作/queue/cancel與backend仍未知。','RETAINED_UNKNOWN_NOT_A_POSITIVE_NATIVE_CLAIM',['Original source lines279..290']),
]}
records=[]
for s in A['sources']:
    n=int(s['source'].split('-T10-')[1].split('-')[0])
    block_decisions=[]
    for b in s['blocks']:
        head=b['classification_counts'].get('MISALIGNED_WINDOW_HEAD_LINEAR_DECODE',0)+b['classification_counts'].get('EXPLICIT_BAD_DECODER_OUTPUT_AT_MISALIGNED_HEAD',0)
        tail=b['classification_counts'].get('EXPLICIT_END_TRUNCATION_FRAGMENT',0)
        assert all(r.get('operand_text_equivalence',True) for r in b['rows'])
        block_decisions.append(dict(index=b['index'],source_lines=b['source_lines'],source_block_sha256=b['source_block_sha256'],full_block_examined=True,all_quoted_bytes_match=True,instruction_rows_complete=True,native_operand_equivalence_all_canonical_rows=True,status='SCOPE_ANNOTATION_REQUIRED' if head else 'PASS_WITH_EXPLICIT_RAW_TAIL_EXCLUDED' if tail else 'PASS_NATIVE_INSTRUCTION_DECODE',reason='Arbitrary start yields linear misdecode until true resynchronization; excluded from native instruction proof.' if head else 'End .byte/prefix and subsequent decoded fragments are explicit raw truncation, not affirmative native instructions.' if tail else 'All rows match rooted native boundaries and x86 decoded operands, subject to stated path conditions.',counts=b['classification_counts']))
    records.append(dict(source=s['source'],source_sha256=s['sha256'],source_git_blob_sha=s['git_blob_sha'],source_lines=s['line_count'],review_examination_complete=True,all_substantive_affirmative_claims_and_blocks_enumerated=True,source_whole_document_certified=False,document_verdict='PARTIAL',reason='Central native facts pass. Broad instruction-confirmation wording has not explicitly excluded misaligned window-head decoder artifacts; preserve original source version, add scope annotation/corrected appendix before whole-document signoff.',native_core_refuted=False,new_gameplay_behavior_refutation=False,claims=M[n],codeblocks=block_decisions,pending_for_whole_document_pass=['Keep source version; publish an annotated correction declaring exactly which window-head rows and explicit tail fragments are not native instruction evidence.','Replace or supplement the misaligned window with rooted corrected ASM, keep original artifact for provenance, and bind correction blob/SHA.','Revalidate broad confirmed-instruction wording and all affected source claims against correction; dynamic/runtime unknowns need not be solved for bounded document signoff.']))
counts=collections.Counter(r['classification'] for s in A['sources'] for b in s['blocks'] for r in b['rows'])
decision=dict(schema='t01-three-source-full-examination-v1',base_commit=A['base_commit'],target_sha256=A['binary_sha256'],reviewer='Codex T01 / review_t10',date='2026-10-29 Asia/Taipei',source_count=3,codeblocks_examined=14,quoted_rows_examined=sum(counts.values()),row_classifications=dict(counts),whole_source_full_pass_count=0,partial_sources=3,new_native_core_failures=0,all_pending_98_sources_completed=False,sources=records)
(D/'decisions.json').write_text(json.dumps(decision,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({k:v for k,v in decision.items() if k!='sources'},ensure_ascii=False))
