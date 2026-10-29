# T10 普通攻擊與連段

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**每次開工必讀**：確認最新 origin/main SHA，先檢查本 README 的 T01 驗收退回與既有主責，再讀 [T10 S00 收件箱](../../../research/dispatch/inbox/T10.md)、[唯一 RR 台帳](../../../research/requests/index.json)、[派工／認領／回報規則](../../../research/dispatch/README.md)。先處理已指派且獲使用者授權的 P0/P1；只在認領變更發布於 main 後才算跨 Agent 已認領。完成研究需提交 Markdown + 精確 Git blob SHA 並更新 RR 為 SUBMITTED，S00 才能結案。**收件箱不會自動喚醒本 Agent**；不變更原有 Task owner、原稿及 T01 退回規則。


## T01 驗收退回事項

<!-- T01-continuation-02-notices:start -->

### 2026-10-29 接續第02批複驗

逐篇主張與全部碼塊已核對；以下限定需修正的內容，保留其他獨立支持的結論。

#### T01-RETURN-T10-055-EVIDENCE-001 — NEEDS_QUALIFICATION
- 原稿：`kr-temp-roy/20261028-021236-chatgpt-web-roy-T10-055-special-key-domain-tree-branches.md`；Git blob `61c1e3bca931c781be72db549bed483202cfff1a`；SHA256 `3b3a2dcf12540643499faa3f00770b61e9e74669fe6048744f0313503280f84a`。
- 問題：第一視窗起點6D4BB0在6D4BAC指令的immediate內，至6D4BC2才重新對齊；第四視窗6D4D40是6D4D3E LEA的immediate，lock push不是reader正常路徑指令。
- 原生依據：6D4BAC c7 45 fc 04 00 00 00 (mov[ebp-4],4);6D4BB3 e8 98 bb ff ff (call6D0750);6D4BBD e8 58 d7 1b 00 (call89231A);6D4D3E 8d 4d f0 (lea ecx,[ebp-10h]);6D4D41 51 (push ecx)
- 修正及複驗：保留原稿與SHA；提供勘誤／標註版，明列錯位視窗頭不屬native instruction證據；分開明示.byte尾端截斷和續行；替泛稱「列出的讀寫/call已確認」限定有效區段。可附本批rooted canonical excerpt，不能更換原來源SHA。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t10/README.md)。

#### T01-RETURN-T10-056-EVIDENCE-001 — NEEDS_QUALIFICATION
- 原稿：`kr-temp-roy/20261028-021236-chatgpt-web-roy-T10-056-indexed-reader-polymorphic-consumers.md`；Git blob `e2da2b34e1c97aeffd192d5af7a258f80b50c527`；SHA256 `0d0b9f07373355c959291cb9ac8fddc5ad840b05167e5222b9001f8626f549a5`。
- 問題：第三視窗596430落在59642E JMP的rel32內，其假CALL596441→F8DC6459跨過真正59643F CALL的immediate和596444 CMP；596452起才重新對齊。
- 原生依據：59642E e9 7a 01 00 00 (jmp5965AD);596433 68 34 20 bf 00;596438 e8 f3 76 2e 00 (call87DB30);59643D 32 db (xor bl,bl);59643F e8 9c e8 13 00 (call6D4CE0);596444 83 f8 01 (cmp eax,1)
- 修正及複驗：保留原稿與SHA；提供勘誤／標註版，明列錯位視窗頭不屬native instruction證據；分開明示.byte尾端截斷和續行；替泛稱「列出的讀寫/call已確認」限定有效區段。可附本批rooted canonical excerpt，不能更換原來源SHA。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t10/README.md)。

<!-- T01-continuation-02-notices:end -->


<!-- T01-20261029-stage-notices:start -->

### 2026-10-29 階段複驗通知（4筆具體更正，既有ID原位補充）

本次僅通知已證實的錯誤；原稿全文驗收仍未完成。保留原稿，提供獨立修正版及新 blob/SHA；複驗通過前維持 NEEDS_FIX，不能將局部主張支持算作全文 FULL-PASS。

[本批總台帳](../../../shared/integrations/T01-20261029-semantic-review/README.md)；[機器可讀退回紀錄](../../../shared/integrations/T01-20261029-semantic-review/return-notices.json)。

#### T01-RETURN-T10-062-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-062-lifecycle-reset-dual-branch.md`；Git blob `43ca57972ac64ad0752ce37c419331ff120befda`；SHA256 `5ea18b4b53024c5ca3c1ef67d2b70596c0966ea6d61032d1f55ec1ff0712c0b5`。
- 問題：First reset branch clears ordinary40bytes before the optional6D1DA0 initialization call, contrary to the stated initialize-then-clear order.
- 原生反證：第一支可先依 `FB7C14` 呼叫 `6D0750`；但 `0x6D4A95` 僅測試 `FDF3EC` 並留下 flags，`6D4A9C..6D4AC9` 先清普通 40 bytes。`0x6D4ACE` 才依該 flags 選擇分支，未初始化時 `0x6D4AD9 = E8 C2 D2 FF FF` 呼叫 `6D1DA0`，最後 `6D4AF3` 呼叫 `823850` 清特殊樹。故特殊域初始化不在普通清零之前。
- 修正及複驗條件：Preserve original; supply separate correction with new blob/SHA and revalidate affected argument/control/value flow. Use the per-item specific conditions in DECISIONS.md.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md)。

#### T01-RETURN-T10-063-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-063-indexed-reset-list-partition.md`；Git blob `82b83636f00ded1be14216c7529a686fad331a16`；SHA256 `719c52c2b41b21faf06d4e345e31b01b95c685659239a34298a486e64ea014eb`。
- 問題：Clear path at6D4CAE has no ESI<=27 guard; reader guard cannot be transferred to writer.
- 原生反證：第一支可先依 `FB7C14` 呼叫 `6D0750`；但 `0x6D4A95` 僅測試 `FDF3EC` 並留下 flags，`6D4A9C..6D4AC9` 先清普通 40 bytes。`0x6D4ACE` 才依該 flags 選擇分支，未初始化時 `0x6D4AD9 = E8 C2 D2 FF FF` 呼叫 `6D1DA0`，最後 `6D4AF3` 呼叫 `823850` 清特殊樹。故特殊域初始化不在普通清零之前。
- 修正及複驗條件：Preserve original; supply separate correction with new blob/SHA and revalidate affected argument/control/value flow. Use the per-item specific conditions in DECISIONS.md.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md)。

#### T01-RETURN-T10-007-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/T10/20261027-191139-chatgpt-web-roy-T10-7-runtime-input-merge.md`；Git blob `d99588c94a6647acffb036ef497b66377d22e200`；SHA256 `7c28ce9bbca0d2081a534c51d14231d323dc1263be00d7f307d48cb4e677e3a4`。
- 問題：5467F1 is pointer load; actual WORD store is5467F4; correct main dataflow retained.
- 原生反證：第一支可先依 `FB7C14` 呼叫 `6D0750`；但 `0x6D4A95` 僅測試 `FDF3EC` 並留下 flags，`6D4A9C..6D4AC9` 先清普通 40 bytes。`0x6D4ACE` 才依該 flags 選擇分支，未初始化時 `0x6D4AD9 = E8 C2 D2 FF FF` 呼叫 `6D1DA0`，最後 `6D4AF3` 呼叫 `823850` 清特殊樹。故特殊域初始化不在普通清零之前。
- 修正及複驗條件：Preserve original; supply separate correction with new blob/SHA and revalidate affected argument/control/value flow. Use the per-item specific conditions in DECISIONS.md.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md)。

#### T01-RETURN-T10-026-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/T10/20261027-205931-chatgpt-web-roy-T10-26-subai-cast-state-machine.md`；Git blob `c82bc8c3c53f304faecab0911f214b89440d1784`；SHA256 `8bbf8f35d131d8274a7f49a1d26dac551b60e8f072a0df274de780d19a4ada2f`。
- 問題：549D54 belongs independent549C60, not549980; function boundary/caller attribution false.
- 原生反證：第一支可先依 `FB7C14` 呼叫 `6D0750`；但 `0x6D4A95` 僅測試 `FDF3EC` 並留下 flags，`6D4A9C..6D4AC9` 先清普通 40 bytes。`0x6D4ACE` 才依該 flags 選擇分支，未初始化時 `0x6D4AD9 = E8 C2 D2 FF FF` 呼叫 `6D1DA0`，最後 `6D4AF3` 呼叫 `823850` 清特殊樹。故特殊域初始化不在普通清零之前。
- 修正及複驗條件：Preserve original; supply separate correction with new blob/SHA and revalidate affected argument/control/value flow. Use the per-item specific conditions in DECISIONS.md.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md)。

<!-- T01-20261029-stage-notices:end -->



## 既有任務說明

狀態：bounded-review-handoff；負責人未認領。

## 範圍

輸入、連段及取消流程；傷害公式交 T12

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：CHAIN_WINDOW=.65及服務端續段排程是自製；官方連段取消窗口未知
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。CHAIN_WINDOW=.65及服務端續段排程是自製；官方連段取消窗口未知
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：0.65秒連段窗口是本機實作選擇，正式連段/取消窗口仍待證據。

## 依賴、接續與驗收

依賴：T02, T04, T09。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/battle-input-batch-producer.txt](../../../unclassified/evidence/0815371627e08a9ce0e2c3bd049b3e9b38a563ccae35282295d3167d1e24f046.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [native-index/battle-input-socket-worker.txt](../../../unclassified/evidence/172d170a21ef8fedc0bd04c0fd9bf0dcb88da582fa7a2b15072630f554371bee.txt)
- [BATTLE-INPUT-TO-SOCKET.md](../../../kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [audit_native_skill_timing.py](../../../unclassified/evidence/49782e44e5da6f0f86cf0ead1fecee49e0432cb4b20226024734366b6772b5e4.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/battle-input-packet-copy.txt](../../../unclassified/evidence/588f5dc116999cb57a48fed1d3db37f0935618529dd97ece4a2aaffa7a244b5b.txt)
- [native-index/battle-input-network-slot-send.txt](../../../unclassified/evidence/67682cca0b94bc1698d95851c3f8b7e5d666fa653a33d90b225c5c52f8730c1c.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [audit_battle_input_transport.py](../../../kr/evidence/74754a41cc22cc3766d83a94e1043b3521951faff7f6bb46bdf30392d7931acd.txt)
- [CONTROL-AND-SKILL-SOURCE.md](../../../unclassified/evidence/7bafd3143273877097a98dd0c42dc0f1c7e30719d0e86821318db4612473f89f.txt)
- [native-index/network-overlapped-wsasend.txt](../../../unclassified/evidence/7f5642ef15578b61a3491e8663e77e15876e3ec8a85ef0d2004671019cac8e9d.txt)
- [audit_battle_controller_sidepaths.py](../../../kr/evidence/80e6e839c336f750094477c4252b4d65358cec8345c22f524a54e396c4cf89c5.txt)
- [BATTLE-CONTROLLER-SIDEPATHS.md](../../../kr/evidence/91830956fb04388f5eabd1c876f283c6e78e9f001e953e978345472ff3572866.txt)
- [native-index/battle-input-row-append.txt](../../../unclassified/evidence/91df777cd65f424ef5e91e8d22635a0e80381ef2396b11a4d200da7440488ec6.txt)
- [native-index/battle-controller-sidepaths-audit.json](../../../kr/evidence/af5971a741bd7818c74ac9e8e51f6a765b8741cd57efc2f6d9bb0dae909c3371.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/battle-input-connection-framing.txt](../../../unclassified/evidence/cafb013e5bbd93cfa8b7d85af36cc32c61807a612ac95069cc55c8f0b4f0b96e.txt)
- [native-index/network-close-connection.txt](../../../unclassified/evidence/db5aafa5b1384358c3eb777361b2fcc9974e9b69c0bd6f9ef014cb15523f9014.txt)
- [native-index/battle-input-transport-audit.json](../../../kr/evidence/dd0ce08b9da2191d41341ed42c2f3e2c86c6ffdea781395adfc1b44c740940a8.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/battle-input-connection-queue.txt](../../../unclassified/evidence/f7402fb5881f2eff0a3a56b4fe54072ce4b3635c213a8cd17ac47b018f7e4163.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源審核：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)。先前105份source-only報告已有逐份來源與限定內容處置；完整語意／映射缺口仍保留。最新來源狀態見[來源審核索引](../../../shared/source-review-status.json)，實際遠端接續基準見批次收據。


2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。
