# T16-104 — KR 兩套 handler 表隔離、實際 parser 參數與全域 callback 範圍（BIN-first）

研究者 `chatgpt-web roy`；時間 `2026-10-28T23:49:43+08:00`；範圍 T16/KR，唯讀檔案分析。

## 0. Git 同步及第一手來源

- 啟動時 GitHub `main=baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，`main...t16/roy/chatgpt-web` 為 ahead=16、behind=0，已包含 main，不需製造新的 merge commit。
- KR `Tartaros.bin`: bytes=12,472,320，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。KR `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `.text` VA 到 raw：`raw=VA-0x00400C00`。以下引用由原始 BIN `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 靜態反組譯，切取定位區域；指令與 offset 必須按所示字節重新核對。未執行/注入/修改程式、未擷取封包。
- T16-102/103 與 GitHub T16 分支只做導航。共用 T01 FULL-PASS 審核狀態不會因本分析自動升級。

## 1. 本次研究問題及結論範圍

T16-103 證明 receiver object constructor `0x4ADD50` 配置內嵌 `0xBD5` 個 8-byte callback/context 配對，索引 66 寫 `0x4B2190`。本段追加一條**先前尚未分辨的獨立全域 callback table**：`0x4B7DC0` 從 `0xFD2CFC` 開始寫入另一組 8-byte 配對，預設 callable 是 **`0x4B7EC0`**，與 receiver-object table 預設 callable **`0x4B7D40`** 不同。兩張表長度與元素佈局相近不等於同一表，不能將全域表與物件內嵌表 slot 混用。

獨立確證 `0x4B2190` 的 C 風格參數界面：`[ebp+8]` 指向至少包含 little-endian 16-bit 欄位的輸入緩衝，`[ebp+0xc]` 當資料長度／剩餘界線，後段 `[ebp+0x10]` 尚未於此片段直接使用。subtype 從 `input[5]` 取得（先 `esi=input`, `eax=esi+4`, `movzx ecx,[eax+1]`），減 1 後限定 0..10；不能以目前證據將它命名為 wire 協定 subtype 或 Quest 狀態。`0x4B22BC` 將資料交 `0x53D840`，可接先前 `[FAB134]` 記錄讀寫證據，但輸入自 receive frame 的路徑未閉合。

### 證據等級

- **原生確認**：兩組 table 的基址、預設 callable、8-byte stride、`0x4B2190` 參數資料存取、其長度 gate / subtype 跳表 / writer call。
- **部分確認**：`0x4B2190 → 0x53D840 → [FAB134]` 可寫執行期資料，且 `0x500E00` 另行讀取；動態更新的具體玩家情境未知。
- **尚待驗證**：兩張表各自的真正 runtime dispatch caller、如何選出 index=66、receive framing、wire opcode、Quest16→Quest15 接取/解鎖。

## 2. 第一輪 T16-104：獨立全域表與兩種預設入口

- 內嵌表：`0x4ADD50`，以 `EAX` 物件基址、`EDX=EAX+8`、`ESI=0xBD5` 迴圈；`[edx-4]=0x4B7D40`, `[edx]=0xBF2375`。第 i 個 callback `[obj+4+8*i]`；第 i 個配對 context `[obj+8+8*i]`。
- 全域表：`0x4B7DC0`，`EAX=0xFD2D00`、`EDX=0x4B7EC0`、`ECX=0xBF2375`。每一輪 `[eax-4]=edx`, `[eax]=ecx`, `eax+=8`，直到 `eax>=0xFD8BA8`。第一個 callable 位址 `0xFD2CFC`，context 位址 `0xFD2D00`；步幅 8。其末端界線和索引不可拿來推測網路 frame 長度。
- 計算：`0xFD8BA8-0xFD2D00=0x5EA8`，共 `0xBD5 = 3029` 筆。`0xFD8BA8` 是比較的 **next-context-address** 上界，而不是欄位有效載荷本身；全域表第 0 項位址 `0xFD2CFC`，不應從 `0xFD2D00` 當第一個 callable。
- 完成預設初始化後，寫入多個 explicit handler，例如 `[0xFD2D0C]=0x4B7F00`，`[0xFD8B8C]=0x4B8DC0`，`[0xFD2FFC]=0x4B8F50`。這是全域表的**真實覆寫**，不證明 `0x4B2190` 位於該全域表。
- `0x4B7D40` 是 `mov eax,[ecx]; jmp [eax+0xc]`，屬使用輸入物件 vtable 的 trampoline；`0x4B7EC0` 則查看 `[ecx+0x5EAC]`，有 active receiver 時 `jmp [vtable+4]`，沒有時呼叫 `0x6EDB60` 回 0。因此雖有相同的 context 常數，預設行為有重大差異。

## 3. 第二輪 T16-104-2：parser 參數、長度及錯誤路徑

- `0x4B2190`（`ret 0xC`）採三個 stack 參數，於 `[ebp+8]` 得 input pointer，`[ebp+0xC]` 得長度/界線。`input[2:4]` 以 signed 16-bit 給 `0x500110` 前的 selector，對應 Quest 靜態 owner initialization 的 lazy guard，但不表示 input 是 Quest 封包。
- `0x4B2210` 檢查 length 必須 `>4`，`0x4B2220` 取 `input[5]`，`0x4B2223` 減 1，`0x4B2228` 檢查 `<=10`；合法時以 `0x4B22E0` 的 jump table 分支。失敗會走 `0x4B22C6` 返回。
- 跳表分支調整 `EAX`（payload cursor）和 `EBX`（消費長度），比較 `EBX <= EDI`；若越界 `0x4B2266` 會走 error reporter。這是**局部 parser 的有界長度管理**，不是整個 socket framing 的格式。
- `0x4B2273` 若 subtype 記錄的 byte 為 `9`，重新進入檢查迴圈；否則 lazy init `[0xFAB22C]`，再 `0x4B22BC call 0x53D840`。該函式如何將資料寫至 `0x18`-byte 記錄見 T16-101。對輸入與輸出長度格式仍需完整逐 subtype 列表。
- 「三個參數」是 `ret 0xC` 所反映的呼叫慣例；第三個來源與語意仍 unknown，不能由其存在推測時間戳或 opcode。

## 4. 第二輪反例控制：另一處 8-byte pair 並非同一 handler table

`0x4BA790` 也用 `[EAX+ESI*8]` 與 `[EAX+ESI*8+4]` 取值，但其資料來自 `[EDI+0x5EE8]`～`[EDI+0x5EEC]` 之間的**動態 pair vector**，取出後向 `0x7A7510` 傳入。這示範 8-byte stride 並不專屬於 callback table。若只搜尋 `*8+4` 很容易把其他容器誤當 T16 的 slot-66 調度。特定內容無法確認與 Quest 業務有關，因此僅作 bounded negative control。

## 5. 有界偽碼

```cpp
// Evidence-only schematic, not recovered original class definitions.
struct Entry { uint32_t callback; uint32_t ctx; };
void initReceiverTable(uint8_t* receiver) {
  for (uint32_t i=0; i<0xBD5; i++) {
    store32(receiver+4+8*i,0x004B7D40);
    store32(receiver+8+8*i,0x00BF2375);
  }
  // Receiver specialization later sets callback at receiver+0x214 to 0x4B2190.
}
void initGlobalDefaultTable() {
  for (uint32_t p=0x00FD2D00; p<0x00FD8BA8; p+=8) {
    store32(p-4,0x004B7EC0);
    store32(p,0x00BF2375);
  }
  store32(0x00FD2D0C,0x004B7F00);
  // Other explicit global overrides omitted.
}
int parseRecord(const uint8_t* input, size_t length, void* thirdUnknown) {
  if (length <= 4) return 0;
  uint8_t sub = input[5];
  if (sub < 1 || sub > 11) return 0;
  // per-subtype size branch and bounded writer sequence; exact full switch not reproduced here
  return 0;
}
```

## 6. 玩家情境與收發、缺口矩陣

| 玩家情境 | Client 本地條件/證據 | C→S | S→C 業務 parser | Client 寫入及可見效果 | 分類 |
|---|---|---|---|---|---|
| 建立接收/回覆物件 | `0x4ADD50` 內嵌 3029 個 callback/context entry；slot 66 可特化 | unknown | 尚未證實與網路相連 | 建立 callback 表，UI unknown | 原生確認局部，跨功能待整合 |
| 建立全域預設 receiver 表 | `0x4B7DC0` 在 `0xFD2CFC` 另設預設 trampoline 並覆寫特定項 | unknown | 索引來源 unknown | 活動 receiver 可有多型轉發 | 原生確認局部，Client 待逆向 |
| 處理包含記錄 subtype 的 input | `0x4B2190` 的 input, length, 11-way selector -> `0x53D840` | unknown | 已知 bounded local parser；wire domain unknown | 寫 `[FAB134]` 相關記錄，`0x500E00` 另行消費；畫面效果 unknown | 部分確認，Client 待逆向 |
| Quest16 完成→Quest15 可接→玩家接取 | unknown | opcode/欄位/時序 unknown | Quest opcode/handler unknown | 本地 Quest/UI state 未閉合 | Client 待逆向、Server 待開發、待遊玩驗證 |

## 7. 三輪深入門檻及反證

- **第一輪 T16-104**：找到與先前 receiver-object table 並列的獨立全域 0xBD5-entry 表、精確基址/上界及不同 default callback，是先前缺少的具體 owner/dispatch 佈局新原生證據。
- **第二輪 T16-104-2**：驗證 `0x4B2190` input 的 buffer/length/subtype 欄位與 `0x53D840` writer，並以 `0x4BA790` 8-byte vector 作防誤認反例；已達有界新功能關係門檻。
- **第三輪 T16-104-3**：未啟動，前兩輪已取得可核證實質發現。停止不意味 socket → table → Quest UI 全鏈完成。
- 未確認：沒有找到 decoder 使用封包內欄位選取 `receiver+4+8*66` 的具體原始指令；尚未把 `0x4B2190` 鎖定為 Quest S→C handler。
- 不將 `[0xFAB134]` 執行期記錄中的任何 key/selector 直接推成 Quest16/Quest15 任務前置值；需要 KR `QuestInfo.xml` 與實際 receive path 的證據。

## 8. T16-105 後續必要入口

1. 搜尋以 receiver object 為 base、索引乘 8 並讀取 `+4` callback／`+8` ctx 的動態 consumer，確認其來源是 receive frame 的解碼索引或不同 UI callback domain。
2. 針對 `0x4B2190` 的前兩參數，逆向追蹤實際 caller 封包內容與 framing；與 T02 已經確認的 socket parser 接口對照。
3. 追 `0x53D840` 寫後的 `[FAB134]` record 是否進入 Quest UI 的即時 refresh call；不把只有讀取的列表推斷為事件觸發。
4. 嘗試建立 Quest16→Quest15 接取／交付的 C→S producer 和 S→C writer 雙向完整玩家情境。

## 9. 逐段原始 BIN 反組譯摘錄

以下所有 VA 均以 `raw=VA-0x400C00` 取原始機器碼。raw 取樣：`0x4B7DC0→0x000B71C0`、`0x4B2190→0x000B1590`、`0x4ADD50→0x000AD150`；不將跳表當作 code。

### object_table_constructor — VA 0x004add50 至 0x004addac / raw 0x000ad150

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
```

### slot_66_registration — VA 0x004adf28 至 0x004adf54 / raw 0x000ad328

```asm
  4adf28:	88 a8 01 00 00 c7    	mov    BYTE PTR [eax-0x38ffffff],ch
  4adf2e:	80 c4 01             	add    ah,0x1
  4adf31:	00 00                	add    BYTE PTR [eax],al
  4adf33:	f0 1b 4b 00          	lock sbb ecx,DWORD PTR [ebx+0x0]
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	   
```

### global_table_init — VA 0x004b7dc0 至 0x004b7e80 / raw 0x000b71c0

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7 05 e4 31 fd 00 60 	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	9c 4b 00 
  4b7e79:	89 0d e8 31 fd 00    	mov    DWORD PTR ds:0xfd31e8,ecx
  4b7e7f:	c7       	mov    DWORD PTR ds:0xfd34d4,0x4b9d30
  4b7e86:	   
```

### global_default_forwarder — VA 0x004b7ec0 至 0x004b7ef0 / raw 0x000b72c0

```asm
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2               	ret    0xc
```

### receiver_replace — VA 0x004b7d50 至 0x004b7dc0 / raw 0x000b7150

```asm
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```

### parser_packet_arguments — VA 0x004b2190 至 0x004b2240 / raw 0x000b1590

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
```

### parser_loop_and_writer — VA 0x004b2258 至 0x004b22dc / raw 0x000b1658

```asm
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c              	ret    0xc
```

### unrelated_pointer_vector_guard — VA 0x004ba76c 至 0x004ba7c9 / raw 0x000b9b6c

```asm
  4ba76c:	8b 97 ec 5e 00 00    	mov    edx,DWORD PTR [edi+0x5eec]
  4ba772:	2b 97 e8 5e 00 00    	sub    edx,DWORD PTR [edi+0x5ee8]
  4ba778:	33 f6                	xor    esi,esi
  4ba77a:	c1 fa 03             	sar    edx,0x3
  4ba77d:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  4ba781:	85 d2                	test   edx,edx
  4ba783:	74 44                	je     0x4ba7c9
  4ba785:	eb 09                	jmp    0x4ba790
  4ba787:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4ba78e:	8b ff                	mov    edi,edi
  4ba790:	8b 87 e8 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ee8]
  4ba796:	8b 0c f0             	mov    ecx,DWORD PTR [eax+esi*8]
  4ba799:	8b 44 f0 04          	mov    eax,DWORD PTR [eax+esi*8+0x4]
  4ba79d:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4ba7a1:	8b 8b 5c 01 00 00    	mov    ecx,DWORD PTR [ebx+0x15c]
  4ba7a7:	85 c9                	test   ecx,ecx
  4ba7a9:	74 19                	je     0x4ba7c4
  4ba7ab:	83 bb 70 03 00 00 00 	cmp    DWORD PTR [ebx+0x370],0x0
  4ba7b2:	74 10                	je     0x4ba7c4
  4ba7b4:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4ba7b8:	50                   	push   eax
  4ba7b9:	52                   	push   edx
  4ba7ba:	51                   	push   ecx
  4ba7bb:	e8 50 cd 2e 00       	call   0x7a7510
  4ba7c0:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4ba7c4:	46                   	inc    esi
  4ba7c5:	3b f2                	cmp    esi,edx
  4ba7c7:	72 c7                	jb     0x4ba790
```