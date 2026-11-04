# W2 未知、Server 開發需求與解除條件 — v2

**三怪的矩陣與Actor body已取得；本輪資料盤點完成。** 目前保留的是skill WORD→動作／原生consumer、PRE選擇、metadata/provider來源，以及應由Server制定的九類規則；不能再把「raw矩陣／ABF尚未附」作為當前阻塞。

本頁狀態為 `DRAFT_FOR_REVIEW`。`W2-U*`／`W2-SRV-*` 只是交付內的局部引用鍵，**不是新增正式RR／REQ／SPEC台帳**；S00按既有流程採用、去重及登錄。來源與SHA見 [source-index.json](source-index.json)、[table-stp-presence-audit.json](table-stp-presence-audit.json)、[base-stp-audit.json](base-stp-audit.json)；native條件與更正見 [consumer-notes.md](consumer-notes.md)。本輪未執行Client／Server或歷史腳本，未做新BIN、MEF、loader研究。

## 1. 已解除的資料缺件與尚未解除的語意

| 已取得項目 | v2直接來源值 | 取得資源後仍未證明 |
| --- | --- | --- |
| M01 `Table/Skill/Matrix/MonsterMatrices.xml` | 3怪共11個cell，Matrix ID均0；1001有76/307/371，1009有92/1593/93/1594，1004有80/309/81/455，保留各tier/key | PRE→Matrix/tier、skill WORD→definition／action／效果及選招策略 |
| M02 `Base.stp!Mon/00_HokyPoky.abf` | 15個Animation、11個不同clip引用、ID101 SKILL01及直接effect／sound | 3個矩陣WORD如何映射到動作、起手／命中／冷卻 |
| M03 `Base.stp!Mon/01_Moose.abf` | 16個Animation、13個不同clip引用、ID101／102 SKILL01／02及直接effect／sound | 4個矩陣WORD如何映射到動作、不同PRE的規則 |
| M04 `Base.stp!Mon/01_Nepenths.abf` | 16個Animation、6個不同clip引用；ID4/6指WAIT01，ID9/10/11/12/14共用ATTACKED | 不動／移動權限、hurt狀態差異、tier0／2與PRE的關係 |
| M06 `Table/Skill/Matrix/CharacterMatrices.xml` | import成員已取得且SHA核對 | hero SubAI未因此成為Monster AI；model≤9等限制仍保留 |

以上為 `ACQUIRED_AND_VERIFIED` 的檔案／資料身分狀態，不是新的T01 FULL-PASS、SPEC STABLE或Server可玩狀態。三個body共有47個Animation、70個資源引用出現、50個去重引用；body的ActorID來自`_ActorList FILE`與exact member basename相符，ABF自身沒有ActorID/PRE。相同FILE不保證所有PRE共用技能／AI。

## 2. 九類AI欄位：來源線索與決策值分開

以下三怪的每個**AI決策／判定值**均為「無來源」：`source_status="無來源"`、`value=null`、`unit=null`。原始FILE／PRE、矩陣cell、Animation與child引用另存為「已知來源值」；九項Server需求可獨立推進。`null`不得默認轉0、false、固定不動或某個預設節奏。

| 欄位 | 三怪目前的直接來源線索 | 仍沒有來源的決策／判定值 | Server需求 |
| --- | --- | --- | --- |
| 追逐 | 1001／1009的Animation ID4/6指MOVE01；1004指WAIT01 | 速度、追逐距離、路徑、停止條件與移動權威。WAIT不代表永不移動。 | W2-SRV-01 |
| 感知 | 三body及目標矩陣沒有感知／視線／仇恨欄位 | 半徑、有效目標、視線、仇恨規則、感知更新時機。 | W2-SRV-02 |
| 回位 | `_ActorList FILE`與`Character RelativePath`只描述資源；矩陣沒有world anchor | 回位錨點、leash、仇恨／HP重設與返回條件。 | W2-SRV-03 |
| 選招 | 11個matrix cell均已直接讀取；三body有具名SKILL01，Moose／Nepenths另有SKILL02 | skill WORD→Animation/action provider、優先序／權重／距離／觸發條件、PRE選擇。 | W2-SRV-04 |
| 起手 | 47個Animation皆有FrameSpeed="40.000000"、LagtimeType="LightMelee" | FrameSpeed單位、FPS、總幀數、duration、起手／提交／取消時間。FrameSpeed不是已證40FPS。 | W2-SRV-05 |
| 命中 | SKILL-named Animation有明列Effect與Sound child | child何時播放、是否對應hit、傷害／範圍／目標權威與skill WORD橋接。 | W2-SRV-06 |
| 冷卻 | 11WORD與SkillActive469個no交集為空；舊報告54F270只檢查remaining==0 | 時間單位、monster cooldown instance、起算／取消／清除／重設政策。 | W2-SRV-07 |
| 受傷 | 三者Animation ID9均指ATTACKED；Nepenths多個ID共用該clip；其他受擊樣式檔名已知 | 硬直、免疫、打斷、狀態分派、恢復與實際動作consumer。 | W2-SRV-08 |
| 死亡 | 三者Animation ID7均指DEAD並引用DEAD.wav，Repeat字面為0 | 死亡權威判定、結算／任務／掉落／移除次序與時點。動畫結束不等於任務完成。 | W2-SRV-09 |

三body沒提供clip總幀數、duration、hit frame或effect/sound啟動時點；它們有資源child，不能把「有Effect節點」改稱已知命中事件。未來即使測得播放時間，也要與Server規則分欄，不能直接將clip總長當作起手、傷害、冷卻或死亡移除時間。

## 3. 真正仍未閉合的Client／資料邊界

| 局部ID | 已查範圍與排除的錯接 | 剩餘未知與解除條件 | 責任／影響 |
| --- | --- | --- | --- |
| W2-U01 body資源身分 | 12個Actor/PRE列、三個exact Base member、SHA、全部47Animation已核對 | 資料缺件已解除；若需要證明每條PRE實際loader行為，須依具體Client相容需求另引用或補證consumer | 不再要求重取三body；本輪不新追loader |
| W2-U02 PRE→矩陣選擇 | 已讀三個SkillMatrix完整11cell；Matrix ID0、tier0/2與Actor PRE是不同域 | 取得可證的PRE／runtime actor變體→matrix ID/tier選擇證據；不能用PRE−1或同FILE直接轉換 | Client consumer／資料整合，未證映射保持null |
| W2-U03 技能provider與動作橋接 | 三body沒有skill／matrix／PRE bridge欄位；11WORD沒有等值Animation ID；CharSkill與SkillActive對這11WORD交集為空 | M07檔名／carrier仍未解析。需typed provider或既有有界consumer，明確把skill WORD連到action/animation/event/必要參數；不能編造檔名 | 真正Client資料／consumer缺口；保留11cell，不啟用猜接的技能動作 |
| W2-U04 Monster metadata來源 | 已有ActorResource/display欄位與body，但沒有已證的Monster stats/provider | M05為來源角色未解，檔名/carrier保持null；若相容Client需要特定欄位，補其來源consumer。純Server政策由S00設計 | 不憑空要求Monster.xml，也不以缺官方Server規則阻擋Server開發 |
| W2-U05 下層呈現asset與時間 | 30個clip有精確RelativePath+File；6個effect有精確Folder+File；另有base／聲音／貼圖引用 | carrier仍未知；只在呈現需要時取原件、記錄其實際單位／consumer，再判定能推出哪些播放資料。不能預填FPS或傷害時點 | **P2 OPTIONAL_PRESENTATION**，不阻擋W2盤點或Server AI自主規則設計 |
| W2-U06 原生Monster指令／結果consumer | 819220／81A8E0只是lookup；549980／54AE70有hero≤9 gate；54F270為predicate；54F330為UI snapshot | 依S00具體相容情境，重用既有已證入口、封包／parser／writer；仍未知的native wire與actionID另交主責Task限定補證 | 不能將Animation ID直接命名wire motion ID，也不能把缺wire推成自由Server政策 |

**同號不構成domain bridge：** Moose matrix WORD92／93在IndependentSkillEffect恰有同數字Index；Index92的File為空，Index93是`B_Self-BasisDestructionTrap01.eff`。Moose body的SKILL01／02直接child則是`Effect/Monster/M_Moose-AttacK01.eff`與`Effect/Monster/M_Moose-AttacK02.eff`。因此`effect_index_present=true`可如實記錄，但`skill_action_effect_binding`仍必須UNKNOWN，不能把92/93列直接接成Moose技能效果。[IndependentSkillEffect原件71–72行；Moose body28–34行]

另一個反例是數量不同：HokyPoky的3個WORD只有1個SKILL-named動畫；Moose／Nepenths各4個WORD、2個SKILL-named動畫。這不證明技能不存在或固定共用哪個clip，只能排除未加證據就按順序配對的作法。

保留T01更正：`549D54→54F270`屬獨立入口`549C60`，不屬`549980`；T10-026既有`NEEDS_FIX`未因本輪資源核對而解除。玩家SubAI入口仍不能當Monster AI。同樹helper或同數值也不證同一資料域。

## 4. 可選引用的使用方式

[required-members.csv](required-members.csv)應按狀態區分：M01–M04／M06為已取得，M05／M07為尚未解析名稱的來源角色，6 effects／30 clips為可選呈現引用。列數不代表尚缺的必需檔案數。Folder+File或RelativePath+File是已證原字串，**未必就是另一archive的member path**；原件的實際carrier、member與SHA取得後才可填入。

Base完整index沒有這50個引用的exact literal或basename match，只能排除此一精確Base版本，不能聲稱其他archive不存在。聲音／貼圖／base model同樣是呈現項目；本輪不用取得它們就能完成三怪資料／未知對照、開發Server政策介面與交付S00需求。不把29個未附歷史README引用升成必需原件，不要求使用者自行找檔、影片或截圖。

## 5. Server待開發：九項可獨立推進的相容行為契約

下表是**待開發需求**，不是已獲S00批准的政策或官方數值。本輪沒有寫私有Server，也不替未知規則填預設數字。可先建立可配置介面、狀態與事件邊界；由S00決定明示的候選政策，Client必需wire／parser保持來源約束。

| 局部需求 | 玩家情境與行為 | 已有來源可提供什麼 | S00仍需設計／實作 |
| --- | --- | --- | --- |
| W2-SRV-01 追逐 | 玩家移動後，怪物按規則接近、停止或重選目標 | 3個Actor body與MOVE／WAIT引用，包含1004的差異 | 速度、路徑／移動介面、停止與重選條件；不得由WAIT永久禁用位移 |
| W2-SRV-02 感知 | 怪物從有效玩家中決定是否進入戰鬥 | 本輪直接資料未給感知數值 | 目標有效性、範圍／視線、仇恨與更新政策 |
| W2-SRV-03 回位 | 目標失效或越界後返回並重設適當狀態 | Actor resource identity；資源路徑不等於world出生座標 | 接W1出生錨點、leash、回位路徑、仇恨與HP重設 |
| W2-SRV-04 選招 | 在可用技能中依條件選擇 | 三怪11個具完整來源的matrix cell；分開的Animation資源集合 | 解決或明示skill/action相容provider，再配置可用性、距離／資源、優先序；未知mapping不可默認可施放 |
| W2-SRV-05 起手 | 起手、打斷與攻擊提交可解釋且與呈現協調 | SKILL01／02資源與原始播放屬性，但無已證FPS／duration | 起手／commit／interrupt階段、Server時點與呈現同步，不用clip總長替代全部判定 |
| W2-SRV-06 命中 | 攻擊產生權威命中／傷害並同步 | 明確Animation→Effect/Sound從屬，尚無skill→hit事件鏈 | 目標／範圍、傷害交T12／既有Server契約、權威事件與結果同步；未知wire另補證 |
| W2-SRV-07 冷卻 | 施放或取消後按規則再次可用 | 54F270只是predicate；11WORD沒有SkillActive直接row | 時間單位、起算／取消／重設與next-usable狀態，不沿用v41或玩家fixture猜值 |
| W2-SRV-08 受傷 | 怪物受擊後按設定反應 | ATTACKED及其他受擊樣式引用、重複clip alias與原始Repeat | 硬直、免疫、取消／打斷／恢復與狀態轉移；不修改既有玩家連段核心 |
| W2-SRV-09 死亡 | 死亡結算、任務／掉落通知、移除與呈現分工 | ID7→DEAD及DEAD.wav的直接來源 | 一次性死亡權威與結算、事件順序、重複處理防護、移除條件，與T16/W1串接 |

原始presentation、Server policy、runtime state應分開；相同FILE不自動保證跨PRE規則相同。可選`.gb3/.eff`補件不應成為上述Server自主設計的停止理由；未知Client必要格式也不能因Server政策可以自定就被猜填。

## 6. 跨功能整合與待遊玩驗證

- **W1／場景生怪**：把已確定的ActorResourceKey接到合法場景node、群組與spawn錨點。群組ID、ActorID、PRE、matrix CharID與world entity ID保留各自型別；Cluster出現／COUNT不直接等於世界出生座標。
- **T10/T11／戰鬥**：重用已有來源、適用條件及更正的共同接口。矩陣與ABF取得不證明目標／出招時機，不藉此修改連段核心或解除T10退回。
- **T16／任務**：既有runtime包仍為`DRAFT_BLOCKED`；W2 JSON不是原生MEF，動畫播放也不等於任務完成或正式啟用。
- **T01／S00**：資源SHA／Git blob只證身分與版本；本輪沒有新FULL-PASS、RRACCEPTED、S00APPROVED、SPECSTABLE或native_complete。由T01按有界原生主張審查，S00按Server玩家情境採用需求。

待對應Server實作就緒後，由S00安排三怪正確FILE/PRE／動作載入、追逐／起手／命中／受傷／死亡、技能結果與Server狀態一致、清怪／任務／出口接續的正常遊玩驗收。**本輪runtime為NOT_RUN**；XML／hash／資料檢查不證動畫實際播放、原版AI或可玩性，也不要求使用者立刻補拍。
