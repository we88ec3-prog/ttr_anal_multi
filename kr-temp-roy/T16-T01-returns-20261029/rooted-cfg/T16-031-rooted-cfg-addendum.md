# T16-031 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x004A88E0` → source problematic `0x004A89A0`

- Root accessible native instructions: **77**; known conditional/direct/indexed branch edges: **0**; `call` instruction sites: **33**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004A899E: e85d2e0000                     call 0x4ab800`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004A898B: 50                   push eax
0x004A898C: e88f2c0000           call 0x4ab620
0x004A8991: 50                   push eax
0x004A8992: e8292d0000           call 0x4ab6c0
0x004A8997: 50                   push eax
0x004A8998: e8c32d0000           call 0x4ab760
0x004A899D: 50                   push eax
0x004A899E: e85d2e0000           call 0x4ab800
0x004A89A3: 50                   push eax
0x004A89A4: e8f72e0000           call 0x4ab8a0
0x004A89A9: 50                   push eax
0x004A89AA: e8912f0000           call 0x4ab940
0x004A89AF: 686468c000           push 0xc06864
0x004A89B4: 8bce                 mov ecx,esi
0x004A89B6: e895c02400           call 0x6f4a50
0x004A89BB: 8be5                 mov esp,ebp
0x004A89BD: 5d                   pop ebp
0x004A89BE: c3                   ret 
```

**可達 call sites（此局部區間）**

- `0x004A898C call 0x4ab620`
- `0x004A8992 call 0x4ab6c0`
- `0x004A8998 call 0x4ab760`
- `0x004A899E call 0x4ab800`
- `0x004A89A4 call 0x4ab8a0`
- `0x004A89AA call 0x4ab940`
- `0x004A89B6 call 0x6f4a50`

**可達分支（此局部區間）**

- 無

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。