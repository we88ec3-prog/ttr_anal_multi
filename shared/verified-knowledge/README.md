# 共用原生驗證知識（不按 Task 分類）

本目錄僅收錄符合 [T01 FULL-PASS 准入政策](../T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md) 的**有界、完全驗證的原生結論**，按玩家功能／Client 協定／資料結構檢索，**不依來源 Task** 分區。原始 Task、作者、原稿 Git blob SHA、版本、驗收者及日期仍必須在條目 metadata 中留存。

## 正式已驗證條目

已收錄 **5 筆**經有界逐項審核的 KR Client 原生結論（不代表來源 Task 整體完成）：

- [CK-SCENARIO-MAP-READ-NATIVE-01 — Native Map reader 正常返回路徑](client-scenario-map-native-reader-and-clear.md#ck-scenario-map-read-native-01--full-pass限定正常返回)：`0x4AA510` 在有效 owner/key 及 accessor 正常返回時，從 `ECX+4` 容器讀 DWORD。
- [CK-SCENARIO-MAP-CLEAR-STATE-01 — Map clear 正常返回後的 sentinel/count](client-scenario-map-native-reader-and-clear.md#ck-scenario-map-clear-state-01--full-pass限定正常返回)：`0x823850` 在有效容器及節點處理正常返回時重設 sentinel links 並將 count 清零。

上述兩筆是**限定條件的局部 FULL-PASS**；整體 Lua 綁定生命週期、其他全域 writer、完整 TUTO／Scenario 流程仍未准入。原稿與歷史狀態不變。

## 索引條目必要欄位

- 不包含 Task 編號作分類維度的獨立 ID／玩家功能／協定／資料結構
- 精確原生肯定主張與限定範圍；Client 已確認／Client 待逆向
- KR／TC 原件版本、SHA、地址／原始 bytes、證據出處、原稿 blob SHA
- 上下游關聯、Server 待開發、待整合與待遊玩驗證
- 審核者、驗證日期、FULL-PASS 判定、限制、歷史修正／撤銷連結

PARTIAL、source-only、AI/fixture、抽樣 byte 驗證不得混入正式已驗證條目。原稿與 Task 主責不搬移、不改寫。


2026-10-29：[接收器／精確鍵查找／erase iterator 三項有界 FULL-PASS](client-receiver-exact-lookup-erase-iterator.md)。三項 ID 為 `CK-CLIENT-LAZY-RECEIVER-01`、`CK-CLIENT-EXACT-TREE-LOOKUP-01`、`CK-CLIENT-ERASE-NEXT-ITERATOR-01`；原稿全文均未升級。逐項條件、來源版本及歷史更正見內文。
