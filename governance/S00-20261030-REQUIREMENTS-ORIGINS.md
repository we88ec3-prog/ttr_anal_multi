# S00 — Server 需求發現來源與共用需求台帳 (2026-10-30)

## 已定義的需求入口

使用者明確指定最少三種來源：

1. **Client 程式碼分析遇到的 Server 收發或狀態依賴**：既有來源證據足夠時先建 REQ 候選，日後分析可增加更精確的 byte/handler/branch；不能把靜態 handler 可達視為原版 Server 必然送封包。
2. **直接遊戲運行的觀察**：需明確另行授權原版 Client 執行及合規測試；公開安全的測試紀錄與原始版本 SHA 才能作第二種 discovery，不得虛構測試結果。
3. **玩家／管理員實際提出的要求**：功能、帳密和帳號操作、管理權限、GM 稽核、營運安全、備份復原等一律依 PLAYER_ADMIN_REQUEST 登錄，非原版協定證據。

使用者已要求把「營運／安全審查」併入第 3 類，**不另設來源**。建議但尚未啟用的第四類僅 \`SERVER_IMPLEMENTATION_FEEDBACK\`；原有 FB 仍照舊保留，未經核准不開啟此枚舉。

## 已建立的可用工具

- [單一需求索引](../design/requirements/index.json)：5 個基於程式碼分析的 **CANDIDATE**，無聲稱遊戲已經運行或玩家/管理員已提出的虛構條目。
- [來源與分流規則](../design/requirements/README.md)：一項需求可收錄三來源佐證，與 SPEC、GAP、RR、ADR、FB 的分工與去重。
- [檢查器](check_server_requirements.py) 及 [回歸測試](tests/test_server_requirements.py)：檢查 Client build 關聯、來源可信範圍、虛構運行無授權／無紀錄、未批准來源、APPROVED 無維護者記錄等機械規則。
- CI 執行 \`python3 -B governance/check_server_requirements.py --check\`。通過只表示結構合理，並不表示需求核准、Client 原生語義成立或測試已實際發生。

## 先行候選範圍

\`REQ-0001\` 登入請求/結果、\`REQ-0002\` 選服跨線、\`REQ-0003\` 角色清單、\`REQ-0004\` 角色 UI 就緒、\`REQ-0005\` 封包與解碼錯誤。所有 Client 證據仍以既有 CLM/RR/GAP/SPEC 為權威；部分已在 S00 有界整合，但不因建立需求而將 RR 接受或 GAP 關閉。

## 交付與下一步

將上述需求分類加入 [S00 開工流程](s00-workflow.md)、[SPEC 實作者交接](../spec/IMPLEMENTER-HANDOFF.md)。後續每一段研究分析（T02–T16）若找到新的 Server 收發依賴，即可提交同 ID discovery，或提出不同驗收目標的新 REQ。若之後獲准原版 Client 運行，研究員按真實環境/重現紀錄補 REQ；玩家及管理員的實際要求則由維護者內部收件，當前仍不開放外部 Issues。任何 REQ 的 \`APPROVED\` 必須另有維護者決議，不由索引/CI 自動發生。

無新增原版 Server 行為、原版 Client runtime 驗證、正式 SPEC 進階、Server 程式或新的研究認領。
