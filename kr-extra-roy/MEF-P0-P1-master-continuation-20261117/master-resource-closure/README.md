# Master 與 P0 資源接續

入口：[完整分析](report.md)；機器契約：[掛載摘要](master-summary.json)、[132 項路由](selected-resource-routes.json)、[108 項前緣差異](p0-frontier-delta.json)、[資源載入器](resource-loader-contract.json)。

Master 的原件／完整掛載宣告已閉合；P0 真實 payload 與實際 cache／安裝選取仍有精確缺件。`resource_ready=false`，不是可部署包。

從 repository root 執行，原件目錄沿用本次提供的檔名，supplemental 需既有 Base 與 W1/W2/W3 ZIP：

```bash
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/master-resource-closure/verify_evidence.py \
  --repo . --sources /absolute/path/to/project_sources \
  --supplemental /absolute/path/to/supplemental/ttr
```

加 `--require-ready` 應回傳 2；它不是驗證器失敗，而是阻止有缺件的真實資源被誤報 ready。預設僅讀，沒有 Client／Lua／Server 執行；重建 derived JSON 請使用 [master_audit.py](master_audit.py)，output 必須在本研究子目錄或與原件分離的 scratch。
