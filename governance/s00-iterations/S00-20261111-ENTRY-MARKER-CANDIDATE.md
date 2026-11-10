# S00 GAME_RUNTIME_OBSERVATION：回到進場位置的可見標記

## 使用者回覆

v94純清怪增援與返回入場處的區域增援兩場皆通過，但原進場位置沒有任何標記，
返回有困難。當次狀態為ContentRegion、2/2波、兩怪HP0，程序名稱為v10；
不擴大成only-v2／原始BIN實機通過。補測通過與標記易用性分開保存。

## 原生來源與候選

重用既有S00-20261103-FIELD19-PORTAL-GATE.md的有限離線證據：
原BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91本輪重新核對相符。
543700將enable存到+105；544730先檢enable，再判斷位置及手動／自動互動。
category0、auxiliary0、enable0由PortalList選關閉特效A_Zone_BasisTeleportB01.eff；
不接受互動是原生輸入支路的來源結論，不是本輪已完成Client操作驗收。

新增Server顯示候選：只在ContentRegion建立key65530、入場426/385、wireRadius6，
category0／enable0／automatic0／auxiliary0。它是禁用檢查點，不是可用出口；
Server不會開啟該點或以它提交任務／傳送。圈圖只提供中心參考，不保證其可見邊界
等於Server半徑6的觸發區。其他測試場與正式任務不放入這個輔助點。
0027必須一次攜帶同場所有點；本測試場只有這一個顯示點，不覆蓋正式NPC／出口集合。

## 本機唯讀資源核對

沒有修改、提取上傳或補造Client檔案。只讀既有三個archive及相關member，在記憶體
以既有STP reader與標準gzip解碼兩個EMF，確認閉點特效的依賴載體可找到：

|資料|SHA256|
|---|---|
|Effect/Effect.stp|ef0c4fae74c5660aaea7cbe0919549c20db2fd248c81f829aeb7616a11b300ec|
|Effect/Area/Zone/A_Zone_BasisTeleportB01.eff decoded member|b677ff0f8ab75f8040f56fdf6f61d3d68f01e236ab85d2e62f1e64b97476f268|
|Effect/Object.stp|72d89bc529467d1a3633c785583183868abc0ff982bfab22ca6b3d9d49f4cc5c|
|Object/E3_SE_TeleportZone_LargeA_O01.emf member|6da9e1c3694862f53f630cf2de521c96128fb87d50e7e6056dc339d2c6670c11|
|Object/E3_SE_TeleportZone_LargeA_O02.emf member|e85e540486220964a07a8b972b50f9e83a9058b4161f69e4b197f2d4c3cd8ffe|
|Effect/Texture.stp|bd2bb1c5101211bfe79d7d13e5a15d6b515ecf56d1b3fae53edc253d4c682ef7|

特效引用邏輯GB3名稱對應上述同名EMF載體；gzip解碼後的模型引用
AO_LO_PatternTeleportA01、AO_LO_PatternTeleportB01、AS_SO_PatternTeleportC01三個DDS名稱，
同名ETF載體均在Texture archive中。本輪沒有宣稱實機resolver、全部材質或渲染已通過。

## 驗證與待測

Server正流程驗證只發一個20B登記包、enable及automatic皆0、位置正確，增援期間不發
0048開啟標記，區域波次仍照原規則完成。337項受影響HappyPath回歸通過。
後續只短測能否看見標記、走出／走回以及在標記附近按Z仍可正常操作；
不重測已通過的整輪增援，也不把此輔助特效算作完整MEF完成。
