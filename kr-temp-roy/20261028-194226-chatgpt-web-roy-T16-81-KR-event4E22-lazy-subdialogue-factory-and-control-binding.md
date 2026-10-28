# KR T16-81 — Quest UI 事件 `0x4E22` 的延遲子視窗配置、建構與控制項綁定（BIN-first）

- 研究者：`chatgpt-web roy`；日期：2026-10-28 19:42:26 Asia/Taipei。**KR only**。
- 第一手原件：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪以 Python/hashlib 與 `objdump -d -Mintel` 重新核對。
- PE32 x86：`.text` VA `0x00401000` / raw `0x400` / size `0x7D01F0`；本輪全部摘錄位於 `.text`，故 `raw=VA-0x00400C00`。`.rdata` VA `0xBD2000`/raw `0x7D0600`，`.data` VA `0xD61000`/raw `0x95E800`。不同 section 不混用映射。
- 僅靜態、唯讀，不執行／附加／patch Client；未有原版網路流量或 Server 原件。地址與 class 名以來源證據分級。
- 此段根據先前 T16-79/80 已確認的內層 UI vtable `0x00C2DA0C` 與 `0x62E360` / `0x62E380`，進入實際事件路徑。本段研究重點是前述 callback **是否真正提交 Quest**，不把 UI ID 當 opcode。

## 1. 新確認的端到端局部功能鏈：事件 → 條件性子物件產生 → 子物件 UI 綁定

### 1.1 事件入口 `0x62E360`（原生已確認）

`[ebp+8] == 0x4E22` 才使用 `lea esi,[ebp+8]` 呼叫 `0x6306F0`；其他事件從本函式直接返回。結尾 `ret 0x0C` 表示會彈出 12 bytes stack arguments。**重要：`0x4E22` 是此 callback 用於條件分派的數值；沒有證明等於 T16-80 查找的 widget ID `0x4E20`，也無證據指向 C→S wire opcode。**

呼叫點 `0x62E370` 的 `ESI` 指向參數區起始地址，故在 `0x6306F0` 內，`[esi+4]` 讀取原函式第二個堆疊參數、`[esi+8]` 讀取原函式第三個堆疊參數；不能把其 `+4`/`+8` 誤認為 UI 物件欄位。

### 1.2 `0x6306F0` 的實際分支（原生已確認）

1. 讀取 `[esi+8]` 作為 output-slot pointer，若 null → 返回；若非 null，讀 `[slot]`。
2. 若 `[slot]!=0`，走診斷分支 `0x630782`，**不建新的物件**。
3. 若 `[slot]==0`，檢查 `[esi+4] == 0x12D`；不相等進 `0x630728` 的診斷路徑。
4. 相等時 `push 0x254; call 0x892068`，配置候選 596 bytes；非 null → `ECX=ptr; call 0x6309D0`，將建構器回傳值寫至 `[slot]`。
5. 失敗時原生 `xor eax,eax; mov [slot],eax`；這是配置失敗結果，不等於任務拒絕回包。

這是一條 **typed lazy factory / output-slot allocation** 靜態鏈，非 packet enqueue、socket API 或 Quest accept handler。使用前段所見 `[esi+4]==0x12D` 與此處的比較只能確認同一數字，不等同把兩者的語意綁定為 Quest UI 按鈕。

### 1.3 新追到的子物件建構器 `0x6309D0`（原生已確認）

配置成功後：

- `0x6309FA` 呼叫 `0x754880`（父層／基底初始化候選，型別未確認）。
- `0x630A0A` 將 vptr 暫寫 `0x00C467DC`。
- `0x630A0B` 將 `this+0x15C` 交給 `0x77B520` 做內嵌成員初始化。
- `0x630A16` 設 `BYTE[this+0x158]=1`。
- `0x630A1D` 將最終 vptr 改為 `0x00C2DBAC`。
- `0x630A23`～`0x630A2F` 將 `this+0x248`, `+0x24C`, `+0x250` 三欄清零。
- `0x630A35` 返回 `this`。

因此前段 `0x6306F0` 只見 `0x254` 配置大小，現在實際閉合到這個子物件的 native vtable／初始化欄位，**是本段相對前稿的實質增量**。

### 1.4 子物件初始化控制項 `0x630A50` / `0x630B30`（原生已確認）

`0x630A50` 使用從 `0x6309D0` 初始化過的 `+0x248/+0x24C/+0x250` slots：

- `0x630B30` 用 child ID `0x526C` 查找，檢驗型別碼 `0xC8`，將結果導向 `this+0x248`（EDI 指向欄位）。
- `0x46B6F0` 按 `0x5208`、`0x52D0` 查另外兩個 child，分別保存到 `this+0x24C` 與 `this+0x250`（helper ABI 需限定，不推測註冊操作）。
- 對後兩個控件調用 `0x7444B0`，傳入 `0xBF6B`，並設定 widget `+0xA4=1`；如 widget 的 `+0x94` 指標非 null，再呼叫其 vtable+`0x04`、比較回傳 `0xBF6B`，吻合時寫被指向物件 `+0x4C=1`。
- 上述為 **UI child lookup / type guarding / flag writes**，沒有觀察到直接把 Quest ID、NPC ID 或封包資料傳入發送佇列。名稱與事件意義仍待 UI 資源對照。

## 2. 版本／位址與 byte proof

| VA | `.text` raw | 確認內容 | 證據級別 |
|---|---|---|---|
| `0x62E360` | `0x22D760` | `cmp [ebp+8],0x4E22; call 0x6306F0` | 原生已確認 |
| `0x62E380` | `0x22D780` | T16-80 七組 child pointer 綁定 | 原生已確認 |
| `0x6306F0` | `0x22FAF0` | output-slot/`0x12D`/`0x254` 分支 | 原生已確認 |
| `0x6309D0` | `0x22FDD0` | final vptr `0xC2DBAC` + 成員初始化 | 原生已確認 |
| `0x630A50` | `0x22FE50` | child 控件 `+0x248/24C/250` 初始化 | 原生已確認 |
| `0x630B30` | `0x22FF30` | child `0x526C` 的 lookup/type checker | 原生已確認 |

原始短 byte proof（從 BIN 指定 raw 讀取，而非前稿複製）：

```text
0x62E360 raw 0x22D760: 55 8b ec 81 7d 08 22 4e 00 00 75 0a 56 8d 75 08 e8 7b 23 00 00 5e 5d c2
0x6306F0 raw 0x22FAF0: 55 8b ec 6a ff 68 c8 d9 91 00 64 a1 00 00 00 00 50 51 a1 20 1f d6 00 33
0x6309D0 raw 0x22FDD0: 55 8b ec 6a ff 68 68 9c 91 00 64 a1 00 00 00 00 50 51 56 57 a1 20 1f d6
0x630A50 raw 0x22FE50: 53 56 8b f0 57 8d be 48 02 00 00 8b ce e8 ce 00 00 00 8d 9e 4c 02 00 00
```

## 3. 局部 CFG 與 C++ 偽碼（不冒認正式 class name）

```cpp
// event callback 0x62E360; schematic only
void OnLocalEvent(uint32_t event, uint32_t subtype, void** destination) {
    if (event == 0x4E22)
        factory_6306F0(&event); // ESI addresses stack argument area
}

void factory_6306F0(uint32_t* event_args) {
    void** slot = (void**)event_args[2];
    if (!slot) return;
    if (*slot != nullptr) { diagnostics(); return; }
    if (event_args[1] != 0x12D) { diagnostics(); return; }
    void* storage = allocate(0x254);
    *slot = storage ? constructor_6309D0(storage) : nullptr;
}

void* constructor_6309D0(void* this_) {
    base_init_candidate(this_);
    *(void**)this_ = (void*)0x00C467DC; // intermediate vptr
    embedded_member_init((char*)this_ + 0x15C);
    *(uint8_t*)((char*)this_ + 0x158) = 1;
    *(void**)this_ = (void*)0x00C2DBAC; // final vptr
    for (auto off : {0x248, 0x24C, 0x250})
        *(void**)((char*)this_ + off) = nullptr;
    return this_;
}
```

注意：以上使用自擬的函式名；不是 PDB / source symbol。factory 的 `ESI` 呼叫慣例並非普通 C 函式參數，偽碼只呈現值來源和控制流，不供直接 ABI 編譯。

## 4. 分輪紀錄與停止門檻

- **T16-81 第 1 輪：** 已新增 `0x62E360` → `0x6306F0` → `0x6309D0` 的成功、null、mismatch、already-initialized CFG；並接到子物件 vptr `0xC2DBAC` 及 `+0x248/+0x24C/+0x250` 的控制項初始化。此為直接 BIN 驗證的完整、有限功能鏈，已達重大新進展門檻。
- **T16-81-2：未啟動。** 第 1 輪已達規範門檻，不機械重做其他函式掃描。
- **T16-81-3：未啟動。** 同上；不是省略未達標輪次。

## 5. 玩家情境與 Client ↔ Server 證據矩陣

| 玩家情境 | Client 本地行為 | C→S | S→C | Quest/UI 狀態 | 相容 Server 待開發 |
|---|---|---|---|---|---|
| 本地事件 `0x4E22` | 條件性檢查 `0x12D`，配置 596 bytes 子 UI 物件到 output-slot | 本鏈無發包證據；整體是否發包 unknown | unknown | 子 UI 物件存在與否改變；Quest cache 不可證 | 無法從本鏈推導任務接受格式 |
| NPC 點擊「接受任務」 | 尚未確定對應哪個控件／事件 | opcode/len/fields unknown | handler/fields unknown | Quest accepted 狀態 writer unknown | 待明確封包原生證據 |
| Quest16 完成 / Quest15 開放 | unknown | unknown | unknown | unknown | 待查 KR 原始資源及任務回覆 |

## 6. 與其他任務／前段邊界及後續入口

- `0x4E22`、`0x12D`、`0xBF6B`、`0x526C`、`0x5208`、`0x52D0` 都在上述 UI/控制項的不同比較域；**不互指**，不可改稱 Quest ID 或封包 opcode。
- 此鏈沒有直接證實 `CQuestListDlg` 事件等價於任務接受。當下可驗證的是 UI callback 觸發新子物件配置與控制項綁定；真正玩家意圖尚需 UI XML／回呼註冊表與其他物件指標使用者證明。
- T02 的 socket/framing、T07 場景、T14 結算、T15 persistence 保留原 owner；本段只在 T16 追入口，未改其他 Task。
- **T16-82 建議：** 從新 vtable `0x00C2DBAC` 的事件處理 entry 與 `0x630A50` 綁定的三個控件出發，定位實際 click callback；並雙線從 Quest cache writer 或 T02 訊息 dispatcher 追到真正任務業務協定。對這些未知不得引用本地化訊息表 ID 冒充 wire opcode。

## 7. 交付與 Git

完整技術原稿僅提交 `kr-temp-roy/`，不更動 owner、catalog、其他 Task 或任何 KR 二進位。若本次產生後續修正版，保持舊原稿並以勘誤追加，禁止靜默覆寫。

### 0x62E360 event branch (VA `0x0062E360`–`0x0062E378`)

```asm
  62e360:	55                   	push   ebp
  62e361:	8b ec                	mov    ebp,esp
  62e363:	81 7d 08 22 4e 00 00 	cmp    DWORD PTR [ebp+0x8],0x4e22
  62e36a:	75 0a                	jne    0x62e376
  62e36c:	56                   	push   esi
  62e36d:	8d 75 08             	lea    esi,[ebp+0x8]
  62e370:	e8 7b 23 00 00       	call   0x6306f0
  62e375:	5e                   	pop    esi
  62e376:	5d                   	pop    ebp
  62e377:	c2 0c 00             	ret    0xc
```

### 0x6306F0 slot factory and guard CFG (VA `0x006306F0`–`0x006307A5`)

```asm
  6306f0:	55                   	push   ebp
  6306f1:	8b ec                	mov    ebp,esp
  6306f3:	6a ff                	push   0xffffffff
  6306f5:	68 c8 d9 91 00       	push   0x91d9c8
  6306fa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  630700:	50                   	push   eax
  630701:	51                   	push   ecx
  630702:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  630707:	33 c5                	xor    eax,ebp
  630709:	50                   	push   eax
  63070a:	8d 45 f4             	lea    eax,[ebp-0xc]
  63070d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  630713:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  630716:	85 c0                	test   eax,eax
  630718:	74 7c                	je     0x630796
  63071a:	83 38 00             	cmp    DWORD PTR [eax],0x0
  63071d:	75 63                	jne    0x630782
  63071f:	81 7e 04 2d 01 00 00 	cmp    DWORD PTR [esi+0x4],0x12d
  630726:	74 0e                	je     0x630736
  630728:	6a 00                	push   0x0
  63072a:	68 c0 1f bf 00       	push   0xbf1fc0
  63072f:	68 78 20 bf 00       	push   0xbf2078
  630734:	eb 58                	jmp    0x63078e
  630736:	68 54 02 00 00       	push   0x254
  63073b:	e8 28 19 26 00       	call   0x892068
  630740:	83 c4 04             	add    esp,0x4
  630743:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  630746:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  63074d:	85 c0                	test   eax,eax
  63074f:	74 1b                	je     0x63076c
  630751:	8b c8                	mov    ecx,eax
  630753:	e8 78 02 00 00       	call   0x6309d0
  630758:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  63075b:	89 01                	mov    DWORD PTR [ecx],eax
  63075d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  630760:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  630767:	59                   	pop    ecx
  630768:	8b e5                	mov    esp,ebp
  63076a:	5d                   	pop    ebp
  63076b:	c3                   	ret
  63076c:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  63076f:	33 c0                	xor    eax,eax
  630771:	89 01                	mov    DWORD PTR [ecx],eax
  630773:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  630776:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  63077d:	59                   	pop    ecx
  63077e:	8b e5                	mov    esp,ebp
  630780:	5d                   	pop    ebp
  630781:	c3                   	ret
  630782:	6a 00                	push   0x0
  630784:	68 c0 1f bf 00       	push   0xbf1fc0
  630789:	68 c8 20 bf 00       	push   0xbf20c8
  63078e:	6a 00                	push   0x0
  630790:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  630796:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  630799:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6307a0:	59                   	pop    ecx
  6307a1:	8b e5                	mov    esp,ebp
  6307a3:	5d                   	pop    ebp
  6307a4:	c3                   	ret
```

### 0x6309D0 initialized inner UI object (VA `0x006309D0`–`0x00630A48`)

```asm
  6309d0:	55                   	push   ebp
  6309d1:	8b ec                	mov    ebp,esp
  6309d3:	6a ff                	push   0xffffffff
  6309d5:	68 68 9c 91 00       	push   0x919c68
  6309da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6309e0:	50                   	push   eax
  6309e1:	51                   	push   ecx
  6309e2:	56                   	push   esi
  6309e3:	57                   	push   edi
  6309e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6309e9:	33 c5                	xor    eax,ebp
  6309eb:	50                   	push   eax
  6309ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  6309ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6309f5:	8b f1                	mov    esi,ecx
  6309f7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  6309fa:	e8 81 3e 12 00       	call   0x754880
  6309ff:	33 ff                	xor    edi,edi
  630a01:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  630a07:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  630a0a:	50                   	push   eax
  630a0b:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  630a11:	e8 0a ab 14 00       	call   0x77b520
  630a16:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  630a1d:	c7 06 ac db c2 00    	mov    DWORD PTR [esi],0xc2dbac
  630a23:	89 be 48 02 00 00    	mov    DWORD PTR [esi+0x248],edi
  630a29:	89 be 4c 02 00 00    	mov    DWORD PTR [esi+0x24c],edi
  630a2f:	89 be 50 02 00 00    	mov    DWORD PTR [esi+0x250],edi
  630a35:	8b c6                	mov    eax,esi
  630a37:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  630a3a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  630a41:	59                   	pop    ecx
  630a42:	5f                   	pop    edi
  630a43:	5e                   	pop    esi
  630a44:	8b e5                	mov    esp,ebp
  630a46:	5d                   	pop    ebp
  630a47:	c3                   	ret
```

### 0x630A50 three child-control slots (VA `0x00630A50`–`0x00630B27`)

```asm
  630a50:	53                   	push   ebx
  630a51:	56                   	push   esi
  630a52:	8b f0                	mov    esi,eax
  630a54:	57                   	push   edi
  630a55:	8d be 48 02 00 00    	lea    edi,[esi+0x248]
  630a5b:	8b ce                	mov    ecx,esi
  630a5d:	e8 ce 00 00 00       	call   0x630b30
  630a62:	8d 9e 4c 02 00 00    	lea    ebx,[esi+0x24c]
  630a68:	68 08 52 00 00       	push   0x5208
  630a6d:	8b fb                	mov    edi,ebx
  630a6f:	8b ce                	mov    ecx,esi
  630a71:	e8 7a ac e3 ff       	call   0x46b6f0
  630a76:	8d be 50 02 00 00    	lea    edi,[esi+0x250]
  630a7c:	68 d0 52 00 00       	push   0x52d0
  630a81:	8b ce                	mov    ecx,esi
  630a83:	e8 68 ac e3 ff       	call   0x46b6f0
  630a88:	8b 33                	mov    esi,DWORD PTR [ebx]
  630a8a:	83 c4 08             	add    esp,0x8
  630a8d:	68 6b bf 00 00       	push   0xbf6b
  630a92:	b8 02 00 00 00       	mov    eax,0x2
  630a97:	8b ce                	mov    ecx,esi
  630a99:	e8 12 3a 11 00       	call   0x7444b0
  630a9e:	c6 86 a4 00 00 00 01 	mov    BYTE PTR [esi+0xa4],0x1
  630aa5:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  630aa7:	80 bb a4 00 00 00 00 	cmp    BYTE PTR [ebx+0xa4],0x0
  630aae:	74 27                	je     0x630ad7
  630ab0:	83 bb 94 00 00 00 00 	cmp    DWORD PTR [ebx+0x94],0x0
  630ab7:	74 1e                	je     0x630ad7
  630ab9:	8b 8b 94 00 00 00    	mov    ecx,DWORD PTR [ebx+0x94]
  630abf:	8b 01                	mov    eax,DWORD PTR [ecx]
  630ac1:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  630ac4:	ff d2                	call   edx
  630ac6:	3d 6b bf 00 00       	cmp    eax,0xbf6b
  630acb:	75 0a                	jne    0x630ad7
  630acd:	8b 83 94 00 00 00    	mov    eax,DWORD PTR [ebx+0x94]
  630ad3:	c6 40 4c 01          	mov    BYTE PTR [eax+0x4c],0x1
  630ad7:	8b 37                	mov    esi,DWORD PTR [edi]
  630ad9:	68 6b bf 00 00       	push   0xbf6b
  630ade:	b8 02 00 00 00       	mov    eax,0x2
  630ae3:	8b ce                	mov    ecx,esi
  630ae5:	e8 c6 39 11 00       	call   0x7444b0
  630aea:	c6 86 a4 00 00 00 01 	mov    BYTE PTR [esi+0xa4],0x1
  630af1:	8b 3f                	mov    edi,DWORD PTR [edi]
  630af3:	80 bf a4 00 00 00 00 	cmp    BYTE PTR [edi+0xa4],0x0
  630afa:	74 27                	je     0x630b23
  630afc:	83 bf 94 00 00 00 00 	cmp    DWORD PTR [edi+0x94],0x0
  630b03:	74 1e                	je     0x630b23
  630b05:	8b 8f 94 00 00 00    	mov    ecx,DWORD PTR [edi+0x94]
  630b0b:	8b 11                	mov    edx,DWORD PTR [ecx]
  630b0d:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  630b10:	ff d0                	call   eax
  630b12:	3d 6b bf 00 00       	cmp    eax,0xbf6b
  630b17:	75 0a                	jne    0x630b23
  630b19:	8b 8f 94 00 00 00    	mov    ecx,DWORD PTR [edi+0x94]
  630b1f:	c6 41 4c 01          	mov    BYTE PTR [ecx+0x4c],0x1
  630b23:	5f                   	pop    edi
  630b24:	5e                   	pop    esi
  630b25:	5b                   	pop    ebx
  630b26:	c3                   	ret
```

### 0x630B30 first child type verifier (VA `0x00630B30`–`0x00630BB5`)

```asm
  630b30:	55                   	push   ebp
  630b31:	8b ec                	mov    ebp,esp
  630b33:	83 ec 20             	sub    esp,0x20
  630b36:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  630b3b:	33 c5                	xor    eax,ebp
  630b3d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  630b40:	56                   	push   esi
  630b41:	8b f1                	mov    esi,ecx
  630b43:	68 6c 52 00 00       	push   0x526c
  630b48:	e8 f3 5d 11 00       	call   0x746940
  630b4d:	8b f0                	mov    esi,eax
  630b4f:	85 f6                	test   esi,esi
  630b51:	75 52                	jne    0x630ba5
  630b53:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  630b58:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  630b5d:	8d 75 e0             	lea    esi,[ebp-0x20]
  630b60:	e8 1b 3f dd ff       	call   0x404a80
  630b65:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  630b68:	be 08 00 00 00       	mov    esi,0x8
  630b6d:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  630b70:	73 03                	jae    0x630b75
  630b72:	8d 45 e0             	lea    eax,[ebp-0x20]
  630b75:	6a 00                	push   0x0
  630b77:	68 c0 1f bf 00       	push   0xbf1fc0
  630b7c:	50                   	push   eax
  630b7d:	6a 00                	push   0x0
  630b7f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  630b85:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  630b88:	72 7f                	jb     0x630c09
  630b8a:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  630b8d:	50                   	push   eax
  630b8e:	e8 79 06 26 00       	call   0x89120c
  630b93:	83 c4 04             	add    esp,0x4
  630b96:	5e                   	pop    esi
  630b97:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  630b9a:	33 cd                	xor    ecx,ebp
  630b9c:	e8 60 04 26 00       	call   0x891001
  630ba1:	8b e5                	mov    esp,ebp
  630ba3:	5d                   	pop    ebp
  630ba4:	c3                   	ret
  630ba5:	8b 16                	mov    edx,DWORD PTR [esi]
  630ba7:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  630baa:	8b ce                	mov    ecx,esi
  630bac:	ff d0                	call   eax
  630bae:	3d c8 00 00 00       	cmp    eax,0xc8
  630bb3:	74 52                	je     0x630c07
```
