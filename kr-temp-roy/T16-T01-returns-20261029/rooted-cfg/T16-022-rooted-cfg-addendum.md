# T16-022 — appendix rooted CFG / corrected instruction windows

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

### Root `0x004A8A60` → source problematic `0x004A8B10`

- Root accessible native instructions: **82**; known conditional/direct/indexed branch edges: **6**; `call` instruction sites: **11**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004A8B0C: a3f0adfa00                     mov ds:0xfaadf0,eax`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004A8AF9: 83c404               add esp,0x4
0x004A8AFC: 897dfc               mov DWORD PTR [ebp-0x4],edi
0x004A8AFF: b80f000000           mov eax,0xf
0x004A8B04: 3905ecadfa00         cmp DWORD PTR ds:0xfaadec,eax
0x004A8B0A: 7407                 je 0x4a8b13
0x004A8B0C: a3f0adfa00           mov ds:0xfaadf0,eax
0x004A8B11: eb05                 jmp 0x4a8b18
0x004A8B13: e8881e0e00           call 0x58a9a0
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

- `0x004A8B13 call 0x58a9a0`
- `0x004A8B2B call 0x89231a`
- `0x004A8B5B call edx`
- `0x004A8B64 call 0x6f4a50`
- `0x004A8B74 call 0x6f4dd0`

**可達分支（此局部區間）**

- `0x004A8B0A je 0x4a8b13`
- `0x004A8B11 jmp 0x4a8b18`
- `0x004A8B1E jne 0x4a8b33`
- `0x004A8B46 jne 0x4a8b5d`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。