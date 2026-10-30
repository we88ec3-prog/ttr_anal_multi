# S00 Iteration 24 — E80 應用：角色選擇、Square 場景與新手教學之前的 Server 契約

**2026-10-31（Asia/Taipei）**｜**KR Client** 原件 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本次是 **S00 設計／有限 Client 靜態交叉審查／開發交接**，不是 Server code 或 original Client 可玩驗收。

## A. 新來源和既有 RR-0010 的嚴格區別

- [PR #67](https://github.com/we88ec3-prog/ttr_anal_multi/pull/67) 將 `extra/roy1` **E80 RR-0002** 的兩份原件分析與驗證器合併到 main（merge `ba5f2795a047b01d861ad470b424a555d7554353`），來源：
  - [E80 研究報告](../../kr-extra-roy/20261031-0414-chatgpt-web-roy-E80-RR0002-selection-UI-roster-square-new-server-contract.md)，blob `8b15f43fe9414936ec8e6f987347e27c77fb211e`。
  - [E80 原件驗證器](../../kr-extra-roy/20261031-chatgpt-web-roy-E80-RR0002-native-verifier.py)，blob `fd5b14005898b017ce1063fc6e042f23ec8b991c`，作者報告 **117 assertions PASS**（原始 BIN 指令／RTTI／call + 顯式標籤為合成 Server policy 的檢查）；**本 S00 回合沒有原件 BIN，不曾重新執行上述 117 項，不能拿它當 T01 FULL-PASS**。
- 此次獨立核對兩份 Git blobs，並交叉讀取同 KR SHA 既存的 `kr-bulk-roy/.../functions/0x4a3b80.c`（blob `546aa404686ee2b38cf5cb0cd9a3ed69f2f04366`）、`0x5f46d0.c`（blob `92e76f6e7ad35bc3d0e5d31cc1e1b5d428da73ef`）、`0x673da0.c`（blob `9d25a5d2c91e5cca3947b93b84b3d57946cf7aa1`）及 `0x4b7f00.c`（blob `871c336add31a6ad3ddabce41c1a284bc37c41bb`）。這些 Ghidra 派生文字**尚未逐函式語意審核**，僅支持限定 UI sender、同源 role record、C2S42 的 local queue guard 等交叉論點，不等於親自重跑 raw BIN，也未證 E80 的整條 Square 原生 CFG。
- RR-0010（**建立可操作角色／建名結果到角色名單**）仍是 `BLOCKED`、`GAP-CHAR-0003 OPEN`；E80 是相鄰 **RR-0002（選擇既有可用角色）**，同樣維持 `BLOCKED`，`GAP-CHAR-0001 OPEN`。不可以因為選角後找到 Square candidate handler 就稱前一步「建立角色」已成功。
- 上輪 [Iteration 23](S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md) 的結論不改：Expedition 命名 `C2S3E`/候選 `S2C4A`、full `S2C2` 與 delta `S2C2B` **同一 F94304 role record array**、條件式 `S2CB6→local F4278→role UI`，**彼此沒有已證 official Server transaction 序列**。

## B. Client 已觀察的**有限能力** → 不推論的邊界

| 方向／部位 | 可引用的來源有限事實 | Server 絕不能自行補完 |
| --- | --- | --- |
| UI 選角來源 A | `CExpeditionScene` event `0x70A` 讀 child control `+0x20`，將 child index **+1** 寫 scene `+0xC8`，具 `<=9` 及 **role record+0x5C != 0** gate，呼叫 `0x4A3B80(index,0)`（E80 `0x5F46D0`） | 不能說所有 UI sender 都檢查 +0x5C 或所有原版合法 ID 都是 1..9 |
| UI 選角來源 B | 同 scene event `0x578` 的兩個 control 可送 `mode=0` 或 `mode=2`；兩條在送前檢查 `scene+0xCC==0`，sender 返回後寫 **local pending flag=1** | `scene+CC` 可能在 `FBA798!=0` **未 queue** 情況已變1；pending 不是 TCP sent、Server ACK、角色就緒 |
| UI 選角來源 C | `CExpeditionDialog` `0x578` 以 `dialog+0xD8` 為 index、mode0 呼叫同一 sender；該 callback 未直接呈現與來源 A 同一 +0x5C gate；`F42EF/F4247` 是另一本地事件 | 不得強迫所有 Client UI 入口服從同一按鈕 guard；本地 event 不能直接當 S2C |
| **C2S `0x0042`** | `0x4A3B80` 以 slot0 queue **4 byte inner payload**：`42 00 [roleIndex u8] [mode u8]`；已證 UI 送出候選值 `mode=0/2`，`FBA798==0` 才可 enqueue | `mode0/2` 真實商業含義未知；local queue≠外框/socket delivery；不能用 S2C `0x42/0x43` 當 ACK |
| Full **S2C `0x0002`** | **65+53×N** header+record；Client 在 row count 的 `len>=65` 前已讀 header `+2`、`+0x0C`、`+0x36/+0x38/+0x3A/+0x3C/+0x3D`；row index field `row+0x2E` 本地 upper guard <=9 | ID=0 於後續 mask `1<<(ID-1)` 可能不一致；**建議 Server 合成輸出先採 1..9** 是新 Server 防呆選擇，**不是官方所有合法 ID 集合**；完整 header 的其他業務值仍未知 |
| **S2C `0x0069`, subtype7** | E80 報告 `0x4B90C1` 讀 `payload+2=7`，`0x4B90F0→0x4BBB70` 初始化 CSquare、`0x4B90FD` 進場景流程，`payload+3/+4` 寫 **CSquareChannelState** | 不是原版 Server **C2S42 ACK** 的官方配對；scene/resource/Conn 未證，短包不能拿只含 subtype 的 3B 亂試 |
| **C2S `0x0043` Square entry** | E80 `0x4BBE66..AF` 在相應初始化下 queue `43 00 [CSquareUserData+0x18 low8] 0A` len4 slot0；`CSquareUserData` 與 `CSquareChannelState` 為不同 singleton；另本地 index setter 也可 queue C2S43 | 不得拿 ChannelState+0x18 當 C2S43 identity；C2S43 != S2C43 ACK，也不等於教學開始 |
| Square 補充資料 | S2C `0x0068/0x006A` 另有 Square channel/user 初始化相關 handler（E80 與相鄰 T03 來源） | 具體 callback/order/所需最短欄位仍需 T02/T03/T05 查證；不可因看到 CSquare 類名就直接切到 tutorial |

**E80 的重要反證：** C2S42 的 role slot 和 mode 字節不同；`S2C42` 與 `S2C43` 只是各自 consumer，沒有已證 accepted/rejected 結果配對。`S2C69 subtype7` 是**可供新 Server 的相容測試假設**，不是官方原始 response。原版選角失敗/重試的可見 UI consumer 尚未明確找到，仍應由 T03 補 native source。

## C. 從 RR-0010 到 E07+ 的具體分階段 Server 規劃

**前提**：管理員 WEB 建帳只建立 Account，可能尚未擁有 ExpeditionName 和 playable character；第一個正式可驗收里程碑不是「某個命名成功 flag」，而是隔離場景中有一筆**權威可用角色資料**。

| Stage ID | Server 設計元件／狀態 | 可以離線開發的部分 | 需補證才能接原版 Client |
| --- | --- | --- | --- |
| **S24-A** | Account→ExpeditionProfile→PlayableRoster（沿用 I23） | `AccountId` 與 `RoleId` 分開；role slot 與 account 綁定、單一 roster snapshot/delta source of truth、持久化/樂觀 revision | RR-0010 真正角色招募/建立 producer→roster 及 GUI R9 的可達性 |
| **S24-B** | `RoleSelectable` gate | 只看 Server 已存權威 role、slot 是否有權限、角色啟用狀態；不直接信任 Client `record+0x5C` | app2/2B header 與角色 row 正式 wire 值；0x5C 是 Client local field，不能當網路回報 |
| **S24-C** | `SelectionAttempt` immutable intent | 在已登入/有效 Session/未停權的條件下解析 index/mode、CAS Session lease、檢查所有權、single-flight/pending expiration、connection loss rollback | mode0/2 真正 GUI 行為、處理成功/拒絕後的 state writer |
| **S24-D** | `AwaitingSceneBootstrap` (proposed) | 成功授權只保存 server-internal pending selected role；分離 selection acceptance 與 scene delivered，區分 idempotent duplicate / stale/timeout | `C2S42→S2C69/7` 原版因果**未知**；需要正向 Client error/scene preconditions |
| **S24-E** | `SquareBootstrap` (feature-gated candidate) | 在 **synthetic compatibility fixture** 中組 `S2C69 subtype7` 所需資料的候選 adapter，留 Scene/Conn/resource gate；擷取 subsequent `C2S43` | T02 封包框架/Conn、T05 Square 資源/scene、payload+3/+4 與 68/6A 正式需求 |
| **S24-F** | `WorldSessionReady`→初次教學 E08+ | 內部區分 scene entered、world spawn ready、tutorial quest progress；失敗可以回選角，不由單一 F4278 或 C2S43 宣稱通關 | C2S43 與 world login authorization/教程 1001,1 的原生必要正向鏈、RR-0008 和 T05/T07/T16 |

**不可把階段拼成官方必然順序**：`3E→4A→2→2B→B6→42→69/7→43→tutorial` **不是**已觀測的原版 Server trace。這張表是 Server V1 **建議的內部 domain state machine**，由設計 ADR 將角色 ID policy/Session/CAS/timeout/retry/error UI/first-tutorial 決定列為待批准，且 native adapter 應**預設關閉**直到最小完整 Client-compatible fixture 成功。

## D. 隔離工作包、可交付項與順序

| WP | Owner 模組 | 明確交付 | 驗收門檻 |
| --- | --- | --- | --- |
| **SR24-01** | Account / Character / Persistence | `SelectableRole(account, roleId, slot, revision)` model、account/slot FK、0/1/9 合法合成 roster、role0/10/duplicate 失敗；處理改派與角色不存在 | Domain unit tests，不需要原 Client，policy 標 `PROPOSED` |
| **SR24-02** | Session | `SelectionAttempt(sessionLease, roleIndex, mode, idempotencyScope)` state machine / Timeout / duplicate / disconnect cleanup；永不以 Client `+CC` pending 當 ACK | 斷線/並行/replay/CAS 可靠，不自行產生官方 error code |
| **SR24-03** | Protocol / Gateway | 4-byte C2S42 parser／frame 與 app payload 分開，保留模式0/2為源級候選；對未知 69+3/+4 等 payload 不硬編業務值 | protocol payload static fixture 有來源、T02 lane 已評估，adapter 預設關 |
| **SR24-04** | Square / World | 將 SquareBootstrap 設計為選角成功後的**可選實驗步驟**，區分 UserData/ChannelState；C2S43 只驗必要限界、不要把到達當教學成功 | 受控合成測試經批准後，明列實際 Client/scene outcomes |
| **SR24-05** | Conformance / Test | [I24-T01～T20 計畫驗收](S00-20261031-ITERATION-24-ACCEPTANCE.md)：role guard、mode/dup、pending flag、short body、Scene/Square、多版本/錯序、教學前置 | 20 cases 全 `PLAN_ONLY/NOT_RUN`，不納正式 TEST index |
| **SR24-06** | T03/T02/T04/T05/T06/T01/S00 | 定向補證 C2S42 success/reject consumer、S2C69/7 真 scene/Conn/field bounds、C2S43 producer path、零角色建名/真正 playable role 招募、首次進教學 | 從現有 RR-0002/RR-0008/RR-0009/RR-0010 去重；不可直接把舊 BLOCKED 判 ACCEPTED |

### 特別分流：不因原版 Server 不可得停止 Client 靜態研究

- **Client 專責可繼續**：`scene+CC` pending 何時/由誰 reset、mode2 UI/資源分支、`C2S42` rejected S2C→頁面恢復、`S2C69` 的 lane/subtype/scene、`0x0033` 招募角色的真正可操作結果 writer。
- **Server 自訂決策可先開發**：合法 role slot/權限、帳號封禁影響 Session、角色選擇幂等/排他鎖、空角色與重登資料一致性、限流/重放、分開給前台和後台的資料模型，並定義至少一種可重試且不重複 commit 的 state machine。
- **跨功能需協同**：T02 transport、T03 選角、T04 角色初值、T05 Square/world、T06 UI、T07/16 新手教學、S00 SPEC/REQ/GAP/ADR/TEST。不能以「T01 FULL_PASS 於別的入口」冒稱 RR-0002/0010 完整成立。
- **待遊玩驗收（須另行授權）**：隔離的原版 KR Client＋新相容 Server，按 S2C2 → 使用者點選 → C2S42 → 候選 S2C69/7 → CSquare/C2S43→世界/教程，記錄實際 UI/多 Conn/資源/失敗重登。即使通過也只能稱 **自製 Server 相容**，不是 original official Server 時序。
- **仍需保留的正式狀態**：RR-0002、RR-0010 均 `BLOCKED`；RR-0008 依其最新台帳狀態；`GAP-CHAR-0001/0003` OPEN，`SPEC-CHAR-0001/FLOW-0001` DRAFT/PARTIAL。新規劃不覆寫研究者或其它 Task 的 source evidence。

## E. 下一輪 S00 開工順序及不亂加 REQ 原則

1. 實作者可先按 **SR23-01/02 → SR24-01/02** 完成 Account/Expedition/Role Authority + SelectionAttempt 的領域資料與合成測試；不用等待原版 Server 程式碼。
2. **SR24-03** 先只做 *independent parser/test fixture*，不要未經 T02/合成 Client 驗證就暴露可通公網的 native Gateway。
3. 需要錄入 S00 `REQ-0003`（角色完整與增量清單）、`REQ-0004`（role UI 就緒）及可能 selection 專用需求時，正式 `CODE_ANALYSIS` discovery validator 要求**同版本、現存正式 CLM**。E80 本輪仍是 T03 研究報告和腳本；**不拿舊 CLM 冒充新的 mode/ID/69/43 限定證據，也不虛構 REQ-0009**。新結果先在此設計文件及 DRAFT SPEC 記錄、交 T01 正式核對後再提出不同可驗收成果的 CANDIDATE REQ。
4. `SLICE-ENTER-WORLD` 繼續依賴 `SLICE-LOBBY` 而**非強制依賴 SLICE-CREATE**：持有既有可用角色的老帳號應能直接選角，不必每次重新命名或重做角色建立。新帳號仍須按 E05/E06 判斷是否需要 Expedition/角色資料。
5. 本次成果只在 [Iteration 24 驗收矩陣](S00-20261031-ITERATION-24-ACCEPTANCE.md) 和 DRAFT planning 中作可實施的工程建議；沒有改 `ttr_server_roy`、沒有啟動原 Client、沒有 T01 全函式驗收。

**最重要的設計交接**：`C2S42` **角色索引 + 模式是兩個不同欄位**；`scene+CC` 只是 UI pending、可能在 Client 未 send 時也置1；`S2C69/7` 是 Square scene 的有界候選而非已證選角 ACK。這三個界線要寫進 Server Parser/Session/World 三層防 BUG 設計。
