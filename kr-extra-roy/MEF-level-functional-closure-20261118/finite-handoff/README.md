# 關卡演出與業務狀態的交接

本子題把已證有限 Q 能力接到**實際 Q119 第四節點**，並補完會影響重打的已播放紀錄持久化鏈。MEF 是 Server 開發；內容規則可在 Server 執行，本地演出優先使用既有 Client 能力。

- [完整結論與原件接點](report.md)
- [機讀交接契約](handoff-contract.json)
- [實際關卡／原場景投影](content-projection.json)
- [原件證據](native-evidence.json)／[可讀組語](native-evidence.asm)
- [來源識別](source-manifest.json)／[重驗收據](verification-result.json)

重驗（只讀分析，不執行遊戲、Lua 或 Server）：

```bash
python -B kr-extra-roy/MEF-level-functional-closure-20261118/finite-handoff/analyze_handoff.py --repo /path/to/ttr_anal_multi --sources /path/to/project_sources
```

重要修正：**一次／Client epoch 的發送限制不等於保證未被 seen-skip。** 原生 `CSL.scn` 可保存並讀回已播 scene；舊研究的限制仍可作 Server 排程預算，但不能作重啟後必定重播的證據。封存包不改寫；以本次新證據補充其適用範圍。
