# S00 — 教學專用05/09進場分支與舊載入假設更正

接續[REQ-0014首戰紀錄](S00-20261101-TUTORIAL-FIRST-BATTLE.md)。v2人工已看到戰場與敵人，
但編隊頁未關、缺原版換場畫面。本段修教學場景的進場階段，不改Client、不升正式契約，
不把單敵prototype當作完整新手任務。原始KR SHA仍
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 舊資料為何不足以直接沿用

使用者詢問是否上次缺少分析資料。舊`anal/47-new-expedition-reference.md`、
`48-tutorial-battle-fixture.md`和native-index確有分析／版本／限制紀錄；不是沒有留下資料。
但各段證據強度不同：有修改Client後的實測、有合成B0與socket roundtrip，也有未核實的
callback／欄位命名。這輪v1仍沿用等待B0的舊假設，讓實際正常流程重遇卡點。
必須保留失敗與更正，不能把「有測過」當作未修改指定工作副本已整段通過。

兩項具體更正：

1. B0有狀態／商城相關sender，不是已證載入完成ACK。v2已移除它；初次world目前仍以
   實際B0作舊候選觸發點，不額外宣稱這是原版必需載入協定，後續亦應追溯完整初始化。
2. 舊筆記把38尾端listener mode4叫作loading page4。**該呼叫不能用來證明載入頁。**
   FAB090由FAB028 virtual+20取得；OpenAL driver80FD80建立listener，vtable C51D60+18
   指812760，後者加D000後呼叫IAT BD23F8。從原始PE import表解析此格確為
   `alDistanceModel`。所以3／4是此音訊API的mode值，不是UI頁3／4。
   同一38處理器另有context、group、fade-title等工作；這個更正不等於整個38無視覺作用。

## 有界原生進場路徑

沿用保存的Ghidra按址原稿，並用[驗證器](../verify_legacy_login_sources.py)加
`--tutorial-pose --tutorial-npc-formation --tutorial-first-battle --tutorial-entry-phase`，
[140 checks／44 windows](evidence/S00-20261101-TUTORIAL-ENTRY-PHASE-RECHECK.json)通過。
包括原始import解析；仍是限定靜態片段，不是T01 FULL-PASS、官方配對或實際UI驗收。

- shared初始化4B7E8F將4B9630寫到FD2D24，以FD2CFC/stride8範圍是app05。
- 4B9630建立2 bytes的C2S09；另讀payload+2模式。mode1且active scene tag TUTO時，
  4B9737呼叫4C4EB0。這段不走4B7D50替換scene，也不跑6E重建教學。
- 4C4EB0→4A9260，後者比較current page、選next page16（FAADF0），並post
  F43FD參數10／0。這是先前直接送38／map12所缺少的教學專用UI交接。
- **09由05處理器前段送出，先於上述UI分支完成；不能稱為GPU載入／畫面已呈現ACK。**
  Server可用來銜接此明示候選phase，但實際page16顯示、編隊頁關閉與換場畫面須人工觀察。
- TUTO exit4C4D60會呼叫`t_removeAllCoroutines`及清理；5F/type2替換scene不適合直接
  借來保留當前教學。4C scenario完成接收與Part2後續SetUIPage仍須活著。

另唯讀解析pinned Table.stp（SHAea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c），
_MapList的188/190共用town000D，分別用town000／scenario_town000 bounds／trigger；
_MapTitleList的190對Field_04_crypt.dds。552FC0會建立FlyingObject::CFadeObject。
這不是原版完整換場loading UI契約；不要因title fade存在就宣稱使用者期待的載入畫面已恢復。

## Server v3候選與驗收

同一已授權connection正常28/13B後：保存返回pose、停止移動、提交既有starter kit，
送05/1，進入entry-pending；只有精確09/2B在此階段才送38 context、map190、actor／
skills／equipment／control／14／enemy。其餘階段不藉09授權切場，角色owner／lease
保護維持。沒有假B0、無關status誘發、人工delay或自畫loading bar。
API名稱從StartLoad改為PrepareBattleContext，避免錯把38等同完整載入。

Server encounter完成後的候選仍先同DB current-lease記錄勝利，再map188／保存pose／
14／4C14，讓保留的Part2繼續與SetUIPage15。這不是Quest14/16或完整獎勵實作。
AI反擊、技能成本、完整波次、後續任務／獎勵／廣場仍為當前開發，沒有刪除要求。

13個HappyPath cases通過：正常28→收到05/1→模擬原生09→收到38與地圖初始化→普攻
三次→Server win／返回。總207方法／9正向／198暫緩；模擬09不證明實際UI或loading。
10:27:27 UTC本機換版v3，globalv2／兩個component v1及既有角色保留，無新migration。
Network SHA `0de967d27a21bec666996ea743ffa19fecdb8bdfa67a3738bdcd0c3c8f82f703`；
Protocol SHA `f26c7945bdbb42e21a8bdc690ea4420d7433e597bf977518da9c9f93d610e583`；
Persistence沿用前報告。Client SHA不變。
已發結果卡分別觀察編隊頁、換場畫面、普攻與戰後返回；人工結果待回。

待測清單追加：entry-pending斷線／重送、09錯階段、過期lease、partial-send、UI切換與
封包到達競態。這些異常案例現在不執行；只推進正常完整旅程。
