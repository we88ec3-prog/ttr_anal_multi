# S00 — 正常教學進展、入場朝向與轉段殘留移動

接續[world bootstrap](S00-20261101-TUTORIAL-WORLD-BOOTSTRAP.md)。本輪僅使用者操作
指定工作副本；Agent沒有啟動、操作、附加或修改 Client，原件／資源保持唯讀。
所有新需求為 CANDIDATE，沿用 RR-0008／FLOW、SCENE gap；正式契約、T01驗收與
Server normative pin `dd69ec9de353a695d25c6db8e362ff471ea0c137` 均不升格。

## 實測成功與尚存問題

使用者已明確回報：人物與頭像正常，方向鍵到第一T後進下一段；接著滑鼠移動與
視角教學通過，停在切換角色提示。這是指定修改工作副本的實測成功，非原始KR全版。
第一輪可玩進展不因後續bug被抹除，也不代表完整教學／戰鬥／廣場完成。

另有兩項問題：

1. 使用者提供截圖並指出「進場應為視角向東，目前進場是向南」。**向東是本次
   使用者提出的預期**；截圖／口述本身不證明官方伺服器朝向值。REQ-0010追加runtime。
   原圖僅保留本機，SHA256 `96da31131055641804ed9d2628d1fcbe59e2612d5ef45cbc4e26fe7c395c61fd`。
2. 使用者隨後指出「角色一直向前撞牆，卻不能進行其他移動」。這是在正常教學發生，
   不是刻意異常測試。新增 **REQ-0011／GAME_RUNTIME_OBSERVATION**：轉段與輸入結束
   後終止殘留移動，下一段可正常繼續。切角保留位置是正常後續開發，不是已成功實測。

實際 v1 journal：08:16:29 UTC primary admission及scene/tutorial entry；90個C2S0A/11B，
首筆08:16:32.0389405，末筆08:19:30.6575323。四個3F/8B在08:16:34.5810345、
08:17:11.7266744、08:19:28.4361055、08:19:35.2910942；92次world候選寫入包含
bootstrap、intro與移動回覆。**只記opcode／長度，沒有保存最後flags、方向或scene ID**，
不可將合成scene4冒充這次觀察。舊版沒有通用轉段stop／input-silence watchdog，
故輸入不再更新時最後run狀態可能持續；這是有程式缺漏支持的原因，實際修復仍待重測。

## 朝向與原生鏡頭的限定核對

原始BIN SHA仍為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
[驗證器](../verify_legacy_login_sources.py) `--tutorial-pose` 的
[58片段／20有限windows](evidence/S00-20261101-TUTORIAL-POSE-CAMERA-RECHECK.json)通過。
使用既存Ghidra原稿配合唯讀PE／Capstone5.0.9；REA前段無可用結果，沒有假稱全函式
REA／T01 FULL-PASS。新增範圍只支持：

- 4AEB4B把actor record+22（payload+24）byte送virtual+58；CCharacter vtable
  C07B44+58指4C8C30，此setter保存byte到actor+B0。
- 4A9720 wrapper呼叫54C410；後者54C550讀當前actor+B0，以FB7C20角度表取值，
  在54C5A9加C55AD8約PI後寫camera+20。並非角色朝向永遠等於鏡頭視線。
- 4449D0表步長常數約2PI/256。64對應約PI/2；沿既有方向表sin/-cos限定來源，
  是+X候選。以64實作本次「東向」預期，仍須使用者畫面確認。

所以Server在初始actor明示64，序章後以idle facing64恢復；不修改鏡頭函式／Lua／資源。
這不是找到一個官方「設定攝影機朝東」回覆，也不保證所有場景與時序已驗收。

## 靜態碰撞資源與位置保留

舊 `anal/movement_position.py`以Client tick差及wall time推算，沒有碰撞，不能直接搬作
Server權威。舊 `read_walkable_grid.py`／其他runtime工具含Frida，僅讀原稿，沒有執行。

目前 `Map/BoundMap.stp` SHA256
`07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`，
[唯讀資源驗證器](../inspect_tutorial_bounds_resource.py)與
[資源metadata](evidence/S00-20261101-TUTORIAL-BOUNDS-RESOURCE.json)核對：

| member | SHA256 | 結構／正常路線 |
| --- | --- | --- |
| town000.bnd | ee69d4ae60d468862761675f11f41c185f5810c7d1150e5876c4d9dd756ea776 | 768×768，world768×768，兩個zlib u32 layers；231/144、275/144、311/149、360/170、383/315、440/394的兩層皆0 |
| scenario_town000.bnd | 7c98d3d5c5512cfe20f2946abc27c1c94424474ee6450fa3593693a4c5139bfc | 同尺寸，231/144、275/144、311/149、360/170第二層為1；後面兩點及368/272兩層0 |

Header+20=0（本檔version值），+24/+28為整數尺寸，+2C/+30為world float尺寸；
0x234 header後是壓縮層，descriptor從+34、stride16，包含offset／compressed bytes／
expanded bytes／cell count。原生830040讀34B並比較version3；本檔走82F660的234B
舊格式reader，cursor從header+38讀compressed size，+4 expanded、+8 count，複製count×4。
Server另要求descriptor offset與順序一致，是嚴格本機讀取政策，不冒稱原生也驗offset。

837C99 row-major copy與837D08 nonzero→packed bit支持靜態u32 grid解讀；82CE25/30
以bounds scale轉換候選XY，82CE51/5D檢查兩層。舊packed query看似`pointer - quotient`，
但**C55690是負0.125**，不能照抄為減去正的index/8；本輪直接保留解壓u32層，避開
歷史probe誤讀。原生動態override／MEF屏障、clamp／轉整數所有邊界仍未全文驗收。

資源解析不證官方BIN配套。只公開metadata／驗證器，遊戲BND未提交Git；可選擇抽出至
新的本機檔給Server唯讀。私庫reader再次實際讀取上述SHA，六個正常路線點皆clear。
不將舊修改版runtime的clear判讀當成唯一證據。

## Server候選修正／驗證／部署

本輪以私庫 `1dcd9e80d07dda4c4d93d4d215fbca25441a319d` 為基準的working-tree build：

1. 正常3F1000/scene2..8/event1回stop movement／idle animation，不授予Quest完成或獎勵。
   scene範圍及回覆關係是Server候選，這次metadata未保存其精確scene數字。
2. 750ms無正常移動輸入即停止；primary單讀取迴圈以100ms輪詢，同一writer送stop，
   送前確認當前Session；沒有平行socket read或重疊write。750/100ms為Server政策，
   非原生官方時限。正常held輸入約133ms更新只是本次metadata現象，不是永久保證。
3. 額外指定唯讀town000.bnd才能啟用Server pose／切角：用Server monotonic receipt time、
   30units/sec、每次最多750ms、四分之一unit靜態候選步檢查；不信任Client tick。
   停止及切角時同步Server位置；切換自有角色只重建actor/control，不重送map、不回出生點。
4. 這是**Server-owned prototype authority**，不冒稱精確原生時鐘／Client pose。
   動態MEF障礙、Client與Server速度校準、長時間漂移、多人與持久化仍有缺口。

正流程Theory三列（world OFF、world ON、world＋static pose）合計**11 cases通過**；
仍207方法／9正向方法／198暫緩。TCP／SQLite正常case驗證東向byte64、移動後位置、
同alias owned-role切角、正常轉段stop及沒有新request時的silent-release stop。
用合成all-clear BND與可控Server時鐘，不把它說成真遊戲碰撞／鏡頭成功。
Host建置零警告／零錯誤；實際資源的獨立reader核對也通過。異常、競態、安全、壓測未跑。

使用者確認關閉遊戲後，再查無primary連線，08:30:46 UTC啟用獨立輸出新Host。
Network DLL SHA256 `427430c312fdd68be5be412d81c06c97646a1807a038bd2ce394a60ab2c0cb90`；
Host DLL `882179f938be369803206d5ea5c808a2604a05d84fdcffb29a2b2515d8058e62`。
Client SHA仍 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
非同步結果卡安排：正常登入→序章後視角→鍵盤／滑鼠／視角→轉段停止→按提示切角→
下一T；遇新劇情／NPC／戰鬥入口或卡住即停。**新版人工結果待回**。
完整新帳號任務、戰鬥與進廣場仍未完成；沒有修改／接觸as_server_spec。
