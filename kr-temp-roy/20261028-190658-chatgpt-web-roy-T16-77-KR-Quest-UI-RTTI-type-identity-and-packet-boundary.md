# KR T16-77 — Quest UI RTTI 原生型別定位、引用結構及封包界線

- 研究時間：20261028-190658 Asia/Taipei；研究者：chatgpt-web roy；**KR only**。
- 本輪唯讀驗證 `/mnt/data/Tartaros.bin` 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE32 section map：`.text` VA `0x00401000` / raw `0x400`；`.rdata` VA `0x00BD2000` / raw `0x007D0600`；`.data` VA `0x00D61000` / raw `0x0095E800`。下表的名稱原文在 `.data`，其 VA 必須按 `.data` 映射，**絕不能套 `.text` 映射**。
- 靜態分析，沒有執行／patch／附加原始遊戲程式；沒有封包截取、Server 原碼或外部 Quest 資源。

## 1. 研究問題與上一段修正

T16-75 已證明 `kRequestAcceptQuest`、`kAcceptedQuest` 等數字對應本地化 XML 索引，而非已證實的網路 opcode。T16-76 的 `HasQuest` 等名稱屬 ShoutTable 條件解析，而非已證實的 Quest 封包 handler。本段據此改以 Client Quest UI 真實型別作逆向起點：嘗試由型別 → 實際使用者／UI 點擊 → packet builder 或 Quest cache writer 連結。**此處的型別定位不能代替業務行為證據。**

## 2. 第一輪 T16-77：原始名稱、型別描述器與候選引用

BIN 內存在 MSVC 裝飾型別名稱，從 `.?AV...@FUI@@` 原文解析出下表。`TypeDescriptor` 是根據名稱之前 8-byte 的 `vfptr/spare/name` x86 常見佈局推導；指標命中為完整 BIN 的 4-byte little-endian 精確搜尋。兩者需跟具體 RTTI 使用者驗證，不等於已找到 ctor/vtable。

| 原始 UI 類別（名稱） | name raw | TypeDescriptor VA（推定） | 指向 TypeDescriptor 的候選 raw offsets |
|---|---|---|---|
| `CQuestListDlg` | `0xB7E30C` | `0x00F80B04` | `0x86D020`, `0x86D044` |
| `CQuestListItem` | `0xB82D7C` | `0x00F85574` | `0x87444C`, `0x874488` |
| `CTutorialQuestDlg` | `0xB7FFC0` | `0x00F827B8` | `0x86F5C0`, `0x86F5E4` |
| `CMissionConditionQuestList` | `0xB839A0` | `0x00F86198` | `0x875CBC`, `0x875CF8` |
| `CMissionConditionQuestListItem` | `0xB839D0` | `0x00F861C8` | `0x875D20`, `0x875D5C` |
| `CQuestNormalDetailDlg` | `0xB7E2C8` | `0x00F80AC0` | `0x86CFD4`, `0x86CFF8` |
| `CQuestScenarioDetailDlg` | `0xB7E280` | `0x00F80A78` | `0x86CF88`, `0x86CFAC` |

### 原件附近的資料摘錄

```
raw 0x86D020: 04 0b f8 00 28 ea c6 00 00 00 00 00 00 00 00 00 02 00 00 00 38 ea c6 00 44 ea c6 00
raw 0x86D044: 04 0b f8 00 01 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 28 ea c6 00
raw 0x87444C: 74 55 f8 00 54 5e c7 00 00 00 00 00 00 00 00 00 08 00 00 00 64 5e c7 00 88 5e c7 00
raw 0x874488: 74 55 f8 00 07 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 54 5e c7 00
raw 0x86F5C0: b8 27 f8 00 c8 0f c7 00 00 00 00 00 00 00 00 00 02 00 00 00 d8 0f c7 00 e4 0f c7 00
raw 0x86F5E4: b8 27 f8 00 01 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 c8 0f c7 00
raw 0x875CBC: 98 61 f8 00 c4 76 c7 00 00 00 00 00 00 00 00 00 08 00 00 00 d4 76 c7 00 f8 76 c7 00
raw 0x875CF8: 98 61 f8 00 07 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 c4 76 c7 00
raw 0x875D20: c8 61 f8 00 28 77 c7 00 00 00 00 00 00 00 00 00 08 00 00 00 38 77 c7 00 5c 77 c7 00
raw 0x875D5C: c8 61 f8 00 07 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 28 77 c7 00
raw 0x86CFD4: c0 0a f8 00 dc e9 c6 00 00 00 00 00 00 00 00 00 02 00 00 00 ec e9 c6 00 f8 e9 c6 00
raw 0x86CFF8: c0 0a f8 00 01 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 dc e9 c6 00
raw 0x86CF88: 78 0a f8 00 90 e9 c6 00 00 00 00 00 00 00 00 00 02 00 00 00 a0 e9 c6 00 ac e9 c6 00
raw 0x86CFAC: 78 0a f8 00 01 00 00 00 00 00 00 00 ff ff ff ff 00 00 00 00 40 00 00 00 90 e9 c6 00
```

上列內容為實際 BIN 位元組，而非反編譯器推斷字串。可看見每個 TypeDescriptor 往往至少被兩個靜態資料結構引用。`0x00F85554` 是 `CQuestListDlg` 的 TypeDescriptor 候選指標，而相應引用見 raw `0x8743F0`、`0x874424`；`0x00F85574` 是 `CQuestListItem` 候選指標，其引用見 raw `0x87444C`、`0x874488`。

## 3. 第二輪 T16-77-2：來源分類及有限否證

- 逐筆把 `.data` 原文 VA 與 `.rdata` 候選引用位置隔離，確認如 `0x8743F0` 對應 `.rdata` VA `0x00C75DF0`，不是程式碼入口。
- 在指定 `CQuestListDlg` / `CQuestListItem` / `CTutorialQuestDlg` / `CMissionConditionQuestList` 的候選引用上，查找指向各記錄首地址的 raw pointer，未發現直接的程式碼 caller；記錄間的 pointer 關係屬同一組 RTTI metadata 的可能性高，但其精確 COL/CHD 層級尚未完全逆出。
- 以上掃描不能排除 vtable[-1] 之 COL、使用基址加索引、動態指標或編譯器不同 RTTI 佈局。未找到 direct pointer，**不等於** UI 類別在遊戲中沒有被建立或呼叫。

## 4. 第三輪 T16-77-3：封包／狀態寫入接合測試

本輪檢查跨前段導航來源的證據邊界：

- 前段已找到 C→S 通用 `WSASend` 入口與 S→C frame → queue worker 流程。此處新增的型別描述器**沒有建立** `NPC click → CQuestListDlg click handler → RequestAcceptQuest packet builder → queue` 的原生呼叫鏈。
- 沒有從這些 RTTI record 直接連接到 `Quest accepted/completed` 的 S→C consumer，也沒有證明 `Quest16 → Quest15` 的 mapping 或角色任務 cache writer。
- 因缺少具名 UI ctor/dtor 與 callback target 的交叉驗證，沒有把 `CQuestListDlg` 假定成某一個具體 VA 的 click function；保持 **unknown**。
- 對 3 輪工作量的證據認定：只取得 UI class identity/navigation 的有限新資料，未閉合有用業務功能鏈；依共用三輪門檻可終止 T16-77，不能誇稱已完成 Quest 封包分析。

## 5. 玩家操作／封包證據矩陣

| 玩家情境 | Client 本地 gate | C→S | S→C | Client cache／UI | 相容 Server 待開發 |
|---|---|---|---|---|---|
| 開啟任務列表 | 有 `CQuestListDlg` 型別原文；實際 caller unknown | unknown | unknown | UI 類別存在；顯示來源 unknown | 不得由 RTTI 猜測 |
| 點 NPC 接取任務 | unknown | opcode、欄位、發送時機 unknown | accepted/failed 實際 handler unknown | Quest 狀態寫入 unknown | 接受／拒絕的 wire 格式待證 |
| 任務完成、下個任務可接 | unknown | unknown | 完成／解鎖消息 unknown | Quest16→15 unknown | server 規則不可猜 |
| 教學場景啟動 | 前段已確認本機 gate / 4-byte message | 已有 socket 一般寫出路徑，但個別 wire message mapping 待驗 | unknown | unknown | 待證回覆與任務效果 |

## 6. 接棒與驗收

1. **T16-78** 優先從 UI 物件的實際使用者、事件 callback table 或由 Quest cache writer 訪問者反推。若走 MSVC RTTI，須解析 COL → vtable[-1] → vtable 與具體 constructor 寫入，不能停在 TypeDescriptor。
2. 優先找到 CQuestListDlg 真正的按鈕 handler 與 `CQuestListItem` 的實際選項 callback；再沿產生的 C→S buffer 到已確認 queue，確認正式 opcode/length。
3. 由角色 Quest list cache 被修改位置，反向追 S→C 可能 payload 與 opcodes，再接回 T02 收包業務 dispatcher。
4. QuestInfo.xml / TutorialBase.lua 原件未在本輪取得，仍保持未知，不冒稱已證明 Quest16/15 前置。
5. 原稿只放 `kr-temp-roy/`，不得修改其他任務 owner/catalog 或上傳原版二進位檔。

## 7. 三輪總結及證據等級

- 原生確立：KR 原件 SHA、節區映射、Quest UI 類別裝飾名稱字節、精確 pointer hits 與 metadata 內容。
- 合理推測：TypeDescriptor / RTTI 資料結構分類；未驗到類別 constructor 的實際 vptr 寫入。
- Unknown：UI 事件 callback、接取 Quest C→S 實際 wire opcode、Quest 完成 S→C handler、NPC 更新／劇情效果。
- **三輪均未達重大完整業務功能鏈門檻；按照專案規定正式進度可轉 T16-78，不可稱 Quest 封包已還原。**