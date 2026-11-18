# MEF 生怪／戰鬥／清波分題

[完整繁中分析](report.md)｜[機讀能力契約](capability-contracts.json)｜[讀取與停止範圍](READ-SET.md)

MEF 開發屬 Server 開發。內容規則優先交由 MEF 定義，能由既有 Client／native 執行的部分優先下放。現有 Server 的 Scenario、MonsterBehavior、WaveCleared、WaveHealthReached、巡邏及固定路段成果均保留；本包明列追加下放所需的接口。

本輪的必要原件核對把 CMonster 的同一 world 身分接到 native 位置步進、位置可用性 gate、writer 及 state 更新；另接到普通技能動作的實際 state hooks，區分表現、傷害、HP、死亡與刪除。普通 Lua 的 world handle／生命事件缺口保留為具體 adapter 需求，不以官方 MEF 樣本或責任歸屬阻塞自訂功能。

## 重跑

```bash
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/world-offload/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi
```

需要 Python 3、git、GNU objdump；驗證器只讀取本包、原 BIN 與固定 Git blobs，結果寫 stdout。`verification-result.json` 是本輪實際收據。`artifact-manifest.json` 固定本包內容；收據與 manifest 自身不放進其 hash 集合，避免循環。

本包未執行遊戲、Server、Lua、target DLL 或測試封包。10 個 observer 案例僅驗證提議資料契約的有限審核模型；不等於修改既有 WaveCleared，更不是遊玩測試。未新增或擴大既定人測排程。
