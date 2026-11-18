# P0-5～8：增援、清場、分支與計時的實作輸入閉合

本輪把前次留下的四種公開範例缺口補成新的作者輸入，並直接核對固定版本 Server 程式。交付 **6 個關卡定義、9 個節點**，涵蓋進區伏擊、頭目擊倒事件、初始空場、具名波次頭目、固定三輪展開，以及跨節點的必要清場旗標。這些內容通過既有 JSON Schema、條件依賴和原 Map193 BND 的靜態檢查；尚未載入真正 Server、Client 或 Lua，也沒有部署到正式關卡。[分析結果](analysis-result.json)、[作者來源清單](examples/manifest.json)

這裡的 MEF 是 Server 提供的關卡規則與演出編排。既有 typed Server 規則也是 MEF 的開發面，不以還原官方檔案格式作為功能完成前提。用途可組合，並非新宣稱數種官方 `.mef` 格式。

## 1. 分析進度與實際缺口

| 項目 | 本次完成的分析 | 玩家能理解的效果 | 接續開發／整合需求 |
|---|---|---|---|
| P0-5 分批增援 | 固定程式確認定時先、順序後；四缺口候選；初始空場與波次身分 | 先等一下才出怪、走到區域才伏擊、清完一批再來一批 | 將選定作者檔登錄到實際內容目錄及入口；依正常流程驗收出怪時點 |
| P0-6 清場與頭目 | Mission／Lab 清場門檻、必要波、敵方投射物、頭目唯一匹配、死亡與移除分層 | 場上暫時沒怪不會提前過關；必要頭目與後續增援都完成才離開 | 沿所選場景 adapter 接清場；確認 Client 實際死亡與移除畫面 |
| P0-7 分支與旗標 | 合流保證、三次有限展開、入場一次加權選擇、物品／任務條件的現有服務對應 | 左右分路、三輪房間挑戰、進場選一種玩法 | 加權入口及道具條件是明確新 adapter；動態循環另有新規則需求；泛用圖不能直接越過主線 binding 限制 |
| P0-8 倒數 | 六種起算原點、處理階段、實際小數秒轉換、排程等價條件 | 增援、占點、清場後等待各自準時，劇情時間不會套錯 | 新排程器保留原時計與比較法，再量測；新內容仍需正常時間流程驗收 |

狀態是「有界能力、來源與實作輸入分析完成」。未將作者分析器當成 Server typed loader，亦未把尚未實作的新 adapter 寫成既成功能。[執行契約](execution-contract.json)、[擴充契約](extension-contracts.json)

## 2. 本輪來源與可重跑範圍

分析庫固定基準為 `19005c9f8a8180e6f0deb00faf008a11ef98023f`。新加入的私有 Server 原碼固定於 `we88ec3-prog/ttr_server_roy` 的 `e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4`，tree `1c42df357de7385bb0263732c9c8a33550a8f571`。本子題核對 14 個完整檔案的 bytes、Git blob 與 SHA-256，並保存 39 個有界視窗的行位、byte offset／length、SHA-256 和語意索引；完整 Server 原碼保持在私有 scratch。後文 `S01` 等識別字均對應這些精確視窗。[Server 證據索引](server-code-evidence.json)

28 個分析庫來源包含實際 schema、functional-lab JSON／profile、前輪波次／地形分析和固定文件。歷史 Markdown 用 immutable Git object 核對；真正輸入 JSON、schema、匯入 helper 必須同時與工作檔逐 byte 相等。原 `07-Table.stp` 與 `10-BoundMap.stp` 先核整檔 hash，再只讀 `Table/_MapList.xml → Map193 → BoundMap/keep04.bnd`，不把整份原件搬進 Git。[來源清單](source-manifest.json)

地形結果為 **39 個位置、2,160 個出生點至目標線段取樣、8,158 個圓域取樣**，皆無阻擋樣本，位置在相同四鄰接可走區。BND 是 768×768 格、768×768 世界範圍。這證明本包選定二維點位與取樣路線，並不包含怪物體寬、Client 三維模型碰撞或實際玩家操作。[完整幾何結果](analysis-result.json)

## 3. P0-5：波次按什麼順序出現

實際 combat `Poll` 的相關後半段依序為：敵方更新與敵方投射物、地形傷害、波次血量觀察、定時波、順序波。波次血量變化在正常觀察階段轉為旗標，定時波先依原陣列順序檢查；某個定時波等區域或旗標，不會阻擋其他合格定時波。順序波只處理下一筆，且一個有效 Poll 最多生成一個順序波。[S13～S16](server-code-evidence.json)

兩種波都要求玩家存活、相應普通 expanded 戰鬥模式、時間到、全部 `requiredFlags` 和目前位置在 `activationRegion`。定時波從**當前 combat instance 建立**起算；順序波從順序處理階段首次看到聚合敵人 HP 為零時起算。生成任何新波會清掉先前空場計時與勝利等待。若先到期的定時波放進活怪，當次順序波不會繼續以舊空場時間放怪。[S11、S15、S16](server-code-evidence.json)

初始空場不虛構一個已清掉的 `null` 波次：初始波數為 0，不建立其血量觀察者。仍有設定的必要波時，總波數大於已生成波數，因而不能清場。空場第一個順序波在有效順序處理階段開始倒數；若同次的定時波先生成，順序倒數要等後來真的清空。[S11、S12、S15](server-code-evidence.json)

`RegionEntered` 與 `activationRegion` 不同。前者一旦經有效位置觀察成立便留下本場旗標；後者在放怪當下仍需人在區內。正常 world 更新中，NodeDelay 觀察在 combat Poll **之前**，位置／RegionEntered 觀察在其**之後**，因此不能保證剛在後半段取得進區旗標，就在同一個 Poll 補出那一波。[S08、S15、S22](server-code-evidence.json)

本輪的四個最小例子如下，均明示為自行編寫的分析輸入：

| 定義 | 使用既有欄位的安排 | 補上的缺口 |
|---|---|---|
| `p0-region-entered-candidate` | 進區旗標＋2 秒 NodeDelay 共同解鎖 1 秒定時波；清場後另等 2 秒 ClearDelay | 原公開內容缺 RegionEntered 的可檢查作者例 |
| `p0-boss-defeated-candidate` | 初始唯一 Model1001／PRE1 頭目，擊倒後開放 Model1009 增援 | BossDefeated 有實際生產者與消費者 |
| `p0-empty-initial-candidate` | 初始無怪，先等 2 秒出第一波；其清除旗標再解鎖第二波 | 空初始不被誤判清場 |
| `p0-named-wave-boss-candidate` | 初始無怪，5 秒後 `boss-entry`；requiredBoss 明確綁該波 | requiredBoss.waveId 與延後頭目 |

Model1001、Map193、原出生點／出口及 AI profile 取自既有 `content-lab-wave-clear`。Model1009 也在既有 `region-wave-example.scenario.json`，不是臨時發明怪物資料。新增位置仍逐一重核 BND。時間是作者選擇，不聲稱來自官方關卡。[作者說明](examples/README.md)、[missing-coverage.scenario.json](examples/missing-coverage.scenario.json)

## 4. P0-6：打死頭目與整關清場如何分開

`BossDefeated` 在有效致死傷害路徑通知 scenario；`WaveCleared` 在該波已生成成員的聚合 HP 變為零時通知。它們可以早於死亡動畫／移除，不等於整節點已可過關。波血量百分比用整數交叉相乘比較；死人仍保留在最大 HP 的分母，不能把死亡成員移除後誤算剩餘百分比。[S07、S14、S19](server-code-evidence.json)

頭目設定的精確規則：省略 `requiredBoss.waveId`，會在本節點的初始、順序、定時全部出生中以 Model／PRE 匹配，typed loader 要求**恰好一隻**；指定波名才只查該波。這與波次觀察事件的 `waveId:null` 代表非空初始波不同。本輪 BossDefeated 例故意讓後續增援改用 Model1009，避免產生兩隻相同 Model1001／PRE1 而不符唯一匹配。[S01、S02](server-code-evidence.json)

| 清場 consumer | 必要門檻 |
|---|---|
| `ReadyToReturn`，功能測試場採用 | 所有設定波已生成；總 HP 為 0；玩家活著；無**敵方**飛行投射物；勝利等待已到；有指定頭目時還要匹配頭目 HP0 且移除已排送 |
| `ReadyToClearMissionNode`，一般主線／一般副本採用 | 上列全部，再要求所有敵人的 `RemoveAt` 清空 |
| 一般副本 StageOne 提交 GroupCleared | 再等 `PendingStageOneDefeatExperience` 為 null |

expanded 勝利等待是 1.25 秒，非 expanded 是 0.75 秒。敵人移除要同時到期且沒有該敵人作為來源的敵方飛行投射物，排入移除封包後清空 `RemoveAt`。這是 Server 更新完成的門檻，並非已收到 Client 模型回收回報；也沒有證據支持把所有種類投射物一概加入此判定。[S12、S17、S18、S22、S29](server-code-evidence.json)

全必要波、Boss、玩家存活、投射物與移除時間由同一執行器各守其職。新 MEF 只需消費其有效事件並使用正確 adapter，不必另維護一個「畫面看起來空了」的清場計數。

## 5. P0-7：分支、固定輪數與較小的擴充面

### 5.1 跨節點旗標已有比前輪簡化器更完整的保證

現有 validator 在合流節點取所有入路的**保證交集**。離開前一節點後的保證集合包含：之前已保證的旗標、GroupCleared／BossDefeated／全部波次血量觀察事件、全部必要波的 `requiredFlags`、選定出口的 `requiredFlags`，再加上已保證手動互動所隱含的前置旗標。因離開必須完成全部必要波，這些條件有來源；不能只保留 GroupCleared 與出口條件。[S05、S06](server-code-evidence.json)

新 `p0-cross-node-wave-guarantees-candidate` 第一節點的出口刻意**不要求** Boss/Wave 旗標；第二節點的增援仍依賴第一節點必然完成的兩個旗標。新版靜態投影與精確 Server 規則相符，補正前輪可能錯拒這類有效輸入的保守簡化；不回頭改掉舊證據包。[cross-node-guarantees.scenario.json](examples/cross-node-guarantees.scenario.json)、[分析結果](analysis-result.json)

### 5.2 固定三輪可編譯成有限圖

本包的作者 helper 僅處理「一個節點模板、固定輪數、每輪各自的旗標」子集。第 i 次拜訪編成新 node i、新 encounterGroup；每個訊號生產者和 `requiredFlags`／`opensWithFlag`／`disabledByFlag` 都改寫為 `visit<i>.*`。波名保留在各節點自己的範圍，世界 actor ID 仍交原執行器配置。前兩輪出口改成 NextNode，第三輪才是 Result。[展開對照](repeat-mapping.json)、[作者 helper](build_authoring.py)

這把原本想像中的「循環計數」轉成目前合法節點身分，無須新增 Client wire 或循環 runtime。合成後仍受 256 節點、64 旗標、名稱長度與各節點波次／怪物上限約束。helper 對分支模板、掉落政策及未宣告跨輪旗標直接拒絕，沒有偷偷推測其重設方式。[S03～S06、S10](server-code-evidence.json)、[bounded-repeat.scenario.json](examples/bounded-repeat.scenario.json)

三輪範例明確將擊倒／清場經驗設 0，沒有掉落與 completionExperience；只有一個 Result，**並未自動創建最終獎勵**。實際採用時由所選既有 adapter 指定最後獎勵政策。若每輪要給獎，需按展開後的發生次數計算，不能一面複製有獎勵的模板一面宣稱只有最後一次發獎。旗標作用域及獎勵作用域必須分開宣告。[擴充 E2](extension-contracts.json)

節點換代可能重建同張地圖與怪物，與同一房間連續出三波不同。希望戰鬥不中斷時，直接用既有 reinforcement 陣列。跨節點保留玩家資源／冷卻則使用支援此功能的主線 adapter 與其選項，不把它視為所有節點的預設。[S23、S24](server-code-evidence.json)

### 5.3 入場一次選配置，比關內隨機小得多

`weighted-entry.plan.json` 是**新入口 adapter 的分析提案**，不是現有 scenario schema 欄位。候選目錄固定 hash，兩個 definition 的權重為 2:1。受信入口給均勻整數 `[0,3)`；原順序累加後 `[0,2)` 選進區例、`[2,3)` 選具名頭目例。選擇發生在 instance 建立前，當場保存 run 身分、definition、內容 hash 和政策版本；換圖／重建不重抽，選中本身不發獎。[加權提案](examples/weighted-entry.plan.json)、[擴充 E1](extension-contracts.json)

持有道具或任務已完成，可先讀現有保存服務，作為入場候選過濾。它不等於關內即時改變權重。關內重抽、真正循環、跨重登續跑，仍需新的次數作用域、重設／保留規則、終止條件與保存政策。[擴充 E3～E5](extension-contracts.json)

### 5.4 道具與任務條件已對到現有服務

| 需求 | 可重用的現有入口 | 最小新增部分 |
|---|---|---|
| 持有 Product | `ILocalTownTradeStore.ReadAuthorizedAsync(SessionLease)`，實作以同筆 deferred SQLite 交易讀授權帳號錢包／背包 | 有型別 HasProduct predicate；明確數量、是否包含獨立裝備、入場快照或使用當下判定 |
| 普通任務狀態 | `ReadHuntingQuestAsync(lease, role, ct, questId)` | 對已接入的 Quest／role 建 QuestStep predicate；沿現有旅程及前置任務資格 |
| 扣鑰匙後開門 | 現有交易服務的背包讀寫與提交收據模式；任務交付已有同筆交易扣收集品和更新進度的先例 | 新的消耗門鎖 operation，在同筆交易扣物品並記成功操作；提交後才投影為本場開門狀態 |

現有 `LocalTownBagStack.Item` 是歷史欄位名稱，交易實際使用 Product 身分；不能拿背包格或 Item.xml row 直接替代。普通任務路徑使用已授權 SessionLease 及本機 role byte，不能混成另一條 selected-character 路徑。任務 UI 目標列只是已保存狀態的投影。[S31～S38](server-code-evidence.json)

現有回復卷軸／商店 API 並不是泛用消耗鑰匙 API。新 operation 的輸入、交易、收據、提交後背包／快捷列發布及關卡旗標投影已列入契約；若只是檢查持有物品，要明確選「第一次打開就固定」或「使用時重新檢查」，因既有出口開啟是 latch，不能直接代表會失效的持有條件。[擴充 E3、E4](extension-contracts.json)

### 5.5 真正採用時的內容限制

功能測試場的 mode→definition 是明列的目錄，複製新 JSON 並不會自動多一個可選模式。一般主線 override 更要求綁原 narrative hash，保留節點數、節點編號對應地圖及初始怪物模型順序。因此固定三輪候選應接支援此圖的正式入口，不能宣稱直接覆蓋任意既有主線就會成功。[S27、S30](server-code-evidence.json)

## 6. P0-8：六種時計與精確小數秒比較

| 時間語意 | 起算點 | 到期比較／處理時機 |
|---|---|---|
| C1 定時波 | 當前 combat 建立的 entry timestamp | combat Add 算期限；定時陣列檢查，先於順序波 |
| C2 順序波 | 順序處理階段第一次觀察聚合 HP0 | combat Add；仍要下一波條件成立；新波重設空場期限 |
| C3 空初始第一個順序波 | 第一個合格順序處理階段 | 沒有假的初始清場事件；當次定時波可能先阻擋空場 |
| C4 NodeDelay | ActivateNodeTimer；主線在 Encounter phase | elapsed seconds 比較；正常更新在 combat Poll 前 |
| C5 ClearDelay | 清場後首次有效位置觀察；主線在 Portal 提交後 | elapsed seconds 比較；保存及先前清場劇情不預付等待 |
| C6 RegionHeld | 首次有效區內位置觀察 | elapsed seconds 比較；未完成時離開／死亡／清場計畫會重設 |

六種語意已逐項對到實際程式，不再留下「小數秒取整待猜」的缺口。戰鬥 Add 是 **double 秒數乘該 TimeProvider 的 TimestampFrequency，轉 long 向零截斷，再做 checked timestamp 加法**；必須保留 double 乘積本身，不以十進位精確乘法、round 或 ceil 代替。NodeDelay、ClearDelay、RegionHeld 則直接使用 `TimeProvider.GetElapsedTime(...).TotalSeconds` 對 double 秒數比較，並沒有先套相同 Add 的轉換。[S08、S20](server-code-evidence.json)

World、scenario、combat 共用注入的 TimeProvider，預設 System；沒有在這裡猜一個固定時計頻率。實作應保留同一部署的 .NET `GetElapsedTime`／TimeSpan 行為。本分析確認呼叫鏈與兩種比較法，不自行重寫 framework 後宣稱完全相同。[S21、S22、S24、S28](server-code-evidence.json)

主線的 Combat transition 會在入場演出後重新建立 combat，因此不能拿先前演出前的分配時間，推論定時波一定包含整段入場演出。NodeDelay 在可戰鬥階段啟動；清場演出雖暫停派送，其經過時間仍反映在相同 node 時計。ClearDelay 的原點刻意更晚；未完成的 RegionHeld 則在清場計畫重設。[S23～S26](server-code-evidence.json)

## 7. 可以優化，但必須保留什麼

| 優化方向 | 等價條件 | 才值得量測的項目 |
|---|---|---|
| 事件／旗標消費者索引 | 相同 instance、ALL 條件、原處理階段；RegionEntered 不提前到 combat 前 | 每個有效事件實際求值的規則數 |
| 波次 HP／存活數彙總 | 只採有效 HP 變化；死人最大 HP 留分母；未生波不算清空；回位／回復也正確更新 | 每次更新省下多少 actor 掃描 |
| deadline 候選佇列 | 相同兩種比較法；最終仍用原 predicate；定時陣列順序、順序波一次一批、故事可處理階段不變 | 倒數檢查次數及事件順序 |
| immutable plan 共用 | 只共用 definition／版本；旗標、時計、出口和使用狀態仍各場獨立 | 內容建構次數與配置量 |

現有實作**已經**做到 HP 未變不回呼、清空波退出觀察清單、定時波生成集合及旗標 latch；不能再把它們當成本輪新增的效能收益。新的彙總或索引仍需正常流程對照相同出怪／旗標／清場序列後才能報數字。[S07、S11、S14、S16](server-code-evidence.json)、[優化契約](optimization-contracts.json)

## 8. 重跑方式與交付範圍

在 repo 根目錄執行下列唯讀驗證，`--sources` 指向原件所在資料夾，`--server-sources` 指向固定版本私有程式 cache：

```bash
python kr-extra-roy/MEF-P0-level-execution-20261118/rules-scheduling/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --server-sources /absolute/path/mef_p0_level_server_sources_20261118 \
  --receipt /tmp/mef-p0-rules-receipt.json
```

不帶 `--receipt` 時僅輸出結果，不改包內既存收據。驗證先核交付檔與來源身分，再重新產生作者 JSON 的預期內容、跑 schema／相依／BND 分析，最後比對保存的分析結果及契約參照。本包不執行 Server typed loader、Server／Client／Lua、部署或正式台帳更新。[唯讀 verifier](verify_evidence.py)、[本次收據](verification-result.json)
