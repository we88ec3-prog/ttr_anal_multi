# T08 roy 早期來源 R0／R1 整合提案

已完成 **42／42 份，範圍剩餘 0 份**；包括 15 份未先登錄／非標準命名來源中的090，以及079～105（兩份105各保留獨立blob）。不重複計090。由根整合者合計本輪138份進度。

精確基準 main `610a822b15346c9e0b69edd4e104c2076f2b59ac`；來源分支 head `5816884ef481995a9fe0d92277b1dde06aff32e8`。42份原稿本來已在main，本子代理沒有新增原稿。依新 [T01流程](../../../../governance/t01-integration-workflow.md) 執行來源身份、實際敘述閱讀、有界主張去重與已知衝突處置，達 R1 停止條件即停止。

[proposal.json](proposal.json) 含24個功能group、74個人工選定行段觀察；20組 PARTIAL、4組 UNKNOWN。來源各含原稿路徑、blob、SHA、精確行號與逐字excerpt、歷史判決、主張連結及衝突處置。原稿的已確認措辭只視為作者主張；本批沒有新 NATIVE_VERIFIED、全文pass或S00接受。

已知衝突已分列：

- heap名稱索引的hash/bucket/list反證，排除排序樹／RB措辭；不連帶否定相鄰內嵌容器。
- 096／097的0x8C管理器與heap Provider錯連，參照098指出ID/vptr問題、099地址與內容分離、100的0xB4 Provider後續來源。
- 089／090／092早期resource+20讀取者未定位，與093的具體7BD8D0後續描述對應，不把歷史未知當現在不存在。
- 102～105「當時未找到係數writer」與KB／118～120後續導航分離；camera／半徑／方向語義仍UNKNOWN。
- 候選桶consumer不直接讀global，不能推一定不同實例；129另有相反owner說法但其映射版本已FAILED，維持owner未知與既有退回。
- reaudit的PE／flat座標來源群組限制；不自動校正舊稿、rdata指標或歷史判決。

CLM-CLIENT-0002 僅作pool group內原已審mode／gate子範圍的既有引用；新生命期其他步驟仍PARTIAL。沒有適用的當前Phase-B SPEC依賴，affected_spec_ids留空並明示用途；不因來源有封包數字即生成wire規格。

重現：從repo外或內執行 `python -B <本目錄>/build_proposal.py`，再執行 `python -B <本目錄>/validate.py`。只讀原稿／Git objects／既有來源總表與舊反證，不讀取BIN、不跑REA、不執行歷史研究腳本。[validation.json](validation.json) 只核來源與引用一致性；[manifest.json](manifest.json) 保存產物SHA。

只寫本early專區；global index、原稿、Task、catalog、舊批、Git均由整合者另行處理。
