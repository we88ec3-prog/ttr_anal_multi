# R11：.mef 流程可使用的對白、文字、浮動面板與書本演出能力

## 1. 結論與適用範圍

這個 Client 已有可用於演出編排的**多段頭像對白、序章文字與語音、書本動畫、畫面字幕、物件位置上的數字／Miss／Block 面板，以及螢幕擊殺數／Critical 字樣**。它們有不同資料來源、owner、等待方式，不能只憑名稱互相替換。本章把 10 個 Q binding、`Prolog.OnClose` 與完整 5 個 `ScenarioTalkTable` 一般能力，共 **16 項**，接到實際的 producer、資料 reader、update／draw 或 UI consumer。

對使用者最有用的選擇是：**帶人物頭像、名字、多句內容並能按鍵推進的對白，走 `OpenTalkScene`／`OpenAutoTalkScene` → `ScenarioTalkTable.open`；`Q.Dialogue` 則使用 Prolog 表與 Synopsis 樣式，沒有選取世界人物。`Q.BalloonTalk` 在這個 build 的正常 target 是空操作。** 所有可見面板都須與 Server 的命中、傷害、擊殺、獎勵、交易與任務結果分開處理。

本章是既有 MEF 執行流程可呼叫能力的分析，**不把 native `.mef` parser 改稱一般 Lua 執行器**。若以新相容內容的外層 seq／Lua caller 編排這些能力，仍須遵守既有 prepass、正式 VM、Register、DoFile 返回後再進 coroutine、取消與清理契約。原生 MapList／TRIGGER 第一個 caller、ordinary-world 介面的未閉合範圍繼續保留，沒有因 UI 入口被辨認就宣告補齊。

直接來源是原始 BIN、Event.stp 的指定 qbase member、Table.stp 的五個指定 member 及其中 TalkTableSet 明示的 26 個 PATH。舊證據只以已公開 R10 `af97bbd29c892e031eef7a3bc3a98cb79f1be729` 釘選，main 為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。完整身份與 Git blob hash 見 [source-manifest.json](source-manifest.json)。新原件片段見 [native-windows.json](native-windows.json)／[native-windows.asm](native-windows.asm)，以下以其 window id 與 VA 引用；原 qbase 操作數見 [lua-evidence.json](lua-evidence.json)。

## 2. 先選對表達方式

| 需求 | 實際入口與效果 | 內容選取方式 | 等待／結果 |
|---|---|---|---|
| 多句頭像、名字、文字、表情與語音 | `ScenarioTalkTable.open(id, scene, manual)`；原 qbase 有手動／自動 helper | 場景雙鍵 → 每列 actor key／talk key；actor 是顯示資料身份 | qbase 等 `g_scenePlaying`；native hide 呼 `OnEndTalk`。不是 yes/no 或任務結算。 |
| Synopsis 樣式的序章文字／語音 | `Q.Dialogue(prologKey)` | `Table/Prolog.xml` 的 idx；Line 是 XML literal UTF-8 | helper 只 yield 一次；此 finite binding 集沒有 Dialogue 專用完成 query。 |
| 可互動的 Prolog 書頁文字 | `Q.Prolog(prologKey)`／`DoProlog` | 同 Prolog 表；另一個 owner 與 typed UI | `WaitForProlog` 讀數值 `Q.IsPrologRunning()==1`；0 也可能來自缺鍵或關閉。 |
| 固定書本演出 | `Q.Book(integer)`／`Book` | native 忽略該整數；讀 `Table/Book.txt` 的固定設定 | `WaitForBook` 讀 `Q.IsBookFlying()==1`；動畫／共享 voice gate 共同影響進度。 |
| 畫面上短文字 | `Q.InsertText(text)` | literal narrow string，依設定 codepage 轉寬字 | 固定 queue／tick fade；沒有本章已證完成 query。 |
| 物件位置數字、Critical 數字、Miss／Block 字樣 | `Q.NumberPanel(slot,style,value)`、`Q.BattlePanel(slot,style)` | live Q slot 的位置＋內建 style texture | 自己的動畫 update／draw／刪除；qbase wrapper 的 yield 不是動畫完成。 |
| 螢幕擊殺數與 Critical 字樣 | `Q.BurstStruck(killsFlag,criticalFlag,count)` | 數值開關及顯示 count，不選 Q 物件 | native update 計數器，沒有本章完成 query；不產生權威擊殺結果。 |
| 氣泡對話 | `Q.BalloonTalk(a,b)` | 兩個值在 native 被忽略 | 正常 target `550450: C2 08 00 / RET 8`；沒有氣泡 consumer。 |

本表的原生連結、必要條件、失敗與範圍限制均逐項落在 [contracts.json](contracts.json)。這份正向能力表不要求 MEF 完全替代一般戰鬥 Server 才算有用；Server 應提供權威事實，Client 可以編排與呈現這些事實。

## 3. 呼叫 ABI 與命名空間生命週期

### 3.1 Q 的參數會被轉換；呼叫成功不能從 action 回值推定

正常 Q receiver slot 是 `FE2778`，wrapper slot 是 `FE2774`。本章重新核對 registrar → 名稱字串／closure → converter → native target，以及 constructor 呼叫 registrar 的位置，16 項完整 tuple 見 [bindings.json](bindings.json)。

| Converter | 已證行為 | 內容契約 |
|---|---|---|
| `56A300` | 從最後一個 Lua 值取得字串；必要時嘗試轉字串，失敗為 null | InsertText 提供明確 literal 字串。 |
| `56A430` | 取最後一值，number 或可解析 numeric string → x87 `FISTP` dword；其他失敗值變 0 | Prolog、Book、Dialogue 使用明確 int32。不要把任意小數當保證朝零截斷。 |
| `56A220` | 從倒數兩值轉 int；再依原參數順序呼 target | BalloonTalk、BattlePanel 用精確二參數。 |
| `56A4B0` | 從倒數三值轉 int；再呼 target | NumberPanel、BurstStruck 用精確三參數。 |

這些 converter 沒有提供「精確 arity 不符即拒絕」的保證。數值轉換失敗會落到 0，所以新內容應先檢查整數與範圍。`Q.BurstStruck` 的開關是數值 0／非 0；Lua boolean `true` 並不是此 converter 接受的 number，不能拿來代替數字 1。

上述 action closure 最後回傳 C 函式的結果數 `1`，但沒有建立成功狀態值或 handle 的 push。這不代表「回傳 true」；若讀取回值，可能只是當時 stack 上既有值。原 qbase 對這些 action 都丟棄結果。`IsPrologRunning`／`IsBookFlying` 是另有 query wrapper 的數值結果，應與 action 分開理解。（windows `q_convert_*`、`Q_*_closure`；R10 world binding／observer 的公開 pins。）

### 3.2 ScenarioTalkTable 是正式 VM 中由 UI 物件建立的 namespace

`597D5E` 工廠配置 `0xAC` bytes，建構 `6BCE70`，UI ID 為 `0xD4`。vtable `C3EB44` 的 RTTI 明確指向 `FUI::CScenarioTalkBox`。建構子取得正式 wrapper `FDF3C8`，在 `6BCF16` 呼 `6BDA20` 建立 `ScenarioTalkTable`，寫 wrapper `FE317C`、receiver `FE3180`。它不是一個不依 UI context、永久存在的全域函式集合；物件銷毀會處理其 binding 生命週期。

| 一般能力 | Constructor call site | Registrar | Closure | Native target／slot |
|---|---:|---:|---:|---:|
| `open` | `6BCF1F` | `6BDB00` | `6BDEB0` | `6BD620`／`FE3184` |
| `start` | `6BCF25` | `6BDBA0` | `6BDF10` | `6BD6B0`／`FE3188` |
| `hideOtherUI` | `6BCF2B` | `6BDC40` | `6BDF70` | `6BD7F0`／`FE318C` |
| `showOtherUI` | `6BCF31` | `6BDCE0` | `6BDFD0` | `6BD9B0`／`FE3190` |
| `hide` | `6BCF37` | `6BDD80` | `6BE030` | `6BD720`／`FE3194` |

namespace producer 還直接註冊 `Rebind` → `6BDE20`；它經 `4A2BB0` 改 receiver slot，屬管理入口，本章不把它列作第六項玩法能力。正常 binding 證據只支持沒有被 runtime rebind／global 污染後的既定 target。

`open` converter `6BE090` 從倒數第三、第二值取得兩個 int；**最後一值走 Lua truthiness**：nil／false 為 false，數字 0 仍為 true。原 `OpenTalkScene` 用 `LOADBOOL true`，`OpenAutoTalkScene` 用 `LOADBOOL false`，沒有以數值 FALSE 代替這個參數。其餘四項不取業務參數。action 回值同樣不是成功 ACK。（windows `talkbox_factory`、`talkbox_ctor`、`talk_namespace`、`ScenarioTalkTable_*`、`talk_open_converter`。）

## 4. 多段人物對白的完整功能鏈

### 4.1 發起前先具備兩層資料

第一層是場景排列。`52EB80` 讀 `Table/ScenarioTalkTable.xml`；主初始化 caller `48D34C` 所在片段 `scenario_table_load_caller` 將資料交給集合 `FC1AF0`。每個場景 record stride `0x20`：

| Offset | 意義 |
|---|---|
| `+0`／`+4` | `id`、`scene` 雙鍵 |
| `+8`／`+0C` | 是否有 `msg`、msg 的文字鍵 |
| `+10..+18` | Talk vector |

每個 Talk record stride `0xC`：`+0` 是 `char` 或 `npc` 顯示角色鍵，`+4` 是 talk key，`+8` 是 parser 記錄的 kind（char=0、npc=1）。**本章完整讀到的 `6BD050` display consumer 只使用前兩欄，沒有按 kind 欄分流。** 不能由 XML 名稱推論它會找到場上玩家或 NPC entity。

第二層是文字與顯示角色資料。`CNPCTable` 建構 `5245B0` 將 singleton 指向 `FE1BD0`，actor tree 位於 owner `+8`，talk tree 位於 `+18`。載入順序 `5247D0` 是：

1. `524850` 讀 `Table/NPCTable.xml`，NPC ID 與 NAME literal，名稱以 UTF-8 轉寬字。
2. `525110` 讀 `Image/TalkNPC.xml`，延伸顯示角色名稱、face group、表情對應。這條延伸不能用「每個 char 都須在 NPCTable 出現」取代。
3. `527070` 讀 `Table/TalkTableSet.xml` 的每個 PATH，交 `526960` 載入 talk 表。Talk id 是 key；文字節點是 UTF-8 literal。`440130` 的實際 `MultiByteToWideChar` codepage 是 65001。talk record 保留 id、plain wstring、next、face 及經 native formatter 預備的 rich text。

文字不是把一個 Lua literal 直接塞給 `ScenarioTalkTable.open`，也不是由 Server 在這個 binding 的參數中帶文字。新內容若新增文字，必須把合法 table／依賴／語音與 UI 資源按既有發布流程提供給 Client。本章未展開 rich-text markup 的全 grammar，不宣稱任意 HTML 或新標記可用。（windows `scenario_table_reader`、`scenario_talk_append`、`npc_table_*`、`display_actor_*`、`talk_table_*`、`utf8_to_wide_talk`。）

TinyXML attribute／element lookup 的已查正常 ASCII comparison 走 `893CB1` → `893BB8`，把 A–Z 折成小寫再比較。本次原表有 2110 個大寫 `Talk` attribute；不能只用大小寫不同便判為缺欄。此結論限正常 ASCII 路徑，不擴成所有 locale／Unicode 名稱等價。

### 4.2 open → 選列 → 顯示的實際內容

原 `OpenTalkScene(id,scene)`／`OpenAutoTalkScene(id,scene)` 先設 `g_scenePlaying=TRUE`，呼 native open，再進 `WaitForScene`。native `6BD620` 線性查整份場景集合，匹配雙鍵；匹配後不 break，**最後一個同鍵場景勝出**。找到後保存 selected `+9C`、manual `+A8`、本次 open 的 `timeGetTime` 到 `+A4`，呼 `start`。

`6BD6B0` 顯示視窗，row index `+98=0`，把首個 Talk 放進 `+A0`；count≤1 時標記 last。`6BD050` 依該 Talk 執行：

- actor key 查 `NPC_Talk` image group，設定頭像 child `+88`（UI child ID `0x7D0`）。
- talk key 查 `CNPCTable+18`，將 payload 的 rich text `+28` 寫入文字 child `+84`（`0x44C`），更新版面。
- 同一 actor key 查 actor tree，將 actor name wstring 寫入姓名 child `+80`（`0x4B0`）。
- talk 的 face id 查 actor 的 face vector，取 face group／image key／相對 offset，顯示表情 child `+8C`（`0x834`）；沒有適用 face 時隱藏該 overlay。
- talk payload 的 id 交 `49FED0` 啟動其 voice 路徑，使用共用 sound manager。

這裡有可見人物身份與表情，但身份是**顯示 catalog key**，不是 Q slot、server EntityId，也不要求由這個 consumer 在地圖中尋找同名物件。若內容需要「某個世界 NPC 說話」，應由流程明確把世界事件與正確顯示鍵對應，不能把兩者數字相同當作規格。（`talkbox_open`、`talkbox_start`、`talkbox_bind_children`、`talkbox_display_row`。）

### 4.3 手動、自動、正常結束與 msg 分支

手動旗標為 true 時，`6BD4C0` 在 UI event `+10==100` 呼 next；`6BD5A0` 在 Enter `0xD` 呼 next。另一個 key `0x2AFA` 會建立內部 UI event `F43E5`，本章沒有把其尚未閉合 consumer 宣稱為選項確認或網路封包。

自動模式有兩個已追到的真 caller：`5A456C` 起的頁面 update 片段與 `5A7530`。它們取得 page `+B4` 的 talk box，確認 manual false、selected 非 null，且 `timeGetTime - box.openTime > 0x5DC`，再呼 next。**1500ms 是自 open 起算；所查 next／display 並未重設這個 timestamp。** 因而只能說存在開始後的原生計時推進，不能說每句保證各停 1.5 秒，也不能假定每種普通世界頁面都有同一 auto updater。

`6BD400` 的 next 有三個實質分支：

| 狀態與事件 | 下一步 | 對等待的影響 |
|---|---|---|
| 還有 Talk | index+1，取下一 row，再顯示頭像／文字／語音 | `g_scenePlaying` 仍維持播放中。 |
| 已在最後一 row，沒有 msg | 呼 `6BD720 hide` | 請求停止 voice → 正式 VM `OnEndTalk` → hide 視窗 → selected 清 0。 |
| 已在最後一 row，有 msg | lookup msg 文字鍵，放入文字 child 並顯示 | 這個分支沒有同時 close／OnEndTalk，也沒有證明會建立 yes/no 選項。 |

原 `OnEndTalk` 只有把 `g_scenePlaying` 設為 FALSE；`WaitForScene` 先 yield，再每次 Wait(100)，直到與數值 0 的比較允許退出。原 `OnNextTalk` prototype 是空的 RETURN。**結束對話不會自動變成任務同意、購買同意或領獎完成。** 原表 `msg` attribute 數為 0；本章仍把 native msg 分支記錄清楚，避免以沒有使用樣本的名稱推論出選項 schema。（`talkbox_next`、`talkbox_event`、`talkbox_key`、`auto_talk_update_*`、`talkbox_hide`；qbase P7、P9、P10、P17、P18。）

### 4.4 真實失敗與必須先驗的內容條件

找不到 `(id,scene)` 時，open 只把 selected 設為 null 然後返回，**沒有補呼 OnEndTalk**。由於 qbase 已先設播放中，無另外取消／timeout 設計就可能持續等。

更嚴格的是缺少 talk key：`6BD291` 把 local payload 設 0，仍接到 `6BD1D0`，`6BD1D3` 讀 payload `+24`，沒有 intervening null guard。不能把錯誤 key 當作可安全探測的 API。應在內容發布前檢查所有依賴，而非讓 Client 用一次 open 測存在性。空場景首 row 亦無有效段落可顯示；應要求新場景非空。

已對 supplied Table.stp 的五個指定 member 與 26 個宣告依賴做精確唯讀核對，沒有全量解包。結果如下；完整 member locator、stored／decoded hash、key 統計與缺鍵清單見 [resource-evidence.json](resource-evidence.json)。

| 核對範圍 | 實際數量／結果 |
|---|---|
| ScenarioTalkTable 場景列 | 6776 列、6775 組唯一雙鍵 |
| Talk 段落 | 24445 列；char 8954、npc 15491 |
| 重複雙鍵 | `(211,1)` 兩列；native 選最後一列 |
| 空場景 | `(460,1)`，zero-based row index 6526 |
| msg attribute | 0 |
| TalkTableSet 明示 PATH | 26 份，全數指定讀取 |
| 這 26 份中的文字 | 50222 Talk rows、50222 唯一 id |
| 場景參照的不同 talk key | 23928 |
| 在上述 26 份中未出現的參照 | 71 個不同 key、71 個 row reference，分布 18 個場景 |
| NPCTable | supplied member 實際 spelling 是 `Table/npctable.xml`，531 NPC rows |

71 個缺鍵是 `1093..1129`、`1131`、`1690..1693`、`5220..5235`、`45621..45633`。這是**明示讀集的完整性差異**，不是對所有可能 overlay／其他發布資源或整個 Client 可玩性的判決。`Image/TalkNPC.xml` 在 supplied Table archive 的精確 index path 不存在；本章只有其 native loader／consumer，沒有宣布角色延伸資源已齊備。新內容工具應把缺鍵、重複鍵、空列與顯示資源缺件轉成發布前明確失敗。

### 4.5 隱藏／恢復其他 UI 有真 consumer，但有 owner 限制

`hideOtherUI` 建立豁免 ID 集合 `D4,D3,93,92,11C`，呼 `58B450`；該路徑要求目前頁面的 virtual `+4` 回傳 `D6D8`，再交 `5968F0`。它遍歷 page `+64` children，對原本可見且非豁免的子視窗，將 ID 記錄在 page `+A0` set，再以 visibility virtual `+94(0)` 隱藏。

`showOtherUI` 走 `58B510→596A70`，在同一類頁面找 saved set 中的子視窗，呼 `+94(1)` 後清 set。這是可配對的 UI 操作；不是堆疊式多重 hide owner，也不會把舊頁面的 saved set 自動搬到新頁面。`ScenarioTalkTable.hide` 本身**不包含** `showOtherUI`。取消時應按照自己持有的頁面與 hide 範圍恢復，而非把 showOtherUI 當通用 reset。（`talkbox_hide_other_ui`、`talkbox_show_other_ui`、`*_other_ui_page_gate`、`hide_visible_page_children`、`restore_saved_page_children`。）

## 5. Q.Dialogue、Prolog 與 Book 如何不同

### 5.1 Dialogue：Prolog literal → Synopsis frame → 文字與 voice update

`Q.Dialogue` 的一個整數由 `5651F0` 送到 owner `FC1B90` 的 `582530`。此 owner 與 Prolog `FC1B18`、Book `FC1BF8` 分開。constructor `581C10` 用共用 loader `513560` 讀 `Table/Prolog.xml`：`PrologSet → Prolog idx → Dialog → Line`；多個 Line 以 LF 串接，`4028B0` 使用明確 UTF-8 codepage 65001 轉寬字。row stride `0x3C`，另保存 PicturePath 與從 0 起算的 ordinal。

`582530` 首次載入 `Synopsis/SynopsisFrame.eif`，清舊 queue、設 active／draw flag，查 key，將 row pointers 排入 queue，呼 `582400`。pop row 將文字送到 `56C620` 的文字物件，並把 key／ordinal 交 `4A03F0`，其格式字串為 **`Scenario/Prologue/P%02d_%02d.ogg`**。本 Dialogue consumer 沒有選 actor，也沒有使用 row 的 PicturePath 來保證每段切換圖片；不能把「loader 有讀圖片欄」直接當作此入口有圖片演出。

正常主 update 經 `48A120→581F70`；active 時，若共享 voice handle `FB72AC==0` 就取下一 row，無 row 時 `582670` 清 active／draw 並刪 frame。文字物件自己的 reveal counter 也在 update 內推進。主 draw 經 `582040` 畫 Synopsis frame，並呼 `56CA70`；它逐字交 `735BA0→735C90`，接到實際 font cache／graphics renderer。這條鏈已到 update 與 draw consumer，沒有停在名稱或啟動函式。

缺 key 會令 active 清 0，但不是帶錯誤碼的 Lua 結果。原 `Dialogue` helper 只呼 Q 然後 yield 一次，**沒有 WaitForDialogue**。沒有語音或語音 gate 已空時，row 推進可能很快；反之共用 channel 被其他演出占用又可能延後。本章不承諾每段顯示時間、一次 yield 後完成或缺音檔仍能讀完文字。（`q_dialogue`、`dialogue_*`、`prolog_table_load`、`utf8_to_wide_prolog`、`prologue_voice_start`、`font_*`、`main_dialogue_*`。）

原 Prolog.xml 有 27 個 idx、206 個 Dialog、657 個 Line，195 個 PicturePath attribute；最大單 Line 為 49 UTF-16 units。idx 集合為 1–13、15、17–29，內容文字未收錄於本交付。這些是資料觀測，不是給新內容任意占用現有 key 的授權。

### 5.2 FB72AC 是共享 voice handle pointer

`FB72AC=FB72A8+4` 是 playback handle pointer，**不是 boolean flag**。`4A03F0→49FE30` 在有有效新資源時可以停止／標記舊 handle，再建立並保存新 channel。新資源為 null 的路徑不保證把舊 handle 清掉。

主 sound update `49FA50` 在 handle `+24<=0`，且 backend 不存在或 backend virtual `+10` 回 0 時，標記 handle 並清 owner `+4`。因此 Dialogue 的「handle==0 可往下一段」與 Book 的聲音 gate 使用同一可被其他入口影響的資源。ScenarioTalk hide 所呼 `4A0540` 是停止請求，不能寫成該呼叫同步銷毀所有聲音。

需要交錯使用 Dialogue、ScenarioTalk、Prolog、Book 時，內容設計應明確序列化或協調此 owner，而不是各自看到自己 UI idle 就假定聲音已釋放。獨立聲音／音樂能力與資源路徑另見 [audiovisual 報告](../audiovisual/report.md)；跨組連結由整包 verifier 處理。

### 5.3 Prolog 與 Book 重用 R10 已閉合的生命週期

本輪重新核對 Q／Prolog binding 與原 qbase wait，但不重做已公開的 native observer 工作。來源是 source-manifest 釘選的 `MEF-control-flow-20261116/world/{report,native-windows,contracts}.json/md`。

- **Prolog**：Q.Prolog → `55F780`，owner `FC1B18`；typed UI `FUI::CPrologBookPanel`（constructor `5A3650`，UI ID `0x11C`）。`55F9D0` 更新 fade／文字；Enter／按鈕 `55F960` 先完成當前文字，再推進 row，耗盡後 close。`Prolog.OnClose→55F950` 是正常已註冊入口，會關閉並發內部 UI event。原 `PrologCloseCallback` 有定義且會呼它，但不能因此聲稱已找到 native 按該 callback 名自動呼叫的來源。
- **Book**：Q.Book `565140` 接受一整數 ABI，**native 沒有用這個整數選內容**。owner `FC1BF8` 由 `5826A0` 讀 `Table/Book.txt` 的兩個三分量設定，啟動 `57F950` 固定序列。四個 typed state 由 `57FA40` 更新；state 2 等自己 done 且 shared voice handle 為 0，其他狀態依模型 threshold／delta 推進，最末清 active。
- **等待**：原 `WaitForProlog`、`WaitForBook` 先 yield，再以數值 query 是否等於 1 決定 Wait(100)。`Is...==0` 可表示正常結束、關閉、未開始或失敗等狀態，不能直接當業務成功。

## 6. InsertText：直接文字字幕與長度契約

`5628C0` 收 literal char*，先 `46E270` 轉寬字，再交 queue owner `FC1C84` 的 `56B7F0`。這個轉換使用全域 `FBA808` codepage；本輪已核實 import `BD230C=KERNEL32!MultiByteToWideChar`，但沒有追到該 codepage 的確切設定值，不能把 InsertText 一律標成 UTF-8。這與 Prolog／Talk 的固定 UTF-8 reader 是不同契約。

queue record 的文字 buffer 是 **`0x200` bytes＝256 個 UTF-16 code units**，native 逐 WCHAR 複製直到 NUL，沒有長度 guard。新內容須保證轉換後最多 255 units 加終止 NUL，不應把不受限的使用者字串直送這個入口。record 還保存顏色、alpha、fade flag 與 age；queue 超過六列會丟最舊列。

主 update `491DED` 所在片段呼 `56B990`，增加 age，再用 `56B8B0` 調整位置／淡出；age≥`0x78` 可進 fade，alpha 每次減 2。這些是 native update 次數，不能換成未證的固定秒數。主 draw `492EFF→48A8C0` 取 queue，再呼 `56BA10`；實際字串交 `735C90` 字型渲染。InsertText 可以作場景短提示／字幕，不選人物、不查 talk key、沒有本章已證的「字幕顯示完成」回呼。（`q_insert_text`、`narrow_to_wide_configured`、`text_queue_*`、`main_text_*`。）

## 7. NumberPanel／BattlePanel：帶位置的可見結果

### 7.1 物件身份與原 qbase 分流

`5652E0`／`5653C0` 用完整 dword 第一參數查 **Q manager 的物件樹**；找不到便返回。找到後取該物件 virtual `+4C` 的三分量位置，對第三分量加 7.0，再交 field-panel manager `FD92A0`。因此第一參數是 live **Q slot**，不應混用 world EntityId、actor portrait key 或隨意選一個 NPC ID。

兩個原生簽名與 qbase helper 不同：

| 呼叫層 | 參數與分流 |
|---|---|
| `Q.NumberPanel(qSlot, style, value)` | style 為 0..5，value 是顯示數字。 |
| `Q.BattlePanel(qSlot, style)` | style 為 0..3，沒有第三參數。 |
| 原 `NumberPanel(qSlot, mode, value)` | mode<4 呼 `Q.BattlePanel(qSlot,mode)`，忽略 value；mode≥4 呼 `Q.NumberPanel(qSlot,mode-4,value)`；最後 yield。新內容限 mode 0..9。 |

原 qbase 沒有同名 global BattlePanel helper。負的 mode 不能因 `<4` 就被當合法，應在進 helper 前拒絕。（`q_number_panel`、`q_battle_panel`；qbase P57。）

### 7.2 內建 style 與資源

| Number style | 原 texture | 負 value 時的 style 重映射 |
|---:|---|---:|
| 0 | `DamageEnemy.dds` | 2 |
| 1 | `DamageNumber.dds` | 2 |
| 2 | `NumberHeal.dds` | 1 |
| 3 | `NumberSP.dds` | 3 |
| 4 | `NumberMP.dds` | 4 |
| 5 | `DamageEnemy.dds`，另加 `Critical.dds` | 5 |

| Battle style | 原 texture |
|---:|---|
| 0 | `miss.dds` |
| 1 | `block.dds` |
| 2 | `EnemyMiss.dds` |
| 3 | `block.dds` |

`7AB4E0` 建立上述 table。數字模型 loader `7AB7D0` 載 `Panel/NumberPanel%d.gb3` 的 0..9 templates，另有 `.emf` fallback；descriptor 與材質用各 style texture。這些檔名是 native 已證依賴，未在本輪提供全部模型／texture 原件，不能宣告視覺資產全部可部署。

`7ABCD0` 在 value=0 時不產生面板；負值先轉正，並按表換 style，**不是畫負號**。`INT32_MIN` 不能安全當一般可取絕對值的整數，新契約排除。Number style 在查表前沒有範圍保護；Battle 雖有 unsigned style>3 檢查，但之前已經索引 style 字串。所以兩者都須在進 native 前驗證範圍，不能靠返回值測支援樣式。

### 7.3 已閉合到畫面與移除

field panel vtable `C4FD0C` 的 RTTI 是 `IS3D::CFieldPanel`。Number／Battle consumer 依 digit 或提示 texture 建 descriptor `7BEDC0`，以 `7BE770` 複製模型、設定材質、尺寸與相對位置，`7BEE40` 建動畫，掛到 manager list。

主更新 `4925AA` 所在片段呼 `7AC230`，逐個 `7BEB30` 更新 camera-facing transform、位置／alpha／動畫；動畫 `7E9D50` 用 delta 減剩餘時間並設 done，manager 在 done 時清模型、銷毀物件並移除 list node。

主 draw `492B77` 所在片段對 list 呼 virtual `+8=7BED00`。它將物件放進 graphics owner `FB76A8+98` 的 bucket，virtual `+4=7BE660` 指明類別 21（`0x15`）；bucket 有 `0x800` 容量上限，滿時不登記。`799F20` 把 bucket array 送進 typed `IS3D::CFixedRenderPipeline`，其 vtable `+C=7D1310` 在 `7D16F8` 起遍歷 bucket 19–21，對 panel 呼 virtual `+C=7BEDA0`，最後轉送所持模型的 virtual `+28` render。**這已是正常逐幀渲染鏈，而非只知道建構函式叫「Panel」。**

整條鏈只把供給的 value／style 呈現為浮動視覺。Server 若需要顯示傷害、Miss、Block、治療或資源變化，應先完成權威判定，再由內容選正確 style 與已存在的 Q slot；此 API 不替代命中判定、HP 更新、金錢或背包更新。（`fieldpanel_*`、`number_panel_consumer`、`battle_panel_consumer`、`render_pipeline_*`、`main_panels_*`。）

## 8. BurstStruck：擊殺數與爆擊字樣，不是受擊指令

`565490` 只操作全域效果 owner `FD8F10`，沒有查 Q slot 或世界物件。三參數的實際用法是：

| 參數 | consumer 行為 |
|---|---|
| 第 1 個數值非 0 | 啟動 Kills 效果；scale=1、alpha=255、counter=60，保存第 3 個參數到 owner `+34`。 |
| 第 2 個數值非 0 | 啟動 Critical 與 Critical_Line；兩個 counter 分別 36、14。 |
| 第 3 個整數 | Kills 顯示數；只在第一分支使用，沒有角色／傷害身份語意。 |

`5592B0` 從 `UI/ImageSets` 建立 `Kills.dds`、`Num_Kills.dds`、`Critical.dds`、`Critical_Line.dds`、`AttackedFX.dds`。實際 `559680` draw 會在 counter、texture、display gate 成立時繪製；Kills 另要求 count 非 0，再以 atlas 算各位數。新內容應用正且有上界的顯示 count。

**AttackedFX 的 gate 在 owner `+94`；此 Q 入口沒有設它。** 所以雖然同一 owner 載入了該 texture，也不能宣稱 Q.BurstStruck 會產生受擊效果。兩個 flag 都為 0 也不是 clear/reset，而是沒有開新分支。

主 update 呼 `559390` 遞減 counter／調 scale／alpha／critical jitter；主 draw 另有頁面／UI gate 再呼 `559680`。60、36、14 是 update 計數，不是秒。原 qbase 只 yield 一次，沒有等待全部效果消失。這個入口可以呈現已知擊殺數與爆擊提示，但不會因此計入擊殺、扣血或發獎。（`q_burst_struck`、`burst_*`、`main_burst_*`。）

## 9. 對話結束、玩家選擇與 Server 回報要分開

原 `OnYesTriggered`／`OnNoTriggered` 分別設各自 flag。`CheckConfirmMessage` 先看 no 是否不等於 FALSE，有則回 0；否則 yes 不等於 FALSE 回 1，其他回 0。`WaitAndCheckConfirmMessage` **先 yield，再清兩個 flag**，之後才 loop 等觸發；若確認事件在第一次 yield 之前就到，會被後面的 reset 清掉。

既有公開證據已閉合 `004E → F43DA` 在 MissionLobby state 4／Tutorial `0xF` 的 `OnYesTriggered` namecall；ordinary Mission 5／Scenario 7 的分支不是同一路徑，不能假設任意頁面都會轉發。原 qbase 的 OnNo 有定義，不等於本限定讀集已有 native caller。來源是 source-manifest 的 R8 `named-calls/report.md`、`events/report.md`，本輪不重掃舊的負證據。

`OnEndTalk` 不設 yes／no。**正常非 review、active、非零 quest 的 End**，只有轉換後的 `CheckConfirmMessage` 恰等於 1，才在 `561FB0` 發 `003F`。這個條件不能泛化所有 sender：正常 active 的 quest 0 End 在 `561FE0` 送出並設定等待；quest 0 已看 skip 也能在 `5618C8` 送出，而本次 seq 尚未載入。inactive End 與 review 又有各自分支。這些邊界重用 source-manifest 釘選的 R9 entry §7 和 R10 presentation；`003F` 因此既不是通用玩家同意，也不是演出成功憑證。自然讀完多句文字、點 next、調 hide 或顯示一個 BattlePanel，都不構成 Server 收到任務同意。要做選項、交易、接任務或領取獎勵，**Server 開發需求**是提供可關聯 session／request／操作身份的決策協定、驗證權限與前提、處理拒絕／逾時／重送／重入，並把回應接到已證的 Client 頁面或另有完整 contract 的入口。不能以 msg 欄或 namecall 名稱自行發明商店／選項 schema。

## 10. 可審閱的新內容編排範例與取消條件

下列是**條件式設計 pseudocode**，不是可部署 Lua、seq 或 mef，也沒有分配新的 scene key、actor key、模型或座標。

```text
輸入：已分配的 STORY_ID、SCENE_ID、PROLOG_IDX、LIVE_Q_SLOT、已核實的顯示結果
前置：既有發布／雙 VM／Register 契約已成立；UI 物件與所需 assets 已就緒

1. 預驗 STORY_ID/SCENE_ID 唯一、非空；全部 talk／actor／portrait／face key 可解。
2. 若本流程需要隱藏其他 UI：在目前適用 page 執行 hideOtherUI，記錄該 page 的持有狀態。
3. 以 OpenTalkScene 發起手動對話，或在已證 auto-updater 的 page 使用 OpenAutoTalkScene。
4. 只有 OnEndTalk 對應的 scene-playing 狀態結束，才走「對話已關閉」後續。
   缺 key、取消、page 更換、逾時各走明確失敗／收尾路徑；不等待假定的成功回值。
5. 如需數值提示，將 Server 已確認的結果映射為合法 Number/Battle style，使用本輪 live Q slot。
6. 依已持有紀錄恢復同 page 的其他 UI、協調共用 voice；接續其他效果的 cleanup。
7. 若需要玩家決策或業務完成，另等已關聯且有來源的確認／Server 結果。
8. 在 Q.End 前完成自己持有的清理；End／003F 的條件按原完整流程處理。
```

單次 coroutine yield 是交回排程，並不表示 panel、聲音或字母 reveal 完成。沒有完成 query 的能力要靠已證的時序／owner 狀態或明訂的內容流程，而不是用一個固定 sleep 假裝已證。外層 supervisor 對 Lua error／cancel 的可達 cleanup 契約沿用公開 R10，視覺狀態釋放與 End／Stop 次序見 [audiovisual 報告](../audiovisual/report.md) 及 source-manifest 釘選 R10 presentation。原 End 先清 active 後再 Stop，不能補走原 bulk cleanup；這個限制在本章 UI 編排也要保留。

## 11. Server／內容工具的具體開發需求

| 需求 | 本章已給的 Client 契約 | Server／內容工具應完成的工作 |
|---|---|---|
| 對白發布 | 場景雙鍵、actor／talk 讀取、固定 UTF-8 reader、名字／頭像／表情／voice consumer | 分配／版本化內容 key；檢查重複、空場景、全部依賴與語系版本；不要在 Client 上以失敗 key 試探。 |
| 身份隔離 | Q slot、顯示 actor key、talk key、Prolog idx 各有不同 consumer | 在 schema 上分開，明訂與世界 EntityId／quest session 的對應。Book 整數不得列作選書 key。 |
| 顯示傷害／擊殺 | Number／Battle／BurstStruck 的 style、value、位置、update／draw 已閉合 | 權威計算命中、HP、資源、擊殺、獎勵；只把已核實的結果交給演出呈現。 |
| 玩家選擇／商店／任務 | Scene end 和確認 flag 是不同路徑；msg 尚非選項 schema | 提供可驗證、可關聯、防重複執行的決策／交易／任務狀態協定與適用 Client 入口。 |
| 等待與回報 | scene close、Prolog／Book query、一次 yield 的語意已區分 | 對正常、失敗、取消、timeout 定義不同結果；不以 idle 或未收到 003F 當成功。 |
| 清理與再入 | same-page UI saved set、shared voice handle、原 End／Stop 次序 | 追蹤取得的效果／UI owner；page replacement、重入和中斷要有明確回收。 |
| 原生入口缺口 | 本章提供能用的能力，沒有補掉原 MapList／ordinary 入口 | 依既有總報告保留各條未閉合 caller；Server 新入口開發須選明確已證或新設計合約。 |

這些是 Server 開發與內容發布需求，不寫成「再找到更多 Client 函式就會自動完成」。同時，本章也不以普通戰鬥能否完全由 MEF 取代作為對白與演出能力的完成標準。

## 12. 重跑、交付與證據界線

執行方式（只讀 originals／repo，結果預設 stdout）：

```sh
python -B verify_evidence.py --originals /path/to/project_sources --repo /path/to/ttr_anal_multi
```

可選 `--out /path/to/result.json` 只寫結果 JSON。工具使用 Python 標準函式庫、GNU objdump 與本機 Git objects；不 fetch、不執行或編譯 Lua、不啟動 Client、不產生可部署遊戲資源。它核對：

- 4 份原始來源身份、公開 parent／main ancestry、16 個 Git blob pins。
- 150 個 bounded native windows 的 VA→raw mapping、33668 bytes 的 opcode／逐指令 disassembly，以及指定字串、vtable／RTTI、import 與關鍵 ABI anchors。
- 16 項 normal binding 的 constructor call、registrar slot／target、名稱、closure。
- 原 qbase 76 prototypes／906 instruction words 中，與此章直接相關的 20 個 prototype 選段、210 個原始 word／operands；包含 root 的 CLOSURE／SETGLOBAL 關係。
- 31 個選定 Table members（5 個指定＋26 個明示 PATH）及其 schema／key aggregates；沒有把整個 archive 解包輸出。
- 機讀能力／狀態契約的 evidence references 與交付檔案 hash。

實際結果見 [verification-result.json](verification-result.json)；交付 allowlist 與 hash 見 [deliverables-manifest.json](deliverables-manifest.json)。只有 allowlist 內的報告、選段證據、機讀契約、pin、verifier 與結果可併入 Git；工作目錄 `_work`／完整 parsed scratch 資料、原 BIN／STP、完整解碼 member、遊戲資源均不屬交付。

**PASS 只代表這份靜態證據與其原始來源一致。** 它不代表動態可玩驗收、所有模型／UI／聲音 assets 已具備、T01 FULL-PASS、RR ACCEPTED、Server 行為完成或未知 native caller 已補齊。這些限制與具體可顯示能力同時保留。
