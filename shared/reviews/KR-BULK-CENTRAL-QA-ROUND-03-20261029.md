# KR Bulk 集中品質檢查 — 第三段：索引／查詢器品質（2026-10-29）

**PARTIAL / SOURCE-CODE-AUDIT / NOT FULL-PASS**。目標是跨 Task 資料查詢可靠性，不是原版遊戲功能語意驗收；不覆寫 T01、其他 Task 或任何凍結原始 bulk 資料。

## 1. 已實際讀取的來源

- `kr-bulk-roy/lookup.py`，Git blob `6a9f6a363a1ba2dceb8b01414d40aa91328d2cac`，分支 `extra/roy2`。
- `kr-bulk-roy/review_status.py`，Git blob `44ca546d60e002a8d1ff3fc55fa48183f7568905`。
- `shared/reviews/KR-BULK-CENTRAL-QA-ROUND-02-20261029.md`，Git blob `6cc2e8e54a32df5df9d96cbe2f231169b3c96a27`。
- 本地只讀 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、12,472,320 bytes。重新核對 PE ImageBase `0x400000`、四入口的前 16 bytes 與第二段報告一致。
- GitHub connector 對完整 `index.jsonl` 的內容擷取未成功（大型檔案讀回為空）；容器無法連線 GitHub 進行 clone。**因此本段沒有全量 index→functions→raw SHA256 成功率，不提供虛構分母或通過率。**

## 2. 靜態程式碼品質缺口（不是已觀察到的資料毀損）

| ID | 位置及實際邏輯 | 風險／影響 | 證據等級 | 建議驗收 |
|---|---|---|---|---|
| KR-BULK-QA-301 | `lookup.py` 每次 `for line in f` 掃描整份 `index.jsonl`，並對成功行做 `json.loads` | 每次查詢 O(N)，大量 Task 交錯查詢可能重複讀取 111,054 筆 | 原碼確認；未量測效能 | 離線 benchmark 單次／100 次查詢耗時 |
| KR-BULK-QA-302 | `except json.JSONDecodeError: continue` 未限制在最後一行 | 中間行損毀也被靜默略過，可能輸出 `not-saved-yet` | 原碼確認；**未發現實際損毀行** | 插入中間損毀行 fixture，應明確報錯 |
| KR-BULK-QA-303 | 同地址若多個 `ok`，`(match is None or r.get('status')=='ok')` 令最後一個 `ok` 覆寫前者 | 同地址不同 SHA 或內容衝突不會明確回報 | 原碼確認；**未確認存在重複** | 同地址不同 hash fixture 必須列衝突 |
| KR-BULK-QA-304 | 偽碼 `path=(out/... ).resolve(); assert path.is_relative_to(out.resolve())`；Evidence `reference_path=(out/reference)` 或 `root.parent/reference` 未用相同方式界定根目錄 | 來源路徑仍需防止無意越界／不同來源混入；雖有 SHA 比對，但 SHA 不是來源範圍驗收 | 原碼確認；未驗證實際越界 | 檢查 `.. `、絕對路徑、符號連結及 seed 例外白名單 |
| KR-BULK-QA-305 | `assert` 用於 SHA／路徑／輸入上限檢查 | `python -O` 會移除 assert，不應依賴其作完整性必經防線 | Python 語意與原碼確認；未在正式檔案執行 `-O` | 以明確 exceptions 取代關鍵 assert |
| KR-BULK-QA-306 | `review_status.py` 對 `review-status.jsonl.gz` 逐行查詢 | 每次 O(N)，但有固定的未審核狀態標記，避免一律 FULL-PASS | 原碼確認；效能未測 | 可選獨立快取，凍結資料不更改 |
| KR-BULK-QA-307 | `lookup.py` 會校驗偽碼與 raw/seed Evidence SHA256 | **既有正向防護**，但只在被查詢的單筆成功執行時觸發 | 原碼確認，非全量實行 | 對完整 checkout 跑批次全量 hash 驗證 |

## 3. 索引無法直接讀回的明確阻塞

需要在具完整 repository checkout 的本地環境，對 `kr-bulk-roy/<BIN SHA>/index.jsonl` 逐行掃描，輸出以下**真實**結果：總行數／可解析 JSON 行數／錯誤行號／唯一地址數／重複地址及其 SHA 差異／狀態分布／缺少 pseudocode 或 raw 檔案／每一筆 SHA 比對結果。對 `seed_evidence` 與 `batch_path` 先依原 schema 區分根路徑，不得把 seed 視為 bulk 檔案。

本分支的下一步應開發**唯讀**驗證器，從完整 checkout 產生 `summary.json` 與 `exceptions.jsonl`，且工具本身要能用人工建立的局部 fixture 測試；**在尚未執行前不得聲稱已驗證 111,054 筆。**

## 4. 原件對第二段的再驗證

PE ImageBase 直接讀到 `0x400000`；四個地址映射為：

| VA | raw | 重新讀取的前 16 bytes |
|---|---|---|
| `0x004DF510` | `0x0DE910` | `55 8b ec 6a ff 68 a4 44 94 00 64 a1 00 00 00 00` |
| `0x004F49A0` | `0x0F3DA0` | `55 8b ec 6a ff 68 d6 47 92 00 64 a1 00 00 00 00` |
| `0x004F3D80` | `0x0F3180` | `55 8b ec 6a ff 68 a2 75 92 00 64 a1 00 00 00 00` |
| `0x0055D7E0` | `0x15CBE0` | `55 8b ec 51 a1 f0 1e fe 00 53 56 8b 30 57 6a 00` |

僅證實入口映射／短指令片段，**沒有**完成 CFG／callee／writer／事件語意的第二次完整複驗。

## 5. 各 Task 的正確採用方式

1. 查詢 `kr-bulk-roy` 可作函式導航，但 `not-saved-yet` 不是「BIN 不存在該程式碼」的證據，尤其要先排除索引 parse 失敗與 SHA 阻塞。
2. 若 `lookup.py` 成功回傳 SHA 檢驗，僅表示**被查詢那一筆衍生文字／Evidence bytes** 符合索引，不表示其機器碼、parser 或 gameplay 已被 T01 FULL-PASS。
3. 不應由本稽核對 `shared/verified-knowledge/`、`kr/tasks/`、`shared/catalog.json` 作任何改動；正式接收仍須遵守 T01 精確主張政策。

## 6. 下一段入口

P0：在可讀取全量 Git tree 的環境實行 integrity audit，取代「預期 111,054」為實際觀察分母；比較凍結 `validation.json` 與重跑差異。P1：修正查詢器前以 fixture 重現靜默漏資料與同地址衝突；變更應是獨立 PR／提案，而非直接修改 frozen 來源。
