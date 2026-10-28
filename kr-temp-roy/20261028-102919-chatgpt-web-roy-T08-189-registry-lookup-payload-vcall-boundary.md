# T08-189 — 索引查找與 payload 多型移除之 ABI／回呼約束

- 研究時間（Asia/Taipei）：2026-10-28T10:29:19+08:00
- 研究者：`chatgpt-web roy`；範圍：KR T08 靜態研究／正式 0007 實體建立、登記、移除之介面（資源管理為上下游線索）
- 證據：原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算一致）。PE `.text` VA `0x401000`/raw `0x400`、section size `0x7D01F0`（以 `objdump -h` 檢視）；唯讀，未執行遊戲。
- GitHub：`we88ec3-prog/ttr_anal_multi` `main`；沿 T08-185～188 證據線索接續。以下皆以 RVA 映射實際機器碼獨立檢視；舊筆記不取代第一手驗證。

## 本段實質研究結果及證據等級

1. **已確認** `0x007DC510` 是索引查找與條件移除鏈，`0x007DC591` 取 `[ebp-0x4C]`，`0x007DC594` 和 `[esi+4]` 哨兵比對；不存在時不走 payload 回呼。這條與場景 actor tree 尚未有同一實例的直接指標證明。

2. **已確認** `0x007DC599` 取得 `node+0x24` payload，`0x007DC59C～0x007DC5A3` 先調用 payload vtable `+0x0C`；零值返回才於 `0x007DC5B0` 呼叫 vtable `+0x00`，再於 `0x007DC5C2` 調用 `0x007B8680` 刪索引節點。這是回呼閘門，不可稱 callback 是析構。

3. **部分確認** `0x007DD17D` 從 manager 最終引用流程傳入全域名稱索引 `[0x00FE173C]`；未取得該節點 payload 的具體 vptr 值，無法將兩個間接呼叫解析到單一實作。

4. **新增交叉驗證** `0x007B86F0` 查找者不只 `0x007DC510`；多處引用不同 owner，不能由同一名稱查詢函式認定 owner 同型或同實例。

## 相關函式與前段差異

本段重點縮小 T08-185 未定 callback 的實際依賴：`lookup -> compare sentinel -> payload vtable+0C -> optional +00 -> erase`。並保留實際多型目標、節點配置來源的缺口。

## E8 相對位移重新實算（僅 byte 候選，不是完整 CFG）

- 目標 `0x007DC510`：1 候選：`0x007DD17D` (`e88ef3ffff`)
- 目標 `0x007DD160`：0 候選：無
- 目標 `0x007B86F0`：14 候選：`0x007194D9` (`e812f20900`), `0x0071954A` (`e8a1f10900`), `0x00719868` (`e883ee0900`), `0x00719A09` (`e8e2ec0900`), `0x007B80FA` (`e8f1050000`), `0x007B81E5` (`e806050000`), `0x007B8360` (`e88b030000`), `0x007B84F7` (`e8f4010000`), `0x007BE04A` (`e8a1a6ffff`), `0x007D09B1` (`e83a7dfeff`), `0x007D0E89` (`e86278feff`), `0x007DC573` (`e878c1fdff`), `0x007DC78B` (`e860bffdff`), `0x007DC868` (`e883befdff`)

**限制**：此掃描在 `.text` 每 byte 搜索 `E8 + signed rel32`，可能包含非指令邊界，亦不包含 FF/2、vtable 或反常 CFG；只可當交叉參照候選。

## 有界資料流與 ABI 注意

下列地址窗口從明示 VA 分段反組譯；函式入口／呼叫慣例需依 prologue、callsite 和實際 CFG 共同確認。若觀察到 `+0x44/+0x5C/+0x60` 等相同欄位，**只有在 pointer provenance 相同時**才視為同一結構；不得以同 offset 合併 actor、resource、registry、wrapper。

## 待查問題及下一段入口

1. 取得 `node+0x24` 寫入時的真實 vptr，建立以構造點為中心的間接 call 目標集合。
2. 對每個 caller 核對 ECX/EDX ABI 及字串暫存生命週期。
3. 檢查 callback 非零返回時是否仍可能從其他路徑移除節點。

## 附錄：原始 BIN 組語（objdump x86 Intel，指定 VA 有界解碼）

### `0x007DC510` ～ `0x007DC660`

```asm
  7dc510:	55                   	push   ebp
  7dc511:	8b ec                	mov    ebp,esp
  7dc513:	6a ff                	push   0xffffffff
  7dc515:	68 b0 49 91 00       	push   0x9149b0
  7dc51a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc520:	50                   	push   eax
  7dc521:	83 ec 44             	sub    esp,0x44
  7dc524:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc529:	33 c5                	xor    eax,ebp
  7dc52b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7dc52e:	53                   	push   ebx
  7dc52f:	56                   	push   esi
  7dc530:	57                   	push   edi
  7dc531:	50                   	push   eax
  7dc532:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dc535:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc53b:	8b fa                	mov    edi,edx
  7dc53d:	33 db                	xor    ebx,ebx
  7dc53f:	8b c7                	mov    eax,edi
  7dc541:	8b f1                	mov    esi,ecx
  7dc543:	c7 45 cc 0f 00 00 00 	mov    DWORD PTR [ebp-0x34],0xf
  7dc54a:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  7dc54d:	88 5d b8             	mov    BYTE PTR [ebp-0x48],bl
  7dc550:	8d 50 01             	lea    edx,[eax+0x1]
  7dc553:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc555:	40                   	inc    eax
  7dc556:	3a cb                	cmp    cl,bl
  7dc558:	75 f9                	jne    0x7dc553
  7dc55a:	2b c2                	sub    eax,edx
  7dc55c:	50                   	push   eax
  7dc55d:	57                   	push   edi
  7dc55e:	8d 4d b8             	lea    ecx,[ebp-0x48]
  7dc561:	e8 0a 65 c2 ff       	call   0x402a70
  7dc566:	8d 45 b8             	lea    eax,[ebp-0x48]
  7dc569:	50                   	push   eax
  7dc56a:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc56d:	51                   	push   ecx
  7dc56e:	8b c6                	mov    eax,esi
  7dc570:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dc573:	e8 78 c1 fd ff       	call   0x7b86f0
  7dc578:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7dc57f:	83 7d cc 10          	cmp    DWORD PTR [ebp-0x34],0x10
  7dc583:	72 0c                	jb     0x7dc591
  7dc585:	8b 55 b8             	mov    edx,DWORD PTR [ebp-0x48]
  7dc588:	52                   	push   edx
  7dc589:	e8 7e 4c 0b 00       	call   0x89120c
  7dc58e:	83 c4 04             	add    esp,0x4
  7dc591:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc594:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7dc597:	74 33                	je     0x7dc5cc
  7dc599:	8b 78 24             	mov    edi,DWORD PTR [eax+0x24]
  7dc59c:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc59e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7dc5a1:	8b cf                	mov    ecx,edi
  7dc5a3:	ff d2                	call   edx
  7dc5a5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  7dc5a8:	3b c3                	cmp    eax,ebx
  7dc5aa:	0f 85 8a 00 00 00    	jne    0x7dc63a
  7dc5b0:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc5b2:	8b 10                	mov    edx,DWORD PTR [eax]
  7dc5b4:	6a 01                	push   0x1
  7dc5b6:	8b cf                	mov    ecx,edi
  7dc5b8:	ff d2                	call   edx
  7dc5ba:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc5bd:	50                   	push   eax
  7dc5be:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc5c1:	51                   	push   ecx
  7dc5c2:	e8 b9 c0 fd ff       	call   0x7b8680
  7dc5c7:	8b 45 b0             	mov    eax,DWORD PTR [ebp-0x50]
  7dc5ca:	eb 6e                	jmp    0x7dc63a
  7dc5cc:	8b c7                	mov    eax,edi
  7dc5ce:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7dc5d5:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  7dc5d8:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  7dc5db:	8d 50 01             	lea    edx,[eax+0x1]
  7dc5de:	8b ff                	mov    edi,edi
  7dc5e0:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc5e2:	40                   	inc    eax
  7dc5e3:	3a cb                	cmp    cl,bl
  7dc5e5:	75 f9                	jne    0x7dc5e0
  7dc5e7:	2b c2                	sub    eax,edx
  7dc5e9:	50                   	push   eax
  7dc5ea:	57                   	push   edi
  7dc5eb:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7dc5ee:	e8 7d 64 c2 ff       	call   0x402a70
  7dc5f3:	6a 43                	push   0x43
  7dc5f5:	68 78 03 c5 00       	push   0xc50378
  7dc5fa:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7dc5fd:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7dc604:	e8 b7 59 c2 ff       	call   0x401fc0
  7dc609:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  7dc60c:	be 10 00 00 00       	mov    esi,0x10
  7dc611:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  7dc614:	73 03                	jae    0x7dc619
  7dc616:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7dc619:	53                   	push   ebx
  7dc61a:	68 d4 53 c4 00       	push   0xc453d4
  7dc61f:	50                   	push   eax
  7dc620:	53                   	push   ebx
  7dc621:	ff 15 90 24 bd 00    	call   DWORD PTR ds:0xbd2490
  7dc627:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  7dc62a:	72 0c                	jb     0x7dc638
  7dc62c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7dc62f:	52                   	push   edx
  7dc630:	e8 d7 4b 0b 00       	call   0x89120c
  7dc635:	83 c4 04             	add    esp,0x4
  7dc638:	33 c0                	xor    eax,eax
  7dc63a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dc63d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dc644:	59                   	pop    ecx
  7dc645:	5f                   	pop    edi
  7dc646:	5e                   	pop    esi
  7dc647:	5b                   	pop    ebx
  7dc648:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  7dc64b:	33 cd                	xor    ecx,ebp
  7dc64d:	e8 af 49 0b 00       	call   0x891001
  7dc652:	8b e5                	mov    esp,ebp
  7dc654:	5d                   	pop    ebp
  7dc655:	c3                   	ret
  7dc656:	cc                   	int3
  7dc657:	cc                   	int3
  7dc658:	cc                   	int3
  7dc659:	cc                   	int3
  7dc65a:	cc                   	int3
  7dc65b:	cc                   	int3
  7dc65c:	cc                   	int3
  7dc65d:	cc                   	int3
  7dc65e:	cc                   	int3
  7dc65f:	cc                   	int3
```

### `0x007DD160` ～ `0x007DD1B5`

```asm
  7dd160:	04 89                	add    al,0x89
  7dd162:	7d fc                	jge    0x7dd160
  7dd164:	8b 7e 50             	mov    edi,DWORD PTR [esi+0x50]
  7dd167:	2b 7e 4c             	sub    edi,DWORD PTR [esi+0x4c]
  7dd16a:	c1 ff 02             	sar    edi,0x2
  7dd16d:	3b fb                	cmp    edi,ebx
  7dd16f:	76 16                	jbe    0x7dd187
  7dd171:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  7dd174:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7dd177:	8b 0d 3c 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe173c
  7dd17d:	e8 8e f3 ff ff       	call   0x7dc510
  7dd182:	43                   	inc    ebx
  7dd183:	3b df                	cmp    ebx,edi
  7dd185:	72 ea                	jb     0x7dd171
  7dd187:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd18a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dd18d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dd194:	59                   	pop    ecx
  7dd195:	5f                   	pop    edi
  7dd196:	5e                   	pop    esi
  7dd197:	5b                   	pop    ebx
  7dd198:	8b e5                	mov    esp,ebp
  7dd19a:	5d                   	pop    ebp
  7dd19b:	c3                   	ret
  7dd19c:	cc                   	int3
  7dd19d:	cc                   	int3
  7dd19e:	cc                   	int3
  7dd19f:	cc                   	int3
  7dd1a0:	55                   	push   ebp
  7dd1a1:	8b ec                	mov    ebp,esp
  7dd1a3:	53                   	push   ebx
  7dd1a4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dd1a7:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd1ab:	57                   	push   edi
  7dd1ac:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  7dd1af:	7c 24                	jl     0x7dd1d5
  7dd1b1:	56                   	push   esi
  7dd1b2:	8d 73 64             	lea    esi,[ebx+0x64]
```

### `0x007B86F0` ～ `0x007B8775`

```asm
  7b86f0:	55                   	push   ebp
  7b86f1:	8b ec                	mov    ebp,esp
  7b86f3:	83 ec 10             	sub    esp,0x10
  7b86f6:	53                   	push   ebx
  7b86f7:	56                   	push   esi
  7b86f8:	8b f0                	mov    esi,eax
  7b86fa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b86fd:	57                   	push   edi
  7b86fe:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  7b8701:	e8 da 9e d9 ff       	call   0x5525e0
  7b8706:	23 c7                	and    eax,edi
  7b8708:	39 46 24             	cmp    DWORD PTR [esi+0x24],eax
  7b870b:	77 09                	ja     0x7b8716
  7b870d:	d1 ef                	shr    edi,1
  7b870f:	83 c9 ff             	or     ecx,0xffffffff
  7b8712:	2b cf                	sub    ecx,edi
  7b8714:	03 c1                	add    eax,ecx
  7b8716:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  7b8719:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b871c:	8d 04 c2             	lea    eax,[edx+eax*8]
  7b871f:	8b 10                	mov    edx,DWORD PTR [eax]
  7b8721:	8b ca                	mov    ecx,edx
  7b8723:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7b8726:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  7b8729:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7b872c:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  7b872f:	90                   	nop
  7b8730:	3b d6                	cmp    edx,esi
  7b8732:	75 04                	jne    0x7b8738
  7b8734:	8b c6                	mov    eax,esi
  7b8736:	eb 05                	jmp    0x7b873d
  7b8738:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  7b873b:	8b 00                	mov    eax,DWORD PTR [eax]
  7b873d:	3b c8                	cmp    ecx,eax
  7b873f:	0f 84 d5 00 00 00    	je     0x7b881a
  7b8745:	8d 41 08             	lea    eax,[ecx+0x8]
  7b8748:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  7b874b:	8b 79 10             	mov    edi,DWORD PTR [ecx+0x10]
  7b874e:	bb 10 00 00 00       	mov    ebx,0x10
  7b8753:	39 59 14             	cmp    DWORD PTR [ecx+0x14],ebx
  7b8756:	72 02                	jb     0x7b875a
  7b8758:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b875a:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  7b875d:	8b d6                	mov    edx,esi
  7b875f:	3b d6                	cmp    edx,esi
  7b8761:	73 00                	jae    0x7b8763
  7b8763:	8b d6                	mov    edx,esi
  7b8765:	3b f7                	cmp    esi,edi
  7b8767:	72 02                	jb     0x7b876b
  7b8769:	8b d7                	mov    edx,edi
  7b876b:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  7b876e:	72 02                	jb     0x7b8772
  7b8770:	8b 00                	mov    eax,DWORD PTR [eax]
  7b8772:	52                   	push   edx
  7b8773:	8b d0                	mov    edx,eax
```