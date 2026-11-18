# P0-3～10 深入分析：可用能力、具體內容與接口

本輪接續前次玩家表中的八個 P0 項目，重新對照 KR 原 BIN、實際 Table／BoundMap 與固定版本 Server 原碼。MEF 仍採使用者的定義：**Server 提供並執行或派送內容，能以 MEF 編排的功能優先納入；Server 規則資料化與 Client 計算外移各自說明。**

分析 branch 基線 `19005c9f8a8180e6f0deb00faf008a11ef98023f`，Server 原碼基線 `e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4`。後者只作唯讀實作證據，完整 C# 不發布到本庫。研究終點與編號對照在 [acceptance-plan.json](acceptance-plan.json)，來源界線在 [SOURCE-NOTES.md](SOURCE-NOTES.md)。

## 1. 生怪與戰鬥：從「能建立物件」補到初始化及可用行為

### P0-3 生怪

`Q.CreateObject` 建立的演出角色、`lb.CreateObject[Ex]` 建立的本地 world actor，以及 `0007` 建立的網路 world actor，要各自保留 slot／world ID 與 owner。兩條 world 路徑都可能建立 `CMonster`，卻不代表已初始化成相同敵人；本輪補查關係／陣營、怪物變體、HP 表示及控制所需資料。

新原件證據把 `CMonster` 的 selector 29 接到 group（`+90`）writer，因此不能繼續把 ordinary group 設定列為完全沒有 Client 接口。它與 relation key（`+9C`）是不同欄位；這個設定落點不會自動產生敵對 AI、Lua 查詢結果或世界身分回傳。

真正 Server 原碼也已確認：出生資料、個體身分、怪物行為 profile、巡邏／追敵／返家及後續結果可直接作 Server MEF 的底層。新的 MEF 內容應編排這些既有能力；只有選擇完整 Client 自主戰鬥時，才另外處理它的控制與事件回報接口。

另找到具體的作者資料限制：現有移動速度 schema 的上限比 Client signed 16-bit consumer 的正值範圍大。本輪指定作者 corpus 的 8 檔／17 個 profile 出現均經完整 schema／typed 關係核對，現有速度都是 12 或 18；新正速度設定應限制到 `1..32767` 或由 adapter 明確處理。這是新發現的 Server MEF 內容檢查需求，本輪不改 Server schema 或原設定。[詳細初始化、consumer 與行為稽核](actors-combat/report.md)

### P0-4 戰鬥與扣血

已把原生輸入／動作、接收結果、HP、死亡與刪除分開，並對照現有 Server 的真實執行落點。Server 已有依血量、距離及冷卻選招，攻擊前搖後重新驗距離，以及傷害、防禦、死亡延後移除與波次血量觀察。這些是可直接接入 MEF 的既有服務，不需把整套戰鬥重列為未開發。

本輪新增的 `0094 → CBullet` 證據也提供可用投射物呈現鏈：Client 原生更新負責飛行，按所選模式使用方向或目標／座標，終止另有清除 consumer。它能承接投射物畫面工作，沒有因此變成命中／傷害提交，也不能把「到達目標」推成原生自動刪除或命中回報。

資源 key 也從真正 `Table/Blt2.blt` 補足：228 個唯一 Bullet Type，及其 actor model key 轉換已有原件與資料對照。這是投射物資源種類，不另計成228種MEF。當前 Server 的 `LocalMonsterProjectiles` 還沒有這條 native flight visual mapper；**仍須新增 `0094／0000／001A` 視覺 adapter、network entity 生命期與所選效果的畫面驗收**。不能把 Client consumer 已找到寫成目前 Server 已接好飛行效果。

`Q.NumberPanel` 等仍只是字樣／畫面；完整普通敵方目標決策與命中判定移到 Client MEF、一般死亡結果直接注入常駐 Lua，仍需精確的新增接口。這些選用路線不阻擋 Server MEF 先使用已存在的戰鬥與投射物規則。[輸入、結果及投射物原件鏈](actors-combat/report.md)

## 2. 增援、頭目、分支與時計：以實際程式取代概括

### P0-5 分批增援

目前既有定時與順序波可以直接編排。相同有效更新先考慮定時波，再處理順序波；有前置旗標的定時波不應阻擋其他合格定時波，順序波則保持其陣列順序及聚合活怪門檻。

本輪把前次缺少的公開內容補成明示作者候選：進區觸發、頭目擊倒訊號、初始空場後出怪，以及具名波次頭目。範例使用既有 schema；來源、條件安排及指定二維地形均有靜態核對。這些是可交開發採用的內容，尚未默默裝入正式關卡或當成 Server／Client 實測通過。[作者候選與分析](rules-scheduling/report.md)

### P0-6 敵群清空與頭目

實際程式使清場條件更精確：所有必要波已生成、活怪歸零、玩家存活、勝利等待到期、**敵方**投射物已結束，以及適用的頭目移除條件都需要保留。一般主線與一般副本另要求所有敵人的移除都已排送；一般副本還等待既有擊倒經驗處理完成，`PendingStageOneDefeatExperience` 不再掛起。功能測試場使用的返回條件較窄。不能將不同 consumer 一律描述為相同門檻。

頭目識別也已收斂：`requiredBoss.waveId` 省略時，是在該節點的所有候選出生中以 Model／PRE 唯一匹配，不只限定初始波；指定 waveId 時才再限定該波。這讓延後登場頭目有清楚的設定方式。

Server 排送移除不代表 Client 已實際回收模型。MEF 清場條件要消費既有的有效事件；空畫面、所有演出角色停止或無有效 count 的 Lua 名稱都不能代替這條鏈。[清場與頭目契約](rules-scheduling/report.md)

### P0-7 分支路線與旗標

本輪找到兩種可減少 runtime 擴充的做法：

1. **固定重複次數**：將三次挑戰展開成三個現有節點，逐次改寫旗標與 encounter group；中途出口走 NextNode，只有最後一次走 Result。這會逐節點重建；若玩法要同房不中斷連打三波，應採既有 reinforcements。角色狀態延續仍依所選 adapter，計數不是寫進新的 Client wire。
2. **入場前選路**：先選定一個既有 definition，再建立該次副本。選擇 adapter 需要實作／接線，但關卡內仍使用既有執行器；地圖重建不重新抽路。

作者 definition ID 仍須登錄正式 catalog／selector；現有主線 override 會限制節點數、地圖及初始怪物順序，所以有限展開不是任意塞進一份既有主線檔就會被接受。六個自製定義／九個節點的候選，證明的是明列靜態範圍與所需接線。

關卡內動態權重、真正可循環流程、道具或任務條件則另列 typed 擴充契約。道具條件若涉及消耗，需要接既有交易與保存，不能把 Client 的外觀附件或本地旗標當成已扣除道具。

分支合流仍取每條入路的保證交集；新原碼證據補上：能離開節點，會保證必要的 Boss／Wave 訊號及全部必要波的前置旗標已成立。公開候選也補到這條跨節點依賴。這比只看 GroupCleared 及出口旗標的簡化模型更完整。[有限展開、入口選路與擴充落點](rules-scheduling/report.md)

### P0-8 倒數與延遲事件

前輪尚未確認的小數秒轉換，現在由真實程式補足：戰鬥／波次期限按時計頻率換成整數 timestamp 增量，採向零截斷；NodeDelay、ClearDelay、RegionHeld 則以 `TimeProvider.GetElapsedTime(...).TotalSeconds` 與 double 秒數比較。兩者不能一律改成相同 round／ceil 公式。

六種計時語意仍各有原點與派送階段。NodeDelay 在開放戰鬥後起算，清場演出經過的時間仍算；ClearDelay 在適用的清場／Portal 提交後，第一次有效位置觀察才起算；占點中途離開會重設未完成的等待。

因此事件索引、波次彙總與 deadline 優化必須保留原時計、精度、合格處理階段及定時先於順序的排序。本輪提供等價條件，沒有用作者模擬取代實際 Server 執行紀錄。[時計與優化條件](rules-scheduling/report.md)

## 3. 門與出口：新增能封路的內容候選與門外觀控制鏈

### P0-9 門、屏障與通路

前輪 Q119 屏障可以繞過；本輪不再只記錄問題，已找出 Map635 的具體替代配置：保留原出生與必要怪物，將出口移到東側小區，以單一 8 格屏障封住自然瓶頸。

| 項目 | 作者候選 |
|---|---|
| 屏障 | `x∈[427,428), y∈[397,405)`，覆蓋 8 個原可走格 |
| 新出口 | `(431.5,401.5)`，半徑 2；原出口為 `(391.5,391.5)`、半徑 6 |
| 閉門 | 出生側與出口側不連通；允許斜向的保守搜尋也不能繞過 |
| 出口互動範圍 | Server 半徑 2 與 Client 類別 0 的約 0.8 倍半徑，依實際浮點值核對的保守相交格都位於門後 |
| 必要條件 | 原必要怪、占點與門前標記仍在出生側可達 |
| 開門 | 出生到新出口有 62 格步數的路徑 |

這是**新關卡候選**：出口移位、互動半徑縮小、通關後要多走到另一個區域，都明確列為玩法差異。靜態通路依二維 BND 及 Server overlay 政策推導，沒有替代完整三維碰撞／角色體積／畫面驗收。[幾何推導與候選](gates-transitions/report.md)

門外觀也找到真正正向鏈：worldID 的 type 7 走 `CEventObject`，actor 狀態 selector `0x1C` 讀 `EventObjects` 的 AVATAR／MOTION。實際表交叉命中 6 個門模型：20055、20056、20109、20148、20159、20162。它們有 state 0／1／2 對 motion 1／2／3 的資料，但沒有實際模型動作語意時，不能替它們擅自命名「關門／開門」。

此鏈提供可供 Server MEF 對接的**門外觀狀態**。真正動態 Client 碰撞仍需分開：本輪查到的額外區域掃描結果沒有參與所選碰撞函式的最終回值，不能把那個容器當成已找到可切換的物理門。[原件 consumer、表資料與碰撞反證](gates-transitions/report.md)

### P0-10 開出口與換圖

本輪沿 Client 點條件與輸入到互動請求，再對照現有 Server 的一般、Story 及功能測試場 adapter。出口意圖只有既有 category／key；目的節點、當前 instance 及所用規則由 Server MEF 解析，不增加 Client 未支援的 token。

實際 Portal 接線也補出精確分支：有清場演出或任一出口未預註冊時，會走 Map／重建／完整點集；全部預註冊且沒有該清場演出時，才可以只更新各點狀態。因此先前針對單次 setter 路線的限制，不能擴張成所有關卡都不准有 ClearScenes。

無論採哪條，開點資格、點集換代、場景 loading、可操控 ready 與 Q 等待都要保持各自生命期。003F 仍可能來自 seen-skip；不能以它證明新 callback、門外觀或本地 setter 確實執行。重建後多步演出只在內容確實需要時新增 hook。[出口與換圖交接](gates-transitions/report.md)

## 4. 現在有哪些 MEF 種類

本輪以用途整理成 **12 類**，同一份內容可組合多類。這是專案能力分類，並未聲稱原版有 12 種 `.mef` 格式。

1. 關卡流程與分支。
2. 生怪與增援。
3. 怪物行為、戰鬥與頭目階段。
4. 機關、占點與障礙。
5. 出口、地圖與轉場。
6. 角色演出與外觀。
7. 劇情、對話與教學。
8. 鏡頭與畫面效果。
9. 音樂、語音與圖片。
10. NPC 與商店服務。
11. 結算、獎勵與進度保存。
12. 輸入、排程與生命週期。

每一類的玩家例子、可用接口、執行位置與限制見 [MEF-TYPES.md](MEF-TYPES.md)。正常 121 binding／15 技術域映射保留原分類：116 個有界可用作用／查詢、4 stub、1 無有效 count。新發現的 Server wire／原生物件能力另外列示，不冒充新增 Lua binding。

## 5. 接續開發應採的路線

優先使用 Server 規則 MEF 編排已存在的 actor、戰鬥、增援、旗標與出口；Client 原生負責已支持的動作、投射物與演出更新。這樣可以先把完整關卡接起來，而不要求普通敵對 AI 全移到 Client 或先建通用常駐 Lua 橋。

內容工作先採用本輪有明確來源的四種補缺範例、有限重複展開或真封口候選。新配置需明確選定，不把它們與前輪不同 Q119 變體默默混成一個已發布版本。

之後以相同內容比較規則求值、波次掃描、時間排程與封包工作量；只有有實測才報效能數字。動態道具條件、真正循環、普通背景 Lua、可見門模型與動態碰撞各按具體需求開發，不把它們混成所有 MEF 的共同缺口。

本包沒有執行目標、修改 Server／原件、部署內容或改正式台帳。八項的分析進度與剩餘工作見 [P0-PROGRESS.md](P0-PROGRESS.md)，整包來源與重驗見 [verification-result.json](verification-result.json)。
