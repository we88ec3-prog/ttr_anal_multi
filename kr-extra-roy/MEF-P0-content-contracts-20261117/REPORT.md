# 三項 P0 的分析結果

## 1. 問題、範圍與證據

本輪目的，是把上一批規劃中「ABI／勘誤採用、內容真實依賴、執行與收尾」三個共用前提分析到可交付 Server 開發的程度。研究沿 `extra/roy1` 的既有精確成果接續，必要處回到同一 KR BIN 與原資源驗證；沒有用全量重掃取代缺邊補證，也沒有另認領正式 RR。

原 BIN 的 SHA-256 是 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原始 Event／Table／BoundMap、既有 Base 與 W1/W2/W3 載體逐一固定身份；公開研究來源固定至 Git commit、blob、SHA-256、byte length。治理讀取以 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 為準。完整範圍見 [根來源 manifest](source-manifest.json) 及三個子包的 manifest。

## 2. P0-ABI：從 binding 名稱進到可採用的呼叫規則

### 2.1 完整表與兩種使用目的

本輪將既有 **121 個正常 binding** 的 native、marshaller、參數數量、型別與 producer 分類保留，加入內容採用規則。四個 stub 不可當作功能；`lb.GetObjectCount` 沒有新的 count producer，不能因名稱就被內容條件式視為物件數。17 個 number producer 包含 16 個 query 與 `lb.DoFile`，也不因此成為成功 ACK；大寫全域 `DoFile` 是另一個入口，不能交換。[採用 catalog](abi-adoption/adoption-catalog.json)

前輪 15 項公開勘誤全部採用，followup 的 3 項已去重，涵蓋 FlyingObject、歷史 SYN／parser pin、Doll lease 與實際 Q immediate caller。原歷史稿及其驗證狀態保留，採用動作可逐項追溯。[errata-adoption.json](abi-adoption/errata-adoption.json)

新內容 preflight 是有版本的作者政策：拒絕錯誤 arity、未知欄位、非法數值範圍、bool／number 混用、錯誤結果用途與未證能力。**它不執行 Lua，也不宣稱可接受所有原生 Lua 程式。** 原內容審讀另保存 helper 的真實轉換與原生相容行為，避免以一套新規則反推舊內容必定壞掉。[preflight](abi-adoption/preflight.py)、[原始內容審讀](abi-adoption/original-call-review.json)

### 2.2 Boot 與 helper 的關鍵轉換

本輪在已存在的精確 Git 證據中找回原始 `Boot.lua`、`Logic.lua`、`Coroutine.lua`。Boot 的原 bytecode 寫入 **number 1 的 TRUE 與 number 0 的 FALSE**，不是 Lua boolean。對這些原件而言，先前僅依附件名稱搜尋而產生的缺檔疑慮已解除；實際安裝版本選取仍需另綁。適用前提是指定載入鏈成功且之後未覆寫 global。[bootstrap-global-contract.json](abi-adoption/bootstrap-global-contract.json)

`CreateObject` 的 helper 會把第 6 參數 action 0 改為 1，並比較第 7 參數是否為 **number 0**：相等才轉成 native show integer 1；boolean false 與 nil 並不相等。這條鏈是數值比較及 integer marshalling，不能錯寫為 `lua_toboolean`。`WalkObject` 的七個 helper 參數只形成六個 native 參數，direction 未轉交，action -1 另轉為 4。完整規則及來源在 [helper-adoption-rules.json](abi-adoption/helper-adoption-rules.json)。

75 個 qbase helper 的名稱分析使用保守的控制流合併：只有各到達分支都保留同一已知 callee 才定名；有不同定義或 kill 就回到 UNKNOWN。這關閉了只看文字次序或最近 GETTABLE 會誤判呼叫目標的風險。SYN 只驗分析器對構型的處理，不冒稱原 Lua 執行結果。[helper-call-audit.json](abi-adoption/helper-call-audit.json)、[分析器](abi-adoption/analyze_original.py)

### 2.3 原始零參數 EndSepia 已追到實際 native 參數

`RevPhase1` 的原始 `Q.EndSepia()` 確實少於 binding 宣告的一個參數。分析沒有停在「arity 不符」：在原 C closure、正常 frame／allocator、無改寫 hook 的條件下，`CALL B=1` 令 `L.top=callee+16`；marshaller 的 index -1 讀到 callee function，tag 6 進入非 number／string 的 default 分支，**傳出 native integer 0**。`565600` 因而設定 state 4 並寫入零參數。

這是特定原件 call frame 的有界推導，不能泛化成所有缺參數都等於 nil；也沒有證明視覺效果同一時刻就完成。新內容仍要求顯式的一個 integer。[zeroarg-endsepia-contract.json](abi-adoption/zeroarg-endsepia-contract.json)

## 3. P0-RESOURCES：完整原場景與真正選檔規則

### 3.1 覆蓋範圍

| 選定原場景 | 函式主體呼叫 | Create／Q slot | 不同模型 | 相機 | 對話列 |
|---|---:|---:|---:|---:|---:|
| Q119/3，Phindous_YuriandRazed_Boss | 46 | 3 | 1 | 1 | 5 |
| Q2440/5，Aisen_01_After | 62 | 14 | 14 | 7 | 7 |

兩個獨立靜態解析流程核對全部 **108 次呼叫的順序、名稱、行號與 arity**，不是只摘取圖片或尾段。限定 parser 會消費完整所選函式與 Register；對未支援的分支、別名、運算式或尾隨語句拒絕處理。完整內容圖含模型／action、camera、map／BND、對話文字、顯示角色、portrait、voice、music、sound、圖片和 Prolog。[scene-dependencies.json](content-dependencies/scene-dependencies.json)

Q2440/5 的 Prolog 19 有 10 個 dialog、36 行文字、7 張不同圖片；加上直接 FlyingObject 共 8 張不同 DDS。文字保留 hash 與來源，不複製完整故事。相機與對話表的原件存在不會自動證明其周邊圖片、音訊或當前 runtime 選檔可用。

### 3.2 本輪補到的原生缺邊

模型正常建立會在 materialized resource 可用時請求 action 1 與 4，所以依賴不可只取 prepass 見到的 action。除了 9 個顯式附件，15 個不同模型還會分別嘗試 `(modelLowWord + 31000) & 65535` 的 default item 查詢。**查詢嘗試不等於附件必須存在**；native 可 miss 與完整外觀可用是不同問題。[資源報告](content-dependencies/report.md)

Walk 也有兩個階段：預掃描暫綁的原生 collector 對任意負 action 改為 4；正式 qbase P26 只將 number -1 改為 4。兩個實際 consumer 的規則分別保存，不能用正式 helper 規則覆蓋 prepass，或把預掃描結果當所有作者參數都保證與正式執行一致。

附件入口已接到 `Character/Cha/Items.ipk` 以及 Include／ItemList／EffectList 解析。地圖 reader 與模型／texture 路徑也已接到實際 parser／request。真正 mount 來自 `Master.stp` 的 `Master0z` 與 `AttachedPackage`，所以 Base 內 `Mon/...abf` 的候選不能直接改寫成 `Character/Mon/...abf` 當作已選路徑。

| 層次 | 重複項的原生規則 | 採用影響 |
|---|---|---|
| Actor.ID → FILE | 後續 admitted row 覆寫；PRE 不參與 Q model key | 不以 world PRE 硬選 Q 模型 |
| CHA_ABF／MAP_FLD 的正規化 basename entry | 既有 entry 優先，新重複 entry 釋放 | 不能沿用 Actor 的後寫覆寫規則 |
| Master directory → AttachedPackage | 後續成功 binding 可取代前一 provider | 必須保留實際 mount／provider 及成功條件 |

Q2440 的 `town014S.fld` 沒有 exact same-stem 的 MapList row；鄰近的 `town014` 不能代替其 BND／map identity。Q119 的 world Cluster 與演出 Q slot 也分別保留 namespace。

### 3.3 分析完成與原件缺口

已找到並解析的選定 descriptor 是 `Mon/02_Stoncken.abf` 與 `Mon/00_Alphonso.abf`；其他 13 個選定模型缺 descriptor。Base 的 830 筆 index 並不表示 830 個 descriptor 都已解析。缺 descriptor 時，不可能誠實列出其全部 texture／animation／effect／avatar 遞迴後代；目前的 dependency graph 表示已到達的依賴與明確前緣，沒有填造後代。[精確缺件](content-dependencies/dependency-frontier.json)

此外仍缺實際 CHA_ABF／MAP_FLD entry、Master mount、Items.ipk、portrait／voice／image／audio／geometry 等所選 bytes。本輪可證的是「完整審讀所選原場景、追到現有資料可達的邊及選取規則」，**尚不能證完整遞迴 payload 或 exact runtime selection**。`ready=false` 與 `BLOCKED_MISSING_ORIGINAL_SOURCE` 保留。材料、搜索界線及解除方法見 [SOURCE-REQUEST.md](SOURCE-REQUEST.md)。

## 4. P0-LIFECYCLE：持有、退出與真正完成時點

### 4.1 模型釋放及 pending producer 分類

原件已接通 `Q.DeleteAllObject → actor.v+14 → D+8.v+8 → 7A57C0`。已 apply 的 state 1 Doll 先排 instance／parts 釋放，清 instance、重設 state 0 並置 dirty，再由 actor destructor 放下強引用；因此 destructor 不再透過同一 state 1 路徑重複排這份 release。secondary receiver 的偏移須先換回 D，不能混用兩套基址。[生命期報告](execution-lifecycle/report.md)

正常 Q.Create 的實際 caller 使用 **immediate 1**，正常返回前 apply。兩個選定原場景的初次 Create 不能被說成必然留下 deferred state 2；一般延後 request、old-D callback 與工作結果仍各有適用 producer。另一方面，release worker 的完成仍晚於排程，level-job signal 也不能代表所有引擎佇列清空。

### 4.2 原圖片的零 fade-out 分支

Q2440/5 的 FlyingObject 使用 fade-in 100、hold 100、fade-out 0、holdForever 0。constructor 將 fade-out 同值寫入 total 與 remaining。phase 4 在除法之前先測 remaining：零值直接跳往 alpha 0／phase 0，**繞過以 total 為除數的路徑**。下一個符合條件的 update 才將 alive 清零，後續 manager 再 release／delete／erase。

因此原參數的零 fade-out 不等於必然除零，也不等於函式返回時已釋放。這是正常配置／初始化返回、owner 與合格 update 前提下的狀態轉移；texture 可見性另驗，缺 texture 不等於生命期必定不前進。alive 清零後由同次 manager 迭代續作 release／delete／erase，但不能換算成固定 wall-clock 完成保證。另沿用已更正的 FlyingObject 替換語意：新圖先取消 Q 追蹤的前圖，再建立下一張；實體釋放由 manager 續行。[圖片契約](execution-lifecycle/selected-image-contract.json)、[run-contracts.json](execution-lifecycle/run-contracts.json)

### 4.3 音樂、清理順序與三種策略

`SetFinalMusic("")` 走 append，追加零 bytes 而保留舊值；accepted Start 走另一個 assign helper 清空。兩者不能當同一 clear。原場景以 CameraWorks.Stop、DeleteAllObject、RestoreMap、RevPhase1 收尾；native active Stop 則可先 RestoreMap 再 DeleteAll。清理圖因此保留條件式偏序，不造一條所有出口必須相同的總序。[cleanup-order.json](execution-lifecycle/cleanup-order.json)

原 `RevPhase1` 會呼 EndSepia／EndSlowMotion，即使本 scene 未先取得這兩項效果；這是回復預定正常基準的既有內容政策，並非把所有共享旗標 snapshot 回任意舊值。新內容套用清理節點時仍須有 owner 權限或已知基準，不能據此替另一個 owner 清除狀態。

22 類 owner 分開記取得、持有、更新、終止、排釋放及觀察出口。有限效果、同 run 多 phase、獨立 run 的入口與前後置條件分別列明。`End`、qco removal、003F、level-job 或已過若干時間都不能當作所有 owner 的共同完成 ACK。[owner-ledger.json](execution-lifecycle/owner-ledger.json)、[策略契約](execution-lifecycle/run-contracts.json)

## 5. 對目前 Server 的具體影響

已重算目前主線候選與外部關卡的四份 JSON，保留其重建政策與版本。Q119 末圖入場 scene 是 **119/3**，清場是 **119/4**，返回是 **119/5**；本次 119/3 分析不可冒充全部旅程。world 的 Cluster／model 與 Q slot／model 不是可直接互換的 ID。[現行 Server 對照](integration/README.md)

外部 scenario schema 的四個對象層級禁止未聲明欄位，目前事件與 action 集合沒有任意 PlayScene／Lua API。本包應由既有 REQ-0019／REQ-0021 工作線去重採用，經有版本的接口擴充或相容工具接入。需要的工作是內容審查、實際資源選取、run owner 排程、原回覆與業務結果分離；這些列為 **Server 開發需求**，不要求猜還原官方 Server 內部規則。[SERVER-ADOPTION.md](SERVER-ADOPTION.md)

## 6. 驗證及完成界線

根驗證器交叉核對 121 binding、兩個 SEQ 的完整呼叫、Boot／helper 轉換、22 owner／三策略、來源與檔案身份、明確的 P0 狀態，以及四套證據工具的新結果。工具 PASS 不會把缺檔欄位寫成 ready，亦不提升 T01 FULL-PASS、RR 接受、S00 規格或遊玩狀態。[VALIDATION.md](VALIDATION.md)

所有本輪靜態可閉合的特例都已進一步查到底；確實需要原件的前緣留具體材料清單。普通場景首次入口 B、world 結果到 Lua 的新出口與官方 MEF grammar 仍沿上一批 P1／P2 工作另行接續，不冒稱被本次三項 P0 一併完成。
