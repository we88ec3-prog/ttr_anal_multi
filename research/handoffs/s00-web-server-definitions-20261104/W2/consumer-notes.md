# W2 consumer 證據與使用邊界

本稿只閱讀上傳包中的 XML、既有 T10/T11 報告、歷史稽核程式文字及 T01 更正。沒有執行歷史腳本、BIN、遊戲、Server；沒有新作 loader／MEF 追查。表格值可供資料盤點；既有原生分析只以 **SOURCE_REPORT_PARTIAL** 轉述，不構成本輪獨立原生複驗、FULL-PASS 或正式規格核准。九個 AI 欄位的數值均保持 `null / 無來源`；Server 應透過 S00 制定相容政策。

來源包宣告 `source_analysis_commit=fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。協作中的 provenance audit 已用 exact Git blob 核對全部 110 件 `git-evidence/` 副本；本稿仍只針對已讀內容下結論。Table carrier 是 local variant，不能因包完整性相符就一律稱原版表。文內 `[Sx:行]` 對應末尾來源表，行號只用於本筆記內精確定位；完整來源索引由同目錄 `source-index.json` 提供。

## 1. 三個目標與 Actor／ABF 邊界

| ActorID | OBJCATEGORY | PRE | FILE 原值 | 可證範圍 |
| --- | --- | --- | --- | --- |
| 1001 | 1 | 1, 2, 3, 6, 7 | `00_HokyPoky` | `_ActorList` 5 列；只取得 stem [S1:32–36] |
| 1009 | 1 | 1, 3, 4 | `01_Moose` | `_ActorList` 3 列；只取得 stem [S1:72–74] |
| 1004 | 1 | 1, 2, 3, 6 | `01_Nepenths` | `_ActorList` 4 列；只取得 stem [S1:48–51] |

`_ActorList` 的 `(OBJCATEGORY, ACTOR ID, PRE)` 必須保留為型別化資料鍵；表中的 `FILE` 不含目錄或副檔名。包內無原始 Actor／ABF body，亦無足以證明這三個 stem 如何拼成實際 archive/member 的原生 loader 內容。**三者的 carrier、完整 member、extension 均保持未知**；不得編造 `Actor/<stem>.abf` 或 `Actor/Monster/...`。Manifest 對 `_ActorList` 標 `original_member_sha_match=true`，其餘四份技能／效果相關表標 `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`；該原始比對欄不能延伸到缺失 body。[S17:7–9]

既有比較報告稱查過五個 ABF，但只給模型標籤與兩個目標的局部動畫引用：[S6:18–35]

| 目標 | 歷史報告給出的引用 | 本輪不得推出 |
| --- | --- | --- |
| 1001 | 動畫 index 4 → `HokyPoky_MOVE01` | 完整動作清單、frames/FPS/duration、追逐或位移政策 |
| 1004 | 動畫 index 4、6 → `Nepenths_WAIT01` | 所有情境固定不動、感知／攻擊範圍或原版 AI |
| 1009 | 不在該五模型樣本內 | 不補任何動作或技能值 |

報告原文：「僅憑動畫引用不能斷言它們在所有情境都不會位移，也不能推出原版偵敵／攻击規則」。五個樣本沒有直接 AI-script 節點的觀察只對該五個樣本成立；它不是所有 Actor／ABF 的否定證明。

## 2. 技能／效果資料域

| 來源 | 本包直接可讀資料 | consumer 與跨域限制 |
| --- | --- | --- |
| `CharSkill.xml` | 9 個 `CHAR ID=1..9`、27 個 GROUP、325 個 SKILL 引用；三目標均不在 CHAR 域 [S2:1–400] | 包內未提供其 native consumer。不能用某個 SKILL ID 或 GROUP ID 數字相同替代怪物技能 join。 |
| `SkillActiveTable.xml` | 469 個 `SKILL@no`；存在 LEVEL、ACTIVEINFO hp/sp/mp/cooltime、ATTACK ratio/rev 等欄位 [S3:1–7911] | `no=76/307/371/1001/1004/1009` 均無直接匹配。`cooltime` 單位與目標怪物的 consumer 未證；不要填 0 或借其他角色數值。 |
| `Skill/SkillMatrix.xml` | 精確引用 `Table/Skill/Matrix/CharacterMatrices.xml` 與 `Table/Skill/Matrix/MonsterMatrices.xml` [S4:3–4] | 兩個被引用的 member 不在包內；只有 import 檔名是本輪第一手資料。 |
| `IndependentSkillEffect.xml` | 92 個 `Entry@Index → File`；`File` 可為空字串，非空值有 `.eff` 副檔名 [S5:1–95] | 沒有三目標 Actor 或矩陣技能 ID 到 Entry.Index 的已證 join。僅靠相同整數不可連接技能、效果、動作域；包內也未供 native consumer。 |

舊報告轉述 MonsterMatrices 有 877 個 SkillMatrix、五個模型都有配置；其中三目標只有 **1001 tier0 key1→76、key2→307、key3→371** 有明列值。[S6:39–49] 這三列可保留為 `SOURCE_REPORT_PARTIAL`，不能冒充已取得原始 MonsterMatrices。1004「有配置」不等於有可用技能清單；1009 在該樣本外。`PRE` 到 matrix variant 或 tier 的關係皆未證，不能把 PRE1 自動轉 tier0。

舊報告也直接警告跨 Table ID 搜尋有四份 XML 解析例外、不同表相同 ID 不屬同一命名空間。[S6:46–49] 本輪對 supplied SkillActiveTable 的完整解析，可支持「此一 member 無這些 SKILL no」；不能支持「整個 Client 沒有這些技能」。

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

## 4. 資料／動畫時間與 Server AI 政策

三隻怪的追逐、感知、回位、選招、起手、命中、冷卻、受傷、死亡均無目標專屬可證值，profile應標「無來源」，數字及單位為null。不得把「沒有找到」存成0，或讓空值隱含停用。既有動畫名是獨立的 `SOURCE_REPORT_PARTIAL` 提示，不能填入 AI 欄位。

即使後續取得 ABF frames/FPS/duration，也只能先表示資源／播放時間；它不自動證明 Server 的 windup、hit moment、cooldown、recovery、受傷取消或死亡 despawn 規則。命中／傷害裁決、冷卻起算、追擊條件、回位和選招屬 **Server 開發需求**：S00 應定義候選政策、所需參數、Client相容輸出與驗收；本稿不填官方猜值，也不另造成熟度或平行REQ台帳。仍缺Client wire/parser/state consumer的項目另列Client待逆向，不整批推給Server。

`MAIN-PROGRAM-FUNCTION-MAP` 也限制 `CMonster 4D1710 / 4D1AF0 / 4C87D0` 為建立／更新／模型陣營顯示證據；owner/update欄位不等於AI權威。隊友框架548FF0／8092C0尚未證普通怪物接入；`monster-ai`68個候選標籤不是68支怪物AI函式。[S16:92–107]

### 排除的自製值

`107acb…` 是歷史本機 `tutorial_skill_cast.py` 實作文字；其中 `HOLD_TIMEOUT=.4`、`CHAIN_WINDOW=.65`、非基本攻擊額外`.1` padding、以`duration_seconds`做deadline均不能當官方怪物值。[S15:9–12,38–49] T10 README 明確說 `.65` 與Server續段排程是自製、官方連段／取消窗口仍未知。[S10:103–109] T11亦將本機實作標為AI替代，官方冷卻與消耗裁決不完整。[S11:17–23] 兩份技能矩陣報告也說當時部署v41仍是自製AI。[S6:78; S7:3–7] 本輪未採用這些值，未修改連段核心。

## 5. 最小缺件與精確度

| 項目 | 精確度／已知名稱 | 尚未知 | 缺件阻擋的結論 |
| --- | --- | --- | --- |
| Monster matrix | **精確member** `Table/Skill/Matrix/MonsterMatrices.xml`，由S4:4直接引用 | 缺失member SHA；carrier實際成員身份尚未重新解出 | 三目標全部CharID／variant／tier／key與技能ID的第一手確認；取得後仍須另證PRE關係 |
| Actor1001 body | **stem** `00_HokyPoky`，PRE1/2/3/6/7 | carrier、member完整路徑、副檔名、body SHA | 完整動作／動畫／音效／效果引用及動畫時間輸入 |
| Actor1009 body | **stem** `01_Moose`，PRE1/3/4 | 同上 | 此目標目前連局部動作／技能明細也未有報告支持 |
| Actor1004 body | **stem** `01_Nepenths`，PRE1/2/3/6 | 同上 | 完整動作引用；不能由WAIT01推固定不動 |
| 已確認Monster／技能定義資料來源 | **logical requirement，檔名未解析** | carrier/member/副檔名及nativeconsumer | 目標數值、技能定義域與Client必需參數；不能虛構`Monster.xml` |

CharacterMatrices的精確member亦已知，但只屬完整import圖／hero比較的補件，非三目標最小關鍵缺件。動畫／效果下一層body必須等Actor body實際引用後再列；現有 `HokyPoky_MOVE01`、`Nepenths_WAIT01` 是動畫reference名稱，不能自行附suffix或補`ATTACK01`等猜值。不要求使用者找檔，保留給S00一次定向解包；本輪不為這些缺件展開新loader或MEF搜尋。

## 6. 審核狀態與反證範圍

- S6是五樣本及有解析例外的歷史報告；S7/S8是8個有界函式與raw indexed call候選，未覆蓋完整runtime／caller graph；S9只讀歷史腳本，未執行。均不能提升FULL-PASS。
- S12的2026-10-29檢查點：98份來源全文certified **0**、4原版本有原生反證、94 PARTIAL；11份來源中的14個限定FULL-PASS主張不等於11份全文通過。[S12:48–52] 本稿不將這4份錯誤泛化為整個T10或本次所有報告FAILED。
- 更新的T01 2026-11-03批次只有R0全件收件與選定R2 anchors，明列不代表新NATIVE_VERIFIED／FULL-PASS；T10七項退回狀態保留，沒有RRACCEPTED、S00APPROVED、SPECSTABLE、Server試跑或人測。[S13:77–83]
- packaged source-review-status是有界來源索引；provenance audit對17件packaged kr/evidence精確digest均未找到索引列。這只能說該snapshot無精確join，不能聲稱這些來源從未在別處審過，也不能反向視為通過。[S14:1–4]

## 來源登錄

所有package path均相對上傳ZIP根目錄；原始資源只在輸入包中讀取。本稿不複製原始XML／ABF到Git。表內Git blob只適用`git-evidence/`，raw member用SHA256並在source-index保留carrier聲明。

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
