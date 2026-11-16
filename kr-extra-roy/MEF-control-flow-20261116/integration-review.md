# 本輪整合複核紀錄

本紀錄是本輪研究者之間的交叉核對，不是正式T01審核、RR接受或遊玩驗收。兩個獨立分題研究者以同一固定BIN、原native windows及報告檢查presentation的關鍵主張；主整合依反饋修正契約與摘要，再重跑唯讀verifier。

## 已核對且保留的主張

| 主張 | 原件檢查 |
|---|---|
| End之後Stop不補bulk | Stop `562521→562891` inactive bypass；bulk `56268B→RestoreMap`、`562694→DeleteAll`、`56269D→override`、`562883→sweep`、`56288C→End`。 |
| Camera pop先改狀態後比名 | `79877C`複製11 DWORD；`798856`縮end；`798872`才比label；mismatch由`7988B4`回`798750`。 |
| Map不是TRIGGER首載 | Load使用同一M+30／+34；Restore `564090`用FB74B0，`56434D/353`改backup，`56435C`進既有FLD loader。 |
| Sepia需三次後續更新 | 六項jump table、phase4→5→6→0各自寫入；Q active／pump gates匯流後才到`56165F` updater。 |
| Attach的真實frame consumer | `492410`取current、判null、`49241F`讀v+10、`492426`dispatch；Attach對應54E580並呼54E340。 |
| observer取消writer | Stop `5625F5`清Book active；非零參數才`5626DA→55F8A0`關Prolog；不能把0稱正常完成。 |

## 已修正的具體問題

1. **Stop圖片清掃的描述過寬。** 改成G selective sweep；其本身不標記／清空Tutorial tracking。Skip／Scaling `v+28=1`被保留，不能將單獨Stop說成完整取消。CFlyingImage predicate另有型別化處理。
2. **設計cleanup清單與所稱native順序不一致。** 機讀契約已拆成RestoreMap→DeleteAllObject→EndCameraOverride，圖片取消另依owner／型別；避免先刪actor再稱對齊Stop。
3. **CameraWorks摘要保留型別界線。** KeyFrame v+10是476430的ret4，不能以這個callsite證它的播放進度；原件三bytes另存code window。
4. **完整流程不能無條件接End。** 主圖與契約改為必要cleanup後置條件成立才End；必要pending／失敗留外部失敗策略，不把outer return當完成。
5. **完成條件摘要補gate。** Book State2須FB72AC==0；FlyingImage可有限fade或hold−1，G ordering gate限制絕對完成時刻；沒有每張圖公開完成query。
6. **精確數值與指令。** 慢動作常數原bytes為`000000a09999c93f`，double精確值0.20000000298023224（約0.2）；Stop active compare實際用先歸零的ESI，不把它印成不存在的immediate指令。mask0x2明確為bit index1。

本輪驗證器與原件核對也保留code／data分界：EnableObjRender止於56487E，後面564880是獨立函式；sepia560158..560170為jump table；CameraWorks vtable只取有證九個slot，不把下一個COL當方法。

最終分題檔案、來源與指令核對數據見[verification-result.json](verification-result.json)。此複核沒有新增完整原件、執行遊戲、改正式owner／RR／REQ或放寬ordinaryMEF未解依賴。
