# KR T10-15 — 狀態位元組的另一組消費者及命令派發

原始來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，檔案大小 12,472,320 bytes。`.text` 依 PE 映射 VA `0x401000` ↔ raw `0x400`。唯讀截取，GNU objdump x86 Intel 模式；**不得執行客戶端**。以下若截取從區塊內部開始，首行解碼可能不是指令界線，應以原函式 CFG 校正。所有名稱都是暫定。日期：2026-10-27（Asia/Taipei）。

## 主要新增結果
`0x54883A～0x548883` 檢查 `[0xFB9015]`、`[0xFB9016]`、`[0xFB9017]`、`[0xFB9018]` 是否為 `1`，各自推送 `1～4` 呼叫 `0x50C640`。這與 `0x6D4CE0` 的一般狀態 getter 不同，是另一個專用消費者。`0x548891` 另外檢查 `0xFB901B`，在 actor 狀態許可時寫局部 byte `0x80`。
`0x50C640` 按輸入參數計算 `ecx + index*0x10` 的 slot，檢查 `slot+0x0C`、`slot+4` gate、樹查找和可選狀態守衛。成功時建構三個欄位 `WORD 0x22` / `BYTE index` / `DWORD slot+8`，並交 `0x50CAC0`。該命令暫定為一種**額外操作請求**，不是已證實的普攻。
`0x50CAC0` 若 `[0xFBA798]==0`，讀 `[0xFBA854]` 的 virtual `+0x10`，傳三參數 `0, packetAddr, 7`；否則直接回傳 1。這是已確認的封包送出交接邊界，未核實命令 `0x22` 的服務端語義。
## 重要界線
不能把 `0xFB9015～18` 的四個 `state==1` 當成連擊四段：它們是四個**不同位址**各觸發參數 1～4，並非單一 Z 連段 counter。需要由各位址 key mapping 與封包 response 查證用途。

## 第一手原始組語摘錄
### 原始 BIN：0x54883a
[code block separately checked in preflight]

### 原始 BIN：0x50c640
[code block separately checked in preflight]

### 原始 BIN：0x50cac0
[code block separately checked in preflight]

## Git 與來源完整性
此檔為含原始反組譯摘錄的獨立原稿；實際是否推送成功以 GitHub 遠端回讀和 SHA 為準。