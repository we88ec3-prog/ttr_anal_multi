# MEF 能力分析公開發布說明

使用者已明確同意將本輪與前輪待推送的 MEF 完整分析及節錄證據，公開推送到 `we88ec3-prog/ttr_anal_multi` 的既有 **`extra/roy1`**，不包含原始 BIN、STP 或完整解包資源。沿用本次授權完成研究與推送，不另建分支、不 force push、不改 main。

本輪依最新指示聚焦 `.mef`／相容事件內容能編排的功能與使用條件，並將 Server 尚待實作的內容流程、交易、同步與保存列為 Server 開發需求。普通戰鬥完全取代 Server 不作為研究完成標準。

前輪 R10 已公開，沒有遺留待推送的 R10 成果。直接父提交為 `af97bbd29c892e031eef7a3bc3a98cb79f1be729`，tree 為 `44477e41924e45cf16f9eef28066e787a5abc54b`。main 基準 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已是其祖先；來源 pins 不依賴未公開的研究提交。

本輪完整提交範圍為：

- `kr-extra-roy/20261116-113220-chatgpt-web-roy1-MEF-capabilities.md`
- `kr-extra-roy/MEF-capabilities-20261116/` 內的能力目錄、helper 導覽、四組分題、節錄、機讀契約、來源、開發交接及核對結果。

完整 allowlist 由 `artifact-manifest.json` 列出。Native 只含支持結論的 bounded instruction／data／RTTI／string windows；Lua 只含必要 prototype／operands 或 export metadata；Table 只含選定 member 身分、必要鍵與統計。沒有放入原 BIN／EXE／STP、完整解包資源、完整原始 Lua／SEQ member 或新可部署的 `.lua`／`.seq`／`.mef`。

發布透過已授權 GitHub 連線建立與本機 staged tree 相同的 Git tree／commit，以真實公開父 SHA、`force=false` 和 expected-head lease 更新 `extra/roy1`。ref 移動前再次讀取 main／branch，遇到其他更新先同步整合，不覆寫他人工作。認證資料不寫入或輸出。

提交本身不填入尚未存在的自我 SHA。更新後實際讀回 commit／tree／ref、取得公開 Git objects，逐檔核對本輪內容，才將本機分支對齊同一公開提交。正式 RR／REQ／Task owner 與驗收狀態維持原狀。
