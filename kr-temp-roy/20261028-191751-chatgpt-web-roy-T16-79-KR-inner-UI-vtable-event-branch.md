# KR T16-79 — QuestListDlg 內部物件 vtable、生命週期與事件分支

- 日期：2026-10-28T19:17:51+08:00；分析者 `chatgpt-web roy`；僅 KR。
- 唯讀原件：BIN 12472320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `objdump -h`：`.text` VA `0x401000` raw `0x400`，`.rdata` VA `0xBD2000` raw `0x7D0600`，`.data` VA `0xD61000` raw `0x95E800`。不同節採相應換算，未執行或修改程式。

## 目標與前段的必要修正

T16-78 已確認 `0x5A21D0` 的 QuestListDlg wrapper vtable `0xC1BB50`、其 `0x130` 位元組內物件配置、`0x5A2223` 進入 `0x62E280`、wrapper+0xC 保存內物件地址。本段追內物件的真實虛表與事件分支。**重要 ABI 邊界**：`0x5A2221` 把 allocator 回傳值放入 **ESI**，`0x62E280` 一開始使用 `mov ecx,esi`，不可在沒有 ESI 前置的情況下單獨視為標準 thiscall。

## 第 1 輪 T16-79：物件配置／狀態／配對釋放

- `0x62E2C0`：`mov dword [esi],0xC2DA0C`，確認內物件 vptr。
- `+EC/+F4/+FC/+100/+104/+108/+10C/+110/+114/+118/+11C/+124/+128` 被寫零；`+F0` 寫 `1`，`+F8` 寫 `0xFFFFFFFF`。這些偏移**不可在未有 consumer 證據前命名為 Quest ID／選擇項／清單長度**。
- vtable `+0x1C` 為 `0x62E300`：先有條件釋放 `[esi+0x114]`，清零 `+114/+118/+11C`，覆寫 vptr `0xC482CC` 後呼叫 `0x756590`；`[ebp+8]&1` 控制最終物件釋放。與前段 wrapper destructor 形成內外兩層有界生命週期證據，但本段**沒有證實 UI 被點擊或有發包**。

### BIN 原生指令：初始化

```asm
0062e280 <.text+0x22d280>:
  62e280:	8b ce                	mov    ecx,esi
  62e282:	e8 59 82 12 00       	call   0x7564e0
  62e287:	33 c0                	xor    eax,eax
  62e289:	89 86 ec 00 00 00    	mov    DWORD PTR [esi+0xec],eax
  62e28f:	89 86 f4 00 00 00    	mov    DWORD PTR [esi+0xf4],eax
  62e295:	89 86 fc 00 00 00    	mov    DWORD PTR [esi+0xfc],eax
  62e29b:	89 86 00 01 00 00    	mov    DWORD PTR [esi+0x100],eax
  62e2a1:	89 86 04 01 00 00    	mov    DWORD PTR [esi+0x104],eax
  62e2a7:	89 86 08 01 00 00    	mov    DWORD PTR [esi+0x108],eax
  62e2ad:	89 86 0c 01 00 00    	mov    DWORD PTR [esi+0x10c],eax
  62e2b3:	89 86 10 01 00 00    	mov    DWORD PTR [esi+0x110],eax
  62e2b9:	c6 86 f0 00 00 00 01 	mov    BYTE PTR [esi+0xf0],0x1
  62e2c0:	c7 06 0c da c2 00    	mov    DWORD PTR [esi],0xc2da0c
  62e2c6:	c7 86 f8 00 00 00 ff 	mov    DWORD PTR [esi+0xf8],0xffffffff
  62e2cd:	ff ff ff 
  62e2d0:	89 86 14 01 00 00    	mov    DWORD PTR [esi+0x114],eax
  62e2d6:	89 86 18 01 00 00    	mov    DWORD PTR [esi+0x118],eax
  62e2dc:	89 86 1c 01 00 00    	mov    DWORD PTR [esi+0x11c],eax
  62e2e2:	89 86 24 01 00 00    	mov    DWORD PTR [esi+0x124],eax
  62e2e8:	89 86 28 01 00 00    	mov    DWORD PTR [esi+0x128],eax
  62e2ee:	8b c6                	mov    eax,esi
  62e2f0:	c3                   	ret
```

### BIN 原生指令：內物件析構

```asm
0062e300 <.text+0x22d300>:
  62e300:	55                   	push   ebp
  62e301:	8b ec                	mov    ebp,esp
  62e303:	56                   	push   esi
  62e304:	8b f1                	mov    esi,ecx
  62e306:	c7 06 0c da c2 00    	mov    DWORD PTR [esi],0xc2da0c
  62e30c:	8b 86 14 01 00 00    	mov    eax,DWORD PTR [esi+0x114]
  62e312:	85 c0                	test   eax,eax
  62e314:	74 09                	je     0x62e31f
  62e316:	50                   	push   eax
  62e317:	e8 f0 2e 26 00       	call   0x89120c
  62e31c:	83 c4 04             	add    esp,0x4
  62e31f:	c7 86 14 01 00 00 00 	mov    DWORD PTR [esi+0x114],0x0
  62e326:	00 00 00 
  62e329:	c7 86 18 01 00 00 00 	mov    DWORD PTR [esi+0x118],0x0
  62e330:	00 00 00 
  62e333:	c7 86 1c 01 00 00 00 	mov    DWORD PTR [esi+0x11c],0x0
  62e33a:	00 00 00 
  62e33d:	8b ce                	mov    ecx,esi
  62e33f:	c7 06 cc 82 c4 00    	mov    DWORD PTR [esi],0xc482cc
  62e345:	e8 46 82 12 00       	call   0x756590
  62e34a:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  62e34e:	74 09                	je     0x62e359
  62e350:	56                   	push   esi
  62e351:	e8 a6 3d 26 00       	call   0x8920fc
  62e356:	83 c4 04             	add    esp,0x4
  62e359:	8b c6                	mov    eax,esi
  62e35b:	5e                   	pop    esi
  62e35c:	5d                   	pop    ebp
  62e35d:	c2                   	.byte 0xc2
```

### vtable `0xC2DA0C`（raw `0x82C00C`）

| slot offset | target VA |
|---|---|
| +0x00 | 0x004882E0 |
| +0x04 | 0x00407290 |
| +0x08 | 0x00407290 |
| +0x0C | 0x00407280 |
| +0x10 | 0x00403DE0 |
| +0x14 | 0x00755F00 |
| +0x18 | 0x00755F40 |
| +0x1C | 0x0062E300 |
| +0x20 | 0x004071F0 |
| +0x24 | 0x00407140 |
| +0x28 | 0x00407080 |
| +0x2C | 0x00586420 |
| +0x30 | 0x00745530 |
| +0x34 | 0x007456F0 |
| +0x38 | 0x00760B80 |
| +0x3C | 0x00745A20 |
| +0x40 | 0x00745B70 |
| +0x44 | 0x00403DD0 |
| +0x48 | 0x00466DA0 |
| +0x4C | 0x00403DB0 |
| +0x50 | 0x00749890 |
| +0x54 | 0x007498E0 |
| +0x58 | 0x00403DC0 |
| +0x5C | 0x005F5D10 |
| +0x60 | 0x00746FE0 |
| +0x64 | 0x00746FD0 |
| +0x68 | 0x00748600 |
| +0x6C | 0x00748670 |
| +0x70 | 0x00746640 |
| +0x74 | 0x00746700 |
| +0x78 | 0x00403DB0 |
| +0x7C | 0x00403DB0 |
| +0x80 | 0x00403DB0 |
| +0x84 | 0x00403DB0 |
| +0x88 | 0x00403DB0 |
| +0x8C | 0x00403D80 |
| +0x90 | 0x00746080 |
| +0x94 | 0x007460E0 |
| +0x98 | 0x00746130 |
| +0x9C | 0x007461F0 |
| +0xA0 | 0x00746280 |
| +0xA4 | 0x007462E0 |
| +0xA8 | 0x00746350 |
| +0xAC | 0x007463B0 |
| +0xB0 | 0x005F5D10 |
| +0xB4 | 0x00745C80 |
| +0xB8 | 0x00746C60 |
| +0xBC | 0x00749B50 |
| +0xC0 | 0x00757080 |

以上只證明指標值，沒有對全部虛方法推定語意。

## 第 2 輪 T16-79-2：事件虛方法與條件性配置

- vtable `+0x110`（表內指標 VA `0xC2DB1C`）指向 `0x62E360`，下一筆 `+0x114` 指向 `0x62E380`。這兩個 **是同一指標表中的連續 entry**，不是 Quest opcode。
- `0x62E360` 檢查 `[ebp+8] == 0x4E22`；不符合直接 `ret 0x0C`。符合時用 `lea esi,[ebp+8]` 呼叫 `0x6306F0`，可知傳給它的是**堆疊參數地址**，不可誤標 `esi` 為 C++ this。
- `0x6306F0` 的 `[esi+8]` 對應上層 `[ebp+0x10]`；該 pointer 存在且其指向值為零、且 `[esi+4]==0x12D` 時，配置 `0x254` bytes，再調 `0x6309D0`，把結果寫回 caller-supplied pointer；失敗則寫零。其餘分支含診斷性間接 API 呼叫，所見數值 **不是已驗證 Quest ID、任務接取封包或 wire opcode**。

```asm
0062e360 <.text+0x22d360>:
  62e360:	55                   	push   ebp
  62e361:	8b ec                	mov    ebp,esp
  62e363:	81 7d 08 22 4e 00 00 	cmp    DWORD PTR [ebp+0x8],0x4e22
  62e36a:	75 0a                	jne    0x62e376
  62e36c:	56                   	push   esi
  62e36d:	8d 75 08             	lea    esi,[ebp+0x8]
  62e370:	e8 7b 23 00 00       	call   0x6306f0
  62e375:	5e                   	pop    esi
  62e376:	5d                   	pop    ebp
  62e377:	c2                   	.byte 0xc2
  62e378:	0c                   	.byte 0xc
```

```asm
006306f0 <.text+0x22f6f0>:
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

- `0x62E380` 依序使用 `0x755E50`、`0x43C570`、`0x615FC0`、`0x6AE700` 操作 `+FC/+100/+104/+108/+10C/+110/+12C`，再由 `[esi+0x110]` 讀取指標、寫入其 `+0xD4=0`。這是一條初始化型資料流；未追到 UI click 或通訊。

```asm
0062e380 <.text+0x22d380>:
  62e380:	53                   	push   ebx
  62e381:	56                   	push   esi
  62e382:	57                   	push   edi
  62e383:	8b f1                	mov    esi,ecx
  62e385:	e8 c6 7a 12 00       	call   0x755e50
  62e38a:	68 10 27 00 00       	push   0x2710
  62e38f:	8d be 08 01 00 00    	lea    edi,[esi+0x108]
  62e395:	8b ce                	mov    ecx,esi
  62e397:	e8 d4 e1 e0 ff       	call   0x43c570
  62e39c:	68 f8 2a 00 00       	push   0x2af8
  62e3a1:	8d be 0c 01 00 00    	lea    edi,[esi+0x10c]
  62e3a7:	8b ce                	mov    ecx,esi
  62e3a9:	e8 12 7c fe ff       	call   0x615fc0
  62e3ae:	8d be 10 01 00 00    	lea    edi,[esi+0x110]
  62e3b4:	8b ce                	mov    ecx,esi
  62e3b6:	e8 45 03 08 00       	call   0x6ae700
  62e3bb:	68 30 75 00 00       	push   0x7530
  62e3c0:	8d be fc 00 00 00    	lea    edi,[esi+0xfc]
  62e3c6:	8b ce                	mov    ecx,esi
  62e3c8:	e8 f3 7b fe ff       	call   0x615fc0
  62e3cd:	68 40 9c 00 00       	push   0x9c40
  62e3d2:	8d be 04 01 00 00    	lea    edi,[esi+0x104]
  62e3d8:	8b ce                	mov    ecx,esi
  62e3da:	e8 e1 7b fe ff       	call   0x615fc0
  62e3df:	68 50 c3 00 00       	push   0xc350
  62e3e4:	8d be 00 01 00 00    	lea    edi,[esi+0x100]
  62e3ea:	8b ce                	mov    ecx,esi
  62e3ec:	e8 cf 7b fe ff       	call   0x615fc0
  62e3f1:	68 b0 ad 01 00       	push   0x1adb0
  62e3f6:	8d be 2c 01 00 00    	lea    edi,[esi+0x12c]
  62e3fc:	8b ce                	mov    ecx,esi
  62e3fe:	e8 6d e1 e0 ff       	call   0x43c570
  62e403:	8b 86 10 01 00 00    	mov    eax,DWORD PTR [esi+0x110]
  62e409:	83 c4 18             	add    esp,0x18
  62e40c:	5f                   	pop    edi
  62e40d:	5e                   	pop    esi
  62e40e:	c7 80 d4 00 00 00 00 	mov    DWORD PTR [eax+0xd4],0x0
  62e415:	00 00 00 
  62e418:	5b                   	pop    ebx
  62e419:	c3                   	ret
```

## 第 3 輪 T16-79-3：反向引用、否定邊界與停止理由

本輪以原始 `.rdata` 搜尋 `0x62E360` 的 little-endian 4-byte 直接引用，找到 `0xC2DB1C` 一處且與上述 vtable slot 對齊。這是**有限直接指標檢索**，不能據此排除 registry、基底 callback 或動態綁定。`0x6309D0` 已知是配置後的 constructor-like 下游，尚缺它與 Quest 點擊、RequestAcceptQuest producer 或 Quest cache writer 的關係。

三輪結果：第 1 輪發現內物件實際 vtable、欄位與配對析構；第 2 輪定位具體事件虛方法並還原有界的 event→conditional allocation；第 3 輪核對直接引用、確認本次無 Quest 業務封包證據且完成停止盤點。已具第一手機器碼支持的局部重大增量，因此結束 T16-79；但不能宣稱 Quest 收發閉環已完成。

## 玩家情境／Client-Server 證據矩陣

| 情境 | Client local | C→S | S→C | UI/Quest 結果 | Server 待開發 |
|---|---|---|---|---|---|
| Quest UI 建立 | wrapper+0xC 保存 0x130 內物件；vtable 0xC2DA0C | unknown | unknown | 配置、初始化、析構有界確認；顯示 unknown | 無法由 UI 配置推測 |
| 事件 0x4E22 | 0x62E360 判斷後交 0x6306F0，含 0x12D gate | unknown | unknown | 有條件寫回 0x254 配置物件；事件語意 unknown | 無法稱為任務接取 |
| 玩家點 NPC 接 Quest | unknown | opcode、欄位、時序 unknown | 接受/拒絕 handler unknown | Quest cache writer unknown | 必須先補 Client 證據 |
| Quest16→Quest15 | unknown | unknown | unknown | unknown | 不推定原版 Server 前置邏輯 |

## 後續入口

優先從 `0x62E380` 建立的具體控件及註冊 callback 查 NPC UI 點擊發包；或從 Quest cache writer 反向找 S→C 業務 dispatcher。不要再以 RTTI／本地化文字 ID 當 wire opcode。T02/T07/T14/T15 的主責範圍不修改。本筆記只新增於 `kr-temp-roy/`，未修改原始程式與資料、owner 或 catalog。