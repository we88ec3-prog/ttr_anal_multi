# T10-086 — 全域狀態 0xFB73E8 與角色切換路徑的控制流

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 新結論

1. `[0xFB73E8]` 的直接絕對寫入參考在全 `.text` 掃描中僅定位 `0x560239: mov [0xFB73E8],ebx`，而前段 `0x560197 xor ebx,ebx`：確定這一條是**初始化清零**。不代表不存在由基址／別名／間接指標寫非零的路徑。
2. `0x5A4614` 在主物件 `[esi+0x15c]==0` 的前提下讀全域 `[0xFB73E8]`，將布林結果放入 `bl`，與 `[esi+0x154]` 舊值比較。若轉為非零，`0x5A462B push 2; call 0x5A55E0`，之後 `0x5A5760`、`0x5A57A0`；若轉為零則 `push 1; call 0x5A55E0`。最後 `0x5A466B` 將新 bool 寫入 `[esi+0x154]`。
3. `0x5A55E0` 不只是單純動畫 setter：存入 `[esi+0x158]` 新 mode、`[esi+0x15c]` 旗標，再針對 mode 1/2 操作 `[esi+0x140]`、`[esi+0x148]` 所指物件之 vtable `+0xD0/+0xD4`，設定或清除 `[object+0x28] & 0x80000` 並引入其他資源邏輯。此路徑屬**模式／子物件狀態切換**，目前未證明是普通攻擊、連段或取消。
4. `[0xFB73E8]` 既在 `0x5961C0` 限定 ID 13/14 的 dispatch，又在 `0x5A46xx` 觸發模式切換，構成跨路徑證據；但旗標的語義、權威寫入者仍未證實，必須保留不同 class/instance 區隔。

## 直接引用清單

### VA 0x00560197..0x00560274

```asm
  560197:	33 db                	xor    ebx,ebx
  560199:	6a 34                	push   0x34
  56019b:	c7 45 e4 c0 73 fb 00 	mov    DWORD PTR [ebp-0x1c],0xfb73c0
  5601a2:	89 1d c0 73 fb 00    	mov    DWORD PTR ds:0xfb73c0,ebx
  5601a8:	89 1d c4 73 fb 00    	mov    DWORD PTR ds:0xfb73c4,ebx
  5601ae:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  5601b4:	e8 af 10 33 00       	call   0x891268
  5601b9:	83 c4 04             	add    esp,0x4
  5601bc:	3b c3                	cmp    eax,ebx
  5601be:	0f 84 32 02 00 00    	je     0x5603f6
  5601c4:	a3 cc 73 fb 00       	mov    ds:0xfb73cc,eax
  5601c9:	89 00                	mov    DWORD PTR [eax],eax
  5601cb:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5601d3:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d8:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5601db:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601e0:	c6 40 30 01          	mov    BYTE PTR [eax+0x30],0x1
  5601e4:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  5601ea:	c6 41 31 01          	mov    BYTE PTR [ecx+0x31],0x1
  5601ee:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5601f1:	6a 18                	push   0x18
  5601f3:	89 1d e0 73 fb 00    	mov    DWORD PTR ds:0xfb73e0,ebx
  5601f9:	e8 6a 10 33 00       	call   0x891268
  5601fe:	83 c4 04             	add    esp,0x4
  560201:	3b c3                	cmp    eax,ebx
  560203:	0f 84 c9 01 00 00    	je     0x5603d2
  560209:	a3 dc 73 fb 00       	mov    ds:0xfb73dc,eax
  56020e:	89 00                	mov    DWORD PTR [eax],eax
  560210:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  560215:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  560218:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56021d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  560220:	8b 15 dc 73 fb 00    	mov    edx,DWORD PTR ds:0xfb73dc
  560226:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  56022a:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56022f:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  560233:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  560237:	6a 48                	push   0x48
  560239:	89 1d e8 73 fb 00    	mov    DWORD PTR ds:0xfb73e8,ebx
  56023f:	89 1d ec 73 fb 00    	mov    DWORD PTR ds:0xfb73ec,ebx
  560245:	e8 1e 10 33 00       	call   0x891268
  56024a:	83 c4 04             	add    esp,0x4
  56024d:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  560250:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  560254:	3b c3                	cmp    eax,ebx
  560256:	74 09                	je     0x560261
  560258:	8b f0                	mov    esi,eax
  56025a:	e8 51 d0 26 00       	call   0x7cd2b0
  56025f:	eb 02                	jmp    0x560263
  560261:	33 c0                	xor    eax,eax
  560263:	a3 f0 73 fb 00       	mov    ds:0xfb73f0,eax
  560268:	89 1d f8 73 fb 00    	mov    DWORD PTR ds:0xfb73f8,ebx
  56026e:	89 1d fc 73 fb 00    	mov    DWORD PTR ds:0xfb73fc,ebx
```

### VA 0x005A45DB..0x005A4671

```asm
  5a45db:	83 cf ff             	or     edi,0xffffffff
  5a45de:	38 9e 5c 01 00 00    	cmp    BYTE PTR [esi+0x15c],bl
  5a45e4:	0f 85 87 00 00 00    	jne    0x5a4671
  5a45ea:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5a45f1:	75 21                	jne    0x5a4614
  5a45f3:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  5a45fa:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  5a45fe:	e8 6d bb fb ff       	call   0x560170
  5a4603:	68 10 d1 bc 00       	push   0xbcd110
  5a4608:	e8 0d dd 2e 00       	call   0x89231a
  5a460d:	83 c4 04             	add    esp,0x4
  5a4610:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  5a4614:	39 1d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,ebx
  5a461a:	8a 86 54 01 00 00    	mov    al,BYTE PTR [esi+0x154]
  5a4620:	0f 95 c3             	setne  bl
  5a4623:	84 c0                	test   al,al
  5a4625:	75 35                	jne    0x5a465c
  5a4627:	84 db                	test   bl,bl
  5a4629:	74 2d                	je     0x5a4658
  5a462b:	6a 02                	push   0x2
  5a462d:	32 c9                	xor    cl,cl
  5a462f:	8b d6                	mov    edx,esi
  5a4631:	e8 aa 0f 00 00       	call   0x5a55e0
  5a4636:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  5a4639:	81 ea 3b 01 00 00    	sub    edx,0x13b
  5a463f:	56                   	push   esi
  5a4640:	b8 05 00 00 00       	mov    eax,0x5
  5a4645:	e8 16 11 00 00       	call   0x5a5760
  5a464a:	ba 66 00 00 00       	mov    edx,0x66
  5a464f:	8b ce                	mov    ecx,esi
  5a4651:	e8 4a 11 00 00       	call   0x5a57a0
  5a4656:	eb 13                	jmp    0x5a466b
  5a4658:	84 c0                	test   al,al
  5a465a:	74 0f                	je     0x5a466b
  5a465c:	84 db                	test   bl,bl
  5a465e:	75 0b                	jne    0x5a466b
  5a4660:	6a 01                	push   0x1
  5a4662:	32 c9                	xor    cl,cl
  5a4664:	8b d6                	mov    edx,esi
  5a4666:	e8 75 0f 00 00       	call   0x5a55e0
  5a466b:	88 9e 54 01 00 00    	mov    BYTE PTR [esi+0x154],bl
```

### VA 0x005A5605..0x005A5745

```asm
  5a5605:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5a5608:	8b f2                	mov    esi,edx
  5a560a:	bb 01 00 00 00       	mov    ebx,0x1
  5a560f:	89 86 58 01 00 00    	mov    DWORD PTR [esi+0x158],eax
  5a5615:	2b c3                	sub    eax,ebx
  5a5617:	88 8e 5c 01 00 00    	mov    BYTE PTR [esi+0x15c],cl
  5a561d:	0f 84 a9 00 00 00    	je     0x5a56cc
  5a5623:	2b c3                	sub    eax,ebx
  5a5625:	0f 85 19 01 00 00    	jne    0x5a5744
  5a562b:	84 1d e0 11 fb 00    	test   BYTE PTR ds:0xfb11e0,bl
  5a5631:	75 22                	jne    0x5a5655
  5a5633:	09 1d e0 11 fb 00    	or     DWORD PTR ds:0xfb11e0,ebx
  5a5639:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5a563c:	e8 cf f6 f2 ff       	call   0x4d4d10
  5a5641:	68 f0 ce bc 00       	push   0xbccef0
  5a5646:	e8 cf cc 2e 00       	call   0x89231a
  5a564b:	83 c4 04             	add    esp,0x4
  5a564e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5a5655:	c7 05 e8 11 fb 00 02 	mov    DWORD PTR ds:0xfb11e8,0x2
  5a565c:	00 00 00 
  5a565f:	8b 8e 40 01 00 00    	mov    ecx,DWORD PTR [esi+0x140]
  5a5665:	8b 11                	mov    edx,DWORD PTR [ecx]
  5a5667:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  5a566d:	ff d0                	call   eax
  5a566f:	8b 8e 48 01 00 00    	mov    ecx,DWORD PTR [esi+0x148]
  5a5675:	8b 11                	mov    edx,DWORD PTR [ecx]
  5a5677:	8b 82 d0 00 00 00    	mov    eax,DWORD PTR [edx+0xd0]
  5a567d:	ff d0                	call   eax
  5a567f:	8b 86 48 01 00 00    	mov    eax,DWORD PTR [esi+0x148]
  5a5685:	8b b8 ec 00 00 00    	mov    edi,DWORD PTR [eax+0xec]
  5a568b:	85 ff                	test   edi,edi
  5a568d:	74 05                	je     0x5a5694
  5a568f:	e8 2c 2c 0a 00       	call   0x6482c0
  5a5694:	8b 86 48 01 00 00    	mov    eax,DWORD PTR [esi+0x148]
  5a569a:	81 48 28 00 00 08 00 	or     DWORD PTR [eax+0x28],0x80000
  5a56a1:	8b b6 48 01 00 00    	mov    esi,DWORD PTR [esi+0x148]
  5a56a7:	8b 7e 60             	mov    edi,DWORD PTR [esi+0x60]
  5a56aa:	85 ff                	test   edi,edi
  5a56ac:	0f 84 92 00 00 00    	je     0x5a5744
  5a56b2:	56                   	push   esi
  5a56b3:	e8 58 49 1a 00       	call   0x74a010
  5a56b8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5a56bb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5a56c2:	59                   	pop    ecx
  5a56c3:	5f                   	pop    edi
  5a56c4:	5e                   	pop    esi
  5a56c5:	5b                   	pop    ebx
  5a56c6:	8b e5                	mov    esp,ebp
  5a56c8:	5d                   	pop    ebp
  5a56c9:	c2 04 00             	ret    0x4
  5a56cc:	84 1d e0 11 fb 00    	test   BYTE PTR ds:0xfb11e0,bl
  5a56d2:	75 26                	jne    0x5a56fa
  5a56d4:	09 1d e0 11 fb 00    	or     DWORD PTR ds:0xfb11e0,ebx
  5a56da:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5a56e1:	e8 2a f6 f2 ff       	call   0x4d4d10
  5a56e6:	68 f0 ce bc 00       	push   0xbccef0
  5a56eb:	e8 2a cc 2e 00       	call   0x89231a
  5a56f0:	83 c4 04             	add    esp,0x4
  5a56f3:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5a56fa:	89 1d e8 11 fb 00    	mov    DWORD PTR ds:0xfb11e8,ebx
  5a5700:	8b 8e 48 01 00 00    	mov    ecx,DWORD PTR [esi+0x148]
  5a5706:	8b 11                	mov    edx,DWORD PTR [ecx]
  5a5708:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  5a570e:	ff d0                	call   eax
  5a5710:	8b 8e 48 01 00 00    	mov    ecx,DWORD PTR [esi+0x148]
  5a5716:	8b 41 28             	mov    eax,DWORD PTR [ecx+0x28]
  5a5719:	a9 00 00 08 00       	test   eax,0x80000
  5a571e:	74 08                	je     0x5a5728
  5a5720:	35 00 00 08 00       	xor    eax,0x80000
  5a5725:	89 41 28             	mov    DWORD PTR [ecx+0x28],eax
  5a5728:	8b 8e 40 01 00 00    	mov    ecx,DWORD PTR [esi+0x140]
  5a572e:	8b 11                	mov    edx,DWORD PTR [ecx]
  5a5730:	8b 82 d0 00 00 00    	mov    eax,DWORD PTR [edx+0xd0]
  5a5736:	ff d0                	call   eax
  5a5738:	8b 8e 40 01 00 00    	mov    ecx,DWORD PTR [esi+0x140]
  5a573e:	51                   	push   ecx
  5a573f:	e8 0c fb 09 00       	call   0x645250
  5a5744:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
```

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。