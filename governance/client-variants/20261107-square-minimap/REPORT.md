# 廣場右上小地圖黑底：有界調查（2026-11-07）

使用者確認只右上小地圖黑，中央3D正常、城鎮小地圖正常。沒有操作／附加／啟動遊戲，沒有修改Client或Server；也未搜索MEF。

## 已核對事實

1. 現行Server廣場初始化先送38/type0/Town5，再12/map511。原Table ID511對應MAP=square001D、BOUND=square001；TC同一ID這兩欄相同。
2. 既有原件source4F5640把BOUND存入FB74D0；v6有界指令56CE05也從FB74D0查當前map，56CE6D追加'.mmt'。因此所需檔是Map/Minimap/square001.mmt，而不是square001D.mmt。逐來源hash與指令片段見source-identities.json和*-v6.txt。
3. KR Map/MiniMap.stp缺MiniMap/square001.mmt，只存在MiniMap/square001t.etf。TC原件有square001.mmt（SHA a38109bff6fa948cb935a0cd7e411679ee23ae9c9e78e0f5e4207695f953a37a），其TextureFile=square001.dds，WorldSize1536。
4. KR/TC town001.mmt、town002.mmt逐byte相同而且存在，故城鎮成功與廣場descriptor缺件差異直接對應。不能因只看到ETF存在就認為完整小地圖資料已齊。
5. 56E790先檢查／載入mmt；失敗進56E330，找不到texture時創建256x256並734470填0xff000000。有界工作副本指令56E4D2/56E565核對黑色常數。這是與人測黑底相符的具體因果候選，不是新原件全鏈FULL-PASS或實機截取。

## 兩張紋理比較

只讀指定兩個ETF，按既有733E60/733EA0程式的gzip後8-byte wrapper與首128-byte XOR步驟解碼。兩個都取得有效DDS並由Pillow讀取：KR square001t是1024x1024簡化平面地圖；TC square001是768x768完整材質俯視圖。圖片不是同尺寸或同像素；小縮圖可見中央圓形廣場、左右道路、周邊建物配置相符，但沒有獨立量測每個world座標的像素對齊。

texture-comparison.json記完整SHA與尺寸；square001-comparison-thumbnail.png只作本機有界視覺查核，勿上Git或當原件payload公開。

## 最小可審方案：只新增一份descriptor（尚未套用）

新增Map/Minimap/square001.mmt，沿用TC原件結構/WorldSize1536，但TextureFile指向已有KR Map/Minimap/square001t.dds。這與現有town001.mmt指向town001t.dds並讀ETF的模式一致；不換TC紋理、不覆寫KR原資源、不改BOUND／碰撞／3D場景，不改EXE。使用新檔並記錄原件hash；回復僅移除本次明確新增的單一檔案。

這是非翻譯Client資源變更，使用者的翻譯配套免確認授權不直接涵蓋。主agent應先向使用者說明並取得本方案確認，再新增檔案。需實機驗收是否可解析loose mmt、背景出現、人物/NPC標記與道路對齊、城鎮維持正常。

## Server替代邊界

本輪已確認的Server38/12帶town/map ID，不帶TextureFile或mmt payload。這些靜態選路由Client依BOUND取檔；任意換地圖ID或改BOUND來借另一張mmt可能連帶更換場景／碰撞，不是安全的等價修復。尚未在有界來源中建立能單獨覆寫小地圖texture的Server封包，不宣稱所有可能封包均排除。官方新廣場/其他活動Map需另排，不應為修背景而擅自切換當前主線場景。

## 使用者追問：是否有其他廣場的mmt？（補充）

有。已完整列舉兩個MiniMap archive中名稱含square的mmt，並依_MapList的BOUND欄位做逐一對應，不把filename存在當成可直接切換：

|來源|已確認例|對應／限制|
|---|---|---|
|KR|Square03N_Avatar_Pool.mmt|Map1088的MAP與BOUND均Square03N_Avatar_Pool，精確對應；TextureFile是泳池版同名dds，WorldSize1536|
|KR|Square03D.mmt、聖誕／萬聖／櫻花／冬季等|共14個square命名mmt中的大部分；多數共享square003t.dds/WorldSize1536，但在本次_MapList未找到同BOUND的普通Square03D節點，不替它們臆造MapID|
|KR|Map4514的Square02D|BOUNDsquare002，但缺square002.mmt；只有square002t.etf。換4514不能據此說會修好小地圖|
|TC|square001.mmt|直接對應Map511/1088，現行KR場景Map511同MAP/BOUND|
|TC|Square_Beach001N.mmt|對應Map2714、BOUND精確相同；KR本次MiniMap archive沒有這個mmt|
|TC|Square03D與活動變體等|共13個square命名mmt；多數未在本次MapList找到同BOUND節點，需保持有限主張|

所有列到的descriptor WorldSize都是1536，但它們使用不同地圖與紋理；相同world範圍數值不表示道路、出生點、NPC位置或碰撞相同。若採用Map1088泳池廣場，應視為切換另一個完整廣場：同步驗BND、出生/NPC位置、互動與主線上下文，不能只借其小地圖貼到目前square001。

完整member/texture/sourcehash/MapList關聯表在square-alternatives.json；本補充仍未修改任何遊戲資源，未把使用者追問視為同意新增mmt或切廣場。

## 使用者新授權：先切泳池廣場＋完整移動遮罩等價比較

主agent轉達使用者已要求先改用泳池廣場；本子工作只讀原件並新提取BND，Server程式由主agent修改。沒有新增或修改Client mmt/texture。

### 泳池資料與安全佈點

- Map1088，MAP/BOUND=Square03N_Avatar_Pool；既有mmt TextureFile=Map/Minimap/Square03N_Avatar_Pool.dds，WorldSize1536。
- BND33617bytes，version2、1536×1536格、world1536×1536，完整layer0/1。
- BND SHA8086412206ffe2566427a5ec62d95496ae9a4c8fb2da109e186d5ce067c60765；新提取至runtime-observations/2026-11-07-pool-square/pool-square.bnd。重跑僅接受逐byte相同既有輸出，不覆寫。
- 精確套用目前LocalTutorialBounds規則：CanStand(900,900)=true、CanStand(906,900)=true；version2需以新的內容pin及allowValidatedStaticVersion2方式明確准入，不改header。
- 原12NPC有3個點落入blocked；僅泳池候選表調整：10013(850,940)→(855,940)，10014(870,940)→(865,945)，10069(850,910)→(845,910)。各點最近5-unit格網、另驗四方向3-unit margin，且與其餘NPC至少10-unit；是Server候選佈點，不是官方MEF。

### 完整比較結果

枚舉KR BoundMap中44個名稱含square的BND，並join所有_MapList中square相關MAP/BOUND及既有mmt；43份可按現行完整static0/1規則解析。msquare01多出layer2，當前Server不能准入，不猜該層語意或偷偷忽略。

每份都解壓完整兩層，分別計：整檔SHA、含extent與完整UInt32 layer payload的SHA、兩層nonzero聯集完整cell mask的SHA。另把768格square001以精確2倍最近區塊複製對齊1536世界1-unit格，與其餘1536格比較完整world-unit mask；不是只看尺寸／抽樣點。正規化後仍相同4個等價群：

|可移動遮罩等價群|整檔相同？|KR既有mmt|
|---|---|---|
|square002 / Square02DSakura|是|兩者皆無|
|square002_TL01 / Square02Dsunflower_TL01|是|兩者皆無|
|Square03D / Square03D_Sakura / Square03N_Fullmoon|否，但兩靜態層與完整移動mask相同|前兩者有，且mmt內容本來就相同（square003t.dds/1536）|
|Square03N_Avatar_Pool / Square03N_Avatar_Pool_Kr|是|Pool有，Pool_Kr無|

原square001沒有與其他廣場形成相同遮罩群；不能因world尺寸都是1536就拿Square03D或泳池小地圖來貼原square001。選泳池1088本身已有完整descriptor/texture，因此不用補Client資源即可先測這一個Server切換候選。

### 共用mmt的界線

上述相同mask群支持共用同一幾何映射的候選，但BND只涵蓋Server目前採用的兩靜態層；動態MEF物件、實際藝術地面、marker/texture與地標對齊沒有因此自動等同。優先直接使用資源原本已共同引用的mmt（Square03D/Sakura）；Pool/Pool_Kr整檔相同支持後續共用，但後者未在本次MapList找到直接MapID，不能直接發一個猜測ID。

可重現工具audit_square_bounds.py（numpy1.26.4）、完整hash/group/佈點資料square-bounds-equivalence.json。沒有刪改原件、沒有改Client、沒有開/附加遊戲、沒有Git提交。
