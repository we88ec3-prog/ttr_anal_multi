# T16-51 — KR QuestInfo／QuestTalk 原生資源 reader 邊界與資料域

- 研究時間：2026-10-28；研究者 chatgpt-web roy；KR T16 only。
- 原始 KR BIN：12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本批次未啟動或修改檔案。
- 來源優先：本機原始 BIN/PE、已核對的 GitHub main 和 T16-45～48。
- 注意：以下機器碼中的函式語意是有限範圍判斷；沒有 server source/封包便不宣稱 server 端任務狀態。

## KR BIN 上 reader 候選的機器碼

### `0x00504740`（raw 0x103B40）

```asm
00504740 <.data>:
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
  504816:	89                   	.byte 0x89
  504817:	bc 24 88 01 00       	mov    esp,0x18824
```

### `0x00505570`（raw 0x104970）

```asm
00505570 <.data>:
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8                   	.byte 0xe8
  50564b:	91                   	xchg   ecx,eax
```

### `0x004A8B90`（raw 0xA7F90）

```asm
004a8b90 <.data>:
  4a8b90:	55                   	push   ebp
  4a8b91:	8b ec                	mov    ebp,esp
  4a8b93:	83 ec 18             	sub    esp,0x18
  4a8b96:	53                   	push   ebx
  4a8b97:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a8b9a:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a8b9c:	56                   	push   esi
  4a8b9d:	57                   	push   edi
  4a8b9e:	68 d4 68 c0 00       	push   0xc068d4
  4a8ba3:	6a 01                	push   0x1
  4a8ba5:	50                   	push   eax
  4a8ba6:	e8 f5 44 00 00       	call   0x4ad0a0
  4a8bab:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a8bad:	8b 09                	mov    ecx,DWORD PTR [ecx]
  4a8baf:	83 c8 ff             	or     eax,0xffffffff
  4a8bb2:	e8 39 c5 24 00       	call   0x6f50f0
  4a8bb7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a8bba:	83 f9 03             	cmp    ecx,0x3
  4a8bbd:	74 26                	je     0x4a8be5
  4a8bbf:	83 f9 04             	cmp    ecx,0x4
  4a8bc2:	75 42                	jne    0x4a8c06
  4a8bc4:	8b 30                	mov    esi,DWORD PTR [eax]
  4a8bc6:	83 c6 10             	add    esi,0x10
  4a8bc9:	8d 7d f4             	lea    edi,[ebp-0xc]
  4a8bcc:	e8 8f eb 24 00       	call   0x6f7760
  4a8bd1:	85 c0                	test   eax,eax
  4a8bd3:	74 31                	je     0x4a8c06
  4a8bd5:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4a8bd8:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [ebp-0xc],0x3
  4a8bdf:	dd 5d ec             	fstp   QWORD PTR [ebp-0x14]
  4a8be2:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8be5:	dd 00                	fld    QWORD PTR [eax]
  4a8be7:	dd 5d f4             	fstp   QWORD PTR [ebp-0xc]
  4a8bea:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4a8bed:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a8bf0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a8bf3:	33 d2                	xor    edx,edx
  4a8bf5:	85 c0                	test   eax,eax
  4a8bf7:	0f 95 c2             	setne  dl
  4a8bfa:	89 53 34             	mov    DWORD PTR [ebx+0x34],edx
  4a8bfd:	5f                   	pop    edi
  4a8bfe:	5e                   	pop    esi
  4a8bff:	5b                   	pop    ebx
  4a8c00:	8b e5                	mov    esp,ebp
  4a8c02:	5d                   	pop    ebp
  4a8c03:	c2 04 00             	ret    0x4
  4a8c06:	33 d2                	xor    edx,edx
  4a8c08:	33 c0                	xor    eax,eax
  4a8c0a:	85 c0                	test   eax,eax
  4a8c0c:	0f 95 c2             	setne  dl
  4a8c0f:	5f                   	pop    edi
  4a8c10:	5e                   	pop    esi
  4a8c11:	89 53 34             	mov    DWORD PTR [ebx+0x34],edx
  4a8c14:	5b                   	pop    ebx
  4a8c15:	8b e5                	mov    esp,ebp
  4a8c17:	5d                   	pop    ebp
  4a8c18:	c2 04 00             	ret    0x4
  4a8c1b:	cc                   	int3
  4a8c1c:	cc                   	int3
  4a8c1d:	cc                   	int3
  4a8c1e:	cc                   	int3
  4a8c1f:	cc                   	int3
  4a8c20:	55                   	push   ebp
  4a8c21:	8b ec                	mov    ebp,esp
  4a8c23:	83 e4 f8             	and    esp,0xfffffff8
  4a8c26:	6a ff                	push   0xffffffff
  4a8c28:	68 b7 4f 92 00       	push   0x924fb7
  4a8c2d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8c33:	50                   	push   eax
  4a8c34:	81 ec 20 01 00 00    	sub    esp,0x120
  4a8c3a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8c3f:	33 c4                	xor    eax,esp
  4a8c41:	89 84 24 18 01 00 00 	mov    DWORD PTR [esp+0x118],eax
  4a8c48:	53                   	push   ebx
  4a8c49:	56                   	push   esi
  4a8c4a:	57                   	push   edi
  4a8c4b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8c50:	33 c4                	xor    eax,esp
  4a8c52:	50                   	push   eax
  4a8c53:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  4a8c5a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8c60:	8d 84 24 ac 00 00 00 	lea    eax,[esp+0xac]
  4a8c67:	8b f9                	mov    edi,ecx
  4a8c69:	50                   	push   eax
  4a8c6a:	b9                   	.byte 0xb9
  4a8c6b:	e0                   	.byte 0xe0
```

## 實際來源與不成立的跨域推論

- 已讀 KR `QuestTalk.xml` 初段 `<Quest id="13" givertalk="387" givertotalk="389" finishertalk="390"/>` 後直接見 `<Quest id="17" .../>`，只能認定**這個可見的 XML 區域未列出 id 14/15/16**；不是整個 QuestInfo 的欄位證據。原件 SHA `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`。
- `QuestInfo.xml` 的原件仍標為 **DEFERRED-LOCAL-RESOURCE**：SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`；缺任務 15/16 的 XML element、前置欄位、giver/finisher、NPC 與場景關聯。
- 已找到 table reader 候選入口也不表示該表具任務持久化權威；原版 C++ client 管理器內記憶體常駐資料，和 server quest writer 必須分開取證。
- `QuestInfo id`、`QuestTalk id`、`scenario id`、`stage id` 以及 `TutoQuest` 不能在沒明確 getter/condition 時強行視為相同 namespace。

## 接棒

針對 BIN reader 上游 XML element getter / table index、下游 UI consumer 的**可重現呼叫位置**進一步擴展；封包業務語義需真正的 send/receive callsite / command field / server handling。不得用 client XML 取代 server 完成條件。