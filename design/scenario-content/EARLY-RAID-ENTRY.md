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

KR 說明表 `Table/Tip.xml` 的類型 2、ID 10 指向 `UI/Texture/Tooltip/0_15.dds`。對應原始 `UI/Texture.stp` 內的 `Texture/Tooltip/0_15.etf`。圖文明示挑戰任務需要內容點數，餘額不足無法使用，並指示從商城取得內容點數書。插圖中的 3,000 是畫面示例，實際起始額與上限待證。

| 來源 | 核對結果 |
|---|---|
| KR `UI/Texture.stp` 與 ETF | 封裝 SHA-256 `2a04d6bbb5687a9a680a66d75703ef1cb4a04b941f9501af9ab1b185060c0f67`，member SHA-256 `188313db0403127649b656565ee41549f980f80f486dd76cb31234a1cc488083`。自 STPD 取出後解 gzip、略過 8 byte wrapper 並解開 ETF 前 128 byte，JPEG SHA-256 `616e310ffe06e9d93adceb11b6380a658edfcb95610aa86df10ea16fea17af1a`。 |
| KR `Table/ItemTable2.xml`、`Product.xml`、`ItemUsableTable.xml` | Product 5410 對應 Item 5376／Class 21。使用動作 11、priority 5、VALUE 500。Product 5454／Item 5420 和 Product 5548／Item 5514 同為動作 11，VALUE 分別為 50、100。商城實際供貨與購買流程待證。 |
| KR `Table/Messages/UIText.xml` | `kRaidToolTip2` 顯示入場需求，`kRaidToolTip3` 顯示失敗消耗，`kContentsPointTooltip` 有下次回復倒數。Server 自動回復週期及單次點數、失敗與退場的交易時點待證。 |

重現時以 `Archive.read` 讀取原始 `Table.stp`（SHA-256 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`）的上述表格。原版 ETF 使用同一 STPD 讀取器，再呼叫 `decode_object_member`。本件前綴為 `3f00030000004800`，模式 0，輸出 JPEG 以 `ffd8ff` 開頭。 [STPD 讀取器](../../governance/client-variants/20261105-zh-tw-v3/tools/stp_resources.py) · [ETF 前綴與 XOR 轉換](../../governance/client-variants/20261107-all-skills-unlock/decode_object_envelope.py)

### 背包使用與保存

Class 21 的一般背包使用從 `5FFF60` 進入 `600409`，以 class 減 1 查 `600F90`。表項 `600FA4` 值為 3，`600F6C` 指向 `600747`。該分支巡覽使用動作，Action 11 落在另外處理的 13～26 之外。通過使用條件且走無確認分支時，`600ACA → 4A39F0` 送既有 8-byte `0021`，用背包 1、1 起算格位、Product DWORD，尾參數為 0。

| Product | Item | Class | Action 11 點數 |
|---:|---:|---:|---:|
| 5410 | 5376 | 21 | 500 |
| 5454 | 5420 | 21 | 50 |
| 5544～5548 | 5510～5514 | 21 | 60／70／80／90／100 |

原版 `ShopInfo.xml`（SHA-256 `2c61fee77c6a8b24bdb350d1639818a2d9f871562c9b97eb51a3d15416699b0b`）把 Product 5410 列在對戰商店 31／109（NPC 10094）及公會商店 32／110（NPC 10051，公會 Lv.1），分別位於 Town 5／23。Product 5410 列上有 `BATTLE_POINT=30` 與 `HOORU=100`，各商店的貨幣選擇仍待核對。商城 `CashProduct.xml` 另列 Product 27461／27462 各一件的價格欄 18／29，對應 Action 11 的 2,000／4,000 CP。這些為原表取得途徑，前兩村新帳號的單人取得方式仍待分析。

七項的原表皆指定冷卻群組 6，說明寫明使用後 1 秒內不可再次使用。Server 支援廣場或村莊正常背包使用已持有的上述道具。有效遊戲租約、格位與 Product 皆須吻合。在同一 SQLite 交易扣一件、增加該帳號 CP 並記錄共用冷卻。提交後送背包 `002C`、絕對餘額 `00ED <balance:u16 LE>` 與冷卻 `00B7`。新連線還原一般背包與快捷欄時同步發布正餘額與仍有效的冷卻。V19 遷移至 V20 時，既有帳號 CP 從 0 開始，保留原背包、各類貨幣及既有冷卻。以 32,767 為 Client 有號比較的表示上限，超過時保留道具。遊戲設計的上限、自然取得、定時回復及入場或失敗扣點仍待確認。

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

## Server 開發順序

1. 確認選定 RAID 後的挑戰大廳初始化，補齊 RAID 與 CP 快照。核對點數取得的實際請求及隊伍人數，保留模式 8 大廳和模式 9 戰鬥場。
2. 由有效連線及隊長提交開場，以房間所選 RAID 查出 Stage／Case。逐步核對首圖載入、就緒和離場握手。
3. 將 Case 88 候選接上正常挑戰入口，驗證實際戰鬥、換圖及結果頁。結算採已核對的 CP 與獎勵規則，回廣場後恢復主線。
