# KR T10-16 — 現有輸入鏈整合、候選排除與普攻續段缺口

原始來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，檔案大小 12,472,320 bytes。`.text` 依 PE 映射 VA `0x401000` ↔ raw `0x400`。唯讀截取，GNU objdump x86 Intel 模式；**不得執行客戶端**。以下若截取從區塊內部開始，首行解碼可能不是指令界線，應以原函式 CFG 校正。所有名稱都是暫定。日期：2026-10-27（Asia/Taipei）。

## 本批新整合結論
已能將主要路徑分為：
1. `0x6D4C20` / `0x6D4CE0`：以實際鍵值分類分別訪問 `0xFDF630` 的擴展鍵樹或 `0xFB9004+index`，涉及狀態清零與查詢。
2. `0x59624E` / `0x59643F`：依 getter 的狀態 `1/3` 進入不同虛函式與容器分支。
3. `0x54883A`～`0x548883`：專用多位址狀態測試，透過 `0x50C640` 建構命令 `0x22`，`0x50CAC0` 交給 virtual sender。
4. 舊段 `0x547240→0x546780→0x546100`：輸入相位轉 mask，屬另一套消費鏈，尚不能與上述 1～3 全部畫成一條 Z 連擊功能鏈。
## 排除與反例
四個位址 `0xFB9015～18` 不是確定的「連擊四段」；`0x22` packet 也不是確定的普攻。前段的 500ms 僅是 timeGetTime 狀態門檻，絕不能改成原版 combo window。`0x6D4CE0` 的狀態 1/3 也沒有可靠標籤可以斷言 keydown/keyup。
## 下一段 T10-17 的精確工作
(1) `0x5961C0`/`0x5963xx` caller 與 input polling tick；(2) 對 `0xFB9004` 的 indexed **非零** writer 進行 instruction-level xrefs；(3) 獲取實際 `Table/KeyMapping.xml` 檢查 Z 對應的 key/action；(4) 針對普通攻擊 motion state 追 next-action consumer 與動畫結束 callback；(5) 若封包證據必要，與 T02 交叉引用，不篡改共享 catalog。上述缺口未閉合前，不編造 combo 段數／cancel 時間。

## 第一手原始組語摘錄
### 原始 BIN：0x6d4d70
[code block separately checked in preflight]

### 原始 BIN：0x54883a
[code block separately checked in preflight]

### 原始 BIN：0x50c640
[code block separately checked in preflight]

### 原始 BIN：0x50cac0
[code block separately checked in preflight]

## Git 與來源完整性
此檔為含原始反組譯摘錄的獨立原稿；實際是否推送成功以 GitHub 遠端回讀和 SHA 為準。