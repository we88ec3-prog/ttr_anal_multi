# MEF 完整使用流程續查：交付、首次載入、執行、失敗與清理

> extra/roy1／KR 原件／本輪開始 **2026-11-15 06:07:00 Asia/Taipei**。使用者要求：「請繼續分析完整的.mef使用流程」；沿用同一對話「分析後上 git」授權。
>
> **目前是完整流程的階段性分析，原生新 `.mef` 的端到端使用仍未完成。** 本輪補閉資源限制、checksum consumer、底層 parser／executor 的有限入口集合，以及載入錯誤、回值、重入和清理的具體契約。尚未找到「原版正常流程選中新 `.mef` 並首次執行」的正向 caller；不能將已證通用 Lua 能力直接寫成原生 MEF 功能。

## 1. 本輪進展與開發判斷

**已經能明確寫出每一階段需要什麼、哪裡會失敗，以及哪些內容可以交給 Server 開發；仍不能宣稱放進一個新 `.mef` 後，原版 Client 會自動執行。**

本輪實質新增包括：

- 把普通資源的 checksum virtual call 接回真實 `MD5ChecksumProvider`，確認表的初始化來源、lookup miss／hit 和內容不符的返回結果；補查 fallback／prefix 的 owner alias，避免只看全域 literal。
- 從最底層 parser／reader 與直接 executor 反查，補分類 3 個 parser/reader target、20＋4 個 execute callsites；通用 wrapper 已追到實際 metatable、registry 或 Lua 引數來源。
- 以原件修正偽碼的 `void` 假象：`6F4A50` 真有 **0 成功／1 失敗** 的 EAX；既有 Q／Tutorial caller 卻不依它分流。
- 確認全域 `DoFile` 的 **內層 MULTRET、外層只公開一個數字 status**；不能把 C callback 的「回 1 個 Lua 值」與 Lua 層的失敗值 1 混淆。
- 補選定 Lua 函式的實際 callable 來源、父子工作／skip／重入順序；把 `005F` 換場從 packet receiver 接到舊場景 exit／delete、新 pointer 安裝與 controller 初始化，確認不能拿換場成功保證舊 qco 已取消。舊 MapList root 冷分支與間接 sender 也補到具體物件／vtable，沒有停在第一個間接 call。

對開發的區分是：**既有有限劇情的 Server 排程、內容發布一致性、錯誤／結束狀態管理可以開始；新 MEF 自動入口與完整戰鬥接管仍缺必要 Client 契約。** 新內容橋接的技術設計另列於 §8，與已存在的原生 caller 分開。

## 2. 從 Server 到 Client 的完整流程地圖

「可用的新 `.mef` 路徑或內容」指的是：**某個已經會被執行的 caller，實際持有能讀到正確 bytes 的路徑，或直接持有 pointer＋length，並將它交給對應 loader。** 「新」表示未來要發布的內容；不是要求先取得官方 `.mef`。路徑只有在對應的資源命名空間內可解決，才對該 caller 有意義。

| 階段 | 必須成立的條件 | 已證行為 | 目前界線 |
|---|---|---|---|
| 1. 選定需求與版本 | 要讓 Client 接替哪項操作、使用何種入口及內容版本 | 有既有 Q／Tutorial／Synopsis 的內容執行能力 | 普通戰鬥波次、死亡事件、身分同步不因 Lua 存在而自動齊備 |
| 2. Server 交付檔案 | 相容更新服務、manifest／payload／路徑一致 | 原 launcher 啟動前 FILE→HTTP/gzip→普通檔案寫入鏈可接受新增名稱 | 不等於 Game TCP 能接收任意 script blob；實際更新站仍需部署及驗收 |
| 3. Client 能讀到正確版本 | package 優先順序、prefix／restriction、checksum 與快取條件成立 | `714770` 先查 package，miss 才 fallback；ordinary reader 有本輪閉合的校驗分支 | 磁碟有檔或存在性 probe 非零，不保證後續 open 接受該版本 |
| 4. 正常事件選中內容 | 有 caller 將實際 path／bytes 送入 loader | Q 選 SceneList key 後形成固定 `.seq` 路徑；Tutorial／Synopsis 選固定 Lua 檔 | **MapList 的 `.mef` 名稱查詢與首次載入之間仍缺正向 consumer** |
| 5. Parser 建立程式 | bytes 符合實際 parser，state 有效 | 已證 Lua text／5.1 binary chunk 分流與受保護 parse | 尚未證明官方 `.mef` 另有何種語法；不能按副檔名發明格式 |
| 6. 頂層與前置處理 | 頂層可有限返回、定義／註冊正確、依賴收集完整 | Q 同一 `.seq` 有獨立前置 VM 與正式 VM | prepass 的 wait/yield 是 stub，正式庫不能無條件套用 |
| 7. 正式逐幀執行 | 有效 scene/controller、runner 啟用、pause 等 gate 成立 | global Q pump；Tutorial／Synopsis 各有 tco 更新條件 | Q 啟用會影響 controller 輸入，不是已證透明背景戰鬥服務 |
| 8. 完成、失敗或取消 | 分清正常 return、載入錯誤、resume 錯誤、skip、離場 | 已證特定 End／Stop／remove 路徑；本輪補 caller 忽略載入狀態的反例 | MoCo 內部 resume／wait／移除政策還缺可重驗 body；不能宣稱每一錯誤都會自動清理 |
| 9. Server 接受結果 | 用已證訊息及狀態判斷合法完成、持久化與後續動作 | 特定劇情結束／停止已有原生回報路徑 | 沒有通用「新檔已載入／某波已清怪」ACK；業務規則屬 Server 開發 |

交付能力沿用 [Server 可傳遞時窗](20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md)。選擇器與生命週期沿用 [entry/lifecycle 原稿](20261114-192949-chatgpt-web-roy1-MEF-entry-lifecycle-events.md)。本輪沒有把重列流程當成全部新增發現；每一增量都有下列分題原件證據。

## 3. 誰啟動內容：三條線不能合併

### 3.1 MapList 的 `.mef`：名字有被查，內容尚未被證實載入

前稿已證 `S2C 0012 → 4B24F0 → 4DF510 → 4F7DF0` 依 map ID 查 MapList 的 TRIGGER；返回的是窄字串物件位址，並非直接的 char buffer。已知 `4DF510` 分支丟棄／覆寫該結果，沒有將其作 path 交給 Lua loader。

本輪針對 accessor 返回後保留在 ESI／EDI 的 **MapList root 值**，續追冷初始化、generic sender、字型／controller／音訊等具體 virtual target；這不是將它與 `4F7DF0` 返回的 TRIGGER 字串物件當成同一個值。查驗重點是 root 是否在下游成為新的功能性輸入。沒有將 register 只被 callee-save 保存到 stack 當成 MEF 的語義使用，也沒有把第一次暫時覆寫當成整條鏈已經結束。[本輪 native aliases](MEF-complete-flow-20261115/native-aliases/report.md)

這些候選的已識別正常用途仍沒有提供正向新 MEF reader。保留任意動態 callback／外部模組／計算式 alias 的界線，並不等於它們已被辨識為可供 Server 使用的入口。

### 3.2 Q：原生 caller 選中的是 SceneList 對應 `.seq`

普通 scene entry `561760` 由既有劇情訊息帶入 quest／scene key，查 SceneList 成功後組成：

```text
Event/Sequences/ + 該列的 funcName + .seq
```

它不是直接接受一個 filename 欄位。先到 `55D6A0` 前置收集，再由 `561C7D → 6F4A50` 正式載入。回顧 `565720` 亦用同一表及命名規則。即使底層 parser 不在乎副檔名，**上游固定附加 `.seq` 的事實仍存在**。[既有選擇器與 gates](MEF-entry-lifecycle-events-20261114/entry.md)

### 3.3 Tutorial／Synopsis：固定檔案，再呼固定 global

原生 loader 使用 `Event/TutorialMain.lua`，接著分別呼 `Tutorial_EntryPoint` 或 `Synopsis_EntryPoint`。前稿已閉合 Tutorial scene 與 Expedition page 初始化／特定 UI event 的正常來源。tick、對話回呼、清理等其他命名 wrapper 則主要呼已經存在的 global function，沒有直接把新路徑送入 parser。[前稿觸發者](20261115-001734-chatgpt-web-roy1-MEF-trigger-callers.md)

本輪新增的是：這兩個固定 entrypoint 的 caller **沒有檢查剛才載檔是否成功**；Lua 的入口 body 也沒有自身重複啟動 guard。若錯誤前已有舊定義或部分副作用，不能單靠入口又被呼叫便判斷新內容已成功替換。[本輪載入與失敗處理](MEF-complete-flow-20261115/script-lifecycle/report.md)

## 4. 檔案在哪裡、何時在記憶體

### 4.1 取得內容與判斷可用

本輪把 `714770 → 714030 → 713CC0` 的普通檔案支線接到 `FBA81C=&FE37A0`。constructor 安裝 vtable `C05A8C`；原件 RTTI 證實是 `MD5ChecksumProvider`。`48B730` 從本機 `Integrity.xml` 建立 normalized filename→16-byte digest 表，初始化呼叫受一次性 gate 控制。

`713CC0` 的關鍵條件是 **provider lookup 回 true 才進行 digest 比較**；false 直接接受已開啟的 ordinary file。lookup 有 `.ogg`／`locale` 等既有排除條件，故不能僅以「manifest 有項目」推導一定檢查。真正進入比較時，任一 byte 不符就析構並回 NULL。compressed reader 是另一支線，普通檔案的契約不能直接套過去。[完整資源證據](MEF-complete-flow-20261115/resource-gates/report.md)

額外查出的 `714550` 存在性 probe 回 0/1/2/3，分別為未命中／普通檔案／gzip probe／package。普通檔案只 fopen/close，不做上述 checksum；gzip probe 也不等於完整解壓。因此 **「存在」「能開啟」「能解析」必須分開觀察**。

`FE4C94` restriction byte 與 `FE3648` prefix enable 的已核初值都是 0；本輪新增的 owner／getter 使用集合未找到啟用 setter。沒有已證的 `.mef` 專用保存路徑，也沒有發現 Server 可直接修改這兩個 flag 的介面。不能憑 buffer 位址命名出下載目錄。

### 4.2 記憶體有不同層次

| 保存內容 | 已證位置／機制 | 生命週期與界線 |
|---|---|---|
| MapList TRIGGER 名稱 | root `FB7470+50h` 的容器節點及窄字串物件 | 只是名稱，不是 `.mef` 的完整檔案內容 |
| package 原始成員／解碼內容 | STPD 索引與既有 resource cache | 受 member 載入／引用與 release 條件影響，不因磁碟新檔出現就自動重建索引 |
| ordinary file bytes | StdFile `+8` 的內容 cache，長度在 `+0Ch` | `713F90` 需要時配置並讀整檔；checksum hit 可提早觸發這個讀取 |
| Lua loader 的輸入 copy | `malloc(length+1)`、複製、補 NUL；實際 parse 仍帶 length | 頂層載入／執行返回後釋放該 copy |
| Lua 程式與狀態 | 正式 VM 的 closure／prototype／string／table／coroutine | 依 VM 引用與清理存活；來源 copy 被 free 不等於已定義程式消失 |

所以不能僅回答「MEF 在 RAM」或「MEF 在某個資料夾」。本輪可確定一般檔案、讀取 cache 與執行物件可以同時存在；**沒有證據指出現成 Client 已把 MapList 那個 `.mef` 的內容載進 VM**。[既有 storage](MEF-parser-executor-storage-20261114/storage.md)、[本輪 cache](MEF-complete-flow-20261115/resource-gates/report.md)

## 5. Parser／executor 對內容的真正要求

已證的 Lua parser 以輸入首 byte 分流：`0x1B` 走 binary chunk，其他走 text parser。已核 Lua 5.1 binary header 為 `1b 4c 75 61 51 00 01 04 04 04 08 00`。這是目前已知 loader 的內容契約，不能倒推所有官方 `.mef` 都使用此格式。[parser 原稿](MEF-parser-executor-storage-20261114/parser.md)

本輪從最底層反查：`70E420` text 與 `70D680` binary 的指定 literal 集合都只回到 `6FE860`；`6F70E0` memory reader 的 6 個使用點分別回到 global DoFile、native path loader、memory wrapper、BOM helper、stdin debug 與 loadstring。直接 execute core 的 20＋4 個 caller 亦已按 callable 的來源分類。[本輪 parser／executor 覆蓋](MEF-complete-flow-20261115/parser-executor/report.md)

其中 `__tostring`／metatable／debug hook／sort callback 等確實可到達，但輸入是已存在 VM 的函式值；**executor 不會把普通字串或 map name 自動變成腳本**。需要 bytes 的 parse、需要 compiled closure 的 execute、需要既有 Lua callback 的再呼叫，是不同入口條件。

### `DoFile` 的回值要分兩層

| 呼叫層 | 本輪核實的回值 | 使用方式 |
|---|---|---|
| native `6F4A50` | EAX=0 成功，1 代表開檔／parse／頂層執行失敗 | caller 必須真正檢查，不能信導航偽碼的 `void` 簽名 |
| 全域 `DoFile` 的 Lua 回值 | 一個 **number**：0 或 1 | 檢查 `==0`；在 Lua 中兩個數字都是真值，`if DoFile(path) then` 不能判成功 |
| 全域 `DoFile` 的 C callback 返回 EAX | 1 | 表示對外公開一個 Lua result slot，不是另一個成功／失敗碼 |
| 內層 chunk 的 return values | 內部以 MULTRET 執行，但外層只公開最後壓入的 status | 不能用 `local module=DoFile(path)` 取得 chunk 返回的 table／function |
| `lb.DoFile` 的 Lua 回值 | 也是 number；前稿已證 open fail 與成功都可能為 0 | 0 不足以證明載檔成功，更不是 Server ACK |

若日後選用通用 Lua 路徑製作新內容，頂層須在約定的 global／table 匯出函式或資料，並處理當次版本與舊定義。格式建議仍為不帶 BOM 的相容 Lua 5.1 source；這減少已證入口間的 BOM 差異，不構成官方 MEF grammar 的宣告。[DoFile ABI 與錯誤證據](MEF-complete-flow-20261115/script-lifecycle/report.md)

## 6. 前置 VM、正式 VM 與逐幀工作

正式 wrapper `W=&FDF3C8`，Lua state `L=[W]`；Q manager `M=&FB73C0` 持有 W。前置 state／wrapper 分別在 `FE1EEC / FE1EF0`，是另外建立的 VM。二者不能共享全域表內容或假定有相同 API。

| 階段 | `Register(f)` 的真實行為 | 內容要求 |
|---|---|---|
| 前置收集 | native `55D560` 立即以 protected call 呼 f；72 個初始 stub 與 6 個 per-load bindings，其中 Register 立即執行 | 可有限結束，資源依賴確實被走訪；不能依賴 wait 暫停或未註冊正式庫 |
| 正式啟動 | qbase 建 `coroutine.create(f)`，再交 qco 登記 | 定義正確 entry；初始化不應誤重複建立不可回收的工作 |
| 每幀 | `490FE0 → 561520`；M active、pause、controller 及其他更新條件成立才呼 `f_doCoTask` | 工作只在合法 runner window 前進；不能自行假定固定幀率或 wait 時間單位 |
| 結束／取消 | qbase 把 `Q.EndCutScene` 作 callback 交 MoCo；特定 native Stop／End 會 remove qco | 必須分清 callback 傳入與它何時被 scheduler 呼叫；後者不能只靠函式名猜測 |

已證 Q 啟用路徑會把 controller `+58` 設 1，影響常規 `000A` 控制 row 的移動／動作輸入；因此把 Q 保持 active 來跑無限波次邏輯，不能直接當成不影響戰鬥的方案。[雙 VM／executor](MEF-parser-executor-storage-20261114/executor.md)、[輸入副作用](MEF-entry-lifecycle-events-20261114/controller-input.md)

`DoFile` 又位於 C callback／protected-call 層。Lua 5.1 的已證 yield gate 不保證能跨此 C 邊界暫停。因此對條件式模組設計，安全的靜態契約是：**頂層只建立有限的資料／函式並返回；`DoFile` 返回後，再由已建立的 Lua coroutine 直接呼匯出的工作函式。** 這是由原件呼叫層次推導的內容要求，尚未執行新腳本驗收。

## 7. 失敗、跳過與重入：本輪發現的缺口

### 7.1 不同失敗點的原生行為不同

| 失敗／事件 | 本輪原件結論 | 不可作出的保證 |
|---|---|---|
| normal Q 查無 SceneList row | `561A85 → 561D7F → 561DB0` | 不是一個通用的新內容載入失敗 ACK |
| normal Q 命中 row，但載檔失敗 | active 已在 `5618EF` 設 1；`561C7D` 返回 status 未檢查，之後繼續初始化 | 不能保證立即 End／cancel；也不能反向斷言一定永遠卡住 |
| review Q 查無 row | active 在 `56578B` 先設 1；miss `565926` 直接走 epilogue | 不可套用 normal Q 的 miss-cleanup 保證 |
| review Q 載檔失敗 | `5659D9` 返回 status 未檢查 | 不保證立即清理或自動重試 |
| Tutorial／Synopsis 載檔失敗 | 仍呼固定 global entrypoint | 沒有保證載入失敗便停止；需考慮舊 global 或部分定義 |
| Q tick 呼叫失敗 | `5615D8` 後直接進後續 native actor 遍歷，不依 Lua wrapper status 取消 | 「每幀有 protected call」不等於有自動 recovery |
| tco tick 呼叫失敗 | `4A8BA6` 後未先驗證 wrapper 成功，仍讀 stack 值轉數字寫 owner 狀態 | 不能把 owner 數值 0 一律解釋成正常全部完成 |

以上不能用同一個「失敗」狀態替代。load error、缺少函式、函式內 error、scheduler 自己捕獲 resume error，能到達的 native 分支可能不同。[完整錯誤資料流](MEF-complete-flow-20261115/script-lifecycle/report.md)

### 7.2 內容的清理順序本身也是契約

TutorialMain 兩個入口都把函式值交 `t_executeCoFunction`，自身沒有重入 guard。父工作保存子 handle，再查 alive、檢查 skip 並 yield；Tutorial 的選定取消分支先 `StopCutScene` 再 remove 子 handle，Synopsis 的選定分支則 remove 後走自身 EndSynopsis。這些是一般順序 CALL，不能假定中途失敗也一定執行後續清理。

原生 `Q.EndCutScene=561DB0` 的 normal／review 兩條清理支線，**通過 `M+28` 非零檢查後**才清 active 並呼 `f_removeAllCoroutines`；較大的 `5624B0` Stop 路徑還有其他畫面／物件清理。Tutorial 的離場明確移除 tco，而 ordinary field exit 本身不能等同全域 Lua VM 被銷毀。

**取消一個 scheduler 工作、移除全部 handle、清 native object tracking、還原輸入／相機、Lua GC、Server 接受業務完成，必須分開驗收。** 既有 C2S `003F` 的特定結束路徑也不能直接轉義成「MEF 成功」「全部怪死亡」或「可以發獎勵」。[既有終止流程](MEF-entry-lifecycle-events-20261114/lifecycle.md)、[003F 回報界線](MEF-parser-executor-storage-20261114/executor.md)

### 7.3 `005F` 換場的真正順序

本輪由 packet registration 與 indirect dispatch 證明，**`4B99C0` 是 `005F` handler，`4B7D50` 是共同替換 helper**。receiver 為 `CSceneManager @FD2CF8`，current scene 是 `FD8BA4 = owner+5EAC`；GameInfo mode 另在 `F9392C`。不能將不同 owner 的欄位混在一起。

| 順序 | 原件動作 | 對取消的意義 |
|---|---|---|
| 1 | 更新 GameInfo mode，建立新 field | 新 mode 已寫入時，current scene 仍可能是舊物件 |
| 2 | 舊 scene `v+14` exit | Scenario 為空；Mission 清另一個四容器 owner，其 element callback 尚有動態型別界線 |
| 3 | 舊 scene `v+0` deleting destructor，清舊 pointer | 普通 Scenario／Mission 均到 `4C5940`，只刪 field 本體；不因此清 qco／關 VM |
| 4 | `4B7DA7` 安裝新 field pointer | 不能當作舊 Lua 工作已取消的完成點 |
| 5 | 新 scene `v+10` init，處理 controller 與 UI | controller reset／replacement 在安裝之後；UI `F4355` 是排隊事件，不是同步取消 ACK |

因此，對本輪閉合的「已初始化、舊 Scenario → 新 subtype 2／4」正常替換，安裝前的固定流程沒有必經 Q Stop／End／qco remove。**`005F` 自身不保證安裝前取消舊工作**；這不排除另一封 packet 或已執行的 Lua 工作先做過取消。前稿 `0038` 的 stop→preload 只是該 handler 內的順序，不能推成一定先於另一封 `005F`。Mission collection／controller member 的全部 runtime class、queued UI consumer 與其他 subtype 不在本輪全覆蓋範圍。[完整換場與取消證據](MEF-complete-flow-20261115/scene-cancellation/report.md)

## 8. 如果未來以 Lua 相容內容承載新 MEF，檔案應實作什麼

本節是**具體技術設計推論**，不宣稱已找到原生 MapList MEF caller。現行專案政策仍要求保留 Client 主程式與原資源；本輪只分析內容契約，沒有建立或套用新 `.seq`／`.mef`／SceneList 修改。

### 8.1 可審閱的內容組合

若日後另有獲准且可到達的新內容入口，一個能與已證 loader 相接的設計需要：

| 組件 | 必須負責的工作 | 原件約束 |
|---|---|---|
| 發布清單 | 名稱、版本、長度、digest、套件與普通檔案的對應 | 啟動前發布一致；避免 package 優先命中舊內容與 checksum 表殘留 |
| 啟動橋接 | 由已選中內容傳入確定的 path，驗證 numeric status，挑選當次匯出的函式 | 檔案存在不會自行建立 caller；Q 只自動組 `.seq` 路徑 |
| `.mef` 內容本體 | 相容 Lua 定義、明確匯出、版本身分、有限頂層、狀態及工作函式 | DoFile 不把 chunk return value 公開給外層；不能在頂層假定 yield 可跨 C |
| 前置依賴描述 | 以已證 collector 收集必要物件／動作記錄與音樂；相機、音效等另核資源取得路徑 | per-load bindings 僅已證 CreateObject／AniObject／WalkObject／WarpObject／Register／PlayMusic；獨立 prepass 的 wait/yield stub 不暫停 |
| 正式工作 | 合法 API、可前進／可結束狀態、取消 handle、重入規則 | 正式 coroutine 才承載等待；需要合法 scene/controller/runner |
| 收尾契約 | 正常完成、失敗、skip、中斷各走哪條清理，哪些本地效果須還原 | native caller 不普遍處理 loader status，不能依賴自動 rollback |
| Server 整合 | 使用已證事件啟動、維護業務狀態、驗證合法結果 | 不發明原版 Client 不認識的 opcode／ACK；權威規則由 Server 實作 |

一個條件式的內容橋接順序可以是：選中的 `.seq` 定義受控 `Register` 入口；前置階段只做有限依賴收集；正式 coroutine 才呼全域 `DoFile(<已發布路徑>)`；檢查 status 為 0 及當次匯出身分；在 DoFile 已返回後直接呼工作函式；結束或取消時清理自己的狀態。

這個順序依賴**實際可到達的選擇器與新內容橋接**。原版既有檔案未包含此橋接，就不能把它列成現成入口。若以 `DoFile` 是否存在辨別階段，只能作固定初始化集合下的內容約定；globals 可以被改寫，這不是引擎提供的正式 phase API。[條件式內容契約的原件推導](MEF-complete-flow-20261115/script-lifecycle/report.md)

### 8.2 可以準備的最小範圍

可以先準備有限、可結束的對話／鏡頭／事件 actor 動作內容規格，以及發布服務與 Server 啟動／結束狀態的設計。不能先將無限清怪迴圈、一般怪 AI 接管、任意 live hot reload、斷線恢復或獎勵入帳當作同一個最小功能。

是否真正取代指定 Server 操作，需要在後續獲准測試時停掉該項 Server 操作，確認 Client 仍能完成它；Server 自己繼續代跑波次或畫面續播，不足以驗收 Client 接手。

## 9. 剩餘問題、證據阻塞與 Server 開發需求

### 9.1 Client 待逆向／可取得證據的缺口

| 未解問題 | 已做／可復用的範圍 | 要補的具體證據 |
|---|---|---|
| 新 MEF 首次載入 caller | 既有 MapList getter／root 直接集合、保存 alias、正式 wrapper、底層 parser/execute 及已知 Lua loader 來源 | 正常事件的實際 producer→path/bytes→loader→首次 execute。若有新候選，追其寫入者與 consumer；不重跑相同 literal 清單當進展 |
| MoCo wait／resume／完成 callback／當前 task 移除 | qbase／TutorialBase 的外層介面、本輪 selected Lua body、native tick／失敗處理；S00 已有 Coroutine 13 proto 的 loader-negative 分析 | **Coroutine.lua 13 個 prototype 的原件 bytes 或有可追溯來源的完整解碼**，包含 opcode operands、constants、nested prototype 對應，才能重驗內部政策 |
| 普通戰鬥常駐執行 | ordinary finite Q pump 已證，controller 輸入副作用已證，Tutorial tco 有特定 context | 合法且不干擾普通操作的啟動／更新／取消 owner；不是只找任意 tick |
| 戰鬥事件與物件一致性 | 既有 local creation、native actor state、Tutorial getters 已有分題 | 所選功能的死亡／清組事件來源、local entity 與 Server identity／AI 的實際接合 |
| 所需中斷情境 | 已證 End/Stop、Tutorial exit、指定 handler；本輪新增特定 scene replacement 查驗 | 依要支援的情境逐一指出 cancel 到達與下一次初始化條件，不宣稱所有換場／斷線都相同 |

本輪已核最新 main 的 S00 baseline 仍引用 `anal/SHARED-LUA-LOADING-AND-TUTORIAL-BOUNDARY.md`，但該 carrier 不在本次取得的 repository tree；相關 evidence JSON 也未提供 Coroutine body。現有原件與 T16 Event Lua JSON 不含該獨立檔。**這只限制內部 scheduler 細節的再次核實，不表示 Boot／Coroutine 從未分析，更不是要求先取得官方 MEF。** 已有 Boot／Logic／Coroutine／ai 與 1,843 份 Event loader 的限定舊結果仍復用。

本報告對缺口保持「階段性未完成」；有限候選已分類與資料缺失不是全程式不支援的證明。原件未執行，所以 runtime 的版本、時序與遊玩結果也沒有被偽裝成靜態結論。

### 9.2 Server 開發需求

以下由相容 Server 自行開發、核對或整合，不要求還原官方內部演算法，也不視為 Client 逆向 blocker：

| 玩家／系統情境 | Server 需要提供的工作 | 已證 Client 介面與限制 |
|---|---|---|
| 發布新版本的內容 | 相容更新 HTTP 服務、完整 release、版本／checksum／路徑一致性、失敗回復與啟動順序 | 原 launcher 的普通檔案交付；Client 資源初始化／快取／checksum 契約 |
| 啟動既有有限劇情 | 合法 quest/scene key、context 資料、busy／重入排程與所需回覆 | 既有劇情訊息與 SceneList selector；沒有任意 filename 欄位 |
| 正常結束、跳過、中斷、重試 | 後端狀態機與去重，分清開始／完成／取消，不將異常當成功 | 按已證 native stop／end 與回報語義設計；未證 wire 欄位不能猜補 |
| 戰鬥規則與持久化 | instance／隊伍／任務／權威結果／獎勵政策 | 原生 actor、事件與身分介面仍需滿足；Server 政策不是 Client 原生事實 |
| 驗收 Client 接手 | 記錄被替代的 Server 操作，驗證關閉該操作後 Client 仍能完成 | 不以 Server JSON 引擎、可編譯或腳本 parse 成功替代遊玩驗收 |

跨功能整合包括發布→資源可見→已證 selector→正確 VM→正式工作→清理→既有回報的同一版本測試。待遊玩驗證再分正常、缺檔、語法錯誤、頂層錯誤、工作錯誤、skip、換場與重入；這是後續驗收契約，本輪沒有執行這些案例。

## 10. 工作基準與證據交付

沿用 `extra/roy1`，parent **`67021e609f56e45981aecf45533bdad084039a47`**；main 固定查核基準 **`909754f28bd2e54c8ede00e3a56021cf59facd14`**。已讀指定 `02-PROJECT-SHARED-INSTRUCTIONS.md`，本地來源 SHA-256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43`。同一研究鏈的治理／派工／相關共用與 S00 基準較前次 main 沒有相關內容變動，沒有重設 RR 或搬動 owner。

本輪只新增 `kr-extra-roy` 原稿、有限 evidence 與唯讀 verifier，不新建 branch、不合併 main、不改原始 BIN/STP、原始資源或共用索引。此研究庫保存規格與分析；沒有聲稱已提交 Server 程式實作。

證據分題：

- [資源可見性／限制／checksum](MEF-complete-flow-20261115/resource-gates/report.md)
- [底層 parser／直接 executor 的完整有限集合](MEF-complete-flow-20261115/parser-executor/report.md)
- [載入回值／錯誤／重入／內容契約](MEF-complete-flow-20261115/script-lifecycle/report.md)
- [保存 root alias 的冷分支與間接 target](MEF-complete-flow-20261115/native-aliases/report.md)
- [指定換場景流程的取消到達性](MEF-complete-flow-20261115/scene-cancellation/report.md)

來源的 commit／path／blob／hash、原件 VA/raw/bytes、Lua prototype／operand 與有限候選集合隨包保存。統一重驗方式見 [README](MEF-complete-flow-20261115/README.md)，實際結果見 [verification-result.json](MEF-complete-flow-20261115/verification-result.json)。

**原件與證據重驗通過，只代表這些限定主張可重現；不等於新 MEF 已接通、T01 FULL-PASS、RR ACCEPTED、Server 已完成或已可遊玩。**
