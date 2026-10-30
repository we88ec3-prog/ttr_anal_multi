# S00 Iteration 24 — 選角、Square 與教學前置驗收計畫（20 項）

**全部 `PLAN_ONLY / NOT_RUN`，沒有在這個研究/規劃回合執行原 Client 或 Server。** `I24-Txx` 是設計案例 ID，**不是**正式 `conformance/test-index.json` 的來源測試 ID；Domain 测试由獨立 `ttr_server_roy` 開發時才逐項執行並保留輸入/輸出。合成測試 PASS 不可冒稱本版原始 Client/Server 的實測驗收、T01 FULL-PASS 或 RR ACCEPTED。相關：[Iteration 24](S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md)、[Iteration 23](S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md)。

| Case | Type | Preconditions / Action | Required check and **boundary** |
| --- | --- | --- | --- |
| **I24-T01** | DOMAIN | 玩家帳號存在、沒有 Expedition 名稱／角色 | role selection 明確不可用；不能因「帳號已建立」假裝 role 可選、不要自動進場 |
| **I24-T02** | DOMAIN | 角色 snapshot 與 delta 均指向同 account 的 slot 1 | `FullRoster`/ `Delta` 寫同一權威 RoleStore、加 revision；**不是** E79 已證的 Server DB schema |
| **I24-T03** | DOMAIN | 角色所屬權與目前 Session AccountId 不同 | 拒絕選擇、不送 scene、Session state 不變；Client local `record+5C` 不是權限憑證 |
| **I24-T04** | NEGATIVE | role ID 0 / 10 / 重複值、或超過本 Server 提案的1..9 | Server 提案政策 fail-closed，不能宣稱 KR Client 官方 ID 合法域等同1..9 |
| **I24-T05** | STATIC PLAN | C2S42 inner body `42 00 01 00` 4B | Parser 區分 u16 opcode、u8 index=1、u8 mode=0，slot0 queue 與 TCP frame 分開；還沒原 Client run |
| **I24-T06** | STATIC PLAN | C2S42 inner body `42 00 01 02` 4B | mode2 正向 UI 候選，**不等同另一個角色 ID**；Server mode2 policy 需另定 ADR/負向路徑 |
| **I24-T07** | NEGATIVE | C2S42 body 缺1 byte、多 byte、錯 opcode、非法 mode | 依 Server V1 parser policy 拒絕且不產生場景副作用；這不是原版 Client 的拒包行為 |
| **I24-T08** | DOMAIN | 多連線／重複點擊相同 role 與 mode 0 | single-flight 選角/lease/CAS 去重，不能雙重 spawn；不賴 `scene+CC` local pending |
| **I24-T09** | DOMAIN | 從不同裝置／Session 同時選擇同一 AccountId 的 role | Server 定義 lease fencing 與單一 session authoritativeness，不以新 Client local flag 決勝 |
| **I24-T10** | NEGATIVE | C2S42 進入 manager unavailable（本地 FBA798!=0） | 本地 scene+CC 仍可能變1，但 Server 不曾收到；timeout/重連設計不可解讀為已 ACK |
| **I24-T11** | STATIC PLAN | ExpeditionScene 0x70A UI child index +1、record+5C gate | 記錄**只有此分支**做本地 available 檢查；另一 ExpeditionDialog 入口未見完全相同 gate |
| **I24-T12** | STATIC PLAN | ExpeditionScene 0x578 按鈕 mode0/2、scene+CC pending | 狀態是**local pending**，其 reset/失敗回復仍需 T03 補證；不當作 wire field |
| **I24-T13** | STATIC PLAN | S2C0x0002 65B header + 53B×0,1,9 | 完整 header `+2,+0C,+36,+38,+3A,+3C,+3D` 安全初始化並保留未知業務欄位，角色1..9 的 bitmask；禁止自行發明完整 official prefix |
| **I24-T14** | NEGATIVE | app2 role ID0、ID10、短 header、name 無 NUL | Server 合成**不產生**可能觸發 Client mask/提前 header read 的危險封包；不是證 Client 可安全拒絕 |
| **I24-T15** | DOMAIN | 選角權威核准但 SceneBootstrap adapter disabled | `SelectionAcceptedInternal` 不等於已進遊戲；保留 Pending/Recoverable 與 rollback |
| **I24-T16** | STATIC PLAN | S2C `0x0069` `payload+2=7`，且讀 `+3/+4` | CSquare scene candidate 要有長度/scene/Conn/資源前提，3B短包不安全；不是已證 C2S42 ACK |
| **I24-T17** | STATIC PLAN | 0x69/7 寫 CSquareChannelState+18/+1C | 不能和 CSquareUserData+18/+1C 混同；進場事件 != world spawn |
| **I24-T18** | STATIC PLAN | CSquare entry C2S `43 00 XX 0A` len4 slot0 | XX 取 **CSquareUserData+18 low8**、不是 ChannelState+18；不要把它和 S2C43 當成一問一答 |
| **I24-T19** | DOMAIN | SceneBootstrap interrupted/timeout/duplicate C2S43 | Session 隔離已核准 role / pending scene / world ready，重複/過期/斷線時 fail-closed，可重登入 |
| **I24-T20** | E2E PLAN | 原版 KR Client + 隔離相容 Server，已存在角色 / 不存在 / mode0/2 / retry / Square / 教學 | **需使用者另行授權**、保存 frame/Conn/scene/UI/quest trace；成功只證自製 Server 的相容性，不證官方原版 Server 因果 |

## 驗收紀錄模板與開發順序

當 `ttr_server_roy` 實作者執行時，每個 case 應保存：
`case_id`、`server_commit`、`KR_target_sha256`、`environment`、`input_hash`、`expected`、`observed`、`pass/fail`、`evidence_type`（DOMAIN_SYNTHETIC / ORIGINAL_BIN_STATIC / COMPAT_CLIENT_RUNTIME / ORIGINAL_SERVER_TRACE）、`blocker`、`last_reviewed`、`reviewer`。

**建議優先順序**：先 I24-T01～T04 領域模型與權威；再 T05～T10 parser/Session；接著 T11～T14 roster/UI source 限界、T15～T19 gated Square；最後另行授權的 T20 gameplay。任何 synthetic tests 的通過**都不會自動**將正式 RR-0002/RR-0010、GAP 或 SPEC 升格。
