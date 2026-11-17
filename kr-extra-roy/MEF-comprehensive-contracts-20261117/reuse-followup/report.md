# MEF 可重用生命周期補證：同一模型資源的 CDoll 引用、回載與 callback 收尾

日期：2026-11-17（Asia/Taipei）。來源基準 `extra/roy1@5ef4ab8870ea1c65c6c7497901302d851f5c7a51`。本稿是 [reuse 主報告](../reuse/report.md) §5／§8 的完成補證；兩稿應一併閱讀。不是正式 RR 接受、T01 FULL-PASS、Server 實作或遊玩驗收。

## 1. 結論與更正範圍

**保留的正常 CDoll 本身會持有模型資源引用；level 3 預載層不是唯一持有者。有效的新 CDoll 請求也會明確回載同一個 catalog resource。** 因此，不能從「Start(B) 移除 A 的 level 3」推導「仍留在 Q 樹中的 A 必然失去模型」，也不能從「catalog entry+54 非空，CreateObject 跳過按需配置」推導「卸載後不能自動恢復」。這兩個過寬推論在本附錄已被原 BIN 的實際 writer／callee 反證。

核心證據是 `79EB03 inc [resource+5C]`、`79F045 → 7C5BE0`，以及對稱的 `79ED76 dec [resource+5C]`。前兩者發生在 CDoll 請求工作中，與 `7A03B0` 的四層預載引用是不同來源。這不是找到另一個同名資源：`79E9D1` 從該模型 catalog record 的 `+54` 取 R，沿局部儲存、參數傳遞到 `79F042` 結果 `+4` 及 `79F045` 的 `ECX=R`。釋放則以同模型 key 再取 record+54。[本包 `doll_request_worker`、`materialize_reload_prefix`、`doll_release_worker`]

還有一個必須明示的呼叫關係更正：**Q.CreateObject 的真實建立路徑是 `56322E → 4D0FE0 → 4C7DF0(actor,1)`，首次請求為 immediate。** `C0C824+30` 指向 `4C8050`、後者傳 0，是虛擬槽的真實資料，但不能代替這一條 direct call。先前研究中若僅根據該槽把 Q.CreateObject 判成非 immediate，該推論不成立。[`q_create_actor`、`q_actor_immediate_init`、`actor_doll_init`、`base_init_virtual_slot`]

有界靜態目標已完成：本附錄連起實際 Q 建立 caller、同一資源引用取得／放回、resident 回載 writer、原 CDoll callback target、request 強引用與 render consumer。剩餘問題是特定內容／失敗策略與可玩整合，不再把此條回載鏈列為未知。**它仍不是任意失敗均會恢復的定理**：catalog identity、資產可讀性、clone／附屬物、正常 worker/apply 執行及 render gate 都有條件；state 3 的舊 CDoll 不會由選定 tick gate 自動重試。

## 2. 第一手來源與驗證單位

| 來源 | 原件識別與用途 |
|---|---|
| `02-Tartaros.bin` | 12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32/i386，image base `00400000`；全部 native 結論直接取此原件 |
| `06-Event.stp` | 11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；本附錄只核 identity，沒有把前包 qbase 成果再算新增解析 |
| Git C 指引 | 固定上述 commit 的 `kr-bulk-roy/<BIN SHA>/functions/0x*.c`，只供導航；本包有 37 個精確 Git blob／SHA-256 pins，包括相關舊原稿 |

[native-evidence.json](native-evidence.json) 與 [native-evidence.asm](native-evidence.asm) 保存 32 個窗口、15,571 bytes、5,007 個連續解碼指令起點、66 個指令錨點、36 條 selected direct call、5 個原始 vtable word、4 個 PE import。28 個窗口為完整 body，4 個明列為從函式起點解碼的 prefix；prefix 的外跳與後續未收 body 不被冒充全函式覆蓋。`REUSED_*` 是既有入口／計數器上下文，`NEW_*` 指本次功能鏈接合，不代表發現了同等數量的新 API。

原件 import table 確認 `BD20CC=CreateEventW`、`BD20D0=SetEvent`、`BD20FC=WaitForSingleObject`、`BD21C8=CloseHandle`。本次沒有執行 Client、Lua、Server、遊戲或封包。驗證器檢查的是原始 bytes、來源 pins、指令邊界／選定 call、資料 word、明列 SYN 案例；不是全引擎語義形式證明。

## 3. 必須分開的 identity 與欄位

本稿以 A 表示 Q actor、D 表示暫沿既有原稿名稱的 CDoll、R 表示模型 catalog record+54 的資源物件、Qreq 表示一次 doll 請求。不同物件上相同 offset 不能混用。

| 物件／欄位 | 本鏈確認用途 | 證據 |
|---|---|---|
| A+15C／+160 | CDoll object／shared control pair | `4C7E80..4C7E92` |
| D+10／+14 | 指回 D 的 weak pair；request 前轉 strong | `4CA4ED/4CA4F0`；`7A8F6A..7A8F7E` |
| D+18 | 本鏈 request 與 release 使用的模型 key | `7A4CC0`、`7A8F0F`、`7A5253` |
| D+1C | 目前模型 instance；初始／失敗為 NULL | `7A4CC3`、`7A9141`、`7A91B5` |
| D+20 | 選定請求的 immediate／等待分支 | `4C7EE6`、`7A8FD5`、`7A9070` |
| D+24 | 0 初始；2 request pending；3 無效結果；1 apply 正常末段 | `7A4CC9`、`7A8FFE`、`7A913A`、`7A9964` |
| D+28 | dirty request gate | `7A4CCC`、`7A5C93`、`7A8FFA` |
| Qreq+4 | request 建立時 `D.state==0` 的 first-load 布林；不是取消位 | `7A8FCB/7A8FCF/7A8FD2`、`7A96E4` |
| Qreq+68／+6C | 原 D 的 strong pair | `7A8F76/7A8F7E`；析構 `7AA9CE` |
| Qreq+70 | immediate event；非 immediate 使用 `FFFFFFFF` | `7A8FD5..7A8FF2` |
| result+4 | 此次 R | `79F03F/79F042` |
| result+8／+C | 此次 request 的 strong pair | `79F031..79F03A` |
| result+10 | 產出的模型 instance，之後寫入 D+1C | `79F056..79F06F`、`7A91B2/7A91B5` |
| R+5C | 共用引用計數，至少包括預載層與 CDoll 請求 | `7A0529/7A0701` 與 `79EB03/79ED76` |
| R+58／+60／+EC | unload/reload 狀態、resident 位、base asset pointer | `7C5BE0`、`7C4310`；前包 unload 證據 |

R+5C 與 shared control+4 是兩種不同的計數。前者管模型資源引用；後者保護 D／request／result 等 C++ 物件存活。不能用「request 活著」直接替代「asset 已載好」，也不能把清預載層視為釋放全部 CDoll strong reference。

## 4. Q.CreateObject 真實 caller：immediate 不是猜測

Q.CreateObject 完整 body 的 `56322C mov esi,ebx`、`56322E call4D0FE0`，把新 actor 傳到 Q 專用初始化。`4D0FE1 push1`、`4D0FE3 push esi`、`4D0FE4 call4C7DF0` 指定 immediate。

共同初始化在 A 尚未初始化的 gate 下配置 `0x170` bytes 的 D，選 A+8C 或 A+88 的模型值，以低 WORD 傳入 `7A4C50`。`4CA460` 建 shared pair 和 D 的 self weak pair，`4E0F60` 移入 A+15C/+160。`4C7EDE` 檢查參數，非零則 `4C7EE6` 設 D+20=1、`4C7EED` 立即呼 `7A8E70`。[`actor_doll_init`]

`7A8E70` 先建立 request 與 D strong hold，寫 D+28=0／D+24=2，提交到 manager `FC0E90` 的 request queue。D+20 非零時建立 event、提交後無限 wait、close。有效 worker 分支在 `79EC3C` 先呼 `7A90F0` apply 原 D，`79EC48` 再 SetEvent；無效 catalog 分支也先 apply failure，再 signal。**正常 event 完成不是單純「request 已排入」；但 wait 的回傳值未在這個 body 驗成功，也沒有因此取得全部資產／可見畫面的 ACK。**

後續 `4D1029 → 7A7240` 尚處理 D 的附加請求；本稿不以首個 immediate 回傳保證所有後續 attachment、motion、render readiness 都已就緒。這個界線也是不能把初次同步建立擴大為整場演出完全同步的原因。

## 5. 同一 R 的 lease 與回載已閉合

### 5.1 取得資源引用

`79E980` 從 Qreq+0 取模型 key，`79E9C1 → 515790` 查 catalog。找到 record 且 record+54 非 NULL 才進有效分支。`79E9D1` 的 EDI 就是 R，先存到局部 `[ebp-14]`。`79EB03` 對 R+5C 加 1，做 avatar／part 準備，再恢復該 EDI，`79EBED push edi` 傳入 `79EFC0`。因此這筆加 1 不是 level 3 的替代名稱，也不依賴目前 Q run key。

### 5.2 resident 已清仍有真實重新載入路徑

`79EFC0` prefix 建立 result，把 request strong pair 放進 result+8/+C；`79F03F` 讀參數 R，`79F042` 寫 result+4，接著 **`79F045 call7C5BE0`，receiver 正是同一 R**。

`7C5BE0` 先核 R+5C 非零，再核 R+60==0。因有效 doll worker 先加引用，此時即使沒有任何預載層，選定非零 gate 也能成立。resident 為 0 時會進 base reload `7C4310`；其中 `7C43E2 → 7D0920` 讀實際 base asset，`7C43E7` 寫 R+EC，資產存在的正常分支才在 `7C490C` 寫 R+60=1。上層還處理其他資料與 part consistency，並設 R+58=1。[`resource_reload`、`resource_base_reload`]

所以「record+54 留存」與「R+60=0」並不矛盾；前者可以讓後來的 CDoll request 找回 R，後者正是回載 gate。CreateObject 早期 `5630BE` 跳過 `541610` 只表示不用再次按需配置 catalog resource，**沒有跳過後面的 D request／resident reload**。

### 5.3 instance 與畫面另有 gate

`7C5100` 在 `7C5129` 檢查 R+EC，為 NULL 直接回 0；非 NULL 且 output instance 尚空，才經 base v+0C clone，配置 `0xB8` wrapper、`7D2DB0`，在 `7C518C` 寫 output pointer。這個輸出在正常 apply 路徑被複製到 D+1C。

result.byte0 的 1 在 `79F037` 就寫入，先於本次 reload／clone；它不是對這些後續資產動作的最終成功回報。apply 正常到達尾段會寫 D.state=1，但 render 仍要求 instance 與其他 readiness；不能把 state／event 直接當畫面成功。缺資產、配置異常或非正常 callee 返回的完整錯誤恢復，超出這條正常回載證明。

## 6. 引用放回、替換與工作排序

| 階段 | 真實 writer／consumer | 精確意義 |
|---|---|---|
| 有效新 request | `79EB03 inc [R+5C]` | 先取得新使用引用 |
| 初次 apply | Qreq+4==1 時 `7A96E8` 跳過舊 release 區 | 沒有上一個已應用 instance 可替換 |
| 後續正常 apply | Qreq+4==0 時建立 release spec；以 D+18 及先前 D+1C／maps填入；`7A98EB` 放入 manager+38 | 新引用取得後，舊使用才排釋放 |
| D 析構 | `7A520D` 只在 state==1 建 release；`7A5253/7A5264` 取 key／instance；`7A5325 → 79DE00` | 已應用的最後使用排入釋放 queue |
| release worker | `79ED42` 以 key 查 catalog，`79ED58` 取 record+54；`79ED76 dec [R+5C]` | 放回該正常使用引用；另釋放 part／instance |
| 預載層 replace | `7A0529` 減舊層，`7A0701` 加新層，`7A098E` 最終讀共同 R+5C | CDoll 的引用會參與同一個最終非零判斷 |

這組對稱關係以 **模型 key 到 record+54 的 identity 穩定、正常請求／apply／析構路徑**為前提。release 重新以 key 查 resource，並非將取得時的 raw R 直接存成永久 generation token。本包沒有宣稱全程式永不替換 catalog record，也沒有替既有 Client 發明 generation guard。單一正常替換會短暫同時有新舊引用，不能因此判成 leak；尚未處理的 release 也不能當成已清零。

`79DEA0` worker 先取 request／release queue，優先處理 manager+68 的 level job：`79E083 → 7A03B0`，`79E08E` signal；其後的不同分支才處理 `79E21B → 79E980` 與 `79E3DE → 79ED00`。因此 **Start／DeleteAll 內等待 level job 的 event，只證這個 job 的完成路徑，不等於所有 doll request、deferred apply、release queue 已 drain**。`79ED00` 完整 body 也沒有 direct call `7C4FF0`；此項是有界 direct-target 檢查，不是所有間接 callee 都不釋放資源的證明。

## 7. callback 指回誰？取消與生命週期的邊界

`4CA460` 把 D 的 self weak pair 寫在 D+10/+14。request 建立時 `7A8F6A` 指向該 pair，`7A9D90` 透過 `47C250` 的非零 strong-count CAS 保留原 D，再 `4E0F60` 移入 Qreq+68/+6C。這是原物件的 strong hold；若 weak lock 失敗，選定 helper 走 throw，而不是以 current scene 找另一個 actor。

result 在 `79F03A → 7A0DA0` 保留該 request。immediate apply 從 Qreq+68 取 D；deferred drain 在 `79DC57` 取 result+8、`79DC5A` 取 request+68、`79DC5E` 呼 apply。選定 consumer 直接更新原 D，不按當前 Q slot／scene key 重查。結果 queue 有時間 budget，`79DC6C` 比較 3；這也不能被默認成一次 tick 必然清空全部結果。

request control block 的 v0 是 `7AAA50`，呼 `7AA9A0` 析構 request。`7AA9CE` 讀 request+6C，`7AA9DB` 減 D 的 strong count；最後一份強引用消失才經其 v0 釋放 D。D control v0=`4CA660`，再經 D v0=`7A4FF0` 呼 `7A51C0`。因此 Q actor 放掉自己的 D 引用後，pending request／result 仍能使原 D 存活到 apply／釋放；這是生命期保護，**不是把 late callback 自動取消或轉送給新場景**。

在這條已查 request→worker→result→apply→release 鏈內，Qreq+4 是 first-load，不能當 cancel；沒有建立以 MEF run／generation 拒收舊結果的判斷。這是所選鏈的正向資料流結論，並非「整個引擎不存在任何取消機制」。因此規格不能把 normal End、清 Q tree 或 level-job wait 宣稱為全部 callback 已取消的 barrier。

## 8. 哪些舊 object 會沿用，哪些需要解除條件

`7A5C50` prefix 的 request gate 是 dirty 非 0 且 state 不是 2、也不是 3 才呼 `7A8E70`。D+1C 為 NULL 時另有後續更新 gate；draw 的 `7A63C0` 先看 D+1C 與 D+124，再看 motion v+2C／attachment v+30 的 readiness，通過後 `7A6556..7A655E` 才對 instance v+8 畫模型。draw 完整 body沒有直接呼 `7A8E70` 或 `7C5BE0`，不能把「持續 render」視為已證的 retry trigger。

| 跨 Start(B) 的具體狀態 | 本次可裁定事項 | 不能外推的事項 |
|---|---|---|
| A 的 D 已正常 apply，仍被持有；B 只移除 A 的預載層 | D 的 R 引用仍在，僅減該層不足以讓 R+5C 歸零；已不需要假設自動恢復才能解釋正常沿用 | 不保證 A 是 B 所需內容、可見旗標／動作不被其他 event 改寫 |
| R 已退駐但 record+54 留存；後來有效新 request 使用同 key | 有明確同 R 的 inc→reload→instance→apply 路徑 | 資產、part、配置、callback 正常執行與 draw gate 仍須成立 |
| request pending，Q actor 的持有被移除 | request/result 保護原 D；level-job wait 不等於取消該工作 | 不得宣稱 callback 已 drain，或一定會改到 B 的新 actor |
| 舊 D 收到無效結果而 state=3 | selected tick gate 排除重試；Start 的預載工作不會自動把該 D state 寫回0 | 若要重試，需真正的 reset／替換入口與 ownership 條件；不能只再送相同 scene tuple |
| B callback 先 DeleteAllObject，再建立 B 角色 | 全 Q tree與 B 剛準備的 level3 都被清；但後來有效 CreateObject 可經 immediate request 回載模型 | 不能再把這種排序單憑 level3 清空判成必然不能顯示；也不能把它當純 A 清理 |
| callback 中途換同 slot 的模型 | 仍受 Q tree duplicate slot、低 WORD／低 BYTE aliases、預掃描 first-slot 收集規則約束 | 回載鏈成立不等於真實兩 phase slot／model表已完成；不預設新slot可用 |

## 9. 對完整 MEF 實作方向的具體修訂

連續兩段演出的建議仍是先確認 A 對全 Q tree及共享狀態的合法控制，再在 A 尚能執行的清理時機做全清，normal End 後才允許 B Start。這個建議的依據是 **全域清理範圍、腳本執行時機與跨段干擾**，不是「晚清就必然卸載且回不來」。若實際內容選擇 B callback清場後建立 B，現在可把模型重建評估移到有效 CDoll request／資產 gate，不能再保留已被反證的單向毀損推論。

合法偏序要分成三種 completion：Q tree 操作完成、level job 完成、Doll/result/release 工作消化。前兩者已有具體函式返回／event路徑；第三者不能由前兩者冒充。若 Server／整合層需要「A 的全部 client 工作都已靜止」才宣告完成，這是另需正式完成證據或可接受過渡策略的需求，不能把既有 `003F`／`00EB` 猜成所有 callback完成 ACK。

本補證降低了兩 phase 的模型回載不確定性，沒有解決以下內容綁定：真實合法 scene/quest入口、同 key seen／skip政策、slot/model/action與資源manifest、共享receiver重綁、Camera/圖片/音樂的有限效果和清理所有權。前包 FlyingObject 的 pre-cancel 勘誤、End不是全 reset、單一DeleteObject stub與Server不虛構wire的結論均維持。

## 10. 已完成、剩餘工作與解除條件

| 類別 | 狀態／精確剩餘項目 | 下一個必要證據 |
|---|---|---|
| Client 靜態分析 | **本次完成**：Q實際immediate caller、同R lease/reload、release對稱、request strong hold、原D apply、draw gates | 本包原BIN窗口／驗證器 |
| Client 待逆向 | 若產品要求同一個 state3 D 原地重試：本包不提供已證 reset API；tick明確跳過3 | 從具體可達caller追 D+24 的其他 writer，核是否合法恢復；或採已證全清後重建且滿足ownership。這是額外失敗恢復需求，不是本次正常回載鏈未閉合 |
| Client 待逆向／跨功能整合 | 如果需要可觀測的全工作 drain：level job event不夠，所選result drain受budget限制 | 精確queue-empty／in-flight／apply/release完成的既有consumer或transition teardown證據；無此需求時不得擴大成整引擎重建 |
| 跨功能待整合 | 兩phase真實slot/model/action與prepass收集是否相容 | 實際內容表、依賴manifest、相同slot重建時機；不補虛構slot或scene key |
| Server 待開發 | 演出run狀態、內容版本／資源綁定、超時／失敗政策與重播策略 | 依已證Client介面定義Server需求；無新wire ACK便保持等待／取消／不確定狀態，不能猜官方Server內部規則 |
| 待遊玩驗證 | 真實資產可讀性、各render readiness、連續開始與外部中斷時畫面／聲音／鏡頭 | 綁定內容與可重現trace；本次沒有執行任何遊戲測試 |

對「同一 resource／舊 object 跨 Start(B) 是否有恢復」的停止點已達：正向持有與回載鏈、反例gate和適用條件完整列出。沒有因未執行遊戲而把仍可查的正向恢復保留成永久未知，也沒有為追所有失敗情境擴張成整個引擎。

## 11. 勘誤與 SYN 模型邊界

[errata.json](errata.json) 逐項對照前包 §5.2／§5.3／§8、同phase契約與 layer-only SYN，以及 R11 world-npc 的 slot facts與本次實際caller之別。原歷史稿保留；前包此次修訂在主文直接納入更正並連回本附錄，不讓讀者只靠末尾附註才發現過寬結論。

[reference_model.py](reference_model.py) 的12個案例均為 **SYN**：示範保留 D 引用能抵住僅清level3、同 R 回載、替換先加後減、pending request延長原D生命期、level event不是全queue drain，以及failed-state／asset-ready界線。模型使用虛構symbol，沒有真實slot／key配置；假設所選正常callee返回，不模擬引擎的全部異常與thread排程。這些案例的PASS不能替代原BIN資料流證據，更不是遊玩成功。

前包原來的4個預載層SYN已改名並明示 **zero-doll projection**，只保留「沒有CDoll／其他持有者」的有界意義。正常保留Doll情境的正反例使用本附錄模型，不能再把缺少CDoll的舊合成輸出當成完整生命周期預測。

## 12. 可重跑驗證

```bash
python -B verify_evidence.py \
  --bin /absolute/path/02-Tartaros.bin \
  --event /absolute/path/06-Event.stp \
  --repo /absolute/path/ttr_anal_multi \
  --out verification-result.json
```

所需是原件、固定 Git objects、Python standard library及objdump。程式只讀原件和 Git，`--out` 只能寫派生結果，不能覆寫輸入／證據檔。它不重新使用或修正舊aggregate verifier的parser pin；本附錄根本不import Lua parser，前包的審讀parser與原qbase核對另有真實結果。[source-manifest.json](source-manifest.json)、[artifact-manifest.json](artifact-manifest.json)、[verification-result.json](verification-result.json) 保存實際識別與結果。
