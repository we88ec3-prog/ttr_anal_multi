# T16-52 — KR scenario14→教學完成→Quest16→Quest15 端到端驗收缺口與交接

- 研究時間：2026-10-28；研究者 chatgpt-web roy；KR T16 only。
- 原始 KR BIN：12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本批次未啟動或修改檔案。
- 來源優先：本機原始 BIN/PE、已核對的 GitHub main 和 T16-45～48。
- 注意：以下機器碼中的函式語意是有限範圍判斷；沒有 server source/封包便不宣稱 server 端任務狀態。

## 端到端狀態與反證

| Boundary | 直接證據 | 可宣稱範圍 | 不可宣稱 | 下一份必需證據 |
|---|---|---|---|---|
| 教學腳本入口 | BIN `0x004A8A60`、Lua TutorialMain proto | 有客戶端教學路徑 | 角色一定開始教學 | 角色狀態判定及 Lua callback |
| Part1/Part2 切換 | TutorialMain proto8 / 5 / 6 opcode，見 T16-46 | client 協程順序 | 每個 checkpoint 會 server 存檔 | 原始 TutBase 與 request |
| scenario 開始與結束 | TutorialMain proto6 `RequestStartScenario`／`IsScenarioEnded` | 呼叫 API 候選 | `scenario14` 是已確認輸入值、合法成功 | Lua 參數 + T14 server result |
| TUTO 場景恢復 | T01 NEXT-QUERIES 待辦 | 研究鏈 | 經官方結算返回成功 | T07 scene transition + authoritative ACK |
| Quest16 完成 | 尚無原始 server writer | unknown | 已自動完成／已持久化 | QuestInfo id16 + server writer / packet |
| Quest15 可接 | QuestTalk 可見片段 13→17；無 QuestInfo id15 原文 | unknown | Quest16 必然前置 | QuestInfo id15 + server validation |
| 重登續接 | 本批無 role scoped progress snapshot | unknown | client local checkpoints 會恢復 | T15 state reader + scope |

## 具體的 refutation checks

1. 在 QuestInfo id16 完整 element 中檢查 completion type/condition；若不存在相關任務 ID，重新檢查「Quest16」是否為 quest namespace 而非 tutorial/scenario enum。
2. 在 QuestInfo id15 中核對 predecessor/needquest/level/NPC 欄位原始名稱和數值；不預設一定以前一個 quest ID 完成作條件。
3. 對 `scenario14` request 參數追踪 Lua constant → native bridge → packet → server result；若只有 `IsScenarioEnded`，只能證實 client-ended polling，不能證明勝利。
4. 任務 writer 與 client cache 必須分開；需要收到 authoritative reply、server persistent store、再次登入 reader 閉環，才能聲稱「進度可續」。
5. 舊 fixture 的 Tutorial patch 與原版 `005F type6` 嚴格隔離，不以 AI 版本或修改客戶端為原版 acceptance。

## Deferred resource 機讀交接表

| Resource | SHA256 | 缺口與研究後果 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | 無原始 callback/instruction；不能完整還原節點 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 無 Quest15/16 實際欄位；不能證明依賴 |
| server quest writer／ACK | unknown | 無封包 + server source；Quest16 completed 無法閉合 |
| T15 重登 state reader | unknown | 無持久化保存驗證 |

## KR T16-49～52 限定結論

- **原生已確認**：本批 BIN 檔 SHA／PE layout／指定指令 bytes、先前 GitHub Lua bytecode 和局部 QuestTalk XML 有據。
- **部分確認**：client 教學路徑與 callback／table 消費邊界。
- **資訊缺失**：Quest16 官方完成條件、Quest15 可接條件、官方 server writer、重登恢復。
- **無 AI 替代部署**；未修改、啟動原始 client；不執行 TC 研究。

下一段優先取回兩個 deferred 來源的**真實原件**，其次在 BIN 原生 call graph 上追 quest state notification/send/receive 的精確 callsite；如 server 缺失，保留 unknown。