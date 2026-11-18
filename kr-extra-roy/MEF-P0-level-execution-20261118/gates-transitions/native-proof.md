# 原件補證：門外觀、碰撞 consumer 與出口按鍵

本頁以 BIN `9741d197…ebef91` 為準；完整 SHA、VA→檔案偏移、bytes 與指令在 [native-evidence.json](native-evidence.json)／[native-evidence.asm](native-evidence.asm)。`N01–N22` 是本輪定向窗口；`R-*` 復用前輪限定主張並重新對原件核對；`D-*` 為資料。函式邊界後的 padding 保留；`4AED90` 的 switch table 已獨立列為資料，不當作指令。CEventObject的COL→type descriptor→原生RTTI名稱亦已固定，不僅依賴反編譯標籤。

## 1. CEventObject 有實際外觀狀態 consumer

| 鏈節 | 原件窗口／精確接點 | 可證語意 |
|---|---|---|
| 類型選擇 | N15、D-spawn-type-switch；`4AE5DD` switch，type7 table entry→`4AE8D6` | 0007 的 actor type 來自 worldID low byte；type7 配置 `0x428` bytes，`4AE8F7` 呼 `4D1060`。不是看模型號碼「很大」就選事件物件。 |
| 建構 | N12；`4D1060`，vtable `C0C8C4` | 建共同 actor，裝事件物件 vtable；清 `actor+424`。派生類型按既有符號導航，原件 vtable bytes 另核。 |
| actor 初始化 | N15；共同 `v+3C`、`v+44`、`v+58`、`v+5C`、`v+30` | 模型、位置、朝向與顯示初始化仍走現有 actor 生命期，不能直接對未建構指標設狀態。 |
| 初始狀態 | N11；`4D1370` | 依 actor model 查 EventObjects 的 state0，選 motion／avatar；另有特定 actor subtype 的效果配置。初始化不是碰撞開關。 |
| 狀態來源 | N20；`4C62B0` | 解析 `EVENTOBJECTS / OBJECTS / OBJ / STATE`；state slot 每格兩個 DWORD，依 `AVATAR`、`MOTION` 寫入。 |
| 外部參數 | N14；`4AFAF0`，`4AFB20/61/69` | 既有 0000 handler 每列6 bytes：actor ID、selector、value；world lookup 後呼 actor `v+2C`。此處 selector/value 讀成零擴展 WORD，型別解釋在派生 consumer。 |
| 實際派生入口 | D-event-object-vtable；`C0C8C4+2C=4D1250` | 事件物件參數沒有被導向怪物血條 consumer。 |
| 合法 selector | N10；`4D1278` | 僅比較 selector 的 low WORD 是否 `0x1C`；不是 checkpoint category 或點 key。 |
| state 索引 | N10；`4D12DB–4D12DF` | value low WORD **符號擴展**，乘8查 state。此局部沒有完整0..2範圍拒絕分支；內容 adapter 僅許該模型表中明列的 state，不能試任意值。 |
| motion | N10 `4D12EF/4D12F8`、N13 `4C8DA0` | slot+4 送 actor `v+68`，存 `actor+38C`，有已載入視覺時呼 `7A6970`。 |
| avatar | N10 `4D12FA–4D131B` | slot low WORD 存 `actor+388`；視覺已載入時以 `7A6EA0` 更新。 |
| 舊效果生命期 | N10 `4D1320–4D1347` | 如 `actor+424` 有效果，走停止／回收並清指標；不能假設每次狀態切換保留同一效果實例。 |

Table 實物交叉結果見 [resource-evidence.json](resource-evidence.json)：`_ActorList` category7 的門名模型中，6筆有 EventObjects state資料，另2筆沒有。前6筆均有 state0／1／2→avatar0、motion1／2／3。這是**可選外觀狀態**的完整正向鏈；表沒有宣稱 motion1一定關門、motion2一定開門。`00_TestDoor` 亦不能因名字而當成正常關卡已驗收素材。

`7A6970`／`7A6EA0` 的既有反編譯導航本輪亦讀過：它們處理 motion、模型附件／avatar 與視覺通知。本包不以「呼叫樹未出現某個名字」證明所有間接 callback 都不可能影響碰撞；要證明可控門，仍須找到**寫入有效碰撞資料、且移動 consumer 真的讀到改變**的正向鏈。

## 2. 已選碰撞線索為何不能當動態門

### 2.1 入口與建構生命期

`4DF1A0`（R-map_resource_select）以 MapList 的 BOUND 選 `Map/BoundMap/<name>.bnd`，清舊 owner 後載入，`82FF10`（N07）建新的 Bound owner。owner constructor／destructor在 N06，32個 layer wrapper 由 N04 `833280` 建立。wrapper `+0` 指 base layer；其 `[+4,+8)` 是8-byte rows，row為 enabled DWORD 與 region pointer。

不能把建構初期清 vector誤報成 vector永遠為空：`8332B2` 讀 source layer `+1C`，比到 `+20`；`8332C6` 讀每個 region 的 `+14` enabled值，之後把 enabled與pointer存進 wrapper。**這是從已載入資料複製的初始 region，不是已證的門控制 API。**

N01 `4CABE0` 以 actor當前位置加位移，載入 `FAB1D0`（world Bound owner），呼 N02 `82CDF0`。查詢通過才呼 actor `v+44`更新位置。N08 `545F30` 也使用同一 owner與query作玩家移動探測；N09在 `5463BC` 呼這個helper，依結果決定一般移動／替代方向。因而不是只找到一個無人使用的底層函式。

N02 先經 N21 `82CE80` 限制座標，再按 owner比例轉換格位；分別查 wrapper `+28`、`+24`。`82CE62` OR兩層結果；只有兩個都為0才回傳可走。只在兩個wrapper都空時有早退，不推導任意缺一層的資料可安全使用。

### 2.2 832DA0 的所有實際返回分支

N03完整涵蓋 `832DA0..832EB9`：

1. 掃描 enabled region，作嚴格矩形內部比較；命中則 `832E04` 呼 `837B80`（N05）讀region bitmap。
2. `832E09` 把region查詢值寫到 `[ebp-4]`。它會影響region迴圈是否繼續，這個局部值確實被使用，不能簡化成函式中完全未讀。
3. 迴圈結束後 `832E1A` **無條件讀 wrapper+0 的base layer**；之後不再讀 `[ebp-4]`。
4. base layer三條return分支分別是：`832E5B` 載入uniform tile值→`832E64 ret`；索引越界 `832E77 xor eax,eax`→`832E7F ret`；packed bitmap `832EB1 and eax,ecx`→`832EB6 ret`。三條都沒有 OR／傳回region結果。

本包 verifier對原件連續指令、三個return與 `832E1A` 後不再引用region結果local做可重跑核對。因此**修改此wrapper的enabled或region bitmap，不能由這條回值鏈推導出角色會被動態擋住**。`837B80`本身也是讀bitmap，並非writer。結論只約束上述普通移動／玩家探測路徑，不宣稱整個Client不存在其他動態碰撞機制。

下一個原生研究目標須是新的可達writer/consumer鏈：例如真正改寫這兩層base occupancy的操作，或移動路徑實際呼叫的另一個動態物件阻擋查詢。不能再把region容器存在、模型名帶Door、portal特效亮起當成那個接口。具體模型／場景資料可協助找這種xref，但目前選定資料沒有提供可部署的物理門控制契約。

## 3. 出口按鍵、距離與latch的實際行為

N22 `543700` 建point並初始化category、key、radius、mode與latch。category0分支 `543892` 乘QWORD `C55BA8`，`543898`存回float32半徑。該QWORD實際為`0.800000011920929`，即float32的0.8擴成double；新候選半徑2得到`1.600000023841858`。本包幾何以此實際float32結果檢查，表格的1.6是便於閱讀的近似；整圓盤仍涵蓋21格，結論不變。

N16 `544730` 先檢查 `point+105` enabled。未啟用直接退出，**不清** `point+104` latch。啟用時以XY距離作嚴格 `<radius²`；`point+100==0`另要求輸入參數非零，否則清latch。非零mode靠進入半徑產生新資格。符合時先設latch；已有latch則把「本次通知」清零。手動模式放開按鍵或走出區域可重新武裝；只把enabled關再開不能當成可靠重觸發策略。[N16]

N17 `544A00` 對所有point先呼上述判定，再在本次新合格者選距離最近者。`544ABD` 的 `jbe`使同距離保留先前vector row。**不是按key排序**。因為落選point也已經被設latch，重疊區域可能吃掉另一點本次進入資格。門marker與真正出口應分開；目前Server內容檢查已禁止barrier marker碰到actionable point。[N17；Server `LocalScenarioConditions.ValidateConditions`]

選中後仍過原有page gate，再呼point `v+64`。N19對NPC、商店、Tutorial類別各有分支；一般category0／1也有context mode23／24與group狀態分支，可先走確認UI。正常sender N18 `544020`送的是既有6-byte `001C(category,key)`；不含座標、MapID、instance或世代。Server由當前權威位姿／節點解析，不能把新token塞進此Client未讀格式。

點的 `+105` enabled、`+104` latch、世界actor參數 selector0x1C以及 C2S opcode001C是不同型別的相同數字。這些相似值不構成互相轉用的依據。

## 4. 哪些資料保留、哪些必須重建

R-s2c0012_map證明 `0012`先清point、reset controller，再呼map loader；R-world_map_load的同MapID早退只跳過後面的部分場景工作，不能挽回前面已清的point。`lb.ChangeMap`則直接進loader，缺少該預清理，不能當成等價Server轉場。

完整point集合、0048 setter、field ready及Q等待的其餘限定行為沿用 [前輪SCENE-INTERACTION](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md) 與 [finite-handoff](../../MEF-level-functional-closure-20261118/finite-handoff/report.md)。其中0014共同ready、0012／0048及point setter，本輪已按R窗口重新核對。`0027`全量替換、category0半徑0.8倍與持久seen-skip維持既有證據範圍，不因這份重驗升格為整個函式庫FULL-PASS。
