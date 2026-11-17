# P1 world 結果到 Lua：續析交付

本目錄完成普通 world actor 結果的所列原生 producer／實際 consumer 有界分析，並保留精確的未閉合終點。**尚無同 run／actor generation 的 world→Lua 出口證據**；Server 權威事件、敵群與任務另列開發需求，不依賴客戶端畫面當 ACK。

- [report.md](report.md)：完整繁中結論、原生資料流、型別、候選處置與 Server 規劃。
- [contracts.json](contracts.json)：7種 wire通道、4個身分域、3個 native記錄/消費契約、未閉合接點與5項Server需求。
- [native-evidence.json](native-evidence.json)／[native-evidence.asm](native-evidence.asm)：31個新程式窗口、38個資料窗口、17個復用窗口、9項有限參照census。
- [source-manifest.json](source-manifest.json)／[read-set.json](read-set.json)：基線 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa` 的75個source pins及分析/搜尋邊界。
- [verify_evidence.py](verify_evidence.py)／[verification-result.json](verification-result.json)：原件只讀重跑工具與實際PASS收據。PASS不代表runtime或world→Lua bridge已完成。
- [artifact-manifest.json](artifact-manifest.json)：本目錄交付檔案的bytes與SHA-256。

```bash
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/world-lua/verify_evidence.py \
  --bin /path/to/Tartaros.bin \
  --repo /path/to/ttr_anal_multi \
  --shared-instructions /path/to/02-PROJECT-SHARED-INSTRUCTIONS.md
```

本輪不改舊報告、正式claim狀態、來源原件；Git整合由本輪主分析負責。
