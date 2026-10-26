# KR T09 / T02 共用 — 接收鏈：807B40 → 佇列 FC10D0 → worker 804740 → CClient vtbl+0 的 4930E0（命令字＝資料首 word）

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 08:06:10 +08:00`
- Scope: `Tartaros.bin` PE32 x86；`8040A0..8040F5`、`804100..`（前段）、`804740..804A0C`（前段至回呼）、`49198A` 附近、`4930E0..49315E`、`493170..49325x`（前段）、`48ACA0..48AD60`（CClient 建構，前段）；RTTI 讀取（`C05AA4`、`C05AEC`、`C515EC`）
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…handler-table-4ADD50.md` 的「下一步：找分派者」
- Summary: 把「收到封包 → 處理器」的鏈接到 CClient：`807B40`（網路執行緒側）把解出的封包依連線頻道索引放入雙緩衝佇列 `0xFC10D0`（`8040A0`）；CClient 的 frame 函式（`CClient` vtbl+0x30＝`490FE0`）呼叫 `804740`，由後者取出封包並呼叫 `CClient`（作為 `CTCPInterface` 子物件）vtbl+0 ＝ **`4930E0(node0, data, len, channel)`**；其中 **`edi = word [data]`（資料首 word）** 即「命令字」，頻道 2 時轉交 `[this+0xB8]` 物件的 vtbl+4。該物件的類別與其查表方式本次**未找到**，故「索引＝命令字」仍為【推測】。

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認

## 一、佇列 FC10D0（【確認】）
- `8040A0(node, chan)`（`edi＝FC10D0` 物件，`ret 8`）：鎖 `[edi+0x124]`；以 `byte [edi+chan+0x128]==0` 選擇雙緩衝的哪一半：佇列位址＝`edi + ((flag + chan*2)*3)*8`（每個佇列 0x18 bytes，3 個頻道 × 2 緩衝）；`804260` 推入；解鎖；若 `chan==2` 則呼叫 `SetEvent`（`[BD20D0]`，對 `[edi+0x120]`）。
- 唯一呼叫點：`807DAD`（`807B40` 之後的函式，緊跟 `489920` 取得 `FC10D0`）。頻道索引＝`[conn+0xA080]`（來自連線物件；其值來源未查）。
- `803FF0`（`489920` 首次呼叫時的靜態初始化）：以向量建構器 `892003`（元素 0x18、個數 0xC）建立 `FC10D0` 陣列。
- 當 `[node+4]==0`（長度 0）時走另一路：`804310`（回傳 `0xFE3358` 節點池）＋`8076F0(node)`（歸還節點；`dec [pool+0x54]`）。

## 二、worker 804740（`ret 4`，`ebx＝arg`）（【確認】流程）
- 迴圈：`804100(&node, chan)`（`eax=0xFC10D0`）自雙緩衝取一個節點；`call [[ebx]+0]`：`this=ebx`，**stdcall 4 參數 `(node[0], &node[8]`〔資料〕`, node[4]`〔長度〕`, chan)`**（804862..80486D）；以 `timeGetTime`（`[BD25A0]`）量測耗時，若 `>0x28`（40）則呼叫 `[[ebx]+8]`（`arg=[ebx+0x8C]`，疑為慢速記錄；語意【未知】）；呼叫完後 `[node]=[node+4]=0`，並把節點指標推回池（`FE33xx` 環形陣列）。
- 呼叫者：`49198A`（`CClient` 的 vtbl+0x30 函式 `490FE0` 之中；`ebx = this+0x140`）。**`490FE0` 被登記於 vtable `C05AA4`（RTTI `.?AVCClient@@`）的 slot 0x30**（`C05AA4+0x30 = 0x490FE0`）。
- 該函式另在 `4919DB..491A25` 讀 `FC1140/FC11FA`（雙緩衝佇列的筆數，統計用；`call 6DAEF0` 之前）。

## 三、被呼叫的物件與 vtbl+0 = 4930E0（【確認】）
- `CClient` 建構（`48ACA0..`）：`[edi]=C05A9C`、`[esi=edi+8]=C05AA4`、`[edi+0x200]=C05B04`；`lea eax,[edi+0x148]; call 804380`（基底 `CTCPInterface`，vtable `C515EC`，RTTI `.?AVCTCPInterface@@`），隨後 `[eax]=0xC05AEC`（vtable，**RTTI `.?AVCClient@@`**）。故 `49198A` 的 `ebx`（`this+0x140`，以 `esi=edi+8` 為基準）就是這個 `CTCPInterface` 子物件，其 vtbl 為 `C05AEC`：slot0 ＝ **`4930E0`**、slot1＝`5F5D10`、slot2..4＝`49AE20/49AE10/49AE00`；`C515EC`：slot0＝`891FB2`、slot4＝`804430`。
- `4930E0(node0 [ebp+8], data [ebp+0xC], len [ebp+0x10], chan [ebp+0x14])`（`ret 0x10`；`ecx＝CClient`）：
  - `edi = movzx word [data]`（**資料首 word**，命令字候選）；`len==0` → 回傳 0。
  - `chan - 2 == 0`（頻道 2）時：呼叫 `6DB1F0(eax=this+0xBEE0, edi, len)`（記錄；語意【未知】）、`timeGetTime`，然後 **`call [[this+0xB8]+4]`**，`ecx = this+0xB8`，參數 `(data, len, cmd=edi)`；回傳值 `edi'`；若 `edi'==0x100` 且 `[this+0xBE8C]≠0` 則 `[ebp-1]=1`（回傳 al）。**`4B24F0`（`mov eax,0x100` 回傳）正是會回傳 0x100 的處理器**，與此檢查吻合——暗示 `[this+0xB8]` 物件的 vtbl+4 會呼叫處理器表中的處理器並把其回傳值傳回（【推測】，未見該函式）。
  - 其他頻道：直接回傳 0。
- `this+0xB8` 為內嵌子物件（`lea ecx,[esi+0xB8]`，`edx=[esi+0xB8]＝vtable`）。本次掃描 `mov dword [reg+0xB8/0xC0], imm(vtable)` 於全 `.text` **未找到**建構點，物件類別【未知】。

## 四、第二張表（493170）（【確認】形狀；用途【未知】）
- `493170(eax=對象)`：以 `edx=eax+0x210`、計數 `esi=0xBD5`、每筆 **0x10 bytes**：`[edx-8]=0x494360`（預設）、`[edx-4]=0`、`[edx]=0xBF2375`；之後覆寫例如 `[eax+0x398]=494780`、`[eax+0x1048]=4943B0`、`[eax+0x978]=494750`…（索引＝`(off-0x208)/0x10`：`0x398→0x19`）。與 `4ADD50` 同為 0xBD5 筆、同樣的 ctx 常數 `BF2375`，但**預設處理器不同（4B7D40 vs 494360）、每筆 0x10 vs 0x8 bytes**。哪一張對應 S→C 分派、哪一張是 C→S 建包，本次**無法判斷**。

## 五、對先前結論的修正
| 項目 | 結論 |
| --- | --- |
| 上一份「489920 回傳的是接收佇列／分派表之一」 | 修正：`489920` 回傳雙緩衝佇列物件 `FC10D0`（`8040A0` 的 `this`），不是處理器表。 |
| 上一份「索引＝命令字」 | 仍為【推測】：資料首 word 確由 `4930E0` 讀為 `edi`（確認），並傳給 `[this+0xB8]` 物件；但該物件如何使用它未見。 |
| 「4B24F0 返回 0x100」 | 現可對應 `4930E0` 內對 0x100 的檢查。 |

## 六、尚未確認
- `[this+0xB8]` 物件的類別與 vtbl+4（`4930E0` 的真正分派者）；`6DB1F0`。
- `[conn+0xA080]`（頻道）的值域；頻道 0/1/3 的處理者（`4930E0` 只處理頻道 2，其他頻道在別處）。
- `4ADD50` 表與 `493170` 表哪個被實際用於接收分派；兩表索引與 C→S 0x0A 命令字的對應。

## 建議
- 值得提交：`kr-temp-roy/`，T02 優先。
- 下一步：從 `4930E0` 的 `[esi+0xB8]` 反推：找建構 `CClient` 時填入 `+0xB8`（`edi+0xC0`）的程式（可能經基底建構器間接寫入）；或直接以 `ecx=this+0xB8`、`call [edx+4]` 的 vtable slot+4 反查 RTTI 類別（候選＝含 `4ADCD0` 或 `0xBD5` 的類別）。
