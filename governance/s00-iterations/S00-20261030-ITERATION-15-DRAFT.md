# S00 Iteration 15 — KR roster→初始化→角色 UI：事件路徑與「資料就緒」反例矩陣

> **本地研究交接稿，尚未 Commit/Push。** 2026-10-30（Asia/Taipei）。已核對 GitHub `we88ec3-prog/ttr_anal_multi main@dd69ec9de353a695d25c6db8e362ff471ea0c137`；`ttr_server_roy main@2901f05eeb229ee2c3c0e9a46b6248aa555c3309` 的 `contracts/spec-revision.json` 正確鎖定前者。Client 対象 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**本輪只重新閱讀已保留的 GitHub 研究證據／台帳與上一輪 Iteration 14，不曾取得原始 BIN 重新獨立驗證，也不曾執行原版 Client、連線或抓包。**

## 1. 研究目標與與 Iteration 14 不同的新整理

Iteration 14 已分清 `F42EF` writer/consumer 與 `0x665150` 的 list-hit／record-ready。Iteration 15 在不重做原生工作的前提下，再把 **`F4246` / `F4247` / `F4278` 各自的有限 UI 消費、`0x4B7F00` 發送初始化請求的事實，以及 GUI 事件與 roster 消費之間仍斷開的邊**整成兩層不同的因果圖。提供 [16 例純邏輯前提工作表](S00-ITERATION-15-UI-PREDICATE-WORKSHEET.json)，不是新增 `TEST-*`、不是 Client 測試，更不是 Server 完成度宣稱。

**本次新增的設計收斂**：角色清單能進入 record copy 以後，仍不能從任一個可見的 `F4246/F4247/F4278/F42EF` local consumer，逆推出「名單已收 → 該 UI 事件必然發生」。尤其 `0x4E5FB0` 的既有局部結果偏向 rank/interface 更新，**在那一處**沒有看到泛用 roster refresh；但原先對 `0x4B7F00` 的 def-use 有截斷限制，**也不能反過來宣稱不存在其他 UI refresh producer**。

## 2. 收包路徑與 UI 事件路徑分開呈現

### A：network/app command2 路徑（只有局部正證）

```text
已知 S2C 應用路徑（非已觀測 wire 時序）
  app command 0x0002 / first-level dispatch
     └─ 0x4B7F00  （必要 resource/scene/state 使得迴圈可達）
          ├─ 65-byte prefix + 53-byte × N 完整 records
          ├─ record+0x2E → unsigned ID<=9 與有效目的指標
          │     └─ 0x4D4150 → F94304+ID*0x210 → record+0x5C=1
          ├─ local command 26+ID 的 3-byte 初始化請求（仍有 gate）
          ├─ 其他局部初始化請求（24/1F/25/15；有效 ID 的 DA/D2）
          └─ 0x4E5FB0  局部 rank/icon 類效果（不能當一般 UI refresh）

          >>> 尚未證實直接發出 F42EF / F4246 / F4247 / F4278 <<<
```

這一層的 `26+ID` 是 **Client 本地構建的應用請求**，不是已確認每個 ID 對應的原版 Server 回覆。資料形狀 `65+53*N` 也不能保證前面已讀的 header 偏移安全或無效字串的原版行為。`N=0` 是可能的幾何測試情境，並**不**證明會自動跳到創角畫面。

### B：GUI 事件與畫面細節路徑（並非 wire）

```text
來源條件不同的本地 GUI producer（不以網路 command2 為已證前提）
  0x660260 ─ 0x578 / 0x641 及 identity gate ─ F42EF (+0x14 來自 +0x1A8)
  0x673DA0 ─ 0x578 及 identity gate       ─ F42EF (+0x14 來自 +0xD8)
             └─ event 0x387 某條分支      ─ F4247

  F42EF local consumer: 0x5A69E0
       ├─ event type +0x10 == F42EF
       ├─ 虛擬方法回 0x105B9 才能在已證正常支線取 +0x14
       ├─ 0x665150(candidateID)；包含 table-hit 和 record-ready 兩種 gate
       └─ receiver+0x13C dialog virtual +0xD0

  F4246 / F4247 / F4278 local consumer: 0x5A67D0  （獨立函式）
       ├─ F4246 → 40AFC0 result+0x14 作 ECX，dialog receiver+0x138
       │            └─ 0x672F00 → dialog virtual +0xD0
       ├─ F4247 → receiver+0x138 dialog virtual +0xD4
       └─ F4278 → 僅在 40AFC0 result+0x14 == 0 時
                    0x672F00(ECX=0, dialog receiver+0x138)
                    → receiver+0x13C virtual +0xD4 與後續訊息路徑

  >>> F42EF 投遞器 virtual+0x15C 與其 listener/receiver 實際訂閱、
      以上三事件的完整 producer→consumer、dialog 資源生命週期均未完全閉合 <<<
```

`F42EF` 不在 `0x5A67D0` 的 switch 裡是**局部排除**，不是不存在消費者（另一個 `0x5A69E0` 已有局部證據）。`F4247` 已有 `0x673DA0` 局部 producer 和 `0x5A67D0` consumer，但中間實際 subscription 和 event delivery 時機仍未知。控制事件 ID（包括 `0x578`、`0x387`）不應變成 Server S2C opcode。

## 3. 細化 `0x665150`：Server 不可採用的三種假驗收

以下是既有 T03 `LOGIN-02` x86 原稿的**有限敘述重排**，不對其全部函式作新的 BIN 複驗。先假定 `FE1DF4` 已完成可能的 `F94390 bit0 / 0x4E1590` lazy initialization，且所有指標合法；不然連以下模型都不能無條件套用。

| 條件 | 以既有 source 支持的局部效果 | 不能推論 |
| --- | --- | --- |
| ID **不**在 `FE1DF4` 的 8-byte stride 表 | `0x665150` 返回 0；caller `0x59A520` 不進行自己的 `+D0` 通知；若在合法 F42EF consumer 支線，`0x5A6A28` 的 `+D0` 仍無條件呼叫 | UI 必定關閉、Server 拒絕角色 |
| ID **在**表中，但 ID>9／對應 record 不可用 | 未進入多控件填入支線；`0x665150` **仍可返回非零** | +D0 或非零回傳代表 record 已更新 |
| ID 在表、`ID<=9`、`record+0x5C!=0` | 進入 `dialog+0x110`、`+0xF4…+0x108` 控件 setter 與 `virtual+C8` 的局部路徑 | 已有同版資源／scene、畫面已 draw、Server 選角已批准 |
| F42EF 未實際投遞到 listener | 即使 producer 和 consumer 都存在也無法主張 `0x665150` 這次有被執行 | 角色清單缺失或完整 UI 不可達（還可能走其他事件路徑） |

**可構造的反例**：`table_hit = true`，`ID<=9 = true`，`record_ready = false`。這時依 report，`0x665150` 仍返回非零，但**沒有執行多控件填入**。因此下列三項都不能充當 `UI_READY` 的充分條件：`record+0x5C` 寫入、`0x665150` 返回非零、`virtual+D0` 被呼叫。這也顯示真正的 Server-compatible UI 驗收需要證明更多 Client 的狀態／資源前提，而不是加入猜測封包。

## 4. 真正缺少的跨邊證據——P15 研究工作包

| 子題 | 必須找出的關係 | 現有候選與刻意不做的推論 | 成功判準與證據形式 | 原負責人 |
| --- | --- | --- | --- | --- |
| **P15-01 roster 完成→更新觸發** | `0x4B7F00` header/record 完成分支、local 26+ID 發送、何時設定 F4246/F4278 相關的狀態物件 | 不能因 `0x4E5FB0` 非一般刷新而宣稱整條路沒有 GUI event | 指令/函式 caller→writer、明確 state gate、前後 state/事件 ID；反例與 def-use 截斷須列出 | T03；T02 僅分派 |
| **P15-02 F42EF 真實 listener 路由** | `0x660260`、`0x673DA0`→`virtual+0x15C` 的實體 dispatcher、註冊者、`0x5A69E0` 所在 receiver/vtable 與有效生命週期 | 相同 F42EF 字面值／virtual offset 不代表肯定投遞到此 consumer | 帶 class/vtable/object identity 的正向派發邊，必要的訂閱/卸載與負向未註冊分支 | T03；T06 資源身分 |
| **P15-03 F4246/47/78 三種不同 producer 路由** | `0x5A67D0` 每一個 case 的來源；特別是 `0x40AFC0` 回傳物件+0x14 如何設值，何時觸發 `F4278` 的 zero gate | F4246/F4278 不能合併成無條件刷新，F4247 的 +D4 不等於 +D0 | 對每個 event 各一份 producer→dispatcher→consumer 與條件表；未知保留 | T03；T06 資源 |
| **P15-04 Dialog/scene readiness** | `0x672F00`、`0x665150` 的 dialog 擁有者，Control ID→資源存在、scene 驗證、顯示/可操作完成條件 | 不得依虛擬方法 offset 命名確切控件或等同實際 render | 同版 resource locator 與函式 source，必要時保持 runtime 待驗 | T06（資源）；T03（UI） |
| **P15-05 init replies 與 roster UI 前提** | `26+ID` 和其他 C2S 初始化請求對應哪些 S2C 消費者／後續 gating | 不猜 request+1、不可把 24/1F/25/15/DA/D2 的 handler 當固定 reply | C2S producer、S2C consumer、已證/未證 pairing 的雙向矩陣 | T03/T02；T04 資料權威 |

**工作規則**：以上只將既有 `RR-0002`（仍 BLOCKED）與相關 T03/T02/T06 工作拆成**研究題單**，不新增重複 RR、不更動任何 Task owner、不自動喚醒 Task Agent、也不重新指定其他研究分支。若 T01 要做定向 R2，只驗上表對開發最關鍵的 native byte 和 vtable gate；不以 T01 已有來源收件當整份 FULL-PASS。

## 5. 真正能交給 `ttr_server_roy` 的內容（避免範圍膨脹）

- C00 已在獨立 Server repo 主線；可持續 C01 transport 與 C02/C03 **內部** session/roster storage，但任何 KR 協定 decode/encode 只實作已來源界定的有限形狀並採保守測試，未證的 65-byte header 與 reply 不得自行補值當官方真實。
- 對 `REQ-0003` 而言，可供無 UI 假設的資料契約是 `65+53*N` 的局部 Client consumer record geometry、部分欄位 offset 和測試器的明確安全限制。
- 對 `REQ-0004` 而言，真正仍欠的是 scene、資源、local event dispatch、額外初始化的上下游證據。**不需要 Server 直接發送 `F42EF/F4246/F4247/F4278`。**
- 對 `SLICE-CREATE` 而言，尚無建立角色 C2S/S2C 正向契約；無角色不等於自動創角。對 `SLICE-ENTER-WORLD` 而言，選角 C2S `42 00 XX YY` 本地建構不等於原版 Server S2C 成功回覆確定。
- 若 Server Agent 在 C01/C03 讀 spec 遇到 blocking UNKNOWN，使用既有 `docs/FEEDBACK.md` 提出具 source SHA/SPEC/GAP/RR 的 FB；本輪未實際改 Server 或其 S00 pin。

## 6. 假設反例與後續驗收設計

| Case | 假設資料 | 期待（僅上述局部 Source 模型） | 必須仍標 UNKNOWN |
| --- | --- | --- | --- |
| A | `table_hit=0`、`record_ready=1` | `0x665150` 返回 0，無多欄填入 | UI 狀態與任何 Server response |
| B | `table_hit=1`、`ID<=9`、`record_ready=0` | 返回 1，**無多欄填入** | Dialog 是否更新／render |
| C | `table_hit=1`、`ID<=9`、`record_ready=1` | 可以進入多欄填入分支（假定指標/資源有效） | Client 是否真的看見可用角色畫面 |
| D | F42EF producer 與 consumer 存在但無已證 subscription | 只可各自標源碼存在，不能推出實際派發 | 事件路由、UI 畫面 |
| E | `0x5A67D0` 收到 F4278 且 `40AFC0 return+0x14 != 0` | 不會走**該 F4278 分支的** `0x672F00(0)` 路徑 | 是否由其他事件改變 UI |
| F | S2C command2 有效記錄寫入並建立 local `26+ID` request | 本地 roster/初始化工作已發起，但不能認定收到其 reply | 後續 Server reply 與 UI-ready |

同批 JSON 收錄 16 個抽象條件組合。它只提供 **S00 設計及 Agent 檢查用的邏輯防誤判**：沒有導入 TEST 索引、不新建 CI、不宣稱 original Client runtime／server-conformance pass，也不取代 T03 原始證據。

## 7. 台帳維持與來源追溯

- `REQ-0003`／`REQ-0004`：`CANDIDATE`；
- `SPEC-CHAR-0001`／`SPEC-FLOW-0001`：`DRAFT/PARTIAL`；
- `GAP-CHAR-0001`／`GAP-FLOW-0001`：`OPEN`；
- `RR-0002`：`BLOCKED`；`RR-0007`：`IN_REVIEW`；
- `CLM-CHAR-0001..0004`、`CLM-NET-0030`：`PARTIAL`。`CLM-CHAR-0005/6` 亦為 `PARTIAL`，但其功能主要是選角本地 C2S interface，不拿來補 roster→UI refresh。`RR-0005=ACCEPTED` 僅對 connection/handoff 的有界 static acceptance 有效。

**精確原始來源**：

1. `kr/evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt`；`CLM-CHAR-0001/2`，Git blob `1c05261ac5a5a57bb7b0142bf0bb14fba2cc4603`（role records、26+ID／其他初始化與 4E5FB0 rank update）。
2. `kr/evidence/aa769d397c649ca9d59931b53b074ab0ac2fd599d53082884743e2bd73a4b5a0.txt`（F4246/F4247/F4278 的 0x5A67D0 local consumer 與 0x40AFC0 gate；精確副本見 T03 README）。
3. `kr-temp-roy/20261028-203031-chatgpt-web-roy-T03-LOGIN-01-F42EF-native-event-chain.md`，`CLM-CHAR-0003`，Git blob `563ef44eb41beada1c35214d3591a66dbeccc68f`。
4. `kr-temp-roy/20261028-204121-chatgpt-web-roy-T03-LOGIN-02-665150-dialog-update-native.md`，`CLM-CHAR-0004`，Git blob `39a12e6feeea532f6fd235061b77ed80aa408220`。
5. `research/handoffs/t01-t03-roy-20261029/README.md`（19篇原稿 `CONFLICT_CHECKED`、**非** `FULL-PASS`）、`research/claims/index.json`、`research/requests/index.json`。
6. S00 Iteration 14 原稿（**未上 Git**）：`S00-20261030-ITERATION-14-DRAFT.md`（本地已上傳於前次對話，本輪讀取）。

**限制**：本輪未看到新的首次相容 Server wire trace、真正原版 Client 畫面、T01 全文接受或官服成功/失敗回覆；所列 local event 的具體 UI 商業含義仍保留未知。下一輪可依 P15-01/02/03 原生 BIN 補證後，將新 CLM 的來源與範圍送 T01/S00 有界審核，否則保持 SOURCE-MAPPED 而非 CONTRACT-TESTABLE。

## 8. 後續交接（未推 Git）

若下次要求「將 Iteration 14/15 上 Git」，從當時最新 `main` 建分支，將本報告存到 `governance/S00-20261030-ITERATION-15.md`，將上一輪草案存 `governance/S00-20261030-ITERATION-14.md`，附本次 JSON 非規範 worksheet；更新唯一 `governance/S00-NEXT-CHAT.md`，經 CI、PR 審核再合併。不得藉此修改正式 REQ/RR/GAP/SPEC/TEST、Txx owner 或 Server C00 契約 pin（除非另有正式 SPEC 改動）。