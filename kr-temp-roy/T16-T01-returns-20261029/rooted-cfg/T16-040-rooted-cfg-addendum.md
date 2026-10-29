# T16-040 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x005027D0` → source problematic `0x00502870`

- Root accessible native instructions: **256**; known conditional/direct/indexed branch edges: **25**; `call` instruction sites: **32**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0050286F: 894814                         mov DWORD PTR [eax+0x14],ecx`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x00502858: 50                   push eax
0x00502859: 895004               mov DWORD PTR [eax+0x4],edx
0x0050285C: 895008               mov DWORD PTR [eax+0x8],edx
0x0050285F: 89700c               mov DWORD PTR [eax+0xc],esi
0x00502862: c7401006430f00       mov DWORD PTR [eax+0x10],0xf4306
0x00502869: c700ac67c400         mov DWORD PTR [eax],0xc467ac
0x0050286F: 894814               mov DWORD PTR [eax+0x14],ecx
0x00502872: e8d9810800           call 0x58aa50
0x00502877: e9a1020000           jmp 0x502b1d
0x0050287C: 33c0                 xor eax,eax
0x0050287E: 50                   push eax
0x0050287F: e8cc810800           call 0x58aa50
0x00502884: e994020000           jmp 0x502b1d
0x00502889: 8b5348               mov edx,DWORD PTR [ebx+0x48]
0x0050288C: 52                   push edx
0x0050288D: 57                   push edi
0x0050288E: e8ad06f2ff           call 0x422f40
0x00502893: 8bc8                 mov ecx,eax
0x00502895: e8c6ee0500           call 0x561760
0x0050289A: bf0f000000           mov edi,0xf
0x0050289F: 68b8dac000           push 0xc0dab8
0x005028A4: 8d47fc               lea eax,[edi-0x4]
0x005028A7: 8d4dd4               lea ecx,[ebp-0x2c]
0x005028AA: 897de8               mov DWORD PTR [ebp-0x18],edi
0x005028AD: 8975e4               mov DWORD PTR [ebp-0x1c],esi
0x005028B0: c645d400             mov BYTE PTR [ebp-0x2c],0x0
0x005028B4: e8578af0ff           call 0x40b310
0x005028B9: 8975fc               mov DWORD PTR [ebp-0x4],esi
0x005028BC: f605d4b0fa0001       test BYTE PTR ds:0xfab0d4,0x1
0x005028C3: 7521                 jne 0x5028e6
0x005028C5: 830dd4b0fa0001       or DWORD PTR ds:0xfab0d4,0x1
0x005028CC: c645fc01             mov BYTE PTR [ebp-0x4],0x1
0x005028D0: e8cb7a3000           call 0x80a3a0
0x005028D5: 68d0cdbc00           push 0xbccdd0
0x005028DA: e83bfa3800           call 0x89231a
0x005028DF: 83c404               add esp,0x4
0x005028E2: c645fc00             mov BYTE PTR [ebp-0x4],0x0
0x005028E6: 6828b0fa00           push 0xfab028
0x005028EB: 8d4dd4               lea ecx,[ebp-0x2c]
0x005028EE: e80d823000           call 0x80ab00
0x005028F3: 3bc6                 cmp eax,esi
0x005028F5: 7409                 je 0x502900
0x005028F7: 8b10                 mov edx,DWORD PTR [eax]
0x005028F9: 8bc8                 mov ecx,eax
0x005028FB: 8b4214               mov eax,DWORD PTR [edx+0x14]
0x005028FE: ffd0                 call eax
0x00502900: c745fcffffffff       mov DWORD PTR [ebp-0x4],0xffffffff
0x00502907: 837de810             cmp DWORD PTR [ebp-0x18],0x10
0x0050290B: 720c                 jb 0x502919
0x0050290D: 8b4dd4               mov ecx,DWORD PTR [ebp-0x2c]
0x00502910: 51                   push ecx
0x00502911: e8f6e83800           call 0x89120c
0x00502916: 83c404               add esp,0x4
0x00502919: 68c4000000           push 0xc4
0x0050291E: 897de8               mov DWORD PTR [ebp-0x18],edi
0x00502921: 8975e4               mov DWORD PTR [ebp-0x1c],esi
0x00502924: c645d400             mov BYTE PTR [ebp-0x2c],0x0
0x00502928: e83be93800           call 0x891268
0x0050292D: 83c404               add esp,0x4
0x00502930: 894598               mov DWORD PTR [ebp-0x68],eax
0x00502933: c745fc02000000       mov DWORD PTR [ebp-0x4],0x2
```

**可達 call sites（此局部區間）**

- `0x00502872 call 0x58aa50`
- `0x0050287F call 0x58aa50`
- `0x0050288E call 0x422f40`
- `0x00502895 call 0x561760`
- `0x005028B4 call 0x40b310`
- `0x005028D0 call 0x80a3a0`
- `0x005028DA call 0x89231a`
- `0x005028EE call 0x80ab00`
- `0x005028FE call eax`
- `0x00502911 call 0x89120c`
- `0x00502928 call 0x891268`

**可達分支（此局部區間）**

- `0x00502877 jmp 0x502b1d`
- `0x00502884 jmp 0x502b1d`
- `0x005028C3 jne 0x5028e6`
- `0x005028F5 je 0x502900`
- `0x0050290B jb 0x502919`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
