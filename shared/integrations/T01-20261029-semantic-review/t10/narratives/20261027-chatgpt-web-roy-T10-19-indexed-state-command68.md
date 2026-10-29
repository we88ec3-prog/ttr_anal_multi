# KR T10-19 — 548918 索引 28～37 的命令送出

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

548918 先設 ebx=0, esi=0x1C。548952 cmp esi,0x27 為個別上界測試，但迴圈 5489B0 cmp esi,0x26 / 5489B3 jl 548920 實際走索引 28..37，共十個，不是 28..39。當 [FB9004+esi]==1 且 FBA798 gate 允許時，組裝 WORD=0x68、BYTE=ebx+1，透過 FBA854/vtable+0x10 傳送；另一 branch 從 controller 輸入 byte 送出 WORD=0x07 的命令。沒有證據這些是十段普攻或 Z 對應的 action。

## 原始反組譯節錄（擴充留存；按 CFG 辨識指令界線）

### 片段起點 0x5488E0

[code block separately checked in preflight]

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。