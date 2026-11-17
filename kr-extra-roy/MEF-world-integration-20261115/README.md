# MEF world integration — 第七輪有界原件證據

主報告：[普通場景 runner、物件身分、事件橋接與完整收尾封包](../20261115-121913-chatgpt-web-roy1-MEF-world-integration.md)。本包位於使用者指定的 `extra/roy1`，parent `acc5b1e6d856bd31456fe2806044c3a09d5bbb43`；main參考 `060ed5163a67308f15aa32a91f3a6661e6e5b106`。

| 分題 | 報告 | 這輪補上的契約 |
|---|---|---|
| Wire／收尾 | [wire/report.md](wire/report.md) | 00EB完整入站路由、2-byte app／兩種frame、完整frontend初始化、003F的略過與正常End producer |
| Runner | [runner/report.md](runner/report.md) | Tutorial／Expedition／review三個pump的合法場景、UI入口、更新與取消界線 |
| 世界身分 | [identity/report.md](identity/report.md) | 本地actor共享樹、duplicate不接管、EntityId低byte分型、位置／控制更新與刪除條件、具體Lua getter |
| 事件 | [events/report.md](events/report.md) | 004C的Tutorial限定writer，004E到特定UI的零參數Lua callback、ordinary field/page分歧 |

## 重現

```sh
python -B kr-extra-roy/MEF-world-integration-20261115/verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi
```

需要對應版本原始 `02-Tartaros.bin` 與各分題列明的Event載體，以及已存在於本機的固定Git來源。驗證器不fetch、不改Git、不執行Client／Lua；原件只以bytes解析及objdump解碼。主結果在 [verification-result.json](verification-result.json)，檔案身分在 [artifact-manifest.json](artifact-manifest.json)，固定來源與main差異範圍在 [source-manifest.json](source-manifest.json)。

## 使用界線

本包支持有限內容與Server相容流程開發，沒有證明新 `.mef` 的原版首次caller已存在，也沒有完成普通戰鬥的完整Client接手。`00EB` 是解除等待；`003F` 可由略過分支送出；同一世界樹不代表ID／actor class已對齊；特定UI的OnYesTriggered不是typed死亡事件。具體Server開發需求與後續定向分析項見主報告。

SYN frame只作文件與純Python算術重驗，沒有送出網路封包。研究中未修改原Client／原資源，未新增branch，未改共享governance、RR、Task、registry或owner狀態；原始資源與導航副本不作新的raw原件上傳。
