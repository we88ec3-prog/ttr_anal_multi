# 指定 Lua 函式名的 native caller：是否能繞過檔名 loader 啟動新 MEF

## 結論

本分題補查的是前稿「檔名 → Lua loader」之外的另一種可能入口：**native 先按名稱呼某個已存在的 Lua 函式，該函式再載新檔**。已將本輪三種 execution wrapper 的直接 caller 及其函式名／參數來源閉合。

在有界讀集中，native 傳入的名字是固定的 Tutorial／Synopsis 入口、qco／tco 更新與清理、對話旗標 callback，或 `g_CharExplain.GetExplain`。沒有由這些 callsite 將 Server 的字串欄位當成 `DoFile`／`load` 函式名，也沒有將 MapList TRIGGER 字串當成函式名或檔案參數。這是原件 caller 的資料流結果；不是僅以「名稱看起來不像 MEF」判定。

這些 wrapper 本身確有呼叫 Lua 的能力。**函式已存在於 VM，與新檔被讀入 VM，是不同事件。** 前兩輪已證 Lua VM、protected execution 和正式 state 的部分沿用；本輪新增的是不同 native execution wrapper 的 name／argument source，以及與原始 qbase callback body 的銜接。

## 原件與來源

- 原 BIN：12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32 i386 ImageBase `00400000`。
- 本輪固定 Git 導航 commit：`e66dadaa721671919cbbeb228ae3f26ad990c9e3`；工作分支 parent：`0a2503db089a4867cff5ef8bf6d7689333f12fd1`。
- 本題原件：24 個 code windows、3,056 bytes；13 個名稱字串。VA/raw/完整 hex/SHA-256 與反組譯保存於整合證據包的 named-calls 群組。視窗間重疊保留，不算唯一覆蓋率。
- 20 個既有反編譯來源保存 commit/path/Git blob/SHA-256，僅作導航。其 byte 身分已核；關鍵主張由原 BIN 確認。
- 只讀取／反組譯原件，沒有執行 Client、Lua、讀入的腳本或其原生 API。

## 1. 三種 wrapper 的功能並不等於三種檔案載入器

| Wrapper | 原件行為 | 本題確認的限制 |
|---|---|---|
| `6F4DD0` | 從參數取得函式名，intern 字串後查 Lua globals；確認 TValue type=6，依格式字串推參數，再將 `6F5A50` 作為 callback 交給 `6FE770` 的受保護呼叫框架 | 這裡沒有 open/read/parse 新檔。函式名與格式由 caller 決定；下列已核 caller 使用正式 Lua wrapper。 |
| `6F4F40` | 對既有 table 取指定 method；正常函式分支推 table 作 self，再推格式參數；亦保留 metamethod 處理分支 | 需要已存在的 table/function。不能因內部可間接呼函式而推定 Server 能指定任意方法名。 |
| `4AD0A0 → 6F5A70` | `4AD0AB` 取 `[ebp+0x10]` 的名稱；`4AD0AE` 使用 globals index `FFFFD8EE`，`4AD0B3 → 6F5680` 查名稱；確認函式後 `4AD0EF` push 0 個引數，`4AD0F3` 受保護執行 | 第二參數是 wanted-results；它不是從 Server 收到的任意 payload 長度。實際呼叫為零引數。 |

`6F4CD0` 的格式處理在本輪原件另核：`%d`／`%f` 產生 Lua number，`%s`／`%w` 產生字串，`%w` 先做字元轉換。**某 wrapper 支援字串參數，不代表這次 caller 有提供檔案路徑**；以下須逐一看 caller 使用的格式與來源。

`6F5A50` 是執行 callback，並非 parser 或 error handler。其 execution-thunk 語義由前稿 `parser.md` 閉合，本輪復用；`6FE770` 負責受保護地呼叫傳入的 callback。

## 2. `6F4DD0` 的三個直接 caller 全是固定零引數函式

| 原件 callsite | 呼叫者 | 名稱所在原 VA／內容 | 引數來源與觸發含意 |
|---|---|---|---|
| `4A8A46` | `4A89C0` | `C06894 = Synopsis_EntryPoint` | 前方 `4A8A31` push 固定 `Event/TutorialMain.lua`，`4A8A36 → 6F4A50` 已載入；再 push NULL format、0 wanted-results、固定 entry 名稱。Synopsis 的正常 UI 上游另見本輪入口分題。 |
| `4A8B74` | `4A8A60` | `C068A8 = Tutorial_EntryPoint` | 前方 `4A8B5F` 同樣給固定 TutorialMain 路徑，`4A8B64` 載入；name 不是 MapID 或來包字串。 |
| `5615D8` | `561520` | `C106A0 = f_doCoTask` | name 與 NULL format 都是立即常數；已有 Q active/pause/controller 前置，逐幀推進現有 coroutine。 |

新建立的是這個 named-call target 的 caller／參數讀集。Tutorial／Q 的既有 loader、frame pump 與生命週期結論本身沿用前稿，不以此次再取 bytes 冒稱又找到新的 MEF 啟動器。

## 3. table method 的兩個 caller 都是角色說明查詢

`6F4F40` 的直接呼叫在 `673034` 和 `6BF7E5`。兩側原件各自完成同一組操作：

1. `672FDF`／`6BF78E` 取固定 `C3591C = g_CharExplain`，`6F5680` 查 globals；TValue type 必須為 table（5）。
2. `67302A`／`6BF7DB` push 固定 `C3592C = GetExplain`。
3. `673023`／`6BF7D4` push `C0D6DC = %d`；提供的是 local slot 中的整數，wanted-results=1。
4. wrapper 呼 table method，後續將回傳值作文字使用；本題不把完整 UI 顯示／角色資料重列為新增研究。

沒有可供 Server 直接填寫的 method name、檔名字串或腳本 bytes 參數。Lua 端 `g_CharExplain` 的來源與既有 UI/Table 載入鏈引用前稿與 main baseline；本題沒有修改那些資源或假設可遠端替換其函式定義。

## 4. 零引數 callback 的十一個 callsite

`6F5A70` 的唯一 E8 caller 是 `4AD0F3`，因此進一步追 `4AD0A0` 的 name 來源。以下十一處全部以固定字串提供函式名：

| Callsite | 名稱 | 原字串 VA | 本題分類 |
|---|---|---|---|
| `47B71C` | `t_removeAllCoroutines` | `C068BC` | Tutorial／review UI 取消，wanted-results=0 |
| `4A8BA6` | `t_doCoTask` | `C068D4` | Tutorial runner 更新，wanted-results=1 |
| `4C1A1F` | `t_removeAllCoroutines` | `C068BC` | Expedition 特定更新支線清理 |
| `4C20B6` | `t_removeAllCoroutines` | `C068BC` | Expedition 清理支線 |
| `4C4DC2` | `t_removeAllCoroutines` | `C068BC` | Tutorial leave |
| `561E42` | `f_removeAllCoroutines` | `C106EC` | Q review 結束分支 |
| `561F8A` | `CheckConfirmMessage` | `C10344` | Q 正常結束分支取一個結果 |
| `56202D` | `f_removeAllCoroutines` | `C106EC` | Q 正常結束分支 |
| `5B9742` | `OnYesTriggered` | `C0DD40` | 已有 UI callback 的 Lua 全域呼叫 |
| `5C3672` | `OnYesTriggered` | `C0DD40` | 另一 UI callback 的同名 Lua 呼叫 |
| `6BD7BC` | `OnEndTalk` | `C102AC` | 對話結束支線的 Lua 全域呼叫 |

上表的 name 來源是在每個 callsite 的實際 push／register 資料流確認；不是從反編譯顯示的推定 prototype 猜參數個數。以 `47B71C`、`4C20B6` 為例，偽碼漏列後兩個參數，但原件仍可見名稱 push、零值與 wrapper 指標。

三個對話 callback 的 Lua body 已由同輪腳本分題回核 Event.stp 原件：

- `OnYesTriggered`：qbase root 的 CLOSURE／SETGLOBAL 綁到 prototype 5；body 將 `TRUE` 寫入 `g_yesTriggered` 後返回。
- `OnEndTalk`：prototype 9 將 `FALSE` 寫入 `g_scenePlaying` 後返回。
- `CheckConfirmMessage`：prototype 19 讀 yes/no flags，以比較／跳躍／常數返回 0 或 1；沒有 CALL 或 TAILCALL。

原件 prototype 與 binding 操作數見本輪腳本分題，這補上 **native UI／結束事件 → Lua 旗標函式** 的真實語意。它不是檔案載入通知；並且結論限定所核 qbase 定義，未將 runtime 全域永不被改寫當作前提已證。

`CheckConfirmMessage` 的 state 來源亦有原件橋接：caller `561F84` 先呼 `49B230`，其 `49B27E` 明確 `mov eax,0xFDF3C8`，經 epilogue 返回；`561F8A` 把這個 wrapper 交給 `4AD0A0`。因此這個 callback 不是另猜一個獨立 VM，而是前稿與 qbase 綁定使用的正式 wrapper。

## 5. 搜尋範圍與可重驗資料

本題不是再做舊 `6F4A50` 15 個路徑 loader 的清冊，也不是重掃 `.mef` 名稱。指定的新 native target 是：

- `6F4DD0`：3 個 E8 候選；
- `6F4F40`：2 個 E8 候選；
- `6F5A70`：1 個 E8 候選；
- `4AD0A0`：11 個 E8 候選。

各候選均由原指令 call 編碼與 containing function 內的參數設定重新核對。Containing function 名稱由固定 bulk 路徑索引導航，call target 則由原件 `E8 rel32` 算出。

另外針對這四個入口核 `.text` 的 E9 及 `.text/.rdata/.data` 的 literal absolute pointer，均無候選。此範圍不包含計算式間接位址、外部模組、任意常數算術或全域 table 在執行期被未知程式替換；因此不宣稱對整個 Client 的形式化無路徑證明。

`call-wrapper-candidates.json`、`callback-wrapper-candidates.json`、`wrapper-address-taken-and-tail.json` 保存候選範圍；整合後的唯讀驗證器會對同一原 BIN 重算。原件窗口保存逐指令反組譯，capture 時已確認 byte 覆蓋連續、無截斷或 `(bad)`。

## 6. 對使用者問題的影響

這一輪可以進一步說明：**既有 native 按名稱呼 Lua 的機制，尚未提供從正常 Server 訊息指定 `DoFile(new_path)` 的接線。** 在本題 caller 中，沒有被保留到 wrapper 的可變函式名／檔名來源；已有 callback body 也未接到新檔 loader。

Server 可依既有玩法流程使用合法 scene／UI／對話結果契約；不能因這些 wrapper 接受 `char *name`，便新增一個任意名字或任意 Lua bytes 的自訂訊息，並宣稱原版 Client 會處理。新內容入口仍需實際可達、資源可見、內容相容的 source→loader 證據。

本題的陰性結果已收斂到具體 caller 與參數，後續只有出現新的實際 consumer／註冊／外部模組資料流，才值得擴展；不需要再次重跑這份相同清冊。
