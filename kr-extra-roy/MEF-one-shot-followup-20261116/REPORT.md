# 普通 Mission／Scenario 一次切點：非 Q callback 的入口與退出核對

工作分支：`extra/roy1`；本輪公開父提交 `716814e1ba88c1917a90b890a0187642eaca80ef`。核對 main 仍為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，沿用本對話已同步的歷史，不建立分支或空合併。本輪日期 2026-11-16（Asia/Taipei）；精確組包時間見 source-manifest.json。

> GitHub 閱讀副本：正文保留，只將包內相對連結改為檔名提示，避免未還原時連結失效。兩輪原始 Markdown、證據及驗證器逐位元組保存於研究包；[還原方式與逐檔雜湊](README.md)。

## 1. 目標、結論與前輪增量

目標仍是：**在普通 Mission／Scenario 的同一場景，經合法入口讓相容事件內容對一個已存在互動點作一次狀態切換，區分允許有限插播 A 與保持正常戰鬥操控 B。** 不要求腳本承擔通關、戰鬥、服務與持久化的全部 Server 職責；官方 MEF 首次載入與 grammar 未證，本文不偽稱還原原生格式。

上一輪未推送的 `MEF-one-shot-study-20261116` 完整原稿與 13 個交付檔已找回並重新驗證。其 A 為有條件、未部署的靜態完整鏈；B 的兩種 0047 時序有明確反證。本輪保存這些結果，不把它們重算為新增發現。

**本輪沒有取得符合 B 的新入口。** 已完成的增量是把上一輪提到的 native→Lua callback 候選追到正確 page／event producer、資料前置與 callback 返回後副作用，精確區分可達性與可用性：

| 候選 | 本輪後的結果 | 不能當成 B 解法的原因 |
|---|---|---|
| `OnYesTriggered` | 普通 page 拒絕結論直接復用 R7；補合成 inherited switch 與 callback 返回尾段 | 004E/F43DA 在 Mission／Scenario 不進此 callback；適用 Lobby／Tutorial 的成功分支還排 F4358 |
| `OnEndTalk` 的 F434E 事件 | 普通 page 確實可到 Lua；已追清已識別事件 producer | producer 是 active Q Stop bulk，不能把 Q 已接管後的關閉事件當成未接管入口 |
| `OnEndTalk` 的正常／自動對話完成 | 已閉合 selected-record gate、資料選取與 open/start 來源 | 必須先有已選對話；已識別的 open 啟動是 Lua binding，不能靠此反過來證明首次進入 Lua |
| `g_CharExplain.GetExplain` 的兩個 callsite | 延伸到具體正常 page vtable／event | 已識別上游是遠征、劇情結算與 Tutorial，不是正在戰鬥的 Mission／Scenario page |

這是**限定候選集合的阻塞結論**，不是全 Client 不存在任何間接呼叫的證明。B 的整體目標仍未完成；解除條件與下一個可核證據入口見第 9 節。

## 2. 第一手來源、復用與驗證方法

KR `Tartaros.bin`：12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32 i386、ImageBase 0x400000。`Event.stp`：11,241,597 bytes，SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。原件唯讀，只解析 Lua bytecode 為資料，沒有執行 Client／Lua／Server。

`native-evidence.json`（完整檔案見發布包） 保存 35 個原件區間的 VA、raw、長度、hash、指令數及角色，43 個精確指令錨點、10 組 switch table、8 組 vtable／RTTI、4 個名稱字串、120 條直接 transfer，以及 12 個明確 target 的有界 xref 候選。完整可讀反組譯見 `native-evidence.asm`（完整檔案見發布包）。以 GNU objdump 2.44 重算指令邊界、相同窗口、跳轉及資料；窗口數不是全程式覆蓋率。

`resource-evidence.json`（完整檔案見發布包） 僅保存原 qbase member 身分、兩個 callback 的 6 個 body 指令字與 4 個 root binding 指令字，不含完整解包 member。`verify_evidence.py`（完整檔案見發布包） 的 STPD／Lua parser 復用前輪已檢閱的 data-only parser；原始來源固定於 R14 blob `07615c139a6f19221355110cba857807559f7298`。

復用：R7 `MEF-world-integration-20261115/events/report.md` 的 004E 普通路由否定、R4 named-calls 的固定函式名／參數集合、R11 dialogue-ui 的對話資料與 namespace、以及上一輪 one-shot 的同場景 setter／輸入／退出契約。導航 `.c` 只用於辨認函式，關鍵主張核回 BIN。

**效率更正：**R7 已經完成「004E 到 OnYes，普通 page 不走該 callback」的有界分析。上一輪將 OnYes 再列為新的候選不夠精確；本輪只補 inherited route 合成與返回後副作用，後續不再把這個已排除路線當新任務重掃。

## 3. 先保留 A：允許有限插播的已閉合方案

完整原稿保存在本次共同發布包的 `MEF-one-shot-study-20261116/REPORT.md`。其結論是**條件式相容內容設計，不是已部署資源或人測成功**：

```text
有效普通 Mission／Scenario + 唯一既有 (category,key)
 → 0047 / SceneList 合法雙鍵與資源
 → 有限 prepass、正式 Register
 → native Start 尾段結束
 → 合格 Q pump 恢復 callback
 → Tutorial.SetCheckPointStatus(key,category,0/1)
 → 明確 End 並立即返回
 → 依 quest 分支處理等待與 controller busy 的正常消費
```

名稱位於 Tutorial 不表示 setter 需要 Tutorial controller：該方法使用共用 checkpoint manager `FB79F0`。它只改第一個既有相符點，不建立點、不回可靠成功 ACK。point key/category、scene 雙鍵、world EntityId、Q slot 分域；同場景期間不得由另一個 0027 重建或有未協調的競爭寫者。

A 的正常退出可有有限輸入中斷。quest0 End 的等待由適用原生 00EB 解除；非零 quest 的 003F 有確認條件，不能強制假設一定回報。End 不清 controller busy；須由後續合格 controller 更新消費。003F 不是 point 成功 ACK。

B 的前輪反證保持：deferred callback 前，`5615C4` 已寫 controller+58；同步載入頂層提前 End 又會被 Start 尾段 `561CCE` 重寫 checkpoint 呈現 gate；此外 F4358 有普通頁面控制器／相機副作用。不能靠 EnableInput、inactive End 或 00EB 抹掉這些不同 owner 的效果。

## 4. OnYes：已知事件不能在普通戰鬥 page 呼 Lua

### 4.1 原生事件和 typed 路由

`4B3570` 讀訊息 +2 的 u16 到 native selection token，`4B35D5` 推 F43DA，`4B35DA` 呼 `58AAD0` 排 UI event。common table `4ADF9D` 寫 `field+274=4B3570`，索引公式 **(0x274-4)/8=0x4E**。該 table 的 +4 不能略去。網路路由的完整版本沿用 R7，不重新宣稱是本輪新 opcode。

`595D20` 依事件範圍呼 page virtual +18C/+190/+194/+198；F43DA 落 +198。正常 vtable／RTTI 的精確結果：

| Page | vtable | +198 target | F43DA 結果 |
|---|---:|---:|---|
| CMissionFieldPage | C1D1AC | 5AD630 | 先呼共用 59BD80，自身所處理事件不含此值 |
| CScenarioFieldPage | C1D62C | 5AFE70 | 同上；自身僅處理所列兩項事件 |
| CLobbyPage／CPartyLobbyPage | C1EF14／C1F27C | 5B7F80 | switch 到 5B8177，再呼 5B96E0 |
| CTutorialPage | C1F5F4 | 5C3370 | 比較 F43DA 後呼 5C3610 |

不能只看 subclass 內沒寫 F43DA 就下結論。本輪同時核對 inherited `59BD80→5A4310`：

- `59C0CC[event-F4361]` 對 F43DA 為 26；`59C060+26*4` 是 default 59C057。
- `5A4310` 第一 switch 從 F43DB 開始，F43DA 不在範圍；第二 switch 的 `5A445C[event-F4366]` 得 9，target `5A4434+9*4=5A43F0`，也是 default。
- Lobby 的 `5B8460[event-F4364]` 與 `5B8394` target table 則確實到 5B8177。這是同資料方法核出的正反對照，不靠頁面名稱猜測。

### 4.2 callback 返回後還有副作用

Lobby `5B96E0` 於 `5B9742` 呼固定零引數 OnYesTriggered；Tutorial `5C3610` 於 `5C3672` 同樣呼叫。兩條路在 callback 返回後仍處理對話／視窗，並分別在 **5B977E／5C36AE 推 F4358**，再交 `58AAD0`。

因此即使換到能處理它的頁面，也不是無 owner 的純腳本 callback。切換到 Lobby／Tutorial 本身更違反本題「保留普通戰鬥場景與操控」的前提。此路線可從 B 的候選清單移除；已證功能不因此被說成不存在。

## 5. OnEndTalk：普通事件可到，但已知 producer 不是獨立入口

### 5.1 F434E 在普通頁面有真正 consumer

兩個普通 page 的 +190 都是 `5AC5C0`，其共用處理呼 `59B8C0`。F434E 在 `59B8F0` 取 page+B4 的 CScenarioTalkBox，`59B8F6` 呼 `6BD720`。該函式會呼 Lua OnEndTalk。共用第二 switch 對 F434E 落 default，沒有把它再次當別的事件。另一個 base consumer `5965D0` 也於 `596605` 呼相同 target。

這條普通 page→Lua 邊是正向成立的；**問題在事件如何被合法產生，以及內容是否已在 VM。** 本輪針對 DWORD F434E 的 raw-backed `.text/.rdata/.data` literal census 只有三處：

| literal 位址 | 指令／角色 |
|---|---|
| 5627A7 | 5627A6 `push F434E`，5627AB 呼 58AAD0，真正 producer |
| 5965DB | base page 的事件比較 |
| 59B8CC | ordinary 共用頁面的事件比較 |

producer 位於 **Q Stop `5624B0` 的 active bulk**。`56251E` 檢查 active，`562521` 在 inactive 時略過該 bulk。因此「先利用 Q，再 Stop，讓 F434E 呼 Lua」仍是 Q 已經接管的生命週期，不是 B 所需的未接管開始事件。直接編造一個 F434E 網路封包也不成立：它是內部 UI event，不是本輪證實的 wire opcode。

此 census 不涵蓋 computed event ID、外部模組、未知 indirect/alias writer；不把三個 literal 的有限結果宣稱為全程式無其他 producer。

### 5.2 OnEndTalk 不是「所有清理均已完成」的訊號

`6BD720..6BD7E7` 的正常順序：

1. `6BD77B→4A0540` 停止共用 voice；必要時有既有 owner 初始化。
2. `6BD7B0` 推固定名稱 OnEndTalk，`6BD7BC→4AD0A0` 在正式 wrapper 呼零引數 Lua 函式。
3. **返回後** `6BD7CB` 才呼此視窗 v+D4 隱藏。
4. **返回後** `6BD7CD` 才把 selected-record `this+9C=0`。

沒有在 callback 前檢查該視窗是否可見／selected-record 是否非空；這只說明 hide 的局部語義，不等於已得到新的外部觸發。新 callback 若重入相同 hide，會破壞一次性假設；返回值也不是 Server 的 point-state ACK。本文不為未知錯誤路徑補猜 finally 保證。

## 6. 正常對話完成：為什麼不能倒過來當首次入口

對話非 Q 的完成路徑值得獨立查，不應只因 Stop producer 失敗就跳過。本輪實際追到：

| 完成來源 | 原件條件 | 後續 |
|---|---|---|
| 一般 auto-talk 更新 5A4540 前段 | page+B4 非空、manual+A8==0、selected+9C 非空，時間差符合門檻 | 5A45A1 呼 6BD400 |
| 另一 auto-talk 更新 5A7530 | 同類 selected/manual gate | 5A7560 呼 6BD400 |
| 視窗手動事件 6BD4C0 | 事件 0x64、manual+A8 非零 | 6BD4D8 呼 6BD400 |
| 鍵盤處理 6BD5A0 | manual gate；0xD 推進；另一 0x2AFA 分支排 skip-confirm event | 6BD60F 呼 6BD400 |

`6BD400` 一開始讀 `this+9C`，為零立即返回。正常進度可轉下一列，最後一列又依資料分支選訊息／直接關閉；實際直接關閉在 `6BD467→6BD720`。因此不是每次 timer 或任意按鍵都無條件呼 OnEndTalk。

關鍵前置如下：

- CScenarioTalkBox ctor `6BCE70` 於 `6BCED9` 將 `+9C` 清零。
- `6BD620` open 用雙鍵查既有對白表，`6BD682` 寫 selected-record；命中後寫 manual/time，再於 `6BD6A3` 呼 start `6BD6B0`。
- start 自身也要求 selected 非空，才顯示與填入對白。
- native `6BD620` 的指定 E8/E9 census 無 direct candidate；raw pointer 命中只有 `6BDB1E`，屬正常 registrar `6BDB18: FE3184=6BD620`。start 有來自 open 的 direct caller，另有其 Lua registrar。
- 既有原 qbase 使用 `ScenarioTalkTable.open`；這是**已在 Lua 中的內容**開啟對話，並非找到一個尚未進 Lua 的 Server／普通場景事件。

所以在目前正常 binding／已識別 caller 集合中，依賴是 **已有 Lua → open → 顯示／推進 → OnEndTalk → Lua**，不能將後段倒過來證明首次入口已存在。對話可以成為已啟動內容的後續條件；它目前不解除 B 的首次啟動阻塞。

本輪**沒有**證明「所有對話都會全面鎖住戰鬥輸入」，也不以這種未查結論否定對話方案。可用的反證是具體 selected-record 與啟動依賴。UI capture、show/hide 的全部子樹及任意 callback 改寫不在本次語義閉包內。

## 7. 原 callback body 與另兩個 table-method 候選

### 7.1 qbase 原件實際做的是旗標寫入

從 Event.stp 固定 `Event/qbase.lua` member（block7378、offset10618896、length11836、SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`）只讀解析：

| Callback | root 實際 CLOSURE/SETGLOBAL | prototype | 完整 body 語義 |
|---|---|---:|---|
| OnYesTriggered | PC24–25 | P5 | 讀 TRUE，寫 g_yesTriggered，RETURN |
| OnEndTalk | PC32–33 | P9 | 讀 FALSE，寫 g_scenePlaying，RETURN |

兩個 prototype 均零參數、三條指令（GETGLOBAL/SETGLOBAL/RETURN）；沒有 loader、point setter 或 callback payload。這是已存在完成旗標的更新，不是未修改 Client 自動完成切點。若新增 setter 邏輯須明確標為相容內容改造，並先解決檔案可見性、正式 VM 載入和作用域；本輪未改任何遊戲內容。

### 7.2 g_CharExplain.GetExplain 不是本輪的新戰鬥事件

既有 named-call 清單另有兩個 table-method callsite。本輪不擴大掃全部 UI，僅往上核到 concrete normal owner：

| callsite／含括函式 | 已識別上游 | vtable／型別 | 判定 |
|---|---|---|---|
| 673034，672F00 | 5A6839、5A68F0，皆在 5A67D0 event handler | C1C1A4+194=5A67D0，CExpeditionPage | 遠征頁面；不是普通 Mission/Scenario +194 |
| 6BF7E5，6BF310 | 5AAED2 及 5C36DE | C1CBAC+18C=5AAE80，CScenarioResultPage；另一條為 Tutorial | 結算／教學，不是正在戰鬥的 ordinary page |

兩處原件查固定 `g_CharExplain` table，呼 GetExplain，傳整數並要求一個結果，後續當文字消費；不是從 Server 取得任意 filename／function name。本輪沒有把「Lua 函式可以被改寫」當成普通戰鬥必有合法觸發。保留 computed/indirect call 與未知額外安裝的邊界，不能升格全程式無路徑證明。

## 8. 同場景與狀態所有權的結論

本輪沒有繞過以下必要條件：正確普通 current field/page、正式 VM 已載入本次相容內容、同一場景的唯一既有 point、真正可達事件，以及不寫入 Q busy／不切場／不依已接管對話或未知 UI capture 的執行與退出。

有限 A 已具體定義的 setter 與 key 不需要重新逆向。對 B，**能在某個頁面呼 Lua**不等於**能從普通戰鬥的合法事件第一次到達本次內容**；也不等於**callback 返回時所有 UI 已恢復**。本輪恰好補齊這三項分別檢查，避免為了得到「有函式」而忽略事件、資料及 owner。

通關判定、何時允許開門、0027 集合與0048差量、服務結果、世界／任務及資產保存，都仍是 Server 待開發。它們不應阻塞 A 的靜態研究，也不能拿來猜補 B 的未知 Client 入口。`Server 開發交接`（完整檔案見發布包）

## 9. 精確阻塞、下一證據入口與建議調整

### 9.1 本輪可以結束的限定題目

「上一輪列出的 OnYes／OnEndTalk，以及既有另外兩個 named-method callsite，在正常 ordinary page 能否提供不經 Q 的首次一次性切點入口？」已完成所列正常初始化、直接 caller、switch 與資料前置的有界分析，**答案目前沒有正向成立鏈**。這個候選題到達具體證據阻塞；不是宣稱 B 的所有可能性都被排除。

### 9.2 解除 B 的可驗證條件

| 缺邊 | 下一份能實際解除的證據 | 不應再重做的已查集合 |
|---|---|---|
| 獨立普通事件 producer | 一個保持 Mission／Scenario 的真正 native→Lua 呼叫，含來源、參數及 page/context；或證實存在的額外已註冊 callback producer | 同一批 OnYes F43DA、Stop F434E literal census |
| 對話是否有獨立啟動來源 | CScenarioTalkBox+9C 的另一個**有 concrete receiver 身分**的 writer／dispatch；或 FE3184／6BD620 的真實間接 caller，且非已在 Lua 中的 open | 不能再用全程式 `+9C` 數值命中冒充同一物件；不能只重掃 E8 |
| 本次內容如何合法到達 VM | 固定正式 bootstrap 48D7xx／6BCF16 的資源初始化，與新候選 producer 在同一生命期的接線；需要實際被 resource loader 選到的內容 | 不把副檔名、global 已存在、UI callback 名稱當載入證據 |
| 操控與退出 | 證明該新正向路線的 input/capture/controller/map/UI 前後狀態，不引入 Q busy、page 替換或未釋放 owner | 不再以 EnableInput 或00EB 當通用恢復 |

目前資料沒有給出上述新增 concrete alias/caller，因此 B 保留未完成。若沿本次對話繼續，應先針對 **CScenarioTalkBox selected-record 的獨立 producer／FE3184 間接呼叫**立小題；沒有實際新指標流時停止該路線，不重做完整 MEF 搜尋。這是仍可進行的定向靜態入口，不把「需要 runtime」當成一切未知的替代說明。

### 9.3 建議優先做什麼

**先將 A 轉成一份最小可實作內容契約**：選有來源的 scene雙鍵與point(category,key)，只切狀態，不建角色、不換圖、不動鏡頭；處理 prepass/formal、End及相應等待解除。Server 平行實作資料發布、判定、請求序列化、結果對帳與保存。這比繼續擴增 API 清單更能形成玩家可感知成果。

B 保留獨立待逆向項，不強行拖住 A。原生 MEF 格式研究亦分線，不宣稱相容 seq/Lua 是官方 MEF。未經新授權不生成部署遊戲資源、不啟動 Client 或擴大測試；本輪授權僅續查與公開分析交付。

## 10. 實際驗證與發布

本輪只讀 verifier PASS：35 個原件 code windows、3,836 bytes、1,200 條解碼指令、43 個錨點、10 組 switch data、8 組型別vtable、120 個直接transfer、12 個指定target census；原 qbase只有兩個完整小callback及兩組root綁定節錄。這些數量是證據一致性，不是全部函式語義或遊玩完成。

上一輪原13檔 verifier 亦實跑 PASS（42 windows、3,380 instructions）；未宣稱重驗整個歷史Git source graph。兩輪完整原稿、已查範圍、來源與實際結果一併保存。發布只含研究及有限節錄，不含原始 BIN／EXE／STP、完整解包遊戲 member。Git 的研究包儲存方式、確切還原與hash校驗見外層發布 README；原本研究紀錄的「當時未push」欄位保留歷史，不改寫成當時已發布。
