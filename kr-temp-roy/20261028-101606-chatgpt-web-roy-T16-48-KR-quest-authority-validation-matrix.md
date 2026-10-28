# T16-48 — KR 教學末端至 Quest16／Quest15：通知、權威 writer 與重登狀態證據矩陣

- 研究者 `chatgpt-web roy`；KR T16（不涉及 TC）；日期 `2026-10-28T10:16:06+08:00`。
- SHA256(KR BIN) `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，size `12472320`；原檔唯讀。
- GitHub `we88ec3-prog/ttr_anal_multi`, main 最近 commit 查詢回報 `4b2f7cc8295df4256b7b1c1f94a33083c2f8a7c1`（commit 搜尋的最近項，非 ref 原子鎖定）；未改 catalog/owner。
- 證據標示：「原生已確認」僅限本輪實際解析位元組／讀取 XML；「部分確認」為本地 script 與 client 邊界；「資訊缺失」為無 server writer/packet 的結果；不可推成可玩驗收。


## 1. 本輪已閉合與未閉合的證據邊界

本輪直接檢查 KR 原始 BIN 的 SHA 與 `QuestInfo.xml`, `QuestTalk.xml`, `TutorialMain.lua`, `TutorialBase.lua`, `TutoQuest`, `HasQuest`, `HasCompletableQuest`, `HasScenario` 字串 raw offset；Lua bytecode 的 proto、opcode/JMP 與 client-level coroutine/controller 邏輯在 T16-46 記錄；QuestTalk XML 前段實際條目和 QuestInfo 資源阻塞在 T16-47。這些**不構成 server Quest16 complete callback 實際已被觀察**。

| 階段 | 觸發者 | 可觀察證據 | writer / owner | 驗證狀態 |
|---|---|---|---|---|
| 教學 entry | KR client/ Lua loader | BIN 0x4A89C0 / 0x4A8A60 與 Lua 名稱；T16-45 | client Lua 調度 | 部分確認 |
| Part1 loop | TutorialMain proto8 + proto5 | pc15–45 協程與 proto5 control/checkpoint 等候 | client controller | Lua 指令與 loop 原生確認；具體 API side effects unknown |
| Part2 begin | proto8 pc75/76 | 直接呼叫 `Tutorial_Part2` | client controller | 原生已確認呼叫，真正場景狀態仍未知 |
| 關卡要求 | proto6 | `RequestStartScenario`, `IsScenarioEnded` 常數+呼叫候選 | T07/T14 及 server 領域 | 未驗證 scenario ID/判定／response |
| scenario14 合法結算與 TUTO 返回 | T14/T07 邊界 | T01 `NEXT-QUERIES.md` 待辦鏈（非原生實證） | **server 權威未取** | unknown |
| Quest16 完成 | server 應判定 | 目前沒有可驗證的 Quest16 server writer/ACK | **unknown** | 資訊缺失 |
| Quest15 可接取 | server Quest state/QuestInfo | 目前沒讀到 Quest15/16 原件定義 | **unknown** | 資訊缺失 |
| 重登／續接 | T15 責任介面 | 沒有角色 scope snapshot／持久化 writer | **unknown** | 資訊缺失 |

## 2. 關鍵反證與隔離

- Lua 全域 `g_TutoEmployCharQuery` 在 Part2 的兩組 yield-loop 後明確 `SETGLOBAL FALSE`，只能確認**client-local flag**；不能以其清除推論 server Quest16 完成。
- `SetCheckPointStatus` 在 Lua proto5/6/8 有實際參照；它可能標記教學 UI／checkpoint，沒有 packet 與 server writer 證據，**不將其命名成 quest persisted state**。
- `QuestTalk` 的 `givertalk`, `givertotalk`, `finishertalk` 是 talk reference，不表示 QuestInfo 的前置解鎖條件。
- `IsScenarioEnded` 可能僅查 client-level event completion；不能無結果原件推論 scenario14 勝敗與領獎合法性。
- T01 的 `owner:null`, `unclaimed`, `native_complete:false` 與歷史 fixture 代表此流程不具原生完成聲明。本輪不改其他 Task 的主責、catalog 或 SQL。

## 3. 最小權威驗證矩陣（待驗收，而非提供猜測資料）

| 條件測試 | server 入力（待取得） | 必需權威回應 | 是否已取原件 |
|---|---|---|---|
| 新手教學尚未進入 | 已建立角色的 Quest/tutorial snapshot | 入口與 checkpoint 初始化、合法續接 | 否 |
| 教學中斷重登 | 既有 tutorial step + role scope | 復原同一節點或原版合法重入 | 否 |
| scenario14 失敗 | 官方結算結果欄 | 不可默認 Quest16 完成 | 否 |
| scenario14 勝利 | 官方結算結果欄 | 僅在有 server 驗證後變更 Quest16 | 否 |
| Quest16 完成重複回報 | 同一進度的 duplicate request | 防重覆寫入／領取的原版規則 | 否 |
| Quest16 已完成 | 原生 QuestInfo prerequisite | Quest15 是否顯示可接取/由誰發放 | 否 |

上表後半的行為是**驗收時要測的性質／問題**，不是已有的原版規範；請勿直接作為 server 實作設計常數。官方封包 opcode、Quest actor/character scope、SQL schema、Quest15/16 reward 均保留 unknown。

## 4. DEFERRED-LOCAL-RESOURCE 和後續行動

| 來源 | 來源 SHA256 | 阻塞研究 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | Lua 教學 API 回調、基底函式 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | Quest15/16 schema/prerequisites |
| Quest15/16 server handler/persistence | **unknown（尚無來源原件）** | 權威寫入、通知、重登、反重複 |
| T14/T07 原始結算／返回事件 | 需按跨任務現有原稿逐地址引用 | scenario14 → TUTO interface |

本段嚴格只完成 KR client evidence 的局部拼接與不成立推論排除，**沒有證實**「scenario14 → Quest16 complete → Quest15 available」。接棒時優先補 QuestInfo 原件及 TutorialBase，然後逐原生封包定位 server handler、角色 key 與 state writer；不以客戶端 patch 補齊缺口。原版 `005F type6` 不等歷史 tutorial patch。

## 5. Git 操作界面

本檔與 T16-45、T16-46、T16-47 均屬 KR T16 `chatgpt-web roy` 技術原稿，只有使用者此輪明確要求時提交。GitHub 的最後 SHA 以實際 push 結果與遠端讀回為準，不能將本文撰寫時的 HEAD 搜尋結果誤稱 commit 收據。