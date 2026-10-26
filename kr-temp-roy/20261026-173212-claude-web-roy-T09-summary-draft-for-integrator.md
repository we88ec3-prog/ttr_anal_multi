# KR T09 彙總草稿（供整合者併入）— 關卡內移動與同步：碰撞、本機輸入、C→S/S→C 封包、位置補正

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 17:32:12 +08:00`
- Target: KR `Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 性質：**整合用彙總**，不含新的機器碼分析；每項皆指向我於 `kr-temp-roy/` 提交的原始筆記（檔名關鍵字見括號）。僅靜態；未執行遊戲；未讀任何遊戲資料檔。
- 狀態標記：【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認。已於各筆記中修正的錯誤列於「更正」一節。

## 一、資料流總覽（皆為【確認】，除非標註）
```
本機輸入 (FB9005..8 / 滑鼠) → 546850/546D50 → 546780 → 546100（輸出記錄 {flags word, heading byte}，含 545F30 前探與 5464C0 朝向搜尋，依 82CDF0 碰撞）
   → 5452C0（CController vtbl+0x2C）：每幀對 3 個槽呼叫 vtbl+0x48(=546100)，把有變動者組入 cmd 0x000A 封包
   → CIocpNetwork（[0xFBA854]）vtbl+0x10(8069A0) → 8060D0 佇列 → 8061A0 → 807830（外框 len+0x0BBB+和檢核＋XOR 串接）→ socket
S→C：IOCP 接收 → 807B40 拆外框 → 8040A0 入 0xFC10D0 雙緩衝 → 804740（封包泵，CClient vtbl+0x30 內）→ 4930E0 → Scene vtbl+4(4C4670)
   → 表 B（scene+0x5EAC+8·idx）→ 表 A（scene+4+8·idx，4ADD50 建，預設 4B7D40）→ vtbl+0xC
   首 word＝命令索引 idx；處理器簽名 (data, len, idx)，ret 0xC
```

## 二、碰撞（筆記：`collision-query-82CDF0`、`boundmap-collision-object-origin`、`bnd-parser-and-tile-grid`、`tile-builder-8330E0-blocked-bit`、`collision-users-probe-545F30`）
- 【確認】`4CABE0`（10 個 actor 類別 vtbl+0x54）→ `82CDF0`（兩層皆 0 才通行）→ `832DA0` → 磚格（均勻磚存原值、其他存「dword≠0」位元圖）。`FAB1D0`＝`0xFAB130+0xA0`，由 `4DF35F` 設定；資料來自 `Map/BoundMap/<name>.bnd`（`4DF1A0`，"rb"）；檔頭 0x534 bytes、32 個圖層條目。
- 【確認】`545F30`：沿朝向前探 3 點（1.5/1.6/1.7 × dist）；`5464C0`：反向→軸向→0..255 暴力搜尋朝向。
- 【推測】兩層 `slot0/slot1` 的遊戲語意、dword≠0＝「不可通行」。【未知】`727190`（疑解壓）、`82F660`。

## 三、本機輸入與 C→S（筆記：`hero-input-record-546100-546780`、`controller-frame-5452C0-input-packet-0x0A`、`CIocpNetwork-send-8069A0-8060D0`、`send-queue-drain-8061A0-frame-header`、`frame-mode-A02C-and-recv-parser-807B40`）
- 【確認】輸出記錄 `{+2 word：bit15＝移動位＋低 15 位旗標；+4 byte：朝向}`；朝向來源優先序 鍵盤（FB9005..8 ＋ 相機偏航）＞ 546B50 ＞ 滑鼠。
- 【確認】cmd `0x000A`：`word 0x000A`＋4 bytes（堆疊殘值，來源未知）＋N×5 bytes `{word [actor+4], word flags, byte heading}`；單筆 11 bytes。
- 【確認】外框：`[conn+0xA02C]` 唯一寫入＝2（`805D02`）→ 出站走 `807830`：`{u16 len, u16 0x0BBB, u16 明文位元組和}`＋payload（`out[0]=in[0]^0xB6; out[i]=in[i]^in[i-1]`）。收端另認 `0x2633`（8 bytes 標頭、`^0x7C`＋`727190`）、`0x1A68`、`0x22D7`。
- 【未知】5452C0 標頭 +2..+5 的 4 bytes 來源；`4930E0` 對 channel≠2 的資料。

## 四、S→C 命令索引（表 A，索引＝封包首 word；部分列表。筆記：`handler-table-4ADD50`、`scene-handler-table-owners`、`recv-dispatch-chain`）
| idx | 處理器 | 內容（筆記） | 狀態 |
| --- | --- | --- | --- |
| 0x0B | 4AFE60 | 移動狀態：8-byte `{id,朝向,旗標,X(u16),Y(u16)}`；寫 `actor+0xE2` bit15、`+0xE4`、`+0xE8/EC`、殘差；本機英雄決定 `[ctrl+0x74]`（`cmd-0x0B-handler`） | 【確認】 |
| 0x01（及 0x16【推測】） | 4AFB80 | 位置設定：10-byte `{id,float x,float y}`；0x16＝硬設，其他＝殘差（`position-set-handler`） | 【確認】結構 |
| 0x18 | 4B2730 | 目標＋步數：12-byte `{id,float x,float y,word 步數}`；`4CA890` 逐幀逼近（`cmd-0x18`） | 【確認】 |
| 0x1A | 4B28D0 | 依 id 移除 actor（刪除物件、抹除 map）（`cmd-0x1A`） | 【確認】 |
| 0x94 | 4AF1F0 | 建立 actor：24-byte，含新 id、類型、int16 x/y、朝向（`actor-register-4DFF30-and-spawn`） | 【確認】 |
| 0x12 | 4B24F0 | 切換地圖（讀 `[packet+2]` DWORD → `4DF510`；T06/T07） | 【確認】指令；語意【推測】 |
| 0x0A | 4AF920 | **未讀** | 【未知】 |
- actor 登記：`holder(0xFAB130)+8`＝`0xFAB138` map（鍵 word `[actor+4]`，值 actor 指標）；插入 `4DFF30`，移除 `4DFBC0`。
- 場景類別（18 個）各自持有表 A（4ADD50 基底預設）與表 B（子類填入）：CDailyDungeonField / EternalTowerField / InfiniteDungeonField / FirstScene / DuelSquare / MissionRoom / RaidRoom / DuelField / DailyDungeonRoom / DecisionBase / Square / MissionField / DuelWaitRoom / Expedition / Login / ScenarioField / Tutorial / RaidField（皆 `Scene::`）。

## 五、位置補正語意（筆記：`cmd-0x18`、`residual-consumers-4CAD60-4C8A90`）
- 【確認】三種座標：spawn＝int16；0x0B＝u16；0x18/索引1＝float；一律轉為 float 後存入 actor（`+0xA0/+0xA4` 位置、`+0xB0` 朝向、`+0xC0..`/`+0xE8..` 目標、`+0xD4` 插補旗標、`+0xD8/+0xDC` 殘差）。
- 【確認】0x18：每幀位移＝剩餘距離／剩餘步數，經 `4CABE0` 碰撞；步數歸 0 以 vtbl+0x44 設到目標、清 `actor+0xE2` bit15。
- 【確認】殘差由 `4CAD60`（每幀、`|R|²>0.01`、剩餘 `<0.04` 沖銷；`mode0` 含碰撞）或 `4C8A90`（一次沖銷、無碰撞）吸收。
- 【確認】`[ctrl+0x74]`：被 `4AFE60`（=1／=0）、`4AFB80`（=0）、`5452C0`（=0）寫；`546100` 讀它決定是否走 `5464C0`。語意描述【推測】：伺服端回報「不動」而本機剛送「動」時觸發朝向搜尋。

## 六、更正（相對我先前筆記／既有紀錄）
1. 先前我寫「`4CABE0` 呼叫 `4CAD60`」的反例：`4CABE0` 本體不呼叫它（`4CAD60` 的呼叫者＝`4CAAEA`、`4CC504`、`4D05C9`；見第一份筆記）。
2. 先前（`handler-table-4ADD50`）把 `4ADCD0／FE18A4` 當成處理器表存取器 → **錯**；它是另一個容器。表在每個 Scene 實例內（`scene-handler-table-owners`）。
3. 先前（`recv-dispatch-chain`）把處理器參數寫成 (a,data,cmd) → 實為 **(data, len, cmd)**（`cmd-0x18` 已更正）。
4. 先前（`cmd-0x18`）把 `[actor+4]`＝map 鍵標為確認 → 後降為推測，現已因 `4DFF30` 插入點而**重新確認**。
5. `4DFBC0` 內 `ctrl vtbl+0x1C(i)`：取槽 actor（非「通知」）。

## 七、剩餘缺口（建議優先順序）
1. 表 B 在各 Scene 子類的內容（尤其 Field 類）與表 A 索引 `0x0A`（4AF920）、`0x16` 的表項。
2. 5452C0 標頭 4 bytes；`[0xF9423C]`／`[0xFBA7B0]`（發送節流）語意。
3. 座標單位與 `.bnd` 格（cell）之間的換算（`82CDF0` 的 `this+0x14/0x18` 縮放與 u16/int16/float 座標的關係）。
4. `4CAD60` 步長公式；`[actor+0x3A8/0x370/0x158+8]` 語意；`vtbl+0x58/0x5C/0x68`。
5. 屬 T06/T07：`[CClient+0xB8]`（目前場景）的設定處、`4B24F0`（地圖切換）之後的流程。

## 八、建議
- 這批筆記可直接作為 T09 的「命令產生權責」與「位置補正來源」兩缺口的證據；請整合者在採用前以 `4409808e…`、`508a8f…` 的既有描述對照（我未逐項核對）。
