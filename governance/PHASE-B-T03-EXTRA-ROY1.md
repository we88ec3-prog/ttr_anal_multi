# Phase B / T03 補充證據：extra/roy1 的 E01–E16

日期：2026-10-29。原始研究分支：`extra/roy1`；來源 HEAD：`44a610968a228d4104e39457891e4fc565a3790c`。

## 合併方法與範圍

- `extra/roy1` 相對工作分支另有 16 個 `kr-extra-roy/` 檔案。本次採用 **原始 Git blob 直接納入**，沒有 merge 整個分支、重寫原稿或抹掉 T01 歷史。
- E06（EX v1 SceneList 解碼）、E08（雙鍵索引與 tutorial_start source）、E13（索引 reader → seq path）、E16（上游 caller/EndCutScene 反證）是此輪選擇性建立 SRC/CLM 的四個來源；E14/E15 是更正前後鏈接的必要補充，但不單獨聲稱已經 T01 認證。
- 現有 SPEC-AUTH-0001、SPEC-CHAR-0001、SPEC-NET-0002 仍是登入/選角/連線的主要證據來源；E01–E16 不能替代它們的 wire 規格。

## 語意差異及後續修訂

- E06：SceneList.xml `(1001,1)→tutorial_start` 是 Client 靜態資源資料，不能推定 Server 會必發 `(1001,1)`。
- E13→E14→E15→E16：同一 Script API/seq loader 的後續 caller 與路徑已有範圍修正。只採後續有界更正；歷史原稿保持原樣且互相引用。
- E16：`0x565720` 不僅從 `0x47B5C0` 路徑呼叫，EndCutScene 亦會呼叫。這是「只要觸發它就等於新角色初登」的**反證**。
- 最重要的 T03 未解點仍是 **選角 C2S 0x42 → 精確 S2C response → 客戶端 scene gate / index key**，尚無閉環。新增 `GAP-SCENE-0001`、`RR-0008`。
- S00 現有跨流程 [SPEC-FLOW-0001](../spec/session-account/SPEC-FLOW-0001.md) 分列證據與未知；未補出不具證據的 opcode、回覆順序或原版 Server 帳號決策。

## 下一輪定向分析

最有效的 Agent 工作不是從所有 Event.stp 重讀，而是 `T03 0x42` 的 exact response handler、`0x47B5C0` 的 caller 和 `[object+0x248]` writer，並檢查它們是否真正會把 `(questIdx,sceneIdx)` 傳入 `0x565720`。**無 REA Agent** 可先核對這批 E01–E16 的原始文字與有限 caller 清單；需要未收錄的原始 BIN 分支資料流再交 REA Agent。

無外部 Issue 啟用、無原版 Client 互動/運行驗收，全部維持 DRAFT/PARTIAL。
