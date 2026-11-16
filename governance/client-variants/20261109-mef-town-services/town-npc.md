## 馮德斯村的 NPC 放置、互動與商店位置

本節以 KR 原始 BIN 機器碼、Table／Event／BoundMap 成員與 v81 Server 實作作交叉查證。結論適用於已還原的原生函式及資料，不把腳本函式的存在視為村落已自動啟動重建 MEF。

### 資料身分與 Town1 對照

Town1 是城鎮內容鍵，Map182 是其載入地圖。原 `_TownList.xml` 的 Town1 名冊含 10001、10002、10003、10008、10013、10014、10047、10048、10015；每筆只給 NPC ID。位置須另有資料來源。現行 `LocalPhindosTownCandidates.cs` 把 10008 放在 (758,714)、10013 放在 (778,714)、10047 放在 (778,726)。本輪以原 `BoundMap/town001.bnd` 實算三處候選格的兩層均為 0。這三個位置是 Server 選在一塊靜態可通行矩形中的配置，不能當成原版的 NPC 座標。v81 初始化以 0007 產生 9 名 NPC，再將同一組九點全部發為 0027／category 3；目前這個方法不產生任何 category 2 商店點。[現行村落設定](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Network/LocalPhindosTownCandidates.cs) · [封包構造](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Protocol/KrTutorialWorldCandidateProtocol.cs) · [配置的來源與測距條件](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/s00-iterations/S00-20261103-PHINDOS-TOWN-LAYOUT.md)

以下五筆來自原 `Table/ShopInfo.xml` 所有 TOWN=1 的 SHOP。商品數僅計該 SHOP 直屬 PRODUCT 宣告，未依等級、持有或 UI 篩選。NPC TYPE 與 SHOP.TYPE 是不同類型。

| ShopNo | 商店（原表名稱意譯） | SHOP.TYPE | NPC ID | NPC.TYPE | 商品列數 | 在 Town1 九名冊／有 category 6 模型 |
|---:|---|---:|---:|---:|---:|---|
| 1 | 雜貨店 | 1 | 10028 | 11 | 5 | 否／否 |
| 2 | 鐵匠鋪 | 2 | 10030 | 12 | 27 | 否／否 |
| 3 | 飾品店 | 3 | 10029 | 13 | 3 | 否／否 |
| 4 | 煉金店 | 4 | 10031 | 14 | 6 | 否／否 |
| 70 | 銀行商店 | 7 | 10013 | 1 | 1 | 是／是，FILE=00_Ertale |

前四位仍各自有原 npctable 定義與 TALKSET；10030 的五個 TALK VALUE 是 2255、2256、2257、2258、4781。不能因商戶不在常駐 NPC 名冊就刪掉商店，也不能把每個商店 NO 當成等號右側的 NPC 模型 ID。銀行同時有 NPC 與店記錄，因此亦不能推定每家店都需另生成一個新角色。ShopInfo 的這些行均沒有 XY。另有相連但不同的類型值：原件 4FBD15 取得 NPC 記錄，4FBD22..29 限制 SHOP.TYPE 在 1..4，4FBD2B/2E（`83 C1 0A 89 48 20`）把 type+10 寫進 NPC 記錄 +0x20，與四位商戶的 11/12/13/14 相合。銀行的 SHOP.TYPE=7 不走這個覆寫。這項分類不能證明強化或交易已成功。

原 BIN 未搜到大小寫精確的 ASCII 或 UTF-16LE「MPC」「CMPC」，存在 CNPC、CNPCTable RTTI。三個 STP 共 1,026、7,382、1,296 筆（Table、Event、BoundMap）成員路徑沒有不分大小寫的 mpc 子串；上述鎖定的五個 Town／NPC／Shop／Actor／Map 表亦無獨立 MPC 詞。這只是受查範圍，不能排除其他名稱、語言或模組。此報先覆蓋 NPC 位置，若 MPC 意指玩家、怪物或其他物件，維持獨立待釋義。

### 可站在指定位置的角色，不等同能互動的點

1. **一般世界 NPC 有本地建立能力。** `lb.CreateObjectEx(model,x,y,scale,direction,attach)` 在 `4A0FA3..4A0FB6` 分流；有號 model 大於 10000 的路徑選 class 6，`4A101E` 配置 0x42C、`4A103C E8 DF 10 03 00` 呼叫 CNPC 建構 4D2120。輸入 X/Y 傳給 virtual +44（`4A107D`、`4A114A`），朝向傳 +58；`4A104F..4A105F` 由本地 F7DE04 指派 EntityId，`4A11B6` 進 4DFF30 共用索引。S2C 0007 的 class 6 分支也在 `4AE82B E8 F0 38 02 00` 呼叫 4D2120，但 `4AEB2C..30` 取的是封包給的 EntityId，再經 `4AEC03` 登錄。可在重建關卡定義座標與朝向，純本機生角要先找到 Town1 腳本入口、驗有效模型與身分對應。對無模型來源的四位市集商戶不可直接套用這條建模路徑。
2. **演出 NPC 與世界 NPC 分屬兩條路徑。** 原 SEQ 的 Q.CreateObject 建 CEventActor，Q.WalkObject、Q.AniObject 以劇情自己的槽號表驅動動作與對白，適用於固定演出。普通場景中的可點角色仍涉及實體身分、互動區與正常狀態，不得用戲中的座標或同名 NPC 充作常駐站位。例如兩位同名 Yuri 10047／10048 都列在 Town1，但各有獨立模型 01_Yuri01、01_Yuri02。
3. **市集區與 NPC 互動區可由資料放置。** `Event/TutorialBase.lua` 主 prototype 指令與原件逐字相符，pc3/4 分別設定 MARKET=2、NPC=3。S2C 0027 在 4B2AF0 解析 header 後每列18B，`4B2B65` 先清舊點集合，`4B2BBF/4B2BC4/4B2BCB/4B2BD5` 供 key、XY 參照、category，交 543700。該建構器寫 +F6 key、+F4 category、+FC 半徑、+105 enable，`5437BB..5437C4` 複製 XY 至 +A0/A4。對 category2，`5437F0 E8 1B 81 FB FF` 查店、`5437F9..543809` 將店 TYPE 1..4 換成 0..3，其餘或查不到走 0。 `543838` 取字串 CHECKPOINT_MARKET，`543842` 選視覺，`54385D/543865` 將該點 XY 交本機視覺建立。如此可讓 Server 用重建定義發布市場點，再由 Client 自己放標記。此證據沒有顯示常駐腳本能直接配置任意 category2/3 點；兩個已辨識的 CCheckPoint 建構器 E8 caller 另一路固定 category4。
4. **既有點可本地開關。** `Tutorial.SetCheckPointStatus(key,category,status)` 與 S2C 0048 同至 544940，依 key/category 找既有點，543B77 寫 +105；互動端 544739 讀該欄位作 gate。對 category2、3 可證互動 enable，但 543B30 的出口／教學視覺分支受 category 限制，不能由此推論商店招牌會消失。該 API 也沒有新 XY 或商品欄位。

### 點商店之後，哪些步驟已由 Client 自己做

- **市場點採 ShopNo 作鍵。** `544478` 判 category2，`544482..544491` 以點的 +F6 key 查全域 CShopMgr 的 0x3C 列（4FB938 比對列 +0，4FB93D 的 stride=0x3C）。原 ShopInfo parser `4FB9C0` 依次讀 NO／TOWN／TYPE／NPC（`4FBB6D/4FBB9F/4FBBCD/4FBBFB` 對應字串）並順序保存於列 +0/+4/+8/+0C。 `5444A0/5444AA` 再取列 +0C 的 NPC ID 查 NPC 表，且要求非空對話集合；成功後建立 F4388 並入本機 UI queue。例：鐵匠使用 category 2、key 2，查到 NPC10030。將 key 填成 10030 會查找另一個鍵，不能這樣開鐵匠。
- **對話與貨架入口有本機消費者。** MARKET 路徑的 5444DB..5444EC 與一般 NPC category3 中有普通對話的分支 5441CD..5441E2 均可建立 F4388。事件帶 +14 當前 GameInfo context、+18 NPC。5B7F80 的兩級 dispatch 將 F4388 對到 slot9，`5B7FB7` 呼 5B6B70，型別為 105BE 才按預期處理。 `5B6BA1..5B6BB2` 將其帶入 TalkBox 636520 mode0。 `636608` 呼 4FC250、`4FC2A9` 呼 4FB960；後者 `4FB990/4FB995` 以當前 Town 和 NPC 比對 SHOP.+4/+0C，並從 PRODUCT 清單建候選。因此放置／切換既有店點可讓原生表決定對話、商品入口，任意搬用另一城的 ShopNo 仍可能使下一層查不到商品。沒有由該操作產生交易成功、任務完成或正式獎勵的證據。
- **普通 NPC 有多種具條件的操作。** 查詢類型與場景 gate 可選普通談話、任務候選或其他分支。先前已閉合 NPC10338 的特定選取路徑：5B9447 先呼 scene manager，之後才組 C2S 001C；不能對所有 NPC 點擊都要求「Server 先逐句發台詞」或一律把 001C 解為購買。
- **開發需求與驗收。** 在關卡規則中以 `map, town, checkpointCategory, key, x, y, radius, state` 明確描述站點。可見 NPC 外觀另以 `model, entity binding, facing` 表示；MARKET 必須另按 (Town, ShopNo, NPC) 驗關聯。首次 0027 應一次發布需共存的所有類別，以免替換集合時消除 NPC／出口；同 key 不同 category 不可去重為一個點。離線可驗表關聯、範圍與 schema、包列和 UI 路徑；實機後驗 NPC 與區域同地、market marker、靠近按 Z 顯示指定商戶、離開範圍、錯店／錯人。錢、道具、庫存與強化結果應另由對應交易需求驗收。

### 來源識別與重查錨點

| 來源 | SHA-256 |
|---|---|
| KR Tartaros.bin | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| KR Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| Table/_TownList.xml | `bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660` |
| Table/npctable.xml | `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d` |
| Table/ShopInfo.xml | `2c61fee77c6a8b24bdb350d1639818a2d9f871562c9b97eb51a3d15416699b0b` |
| Table/_ActorList.xml | `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7` |
| Event/TutorialBase.lua | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` |
| BoundMap/town001.bnd | `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6` |
| .text 範圍 [4A0F9C,4A10A1) | `122590d1a015c502188124a496ebb0ea60b4c423ba90eaea61240cbe1baca682` |
| .text 範圍 [543745,54386F) | `798b368a01f40cef0c22d5f979709fb402ace847785ec5235ea65d989299d05b` |
| .text 範圍 [544478,5444F1) | `2cf094a19e5d9e145d0213b3bfaa5e16828dcf98447a96377d54097b2659254b` |
| .text 範圍 [4FBB6A,4FBC40) | `e5f019b280d5caa93d78eeaf8e9980eba2d44910b2b791c742cbf2fd4aa7c836` |

[原料補證與語意邊界](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/research/handoffs/s00-web-server-definitions-20261104/W3/RAW-RESOURCE-FINDINGS.md) · [NPC 互動原始路徑](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/s00-iterations/S00-20261103-PHINDOS-NPC-INTENT.md)
