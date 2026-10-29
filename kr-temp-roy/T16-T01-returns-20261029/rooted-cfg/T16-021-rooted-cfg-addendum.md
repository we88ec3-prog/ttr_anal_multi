# T16-021 — appendix rooted CFG / corrected instruction windows

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

### Root `0x0053FBB0` → source problematic `0x0053FD40`

- Root accessible native instructions: **223**; known conditional/direct/indexed branch edges: **29**; `call` instruction sites: **27**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0053FD3D: e826153500                     call 0x891268`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0053FD28: 50                   push eax
0x0053FD29: e8861a3500           call 0x8917b4
0x0053FD2E: 83c404               add esp,0x4
0x0053FD31: 89442418             mov DWORD PTR [esp+0x18],eax
0x0053FD35: eb04                 jmp 0x53fd3b
0x0053FD37: 89742418             mov DWORD PTR [esp+0x18],esi
0x0053FD3B: 6a40                 push 0x40
0x0053FD3D: e826153500           call 0x891268
0x0053FD42: 83c404               add esp,0x4
0x0053FD45: 3bc6                 cmp eax,esi
0x0053FD47: 7429                 je 0x53fd72
0x0053FD49: 8930                 mov DWORD PTR [eax],esi
0x0053FD4B: 897004               mov DWORD PTR [eax+0x4],esi
0x0053FD4E: 897008               mov DWORD PTR [eax+0x8],esi
0x0053FD51: 897010               mov DWORD PTR [eax+0x10],esi
0x0053FD54: 897014               mov DWORD PTR [eax+0x14],esi
0x0053FD57: 897018               mov DWORD PTR [eax+0x18],esi
0x0053FD5A: 897020               mov DWORD PTR [eax+0x20],esi
0x0053FD5D: 897024               mov DWORD PTR [eax+0x24],esi
0x0053FD60: 897028               mov DWORD PTR [eax+0x28],esi
0x0053FD63: 897030               mov DWORD PTR [eax+0x30],esi
0x0053FD66: 897034               mov DWORD PTR [eax+0x34],esi
0x0053FD69: 897038               mov DWORD PTR [eax+0x38],esi
0x0053FD6C: 89442414             mov DWORD PTR [esp+0x14],eax
0x0053FD70: eb04                 jmp 0x53fd76
0x0053FD72: 89742414             mov DWORD PTR [esp+0x14],esi
0x0053FD76: 68e4f4c000           push 0xc0f4e4
0x0053FD7B: 8bc3                 mov eax,ebx
0x0053FD7D: e85ee51e00           call 0x72e2e0
0x0053FD82: 8bf8                 mov edi,eax
0x0053FD84: 68ecf4c000           push 0xc0f4ec
0x0053FD89: 8bc3                 mov eax,ebx
0x0053FD8B: e850e51e00           call 0x72e2e0
0x0053FD90: 8bf0                 mov esi,eax
0x0053FD92: 68f8f4c000           push 0xc0f4f8
0x0053FD97: 8bc3                 mov eax,ebx
0x0053FD99: e842e51e00           call 0x72e2e0
0x0053FD9E: 89442420             mov DWORD PTR [esp+0x20],eax
0x0053FDA2: 680cf5c000           push 0xc0f50c
0x0053FDA7: 8bc3                 mov eax,ebx
0x0053FDA9: e832e51e00           call 0x72e2e0
0x0053FDAE: 8944241c             mov DWORD PTR [esp+0x1c],eax
0x0053FDB2: 85ff                 test edi,edi
0x0053FDB4: 740c                 je 0x53fdc2
0x0053FDB6: 8b4c2414             mov ecx,DWORD PTR [esp+0x14]
0x0053FDBA: 51                   push ecx
0x0053FDBB: 8bc7                 mov eax,edi
0x0053FDBD: e8ee000000           call 0x53feb0
0x0053FDC2: 8b7c2414             mov edi,DWORD PTR [esp+0x14]
0x0053FDC6: 85f6                 test esi,esi
0x0053FDC8: 740b                 je 0x53fdd5
0x0053FDCA: 8d5710               lea edx,[edi+0x10]
0x0053FDCD: 52                   push edx
0x0053FDCE: 8bc6                 mov eax,esi
0x0053FDD0: e8db000000           call 0x53feb0
0x0053FDD5: 8b442420             mov eax,DWORD PTR [esp+0x20]
0x0053FDD9: 85c0                 test eax,eax
0x0053FDDB: 7409                 je 0x53fde6
0x0053FDDD: 8d4f20               lea ecx,[edi+0x20]
0x0053FDE0: 51                   push ecx
0x0053FDE1: e8ca000000           call 0x53feb0
0x0053FDE6: 8b44241c             mov eax,DWORD PTR [esp+0x1c]
0x0053FDEA: 85c0                 test eax,eax
0x0053FDEC: 7409                 je 0x53fdf7
0x0053FDEE: 8d5730               lea edx,[edi+0x30]
0x0053FDF1: 52                   push edx
0x0053FDF2: e8b9000000           call 0x53feb0
0x0053FDF7: 8b442418             mov eax,DWORD PTR [esp+0x18]
0x0053FDFB: 897c2428             mov DWORD PTR [esp+0x28],edi
0x0053FDFF: 8d7c2424             lea edi,[esp+0x24]
0x0053FE03: bedc18fe00           mov esi,0xfe18dc
```

**可達 call sites（此局部區間）**

- `0x0053FD29 call 0x8917b4`
- `0x0053FD3D call 0x891268`
- `0x0053FD7D call 0x72e2e0`
- `0x0053FD8B call 0x72e2e0`
- `0x0053FD99 call 0x72e2e0`
- `0x0053FDA9 call 0x72e2e0`
- `0x0053FDBD call 0x53feb0`
- `0x0053FDD0 call 0x53feb0`
- `0x0053FDE1 call 0x53feb0`
- `0x0053FDF2 call 0x53feb0`

**可達分支（此局部區間）**

- `0x0053FD35 jmp 0x53fd3b`
- `0x0053FD47 je 0x53fd72`
- `0x0053FD70 jmp 0x53fd76`
- `0x0053FDB4 je 0x53fdc2`
- `0x0053FDC8 je 0x53fdd5`
- `0x0053FDDB je 0x53fde6`
- `0x0053FDEC je 0x53fdf7`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
