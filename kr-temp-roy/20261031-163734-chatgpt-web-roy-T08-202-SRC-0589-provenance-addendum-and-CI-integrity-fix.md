# T08-202 SRC-0589 來源凍結與作者側後續勘誤補充

研究者：chatgpt-web roy；2026-10-31 16:37 Asia/Taipei。此次為 GitHub CI 完整性修復，不擴張202研究範圍，不變更T01/C01/S00主責或審核狀態。

## 來源身分（必須保持不變）

- T01登錄項：`research/intake/index.json` 的 **SRC-0589**；限定主張 `CLM-CLIENT-0066` 在 `research/claims/index.json`。
- 凍結來源：`kr-temp-roy/20261031-043540-chatgpt-web-roy-T08-202-native-owner-record-0008-0007-000A-and-26-81-lifecycle-analysis.md`。
- T01凍結來源 Git blob SHA：`1db1077f7e7c0ed9cd0de070a09daec9f9db5eb9`。
- T01凍結來源 SHA256：`94cffb829a4957ff482e89e0d03761ce6b2fad31268e86b77e40e6a223ad2abb`。
- 先前T08 branch將下述補充說明插入原來源的開頭，讓同路徑內容 SHA 改成 `5e9c3d89f982a47f9b65cd158737dd95eba6a52f`；因此2026-10-31 GitHub Actions run `41127979541` 的 `governance/validate_s00.py` 拒絕 `SRC-0589`，顯示 `source SHA256 mismatch` 和 `source Git blob SHA mismatch`。這是來源身分錯誤，不是Tartaros.bin機器碼判定為錯。
- **修復方式**：還原原凍結路徑內容（與main SRC-0589相同 Git blob）；新增補充獨立source，不修改 T01 登錄的 Git blob/SHA，也不重寫T01已審的限定主張。

## 自原來源移出的補充資訊

T08-201 原始完整技術稿已經確認 `4AF530 → 0x2C P allocation → 4DFFB0`、owner 主樹與次級 P 樹分離，及 CMonster vtable+0x14 → `4D1F80 → 4C8360`。因此原 T08-202 的 `index8 new P` 寫入和插樹鏈不是首次發現，應標為 **「T08-201 已證，T08-202 重驗」**。

T08-202 後續真正新增的有界補證包括：同key `0x4AF6F1..0x4AF781` refresh 不覆寫 P+4/P+8、命令26和81的不同Actor/Controller清理路徑、四種0007 Actor RTTI型別的虛擬清理、六種Controller析構都能回到 `0x544E80` H-tree cleanup、以及Scene::CDuelDecision的 P+4 讀取鏈。完整證據已在其他獨立 GitHub 技術稿保存，無需修改SRC-0589凍結原文。

- 相關補證：`20261031-044016-chatgpt-web-roy-T08-202-four-native-Actor-RTTI-virtual-cleanup-and-Controller-H-tree-destructor-evidence.md`；Git blob `b9f89e4ecd069752c18a99142e5eb392000987e2`。
- 本地完成研究仍須區分 **T08-202有界Client靜態研究已交**、**T01來源FULL-PASS未審完**、**Server實作/玩測未驗**。

## 防止再犯的交付規範

任何 `research/intake/index.json` 已登錄 `source_file + source_blob_sha + source_sha256` 的來源，都應視為**不可原地修改的凍結證據**。發現補證、勘誤、錯字或新解釋，請另建 `-addendum.md`／`-corrected-source-vN.md`，讓新文件有自己的不可變 Git blob SHA，再由T01依正式收件程序新登錄；**不可只更新CI記錄的hash來掩蓋原來源遭修改**。README可引用新的補充稿，但不能讓原登錄來源和實際文件內容脫鉤。

## CI查核

- GitHub Actions流程：`S00 specification registry integrity`，失敗工作在 `Validate S00 registry and source identity`，日誌確定失敗項為 `SRC-0589`。
- main 2026-10-31 16:32觀察的最新工作流程 `41185000160` 顯示 success；T08工作分支的提交 `d907011bc6f559309c010fac3b036114df61cc34` 流程 `41127979541` 顯示 failure。修復後須檢查**新T08 HEAD**真正觸發的新流程及全部步驟，不能用main先前success或GitHub上傳成功代替T08新CI通過。
