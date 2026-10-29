# KR T10-20 — 三條輸入資料流與 Z 續段的證據邊界

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

A：未知非零 writer -> FB9004+index 或擴展鍵樹 -> 6D4CE0 -> 5961C0 按 phase 1/3 dispatch，596140 可攔截。B：FB9014 -> 547240 (500ms timeGetTime gate) -> 546780 mask -> 546100 controller -> 5452C0 封包 000A，但未直接與 Z 對應。C：FB9015..18 -> 50C640 命令 0x22；FB9004+[28..37] -> 548918 命令 0x68；另一 controller branch 命令 0x07。三者不能混成單一 Z combo；尚未證明 held auto-chain、rapid-press chain、animation completion callback 和取消時間。未取得 Table/KeyMapping.xml 本體，不能確認 Z 的配置。

## 原始反組譯節錄（擴充留存；按 CFG 辨識指令界線）

### 片段起點 0x596140

[code block separately checked in preflight]

### 片段起點 0x5488E0

[code block separately checked in preflight]

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。