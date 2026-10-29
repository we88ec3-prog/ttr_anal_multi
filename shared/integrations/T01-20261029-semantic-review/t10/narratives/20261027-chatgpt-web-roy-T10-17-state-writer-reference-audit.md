# KR T10-17 — 精確地址 xref 核對與缺失的非零 writer

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

已核對 FB9004 精確地址字面值的七處出現位置：54895A、6D0876、6D1B03、6D4A9D、6D4B6C、6D4CB0、6D4D9B；FB9014 五處：547293、6D088A、6D1B17、6D4AB1、6D4B80。這些是位址字面值而非指令起點。6D4A9C/6D4B6B 是直接批次清零，6D4CAE 是 [esi+FB9004] 的間接索引清零。6D4D98 和 548957 是 indexed read。尚未找到一般事件將非零相位寫進陣列的 writer。搜尋絕對位址不足以排除 base+index、指標別名及其他 DLL。

## 原始反組譯節錄（擴充留存；按 CFG 辨識指令界線）

### 片段起點 0x6D4A40

[code block separately checked in preflight]

### 片段起點 0x6D4B20

[code block separately checked in preflight]

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。