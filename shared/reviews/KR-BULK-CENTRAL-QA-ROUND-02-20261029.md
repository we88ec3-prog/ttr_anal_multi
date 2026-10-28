# KR Bulk 集中品質檢查 — 第二段（2026-10-29）

**檢查分類：PARTIAL / NAVIGATION-ONLY / NOT FULL-PASS。** 此文件供所有 Task 查詢；只記錄在本輪實際核對的狀態，不修改 T01 正式驗收或 shared/verified-knowledge。

## 1. 基準

- Repository: `we88ec3-prog/ttr_anal_multi`; 獨立品質工作分支：`extra/roy2`，由 `main` 建立。本批不合回 main。
- 本地原件：`Tartaros.bin`，12,472,320 bytes，實算 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 本地 PE header 直接核對：PE32 x86、ImageBase `0x00400000`，`.text` RVA `0x1000`、raw `0x400`、raw size `0x7D0200`；`.rdata` RVA `0x7D2000`、raw `0x7D0600`；`.data` RVA `0x961000`、raw `0x95E800`。
- 映射公式（限定 .text）：`raw = VA - 0x00400000 - 0x1000 + 0x400`。
- GitHub connector 分別讀回四份完整 `functions/*.c`；對照本地原件入口 48 bytes。**未能取得完整 Git checkout 作全量 SHA / raw batch 驗證**，故不能自稱全量重新審核。
- 既有第一段：`KR-BULK-CENTRAL-QA-20261029.md`（本工作分支亦保存），其中 GitHub 封存 111,054 及零失敗為凍結保存紀錄，不代表重新全量統計。

## 2. 原生 BIN 入口抽查（48 bytes／函式）

| VA | raw offset | Git blob SHA | 局部核對 |
|---|---|---|---|
| `0x004DF510` | `0x0DE910` | `3a0ce713aebc54dad99b07c04f7c3f988fbdf4e1` | SEH / cookie; warning globals overlap |
| `0x004F49A0` | `0x0F3DA0` | `620eb7e2111e17d2b42c0856c3439d2b883a0e0b` | SEH / stack cookie; source lists Table/_ActorList.xml |
| `0x004F3D80` | `0x0F3180` | `594ef1f53fef73451ec93c0392a40592baeb26b7` | SEH / cookie; pseudocode allocates tree-like nodes |
| `0x0055D7E0` | `0x15CBE0` | `f97fc525bd23944f312c3eb5db595313c3192f69` | Native entry contains pushes/calls; pseudocode repeats call pair |

### 實際入口 48 bytes

#### 0x004DF510 → 0x0DE910

```text
55 8b ec 6a ff 68 a4 44 94 00 64 a1 00 00 00 00 50 83 ec 14 53 56 57 a1 20 1f d6 00 33 c5 50 8d 45 f4 64 a3 00 00 00 00 8b 75 0c 8b 45 08 39 70
```

- 風險／未解：WARNING: Globals starting with '_' overlap smaller symbols at same address。
- 驗證界線：入口指令序列與已讀偽碼入口的局部堆疊/例外處理框架可對應；**尚未覆蓋完整 CFG、呼叫目標、vtable、變數型別與資料流。**

#### 0x004F49A0 → 0x0F3DA0

```text
55 8b ec 6a ff 68 d6 47 92 00 64 a1 00 00 00 00 50 81 ec 9c 01 00 00 a1 20 1f d6 00 33 c5 89 45 f0 53 56 57 50 8d 45 f4 64 a3 00 00 00 00 33 db
```

- 風險／未解：Resource role needs file/parser + CFG verification。
- 驗證界線：入口指令序列與已讀偽碼入口的局部堆疊/例外處理框架可對應；**尚未覆蓋完整 CFG、呼叫目標、vtable、變數型別與資料流。**

#### 0x004F3D80 → 0x0F3180

```text
55 8b ec 6a ff 68 a2 75 92 00 64 a1 00 00 00 00 50 83 ec 24 53 56 a1 20 1f d6 00 33 c5 50 8d 45 f4 64 a3 00 00 00 00 bb 01 00 00 00 33 f6 8b c3
```

- 風險／未解：WARNING globals overlap; node ownership unverified。
- 驗證界線：入口指令序列與已讀偽碼入口的局部堆疊/例外處理框架可對應；**尚未覆蓋完整 CFG、呼叫目標、vtable、變數型別與資料流。**

#### 0x0055D7E0 → 0x15CBE0

```text
55 8b ec 51 a1 f0 1e fe 00 53 56 8b 30 57 6a 00 68 f0 c2 8d 00 8b d8 e8 b4 7d 19 00 8b 33 bf 7c 02 c1 00 b8 ee d8 ff ff e8 83 7f 19 00 a1 f0 1e
```

- 風險／未解：Repeated calls may be unrolled code; no loop or semantic acceptance。
- 驗證界線：入口指令序列與已讀偽碼入口的局部堆疊/例外處理框架可對應；**尚未覆蓋完整 CFG、呼叫目標、vtable、變數型別與資料流。**

## 3. 下一段新增品質結論

1. **VA→RAW 映射實證**：四個指定位址皆落入原件 .text 原始 bytes 範圍，排除僅將 RVA 當 VA 的導航錯誤。
2. **函式入口有限相符**：四個入口均有 x86 prologue bytes，對應 GitHub 四份偽碼宣稱的本地函式入口；這不代表完整函式邊界或語意正確。
3. **特定警告應分群**：`0x004DF510` 與 `0x004F3D80` 的偽碼出現 overlapping globals warning，需比對實際資料載入寬度與同位址符號；屬反編譯品質警告，不應自動視為原生 bug。
4. **重複呼叫暫不命名為事件迴圈**：`0x0055D7E0` 偽碼大量重複 `FUN_006f55b0` 與 `FUN_006f5790`；原生入口確有 call，未沿函式全程證實重複次數、目的與終止條件。
5. **資源相關函式不得跨領域誤用**：`0x004F49A0` 偽碼有 `Table/_ActorList.xml` 字串參考，但仍需查證原生字串交叉引用、真正解析器和欄位消費者。

## 4. 跨 Task 查詢狀態

| 類別 | 可用結果 | 不可推論 |
|---|---|---|
| 原件版本與 .text 映射 | 四入口已作 BIN 直接抽樣 | 全量函式地址/大小皆正確 |
| 函式導航 | GitHub 四份 `functions/*.c` 有讀回 | 已完成 raw ↔ pseudocode 全文 SHA 驗證 |
| SEH/stack prologue | 四入口 bytes 有限確認 | 全函式 CFG/例外處理邏輯 |
| Globals overlap warning | 兩個指定入口確認偽碼警告 | 原程式有記憶體覆蓋錯誤 |
| 狀態 | PARTIAL、非 FULL-PASS | T01 已正式驗收、Server 規格已恢復 |

## 5. 後續本地集中驗證佇列

- P0：列舉完整 `index.jsonl` 的唯一地址與 `status`，逐筆核對 `pseudocode_sha256`、`batch_sha256`／`seed_evidence_sha256` 與實際 Git 文件。
- P0：從 raw Ghidra source/機器碼擷取上述四函式完整區間及 call/jump CFG，確認局部入口之後的語意。
- P0：對所有警告建立類型 × 地址 × 來源 SHA 的可查詢索引，嚴格區分工具警告與確認原生錯誤。
- P1：替 `lookup.py` 建立唯讀加速索引前先評估搜尋熱點；保持 frozen 原始資料唯讀。
- P1：T01 依精確主張、來源 blob SHA 與正式驗收程序處理 FULL-PASS；本檔不可自行提升。

## 6. 已知限制與權限

原件只做離線位元組讀取，沒有執行、附加、patch、上傳 EXE/BIN。沒有修改其他 Task 的 owner、catalog、task.json、原始研究原稿。本工作分支的品質檢查報告**不是** `shared/verified-knowledge/` 正式條目；跨 Task 引用請註明來源與 PARTIAL 範圍。
