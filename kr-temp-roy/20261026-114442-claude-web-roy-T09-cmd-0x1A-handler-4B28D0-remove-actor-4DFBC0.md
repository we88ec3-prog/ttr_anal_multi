# KR T09 — S→C 命令索引 0x1A：4B28D0 依 id 清單「移除 actor」（經 holder 方法 4DFBC0 刪除物件並自 0xFAB138 map 抹除）

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 11:44:42 +08:00`
- Scope: `Tartaros.bin` PE32 x86；`4B28D0..4B2AEA`（全）、`4DFBC0..4DFC29`（全）、`4DFC30..4DFC8A`（姊妹函式，僅控制流程）、`4CC8B0..4CC96D`（開頭）、`4C7060..4C70F6`/`4CA730..4CA7CA`（CActor/CBasicObject 建構開頭）、`0xFAB138` 查找點掃描
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…cmd-0x18-handler-4B2730-target-move.md` 的下一步
- Summary: 命令索引 0x1A 的處理器 `4B28D0` 讀取一串 word id（`n=(len-4)/2`，自 `data+4` 起），對每個 id 在 `0xFAB138` map 取得 actor，做一些清理後呼叫 `0xFAB130` 持有者的 `4DFBC0(id)`：通知控制器、呼叫 actor vtbl+0x14、以 vtbl+0（`push 1`＝刪除）銷毀 actor、把 map 節點值歸零並抹除。所以 0x1A 是「依 id 移除 actor」（控制流程確認；遊戲上稱為「消失」屬【推測】）。

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認

## 一、4B28D0(data, len, cmd)（`ret 0xC`；回傳 0）（【確認】）
- `n = (len-4)/2`（`len<4 → 0`；`add eax,-4; shr eax,1`；4B28FC..4B290D）；`n==0` → 結束。
- 迴圈起點 `ecx=data+4`（`add ecx,4`），每筆 2 bytes（`add [esp+0x14],2`，4B2AC7）。故封包：`data+0` word＝命令 0x1A、`data+2` word＝**未被本函式讀取**（語意【未知】）、`data+4..` 為 word id 陣列。
- 每個 id（`movzx eax, word [ptr]`）：
  1. 以 `0xFAB138` map 查找（`82EF00`）；找不到或值為 0 → `push C06CE0; call 6EDB60`（記錄訊息；字串內容未讀）並略過此 id（4B2989..4B2996）。
  2. `esi=actor`。以 `low byte of word [actor+4]`：
     - 若為 `1`、`6`、`0`、`7` 之一：`xmm0=1.0f（[C456C0]）`填四個 float 欄（`[esp+0x24..0x30]`）；若 `[actor+0x15C]` 與 `[actor+0x370]` 皆非 0：呼叫 `7A7CC0(sub,0)` 再以 16-byte 參數呼叫 `7A7BF0`（以 `1.0f ×4` 為值；用途【未知】，外觀像 RGBA／縮放類的重設，但**只是外觀推測**）。
     - 若為 `2`、`8`、`9` 之一：當 `[actor+0xF4]≠0`、`[actor+0x124]==0` 且 `[actor+0x134]/[actor+0x130] >` 常數 `double [C557F0]` 時呼叫 `4CC8B0`（開頭：`[esi+0x124]==0`、`[esi+0xF4]≠0`、依 `[esi+0xF8]` 分支，並以 `[0xFBA838]` 物件的 vtbl 呼叫；用途【未知】）。
  3. 若 `word [actor+4]` 與 `[0xFBA7A4]+0xC+12·i`（i=0..2）處物件的 `word [+4]` 相等（以 `si` 比較；4B2A56..4B2A7B），找到則 `call [[0xFBA7A4]→vtbl+0x14]`（對 `ecx=0xFBA7A4` 的控制器；用途【未知】）。這與 5452C0 使用的控制器槽結構（stride 0xC）一致。
  4. **`4DFBC0`**（`eax=0xFAB130`；`push word id`；4B2AB5..4B2AC2）。
- `[actor+4]` 的語意：CBasicObject 建構（`4CA730..4CA7CA`）把 `word [actor+4]` 初始化為 0；之後寫入點【未查】。`5452C0` 把它寫入 0x0A 封包、`4B28D0` 以它在 3 個控制器槽中比對；但 map 的**插入點**本次未找到（`0xFAB138` 的 38 個直接引用都是 `82EF00` 查找），因此「`[actor+4]`＝ `FAB138` 的鍵」只是【推測】（高度一致，但無插入證據）。**前一份寫為確認的敘述降為推測**。

## 二、4DFBC0（`eax=holder(0xFAB130)`；`ret 4`；參數 `word id`）（【確認】）
1. 在 `holder+8`（＝`0xFAB138` map，與 `4B2730` 查的同一個 map）以 `82EF00` 查找 `id`；等於 end（`[holder+0xC]`）→ 直接回傳（4DFBDD..4DFBE0）。
2. 對 `i=0..2`：`call [vtbl+0x1C](i)`（`ecx=[0xFBA7A4]`，控制器；4DFBE4..4DFBF6；用途【未知】，與 3 個槽一一對應）。
3. `actor=[node+0x10]`：`call [actor vtbl+0x14]`（4DFBF8..4DFC00）。
4. `actor≠0`：`call [vtbl+0](push 1)`（MSVC scalar-deleting destructor 慣例；與 `8045EC` 對 CIocpNetwork 的刪除相同寫法），並 `[node+0x10]=0`（4DFC02..4DFC11）。
5. `7B6890`（map erase；參數 map、key、節點迭代器；4DFC18..4DFC1E）。
- 姊妹 `4DFC30`：同樣對 `holder+0x18` 的**另一個 map**（`8438C0` 查找；與 `8069A0` 查連線容器所用的同一種函式）做 erase 並 `free([node+0x10])`（`89120C`）；它的鍵／語意【未知】。

## 三、與前幾份
| 項目 | 結論 |
| --- | --- |
| `4B2730`（0x18）與本檔 | 同一個 map（`0xFAB138`）；0x18＝設定移動目標，0x1A＝依 id 移除。 |
| `0xFAB130` 的結構 | 前文：`FAB1D0` 為其 `+0xA0`；本檔補：`+8`＝以 word id 為鍵的 actor map（`FAB138`，end 節點 `[+0xC]`＝`FAB13C`），`+0x18`＝另一個 map。 |
| 前一份對 `[actor+4]`＝鍵 | 降為推測，見一節。 |

## 四、尚未確認
- map 的插入點（可能是某「建立 actor」封包處理器，如表 A 中其他索引）；`[actor+4]` 的寫入者。
- `data+2` 的 word；`7A7CC0/7A7BF0`、`4CC8B0`、控制器 vtbl+0x14/+0x1C 的語意。
- actor 被刪除時，3 個控制器槽的指標是否被清除（`vtbl+0x1C(i)` 的內容未讀）。

## 建議
- 值得提交：`kr-temp-roy/`。T09 以外亦屬 T06/T07（場景內物件生成／消失）。
- 下一步（T09）：找 `0xFAB138` map 的**插入**（建立 actor 並登記）——搜尋以 `holder+8`／`FAB138` 為 `this` 的非 `82EF00` 呼叫（例如 `7B6xxx` 家族的 insert），可確認 `[actor+4]`＝鍵與 spawn 封包的命令索引。
