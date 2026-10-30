# T01 現有成果來源審核

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**開工必讀**：先核對最新 origin/main SHA，讀取 [T01 S00 待審收件箱](../../../research/dispatch/inbox/T01.md)、[唯一 RR 台帳](../../../research/requests/index.json) 與 [派工／審查規則](../../../research/dispatch/README.md)。本收件箱只提示來源報告待審，**不取代下文 T01 FULL-PASS、NEEDS_FIX、README 原有退回制度**。S00 才能 ACCEPTED；任何 RR 完成不自動升格原生證據。


## 跨 Task 驗收退回、修復及複驗（正式工作流程）

- T01 須先核對原件 SHA／來源版本、PE section 映射、指令界線、工具預期、CFG、caller/callee、資料流與所有實質肯定主張；不得用抽樣 bytes 全部相符冒充全文 FULL-PASS。
- 發現可補證據的缺口，優先繼續追查及完成本 Task 能處理的分析；若確認原稿錯誤且需原分析者修正，應將退回通知寫入 kr/tasks/<TaskID>/README.md 的「T01 驗收退回事項」，不得使用 GitHub Issue。
- 每個通知包含固定唯一 ID、原稿完整 GitHub 路徑與 Git blob SHA、錯誤位址/主張、第一手機器碼或資料反證、影響範圍、具體修正工作、完成條件、T01 驗收紀錄來源。
- 來源 Task README 限修改上述退回節，不能覆寫其他 Task 原稿、其 task.json、owner 或 native_complete。重複問題只更新既有 ID。每次寫入前讀取最新遠端版本，避免併發覆蓋。
- 狀態 NEEDS_FIX → FIXING → READY_FOR_REVIEW → RESOLVED；無現有證據或權限可再前進時才用 BLOCKED，必須留下解除條件。PARTIAL 不等同於已證錯誤。
- 原作者保留舊稿並提出修正版/勘誤及新版 blob SHA。T01 對新版受影響的全部主張重新驗收，通過才改為 RESOLVED；舊版仍保留 FAILED/SUPERSEDED 紀錄，禁止偷換 SHA 或刪除錯誤證據。
- 已獲提交授權時應將退回通知與同批驗收紀錄一起提交並遠端讀回；未獲授權時只保存待提交工作並如實回報。
- T08 範例與現行通知見 ../T08/README.md 的「T01 驗收退回事項」。已提交的 T01 原稿主張級驗收不會自動升格為遊戲功能完整還原。


2026-10-26：[完整反編譯保存批次 T01-BULK-20261026-02](../../../shared/integrations/T01-BULK-20261026-02/README.md)。依使用者指示先全部上傳，逐函式列明尚未完整審核的狀態；不改各功能主責或擴大原生驗收範圍。

狀態：bounded-review-handoff；負責人未認領。

## 範圍

逐行區分原生證據、歷史修補及 AI 替代；不重做功能解析

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：版本與替代規則審核，不宣稱現在仍可玩
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。版本與替代規則審核，不宣稱現在仍可玩
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：T02, T04, T08, T10, T13。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [trace_login_runtime.py](../../../unclassified/evidence/2ab7c5def650564b17693a383b09f7c27a48d60056958eb98b8547897ae7dca4.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [MAINLINE-FLOW.md](../../../unclassified/evidence/3a6376c5d84b4f03edc301d4467746680dfa448efb1df1eb5d2c20e278a20690.txt)
- [48-tutorial-battle-fixture.md](../../../unclassified/evidence/43aa311555dd6ad2e6843224cf710036c07b390942f7836b58ae9c80de587e59.txt)
- [06-runtime-login-fix.md](../../../unclassified/evidence/4d4a53d916b03a6766d33001449ed765af88a1cd1088471dc5bd2b4c6e0c72db.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [verify_localhost.py](../../../unclassified/evidence/63857e00b57640493c86c1e4e834f5cff9edef43baed0c2fe0b18c055b7e736d.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [make_localhost.py](../../../unclassified/evidence/75dc9112a6bf12985dc3c9d0359807abcdfbecb8788e5238ee965fcd46de3560.txt)
- [movement_simulation.py](../../../kr/evidence/83a4a5d5b2f1a6ca943b07ad47f801f57ade327d720b1ed0e41629e95ff49bc0.txt)
- [movement_position.py](../../../kr/evidence/846599cf8a88e9b999e75bc4f8bbfcd4930f2a8e31c0e2de5b30b6df3a07c40f.txt)
- [plaza_npcs.py](../../../kr/evidence/9a9e396000323e0b7359afeb933922ce3ff40b50a4dedd982ed752b2fe228e49.txt)
- [tutorial_monster_ai.py](../../../kr/evidence/9c1a55a267f465549b585b7c457471a6ce293feac0fe57daf40f3b74f6669286.txt)
- [inventory.json](../../../kr/evidence/b3ce8bd398b4972a9571b78f76c20f546dbbe664942c5470bb993675b2bd3667.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [31-collision-grid-spawn-and-trace-crash.md](../../../unclassified/evidence/ce5e1aad285f5b3fea35f655ebba154dfbfa6f67045204284988e7d97b05b56f.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [localhost-patch.json](../../../kr/evidence/e42a91ff65509d77c8bd65af089ec4d64d146b0ce3df1eeb6fbeee52c7cf6a20.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


2026-10-27 來源整合：[T01-20261027-03](../../../shared/integrations/T01-20261027-03/README.md)。只接受列明 SHA 與限定結論；其他暫存及整體功能未完成。本批已推送至 origin/main，接續基準 `d370a01645218615ad42595071c5328077e643a7`；推送收據見批次紀錄。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源審核：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)。先前105份source-only報告已有逐份來源與限定內容處置；完整語意／映射缺口仍保留。最新來源狀態見[來源審核索引](../../../shared/source-review-status.json)，實際遠端接續基準見批次收據。


2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。

## FULL-PASS 整合後不依 Task 分類（2026-10-28）

依 [T01 FULL-PASS 共用知識政策](../../../shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md)，T01 對**精確範圍全部原生主張均已核驗**的結論／子流程，發表於 [shared/verified-knowledge](../../../shared/verified-knowledge/README.md)，依玩家功能、協定與資料結構檢索，不依來源 Task 分類。仍保留 Task ID、作者、原稿路徑與 Git blob SHA 為審核及錯誤退回 metadata，不搬移既有原稿。

准入必須完成原件 SHA、PE/VA/raw、指令邊界、CFG／上下游／資料流與相關矛盾的必要查核；抽樣 bytes／SHA 一致、來源收件、局部主張通過不會讓全篇或整 Task 通過。僅通過的有界子流程可納入；所有未通過內容保留待審來源。原版 Server 內部演算法不是 Client 逆向驗收，列 Server 待開發；未知 Client 封包列 Client 待逆向。每批建立 FULL-PASS 條目、更正或撤銷的可追溯清單，禁止隱性升級歷史 accepted-claims。


2026-10-29 階段整合：[T01原稿語意驗收檢查點](../../../shared/integrations/T01-20261029-semantic-review/README.md)。318個來源版本已凍結；全文FULL-PASS為0，69個原版已有反證、153部分、9來源級、87待審。46項具體退回及映射群組已更新Task README，另有3項精確原生結論准入共用知識。接續逐篇來源SHA／碼塊待辦，不把本次階段收尾算作318篇完成；實際main基準見批次推送收據。


2026-10-29 接續整合：[T01 第02批全文驗收](../../../shared/integrations/T01-20261029-continuation-02/README.md)。本批10篇逐篇核對，158／177／197三篇有界全文通過；舊173／196退回結案但舊版維持FAILED；新增10項修正／限定退回。最新318版狀態為 全文有界通過3、FAILED71、PARTIAL151、SOURCE_ONLY9、PENDING84，未全部完成；以本批 source-ledger 與推送收據接續。


## Server 規格整合的新通道（Phase A 試行，待合併）

T01 對 Server 設計的接收、精確主張去重、風險分流及 S00 交接，按 [新 T01 工作流程](../../../governance/t01-integration-workflow.md) 辦理。這是**與舊版全文 FULL-PASS 分開的增量通道**；不更改 318 份歷史來源狀態、其他 Task 主責及 `shared/verified-knowledge/` 准入要求。原稿失敗/部分通過/待審應原樣保留；非已驗證材料只可標註可信度交 S00 參考。

2026-10-29 使用者指定改按最新main新方法接續：以 `9d97ea37e` 為基準，完成[新流程首次收件與主張交接](../../../research/handoffs/t01-20261029-risk-intake/README.md)。318版R0收件完成（剩0），其中4版萃取有限主張並查對衝突，待萃取314版；歷史全文通過仍3／318、未通過315，不再作規格整合門檻。沒有S00接受或SPEC_CONSUMABLE，舊第03批未提交全文裁決保留本機草稿。

2026-10-29 指定分支增量：[t03/roy/chatgpt-web整合交接](../../../research/handoffs/t01-t03-roy-20261029/README.md)。19篇原稿、13項有限主張及10筆去重追加來源已完成新通道CONFLICT_CHECKED（本批剩0）；1項精確API layout反證以T03 README退回，Print Screen更正連回早期provenance推論。未新增全文FULL-PASS或SPEC_CONSUMABLE，不改318版既有進度。

2026-10-29 指定T08分支：[t08/roy/chatgpt-web新通道整合](../../../research/handoffs/t01-t08-roy-20261029/README.md)。138份原稿blob原已在main；補15個SRC、完成135份整合差額，保留3份既有正式關聯，本分支剩0份。新增55項有限主張及233筆追加來源，24個映射FAILED與6類既有REFUTED單獨隔離；原318版R1待萃取剩194份，歷史全文判決未改。


2026-10-30：[T10分支整合階段保存](../../../research/handoffs/t01-t10-roy-20261029/README.md)。依使用者要求暫停；核127份來源、原樣補入22份原稿並補登29個SRC，保存early49／middle44份待裁決提案。未發布新canonical claim，本分支canonical整合剩127份（34份尚無完整提案）；原318版待萃取仍194份。T01自有通知3處誤貼欄位已勘誤，歷史判決及退回狀態不變。


2026-10-30 T16 43 筆作者端勘誤後續獨立複驗：[T01-20261030-t16-followup](../../../shared/integrations/T01-20261030-t16-followup/README.md)。11 筆精確退回修正已由 T01 `RESOLVED`，32 筆仍 `READY_FOR_REVIEW`；不表示相關 T16 原稿 FULL-PASS、T16 branch 合併或 S00 SPEC STABLE。精確原件/新舊 blob 與剩餘義務見批次索引。

2026-10-30 T16 第二輪：原始 Event.stp 的 TutorialBase 來源 SHA 更正 14 筆、A0A4/A078 佇列欄位 1 筆、T01 對 4AEDB0 錯誤反證撤回 1 筆；本輪新增 16 筆 RESOLVED，累計 27 RESOLVED / 16 READY_FOR_REVIEW，未提升 T16 原稿全文。完整決議及缺件請求：[第二輪驗收](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。

2026-10-30 T16 第三輪：已透過使用者上傳 phase3 ZIP + 原件 KR BIN 對 19 root、4464 native 指令、4905 CFG edges、28 問題窗口、71 舊 call/jmp 做獨立查核，**本輪新增 16 筆 appendix/CFG 限定退回 `RESOLVED`；固定 T16 退回累計 43/43 `RESOLVED`。** 這不是 T16 全稿 FULL-PASS、Quest 原生封包實證或 S00 SPEC STABLE。詳見 [完整獨立驗證與 Table.stp 解包](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md)。

2026-10-30 Quest16 T01 有界驗收整合：[T16-117／121／122／123 四來源與 R2 反證](../../../research/handoffs/t01-20261030-quest16-r0-r2/README.md)。正式新增 4 SRC、6 CLM（5 PARTIAL／1 REFUTED），針對117建立 T01-RETURN-T16-117-Q16-MODE2-C2S36-001 NEEDS_FIX；歷史43筆 RESOLVED 不變，未新增全文FULL-PASS/NATIVE_VERIFIED/SPEC_CONSUMABLE。

2026-10-30 RR-0001／RR-0004 T01 限定驗收：[兩份原始來源、獨立 BIN R2、5 項新 CLM](../../../research/handoffs/t01-20261030-rr0001-rr0004-bounded-r2/README.md)。原樣補入 E57／E58 提交報告 blob 並登錄 SRC-0461/0462，補足原先 main 缺少 RR 來源導致的驗證阻塞；兩 RR 仍由 S00 判定 ACCEPTED。沒有新的全文 FULL-PASS 或 SPEC_CONSUMABLE，不改其它 Task 的原始研究、owner 或 T16 退回。

2026-10-30 T01 多分支 merge／有限驗收：[完整來源、R1 主張及 BIN R2](../../../research/handoffs/t01-20261030-multi-branch-merge-r0-r2/README.md)。保留 extra/roy1、rr/t02/roy 的原始分支提交歷史，整合 T16-114/115/116/118/119/120/124/125 與 E59 共九份 SHA 限定原稿（SRC-0463～0471），新增 8 條 PARTIAL CLM；RR-0006 SUBMITTED、RR-0007 CLAIMED 沿用最新主線，不覆寫 S00 台帳；T16-117 原 NEEDS_FIX 仍有效。來源納入≠全文 FULL-PASS 或 RR/SPEC 接受。

2026-10-30 RR-0008/E68 T01 有界 R0–R2：[來源身分、21 個原生 byte 位址、兩個 RTTI、5 個 direct E8 target 與 Event.stp 資源交叉驗證](../../../research/handoffs/t01-20261030-rr0008-e68-bounded-r2/README.md)。新增 SRC-0474、CLM-SCENE-0005/0006（PARTIAL），既有 CLM-SCENE-0004 追加限定來源；RR-0008 轉 IN_REVIEW 供 S00 裁決，原版選角回覆仍 UNKNOWN、RR-0002 BLOCKED；**不新增全文 FULL-PASS 或修改其它 Task 退回／SPEC／GAP**。
