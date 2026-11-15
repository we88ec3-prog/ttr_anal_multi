# 一般挑戰 RAID 1～3 的入場交握與關卡來源

廣場 NPC 10069 開窗的事件 9 用於 Q2851。選關、開始以及進戰鬥場各有自己的請求和場景。 [Q2851 開窗證據](TOWN-SERVICE-TUTORIAL-EVENTS.md#q2851-挑戰入場教學)

| RAID | 最低等級 | Stage／Case | NodeLink 的地圖順序 | 結算表獎勵 |
|---:|---:|---|---|---|
| 1 | 7 | 50／88 | 932 → 934 → 936 → 937 → 938 | Product 2274 ×1 |
| 2 | 12 | 51／89 | 942 → 944 → 948 → 950 → 951 | Product 2275 ×1 |
| 3 | 17 | 52／90 | 952 → 954 → 957 → 960 → 961 | Product 2276 ×1 |

三筆皆為可見的一般挑戰。原表要求列 CP_TOTAL=700。Stage 各列 TOTAL_CP=700、BOSS_COUNT=3、FAIL_CP=140、START_CP=0，扣除時機須再核對。三份 CHART 均為五節點單線，首節點 type 0，末節點 type 3。索引列出 CLUST、15 張圖的原版 BND 雜湊及 _MapList 的 TRIGGER 引用。原版逐圖怪群分配、頭目位置及波次仍待取證。 [來源索引](early-raid-kr-source.json)

```powershell
python -B <分析庫>/design/scenario-content/extract_early_raid_sources.py <KR目錄> <輸出>/early-raid-kr-source.json --bounds <輸出>/raid-bounds
dotnet <本機檢查器DLL> --early-raid-sources <輸出>/early-raid-kr-source.json 3209d0afff692a7636d8945c96ec4e26b5046ecb0ba39a65bebf1e5489352053 <輸出>/raid-bounds
```

本機 Release 檢查器已逐一載入 15 份 BND，核對清單雜湊、每圖 BND 雜湊、版本與靜態碰撞層格式。九份為版本 2，六份為版本 0。收據 SHA-256 為 `907fa767bf2fc0328d8c3d0305258fafa54ced385f759661568c49cc7b101578`。MEF 讀取、動態碰撞、實際走位及戰鬥仍待驗。

## Client 選關、建隊與開始

| 操作 | 封包 | 原版路徑 |
|---|---|---|
| 開啟挑戰配對清單 | C2S `52 00 <page> 09 03 <raidId> <waitingOnly>` | `6910B0` 設定列表類型 3，經 `6904B0 → 53B890` 發送。 |
| 選定挑戰 | C2S `57 00 <raidId> 01` 或 `7B 00 <raidId> 01` | `68C790` 的挑戰分支可在 `0053` 建隊後產生本機事件 `F4396`。 `5B7F80 → 5B68C0` 檢查選中關卡等級，從配對面板 `+20Ch` 取選擇。當前模式 7、23、24 由 `4DDA10` 發 `0057`。其他模式由 `4DDA70` 發 `007B`。 |
| 安裝挑戰大廳 | S2C `00A6`／mode 8 | `4B7DC0` 在 `FD322C` 登錄 `4B9410`。該函式檢查 `+2` 等於 8，建立 `CRaidRoom` 並寫入模式。 |
| 大廳開始 | C2S `08 00 00 00` | `F439E → 5B1230 → 5B1380`。比較已選 RAID 的門檻與 `CGameInfo+5EB4h` 的 CP，符合隊長條件的分支由 `5B15C6 → 4A35F0` 發送。封包沒有 RAID 或 Stage 欄。 |
| 安裝挑戰戰鬥場 | S2C `005F`／mode 9 | `4B7DC0` 在 `FD2FF4` 登錄 `4B99C0`。mode 9 分支經 `4C54E0` 建立 `CRaidField`。首圖載入及戰鬥初始化仍待核對。 |

另一個選項視窗的 `426060` 比較目前選擇與 `CGameInfo+5EACh`，變更時發 C2S `01 01 <row+258h> <row+260h>`。S2C `00A7` 經 `4DD8F0` 登錄到 `4DDBF0`，把 offset 3／4 的 byte 寫入 `+5EACh/+5EB0h`。offset 2 為零時處理 offset 5 起的 DWORD 陣列並顯示提示。回覆狀態與發布時機仍待確認。

`CRaidRoom` 在 `4C5970` 安裝 `00A7 → 424610`，再轉交全域 `CGameInfo`。開始按鈕在 `5B13EB` 取 `CGameInfo+5EACh` 查 RAID 資料，因此正式大廳須先讓 Client 的選定 RAID 與 Server 房間一致；`00A6` 只切場景。開始請求仍從已選且有效的房間判定，請求本身沒有 RAID ID。

mode 9 的 `CRaidField` 在 `4C5520` 註冊覆寫 `0014`、`0031`、`0039～003B`，保留基底的 `0012`、`0038` 與 `0049`。`4ADE41` 註冊的 `0012 → 4B24F0` 在 `4B254D` 讀 `+2` 的實體地圖 DWORD。 `4ADF2D` 註冊的 `0038 → 4B1BF0` 在子型 2 與 6 使用 `+7` 的 Case WORD；`4ADF6D` 註冊的 `0049 → 4B3350` 讀 `+2` 的節點 WORD。這確認可沿用現有欄位形狀，挑戰實際子型、首次載入的送出順序、就緒回報及模式專用結果仍待證。

`CRaidField` 的 `0014` 經 `4C5930` 轉到 vtable `+2Ch → 4230F0`，執行共用的 `4B2570` 後發布本機事件 `F4262`。同場景另有 C2S `31 00 00 00`，由 update `423060` 的 `+BD54h` 計時旗標觸發並清除。這筆請求的發送條件有獨立計時邏輯，尚未認定為首次地圖就緒回報。

### Server 單人挑戰大廳候選

從正常廣場以 `0053` 建隊，建隊後由 `0057` 或 `007B` 選 RAID 1～3。Server 依參戰角色的等級檢查關卡門檻，並在隊伍目錄鎖內確認發送者是唯一隊員兼隊長。首次選定時停止廣場的移動和更新，將隊伍類型切為 3、context 設為 RAID ID，並保留房號。候選大廳暫列忙碌，拒絕一般公開房加入。

回覆順序為模式 8、同隊伍的 `001C/008E/008F`、`00A7 01 <raidId> 00` 與帳號 CP 餘額 `00ED`。欄位 offset 2 的 `01` 走只儲存選項的原版分支。第二選項填 0 是本候選固定值，原服預設待證。已在大廳時改選有效 RAID 只更新原隊伍的選擇。CP 門檻留在開始戰鬥的階段，大廳開啟與改選不扣點。

Server 以既有世界地圖返回廣場 `0042/00/00` 或離隊 `005D/00` 接受大廳離開，清除房間並以正常廣場載入恢復角色和任務。模式 8 的實際按鈕及封包順序待指定 v2 實機。

合成正流程用從新帳號完成 Q144 的 Lv.16 伊希莉亞，以一般介面命令建隊，選 RAID 1 後改選 RAID 2，再經世界地圖返回廣場。驗證房號、隊長、CP 發布、主線保存，且回廣場後可重新建隊進村、接續一般狩獵場。Release 建置與 563 項 HappyPath 合成測試通過。

上述路徑的額外 KR／指定 v2 一致區段如下。

| VA＋長度（十六進位） | SHA-256 |
|---|---|
| `4DDC35+1E` | `5b0d0bff1fbcfb20b02c352ad0bff79f6a479d5e18220e99cded7871d5d6cde4` |
| `C0748C+30` | `c474e836cd4b767bd9483587fc1fae6650bfa865005d34169ad6889bc73d5e7d` |
| `423113+50` | `98066a71d2b76326ee659a5c758fd8c59fda4fe275eb83d344cd12a365834be0` |
| `4230B5+2F` | `30bdc13d61503de6577cfa3bad49af35fcaebe1722e07f2448b223618323bd44` |
| `5B66EF+27` | `b591e215a761d57aff5f5b644f0f1c0b732eace261955e7162a34f255c0648fc` |

挑戰 UI 讀取的 CP 由兩個已定位的入口更新。帳號資料 S2C `002A` 經 `4E1E9F → 4E2B30` 讀取 `+39h` 的 WORD，寫入 `CGameInfo+5EB4h`。場景 S2C `00ED` 由 `4AE0ED → 4B5C10` 讀取 `+2` 的 WORD，與現值比較後寫入同一位置。更新函式也依差額顯示提示。

下列原版 KR BIN 和指定 v2 視窗依個別 PE section 映射後一致。長度以十六進位計。

| VA＋長度 | SHA-256 |
|---|---|
| `5B6AE6+60` | `4ff1a45301f8460982407f272f3addae21a8c7d3cb4f481d47643ad669454fcf` |
| `4DDA10+60` | `e73830a0036412c95449a569429983e5a29f0ea1939e481b6215f9d406c2f121` |
| `4DDA70+60` | `f7ede665be0d2a2273bb98a4bde03f8182efa6fca9af5e4a0e71dec1fdce5e60` |
| `4B7E3F+A` | `c7f6632306d928379472971b0cdc89a7512dc6a4a6685cc21559df5f85a8d858` |
| `4B9441+59` | `baa65e8d9941aada916407e1053aafa5cd6fbf70167e8b2d8b3719b6944c9657` |
| `5B1480+7` | `eb4477e727b83b7349acacddd89ad1b900a1ff5933e904747f726a182e86d4c1` |
| `5B15C1+A` | `203f580044041fc2fc577a26d4e92153fb0faa203e996ffb00569a0a13f14dea` |
| `4A35F0+2B` | `d777b9726046f5ee65935216aa73cca27a2179b49f06c652789e3ee9df790482` |
| `4B7EAF+A` | `342e3f034373d37878b84ca62ae2e573afd6bacdfe6d70dbe2d470d09da4ed9a` |
| `4B99C0+1D0` | `31c4678af808f8a5c84c78e398a9cff725f7cb75bb4b873353ff22a1b909dbff` |
| `426154+6B` | `f00fbb090799c30e80c87cb1a354892d77434688d41f716b64b2a65e632799af` |
| `4DD94F+A` | `d15da530a33207fc48f7bc256051b4e972f91c5d1511dc8407aa0d847aca3f86` |
| `4DDC35+30` | `a2f88b2ecebed686c8bbf634c84909e83a2c67b74962b13719b37748c9cfcb30` |
| `4AE0ED+A` | `58f4d9f2008046234cf2bf1b8236d28341b00fa11410b3265f43c14d99f9051c` |
| `4B5C44+31` | `96b2354f345d3b11c22f86933be839f3023ef14cbed7985ebb296d0beb1fd7f7` |
| `4E1E9F+A` | `7b3dae489f600fc22f96f4804a8a152ad631eccc16d0d11345985e3c36ce8c3e` |
| `4E2BE4+D` | `b4b000367819b51ef10706d866cc4f47da95ea626093e8575b1ed7177baadd7b` |

## 內容點數（CP）來源

KR 說明表 `Table/Tip.xml` 的類型 2、ID 10 指向 `UI/Texture/Tooltip/0_15.dds`。對應原始 `UI/Texture.stp` 內的 `Texture/Tooltip/0_15.etf`。圖文明示挑戰任務需要內容點數，餘額不足無法使用，並指示從商城取得內容點數書。

| 來源 | 核對結果 |
|---|---|
| KR `UI/Texture.stp` 與 ETF | 封裝 SHA-256 `2a04d6bbb5687a9a680a66d75703ef1cb4a04b941f9501af9ab1b185060c0f67`，member SHA-256 `188313db0403127649b656565ee41549f980f80f486dd76cb31234a1cc488083`。自 STPD 取出後解 gzip、略過 8 byte wrapper 並解開 ETF 前 128 byte，JPEG SHA-256 `616e310ffe06e9d93adceb11b6380a658edfcb95610aa86df10ea16fea17af1a`。 |
| KR `Table/ItemTable2.xml`、`Product.xml`、`ItemUsableTable.xml` | Product 5410 對應 Item 5376／Class 21。使用動作 11、priority 5、VALUE 500。Product 5454／Item 5420 和 Product 5548／Item 5514 同為動作 11，VALUE 分別為 50、100。商城實際供貨與購買流程待證。 |
| KR `Table/Messages/UIText.xml` | `kRaidToolTip2` 顯示入場需求，`kRaidToolTip3` 顯示失敗消耗，`kContentsPointTooltip` 有下次回復倒數。Server 自動回復週期及單次點數、失敗與退場的交易時點待證。 |
| KR `Table/_LoadDisplay.xml` | SHA-256 `49aba61c484fc27964e2c75ecd487e9a1e6a4fdcf9b52173cbed3088167ee265`。載入提示明載每日早上 7 點更新為 3,000 CP，也說明按在線時間逐步恢復及可用 CP 道具補充。提示未列在線回復的週期或單次點數。 |

重現時以 `Archive.read` 讀取原始 `Table.stp`（SHA-256 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`）的上述表格。原版 ETF 使用同一 STPD 讀取器，再呼叫 `decode_object_member`。本件前綴為 `3f00030000004800`，模式 0，輸出 JPEG 以 `ffd8ff` 開頭。 [STPD 讀取器](../../governance/client-variants/20261105-zh-tw-v3/tools/stp_resources.py) · [ETF 前綴與 XOR 轉換](../../governance/client-variants/20261107-all-skills-unlock/decode_object_envelope.py)

### 背包使用與保存

Class 21 的一般背包使用從 `5FFF60` 進入 `600409`，以 class 減 1 查 `600F90`。表項 `600FA4` 值為 3，`600F6C` 指向 `600747`。該分支巡覽使用動作，Action 11 落在另外處理的 13～26 之外。通過使用條件且走無確認分支時，`600ACA → 4A39F0` 送既有 8-byte `0021`，用背包 1、1 起算格位、Product DWORD，尾參數為 0。

| Product | Item | Class | Action 11 點數 |
|---:|---:|---:|---:|
| 5410 | 5376 | 21 | 500 |
| 5454 | 5420 | 21 | 50 |
| 5544～5548 | 5510～5514 | 21 | 60／70／80／90／100 |

原版 `ShopInfo.xml`（SHA-256 `2c61fee77c6a8b24bdb350d1639818a2d9f871562c9b97eb51a3d15416699b0b`）把 Product 5410 列在對戰商店 31／109（NPC 10094）及公會商店 32／110（NPC 10051，公會 Lv.1），分別位於 Town 5／23。Product 5410 列上有 `BATTLE_POINT=30` 與 `HOORU=100`，各商店的貨幣選擇仍待核對。商城 `CashProduct.xml` 另列 Product 27461／27462 各一件的價格欄 18／29，對應 Action 11 的 2,000／4,000 CP。另以 `QuestInfo.xml`（SHA-256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`）比對前述七個 Product 的 Reward value。找到 11 筆，皆為 Town 12、13 或 28，對應 Product 5544／5547，最低 Lv.48。早期單人帳號可走每日更新。

七項的原表皆指定冷卻群組 6，說明寫明使用後 1 秒內不可再次使用。Server 支援廣場或村莊正常背包使用已持有的上述道具。有效遊戲租約、格位與 Product 皆須吻合。在同一 SQLite 交易檢查每日刷新、扣一件、增加該帳號 CP 並記錄共用冷卻。提交後送背包 `002C`、絕對餘額 `00ED <balance:u16 LE>` 與冷卻 `00B7`。V19 遷移至 V20 時，既有帳號 CP 從 0 開始，保留原背包、各類貨幣及既有冷卻。以 32,767 為 Client 有號比較的表示上限，超過時保留道具。遊戲設計的上限、逐步回復及入場或失敗扣點仍待確認。

### 每日刷新

V22 另存記帳日。以 07:00 KST 作為韓版 Server 候選，對應 22:00 UTC 及台灣 06:00，無須更改 Host 時區。第一次進入載入完成的廣場或村莊時，零餘額初始化為 3,000，已持有正餘額的舊存檔保留其數值並記入當天。走到下一個記帳日後，餘額設為 3,000。只要重新進入正常城鎮、選挑戰或開戰，Server 都會檢查記帳日。已在廣場、村莊或挑戰大廳的連線，在日界後的下一次世界更新收到 `00ED`。同一記帳日重連不會再給點，各日也不另外累加。扣點、在線逐步回復、倒數顯示及首次建帳行為的原服逐包內容仍待取證。

以下指令視窗在原版 KR BIN 與指定 v2 依個別 PE 區段對照一致。

| VA＋長度（十六進位） | SHA-256 |
|---|---|
| `600409+29` | `2eea2f2a2099549f4d1b582c01a32e07fdfa6a4b5ee817f3cf044581d5d83c25` |
| `600FA4+1` | `084fed08b978af4d7d196a7446a86b58009e636b611db16211b65a9aadff29c5` |
| `600F6C+4` | `6dbe44288fb5a2ca0d611a2a459538e37d3e95855485490f94453c1cec4ef27a` |
| `600ACA+23` | `852094866c3dd4fd82e7b46fda3abd25d94779f6aca5ec02c21fd8e5586d2999` |
| `4C5970+5C` | `dc453caf797ab5a57433e6aafed7680de79e128f710f4a04b6b5f45bfbdcc069` |
| `5B13DF+51` | `97d03e59d86f1f5617bb049e55fd86cdfb96cb7478cafdb8fb8ad2783c432531` |
| `4C5520+6C` | `618acd34e4221f45b712fb7b7653a16e7093e7052e06306f1441841909173228` |
| `4ADF2D+4A` | `50bc71657b20251ba0826e6c33caec90e9ef8150bfe135ac5ae95ece648f5826` |

## Case 88 的 Server 關卡候選

候選檔用 `NOT_NATIVE_MEF` schema。五個節點與地圖順序來自 CHART，怪物組成取自 CLUST。逐圖群組分配及出生點、出口座標由 Server 設定。三隻頭目各在所屬圖進場時生成，其中兩圖同時有小怪。採清場後解鎖、到傳送點按 Z，再進下一圖或結果頁。

| 節點／地圖 | 採用的 CLUST 群組 | 生成數 | 頭目 |
|---|---|---:|---|
| 1／932 | 2 | 3 | — |
| 4／934 | 14、19 | 4 | 1155 |
| 7／936 | 32 | 3 | — |
| 9／937 | 27、30 | 3 | 1157 |
| 10／938 | 44、43、45 | 3 | 1159 |

以原版 BND 驗證出生點、怪物與出口在靜態碰撞層可達。Server 離線檢查核對 16 筆怪物生成封包，再以模擬清場推進四次換圖與一次結算動作。原生挑戰進場、實際交戰及獎勵入帳待開發或實機驗收。 [Case 88 候選設定](phindos-raid1-stage50-case88.scenario.json)

```powershell
dotnet <本機檢查器DLL> --early-raid-case88 <來源清單> 3209d0afff692a7636d8945c96ec4e26b5046ecb0ba39a65bebf1e5489352053 <碰撞目錄> <Case88候選檔> e37997b09e30a425730b1c5a463ef3b6b561914233de90147fac6ac8cfac9a87
```

輸出狀態為 `STATIC_BOUNDS_SPAWNS_AND_SIMULATED_CLEAR`。本機 JSON 收據 SHA-256 為 `e02840a8e7f1be0957a898a96da52f9e57cc6fb15a1a2e0e6b19d125dc395450`。

### Case 88 的 Server 開戰候選

本機 Host 可指定 `TARTAROS_LOCAL_RAID_ONE_SCENARIO_PATH` 和 `TARTAROS_LOCAL_RAID_ONE_BOUNDS_DIR`，分別指向上述 Case 88 候選和五張原版 BND 的絕對路徑。啟動時核對候選及各 BND 的 SHA-256，驗證出生、怪物與出口可達。這兩項設定須與正常廣場及帳號錢包一起使用。

大廳選中 RAID 1 後，Server 只接受本房唯一隊員兼隊長的 `08 00 00 00`。重新查目前角色達 Lv.7、帳號 CP 達 700，再送載入開始、`005F/09`、`0038` 子型 2（Stage 50、Case 88）、實體地圖 `0012`、節點 `0049`、玩家與怪物、出口、`0014` 和載入結束。選關、清怪及出口按 Z 走目前的正常遊戲請求。後四張圖沿用已安裝的 mode 9 和 Case。

指定 v2 仍須確認開戰畫面、子型 2、封包順序與換圖。固定 BND 檢查涵蓋可達及生成資料，五圖輸入與清怪另以合成碰撞 fixture 驗證。

### Case 89／90 的 Server 開戰候選

啟用 RAID 2 或 3 時，分別設定 `TARTAROS_LOCAL_RAID_TWO_SCENARIO_PATH`／`TARTAROS_LOCAL_RAID_TWO_BOUNDS_DIR` 及 `TARTAROS_LOCAL_RAID_THREE_SCENARIO_PATH`／`TARTAROS_LOCAL_RAID_THREE_BOUNDS_DIR`。每個關卡獨立啟用，原有 RAID 1 設定沿用。Host 核對候選檔及對應的五張 BND。大廳沿用同一入口，Server 依唯一隊員兼隊長所在隊伍的選關查路線，檢查角色 Lv.12／17 與帳號餘額至少 700 CP。開戰用 mode 9，`0038` 子型 2 使用 Stage 51／52 與 Case 89／90。

| RAID／圖 | Node | 選用 CLUST 群組 | 生成數 | 頭目 Model／PRE |
|---|---:|---|---:|---|
| 2／942 | 1 | 4 | 3 | — |
| 2／944 | 3 | 20 | 4 | 1164／1 |
| 2／948 | 7 | 34 | 3 | — |
| 2／950 | 9 | 40 | 4 | 1085／5 |
| 2／951 | 10 | 19 | 6 | 1088／5 |
| 3／952 | 1 | 5 | 3 | — |
| 3／954 | 3 | 61、34 | 4 | 1173／1 |
| 3／957 | 6 | 43 | 3 | — |
| 3／960 | 9 | 67、49 | 4 | 1181／1 |
| 3／961 | 10 | 69、40 | 4 | 1184／1 |

地圖與出口順序由 CHART 取用。每組模型、PRE、數量和表內頭目標記由 CLUST 核對。群組如何分配到地圖、怪物座標、即時生成和出口規則是 Server 候選。三張頭目圖的頭目與同圖小怪採入場生成，整組清掉後才解鎖出口。每張圖到出口按 Z，末圖進 mode 3 結果，確認後回廣場。

離線檢查器已核對原始靜態碰撞層、出生和出口可達、Case 89 的 20 筆與 Case 90 的 18 筆怪物生成封包，以及兩條路線各四次換圖和一次模擬清場結算。

| 候選設定 | 候選 SHA-256 | 離線 JSON 收據 SHA-256 |
|---|---|---|
| [RAID 2](alsmeer-raid2-stage51-case89.scenario.json) | `ab0630e952ffea353c1b4880dfa139f6701d65403af0a53e810e6bc7ca3e9c51` | `d8c448f49a6fc8808248d286b4877a77fa131a17a020cefb12c24a8c163110c8` |
| [RAID 3](rotrua-raid3-stage52-case90.scenario.json) | `05d918b631c93fb1202fc39e3647a2f780cb0dabe723109532afa7d7fa7cc370` | `4e25b24508238867416955fe54251aa820b288b1603ec5a49119f35510fc4427` |

以 `--early-raid-route <raid> <來源清單> <清單SHA-256> <碰撞目錄> <候選檔> <候選SHA-256>` 可重現。來源清單沿用本文的三關固定版本。收據以上列 CLI 輸出使用 PowerShell `Set-Content -Encoding utf8` 儲存。指定 v2 的載入、走位與戰鬥體驗另待驗。

### 挑戰結果頁與單人結算

全域 `0022` 的 `FD2E0C` 由 `4B7E9F` 登錄 `4B9770`。`+2=3` 經 `4B98BC → 4C4FB0` 安裝 RAID 結果場景，`4C5030` 選擇頁面 14，`4B994E` 再經 vtable `+38h` 呼叫 `4C50F0`。mode 9 的基底場景 `0022 → 4B3040` 是另一張 dispatch 表中的槽位。挑戰成功使用全域 mode 3 路徑。

| Application offset | 原版消費與本次候選值 |
|---:|---|
| 0–2 | `22 00 03`。 |
| 3 | 有號 byte 成為本機事件 `F426B` 的第三參數，候選填 0，實際用途待證。 |
| 4–7、11–13 | 由 `4C50F0` 複製至 `CRaidDescData`，候選填 0。 |
| 8 | 1 走成功分支，0 走失敗分支。 |
| 9 | `4DDAD0` 用作卡片排序種子，也成為 `F426B` 的第二參數。候選填 0。`5ABCE0` 另從 `CGameInfo+5EB8h/5EBCh` 的隊員資料計算卡片數量。 |
| 10 | 成功分支讀取資料列數量，候選填 1。 |
| 14 起 | 每列 5 byte，DWORD 及 byte 由 `4DE9C0` 複製。結果 UI `6CB3B4` 開始取各列 DWORD 作獎勵圖示。RAID 1 候選填原表 Product 2274 與數量 1。 |

場景的 `4C5370` 在返回旗標允許、`scene+5EBCh=0` 的分支送出兩 byte C2S `19 00`。結果頁 `F439F → 5ABB40 → 5ABB90` 另有多人卡片控制，僅在隊員數大於一且卡片資料非空時切換畫面。其他 `0037` 分支和單人返回按鈕的實際操作待驗。候選以結果發布後的 `0019` 為正常返回廣場請求。

末圖清場後操作出口，Server 先在 V21 錢包資料庫保存該帳號的 run ID 和待領資格，再送 19 byte 的 mode 3 成功結果。確認後回廣場，於場景就緒前嘗試把一件書籍送入背包並發布 `002C`。已占用書籍格或背包已滿時保留待領，下次進廣場再嘗試。結果頁斷線後同樣可在正常重登進廣場領取。背包寫入與待領標記在同一 SQLite 交易。成功的 CP 暫時維持，原服成功、失敗與退場扣點仍待確認。

V23 將 RAID 1 待領及已交付紀錄保留為 Product 2274，RAID 2／3 分別記 2275／2276。每次回廣場可各交付一本目前能放入背包的不同書籍。某一本已在背包時只保留該 Product 的待領資格，其他符合條件的書可以入包。各場以 run ID 去重，同一場紀錄的帳號與獎勵都須一致。

原版 Client 的以下視窗已依各自 PE section 與指定 v2 比對一致。KR BIN SHA-256 為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，指定 v2 為 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。

| VA＋長度（十六進位） | SHA-256 |
|---|---|
| `4B7E9F+A` | `d5888d9f21863ebe1e575a699f241ffb54d69f968626503502ea6a0a4760727f` |
| `4B98BC+9` | `80fb30f5c4cf68f4a8b0b1d75826ede4e402623b5e9a63eadf362cd5d01159b5` |
| `4B9933+2C` | `c3409f9586184cd950601e2d98d9bc17b9a0e1f1fc5743a9c758d2255ddcd2fa` |
| `4C5030+89` | `d838e49ec774d2002d49e40ad5b6f05ae2b484ecf35501ff917a0764c2d41f30` |
| `4C5120+135` | `b8033dcdbda118de8fffc95577ef9bb3355e36ea1350409bfa39ce088a9b3e3e` |
| `4C5460+44` | `e9ed3471229d77e5b99653f5a941c31ba280d9169442fede640b36562032abec` |
| `5ABCE0+36` | `079dd6e17f81b118c8d379730c1712a2251dab64e8b6412bb2e9559fd74c38df` |
| `5ABB90+8D` | `68ebd15fe156a6542f3fdd1af0852f535f2b7a2f1f660a23de7f1bd8424deed9` |
| `C1CF48+20` | `e8e25e74508439cd8ca3136c120c35abe339bc424737c5141112ae0f8fdc6d77` |
| `6CB3B4+7A` | `5920fc16f858fa3db17aad1c098e8d1b021650438949fd2052fdb52d0b477852` |

獎勵資料以原版 `Table.stp` 的三份成員另核對。 `Product.xml` SHA-256 `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c`，`ItemTable2.xml` `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2`，`ItemUsableTable.xml` `30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c`。

### 經驗書使用

| Product／Item | `EXP_BOOK` 原表數值 | 來源 |
|---:|---:|---|
| 2274 | 10,000 | RAID 1 |
| 2275 | 13,750 | RAID 2 |
| 2276 | 17,500 | RAID 3 |

三者皆為 class 23、`quan=1`、`COOLTIME group=6`、使用 action 4、priority 1。使用分支從本地角色物件的 `+88h` 取角色索引。直接使用時以 class 減 1 查 `600F90`，項目 `600FA6` 為 4，經 `600F70` 跳到 `600539`。該分支讀角色表中選定角色的擁有旗標及等級，再與 `4D43D0` 掃描已擁有角色得到的最高等級比較。嚴格小於時跳 `600482 → 4A39F0`，發送 C2S `21 00 01 <自 1 起算背包格> <Product:u32 LE>`。這條直接使用路徑沒有追加角色欄位。

Server 候選在載入完成的正常廣場與村莊啟用。接收端以該連線場景目前角色決定受益者。SQLite 交易同時驗證遊戲租約、持有角色、角色低於冒險團最高等級、背包格與 Product，以及群組 6 共用的一秒冷卻。依原表數值和既有成長曲線入帳，與扣一件道具及冷卻一起提交。提交後依序發布 `002C` 背包差量、`005C` 角色資料、`0034/type 1` 經驗條、`00B7` 冷卻。原服跨越最高等級時有無額外截斷待核對，候選沿用共用經驗資料的上限。RAID 2／3 的實機取得與戰鬥中使用另待驗證。

以下指令視窗依原版與指定 v2 各自 PE section 映射核對一致。

| VA＋長度（十六進位） | SHA-256 |
|---|---|
| `600323+43` | `a6324a218e181cc7613656ceb371487a595294e2a76d8f9857123373d40ef741` |
| `600409+29` | `2eea2f2a2099549f4d1b582c01a32e07fdfa6a4b5ee817f3cf044581d5d83c25` |
| `600FA6+1` | `e52d9c508c502347344d8c07ad91cbd6068afc75ff6292f062a09ca381c89e71` |
| `600F70+4` | `030014f7b27120fba46a6f39e044b559240d2642cf840de42f86854963addad6` |
| `600539+41` | `39debe2cdadaa9497a27a23607b14287effaaa0dc1534eb87d3a8760ab20c7e4` |
| `600482+23` | `318a6dca7fd07c76824bc4e16c8550e165efa3a4098ebf9177e32d82f0293acb` |
| `4D43D0+AB` | `d607678467e17974acd9814eb802397949d237fb31613b4b75d64d1fdcc4cecd` |
| `4A39F0+50` | `00169f7663a7afd272f88b8f0a7c91956221429a988c376dbf416d57929475dd` |

## Server 開發順序

1. 驗證早期新帳號每日 CP 刷新以及顯示，核對在線逐步回復規則。
2. 以指定 v2 驗證 mode 8 至 mode 9 的載入、戰鬥與換圖，以及 mode 3 結果頁、獎勵顯示和返回握手。
3. 驗證經驗書畫面與等級保存，補上成功／失敗／離場的 CP 交易及各自的持久化行為。
