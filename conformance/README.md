# S00 Conformance — Phase B 離線合成測試

本批 TEST-NET-0001/0002、TEST-CHAR-0001、TEST-AUTH-0001 的狀態一律為 **OFFLINE_SYNTHETIC**。由 KR Client 局部原生分析的 **PARTIAL** 主張推導出人工測試資料。它們**不是**真實封包捕獲、不代表可登入 Server、不代表完整原版 Client 相容性。

| 子集 | 測試內容 | 明確排除 |
| --- | --- | --- |
| [Network](protocol/kr-framing-vectors.json) | 1A68/0BBB 本地外框、XOR、校驗值、分片/黏包、收送長度差異 | mode 切換完整時序、0x2633、未知 marker 的原生錯誤路徑 |
| [Roster](character/kr-roster-vectors.json) | 65+53*N 資料形狀、有限 UI 欄位位置、尾端不足整筆 | 真實角色政策、65-byte prefix 內容、UI 生命週期與選角成功 |
| [Authentication](session/kr-auth-vectors.json) | E8/000F 本地 payload 長度/slot 分隔與已觀察固定欄位 | 官方認證、ACP、登入回覆及切線 |

```powershell
python -B -m unittest discover -s conformance/protocol -p "test_*.py" -v
python -B -m unittest discover -s conformance/character -p "test_*.py" -v
python -B -m unittest discover -s conformance/session -p "test_*.py" -v
```

[測試登錄](test-index.json)。`RUNTIME`（Server 可運作）、`CONFORMANCE`（規格相符）、`CLIENT_COMPATIBILITY`（原版 Client 實際測試）互不取代。對非支援 marker／checksum mismatch，測試器採**保守拒絕**，並非宣稱原生 Client 也這麼做。

## T02 收發與連線盤點的靜態矩陣測試

新增 [TEST-NET-0003](protocol/kr-network-boundary-matrix.json)：核對舊 KR 靜態呼叫的 `port/slot/pipeline` 分離、發送端 `WSASend` 路徑、接收端經 `4930E0` 命令分派的**整理結果**。對應 [Python unittest](protocol/test_kr_network_boundary_matrix.py) 隨 protocol test discovery 執行。此測試登錄狀態沿用 `OFFLINE_SYNTHETIC`，但內容本身是**來源派生的靜態矩陣**，不代表跑過 socket、連上 Server、擷取到任何真實封包或驗證過公式以外的程序。
