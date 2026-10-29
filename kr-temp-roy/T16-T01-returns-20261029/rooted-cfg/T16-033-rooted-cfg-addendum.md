# T16-033 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x004C4B10` → source problematic `0x004C4C80`

- Root accessible native instructions: **149**; known conditional/direct/indexed branch edges: **15**; `call` instruction sites: **24**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004C4C7F: 6870dbbc00                     push 0xbcdb70`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004C4C6A: 7524                 jne 0x4c4c90
0x004C4C6C: 093d800ffc00         or DWORD PTR ds:0xfc0f80,edi
0x004C4C72: c744242003000000     mov DWORD PTR [esp+0x20],0x3
0x004C4C7A: e83162fbff           call 0x47aeb0
0x004C4C7F: 6870dbbc00           push 0xbcdb70
0x004C4C84: e891d63c00           call 0x89231a
0x004C4C89: 83c404               add esp,0x4
0x004C4C8C: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4C90: b9840ffc00           mov ecx,0xfc0f84
0x004C4C95: e8863ffeff           call 0x4a8c20
0x004C4C9A: 8b0da4a7fb00         mov ecx,DWORD PTR ds:0xfba7a4
0x004C4CA0: 3bce                 cmp ecx,esi
0x004C4CA2: 742f                 je 0x4c4cd3
0x004C4CA4: 833daca7fb0004       cmp DWORD PTR ds:0xfba7ac,0x4
0x004C4CAB: 750e                 jne 0x4c4cbb
0x004C4CAD: 8bf9                 mov edi,ecx
0x004C4CAF: e89c020800           call 0x544f50
0x004C4CB4: bf01000000           mov edi,0x1
0x004C4CB9: eb52                 jmp 0x4c4d0d
0x004C4CBB: 8b01                 mov eax,DWORD PTR [ecx]
0x004C4CBD: 8b5028               mov edx,DWORD PTR [eax+0x28]
0x004C4CC0: ffd2                 call edx
0x004C4CC2: 8b0da4a7fb00         mov ecx,DWORD PTR ds:0xfba7a4
0x004C4CC8: 3bce                 cmp ecx,esi
0x004C4CCA: 7407                 je 0x4c4cd3
0x004C4CCC: 8b01                 mov eax,DWORD PTR [ecx]
0x004C4CCE: 8b10                 mov edx,DWORD PTR [eax]
0x004C4CD0: 57                   push edi
0x004C4CD1: ffd2                 call edx
0x004C4CD3: 6838010000           push 0x138
0x004C4CD8: e88bc53c00           call 0x891268
0x004C4CDD: 83c404               add esp,0x4
0x004C4CE0: 89442410             mov DWORD PTR [esp+0x10],eax
0x004C4CE4: c744242008000000     mov DWORD PTR [esp+0x20],0x8
0x004C4CEC: 3bc6                 cmp eax,esi
0x004C4CEE: 7409                 je 0x4c4cf9
0x004C4CF0: 8bf0                 mov esi,eax
0x004C4CF2: e8993e0800           call 0x548b90
0x004C4CF7: eb02                 jmp 0x4c4cfb
0x004C4CF9: 33c0                 xor eax,eax
0x004C4CFB: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4CFF: 8b10                 mov edx,DWORD PTR [eax]
0x004C4D01: a3a4a7fb00           mov ds:0xfba7a4,eax
0x004C4D06: 8bc8                 mov ecx,eax
0x004C4D08: 8b4224               mov eax,DWORD PTR [edx+0x24]
0x004C4D0B: ffd0                 call eax
0x004C4D0D: f605800ffc0001       test BYTE PTR ds:0xfc0f80,0x1
0x004C4D14: 7524                 jne 0x4c4d3a
0x004C4D16: 093d800ffc00         or DWORD PTR ds:0xfc0f80,edi
0x004C4D1C: c74424200b000000     mov DWORD PTR [esp+0x20],0xb
0x004C4D24: e88761fbff           call 0x47aeb0
0x004C4D29: 6870dbbc00           push 0xbcdb70
0x004C4D2E: e8e7d53c00           call 0x89231a
0x004C4D33: 83c404               add esp,0x4
0x004C4D36: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4D3A: be840ffc00           mov esi,0xfc0f84
0x004C4D3F: e81c3dfeff           call 0x4a8a60
0x004C4D44: 33c0                 xor eax,eax
0x004C4D46: 8b4c2418             mov ecx,DWORD PTR [esp+0x18]
```

**可達 call sites（此局部區間）**

- `0x004C4C7A call 0x47aeb0`
- `0x004C4C84 call 0x89231a`
- `0x004C4C95 call 0x4a8c20`
- `0x004C4CAF call 0x544f50`
- `0x004C4CC0 call edx`
- `0x004C4CD1 call edx`
- `0x004C4CD8 call 0x891268`
- `0x004C4CF2 call 0x548b90`
- `0x004C4D0B call eax`
- `0x004C4D24 call 0x47aeb0`
- `0x004C4D2E call 0x89231a`
- `0x004C4D3F call 0x4a8a60`

**可達分支（此局部區間）**

- `0x004C4C6A jne 0x4c4c90`
- `0x004C4CA2 je 0x4c4cd3`
- `0x004C4CAB jne 0x4c4cbb`
- `0x004C4CB9 jmp 0x4c4d0d`
- `0x004C4CCA je 0x4c4cd3`
- `0x004C4CEE je 0x4c4cf9`
- `0x004C4CF7 jmp 0x4c4cfb`
- `0x004C4D14 jne 0x4c4d3a`

### Root `0x004C4B10` → source problematic `0x004C4C87`

- Root accessible native instructions: **149**; known conditional/direct/indexed branch edges: **15**; `call` instruction sites: **24**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004C4C84: e891d63c00                     call 0x89231a`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004C4C72: c744242003000000     mov DWORD PTR [esp+0x20],0x3
0x004C4C7A: e83162fbff           call 0x47aeb0
0x004C4C7F: 6870dbbc00           push 0xbcdb70
0x004C4C84: e891d63c00           call 0x89231a
0x004C4C89: 83c404               add esp,0x4
0x004C4C8C: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4C90: b9840ffc00           mov ecx,0xfc0f84
0x004C4C95: e8863ffeff           call 0x4a8c20
0x004C4C9A: 8b0da4a7fb00         mov ecx,DWORD PTR ds:0xfba7a4
0x004C4CA0: 3bce                 cmp ecx,esi
0x004C4CA2: 742f                 je 0x4c4cd3
0x004C4CA4: 833daca7fb0004       cmp DWORD PTR ds:0xfba7ac,0x4
0x004C4CAB: 750e                 jne 0x4c4cbb
0x004C4CAD: 8bf9                 mov edi,ecx
0x004C4CAF: e89c020800           call 0x544f50
0x004C4CB4: bf01000000           mov edi,0x1
0x004C4CB9: eb52                 jmp 0x4c4d0d
0x004C4CBB: 8b01                 mov eax,DWORD PTR [ecx]
0x004C4CBD: 8b5028               mov edx,DWORD PTR [eax+0x28]
0x004C4CC0: ffd2                 call edx
0x004C4CC2: 8b0da4a7fb00         mov ecx,DWORD PTR ds:0xfba7a4
0x004C4CC8: 3bce                 cmp ecx,esi
0x004C4CCA: 7407                 je 0x4c4cd3
0x004C4CCC: 8b01                 mov eax,DWORD PTR [ecx]
0x004C4CCE: 8b10                 mov edx,DWORD PTR [eax]
0x004C4CD0: 57                   push edi
0x004C4CD1: ffd2                 call edx
0x004C4CD3: 6838010000           push 0x138
0x004C4CD8: e88bc53c00           call 0x891268
0x004C4CDD: 83c404               add esp,0x4
0x004C4CE0: 89442410             mov DWORD PTR [esp+0x10],eax
0x004C4CE4: c744242008000000     mov DWORD PTR [esp+0x20],0x8
0x004C4CEC: 3bc6                 cmp eax,esi
0x004C4CEE: 7409                 je 0x4c4cf9
0x004C4CF0: 8bf0                 mov esi,eax
0x004C4CF2: e8993e0800           call 0x548b90
0x004C4CF7: eb02                 jmp 0x4c4cfb
0x004C4CF9: 33c0                 xor eax,eax
0x004C4CFB: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4CFF: 8b10                 mov edx,DWORD PTR [eax]
0x004C4D01: a3a4a7fb00           mov ds:0xfba7a4,eax
0x004C4D06: 8bc8                 mov ecx,eax
0x004C4D08: 8b4224               mov eax,DWORD PTR [edx+0x24]
0x004C4D0B: ffd0                 call eax
0x004C4D0D: f605800ffc0001       test BYTE PTR ds:0xfc0f80,0x1
0x004C4D14: 7524                 jne 0x4c4d3a
0x004C4D16: 093d800ffc00         or DWORD PTR ds:0xfc0f80,edi
0x004C4D1C: c74424200b000000     mov DWORD PTR [esp+0x20],0xb
0x004C4D24: e88761fbff           call 0x47aeb0
0x004C4D29: 6870dbbc00           push 0xbcdb70
0x004C4D2E: e8e7d53c00           call 0x89231a
0x004C4D33: 83c404               add esp,0x4
0x004C4D36: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x004C4D3A: be840ffc00           mov esi,0xfc0f84
0x004C4D3F: e81c3dfeff           call 0x4a8a60
0x004C4D44: 33c0                 xor eax,eax
0x004C4D46: 8b4c2418             mov ecx,DWORD PTR [esp+0x18]
0x004C4D4A: 64890d00000000       mov DWORD PTR fs:0x0,ecx
```

**可達 call sites（此局部區間）**

- `0x004C4C7A call 0x47aeb0`
- `0x004C4C84 call 0x89231a`
- `0x004C4C95 call 0x4a8c20`
- `0x004C4CAF call 0x544f50`
- `0x004C4CC0 call edx`
- `0x004C4CD1 call edx`
- `0x004C4CD8 call 0x891268`
- `0x004C4CF2 call 0x548b90`
- `0x004C4D0B call eax`
- `0x004C4D24 call 0x47aeb0`
- `0x004C4D2E call 0x89231a`
- `0x004C4D3F call 0x4a8a60`

**可達分支（此局部區間）**

- `0x004C4CA2 je 0x4c4cd3`
- `0x004C4CAB jne 0x4c4cbb`
- `0x004C4CB9 jmp 0x4c4d0d`
- `0x004C4CCA je 0x4c4cd3`
- `0x004C4CEE je 0x4c4cf9`
- `0x004C4CF7 jmp 0x4c4cfb`
- `0x004C4D14 jne 0x4c4d3a`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。