# P1 正常旅程與功能族

本題承接 `MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md` 的兩項 P1：完整正常旅程、擴充所有功能族。固定 baseline 為 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa`；不新增正式REQ／RR／T01狀態，不執行Client／Server／Lua。

- [REPORT.md](REPORT.md)：繁中分析、Q119十步旅程、七族取得／退出／資源及Server需求、精確未決前沿。
- [contracts.json](contracts.json)：十步旅程、七族、六個有界wire契約、六條既有REQ開發輸入。
- [data-evidence.json](data-evidence.json)：五段原SEQ全檔靜態讀取、Quest／Chart／Cluster／Map／Talk／商品／效果／Master宣告、BND候選位置檢查。
- [native-evidence.json](native-evidence.json)及[native-evidence.asm](native-evidence.asm)：49個固定原件窗口的再比對；8個新窗口及完整指令邊界。
- [source-manifest.json](source-manifest.json)及[native-selection.json](native-selection.json)：commit／blob／SHA／bytes與有界讀集。
- [audit.py](audit.py)、[verify_evidence.py](verify_evidence.py)、[verification-result.json](verification-result.json)：只讀重算器、驗證器及實跑收據。

```sh
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/journey-families/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --supplemental /absolute/path/supplemental_resources/ttr \
  --receipt /scratch/receipt.json
```

`PASS`只表示本題的固定靜態資料與原件證據可重現；完整payload、實際cache選取、部署與遊玩驗收保持分開。Master缺檔已解除，不能因此把所有引用carrier視為已取得。
