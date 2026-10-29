# T03-19 — KR 接收 worker 的父物件來源與初始化寫入邊界（BIN-first 三輪複核）

- 作者：chatgpt-web roy；日期：2026-10-29 Asia/Taipei；研究標記：T03-19。
- 唯讀原件：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新執行 `sha256sum` 驗證。
- GNU `objdump -h`：`.text` VMA `0x401000`、raw `0x400`，故文中 VA 的 `.text` raw offset = VA − `0x400C00`；`.rdata` VMA `0xBD2000`、raw `0x7D0600`；`.data` VMA `0xD61000`、raw `0x95E800`。
- 根據 GitHub `t03/roy/chatgpt-web` 的 T03-9～18 原稿及 `03-PROJECT-T03-INSTRUCTIONS.md` 定位，所有新判斷以本輪直接讀取 BIN 的 assembly 為準。原件未執行、patch 或上傳。
- 開始核對 GitHub `main...t03/roy/chatgpt-web`：`status=ahead, behind_by=0`；無新主線須合併。共用 FULL-PASS 目前不能替代本題完整驗證。

## 研究結論（有界）

1. 從 `0x48BE50` 的真實入口追到 `0x48C0E0`：該函式的 `EBX` 由 `[EBP+8]` 取得，`LEA EDI,[EBX+0x140]` 後呼叫 `0x804650`；它是**對已持有父物件的內部區域初始化**，不是在此建立父物件的證據。
2. 完整核對 `0x804650`：只看得到 `[EDI+0x8C]`、`[EDI+0x60]`、`[EDI+0x34]` 等寫入與共用傳輸物件配置；`0x8046F7` 寫入 vtable `0xC51748` 的基底是新配置傳輸物件 `ESI`，**不是 `parent+0x140` 的 `EDI`**。在該函式可見路徑內沒有寫入 `DWORD PTR [EDI]` 或可確證的 worker slot0。
3. 新補充：`0x48C105` 取得另一全域物件 `0x44D680`，先檢查其內部物件，再呼叫該物件的 vtable+`0x20`，失敗分支回傳 `0x80004005`。它與 worker vtable+0 是**兩個不同的動態呼叫點**，不能合併成角色結果 callback。
4. `0x49197F` 仍在 T03-18 已辨識的 Print Screen／D3DX 畫面處理路徑中；該處傳入 `0x804740` 的 `parent+0x140` 實際資料應由上游有效物件與控制流保證。尚無證據說這就是選角 S→C 業務 handler。
5. 依此次證據，對應 command `0x42` 的**真實回覆 opcode、成功／拒絕 handler、T05 世界轉場**全部仍屬 Client 待逆向，而非 Server 已證明的結果。

## 第 1 輪 T03-19：父物件指標與初始化上下游

原始 `.text` assembly：

```asm
48be50: 55                    push ebp
48be51: 8b ec                 mov ebp,esp
48be90: 8b 5d 08              mov ebx,DWORD PTR [ebp+0x8]
48c0dd: 83 c4 04              add esp,0x4
48c0e0: 8d bb 40 01 00 00     lea edi,[ebx+0x140]
48c0e6: e8 65 85 37 00        call 0x804650
48c0eb: 6a 34                 push 0x34
```

`0x48BE50` 沒有證據於這個呼叫之前配置 EBX；它使用外部指標。`LEA` 的結果是內嵌區域位置，而不是讀取該處的 vtable。

## 第 2 輪 T03-19-2：共用傳輸物件／worker vtable 排除

```asm
804650: 55                    push ebp
80467b: c7 87 8c 00 00 00 00 00 00 00  mov DWORD PTR [edi+0x8c],0
8046cc: a1 58 a8 fb 00        mov eax,ds:0xfba858
8046d1: 50                    push eax
8046d2: e8 49 10 00 00        call 0x805720
8046d7: 6a 5c                 push 0x5c
8046d9: e8 8a cb 08 00        call 0x891268
8046de: 8b f0                 mov esi,eax
8046ed: 85 f6                 test esi,esi
8046f1: 56                    push esi
8046f2: e8 69 f6 ff ff        call 0x803d60
8046f7: c7 06 48 17 c5 00     mov DWORD PTR [esi],0xc51748
8046fd: 8b ce                 mov ecx,esi
80470a: 8b 11                 mov edx,DWORD PTR [ecx]
80470c: 8b 42 08              mov eax,DWORD PTR [edx+0x8]
80470f: 89 0d 54 a8 fb 00     mov ds:0xfba854,ecx
804715: ff d0                 call eax
80471f: 89 47 60              mov DWORD PTR [edi+0x60],eax
804724: 89 47 34              mov DWORD PTR [edi+0x34],eax
```

`ESI` 由 `0x891268(0x5C)` 建立，`EDI` 來自父物件 `+0x140`。不要把 `0x8046F7` 的 `[ESI]` 寫入作為 `0x80486D` 讀取的 `[EBX]` vtable 來源。`0x804740` 的 `EBX` 來自外部函式參數，並非此傳輸物件。

## 第 3 輪 T03-19-3：另一虛擬介面與失敗路徑

```asm
48c105: e8 76 15 fc ff        call 0x44d680
48c10a: 8b 08                 mov ecx,DWORD PTR [eax]
48c10c: 85 c9                 test ecx,ecx
48c10e: 74 0b                 je 0x48c11b
48c110: 8b 11                 mov edx,DWORD PTR [ecx]
48c112: 8b 42 20              mov eax,DWORD PTR [edx+0x20]
48c115: ff d0                 call eax
48c117: 85 c0                 test eax,eax
48c119: 75 27                 jne 0x48c142
48c13b: b8 05 40 00 80        mov eax,0x80004005
48c142: 33 c0                 xor eax,eax
48c167: c2 04 00              ret 0x4
```

這個 vtable+0x20 作用於 `0x44D680` 回傳之**另一物件**，不可說它呼叫接收 worker 的 vtable+0，亦不可當作原生登入／選角錯誤碼。`0x80004005` 是此函式的一個失敗返回值，不等於 Server 選角拒絕回覆。

接收 worker 真正的 callback 邊界仍為：

```asm
804768: 8b 5d 08              mov ebx,DWORD PTR [ebp+0x8]
804858: 8b 13                 mov edx,DWORD PTR [ebx]
80485a: 8b 12                 mov edx,DWORD PTR [edx]
80486b: 8b cb                 mov ecx,ebx
80486d: ff d2                 call edx
```

透過 `.text` 局部反組譯，於 `0x48BE50..0x48C167` 中未看到對 worker vtable 的直接寫入。**這是限定範圍的否定觀察**：不能延伸推論到其他 constructor、class hierarchy、複製／placement new 或間接呼叫。

## 功能鏈與驗證矩陣

| 玩家情境／資料路徑 | Client gate / 來源 | C→S | S→C | Client 效果 | 狀態 |
|---|---|---|---|---|---|
| 玩家確認可用角色 | T03-3：角色 `+0x5C`、本地送出條件 | `42 00 XX YY` builder；T03-4～6 queue/framing/WinSock 共用鏈 | 未定位原生 reply opcode/handler | 不可斷言成功進世界 | 部分確認 |
| 接收 worker poll | 上層傳入 `worker`，`0x804740` 依 bucket 讀取 | 不適用 | 由共用解框送至 queue，worker vtable+0 具體實作未知 | 有界 worker 迴圈、耗時、回收 | 原生有界 |
| `0x48BE50` 初始化 | 來自 `[EBP+8]` 的父物件 | 無新增業務 C→S | 無新增業務 S→C | 初始化 `parent+0x140` 區域與另一傳輸物件 | 原生已確認（有界） |
| `0x48C10E` 檢查失敗 | 全域另一介面及其 vtable+0x20 | 無新增業務 C→S | 無新增業務 S→C | 返回 HRESULT 型態數值 `0x80004005` | 原生已確認（有界） |

**缺口分類：** Client 待逆向：真正的 `parent+0x140` 所屬父物件 constructor/slot0 writer、業務 S→C 選角結果；Server 待開發：待 Client reply 格式確認再實作相容選角判斷；跨功能待整合：T03→T05 場景；待遊玩驗證：原版 Client 與新 Server 的實際登入選角轉場。

## 三輪門檻與下一段

此段第 1 輪發現 `0x48BE50` 的確切外部指標來源；第 2 輪完成 `0x804650` 的兩物件 vtable non-alias；第 3 輪排除 `0x48C105` 另一個虛擬目標並限定失敗回傳值。**主要未知 vtable+0 未突破；這是有界 provenance／false-positive 排除的研究原稿，不宣稱已找到角色結果 handler。** 下一段應對父物件的分配點、真正 callback 實作與業務 opcode 做跨函式追查，並優先利用 T01 既有索引以避免反覆追共用輸入／圖形路徑。

不修改 `main`、其他 Task 原稿、Owner 或 catalog；本次使用者明確允許將本段原稿提交 T03 分支。