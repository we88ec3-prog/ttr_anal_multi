# KR T10-2 — 條件樹插入副作用與輸入 Bank 寫入路徑

日期：2026-10-27 Asia/Taipei。任務編號依使用者新規則：先前全部研究歸 T10-1；本篇為 T10-2。未 Commit／Push。

## 0. 研究邊界和來源

本篇使用 `/mnt/data/Tartaros.bin` 唯讀反組譯，SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`objdump -d -Mintel --start-address --stop-address`；目標為 KR PE32 i386。未執行客戶端。引用 T10-1 文件 `20261027-T10-matrix-and-input-bank-analysis.md` 的候選鏈，但以下關於內部配置/插入及 Bank 寫入使用**本次 BIN**直接核對。

研究問題：(A) `0x54F4E0` 是否只查詢？(B) `0x6D0Bxx` 對 bank row 做了什麼？(C) 這些是否足以確認 Z 連按／長按？結論：(A) 否、可插入；(B) 至少有 DWORD 值 append 到 bank 中 row vector；(C) 不足。

## 1. `0x54F4E0–0x54F56B`：條件樹查找後可插入

證據摘要：

```asm
54F4EA mov ecx,[ebx+4]      ; tree/header
54F4F1 mov eax,[ecx+4]      ; initial node
54F4F4 cmp byte [eax+21h],0 ; sentinel candidate
54F500 cmp [eax+0Ch],ecx    ; key comparison
54F505 mov eax,[eax+8]      ; right candidate
54F50C mov eax,[eax]        ; left candidate
54F519 mov eax,[edi]        ; sought key
54F51B cmp eax,[esi+0Ch]
54F51E jae 54F562          ; existing-node return
54F542 call 54F7D0         ; allocate + initialize node
54F54E call 54F6A0         ; insertion logic
54F553 mov eax,[ebp+8]
54F556 add eax,10h         ; new-node payload pointer
54F562 ...
54F563 lea eax,[esi+10h]   ; existing-node payload pointer
```

**已確認**：此 helper 不是 pure lookup。不存在適當節點／key 落在缺口時會走建立新節點與插入。`0x54F270` 的末端 `cmp dword [eax+4],0` 讀的是**返回 payload 指標 +4**，不能僅憑此稱「是否能取消攻擊」或「連段允許」。

## 2. `0x54F7D0–0x54F849`：新節點配置與值複製

```asm
54F7D7 push 24h
54F7DB call 891268          ; allocating helper, 0x24 bytes
54F7E9 mov edx,[esi+4]
54F7EC mov [eax],edx         ; child/header linkage
54F7F1 mov [eax+4],edx
54F7F7 mov [eax+8],edx
54F7FD mov word [eax+20h],cx
54F805 mov ecx,[edi]
54F807 mov [eax+0Ch],ecx
54F809 mov esi,[edi+4]
54F80C mov [eax+10h],esi
54F80F mov esi,[edi+8]
54F812 mov [eax+14h],esi
54F815 mov esi,[edi+0Ch]
54F818 mov [eax+18h],esi
54F81B mov ecx,[edi+10h]
54F81E mov [eax+1Ch],ecx
```

配置為 **0x24 bytes**，其中 links `+0/+4/+8`、鍵 `+0x0C`、後續 16 bytes `+0x10..+0x1F`，狀態/顏色候選位元組 `+0x20/+0x21`。`0x54F7D0` 只是建立節點，無法單憑其本身斷言所有不同節點類型的生命週期。

## 3. `0x54F6A0–0x54F7BE` 與 `0x597E80`：實際樹連接

`0x54F6A0` 依樹大小及 key 位置選擇插入方位，多處呼叫 `0x597E80`，部分分支走 `0x597DB0` 再得到結果。示例：

```asm
54F6AE cmp dword [edi+8],0
54F6B6 mov eax,[edi+4]
54F6B9 push esi
54F6BA push 1
54F6BC push ebx
54F6BD call 597E80
...
54F71E mov ecx,[esi+0Ch]
54F721 cmp ecx,[eax+0Ch]
54F74C call 597E80
54F7AA lea esi,[ebp-8]
54F7AD call 597DB0
```

下層 `0x597E80` 證據：

```asm
597E83 mov ecx,[edi+8]      ; current count
597EA7 inc ecx
597EA8 mov [edi+8],ecx      ; count modified
597EAB mov [edx+4],eax      ; parent link
597EB5 mov [ecx+4],edx      ; root/header case
597EBB mov [ecx],edx
597EC0 mov [eax+8],edx
597ECB mov [eax],edx        ; left child case
597ED8 mov [eax+8],edx     ; right child case
597EE6 mov ecx,[edx+4]
597F25 mov byte [edx+20h],bl ; tree balancing candidate
```

**結論確證**：發生 count++ 及 parent/child 指標寫入，不是單純搜尋。尾端分支含類似樹平衡操作，函式 `0x597E80` 後半段尚未全量審核，稱為「平衡候選」而非強指定 RB-tree 標準實作。

### 修正 T10-1 的敘述

T10-1「可能插入」可升級為「`0x54F4E0` 的 miss 路徑確有配置與樹插入」（透過 `0x54F7D0 → 0x54F6A0 → 0x597E80`）；但是 **`0x54F270` 返回值真正遊戲語義仍未確認**。如果 miss 會新增一個零初始化/複製的 payload，gate 的數值可能受預設值及後續寫入影響，不能當成單純固定 allow-list。

## 4. Bank 資料：`0x6D0B00` 是較大函式的內部區塊，確有 DWORD 追加

**重要校正**：先前 T10-1 將 `0x6D0B00–0x6D0B6C` 當獨立函式範圍來描述並不嚴謹。由 `0x6D0BF1 jmp 0x6D0B00`、`0x6D0B71 jmp 0x6D0A2C` 及 `0x6D0C26 jmp 0x6D0A51` 可見它位於更大的控制流中；不得標註為已完整還原的函式。

```asm
6D0B00 mov esi,[esp+20h]
6D0B04 movzx edi,al
6D0B07 mov eax,[esp+1Ch]
6D0B0B lea esi,[esi+eax]
6D0B0E movzx ecx,bl
6D0B11 shl esi,4             ; row_index * 16
6D0B14 shl edi,10h
6D0B17 or edi,ecx            ; construct DWORD from two 8-bit values
6D0B19 add esi,0FB8834h     ; bank base + 16-byte row
6D0B1F mov eax,[esi+4]      ; vector end
6D0B32 mov ecx,[esi]        ; vector begin
6D0B47 cmp eax,[esi+8]      ; capacity bound
6D0B53 call 6D6240          ; ensure capacity candidate
6D0B68 mov ecx,[ecx]
6D0B6A mov [eax],ecx         ; append copy from in-buffer alias case
6D0BF6 cmp eax,[esi+8]
6D0C02 call 6D6240
6D0C07 mov eax,[esi+4]
6D0C0E mov [eax],edi         ; append constructed DWORD
6D0C14 add [esi+4],4        ; increment end
```

**已確認**：這條路徑在 `0xFB8834 + 16*(indexA+indexB)` 取得 row，並向該 row 的 4-byte element vector 新增一個 DWORD，編碼形式為 `(uint8_t)AL << 16 | (uint8_t)BL`；輸入還有外側迴圈與其他來源。基於這是 Bank 內某 row 的寫入**不能直接推導這是遊戲執行期按 Z 按鍵事件的 writer**。從附近 `0x6D0A18 call 0x8917B4`、`0x6D0A23 cmp esi,3` 可見有外部文字/數值解析及範圍判斷，這條路徑更可能是讀入/建立映射表（**合理推測，尚非已確認**），不是 frame tick 鍵盤事件。

## 5. 與 Z 連按／Z 長按關係：嚴格證據界線

使用者確認有兩種操作：反覆連按 Z，以及按住 Z 不放。這是待解釋的遊戲可觀察行為，不是上面指令的語義標籤。

- 已確認：三個選用的 0x280 bank（T10-1）、bank row 中動態 vector 寫入（本段）、`0x54F270` 的條件查找帶插入副作用（本段）。
- 合理假說：輸入 Bank 可保存鍵碼到內部動作組合的配置；按下事件與持續 held-state 可能在控制器打包後合流。均需 key source、caller 和 frame update 的交叉引用。
- 未證實：Z 對應的實際 scancode / virtual key；Z 連按是否每次 edge 觸發攻擊；Z 按住是否引起 autorepeat 或每 tick 重新生成攻擊指令；哪個攻擊 state machine 接收；服務端續段規則及取消窗口。
- **500ms 已是 timeGetTime 門檻，但尚不可當作 Z 長按／連段時間**；`CHAIN_WINDOW=0.65` 是自製數值。

## 6. 後續 T10-3 指向

1. 對 `0x6D09xx` 較大函式確定入口/呼叫者與字串解析來源，驗證是否為載入鍵盤映射；再做 keycode/Z 資料來源搜尋。
2. 從實際鍵盤事件的分發器定位 `0xFB9014` 的**非零寫入**（可能為索引/別名），接上 `0x547240` 及 `0x546780`，嚴格區分 held 與 edge。
3. 選特定 `0x54F270` caller，確定第一參數位元來源與所查樹的 owner、初值、後續寫入者，再將結果連接到攻擊 state handler。
4. 維持 T02/T04/T09/T12 分工，未完成證據前不補官方連段/取消數值。

## 7. GitHub/安全

沒有更動 repository、task.json、owner、catalog 或別人筆記；沒有 Commit/Push；沒有執行或修改遊戲原始客戶端。以上是 T10-2 的原始技術研究，**不是 Z 攻擊鏈已還原完成**。