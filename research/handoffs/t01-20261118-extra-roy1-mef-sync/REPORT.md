# T01 — extra/roy1 → main MEF 新增研究有限檢核（2026-11-18）

## 1. Git 整合事實

- 工作範圍：使用者指定將 `extra/roy1` 同步到 `main` 並執行 T01 檢核。
- 原 `main`：`7344eeb65198e2dd61684b66cf811021765ed8f5`。
- 新來源 head：`extra/roy1@4b440352fe3a4b031fd77b0814425a9f843e532e`。
- 共同祖先／上次檢核提交：`5ed4833b805949fabe260aea77e3fe0fd8e86bfa`。
- 分歧：來源分支 ahead 5、behind 15；相對共同祖先的新增差異 **277 個新增檔案，無同一比較中的修改或刪除，全部位於 `kr-extra-roy/`**。
- 實際整合：GitHub PR [#108](https://github.com/we88ec3-prog/ttr_anal_multi/pull/108)，以 merge commit 方式合併，`9fea52d1cdd336aa12f6ea8b0167b32559084672`。未 force push、未新建工作分支。
- 本文件屬整合後獨立 T01 有界紀錄，不聲稱重新執行研究者全部私有 verifier。

## 2. R0：來源身分、機械接收及範圍

- 本機唯讀 `Tartaros.bin` SHA-256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 本機唯讀 `Master.stp` SHA-256：`f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d`。
- GitHub `compare 5ed4833...4b440352` 所列 277 項均為 `added`，只在個人研究目錄；本次來源合併沒有直接修改正式 `research/intake/index.json`、`research/claims/index.json`、RR／REQ、Task owner 或其他 Task 原稿。
- `MEF-P0-P1-P2-continuation-20261118/artifact-manifest.json` 原件聲明 47 個 sealed files、1,332,732 bytes；作者已發布 `verification-result.json` 亦記載 47 檔，三個子題 runner 分別為 P0 exit0、P1 exit0、P2 `--require-native-mef` exit2，根 `--require-ready` 為 exit2。**此處核對的是公開 manifest／作者 receipt 相互符合，不是本輪獨立全檔 SHA 重算或重新執行三支 verifier。**
- `MEF-P0-level-execution-20261118/verification-result.json` 聲明 60 個 sealed files、21 Git sources、5 原件、28 個固定 Server 來源、171 Markdown links；作者 receipt 狀態 `PASS_BOUNDED_P0_LEVEL_EXECUTION_ANALYSIS`。**本輪沒有重新取得作者的私有 Server source snapshot，不能把該 receipt 稱為 T01 對私有 Server 原碼的獨立核查。**

## 3. R1：可採用的限定主張及矛盾界線

| 研究題 | 可以登錄為待進一步確認的有界主張 | 不得升格為完整原生／產品事實 |
| --- | --- | --- |
| P0 資源索引 | `fcs.flu` 的 reader 記錄、群組與條目索引、開檔失敗 fallback 的限定資料流；`group_count*0x158`／`entry_count*0x218` 是正常輸入的實體 layout | 沒有同版實際 `fcs.flu` 和 selected payload；不能聲稱實際角色／地圖 winner 或 ready |
| P1 普通 UI B | resource 212 對應 `UI/Component/TalkBox_Scenario_Panel.FTC`，talk root 的 `+18=self`、cache/reentry/detach 有界 native 鏈 | UI 首次建立不等於背景 Lua 首次執行、同 VM pump、script owner 取消已閉合 |
| P2 格式 | Master 的 Field carrier／`xml/mef` 包裝宣告與一般掛載流程分開；MapList trigger 名稱是字串，不是 MEF 已執行 | 無經核身分的官方 MEF payload→reader→parser→executor；不能稱 native grammar ready；亦不應以取得官方格式作為新 Server 自訂 MEF 開發的唯一先決 |
| P0-3～10 關卡 | 生怪／戰鬥、增援、清場、分支、時計、門、出口等研究者提供有界 Client、Server snapshot 與自訂內容設計對照 | 作者 Server snapshot/研究 fixture 不等於實際部署／原版 Server 規則；12 類 MEF 為玩家用途分類，不是12種原生副檔名或格式 |

本次特別採納兩個作者明示勘誤：`fcs` 成功正常返回並跳過全域 fallback 不能誤寫成索引已完整有效；普通 talk root owner `+18` 不能再寫成「必然非 talk 本身」。舊 MapList EDI root alias 必須止於 `4BADC2` 對 DI 的部分覆寫；並非全 EDI 清零。

## 4. R2：本輪獨立 BIN 定向 byte 交叉驗證

以指定 KR PE32 `.text` 映射（VA `0x401000` → raw `0x400`）於本機實體 BIN 定向讀 bytes：

| VA | raw | 實得 bytes | 限定結論 |
| --- | --- | --- | --- |
| `4BAD73` | `BA173` | `BF 70 74 FB 00` | `mov edi,0xFB7470`，舊 root 初值 |
| `4BADC2` | `BA1C2` | `66 8B 3D EA 90 FB 00` | `mov di,[0xFB90EA]`，只改低16位；反證「後續 EDI 完整不變」 |
| `4BAE70` | `BA270` | `0F BF D7` | `movsx edx,di`，取被覆寫後的 DI |
| `799170` | `398570` | `E8`（call opcode 首 byte） | 僅核對指令種類起點，不作整條控制流驗收 |
| `7645D1` | `3639D1` | `89 5B 18` | `mov [ebx+0x18],ebx`，有限確認 talk root owner = self |

本輪的 R2 屬**精確抽核**，不能替代全部 P0/P1/P2、P0-3～10 的 caller、CFG、資料流、Server 原碼和實際素材完整原生審核。未發現上述所選窗口與本次報告勘誤相反的 bytes；未全面排除其他衝突。

## 5. T01 正式判定與工程分流

- **R0：Git 變更範圍和指定原件身分已核；作者包內 manifest/receipt 已閱讀。R1：限定主張可供 S00 做帶信心／未知的設計引用。R2：本輪上述選定原件 bytes PASS。R3：未進行，不新增 FULL-PASS／NATIVE_VERIFIED。**
- 本輪沒有為 277 個檔案各自新增正式 SRC 或 CLM；需經 T01 來源去重、完整檔案 blob/SHA256 逐項比對、精確 claim 範圍／反證檢閱和 `governance/validate_s00.py` 後才可更新正式台帳。舊 608 SRC、24 CLM 等既有紀錄不更動。
- **Client 待逆向／原件待補**：實際 `fcs.flu`／UI FTC 選中 payload、普通入口 B→同 VM script、world→Lua 正向橋接、若要兼容原生格式則需真實 MEF bytes 與 consumer；門的 Client 真動態碰撞與演出實際選取另驗。
- **Server 開發需求（MEF 屬 Server 開發）**：自訂 MEF 內容解析與版本／typed ID／素材檢查；run、owner、取消／重入、狀態事件順序；生怪、敵方AI／傷害／HP／死亡、唯一事件、波清／增援／頭目；出口點集與跨圖重建／門路徑；任務判定、結果、獎勵與資產原子提交／重登保存；NPC／商店／強化及持續服務接入。**能由 MEF 內容規則處理者優先放 MEF；仍需要 Server 權威狀態與持久化整合，不等於全部硬寫 Server if。** 對應既有 REQ-0010/0016/0017/0018/0019/0021 等工作線，由 S00 去重，不自行偽造正式採納狀態。
- **跨功能待整合**：目前 scenario schema、MonsterBehavior、scene/map、wire adapter、事件投影、資源與內容工具的版本接線。
- **待遊玩驗證**：主線正常旅程的角色、怪物、開門、出口、結算、回城、任務／資產保存。這次無 Client／Lua／Server 執行。
- 遵循使用者排程，登入／創角／新手教學／廣場正常流程先行；未重啟已暫緩的異常／故障測試。

**最終狀態：已合併；T01 R0/R1 來源整理 + 選定 R2 原件抽核，未達全文 FULL-PASS。** 不改其他 Task 的退回、RR、REQ、S00 acceptance、owner、catalog 或 native_complete。
