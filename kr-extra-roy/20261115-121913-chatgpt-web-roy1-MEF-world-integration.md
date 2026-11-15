# MEF 使用流程續查：普通場景 runner、物件身分、事件橋接與完整收尾封包

> 工作分支 `extra/roy1`；開始時間 **2026-11-15 12:19:13 Asia/Taipei**。研究 parent：`acc5b1e6d856bd31456fe2806044c3a09d5bbb43`；最新 main 參考：`060ed5163a67308f15aa32a91f3a6661e6e5b106`。
>
> 本輪依使用者「請繼續分析 .mef 並上 git」接續未閉合問題，保留原 Client／原資源唯讀。**有限演出可繼續進入內容與 Server 整合開發；完整普通戰鬥的 Client 接手仍缺首次可達內容橋接、合適 runner，以及可可靠對齊的 actor／事件契約。** 不以取得官方 `.mef` 原檔為前提，也不把 Server 必須實作的狀態與發布功能列成逆向阻塞。

## 1. 這一輪新增的四項結論

### 1.1 收尾解除已補到完整封包

前輪只證明共用 field 的 `00EB → 4B6190 → 562250` 能移除等待對話框並清輸入 mask。本輪已補上 **inbound frame parser → application queue → Client frontend → SceneManager → ordinary Mission／Scenario field → helper**，確認本版本這條路由的最小足夠 application 是 `EB 00`。

| 形式 | 靜態合成 bytes | 用途 |
|---|---|---|
| Application | `EB 00` | 現有00EB命令，無額外body欄位需求 |
| Raw `1A68` frame | `02 00 68 1A EB 00` | 6-byte完整封裝候選 |
| `0BBB` frame | `02 00 BB 0B EB 00 5D EB` | 8-byte、B6差分XOR與plaintext加總checksum候選 |

這些是按原件推導、經靜態算術檢查的 **SYN vectors**，沒有發送或執行 Client。需要正常初始化、lane2 與本稿核對的 current field；不是所有登入／無場景狀態都能套用，也不是 `.mef` 載入命令。[wire 完整原件與契約](MEF-world-integration-20261115/wire/report.md)

更重要的是，**`003F` 不能當新 `.mef` 成功執行的確認。** 除了正常 End，`561760` 的「已看過而略過」分支也送同一個8-byte回報，並開等待鎖；該支線跳過本次正常sequence選取／載入。Server 必須區分略過、正常結束、取消及當前run，才能安排00EB。官方是否固定以00EB回003F仍未證實，並不妨礙新 Server 設計自己的相容策略。[003F 三個直接 producer](MEF-world-integration-20261115/wire/contracts.json)

### 1.2 找到 Tutorial runner 在廣場回顧中的正向路徑，也界定普通戰鬥限制

Tutorial runner 並非只在 Tutorial 場景運作。這輪從合法NPC對話控制項、`F4337`、回顧視窗顯示、特殊選取 `60001`，接到固定 Synopsis 內容及 tco 更新。廣場等已註冊頁面確有呼到這個pump的路徑。

但這條路依賴**當前page的更新hook、回顧視窗visible、選取項的active gate與固定入口**；普通 Mission／Scenario 戰鬥頁的hook不同。另一個 Expedition 入口也有自己的啟動旗標與完成動作。因此不能僅因Tutorial API已註冊，就把它當任意普通戰鬥的常駐排程服務。[runner 的三條原生更新路徑](MEF-world-integration-20261115/runner/report.md)

### 1.3 本地 actor 與 Server 同用世界索引，但建立、接管與刪除各有不同條件

`lb.CreateObjectEx` 建立的本地物件，在**唯一ID插入成功時**會進到既有世界索引。若Server**已確知唯一、正確的EntityId**，部分現有位置／控制更新能命中同一物件，沒有另查一個「本地物件禁止更新」來源旗標。

然而，S2C `0007` 一旦查到該ID已存在，就整筆略過；它不能補發來自動接管或校正本地物件的model／來源row欄位。網路建立與刪除還使用EntityId低byte分型，本地自增counter沒有依相同型別編碼分配。**共享索引只提供查找可達性，不提供可靠的身分握手與任意操作相容性。**[identity 的 duplicate／typed-ID／更新／刪除契約](MEF-world-integration-20261115/identity/report.md)

### 1.4 004C／004E 都有現成 handler，但可到達的 Lua 意義不同

`004C` 的完成旗標writer由Tutorial secondary table安裝；普通Mission／Scenario的已核初始化沒有這個slot，會走invalid-message路由。不能對普通場送004C後，就期待 `Tutorial.IsScenarioEnded(key)` 有新的完成狀態。

本輪也補出一條正向事件橋：`004E` common handler可寫一個u16 selection token並排 `F43DA`；在適用的Lobby／Tutorial UI consumer下會呼零參數 `OnYesTriggered()`。這證明某些Server事件可以到Lua，但這個callback沒有攜帶EntityId／group／death原因，普通戰鬥頁也不走同一consumer。[events 的完整producer與page分派](MEF-world-integration-20261115/events/report.md)

## 2. 目前完整使用流程與本輪補上的位置

以下「新 `.mef`」是要自行發布的相容內容。原始MapList的 `TRIGGER` 字串、檔案存在、Lua已載入、coroutine已排程與遊戲功能完成仍是不同狀態。

| 階段 | 已有證據／可用能力 | 開發時必須滿足 |
|---|---|---|
| 發布與落地 | 原launcher的啟動前HTTP／gzip／普通檔案交付鏈已閉合 | Server實作版本、manifest、檔案發布與啟動放行；遊戲TCP沒有因而得到任意檔案傳送介面 |
| 資源選取 | STP優先、ordinary fallback、路徑prefix、checksum與cache各有明確gate | 以實際resource resolver拿到當次內容，不能僅檢查磁碟有檔 |
| 首次caller | 已證0047依SceneList雙鍵選固定 `.seq`；固定Tutorial／Synopsis與已啟動Lua的DoFile亦存在 | 新內容需有可到達的呼叫點；MapList列出 `.mef` 尚未接成正常首次載入 |
| Parser與頂層 | Lua text／5.1 chunk、protected load/call、DoFile numeric status已證 | 有限頂層、當次匯出身分、錯誤檢查；不把chunk return table當DoFile回值 |
| 預掃描 | 獨立VM執行Register body並收集依賴 | 前置與正式效果分開；預掃描不能直接冒用正式等待／副作用 |
| 正式runner | qco／tco的MoCo原件、yield、resume、移除與回值已證 | 明確選合法tick owner；本輪補Tutorial／Expedition／review的實際page與scene條件 |
| 世界操作 | 有本地actor建立及既有世界索引 | 本輪補duplicate不接管、ID低byte型別分派與唯一ID對齊條件 |
| 事件觀察 | 有特定Tutorial旗標及UI全域callback | 本輪補004C ordinary不可套用；004E只形成特定page下的零參數UI旗標 |
| 正常End／取消 | 內容須明確End；return不是自動收尾；不同場景leave／init行為不同 | 不把視窗消失、頁面不tick或MoCo list改變當成完整取消 |
| 等待解除 | 本輪補00EB完整framing與ordinary接收鏈 | Server按run狀態在適用階段解除；00EB不Stop runner，也沒有generation／ACK欄位 |
| 接手驗收 | 靜態證據說明各子能力與界線 | 在獲准整合時停掉要被替代的Server操作，證明Client實際接手；不能Server仍代跑卻算MEF完成 |

發布、parser與儲存的來源沿用 [完整流程前稿](20261115-060700-chatgpt-web-roy1-MEF-complete-flow.md)；scheduler、input雙層owner與VM壽命沿用 [上輪runtime契約](20261115-065342-chatgpt-web-roy1-MEF-runtime-contracts.md)。本輪沒有重掃已收斂的loader／MapList清冊充作新的首次caller。

## 3. runner：可達性、排程停止與取消要各自成立

### 3.1 三種已核入口不能共用一個「普通背景runner」結論

| tco來源 | 本輪閉合的條件 | 對普通戰鬥整合的意義 |
|---|---|---|
| Tutorial場景 | 真實scene/controller初始化、當前場景update、T自身狀態及離場清理 | 是有型別、有生命週期的場景能力，不能僅改一個全域owner就視為普通field已取得同等條件 |
| Expedition／Synopsis | Expedition啟用旗標、固定Synopsis entry、tick completion與後續動作 | 有自己的內容／場景流程；正常完成旗標與離場取消不是同一件事 |
| Lobby／Square劇情回顧 | 合法UI開啟、window可見、特殊內容選取、page更新hook | 是本輪新增的非Tutorial場景陽性；普通Mission／Scenario戰鬥page hook不相同 |

完整的vtable、factory、控制項、函式參數與gate列於 [runner](MEF-world-integration-20261115/runner/report.md)。本稿不以類別名稱排除用途，也不把review控制項的type值 `0x12D` 誤當唯一SceneItem RTTI身分。

### 3.2 頁面離開不等於tco被取消

回顧視窗從active UI map移除時可能進入cache分支，沒有直接銷毀視窗；固定unload路由也不能提供 `t_removeAllCoroutines` 保證。Expedition的native容器析構同樣不能自動等同Lua工作清理。動態child/window callback的未解範圍已在分題保留，沒有擴張成「整個UI不可能間接取消」。

因此，新內容的取消契約應明列：誰不再tick、誰移除tco、誰處理native效果、是否還有等待mask、哪個狀態容許下一次啟動。頁面不可見只回答其中一項。[runner 離場與cache邊界](MEF-world-integration-20261115/runner/report.md)

既有Q則仍受上輪的controller `+58` gate限制。`Q.EnableInput`及00EB清的是另一層mask，無法據此證明active Q可長期保留一般戰鬥操作。runner選擇是功能設計需求，不應把未證的pointer Rebind／停泵欄位當可用API。[既有Q限制](MEF-runtime-contracts-20261115/input-lifecycle/report.md)

## 4. actor身分：目前不能直接把CreateObjectEx當成網路生怪替代品

### 4.1 可以命中的部分

`lb.CreateObjectEx → 4DFF30` 進同一世界索引後，`0001`／`0016`位置及`000B`控制等既有consumer，能在ID正確、唯一、物件型別與欄位契約適合時命中該actor。這提供後續對齊的實際候選，不需要假設本地物件與網路物件完全隔離。[identity 正向更新路徑](MEF-world-integration-20261115/identity/report.md)

### 4.2 為何「再送一次0007接管」不可行

`4DFF30` 對重複ID不做自動合併；網路 `0007` 先查世界樹，命中則直接略過該列。這表示Server若事後以同ID補送建立，不能期待Client把本地actor重新定型、覆寫來源row欄位或補初始化狀態。若未命中，0007還按ID低byte選擇具體actor class；兩條分支不能混稱為「自動同步」。[duplicate 與 create 分支](MEF-world-integration-20261115/identity/report.md)

本地counter `F7DE04` 初值是十進位1001、逐次加1，建立時取低WORD；它不是按網路actor型別編碼分配的ID產生器。`CreateObjectEx` 的Lua wrapper也沒有因此回傳實際EntityId。用Server與Client各自數次數來猜相同ID，無法形成可靠契約；不同呼叫順序、既存碰撞與counter壽命尚無跨端同步契約。

碰撞還有具體的指標分歧：索引若已保留舊actor A，新actor B的插入只發警告，呼叫端卻仍繼續加counter並可能把B attach到controller。此時「控制器持有B」與「Server按同ID查到A」可以同時成立。這是為何驗收必須包含**實際插入成功與指標身分一致**，不能只看數值ID相等。[本地collision控制流](MEF-world-integration-20261115/identity/report.md)

### 4.3 刪除也必須核型別

`001A` 最後可以走到世界物件的cleanup／delete／erase；但在共同刪除之前，還會依ID低byte走不同的欄位處理，包含另一類物件的 `+F4/+124/+130/+134`。因此「樹查到指標」不是把任意本地counter ID安全套入整套網路生命週期的充分條件。[001A 前置型別分支與共同刪除](MEF-world-integration-20261115/identity/report.md)

### 4.4 新核對的getter沒有補上怪物身分／存活查詢

| API | 原件實際可取得 | 不能據此取得 |
|---|---|---|
| `Q.GetLeaderPosN(n)` | n=0／1／2的當前controller leader位置分量，wrapper確有push Lua number | 任意actor的EntityId、HP或FSM死亡狀態 |
| `Tutorial.IsCharacterAvailable(...)` | 固定 `CCharStatus` 第2項 `+5C`；本體不使用輸入key，回數值0／1 | 依傳入怪物ID查任意世界物件是否存活 |
| `lb.CreateObjectEx(...)` | 建立本地actor的副作用 | 本輪仍沒有可靠的實際EntityId Lua回傳 |

這是對已選具體接口的陽性資料流檢查，**不是全程式所有Lua API都不存在其它observer的證明**。AI字串候選則接到XML條件／動作factory，不能單憑名稱稱為Lua世界查詢namespace。[getter與AI候選範圍](MEF-world-integration-20261115/identity/report.md)

## 5. event：已有Server→Lua橋，尚不足以提供ordinary死亡／清組

### 5.1 004C的旗標owner與普通場景分派

Tutorial的 `004C → 4C4F20` 寫入Tutorial owner中的scenario-key map，`IsScenarioEnded`讀同一條已註冊owner鏈。它是可用的特定場景事件，不是可以在任何field直接送的通用完成通知。

本輪把普通Mission／Scenario的secondary slot、common primary default、current field vtable一起核對；在這些正常初始化範圍內，004C落invalid路由，沒有寫入Tutorial完成map。`Tutorial.Rebind` 能改Lua binding receiver，但不替普通field安裝004C writer，也不會自動維持owner型別與tick生命週期。[004C dispatch與Rebind界線](MEF-world-integration-20261115/events/report.md)

### 5.2 004E的正向橋接與資訊量限制

共用handler `4B3570` 取payload的u16 token，寫入 **`[FE18F8]` 所指 `CScenarioDescData` 物件的 `+8`**，並排出UI event `F43DA`。這個token目前保留為opaque selection token，不能直接改名成EntityId、waveId或groupId；另一個既有UI路徑會將它送入C2S0028，並不能反推成死亡事件編號。

適用page處理F43DA時，呼的是 **零參數** `OnYesTriggered()`；qbase的對應body設全域旗標。普通Mission／Scenario page對同一event走不同／default分支。這使004E可作特定UI流程的既有橋接候選，卻沒有構成「任意怪物死亡→帶型別ID與原因→普通 `.mef` 工作」的契約。[004E producer、token owner、Lua body與page表](MEF-world-integration-20261115/events/report.md)

### 5.3 不能把視覺死亡與Lua通知合併

前輪 `000C → actor FSM → CDeadState` 已證的是原生死亡表現；本輪getter／004C／004E沒有把它補成可靠的ordinary Lua死亡observer。若要讓新 `.mef` 決定清波、下一波或局部目標完成，必須再有明確的actor/group關聯、重複事件語義與取消邊界。[前輪死亡鏈](MEF-entry-lifecycle-events-20261114/events.md)、[本輪 identity](MEF-world-integration-20261115/identity/report.md)、[本輪 events](MEF-world-integration-20261115/events/report.md)

## 6. 新 `.mef` 內容現在應包含的契約

本表是內容與Server開發的要求，不是新發現的官方MEF grammar或opcode。本輪未製作可執行遊戲資源，也未修改原SceneList／SEQ。

| 內容部分 | 必須明確表達 | 對應證據 |
|---|---|---|
| 內容身分與載入狀態 | 版本／當次匯出、有限頂層、DoFile status、避免沿用上輪殘留global | 前輪parser／共用VM壽命 |
| 首次入口 | 已可達內容如何選中這份新檔案、何時resource已可見 | SceneList／固定入口與loader分離 |
| 預掃描宣告 | 需要哪些actor／動作／音樂；有限返回 | 獨立prepass VM與立即Register執行 |
| 正式工作 | Lua closure、合法runner、yield／wait、明確正常End | MoCo原件與本輪runner gates |
| 物件參照 | 內容邏輯ID與實際EntityId／actor class如何對齊，重複建立如何處理 | 本輪共享樹、duplicate、typed低byte |
| 事件輸入 | 事件來源、key型別、可讀結果、是否有instance／group／原因 | 004C限定map、004E零參數callback |
| 取消與重入 | 離場、不可見、失敗、重跑時哪些task和native效果必須清理 | Q／T差異、cache與leave結果 |
| 收尾協調 | 何時停止、何時003F僅是略過／結束報告、何時由Server解除等待 | 本輪003F與00EB完整契約 |

若採用「**相容的新 `.seq` 明確呼 `DoFile(new.mef)`**」方案，這是自行設計的首次caller，不必假裝原MapList的TRIGGER已自動串起來；仍需實際完成新內容映射、預掃描／正式兩套契約及版本驗收。它目前是**條件式設計方案**，不能把有DoFile API改寫成原版既有流程已呼到新檔案，也不能因此直接修改原資源。

## 7. Server 開發需求

以下編號僅屬本稿本地需求索引，不改共享GAP／RR／Task台帳。

| 本稿需求 | Server／內容開發要完成的工作 | 完成判準 |
|---|---|---|
| S1 相容內容發布 | 實作既有launcher可取得的版本／manifest／普通檔案交付與啟動放行 | 同版本內容在首次索引前可見；resource resolver實際開到正確版本 |
| S2 首次caller與內容選擇 | 對欲採用入口提供可達的新內容映射；正確使用SceneList signed雙鍵，不把MapID／TRIGGER／review60001互換 | 實際沿指定入口取到新檔案；不能僅有磁碟檔案或資料表字串 |
| S3 runner生命週期 | 為有限演出／回顧／普通戰鬥分別選已支持的owner與取消規則；處理busy與重入 | 玩家操作、task持續更新、正常結束與換場取消各自成立 |
| S4 世界身分與接手 | 若目標是讓MEF替代生怪，先完成可驗證的ID／class／owner對齊與建立結果契約；禁止以補發0007當接管 | 關掉原Server該生怪操作後，Client建立正確物件，後續更新與刪除仍一致 |
| S5 事件與完成判斷 | 針對欲下放的邏輯定義事件key、來源、去重與狀態轉移，選真正可達的現有Client橋接或繼續定向查機制 | 普通場景的目標／清組由指定觀察點驅動，不能用全域UI yes或視覺死亡替代 |
| S6 結束與解鎖 | 實作00EB serializer與狀態排程；003F解析保留雙鍵／略過語義；抑制過期解除 | End／置鎖之後，在正確current field解除；下一run不被舊00EB影響 |
| S7 Server權威狀態 | 保存instance、任務、結果接受、斷線／重跑與必要獎勵規則；區分本地演出報告與業務結果 | 無需猜官方後端政策；不能依單一003F自動認定新檔已執行或戰鬥成功 |
| S8 接手驗收 | 明列要替代的Server操作與停用點，記錄Client行為及失敗回復 | 功能確由新內容執行，Server沒有持續代做被宣稱已替代的操作 |

S4／S5需要的既有Client接口仍有具體待查處，但這不把整個Server狀態機、ID設計、內容發布或驗收方案推回「等官服資料」。Server應先把要求定清楚，後續逆向只追實際欠缺的機制。

## 8. 現在可以開發到哪裡；還要分析什麼

**可以繼續開發的部分**是內容發布、Lua相容格式與離線檢查、有限演出的內容契約、SceneList入口整合設計、runner狀態管理，以及本輪已補齊的00EB serializer／003F分類。這些不需等待官方 `.mef` 原檔。

**尚不能宣稱完成的部分**是原版普通流程已自動載入新 `.mef`，以及普通戰鬥中的「Client常駐編排＋可靠生怪身分＋死亡／清組事件＋換場取消」端到端接手。這輪將三個常見捷徑逐一限界：Tutorial runner不會因API存在就被ordinary page持續tick；補發0007不能接管既存local actor；004C／004E不能直接充當ordinary typed死亡訊號。

下一步應由實際要下放的功能收斂，而不是再無限找所有loader：

1. **有限演出路線**：把新內容橋接、預掃描、正式body與明確End做成可review的內容交付；00EB與003F的相容收尾已可接Server狀態設計。
2. **普通戰鬥接手路線**：定向補「可用且不壓住操作的既有runner」「實際EntityId／class對齊或typed handle」「ordinary actor／group狀態observer」，每個都要有producer到Lua結果的正向鏈。
3. **取消與重跑驗收**：採所選runner實際支持的leave／stop機制；不要以頁面隱藏、場景指標換掉或收到003F作替代證據。

其中內容製作、協定serializer與Server狀態規則是**開發需求**；現有Client是否另有符合目標的runner／typed observer則是**有界待分析項**；實際Client執行結果屬**後續獲准整合驗收**。本輪只有靜態原件與合成算術核驗，未執行Client／Lua，也未宣告T01 FULL-PASS或更改共享驗收狀態。

## 9. 來源與重現

四組完整報告、VA／raw mapping、選定原件bytes、source pins、唯讀verifiers與結果集中於 [證據包README](MEF-world-integration-20261115/README.md)。

```sh
python -B kr-extra-roy/MEF-world-integration-20261115/verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi
```

主驗證器檢查原件身分、各分題檔案hash與固定Git來源，執行各分題的靜態重現，再檢查文件連結。結果的PASS僅限已列證據與斷言，不代表所有原版caller均已窮盡，也不代表遊玩已通。
