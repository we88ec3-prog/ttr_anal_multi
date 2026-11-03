# W2 P1：共用任務Runtime與批量內容資料

## 現況（Server程式核對，非原版Server事實）

現行不是每個任務各寫一個獨立服務，但教學→廣場→Quest15→兩張路圖→馮德斯村主要靠專用分支與狀態旗標。已有共用TCP framing、場景／地圖封包編碼、角色初始化、碰撞／移動、有限遭遇戰與SQLite元件；尚無通用任務定義+事件驅動流程可直接大量套表。

例如教學退出固定scene10/12/13/14；主線橋接固定Quest15、Field19、Case103、Map191/192、Town1/Map182；兩張圖spawn／monster／portal仍由專用配置給定。Quest117以後未因已到村就算實作。單人主線的編隊頁不等於多人組隊任務。MEF格式缺口與ScenarioRuntime規劃另見S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md。

## 可直接貼給Web AI的提示詞

你是KR任務資料／流程分析者，配合T16主責並引用T06/T07場景、T09副本及既有W1/W2/W3馮德斯工作包。請讀AGENTS與原Task既有成果；不更改他人owner，不把此工作包當已公開RR認領。只讀Client與資源，區分Client事實、使用者要求、Server候選設計和未知。

目標：讓S00後續新增主線主要填資料和補少數共用handler，不再為每個Quest堆if。請先盤點可用原表及既有分析，再抽出共用流程；不能假定所有任務都同一線性模板，也不能把播放劇情成功當任務完成。

請交付下列九類可實作資料：

1. **識別碼／來源字典**：Quest、Chapter、Scene、NPC、Town、Field、Map、Case、formation token、portal、monster、item/reward各自typed ID、關聯表與SHA。Quest15≠Field19≠Case103≠Map191/192；名稱翻譯與ID分離，不能按ID遞增猜主線。
2. **任務定義與目標**：前置AND/OR、接取條件、可見NPC、等級／角色限制、目標型別（對話／觀影／到區域／擊殺／收集／通關／交付等）、數量與作用域、可選分支／重複性；原表欄位與缺失後端規則分開。
3. **通用狀態機**：可接、已接、進行、目標達成、可交付、已結算等候選狀態及合法事件轉移；列出Client可見狀態、Server權威狀態與持久化邊界。不得只用「scene播放完→已完成」捷徑。
4. **事件與流程節點**：對話、關閉UI、播放scene、等待receipt、提供單人編隊、建立instance、初始化地圖／NPC、開啟手動portal、顯示result、返回村莊、發布下一任務等共用primitive；每類列precondition、input、effect、wait/receipt、next、持久化點及未知。NPC對話窗與下一段scene的生命週期必須納入。
5. **單人Scenario介面**：任務Runtime只呼叫遭遇／副本服務，定義入場要求、允許隊員、map graph、完成條件、清怪後保留戰鬥、portal需站上按Z、result/return事件；保留教學特殊分支，與多人party獨立。
6. **結算／保存／回復契約**：接取、目標計數、場景進度、instance完成、獎勵、下一任務解鎖的提交點與資料欄位；道具／貨幣／角色／經驗獎勵的原表域和Client發布封包。未恢復的原Server規則不得填猜值。重複結算／斷線等只提出設計及待測清單，現在不執行相關測試。debug快進／退回不回寫正常紀錄。
7. **wire適配表**：domain事件→C2S consumer／S2C producer及完整欄位／長度／scene/controller條件，防止同opcode跨場景誤用。共用任務引擎不要直接塞byte陣列；與既有編碼器分層。
8. **批量內容產物與檢核規則**：任務清單、node graph、NPC/scene關聯、目標、獎勵、Scenario入口的CSV/JSON schema與可機讀樣本；檢查重複ID、缺引用、不可達node、缺合法結算、ID域混用、來源缺失。不能將自訂schema命名為原生MEF。
9. **採用／例外／遷移矩陣**：現有專用分支→共用primitive→內容資料→真正特殊hook→來源／未知／正流程驗收。先抽取教學與Quest15已通路徑，核對保存的玩家進度與Client行為；再用至少兩個結構不同的後續任務驗證可重用。不要一次重寫整條已通流程。

交付檔案建議：

- `quest-runtime-design.md`：狀態機、服務邊界、事件與持久化。
- `quest-definition.schema.json`、`quest-flow.schema.json`：明確標Server候選，版本化。
- `quest-catalog.csv`、`quest-nodes.csv`、`quest-objectives.csv`、`quest-rewards.csv`、`quest-wire-map.csv`：每列附source_ref／source_sha／evidence_kind／unknowns，未知留空並解釋，禁止補預設猜值。
- `migration-matrix.csv`：現有教學／Quest15專用分支的共用映射。
- `acceptance-cards.md`：按功能／任務分正流程步驟與可觀察結果；未跑就標待測，測試快進不算正常通關。

內容示範至少含：現行教學特殊流程、Quest15橋接，以及經表格確認的兩個不同形態後續任務（候選117/118/119，必須先證明其結構，不能硬湊）。沿用既有馮德斯候選鏈15→117→118→119→120→121→122→123→124→131→132→133(Town2)，但逐個核對章節／前置／scene；這是先前靜態篩選，不是已驗收的完整章節。

優先交第一批：任務／flow schema草案+Quest15完整資料例+一個後續任務例+無法共用的例外表，讓S00可先設計接口。後續再交整村機讀內容；缺獎勵／合法達成證據時明確標BLOCKED欄位，不把單純播放所有scene當完成整村主線。
