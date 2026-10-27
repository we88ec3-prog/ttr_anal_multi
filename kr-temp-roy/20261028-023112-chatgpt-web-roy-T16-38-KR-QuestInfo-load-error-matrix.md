# T16-38 — QuestInfo XML 載入及失敗分支 vs 可證明資料邊界

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：QuestInfo XML 載入及失敗分支 vs 可證明資料邊界
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 344 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x00504740` | `0x00504950` | `0x103B40` | `0x005043E9` |
| `0x0072EE30` | `0x0072EF50` | `0x32E230` | `0x004077CD`, `0x0040799C`, `0x0043E826`, `0x0044564A`, `0x0044E9B4`, `0x0045234D`, `0x0046E57D`, `0x00474783`, `0x0047DE8A`, `0x004899DC`, `0x0049EFBD`, `0x004A7B2A` |
| `0x0072F110` | `0x0072F220` | `0x32E510` | `0x004077FE`, `0x004079C1`, `0x0043E84E`, `0x00445679`, `0x0044E2C7`, `0x0044E9E5`, `0x0045236F`, `0x0046E5AF`, `0x004747A4`, `0x0047DEBC`, `0x004899F9`, `0x0049EFEB` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x00504740` .. `0x00504950`

```asm
  504740:	55                   	push   ebp
  504741:	8b ec                	mov    ebp,esp
  504743:	83 e4 f8             	and    esp,0xfffffff8
  504746:	6a ff                	push   0xffffffff
  504748:	68 3d 42 92 00       	push   0x92423d
  50474d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504753:	50                   	push   eax
  504754:	81 ec 48 02 00 00    	sub    esp,0x248
  50475a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50475f:	33 c4                	xor    eax,esp
  504761:	89 84 24 40 02 00 00 	mov    DWORD PTR [esp+0x240],eax
  504768:	53                   	push   ebx
  504769:	56                   	push   esi
  50476a:	57                   	push   edi
  50476b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  504770:	33 c4                	xor    eax,esp
  504772:	50                   	push   eax
  504773:	8d 84 24 58 02 00 00 	lea    eax,[esp+0x258]
  50477a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84 24 64 02 00 00 	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	ff ff ff ff 
  50485b:	83 c4 04             	add    esp,0x4
  50485e:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  504865:	94 23 bf 00 
  504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  504870:	72 10                	jb     0x504882
  504872:	8b 84 24 78 01 00 00 	mov    eax,DWORD PTR [esp+0x178]
  504879:	50                   	push   eax
  50487a:	e8 8d c9 38 00       	call   0x89120c
  50487f:	83 c4 04             	add    esp,0x4
  504882:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  504889:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504890:	0f 00 00 00 
  504894:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50489b:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  5048a2:	00 
  5048a3:	e8 98 97 22 00       	call   0x72e040
  5048a8:	33 c0                	xor    eax,eax
  5048aa:	e9 29 0c 00 00       	jmp    0x5054d8
  5048af:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  5048b2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5048b6:	3b c7                	cmp    eax,edi
  5048b8:	0f 84 c0 0b 00 00    	je     0x50547e
  5048be:	8b ff                	mov    edi,edi
  5048c0:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  5048c4:	51                   	push   ecx
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5048ce:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5048d5:	01 
  5048d6:	8b 11                	mov    edx,DWORD PTR [ecx]
  5048d8:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5048db:	ff d0                	call   eax
  5048dd:	8d 78 44             	lea    edi,[eax+0x44]
  5048e0:	68 d0 d1 be 00       	push   0xbed1d0
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  5048ea:	bb 10 00 00 00       	mov    ebx,0x10
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f3:	83 c0 30             	add    eax,0x30
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74 0b                	je     0x50490c
  504901:	50                   	push   eax
  504902:	e8 ad ce 38 00       	call   0x8917b4
  504907:	83 c4 04             	add    esp,0x4
  50490a:	eb 02                	jmp    0x50490e
  50490c:	33 c0                	xor    eax,eax
  50490e:	68 08 b8 bf 00       	push   0xbfb808
  504913:	89 44 24 68          	mov    DWORD PTR [esp+0x68],eax
  504917:	e8 84 b7 22 00       	call   0x7300a0
  50491c:	85 c0                	test   eax,eax
  50491e:	74 19                	je     0x504939
  504920:	83 c0 30             	add    eax,0x30
  504923:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504926:	72 02                	jb     0x50492a
  504928:	8b 00                	mov    eax,DWORD PTR [eax]
  50492a:	85 c0                	test   eax,eax
  50492c:	74 0b                	je     0x504939
  50492e:	50                   	push   eax
  50492f:	e8 80 ce 38 00       	call   0x8917b4
  504934:	83 c4 04             	add    esp,0x4
  504937:	eb 02                	jmp    0x50493b
  504939:	33 c0                	xor    eax,eax
  50493b:	68 94 db c0 00       	push   0xc0db94
  504940:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
  504944:	e8 57 b7 22 00       	call   0x7300a0
  504949:	85 c0                	test   eax,eax
  50494b:	74 19                	je     0x504966
  50494d:	83 c0 30             	add    eax,0x30
```

### `0x0072EE30` .. `0x0072EF50`

```asm
  72ee30:	55                   	push   ebp
  72ee31:	8b ec                	mov    ebp,esp
  72ee33:	6a ff                	push   0xffffffff
  72ee35:	68 13 96 91 00       	push   0x919613
  72ee3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  72ee40:	50                   	push   eax
  72ee41:	51                   	push   ecx
  72ee42:	53                   	push   ebx
  72ee43:	56                   	push   esi
  72ee44:	57                   	push   edi
  72ee45:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  72ee4a:	33 c5                	xor    eax,ebp
  72ee4c:	50                   	push   eax
  72ee4d:	8d 45 f4             	lea    eax,[ebp-0xc]
  72ee50:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  72ee56:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  72ee59:	83 c8 ff             	or     eax,0xffffffff
  72ee5c:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  72ee5f:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  72ee62:	33 db                	xor    ebx,ebx
  72ee64:	89 5e 0c             	mov    DWORD PTR [esi+0xc],ebx
  72ee67:	89 5e 30             	mov    DWORD PTR [esi+0x30],ebx
  72ee6a:	ba 0f 00 00 00       	mov    edx,0xf
  72ee6f:	89 56 34             	mov    DWORD PTR [esi+0x34],edx
  72ee72:	88 5e 20             	mov    BYTE PTR [esi+0x20],bl
  72ee75:	89 5e 10             	mov    DWORD PTR [esi+0x10],ebx
  72ee78:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  72ee7b:	89 5e 18             	mov    DWORD PTR [esi+0x18],ebx
  72ee7e:	89 5e 1c             	mov    DWORD PTR [esi+0x1c],ebx
  72ee81:	89 5e 3c             	mov    DWORD PTR [esi+0x3c],ebx
  72ee84:	89 5e 40             	mov    DWORD PTR [esi+0x40],ebx
  72ee87:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  72ee8a:	c7 06 94 23 bf 00    	mov    DWORD PTR [esi],0xbf2394
  72ee90:	89 56 60             	mov    DWORD PTR [esi+0x60],edx
  72ee93:	89 5e 5c             	mov    DWORD PTR [esi+0x5c],ebx
  72ee96:	88 5e 4c             	mov    BYTE PTR [esi+0x4c],bl
  72ee99:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  72ee9d:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  72eea0:	89 46 6c             	mov    DWORD PTR [esi+0x6c],eax
  72eea3:	8b c1                	mov    eax,ecx
  72eea5:	8d 50 01             	lea    edx,[eax+0x1]
  72eea8:	c7 46 68 04 00 00 00 	mov    DWORD PTR [esi+0x68],0x4
  72eeaf:	88 5e 74             	mov    BYTE PTR [esi+0x74],bl
  72eeb2:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  72eeb5:	8a 10                	mov    dl,BYTE PTR [eax]
  72eeb7:	40                   	inc    eax
  72eeb8:	3a d3                	cmp    dl,bl
  72eeba:	75 f9                	jne    0x72eeb5
  72eebc:	2b 45 f0             	sub    eax,DWORD PTR [ebp-0x10]
  72eebf:	50                   	push   eax
  72eec0:	51                   	push   ecx
  72eec1:	8d 4e 20             	lea    ecx,[esi+0x20]
  72eec4:	e8 a7 3b cd ff       	call   0x402a70
  72eec9:	53                   	push   ebx
  72eeca:	68 75 23 bf 00       	push   0xbf2375
  72eecf:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  72eed2:	88 5e 44             	mov    BYTE PTR [esi+0x44],bl
  72eed5:	89 5e 48             	mov    DWORD PTR [esi+0x48],ebx
  72eed8:	e8 93 3b cd ff       	call   0x402a70
  72eedd:	89 5e 70             	mov    DWORD PTR [esi+0x70],ebx
  72eee0:	89 5e 6c             	mov    DWORD PTR [esi+0x6c],ebx
  72eee3:	8b c6                	mov    eax,esi
  72eee5:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  72eee8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  72eeef:	59                   	pop    ecx
  72eef0:	5f                   	pop    edi
  72eef1:	5e                   	pop    esi
  72eef2:	5b                   	pop    ebx
  72eef3:	8b e5                	mov    esp,ebp
  72eef5:	5d                   	pop    ebp
  72eef6:	c2 04 00             	ret    0x4
  72eef9:	cc                   	int3
  72eefa:	cc                   	int3
  72eefb:	cc                   	int3
  72eefc:	cc                   	int3
  72eefd:	cc                   	int3
  72eefe:	cc                   	int3
  72eeff:	cc                   	int3
  72ef00:	55                   	push   ebp
  72ef01:	8b ec                	mov    ebp,esp
  72ef03:	6a ff                	push   0xffffffff
  72ef05:	68 e3 95 91 00       	push   0x9195e3
  72ef0a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  72ef10:	50                   	push   eax
  72ef11:	53                   	push   ebx
  72ef12:	56                   	push   esi
  72ef13:	57                   	push   edi
  72ef14:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  72ef19:	33 c5                	xor    eax,ebp
  72ef1b:	50                   	push   eax
  72ef1c:	8d 45 f4             	lea    eax,[ebp-0xc]
  72ef1f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  72ef25:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  72ef28:	33 db                	xor    ebx,ebx
  72ef2a:	83 c8 ff             	or     eax,0xffffffff
  72ef2d:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  72ef30:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  72ef33:	8d 4e 20             	lea    ecx,[esi+0x20]
  72ef36:	89 5e 0c             	mov    DWORD PTR [esi+0xc],ebx
  72ef39:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  72ef3c:	ba 0f 00 00 00       	mov    edx,0xf
  72ef41:	89 51 14             	mov    DWORD PTR [ecx+0x14],edx
  72ef44:	88 19                	mov    BYTE PTR [ecx],bl
  72ef46:	89 5e 10             	mov    DWORD PTR [esi+0x10],ebx
  72ef49:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  72ef4c:	89 5e 18             	mov    DWORD PTR [esi+0x18],ebx
  72ef4f:	89               	mov    DWORD PTR [esi+0x1c],ebx
```

### `0x0072F110` .. `0x0072F220`

```asm
  72f110:	55                   	push   ebp
  72f111:	8b ec                	mov    ebp,esp
  72f113:	6a ff                	push   0xffffffff
  72f115:	68 f8 4b 91 00       	push   0x914bf8
  72f11a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  72f120:	50                   	push   eax
  72f121:	83 ec 2c             	sub    esp,0x2c
  72f124:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  72f129:	33 c5                	xor    eax,ebp
  72f12b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  72f12e:	53                   	push   ebx
  72f12f:	57                   	push   edi
  72f130:	50                   	push   eax
  72f131:	8d 45 f4             	lea    eax,[ebp-0xc]
  72f134:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  72f13a:	33 db                	xor    ebx,ebx
  72f13c:	8b c1                	mov    eax,ecx
  72f13e:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  72f145:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  72f148:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  72f14b:	8d 78 01             	lea    edi,[eax+0x1]
  72f14e:	8b ff                	mov    edi,edi
  72f150:	8a 10                	mov    dl,BYTE PTR [eax]
  72f152:	40                   	inc    eax
  72f153:	84 d2                	test   dl,dl
  72f155:	75 f9                	jne    0x72f150
  72f157:	2b c7                	sub    eax,edi
  72f159:	50                   	push   eax
  72f15a:	51                   	push   ecx
  72f15b:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  72f15e:	e8 0d 39 cd ff       	call   0x402a70
  72f163:	6a ff                	push   0xffffffff
  72f165:	53                   	push   ebx
  72f166:	8d 45 d4             	lea    eax,[ebp-0x2c]
  72f169:	8d 7e 20             	lea    edi,[esi+0x20]
  72f16c:	50                   	push   eax
  72f16d:	8b cf                	mov    ecx,edi
  72f16f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  72f172:	e8 c9 3e cd ff       	call   0x403040
  72f177:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  72f17b:	72 04                	jb     0x72f181
  72f17d:	8b 07                	mov    eax,DWORD PTR [edi]
  72f17f:	eb 02                	jmp    0x72f183
  72f181:	8b c7                	mov    eax,edi
  72f183:	68 e0 d1 be 00       	push   0xbed1e0
  72f188:	50                   	push   eax
  72f189:	e8 e2 55 fe ff       	call   0x714770
  72f18e:	8b d8                	mov    ebx,eax
  72f190:	83 c4 08             	add    esp,0x8
  72f193:	85 db                	test   ebx,ebx
  72f195:	74 30                	je     0x72f1c7
  72f197:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  72f19a:	51                   	push   ecx
  72f19b:	8b d3                	mov    edx,ebx
  72f19d:	8b ce                	mov    ecx,esi
  72f19f:	e8 bc 00 00 00       	call   0x72f260
  72f1a4:	8b 13                	mov    edx,DWORD PTR [ebx]
  72f1a6:	88 45 d3             	mov    BYTE PTR [ebp-0x2d],al
  72f1a9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  72f1ac:	8b cb                	mov    ecx,ebx
  72f1ae:	ff d0                	call   eax
  72f1b0:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  72f1b4:	72 0c                	jb     0x72f1c2
  72f1b6:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  72f1b9:	51                   	push   ecx
  72f1ba:	e8 4d 20 16 00       	call   0x89120c
  72f1bf:	83 c4 04             	add    esp,0x4
  72f1c2:	8a 45 d3             	mov    al,BYTE PTR [ebp-0x2d]
  72f1c5:	eb 71                	jmp    0x72f238
  72f1c7:	80 7e 44 00          	cmp    BYTE PTR [esi+0x44],0x0
  72f1cb:	75 57                	jne    0x72f224
  72f1cd:	c6 46 44 01          	mov    BYTE PTR [esi+0x44],0x1
  72f1d1:	c7 46 48 02 00 00 00 	mov    DWORD PTR [esi+0x48],0x2
  72f1d8:	8b 15 90 3c d6 00    	mov    edx,DWORD PTR ds:0xd63c90
  72f1de:	8b c2                	mov    eax,edx
  72f1e0:	8d 58 01             	lea    ebx,[eax+0x1]
  72f1e3:	8a 08                	mov    cl,BYTE PTR [eax]
  72f1e5:	40                   	inc    eax
  72f1e6:	84 c9                	test   cl,cl
  72f1e8:	75 f9                	jne    0x72f1e3
  72f1ea:	2b c3                	sub    eax,ebx
  72f1ec:	50                   	push   eax
  72f1ed:	52                   	push   edx
  72f1ee:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  72f1f1:	e8 7a 38 cd ff       	call   0x402a70
  72f1f6:	83 c8 ff             	or     eax,0xffffffff
  72f1f9:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  72f1fc:	89 46 6c             	mov    DWORD PTR [esi+0x6c],eax
  72f1ff:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  72f203:	c7 45 cc f4 51 c4 00 	mov    DWORD PTR [ebp-0x34],0xc451f4
  72f20a:	72 02                	jb     0x72f20e
  72f20c:	8b 3f                	mov    edi,DWORD PTR [edi]
  72f20e:	6a 00                	push   0x0
  72f210:	6a 00                	push   0x0
  72f212:	6a 00                	push   0x0
  72f214:	8d 55 cc             	lea    edx,[ebp-0x34]
  72f217:	52                   	push   edx
  72f218:	8b d7                	mov    edx,edi
  72f21a:	b9 02 00 00 00       	mov    ecx,0x2
  72f21f:	e8           	call   0x731de0
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  504794:	e8 97 a6 22 00       	call   0x72ee30
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504825:	e8 16 98 22 00       	call   0x72e040
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  50487a:	e8 8d c9 38 00       	call   0x89120c
  5048a3:	e8 98 97 22 00       	call   0x72e040
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048db:	ff d0                	call   eax
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  504902:	e8 ad ce 38 00       	call   0x8917b4
  504917:	e8 84 b7 22 00       	call   0x7300a0
  50492f:	e8 80 ce 38 00       	call   0x8917b4
  504944:	e8 57 b7 22 00       	call   0x7300a0
  72eec4:	e8 a7 3b cd ff       	call   0x402a70
  72eed8:	e8 93 3b cd ff       	call   0x402a70
  72f15e:	e8 0d 39 cd ff       	call   0x402a70
  72f172:	e8 c9 3e cd ff       	call   0x403040
  72f189:	e8 e2 55 fe ff       	call   0x714770
  72f19f:	e8 bc 00 00 00       	call   0x72f260
  72f1ae:	ff d0                	call   eax
  72f1ba:	e8 4d 20 16 00       	call   0x89120c
  72f1f1:	e8 7a 38 cd ff       	call   0x402a70
  72f21f:	e8           	call   0x731de0
```

比較、測試及分支位置（節錄）：

```asm
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d3:	74 5c                	je     0x504831
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  504870:	72 10                	jb     0x504882
  5048aa:	e9 29 0c 00 00       	jmp    0x5054d8
  5048b6:	3b c7                	cmp    eax,edi
  5048b8:	0f 84 c0 0b 00 00    	je     0x50547e
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74 0b                	je     0x50490c
  50490a:	eb 02                	jmp    0x50490e
  50491c:	85 c0                	test   eax,eax
  50491e:	74 19                	je     0x504939
  504923:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504926:	72 02                	jb     0x50492a
  50492a:	85 c0                	test   eax,eax
  50492c:	74 0b                	je     0x504939
  504937:	eb 02                	jmp    0x50493b
  504949:	85 c0                	test   eax,eax
  50494b:	74 19                	je     0x504966
```

### 最低限度的局部偽碼（語義不作確定）

```cpp
// Abstracted from instruction traces, not reconstructed source.
void candidate_native_path(State* opaque, Input* candidate) {
    // Calls and conditional transitions follow the literal assembly above.
    // Unknowns: field ownership, valid input domain, caller context, side effects.
    // Any quest step / success / tutorial flag semantics remain unknown.
}
```

## 5. T16 功能鏈驗收矩陣

| 驗證項 | 狀態 | 說明 |
|---|---|---|
| KR 映像版本與 VA 原生反組譯 | 原生已確認 | 本段實際读取 BIN 機器碼並附起訖區間 |
| 選定指令之直接 call / branch | 原生已確認（有界） | 詳見 assembly，非完整函式 call graph |
| 此路徑是否屬 Quest / Tutorial 的業務邏輯 | 部分確認／推測 | 依前批上下文選取；需要 event 與進度鏈封閉 |
| 伺服器權威任務 writer | 資訊缺失 | 未由本段地址鎖定 |
| 教學步驟及觸發旗標 | 資訊缺失 | 不能由腳本入口名稱倒推 |
| 教學完成後第一個主線 | 資訊缺失 | 無原生 quest/step ID |
| TC 版本函式對應 | 資訊缺失 | 本段只使用 KR BIN |
| 可玩性驗證 | 未測試 | 禁止將原生指令分析視為可玩 |

## 6. 跨 Task 分工與證據風險

- T02：封包 envelope／dispatcher 是其主責；T16 僅需任務業務欄位與事件結果。
- T03/T04：登入與既有角色是 T16 的輸入；不可臆造新角色教學初始值。
- T07/T14：關卡轉場／結算由其主責，T16 僅需其對進度的輸入事件。
- T15：持久化底層，T16 僅指定需要寫入或恢復之欄位（目前 unknown）。
- T08：實體行為僅作事件界面引用。

## 7. 延後本地資源（DEFERRED-LOCAL-RESOURCE）

| 來源 | 待本地分析交付的最小內容 | 阻塞語義 |
|---|---|---|
| `Event/TutorialMain.lua` | 函式定義／呼叫、步驟與事件線索、原檔 SHA | 教學節點序列／完成條件 |
| `Event/TutorialBase.lua` | 提供的 Lua API 清單及參數 | 客戶端教學行為 |
| `Table/QuestInfo.xml` | Quest/step ID 與前置條件及資料 schema | 主線入口／依賴 |
| `Table/QuestTalk.xml` | NPC／對話／任務 ID 關聯及 SHA | 交付與對話 |
| 原版伺服器任務資料與封包 | 任務業務欄位、接受／拒絕及重登資料 | 權威、儲存、恢復 |

以上列為延後，本批不要求、下載或臆造檔案。

## 8. 後續應查項目

1. 從本段已驗證的 branch / call 對應上游條件與下游 consumer；目標是可確認業務 writer，而非重複解析 CRT 或 container。
2. 比對 T16-1～T16-32 有界結論，釐清新發現是否真能跨越任務介面。
3. 有足夠原生來源前不將任何 `0x6`、Quest 顯示文字或本地補丁當作原版進度旗標。
4. 將原始資源缺口留待本地流程回填，下一段仍優先研究 BIN/EXE 可證實的路徑。

## 9. 提交狀態

本文件生成時為原始本地稿；是否已推 GitHub 以後續實際提交收據為準。