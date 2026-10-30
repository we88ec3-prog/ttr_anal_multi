# KR T10-10 — 0x546850 四個輸入位元組與方向／角度合成

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 範圍
T10-7 確認 `0x546780` 會呼叫 `0x546850`，但這一分支是否屬於普攻需要查看它自己的輸入與輸出。完整檢查 `0x546850..0x546B45` 的方向狀態運算，定位 `0xFB9005..0xFB9008` 及其角度 byte 的意義邊界。

## 關鍵原生證據
`0x5468AA,0x5468E5` 取 `FB9005` 並與 1 或 2 比較，符合時 `sub [ebp-0x18],1`；`FB9006` 相同模式，符合時 `add [ebp-0x18],1`；`FB9007` 對 EDI 做 `sub 1`；`FB9008` 對 EDI 做 `add 1`。輸入值 1、2 在此**具有相同的啟動效果**，但二者在其他消費者可仍有不同語義。

方向分支在 `0x546A54..0x546A91` 將軸向符號轉換成離散 byte `0x00/0x20/0x40/0x60/0x80/0xA0/0xC0/0xE0`，再以 `0xFB8824 * ([0xFB76E8]+0x20)` 的 float 調整量（經 x87 float-to-int）加到輸出 byte。兩軸都為 0 時返回 0；否則寫出 angle byte 並返回 1。未確認輸出單位、浮點欄位正式命名。

### 原始 BIN：四向來源
[code block separately checked in preflight]
[code block separately checked in preflight]
[code block separately checked in preflight]
[code block separately checked in preflight]

### 原始 BIN：離散角度與輸出
[code block separately checked in preflight]
[code block separately checked in preflight]

## 結論
這條分支讀四個連續的輸入狀態 byte，合成類似二維方向資料及 byte 角度。在輸出合流 `0x546780` 中它對某個 byte 輸出具有優先權；**但沒有看到可把四個 byte 命名為 Z、普攻段數或取消窗口的依據**。

暫定偽碼：
[code block separately checked in preflight]
`enabled` 在此只指 ==1 或 ==2；浮點調整的正式語義未確定。下一段 T10-11 轉向 `0x546B50` 中的另一裝置狀態與按下邊沿條件。