# 後續缺檔清單與現有檔案覆蓋（T01 / KR）

## 本輪已取得，不需要再上傳

- **`Event.stp`**：本會話已有原始檔，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。可還原 `Event/TutorialBase.lua`（1416 bytes）及 `Event/TutorialMain.lua`（5480 bytes）；不需要另外提供相同內容的 `.lua` 才能關閉 SHA 通知。
- **`Tartaros.bin`**：本會話已有 KR 第一手機器碼，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。T01 已直接核對本批欄位與 callback VA。
- **`Tartaros.exe`**：已上傳，但與本批 SHA 恢復無直接關係。

## 若要繼續 Quest16→Quest15、NPC／接任務條件驗證，請優先提供

1. **原版 KR `Table.stp`**（若遊戲資源以此容器保存），或直接解出的完整 **`Table/QuestInfo.xml`**，期望原件內容 SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。用途：確認 id=15/16 是否存在、任務前置與資料欄位的實際 schema；目前從其他 XML 片段不能推定 quest 15/16 不存在。
2. **`Table/QuestTalk.xml`** 原始完整檔（可隨同 Table.stp 提供；歷史 evidence ID `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`），用途：檢查真正 NPC giver/finisher 對話映射，不能只依序列中 id=13 後為 id=17 宣稱 quest 15/16 不存在。
3. **T16 作者完整 `20261029-220621-chatgpt-web-roy-T16-T01-returns-phase3.zip`**（不是原版遊戲資源），作者交接明示有 rooted CFG `root-*.json`、28 地址與 71 call/jmp 交叉對照；這是後續解除 16 個附錄相關通知的最佳補件。T01 仍會以現有 BIN 重新驗證。

如果另外有原始**文字版** `Event/TutorialBase.lua` 或 `Event/TutorialMain.lua`（非 Lua bytecode），可補充符號/語意，但**不必為了本次 SHA 複驗重新上傳**。

## 不應要求的資料

- 不要求原版 Server 內部程式碼才能驗證 Client 的封包、狀態與 UI。Server 任務前置與資料儲存演算法由 S00/SERVER 開發另行設計。
- 禁止將 fixtures、舊 patch 或推測 Quest 16→15 的結果作為原版 Client 端到端驗證。