# KR T16-83 — Quest UI 事件 0xC352 / 0x61A8 的原生型別工廠與資料回填（BIN-first）

- 研究時間：2026-10-28T19:52:12+08:00 Asia/Taipei；分析者：chatgpt-web roy；**KR T16 only**。
- BIN：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `objdump -h` 對應：`.text` VA `0x00401000` / raw `0x400`、size `0x7D01F0`；`.rdata` VA `0x00BD2000` / raw `0x7D0600`；`.data` VA `0x00D61000` / raw `0x95E800`。**僅 `.text` 使用 raw=VA-0x00400C00**。
- 唯讀離線反組譯；未執行、附加、修改客戶端；無原版封包擷取與原版 Server 證據。GitHub T16-82 完整原稿及 T16 正式 scope 已核對。

## 1. 第 1 輪 T16-83：兩個事件值並不直接意味著 Quest 封包

### 1.1 `0x630D50` 精確分支

- `[ebp+8] == 0xC352`：傳入 `&[ebp+8]`（即從第 1 個事件參數起的參數塊）給 `0x45EFE0`，caller 自行 `add esp,4`。
- `[ebp+8] == 0x61A8`：將 `edi = &[ebp+8]`，呼叫 `0x632D70`，結束時恢復 `edi`。兩分支並非互斥跳表，而是順序比較，對各自值走對應入口。
- 事件函式 `ret 0xC`；事件值是**本地事件識別**，未驗證 wire opcode。

### 1.2 `0x45EFE0`：`0xC352` 的有條件物件配置

傳入的 event-block 指標位於 `[ebp+8]`，`ebx=[ebp+8]`；`[ebx+8]` 為 pointer-to-pointer 輸出槽：先驗證槽指標不為零、`*[slot]==0`，再驗證 `[ebx+4] == 0x12D`。通過則以 `push 0x2A0; call 0x892068` 配置物件，`call 0x5D6DD0` 初始化，`mov dword [esi],0xC2296C` 設 vptr，`mov [esi+0x298],0`，最後以 `mov [slot],esi` 回填。配置失敗則回填 null。

slot 既已含物件、type!=0x12D 時走 `0xBD2580` 訊息/錯誤呼叫候選，所用四個 push 與間接 IAT 直接見原生；並**非** Quest ACK。

### 1.3 `0x632D70`：`0x61A8` 的有條件物件配置

使用 `edi=&event parameters`，讀 `[edi+8]` 作輸出槽指標，檢查 `*[slot]==0` 及 `[edi+4]==0xC8`。符合後 `push 0x15C; call 0x892068`，透過 `0x754880` 初始化，設 final vptr `0xC2DD6C`、`word [obj+0x158]=0`，再回填 `*[slot]=obj`。null / mismatch / existing-object 的分支都有原生條件。

**重點新增:** 兩條不同事件均涉及 *typed UI object factory*、型別碼與輸出槽回填，不是已證的 Quest accept/complete packet producer。

### 1.4 有界偽碼

```cpp
void ui_event_dispatch(uint32_t event_id, uint32_t expected_type, void** output_slot) {
    // represents only two checked event values; compiler/calling convention schematic
    if (event_id == 0xC352) factory_0x45EFE0({event_id, expected_type, output_slot});
    if (event_id == 0x61A8) factory_0x632D70({event_id, expected_type, output_slot});
}

// 0x45EFE0: only when output_slot && *output_slot == nullptr && expected_type == 0x12D
// allocate(0x2A0), init 0x5D6DD0, vptr=0xC2296C, member[+0x298]=0, assign slot.
// 0x632D70: only when output_slot && *output_slot == nullptr && expected_type == 0xC8
// allocate(0x15C), init 0x754880, vptr=0xC2DD6C, member[+0x158]=0, assign slot.
```

C++ interface/語意是機器碼的有界描述，不宣稱已知原版類別名。

## 2. 第 1 輪延伸：事件 ID 與 UI 控件查找 namespace 必須分開

- `0x632F30`: 以 `push 0x61A8` 呼叫 `0x746940` 尋找物件；取得 vptr 後呼叫 `vtable+0x04` 的型別查詢，與 `0xC8` 比較；成功才寫入 `*[edi]`。這是另一條 UI 查找/型別驗證路徑，**不是**證實 `0x630D50` 事件直接觸發這個 helper。
- `0x633020`: 以 `0xC350` 查找物件，型別比對 `0x514`。不要混淆 `0xC350` 控件 ID 與 `0xC352` 事件值。
- `0x45F0C0`: 以 `0x7D0` 查找物件、型別比對 `0xC8`。此路徑不等於 `0x45EFE0` 物件工廠，需 caller/xref 連接。
- 三類數值須嚴格分域：**event ID** (`0xC352`, `0x61A8`)、**expected type** (`0x12D`, `0xC8`, `0x514`)、**UI lookup ID** (`0x61A8`, `0xC350`, `0x7D0`)。同一常數在不同程式路徑出現時不能不看資料流便合併語意。

## 3. 原始反組譯與 VA/raw

- `0x630D50 → raw 0x230150`
- `0x632D70 → raw 0x232170`
- `0x45EFE0 → raw 0x5E3E0`
- `0x632F30 → raw 0x232330`
- `0x633020 → raw 0x232420`
- `0x45F0C0 → raw 0x5E4C0`

### event dispatcher: `0x630d50` to `0x630d7f`
```asm
00630d50 <.text+0x22fd50>:
  630d50:	55                   	push   ebp
  630d51:	8b ec                	mov    ebp,esp
  630d53:	81 7d 08 52 c3 00 00 	cmp    DWORD PTR [ebp+0x8],0xc352
  630d5a:	75 0c                	jne    0x630d68
  630d5c:	8d 45 08             	lea    eax,[ebp+0x8]
  630d5f:	50                   	push   eax
  630d60:	e8 7b e2 e2 ff       	call   0x45efe0
  630d65:	83 c4 04             	add    esp,0x4
  630d68:	81 7d 08 a8 61 00 00 	cmp    DWORD PTR [ebp+0x8],0x61a8
  630d6f:	75 0a                	jne    0x630d7b
  630d71:	57                   	push   edi
  630d72:	8d 7d 08             	lea    edi,[ebp+0x8]
  630d75:	e8 f6 1f 00 00       	call   0x632d70
  630d7a:	5f                   	pop    edi
  630d7b:	5d                   	pop    ebp
  630d7c:	c2 0c 00             	ret    0xc
```
### event 0x61A8 factory: `0x632d70` to `0x632e3e`
```asm
00632d70 <.text+0x231d70>:
  632d70:	55                   	push   ebp
  632d71:	8b ec                	mov    ebp,esp
  632d73:	6a ff                	push   0xffffffff
  632d75:	68 18 1d 91 00       	push   0x911d18
  632d7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  632d80:	50                   	push   eax
  632d81:	51                   	push   ecx
  632d82:	56                   	push   esi
  632d83:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  632d88:	33 c5                	xor    eax,ebp
  632d8a:	50                   	push   eax
  632d8b:	8d 45 f4             	lea    eax,[ebp-0xc]
  632d8e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  632d94:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  632d97:	85 c0                	test   eax,eax
  632d99:	0f 84 8f 00 00 00    	je     0x632e2e
  632d9f:	83 38 00             	cmp    DWORD PTR [eax],0x0
  632da2:	75 76                	jne    0x632e1a
  632da4:	81 7f 04 c8 00 00 00 	cmp    DWORD PTR [edi+0x4],0xc8
  632dab:	74 0e                	je     0x632dbb
  632dad:	6a 00                	push   0x0
  632daf:	68 c0 1f bf 00       	push   0xbf1fc0
  632db4:	68 78 20 bf 00       	push   0xbf2078
  632db9:	eb 6b                	jmp    0x632e26
  632dbb:	68 5c 01 00 00       	push   0x15c
  632dc0:	e8 a3 f2 25 00       	call   0x892068
  632dc5:	8b f0                	mov    esi,eax
  632dc7:	83 c4 04             	add    esp,0x4
  632dca:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  632dcd:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  632dd4:	85 f6                	test   esi,esi
  632dd6:	74 2b                	je     0x632e03
  632dd8:	8b ce                	mov    ecx,esi
  632dda:	e8 a1 1a 12 00       	call   0x754880
  632ddf:	33 c0                	xor    eax,eax
  632de1:	c7 06 6c dd c2 00    	mov    DWORD PTR [esi],0xc2dd6c
  632de7:	66 89 86 58 01 00 00 	mov    WORD PTR [esi+0x158],ax
  632dee:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  632df1:	89 31                	mov    DWORD PTR [ecx],esi
  632df3:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  632df6:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  632dfd:	59                   	pop    ecx
  632dfe:	5e                   	pop    esi
  632dff:	8b e5                	mov    esp,ebp
  632e01:	5d                   	pop    ebp
  632e02:	c3                   	ret
  632e03:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  632e06:	33 f6                	xor    esi,esi
  632e08:	89 31                	mov    DWORD PTR [ecx],esi
  632e0a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  632e0d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  632e14:	59                   	pop    ecx
  632e15:	5e                   	pop    esi
  632e16:	8b e5                	mov    esp,ebp
  632e18:	5d                   	pop    ebp
  632e19:	c3                   	ret
  632e1a:	6a 00                	push   0x0
  632e1c:	68 c0 1f bf 00       	push   0xbf1fc0
  632e21:	68 c8 20 bf 00       	push   0xbf20c8
  632e26:	6a 00                	push   0x0
  632e28:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  632e2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  632e31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  632e38:	59                   	pop    ecx
  632e39:	5e                   	pop    esi
  632e3a:	8b e5                	mov    esp,ebp
  632e3c:	5d                   	pop    ebp
  632e3d:	c3                   	ret
```
### event 0xC352 factory: `0x45efe0` to `0x45f0b5`
```asm
0045efe0 <.text+0x5dfe0>:
  45efe0:	55                   	push   ebp
  45efe1:	8b ec                	mov    ebp,esp
  45efe3:	6a ff                	push   0xffffffff
  45efe5:	68 48 f5 91 00       	push   0x91f548
  45efea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  45eff0:	50                   	push   eax
  45eff1:	53                   	push   ebx
  45eff2:	56                   	push   esi
  45eff3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  45eff8:	33 c5                	xor    eax,ebp
  45effa:	50                   	push   eax
  45effb:	8d 45 f4             	lea    eax,[ebp-0xc]
  45effe:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  45f004:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  45f007:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  45f00a:	85 c0                	test   eax,eax
  45f00c:	0f 84 92 00 00 00    	je     0x45f0a4
  45f012:	83 38 00             	cmp    DWORD PTR [eax],0x0
  45f015:	75 79                	jne    0x45f090
  45f017:	81 7b 04 2d 01 00 00 	cmp    DWORD PTR [ebx+0x4],0x12d
  45f01e:	74 0e                	je     0x45f02e
  45f020:	6a 00                	push   0x0
  45f022:	68 c0 1f bf 00       	push   0xbf1fc0
  45f027:	68 78 20 bf 00       	push   0xbf2078
  45f02c:	eb 6e                	jmp    0x45f09c
  45f02e:	68 a0 02 00 00       	push   0x2a0
  45f033:	e8 30 30 43 00       	call   0x892068
  45f038:	8b f0                	mov    esi,eax
  45f03a:	83 c4 04             	add    esp,0x4
  45f03d:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  45f040:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  45f047:	85 f6                	test   esi,esi
  45f049:	74 2d                	je     0x45f078
  45f04b:	8b ce                	mov    ecx,esi
  45f04d:	e8 7e 7d 17 00       	call   0x5d6dd0
  45f052:	c7 06 6c 29 c2 00    	mov    DWORD PTR [esi],0xc2296c
  45f058:	c7 86 98 02 00 00 00 	mov    DWORD PTR [esi+0x298],0x0
  45f05f:	00 00 00 
  45f062:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  45f065:	89 30                	mov    DWORD PTR [eax],esi
  45f067:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  45f06a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  45f071:	59                   	pop    ecx
  45f072:	5e                   	pop    esi
  45f073:	5b                   	pop    ebx
  45f074:	8b e5                	mov    esp,ebp
  45f076:	5d                   	pop    ebp
  45f077:	c3                   	ret
  45f078:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  45f07b:	33 f6                	xor    esi,esi
  45f07d:	89 30                	mov    DWORD PTR [eax],esi
  45f07f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  45f082:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  45f089:	59                   	pop    ecx
  45f08a:	5e                   	pop    esi
  45f08b:	5b                   	pop    ebx
  45f08c:	8b e5                	mov    esp,ebp
  45f08e:	5d                   	pop    ebp
  45f08f:	c3                   	ret
  45f090:	6a 00                	push   0x0
  45f092:	68 c0 1f bf 00       	push   0xbf1fc0
  45f097:	68 c8 20 bf 00       	push   0xbf20c8
  45f09c:	6a 00                	push   0x0
  45f09e:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  45f0a4:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  45f0a7:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  45f0ae:	59                   	pop    ecx
  45f0af:	5e                   	pop    esi
  45f0b0:	5b                   	pop    ebx
  45f0b1:	8b e5                	mov    esp,ebp
  45f0b3:	5d                   	pop    ebp
  45f0b4:	c3                   	ret
```
### factory type checker: `0x632e40` to `0x632f27`
```asm
00632e40 <.text+0x231e40>:
  632e40:	55                   	push   ebp
  632e41:	8b ec                	mov    ebp,esp
  632e43:	83 ec 20             	sub    esp,0x20
  632e46:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  632e4b:	33 c5                	xor    eax,ebp
  632e4d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  632e50:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  632e53:	56                   	push   esi
  632e54:	8b f1                	mov    esi,ecx
  632e56:	50                   	push   eax
  632e57:	e8 e4 3a 11 00       	call   0x746940
  632e5c:	8b f0                	mov    esi,eax
  632e5e:	85 f6                	test   esi,esi
  632e60:	75 52                	jne    0x632eb4
  632e62:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  632e67:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  632e6c:	8d 75 e0             	lea    esi,[ebp-0x20]
  632e6f:	e8 0c 1c dd ff       	call   0x404a80
  632e74:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632e77:	be 08 00 00 00       	mov    esi,0x8
  632e7c:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632e7f:	73 03                	jae    0x632e84
  632e81:	8d 45 e0             	lea    eax,[ebp-0x20]
  632e84:	6a 00                	push   0x0
  632e86:	68 c0 1f bf 00       	push   0xbf1fc0
  632e8b:	50                   	push   eax
  632e8c:	6a 00                	push   0x0
  632e8e:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  632e94:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632e97:	72 7f                	jb     0x632f18
  632e99:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632e9c:	50                   	push   eax
  632e9d:	e8 6a e3 25 00       	call   0x89120c
  632ea2:	83 c4 04             	add    esp,0x4
  632ea5:	5e                   	pop    esi
  632ea6:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  632ea9:	33 cd                	xor    ecx,ebp
  632eab:	e8 51 e1 25 00       	call   0x891001
  632eb0:	8b e5                	mov    esp,ebp
  632eb2:	5d                   	pop    ebp
  632eb3:	c3                   	ret
  632eb4:	8b 16                	mov    edx,DWORD PTR [esi]
  632eb6:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  632eb9:	8b ce                	mov    ecx,esi
  632ebb:	ff d0                	call   eax
  632ebd:	3d 58 02 00 00       	cmp    eax,0x258
  632ec2:	74 52                	je     0x632f16
  632ec4:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  632ec9:	b8 d0 1f bf 00       	mov    eax,0xbf1fd0
  632ece:	8d 75 e0             	lea    esi,[ebp-0x20]
  632ed1:	e8 aa 1b dd ff       	call   0x404a80
  632ed6:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632ed9:	be 08 00 00 00       	mov    esi,0x8
  632ede:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632ee1:	73 03                	jae    0x632ee6
  632ee3:	8d 45 e0             	lea    eax,[ebp-0x20]
  632ee6:	6a 00                	push   0x0
  632ee8:	68 c0 1f bf 00       	push   0xbf1fc0
  632eed:	50                   	push   eax
  632eee:	6a 00                	push   0x0
  632ef0:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  632ef6:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632ef9:	72 1d                	jb     0x632f18
  632efb:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  632efe:	51                   	push   ecx
  632eff:	e8 08 e3 25 00       	call   0x89120c
  632f04:	83 c4 04             	add    esp,0x4
  632f07:	5e                   	pop    esi
  632f08:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  632f0b:	33 cd                	xor    ecx,ebp
  632f0d:	e8 ef e0 25 00       	call   0x891001
  632f12:	8b e5                	mov    esp,ebp
  632f14:	5d                   	pop    ebp
  632f15:	c3                   	ret
  632f16:	89 37                	mov    DWORD PTR [edi],esi
  632f18:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  632f1b:	33 cd                	xor    ecx,ebp
  632f1d:	5e                   	pop    esi
  632f1e:	e8 de e0 25 00       	call   0x891001
  632f23:	8b e5                	mov    esp,ebp
  632f25:	5d                   	pop    ebp
  632f26:	c3                   	ret
```
### UI lookup 0x61A8: `0x632f30` to `0x633018`
```asm
00632f30 <.text+0x231f30>:
  632f30:	55                   	push   ebp
  632f31:	8b ec                	mov    ebp,esp
  632f33:	83 ec 20             	sub    esp,0x20
  632f36:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  632f3b:	33 c5                	xor    eax,ebp
  632f3d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  632f40:	56                   	push   esi
  632f41:	8b f1                	mov    esi,ecx
  632f43:	68 a8 61 00 00       	push   0x61a8
  632f48:	e8 f3 39 11 00       	call   0x746940
  632f4d:	8b f0                	mov    esi,eax
  632f4f:	85 f6                	test   esi,esi
  632f51:	75 52                	jne    0x632fa5
  632f53:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  632f58:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  632f5d:	8d 75 e0             	lea    esi,[ebp-0x20]
  632f60:	e8 1b 1b dd ff       	call   0x404a80
  632f65:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632f68:	be 08 00 00 00       	mov    esi,0x8
  632f6d:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632f70:	73 03                	jae    0x632f75
  632f72:	8d 45 e0             	lea    eax,[ebp-0x20]
  632f75:	6a 00                	push   0x0
  632f77:	68 c0 1f bf 00       	push   0xbf1fc0
  632f7c:	50                   	push   eax
  632f7d:	6a 00                	push   0x0
  632f7f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  632f85:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632f88:	72 7f                	jb     0x633009
  632f8a:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632f8d:	50                   	push   eax
  632f8e:	e8 79 e2 25 00       	call   0x89120c
  632f93:	83 c4 04             	add    esp,0x4
  632f96:	5e                   	pop    esi
  632f97:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  632f9a:	33 cd                	xor    ecx,ebp
  632f9c:	e8 60 e0 25 00       	call   0x891001
  632fa1:	8b e5                	mov    esp,ebp
  632fa3:	5d                   	pop    ebp
  632fa4:	c3                   	ret
  632fa5:	8b 16                	mov    edx,DWORD PTR [esi]
  632fa7:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  632faa:	8b ce                	mov    ecx,esi
  632fac:	ff d0                	call   eax
  632fae:	3d c8 00 00 00       	cmp    eax,0xc8
  632fb3:	74 52                	je     0x633007
  632fb5:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  632fba:	b8 d0 1f bf 00       	mov    eax,0xbf1fd0
  632fbf:	8d 75 e0             	lea    esi,[ebp-0x20]
  632fc2:	e8 b9 1a dd ff       	call   0x404a80
  632fc7:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  632fca:	be 08 00 00 00       	mov    esi,0x8
  632fcf:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632fd2:	73 03                	jae    0x632fd7
  632fd4:	8d 45 e0             	lea    eax,[ebp-0x20]
  632fd7:	6a 00                	push   0x0
  632fd9:	68 c0 1f bf 00       	push   0xbf1fc0
  632fde:	50                   	push   eax
  632fdf:	6a 00                	push   0x0
  632fe1:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  632fe7:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  632fea:	72 1d                	jb     0x633009
  632fec:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  632fef:	51                   	push   ecx
  632ff0:	e8 17 e2 25 00       	call   0x89120c
  632ff5:	83 c4 04             	add    esp,0x4
  632ff8:	5e                   	pop    esi
  632ff9:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  632ffc:	33 cd                	xor    ecx,ebp
  632ffe:	e8 fe df 25 00       	call   0x891001
  633003:	8b e5                	mov    esp,ebp
  633005:	5d                   	pop    ebp
  633006:	c3                   	ret
  633007:	89 37                	mov    DWORD PTR [edi],esi
  633009:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  63300c:	33 cd                	xor    ecx,ebp
  63300e:	5e                   	pop    esi
  63300f:	e8 ed df 25 00       	call   0x891001
  633014:	8b e5                	mov    esp,ebp
  633016:	5d                   	pop    ebp
  633017:	c3                   	ret
```
### UI lookup 0xC350: `0x633020` to `0x633108`
```asm
00633020 <.text+0x232020>:
  633020:	55                   	push   ebp
  633021:	8b ec                	mov    ebp,esp
  633023:	83 ec 20             	sub    esp,0x20
  633026:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63302b:	33 c5                	xor    eax,ebp
  63302d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  633030:	56                   	push   esi
  633031:	8b f1                	mov    esi,ecx
  633033:	68 50 c3 00 00       	push   0xc350
  633038:	e8 03 39 11 00       	call   0x746940
  63303d:	8b f0                	mov    esi,eax
  63303f:	85 f6                	test   esi,esi
  633041:	75 52                	jne    0x633095
  633043:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  633048:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  63304d:	8d 75 e0             	lea    esi,[ebp-0x20]
  633050:	e8 2b 1a dd ff       	call   0x404a80
  633055:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  633058:	be 08 00 00 00       	mov    esi,0x8
  63305d:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  633060:	73 03                	jae    0x633065
  633062:	8d 45 e0             	lea    eax,[ebp-0x20]
  633065:	6a 00                	push   0x0
  633067:	68 c0 1f bf 00       	push   0xbf1fc0
  63306c:	50                   	push   eax
  63306d:	6a 00                	push   0x0
  63306f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  633075:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  633078:	72 7f                	jb     0x6330f9
  63307a:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  63307d:	50                   	push   eax
  63307e:	e8 89 e1 25 00       	call   0x89120c
  633083:	83 c4 04             	add    esp,0x4
  633086:	5e                   	pop    esi
  633087:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  63308a:	33 cd                	xor    ecx,ebp
  63308c:	e8 70 df 25 00       	call   0x891001
  633091:	8b e5                	mov    esp,ebp
  633093:	5d                   	pop    ebp
  633094:	c3                   	ret
  633095:	8b 16                	mov    edx,DWORD PTR [esi]
  633097:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  63309a:	8b ce                	mov    ecx,esi
  63309c:	ff d0                	call   eax
  63309e:	3d 14 05 00 00       	cmp    eax,0x514
  6330a3:	74 52                	je     0x6330f7
  6330a5:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  6330aa:	b8 d0 1f bf 00       	mov    eax,0xbf1fd0
  6330af:	8d 75 e0             	lea    esi,[ebp-0x20]
  6330b2:	e8 c9 19 dd ff       	call   0x404a80
  6330b7:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  6330ba:	be 08 00 00 00       	mov    esi,0x8
  6330bf:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  6330c2:	73 03                	jae    0x6330c7
  6330c4:	8d 45 e0             	lea    eax,[ebp-0x20]
  6330c7:	6a 00                	push   0x0
  6330c9:	68 c0 1f bf 00       	push   0xbf1fc0
  6330ce:	50                   	push   eax
  6330cf:	6a 00                	push   0x0
  6330d1:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  6330d7:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  6330da:	72 1d                	jb     0x6330f9
  6330dc:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  6330df:	51                   	push   ecx
  6330e0:	e8 27 e1 25 00       	call   0x89120c
  6330e5:	83 c4 04             	add    esp,0x4
  6330e8:	5e                   	pop    esi
  6330e9:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6330ec:	33 cd                	xor    ecx,ebp
  6330ee:	e8 0e df 25 00       	call   0x891001
  6330f3:	8b e5                	mov    esp,ebp
  6330f5:	5d                   	pop    ebp
  6330f6:	c3                   	ret
  6330f7:	89 37                	mov    DWORD PTR [edi],esi
  6330f9:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6330fc:	33 cd                	xor    ecx,ebp
  6330fe:	5e                   	pop    esi
  6330ff:	e8 fd de 25 00       	call   0x891001
  633104:	8b e5                	mov    esp,ebp
  633106:	5d                   	pop    ebp
  633107:	c3                   	ret
```
### UI lookup 0x7D0: `0x45f0c0` to `0x45f199`
```asm
0045f0c0 <.text+0x5e0c0>:
  45f0c0:	55                   	push   ebp
  45f0c1:	8b ec                	mov    ebp,esp
  45f0c3:	83 ec 20             	sub    esp,0x20
  45f0c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  45f0cb:	33 c5                	xor    eax,ebp
  45f0cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  45f0d0:	56                   	push   esi
  45f0d1:	8b f1                	mov    esi,ecx
  45f0d3:	68 d0 07 00 00       	push   0x7d0
  45f0d8:	e8 63 78 2e 00       	call   0x746940
  45f0dd:	8b f0                	mov    esi,eax
  45f0df:	85 f6                	test   esi,esi
  45f0e1:	75 52                	jne    0x45f135
  45f0e3:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  45f0e8:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  45f0ed:	8d 75 e0             	lea    esi,[ebp-0x20]
  45f0f0:	e8 8b 59 fa ff       	call   0x404a80
  45f0f5:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  45f0f8:	be 08 00 00 00       	mov    esi,0x8
  45f0fd:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  45f100:	73 03                	jae    0x45f105
  45f102:	8d 45 e0             	lea    eax,[ebp-0x20]
  45f105:	6a 00                	push   0x0
  45f107:	68 c0 1f bf 00       	push   0xbf1fc0
  45f10c:	50                   	push   eax
  45f10d:	6a 00                	push   0x0
  45f10f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  45f115:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  45f118:	72 7f                	jb     0x45f199
  45f11a:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  45f11d:	50                   	push   eax
  45f11e:	e8 e9 20 43 00       	call   0x89120c
  45f123:	83 c4 04             	add    esp,0x4
  45f126:	5e                   	pop    esi
  45f127:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  45f12a:	33 cd                	xor    ecx,ebp
  45f12c:	e8 d0 1e 43 00       	call   0x891001
  45f131:	8b e5                	mov    esp,ebp
  45f133:	5d                   	pop    ebp
  45f134:	c3                   	ret
  45f135:	8b 16                	mov    edx,DWORD PTR [esi]
  45f137:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  45f13a:	8b ce                	mov    ecx,esi
  45f13c:	ff d0                	call   eax
  45f13e:	3d c8 00 00 00       	cmp    eax,0xc8
  45f143:	74 52                	je     0x45f197
  45f145:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  45f14a:	b8 d0 1f bf 00       	mov    eax,0xbf1fd0
  45f14f:	8d 75 e0             	lea    esi,[ebp-0x20]
  45f152:	e8 29 59 fa ff       	call   0x404a80
  45f157:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  45f15a:	be 08 00 00 00       	mov    esi,0x8
  45f15f:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  45f162:	73 03                	jae    0x45f167
  45f164:	8d 45 e0             	lea    eax,[ebp-0x20]
  45f167:	6a 00                	push   0x0
  45f169:	68 c0 1f bf 00       	push   0xbf1fc0
  45f16e:	50                   	push   eax
  45f16f:	6a 00                	push   0x0
  45f171:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  45f177:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  45f17a:	72 1d                	jb     0x45f199
  45f17c:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  45f17f:	51                   	push   ecx
  45f180:	e8 87 20 43 00       	call   0x89120c
  45f185:	83 c4 04             	add    esp,0x4
  45f188:	5e                   	pop    esi
  45f189:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  45f18c:	33 cd                	xor    ecx,ebp
  45f18e:	e8 6e 1e 43 00       	call   0x891001
  45f193:	8b e5                	mov    esp,ebp
  45f195:	5d                   	pop    ebp
  45f196:	c3                   	ret
  45f197:	89 37                	mov    DWORD PTR [edi],esi
```

## 4. 情境、網路與 Server 責任矩陣

| 玩家情境/事件 | Client gate/本地效果 | C→S | S→C | Quest/NPC/UI 結果 | Server 待開發 |
|---|---|---|---|---|---|
| 事件 `0xC352` | type=0x12D、空槽時建 0x2A0-byte UI 物件 | unknown | unknown | 出站資料無證據 | 仍需找到真實接任務協定 |
| 事件 `0x61A8` | type=0xC8、空槽時建 0x15C-byte UI 物件 | unknown | unknown | 出站資料無證據 | 仍需找到真實接任務協定 |
| NPC 任務接取 | 真正 accept callback 未定位 | unknown | unknown | unknown | 不虛構請求／回覆 |
| Quest16→Quest15 解鎖 | Client cache writer 與資源前置待核 | unknown | unknown | unknown | 原版 Server algorithm 不在本任務可證範圍 |

## 5. 三輪門檻與停止條件

第 1 輪由先前無語意的兩個事件分支，擴展到具體**兩種不同配置大小、型別驗證、vptr/初始化、輸出槽、成功與失敗 CFG**，構成可回溯原始位元組的完整局部功能鏈及重要誤判排除。據共用門檻完成 T16-83；`T16-83-2`、`T16-83-3` **未啟動**，原因是本輪已有重大新發現；不宣稱 Quest 雙向封包已還原。

## 6. 後續 T16-84 與阻塞

從 NPC／Quest 確認按鈕的實際業務事件、真正的 Quest-state cache writer 追到 C→S/S→C。查 `0x45F0C0` 與 `0x632F30` 的 callers，以追 UI 標記和 output-slot 消費；但不要把本段的工廠/型別 helper 當成 Quest 進度。可參照 T02 已驗收的 framing/dispatcher，不修改 T02／T07／T14／T15 主責。

## 7. GitHub 管理

個人原稿僅提交 `kr-temp-roy/`；原始 BIN/EXE 不上傳、不修改其他 Task owner/catalog。以遠端讀回驗證為準。