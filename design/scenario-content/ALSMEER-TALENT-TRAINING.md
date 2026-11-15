# 爾勒梅斯 Q2853 特性訓練

KR `QuestInfo.xml`（SHA-256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`）列 Q2853 為 Town 2、Lv.11、type 1／subtype 4，前置 Q2852。接取及交付 NPC 均是 10014。AcceptAction 為 type 3／param 6，CompleteAction 為 type 1，獎勵為 2,890 EXP 與 1 點公會地區名聲。Content 2949 要求按技能師的「特性學習」。原文按鈕說明含馮德斯字樣，任務欄位指定 Town 2。KR `npctable.xml`（SHA-256 `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d`）列 NPC 10014 為 TYPE 2。

## 原版 Client 開窗及任務回報

1. TYPE 2 的功能 26 經選單槽 `+140h` 調用 `639CE0`，發本機事件 `F432B`。UI `5B7750 → 59B420 → 59A6C0` 顯示 owner `+1E8h` 的視窗。初始化 `598D07 → 59FCB0 → 5A30B0 → 40F9A0` 建立 vtable `BF342C`、RTTI `CBuyPracticeTalentWnd`。功能 25 的 `F432A` 開普通技能學習，功能 28 的 `F432C` 開技能 Phase 視窗。
2. 特性視窗的 vtable `+D0h` 是 `410250`。開窗初始化在 `4107A6` 推入 11，再由 `4107A8` 呼叫 `501650`。後者遍歷 24-byte 目標記錄，要求 `+4:u16=11`、`+12:u32=11`、`+8:i16 < +6:i16`，取 `+20:u16` 為回報鍵。鍵非零且 sender gate 允許時送六個位元組 `00DF:u16, QuestKey:u16, UiEvent:u16`。Q2853 此列為 `DF 00 25 0B 0B 00`。同一 sender 可用於其他 UI／動作，必須同時比對任務鍵、事件及場景。
3. `0042` 的 `4B2190 → 53D840` 接收器針對 subtype 11 將 header `+2:u16` 寫到記錄 `+20`；entry `+1:u8`、`+7:u16`、`+9:u8`、`+10:u8` 分別寫到記錄 `+4`、`+12`、`+8`、`+6`；entry `+4:u16` 存畫面進度使用的目標鍵。以 Content 2949 加 1000 的既有 Server 規則得到 3949。Q2853 的 Accepted 登錄是 `42 00 25 0B 00 0B 00 00 6D 0F 00 0B 00 00 01`。

## Server 流程

走正常村莊、角色等級與前置驗證後，先保存 Accepted，再發 `0040`、`0042`。重登從已存進度重新發布目標。收到 Q2853 的 `00DF`／事件 11 時，需在爾勒梅斯正常場景、技能師互動範圍，且資料庫進度為 Accepted。成功保存 Ready 後發 `0041` 更新目標 3949 為 1，並送 `0045`。回 NPC 10014 用既有 `001C/type 3` 普通任務交付，交易提交一次 2,890 EXP 與完成旗標。公會地區名聲待公會功能接入。

使用 `--fresh-alsmeer-journey --check-early-ordinary-quests --check-refine-materials --check-remaining-base-skills --check-equipment-tutorial-chain`，以兩組原版 BND 新帳號驗證正常至 Q144，接著完成 Q2849、Q2850、Q2852 與 Q2853。隔離測試送出上列原版形狀的開窗回報，核對已接取及 Ready 重登後皆可繼續、交付一次 2,890 EXP、完成後維持主線及 Lv.19／344,962 EXP。兩路線收據 SHA-256 分別為 `745e1835b6eedd2839b8311dc682966f7dbd115a9ba11a1674acef33240b0900` 與 `3c163ea40c9b3fc5eee1fdb598fb00e7e7f60ca7cde16a6f721172e444c19271`。指定 v2 開窗、回報及畫面仍待 SK-P13 實機。

特性購買由同一視窗的確認操作獨立發送。`410FE0` 在確認識別為 `6A7h` 時走 `411BD0`。C2S `00D6` header 為命令 u16、角色 u8、預設索引 u8，後接最多十筆 `Practice:u32 + 變更量:i16`。成功 `0129` 由 `411CD0` 讀 status `+2:u32`、角色 `+6:u8`、預設 `+7:u8`、已用點數 `+8:u8`、熟練度 `+0C:u32`。視窗 `4107F0` 讀角色記錄 `+D4h` 為點數上限，並以預設 `+18h` 加暫存調整作已用點數。角色記錄由 `0002` 的 53-byte roster row `+2Fh:u8` 或 `005C+22h:u8` 供應。原服如何給點、預設購買後的完整發布及戰鬥效果另待驗證。開窗任務不歸入購買。

## 證據位置

原版 BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，指定 v2 EXE SHA-256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。以下 VA 視窗依各自 PE section 映射，兩版逐位元組一致。既存 Ghidra 結果與原指令交叉比對，範圍限下列流程。

| VA＋十六進位長度 | SHA-256 |
|---|---|
| `637488+65` | `0db66bdf40c2f8382c56aa7e8f4bb8cef40114bdb181e69674915bde712d2091` |
| `639CE0+35` | `3d91f1ca7fccffff7fc7ccd9cdfef0e6d1c655bb61c359b190d6b90f24325de2` |
| `59A6C0+42` | `f0d6712c6ae4cf00b42f14e958decedc0e97dc1e7258e9a0a9d0af421453d020` |
| `410250+560` | `24aca1f98ae6bf412d27e87558742c95ff96dc006b2a4a652c445fc739201a43` |
| `501650+9A` | `73e1e8f063cd4ac7767623e2a0e04728e29966bfe72a789166f41745b97e34b0` |
| `4B2190+157` | `21f9b118f6cae405da945b7cea8a26b8c63bb5ec4b7a60d3feeb21d48d8efdbd` |
| `53D840+1F0` | `9402cbe8c8b9fe36bd82fa667e5dc322be9620e526c6b1895a39c125dd340e06` |
| `4D4150+4D` | `6a579dcbf1504b8db20b0865abf134521ef85fb7728a178c7ab80968ac03f9d4` |
| `4D41A0+68` | `c43bcf8b6c740fbc98ace87cd466f5ab8f507be119a2186bbe0405bbb36a3a7e` |
| `411BD0+100` | `adfea0e2233a9a107a2109150faa1b35ff341f9c6d2dfebf43c32b43eaca3222` |
| `411CD0+100` | `0e1b2fdc435984767c626ede59595e9cb2978605bc614b3772964b1abc41c450` |

[普通任務接取與交付](PHINDOS-ORDINARY-QUEST-2843.md) · [學習協定](../runtime-content/SKILL-PRACTICE-PROTOCOL.md) · [SK-P13 實機驗收](../testing/S00-CONTENT-BATCH-TESTS.md)
