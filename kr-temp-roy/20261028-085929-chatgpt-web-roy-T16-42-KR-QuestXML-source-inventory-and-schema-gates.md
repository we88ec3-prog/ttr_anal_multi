# T16-42 — KR Quest XML 原始來源、根節點與 Quest16／Quest15 schema 缺口

- 執行日期：2026-10-28 Asia/Taipei
- 研究類型：GitHub T01 來源稽核 + KR BIN 舊證據約束的交叉核對；不可讀原始 resource 全文的限制明示。

## 來源、方法與證據界線
- 倉庫：`we88ec3-prog/ttr_anal_multi`，基準 `main`：`d0fce702b42c89cd8ba2fd077ddbdfde341da19f`（本輪開始時核對）。
- 主要新來源：`shared/integrations/T01-20261028-06/{README.md,resource-source-audit.json,pending.json,NEXT-QUERIES.md}`；`kr/tasks/T16/{README.md,task.json}`；既有 `kr-temp-roy/T16-1…40` 原稿。
- KR 原始 BIN：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新以本機 sha256sum 核對。EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 資源稽核紀錄源自 T01 靜態讀取與校驗，**不是本輪已讀取資源內容全文**。`kr-temp-roy/T16-local-20261028/evidence/resources/...` 是歷史本地工作區路徑，未出現在目前 GitHub 同路徑；GitHub 的 `kr/evidence/<SHA>.txt` 具有非 UTF-8 內容，現有 UTF-8 fetch 介面拒絕，不能據此假稱本輪已還原其欄位或 Lua 指令。這是 **ACCESS-BLOCKED-RAW-CONTENT**，不是「資源不存在」。
- 證據等級：**S**=可讀原始內容與直接來源核對；**B**=原生 BIN 指令直接證明的有限事實；**A**=T01 來源/解碼/SHA 稽核事實；**H**=歷史研究待交叉驗證；**U**=尚未證明。不得把 A/H 提升為 S。
- KR/TC 必須隔離；歷史 fixture、模擬服及 005F type6 本地修補不等於原生規則。原件唯讀；不執行客戶端或歷史程式，不更改其他 task 的 owner/catalog。

## 新整合的 KR XML 原始來源稽核
來源容器 `E:\Tartaros\origin\Table.stp`，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`，大小 5,248,784 bytes。T01 獨立校驗資料列如下：

| 成員 | SHA256 | raw offset | stored size | XML root | 直接 children 數 |
|---|---|---:|---:|---|---:|
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 4,345,872 | 204,056 | `QuestInfo` | 4,798 |
| `Table/QuestTalk.xml` | `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28` | 4,550,672 | 52,404 | `QuestTalk` | 4,322 |
| `Table/ScenarioBookContents.xml` | `15b67767af884ac2abe05319ca406c9bc5e705c5ea8311de8d6b45644f8210d1` | 4,620,304 | 10,987 | `ScenarioBook` | 426 |

`children` 是根節點下的 XML element 數，不等於唯一 Quest ID 數，也不代表 4,798 個任務。Quest ID、step ID、conversation ID、scenario ID 必須依欄位命名空間分開。

## 原生載入與資源關聯
- 前批 T16 BIN 分析標記 QuestInfo 入口 `0x00504740`、路徑常數 `0x0050478B`，QuestTalk 入口 `0x00505570`、路徑常數 `0x005055B8`；兩條路徑都見 `0x0072EE30` 與 `0x0072F110` 一類處理函式。
- 以上位址是 KR PE VA，非 table row 的 ID，也不跨版套用。
- T01 XML root 校驗對應了先前 BIN 看到的路徑字串，但 **root/child 計數無法證明 Quest16 或 Quest15 的實際屬性值**。
- `Table/TutCheckPointList.xml` 另有根 `TutCheckPointList`、4 個直接 children，SHA `fe0a7131118ae804897ed8255da00f4cf8bad58bbe8fcc87ca2e5676146a2555`；與角色續接的語義尚不可直接宣稱。

## Quest16 → Quest15 的證據欄位審計
| 待回答問題 | 可使用資料 | 本輪結論 |
|---|---|---|
| Quest16 是否存在且 ID namespace 為何 | QuestInfo XML 條目／腳本映射 | U：未讀取原始 row |
| Quest16 完成判定是什麼 | Lua 事件 + 封包 + server state | U：無直接原生 server 證據 |
| Quest15 可接前置依賴 | XML prerequisite 欄位 + server | U：目前只有 T01 pending 明列作為待查 |
| NPC／Talk 與 Quest16/15 的對應 | QuestTalk row 及 NPC identity | U：尚未抽取原始 row |
| 劇情序列或過場 | ScenarioBook/ScenarioTalkTable/Sequences | U：不能靠 root counts 推斷 |
| 分版本 ID 一致性 | KR、TC 同名 row 的原文 + SHA | U：兩版檔案 SHA 不同，不等於每筆不同 |

## 下次有原件後的可重現提取策略
1. 以 sha256 定位並讀取 `QuestInfo.xml`、`QuestTalk.xml`，建立 row ordinal、原始屬性原文與來源 span（若原件是壓縮存放，先分開記 carrier 跟解出 bytes）。
2. 檢視 XML 的 ID 欄、source/target/require 欄名，不先假定 `Quest16` 字串必為整數 16。
3. 原樣搜尋 ID 16/15 的**所有命中**，附 row、上游 prerequisite、NPC、類別、獎勵、章節、故事文本；區分同名不同域。
4. 用 Lua 的實際常數與 server 封包驗證依賴箭頭，UI 顯示或資源 Demand 不等於後端合法性。
5. 檢視 KR/TC 資源差異，不搬用 KR 事件實作判斷 TC。

## 結論與阻塞
已取得來源 SHA、封裝 offset、根節點與大小的**A 級來源證據**；目前無法給出任務 ID、Quest16/Quest15 的真正 prerequisite、NPC/對話/獎勵矩陣。應優先解除 GitHub **非 UTF-8 證據 bytes** 的存取阻塞，或由有原始 carrier 的工作者匯出可讀、帶 SHA 的 schema/row 索引；不得用 root count 虛構任務資料。