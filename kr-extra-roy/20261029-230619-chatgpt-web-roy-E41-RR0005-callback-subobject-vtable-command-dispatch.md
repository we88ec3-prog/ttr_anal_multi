# E41 — RR-0005 / KR T02：Client 次級基底位址修正、0x80486D 目標、雙層 command routing 與條件性入站鏈

**研究者**：chatgpt-web roy　**建立時間**：2026-10-29T23:06:19+08:00（Asia/Taipei）  
**正式段號**：E41；同一段內 Round 1–3；**不代表 RR 正式認領、T01 FULL-PASS、S00 接受或遊玩驗收**。  
**原始標的**：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次實讀重算；PE32/i386，靜態分析；無執行、patch、附加、官方 pcap）。  
**Github 首次開工快照**：`main=43c51f579cada3aa6257eb8467f65af281c3585b`（本對話實際核對）、`extra/roy1=34d1a55b21df78ac1c025872e641fe23dfe52645`（本對話實際核對）。僅一回合開工讀取 `AGENTS.md`、KR T02 README/task.json、研究派工規則及 T02 inbox、唯一 RR 台帳、共用 FULL-PASS 索引、E40/E39/E38 原稿。E40 blob `f5e05c25933bb7304f4b72048a0f7151f38bd5b1`。  
**RR-0005 狀態（上述 main 快照）**：KR / owner T02 / P0 / GAP-NET-0002；`status=PENDING`、`dispatch.state=QUEUED`、`claim=null`、`submission=null`。**暫不正式認領；本段不 Commit/Push，不寫 RR 台帳、主線、其他 Task、共用索引。** README 未見 T02 `NEEDS_FIX/FIXING` 退回區塊。共用 FULL-PASS 索引查無直接對應 RR-0005 的閉合原生認證。  
**原稿預定安置位置**：`kr-extra-roy/20261029-230619-chatgpt-web-roy-E41-RR0005-callback-subobject-vtable-command-dispatch.md`（**僅供未來授權提交**；此時是本機可下載 Markdown，沒有遠端 Git blob SHA）。

## 0. Executive finding：這不是相鄰 8 bytes 的矛盾，而是兩種 Client 指標座標

**新證據強度最高的主張**：`0x490FE0` 是完整 Client 物件 `C` 的 **`C+8` 多型次級基底** `vptr C05AA4` 內的 `+0x30` 虛擬方法；其 `0x491020` 從 explicit argument `[ebp+8]` 讀取事件物件指標，`0x491983` 才計算 `arg+0x140`。初始化函式 `0x4A3041..4A305A` 明確使用 `C=&stack[0x2C]`，隨後 `ESI=&stack[0x34]=C+8`，把 **`C+8` 傳入基底事件框架**。在這個實際註冊／派送模型中：

`(C+8)+0x140 = C+0x148`。

而建構 `0x48AC81..0x48ACA6` 明確把 **`[C+0x148]=0xC05AEC`**；`.rdata [C05AEC]=0x4930E0`。所以 E40 的疑點應校正為 **以 C+8 與 C 兩個不同原點計算 offset**，不是對 `C+0x140` 猜一個 vptr。`0x80486D` 的 `holder.vptr[0]` 在 holder 是 `C+0x148` 且 vptr 未遭覆寫時，**可以精確解析到 `0x4930E0`**。

E41 還將 `0x4930E0` 的下一層閉合：`receiver= C+0x148`；`receiver+0xB8=C+0x200` 的 `vptr C05B04`，其中 `+4=0x48AAD0`；後者以 `command` 的 signed16 值索引 **`C+0x200` 後方 stride16 callback table**，對未覆寫的 index 2 / 0xBD2 轉交 `0x494360`；再由 `FD2CF8`（vptr `C06EB4`）的 `+4=0x4FDA30` 查取 **另一張 stride8 table**。因此先前 `0x4930E0→0x494360→0x4FDA30` 不是單一直接 call，而有必要的中繼 `0x48AAD0`，且存在優先別的 callback override / fallbacks。

**重要限定**：已證完整 Client 的建構、具體 vtable 槽、事件框架的間接呼叫與兩層表的靜態條件可達性；尚未找到與實際執行時間一致的 `runtime manager [0xFBA7CC]+4` 的**完整 writer/lifetime**（詳 Round2）。不宣告所有 connection/lane/command 都一定走 0x4FDA30，更不能因指標鏈閉合就宣告選服後第一個 S→C、first wire、相容 Server 或可玩已閉合。

### 研究結果與證據分級

| Claim | 原生第一手新事實 | 核對位置 | 等級／限定 |
|---|---|---|---|
| E41-C01 | `C+8` 為獨立 vptr `C05AA4`，`C05AA4+0x30=490FE0`；`C+148` vptr `C05AEC[0]=4930E0` | `48AC79..48ACAC`；PE `.rdata` | **已證**靜態布局 |
| E41-C02 | 具體 stack Client 建構後取 `C+8` 作為事件框架 `ESI`；`490FE0` 的 `[ebp+8]` 為另一個 explicit pointer，並以 `+0x140` 算 pump holder | `4A3041..4A305A`、`6DEB40`、`490FE0..491025`、`49197F..49198F` | **已證**來源/運算；管理器註冊重取尚需補證 |
| E41-C03 | `80486D` 取 `[holder.vptr+0]` 並以 `this=holder` 傳 `Conn*, payload*, len, lane`；若 holder 是 `C+148`，唯一已安裝的 constructor vtable entry 為 `4930E0` | `804837..80486F`、`48AC9A`、`.rdata C05AEC` | **條件已閉合**；動態 vptr 覆寫須另核對 |
| E41-C04 | `4930E0` 在 len≠0、lane==2 時從 `this+B8` 取次級物件，`C05B04+4` 的 target 實為 `48AAD0` | `4930E4..493154`、`48ACAC`、`.rdata C05B08` | **已證**上述條件 |
| E41-C05 | `48AAD0` 用 signed16 command 索引 `C+0x200+16*cmd+8` callback、`+0xC` this-adjust；`493170` 初始化 3029 slots default=`494360`，exceptions 依偏移改寫 | `48AAD0..48AB65`、`493170..494354`、`48C027..48C02A` | **已證**表構造／分派；不代表免前置界限 |
| E41-C06 | `494360` 用 `FD2CF8.vptr+4` tail-jmp 到 `4FDA30`，後者 signed16 command 查 stride8 callback；index2/0BD2 registered handlers 仍只代表 callback 命名空間 | `494360..4943AA`、`4FDA30..4FDAB0`；E38/E39 | **已證**條件性二層轉送 |
| E41-C07 | `4930E0` 在 index2/BD2 的 first-tier slot 沒有出現在 `493170..494354` 的明確 override 寫入中 | 靜態全函式掃描 + 索引算式 | **限定否證**，其他 writer/alias 不能排除 |
| E41-C08 | `804740` 收到 callback 非零值時不再對當前 lane 繼續 pop；零才可再從同 lane pop；packet recycle 先於 return gate | `80486F`, `8048D3..8049C7` | **已證**本 pump 局部條件 |

## 1. 原件、映射與掃描方法

- 靜態讀取原始 `Tartaros.bin` 12,472,320 byte，重算 SHA256 如上；用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 解碼局部指令，用 Python `struct.unpack_from('<I')` 讀取 `.rdata` 實際 DWORD。`objdump` 對 `-b binary` 顯示 `section .data` 只是 raw input 虛擬 label，**不可誤認為 PE `.data` section**。
- PE `.text` VA `0x401000` / raw `0x400`：`raw=VA−0x400C00`；PE `.rdata` VA `0xBD2000` / raw `0x7D0600`：`raw=VA−0x401A00`；`.data`（如 FD2CF8 / FB A7 CC globals）有獨立 raw 映射，絕不能把 `.text` bias 用於讀取 vptr。
- 對關鍵 function 用直接 BIN bytes/asm 而非用 `kr-bulk-roy/9741d.../functions/*.c` 推測；既有 E38/E39/E40 只作交叉索引，不當成這次新驗證結論。
- 以下 .rdata 原始 DWORD 全由目前 BIN 實際讀出：

```text
{
  "0xc05a9c": [
    "0x48b160",
    "0xc6940c",
    "0x49ade0",
    "0x48ee70"
  ],
  "0xc05aa4": [
    "0x49ade0",
    "0x48ee70",
    "0x48fff0",
    "0x490550"
  ],
  "0xc05ad4": [
    "0x490fe0",
    "0x492040",
    "0x492900",
    "0x476430"
  ],
  "0xc05aec": [
    "0x4930e0",
    "0x5f5d10",
    "0x49ae20",
    "0x49ae10"
  ],
  "0xc05b04": [
    "0x49adf0",
    "0x48aad0",
    "0x422810",
    "0x4227f0"
  ],
  "0xc06eb4": [
    "0x4c5940",
    "0x4fda30",
    "0x422810",
    "0x4227f0"
  ]
}
```

關鍵 offset 核對（僅 `.text` 與 `.rdata` 有效）：

| 位址 VA | PE 區塊 | file raw | 性質 |
|---|---|---:|---|
| `0x80486D` | `.text` | `0x403C6D` | `call edx`, holder virtual0 |
| `0x490FE0` | `.text` | `0x903E0` | `C+8` vtable +0x30 routine |
| `0x4930E0` | `.text` | `0x924E0` | holder callback target |
| `0x48AAD0` | `.text` | `0x89ED0` | C+0x200 command frontend |
| `0x493170` | `.text` | `0x92570` | front-tier stride16 table init |
| `0x494360` | `.text` | `0x93760` | front-tier default forwarding |
| `0x4FDA30` | `.text` | `0xFCE30` | global stride8 table dispatch |
| `0xC05AA4` | `.rdata` | `0x8040A4` | subobject vtable |
| `0xC05AEC` | `.rdata` | `0x8040EC` | packet holder vtable |
| `0xC05B04` | `.rdata` | `0x804104` | front-tier dispatcher vtable |
| `0xC06EB4` | `.rdata` | `0x8054B4` | global handler vtable |

## Round 1（E41）：先以原始物件布局和間接目標修正 8-byte 認知缺口

### 1.1 兩個真正的物件指標，不能共用 Client 原點

完整 Client 記作 `C`，建構入口 `0x48AB70` 取 `[EBP+8]→EDI=C`。`0x48AC79` `ESI=C+8`；`0x48AC81` 用 `EAX=C+0x148` 構造 queue consumer holder；完成後 `0x48AC9A` 安裝 `C05AEC`。`0x48ACA6` 是 **`[C+8]=C05AA4`**，不是 `[C+0]=C05AA4`。`C+0x200` 再安裝 `C05B04`。建構過程曾有 `C515EC`, `C05B38` 等初始/過渡 vptr，**必須依建構完成的可達階段判斷**。

### 完整 Client 建構及四個次級 vptr (`0x48AC71`–`0x48ACD9`)

```asm
  48ac71:	b9 00 04 00 00       	mov    ecx,0x400
  48ac76:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  48ac79:	8d 77 08             	lea    esi,[edi+0x8]
  48ac7c:	e8 1f 3e 25 00       	call   0x6deaa0
  48ac81:	8d 87 48 01 00 00    	lea    eax,[edi+0x148]
  48ac87:	e8 f4 96 37 00       	call   0x804380
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f 60 bf 00 00    	mov    DWORD PTR [edi+0xbf60],ebx
  48acbc:	89 9f 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],ebx
  48acc2:	89 9f 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],ebx
  48acc8:	89 9f 6c bf 00 00    	mov    DWORD PTR [edi+0xbf6c],ebx
  48acce:	c7 87 70 bf 00 00 64 	mov    DWORD PTR [edi+0xbf70],0x64
  48acd5:	00 00 00 
  48acd8:	89         	mov    DWORD PTR [edi+0xbf74],ebx
```

`0x804380` 以 `EAX=C+0x148` 建立 holder，先寫 `C515EC`、清零其計數欄位，稍後由 Client ctor 改成 `C05AEC`；反證「`C+140` 自己在 ctor 就被寫 `C05AEC`」：沒有，實際位置是 `C+148`。

### holder 前段構造 (`0x804380`–`0x8043C8`)

```asm
  804380:	33 c9                	xor    ecx,ecx
  804382:	c7 00 ec 15 c5 00    	mov    DWORD PTR [eax],0xc515ec
  804388:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  80438b:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  80438e:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  804391:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  804394:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  804397:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  80439a:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  80439d:	89 48 24             	mov    DWORD PTR [eax+0x24],ecx
  8043a0:	89 48 28             	mov    DWORD PTR [eax+0x28],ecx
  8043a3:	66 89 48 2c          	mov    WORD PTR [eax+0x2c],cx
  8043a7:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  8043aa:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  8043ad:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  8043b0:	89 48 3c             	mov    DWORD PTR [eax+0x3c],ecx
  8043b3:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  8043b6:	89 48 44             	mov    DWORD PTR [eax+0x44],ecx
  8043b9:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  8043bc:	89 48 50             	mov    DWORD PTR [eax+0x50],ecx
  8043bf:	89 48 54             	mov    DWORD PTR [eax+0x54],ecx
  8043c2:	66 89 48 58          	mov    WORD PTR [eax+0x58],cx
  8043c6:	89 48              	mov    DWORD PTR [eax+0x5c],ecx
```

### destructor/reinit 再次安裝四個 vptr (`0x48B1B5`–`0x48B1D8`)

```asm
  48b1b5:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  48b1b8:	c7 06 9c 5a c0 00    	mov    DWORD PTR [esi],0xc05a9c
  48b1be:	c7 46 08 a4 5a c0 00 	mov    DWORD PTR [esi+0x8],0xc05aa4
  48b1c5:	c7 86 48 01 00 00 ec 	mov    DWORD PTR [esi+0x148],0xc05aec
  48b1cc:	5a c0 00 
  48b1cf:	c7 86 00 02 00 00 04 	mov    DWORD PTR [esi+0x200],0xc05b04
  48b1d6:	5b c0  
```

### 1.2 真實調度到 Client+8 的來源／plus-8 取址不是猜測

`0x4A3041` 先建 Client `C=lea[esp+0x2c]`，呼叫 ctor；`0x4A304B` 將 `ESI=lea[esp+0x34]=C+8`，之後呼叫 `0x6DEB40`（並將 ESI 保留以繼續後續事件流程）。這是直接 BIN 支援的相對取址，不靠推斷 C++ 物件名稱。

### 完整 Client stack 與事件框架指標差 8 bytes (`0x4A3041`–`0x4A306C`)

```asm
  4a3041:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  4a3045:	51                   	push   ecx
  4a3046:	e8 25 7b fe ff       	call   0x48ab70
  4a304b:	8d 74 24 34          	lea    esi,[esp+0x34]
  4a304f:	c7 84 24 c0 c0 00 00 	mov    DWORD PTR [esp+0xc0c0],0x1
  4a3056:	01 00 00 00 
  4a305a:	e8 e1 ba 23 00       	call   0x6deb40
  4a305f:	e8 dc bb 23 00       	call   0x6dec40
  4a3064:	8b fe                	mov    edi,esi
  4a3066:	e8 25 bc 23 00       	call   0x6dec90
  4a306b:	e8           	call   0x44d680
```

### 事件框架以 ESI 次級物件作 receiver 進入 vtable+0x20/+0x28 (`0x6DEB40`–`0x6DEB52`)

```asm
  6deb40:	8b 06                	mov    eax,DWORD PTR [esi]
  6deb42:	8b 48 20             	mov    ecx,DWORD PTR [eax+0x20]
  6deb45:	57                   	push   edi
  6deb46:	56                   	push   esi
  6deb47:	ff d1                	call   ecx
  6deb49:	85 c0                	test   eax,eax
  6deb4b:	74 1f                	je     0x6deb6c
  6deb4d:	8d 56 40             	lea    edx,[esi+0x40]
  6deb50:	52                   	push   edx
  6deb51:	68           	push   0xc411d8
```

### 事件框架 vtable+0x28 並且保留 ESI 至背景設置 (`0x6DEC15`–`0x6DEC3E`)

```asm
  6dec15:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6dec18:	8b 06                	mov    eax,DWORD PTR [esi]
  6dec1a:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  6dec1d:	56                   	push   esi
  6dec1e:	ff d1                	call   ecx
  6dec20:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6dec23:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6dec26:	56                   	push   esi
  6dec27:	68 50 ae 6e 00       	push   0x6eae50
  6dec2c:	68 10 ae 6e 00       	push   0x6eae10
  6dec31:	50                   	push   eax
  6dec32:	51                   	push   ecx
  6dec33:	e8 18 3c 00 00       	call   0x6e2850
  6dec38:	83 c4 14             	add    esp,0x14
  6dec3b:	33 c0                	xor    eax,eax
  6dec3d:	5f                   	pop    edi
```

`C05AA4` vtable 的 `+0x20=48BE50`，`+0x28=48C6E0`，`+0x30=490FE0`，均以 `.rdata` 原始 DWORD 驗證，這可將 `490FE0` 定為 **C+8 這張 vtable 的第12個 slot**。`0x48BE50` 入口 `[ebp+8]` 為 subobject pointer，向下在 `48C027` 以 `EBX−8` 取得完整 C 呼叫 `493170` 初始化 command table，提供反向的 this-adjust 證據。

### 從 C+8 減 8 復得 C，初始化 callback table (`0x48C009`–`0x48C032`)

```asm
  48c009:	8b 83 78 bf 00 00    	mov    eax,DWORD PTR [ebx+0xbf78]
  48c00f:	68 28 5b c0 00       	push   0xc05b28
  48c014:	68 f0 56 c0 00       	push   0xc056f0
  48c019:	50                   	push   eax
  48c01a:	68 fc 56 c0 00       	push   0xc056fc
  48c01f:	e8 dc 1c 26 00       	call   0x6edd00
  48c024:	83 c4 10             	add    esp,0x10
  48c027:	8d 43 f8             	lea    eax,[ebx-0x8]
  48c02a:	e8 41 71 00 00       	call   0x493170
  48c02f:	f6 05 14     	test   BYTE PTR ds:0xfb1314,0x1
```

### 1.3 mainloop 的 callback holder 實際計算

`0x490FE0` 是無 direct `E8 CALL` xref 的虛擬槽 `C05AA4+0x30`；入口讀 explicit stack argument（不是 `ECX=this`）`[ebp+8]`，保存在 local `[esp+0x20]`，後段 `49197F` 取回並 `lea ebx,[edi+0x140]`。如果事件框架傳的是上述 `C+8`，則 **holder=C+0x148**。不可以直接將 `+0x140` 視為完整 `C+0x140`。

### vtable+0x30 中的 explicit argument 來源 (`0x49101A`–`0x49102B`)

```asm
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35        	cmp    DWORD PTR ds:0xfba858,esi
```

### 主循環以傳入指標 +0x140 調用 queue pump (`0x49197F`–`0x49199B`)

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc     	or     DWORD PTR ds:0xfc10cc,0x1
```

### 1.4 pump 的 virtual0 參數與返回值

`0x804740` 的持續保留 `EBX=holder`；`804858` 讀 `holder.vptr`、`80485A` 讀 vptr[0]，`ECX=holder`，使用 thiscall/stdcall 混合 ABI：stack arg1=`pkt+0 Conn*`、arg2=`pkt+8 payload bytes`、arg3=`pkt+4 length`、arg4=`lane loop value`，此處 **lane 是應用 queue lane，不等 transport key**。callback 的 return 在 `80486F` 存到 `[ebp-0x1c]`。`0x8049A3` 值為零才繼續同 lane pop；非零則先停止該 lane drain，轉下個 lane。packet block 早在 `8048D3...` 清零並交回 FE3358 pool，這與 Conn lifetime 是不同事情。

### application packet pop → vptr[0] thiscall (`0x804837`–`0x80488B`)

```asm
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
```

### 回收後 callback return!=0 停止當前 lane pop (`0x804993`–`0x8049E5`)

```asm
  804993:	01 73 50             	add    DWORD PTR [ebx+0x50],esi
  804996:	83 7d 08 02          	cmp    DWORD PTR [ebp+0x8],0x2
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
  8049c7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049cd:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8049d0:	83 fe 02             	cmp    esi,0x2
  8049d3:	75 05                	jne    0x8049da
  8049d5:	ff d7                	call   edi
  8049d7:	89 43 44             	mov    DWORD PTR [ebx+0x44],eax
  8049da:	46                   	inc    esi
  8049db:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  8049de:	83 fe 06             	cmp    esi,0x6
  8049e1:	0f 8c 3f fe      	jl     0x804826
```

**Round1 增量/停止理由**：首次用精確的 `C+8` vptr +0x30、Client `C+0x148` constructor、事件框架 `ESI=C+8` 建立能解釋 E40 8-byte mismatch 的**native 因果鏈**。此已達三輪規則的「重大有界新增功能鏈」門檻，理論上可停止 E41；但為查真實 callback downstream/不同命令表的中繼，繼續 Round2/3，而非換題。

## Round 2（E41-2）：追完整雙層 virtual 中繼、command table owner 和 ABI

### 2.1 `0x4930E0` 根本不是直接 call `0x494360`

在 `ECX=holder=C+0x148` 條件成立時，函式 `0x4930E0` 先取 payload 前兩 bytes 成 unsigned `WORD command`；只在 `len!=0` 且 `lane==2` 下由 `0x493120` 讀 `holder+0xB8`，算式等於 `C+0x200`。**這是次級多型子物件本體而非 `[Client+0xB8]`**。建構寫的 `[C+0x200]=C05B04`，從其 vtable+4 取回 `0x48AAD0` 並 `call edx`。傳入 payload,len,command；**Conn* 在這段沒有透傳給二層函式**，但仍在 80486D 初始 callback arg1 供擴充/紀錄。

### 本次關鍵：holder+B8 ⇒ C+200 ⇒ 48AAD0 (`0x4930E0`–`0x493160`)

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10              	ret    0x10
```

### 2.2 `0x48AAD0` 的 stride16 callback table：index 與 this-adjust

`0x48AAD0` (ECX=C+0x200) 將 command 以 `movsx eax,bx` 轉 signed16，`eax*=2`，用 `edi+eax*8+8` 取 callback，即實際 16 bytes/entry；`+0xC` 是 this adjustment。`lea ecx,[adjustment + (C+0x200) - 0x200]`：default zero adjustment 下 ECX 回復完整 C；從而 `0x494360` 以**完整 Client C** 當 thiscall ECX 進入（該 forwarding 函式隨後改用 global object ECX），此補完 E39 只見兩張表的中間 owner。缺 callback 走 vtable+0xC（`C05B10=0x4227F0`），回傳 `0x80004005` 只觸發 local 報錯紀錄，不代表 remote error code。

### front-tier command dispatch, fallback and this adjustment (`0x48AAD0`–`0x48AB66`)

```asm
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
  48ab64:	5d                   	pop    ebp
  48ab65:	c2               	ret    0xc
```

### 2.3 `0x493170` 是 table 初始化，而非 packet handler；逐個 slot 初始化總數 0xBD5

`EAX=C` 從 `0x48C027 LEA EAX,[EBX-8]` 得到，`0x49317A lea edx,[eax+0x210]` 配合寫 `[edx-8]`，故起點是 `C+0x208`，完整 frontend entry callback 偏移為 `C+0x208 + 16*command`，元資料／調整欄位 `C+0x20C + 16*command`，描述 pointer `C+0x210 +16*command`。原 E39 「Client callback table stride16」確定不是 FD2CF8 stride8。

完整函式 `0x493170..0x494354` 的線性解碼檢視有若干 special index callback 覆寫（例如 `C+0x398→0x494780`、`C+0x1048→0x4943B0`、`C+0xBE78→0x4943B0`），所以不能說**所有** command 都經過 `0x494360`；但本次**精確查** command `2` 的前端 callback 位址 `C+0x228`，command `0xBD2` 的前端 callback 位址 `C+0xBF28`，均不出現在這個 initializer 的明確 override 寫入中（這是有搜尋邊界的反證，不保證其他 writer 不可能動態覆蓋）。

### default callback table loop + 初期特例 (`0x493170`–`0x4931D1`)

```asm
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80 47 49 00       	mov    edx,0x494780
  4931a3:	89 90 98 03 00 00    	mov    DWORD PTR [eax+0x398],edx
  4931a9:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931ae:	89 90 48 10 00 00    	mov    DWORD PTR [eax+0x1048],edx
  4931b4:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931b9:	89 90 c8 03 00 00    	mov    DWORD PTR [eax+0x3c8],edx
  4931bf:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931c4:	89 90 08 04 00 00    	mov    DWORD PTR [eax+0x408],edx
  4931ca:	ba 60 48 49 00       	mov    edx,0x494860
  4931cf:	89 90        	mov    DWORD PTR [eax+0x438],edx
```

### 2.4 `0x494360 → 0x4FDA30` 的 vtable 尾部

`0x494360` 在 `FD2CF4` lazy guard 未初始化時把 `.data [FD2CF8] = C06EB4`、call `0x4B7DC0` 註冊 handlers；之後 `ECX=FD2CF8`, `EDX=[[FD2CF8].vptr+4]=4FDA30`, `jmp edx`。`0x4FDA30` 對 signed16 command 用 `FD2CF8+8*command+4` 取 handler callback，與上一層 16-stride 是不同表。E38 的 table writer 將 index 2 設為 `4B7F00`、index 0xBD2 設為 `4B8DC0`；只有輸入 command、lane、其他 gates 真正滿足時才可達，**尚未證任何一筆是登入/選服 first S2C**。

### FD2CF8 lazy vtable dispatch (`0x494360`–`0x4943AB`)

```asm
  494360:	55                   	push   ebp
  494361:	8b ec                	mov    ebp,esp
  494363:	b8 01 00 00 00       	mov    eax,0x1
  494368:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  49436e:	75 2c                	jne    0x49439c
  494370:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  494376:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  49437d:	6e c0 00 
  494380:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  494387:	00 00 00 
  49438a:	e8 31 3a 02 00       	call   0x4b7dc0
  49438f:	68 f0 dc bc 00       	push   0xbcdcf0
  494394:	e8 81 df 3f 00       	call   0x89231a
  494399:	83 c4 04             	add    esp,0x4
  49439c:	b9 f8 2c fd 00       	mov    ecx,0xfd2cf8
  4943a1:	a1 f8 2c fd 00       	mov    eax,ds:0xfd2cf8
  4943a6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4943a9:	5d                   	pop    ebp
  4943aa:	ff                 	jmp    edx
```

### global handler table stride8 signed command (`0x4FDA30`–`0x4FDAB3`)

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
```

**Round2 增量/停止理由**：新增 E40/E39 都沒有連起的 `C+0x148→C+0x200→48AAD0→C+0x208/stride16→494360→FD2CF8/stride8→4FDA30`，含命令轉換、this-adjust、兩套 index 的具體地址、fallback 和 conditional lane；**超過重大發現門檻**，第三輪只是為以框架上游來源和反證／錯誤處理檢查確認不超稱。

## Round 3（E41-3）：framework 的真正 callback upstream、return gate、native bounds 與反證

### 3.1 事件框架的 indirect vtable+0x30（不是盲用 0x490FE0 static reference）

`0x6DFA50` 有本輪新找到的框架調度：`call 0x6DFBE0`、後段 `0x6DFADF MOV ECX,[EAX]`、`0x6DFAE1 MOV EDX,[ECX+0x30]`、`0x6DFAE4 PUSH EAX`、`0x6DFAE5 CALL EDX`。`0x6DFBE0` 實際從 `FBA7CC` 指向的 runtime manager 的 `+4` 取出物件指標；若它是前述註冊的 `C+8`，虛擬 slot+0x30 就是 `0x490FE0`，並把 **same object pointer as explicit arg** 傳給它。再由 `0x491983` 做 `arg+0x140` 恰好 `C+0x148`。

**受限證據**：追到 manager+4 的讀取和 `0x4A304B` 的 `C+8` 建立，但**尚未把 manager+4 的寫入者／替換／teardown 與該同一物件 C+8 做完整別名/生命週期證明**。故完整 IOCP→特定 handler 的實際 runtime reachability 判為「條件式高可信靜態可達」，**不宣稱無條件一定發生**。與 E40 相比，疑點已大幅縮減為可定位的 manager pointer writer，而不是不知道 80486D 的 vptr。

### framework 以 vtable+0x30 呼叫登記物件 (`0x6DFAC9`–`0x6DFAEE`)

```asm
  6dfac9:	e8 12 01 00 00       	call   0x6dfbe0
  6dface:	6a 01                	push   0x1
  6dfad0:	eb 0d                	jmp    0x6dfadf
  6dfad2:	ff 15 d4 24 bd 00    	call   DWORD PTR ds:0xbd24d4
  6dfad8:	e8 03 01 00 00       	call   0x6dfbe0
  6dfadd:	6a 00                	push   0x0
  6dfadf:	8b 08                	mov    ecx,DWORD PTR [eax]
  6dfae1:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  6dfae4:	50                   	push   eax
  6dfae5:	ff d2                	call   edx
  6dfae7:	e8 e4 a8 00 00       	call   0x6ea3d0
  6dfaec:	84 c0                	test   al,al
```

### framework manager 的 +4 object getter (`0x6DFBE0`–`0x6DFC3A`)

```asm
  6dfbe0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6dfbe5:	85 c0                	test   eax,eax
  6dfbe7:	75 1f                	jne    0x6dfc08
  6dfbe9:	68 80 13 00 00       	push   0x1380
  6dfbee:	e8 75 16 1b 00       	call   0x891268
  6dfbf3:	83 c4 04             	add    esp,0x4
  6dfbf6:	85 c0                	test   eax,eax
  6dfbf8:	74 07                	je     0x6dfc01
  6dfbfa:	e8 d1 f7 ff ff       	call   0x6df3d0
  6dfbff:	eb 02                	jmp    0x6dfc03
  6dfc01:	33 c0                	xor    eax,eax
  6dfc03:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6dfc08:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc0f:	56                   	push   esi
  6dfc10:	8b f0                	mov    esi,eax
  6dfc12:	74 0b                	je     0x6dfc1f
  6dfc14:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc19:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6dfc1f:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc26:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  6dfc29:	74 0b                	je     0x6dfc36
  6dfc2b:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc30:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6dfc36:	8b c6                	mov    eax,esi
  6dfc38:	5e                   	pop    esi
  6dfc39:	c3                   	ret
```

### 3.2 Callback return 和 lane 的嚴格邊界

- `0x4930E0` `len==0` 返回零；`lane!=2` 也返回零，並未轉送到 `C+200`。`lane==2, len>0` 時，dispatch return 必須 `==0x100` **且** `[holder+0xBE8C]!=0`，才回傳 1；其餘回傳0。`0x804740` 的 `0x8049A3` 依此決定是否繼續 pop 該 lane；這是局部 consumer drain control，不是 socket close/retry 的證據。
- `0x4930ED` 在 `test len` 之前就讀 `WORD [payload]`；本地沒有 `len>=2` check 的證據（frame 上游是否保證最短長度需另核）。`0x48AAD0/0x4FDA30` 都對 signed 16-bit command 做乘 stride 的索引；範圍／可靠性仰賴 upstream command 範圍和有效 payload，不得未驗就聲稱可由遠端隨意 out-of-bounds，也不得忽視測試中需要長度/索引邊界。
- E40 證明 `Conn+A080` 與 transport map key 不同：三條 Connect 的第四參數都曾傳 2。E41 的 `493105..49310b` 僅檢查**application lane==2**，不能用它宣告這張表只處理 key2 socket。來自 key0/1/2 的 Conn* 可以同 lane；哪一條 wire 產生命令2/0BD2仍待驗。
- `0x804740` 返回值驅動 pop loop stop；packet pool 的回收只保證 packet block pointer 被處理，**不能推論 Conn object refcount 已保持至 handler 完成**；未找到 free/race runtime 反證。

### 3.3 失敗、fallback、下一步分析應限定到什麼程度

| 條件 | 本輪 native 本地效果 | 未可宣稱的遠端/遊玩結果 |
|---|---|---|
| `804100` 無 packet | `804740` 轉 lane/完成這次 drain | 不等於 socket 空閒或斷線 |
| packet callback 透傳 `Conn*` | `80486D` 傳 pkt+0 Conn* 至 `4930E0` 的第一參數 | 不等於 `4930E0` 會依 transport key 決定 business handler |
| `len==0` 或 lane!=2 | `4930E0` 不調 `48AAD0` | 不等於非2 lane 的所有消息都永不被消費（仍由 pump 虛擬0獲取） |
| `48AAD0` 前端 slot null | virtual +0xC fallback（由 C05B04 表實例為 4227F0） | 不等於 wire 回應失敗 |
| 前端 slot 為 special callback | 可繞過 494360/4FDA30 | 不得對所有命令畫單線流程 |
| `4FDA30` global handler null | global vtable +0xC fallback | 不等於 Server 需要送空 handler 消息 |
| `48AAD0` / `4FDA30` callback return `0x80004005` | 走本地報錯/trace helper | 不等於官方 Server 的拒絕代碼 |
| callback return 1 | `804740` 在當前 lane 停止連續 pop | 不等於重試/掉線/丟棄未來 queue |

**Round3 結論/停止**：利用不同 upstream（事件框架 `6DFA50`）補上 `vtable+0x30` consumer，並把 `6DFBE0` 定位為 manager+4 object reader；足以讓 RR5 之網路 → application dispatcher 有實質新的、可供本地或下段追查的條件閉合。manager+4 writer/lifetime 與真正遊戲第一個收包則保留 UNKNOWN；三輪均已執行，完成本段，不用 E41 重跑相同入口。

## 4. 目前證實的條件式呼叫鏈／精確參數來源

```text
C := complete Client at 0x48AB70([ebp+8])
C+0x008 -> vptr 0xC05AA4, slot+0x30 -> 0x490FE0
C+0x148 -> vptr 0xC05AEC, slot+0x00 -> 0x4930E0
C+0x200 -> vptr 0xC05B04, slot+0x04 -> 0x48AAD0

0x4A3041 C = &stack[0x2c]
0x4A304B ESI = C+8 ; 0x6DEB40 passes ESI to event framework

0x6DFBE0 -> runtime manager[+4] => obj* (writer/lifetime NOT FULLY CLOSED)
0x6DFAE1 [obj.vptr+0x30], push obj, call
    [IF obj = C+8 AND vptr = 0xC05AA4]
      -> 0x490FE0(arg=obj=C+8)
      -> 0x491983 pump holder = obj+0x140 = C+0x148
      -> 0x804740 / 0x804100 app queue pop (FC10D0)
      -> 0x80486D holder.vptr[0](Conn*, payload*, len, lane)
      -> 0x4930E0(ECX=C+0x148)
           if len==0 OR lane!=2: return 0
           command = LE16(payload[0:2])
           C+0x148 + 0xB8 = C+0x200
      -> 0x48AAD0(ECX=C+0x200; payload,len,signed16 command)
           frontend = [C+0x208 + signed16(command)*16]
           adjust   = [C+0x20C + signed16(command)*16]
           [IF callback==494360 (default, no override)]
      -> 0x494360 -> FD2CF8.vptr[+4]
      -> 0x4FDA30 -> [FD2CF8 + 4 + signed16(command)*8]
           [IF registered entry nonnull] -> native handler
               command 2     -> 0x4B7F00 (E38 register)
               command 0xBD2 -> 0x4B8DC0 (E38 register)
           else -> global vtable fallback
      -> callback return to pump (recycle packet, conditional lane drain)
```

**實際 ABI**：

- `80486D` ECX=`holder=C+148`; stack arg1=`Conn*`, arg2=`&pkt[8]`, arg3=`pkt[4] len`, arg4=`queue lane`；receiver method `ret 0x10`。
- `4930E0` 保留 ECX 為 subobject; `0x493120` 取 `C+200`, arg1=`payload*`, arg2=`len`, arg3=`command` 傳 `48AAD0`，沒有 Conn*；`ret0x10`。
- `48AAD0` ECX=`C+200`，以表內 adjusted this (`C+200 -0x200+metadata`) 調 callback；`ret 0xC`。default adjustment=0，所以轉接 `494360` 以 ECX=C（此函式自行將 ECX 換 global FD2CF8），push 不修改 payload,len,command。
- `494360` 用 `jmp edx` tail-call 到 `4FDA30`，命令仍為獨立第三 stack arg；`4FDA30` ECX=FD2CF8, `ret0xC`。
- `0x804740` 的第四個 callback arg 是 queue lane 由 `0x804100` pop loop 取得；`packet+0 Conn*` 的完整來源已在 E40 實證 `0x807D8B`。**不把 `lane==2` 翻譯成 socket key2**。

## 5. 上輪原稿關係、糾正與真正 RR-0005 尚缺的部分

| 來源 | E41 補證/限縮 |
|---|---|
| E38 | `4B7F00` index2 / `4B8DC0` index0BD2 的 writer 及 handler 副作用沿用；E41 首次讓其可能接在 app FIFO 後面，仍不得說是登入初始回覆。 |
| E39 | 原已見 `4930E0`,`494360`,`4FDA30` 個別，還差 runtime queue 來源與中介 48AAD0；E41 以兩個 vptr+兩張表連起，並指出 front-tier override 會繞過 generic dispatch。 |
| E40 | `IOCP→FC10D0→804740` 成立；對 `Client+140` 與 `Client+148` 的表面不一致，應改成「事件框架傳入 `C+8`，其 `+0x140=C+0x148`」的**帶條件 vtable 修正**，而非說 C+140 本身需要寫 C05AEC。 |
| E32–E37 | transport key0/1/2、local frame、queue/wire 的原有來源隔離不變；C2S enqueue 不等於 WSASend，handler index 2 不等於完整 wire envelope。 |

### RR5 最小可用目前接口／玩家情境矩陣

| 玩家／連線情境 | 原版 Client 已證 | wire/order/UI 仍未知 | Server 需要開發/整合 |
|---|---|---|---|
| 在某條 Conn 已連線後收到 framing 成功 payload | E40 IOCP parser→queue；E41 可條件性進兩層 callback index | 此 Conn 是 key0/1/2 的哪個 map 物件、當前 lane writer、真實第一個 S2C payload | 相容 framing/response schema 須等逐連線證據才能固定 |
| payload command index 2，lane2 | E41 在 default callback 下可條件性路由 `4B7F00`；E38 handler 更新局部 state 並本地 enqueue C2S | 是否由登入/選服 Server 實際送來、長度完整最小 guard、與 `0x13` UI 的時序 | 客製資料填充/狀態決策不能推為官方 Server 規則 |
| payload command index0xBD2，lane2 | E41 可條件性路由 `4B8DC0`，E38 記錄兩段文字及 local key2 control enqueue | 是否曾由選服第一個回覆引發、Conn key 與實際 wire arrival order | 有驗證之欄位時才可列入設計 SPEC |
| 登入 result `0x13`→選服→close/connect | 原 E32–E37 有某些 Connect call sites / old static port / local send | `0x13` UI result → 哪個 Connect caller 的條件、first sender/response、retry、時序未由 E41 打通 | T03 提供業務 UI 證據，T02 補連線，T01/S00 跨功能整合 |

### 四類缺口（不得混淆）

1. **Client 待逆向（T02）**：`0x6DFBE0` manager+4 writer/owner/lifetime 與 `0x6DFA50` 真正 registration call；所有 `C+0x148` vptr alias／覆寫；`C+0x208+16*cmd` 其他寫入者；`0x495610/0x4957C0` 選服切換之具體 gate、close/retry、first packet per connection；frame 最短資料長度與 signed index upstream range。
2. **Server 待開發**：以原 Client 實證的 framing、每條 conn/slot、command payload/回覆資料為基礎做相容設計；原版 Server 驗證／分流演算法、部署 port、自訂 policy 尚無可冒充的原生證據；歷史 ports 只是 literals。
3. **跨功能待整合**：T03 主責 `0x13` 驗證結果、選服 UI、角色選擇等本地 business state；T02 只負責本層 route。T01 的 NATIVE_VERIFIED/FULL-PASS 及 S00 GAP-NET-0002 接受仍需權責/證據審核，E41 本機原稿不是 Git 提交。
4. **待遊玩驗證**：無原版 Server pcaps、實際原版 client 啟動、socket trace 或相容 Server round-trip；`runtime chain conditionally closed` **不等於**「選服後下一畫面可進」。

### E42 精確下一入口（不是重做 E40）

優先從 runtime manager `0xFBA7CC` 的 `+4` pointer 寫入者／替換者搜尋（`0x6DFBE0`, `0x6DFA50`, `0x6DEB40`, `0x6E2850`）證明其指向 `C+8`；再有界檢查 `0x80486D` callback 的其他可達 vptr writers，以及 `0x493170` exceptions 對本 RR 中可能 first command 的覆寫；之後定向回 `0x495610/0x4957C0` 選服時序、Conn keys 和 T03 `0x13`。如果缺原版抓包/端點授權，提供獨立本地驗證方案而不虛構結果。

## 6. 重現命令（不執行原版遊戲）

```bash
sha256sum Tartaros.bin
# 只讀 PE32 機器碼；objdump 的 binary section 名稱不表示真實 PE section
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x48ac71 --stop-address=0x48acd9 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4a3041 --stop-address=0x4a306c Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804837 --stop-address=0x80488b Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4930e0 --stop-address=0x493160 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x48aad0 --stop-address=0x48ab66 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x493170 --stop-address=0x494355 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6dfac9 --stop-address=0x6dfaee Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4fda30 --stop-address=0x4fdab3 Tartaros.bin
```

**完整結果標記**：E41 **本地研究已完成（Round 1/2/3）**；新函式鏈和限定別名已實證，**RR-0005 仍 PENDING/QUEUED、未正式認領、未 Submit、未 Commit/Push**。不得使用 `SPEC STABLE`、`FULL-PASS`、`可玩` 等無憑斷言。
