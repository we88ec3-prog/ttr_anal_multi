# KR T16-84 — UI 控件樹索引、六筆子控件消費及業務封包證據邊界

- 研究者：chatgpt-web roy。分析時間：2026-10-28 19:57:46 Asia/Taipei。
- 研究標的：**KR T16**，限原版 Client Quest/Story 封包相關線索與本地 UI consumer；不修改其他 Task。
- 原件實際讀取：`/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。靜態唯讀，以 `objdump -D -b pei-i386 -m i386 -M intel` 檢視。
- PE32 .text VA `0x00401000` → raw `0x400`；本段 .text 地址換算 raw=VA−`0x00400C00`。rdata/data 不得跨節套算。
- GitHub 接續基準：`kr/tasks/T16/{README.md,task.json}` 與 `kr-temp-roy/20261028-195212-chatgpt-web-roy-T16-83-KR-event-factory-two-branches-native-validation.md` 均於本次從 `main` 直接讀回。GitHub 前稿及 decompile 僅供導航，新增主張回到 BIN 原始位元組。
- T02/T07/T14/T15 之 owner、catalog、正式規格不變。未執行、hook、patch、附加原始客戶端，沒有原版 Server 原始程式或封包錄製資料。

## 1. T16-84 第一輪：從 T16-83 查找者反向連接實際樹索引

### 1.1 共同 lookup `0x00746940`

本次原生指令表明它以 caller 保留的 `ESI` 為物件，採 `[esi+0x50]` 指向的 sentinel tree 索引，搜尋堆疊傳入的整數鍵。不是 Quest 狀態表，也不是 wire packet decoder。指令（精選，保留原文）：

```asm
746940: push ebp
746943: push ebx
746944: mov ebx,DWORD PTR [ebp+0x8]
746947: push edi
746948: mov edi,DWORD PTR [esi+0x50]
74694b: mov edx,DWORD PTR [edi]
74694d: cmp edx,edi
74694f: je 0x7469ab
746951: mov eax,DWORD PTR [edx+0x10]
746954: push ebx
746955: push eax
746956: mov ecx,esi
746958: call 0x7469c0
74695d: test eax,eax
74695f: jne 0x7469ad
746961: cmp BYTE PTR [edx+0x15],al
746966: mov eax,DWORD PTR [edx+0x8]
746973: cmp BYTE PTR [eax+0x15],0x0
746980: mov edx,eax
746982: mov eax,DWORD PTR [edx]
74698c: mov eax,DWORD PTR [edx+0x4]
7469a7: cmp edx,edi
7469a9: jne 0x746951
7469ab: xor eax,eax
7469ad: pop edi
7469ae: pop ebx
7469af: pop ebp
7469b0: ret 0x4
```

- 原生確認：tree/sentinel 迭代，node 的 `+0x10` 是比較器輸入，`+0x15` 是條件性標記，`0x7469C0` 為共同比較／下游搜尋 helper，找到時返回非零，未找到返回零。
- `[esi+0x50]` 與 `[esi+0x64]` 所在的其他方法不能不核對型別便視為同一容器。
- caller 必須設好 `ESI`：此函式並非傳統完全由 ECX 作為 this 的 ABI。將其誤認一般 STL map::find 然後直接移植 C++ 類別名稱並不安全。
- 精確 5-byte `E8 rel32` 掃描原始 .text，計算候選目標：`0x746940` 287 處、`0x7469C0` 2 處（`0x746958`、`0x7469E7`）。這些是經位址數學篩選的 raw 候選；**只有下面實際 disassembly 的 call 是已確認指令邊界**，不可把全部 287 處視作已驗證呼叫者。

### 1.2 直接 caller，證明為 UI key/type lookup

`0x0045F0C0`：

```asm
45f0d3: push 0x7d0
45f0d8: call 0x746940
45f0df: test esi,esi
45f135: mov edx,DWORD PTR [esi]
45f137: mov eax,DWORD PTR [edx+0x4]
45f13c: call eax
45f13e: cmp eax,0xc8
45f197: mov DWORD PTR [edi],esi
```

`0x00632F30`：

```asm
632f43: push 0x61a8
632f48: call 0x746940
632fa5: mov edx,DWORD PTR [esi]
632fa7: mov eax,DWORD PTR [edx+0x4]
632fac: call eax
632fae: cmp eax,0xc8
633007: mov DWORD PTR [edi],esi
```

這兩者不是直接 producer；key `0x7D0`／`0x61A8` 是本地 lookup key，`0xC8` 是 callback 返回的 runtime type check。查找失敗或類型不符則進入格式化診斷及 `call DWORD PTR [0xBD2580]` 分支；成功寫入 caller 預先設定的 `EDI` 指向輸出槽。不能以該數值認定 Quest ID 或官方 opcode。

## 2. T16-84 第二輪：真正的 UI 綁定上游與消費者

### 2.1 `0x00630D80` 依次綁定 10 個控件指標

原生呼叫者交替使用 `[esi+offset]` 的輸出槽：

| UI key | 目標欄位 | helper | 已知 type gate |
|---|---|---|---|
| `0x7530` | `+0x100` | `0x43C570` | 依 helper，未在此輪逐指令展開 |
| `0x2AF8` | `+0x104` | `0x632E40` | 独立型別驗證 |
| `0x2EE0` | `+0x108` | `0x632E40` | 同上 |
| `0x5208` | `+0x10C` | `0x43C570` | 未在此輪完整覆核 |
| `0x55F0` | `+0x110` | `0x43C570` | 同上 |
| `0x59D8` | `+0x114` | `0x43C570` | 同上 |
| `0x5DC0` | `+0x118` | `0x43C570` | 同上 |
| `0x61A8` | `+0x11C` | **`0x632F30`** | `0xC8` |
| （內部固定鍵，參數待核）| `+0x120` | `0x6355C0` | unknown |
| `0xC350` | `+0x124` | `0x633020` | 見前段限定 |

原生 assembly（節錄）：

```asm
630d84: call 0x755e50
630d89: push 0x7530
630d8e: lea edi,[esi+0x100]
630d96: call 0x43c570
630d9b: push 0x2af8
630da0: lea edi,[esi+0x104]
630da8: call 0x632e40
630dad: push 0x2ee0
630db2: lea edi,[esi+0x108]
630dba: call 0x632e40
630dbf: push 0x5208
630dc4: lea edi,[esi+0x10c]
630dcc: call 0x43c570
630dd1: push 0x55f0
630dd6: lea edi,[esi+0x110]
630dde: call 0x43c570
630de3: push 0x59d8
630de8: lea edi,[esi+0x114]
630df0: call 0x43c570
630df5: push 0x5dc0
630dfa: lea edi,[esi+0x118]
630e02: call 0x43c570
630e0a: lea edi,[esi+0x11c]
630e12: call 0x632f30
630e17: lea edi,[esi+0x120]
630e1f: call 0x6355c0
630e24: lea edi,[esi+0x124]
630e2c: call 0x633020
```

這不是單純一個 RTTI 符號；已從事件分支外延到同一個物件的十個控件槽位。

### 2.2 兩個確定的 `0x632F30` direct caller

依 `E8 rel32` 掃描並由 objdump 覆核：
- `0x630E12`：`lea edi,[esi+0x11C]` → `call 0x632F30`。
- `0x63406B`：`lea edi,[esi+0x110]` → `call 0x632F30`。

**同一 key/type helper 寫到兩種不同 UI 物件佈局**；因此 `+0x11C` 與 `+0x110` 不可只依共用 helper 就視作同一欄位。

`0x632E40` 的已覆核直接 caller `0x630DA8`／`0x630DBA`，分別為 `+0x104` 與 `+0x108`。這些是控件樹查找與暫存，不代表接取封包。

## 3. T16-84 第三輪：下游 consumer `0x00630E40`

與初始化清單銜接的實際 consumer 使用 `this+0x124` 指標：

```asm
630e47: mov edi,ecx
630e49: mov eax,DWORD PTR [edi+0x124]
630e4f: mov eax,DWORD PTR [eax+0xcc]
630e55: test eax,eax
630e59: push 0x6
630e5b: push eax
630e5c: call 0x408920
630e61: xor esi,esi
630e70: mov eax,DWORD PTR [edi+0x124]
630e76: mov eax,DWORD PTR [eax+0xcc]
630e7c: test eax,eax
630e85: mov ecx,DWORD PTR [eax+0xac]
630e8b: sub ecx,DWORD PTR [eax+0xa8]
630e91: sar ecx,0x2
630e98: mov edx,DWORD PTR [eax+0xa8]
630e9e: mov ecx,DWORD PTR [edx+esi*4]
630ea5: mov DWORD PTR [edi+esi*4+0x128],ecx
630eac: mov eax,DWORD PTR [ecx]
630eae: mov edx,DWORD PTR [eax+0x198]
630eb4: push 0xc739
630eb9: call edx
630ebb: inc esi
630ebc: cmp esi,0x6
630ebf: jl 0x630e70
630ec1: mov ecx,DWORD PTR [edi+0x124]
630ec7: mov ebx,DWORD PTR [ecx+0x64]
630eca: mov esi,DWORD PTR [ebx]
630ed3: mov eax,DWORD PTR [esi+0x8]
630ed6: cmp DWORD PTR [eax+0x60],0x0
630ee5: mov ecx,edx
630ee7: mov edx,DWORD PTR [ecx]
630eed: call eax
630ef8: mov edx,DWORD PTR [ecx]
630efa: mov eax,DWORD PTR [edx+0x128]
630f00: call eax
630f02: mov ecx,DWORD PTR [edi+0x104]
630f08: mov BYTE PTR [ecx+0xc9],0x0
```

原生確認：
1. 若 `this+0x124` 控件的 `+0xCC` 非零，以 **6** 和其指標呼叫 `0x408920`；
2. 迴圈 `ESI=0..5` 依 `[list+0xAC]-[list+0xA8]` 的指標跨度（`sar 2`）取子控件，將指標寫到 `this+0x128+4*i`；
3. 每項取出的非空控件其 vtable `+0x198` 由 indirect call 消費一個 `0xC739` 參數；**此為控件 virtual method 的參數，不等同正式網路 opcode**；
4. 之後遍歷 `this+0x124` 控件 `+0x64` 內的鏈表，依節點/物件欄位判斷是否做 vtable `+0x30` 呼叫，最後呼叫控件本體的 vtable `+0x128`，並清 `this+0x104` 指標所指控件的 `+0xC9` 位元組。

**資料流邊界：** 這條 `0x630D80` binding → `0x630E40` consumer 是本輪新閉合的 Client UI 機制，包含已證實的最大六筆子控件儲存與虛呼叫。不代表玩家真的點擊「接受任務」或 UI 內容有六個任務。接收任務 state writer、C→S message builder／WSASend、S→C Quest result handler 均未連到這條鏈。對缺少 runtime 型別與容器不變量的路徑，不由原生靜態節錄推導 UI 必然不會 null dereference。

## 4. 三輪門檻判定及下一段

- **T16-84**：解出通用樹狀 UI key lookup `0x746940` 的 sentinel/比較器與具體 caller，並從 `0x630D80` 得到跨十個控件槽的本地映射；但其時尚未完成下游效果驗證。
- **T16-84-2**：透過 objdump 兩個 direct callers 區分相同 lookup helper 在不同 UI 佈局的 `+0x11C` 和 `+0x110` 輸出，避免跨類別欄位誤合併。
- **T16-84-3**：解析 `0x630E40` 的六筆內嵌指標複製、子控件虛呼叫、額外 tree/list 遍歷及 UI flag 清除；構成具明確上下游的**新完整局部 Client UI 功能鏈**，於第三輪達成門檻。三輪皆實際進行；不宣稱 Quest 業務封包已閉合。

下一正式段號 **T16-85**：優先由 `0x630E40` 的 vtable +0x198 callee 和 `0x408920` 對 `0xC739` 的業務影響界定這些控件的實際 UI 行為；同時必須重新把重心放回 NPC 接任務 request producer／Quest cache receiver。不要只靠本地 UI event ID 猜 opcode。若控制端仍只有裝飾性 UI 行為，應轉由原生 quest state writer 的記憶體 xref 或 T02 packet-dispatch domain 逆追。沒有找到不等於原版不存在。

## 5. 玩家情境／Client-Server 矩陣

| 玩家情境 | Client gate | C→S | S→C | Client 寫入／UI 效果 | 相容 Server 待開發 |
|---|---|---|---|---|---|
| NPC 任務清單 UI 初始化 | key/tree 查找與 runtime type gate（已確認部分） | unknown | unknown | 10 個控件槽回填，後續 6 筆列表子控件處理（本地已確認） | 無從此本地流程直接推定協定 |
| 玩家點擊接取 Quest | 尚無原生 accept handler | unknown | unknown | Quest cache writer unknown | 接取確認/拒絕封包需更多原生證據 |
| Quest 完成並解鎖下一個 | unknown | unknown | unknown | Quest16→Quest15 仍 unknown | Server 判定/DB 非 T16 原生 Client 證據 |
| 教學 RequestStartScenario | 前段 `[FBA798]==0` 限定 | local message tag `0x0040`，實際 wire domain 尚待對照 | unknown | unknown | 待按已確認 wire 格式設計 |

## 6. GitHub 版本管理與資料隔離

本研究僅在 `kr-temp-roy/` 新增完整文字原稿；未改 T02/T07/T14/T15、其他 Task、catalog、owner、遊戲原始 BIN/EXE。此文中列出的 bytes/assembly 屬 KR 原生來源；字義推論與網路業務功能 unknown 均明確分離。
