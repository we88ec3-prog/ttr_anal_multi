# MEF 全面能力搜尋：註冊面盤點與 Q 結束後的 native 持續效果

研究基線：2026-11-16，KR `Tartaros.bin`。工作分支 `extra/roy1`；公開父提交 `0d76b827dfda0deb263e2692281ec304747652f8`。核對 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已為父提交祖先，ahead 14／behind 0；本輪不新增分支、不修改正式 Task／RR／驗收狀態。本文為完整研究原稿，不是根據聊天補寫的摘要。

## 1. 研究終點、成果與未完成界線

使用者在 A1 最小規格完成後要求全面搜尋 MEF 功能。A1 的「完成」是可實作的相容內容規格，不是已部署／遊玩通過，也不是官方 MEF 已還原。本輪將廣泛目標落在兩個可核對的工作面：

1. 不只列已知名稱，而是對原 BIN 的 raw-backed `.text` 重建**既有 C closure 建構機制的全部直接呼叫與固定 registrar 模板**，區分正式功能、預掃描、管理入口、語言函式庫及未涵蓋的動態路徑。
2. 對完整功能鏈補缺：**有限 Q 發起操作 → End 停止 Lua → 同一普通場景繼續 native 更新／動畫／繪製 → 效果的結束與清理責任**。這回答哪些功能不必一直佔用 Lua runner，而不把它冒稱為全程不中斷操控的 B。

**實質新結果：正常 Q 的 active gate 只包住 controller busy／Lua pump，不包住 Q actor 的後續 native tick；動畫與繪製另有 Client hook。** 只要物件仍由 Q 索引持有、資源與普通場景更新條件成立，End 後演出角色仍可繼續移動、動畫及繪製。Fade 更新位於 active gate 之前；Sepia 更新位於 actor loop 之後。這些是獨立 native 狀態機，不是背景 Lua。

**全面功能目標仍為階段性未完成。** 本輪未證明官方 `MapList.TRIGGER → .mef` 首次 loader／grammar、不中斷輸入的首次腳本入口、一般戰鬥死亡／清組到 Lua 的可靠介面，亦未部署新內容。已查完的盤點機制與上述持續效果鏈可獨立交付；其餘保留精確缺邊，不能因數量多或 verifier PASS 就標成「所有 MEF 功能完成」。

## 2. 第一手來源與驗證邊界

KR BIN：12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32/i386，ImageBase `0x400000`；所有 VA/raw 依實際節區表換算，不把 `.text` 位移公式套到 `.rdata/.data`。

Event.stp：11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。只讀選定 `Event/qbase.lua` 成員為資料，不執行 Lua；其解碼 SHA 為 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`。完整原件、完整解包成員與可部署腳本不在交付中。

證據檔：
- `surface-census.json`：122 個固定 registrar、223 個 closure sink 呼叫位置的完整分類、11 個 table registration caller、正式命名空間計數。
- `capability-matrix.tsv`：逐項保留 121 個正式名稱、原生 target、registrar/caller/closure、能力域與適用限制；語意來源是既有 R11，不把本次重驗名稱當成重新證完全部 body。
- `native-proof.json`：46 個完整或明列區間的 VA／exclusive end／raw／SHA／指令數，16 組完整指令節錄、5 組資料及15條 direct calls。switch 資料與程式碼分開；範圍數不代表全程式覆蓋。
- `qbase-evidence.json`：6 個選定 prototype 的48個指令字與相關常數，區分排程清除、角色清除、Register、會 yield 的 wrapper。
- `audit.py`：只讀重算上述盤點與原件證據；可將選定完整反組譯輸出到獨立研究目錄。沒有遊戲／Lua／Server 執行。

既有證據來源與閱讀範圍見 `SOURCES.md`。本輪重跑 A1 原件／格式檢查，保存實際 stdout `previous-a1-rerun.json`。來源相符、格式測試與有界靜態核對，不等於 T01 FULL-PASS、S00 STABLE 或遊玩驗收。

## 3. 全面搜尋的實際範圍與分類

### 3.1 122 個同型 registrar，不是新增122種功能

掃描原 `.text` 中 MSVC 產生的固定 registrar 形式，以完整序列核對名稱字串、native slot、native target、closure 與實際 E8 caller；每筆153 bytes皆重新反組譯，要求起訖完整且無 bad instruction。不是只搜尋英文字串。

| Wrapper slot | 命名空間／階段 | 同型 registrar 數 | 解讀 |
|---|---|---:|---|
| FE1774 | 正式 lb | 14 | 既有本地世界／輔助 API |
| FE1800 | 正式 Tutorial | 31 | 各 target 的實際 context 不同，不能一律當教學控制器專用 |
| FE1E24 | 正式 CameraWorks | 5 | 共享相機工作 |
| FE1F20 | 預掃描 Q | 1 | `DeleteAllObject → 5F5D10` 空操作；不可當正式新增能力 |
| FE1F2C | 正式 Fade | 2 | 共享淡幕 |
| FE2764 | 正式 Prolog | 1 | 原序章關閉能力 |
| FE2774 | 正式 Q | 63 | 既有有限演出操作 |
| FE317C | 正式 ScenarioTalkTable | 5 | UI 物件生命週期相關對白 binding |

正式共121個名稱，與既有R11範圍一致。4個正常 target stub（Q.DeleteObject、Tutorial.InsertObject、Q.BalloonTalk、lb.PrintCurrSceneID）及非可靠計數的 lb.GetObjectCount 仍明列，未刪去來灌大「可用功能數」。alias、shared owner、同 target 不等於獨立玩法。

### 3.2 再由共同 sink 補查其他註冊樣式

`6F55B0` 是所查 C closure 建構 sink。對 raw-backed `.text` 的 E8/E9 rel32 全掃得到223個 E8、沒有 E9候選；在 `.text/.rdata/.data` 中沒有該 target 的直接 DWORD 指標。完整位置列表在 census，分類如下：

| 分類 | 呼叫點 | 是否新增正式玩法 API |
|---|---:|---|
| 上述同型 registrar | 122 | 121正式＋1預掃描重名 |
| namespace Rebind | 8 | receiver重綁管理；不構成合法新排程器 |
| 預掃描預設 globals | 72 | 固定空 callback，不能按名稱當真實效果 |
| 每次預掃描覆寫 collector | 6 | 宣告／收集依賴，不是正式玩法 |
| 額外正式 globals | 2 | `PrintStackStatus`、大寫 `DoFile`，不是新傳檔協定 |
| 語言／函式庫及動態擴充支援 | 13 | 需看函式指標來源，不能當13個遊戲事件 API |

13個支援呼叫點：`6F66C2, 6F7685, 704624, 707464, 707514, 70751F, 70774C, 70824A, 70833D, 7091DF, 70A102, 70B3D2, 70B4DC`。其中 `6F66C2` 從 `{name,function}` table讀 target；`6F7685` 從固定 opener table 讀 target；其餘落在迭代器、coroutine包裝、I/O及package支援。**動態 package 載入的函式指標不在此被宣稱為窮盡**，不以它執行任意模組或改寫 Client。

`6F6590` table registrar 的11個直接 caller也逐筆列出；其固定表是 debug(14)、math(28)、string(15)、_G(24)、coroutine(6)、FILE metatable(9)、io(11)、os(11)、package(2)、package追加globals(2)、table(9)。這些數量是原 table entries，不是額外遊戲能力。固定 opener 在 `C0C0D8`；`6F7660` 實際推 closure 並執行這些 opener。正式 VM ctor `6F4380` 另登記 `PrintStackStatus→6F4420`、`DoFile→6F48A0`，所以不能漏掉非共同 registrar 的 global loader。

### 3.3 搜尋不能支持的全稱命題

這是「已知 sink＋固定 registrar 的有界完整直接呼叫集合」，不是所有可能 API 的形式化窮盡。尚不涵蓋計算後的間接 target、另行內聯的 closure配置、外部 DLL、任意 runtime table改寫或未知資料載入後新增的 binding。沒有在這組機制發現額外正常遊戲 namespace，不等於整個程式絕不可能提供其他入口。

本輪沒有重掃全部 STP 名稱、沒有重新做已排除的 MapList alias／OnYes 路線，也沒有把 standard loadlib 的存在當成已授權 Client 改造途徑。新的搜尋範圍相對既有七組索引，是共同 sink的跨樣式直接呼叫閉合。

## 4. 新功能鏈：End 後仍繼續的 Q actor

### 4.1 三條更新／繪製入口必須一起成立

正常 CClient vtable `C05AA4` 的 +30／+34／+38 分別是 `490FE0`、`492040`、`492900`。本輪完整核對三段程式的原件起訖，保留各自 loading／renderer／current context gate，不承諾任意狀態每個畫面 frame都必到。

| 路徑 | 同一 Q owner／container | 到 actor 的 target |
|---|---|---|
| `491ED7 → 561520` native tick | 固定 M=FB73C0，M+1C Q tree | node+10 actor → v+20 |
| `4924E3 EAX=FB73C0; 4924EB → 561680` animation | 同一 M+1C | actor v+24(delta) |
| `492B52 EAX=FB73C0; 492B57 → 5616F0` render | 同一 M+1C | actor v+28() |

Q.CreateObject正常建立 CEventActor：`562F48` 配置0x438、`562F68→4D0B80`、`4D0BB8` 寫 vptr `C0C824`。該表 +20=4D0F80、+24=4D0FA0、+28=4D0FC0；不是從類名推測世界 CMonster。

### 4.2 active gate 真正只跳過哪一段

`561520` 的關鍵原件順序如下：

```text
56157D  ESI = FE2744
561582  call 55E790             ; Fade native tick
561587  cmp [M+28],0
56158B  je 5615E0               ; inactive 不是 return
 ...                            ; active 分支
5615C4  [currentController+58] = 1
5615C7  cmp [M+2C],0
5615CB  jne 5615E0
5615D8  call 6F4DD0             ; 固定 f_doCoTask
5615E0  讀 M+1C 的 Q actor tree
5615F8  call actor.v+20         ; inactive 仍可達
 ...
56165F  call 560090(FE36D4)     ; Sepia native state machine
```

因此「Q inactive」只阻止這條 busy／Lua pump 分支，沒有跳過後半的 actor更新；另外兩個 animation／render迴圈亦沒有 Q active 條件。這是本輪新增的完整**入口→保留container→實際virtual target→consumer**連接，不是只找到一個每幀函式便宣稱新Lua runner。

### 4.3 指定走位會怎樣繼續

direct `Q.WalkObject(slot,x,y,gate,action,speed)` 以精確六參數契約操作Q slot；`563330` 查Q tree，`56337E→4D0CE0` 寫 actor+424/+428目標、設定+E2的8000移動bit。需有效模型／動作及預掃描依賴，不能用world EntityId代替slot。

`4D0F80` 先呼common actor tick再到 `4D0DD0`。後者在+D4條件與pending bit成立時，以v+60速度、方向表及目前／目標位置算步進；一般分支進v+54，結束分支經v+44設定目標、v+68切action1，`4D0EF9` 清8000 bit。這不是權威尋路／碰撞／怪物AI，也沒有回Server死亡或完成事件。

動畫 `4D0FA0→4C87D0` 在actor+370及有效+15C CDoll條件下呼 `7A5C50`；Qactor繪製 `4D0FC0` 先看自身+42C，再到 `4C88F0`，後者看+370與CDoll，再呼render object v+8。後段CDoll模型／動作／附件消費直接復用R11；本輪沒有把這幾個render gate當「所有模型必可見」。

**可承諾的有界效果：**已合法建立且保留的Q演出actor，已被設定的走位／動畫在End後仍有native update與draw來源。到點不會自動Delete；show=0也不等於停止更新。`IsAllObjectsStopped`仍是全Q tree的query，沒有證明End後能自動把結果回給已移除的Lua工作。

### 4.4 End 不等於清掉角色

在原始qco methods／globals未替換、沒有新增hook的正常內容環境下，End `561DB0` 於 `561F69` 清M+28，之後走原有回報、wait、qco清除與UI政策。`56202D` 呼 `f_removeAllCoroutines`；原qbase P3只呼`qco:removeAllCoroutines()`，與P36 `ClearObjects→Q.DeleteAllObject()`是不同函式。排程移除語意沿用既有MoCo契約，不等於native actor tree被clear。

本輪核對End正常路徑不直接進 `563A70`。R10已證active Stop才有批次DeleteAllObject，而**先End再Stop會跳過主要cleanup**。因此內容不得靠End自動回收，也不能用stub Q.DeleteObject刪單隻。跨場景、下段Q、外部Stop或任何owner清除會打破「物件仍保留」前提，本文不保證跨圖持續。

## 5. Fade 與 Sepia：可持續，但收尾各不同

### 5.1 Fade 的動畫和繪製都不依賴 Q active

共享owner FE2744；`55E740`設定direction、count、active、counter及起始alpha。`55E790`在`561582`已於Q active檢查前被呼叫。draw另由`492EEE→5646E0→56477F→55E7F0`，只要求有效texture及alpha>1，未以Fade.active或Q.active作該處的draw gate。

| 操作／狀態 | 原件結果 | 內容限制 |
|---|---|---|
| 正向淡出至不透明（direction0） | counter/count×255，上限255；到尾不清active | EndQ不會把遮罩移除；需安排淡入或明確清alpha |
| 反向淡入至透明（direction非0） | alpha=255−進度；到0同時清Fade.active | 需count>0及native tick繼續；count不是毫秒 |
| Fade.End(0) | 清active但保留alpha | 即使active0仍可能被draw，不等於恢復畫面 |
| Fade.End(非0) | 清active且alpha0 | 清共享遮罩，不是釋放所有音畫資源 |

原`FadeOut/FadeIn` global helper會yield一次；若採「啟動native效果後同一callback End」的設計，必須選direct binding與精確ABI，不能無意使用有等待的wrapper。新內容仍需數字/布林轉換檢查；count0、NaN、溢位等不作合法功能。

### 5.2 Sepia 是另一個 native state machine

`56165F→560090` 的輸入為FE36D4。其switch table `560158` 與程式分開保存；這是色調/renderer流程，不是字幕queue。既有StartSepia／EndSepia語意復用R10：EndSepia發phase4，後續合格native更新4→5→6→0。新證據是這個消費點也不在Q active gate內。

這不保證任意renderer狀態都成功，亦不替代相機快照、字母黑邊、音樂stream等各自owner的清理。音樂、CameraWorks、圖片及對話已有R10/R11的consumer證據，本輪不將其全部冒稱新查完的post-End特性。

## 6. 實作上應分成三種能力，而非一律要求背景 Lua

| 分類 | 已有用途 | 完成條件 |
|---|---|---|
| 同步本地狀態修改 | 既有point enable、部分外觀／顯示切換 | 合法entry、正確typed key、資料可見、同owner後置條件；A1屬此類 |
| 啟動後由native自行推進 | 本輪閉合的Q actor移動／動畫、Fade、Sepia；其他效果按既有owner逐項採用 | 原生tick持續、資源仍保留、明確終點／持有與清理；無需Lua逐步下指令 |
| 必須由Lua持續等待／分支，或Server提供權威事件 | 多步依條件劇情、普通波次、任務／交易／結果 | 合法持續pump或下一個已證入口；不能用native動畫tick假充Lua callback |

**相容設計 A-native-continuation（尚非新的最小規格／部署品）：**有限插播完成依賴準備與一次native啟動，依A政策End／解除等待，native效果在同一場景繼續。初始插播仍會干擾控制，故不符合B「全程正常操控」。演出角色不被改稱世界怪；Server也不因Client持續動畫就停止權威位置／命中／資產管理。

A1 v1的固定鍵與單次政策不改。本輪沒有私自把新角色／Fade塞入A1既有sequence。新內容、清理內容及其唯一雙鍵、來源座標／模型／slot、資源hash與驗收，需另行綁定。當下還無可用的持有／清理計畫時，不把「會持續」升級成可發布功能。

## 7. 全能力交接矩陣與剩餘工作

逐名稱121列見TSV；以下按玩家功能匯總，狀態不是T01或S00正式台帳。

| 功能域 | 已有靜態能力 | 仍須完成／保留的界線 |
|---|---|---|
| 發布／入口／parser | 相容資源選路、SceneList/0047、雙VM、Lua parser已有證據 | 官方MEF首載入/grammar仍Client未知；新發布品仍待配置與授權 |
| 排程／等待 | Register、qco/tco、resume/yield/End已證 | 正常戰鬥B入口／持續Lua仍未閉合 |
| 既有互動點 | 0027建立，0048/Lua同setter，A1最小規格 | Server合法資料／開放條件、實際部署與遊玩；不存在點不能upsert |
| Q角色 | 槽位、走位、動畫、臉部、顯示、批次clear | 新增post-End native鏈；仍缺可發布持有/清理與場景切換契約 |
| 世界NPC／外觀 | lb本地建物件、CDoll外觀與附件 | 本地counter不提供Lua新EntityId，不能取代Server一致的世界身分 |
| 鏡頭 | snapshot、work、跟隨、相對路徑、轉向 | 共享owner、非冪等pop，逐內容平衡取得/還原 |
| 音樂／聲音 | 既有播放、停止、fade、voice路線 | shared stream/handle，fade至0不等於release，無通用完成ACK |
| 淡幕／褐色／黑邊／慢動作 | native效果已證；本輪補Fade/Sepia inactive後consumer | 分開各自時基與停止/透明/回收；不把所有子系統當Server時間 |
| 對白／書本／字幕／數字 | 原表對白、文字、語音、Book及面板 | UI/context、資料key、完成與取消不同；數字面板不扣HP |
| 教學／玩家操作 | 提示點→controller progress→Lua→下一幕 | 限定Tutorial context；進度/點latch/點enabled三者分開 |
| 地圖／小地圖 | 已知本地loader／backup與BOUND連動 | 本地換圖不完成Server轉場；actor/point/ready與保存需整合 |
| NPC／商店／強化 | 原生服務UI路由、請求與結果已有局部鏈 | Server貨單、價錢、材料、背包、裝備、原子提交與保存 |
| 生成／死亡／波次 | 部分世界及演出物件機制已證 | 普通怪可供Lua消費的typed死亡/清組還未閉合；權威規則由Server實作 |
| 完成／取消／重入 | End、Stop、003F/00EB、owner差異已證 | 不能以回報代替效果成功，跨run遲到事件與多owner清理待整合 |

## 8. 精確未解、已查範圍與下一條證據入口

**B不中斷操控的首次入口：**0047已證會接管；OnYes在ordinary頁面不達、OnEndTalk需先有對話或activeQ Stop、GetExplain已識別頁面不符，均復用前輪反證，不重掃。下一個具體方向仍為`CScenarioTalkBox+9C`的其他**已定型receiver**寫入者，或`FE3184/6BD620`的其他合法間接caller；需接到普通場景事件來源與非Q首次載入，不能只找到相同offset。

**官方MEF入口/grammar：**已查MapList TRIGGER及原loader／named-call集合沒有正向新檔鏈。解除需可追的filename/bytes producer→reader→parser，不是新字串命中或把Lua改副檔名。本輪sink census不證全程式無入口。

**普通世界事件／身分：**lb本地counter不回新EntityId，Q slot不是world ID。若需求要替代真正生怪／普通清組，下一條必需證據是同一world entity的network create／更新／移除與合法Lua reader／callback；目前不能用空query、Q到點或Tutorial progress替代。

**新增native continuation的發布缺口：**本輪已接到actor位置／動畫／draw及Fade/Sepia狀態，仍需選實際內容、slot與依賴、收尾入口、same-field擁有權及退出政策。未配置這些不是native鏈不存在，而是跨功能整合。若下一題要「自動清掉保留Q actor」，應沿合法下一次Lua入口→DeleteAllObject與所有權追，不可用不存在的單體Delete或inactiveStop。

**Server待開發：**詳SERVER-HANDOFF，包括勝敗／開門條件、內容發布、服務、持久化、run協調與保留效果的持有紀錄。這些不被列成要求還原原版Server內部的逆向阻塞。

## 9. 驗證、交付與重跑

執行方法見README。`verification-result.json`是本輪實際核對輸出，`previous-a1-rerun.json`是重跑A1實際stdout。驗證包括原件SHA、PE mapping、精確程式端點、全部registrar解碼、指定sink重掃及分類、固定table hash、選定qbase指令。完整Native反組譯可由同一原件及manifest確定性重建。

本輪沒有執行Client/Lua/Server、發送封包、修改遊戲資源或正式規格狀態。**可確認的是所列靜態子鏈與資料一致性；所有功能實作完成、官方MEF完整復原及可玩驗收均沒有被宣稱達成。**
