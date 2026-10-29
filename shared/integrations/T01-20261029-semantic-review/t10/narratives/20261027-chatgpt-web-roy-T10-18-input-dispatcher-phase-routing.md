# KR T10-18 — 5961C0 正常鍵與擴展鍵的事件分派

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

596140..5961B9 為獨立攔截 helper，5961C0 為下一函式 prologue。5961C0 遍歷一般鍵索引 0..39，透過 6D4CE0 取 phase；phase 1 走 vtable+EC，phase 3 走 vtable+F0，其間結合由 761010 返回物件的旗標、FB73E8 gate，以及 596140 的 keyed-tree 攔截結果。0xD/0xE 存在特殊條件。596390 後另遍歷 0xFDF624 管理的擴展鍵資料，不是普通鍵的純連續追加。未確認 phase 1/3 是 keydown/keyup，也未確認 5961C0 的間接/vtable 主呼叫者。

## 原始反組譯節錄（擴充留存；按 CFG 辨識指令界線）

### 片段起點 0x596140

[code block separately checked in preflight]

### 片段起點 0x596330

[code block separately checked in preflight]

### 片段起點 0x5964C0

[code block separately checked in preflight]

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。