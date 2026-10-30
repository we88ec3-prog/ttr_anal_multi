# KR T10-13 — 間接索引輸入狀態寫入與讀取

原始來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，檔案大小 12,472,320 bytes。`.text` 依 PE 映射 VA `0x401000` ↔ raw `0x400`。唯讀截取，GNU objdump x86 Intel 模式；**不得執行客戶端**。以下若截取從區塊內部開始，首行解碼可能不是指令界線，應以原函式 CFG 校正。所有名稱都是暫定。日期：2026-10-27（Asia/Taipei）。

## 主要新證據
`0x6D4C20` 遍歷容器節點，取 `[edi+8]` 的鍵值 `esi`。對 `[0x2711,0x4E1F]` 的鍵值走 `[0xFDF630]` 樹內的 `node+0x10 = 0`；其他鍵值經 `0x6D0750` 初始化 gate，執行 `mov BYTE PTR [esi+0xFB9004],0`。**這是正常流程中的間接索引清零，不是 0xFB9014 非零事件寫入**。因 `esi` 未在該分支前做 `<=0x27` 檢查，不能把任意鍵值計算為 0xFB9004+index 並假設都在 40-byte buffer 內；此處需追呼叫者與樹內值域。
另一函式 `0x6D4CE0` 根據 `esi-0x2711 <=0x270E` 決定讀樹節點 `+0x10`，或僅在 `esi <=0x27` 時讀 `[esi+0xFB9004]`；超界返回 0。這比 T10-9 直接地址掃描證據更強，證實狀態讀取會透過索引間接定址。
## 暫定偽碼
[code block separately checked in preflight]
注意：清除路徑的 guard 與 getter 不同，不能據此聲稱 `0x6D4C20` 一定安全處理任意整數鍵值。
## 證據分級
已確認：indexed clear、indexed getter、extra-key tree 的 key range。未確認：正常事件將狀態設為 1/2/3 的 writer；Z 的 action index；普通攻擊 gate。

## 第一手原始組語摘錄
### 原始 BIN：0x6d4c20
[code block separately checked in preflight]

### 原始 BIN：0x6d4ce0
[code block separately checked in preflight]

## Git 與來源完整性
此檔為含原始反組譯摘錄的獨立原稿；實際是否推送成功以 GitHub 遠端回讀和 SHA 為準。