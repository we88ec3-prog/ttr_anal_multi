# 研究接收與主張索引（T01）

此目錄是 **新增整合/檢索通道**，不是既有 `kr/` / `tc/` 原稿及 T01 歷史台帳的替代品。

- `claims/index.json`：增量精確主張/證據/版本索引；不等於原稿已全部通過 FULL-PASS。
- `requests/index.json`：**唯一的研究補證 RR 台帳**（S00 發件、Task 認領、回報、T01/S00 審查）；不得自行猜測原始協定。
- [T01 新工作流程](../governance/t01-integration-workflow.md)：風險分流與兩軸狀態。
- [舊版嚴格 FULL-PASS](../shared/verified-knowledge/README.md)：完整保留，不從本索引自動推升。

T02–T16 研究原稿應繼續保留完整技術證據，對 S00 交付 bounded claims、server-impact 與必要 GAP；REA 可選，無 REA Agent 也可查原稿/快取/索引。

- `intake/index.json`：**新的 T01 來源收件台帳**，保留精確原稿 SHA 與兩軸工作狀態，不取代歷史 FULL-PASS。
- [來源收件範本](templates/source-intake.md)、[Server 影響交接範本](templates/server-impact.md)。

- [正式研究派工規則與 T01–T16 收件箱](dispatch/README.md)，KR／TC 共用 RR index，但各 Agent 必須按 client_version 認領。

2026-10-29：[T01 新流程首次接續](handoffs/t01-20261029-risk-intake/README.md)。318版完成R0身份收件，其中4個來源完成有限主張／衝突查對，其餘314版待萃取；新增3項重用既有原生決議與1項PARTIAL導航主張。歷史全文通過3／318不變，不作本通道准入門檻；未標S00接受或SPEC_CONSUMABLE。

2026-10-29：[T03 roy/chatgpt-web指定分支整合](handoffs/t01-t03-roy-20261029/README.md)。LOGIN-01／02、T03-3～19共19篇原稿以精確blob保留，13項有限主張與10筆canonical追加來源完成衝突查對；本批新通道剩0篇。Print Screen／D3DX更正與T03-6 API layout退回單獨追溯，沒有新增FULL-PASS、S00接受或RR結案。

2026-10-29：[T08 roy/chatgpt-web指定分支整合](handoffs/t01-t08-roy-20261029/README.md)。138份既有原稿完成新通道查對（本分支剩0）；新增15個SRC、55項有限主張及233筆追加來源，保留3個正式來源關聯。原318版待萃取剩194份；沒有新FULL-PASS、S00接受或既有退回狀態改動。


2026-10-30：[T10分支整合階段保存](handoffs/t01-t10-roy-20261029/README.md)。依使用者要求暫停；核127份來源、原樣補入22份原稿並補登29個SRC，保存early49／middle44份待裁決提案。未發布新canonical claim，本分支canonical整合剩127份（34份尚無完整提案）；原318版待萃取仍194份。T01自有通知3處誤貼欄位已勘誤，歷史判決及退回狀態不變。


2026-10-30：[extra/roy1 × T16 跨 Task 三批 T01 R0–R2 實質整合](handoffs/t01-20261030-extra-t16-r2/README.md)。保留59份完整來源身份草案及14項有界主張草案；8份高優先來源已具SHA256正式SRC收件，新增4項PARTIAL CLM。第三批對Conn池重用／key-map替換／IOCP completion key再作47條定點指令及15條直接分支驗證。RR-0005仍由T02 CLAIMED、51份來源待正式收件；沒有新R3 FULL-PASS、S00 SPEC STABLE或RR ACCEPTED。
