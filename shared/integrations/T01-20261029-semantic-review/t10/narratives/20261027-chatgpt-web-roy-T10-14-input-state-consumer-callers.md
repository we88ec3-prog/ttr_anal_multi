# KR T10-14 — 即時狀態 getter 的呼叫者與事件階段分派

原始來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，檔案大小 12,472,320 bytes。`.text` 依 PE 映射 VA `0x401000` ↔ raw `0x400`。唯讀截取，GNU objdump x86 Intel 模式；**不得執行客戶端**。以下若截取從區塊內部開始，首行解碼可能不是指令界線，應以原函式 CFG 校正。所有名稱都是暫定。日期：2026-10-27（Asia/Taipei）。

## 函式交叉參照
在 `.text` `CALL rel32` 掃描的**候選**交叉參照中，`0x6D4CE0` 有兩個直接 `CALL`：`0x59624E` 與 `0x59643F`。這是定向 call-site 掃描，不包含虛呼叫、間接指標與 jump tail。
`0x59624E` 後先比較 `eax == 1`，再比較 `eax == 3`，依分支使用虛函式 slot `+0xEC/+0xF0`，並呼叫 `0x596140` 或查找物件自身 `+0x80` 樹資料。`0x59643F` 後也比較 `eax==1`，使用相似 `+0xEC` 虛函式。這是強烈的 state-phase 分流證據，但**不能將 1/3 直接命名 pressed/released，更不能確認 Z**。
## 偽碼控制框架
[code block separately checked in preflight]
## 限制
對象類別、虛函式實際動作名稱、是否為普攻、是否為重複按壓，以及由誰將其設為 1/3，均未確認。需要由 `0x5961C0`、`0x5963xx` 的 caller 追到輸入 polling 主循環及相應轉態 writer。

## 第一手原始組語摘錄
### 原始 BIN：0x59623b
[code block separately checked in preflight]

### 原始 BIN：0x59643d
[code block separately checked in preflight]

## Git 與來源完整性
此檔為含原始反組譯摘錄的獨立原稿；實際是否推送成功以 GitHub 遠端回讀和 SHA 為準。