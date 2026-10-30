# T01 — extra/roy2 反編譯 QA 分支審核與 main merge（2026-10-31）

## 分支與 merge 適格裁決

- 起始 `main`：`412a2374a7c6c56de8ab881bcac8c9caa8aaac5c`；`extra/roy2`：`d3c7b3bcc494d80c2607f19272c07748bae7956a`，`ahead 47 / behind 473`。
- 兩邊 GitHub compare 得到 **25 筆 added、0 modified、0 deleted**；都位於 `shared/reviews/`，不涉及其他 Task owner/task.json、RR/S00、凍結的 `kr-bulk-roy`、已有共用 verified 原稿。
- **合併決議：適合真正雙親 merge commit**。以最新 main tree 為底，只新增 extra/roy2 的 25 份原始 blob（16 輪 QA 的 Markdown／README／json／txt／四份 Python tools），再追加由 T01 本輪編輯的台帳及驗收紀錄。保留 47 個來源 commit 的歷史，不將過時工作分支視為可以覆寫主線的狀態。
- **全面品質裁決**：歷史 QA 的「PARTIAL / NOT FULL-PASS」「BLOCKED-FULL-DATA」「FULL-PASS CANDIDATE」原稿不改字；合併指**歷史來源及工具可以共享**，不等於整批反編譯、111,054 函式通過 T01。

## R0 來源收件

本次在 `research/intake/index.json` 登記 `SRC-0493..0508`（第 01～16 輪原報告的 Git blob SHA、UTF-8 SHA256、原件版本），新增工具／JSON 原始 blob 路徑保留在 `shared/reviews`。

| 範圍 | 本次整合判定 | 限制 |
|---|---|---|
| Round01 摘要 | REGISTERED／SOURCE_ONLY | 舊完整 Round01 原稿未在這份分支逐字保存；不得把摘要充當全文 |
| Round02～03 | REGISTERED；四個 48-byte native 入口重跑通過 | 未做整函式 CFG／完整功能語意審核 |
| Round04～09 | REGISTERED；保存 QA 工具設計、修正與測試歷史 | 23/23 現行原始 Git blob 測試通過，不代表全量 data audit |
| Round10～11 | REGISTERED；保留 `BLOCKED-FULL-DATA` 的原始事實與局部 native bytes | 本輪沒有實際 111,054 筆 index→raw/functions 全量 QA |
| Round12～15 | CONFLICT_CHECKED，僅指定 native dataflow 的有界 claims | 72 名稱註冊和 Rebind/VM 未完成 runtime/所有 writer |
| Round16 | CONFLICT_CHECKED，精確零回傳 stub 的 T01 R3 已另行通過 | 原稿所有其他推論／72 個 script API 不因此 FULL-PASS |

## 工具程式碼與 23 個實際 unittest

T01 透過 GitHub 原始檔逐 byte 重建四份工具與測試，以 `git hash-object` 相同算法逐一核對來源 Git blob：
- `bulk_integrity_audit.py` = `7c863ce2f4d997825268a254356d96c2c1678730`
- `kr_bulk_preflight.py` = `658e96d757a1cff28064353954b5e3e4e874e88f`
- `test_bulk_integrity_audit.py` = `586fd0b908ae97f3420418faae171b1d79f83cdc`
- `test_kr_bulk_preflight.py` = `147dec265fc23ab6d8cae1bc8218237d28c69fb9`

執行 `PYTHONDONTWRITEBYTECODE=1 python -m unittest discover -s tools -p 'test_*.py' -v`：**23 tests, OK**。有覆蓋重複地址、JSON 破損、hash 不符、逃逸路徑、preflight 不足行數等 fixture。這是小型 fixture 測試，**不是**原始 111,054 行全量驗證；原始 bulk 的另一次已凍結備份驗證 `shared/integrations/T01-BULK-20261026-02`，不得把它誤寫為「extra/roy2 本次重新跑完」。

## 原生 Client BIN-first 完整有界核對

KR Tartaros.bin **12,472,320 bytes**、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE .text raw=VA−`0x400C00`，.rdata raw=VA−`0x401A00`。本輪唯讀核對：
1. Round02 原始 JSON 的 **四段 48-byte entry** `0x4DF510`、`0x4F49A0`、`0x4F3D80`、`0x55D7E0`：**4/4 完全吻合**。只是入口抽查。
2. Round14 的 `KR-BULK-CENTRAL-QA-ROUND-14-20261029-keys.json`：**72/72** 個 `BF <imm32>` native `mov edi,stringVA` 的指令起點及對應 NUL 結尾 `.rdata` 字串一致，原生 72 個鍵名彼此不同。非字串推測，非 API semantic。
3. `0x55D7E0..0x55E410` 區間：**72 次** `6A 00 68 F0 C2 8D 00`，不是 72 次實際函式呼叫。第一處 `0x55D7F0`，後 `0x55D7F7 call 0x6F55B0`。
4. **0x8DC2F0** raw `0x4DB6F0` bytes `33 C0 C3`，後有 `CC` padding，單基本塊無分支／callee，正常返回 `EAX=0`；RET 的 ESP/stack reader 必須保留。原稿 Round16 標「候選」，本 T01 在 [不分類共用知識](../../../shared/verified-knowledge/client-script-registration-zero-return-stub.md) 對**精確 3-byte 入口**正式給予 R3 FULL-PASS；`CLM-CLIENT-0063 NATIVE_VERIFIED`。
5. `0x55E590` Rebind callback 是 `mov eax,[FE1F20]; call 4A2BB0; mov [FE1F24],eax; xor eax,eax; ret`；`0x55E4F0` 初始寫 `[FE1F28]=0x5F5D10`；`0x55E620` 是經此指標間接 call 後固定 EAX=1 的有界鏈，獨立 handler `0x5F5D10` 是 ret-only。未盤點全體 writer，不得說 `DeleteAllObject` 永遠無效果。

## R1/R2/R3 整合主張

- `CLM-CLIENT-0063 NATIVE_VERIFIED`／`CK-CLIENT-SCRIPT-REGISTRATION-ZERO-STUB-01`：**僅入口 0x8DC2F0 正常執行 33C0C3 的直接效果**；這是此分支唯一提升的精確 R3。
- `CLM-CLIENT-0064 PARTIAL`：72 個 native script key 的原始註冊 source site，不代表工作 API／VM 呼叫成功。
- `CLM-CLIENT-0065 PARTIAL`：Rebind/Deletion 初始指標的局部 producer/consumer，不代表所有 runtime pointer writer、callback 生命週期、Client 功能或 Server 策略已閉合。
- 與主線 T16 Quest15 的 Lua binder / Scene VM 資料可能共用命名，但 **T16 的某一 callback 名稱不等於 72 個 key 的當前執行函式**；對同名異路徑不做品質繼承。
- Round03 的 silent JSON parse skip、duplicate address 等是原查詢工具的靜態風險，**未實測原凍結 index 損壞**。本 QA 新工具沒有直接修改 `kr-bulk-roy/lookup.py`，那些改進是待獨立修正的提案。

## S00／其他 Task 使用界線

**可用**：全 25 筆 QA 歷史、唯讀完整性工具、具來源的 72 字串 index、確定的零回傳 stub 及兩個 PARTIAL 功能線索。

**不可推論**：整個 decompiler index 111,054 都被新 QA 全量核驗、偽碼具實際原生遊戲語意、整個 script registration/VM 已還原、API stub 一定不會被重綁、任務／場景 Server 行為、玩法已通過。

**Client 待逆向**：`0x6F5790/6FB9A0` VM store、72 stub 是否在 runtime 被替換、`FE1F28` 全 writers、Script binder／Quest 的實際 consumer；`lookup.py` QA 提出的錯誤處理缺口可另訂來源修復。

**Server 待開發**：本批沒有新增可強制相容的官方 wire contract；不能因此建立任何新必需的 Server 業務 opcode。

**跨功能待整合**：Script/Story/Scene/T16 與原來 111,054 導航型 corpus 可相互引用；不修改 Task owner/README 或 RR、SPEC。

**待遊玩驗證**：無 Client 執行、官方 Server 連線、封包抓取、劇情／Lua 實際執行測試。

完整來源均原樣保留在 [shared/reviews](../../../shared/reviews/README-KR-BULK-QA.md)，可獨立使用本批 [BIN+QA 驗證器](revalidate.py)。T01 僅修改 SRC/CLM 台帳和共用 CK 索引，不覆寫 branch 的任何歷史報告。
