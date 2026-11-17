# R11 能力與完整流程整合審查

## 1. 審查目標

本輪以使用者指定的「`.mef` 能做到哪些事」為分析中心。四組分題都須從實際公開入口與參數，追到資料來源、owner、更新／繪製／UI／音訊 consumer，以及可用的等待或收尾。沿用固定公開前稿的已證能力；新發現、復用證據、條件式內容設計與 Server 開發需求分別標示。

主稿、能力總表與 Server 交接經跨組核閱；世界／NPC分題另獨立逐 byte 對照本輪 control 的44個窗口與世界的158個窗口，核閱 GetTime import、SetUIPage、HideUI、minimap BOUND 及相關參數。總控再執行各子 verifier 並核重疊指令一致性。這些審查沒有執行 Client／Lua／Server。

## 2. 已修正或明確化的關鍵內容

| 項目 | 發布稿採用的精確結論 | 證據 |
|---|---|---|
| KeyFrame 自動進度 | 真實逐幀路徑是 main `491CD6 → v+14 → 54E270`；另一條 `v+10` 對 KeyFrame 為空操作。 | [鏡頭 §4.2](audiovisual/report.md) |
| SkipCamera | 在當前進度加 `trunc(float(k)/R)`；KeyFrame只夾尾端上界。不是設定絕對frame或毫秒。 | [鏡頭 §4.2](audiovisual/report.md) |
| MoveCamera／RotCamera | Move是立即XYZ setter；Rot前兩值為角度，第三值為局部距離。 | [鏡頭 §4.3](audiovisual/report.md) |
| PlayTalkSound | 額外改快取SoundFile的Voice group；沒有寫Book／Prolog使用的全域voice handle，也不回本次完成handle。 | [音效 §6](audiovisual/report.md) |
| 音樂停止／淡出 | fade至0沒有等同停止／釋放stream；StopMusic另有實際Stop與release。 | [音樂 §5](audiovisual/report.md) |
| Fade owner | Fade.Start／End與Q.FadeIn／Out／Color共用FE2744。End(0)可保留可見alpha；音樂fade與Transition另有owner。 | [畫面 §7](audiovisual/report.md) |
| SetFinalMusic | 非空白一般分支追加字串，RestoreMap才消費；不是立即播放或一般覆寫。 | [音樂 §5.5](audiovisual/report.md) |
| AniSkip／角色參數 | AniSkip的signed step沒有非負gate；Rotate方向是低BYTE、Speed是走速倍率，FaceObject是表情。 | [角色 §4](world-npc/report.md) |
| 世界NPC建立 | CNPC採自己的v+30初始化路徑；local配號、world key、Q slot與model不同。 | [物件 §2–§4](world-npc/report.md) |
| 互動點識別 | category2 key已證為ShopNo，category3為NPC key；建立完整集合是保留目前應存在的點，並非每次須列所有category。 | [服務 §6](world-npc/report.md) |
| 對話角色／文字 | actor選頭像／名字／表情資料，talk選文字；所查display不讀parser保存的kind。兩者都不尋找world EntityId或Q slot。 | [對白 §4](dialogue-ui/report.md) |
| 手動旗標／自動時間 | ScenarioTalk.open用Lua truthiness，數字0仍為true；auto timestamp由open起算，不能宣稱每句各1.5秒。 | [對白 §3–§4](dialogue-ui/report.md) |
| Book與Dialogue | Book的一整數被忽略，啟動固定序列；Dialogue有Prolog表key，但原helper只yield，沒有本輪已證專用完成query。 | [對白 §5](dialogue-ui/report.md) |
| BurstStruck | 螢幕Kills／數字、Critical／Critical_Line；不選Q角色，不設同owner的AttackedFX gate。 | [面板 §8](dialogue-ui/report.md) |
| End確認 | 僅正常非review、active、非零quest End受converted confirm恰等於1約束；active quest0 End與seen-skip也可送003F。 | [回報 §9](dialogue-ui/report.md) |
| SetUIPage | 固定選15；同頁只證到送固定F4355刷新事件，不當作wrapper同步重建整頁。 | [控制 §3.2](control/report.md) |
| 小地圖 | 整數map key查FB74D0 BOUND，需既有minimap component，與TRIGGER及任意檔名入口分開。 | [控制 §4](control/report.md) |
| 無效果名稱 | 四個native stub、GetObjectCount初始化名稱、六個空helper與兩個只yield loading helper，都沒有包裝成正向效果。 | [總表](capability-catalog.md)、[helper導覽](helper-catalog.md) |
| Server工作分類 | 已證但未實作服務列Server開發需求；未查明native／wire／公開入口保留Client待逆向。 | [Server交接](server-handoff.md) |

## 3. 資料預驗與可用性

對白分題實際重讀ScenarioTalkTable與其宣告的26份文字表，保存6776個場景列、24445個Talk列、71個未在該文字讀集出現的參照key、1組重複雙鍵與1個空場景。這些結果轉成內容發布前的檢查要求；沒有把其外推成整個Client不可玩，也不以失敗key執行native作探測。[原表統計](dialogue-ui/resource-evidence.json)

世界／服務分題核過Town1五間原表商店、各NPC與商品／服務路由。部分店主在所查ActorList缺world model，不代表店面服務鏈不存在；不能反過來以同號NPC模型推定交易已可用。Server應按服務契約完成資產、材料、費用、結果與保存。[原資源對照](world-npc/resources.json)

## 4. 保留界線與交付判定

已列能力的caller／參數／實際效果與生命週期，構成本輪研究交付。原生MEF首次自動入口／官方格式仍未證；相容模組與清理supervisor的新增組合屬條件式設計。研究可以交接內容／Server開發，實際畫面、聲音、互動及交易仍需按既有授權安排遊玩驗收。

本輪沒有將Server尚未開發改成Client能力不存在，也沒有以普通戰鬥全面替代Server作共同門檻。正式T01／RR／REQ／Task狀態不變。唯讀核對的實際統計及四組結果以 [verification-result.json](verification-result.json) 為準；資料完整性與來源PASS不代替完整語義或遊玩驗收。
