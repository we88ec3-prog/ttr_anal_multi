# S00：原生載入背景開始／結束候選

接續REQ-0017的v7實測：可到廣場，但使用者明確回報沒有可見轉場。不是以首次到達
取代完整教學／任務結算；本輪未改Client或加固定sleep冒稱修復。

## 原始來源與分派

原始KR BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
沿既有E41原稿 `kr-extra-roy/20261029-230619-chatgpt-web-roy-E41-RR0005-callback-subobject-vtable-command-dispatch.md`
blob `1606a102a4553b52d417f383cb78b8eca2dc2f38` 的兩層分派原點，重新核對有限BIN指令：

- 48AAD0：signed16 command加倍後以scale8索引，callback在dispatcher+16*cmd+8。
  dispatcher原點是完整Client C+200，不可把C與C+200混算。
- 493170：C+438寫494860，C+448寫494A90，故分別是command23／24。不是43／44，
  也不是只憑第二層場景表找同號handler。
- 494860：payload+2、+4是兩個signed WORD，交5550E0；設定loading相關旗標、
  經繪製／資源處理後return100。494A90清相關旗標與顯示資源，亦return100。
- E41的4930E0／804740對100結果的pump停取仍有條件；本輪不聲稱網路寫完即已顯示，
  或正式Server一定用本輪順序／持續時間。C2S24 roster後續與S2C24的用途須按方向分開。

[唯讀檢查器](../inspect_loading_display_sources.py)與[有限byte／資源結果](evidence/S00-20261101-LOADING-DISPLAY.json)。
所有反組譯從保存函式入口開始；視窗不是全文CFG驗收。PE各section獨立映射，.rdata
不能用.text偏移：StartLoading字串在C10458、EndLoading在C10468；55D7E0的限定註冊
支路把兩者都綁8DC2F0，該原始入口為33c0c3（return0）。這個綁定本身不能拿來啟動loading。

## 與先前38／CFadeObject路線分開

552FC0的type0／2與FB7490／FB74A0查表會構造CFadeObject，仍可用於地圖標題呈現；
但不能因此當成_LoadDisplay完整載入背景。這次定位的是554FC0解析_LoadDisplay.xml、
554B30處理BackGround/Category/Param Texture及5550E0按category/index選背景的另一條線。
沒有把先前「38會建fade」升格為「38已恢復loading」，也沒有發現MEF下載／接收格式。

Table.stp carrier `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`；
_LoadDisplay.xml member `49aba61c484fc27964e2c75ecd487e9a1e6a4fdcf9b52173cbed3088167ee265`。
selected metadata：Category1/index0是General01，index5為Square01；Category2是六張Mission；
Category3/index0是Square01。5550E0對category2有隨機選圖支路，index仍須合法。
UI/Texture.stp carrier `2a04d6bbb5687a9a680a66d75703ef1cb4a04b941f9501af9ab1b185060c0f67`
含對應General01／Misson01／Square01的.etf member；存在相同basename不等於本輪已證
全部DDS→ETF解析或實際renderer成功。原件保持唯讀，沒有解出／提交整份圖像。

## Server候選接線

只在既有opt-in tutorial exit模式（有squareBounds）啟用：

| 轉移 | 開始 | 原本合法流程 | 結束 |
| --- | --- | --- | --- |
| 首戰 | 23/category2/index0 | 05/type1→C2S09→context/map190→玩家／技能／三怪→14 | S2C24 |
| 戰後返回教學 | 23/category1/index0 | Server勝利保存→map188／重建→14／4C14 | S2C24 |
| 教學末段到廣場 | 23/category3/index0 | 69/type7→C2S43→Town5/context/map511／玩家／12NPC→14 | S2C24 |

23 payload為opcode WORD+category WORD+index WORD，共6B；24候選2B。
命名／教學／battle模式預設路徑不改；沒有新造map-ready ACK、延遲、Server完成旗標或獎勵。
圖類別／index選擇及相對scene順序是可測試的Server候選，不冒稱官服已捕捉序列。

21個正流程合成案例通過；TCP／SQLite旅程明確核對上述開始／資料／結束的順序，
保留先前combat／ownership／廣場移動停止驗證。這是合成先決條件，實際載入背景是否可見、
有無殘留遮擋、後續控制需另由使用者測試；此報告提交時尚未部署。異常／重送／故障等暫緩。
NPC業務事件與合法Quest14/16結算保存仍未補齊，不宣稱完整goal完成。
