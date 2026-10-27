# T08-105 延伸 — 六平面測試兩種入口、全域桶生產者及內嵌桶持有者（BIN 驗證）

- 時間：20261027-160157 Asia/Taipei
- BIN：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次重新驗證一致）。
- PE：`pei-i386`；`.text` VMA `0x00401000`，File off `0x400`，長 `0x7D01F0`（objdump -h 核對）。
- 依據：本次 `objdump -D -Mintel` 直接反組譯 BIN，與前段 T08-105 初稿比對。**本文為完整保留本次延伸工作之原始筆記，不代表 T08-105 的全部疑點已解決。**

## 1. 六平面緩衝的初始化及所有權

`0x00798DE0` 全域初始化流程：

```asm
00798E3A push 0x60
00798E41 call 0x00891268        ; heap allocate
00798E49 cmp eax,ebx          ; ebx=0
00798E4D fldz
00798E4F fst dword ptr [eax]
00798E51 fst dword ptr [eax+0x4]
...                            ; each DWORD/float offset 0x08..0x58
00798E93 fstp dword ptr [eax+0x5c]
00798E9C mov ds:[0x00FB76B0],eax
```

**已確認**：成功配置 `0x60` bytes，連續 24 個 float 以 `0.0` 初始化，指標儲存至 `[0x00FB76B0]`。失敗路徑寫入 NULL。`0x0079963F..0x00799657` 由全域取指標、呼叫 `0x0089120C` 釋放，再將全域清零；因此本全域持有 allocation 生命週期。

**未確認**：正常運作時將 24 個 float 改寫為新值的指令或間接函式；初始化零值本身無法證明該物件即相機視錐。

## 2. 新確認：兩種六平面比較函式的精確差異

### 2.1 `0x00838800`：三 float 點測試

```asm
00838803 fld dword ptr [ebp+0x10] ; z
00838808 fld dword ptr [ebp+0x0c] ; y
0083880B add edx,0x8             ; edx points to first plane c
0083880E fld dword ptr [ebp+0x08] ; x
00838813 fld dword ptr [edx-0x8] ; a
00838816 fmul st,st(2)           ; a*x
00838818 fld dword ptr [edx-0x4] ; b
0083881B fmul st,st(4)           ; b*y
0083881D faddp st(1),st
0083881F fld dword ptr [edx]     ; c
00838821 fmul st,st(5)           ; c*z
00838823 faddp st(1),st
0083882B fadd dword ptr [edx+0x4] ; + d
00838837 inc ecx
00838838 add edx,0x10
0083883B cmp ecx,0x6
00838842 mov eax,0x1             ; all six passed
00838853 xor eax,eax             ; one failed
0083884D ret 0x0c
0083885C ret 0x0c
```

條件依 `fcomp`／`test ah,0x41`／`je` 評估；已確認每組計算 `a*x+b*y+c*z+d`，並對六組做提前結束測試。為避免浮點旗標與 NaN 分支被高階化誤寫，本文不將其簡化成未經證實的精確 `<` / `>=` 排除規則。

已確認入口：`0x0049DAFB`、`0x004AA320`、`0x004C9BEB`、`0x0055B439`、`0x0055B627`，均將三個位置 float 壓入堆疊，`edx=[0x00FB76B0]`，呼叫 `0x00838800`，隨後 `test eax,eax` 決定分支。

### 2.2 `0x00838860`：四 float 測試（第四量用作比較閾值）

```asm
00838863 fld dword ptr [ebp+0x14] ; fourth scalar
0083886E fld dword ptr [ebp+0x0c]
00838871 fld dword ptr [ebp+0x08]
00838874 fld dword ptr [edx-0x8]  ; a
00838877 fmul st,st(1)
00838879 fld dword ptr [edx-0x4]  ; b
0083887C fmul st,st(3)
0083887E faddp st(1),st
00838880 fld dword ptr [edx]      ; c
00838882 fmul st,st(4)
00838884 faddp st(1),st
0083888C fadd dword ptr [edx+0x4] ; + d
00838895 fcomp st(4)             ; compare to fourth input
0083889E inc ecx
0083889F add edx,0x10
008388A2 cmp ecx,0x6
008388A9 mov eax,0x1
008388BA xor eax,eax
008388B5 ret 0x10
008388C3 ret 0x10
```

**已確認**：兩函式均讀同一排列的六個 16-byte 平面係數。前者使用三個 float；後者以第四 float 作比較基準，而**不是**把第四 float 乘上 plane `d`。`0x007F259F`、`0x007F754A`、`0x007F98BE`、`0x007FE498` 等均提供四個 float 呼叫後者。

**推測**：第四參數可能是球形界限相關量，但尚未證實必然是半徑或特定場景物件形狀。

## 3. 全域 `[0x00FB7740]` 的配置與可證生產者

```asm
00798F26 push 0x2c058
00798F4F call 0x00891268
00798F5B mov edx,0x15
00798F60 lea ecx,[eax+0x2000]
00798F66 mov dword ptr [ecx],ebx ; 22 bucket counts set to zero
00798F68 add ecx,0x2004
00798F6E sub edx,edi           ; edi = 1
00798F78 mov ds:[0x00FB7740],eax
```

22 個 `0x2004` 的桶（`0x2C058` 正好等於 22*`0x2004`）用於每桶 2048 指標與 count；額外尾端大小為 0。不能僅因其它 manager 具有相同 bucket layout 就視同同一配置。

典型全域插入指令：

```asm
0079CDA8 mov edi,ds:[0x00FB7740]
0079CDB0 call edx                  ; object vtable+0x04, return bucket index
0079CDB2 imul eax,eax,0x2004
0079CDB8 mov ecx,[eax+edi+0x2000]
0079CDC1 cmp ecx,0x800
0079CDC9 mov [eax+ecx*4],esi      ; eax now points to bucket base
0079CDCC inc dword ptr [eax+0x2000]
```

另在 `0x007F96ED`、`0x007FEC92` 觀察同型插入；`0x007FECE9` 進一步額外插入固定第10桶：

```asm
007FECE9 mov edx,ds:[0x00FB7740]
007FECEF mov ecx,[edx+0x16028]  ; bucket10 count = 10*0x2004 + 0x2000
007FECF5 cmp ecx,0x800
007FECFD mov [edx+ecx*4+0x14028],esi
007FED04 inc dword ptr [edx+0x16028]
```

**注意**：`0x007F96ED` 局部使用 `add [eax+0x2000],ebx`，是否相當於 count++ 需要先追溯 `ebx`，不能與固定 `inc` 直接等同。

## 4. 管理器內嵌桶：新追到更廣泛的 consumer 輪次

`0x007D13D8`、`0x007D1452`、`0x007D14E0` 的物件來源是 `[ebx + per_bucket_offset + i*4]`，會呼叫 `entry.vtable+0x0C`，第二參數逐段分別為 1、2、4，且各自將 `ebx+bucket_count_offset` 清零。這表明 `0x007D170B` 的 19～21 桶並非唯一內嵌桶 consumer，而是此管理器多階段消費流程末端之一。

進一步 `0x007D16A0` 消費管理器 `[ebx+0x24048]` 的桶；`0x007D16BA` 以 `push 0x00FB76A8` 呼叫 `0x0079A5F0`；`0x007D16E4..0x007D16F6` 遍歷八次另一個由 `0x0079A5F0` 取得的介面方法 `vtable+0xD4`；`0x007D16FD` 從 `[ebx+0x2604C]` 起消費桶 19,20,21，然後 `0x007D1769..0x007D178F` 清掉此**內嵌**物件所有22桶 count。

**已確認的區隔**：這些函式由 `ebx` 管理器位址計算內嵌 bucket，並未在 consumer 中取 `[0x00FB7740]`。故不可把 `0x007D170B`（或同一管理器的早期階段）列為全域分桶的已確認消費者。

**語義限制**：每個 entry vtable+0x0C 的具體類型、`ebx` 的配置者、consumer 的外部呼叫者和周期仍未追畢；僅能確定多階段 dispatch/reset，不可命名為場景主迴圈或渲染主迴圈。

## 5. 新判定：係數直接引用的資料角色

本次檢視先前 16 個 `[0x00FB76B0]` 的直接絕對引用。觀察到初始化（`0x00798E9C`）、清理（`0x0079963F` 及 `0x00799651`）以及大量呼叫 `0x00838800/0x00838860` 的讀取者；例如 `0x007A5D44`、`0x007E10E8`、`0x007E4354`、`0x007F3030`、`0x007F98BE` 皆屬將全域指標交給六平面測試函式的路徑。

因此**直接絕對引用中目前沒有定位到正常影格更新係數內容的寫入者**。但間接別名（結構內指標、參數傳遞、陣列拷貝、memcpy、一次性計算函式等）仍完全可能；不得說系統從不更新係數。

## 6. 待解及下一段 T08-106 建議

1. `0x00FB76B0` 的**非初始化**寫入者：以 `0x60` 長度的 copy/memcpy 或 `mov/fstp [base+0..0x5C]` 反向搜尋；檢查 `[0x00FB76AC]` 是否為計算平面的上游矩陣／向量，但目前只有配置為0x10及 0,0,0,1 初始化之證據。
2. 全域22桶 consumer：從桶指標存入其它全域／物件欄位的別名流、含 `0x2004` 步距及 `+0x2000` 清零的迴圈檢索。每個候選須證明最後讀取的基址源自 `[0x00FB7740]`。
3. 內嵌 manager `ebx` 來源：尋找容器建構者與 `0x007D13xx` 函式入口／呼叫者，解析分桶 `vtable+0x0C` 動態目標。
4. 若有真正場景主更新入口交叉引用，才串至場景物件 vtable `0x00C07554+0x20`（函式 `0x004C8580`）。

### 證據分級

- **已確認**：本文件具體 BIN 位址、逐指令彙編、呼叫目標、計數陣列佈局及 3-float / 4-float 比較差異。
- **合理推測**：係數可以表達六個半空間；四參數入口可能為附帶邊界值的測試。
- **尚待驗證**：係數更新者、全域桶 consumer、entry 多型實作、相機視錐的身份、管理器持有者、更新頻率、場景主更新鏈。

## 7. Git 及來源界線

前段 T08-105 初稿在本地 `/mnt/data/20261027-155733-chatgpt-web-roy-T08-105-global-buckets-plane-writers.md`，本次延伸作為另一份完整原始筆記保留。未修改 BIN 或 EXE；本次沒有 Commit 授權，**沒有 Commit 或 Push**。GitHub 目前長期知識庫 `kr-temp-roy/T08-KNOWLEDGE-BASE.md` 僅作既有研究背景；本次新增結論依 BIN 直接反組譯。