# 檔案交付之後：資源選取、鬆散檔案限制與 checksum 的真實契約

> 本輪新增定向原件分析。基準 `02-Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。偽碼只導航；下列返回值、receiver、vtable 與分支以原件為準。所有原件唯讀，未啟動 Client、執行 Lua 或修改資源。

## 1. 先回答「什麼叫可用的檔案」

**下載成功、資源查找有命中、實際 open 成功、內容通過 parser，是四個不同條件。** 本輪補上前稿未閉合的限制旗標來源與普通檔案 checksum consumer，沒有把檔案層的成功當成新 MEF 已有啟動 caller。

前稿已證 `714770` 先查 package，miss 才進 fallback。本輪沿用這個順序，補出：

| 層級 | 本輪精確結果 | 對新內容的意義 |
|---|---|---|
| 普通檔案路徑 | `714030 → 713CC0` 走 filename/mode 的 `_fopen`，成功後可能另驗 checksum | 磁碟存在不等於實際 reader 接受 |
| fallback 限制 | `FE4C94` 初建為 0；限定 direct references 與 accessor aliases 未找到設成 1 的正常設定 caller | 不再將「可能另有 setter」當成已知的必要外部開關；也不宣稱所有計算式 alias 永遠不會改它 |
| 額外 prefix | `FE3648` 初建為 0，`FE3548` 清空；限定 getter caller 只讀出 prefix 拼接 | 沒有已證的 `.mef` 專屬目錄或可由 Server 設定的 prefix 介面 |
| checksum receiver | `FBA81C=&FE37A0`；vtable `C05A8C`，`+0=48B9C0`、`+8=48BB80` | 實際 provider 與方法已閉合，不能只留一個未知 virtual call |
| lookup miss | provider 回 AL=0，`713D76` 直接走接受檔案的 `713DB0` | 查無項目不是這條 StdFile 路徑的強制拒絕條件 |
| lookup hit | provider 未排除、實際 lookup 回 true，預期 16 bytes 與實際 digest 不同 → 析構並回 NULL | 符合此分支的內容必須與載入時的表一致 |
| 存在性 probe | `714550` 回 0/1/2/3，只做 package／gzip／普通檔案可見性探測 | 非零結果不能作為 checksum、parser 或執行成功證據 |

上述 checksum 契約限定於 **`713CC0` 的 StdFile 支線**。`714030` 也有獨立的 compressed-file 支線；不能將普通檔案的檢查、失敗碼或快取配置直接套到所有 reader。

## 2. fallback 限制與 owner alias 已追到哪裡

### 2.1 `FE4C94`：不是只有查 literal 就下結論

`7142D0` 建立 owner `P=&FE4C7C`，配置兩個 0x24-byte sentinel，形成空的雙向 list。重要欄位是：

| Owner offset | Global | 已證用途 |
|---|---|---|
| `+0` | `FE4C7C` | extension list 的 head |
| `+4` | `FE4C80` | 該 list 計數，初建 0 |
| `+0x0C` | `FE4C88` | path-prefix list 的 head |
| `+0x10` | `FE4C8C` | 該 list 計數，初建 0 |
| `+0x18` | `FE4C94` | fallback restriction byte，初建 0 |

原件 `7142F6 xor ebx,ebx`，`714348 mov [FE4C94],bl`。`71434E` 與 getter `7142AE` 返回 `&FE4C7C`，因此本輪另外查這些返回指標的 consumer，沒有因全域 literal 只有三個命中就假定沒有間接 setter。

限定 `.text` E8/E9 與 raw-backed `.text/.rdata/.data` absolute pointer 候選：

| Target | 已核直接 callsites | 返回值的實際使用 |
|---|---|---|
| `714260` getter | `714614`、`714840` | 都立即 push EAX，交 `714470` 讀 prefix list |
| `7142D0` constructor | `71429C`、`7145BA`、`7145EF`、`7147C4`、`714817` | lazy initialization；回傳後沒有以 owner 寫入 `+0x18` 的動作 |
| `713FF0` prefix getter | `714661` | `714666..71468E` 計長、複製到局部字串，再 append 輸入路徑 |

這三個 target 的 E9 與 literal function-pointer 集合皆空。資料 owner `FE4C7C` 的 9 個 literal、`FE4C88` 的 4 個 literal 亦納入；額外命中是 `BD0760` 的 atexit 清理。它呼 `552640` 清節點後 free head，並非填入允許項目的設定者。`552640` 清空 head 的 next/prev、計數及每個字串節點，原件已保存。

`7143B0` 先取 extension、略過開頭 `.`，與原件 `C44294="stp"` 比較；其餘情況走 owner 第一個 list。`714470` 複製 filename、將反斜線轉為 `/`，用第二個 list 的每項長度做不分大小寫 prefix 比較。這是路徑／副檔名條件，沒有 `.mef` parser、網路 payload 或新內容選擇的行為。

**限定結論：已核的初始化及 accessor/owner 直接使用中，沒有啟用限制或填入新允許名單的 caller。** 這比前稿只說「其他設定者未窮盡」更精確；仍不涵蓋任意整數運算重建地址、未取得模組、記憶體損毀或 runtime 外部寫入。

### 2.2 `FE3648` 與 `FE3548`：一般 prefix，不是 MEF 位置

`713FF0`、`714030`、`714550` 的 lazy initialization 都把 `FE3648` 設 0，並清空 `FE3548` 的 0x100-byte buffer。`FE3648` 的 6 個 literal 命中都是這些初始化或判斷；`FE3548` 的 7 個命中都是清空、返回或讀取 prefix。

`714030` 在旗標非零時依次嘗試 `prefix + callerPath` 的 compressed／ordinary reader；未取得物件則再試原來的 callerPath。旗標為零直接試 callerPath。它沒有在這裡建立路徑、下載檔案或列舉 `.mef`。

因此，不能從 buffer 名稱推導 `Event/MEF/`、暫存下載目錄或 executable directory。實際相對檔案位置仍受 caller 提供的名稱與程序的工作目錄影響；本輪沒有取得指定執行個體的 working directory 證據。

## 3. `FBA81C` 的實際物件與方法

原件 `48BD6B → 48B2E0` 以 `FE6994 & 1` 控制一次初始化。constructor 寫入：

```asm
48B311  mov dword ptr [FE37A0], C05A8C
48B362  call 48B730
48BDCA  mov eax, FE37A0
48BDD5  mov [FBA818], eax
48BDDA  mov [FBA81C], eax
```

`C05A88 → C69568` 的 RTTI Complete Object Locator，type descriptor `F7DD54`，名稱在 `F7DD5C`，原件為 `.?AUMD5ChecksumProvider@@`。所以此類別名稱有原件依據，並非本稿憑功能命名。vtable 前三個 DWORD 為：

| Slot | Target | 本輪使用範圍 |
|---|---|---|
| `+0` | `48B9C0` | 以 filename 查預期 digest，回 AL 狀態 |
| `+4` | `48BB60` | 不在本次 StdFile consumer 的呼叫鏈，未展開語義 |
| `+8` | `48BB80` | 以 pointer、length、output 計算 16-byte digest |

`FBA81C` 限定 literal 集合只有 4 個：上述唯一直接指派，以及 `713D49 / 713D78 / 713D91` 三個 load。原件 `48BB80` 的參數與初始值、`809BA0` 第一輪的常數 `D76AA478` 和 rotate 7 同時保存，與 RTTI 共同支持 MD5 身分；沒有把任何 16-byte 值一概稱為 MD5。

這裡的 provider 是 Client 本機檔案完整性檢查，沒有把它稱為下載器，也沒有把 `FBA818` 的其他使用者與 `FBA81C` 混成同一個 reader 契約。

## 4. checksum 表從哪裡來、何時建立

`48B730` 使用原件路徑 `C05640="Integrity.xml"`，經 `714770(path,"rb")` 開啟，以內容 pointer 和 length 交 XML reader `499340`。成功才從 `PATCH` 及第一層 `FOLDER` 開始，呼 `48B380` 建表。失敗分支沒有填入這些記錄；本稿不假設目標機器上 manifest 的實際內容或存在狀況。

`48B380` 的 FILE 部分：

1. 取 `name` 與 `Checksum` 屬性；缺值則略過。
2. `48B459 cmp eax,20h` 要求 checksum 字串長度為 32。
3. `.stp` 有獨立略過條件，不能把這個表視為所有套件內容的統一清單。
4. 將 folder prefix 與 file name 拼接，再經 `48B8C0` 將 `\` 轉為 `/`、逐字元 `_tolower`。
5. `48B510..48B526` 逐兩個字元經 `49B1B0` 轉成一個 byte，共 16 bytes，與 normalized key 一起插入 provider `+8` 的樹。
6. 子 `FOLDER.name` 以 `parent + name + "/"` 遞迴，原件 self-call 在 `48B673`。

`49B1B0` 接受十進位字元與大小寫 A–F。非 hex nibble 對應 0；這不是完整格式嚴格驗證，發布端仍應產生正確 32-character hex。此處僅說明原生轉換，不建議依賴它的寬鬆行為。

補查初始化 target 後：`48B2E0` 唯一 E8 caller 為 `48BD6B`；`48B730` 唯一 E8 caller 為 `48B362`；`48B380` 的兩個 E8 為 `48B861` 與自身遞迴 `48B673`。三者 E9／literal function-pointer 集合皆空。

**因此，已核的正常初始化路徑把表建成程序內的持續物件；沒有在每一次開檔前重新讀 Integrity.xml。** 僅替換磁碟 manifest 不能推導目前程序已刷新表。這是支持「內容與清單應在啟動前一致交付」的另一項原生依據；有限 target 集合不構成全程式不存在其他計算式更新的證明。

## 5. StdFile 的成功與拒絕條件

`713CC0` 以 ECX 接 filename、stack 接 mode。新物件 0x10 bytes：vtable、FILE pointer、content cache pointer、length；實際 vtable 是 `C44204`。

| 位移 | 初始／後續值 |
|---|---|
| `+0` | `C44204` |
| `+4` | `_fopen` 結果 |
| `+8` | 0，之後可能為整個內容的 cache pointer |
| `+0x0C` | 由 seek/tell 得到檔案長度 |

開檔失敗的 `713D0E..713D26` 析構並回 EAX=0。成功時，先記錄長度並 seek 回 0，再做以下原件流程：

```text
provider == NULL                     → 回傳 StdFile
provider.lookup(filename, expected)  → AL == 0：回傳 StdFile
                                    → AL != 0：取內容與長度，計算 actual
expected[0..15] == actual[0..15]      → 回傳 StdFile
任一 byte 不等                       → 析構 StdFile，回傳 NULL
```

關鍵原件如下：

```asm
713D49  mov ecx,[FBA81C]
713D67  mov eax,[eax]          ; vtable +0
713D6C  push edx               ; expected buffer
713D6D  push edi               ; caller filename
713D72  call eax
713D74  test al,al
713D76  je 713DB0              ; lookup false：接受物件
713D8F  call eax               ; StdFile v+38 → 713F90，回 content pointer
713D97  mov edx,[edi+8]        ; provider +8 → 48BB80
713D9A  push eax               ; pointer；length/out 已在 stack
713D9B  call edx
713DA4  cmp cl,[ebp+eax-24h]
713DA8  jne 713DC3             ; 任一 digest byte 不同
713DAB  cmp eax,10h
713DAE  jl 713DA0
713DB1  mov eax,esi            ; success = file object
713DCB  call eax               ; mismatch：析構
713DD4  xor eax,eax            ; failure = NULL
```

lookup `48B9C0` 自己也呼 `48B8C0` 正規化 key，再查 provider 的樹。找到資料節點時把 `node+28h..+34h` 四個 DWORD 複製到輸出，`48BB1D mov al,1`。沒有節點時將輸出清零，`48BB3F xor al,al`。另有原生 `.ogg`／`locale` 排除條件；這不是新 MEF 的特別允許分支。

**未被 provider 排除且 lookup 回 true 的普通內容必須符合預期 digest；lookup 回 false 則這個 consumer 不做該次 digest 比較。** `.ogg`／`locale` 的排除判斷在查樹之前，因此只有「manifest 有表項」仍不足以保證走比較支線。這只是原生行為，不是授權停用校驗或修改原資源。相容 Server 的發布工作仍應使 manifest、檔案與版本一致。

## 6. 檔案 bytes 是否一直留在記憶體

本輪補核 `StdFile v+38=713F90`：當 `file+8==0`，它保存目前 offset、seek 到 0、按 `file+0C` 配置 buffer、透過 `v+10` 讀入、恢復 offset，將 pointer 存入 `file+8`；後續同物件讀取直接回該 pointer。

因此「磁碟檔案」與「記憶體內容」可以同時存在。checksum hit 時，在 loader 取得 bytes 前就可能因 checksum 需要而把整個 ordinary file 讀進記憶體。這不是 `.mef` 專屬記憶體儲存，也不是 Server payload 的接收 buffer。

前稿已證遊戲 Lua loader 再複製 bytes、以長度餵 parser、頂層執行後釋放自己的 copy；Lua closure、字串、table 等 VM 物件各依引用存活。package member 又有自己的快取／索引生命週期。這三種記憶體不可統稱「Client 把 `.mef` 放在 RAM」，也不能推導換掉磁碟檔就會替換目前已建立的 Lua objects。[既有 parser／記憶體完整證據](../../MEF-parser-executor-storage-20261114/parser.md)

## 7. 只做存在性檢查仍不足

原件 `714550` 對 package 命中回 **3**（`714596`），gzip probe 命中回 **2**（`7146DD`），ordinary `_fopen("rb")` 成功後 close、回 **1**（`714712 / 714747`），沒有命中回 **0**（`71474E`）。這些分支沒有經 `713CC0` 的 checksum 比較。

故某個呼叫者若只使用此 probe 的非零結果，也只能知道候選資源可見；仍不能知道後續 `713CC0` 是否接受、Lua 是否 parse 成功或 scene 是否結束。本稿沒有宣稱該 probe 就是 MEF entry，它在此用於閉合旗標／prefix getter 的 consumer。

## 8. 對 Server 發布與流程設計的要求

以下為 **Server 開發需求／跨功能整合要求**，不冒稱原版 Server 的內部實作：

- 同一 release 的普通內容與 `Integrity.xml` 須一致，在已證的初始化順序前完成交付；發布端記錄正規化後的檔名、長度、checksum 及版本。
- 先決定實際 caller 會請求的名稱，再核 package 優先命中與快取，不能只檢查某個磁碟位置有新檔。
- 區分下載落地、資源可見、實際 open、parse、頂層執行、正式協程與業務完成。既有 wire 未提供的 ACK 不可由 Server 自行假定 Client 會回。
- 未被 provider 排除且 lookup 回 true 的 ordinary file，digest 不符時後續會收到 NULL；要與本輪腳本失敗分支一起處理，不可只依既有入口仍被呼叫便視為載入成功。
- 既有 Client 主程式與原資源保持不變。本稿沒有實際交付新檔、更新清單或啟用 prefix；內容橋接提案與原生 caller 的證據分開。

## 9. 覆蓋、界線與重驗

完整有限集合見 [candidate-sets.json](candidate-sets.json)，39 筆原件紀錄、6,369 bytes（包含 22 個 code windows、字串、vtable 與 RTTI），見 [native-windows.json](native-windows.json) 與 [native-windows.asm](native-windows.asm)。20 個 navigation source 已核對 main `909754f28bd2e54c8ede00e3a56021cf59facd14` 的 exact path／blob 與原文 hash；不提交偽碼工作副本。[source-manifest.json](source-manifest.json)

`verify_evidence.py` 只讀原件與固定 parser helper；重驗 VA/raw/bytes、完整指令界線、7 個全域 literal target 的 38 個候選、6 個函式 target 的 12 個直接 calls、明確 receiver/branch anchors 及 Git tree pins。解碼向視窗終點後多讀 15 bytes，再要求最後一個採用指令恰好結束於指定 end，避免截斷顯示造成假通過。有限候選掃描本身不是語義證明，語義由上面的原件資料流支持；任意計算式 alias 不在完整陰性主張內。

同輪 parser 分題另行獨立核對本包 receiver／分支、39 筆 bytes、22 窗完整邊界、有限集合與20個source pins，結果相符；並據其反例將「有表項就比較」收窄為上述實際 provider 排除／lookup 條件。這是交叉核對，不是 T01 品質狀態升級。

仍未取得的是指定 Client 執行個體的 Integrity 內容、實際 cwd、runtime 可見版本與原生新 MEF 首載 caller。本輪已把資源層的條件說明到具體 reader；沒有用這些未知停止尚可推進的 parser、錯誤處理與 caller 靜態研究，也沒有把它們合併成一個籠統的 Runtime blocker。
