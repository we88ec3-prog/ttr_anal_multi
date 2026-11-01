# 工作副本登入：credential 前處理與本機認證接線交付

2026-11-01；S00 的增量交付紀錄，接續 REQ-0001／REQ-0009、I39／I40。不另建 RR、CLM、GAP 或官方 wire 規則。原始 Server 與原版 Client 相容性仍未驗收。

## 發現與證據範圍

既存同 SHA 偽碼：`0x4A31B0/0x4A3360` 經 `0x47F540 -> 0x733DD0 -> 0x46E3C0/0x46E270` 形成登入第二文字槽。`0x733DD0` 對 16 bytes 使用 `%02x`；`0x733C30` 初始狀態 `67452301/EFCDAB89/98BADCFE/10325476`，`0x809BA0` 所見輪函數、旋轉與常數對應 MD5。故 **ASCII → MD5 → 32 lower-hex** 是可供隔離工程實驗的來源推論；不是新 T01 FULL-PASS、原版 Server 密碼政策或已觀察的實際 wire 值。CP_ACP runtime 非 ASCII 語意仍未知，實驗拒絕非可列印 ASCII。

偽碼來源為 `kr-bulk-roy/<KR SHA>/functions/{0x4a31b0,0x4a3360,0x47f540,0x733dd0,0x733c30,0x46e3c0,0x46e270,0x809ba0}.c`，其完整 raw Evidence 與索引仍是原權威。這些快取原本標為 saved-unreviewed，不能因本次引用升格。REA 本輪 open 已確認原件 SHA；第一手 instruction 查詢在 300 秒後逾時，沒有成功的新指令證據；已停止重試並關閉該分析 session。

原始 BIN 與指定測試 EXE 的 **10 個選定 VA 範圍** bytes 相同，摘要在 [selected byte ranges](2026-11-01-credential-selected-byte-ranges.json)。原件與工作副本 SHA 仍不同；範圍相同不代表完整函式／整個 Client 語意相同。可重現：

```text
python -B governance/verify_working_copy_login_ranges.py ORIGINAL_BIN WORKING_COPY_EXE
```

## 必要的 Server 設計選擇

不能直接拿傳輸摘要字串去驗證「原始使用者密碼」所產生的既有 PBKDF2 hash。隔離實驗的新帳號，建立時把 printable-ASCII 原始密碼轉成 Client wire secret，再以既有 C02 salt／PBKDF2 保護該 secret。MD5 是相容文字表示推論，不是儲存保護演算法；摘要文字具有憑證性質，不得進日誌。

這是 **NEW_ACCOUNT_OPT_IN_EXPERIMENTAL_POLICY**，不會／不能恢復舊密碼、不猜帳號採用哪種 policy、不以 raw password fallback、不重寫原帳號 hash。現有 schema 未記錄逐帳號 profile，因此目前只能由操作者明確選用新的測試帳號／專用 SQLite DB，不可宣稱整個舊帳號庫已可用。正式多 profile／重設／轉換需獨立 policy 與 migration 審查。

管理後台的預設建立方式不變；明確設定新帳號 profile 後，頁面顯示它是工作副本本機測試用途。Gateway 和管理後台必須指定同一個已存在 SQLite v2；不自動 create/migrate、不得 fallback InMemory，PostgreSQL 此模式暫不開放。原版 codec admission 仍 OFF。

## 現有交付與驗收界線

- 有界 per-socket C2S writer decode／E8、0F 純語法容器 → ASCII lower-hex 檢查 → C02 provider／ban／lockout → Server GUID SessionLease。
- 每 socket 一次 attempt、最多4連線／2個並行 auth、16KiB RX budget、登入前15秒 idle、之後60秒；provider 失敗不回成功，EOF／舊連線／shutdown 使用 exact lease 清理。這些是本機測試政策，非官方 Server 規則。
- Host 啟動前核對指定工作副本 EXE 檔案 SHA；這不是 TCP peer 或正在執行程序的遠端 attestation。
- 安全日誌只用固定 metadata 類別，區分 `LOCAL_WORKING_COPY_AUTH_ONLY`；每個 queue-drained batch flush，能在服務仍執行時檢查。
- 本輪合成 Host integration 已驗：實際 WEB 新建帳號 → TCP E8 合成 frame → 同 SQLite Session → EOF 清理 → WEB 永久停權後拒絕同憑證。測試不輸出原始／wire secret，未使用原遊戲帳號庫。
- 此項是 **OFFLINE_SYNTHETIC_HOST_INTEGRATION PASS**。實際工作副本 M2 **NOT_RUN**、M3 正確回覆／下一畫面 **NOT_RUN**、角色建立、教學與廣場仍 **NOT_DONE**。Computer Use 啟動兩次逾時，未透過其他方法繞過，也沒有附加／注入。

## 下一個必要工作

1. 經已授權的實際工作副本操作，確認本服務確實接收其 C2S 變體及 credential 前處理假設；不傾倒密碼來「確認」。
2. 依 SPEC-AUTH-0001 的 `0x13` consumer 做安全有界 candidate writer：名稱終止在 status+0x16 前，保守最多9 UTF-16 units；notice 明確空終止；+0x87 槽最多4 ASCII bytes＋NUL；其餘欄位須作明示 Server policy，不冒稱原版 ticket。
3. groupCount=0 的固定0x92 extent可用於獨立候選測試，但不是有可選伺服器的成功畫面。非空 group/child ID 必須與資源表、child+9、selection mapping 一起證實；`+2..3` 不得臆稱 port。S2C0x7A 與0x13不是同布局。
4. 保持 M2 auth、M3 reply/UI、M4 roster/create、教學完成與廣場控制可操作的證據獨立。不得因本次合成認證通過就跳過最後三段或宣布可玩。

本文件包含公開可重現分析及接口設計，不包含私有 Server 實作碼、DB、完整封包或憑證。
