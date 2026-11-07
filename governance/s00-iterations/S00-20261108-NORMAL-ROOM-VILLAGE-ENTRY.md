# 正常房間進村：目前階段目標及實機阻塞

使用者更新階段目標為「開放所有角色技能」與「正常管道（開啟組隊房間）進入村莊」。私有Server不公開；分析與規劃仍在ttr_anal_multi，實作在私有ttr_server_roy，main作業。

使用者截圖確認路徑：廣場→移動至村莊世界地圖→選馮德斯Lv01→隊伍配對→建立隊伍房間（名稱、人數4、公開／非公開）→確認後顯示「진입 가능 레벨이 아닙니다.」。該字串為「未符合可進入的等級」，但不能直接宣稱角色等級不足，也不能混入Q120的level8門檻。

本輪查Table/Messages/CommonMessages.xml定位key=kNotEnoughLevel。既有S2C共同訊息表有候選code6，尚待核對是否本地前置檢查、Server回覆或其他路徑產生。現行Server對Unavailable一般請求僅記錄不回覆，故不能假定這個分支回錯誤6。需要具體字節與producer/consumer閉合。

目前能正常教學／單人主線編隊進村，或透過測試頁切圖，不等於已建立正常組隊房間。主線單人劇情編隊與一般房間為不同功能。正常要求至少覆蓋房間列表／建立、房間狀態、選村與載入／人物NPC／控制綁定；多人同步與其他尚未排程測試不由此自動展開。

重用shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md、原生場景／reset／ready及既有worldmap/lobby來源；按最小必要鏈接入Server。不取消Client的等級檢查、不用測試跳轉替代、不混用005F與0069的type。實機仍未通過。

翻譯同時回報世界地圖村莊名、隊伍建立標題、進村按鈕／提示韓文；加入REQ-0022。v9僅啟動與部分任務名稱通過，殘留韓文不標完成。

## 新補證（來源靜態核對，尚未部署）

CCreatePartyDialog 確認先經 68C790→53B900 送 C2S0053（50B，名稱／人數），再送公開或非公開005E/0060，旅程 context2 才發 F4390→5B6250。4E2E70 以 CGlobalStatus+68FC 城鎮 bitvector 及 CTownInfoTable.TYPE1 檢查資格，失敗由本地顯示 CommonMessages6，該 helper 沒有比較角色／遠征隊等級。故不能為消除訊息而提高角色等級。通過後才送003D+townBYTE。

原生 S2C0080 可 OR 單一城鎮 bit；007E 為 append，不能當替換。008E／008F 有房間／成員 consumer，0088／0089 會清隊伍，不能作建隊成功。008E+2C 語意仍需補證（capacity 候選），不當 town；缺少完整最小回覆順序驗收。正常進村尚未修復，不以測試跳轉替代。

來源包：[原生建隊及城鎮資格鏈](../client-variants/20261108-normal-village-entry/README.md)。舊 metadata 中未閉合 create producer 的文字由後補 create-party-producer.json 限定更新，不擴張回覆語意。
