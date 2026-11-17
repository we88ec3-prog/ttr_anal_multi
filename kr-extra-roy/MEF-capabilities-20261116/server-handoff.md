# Server 開發需求：讓已證腳本能力成為可用內容

本文件接續 REQ-0019／REQ-0021 與既有關卡／城鎮服務脈絡，僅在 `extra/roy1` 的自有研究目錄交接開發需求，不新增正式 REQ、指派 Task owner 或提升 RR／T01 狀態。

**開發目標是讓內容可選擇正確功能、產生正確Client效果，並與Server流程及保存一致。** 可以保留Server的戰鬥、交易、同步與持久化職責，同時使用Client既有演出、UI、互動及資源能力。這份需求以各功能的可用性驗收，不以完全移除Server工作為標準。

## 1. 按能力拆分開發責任

| 能力 | Client 已證執行部分 | Server 待開發的交界 | 驗收結果 |
|---|---|---|---|
| 固定劇情／演出 | scene雙鍵→seq；Q角色／鏡頭／聲音／對白可在腳本內編排 | 合法內容選擇、busy序列化、進度與取消；版本與依賴清單 | 選定內容實際播放，恢復輸入／UI，Server續接正確節點。 |
| 新相容模組 | 已證Lua parser、全域DoFile及條件式caller／supervisor設計 | 自有內容契約、當次export與version、phase分離、可到達入口 | 同一內容在prepass／正式phase各做預定工作，錯誤及清理有可觀察結果。 |
| Q actor動作 | slot→CEventActor；位置、走位、動畫、表情、外觀、顯示、批次清理 | 保持內容slot唯一，model/action依賴一致，避免同slot重建當upsert | 正確物件有正確動作與外觀，最後該段持有物件完成清理。 |
| 世界NPC與外觀 | lb本地建構、CDoll部件／附件、真正native update/apply | 已有world key、合法模型、座標來源、本機與網路identity及生命週期 | 可見NPC／外觀對應同一實體；互動key不靠模型號或顯示外觀猜測。 |
| camera／音訊／畫面 | KeyFrame tick、camera snapshot、music stream、voice、Fade等 | 同一玩家共享owner的占用／替換／取消策略，必要清理順序 | 相機、畫面與聲音達到目標且能按政策恢復；停止／音量0／已釋放分開。 |
| 對白 | ScenarioTalkTable雙鍵／文字／頭像；Prolog文字／語音；按鍵／自動推進 | key與資料預驗、手動旗標型別、結束後分支、語音／UI owner協調 | 顯示正確人物與文字、預期方式推進；關閉後UI與後續狀態正確。 |
| 教學 | 提示點、輸入mask、教學state、UI訊息與scenario等待 | 合法scenario request、適用context的完成事件、教學進度保存 | 玩家完成指定操作後腳本接續，Server進度不由任意UI旗標直接裁定。 |
| 互動點 | 已建點可本地切狀態；Client判範圍／按鍵並送意圖 | 完整點集合、category/key/XY/radius、服務與出口可用性及意圖處理 | NPC、市場、出口共存；同一點在預期時機可用且轉到正確服務／下一圖。 |
| 地圖與小地圖 | 本地load／restore；map→BOUND→mmt／texture／symbols | map節點、actor／point重新發布、資源依賴、Server轉場與保存 | 3D場景、邏輯位置、互動點與小地圖對齊，接續到正確節點。 |
| 商店與服務 | 原生選單、貨單、買賣／強化UI、各自請求和結果顯示 | 商戶授權、貨單／價格政策、資產驗證、原子提交、結果更新、持久化 | 一次合法交易對應正確金錢／背包／材料／裝備變更，重登一致。 |

來源：本輪 [世界與服務](world-npc/report.md)、[鏡頭與音訊](audiovisual/report.md)、[對白](dialogue-ui/report.md)、[教學與輔助層](control/report.md)；既有 [R9 caller](../MEF-end-to-end-20261116/entry/report.md)、[R10 supervisor](../MEF-control-flow-20261116/supervisor/report.md)、[R10持有資源與清理](../MEF-control-flow-20261116/presentation/report.md)。

## 2. 內容與資料工具應先實作的檢查

### 2.1 把不同的鍵存成不同欄位

| 識別域 | 正確用法 | 不能靠數值相等自動互換 |
|---|---|---|
| scene quest/scene雙鍵 | 原SceneList選seq、Q admission與原回報 | ScenarioTalkTable雙鍵、scenario ID。 |
| Q slot | 同一Q tree中的演出角色參照 | world EntityId、NPC ID、model ID。 |
| world EntityId | 同一world tree與網路後續操作的實體參照 | lb.CreateObjectEx的輸入model及未回傳的本機配號。 |
| model／avatar part／variant／item key | 對應模型／CDoll資源目錄的不同欄位 | 外觀附件key與Detach的part鍵。 |
| point category/key | 同一互動點集合中的NPC、市場、出口等條目；category2 key已證為ShopNo，category3 key為NPC key | 不能略過category任意換成model、EntityId或目的地圖鍵；跨表映射須有原consumer支持。 |
| Town／ShopNo／NPC | 依原表選商店、貨單、服務選單 | 世界NPC模型或原生座標。 |
| ScenarioTalkTable id/scene、actor/talk key | 選對白列、頭像與文字 | 世界說話者pointer或Q slot。 |
| Prolog／Dialogue key；Book固定序列 | 前兩者選各自表資料；Book的一整數參數被native忽略 | 不能把Book參數當內容選鍵，亦不對應一般world角色。 |
| map key／BOUND／TRIGGER | 分別對應場景索引、小地圖／碰撞關係、原觸發名稱 | 檔案名、副檔名、camera key。 |

此型別區分是相容內容／Server資料設計要求，沒有宣稱這些是官方MEF欄位名稱。實際名稱、合法值與資源關係只能取自已證原表及選定內容，候選座標必須保留來源及驗收狀態。[能力索引](capability-catalog.md)

### 2.2 參數、資料完整性與 helper 差異

- 數值型binding使用已證整數／float；x87 `FISTP` 不寫成保證朝零截斷。Q的數值開關使用數字0/1；`ScenarioTalkTable.open`第三參數則依Lua truthiness，數字0仍為true，應用明確boolean表意。
- qbase不是純alias清單：PlayCameraNoWait加工相對座標，NumberPanel分流兩個native，速度helper換算倍率；StartLoading／EndLoading只yield。內容工具應區分helper參數與native參數。
- 對白資料至少預驗(id,scene)唯一性、非空Talk列、頭像資料、talk文字key與所有宣告文字表。原件含缺key／重複／空列的實際統計由對白分題保留；不要把native缺資料路徑假定為安全false。
- 模型、motion、Face.SKIN、avatar部件與附件、camera XML、音訊、texture、minimap descriptor／symbols，都須在發布前與實際資源選路一致。外觀setter或loader存在不等於指定資源已存在。
- native明確stub與helper空函式應在內容工具標成不可產生該效果：Q.DeleteObject、Q.BalloonTalk、lb.PrintCurrSceneID、Tutorial.InsertObject；GetObjectCount不能當有效query。

具體ABI與原件分別見 [control](control/report.md)、[audiovisual](audiovisual/report.md)、[dialogue-ui](dialogue-ui/report.md)、[world-npc](world-npc/report.md)。本文件列工具需求，不交付會修改原資源的compiler或可部署腳本。

## 3. 演出生命週期與共享資源

Server的同玩家內容流程至少記錄選定內容版本、scene context、接納／未接納、實際開始與結束原因、取消／超時，以及下一步業務狀態。若需generation/run等內部欄位，可以由Server自行設計；**不能塞進原wire沒有的欄位或假設Client會回傳。**

內容整合層應保存實際取得清單：Q slots、camera works、相機snapshot、map backup、被隱藏的UI、world render gate、輸入mask、圖片、voice/music／淡幕等。這些不全由一個namespace獨占。對外部轉場／Stop、使用者skip、一般Lua error，應按已證可接回的邊決定收尾或外部修復；只在必要後置條件成立後最後End。

本輪新增會影響清理的具體事項如下：

| 情況 | 必須落到實作的規則 |
|---|---|
| CameraWorks完成 | 使用該工作predicate，並區分null／未建立、停止、自然到尾；相機快照仍另行還原。 |
| camera pop | 先還原／erase再比label；記錄平衡取得，避免盲目重試消耗其他快照。 |
| 音樂fade到0 | 記為音量已到目標，仍可能持有stream；需要停止／釋放時另走已證Stop。 |
| Fade.End(0) | 只停更新但可保留overlay；清覆蓋需明確非零參數與有效owner。 |
| ScenarioTalk／Prolog語音 | 共用voice handle可能影響等待；close、audio stop與UI hide按同owner協調。 |
| Q圖片與Tutorial圖片 | 不同tracking／共用G owner；取消與實體回收分時點，不把任一sweep當全清。 |
| End／Stop | End會清active；先End再Stop可能跳過bulk，不用來補救清理。 |

依據：[audiovisual](audiovisual/report.md)、[dialogue-ui](dialogue-ui/report.md)、[既有圖片owner](../MEF-control-flow-20261116/world/report.md)、[既有Stop順序](../MEF-control-flow-20261116/presentation/report.md)。

## 4. NPC、商店與資產流程

本輪世界／服務分題保留原件支持的Town1商店、NPC type、商品與服務路由。可先以已有資料的雜貨與普通鐵匠功能形成完整開發切片：內容／Server決定何時開放，正確market point key進原生店面，再處理真實請求、資產提交與相容結果顯示。NPC模型只是世界表現；原表店主缺world model時，不能以猜model或座標補成已驗證方案。

Server需要逐服務區分處理器及驗收資料。普通買入、背包出售、裝備強化、銀行商店／倉庫、鍊金、製作、拆解有各自契約；本輪已證而尚未實作的部分列Server開發需求，尚未查明的native／wire／公開入口保留Client待逆向，不藉「開了功能視窗」宣稱交易已完成。扣款、材料消耗、裝備結果、背包容量、重複請求及持久化均需原子一致性。

category2市場點與category3普通NPC點、category0出口、category4教學點可同時存在於完整集合。首次S2C0027安裝／重建集合與既有點狀態setter是不同動作；發布新集合前需避免把其他種類意外清掉。[世界／商店原件](world-npc/report.md)、[既有互動點安裝與狀態setter](../../governance/client-variants/20261109-mef-town-services/scenario-controls.md)

## 5. 回報與驗收

原C2S003F可由正常End或已看略過等分支送出，不能單憑它提交獎勵。原S2C00EB解除等待／特定mask，也不是通用腳本停止／清理。教學004C、互動001C、普通買賣及強化請求各有明確context，應對到相應Server流程。[原wire契約](../MEF-world-integration-20261115/wire/report.md)、[control](control/report.md)、[world-npc](world-npc/report.md)

按專案既有驗收優先序，先規劃一條合法內容的正常路徑：資源版本一致→啟動成功→具體功能產生正確效果→同owner觀察到預期結束→資源／輸入恢復→Server續接／保存。各項留下選定key、實際檔案hash、Client畫面／聲音／互動記錄、Server事件與持久化狀態。是否省去某類封包可以作另外的量測題目，不作所有MEF能力的共同前提。

## 6. 四類待辦各自維持

| 分類 | 精確工作 |
|---|---|
| **Server 待開發** | 本稿所有內容發布、場景／教學／互動／服務流程、identity對帳、權威提交與保存。 |
| **跨功能待整合** | 相容內容caller、prepass/formal phase、UI／camera／音訊等owner、依賴工具與清理策略。 |
| **Client 待逆向** | 原生MEF首次入口／官方格式，以及超出本次已證能力範圍而實際需求又需要的接口。逐功能立題，不把所有未知能力捆成一道門檻。 |
| **待遊玩驗證** | 已選正常內容的畫面／聲音／互動／交易與雙端一致性；後續錯誤、取消與重入依既有排程與授權安排。 |

本輪只交接研究與規格，沒有修改Server repo、執行Client或遊戲測試。證據verifier PASS與Server功能完成／遊玩驗收分開記錄。
