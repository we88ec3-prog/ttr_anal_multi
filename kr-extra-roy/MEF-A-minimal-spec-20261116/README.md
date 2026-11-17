# A1 v1：有限插播的一次切點最小規格

**[完整可實作規格](SPEC.md)**｜[機讀profile](profile.json)｜[原件與候選鍵核對](evidence.json)｜[實際驗證](verification-result.json)

交付範圍：原普通Mission／Scenario中，對唯一既有point執行0→1；固定採quest0單次內容與003F／00EB收尾。允許有限插播，沒有把它提升為不中斷操控B。原版MEF格式仍未證，分類為`NOT_NATIVE_MEF`。

已定候選 `(0,32760)` 與 `Event/Sequences/compat_point_once_a_v1.seq`；已核原資源未占用，但不是官方／跨Agent保留鍵。正式發布必須查實際合併索引。point常數建置時綁定，執行時核對快照，0047不帶任意point參數。**本包沒有現場RunBinding、實際新sequence或部署授權，因此不能直接放入Client遊玩。**

開發者可依SPEC實作三部分：內容建置與release manifest、Server單次排程／原封包／持久已用鍵帳、正常流程觀察與對帳。Server通關、資料發布、服務與持久化不必交給腳本。

## 離線參考與重跑

`contract.py`提供Application形狀、RunBinding一致性檢查及純記憶體政策模型；不發包、不寫DB、不產生遊戲資源，不是Server產品實作。`test_contract.py`只有明確標為SYN的格式／政策算術，座標、key及hash不是合法關卡配置。

```bash
python -B test_contract.py
python -B contract.py /path/to/run-binding.json /path/to/prior-0027-application.bin
python -B verify_evidence.py --bin /path/to/Tartaros.bin --event /path/to/Event.stp \
  --prior /path/to/restored/MEF-one-shot-study-20261116
```

`--prior`需先按[父提交研究包](../MEF-one-shot-followup-20261116/README.md)還原。驗證器在載入舊的data-only parser前，強制核對其公開SHA；沒有網路、Git或遊戲執行。前輪完整原件42窗的本次重跑另存 `previous-study-rerun.json`。新驗證器只核新增鍵配置／003F節錄及本規格需要的關鍵寫入，不重做B候選研究。

PASS不是T01 FULL-PASS、S00 STABLE、部署或遊玩通過。文件狀態、Client靜態已證、Server待開發、發布待整合與待遊玩驗證分開維持。

工作分支`extra/roy1`；本次僅新增本目錄，不改原件、其他Task、正式REQ／RR或Server程式。公開範圍僅規格、少量證據、配置profile與離線檢查碼，不含BIN／EXE／STP及完整解包資源。
