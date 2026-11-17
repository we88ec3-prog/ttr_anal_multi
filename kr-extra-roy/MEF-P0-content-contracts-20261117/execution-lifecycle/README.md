# P0：MEF 執行、持有與收尾契約

日期：2026-11-17；工作分支 `extra/roy1`；原稿基準 `ac7e668ef19b91f86f05074d660aba10612c9a5f`。本題完成上一份 [ANALYSIS-PLAN 的 P0 執行與收尾項目](../../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)：把同一 KR Client context 的取得、使用、停止、排釋放、恢復、End 與下一次 Start 分開，並提供可供 Server 採用的三類 run 契約。

**分析與契約交付完成；選定內容與三類策略仍不宣稱可部署或已遊玩。** 真實資源、目前 runtime 選取及實際 Server 串接依整包資料與採用規格處理。沒有執行 Lua、Client、Server 或遊戲；沒有變更原件、正式 RR、T01、S00 狀態。

## 主要產物

| 產物 | 用途 |
|---|---|
| [report.md](report.md) | 完整繁中分析、原件接點、適用條件、具體剩餘邊界 |
| [owner-ledger.json](owner-ledger.json) | 22 類 owner 的 identity、取得、釋放及完成限制 |
| [cleanup-order.json](cleanup-order.json) | 20 條條件式清理偏序，保留原 SEQ 與 native Stop 的不同順序 |
| [run-contracts.json](run-contracts.json) | 有限效果、同 run 多 phase、獨立兩 run；pending producer 分別限定 |
| [completion-boundaries.json](completion-boundaries.json) | 7 項研究終點與 Client／Server／整合／遊玩剩餘責任 |
| [SERVER-HANDOFF.md](SERVER-HANDOFF.md) | 對既有 REQ-0019／REQ-0021 的增量開發輸入 |
| [native-evidence.json](native-evidence.json)、[native-evidence.asm](native-evidence.asm) | 7 個新增有界 native 窗口、28 個精確復用窗口、指令及資料錨點 |
| [selected-image-contract.json](selected-image-contract.json) | Q2440/5 原 fade-out0 的 constructor→branch→alive0→實體回收正向鏈 |
| [qbase-lifecycle.json](qbase-lifecycle.json)、[selected-scene-lifecycle.json](selected-scene-lifecycle.json) | 原件 data-only 解析所得的 helper、Boot 數字初始化及兩個 SEQ 收尾片段 |
| [source-manifest.json](source-manifest.json)、[artifact-manifest.json](artifact-manifest.json) | 47 個固定 Git blob／SHA-256 與本題交付檔雜湊 |
| [verify_evidence.py](verify_evidence.py)、[reference_model.py](reference_model.py)、[verification-result.json](verification-result.json) | 可重跑只讀驗證器、12 個明列 SYN 投影與實際結果 |

## 本輪最重要的增量

`Q.DeleteAllObject → actor.v+14 → D+8.v+8 → 7A57C0` 已接到原件：**已 apply 的 state 1 Doll 先排 instance／applied parts 釋放，再清 instance、改 state 0、置 dirty；之後 actor destructor 不會再以 state 1 重複排同一份釋放。** 原件 secondary receiver 是 `D+8`，不能直接把函式內 `+1C` 誤讀成 D.instance。release worker 仍是後續 native 工作。[報告 §3](report.md#3-新增閉合全q樹刪除如何實際釋放doll與附件)

正常 Q 建立的 direct call 仍是 **immediate 1**；它正常返回前已 apply，不能把 generic deferred callback 風險套成兩個選定原 scene 的既成事故。另一方面，排 release、圖片自然回收、sepia 更新和聲音工作各有自己的完成時點，沒有共同 drain ACK。[報告 §4](report.md#4-pending-callback取消與render必須按真正producer分類)

`SetFinalMusic("")` 的空字串追加 0 bytes，保留舊值；**accepted Start** 則呼另一個 assign helper 將字串清空。這兩個轉移不可互換。兩個原 SEQ 的空字串呼叫保留原樣，不被當成通用 clear API。[報告 §6](report.md#6-音樂策略與空字串的精確意義)

## 重跑

```bash
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/execution-lifecycle/verify_evidence.py \
  --bin /absolute/path/02-Tartaros.bin \
  --event /absolute/path/06-Event.stp \
  --repo /absolute/path/ttr_anal_multi
```

需要 Python 3.10+、objdump、原件與固定 Git objects。預設只輸出 JSON；需要更新本題收據時才加 `--out .../execution-lifecycle/verification-result.json`，也可寫非原件目錄、非 repository 的結果路徑。驗證器不許覆寫原件、其他 repo 檔或不相干的既存檔案。PASS 限於資料、來源、位元組、指令邊界、圖與 SYN 一致性；不是語意全文 FULL-PASS、全引擎取消保證或 Server／可玩驗收。
