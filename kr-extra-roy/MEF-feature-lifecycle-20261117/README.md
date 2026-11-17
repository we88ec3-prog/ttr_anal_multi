# MEF 全能力續查：owner、End後持續與真實收尾

[完整技術報告](REPORT.md) · [全能力分組](CAPABILITIES.md) · [121列矩陣](capability-lifecycle.tsv) · [Server開發交接](SERVER-HANDOFF.md) · [下一階段計畫](NEXT-ANALYSIS.md)

本包接續尚未推送的 `MEF-full-surface-native-continuation-20261116`。沿用其有界121正常binding／223 closure calls／11 library table calls盤點，新增接通鏡頭、有限圖片、BGM、Q actor全量回收，以及世界顯示、慢動作和黑邊的獨立owner／停止／清理契約。**是階段性全功能研究，不宣稱完整官方MEF格式、B不中斷入口或全部功能已實作。**

## 證據與結果

`native-evidence.json` 保存50個選定原件區間、24個精確指令錨點、9個資料區間、14條direct calls；`native-evidence.asm` 是逐指令可讀原件。`feature-families.json` 與TSV保留所有正常名稱，stub與無效query沒有被當成可用玩法。

`verification-result.json` 是本輪實際執行輸出；`previous-surface-rerun.json` 是前輪原件盤點的重跑結果。`models.py`／`test_models.py` 是32個**SYN推導檢查**與分析計畫檢查器，不是Client模擬器、Server程式或可部署MEF格式。

## 重跑

需要固定KR原件與前輪完整研究資料夾（累積ZIP／patch已同時提供）。原件不隨本包發布。

```sh
python -B verify_evidence.py \
  --bin /path/to/Tartaros.bin \
  --previous ../MEF-full-surface-native-continuation-20261116
```

要同時重核原始qbase選定資料，提供原Event.stp及先前one-shot研究包的固定data-only parser：

```sh
python -B verify_evidence.py \
  --bin /path/to/Tartaros.bin \
  --previous ../MEF-full-surface-native-continuation-20261116 \
  --event /path/to/Event.stp \
  --prior-parser /path/to/MEF-one-shot-study-20261116/verify_evidence.py \
  --check-manifest
```

需Python3與GNU objdump；原件hash、parser／prior audit hash均核對。不同disassembler格式可能影響ASM字串比對；應核對工具差異，不可改原件湊PASS。程式不連網、不執行Lua／Client／Server，不改Git或遊戲資源。

## 發布

基準 `extra/roy1@0d76b827dfda0deb263e2692281ec304747652f8`；main仍 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本輪連線沒有寫入操作，未推送、未建立commit或branch。詳 [PUBLICATION.md](PUBLICATION.md)。完整前後兩包以累積patch保存，不含原始BIN/EXE/STP、完整解包member或可部署腳本。
