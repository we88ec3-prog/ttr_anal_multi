# S00 Iteration 14 — KR 角色名單 → 本地選角 UI：已知正向鏈、不可跳過的斷點與 Server 交付

> **未上 Git，僅作 S00 本輪分析原稿。** 2026-10-30 Asia/Taipei。核對來源：`we88ec3-prog/ttr_anal_multi main@dd69ec9de353a695d25c6db8e362ff471ea0c137`。`ttr_server_roy main@2901f05eeb229ee2c3c0e9a46b6248aa555c3309` 使用相同 S00 pin。原始 KR Client `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本批沒有重新取得 BIN 並獨立反組譯；是**對已提交的原生 BIN-first 報告及登記 CLM 的限定範圍整合**。不聲稱 T01 FULL-PASS、官方 Server 回覆或 Client 動態測試。

## 1. 本輪真正前進的範圍

Iteration 13 的優先項 P13-1 是角色清單到 UI-ready。既有 `SPEC-CHAR-0001` 主要涵蓋 app command2 `65+53×N`、`0x4D4150` 對 UI record 的寫入，尚未描述足夠的 UI 狀態。這次補足**已存在卻尚未被 S00 UI-ready 檢查點充分採用的** `CLM-CHAR-0003`（`F42EF` producer/consumer）、`CLM-CHAR-0004`（`0x665150` 的兩重 gate 與 caller 通知分歧）。這兩筆都是 `PARTIAL`，並未提高來源品質。

還核對 `CLM-CHAR-0005/0006` 的其他 UI callback 與本地 C2S `0x42` 建構；它們是選角發送路徑，**不能**視為 `F42EF` 與 roster 消費之間已證明的因果連結。`CLM-NET-0030` 說明 app command2 可走第一層直接 handler，而 LOGIN `0x13/0x7A` 受 active scene 第二層 gate，不能由文件行順序補出動態時序。

**與 Server 工程最相關的發現**：在 Client 本地 `0x665150` 中，`list-hit`（候選 ID 存在）和 `record-ready`（`F94304+ID*0x210` 的 `+0x5C` 非零）是兩個不同條件；list-hit 返回非零並**不表示** UI 欄位確實填入。故不能使用「名單包已收」、「+0x5C 已寫」、「`0x665150` 返回 true」任何單一現象推斷 UI-ready。

## 2. 嚴格的部分正向鏈（不能拼接成已運行流程）

| 局部子鏈 | 已提交原生證據／限定範圍 | 還缺的連結與假設限制 | S00 用途 |
| --- | --- | --- | --- |
| **A. app command2 → 角色記錄** | `CLM-NET-0030`：首層命令 0x0002→`0x4B7F00`；`CLM-CHAR-0001`：在有效路徑上 `65+53×N`，記錄第一筆 +65 | 與 LOGIN/選服真實 wire 次序、所有 65-byte prefix 意義、資料的原版 Server 權威 | `REQ-0003`／`SPEC-CHAR-0001` 的有界 payload geometry |
| **B. 記錄 → 可用 UI 槽** | `CLM-CHAR-0002`：`row+0x2E` ID，觀察 guard 為 unsigned ID<=9 且目的 pointer 有效；`0x4D4150` 對 `F94304+ID*0x210` 拷貝欄位並設 `record+0x5C=1` | 並未證原版有效 ID 政策、去重、字串容量安全或 UI 實際刷新 | 離線的資料形狀／受控邊界；非 UI-ready verdict |
| **C. 兩條 UI 本地 producer → F42EF** | `CLM-CHAR-0003`：`0x660260` 與 `0x673DA0` 在不同 `0x578`/`0x641` 等本地事件與 control identity 條件產生 `F42EF`，`event+0x14` 來源不同（`+0x1A8`／`+0xD8`） | 尚未證**command2 完成會觸發哪個 producer**、event 註冊/生命週期/實際投遞 | 本地 GUI event，**非** Server opcode |
| **D. F42EF consumer → 選角 detail** | `CLM-CHAR-0003`：`0x5A69E0` type gate，經事件 `+0x14` 呼叫 `0x665150`，再有 dialog virtual `+0xD0` | producer 經 virtual+0x15C 到特定 consumer 的 listener/route 尚未完整閉合；控件 class 未命名 | UI local event consumption，不是 Server 回覆配對 |
| **E. `0x665150` 的雙重資料門檻** | `CLM-CHAR-0004`：`FE1DF4` 8-byte stride 表找 ID；ID<=9；`F94304+ID*0x210+0x5C!=0`；通過後 `dialog+0x110`、多個 UI setter、virtual `+0xC8` | lazy init `F94390 bit0`/`0x4E1590` 的影響，實際 dialog/resource 對應，完整 render | 精確區分 list-hit 與真正欄位填入 |
| **F. 不同 direct caller 的 +D0** | `CLM-CHAR-0004`：`0x59A520` 後只有 `0x665150` 返回非零才調 +D0；`0x5A6A28` 在型別分支通過後不以此返回值 gate +D0 | 返回非零可能仍未填欄位；未知 control 及其畫面更新效果 | 防止把任何 +D0 通知統一解讀為 UI 顯示成功 |
| **G. 使用者選角本地發送** | `CLM-CHAR-0005/0006`：`0x5F46D0` 的 `0x70A` 局部 roster guard；`0x578` 另一 caller 分支；`0x4A3B80` 建 `42 00 XX YY` 且受 `FBA798==0` 影響，送 manager 的 local virtual+0x10 | 不等於原版 Server 的已成功選角／回覆 pairing；也不證明上列 UI events 的全域次序 | 只屬後續 `SLICE-ENTER-WORLD` 界面，不補齊 `L07` |

### 刻意保留的重大斷點

1. **A/B → C**：未證實 `0x4B7F00` 角色資料寫入會直接引發 F42EF；`F42EF` 是由 GUI 輸入控制分支產生，不是 roster handler 的已確認呼叫結果。
2. **C → D**：已證兩種 writer 與獨立 consumer 存在，卻還需註冊／listener 生命週期／virtual dispatch 的精確邊，不能僅由相同常數當成一次必達事件。
3. **D/E/F → 可見角色畫面**：資料填入與虛擬更新不等於 Client scene 初始化、畫面 draw 或人能操作。`0x665150` 返回值只表示清單命中。
4. **Client local UI → Server wire**：`F42EF`、`F4246`、`F4247`、條件式 `F4278`、`0x578` 等均為局部事件／GUI identity 的範圍，**不是** Server 應送的 app opcode。
5. **Server packet → UI**：現有合成 `0x0002` 角色資料沒有證明畫面出現，也沒有經授權的同版真實 packet/GUI 觀察。

## 3. `0x665150` 的不能混為一談的情境

| 狀態／參數 | native-static 局部結果 | 不能推論 |
| --- | --- | --- |
| ID 不在 `FE1DF4` 表 | 返回 0；`0x59A520` caller 跳過 +D0，但 `0x5A6A28` caller 在 type gate 通過後仍呼叫 +D0 | UI 一定關閉或 Server 拒絕角色 |
| 表中找到 ID，但 ID>9 或 `record+0x5C==0` | 未通過欄位填入分支，函式仍**可能返回非零**（代表表中找到 ID） | 已經填入選角資料或 UI-ready |
| 找到 ID 且 record gate 有效 | 可以進入 `dialog+0x110`、欄位更新、virtual +C8 路徑 | Dialog 已經 render；角色選擇已獲 Server 批准 |
| 需要執行 lazy init 的本地表 | `F94390 bit0`/`0x4E1590` 局部入口存在 | 空表等於帳號沒有任何角色；初始化一定成功 |

具體業務名稱、控件文本與 `0x665372` 比較的語義尚未知；切勿將 `0x665560`（文字格式化）命名為 packet builder。

## 4. 迭代後的最小研究／設計工作（依既有任務而非新 RR）

| 候選下一步 | 原 Task | 精確輸出／完成條件 | 失敗時如何記錄 |
| --- | --- | --- | --- |
| **P14-01**：從 `0x4B7F00/0x4D4150` 向 UI 追找直接或間接的 event/scene 設置與初始化門檻 | T03，必要時 T02 支援 dispatch | 兩個以上直接引用的 caller/writer、scene 或通知關係；反證也明記，須有原始 BIN 指令範圍和完整參數基準 | 若沒有連結，將 `L05→L07` 標斷鏈；不偽造「角色清單到 UI」因果 |
| **P14-02**：定位 `F42EF` 路由與 listener/receiver 訂閱 | T03（事件／UI）；T06 僅在資源身分需要時協查 | writer A/B 的投遞物件、virtual+15C 與 `0x5A69E0` 的可能 route、明確的正/負觸達條件 | 只可說 producer／consumer 各自存在，不可稱保證投遞 |
| **P14-03**：追 `0x665150` direct callers 與 dialog 初始化、virtual+C8/+D0 | T03；T06 同版資源/控件文件支援 | ID 不在表、在表但 record 不可用、通過兩重 gate 等 3 種 branch 最小 CFG、UI 資源有效性、是否真有 scene readiness writer | 把 `list-hit`、`record-ready`、`dialog-updated` 分開，不推動 SPEC maturity |
| **P14-04**：分析 N=0/多角色及失效資料 | T03/T04（資料權威、業務 policy 分離） | 所有合法長度/早期 header 讀取/ID=0或>9/duplicate/缺 NUL 的有界 Client 行為；原版政策不能由 local guards 推出 | 更新限制與測試範圍，N=0 不直接推創角入口 |
| **P14-05**：交給 S00 的 Server 契約分隔檢查 | S00 | （一）`SPEC-CHAR-0001` 哪些 bytes 可用 synthetic parser 實作；（二）哪些是純 UI local，不列 wire MUST；（三）哪些阻塞 Client-visible acceptance | 原始 `REQ-0003/0004` 保留 CANDIDATE、`GAP-CHAR/FLOW` 保留 OPEN，必要時定向返 T01 R2；絕不改成 STABLE |

**建議本輪重心：P14-01＋P14-02＋P14-03**。它們能直接決定 Server 交付到「清單資料可解碼」之後，是否還需要某些 Server 資料或只剩 Client local UI 資源／事件門檻。P14-04 不得改變原版資料政策，P14-05 不是新 Server 開發任務。

## 5. S00 對 `ttr_server_roy` 的本輪回饋（目前僅建議，不更動另一倉庫）

- **現在可實作**：Server 內部角色 ownership/CRUD、純合成 `65+53*N` 序列化／解析器與嚴格字串容量的**保守 Server 自訂測試規則**（不是原版 Client 的所有原生安全規則）。如果必要的 65-byte prefix 仍未知，則只可測幾何，**不可**宣稱原版 Client 可接受該封包。
- **不能實作為原版必須的封包**：`F42EF`、`F4246`、`F4247`、`F4278`；它們目前應留在 Client UI 靜態圖，而不是新增 Server S2C opcodes。
- **不可建立的驗收捷徑**：roster bytes 被測試器接受、`record+0x5C` 為 1、`0x665150` 返回 1、某個 virtual+0xD0 被呼叫，任何一項皆不能代表 `ORIGINAL_CLIENT_COMPATIBILITY`。
- Server C00 設計與 S00 pin 在本次核對時一致：`ttr_server_roy main@2901f05eeb229ee2c3c0e9a46b6248aa555c3309` 的 `contracts/spec-revision.json` 指向 S00 `dd69ec9de353a695d25c6db8e362ff471ea0c137`。本次未更新原正式 SPEC，所以**不需要為本草案調整 pin**。
- 如 Server Agent 需要精確完整 prefix、封包回覆時序與 UI side effects，依 `docs/FEEDBACK.md` 記錄可重現的 SPEC 缺口，走既有 FB/S00 收件，不私創額外 REQ/RR/TEST 索引。

## 6. 形式化的追蹤與證據品質

- `REQ-0003`：角色清單提供；`REQ-0004`：角色畫面 UI 就緒；目前都 `CANDIDATE`，不能直接批准。
- `SPEC-CHAR-0001`、`SPEC-FLOW-0001`：`DRAFT/PARTIAL`。
- `GAP-CHAR-0001`、`GAP-FLOW-0001`：`OPEN`。
- `RR-0002`：`BLOCKED`（要求完整選角回覆／scene 終點），但不妨礙針對 UI 子問題整理 bounded evidence；`RR-0007`：`IN_REVIEW`。其中 `RR-0005=ACCEPTED` 僅是其他限域 T02 成果，不能提升角色 UI 證據。
- **證據範圍**：`CLM-CHAR-0001..0006` 與 `CLM-NET-0030` 均須依各自 `PARTIAL`、`native_review_ref`、`source_file`、`source_blob_sha`、`additional_sources` 的實際範圍讀取；已有 SRC-0329/0330/0331 來源收件**不等於**全文獨立驗證。
- 原始 Client 沒有在這輪執行；沒有 runtime trace；沒有創角成功；沒有原版 Server 封包捕獲或互通測試。

## 7. 逐項來源（已在 GitHub main，未新生原始 BIN 研究）

- [CLM index](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/claims/index.json)：`CLM-CHAR-0001..0006`、`CLM-NET-0030`。原稿對應：
  - `CLM-CHAR-0001/2`: `kr/evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt`, blob `1c05261ac5a5a57bb7b0142bf0bb14fba2cc4603`。
  - `CLM-CHAR-0003`: `kr-temp-roy/20261028-203031-chatgpt-web-roy-T03-LOGIN-01-F42EF-native-event-chain.md`, blob `563ef44eb41beada1c35214d3591a66dbeccc68f`。
  - `CLM-CHAR-0004`: `kr-temp-roy/20261028-204121-chatgpt-web-roy-T03-LOGIN-02-665150-dialog-update-native.md`, blob `39a12e6feeea532f6fd235061b77ed80aa408220`。
  - `CLM-CHAR-0005/6`: `kr-temp-roy/20261028-204757-chatgpt-web-roy-T03-3-command42-selection-callback.md`, blob `e38d3c84ab6e65bc9df95789a749349df81234e4`。
  - `CLM-NET-0030`: `kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md`, blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`。
- [T01 19-source bounded intake](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/handoffs/t01-t03-roy-20261029/README.md)：`CLM-CHAR-0003/4` 在來源收件後仍屬 PARTIAL。
- [SPEC-CHAR-0001](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/spec/session-account/SPEC-CHAR-0001.md) 與 [S00 P13 prior plan](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/governance/S00-20261030-ITERATION-13.md)。

## 8. 後續 Git 提交／交接條件

本輪原稿若經使用者授權「上 Git」，建議以 `governance/S00-20261030-ITERATION-14.md` 保存，並在 `governance/S00-NEXT-CHAT.md` 增加摘要和下一個 P14-01/02/03 動作；必要時給 `SPEC-CHAR-0001` 加**限定** UI 狀態附錄（不能說原版 Server 要發 F42EF）。上 Git 時重查最新 main、比對其它 T03 新成果、走 PR + CI，**不改**正式 REQ/RR/GAP/SPEC status 或對應 Task owner。現有 Server repo 不需要因僅分析草稿而更新 source pin。