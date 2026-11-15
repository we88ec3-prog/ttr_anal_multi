# 普通任務清單容量

## Client 接取入口

`630570` 逐格讀 `FB1170..FB1198` 的 20 個 WORD，查任務定義，只計入 type 1。涉及正常普通任務的列表操作經 `62ED60`，先要求該計數小於 20 才產生接取對話事件。滿 20 時改從 `FE5B0C` 取 0x1B 本機提示；相應名稱是 `kQuestListAlredyFull`。確認對話後 `636E10` 仍可能送出 `0036 + QuestId:u16`，此 sender 沒有重新計數。因此重建 Server 需要在提交時另核容量。

`502270` 接收 S2C `0040` 時，DWORD status 1 走文字索引 0x12，對應 `kAcceptQuestFailed`，不走 status 0 的登錄路徑。此處採它作 Server 容量拒絕的一般接取失敗回覆。滿格提示本身仍由前述 Client 按鈕分支提供。 [T16 文字索引表](../../kr-temp-roy/20261028-185456-chatgpt-web-roy-T16-74-KR-quest-command-notification-enum-tables-and-opcode-boundary.md) · [0040 分支](../../kr-temp-roy/20261030-101735-chatgpt-web-roy-T16-123-KR-Quest16-study4-S2C-0040-0064-0065-0072-0074-state-UI-native.md)

以下視窗依 KR BIN 與指定 v2 各自的 PE section 映射核對一致。 [版本 SHA-256](ORDINARY-QUEST-READY-RESTORE.md)

| 指令視窗 | 共同 SHA-256 |
|---|---|
| `630570+C0` | `fc963224c3e5813d94a0e587654dd3fc9192b8a1b22bdbc4b787e99930cb2196` |
| `62ED60+120` | `bd72e57fdde71412e8c7f8ed4ab99a88584a2d925f6fa688660d69884ebf9a09` |
| `636E10+C0` | `fe1717bf448314c98e12aa3697277872ebd4d58a6d715660aa75b78c017d053c` |
| `5026F0+95` | `29fa8ce15f9240e57d7b80eada8978415608c47ee26b44554fce20c765c19e8a` |

## Server 提交

共用容量為每冒險團 20 項。Accepted 與 Ready 都占一格，交付並保存為 Completed 後釋放。主線及教學使用各自的狀態，普通任務容量只計 `local_ordinary_quests`。接取須先通過現有場景、NPC、等級、前置與租約檢查，在同一筆寫入交易內檢查當前容量並保存。滿額的有效接取不新增任務或目標列，回 `0040` 的通用失敗狀態。既有超額存檔維持可完成與交付，降到 20 以下即可接取，重登發布仍受 Client 的 20 格限制。

新帳號離線路線分批接爾勒梅斯任務。保留跨關卡的對照任務先接，以及同 NPC 的主線優先與 Q136 後交付。階段驗收涵蓋填滿 20 格、交付後繼續接下一批，獨立的拒絕測試列待測。 [AQ-31](../testing/S00-CONTENT-BATCH-TESTS.md)

## 離線收據

一般及輪替配置各以全新帳號跑原版 BND。兩組都達到 20 個進行中任務，首場 Stage 465 後有 Ready 任務仍占格，第一次交付後確認降至 19。之後分批接全 55 項爾勒梅斯普通任務，連同馮德斯共完成 87 項並走到 Q144、圖 199、Lv.19／333,742 EXP。Release 建置與 504 項 HappyPath 合成通過。指定 v2 顯示仍待 AQ-31。

| 離線收據 | SHA-256 |
|---|---|
| 一般配置 | `e84f6e94abbb73f6abf283316f23a006925b7d1d43c32716e875f9b55c23c0e1` |
| 輪替配置 | `002f3ff56dfeb804de259cf72f71fc37c6d441a172cff2d4ffb20ff6a1ae4d67` |
