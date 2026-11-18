# 整合審查與證據界線

日期：2026-11-18。這是本研究包的內部證據／文件一致性審查，不是 T01 FULL-PASS、S00 規格接受或遊玩通過。

## 已採納的交叉審查修正

| 問題 | 審查後的精確表述 | 已修正的主包文件 |
|---|---|---|
| fcs record 容易被寫成帶有各 entry 的 packed flag | record 沒有 per-entry packed flag；FB79A8 為正常初始化依 reader 返回設定的全域狀態。候選 path、實際分支、provider 與 payload 分開核對 | SOURCE-REQUEST、REPORT |
| `cache-miss` 容易混成 basename／group miss | 啟動十組 defaults／全域 scan 的條件是 `fcs.flu` 開啟失敗、reader 回 0；一般 group/key miss 不觸發它 | REPORT、SOURCE-REQUEST、status |
| first-wins 容易被讀成所有 group 全域競爭 | entry 只在同 group 的正規化 basename 內競爭；不同 group 同名 entry 可並存 | REPORT |
| 零計數反例的環境條件 | 成功開啟、空 manager、配置／CRT 正常完成，reader 才沿該路回 1；不是所有損壞資料都成功或必定 crash | REPORT、COMPLETION |
| 不必永遠要求實際列舉順序 | 完整搜尋範圍可證唯一候選時，可免除同鍵先後順序依賴 | SOURCE-REQUEST、PLAYER-PROGRESS |
| Q119 portal 政策可能被讀成原版 MEF／實機事實 | 四節點使用現有 Server 重建候選，authority 明示 `SERVER_RECONSTRUCTION_NOT_NATIVE_MEF` | PLAYER-PROGRESS、SERVER-REQUIREMENTS、status、verify_evidence |
| Field 路由被算成新發現 | Field 掛載與路由為復用；本輪 P2 新原生更正是 partial-DI lifetime，其他為接點整理與分域核對 | REPORT、REUSED-EVIDENCE、status |
| 「Master 包含 .mef」可能被讀成已取得 member | Master 的 Field 封裝規則列 xml/mef，沒有提供官方 MEF 內容 | PLAYER-PROGRESS |
| UI cache 被等同新 script run | 初次 FTC 讀取、既有 UI instance 重掛與 script 首次執行／取消世代分開；B 保留 NOT_CLOSED | REPORT、COMPLETION、status |

P1 的原生 receiver 勘誤另見 [ERRATA](p1-entry/ERRATA.md)。本包保留舊研究歷史，沒有覆寫舊報告或正式驗收狀態。

## 驗證分工

1. 新三份原生分題從同一原 BIN／Master 的有限視窗、指令與表重驗，並固定其舊來源 Git blob。
2. P0 的合成案例只驗離線 inspector 的有界政策，不作 Client 行為實驗。
3. 根整合檢查來源／交付 hash、原八個工作項、前緣數字、Server 候選身分、Markdown 連結及所有未閉合狀態，實際呼叫三份 verifier。
4. P2 的 `--require-native-mef` 與整包的 `--require-ready` 都保留資料有效但能力未滿足的 exit 2；沒有用證據 PASS 取代 ready。

本輪不例行重跑未變更的全部舊 ABI、生命期、Q119 與 world 工具；它們的來源及已發布 receipt 由固定 Git pin 採用。只核對會受這次整合影響的數字與邊界。

## 排程與正式狀態

沿用使用者指定的 `extra/roy1`；沒有新建 branch。未修改 Client、Lua、Server、原件、Task owner、task.json、RR／REQ 台帳或正式 FULL-PASS。Server 的出生、戰鬥、任務、服務、結算與保存列為開發／整合要求。

專案現有登入／創角／新手教學／進入廣場正流程仍優先；Q119 是 MEF 接續旅程的研究與驗收目標。重送、重連、故障與邊界要求保留，沒有因本輪分析而重新啟動暫緩測試。
