# SPEC-NET-0003 — KR Client 收包、佇列與命令分派（有界）

狀態：**DRAFT / PARTIAL**。KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。這是已見 Client 內部接收路徑的**邊界契約**，不是 Server 業務請求／回覆表。來源 [T02 盤點](T02-EVIDENCE-INVENTORY.md)。

## 有界資料流

```text
WSARecv completion / IOCP (0x806CF0; network virtual+4)
    → 0x807B40 frame parser
    → [known frames] decoded payload (frame marker removed)
    → 0x489920 pipeline object access; conn+A080 determines class
    → 0x8040A0 enqueues payload node in FC10D0
    → CClient vtable+0x30 / 0x490FE0
    → 0x804740 consumes 0..5 channels via 0x804100
    → CTCPInterface/CClient callback 0x4930E0(conn, payload, len, channel)
    → channel==2 path reads payload first WORD as command index
    → CClient processor / scene dispatcher
    → scene-specific table B (0x4C4670) else common table A (0x4FDA30)
```

`4930E0` 只在 `channel==2` 執行所述 handler 路徑；**不能**把 `channel 2` 稱為 actor2、某個 Server 埠或命令值 2。舊 KR 已找到的三條 Connect 呼叫均把此 pipeline 參數設為 2，但其他渠道、分支或執行時切線未窮盡。

## Frame marker、command、table 層次

- 外框 `0x1A68/0x0BBB/0x22D7/0x2633` 的 parser 規則在 [SPEC-NET-0001](SPEC-NET-0001.md)。
- 解析後 payload 起始的 **LE16 word** 才是已觀察的應用命令索引（至少 channel2 這條路径）。**不能**將 `0x0BBB` 誤當業務命令；也不能把相同數值的 C2S 與 S2C 命令視為相同封包。
- CClient 層有 3029 個預設 command 槽與 197 筆明示覆寫（來源限定為其已核對的建構/註冊範圍）。
- Scene 層至少分成**場景專屬表 B**、**通用表 A**、以及後續 virtual fallback。場景可改變 handler；不能僅憑 command 值推測收到後必然導致相同 UI 或戰鬥效果。
- `807B40` 0BBB checksum 不符時跳過部分 copy 但仍進共同處理段，完整 node pool 初值與最終丟棄語意尚未通過必要驗證。未知 marker 沒在觀察到的比較鏈直接拒絕；離線工具的 UnsupportedMarker 並不是 Client 行為。

## 對獨立 Server 的用法

Server 對 Client 送 S2C 時，必須先決定待確認的 frame 類型，再封裝 payload command+fields；而不是直接送本地 processor 表的 memory address。相反地，Server 收 C2S 時先拆外框再解 payload；**應按每條業務命令的獨立方向別契約作解析**。目前尚缺登入/選角實際 S2C 時序與異常狀態，不可稱為已完成 Gateway 相容性規格。

來源 `CLM-NET-0004`、`CLM-NET-0006`、`CLM-NET-0008`（PARTIAL）；`kr/evidence/4a64b51809c87fe6c8bab24f033fb4c94964a8e403e861be22e8210d3f639b8e.txt`；T09 後續修正索引只作補充，不提升本批新原生語意等級。缺口 `GAP-NET-0001`、`GAP-NET-0003`；驗證 `TEST-NET-0003` 僅為整理後的離線一致性測試。
