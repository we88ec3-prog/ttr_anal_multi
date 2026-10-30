# T01 KR T16 作者勘誤後續獨立複驗與限定整合（2026-10-30）

- **基準 main**：`e7416169fd20e4fcb0fe2c0b4d6207e4c9b443bc`；T16 作者分支 `t16/roy/chatgpt-web`，最後已核對 `0c8692fd18f510f7634890d626c5a93cd89467b2`。**沒有合併 T16 分支。**
- 原件：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- 審查對象：43 筆 T01-RETURN-T16；37 份原稿/作者勘誤 unique Git blob；17 篇 rooted-CFG Markdown 候選（未附所引用全量 root JSON）。每筆的來源 blob、勘誤 blob 與結案／待驗狀態見 [notice-review.json](notice-review.json)。
- **本次 T01 審核：11 筆限定修正型通知 `RESOLVED`，32 筆維持 `READY_FOR_REVIEW`。** `RESOLVED` 僅表示該筆原生差錯與作者修正已完成獨立核對；**不是**對來源舊版的 FAILED 撤銷、原稿全文 FULL-PASS、`NATIVE_VERIFIED`、Server SPEC STABLE、Quest 成功或可玩性的判定。

## 新通過的 11 筆（依實際可復用功能分類）

| 修正群 | 正式通知 | 限定驗證結果 |
|---|---|---|
| 原生 loader、node 迭代與 signed lookup | T16-002, T16-005, T16-013 | resource 缺失的 raw return 非零；`0x53FEB0` 由原始 ESI 沿 `+40` 遍歷而非回呼 EAX；`0x8438C0` 排除 `key<best` 的 signed 比較 |
| Lua VM | T16-046-2170ef08 | `TutorialMain.lua` prototype5 的 PC20/40/136 全為 Lua5.1 CALL C=2 → **1** 個 result |
| 出站 frame 與位址 | T16-070-C06/C09/C13 | `len16,1A68` header；`conn+501C` stream-base 與 `+A020/+A028` connection-base；`0x807BD8` 與 `0x807BDD` 分別是 2633 常數與 4-byte header 設定 |
| WSASend/virtual transport 註解 | T16-071-C05/C06/C08/C14 | OVERLAPPED`+A050` 與 WSABUF`+A064`；`0x80695A` 清零；vtable `C51748` raw `84FD48`；`0x807DAB` mov 與 `0x807DAD` call |

**檢核方法**：從 KR BIN PE section map 轉出 VA/raw，獨立 objdump 解碼；`0x53FEB0` 整段 44 條指令的 7 個直接分支目標與 `0x8438C0` 47 條指令的 6 個直接分支目標均落在指令起點，後者雙出口 `ret 4`。與作者勘誤及原始 Markdown 受影響偽碼／註解核對，Lua 從 Event.stp 原始載體解壓解碼、驗證 `CALL` 字段。完整原生位元組與步驟見 [技術裁決](native-evidence-and-limits.md)；本輪**未**完成全部來源的 100% semantic graph/全文驗收。

## 維持 READY_FOR_REVIEW 的 32 筆

- `T16-026`：舊 T01 因 `0x4AEDAF` 線性解碼而否定 `0x4AEDB0` 的反證本身**錯誤**。`0x4ADD88` 明確儲存 `0x4AEDB0` callback，獨立 prologue 與 ret 0xC 存在；T01 應撤回該錯誤反證，**但目前附錄 root 全邊／衍生主張未完整覆核，故不虛標 RESOLVED。**
- `T16-069`：`A0A4>300` 是 signed gate、`A078` 為 list count 的部分證據成立；仍待所有 writer/consumer/重複敘述交叉驗證。
- `TutorialBase` 14 份退回：`Event.stp` member 真實 SHA256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`，有 6 prototypes/72 instruction words；先前 56-hex 字串無效，但歷史 404/各篇來源相依仍須逐篇覆核。
- `T16-092` 與其餘 rooted-CFG 附錄：局部座標 25 例中，24 次為前置指令內部、1 次 `0x4AEDB0` 為有效獨立入口。**沒有完整 root JSON、全分支與 all-claims 核查**，不能由這個計數推斷 16 篇全部通過。

## 去重與 S00 邊界

- Header `length16, 1A68` 是既有 `CLM-NET-0001`、`SPEC-NET-0001` 的補強，不另創重複 opcode 主張；vtable/WSABUF 局部佐證可補 `CLM-NET-0005`。既有 `CLM-NET-0013` 指認的錯誤參數佈局仍為 `REFUTED` 歷史，不能把來源錯誤說法改作 `NATIVE_VERIFIED`。
- S00 的 `SPEC-NET-0001/0002/0003` 均維持 DRAFT/PARTIAL；無新 Quest C→S accept、Quest S→C ACK/拒絕、NPC/UI、Quest16→15 原生閉環或 Server 原版邏輯。未更動 `research/requests/index.json` 與其他 Task owner/原稿。
- 這是 T01 主線整合和 T16 README 的**退回通知專區**狀態變更，不是 `main→T16` 或 `T16→main` 的任何 branch merge。原作者全部文件原封不動。

## 可重現的前一階段材料

原本地完整檔名：`20261030-T01-T16-PASSED-BOUNDED-INTEGRATION.zip`，包括 `notice-dispositions.json` 43 條、`source-crosswalk.json` 37 份、14 個限定候選及兩份一手驗證腳本。其內容是初步整合工作底稿，**不能因本次 11 筆結案而整包升為 FULL-PASS**。新遠端 43 筆精確版本清單以本批 `notice-review.json` 為準。

## 歷史版本隔離與驗收者

審核者：ChatGPT-web roy，T01 review；日期：2026-10-30（Asia/Taipei）。已保留原稿 Git blob SHA、T16 作者勘誤 SHA、原生目標 SHA、剩餘缺口、具體原生核對地址。若未來發現反證，依既有退回程序按原 ID 重新審查；不覆蓋歷史。
