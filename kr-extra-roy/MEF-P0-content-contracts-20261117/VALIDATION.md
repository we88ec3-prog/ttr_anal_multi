# 驗證方法、實際結果與邊界

## 1. 這份 PASS 驗什麼

本包驗證器處理原件與研究資料，**不執行原 Client、Lua、Server 或遊戲資源**。它驗證固定 Git 來源、原 BIN／STP／ZIP 身份、有界原生 bytes 與指令、原資料解析、分析器衍生物、作者政策、owner／清理模型及目前 Server JSON 對照。

根收據：[verification-result.json](verification-result.json)。四份子收據：[ABI](abi-adoption/verification-result.json)、[資源](content-dependencies/verification-result.json)、[生命期](execution-lifecycle/verification-result.json)、[Server 對照](integration/verification-result.json)。各子題的 manifest／驗證器說明精確方法及限制；來源相符不等於全文語意、整個函式或全引擎已被獨立認證。

## 2. 完整重跑

需要 Python 3.10+、GNU objdump、Git、本 repository 的固定歷史 objects、原始材料與補充材料。檔案位置可替換，原 bytes／SHA 不可替換。

```bash
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/verify_package.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --supplemental /absolute/path/supplemental_resources/ttr \
  --run-evidence \
  --result /absolute/path/ttr_anal_multi/kr-extra-roy/MEF-P0-content-contracts-20261117/verification-result.json
```

`--sources` 應包含精確的 `02-Tartaros.bin`、`06-Event.stp`、`07-Table.stp`、`10-BoundMap.stp`、`09-02-PROJECT-SHARED-INSTRUCTIONS.md`。補充目錄應包含 `Base.stp` 及 `Tartaros-Web-AI-W1-W2-W3-input.zip`。Boot／Logic／Coroutine 原 bytes 從固定 Git 證據取用，不要求重新上傳。

不指定 `--result` 時只輸出 JSON。不指定 `--run-evidence` 時仍檢查包內檔案、來源、語法、文件目標、P0 狀態、跨題契約與已保存收據，但結果明示 `evidence_rerun_this_invocation=false`，不能宣稱這次已重新驗原件。正式交付收據使用完整重跑。

## 3. 四項必跑的證據工具

| 子題 | 真正驗證內容 | 成功欄位與保留狀態 |
|---|---|---|
| ABI | 舊 121 binding 證據重跑、原 helper／SEQ／Boot 再生、零參數特例、新作者政策與保守名稱資料流 | `PASS_REPRODUCIBLE_BOUNDED_RESEARCH`；部署／遊玩／Client／Lua／Server 執行皆 false |
| 資源 | 六份原件、固定來源、所選完整函式／member、原生選檔窗口、三份圖表重建 | `PASS_REPRODUCIBLE_BOUNDED_ANALYSIS`；exact selection 仍 BLOCKED，完整遞迴 payload 與 ready 仍 false |
| 生命期 | 原生新／復用窗口、call／data 錨點、qbase／Boot／兩 SEQ、22 owner／清理 DAG／三策略／有限 SYN | `all_matched=true`；沒有全佇列 drain、部署或遊玩證明 |
| Server 對照 | 目前 main 四份精確 JSON、Q119 四節點與 scene 階段、外部 schema、既有兩需求狀態 | `PASS`；純資料對照，沒有 Server 執行或正式狀態變更 |

[evidence-runs.json](evidence-runs.json) 保存命令模板及收據；根驗證器固定四組名稱、目錄、命令、收據與成功／邊界欄位。缺少其中一項、重複、空清單或弱化 success check 都不能得到完整重跑 PASS。執行後四個新 JSON 必須逐項等於保存收據，且再核 artifact manifest 確認工具沒有修改交付內容。

## 4. 跨題與來源檢查

根 [verify_package.py](verify_package.py) 另核：

- 121 個 adopted rows 與已發布 ABI 的關鍵欄位逐項相符，stub 與無 count producer 仍明列。
- 三個子題使用同兩個 original selector 與相同 SEQ member hash；兩解析器的 108 次 body call 順序、行號、名稱、arity 完全一致。
- Boot number0 經 Create helper 數值比較變 number1，再走 integer32，不誤混 Lua truthiness。
- lifecycle 的 selected statement 均來自同一原 SEQ；22 owner／三策略完整，沒有把兩個不相干原場景當作兩段 pair。
- 3,187 筆既有 source-map 的指定資源模式有界查詢可重算，三份找回的原 Lua bytes 可核 SHA。遠端檔案標題搜尋只保存觀察紀錄，驗證器不假裝重新查了一次。
- P0 的每項完成條件都有明確狀態、證據與邊界；全部 release gate 與正式狀態提升旗標保持 false。
- 包內檔案種類、實際 SHA／長度、strict JSON、Python 語法及 Markdown 相對目標存在性。

Python 工具以 `-B` 運行且停用 bytecode 寫入；需要使用既有 assertions 的工具拒絕 `-O`。原件身份驗證失敗直接停止，不以較寬鬆 parser 或猜測 source 取代。寫出結果的選項只能覆寫指定收據或合法的獨立輸出，不可覆寫原件／其他 repo 檔。

## 5. 審查時修正的具體問題

| 問題 | 最後採用的修正 |
|---|---|
| 原 EndSepia 零參數只停在 arity mismatch | 追 VM CALL、C frame、stack relocation、marshaller 到 native integer0；保留新內容嚴格 arity |
| Q2440 的 fade-out0 只有「原件存在」描述 | 追到 phase4 先行 JLE 跳過除法，phase0／alive0／manager 釋放分列 |
| 一般 deferred model 風險誤套正常 Q.Create | 固定實際 immediate1 caller，generic pending 按 producer 限定 |
| helper callee 僅按來源次序推定 | 控制流 reaching-def 合併，conflict／kill 回 UNKNOWN；含實質分支反例 |
| 已解析的 talk_text 因沒有 path 被誤列缺檔 | 綁其真正 active table member，保留文字已解析與全域 runtime 選取不同層 |
| Create 第7參數被口頭混稱 truthiness | 以 Boot number0／helper numeric comparison／native integer32 三段交叉核對 |
| aggregate 空集合或漏子題仍可能算完整重跑 | 固定四套命令及成功／限制欄位；空、缺一、重複集合拒絕 |
| 研究工具輸出選項可能覆寫其他來源 | 限定輸出目的地並保護原件／repo 檔案 |

SYN 案例只驗分析器或明列研究模型的預期性質，不是遊戲 runtime、Server 故障、網路重送或實際玩家旅程測試。

## 6. 不由 PASS 決定的事

資源子題另有 `--require-ready`；即使資料重現成功，只要現有原件缺口保留，它回 exit 2。本包的根 PASS 必須能同時保留這個結果。真正原始 carrier 選中、payload 語意接受、畫面／聲音、輸入恢復、業務結果與遊玩各有不同證據，不用工具案例數換算完成百分比。

Git 發布只保存這份研究；不代表 T01 FULL-PASS、RR SUBMITTED／ACCEPTED、S00 接受、Server 實作或正式可玩。依使用者指示，Server 要自行提供的政策與工程列在 [SERVER-ADOPTION.md](SERVER-ADOPTION.md)，其餘原件／Client 證據界線保留。
