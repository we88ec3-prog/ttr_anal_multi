# Web AI：既有資料整理派工（2026-11-04）

使用者最新規則：MEF檔案搜尋／載入鏈追查等Server開發至少60%以後再處理。本包不重掃封包、不找MEF、不做未授權Client修改／執行。AI/戰鬥核心仍由S00處理，Web端只整理可供審核的資料，Git更新不代表已派送或已接收成果。

## 可貼至Web AI的共用提示

你在ttr_anal_multi整理既有證據供S00開發Server。先同步main、閱讀AGENTS.md與CLIENT-MODIFICATION-POLICY；使用者要求直接main作業，不新建branch。只使用明確列出的既有來源，不重啟MEF搜尋或聲稱找到了原生MEF。逐筆提供來源路徑、commit/blob/member SHA、欄位/函式、判斷與未知。把原生已確認、使用者要求、影片觀察、Server候選政策、資料不足分開；不要提升CLM/SPEC成熟度或APPROVED。沒法讀到的來源明記，不能補造官方數值。成果放本handoff子目錄，附機器可讀JSON/CSV、來源對照和未知清單；供T01來源驗證及S00實作採用。

### A：生怪與事件資料定義（目前可做）

參考governance/s00-iterations/S00-20261104-ALSMEER-STORY-CONTINUATION.md、其resource-baseline evidence、既有Field/Case/MapFlow/Cluster與T16來源。整理Case101/103/107/108/109的node順序、選定cluster與所有未採用group、怪物ID/count/PRE、清怪條件、場景cue和出口依賴。交付ScenarioDefinition/SpawnGroup/Condition/Action/PortalDefinition的typed欄位與source-ref。COUNT不可冒稱整場總怪數、editor座標不可冒稱遊戲座標、有限cluster不可叫官方波次。不要新增所有怪AI的猜值。

### B：怪物AI資料與動畫/戰鬥介面（目前可做）

先1001/1009，必要時1004。整理已收錄Monster/Skill/Actor/ABF與現有AI分析，欄位對照感知/追逐/回位/選招/起手/命中/冷卻/受傷/死亡。區分呈現動畫時長、Server判定時間與候選節奏；指出既有資料是否足以定義AIProfile、哪部分缺官方規則。不要從玩家SubAI入口、動畫FPS或影片感覺直接推定官方AI演算法。輸出AIProfile-schema與逐怪可用/未知欄位表，S00負責核心引擎與連段。

### C：S00後續副本實作時處理，不列目前Web派工

使用者要求：通關傳送陣在通道底端、使用大型傳送陣、走上按Z才觸發；敵人出生不要貼近玩家入口。參考影片https://youtu.be/A3-XRUsrcTM?t=566，逐圖確認入口/通道/出口/怪群相對位置；不能僅憑畫面宣稱絕對世界座標。若影片不可讀要明記，不能稱已觀看。現有packet27 radius與effect scale是否共用需有既有consumer證據，不以放大互動半徑假稱美術傳送陣已放大。交付驗收項與影片時間點，不現在批次套用全圖猜座標。

## 暫緩

MEF sample inventory、再次全包掃描、完整loader/parser/network-receive追查：Server功能開發至少60%以後另行排程。NativeMefReader/Client收MEF仍BLOCKED_BY_FORMAT，不把自訂JSON改副檔名冒充。來源核驗、S00採用與真人驗收分開。此文件是可交接工作包，尚未實際送給Web對話。

## 上班時低操作量的派工方式（最新）

目前只派A/B，皆以Git已存在的來源一次下令完成，不要求使用者尋找影片、提供截圖、逐段播放或即時互動。C由S00在各副本實作時另處理；已有影片保留參考，使用者不必補找對應影片。若來源讀不到或資料不足，Web需交缺口清單與可做的部分，不把任務卡在等待使用者補素材。MEF搜尋仍等Server至少60%。

## 材料放置政策

依使用者確認，原BIN/STP/ABF與遊戲member留本機、由使用者另行上傳Web；不放Git。Git只存報告、資料定義、SHA／來源對照及未知清單。已整理本機初始包128檔約0.96MB，讀回檢核通過；它含Case/MapFlow/Cluster/MapList/QuestInfo、ActorList與部分Skill表、既有T10/T11/T16引用報告，未含BIN、raw Actor/ABF body或已確認Monster table。先做可用欄位與缺件精確member盤點；不能將原料尚缺寫成完整AI還原。包內Table carrier為已知variant，各member原始SHA符合情況逐一標明，不從載體相同／不同推論所有member版本。
