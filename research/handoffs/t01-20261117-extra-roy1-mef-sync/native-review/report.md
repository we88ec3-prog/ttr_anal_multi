# T01：MEF comprehensive／P0 原件與採用邊界定向檢核

## 結論與精確範圍

本次對 `extra/roy1@534746f194a889ebb34dda7471c2ae62d30a1dd1` 的 `MEF-comprehensive-contracts-20261117` 與 `MEF-P0-content-contracts-20261117` 完成 **R0 重現檢核、R1 限定主張／勘誤採用檢核，以及下列高風險路徑的 R2 原件核對**。沒有發現需要以新矛盾退回這兩包的問題。這個結論不延伸為兩包全文 FULL-PASS、121 個 native body 全部語意驗收、其他歷史包通過、Server 已實作或玩家已可玩。

本次沒有修改原稿、原件、正式 RR／owner／T01 既有狀態；本報告只提交給主整合者。官方 MEF grammar、普通場景首入／world-result→Lua 的未解範圍、實際 mount／payload 和正常遊玩證據仍照原稿分層保留。

## 1. 檢核方法及真實重跑結果

原件為 KR `02-Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes。`native-review.json` 由獨立的 PE32/i386 讀取及 GNU objdump 重新產生，核實 **25 個窗口、6,421 bytes、2,147 條指令** 的 VA/raw 映射、連續解碼及 bytes；窗口範圍來自固定來源 metadata，解碼與原件讀取未調用來源 verifier 的 PE/parser。這些數字僅表示證據取讀範圍，不能換算全文語意覆蓋率。

| 檢核 | 實際結果 | 證據／限制 |
|---|---|---|
| P0 根 verifier `--run-evidence` | PASS；四個子題實際重跑，結果與各保存收據逐欄相等 | `p0-package-result.json`；ABI、資源、生命期、Server 資料對照均執行 |
| P0 包完整性 | 66 檔、153 個不同固定 Git 來源、40 JSON、9 Python、76 文件目標 | 根收據，不自動為語意認證 |
| comprehensive 根機械 verifier | PASS | `package_mechanical.stdout.txt`；根本次不使用 `--run-evidence`，避免原 fixture 腳本就地重寫研究檔 |
| comprehensive 六個原件 verifier | ABI、events、reuse、reuse-followup、resources、resource-selection 均 exit 0，JSON 等於保存收據 | `comprehensive-runs.json`／各 stdout；是新的執行記錄，非只讀舊 PASS |
| comprehensive ABI fixture | 14 例 PASS，重建 JSON 等於保存收據 | 只在 `abi-fixture-copy` 執行，原包不覆寫 |
| comprehensive 原包前後身份 | 78 個檔案全部相同 | `comprehensive-rerun-result.json`；檔案數以該收據的 `source_package_files` 為準 |
| 資源就緒 gate | 研究可重現，仍須拒絕 READY | `resources-require-ready.stdout.json` 與命令收據；`ready=false`，完整遞迴 payload／exact runtime selection 仍未完成 |

上述 subprocess 只使用固定研究工具、Git 唯讀物件查詢及 objdump；沒有啟動 Client、Lua、Server 或任何原始資源腳本。自訂作者模型與 fixture 仍屬 SYN／NOT_NATIVE_MEF。

## 2. R1／R2 主張與證據

以下 `P0-R1-xx`／`P0-R2-xx` 是此報告的局部識別碼，不是新建正式台帳或 REQ。完整 source path、blob SHA、SHA-256 與 byte length 由 `review-sources.json` 保存；機讀主張在 `claims.json`。`BOUNDED_R2_CONSISTENT` 表示本次定向核對沒有反證，所有正式 evidence level 保持 PARTIAL，未提升 R3。

### P0-R1-01：121 binding 採用資料一致，但不是 121 個獨立玩法完成

P0 的 121 筆唯一名稱與 comprehensive ABI 的 native、marshaller、argument_count、argument_kinds、binding_status、produces_new_lua_value 逐欄相符。16 個 observation query 加 `lb.DoFile` 共 17 個 new numeric value producer；104 個無新的 binding 回值。四個 stub 和 `lb.GetObjectCount` 的「不能當新 count producer」限制保留。ABI 名稱、引數與回值契約通過，不代表每一 native body 的所有副作用、呼叫前提和畫面成功皆已審核。

來源：`MEF-comprehensive-contracts-20261117/abi/abi-contracts.json`、`abi/verification-result.json`；`MEF-P0-content-contracts-20261117/abi-adoption/adoption-catalog.json` 與新根收據。

### P0-R2-02：原 RevPhase1 的零引數 EndSepia 不是「泛用缺參數等於 nil」

原 qbase P74 的 PC36–38 形成 `GETGLOBAL Q → GETTABLE EndSepia → CALL A=0 B=1 C=1`，原資料由 P0 reader 重新產生並核同一 Event member SHA。關鍵 native 邊獨立核對如下：

1. `6FD029..6FD045` 以 B=1 將 L.top 設為 callee slot+16，傳同一 callee 及 L 給 `6FE1C0`。
2. `6FE1C6` 確認 tag6；C closure 分支 `6FE2E6..6FE360` 在正常、無改寫 hook 的條件下保留該相對位置。stack grow 經 `6FDCB0 → 6FDC30` 按同一 displacement 調整 top／frame；CI grow 另調 CallInfo。
3. `56A100` 傳同一 L 至 `56A430`，沒有先加入 user arguments；`6F510F..6F5115` 的 -1 是 top-16，因而讀到 callee TValue。
4. `56A44A`／`56A44F` 只接受 number3／string4；tag6 走 `56A494 xor eax,eax → push eax`，native 入參為整數 0。
5. `565608..565636` 寫 FE36D4=4，處理 FE36DC bit1，兩條旗標分支均將 supplied 0 寫到 FE36D8。

採用限制：原 C binding 不被替換、一般 frame、正常配置返回、無修改 callee/top 的 hook。沒有證明全部缺參數呼叫皆如此，也沒有證明視覺同步完成。新內容必須明給一個 integer 的作者政策與原相容特例可以並存。

### P0-R2-03：FlyingObject 的取消在新配置之前

`564940` body 的 `56496A call 564A60` 早於 `56496F push 0x70`／配置。`564AB4` 讀目前 M+40 handle；若 shared manager tree 找到對象，`564ADD` 寫該圖 alive+14=0；`564AE4` 將 M+40 設為 -1。之後才建立新圖與保存新 handle。故「新建僅覆寫 handle，完全不取消舊圖」被原 bytes 反證；目前 comprehensive/P0 採用的更正方向成立。

取消不是同步實體釋放；`5537F0` manager 在合格迭代呼 tick、alive reader，零值才 release／deleting destructor／erase。也沒有把 Q 的單一 handle 擴張為 Tutorial 全共享 owner sweep。

### P0-R2-04：選定原場景的 fade-out 0 跳過除法

Q2440/5 的原 FlyingObject 入參是 fade-in100、hold100、fade-out0、holdForever0。`553E90` 同值寫 total_out+20 與 remaining_out+2C；`560080` 於正常載入函式返回路徑寫 phase1。`553C05..553C0A` 對 remaining_out=0 的 signed JLE 跳至 `553C41`，越過 `553C22 fidiv [+20]`，設 alpha0／phase0。下一次合格 tick 的 phase0 才在 `553B79` 寫 alive0；manager 同次後段再清理。

這排除這組正常值的必經除零，並支持有條件的有限生命期；並不保證圖片 DDS 存在、畫面可見、固定 wall-clock 期限或 Lua completion token。group eligibility、正常初始化、持續合格 tick 與無競爭改寫仍是實質前提。

### P0-R2-05：Q 初次建立的真實 direct caller 傳 immediate=1

`56322C mov esi,ebx → 56322E call 4D0FE0` 進 Q 初始化；`4D0FE1 push1 → 4D0FE3 push esi → 4D0FE4 call 4C7DF0` 明確傳入 1。`4C7EDE..4C7EED` 讀此引數，設 D+20=1 並直接呼 `7A8E70`。該 request 另按 D+20 選 event／等待分支。因而不能把 vtable+30 的 `4C8050 → init(actor,0)` 當成這條真實 direct caller 的值。

本次獨立 R2 決議限定實際 caller／模式 writer／request 分支；其他 producer 的 deferred request、附件、後續動作及 draw gate 仍按原資料限定。所有附件、資源或畫面 ready 不是 immediate flag 的推論。

### P0-R2-06：Doll cleanup 與全 queue drain 分開

P0 的 `7A57C0` 使用 adjusted receiver B=D+8。`7A580C` 比 B+1C，即 D+24 state；只有 state1 進 `0x38` release record 路徑。`7A5862`、`7A586C` 分別記 model／instance，`7A5891` 複製 applied parts，`7A5909` 呼 release queue；其後 `7A5911` 清 instance、`7A5949` 重設 state、`7A594C` 置 dirty。這支持「排釋放與物件欄位更新」的精確邊界，不能改寫成同步 drain。

22-owner 與三種 run profile 的完整性及 source pins 已重跑，但本次未將 22 項全部升為新的獨立全文語意認證。作者的 cleanup DAG、generation 和排程政策仍屬相容 Server／內容工具設計；Client 沒有因此多出一個 run token 或全 owner ACK。

### P0-R1-07：資源未知及 Server 採用責任保留正確

兩份原場景共 108 個 body call／17 次 Create／15 個模型，兩個所選模型 descriptor 已找到並解析，13 個仍缺原件。根交叉檢核與 resource 子題保留 exact runtime selection、全遞迴 payload 及 `ready` 的 false／BLOCKED；Base index 830 筆不被誤寫成 830 個 descriptor 已解析。Q119/3 的範圍只到入場演出，不包含 119/4 清場及 119/5 返回的完整驗收。

三類開發工作已列在 `SERVER-ADOPTION.md`：採用版本化 ABI 與 helper 規則、部署資料的實際 resolver／payload 審查、owner／退出／業務結果分離。它們應沿 REQ-0019／REQ-0021 由 S00 去重接收，不能把官方 Server 內部演算法未知當 Client 靜態停工理由；也不能把未知 Client wire／合法入口全部推給 Server 開發。沒有新增任意 Lua wire、cleanup ACK、opcode 或擅改現行 `.scenario.json` schema。

## 3. 歷史衝突與版本判讀

P0 已採用 15 項既有勘誤；其中 FlyingObject 解讀與 SYN 前提的更正、Doll 獨立引用／有限 layer projection、Q 真實 immediate caller 都保留原稿及來源。舊 SYN PASS 只保留「當時工具曾執行」的事實，不可反過來推翻原 BIN。

`ERRATA-12`／comprehensive `VALIDATION.md` §4 的 parser SHA 說明必須限制於該包當時選用的 Git parser。`3a7e2751…` 與 `8eb16bbc…` 是不同來源版本；「當次選用 parser 與某舊工具 pin 不合」不能擴張為「舊工具所有合法來源都無法重現」。本輪歷史包檢核已從 one-shot-followup 12 分片按既有還原工具取得正確 parser，實際 SHA-256 為 `3a7e2751274b9c1cc43f514e8ab13a5b48ff5983251f847334e213baab0381d2`；archive 有 24 個 regular member，工具將 packed previous-native 還原為兩份，因此交付總數為 25 原稿。正確來源下，主 T01 歷史審查已完成 17 個舊 package 的重跑 PASS；`canonical-runs.json` 的 8 個重新執行項目全部 exit0，包括 A1／surface，配合其餘既有新收據計入總數。本子題實讀 canonical 收據並核實還原 parser hash。這解除當次輸入版本失配，沒有修改歷史收據，也不是目前兩包 ABI／native 語意的反證；不得繼續將所有歷史 aggregate 概稱不可重現。

## 4. 交給主整合者的決議

這兩包可作有限研究來源導航，並保存本次 R0／R1／R2 記錄。主整合的來源收件狀態維持 `CLAIMS_EXTRACTED`，不因選定有界主張的定向核對將整包全面升為 `CONFLICT_CHECKED`；`SPEC_CONSUMABLE` 仍需 S00 按用途接受，R3／FULL-PASS 不自動提升。對已存在的歷史錯誤只引用更正關聯，不重開重複退回或修改歷史原稿。四層未完成狀態繼續分開：

- **Client／原件待補**：普通首入或 world-result→Lua 未證路徑、指定 mount／cache、13 個選定模型 descriptor 及其遞迴 payload 等。
- **Server 待開發**：ABI／typed identity／owner／業務結果分層的採用與審查、權威規則及保存。
- **跨功能待整合**：既有合法 selector、資源發布、原封包 adapter、正常主線各節點串接。
- **待遊玩驗證**：完整視聽／對話、輸入及場景恢復、各原回覆與任務／獎勵結果；本次沒有執行遊戲或 Server。

原包與原件保持唯讀；沒有在此子任務 commit／push。
