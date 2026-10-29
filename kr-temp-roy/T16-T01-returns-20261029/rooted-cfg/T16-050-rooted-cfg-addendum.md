# T16-050 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x006F4DD0` → source problematic `0x006F4E83`

- Root accessible native instructions: **129**; known conditional/direct/indexed branch edges: **12**; `call` instruction sites: **8**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `006F4E81: e8ea980000                     call 0x6fe770`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x006F4E6B: 2b4620               sub eax,DWORD PTR [esi+0x20]
0x006F4E6E: 8d542410             lea edx,[esp+0x10]
0x006F4E72: 50                   push eax
0x006F4E73: 52                   push edx
0x006F4E74: 68505a6f00           push 0x6f5a50
0x006F4E79: 33d2                 xor edx,edx
0x006F4E7B: 8bc6                 mov eax,esi
0x006F4E7D: 895c2420             mov DWORD PTR [esp+0x20],ebx
0x006F4E81: e8ea980000           call 0x6fe770
0x006F4E86: 83c40c               add esp,0xc
0x006F4E89: 83fbff               cmp ebx,0xffffffff
0x006F4E8C: 750e                 jne 0x6f4e9c
0x006F4E8E: 8b4e14               mov ecx,DWORD PTR [esi+0x14]
0x006F4E91: 8b7608               mov esi,DWORD PTR [esi+0x8]
0x006F4E94: 3b7108               cmp esi,DWORD PTR [ecx+0x8]
0x006F4E97: 7203                 jb 0x6f4e9c
0x006F4E99: 897108               mov DWORD PTR [ecx+0x8],esi
0x006F4E9C: 85c0                 test eax,eax
0x006F4E9E: 0f8487000000         je 0x6f4f2b
0x006F4EA4: 8b3f                 mov edi,DWORD PTR [edi]
0x006F4EA6: 8b7708               mov esi,DWORD PTR [edi+0x8]
0x006F4EA9: 83ee10               sub esi,0x10
0x006F4EAC: 837e0804             cmp DWORD PTR [esi+0x8],0x4
0x006F4EB0: 7425                 je 0x6f4ed7
0x006F4EB2: e819670000           call 0x6fb5d0
0x006F4EB7: 85c0                 test eax,eax
0x006F4EB9: 7504                 jne 0x6f4ebf
0x006F4EBB: 33f6                 xor esi,esi
0x006F4EBD: eb1d                 jmp 0x6f4edc
0x006F4EBF: 8b4710               mov eax,DWORD PTR [edi+0x10]
0x006F4EC2: 8b4844               mov ecx,DWORD PTR [eax+0x44]
0x006F4EC5: 3b4840               cmp ecx,DWORD PTR [eax+0x40]
0x006F4EC8: 7207                 jb 0x6f4ed1
0x006F4ECA: 8bc7                 mov eax,edi
0x006F4ECC: e8cf640000           call 0x6fb3a0
0x006F4ED1: 8b7708               mov esi,DWORD PTR [edi+0x8]
0x006F4ED4: 83ee10               sub esi,0x10
0x006F4ED7: 8b36                 mov esi,DWORD PTR [esi]
0x006F4ED9: 83c610               add esi,0x10
0x006F4EDC: 8b5508               mov edx,DWORD PTR [ebp+0x8]
0x006F4EDF: 56                   push esi
0x006F4EE0: 52                   push edx
0x006F4EE1: 687826c400           push 0xc42678
0x006F4EE6: e8d2e11900           call 0x8930bd
0x006F4EEB: 83c40c               add esp,0xc
0x006F4EEE: 5f                   pop edi
0x006F4EEF: 5e                   pop esi
0x006F4EF0: 5b                   pop ebx
0x006F4EF1: 8be5                 mov esp,ebp
0x006F4EF3: 5d                   pop ebp
0x006F4EF4: c3                   ret 
0x006F4EF5: 8b4508               mov eax,DWORD PTR [ebp+0x8]
0x006F4EF8: 50                   push eax
0x006F4EF9: 681026c400           push 0xc42610
0x006F4EFE: e8bae11900           call 0x8930bd
0x006F4F03: 8b07                 mov eax,DWORD PTR [edi]
0x006F4F05: 8b4808               mov ecx,DWORD PTR [eax+0x8]
0x006F4F08: 83c408               add esp,0x8
0x006F4F0B: 3b480c               cmp ecx,DWORD PTR [eax+0xc]
0x006F4F0E: 7315                 jae 0x6f4f25
0x006F4F10: 8b5008               mov edx,DWORD PTR [eax+0x8]
0x006F4F13: c7420800000000       mov DWORD PTR [edx+0x8],0x0
0x006F4F1A: 015808               add DWORD PTR [eax+0x8],ebx
0x006F4F1D: 8b4808               mov ecx,DWORD PTR [eax+0x8]
0x006F4F20: 3b480c               cmp ecx,DWORD PTR [eax+0xc]
0x006F4F23: 72eb                 jb 0x6f4f10
0x006F4F25: 8b500c               mov edx,DWORD PTR [eax+0xc]
0x006F4F28: 895008               mov DWORD PTR [eax+0x8],edx
0x006F4F2B: 5f                   pop edi
0x006F4F2C: 5e                   pop esi
0x006F4F2D: 5b                   pop ebx
0x006F4F2E: 8be5                 mov esp,ebp
0x006F4F30: 5d                   pop ebp
0x006F4F31: c3                   ret 
```

**可達 call sites（此局部區間）**

- `0x006F4E81 call 0x6fe770`
- `0x006F4EB2 call 0x6fb5d0`
- `0x006F4ECC call 0x6fb3a0`
- `0x006F4EE6 call 0x8930bd`
- `0x006F4EFE call 0x8930bd`

**可達分支（此局部區間）**

- `0x006F4E8C jne 0x6f4e9c`
- `0x006F4E97 jb 0x6f4e9c`
- `0x006F4E9E je 0x6f4f2b`
- `0x006F4EB0 je 0x6f4ed7`
- `0x006F4EB9 jne 0x6f4ebf`
- `0x006F4EBD jmp 0x6f4edc`
- `0x006F4EC8 jb 0x6f4ed1`
- `0x006F4F0E jae 0x6f4f25`
- `0x006F4F23 jb 0x6f4f10`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。