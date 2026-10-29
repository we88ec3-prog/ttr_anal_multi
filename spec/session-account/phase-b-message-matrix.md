# Phase B — KR 登入/選角 Server-facing 訊息契約矩陣

**不是原版封包序列**。目前只描述個別 Client 本地 producer、receiver 消費、frame 及資源依賴；表格順序是**設計與查證順序**，不代表已觀察的 C2S/S2C 實際執行順序。來源版本：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；TC 須獨立核對。

| 邊界／方向 | 本地 Client 證據 | 外框、連線、狀態 | Server 契約缺口 | 主責 RR |
|---|---|---|---|---|
| **NET-C2S local framing** | `0x807A70` 為 1A68；`0x807830` 為 0BBB；佇列 `0x8061A0` 存在 fallback | **已知局部** framing，尚無每種 login state 首筆實際 wire mode；slot key 與 pipeline 不可混用 | 首筆封包所屬 connection 與 mode；按階段的 frame 選擇 | T02 RR-0001/0004/0005 |
| **NET-S2C frame decode / delivery** | `0x807B40` parser → `0x8040A0` queue → `0x4930E0` channel2 dispatcher | receiver 1..4096、未知 marker 預設 header4；checksum 異常與 2633 未閉合 | Server 應發的具體 marker、checksum/壓縮前提，命令可被處理的狀態 | T02 RR-0001/0006/0007 |
| **AUTH C2S** | payload LE16 `0x00E8` 112 bytes 或 `0x000F` 214 bytes；已知字串槽位、部分常數 | **只有 Client 本地 payload geometry**，連線/啟動路徑未完全配對 | 分支選擇、codepage、opaque bytes、外框 mode、Server 可接受的最小欄位 | T03 RR-0003 |
| **AUTH S2C / choice/handoff** | `0x4C37A0` 局部 status +0x16 及寬字串 +2 消費者；群組 3-byte prefix + 10-byte rows；三條限定 Connect callsites | 尚未建立精確 S2C opcode、完整 payload、該次回覆是哪個 slot、是否導致切線 | 完整狀態/錯誤處理、回覆 layout、下一個 C2S 與連線的必要條件 | T03 RR-0003、T02 RR-0005/0007 |
| **Roster S2C** | handler index 2 的有效路徑：`65 + 53*N` bytes；另一 2-byte prefix consumer 不得混用 | 存在部分可用 UI 欄位，但不能從 copy 行為推定 Server 角色政策、下一次請求 | 65-byte prefix、record count/合法 ID 前提、第一次清單請求及 UI/state 準備條件 | T03 RR-0002 |
| **Selection C2S + S2C** | 先前有 C2S command `0x42` 的 4-byte 候選；S2C 回覆未確定 | **不得**假定 S2C opcode 0x43／按 request+1；實際 success/error 及 post-selection 初始化未知 | 精確兩方向 byte fields、handler、狀態前提、成功與錯誤的配對與後續初始化 | T03 RR-0002/0008、T02 RR-0007 |
| **Scene resource（非 packet）** | `extra/roy1` 已有 `(1001,1)→tutorial_start` 靜態 XML 和雙鍵查找/seq loader；`0x565720` 還供 EndCutScene 路徑使用 | **不是**已證的 S2C scene packet，也不證明新帳號都跑 tutorial | `0x42` 實際回覆 → state writer → scene key/loader 的真實連結 | T03 RR-0008 |

## S00 把 UNKNOWN 轉成可實作規格的檢查點

1. **消息身份**：Client 版本 SHA、方向（C2S 或 S2C）、真正的 payload command，與 frame marker 分開。未知請明說，不猜相對數值。
2. **連線條件**：Connection slot、pipeline、mode、業務 Session 狀態；區分本地 buffer/發送 API/實際 TCP wire。
3. **位元組佈局**：精確最短/最長長度、欄位型別/endianness、陣列個數、編碼、哪個狀態能接收；未證欄位保持 opaque。
4. **回覆配對**：給出 C2S 與其 S2C 成功/失敗 consumer 的 Native 函式/資料流依據；不把同命令整數當成同方向的結構。
5. **測試**：要求來源可追溯的正向/錯誤/分段收包測試；測試工具拒絕與 Client 原生行為須分開。
6. **可實作者驗證**：不看原始反組譯亦能填出資料包/事件，才可考慮將該**有界契約**交給實作 Agent；並不表示原版 Server 內部算法已確定。

來源：[SPEC-NET-0001](../protocol/SPEC-NET-0001.md)、[SPEC-NET-0002](../protocol/SPEC-NET-0002.md)、[SPEC-NET-0003](../protocol/SPEC-NET-0003.md)、[SPEC-AUTH-0001](SPEC-AUTH-0001.md)、[SPEC-CHAR-0001](SPEC-CHAR-0001.md)、[SPEC-FLOW-0001](SPEC-FLOW-0001.md)、[SPEC-SCENE-0001](../world/SPEC-SCENE-0001.md)。

在 [s00-roadmap.json](../../governance/s00-roadmap.json) 中，此表對應 B-NET、B-AUTH、B-CHAR、B-SCENE、B-CONTRACT。**目前所有 B 階段工作包仍有阻塞**，S00 不應為了填表而提升證據等級。
