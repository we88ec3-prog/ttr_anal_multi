# P2：原生 MEF 格式、真正讀取者與目前能閉合的界線

日期：2026-11-18（Asia/Taipei）。工作分支：`extra/roy1`。固定來源基準：`15d9501c203c6f656461b64f578a50c96e38a5ff`。原件、Client、Lua、Server 均未執行或修改；未建立分支、未變更正式 RR／T01／S00 狀態。Git 提交由整合者處理。

## 1. 結論及玩家能理解的進度

**P2 的現有證據已逐項整理到明確終點，原生 MEF 格式目標仍是「尚未完成／受阻」。** 現在知道應優先取得 `Field.stp`，知道一般資源怎樣掛載、怎樣被查找，也知道已辨認的 Lua 腳本怎樣解析與執行。但仍沒有一份可核身分的真正 MEF 檔案，以及「遊戲選到這份檔案 → 讀到它的內容 → 交給哪個解譯器」的正向連線。不能把這個狀態寫成原生 MEF 已完成或已可玩。[格式與能力判定](format-capability.json)

用玩家的語言說：**已找到劇本可能放在哪個資源包，也已看懂現有 Lua 劇情播放器；還沒有拿到原生 MEF 劇本，不能保證這兩者就是同一套格式。** `Master.stp` 是能實際讀到的原件，這項缺件已經解除；下一項缺的是它宣告的 Field 資源內容，不是再要一次 Master。

| P2 問題 | 現在的進度 | 還缺什麼 |
|---|---|---|
| MEF 可能裝在哪裡 | `Field → Field.stp` 宣告及 `xml/mef` 規則已證；通用掛載函式已核 | Field 實際載體及 member |
| 地圖表裡的劇本名稱放在哪裡 | 已證是依 map ID 保存的自有字串 | 名稱第一次變成被讀取檔案的 caller |
| 現有 Lua 能否解析、執行 | 已有可復用的原件鏈，文字／bytecode、closure、VM 及 callback 邊界清楚 | 不能據此認定真正 MEF 就是 Lua |
| 原生 MEF 格式與指令 | **尚未完成／受阻** | 真正樣本、實際 parser、executor、版本與拒絕規則 |
| Server 能否開始做劇情與地圖規則 | 已證 Client 介面涵蓋的部分可繼續開發 | Server 的狀態、條件、持久化、取消與結果整合；這些不是等待官方 Server 原始碼的理由 |
| 玩家實際能不能玩完整 MEF 流程 | 本輪沒有執行遊玩驗收 | 原件、入口、Server 整合完成後的另行驗收 |

本稿不提供猜測百分比：`有證據的機制`、`仍缺的原生格式`、`Server 待開發`、`待遊玩驗證` 是不同狀態，不能用一個平均數掩蓋缺口。

## 2. 這次真正新增與明確復用的內容

### 2.1 新增的是可核對的勘誤及完整判定表

1. 更正舊 MapList root alias 生命期說明：`4BADC2` 已局部覆寫 `DI`，不能把其後整段 EDI 都當成未變動的 `FB7470`。原件與精確限制見第 5 節。
2. 將 Field 的「封裝宣告 → 通用掛載／資源查找」與「內容 → 格式 parser／executor」分開列成八項有界判定，並列三項真正尚未閉合的證據需求。[format-capability.json](format-capability.json)
3. 交付可重跑的原件／來源檢查與獨立的原生 MEF 完成 gate。來源重驗成功仍會保留 `native_mef_gate=BLOCKED`，要求 MEF 完成時回傳 2，避免把驗證器 PASS 誤用成遊戲功能完成。

### 2.2 後稿已經處理的冷分支，不能再次算新發現

本輪先接到 `MEF-trigger-callers-20261115/native-root` 的未解描述；查到更後的 `MEF-complete-flow-20261115/native-aliases` 後，已完整閱讀該後稿並去重。world 冷初始化、font virtual method、固定 sender、音訊資源清理的具體 receiver／vtable／register 覆寫鏈，都已由後稿完成指定範圍的補證。本輪對其中幾個前綴的原件重核屬**復用查核**，不增加新完成項。[舊未解描述](../../MEF-trigger-callers-20261115/native-root/report.md)、[後續已閉合範圍](../../MEF-complete-flow-20261115/native-aliases/report.md)

同樣不重算：155 個 root literal、32 個 getter caller、165 個 initializer 候選、16 個 `4F7DF0` 直接 callsite、既有 Event 全體內容掃描、Lua parser／reader 使用點及 `6FE550/6FE1C0` 的 20／4 個執行 callsite。它們都有先前的實際分類。本輪沒有拿相同字串或相同函式再次命中當成新入口。[既有 storage](../../MEF-parser-executor-storage-20261114/storage.md)、[既有 parser/executor 集合](../../MEF-complete-flow-20261115/parser-executor/report.md)、[實際腳本 consumer](../../MEF-trigger-callers-20261115/script-consumers/report.md)

## 3. Field 宣告究竟接到哪裡

### 3.1 已取得的原件與規則

`11-Master.stp` 為 1,094,887 bytes，SHA-256 `f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d`。前稿已完整走訪 899 個 file members、897 個 AttachedPackage 與 897 筆 PackingRules，不能重新把它列為未讀原件。[Master 完整分析](../../MEF-P0-P1-master-continuation-20261117/master-resource-closure/report.md)

本輪只重驗與 P2 直接有關的兩筆有界 PackingRules 記錄及兩個 binding 身分；不輸出完整解包 member。

| 宣告 | 原件位置／判定 | 能證明的內容 |
|---|---|---|
| `Master0z/Field/AttachedPackage` | 原件 raw `DC010`，5 bytes；本包只保存身分 hash | 對應 carrier basename 為 Field |
| Field PackingRules | member offset 91,477；原件 raw `F6D65`；39 bytes | package Field、source directory `Field\`、未命名 flags `[0,1]`、slots `xml/mef` 及六個空值 |
| `Master0z/UI/LUA/AttachedPackage` | 原件 raw `DA410`，6 bytes；本包只保存身分 hash | 獨立 carrier basename 為 UI/LUA |
| UI/LUA PackingRules | member offset 91,098；原件 raw `F6BEA`；59 bytes | 八個 slots 為 `ftc/fft/fcs/fis/fsd/etf/obj/lua` |

兩個 flags 仍為 `UNASSIGNED`，不猜成壓縮、加密或遞迴選項。Field 的 `mef` slot 是封裝 metadata，不是已取得一個 `.mef` payload。[master-rule-evidence.json](master-rule-evidence.json)

### 3.2 掛載函式沒有補出 MEF 格式分派

本輪在同一 BIN 上重核以下完整函式／有界窗口，位址、原 bytes 與指令均在 [native-windows.json](native-windows.json)，閱讀版在 [native-windows.asm](native-windows.asm)。這是對已知掛載機制的 Field 專題整理，不冒稱新還原一套 loader。

| 連線 | 原件落點 | 精確終點 |
|---|---|---|
| Master 進掛載遍歷 | `713740 → 7135B0` | 指定名稱檢查及 EncSetting 查找後走目錄；原件缺 EncSetting 時沿既有 default=1，不把 EncFlag=5 代入 |
| 分辨目錄節點 | `71360D cmp eax,1`；`713610 jne 71370E` | 非該目錄 kind 直接移往 sibling；不是把遇到的任意檔案當腳本執行 |
| 登記／重用虛擬目錄 | `713626 → 714D50` | 建立可供查找的 namespace 節點 |
| 讀 carrier 名稱 | `713632 push C44158="AttachedPackage"`；`713639 call edx` | 複製 property bytes 到 basename buffer，不是讀 Field 內的某個 MEF |
| 嘗試打開 carrier | `7136BA` 把 basename buffer 交 EDX；`7136C9 → 715620` | `7156FE/71570D` append `.stp`；`715787/7158F7 → 714770` 是一般資源開檔 |
| 安裝 provider | `7136CE test eax,eax`；成功才 `7136D2 mov [ebx+100],edi` | 宣告存在與載體成功打開是不同條件 |
| 子目錄 | `713706 → 7135B0` | 繼續相同掛載契約 |
| 日後請求某個 resource | `714770 → 713910`，既有路徑查找包含 `714C50/7155B0` | package 優先；父 provider 先查，miss 才走子目錄／既有 fallback；返回資源物件仍不等於 parser 已接受內容 |

`715620` 在這條鏈上處理的是 STP 容器開啟、標頭與索引載入。`7135B0` 查的是 AttachedPackage，不消費 Field PackingRules 的 `xml/mef` slots 來選擇某個 MEF executor。這個結論限定於表列掛載鏈；**沒有宣稱 PackingRules 在整個 Client 或其他工具中絕無其他 consumer**。[原件窗口 `MOUNT_WALK/MASTER_INIT/STP_OPEN/MOUNT_LOOKUP/RESOURCE_OPEN/MEMBER_LOOKUP`](native-windows.json)

因此目前正向鏈的終點是：**如果 Field carrier 存在且開啟成功，資源系統有地方可以尋找 caller 指定的 member。** 仍缺「誰指定哪一個 Field member、讀出的 bytes 交給哪個 parser」。只要這個接點沒證明，通用開檔支援就不能改寫為原生 MEF 支援。

### 3.3 同輪相鄰 consumer 對 P2 的影響

P0 分題已把正常初始化 fallback 的十個 group 接到具體副檔名；其中沒有 Field／mef，`718FB0` 是實體檔案系統的 FindFirstFile/FindNextFile 掃描。fcs 又可以載入其他 group，所以這個十筆集合不能用來否定所有其他來源。[同輪 P0](../p0-selection/)

P1 分題把普通 talk 的 resource 212 接到 `UI/Component/TalkBox_Scenario_Panel.FTC` 與 XML/UI reader，並定位 owner 的 custom-child factory。這是確實有型別的 UI consumer；不能因為它位於普通頁面或含 script callback 就改稱 Field／MEF loader。[同輪 P1](../p1-entry/)

這兩項在本稿是同輪交叉引用；其原始 bytes、驗證結果與最後檔案身分由各自交付及主線總 manifest 負責。本稿的 26 個固定 Git pins 都是已存在於 `15d9501…` 的來源，沒有替尚未 commit 的同輪檔案虛構 Git blob。

## 4. MapList 的 `trigger` 是檔名，不是已載入的劇本

既有完整鏈是 `4F5640` 讀 `Table/_MapList.xml` 的 `trigger` → `4F7DF0` 依 map ID 取得／建立節點 → `403040` 深拷貝至 `node+10` 的窄字串。容器位於 `FB7470+50`，head 是 `+54`。字串有 inline／heap 容量、長度與自己的生命週期；XML 與區域字串釋放後，名稱仍可保留。[storage.md](../../MEF-parser-executor-storage-20261114/storage.md)、本輪重核 [`TRIGGER_STORAGE`](native-windows.json)

因此記憶體中能看見 `scenario_town000.mef` 這類名稱，只代表引用名稱的資料已讀取；不能推出該 MEF 內容已載入、內容只存在 RAM、或某個 MEF executor 已啟動。這個名稱並未帶來原生格式規格。

前稿 `4DF58D → 4F7DF0` 的返回值沒有成為 filename 輸入：既有初始化分支與後續覆寫都已核過。MapList root 的其他 member 又各有自己的 consumer，例如 `+E0` 的資源名稱與音訊處理、`+A0` DamageSound；它們不能因共用 `FB7470` 就被歸成 `+50` trigger。[root caller 報告](../../MEF-trigger-callers-20261115/native-root/report.md)、[具體 virtual target 續追](../../MEF-complete-flow-20261115/native-aliases/report.md)

這個被檢查過的候選集合沒有提供首載 MEF 的正例。有限 literal／direct-call／特定 owner writer 的分類不等於任意計算式 alias、所有例外 callback 或外部模組都已全局排除；但也不能把這些一般可能性當成已存在的 MEF 支援。

## 5. 精確勘誤：`4BADC2` 已改寫低 16 位

受影響舊說法在兩處：

- `MEF-trigger-callers-20261115/native-root/report.md` 的 `4BAD73` 長 caller 保存範圍。
- `MEF-complete-flow-20261115/native-aliases/report.md` §6.4，仍以 `4BAEAD/4BAEB4` 換固定字串位址作為原 root 的最後位置。

本輪沒有覆寫歷史原稿；對這個細節追加原件更正：

| VA | 原 bytes | 原件含義 |
|---|---|---|
| `4BAD73` | `BF 70 74 FB 00` | EDI 初值為 `FB7470` |
| `4BAD78` | `E8 03 C1 03 00` | 呼叫既有 `4F6E80` |
| `4BAD84` | `8B D8` | 返回的資源名稱保存在 EBX |
| `4BADC2` | `66 8B 3D EA 90 FB 00` | `mov di,word ptr [FB90EA]`，覆寫 EDI 的低 16 位 |
| `4BAE70` | `0F BF D7` | 將該 DI 以有號數延伸到 EDX，進後續數值處理 |
| `4BAE92/4BAE9D` | `53`／`E8 8E EC 21 00` | 推入 EBX 的資源名稱，再呼叫既有 `6D9B30` |

**正確說法是「從 `4BADC2` 起，未變動 root 指標的資料來源追蹤已中斷」。** 這是 partial write，不是把整個 EDI 清零；高 16 位仍保留。若讀入的 low word 偶然等於舊 low word，數值甚至可能相等，因此不能把此指令描述為對所有值皆成立的指標不相等證明。後續 `movsx edx,di` 使用的是設定來源的低 word，EBX 才承載這條路徑的資源名稱。[`ALIAS_PARTIAL_WRITE/ALIAS_NUMERIC_USE`](native-windows.json)

這個勘誤縮短了應當視為「未變動 root alias」的範圍，沒有產生 MEF loader，也不改變已辨認音訊 consumer 的結論。驗證器同時把兩個新窗口的起點與每條指令接回舊完整 caller window，避免僅由任意 offset 開始反組譯得到假指令邊界。

## 6. 哪些格式已證明，哪些仍不能命名

| 證據 | 可以採用的分類 | 不能提升成什麼 |
|---|---|---|
| Master 的外層 STPD 與一般 STP loader | 容器及 member namespace | 內部原生 MEF 格式 |
| 897 筆 PackingRules 與其中 Field row | 本檔實際觀測到的封裝 metadata | 封裝工具全部規格、MEF records 或 MEF opcode |
| MapList `trigger` 字串 | 檔名／引用資料的保存機制 | 已載入的 MEF buffer 或 executor state |
| `6FE860` 看首 byte，`1B` 分至 `70D680`，否則 `70E420` | 已識別 Lua binary／text 解析鏈 | MEF 專用 parser |
| `1B 4C 75 61 51 00 01 04 04 04 08 00` | 此 BIN 期待的 12-byte Lua 5.1 header | 官方 MEF header；header 本身也不證明 Lua patch version |
| Lua loader → closure → protected execute／coroutine | 已知 Lua 內容的執行機制 | Server 任意 bytes 可以進入同一 reader，或任意 `.mef` 可正常啟動 |
| Server 自訂劇情 schema | 必須標記 `NOT_NATIVE_MEF` 的獨立內容設計 | 原生 MEF 還原完成 |

Lua 的格式與記憶體生命期可以直接復用；不需要因為本輪缺少某個散檔而再把已分析 Boot／Logic／Coroutine 等列為未知。已知 `.seq`／`.lua` 樣本的正常入口也有自己的正證。但把 Lua 檔改副檔名為 `.mef`，最多驗證「同一 Lua parser 不依副檔名分流」，不能反過來證明原生 MEF 就是 Lua。[parser.md](../../MEF-parser-executor-storage-20261114/parser.md)、[executor.md](../../MEF-parser-executor-storage-20261114/executor.md)、[完整 reader／execute 集合](../../MEF-complete-flow-20261115/parser-executor/report.md)

## 7. 精確未閉合接點及解除方法

### 7.1 Client 原件與逆向需求

| ID | 未解問題 | 已走到的終點及不能再代推的原因 | 具體補件／下一步 |
|---|---|---|---|
| P2-B01 | 哪個真實 member 是本版本原生 MEF？ | Master 只有 carrier／metadata，沒有這些 MEF bytes；引用字串不能透露檔頭、版本或 record 邊界 | `Field.stp` 完整原件；或真實 `.mef` 加原 carrier、member path、長度、hash、版本來源 |
| P2-B02 | 哪個 producer 把該名稱／內容交給哪個 reader，誰首次執行？ | 已查 MapList 保存、具體 root alias、Lua reader/sink 集合，仍未得到一條正向 MEF bytes 來源鏈 | 保留 Field 同目錄 XML／設定參照與 map/trigger 身分；從 exact member/ref 回接 reader 實參、parser、owner、首次 execute |
| P2-B03 | 原生 MEF 的消費欄位、拒絕條件、狀態及 dispatch 語義是什麼？ | STP、PackingRules、Lua 各有另一個已證用途；不能拿其中任一個代填 MEF grammar | 在 B01/B02 綁定後，逐項還原實際消費欄位、版本、錯誤分支及 executor，建立對應的有界正例與拒絕例 |

若來源是另一 Client 版本，須同時取得對應 BIN／EXE 並重新固定映射，不能沿用本稿 `9741d197…` 的 VA。取得 Field 只解除 B01 的材料缺口，不會自動讓 B02/B03 通過。

上述停止點是**尚缺真實內容與其原生 consumer 綁定**，不是等待官方 Server 的內部演算法，也不是籠統的「沒有 runtime 所以停止」。本稿也沒有聲稱全 Client 靜態分析已被窮盡。任意未辨認 computed callback 不能取代具體檔案來源與接點；本輪不再把已有後稿閉合的候選重開成未解清單。

### 7.2 Server 開發需求與整合需求

Server 仍可沿已確認的 Client 介面開發內容選擇、玩家／任務／地圖資格、場次識別、取消、結果對帳與持久化；版本清單要保留 BIN、Master、carrier／member hash 與實際選取證據。這些是相容 Server 自己要提供的規則，無須還原官方 Server 內部實作。本稿不另建正式需求台帳；整合由既有 S00 收件／REQ 流程處理。

真正尚缺的 Client parser／wire 不能移交成「Server 補送即可」。目前沒有新增 MEF 傳送 opcode、原生接收欄位、確認訊息或成功執行 ACK；不能任意編造。如果先採 Server 自訂內容格式，應保持獨立 schema、副檔名與 `NOT_NATIVE_MEF` 身分。

跨功能還需要兩條連線：P0 的實際選檔／資源 ready 接到該真實 member；P1 的真實首次入口接到正確 VM／scheduler。原生掛載宣告、頁面存在、callback 可用、Lua parser 可讀內容，各自都不能替代這兩條連線。

## 8. 重驗、交付與驗證界線

```bash
python -B kr-extra-roy/MEF-P0-P1-P2-continuation-20261118/p2-format/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --master /path/to/11-Master.stp \
  --repo /path/to/ttr_anal_multi
```

正常來源檢查回傳 0；另加 `--require-native-mef` 時，現況應回傳 **2**。兩次實跑分別保存於 [verification-result.json](verification-result.json) 與 [native-mef-gate-result.json](native-mef-gate-result.json)。

本包核對：11 個 native windows、3,911 bytes、1,227 條指令、3 個字串、13 個精確指令 anchor、10 個 direct call edges、兩筆共 98 bytes 的 PackingRules、兩個 AttachedPackage 身分、26 個固定 Git source pins。窗口末端以額外 15 bytes 解碼後檢查，兩個勘誤窗口另接回舊 caller 的連續指令表。原件與 source pins 相符，功能 gate 仍受阻。

驗證器只讀原件及 Git objects，關閉 lazy fetch，不執行目標、不輸出完整解碼 member。其 PASS 是位址／bytes／來源與宣告狀態一致，**不是整份語義自動證明、T01 FULL-PASS、RR 接受、Server 完工或遊玩通過**。

| 交付 | 用途 |
|---|---|
| [format-capability.json](format-capability.json) | P2 八項鏈判定、三項 blocker、格式與能力邊界、Server 及整合需求 |
| [source-manifest.json](source-manifest.json) | 原件身分、固定 commit/path/blob/hash、實際讀取深度 |
| [master-rule-evidence.json](master-rule-evidence.json) | Field/UI-LUA 有界規則與 binding 身分；沒有完整 member |
| [native-windows.json](native-windows.json)、[native-windows.asm](native-windows.asm) | 原件證據與可閱讀指令 |
| [verify_evidence.py](verify_evidence.py) | 唯讀重驗與 fail-closed 原生 MEF gate |
| [artifact-manifest.json](artifact-manifest.json) | 本子包檔案完整性清單 |

建議下一步優先取得 **Field 原件及其版本資訊**，再以實際 member 反追 consumer；現有 Server 已知介面的工作可以並行。不要以重新掃相同字串、重新查已閉合 cold helper、或自行設計另一種格式代替原生 MEF 完成。
