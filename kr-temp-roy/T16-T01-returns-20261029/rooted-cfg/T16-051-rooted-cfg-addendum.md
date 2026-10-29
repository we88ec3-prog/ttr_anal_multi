# T16-051 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x00504740` → source problematic `0x00504817`

- Root accessible native instructions: **1063**; known conditional/direct/indexed branch edges: **204**; `call` instruction sites: **92**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `00504816: 89bc2488010000                 mov DWORD PTR [esp+0x188],edi`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x00504801: 83c404               add esp,0x4
0x00504804: 8d8c242c010000       lea ecx,[esp+0x12c]
0x0050480B: c784248c0100000f000000 mov DWORD PTR [esp+0x18c],0xf
0x00504816: 89bc2488010000       mov DWORD PTR [esp+0x188],edi
0x0050481D: c684247801000000     mov BYTE PTR [esp+0x178],0x0
0x00504825: e816982200           call 0x72e040
0x0050482A: 33c0                 xor eax,eax
0x0050482C: e9a70c0000           jmp 0x5054d8
0x00504831: 6870dbc000           push 0xc0db70
0x00504836: 8d842430010000       lea eax,[esp+0x130]
0x0050483D: e89e9a2200           call 0x72e2e0
0x00504842: 3bc7                 cmp eax,edi
0x00504844: 7569                 jne 0x5048af
0x00504846: 687cdbc000           push 0xc0db7c
0x0050484B: e810931e00           call 0x6edb60
0x00504850: c7842464020000ffffffff mov DWORD PTR [esp+0x264],0xffffffff
0x0050485B: 83c404               add esp,0x4
0x0050485E: c784242c0100009423bf00 mov DWORD PTR [esp+0x12c],0xbf2394
0x00504869: 399c248c010000       cmp DWORD PTR [esp+0x18c],ebx
0x00504870: 7210                 jb 0x504882
0x00504872: 8b842478010000       mov eax,DWORD PTR [esp+0x178]
0x00504879: 50                   push eax
0x0050487A: e88dc93800           call 0x89120c
0x0050487F: 83c404               add esp,0x4
0x00504882: 8d8c242c010000       lea ecx,[esp+0x12c]
0x00504889: c784248c0100000f000000 mov DWORD PTR [esp+0x18c],0xf
0x00504894: 89bc2488010000       mov DWORD PTR [esp+0x188],edi
0x0050489B: c684247801000000     mov BYTE PTR [esp+0x178],0x0
0x005048A3: e898972200           call 0x72e040
0x005048A8: 33c0                 xor eax,eax
0x005048AA: e9290c0000           jmp 0x5054d8
0x005048AF: 8b4018               mov eax,DWORD PTR [eax+0x18]
0x005048B2: 89442418             mov DWORD PTR [esp+0x18],eax
0x005048B6: 3bc7                 cmp eax,edi
0x005048B8: 0f84c00b0000         je 0x50547e
0x005048BE: 8bff                 mov edi,edi
0x005048C0: 8d4c2464             lea ecx,[esp+0x64]
0x005048C4: 51                   push ecx
0x005048C5: e856b0ffff           call 0x4ff920
0x005048CA: 8b4c2418             mov ecx,DWORD PTR [esp+0x18]
0x005048CE: c684246002000001     mov BYTE PTR [esp+0x260],0x1
0x005048D6: 8b11                 mov edx,DWORD PTR [ecx]
0x005048D8: 8b4214               mov eax,DWORD PTR [edx+0x14]
0x005048DB: ffd0                 call eax
0x005048DD: 8d7844               lea edi,[eax+0x44]
```

**可達 call sites（此局部區間）**

- `0x00504825 call 0x72e040`
- `0x0050483D call 0x72e2e0`
- `0x0050484B call 0x6edb60`
- `0x0050487A call 0x89120c`
- `0x005048A3 call 0x72e040`
- `0x005048C5 call 0x4ff920`
- `0x005048DB call eax`

**可達分支（此局部區間）**

- `0x0050482C jmp 0x5054d8`
- `0x00504844 jne 0x5048af`
- `0x00504870 jb 0x504882`
- `0x005048AA jmp 0x5054d8`
- `0x005048B8 je 0x50547e`

### Root `0x00505570` → source problematic `0x0050564B`

- Root accessible native instructions: **207**; known conditional/direct/indexed branch edges: **33**; `call` instruction sites: **23**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0050564A: e8918c2200                     call 0x72e2e0`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
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
0x00505668: 83c404               add esp,0x4
0x0050566B: c74424249423bf00     mov DWORD PTR [esp+0x24],0xbf2394
0x00505673: 39bc2484000000       cmp DWORD PTR [esp+0x84],edi
0x0050567A: 720d                 jb 0x505689
0x0050567C: 8b442470             mov eax,DWORD PTR [esp+0x70]
0x00505680: 50                   push eax
0x00505681: e886bb3800           call 0x89120c
0x00505686: 83c404               add esp,0x4
0x00505689: 8d4c2424             lea ecx,[esp+0x24]
0x0050568D: c78424840000000f000000 mov DWORD PTR [esp+0x84],0xf
0x00505698: 899c2480000000       mov DWORD PTR [esp+0x80],ebx
0x0050569F: 885c2470             mov BYTE PTR [esp+0x70],bl
0x005056A3: e898892200           call 0x72e040
0x005056A8: 33c0                 xor eax,eax
0x005056AA: e97e010000           jmp 0x50582d
0x005056AF: e87c130000           call 0x506a30
0x005056B4: 89442414             mov DWORD PTR [esp+0x14],eax
0x005056B8: 3bc3                 cmp eax,ebx
0x005056BA: 0f8420010000         je 0x5057e0
0x005056C0: eb04                 jmp 0x5056c6
0x005056C2: 8b442414             mov eax,DWORD PTR [esp+0x14]
0x005056C6: 8d7844               lea edi,[eax+0x44]
0x005056C9: 68d0d1be00           push 0xbed1d0
0x005056CE: e8cda92200           call 0x7300a0
0x005056D3: 3bc3                 cmp eax,ebx
0x005056D5: 741a                 je 0x5056f1
0x005056D7: 83c030               add eax,0x30
0x005056DA: 83781410             cmp DWORD PTR [eax+0x14],0x10
0x005056DE: 7202                 jb 0x5056e2
0x005056E0: 8b00                 mov eax,DWORD PTR [eax]
0x005056E2: 3bc3                 cmp eax,ebx
0x005056E4: 740b                 je 0x5056f1
0x005056E6: 50                   push eax
0x005056E7: e8c8c03800           call 0x8917b4
0x005056EC: 83c404               add esp,0x4
0x005056EF: eb02                 jmp 0x5056f3
0x005056F1: 33c0                 xor eax,eax
0x005056F3: 8b742418             mov esi,DWORD PTR [esp+0x18]
0x005056F7: 8d4c2420             lea ecx,[esp+0x20]
0x005056FB: 89442420             mov DWORD PTR [esp+0x20],eax
0x005056FF: 51                   push ecx
0x00505700: 8d442420             lea eax,[esp+0x20]
0x00505704: 8bce                 mov ecx,esi
0x00505706: e815e6ffff           call 0x503d20
0x0050570B: 8b4c241c             mov ecx,DWORD PTR [esp+0x1c]
0x0050570F: 3b4e04               cmp ecx,DWORD PTR [esi+0x4]
0x00505712: 0f8492000000         je 0x5057aa
```

**可達 call sites（此局部區間）**

- `0x00505635 call 0x72e040`
- `0x0050564A call 0x72e2e0`
- `0x00505658 call 0x6edb60`
- `0x00505681 call 0x89120c`
- `0x005056A3 call 0x72e040`
- `0x005056AF call 0x506a30`
- `0x005056CE call 0x7300a0`
- `0x005056E7 call 0x8917b4`
- `0x00505706 call 0x503d20`

**可達分支（此局部區間）**

- `0x0050563C jmp 0x50582d`
- `0x00505651 jne 0x5056af`
- `0x0050567A jb 0x505689`
- `0x005056AA jmp 0x50582d`
- `0x005056BA je 0x5057e0`
- `0x005056C0 jmp 0x5056c6`
- `0x005056D5 je 0x5056f1`
- `0x005056DE jb 0x5056e2`
- `0x005056E4 je 0x5056f1`
- `0x005056EF jmp 0x5056f3`
- `0x00505712 je 0x5057aa`

## 0x504740 六路分派與錯誤路徑

- `0x504D99 cmp ecx,5; 0x504D9C ja 0x504E16; 0x504D9E jmp [ecx*4+0x505554]` 的 6 筆 jump table（native DWORD）為 `0x00504DE2, 0x00504DF4, 0x00504DEB, 0x00504DFD, 0x00504E06, 0x00504E0F`。
- `0x505554` 是表的資料起點，不是正常指令起點；`0x50554C call 0x87DB30` 的 callee 有正常指令鏈 `0x87DB5A call 0x89C9F0 → 0x87DB5F int3`，在此有界正常路徑**沒有 ret**。故不得誤將 call 後跳表解碼成程式。完整 callee CFG 與機器碼見 `rooted-cfg/callee-0087DB30.json`；仍不主張 SEH/runtime trap 行為。

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。