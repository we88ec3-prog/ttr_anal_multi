# T01 → S00：t08/roy/chatgpt-web 分支整合與有界 BIN-first 複驗（2026-10-31）

**判定：可以安全整合至 main，T01 有界來源／主張 R0–R2 交接通過；不是 81 篇全文 `FULL-PASS` 或 Server／遊玩完成。**

## Git 基準與合併策略
- 比對時 main：`dd8d487316ea2bfb1de3e0b3851f14c398303a68`；T08 工作分支：`484bf03df60079cf787d84f0b9e966fbf163c2d5`。
- compare：`ahead 97 / behind 0`；**81 個 added 原稿／映射表／驗證器檔案，僅 1 個 modified（kr/tasks/T08/README.md）**。沒有其他 Task 檔案或研究台帳的分支改寫。以**fast-forward 歷史**為基礎，追加獨立 T01 審核提交；無 force push。
- T08 README 將 5 個舊退回及 `LEGACY-MAPPING-001` 標為 `READY_FOR_REVIEW`：這只表示**作者提交更正版**，**不能**代替 T01 全面認可。保留既有 173/196 RESOLVED，不更動凍結的 FAILED 原稿及歷史 `REFUTED`。
- 81 個新增檔案已由 GitHub 檢索完整正文並核對各自 Git blob SHA、重算 UTF-8 SHA256；在 [R0 源碼矩陣](source-matrix.json) 保存逐篇身分、行數、主張與適用等級。SRC-0509～0589 保留精確 Git 作者來源。

## T01 R0 / R1 / R2 分級整合
- 本批新 SRC **81**；其中 **43 REGISTERED**（已保留原始全文，尚未做完整 R1），**24 CLAIMS_EXTRACTED**（T08-129～152 每篇獨立 v3 corrected-source，已與既有歷史 UNKNOWN/FAILED 交叉引用），**14 CONFLICT_CHECKED**（五個個別退回修正及選定 202 原生、IOCP 及 Actor 來源；只限確實核過的子範圍）。任何一個 SRC 工作流狀態**不等於**原稿原生品質。
- 新增 `CLM-CLIENT-0066 PARTIAL`：0007 的 actor 記錄 P+4==0 gate、000A 首筆 P+4/+8 覆寫，以及本地 26/81 清理路徑的差異。與原有 CLIENT-0009、CLIENT-0029 等有界主張對照，不把 handler index 當官方 wire opcode。
- T08-202 的 0x0BBB TX checksum／XOR、RX inverse/checksum、mode2→fallback、IOCP outbound ring／WSABUF／WSASend 均與主線 T02 `CLM-NET-0001..0005`、`0021..0024`、`0033..0035` 的已建 LIMITED claim 重合：**僅追加 T08 原稿精確來源**，不重複創建另一套規格、也不把其品質自動繼承到所有條件。
- T08-201 大型原稿及其它附錄完整保存（其超過五千行的原文**不是**此次逐行原生審核）；R0 不等於 SOURCE FULL_PASS。所有本次未驗證的正面主張保持原作者等級或 UNKNOWN。

## T01 原生 BIN：獨立原件覆核

實際使用唯讀 `Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原件 PE32 .text VA 0x00401000/raw0x400；**raw=VA−0x400C00**，.rdata 不可套相同公式。此批 [可重跑腳本](revalidate.py) 在原始 BIN 的 34 個精確指令／分支、writer、入口和 caller sites **34/34 PASS**。

| 退回／主張 | 具體原生複驗 | 本次裁決 |
| --- | --- | --- |
| T08-153 | `4DFBC9 8D4508` 傳 search-key 的地址；`4DFC19 8D4D08` 同 stack 儲位改作 erase out iterator；`4DFC1E E86D6C2D00` | 修正方向相符，但舊 FAILED 與 READY_FOR_REVIEW 保留；非整篇 FULL_PASS |
| T08-155 | `7B698E 894104` 真 mov；`7B6991 EB0E` 真 jmp，並由 `7B6890` 函式入口定位 | 舊中段假指令已更正；其餘 two-child 全分支仍需 T01 複驗 |
| T08-157 | `4B297A 3B053CB1FA00`、`4B2980 7407`、`4B2982 8B7010` | 真 cmp/je/mov；非 `4B297C` 錯位入口 |
| T08-183 | `7B868B` hash/mask/bucket；`7B86DE 8D7E04 E83A14F6FF` list unlink helper | 不能當 ordered RB-tree remove |
| T08-187 | `7F6FBF 6A30`、`7F6FC1 8BF8` | push30 與保存 EDI 的座標正確；其他用途仍以原稿的 guard 為準 |
| 24篇 legacy | T01 既存 `mapping-findings.json` 內 18 篇／1,263 行 `affine_candidate_equal=true`；新 v3 各自保留原 FAILED 對照與真 PE 範圍。本輪另外獨立核了 10／10 個 v3 verifier 的原生入口 | **尚未在完整 Git checkout 真正執行全 1,263 行 verifier，也未驗完 24 份修正版 CFG／ABI。** 維持 READY_FOR_REVIEW、不可 RESOLVED |
| T08-202 Actor | `4AEC77` 0007 P+4 gate，`4AFA37` 000A 首筆獨立 gate；26/81 局部 erase 不同 | partial Actor field／consumer，wire/domain、動態 vtable 及全 alias 未閉合 |
| T08-202 transport | `805D02` Conn mode=2，`8068B0` WSASend function entry，`807BFC` 0BBB marker，`807C18` 1A68，`807D66` checksum compare，`8079F0` checksum header store，`806EC4` IAT call | 原生所見與現有 NET claim 的有界算法/分支一致；runtime socket 實際成功與 Server 協定來源不能從此倒推 |

## 有界 net/actor 與 Server 對接

- **Client 確認／部分確認**：T08-202 在有條件模式下，非零轉換使用 payload_len/u16 0x0BBB/u16 checksum 的 6-byte header，與原始 XOR body；接收端有對應 inverse/checksum 解析；轉換失敗可退 mode0 1A68 plain。這是**Client 本機**的分支行為，且與主線 T02 證據部分重合，不能據此排除其他 marker 或 connection lane。
- **Client 待逆向**：0007／000A 記錄 P+4/+8 其他 alias writer，Actor vtable+0x14 各派生實作，26/81 socket/dispatch 到玩家可見的 end-to-end chain，IOCP failure/retry、所有 connection/lane 實例、以及 T08 202 剩餘的關卡更新時序。
- **Server 待開發**：只按已證 Client 相容消息/framing 的有效邊界訂 SPEC/GAP；原版 Server 生成決策／物件死亡與關卡波次規則未知不能猜填。
- **跨功能待整合**：T02 socket/framing（主責）；T06/T07 場景、T14 戰鬥事件；T08 的本地 handler index 不自動是獨立 wire opcode。
- **待遊玩驗證**：未執行原始 Client 或抓取原版 Server 封包；沒有宣稱怪物可玩或動態場景運作完成。

## 獨立 T01 判決與後續
**PASS：Merge 適格、81 份原稿 R0、指定 34 native 位點、T08-202 與既存 T02 研究去重、有界 S00/研究交接。**
**PENDING：五個作者修訂稿與 24 篇 legacy 的 R3 全部受影響主張驗收；仍是 READY_FOR_REVIEW 而非 RESOLVED。** 若只因十處入口或原始哈希一致就把五個/24個退回全部結案，將違反原有 T01 語意審核政策。未修改 RR／SPEC／TEST／owner／catalog／歷史 FAILED/FULL_PASS。

[完整新 SRC](../../intake/index.json) · [現有 NET/CLIENT claim](../../claims/index.json) · [24份原稿修復清單](../../../kr-temp-roy/20261031-042008-chatgpt-web-roy-T08-T01-LEGACY-24-corrected-source-delivery-and-review-manifest.md) · [舊 T01 映射證據](../../../shared/integrations/T01-20261029-semantic-review/t08-early/mapping-findings.json)。

## 2026-10-31 04:35 T08-202 追加提交，與最新 main 同步校正

作者工作分支更新至 `d87403c45e16b69741e7dcb15ff58c23ef50bcac`，增加原文 `kr-temp-roy/20261031-043540-chatgpt-web-roy-T08-202-native-owner-record-0008-0007-000A-and-26-81-lifecycle-analysis.md`（blob `1db1077f7e7c0ed9cd0de070a09daec9f9db5eb9`，SHA256 `94cffb829a4957ff482e89e0d03761ce6b2fad31268e86b77e40e6a223ad2abb`），已登錄 `SRC-0589`，並為 `CLM-CLIENT-0066` 加入有界附加來源。**T08-202 新分析：**本地 handler 表 index8 `0x4AF530` 是 P+0 記錄建立／既存鍵刷新入口；原生 `0x4AF637 push 0x2C` 配置 0x2C bytes，`0x4AF649` 與 `0x4AF64C` 初始化新 P+4/P+8=0；owner 的二級樹 `owner+0x18` 及特殊 `owner+0xF8` cache 與 Actor 主樹 `owner+0x08` 分離。這補足前稿沒有正式定位的 P 生成者，但不等於所有 P 別名都已閉合。補核 8 個原始 handler 表／真正 handler 入口：`4ADD98`、`4ADDA2`、`4ADE8D`、`4ADFBD`、`4AF530`、`4AF920`、`4B28D0`、`4B3710`，**8/8 PASS**，加上前述 34 個定位檢查總計 **42 個有界原生檢查**（含相同功能的部分重疊，不是 42 個獨立語意主張）。新的 T08 文中仍以 local index7/8/10/26/81 區分，不能擅自替換 T02 的正式收發域。新來源為完整原文，沒有全文 R3／S00 ACCEPTED。

最新 main 在本輪競爭檢查期間由其它工作提交前進，因此本整合必須使用**雙親非強制 merge**，以最新 main tree 為底並加入 T08 worktree 81 個新原稿及其 README；不得退回較新 governance/claims 更改。本段更新並非修改 T08 作者原稿，T01 只更新新台帳與交接報告。
