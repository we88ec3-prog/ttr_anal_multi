# T10-42 — 第二容器的索引與 controller actor slot 來源之辨別（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.731845+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】工廠建構回傳的 `esi` 先傳入 `0x4DFF30`；它的註冊鍵來自 `[esi+4]`，不能視為玩家角色 slot 編號。
- 【已確認】`0x4DFFB0` 的入口使用 `ecx` 指向另一物件，`[esi]` 作為識別，`0x4E0020` 在特定全域條件下向 `[ebx+0xF8]` 寫回該 `esi`，隨後在 `ebx+0x18` 呼叫 `0x57E850`。這是另一個容器更新流，而非足以證明 controller actor 的直接證據。
- 【已確認】`0x546137` 從 controller `[ecx+0xC]` 讀取 actor；若全域模式 `[0xFBA7AC]==3`，`0x546141..148` 以 `3*(slot)+3` 生成索引，從同一 controller 的不同位置讀取。
- 【排除】不應把 `0x4DFFB0` 的 `ebx+0xF8` 與 `0x546137` 的 controller `[ecx+0xC]` 混同；必須先追到同一個 owner 指標。

## 呼叫與欄位證據
`0x4DFFB0 → 0x57E850` 把第二種物件/容器的寫入與 controller slot 區隔。`0x546137` 的 `[ecx+0xC]` 和 slot 分流皆從 controller `ecx` 派生。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x4aec00–0x4aec90
```asm
004aec00 <.text+0xadc00>:
  4aec00:	00 8b c6 e8 28 13    	add    BYTE PTR [ebx+0x1328e8c6],cl
  4aec06:	03 00                	add    eax,DWORD PTR [eax]
  4aec08:	83 7b 0e 00          	cmp    DWORD PTR [ebx+0xe],0x0
  4aec0c:	0f 84 86 00 00 00    	je     0x4aec98
  4aec12:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aec19:	75 2f                	jne    0x4aec4a
  4aec1b:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aec22:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xe
  4aec29:	0e 00 00 00 
  4aec2d:	e8 5e 00 03 00       	call   0x4dec90
  4aec32:	68 30 ce bc 00       	push   0xbcce30
  4aec37:	e8 de 36 3e 00       	call   0x89231a
  4aec3c:	83 c4 04             	add    esp,0x4
  4aec3f:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aec46:	ff ff ff ff 
  4aec4a:	8b 4b 0e             	mov    ecx,DWORD PTR [ebx+0xe]
  4aec4d:	8d 54 24 14          	lea    edx,[esp+0x14]
  4aec51:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4aec55:	52                   	push   edx
  4aec56:	8d 44 24 34          	lea    eax,[esp+0x34]
  4aec5a:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4aec5f:	e8 5c 4c 39 00       	call   0x8438c0
  4aec64:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  4aec68:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4aec6e:	74 28                	je     0x4aec98
  4aec70:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  4aec73:	85 c9                	test   ecx,ecx
  4aec75:	74 21                	je     0x4aec98
  4aec77:	83 79 04 00          	cmp    DWORD PTR [ecx+0x4],0x0
  4aec7b:	75 1b                	jne    0x4aec98
  4aec7d:	0f b7 43 fc          	movzx  eax,WORD PTR [ebx-0x4]
  4aec81:	8b f9                	mov    edi,ecx
  4aec83:	e8 c8 81 01 00       	call   0x4c6e50
  4aec88:	80 7e 04 00          	cmp    BYTE PTR [esi+0x4],0x0
  4aec8c:	75 0a                	jne    0x4aec98
  4aec8e:	c7                   	.byte 0xc7
  4aec8f:	86                   	.byte 0x86
```

### VA 0x4dffb0–0x4e0060
```asm
004dffb0 <.text+0xdefb0>:
  4dffb0:	55                   	push   ebp
  4dffb1:	8b ec                	mov    ebp,esp
  4dffb3:	83 e4 f8             	and    esp,0xfffffff8
  4dffb6:	6a ff                	push   0xffffffff
  4dffb8:	68 de ed 93 00       	push   0x93edde
  4dffbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4dffc3:	50                   	push   eax
  4dffc4:	83 ec 10             	sub    esp,0x10
  4dffc7:	53                   	push   ebx
  4dffc8:	56                   	push   esi
  4dffc9:	57                   	push   edi
  4dffca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4dffcf:	33 c4                	xor    eax,esp
  4dffd1:	50                   	push   eax
  4dffd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  4dffd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4dffdc:	8b f1                	mov    esi,ecx
  4dffde:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dffe1:	8b 3e                	mov    edi,DWORD PTR [esi]
  4dffe3:	b8 01 00 00 00       	mov    eax,0x1
  4dffe8:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4dffee:	75 28                	jne    0x4e0018
  4dfff0:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4dfff6:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  4dfffd:	00 
  4dfffe:	e8 8d 15 00 00       	call   0x4e1590
  4e0003:	68 80 cc bc 00       	push   0xbccc80
  4e0008:	e8 0d 23 3b 00       	call   0x89231a
  4e000d:	83 c4 04             	add    esp,0x4
  4e0010:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4e0017:	ff 
  4e0018:	3b 3d 30 39 f9 00    	cmp    edi,DWORD PTR ds:0xf93930
  4e001e:	75 06                	jne    0x4e0026
  4e0020:	89 b3 f8 00 00 00    	mov    DWORD PTR [ebx+0xf8],esi
  4e0026:	8b 06                	mov    eax,DWORD PTR [esi]
  4e0028:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4e002c:	8d 73 18             	lea    esi,[ebx+0x18]
  4e002f:	8d 7c 24 14          	lea    edi,[esp+0x14]
  4e0033:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4e0037:	e8 e4 ee 09 00       	call   0x57ef20
  4e003c:	50                   	push   eax
  4e003d:	56                   	push   esi
  4e003e:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  4e0042:	e8 09 e8 09 00       	call   0x57e850
  4e0047:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4e004b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4e0052:	59                   	pop    ecx
  4e0053:	5f                   	pop    edi
  4e0054:	5e                   	pop    esi
  4e0055:	5b                   	pop    ebx
  4e0056:	8b e5                	mov    esp,ebp
  4e0058:	5d                   	pop    ebp
  4e0059:	c2 04 00             	ret    0x4
  4e005c:	cc                   	int3
  4e005d:	cc                   	int3
  4e005e:	cc                   	int3
  4e005f:	cc                   	int3
```

### VA 0x546100–0x5461c0
```asm
00546100 <.text+0x145100>:
  546100:	55                   	push   ebp
  546101:	8b ec                	mov    ebp,esp
  546103:	83 e4 f8             	and    esp,0xfffffff8
  546106:	6a ff                	push   0xffffffff
  546108:	68 6c fe 93 00       	push   0x93fe6c
  54610d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  546113:	50                   	push   eax
  546114:	83 ec 28             	sub    esp,0x28
  546117:	53                   	push   ebx
  546118:	56                   	push   esi
  546119:	57                   	push   edi
  54611a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54611f:	33 c4                	xor    eax,esp
  546121:	50                   	push   eax
  546122:	8d 44 24 38          	lea    eax,[esp+0x38]
  546126:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  54612c:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  546130:	83 3d ac a7 fb 00 03 	cmp    DWORD PTR ds:0xfba7ac,0x3
  546137:	8b 79 0c             	mov    edi,DWORD PTR [ecx+0xc]
  54613a:	c6 44 24 17 00       	mov    BYTE PTR [esp+0x17],0x0
  54613f:	75 0a                	jne    0x54614b
  546141:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  546144:	8d 44 40 03          	lea    eax,[eax+eax*2+0x3]
  546148:	8b 3c 81             	mov    edi,DWORD PTR [ecx+eax*4]
  54614b:	33 f6                	xor    esi,esi
  54614d:	3b fe                	cmp    edi,esi
  54614f:	75 20                	jne    0x546171
  546151:	89 71 7c             	mov    DWORD PTR [ecx+0x7c],esi
  546154:	89 b1 80 00 00 00    	mov    DWORD PTR [ecx+0x80],esi
  54615a:	32 c0                	xor    al,al
  54615c:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  546160:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546167:	59                   	pop    ecx
  546168:	5f                   	pop    edi
  546169:	5e                   	pop    esi
  54616a:	5b                   	pop    ebx
  54616b:	8b e5                	mov    esp,ebp
  54616d:	5d                   	pop    ebp
  54616e:	c2 08 00             	ret    0x8
  546171:	0f b6 87 e4 00 00 00 	movzx  eax,BYTE PTR [edi+0xe4]
  546178:	8b 97 e0 00 00 00    	mov    edx,DWORD PTR [edi+0xe0]
  54617e:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  546181:	88 44 24 30          	mov    BYTE PTR [esp+0x30],al
  546185:	33 c0                	xor    eax,eax
  546187:	89 54 24 2c          	mov    DWORD PTR [esp+0x2c],edx
  54618b:	8a 97 b0 00 00 00    	mov    dl,BYTE PTR [edi+0xb0]
  546191:	66 89 43 02          	mov    WORD PTR [ebx+0x2],ax
  546195:	8a 87 b0 00 00 00    	mov    al,BYTE PTR [edi+0xb0]
  54619b:	88 43 04             	mov    BYTE PTR [ebx+0x4],al
  54619e:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  5461a4:	88 54 24 1c          	mov    BYTE PTR [esp+0x1c],dl
  5461a8:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  5461ac:	3b c6                	cmp    eax,esi
  5461ae:	74 05                	je     0x5461b5
  5461b0:	39 70 34             	cmp    DWORD PTR [eax+0x34],esi
  5461b3:	74 09                	je     0x5461be
  5461b5:	89 71 7c             	mov    DWORD PTR [ecx+0x7c],esi
  5461b8:	89 b1 80 00 00 00    	mov    DWORD PTR [ecx+0x80],esi
  5461be:	f6                   	.byte 0xf6
  5461bf:	05                   	.byte 0x5
```