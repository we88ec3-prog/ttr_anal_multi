# 一般狩獵場入場加權選擇

2026-11-22，沿用既有 scenario V1，NOT_NATIVE_MEF。接續 P0 rules-scheduling
E1：在已通過正常村莊／Stage／隊長／角色入場條件後選一次配置，該run不再重抽。
不改Client、Stage／Case目錄、節點圖或獎勵服務。

既有一般狩獵場 definition 可選 `entryWeight` 整數1..10000。相同Stage的已載入
正常Case中，只要任一設定此欄位，就使用權重模式；缺少欄位的Case有效權重為1。
全部省略則維持原有輪替，單一Case仍為單一選項。主線、RAID與功能測試場不使用
此欄位，載入器應拒絕，不可接受後忽略。

候選依Case排序，必須同村／同Stage、識別唯一，僅從目前已註冊正常入口配置中選。
可信Server draw在[0,totalWeight)取一次；依累積區間選中既有不可變configuration。
來源預設為密碼學亂數；檢查器可注入固定draw驗證選擇，沒有C2S設定draw的介面。

本場保存run ID、選中Case／definition／scenario及AI SHA、policy SHA、權重池與draw。
policy SHA綁有效權重、排序、各配置版本及地形來源。畫面查詢、狀態預覽、換圖與
同場重建不得再次抽選。結果歷史保留同一筆決策；只記於目前連線run／歷史，不
宣稱重登繼續副本。選擇本身不發獎勵，也不能越過既有入場資格。

管理端一般狩獵場編排提供可選權重欄位，寫回同一JSON／不可覆寫版本及配套ZIP；
取消設定會刪除欄位。保存／匯出不自動發布，須配合已載入的同Stage Case池重啟
Host並預檢；未改的另一Case權重視為1，而非假設對方草稿也已發布。

正流程應驗證兩個實際Case選擇、draw只呼叫一次、既有未設定輪替、選中內容SHA
與獎勵／回村一致。指定v2的入場配置、畫面與完整副本仍待實機；分布／重送／
重連／併發／故障等維持原待測安排，不以測試計數或理論權重宣稱實際分布通過。

## 本輪驗證

Release Host／Inspector／Admin.Web皆零警告錯誤；HappyPath 652/652。
Case693權重6、Case694權重4，固定draw2及8各跑兩條正常TCP路線：
693各88EXP、694各76EXP，均回同村同隊並保存。四場policy SHA一致，
每場draw一次，逐圖及完成歷史的決策一致。舊版未設定權重的693兩路
仍各88EXP，沒有entrySelection。Host預檢確認實際載入6／4。

管理端實際取消權重保存版本2，再恢復6保存版本3；舊版1保留。
同版本HTTP配套ZIP匯出、Schema與內容雜湊驗證通過；版本3配套再跑
兩條TCP路線，各88EXP回原村同隊。瀏覽器下載等待逾時，不列下載UI通過。
表單換行正規化造成scenario／AI位元組SHA不同，JSON語意與預設配套相同；
使用匯出metadata的實際SHA載入，沒有忽略來源鎖定。

詳見 [機器收據](hunting-entry-weights-validation.json)。這些使用準備好的
role4／Lv15及受控時計、同程序正式gateway與真正loopback socket，
並非指定v2、全新帳號養成、獨立部署Host或亂數分布驗收。
