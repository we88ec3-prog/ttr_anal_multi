# S00／Server 交付 — KR T10/T11 新手首戰普攻、連段、技能有限契約（2026-11-01）

> **交接文件，不是新 RR／官方 Server 規則。** 此目錄的兩份新 native 報告已保存到 `t10/roy/chatgpt-web`；主線 `main` 尚未因本工作更新。使用者要求處理 T10/T11，並特別關心首戰伊莉西亞操作順暢；只跑正流程規劃，異常/重送/並發/壓測保留待測。

## Git 與來源

- 分析基準 `main=ac6aac673426459df2a778d20a80c623b8559a92`。T10 工作分支原本 behind 59、ahead 0，已由 GitHub fast-forward 同步，compare 同步後 behind=0/ahead=0；**未新建分支、未將 T10 分支合到 main**。
- 工作卡：`research/handoffs/s00-web-skill-gap-20261101/README.md`，來源分支 `codex/s00-web-skill-gap-20261101`，blob `cdfed8f0f09086f175c842ebef22ad97d2fd7c9f`。
- BIN 第一手 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪實際檢查。
- [T10 原生勘誤](20261101-T10-NATIVE-ROW5-T01-ERRATA.md)，遠端 Git blob `adb3b4fd1557dd3fffb50f37699d89ef0b634586`。
- [T11 012A／技能本地門檻](20261101-T11-KR-SKILL-012A-GATES-BOUNDARY.md)，遠端 Git blob `3691a72a7177c5fb91767cc01a4caf030375f304`。

## 可以使用的有界 Client 契約

| 功能／觸發 | 原生證據 | Client 寫入或消費 | Server 可利用的限定要求 | 不可作原版規則 |
|---|---|---|---|---|
| 普攻／輸入輸出 | `545829` 000A、`545895/545A54` row producers、`545B38..545B71` sender | app buffer 6-byte header + 5-byte rows；N>0 且 selector0/queue/Conn 成功才有條件送出 | 依實際 000A bytes/selector 驗證可接受的 Client 輸入；保留 row fifth byte 為**不透明欄位** | 每次 Z 都送、row[4] 永遠 B0、0.65 秒 combo window、row highWORD 的未證語意 |
| Row B 特殊分支 | `545A67/70`、`545AA1`、`545AC8`、`545ADB/B10` | v44≠0 且 owner+58==0 可保持 E4 snapshot；其它可 append 分支經 AC8 覆寫 B0 | 不要以本地 Server 假設丟掉 E4 分支；如需語意先逆向 actor/owner | E4 代表「方向」或 B0 代表「技能」 |
| 技能倒數更新 | `545E20..545F29`，app 012A handler | actor 三槽比對；reset 非零清計時 tree；正常每列 skill WORD + signed count，/33 更新 total/remaining | 可據此設計 **S→C 顯示同步的相容候選**，必須先補 framing 與有效角色生命周期 | /33 換算為秒、Server 真正冷卻起點或官方持續時間 |
| 技能可用 gate | `54F270..54F32E`, `549980..549C4F` | hero model<=9 限定路徑；matrix/tier/key/數值/剩餘 count | 自行區分 Client UI gate 與 Server 權威施放裁決；不以 UI 可用直接代表 Server 接受 | 將此 helper 當怪物 AI、將 resource sum 當完整 MP cost |
| 技能/動作/特效 | 既有 0D / motion 部分證據但本次未閉合各 ID 域 | 不同 domain 尚無端到端合流 | 各 ID 分表、要求來源與 subtype，避免靠同整數對應 | TargetSkillID=MotionID、0D float=開始時間 |

## 正流程建議（**待實際遊戲驗收**，不是已通過）

1. 進入首戰後先以已知的角色/actor ID 觀察按普攻鍵的 **input gate → 000A app buffer → 對應角色動作**；若收包沒有可信 S2C 因果關聯，不可標示回覆 ACK 已確認。
2. 角色面板實際列出 learned／slot/preset 後，按伊莉西亞技能鍵，逐步記錄 Client gate、是否發出任何 C2S，後續有哪些 S2C 導致 motion/effect；官方 SkillID/MotionID 尚未提供，因此此項先以**採證**為驗收工作，而不是直接把候選常數寫死。
3. 有效 actor 若收到 012A 更新，確認對應技能剩餘計數可在 Client 更新中遞減，並追到 UI refresh（`54F330` 與 bottom menu）；先量測回覆與實際刷新，**不要先假設 33 tick/s**。
4. 完成普攻與技能各一條最小正流程後，才進連按、按住、放開、施放中鍵盤/滑鼠移動／取消；這些尚無官方 clock/window，不可宣稱已驗收。

## 目前阻塞，不等於整項 Task 無法研究

| 類別 | 尚待閉合 | 明確下一證據 |
|---|---|---|
| **Client 待逆向** | T10 Row A owner+58=0 的 local writer、全 controller ABI；按住/放開/快速再按到 row 的多支資料流 | `5458C8..5458FB`、所有 +48 vtable concrete targets、`R::vtable+58`、輸入 state buffer |
| **Client 待逆向** | T11 首戰伊莉西亞 learned/preset/slot→Skill ID→motion/effect/target、C2S skill builder | KR 原版技能/角色對應資源，STPD 解包及對應 native consumer；0D/012A dispatch 與 T02 framing |
| **Server 待開發** | 冷卻、消耗、取消時窗、連段與技能權威裁決、命中/傷害 | 請 S00 以已證 Client 最小契約規劃 DRAFT SPEC/ADR，原版 Server-only 判定留 UNKNOWN，T12 傷害不在本次 |
| **跨功能待整合** | T02 socket/receive、T04 角色初值、T09 motion、T12 傷害、T14 教學回合 | 引用各 Task 已驗證限定證據，由 S00 協調；不改他人 owner |
| **待遊玩驗證** | 輸入→動畫→timer→戰鬥結束的時間序列及官方行為 | 原版 Client 封包實例、按鍵/釋放時間戳、Client trace 與畫面結果 |

### 「首戰三隻怪」依賴，分離處理

交接工作卡表示 pinned `Field.stp` set0/cluster1 的 `OBJECTID1036/PRE1/COUNT1` 是**單次 cluster 呼叫**。本次沒有取得可閉合的 spawn trigger/重複 call/波次條件。故「全關僅一隻」與「官方固定三隻」均未證，不能直接修改成 COUNT3；交 S00 與關卡/場景 owner 協調，**不記為 T10/T11 已修復**。

## 狀態

- 兩份文件是**本次新交付的完整限定研究筆記**；重點位址及本輪視窗在各文件能逐筆重現，仍有未閉合功能鏈，研究狀態為**階段性未完成**。
- T10 原有 T01 `NEEDS_FIX`／`NEEDS_QUALIFICATION` **維持原狀**，待 T01 審核完整修復；新報告不能自動變成 `READY_FOR_REVIEW` 或 `RESOLVED`。
- T10/T11 收件箱在本 baseline 均無待處理 RR；不修改 `research/requests/index.json`、派工 inbox、Task owner 或 `native_complete`。
- 本次沒有更新 Server/Client 程式、沒有遊玩測試，不宣稱新手首戰已流暢或已還原全部技能。
