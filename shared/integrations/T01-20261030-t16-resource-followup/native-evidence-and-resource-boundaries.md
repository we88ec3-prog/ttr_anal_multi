# T01 第二輪 KR 原生核對：來源成員、函式入口與 A0A4 gate

本文件為針對精確 16 筆退回問題的原生核對，不是全部來源函式/Script 的 CFG 或端到端語義報告。

## 一手來源及 hashes

- `Event.stp` 11241597 bytes：SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- `Tartaros.bin` 12472320 bytes：SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `Event/TutorialBase.lua`：容器 offset 10645520、長度1416；XOR 0xFF，header `1b4c75615100010404040800`；正確 SHA256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`。6 個 Lua5.1 prototype、72 instruction words。**原錯誤 `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` 僅56位。**
- 原成員由實際 carrier 切出，沒有從 Git 404 生成或推論 member 存在。最小重現程式見 [verify_tutorialbase_carrier.py](verify_tutorialbase_carrier.py)。

## 1. A0A4：有號 admission 比較與獨立增減數值

```asm
8060FA: 81 BE A4 A0 00 00 2C 01 00 00   cmp DWORD PTR [esi+A0A4],12C
806104: 7E 16                             jle 80611C  ; signed <=300 allows queue path
806106: 33 C0                             xor eax,eax ; >300 refuses
804ADF: 8B 86 A4 A0 00 00               mov eax,[esi+A0A4]
804AEB: 83 F8 05                        cmp eax,5
804AF0: C7 86 A4 A0 00 00 00 00 00 00   mov [esi+A0A4],0
804AFC: 83 C0 FB                        add eax,-5
804AFF: 89 86 A4 A0 00 00               mov [esi+A0A4],eax
804B13: 83 86 A4 A0 00 00 05            add DWORD PTR [esi+A0A4],5
```

- `0x804A40` 中 A0A4 update 受 `0x8061A0` draining-return、`0x804B07` flags/branches 控制；不是每次呼叫必然+5或-5。
- 比較 `0x804AEB cmp eax,5` 的 `jae` 是特定失敗/成功修補計算路徑；**不要**由此為 A0A4 指定 retry/backoff 甚至「排隊封包數」的業務名稱。

## 2. A078：list operation 同一連線的 enqueue/dequeue count

```asm
806071: 8B BE 74 A0 00 00  mov edi,[esi+A074]    ; list sentinel
806085: 8B 8E 78 A0 00 00  mov ecx,[esi+A078]    ; count
8060A1: 41                 inc ecx
8060A2: 89 8E 78 A0 00 00  mov [esi+A078],ecx   ; linked-list insert increments
8061E6: 8B 86 74 A0 00 00  mov eax,[esi+A074]   ; same type list base
8061EC: 8B 18              mov ebx,[eax]
8061EE: 3B D8              cmp ebx,eax           ; empty list sentinel?
806275: FF 8E 78 A0 00 00  dec DWORD PTR [esi+A078] ; drain node removal
```

- `8061A0` 0x8061F0 對 empty sentinel 走不同 path；`806275` 並非函式所有路徑均執行。條件式入列成功 `806060` count++ 與消費 `8061A0` count-- 在正確連線基準 `ESI` 上相互對照，支持本通知的正確標記。

## 3. 4AEDB0：獨立 callable callback，不可由鄰位 ADD 反推 invalid

```asm
4ADD88: C7 80 F4 09 00 00 B0 ED 4A 00  mov dword ptr [eax+09F4],004AEDB0
4AEDB0: 55                             push ebp
4AEDB1: 8B EC                          mov ebp,esp
4AEDB3: 83 E4 F8                       and esp,0fffffff8
4AF1E4: 8B E5                          mov esp,ebp
4AF1E6: 5D                             pop ebp
4AF1E7: C2 0C 00                       ret 0C
```

這是獨立跨函式入口的第一手原件佐證；`0x4AEDAF` 的 `00 55 8B` 是跨可能的資料/函式界線開始的錯誤線性解碼，不支配明確 callback 指標 `4AEDB0`。T01 當時「4AEDB0 在 4AEDAF 指令內」原反證不成立，故此 **退回項撤銷其依據並結案**。原函式整個 CFG、非本通知相關原稿主張及其 Quest-specific 效果仍待獨立核對。

## 4. 版本、作者與 S00 邊界

- 14 Lua source identity / one queue field / one false counterproof 是**通知修正驗收**，不是 16 篇原稿或 16 個函式完整語意。舊壞引用版繼續保留原 blob。
- 作者各 erratum 的來源 old/new SHA 精確映射在 JSON；絕不因 newer-file timestamp/空字串或 Git connector 404 宣告 source absent。
- 沒有外部 Server/Quest 回覆、沒有跨版本 TC 協定對應；相關 spec DRAFT/PARTIAL 不改。