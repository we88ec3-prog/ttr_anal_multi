# T01：extra/roy1 × T16 × T02/T03 增量原生整合（2026-10-30）

**這不是單純 Git 分支 Merge。** 已執行跨 Task 有界主張、歷史勘誤、原生 KR BIN 定點核對並保存 R0–R2 三批連續技術原稿。

- [R0-R2.md](R0-R2.md)：59 篇來源（extra 37、T16 22）及 14 個 provisional 主張／反證的原始分析。
- [batch2.md](batch2.md)：57 條 native bytes／20 條直接邊、Pool+28/+48 與 WSASend/GQCS 計數。
- [batch3.md](batch3.md)：**本批新增** Pool reuse/new、同 key tree erase、新 Conn 指標及 IOCP completion key 的條件式生命週期。
- [source-intake-proposal.json](source-intake-proposal.json)、[bounded-claims-proposal.json](bounded-claims-proposal.json)：原始 R0/R1 候選來源與主張，未完整逐檔 raw SHA 時不可假稱 canonical FULL-PASS。
- [native-checks-batch1.json](native-checks-batch1.json)：第一批原生檢查 JSON。

最新開工主線為 `eadabf33f31da542db32ddf1d10cabea5a020ea4`，RR-0005 已 `CLAIMED` 且 owner=T02。**本次不變更 RR / S00 SPEC / Task 原稿 / T01 原生 FULL-PASS**。歷史原稿自述未 push 是當時真實狀態；本批補推 Git 只更新整合交接，不覆寫歷史文字。完整本地 batch3 script/JSON/disassembly 視窗見附帶 ZIP，勿誤稱此處正文是全部 rooted-CFG。
