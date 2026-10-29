# T01 新流程首次接續：來源收件與有限主張

基準：`origin/main 9d97ea37e`，2026-10-29 Asia/Taipei；T01 integrator。依使用者「先更新 main，再按新 T01 處理」指示，停止將318篇全文驗收作為整合門檻，採用 [風險分流流程](../../../governance/t01-integration-workflow.md)。正式歷史仍是全文有界通過3／318、未通過315，未匯入尚未提交的第03批草稿裁決。

## 本批完成

- 先處理13個精確來源版本，再以一次Git blob批次核對補齊其餘305版，完成全部318版R0：來源SHA256、Git blob SHA1、最新main原文、KR原件身份及歷史狀態對應。兩個T16-73按不同檔案／blob保留，未合併。
- 4個來源萃取4項有限主張並完成範圍／既有衝突查對：3項重用既有正式原生決議，1項保持來源級PARTIAL。
- 本批來源工作狀態：314個REGISTERED、4個CONFLICT_CHECKED、0個SPEC_CONSUMABLE。全庫SRC由10增至328（保留既有10個不同來源）、CLM由16增至20。**來源收件剩0版；有限主張萃取剩314版。**
- 未新增或結案RR、GAP，未升格SPEC／TEST，未改歷史318版台帳、原稿、其他Task主責或退回狀態。T01收件箱在基準main沒有SUBMITTED／IN_REVIEW請求；其他Task的QUEUED請求不由T01代認領。

[操作紀錄](actions.json)｜[唯一來源索引](../../intake/index.json)｜[唯一主張索引](../../claims/index.json)｜[Server影響交接](server-impact.md)

## 主張與衝突處置

| 主張 | 信心／風險 | 查對與適用範圍 | S00用途 |
| --- | --- | --- | --- |
| CLM-CLIENT-0001 | NATIVE_VERIFIED，重用既有R3決議 | 僅40F060正常返回與4B3710→4DFC90 stack／actor+88資料流；對應CK-CLIENT-LAZY-RECEIVER-01。154／156的key-converter假設不再使用，其他舊稿不升格。 | Client下游導航，尚無Phase-B規格依賴 |
| CLM-CLIENT-0002 | NATIVE_VERIFIED，重用既有R3決議 | 僅集合mode切換／producer gate；177已修復RETURN173，但舊173仍FAILED。不同owner不推定同一類別或跨執行緒安全。 | 同上，不生成Server模式觸發規則 |
| CLM-CLIENT-0003 | NATIVE_VERIFIED，重用既有R3決議 | 僅4DFC30 owner+18/1C與4DFC90 owner+8/C差異及清理路徑；197修復RETURN196。共享所有權仍未知；200「索引」歧義不帶入此結論。 | 同上，不生成移除封包或玩法政策 |
| CLM-QUEST-0001 | PARTIAL／R1 | T16-74原稿L17–66報告本地12-byte名稱／值表；L94–119明示wire域、consumer、producer未知。當前CLM無同scope的Quest表主張；數值13不等於CLM-AUTH-0002的登入回覆命令域。 | SPEC-NET-0003的非規範導航，不能把1F／11／12／13填作opcode |

前三項證據沿用已推送的continuation-02決議、原件CFG及既有CK，不因本批收件狀態或CI通過才標NATIVE_VERIFIED。第四項沒有新的原件語意驗收引用，保持PARTIAL；其與現有登入數值域的查對只排除不當等同，沒有證明Quest業務協定。

## 第一階段停止與後續

上述4項已具備來源身份、有限適用範圍、可信度、衝突及未知的S00導航資訊，因此按R1停止條件結束一般重驗，不再要求全文通過。S00未接受任何項為SPEC_CONSUMABLE；需要具體設計阻塞時由S00依現有RR台帳定向派工，不重複建RR。

其餘314個REGISTERED來源尚未完成本新通道的bounded claim萃取。FAILED來源只保留身份與反證導航；REFUTED主張不得作規範性來源。舊第03批的本機證據留在 `shared/integrations/T01-20261029-continuation-03/`，維持未提交草稿；已落盤的pass字樣不構成正式歷史升格。接續先查最新main、T01收件箱及RR，而非直接恢復舊全文掃描。

## 驗證方法與機械問題修復

執行新main要求的S00索引、工作包、派工與離線向量檢查；結果見 [validation.json](validation.json)。它們檢查身份、schema、引用、狀態與合成向量，不證明native語意、真實Client相容性或Server運作。

基準main首次驗證時SRC-0007～0010的SHA不符：Windows core.autocrlf將新加入的kr-extra-roy原稿轉成CRLF。已從同一origin/main Git blob還原精確bytes，並加入`.gitattributes`的`kr-extra-roy/** -text -whitespace`防止再轉換。原稿Git blob／內容未變；[逐份還原紀錄](checkout-normalization.json)。這是本機收件／封裝問題，未退回原作者。

REA使用紀錄：重用既有精確SHA的REA／Ghidra快取與正式決議。新的單指令live請求逾300秒未返回、沒有可用證據，故未拿它作任何升格依據。快取與小範圍輸出可減少重複閱讀的token；本輪沒有量測節省比例，也不承諾冷啟動Ghidra較快。
