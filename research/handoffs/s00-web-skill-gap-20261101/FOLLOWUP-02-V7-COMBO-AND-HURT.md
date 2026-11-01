# S00 → Web T10／T11：v7實測後續補查

使用者於本對話指定「執行T10T11並上Git」要求派工；本卡是後續研究工作範圍，
不新建正式RR、不改Task owner／T01退回／APPROVED或native_complete。
戰鬥仍為第一優先，僅離線唯讀原版；不啟動、附加、修改Client，也不做負向／併發／壓測。

## 已收件與目前狀態

你交付的commit `4064846ff77fbf3884fc84830ed35f60c9d8781d` 三份報告已由S00讀取；
[S00收件](../../../governance/s00-iterations/S00-20261101-WEB-COMBAT-INTAKE.md)保存來源及七段
BIN視窗hash吻合的有限結果。沒有整份升FULL-PASS。請沿用原分支，不重做全量反編譯，
不覆寫原稿／main；有可用原始BIN與保存Ghidra就按精確入口補查。

原始KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
[v7人測與候選修正](../../../governance/s00-iterations/S00-20261101-V7-PLAYER-RESULT-AND-COMBAT-FIX.md)：
使用者確認已進廣場、人物/NPC可見且能移動停止；另報「被攻擊不會出現受傷動作、連點Z不連段」。
實測是指定修改工作副本，不是原版Client驗收；缺少完整按鍵時間戳／payload，不能先定唯一根因。

Server已備源碼（尚非人測部署）：多row000A中選唯一受控row、普通動作末段X/Z+C暫存、
放開後接段寬限0.4秒、伊莉西亞待機受擊motion9。0.4秒是Server政策，非官方窗口。
上述候選不能反過來當作原生證據；本工作要補它們仍缺的Client資料流。

## P0-A：普通連點／放開後接段與多row語意

1. 沿既有5452C0、545895／545A54及真正controller concrete virtual+44/+48/+58，
   選一條首戰伊莉西亞普通Z輸入鏈：keydown／hold／keyup到6+5N producer。
2. 明確記錄同一受控actor是否可能一次出現多row、row順序與first／second WORD及第五byte
   哪些分支已證、哪些仍opaque。不能將Row B的E4/B0反證改寫成兩者都代表方向。
3. 找連段counter／reset與clock的writer、讀者及作用域；特別核對「目前動作已自然結束、
   玩家放開後稍晚再按Z」如何保留／重置下一段。0.65舊fixture與0.4新Server政策都不是答案。
4. 若完整鏈超出本輪，先交一條可重現正常路徑與精確剩餘caller/ABI缺口；不堆地址清單。

## P0-B：受擊動作觸發的Client接口

1. [有限資源metadata](../../../governance/s00-iterations/evidence/S00-20261101-ISLA-HURT-RESOURCE.json)：
   Isla.abf ID9→Isla_ATTACKED.asd；單段20frames／40FPS／Delay0，名目0.5秒。
   請勿把資源名目片長直接稱官方硬直或霸體時間。
2. 針對敵人對玩家的000E結果與後續actor/controller處理，查哪個已證欄位／本機條件會
   觸發受傷動作或抑制它；區分0D顯式motion與0E自動reaction。T12傷害公式不在本卡。
3. 若跨T08/T09/T12主責，引用其既有成果並交明確交界缺口即可；不要改他人owner／主張，
   也不要自行傳訊其他對話。輸出可供Server選擇正確回覆／狀態的有限契約與未知點。

## P1：原技能ID／clock缺口

時間允許再補伊莉西亞Practice49/50/52→Skill29/30/31候選對應的原資源與consumer，
再到Motion／Effect／TargetSkill；不同ID domain分表。012A actor/skill/count／33與更新
頻率分開，仍未知就保留未知，不把hero-only helper泛化成怪物AI。

## 交付

- 在原分支新增限定報告到本目錄，保留原稿；列target SHA、精確入口、必要byte／保存
  Ghidra來源、hash、正常案例的輸入→狀態→輸出→clock及反證／未知。
- 有界原生事實、Server選擇、工作副本人測各自標示；不虛填正式RR CLAIMED／ACCEPTED。
- Commit／Push後回覆commit與各檔blob SHA、可直接採用項目、仍需補證項目。
- 不需反覆回「繼續嗎」；在本卡範圍完成可核對的一批後交付。不要修改Server或Client。

廣場loading及NPC後續劇情卡住另由S00接續，不把它們塞成T10／T11必須解完的責任。
