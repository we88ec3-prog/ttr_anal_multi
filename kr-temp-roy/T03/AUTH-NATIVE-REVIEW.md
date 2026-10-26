# KR T03 登入原生資料流與替代實作核對 — 待整合

來源為原始 KR Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。REA6.5.0／Ghidra12.1.4，profile `3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece`；只做靜態分析。所有原始 Evidence 各自保存 evidence/rea-*.json，由 auth-session-journal.jsonl 記錄交付SHA，不以候選數或pcode覆蓋率驗收。

## 參數分割與模式選擇

**原生觀察**：0x440d30 從start=0呼叫0x440930查找literal delimiter；命中時將[start,match)長度交字串建構再送0x440c60，start增加delimiter長度。0x440c60沒有以字串長度過濾token，輸出end增加0x1c；末端start等於來源長度時仍追加空字串。0x440930以_memchr找第一個delimiter byte，再比較指定長度，沒有quote狀態分支。本登入用法的delimiter長度都是1，不推廣空delimiter的終止性。

**有條件推論**：對傳入的有效NUL終止byte string，該路徑先依空格分割，再將各項依`&`分割並追加至同一輸出容器，保留前導、相鄰與末尾的空token。parser在0x440420取得輸出begin，0x440427把它交copy helper，隨後比較mode marker；這是第一個flattened token物件，不能把最後token直接當marker。這個結論不建立上游launcher如何準備輸入、OS quoting規則或任意編碼字串的行為。依此路徑，quote bytes沒有得到特殊解釋；這不是Windows命令列的一般規格。

既有新parser的mode40/52/54分支成立條件與body更正保留，見先前native-parser-review.json；本輪沒有重跑parser。

## 原生認證payload

0x440790：mode52呼叫0x4a3360；mode54及其餘模式呼叫0x4a31b0。兩個body都使用FBA854的virtual+0x10、slot1界面。僅引用T02的Send介面，不由這裡推論整個程式的connection ownership。

| payload位置（inclusive） | 00E8／112 bytes | 000F／214 bytes |
|---|---|---|
| +0..1 | little-endian command00E8 | little-endian command000F |
| 第一字串 | +2..52，_strcpy_s容量51 bytes；第一輸入經WideCharToMultiByte(0,0,…,-1,…) | +2..103，_wcscpy_s容量51 wchar_t（本x86 PE為102 bytes） |
| 轉換後第二字串 | +53..103，_strcpy_s容量51 bytes；摘要字串widen後再以codepage0轉窄 | +104..205，_wcscpy_s容量51 wchar_t |
| 尾部 | +104..109的值／角色本輪未閉合；不可指定全零 | +206..209明寫0x00010001；+210..211為0x0034；不命名為官方version等業務語意 |
| 共同16-bit來源 | +110..111讀自client(FB1318)+0xBF80 | +212..213同一來源；正式欄位含義未知 |

這是client寫入位置與copy容量，**不是官方允許的帳號／密碼長度**。第一／第二輸入的UI語意尚未由完整caller鏈重新驗收；本機AccountStore分別把它們解作username及password digest。copy函式對超界、轉碼失敗與invalid-parameter的完整行為未展開CRT。

0x47f540使用FBA808全域codepage將第二輸入由wide轉窄；0x733dd0呼叫0x733c30，在摘要helper回報非零的路徑，將16-byte摘要逐byte用`%02x`追加小寫hex。0x809ba0的MD5四輪、rotation及64個round constants均有原始Ghidra證據，Python獨立核對其常數順序與MD5 sine公式相符；0x733c30有MD5四個IV，0x809a70有長度／padding／little-endian digest輸出，padding資料D63A00為80後接零。這足以識別此MD5實作鏈，**不構成對任意長度／失敗條件的完整等價證明**，也不證明server如何保存或驗證密碼。

0x46e3c0→0x46e270以同一FBA808呼叫MultiByteToWideChar做digest文字widen。FBA808的Ghidra靜態image四個bytes為零，已觀察的直接references只有reads；這支持static initial codepage0，不能排除alias寫入或當作執行時量測。OS active ANSI codepage及轉換失敗情形仍需界定，不得固定猜成UTF8／949。native auth的正常返回路徑在Send後清除兩個字串slot；這不能反證Send前所有未寫尾部／padding為零。

## 登入結果消費者與選服資料

0x4c37a0讀status+0x16。status5走獨立非成功支路；status0且+2的wide名稱非空才進資料更新；其他status及空名稱走失敗／清理。status的完整人類語意enum仍缺失；不能把整組UI訊息值由單一fixture推廣。

| response位置 | 新原生觀察 | 限制 |
|---|---|---|
| +2 | wide名稱；copy至client+0x67E4，_wcsncpy_s容量11、count10 | 不等於官方名稱政策；不從此函式推出9字限制 |
| +0x18 | dword存client+0x67E0 | 本機稱account ID；server分配規則未知 |
| +0x17 | byte擴展存client+0x68B4 | 業務含義未知 |
| +0x86 | byte存client+0x6898 | 格式已見，token政策未知 |
| +0x87 | NUL終止窄字串經_strcpy_s複製，destination容量5；callsite4C39F8屬4C37A0 | 有效字串copy的容量要求，不證明官方token產生／過期／重放規則 |
| +0x8C | dword存client+0x68A0 | 本機與上述欄位拼成10-byte token，但官方語意未建立 |
| +0x90 | byte存client+0x68B0；為零才呼叫4C3170 | 不將它擅自命名為權威／成功／skip旗標 |
| +0x1C、+0x92 | dword群組數及group cursor傳4C3080 | 只確認此消費格式；不認證任意長度buffer或server資料合法性 |
| +0x20 | 非空wide字串會轉窄並copy至全域文字buffer | 未建立正式notice array容量或完整response struct大小 |

4C3080：每group header為uint16 ID＋uint8 channel count（3 bytes）；每channel row跨度10 bytes：ID在+0..1，+2..3用途未解，IPv4 octets在+4..7，+8非零才把row加入後續資料，+9經EDX傳給507610。**+9在Ghidra偽碼的recovered signature中消失，assembly仍明確讀取／傳遞**；不能只靠偽碼欄位清單，亦不把本機稱呼load直接提升成官方含義。尾端通知0xF4243。

4C3170呼叫login module virtual+0x14(1)、寫context+BD54=1與timeGetTime至BD58、通知0xF4241。這些是狀態／通知的觀察，不能單靠此函式宣布已選服、切線或進入角色世界。T02連線核心保持依賴；4958D4新instruction觀察定位到4957C0的_wcsncpy_s call，未在本項重做整個connection函式。

## 與AI替代實作的對照

- `account_store.py`（SHA512368d3…）的E8切片[2:53]／[53:104]與新native窄字串slot相符；ASCII、1..10名稱、空密碼限制、PBKDF2、嘗試延遲、ticket/lease與初始存檔仍是本機政策。MD5的文字表示已有client依據，不能因此把整份AccountStore認成官方規則。
- `login_ticket_response`的+86、+87..8B、+8C..8F位置與client讀取相符；本機token「四個非零bytes＋NUL」符合該容量5 copy的格式設計，但隨機性、有效期、綁定peer等仍屬AI替代。
- 本機先截name為9個字元的原因需與T02下游channel identity容量並讀；本輪新0x13消費者自身是容量11/count10，不能用它單獨證明9字上限。
- `login_protocol.py`（SHA2df1658b…）的group/channel cursor與3＋10格式得到新native支持；固定account ID1、單group/channel、127.0.0.1及預設旗標值仍為合成fixture，沒有變成官方正常值。
- SHA7385c9a5…本機server的登入回應分支仍只允許E8/112；000F/214不進此分支。這只限該來源快照，不等於目前所有服務一律不支援000F。

## 缺失、依賴與後續開發

需要相容層時，先分開E8窄字串與000F寬字串的client格式及轉碼契約；保留unknown tails／opaque欄位，不擅自補值。原生認證format不提供官方帳號驗證、密碼政策或合法帳號資料；取得相應規格前繼續標示資訊缺失／待補充開發。

選服資料顯示、實際選取與切線仍須T03 UI界面與T02連線時序相接；帳號角色清單與選角UI尚需定向查證，世界內初值和廣場轉場仍交T04/T05。PLAYABLE-FLOW-GAPS.md保留完整階段與遊玩影響，不能只用本報告的auth小成果驗收整項T03。
