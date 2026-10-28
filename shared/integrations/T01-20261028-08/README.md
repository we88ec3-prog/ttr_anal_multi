# T01-20261028-08 — T16 同段雙原稿來源仲裁登記（第一階段）

> 此批為 T01 整合者的 **來源層級比較／仲裁佇列**，不是新的原生語義驗收，也不代表 T16 的四段任務流程完成。依既有 T01-20261028-07 清單，八份來源全都已在 GitHub main；**不搬移、不覆蓋、不刪除**任一 T16 原稿。

## 基準與方法

- 前批入口：`shared/integrations/T01-20261028-07/README.md`，先前已索引 80 份 T08/T10/T16 研究原稿。
- 此批閱讀時 main 最新已見：`9fef4b2e534b00f1e2d50e62094853b474adda2b`；整合前逐一以 GitHub fetch_file 取得下面八份 Markdown 的 blob SHA 並對照原始內容開頭。
- 本批是 **GitHub 文件內容審閱**。沒有重跑原始 BIN 的每條指令，沒有取得完整 Lua/XML 原始 bytes，也沒有執行遊戲或後端。
- T16-41～44 各有兩份不同主題延伸的原稿，段號相同但 SHA 不同。以 **完整路徑＋blob SHA** 作為獨立來源識別；不得由檔名時間或篇幅決定唯一正本。
- 原始 KR BIN 版本識別：SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（來源原稿記載；**本批未重新做原始檔 hash 驗算**）。
- 不修改 `shared/catalog.json`、`shared/source-review-status.json`、Task owner、任何研究原稿；不把本次比對自動標成 native_confirmed。

## 逐段雙來源與差異

| 段號 | 來源 A：較早的來源稽核版（blob SHA） | 來源 B：後續含 BIN 指令摘錄版（blob SHA） | 可確認的內容差異與處置 |
|---|---|---|---|
| 41 | `20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md` (`709dc7206d8ef70024a2f77de79d86ce3c557cc7`) | `20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md` (`46d93721bb6a343d83a00fa5cfe2283b33e16337`) | A 彙整 Lua chunk SHA、prototype/word 數與入口界線；B 加入 `0x004A8A60` 等機器碼摘錄。二者尚未取得完整 Lua 腳本指令語義；均保留。 |
| 42 | `20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md` (`97773d959e623df88dec3a4506ebd83c8ac9c115`) | `20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md` (`77b960803fe95ba9fc5dd7a7f086dcc79c05b6e4`) | A 包含 Table.stp offset、XML root/children 與取用阻塞；B 加入 `0x00504740` loader 的 BIN 指令摘錄、KR/TC 來源界線。不能由 root count 推出 Quest ID 或前置。 |
| 43 | `20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md` (`2feafd823d0de32ec1b2503df9fa2a9c2b3c1856`) | `20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md` (`22c02f093ab0e8804e42ec5b071c9fb316e9bebc`) | A 以 scenario14→TUTO→Quest16→Quest15 待驗證箭頭及跨任務契約呈現；B 補 `0x004A89C0` Lua bridge 相關指令摘錄。箭頭仍 **非已證實的 server 狀態轉換**。 |
| 44 | `20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md` (`c7d68207f95fd2ceb1d9ad8cbe4d5410e04e8f41`) | `20261028-095118-chatgpt-web-roy-T16-44-KR-quest-state-authority-acceptance.md` (`8262d45d0f8cf5672ff4617d2c0ac741d764c205`) | A 詳列 request/validation/write/notify/restore、未執行案例；B 加入 BIN 指令與較完整驗收矩陣。Quest16→Quest15、server authority、跨登入續接均未閉合。 |

上述檔名的共同目錄均為 `kr-temp-roy/`。表格的 blob SHA 是 **Git 檔案 SHA**，不是 SHA256 原始素材。

## 尚未裁決與下一個可執行整合單位

1. **待逐主張證據仲裁**：逐項對照 8 份全文中重疊的 VA、Lua prototype 計數、QuestInfo/QuestTalk schema、各版本成員 SHA；若有不同結論，記錄 A/B 主張和反證，不取時間較晚者覆蓋。
2. **待直接原件補證**：以可讀的 Lua chunk / XML row bytes 核實 `TutorialMain.lua` 內實際事件、Quest 16/15 row、quest authority 及 server packet 的 producer→handler→writer；不得因 BIN 摘錄在 Markdown 中存在便宣稱本批重新驗證。
3. **不升級**：保留先前 `T01-20261028-07` 的全部 80 份「已收件、待審核」狀態。T16 舊原稿明示 raw resource 存取阻塞，不應將「已記錄 raw SHA」表達為「已解析完整內容」。
4. **跨任務**：T02 負責 packet envelope，T07 場景轉換，T14 結算，T15 保存；T16 只負責任務進度語義。不改 owner、catalog 或他人原稿。
5. **其他 Task**：T08 173–200、T10 081–100 本批不重新做 native 語義審核；其來源狀態依 T01-07。

## 本批驗收狀態

- **通過：** 八份 GitHub 文件存在、四組相同段號但不同 blob SHA、表格保留兩份來源及對應審核邊界。
- **未進行／未通過：** 八份全文逐主張仲裁、原始 BIN 重新直接比對、Lua/XML 原始內容解析、完整 client→server 任務狀態鏈、可玩性。
- **提交意義：** 只新增 T01 自己的整合比較文件，並保留既有來源；提交成功不改變原生研究的驗收分級。
