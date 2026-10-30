# T01 — RR 分支全部併入 main 與驗收整合收據（2026-10-30）

本次經使用者明確要求，先比對並合併所有當時 GitHub 存在的 rr/* 分支，再繼續 T01 原生驗收與來源整合。倉庫：we88ec3-prog/ttr_anal_multi，版本 KR ；TC 不互借證據。

## Git graph 真實合併

起始 main f272da2f503949a3b813729b4b80592720f8ea70；當時 20 個 rr/* 分支中 19 個原本已為 main 的祖先。唯一 divergent 的 rr/t02/roy/rr-0007（head 2e13993164b5058523e6edc9ce1a3b3214ac3ff8）用雙父 merge commit 5c97f7367425df86538c357fb7d59052635f0cc3 合入主線，parents 分別 f272da2f503949a3b813729b4b80592720f8ea70 和 2e13993164b5058523e6edc9ce1a3b3214ac3ff8。E60 的 main 原稿與來源分支 blob 相同 2ca02f3870d79d3217abf39b8651c43226eb77d6，無合併內容衝突，因此使用 main 相同 tree，不覆寫主線已有台帳或 T01 調查。這是有真實親代關係的 merge，而不是檔案複製偽裝。

處理期間 T03 的 rr/t03/roy/rr-0003-progress 與 rr/t03/roy/rr-0003-submit 由另一個工作流程透過 PR #44 / #45 合到 main，及 T03 RR-0002 claim 也由其他流程更新。T01 沒有重做、倒退或改寫這些來源 RR 狀態。最後 2026-10-30 本輪重新列出 **22 個 rr/* 分支並逐一 compare main...branch，22/22 均 ahead_by=0**，表示各分支提交已在 main 的祖先圖中。分支本身未刪除，保留可稽核歷史。將來出現的新分支需要重新核對，不代表自動持續同步。

## T01 收件／檢驗結果

| RR | 主責 | 此輪狀態 | 主要 T01 原稿與限制 |
|---|---|---|---|
| RR-0001 | T02 | IN_REVIEW | E57 0BBB/1A68 framing，T01 既有 t01-20261030-rr0001-rr0004-bounded-r2；首個實際 S2C 未知 |
| RR-0003 | T03 | IN_REVIEW | 原 T03 auth 完整報告原樣補回 main；T01 新 t01-20261030-rr0003-t03-bounded-r2，三項 CLM-AUTH 局部 PARTIAL；E8 tail/codepage runtime 尚未閉合 |
| RR-0004 | T02 | IN_REVIEW | E58 A02C/fallback，T01 既有有限 R2；全域 indirect writer unknown |
| RR-0005 | T02 | ACCEPTED | S00 有界接受 E56，但 T01 不因此 FULL-PASS；GAP 仍需按實際台帳單獨判 |
| RR-0006 | T02 | IN_REVIEW | E59 compressed / checksum / pool，T01 multi-branch R2；無原始 Server runtime 或全文 R3 |
| RR-0007 | T02 | IN_REVIEW | E60 command2/LOGIN scene command13/7A/scene cmd42 的 bounded R2，T01 新審核記錄；S2C42 不等於已證選角批准 |
| RR-0002 | T03 | CLAIMED | 不由 T01 代原作者研究或認定已交付 |
| RR-0008 | T03 | QUEUED | 不由 T01 認領 |

T01 原生靜態原件 KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。兩份新原稿來源 R0 補齊：
- RR-0007 E60 原作者 blob 2ca02f3870d79d3217abf39b8651c43226eb77d6；正式來源 SRC-0472、CLM-NET-0029..0031 PARTIAL。
- RR-0003 T03 auth 原作者 blob 64c8c1a3429ae6ff177a84dee0d08ad69dba0b17；正式來源 SRC-0473、CLM-AUTH-0003..0005 PARTIAL。

舊 R0/R1/R2、既有 FULL-PASS 和 FAILED/NEEDS_FIX 來源決議全部保留。不擅自標任一新 RR ACCEPTED、修復他人 README 退回、SPEC_STABLE、GAP_RESOLVED、Server 已開發或 Client 已可玩。

## 機械檢查與已知缺口

- 將 7 項過時的 S00 regression tests 舊版「所有 RR QUEUED／無審查紀錄」假設隔離到 TemporaryDirectory synthetic baseline，沒有回滾或竄改真實 RR 台帳；修復後 commit f272da2f503949a3b813729b4b80592720f8ea70 的 GitHub Actions run 41014116669 **success**。
- 後續 RR-0003 正式 R0/R2、來源與主張索引、IN_REVIEW 派工與衍生 inbox 均已提交；commit 2ed7b61f24d67289777f5081fb0ea5edf5d47607 的 GitHub Actions run 41015561515 **success**。這只是 schema/hash/機械一致性，不是原生語意或遊戲互通測試。
- T01 本輪只有精確有界來源驗收；五項 IN_REVIEW 仍由 S00 依各自 RR acceptance criteria 決定 ACCEPTED/NEEDS_REVISION。S00 DRAFT SPEC、Client wire/Server 設計、跨功能以及待遊玩四類缺口不可互相推卸；沒有新的 FULL-PASS 共用知識。
- 正式權威狀態為最新 main 的 research/requests/index.json、research/intake/index.json、research/claims/index.json；本文件只保留本批收據，不作第二份 RR 台帳。

## 繼續驗收的明確入口

1. 先查看最新 main、新 SUBMITTED 與 T01/各 Task READY_FOR_REVIEW，確認作者 blob、原件版本，避免在 T01 R2 限定後擅自整篇 FULL-PASS。
2. S00 優先審核 RR-0001/0003/0004/0006/0007 對 SPEC-AUTH/NET/CHAR/FLOW 的必要 client-facing 介面；未閉合原版 wire/Server 觸發僅保留 UNKNOWN、適用條件與明確跨 Task 補證。
3. 機械 CI 綠燈與原版 Server 真實可玩仍屬獨立驗收；不要用來源數量、合併分支數或合成測試代替。
