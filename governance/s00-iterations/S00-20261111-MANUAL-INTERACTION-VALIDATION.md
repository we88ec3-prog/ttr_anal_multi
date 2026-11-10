# S00：手動互動點驗證與v98準備狀態

本批功能為SERVER_RECONSTRUCTION_NOT_NATIVE_MEF；使用者目前不便測，先累積，不發逐項提問。
[原生邊界](S00-20261111-CHECKPOINT1-NATIVE-BOUNDARY.md)、[資料與執行契約](S00-20261111-MANUAL-INTERACTION-CONTRACT.md)、[批次表](../../design/testing/S00-CONTENT-BATCH-TESTS.md)。

## 已完成本批實作與正常流程驗證

350個受影響HappyPath全數通過。相較v97增加5個案例：混合集合線形、互動依賴／旗標隔離、
完整兩圖互動測試場，以及Story兩種點生命週期。先前targeted6＋2包含既有案例，不與350相加。

- category0出口、category1互動及category0提示圈在一次0027集合發布，避免覆蓋。
- 清組與前置旗標能開啟互動；有效001C(1,key)才給固定旗標並停用該點。
- 互動本身不換圖、不提交正式任務；已開出口的001C(0,key)才規劃下一圖／結果，Story提交前原游標不變。
- 互動依賴以有限閉包驗證；通過出口要求的互動旗標也保證其前置，後圖可使用。
- catalog凍結巢狀requiredFlags；Fork與兩個instance不共用可變狀態。
- 實際typed loader讀公開JSON，互動901→出口801→map194→結果路線完成。
- map193／194的新出生、怪物、出口與互動中心通過既有BND靜態可站立檢查；非完整導航證明。
- JSON Schema validator通過目前、v97/v96/v94歷史場與分支示範；網頁JS語法通過。

資料SHA256 `0c081ec160b5480cdf513e22ea9cbd33206dc0f017514bdbaf5901e8bfa1bc14`。
Schema SHA256 `b2dc16ee4918c8a890375b348d668958266ef4266396441217de471011214cac`，公開與私有副本一致。
v97資料與條件schema已另存歷史檔，不改舊版Host或Client。

## 尚未通過／未完成

v98僅準備，不啟用；線上仍v96a。8列BR／CG／CT／IP均等待日後集中人測。
Category1經已查普通模式有原生producer，但本輪未實機確認按Z能收到其意圖。
沒有新的Client執行／附加或修改；沒有原生MEF格式／接收器／官方存檔政策完成主張。
3D槓桿、寶箱、破壞物件、任務道具條件、敵人投射物與完整物種AI、跨圖Buff／地面效果仍有後續工作。
延期的錯誤／邊界／重送／併發／故障／安全／壓測未執行。
