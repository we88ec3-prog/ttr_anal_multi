# KR T03 可玩流程阻塞與開發依據 — 待整合

此表覆蓋 T03「登入、選服、選角與連線切換」；不把其他任務的世界初值、碰撞或 actor 生成收進 T03。原檔 SHA：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。靜態分析與來源審核不代表實際可玩驗收。

| 階段 | 已有依據／目前確認程度 | 既有 AI 替代 | 缺失及遊玩影響 | 下一項證據／後續開發 |
|---|---|---|---|---|
| 啟動參數→登入模式 | 原生已確認：parser mode40/52/54、兩段body與literal起點；440D30/440930/440C60顯示literal delimiter分割及空token保留，登入用法先空格再&，marker取首個flattened token。 | 本機啟動／固定 endpoint 不能等同原 launcher 輸入規則。 | 上游launcher／OS quoting、輸入字串編碼及失敗／超界契約未閉合，仍可能選錯模式。 | AUTH-NATIVE-REVIEW.md；後續需同版本launcher輸入規格或可追溯來源，不重做已完成helper，不臆造quote語法。 |
| 模式→登入請求 | 原生已確認：mode52送E8/112，其餘路徑0F/214；E8有兩個51-byte narrow slots，0F有兩個102-byte wide slots；input B經codepage轉換、MD5與32字元lowercase hex鏈。 | 已核對本機server來源只在E8/112登入分支呼叫credentials；ASCII/1..10、空密碼限制與PBKDF2是AI後端政策。 | 0F未進該來源分支；E8+104..109、共同client+BF80業務意義、執行時ACP及完整錯誤契約未知。 | 相容層需為0F另訂具證據的解碼分支，不能沿用E8切片。0F固定尾部可按原生形狀實作；E8未知尾部不得補猜。容量不代表帳密政策。 |
| 驗證→登入結果0x13 | 原生已確認：4C37A0辨status5，status0且非空名稱進更新；帳號／名稱／token位置與group-list 3-byte header、10-byte rows有消費者依據。4C3170通知與狀態寫入不等於socket成功。 | 固定ID、名稱、localhost、group/channel與成功狀態是fixture；ticket產生、有效期、lease、重試延遲是本機政策。 | 官方驗證／完整失敗碼／token產生失效、任意長度封包安全邊界仍未知。row+9只確認傳EDX，不命名負載值。 | AUTH-NATIVE-REVIEW.md；開發先分開client格式相容與可配置本機政策。需原生完整接收尺寸／後端規格才驗收所有錯誤路徑。 |
| 選服／頻道→連線切換 | 原生已確認的介面：66C620的70A事件帶選取值，578用UI fallback；5078C0/507750按群組／row keys查stride60記錄，回row+4與row+C。66C090依分支值與有效指標呼叫T02的4957C0，保存第一選取值到D63DCC。 | 固定localhost、單group/channel、隨機ticket與30秒lease屬本機策略。 | row+4之0/4/5官方意義、F94294來源、D63DCC後續消費、endpoint權威與連線／重試時序未閉合；有效指標不是連線成功。 | SERVER-CHOICE-REVIEW.md；T02接收此呼叫介面與前置條件，核對其framing/socket狀態。本項不重新定義連線核心。 |
| 帳號角色清單／角色場景 | 原生資料橋接已補證：command2的65-byte header+53-byte rows，4B7F00按record+2E且ID<=9選F94304+ID*210，4D4150寫+5C與字串／欄位；672F00讀同記錄+5C。5A67D0的F4246及條件式F4278呼叫672F00，switch經原檔位元組核對。 | LocalHero、固定數值／零值、預設名單與unique IDs1..9仍為本機內容／政策。53-byte形狀已驗證，command60的27-byte場景路徑未因本項而新驗收。 | +5C不是server授權；F4246/F4278產生與訂閱／投遞、資源前置、實際刷新及完整bootstrap仍缺。替代2-byte header路徑命令號未知。 | ROSTER-INTERFACE-REVIEW.md、ROSTER-UI-UPDATE-REVIEW.md；依已驗證格式開發，真實資料權威交T04、資源交T06，不以頭像變色驗收。 |
| 選角→廣場／下一場景 | 原生界面：event578中C0通知F42EF，DC以+D8/0呼叫4A3B80，僅FBA798==0經slot0送42+兩bytes。事件387產生F4247，5A67D0已有F4247局部消費分支呼叫dialog virtual+D4。 | login_protocol.plaza_entry_responses與42配對43/69仍是測試假設；不能以可動fixture認作原生時序。 | F42EF消費者、F4247訂閱／投遞、gate來源、完整轉場與成功前置仍缺；不能因局部producer/consumer對應宣稱已完成事件路由。 | T03交選角請求與UI入口條件，T05核對實際轉場；不補世界值、猜回應或解除client gate。 |

證據定位：完整SHA與正式路徑見 changes.json、catalog claims 及各 evidence/*-audit.json。表中短SHA只是引用標籤；依據分為新原生、已核對位元組的舊清單、歷史報告、AI來源，不能互相替代。

目前建議順序：T03已補清單資料橋接與局部UI更新消費者，下一項定向查證是F4246/F4278來源／投遞或F42EF路由。T02接選服介面與連線契約，T04/T05/T06分別回補資料權威、場景／bootstrap前置及資源身分。新方法先向整合者登記，依賴不得收編。開發優先序與禁止猜值條件見T03-DEVELOPMENT-HANDOFF.md；本輪不修改或執行遊戲／server。

## 驗收界線與證據定位

本表是全T03範圍的缺口／交接評估，不是完整可玩驗收。已整合版本逐筆SHA見changes.json；清單與UI更新的審核以roster-acceptance-review.json及roster-ui-acceptance-review.json定位。舊版「資料橋接未閉合」僅其wire→record+5C部分已補證；完整事件／資源／bootstrap仍未閉合。4B7F00 def-use截斷限制保留，不用包內verify或指令數消除。
