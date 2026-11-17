# 驗證、重跑與結果界線

所有工具只讀原 BIN／STP／ZIP及固定Git來源，不執行Client、Lua或Server。Python使用標準函式庫；native verifier需GNU `objdump`。本輪實際工具版本保存在 [source-manifest.json](source-manifest.json)。原檔不隨研究包發布，須使用相同SHA的唯讀來源。

## 1. 本輪有不同的驗證層

| 層次 | 實際驗什麼 | 不能推出什麼 |
|---|---|---|
| 原件身份與證據 | 整檔SHA、PE raw mapping、指令邊界、指定call／writer／資料表、固定Git blob | 全程式形式驗證、所有native副作用、所有動態caller |
| 跨包一致性 | 121名稱／native／參數與15域導航，16query集合，來源與manifest，Markdown連結 | 121獨立玩法均已開發、官方MEF格式完成 |
| 內容工具與SYN模型 | 錯誤型別／arity／回值、lexer反例、圖片取消／模型引用／交接的已證語義 | 原遊戲執行、畫面成功、Server已提交、T01 FULL-PASS |
| 資源分析 | 原包index、文字SEQ literal、選定descriptor／表格／ZIP成員及轉依賴 | 實際安裝版本與mount、每個分支可達、缺件必然造成崩潰 |
| 遊玩 | 本輪未執行 | 不填新的Client／Server正常流程通過記錄 |

各子題窗口有重疊，數量不能相加換算整體覆蓋。`verification-result.json`是執行結果，不以修改預期的方式把缺資源變成PASS_READY。

## 2. 整包檢查

在本目錄執行：

```bash
python -B verify_package.py --repo /path/to/ttr_anal_multi
```

預設核對本包manifest、所有JSON與Python語法、文件連結、來源pin、跨表集合及已保存分題收據。它明示是否在這一次呼叫重跑原件；僅核保存的收據不冒稱本次已重跑原件。

若要重新執行六個分題原件verifier及一個ABI工具fixture runner，另提供原件與補充資料目錄：

```bash
python -B verify_package.py \
  --repo /path/to/ttr_anal_multi \
  --run-evidence \
  --sources /path/to/project_sources \
  --supplemental /path/to/supplemental_resources/ttr
```

`project_sources`的檔名對應本次提供的 `02-Tartaros.bin`、`06-Event.stp`、`07-Table.stp`、`10-BoundMap.stp`及 `09-02-PROJECT-SHARED-INSTRUCTIONS.md`；補充目錄含 `Base.stp`和 `Tartaros-Web-AI-W1-W2-W3-input.zip`。不要用另一版本同名檔強行通過hash gate。完整命令與各自必要參數亦保留在分題報告。

## 3. 個別工具

### ABI與內容呼叫預驗

```bash
python -B abi/verify_evidence.py --bin /path/to/Tartaros.bin
python -B abi/validate_calls.py /path/to/call-plan.json
python -B abi/check_validation.py
```

`call-plan.json`是本工具自訂的 **NOT_NATIVE_MEF** 分析輸入，並非原遊戲檔案。成功只給 `ABI_PASS_ONLY`；typed ID、資源、owner、合法入口與業務條件仍需下一層。14個SYN案例檢查的是已證ABI陷阱，不是原Client互通測試。

### 事件、圖片／重用與模型恢復

```bash
python -B events/verify_evidence.py --bin /path/to/Tartaros.bin --repo /path/to/ttr_anal_multi
python -B reuse/verify_evidence.py --bin /path/to/Tartaros.bin --event /path/to/Event.stp --repo /path/to/ttr_anal_multi
```

追加模型鏈使用 [reuse-followup](reuse-followup/report.md) 的命令；它必須與更新後的reuse報告一起閱讀。舊layer-only模型不能推算存活doll的總引用；舊FlyingObject不取消前圖的模型已由 [errata](reuse/errata.json)撤銷。

### 模型ID與實際描述檔選擇

```bash
python -B resource-selection/verify_evidence.py \
  --sources /path/to/project_sources \
  --supplemental /path/to/supplemental_resources/ttr \
  --repo /path/to/ttr_anal_multi
```

此分題重讀ActorList與Base，核對ID／FILE／basename與CHA_ABF索引鏈。PRE不參與這條模型key已閉合；實際cache／directory／mount未取得，完整runtime路徑仍為null。這個預期未知不應被改成部署成功。

### 資源預驗

```bash
python -B resources/resource_audit.py \
  --sources /path/to/project_sources \
  --repo /path/to/ttr_anal_multi \
  --supplemental /path/to/supplemental_resources/ttr \
  --output-dir /tmp/mef-resource-audit \
  --require-ready
```

本讀集預期退出 **2**，仍會保存完整分析；它表示依賴尚未齊全。對應 `resources/verify_evidence.py` 會驗證五份重算JSON、來源與這個拒絕行為，研究重現可PASS但ready仍false。Base／ZIP已補到descriptor及動作宣告，未到的mesh／texture／audio／effect payload不因重新執行而變成存在。

## 4. 歷史驗證器的已知版本問題

舊 `MEF-full-surface-native-continuation-20261116/audit.py` 使用的parser SHA pin與基準Git實存parser不同。本輪重新審讀並固定現存parser SHA `8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56` 後，用其data-only reader核原Event。這不是把舊總包改成通過；本輪沒有聲稱歷史aggregate verifier重新PASS。

舊ASM仍是原件可核的證據，指定解讀／SYN預期的勘誤另列。新增來源與模型修正應以完整上下游證據判定，不能因歷史測試PASS就拒絕原件反證，也不能因一處舊pin不符就把其他已核結果全部歸零。

## 5. 發布核對

發布僅包括本新目錄的分析、必要原件片段、來源摘要與工具。提交前檢查目標branch與當前remote SHA，不force push、不新增branch；推送後讀回remote HEAD及本目錄tree。實際Git提交與remote結果由對話回報，避免在被hash的檔案中填入尚未產生的self commit SHA。
