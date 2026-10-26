# T01-20261026-01 成果來源審核與整合批次

日期：2026-10-26（Asia/Taipei）。操作者：Codex T01 integrator。目標：`origin/main`，遠端 `https://github.com/we88ec3-prog/ttr_anal_multi.git`。獨立整合分支：`codex/t01-integration-20261026-01`。

遠端來源基準：`789784c9fa256d849d06eed417603d5ec208cb0b` 的完整 SHA 見 [checkpoint.json](checkpoint.json) 的 `remote_base`。本地來源基準：`08a08599c4dac2febab869523780cabf39806b69`，工作分支 `codex/kr-t06-roy`。未在來源工作區 pull、切分支或清理；原 anal 保持唯讀。

本批次接續基準是**引入本目錄的提交**；以 `git log --diff-filter=A --format=%H -- shared/integrations/T01-20261026-01/README.md` 取得完整提交 SHA，確認 `origin/main` 包含它後再接續。實際推送收據另保存於本輪操作者輸出；文件不以自我引用方式預填尚未產生的 commit SHA。

## 本輪結果

本地 roy 的 T02／T03／T06 共 290 個 SHA 證據版本通過有限來源審核，增量納入 `kr/evidence/<SHA>.txt`、`shared/catalog.json`、SQLite 與來源映射；沒有移除舊 artifact、claim 或 correction。42 筆新增結論、2 筆更正，96 筆方法登記與 5 筆既有方法 metadata 更新；登記不表示語意已完成，既有方法主責未改派。TC 保留背景／缺口狀態，未套用 KR 位址。

本地清單、來源任務／分析者、接受 SHA、當前暫存 SHA 及每項正式位置見 [local-items.json](local-items.json)。T02 16 份、T03 96 份、T06 178 份。若同一暫存路徑有數個版本，以正式 artifact SHA 區分；只有 `current_staging_equals_accepted=true` 才表示目前該暫存版本亦已整合。`changes.json` 是分析者凍結來源紀錄，不能將其舊 catalog_after_sha256 當成本輪結果 SHA。

分類保留來源的成立條件：新增結論中原生已確認 11、部分確認 21、AI 替代 5、資訊缺失 3、待補充開發 1、使用者記憶待原生核對 1。原生標記僅對來源限定的靜態指令／介面成立；T01 未重新展開功能分析，沒有 runtime／可玩驗收。

遠端新增 15 份報告均保留原暫存區，逐份 SHA／分析者／任務與處置見 [remote-review.json](remote-review.json)。報告內自稱機器碼確認不等於本輪可獨立重放證據；新增原生主張仍待原始 bytes／指令與歸屬核對，不因已在 main 就自動轉正式。

## 更正、去重與衝突

[resolutions.json](resolutions.json) 記錄逐項依據與後續需求：

- 807B40 checksum 不符：保留 skip-copy→共用 record 路徑；pool 初始值未閉合，不能無條件宣稱完整丟棄。
- 非零 A02C：保留 807830 失敗 fallback 到 807A70；遠端 805D02 初始化值是待補原始證據的線索，不能消除間接 writer／時序缺口。
- 同 Map selector：遠端與本地局部觀察相容，去重採已封裝的完整局部指令／CFG 依據；4DFA13 是分支落點，返回點為 4DFA9A，不推成功重載。與 7C1E00 同檔名的旗標分支是不同問題。
- Town1/2→Map182/183 未直接證實；unsigned manifest 一致只能建立有限關聯，不能推發行者真實性或完整 build 配對。
- T03 body AddressSet 與外包範圍、T06 selector DWORD 與反編譯 float 解讀的更正，見 catalog 新增 C-T03-roy-parser-body／C-T06-roy-map-selector-float。

查出 101 份既有 evidence 在 Git checkout 後與登記 SHA 不符；從凍結副本恢復與既有 SHA 完全相符的 bytes，未改舊結論。逐筆前後 SHA 見 [byte-preservation-repairs.json](byte-preservation-repairs.json)。新增 `.gitattributes` 固定證據原始 bytes，避免 newline conversion 再次破壞 SHA。這是來源完整性修正。

## 未整合與保存

[pending.json](pending.json) 列明任務既有缺口、暫存內容漂移及未接受項目。IP／翻譯 client 副本、封包恢復契約、未驗證資源 consumer、完整 ABI／重試／ready／官方後端規則仍未驗收，不提交整份分析歷史或遊戲副本。必要跨任務文件若作導覽背景攜入，只以 [context-only.json](context-only.json) 標示，不提升為原生結論。

[frozen-inventory.json.gz](frozen-inventory.json.gz) 保存 119,699 個本地檔案的路徑、SHA、大小、未提交狀態與本輪處置；其中未接受項目留原位置。來源工作區尚未提交的正式修改可能已按本批 SHA 整合，接手者不可單憑 git status 重複提交。盤點後的新內容不屬本輪；見 post-freeze-changes.json。

可恢復備份位置、凍結時間與備份驗證見 [freeze-summary.json](freeze-summary.json)。備份不含 `.git`；118,021 份 bulk cache 用獨立可恢復 ZIP 保存。倉庫只新增被明確引用的少量父批次，不上傳整份 cache；見 [supporting-dependencies.json](supporting-dependencies.json)。來源檔與正式副本 SHA 相同者去重以 artifact SHA 識別。

## 驗證與接續

驗證結果見 [validation.json](validation.json)。重跑 `python shared/handoff.py verify` 及 `python shared/integrations/T01-20261026-01/validate_batch.py`。檢查 artifact SHA、JSON／SQLite 全筆一致、task.json、方法主責、必要來源映射、正式導覽連結，以及隔離匯出／查詢。569 筆歷史引用未閉合，native_complete=false；驗證通過不消除這些限制。

T02 接續 pool/copy、2633、A02C writer 及實際切線；T03 接續 UI 事件投遞／訂閱、F42EF、官方資料與初始化鏈；T06 接續資源 consumer／掛載與兩村配對；T07 依場景 reset／ready 介面查證，T08／T09 先取遠端暫存報告的原始證據再提審。各項只引用共用主責，不擴張重做分析。

T01 本批來源審核完成不代表整項 T01 或任一功能任務完成；持續保留未知項及待開發分類。全程未執行／附加遊戲、呼叫目標 API，亦未改原執行檔、資源、帳號或存檔。交接僅透過文件；沒有向其他對話發送訊息。

遠端 15 份報告亦依捕獲時的 bytes 固定保存，沒有改動語意文字；見 remote-byte-preservation.json，避免套用新屬性後再次 checkout 造成報告 SHA 漂移。
