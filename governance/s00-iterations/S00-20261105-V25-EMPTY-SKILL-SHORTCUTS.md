# v25：技能快捷列空白

## GAME_RUNTIME_OBSERVATION

使用者在v24回報「角色技能都不見了」，澄清下方快捷列圖示全部空白；不確定廣場就已空白，或Road191切換後才發生。Server83172125f393273b635cc8d4d1ef559133b2907d，工作副本EXE SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c未變更。v24三項戰鬥卡中止，不把37項合成PASS當成HUD／技能成功。

本機v24-empty-shortcuts-snapshot保存HTTP狀態與診斷；完整gameplay journal另保留。Road191 override於17:09:34Z applied，另一次17:10:27Z也進到combat；能收到basic motion、typed resources。抓取時連線已不ready。固定診斷先前沒有126/127/12C白名單，也不收大於68B的availability，因此無法從缺列判斷技能組態未送。沒有證據顯示帳號技能持久資料被刪除；UI消失原因尚未完全證實。

## 有限來源核對與修正候選

只讀既有Git bulk偽碼：4E46D0讀role及4B learned rows；4E48A0讀role、preset、enabled及4B rows並重建角色skill cache；4E5620選用preset的guard要求role<10且record+5C非零。4AF920綁定owner/controller actor。5CD520快捷列讀目前actor role、角色選用matrix與skill cache，缺對應條目可顯示空項；012A/545E20僅是timer map接收／reset，不能逕稱它刪除了learned技能。4D41A0 stats writer未見清技能cache，故不能宣稱Stats必然刪技能。

Server原順序在owner/controller Bind前送126/127/12C。本輪把完整三包移至Bind與最後Stats之後、原AddTiming之前，以確保發布時目前actor已綁定；沒有重送空清單、改ID／級別／消耗／角色持久資料，也不撤回v24連擊／資源／不可用技能移動候選。這是針對初始化順序的Server修補候選，不是已證唯一根因或官方發包順序。

新增固定15B126／17B127／9B12C出站診斷，保留68B cap及原資料限制；不是任意技能庫／帳號資料日誌，也不宣稱大012A已能完整捕捉。新正常案例驗Road191/192完整預設組態在binding後，TCP旅程helper保留原skills/gear檢查並更新先後順序。第一次38項有7個TCP案例因仍期待舊順序而失敗，需更新helper後以完整綠燈為準；不抹去失敗或宣稱真人修好。

## 驗收

v25尚未部署／人測。下一輪先確認廣場與Road191快捷列圖示；有圖示才續原Z連段、滿SP的Z+C與不足X保留移動短卡，任何異常停下。仍不跑暫緩套件，不改Client，不啟動MEF搜尋／新原件分析。

更新：修正TCP helper先後預期後，38項Category=HappyPath全部通過57秒；保留既有技能內容、裝備與旅程檢查。真人HUD仍PENDING。
