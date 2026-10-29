# T16-103 — KR handler table 的全域預設項目、索引佈局與活動接收者 (BIN-first)

研究者 `chatgpt-web roy`；實際產生時間 `2026-10-28T23:46:15.531960+08:00`，原件唯讀。研究對象 T16，KR。

## 0. 來源與同步狀態

- 原始 `Tartaros.bin`：`12,472,320` bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `.text` VA = raw `+0x00400C00`；下列 `objdump` 逐段由原始 BIN 產生，僅已定位指令邊界可作確認。對所有機器碼 fragment 列出 VA，可用 `VA-0x400C00` 重取原始位元組。
- 啟動前 GitHub `main` 包含於 `t16/roy/chatgpt-web`（compare ahead=15、behind=0），故沒有新 Merge Commit；此分支已保留 T16-102，待本段完成才新增研究原稿。
- 依 02 共用 FULL-PASS 准入原則，這是**第一手原生局部證據**，不自稱 T01 FULL-PASS／完整 wire protocol。T02 仍負責 socket/framing。

## 1. 研究問題與重要結果

T16-102 證明 `0x4ADF3D` 將 `0x4B2190` 登記到 `+0x214`，但沒證明註冊表的配置與調度來源。本段**首次從原生 BIN 確認表格一律按 8-byte entry 初始化：`0x4ADD50` 循環 `0xBD5` 次，預設 handler 為 `0x4B7D40`，配對的 context 值為 `0xBF2375`；同一結構的專用 slot `+0x214` / `+0x218` 分別保存 `0x4B2190` 與 context。** `+0x214=4+8*66`，因此它是表格中 **index 66 的 callable field**，不是已證實的原版 wire opcode 0x214 / 0x42。

第二項新證據是 `0x4B9129` 從 constructor `0x4ADD50` 建立大型接收者，並且 `0x4B7D50` 在替換 owner 的 `[+0x5EAC]` 活動接收物件時，先釋放舊接收者，再呼叫新接收者 vtable `+0x10`。`0x4B7EC0` 是另一個 **default handler / active-forwarding** 路徑：有活動接收者時尾呼叫其 vtable `+4`，沒有則傳入 `[ebp+0x10]` 的 16-bit 值到錯誤通報器。這能說明 callback 表與多型接收對象之間的介面，但**仍未找到從 socket frame index 到 slot 66 的已證直接消費路徑**。

## 2. 第一輪 T16-103：表格尺寸、固定 stride、callable/context 配對

- `0x4ADD50`: `EDX=EAX+8`；`ESI=0xBD5`；每輪 `mov [edx-4], 0x4B7D40`、`mov [edx],0xBF2375`、`edx+=8`。根據精確指令，第一個 function field 在 `[base+4]`，其後 context field `[base+8]`；後續每 8 bytes 重複。這是函式/上下文配對初始化，不代表所有索引實際啟用或線上表的長度。
- 範圍內 0xBD5 個 entry，重複初始化觸及 `[base+4]` 到 `[base+0x5EA8]`；`0xBD5*8=0x5EA8`，需配合 object size 另有 vptr/header 的可能；不能將這個乘積直接當成物件完整配置大小。
- `0x4ADF3D` 寫 `base+0x214`，`0x4ADF47` 寫 `base+0x218`；`0x214-4=0x210`，除以 8 得 66。`+0x20C` 是另一個 function field `0x4B2310`，對應 index 65；`+0x21C` 另為 index 67 的 `0x4B1A90`。三個索引相鄰，證明這些寫入在同一 stride 域，不能直接當封包號碼。
- `0x4B9129` 直接 call `0x4ADD50`；成功分支隨後設置物件 vptr `0x00C06F7C`、更新 `[0xD6A674]` signature，並將此物件交給 `0x4B7D50`；其餘不同分支亦呼叫相同 constructor，故需分清 receiver variant。

## 3. 第二輪 T16-103-2：活動 receiver 的替換與 default forwarding

- `0x4B7D50` 使用 `ESI+0x5EAC` 保存活動 receiver。若非空，先對舊 receiver vtable `+0x14` 呼叫，再對同指標 vtable `+0` 呼叫（push 1），然後把欄位清零；新值 `EDI` 寫入 `[ESI+0x5EAC]`，隨後透過新 receiver vtable `+0x10` 執行初始化或啟用相關方法。這是**狀態替換與多型通知**，不能直接推為業務封包送出。
- `0x4B7EC0` 是另個有界 consumer：若 `[ECX+0x5EAC] != 0`，將 `ECX` 換成活動 receiver，取其 vtable `+4` tail-jump；沒有活動 receiver 時將第三參數（`[EBP+0x10]`）的 signed 16-bit value 傳至 `0x6EDB60` 錯誤處理後返回 `0`。這與 `0x4B7D50` 的相同欄位相互支持。
- `0x4BBB70` constructor 亦呼叫 `0x4ADD50`，其後設置 vptr `0xC06FB0`；`0x4BBBA0` 初始化 `receiver+0x5EAC` 相關範圍並登記其他 callable/context 項，證實多個 receiver variant 可沿共同表格作擴展；不能把 `0xC06F7C` 和 `0xC06FB0` 視為同一型別。
- 原生 `0x4B2190` length gate / subtype 仍依 T16-102，這裡僅引用少量 BIN 片段供交叉核對，不用 subtype 1..11 擅稱 Quest state / wire opcode。

## 4. 有界偽碼與型別界線

```cpp
struct CallbackEntry {
    void* callable;   // entry at base+4+8*i; function is receiver/interface specific
    void* context;    // entry at base+8+8*i; type currently unconfirmed
};
void initReceiverTable(uint8_t* base) {
    for (unsigned i=0;i<0xBD5;i++) {
        store32(base+4+8*i, 0x004B7D40);
        store32(base+8+8*i, 0x00BF2375);
    }
    store32(base+0x214,0x004B2190); // index=66, overwritten later in same init
    // many more specialized slot writers omitted
}
void setActiveReceiver(Owner* owner, Receiver* next) {
    auto old = *(Receiver**)((uint8_t*)owner+0x5EAC);
    if (old) { old->vcall_14(); old->vcall_00(1); }
    *(Receiver**)((uint8_t*)owner+0x5EAC) = next;
    next->vcall_10();
}
```

*註：以上是局部資料流的結構化表示，函式型別、物件關係、context 是推論性命名；`0x4ADD50` 初始化後有許多覆寫，專用 slot `0x214` 已由原生寫入證實。未證某個 frame 的 index 等於 66。*

## 5. 三輪門檻／反證紀錄

- 第一輪 T16-103：從 BIN 確立 0xBD5 個 8-byte pair 初始化、函式 field/context field、slot 66 定位，是舊研究所缺的**具體佈局重大發現**。
- 第二輪 T16-103-2：擴展至 `0x4B9129` 建構 variant、`0x4B7D50` active receiver writer、`0x4B7EC0` read/forward，達成有界 owner-to-consumer 閉合。
- 第三輪 T16-103-3：**未啟動**，前兩輪已達重大新發現與完整有界功能鏈門檻。此停止條件不代表 S→C opcode、Quest16→15 或 socket handler 已驗收。
- 索引 66 是內部陣列表格索引；並無 frame bytes 驗證其實際封包域。不能從 0x214／8 命名 wire command。
- `0x4B2190` 會寫入 `[FAB134]` 的記錄資料，`0x500E00` 會讀取；兩者因接收時序與 register domain 尚未核證，**不能**說已找到完整 Server→Client Quest state writer。

## 6. 玩家情境與尚缺資料

| 玩家情境 | C→S | S→C | Client已確認 | Client待逆向 | Server待開發／跨功能／待遊玩 |
|---|---|---|---|---|---|
| 建立大型接收 dispatcher | unknown | unknown | 0xBD5 entry stride=8；slot 66 註冊 0x4B2190 | 表格 index 來源與網路 framing | 不推定協定數值 |
| 接收者切換／啟動 | unknown | unknown | 0x4B7D50 `+0x5EAC` writer 與 virtual +0x10 | caller 的業務事件與 server 關聯 | 待整合、待遊玩驗證 |
| handler 解析 record subtype | unknown | **尚無已驗 wire opcode** | 0x4B2190 → 0x53D840 → [FAB134] writer；0x500E00 reader（前段已證） | index 66 如何被真正 dispatcher 呼叫 | server相容介面需等 parser/字段確認 |
| Quest16 完成後 Quest15 顯示／接取 | unknown | unknown | 無法連到此表證明該行為 | request/response、UI writer 尚未閉合 | server判定規則待開發；UI待驗 |

## 7. 後續 T16-104

1. 先定位索引讀取者：從 `0x4ADD50` 生成的 receiver table 消費路徑和 `0x4B7D40/0x4B7EC0` vtable dispatch 搜尋，驗證傳入 handler 的前三參數來源；不要把初始化表覆寫當作 dispatch 消費。
2. 查 `0x4B2190` 的 `data`、length 由哪個 receive-decode branch 傳入，確認 16-bit key 與 subtype data 的原始 wire mapping。
3. 追 `[FAB134]` 到 `0x500E00` 的 UI 具體控件與 Quest16/15 對應；無法閉合者明列 Client 待逆向而不是原版不存在。

## 8. 原始 BIN 組語附錄（精確 VA/raw）

每組均以原始檔 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 取得。若切在資料或指令中間，僅引有明確完整指令的列；`0x4ADD50` 與專用欄位初始化所在區域跨數個函式功能段。

### Callback table allocation, initialization and 0xBD5 entries — VA `0x004add50`，raw `0x000ad150`

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
```

### Handler registration for +0x214, surrounding slots — VA `0x004adf1d`，raw `0x000ad31d`

```asm
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
```

### Object factory and receiver installation — VA `0x004b90df`，raw `0x000b84df`

```asm
  4b90df:	68 54 bd 00 00       	push   0xbd54
  4b90e4:	e8 7f 81 3d 00       	call   0x891268
  4b90e9:	83 c4 04             	add    esp,0x4
  4b90ec:	85 c0                	test   eax,eax
  4b90ee:	74 07                	je     0x4b90f7
  4b90f0:	e8 7b 2a 00 00       	call   0x4bbb70
  4b90f5:	eb 02                	jmp    0x4b90f9
  4b90f7:	33 c0                	xor    eax,eax
  4b90f9:	8b f8                	mov    edi,eax
  4b90fb:	8b f3                	mov    esi,ebx
  4b90fd:	e8 4e ec ff ff       	call   0x4b7d50
  4b9102:	e8 99 ba f4 ff       	call   0x404ba0
  4b9107:	c7 80 a8 69 00 00 07 	mov    DWORD PTR [eax+0x69a8],0x7
  4b910e:	00 00 00 
  4b9111:	e9 ab 00 00 00       	jmp    0x4b91c1
  4b9116:	68 54 bd 00 00       	push   0xbd54
  4b911b:	e8 48 81 3d 00       	call   0x891268
  4b9120:	8b f0                	mov    esi,eax
  4b9122:	83 c4 04             	add    esp,0x4
  4b9125:	85 f6                	test   esi,esi
  4b9127:	74 25                	je     0x4b914e
  4b9129:	e8 22 4c ff ff       	call   0x4add50
  4b912e:	c7 06 7c 6f c0 00    	mov    DWORD PTR [esi],0xc06f7c
  4b9134:	c7 05 74 a6 d6 00 55 	mov    DWORD PTR ds:0xd6a674,0x44535155
  4b913b:	51 53 44 
  4b913e:	e8 5d 23 00 00       	call   0x4bb4a0
  4b9143:	8b fe                	mov    edi,esi
  4b9145:	8b f3                	mov    esi,ebx
  4b9147:	e8 04 ec ff ff       	call   0x4b7d50
  4b914c:	eb 73                	jmp    0x4b91c1
  4b914e:	33 f6                	xor    esi,esi
  4b9150:	8b fe                	mov    edi,esi
  4b9152:	8b f3                	mov    esi,ebx
  4b9154:	e8 f7 eb ff ff       	call   0x4b7d50
```

### Active receiver selection and virtual call — VA `0x004b7d50`，raw `0x000b7150`

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

### Default table function and fallback — VA `0x004b7ec0`，raw `0x000b72c0`

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
  4b7eef:	c2 0c 00             	ret    0xc
```

### Receiver constructor extension — VA `0x004bbb70`，raw `0x000baf70`

```asm
  4bbb70:	56                   	push   esi
  4bbb71:	8b f0                	mov    esi,eax
  4bbb73:	e8 d8 21 ff ff       	call   0x4add50
  4bbb78:	c7 06 b0 6f c0 00    	mov    DWORD PTR [esi],0xc06fb0
  4bbb7e:	c7 05 74 a6 d6 00 52 	mov    DWORD PTR ds:0xd6a674,0x53515552
  4bbb85:	55 51 53 
  4bbb88:	e8 13 00 00 00       	call   0x4bbba0
  4bbb8d:	8b c6                	mov    eax,esi
  4bbb8f:	5e                   	pop    esi
  4bbb90:	c3                   	ret
  4bbb91:	cc                   	int3
  4bbb92:	cc                   	int3
  4bbb93:	cc                   	int3
  4bbb94:	cc                   	int3
  4bbb95:	cc                   	int3
  4bbb96:	cc                   	int3
  4bbb97:	cc                   	int3
  4bbb98:	cc                   	int3
  4bbb99:	cc                   	int3
  4bbb9a:	cc                   	int3
  4bbb9b:	cc                   	int3
  4bbb9c:	cc                   	int3
  4bbb9d:	cc                   	int3
  4bbb9e:	cc                   	int3
  4bbb9f:	cc                   	int3
  4bbba0:	68 a8 5e 00 00       	push   0x5ea8
  4bbba5:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4bbbab:	6a 00                	push   0x0
  4bbbad:	50                   	push   eax
  4bbbae:	e8 ad 2c 3e 00       	call   0x89e860
  4bbbb3:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4bbbb8:	83 c4 0c             	add    esp,0xc
  4bbbbb:	c7 86 a4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fa4],0x4c5c50
  4bbbc2:	5c 4c 00 
  4bbbc5:	89 86 a8 5f 00 00    	mov    DWORD PTR [esi+0x5fa8],eax
  4bbbcb:	c7 86 d4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fd4],0x4c5c50
  4bbbd2:	5c 4c 00 
  4bbbd5:	89 86 d8 5f 00 00    	mov    DWORD PTR [esi+0x5fd8],eax
  4bbbdb:	c7 86 ec 61 00 00 50 	mov    DWORD PTR [esi+0x61ec],0x4bc050
  4bbbe2:	c0 4b 00 
  4bbbe5:	89 86 f0 61 00 00    	mov    DWORD PTR [esi+0x61f0],eax
  4bbbeb:	c7 86 fc 61 00 00 a0 	mov    DWORD PTR [esi+0x61fc],0x4bbfa0
  4bbbf2:	bf 4b 00 
  4bbbf5:	89 86 00 62 00 00    	mov    DWORD PTR [esi+0x6200],eax
  4bbbfb:	c7 86 04 62 00 00 e0 	mov    DWORD PTR [esi+0x6204],0x4bbae0
  4bbc02:	ba 4b 00 
  4bbc05:	89 86 08 62 00 00    	mov    DWORD PTR [esi+0x6208],eax
  4bbc0b:	c3                   	ret
```

### Handler byte-length / subtype gate — VA `0x004b220b`，raw `0x000b160b`

```asm
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
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
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
  4b2278:	f6       	test   BYTE PTR ds:0xfab22c,0x1
```