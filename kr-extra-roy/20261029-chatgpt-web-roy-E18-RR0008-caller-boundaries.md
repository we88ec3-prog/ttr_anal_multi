# E18 — RR-0008：本地場景切換的上游呼叫、初始化 gate、逐層參數傳遞及收包反證

2026-10-29 Asia/Taipei，跨 Task 工作線 `extra/roy1`。**第一手原始** `/mnt/data/Tartaros.bin`（12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；`.text` VA=raw+`0x400C00`。原版唯讀，無執行／patch。延續未推送 E17。GitHub main `5cb495f4561833e0a123bbded14b76266ac1f201`，RR-0008 仍 KR/T03/P0/QUEUED，非已公開認領；沒有變更 RR 台帳。

## 第一輪：確立 0x47D530 的唯一直接 E8 上游，以及反證觸發層級

本輪掃描 BIN `.text` raw 區所有 E8 rel32 直達 `0x47D530` 的指令，命中 `0x47D9DA`；同法對 `0x47B5C0` 只命中 `0x47D5B7`。這是**direct E8 的有界命中**，不排除 virtual/indirect dispatch。`0x47D9DA` 位於另一個函式較後面的 exception/cleanup 路徑（由 `0x47D9CE` 開始之區段）；它不是已證 S2C handler。請注意同一整段程式在 `0x47D93B` 寫 `arg+0xC=0x177`、呼叫 `0x5854B0`、`0x5740F0` 與 `0x58B270`，但**不能**直接把 `0x177` 宣告為 wire opcode。

```asm
47D9CE push eax
47D9CF call 0x539AF0
47D9D4 mov ecx,[ebp+0xC]     ; source object
47D9D7 mov edx,[ebp+8]       ; destination object
47D9DA call 0x47D530

47D554 mov esi,ecx
47D556 mov edi,edx
47D558 mov eax,[esi+0x248]
47D55E mov [edi+0x120],eax
47D564 mov eax,[esi+0x24C]
47D56A mov [edi+0x11C],eax
47D575 test byte [0xFC0F64],1
47D57D or dword [0xFC0F64],1
47D58A call 0x47DCE0        ; one-time local registration/helper
47D5A3 mov eax,[edi+0x120]
47D5A9 push eax
47D5AA push 0xFC0F68
47D5AF call 0x47E890        ; map/lookup candidate
47D5B4 push eax             ; actual argument, NOT src+0x24C
47D5B5 mov ecx,esi
47D5B7 call 0x47B5C0
47D5BD push edi
47D5BE call 0x47CDF0
47D5C2 mov ecx,[edi+0x100]
47D5CA call 0x47D610
47D5D8 mov eax,[esi+0x90]
47D5DF call eax              ; virtual callback
47D5E9 mov eax,[edx+0xC8]
47D5EF call eax              ; virtual callback
47D5F3 call 0x47D0B0
```

**新增結論**：`0x47D530` 的 side effects 不止 scene lookup：還會連續呼叫 `0x47CDF0`（對目的物件的後續處理）、`0x47D610`，以及 `dest+0x100` 所屬 interface 的 virtual `+0x90/+0xC8`；故應把它視為一條有條件的**物件場景切換／狀態交接流程**，不能把整個 function 簡化成封包 reader 或 quest pair translator。

## 第二輪：writer 值來源與是否能作為「網路選角回覆」

E17 `0x47CCxx` 的實際機器碼再次核對：

```asm
47CC29 mov ecx,[ecx+0xCC]   ; owner collection
47CC4B mov eax,[ecx+0xA8]   ; item pointer array base
47CC51 mov edi,[eax+ebx*4]
47CC58 mov edx,[edi]
47CC5A mov eax,[edx+4]
47CC5F call eax
47CC61 cmp eax,0x12D       ; local polymorphic type filter
47CC7E mov ecx,[esp+0x1C] ; other local array base
47CC82 mov eax,[ecx+ebx*4]
47CC87 mov byte [edi+0x26C],0
47CC8E mov edx,[eax]
47CC9E mov [edi+0x248],edx ; source item first dword
47CCA4 call 0x4026E0       ; copy item +4C -> dest +250
47CCB5 mov eax,[ebp+0xC]
47CCB8 mov [edi+0x24C],eax ; parameter rather than S2C buffer
47CD08 mov ecx,[edi+0x270]
47CD1D call edx            ; vtable +94 with derived boolean
47CD2F call edx            ; vtable +C8
```

**重要：** `0x47CC87` 的 `[edi+0x26C]` 是 `+0x248/+0x24C` writer **前**被置 0；`0x47B5C0` 的特殊 `0xEA61` gate 會讀 `+0x26C`。這是新確認的**初始化→寫入→consumer 條件關係**，但不證明兩函式必在同一 runtime request 連續執行，仍需 object identity/upstream。`0x12D` 是 item virtual return 的 filter，絕非可自行推斷的封包碼。

## 第三輪：補齊 0x47B5C0 的分支和兩個不同的下游表介面

```asm
47B5EB cmp dword [edi+0x248],0xEA61
47B5F5 jne 0x47B608
47B5F7 cmp byte [edi+0x26C],0
47B601 call 0x47B850         ; special-case only
47B608 test byte [0xFB73B8],1
47B620 call 0x560170         ; initialize scene-related singleton
47B63A mov eax,[ebp+8]      ; returned lookup object from 0x47E890
47B63D mov ecx,[edi+0x248]
47B643 push eax              ; second argument is lookup result
47B644 push ecx              ; first argument is +0x248
47B645 mov esi,0xFB73C0
47B64A call 0x565720         ; pair-driven scene helper
47B681 mov edx,[edi+0x24C]
47B687 mov ecx,[edi+0x248]
47B68D push edx
47B68E mov edi,0xFC0F68
47B693 call 0x47E750         ; uses two local fields, distinct from 565720 arguments
```

**可證的否定界線**：`0x565720` 收到的並非 `[+0x248],[+0x24C]` 原樣兩欄，因第二值由 `0x47E890` lookup 提供；`0x47E750` 才會收到 `+0x248,+0x24C`。單靠此鏈，不能說 `+0x248` 是 `questIdx` 或 `+0x24C` 是 `sceneIdx`，不能說它消費 `0x42` S2C 回覆，更不能將 XML 1001/1 升級為協定值。

## 跨 Task RR-0008 情境與目前證據等級

| 玩家情境 | Client 可證 | C→S | S→C | 本地結果/依賴 | 未解 |
|---|---|---|---|---|---|
| 選角後進世界 | 有場景物件 writer/複製/lookup/呼叫鏈，但未證出自選角 | T03 選角 0x42 有歷史資料，這一輪沒有重驗 socket | **UNKNOWN**：未找到本段 writer 的 S2C handler | T05/T07 scene controllers、T03 reply interface | 收包 handler→writer、reply payload、初次/重入條件 |
| CutScene 結束重入 | E16 已證 EndCutScene 可進 0x565720 | 不主張 | 不主張 | 本地 script/scene state reuse | 不可移植成首次登入規則 |
| local item list state transfer | `0x47CCxx` 按 type 0x12D 寫入欄位並操作 virtual objects | 不主張 | 不主張 | `0x47D530` 後續調用多個 UI/scene-like virtual methods | 完整 class/vtable 和上游 player action |

- **Client 待逆向**：由 `0x47D9DA` 向上找到 object identity 與哪個事件觸發；另從真正 T03 S2C dispatch 方向核對是否存在交會。
- **Server 待開發**：原生協定已證的選角狀態及場景需求明確後才設計相容回覆，不捏造 0x42 的反方向 opcode 或 1001/1 封包。
- **跨功能待整合**：T02 dispatch、T03 role state、T05 world transition、T07 scene，T01 有界 claim 審查。
- **待遊玩驗證**：沒有執行 Client 或取得原版流量，不能宣稱可玩。

## 重現與交付

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47cc20 --stop-address=0x47cd40 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47d530 --stop-address=0x47d610 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47d9ce --stop-address=0x47d9f3 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47b5c0 --stop-address=0x47b6a0 Tartaros.bin
```

三輪深入已執行：第一輪補直接 caller 和額外 virtual side effects；第二輪核對 writer 的 item array、`+0x26C` 初始化及不同來源；第三輪檢查 0xEA61 分支與兩種下游參數差異。這是有界新的資料流增量，**不是** RR-0008 完成或 S2C full pass。本次允許上傳本研究筆記至 extra/roy1；**RR 台帳仍 QUEUED**，不假稱 CLAIMED/SUBMITTED/ACCEPTED。