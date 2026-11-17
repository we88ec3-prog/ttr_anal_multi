# MEF — 世界身分與事件／場景與互動

本輪的重點不是再列API名稱，而是接通world身分、控制重綁、死亡／移除，以及field／map／point／loading／ready的正常consumer；普通世界結果到Lua仍保留精確缺邊。相容設計不是官方MEF格式。

閱讀入口：[總報告](REPORT.md) · [世界身分與事件](WORLD-IDENTITY-EVENTS.md) · [場景與互動](SCENE-INTERACTION.md)

開發交接：[Server需求](SERVER-HANDOFF.md) · [下一階段分析](NEXT-ANALYSIS.md) · [機讀契約](contracts.json) · [已查範圍](read-set.json)

證據：[原生資料](native-evidence.json) · [可讀組譯](native-evidence.asm) · [選定資源](resource-evidence.json) · [固定來源](source-manifest.json)

核對：[驗證器](verify_evidence.py) · [資料reader](stp_reader.py) · [推導模型](model_checks.py) · [實際stdout](verification-result.json)

所有原件只讀。沒有Client/Lua/Server執行、可部署遊戲內容、新opcode、完整解包資源或原BIN/STP。30項模型檢查不是原程式執行測試。

目標分支`extra/roy1`，基線`0d76b827dfda0deb263e2692281ec304747652f8`。本輪未建立分支，未改其他owner、Task／RR或正式驗收。遠端發布受目前GitHub只讀介面限制；請以[發布記錄](PUBLICATION.md)及累積patch核對，勿當成已push。

重跑：
```sh
python -S -B verify_evidence.py --bin /path/to/Tartaros.bin \
  --table-stp /path/to/Table.stp --event-stp /path/to/Event.stp \
  --boundmap-stp /path/to/BoundMap.stp
```
