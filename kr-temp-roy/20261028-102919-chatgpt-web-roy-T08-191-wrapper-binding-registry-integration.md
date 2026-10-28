# T08-191 — Wrapper 建立、Provider 綁定與索引管理之跨層邊界

- 研究時間（Asia/Taipei）：2026-10-28T10:29:19+08:00
- 研究者：`chatgpt-web roy`；範圍：KR T08 靜態研究／正式 0007 實體建立、登記、移除之介面（資源管理為上下游線索）
- 證據：原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算一致）。PE `.text` VA `0x401000`/raw `0x400`、section size `0x7D01F0`（以 `objdump -h` 檢視）；唯讀，未執行遊戲。
- GitHub：`we88ec3-prog/ttr_anal_multi` `main`；沿 T08-185～188 證據線索接續。以下皆以 RVA 映射實際機器碼獨立檢視；舊筆記不取代第一手驗證。

## 本段實質研究結果及證據等級

1. **已確認** `0x007F6FBA` 周邊可見配置約 `0x30` bytes wrapper，再藉 `0x007DCFB0` 取得共享資源，並將資源指標放入 wrapper 的相應欄位（前段確認 `wrapper+0x2C`）。此 wrapper 與底層 `0x7C` bytes resource 不可混同。

2. **已確認** `0x007DD0E4` 比較 manager+0x44 與 1，達條件才走 `0x007BDF90` 名稱 Provider binding；未開啟模式時不代表底層 resource 不能存在。

3. **已確認** `0x007BE0F0` 為資源清理時的 binding 解除入口；此行為與 `0x007DC510` 名稱索引 payload callback 作用不同，僅可論斷存在橋接／引用。

4. **尚待驗證** wrapper 配置失敗、resource 取得失敗時是否呼叫對稱釋放；名稱樹 `[0x00FE173C]` 與其他 `0x00FE1740` 內嵌樹為不同容器，不能借用彼此 payload 類型。

## 相關函式與前段差異

銜接 T08-187：將 `wrapper -> manager acquire -> resource`、`resource -> name/Provider binding`、`release -> binding cleanup` 分成不同邊，避免將任何索引 erase 直接命名 wrapper destructor。

## E8 相對位移重新實算（僅 byte 候選，不是完整 CFG）

- 目標 `0x007F6FBA`：0 候選：無
- 目標 `0x007BDF90`：1 候選：`0x007DD0EC` (`e89f0efeff`)
- 目標 `0x007BE0F0`：7 候選：`0x007A53F4` (`e8f78c0100`), `0x007A5A0C` (`e8df860100`), `0x007A5AE8` (`e803860100`), `0x007A7914` (`e8d7670100`), `0x007A874E` (`e89d590100`), `0x007BE626` (`e8c5faffff`), `0x007DD21B` (`e8d00efeff`)
- 目標 `0x007DD0D0`：0 候選：無

**限制**：此掃描在 `.text` 每 byte 搜索 `E8 + signed rel32`，可能包含非指令邊界，亦不包含 FF/2、vtable 或反常 CFG；只可當交叉參照候選。

## 有界資料流與 ABI 注意

下列地址窗口從明示 VA 分段反組譯；函式入口／呼叫慣例需依 prologue、callsite 和實際 CFG 共同確認。若觀察到 `+0x44/+0x5C/+0x60` 等相同欄位，**只有在 pointer provenance 相同時**才視為同一結構；不得以同 offset 合併 actor、resource、registry、wrapper。

## 待查問題及下一段入口

1. 沿 `0x007F6FBA` 返回路徑追 wrapper allocation 的 NULL edge 和 owner 傳遞。
2. 定位 binding vtable 具體實作與其資料成員初始化點。
3. 對比兩種 name tree 的 payload 實值寫入位址。

## 附錄：原始 BIN 組語（objdump x86 Intel，指定 VA 有界解碼）

### `0x007F6FBA` ～ `0x007F707A`

```asm
  7f6fba:	e8 c1 11 fc ff       	call   0x7b8180
  7f6fbf:	6a 30                	push   0x30
  7f6fc1:	8b f8                	mov    edi,eax
  7f6fc3:	e8 a0 a2 09 00       	call   0x891268
  7f6fc8:	8b f0                	mov    esi,eax
  7f6fca:	83 c4 04             	add    esp,0x4
  7f6fcd:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7f6fd0:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7f6fd7:	85 f6                	test   esi,esi
  7f6fd9:	74 46                	je     0x7f7021
  7f6fdb:	57                   	push   edi
  7f6fdc:	e8 cf 5f fe ff       	call   0x7dcfb0
  7f6fe1:	d9 ee                	fldz
  7f6fe3:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  7f6fea:	c7 06 cc 11 c5 00    	mov    DWORD PTR [esi],0xc511cc
  7f6ff0:	d9 56 08             	fst    DWORD PTR [esi+0x8]
  7f6ff3:	d9 56 0c             	fst    DWORD PTR [esi+0xc]
  7f6ff6:	d9 56 10             	fst    DWORD PTR [esi+0x10]
  7f6ff9:	d9 56 14             	fst    DWORD PTR [esi+0x14]
  7f6ffc:	d9 56 18             	fst    DWORD PTR [esi+0x18]
  7f6fff:	d9 56 1c             	fst    DWORD PTR [esi+0x1c]
  7f7002:	d9 56 20             	fst    DWORD PTR [esi+0x20]
  7f7005:	d9 56 24             	fst    DWORD PTR [esi+0x24]
  7f7008:	d9 5e 28             	fstp   DWORD PTR [esi+0x28]
  7f700b:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  7f700e:	8b c6                	mov    eax,esi
  7f7010:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7013:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f701a:	59                   	pop    ecx
  7f701b:	5f                   	pop    edi
  7f701c:	5e                   	pop    esi
  7f701d:	8b e5                	mov    esp,ebp
  7f701f:	5d                   	pop    ebp
  7f7020:	c3                   	ret
  7f7021:	33 c0                	xor    eax,eax
  7f7023:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7026:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f702d:	59                   	pop    ecx
  7f702e:	5f                   	pop    edi
  7f702f:	5e                   	pop    esi
  7f7030:	8b e5                	mov    esp,ebp
  7f7032:	5d                   	pop    ebp
  7f7033:	c3                   	ret
  7f7034:	cc                   	int3
  7f7035:	cc                   	int3
  7f7036:	cc                   	int3
  7f7037:	cc                   	int3
  7f7038:	cc                   	int3
  7f7039:	cc                   	int3
  7f703a:	cc                   	int3
  7f703b:	cc                   	int3
  7f703c:	cc                   	int3
  7f703d:	cc                   	int3
  7f703e:	cc                   	int3
  7f703f:	cc                   	int3
  7f7040:	55                   	push   ebp
  7f7041:	8b ec                	mov    ebp,esp
  7f7043:	6a ff                	push   0xffffffff
  7f7045:	68 2a 64 92 00       	push   0x92642a
  7f704a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f7050:	50                   	push   eax
  7f7051:	51                   	push   ecx
  7f7052:	56                   	push   esi
  7f7053:	57                   	push   edi
  7f7054:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f7059:	33 c5                	xor    eax,ebp
  7f705b:	50                   	push   eax
  7f705c:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f705f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f7065:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  7f7068:	83 79 18 10          	cmp    DWORD PTR [ecx+0x18],0x10
  7f706c:	8d 71 04             	lea    esi,[ecx+0x4]
  7f706f:	72 04                	jb     0x7f7075
  7f7071:	8b 3e                	mov    edi,DWORD PTR [esi]
  7f7073:	eb 02                	jmp    0x7f7077
  7f7075:	8b fe                	mov    edi,esi
  7f7077:	f6 05 f8     	test   BYTE PTR ds:0xfe1df8,0x1
```

### `0x007BDF90` ～ `0x007BE090`

```asm
  7bdf90:	55                   	push   ebp
  7bdf91:	8b ec                	mov    ebp,esp
  7bdf93:	6a ff                	push   0xffffffff
  7bdf95:	68 b6 8a 91 00       	push   0x918ab6
  7bdf9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7bdfa0:	50                   	push   eax
  7bdfa1:	83 ec 2c             	sub    esp,0x2c
  7bdfa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7bdfa9:	33 c5                	xor    eax,ebp
  7bdfab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7bdfae:	53                   	push   ebx
  7bdfaf:	56                   	push   esi
  7bdfb0:	57                   	push   edi
  7bdfb1:	50                   	push   eax
  7bdfb2:	8d 45 f4             	lea    eax,[ebp-0xc]
  7bdfb5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7bdfbb:	8b f1                	mov    esi,ecx
  7bdfbd:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7bdfc0:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  7bdfc3:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7bdfc6:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7bdfc9:	0f 84 f4 00 00 00    	je     0x7be0c3
  7bdfcf:	eb 03                	jmp    0x7bdfd4
  7bdfd1:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7bdfd4:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7bdfdb:	8b 18                	mov    ebx,DWORD PTR [eax]
  7bdfdd:	75 27                	jne    0x7be006
  7bdfdf:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7bdfe6:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bdfed:	e8 ae 9d ff ff       	call   0x7b7da0
  7bdff2:	68 90 e7 bc 00       	push   0xbce790
  7bdff7:	e8 1e 43 0d 00       	call   0x89231a
  7bdffc:	83 c4 04             	add    esp,0x4
  7bdfff:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be006:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7be009:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7be00f:	8b c1                	mov    eax,ecx
  7be011:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be018:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be01f:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be023:	8d 78 01             	lea    edi,[eax+0x1]
  7be026:	8a 10                	mov    dl,BYTE PTR [eax]
  7be028:	40                   	inc    eax
  7be029:	84 d2                	test   dl,dl
  7be02b:	75 f9                	jne    0x7be026
  7be02d:	2b c7                	sub    eax,edi
  7be02f:	50                   	push   eax
  7be030:	51                   	push   ecx
  7be031:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7be034:	e8 37 4a c4 ff       	call   0x402a70
  7be039:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7be03c:	50                   	push   eax
  7be03d:	8d 4d c8             	lea    ecx,[ebp-0x38]
  7be040:	51                   	push   ecx
  7be041:	8b c6                	mov    eax,esi
  7be043:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7be04a:	e8 a1 a6 ff ff       	call   0x7b86f0
  7be04f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be056:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7be05a:	72 0c                	jb     0x7be068
  7be05c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7be05f:	52                   	push   edx
  7be060:	e8 a7 31 0d 00       	call   0x89120c
  7be065:	83 c4 04             	add    esp,0x4
  7be068:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  7be06b:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be072:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be079:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be07d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7be080:	74 11                	je     0x7be093
  7be082:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  7be085:	85 c9                	test   ecx,ecx
  7be087:	74 0a                	je     0x7be093
  7be089:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be08b:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7be08e:	ff d2                	call   edx
```

### `0x007BE0F0` ～ `0x007BE200`

```asm
  7be0f0:	55                   	push   ebp
  7be0f1:	8b ec                	mov    ebp,esp
  7be0f3:	51                   	push   ecx
  7be0f4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be0f7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7be0fa:	57                   	push   edi
  7be0fb:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  7be0fe:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7be101:	3b f9                	cmp    edi,ecx
  7be103:	74 33                	je     0x7be138
  7be105:	56                   	push   esi
  7be106:	8b 37                	mov    esi,DWORD PTR [edi]
  7be108:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be10b:	85 c9                	test   ecx,ecx
  7be10d:	74 1d                	je     0x7be12c
  7be10f:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be111:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7be114:	ff d2                	call   edx
  7be116:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be119:	85 c9                	test   ecx,ecx
  7be11b:	74 0f                	je     0x7be12c
  7be11d:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be11f:	8b 10                	mov    edx,DWORD PTR [eax]
  7be121:	6a 01                	push   0x1
  7be123:	ff d2                	call   edx
  7be125:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  7be12c:	83 c7 04             	add    edi,0x4
  7be12f:	3b 7d fc             	cmp    edi,DWORD PTR [ebp-0x4]
  7be132:	75 d2                	jne    0x7be106
  7be134:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be137:	5e                   	pop    esi
  7be138:	c7 40 74 00 00 00 00 	mov    DWORD PTR [eax+0x74],0x0
  7be13f:	5f                   	pop    edi
  7be140:	8b e5                	mov    esp,ebp
  7be142:	5d                   	pop    ebp
  7be143:	c2 04 00             	ret    0x4
  7be146:	cc                   	int3
  7be147:	cc                   	int3
  7be148:	cc                   	int3
  7be149:	cc                   	int3
  7be14a:	cc                   	int3
  7be14b:	cc                   	int3
  7be14c:	cc                   	int3
  7be14d:	cc                   	int3
  7be14e:	cc                   	int3
  7be14f:	cc                   	int3
  7be150:	55                   	push   ebp
  7be151:	8b ec                	mov    ebp,esp
  7be153:	83 e4 f8             	and    esp,0xfffffff8
  7be156:	81 ec 04 01 00 00    	sub    esp,0x104
  7be15c:	d9 ee                	fldz
  7be15e:	53                   	push   ebx
  7be15f:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7be162:	d9 54 24 24          	fst    DWORD PTR [esp+0x24]
  7be166:	d9 43 18             	fld    DWORD PTR [ebx+0x18]
  7be169:	56                   	push   esi
  7be16a:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  7be16e:	57                   	push   edi
  7be16f:	d9 43 18             	fld    DWORD PTR [ebx+0x18]
  7be172:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  7be176:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  7be17a:	6a 34                	push   0x34
  7be17c:	d9 43 18             	fld    DWORD PTR [ebx+0x18]
  7be17f:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  7be183:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  7be187:	89 84 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],eax
  7be18e:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  7be192:	8d 44 24 54          	lea    eax,[esp+0x54]
  7be196:	d9 54 24 20          	fst    DWORD PTR [esp+0x20]
  7be19a:	6a 00                	push   0x0
  7be19c:	d9 54 24 28          	fst    DWORD PTR [esp+0x28]
  7be1a0:	bf 01 00 00 00       	mov    edi,0x1
  7be1a5:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  7be1a9:	50                   	push   eax
  7be1aa:	d9 e8                	fld1
  7be1ac:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  7be1b3:	d9 5c 24 34          	fstp   DWORD PTR [esp+0x34]
  7be1b7:	89 bc 24 b8 00 00 00 	mov    DWORD PTR [esp+0xb8],edi
  7be1be:	89 8c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ecx
  7be1c5:	89 94 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],edx
  7be1cc:	e8 8f 06 0e 00       	call   0x89e860
  7be1d1:	d9 e8                	fld1
  7be1d3:	d9 54 24 7c          	fst    DWORD PTR [esp+0x7c]
  7be1d7:	83 c4 08             	add    esp,0x8
  7be1da:	d9 54 24 64          	fst    DWORD PTR [esp+0x64]
  7be1de:	8d 74 24 54          	lea    esi,[esp+0x54]
  7be1e2:	d9 5c 24 54          	fstp   DWORD PTR [esp+0x54]
  7be1e6:	d9 43 34             	fld    DWORD PTR [ebx+0x34]
  7be1e9:	d9 1c 24             	fstp   DWORD PTR [esp]
  7be1ec:	e8 cf 2b fd ff       	call   0x790dc0
  7be1f1:	d9 43 38             	fld    DWORD PTR [ebx+0x38]
  7be1f4:	51                   	push   ecx
  7be1f5:	d9 1c 24             	fstp   DWORD PTR [esp]
  7be1f8:	e8 93 2c fd ff       	call   0x790e90
  7be1fd:	d9 43 3c             	fld    DWORD PTR [ebx+0x3c]
```

### `0x007DD0D0` ～ `0x007DD0FE`

```asm
  7dd0d0:	83 46 08 04          	add    DWORD PTR [esi+0x8],0x4
  7dd0d4:	40                   	inc    eax
  7dd0d5:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7dd0d8:	3b 45 f4             	cmp    eax,DWORD PTR [ebp-0xc]
  7dd0db:	0f 82 73 ff ff ff    	jb     0x7dd054
  7dd0e1:	8b 75 f8             	mov    esi,DWORD PTR [ebp-0x8]
  7dd0e4:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd0e8:	7c 07                	jl     0x7dd0f1
  7dd0ea:	8b ce                	mov    ecx,esi
  7dd0ec:	e8 9f 0e fe ff       	call   0x7bdf90
  7dd0f1:	5f                   	pop    edi
  7dd0f2:	8b c6                	mov    eax,esi
  7dd0f4:	5e                   	pop    esi
  7dd0f5:	5b                   	pop    ebx
  7dd0f6:	8b e5                	mov    esp,ebp
  7dd0f8:	5d                   	pop    ebp
  7dd0f9:	c2 04 00             	ret    0x4
  7dd0fc:	cc                   	int3
  7dd0fd:	cc                   	int3
```