# 本地登入運行觀察與測試授權

狀態：GAME_RUNTIME_OBSERVATION，僅限已修改工作副本；不是原始 KR Client 或官方 Server 相容性證明。

## 授權與環境

使用者在本對話要求「我現在開啟遊戲程式，請幫我監聽」，之後回報「已按登入」，並補充「原本專案內可能有要求agent不能開遊戲，但我允許你開遊戲測試」。授權限定指定工作副本與本機 Server 的啟動、操作及連線測試；不包含附加、注入、修改原始程式或對官方服務連線。

- 工作副本：`Tartaros.ip-zh-tw-only-v2.exe`，SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
- 靜態研究基準 KR BIN：SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。與實際測試 EXE **不是相同檔案**；REQ target 是研究基準，不能將副本觀察外推原件。
- Windows 本機 loopback；當時 Server checkout `284c1df16707834c5df64976ff8d1307e1906ae4`，工作目錄乾淨；程序為 `Tartaros.Server.Host`。
- S00 後續開發基準 `b2ff7074819986e0176cb1d434ac063ed3887857`；Server 後續開發基準 `b9f3bd6`，已新增 opt-in 診斷入口，不能將舊程序結果套用到新版開啟診斷後的狀態。

## 重現與已觀察

1. 使用者啟動指定 EXE，使用 Git 專案當時的預設 Host 啟動方式。
2. 使用者按登入；2026-11-01 00:35:47.5369401 +08:00 的 OS TCP snapshot 顯示遊戲 `127.0.0.1:59122 -> 127.0.0.1:8415`，狀態 `SynSent`。
3. 00:35:49.7617048 +08:00 snapshot 已無該 SynSent 項；此抽樣不能判定 RST、timeout 或特定 Winsock error。
4. 同期 Host 僅監聽 `127.0.0.1:5080`；`GET /health` 回報 `phase=C00-diagnostic-only`、`gameListener=false`、`originalClientCompatibility=not-verified`。對照當時 Program.cs，確實沒有遊戲 TCP listener。

結論：本次登入未建立遊戲 TCP 連線；尚未到達登入 payload、C02 驗證或 S2C 回覆。無法據此判定帳密是否正確、實際使用 E8/000F、first-wire 或登入後畫面。

證據是 2 秒週期 OS 連線狀態抽樣與 health，不是 pcap、遊戲記憶體或原始 Server capture。原始連線紀錄留在操作者本機 `runtime-observations/2026-11-01/connections-003515.jsonl`，不含帳密。遊戲 log.txt 被獨占，未成功讀取。遊戲畫面結果未獨立驗收。

## 去重與修正驗收

追加 REQ-0001 的 runtime discovery，不另建同義需求。此為登入服務未接入的交付缺口，不宣稱 C02 已有 bug；REQ-0009 既有觀測需求繼續沿用。

1. 先在實際目的端口提供 opt-in 本地接收並驗證 Accept/RX；診斷接收不等於遊戲服務可用。
2. E85 限定 C2S：raw `1A68` payload 1..4092，XOR `0BBB` payload 1..4090；拆包/黏包、checksum、方向及錯誤隔離皆需驗證，不挪用 S2C 的 4096 上限。
3. shape candidate 不構成 build、Client slot/scene 或帳密身分；C02 只能從經審核的 request 接線，且與 Admin 共用明確指定的 provider、ban/lockout 與 exact Session lease。
4. M2（實際請求進 C02）與 M3（正確 S2C 後 Client 下一畫面）獨立記錄；M4 角色建立、教學戰鬥、任務完成與廣場仍須接續實作及工作副本 runtime 驗收。

E85 verifier 在本機原始 BIN 重跑：90 checks PASS；只限 byte/合成範圍，沒有升級 T01 FULL-PASS、RR ACCEPTED、SPEC STABLE 或 NativeContractAdmission。原始來源在 `kr-extra-roy/20261101-chatgpt-web-roy-E85-C04-E2b-KR-login-C2S-transport-frame-contract.md`，verifier 同前綴 `-verify.py`。
