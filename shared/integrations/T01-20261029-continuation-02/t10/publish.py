import pathlib,json,hashlib
D=pathlib.Path(__file__).resolve().parent
A=json.loads((D/'source-codeblock-audit.json').read_text(encoding='utf-8'))
V=json.loads((D/'decisions.json').read_text(encoding='utf-8'))
by_num={int(s['source'].split('-T10-')[1].split('-')[0]):s for s in A['sources']}
returns=[]
for n,span,summary,root,correct in [
    (55,[18,26],'第一視窗起點6D4BB0在6D4BAC指令的immediate內，至6D4BC2才重新對齊；第四視窗6D4D40是6D4D3E LEA的immediate，lock push不是reader正常路徑指令。','6D4A30、6D4CE0入口CFG','6D4BAC c7 45 fc 04 00 00 00 (mov[ebp-4],4);6D4BB3 e8 98 bb ff ff (call6D0750);6D4BBD e8 58 d7 1b 00 (call89231A);6D4D3E 8d 4d f0 (lea ecx,[ebp-10h]);6D4D41 51 (push ecx)'),
    (56,[209,220],'第三視窗596430落在59642E JMP的rel32內，其假CALL596441→F8DC6459跨過真正59643F CALL的immediate和596444 CMP；596452起才重新對齊。','5961C0入口CFG','59642E e9 7a 01 00 00 (jmp5965AD);596433 68 34 20 bf 00;596438 e8 f3 76 2e 00 (call87DB30);59643D 32 db (xor bl,bl);59643F e8 9c e8 13 00 (call6D4CE0);596444 83 f8 01 (cmp eax,1)')
]:
    s=by_num[n]
    returns.append(dict(id=f'T01-RETURN-T10-{n:03d}-EVIDENCE-001',task='T10',state='NEEDS_QUALIFICATION',source=s['source'],source_sha256=s['sha256'],source_git_blob_sha=s['git_blob_sha'],source_lines=span,additional_scope_claim_line=244 if n==55 else 278,issue=summary,canonical_roots=root,canonical_evidence=correct,review='shared/integrations/T01-20261029-continuation-02/t10/README.md',scope='證據呈現界線修正；不撤銷特殊樹clear/兩個reader callsite的核心已核對事實，不當作新遊玩行為反證。',required_change='保留原稿與SHA；提供勘誤／標註版，明列錯位視窗頭不屬native instruction證據；分開明示.byte尾端截斷和續行；替泛稱「列出的讀寫/call已確認」限定有效區段。可附本批rooted canonical excerpt，不能更換原來源SHA。',revalidation='新勘誤blob/SHA、所有受影響碼塊與泛稱確認範圍逐項核對；既有核心條件與unknown維持。',not_a_new_native_behavior_failure=True))
(D/'return-proposals.json').write_text(json.dumps(returns,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
lines=['# T10-053／055／056 全碼塊與原生主張複驗','',
'2026-10-29 Asia/Taipei；審核者 Codex T01 / review_t10。基準 `fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5`。僅讀原件，不執行／附加、目標API或修改遊戲。','',
'三篇均完成此次逐行檢查及決議，維持 **PARTIAL，全文 FULL-PASS 0**。三篇主題的有限原生事實仍有支持；不是發現三篇新的原生行為錯誤。剩餘是原稿證據附錄與泛稱「列出的直接讀寫／call 已確認」的適用界線，不是要求先解完 Z/V 或整體遊戲才可驗收。','',
'原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。獨立讀取 PE sections，`.text` VA `401000`／raw `400`。','',
'## 覆蓋與防止驗收器偽陽性','',
'- **14 個 ASM 碼塊，648 行 quoted bytes** 全核對原件；602 行為對齊、操作數一致的原生指令／padding編碼；22 行為視窗尾端明示 `.byte`／segment-prefix 截斷及其後續殘片；24 行位於錯位視窗頭（其中1行已明標 `(bad)`，23行為錯位線性解碼的指令呈現）。','- 602 行另比較 mnemonic/operands；五個 `push 0xffffffff` 與 Capstone `push -1` 皆為同一 `6A FF` 的 32-bit sign-extension 顯示，已排除偽陽性。','- `.byte`、`(bad)`、續行／尾端殘片不當成新 native 行為反證。原始 byte 片段正確，不表示錯位解碼可以當作正常路徑指令。','- 原件 rooted CFG 來自九個已指定入口；cached Ghidra 的 source/index hashes 已核對。`6D08C0` 是 `6D0750` 靜態傳入的callback指標，只用來校正附錄跨入下一函式的截斷，不假造cache entry。','- 每個碼塊、每行bytes／canonical指令／分類／來源行號在 [source-codeblock-audit.json](source-codeblock-audit.json)；非code每項肯定主張、unknown和完整覆蓋決議在 [decisions.json](decisions.json)。','',
'## 來源版本','',
'| 原稿 | SHA256 | Git blob SHA | 本批決議 |','|---|---|---|---|']
for n,s in by_num.items():lines.append(f'| T10-{n:03d} | `{s["sha256"]}` | `{s["git_blob_sha"]}` | PARTIAL；核心事實支持，附錄界線需註明 |')
lines += ['', '## 全部碼塊','', '| 原稿／塊 | 原稿行號 | 對齊行 | 尾端明示截斷 | 起點錯位 | 決議 |','|---|---|---:|---:|---:|---|']
for s in A['sources']:
    n=int(s['source'].split('-T10-')[1].split('-')[0])
    for b in s['blocks']:
        c=b['classification_counts'];head=c.get('MISALIGNED_WINDOW_HEAD_LINEAR_DECODE',0)+c.get('EXPLICIT_BAD_DECODER_OUTPUT_AT_MISALIGNED_HEAD',0);tail=c.get('EXPLICIT_END_TRUNCATION_FRAGMENT',0)
        lines.append(f'| {n:03d}／{b["index"]} | {b["source_lines"][0]}–{b["source_lines"][1]} | {c.get("CANONICAL_NATIVE_INSTRUCTION",0)} | {tail} | {head} | '+('需排除錯位起點指令' if head else '有效指令通過；尾端僅作raw片段' if tail else '有效指令解碼通過')+' |')
lines += ['', '## 逐篇核心與附錄裁決','',
'**053**：line11及17–23的七筆 literal、raw/VA、reader／zero-store 分類相符。`548950..548956` 的 `(bad)`／錯位 inc 不證明有該 inc 路徑，真正 `54894A` 長指令結束於 `548952`，後接 cmp/jump，`548957` reader 是有效邊界。原稿 line25 已明示需從正確邊界解碼，因此不把首窗當作原生語意反證，也不新建 FAILED 通知。建議只在後續勘誤把這兩行明列 diagnostic，並讓line268的泛稱確認不涵蓋它們。','',
'**055**：line11的 `FDF630` tree、sentinel `FDF634`、命中才寫 `node+10` byte0 以及普通reader介面差異均通過。第一窗 source18–26（`6D4BB0..6D4BC1`）起點錯位；第四窗 source194的 `6D4D40 lock push` 來自前一LEA的F0 immediate。它們不是尾端 `.byte` 截斷，而是不同的頭部錯位現象。第二／第三窗已同時保留正確路徑，不能依最新視窗覆蓋。line244的泛稱確認需限定有效範圍。','',
'**056**：line11/15的兩個 valid direct calls `59624E`、`59643F` 及附近 EC/F0 多態處理通過。第三窗 source209–220 的頭部錯位解碼含 `596441 call F8DC6459`，與本篇第二窗正確 `59643F call6D4CE0` 互相重疊；rooted CFG 證明後者是此路徑指令。這不是改變reader核心結論，應在line278的泛稱確認中排除錯位頭部。','',
'## 具體限定修正提案','',
'[return-proposals.json](return-proposals.json) 僅有055／056兩項 `NEEDS_QUALIFICATION` 建議，供整合者決定如何登記T10 README專區；未寫其他Task、原稿或前批資料。固定ID含EVIDENCE，明示不撤銷核心已核對事實。053有明示boundary caveat，沒有把它新增為FAILED。','',
'修正可由T01自有勘誤先提供正確片段；要簽核原稿全文，仍須將勘誤／標註版及其新blob/SHA與原稿連結並重驗確認範圍。不能把本次結果倒寫成原始版本全文通過。','',
'## 重跑','',
'在repo根目錄，提供指定SHA原件與Capstone5.0.6（例為本機既有vendor）後：','', '```powershell',
"$env:T01_TARGET='E:/Tartaros/workspace/Tartaros.bin'", "$env:T01_CAPSTONE_ROOT='E:/Tartaros/workspace/t01-work-20261029/vendor'",'python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/review.py','python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/decide.py','python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/publish.py','```','',
'重現腳本使用前批已提交 `T01-20261029-semantic-review/support/audit.py`，不依賴私有未提交helper；cached原證據以本機anal-multi快取唯讀核SHA。未攜帶原BIN或Capstone執行庫，不宣稱沒有原件也能重做語意驗證。此批不代表其餘95篇、T10動作鏈或遊玩已驗收。']
(D/'README.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
rows=[]
for p in sorted(D.rglob('*')):
    if p.is_file() and p.name not in ['files-manifest.json','validation.json']:
        b=p.read_bytes();rows.append(dict(path=p.relative_to(D).as_posix(),bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
(D/'files-manifest.json').write_text(json.dumps(dict(files=rows,total_bytes=sum(x['bytes'] for x in rows)),ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
assert len(A['sources'])==3 and sum(len(s['blocks']) for s in A['sources'])==14
assert sum(len(b['rows']) for s in A['sources'] for b in s['blocks'])==648
assert all(s['all_codeblocks_examined'] for s in A['sources'])
assert all(not s['source_whole_document_certified'] for s in V['sources'])
assert all(r.get('operand_text_equivalence',True) for s in A['sources'] for b in s['blocks'] for r in b['rows'])
(D/'validation.json').write_text(json.dumps(dict(ok=True,source_count=3,source_full_pass=0,source_partial=3,codeblocks=14,quoted_rows=648,canonical_native_rows=602,explicit_end_fragments_not_native_claims=22,misaligned_head_instruction_renderings=23,explicit_bad_decoder_rows_not_native_claims=1,misaligned_head_total=24,operand_mismatches_after_proven_display_aliases=0,source_versions_bound=True,new_native_core_failures=0,source_scope_not_silently_promoted=True),ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(dict(ok=True,files=len(rows),bytes=sum(x['bytes'] for x in rows),return_proposals=len(returns)),ensure_ascii=False))
