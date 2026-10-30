# KR Bulk 集中品質檢查 — 第十一段（2026-10-29）

**PARTIAL / DIRECT-BIN-BYTE-RECHECK / NOT FULL-PASS**

## 本次新實測

直接由當次本地 `/mnt/data/Tartaros.bin` 以唯讀方式取出 bytes，實際 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。GitHub connector 讀回 `extra/roy2` 第二段 `shared/reviews/KR-BULK-CENTRAL-QA-ROUND-02-20261029.md` 中四個 48-byte 原生入口記錄，與當次 BIN 的原始 bytes **192/192 bytes 完全相符**。

| VA | raw offset | 比對範圍 | 比對結果 |
|---|---|---:|---|
| `0x004DF510` | `0x0DE910` | 48 bytes | EXACT |
| `0x004F49A0` | `0x0F3DA0` | 48 bytes | EXACT |
| `0x004F3D80` | `0x0F3180` | 48 bytes | EXACT |
| `0x0055D7E0` | `0x15CBE0` | 48 bytes | EXACT |

PE .text VA/raw 映射基準：image base `0x400000`，section RVA `0x1000`、raw base `0x400`，公式 `raw = VA - 0x400000 - 0x1000 + 0x400`。所有地址均位於 .text 映射範圍內。

## 資料取得限制再次確認

本地執行 `git ls-remote https://github.com/we88ec3-prog/ttr_anal_multi.git refs/heads/extra/roy2` 回傳 `Could not resolve host: github.com`；容器並無完整 bulk checkout。上述 192 bytes 是 **BIN 與 GitHub 第二段 Markdown 記錄**的交叉比對，不是 111,054 個函式的全量 SHA 檢驗，也不是反編譯檔與 raw JSON 的全文 hash 核對。

## 對所有 Task 的可用結論

- 可引用：上述四個入口的 `VA → raw` 映射及 48-byte 原生片段在指定 BIN SHA 下正確。
- 不可引用為：完整函式邊界／完整 CFG、函式語意、wire opcode、Server 原版演算法、全部反編譯正確性、FULL-PASS。
- 若需提升有界主張至正式 `shared/verified-knowledge`，仍由 T01 逐主張查證及裁決。

## 下一段真正阻塞

`kr-bulk-roy/<SHA>/index.jsonl` 的 Git blob 已存在但本環境沒有可用的完整檔案內容；需在可下載完整 checkout 的環境，以已提交 `kr_bulk_preflight.py` 與 `bulk_integrity_audit.py` 執行實際逐筆索引／檔案 SHA 檢查。

本段沒有修改 `kr-bulk-roy`、其他 Task、`main` 或 T01 正式驗收狀態。
