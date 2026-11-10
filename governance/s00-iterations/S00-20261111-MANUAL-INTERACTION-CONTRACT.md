# S00：單次手動互動點契約

SERVER_RECONSTRUCTION_NOT_NATIVE_MEF，基礎原生邊界見CHECKPOINT1-NATIVE-BOUNDARY。
沿用scenario JSON新增signal.event=CheckpointInteracted，搭配interaction物件；不增加傳檔或玩法opcode。
interaction含非零key、region、requireGroupCleared（預設false）、requiredFlags（ALL，預設空）、
可選markerKey及markerRadius（預設6）。每節點最多8個不同key，marker需避開category0出口與其他marker。
全定義仍最多64個唯一flag，每個互動前置最多16個。集合凍結、實例旗標及Fork沿用條件出口契約。

互動row固定category1、automatic0、auxiliary0，身份是category/key；marker另外固定category0且關閉。
全部出口／互動／marker需一次0027發布，不得追加導致覆蓋。組內清除或前置flag滿足才啟用的點，
透過0048(category1)更新；使用後立即停用，事件只給該instance的固定flag，沒有Client自由字串設定。
C2S001C(1,key)只作意圖，Server仍檢同instance/當前節點、擁有actor、alive、enable及目前Server位姿在region。
成功不換圖、不發正式任務／獎勵／物品，也不保存副本中途進度；接著共用條件引擎評估出口。

允許互動依賴先前typed flag，定義驗證以有限閉包確認每個producer可在所有入口路線完成。
以互動flag通過出口，保證該flag之互動前置也已完成，匯流仍取每條入口保證的交集。
不接受無來源旗標或相互鎖死的互動定義；安全／錯誤／重送等延期測試另列，現在只做必要正常流程。

獨立ContentInteractions：map193清一隻20HP怪後，回可見提示圈按Z，設定point-used、開出口；
走到出口按Z進map194，再清怪並到出口按Z結算。第二圖要求第一圖旗標，互動marker不要求改色。
這是手動點功能示範，不是3D槓桿、寶箱、破壞物件或官方存檔系統。互動flag可在清怪前收集但出口仍要全組清除。
Shared Story與隔離場使用同adapter。正式故事與固定Phindos保存資料不改；使用者目前不便測，先累積測試列。
