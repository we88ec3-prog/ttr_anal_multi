# P0：資源選取 cache/index 續接

**已完成現有原件可證的選取政策；實際 `CHA_ABF`／`MAP_FLD` winner 與 payload 仍受阻。**

主稿：[report.md](report.md)。精確狀態與缺件：[contracts.json](contracts.json)。實跑結果：[verification-result.json](verification-result.json)。

本輪固定 `fcs.flu` reader 的完整佈局、開檔與有效覆蓋的區別、group definition 首筆規則、十組無 cache 預設值、filesystem parent-first 遞迴、一般 lookup 與 `MAP_PTC` stack-local 補掃例外。Master 掛載、basename first-wins、Actor.ID last-write、EMF／ETF 舊證直接復用，沒有重算完成數。

## 驗證

從 repository root：

```bash
python -B kr-extra-roy/MEF-P0-P1-P2-continuation-20261118/p0-selection/verify_evidence.py
```

`--binary` 與 `--repo` 可覆寫絕對位置；BIN SHA 必須相符。工具僅讀取原件、固定 Git blobs 和分析成果，將結果印到 stdout；不執行 Client/Lua/Server/DLL，也不寫原件。

## 有真實 cache 後的只讀查詢

```bash
python -B kr-extra-roy/MEF-P0-P1-P2-continuation-20261118/p0-selection/cache_inspect.py /path/to/fcs.flu --query CHA_ABF 02_Stoncken.abf
```

此命令是後續用法，本輪未取得 actual cache。嚴格 ASCII profile／NUL／長度條件屬分析工具政策；輸出只稱 candidate，`native_selected_path` 維持 `null`。20 個記憶體內合成測例不能替代真實檔案或 native 遊玩。

## 檔案

| 檔案 | 用途 |
|---|---|
| [contracts.json](contracts.json) | layout、群組、順序、狀態、缺件與 Server 交接 |
| [native-evidence.json](native-evidence.json)／[native-evidence.asm](native-evidence.asm) | 完整有界原生視窗、舊視窗引用、literal 與 import 身份 |
| [source-manifest.json](source-manifest.json) | 原 BIN、21 個 immutable Git source pins |
| [source-availability.json](source-availability.json) | 指定原件目錄／ZIP 未見 cache 的有限範圍 |
| [caller-census.json](caller-census.json) | 19 個經解碼 direct-call 候選；不當全程式 absence proof |
| [cache_inspect.py](cache_inspect.py) | 僅讀本地 cache bytes 的嚴格 profile 查詢器 |
| [verify_evidence.py](verify_evidence.py)／[evidence_io.py](evidence_io.py) | 原件與契約 replay |
| [artifact-manifest.json](artifact-manifest.json) | 本子包成果 hashes；receipt 和自身不形成循環 |
| [verification-result.json](verification-result.json) | 實際只讀執行結果與未升級旗標 |

`full_p0_ready=false`、`resource_payload_ready=false`、`t01_full_pass=false`、`playable_verified=false`。
