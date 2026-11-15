# 普通任務單項與全部放棄

## Client 靜態證據

任務列表的 `62EB70` 依兩個按鈕分流。單項經 `62EA30` 取任務列表的放棄文字索引 `0x1D`，產生事件 `F438D`，帶動作 0 和所選列。確認後 `62E930 → 62EC20 → 62ECE0` 讀選定 Quest ID，將命令和 ID 分別寫到相鄰的 WORD，再交傳輸層送四位元組。全部放棄由 `62EB70` 取索引 `0x1E`，產生 `F438E`，`62E930` 收到確認值 `0x6A7` 才呼叫 `6306A0`。後者只寫命令 WORD，明確傳給傳輸層長度 2。 [文字索引對照](../../kr-temp-roy/20261028-185456-chatgpt-web-roy-T16-74-KR-quest-command-notification-enum-tables-and-opcode-boundary.md)

| 動作 | C2S application payload | Server 成功回覆候選 |
|---|---|---|
| 放棄選定普通任務 | `0039 + QuestId:u16 LE` | `0064 + QuestId:u16 LE + status:u32 LE=0`，8 bytes |
| 全部放棄普通任務 | `003A`，2 bytes | `0065 + status:u32 LE=0`，6 bytes |

CClient 頂層表的 `+0x848／+0x858` 槽分別為 S2C `0064／0065`，共用 `494440 → 4FDA30` 送往 QuestOwner。其 `5020B0` 所設的回呼為 `5030C0／5035D0`。status 0 時，前者清除指定的一個登錄鍵，後者逐格清理 20 格；兩者都清除相關目標記錄並重建候選。指定 v2 的實機通知及刷新待驗。C2S `0064` 仍是獨立的狩獵場選擇。 [頂層分派](../../kr-temp-roy/20261030-032743-chatgpt-web-roy-T16-116-KR-Quest14-study4-S2C-0x74-quest-owner-demand-UI-end-to-end.md) · [QuestOwner 回呼](../../kr-temp-roy/20261030-101735-chatgpt-web-roy-T16-123-KR-Quest16-study4-S2C-0040-0064-0065-0072-0074-state-UI-native.md)

原版 KR BIN 與指定 v2 的版本 SHA 見 [登入恢復規格](ORDINARY-QUEST-READY-RESTORE.md)。依各自的 PE section 映射核對，下列指令視窗的內容逐位元組一致。

| VA 視窗 | 共同 SHA-256 |
|---|---|
| `62EA30+140` | `85a39055c49600187d860c55a3030268a4e701d8a24d7821c1d5ae9e6da1f409` |
| `62EB70+150` | `4ec2bb190e51ca3808d3773380e372a0a582aaf1b4a494d336dc19cfa602bb11` |
| `62E930+100` | `7e5cd7ef5c74c54b5a35912b45735467849c4ef0f73c58b4f326246c98d6d2b0` |
| `62EC20+C0` | `a360375e6d6cac3c6727a1929d3fb34a1a85e5f9233b1a6d2935d4b2a72bad23` |
| `62ECE0+85` | `d237bcf4cbadbb1a344718579e34c6fcbbaa9c2aee0c878cc1f66a81964f1ee3` |
| `6306A0+50` | `70f125eb04850a30e81c9b4afaef3ba00d6bba34a49e2edcfcc74e85ba846940` |
| `50211B+1A` | `e91d867d8e99761b860a0a706ae9b867bcab28d72ceed7e53542f1b35167ece3` |
| `5030C0+134` | `9d1a61e5088ffd31e6a59a2318d541e024447029ff2b14573f5530c0a3b45c8f` |
| `5035D0+119` | `0f8c8f5253271de5ba67b801e4320037c9b9d6528d2850bc80cf7ceb1c8169e5` |
| `4936EB+2E` | `3aae0aa0acee4ec45681564dd0fc27099ffe3e317ce2020be569ea5d406a491d` |
| `494440+82` | `d4a12bc9ab8dc2b740314edab430c4c17866971bbb6ecaea3a30d7eb65dea3f3` |
| `4FDA30+80` | `8971f7efd3f376924501e28533aedd383ac11425ad7554d3d7bd880839e73b74` |
| `C0DB08+8` | `f9727d49e6655c6e862d09addb3bbf24e70607b1da77fa13f2539e4fee66b9b0` |

## Server 作法

已載入正常遊玩場景，有效冒險團工作階段才處理。單項或全部移除 Accepted／Ready 普通任務。釋出清單空格，完成鍵、已入帳經驗與報酬，以及主線和教學保存點照原有記錄。收集材料使用重建 Server 的規則：同一寫入交易移除已放棄任務專用的背包材料，若仍有其他進行中任務使用同一 Product 就保留。寫入成功後才送清單及背包更新。重新接取依既有 NPC、等級、前置及容量檢查，進度重新開始。

在進行中的狩獵場，取消相關掉落配額、已出現但尚未拾取的專用掉落及互動箱，並停止其後續地圖的專用新怪群。已在場怪物繼續依當前戰鬥規則運作。共享怪群仍可由其餘 Accepted 任務保留。以上為 Server 選定規則，待核對指定 v2 畫面與輸入。

## 離線驗證

兩個全新帳號以一般及輪替配置走原版 BND。先在爾勒梅斯接 Q96／104 後全部放棄，確認清單清空、資產和主線保存點一致，再納入正常接取。Stage 465 首場拾得兩件 Q11 材料後，正常回廣場放棄 Q11。驗證釋出一格、扣除 Product 240，保留 Q38 待交及其材料。重登沒有恢復 Q11，回村重新接取時顯示註冊數量 0。兩條離線旅程均完成 87 項普通任務並保存 Q144、圖 199、Lv.19／333,742 EXP。

| 離線收據 | SHA-256 |
|---|---|
| 一般配置 | `e1c5678e54c3759049fea4d5710d7e13295a27b4cfc853346fc3197acf52265c` |
| 輪替配置 | `4345d1aebcbc857ebdba63170ab51df2a456eae3862973c691d34f7df37ca0c4` |

[指定 v2 批次驗收 AQ-32](../testing/S00-CONTENT-BATCH-TESTS.md)
