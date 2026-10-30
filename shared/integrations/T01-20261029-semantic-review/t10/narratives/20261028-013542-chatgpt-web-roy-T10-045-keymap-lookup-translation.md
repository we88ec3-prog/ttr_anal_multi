# T10-45 — 按鍵映射查詢展開、兩類鍵碼容器與後續事件轉換（BIN-first）

- 產出時間（Asia/Taipei）：2026-10-28T01:35:43.055855+08:00
- 一手來源：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 x86；唯讀靜態反組譯，沒有執行遊戲。
- 段號接續 T10-1～44；先前 `REBASE-01/02` 僅作審核附錄，**不是 T10-45/46**。
- GitHub：既有 T01-20261027-05 接受範圍僅部分確認。**本次未 Commit、Push、變更 owner、catalog 或其他任務資料。**
- 位址映射取本次 BIN PE header：`.text` RVA 0x1000、ImageBase 0x400000、raw pointer 0x400，故下列 `.text` VA 轉 raw = VA - `0x401000` + `0x400`；不應套用 flat raw 0。

## 本批核心判定

1. **`0x6D4DC0` 不是非零 phase writer**。從直接 x86 控制流看是以 `[ebp+8]` 鍵碼及 `[ebp+0xC]` 第二參數尋找映射集合，走兩類來源容器後逐項加入 ECX 指向的輸出 vector-like buffer（`[edi]` begin、`[edi+4]` end、`[edi+8]` capacity）。回傳 `ret`，不含把 `FB9004` phase 寫成非零的直接證據。
2. 特殊鍵碼範圍使用 `(unsigned)(key-0x2711) <= 0x270E`，每個第二參數以 `shl eax,4` 定位 `0xFDF3F4 + 16 * arg2` 的容器，透過 `0x6D43F0` 查鍵碼樹，取其 +0x10 動態 DWORD 指標集合，再逐筆追加。另一支以 `0xFB8834 + 16*(key + 40*arg2)` 指向 vector-like 集合。**這是映射結果集合，尚未證明 key 是 Virtual-Key、XML action row 或 combo command。**
3. `0x6D4DC0` 在本 BIN 找到 29 處直接 E8 call 相對指令編碼候選（僅位元組比對，不等於皆可達執行），集中 `0x594610` 周邊，另有多處。首批檢查確認 `0x594610` 給第二參數 2，先以 EDI 原值查詢，再在 `edi==0x18` 時查 `0x0D`、`0x0E`；`edi==0x19` 時查 `0x0E`、`0x0F`。返回的集合元素透過 `0x594A80` 或 `0x594570` 轉成後續輸入／顯示資料。**此為具體下游消費路徑，不是 Z/X/C/V 實體綁定已證。**
4. `0x594A80` 針對輸入 DWORD 取 bits 16..23 與 bits 0..7；前者非零時 `0x4026E0`，後者非零時 `0x4041F0`；如兩者全零則 `0x402160` 設定 fallback。目的指標使用 `(byte*7)*4 + 4` 偏移，說明至少有兩個子欄位格式，**尚不應將其中一個稱為按下／放開事件**。
5. `0x546263` 是 `0x546780` 的直接 caller，且先檢查 actor 來源及 `0x4C9ED0` gate，後續把 WORD 輸出與 `[ebx+2]` 比較、合併。因此 500ms 狀態機不是獨立運作，亦沒有充足證據把它定義為原版連段時間。

## 交叉參照（本 BIN 原始 E8 rel32 bytes 搜尋）

完整 `call 0x6D4DC0` 候選 VA：0x594672, 0x5946cb, 0x59471b, 0x5947fd, 0x59484d, 0x59492f, 0x59497f, 0x594cd4, 0x594dc4, 0x594eb4, 0x594fa4, 0x595094, 0x595184, 0x595274, 0x595364, 0x595454, 0x595544, 0x595634, 0x595724, 0x595814, 0x595901, 0x5959f4, 0x5cd68a, 0x5ce5ba, 0x62b5ba, 0x650e96, 0x650f48, 0x650ff6, 0x6510a4。

注意：此搜尋僅對 E8 + signed rel32 計算目標，未掃描 indirect call、tailjmp，也可能在資料或反組譯邊界中誤判；`0x594672` 等已用 objdump 交叉核對。

## 重要證據窗口：原始 PE 指令解碼


### 0x006D4DC0–0x006D4E5F（raw 0x2D41C0）

[code block separately checked in preflight]


### 0x006D4E8F–0x006D4F00（raw 0x2D428F）

[code block separately checked in preflight]


### 0x006D4F70–0x006D500C（raw 0x2D4370）

[code block separately checked in preflight]


### 0x00594647–0x00594727（raw 0x193A47）

[code block separately checked in preflight]


### 0x00594A80–0x00594B09（raw 0x193E80）

[code block separately checked in preflight]


### 0x00546230–0x005462A4（raw 0x145630）

[code block separately checked in preflight]


## 保守偽碼（僅對已讀路徑）

[code block separately checked in preflight]

這個偽碼只示意已觀察到的資料流，不宣稱超界防護、參數範圍或 `lookup_or_create` 的完整安全語義。`0x6D43F0` 會在找不到鍵時配置節點，從機器碼看不能單純寫成純唯讀 lookup。

## 證據分級與新缺口

| 判定 | 級別 | 依據／限制 |
|---|---|---|
| 6D4DC0 按兩參數選 bank，迴圈將 DWORD 追加到輸出 | 局部 BIN 已確認 | 6D4E02、6D4E49、6D4EE6、6D4F30～4FE9 |
| 6D4DC0 是非零 phase writer | 與當前直接證據不符 | 目前發現的是映射結果寫入 output vector；**不能**據此否定另有 phase writer |
| 594610 消費多個查詢結果，指定查 0D/0E/0F | 局部 BIN 已確認 | 5946BB～59471B、5947ED～59484D |
| 594A80 把編碼 DWORD 分解送往兩類輸出函式 | 局部 BIN 已確認 | 594A87～594AFF |
| 0D/0E/0F 或 EDI=18/19 等於 Z/X/C/V | 尚待驗證 | 尚缺 XML action row、設定讀取及使用者重綁實例連線 |
| 546780 與 546263 是 direct caller/callee | BIN 已確認 | E8 rel32 在 546263；後續 actor gate 沒有還原完整 |
| 非零鍵 phase writer、V 蓄氣、普通攻擊 next-action/cancel | 缺口 | 此段沒觸及可靠 writer 或動作 queue 證據 |

## 下一大型研究主題（不限一兩個函式）

1. 從 `0x594610` 的 caller 向上追，查明 `edi` 是否真正是可重綁 action 及其 XML 載入路徑；確認 `0x0D`、`0x0E`、`0x0F` 是修飾鍵還是 action indices。
2. 定位 `0x6D4DC0` 所用 `0xFB8834` 與 `0xFDF3F4` 容器的非初始化 writer；不把 container writer 與 phase writer 混同。
3. 依 `0x6D4CE0` 的調用者與非零 `0xFB9004` writes 追真正鍵盤事件來源；找 KeyMapping.xml/default row 證據。
4. 沿 `0x546263`、`0x546780` 輸出流追 actor 動作啟動及 queue/cancel；與 T11 技能裁決僅做明確 interface 引用。

## GitHub 證據使用界線

本次一手原始 BIN 已核對；`T01-20261027-05` 與 REBASE 原稿只能作索引，沒有逐份完成 T10-1～44 的最新 GitHub SHA reconciliation，不宣稱舊 44 段全部驗收。原版 0.65 秒是 AI 替代，500ms state gate 也不等於原版 Z 連段窗口。