# KR T08-160 — bounded lifecycle reconciliation and evidence gates

- 研究時間：2026-10-28T01:52:16+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：唯讀 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，GNU objdump 對 PE `.text` VA 反組譯。
- 正式 Task：GitHub KR T08 只負責 `0007` 實體建立／登記／移除的資料介面；dispatch 框架屬 T02、場景重置屬 T06/T07，僅交叉參照，不更動其他任務。
- 分級：**原始 bytes**／**已證局部 data-flow**／**有條件推論**／**未知**。線性反組譯與直接呼叫搜尋不代表完整 CFG；外部封包來源與 runtime 未驗證。
- 參照：`T08-153`、`T08-154`、`T08-155`、`T08-156`；上批保留的映射差異與 `T01-20261027-05` 部分驗收限制持續適用。
- 無遊戲執行、修改主程式、服務或存檔。本文不是可直接部署的 C++ 原始碼。

## 本批 T08-157～160 技術整合結論

延續原始 T08-xx 歷史連續編號，不以新段落覆蓋 GitHub 現有正式 claim。新增兩個可直接重現的重要結果：

1. `4B28D0` 接收候選入口包含最低長度門檻、actor 查找、kind 分支、三槽控制清理與按 WORD ID 刪除（T08-157）。
2. **修正 T08-154/156**：`40F060` 是返回 `0xFAB130` 的 lazy singleton getter，不是 key 轉換器。key 在 `4B3733` 由 `WORD|0x06000000` 建立、並透過 stack 交 `4DFC90`，只依 actor+0x88 選取對象（T08-158）。
3. `4DFBC0` 中**node+10 指標第一次經 virtual+14 使用之前沒有 null check**；這個 helper 的安全前提是 map invariant 而不是函式內一般性空檢查。vtable+0(1) 身分仍待具體 class 佐證（T08-159）。

### 1. 功能鏈比較

| 工作路徑 | 入口與來源 | 對象索引 | 移除執行 | 一手確認點 | 未證界限 |
|---|---|---|---|---|---|
| 0007 建立 | `4AE4D0` | WORD actor+4 | `4D1710`/`4DFF30` | 26-byte row 與 E8 對齊（T08-153 前證） | 生成來源/時間 |
| ID remove | `4B28D0` | 逐 WORD actor ID | `4DFBC0` | `4B2AB9/4B2AC2` | dispatch opcode 註冊 |
| conditional remove | `4B3710` | `(WORD|0x06000000)` vs actor+88 | `4DFC90` | `4B3733/38/39/3E` + `40F0B4` | 複合 key 語意 |
| alternate tree | actor manager+0x18 | 不同 key | `4DFC30` | 直接 `89120C` payload free | 不是 GameInfo+8 actor destructor |
| bulk by type | `4DFD40` | actor+4 低 BYTE | 依 kind 條件刪 | T08-153/159 本機反組 | 跳轉完整 caller |
| full clear | `4DFE90` | GameInfo+8 tree | actor 清理後 clear tree | T08-153/159 | 場景重置時序 |
| script object | `563A70` | `Q.this+18` DWORD | Q 對象與 script tree | T08-重審-02 | 不能與普通 actor 混算 |

### 2. 明確修正 / 不變結論

| 前段假設／措辭 | 本段處置 | 一手測試 |
|---|---|---|
| `40F060` 為 `0x06000000` 鍵值轉換 | **更正為 GameInfo lazy getter** | `40F0B4 mov eax,0xFAB130; ret` |
| `7B6890` erase 即銷毀 actor | **否定**：只解樹節點，物件清理由 caller 決定 | `4DFC1E` vtable/free 前置及 `7B6AC7` node free |
| `4DFBC0` 一般安全支援 null payload | **缺乏證據**：先行 virtual+14 使用 payload | `4DFBF8..4DFC00` |
| 所有移除都來自同一封包 | **否定普遍化**：存在分流、批次、腳本與全清 | T08-153..159 不同路徑 |
| flat dump 與 PE bytes 總可互換 | **否定**：PE `.text` +0x400，來源必分類 | 舊整合映射核對 |

### 3. 函式與物件欄位映射表（限定類型）

| 屬性 | 主體與欄位 | 已知讀／寫者 |
|---|---|---|
| 主樹 | GameInfo candidate `0xFAB130 +8` | `4DFF30`, `4DFBC0`, `4DFC90`, `4DFD40`, `4DFE90` |
| 主樹 sentinel | GameInfo candidate `+0x0C` | `4DFBDD`, `4DFC1E` 前等 |
| tree node actor payload | Node `+0x10` | `4DFBF8`, `4DFCB0` |
| actor ID | Actor `+0x04` (WORD) | `4DFF30`, `4B299B` |
| conditional key | Actor `+0x88` (DWORD) | `4DFC90` |
| controller | global `[0xFBA7A4]` vptr+0x1C | `4DFBE4...` |
| lazy receiver | getter `40F060` -> `0xFAB130` | `4B3739` caller |
| script tree | ScriptInstance `+0x18` | `562EC0`, `563A70` |

`+8/+10/+88` 的同 offset 在不同 object 類型不可混為一欄；未解析 owner 或 packet ID 不能填猜值。

### 4. 仍待核心確認 / 下批入口

1. **T02 dispatch 交界**：查 `4B28D0`、`4B3710` 在接收器註冊表的函式指標與 opcode，需原始 bytes；不能因封包形狀推論已驗證 opcode。
2. **具體 actor vtable**：追由 `4D1710`、`4D0B80` 等建立者寫入的 vptr，再定位 slot+0x14/+0x00 之實際目標，按 class 分別列 destructor flag(1) 語意，不把未覆蓋 class 全叫 CMonster。
3. **actor+0x88 key 來源**：追 writer/reader，證明 compound `0x06000000 | WORD` 是否與 entity 類型、關聯或地圖資料有關；不能僅由常數 6 命名。
4. **全清/重置**：`4DFE90` caller 連回 T06/T07，但場景建立或 reset 完整序列仍需 upstream CFG 證據。
5. **地址一致性**：同一指令的 PE raw 與反編譯 raw 錨點逐項檢查；避免舊 flat 映射帶來虛假 vtable 入口。

### 5. 提交與整合備註

- 本批四份 **完整版**：T08-157、158、159、160，保留原生反組譯、前後關係、偽碼、反證和缺口。
- 另有前批**本機尚未提交**六份完整版：整合重審-01/02、T08-153..156。正式 GitHub 是否已有同 SHA 副本需提交前比對，不以檔名或暫存目錄存在當作未整合的依據。
- 正式 task.json 依 AGENTS 分工流程，**不代為認領/更改**；所有報告可提交 `kr-temp-roy/`，其正式語意仍交由 T01 integrator 逐 SHA 評閱。
- 應由 GitHub 連接工具提交後遠端 `fetch_file` 重讀，核對 hash；若 GitHub 寫入無法取得本地原始 Markdown bytes，不以摘要冒充原始報告；以 ZIP + SHA manifest 交付。