# RR-0004（KR / T02）跨 Task 補驗：A02C alias 與 0BBB→1A68 回退
> 研究者：chatgpt-web roy；日期：2026-11-01 Asia/Taipei；工作分支：`extra/roy2`；補充原稿（**不覆寫 E58**）。

## 0. 來源、目標與狀態

- 第一手：唯讀 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；另核對 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE header `MZ` / `PE\0\0`：ImageBase=0x400000；`.text` RVA=0x1000、VA=0x401000、raw offset=0x400、VirtualSize=0x7D01F0、SizeOfRawData=0x7D0200。以下 .text VA 的 raw offset 為 `VA-0x400C00`。
- 完整既有主稿：`kr-extra-roy/20261030-110906-chatgpt-web-roy-E58-RR0004-A02C-alias-mode-fallback-bounded-BIN-first.md`（main 取得，研究時 RR-0004 台帳為 **IN_REVIEW**）；相關 E57、RR-0001／T01 有界審核仍各自獨立。
- 正式 RR 問題：`Conn+A02C` 初始化與可能 alias writer、`0x8061A0` 的 0BBB 失敗及 plaintext fallback 成立條件。依 `GAP-NET-0001` 不重做已知 WSASend/WSARecv 位址發現。
- **本稿增加的價值**：把已知 Conn 基址、Tx 子物件基址、Rx 緩衝基址三種偏移表示分開；對新增別名候選作 **整節原始 bytes 搜尋 + 指令上下文歸類**，避免把位移 literal 當成真正 writer；另外以 16 個關鍵 native prefix 與 12 個非動態合成邊界向量做可重現回歸。
- **不主張**：全域間接 alias 不存在、某個原版遊戲業務封包實際曾觸發 fallback、原版 Server 第一次回覆外殼、原版可遊玩測試已過、T01 FULL-PASS 或 S00 ACCEPTED。

## 1. Alias 從指標來源換算

`0x805CA0` constructor 以 `ESI = Conn*` 操作：

| 源基址 | 指向 `Conn+A02C` 應使用位移 | .text byte-pattern 搜尋結果 | 人工指令上下文 | 有界結論 |
|---|---:|---|---|---|
| `Conn*` | `+A02C` | operand bytes `0x805D04`、`0x806205` | `805D02 mov BYTE [esi+A02C],2`；`806202 movsx eax,BYTE [esi+A02C]` | 一個直接 writer、一個 reader |
| `Tx = Conn+501C` | `+5010` | 只有 `0x7438C4` | `0x7438C3: b8 10 50 00 00` = `mov eax,0x5010`，是立即數，不是 `[Tx+5010]` | **未找到這種 literal direct Tx alias writer**；不是全域 alias 不存在證明 |
| `Rx = Conn+18` | `+A014` | 只有 `0x7D1913` | `0x7D1910: 8b 8c b7 14 a0 00 00` = `mov ecx,[edi+esi*4+A014]`；周圍 `7D1906` / `7D1922` 使用不同 `+C014` 計數器，未證該 EDI 為 Conn+18 | 只證候選屬索引讀取，**不能冒稱是 KR Conn 的模式 setter** |
| `Tx = Conn+501C` | `+500C` | `0x8077C0, 0x8077CC, 0x80789C, 0x807A21, 0x807AAD, 0x807AFC` | `Tx+500C = Conn+A028`，是 Tx used/計數量，**不是 A02C** | 防止把六個 A028 xref 誤判成模式寫入 |

以上是對 **明確 32-bit literal displacement** 的全節掃描，不能排除基址再加減、16-bit/8-bit offset、指標逃逸、整物件 memcpy、其他 section、執行時 patch 等寫入路徑。搜尋結果是位置而非函式 xref；凡未確認指令起點者不提升為 writer。

### 1.1 原生機器碼比對摘錄

```asm
805CF6 8D 86 20 50 00 00    lea eax,[esi+5020]
805D02 C6 86 2C A0 00 00 02 mov BYTE PTR [esi+A02C],2
805D09 89 86 20 A0 00 00    mov DWORD PTR [esi+A020],eax
805D15 89 9E 28 A0 00 00    mov DWORD PTR [esi+A028],ebx

8059E9 E8 62 05 00 00       call 805F50        ; Pool reuse reset, not ctor
805F79 88 9E 24 A0 00 00    mov BYTE PTR [esi+A024],bl
805F7F 89 9E 28 A0 00 00    mov DWORD PTR [esi+A028],ebx
805F8B 89 86 20 A0 00 00    mov DWORD PTR [esi+A020],eax

806202 0F BE 86 2C A0 00 00 movsx eax,BYTE PTR [esi+A02C]
806218 74 15                je 80622F         ; mode==0 => plain
80621A 48                   dec eax
80621B 74 01                je 80621E
80621D 48                   dec eax
806223 E8 08 16 00 00       call 807830       ; 0BBB
806228 85 C0                test eax,eax
80622A 75 23                jne 80624F        ; succeeded
80623A E8 31 18 00 00       call 807A70       ; 1A68 fallback
806246 0F 84 58 01 00 00    je 8063A4        ; both failed, skip success unlink
80624F 8B 0B                mov ecx,[ebx]      ; success branch
806275 FF 8E 78 A0 00 00    dec DWORD PTR [esi+A078]

7438C3 B8 10 50 00 00       mov eax,0x5010   ; literal, NOT [Tx+5010]
7D1910 8B 8C B7 14 A0 00 00 mov ecx,[edi+esi*4+A014] ; indexed read, not store
```

**指標安全性（有界）**：上述 reset 片段的 DWORD `[A028,A02B]` 不覆蓋 A02C；Tx encoder 並非向 `Conn+A02C` 寫入，除非另有超出這些正常 guard 的 corruption/別名。不能因單個偏移數字相似而合併物件語意。

## 2. 雙 encoder 及佇列分支：原件交叉驗證

`0x8061A0` 從 `Conn+A074` 所在鏈表取 payload node，`[node+8]` 為資料物件，`[payload+4]` 為 n，`payload+8` 為資料指標。傳入 `Tx = Conn+0x501C`，`mode = signed BYTE[Conn+A02C]`：

1. `mode==0`：直接嘗試 `0x807A70`（4B 1A68 header）。
2. `mode!=0`：先嘗試 `0x807830`（6B 0BBB header），**返回失敗**才去 `0x807A70`。中間 `dec` 不形成對 mode 1/2 的不同 callee。
3. `0x807830` 的 `807887 cmp eax,0x1000`、`8078A2 cmp edx,0x4000` 與 pointer 範圍檢查限制 n+6 及 used+n+6。
4. `0x807A70` 的 `807A97 cmp ebx,0x1000`、`807AB3 cmp ecx,0x4000` 與 pointer 範圍檢查限制 n+4 及 used+n+4。
5. 兩個 encoder 都失敗時，`806246 je 8063A4`，本輪略過 **成功路徑** `80624F..` 的 unlink／`A078--`／payload release；`8063A4` 又依 `[Conn+A0B4]==1` 與本輪曾成功的旗標決定返回值，不能把返回值當成一定已送到 socket。

原生簡化 CFG（不是 Server 規格）：

```text
[queue node] → [read A02C]
       ├ mode == 0 ─────────────────────→ [try 1A68]
       └ mode != 0 → [try 0BBB] ─success→ [unlink node]
                            └ failure ─→ [try 1A68]
                                               ├ success → [unlink node]
                                               └ failure → [8063A4 exit flags; node remains]
```

### 2.1 原生 guard 與合成靜態邊界

假設正常初始化、合法 Tx cursor、沒有競態或記憶體損毀時，具體邊界為：

| n / used / mode | 靜態可選結果 | 理由 |
|---|---|---|
| 57 / 0 / 2 | 0BBB | n+6=63；兩個上限均通過 |
| 4090 / 0 / 2 | 0BBB | 4090+6=4096，邊界可包含 |
| 4091 / 0 / 2 | 1A68 | 0BBB n+6=4097 失敗；1A68 n+4=4095 可行 |
| 4092 / 0 / 2 | 1A68 | 0BBB n+6=4098 失敗；1A68 n+4=4096 可行 |
| 4093 / 0 / 2 | NONE | 兩種 header 都超過 4096 |
| 57 / 0 / 0 | 1A68 | mode zero 直接選明文 |
| 1 / 16377 / 2 | 0BBB | 累積 16384 邊界 |
| 1 / 16378 / 2 | 1A68 | 6-byte header 不可；4-byte header 可以 |
| 1 / 16379 / 2 | 1A68 | 明文累積 16384 邊界 |
| 1 / 16380 / 2 | NONE | 兩個都超過累積 16384 |

以上是 **輸入邊界合成模型**，不是觀察到原版 Client 的實際業務封包，也不是網路封包擷取；`0x8060D0` 的 queue n<=4096 接受條件只能證這些長度能進入局部 API，而不是正常玩家流程必然產生這些長度。Tx 的物理合法指標上界與 16384 累積容量上限不同。

## 3. 可重現工具與實際核對結果

本分支配套：`kr-extra-roy/tools/rr4_native_audit.py`。使用 Python 標準函式庫離線讀取用戶自行合法取得的原始 BIN，不執行遊戲，亦不提交 BIN。

```powershell
python -B kr-extra-roy/tools/rr4_native_audit.py "E:\\Tartaros\\Tartaros.bin"
```

2026-11-01 本次已在提供的唯讀原檔執行，結果為 `PASS`：原始 SHA 一致；PE 原始 section 映射一致；4 組 displacement 搜尋集合符合；**16 組 native 指令位元組前綴**符合；**12 組 synthetic guards** 通過。測試不是 T01 FULL-PASS 認證，也不證實間接記憶體寫入不存在。

## 4. 受影響界面／未閉合與驗收建議

| 分類 | 結論／下一步 |
|---|---|
| **已確認 Client 靜態行為** | `A02C=2` ctor；已核 reset 不重設 mode；A02C 直接 setter/reader；非零 0BBB→失敗 1A68；兩次失敗保留本輪 node；接收端依 frame marker parser，不因 A02C 直接決定 S2C marker。 |
| **部分確認／需慎言** | 已檢 literal-displacement alias 及三種基址算術；沒有發現額外模式 writer，**不是 complete points-to/alias proof**；綁定未知的 0 分支在 CFG 上存在，不代表官方正常路徑使用過。 |
| **Client 待逆向** | 若 S00/T01 要求全域 mode0 可達性證明，需對 Conn 指標逃逸、間接寫入者、整物件拷貝、不同 alias base 建立完整可追溯別名圖；目標界線不得以單一 literal 掃描冒充完成。 |
| **Server 待開發** | 相容 Server 應按已知 S2C marker/length 規則解碼；不能假設新 Conn 發送或原版 Server 接收一定只接受 0BBB，也不能由本地 sender mode 推原版 Server 決策。 |
| **跨功能待整合** | `GAP-NET-0001` 的首包/連線順序仍引用 RR-0001、RR-0005 與 T01/S00 已接受的限定結論；本稿不改其他 RR 狀態或其他 Task 原稿。 |
| **待遊玩驗證** | 要證實 mode0 真實寫入或 4091/4092 fallback 實際出現在網路，需同一 KR 版本可靠 runtime trace／capture，連同 Conn lifecycle、payload n、TxUsed、收包 marker、OS send 結果。 |

**提交／審核界線**：這是對 RR-0004 已提交 E58 的增量交叉驗證；正式台帳本次開始為 `IN_REVIEW`（主責 T02），不重新認領、不修改唯一台帳 `research/requests/index.json`、不擅自將 RR 標 `ACCEPTED`。S00 依原 acceptance criteria 判定有限靜態介面是否足夠；若要求消除 alias 全域未知，請下達具體需補的 native 靜態工作。T01 對 `FULL-PASS` 另行嚴格評審。

## 5. 排除與可反證前提

- 若有人指出合法 Conn 指標經 `lea` 導出、別名傳播或非 literal displacement 寫入，應以精確 VA/bytes/callchain 反證本稿的「未發現」；本稿**沒有宣稱全面排除**。
- `0x7438C4` 的 raw bytes 是 `mov eax,0x5010` 的立即數；`0x7D1913` 是索引讀取，不應把四個 bytes 搜尋結果直接轉成 writer。
- 所有 guard 向量假定健康物件；與 wraparound/異步並發/非法 cursor／多執行緒寫入無關；它們不能替代動態真實封包證明。
- 相關原件位址只對上述 KR SHA 有效；不套用至 TC；不執行／patch 遊戲或修改原件。
