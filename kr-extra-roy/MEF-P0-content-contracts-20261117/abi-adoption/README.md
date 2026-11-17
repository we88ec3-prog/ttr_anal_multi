# P0：ABI 與勘誤採用契約

本題已完成上一批 P0「採用勘誤與 ABI」的有界靜態分析及內容工具交接：完整納入 **121 正常綁定、33 種 marshaller、17 個新 number producer、104 個不建立新值的綁定、16 個本地觀察 query、四個 stub 與一個不提供 count 的名稱**；對既有全部採用勘誤建立索引，並分開新作者政策與原 SEQ 相容審閱。原生來源、Git 來源與每項機讀產物均有固定身分；未修改原檔、既有研究、正式 T01／RR／S00 狀態或 Server 產品程式。

**這是研究 sidecar，格式明示 `NOT_NATIVE_MEF`。** 預驗器只讀 JSON，不執行 Lua、原 Client 或 Server；其 PASS 不代表原生 MEF 格式、實作完成、實際選到資源、執行成功或可玩。本題也不直接擴充既有 Server JSON schema。

## 閱讀入口

| 檔案 | 用途 |
|---|---|
| [report.md](report.md) | 完整採用理由、原件反例、VM 證鏈、限制與 Server 交接 |
| [ADOPTION-INDEX.md](ADOPTION-INDEX.md)／[adoption-catalog.json](adoption-catalog.json) | 全121項逐列索引、原生 ABI、功能限制、query來源 |
| [adoption-rules.json](adoption-rules.json) | 18組規則、原生／政策分類、逐規則預期結果與案例 |
| [errata-adoption.json](errata-adoption.json) | 前輪全部15個勘誤項及三個 followup 項的去重採用 |
| [preflight.py](preflight.py) | 嚴格的 normal-binding 作者計畫預驗器；固定來源、版本、欄位、型別與結果用途 |
| [original-call-review.json](original-call-review.json) | Q119/3、Q2440/5 原 SEQ 全部呼叫層級／arity／原符號條件；不改寫原文 |
| [helper-call-audit.json](helper-call-audit.json) | 原 qbase 全75 helper 的有界 CFG reaching-definition 審核與 opcode 覆蓋 |
| [helper-bridge-evidence.json](helper-bridge-evidence.json)／[helper-adoption-rules.json](helper-adoption-rules.json) | 原 helper 的精確字碼、型別轉換與反例 |
| [bootstrap-global-contract.json](bootstrap-global-contract.json) | 已保存 KR Boot／Logic／Coroutine 的精確 Git 原件、source-map身分與初始 TRUE/FALSE數值證據 |
| [zeroarg-endsepia-contract.json](zeroarg-endsepia-contract.json) | 原 RevPhase1 零參數 EndSepia 的限定相容證明；不放寬新作者 arity |
| [native-evidence.json](native-evidence.json)／[native-evidence.asm](native-evidence.asm) | 本輪補閉 VM stack 成長、allocator端點、EndSepia 的9個原BIN窗口 |
| [source-manifest.json](source-manifest.json) | 原BIN／Event身分與精確來源 commit、Git blob、SHA256、bytes |
| [fixtures.json](fixtures.json)／[fixture-results.json](fixture-results.json) | SYN作者反例、資料流反例及實際結果，與原生證據分開 |
| [verify_evidence.py](verify_evidence.py)／[verification-result.json](verification-result.json) | 可重跑驗證器及本輪實際執行收據 |

## 重跑

在 repository 根目錄，以可取得兩份原件的資料夾執行；只讀原件並執行資料解析／比對工具：

```bash
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/verify_evidence.py \
  --sources /path/to/project_sources \
  --result kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/verification-result.json
```

`project_sources` 需有固定 SHA 的 `02-Tartaros.bin` 與 `06-Event.stp`。Boot／Logic／Coroutine 從原已保存的固定 Git blob 讀取，不要求新上傳原檔。Python標準函式庫、`git`、`objdump` 是工具依賴；不啟動遊戲或 Lua runtime。來源與產物任一 hash／形狀／案例不符即失敗，不改來源。退出0只表示這份有界研究產物可重現。

單獨審閱新作者計畫：

```bash
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/preflight.py /path/to/research-plan.json
```

輸入格式見 `fixtures.json` 的每個 `plan`；這些計畫只供研究工具，不是官方 MEF、網路封包或可直接部署的 Server 定義。不得將合成案例重命名成原遊戲資源。

## 驗收與接續

本題靜態採用／交接目標已閉合。Server 要將型別化識別、原件版本、入口／pump、預載與正式執行一致性、owner／退出契約與內容功能需求接入現有流程；沿包根 [SERVER-ADOPTION.md](../SERVER-ADOPTION.md) 的既有 **REQ-0019／REQ-0021** 接收，屬 **Server 待開發**。一般世界事件、任意 lookup owner、全資源 coverage 與實際遊玩結果不由 ABI 工具推導。完整資源與收尾採用分別見本批 `content-dependencies` 與 `execution-lifecycle`；跨題身分固定由包根統一處理。
