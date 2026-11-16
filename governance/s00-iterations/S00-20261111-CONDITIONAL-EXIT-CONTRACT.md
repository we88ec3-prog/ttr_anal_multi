# S00：typed條件出口與實例旗標契約

SERVER_DESIGN_CHOICE／SERVER_RECONSTRUCTION_NOT_NATIVE_MEF。
沿用獨立scenario JSON；不發明原生MEF格式、傳檔opcode或Client自由設定旗標介面。

portal.condition可選，含requiredFlags（ALL）及activationRegion（AND）。
沒有condition保持原先清怪後開啟。所有出口均先要求整個遭遇含增援完成；
條件滿足後按key鎖存開啟，離開區域不關回。PortalUnlocked僅表示至少一點開啟，
授權需查OpenExitKeys；GroupIsCleared與出口狀態分開。

node.signals產生本實例旗標：GroupCleared在全組清除時產生；RegionEntered於節點
已進入且Server位姿在指定區域時產生，可早於清怪。兩者沒有Client任意字串設定入口。
旗標名ASCII字母開頭、其餘英數／底線／點／連字號，長度1–64；全definition唯一、
合計最多64；每出口最多16個不同requiredFlags。旗標換圖保留、放棄／新instance重置。
Fork複製狀態，catalog及RequiredFlags集合凍結，不共享可變狀態。

有限無環圖的每一入口路徑都要能產生該出口所需旗標：目前節點producer可在本節點
完成，既有旗標須在所有上游入口路徑保證存在。傳遞保證含上游GroupCleared與所選
出口明確要求的旗標；合流採交集。不能以另一分支或將來節點的producer解鎖目前出口。
這是邏輯可達性驗證；BND中心可站立由adapter另核對，不代表完整場景幾何可達性。

World持續評估Server位姿，逐key只發布新開啟0048；需要重建時0027仍是一次整份點集合，
包含所有出口及真實開關值，不能追加而覆蓋其他點。條件未滿足仍可移動、普攻，
不因清怪或等待出口而鎖輸入。Story交易先複製instance，提交前不推進原游標；
既有固定兩段Phindos保存adapter不接此功能，避免繞過原保存階段。

獨立ContentConditions場使用193→194/195→Result，Field20/Case104。
第一圖近出口A清怪即開，另一出口B要清怪後返回進場圈才開；離開圈後B保持開啟。
第一圖GroupCleared產生first-clear，第二圖結果出口要求該旗標及當前圖清怪完成。
只有開關與跨圖條件驗證；不提交正常任務、EXP、物品或獎勵。
示範使用既有BND中已核對的出生點與向前24單位區間，不代表正式通道／特效配置。

NPC／機關互動producer、背包或任務道具條件、跨實例與永久存檔仍待後續接線。
人測先累積在單張批次表，使用者目前無法測，不發測試催問，不因合成通過代填人測。
