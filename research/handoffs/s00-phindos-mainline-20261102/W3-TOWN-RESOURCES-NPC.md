# W3：馮德斯村場景、地圖、bounds、NPC及互動

指定extra/roy3，使用已建立的extra/roy3分支；先讀[總卡](README.md)。最新使用者已指定
核心AI／MEF與連段由S00親自處理，因此本輪不要重做那兩項；專注明天要用的進村資料。

1. 核對Town1 TYPE1／map182→town001D／BoundMap town001與正常村落scene/controller/UI
   的連接；0099/type3 MissionRoom是舊候選，不可僅憑名稱指定正常村場景。0038 Town1
   context不能當自動載圖或玩家spawn；005F／0069／0099 type值分域。
2. 村初始化需要的NPC／玩家／角色資料、controller綁定、ready／loading順序。S00新查23/24
   載入背景介面見governance/s00-iterations/S00-20261101-LOADING-DISPLAY-LIFECYCLE.md；
   不重做已界定路線，查它在村落前置與收尾的依賴即可。
3. Town1靜態NPC列表10001/10002/10003/10008/10013/10014/10047/10048/10015；
   與Quest117等主線giver對照。角色顯示、checkpoint／NPC event category、本地F事件、
   C2S001C／003C／003F／0036等各自producer要分開，避免點NPC後鎖住卻無Server接續。
4. 合法出生／返回點與碰撞資料：區分FLD擺設、Portal效果、graph節點x/y、結果演出座標
   與真正Server玩家spawn。沒有來源便保留未知，另列可明示重建政策及需要的正常驗收。
5. 先交Town1 BND version0／world1536與地圖NPC資料；再查Field19兩BND header version2
   與舊候選version0解析器的實際格式差異，不可直接改version或all-clear。只提供格式／
   bounds依賴，不展開核心AI。村／廣場旅行003D與Town開放7E/80另列未用到的後續接口。

交付村初始化／NPC事件／資源與座標來源／bounds版本差異的實作矩陣，列hash及未知。
新增W3-RESULT檔，Commit／Push回精確commit／blob SHA。不啟動／附加／修改Client，
不操作Server，不自行派訊息給別的對話或改Task owner。取消／重登／往返等暫緩測試只列清單。
