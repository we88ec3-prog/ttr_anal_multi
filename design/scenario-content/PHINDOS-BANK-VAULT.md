# 馮德斯銀行道具倉庫

## 第二、三村銀行

同一份原始 `ShopInfo.xml`（SHA-256 `2c61fee77c6a8b24bdb350d1639818a2d9f871562c9b97eb51a3d15416699b0b`）列出三村的銀行商店。Town 1／2／3 分別為 ShopNo 70／71／72，三者都是 TYPE 7、NPC 10013，唯一商品皆為 Product 23232。`0086` 只帶 NPC ID，因此 Server 以當前村莊解析實際店號，並用該村 NPC 10013 的站位檢查互動距離。 [三村市場配置](TOWN-MARKETS.md)

啟用三村市場設定與交易服務時，第二、三村各自在載入時發布帳號共用倉庫。支援支票買賣、道具存取、換位及已配置費率的擴充。角色跨村後須完成該村初始化，支票買賣須重新開啟當地銀行貨單。原有資產資料庫結構沿用。以上為 Server 候選，實機驗收見 TS-16。

銀行 NPC 10013 與 ShopNo 70 共用角色身分。倉庫由 `FUI::CBankDialog`（vtable `C2898C`）與 `FUI::CBankInsideWindow`（`C28BE4`）管理。此處先核對普通背包與倉庫之間的道具存取。 [城鎮服務與原表](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

NPC 10013 的 NPC.TYPE 是 1。初始化 `637335..63739B` 將選項 12 加入 TYPE 1，`63877A` 把選項 12 的槽 `+108h` 綁到 `639530`。該函式在 `639557..63955E` 建立本機事件 `F42E4`，UI 派送表 `5B7B70/5B7AC0` 將它分派至 `5B7928`，由 `596E00` 顯示 owner +234h 的視窗。`5B531B → 5BC160 → 5C0620` 建立的正是該銀行視窗。銀行開窗回呼用 `501650(17)` 回報對應已接取的任務。 [Q2857 開窗事件](TOWN-SERVICE-TUTORIAL-EVENTS.md)

### 爾勒梅斯銀行與市場教學

同版 `QuestInfo.xml` 的 Q2857 為 Lv.13、10007 接取、10013 交付，AcceptAction type 3／param 23。Content 2953 和對話 31760 都要求按「銀行利用」。Server 收到開窗事件便可以讓任務進入 Ready，後續向銀行 NPC 交付。倉庫存取和銀行商店走各自的交易流程。

Q2997 需先完成 Q2857，Lv.13 由爾勒梅斯 NPC 10013 接取、10101 交付。`QuestInfo.xml`（解碼 SHA-256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`）列 Town 2、type 1／subtype 4、AcceptAction 1、CompleteAction 1。Content 3070 要求和艾特爾市場交談。`QuestTalk.xml` 為接取、途中和交付分別登錄 31767、31768、31769。`_TownList.xml`（`bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660`）把 10101 列於 Town 5 廣場 1。`npctable.xml`（`a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d`）列 TYPE 9。Q2857 與 Q2997 各有 1,910 EXP 及一點公會地區名聲。 [任務來源版本](ALSMEER-ORDINARY-COLLECTION-EXPANSION.md)

### Q2997 跨城鎮交付

沿用普通任務 `0036` 接取，在爾勒梅斯的銀行 NPC 10013 驗證等級、互動範圍與 Q2857 已完成。`0040` 確認接取，`0042` 登錄自訂文字目標 4070（Content 3070 加 1000 的既有映射），數量 0／1。已接取狀態從 SQLite 回填，重登進泳池廣場圖 1088 後仍可交付。

Server 沿用已核對的普通任務互動 `001C/type 3`。由目標所在城鎮及 Server 當前座標驗證 NPC 10101，第一次有效互動保存 Ready，發布 `0041`／`0045`。後續交付在既有普通任務交易內存入完成旗標及接取角色的 1,910 EXP，回覆 `0046`、前置快照與角色經驗。廣場 Town context 5 與地圖 1088 分別處理，座標沿用現行廣場 NPC 配置。這兩步是 Server 的交付規則，指定 v2 的對話和任務標記待驗。完成後可向 10101 接 Q2858 的市場開窗教學。 [Q2858 開窗事件](TOWN-SERVICE-TUTORIAL-EVENTS.md#q2858-艾特爾市場開窗)

重跑 `--fresh-alsmeer-journey`，加上 `--check-early-ordinary-quests --check-refine-materials --check-remaining-base-skills --check-equipment-tutorial-chain --check-native-equipment-windows`。標準及輪替新帳號以原版 BND 完成 Q144，並在銀行教學完成後步行接取、重登回廣場、步行找到市場 NPC 交付。核對廣場 `006F` 保留先前全部旗標並增補 Q2997、交付後角色 Lv.19／351,162 EXP，以及再次重登的保存結果。`equipmentTutorialChain.earlyUiTraining.marketIntroduction` 收據 SHA-256 分別為 `3dc4b2803dda0501ca7b43ada404460f64c7b8088949aa9883b8c814773caee1` 和 `4fe1752f467a6313fd7298e0c8441019394697ace7e0a0bd5af1e9f095317471`。 [AQ-33 實機驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

新增正常村莊直接返回廣場，可在同一登入內交付 Q2997。 [村莊返回廣場的按鈕與協定](VILLAGE-SQUARE-RETURN.md)

## C2S 道具存取

`60233E..602347` 的背包路徑向 `4A44E0` 傳入方向 1。`5F9D60` 先從倉庫 backing store 讀道具，`5F9E52 → 5FA0F0` 驗背包位置後在 `5FA211..5FA218` 傳入方向 2。兩條路徑使用同一個 8-byte 格式。

| Payload 偏移 | 欄位 |
|---|---|
| +0 u16 | `008D` |
| +2 u8 | 1 存入倉庫，2 取回背包 |
| +3 u8 | 背包種類 1 |
| +4 u8 | 背包格位 1–100 |
| +5 u16 | 倉庫格位，`(頁號 − 1) × 80 + 頁內格位`，Client 讀取邊界為 1–480 |
| +7 u8 | 搬移數量 |

`4A4560` 另組裝 6-byte `008E`，+2 u16 是來源格位，+4 u16 是目的格位，兩者使用相同的頁號公式。`5F995F..5F99B7` 檢查第一格有物品和非零數量後送出。`5F9A6F..5F9AA9` 則由 `5093A0` 在指定頁找第一個空格，將該格寫為第二欄。封包沒有數量欄。

本機候選將整疊移入空格。若目的格已有物品則交換兩格，保留各自數量和物品欄位。兩格在同一筆交易提交，回覆一包 `00C3`。這是候選換位規則，原版 Server 對已占用目的格的行為待驗。

已卸下的獨立裝備也走 `008D`。每次搬一件，使用空的目的格，保留 Server 裝備實例 ID、Product 和兩個物品欄位。Q140 的實際任務所得購裝旅程驗證爾勒梅斯存入、重登前往馮德斯、載入時發布原格、取回原實例及後續售出；存取期間 LeeLoo 與 Battle Point 不變。 [單人離線收據](ALSMEER-SINGLE-PLAYER-ACCEPTANCE.md)

2026-11-18 補驗換下的護甲。新帳號正常完成 Q144 後，先從兩村鐵匠購入伊希莉亞護甲 Product 11250／11262，直接換裝並重登。將換下的 11250 存入馮德斯銀行第 79 格，再重登、正常建隊到爾勒梅斯，核對場景啟用前發布原倉庫格。取回後重新穿上該件，再換回 11262，核對兩件獨立 ID、物品欄位及背包交換位置。最後卸下售出兩件，原有背包與倉庫格位保留，LeeLoo 為兩次買賣後的預期餘額。此流程使用現行 NPC 商店、穿戴及倉庫協定。

離線收據 `equipmentSwapReceipt` 記錄 `replacedArmorStoredAcrossVillages=true`、`vaultSlot=79` 與 `withdrawnArmorWornAgain=true`。完整收據 SHA-256 為 `f8af14b5134e9e0b8dbbc97815424ee70643b3b75f4712a4e9b310b2f003a4fe`。指定 v2 的拖曳、銀行分頁與取回後換裝待 TS-18 批次驗收。

## S2C 倉庫格位

player-state 表 `4E1FCF..4E1FFF` 登錄 `00C2 → 4E2600 → 50A890`、`00C3 → 4E2620 → 50A9B0`。初始 `00C2` 有 4-byte 頭部，+2 u16 寫入倉庫容量 `+50B8h`，其值由 `5FA3E8..5FA410` 用來限制每頁可用格數。`00C3` 有 2-byte 頭部，直接接格位資料。

兩者的列均為 17 bytes，列內 +0 u16 格位，+2 和 +6 各 u32 物品原欄位，+10 至 +11 未見讀取，+12 u8 數量，+13 u32 Product 鍵。數量為零清格，其餘經 `509260` 查商品表並填槽，兩種包均發出 `F4364` 刷新事件。候選 raw frame 上限 4,096 bytes，每包最多組裝 240 列。容量超過單包時，應先發容量，再用格位增量分批傳送，實際顯示待驗。

Server 已可在同一筆 SQLite 交易內變更共用背包與倉庫，保留物品欄位，並讀回重開資料庫後的格位。初始 80 格是本機候選配置，原版起始容量待查。候選支援移入空格及同道具、同物品欄位的堆疊，沿用目前背包每種道具一格與每格最多 255 件的規則。交易回傳兩邊的新數量，LeeLoo、Battle Point 保持原值。

本機候選在馮德斯村收到已知的 `0043` 載入回報後，從同一份資料庫快照取出背包、錢包與倉庫。在載入結束 `0024` 前依序送出背包 `0029`、餘額 `002C` 和倉庫 `00C2`，需要時追加 `00C3` 格位資料。未準備測試資產的帳號仍能正常進村。這個同步時機是 Server 的候選安排，原版服務何時送出初始化尚未確認。

處理 `008D`、`008E` 時確認這個連線已同步資產，且角色在馮德斯銀行 NPC 10013 的互動範圍內，再以當前帳號租約提交。存取成功後依序送出背包 `002C` 和倉庫 `00C3`。Client 開窗、存取、換位與重登列為 TS-03、TS-04 待實機驗收。 [批次測試表](../testing/S00-CONTENT-BATCH-TESTS.md)

## 擴充容量與銀行商店

`5F78BA..5F790A` 讀倉庫容量並建立確認事件 `F43A3`。確認分支 `5F7AC3..5F7AD3 → 5F7A60` 送出僅含 opcode 的 `008C`。player-state `00C4 → 4E2640 → 50AAD0` 在 +2 為 1 時，從 +3 u16 更新容量並觸發 `F4364`，+2 為 0 時走失敗提示。`5F791B` 選字串 0x1C6，原件表 `D67168..D67170` 對應 `kExpandBank`。同版 `CommonMessages.xml` 說明每次增加 20 格，以 Garnet 計費，金額為樣板參數。該 XML 的 SHA256 是 `307d8eee122a852843376d4dacce06e25b53bd9914b98aec2955e8b044095cb4`。

本機候選使用測試設定指定費用。已同步過倉庫且在銀行 NPC 附近的連線可送 `008C`。同一筆 SQLite 交易扣 Garnet 並加 20 格，容量上限 480。成功提交後送 `00C4` 回傳容量，已存在的道具和其他餘額保留。舊測試帳號新增的 Garnet 欄位預設 0。原版實際費率待查。

`00C4` 已確認的欄位只有結果與容量。2026-11-18 新增 `00DD` 餘額發布，正常進入廣場／村莊時發送已保存的 Garnet，銀行擴充成功後在 `00C4` 後發同筆提交的剩餘餘額。原版 `4E3BC0` 從 `00DD/+2` 讀 DWORD，寫到購物車使用的 `CGlobalStatus+686Ch` 並觸發更新。合成正例驗證 120 扣 50 後發布 70，下一次正常廣場初始化讀回相同值。指定 v2 的顯示位置與數字更新仍待 TS-06。 [餘額來源與 Server 映射](../../governance/client-variants/20261118-cash-shop/BALANCE-AND-STORAGE.md)

另經技能支付 UI 核對，`012B → 4E4F30` 更新的是技能熟練度欄 `+6874h`，提示為 `kSkillPhase_Success`。 [技能熟練度欄位](../runtime-content/SKILL-PRACTICE-PROTOCOL.md#技能視窗的熟練度餘額)

ShopNo 70 唯一商品是 Product 23232，對應 Item 20572「一億 LeeLoo 支票」，原表購買和售回都是 100,000,000 LeeLoo。TYPE 7 開貨單走 `683DBA..683DC6 → 4A36E0`，發出 4-byte C2S `0086`，+2 u16 取自商店視窗 +F8。該欄由 `639320 → F42EA +18 → 5B8580` 從 TalkBox 的 NPC 欄 +84 傳入，對應 NPC 10013。購買 context 仍由商品頁初始化決定，TYPE 7 使用 1。 [原表與商店路徑](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

Server 候選在 NPC 10013 附近收到 `0086` 後綁定銀行商店並同步帳號背包與餘額，之後接收 `0027` 購買及 `0020` 售回。同一筆交易更新支票與 LeeLoo。買賣回覆沿用 `002C` 與 `0030`。新支票的物品欄位由本機測試設定提供，正式來源待查。

資產封包的識別欄使用 Product 23232。`508D14..508D37` 把收到的識別值交給 `51D700`，並原樣保存在格內 +Ch。`51D724..51D7A4` 先查 Product 表，再取該列 +20h 查 Item 表。`51C518..51C617` 證明 Product 表的 +1Ch 為 PRODUCT、+20h 為 ITEM。把 20572 直接填入格位封包會使用錯誤的第一層查表鍵。 [背包更新與格位格式](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)

## 原件核對

`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。區段左閉右開，程式檔案偏移為 VA − `0x400C00`。

| VA | SHA256 |
|---|---|
| `4A44F8..4A455A` | `4a7c5bfb7e6581a7db18f0fdd9de1728ad3d5e8a1f0f8d296e1eb56505d51dbb` |
| `4E1FCF..4E1FFF` | `d9b4dcea4e3fe28c33e078e42facd9ebd02211dfa9540f8c9582a44446908b9b` |
| `50A8BC..50A957` | `b72c53d346a7f2749e2d56c28239596e2a9941cae8385c64ee1077ddf87978ba` |
| `50A9DC..50AA71` | `168f3a69d245df9d7bca78f38a729431063f1a1af60cd4bca50777c9e253b802` |
| `4A457A..4A45E3` | `bce687aaef03af3f519743c63f4fa3a71ed66781f76c6824f9eecbf501cb71f9` |
| `5F995F..5F99BC` | `d1fe1318ac97bf2e53331721334d9352b57e0d906591bfc139978093343c74ff` |
| `4A36E0..4A3719` | `d1e04383c726185442f136e924040489e7ca3ca04ae995673a21b599f3f0cb73` |
| `508D14..508D40` | `b331d58c1dfa3da6ae5ddc3683a8f6db753b913baed8e3c1d454ca36e497dbde` |
| `51D724..51D7A7` | `022c0db24e8b7c68d09272d4c71ab442f674358ef9a87fbad90db50314d48a20` |
| `50AAF4..50AB14` | `8810f86febeae39fde6c4121e192fdd5a8f20b9080ca7a1a23ed0b64ba08ab33` |
| `4E4F5B..4E4F80` | `09b8b6c077430293390f2b7c6876960d40505c5a33fbf35b4940c62213b8722c` |
馮德斯單人狩獵場大廳採直接安裝城鎮控制器。Server 在建隊進大廳、正常換村進大廳及結算回原隊伍時，隨同一批初始化發布已存背包、餘額及倉庫，並在場景就緒前完成。已有背包快照時只補倉庫。實際存取依舊需要在銀行 NPC 互動範圍。全新帳號離線旅程已核對建隊時的背包、餘額，以及先前存入第 80 格的復活卷軸，並持續完成兩個狩獵場與 Q144。指定 v2 的銀行介面仍待驗。
