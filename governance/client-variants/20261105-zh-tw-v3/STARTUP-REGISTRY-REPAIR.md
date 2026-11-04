# v3首次啟動退回／資源索引補齊

## GAME_RUNTIME_OBSERVATION

使用者啟動新Client時截圖錯誤：E3_SE_TeleportWarp_CenterStayA_P01.gb3 - Couldn't Open File!! - CEffectElement::OnCreateDevice()。新Client SHA f1a23ee3c410e4261aef5eddcb9b4bacbe185cfff50d83155d2c3842bf088cee。這是Client初始化前置失敗，本輪尚不能驗收新翻譯／字型／技能，不作Server v28回歸失敗或原件相容性判斷。

已確認打包器副檔名allowlist漏了.flu，新profile缺fcs.flu。既有Git原生偽碼716440相對cwd fopen("fcs.flu","rb")；成功時讀8B兩個數量、每組344B／每列536B並註冊資源搜尋類別；找不到直接跳過。本機原檔9,058,096B，10組／16,893列，長度公式吻合；包含Effect貼圖／特效、Character模型、Map模型等路徑。Effect/Object.stp既有Object/E3_SE_TeleportWarp_CenterStayA_P01.emf成員，profile effect archive/junction可到達；沒有改／補猜特效內容，亦未展開MEF研究。

原生顯示的.gb3與容器.emf實際解析鏈仍未在本輪完整閉合，不能僅因補.flu就聲稱已實機成功。但『漏帶必需索引』是已證明、可立即修正的打包缺陷。

修正：只把來源fcs.flu逐byte相同副本補到新profile，SHA32348f44fbbbd3254dca9a3a2113e73ed0bfd0d1d4e5f616514322f37aee9ea9；profilebuilder納入.flu並檢查來源相同、二計數與長度。原EXE／新EXE／特效／Server均不修改；無遊戲啟動／附加／輸入。先前PE／文字／字型靜態子集PASS保留，但不足以證明啟動依賴完整，本輪runtime退回另列。

下一步：使用者關閉錯誤與遊戲後，用同一Open-Tartaros-zh-tw-v3.cmd重新啟動，先到登入畫面即可；若仍錯，停下保留新訊息。之後才能續v28翻譯與六鍵短卡。人測PENDING。
