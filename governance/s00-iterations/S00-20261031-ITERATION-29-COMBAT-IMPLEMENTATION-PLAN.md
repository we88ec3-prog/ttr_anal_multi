# S00 Iteration 29 — W04：普通攻擊、技能施放、命中傷害、死亡與取消恢復

**2026-10-31 Asia/Taipei｜Server-only 設計提案／原生相容仍待證／24 項驗收均 NOT_RUN**。這份文件不是現成的 `ttr_server_roy` 程式碼、正式 SPEC/TEST，也不主張原版 Tartaros Server 按此演算法運作。

## 1. 核對最新基線及本輪相較 Iteration28 的修正

- 上游 `we88ec3-prog/ttr_anal_multi main=d1f9e174eb1e24e0589eee6605b750bc85a54215`，Main [CI #41130071717](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41130071717) **SUCCESS**。此為 registry/規劃驗證，**不是原版 Client 技能已可施放**。
- 下游 `we88ec3-prog/ttr_server_roy main=9caffb75c374147b71dea51227b5c4f13b33071d`，主庫 CI [#41130449937](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41130449937) **SUCCESS**；本輪透過 GitHub 讀取 `SessionLease`、`IAtomicCharacterActions`、`SqliteLocalDatabase`、`SqliteCharacterStore`、`PostgresCharacterActions` 與 [C02-D local account moderation](https://github.com/we88ec3-prog/ttr_server_roy/blob/main/docs/C02-D-LOCAL-ACCOUNT-ADMIN.md) 的實際 blob 快照。
- **重大版本修正**：Iteration28 的 Server 快照為 `c17a986...`，當時 SQLite `user_version=1`；目前下游已於 C02-D 加入停權/解封、audit、交易內 Session 撤銷，**SQLite local schema v2**。因此新的 C05 mock combat 表格應從 **v2→候選 v3** migration 規劃；PostgreSQL 仍只有 001～003，下一次獨立候選 v4（兩者都**未實作**）。**不可把 Iteration28 當時的歷史快照事後改寫成 v2**。
- C05 正式世界/戰鬥功能仍 `BLOCKED BY EVIDENCE`。C02-D 的停權是 **SQLite local、Server-owned**，不推導原版登入/戰鬥封包、也不表示 PostgreSQL 同等停權機制已存在。Server C03-C 選角交易可復用，但 Iteration28 的 Encounter/Actor/AI 仍是提案、**並未因本文件而完成**。
- 規劃與權威承接：[Iteration27 的 S27-W04](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)、[Iteration28 的 S28-01～03](S00-ITERATION-28-C05-W01-W03-CONTRACT.json)、[Iteration18 E17-E/F/G 原始 gate](S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json) 與 [Iteration26 source-pinned overlay](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)。`ADR-0006/7` 仍 **PROPOSED / NON-NORMATIVE**。

## 2. 把「玩家輸入」與「Server 正式改變戰鬥狀態」切開

```text
SessionLease + SelectedCharacter + ACTIVE MockEncounter + MockActor
  -> AttackIntent / SkillCastIntent [Client-like input; no authority on outcome]
    -> atomic authorize [lease + ban + owner + current aggregate revision]
      -> attack AUTHORIZED / cast RESERVED [dedup + resource/cooldown]
        -> server tick/action-window decision [possible cancel/expire]
          -> server-owned mock hit eligibility
            -> transactional hit ledger + HP update + death once
              -> verified ActorDeath domain event
                -> LATER S27-W05 objective (not Scenario14/Quest/Exit)
```

**設計底線**：Client 僅提出「我要攻擊／施法」的意圖（mock 介面，非 KR 協定已證 payload）。由 Server 自己決定當前角色權限、當前 actor/target、技能可用性、施法時窗、冷卻/消耗、合法命中、傷害與死亡。**任何 Client 傳來的傷害、死亡或過關旗標都不得直接成為 Server domain 真相**。當 Server 端能完成 mock 測試，不表示原版 Client 有相同技能、動畫、命中時機或傷害計算。

## 3. S29-01：普通攻擊與連段／取消窗口的最小原子契約

建議 `AuthorizeBasicAttackAsync(SessionLease, EncounterId, ActorId, TargetId, ActionId, ExpectedRevision,...)` 和 `CommitBasicAttackAsync(...)`（**僅提案的 .NET API**）。

- **授權**：重新在 authoritative DB transaction 內檢查完整 `SessionId+AccountId+ConnectionId+Revision+ExpiresAt`、角色仍是當前選定、帳號未停權、場景/Encounter 是 ACTIVE 且 actor 屬權正確。**不能**先 `IsCurrentAsync` 或 `GetSelectedAsync`、再讓另一交易自由寫行為/HP；這會重新引入 Iteration28 解決的 TOCTOU。
- **輸入語意**：`ActionId` 為新 Server 的 opaque/unique request key；`ExpectedRevision` 與 actor/target 的 mock namespace 驗證，`ActionId` 重送應先重驗授權，然後依 payload fingerprint 返回原結果；不同 payload 同 key 一律 Conflict。
- **時序**：普通攻擊可能包含起手、連段、取消與命中，但要以**可審核的 mock fixture**、Server-owned monotonic `tick` 定義可操作窗口；禁止 Client timestamp/animation progress 直接證成功，亦不得把自製 tick 窗宣稱為 KR 正式連段窗口。
- **隔離效果**：`AUTHORIZED`/甚至 `COMMITTED` action 仍不是 `HIT`，不能自動扣 HP、擊殺或完成 Scenario14。Actor position/tick 需要 Iteration28 W03 的修訂及場景權威。

## 4. S29-02：技能施放、費用與冷卻的兩階段狀態

新 Server mock `ReserveSkillCastAsync`、`CommitOrCancelMockCastAsync`：

| 轉移 | 必須原子執行的效果 | 未解政策（不能冒充原版） |
| --- | --- | --- |
| AVAILABLE→RESERVED | 同一交易驗 actor owner、selected role、lease+ban、resource/skill availability、cooldown，寫唯一 CastId / revision；防兩 cast 同花資源 | 原版技能可用清單、SP/MP、費用/冷卻與 cast animation 的 Server/client 權威 UNKNOWN |
| RESERVED→CASTING→COMMITTED | 只能由 Server tick/合法窗口與有效 lease 推進；唯一 cooldown start/debit/hit eligibility | 到底「預留」或「定案」才扣費、冷卻何時開始均待維護者政策選擇 |
| RESERVED/CASTING→CANCELED/INTERRUPTED/EXPIRED | 按事先批准的模擬 fixture 政策退款或不退款，與 commit/CAS 互斥，永不重複退款 | 原版 Client 是否可取消、取消時窗/資源補償及 CD 規則未證 |
| COMMITTED→hit decision | 成功施法只允許後續 Server 計算合法 Hit，**不是直接造成傷害** | 真正彈道、範圍、命中回報/特效與 KR 封包 UNKNOWN |

**重要競態**：若兩個 CastId 同時讀到相同的資源餘額，必須用 Encounter aggregate revision + 帳號/角色交易權威，防止兩個都扣成功。Cancel 與 Commit 必須在同一 CAS/state row 上決勝；一旦已 commit hit，晚到取消不能倒轉傷害或退款兩次。令同一 `CastId` 搭配不同技能/target 的重送回 Conflict。

## 5. S29-03：Server 自己做命中/傷害/死亡，不信任 Client 報值

提案 `ResolveMockHitAsync`、`CommitMockDeathOnceAsync`，共用 EncounterId、ActionOrCastId、HitId 與 `expectedRevision`。

- **合法 Hit 最低條件**：來源 actor Alive、目標同 Encounter/合法 target、有效攻擊或 cast 先前已授權/定案、距離/範圍/有效窗口與碰撞類型符合 mock fixture。即使 Client 回報自己打到怪也不能跳過。
- **傷害**：用 deterministic mock fixed-point 或 checked integer，必須限制輸入、禁止負傷害/溢位與 `maxHp` 無效、HP clamp 到 `[0,maxHp]`；此規則**只是 Server 保護邊界，不是原版遊戲傷害公式**。
- **交易**：`unique(EncounterId, HitId)` 加 actor/target revision CAS，在同 transaction 寫 HP、命中去重事件、死亡旗標及 outbox intent（如有）；相同來源事件重播只產生同一結果，參數不同應拒絕。多 worker 並行不得把 HP 扣兩次、死亡反覆触發。
- **死亡分離**：ActorDeath 只是一個**經 Server 驗證的 domain event**；下游 S27-W05 仍須獨立計算波次/勝負目標，Scenario14 terminal、Quest14/16、tutorial 完成/離場**均不得自動發生**。

## 6. S29-04：取消、斷線、重登、停權與崩潰後恢復

- 登入/續租/停權更新 `SessionLease` 後，舊 action/cast 任務就算已進佇列，**真正 commit 時**仍須確認 actor ownership、full lease 與 account ban（SQLite C02-D policy），不能任由背景 worker 绕過 DB 權威。對 PostgreSQL 必先確認有相同功能；目前不假設 C02-D 政策跨 DB Provider 自動存在。
- **三個 Crash point**：①費用預留後、cast commit 前；②Hit+HP commit 後但 outbox 尚未傳；③ActorDeath 傳給 Objective 前。必有持久化 `action/cast/hit/death event key` 可以依來源唯一恢復；未批准取消/退款 policy 應 fail closed，而不是任意重發資源或造成雙傷害。
- **交易效果 ≠ 傳輸保證**：對同個 ID 的 DB 效果可使用 idempotent one-time commit，Outbox 發送通常 at-least-once，故接收方還需去重；**不能聲稱 TCP 保證 exactly-once**。
- 同步 Owner 對每個操作指定單一 locking order，SQLite single-writer 與 PostgreSQL `FOR UPDATE` 不互相代換；負向測試需覆蓋 ban/unban、同帳多 Session、跨帳角色、舊 action/擊殺事件、兩個 worker 並行。

## 7. DB 與實作 PR 的實務交付

| 後續 Server PR | 內容 | 最低 planned 驗收（未執行） |
| --- | --- | --- |
| **C05-P4** | `S29-01`：由 Iteration28 W01～03 的 Encounter/Actor 同交易授權並建立 AttackIntent 狀態 | [I29-T01～T06](S00-20261031-ITERATION-29-COMBAT-ACCEPTANCE.md) |
| **C05-P5** | `S29-02`：SkillCast reserve/commit/cancel、技能可用／資源／cooldown／fence | I29-T07～T12 |
| **C05-P6** | `S29-03`：Hit eligibility、傷害固定點、HP CAS 與唯一死亡事件 | I29-T13～T18 |
| **C05-P7** | `S29-04`：取消／重登／停權／崩潰重播與只輸出 ActorDeath 給 W05 | I29-T19～T24 |

- **預定資料表（未建立）**：`mock_action_intent`、`mock_skill_cast`、`mock_actor_combat_state`、`mock_hit_ledger`、`mock_combat_dedup`；屬內部資料儲存規劃，不是原版 Server schema。SQLite local v2→候選 v3，PostgreSQL migration003→候選004，皆需獨立 schema verifier/backup/restore/lock-order 審查後才能進正式資料。Server 現有 `contracts/spec-revision.json` 仍 pin `dd69ec9...`、`implemented_wire_contracts=[]`，本輪不改。
- 維護者需在批准 ADR-0006/0007 或其 Server-specific policy 後才可正式確定取消退款、冷卻起算、持久化狀態和防作弊策略。未核准時先做隔離的 mock prototypes/tests，不能把這份草案視為產品已採納政策。
- **原生研究交接**：E17-E 由 T10/T02/T04 補普通攻擊 producer/consumer、combo/cancel；E17-F 由 T11/T10/T04/T02 補 Skill/available/cooldown；E17-G 由 T12/T08/T10/T11 補 Hit/Death/HP。**同版 KR BIN/Client 來源證據必須有方向、封包 frame/Conn、scene/actor owner、函式或資源定位、正負路徑**。原版 Client 實際執行另需使用者明確授權。不要只因來源 handler 存在就補造相鄰的 S2C 回應或猜原版勝負。
- **下輪 Iteration30 候選**：W05 真正的 Scenario Objective / Once-only Settlement；需接收驗證過的 ActorDeath、維持 Wave/Scene 分離、Outbox/Quest state 不互相直接推進。

本輪只修改規格庫規劃與相關治理檢查。正式 RR/REQ/GAP/CLM/TEST 的證據等級、SPEC-FLOW/SCENE DRAFT/PARTIAL、ADR 提案狀態和 Server 實作庫均不更動。
