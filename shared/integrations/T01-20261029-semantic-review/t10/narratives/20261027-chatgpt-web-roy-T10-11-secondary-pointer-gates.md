# KR T10-11 — 0x546B50 裝置狀態、邊沿旗標與方向產生

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 問題
`0x546B50` 是 `0x546780` 即時合流的第二路。確認其狀態來源、邊沿記錄、阻擋條件及返回值，避免將所有 output mask 都誤歸於 Z 長按。

## 新證據
- `[0xFBA80C]` 為懶初始化全域指標；為空時配置 `0x57C` bytes 並呼叫 `0x6F1370`。
- 讀取 `[0xFB1318]`，在 `+0xC01C` 測 bit 0 與 bit 1，控制是否可以繼續某個裝置輸入分支。
- `[edi+0x7C]` 與 `[edi+0x80]` 被反覆清零、比較及變更；`0x546C03..0x546C24` 利用全域 `0xFE1E20` 做一次性邊沿門檻及狀態翻轉。不能直接命名為 Z keypress。
- `0x546BC3` 檢查 caller 第三參數，不為 0 時清 `+7C/+80` 並返回 0；這是可確認的 gate。
- `0x546C79..0x546D39` 經 vtable `+0x4C`、`0x434740`、`0x79A6B0`，以座標差和三角函式 `0x8FEDCA`、`0x4BB450` 產生輸出 byte，顯示存在畫面／指標座標式方向候選路徑。確切 UI 裝置和座標空間待確認。

### 原始 BIN 節錄：一次性狀態與 gate
[code block separately checked in preflight]
[code block separately checked in preflight]

### 原始 BIN 節錄：指標座標角度
[code block separately checked in preflight]
[code block separately checked in preflight]

## 結論與否定
**已確認**：多個全域/控制器 gate，及使用位置資料產生 byte 方向的處理。
**合理推測**：這可能是指標／滑鼠取向分支，但原始符號、IAT 與來源還需驗證。
**未證實**：此 branch 是 Z 連按的 edge consumer、`[edi+0x80]` 是普攻 combo index、global `0xFE1E20` 是按鍵 debounce。

[code block separately checked in preflight]

下一段 T10-12 研究第三路 `0x546D50` 的差異，完成這批非 Z 分支的證據邊界及待追查優先序。