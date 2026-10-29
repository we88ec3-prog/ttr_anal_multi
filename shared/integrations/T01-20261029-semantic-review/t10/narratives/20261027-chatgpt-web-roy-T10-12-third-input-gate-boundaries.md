# KR T10-12 — 0x546D50 第三路裝置取向與 Z 連段證據邊界

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 範圍
從 `0x546780` 第三路 `0x546D50` 展開，判定此分支取值、門檻、輸出和狀態依賴，並與 T10-10/T10-11 整合。這是本次連續研究的第四段；原生 Z 連段完整閉環仍未找到，不因預定四段就虛構成功。

## 原始觀察
- 入口 `0x546D50`（未有正式函式符號），一次性檢查 `0xFB7C14`，需要時呼叫 `0x6D0750`。
- `[0xFB8830] != 0` 直接跳向返回 0；否則將 `[0xFB1318+0x10]` 與呼叫 `IAT 0xBD245C` 的結果比較，不一致也返回 0。IAT 的正式 API 身份本段未直接核對，不能稱為特定 window API。
- 在允許分支，呼叫 `0x6F3350` 將兩個整數座標填入局部變數，轉 float，平方相加，呼叫 `0x8FF870`（形式類似取得向量大小）與 `0xC55CAC` float 常數比較；門檻未跨越返回 0。
- 超過門檻才利用 `0xBD25F8`、`0x8FEDCA` 及 `0x4BB450` 換算兩個來源角度，將兩結果合成 byte 輸出，返回 1。函式在 `0x546EEC` 結束；其後 `0x546EF0` 是下一個函式入口，不能混入本函式。

### 原始 BIN：前置 gate
[code block separately checked in preflight]

### 原始 BIN：座標閾值與角度計算
[code block separately checked in preflight]
[code block separately checked in preflight]

### 原始 BIN：返回邊界
[code block separately checked in preflight]

## T10-9～T10-12 合併後的可驗證資料流
[code block separately checked in preflight]

## 嚴格區分
已確認＝清零位置、四向狀態取樣、部分 gate、位元組輸出及幾何處理。推測＝第二與第三路屬於指標／滑鼠輸入相關處理。未確認＝Z 對應行為碼、Z 按住連打的重複續段來源、不同普通攻擊段數、原生取消窗口、實際 `Table/KeyMapping.xml` 内容、伺服器權威規則。之前 `0x1F4` 即便為 500ms，也仍不可稱為 combo window。

## T10-13 後續追查
1. 優先由正常運作的鍵盤事件管理器定位 `0xFB9004` 基底的**間接寫入者**，確認 `FB9014` 實際值域。
2. 查同版本 `Table/KeyMapping.xml` 及 actor/action 入口，具備來源證據後映射 Z 行為。
3. 倒查攻擊 motion/animation 的「下一段完成回呼」、連按 pressed-edge 和 held 同時是否各自有條件分支。
4. 不跨越 T12 傷害公式，不將伺服器自製 `CHAIN_WINDOW=0.65` 冒稱原生。
5. 本批原始檔唯讀；按使用者明確授權，在 T10-12 完成後提交四份 T10 個人原稿；不改 AGENTS、task.json 或其他 Agent 目錄。