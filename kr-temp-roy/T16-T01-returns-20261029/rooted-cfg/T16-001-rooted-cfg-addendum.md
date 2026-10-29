# T16-001 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x004A88E0` → source problematic `0x004A899F`

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

### Root `0x004A8A60` → source problematic `0x004A8B2F`

- Root accessible native instructions: **82**; known conditional/direct/indexed branch edges: **6**; `call` instruction sites: **11**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004A8B2B: e8ea973e00                     call 0x89231a`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004A8B18: 841d1413fb00         test BYTE PTR ds:0xfb1314,bl
0x004A8B1E: 7513                 jne 0x4a8b33
0x004A8B20: 091d1413fb00         or DWORD PTR ds:0xfb1314,ebx
0x004A8B26: 6810cfbc00           push 0xbccf10
0x004A8B2B: e8ea973e00           call 0x89231a
0x004A8B30: 83c404               add esp,0x4
0x004A8B33: 833d98a7fb0000       cmp DWORD PTR ds:0xfba798,0x0
0x004A8B3A: b80c000000           mov eax,0xc
0x004A8B3F: 668945ec             mov WORD PTR [ebp-0x14],ax
0x004A8B43: 895dee               mov DWORD PTR [ebp-0x12],ebx
0x004A8B46: 7515                 jne 0x4a8b5d
0x004A8B48: 8b0d54a8fb00         mov ecx,DWORD PTR ds:0xfba854
0x004A8B4E: 8b11                 mov edx,DWORD PTR [ecx]
0x004A8B50: 8b5210               mov edx,DWORD PTR [edx+0x10]
0x004A8B53: 6a06                 push 0x6
0x004A8B55: 8d45ec               lea eax,[ebp-0x14]
0x004A8B58: 50                   push eax
0x004A8B59: 6a00                 push 0x0
0x004A8B5B: ffd2                 call edx
0x004A8B5D: 8b0e                 mov ecx,DWORD PTR [esi]
0x004A8B5F: 687c68c000           push 0xc0687c
0x004A8B64: e8e7be2400           call 0x6f4a50
0x004A8B69: 8b06                 mov eax,DWORD PTR [esi]
0x004A8B6B: 6a00                 push 0x0
0x004A8B6D: 6a00                 push 0x0
0x004A8B6F: 68a868c000           push 0xc068a8
0x004A8B74: e857c22400           call 0x6f4dd0
0x004A8B79: 83c40c               add esp,0xc
0x004A8B7C: 8b4df4               mov ecx,DWORD PTR [ebp-0xc]
0x004A8B7F: 64890d00000000       mov DWORD PTR fs:0x0,ecx
0x004A8B86: 59                   pop ecx
0x004A8B87: 5f                   pop edi
0x004A8B88: 5b                   pop ebx
0x004A8B89: 8be5                 mov esp,ebp
0x004A8B8B: 5d                   pop ebp
0x004A8B8C: c3                   ret 
```

**可達 call sites（此局部區間）**

- `0x004A8B2B call 0x89231a`
- `0x004A8B5B call edx`
- `0x004A8B64 call 0x6f4a50`
- `0x004A8B74 call 0x6f4dd0`

**可達分支（此局部區間）**

- `0x004A8B1E jne 0x4a8b33`
- `0x004A8B46 jne 0x4a8b5d`

### Root `0x00505570` → source problematic `0x0050559F`

- Root accessible native instructions: **207**; known conditional/direct/indexed branch edges: **33**; `call` instruction sites: **23**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0050559B: a1201fd600                     mov eax,ds:0xd61f20`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0050558A: a1201fd600           mov eax,ds:0xd61f20
0x0050558F: 33c4                 xor eax,esp
0x00505591: 89842490000000       mov DWORD PTR [esp+0x90],eax
0x00505598: 53                   push ebx
0x00505599: 56                   push esi
0x0050559A: 57                   push edi
0x0050559B: a1201fd600           mov eax,ds:0xd61f20
0x005055A0: 33c4                 xor eax,esp
0x005055A2: 50                   push eax
0x005055A3: 8d8424a8000000       lea eax,[esp+0xa8]
0x005055AA: 64a300000000         mov fs:0x0,eax
0x005055B0: 8b4508               mov eax,DWORD PTR [ebp+0x8]
0x005055B3: 8d4c2424             lea ecx,[esp+0x24]
0x005055B7: 51                   push ecx
0x005055B8: b95cdbc000           mov ecx,0xc0db5c
0x005055BD: 8944241c             mov DWORD PTR [esp+0x1c],eax
0x005055C1: e86a982200           call 0x72ee30
0x005055C6: 33db                 xor ebx,ebx
0x005055C8: 899c24b0000000       mov DWORD PTR [esp+0xb0],ebx
0x005055CF: 8b4c2444             mov ecx,DWORD PTR [esp+0x44]
0x005055D3: bf10000000           mov edi,0x10
0x005055D8: 397c2458             cmp DWORD PTR [esp+0x58],edi
0x005055DC: 7304                 jae 0x5055e2
0x005055DE: 8d4c2444             lea ecx,[esp+0x44]
0x005055E2: 53                   push ebx
0x005055E3: 8d742428             lea esi,[esp+0x28]
0x005055E7: e8249b2200           call 0x72f110
0x005055EC: 385c2468             cmp BYTE PTR [esp+0x68],bl
0x005055F0: 744f                 je 0x505641
0x005055F2: c78424b0000000ffffffff mov DWORD PTR [esp+0xb0],0xffffffff
0x005055FD: c74424249423bf00     mov DWORD PTR [esp+0x24],0xbf2394
0x00505605: 39bc2484000000       cmp DWORD PTR [esp+0x84],edi
0x0050560C: 720d                 jb 0x50561b
0x0050560E: 8b542470             mov edx,DWORD PTR [esp+0x70]
0x00505612: 52                   push edx
0x00505613: e8f4bb3800           call 0x89120c
0x00505618: 83c404               add esp,0x4
0x0050561B: 8d4c2424             lea ecx,[esp+0x24]
0x0050561F: c78424840000000f000000 mov DWORD PTR [esp+0x84],0xf
0x0050562A: 899c2480000000       mov DWORD PTR [esp+0x80],ebx
0x00505631: 885c2470             mov BYTE PTR [esp+0x70],bl
0x00505635: e8068a2200           call 0x72e040
0x0050563A: 33c0                 xor eax,eax
0x0050563C: e9ec010000           jmp 0x50582d
0x00505641: 6844dcc000           push 0xc0dc44
0x00505646: 8d442428             lea eax,[esp+0x28]
0x0050564A: e8918c2200           call 0x72e2e0
0x0050564F: 3bc3                 cmp eax,ebx
0x00505651: 755c                 jne 0x5056af
0x00505653: 6850dcc000           push 0xc0dc50
0x00505658: e803851e00           call 0x6edb60
0x0050565D: c78424b4000000ffffffff mov DWORD PTR [esp+0xb4],0xffffffff
```

**可達 call sites（此局部區間）**

- `0x005055C1 call 0x72ee30`
- `0x005055E7 call 0x72f110`
- `0x00505613 call 0x89120c`
- `0x00505635 call 0x72e040`
- `0x0050564A call 0x72e2e0`
- `0x00505658 call 0x6edb60`

**可達分支（此局部區間）**

- `0x005055DC jae 0x5055e2`
- `0x005055F0 je 0x505641`
- `0x0050560C jb 0x50561b`
- `0x0050563C jmp 0x50582d`
- `0x00505651 jne 0x5056af`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
