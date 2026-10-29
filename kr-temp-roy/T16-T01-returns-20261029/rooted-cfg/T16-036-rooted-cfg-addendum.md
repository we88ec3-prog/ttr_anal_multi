# T16-036 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x00531D00` → source problematic `0x00531E00`

- Root accessible native instructions: **549**; known conditional/direct/indexed branch edges: **63**; `call` instruction sites: **69**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `00531DFC: 0f8441040000                   je 0x532243`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x00531DEC: bf7cf1c000           mov edi,0xc0f17c
0x00531DF1: e86ac51f00           call 0x72e360
0x00531DF6: 89442410             mov DWORD PTR [esp+0x10],eax
0x00531DFA: 3bc3                 cmp eax,ebx
0x00531DFC: 0f8441040000         je 0x532243
0x00531E02: bf0f000000           mov edi,0xf
0x00531E07: 89bc24c4000000       mov DWORD PTR [esp+0xc4],edi
0x00531E0E: 899c24c0000000       mov DWORD PTR [esp+0xc0],ebx
0x00531E15: 889c24b0000000       mov BYTE PTR [esp+0xb0],bl
0x00531E1C: c68424e801000001     mov BYTE PTR [esp+0x1e8],0x1
0x00531E24: 6a04                 push 0x4
0x00531E26: 68f0d5c000           push 0xc0d5f0
0x00531E2B: 8d8c249c000000       lea ecx,[esp+0x9c]
0x00531E32: 89bc24b0000000       mov DWORD PTR [esp+0xb0],edi
0x00531E39: 899c24ac000000       mov DWORD PTR [esp+0xac],ebx
0x00531E40: 889c249c000000       mov BYTE PTR [esp+0x9c],bl
0x00531E47: e8240cedff           call 0x402a70
0x00531E4C: 8b4c2410             mov ecx,DWORD PTR [esp+0x10]
0x00531E50: 687523bf00           push 0xbf2375
0x00531E55: 8d842498000000       lea eax,[esp+0x98]
0x00531E5C: 8d742460             lea esi,[esp+0x60]
0x00531E60: c68424ec01000002     mov BYTE PTR [esp+0x1ec],0x2
0x00531E68: e883ce1f00           call 0x72ecf0
0x00531E6D: 50                   push eax
0x00531E6E: 8d8c24b4000000       lea ecx,[esp+0xb4]
0x00531E75: c68424ec01000003     mov BYTE PTR [esp+0x1ec],0x3
0x00531E7D: e82e0dedff           call 0x402bb0
0x00531E82: be10000000           mov esi,0x10
0x00531E87: 39742470             cmp DWORD PTR [esp+0x70],esi
0x00531E8B: 720d                 jb 0x531e9a
0x00531E8D: 8b44245c             mov eax,DWORD PTR [esp+0x5c]
0x00531E91: 50                   push eax
0x00531E92: e875f33500           call 0x89120c
0x00531E97: 83c404               add esp,0x4
0x00531E9A: c68424e801000001     mov BYTE PTR [esp+0x1e8],0x1
0x00531EA2: 897c2470             mov DWORD PTR [esp+0x70],edi
0x00531EA6: 895c246c             mov DWORD PTR [esp+0x6c],ebx
0x00531EAA: 885c245c             mov BYTE PTR [esp+0x5c],bl
0x00531EAE: 39b424a8000000       cmp DWORD PTR [esp+0xa8],esi
0x00531EB5: 7210                 jb 0x531ec7
0x00531EB7: 8b8c2494000000       mov ecx,DWORD PTR [esp+0x94]
0x00531EBE: 51                   push ecx
0x00531EBF: e848f33500           call 0x89120c
0x00531EC4: 83c404               add esp,0x4
0x00531EC7: 8b742410             mov esi,DWORD PTR [esp+0x10]
```

**可達 call sites（此局部區間）**

- `0x00531DF1 call 0x72e360`
- `0x00531E47 call 0x402a70`
- `0x00531E68 call 0x72ecf0`
- `0x00531E7D call 0x402bb0`
- `0x00531E92 call 0x89120c`
- `0x00531EBF call 0x89120c`

**可達分支（此局部區間）**

- `0x00531DFC je 0x532243`
- `0x00531E8B jb 0x531e9a`
- `0x00531EB5 jb 0x531ec7`

### Root `0x00531D00` → source problematic `0x005321E0`

- Root accessible native instructions: **549**; known conditional/direct/indexed branch edges: **63**; `call` instruction sites: **69**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `005321DD: 83bc24a800000008               cmp DWORD PTR [esp+0xa8],0x8`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
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
0x00532269: 0f84e1020000         je 0x532550
0x0053226F: 90                   nop 
0x00532270: 8b7c2410             mov edi,DWORD PTR [esp+0x10]
0x00532274: 83c744               add edi,0x44
0x00532277: 68b0f1c000           push 0xc0f1b0
0x0053227C: e81fde1f00           call 0x7300a0
0x00532281: 3bc3                 cmp eax,ebx
0x00532283: 741e                 je 0x5322a3
0x00532285: 83c030               add eax,0x30
0x00532288: 83781410             cmp DWORD PTR [eax+0x14],0x10
0x0053228C: 7202                 jb 0x532290
0x0053228E: 8b00                 mov eax,DWORD PTR [eax]
0x00532290: 3bc3                 cmp eax,ebx
0x00532292: 740f                 je 0x5322a3
0x00532294: 50                   push eax
0x00532295: e81af53500           call 0x8917b4
0x0053229A: 83c404               add esp,0x4
0x0053229D: 89442418             mov DWORD PTR [esp+0x18],eax
0x005322A1: eb04                 jmp 0x5322a7
0x005322A3: 895c2418             mov DWORD PTR [esp+0x18],ebx
0x005322A7: 68b4f1c000           push 0xc0f1b4
```

**可達 call sites（此局部區間）**

- `0x005321D3 call 0x89120c`
- `0x00532200 call 0x89120c`
- `0x00532221 call 0x89120c`
- `0x00532232 call 0x72e3c0`
- `0x0053224C call 0x72e2e0`
- `0x0053225E call 0x72e360`
- `0x0053227C call 0x7300a0`
- `0x00532295 call 0x8917b4`

**可達分支（此局部區間）**

- `0x005321CC jb 0x5321db`
- `0x005321F6 jb 0x532208`
- `0x00532217 jb 0x532229`
- `0x0053223D jne 0x531e02`
- `0x00532253 je 0x532550`
- `0x00532269 je 0x532550`
- `0x00532283 je 0x5322a3`
- `0x0053228C jb 0x532290`
- `0x00532292 je 0x5322a3`
- `0x005322A1 jmp 0x5322a7`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。