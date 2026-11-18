# MEF 目前開發方向：Server 提供內容，優先由 MEF 處理

**2026-11-18 使用者最新指示；適用 `extra/roy1` 的後續 MEF 分析與規劃。**

本頁是目前研究入口。最新關卡功能分析在 [MEF-level-functional-closure-20261118](MEF-level-functional-closure-20261118/README.md)；能力與執行位置基礎見 [MEF-server-provided-capabilities-20261118](MEF-server-provided-capabilities-20261118/README.md)。歷史包保留原始證據與當時結論；遇到「是否必須還原官方 MEF」「Server 責任是否排除 MEF」「哪些項目阻塞所有自製內容」的方向衝突，依本頁與本輪報告解讀。

## 已確定的目標

1. **MEF 開發屬於 Server 開發。** Server 提供、選擇及管理 MEF 內容；生怪、戰鬥判定、敵群清空、開出口、任務結算、獎勵與進度保存均在此開發範圍。
2. **能用 MEF 處理的優先交給 MEF。** 分析每項功能的規則、排程、執行、觀察、回報與保存，不因標示「Server 負責」就把整項排除於 MEF。
3. **以可實作能力為目標。** 官方 `.mef` 檔案、官方容器與格式復原不再是研究目標，也不作自有 MEF 開發的共同門檻。來源標籤 `NOT_NATIVE_MEF` 僅區分自行設計與原生事實，不表示自有內容不算 MEF 開發。
4. **區分執行位置及實際收益。** Client 執行的 MEF／native 效果可承擔本地排程與運作；Server 執行的 MEF 規則可集中關卡邏輯、減少硬編碼，但不能直接算成 CPU 已移到 Client。節省量須以實際流程量測。
5. **只保留具體接口缺口。** 例如某個普通怪物事件未能傳入 Lua、某個原生指令不回傳物件 ID、現有結算 adapter 尚未讀取新 MEF 規則。不要再用「缺官方 MEF」概括這些不同的工作。

## 歷史結論如何使用

- 既有 BIN／資源證據、ABI、作用對象、生命期與 loader 結論仍可引用。不能因目標改變就把空操作說成有效、把顯示傷害說成扣血，或創造原件未證的 wire。
- 舊版 P2 官方格式搜尋改為**退出本次目標**，不是已復原；既有搜尋紀錄不必重做。
- 舊版普通場景背景 Lua（B）缺口只約束「保持普通場景操控且常駐 Lua」這個 profile；有限 Q 與 Tutorial 的已證入口仍可用。
- 舊版特定 Q119／模型／UI 資源缺口，僅約束真正依賴那些資源的內容；不能阻擋不使用那些資源的新 MEF。
- 既有 Server 功能與驗證收據要復用。新 MEF 還沒接入，不等於整個背包、任務或存檔功能從未實作。

本頁不變更正式 Task owner、RR、T01 驗證、S00 規格狀態或遊玩驗收；原件唯讀及分析與執行分離仍依共用指示。使用者已指定工作分支 `extra/roy1`，不另開分支。

## 最新關卡分析補充

- 已完成20類關卡功能的有界分析；實際67份配置的圖／旗標和BND分層稽核，進度、缺項、優化分列[玩家進度](MEF-level-functional-closure-20261118/PLAYER-PROGRESS.md)。這些包含歷史與候選，不等於67個已部署可玩副本。
- 原生 `CSL.scn` 有保存／讀回seen紀錄的路徑。舊「一次／Client epoch」只足作Server派送預算，不保證重啟後未看或callback必跑；003F也可來自seen-skip。[原件補證](MEF-level-functional-closure-20261118/finite-handoff/report.md)
- Q119清場演出後的地圖／完整點集重建會換代；較早的本地setter不保證保留。沿用已提交Server MEF旗標投影到新快照；只有需要多步演出才新增有限插播hook。
- 現有scenario JSON／typed規則可以直接作MEF開發，不強制新建格式。公開範例缺口、實作缺口、特定Client可見操作與新玩法擴充分開，不能互相代換。
