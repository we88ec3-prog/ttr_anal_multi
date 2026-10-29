# T03-10 — KR 接收 worker 物件歸屬、實際上游呼叫者與 callback 邊界

- 研究者：chatgpt-web roy；日期：2026-10-28 Asia/Taipei。
- BIN-first 原件：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes。只使用離線靜態解碼，未執行、修改或連線。
- PE `.text` VA `0x401000`，raw `0x400`，因此本檔 `.text` 位址換算 `raw=VA-0x400C00`。`.rdata` VA `0xBD2000`、raw `0x7D0600`。
- Git 基準：當段開始 `main=baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，T03 branch 在研究前透過兩父 merge `4f92569d636dcdcd855813c091e4e44c061091e0` 同步。未更動其他 task 原稿。
- 承接 `T03-9`（reader `0x804100` → `0x804740` 內的 worker vtable `+0`，其目標未知）；本輪研究上游擁有者，**不將通用回調當成選角結果 handler**。

## 1. 第 1 輪：重大新增原生鏈——`0x804740` 確有具體上游入口

掃描整個 `.text` 的 `E8 rel32`，以 `call_site_va+5+signed_disp32 == target_va` 為條件，比對固定函式 `0x804740` 與附近工作迴圈。

| 目標 | `.text` 中直接 `E8 rel32` caller | 本段限定意義 |
|---|---|---|
| `0x804740` | **`0x49198A`** | 上游將父物件內部欄位 `+0x140` 的地址作為 worker 指標傳入 |
| `0x804A40` | **`0x491FDD`** | 同一大系統另一條通用 transport poll 呼叫，不能合併為同一 worker callback |
| `0x804650` | **`0x48C0E6`** | 父物件內嵌 `+0x140` 子物件的初始化入口 |
| `0x804100` | `0x804841`, `0x8049B2` | 兩個 reader 直接 call 均在 `0x804740` 所屬函式內 |
| `0x804820` | 無 | **不是函式入口**，而是 `0x804740` 內部基本區塊／指令位址，須避免錯稱其有獨立 caller |

### 1.1 上層 `0x49198A` 實際以嵌入子物件為引數

```asm
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
49198f: f6 05 cc 10 fc 00 01  test BYTE PTR ds:[0xfc10cc],0x1
```

由此在 `0x804740`：`mov ebx,[ebp+8]` 的 EBX，即上層傳入 `&parent[0x140]`；後續 `mov edx,[ebx]; mov edx,[edx]; call edx` 才取得此 worker 子物件的 **vtable slot 0**。這比前段泛稱 `worker` 更精確，但**沒有確定 parent class 名稱，也未確定 vtable 靜態內容**。

### 1.2 同一父物件的子物件初始化由 `0x48C0E6` 實際發生

```asm
48c0e0: 8d bb 40 01 00 00     lea edi,[ebx+0x140]
48c0e6: e8 65 85 37 00        call 0x804650
48c0eb: 6a 34                 push 0x34
```

`0x804650` 使用 EDI 子物件地址進行共用通訊/計時狀態初始化（包括 `+0x8C` 清零、依賴 `FBA854` socket interface），可說明 worker 物件確屬較大的上層 client/session 物件之一部分，且在工作迴圈之前存在獨立初始化入口。**不能從 `0x804650` 直接推斷 vtable+0 目標；在已摘錄的該函式內尚未觀察到 `[edi]` 被寫入 vtable 常數。**

### 1.3 `0x804740` 並非與 `0x804820` 不同函式

```asm
804740: 55                    push ebp
804741: 8b ec                 mov ebp,esp
804768: 8b 5d 08              mov ebx,[ebp+8]
804837: 56                    push esi
804838: 8d 45 f0              lea eax,[ebp-0x10]
80483b: 50                    push eax
80483c: b8 d0 10 fc 00        mov eax,0xfc10d0
804841: e8 ba f8 ff ff        call 0x804100
804846: 84 c0                 test al,al
804848: 0f 84 82 01 00 00     je 0x8049d0
804858: 8b 13                 mov edx,[ebx]
80485a: 8b 12                 mov edx,[edx]
80485f: 8b 46 04              mov eax,[esi+4]
804862: 51                    push ecx
804863: 50                    push eax
804864: 8d 46 08              lea eax,[esi+8]
804867: 50                    push eax
804868: 8b 06                 mov eax,[esi]
80486a: 50                    push eax
80486b: 8b cb                 mov ecx,ebx
80486d: ff d2                 call edx
80487c: 8b 03                 mov eax,[ebx]
80487e: 8b 50 0c              mov edx,[eax+0xc]
804886: ff d2                 call edx
804890: 8b 03                 mov eax,[ebx]
804898: 8b 40 08              mov eax,[eax+0x8]
8048a1: ff d0                 call eax
8049da: 46                    inc esi
8049de: 83 fe 06              cmp esi,0x6
8049e1: 0f 8c 3f fe ff ff     jl 0x804826
804a09: c2 04 00              ret 0x4
```

`ESI` 選槽從 0 迭代，`cmp esi,6` 支持 worker 對 **6 個 selector 值 0..5** 作輪詢（不代表 6 種官方 opcode）。reader 失敗會按程式其他 gate 跳轉，不可推定每次都執行六條 callback；callback 只有 reader 回傳成功才會調用。`+0xC`、`+0x8` 是同 worker vtable 的其他槽位，尚無原生目標地址。

## 2. 第二輪：同上層環境是否也主導 transport 服務

```asm
491fce: e8 ad 4b 06 00        call 0x4f6b80
491fd3: 80 bb 90 00 00 00 00  cmp BYTE PTR [ebx+0x90],0x0
491fda: 75 08                 jne 0x491fe4
491fdc: 53                    push ebx
491fdd: e8 5e 2a 37 00        call 0x804a40
491fe4: 8b f3                 mov esi,ebx
491fe6: e8 85 2c 37 00        call 0x804c70
491feb: 53                    push ebx
491fec: e8 cf 2f 37 00        call 0x804fc0
```

`0x804A40` 擁有 `0x8061A0` send queue drain 等網路 poll（在同函式中可見 `0x804AD6 call 0x8061A0`、`0x804B5A` 的 interface vtable `+0xC`）。因此 **reader worker `0x804740` 與 transport poll `0x804A40` 是上層兩個不同直接呼叫點**，不能憑空把 worker 的 `+0` callback 等同 socket 回包業務分派器。

```asm
804ac3: 8b 16                 mov edx,[esi]
804ac5: 8b 34 82              mov esi,[edx+eax*4]
804ac8: 83 be ac a0 00 00 00  cmp DWORD PTR [esi+0xa0ac],0x0
804ad5: 56                    push esi
804ad6: e8 c5 16 00 00        call 0x8061a0
804b42: 8b 0d 54 a8 fb 00     mov ecx,[0xfba854]
804b48: 8b 11                 mov edx,[ecx]
804b4a: 8b 52 0c              mov edx,[edx+0xc]
804b5a: ff d2                 call edx
```

此結果讓多個 transport-facing loop 可回溯至上層控制，但仍不能證明在同一 schedule 一定發生完整特定 command42→特定 reply 配對。

## 3. 第三輪：vtable 實作缺口的排除驗證

- 本輪直接 `E8 rel32` 掃描結果可以重現 **入口**，但 C++ vtable `+0/+8/+C` 是間接 `call [table]`，不會出現 `E8` 的直接 target 引用；不可將「掃不到直接 caller」轉譯成「未被執行」。
- 掃查上層 `0x48C0E0` 及 initializer `0x804650` 已確定 `&parent[+0x140]` 的地址來源，**未核出 parent constructor 對該子物件 `[0]` vtable 的靜態賦值及具體 vtable table blob**。實際 callback target 保留 unknown。
- 明確否證：`0x804820` 位於 `0x804740` 中間，不能使用 `0x804820` 作函式名或以它尋找建構器；`0x804A40` 的 send queue drain 和 `0x804740` 的 recv worker 不能互相當成對方的實作；`0xFC10D0` 是中繼容器基址而不是選角 wire opcode。
- 三輪均執行；本段重大增量是找到 `reader worker` 的實際上游父物件偏移和兩個獨立循環入口，未取得業務 dispatcher 特定實作。**本段研究完成不等於登入／選角可玩驗收完成。**

## 4. 使用者可驗證的場景／契約矩陣

| 玩家情境 | C→S Native 來源 | S→C decode / staging | 本段下游證據 | 選角結果/UI | 等級 |
|---|---|---|---|---|---|
| 點選確認角色 | T03-3 `0x4A3B80` 產 `42 00 XX YY`，受 UI/connector gates 限制；T03-4～6 共用送出機制 | T03-7 `0x807B40` 解框；T03-8 分 lane | 在 FC10D0 lane 可由 `0x49198A→0x804740→0x804100→vtable+0` 被處理；但**尚無特定 42 回應關聯證據** | 未知 | 部分確認 |
| 通用 transport poll | queue entry/封裝模式待具體條件 | WinSock IO / pending | `0x491FDD→0x804A40→0x8061A0` 共用通道出列；與 worker 分離 | 不能代表 Server 批准 | 原生確認（通用） |
| 任意 FC10D0 reader 無資料 | 不適用 | 中繼容器 | `0x804100` 失敗不呼叫 `vtable+0`；worker 仍進其 loop | 不等於 Server 拒絕 | 原生確認（bounded） |

## 5. 下段 T03-11 優先入口

1. 找到內嵌 `parent+0x140` 的最初 vtable 寫入（可能由更早的 base constructor/複合物件初始化），**先用 raw 指令確認 `[worker+0]` 設定再解 `.rdata` entries**，不可猜 class 或 virtual target。
2. 追 `0x49198A` 的父物件／主事件迴圈與 `0x48C0E6` 的初始化對應性；分清資料消費 worker、socket poll、通知 callback，不泛稱皆為 dispatcher。
3. 一旦找到實際 `vtable+0` target，再追到真正的業務 opcode 判斷及角色選擇回覆；否則保留 S→C opcode/長度、approve/reject、T05 轉場均未確認。
4. 專屬研究提交位置 `kr-temp-roy/`、僅 `t03/roy/chatgpt-web`，不修改主線或 T02/T04/T05/T06 owner/catalog。

## 6. 重現指令

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x491970 --stop-address=0x49199b Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x48c0e0 --stop-address=0x48c0f0 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x804740 --stop-address=0x804a0a Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x491fd0 --stop-address=0x491ff0 Tartaros.bin
```

直接 caller 掃描：解析 `.text` raw `0x400..0x7D0600`，逐 byte 判斷首位元組 `0xE8` 並將 `call_site_va + 5 + int32_le` 與目標函式 VA 比較；這是 **direct E8** coverage，不能推導全部間接 caller。