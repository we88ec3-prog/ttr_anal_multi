# S00 — 切角保留教學NPC與首戰編隊入口

接續[移動／切角候選](S00-20261101-TUTORIAL-MOVEMENT-CAMERA-SWITCH.md)。
使用者正常Tab後回報伊莉西亞消失，靠近戰場沒有戰鬥選擇頁；截圖有玩家與要求
伊莉西亞進戰鬥的提示，沒有編隊頁。原圖只留本機，SHA256
`19f9413b1e21bc7884552f82a7661347bf8f959ae0da5df721d7a910ce0c71d8`。
新增 **REQ-0012／0013 GAME_RUNTIME_OBSERVATION**，分開NPC lifecycle與角色取得／
編隊資料需求，沿用RR-0008及既有SCENE/FLOW缺口，不造同義RR或升格正式契約。

## 來源分類及原生限定核對

舊 `anal/44-full-character-switch-and-movement.md` 的10/08/07等全重建，只有當時
修改工作副本／特定環境的可用紀錄；不能推定適用含教學NPC的場景。
舊 `anal/47-new-expedition-reference.md` v11–v16提供入口／編隊候選及角色ID更正；
不是使用者要求固定角色的證據，也不將早期synthetic B0當作真實battle生命周期。

本輪以原始KR SHA
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，
既存Ghidra按址原稿＋唯讀PE／Capstone5.0.9補核。
[驗證器](../verify_legacy_login_sources.py)加`--tutorial-pose --tutorial-npc-formation`，
[86片段／30有限windows](evidence/S00-20261101-TUTORIAL-NPC-FORMATION-RECHECK.json)通過。
不是REA整函式審核、T01 FULL-PASS或官方回覆順序／任務規則：

- app10的4B1A30傳類別0給4DFD40、清控制與玩家metadata tree。這是類別範圍reset，
  不等於只移除自己的entity。當次NPC的實際entity ID／類別未讀取，不能從截圖猜值。
- 基本slot+D4（4ADE8D）指4B28D0，候選app1A；它以(length−4)/2讀payload+4的
  u16 entity list，4B2AC2對指定ID呼叫4DFBC0。候選payload只列Server自有entity256，
  +2未知word維持0，官方用途／值不冒稱已確認。單一移除與後續重建順序是Server候選。
- 帳號slot+15C（4E1E3F）指4E2730，依既有base4/stride8範圍為2B。
  後者讀53B role records及+2E角色index，交4D4150設取得旗標／複製欄位。
  角色取得時機／持久化政策仍是Server設計，不是原版DB證據。
- 4AA4D0包含C2S40／4B sender；實際本機日誌只保留40及長度，沒有body，
  所以scenario14來自既有同版教學候選，不宣稱由這次metadata讀得。
- 基本slot+274／284分別指4B3570／4B3600，候選4E／50。4E讀+2 scenario並派
  F43DA，tutorial page5C3370走5C3610顯示child+22C。
- 50的4B3600複製包含opcode的首u32到FE18F8+C、+4 word到+10、+6 byte到+12，
  後續u16列表由(length−7)/2計算。5082B0以state+E作allowed mask，
  不把state+C低word的opcode誤叫allowed；5083A0處理+10及ordered list的限定
  舊來源仍保留完整函式未審核限制。

## Server候選修正

切角改用1A只移除當前Server自有actor，再metadata／actor／stats／parameters／bind／
stats／timing；初次bootstrap保留先前map初始化。沒有用13E外觀替換冒充邏輯切角，
也沒有補造另一個伊莉西亞NPC來遮掩全清除。

另設opt-in `LOCAL_WORKING_COPY_TUTORIAL_FORMATION_CANDIDATE`，需world模式與pinned
walking bounds。收到精確40/14且同connection已完成intro初始化後，在同DB current-lease
交易中取得role4／Isilia，再送2B、level2候選stats、50資料、4E/14；先commit再送positive。
不接受client提供任意角色／名字作授予，未授予Quest完成或獎勵。
SQLite沿用component v1既有role表，無新增schema／global migration；profile revision
只在新role真正insert時增加，既有roles不重置。更完整任務／重登進度仍需實作。

## 「預設伊莉西亞、不能改」的來源釐清

目前Server50候選是allowed mask13（1/3/4）、forced mask0、capacity1、ordered首位4。
因此**預選伊莉西亞及一人名額，是沿用舊本機fixture的Server設定**，不是這輪使用者
提出的鎖定要求，亦未核實為官方規則。查閱的舊紀錄未找到使用者要求「強制鎖死4」；
這不能推廣成所有歷史對話絕對從未有相關要求。

使用者看到不可改的頁面後，僅詢問來源；隨後明確補充：「原本應該就是讓玩家體驗
伊莉西亞……只是詢問而已，目前是正確的」。**現行體驗保留，不做解鎖／選角限制
變更，不把此問題列為待修bug。** Client是否另有條件、滿員處理或UI限制尚未確認，
不能因Server forced=0就斷言UI一定可改，也不能以使用者認可當作原生FULL-PASS。
這次查閱6BC1A0／6BC2B0的容量／移除候選也未完成上下游核驗，不拿它們斷言根因。

後續battle request不得只因舊fixture曾只接受role4，就把它宣稱官方唯一合法領隊。
實作仍須明示教學候選政策，核對已取得角色、編隊與原生／資源限制；目前不改現行預選。

## 實測與驗證

- 合成正流程12 cases通過：仍207方法／9正向方法／198暫緩；旅程四列涵蓋OFF、world、
  pose、formation。檢查切角第一包只列entity256的1A、owned grant／stats／50／4E，
  獨立SQLite查得新增role及revision。沒有測重送／競態／安全等暫緩項目。
- 08:52:32 UTC啟用獨立formation-v1 Host。Network DLL
  `b418f3c5b85455ebeacd5ede2ebd9a3a841e44b1f7a1d7e6114b507250b773de`；
  Persistence `36a842b04c79bd0862ed08a2d654091f94cafe265c26f032ee6e0845df8168c9`；
  Protocol `570cd316ca9cbdf9077686011eb45f61361400ba5cb977f06517e655754533c2`。
  這是以私庫`3e12a30cb3efc622a21a751e7ec9f668a8234d1e`為基準的本輪working-tree build。
- 08:53:45.9993539 UTC正常C2S40/4B；08:53:46.1217–.1219寫出59／39／13／8B
  raw frames。這是程式對應2B／5C／50／4E的長度證據，不冒稱有完整body capture。
- **使用者明確確認「伊莉西亞仍在，編隊頁出現且看得到她」**。獨立唯讀同DB精確
  fixture查詢證profile revision3、roles3筆、role4恰1筆；不公開名稱／IDs／帳密。
- Client SHA保持`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`；
  沒有Client修改／附加／操作。入場東向及前輪停止效果未得到單獨明確回覆，不額外
  宣稱兩項全部已驗收。首次主線實測只證明當前工作副本，不是原始KR全版相容。

現在停在編隊頁，未按進戰鬥。下一段開發為戰場載入、技能／首戰完成及返回教學，
必須保留TUTO coroutine，不能照搬舊5F2取代場景而使4C完成通知無人接收。
完整新帳號任務與進廣場仍未完成，正式SPEC／RR／GAP不升格。

使用者另明確授權：整段Server修正準備好後，可直接結束本任務本機測試連線換版，
不必再逐次請手動關遊戲；只處理已核對PID／路徑的loopback Host。這是協作授權，
不是一條Server產品REQ，不授權修改Client、操作遊戲或終止無關程式。
