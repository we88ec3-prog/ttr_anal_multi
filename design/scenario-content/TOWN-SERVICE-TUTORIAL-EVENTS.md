# 世界地圖、技能與銀行教學事件

## 原表要求

| 任務 | 條件 | 原表目標 |
|---|---|---|
| Q2840 | 馮德斯、Lv.3、NPC 10002 接取及交付，無前置；AcceptAction type 3／param 2，CompleteAction type 1 | Content 2936 要求點擊世界地圖。對話為 31646／31653／31654，報酬 700 EXP 與一點公會地區名聲。 |
| Q2845 | 馮德斯、Lv.5、NPC 10014 接取及交付，無前置；AcceptAction type 3／param 5 | Content 2941 要求開啟技能學習。報酬 840 EXP 與一點公會地區名聲。 |
| Q2846 | 馮德斯、Lv.6、NPC 10014 接取及交付，前置 Q2845；AcceptAction type 1 | Content 2942 要求點選技能 Phase。報酬 840 EXP 與一點公會地區名聲。 |
| Q2857 | 爾勒梅斯、Lv.13、NPC 10007 接取、10013 交付；AcceptAction type 3／param 23 | Content 2953 與對話 31760 要求按「銀行利用」。報酬 1,910 EXP 與一點公會地區名聲。後續 Q2997 需要此任務完成。 |

任務資料沿用已核對的 KR QuestInfo、QuestTalk 及 Content。 [任務資料版本](PHINDOS-ORDINARY-QUEST-2843.md) · [銀行及市場教學](PHINDOS-BANK-VAULT.md)

## Client 路徑

使用 KR BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。世界地圖的本機事件 `F438F` 經 `5B7F80 → 5B6FA0 → 596E00` 顯示 `CWorldMapDialog`。銀行選項 12 由 `639530` 送本機事件 `F42E4`，經 `5B7928 → 596E00` 顯示 `CBankDialog`。技能師功能 25 的 `F432A` 開技能學習，功能 28 的 `F432C` 開技能 Phase。四個視窗的開啟回呼均指向同一任務事件發送器 `501650`。 [技能師選單與回報形狀](ALSMEER-TALENT-TRAINING.md)

| 任務 | 視窗 vtable 與 `+D0h` | 呼叫 `501650` | C2S 事件  | S2C 目標鍵 |
|---|---|---|---|---|
| Q2840 | `CWorldMapDialog C310BC → 649B40` | `649C9F`，EBX 由 `649B77` 設為 1 | `DF 00 18 0B 01 00` | 3936 |
| Q2845 | `CBuyPracticeActiveWnd C2C09C → 61BAA0` | `61BFAC`，事件 4 | `DF 00 1D 0B 04 00` | 3941 |
| Q2846 | `CBuySkillPhaseWnd C2ADB4 → 6158B0` | `615949`，事件 21 | `DF 00 1E 0B 15 00` | 3942 |
| Q2857 | `CBankDialog C2898C → 5F7D60` | `5F7E25`，事件 17 | `DF 00 29 0B 11 00` | 3953 |

上列開窗回呼的 VA 視窗與指定 v2（SHA-256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`）經 PE 映射逐位元組一致。

| VA＋十六進位長度 | SHA-256 |
|---|---|
| `649B40+178` | `5658d69fa1ed4c92e386657e583489debe6cdb217cca66dacfb05ecb6886ed79` |
| `61BAA0+52A` | `befe119289f6e16a0303e72784bf916c4d115bc1b9482f88dda527c4c6c7ce25` |
| `6158B0+A9` | `480068c5e23df5949bc31baf1a2d6249d2ebed728ed8935d041cbfdef4f62e6f` |
| `5F7D60+DC` | `d3b8c341bfcde1290a0860562a7aaccd9d9e09562e04e038245afb9e0af32ba2` |
| `501650+9A` | `73e1e8f063cd4ac7767623e2a0e04728e29966bfe72a789166f41745b97e34b0` |

世界地圖的 `0052` 清單查詢、技能購買的 `00D4`，以及銀行商店 `0086`、倉庫存取／換位 `008D／008E` 各有用途。四項教學的達成訊號是有對應 Accepted 目標的開窗回報。 [隊伍清單與退出](../../governance/client-variants/20261108-normal-village-entry/directory-list-and-leave.json) · [銀行選單與封包證據](PHINDOS-BANK-VAULT.md)

## Server 取證與判讀

在啟用本機進度工具的 Host 上，沿用已完成教學且持有伊莉西亞與蘋果的測試帳號，用正常流程進相應村莊。在進度頁「世界地圖／銀行操作觀察」選取單一步驟。每段最多 15 秒，使用目前正常遊戲連線，在記憶體中保留至多 128 筆 C2S 命令、應用長度、時間及明確形狀中的 Quest ID。一般輸入批次 `000A` 與心跳 `000C` 不列入。每段結果先另存，再開始下一段。工具不提交任務進度或改變場景。

四項已接入一般任務。Server 以原表等級、前置和接取 NPC 開放，登錄 `0042/subtype 11`，收到正常村莊中對應的 `00DF` 才保存 Ready。世界地圖及技能 Phase 在對應村莊判定。技能學習需在技能師、銀行需在使用銀行的 NPC 範圍。回原表交付 NPC 後按既有普通任務交易發 EXP，重登保存。公會地區名聲、Phase 切換及 Q2997 跨村交付另待開發。

兩組原版 BND 新帳號以 `--check-equipment-tutorial-chain` 完成 Q144 和 Q2853 後，按上表送出開窗回報，驗證四項接取、登錄、Ready、交付與重登保存。兩組最後均為 Lv.19／349,252 EXP。一般及輪替路線收據 SHA-256 分別為 `009745e9c5d482d1b82de06d6fd967a7d0bbe247eac35c3cf80bc1da171f2106` 與 `9b6bfaec5b395820fa29a886a3b5b3bc073f1c73c6efedd1b9accdc54c076db1`。指定 v2 實機見 AQ-28／29 與 SK-P14。 [驗收清單](../testing/S00-CONTENT-BATCH-TESTS.md)
