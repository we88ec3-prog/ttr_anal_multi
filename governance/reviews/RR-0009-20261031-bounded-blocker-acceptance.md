# S00 — RR-0009 KR 創角 UI 定向研究有界驗收（2026-10-31）

## 決議與證據身分

- **正式決議：RR-0009 `ACCEPTED`，僅指驗收條件第 5 款「找不到正向原生入口時，提交具體 blocker、反例及解除條件」的**研究成果交付**。**不是**「空角色清單能開創角畫面」功能驗收，也沒有結案 `GAP-CHAR-0002`。
- S00 審查基準：`main=ad1fda170734767c67dd0f62066a34ece34e118a`；版本 KR、原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；未在本次 S00 審查重跑原始 BIN、執行 Client 或擷取原版 Server 封包。
- T03 原始交件：[E70](../../kr-extra-roy/20261031-chatgpt-web-roy-E70-RR0009-empty-roster-GUI-blocker.md)；**Git blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13`**，572 行有界原稿；另有 30 項來源作者原生靜態檢查，並**非**獨立 T01 全文複驗。
- T03 交件狀態由 `SUBMITTED→IN_REVIEW→ACCEPTED`；研究主責 T03 不變，S00 是**範圍限定交付的驗收者**，T01 仍獨立處理 native FULL-PASS、既有 T03 NEEDS_FIX。未曾核發 T01 全文 FULL-PASS、NATIVE_VERIFIED 或 SPEC_CONSUMABLE。

## 逐條對照 RR-0009 的五項條件

| 條件 | E70 可用且來源限定的結果 | S00 判定 |
| --- | --- | --- |
| #1 版本/分支/資源/producer→UI consumer | 原始 KR BIN、`0x4B894C` 零筆跳至 `0x4B8A20`；`0x5AB020→0x5AB280` cache、`CEmployNewCharacter` RTTI、`0x5C30FD/5C316A` UI-owner registration、`0x65D550` 本地事件候選 | 只接受個別有界來源／未知清單；**未找到零筆→可見建角 dialog 的正向鏈** |
| #2 N=0、N>0、資源缺失、資料寫入不等於 ready | N=0 僅略過 53B row；N>0 `0x4D4150` 可寫 record+0x5C；缺實際 GUI pack 同版控制 ID；F42EF/record-ready 不保證 visible/enabled | 反例矩陣完整陳述；resource-missing 是未驗證條件，非實機故障事實 |
| #3 本地 UI 對 roster/wire 分離 | `F4350/F42EF/F4246/F4247/F4278` 為事件域；`0x665150` 現有角色 detail hit；不以它們冒稱 create C2S | 滿足保守區分；不侵占 RR-0002/0007/0010 |
| #4 完整可追溯報告/來源/影響 | E70 原稿 blob、函式/ASM/反例、未解與 T06 資源需要均提供；GAP/SPEC/TEST 影響明列 | 報告可作 S00 規格**阻塞**來源；無 GUI 正向測試向量，沒有新增正式 TEST |
| #5 無 positive entry 則提交精確 blocker | 缺 N0-specific state writer、scene listener、control visible/enabled gate、dialog open；列四種解除路徑（同版 native xrefs/GUI pack/授權合成 runtime/同版真實 trace） | **依本條接受研究交付，不接受 UI 功能閉合** |

## 正式後果（不得以 ACCEPTED 替代）

1. `GAP-CHAR-0002` **OPEN**；`SPEC-CHAR-0001`、`SPEC-FLOW-0001` 仍 **DRAFT/PARTIAL**；不得將 N=0 當成 Client 原生自動開啟創角畫面規則。
2. `RR-0010` 仍 **BLOCKED**；真正 playable-character create 的 C2S→S2C→roster 因果未證。新增研究採 [RR-0009/0010 S00 統合交接](../s00-iterations/S00-20261031-RR0009-RR0010-REVIEW-AND-HANDOFF.md) 的剩餘缺口，不重複建同義 RR；需新範圍時再從唯一 RR 台帳定向派工。
3. 後續 T03/T06 若取得同版 GUI layout、N0 對應 UI listener/控制或原 Client runtime 證據，S00 應重新檢查 **GAP** 的解除條件，必要時新開/重定義研究請求，**不改寫本次已交付的有限歷史決議**。
4. `TEST-CHAR-0001` 只驗 synthetic 角色 record；未新增 GUI 開啟、create transaction 的正式 TEST。不能藉本決議開啟原版 KR native adapter、對玩家保證可創角、批准 ADR 或修改 Server repo。
5. T01 若之後發現 E70 原生主張反證，須保留原審查版本與更正來源，由 S00 重審相關 SPEC/GAP，不能以本 S00 決議阻擋來源勘誤。

**驗收範圍是一個明確的「尚未閉合功能鏈」研究證據交付；功能成功、相容測試及使用者可見 GUI 均未驗收。** 本次以 `main` 單一提交維護正式 RR、review mirror、衍生 T01/T03 inbox、SPEC/GAP，無新分支。
