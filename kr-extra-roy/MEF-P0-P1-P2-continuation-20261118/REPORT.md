# MEF P0／P1／P2 本輪分析報告

日期：2026-11-18（Asia/Taipei）。固定 Git 基準 `15d9501c203c6f656461b64f578a50c96e38a5ff`，工作分支 `extra/roy1`。原件為 KR `Tartaros.bin` SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本輪沒有取得不同版本原件，沒有跨版本套用位址。

## 1. 結果

本輪對原計畫八項逐一處置。新原生證據集中在 **P0 資源索引的真實成功條件及實體搜尋順序、P1 普通對話 UI 的具體資源／factory／cache 生命期、P2 一項精確 alias 勘誤**；P2 的 Field 掛載與路由沿用前輪證據，重新整理至官方格式尚缺的 consumer 邊界。已完成的 ABI、演出收尾、Q119 旅程、七族與 world producer 直接採用固定後稿，沒有把同一批 census 或相同字串再次算成新進度。[完成判定](COMPLETION.md)、[復用清單](REUSED-EVIDENCE.md)

三類目標仍未能整體通過：實際素材 winner／payload、普通背景首次腳本入口及同生命期 world→Lua、官方 MEF grammar／executor。本輪都有具體停點與解除條件；沒有把未證全程式可能性改成「不存在」，也沒有把 Server 業務等待化。[補件](SOURCE-REQUEST.md)、[Server 需求](SERVER-REQUIREMENTS.md)

## 2. P0：cache reader、重複鍵與實體掃描

### 2.1 已知來源不等於可選取的內容

前輪 Master 分析已證 899 file members、897 AttachedPackage／PackingRules 對應與父 provider 優先；EMF／ETF 的實際 consumer 和有條件 fallback 也已有原件證據。本輪不重算這些數字，接續會影響實際選取的 `716440` cache reader 與 `798DE0` 初始化分支。[前輪 Master](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/report.md)

### 2.2 `fopen` 成功後的正常返回不是完整 index 驗證

`716440` 以 `rb` 開啟 `fcs.flu`，先讀兩個 little-endian u32 計數，再讀固定 stride 的 group 與 entry 陣列。group stride 為 `0x158`，entry stride 為 `0x218`。它依檔內順序先註冊所有 group，再插入所有 entry；三次 `fread` 的回值不作完整性判斷。[P0 契約](p0-selection/contracts.json)、[原件窗](p0-selection/native-evidence.json)

| 部分 | 本輪可證內容 | 不應推論 |
|---|---|---|
| header | group count、entry count，各 u32 | 沒有證明 magic／version 或 exact whole-file size 檢查 |
| group | 名稱、pattern、directory、recursive flag | 固定物理槽寬不表示原程式會驗證 NUL 位於槽內 |
| entry | group、選定 directory、filename | entry 的 directory 不是自動接在 group directory 後面 |
| 返回 | 開啟後正常走到底回 1；開啟失敗回 0 | 不是對損壞字串、缺 group、配置失敗或例外的成功保證 |
| 初始化 | 非零返回設定 cache 狀態並跳過全部預設 group／全域 scan | 不是「需要的 CHA_ABF／MAP_FLD 已存在」 |

兩個計數均零、且已成功開啟的 8-byte fcs，是有界靜態反例：在 manager 原先為空、配置／CRT 正常完成的條件下，reader 回傳 1 並跳過預設掃描，但沒有建立所需 group。此結論來自原件控制流；離線合成樣本只檢查 inspector 的政策，不是 Client 執行結果。

### 2.3 winner 受原始順序與實體來源限制

group 名稱以原 bytes 比較，重複 group 保留最早定義，不更新其 pattern／directory／recursive。entry 在同一 group 內按正規化 basename 保留首筆；不同 group 的同名 entry 互不競爭。這項 entry 規則沿用舊證，本輪補齊 group definition 與輸入順序的連接。一般 lookup 缺 group／key 不自動重掃。[P0 報告](p0-selection/report.md)

`fcs.flu` 開啟失敗、reader 回 0 時，指定十組預設搜尋走 Win32 `FindFirstFileA / FindNextFileA` 實體目錄，不是 Master 的封裝 member 列舉。recursive 分支先收子目錄名，處理目前目錄符合 pattern 的檔案，再依保存次序深度優先遞迴；本體沒有額外排序。因此同 group 同 basename 跨兄弟目錄的 winner 仍取決於實際列舉順序，除非已另外證明候選唯一。cache 內缺一個 group 或 basename 不觸發這個全域 fallback。

`MAP_PTC` 的選定 consumer 有 stack-local index fallback；不能把這個例外套成所有 group 都會自動補掃。十個預設 group 沒有 Field／`.mef`，也不能據此否定實際 fcs 可能帶入其他 group。

### 2.4 交付工具與剩餘條件

[cache_inspect.py](p0-selection/cache_inspect.py) 只讀本地 bytes，提供有界 ASCII／空 manager 條件下的候選 record 與 literal path。它不開啟 cache 裡的路徑，也不宣稱實際 Client 已選中或載入素材；嚴格 length、NUL、count／ASCII 檢查明示為離線政策。

P0 的算法問題比前輪更完整，實際 `CHA_ABF / MAP_FLD` winner 仍為未知；沒有新 payload 到手，原兩場景 108 筆阻擋前緣與 13 個 descriptor 缺件維持。先取得同版 fcs，或 fcs 開啟失敗時能證明實際選取的目錄／唯一性／列舉資料，再接後續 provider 與 payload。[精確停點](p0-selection/contracts.json)

## 3. P1：ordinary talk 的真實 UI 來源與生命期

### 3.1 receiver 定型更正

前輪已證 Mission／Scenario 安裝 `CScenarioTalkBox` 與 resource ID `0xD4=212`，但 generic helper 的部分 virtual receiver 尚未正確定型。本輪從原 BIN 接到：`596010` 的 EDI 是棧上 `CFXUIBinder@FUI`，其 v+14 取得 caching manager，v+1C 依 resource ID 查 wchar 路徑。resource 212 的確切字串是：

`UI/Component/TalkBox_Scenario_Panel.FTC`

這提供一個真正可要求的檔案，而不是泛稱缺 UI／Lua。Master 宣告的 `UI/Component.stp` 是 provider 候選；仍依父 provider、loose 及實際安裝情境判定所選內容。[P1 報告](p1-entry/report.md)、[Master 摘要](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/master-summary.json)

### 3.2 `talk+18` 在指定載入鏈等於 talk

resource manager `v+28=44E120` 進 XML／`764520` 路線，`7645D1` 明確寫入 `talk+18=talk`。因此舊稿只從欄位名推定「+18 的 owner 不是 talk」需要更正；該指定路徑已證相同 receiver。

type 相符才呼讀取 virtual；其 `+110` custom child factory 最終為 `49AE10` 的 `RET 0xC`，沒有建立子物件。out-child 先被清零，故走通用 native child factory。這關閉一個具體的 custom-factory 候選，不把整個 XML reader 或所有 UI 元件概括成「永不執行腳本」。實際 FTC 沒有提供，選中的 child／layout／後續事件仍需內容證據。[P1 原件](p1-entry/native-evidence.json)、[勘誤](p1-entry/ERRATA.md)

### 3.3 UI cache 取消／重入不能替代 script run 契約

普通 Mission／Scenario 的移出流程，沿 `5AC500 → 599590 → 5A3CC0 → 5960B0`，以 resource 212 到 `4095E0`。先由 talk 所屬 page detach，再從 active manager 移出；正常 descriptor registry 命中分支可跳過 destroy。重入時，manager 直接取 descriptor 的既有 instance 並重新掛接，不重讀 FTC。

這證明了 UI 物件如何保留及復用，也說明不能將「再次顯示對話框」當成「再次載入一份新劇情」。它沒有提供 script run generation、全部 owner cancel ACK 或首次內容 pump。B 還需要 ordinary event→首次 content load／execute→同 VM 後續更新與取消的完整正向鏈。[P1 契約](p1-entry/candidate-contracts.json)

### 3.4 其餘 P1 工作沿用已證資料

Q119 的 5 段 SEQ、176 次 body calls、54 筆對話、7 個 camera members、4 個普通節點與十步旅程保留原固定口徑。七種功能族各一個真例已在前輪完成，不以本輪重新列出而增加數量。[旅程與七族](../MEF-P0-P1-master-continuation-20261117/journey-families/REPORT.md)

world 結果則沿用 0000 比例、0034 HP／SP／MP、000E 視覺記錄、實際 HUD／AI／tick／draw、死亡 FSM 與 erase 分流。未提供真正同 run／actor generation 的 registered Lua endpoint。先前完整 Lua sink 集合已有後稿分類，本輪查到後立即去重，不用一張新的呼叫數表冒充 world bridge 的突破。[world 契約](../MEF-P0-P1-master-continuation-20261117/world-lua/contracts.json)、[去重說明](REUSED-EVIDENCE.md)

## 4. P2：Field 宣告與官方格式的接點

### 4.1 各種已知格式的證據不能互換

| 已知資料 | 真正可證 | 尚未提供 |
|---|---|---|
| Master Field AttachedPackage | 掛載會組合 Field carrier，進 STP 開啟／index 邏輯，成功後安裝 provider | Field 實際存在、指定 `.mef` bytes、內容 parser |
| PackingRules 的 xml／mef slots | 封裝 metadata 中列出副檔名；兩個 flag bytes 語意未指派 | runtime 按這些 slots 選 parser 的正向邊 |
| MapList.TRIGGER | map-keyed owned 字串／檔名參照 | 將這個名字開成 bytes 的首個有效 consumer |
| Lua text／binary parser | 在已證來源中按首 byte 選 text 或 binary，建立 closure 並由已知執行路徑 invoke | 官方 MEF 就是 Lua、或 Server 任意 buffer 可到該 parser |
| Server 外部 schema | 可有自己明確版本的內容定義 | 官方 MEF 相容；此線維持 `NOT_NATIVE_MEF` |

本輪將 Master mount／STP consumer 與既有原生 aliases 的後續閉包一併核對。P0 的實體 group scan、P1 的 FTC 載入屬於具體其他 resource families；沒有把它們誤作 Field／MEF 的 parser。[P2 能力表](p2-format/format-capability.json)

### 4.2 precise partial-register 更正

舊 `literal-tail-4bad73` 與後稿相同支線把 EDI root 保存範圍延伸至後段。原件 `4BADC2` 的 bytes `66 8B 3D EA 90 FB 00` 是 `mov di,[FB90EA]`，已改寫低 16 位。後續 `4BAE70 movsx edx,di` 是數值使用；原資源名另由 EBX 保存並傳遞。

因此只能保留「此前保存」的證明，不能將後段 EDI 繼續當作未改變的 root pointer。這不是 full 32-bit clobber，也不以數值可能碰巧相等推回 alias 身分。勘誤縮短一條錯誤候選；沒有產生官方 MEF consumer。[P2 原件窗](p2-format/native-windows.json)

### 4.3 官方格式的真實停點

目前已核真實 MEF payload 數為 0。header、version、record grammar、官方 parser 位址、executor 位址、首個正常入口及 Server delivery opcode 都保持未定；不填入 Lua 或其他 container 的值。指定候選已分類，並未證明全程式所有函式／計算間接路徑已耗盡。

續析所需最小正證為：真實 Field member 與原 carrier／版本→具體 reference／native 開檔參數→讀入該 bytes 的 parser→命令派送與 state owner。有正例後才製作官方 grammar 的最小接受／拒絕案例。本輪 P2 gate 應保持 BLOCKED。[P2 報告](p2-format/REPORT.md)、[補件](SOURCE-REQUEST.md)

## 5. 驗證、交付與 Server 接續

三個新分題的 verifier 從本機原件重核位址換算、有限 bytes、指令／表／呼叫及固定來源；P0 另用明示合成資料檢查離線 inspector。P2 要求官方格式 ready 的模式預期以 exit 2 表示未滿足。根 verifier 比對來源／交付雜湊、八項狀態、跨包數字及保留條件，實際重跑新分題，不執行任何目標程式。[驗證結果](verification-result.json)

Server 下一步是把已證資料落到內容檢查、run／scene 編排、權威戰鬥與清組、出口、結算與返回、進度／資產保存。與已有 REQ／主線實作去重後採用，不等待未證背景 B 或官方 MEF。實際遊玩保留登入／創角／教學／廣場正流程優先；MEF 旅程接續以 Q119 為目標，返回可操作且持久進度正確，再接 Q120 資格。已暫緩的故障／邊界演練不因本輪研究而重新啟動。[Server 需求](SERVER-REQUIREMENTS.md)、[玩家版進度](PLAYER-PROGRESS.md)
