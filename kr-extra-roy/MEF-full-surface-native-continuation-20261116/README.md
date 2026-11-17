# 全面腳本能力盤點與 native 持續效果

**[完整原稿](REPORT.md)**｜[Server交接](SERVER-HANDOFF.md)｜[逐名稱能力矩陣](capability-matrix.tsv)｜[來源／已查範圍](SOURCES.md)

A1仍是相容最小規格、未部署。此包新增兩項工作：原BIN的固定registrar與C-closure建構直接呼叫盤點，以及Q End後actor／Fade／Sepia的實際native更新/繪製鏈。這不表示全MEF功能完成、官方格式已還原，亦不解決B的全程不中斷輸入入口。

## 檔案與閱讀

`surface-census.json`保存122個registrar（121正式＋1預掃描）、223個closure呼叫分類及11個table registrar來源；`native-proof.json`保存精確區間digest與必要原件節錄；`qbase-evidence.json`只有6個選定函式的48個指令字，沒有完整遊戲資源。`capability-matrix.tsv`是沿用語意與本輪生命周期覆核的導覽，不是121項已部署功能。

`verification-result.json`是實際本輪stdout；`previous-a1-rerun.json`是重跑前輪A1。實際核對PASS不自動成為T01 FULL-PASS、S00接受、Server已開發或可玩。

## 重跑

準備原KR BIN及Event.stp，以及上輪研究包還原後的純資料parser。原始遊戲資源不上Git，驗證器也不會下載或執行它們。

```sh
python -B audit.py --bin /path/to/Tartaros.bin \
  --event /path/to/Event.stp \
  --prior-parser /path/to/MEF-one-shot-study-20261116/verify_evidence.py \
  --out /a/separate/research-output-directory
```

上一輪完整包與還原方式在[one-shot-followup](../MEF-one-shot-followup-20261116/README.md)。parser的完整SHA在SOURCES與audit.py內；驗證器先核對再import，僅執行STPD/Lua資料解析。不要將不明同名檔案當相同來源。只給`--bin`可做BIN盤點，但輸出會明示`original_qbase_checked=false`，不能當成本包完整重驗。

工具：Python3與GNU objdump。輸出目錄必須獨立；`--out`可重建全部選定完整可讀ASM與結果JSON，不寫Client/Server/原始資源。掃描target索引只建一次，避免每個registrar再重掃整段.text；無網路或Git變更。

## 可用結論與下一步

End只終止選定Lua生命週期，不一定終止已啟動的native效果。有限插播可先啟動作用，再按既有政策退出；演出物件後續仍可能更新和繪製。但保留／回收、共享owner及同場景條件必須另有契約，不能把未清理物件當作完整玩法。FadeOut的遮罩尤其不能靠End自動移除。

逐功能計畫與精確未解見REPORT第7–8節。A1不改、B仍未閉合；通關／服務／資產／持久化維持Server責任。原生MEF未證部分與相容內容設計明確分列。
