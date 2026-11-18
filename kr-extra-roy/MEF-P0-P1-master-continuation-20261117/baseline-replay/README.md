# 本輪歷史 P0 重跑

以下三份JSON是本輪主分析者對既有已發布檢查器實際只讀執行的stdout收據。原package未修改；工具本身固定的歷史source commit保留原值，並未改成新基準假裝所有內容都是本輪新發現。

| 結果 | 命令來源／數量 |
|---|---|
| [abi.json](abi.json) | P0 abi-adoption/verify_evidence.py；40 pins、121 bindings、33 marshallers、15勘誤、75 QBase helpers，PASS_REPRODUCIBLE_BOUNDED_RESEARCH |
| [lifecycle.json](lifecycle.json) | P0 execution-lifecycle/verify_evidence.py；47 pins、22 owners、20 edges、3 profiles，all_matched=true |
| [server-context.json](server-context.json) | P0 integration/verify_context.py；4 pins、4 Q119 nodes、4 schema levels，PASS |

可在repo root重跑（以下三命令互不寫原件或舊收據）：

```sh
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi --sources /absolute/path/project_sources

python -B kr-extra-roy/MEF-P0-content-contracts-20261117/execution-lifecycle/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --bin /absolute/path/project_sources/02-Tartaros.bin \
  --event /absolute/path/project_sources/06-Event.stp

python -B kr-extra-roy/MEF-P0-content-contracts-20261117/integration/verify_context.py \
  --repo /absolute/path/ttr_anal_multi
```

舊原件SEQ計數若含最外層Register會多1，本輪旅程的176明確只計body calls；這不是同一分母。收據中的SYN案例仍是分析器／政策模型，不是Client／Lua／Server執行。
