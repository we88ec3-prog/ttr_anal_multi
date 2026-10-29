# SPEC-NET-0002 — KR Client 連線槽、API 與發送路徑（有界）

狀態：**DRAFT / PARTIAL**。KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此為 Client 觀察到的路徑，不是官方 Server 網路部署標準。來源 [T02 盤點](T02-EVIDENCE-INVENTORY.md)。

## 已觀察的連線參數（805AD0/806AD0 系列）

`806AD0` 的呼叫參數依次為 `address, port, slot, pipeline`（第 3 個參數用作 network+0x18 的連線查表鍵，第 4 個寫入 connection+0xA080）。所見舊版 KR 靜態呼叫：

| 呼叫 VA | Port（十進位） | Slot（outbound key） | Pipeline（inbound queue） | 提醒 |
|---|---:|---:|---:|---|
| 0x49575B | 8415 | 1 | 2 | 本分支回傳 connection，儲存於 Client+BF60 |
| 0x4957EA | 8416 | 0 | 2 | 儲存於 Client+BF64 |
| 0x495803 | 8414 | 2 | 2 | 儲存於 Client+BF68 |

三條呼叫屬 **限定已找到的靜態初始化路徑**；非全部連線、即時 DNS/endpoint、順序保證、正式官方服務拓樸。不能解讀 `slot=0` 或 `pipeline=2` 為玩家/房主身份。對一般業務而言，Server 端的識別應使用顯式 Session/連線上下文，而非猜測 Client slot 語意。

## 出站路徑（已由舊研究追到 API）

```text
Client producer (example 0x5452C0, C2S command 0x000A)
  → [FBA854] vtable+0x10 / 0x8069A0(key=slot, payload, len)
  → network+0x18 map lookup → connection
  → 0x8060D0 (local payload copy)
  → 0x806060 (append conn+0xA074 queue; count +A078)
  → 0x8061A0 (drain, mode +A02C, conditional frame writer)
     → 0x807830 0BBB with fallback 0x807A70 1A68
  → 0x804A40 (connection flush)
  → network vtable+0x0C / 0x8068B0
  → WSASend (overlapped; WSA_IO_PENDING 997 branch)
```

`8061A0` 完成是把 queued payload **搬入 framed connection buffer**，不是 OS 發送成功；`WSASend` 呼叫也不證明遠端 Server 實收/ACK。另有 `806FC0` 的 shutdown、closesocket 清理路徑；失敗處理、重送/重連的完整協定不在證據涵蓋範圍。程式中 `A078` 是已觀察的 linked list 計數；`A0A4` gate 不是已確認的佇列筆數（見 T01 T16-69 勘誤）。

本契約不要求第三方 Server 依照上述 **Client 內部資料結構、佇列或 IOCP** 實作；Server 應對等遵守已確認的**封包位元組與交換時序**（當後者補齊），可使用任何合理的通訊框架。

## 連線「可聲稱」與「不可聲稱」

- 可描述 KR Client 的限定 `Connect`、connection map 和 C2S→WSASend 靜態路徑。
- 尚**不可**發布「第一次封包必須採某一 marker」、「8414/8415/8416 皆為必要的 Server listen port」、「正式切線會關閉哪些 socket」、「斷線後重試幾次」等無佐證行為。
- `+A02C` 直接存取限定掃描顯示初始化寫入 2，但不能排除別名/間接修改；不影響 0/nonzero fallback 的限定契約。
- 登入回覆、選服、角色清單等順序由 T03 S00 SPEC-AUTH/SPEC-CHAR 補齊，不在 T02 猜測。

證據主張：`CLM-NET-0003`、`CLM-NET-0005`、`CLM-NET-0007`（PARTIAL）。來源 `kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt` 與 `kr/evidence/bcc93c2f8128b12d86fd1e296198e4e1735fd410336510b15c58415b6a0c9ced.txt`，Git blob 見 [盤點](T02-EVIDENCE-INVENTORY.md)。缺口 `GAP-NET-0001`、`GAP-NET-0002`。初步對照測試 `TEST-NET-0003` 只驗證檔案中整理的靜態映射。
