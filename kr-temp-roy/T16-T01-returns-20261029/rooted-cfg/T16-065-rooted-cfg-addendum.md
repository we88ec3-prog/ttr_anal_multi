# T16-065 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x004AB8A0` → source problematic `0x004AB930`

- Root accessible native instructions: **48**; known conditional/direct/indexed branch edges: **2**; `call` instruction sites: **5**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `004AB92F: 8b4508                         mov eax,DWORD PTR [ebp+0x8]`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004AB91B: e8d09e2400           call 0x6f57f0
0x004AB920: 8b150018fe00         mov edx,DWORD PTR ds:0xfe1800
0x004AB926: 8b02                 mov eax,DWORD PTR [edx]
0x004AB928: 83c40c               add esp,0xc
0x004AB92B: 834008f0             add DWORD PTR [eax+0x8],0xfffffff0
0x004AB92F: 8b4508               mov eax,DWORD PTR [ebp+0x8]
0x004AB932: 5f                   pop edi
0x004AB933: 5e                   pop esi
0x004AB934: 5b                   pop ebx
0x004AB935: 5d                   pop ebp
0x004AB936: c20400               ret 0x4
```

**可達 call sites（此局部區間）**

- `0x004AB91B call 0x6f57f0`

**可達分支（此局部區間）**

- 無

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
