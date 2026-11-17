# MEF 本輪公開發布說明

使用者已明確同意將本輪與前輪待推送的MEF完整分析及節錄證據，公開推送到 `we88ec3-prog/ttr_anal_multi` 的既有 **`extra/roy1`**，不含原始BIN、STP或完整解包資源。本輪沿用該授權，不另建分支、不force push、不改main。

前輪R8、main merge與R9已完成公開；本輪parent直接使用真實公開R9 `ad9ea950216923b5e351a7501d38e006df57a4c6`。main仍為`03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`且已是其祖先。舊本機C0／B0與未公開R9 SHA只存在前輪的歷史對照，本輪來源pin不依賴那些舊本機提交。

本輪提交範圍為：

- `kr-extra-roy/20261116-092138-chatgpt-web-roy1-MEF-control-flow.md`
- `kr-extra-roy/MEF-control-flow-20261116/`內完整分題、節錄原件、固定來源、設計／開發契約及唯讀驗證工具。

節錄包含有界native函式／指令窗口、必要資料表／字串／RTTI、選定Lua prototype operands，不包含原BIN／EXE／STP、完整解包資源或新可部署遊戲內容。既有Coroutine原件以已公開blob pin復用，本輪沒有新增完整member。

發布透過已授權GitHub連線建立同一Git tree與commit，使用既有branch、預期parentSHA及`force=false`更新ref；沒有儲存或輸出認證資料。實際commitSHA於ref更新後讀回核對，提交本身不寫入尚未存在的自我SHA。若遠端head移動，須先同步新head再整合，不能覆寫別人的更新。

完成後核對remote commit／tree、實際檔案bytes與branchref，並讓local `extra/roy1`指向相同公開commit。正式RR／REQ／Task owner與驗收狀態維持原狀；本輪只是研究與開發交接發布。
