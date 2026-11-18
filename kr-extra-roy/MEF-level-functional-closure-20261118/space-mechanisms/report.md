# 關卡 MEF：地圖、出口、區域與機關的功能閉合

基準：`extra/roy1`，`09799b117f01e577be56dee3e909e1cde25b855f`。本分題完成的是**現有能力、實際內容、幾何限制及實作差額的分析**；不新增正式玩法、不執行遊戲／Lua／Server、不變更既有關卡或人測認定。完整來源與 Git blob／SHA-256 見 [source-manifest.json](source-manifest.json)，可重算資料見 [spatial-evidence.json](spatial-evidence.json)。

## 1. 先說玩家會遇到什麼

目前的 Server MEF 已能用資料描述「進哪張圖、從哪裡開始、怪站哪裡、走哪個出口、按一次開關、站圈幾秒、地板定時扣血、旗標解除障礙、怪物巡邏和繞牆」。這些功能由 Server 供應／執行也算 MEF；原生 Client 已有的點互動、傳送陣效果、移動與動畫則優先重用。現有資料不是空白，亦不必等待官方 `.mef` 格式復原才能開發。[現行方向](../../MEF-CURRENT-DIRECTION.md)、[現行 schema](../../../design/scenario-content/local-scenario-definition.schema.json)、[空間契約](spatial-contracts.json)

本次重新檢查實際地形後，找到兩個必須明說的差額：

1. **舊的分岔教學範例有十個座標落在不可走格**，不能因 JSON 和分岔圖驗證通過就拿它當可玩的關卡。本題已給出具體替換座標並重算通過，沒有修改原範例或選定正式版本。
2. **Q119 的屏障目前能擋直走，仍可繞過去**。出口本身仍受清場／旗標條件鎖定，因此走到出口不等於能過關；但這個配置應稱局部障礙，不能說它已是一扇封死通道的實體門。[十點明細與繞路證據](spatial-evidence.json)、[修正候選與接受條件](content-remediation.json)

「機關分析完成」也不代表畫面已驗收。傳送陣亮起、可按 Z、三維門模型移動、實際碰撞改變是不同效果，不能拿其中一個成功代替另外三個。

## 2. 不是再做一遍二進位盤點：本次查的是實際關卡內容

固定稽核 `design/scenario-content/*.scenario.json` 的 **67 檔、86 個 definition 出現項、399 個 node 出現項**。同一主線有成長、屏障、陷阱、巡邏及歷史版本，不能把這個數字稱為 86 個獨立可玩副本。規則圖／旗標依賴另由 [rules-waves](../rules-waves/report.md) 分題分析；本題獨立把每個 map、座標及空間條件接到原件 BND。[本題來源清單](source-manifest.json)、[內容計數](spatial-evidence.json)

| 稽核項目 | 本次結果 | 結果能支持什麼 |
|---|---:|---|
| MapID → `_MapList` → BND | 118 個 MapID，74 個不同 BND 成員，全部有唯一 MapID 對應 | 可以選對此資料版本的地形；MapID 並不等於場景載入已完成 |
| 出生點 | 399 個出現項 | 包含同地圖／候選版本的重複配置 |
| 出口中心 | 444 個：399 主出口、45 替代出口 | 核對實際座標與出生點所屬的靜態連通區 |
| 初始／增援怪中心 | 895 個 | 同時包含順序與定時增援；不僅查初始怪 |
| 其他中心 | 25 個 | 增援區 7、出口區 2、占點區 1、傷害區 1、手動區 4、手動標記 4、屏障標記 2、巡邏點 4 |
| 合計中心 | 1,763 個；1,753 個可走且與出生點同一四鄰連通區 | 十個不合格中心全部屬於一份舊分岔範例 |
| 同節點出口圓相交 | 0 組面積重疊 | 只比較配置半徑；不代替啟用時序、攝影機或實際按鍵驗收 |
| 原生點證據 | 重驗 13 個既有有界窗口 | 確認相同 BIN／VA／原始位移與窗口 hash；沒有宣稱重新完成全程式反編譯 |

以上是實際重算結果，原件 `_MapList` 共 3,982 列；只輸出本題用到的對應、hash、統計及有界衍生資料，未輸出完整解碼成員。表中 118 與先前提到的 117 沒有資源新增：**Map192 只在 `branch-example.scenario.json` 出現，排除該範例便是 117 個 MapID**。[機讀 evidence](spatial-evidence.json)

### 幾何判定的精確範圍

沿用既有 Server 政策：BND 第 0、1 層任一非零格都視為阻擋；座標按實際格數與 world extent 投影；以四方向相鄰格檢查出生點到目標中心的連通性。屏障另外以格中心投影，左／上界包含、右／下界不包含。原始 BND 保持唯讀，實例屏障另疊加。[既有靜態政策實作](../../MEF-P0-P1-master-continuation-20261117/journey-families/audit.py)、[本次重算程式](audit_spatial.py)

這比「座標是有限數值」或「單一中心格可走」多查了路徑連通性，但仍是**點與靜態二維格的證據**。它不證角色身體寬度、整個圓的連續可達性、三維高度差、會移動的障礙、其他角色碰撞或指定 Client 的真實場景碰撞。對陷阱、占點、互動及修正候選另做 0.25 單位採樣，採樣通過也不提升為完整三維通行證明。[`scope` 與每項採樣結果](spatial-evidence.json)

## 3. 新發現一：舊分岔範例的十個不合格座標

`branch-example.scenario.json` 的 definition 是 `authoring-branch-example`。它的圖結構可以表達分岔／匯合，但下列實際中心落在原件靜態阻擋格：

| Node／Map | 不合格中心 | 數量 |
|---|---|---:|
| 1／191 | 主出口 `(110,100)`；分支出口 `(120,110)` | 2 |
| 2／192 | 出生 `(418,385)`；出口 `(120,100)`；怪物 `(426,385)` | 3 |
| 3／193 | 出口 `(130,100)`；怪物 `(426,385)` | 2 |
| 4／194 | 出生 `(418,385)`；出口 `(140,100)`；怪物 `(426,385)` | 3 |

分成 **5 個出口、2 個出生點、3 個怪物點**。其餘 66 檔共 395 個 node 出現項、1,750 個中心，未發現同類中心阻擋／分量分離問題；這不是把 66 檔列為已部署或玩家通關通過。[`nonreachable_points`／`node_results`](spatial-evidence.json)

### 已具體化的修正方案

只替換座標，保留原來 MapID、出口 key、分支目的地、怪物模型和其餘規則。Node3 原出生點雖可走，這份候選一起移到既有內容使用的區段，讓怪物與出口構成短而明確的路線。

| Node／Map | 候選出生 | 候選出口 | 候選怪物 |
|---|---|---|---|
| 1／191 | `(418,385)` | 主 `(430,385)`；分支 `(418,373)` | `(426,385)` |
| 2／192 | `(379,369)` | `(391,369)` | `(385,369)` |
| 3／193 | `(377.5,315.5)` | `(377.5,307.5)` | `(377.5,291.5)` |
| 4／194 | `(383.5,279.5)` | `(383.5,271.5)` | `(383.5,255.5)` |

本題把候選套入記憶體副本後重新查 **13 個中心全部可走、全部與出生點連通、出生至各中心的直線採樣無阻擋、5 個半徑 3 出口圓的採樣無阻擋**；第一圖兩出口也不重疊。具體差額及接受條件保存在 [content-remediation.json](content-remediation.json)，驗證輸出在 evidence 的 `branch_example_coordinate_remediation`。既有來源沒有被改寫。若日後選用，需走既有可分岔的共用 adapter；不能把四節點候選塞進只准入兩個固定主線節點的 adapter。[分岔契約](../../../governance/s00-iterations/S00-20261111-SCENARIO-BRANCH-CONTRACT.md)

## 4. 新發現二：Q119 的障礙可以繞行，與出口資格是兩件事

三份候選 `story-q119-barrier`、`story-q119-barrier-marker`、`story-q119-region-hold` 在 Map635／Node4 使用同一矩形：`385 ≤ x < 387`、`389 ≤ y < 395`。它覆蓋 **12 個原本可走的格**，沒有把配置的出生、怪物、區域中心或標記放在關閉格上。[屏障規格](../../../design/scenario-content/FLAG-BARRIERS.md)、[本次 overlay 證據](spatial-evidence.json)

從出生 `(379.5,391.5)` 直走出口 `(391.5,391.5)`，開啟時 49 個樣點全可走；關閉時有 8 個樣點被擋。可是關閉狀態仍存在下面的四鄰路徑：

| 次序 | 可走的轉角／終點 | 這一段距離 |
|---|---|---:|
| 起點 | `(379.5,391.5)` | — |
| 1 | `(384.5,391.5)` | 5 |
| 2 | `(384.5,388.5)` | 3 |
| 3 | `(391.5,388.5)` | 7 |
| 4 | `(391.5,391.5)` | 3 |

合計 **18 個四鄰步**；四段分別 21、13、29、13 個樣點，均沒有碰到靜態牆或關閉屏障。這是衍生的靜態點路徑，不是實機移動錄影，也未包含角色半徑。[`closed_barrier_route_witness`](spatial-evidence.json)

現在最合適的落地方式是保留這個配置，明確描述為「有障礙可繞行，但出口須先完成條件」。原設定要求 `exit-gate-open`，Server 仍以當前實例的 `OpenExitKeys` 和其他出口條件決定能否離開；走到門邊、看到特效或直接走繞路都不等於過關。[條件出口契約](../../../governance/s00-iterations/S00-20261111-CONDITIONAL-EXIT-CONTRACT.md)

如果玩法需求確實是「門沒開就到不了後方」，需要把障礙放到真正的瓶頸。接受條件應明寫：關閉時出生區與受保護目的地不連通；所有必打怪與開門機關仍可從關閉側到達；開啟後才有路；重疊門須遵守全部覆蓋旗標；遠端半徑互動不能隔牆選到另一側。最後再接一個真正的門模型與 Client 碰撞契約。不能只把矩形任意拉長，也不能把 portal setter 當作改動實體門。[兩種政策與逐條接受條件](content-remediation.json)

## 5. 四個 consumer 的責任分清，MEF 才能正確減少 Server 工作

| 玩家看到的現象 | 已建立的 consumer | MEF 現在可以怎麼做 | 仍缺什麼 |
|---|---|---|---|
| 可以對某個點按 Z | `544730` 讀 `point+0x105`，再查距離／模式／輸入 | `0048` 或現有 Lua setter 經 `544940 → 543B30` 改同一個已安裝點 | 場景／owner／模式必須正確；缺失點不能靠 setter 自動建立 |
| 出口傳送陣變成開啟外觀 | `543B30` 的 category0 分支精確判 `status==1` | 可讓 Client 執行已支持的本地點效果切換 | 不證門模型動畫，也不證通路碰撞改變 |
| 一扇三維門升起／打開 | 此次點 consumer 沒有建立這條門 mesh 接線 | 自有 MEF 可以宣告要做的門演出，再綁定選定資產與控制器 | 具體資產、公開可達操作、生命週期及碰撞配對是 Server MEF 整合需求 |
| 人／怪／攻擊不能穿過門 | 現有 Server BND ＋ flag barrier overlay | 由提交後的同一實例旗標開關 overlay，失效舊繞路 | 指定 Client 的動態碰撞／角色寬度／三維地形沒有因點變亮而獲得證明 |

重驗的 BIN 是 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；13 個有界窗口的起訖、VA→raw 對應與 hash 全在 evidence。原生解讀復用 [點生命週期與場景研究](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)、[上輪現行能力報告](../../MEF-server-provided-capabilities-20261118/npc-progression/report.md) 及 [category1 邊界](../../../governance/s00-iterations/S00-20261111-CHECKPOINT1-NATIVE-BOUNDARY.md)，不是新造 API。

### 出口與手動機關的精確距離

Category0 的 Client 有效半徑是 wire radius 的 **0.8 倍，且距離要嚴格小於**。例如配置／Server 半徑 6 時，Client 的此輸入門檻是 `<4.8`，不能說站在 Server 的六單位範圍邊緣就一定能按到。Category1 不走 category0 的縮半徑分支，原生使用 `<wireRadius`，Server 的圓形驗證則含邊界。建議作者工具分別顯示 Server 圓和 Client 可按範圍；不要為了讓畫面「差不多」就默默改掉所有半徑。[點原生邊界](../../../governance/s00-iterations/S00-20261111-CHECKPOINT1-NATIVE-BOUNDARY.md)、[位置候選](../../../design/runtime-content/STORY-PLACEMENT-CANDIDATE.md)

Category1 互動已有 Server 單次開關接線：可要求清場與前置旗標，接收到正確同實例／當前節點的意圖且角色存活、在區域內才立旗標，再停用。四個現有手動配置出現項都在 Map193 `(377.5,315.5)`、半徑 4，圈內各 797 個採樣點沒有靜態阻擋。它可以做玩法上的一次機關，並不自動產生寶箱模型、拉桿動畫、物品或永久存檔。可見提示用另一個保持關閉的 category0 點，避免提示點搶走真互動。[手動契約](../../../governance/s00-iterations/S00-20261111-MANUAL-INTERACTION-CONTRACT.md)、[實際配置稽核](spatial-evidence.json)

### 同一張圖也可能已經是另一代點集合

`0027` 先刪整組點，再建立每列 18 bytes 的新集合；`0048`／Lua setter 只改當時找到的 `(category,key)`。因此進場要一次安裝完整點集合，演出後要重建也要一次包含所有仍需存在的出口／互動／標記。Q119 清場演出後的完整重建，會覆蓋先前本地 setter 的狀態；必須把應開啟的狀態帶回新快照，或在重建後才對仍存在的正確點操作。[原生點快照證據](../../MEF-server-provided-capabilities-20261118/npc-progression/native-evidence.json)、[主報整合交接](../README.md)

`001C` 只有 category/key，不帶 map／run。新節點沿用相同 key 或同圖重新安裝點時，舊排程就可能碰到另一代物件。Server MEF adapter 應以自己的實例、節點、內容版本和安裝代數綁定排程，失效舊工作後才供應新集合；不要憑空添加 Client 不會讀的 wire token，也不要假定換 Field 自動取消舊 coroutine。[場景生命週期研究](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)

## 6. 各功能的進度與缺少項目

以下「分析完成」表示已指出現有做法、實際配置、消費端和可驗收的差額，不是宣告新增功能已部署。既有 Server 能力按原契約保留；本輪只補新分析和靜態證據。

| 功能／玩家語言 | 分析與資料進度 | 已可用的 MEF 路線 | 還缺的具體項目 |
|---|---|---|---|
| 進圖與出生 | 118 MapID／74 BND 全部接通；十個舊示例壞點已定位並有修正候選 | 以 node map/spawn 編排，接現有場景初始化 | 選定發行配置與 owner／載入完成契約；不能用已寫 MapID 當 ready |
| 清怪後開出口／選岔路 | 444 出口中心、45 替代出口與半徑重疊已查 | Server MEF 判資格，原生點顯示與按 Z，現有 adapter 換圖／結算 | 全點重建、精確 key／目的地延續；可見半徑、攝影機與實際選取仍待正常遊玩驗收 |
| 按開關 | 4 個實際手動區出現項、幾何與 category1 consumer 已查 | 單次 category1 意圖 → 現有 MEF flag → 出口／增援／屏障 | 選定拉桿／寶箱等外觀時才補模型與演出接線；現在的提示圈不能稱實體機關 |
| 走入區域 | 已分清一次旗標和當前站位條件，中心幾何已查 | 圓形 RegionEntered／wave activationRegion／exit activationRegion | 跨越但沒被觀察到的區域不保證觸發；若要多邊形、高度、全隊占區需擴 schema 與 predicate |
| 站圈 2.5 秒 | Q119 Map635 占點區與關閉側可達性已查；直線 33、圓內 197 採樣全可走 | 現有 RegionHeld 計時與旗標接 barrier／出口 | 指定 Client 的占點提示／倒數與估計位置配對；不能拿主線演出時間填滿占點 |
| 陷阱定時扣血 | Q119 Map632 直線 73、圓內 441 採樣全可走，現有傷害／停用語意已查 | 半徑 3、每完整 1 秒 25 傷害，14 秒入場旗標停用，接現有 HP／受傷／死亡 | 地面危險提示、倒數和實際畫面位置配對；這個固定傷害並不自動等於敵人命中／閃避／格擋 |
| 關門／開通路 | 3 個 barrier 出現項，12 格 overlay、可繞路及出口仍鎖定的界線已查 | 現有旗標 overlay ＋獨立 category0 marker | 若要求封死通道，需真正瓶頸、可達側驗證、門 mesh 和 Client collision 接線 |
| 巡邏／繞牆／回家 | 2 個實際巡邏配置及共用 AI profile 已查；含回程 6 段皆採樣可走、路點在 leash 22 內 | 固定巡邏資料＋現有索敵／戰鬥／有界尋路；Client 重用移動動畫 | 指定 Client 與 Server 位置對照；動態物件、角色寬度等不能由靜態 BND 代證 |
| 換圖／演出後保留正確機關 | 13 個原生點窗口與快照／delta 生命週期已重驗 | 現有 native 集合重建與狀態變更；Server MEF 綁定當前 generation | 所選新發布 adapter 實際接上代數、取消與完整重建；不新增未證實的通用事件 API |

能力／時序來源依序是 [區域增援](../../../design/scenario-content/REGION-WAVE-AUTHORING.md)、[占點](../../../design/scenario-content/REGION-HOLD-SIGNALS.md)、[傷害區](../../../design/scenario-content/AREA-HAZARDS.md)、[屏障](../../../design/scenario-content/FLAG-BARRIERS.md)、[巡邏](../../../design/scenario-content/MONSTER-PATROLS.md)、[條件出口](../../../governance/s00-iterations/S00-20261111-CONDITIONAL-EXIT-CONTRACT.md)。具體可機讀約束及差額一一保存在 [spatial-contracts.json](spatial-contracts.json)。

### 計時不能共用一個模糊的「等幾秒」

占點離圈、技能位移離圈、倒下或主線清場提交會重設未完成計時，主線演出時間不算；傷害區首次看到站入才起算，完整間隔後才扣血，晚到的更新最多扣一次，不追補一串傷害。仍有待觸發增援時尚未全組清場，陷阱不應提早停止。入場延遲 `NodeDelayElapsed` 與清場後延遲 `ClearDelayElapsed` 又有不同起點；尤其前者清場演出中不發事件、結束後更新會計入經過時間，後者在主線 Portal 階段提交後才起算。要做 Client 倒數時，必須對準所選事件的時間語意。[占點](../../../design/scenario-content/REGION-HOLD-SIGNALS.md)、[傷害區](../../../design/scenario-content/AREA-HAZARDS.md)、[入場計時](../../../design/scenario-content/NODE-DELAY-SIGNALS.md)、[清場延遲](../../../design/scenario-content/CLEAR-DELAY-SIGNALS.md)

巡邏的實際資料也已重算：普通候選一圈約 13.656854 單位，繞牆候選一圈約 7.162278 單位。這是本題衍生長度；既有規則的 256 上限是**每一段**，不是整圈。繞牆探針 `(414.5,355.5)` 直回 `(403.5,361.5)` 的 52 個樣點有 18 個受阻，經 `(414.5,361.5)` 的兩段 25／45 點全可走。探針能證明資料確實包含需要繞牆的情況，不預測實機怪一定停在那個探針位置。[巡邏來源](../../../design/scenario-content/MONSTER-PATROLS.md)、[本題巡邏 evidence](spatial-evidence.json)

## 7. 接續優先序與能量測的優化

### P0：先把玩家會卡住或看錯的邊界收斂

1. **作者／發布流程把幾何與規則圖都列為接受條件。** 舊分岔範例以本題具體替換方案修正，或明示僅供結構展示、不選入可玩發布。中心可走、與出生連通、互動區可達三件事分別查；檔名包含「example」不自動代表可忽略。
2. **Q119 採明確玩法敘述。** 保留現有配置時寫局部障礙，出口資格仍以實例條件控制；只有要做真正封門才採 `content-remediation.json` 的完整斷路／開路接受條件。
3. **新 MEF 整合維持點集合生命週期。** 進場／清場演出後一次完整 `0027`，中間只改確實存在的點；內容版本、owner、節點及 generation 綁定同一代。讓本地 setter 優化發生在正確時段，避免下一次快照立即蓋掉。

### P1：讓區域與機關的畫面和規則一致

1. 作者工具同時呈現出生／怪物／出口、Server 半徑、Client category0 的 0.8 半徑，以及目前屏障遮罩。這是工具功能建議，不是假稱已接新 Client 地圖 API。
2. 占點、陷阱、手動機關各自選定可支持的提示資產；用普通流程確認玩家看得見、站得準、按得對。倒數必須保留原本的出區重設、演出暫停／起算政策。
3. 先用現有 Q119 地圖與已驗證座標合成所選單一發布版本，再接原生演出；不要把各候選檔的機關當成已同時存在。

### P2：針對實際重複工作優化

| 建議 | 可量測的量 | 必須保留的語意 |
|---|---|---|
| 按 BND 解碼 hash＋政策版本共用唯讀底圖 | 本 corpus 118 MapID 對 74 個成員；相對「每 MapID 重解一次」可少 44 次重複解碼 | MapID／實例不能合併；屏障另存，不污染共用底圖。這是工作次數比較，不是已測 CPU 百分比 |
| 載入時建立 flag → 出口／屏障／互動依賴索引 | 每次位置／旗標事件評估的規則數、實際變更數、重複 delta 數 | 出區與技能位移要及時重設占點／傷害計時；不偷換成曾進區就算完成 |
| 完整快照只在安裝／重建時發，中間只送必要 delta | `0027` 次數、row 數、`0048` 次數、bytes、演出後點是否齊全 | 缺失點、場景清空與完整重建不能省；已證同一 native setter 並不等於可無限跨場沿用 |
| 以索引期限排程陷阱／占點，Client 負責可支持的提示演出 | 活躍 timer 數、到期回呼數、區域判斷數，及相同正常流程的結束／重設點 | 首次間隔、最多一 tick、不追補、主線占點不計演出時間等規則不變 |
| 預驗巡邏段，目標或影響區域改變才使路徑失效 | BFS 次數、展開格數、重用率、撞牆停一次／恢復的更新數 | 既有最多 4,096 格、每次戰鬥更新至多一隻搜尋、leash／索敵原點、命中視線與 HP／cooldown 延續 |
| 多步演出才比較有限 Client MEF 執行的收益 | 少了多少 Server 表現 timer／逐步指令，增加了多少 selector／completion bytes | 只開一個點時單次 `0048` 可能更便宜；原本已由 Client 做的動畫／選點不能再算一次節省 |

以上是具體實作與量測計畫，未在遊戲或 Server 跑效能試驗，不報虛構百分比。現有「撞牆只停一次、真的移動才發位置、恢復時再發」已在既有 Server 迭代中處理，本題建議重用其語意，不能再列成全新完成的優化。[既有碰撞移動調整](../../../design/runtime-content/MONSTER-COLLISION-MOVEMENT-CANDIDATE.md)、[本題優化契約](spatial-contracts.json)

## 8. 可重現驗證與交付邊界

從 repository 根目錄執行：

```bash
python -B kr-extra-roy/MEF-level-functional-closure-20261118/space-mechanisms/verify_evidence.py --originals /path/to/project_sources
```

需要保有固定 baseline 的 Git 物件及已釘定的 `02-Tartaros.bin`、`07-Table.stp`、`10-BoundMap.stp`；不需啟動遊戲或 Server。verifier 先以 `09799b1` 的 path → Git blob 核對來源 bytes／SHA-256。引用文檔從該固定物件取證，允許現行導覽入口繼續更新；實際解析的 JSON 配置／原生 evidence 與執行的 Python helper 仍強制要求工作樹等於 pin，原件 hash 亦須完全相同，不使用新文件內容代替歷史證據。接著重算 67 檔所有中心／地形連通性、關閉屏障繞路、陷阱／占點／巡邏／手動區採樣、十三個原生窗口，以及未套用的座標修正候選，最後比較完整 evidence。實際執行回條見 [verification-result.json](verification-result.json)。

驗證的 PASS 意義是**稽核可重現且已識別的十個壞點／三個可繞屏障確實重現**，不是把它們消除，也不是指定 Client 遊玩通過。本輪無正式狀態改寫、無既有配置改寫、無完整原件輸出。新增機關外觀、精確 Client 碰撞配對、所選發布 adapter 的落地及正常遊玩對照，都以明確 Server MEF 開發／整合需求交接；不再以官方 MEF 復原作為前置目標。
