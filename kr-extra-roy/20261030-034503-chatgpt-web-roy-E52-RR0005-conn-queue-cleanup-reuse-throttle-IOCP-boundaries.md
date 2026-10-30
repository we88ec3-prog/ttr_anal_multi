# E52 — RR-0005／KR T02：queue drain 非 socket-close、fresh/reused Conn receive-gate 不對稱、close/IOCP/bind lifecycle（15 個研究單元）

- **正式段號**：E52；生成時間（Asia/Taipei）：`2026-10-30T03:45:03+08:00`；`chatgpt-web roy`；來源 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- **原稿基礎**：E51 `20261030-032415-chatgpt-web-roy-E51-RR0005-conn-ownership-close-send-recv-IOCP-pool.md` （本次準備一併提交）；E50 `extra/roy1` 已存在 blob `f4bd62ce69cf96cc35b566bf62721a586f4f51c7`。
- **RR-0005**：在 `main` `eadabf33f31da542db32ddf1d10cabea5a020ea4` 已正式 `ACTIVE/CLAIMED`，`claim.actor=chatgpt-web roy`，`claim.branch=extra/roy1`；是實際 GitHub PR #24 合併後讀回的結果，`submission=null`。RR ACCEPTED／T01 FULL-PASS／SPEC STABLE／可玩均未成立。
- **方法**：唯讀 12,472,320 bytes 原件，不執行、不修改、不附加；`objdump -p/-h` import、section mapping，`.text` 由 raw 0x400 擷取後以 VA 0x401000 從已知入口反組譯；重要跨函式 `call` 以機器碼 `E8 rel32` 輔助而非拿候選當全部 caller。歷史 REA/Ghidra 只作導航。

---

## E52.1 — 0x8063E0 並非 socket close，而是 Conn 待發送佇列回收

**研究問題**：E51 以 `0x805F50→0x8063E0` 為生命週期缺口；此 helper 有沒有真正關閉 socket？

**N**：`0x806408` 讀 `Conn*[ebp+8]`，`0x80640B` 取 `Conn+A0D4` 並 `EnterCriticalSection`；`Conn+A074` 是雙向 list sentinel、`node+8` 是 payload 指標。對每筆 payload，`0x80646D/73` 清其前兩 DWORD，`0x8064C0–0x80650F` 放入全域 `FE3364/FE3368/...` 的重用倉並修改相應 count。最後清空 Conn list（sentinel self-link，A078=0）、釋放 list nodes（`0x89120C`），`LeaveCriticalSection`。完整已查函式沒有直接 `closesocket` 或 `shutdown` IAT 呼叫。

**C**：此函式釋放的是 Conn 的應用層 message queue node／轉移 payload 所有權，不是把 Conn* 送回 Pool+48，也不是釋放 Conn 自身或其 TCP socket。**反證**：先前把 reset 呼叫此 helper 等價於「fail socket 已 close」的說法不成立。

**U**：全域 reuse store `FE336x` 的最終銷毀／有界上限與獨立互斥不是本次函式直接證明；不能以函式名猜出所有跨 thread hazard。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
8063e0:	55                   	push   ebp
  8063e1:	8b ec                	mov    ebp,esp
  8063e3:	6a ff                	push   0xffffffff
  8063e5:	68 fe 98 90 00       	push   0x9098fe
  8063ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8063f0:	50                   	push   eax
  8063f1:	83 ec 18             	sub    esp,0x18
  8063f4:	53                   	push   ebx
  8063f5:	56                   	push   esi
  8063f6:	57                   	push   edi
  8063f7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8063fc:	33 c5                	xor    eax,ebp
  8063fe:	50                   	push   eax
  8063ff:	8d 45 f4             	lea    eax,[ebp-0xc]
  806402:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  806408:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  80640b:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806411:	50                   	push   eax
  806412:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806418:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  80641e:	8b 18                	mov    ebx,DWORD PTR [eax]
  806420:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  806423:	3b d8                	cmp    ebx,eax
  806425:	0f 84 fe 00 00 00    	je     0x806529
  80642b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806432:	75 27                	jne    0x80645b
  806434:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80643b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806442:	e8 d9 0c 00 00       	call   0x807120
  806447:	68 90 0b bd 00       	push   0xbd0b90
  80644c:	e8 c9 be 08 00       	call   0x89231a
  806451:	83 c4 04             	add    esp,0x4
  806454:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80645b:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806460:	8b 73 08             	mov    esi,DWORD PTR [ebx+0x8]
  806463:	50                   	push   eax
  806464:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  806467:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80646d:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  806473:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  80647a:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  80647f:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  806485:	03 c8                	add    ecx,eax
  806487:	f6 c1 03             	test   cl,0x3
  80648a:	75 18                	jne    0x8064a4
  80648c:	83 c0 04             	add    eax,0x4
  80648f:	c1 e8 02             	shr    eax,0x2
  806492:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  806498:	77 0a                	ja     0x8064a4
  80649a:	68 64 33 fe 00       	push   0xfe3364
  80649f:	e8 cc 0a e3 ff       	call   0x636f70
  8064a4:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8064aa:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8064b0:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  8064b5:	8b f7                	mov    esi,edi
  8064b7:	c1 ee 02             	shr    esi,0x2
  8064ba:	3b c6                	cmp    eax,esi
  8064bc:	77 02                	ja     0x8064c0
  8064be:	2b f0                	sub    esi,eax
  8064c0:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  8064c6:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  8064ca:	75 1b                	jne    0x8064e7
  8064cc:	6a 10                	push   0x10
  8064ce:	e8 95 ad 08 00       	call   0x891268
  8064d3:	83 c4 04             	add    esp,0x4
  8064d6:	85 c0                	test   eax,eax
  8064d8:	0f 84 a8 00 00 00    	je     0x806586
  8064de:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  8064e4:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  8064e7:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  8064ec:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  8064ef:	83 e7 03             	and    edi,0x3
  8064f2:	8d 04 b9             	lea    eax,[ecx+edi*4]
  8064f5:	85 c0                	test   eax,eax
  8064f7:	74 05                	je     0x8064fe
  8064f9:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  8064fc:	89 10                	mov    DWORD PTR [eax],edx
  8064fe:	b8 01 00 00 00       	mov    eax,0x1
  806503:	01 05 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,eax
  806509:	29 05 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,eax
  80650f:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806514:	50                   	push   eax
  806515:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80651b:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  80651d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  806520:	0f 85 05 ff ff ff    	jne    0x80642b
  806526:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806529:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  80652f:	8b 01                	mov    eax,DWORD PTR [ecx]
  806531:	89 09                	mov    DWORD PTR [ecx],ecx
  806533:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  806539:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  80653c:	c7 86 78 a0 00 00 00 	mov    DWORD PTR [esi+0xa078],0x0
  806543:	00 00 00 
  806546:	3b 86 74 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa074]
  80654c:	74 17                	je     0x806565
  80654e:	8b ff                	mov    edi,edi
  806550:	8b 38                	mov    edi,DWORD PTR [eax]
  806552:	50                   	push   eax
  806553:	e8 b4 ac 08 00       	call   0x89120c
  806558:	83 c4 04             	add    esp,0x4
  80655b:	8b c7                	mov    eax,edi
  80655d:	3b be 74 a0 00 00    	cmp    edi,DWORD PTR [esi+0xa074]
  806563:	75 eb                	jne    0x806550
  806565:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  80656b:	50                   	push   eax
  80656c:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806572:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806575:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  80657c:	59                   	pop    ecx
  80657d:	5f                   	pop    edi
  80657e:	5e                   	pop    esi
  80657f:	5b                   	pop    ebx
  806580:	8b e5                	mov    esp,ebp
  806582:	5d                   	pop    ebp
  806583:	c2 04 00             	ret    0x4
  806586:	8d 4d e8             	lea    ecx,[ebp-0x18]
  806589:	51                   	push   ecx
  80658a:	8d 4d dc             	lea    ecx,[ebp-0x24]
  80658d:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  806594:	e8 10 ab 08 00       	call   0x8910a9
  806599:	68 a8 57 c8 00       	push   0xc857a8
  80659e:	8d 55 dc             	lea    edx,[ebp-0x24]
  8065a1:	52                   	push   edx
  8065a2:	c7 45 dc a4 2c bd 00 	mov    DWORD PTR [ebp-0x24],0xbd2ca4
  8065a9:	e8 42 64 09 00       	call   0x89c9f0
  8065ae:	cc                   	int3
  8065af:	cc                   	int3
```


## E52.2 — Queue payload 的全域倉與雙層鎖，不等同 Conn pool

**N／較小粒度**：在 `0x8063E0` 中 `Conn+A0D4` 先對每次 drain 保護，global payload store 由 `0xFE3380` 另一 critical section 包覆；全域 `0xFE3374` 逐次加一、`0xFE337C` 減一。`0x8064CC` 需要時配置 0x10 byte block；`0x8064F9` 把 payload 指標寫到分桶 slot。

**資料流**：`Conn+A074 list→node+8 payload→payload[0:8]=0→global FE3368 vector of blocks`；**這與** `Pool+0x10` 的 Conn reuse vector、`Pool+0x28` 的 close-tracking list、`Pool+0x48` 的 delayed Conn recycle list **是不同 base 和不同型別**。同時持有不同層鎖，但其跨執行緒總鎖順序與死鎖不存在性未驗。

**N**：`0x806529–0x806565` reset queue sentinel/count；`0x806550–0x806558` 回收 list 節點。即使 payload 被保存到全域庫，原 list node 仍可能單獨 free；因此不可將兩者當成同一塊記憶體。

**反證／U**：沒有在此路徑看到 Conn socket handle 被傳入網路關閉 API；也未憑此證明全域倉永遠沒有 leak。


## E52.3 — 0x8063E0 caller 清查：parser 失敗、選服舊 Conn 與 reset 共享 queue drain

**E8-relative bytes scanner 候選**（從 `.text` 原始 raw 範圍找 `E8 + signed rel32`，必須以 caller 邊界復核）：`0x495839`、`0x804B61`、`0x804BB9`、`0x8052B3`、`0x805313`、`0x805FDA`、`0x806021`。本次對前五個實際 caller 區塊與 reset 的兩個 caller 做了原件連續 disassembly。

- `0x804B61 / 0x8052B3`：上游 vtable callback 失敗時先 drain queue，再透過 Manager `vtable+0x24` close-by-Conn。
- `0x804BB9 / 0x805313`：`Conn+A0A4 > 0x12C` 且 `Conn+A0A8==0` 時 drain queue，再依 `A0B4==2` 選 **vtable+0x1C shutdown + 0x806010**，或直接 **vtable+0x24**。
- `0x495839`：選服新 Conn 連線後處理 `Client-like+BF60` 的舊 Conn，先 queue drain、queue `0x007E`、設 B0、清 BF60；**並不等同當場 close socket**。
- `0x805FDA / 0x806021`：Conn reset/helper 的 queue drain。這些 caller 證明 `0x8063E0` 是共享 cleanup primitive，**不能靠 caller 名稱把它重新命名為 socket destructor**。

**C/U**：原始 E8 全域掃描只提供 direct CALL 候選，不包含 `call reg`、函式指標、exception handler 等；但上述已核指令是具體正向 xref，而非推測。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
804b00:	86 a4 a0 00 00 eb 13 	xchg   BYTE PTR [eax+eiz*4+0x13eb0000],ah
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  804b21:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  804b28:	0f 84 1d 01 00 00    	je     0x804c4b
  804b2e:	8b 86 b8 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0b8]
  804b34:	85 c0                	test   eax,eax
  804b36:	0f 8f 0f 01 00 00    	jg     0x804c4b
  804b3c:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  804b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b48:	8b 11                	mov    edx,DWORD PTR [ecx]
  804b4a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  804b4d:	8d 7d ec             	lea    edi,[ebp-0x14]
  804b50:	57                   	push   edi
  804b51:	50                   	push   eax
  804b52:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  804b58:	50                   	push   eax
  804b59:	56                   	push   esi
  804b5a:	ff d2                	call   edx
  804b5c:	85 c0                	test   eax,eax
  804b5e:	75 1c                	jne    0x804b7c
  804b60:	56                   	push   esi
  804b61:	e8 7a 18 00 00       	call   0x8063e0
  804b66:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b6c:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b6e:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b71:	6a 00                	push   0x0
  804b73:	56                   	push   esi
  804b74:	ff d2                	call   edx
  804b76:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b7c:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  804b83:	74 16                	je     0x804b9b
  804b85:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b8d:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b90:	6a 00                	push   0x0
  804b92:	56                   	push   esi
  804b93:	ff d2                	call   edx
  804b95:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b9b:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  804ba2:	01 00 00 
  804ba5:	0f 8e 9d 00 00 00    	jle    0x804c48
  804bab:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  804bb2:	0f 85 90 00 00 00    	jne    0x804c48
  804bb8:	56                   	push   esi
  804bb9:	e8 22 18 00 00       	call   0x8063e0
  804bbe:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  804bc1:	8b b8 8c 00 00 00    	mov    edi,DWORD PTR [eax+0x8c]
  804bc7:	85 ff                	test   edi,edi
  804bc9:	74 51                	je     0x804c1c
  804bcb:	8b 8e a0 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0a0]
  804bd1:	8b 96 90 a0 00 00    	mov    edx,DWORD PTR [esi+0xa090]
  804bd7:	8b 86 9c a0 00 00    	mov    eax,DWORD PTR [esi+0xa09c]
  804bdd:	51                   	push   ecx
  804bde:	8b 8e 8c a0 00 00    	mov    ecx,DWORD PTR [esi+0xa08c]
  804be4:	52                   	push   edx
  804be5:	8b 96 98 a0 00 00    	mov    edx,DWORD PTR [esi+0xa098]
  804beb:	50                   	push   eax
  804bec:	8b 86 88 a0 00 00    	mov    eax,DWORD PTR [esi+0xa088]
  804bf2:	51                   	push   ecx
  804bf3:	8b 8e 94 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa094]
  804bf9:	52                   	push   edx
  804bfa:	8b 96 84 a0 00 00    	mov    edx,DWORD PTR [esi+0xa084]
  804c00:	50                   	push   eax
  804c01:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804c07:	51                   	push   ecx
  804c08:	8b 0e                	mov    ecx,DWORD PTR [esi]
  804c0a:	52                   	push   edx
  804c0b:	50                   	push   eax
  804c0c:	51                   	push   ecx
  804c0d:	68 38 14 c5 00       	push   0xc51438
  804c12:	6a 02                	push   0x2
  804c14:	e8 e7 b7 ee ff       	call   0x6f0400
  804c19:	83 c4 30             	add    esp,0x30
  804c1c:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  804c23:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804c29:	8b 11                	mov    edx,DWORD PTR [ecx]
  804c2b:	75 0d                	jne    0x804c3a
  804c2d:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  804c30:	56                   	push   esi
  804c31:	ff d0                	call   eax
  804c33:	e8 d8 13 00 00       	call   0x806010
  804c38:	eb 08                	jmp    0x804c42
  804c3a:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  804c3d:	6a 00                	push   0x0
  804c3f:	56                   	push   esi
  804c40:	ff d0                	call   eax
  804c42:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804c48:	8b 7d f8             	mov    edi,DWORD PTR [ebp-0x8]
  804c4b:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  804c4e:	03 c3                	add    eax,ebx
  804c50:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  804c53:	3b c7                	cmp    eax,edi
  804c55:	0f 82 65 fe ff ff    	jb     0x804ac0
  804c5b:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  804c61:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804c64:	5f                   	pop    edi
  804c65:	5e                   	pop    esi
  804c66:	89 41 4c             	mov    DWORD PTR [ecx+0x4c],eax
  804c69:	5b                   	pop    ebx
  804c6a:	8b e5                	mov    esp,ebp
  804c6c:	5d                   	pop    ebp
  804c6d:	c2 04 00             	ret    0x4
```


## E52.4 — 第二組 decoder callback：重用 0x806010 的 close-mode 分歧

**N**：在 `0x8052B0` 失敗、`0x8052D2` B0 flag、`0x8052F5` A0A4 門檻與 `0x805376` A0B4 判斷，可看到與 `0x804Bxx` 類似、但不應混成同一個函式的獨立 consumer。`A0B4==2` 先呼叫 `Manager vtable+0x1C`（只對 Conn socket `shutdown`），再到 `0x806010`；其他值走 `vtable+0x24` Conn-based closesocket＋Pool+28 tracking。

**N**：此路徑在 drain 後對 `Conn+A0A8` 設 1；`A0A4` 門檻為原始 `0x12C` = 300。反證：一律主張「parser 超限都會走 closesocket」是錯誤的；**mode==2** 與 **mode!=2** 有本地可證分叉。

**U**：callback 的上游具體 S2C 業務 command 未在此段證明；`0x12C` 只是 Conn 欄位 gate，不得移植成 Server 封包長度規格。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
805260:	86 84 a0 00 00 83 86 	xchg   BYTE PTR [eax+eiz*4-0x797d0000],al
  805267:	a4                   	movs   BYTE PTR es:[edi],BYTE PTR ds:[esi]
  805268:	a0 00 00 05 c7       	mov    al,ds:0xc7050000
  80526d:	45                   	inc    ebp
  80526e:	f4                   	hlt
  80526f:	00 00                	add    BYTE PTR [eax],al
  805271:	00 00                	add    BYTE PTR [eax],al
  805273:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  80527a:	0f 84 29 01 00 00    	je     0x8053a9
  805280:	8b 96 b8 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0b8]
  805286:	85 d2                	test   edx,edx
  805288:	0f 8f 1b 01 00 00    	jg     0x8053a9
  80528e:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  805294:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  80529a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80529c:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  80529f:	8d 7d f4             	lea    edi,[ebp-0xc]
  8052a2:	57                   	push   edi
  8052a3:	50                   	push   eax
  8052a4:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  8052aa:	50                   	push   eax
  8052ab:	56                   	push   esi
  8052ac:	ff d2                	call   edx
  8052ae:	85 c0                	test   eax,eax
  8052b0:	75 20                	jne    0x8052d2
  8052b2:	56                   	push   esi
  8052b3:	e8 28 11 00 00       	call   0x8063e0
  8052b8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052be:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052c0:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052c3:	6a 00                	push   0x0
  8052c5:	56                   	push   esi
  8052c6:	ff d2                	call   edx
  8052c8:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052cf:	00 00 00 
  8052d2:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  8052d9:	74 1a                	je     0x8052f5
  8052db:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052e1:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052e3:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052e6:	6a 00                	push   0x0
  8052e8:	56                   	push   esi
  8052e9:	ff d2                	call   edx
  8052eb:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052f2:	00 00 00 
  8052f5:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  8052fc:	01 00 00 
  8052ff:	0f 8e a1 00 00 00    	jle    0x8053a6
  805305:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  80530c:	0f 85 94 00 00 00    	jne    0x8053a6
  805312:	56                   	push   esi
  805313:	e8 c8 10 00 00       	call   0x8063e0
  805318:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  80531b:	8b b8 8c 00 00 00    	mov    edi,DWORD PTR [eax+0x8c]
  805321:	85 ff                	test   edi,edi
  805323:	74 51                	je     0x805376
  805325:	8b 8e a0 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0a0]
  80532b:	8b 96 90 a0 00 00    	mov    edx,DWORD PTR [esi+0xa090]
  805331:	8b 86 9c a0 00 00    	mov    eax,DWORD PTR [esi+0xa09c]
  805337:	51                   	push   ecx
  805338:	8b 8e 8c a0 00 00    	mov    ecx,DWORD PTR [esi+0xa08c]
  80533e:	52                   	push   edx
  80533f:	8b 96 98 a0 00 00    	mov    edx,DWORD PTR [esi+0xa098]
  805345:	50                   	push   eax
  805346:	8b 86 88 a0 00 00    	mov    eax,DWORD PTR [esi+0xa088]
  80534c:	51                   	push   ecx
  80534d:	8b 8e 94 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa094]
  805353:	52                   	push   edx
  805354:	8b 96 84 a0 00 00    	mov    edx,DWORD PTR [esi+0xa084]
  80535a:	50                   	push   eax
  80535b:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805361:	51                   	push   ecx
  805362:	8b 0e                	mov    ecx,DWORD PTR [esi]
  805364:	52                   	push   edx
  805365:	50                   	push   eax
  805366:	51                   	push   ecx
  805367:	68 38 14 c5 00       	push   0xc51438
  80536c:	6a 02                	push   0x2
  80536e:	e8 8d b0 ee ff       	call   0x6f0400
  805373:	83 c4 30             	add    esp,0x30
  805376:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  80537d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  805383:	8b 11                	mov    edx,DWORD PTR [ecx]
  805385:	75 0d                	jne    0x805394
  805387:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  80538a:	56                   	push   esi
  80538b:	ff d0                	call   eax
  80538d:	e8 7e 0c 00 00       	call   0x806010
  805392:	eb 08                	jmp    0x80539c
  805394:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  805397:	6a 00                	push   0x0
  805399:	56                   	push   esi
  80539a:	ff d0                	call   eax
  80539c:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8053a3:	00 00 00 
  8053a6:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  8053a9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8053ac:	03 3b                	add    edi,DWORD PTR [ebx]
  8053ae:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  8053b1:	3b f8                	cmp    edi,eax
  8053b3:	0f 82 59 fe ff ff    	jb     0x805212
  8053b9:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  8053bc:	51                   	push   ecx
  8053bd:	ff 15 d0       	call   DWORD PTR ds:0xbd20d0
```


## E52.5 — 0x806010：invalid socket + queue flush，沒有 closesocket 的可見差異

**N**：`0x806010` 寫 `Conn+0=-1`，`Conn+A0A8=1`，然後 `call 0x8063E0`、清 `Conn+A0C0/C4/C8/CC/D0`、寫 `Conn+A0B4=1`，直接 `ret`。此函式自身**沒有**呼叫 `closesocket`。同段 `0x805F50` 的 reset 也先把 Conn socket 直接設 -1，不能與 `0x806FC0` 的正式 socket close 視為同義。

**C**：當呼叫者事先執行 `vtable+0x1C` 的 shutdown，這條函式只是標記與 queue cleanup；若沒有其他 close owner，handle 資源仍有未解 lifecycle 風險。**不能**僅由欄位 invalidation 斷言 OS handle 已被釋放。

**反證／U**：`0x806010` 的正向 direct callsite 是 `0x804C33`、`0x80538D`，已核兩者都有 mode2 shutdown 前置；仍不可由此排除另類間接 caller。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00 
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  80602e:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  806034:	89 86 c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],eax
  80603a:	89 86 cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],eax
  806040:	89 86 d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],eax
  806046:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80604d:	00 00 00 
  806050:	c3                   	ret
  806051:	cc                   	int3
  806052:	cc                   	int3
  806053:	cc                   	int3
  806054:	cc                   	int3
  806055:	cc                   	int3
  806056:	cc                   	int3
  806057:	cc                   	int3
  806058:	cc                   	int3
  806059:	cc                   	int3
  80605a:	cc                   	int3
  80605b:	cc                   	int3
  80605c:	cc                   	int3
  80605d:	cc                   	int3
  80605e:	cc                   	int3
  80605f:	cc                   	int3
```


## E52.6 — Conn reset 0x805F50：socket 欄位先失效，再清 queue

**N**：reset entry `0x805F50 mov [ESI],0xFFFFFFFF`，`0x805F5B` 清 A0AC，`0x805F61..6D` 清 Conn+04/+08/+0C/+10/+14，`0x805FD0` A080=2，`0x805FDA` 進 queue drain，後設 A0C0/C4/C8/CC/D0 =0、A0B0=0、A0B4=1。此 reset 沒有直接 `shutdown`/`closesocket`，也沒有把 `A02C` 重新強制設 2。

**N**：與 `0x806010` 不同，`0x805F50` 也重設 ring / buffer 相關欄位。`0x805BB7` 的 Pool+48 consumer 在 `Conn+A0B8==0` 才呼叫 reset，此條檢查保護 SEND completion counter，但**未見同步等待 RECEIVE OVERLAPPED 完成**。

**C/U**：呼叫 reset 前可能已有其他路徑關 socket；本函式不能證明有，也不能直接指稱實際 use-after-free。需要動態 Conn socket / recv-overlapped 追蹤。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
805950:	55                   	push   ebp
  805951:	8b ec                	mov    ebp,esp
  805953:	6a ff                	push   0xffffffff
  805955:	68 2b 5a 91 00       	push   0x915a2b
  80595a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805960:	50                   	push   eax
  805961:	83 ec 0c             	sub    esp,0xc
  805964:	53                   	push   ebx
  805965:	56                   	push   esi
  805966:	57                   	push   edi
  805967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80596c:	33 c5                	xor    eax,ebp
  80596e:	50                   	push   eax
  80596f:	8d 45 f4             	lea    eax,[ebp-0xc]
  805972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805978:	8b f9                	mov    edi,ecx
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  805a01:	74 5b                	je     0x805a5e
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
  805a5e:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  805a61:	52                   	push   edx
  805a62:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  805a68:	8b c6                	mov    eax,esi
  805a6a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805a6d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805a74:	59                   	pop    ecx
  805a75:	5f                   	pop    edi
  805a76:	5e                   	pop    esi
  805a77:	5b                   	pop    ebx
  805a78:	8b e5                	mov    esp,ebp
  805a7a:	5d                   	pop    ebp
  805a7b:	c2 04 00             	ret    0x4
  805a7e:	cc                   	int3
  805a7f:	cc                   	int3
```


## E52.7 — 新 Conn 與重用 Conn 的 A0C8/CC/D0 組態差異

**這是本段主要新結論（N，限定 `0x805950` 可見 CFG）**：

- **fresh new**：`0x805A03` 以 `0xA0D8` 配置；`0x805A1B` 執行 constructor；`0x805A2B..A43` 依次將 `Pool+0x38→Conn+A0C8`、`Pool+0x3C→Conn+A0CC`、`Pool+0x40→Conn+A0D0`；隨後 `Conn+A0AC=1`。
- **reuse**：`0x8059E9` 對已有 Conn 呼叫 `0x805F50`（將 A0C8/CC/D0 **全部清零**），`0x8059F3` A0AC=1，`0x8059F9` 增 `Pool+44`，直接跳到 `0x805A5E` 解鎖、回傳，**沒有跳過去執行 fresh-only 的 A0C8/CC/D0 copies**。
- **constructor**：`0x805D02` fresh `Conn+A02C=2`；reuse reset 未看到此 write。故兩種路徑存在 **A02C 與 throttle configuration 的不對稱**。

**C**：若沒有另一個間接/事後 writer，reuse Conn 的 `A0C8=0` 會使 `0x8065B0` 在首個 CMP 即 return 0，跳過 A0BC 門檻及時窗 gate。這是**靜態條件式差異**，不是已動態證明每次回收都如此。

**反證**：過去只指出 frame mode 不重置；本段新增三個 Pool 設定欄位的**明確 CFG 不對稱**，不能直接說全 Conn 都使用同樣 throttle。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
805950:	55                   	push   ebp
  805951:	8b ec                	mov    ebp,esp
  805953:	6a ff                	push   0xffffffff
  805955:	68 2b 5a 91 00       	push   0x915a2b
  80595a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805960:	50                   	push   eax
  805961:	83 ec 0c             	sub    esp,0xc
  805964:	53                   	push   ebx
  805965:	56                   	push   esi
  805966:	57                   	push   edi
  805967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80596c:	33 c5                	xor    eax,ebp
  80596e:	50                   	push   eax
  80596f:	8d 45 f4             	lea    eax,[ebp-0xc]
  805972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805978:	8b f9                	mov    edi,ecx
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  805a01:	74 5b                	je     0x805a5e
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
  805a5e:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  805a61:	52                   	push   edx
  805a62:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  805a68:	8b c6                	mov    eax,esi
  805a6a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805a6d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805a74:	59                   	pop    ecx
  805a75:	5f                   	pop    edi
  805a76:	5e                   	pop    esi
  805a77:	5b                   	pop    ebx
  805a78:	8b e5                	mov    esp,ebp
  805a7a:	5d                   	pop    ebp
  805a7b:	c2 04 00             	ret    0x4
  805a7e:	cc                   	int3
  805a7f:	cc                   	int3
```


## E52.8 — 0x8065B0 recv gate：A0BC 的 threshold + GetTickCount 時窗

**N／精確 CFG**：

1. `Conn+A0C8==0` 立刻回 0；`Conn+A0B4==2` 同樣回 0。
2. 其他情形，若 `A0BC==0`，存 `Conn+A0C4=GetTickCount()` 起始 tick；否則保留原時戳。
3. `A0BC <= Conn+A0CC` 時呼叫 `InterlockedIncrement(&A0BC)` 然後返回 0。
4. `A0BC > A0CC` 時先 `InterlockedExchange(&A0BC,0)`，以 `now-A0C4` 對照 `Conn+A0D0`；若 `elapsed < A0D0`，返回 1；若 `elapsed >= A0D0`，返回 0。

**C**：這更接近 RECV post 頻率／短時超限 gate，不能擅自命名為「Server flood disconnect policy」或「recv outstanding counter」。其返回 1 被 `0x806A00` 下游當關閉條件使用。tick 是 32-bit wrap 算術；`A0BC` 的競態由 atomic 增／交換處理，但 `A0C4` 的非 atomic writer 是否安全需多執行緒測試。

**反證**：`A0BC` 在這裡增減是 threshold 機制，並非 `A0B8` WSASend in-flight。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
8065b0:	83 be c8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0c8],0x0
  8065b7:	75 03                	jne    0x8065bc
  8065b9:	33 c0                	xor    eax,eax
  8065bb:	c3                   	ret
  8065bc:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  8065c3:	74 f4                	je     0x8065b9
  8065c5:	8b 86 bc a0 00 00    	mov    eax,DWORD PTR [esi+0xa0bc]
  8065cb:	53                   	push   ebx
  8065cc:	8b 1d d4 22 bd 00    	mov    ebx,DWORD PTR ds:0xbd22d4
  8065d2:	57                   	push   edi
  8065d3:	8d be bc a0 00 00    	lea    edi,[esi+0xa0bc]
  8065d9:	85 c0                	test   eax,eax
  8065db:	75 08                	jne    0x8065e5
  8065dd:	ff d3                	call   ebx
  8065df:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  8065e5:	8b 0f                	mov    ecx,DWORD PTR [edi]
  8065e7:	3b 8e cc a0 00 00    	cmp    ecx,DWORD PTR [esi+0xa0cc]
  8065ed:	7e 21                	jle    0x806610
  8065ef:	6a 00                	push   0x0
  8065f1:	57                   	push   edi
  8065f2:	ff 15 80 22 bd 00    	call   DWORD PTR ds:0xbd2280
  8065f8:	ff d3                	call   ebx
  8065fa:	2b 86 c4 a0 00 00    	sub    eax,DWORD PTR [esi+0xa0c4]
  806600:	3b 86 d0 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa0d0]
  806606:	73 0f                	jae    0x806617
  806608:	5f                   	pop    edi
  806609:	b8 01 00 00 00       	mov    eax,0x1
  80660e:	5b                   	pop    ebx
  80660f:	c3                   	ret
  806610:	57                   	push   edi
  806611:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806617:	5f                   	pop    edi
  806618:	33 c0                	xor    eax,eax
  80661a:	5b                   	pop    ebx
  80661b:	c3                   	ret
  80661c:	cc                   	int3
  80661d:	cc                   	int3
  80661e:	cc                   	int3
  80661f:	cc                   	int3
```


## E52.9 — WSARecv post 後的 gate / Error 邊：不新增 A0B8

**N（E51 延伸到新證據）**：`0x806A00` 初始化 `Conn+A030` OVERLAPPED，準備 [Conn+0x5018] WSABUF、`0x1000` bytes，透過 IAT `0xBD25BC` 呼叫 `WSARecv`。返回 -1 時依 `WSAGetLastError` 檢查 `0x3E5=WSA_IO_PENDING`；其他錯誤立即 `Manager vtable+0x24` close。成功或 pending 走 `0x806AAB call 0x8065B0`，若返回 1 同樣呼叫 close 並設 `Conn+A0A8=1`。

**N**：此函式全部條件分支均未 `InterlockedIncrement(&Conn+A0B8)`，相應 RECV completion 的 `Conn+A030` 也不 decrements `A0B8`（與 SEND `Conn+A050` 分開）。`A0BC` 的過限 gate 是 POST 成功/accepted 後檢查：可見分支存在**操作已提交後再 close**的先後順序。

**C/U**：已 post receive 且 gate 返回 1 的 close 可能使 GQCS 日後收到失敗完成；何時到達與 Conn recycle 不能只用靜態 CFG 排序。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
806a00:	55                   	push   ebp
  806a01:	8b ec                	mov    ebp,esp
  806a03:	51                   	push   ecx
  806a04:	53                   	push   ebx
  806a05:	56                   	push   esi
  806a06:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806a09:	57                   	push   edi
  806a0a:	8d 86 30 a0 00 00    	lea    eax,[esi+0xa030]
  806a10:	8b f9                	mov    edi,ecx
  806a12:	33 c9                	xor    ecx,ecx
  806a14:	89 08                	mov    DWORD PTR [eax],ecx
  806a16:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  806a19:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  806a1c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  806a1f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  806a22:	8b 8e 18 50 00 00    	mov    ecx,DWORD PTR [esi+0x5018]
  806a28:	6a 00                	push   0x0
  806a2a:	50                   	push   eax
  806a2b:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  806a2e:	8d 48 14             	lea    ecx,[eax+0x14]
  806a31:	8d 45 fc             	lea    eax,[ebp-0x4]
  806a34:	50                   	push   eax
  806a35:	8d 45 08             	lea    eax,[ebp+0x8]
  806a38:	50                   	push   eax
  806a39:	6a 01                	push   0x1
  806a3b:	c7 01 00 10 00 00    	mov    DWORD PTR [ecx],0x1000
  806a41:	8b 16                	mov    edx,DWORD PTR [esi]
  806a43:	51                   	push   ecx
  806a44:	52                   	push   edx
  806a45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806a4c:	ff 15 bc 25 bd 00    	call   DWORD PTR ds:0xbd25bc
  806a52:	83 f8 ff             	cmp    eax,0xffffffff
  806a55:	75 54                	jne    0x806aab
  806a57:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806a5d:	8b d8                	mov    ebx,eax
  806a5f:	81 fb e5 03 00 00    	cmp    ebx,0x3e5
  806a65:	74 44                	je     0x806aab
  806a67:	8b 17                	mov    edx,DWORD PTR [edi]
  806a69:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806a6c:	6a 00                	push   0x0
  806a6e:	56                   	push   esi
  806a6f:	8b cf                	mov    ecx,edi
  806a71:	ff d0                	call   eax
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2 04 00             	ret    0x4
  806acf:	cc                   	int3
```


## E52.10 — Timer 與 mode gate 的初始化／重設：不可混 Conn+A0B4 與 frame A02C

**N**：`Conn+A0B4` 在 `0x805DE3` constructor 用 ECX=1，`0x806003` reset 設 1，`0x806046` 另一 helper 設 1；`0x8065BC` 特別測試它是否等於 2，這**不是** `Conn+A02C` byte framing mode（constructor `0x805D02` 寫入 2）。`A0C8/CC/D0` 三欄位與 `Pool+38/3C/40` 在 `0x805A2B–A43` 見 fresh-only 正向 writer；`0x805FF1–FFD` reset 清零。

**N**：同一物件上 `+A02C` 是 byte，而 `+A0B4` 是 DWORD，兩者 value 2 不能作語意對應。`+A0C4` 是 `GetTickCount` 原生 tick 錨點； `+A0D0` 在 elapsed compare，是時窗 threshold，而不一定是連線 timeout。

**U**：`A0B4=2` 的所有 writer 和時序尚未全域追完；其他函式是否重新把 Pool 組態填到 reused Conn 亦未排除。不能由 constructor 的初值推導真實全 session 模式。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
805ca0:	55                   	push   ebp
  805ca1:	8b ec                	mov    ebp,esp
  805ca3:	6a ff                	push   0xffffffff
  805ca5:	68 dc 99 90 00       	push   0x9099dc
  805caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805cb0:	50                   	push   eax
  805cb1:	83 ec 10             	sub    esp,0x10
  805cb4:	53                   	push   ebx
  805cb5:	56                   	push   esi
  805cb6:	57                   	push   edi
  805cb7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805cbc:	33 c5                	xor    eax,ebp
  805cbe:	50                   	push   eax
  805cbf:	8d 45 f4             	lea    eax,[ebp-0xc]
  805cc2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805cc8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805ccb:	8d 46 18             	lea    eax,[esi+0x18]
  805cce:	6a 18                	push   0x18
  805cd0:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805cd6:	e8 8d b5 08 00       	call   0x891268
  805cdb:	8b f8                	mov    edi,eax
  805cdd:	33 db                	xor    ebx,ebx
  805cdf:	83 c4 04             	add    esp,0x4
  805ce2:	3b fb                	cmp    edi,ebx
  805ce4:	74 0e                	je     0x805cf4
  805ce6:	68 a0 0f 00 00       	push   0xfa0
  805ceb:	57                   	push   edi
  805cec:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805cf2:	eb 02                	jmp    0x805cf6
  805cf4:	33 ff                	xor    edi,edi
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
  805d24:	33 c0                	xor    eax,eax
  805d26:	89 86 30 a0 00 00    	mov    DWORD PTR [esi+0xa030],eax
  805d2c:	89 86 34 a0 00 00    	mov    DWORD PTR [esi+0xa034],eax
  805d32:	89 86 38 a0 00 00    	mov    DWORD PTR [esi+0xa038],eax
  805d38:	89 86 3c a0 00 00    	mov    DWORD PTR [esi+0xa03c],eax
  805d3e:	89 86 40 a0 00 00    	mov    DWORD PTR [esi+0xa040],eax
  805d44:	89 9e 48 a0 00 00    	mov    DWORD PTR [esi+0xa048],ebx
  805d4a:	89 9e 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],ebx
  805d50:	89 86 50 a0 00 00    	mov    DWORD PTR [esi+0xa050],eax
  805d56:	89 86 54 a0 00 00    	mov    DWORD PTR [esi+0xa054],eax
  805d5c:	89 86 58 a0 00 00    	mov    DWORD PTR [esi+0xa058],eax
  805d62:	89 86 5c a0 00 00    	mov    DWORD PTR [esi+0xa05c],eax
  805d68:	89 86 60 a0 00 00    	mov    DWORD PTR [esi+0xa060],eax
  805d6e:	89 9e 68 a0 00 00    	mov    DWORD PTR [esi+0xa068],ebx
  805d74:	6a 0c                	push   0xc
  805d76:	89 9e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ebx
  805d7c:	e8 e7 b4 08 00       	call   0x891268
  805d81:	83 c4 04             	add    esp,0x4
  805d84:	3b c3                	cmp    eax,ebx
  805d86:	0f 84 b6 00 00 00    	je     0x805e42
  805d8c:	89 86 74 a0 00 00    	mov    DWORD PTR [esi+0xa074],eax
  805d92:	89 00                	mov    DWORD PTR [eax],eax
  805d94:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805d9a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  805d9d:	33 c0                	xor    eax,eax
  805d9f:	b9 01 00 00 00       	mov    ecx,0x1
  805da4:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  805da7:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805dad:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805db3:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805db9:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805dbf:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805dc5:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805dcb:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805dd1:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805dd7:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805ddd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  805de3:	89 8e b4 a0 00 00    	mov    DWORD PTR [esi+0xa0b4],ecx
  805de9:	89 9e b8 a0 00 00    	mov    DWORD PTR [esi+0xa0b8],ebx
  805def:	6a 18                	push   0x18
  805df1:	89 9e bc a0 00 00    	mov    DWORD PTR [esi+0xa0bc],ebx
  805df7:	e8 6c b4 08 00       	call   0x891268
  805dfc:	8b f8                	mov    edi,eax
  805dfe:	83 c4 04             	add    esp,0x4
  805e01:	3b fb                	cmp    edi,ebx
  805e03:	74 0e                	je     0x805e13
  805e05:	68 a0 0f 00 00       	push   0xfa0
  805e0a:	57                   	push   edi
  805e0b:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805e11:	eb 02                	jmp    0x805e15
  805e13:	33 ff                	xor    edi,edi
  805e15:	89 be d4 a0 00 00    	mov    DWORD PTR [esi+0xa0d4],edi
  805e1b:	e8 30 01 00 00       	call   0x805f50
  805e20:	89 b6 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],esi
  805e26:	89 b6 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],esi
  805e2c:	8b c6                	mov    eax,esi
  805e2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805e31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805e38:	59                   	pop    ecx
  805e39:	5f                   	pop    edi
  805e3a:	5e                   	pop    esi
  805e3b:	5b                   	pop    ebx
  805e3c:	8b e5                	mov    esp,ebp
  805e3e:	5d                   	pop    ebp
  805e3f:	c2 04 00             	ret    0x4
  805e42:	8d 4d f0             	lea    ecx,[ebp-0x10]
  805e45:	51                   	push   ecx
  805e46:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  805e49:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  805e4c:	e8 58 b2 08 00       	call   0x8910a9
  805e51:	68 a8 57 c8 00       	push   0xc857a8
  805e56:	8d 55 e4             	lea    edx,[ebp-0x1c]
  805e59:	52                   	push   edx
  805e5a:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  805e61:	e8 8a 6b 09 00       	call   0x89c9f0
  805e66:	cc                   	int3
  805e67:	cc                   	int3
  805e68:	cc                   	int3
  805e69:	cc                   	int3
  805e6a:	cc                   	int3
  805e6b:	cc                   	int3
  805e6c:	cc                   	int3
  805e6d:	cc                   	int3
  805e6e:	cc                   	int3
  805e6f:	cc                   	int3
  805e70:	55                   	push   ebp
  805e71:	8b ec                	mov    ebp,esp
  805e73:	6a ff                	push   0xffffffff
  805e75:	68 9c 99 90 00       	push   0x90999c
  805e7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805e80:	50                   	push   eax
  805e81:	56                   	push   esi
  805e82:	57                   	push   edi
  805e83:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805e88:	33 c5                	xor    eax,ebp
  805e8a:	50                   	push   eax
  805e8b:	8d 45 f4             	lea    eax,[ebp-0xc]
  805e8e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805e94:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805e97:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  805e9e:	e8 ad 00 00 00       	call   0x805f50
  805ea3:	8b be d4 a0 00 00    	mov    edi,DWORD PTR [esi+0xa0d4]
  805ea9:	85 ff                	test   edi,edi
  805eab:	74 1a                	je     0x805ec7
  805ead:	57                   	push   edi
  805eae:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  805eb4:	57                   	push   edi
  805eb5:	e8 52 b3 08 00       	call   0x89120c
  805eba:	83 c4 04             	add    esp,0x4
  805ebd:	c7 86 d4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0d4],0x0
  805ec4:	00 00 00 
  805ec7:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  805ecd:	8b 01                	mov    eax,DWORD PTR [ecx]
  805ecf:	89 09                	mov    DWORD PTR [ecx],ecx
  805ed1:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  805ed7:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  805eda:	c7 86 78 a0 00 00 00 	mov    DWORD PTR [esi+0xa078],0x0
  805ee1:	00 00 00 
  805ee4:	3b 86 74 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa074]
  805eea:	74 19                	je     0x805f05
  805eec:	8d 64 24 00          	lea    esp,[esp+0x0]
  805ef0:	8b 38                	mov    edi,DWORD PTR [eax]
  805ef2:	50                   	push   eax
  805ef3:	e8 14 b3 08 00       	call   0x89120c
  805ef8:	83 c4 04             	add    esp,0x4
  805efb:	8b c7                	mov    eax,edi
  805efd:	3b be 74 a0 00 00    	cmp    edi,DWORD PTR [esi+0xa074]
  805f03:	75 eb                	jne    0x805ef0
  805f05:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805f0b:	50                   	push   eax
  805f0c:	e8 fb b2 08 00       	call   0x89120c
  805f11:	8b be 1c 50 00 00    	mov    edi,DWORD PTR [esi+0x501c]
  805f17:	83 c4 04             	add    esp,0x4
  805f1a:	85 ff                	test   edi,edi
  805f1c:	74 1a                	je     0x805f38
  805f1e:	57                   	push   edi
  805f1f:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  805f25:	57                   	push   edi
  805f26:	e8 e1 b2 08 00       	call   0x89120c
  805f2b:	83 c4 04             	add    esp,0x4
  805f2e:	c7 86 1c 50 00 00 00 	mov    DWORD PTR [esi+0x501c],0x0
  805f35:	00 00 00 
  805f38:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805f3b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805f42:	59                   	pop    ecx
  805f43:	5f                   	pop    edi
  805f44:	5e                   	pop    esi
  805f45:	8b e5                	mov    esp,ebp
  805f47:	5d                   	pop    ebp
  805f48:	c2 04 00             	ret    0x4
  805f4b:	cc                   	int3
  805f4c:	cc                   	int3
  805f4d:	cc                   	int3
  805f4e:	cc                   	int3
  805f4f:	cc                   	int3
```


## E52.11 — 登入過渡 0x495610：key0/2 shutdown 及 key1 Conn 指標

**N**：`0x4956B8` 測試呼叫參數 `[EBP+0x10]`；非零分支透過 `FBA854` Manager `vtable+0x20` 依次 shutdown key0、key2（`0x4956F4–0x49570B`），若 `Client-like+BF60` 非零且走到 `0x49570D`，又 shutdown key1、清 BF60。之後 `0x49574E` 呼叫 `vtable+0x18` Connect，其端口常數 `0x20DF`、key1、pipeline2；成功後 `vtable+0x14` WSARecv post，`0x495794` 將新 Conn* 存回 `Client-like+BF60`。

**反證**：key0/2 的 `vtable+0x20` 是 shutdown-by-key、不是 `vtable+0x24` Conn-based closesocket／Pool28，亦非 map erase。`0x495610` 的 key1 非成功 branch 不等於「所有舊 Conn 已 release」。

**C/U**：`BF60` 存的是在此有效條件下的 Conn 指標；究竟是否是同 key replace old Conn 的唯一 alias，需跨 `0x4957C0` 和其他 Client writer 證據；不能把所有 Manager key-map Conn 都當成 BF60。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
495610:	55                   	push   ebp
  495611:	8b ec                	mov    ebp,esp
  495613:	83 e4 f8             	and    esp,0xfffffff8
  495616:	6a ff                	push   0xffffffff
  495618:	68 7c 1c 94 00       	push   0x941c7c
  49561d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  495623:	50                   	push   eax
  495624:	83 ec 08             	sub    esp,0x8
  495627:	53                   	push   ebx
  495628:	56                   	push   esi
  495629:	57                   	push   edi
  49562a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49562f:	33 c4                	xor    eax,esp
  495631:	50                   	push   eax
  495632:	8d 44 24 18          	lea    eax,[esp+0x18]
  495636:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49563c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  49563f:	33 ff                	xor    edi,edi
  495641:	83 ce ff             	or     esi,0xffffffff
  495644:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  49564b:	75 21                	jne    0x49566e
  49564d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  495654:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  495658:	e8 33 bf 04 00       	call   0x4e1590
  49565d:	68 80 cc bc 00       	push   0xbccc80
  495662:	e8 b3 cc 3f 00       	call   0x89231a
  495667:	83 c4 04             	add    esp,0x4
  49566a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  49566e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  495675:	89 3d c0 41 f9 00    	mov    DWORD PTR ds:0xf941c0,edi
  49567b:	75 25                	jne    0x4956a2
  49567d:	b8 01 00 00 00       	mov    eax,0x1
  495682:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  495688:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  49568c:	e8 ff be 04 00       	call   0x4e1590
  495691:	68 80 cc bc 00       	push   0xbccc80
  495696:	e8 7f cc 3f 00       	call   0x89231a
  49569b:	83 c4 04             	add    esp,0x4
  49569e:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4956a2:	6a 0a                	push   0xa
  4956a4:	68 fc d1 be 00       	push   0xbed1fc
  4956a9:	6a 0b                	push   0xb
  4956ab:	68 c4 41 f9 00       	push   0xf941c4
  4956b0:	e8 49 e9 3f 00       	call   0x893ffe
  4956b5:	83 c4 10             	add    esp,0x10
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2 0c 00             	ret    0xc
  4957ba:	cc                   	int3
  4957bb:	cc                   	int3
  4957bc:	cc                   	int3
  4957bd:	cc                   	int3
  4957be:	cc                   	int3
  4957bf:	cc                   	int3
```


## E52.12 — 選服 0x4957C0：部分 Connect 成功時 key0/key2 不保證都清除

**N**：`0x4957DF–0x495805` 先以同 host 對 key0 / port `0x20E0`，再 key2 / port `0x20DE` 呼叫 Manager Connect；只在兩個 Conn* 都非零時繼續 successful branch。之後有 `Client-like+BF60` 非零時，`0x495839` 先呼叫 queue drain `0x8063E0`，再以 `0x8060D0` 在舊 BF60 Conn 排 `0x007E`、設 `A0B0=1`，把 Client BF60 清零；**本地 enqueue 不等於舊 key1 socket 已完成 closesocket**。

**N**：E51 已重驗 key0/key2 一條失敗時走 `vtable+0x20` shutdown 另一條 key，而不是 full cleanup。此 E52 提供更清楚對照：Client BF60 alias 清除只在**兩條新 Conn 成功後**的特定分支執行，不是每次 key0 或 key2 connect fail 都執行。

**C**：若舊 Conn 後續仍在 key-map，而被 cleanup 排入 `0x007E`，`A0B0` 是 close/marker 類旗標候選；其最終 Server ACK 或 flush 時點尚未證明。

**反證**：不能說 key0 的 `0x0001` 57-byte 一定是 Server 上第一個 observed frame；本地 queue/sleep/WSASend 和 TCP timing 是不同層級。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
```


## E52.13 — 0x807090：不經 Manager key-map 的獨立 Conn acquire＋IOCP receive

**N**：`0x8070BD` 呼叫 `0x805950(0)`，`0x8070D0–0x8070EF` 將外部既存 socket 和 4 DWORD 元資料複製入新 Conn，`0x8070F2–0x8070FE` 以 `CreateIoCompletionPort` 綁 socket 與 Conn pointer completion key，`0x807104–0x80710C` 經 vtable+0x14 post WSARecv，返回 1。**整段沒有** `Manager+0x18` active key-map insert。

**C**：原生有 Conn 不在 key-map 的反例；因此 same-key replace 時不可能單靠「map 現值」推斷所有 Conn owner。`0x807090` 本身亦未交出長期 owner 合約；與 `0x806AD0` 兩條 producer 不得混為相同 TCP 建立角色。

**U**：此路徑的間接 vtable caller，連線接受來源是否正式 WSAccept 或其他上游，不能從這個子函式範圍唯一推定；舊 Conn orphan 仍需獨立證據。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
807090:	55                   	push   ebp
  807091:	8b ec                	mov    ebp,esp
  807093:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  80709a:	53                   	push   ebx
  80709b:	56                   	push   esi
  80709c:	8b d9                	mov    ebx,ecx
  80709e:	75 15                	jne    0x8070b5
  8070a0:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8070a7:	74 07                	je     0x8070b0
  8070a9:	e8 b2 3e c9 ff       	call   0x49af60
  8070ae:	eb 05                	jmp    0x8070b5
  8070b0:	e8 4b 3f c9 ff       	call   0x49b000
  8070b5:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  8070bb:	6a 00                	push   0x0
  8070bd:	e8 8e e8 ff ff       	call   0x805950
  8070c2:	8b f0                	mov    esi,eax
  8070c4:	85 f6                	test   esi,esi
  8070c6:	75 06                	jne    0x8070ce
  8070c8:	5e                   	pop    esi
  8070c9:	5b                   	pop    ebx
  8070ca:	5d                   	pop    ebp
  8070cb:	c2 08 00             	ret    0x8
  8070ce:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8070d1:	8b 08                	mov    ecx,DWORD PTR [eax]
  8070d3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  8070d6:	89 0e                	mov    DWORD PTR [esi],ecx
  8070d8:	8b 10                	mov    edx,DWORD PTR [eax]
  8070da:	89 56 04             	mov    DWORD PTR [esi+0x4],edx
  8070dd:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8070e0:	89 4e 08             	mov    DWORD PTR [esi+0x8],ecx
  8070e3:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  8070e6:	89 56 0c             	mov    DWORD PTR [esi+0xc],edx
  8070e9:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  8070ec:	57                   	push   edi
  8070ed:	8b 3e                	mov    edi,DWORD PTR [esi]
  8070ef:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  8070f2:	e8 29 f5 ff ff       	call   0x806620
  8070f7:	8b 08                	mov    ecx,DWORD PTR [eax]
  8070f9:	6a 00                	push   0x0
  8070fb:	56                   	push   esi
  8070fc:	51                   	push   ecx
  8070fd:	57                   	push   edi
  8070fe:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  807104:	8b 13                	mov    edx,DWORD PTR [ebx]
  807106:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  807109:	56                   	push   esi
  80710a:	8b cb                	mov    ecx,ebx
  80710c:	ff d0                	call   eax
  80710e:	5f                   	pop    edi
  80710f:	5e                   	pop    esi
  807110:	b8 01 00 00 00       	mov    eax,0x1
  807115:	5b                   	pop    ebx
  807116:	5d                   	pop    ebp
  807117:	c2 08 00             	ret    0x8
  80711a:	cc                   	int3
  80711b:	cc                   	int3
  80711c:	cc                   	int3
  80711d:	cc                   	int3
  80711e:	cc                   	int3
  80711f:	cc                   	int3
  807120:	55                   	push   ebp
  807121:	8b ec                	mov    ebp,esp
  807123:	6a ff                	push   0xffffffff
  807125:	68 99 74 90 00       	push   0x907499
  80712a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807130:	50                   	push   eax
  807131:	83 ec 24             	sub    esp,0x24
  807134:	53                   	push   ebx
  807135:	56                   	push   esi
  807136:	57                   	push   edi
  807137:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80713c:	33 c5                	xor    eax,ebp
  80713e:	50                   	push   eax
  80713f:	8d 45 f4             	lea    eax,[ebp-0xc]
  807142:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  807148:	33 f6                	xor    esi,esi
  80714a:	6a 0c                	push   0xc
  80714c:	c7 45 e8 58 33 fe 00 	mov    DWORD PTR [ebp-0x18],0xfe3358
  807153:	89 35 5c 33 fe 00    	mov    DWORD PTR ds:0xfe335c,esi
  807159:	e8 0a a1 08 00       	call   0x891268
  80715e:	83 c4 04             	add    esp,0x4
  807161:	3b c6                	cmp    eax,esi
  807163:	0f 84 b1 01 00 00    	je     0x80731a
  807169:	a3 58 33 fe 00       	mov    ds:0xfe3358,eax
  80716e:	89 00                	mov    DWORD PTR [eax],eax
  807170:	a1 58 33 fe 00       	mov    eax,ds:0xfe3358
  807175:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  807178:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  80717b:	6a 08                	push   0x8
  80717d:	89 35 64       	mov    DWORD PTR ds:0xfe3364,esi
```


## E52.14 — IOCP 與 Pool 閉合邊界：SEND 計數不是接收完成屏障

**N**：`0x806CF0` 由 `GetQueuedCompletionStatus` 取 Conn completion key、OVERLAPPED、bytes。`Conn+A030` 完成才進 parser/WSARecv repost；`Conn+A050` 完成才在 `0x806EC3/0x806EF1` 計 `InterlockedDecrement(&A0B8)`。`0x805B40` 只在 `A0B8==0` 時移動 Pool+48 Conn 到 reuse vector 與 reset，卻沒有同步檢查 `A0BC` 或 `A030` receive 正在使用。

**C**：因此此**可見** recycle gate 是 SEND completion-dimension 的限制，不是涵蓋所有 pending RECV 與所有 callback 的完整 happens-before。IOCP recv 失敗是否先呼叫 close、`A0A8` 被寫入，與 recycle 在不同執行緒的排序仍未證。

**反證**：不能拿 `A0B8==0` 證成 「全部非同步 I/O 都已 drain」；也不能拿它單獨證明一定發生 UAF。

**原件 `.text`／反組譯（只讀）**：raw=`VA−0x400C00`。

```asm
806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
  806f2e:	8b 5b 58             	mov    ebx,DWORD PTR [ebx+0x58]
  806f31:	3b de                	cmp    ebx,esi
  806f33:	74 10                	je     0x806f45
  806f35:	68 f4 16 c5 00       	push   0xc516f4
  806f3a:	56                   	push   esi
  806f3b:	8b fb                	mov    edi,ebx
  806f3d:	e8 be 94 ee ff       	call   0x6f0400
  806f42:	83 c4 08             	add    esp,0x8
  806f45:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  806f48:	5f                   	pop    edi
  806f49:	5e                   	pop    esi
  806f4a:	33 cd                	xor    ecx,ebp
  806f4c:	5b                   	pop    ebx
  806f4d:	e8 af a0 08 00       	call   0x891001
  806f52:	8b e5                	mov    esp,ebp
  806f54:	5d                   	pop    ebp
  806f55:	c3                   	ret
  806f56:	cc                   	int3
  806f57:	cc                   	int3
  806f58:	cc                   	int3
  806f59:	cc                   	int3
  806f5a:	cc                   	int3
  806f5b:	cc                   	int3
  806f5c:	cc                   	int3
  806f5d:	cc                   	int3
  806f5e:	cc                   	int3
  806f5f:	cc                   	int3
```


## E52.15 — 整合 RR-0005 的有界狀態與 E53 啟動清單

### 可見原生狀態矩陣（只適用已核的分支）

| 情境 | Conn / key-map | queue / socket | 計數 gate | 結論 |
|---|---|---|---|---|
| fresh `0x805950` | new `0xA0D8`，可後續 map insert | 初始 socket=-1；A02C=2 | Pool+38/3C/40→A0C8/CC/D0 | N：fresh 特定組態 |
| reused `0x805950` | vector 取舊 Conn | `0x805F50` 先 socket=-1 並 queue drain | A0C8/CC/D0 清 0，沒有 fresh copy | N：reuse 不對稱；後續 writer U |
| `0x8065B0` recv gate | Conn 持有 | 無直接 socket API | A0C8, A0B4, A0BC, A0CC, A0D0 | N：條件式 close signal |
| `0x806A00` WSARecv post | `A030` receive overlapped | post 後可能 close | 未見 A0B8 +1 | N；並發 U |
| `0x804B/8052` decoder fail | Conn pointer | queue drain → vtable+24 | 無本地 A0B8 reset | N；map erase U |
| decoder over `A0A4>300` | Conn pointer | A0B4==2: shutdown + 806010；其他: close-by-Conn | A0B8 未必為 0 | N；完整 socket lifetime U |
| `0x495610` key1 過渡 | shutdown key0/2（條件式），BF60 換新 Conn | Connect 0x20DF | 由相應 post 發生 | N：本地；wire U |
| `0x4957C0` key0/2 | success 2 條才繼續 | BF60 舊 queue 先 drain，enqueue 0x007E | 尚待 completion | N：本地；wire U |
| Pool+48 sweep | Conn pointer | `805F50` reset → reuse | 只檢 A0B8==0 | N：SEND-dimension zero gate |

### 本段新證據與前段差異

1. `0x8063E0` 已拆為 **Conn queue list → global payload free pool** 的完整原生資料流，**不能**拿它作為 socket close 的證據。
2. `0x805950` 的 **fresh vs reused** 三個 throttle 欄位 `A0C8/A0CC/A0D0` 有新且可檢驗的 CFG 不對稱；連同 A02C mode 將直接影響重連 framing／接收 gate 的條件式模型。
3. `0x804B/8052` decoder callback 的 A0B4==2 vs !=2 不同 close path 與 300 gate，為之前尚未明確跨連接模式統合的分支。
4. `0x495610` 的 key1/BF60 過渡與 `0x4957C0` 舊 BF60 queue 0x007E 的位置明確分離；map erase、close、flush 的同一次實際 session 順序仍 U。

### 開放問題與 E53

- **Client 待逆向**：`Pool+38/3C/40` 真正配置來源（值是多少、何時更新）、reuse Conn A0C8/CC/D0 事後 writer、Conn+14 非零 writer、A0B4=2 writer、A02C mode 間接 writer、same-key replacement 舊 Conn owner、管理器析構與 Pool+48 的完整 socket close、IOCP concurrent receive safe ordering。
- **跨功能待整合**：T03 S2C `0x0013/0x007A` → UI→key1/key0/key2 同一 session；不要將 T03 角色業務原稿搬為 T02 新主責。
- **待遊玩驗證**：可合法進行的 reconnect/recv error/full socket handle trace；原始第一筆 wire 與 Server 首回覆，須由 PCAP / debugger live evidence 另取。
- **Server 待開發**：依 native 已證 host/key/port 參數、區分 1A68/0BBB framing 與真正 C2S payload 的相容實作，不能由舊 port 硬編新部署規則、不能捏造原版 Server 內部決策。

**正式停止原因 B**：本段達 15 個研究單元。即使重大新發現已出現，並未提前以局部成功結束；RR 仍不等於 S00 ACCEPTED 或 T01 FULL-PASS。完整原生證據與反證見下方附錄，原稿 Push 狀態依此後實際 GitHub 操作另核實。


## 附錄 A — 指令與 xref 重現索引

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -h /mnt/data/Tartaros.bin
objdump -p /mnt/data/Tartaros.bin
# .text raw 0x400, VMA 0x401000；不能把 .text 偏移用到 .rdata IAT
dd if=/mnt/data/Tartaros.bin of=/mnt/data/e52-text.bin bs=1 skip=1024 count=8192496 status=none
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x8063e0 --stop-address=0x8065b0 /mnt/data/e52-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x805950 --stop-address=0x805a80 /mnt/data/e52-text.bin
```

| Native target | E8 direct caller bytes candidate（經可見 caller 區域指令界線復核；非所有 virtual/indirect） |
|---|---|
| `8063E0` | `495839`, `804B61`, `804BB9`, `8052B3`, `805313`, `805FDA`, `806021` |
| `8065B0` | `806AAB` |
| `806010` | `804C33`, `80538D` |
| `805F50` | `8059E9`, `805BB7`, `805E1B`, `805E9E` |
| `495610` | `6D6377`, `6D6424`, `6D6508`, `6D65C8`, `6D670C`, `6D696C`（本段未逐一閉合每個上游 business branch） |
| `4957C0` | `66C1A7`, `66C247` |

**重要界線**：E8 byte candidates may include immediates/data; do not use to claim exhaustive callers. Vtable `0xC51748` + 0x0C send, +0x14 recv, +0x18 connect, +0x1C shutdown conn, +0x20 shutdown key, +0x24 close by Conn, +0x28 separate IOCP binding path; these are `.rdata` pointer offsets, not independent function addresses.

## 附錄 B — 來源保護與後續移交

- 未取得真正原版 Server binary、登入 session wire capture、並發活動追蹤，不做官方 Server 決策、動態 race 或實際 playable 的肯定主張。
- `0x13/0x7A` 與選服 UI 的業務 handler，引用 E44/E45 與 T03 已有研究，非 E52 新確定的所有網路先後。
- E51 必須與 E52 並存，不能只上傳本摘要替代其 2,600 行技術原稿。
- 工作分支 `extra/roy1`；RR 台帳的 main claim 不應搬到個人研究筆記。任何下一次狀態變動再遵守 dispatch CLI schema 和 main 發布。
