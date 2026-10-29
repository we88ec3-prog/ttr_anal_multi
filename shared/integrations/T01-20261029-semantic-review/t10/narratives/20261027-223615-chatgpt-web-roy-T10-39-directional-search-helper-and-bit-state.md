# T10-39 — 方向探索 helper、256 候選迭代與狀態位的誤判排除（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 深度分析
1. 【確認】`0x545F30` 先檢查全域 `0xFAB1D0`；空指標直接往 `0x5460E4` 返回分支。這是 helper 的資源前提，非技能可用性矩陣。
2. 【確認】`0x545FF3` 取得 byte 參數 `edi`，以 `edi*8` 索引 `0xFB8020`、`0xFB8024` 的兩個 float，再與第二參數浮點運算，組成二維座標；`0x546050` 對全域資料 `0xFAB1D0` 呼叫 `0x82CDF0`。即此 helper 實際處理方向樣本和空間位置比較，而不是單純鍵值判斷。
3. 【確認】`0x5464C0` 首先將輸入的 byte 寫出到指標 `[ebp+0x14]`，再依 `[ebp+0x8]` 是否非零在 `0x5464D7` 分支。這個 BYTE 也是方向候選值，不能因其為輸入索引就當 skill matrix key。
4. 【確認】`0x546595` 呼叫 `0x545F30`；返回非零時轉入不同修正路徑。另一條 `0x546700` 起使用 `ebx` 作循環計數，每輪查一次 `0x545F30`，直到結果為零或 `ebx==0x100`。最大 256 是方向/量化索引搜尋上限，**不是 V 蓄氣時間、連段數或按鍵重試次數**。
5. 【確認】`0x54672C` 路徑將 BYTE `bl` 減 `0x80` 並試查一次方向，返回含成功/失敗狀態。因此 `0x5464C0` 有多種方向解析策略，不能將它等同一般連招選擇。
6. 【確認】`0x4C90C0` 僅在傳入參數非零且 actor `+0x3A8` 先前為零時設定 `+0x3A8`；參數為零時清除。若 actor `+0x370`、`+0x15C` 非零，還會走從屬虛擬回呼；此函式管理的是另一個明確旗標，不是 `+0x3E8` setter。
## 偽碼（只表示已確認的條件，不補猜角度規則）
[code block separately checked in preflight]
## 重要限制
- 現在有更強反證：`0x5464C0` 以及 `0x545F30` 方向取樣循環 **不宜作為普攻→技能 cancel 或 V charge level 證據**。這是從局部機器碼而非功能名稱得出的否定性成果。
- 需另外定位真正矩陣 4-tier writer、鍵映射非零 writer 與動作動畫 callback。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x545f88–0x54607f
[code block separately checked in preflight]

### VA 0x5464c0–0x5465a0
[code block separately checked in preflight]

### VA 0x5466f8–0x546774
[code block separately checked in preflight]

### VA 0x4c90c0–0x4c913a
[code block separately checked in preflight]