# KR T09 — S→C 命令索引 0x18：處理器 4B2730 設定遠端 actor 的「目標位置＋步數」，由 4CA890 逐幀逼近（經 4CABE0 碰撞）

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 11:05:19 +08:00`
- Scope: `Tartaros.bin` PE32 x86；`4B2730..4B28C0`（全）、`4CA8C8..4CAA5B`（4CA890 中段）、`4C8000..4CE000` 內對 actor `+0xC0..+0xEC` 的存取掃描
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…recv-dispatch-chain-804740-4930E0-4C4670.md` 的「下一步：讀 4B2730」
- Summary: 命令索引 0x18 的處理器 `4B2730` 把封包解成若干 12-byte 記錄，每筆以 word id 在 `0xFAB138` 的 map 找 actor，寫入目標座標（兩個 float）、步數（word）並設 `[actor+0xD4]=1`；`4CA890` 每幀依此以「剩餘距離／剩餘步數」為步長朝目標前進（每步經 `4CABE0` 碰撞），步數歸 0 時直接設到目標並清 `actor+0xE2` 的 `0x8000`。這是「伺服端位置 → 本機 actor 移動」的接收側，也把前面 546100 輸出記錄中的 id 欄位（`[actor+4]`）對上了。

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認

## 一、對前一份的小更正（【確認】）
- 前一份把分派呼叫的參數寫成「(a, data, cmd)」；實為 **(data, len, cmd)**：`4930E0` 呼叫 Scene vtbl+4 時依序 push `cmd, len, data`（`493 12C..135`），`4C4670`／`4FDA30` 再原樣轉給處理器（stdcall `ret 0xC`：arg1＝資料指標，arg2＝長度，arg3＝命令索引）。`4B2730` 以 `[ebp+8]` 為資料指標、`[ebp+0xC]` 為長度即為證據；`4B24F0` 讀 `[packet+2]` 亦吻合。其餘結論不受影響。

## 二、4B2730(data, len, cmd)（`ret 0xC`；回傳 0）（【確認】）
- 記錄數 `n = (len-2) / 12`（`len<2 → 0`；以 `×0xAAAAAAAB >>3` 做除以 12，4B275F..4B2775）；`n==0` → 結束。
- 記錄起點：`esi = data+4`（`add esi,4`）；每筆 `esi += 12`。以資料起點 `data+0`＝命令 word、記錄自 `data+2` 起，單筆佈局：
  | 偏移（相對記錄起點 data+2+12k） | 型別 | 用途（依下方存取） |
  | --- | --- | --- |
  | +0 | word | **id**（`movzx [esi-2]`） |
  | +2 | dword | **A**＝目標 x（`[esi]`；以 float 使用，見四節） |
  | +6 | dword | **B**＝目標 y（`[esi+4]`） |
  | +10 | word | **C**＝步數（`movzx [esi+8]`） |
  （2+4+4+2＝12 ✓；欄位為未對齊緊密排列。）
- 每筆（4B27B9..4B289F）：
  1. 以 `id` 在 **`0xFAB138`** 的 map 查找（`82EF00`；結果迭代器與 end 節點 `[0xFAB13C]` 比較）；找不到 → 跳過。命中時 `actor = [node+0x10]`；`actor==0` → 跳過。（5452C0 寫入封包的 id 欄為 `word [actor+4]`，兩者對應：`[actor+4]`＝此 map 的鍵；前者為 C→S，此為 S→C。）
  2. `[actor+0xD8]=0.0f`、`[actor+0xDC]=0.0f`（以 `xorps` 取 0 再存）。
  3. `[actor+0xC0]=A`、`[actor+0xC4]=B`、`[actor+0xC8]=C(零擴展為 dword)`、`[actor+0xD4]=1`、`[actor+0xE8]=A`、`[actor+0xEC]=B`。
  4. 若 `[actor+0x3A8]==0`（首個 `cmp` 的旗標沿用至 4B2855 的 `jne`）且 `[actor+0x370]≠0`：`[actor+0x3A4]=byte [actor+0xB0]`（備份朝向），並當 `[actor+0x15C]` 子物件存在時呼叫其 `[obj+4]` 的 vtbl+0xC，參數＝`float 表[0xFB7C20 + 朝向*4]`（角度；4449D0 的角度表）。**朝向本身沒有被封包改寫**（`[actor+0xB0]` 未被寫）。呼叫該虛擬函式的語意【未知】（推測為依現有朝向重設模型旋轉）。

## 三、消費者 4CA890（中段 4CA8D6..4CAA5B）（【確認】流程；常數語意【未知】）
- `4CA890` 為前幾份記錄過的 actor 每幀移動函式；本段是 `[actor+0xD4]==1` 的分支（4CA8D6 `cmp ... ,1`、`jne 4CAA5C`）。`esp+0xC = 1.0 / [某全域+0x1360]`（整數轉 float 的倒數；全域物件及欄位意義【未知】）。
- `dx = [actor+0xC0] - [actor+0xA0]`、`dy = [actor+0xC4] - [actor+0xA4]`（`fsub` 與 `+0xA0/+0xA4`＝位置）。`steps = [actor+0xC8]`。
- **`steps ≠ 0`**（4CA9DE..4CAA5B）：`dist = sqrt(dx²+dy²)`（`8FF870`）、`step = dist / steps`；`D3DXVec2Normalize(&v,&v)`（`[BD25F8]`）；位移向量 `= v * step`；呼叫 actor **vtbl+0x54（4CABE0＝含碰撞檢查的位移）**；`[actor+0xC8]--`；回傳。
- **`steps == 0`**（4CA922..4CA9DD）：呼叫 actor **vtbl+0x44**（`push 1; push &[actor+0xC0]`；基底類別為 `4C8B90` 或 `4CAB80`，見 T09 先前紀錄）把位置設到目標；`[+0xE8/+0xEC] = 目標`；再算 `(目標 − 位置)`，若其平方和 `> [0xC55A64]`（常數；語意【未知】）則 `[actor+0xD8/+0xDC] =` 該殘差；`[actor+0xE2] &= 0x7FFF`（清移動位）；`[actor+0xD4]=0`；回傳。
- 因此逐幀位移為「直線、等分、步長＝剩餘距離／剩餘步數」；每步仍經 `4CABE0`（碰撞全有或全無，見前文）。若某步被擋，位移被丟棄但 `steps` 仍遞減（`4CAA4D` 在 `call edx` 之後無條件 dec；【確認】程式順序），最終 steps 歸 0 時以 vtbl+0x44 直接設到目標。**碰撞擋住時靠最後的「直接設到目標」收斂**（【確認】控制流程；是否有意為之【未知】）。

## 四、型別佐證（【確認】）
- `fld dword [esi+0xC0]`、`fsub dword [esi+0xA0]`：位置與目標皆以 32-bit float 運算；`4B2730` 只把 A、B 以 dword 原樣複製，故 **封包內 A、B 為 IEEE-754 float**（由使用方式推出；封包本身未見）。步數 C 為 16-bit 整數（`fild` 於 4CAA07 以 dword 讀入）。

## 五、與既有紀錄的關係
| 項目 | 結論 |
| --- | --- |
| `4409808e…` 對 4CA890/4B2730 的描述 | 本檔補上 4B2730 的欄位解析與寫入欄位；4CA890 的 `+0xD4` 分支語意可與該紀錄對照（未逐一核對其說法）。 |
| `ee36565a…`「怪物移動執行獨立於英雄輸入」 | 一致：遠端 actor 的移動來自 S→C 0x18，不經 546100。 |
| 前一份「兩個方向的 0x0A」 | 不變：本檔只談 S→C 0x18。 |

## 六、尚未確認
- `[actor+0xD8/+0xDC]` 殘差向量的後續用途（4C8A93..4C8AFF 與 4CAD66..4CADEE 有讀寫；未展開）。
- `[actor+0x3A8]`、`[actor+0x370]`、`[actor+0x15C]` 子物件的語意。
- 封包是否一定針對「別人」的 actor，或也含本機英雄（回報校正）；`id` 與英雄 id 的關係。
- `1/[全域+0x1360]` 與 `[0xC55A64]` 的語意；`[actor+0xE8/+0xEC]`（目標副本）的後續使用。
- 伺服端何時送 0x18（觸發條件）、一包的最大筆數（受 `len` 限制）。

## 建議
- 值得提交：`kr-temp-roy/`。T09「位置校正來源」缺口：S→C 0x18 是已確認的一個來源。
- 下一步（T09）：讀 `4B28D0`（idx 0x1A）與 `4AF920`（idx 0x0A）／`4AFE60`（idx 0x0B）中與 actor 位置／朝向有關的處理器，或回頭追 `[actor+0xD8/+0xDC]` 的消費（4C8A93..4C8AFF）。
