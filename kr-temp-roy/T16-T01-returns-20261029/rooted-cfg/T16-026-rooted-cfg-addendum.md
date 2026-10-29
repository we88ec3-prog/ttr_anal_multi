# T16-026 — appendix rooted CFG / corrected instruction windows

Author-level supplementary native evidence at 2026-10-29T21:44:09.711276+08:00; original historical Git blob unchanged.

## 根據原始 KR BIN 的重解結果

下方只列**由指定函式入口沿正常直接控制流可達**的指令；原附錄從任意位址開始的錯誤解碼不保留。完整指令／分支／call graph 存放 `rooted-cfg/root-*.json`。不推定 SEH、跨函式虛擬呼叫及遊戲時序。

### Root `0x004AEDB0` → source problematic `0x004AEDB0`

- Root accessible native instructions: **269**; known conditional/direct/indexed branch edges: **23**; `call` instruction sites: **31**.
- Start status: **reachable instruction start**.
- Containing reachable instruction: `004AEDB0: 55                             push ebp`.
- Unknown indirects: **0**; bounded graph exceptions: **0**.

```asm
0x004AEDB0: 55                   push ebp
0x004AEDB1: 8bec                 mov ebp,esp
0x004AEDB3: 83e4f8               and esp,0xfffffff8
0x004AEDB6: 6aff                 push 0xffffffff
0x004AEDB8: 688c979300           push 0x93978c
0x004AEDBD: 64a100000000         mov eax,fs:0x0
0x004AEDC3: 50                   push eax
0x004AEDC4: 81ec30050000         sub esp,0x530
0x004AEDCA: a1201fd600           mov eax,ds:0xd61f20
0x004AEDCF: 33c4                 xor eax,esp
0x004AEDD1: 89842428050000       mov DWORD PTR [esp+0x528],eax
0x004AEDD8: 53                   push ebx
0x004AEDD9: 56                   push esi
0x004AEDDA: 57                   push edi
0x004AEDDB: a1201fd600           mov eax,ds:0xd61f20
0x004AEDE0: 33c4                 xor eax,esp
0x004AEDE2: 50                   push eax
0x004AEDE3: 8d842440050000       lea eax,[esp+0x540]
0x004AEDEA: 64a300000000         mov fs:0x0,eax
0x004AEDF0: 8b450c               mov eax,DWORD PTR [ebp+0xc]
0x004AEDF3: 8b7508               mov esi,DWORD PTR [ebp+0x8]
0x004AEDF6: 83f802               cmp eax,0x2
0x004AEDF9: 7304                 jae 0x4aedff
0x004AEDFB: 33d2                 xor edx,edx
0x004AEDFD: eb0d                 jmp 0x4aee0c
0x004AEDFF: 8d48fe               lea ecx,[eax-0x2]
0x004AEE02: b8398ee338           mov eax,0x38e38e39
0x004AEE07: f7e1                 mul ecx
0x004AEE09: c1ea02               shr edx,0x2
0x004AEE0C: 85d2                 test edx,edx
0x004AEE0E: 0f84ab030000         je 0x4af1bf
0x004AEE14: 83c606               add esi,0x6
0x004AEE17: 8954241c             mov DWORD PTR [esp+0x1c],edx
0x004AEE1B: f6052cb2fa0001       test BYTE PTR ds:0xfab22c,0x1
0x004AEE22: 752f                 jne 0x4aee53
0x004AEE24: 830d2cb2fa0001       or DWORD PTR ds:0xfab22c,0x1
0x004AEE2B: c784244805000000000000 mov DWORD PTR [esp+0x548],0x0
0x004AEE36: e855fe0200           call 0x4dec90
0x004AEE3B: 6830cebc00           push 0xbcce30
0x004AEE40: e8d5343e00           call 0x89231a
0x004AEE45: 83c404               add esp,0x4
0x004AEE48: c7842448050000ffffffff mov DWORD PTR [esp+0x548],0xffffffff
0x004AEE53: 0fb756fc             movzx edx,WORD PTR [esi-0x4]
0x004AEE57: 8d442418             lea eax,[esp+0x18]
0x004AEE5B: 50                   push eax
0x004AEE5C: 8d442430             lea eax,[esp+0x30]
0x004AEE60: b938b1fa00           mov ecx,0xfab138
0x004AEE65: 8954241c             mov DWORD PTR [esp+0x1c],edx
0x004AEE69: e892003800           call 0x82ef00
0x004AEE6E: 8b44242c             mov eax,DWORD PTR [esp+0x2c]
0x004AEE72: 3b053cb1fa00         cmp eax,DWORD PTR ds:0xfab13c
```

**可達 call sites（此局部區間）**

- `0x004AEE36 call 0x4dec90`
- `0x004AEE40 call 0x89231a`
- `0x004AEE69 call 0x82ef00`

**可達分支（此局部區間）**

- `0x004AEDF9 jae 0x4aedff`
- `0x004AEDFD jmp 0x4aee0c`
- `0x004AEE0E je 0x4af1bf`
- `0x004AEE22 jne 0x4aee53`

## T01 退回的原生反證／實際函式入口

- `0x4ADD88`: `C7 80 F4 09 00 00 B0 ED 4A 00` = `mov dword [eax+0x9F4],0x4AEDB0`；receiver 建構者明確將此 VA 登錄為 callable。
- `0x4AEDB0`: `55 8B EC` = `push ebp; mov ebp,esp`。此處是獨立函式起點，具完整正常返回路徑 `0x4AF1E7 ret 0xC`；root→ret 被正常直接 CFG 收錄。
- `0x4AEDAF` 從錯誤相鄰位元組硬解成 `00 55 8B add [ebp-0x75],dl` 並**不能**否證有獨立的函式入口 `0x4AEDB0`；前一區域含疑似跳轉表／資料。
- 因此舊 T01 `T01-RETURN-T16-026-c26518b1` 若僅以 `4AEDAF` 線性解碼排斥原附錄 `4AEDB0` 的 `push ebp`，應由 T01 重新審核；保留原始退回狀態，不自行改成 RESOLVED。

## 限定證據與驗收狀態

本篇已將具體舊附錄錯誤視窗由 rooted reachable instructions 重解、產出對應呼叫與分支清單；但**並未手工逐條重寫歷史全文的所有結論／依賴**。此為新勘誤補證而非替代歷史原稿／T01 FULL-PASS。正規提交及狀態更新需依使用者授權與 T01 正式流程。
