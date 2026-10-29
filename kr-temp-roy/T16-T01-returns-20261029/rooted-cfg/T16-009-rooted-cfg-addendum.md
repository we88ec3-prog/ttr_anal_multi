# T16-009 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x0053FA40` → source problematic `0x0053FADE`

- Root accessible native instructions: **87**; known conditional/direct/indexed branch edges: **12**; `call` instruction sites: **5**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0053FADC: c745f0dc18fe00                 mov DWORD PTR [ebp-0x10],0xfe18dc`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0053FAC7: 3b7808               cmp edi,DWORD PTR [eax+0x8]
0x0053FACA: 750a                 jne 0x53fad6
0x0053FACC: 8bf8                 mov edi,eax
0x0053FACE: 8b4004               mov eax,DWORD PTR [eax+0x4]
0x0053FAD1: 385815               cmp BYTE PTR [eax+0x15],bl
0x0053FAD4: 74f1                 je 0x53fac7
0x0053FAD6: 8bf8                 mov edi,eax
0x0053FAD8: 3bf9                 cmp edi,ecx
0x0053FADA: 75a4                 jne 0x53fa80
0x0053FADC: c745f0dc18fe00       mov DWORD PTR [ebp-0x10],0xfe18dc
0x0053FAE3: c645fc01             mov BYTE PTR [ebp-0x4],0x1
0x0053FAE7: 8b01                 mov eax,DWORD PTR [ecx]
0x0053FAE9: 51                   push ecx
0x0053FAEA: 50                   push eax
0x0053FAEB: 8d75ec               lea esi,[ebp-0x14]
0x0053FAEE: b8dc18fe00           mov eax,0xfe18dc
0x0053FAF3: e8c8450100           call 0x5540c0
0x0053FAF8: a1e018fe00           mov eax,ds:0xfe18e0
0x0053FAFD: 50                   push eax
0x0053FAFE: e809173500           call 0x89120c
0x0053FB03: a1cc18fe00           mov eax,ds:0xfe18cc
0x0053FB08: 83c404               add esp,0x4
0x0053FB0B: 3bc3                 cmp eax,ebx
0x0053FB0D: 7409                 je 0x53fb18
0x0053FB0F: 50                   push eax
0x0053FB10: e8f7163500           call 0x89120c
0x0053FB15: 83c404               add esp,0x4
0x0053FB18: 891dcc18fe00         mov DWORD PTR ds:0xfe18cc,ebx
0x0053FB1E: 891dd018fe00         mov DWORD PTR ds:0xfe18d0,ebx
0x0053FB24: 891dd418fe00         mov DWORD PTR ds:0xfe18d4,ebx
0x0053FB2A: 8b4df4               mov ecx,DWORD PTR [ebp-0xc]
0x0053FB2D: 64890d00000000       mov DWORD PTR fs:0x0,ecx
0x0053FB34: 59                   pop ecx
0x0053FB35: 5f                   pop edi
0x0053FB36: 5e                   pop esi
0x0053FB37: 5b                   pop ebx
0x0053FB38: 8be5                 mov esp,ebp
0x0053FB3A: 5d                   pop ebp
0x0053FB3B: c3                   ret 
```

**可達 call sites（此局部區間）**

- `0x0053FAF3 call 0x5540c0`
- `0x0053FAFE call 0x89120c`
- `0x0053FB10 call 0x89120c`

**可達分支（此局部區間）**

- `0x0053FACA jne 0x53fad6`
- `0x0053FAD4 je 0x53fac7`
- `0x0053FADA jne 0x53fa80`
- `0x0053FB0D je 0x53fb18`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
