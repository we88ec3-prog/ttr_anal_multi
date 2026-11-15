# 正常技能學習的封包與入帳規格

## 原版 Client 請求

技能學習視窗的確認事件 `F43B5` 經 `61BFD0` 檢查使用者選擇 `06A7`，進入 `61D360`。該函式取視窗當前角色、從待學習清單逐列讀 Practice ID，從該角色的既有學習資料找到目前等級，再寫入選擇等級減去已學等級的差值。客戶端一次最多送十列。

| C→S `00D4` 偏移 | 讀取方式 | 意義 |
|---|---|---|
| +0 | u16 LE | `00D4` |
| +2 | u8 | 角色索引 |
| +3 + 5 × n | u32 LE | Practice ID |
| +7 + 5 × n | u8 | 本次要求增加的等級 |
| 全長 | 3 + 5 × n | 1～10 列，同一角色 |

以伊希莉亞 Practice 50 增加一級為例，應用層形狀為 `D4 00 04 32 00 00 00 01`。金額、熟練度、角色等級和最終目標等級都由 Server 依當前狀態及原表判定。實機若同時選了多個項目，請逐列保留原始差值。

## 原版 Client 結果與快照

`4E21CF` 在 player-state 表 `+0x944` 登記 `4E4AB0`，對應 S→C `0128`。該入口把原封包指標包裝成 UI 事件 `F428F`，經 `59B9E0 → 59DCC0 → 61D6B0` 交付技能學習視窗。視窗從 `+2` 讀取 u32 結果旗標。零值走成功訊息 `kLearnPractice_Success`，並從 `+7` 讀取 DWORD 寫到全域狀態 `F94254`。該欄的精確貨幣語意與 `+6` 尚未核實。錯誤分支可確認 bit `0x04` 選 `kLearnPractice_Invalid_PracticeID`，bit `0x80` 選 `kLearnPractice_Insufficient_SkillPoint`，bit `0x100` 選 `kLearnPractice_Insufficient_SkillExp`，bit `0x200` 選 `kLearnPractice_Insufficient_Money`。多 bit 的顯示依視窗內判斷順序。

同表另有 `0126` 重新接收角色已學 Practice，`0127` 接收配置列。快取重建會收集兩個集合。普通技能等級的同一 grant 只應貢獻一次。另一個確認發送器 `411BD0` 用 `00D6` 和六位元組列，結果入口 `0129` 進另一個 UI 事件 `F4290`。兩條確認路徑各自驗收。 [快取的原件範圍](../../governance/client-variants/20261107-skill-level-dispatch/README.md)

## 早期技能規則

以下以 KR 的 Practice 原表為準。SkillExp 是學習熟練度成本，與角色升級 EXP、特性點數及戰鬥中的 SP 分開。表內是每一級的成本。從目前已學等級連升多級須逐級查表。既有 Server 教學授予的等級 1 屬現行起始配置。

| 角色 | Practice → Active | 學 1 級（角色等級／SkillExp） | 升 2 級（角色等級／SkillExp） |
|---|---|---|---|
| 索瑪 | 1 → 1、2 → 2 | 1／100 | 10／75 |
| 索瑪 | 3 → 3 | 1／100 | 11／150 |
| 伊希莉亞 | 49 → 29、50 → 30 | 1／100 | 10／75 |
| 伊希莉亞 | 52 → 31 | 1／100 | 11／150 |
| 伊希莉亞 | 53 → 32 | 5／100 | 15／150 |

爾勒梅斯 NPC 10014 的 Q2852 與 Q2853 均為 Lv.11。原表依序要求完成 Q2850、Q2852，兩項 AcceptAction 分別為 type 3／param 28、type 3／param 6。前者主題是氣充電，後者是特性訓練。技能介面開啟、實際學習與普通任務條件的事件應分開記錄。Q2852／Q2853 的觸發規則仍需核對。

## 主線結算的熟練度顯示

原始 `UI/Component.stp` 的 `Component/Mission_Complete_Dlg.FTC`（解碼 SHA-256 `942286bd04a3118a798dde092c839bf359d8c9af77d9f25cf44f47023d7baf5e`）列出第一組獎勵控制項。主線的 `6BA220` 把標題 EID 11100 綁到視窗 `+F4`，數值 EID 11110 綁到 `+F8`。 `6BA400` 把標題換成 UIText 索引 `0x2C6`（`kSkillExp`），並將狀態 `FE18F8+0x32` 的 DWORD 轉成第一列的十進位數字。 `4C4550` 從 `0022/type 0` 應用負載 `+0x12` 複製到該位置。這個欄位已核對到主線結算的熟練度顯示，實際入帳與一般狩獵場 type 2 的顯示須分開查。

同版 `QuestInfo.xml` 的 RewardsEtc type 3 在 Q119、Q122、Q124、Q132 為 40，Q136 為 100，Q138、Q140、Q142、Q144 為 150。這些是熟練度來源的優先候選，仍須將任務欄位語意、實際入帳時機及結算發送次序與上述 UI 接起來，避免在結算與交付各增加一次。

## Server 接續與驗收

- 正常城鎮取證已可在本機頁分開記錄「只開技能學習視窗」與「確認技能學習」。解析符合形狀的 `00D4` 為角色與 Practice 差值列表。取證沿用 15 秒、最多 128 筆的既有城鎮窗口，保留 opcode、時間與長度，並使普通封包處理繼續進行。
- 入帳需建立各角色的 Practice、熟練度與特性點數的來源和持久化。依帳號的有效連線與角色資格檢查同批逐列及逐級條件，再用同一筆交易扣資源和更新已學等級。對同份已提交狀態同時發布 UI 快取及戰鬥使用的等級。重登和切角讀取同一版本，配置與普通學習各自保存。
- 下一個可走的正常技能驗收以伊希莉亞 Practice 50 從 1 級升到 2 級為例。先核對 Lv.10、實際熟練度來源及結果欄，再對照快捷列、普通戰鬥消耗與重登。較高階特性需附各自的 prerequisites 與 ScriptLevel 證據。現有正常流程仍沿用原有技能授權與等級。

## 指紋

原版 KR BIN 及指定 v2 的整檔 SHA 見 [版本指紋](../scenario-content/BAG-CAPACITY-EXPANSION.md)。按兩個 PE 的各自區段映射核對下列位元組相同。

| VA＋長度（十六進位） | SHA-256 |
|---|---|
| `61BFD0+5F0` | `2f98a9683cd14378ed46f60a68ed99c689c2004c91757201bf4ff2005814fcc8` |
| `61D360+1C0` | `a285112aedd0f63b6bda5dda1e786c85e33c6da4a390df4e67a752ec0833e5cf` |
| `4E1DA0+8F0` | `2a51166201c0600273c7904934b4a7ecacd8dbd4a22b24e783d879aab49a9092` |
| `4E4AB0+D0` | `f594f29d1d2b34a9ba518119ae56e89c61abb621b1264da65e151abfe0525a8e` |
| `61D6B0+650` | `56a1c21ec047fe05363490b32cee7888f1aba2e78cca5c63d2f483260b1ee6dd` |
| `411BD0+100` | `adfea0e2233a9a107a2109150faa1b35ff341f9c6d2dfebf43c32b43eaca3222` |
| `6BA220+9A` | `a9eaf7c6ab380987647ad2d5feb546a37c0226e83ff82b1329fbda7145f28e5c` |
| `6BA400+230` | `c1621f1c1dee295d21cf82ea71096645f887d269fa4c25aa687f1ace775dfde9` |
| `4C4550+E0` | `04466f4f5c1c65e37f0e2362b927bd845a9237a1b8d46b953e2af040fc4d6861` |

原始解碼 `Table/Skill/PracticeList.xml` SHA-256 `b837e6c695730b9fe597a9af6d18872323f015a20dc519beb4dbc8b70ac71c97`，`Table/Skill/Active/isla_wslash.xml` 為 `7dd414597137b6b8402c0b690a86f836e768c1d8ccb142c1be893f56c1b678df`，`Table/QuestInfo.xml` 為 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。`CommonMessages.xml` 的學習訊息見原始索引表起始位址 `D66C1C`，表項間距 12 bytes。
