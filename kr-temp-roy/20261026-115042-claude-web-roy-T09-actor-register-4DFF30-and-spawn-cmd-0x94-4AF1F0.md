# KR T09（附 T06/T07 線索）— actor 登記 4DFF30（鍵＝word [actor+4]）與 S→C 命令索引 0x94 的「建立 actor」處理器 4AF1F0

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 11:50:42 +08:00`
- Scope: `Tartaros.bin` PE32 x86；`4DFF30..4DFFA2`（全）、`4AF1F0..4AF51B`（全；`4AF497..4AF4F0` 僅看結構）；`4DFF30` 的 5 個呼叫點（`4A11B6/4AA222/4AEC03/4AF4F7/4B2F83`）與其所屬函式／表 A 索引對照
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…cmd-0x1A-handler-4B28D0-remove-actor-4DFBC0.md` 的「下一步：找 0xFAB138 map 的插入點」
- Summary: (1) 插入點找到：**`4DFF30`**（`eax=actor`，`[ebp+8]=holder`）以 `word [actor+4]` 為鍵，若 `holder+8`（＝`0xFAB138` map）內沒有就插入 `{key, actor}`（`82F200`），已存在則記錄訊息。→ 前一份降為推測的「`[actor+4]`＝鍵」現已【確認】。(2) `4AF1F0`（表 A 索引 **0x94**，回傳 `0x100`）是批次建立 actor 的 S→C 處理器：每筆 0x18 bytes，含新 id、類型、int16 座標、朝向 byte 等，並在結尾呼叫 `4DFF30` 登記。

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認

## 一、4DFF30（actor 登記）（【確認】）
- `edi=actor`（`eax`）；`ebx=[ebp+8]＝holder`。`actor==0` → 記錄訊息（`push C0CED0; call 6EDC70`，函式未讀；可能為斷言）。
- `key=movzx word [actor+4]`；`esi=holder+8`；以 `82EF00` 查找；若迭代器 `== [holder+0xC]`（end，即 `0xFAB13C`）→ 不存在 → 組 pair `{key, actor}` 呼叫 `82F200`（以 `57EF20` 取得節點配置器後插入；`82F200` 為 map 插入，推測依其參數形式）。
- 已存在 → `push C0CEF0`（含 `key`）`call 6EDB60`（記錄訊息）；不覆蓋。
- 與 `4DFBC0`（移除）、`4B2730/4B28D0`（查找）所用 map 相同：`holder(0xFAB130)+8`＝`0xFAB138`，鍵＝word id，值＝actor 指標（`[node+0x10]`）。
- 5 個呼叫點：`4A11B6`（函式起點約 `4A0F70`）、`4AA222`（約 `4AA070`）、`4AEC03`（函式起點未能由前導碼判定；落在表 A 索引 0x07〔`4AE4D0`〕與下一個 `4AEDB0` 之間）、`4AF4F7`（`4AF1F0`，索引 **0x94**）、`4B2F83`（`4B2CD0`，索引 **0x21**）。其中 `4A11B6/4AA222` 的函式起點不在我已得的索引列表中（該列表只是部分）。→ 至少 `0x94`、`0x21`（以及可能 `0x07`）為「建立 actor」類處理器；**後兩者本次未讀**。

## 二、4AF1F0(data, len, cmd)（`ret 0xC`；回傳 `0x100`）（【確認】）
- 記錄數 `n=(len-2)/24`（`×0xAAAAAAAB >>4`＝除以 24）。`edi=data+4`；每筆 `edi+=0x18`（4AF4FC）。記錄起點 `R=edi-2=data+2+24k`。
- 每筆流程：
  1. `id=word [R+2]`（`[edi]`）在 `0xFAB138` 找；**已存在 → 略過此筆**（`cmp [eax],[0xFAB13C]; jne 4AF4FC`）。
  2. `flags=(word [R+6]) | 0x02000000`（`ebx`）。`new(0x138)`（`891268`）後以 `word [R+4]`（類型）呼叫 `4CBFF0(eax=記憶體, push type)` 取得 actor `esi`（失敗＝0；`4CBFF0` 函式本體**未讀**，推測為依類型建構物件的工廠）。
  3. 以 `word [R+0]` 在同一 map 找「來源 actor」；找不到或為 0 → 略過（仍會洩漏已配置物件？未驗，不下結論）。找到時：`[new+0x9C]=[src+0x9C]`、`[new+0x90]=[src+0x90]`（兩欄語意【未知】；`+0x90` 在 CBasicObject 建構中預設為 `0x7F`）。
  4. `[new+4]=word [R+2]`（id）→ 呼叫 `vtbl+0x3C(flags)`（語意【未知】）。
  5. byte `[R+0x13]`（`kind`，`[edi+0x11]`）：
     - `1`：`[new+0xF4]=1`、`[new+0xF8]=0`、`[new+0x128]=word [R+0x14]`；
     - `2`：`[new+0xF4]=1`、`[new+0xF8]=1`、`[new+0x128]=(float)word [R+0x14]`、`[new+0x12C]=(float)word [R+0x16]`。
     （`4CC8B0` 與 `4B28D0` 讀的正是 `+0xF4/+0xF8/+0x128/+0x12C/+0x130/+0x134`，兩處可互證；語意【未知】。）
  6. **位置**：`x=(float)sword [R+8]`、`y=(float)sword [R+0xA]`（`movsx`＋`cvtsi2ss`）→ `vtbl+0x44(&{x,y}, 1)`（設定位置；與 4CA890 的 steps==0 分支呼叫的是同一個 vtbl+0x44）。**座標在封包內是 16-bit 有號整數**。
  7. **朝向**：`vtbl+0x58(byte [R+0x10])`（`[edi+0xE]`；先前 546100 也呼叫 vtbl+0x58，傳 heading）。
  8. `vtbl+0x5C(float [R+0xC])`（`[edi+0xA]`；語意【未知】）。
  9. `[new+0x130]=(float)(word [R+0x11]) / double [C557D8]`（`[edi+0xF]` 未對齊 word；常數數值未讀，語意【未知】）。
  10. 以 `[0xFBA838]` 物件的 vtbl 呼叫（參數含 x、y 等；4AF459..4AF495；結果之後使用；`4AF497..` 未展開），然後 `4DFF30(eax=new, push 0xFAB130)` 登記（4AF4F0..4AF4F7）。
- 記錄佈局（相對 `R`，總長 0x18；皆為由存取方式推出，**欄位名稱不採用**）：
  | 偏移 | 型別 | 用途（存取） |
  | --- | --- | --- |
  | +0 | word | 來源 actor id（取 `+0x9C/+0x90`） |
  | +2 | word | 新 actor id（寫入 `[new+4]`、map 鍵） |
  | +4 | word | 類型（`4CBFF0` 參數） |
  | +6 | word | 旗標（`|0x02000000` 後傳 vtbl+0x3C） |
  | +8 | int16 | x |
  | +0xA | int16 | y |
  | +0xC | float | vtbl+0x5C 參數 |
  | +0x10 | byte | 朝向 |
  | +0x11 | word | ÷常數 → `[new+0x130]` |
  | +0x13 | byte | kind（1 或 2；其他值＝不設） |
  | +0x14 | word | p1 |
  | +0x16 | word | p2（kind=2 才使用） |

## 三、對 T09 的意義
- 新 actor 的**初始位置是 int16 格點整數座標轉 float**（【確認】轉換）；後續位置更新（0x18）用 float。這給出 S→C 位置資料的兩種精度：spawn（int16）與 0x18（float）。
- 朝向：spawn 以 byte 直接進入 vtbl+0x58（與 256 方向表的 byte 單位一致，見前文）。
- 由 `vtbl+0x44`（無碰撞檢查）設定初始位置；之後的移動才經 `4CABE0` 碰撞。

## 四、差異
| 項目 | 結論 |
| --- | --- |
| 前一份「`[actor+4]`＝鍵僅推測」 | 現為【確認】：`4DFF30` 以 `word [actor+4]` 插入 `FAB138`。 |
| 前文表 A 索引 0x94（`4AF1F0`） | 現知用途：建立 actor（含 actor id、類型、位置、朝向）。 |
| `5452C0` 的 C→S 0x0A 封包 | 其 id 欄＝`[actor+4]`，與本檔 `+2` 的新 actor id 對應同一種 id 空間（【確認】欄位來源；編號空間與伺服端對應【推測】）。 |

## 五、尚未確認
- `4CBFF0` 本體（類型→物件類別）；`4AEC03`、`4B2F83`（0x21）、`4A11B6`、`4AA222` 所在函式。
- 記錄 `+0x11`、`+0x14/+0x16` 與 `+0xF4..+0x134` 欄位的語意；`[0xFBA838]` 物件（4AF459）。
- spawn 失敗（來源 actor 找不到）時，新配置物件的處理（可能洩漏／可能 4CBFF0 內含釋放；未驗）。
- `data+0` 之後 `data+2` 處的 `R` 起點是否與其他處理器共用標頭；本處理器 `len-2` 的除法顯示標頭只有 2 bytes（命令 word）。

## 建議
- 值得提交：`kr-temp-roy/`；T06/T07（場景內物件生成）亦可參考。
- 下一步（T09）：讀 `4CBFF0`（類型→actor 類別）以及 `4B2CD0`（索引 0x21）的建立路徑；或回到 T09 的核心，確認英雄本機移動是否也有「伺服端校正」封包（找以 `[0xFBA7A4]` 控制器槽 actor 為目標的 S→C 處理器）。
