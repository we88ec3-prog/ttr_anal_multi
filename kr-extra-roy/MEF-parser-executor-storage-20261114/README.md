# MEF parser／executor／storage 原件證據

本資料夾支援 [主報告](../20261114-190624-chatgpt-web-roy1-MEF-parser-executor-storage.md)，接續已發布的 Server 可傳遞時窗分析。既有工作分支 `extra/roy1`；只發布研究文件、原件有界摘錄與唯讀重驗工具。未執行、附加或修改 Client／Lua／原始資源。

## 主要結論

1. `FB74C0` 儲存 map ID 對應的 trigger **名稱字串**，不是已證 MEF file bytes；相關全域位於零初始化虛擬尾段。
2. 有可達的 Lua text／5.1 binary parser、protected execution、opcode VM。新補全域 `DoFile → 6F48A0` 的註冊；無 direct caller 不能推論不可達。
3. 原生 MEF 文法／名稱到 consumer 尚未接通。副檔名可任意，不表示 Server blob 接收入口已存在。
4. 同一 SEQ 先在受限 VM 執行資源收集，後在正式 VM 用 coroutine；前置的 wait 是空 callback，Register 立即執行，錯誤可能留下部分依賴。
5. Q／lb／Tutorial 的正式環境關係、來源 copy 的釋放與 VM 物件存活已區分；`GetObjectCount` 的 EAX=1 是 Lua 回傳槽數，不能當有效怪物計數。
6. 場景、世界物件、checkpoint、交易及 Server 事件規則的可實作範圍分列；不猜填 MEF opcode、傳檔 wire 或原版 Server 演算法。

## 檔案

| 檔案 | 用途 |
|---|---|
| [parser.md](parser.md) | Parser／header／call engine／DoFile 間接入口／雙 VM／buffer 生命週期 |
| [executor.md](executor.md) | 前置 72 stubs／六個有效 callback、Register、正式 coroutine、API 與 Server 能力矩陣 |
| [storage.md](storage.md) | 名稱型態、copy／move、tree、BSS、析構與指定 alias 候選 |
| [native-windows.json](native-windows.json) | 120 個有界原件窗、85 個具名字串、5 個零初始化全域；逐筆 VA/raw/hex/SHA |
| [native-windows.asm](native-windows.asm) | 同窗原件反組譯，依 storage／parser／resource／executor group 分組 |
| [alias-census.json](alias-census.json) | 165 個指定 initializer 與 32 個 accessor E8 候選；原始 bytes 與第一 consumer |
| [parser-xrefs.json](parser-xrefs.json) | 指定 parser 入口的 literal-pointer／direct-call 候選；保留搜尋範圍，不是全程間接資料流證明 |
| [prepass-bindings.json](prepass-bindings.json) | 72 個空全域、六個每次載入 callback，五個覆寫與 PlayMusic 新增分開 |
| [selected-resource-evidence.json](selected-resource-evidence.json) | 只選六個已知 STP member；carrier/block/offset/hash，五個 MapList row 與一個 scene row |
| [qbase-prototypes-evidence.json](qbase-prototypes-evidence.json) | 24 個本輪引用 prototype 的指令、constants 與結構；固定舊 JSON 來源 |
| [qbase-full-source-verification.json](qbase-full-source-verification.json) | Executor 支線已實跑的全部 76 prototype／906 words 原件核對結果 |
| [source-manifest.json](source-manifest.json) | 71 項固定 Git 來源及原件身分；承接舊筆記與新原件覆核用途分清 |
| [verify_evidence.py](verify_evidence.py) | Python stdlib 唯讀重驗工具；不執行原 PE 或 Lua |
| [verification-result.json](verification-result.json) | 本輪整合工具實際輸出 |

## 原件身分

| 輸入 | SHA256 |
|---|---|
| `02-Tartaros.bin` | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `06-Event.stp` | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `07-Table.stp` | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |

STPD／EX 解碼沿用固定 main 的 `governance/client-variants/20261105-zh-tw-v3/tools/stp_resources.py`，blob `360f32151ba290d64b4f7cba5be3651467d07fd0`；本工具將相同格式讀取整合為唯讀驗證。走索引是為確認六個已知 member 的實體對應，不重做全載體 MEF 檔名盤點。

## 重驗

在 repository 根目錄執行；輸入原件檔名可依所在位置替換，內容 SHA 必須相同：

```bash
python kr-extra-roy/MEF-parser-executor-storage-20261114/verify_evidence.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --event-stp /workspace/scratch/b43c6175f310/project_sources/06-Event.stp \
  --table-stp /workspace/scratch/b43c6175f310/project_sources/07-Table.stp
```

此命令不寫任何檔案。它驗證：

- 原件整檔 hash、真實 PE sections、120 個視窗 bytes／hash／VA/raw 映射、85 個字串及 5 個 BSS 地址。
- 197 個已記錄 alias 候選視窗與 parser 已記錄的正向 xrefs；不以重新搜尋證明陰性完整性。
- 72 個前置名稱的實際註冊 operand、六個有效 callback 的 push 指令。
- 六個指定 STP member 的實體映射、EX 解碼、完整 decoded hash、指定 XML rows。
- 以固定 header 格式只讀解析 qbase 全部結構（76 prototype／906 instruction words），逐項比較本包 24 個選取 prototype 的 482 words、constants、父子與檔案位置。**只解析資料，沒有載入／執行 Lua。**

若本 checkout 有固定主線 blob 與既有完整 qbase JSON，可加以下參數核對全部 prior JSON 及 71 個來源 blob，並輸出衍生結果：

```bash
python kr-extra-roy/MEF-parser-executor-storage-20261114/verify_evidence.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --event-stp /workspace/scratch/b43c6175f310/project_sources/06-Event.stp \
  --table-stp /workspace/scratch/b43c6175f310/project_sources/07-Table.stp \
  --qbase-json shared/integrations/T01-20261029-semantic-review/t16/lua/kr-qbase.lua.json \
  --repo . \
  --out kr-extra-roy/MEF-parser-executor-storage-20261114/verification-result.json
```

完整 qbase JSON 固定 blob `65fbcc2f8dc46bc9fb43a950465c96934b6a547a`／SHA256 `8fdf2bf78c2d8465dc7b401ce76b29dbb2c0f389c5804382196980a38451ab56`。缺少這個可選舊檔不影響第一個命令獨立驗證本包選取證據。

## 本次結果及範圍

`all_matched=true`。120 個視窗的總長 **26,737 bytes**（包含不同 group 的重疊，不是唯一 bytes 覆蓋量）；85 個字串、197 個指定候選窗、六個資源成員與 71 個來源 blob 相符。全部 qbase 舊 JSON 的 76 prototype／906 words、constants 與結構也與本輪唯讀解析相符。

這是來源身分與有界靜態證據核對。它不證明原生 MEF 已還原、不證明所有間接入口不存在、不證明完整 MoCo scheduler 已還原，也不等於 T01 FULL-PASS、S00 ACCEPTED 或實際遊玩通過。其具體未解點與 Server 需求在主稿第 8～10 節。
