# Server 提供 MEF：內容交付、首次入口與執行 profile

2026-11-18（Asia/Taipei）；`extra/roy1`；固定研究基準 `60c1c1a5dc7a73902d9dbb50361d5148e8b30058`。本分題完成新的產品目標下之能力分類、可編寫內容契約、發布輸入及有界證據重驗。沒有執行 Client／Lua／Server、改原件或部署資源；Git 由主稿統一處理。先前報告提到「官方 MEF 復原」「Field.stp／官方 grammar 必須完成」的整體目標，不沿用為本任務的交付門檻。

## 1. 結論：現在就能走的自製 MEF 路線

**Server 可以把多步內容編成現有 Client 能讀的 Lua／SEQ，先發布同版本資源，再以合法入口啟動；啟動後，Client 可自行等待、演出、讀取已證本地條件及操作既有點位。** 內容不必每一步都由 Server 另發命令。有限 Q 與 Tutorial 互動長流程都有正向的入口／執行證據；普通背景 B 是另一個有明確適用條件的擴充 profile，不是全部 MEF 功能的共同門檻。[S01、S03、S05、S07、S10、S13]

本輪採用使用者的架構前提：**MEF 由 Server 提供，MEF 開發屬於 Server 開發，先讓 MEF 承擔可處理的工作。** 已證傳輸實作與這個產品決定仍應分開紀錄：原件已有啟動器的條件式內容交付鏈、資源 resolver、固定腳本 loader、遊戲內 selector；本讀集沒有證明現有 game TCP 可接任意 raw Lua／MEF bytes。因此採用「內容發布一次、Client 本地推進」完全有可實作路線，卻不能把 `0047` 增加成自創 script blob opcode。[S01、N01–N09]

這次的新成果是**以能力與部署需求重新接合已證元件**。沒有把舊 121 名稱盤點、loader census、20+4 execution sinks、完整 Master 掛載或 UI 原件鏈再算成新發現。選定的 22 個 native 視窗及 8 個 Lua 片段均標為復用重驗；它們讓新的自製內容規格能回到實際 bytes，而不是只更換報告用詞。[native-proof.json](native-proof.json)、[lua-proof.json](lua-proof.json)

## 2. 四個 profile，各自需要什麼

| Profile | 玩家看到的玩法 | 已有本地能力 | Server MEF 最小整合工作 | 是否等待背景 B |
|---|---|---|---|---|
| **有限 Q** | 一段演出、等幾個步驟、開既有出口／服務點、再恢復操作 | `0047` 選已配置內容；雙 VM；qco、`wait`、已證 Q／Tutorial bridge、明確 End | 發布內容與索引、確認安全啟動時點、一次觸發、排他與回報／解除等待、保存業務進度 | **否**；接受 Q 本身的演出控制影響 |
| **Tutorial 互動長流程** | 顯示提示、玩家走到位置或按互動、內容自己接下一段 | 固定 TutorialMain loader／entry、tco pump、category4 point→control progress→Lua→續行 | 提供正確 Tutorial 場景／資料／UI、內容版本、必要場景回覆與最後進度整合 | **否**；使用合法 Tutorial controller/context |
| **原生有限效果延續** | 已開始的淡入淡出、圖片或既有物件更新自行推進 | 各效果自己的 native update／生命週期 | 只提供啟動條件、素材、owner 與適用完成政策 | **否**；但這不代表 End 後仍有 qco timer |
| **普通背景 B** | 保持普通 Mission／Scenario 原控制，任意新 Lua 邏輯持續監控 | 尚未完成本次內容首次執行→Q inactive pump→owner／取消／重入的完整 adapter | 只在玩法真的需要此特性時繼續閉合上述 Client 接點 | 此列本身是額外需求，不阻塞前三列 |

有限 Q 的 `wait` 可串多個已證操作，不限「一次 setter」。Tutorial 又有真正的玩家操作→Lua 觀察→本地續行，並非只能播放不能互動。能減少的是逐步派送、逐次 timer、部分提示監控／演出編排；本輪沒有量測 CPU、流量或每場封包差額，不報節省百分比。[S05、S07、S10、S13、S29]

## 3. 首次內容入口：已有 selector 可以承載自製內容

### 3.1 有限 Q 的正向路徑已存在

`0047` consumer `503040` 將 application 的兩個 WORD 解成 signed16，呼 `561760`。Start 查記憶體中的 SceneList 雙鍵，取得 `funcName`，以固定字面前綴與尾碼形成 **`Event/Sequences/<funcName>.seq`**，先送預掃描，再用正式 wrapper 讀同一路徑。這個 path producer 不使用 MapList.TRIGGER，不必等 Field.stp 或另一套官方格式。[N01–N03、N14、N21；S05]

本輪重新讀原 Event.stp 的 `Event/SceneList.xml` 與以下 5 個成員，確認這些已配置 selector 的路徑：

| quest／scene | `funcName` | 已消費的字面路徑 |
|---|---|---|
| 119／1 | `Phindous_YuriandRazed_Blank` | `Event/Sequences/Phindous_YuriandRazed_Blank.seq` |
| 119／2 | `Phindous_YuriandRazed_Stage` | `Event/Sequences/Phindous_YuriandRazed_Stage.seq` |
| 119／3 | `Phindous_YuriandRazed_Boss` | `Event/Sequences/Phindous_YuriandRazed_Boss.seq` |
| 119／4 | `Phindous_YuriandRazed_BossClear` | `Event/Sequences/Phindous_YuriandRazed_BossClear.seq` |
| 119／5 | `Phindous_YuriandRazed_After` | `Event/Sequences/Phindous_YuriandRazed_After.seq` |

五列 `endBehavior=0`，成員均走文字 parser 分支。這是可選內容位置的證據，**不是說上述原檔就是新 MEF，或本輪已替換內容**。若發行版決定在一個既有配置路徑供應自製內容，原 consumer 讀到的就是發行版實際選中的 bytes；須一起審查該 selector 的既有呼叫者、劇情影響、非零 quest 確認條件與回報政策。對新功能通常更清楚的方式是新增配套 SceneList row 與新內容路徑，保留原有映射。[R01、S05、S21]

### 3.2 新增 row 的具體工作，不是重新找 parser

原索引有 1,687 列。舊 A1 提案的 `(0,32760)`、`compat_point_once_a_v1` 與對應 path，在這份原索引／Event archive 中的衝突仍為 0；它並非官方保留鍵或已部署品。新 profile 必須根據**實際合併索引**分配唯一雙鍵、funcName／path 和 release，不以這個歷史候選自動替所有新版本占位。[R01、S16]

`0047` 不刷新 SceneList，亦不接收 point、run-id 或變數表。要在新內容內操作哪個點、使用哪些資源，可以在內容建置時綁定 literal；若玩法要求執行時參數化，必須使用另有實證的狀態接口，不能把資料附在 `0047` 尾端就當 Client 會讀。[N01、N14；S16]

只要正式資源已被 resolver 取得，native parser 依首 byte 選 Lua binary 或 text。自製發布品可直接採相容 Lua 5.1 文字，無須重新編譯舊 bytecode、更不需要還原官方 MEF grammar。產品 MEF schema 若採 JSON 等形式，應由 Server 內容工具先轉成這個已證 Client adapter；JSON 不會因改副檔名就被這個 loader 解析。[N07；S26]

## 4. 交付與啟動：Server 提供一次內容，如何具體成立

| 階段 | 應由 Server MEF 開發完成的交付 | 已證界線 |
|---|---|---|
| 建置 | 同一 release 的內容、有效完整 SceneList、每項必要素材／provider 路徑與 hash | 新增 row 是建置決策；本輪沒有修改原 Event／Master |
| 發布 | Client 啟動前，使已選發布方式交付正確 bytes | 原 launcher 有 manifest→HTTP `.gz`→gzip→普通 writer 正向鏈；端點可達、流程啟用及正確包裝仍是整合條件 |
| 選檔 | 實際安裝的 resolver 選到該 release | Master 原件明確宣告 `Event→Event.stp`；父 provider 先查，再按 miss／policy 落後續來源，散檔同名不自動覆蓋 STP |
| 初始化 | Client 在預定版本建立掛載／讀取 SceneList | index／map 是提前建立的狀態；只在磁碟出現新檔不代表記憶體索引更新 |
| 啟動 | 在 Q idle、正確場景／角色與本次內容前提成立時送一次合法 selector | busy 不內建排隊；Start 還可能先改 review／暫態旗標，重送不是無副作用 |
| 本地推進 | 一個 coroutine 排列等待、演出、已證事件觀察與 setter | Q／Tutorial 各自 pump gate；loading 能收包，不保證同時繼續 Q tick |
| 收尾／保存 | 明確 End、適用的等待解除、保存 desired 進度並在重進時重建 | End／003F／00EB 各有不同語義，不能合成新成功 ACK |

發布工具可以建置獨立工作副本的 carrier／索引；**原始版本是不可變證據**。目前缺的是實際新 release、可用的發布服務／打包與選取驗證，並非缺官方內容才能編寫新 MEF。若採 loose resource，需證明本次 provider miss、fallback policy、path／cwd；若採 Event carrier 發布，需相容包裝、完整索引及實際選中 member hash。兩種都不能用「檔案已下載」取代「Client 開到的版本」。[N08、N09；S01、S18、S27]

原啟動器只對 BIN 的特定 launch gate 做自己的 MD5；更新完成狀態不等於每個 MEF／SEQ 已逐檔校驗。Server 發布層應自行維護 release manifest／hash 證據。遊戲 socket 換成自製 Server 也不會自動改變原 launcher 的更新端點；端點／部署工作是 Server 內容供應的具體需求。[S01]

最小本地工作量例子與完整輸入範本已另存：

- [authoring-contract.md](authoring-contract.md)：雙 VM guard、有限 `wait→setter→End`、prepass、精確 arity、可選 module 與輸入／回報限制。
- [delivery-manifest.template.json](delivery-manifest.template.json)：未綁定 release／selector／資源／Client epoch／點快照與六層完成狀態；這是建置器及 Server 的資料，不是新 Client grammar。

## 5. Tutorial 可以先做互動長流程

真正入口是既有 `006E` 成功分支建立並安裝 `CTutorial`；其初始化使用 controller kind4、準備 page15，然後 `4A8A60` 讀 **`Event/TutorialMain.lua`**、呼 **`Tutorial_EntryPoint`**。正式 bootstrap 先有 **`Event/TutorialBase.lua`**。另一個 `Synopsis_EntryPoint` 也消費同一 Main，所以自製 Main 發行品必須保留／明確管理這些既有 export 的使用情境，而不是僅改掉一個函式名。[N10、N20；S13]

`CTutorial` field 的 `+18=4C4DF0` 走 `4A8B90→t_doCoTask`；這個 caller 沒有 Q active gate。因而在合法 Tutorial context，tco 可以在子 Q 停止後繼續工作。原內容的實際鏈已是：插入 category4 提示點→角色進入範圍／映射動作新按下→native 寫 progress→`GetControlStatus(k)`→關點→下一場 Q。[N11、N12；S10、S13]

這能讓玩家「走到指定地方才接下一段」由 Client 本地處理。新內容仍要綁定合法 table row、控制器索引、UI／效果素材；原 32 格 control array 中有既有用途，不能任意占用。`GetControlStatus` 是 number；不可把 Lua 的 0 當 false。mode0 需要映射動作13的新按下，非零 mode 的既有例子採範圍觸發；所選原等待只證到達，不驗證玩家究竟用鍵盤或滑鼠到達。[S10]

重用點也有完整具體條件：插入會追加，成功不清舊 progress；setter 改第一個匹配點，不是 upsert。新的互動步驟應由內容管理點／progress／區域邊緣，不能重插相同 key 就假定已回到未完成狀態。離開 CTutorial 的 `+14=4C4D60` 明確移除 tco／清 native table，但移除 coroutine 不會執行它的 finally。[N13；S07、S10]

`006E` 會換成 Tutorial field/controller。這是可用且能做互動的 profile，不能把它敘述成「普通戰鬥不換 context 地多一個背景執行緒」。Square／Lobby 的回顧 Synopsis 也有另外的限定 native pump，適合回顧用途；普通 page5／7 不因此獲得相同持續入口。[S13]

## 6. 重入、完成與背景 B 的剩餘界線

兩個 VM 平常重用。下一次 Start 不提供全新 global environment，不自動清 Q tree／全部相機／圖片／音樂／point，正常 End 也不是所有 owner 的共用 destructor。自製內容必須用自己的狀態／版本、明確取得與釋放，並在仍有合法執行時機時完成所需 cleanup，最後才 End。[S15、S28]

已知實用例子包括：新的 `Q.FlyingObject` 會先取消自己追蹤的上一張；取消標記與實體回收分開。下一次 Start 先做 level3 替換，若新 callback 又 `DeleteAllObject`，那會作用於全 Q 樹／該層，不是只清上一個 run。這些是各效果的使用契約，應只對用到該效果的 profile 納入依賴，無需為純 point 範本要求全部角色／圖片／相機素材。[S15]

目前普通背景 B 的最新 UI 證據已到 resource212 的確切 `UI/Component/TalkBox_Scenario_Panel.FTC`、native XML reader、root owner、child factory、卸下與 cache 重入。**這條正向 reader 是 UI layout，不是把新的 Lua bytes 交給 executor。** cache 重入也可能直接取舊視窗，不重讀 FTC。因此不能把 UI 已建立或 `Rebind` 名稱當 B 的首次腳本載入。需要 B 的玩法，仍缺本次內容 producer→同 VM first execute、Q inactive pump、input owner、取消／重入四段；缺 FTC 只限制該 UI 路線，不限制有限 Q 作者契約。[S20]

官方 MEF reader／grammar、Field carrier 等可另作歷史格式研究，**本任務不以它們作 P0 開發前置**。若某項自製玩法不需要 B，就直接選已證 profile；若需要普通戰鬥常駐觀察，再以具體新 producer／事件接點續查 B，而不是重跑所有名稱與 API 清單。

## 7. 可立即排入 Server MEF 的工作與缺項

| 開發順序 | 分析成果／可開始的工作 | 仍缺的具體輸入或整合 |
|---|---|---|
| P0：有限單檔 MEF | 作者骨架、兩階段行為、point ABI、時間／End／wire 界線已定；可實作內容建置器 | 選定真實目標點／場景、實際 release 與唯一 selector、必要快照，不能使用 null 範本當部署品 |
| P0：內容交付與啟用 | 發布時點、Master Event 路由、resolver 規則與既有 selector 可確定 | 相容內容打包／發布服務、實際落地與選中來源、啟動前版本控制；未證 game TCP blob 不能由臆造欄位補上 |
| P0：MEF run coordinator | 排他、Client epoch／已用鍵、內容版本、003F／00EB、結果未證狀態可定型 | 接入真正 Server session／outbox／進度保存；這些不是新 wire 欄位 |
| P1：多步演出與 Tutorial | 有限 Q 排程、合法 Tutorial 互動→續行已閉合；可以自製目標／故事內容 | 各選定素材／合法 row、輸入與場景流程、完成資料對帳及正常遊玩整合 |
| P1：內容重用 | 持久 VM、shared owner、level3／圖片替換與明確 End 已有契約 | 每份內容真正 owner 清單、下一段合法 selector、可觀察 cleanup 條件；不存在的全清 ACK 不捏造 |
| 按需求的擴充：普通背景 B | 精確列出仍缺的 adapter，不拖住其他 profile | 只針對確實要求普通操控同時常駐 Lua 的玩法續查 first producer／pump／input／cancel |

本表的「分析已定」不表示 Server 已實作或能直接遊玩。也不表示每項功能都需要另寫一個 Server handler：內容建置器／run coordinator 可以共用，具體步驟留在 MEF。真正存檔、共享狀態與最終結果如何接合，交由同包整體 capability matrix 按已證事件／介面配置；本分題不把「屬於 Server 開發」當成排除 MEF 的理由。

## 8. 證據重驗與來源

```bash
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/delivery-profiles/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --sources /path/to/project_sources
```

實際結果見 [verification-result.json](verification-result.json)。驗證器核固定 Git blob、原件完整 hash、PE 映射、必要 native 視窗與完整指令邊界；只讀 STPD／XML，核 5 組 selector→literal path、Tutorial 相關成員、Master Event property，並比對 qbase／Coroutine 的選定指令字。沒有載入或執行原 Lua。5 組路徑是資料可達性，並非 5 個新開發功能；PASS 不是 T01 FULL-PASS、部署成功或遊玩驗收。

| 引用 | 內容／精確來源 |
|---|---|
| S01–S02 | [交付窗口主稿](../../20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md)及其 native windows：updater／loading／selector／resolver |
| S03–S04、S26 | [executor](../../MEF-parser-executor-storage-20261114/executor.md)、[parser](../../MEF-parser-executor-storage-20261114/parser.md)與同包 native windows |
| S05–S06、S23 | [首次入口與 lexical 階段](../../MEF-end-to-end-20261116/entry/report.md)、native／Lua 證據 |
| S07–S09、S24、S30 | [scheduler](../../MEF-runtime-contracts-20261115/scheduler/report.md)、時間 native、bridge／Coroutine 選定字；原 Coroutine carrier 只取其 hash／資料驗證，不再發布 |
| S10–S12 | [Tutorial 操作→Lua 續行](../../20261116-191747-chatgpt-web-roy1-MEF-tutorial-observation.md)與 native／resource 證據 |
| S13–S14 | [三個 T runner 的合法 context](../../MEF-world-integration-20261115/runner/report.md)與 native windows |
| S15 | [重入與資源交接](../../MEF-comprehensive-contracts-20261117/reuse/report.md) |
| S16–S17 | [A1 最小規格](../../MEF-A-minimal-spec-20261116/SPEC.md)與候選／003F 證據；本包新有限範本不是原 A1 的未改版部署 |
| S18–S19 | [Master 掛載](../../MEF-P0-P1-master-continuation-20261117/master-resource-closure/report.md)、summary |
| S20 | [最新普通 UI 首載／卸下／重入](../../MEF-P0-P1-P2-continuation-20261118/p1-entry/report.md)；B 未閉合限制 |
| S21 | [119 路程資料](../../MEF-P0-P1-master-continuation-20261117/journey-families/data-evidence.json)；本輪只復用已配置 selector，不新增世界流程假設 |
| S22 | [只讀 STPD reader](../../MEF-world-identity-scene-interaction-20261117/stp_reader.py)，先固定 hash 才載入分析 helper |
| S25、S27–S29 | [supervisor](../../MEF-control-flow-20261116/supervisor/report.md)、[資源 gate](../../MEF-complete-flow-20261115/resource-gates/report.md)、[VM lifetime](../../MEF-runtime-contracts-20261115/vm-lifetime/report.md)、[原生效果生命週期](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| N01–N22、A01–A11、L01–L08、R01 | 本目錄新 profile 接合所用的 [native-proof.json](native-proof.json)、[native-proof.asm](native-proof.asm)、[lua-proof.json](lua-proof.json)、[resource-evidence.json](resource-evidence.json)；全部明標復用，完整 commit／path／blob／SHA 見 manifest |
