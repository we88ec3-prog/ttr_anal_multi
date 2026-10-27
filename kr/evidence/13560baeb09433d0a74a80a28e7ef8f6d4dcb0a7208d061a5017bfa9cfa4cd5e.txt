# KR T10：按鍵時間狀態機與戰鬥輸入合流（候選路徑，尚未證實 Z 映射）

## 0. 工作邊界
- Task：KR T10「普通攻擊與連段」；使用者補充：普攻連擊有兩種操作：**Z 連按**與**Z 持續按住**。這是使用者提供的遊戲操作事實，不是由 BIN 自行推得。
- GitHub `kr/tasks/T10/README.md` / `task.json`：研究輸入、連段、取消；傷害交 T12；owner=null，native_complete=false，尚未正式認領。僅唯讀分析，不更新 task.json/catalog、不 commit。
- 第一手來源：`/mnt/data/Tartaros.bin` PE32 i386；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。另 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本段沒有將此 EXE 認作同版戰鬥邏輯。
- `objdump -h` 驗證 `.text` VMA 0x00401000/raw 0x400，`.rdata` 0x00BD2000/raw 0x007D0600，`.data` 0x00D61000/raw 0x0095E800。依此實際 PE header 定位下列 VA。
- 分類：**BIN 直接證據**、**推導（有條件）**、**未驗證**；所有自命名皆為暫定。

## 1. 關鍵新證據：0x547240 的按鍵時間狀態機
完整入口約 `0x547240..0x54736F`。其 `ESI` 指向暫定狀態記錄，`[ESI]` 為狀態（0..3），`[ESI+4]` 為先前儲存的計時值。讀 `[0x00FB9014]` 的 byte 輸入狀態。使用 IAT `[0x00BD25A0]` 讀取計時值，差值與 `0x1F4` (=500) 比較。

摘錄（由原 BIN 解碼）：
```asm
54728E mov ecx,[esi]              ; 0..3 的索引
547290 movzx eax,byte [0xFB9014]  ; 輸入狀態 byte
5472A0 jmp dword [ecx*4+0x547370]
5472A7 cmp eax,1
5472AC cmp eax,2
5472B5 call dword [0xBD25A0]     ; timer-like IAT，名稱待核
5472C0 mov [esi+4],eax
5472C3 mov dword [esi],2
5472F6 cmp eax,3
5472FF call dword [0xBD25A0]
547305 sub eax,[esi+4]
547308 cmp eax,0x1F4
54730D jbe 0x54735E
547317 mov dword [esi],3
54732F mov [esi+4],edi
547332 mov [esi],edi
```
跳表 `[0x547370]` 小端 DWORD 分別是 `0x5472A7, 0x5472DB, 0x5472F6, 0x54734B`，對應 0/1/2/3 狀態。輸出返回碼可為 1、2、3、4（依分支）；**不能在尚未查證 `[0xFB9014]` 的按鍵映射前稱此函式為 Z 長按判定**。`0x1F4` 為讀取時鐘後的數值差閾值；若 IAT 是毫秒時計才可解釋為 500 ms，待核。

## 2. 0x546780 收集／合併狀態機結果
`0x546780..0x546842`：
```asm
546791 movzx ebx,word [edi+0x5C] ; 原始輸入 bitmask
546795 lea esi,[edi+0x40]        ; 傳入上述狀態機的暫定物件
5467A4 call 0x547240
5467AD sub eax,2
5467B8 or ebx,0x40               ; return 4
5467BD or ebx,0x80               ; return 3
5467C5 or ebx,0x08               ; return 2
5467CD call 0x546850             ; 另外一組輸入/方向資訊
5467E0 call 0x546B50             ; 另一候選（含滑鼠座標處理）
5467EC call 0x546D50             ; 另一候選（含指標座標處理）
5467F4 mov word [edx],bx         ; 寫輸出 input word
```
- **直接確認**：狀態機結果映射到 `0x0008/0x0080/0x0040` 三種 bits，與控制器既有 `[controller+0x5C]` WORD 合併。
- **未確認**：這三個 bit 是否是普攻/連段/長按，也不能由 `0x0008` 猜成 Z。
- `0x546850` 讀數個全域 byte (`0xFB9005..0xFB9008`)，處理方向；`0x546B50` 讀 `[0xFB1318]+0xC01C` 位元與指標座標，並使用 controller `+0x7C/+0x80` 狀態；`0x546D50` 亦有指標相關路徑。這些有其他用途，不能一概指派攻擊。

## 3. 上游控制器與輸出 gate
在 `0x546100`（既有 T10 候選輸入產生函式）：
```asm
54618B mov dl,[edi+0xB0]
546191 mov word [ebx+2],ax        ; 初始化輸出 input word
54619B mov [ebx+4],al            ; 初始化 heading
546263 call 0x546780             ; 生成候選輸入狀態
546293 xor cx,ax
546296 mov edx,0x7FFF
54629B and cx,dx
54629E xor word [ebx+2],cx       ; 僅合併低 15 位
5462DD call 0x54F270            ; 狀態控制 gate，語義未核
5462FD mov edx,0x8000
546302 and word [ebx+2],dx       ; 有分支清除低 15 位
5463F4 test eax,0x7FFF          ; 檢查低 15 位
5463FB or eax,0x8000            ; 另有高 bit 特殊分支
```
對輸出 5-byte row 而言，`[ebx+2]` 為 input WORD、`[ebx+4]` 為方向 byte（與 `kr/evidence/1e156...txt` 歷史筆記一致）。`0x8000` 高位與低 15 位的語義仍不能定名。

## 4. 候選呼叫鏈與暫定 C++ 偽碼
```cpp
// 只描述已觀察的資料操作；key 和時間單位、bits 意義未知。
int StateMachine547240(State* s) {
    uint8_t mode = *(uint8_t*)0xFB9014;
    // switch(s->phase 0..3) 依 (mode, timer - s->savedTick)
    // 產出 0/1/2/3/4 的 transition code；某路徑 threshold > 0x1F4
}
bool CollectInput546780(Controller* c, ..., uint16_t* input) {
    uint16_t bits = c->bits_at_5C;
    int transition = StateMachine547240(&c->field_40);
    if (transition == 2) bits |= 0x0008;
    if (transition == 3) bits |= 0x0080;
    if (transition == 4) bits |= 0x0040;
    // 還會執行 546850、546B50、546D50，取得其他狀態/方向
    *input = bits;
    // return 是否有其他輸入變化
}
```
此鏈為 `0x546100 -> 0x546780 -> 0x547240`；下游 `0x546100` 的 low15 gate 及 `0x5452C0` 已知 000A row 組裝是後續需核的接合位置。不能聲稱已建立「Z -> 連段 -> socket」閉合證據。

## 5. Z 連按 vs Z 長按：暫定驗證矩陣
| 操作 | 預期需要分辨的訊號 | 已核到的候選 | 仍缺的直接證據 |
|---|---|---|---|
| Z 連按 | key-down transition、release、重新按下 | 0x547240 0..3 狀態 / 0xFB9014 | Z key mapping / 原生輸入更新者 / 連段消費者 |
| Z 長按 | held state、跨 frame 持續輸入 | 0x547240 計時器與不同輸出碼 | 是否真代表 Z held / 是否每段自動續發 |
| 合流 | input WORD 或本機動作觸發 | 0x546780 的 OR bits，0x546100 output | bits->動作、動畫及伺服器回覆對應 |
| 取消 | 封鎖、重置、狀態 gate | 0x546100 的 low15 bit 清除分支 | 真正取消原因、允許時窗、哪些動作可取消 |

## 6. 結論/未解事項
**確認**：存在有 phase 0..3、原始輸入狀態 byte、timer 差閾值 0x1F4 的狀態機；結果會由控制器組合為 0x8/0x80/0x40 bits；控制器下游會依狀態清除低15位輸入。這是新分析，直接建立在 BIN 而非僅抄既有筆記。

**尚未確認**：`0xFB9014` 對應 Z、timer 時間單位、短按/長按在普攻中的用途、是否有伺服器連段排程、取消窗口，及 `CHAIN_WINDOW=.65` 的任何原生依據。特別地，`0x1F4` **不是已確認的普攻連段窗口**。

**下一段優先**：找出 `[0xFB9014]` 寫入者及按鍵映射（Z 的 VK/scancode）；核對 `0xBD25A0` IAT 符號；追查 `0x54F270`/state gate、`0x0008/0x0040/0x0080` 的消費者及 actor motion；再將真 Z 連按/長按與 000A 傳輸關聯。與 T12 傷害、T09 移動已有 owner 方法保持隔離。

## 7. 協作與 Git 狀態
參考 `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、`kr/tasks/T10/README.md`、`kr/tasks/T10/task.json`。所有原始檔唯讀，未執行目標、未修改主程式。沒有使用者 commit 授權，**未 Commit / Push**；尚未正式在 task.json/catalog 登記 owner，故筆記先保存為可交付 Markdown，不修改他人目錄。