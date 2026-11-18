# P0-3 生怪與 P0-4 戰鬥：執行鏈與對接契約

本包接續既有 world-offload、L03/L04 及 T09/T10/T11 邊界，補齊生怪初始化、普通 actor 屬性、實際 Server 怪物行為／戰鬥服務，以及 `0094 → CBullet` 投射物的資源、逐幀更新與終止鏈。MEF 採本專案定義，包含 Server 提供及執行的規則內容。

- [report.md](report.md)：完整分析、玩家說明、已存在能力、精確剩餘需求與優化順序。
- [capability-contracts.json](capability-contracts.json)：8 項能力、4 組 adapter 契約、0007／0000／0094／001A 欄位。
- [native-evidence.json](native-evidence.json)、[native-evidence.asm](native-evidence.asm)：原 BIN 的 54 個有界視窗與型別／欄位／呼叫斷言。
- [behavior-audit.json](behavior-audit.json)：8 份既有 authoring 檔、17 個 profile 出現的全量稽核。
- [bullet-resource-audit.json](bullet-resource-audit.json)：原 `Table/Blt2.blt` 的 228 筆投射物宣告及少量對照列。
- [source-manifest.json](source-manifest.json)：原件、65 份固定 Git source pin、10 份實際私有 Server source pin。
- [verification-result.json](verification-result.json)：只讀重跑結果；不代表 Client 遊玩驗收或正式 FULL-PASS。

## 重跑

```bash
python -B kr-extra-roy/MEF-P0-level-execution-20261118/actors-combat/verify_evidence.py \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi \
  --sources /workspace/scratch/3e083e35831f/project_sources \
  --server-sources /workspace/scratch/3e083e35831f/analysis/mef_p0_level_server_sources_20261118 \
  --receipt /tmp/mef-p0-actors-combat-verification.json
```

`--receipt` 可省略；省略時只輸出結果，不改任何檔案。需要 Python、jsonschema、Git 與 GNU objdump。驗證會讀固定 Git object、重新解碼原件／指定 STP 成員、核對實際 Server 檔案的 bytes／Git blob／SHA256；不執行 Client、Lua 或 Server。完整私有 C# 保留在外部來源目錄，未複製到分析 Git。
