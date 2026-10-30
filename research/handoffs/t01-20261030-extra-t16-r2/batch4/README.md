# T01 — R0/R2 第四批：51 份來源 SHA256 收件草案、同 key erase rooted CFG、Quest16 type2 反證

- 日期：2026-10-30（Asia/Taipei）。研究者：ChatGPT-web roy／T01 integration。
- 本批研究證據以原始 KR `Tartaros.bin` 為第一手；全文重要證據詳見 [T01-20261030-R2-BATCH4-FULL-REPORT.md](T01-20261030-R2-BATCH4-FULL-REPORT.md)。
- `main` 開工基準 `dbaf50a1dc1ff119e942458f79700bd18e8c7004`；`RR-0005=CLAIMED`、主責 T02。T16/extra 研究分支正在發展，未合併到 `main`。
- 51 份主線已保存來源（extra 33、T16 18）的 Git blob SHA 回查符合原先 Merge manifest，並從工具回傳的 UTF-8 文件內容計算 source SHA256；補足上一批剩下 51/51 的 R0 所需身分資訊：見 [source-intake-51-proposal.json](source-intake-51-proposal.json)。此前已入主線的 8 篇正式 `SRC-0392～0399` 不重複新增。**新 51 份只作登錄 `REGISTERED`，不代表 R1/R2/R3 完成**。
- 完整 `0x7B6890` rooted reachable graph：223 指令、45 條 branch，10 處 direct CALL，沒有間接 control transfer；刪除樹 node 時經 `0x89120C→0x8920FC→HeapFree`；所追蹤 call chain 不 dereference node+0x10 Conn value/不做 Conn Close。僅證這條 tree erase caller/helper 的 bounded behavior，不證舊 Conn 所有權或 IOCP 競態全局安全。
- `T16-117` 指出 T16-116 的 UI type1/type2 誤連；原件重新驗證 `0x5009D8` type1 gate、`0x500A58` type2 gate，且 `0x5008F3` 叫 `0x500A00`。T16-116 的 0x74 key append 只能作有條件來源主張，不得沿用 type1 view 推導 Quest16 type2 UI。
- [native-r2-batch4.json](native-r2-batch4.json) 是完整驗證輸出；[verify_r2_batch4.py](verify_r2_batch4.py) 是唯讀重驗腳本；[native-disassembly.md](native-disassembly.md) 包含 12 個精確函式/呼叫視窗。
- [apply_source_proposal.py](apply_source_proposal.py) 是**只產生本地合併 JSON** 的腳本，要求既有 canonical SRC max=0399；不 Commit/Push、不自動進行 GitHub 修改，日後如 main 更新須停下重新核對。

## 本批正式狀態

**未 Commit/Push**；此輪使用者僅要求繼續驗證與整合，沒有當次明確的 Git 上傳授權。所有增量可在本地交接包使用，不能宣稱遠端正式 index 已從399升到450。未新增 FULL-PASS、`NATIVE_VERIFIED`、RR `ACCEPTED`、S00 `STABLE` 或 Server 可玩驗收。