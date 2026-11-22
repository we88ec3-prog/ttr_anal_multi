# 進段旗標重置群組

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。此為動態循環的旗標基礎，
尚未放行cycle或完成結構化循環；沿用自有scenario JSON與既有封包。

definition可選flagResetScopes=[{id,entryNode,flags}]：最多16群組，ID唯一且
符合既有旗標名稱字元／長度限制；entryNode必須存在，flags為1～64個不同的
已宣告旗標。不同群組可重疊，表示在任一對應入口都清除；同一入口依作者
群組順序留下紀錄。未列入的旗標保留整場，沒有自動推斷或連帶清除相依旗標。
例如由付款推出的「本場曾付款」可保留，但「這輪門已付費」須列入重置群組。

每次正式Enter先建立節點訪次，再清除該入口群組內已持有的旗標，接著沿用
既有入圖時計／占點／狀態重建及當前節點FlagsCountReached閉合。未持有的
旗標不會虛構成曾清除。群組內的producer在正常事件發生時仍可設立旗標，
機關須重新取得目前訪次的扣款receipt。單純fork／查詢不清除；fork之後的
Enter只改其副本，源instance與原紀錄不變。scope本身不消耗道具、不發EXP。

靜態資料流在每個入口先從所有入路保證旗標中扣除重置集合，再驗目前producer、
前置、AI、波次及出路。不能沿用已被清除的前圖成功作必要保證。入路合流對保證旗標取交集，對已訪問producer及失效推論取聯集；父旗標重置但已產生的子旗標保留時，子到父的逆推標為歷史而不再使用。若子旗標也清除，之後重新產生的子可恢復正常推論。因此「本場曾付款」不會讓已清掉的「本輪付款」在後圖被靜態分析復活。新的群組須
從scenario入口啟動，不允許用initialNode跳過作用域。重置資訊包含run、內容SHA、
訪次、順序、node、scope ID、policy SHA及實際清除旗標，保留至完成摘要。
群組及其清單在catalog深凍結；schema／Story inline／JSON工作台同步，訊號
改名會更新群組flags。尚無專用群組圖形表單，保存與匯出仍須通過完整驗證。

單房／兩房固定重訪編譯器會複製入口群組、映射到logical alias及visit-local
旗標，其他整場旗標名稱不改。原群組保留在原入口。含新群組來源的單房manifest
compilerVersion=3、兩房=2；未填欄位的舊來源保留單房2／兩房1及原六檔bytes。
編譯仍受整份定義的群組／旗標／AI／節點上限限制，不默默略過群組。

固定Case693候選從條件分支版追加：入口付款後保留entrance-paid-once；到node3
重置群組清除entry-paid，保留本場曾付款紀錄。node3必須另外按41消耗一張183，
建立chamber-paid，再按31／33或31／35完成開關與延遲，依C旗標走不同分支。
後段頭目與結算要求新的chamber-paid。這能驗證清除舊成功且重新以合法扣款
建立新門檻；不是同logical node真實循環。三輪固定重訪另作控制，不改稱loop。

後續仍須完成有上限的循環控制流、循環邊界與經驗分析，以及真正同節點重訪
的正常TCP路線。Client、自然新帳號、獨立Host遊戲驗收與非正流程維持待測。

## 本批驗證

[候選關卡](phindos-stage462-case693-reset-scopes.scenario.json) SHA-256
`28171e4253da7cf96484a3c1bb3866a36808105fc6ab88312e25e9736dbfd022`，
沿用AId4768b72。[收據](flag-reset-scopes-validation.json)記錄同一份內容兩路
正常TCP：node3實際只清除entry-paid，Run紀錄保留；41新扣款後才有chamber-paid，
31/33與31/35分別走3／6出口。重置紀錄綁正確訪次，保留到完成；後續runtime
與before-clear分析均沒有復活entry-paid。兩路各兩筆不同訪次成本、14枚投射物
建立／清理及一次88EXP存檔，回原村原隊伍。

舊條件兩路88EXP及三輪prefix兩路128EXP控制組仍通過，無重置紀錄；六個
舊單房／兩房編譯配套bytes相同。正流程單元驗fork來源隔離、清單深凍結、
歷史逆推失效與群組alias／旗標映射。三個Release零警告、零錯誤；689項
HappyPath全通過。隔離Host預檢相符來源／AI／88EXP後停止，僅證配置。

初次工程檢查失敗源於檢查器原先要求每次扣款立刻開門；本候選另有後續開關，
故新增延後開門記錄，仍核對背包與183快捷數量先發布，若同次開任何出口也
必須在庫存之後。未更改runtime門檻，失敗收據保留，修正後及舊立即開門控制
均通過。未換現行服務／資料庫，沒有Client操作；專用群組GUI及動態loop仍待完成。
