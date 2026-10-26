# KR T02 roy：framing 契約有限驗收

2026-10-25 Asia/Taipei。Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。REA6.5.0/Ghidra12.1.4，profile `3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece`。只做靜態分析，無遊戲執行、附加或目標API。

## 新觀察及成立條件

| 函式 | 局部契約 | 限制 |
|---|---|---|
| 807A70 | LE16 length、LE16 1A68、原始payload；檢查length非零且length+4<=1000hex，成功EAX1/失敗0 | 正常不溢位長度下payload上限4092；另有累積量+500C<=4000hex及指標範圍檢查，不是只靠長度就一定成功 |
| 807830 | LE16 length、LE16 0BBB、LE16明文byte sum mod65536；首byte XOR B6，後續byte XOR前一明文byte；length非零且length+6<=1000hex；成功EAX1/失敗0 | 正常不溢位長度下payload上限4090，同樣有累積量/指標guards；偽碼void prototype失真，807A37/807A61及caller TEST EAX支持回傳 |
| 8061A0 | 806202讀connection+A02C byte；零跳807A70；非零先807830，EAX0才fallback807A70 | 806218/806223/806228/80622A/80623A/80623F支持；mode實際初始化/writer未知，不能稱非零mode永遠只送0BBB |
| 807B40 | payload length 1..1000hex；2633 header8、0BBB header6、其他預設header4（1A68/22D7亦4）；資料不足保留剩餘buffer；0BBB相依XOR與sum比較 | 未知marker未在此比較鏈拒絕，不等於官方有效業務；checksum不符跳807D7F，略過807E50 copy，再進共同record處理並按length+header前進。pool+4初始契約未查，暫不宣稱完整discard語意；2633/727190轉換未驗收 |
| 806AD0 | 建立TCP；第四參數寫connection+A080，第三參數供network+18 map鍵；A0B4寫2 | 不把A0B4的2當A02C mode；pipeline不等於actor/房主；不證明connect實際成功或官方端點權威 |

原始Evidence、逐筆SHA、完整inclusive body ranges及原檔range摘要在evidence/native-contract-checks.json；原始dossier為native-807a70/807830/807b40/8061a0/806ad0.json。8處新的獨立byte核對全相符。確切Evidence IDs：

- 807A70：ev_668e65536aff3836aa874892b38a6907fdd0d44b947e5db7a15e4faf3c68887f
- 807830：ev_c6c1444c8e19341ac267bf4ac7901baad63aece15454780ea91b14349446ae5c
- 807B40：ev_4e24cf7c0f2d3a883b44534162144f1cf60f27c135042a2f9138235d70449531
- 8061A0：ev_66d300a9ed6179300972aa69d059c489345d953e4f87e72cd4cf7b9e6d428613
- 806AD0：ev_3a204bc5c421a7778897bb38d4164740cd75f38590444762b755ff6163aec298

## 舊結論與更正關係

TRANSPORT-REVIEW.md及findings001原把4090來源列為待查假說；本次支持它是0BBB sender正常長度上限，raw1A68 sender則4092，receiver payload門檻4096。原先「helper未展開」不再套用本報告驗收的局部路徑，未驗收helper/2633限制保留，舊報告不覆寫。

login_protocol.py的4090 sender限制、0BBB XOR/checksum有局部原生依據；整檔仍是本機替代審核來源。其decode/StreamDecoder拒絕4091..4096及未知marker，checksum mismatch丟例外，不能當作807B40的完整對等行為。合成帳號/角色/出生點與時序假設仍非官方後端。

## 分類、遊玩影響及待開發

- 原生已確認（有限靜態）：兩個sender header/容量/0BBB局部演算法、mode dispatch/fallback、receiver長度/header及checksum跳轉。
- 部分確認：收包至pipeline共同record處理、槽/參數介面；mode來源、非同步時序、pool/copy完整狀態未閉合。
- AI替代：Python codec支援範圍及錯誤策略未對等部分、合成業務fixture/初值；不能以本機可玩紀錄驗收原版。
- 資訊缺失：A02C初始化/writer、2633轉換、pool+4清零、807E50長度契約、官方順序/重試/端點/伺服器權威。
- 待補充開發：已確認sender格式的離線向量及stream parser；分別列sender/receiver限制，涵蓋fragment/coalesced、unknown marker、checksum mismatch；策略先區分相容需求與本機選擇。本輪未改服務/遊戲。

差異可能影響登入後/場景收包同步；此為相容影響推論，未觀察真實故障。下一步查805950及A02C writer，再查8075B0/807E50/806CF0的pool/copy/caller；先核對主責並登記。T03業務、T04真實資料、T05場景前置、T06資源身分仍為依賴，不補猜。

## 驗收限制

8061A0的80639F至89C9F0帶Ghidra terminal-call/no-return假設，不當成獨立證明所有路徑無返回。五份value-flow當次未截斷，仍不跨函式且可能缺alias/call side effects，不以此作語意完成率。PDB載入狀態未知，型別/名稱可能失真；以body AddressSet為準，不把外包範圍當連續body。

只驗收上述局部契約；完整通訊框架及可玩流程未驗收，MEF/普通怪物決策/P2P權威未由此定位。
