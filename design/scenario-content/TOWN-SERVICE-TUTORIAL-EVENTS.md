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

四項已接入一般任務。Server 以原表等級、前置和接取 NPC 開放，登錄 `0042/subtype 11`，收到正常村莊中對應的 `00DF` 才保存 Ready。世界地圖及技能 Phase 在對應村莊判定。技能學習需在技能師、銀行需在使用銀行的 NPC 範圍。回原表交付 NPC 後按既有普通任務交易發 EXP，重登保存。Q2857 完成後可接 Q2997，延續至廣場市場交付，再接下列 Q2858。公會地區名聲與 Phase 切換另列。 [Q2997 跨城鎮交付](PHINDOS-BANK-VAULT.md#q2997-跨城鎮交付)

兩組原版 BND 新帳號以 `--check-equipment-tutorial-chain` 完成 Q144 和 Q2853 後，按上表送出開窗回報，驗證四項接取、登錄、Ready、交付與重登保存。兩組最後均為 Lv.19／349,252 EXP。一般及輪替路線收據 SHA-256 分別為 `009745e9c5d482d1b82de06d6fd967a7d0bbe247eac35c3cf80bc1da171f2106` 與 `9b6bfaec5b395820fa29a886a3b5b3bc073f1c73c6efedd1b9accdc54c076db1`。指定 v2 實機見 AQ-28／29 與 SK-P14。 [驗收清單](../testing/S00-CONTENT-BATCH-TESTS.md)

## Q2858 艾特爾市場開窗

同版 `QuestInfo.xml` 的 Q2858 為 Town 5、Lv.13、NPC 10101 接取及交付，前置 Q2997。AcceptAction 為 type 3／param 24，CompleteAction 為 type 1。Content 2954 要求點廣場艾特爾市場的市場按鈕，`QuestTalk.xml` 的接取／途中／交付為 33060／31770／31777。獎勵為 1,910 EXP 與一點公會地區名聲。 [原表版本](PHINDOS-BANK-VAULT.md#爾勒梅斯銀行與市場教學)

按鈕回呼 `6B2B80` 的 `6B2C5C` 比對控制項 `+94h`，在 `6B2C8B` 建立 `F42F0` 本機事件。廣場 UI `5B0760` 接事件，由 `5B0781` 顯示 owner `+308h` 的框架。`5B26C0 → 5B2FF0 → 5B36D0 → 69CE00` 架設 `CAuctionFrameWnd`，vtable `C39C64+0D0h` 指向 `69D700`。在 `69D791` 推入 18、`69D793` 呼叫 `501650`，之後才進入 `6A0110` 的市場清單初始化。

原版 KR 與指定 v2 的下列視窗依各自 PE section 映射，內容一致。

| VA＋十六進位長度 | SHA-256 |
|---|---|
| `6B2C5C+46` | `91729679ef499985de5992ed619924aba5929873166e0c11898ef57e4bcdede2` |
| `5B0760+26` | `35613a4ddf594dca3a14f6f66b4899a885ee97a647f0fcf70c6d56974898f672` |
| `69CE00+55` | `2b4583c533560373b28c93c87f4d462b3d2c60d217f8840d687eab928a2fc31e` |
| `C39D34+4` | `aa1de08ee7de6cb96b956c4b590296b96c0a191e6c420b281b194c842a7c422e` |
| `69D761+43` | `b57f887136fd58785b3873eaed0757cc82cb9e6eed009b500c7dd6c1613d3f8e` |

Server 接取後登錄 `0042/subtype 11` 的目標 3954，事件 18。Client 回報為 `DF 00 2A 0B 12 00`。Server 要求角色在正常廣場、位於 NPC 10101 互動範圍，且已有 Accepted，才保存 Ready 並回覆 `0041`／`0045`。正常對話交付保存完成旗標及 1,910 EXP。這段開窗及任務交付不扣道具或貨幣。市場清單載入、刊登、交易及公會地區名聲另待開發。 [AQ-34 實機驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

標準與輪替兩條使用原版 BND 的新帳號旅程完成 Q144、Q2857 與 Q2997，再於廣場步行至 10101 接取、送出開窗回報並交付 Q2858。兩條均驗證 Ready 及完成狀態重登保存，開窗及交付時背包和貨幣一致，最後為 Lv.19／353,072 EXP。收據的 `equipmentTutorialChain.earlyUiTraining.marketIntroduction.marketTraining` 記錄該段，整份收據 SHA-256 分別為 `f5f26864e4a422a1ac0cf100c3ee79e0595b8ec2551266c7c04f598c532a75d6` 和 `9d413b47609561cfe0a1e7a037549916da61e85bb2fc810e0aec28b231f459ad`。 [重現參數](PHINDOS-BANK-VAULT.md#q2997-跨城鎮交付)

## Q2841 說明集導覽

同版 `QuestInfo.xml` 的 Q2841 為 Town 5、Lv.13，NPC 10101 接取及交付，要求 Q2840 與 Q2858 均已完成。CompleteAction 為 type 1。Content 2937 要求點選選單「說明」，`QuestTalk.xml` 取接取／途中／交付 48226／48229／48230。獎勵為 1,910 EXP 與一點公會地區名聲。對話提到可從「說明」閱讀指南。任務原表沒有道具獎勵。 [原表版本](PHINDOS-BANK-VAULT.md#爾勒梅斯銀行與市場教學)

`5A2570` 建立 `UICachingData<198, CHelpDlg>`，在 `5A25DA` 寫入 `CHelpDlg` vtable `C3A7FC`。該表 `+D0h` 位於 `C3A8CC`，指向 `6A3810`。回呼在 `6A38A1` 推入事件 2，於 `6A38A3` 呼叫共用開窗任務回報函式 `501650`。原版 KR 與指定 v2 依各自 PE section 映射比對，以下範圍一致。

| VA＋十六進位長度 | SHA-256 |
|---|---|
| `5A25C4+41` | `8903614f80739496a4045b64ad2e40c461bb2f2b09d6d6036f57e0e0b6f9741f` |
| `C3A8CC+4` | `e63751c6c8093a75a79667dcb5ef6a91589188cf2ddcf60a5a0d6d51783967f4` |
| `6A3810+A0` | `20fd956a1d96195d21165d2398a759a117b9743ea8089c7ff41341542a0a5a14` |

Server 接取後傳 `0042/subtype 11` 登錄目標 3937、事件 2。正常廣場載入完成後，已接取者可在廣場任意位置送 `DF 00 19 0B 02 00`。達成時保存 Ready，回覆 `0041`／`0045`，再走回 NPC 10101 交付並保存 1,910 EXP。前置以帳號已完成的兩筆任務紀錄查核。公會地區名聲及其他場景的開窗驗收另列。 [AQ-35 實機驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

標準與輪替兩條原版 BND 新帳號離線流程由 Q144 繼續完成 Q2840、Q2858 及 Q2841。兩條均從市場 NPC 接取，步行離開 NPC 再提交事件，核對 Ready、交付與重登保存，背包及貨幣一致。結束時均為 Lv.19／354,982 EXP。收據位於 `equipmentTutorialChain.earlyUiTraining.marketIntroduction.marketTraining.helpTraining`，兩份 SHA-256 為 `aee388fbd96f6cc44ab6bcd12537532d0f4ced927511db751bef2b1469496990` 與 `82b5ee6131527ce37136b83a654c63b40d47e474bdb1f300618605996272c79f`。 [重現參數](PHINDOS-BANK-VAULT.md#q2997-跨城鎮交付)

## Q2996 挑戰任務負責官介紹

同版 `QuestInfo.xml` 的 Q2996 為 Town 2、Lv.11，前置 Q2853。NPC 10014 接取，NPC 10069 交付。AcceptAction、CompleteAction 均為 type 1。Content 3069 指示與「웨스티」對話。獎勵為 2,890 EXP 與一點公會地區名聲。 `QuestTalk.xml` 的 31721／33058／31722 分別是接取、途中及交付對話。`TalkTable/02_Lenart.xml` 的 33058 指向廣場的 NPC。`_TownList.xml` 的 Town 5 清單包含 10069，`npctable.xml` 確認其為 TYPE 5 挑戰任務負責官，該表 SHA-256 為 `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d`。 [QuestInfo 版本及同類跨城教學](PHINDOS-BANK-VAULT.md#q2997-跨城鎮交付)

Server 沿用 Q2997 的跨城對話流程。爾勒梅斯的 NPC 10014 受理 `0036` 接取，傳 `0042/subtype 11` 登錄目標 4069。可用世界地圖同次登入回廣場，保留已接取的目標。到 NPC 10069 的互動範圍送 `001C/subtype 3`，保存 Ready 並更新任務進度。再由同 NPC 交付，發布完成旗標、前置快照及 2,890 EXP。獎勵入帳至接取角色，背包和錢包維持原值。公會地區名聲待開發。Q2851 以 Q2996 為前置，另外要求點「挑戰入場」。挑戰開窗的回報及副本流程仍需取證。 [AQ-36 實機驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

標準與輪替新帳號使用原版 BND 離線跑至 Q144，經既有教學後，實走爾勒梅斯接取與直接返回廣場。兩條均核對目標跨城保留、Ready 重登回填、交付入帳及重登後完成，最後為 Lv.20／357,872 EXP。收據位於 `equipmentTutorialChain.earlyUiTraining.marketIntroduction.marketTraining.helpTraining.challengeIntroduction`，兩份 SHA-256 分別為 `30988f6b6719ee68049e37174bd3fb6ce4b293eaec3244b0f5dcbabf8be60381` 與 `a67ca508252cdf578b4225c90c81d957009001b5f2d2f97abcf64d11077eee55`。 [重現參數](PHINDOS-BANK-VAULT.md#q2997-跨城鎮交付)

Q2851 的 QuestInfo Content 2947 指向 NPC 10069 的「挑戰入場」。既有事件 15 呼叫點 `63930A` 受 `6392C9` 的 `0x2884` 比較約束，符合 `npctable.xml` 的 10372（TYPE 6）。原版 KR／指定 v2 的 `6392C6+49` 視窗相同，SHA-256 為 `c1e9ad09483806ee640cc220db7c079d6a84d9d9c6b46c108aedcee3fefb23af`。Q2851 仍需核對 10069 的 TYPE 5 按鈕路徑及其回報。
