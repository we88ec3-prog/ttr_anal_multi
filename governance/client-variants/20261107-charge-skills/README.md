# V輸入／技能tier與進階測試最小證據（2026-11-07）

本工作為獨立唯讀證據分工。未修改Client／Server、未執行或附加遊戲、未重試
曾遭拒的REA provider、未展開MEF。使用既有原始Git bulk與T10有界BIN-first原稿，
來源SHA見source-identities.json；不得將本彙整稱整函式/T01/native FULL-PASS。

## 可立即交給Server的精確介面

既有KrTutorialBattleCandidateProtocol.Parameter(entity,4,value)格式為8 bytes：
command0 WORD、actor WORD、property4 WORD、value WORD。既有4AFAF0每6B row按
actor找到物件，呼叫主vtable+2C；對已證CCharacter4CE7F0的property4，value低WORD
會符號擴展寫actor+3E8。SkillMatrix讀取以低byte作row，限制row<4；因此可做測試
指定row0/1/2/3，不能傳4作「第四階」。setter本身接受更廣signed值並不證玩法合法。

value1還會建立FORCE附屬物件；其它值清理舊附屬而不走==1建立分支。這是有界
視覺／狀態分支，不能把值1/2/3自動命名官方一／二／三次V充能或自動取消規則。

## V不是單一held bit

KR預設Type0：Key47（DirectInput V位置）→logical16；工作bank可變。
T10-W02有界native檢查確認：controller+40是獨立state，+44保存timeGetTime，
讀phase[16]=FB9014。546780把547240回值映到同一input WORD：

|事件前提|547240狀態／結果|加入mask|
|---|---|---|
|state0遇pressed1或held2|記起點，state2，return1|不加上述事件bit|
|state2遇released3或idle0|state0，return2|0x0008|
|state2仍按住、elapsed嚴格>500ms|state3，return3|0x0080|
|state3遇released3或idle0|state0，return4|0x0040|

0x80只在跨門檻時形成事件，並非每tick V held；0x40是長按後釋放。UI/FSM/
collector/send gates仍可能影響是否看到wire row。0xC0在54F270早退true，不能
據此當Server已施法或不耗資。500ms是本地輸入分流門檻，不是已證技能蓄力完成、
MP扣除頻率、tier升階時間或普攻連段窗口。v29 `_held=flags&7` 目前忽略這些事件，
故只加六鍵資料並不會自然支援V。

## row與matrix變體是兩種參數

54F270(arg8=modeSelector,argC=actor+3E8)。selector由per-hero record+1F4/+1F5，
受+1F6旗標選擇；819220是actor/model WORD外層、selector BYTE內層；81A8E0用
actor+3E8作4row×11column索引。property4改row，不改內層matrix ID。本次未找出
可靠的Server矩陣變體setter，不應用property4傳Matrix ID來假造切換。

原始CharacterMatrices.xml已由catalog固定成員hash
78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad。
charge-contract.json提供9角色matrix0，共180個配置格，含Practice一級join與
ACTIVEINFO signed raw費用。資源成本需按現行負調整語意換算，rawCD/10仍是Server
既有候選，非本報新證官方單位。

伊莉西亞matrix0的進階六鍵：

|row|Z|X|C|Z+X|Z+C|X+C|
|---|---|---|---|---|---|---|
|0 active|29|30|33|32|31|35|
|1 active|36|2475|34|476|475|1293|
|1 Practice|56|148|54|60|59|62|
|2 active|37|474|477|未配置|未配置|未配置|
|2 Practice|57|58|61|—|—|—|

Isilia row3未配置，不能發布一組編造技能。column7/8/10屬特殊鍵域，default0分別
active67/68/2544；active67台版名「覺悟1階段」MP50、active68「覺悟2階段」零費，
這些名稱/成本支持V功能相關候選，但仍不能代替V事件到官方狀態轉移的因果證據。

## 最小可測開發建議

1. 測試頁增加明示「技能row0/1/2」選擇及固定matrix0；同一批設定同時套在Server
   skill/cost selection與Client property4。只允許該角色資源有格值且Practice有join的行。
2. 每個role只授予有依據的Practice level1，preset不再重覆貢獻level；初始化timers
   和HUD以實際active IDs，不混用Practice或motion IDs。
3. 切換row不是永久進度，不寫正常帳號技能/獎勵。先保留按鍵Z/X/C/ZX/ZC/XC，
   不把motion ID等同active ID；用獨立已核對motion join，未知格留未開放並列原因。
4. 若新增真V互動，解碼三種事件而不推測held；將Server充能duration、費用、tier
   consumption/end/reset政策明確標記原型。先有短V/長V正流程包序列與畫面回覆，
   不能只用500ms作全技能官方規則。
5. 在這批已知資料中，可先開明示row測試讓使用者測進階動畫及消耗，無需等待
   所有V分支完全還原；但是不得將debug強制row宣稱為原生V充能已實作。

目前缺口：selector變體writer、完整V事件→tier/cost/motion的正式Server規則、
各role特殊技能motion及技能位移／多段／傷害、不同context角色權限與重設時機。

## 追加：Tab與特殊column（2026-11-07）

原始Table.stp/KeyMapping.xml兩Type均Key15/Mod0→logical22；Ctrl+Tab
(Mod29)→logical39（此分支未追）。5452C0讀phase22=FB901A，phase1/2於
5455F2 OR controller+5C的0x10。54F270將0x10選matrix column10；548D20
反向映射col7→0x8、col8→0x80、col9→0x40、col10→0x10。因C0在
54F270 bypass，此反向helper不是完整V官方施法流程的證明。

C0F944候選表+2C=5452C0、+48=546100；W03明確保留subtype/runtime
owner缺口。546100依FBA7AC==3選actor槽、!=1才查矩陣，尚未將數值
1/3完整封閉為Single/Multi/Tuto，因此不宣稱全context相同。

Isilia default0 col10 active2544台版名稱「轉換伊希莉亞進階技能」，
Practice193/isla_matrixchange01.xml需角色50級；其ACTIVEINFO為HP-10、CD300
（單位未正式驗收）。Tab戰鬥matrix模式技能與教學切角不可混為一談。
角色選單65D920→4A3660另送000C+DWORDrole的6B請求；本次未將Tab的0x10
強稱000C。

V特別欄位67/68的Practice63/64要求角色10/25級。69雖有原始ACTIVEINFO
MP-90，不可僅因名字或相鄰編號自動授予或升階。現階段僅事件/column
映射閉合，充能累積、升階上限、短放降階、消耗與motion policy仍未知。

## Native matrix selection packet closure (bounded)

4E1DA0 table indices259/25B and4FDA30 key*2+1 dispatcher identify012C/012D.
012C: u16opcode,u32role,u8heroD8,u8unconsumed,then allowed-selector bytes to end.
4E5620 clears hero+1F8/+1FC byte vector and appends each selector through655CE0.
012D: u16opcode,u32role,u8first,u8second.4E56F0 passes hero+1F4 as EAX,
packet+6 as stackarg and+7 as DL to81A860. The helper requires both values
in allowed-vector, writes hero+1F4=first,+1F5=second,+1F6=0. It marks
hero+208 DWORD=1 if active selector changed.4E56F0 enqueues UI eventF4417.

This closes a real receive setter, unlike ParamUpdate property4 or17. It supports
a declared test-lab publish sequence012C(known allowlist) then012D(desired,other).
Official Tab-action2544-to-012D causality and a writer setting+1F6=1 remain open.
See matrix-selector-contract.json for exact source identities and original BIN
windows. No provider execution or Client changes were performed.
