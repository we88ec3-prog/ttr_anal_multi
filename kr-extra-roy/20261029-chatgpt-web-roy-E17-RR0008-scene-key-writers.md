# E17 — RR-0008 跨 Task 補證：scene key writer、複製、狀態切換與選角回覆證據界線

日期：2026-10-29 Asia/Taipei；工作線：`extra/roy1`。本輪僅建立本機報告，未 Commit／Push、未改 RR 台帳或 main。

## 開工來源及狀態

- 原始 KR `Tartaros.bin`: 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；本輪以 `sha256sum` 重新核實。
- PE32 `.text` VA=raw+`0x400C00`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。只靜態反組譯，無 Client 執行、patch。
- `main` 中 RR 台帳 Git blob `6f652f1b763a4198bbc580f86cb9f7703001ffc3`：`RR-0008` KR/T03/P0/QUEUED，GAP-SCENE-0001、GAP-FLOW-0001；未獲正式 main 認領。不越權改狀態。
- 參照 main `kr/tasks/T03/README.md` 中 E01–E16 參考、FULL-PASS `shared/verified-knowledge/README.md`，以及 E16 原稿。此報告是跨 Task 原生資料補證；RR 正式 owner 仍 T03。

## 輪一：原生 `+0x248`、`+0x24C` 的直接 writer（重大增量）

這兩個欄位不是只有 `0x47B5C0` reader。已找到數個實際 **寫入位址及來源**：

```asm
47B4C6 or eax,0xffffffff
47B4C9 mov [esi+0x248],eax      ; 初始化 -1
47B4CF mov [esi+0x24C],eax      ; 初始化 -1

47B2DD mov eax,[edi]            ; 來源物件第一 dword
47B2EF mov [ebx+0x248],eax      ; 複製第一個場景/物件鍵
47B2E6 lea esi,[ebx+0x24C]
47B2F5 call 0x4026E0           ; 向第二欄所在結構複製來源 +8 起的內容

47CC58 mov edx,[edi]            ; item vptr
47CC5A mov eax,[edx+4]
47CC5F call eax                ; 呼叫 item 的 vtable+4
47CC61 cmp eax,0x12D           ; 僅匹配 type 0x12D 的 item 走入
47CC7E mov ecx,[esp+0x1C]
47CC82 mov eax,[ecx+ebx*4]     ; 取得本地項目
47CC8E mov edx,[eax]           ; 該項目首 dword
47CC9E mov [edi+0x248],edx     ; 第一鍵 writer
47CCB5 mov eax,[ebp+0xC]
47CCB8 mov [edi+0x24C],eax     ; 第二鍵來自函式參數
```

證據分級：`+0x248`/`+0x24C` 實際有這些 native write/copy **已確認**；`+0x248` 是否是 `questIdx`、`+0x24C` 是否是 `sceneIdx` **仍須看 consumer 傳參和 object type**；`0x12D` 是虛擬 callback 回傳的本地類型比較，**不是已證 wire opcode**。

### writer 的上游本地資料結構

`0x47CBDA` 以本地 vector end-begin 計算項目數；`0x47CC00` 從 `[edi+0xFC]→[+0xCC]` 讀本地物件，經 `[+0xA8/+0xAC]` 範圍迭代，`0x47CC4B` 取 `[ecx+0xA8+ebx*4]` item，再做 vtable+4 類型過濾。由此 **本段 writer 是本機物件／集合轉換流程**。目前沒有沿這個入口找到直接 socket receive buffer 或選角回覆 handler；不能把它稱為選角 S2C writer。

## 輪二：有界 scene key 傳遞及 lookup bridge

```asm
47D558 mov eax,[esi+0x248]
47D55E mov [edi+0x120],eax
47D564 mov eax,[esi+0x24C]
47D56A mov [edi+0x11C],eax
47D5A3 mov eax,[edi+0x120]
47D5A9 push eax
47D5AA push 0xFC0F68
47D5AF call 0x47E890       ; 從索引/表取相關物件，回傳待進一步型別驗證
47D5B4 push eax
47D5B5 mov ecx,esi
47D5B7 call 0x47B5C0       ; E16 場景入口
```

`0x47B5C0` 內：

```asm
47B5EB cmp dword [edi+0x248],0xEA61
47B5F7 cmp byte [edi+0x26C],0
47B600 push edi
47B601 call 0x47B850
47B63A mov eax,[ebp+8]
47B63D mov ecx,[edi+0x248]
47B643 push eax
47B644 push ecx
47B645 mov esi,0xFB73C0
47B64A call 0x565720
47B681 mov edx,[edi+0x24C]
47B687 mov ecx,[edi+0x248]
47B68E mov edi,0xFC0F68
47B693 call 0x47E750
```

最小可證：`0x47D530` 確實複製場景/物件雙欄 → 使用第一欄做 lookup → 將其結果傳給 `0x47B5C0`；`0x47B5C0` 在 `0xEA61` 特例外，把 `[edi+0x248]` 與傳入 arg 推給 `0x565720`，並在另一支以 `+0x248,+0x24C` 呼叫 `0x47E750`。**是否為 XML `(questIdx,sceneIdx)` 仍不能自動等同**：`0x47B5C0` 傳給 `0x565720` 的第二參數是其上游查找結果，而不直接是 `[edi+0x24C]`。這個區別禁止在 SERVER SPEC 中混寫。

## 輪三：首登/封包反證與後續需求

- E06/E08/E13–E16 已確認 XML 1001/1→tutorial_start、`.seq` 資源、Client scene tree 與 Lua loader；這些只證明資源及本地事件鏈。
- E17 新增了 **物件集合 → `+0x248/+0x24C` writer → `0x47D530` 讀出並跨物件傳遞 → `0x47B5C0` → `0x565720`** 的具體局部 producer/consumer 關係。但 upstream `0x47CCxx` 與 `0x47B2B0` 是否來自 T03 選角回覆仍 **UNKNOWN**。
- 首登 `0x42`：已知 T03 舊證只有選角 C2S；E17 尚未驗證 `0x42` 的 S2C 真實 handler、reply payload、socket transport，以及哪個字段驅動 `0x47CCxx`。不可把 C2S identifier 直接投影成 S2C opcode，亦不可將 `0xEA61` 或 1001/1 冒充原版 wire bytes。
- 需 T03/T02 定向追：收包 `0x4930E0` dispatch→選角 S2C handler→本地 `0x47CCxx`/`0x47B2B0` writer 或明確否證；找 `0x47D530` 的 caller/argument origin，確認進入 `0x47E890` 是哪些資料類型。需 T05/T07 核對場景/世界切換與 EndCutScene 重入分流。T01/S00 審核仍獨立。

| 玩家情境 | 已證 Client local | C→S | S→C | 玩家效果 | 相容 Server / 剩餘缺口 |
|---|---|---|---|---|---|
| 選角後的首次場景 | 存在本地雙欄 writer/read/scene loader 路徑，未證此情境實際到達 | T03 選角 C2S 有既有局部證據，未於本輪重驗精確封包 | 對應選角結果 handler 未確認 | 教學是否開啟未確認 | Server 需相容原生已證介面；scene result/fields 需先補證 |
| 既有 CutScene 恢復 | E16 已證 EndCutScene 可呼叫 0x565720 | UNKNOWN/不主張有 | UNKNOWN/不主張有 | 恢復場景本地控制部分確認 | 不得以此推斷首次登入封包 |

## 重現

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47b2b0 --stop-address=0x47b310 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47cbda --stop-address=0x47cccf Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47d530 --stop-address=0x47d5c2 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47b5c0 --stop-address=0x47b6ab Tartaros.bin
```

三輪：第一輪命中實際 writer 新證，第二輪跨物件 consumer 與 arg 來源，第三輪檢查首登/跨 Task 負證邊界；此研究已有 writer→consumer 有界功能鏈實質進展，未宣告官方 S2C 完成。分析原稿留本地待使用者明確授權 Push；RR 台帳保持 QUEUED。