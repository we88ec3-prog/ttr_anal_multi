# SPEC-FLOW-0001 — KR 登入 → 選服連線 → 角色清單 → 選角 → 場景交接

**狀態：DRAFT / PARTIAL；流程契約尚未閉合，不可作為可連線 Server 完整實作規格。** 對象：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此文件提供開發者的**已知步驟／未知前後條件**，不是推定原版官方 Server 設計。

## 有界證據對照

| Client 階段 | 可觀察且有來源的事實 | Server 開發需要但仍未知的部分 | 關聯 |
|---|---|---|---|
| 1. C→S 認證請求 | Client 可產生 E8/112-byte 或 000F/214-byte 兩種不同的本地 payload，不能互用 | 依 launcher/mode 的完整入口、選擇哪種命令的先後時序、E8 opaque bytes、Server 官方驗證方式 | [SPEC-AUTH-0001](SPEC-AUTH-0001.md) |
| 2. S→C 登入結果 | `0x4C37A0` 在 status=0 且 +2 wide 名稱非空時進資料更新；status5 為不同非成功分支；群組/頻道資料有 3+10 bytes 消費格式 | 完整 response opcode、欄位/長度/有效值、token/租約、各分支後的下一則訊息；此處**不假定**一個回覆必然導致切線 | SPEC-AUTH-0001 |
| 3. 連線/選服 | 三個有界 KR Connect callsite 指向 port 8415(slot1)、8416(slot0)、8414(slot2)，其 pipeline 參數皆為2；這是**靜態 Client 路徑** | 是否在同一條 runtime 路徑依次連三個埠、真正選服觸發點、endpoint 權威、Session handoff/重連時序 | [SPEC-NET-0002](../protocol/SPEC-NET-0002.md) |
| 4. S→C 角色清單 | handler index2 使用有效路徑上的 `65+53*N` payload；選定 record 欄位可寫入 UI 資料 | 65-byte prefix 業務值、帳號授權、有效資源與 UI 更新、完整角色初始化回覆鏈 | [SPEC-CHAR-0001](SPEC-CHAR-0001.md) |
| 5. C→S 角色選擇 | T03 現有研究觀察到 command 42 的 4-byte 候選請求 | 42 的完整權威欄位、成功/失敗 S2C response pairing、角色初始化/切線狀態 | SPEC-CHAR-0001 |
| 6. Client 場景/教學資源 | `Event/SceneList.xml` 包含 `(1001,1)→tutorial_start` 靜態列；Client 有雙鍵 reader 組 `Event/Sequences/<funcName>.seq` 載入路徑 | **尚無原生關係證明**選角 `0x42` 回覆、首登旗標或任何 S2C payload 觸發 `(1001,1)`；也無法宣稱每個新角色必入教學 | [SPEC-SCENE-0001](../world/SPEC-SCENE-0001.md) |

**重要：**上表是不同研究覆蓋的相鄰功能，**不是已驗證的一條完整時序**。不得將表格的行順序寫成已觀察的原版 Client packet trace。

## 客戶端界面與 Server 設計分層

- **Client 相容規定**：只有精確已核對的 payload bytes/offsets、前提、handler 與分派邏輯可以作有限規格。
- **Server 自訂決策**：帳號驗證、DB、角色資料權威、首次登入條件、Session 維護方式，需獨立 ADR／需求，不可冒稱官方 Server 內部規則；決策也不能任意產生 Client 不認識的封包。
- **封包／資源分界**：`questIdx`、`sceneIdx`、`funcName` 是已確認的 Client 資源索引/腳本介面；**不是** `0x42` 回覆中已確認的三個網路欄位。

## 可交給獨立 Server 開發者的目前成果

可以分別實作 T02 framing 子集、E8/000F payload 解析、command2 roster 資料幾何，並於實作庫分開管理自己的帳號 Session；但**不能只依本文件完成原版 Client 的登入/選角/教學端到端運行**。

開發前的阻塞：`GAP-AUTH-0001`、`GAP-CHAR-0001`、`GAP-NET-0002`、`GAP-FLOW-0001`、`GAP-SCENE-0001`；研究請求 `RR-0002`、`RR-0003`、`RR-0005`、`RR-0008`。來源 `CLM-AUTH-0001/0002`、`CLM-NET-0007`、`CLM-CHAR-0001/0002`、`CLM-SCENE-0001..0004`，全部 PARTIAL。**本規格沒有新增 wire conformance fixture 或運行證據，不可升 STABLE。**
