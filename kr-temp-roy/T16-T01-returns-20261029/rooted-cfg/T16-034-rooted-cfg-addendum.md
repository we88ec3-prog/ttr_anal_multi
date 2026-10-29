# T16-034 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x0047B850` → source problematic `0x0047BA80`

- Root accessible native instructions: **223**; known conditional/direct/indexed branch edges: **24**; `call` instruction sites: **29**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0047BA7F: b9900efc00                     mov ecx,0xfc0e90`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0047BA69: e8d2143200           call 0x79cf40
0x0047BA6E: 6880dbbc00           push 0xbcdb80
0x0047BA73: e8a2684100           call 0x89231a
0x0047BA78: 83c404               add esp,0x4
0x0047BA7B: c645fc03             mov BYTE PTR [ebp-0x4],0x3
0x0047BA7F: b9900efc00           mov ecx,0xfc0e90
0x0047BA84: c645fc02             mov BYTE PTR [ebp-0x4],0x2
0x0047BA88: e853223200           call 0x79dce0
0x0047BA8D: 8bf0                 mov esi,eax
0x0047BA8F: 6aff                 push 0xffffffff
0x0047BA91: 56                   push esi
0x0047BA92: ff15fc20bd00         call DWORD PTR ds:0xbd20fc
0x0047BA98: 56                   push esi
0x0047BA99: ff15c821bd00         call DWORD PTR ds:0xbd21c8
0x0047BA9F: f605800ffc0001       test BYTE PTR ds:0xfc0f80,0x1
0x0047BAA6: 7521                 jne 0x47bac9
0x0047BAA8: 830d800ffc0001       or DWORD PTR ds:0xfc0f80,0x1
0x0047BAAF: c645fc05             mov BYTE PTR [ebp-0x4],0x5
0x0047BAB3: e8f8f3ffff           call 0x47aeb0
0x0047BAB8: 6870dbbc00           push 0xbcdb70
0x0047BABD: e858684100           call 0x89231a
0x0047BAC2: 83c404               add esp,0x4
0x0047BAC5: c645fc02             mov BYTE PTR [ebp-0x4],0x2
0x0047BAC9: be840ffc00           mov esi,0xfc0f84
0x0047BACE: e8edce0200           call 0x4a89c0
0x0047BAD3: c645fc01             mov BYTE PTR [ebp-0x4],0x1
0x0047BAD7: 85ff                 test edi,edi
0x0047BAD9: 7429                 je 0x47bb04
0x0047BADB: 8d5704               lea edx,[edi+0x4]
0x0047BADE: 83c8ff               or eax,0xffffffff
0x0047BAE1: f00fc102             lock xadd DWORD PTR [edx],eax
0x0047BAE5: 751d                 jne 0x47bb04
0x0047BAE7: 8b17                 mov edx,DWORD PTR [edi]
0x0047BAE9: 8b02                 mov eax,DWORD PTR [edx]
0x0047BAEB: 8bcf                 mov ecx,edi
0x0047BAED: ffd0                 call eax
0x0047BAEF: 8d4f08               lea ecx,[edi+0x8]
0x0047BAF2: 83caff               or edx,0xffffffff
0x0047BAF5: f00fc111             lock xadd DWORD PTR [ecx],edx
0x0047BAF9: 7509                 jne 0x47bb04
0x0047BAFB: 8b07                 mov eax,DWORD PTR [edi]
0x0047BAFD: 8b5004               mov edx,DWORD PTR [eax+0x4]
0x0047BB00: 8bcf                 mov ecx,edi
0x0047BB02: ffd2                 call edx
0x0047BB04: 8b45a8               mov eax,DWORD PTR [ebp-0x58]
0x0047BB07: 85c0                 test eax,eax
0x0047BB09: 7409                 je 0x47bb14
0x0047BB0B: 50                   push eax
0x0047BB0C: e8fb564100           call 0x89120c
0x0047BB11: 83c404               add esp,0x4
0x0047BB14: 8b4df4               mov ecx,DWORD PTR [ebp-0xc]
0x0047BB17: 64890d00000000       mov DWORD PTR fs:0x0,ecx
0x0047BB1E: 59                   pop ecx
0x0047BB1F: 5f                   pop edi
0x0047BB20: 5e                   pop esi
0x0047BB21: 5b                   pop ebx
0x0047BB22: 8be5                 mov esp,ebp
0x0047BB24: 5d                   pop ebp
0x0047BB25: c20400               ret 0x4
0x0047BB28: 8b7dbc               mov edi,DWORD PTR [ebp-0x44]
0x0047BB2B: 8b4db8               mov ecx,DWORD PTR [ebp-0x48]
0x0047BB2E: 8b7508               mov esi,DWORD PTR [ebp+0x8]
0x0047BB31: 57                   push edi
0x0047BB32: 51                   push ecx
0x0047BB33: e888763200           call 0x7a31c0
0x0047BB38: e914ffffff           jmp 0x47ba51
```

**可達 call sites（此局部區間）**

- `0x0047BA69 call 0x79cf40`
- `0x0047BA73 call 0x89231a`
- `0x0047BA88 call 0x79dce0`
- `0x0047BA92 call DWORD PTR ds:0xbd20fc`
- `0x0047BA99 call DWORD PTR ds:0xbd21c8`
- `0x0047BAB3 call 0x47aeb0`
- `0x0047BABD call 0x89231a`
- `0x0047BACE call 0x4a89c0`
- `0x0047BAED call eax`
- `0x0047BB02 call edx`
- `0x0047BB0C call 0x89120c`
- `0x0047BB33 call 0x7a31c0`

**可達分支（此局部區間）**

- `0x0047BAA6 jne 0x47bac9`
- `0x0047BAD9 je 0x47bb04`
- `0x0047BAE5 jne 0x47bb04`
- `0x0047BAF9 jne 0x47bb04`
- `0x0047BB09 je 0x47bb14`
- `0x0047BB38 jmp 0x47ba51`

### Root `0x004C1E10` → source problematic `0x004C1F90`

- Root accessible native instructions: **151**; known conditional/direct/indexed branch edges: **9**; `call` instruction sites: **25**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004C1F8D: e8aeaf2d00                     call 0x79cf40`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004C1F7B: bf01000000           mov edi,0x1
0x004C1F80: 7522                 jne 0x4c1fa4
0x004C1F82: 093d600ffc00         or DWORD PTR ds:0xfc0f60,edi
0x004C1F88: c644243002           mov BYTE PTR [esp+0x30],0x2
0x004C1F8D: e8aeaf2d00           call 0x79cf40
0x004C1F92: 6880dbbc00           push 0xbcdb80
0x004C1F97: e87e033d00           call 0x89231a
0x004C1F9C: 83c404               add esp,0x4
0x004C1F9F: c644243001           mov BYTE PTR [esp+0x30],0x1
0x004C1FA4: b9900efc00           mov ecx,0xfc0e90
0x004C1FA9: 885c2430             mov BYTE PTR [esp+0x30],bl
0x004C1FAD: e82ebd2d00           call 0x79dce0
0x004C1FB2: 8bf0                 mov esi,eax
0x004C1FB4: 6aff                 push 0xffffffff
0x004C1FB6: 56                   push esi
0x004C1FB7: ff15fc20bd00         call DWORD PTR ds:0xbd20fc
0x004C1FBD: 56                   push esi
0x004C1FBE: ff15c821bd00         call DWORD PTR ds:0xbd21c8
0x004C1FC4: f605800ffc0001       test BYTE PTR ds:0xfc0f80,0x1
0x004C1FCB: 8b5508               mov edx,DWORD PTR [ebp+0x8]
0x004C1FCE: 89ba78bd0000         mov DWORD PTR [edx+0xbd78],edi
0x004C1FD4: 7521                 jne 0x4c1ff7
0x004C1FD6: 093d800ffc00         or DWORD PTR ds:0xfc0f80,edi
0x004C1FDC: c644242803           mov BYTE PTR [esp+0x28],0x3
0x004C1FE1: e8ca8efbff           call 0x47aeb0
0x004C1FE6: 6870dbbc00           push 0xbcdb70
0x004C1FEB: e82a033d00           call 0x89231a
0x004C1FF0: 83c404               add esp,0x4
0x004C1FF3: 885c2428             mov BYTE PTR [esp+0x28],bl
0x004C1FF7: be840ffc00           mov esi,0xfc0f84
0x004C1FFC: e8bf69feff           call 0x4a89c0
0x004C2001: c7442428ffffffff     mov DWORD PTR [esp+0x28],0xffffffff
0x004C2009: 8b742418             mov esi,DWORD PTR [esp+0x18]
0x004C200D: 3bf3                 cmp esi,ebx
0x004C200F: 7429                 je 0x4c203a
0x004C2011: 8d4604               lea eax,[esi+0x4]
0x004C2014: 83c9ff               or ecx,0xffffffff
0x004C2017: f00fc108             lock xadd DWORD PTR [eax],ecx
0x004C201B: 751d                 jne 0x4c203a
0x004C201D: 8b16                 mov edx,DWORD PTR [esi]
0x004C201F: 8b02                 mov eax,DWORD PTR [edx]
0x004C2021: 8bce                 mov ecx,esi
0x004C2023: ffd0                 call eax
0x004C2025: 8d4e08               lea ecx,[esi+0x8]
0x004C2028: 83caff               or edx,0xffffffff
0x004C202B: f00fc111             lock xadd DWORD PTR [ecx],edx
0x004C202F: 7509                 jne 0x4c203a
0x004C2031: 8b06                 mov eax,DWORD PTR [esi]
0x004C2033: 8b5004               mov edx,DWORD PTR [eax+0x4]
0x004C2036: 8bce                 mov ecx,esi
0x004C2038: ffd2                 call edx
0x004C203A: 8b4c2420             mov ecx,DWORD PTR [esp+0x20]
0x004C203E: 64890d00000000       mov DWORD PTR fs:0x0,ecx
0x004C2045: 59                   pop ecx
0x004C2046: 5f                   pop edi
0x004C2047: 5e                   pop esi
0x004C2048: 5b                   pop ebx
0x004C2049: 8be5                 mov esp,ebp
0x004C204B: 5d                   pop ebp
0x004C204C: c20400               ret 0x4
```

**可達 call sites（此局部區間）**

- `0x004C1F8D call 0x79cf40`
- `0x004C1F97 call 0x89231a`
- `0x004C1FAD call 0x79dce0`
- `0x004C1FB7 call DWORD PTR ds:0xbd20fc`
- `0x004C1FBE call DWORD PTR ds:0xbd21c8`
- `0x004C1FE1 call 0x47aeb0`
- `0x004C1FEB call 0x89231a`
- `0x004C1FFC call 0x4a89c0`
- `0x004C2023 call eax`
- `0x004C2038 call edx`

**可達分支（此局部區間）**

- `0x004C1F80 jne 0x4c1fa4`
- `0x004C1FD4 jne 0x4c1ff7`
- `0x004C200F je 0x4c203a`
- `0x004C201B jne 0x4c203a`
- `0x004C202F jne 0x4c203a`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。