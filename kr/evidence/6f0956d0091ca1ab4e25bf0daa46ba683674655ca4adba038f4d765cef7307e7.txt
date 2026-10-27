# T10-57 — 映射讀取者與矩陣消費者的型別邊界

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x594610` 回傳映射結果的查詢轉換，`0x5CD91F` 為其直接 caller，`0x5CD937` 有 `×0xB` 的索引計算。矩陣 `WORD` 不等於 phase byte；沒有 `KeyMapping.xml` 和 action row 就不能聲稱 Z/X/C/V 映射已解。

## 映射消費呼叫交叉參照

`0x594610` direct E8 候選：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。僅作位址索引，未完成 receiver 重建。

## 第一手 x86 反組譯摘錄

### VA `0x00594610` ／ raw `0x00193A10`（320 bytes）

```asm
  594610:	55                   	push   ebp
  594611:	8b ec                	mov    ebp,esp
  594613:	83 e4 f8             	and    esp,0xfffffff8
  594616:	6a ff                	push   0xffffffff
  594618:	68 00 70 92 00       	push   0x927000
  59461d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  594623:	50                   	push   eax
  594624:	83 ec 60             	sub    esp,0x60
  594627:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59462c:	33 c4                	xor    eax,esp
  59462e:	89 44 24 58          	mov    DWORD PTR [esp+0x58],eax
  594632:	53                   	push   ebx
  594633:	56                   	push   esi
  594634:	57                   	push   edi
  594635:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59463a:	33 c4                	xor    eax,esp
  59463c:	50                   	push   eax
  59463d:	8d 44 24 70          	lea    eax,[esp+0x70]
  594641:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  594647:	8b f9                	mov    edi,ecx
  594649:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  59464c:	33 db                	xor    ebx,ebx
  59464e:	8b f2                	mov    esi,edx
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  5946e1:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  5946e4:	74 12                	je     0x5946f8
  5946e6:	8b 10                	mov    edx,DWORD PTR [eax]
  5946e8:	52                   	push   edx
  5946e9:	8d 74 24 50          	lea    esi,[esp+0x50]
  5946ed:	e8 8e 03 00 00       	call   0x594a80
  5946f2:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5946f6:	eb 0c                	jmp    0x594704
  5946f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5946fa:	50                   	push   eax
  5946fb:	8d 44 24 50          	lea    eax,[esp+0x50]
  5946ff:	e8 6c fe ff ff       	call   0x594570
  594704:	6a ff                	push   0xffffffff
  594706:	53                   	push   ebx
  594707:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59470b:	51                   	push   ecx
  59470c:	8b ce                	mov    ecx,esi
  59470e:	e8 dd fa e6 ff       	call   0x4041f0
  594713:	6a 02                	push   0x2
  594715:	6a 0e                	push   0xe
  594717:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59471b:	e8 a0 06 14 00       	call   0x6d4dc0
  594720:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594724:	83 c4 08             	add    esp,0x8
  594727:	3b 7c 24 20          	cmp    edi,DWORD PTR [esp+0x20]
  59472b:	74 2f                	je     0x59475c
  59472d:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594730:	74 16                	je     0x594748
  594732:	8b 17                	mov    edx,DWORD PTR [edi]
  594734:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594738:	52                   	push   edx
  594739:	8d 74 24 50          	lea    esi,[esp+0x50]
  59473d:	e8 3e 03 00 00       	call   0x594a80
  594742:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  594746:	eb 10                	jmp    0x594758
  594748:	8b 07                	mov    eax,DWORD PTR [edi]
  59474a:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  59474e:	50                   	push   eax
  59474f:	8d                   	.byte 0x8d
```

### VA `0x005CD890` ／ raw `0x001CCC90`（245 bytes）

```asm
  5cd890:	30 89 54 24 14 eb    	xor    BYTE PTR [ecx-0x14ebdbac],cl
  5cd896:	08 8b 4c 24 24 89    	or     BYTE PTR [ebx-0x76dbdbb4],cl
  5cd89c:	4c                   	dec    esp
  5cd89d:	24 14                	and    al,0x14
  5cd89f:	33 db                	xor    ebx,ebx
  5cd8a1:	89 5c 24 68          	mov    DWORD PTR [esp+0x68],ebx
  5cd8a5:	8b f0                	mov    esi,eax
  5cd8a7:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5cd8ab:	eb 03                	jmp    0x5cd8b0
  5cd8ad:	8d 49 00             	lea    ecx,[ecx+0x0]
  5cd8b0:	33 d2                	xor    edx,edx
  5cd8b2:	c7 84 24 bc 00 00 00 	mov    DWORD PTR [esp+0xbc],0x7
  5cd8b9:	07 00 00 00 
  5cd8bd:	c7 84 24 b8 00 00 00 	mov    DWORD PTR [esp+0xb8],0x0
  5cd8c4:	00 00 00 00 
  5cd8c8:	66 89 94 24 a8 00 00 	mov    WORD PTR [esp+0xa8],dx
  5cd8cf:	00 
  5cd8d0:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xd
  5cd8d7:	0d 
  5cd8d8:	f6 05 10 fb fd 00 01 	test   BYTE PTR ds:0xfdfb10,0x1
  5cd8df:	75 29                	jne    0x5cd90a
  5cd8e1:	83 0d 10 fb fd 00 01 	or     DWORD PTR ds:0xfdfb10,0x1
  5cd8e8:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xe
  5cd8ef:	0e 
  5cd8f0:	e8 6b 2e fc ff       	call   0x590760
  5cd8f5:	68 60 e7 bc 00       	push   0xbce760
  5cd8fa:	e8 1b 4a 2c 00       	call   0x89231a
  5cd8ff:	83 c4 04             	add    esp,0x4
  5cd902:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xd
  5cd909:	0d 
  5cd90a:	8b 0c 9d f0 32 f8 00 	mov    ecx,DWORD PTR [ebx*4+0xf832f0]
  5cd911:	6a 01                	push   0x1
  5cd913:	68 18 fb fd 00       	push   0xfdfb18
  5cd918:	8d 94 24 b0 00 00 00 	lea    edx,[esp+0xb0]
  5cd91f:	e8 ec 6c fc ff       	call   0x594610
  5cd924:	8a 4c 24 14          	mov    cl,BYTE PTR [esp+0x14]
  5cd928:	8d 43 01             	lea    eax,[ebx+0x1]
  5cd92b:	80 f9 04             	cmp    cl,0x4
  5cd92e:	73 1a                	jae    0x5cd94a
  5cd930:	3c 0b                	cmp    al,0xb
  5cd932:	73 16                	jae    0x5cd94a
  5cd934:	0f b6 c9             	movzx  ecx,cl
  5cd937:	6b c9 0b             	imul   ecx,ecx,0xb
  5cd93a:	0f b6 d0             	movzx  edx,al
  5cd93d:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5cd941:	03 ca                	add    ecx,edx
  5cd943:	0f b7 44 48 04       	movzx  eax,WORD PTR [eax+ecx*2+0x4]
  5cd948:	eb 02                	jmp    0x5cd94c
  5cd94a:	33 c0                	xor    eax,eax
  5cd94c:	0f b7 c8             	movzx  ecx,ax
  5cd94f:	8d 54 24 44          	lea    edx,[esp+0x44]
  5cd953:	89 4c 24 44          	mov    DWORD PTR [esp+0x44],ecx
  5cd957:	52                   	push   edx
  5cd958:	8d 84 24 a4 00 00 00 	lea    eax,[esp+0xa4]
  5cd95f:	8b cf                	mov    ecx,edi
  5cd961:	e8 1a 89 25 00       	call   0x826280
  5cd966:	8b 8c 24 a0 00 00 00 	mov    ecx,DWORD PTR [esp+0xa0]
  5cd96d:	3b 4f 04             	cmp    ecx,DWORD PTR [edi+0x4]
  5cd970:	0f 84 fe 02 00 00    	je     0x5cdc74
  5cd976:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  5cd979:	85 c0                	test   eax,eax
  5cd97b:	0f 84 f3 02 00 00    	je     0x5cdc74
  5cd981:	0f b7 48 04          	movzx  ecx,WORD PTR [eax+0x4]
```

### VA `0x005CD925` ／ raw `0x001CCD25`（150 bytes）

```asm
  5cd925:	4c                   	dec    esp
  5cd926:	24 14                	and    al,0x14
  5cd928:	8d 43 01             	lea    eax,[ebx+0x1]
  5cd92b:	80 f9 04             	cmp    cl,0x4
  5cd92e:	73 1a                	jae    0x5cd94a
  5cd930:	3c 0b                	cmp    al,0xb
  5cd932:	73 16                	jae    0x5cd94a
  5cd934:	0f b6 c9             	movzx  ecx,cl
  5cd937:	6b c9 0b             	imul   ecx,ecx,0xb
  5cd93a:	0f b6 d0             	movzx  edx,al
  5cd93d:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5cd941:	03 ca                	add    ecx,edx
  5cd943:	0f b7 44 48 04       	movzx  eax,WORD PTR [eax+ecx*2+0x4]
  5cd948:	eb 02                	jmp    0x5cd94c
  5cd94a:	33 c0                	xor    eax,eax
  5cd94c:	0f b7 c8             	movzx  ecx,ax
  5cd94f:	8d 54 24 44          	lea    edx,[esp+0x44]
  5cd953:	89 4c 24 44          	mov    DWORD PTR [esp+0x44],ecx
  5cd957:	52                   	push   edx
  5cd958:	8d 84 24 a4 00 00 00 	lea    eax,[esp+0xa4]
  5cd95f:	8b cf                	mov    ecx,edi
  5cd961:	e8 1a 89 25 00       	call   0x826280
  5cd966:	8b 8c 24 a0 00 00 00 	mov    ecx,DWORD PTR [esp+0xa0]
  5cd96d:	3b 4f 04             	cmp    ecx,DWORD PTR [edi+0x4]
  5cd970:	0f 84 fe 02 00 00    	je     0x5cdc74
  5cd976:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  5cd979:	85 c0                	test   eax,eax
  5cd97b:	0f 84 f3 02 00 00    	je     0x5cdc74
  5cd981:	0f b7 48 04          	movzx  ecx,WORD PTR [eax+0x4]
  5cd985:	66 85 c9             	test   cx,cx
  5cd988:	0f 84 e6 02 00 00    	je     0x5cdc74
  5cd98e:	8b 38                	mov    edi,DWORD PTR [eax]
  5cd990:	8b f1                	mov    esi,ecx
  5cd992:	89 74 24 44          	mov    DWORD PTR [esp+0x44],esi
  5cd996:	e8 15 75 eb ff       	call   0x484eb0
  5cd99b:	50                   	push   eax
  5cd99c:	8b c6                	mov    eax,esi
  5cd99e:	8b cf                	mov    ecx,edi
  5cd9a0:	e8 8b 2b f6 ff       	call   0x530530
  5cd9a5:	8b d8                	mov    ebx,eax
  5cd9a7:	e8 04 75 eb ff       	call   0x484eb0
  5cd9ac:	50                   	push   eax
  5cd9ad:	8b c6                	mov    eax,esi
  5cd9af:	8b cf                	mov    ecx,edi
  5cd9b1:	e8 0a 2c f6 ff       	call   0x5305c0
  5cd9b6:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
  5cd9ba:	e8                   	.byte 0xe8
```

## 已確認／部分確認／未證實

- **已確認（區域性）：** 本檔指定 VA 的可讀原始 byte 及列出的直接讀寫／call 指令；以相應位址及前置條件為限。
- **部分確認：** 這些路徑具備輸入資料結構或 controller 消費候選的關聯，確切 receiver／建構實例與完整 CFG 仍待核實。
- **未證實：** Z/X/C/V 自訂 action mapping、V 點按／長按真正的 timer/tier writer、連按 Z 和 held Z 自動續段、動畫完成 callback、普攻↔技能 queue/cancel、官方後端裁決。

## 與既有 T10-45～52／T01 整合的關係

此段為原始 BIN 的**限定驗證／擴充證據盤點**，不取代 T10-1～44 原稿或 T01-20261027-05 的有限語義接受範圍；同 offset 不能跨型別混用。使用者玩家觀察只是動機，非原生已證事實。

## 下一步可驗證路線

1. 向後追 key state 的 **非零 writer**：找不依賴絕對位址常數的 base+index store 或由 keyboard/DirectInput/window message 注入的 callback。
2. 驗證同一個 actor/controller receiver 的建構、指派、虛表及動作啟動 writer，再連接 motion completion 的 next-action queue。
3. 取得此版本的 KeyMapping.xml/fallback row 並比對 action id 與實際鍵狀態，不把 `VK_Z` 寫死。

## GitHub 提交界線

僅使用者授權的 `kr-temp-roy/` 新檔；不變更 owner、catalog、其他 Task 或原始執行檔。