# MEF 三項續查（2026-11-17）

[完整總稿](REPORT.md)｜[轉場](TRANSITION.md)｜[世界角色操作](ACTOR-OPERATION.md)｜[世界事件](WORLD-EVENTS.md)｜[Server交接](SERVER-HANDOFF.md)｜[後續計畫](NEXT-ANALYSIS.md)

本包是BIN-first分析與相容內容規格，不含可部署遊戲腳本，不是官方MEF格式復原。轉場與avatar仍有明列的部署資料缺值；普通死亡／清組到Lua尚未接通。不要把離線PASS當遊戲完成。

重驗需要Python3、GNU objdump，以及唯讀原BIN／Table／Event／BoundMap；本包同層保留前輪三份研究包，因為使用固定SHA的data-only STPD reader與既有surface：

```sh
python -B verify_evidence.py --bin /path/Tartaros.bin --table-stp /path/Table.stp --event-stp /path/Event.stp --bound-stp /path/BoundMap.stp
python -B test_contract.py
```

[原件證據](native-evidence.json)、[可讀ASM](native-evidence.asm)、[選定資源](resource-evidence.json)、[機讀協定](contracts.json)、[轉場profile](transition-profile.json)、[外觀profile](actor-operation-profile.json)、[實際驗證](verification-result.json)、[模型驗證](model-verification.json)、[來源](source-manifest.json)、[已查範圍](READ-SET.md)。

分支仍為既有extra/roy1。發布能力與遠端查核狀態見[PUBLICATION.md](PUBLICATION.md)；沒有寫入成功不能聲稱上Git。整包保留前輪49檔不變，所有SHA在累積發布manifest核對。
