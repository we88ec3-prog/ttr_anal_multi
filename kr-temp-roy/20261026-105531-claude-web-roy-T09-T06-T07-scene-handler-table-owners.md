# KR T09（附 T06/T07 線索）— 處理器表 4ADD50 屬於 Scene 基底：19 個建構呼叫點對應 19 個 Scene 子類；並更正上一份對 4ADCD0／FE18A4 的誤認

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 10:55:31 +08:00`
- Scope: `Tartaros.bin` PE32 x86；`4ADD50` 的 19 個直接呼叫點（含其後的 vtable 寫入與 RTTI）；`4F0AE0..4F0B37`（讀）；`FE18A4` 資料引用掃描；分派函式搜尋（索引化呼叫模式；**未找到**）
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…T09-T02-handler-table-4ADD50.md`

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認

## 一、更正前一份（【確認】）
- 前一份把 `4ADCD0`（回傳 `0xFE18A4`）寫成「表物件的存取器」。**這是錯的**：`FE18A4` 由 `4F0AE0` 初始化為一個 8-byte 節點（`[node]=&FE18A4`、`[node+4]=0`，其後 `FE18A8..FE18B4=0`），是 **容器（疑為 list/map 頭）**，與 4ADD50 的處理器表無關。`4B5F10..4B6040` 那組 `ret 0xC` 小函式只是借用該容器。處理器表**不在**固定全域位址。
- `4ADD50` 不是「單例表建構器」，而是**基底建構函式**：`eax/esi＝this`，在 `this` 內填 `0xBD5` 筆 `{handler, ctx}`（handler 在 `this+4+8k`）。呼叫點之後立刻 `mov [esi], <derived vtable>`，故每個子類實例各自持有一份表。

## 二、4ADD50 的 19 個呼叫點與其 vtable／RTTI（【確認】；vtable 取自呼叫後第一個寫入 `[esi]` 的 `0xBF…/0xC0…` 位址，RTTI 由 vtable[-4]→COL→TypeDescriptor）
| 呼叫點 | vtable | 類別 (RTTI) |
| --- | --- | --- |
| 422FB3 | BF6F10 | Scene::CDailyDungeonField |
| 4369D2 | BF9BAC | Scene::CEternalTowerField |
| 4564F2 | BFD974 | Scene::CInfiniteDungeonField |
| 48F6EA、49530E | C072B4 | Scene::CFirstScene（兩處呼叫，後者可能是另一函式；未區分） |
| 4B9129 | C06F7C | Scene::CDuelSquare |
| 4B9379 | C07098 | Scene::CMissionRoom |
| 4B9469 | C074C0 | Scene::CRaidRoom |
| 4B9AA8 | C0710C | Scene::CDuelField |
| 4B9D89 | BF74CC | Scene::CDailyDungeonRoom |
| 4B9E69 | C06F3C | Scene::CDecisionBase |
| 4BBB73 | C06FB0 | Scene::CSquare |
| 4BC6A3 | C0705C | Scene::CMissionField |
| 4BE3C3 | C07158 | Scene::CDuelWaitRoom |
| 4C1416 | C07280 | Scene::CExpedition |
| 4C2F6A | C072FC | Scene::CLogin |
| 4C46F2 | C073B4 | Scene::CScenarioField |
| 4C4AC2 | C073E8 | Scene::CTutorial |
| 4C54E3 | C0748C | Scene::CRaidField |
- 類別名皆為 RTTI 字串原文。這些建構呼叫之間是否有繼承鏈（例如 CDecisionBase 是其他的基底）未驗；「所有 Scene 子類共用同一基底表」只對表中列出的 18 個類別為【確認】。
- 子類建構函式在呼叫 4ADD50 後的欄位寫入樣本：`CDailyDungeonField` 設 `[esi+0xBD54]=0`、`[esi+0xBD58]=float(C556C0)`，位於表（`4+8·0xBD5≈0x5EAC`）之後的區域；這些欄位語意【未知】。

## 三、對 T09／T02 的意義
- 處理器表是**每個場景實例各一份**（`this+4+8k`），預設處理器 `4B7D40`；子類可再覆寫。→ 「索引 0x12＝4B24F0、0x18＝4B2730」只是 **4ADD50 提供的共同預設**；子類建構函式是否另覆寫同一索引，本次**未檢查**。
- 因此 S→C 命令的處理與**當前場景類別**有關（遊戲「Scene」狀態機），此點可作 T06/T07（場景切換／關卡進入）的線索：進入 `CSquare`、`CDailyDungeonField` 等不同場景實例時，使用各自的 handler 表（【推測】）。
- 與 T09「關卡內移動與同步」：關卡內（Field 系列）的 S→C 移動封包處理器應位在這類 Field 場景的表內（【推測】）；索引 0x18 的 `4B2730` 與 `4409808e…` 關聯，尚未重驗。

## 四、分派者仍未找到
- 掃描 `.text`（`401000..7D0000`）中形如 `call [reg+reg*8+4]`、`mov r,[reg+reg*8+4]` 後接間接呼叫、`lea …*8` 後 `call [reg+4]`、與 `cmp reg,0xBD5/0xBD4` 的邊界檢查：**皆無命中**（`[reg+idx*8+4]` 載入有約 60 處，抽查 40 處，僅為 vector／map 元素存取，與本表無關）。
- 可能原因（【推測】，皆未驗）：處理器以索引乘 8 後加位移（`disp32`／`this+off`）取得；或經由子類／介面的 virtual 函式再轉手；或 handler 與 ctx 被視為 `{fn, this}` 的 pair 物件而用別的方式讀取。
- 下一步（T09/T02）建議：由「Scene 類別」往上找接收端：搜尋 vtable 中「處理封包」的虛擬函式，或 `807B40` 交付鏈（`804310` 節點池 `FE3358` 的消費者，`[conn+0xA080]` 指向的物件）如何取得「目前場景」並呼叫其表。

## 五、差異
| 項目 | 結論 |
| --- | --- |
| 上一份（4ADCD0／FE18A4＝表存取器） | 更正如第一節。 |
| 既有 T06/T07 對 Scene 類別 | 本表可補「哪些類別在建構時安裝了處理器表」；既有紀錄是否已有類別清單未核對。 |
