# E58 — RR-0004／KR T02：`Conn+A02C` 模式來源與 alias、`0x0BBB → 0x1A68` 失敗備援的有界靜態契約

> 狀態：**Client 可證靜態研究提交稿（bounded）**。本文不等於 T01 `FULL-PASS`、S00 `ACCEPTED`、原版 Server 實際連線紀錄，亦不宣稱所有間接 pointer alias 不存在。

- 生成時間（Asia/Taipei）：2026-10-30 11:09:06 CST。
- 原始 KR Client：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，**唯讀、未執行**。
- BIN mapping：PE `.text` VA start=`0x401000`，raw start=`0x400`，size=`0x7D01F0`；此節 raw=`VA−0x400C00`。直接比較已裁 `.text` slice 與原始 BIN，完全相符。
- 報告依據：原始 bytes + 從正確指令起點使用 GNU `objdump` 的反組譯；E57 是交叉參照，不取代驗證。只有已確認指令邊界的 operand 可直接解釋。
- 工作界線：RR-0004 (T02, GAP-NET-0001)，分析 `0x805D02`、可能 indirect alias、`0x8061A0` 中編碼／fallback 是否成立。RR-0001 的首包與原版 Server 首回覆僅在 mode 交界引用，不重新追所有初始業務命令。

## 一、玩家能理解的目的

原版遊戲有兩種可見的**出站封包外殼**：`0x0BBB`（帶 XOR/校驗）與 `0x1A68`（明文資料外殼）。同一包遊戲命令可能因連線目前的 `Conn+A02C`、長度與緩衝空間而選擇不同外殼。這不是帳號密碼或技能封包代號，也不代表原版 Server 必然先發某種包。

RR-0004 的目標是明確回答：**誰設定模式？有無發現寫入 0 的路徑？特殊封包什麼時候真的失敗？備援什麼時候能成功？失敗後佇列如何處置？**

## 二、驗收條件逐項矩陣

| 正式子問題 | 本稿的可證結論 | 證據等級 | 是否有界閉合 |
|---|---|---|---|
| 初始 A02C | `0x805D02` 將新配置 Conn 的 BYTE `+A02C` 寫成 `2`，預建與臨時新建均經此 constructor | N | 是（normal constructor） |
| 再利用 A02C | `0x805F50`／`0x806010` 不寫此 byte；Pool+48 和重用 `8059E9` 可回同一 Conn，欄位保留直到另一 writer | N/C | 是（已列舉 reset） |
| 其他直接 writer | `.text` 中 DWORD displacement `2C A0 00 00` 只有 constructor store 和 send reader；直接 CALL xrefs 在本稿另列 | N/C | 是（限定 byte-pattern 掃描） |
| 間接 alias writer | 未發現能證明會把該欄位寫成 0 的本地來源；間接實際地址、整物件 memcpy 或外部不透明指標不能以 displacement 搜尋全域排除 | C/U | **限定，無全域不存在證明** |
| mode 選擇 | `806202` 以 signed BYTE 載入：**0 直接呼叫 `807A70`；非零一律先呼叫 `807830`**，1/2/其他非零在此無獨立路徑 | N | 是 |
| `0x0BBB` 失敗 | `n==0`、`n+6>4096`、Tx 已累積 `used+n+6>16384`，或目標目的指標不在 buffer 上界內，均會 return 0 | N/C | 是（已列出本函式 guards） |
| `0x1A68` 備援 | mode 0 或 encoded return 0 → 呼叫 `807A70`，`n+4<=4096` 且同樣必須有 Tx 空間及合法 pointer，才會 return 1 | N/C | 是（已列出本函式 guards） |
| 真正可達的長度切換 | `8060D0` 允許把 `n<=4096` 傳入 queue；synthetic `n=4091/4092` 使 `0BBB` 長度 guard fail、`1A68` 在空 Tx 可成功 | N + 合成推導 | **靜態可達的輸入條件**；非真實遊戲封包觀測 |
| 兩 encoder 都失敗 | 若當前節點沒有成功封裝，`8063A4` 路徑**不執行成功的移除 node、回收 payload、Tx 累計**；函式返回還受 `A0B4`、本輪其他節點成功旗標影響 | N | 是（分支語意） |
| 接收模式 | `807B40` 使用**收到的 marker**判斷 0BBB/1A68/2633/22D7，不能由 sender `Conn+A02C` 直接推出 Server 的回覆 marker | N/C | 是（本地 parser gate） |

**符號：**N＝native assembly 確認；C＝有條件靜態結論；U＝無足夠原件證據；合成推導不等於 runtime、封包擷取或官方 Server 規格。

## 三、正向建構、重用與方法入口

### 3.1 Constructor 寫入只證明新建初始化

`0x805CA0` 同時出現在 `0x80577A`（Pool 預熱建立 Conn）及 `0x805A1B`（Pool 動態新建）。兩者的前方均有 `0xA0D8` 大小配置。`0x805D02` 直接寫 `BYTE [ESI+A02C]=2`。`0x805E1B` 在 constructor 結尾還呼叫 reset，但 `0x805F50` 不改它。此順序使新 Conn 對 send path 的預設條件為非零。

### 3.2 重用不等於再次 constructor

`0x805950` reuse 分支 `0x8059E9` 直接對回收 Conn 呼叫 `0x805F50`，不走 `0x805CA0`。`0x805BB7` 回收循環也執行 `0x805F50`。在**無其他 alias writer**的限定下，重用會保留原本的 `2`，但如果其他 writer 曾使它變 0，reset 亦不會自動改回 2。故不能擅稱所有 reuse `A02C==2`。

### 3.3 其他可比對的 metadata / buffer 邊界

- `Conn+0x18` 起為 Rx 區，`0x805CCB` 把 `[Conn+0x5018]` 指回 Rx 起點；這個 0x5000 大小的範圍末端在 `Conn+0x5018` 左右，不包含 A02C。
- `Conn+0x501C` 是 Tx 子物件入口；`[Conn+A020]` 是 Tx write cursor，`[Conn+A028]` 是累積 byte 數；正常資料寫入區為 `Conn+0x5020 .. Conn+0xA020` 的緩衝範圍（嚴格上界檢查）。
- `Conn+A02C` 距 Tx 控制指標 A020 為 +12，位於合法 Tx 寫入緩衝區之外。`0x807830/0x807A70` 的 pointer-guard 分支會排除正常越界到該欄位的操作；另有較小的 `0x4000` 累積 frame cap。
- `Conn+A028` 的 DWORD 存取量不跨入 `A02C`，因 DWORD 正好佔 `[A028,A02B]`。`Conn+A030` 是 WSARecv OVERLAPPED 的起始，前面也有 4-byte 間隙。
- 正常 Tx/Rx buffers 不改 A02C 是**受邊界驗證保護的局部反證**，不是整體行程所有 raw pointer 可寫地址的不可達性證明。

## 四、整節 byte 搜尋：能排除什麼、不能排除什麼

在 `.text` slice 直接搜尋完整 little-endian displacement `2c a0 00 00`，再把命中位置反算到 VA，檢查其所在指令與 operand；**不能把任意 byte 命中自動宣稱函式 xref**。同時搜尋相鄰 +A028、+A020、+A030 位移，以佐證送/收緩衝控制點。對直接 `E8 rel32` 以 call site + 5 + signed immediate 計算 target，仍不代表所有間接呼叫都已涵蓋。

| 4-byte disp | `.text` 命中數 | VA 位址（raw operand 起點） |
|---|---:|---|

| `0xA02C` | 2 | `0x805D04`, `0x806205` |

| `0xA028` | 16 | `0x598265`, `0x5D1946`, `0x5D1A48`, `0x604087`, `0x6151FB`, `0x625C74`, `0x665112`, `0x6B167B`, `0x6B59E2`, `0x804B23`, `0x804B3E`, `0x805275`, `0x805290`, `0x805D17`, `0x805F81`, `0x806EAD` |

| `0xA020` | 2 | `0x805D0B`, `0x805F8D` |

| `0xA030` | 4 | `0x805D28`, `0x806A0C`, `0x806DE6`, `0x806EDF` |

| `0xA02B` | 0 |  |

| `0xA02D` | 0 |  |

**A02C 的原件唯一兩處（在限定搜索內）：**

```asm
805D02 c6 86 2c a0 00 00 02    mov BYTE PTR [esi+0xa02c],0x2
806202 0f be 86 2c a0 00 00    movsx eax,BYTE PTR [esi+0xa02c]
```

本掃描未命中 `A02C` literal 的其它指令（但**變址／指標別名可能先取 `Conn` 再用較小 offset、或經 helper memcpy 寫入**）；因此只能報告「在既有可驗證的標準流程看不到 mode=0 setter」，不能報告「原版永不使用 mode=0」。

**直接 CALL 來源統計：**

| callee VA | E8 direct caller 數 | call sites |
|---|---:|---|

| `0x00805CA0` | 2 | `0x0080577A`, `0x00805A1B` |

| `0x00805F50` | 4 | `0x008059E9`, `0x00805BB7`, `0x00805E1B`, `0x00805E9E` |

| `0x00806010` | 2 | `0x00804C33`, `0x0080538D` |

| `0x008061A0` | 2 | `0x00804AD6`, `0x00805228` |

| `0x00807830` | 1 | `0x00806223` |

| `0x00807A70` | 1 | `0x0080623A` |

| `0x00805950` | 2 | `0x00806B16`, `0x008070BD` |

| `0x00806060` | 1 | `0x00806178` |

| `0x008060D0` | 2 | `0x00495853`, `0x008069EB` |

| `0x00807470` | 1 | `0x00806154` |

### 4.1 別名風險分解與可用反證

1. **確定的直接位移 writer：**`805D02`。任何「另有直接 `mov [reg+A02C]`」主張必須指出不符合本次 byte-pattern 或超出 `.text` 的來源。
2. **局部設計欄位：**`A02C` 與 `A028`、`A030` 相鄰但不重疊；正確長度與 pointer guard 下，這些鄰欄位的寫入不會修改 `A02C`。
3. **未知指標別名：**可能透過 `Conn+delta` 傳入通用寫入函式、以 `memset/memcpy` 大範圍覆蓋、以結構拷貝覆蓋，或動態 patch 修改。未建立對這些形態的全程完整別名圖，應維持 U，而不是填入虛構的 setter。
4. **對原始 KR client 的有界觀察：**已知 constructor 與 reset／recycle 內沒有可見 mode0 正向來源；因此預設路徑選特殊封裝是穩健的有界結論。對於必須回傳明文的相容 Server，不能假設 Client 的 mode 必然會自行變 0；Client 端有編碼失敗 fallback 的另一路徑。

## 五、`0x8061A0` 精確 CFG 與封包佇列語意

原生關鍵分支：

```asm
8061E6 mov eax,[esi+0xa074]   ; queue sentinel
8061EC mov ebx,[eax]          ; queue head
8061EE cmp ebx,eax
8061F0 je  8063BA             ; empty: return current status flag
8061F6 mov edi,[ebx+8]        ; payload node
8061F9 mov edx,[edi+4]        ; payload byte length n
806202 movsx eax,BYTE [esi+0xa02c]
806209 sub eax,0
806218 je  80622F             ; zero -> plain first
80621E push edx
806223 call 807830            ; 0BBB encoder
806228 test eax,eax
80622A jne 80624F             ; encoded success -> remove node
80622F ...                   ; fallback / mode==0
80623A call 807A70            ; 1A68 encoder
80623F test eax,eax
806246 je 8063A4              ; both failed -> leave node
80624F ...                   ; success: unlink node
80626A call 89120C           ; release list node
806275 dec [esi+0xa078]      ; queue count
8062B9 mov [edi],0
8062BF mov [edi+4],0
806341 mov [global free payload slot],edi
80636C ...                   ; next node
8063A4 cmp [esi+0xa0b4],1
8063AD cmp [ebp-0x18],0      ; whether earlier queued payload succeeded
8063B3 mov [ebp-0x1c],0      ; only no earlier progress + mode state1
8063C7 mov eax,[ebp-0x1c]    ; return flag
```

- 不是把任何失敗的 `0x0BBB` frame 改寫成已成功送出的 `0x1A68`；只有第二個 encoder return 1 後才從 queue 移除。
- **無論哪個 encoder 成功**，原文 packet payload/node 會回收，Tx 緩衝區內僅有已封裝的 frame bytes；之後 WSASend 是另一階段。
- 兩種 encoder 失敗時，隊列首節點保留，以供之後的 pump 判斷；不能說它已經被丟棄。
- 返回值不是純粹的「本次 packet encode success」：有 `A0B4`、累積成功旗標 `ebp-18` 的額外條件。若先前有節點成功，即使後一節點失敗也可能保留成功狀態；須結合 `804A40/8051E0` 呼叫者處理。
- 上層 `804AD6` 與 `805228` 的 pump 都用 return flag 更新暫時的失敗/流量追蹤欄位，隨後依 `[Conn+A028]` 與在途 SEND 計數決定是否 `WSASend`；不可把 `8061A0 ret1` 簡化為 wire 成功。

## 六、兩 encoder 的實際失敗條件與可達 fallback

### 6.1 `0x807830`：特殊格式先行

`ECX=Conn+0x501C`，函式內 `ESI` 是 Tx 子物件，不是根 Conn；`ESI+0x5004` 對應 `Conn+A020`、`ESI+0x500C` 對應 `Conn+A028`。入參是 payload 指標、DWORD 長度 `n`。先讀鎖/EnterCriticalSection，然後檢查：

- `n+6 <= 0x1000` 且 `n!=0`（`80786D..807894`）
- `used+n+6 <= 0x4000`（`80789A..8078B6`）
- 目的 start、目的 end 必須位於 `TxBufferBase <= ptr < TxBufferEnd`；原碼比較對 `>= upper bound` 走 fail（`8078D3..8078ED`）
- 以上通過才執行逐 byte XOR/累積 checksum、寫 6B header，拷貝 n bytes 並 `Conn+A028 += n+6`、cursor `+n+6`，最後 return1。

### 6.2 `0x807A70`：直接或 fallback 的明文格式

`EDI=Conn+0x501C`，資料來源與入參相同；檢查 `n+4 <= 0x1000` 且 `n!=0`、`used+n+4 <= 0x4000`、目的 start/end 必須在合法 buffer 內。成功寫 `WORD length, WORD 0x1A68` + n bytes 原文後回傳1。這條路不做 XOR/checksum，不是 0x0BBB 轉成明文再回退原先 header；**它是重新建構 1A68 frame**。

### 6.3 簡化模型（限定正常 initialized buffer、無記憶體損毀／並發修改）

```cpp
bool encode(Conn& conn, const uint8_t* p, size_t n) {
    if (conn.mode_A02C != 0 && try_append_0BBB(conn.tx, p, n)) return true;
    return try_append_1A68(conn.tx, p, n);
}
// try_append_X 成功也只代表 append 到 Conn Tx buffer；不是 WSASend complete。
```

這不是所有 `mode` 不同數值的獨立演算法；`80621A..80621E` 雖有 `dec`，但沒有對非零 1/2 設置不同 handler。

### 6.4 synthetic guard truth table（**不是遊戲 runtime 或 Server 封包**）

給定正常 cursor（`TxUsed` bytes）和有效 Tx pointer，`TxUsed + encoded_length <= 16384` 才能通過累積 byte cap；另有獨立的 0x5000 (20480) bytes Tx 物理指標上界（必須嚴格小於 bufferEnd）。這個小模型刻意不模擬 allocator、CRC 或 OS。`NONE` 表示兩函式都因純數量 guard 不會產生 frame。

| payload n | TxUsed | A02C | 可通過的格式（合成推導） |
|---:|---:|---:|---|

| 0 | 0 | 2 | NONE |
| 1 | 0 | 2 | 0BBB |
| 57 | 0 | 2 | 0BBB |
| 4090 | 0 | 2 | 0BBB |
| 4091 | 0 | 2 | 1A68 |
| 4092 | 0 | 2 | 1A68 |
| 4093 | 0 | 2 | NONE |
| 4096 | 0 | 2 | NONE |
| 1 | 16376 | 2 | 0BBB |
| 1 | 16377 | 2 | 0BBB |
| 1 | 16378 | 2 | 1A68 |
| 1 | 16379 | 2 | 1A68 |
| 1 | 16380 | 2 | NONE |
| 57 | 0 | 0 | 1A68 |
| 4092 | 0 | 0 | 1A68 |
| 4093 | 0 | 0 | NONE |

**邊界解釋：**`n=4090` 使用 `0BBB` 時 n+6=4096 可通過單 frame limit；`n=4091/4092` 的 `0BBB` 必然因 +6 超限，但 `1A68` 在空 Tx 可以通過 (+4)；`n=4093..4096` 則連明文單 frame limit 都過不了。`TxUsed` 接近 16384 的條件也可能造成「6B header 不夠、4B header 可以」的狹窄窗口；**累積 cap 16384 是 inclusive (`jbe`)，而 pointer buffer 的獨立嚴格上界在 20480**；在正常 cursor 與 cap 下不能把兩者混為一個上界。`n=0` 無論模式都失敗。

`0x8060D0` 對 `n<=0x1000` 確有本地 queue memcpy，所以 4091/4092 **是可送入封裝器的合成長度**；不宣稱 KR 原版遊戲正常業務 packet producer 一定會產出此長度、也不宣稱當時 TxUsed 必為0。

## 七、可反證的四條實際處理情境

**情境 A（fresh Conn，典型小封包）：** constructor mode=2、`n=57`、Tx empty、兩 encoder buffer 合法，`8061A0→807830` 可建立 63B 的 0BBB frame，且在單次處理中從 queue 移除該 node。最終送到網路仍受 pump/WSASend/IOCP 條件控制。

**情境 B（mode0，若外部 alias 寫0）：** `806202` 為0則跳過 807830，直接呼叫 `807A70`。雖有明確 CFG，**尚未發現本版 Client 能使 mode=0 的正向 writer**。因此不能宣稱模式自動切換發生過。

**情境 C（mode!=0，長度在兩 header 可區分區間）：** `n=4091/4092`、Tx empty，0BBB 由 n+6 guard return0；plain n+4 gate 可通過，於是 fallback 可以建 1A68 frame。這是基於本地 queue/encoder API 的**靜態可達輸入案例**，不等於曾在官方 Server 上觀察。

**情境 D（全部編碼失敗）：** `n=0` 或 `n>=4093`（合法 queue 內可有這類值）使兩個 encoder guard 均 fail；`806246→8063A4` 不經成功 unlink/free。若 `A0B4==1` 且此前無成功，drain return0；否則可能仍 return1。上層記錄失敗/後續重試/關閉是條件式流程，不可把此分支等同已送包或封包自動丟棄。

### 接收端依 marker 而不是本地 mode 選擇

`807B40` 在收到足夠 data 後以 frame[2:4] 選路：`0x2633` header8、`0x0BBB` header6、`0x1A68/0x22D7` header4；0BBB 收到後另解碼並比 checksum。這份視窗中的解析分支**沒有**以 `Conn+A02C` 決定只接受哪種 Server frame。故不能由 fresh Conn mode2 認定 Server 首包一定是 0BBB。

## 八、與 RR-0001／RR-0005 的接口、Server 相容性／驗收需求

| 類別 | Client 目前有界結論 | 仍未知／不應升格 |
|---|---|---|
| Client 已確認 | 新 Conn A02C=2；非零先 0BBB；mode0 或 encoder failure 試 1A68；兩 encoder 各自有界且可能 fail | `mode` 第三種特殊演算法未發現；不能發明 |
| Client 已確認 | 佇列 drain 成功才移除節點；send pump 再考慮 Tx 的累積 bytes 並呼叫 WSASend | 不能將 local encode/enqueue 視為已發往原版 Server |
| Client 已確認 | Rx `807B40` 照 inbound marker 分支，至少靜態具備處理 0BBB/1A68 的控制路徑 | Server 實際採用哪一種 marker 無官方 capture |
| Client 待逆向 | 間接 alias 及整物件 writes 尚無有證據的 setter；已提供所有直接位移搜尋與相關狀態的負證 | 不能因找不到而聲稱全程沒有任何覆寫 |
| 跨 Task 待整合 | RR-0001 `E57` 初始 C2S queue 候選和本段 encoding 有條件接合；RR-0005 `E56` key0/key1/key2 的建立條件 | RR-0001/0005 的已提交成果由 T01/S00 決定證據採納 |
| Server 待開發 | 正確辨識從 Client 送來的 0BBB/1A68 外殼；對 0BBB 檢查 checksum/逆 XOR；管理 session 協定狀態 | 不得自行宣稱原版 Server 的首個回覆／部署 endpoint／錯誤策略 |
| 待遊玩驗證 | 可對自建 mock Server 實測連線、0BBB/1A68 邊界、不同 payload 尺寸 | 自建 mock 的 Server 回覆不能當原版官方回答 |

- **GAP-NET-0001**：提供可作 DRAFT 的本地 mode／fallback 條件和明確的 alias 負證範圍；交 S00 確認能否滿足 RR-0004 的限定驗收；任何嚴格 SPEC MUST 或 NATIVE_VERIFIED 由 T01/S00 再審，不由本稿自行授權。
- 若 S00 要求「證明模式 0 在玩家操作中必然可達」，**當前靜態證據不支持**；需要可定位的 indirect setter、合法目標 trace 或其他第一手來源。這是具體未解條件，不把它包裝成已證明。

## 九、反例、修正與證據完整性

1. 不能只因 `807830` 有 `ret 0`，就說每次 0BBB 編碼失敗會發出 1A68：次級 encoder 仍可能失敗。
2. 不能因 Pool reuse reset 不寫 A02C，就說 reuse 一定改成 mode0；**沒有重設**與**自動歸零**是相反的事。
3. 不能把 Tx `A028` 誤當 A02C，或把 `Conn+A080 lane==2` 當 A02C mode2。
4. 不能把本地 outgoing A02C mode 與 inbound `807B40` 的 marker gate 混為同一狀態。
5. 對 `.text` direct displacement 沒其他命中，**不等於** C++ pointer alias 或由系統 bug 造成的任意記憶體修改全域不可達；本報告明示搜尋種類。
6. header 的附加 4/6 bytes 不能和 UI 的 57B 本地命令 payload 長度混算。
7. 所有表格邊界數字是原生 guard + 合成 input 推導，不是抓到的真實玩家封包；可驗證測試應獨立寫 synthetic fixture。

## 十、可重現檢查程序

```bash
sha256sum Tartaros.bin
# expected: 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
# Verified: section bytes raw[0x400:0x400+0x7D01F0] match text.bin.
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x805ca0 --stop-address=0x806050 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x8061a0 --stop-address=0x8063e0 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x807830 --stop-address=0x807b40 text.bin
```

**本次分析未啟動或修改原版 Client，沒有連線、執行階段網路封包、原版 Server 私有程式碼、未經審查的官方語義。**

## 十一、T01/S00 審查工作單

1. T01 核對 mode constructor/reuse、two encoders guards、queue-drain failure branch、strict pointer end boundary、出站/入站 mode 界線與 `.text` direct xref methodology。
2. S00 依 RR4 acceptance criteria 決定 bounded submission 是否足夠；若要更高的 alias 全域證明，提出精確的未知寫入形態或必要全域規範條款，不能要求憑空創造 mode0 writer。
3. SPEC 只採用有證據的相容格式與條件；Server 自訂 policy 獨立列 ADR。保留 RR1/RR5 來源與 Git blob，不自動更新他們原稿。
4. T01 FULL-PASS、RR4 S00 ACCEPTED、SPEC STABLE 和遊玩驗收是不同門檻，需由對應審查者決定。

## 附錄 A — 原始 BIN 對應段落（不同函式，完整局部 disassembly）

以下附錄依函式正確入口反組譯，不以整段任意位置解碼。為便於查找保留原始 machine bytes 與 register addressing，所有 VA/raw 都按本版 `.text` 映射。

### Pool 預熱 Conn+mode constructor caller — VA `0x00805750..0x008057B0`；`.text` raw `0x00404B50..0x00404BB0`

```asm

00805750 <.data+0x404750>:
  805750:	15 4c 22 bd 00       	adc    eax,0xbd224c
  805755:	33 f6                	xor    esi,esi
  805757:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  80575a:	eb 06                	jmp    0x805762
  80575c:	8d 64 24 00          	lea    esp,[esp+0x0]
  805760:	33 f6                	xor    esi,esi
  805762:	68 d8 a0 00 00       	push   0xa0d8
  805767:	e8 fc ba 08 00       	call   0x891268
  80576c:	83 c4 04             	add    esp,0x4
  80576f:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805772:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805775:	3b c6                	cmp    eax,esi
  805777:	74 0d                	je     0x805786
  805779:	50                   	push   eax
  80577a:	e8 21 05 00 00       	call   0x805ca0
  80577f:	8b d0                	mov    edx,eax
  805781:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  805784:	eb 05                	jmp    0x80578b
  805786:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  805789:	8b d6                	mov    edx,esi
  80578b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805792:	8b 43 38             	mov    eax,DWORD PTR [ebx+0x38]
  805795:	89 82 c8 a0 00 00    	mov    DWORD PTR [edx+0xa0c8],eax
  80579b:	8b 4b 3c             	mov    ecx,DWORD PTR [ebx+0x3c]
  80579e:	89 8a cc a0 00 00    	mov    DWORD PTR [edx+0xa0cc],ecx
  8057a4:	8b 43 40             	mov    eax,DWORD PTR [ebx+0x40]
  8057a7:	8d 7b 10             	lea    edi,[ebx+0x10]
  8057aa:	89 82 d0 a0 00 00    	mov    DWORD PTR [edx+0xa0d0],eax
```

### Pool reused/new branch — VA `0x00805950..0x00805A50`；`.text` raw `0x00404D50..0x00404E50`

```asm

00805950 <.data+0x404950>:
  805950:	55                   	push   ebp
  805951:	8b ec                	mov    ebp,esp
  805953:	6a ff                	push   0xffffffff
  805955:	68 2b 5a 91 00       	push   0x915a2b
  80595a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805960:	50                   	push   eax
  805961:	83 ec 0c             	sub    esp,0xc
  805964:	53                   	push   ebx
  805965:	56                   	push   esi
  805966:	57                   	push   edi
  805967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80596c:	33 c5                	xor    eax,ebp
  80596e:	50                   	push   eax
  80596f:	8d 45 f4             	lea    eax,[ebp-0xc]
  805972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805978:	8b f9                	mov    edi,ecx
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  805a01:	74 5b                	je     0x805a5e
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb        	call   0x7bb350
```

### Conn constructor — VA `0x00805CA0..0x00805E42`；`.text` raw `0x004050A0..0x00405242`

```asm

00805ca0 <.data+0x404ca0>:
  805ca0:	55                   	push   ebp
  805ca1:	8b ec                	mov    ebp,esp
  805ca3:	6a ff                	push   0xffffffff
  805ca5:	68 dc 99 90 00       	push   0x9099dc
  805caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805cb0:	50                   	push   eax
  805cb1:	83 ec 10             	sub    esp,0x10
  805cb4:	53                   	push   ebx
  805cb5:	56                   	push   esi
  805cb6:	57                   	push   edi
  805cb7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805cbc:	33 c5                	xor    eax,ebp
  805cbe:	50                   	push   eax
  805cbf:	8d 45 f4             	lea    eax,[ebp-0xc]
  805cc2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805cc8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805ccb:	8d 46 18             	lea    eax,[esi+0x18]
  805cce:	6a 18                	push   0x18
  805cd0:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805cd6:	e8 8d b5 08 00       	call   0x891268
  805cdb:	8b f8                	mov    edi,eax
  805cdd:	33 db                	xor    ebx,ebx
  805cdf:	83 c4 04             	add    esp,0x4
  805ce2:	3b fb                	cmp    edi,ebx
  805ce4:	74 0e                	je     0x805cf4
  805ce6:	68 a0 0f 00 00       	push   0xfa0
  805ceb:	57                   	push   edi
  805cec:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805cf2:	eb 02                	jmp    0x805cf6
  805cf4:	33 ff                	xor    edi,edi
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
  805d24:	33 c0                	xor    eax,eax
  805d26:	89 86 30 a0 00 00    	mov    DWORD PTR [esi+0xa030],eax
  805d2c:	89 86 34 a0 00 00    	mov    DWORD PTR [esi+0xa034],eax
  805d32:	89 86 38 a0 00 00    	mov    DWORD PTR [esi+0xa038],eax
  805d38:	89 86 3c a0 00 00    	mov    DWORD PTR [esi+0xa03c],eax
  805d3e:	89 86 40 a0 00 00    	mov    DWORD PTR [esi+0xa040],eax
  805d44:	89 9e 48 a0 00 00    	mov    DWORD PTR [esi+0xa048],ebx
  805d4a:	89 9e 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],ebx
  805d50:	89 86 50 a0 00 00    	mov    DWORD PTR [esi+0xa050],eax
  805d56:	89 86 54 a0 00 00    	mov    DWORD PTR [esi+0xa054],eax
  805d5c:	89 86 58 a0 00 00    	mov    DWORD PTR [esi+0xa058],eax
  805d62:	89 86 5c a0 00 00    	mov    DWORD PTR [esi+0xa05c],eax
  805d68:	89 86 60 a0 00 00    	mov    DWORD PTR [esi+0xa060],eax
  805d6e:	89 9e 68 a0 00 00    	mov    DWORD PTR [esi+0xa068],ebx
  805d74:	6a 0c                	push   0xc
  805d76:	89 9e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ebx
  805d7c:	e8 e7 b4 08 00       	call   0x891268
  805d81:	83 c4 04             	add    esp,0x4
  805d84:	3b c3                	cmp    eax,ebx
  805d86:	0f 84 b6 00 00 00    	je     0x805e42
  805d8c:	89 86 74 a0 00 00    	mov    DWORD PTR [esi+0xa074],eax
  805d92:	89 00                	mov    DWORD PTR [eax],eax
  805d94:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805d9a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  805d9d:	33 c0                	xor    eax,eax
  805d9f:	b9 01 00 00 00       	mov    ecx,0x1
  805da4:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  805da7:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805dad:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805db3:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805db9:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805dbf:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805dc5:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805dcb:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805dd1:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805dd7:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805ddd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  805de3:	89 8e b4 a0 00 00    	mov    DWORD PTR [esi+0xa0b4],ecx
  805de9:	89 9e b8 a0 00 00    	mov    DWORD PTR [esi+0xa0b8],ebx
  805def:	6a 18                	push   0x18
  805df1:	89 9e bc a0 00 00    	mov    DWORD PTR [esi+0xa0bc],ebx
  805df7:	e8 6c b4 08 00       	call   0x891268
  805dfc:	8b f8                	mov    edi,eax
  805dfe:	83 c4 04             	add    esp,0x4
  805e01:	3b fb                	cmp    edi,ebx
  805e03:	74 0e                	je     0x805e13
  805e05:	68 a0 0f 00 00       	push   0xfa0
  805e0a:	57                   	push   edi
  805e0b:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805e11:	eb 02                	jmp    0x805e15
  805e13:	33 ff                	xor    edi,edi
  805e15:	89 be d4 a0 00 00    	mov    DWORD PTR [esi+0xa0d4],edi
  805e1b:	e8 30 01 00 00       	call   0x805f50
  805e20:	89 b6 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],esi
  805e26:	89 b6 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],esi
  805e2c:	8b c6                	mov    eax,esi
  805e2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805e31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805e38:	59                   	pop    ecx
  805e39:	5f                   	pop    edi
  805e3a:	5e                   	pop    esi
  805e3b:	5b                   	pop    ebx
  805e3c:	8b e5                	mov    esp,ebp
  805e3e:	5d                   	pop    ebp
  805e3f:	c2 04 00             	ret    0x4
```

### Conn reset + close-invalid — VA `0x00805F50..0x00806050`；`.text` raw `0x00405350..0x00405450`

```asm

00805f50 <.data+0x404f50>:
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00 
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  80602e:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  806034:	89 86 c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],eax
  80603a:	89 86 cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],eax
  806040:	89 86 d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],eax
  806046:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80604d:	00 00 00 
```

### 公共入隊和 payload 4096 guard — VA `0x008060D0..0x00806191`；`.text` raw `0x004054D0..0x00405591`

```asm

008060d0 <.data+0x4050d0>:
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2 08 00             	ret    0x8
```

### 佇列 drain、mode 選擇及雙 encoder fallback — VA `0x008061A0..0x008063DE`；`.text` raw `0x004055A0..0x004057DE`

```asm

008061a0 <.data+0x4051a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
  80627b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806282:	8b d9                	mov    ebx,ecx
  806284:	75 27                	jne    0x8062ad
  806286:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80628d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806294:	e8 87 0e 00 00       	call   0x807120
  806299:	68 90 0b bd 00       	push   0xbd0b90
  80629e:	e8 77 c0 08 00       	call   0x89231a
  8062a3:	83 c4 04             	add    esp,0x4
  8062a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  8063d4:	59                   	pop    ecx
  8063d5:	5f                   	pop    edi
  8063d6:	5e                   	pop    esi
  8063d7:	5b                   	pop    ebx
  8063d8:	8b e5                	mov    esp,ebp
  8063da:	5d                   	pop    ebp
  8063db:	c2 04 00             	ret    0x4
```

### 0BBB encoder — VA `0x00807830..0x00807A6D`；`.text` raw `0x00406C30..0x00406E6D`

```asm

00807830 <.data+0x406830>:
  807830:	55                   	push   ebp
  807831:	8b ec                	mov    ebp,esp
  807833:	b8 38 10 00 00       	mov    eax,0x1038
  807838:	e8 33 8e 0a 00       	call   0x8b0670
  80783d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807842:	33 c5                	xor    eax,ebp
  807844:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  807847:	53                   	push   ebx
  807848:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80784b:	56                   	push   esi
  80784c:	8b f1                	mov    esi,ecx
  80784e:	8b 06                	mov    eax,DWORD PTR [esi]
  807850:	57                   	push   edi
  807851:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  807854:	50                   	push   eax
  807855:	89 b5 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],esi
  80785b:	89 9d d4 ef ff ff    	mov    DWORD PTR [ebp-0x102c],ebx
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01 00 00 00       	mov    eax,0x1
  807912:	89 95 f8 ef ff ff    	mov    DWORD PTR [ebp-0x1008],edx
  807918:	3b f8                	cmp    edi,eax
  80791a:	0f 86 c9 00 00 00    	jbe    0x8079e9
  807920:	8d 57 ff             	lea    edx,[edi-0x1]
  807923:	83 fa 02             	cmp    edx,0x2
  807926:	0f 8c 8d 00 00 00    	jl     0x8079b9
  80792c:	8d 8d fd ef ff ff    	lea    ecx,[ebp-0x1003]
  807932:	83 c7 fd             	add    edi,0xfffffffd
  807935:	8b d3                	mov    edx,ebx
  807937:	2b d1                	sub    edx,ecx
  807939:	8d b5 fc ef ff ff    	lea    esi,[ebp-0x1004]
  80793f:	2b cb                	sub    ecx,ebx
  807941:	2b f3                	sub    esi,ebx
  807943:	d1 ef                	shr    edi,1
  807945:	47                   	inc    edi
  807946:	89 8d d0 ef ff ff    	mov    DWORD PTR [ebp-0x1030],ecx
  80794c:	8d 4c 3f 01          	lea    ecx,[edi+edi*1+0x1]
  807950:	8d 43 01             	lea    eax,[ebx+0x1]
  807953:	89 b5 c8 ef ff ff    	mov    DWORD PTR [ebp-0x1038],esi
  807959:	89 8d e0 ef ff ff    	mov    DWORD PTR [ebp-0x1020],ecx
  80795f:	eb 06                	jmp    0x807967
  807961:	8b b5 c8 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1038]
  807967:	8a 08                	mov    cl,BYTE PTR [eax]
  807969:	03 f0                	add    esi,eax
  80796b:	0f b6 1c 16          	movzx  ebx,BYTE PTR [esi+edx*1]
  80796f:	32 d9                	xor    bl,cl
  807971:	0f b6 c9             	movzx  ecx,cl
  807974:	66 01 8d ec ef ff ff 	add    WORD PTR [ebp-0x1014],cx
  80797b:	8a 48 01             	mov    cl,BYTE PTR [eax+0x1]
  80797e:	88 1e                	mov    BYTE PTR [esi],bl
  807980:	0f b6 18             	movzx  ebx,BYTE PTR [eax]
  807983:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  807989:	32 d9                	xor    bl,cl
  80798b:	0f b6 c9             	movzx  ecx,cl
  80798e:	66 01 8d f4 ef ff ff 	add    WORD PTR [ebp-0x100c],cx
  807995:	88 1c 06             	mov    BYTE PTR [esi+eax*1],bl
  807998:	83 c0 02             	add    eax,0x2
  80799b:	4f                   	dec    edi
  80799c:	75 c3                	jne    0x807961
  80799e:	8b 85 e0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1020]
  8079a4:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8079a7:	8b b5 cc ef ff ff    	mov    esi,DWORD PTR [ebp-0x1034]
  8079ad:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  8079b3:	8b 8d dc ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1024]
  8079b9:	3b c7                	cmp    eax,edi
  8079bb:	73 1a                	jae    0x8079d7
  8079bd:	8a 14 03             	mov    dl,BYTE PTR [ebx+eax*1]
  8079c0:	8a 5c 03 ff          	mov    bl,BYTE PTR [ebx+eax*1-0x1]
  8079c4:	32 da                	xor    bl,dl
  8079c6:	0f b6 d2             	movzx  edx,dl
  8079c9:	66 01 95 f8 ef ff ff 	add    WORD PTR [ebp-0x1008],dx
  8079d0:	88 9c 05 fc ef ff ff 	mov    BYTE PTR [ebp+eax*1-0x1004],bl
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2 08 00             	ret    0x8
  807a4d:	8b 8d f0 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1010]
  807a53:	51                   	push   ecx
  807a54:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a5a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a5d:	5f                   	pop    edi
  807a5e:	5e                   	pop    esi
  807a5f:	33 cd                	xor    ecx,ebp
  807a61:	33 c0                	xor    eax,eax
  807a63:	5b                   	pop    ebx
  807a64:	e8 98 95 08 00       	call   0x891001
  807a69:	8b e5                	mov    esp,ebp
  807a6b:	5d                   	pop    ebp
  807a6c:	c2               	ret    0x8
```

### 1A68 encoder — VA `0x00807A70..0x00807B3E`；`.text` raw `0x00406E70..0x00406F3E`

```asm

00807a70 <.data+0x406a70>:
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
  807b19:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  807b1c:	52                   	push   edx
  807b1d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b23:	5e                   	pop    esi
  807b24:	33 c0                	xor    eax,eax
  807b26:	5b                   	pop    ebx
  807b27:	8b e5                	mov    esp,ebp
  807b29:	5d                   	pop    ebp
  807b2a:	c2 08 00             	ret    0x8
  807b2d:	56                   	push   esi
  807b2e:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b34:	5e                   	pop    esi
  807b35:	33 c0                	xor    eax,eax
  807b37:	5b                   	pop    ebx
  807b38:	8b e5                	mov    esp,ebp
  807b3a:	5d                   	pop    ebp
  807b3b:	c2 08 00             	ret    0x8
```

### Send pump caller0 — VA `0x00804AC3..0x00804B10`；`.text` raw `0x00403EC3..0x00403F10`

```asm

00804ac3 <.data+0x403ac3>:
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84       	add    DWORD PTR [esi+0xa084],ebx
```

### Send pump caller1 — VA `0x00805210..0x0080526D`；`.text` raw `0x00404610..0x0040466D`

```asm

00805210 <.data+0x404210>:
  805210:	eb 03                	jmp    0x805215
  805212:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805215:	8b 09                	mov    ecx,DWORD PTR [ecx]
  805217:	8b 34 b9             	mov    esi,DWORD PTR [ecx+edi*4]
  80521a:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  805221:	0f 84 85 01 00 00    	je     0x8053ac
  805227:	56                   	push   esi
  805228:	e8 73 0f 00 00       	call   0x8061a0
  80522d:	85 c0                	test   eax,eax
  80522f:	74 28                	je     0x805259
  805231:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805237:	ff 86 94 a0 00 00    	inc    DWORD PTR [esi+0xa094]
  80523d:	83 f8 05             	cmp    eax,0x5
  805240:	73 0c                	jae    0x80524e
  805242:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  805249:	00 00 00 
  80524c:	eb 1e                	jmp    0x80526c
  80524e:	83 c0 fb             	add    eax,0xfffffffb
  805251:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  805257:	eb 13                	jmp    0x80526c
  805259:	80 7b 10 00          	cmp    BYTE PTR [ebx+0x10],0x0
  80525d:	74 0d                	je     0x80526c
  80525f:	ff 86 84 a0 00 00    	inc    DWORD PTR [esi+0xa084]
  805265:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  80526c:	c7       	mov    DWORD PTR [ebp-0xc],0x0
```

### Rx frame marker 選路 — VA `0x00807B9A..0x00807C44`；`.text` raw `0x00406F9A..0x00407044`

```asm

00807b9a <.data+0x406b9a>:
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```

### Rx 0BBB 校驗 / 解碼 — VA `0x00807D1E..0x00807D7A`；`.text` raw `0x0040711E..0x0040717A`

```asm

00807d1e <.data+0x406d1e>:
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
  807d2c:	83 7c 24 1c 00       	cmp    DWORD PTR [esp+0x1c],0x0
  807d31:	74 44                	je     0x807d77
  807d33:	8a 07                	mov    al,BYTE PTR [edi]
  807d35:	34 b6                	xor    al,0xb6
  807d37:	0f b6 c8             	movzx  ecx,al
  807d3a:	8b d1                	mov    edx,ecx
  807d3c:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  807d40:	ba 01 00 00 00       	mov    edx,0x1
  807d45:	88 44 24 2c          	mov    BYTE PTR [esp+0x2c],al
  807d49:	3b f2                	cmp    esi,edx
  807d4b:	76 19                	jbe    0x807d66
  807d4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  807d50:	8a 04 3a             	mov    al,BYTE PTR [edx+edi*1]
  807d53:	32 44 14 2b          	xor    al,BYTE PTR [esp+edx*1+0x2b]
  807d57:	42                   	inc    edx
  807d58:	88 44 14 2b          	mov    BYTE PTR [esp+edx*1+0x2b],al
  807d5c:	0f b6 c0             	movzx  eax,al
  807d5f:	66 03 c8             	add    cx,ax
  807d62:	3b d6                	cmp    edx,esi
  807d64:	72 ea                	jb     0x807d50
  807d66:	66 39 4b 04          	cmp    WORD PTR [ebx+0x4],cx
  807d6a:	75 13                	jne    0x807d7f
  807d6c:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d70:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  807d74:	51                   	push   ecx
  807d75:	eb 03                	jmp    0x807d7a
  807d77:	57                   	push   edi
  807d78:	8b f8                	mov    edi,eax
```

## 附錄 B — 合成 guard 測試碼（無網路／無官方資料）

```python
def choose_frame(payload_len: int, used: int, mode: int) -> str:
    # Assumes normal, internally consistent Tx cursor and length.
    can_obbb = bool(mode != 0 and payload_len > 0 and
                    payload_len + 6 <= 4096 and
                    used + payload_len + 6 <= 16384)
    can_plain = bool(payload_len > 0 and
                     payload_len + 4 <= 4096 and
                     used + payload_len + 4 <= 16384)
    if can_obbb: return "0BBB"
    if can_plain: return "1A68"
    return "NONE"
assert choose_frame(57,0,2)=="0BBB"
assert choose_frame(4091,0,2)=="1A68"
assert choose_frame(4092,0,2)=="1A68"
assert choose_frame(4093,0,2)=="NONE"
assert choose_frame(57,0,0)=="1A68"
assert choose_frame(1,16378,2)=="1A68"
assert choose_frame(1,16379,2)=="1A68"
assert choose_frame(1,16380,2)=="NONE"
```

此測試證明**人工抽象化的長度 gate**符合本文矩陣；不能取代原生指令審核或實際 Client/Server 行為驗證。
