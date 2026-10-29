# T16-051 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md`
- **舊原稿 Git blob SHA**：`d6591307065c066485ec3e312aafe69b38c72448`
- T01 通知：`T01-RETURN-T16-051-c26518b1`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容


### 討論附錄指令起點錯誤 — 修正提案

T01 marked the supplemental assembly windows below as having **instruction-boundary risk or incorrect decoding**. One `0x4AEDAF→0x4AEDB0` pair additionally overlaps a possible distinct function-entry prologue and must not be judged by naive linear scanning of preceding data. A linear `objdump --start-address` from the bad address will invent instructions; remove affected rows, branch lists and any conclusions that depend on them. For each address below, preserve the source historical appendix unchanged; the listed **candidate preceding instruction anchor** is only a local decode location, not proof of a reachable root or that the original entry is invalid. In particular, the `0x4AEDB0` case needs function-start proof. Full function-root/control-flow re-decoding and independent T01 re-review are still required for a `READY_FOR_REVIEW` claim; this is explicitly **not** a fabricated full rooted CFG.


|原錯誤起點|候選前置 decode 起點（T01 建議／本次局部重解）|實檔 raw 摘要|
|---|---|---|
|`0x504817`|`0x504816`|`VA 0x00504816, .text raw 0x00103C16: 89 bc 24 88 01 00 00 c6 84 24 78 01`|
|`0x50564B`|`0x50564A`|`VA 0x0050564A, .text raw 0x00104A4A: e8 91 8c 22 00 3b c3 75 5c 68 50 dc`|

#### 原始 bytes 上 anchored decode（只是候選局部窗口，非全 CFG）

`原錯誤窗口起點 0x504817`，從先前指令 `0x504816` 解碼：

```asm
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98         	call   0x72e040
```

`原錯誤窗口起點 0x50564B`，從先前指令 `0x50564A` 解碼：

```asm
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e        	call   0x6edb60
```

**需 T01 下一步：** 找到完整 containing function entry，從 root 和可到達 edges 重新解碼，重做原報告附錄與由該附錄推導的所有 call/branch list；未修完前不要標 `READY_FOR_REVIEW`。

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x504740` 到 `0x504990`

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
  504950:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504953:	72 02                	jb     0x504957
  504955:	8b 00                	mov    eax,DWORD PTR [eax]
  504957:	85 c0                	test   eax,eax
  504959:	74 0b                	je     0x504966
  50495b:	50                   	push   eax
  50495c:	e8 53 ce 38 00       	call   0x8917b4
  504961:	83 c4 04             	add    esp,0x4
  504964:	eb 02                	jmp    0x504968
  504966:	33 c0                	xor    eax,eax
  504968:	68 9c db c0 00       	push   0xc0db9c
  50496d:	89 44 24 70          	mov    DWORD PTR [esp+0x70],eax
  504971:	e8 2a b7 22 00       	call   0x7300a0
  504976:	85 c0                	test   eax,eax
  504978:	74 19                	je     0x504993
  50497a:	83 c0 30             	add    eax,0x30
  50497d:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504980:	72 02                	jb     0x504984
  504982:	8b 00                	mov    eax,DWORD PTR [eax]
  504984:	85 c0                	test   eax,eax
  504986:	74 0b                	je     0x504993
  504988:	50                   	push   eax
  504989:	e8 26 ce 38 00       	call   0x8917b4
  50498e:	83 c4              	add    esp,0x4
```

### 入口 `0x505570` 到 `0x505710`

```asm
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
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e 00       	call   0x6edb60
  50565d:	c7 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],0xffffffff
  505664:	ff ff ff ff 
  505668:	83 c4 04             	add    esp,0x4
  50566b:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505672:	00 
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50567a:	72 0d                	jb     0x505689
  50567c:	8b 44 24 70          	mov    eax,DWORD PTR [esp+0x70]
  505680:	50                   	push   eax
  505681:	e8 86 bb 38 00       	call   0x89120c
  505686:	83 c4 04             	add    esp,0x4
  505689:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50568d:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505694:	0f 00 00 00 
  505698:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  50569f:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  5056a3:	e8 98 89 22 00       	call   0x72e040
  5056a8:	33 c0                	xor    eax,eax
  5056aa:	e9 7e 01 00 00       	jmp    0x50582d
  5056af:	e8 7c 13 00 00       	call   0x506a30
  5056b4:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5056b8:	3b c3                	cmp    eax,ebx
  5056ba:	0f 84 20 01 00 00    	je     0x5057e0
  5056c0:	eb 04                	jmp    0x5056c6
  5056c2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5056c6:	8d 78 44             	lea    edi,[eax+0x44]
  5056c9:	68 d0 d1 be 00       	push   0xbed1d0
  5056ce:	e8 cd a9 22 00       	call   0x7300a0
  5056d3:	3b c3                	cmp    eax,ebx
  5056d5:	74 1a                	je     0x5056f1
  5056d7:	83 c0 30             	add    eax,0x30
  5056da:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5056de:	72 02                	jb     0x5056e2
  5056e0:	8b 00                	mov    eax,DWORD PTR [eax]
  5056e2:	3b c3                	cmp    eax,ebx
  5056e4:	74 0b                	je     0x5056f1
  5056e6:	50                   	push   eax
  5056e7:	e8 c8 c0 38 00       	call   0x8917b4
  5056ec:	83 c4 04             	add    esp,0x4
  5056ef:	eb 02                	jmp    0x5056f3
  5056f1:	33 c0                	xor    eax,eax
  5056f3:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5056f7:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  5056fb:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  5056ff:	51                   	push   ecx
  505700:	8d 44 24 20          	lea    eax,[esp+0x20]
  505704:	8b ce                	mov    ecx,esi
  505706:	e8 15 e6 ff ff       	call   0x503d20
  50570b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  50570f:	3b               	cmp    ecx,DWORD PTR [esi+0x4]
```


## 修正影響／驗收門檻

- **Client 待逆向**：此勘誤沒有證成任何新的 Quest S→C wire opcode 或 Quest16→15 接取 UI 閉環。
- **Server 待開發**：相容 Server 的任務前置、解鎖、持久化由 S00 SPEC/ADR 獨立設計，不可由局部 ASM 冒稱官方判斷。
- **跨功能待整合**：如涉及 T02 framing/網路、T06 UI 等，由相關 Task 的原始證據及 T01 claim-level review 處理。
- **待遊玩驗證**：未執行原 Client 或動態封包測試。
- **T01 狀態**：GitHub 仍為 `NEEDS_FIX`/`NEEDS_QUALIFICATION`；待來源 Task 將此勘誤審核／提交後，才能提出 `READY_FOR_REVIEW`，且 T01 通過才可 `RESOLVED`。

## 原始來源／交叉引用

- `kr/tasks/T16/README.md` 上固定退回 ID 和精確 blob SHA。
- `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`；`shared/integrations/T01-20261029-continuation-02/t16/README.md`。
- `shared/verified-knowledge/README.md` 的有界條目不等於本篇 FULL-PASS。
