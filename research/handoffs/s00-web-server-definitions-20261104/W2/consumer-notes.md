# W2 consumer 證據與使用邊界 — v2

**本輪已取得並直接核對三個 Actor body 與 11 個 MonsterMatrices cell；資料盤點完成，技能到動作的原生橋接及 Server 規則仍分別保留未知。** 本稿以新上傳 `Base.stp`、已取得的 `07-Table.stp` 解出原件，更新初版 ZIP-only 範圍；以下現況不再把矩陣或三個 body 列為缺件。

本輪完整讀取三個 ABF XML，解析並逐列核對目標 MonsterMatrices 原始資料；既有 T10/T11 報告仍以 **SOURCE_REPORT_PARTIAL** 使用。沒有執行歷史腳本、BIN、遊戲或 Server，沒有新增 loader／MEF 追查。直接資源值不構成 native consumer 複驗、T01 FULL-PASS、S00 核准或可玩驗收；九個 AI 決策／判定欄位的 `value`、`unit` 仍為 `null`，原件提示另列。

舊 `git-evidence/` 的來源分析 commit 為 `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`，先前 provenance audit 已核對 110 件 exact Git blob；新 raw carrier 以各自 SHA256 綁定，未放入 Git。原 ZIP manifest 的 local variant／`original_member_sha_match` 欄位保留歷史原值；本輪另由精確 `07-Table.stp` member bytes 證明五表與 ZIP 副本一致，不再將先前 manifest 未收錄當成永久無法核對。文內 `[Sx:行]` 對應末尾來源登錄與同目錄 [source-index.json](source-index.json)。

## 1. 三個目標：精確 body 已取得，runtime binding 未擴大

| ActorID | OBJCATEGORY | PRE 原值 | `_ActorList FILE` | 本次 exact Base member |
| --- | --- | --- | --- | --- |
| 1001 | 1 | 1, 2, 3, 6, 7 | `00_HokyPoky` | `Mon/00_HokyPoky.abf` |
| 1009 | 1 | 1, 3, 4 | `01_Moose` | `Mon/01_Moose.abf` |
| 1004 | 1 | 1, 2, 3, 6 | `01_Nepenths` | `Mon/01_Nepenths.abf` |

以上 12 個 `(OBJCATEGORY, ACTOR ID, PRE)` 資料鍵來自 `_ActorList` 原始列。[S1:32–36,48–51,72–74] 三個檔名與 FILE stem 精確相符；`Base.stp` index 與 decoded hash 已核對。因此 carrier、body member、副檔名及 body SHA 的資源缺件已解除。但 **ABF 本身沒有 ActorID 或 PRE**，精確 stem／filename 對上不等於每條 PRE runtime loader 路徑都已驗證，也不證明各 PRE 共用技能或 AI 政策。[S20:1–39; S21:1–41; S22:1–41]

`Base.stp`：946,961 bytes，SHA256 `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957`。完整 index／830 stored block MD5 的稽核見 [base-stp-audit.json](base-stp-audit.json)；本 consumer review 獨立重算 carrier 與三個 decoded SHA，並完整解析 body。該完整 index 核對不代表其餘 827 個 body 已做語意分析。

| Actor | carrier / exact member | decoded bytes | decoded SHA256 |
| --- | --- | --- | --- |
| 1001 | `Base.stp!Mon/00_HokyPoky.abf` | 3744 | `3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633` |
| 1009 | `Base.stp!Mon/01_Moose.abf` | 3931 | `d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b` |
| 1004 | `Base.stp!Mon/01_Nepenths.abf` | 4018 | `6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71` |

### 1.1 全部 47 個動畫項目

三個 `Character@RelativePath` 依序是 `00_HokyPoky/`、`01_Moose/`、`01_Nepenths/`；`BaseFile` 依序是 `HokyPoky_BASE.gb3`、`Moose_BASE.gb3`、`Nepenths_BASE.gb3`。[S20/S21/S22:3] 下表保留每個 Animation 的 `File` 與 `Repeat` 原字面值，**不先把 ID 命名為已證 wire motion ID 或 Server 狀態**。

| Animation ID | 1001 HokyPoky：File / Repeat | 1009 Moose：File / Repeat | 1004 Nepenths：File / Repeat |
| --- | --- | --- | --- |
| 1 | `HokyPoky_WAIT01.gb3` / `1` | `Moose_WAIT01.gb3` / `1` | `Nepenths_WAIT01.gb3` / `1` |
| 3 | `HokyPoky_WAIT01.gb3` / `1` | `Moose_WAIT01.gb3` / `1` | `Nepenths_WAIT01.gb3` / `1` |
| 4 | `HokyPoky_MOVE01.gb3` / `1` | `Moose_MOVE01.gb3` / `1` | `Nepenths_WAIT01.gb3` / `1` |
| 6 | `HokyPoky_MOVE01.gb3` / `1` | `Moose_MOVE01.gb3` / `1` | `Nepenths_WAIT01.gb3` / `1` |
| 7 | `HokyPoky_DEAD.gb3` / `0` | `Moose_DEAD.gb3` / `0` | `Nepenths_DEAD.gb3` / `0` |
| 8 | `HokyPoky_WAIT01.gb3` / `1` | `Moose_STUN.gb3` / `1` | `Nepenths_STUN.gb3` / `1` |
| 9 | `HokyPoky_ATTACKED.gb3` / `0` | `Moose_ATTACKED.gb3` / `0` | `Nepenths_ATTACKED.gb3` / `0` |
| 10 | `HokyPoky_LIE.gb3` / `0` | `Moose_LIE.gb3` / `0` | `Nepenths_ATTACKED.gb3` / `0` |
| 11 | `HokyPoky_KNOCKED.gb3` / `0` | `Moose_KNOCKED.gb3` / `0` | `Nepenths_ATTACKED.gb3` / `0` |
| 12 | `HokyPoky_AERIAL.gb3` / `0` | `Moose_AERIAL.gb3` / `0` | `Nepenths_ATTACKED.gb3` / `0` |
| 13 | `HokyPoky_A01_RISE.gb3` / `0` | `Moose_B01_RISE.gb3` / `0` | `Nepenths_WAIT01.gb3` / `0` |
| 14 | `HokyPoky_PULLED.gb3` / `0` | `Moose_PULLED.gb3` / `0` | `Nepenths_ATTACKED.gb3` / `0` |
| 27 | `HokyPoky_A02_RISE.gb3` / `0` | `Moose_B02_RISE.gb3` / `0` | `Nepenths_WAIT01.gb3` / `0` |
| 35 | `HokyPoky_WAIT01.gb3` / `0` | `Moose_WAIT01.gb3` / `0` | `Nepenths_WAIT01.gb3` / `0` |
| 101 | `HokyPoky_SKILL01.gb3` / `0` | `Moose_SKILL01.gb3` / `0` | `Nepenths_SKILL01.gb3` / `0` |
| 102 | 無此 ID | `Moose_SKILL02.gb3` / `0` | `Nepenths_SKILL02.gb3` / `0` |

三者共 47 個 Animation、30 個不同 `.gb3` clip 引用：HokyPoky 15 項／11 clips；Moose 16 項／13 clips；Nepenths 16 項／6 clips。全部 Animation 的共同原字面值為 `FrameSpeed="40.000000"`、`CameraAttach="false"`、`FaceIndex="0"`、`RepeatStartFrame="0.000000"`、`LagtimeType="LightMelee"`。[S20:10–33; S21:10–35; S22:10–35]

原始資料只證明這些屬性存在，**FrameSpeed 的單位未經 native consumer 證明，不能直接改名為已證 40 FPS**。三個 body 沒有 clip 總幀數、duration、起手／命中 frame 或 Effect／Sound 啟動時間欄位，`fps/frame_count/duration_seconds/hit_time` 均保持 null。`LightMelee` 同時出現在 WAIT、DEAD、SKILL 等項目，不能當作共同硬直／冷卻時間。

HokyPoky 的 ID8 仍引用 WAIT01，Moose／Nepenths ID8 引用 STUN；Nepenths ID4/6 仍是 WAIT01，ID9/10/11/12/14 共用 ATTACKED，ID13/27 共用 WAIT01。這些 alias 是已知資源關係，不能推成不移動、相同受傷／打斷規則或相同 runtime 狀態。相同 WAIT01 也可分別有 `Repeat=1` 與 `Repeat=0`，不能只看檔名決定播放旗標。

### 1.2 Animation 到特效／音效的直接 XML 關係

下表是 `Animation` 的直接 `Effect` child，Folder 與 File 保留原始大小寫。這是**資源從屬關係**，不是技能 WORD 對應、特效觸發時間或傷害事件。

| 原樣 Folder＋File 引用 | 所屬 Actor / Animation ID | 原始 body 行 |
| --- | --- | --- |
| `Effect/Assist/State/S_State-BasisDisband01.eff` | 1001 / 35, 1009 / 35, 1004 / 35 | 00_HokyPoky.abf:28, 01_Moose.abf:26, 01_Nepenths.abf:26 |
| `Effect/Monster/M_HokyPoky-AttacK01.eff` | 1001 / 101 | 00_HokyPoky.abf:31 |
| `Effect/Monster/M_Moose-AttacK01.eff` | 1009 / 101 | 01_Moose.abf:29 |
| `Effect/Monster/M_Moose-AttacK02.eff` | 1009 / 102 | 01_Moose.abf:33 |
| `Effect/Monster/M_Nepenths-AttacK01.eff` | 1004 / 101 | 01_Nepenths.abf:29 |
| `Effect/Monster/M_Nepenths-AttacK02.eff` | 1004 / 102 | 01_Nepenths.abf:33 |

音效 child 亦已直接取得：三者 ID7 分別引用對應 `Sound/Monster/<名字>/<名字>_DEAD.wav`；HokyPoky ID9 與 ID101 共用 `Sound/Monster/HokyPoky/HokyPoky_SKILL01.wav`；Moose／Nepenths ID101、102 分別引用其 SKILL01、SKILL02.wav。[S20:14–19,30–32; S21/S22:14–15,28–34] 音效檔名同樣不證明命中或死亡權威時點。

三 body 總共 70 個資源引用出現、50 個去重引用（30 clips、3 base models、6 effects、8 sounds、3 textures）。這些引用在本次 Base 完整 index 中沒有 exact literal／basename match；此否定只適用這個 carrier，其他 archive 未查。`RelativePath+File` 先保留為相對引用，`Folder+File` 保留為明確文字路徑；都不能無證據指定下一層 carrier 或稱已開啟相應 asset。

## 2. 三怪矩陣已直接核對，skill→action→effect 仍無橋接

`07-Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` 中，`Table/Skill/Matrix/MonsterMatrices.xml` 已解出並直接解析，decoded SHA256 `d83b2f311c8ab21779a6bde0371cd05d91b9c840588ad97002a6e64dcbd43539`。目標原始列如下；不再把 1001 的三列只當舊報告提示，也不再聲稱 1009／1004 沒有具體矩陣值。[S23]

| Actor／CharID | Matrix ID | tier | key | skill WORD | 原始 XML 行 |
| --- | --- | --- | --- | --- | --- |
| 1001 | 0 | 0 | 1 | 76 | 39 |
| 1001 | 0 | 0 | 2 | 307 | 40 |
| 1001 | 0 | 0 | 3 | 371 | 41 |
| 1009 | 0 | 0 | 1 | 92 | 132 |
| 1009 | 0 | 0 | 2 | 1593 | 133 |
| 1009 | 0 | 0 | 4 | 93 | 134 |
| 1009 | 0 | 0 | 5 | 1594 | 135 |
| 1004 | 0 | 0 | 1 | 80 | 71 |
| 1004 | 0 | 0 | 2 | 309 | 72 |
| 1004 | 0 | 2 | 1 | 81 | 75 |
| 1004 | 0 | 2 | 2 | 455 | 76 |

三者都使用已觀察的 `Matrix ID=0`；1004 有 tier0、tier2，其餘目標只有上述 tier0 列。此處列出這三個 `SkillMatrix` 的完整 cell；**`Actor PRE`、`Matrix ID`、`tier`、`key`、`skill WORD` 分別保留型別**，資料沒有提供 PRE→Matrix/tier 的映射。[S23:36–44,68–79,129–138]

`Table/Skill/Matrix/CharacterMatrices.xml` 亦已取得、SHA 符合前次 archive audit，屬完整 import／hero 比較來源；取得它並不解除普通怪物的 native consumer 邊界。[S24]

### 2.1 數字／資源域的反例

| 直接核對 | 結果 | 不可作的推論 |
| --- | --- | --- |
| 11 個 WORD vs `CharSkill/SKILL@ID` | 325 個引用中交集為空；CHAR仍為1..9 | 不能用CHAR/GROUP或其他同號值補怪物定義。[S2:1–400] |
| 11 個 WORD vs `SkillActiveTable/SKILL@no` | 469個SKILL中交集為空 | 該表未直接提供這11個技能的cooltime／cost；不能說整個Client沒有技能資料。[S3:1–7911] |
| 11 個 WORD vs各自ABF的Animation ID／attribute value | 沒有字面相等映射，亦無skill／matrix／PRE binding欄位 | 不能將key、WORD、順序或100+key當成Animation ID，更不能直接當wire motion ID。[S20–S23] |
| Moose WORD92 vs IndependentSkillEffect Index92 | Index92存在，但`File=""` | `effect_index_present=true`只表示同數字的另一域有列，不等於有可播放技能特效。[S5:71] |
| Moose WORD93 vs IndependentSkillEffect Index93 | File=`B_Self-BasisDestructionTrap01.eff` | 不等於Moose技能93的效果。Moose body直接children是`M_Moose-AttacK01.eff`、`M_Moose-AttacK02.eff`。[S5:72; S21:28–34] |

HokyPoky 有 3 個矩陣 WORD，但只有 1 個 SKILL-named Animation（ID101）；Moose／Nepenths 各有 4 個矩陣 WORD，卻各只有 2 個 SKILL-named Animation（ID101／102）。這已足以反對按序一對一 zip 的作法，但也不證明某些技能不存在或共用哪一個動作。**目前可成立的是兩組各自帶來源的集合：矩陣 cell 集合，與 Animation→clip/effect/sound 關係；連接兩者的 provider／consumer 仍未知。**

IndependentSkillEffect的92/93數字交集如實保留；全部6個body效果File與該表的File沒有exact相同引用。本次可直接從body列出效果，不必把它們硬塞進IndependentSkillEffect.Index域。Effect child只有File／Folder，未給觸發幀數、傷害／命中參數或server cooldown。[S5; S20–S22]

舊比較報告的1001矩陣值與兩個模型的MOVE／WAIT引用得到本次原件對照，但舊報告其他native語意、全表XML搜尋例外與monster controller未知邊界仍保留；局部資源值吻合不會使整份報告FULL-PASS。[S6:18–49,67–78]

## 3. 已報告 native consumer 的有界內容

下表的邊界與地址是讀取歷史報告／稽核文字所得，沒有在本輪開啟或執行原始 BIN。`endExclusive` 為歷史腳本明列；未明列者不補邊界。八個主要 bounded functions 的原始反組譯輸出並未隨此包提供，腳本本身不能取代機器碼。[S7:3–7; S8:2–3,55–56; S9:28–36]

| 入口／範圍 | 歷史已報告內容 | W2 可採用限制 |
| --- | --- | --- |
| `40F7F0` | 回傳矩陣 singleton `FAB27C` | 只作資料入口；完整邊界未在本稿來源中列出 [S6:53] |
| `48D0A6 / 48D0B8 → 8180C0` | `C52F74` 是 `Table/Skill/SkillMatrix.xml`；MatrixInfo loader 主尾端 `81842C ret1C` | loader 有尾分支，不用第一個 ret 當全體結束；這些敘述不是怪物 controller [S6:54–56,62–65] |
| `818430` | 解析 MatrixList／SkillMatrix／CharID／Matrix；`81895D/8189DC` 以 WORD 保存 CharID | 這段載入並非只限1..9；不證明 ID 到 Actor PRE 的關係 [S6:57–58] |
| `819220..819278` | 依兩個索引尋找矩陣 | 資料 lookup，不會自行選目標或出招 [S6:59; S9:34] |
| `81A8E0..81A909` | `tier<4, key<11`，回傳 `WORD(matrix+4+2*(tier*11+key))` | 值域／布局有界；選哪個 tier/key 的 monster producer 未證 [S7:11–14; S9:35] |
| `549980..549C51` | input+50 actor、model WORD+88 必須 `<=9`；檢查 hero record、矩陣鍵、資源與可用性 | 玩家／隊友 SubAI 條件，不選敵亦不產生怪物技能命令 [S7:21,34–40; S9:28] |
| `54AE70..54AE92` | `CSkillCheckCondition@SubAI` virtual+4；傳 tier/key/options/context 至549980，布林化回傳 | 不能接上怪物矩陣就稱已啟用怪物 AI [S7:34–40; S9:29] |
| `54F270..54F330` | skill flags→key、矩陣查找、cooldown remaining 檢查 | availability predicate；不是冷卻起算、選招、目標、播放 [S7:44–54; S9:30] |
| `54F330..54F466` | inline tree lookup8195E0/8196D0，驗 tier/key，複製16 bytes cooldown entry | UI snapshot；不是冷卻起算或攻擊產生器 [S7:56–61; S9:31] |
| `61C7C0..61CAB3` | `61C82C/82F` 排除 model>9；ret61CAA9 後仍有61CAAC分支及61CAB1 jump | hero skill-list；caller chain 只有視窗證據 [S7:25,70–72; S9:33] |
| `52CCC0..52CD0C` | 使用 `this+30` 呼叫8195E0，再走52D110；不是FAB27C | 同 STL helper 不足以證同一資料域 [S7:63–68; S9:36] |

### 六個 819220 raw indexed direct-call candidates

| Callsite | Consumer | 檢視範圍與限制 |
| --- | --- | --- |
| `470715` | `4704C0` practice/talent list | helper 至470A36曾在候選視窗檢視；索引caller410250=`CBuyPracticeTalentWnd` vD0；完整caller graph未審 [S7:20] |
| `549A7F` | `549980` SubAI condition | bounded function，有model<=9 gate [S7:21] |
| `54F2E0` | `54F270` availability | bounded function，自身沒有<=9 gate；仍未證 monster cooldown instance [S7:22,54] |
| `5CD806` | `5CD520` bottom menu | 大helper仍是候選視窗；caller5CEAB0=`CBottomMenuFrame` v198；input來自controller v1C index0 [S7:23] |
| `60F330` | `60F120` tooltip | 未完整定界helper；model<10／hero stride210；caller60D820=`CSkillSlotToolTip` v184 [S7:24] |
| `61C898` | `61C7C0` skill list | bounded function拒絕model>9；61C660／61BFD0 caller鏈只有視窗證據 [S7:25] |

六個 candidate 不是所有 runtime consumer。計算呼叫、inline、alias、外部模組均未排盡；RTTI object 名稱不等於其每個 caller 的完整目的證明。[S7:27–30]

### 54F270／54F330 必須分開

`54F270` 報告的映射是 flags1/2/4→key1/2/3，flags3/5/6→key4/5/6，bit0x08→key7，bit0x10→key10；涉及0xC0或無法識別 flags 的路徑會提前回 available。其資料來自 object+2 的 model WORD、傳入 variant/tier、object+4 的 cooldown entry；比較 entry+4 的 remaining DWORD 是否為0。這只回答某個輸入旗標是否可用，不給冷卻秒數或起算／重置政策。[S7:44–50]

它的四個 indexed callers 是 `5462DD/54827F/549C0E/549D54`，仍在先前 primary／formation hero-input／SubAI 路徑，未證普通怪物有同一 cooldown object。[S7:52–54] `54F330` 的三個 indexed calls `5CDD2F/5CDEB0/5CE0A7` 則在 bottom-menu helper5CD520內，複製16 bytes供UI。[S7:56–61]

T01 必須保留的更正：**`549D54 → 54F270` 屬獨立入口 `549C60`，不屬 `549980`。** 549980正常返回在549A34／549C4E；`549C60 = 55 8B EC 83 E4 F8` 為獨立序言；`549D54 = E8 17 55 00 00`。舊T10-026的局部state=4並未因更正消失，但 caller／實參與writer歸屬必須從正確入口解讀；既有 `T01-RETURN-T10-026-001 — NEEDS_FIX` 不因本稿引用而解除。[S12:20–27; S10:76–82]

## 4. 原件提示與九項 Server AI 開發需求

三怪的追逐、感知、回位、選招、起手、命中、冷卻、受傷、死亡，**AI決策／判定值仍全部是無來源、value=null、unit=null**。這不否定新取得的47動畫、11矩陣cell、具名effect／sound或DEAD／ATTACKED呈現引用；它們是分開保存的直接資源值。

| AI欄位 | 現有直接來源提示 | 仍須S00設計的Server契約 |
| --- | --- | --- |
| 追逐 | 1001／1009 ID4/6指MOVE01；1004指WAIT01 | 速度、路徑、接近／停止條件、移動權威。WAIT不證永不移動。 |
| 感知 | 三body與矩陣未給感知／仇恨欄位 | 有效目標、範圍／視線、仇恨與更新條件。 |
| 回位 | FILE／RelativePath是資源路徑，無world spawn anchor | leash、回位路徑、仇恨／HP重設，與W1生怪串接。 |
| 選招 | 11個型別化matrix cell；1／2個SKILL-named動畫 | 技能provider接入、可用性、權重／優先序／距離政策；禁止猜接動畫。 |
| 起手 | FrameSpeed40與SKILL01/02引用已知，fps／duration未知 | windup／commit／interrupt時點，與呈現同步策略。 |
| 命中 | Animation有明確Effect／Sound child | 目標／命中／傷害權威與結果同步；Effect child不是命中事件。 |
| 冷卻 | 11WORD無SkillActive直接row；54F270仍只是可用性檢查 | 時間單位、起算／取消／重設規則及next-usable狀態。 |
| 受傷 | 三者ID9引用ATTACKED；Nepenths另有多ID alias | 硬直、免疫、打斷／恢復與狀態轉移；檔名不決定時序。 |
| 死亡 | 三者ID7指DEAD並有DEAD.wav | 一次性死亡權威、結算／掉落／任務事件／移除順序。 |

這九項應作 **Server 開發需求** 交S00，不必先還原官方Server演算法。可先建立可配置狀態／政策介面，政策值須獨立標示並由S00決議；本稿未提供官方猜值。真正未知的Client wire／parser／action consumer、PRE選擇與skill WORD→Animation bridge仍列Client待逆向，不得為推進Server就猜填wire。

`.gb3/.eff/.wav/.dds` 的後續查閱目前屬 **P2 OPTIONAL_PRESENTATION**，不阻擋本輪資源盤點或Server自主AI規則設計。未來即使取得clip總長／播放時間，也不能自動填為Server起手、命中、冷卻、受傷取消或死亡移除時點。完整來源與解除條件見 [unknowns.md](unknowns.md)。

`MAIN-PROGRAM-FUNCTION-MAP` 對 `CMonster 4D1710 / 4D1AF0 / 4C87D0` 的建立／更新／模型陣營顯示界線仍適用；owner/update欄位不等於AI權威。隊友框架548FF0／8092C0未因取得ABF就證實普通怪物接入，`monster-ai`68個候選標籤仍不等於68支已確認怪物AI。[S16:92–107]

### 排除的自製值

`107acb…` 是歷史本機 `tutorial_skill_cast.py` 實作文字；其中 `HOLD_TIMEOUT=.4`、`CHAIN_WINDOW=.65`、非基本攻擊額外`.1` padding、以`duration_seconds`做deadline均不能當官方怪物值。[S15:9–12,38–49] T10 README 明確說 `.65` 與Server續段排程是自製、官方連段／取消窗口仍未知。[S10:103–109] T11亦將本機實作標為AI替代，官方冷卻與消耗裁決不完整。[S11:17–23] 兩份技能矩陣報告也說當時部署v41仍是自製AI。[S6:78; S7:3–7] 本輪未採用這些值，未修改連段核心。

## 5. 取得狀態與目前最小未解邊界

| 項目 | v2狀態 | 可採用／仍限制 |
| --- | --- | --- |
| M01 MonsterMatrices | `ACQUIRED_AND_VERIFIED` | exact Table member、SHA與11目標cell均已直接核對；PRE mapping仍獨立未知。 |
| M02／M03／M04 三個Actor body | `ACQUIRED_AND_VERIFIED` | exact Base member與SHA、47動畫／child引用已取得；不再是stem-only缺件。 |
| M06 CharacterMatrices | `ACQUIRED_AND_VERIFIED` | import來源已閉合；不把hero consumer移作Monster AI。 |
| M05 Monster metadata provider | 來源角色未解，檔名／carrier仍null | 不能編造Monster.xml；Server政策可先獨立設計，必要Client參數仍須已證consumer。 |
| M07 skill WORD→definition/action provider | 來源角色未解，檔名／carrier仍null | 11WORD與body兩端已有；中間typed bridge仍未知，不能用同數字、key順序或檔名SKILL01硬接。 |
| 6效果／30clip引用 | `P2 OPTIONAL_PRESENTATION` | 效果有精確Folder+File；clip有精確RelativePath+File。carrier與actual archive member未證，不是本輪Server AI必需原件。 |

70個引用出現與50個去重資源均可在 [base-stp-audit.json](base-stp-audit.json) 查到來源body、SHA、行、selector及原字面。聲音／貼圖／base model同屬可選呈現範圍；本輪沒有把它們變成AI規則的先決條件。CSV列出的資源角色、已取得項目、可選引用要按狀態解讀，不能把列數當成尚缺多少個必需檔案。

現階段必要的資訊界線是：**PRE如何選matrix、skill WORD的typed provider／Animation或action consumer、需要的Client相容輸入／輸出、以及S00應制定的九項Server政策。** 缺下層視覺／聲音asset，不是拒絕Server自主規則開發或停止本輪盤點的理由；不為此展開新BIN／MEF／loader搜尋，也不要求使用者自行找檔。

## 6. 審核狀態與反證範圍

本次新資源完整性與XML欄位核對屬 `BOUNDED_DIRECT_RESOURCE_AUDIT`；與下列歷史native審核、S00政策核准、Server實作及可玩驗收分開。

- S6是五樣本及有解析例外的歷史報告；S7/S8是8個有界函式與raw indexed call候選，未覆蓋完整runtime／caller graph；S9只讀歷史腳本，未執行。均不能提升FULL-PASS。
- S12的2026-10-29檢查點：98份來源全文certified **0**、4原版本有原生反證、94 PARTIAL；11份來源中的14個限定FULL-PASS主張不等於11份全文通過。[S12:48–52] 本稿不將這4份錯誤泛化為整個T10或本次所有報告FAILED。
- 更新的T01 2026-11-03批次只有R0全件收件與選定R2 anchors，明列不代表新NATIVE_VERIFIED／FULL-PASS；T10七項退回狀態保留，沒有RRACCEPTED、S00APPROVED、SPECSTABLE、Server試跑或人測。[S13:77–83]
- packaged source-review-status是有界來源索引；provenance audit對17件packaged kr/evidence精確digest均未找到索引列。這只能說該snapshot無精確join，不能聲稱這些來源從未在別處審過，也不能反向視為通過。[S14:1–4]

## 來源登錄

所有package path均相對上傳ZIP根目錄；原始資源只在輸入包與使用者提供的原件解出目錄中唯讀使用。本稿不複製原始XML／ABF到Git。表內Git blob只適用`git-evidence/`，raw member用SHA256並在source-index保留carrier聲明。

### S1

- Package path: `local-resources/Table/_ActorList.xml`
- SHA256: `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7`
- Member: `Table/_ActorList.xml`；original match: `True`。

### S2

- Package path: `local-resources/Table/CharSkill.xml`
- SHA256: `604a22ddf9cb297bcfe14481fb8f96d2a2379dc20298fb6ac337378360947d64`
- Member: `Table/CharSkill.xml`；original match: `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`。

### S3

- Package path: `local-resources/Table/SkillActiveTable.xml`
- SHA256: `1ea831f270df757d760f4ff87d6bf509a64326a23614a305c8d767580f2a2139`
- Member: `Table/SkillActiveTable.xml`；original match: `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`。

### S4

- Package path: `local-resources/Table/Skill/SkillMatrix.xml`
- SHA256: `8c58ea135c94dc2c6056a3e408cad76a79c1857d72e37b43e2b9b8869c897dc4`
- Member: `Table/Skill/SkillMatrix.xml`；original match: `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`。

### S5

- Package path: `local-resources/Table/IndependentSkillEffect.xml`
- SHA256: `a1e8be8e36a2feddf7eecaf6d006c45b1ae9e6f8b915072525f3b5f0c91e0070`
- Member: `Table/IndependentSkillEffect.xml`；original match: `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`。

### S6

- Package path: `git-evidence/kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt`
- SHA256: `3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2`
- Git blob SHA1: `617c8aa9ffca3989f36ccb80ede9608d1b6911e8`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S7

- Package path: `git-evidence/kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt`
- SHA256: `d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585`
- Git blob SHA1: `d74fb642bd8b028d8e23ddabf07ddbf12b09661a`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S8

- Package path: `git-evidence/kr/evidence/a26a83997b086fba1532b174451358cbf197825ea9f9d7800fd51529e53ec646.txt`
- SHA256: `a26a83997b086fba1532b174451358cbf197825ea9f9d7800fd51529e53ec646`
- Git blob SHA1: `1444598c7539453aa29750dd2d934b9430d95cce`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S9

- Package path: `git-evidence/kr/evidence/76c6266ea4969307f261c2757611062af506f2a43cba151b6680b33de87530c1.txt`
- SHA256: `76c6266ea4969307f261c2757611062af506f2a43cba151b6680b33de87530c1`
- Git blob SHA1: `d16911b2c00022d1f60f45752e33c66c12a36d2a`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S10

- Package path: `git-evidence/kr/tasks/T10/README.md`
- SHA256: `621686bd88a74372e23d53d5819c12485faa9808bbfdd642303082e26bd71161`
- Git blob SHA1: `a409f168e9a67ae1cf6ba76393aad08a9caf37ad`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S11

- Package path: `git-evidence/kr/tasks/T11/README.md`
- SHA256: `b3df913497dcdf3eec28c01bf0fc501f427fd5df20e400494e9b88a0887a5f12`
- Git blob SHA1: `a6b1294c755802a82ad9e9f2cb366a0627d17346`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S12

- Package path: `git-evidence/shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md`
- SHA256: `8f3ec4620c9b709a222aa971813390670ed4d038d9cca5d67b8084a72600f275`
- Git blob SHA1: `885a6ea68235045b2cb3b284218a27ce00b449e7`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S13

- Package path: `git-evidence/research/handoffs/t01-20261103-t10-t16-native-review/README.md`
- SHA256: `5b6c9e67c1577628b21f5e03494e44d6c6135af4c7e6d29de317ed3c1eefa604`
- Git blob SHA1: `959c857b70287c10d57edf076b1430b9e6c483a4`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S14

- Package path: `git-evidence/shared/source-review-status.json`
- SHA256: `d206a1bdae6b20cdddddce470cce4eef26a3b8860db53be398b77b24c034cd2d`
- Git blob SHA1: `85d93a86b928028494be218581db558250eb427a`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S15

- Package path: `git-evidence/kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt`
- SHA256: `107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48`
- Git blob SHA1: `1825da3a535f6e3c22b2f1c82f3082aa16d1b5d9`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S16

- Package path: `git-evidence/kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt`
- SHA256: `546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f`
- Git blob SHA1: `7f34d03292a8d674b36f37235f399df09b4a6657`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S17

- Package path: `START-HERE.md`
- SHA256: `4522cc77e55b440c21a813eb4229f1cf142d2a1be7993fc7780b07a6a96c4e43`

### S18

- Package path: `git-evidence/research/handoffs/s00-web-server-definitions-20261104/W2-PROMPT.md`
- SHA256: `7c2a9d488397077d40f2e51e6bae31018a3c8f4d43c33324903420510e38ff21`
- Git blob SHA1: `77a069955ecf34efed0f013e18bd8318bea75bed`；source commit: `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。

### S19 — 新上傳 Base carrier

- 原件：`Base.stp`；946,961 bytes。
- SHA256：`1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957`。
- exact archive/member證據：[base-stp-audit.json](base-stp-audit.json)。本稿獨立核對carrier SHA及三個decoded body；其餘member只有peer index/hash核對，不宣稱語意全讀。

### S20 — Actor 1001 body

- Carrier/member：`Base.stp!Mon/00_HokyPoky.abf`。
- Decoded SHA256：`3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633`；3744 bytes，39行。
- 本輪完整文字與XML節點均已讀取；保留EUC-KR宣告及原bytes，原件不入Git。

### S21 — Actor 1009 body

- Carrier/member：`Base.stp!Mon/01_Moose.abf`。
- Decoded SHA256：`d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b`；3931 bytes，41行。
- 本輪完整文字與XML節點均已讀取；保留EUC-KR宣告及原bytes，原件不入Git。

### S22 — Actor 1004 body

- Carrier/member：`Base.stp!Mon/01_Nepenths.abf`。
- Decoded SHA256：`6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71`；4018 bytes，41行。
- 本輪完整文字與XML節點均已讀取；保留EUC-KR宣告及原bytes，原件不入Git。

### S23 — MonsterMatrices 原件

- Carrier：`07-Table.stp`，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
- Member：`Table/Skill/Matrix/MonsterMatrices.xml`。
- SHA256：`d83b2f311c8ab21779a6bde0371cd05d91b9c840588ad97002a6e64dcbd43539`；386,194 bytes，11,659行。
- 完整XML解析；本consumer review的語意範圍是CharID1001／1009／1004全部11個cell，不聲稱全部877個SkillMatrix的consumer皆已驗證。

### S24 — CharacterMatrices 原件

- Carrier/member：`07-Table.stp!Table/Skill/Matrix/CharacterMatrices.xml`。
- SHA256：`78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad`；90,731 bytes。
- 取得與identity核對依 [table-stp-presence-audit.json](table-stp-presence-audit.json)；在本稿僅用於import取得狀態，不轉成monster consumer證據。
