# T10-W07 — KR 戰鬥輸入→封包→角色結果的 S00 可實作性移交、E17-E/F/G Gate 與 I29 回歸矩陣

> **2026-10-31 19:12 Asia/Taipei，chatgpt-web roy，KR BIN-first，工作包 W07。**
>
> **本輪研究結論與完成範圍**：對應 T10–T11 聯合計畫的 **W07「S00／Server 可實作性移交與回歸矩陣」**，已將 T10 W00–W06、T11/T12 原生限定結論與 S00 Iteration29 的 **E17-E/F/G、S29-01～04、I29-T01～24** 逐一對照，提供同版 Client 封包、狀態、UI、未知、Server-only 設計與驗收門檻；新增原始 BIN 的交叉 source audit、12 種玩家情境和 24 筆計畫測試的機器可讀矩陣。**W07 交接目標完成；完整「某次真實普攻→原版 Server 施法成功/拒絕→命中扣血→死亡復活」因果鏈仍未完成，沒有被這份交接假裝閉合。**
>
> 這份交接是 **研究結果而非正式 SPEC／RR／TEST 的發布或 Server 實作**。T01 FULL-PASS、S00 RR ACCEPTED、SPEC STABLE、Server Mock domain test PASS、CompatibleClientRuntime PASS 五種結果必須各別審查，不可因為同版 BIN 來源或 Git commit 而自動取得。

## 0. 原件、工作基準與授權

- 唯讀 KR `Tartaros.bin` 12,472,320 bytes，**SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；KR `Tartaros.exe` SHA256 **03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f**。本輪在原始掛載檔上重新以 sha256sum 核對；未啟動、附加、patch 原始程式或網路 Client。
- PE32 .text VA `0x401000` / raw `0x400`，x86 .text raw=VA−`0x400C00`。rdata VA `0xBD2000` / raw `0x7D0600`，rdata raw=VA−`0x401A00`。不同版本不得共用這些地址。
- 開工 GitHub `main=ad1fda170734767c67dd0f62066a34ece34e118a`，`t10/roy/chatgpt-web=f0b2fafa9a88a8fdfdfcab3656ca40559e17e359`；compare **ahead1/behind0**，已包含最新主線，不需新增 merge commit；只會寫既有 T10 分支，不回推 main，不開 branch。
- 已檢查 Project `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T10-INSTRUCTIONS.md`，本地 `T10-T11-UNIFIED-ANALYSIS-PLAN-20261031.md` W07 工作包；GitHub main `AGENTS.md`、T10 README/task.json 的七筆 T01 退回、T10 S00 inbox/唯一 RR、`research/dispatch/README.md`、`shared/verified-knowledge/README.md`、S00 iteration29 計畫/驗收/JSON、`spec/README.md` 與正式 GAP/TEST 索引。
- **T10 收件箱當時無已派 RR**。T01 七筆退回已有 W00 限定修正版，但 T01 未正式複驗通過，不標 RESOLVED。`shared/verified-knowledge/` 當時沒有與本次完整戰鬥流程同範圍的 FULL-PASS；別項有限主張仍按其原有邊界使用。
- 用 BIN 的 37 項指令起始 bytes、14 個程式碼 SHA256 視窗、`000E` 原生 9 項 jump table 複驗本輪跨方向要點。檢查檔同目錄 `W07-native-audit.json`、`verify-native.py`；只讀；不是 T01 對每一 upstream/callback 的 FULL-PASS。

## 1. 可交 S00 的結果分級：何者是 Client 原生、何者仍是 Server-only mock

| 分級 | 本輪可以採用的限定主張 | **不可**因此推論 | S00 建議處置 |
|---|---|---|---|
| **NATIVE_STATIC_SCOPED**（尚非 T01 FULL-PASS） | Type0 Z/X/C 的 logical13/14/15 mask1/2/4；Z+X=3、Z+C=5、X+C=6 的矩陣 col4/5/6；000A 6+5N app buffer、Row A/B conditional append | 不得將實體鍵恆定、兩鍵=兩 row、每次按下=一次已發網路技能、000A=完整 socket frame | 可用於**具來源限定條件的 parser/研究 prototype**；在正式 native wire SPEC 前保留未知 |
| **NATIVE_STATIC_SCOPED** | S2C category2 key0/000B/000C/000D 的已查 6/8/3/9-byte row 與 actor memory effects | 不得稱每筆都是某一次 000A 的 ACK、成功授權或完整動畫 trigger | 可描述可驗證的**Client consumer 寫入條件**，不直接寫成 server 必發事件 |
| **NATIVE_STATIC_SCOPED** | S2C 000E 13-byte results、subtype0..8、場景 field+28、actor tree 查找；000F cannot-use-skill；001A registry erase | 不得稱 Client 自行算命中/HP、000F 一定拒絕某次技能、001A 就是死亡 | 作**結果 consumer / error hint / delete 的相容介面候選**，關聯仍列 GAP |
| **NATIVE_STATIC_SCOPED / CLIENT_UNKNOWN** | SkillMatrix ID/timer entry+4、local 545E20 8+6N 更新、SubAI 三資源 nonnegative gate | 545E20 的資料**未證來自某 S2C opcode**；三資源檢查不證玩家扣費；不證原版計時單位 | T11 繼續補網路 caller、具名技能、資源 writer、取消/冷卻 |
| **SERVER_TO_IMPLEMENT / PROPOSED** | Iteration29 的 SessionLease、ActionId/CastId/HitId/DeathKey、reservation、once-only HP/Death、重入與 outbox | 都**不是**原版 KR packet、Server 原演算法、原版必用的資料庫 schema | 交 S00 設計/ADR/Server repo；若需自訂策略標記 Server-only |
| **RUNTIME_NOT_RUN** | 12 玩家操作及 I29-T01～24 | 離線 byte checks ≠ Client 真正播放、Server 可玩、domain/mock PASS | 不在正式 `conformance/test-index.json` 建新的 PASS；先保留 NOT_RUN |

正式可升級為原生 SPEC 的下限不只是知名 app WORD：還需指定 **方向、連線 selector/queue category、frame mode、buffer 長度、欄位最終 writer/consumer、actor/scene identity、正負分支及不保證路徑**。未知必須顯示為 Client 待逆向，不以 Server-only 模型填空。

## 2. E17-E：普通攻擊／連段／取消、S29-01 的正確 Client 介面

### 2.1 Type0 輸入與真正的 double-key mechanism

- KR Type0 KeyMapping（DefaultType0 的工作 bank 有效時）：Z DIK44→logical13、X45→14、C46→15；其他 type/custom keybank 不是固定物理 Z。`0x545480` OR WORD[controller+5C] bit1、`0x5454FD` OR bit2、`0x545578` OR bit4；phase1 press 或 phase2 held 均可到 producer。
- 在三個 bit 的特定共同 sampling frame，Z+X→mask3、Z+C→mask5、X+C→mask6。`54566D` logical24 可 OR3、`5456E8` logical25 可 OR6、`545763` logical26 可 OR5；**不能因此證實 ID24–26 是物理雙鍵事件的唯一合成 upstream**。
- `0x54F270` 先評估 bit0+1（`54F28A` col4），再 bit0+2（`54F297` col5），再 bit1+2（`54F2A6` col6），才看單鍵 columns1/2/3。mask7 在此 predicate 先命中 col4，但後續還有 actor/SkillMatrix gates；這不等於會播放 3 個技能。
- `546100→546263 call546780→5467F4` collector 將 controller mask 送到一個 callback local，特定 owner subclass 的 `000A` Row A high WORD 可攜帶 3/5/6，**不必拆成兩個 5-byte row**。`546302` 或 Row A owner+58 等分支仍可能在 append 前清掉 mask。Row B 是其他 actor vector+tree+virtual+44 producer，並不是第二鍵記錄。

### 2.2 C→S 000A 是有界 app payload，不是「一次攻擊一定成功」

`545824` 初始 length=6，`545829` opcode0x000A。最終 app header 的 +2..+5 是 `545887/54588D` 從 `DWORD[F93944]` 覆寫的值；不能命名為已證 SkillId/RowCount。後面 Row A/B 可各自追加一筆5-byte row；兩路第五byte受 callback, owner+58 及 W00-116 勘誤條件影響。`545B38 cmp length,6;545B43 jbe`：**N=0 不呼叫此 builder 的 sender**。若 N>0，`545B6F push0` selector0、`545B71` virtual+10→候選 `8069A0` connection tree→`8060D0` Pending→framing pump→conditional WSASend（T02/T10-115～118）；enqueue 和 WSASend 都不是 Server 業務受理。

可確認 app geometry：
~~~text
app+0 : u16 0x000A
app+2 : u32 runtime [0xF93944] (unknown business semantics)
app+6 : zero or more 5-byte rows:
 row+0 u16 (final direct load WORD[R+4])
 row+2 u16 (callback/flag/action-mask mutable)
 row+4 u8  (callback/local mutable)
length = 6 + 5*N; only N>0 enters local send call
~~~
**不能**做的過度契約：Server 按 mask3 扣 Z 與 X 的兩次技能資源；由 row count=2 判定雙鍵；認定 000A 一次=一次成功施放；用 000A bytes 當最終 TCP header；由 V long-press 的 500ms 推 Z 普攻 combo 窗口。

**S29-01 mock**：Server-owned AtomicAttack、ActionId 去重、session fencing、combo window & cancel 只能作 PROPOSED domain 設計。原版 Client cast phase/起手/後搖、輸入節流、可取消時窗、特定玩家跟哪個 S2C opcode 相連仍是 **CLIENT_UNKNOWN**；不能把 S29 的窗口判定改標 Native。

## 3. E17-F：技能、消耗與冷卻、S29-02 的 Client/Server 分界

### 3.1 local SkillMatrix 可用，不是原版 Server 扣費已證

`5462DD call 54F270` 可依 mask 選 matrix column，`54F2E0 call819220` 查角色 row，`54F2F7 call81A8E0` 取有界 tier<4/column<11 的 u16 value；非零時 `54F310 call54F4E0` 取得 per-key timer entry、`54F317 cmp DWORD[entry+4],0` 判可用。若 mask 有 0x40/0x80 或 mask0 等 branch，predicate 也可直接 TRUE、**根本沒查矩陣/冷卻**，故 return TRUE ≠ 已施放。
- `54F200` 遍歷 timer tree，`54F217` 對 entry+4 非零值 DEC1；沒有在此用 milliseconds 作時間乘積，不能推1 tick=33ms或1s。
- `545E20` 是會**寫** timer entry 的另一端；按角色 slot 比對後，輸入 P+4==0，長度8+6N 解析每筆 u16 key / i32 數值，除以33後存 entry+0/+4，非零才設+8。**此 buffer 的來向/virtual+40 caller/真正 opcode 尚未證明**，不能稱「S2C技能冷卻封包」。P+4非0則另一 clear-helper branch，不能假定每次可用。
- `549980` 是經 `54AE83` 的 SubAI condition；`549BB6/549BC2/549BCC` 取 actor+3C8/3CC/3D0 與三個 signed adjustments 相加，`js` 判負數跳 fail，再 `549C0E call54F270`。這是**三欄資源/技能條件讀取**，未在此 block 寫回扣費值；且玩家直接 action builder 並未證每次走 549980。
- W04 已證 S2C 0000 某 actor subtype/prop4 可寫 actor+3E8，下一輪 controller gate 可讀，說明**收到狀態能影響後續技能輸入判斷**，但屬性4不因此等於官方 MP/cooldown。

**S29-02 mock** 的 reserve→commit、單次資源扣除、Server monotonic tick CD、cast cancel/refund 必須經 Server 設計核准：它們在 Iteration29 被明確標記為 Server-owned proposed，原版技能身分、MP/SP 命名、費用、CD 值/單位、何時扣除及 Server 傳回哪些訊息仍有 CLIENT/ORIGINAL-SERVER 不同缺口。使用者要求「普攻為技能之一」可做相容 Server 的**內部 action 抽象**，但不是 Client 原版 C++ class/官方 backend 做法。

## 4. E17-G：命中、受擊、HP／死亡、S29-03 的結果消費端

### 4.1 S→C 000E 是「已形成結果的呈現」而不是公式

既有 category2 handler table `4ADDEA` key14→`436C40` field virtual+28；CMissionField 候選 `4B0640`，CScenarioField/CInfiniteDungeonField 候選 `4C4920`（`4C4951` 先 call `4B0640`，再按特定 subtype 加 `54A8F0` 目標回饋）。`4B0745` magic count、`4B0770` stride13，app payload 長度 `2+13N`：
~~~text
row+0 u16 first actor tree ID
row+2 u16 second actor tree ID
row+4 s8 subtype 0..8 (index into code table at 4B1914)
row+5 s8  subevent/display source
row+6 i32 result value (may be mutated IN PLACE by Client)
row+10..11 2 bytes: semantic UNKNOWN
row+12 s8 additional branch input
~~~
`4B07AF`/`4B0819` 查 actor tree，缺任一物件可跳過該 row。`4B0B62` 跳九路：0→`4B0B69`，1→`4B118B`，2→`4B0EEC`，3→`4B0E5A`，4→`4B0D14`，5→`4B15B7`，6→`4B1313`，7→`4B18D9`（Mission 該 case 不做專屬效果），8→`4B1673`。這些值不是普攻連段次數、技能型別或死亡 code 的已證 enum。
- `4B0AF0` subtype=1 的特定 local slot/list gate 下，`4B0AF9 neg eax;4B0AFB mov[row+6],eax`：**Client 可能改寫收到的結果 i32 後才做 UI/累計**。`4B0B3F` add `F942C4` 並於負值清零；未知是否為分數/效果累計。不可把 UI 的負號推回原版 Server 真的傳負值。
- `4B0640` 部分分支寫 actor+40C/+410/+414，呼叫 `49B0D0→7ABCD0`、`7AC030`、`5521D0`、`7D28E0` 等視覺/附屬效果；在本輪所審直寫處**未**直接看到通用 actor HP store。callee 和其他 S2C actor property handler 仍可能有 HP writer，因此不能說 Client 全域不更新血量。
- **001A** `4B28D0` 是 `4+2N` actor ID 刪除列表，`4B2AC2 call4DFBC0` 從 actor registry erase；**消失≠死亡或復活**。其他場景可能因離開視野、切圖等移除。
- **000F** `4B19D0→controller vtable+3C=545C50` 的部分分支在 `P+7!=0` 使用 `CANNOT_USE_SKILL`，`P+7==1` 另讀 `P+8` bits 作提示。已有 Client 不能使用技能 UI/音效消費者，但**未證與某次 000A 的 nonce/mask 直接關聯，甚至全部 payload 長度仍待精確核查**。

**S29-03 mock** 的 damage、HP、唯一死亡事件、checked integer 和 HitId 去重是 Server-only 計畫，不是由上述結果視覺函式推導出的官方原生計算。原 T12 已明示半徑45/65、傷害20/35/60、delay0.2 為 **AI_FIXTURE**；無論本輪證實 000E parser 多完整，都不將這些數值升格為原版命中公式。

## 5. S29-04：斷線／重登／取消／死亡通知與目標的兩層分隔

**Client 可以直接指認的**：input sampling 的 phase、manager state、000A send gate、000B／000C／000D actor state/效果、000E result、000F不能使用技能、001A remove；某些 owner+74/actor+3A8 或 actor+3E8 可依 S2C 狀態改變本地 gate。**Client 尚未證**：可取消時窗、取消封包／callback、施放中移動與命令先後、斷線重登時未完成 cast 是否回滾、server S2C 成功拒絕 correlation、真實 ActorDeath 與 Scenario/Quest 的觸發因果。
- **Server-only 兼容策略**：S29-04 用 session lease/revoke、角色/scene/encounter fencing、Action/Cast/Hit/Death unique keys、after-commit outbox/crash recovery 等，是合理 Server domain 設計**提案**。不能用它來聲稱 KR Client 使用 ActionId/CastId 或原版 Server 持久化這些資料。
- **目標/Quest/教學勝利另有獨立 owner**：即使新 Server 模型有某個 validated ActorDeath，不代表原版 Scenario14 terminal 或 Quest14/16 一定立即完成。S00 計畫要求 ActorDeath 再經 S27-W05 objective gate；T14/T16 仍需原生驗證，不可用 000E subtype7 或 001A 替代死亡任務證明。
- **尚未證實**的 Client move/cancel/remote animation/collision 不能靠假造一個 packet、delta、固定0.65秒 chain window 或假設服務端「看到持按就自動續段」消除；要回 T09/T10/T11/T02 繼續追實際 writer/reader。

## 6. W07 機器矩陣：12 個玩家情境（positive / negative / unknown）

完整欄位的 source/owner、C→S、S→C、motion、未知及 evidence status 存放同目錄 **`W07-S00-matrix.json`**；下表供 S00 先人工分流：

| 情境 | 玩家/系統操作 | Client 已有直接證據 | C→S / S→C 未知或負分支 | 相容測試級別 |
|---|---|---|---|---|
| A01 | 單按 Z | phase1 mask1，矩陣col1，000A條件性建包 | 可能 **0筆 row** ⇒ 該 builder 不送；結果回包因果未知 | Native static scoped；runtime NOT_RUN |
| A02 | 連按 Z | phase 及計時 gate 可重評估 | next combo stage、時間窗、packet 次數未知 | Client GAP；runtime NOT_RUN |
| A03 | 持按/放開 Z | phase2也可設bit1；phase3 在所查 producer 不再寫此bit | 放開不等於全系統無發包；持按頻率未知 | Client GAP；runtime NOT_RUN |
| A04 | 單鍵 X/C、三組雙鍵 | mask2/4/3/5/6→矩陣 col2/3/4/5/6 | Row A 可一次承載雙鍵，不保證 append/accepted | static scoped；runtime NOT_RUN |
| A05 | 普攻中按技能／技能中按普攻 | actor/callback 有 gate | queue/drop/interrupt/立即送及 S2C 都未知 | Client GAP；runtime NOT_RUN |
| A06 | 起手／施放中／後搖連按 | local timer 可用判斷存在 | cast phase/重試、正式 CD start/cancel unknown | Client/T11 GAP |
| A07 | 施放中鍵盤移動 | keyboard input/方向 mapping 已找到 | 尚未 closure 至移動 app producer & cast state | Client T09/T02 GAP |
| A08 | 施放中滑鼠移動 | 另有 20-byte mouse DirectInput state | 不能套鍵盤 producer；移動/取消意義未知 | Client T09/T02 GAP |
| A09 | 不足資源或冷卻中 | 本地 matrix timer predicate、SubAI資源檢查、000F提示 handler | 不能保證本次會送或收到000F | Client/T11 GAP |
| A10 | 其他角色的攻擊／動畫 | 000B/000C/000D actor state/effect 查表 | clip 播放與本地/遠端 subtype 未全閉合 | Client T09/T08 GAP |
| A11 | 命中／受擊／死亡 | 000E 13-byte result 消費，001A 刪除 actor | HP真正 writer/death/000A關聯未知 | Client T12 GAP |
| A12 | 取消／受擊／斷線／重登 | actor/manager state、lease mock 概念要分層 | 未證真正 Client stale replay、取消、回覆 | Client GAP + Server proposal |

**正／負測試原則**：
1. 000A正面：至少 1 row append 才可進 selector0 sender；負面：N=0 此 builder 不呼叫 sender。兩者**並非**可直接要求原版 Server 的連段次數/時間窗。
2. 技能正面：mask3/5/6 在 54F270 正確選 col4/5/6；負面：matrix ID=0 走 predicate false；反例：0x40/0x80 bypass 可返回 true 但無施放事實。
3. 結果正面：000E row actor 均存在且 subtype0..8 相符才能有對應 consumer；負面：actor missing、subtype out of range、case7 的指定 handler skip；不能變成「Server必送不可見效果」。
4. 技能拒絕：000F有 Client 不能使用技能音效／提示消費者，但未證「收到000F一定對應此 C2S attack」；要做 mock 負面測試可先測 Domain reject，不可自動標原生拒絕。
5. 物件移除：001A 可 erase，但沒有原生死亡判定/復活/Quest terminal 的必要連結；Server mock 的 once-only DeathKey/Quest gate 只能用 I29 domain tests。
6. 斷線/崩潰：I29-S29-04 的 unique keys、outbox 重送和 SessionLease 必須由獨立 Server 測試驗證，屬後端提案；原版 Client 恢復順序仍需可見封包/原始程式查證。

## 7. S00 Iteration29 S29-01～04 與 24 項 I29 測試的實際對照

| S00 專案 | Gate | 原生研究交付 | Iteration29 planning tests | 執行狀態 | Server-only 與不可升級項 |
|---|---|---|---|---|---|
| `S29-01` | `E17-E` | W01～W03：Type0 logical Z input、雙鍵 mask、SkillMatrix、C2S 000A builder+selector0 conditional network | **I29-T01～T06**（攻擊身份、租約/Actor權限、重送、衝突、時窗） | **6/6 NOT_RUN** | ActionId、mock chain window/TimeStamp 由 Server 自行訂，與原版未知 window 不同 |
| `S29-02` | `E17-F` | W03/W05：合成鍵的矩陣欄位、本地 timer entry+4、SubAI 3資源 nonnegative gate、545E20 8+6N internal update | **I29-T07～T12**（reserve、資源競爭、冷卻、取消、未知技能、重放） | **6/6 NOT_RUN** | CastId/cost reserve/commit/refund 未證原版；技能ID、CD時間、network caller 仍缺 |
| `S29-03` | `E17-G` | W04/W06：000E 13-byte results/9 cases、000B/000D actors、000F警示、001A移除 | **I29-T13～T18**（hit/HP、偽造損傷、邊界、去重、唯一死亡） | **6/6 NOT_RUN** | hit formula、HP authority、DeathKey 是 mock；沒有原版打怪HP死因的完整鏈 |
| `S29-04` | `E17-E/F/G` | W04/W06 局部 actor update/result 及明確未知 cancel/reconnect/Objective | **I29-T19～T24**（取消競態、ban lease、crash、outbox、death handoff、Client E2E no-go） | **6/6 NOT_RUN** | Server recovery 不代表 Client original protocol；T24 native adapter OFF |

原 Iteration29 文件直接說**全部 24 個 I29-T01～T24 是 `PLAN_ONLY/NOT_RUN` 的 Server-only mock/domain acceptance plan**，不是 `conformance/test-index.json` 的正式 `TEST-*`。本次機器矩陣每項保留 `evidence_class="SERVER_DOMAIN_SYNTHETIC_PLAN_NOT_NATIVE"`、`status="PLAN_ONLY_NOT_RUN"`、`native_client_pass=false`。本工作只對照它們，**沒有建立正式 TEST、新 RR 或更改 existing index**。S00 是否在下一輪納入正式規範，須按來源/風險/REQ-SPEC-GAP-ADR-TEST 既有流程去重批准，並且持續保留其與遊玩驗證不同。

### 7.1 對 S00 的「建議受理清單」並非新台帳

| S00 待接議題 | 已有 Client 限定輸出 | 應歸的正式位置（由 S00 查重） | 不可偷渡 |
|---|---|---|---|
| 普攻與三組雙鍵 | C2S 000A payload 存在，mask3/5/6 等欄位有條件入 row | E17-E/E17-F 既有 gate；如果需新增候選需求，依 REQ 接收，不由本稿產生假 ID | 不假定官方 skill identity/成本/連段 |
| 處理失敗/拒絕 | 000F cannot-use-skill handler 已證，缺全欄位/對應 | Client gap → T10/T11/T02；Server domain rejection → 既有 S29 proposal/ADR | 不寫 native reject ACK |
| 資源冷卻/技能可用 | matrix/timer/subAI 有限 Client 證據 | E17-F/ S29-02，T11 須研究 named skill + timer network origin | 不把 545E20 當 S2C/把33當33ms |
| 結果/死亡/移除 | S2C 000E result 2+13N, 001A delete 4+2N | E17-G/S29-03 + T12 Client gap；S00 server mock hit/death | 不把 001A 視為 ActorDeath 或 Quest14 |
| 跨 Session / Crash | Client queue/scene/actor states 與其限制 | S29-04 Server-only lease/outbox plan，由 S00 機制批准 | 不把 SessionLease/ActionId 當 Client wire |

**如 S00 只想先開發 domain mock**：可在獨立 `ttr_server_roy` 依正式核准的 Server 設計完成 Action/Cast/Hit/Death 交易、fencing 與 synthetic tests；**原版 Client native adapter 仍必須 OFF** 直到具方向與 frame 的 packet/response 實際對照完整、且授權隔離 Client runtime 驗收。每次新的 Server mock/pass 必須另回報 Server commit、DB migration、fixture、actual TEST status；本分析沒有執行 Server 或 DB。

## 8. 跨 Task 補證順序／不得假裝已達成的功能鏈

### Client 待逆向（明確下一入口）

1. **T10/T11 單次 Cast→連段／取消**：`5452C0` owner+78/actor+158/+3E8 gate，`546100` callbacks/不同控制器 vtable、`54F270` matrix tier→真正具名 KR hero skill ID；和 T09 動作派生/clip queue 交叉。按下、連按、held、放開各自的 native producer/packet 時序，禁止拿 V 500ms 長按或 AI 0.65 秒當 Z 連段窗口。
2. **T02/T10 真 wire framing／方向/Connection**：`545B71→8069A0→8060D0→8061A0→807A70/807830→8068B0` 的最終 frame 對應原 Client WSARecv parsed application response；selector0 category2 與 app opcode 不是相同 namespace。實際 connection mode、reorder、第一次封包及安全長度待證。
3. **T11 timer network origin/資源 writer**：`545E20` virtual+40 的實際 indirect caller，P+2 slot、P+4 clear branch、8+6N records 的來源，+4 倒數、時間 unit、actor+3C8/3CC/3D0 實際扣費/恢復；`0000` property4→actor+3E8 是已證不同路。
4. **T09/T10 鍵盤 vs 滑鼠移動/受擊取消**：Keyboard logical movement與 20-byte mouse DirectInput state 分別查 actor move producer、施放中 actor+0x158/scene state，判明會立即送、延後、抑制或落入 virtual callback；不能用 000B consumer 的存在補出 C2S move packet。
5. **T08/T09/T10 遠端角色動作**：000B／000C／000D 透過 actor tree、vtable+58/+68 和 actor+F0 subobject effect；沿 W04 `7A6970→7A7800` 真正 asset/animation start、actor class/constructor，並區分遠端 actor/本地 actor。
6. **T12 Health/Death**：000E result row+10/+11 尚未知、actor+40C/410/414 effects／`49B0D0→7ABCD0`／`7AC030` 等下游及真正 HP/death-state writer；001A erase之因、死後保留/移除/復活 S2C opcode。即使原版 Server 內部公式未知，Client wire & death consumer 仍須繼續找。
7. **T02/T10 rejection**：000F P+2..+6、P+7 value enum、P+8 bits、從 C2S000A 到警示是否有同一 skill/actor/correlation key；不能以音效存在當正式 ACK。
8. **T14/T16/S00 Objective**：只有經 Client/S2C 或 domain 合規確定的 actor death identity 才能進 objectives；Scenario14 terminal 與 Quest14/16 的真正 Server/Client 關係另行核對。

### Server 待開發（原版 Server 內部規則未知，但不阻止 Client 分析）

- 有效 Session / actor / scene / encounter 的 Server 自有授權；遊戲技能／combination 的 Server 端 action model；資源/冷卻/cancel/連段流程；命中／傷害／HP／死亡；其他 actor 的場景廣播；出錯時穩定狀態修正與去重／恢復。**只在與 Client 已證必要介面匹配時才能稱 native-compatible**。
- 原始 Server 的真正驗證規則、冷卻時間、技能費用、資料庫 transaction、走幾條連線、combo 允許窗口及 AI/怪物數值在本研究沒有 native Server 來源；自行定義的策略應標 `PROPOSED ADR`／`SERVER_ONLY_MOCK`，**不是「已還原原版」**。

### 跨功能待整合

T02 networking/framing、T04 actor owner、T08 monster/entity、T09 motion、T10 input/combo、T11 skill cost/CD、T12 hit/death、T14/T16 tutorial/Quest、S00 REQ/SPEC/GAP/ADR/TEST。**本工作未跨界修改其原稿、RR 狀態或設計索引**。

### 待遊玩驗證

原版 Client 按 Z/連按/持按/放開、三種雙鍵、技能中按其他鍵、鍵盤與滑鼠移動、被打/取消、資源不足與冷卻中、遠端 actor 動畫、HP/死亡/重生、斷線重登、實際 TCP frame 和結算，**一概 NOT_RUN**。除 W07 offline 原始 bytes audit 外，無任何 Client/Server runtime，不能把 I29 的 `PLAN_ONLY` 變成 `PASS`。

## 9. 原生稽核、資料布局和不誤判的回歸檢查

同目錄的 `W07-native-audit.json` 針對 **37 個 VA→6-byte 指令片段**、**14 個連續 .text 原件窗口 SHA256**、`4B1914` 9-entry u32 table 作完整原 BIN 身分驗證。`verify-native.py` 只讀 `Tartaros.bin`，若附 `W07-S00-matrix.json` 則檢 12個 scenario、24個 I29 test、全部 NOT_RUN/非原生、native adapter OFF；另用純數學檢 mask3/5/6/7 的 predicate 優先序及 000A raw length 上限。**後兩項是 symbol/geometry regression，不是啟動原版 Client、提供真實封包、測試技能或 Server 模擬。**

精確本輪 byte anchors 中幾個直接舉例：
~~~asm
545480 66 83 4B 5C 01      or WORD[ebx+5c],1
5454FD 66 83 4B 5C 02      or WORD[ebx+5c],2
545578 66 09 73 5C         or WORD[ebx+5c],si ; SI=4 on scoped path
54F28A B3 04               mov bl,4 ; combo bit0/1 matrix col
54F297 B3 05               mov bl,5 ; bit0/2
54F2A6 B3 06               mov bl,6 ; bit1/2
54F317 39 48 04            cmp [eax+4],ecx; ECX=0 local availability
545B38 83 3D D0 48 FE 00 06  cmp DWORD[FE48D0],6 ; N=0 builder no send
4ADDEA C7 40 74 40 6C 43 00 mov DWORD[eax+74],436C40 ; S2C 000E field vfunc
436C40 8B 01 FF 60 28      mov eax,[ecx]; jmp DWORD[eax+28]
4B0770 6B C0 0D            imul eax,eax,13 ; 000E row
4B0AF9 F7 D8               neg eax ; 000E result value local mutation under gate
4B0AFB 89 43 06            mov DWORD[ebx+6],eax
4B0B62 FF 24 85 14 19 4B 00 jmp DWORD[eax*4+4B1914] ; actual subtype table
4B2AC2 E8 F9 D0 02 00     call 4DFBC0 ; 001A actor-map erase helper
~~~

**反證必讀**：`4B1914` 真的是 DWORD table，不能按 objdump 線性機器碼解讀為正常 instruction。`545B38` 的 send gate 只限定該 builder；不能「未找到某 opcode」反推全 Client/所有技能沒有任何訊息。`54F317` 成立只代表該 local predicate 而非 cast 成功。`4B0AF9` 改值是在有限控制流程，不可擴張到所有 subtype。`4B2AC2` 是 actor removal 路徑，不能直接稱 Death。
 
## 10. S00 接收操作與正式驗收門檻

1. 先讀本報告與機器 `W07-S00-matrix.json`，逐項核對原本 `E17-E/F/G`、`S29-01..04` 與正式 REQ/RR/GAP/TEST **已有 ID**，不新增平行管理台帳，不自動將 T10 branch 的研究當作已發布正式 S00 spec。
2. 候選 Client-native contract 應寫**適用 subtype/actor/scene/connection、內存 app buffer 的 prefix/row/guard 與 UNKNOWN**；只在 T01/完整來源複驗及設計流程要求成立後才提升 spec maturity。若 Server mock 需要未證欄位，native adapter 必須保持 **OFF**、它的合成 DTO 不聲稱原生。
3. I29-T01～24 若後續真的在新 Server 執行，要附 Server commit／database migration／fixture SHA、lease/revision、expected/actual、runtime evidence class；不同測試類別 **DOMAIN_SYNTHETIC、NATIVE_STATIC_SCOPED、COMPAT_CLIENT_RUNTIME、ORIGINAL_SERVER_CAPTURE** 不可混用。W07 沒有執行任何這些測試，24/24 **PLAN_ONLY_NOT_RUN**。
4. 原始 Server 的內部 dedup/DB/cooldown/hit policy 不能由 BIN 證實；但**Client 的必要封包、consumer、動畫、property/motion/death writer 仍應 T10/T11/T12/T02 繼續有界逆向**。RR 真正被 S00 指派時再走唯一台帳的 CLAIMED/SUBMITTED/IN_REVIEW/ACCEPTED，沒有正式 RR 不在本分支單方面建立。
5. 即使 Server 有 once-only ActorDeath，也須經獨立 S27-W05 Scene objective gate 才能考慮 Quest／過關；這一交叉責任不屬 T10 自行決定。

### W07 完成判定與 remaining scope

- **已完成 W07 指定的交接驗收目標**：S00 能看出 **KR Client 可供有限契約的 app payload / 角色 memory consumer**，區分 **Client 未證的 action correlation/具名技能/取消移動/HP death** 與 **Server-only mock policy**，並逐一分離 I29 的 24 個 `NOT_RUN` 測試。
- **尚未完成更大 T10 gameplay 回溯目標**：普通攻擊 combo stage、官方 chain/cancel 時窗、原版 Server 受理/拒絕與單次 000A→000E 因果、真實本地／遠端 clip start、具名技能對應、角色死後復活與 Scenario14 完成等，維持 Client 待逆向／跨 Task／Server 待開發的可追查清單，**不能因 W07 handoff 已提交就說整個 T10 fully reverse-engineered**。

## 11. 精確來源、Git blob、跨 Task 現成原稿

**S00 iteration29 權威基準（main snapshot）**：
- `governance/s00-iterations/S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md`：blob `70db8208ffb765ca12c7b937173f5c52ce4b38d2`。
- `governance/s00-iterations/S00-20261031-ITERATION-29-COMBAT-ACCEPTANCE.md`：blob `b632d7f09850c660352ec25d15a6b3f3db1b3a93`。
- `governance/s00-iterations/S00-ITERATION-29-C05-COMBAT-CONTRACT.json`：blob `bb22562f91ea5cf4fc361630697ab554f6f00e1d`。
- `governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json`：blob `1f2a7bc63e6bed56c6d5f63a5a2d248f100ea71e`。
- `governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json`：blob `6655e480f3cedb8556d2700a89ef6e9cbb3bd208`。
- `research/dispatch/inbox/T10.md`：blob `0c602bd7c7a3763ff9ebbdf7218a9032bf353160`；`research/requests/index.json` blob `e6ad2a094dc7079acd6e0b09d38e0de3415fda62`；`shared/verified-knowledge/README.md` blob `710e76a446ff807e4d49c724cbc734fcf21c9481`。這些快照後 main 有新提交時須再核對，不把日期寫成永久狀態。

**T10 原生 bounded 原稿（研究原稿，尚非 T01 全文 FULL-PASS）**：
- W02 `kr-temp-roy/T10/W02-20261031/20261031-163141-chatgpt-web-roy-T10-W02-basic-attack-as-skill-native-difference.md` blob `e8a0cedc28c28968905e914d01379915fe9dc17f`。
- W03 `kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md` blob `62d31e8b3d8a450e644362092fd04e7ae696c729`；combo supplement `kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md` blob `0d17362eb300ab8ea002c3d6380d5a41039665bc`。
- W04 `kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md` blob `8e915daab064177490d5de0b3f193810a5de2f41`。
- W05 `kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-skillmatrix-resource-timing-T11-handoff.md` blob `b3c0f31db311cce06f3a87fcbbf4f938171ce972`。
- W06 `kr-temp-roy/T10/W06-20261031/20261031-184010-chatgpt-web-roy-T10-W06-hit-result-death-T12-boundary.md` blob `69189fda3fee408c373738a1c1113f9470b9d640`。
- W00-116 原始錯誤「所有 Row 第五 byte 一律 R+B0」已在 `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md` blob `bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804` 勘誤；W00-007/026 等其他退回同樣保留 T01 正式再審需求。

**T12 獨立既有 bounded evidence**：`kr/evidence/0124ca7a9184fc541708d37dee2516ec3d5f7bd788b1bbeb9df8f86399f81f71.txt` blob `bad6176b400a4ac0154762ac20501122a0081e74`；`unclassified/evidence/41fa17caac92ad6409c7de8bc4aa770123b0b0671b54a16ad035dce179ea11d7.txt` blob `9697f43ae371d668c88fa79a46424d1af6ab5c63`；`kr/evidence/401e0526feff1cb6f88298a2b5ec7bed454705259fd5846c0f80283664c5ff0d.txt` blob `dda5fbadd5341ff139209d004f014ae3e735ad31`。

**本輪原件稽核**：與此報告同目錄的 `W07-native-audit.json`、`verify-native.py`、`W07-S00-matrix.json`。保留完整 repo 相對路徑和實際 blob SHA（提交後讀回）；不可只憑以上路徑或摘要宣稱已在 main 正式整合。

*附註*：以上中文「技能、結果、效果、actor、Scene、SkillMatrix」有些是研究者描述名/既有專案用語；不存在具名原始 C++ 符號與 Server 官方 enum 的部分均按欄位/分支/記憶體證據限定，避免將 Client static inference 過度擴張。
