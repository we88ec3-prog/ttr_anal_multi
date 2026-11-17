# MEF 使用流程續查：排程器、結束解鎖、換場與 VM 生命週期

> `extra/roy1`；本輪開始 **2026-11-15 06:53:42 Asia/Taipei**。使用者要求「請繼續分析 .mef 並上 git」。研究 parent：`a16841ac67638da4b29605f186f355722e8cf106`；本輪 main 基準：`ba5f96dfa94d734cbded291fb8887f50426bfa77`。
>
> **本輪已補上原始 `Coroutine.lua` 的完整 scheduler 證據，並找到 Client 現有的結束等待解除路徑。仍未證明新 `.mef` 在原版正常流程中的首次載入 caller；完整遊玩串接維持階段性未完成。**

## 1. 本輪真正新增了什麼

上輪的主要未解項之一，是只有 qbase／TutorialBase 的 scheduler 外層呼叫，缺少可重新解碼的 `Coroutine.lua` body。本輪沿歷史來源索引找到**既有 Git 中保存的原件 carrier**，恢復 2,168 bytes，確認 SHA-256 與 Git blob，靜態解出完整 **13 個 prototypes／187 個 instruction words**。這項證據缺口已解除，沒有要求取得官方 `.mef`。[原件來源與 scheduler 分題](MEF-runtime-contracts-20261115/scheduler/report.md)

由此確認四項直接影響實作的事實：

1. **`doCoTask` 忽略外層傳入的 `Q.EndCutScene`。** 它只有 `self` 參數，內部呼叫 `executeCoroutines` 也只傳 self；不能把「外層傳了 End callback」解讀成「工作跑完自動 End」。
2. **Lua coroutine 正常 return 不等於立即移出 MoCo list。** 正常 return 的 resume 仍為 true；若後續仍會排程並走訪同一 handle，下一次 dead-resume 才進移除支線。第一次移除還會直接結束該次遍歷。
3. **等待以 `lb.GetTime → WINMM!timeGetTime` 的毫秒值判斷，先 yield 再比時間。** 它不是固定 frame 計數；`wait(0)` 也會先讓出一次執行。
4. **Q 工作結束、輸入解鎖、UI 關閉和 Server 接受完成是四個不同條件。** `Q.EnableInput` 只清一層 mask；Q active 仍有獨立 controller 限制。部分 End 分支會重新設鎖並建立等待對話框，而既有 `S2C 00EB` 可到達明確解除 helper。

本輪另將上輪 `F4355` queue producer 追到當前 page 的真正 consumer，並釐清兩個 Lua VM 的建構、例外清 guard、重用與析構。詳細原件分成 [scheduler](MEF-runtime-contracts-20261115/scheduler/report.md)、[input-lifecycle](MEF-runtime-contracts-20261115/input-lifecycle/report.md)、[ui-lifecycle](MEF-runtime-contracts-20261115/ui-lifecycle/report.md)、[vm-lifetime](MEF-runtime-contracts-20261115/vm-lifetime/report.md) 四包。

## 2. 現在完整流程應怎麼理解

以下把前輪已證部分與本輪增量接在一起。「新 `.mef`」指未來要發布的內容，不以還原官方原檔為前提；通用 Lua loader 的能力也不代表上游已有人選中該檔。

| 階段 | 已確認的契約 | 本輪更新／仍需滿足的條件 |
|---|---|---|
| 發布內容 | 原 launcher 有啟動前 HTTP／gzip／普通檔案交付鏈 | Server 仍需實作相容發布；沒有新增 Game TCP 任意腳本載荷能力 |
| 資源可讀 | package 優先、ordinary fallback、checksum／prefix／cache 各有實際 gate | 存在性 probe、成功 open、成功 parse 分別驗證；不能因磁碟有檔就認定可執行 |
| 選中內容 | Q 依 SceneList key 組固定 `.seq`；Tutorial／Synopsis 載固定 Lua | **正常流程首次選中新 `.mef` 的正向 caller 仍未閉合** |
| 解析與頂層 | 已證 Lua text／5.1 chunk；正式 `DoFile` 對外回 numeric status | 頂層有限返回、檢查 status 與當次匯出身分，不能依賴 chunk return table 或跨 C callback yield |
| 前置收集 | 獨立 prepass VM 立即執行 Register body，收集依賴 | **每次清 native 收集容器，不是清空整個 Lua VM**；新內容要分開前置與正式效果 |
| 正式排程 | qco／tco 使用 recovered MoCo；由既有 native tick 推進 | **已核 wait、resume、移除、alive、回值和 callback 不轉交的實際語意** |
| 正常結束 | 既有樣本透過明確 Phase／RevPhase 呼叫 End | **自然 return／list 長度 0 不保證 Q.EndCutScene 被呼叫** |
| 中斷與換場 | 特定 Stop／End／field init 可清理；ordinary `005F` 固定鏈不保證先取消 Q | **F4355 是目前 page 的 UI hide 路由，不能當舊 runner 已停的證據** |
| 解除等待 | Q 部分 End 分支開 type 200 wait dialog 並設 mask | **00EB 共用 field callback → 562250 可關 dialog 並清 mask；它自身不 Stop Q** |
| Server 接受結果 | 按既有訊息及 instance／phase 判斷合法完成、取消及後續動作 | 規則、去重、狀態保存和回覆排程列為 **Server 開發需求**；不發明通用 MEF ACK |

交付／資源／parser 的詳細依據沿用 [上輪完整流程](20261115-060700-chatgpt-web-roy1-MEF-complete-flow.md)。本輪沒有重跑已收斂的 MapList root alias／CRT／一般 loader 清冊來充當新增入口。

## 3. Scheduler：內容究竟怎麼跑、怎麼停

### 3.1 recovered 原件的來源

來源由 T16 歷史索引接到 `shared/integrations/T01-20261028-06/resource-source-audit.json`，其中原件 SHA-256 為：

```text
c3feac03a40d24a54adf7615781cab175aa4876a2bdad8763987e413d0c2a808
```

既有 carrier 為 `kr/evidence/<上述 SHA-256>.txt`，Git blob `4d7434d97774c966a061e306d85718896db9833d`。重新取得的原始 bytes 同時符合兩種身分檢查與 Lua header；13 個 prototype 的 constants、operands、CFG 及原始 instruction words 都保存為研究證據。原始資源只作唯讀工作副本，未新增另一份原檔到 Git。[provenance](MEF-runtime-contracts-20261115/scheduler/provenance.json)

### 3.2 不能再假設 scheduler 自動 End

qbase／TutorialBase 的外層確實把 `Q.EndCutScene` 作額外引數傳給 `doCoTask`。但原始 `Coroutine.lua` 的 `doCoTask` prototype 為 **1 parameter、非 vararg**；其 SELF／CALL 只把 self 送進 `executeCoroutines`。BIN 中 Lua function-call 參數裁切也與這個 prototype 契約相符。

`executeCoroutines` 本身保留「進入時 task list 已空，且 callback 非 nil，才呼 callback」的分支；經目前 `doCoTask` 這條呼叫鏈，callback 沒有傳下去，值為 nil。因此**那個分支的存在不能提供這條 Q／Tutorial update chain 的自動 End 保證**。這不是因未知 body 而保留的猜測，現在已有原件可直接確認。[scheduler §doCoTask／bridge 證據](MEF-runtime-contracts-20261115/scheduler/report.md)

正常原件範例 `Event/Sequences/Phindous_YuriandRazed_Boss.seq` 有明確的 Phase 呼叫，最後經 `RevPhase1 → Q.EndCutScene`；本輪沿該樣本的實際 body 接回 qbase。**完成應由內容的結束流程負責，不能只寫一個會 return 的 coroutine 並假設 native 自動收尾。** 此結論是內容契約，不表示已把新 `.mef` 掛到該原始 `.seq`；原資源沒有改動。

### 3.3 true、dead、list 長度與業務完成並不相同

| 情況 | 原件 scheduler／Lua 行為 | 對新內容的影響 |
|---|---|---|
| coroutine yield | native resume 回 true＋yield values；MoCo 保留 handle | 後續必須仍有合法 tick 才能繼續 |
| coroutine 正常 return | resume 同樣回 true＋return values；MoCo 該次不因 dead 狀態立即移除 | 不能以單次成功 resume 證明 task 已從 list 消失 |
| 後續再次 resume 已 dead handle | false＋error；MoCo 印錯誤並移除 | 僅在 scheduler 仍被呼叫且走訪該 handle 時發生；Q 已 End 可沒有下一個 Q tick |
| 有效 thread 的 resume 回 false | 進 MoCo 的錯誤／移除分支 | 移除 handle 不等於回復畫面、關 Q、解鎖或 Server 成功；非 thread 引數等直接 raise 不保證走此支線 |
| 第一次移除發生 | `executeCoroutines` 直接 tail-return | list 後面的工作不在同次遍歷繼續執行；不能假定每個 task 每 tick 都跑一次 |
| `doCoTask` 返回 | `table.getn(current task list)` 數值 | Q 外層丟棄；Tutorial 外層返回給其 native owner；不是通用成功 flag |
| `isCoroutineAlive(handle)` | 查 coroutine status，不以當前 list membership 判斷 | handle 被移出排程，仍可能 suspended；alive 不等於將來會被排程 |
| `removeAllCoroutines` | 置換 task list | 不等於銷毀全部 Lua state、立即 GC 或自動取消所有 native 效果 |

內建 `coroutine.create` 還會檢查傳入的是 Lua closure；不能把一個 native C binding 直接當作可建立的 coroutine body。這些 native ABI 已另外核對，沒有用「標準 Lua 通常如此」替代本版 BIN 證據。[完整語義與 native anchors](MEF-runtime-contracts-20261115/scheduler/report.md)

### 3.4 等待的單位和時間邊界

`lb.GetTime` 的綁定、wrapper、IAT import 已接成 `4A0B70 → WINMM.dll!timeGetTime`。MoCo wait 先記時，每輪先 yield，再取時間做 elapsed comparison，所以 duration 的單位是毫秒，實際恢復時間仍受 tick 是否可達影響。

本版 wrapper 用 signed 32-bit `FILD` 轉 Lua number。跨過 `0x7FFFFFFF → 0x80000000` 時會出現符號不連續；wait body 沒有 unsigned modulo 修正。這是明確的計時邊界，不表示本輪已測過長時間 Client 執行。對 Server 的持久期限／斷線補償仍應由 Server 自行管理，不能把這個本地視覺等待當權威時鐘。[IAT、wrapper、原始 wait body 與官方 API 定義來源](MEF-runtime-contracts-20261115/scheduler/report.md)

## 4. 輸入與結束：找到可用解除入口，但不能用它把 Q 變成背景戰鬥服務

### 4.1 `EnableInput` 只處理一層 gate

本輪將 Q 的初始化 registration 接回實際 Lua wrapper／native target：`Q.EnableInput → 568BC0 → 562980`，在 `5629CE` 清 `FB8830` bit `0x2`；`Q.DisableInput → 5629F0` 設同一 bit。

Q 更新另在 `561520` 的 active 路徑將 controller `+58` 設 1，影響常規 `000A` 的控制動作。EnableInput 不改 controller `+58`、Q active 或 `M+2C` 停泵欄位。主 frame 已追到 input aggregation → mask filter → controller update → Q pump 的實際呼叫順序；Q 的寫入可以影響後續 controller pass。

**因此，即使腳本呼叫 EnableInput，也不能保證 Q 持續 active 時普通角色操作正常。** `M+2C` 額外停泵 gate 也不能當背景執行解法：controller 寫入在該 gate 判斷之前，非零又會停止 coroutine 推進。它的合法公開非零 writer 尚未閉合，不能說成已有可用的 Pause API。`Q.Rebind` 只改 binding receiver，沒有改全域 pump 的固定 Q owner；本輪沒有提出 pointer 改寫 workaround。[完整 input 原件鏈](MEF-runtime-contracts-20261115/input-lifecycle/report.md)

### 4.2 End 之後可能重新鎖住，須有解除階段

在本輪確認的 normal End 條件（非 review，`M+28 != 0`，`M+38 == 0`）中，`561DB0` 清 active 後可呼 `5620B0`，在 `56210C` **重新 OR 輸入 mask `0x2`**，建立 type 200 等待對話框。Stop 某處先清 mask，後續再呼 End；不能截取中間那次清位就寫成「Stop 最終必定解鎖」。[End／Stop 條件](MEF-runtime-contracts-20261115/input-lifecycle/report.md)

`F4322` 是附帶於等待對話框的 event tag，沒有排進一般 UI deque。它也不是可供 Server 直接發送的 wire opcode。顯示、移除 dialog 與清輸入 mask 分屬明確動作；type 200 自身的普通 hide 並不寫 `FB8830`。[dialog owner 與移除 consumer](MEF-runtime-contracts-20261115/ui-lifecycle/report.md)

### 4.3 現有 `S2C 00EB` 能到達解除 helper

本輪從共用 field callback 初始化 `4ADD50` 的 table slot 接回 packet index，再沿 scene manager／current field dispatch 核對：

```text
S2C 00EB → 共用 field callback 4B6190 → 562250
```

`562250` 以 `F4322` 尋找並移除 active-dialog list 中的等待對話框，之後明確清 `FB8830 & 0x2`；沒有匹配 dialog 時也仍會走清 mask。`4B6190` 自身不先 Stop Q，而且 callback 本體沒有讀 payload。

該 dispatch 鏈已核於**已初始化且未額外覆寫 callback 的普通 Scenario／Mission current field**。沒有 current field 時，default 分支只記錄錯誤；不能把 00EB 當成所有登入／無場景階段都有效的全域解鎖。

這提供了**實際存在、可列入相容 Server 流程的解除 consumer**。但「本體沒有讀 payload」不等於完整 transport frame／packet 長度已由此證明；本輪也沒有把 `C2S 003F → S2C 00EB` 宣告為已證的官方一對一回覆順序。Server 應按其 instance／劇情階段、合法結束或取消狀態安排這個既有訊息，並補做完整 wire 封裝及時序驗收。[00EB registration、dispatch 與 13 個解除 caller](MEF-runtime-contracts-20261115/input-lifecycle/report.md)

**不要在 Q 還 active 時只發 00EB 就認定已取消工作。** 它沒有處理 Q 的 controller gate，亦沒有移除 qco；解除等待和停止 runner 必須各自成立。

### 4.4 哪些場景會主動 Stop＋解除

`562250` 的有限 direct-call census 共 **13 個 caller**：00EB callback、Tutorial.StopCutScene，以及 **11 個 field init**。後兩類在解除前先 Stop(0)；普通 `005F` subtype 2／4 的 init 不在這個集合。

本輪進一步把 field hooks 接回具體 factory／packet subtype，包括 Expedition、Square／DuelSquare、MissionRoom／RaidRoom／DuelWaitRoom／DailyDungeonRoom，以及各 Decision 路徑。完整表保存在 input 分題；**這不是對所有場景共用一個取消保證**。普通 Scenario／Mission 的上輪限制仍成立。

## 5. 換場 UI：排入 F4355 不代表舊腳本已取消

普通 Scenario／Mission init 依 UI state 選擇寫 pending page，或呼 `58A9A0` 排入 `F4355`。本輪確認 UI 更新先消費 pending page，之後才由 `750550 → 74F000` 消費 queue。每筆事件重新讀取**當時 current page**；event 的完整 0x14-byte payload 沒有 producer page 或 field 身分。

state 5／7 的實際 page 經 `595D20 → 5AC5C0 → 59B8C0 → 597250`，走訪三棵已登錄視窗集合，只對可見視窗呼 `v+D4`。這個固定分支處理 UI 隱藏，未提供 Q／tco 移除契約。末端具體視窗及子控制項仍可能有不同 virtual 行為，所以也不擴張成「全程不可能間接取消」。[F4355 完整 producer／queue／consumer](MEF-runtime-contracts-20261115/ui-lifecycle/report.md)

由此可以收斂一個實作要求：**新場景 pointer 已安裝、UI 事件已排入、舊視窗已消失，均不足以作為啟動下一個工作前的取消完成條件。** Server 排程應使用已證的 Stop／End／場景 init 路徑及合法狀態；UI 內部事件不能替代 Server ACK。

## 6. 檔案、記憶體與重跑：新增的 VM 所有權證據

正式 wrapper `FDF3C8` 擁有 state；預掃描 owner `FE1EEC` 另外建立獨立 state，`FE1EF0` 指向的 wrapper 只是借用它。兩者平常重用，前置／正式 globals 不共享，但同一 VM 前後兩次載入也沒有自動乾淨環境保證。

本輪將 **21 個正式、8 個預掃描建構 callsite** 全部接回初始化 guard 和 atexit 登記。另有 **18／7 個 unique C++ unwind action** 會清各自的 guard，已用 caller prologue、EH handler、FuncInfo 與 unwind-map 閉合。因此準確說法是「正常路徑重用、建構例外另有清 guard」，而非「程序存活期間絕對只建一次」。[建構／例外／所有權原件](MEF-runtime-contracts-20261115/vm-lifetime/report.md)

每次 prepass `55D6A0` 清本次 native collection、music string，重新綁定，再用原 wrapper 載入；沒有建立新 Lua state。正式全域與 task handles 的存活則取決於 Lua 引用與內容清理。之前輸入 copy 已釋放，仍不影響已建立 closure／table 繼續存活。[本輪 VM 生命週期](MEF-runtime-contracts-20261115/vm-lifetime/report.md)、[原始 bytes／cache 分層](MEF-parser-executor-storage-20261114/storage.md)

`6F75F0` 關閉入口會先從 incoming state 找到 global state 的 main thread，再釋放整個 VM 所屬物件。**它不是卸載一個 `.mef` 或取消一條 coroutine 的介面。** native binding 的區域 wrapper 初始 owns=0，只是借用 state，不能把 stack cleanup 當成 VM 銷毀。

對「Client 的 `.mef` 是否在記憶體」的答案因而更完整：原始檔來源、resource cache、loader copy 與 Lua 執行物件是不同層；後者能長期在共用 VM 存活。**仍沒有證據說 MapList 指向的原生 `.mef` 已成功讀入，也沒有新增 `.mef` 專用固定儲存目錄的發現。**

## 7. 新 MEF 應落實的內容契約

本節是依已證 reader／VM／scheduler 推導的設計需求；沒有修改原 `.seq`／SceneList 或新增可執行遊戲資源。`.seq → DoFile(.mef)` 仍是需要實際可達、另有授權之新內容橋接的條件式方案。

| 內容部分 | 應明確實作 | 已證理由 |
|---|---|---|
| 有限頂層與版本匯出 | 初始化當次匯出資料／函式、版本識別；頂層可返回 | 全域 DoFile 只公開 numeric status；共用 VM 會留下既有定義 |
| 前置依賴 | 有限收集所需 actor／動作／音樂等，避開正式副作用 | prepass 是另一個 VM；Register 立即執行，wait/yield stub 不提供正式等待 |
| 正式 coroutine body | 用 Lua closure，在 DoFile 已返回後直接呼匯出工作 | create 的 closure 檢查與跨 C yield 限制 |
| 等待 | 使用毫秒參數；容許 tick 停頓；不得依賴 wait(0) 同步返回 | 原始 wait 先 yield，且使用本地 timeGetTime |
| 正常結束 | 明確執行與該入口相符的內容／native End 流程 | doCoTask 不轉交 callback，return 不會自動完成 Q 收尾 |
| 錯誤與取消 | 清自己的 handle／資料，區分已移除與 alive；明列要還原的 native 效果 | MoCo 移除非業務成功，list reset 不是整個 VM teardown |
| 重入與重跑 | 防止舊全域／舊 handle／部分載入副作用污染新一輪 | native caller 不普遍檢查 loader status；VM 正常重用 |
| 輸入與等待結束 | 驗證 Q active、controller gate、input mask、dialog 各自到位 | EnableInput、End、00EB、UI hide 涵蓋的欄位不同 |

因此，**有限對話／鏡頭／事件 actor 動作的內容契約與 Server 狀態機可以開始開發；無干擾的普通戰鬥常駐 runner 仍不能由 Q 的存在直接推出。** 實際替代哪項 Server 操作，需要在後續獲准驗收時關閉該操作，確認 Client 真正接手；單純 parse 成功或 Server 仍在代跑不構成驗收。

## 8. Server 開發需求與剩餘 Client 證據

### 8.1 Server 必須自行實作／整合

| Server 開發需求 | 具體完成條件 |
|---|---|
| 內容發布一致性 | 相容 launcher／HTTP 內容服務、路徑／版本／長度／checksum 一致，發布完成才允許新執行 |
| 劇情執行狀態 | instance、quest／scene、phase、執行代數與忙碌狀態明確；舊回報不能結束新一輪 |
| 正常完成／錯誤／取消分流 | 不把 coroutine return、MoCo list=0、003F 或 UI 隱藏一律視為任務成功 |
| End 後解除流程 | 按已證 Client 狀態安排既有 00EB／適用場景 init；補足 wire 封裝及時序驗收，不讓正常流程停在等待 mask |
| 換場與重入排程 | 先達成所選入口的實際取消契約，再建立下一輪；普通005F／F4355不能代替這項條件 |
| 權威結果與持久化 | 戰鬥、任務進度、獎勵、斷線恢復、去重與期限由 Server 狀態機負責 |

這些不以還原官方 Server 演算法為前提，也不是等待更多 Client 逆向才能開始處理的藉口。未證的 Client wire 欄位則不能用後端規格自行發明。

### 8.2 已解決與仍需續查的項目

| 項目 | 本輪後的狀態 | 下一步所需證據 |
|---|---|---|
| Coroutine body／wait／resume／移除／完成 callback | **本輪解除原件缺口**；完整 13-proto 可重驗 | 不再把原件 unavailable 當 blocker；後續按所選功能驗證 runtime 情境 |
| End 等待 dialog／input mask 的解除 consumer | **本輪已閉合 native 00EB 路徑與 13 個直接 caller** | 所選 Server 流程的完整 wire framing、合法時點、重複／延遲訊息驗收 |
| ordinary F4355 consumer | **本輪已閉合 state 5／7 固定分支** | 若需要特定 UI 覆寫的附加取消效果，提供實際視窗型別與下游證據 |
| 正式／prepass VM 生命週期 | **本輪補閉正常建構、guard exception、ownership／close 範圍** | 不以全 VM close 代替單一工作取消；針對內容的重跑／失敗恢復驗收 |
| 新 `.mef` 首次入口 | **仍未有正向 caller** | 正常事件 producer → 可讀 path／bytes → loader → 首次 execute 的完整鏈；或在允許範圍中落實可審閱的新內容橋接 |
| 普通戰鬥常駐 runner | **Q 的雙層輸入限制更明確，仍缺適用入口** | 不干擾普通控制的合法更新／取消 owner，不能只指出任意 tick |
| 戰鬥事件與身分 | **仍缺所選接管功能的連線** | 普通死亡／清組事件如何到 Lua、local actor 與 Server entity identity 的對應 |

第一個未解點仍不是「再找官方 `.mef` 原檔」，而是**新內容如何由正常流程真正到達 loader**。本輪同時消除了 scheduler body 的假設，讓後續找 caller 或設計橋接時有精確的執行／結束契約可用。

## 9. 版本、範圍與交付

已全文閱讀指定共用指示（本地檔 `09-02-PROJECT-SHARED-INSTRUCTIONS.md`），SHA-256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43`。同一研究鏈依本輪最新 main 做限定差異檢查；相較 `909754f28bd2e54c8ede00e3a56021cf59facd14`，兩份治理文件刪去先前整合摘要及連結。該文件 diff 不提供原件結論被否定或 review 退回的證據，未自行修改 owner／RR／完成狀態。[精確治理 diff](MEF-runtime-contracts-20261115/ui-lifecycle/governance-diff.patch)

本輪沿用 `extra/roy1`，只新增本主稿與 `kr-extra-roy/MEF-runtime-contracts-20261115/`。原始 BIN／STP／Coroutine bytes 保持唯讀；未執行 Client／Lua，未修改主程式或原資源，未加入 Server 程式實作。

每個分題附固定來源 commit／path／Git blob、原件 SHA-256、VA/raw/bytes、有限 candidate set／prototype operands、唯讀重驗程式與實際結果。來源 pin 與完整內容讀取分開標記，window 數量不冒充互不重複函式數。[證據包與重驗方式](MEF-runtime-contracts-20261115/README.md)

**靜態證據重驗通過不等於新 MEF 已接通、T01 FULL-PASS、RR ACCEPTED 或已完成遊玩驗收。** 本輪交付的是可支援後續實作的更完整契約與明確 Server 需求。
