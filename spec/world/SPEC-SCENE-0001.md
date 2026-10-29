# SPEC-SCENE-0001 — KR 場景靜態索引與 Lua 啟動依賴

**狀態 DRAFT / PARTIAL**；Client KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。來源：`extra/roy1` 原始研究 E01–E16，已以相同 Git blob 複製至當前工作分支。此頁**不是 S2C 場景切換封包規格**。

## 研究支持的資源/Client 本地鏈

| 邊界 | 有限結論 | 原始來源 |
|---|---|---|
| Event.stp → SceneList.xml | E06 對特定 EX v1 範例使用原生 codec 還原完整 XML：158269-byte、1687 個 SCENE；其中一列 `questIdx=1001, sceneIdx=1, funcName=tutorial_start, endBehavior=0` | `CLM-SCENE-0001` / E06 |
| SceneList 索引 | E08 有界研究辨識 `(questIdx, sceneIdx) → funcName` 雙鍵索引及原版 `tutorial_start` Lua source 字串/函式 | `CLM-SCENE-0002` / E08 |
| Index reader → .seq | E13 追到兩條讀取雙鍵索引的路徑，命中後組成 `Event/Sequences/<funcName>.seq`。Lua runtime/load 語意後續由 E14/E15 訂正 | `CLM-SCENE-0003` / E13、E14、E15 |
| 上游 caller 與非首次登入專用反證 | E16 追到 `0x47B5C0 → 0x565720` 與 `EndCutScene → 0x565720` 兩種上游，故 **0x565720 不能被當成首次登入專用入口**；兩路共享 .seq loader，外層資源讀取另有條件 | `CLM-SCENE-0004` / E16 |

注意 E13 提到 `0x55C5A0` 不是直接 file reader；E14 補充 `0x55E2E0` 非檔案 reader、`0x6F4A50` 的資源→Lua 解析/執行候選路徑；E15 再證第一條 reader 經 `0x55D6A0` 的**內部 call** 也會到 loader，E16 修正**兩條都有額外外部 resource call**的描述。整合時請優先採用**後續精確修正**，不要將相對較早的「未查」或錯誤歸納當作目前結論。

## 對 Server 的含義

- Client 確實具有 `(questIdx,sceneIdx)` → 腳本/場景資源的有界靜態消費機制，未來 Server 規格可引用該**資源依賴**。
- **尚未證實任何網路封包**將 `0x42` 選角結果、`0x13` 登入結果或首登旗標與 `questIdx=1001/sceneIdx=1` 綁定。
- `0xEA61` 為 E16 觀察到的物件欄位比較常數，**不能直接稱為教學任務號、S2C opcode 或 1001**。
- 首登是否播放教學、如何持久化、如何跳過教學是 Server 設計與 Client 行為核對的交界；沒有 wire/handler 證據前**不得**聲稱使用 `(1001,1)` 是官方回覆方式。
- Client 原版教學場景可能使用不同於其他場景的資源、腳本與狀態前提；T07 已知 `005F type6` 走 `CDuelField` 的相關反證需保留，不可用自製 Tutorial fixture 作官方場景資料。

## 來源與保留

原稿來源分支頭：`extra/roy1@44a610968a228d4104e39457891e4fc565a3790c`。研究原稿完整保存於 `kr-extra-roy/`（E01–E16 16 篇），未作修訂；目前只把 E06/E08/E13/E16 登錄為四個有界來源 SRC，E14/E15 為修正依據。它們均屬 **PARTIAL（S00 尚未獨立驗證原始 BIN/資源的完整語意）**；不代表 T01 FULL-PASS 或已正式核定相容封包。

缺口 `GAP-SCENE-0001`；請求 `RR-0008`；若需實際啟動狀態研究，與 T03、T05、T06、T07 協作，首要查 `0x42` receive result 與 `0x47B5C0` 上游 gate/writer。無任何 Client runtime 相容性 TEST。
