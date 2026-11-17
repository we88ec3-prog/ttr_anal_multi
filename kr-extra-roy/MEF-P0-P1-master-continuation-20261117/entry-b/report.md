# P1：普通場景首次入口 B——receiver 安裝、繼承資料路徑與 Master 新來源

工作分支 `extra/roy1`；本輪來源基準 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa`，2026-11-17。本分題只新增研究證據與契約，未修改原 Client／資源、未執行遊戲／Lua／Server，也不變更正式 Task、RR 或 T01 驗收狀態。

## 1. 結論及本輪真正新增的範圍

**本輪沒有建立符合 B 的首次內容入口。已完成的是先前尚未閉合的正常 receiver 安裝鏈、全域 receiver 的指定 writer 集合，以及繼承 XML reader／clone 的有界資料流分析。** 這些結果進一步排除了把「普通頁面有對話物件」「建立 Lua namespace」「可重綁 receiver」當成普通戰鬥背景腳本入口的接法；`Master.stp` 則提供了新的、具體的 `.mef` 容器來源方向。

B 的要求是：保留普通 Mission／Scenario 的 current field/page 與一般操作，由原版實際可達的 producer 首次載入或登記本次內容，在同一 VM 持續得到 pump，並具備 owner、取消與重入契約。這不是只證明某個 native 函式或 Lua callback 存在。

| 本輪候選 | 新確認結果 | 對 B 的裁決 |
|---|---|---|
| 普通頁面建立 `CScenarioTalkBox` | Mission／Scenario 的真實 initializer 會取得同一 cached descriptor；`page+B4` 與 `FE3180` 正常指向其 talk instance | receiver 來源閉合；建 namespace／C closure 不等於第一次載入新內容或開始普通 pump |
| `ScenarioTalkTable.Rebind` | 從既有 Lua 的最後參數轉成整數，直接覆寫 `FE3180`；不是具 RTTI 檢查的物件工廠 | 不能作首次入口或合法新 owner 的證明 |
| talk 繼承 XML reader | 完整 reader 中，原 receiver 的直接寫入及兩個矩形 helper 只處理 base 欄位；結尾接固定 child lookup | 未補出 `selected+9C` writer；動態 child/resource 子圖保留明確邊界 |
| talk 繼承 clone/copy | clone 配置 `0x80`、寫 `FXUIDummy` vptr；base copy 不複製 talk 的 `+9C` | 不是另一個已初始化 `CScenarioTalkBox` 或 callback owner |
| 新 `Master.stp` | `Field/AttachedPackage=Field`，`PackingRules` 的 Field 列明列 `xml`、`mef`；`UI/LUA` 列另含 `lua` | 證實封裝宣告及下一個原件來源；未提供 payload、grammar、實際 reader 或普通 pump |

**B 功能仍為 `NOT_CLOSED`。** 本包 `COMPLETE` 僅指表內指定靜態候選已得到可核對的結論；verifier 的 PASS 也不會把 B、官方 MEF、T01 FULL-PASS 或可玩狀態改成完成。機讀狀態與五個候選的逐項裁決見 [candidate-contracts.json](candidate-contracts.json)。

### 復用界線

上一輪已完成 121 個正式 binding、33 個 marshaller、122 個固定 registrar、223 個 closure sink caller，以及 talk concrete vtable 的 91 槽／7 個 override。這些不是本輪的新盤點。OnYes 的普通頁面路由、OnEndTalk 的既有 selected 前置、GetExplain 的實際頁面限制、Q/T 的已知 pump，以及 Q busy 與 input mask 的分工均直接沿用。〔S03–S13〕

本輪改查 **誰建立並安裝這個 receiver、指定全域欄位由誰寫入，以及 inherited 資料讀取／複製是否漏掉另一種 selected producer**。沒有重掃相同 `.mef` 字串、重列已排除的 OnYes callsite，或把任意呼叫原生地址視為正向入口。

## 2. 原件、證據身分與方法

| 原件 | Bytes | SHA-256 |
|---|---:|---|
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `11-Master.stp` | 1,094,887 | `f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d` |

BIN 是 PE32/i386，image base `0x400000`；VA→raw 一律按原件節區表換算。[native-evidence.json](native-evidence.json) 保存 39 個完整函式或明確 prefix／fragment，共 6,541 bytes、2,139 條指令，以及 24 個限定 data／RTTI 窗口。完整可讀指令在 [native-evidence.asm](native-evidence.asm)。所有 code window 都有精確起訖、raw offset、完整 bytes、hash 與逐指令 bytes；prefix 不冒稱整個 caller 已展開。

[source-manifest.json](source-manifest.json) 固定 48 項 Git 來源的 commit、path、blob、bytes、SHA-256，並記錄原件與使用者提供的共用指示。bulk C 只作導航，本文的新 native 主張核回原 BIN；舊報告則明確標成復用。Master 只保存五個必要資料窗口，不提交完整 package 或解包成員。

本輪針對六個已識別 target 取得 `.text` 的 E8/E9 候選，另對這六個 target、`FE3180`、`FE2C5C` 在 raw-backed `.text/.rdata/.data` 取得 DWORD literal 候選。這是有界的直接／literal 集合，不是全程式 computed alias、外部模組或 runtime 改寫的形式化窮盡。

## 3. 普通頁面與 Lua binding 確實共用哪個 receiver

### 3.1 從普通 page 的 initializer 接到實際配置

原 vtable `C1D1AC+108` 是 Mission `5ACEA0`，`C1D62C+108` 是 Scenario `5AFC30`。兩者都接 `5AC3E0 → 598890 → 5A3980 → 596010`。本包保存每個 initializer 從真正起點到該直接 call 的完整前綴，沒有把相同 offset 的別種物件當作普通 page。〔B21–B25；D04–D05；普通 page 型別與 factory 沿用 S08〕

`596010` 的資料流是：

1. `596061` 呼 `597BC0` 取得 cached descriptor。
2. `596066` 計算 **原 page receiver 的 `+B4`**，把該地址交給 `5A9F40`。
3. descriptor 的 `+10=5ADE20` 回 `descriptor+C` window；`+4=7B3250` 回 `descriptor+4` resource ID。
4. `5A3840` 於 `5A3888` 把 supplied window 寫到上述 destination，之後才接 manager 載入與 UI 隱藏／狀態操作。

這次把 `page+B4` 的來源閉合為真實 descriptor/window，並非由 page update 中讀到同一 offset 就反推型別。〔B01、B16–B19、D06〕

### 3.2 descriptor 是 cached owner，不是每 frame 另建的 callback

`597BC0` 先讀 `FE2C5C`，非空直接返回；空值才配置 `0x10` 並呼 `597D20`。descriptor constructor：

| 原件位置 | 已證操作 |
|---|---|
| `597D63` | 寫 descriptor vptr `C1B514` |
| `597D5E`／`597D69` | 要求配置 `0xAC` bytes 的 window |
| `597D7D` | 呼 `6BCE70` 建立 talk instance |
| `597D86` | 保存結果到 descriptor `+C` |
| `597D89` | descriptor `+4=0xD4`，即 resource ID 212 |

RTTI 原件分別是 `FUI::UICachingData<212,FUI::CScenarioTalkBox>` 與 `FUI::CScenarioTalkBox`。`597BC0` 另將 descriptor 與 window 自身 ID 放入既有 cache；descriptor destructor `597CA0` 才清 `FE2C5C`。因此正常 cache 命中時，不會因每次 page 綁定就重新執行 talk constructor。〔B02–B04、B35；D06、RTTI_descriptor、RTTI_talk〕

指定 caller 集合也已分類：`6BCE70` 只有 `597D7D` 這個 E8 候選；`597D20` 只有 `597C0D`；`597BC0` 只有 `596061`。`596010` 的三個 E8 來自共用 ordinary initializer `5A3980`、`CExpeditionPage` 的 `5A65A0`、`CMainPage` 的 `5A7120`；另有 `CBasePage+108` 的 vtable literal。後兩個類型是額外既有 page owner，沒有因此變成新的背景 Lua executor。〔candidate_census；B21、B33–B34；D07–D09；對應 RTTI〕

### 3.3 constructor 登記 namespace；不是內容載入通知

`6BCE70` 在 `6BCEA9` 寫 talk vptr `C3EB44`，並於 `6BCED9` 將 `selected+9C` 清 0。之後 `6BCF0E` push 正式 wrapper `FDF3C8`，`6BCF14` 將 **同一 talk 的 ESI** 放入 EAX，`6BCF16` 呼 `6BDA20`。

`6BDA20` 在 `6BDA2B` 寫 `FE3180=EAX`，在 `6BDA37` 保存 supplied wrapper 到 `FE317C`，建立 `ScenarioTalkTable` 並加入 Rebind，接著由 constructor 的既有五個 registrar 完成 namespace。它沒有接收新的腳本 filename/buffer，也沒有在這條初始化鏈登記 ordinary frame task。既有正式 wrapper、bootstrap 與 core Lua 的初始化順序沿用 S10；不是另一個每個 page 私有的 VM。〔B04–B05；S07、S10〕

因此可以正向成立的是 **普通 page 有合法 talk owner，且該 owner 綁到正式 VM**。不能把這個結果擴大成「新的 `.mef` 已在普通 page 首次執行」；本次 namespace 建立沒有補上本次內容的 producer→load/execute 邊。

## 4. `FE3180` 的完整指定參照集合與 Rebind 真正接受的值

對 `FE3180` 的 raw-backed 三節區 literal 集合共有八處，均已接到真實指令；其中只有三處是 store：

| 指令 VA | 類別 | 原件來源／限制 |
|---|---|---|
| `6BDA2B` | native install writer | 上節 constructor 傳來的 typed talk instance |
| `6BDE2A` | Lua Rebind writer | 必須已在 Lua 內呼叫已註冊的 Rebind；值由 converter 取得 |
| `6BD004` | destructor clear | destructor 的 ESI=0；同時清 wrapper slot 與 Lua namespace |
| `6BDF46`、`6BDFA6`、`6BE006`、`6BE066`、`6BE096` | 五個 marshaller 的 receiver read | 讀 global receiver，不建立物件、不選 record |

〔B05–B08、B26–B30；candidate-contracts.absolute_receiver_references；candidate_census〕

`Rebind` 的 native callback `6BDE20` 先取 `FE317C`，呼 `4A2BB0`，再把結果直接寫入 `FE3180`。converter 把 stack index 設為 `-1`，接受 number tag 3 或可轉數值的 string tag 4，以 x87 `FISTP` 產生整數；其他型別回 0。這裡沒有 typed userdata 檢查、RTTI 驗證、物件配置、owner 註冊或 ordinary pump 設定。亦不能把 `FISTP` 概括為任何浮點環境都朝零截斷。〔B07–B08〕

這項結果是內容契約的重要限制：**不能把 Rebind 暴露為一般內容可任選 owner 的合法 API，更不能以任意地址填入它來宣稱 B 已完成。** 它在因果上還需要既有 Lua 執行，沒有解決首次入口。destructor 的清除同樣不是另一條內容啟動通知，也未提供新排程來源。〔B05–B08、B35〕

這個八處集合只排除了明確 literal 的新 writer；經 computed pointer／另一 alias 的寫入仍須以來源追蹤判定。本文沒有把「三個 absolute store」改寫成全 Client 僅有三種寫入方式。

## 5. 繼承 XML／clone 的新檢查：資料驅動路徑會不會漏寫 selected

### 5.1 完整 inherited reader 的原 receiver 可保持辨識

talk `v+14=748C40` 是繼承的 XML reader。原件 `748C83` 保存 `this` 到 EBX；完整 `748C40..74945D` 內沒有改寫 EBX，直到 epilogue restore。因而以下 direct destinations 的 receiver 有明確依據，不是全程式搜尋 `+9C`：

| 已核對原 receiver 的寫入 | 意義與範圍 |
|---|---|
| `+20`、`+48`、`+28`、`+5C` | base property 值／flags |
| `+1C` | native dock subobject pointer |
| `+68` | base child list count reset |
| `+3C` | attached native graphic 相關清除 |
| 經 `755D10(this+8)` | 固定四個 DWORD，限 `+8/+C/+10/+14` |
| 經 `755D10(this+2C)` | 固定四個 DWORD，限 `+2C/+30/+34/+38` |

完整 direct store 指令與 offset/width 在 `candidate-contracts.json`，可由 verifier 重新從 disassembly 結構比對。這些 direct/helper 寫入均未到 talk `+9C`。〔B09–B10〕

reader 的 virtual edges 也不能不分 receiver：`749019` 的 `+110` 呼叫來自 talk `+18` 的 resource owner；它不是 talk 自己的 `+110`。原 talk 的 `+60/+64` 分別轉 native child/dock factory，`+70` 接 child attachment，`+50` 接 graphic attachment；本包保存選定 slot、forwarding methods 與兩個 attachment body，沒有將 resource-selected child 的全部型別和後續 callback 假裝已窮盡。〔B09、B36–B39；D10–D12〕

最後 `749433` 呼原 talk 的 `+114=6BD4F0`，它以固定四個 child ID 查物件，將返回 pointer 放入 `+80/+84/+88/+8C`。兩個 lookup helper 分別檢查 type code `0xC8`、`0x578`，成功才只寫 caller 提供的單一 pointer slot；本包也保存 helper 完整原件。此處沒有把 XML 整數當 talk record address、沒有寫 `+9C`，也沒有從 XML 字串呼 Lua。〔B20、B31–B32、D03〕

**這次封閉的是原 talk receiver 的上述 direct/helper selected writer 候選。** 未提供原 UI child resource 的動態子圖、計算式 alias、外部模組仍不在這個有限結論內；它們需要新的具體原件／pointer provenance，不以「可能有 callback」當作已存在的解法。

### 5.2 inherited clone 的型別不會保留為 talk

talk 的 `v+28` 實際是繼承方法 `40EB40`。這條路在 `40EB67` 配置 **`0x80` bytes**，呼 base constructor 後，`40EB8B` 明寫 **`C4909C`**；RTTI 是 `FoxUI::FXUIDummy`。這不是 `0xAC` 的 `CScenarioTalkBox`，也沒有呼 `6BCE70`。〔B12、B14；D02；RTTI_dummy〕

隨後 `404DE0` 按欄位複製 base scalars、tree/list 及 `+5C/+60/+70` 等資料，沒有複製 `+9C`；`7456F0` 再複製／安裝 native child、dock、graphic，最後呼 destination 的 `+114`。由於 destination 已定型為 FXUIDummy，不能把這個結尾誤接成新 talk 的 selected writer。原 talk 直接 load 路徑的 `+114` 與此 clone 的 destination 必須分開。〔B11–B15；D02〕

因此「通用 UI clone 能複製整個 talk selected record，然後在普通頁面自然觸發首次 OnEndTalk」這個特定接法，沒有原件支持。單純複製 base UI 狀態既沒有產生本次 Lua 內容，也沒有建立背景 task。

## 6. 新 Master 原件把下一個來源縮小到 `Field.stp`

本輪主線已解析 Master 目錄與完整 packing metadata；此分題只抽取與入口 B 有關的五個有界原件窗口，獨立核對原檔 SHA、XOR 儲存 bytes 與完整選定 record。[master-carrier-evidence.json](master-carrier-evidence.json) 不含完整解包成員。`7135B0 → 715620` 讀 AttachedPackage basename 並形成 `.stp` 路徑的原生契約沿用 S15 §3.1，新增的是現在可以代入原件中的 `Field`／`UI/LUA` 值。

| 窗口 | 原件結果 | 可支持／不可支持 |
|---|---|---|
| M01 | `Master0z/Field/AttachedPackage` 的 body 是 `Field` | 結合本輪主線的 AttachedPackage 消費鏈，指向 `Field.stp`；不是檔內某個 MEF 的 bytes |
| M02 | `Master0z/UI/LUA/AttachedPackage` 的 body 是 `UI/LUA` | 指向獨立 UI/LUA 容器；不是第一個 ordinary caller |
| M03 | PackingRules 首 DWORD 是 897 | 規則列數；不是 MEF 檔案數、callback 數或已完成能力數 |
| M04 | member offset 91,477，完整 39 bytes：package `Field`、source `Field\`、flags `[0,1]`、extensions `xml/mef` 及六個空值 | 正向證實 Field 的 extension slots 含 `mef`；未證實目前容器存在某一 payload，也沒有證明其語法是 Lua |
| M05 | member offset 91,098，完整 59 bytes：package `UI/LUA`，第八個 extension 為 `lua` | 證實另一來源分類；不能直接替代 core loader、callback producer 或 pump 證據 |

M04/M05 依 `u16 length + string` 的兩個字串、兩個 flag bytes、八個 extension 字串解出，嚴格檢查該 row 零剩餘 bytes；flags 只保留原值，不在本分題猜造封裝語意。〔M01–M05〕

這比「沒有找到 `.mef` 字串」前進了一步：**現在有原件宣告的精確來源容器 `Field.stp`。** 下一步應以它的實際 member bytes 接回既有 MapList TRIGGER 與新識別 reader，而不是再掃同一份 binding 名稱。Master 的宣告本身沒有把任何 filename/buffer 傳入 Lua executor，因而本輪不能據此關閉 B，也不能宣稱已還原官方 MEF grammar。

## 7. 精確研究終點及四類交接

### 已結束的有界問題

正常 talk receiver 的建立／cache／page slot／namespace installation、指定 `FE3180` literal writer/read 集合、Rebind 入參轉換、inherited reader 的直接 receiver 寫入、base clone 的實際型別，以及新 Master 的 Field/UI-LUA 宣告，均已由上述原件閉合。這些範圍不應下輪再當成未查題重做。

### B 仍缺哪幾條邊

| 未閉合邊 | 目前具體阻塞 | 能解除的下一份證據 |
|---|---|---|
| 本次 ordinary 內容來源 | Master 指出 `Field.stp`，本讀集仍沒有其被實際選取的 MEF payload／grammar | 該容器原件或可信 member 引用，接到確定 reader 的 byte-level 消費 |
| 第一個合法呼叫者 | 本次 typed UI install 只有 native binding；known talk completion 仍依已開啟對話，既有 open 仍由 Lua 進入 | 一個普通 field/page 的新 producer，含真實 receiver、仍 live 的 filename/buffer/closure 來源、實際 load/execute call |
| 同 VM 的持續 pump | 已知 Q pump 有 busy writer，T pump 有既定 Tutorial／Expedition／review context；本輪 native UI 資料路徑沒有新 resume source | Q inactive 時仍由普通 frame/event owner 持續呼正確 task 的原件鏈，含取消與 generation 的歸屬 |
| 全程普通操作 | 未建立新的完整入口，因而也未能證其 controller、input、camera、page gate 全程保留 | 沿實際新入口逐段核對 side effects／先後；之後才做人測 |

這些不是「需要知道官方 Server 內部怎麼做」的阻塞，也不是用 runtime 測試替代尚未找到的靜態邊。具體 native 候選讀集已查到其結果；無法以目前資料把未提供的 payload、未知 computed writer 或不存在的普通 pump 補成正例。〔本包 B/M 證據；既有排程與輸入反證 S06、S09、S11–S13〕

| 類別 | 可執行交接 |
|---|---|
| **Client 待逆向** | 取得 Master 已指定的 Field 原件；建立 filename/bytes→reader→grammar；追新 typed producer→首次執行→同 VM pump。未知 wire／callback 仍留在這一欄。 |
| **Server 開發需求** | 普通關卡事件、權威進度／實體生命期、instance/generation owner、取消與冪等、結果持久化，均可依已證協定設計開發；需要呈現時使用已有合法有限入口。無須等待還原官方 Server 原始碼。 |
| **跨功能整合** | 內容能力白名單維持 `ordinary_B=false`；資源「宣告路徑」與「實際讀到 bytes」分開驗證；不將原始 pointer Rebind 開放為遊戲內容 API；有限 A 的 owner／清理與背景 B 的 gate 分別驗收。 |
| **待遊玩驗證** | 靜態入口真正成立後，驗證普通輸入、相機、current field/page、取消／重入、持續節奏；此階段不能用來替代上列缺失 caller 或 payload。 |

## 8. 重跑、交付及驗證界線

在 repository 根目錄執行：

```bash
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/entry-b/verify_evidence.py \
  --binary /path/to/02-Tartaros.bin \
  --master /path/to/11-Master.stp \
  --repo /path/to/ttr_anal_multi
```

verifier 只讀原件、Git blob、證據及 manifest，使用 `objdump` 重新取得選定指令，重算來源 hash／VA→raw／window bytes、八組 bounded xref 集合、具體 owner/slot/store 關係、Master selected records 與候選狀態。它不執行目標程式或資源，不下載內容，不修改原檔或 Git。

實際結果保存在 [verification-result.json](verification-result.json)。[artifact-manifest.json](artifact-manifest.json) 保存交付檔的大小與 SHA-256，receipt 與 manifest 自身排除在循環雜湊外。驗證通過的意思是**所列有界證據、來源與明示契約一致**，不是自動授予所有原生分支完整覆蓋、入口 B 可用、Server 已開發或可玩通過。
