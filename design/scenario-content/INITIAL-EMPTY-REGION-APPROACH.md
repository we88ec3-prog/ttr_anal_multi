# 初始空場：正常接近區域才生怪

2026-11-23。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**。補
[D07](../../kr-extra-roy/MEF-level-functional-closure-20261118/DEVELOPMENT-PLAN.md)
的初始空場與 RegionEntered 公開內容採用，沒有新增 runtime、schema、opcode 或 Client 修改。
核對目前版本後，具名 `requiredBoss.waveId` 與 `BossDefeated` 已在 Case693 整合範例及通關
證據中存在，本批沿用，不把歷史規劃中的缺項重算成新引擎功能。

## 內容與玩家操作

[新候選](phindos-stage462-case693-empty-approach.scenario.json)，SHA256
`4608f3ed38e185e473aa659bea98dec741f888bfa2a54c2ec447db2ce1ee7988`。
基準為保留的 `phindos-stage462-case693-integrated.scenario.json`，SHA256
`424b8d5afc3aa822e286e384c7924334ac3800b3b748c6fe521e048b5ce59026`。

只修改入口 node10／Map3430：把原1004／PRE1／4EXP那一隻從 `encounters` 移至
`entry-approach` timed wave，delay0、requiredFlags=`entry-approached`；新增同名旗標的
RegionEntered，中心 `(416,392)`、r16。這是原入口怪的位置及原BND可達點。
原掉落183明確綁到該波；沒有多生成怪物、額外掉落或改變付款／收益。
其他節點、地形、AI、兩出口、頭目階段及結算政策保持。原件／舊版另存保留。

正常登入後在廣場建單人隊進馮德斯，選Stage462／Case693。入口仍安裝玩家及原圖，
但尚無戰鬥怪；正常走向 `(416,392)` 的圈內，Server觀察進區後才生成1004。
擊倒、Space拾取183，到原出口機關付款，再走原波次、分支5或6、合流、頭目及結果返回。
兩條路均88EXP，回Map182原隊伍。這是 Server 發出生怪包，不是 Client 本地自主生成。

## 已驗範圍

[最終收據](../testing/empty-approach-20261123.receipt.json)，SHA256
`c7a5bb054c9767659aa9095ec53700eb5c7fe9d112c0ba96ff6421f113686a31`。

- 來源兩路、正式工作台保存配套兩路、原整合控制兩路，共六條正常 TCP。
  新路先在空場正常等待3秒，Health0、必要波仍pending、groupCleared=false、出口關閉，
  進區前旗標不存在；正常移動後旗標成立、1004為60HP、pending清除，出口仍未開。
  RegionEntered訂閱1→0並只退訂一次。不是把空場當清場，也沒有直接設旗標／出生的測試捷徑。
- 原1004仍掉183並被正常拾取、機關11一次消耗183x1。六次訪問皆有身分，兩岔路都完成，
  既有頭目到場／75%護衛時仍ACTIVE、具名boss-arrival死亡後設boss-defeated，清場延遲後才結算。
  每路一次88EXP存檔並回原村原隊伍。原控制仍在入場即生成原怪，沒有被新探測流程改寫。
- 普通狩獵工作台正常保存與匯出三檔 scenario／AI／manifest；兩次ZIP bytes相同，內容與
  原 AI raw SHA精確相符。普通工作台原本不開放 loop-only preview HTTP API；首輪工具誤用
  該入口得到400，已改回普通保存／匯出時的正式驗證，沒有修改 API 或宣稱該 preview 通過。
- 保存同版的獨立真實時計 Host 走正常登入、建隊、進村、選關、初始空場接近、戰鬥、拾取、
  付款、六圖、頭目與結果。實際入場怪物列0、接近前0／後1，出口前後均關閉，最終原隊回村；
  SQLite一次完成20EXP加已入帳擊倒，合計88EXP，角色39000→39088，成本／拾取守恆。
  Host無測試時計或內部Handle/Poll。精確頭目階段快照是TCP證據，不移用成Host實機畫面。
- Host／Inspect／Admin三個Release零警告／錯誤；796 HappyPath全通過，零失敗／略過。
  此內容採用沒有新增引擎行為；編輯後的正常全路線是本批主要驗證。

隔離 Admin／Host已停止、種子DB未變；沒有替換使用者現用服務或遊戲資源。前置仍是準備好
教學／Q15與Lv15帳號，不能算自然新帳號或指定v2人測。空場玩法提示素材、Client畫面／自主AI、
其他D07操作、原延後的錯誤／邊界／重送／重登／故障／併發／安全／壓測仍各自待辦。

## 封存分析保持

上批把採用註記插入舊 gates-transitions/report.md，會使其封存 manifest 的報告雜湊不同。
本批只移除該追加註記，恢復原報告SHA256
`6a9c1af41a5da267b635603d032bd83eea07a048b06d876dfd2080a6776a274b`，
並核對該包12檔原 bytes／SHA全相符；沒有改寫 manifest 來遷就註記。
封路採用進度仍在[獨立正常路線文件](../testing/STORY-SEALED-GATE-NORMAL-ROUTES.md)與
[目前功能索引](../../governance/MEF-FUNCTIONAL-COMPLETION.md)，舊報告繼續表示原分析時點。
