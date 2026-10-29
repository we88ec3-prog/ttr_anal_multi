# T01 2026-10-29 原稿語意驗收：階段整合

使用者要求接續逐篇原生語意驗收，之後明確要求階段性收尾，再指示繼續整合本批成果。操作者：Codex T01 integrator 與三個經使用者授權的子代理。凍結遠端基準：`a4d58fd21dd40cfd5cc645a829e52e59b23cecaa`；獨立工作分支 `codex/t01-integration-20261029-07`。

## 真實進度

本批**不是318篇原稿全文驗收完成**。全文 FULL-PASS 為 **0**；69個原稿版本已有明確反證，但不代表每個其餘主張均已審完。逐篇來源與剩餘工作見 [source-ledger.json](source-ledger.json)。

| 原稿版本狀態 | 數量 | 意義 |
|---|---:|---|
| FAILED | 69 | 已確認至少一項原件／主張反證；原版不得全文通過，須另立修正版複驗 |
| PARTIAL | 153 | 有限定主張或局部證據，全部肯定主張與碼塊尚未逐項驗完 |
| SOURCE_ONLY | 9 | 來源／候選位元組等級，沒有提升原生語意 |
| PENDING | 87 | 尚未完成逐篇語意矩陣；前置機械核對或讀取紀錄不等驗收 |
| 合計 | 318 | T08 123、T10 98、T16 97個精確來源版本 |

- [T08早期裁決](t08-early/actor-reviews.json)：153/155/157退回；158/159只接受列明的限定主張，沒有全文升級。[24個映射錯誤來源](t08-early/mapping-reviews.json)獨立保留原稿SHA；[1263條逐點對照](t08-early/mapping-findings.json)證明18篇的指定機器碼在其標籤VA減0x400後相符，不能全域平移資料節或絕對函式指標。
- [T08後期](t08-new/README.md)：31篇有125條列明主張，27篇具有有界支持、4篇原稿反證；原稿全文通過0。54個有效入口CFG、5401條來源bytes及IAT／表值核對已保存。
- [T10](t10/DECISIONS.md)：98篇，4篇原稿反證、94篇PARTIAL；11個來源內14條限定主張通過，全文通過0。保存13689條bytes核對、47份CFG、40個重現錨點及每篇待簽核碼塊行號／SHA。
- [T16](t16/README.md)：72篇有局部裁決（33反證、30限定支持、9來源級）、25篇未定稿；97篇全文仍未完成。T16-92的確證座標反證由整合者另行裁決原版FAILED，其餘92主張仍待審，因此總台帳與子審核原始檢查點數量不同。保存35項更正提案、14份資源獨立carrier重解、Lua靜態解析及完整相關CFG。

## 正式准入及更正

只有主整合者另行核對、條件完整的三項精確結論准入 [共用原生知識](../../verified-knowledge/client-receiver-exact-lookup-erase-iterator.md)：lazy receiver正常返回、exact-key-or-head查找、erase先求successor再釋放原節點並回傳iterator。它們不依Task分類，也不提升來源全文。其他子代理局部支持保留於本批矩陣，未自動全部准入正式知識。

歷史T01-20261028-12的N8漏看 `0x82EF41/44` 等值閘門，已在新條目更正並保留原報告。新Ghidra `analyze_function(7B6890)` 在300秒逾時，沒有接受任何新Ghidra結果；使用既存cache Evidence、原件獨立PE／bytes與Capstone根CFG核對，沒有重做全量反編譯。

46筆具體退回及1個既有映射群組已按固定ID寫入T08／T10／T16 README的退回專區；既有157/173/187/196原位補充，沒有重建同ID通知。[return-notices.json](return-notices.json)保存來源blob、SHA、反證、修正及複驗條件。映射群組由歷史BLOCKED改為NEEDS_FIX，因本輪已可獨立證明來源座標錯誤；沒有將其誤標RESOLVED。未發Issue、未傳訊至其他聊天。

## 保存與驗證

原E:分析成果未覆蓋／pull／清理。[本地來源比對](local-source-check.json)確認7480檔、524796506 bytes與第06批逐檔SHA相同，新增差異0。可恢復快照留在 `E:/Tartaros/workspace/t01-work-20261029/local-snapshot.zip`，SHA256 `8d909d79f861baf12dfae9385791a28f8bb6fe05352f264a4afe2ddddac5fa7c`，不含.git；快照不提交。

[validation.json](validation.json)保存實際校驗結果；[files-manifest.json](files-manifest.json)保存交付檔案SHA。[support/audit.py](support/audit.py)和凍結來源queue已封裝，T10/T16不再依賴私有工作helper。重現原生證據仍需另外提供指定SHA原BIN、Capstone5.0.6；資源重解需指定SHA的KR/TC carriers。這不是完整分析引擎或無原件的語意驗證包。

PowerShell重現例（在倉庫根目錄；不執行目標／Lua）：

```powershell
$env:T01_TARGET='E:/Tartaros/workspace/Tartaros.bin'
$env:T01_CAPSTONE_ROOT='E:/Tartaros/workspace/t01-work-20261029/vendor'
python -X utf8 -B shared/integrations/T01-20261029-semantic-review/t10/verify_semantics.py
python -X utf8 -B shared/integrations/T01-20261029-semantic-review/t08-new/validate.py
python -X utf8 -B shared/integrations/T01-20261029-semantic-review/t16/resources.py
python -X utf8 -B shared/integrations/T01-20261029-semantic-review/validate_phase.py
python -X utf8 -B shared/handoff.py verify
```

原件、原anal、遊戲資源／帳號／存檔唯讀；無遊戲啟動／附加、目標API、伺服器部署或客戶端修改。驗證通過只表示記錄與列明機械檢查相符，不表示318篇、全部CFG語意、Server規則或遊戲可玩。下一步見 [NEXT-STEPS.md](NEXT-STEPS.md)，實際推送基準見 [push-receipt.json](push-receipt.json)。
