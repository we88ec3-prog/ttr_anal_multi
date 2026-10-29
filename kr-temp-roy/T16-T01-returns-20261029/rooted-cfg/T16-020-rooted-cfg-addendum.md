# T16-020 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x00502270` → source problematic `0x00502460`

- Root accessible native instructions: **394**; known conditional/direct/indexed branch edges: **45**; `call` instruction sites: **53**.
- Start status: **NOT a reachable instruction start (interior of predecessor)**.
- Containing reachable instruction: `0050245D: 0f8496000000                   je 0x5024f9`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x0050244C: 8b0da4a7fb00         mov ecx,DWORD PTR ds:0xfba7a4
0x00502452: 8b11                 mov edx,DWORD PTR [ecx]
0x00502454: 8b4220               mov eax,DWORD PTR [edx+0x20]
0x00502457: ffd0                 call eax
0x00502459: 8bf8                 mov edi,eax
0x0050245B: 85ff                 test edi,edi
0x0050245D: 0f8496000000         je 0x5024f9
0x00502463: 8b17                 mov edx,DWORD PTR [edi]
0x00502465: 8b424c               mov eax,DWORD PTR [edx+0x4c]
0x00502468: 8bcf                 mov ecx,edi
0x0050246A: ffd0                 call eax
0x0050246C: 8b08                 mov ecx,DWORD PTR [eax]
0x0050246E: 8bb75c010000         mov esi,DWORD PTR [edi+0x15c]
0x00502474: 894de4               mov DWORD PTR [ebp-0x1c],ecx
0x00502477: 8b5004               mov edx,DWORD PTR [eax+0x4]
0x0050247A: 8955e8               mov DWORD PTR [ebp-0x18],edx
0x0050247D: 8b4008               mov eax,DWORD PTR [eax+0x8]
0x00502480: 8945ec               mov DWORD PTR [ebp-0x14],eax
0x00502483: 33c0                 xor eax,eax
0x00502485: 3bf0                 cmp esi,eax
0x00502487: 7417                 je 0x5024a0
0x00502489: 398770030000         cmp DWORD PTR [edi+0x370],eax
0x0050248F: 740f                 je 0x5024a0
0x00502491: e86a4c2a00           call 0x7a7100
0x00502496: d99d54ffffff         fstp DWORD PTR [ebp-0xac]
0x0050249C: 33c0                 xor eax,eax
0x0050249E: eb0b                 jmp 0x5024ab
0x005024A0: 0f57c0               xorps xmm0,xmm0
0x005024A3: f30f118554ffffff     movss DWORD PTR [ebp-0xac],xmm0
0x005024AB: d98554ffffff         fld DWORD PTR [ebp-0xac]
0x005024B1: 668b7f04             mov di,WORD PTR [edi+0x4]
0x005024B5: dc05785ec500         fadd QWORD PTR ds:0xc55e78
0x005024BB: 83ec08               sub esp,0x8
0x005024BE: 8d4de4               lea ecx,[ebp-0x1c]
0x005024C1: 0fb7d7               movzx edx,di
0x005024C4: d845ec               fadd DWORD PTR [ebp-0x14]
0x005024C7: 8945d0               mov DWORD PTR [ebp-0x30],eax
0x005024CA: c745d498dac000       mov DWORD PTR [ebp-0x2c],0xc0da98
0x005024D1: 8945d8               mov DWORD PTR [ebp-0x28],eax
0x005024D4: d95dec               fstp DWORD PTR [ebp-0x14]
0x005024D7: 8945dc               mov DWORD PTR [ebp-0x24],eax
0x005024DA: d9e8                 fld1 
0x005024DC: 8945e0               mov DWORD PTR [ebp-0x20],eax
0x005024DF: d95c2404             fstp DWORD PTR [esp+0x4]
0x005024E3: d9ee                 fldz 
0x005024E5: d91c24               fstp DWORD PTR [esp]
0x005024E8: 51                   push ecx
0x005024E9: 52                   push edx
0x005024EA: e8518cf9ff           call 0x49b140
0x005024EF: 8d55d0               lea edx,[ebp-0x30]
0x005024F2: 8bc8                 mov ecx,eax
0x005024F4: e827fa0400           call 0x551f20
0x005024F9: 8b4328               mov eax,DWORD PTR [ebx+0x28]
0x005024FC: 898550ffffff         mov DWORD PTR [ebp-0xb0],eax
0x00502502: e889d8ffff           call 0x4ffd90
0x00502507: 8bf0                 mov esi,eax
0x00502509: 8d8d50ffffff         lea ecx,[ebp-0xb0]
0x0050250F: 51                   push ecx
0x00502510: 8d8554ffffff         lea eax,[ebp-0xac]
0x00502516: 8bce                 mov ecx,esi
0x00502518: e8d31b0700           call 0x5740f0
0x0050251D: 8b7604               mov esi,DWORD PTR [esi+0x4]
0x00502520: 8b8554ffffff         mov eax,DWORD PTR [ebp-0xac]
0x00502526: 3bc6                 cmp eax,esi
```

**可達 call sites（此局部區間）**

- `0x00502457 call eax`
- `0x0050246A call eax`
- `0x00502491 call 0x7a7100`
- `0x005024EA call 0x49b140`
- `0x005024F4 call 0x551f20`
- `0x00502502 call 0x4ffd90`
- `0x00502518 call 0x5740f0`

**可達分支（此局部區間）**

- `0x0050245D je 0x5024f9`
- `0x00502487 je 0x5024a0`
- `0x0050248F je 0x5024a0`
- `0x0050249E jmp 0x5024ab`

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。