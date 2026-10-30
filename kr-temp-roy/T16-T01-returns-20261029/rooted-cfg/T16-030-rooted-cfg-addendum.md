# T16-030 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x00531D00` → source problematic `0x005321A0`

- Root accessible native instructions: **549**; known conditional/direct/indexed branch edges: **63**; `call` instruction sites: **69**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0053219F: e84c0e0000                     call 0x532ff0`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0053218E: 81c6a81efe00         add esi,0xfe1ea8
0x00532194: 50                   push eax
0x00532195: 8bce                 mov ecx,esi
0x00532197: c68424ec0100000b     mov BYTE PTR [esp+0x1ec],0xb
0x0053219F: e84c0e0000           call 0x532ff0
0x005321A4: 50                   push eax
0x005321A5: 56                   push esi
0x005321A6: 8d7c2440             lea edi,[esp+0x40]
0x005321AA: e8c10b0000           call 0x532d70
0x005321AF: 8db42448010000       lea esi,[esp+0x148]
0x005321B6: e815040000           call 0x5325d0
0x005321BB: 8db4248c010000       lea esi,[esp+0x18c]
0x005321C2: e809040000           call 0x5325d0
0x005321C7: 837c245408           cmp DWORD PTR [esp+0x54],0x8
0x005321CC: 720d                 jb 0x5321db
0x005321CE: 8b4c2440             mov ecx,DWORD PTR [esp+0x40]
0x005321D2: 51                   push ecx
0x005321D3: e834f03500           call 0x89120c
0x005321D8: 83c404               add esp,0x4
0x005321DB: 33d2                 xor edx,edx
0x005321DD: 83bc24a800000008     cmp DWORD PTR [esp+0xa8],0x8
0x005321E5: c744245407000000     mov DWORD PTR [esp+0x54],0x7
0x005321ED: 895c2450             mov DWORD PTR [esp+0x50],ebx
0x005321F1: 6689542440           mov WORD PTR [esp+0x40],dx
0x005321F6: 7210                 jb 0x532208
0x005321F8: 8b842494000000       mov eax,DWORD PTR [esp+0x94]
0x005321FF: 50                   push eax
0x00532200: e807f03500           call 0x89120c
0x00532205: 83c404               add esp,0x4
0x00532208: 889c24e8010000       mov BYTE PTR [esp+0x1e8],bl
0x0053220F: 83bc24c400000010     cmp DWORD PTR [esp+0xc4],0x10
0x00532217: 7210                 jb 0x532229
0x00532219: 8b8c24b0000000       mov ecx,DWORD PTR [esp+0xb0]
0x00532220: 51                   push ecx
0x00532221: e8e6ef3500           call 0x89120c
0x00532226: 83c404               add esp,0x4
0x00532229: 8b442410             mov eax,DWORD PTR [esp+0x10]
0x0053222D: bf7cf1c000           mov edi,0xc0f17c
0x00532232: e889c11f00           call 0x72e3c0
0x00532237: 89442410             mov DWORD PTR [esp+0x10],eax
0x0053223B: 3bc3                 cmp eax,ebx
0x0053223D: 0f85bffbffff         jne 0x531e02
0x00532243: 8b44241c             mov eax,DWORD PTR [esp+0x1c]
0x00532247: 68a4f1c000           push 0xc0f1a4
0x0053224C: e88fc01f00           call 0x72e2e0
0x00532251: 3bc3                 cmp eax,ebx
0x00532253: 0f84f7020000         je 0x532550
0x00532259: bf7cf1c000           mov edi,0xc0f17c
0x0053225E: e8fdc01f00           call 0x72e360
0x00532263: 89442410             mov DWORD PTR [esp+0x10],eax
0x00532267: 3bc3                 cmp eax,ebx
```

**可達 call sites（此局部區間）**

- `0x0053219F call 0x532ff0`
- `0x005321AA call 0x532d70`
- `0x005321B6 call 0x5325d0`
- `0x005321C2 call 0x5325d0`
- `0x005321D3 call 0x89120c`
- `0x00532200 call 0x89120c`
- `0x00532221 call 0x89120c`
- `0x00532232 call 0x72e3c0`
- `0x0053224C call 0x72e2e0`
- `0x0053225E call 0x72e360`

**可達分支（此局部區間）**

- `0x005321CC jb 0x5321db`
- `0x005321F6 jb 0x532208`
- `0x00532217 jb 0x532229`
- `0x0053223D jne 0x531e02`
- `0x00532253 je 0x532550`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
