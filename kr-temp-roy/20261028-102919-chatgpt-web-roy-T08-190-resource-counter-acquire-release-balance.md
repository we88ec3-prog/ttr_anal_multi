# T08-190 — 資源池取得／解除引用之 +0x60 計數與條件分支核對

- 研究時間（Asia/Taipei）：2026-10-28T10:29:19+08:00
- 研究者：`chatgpt-web roy`；範圍：KR T08 靜態研究／正式 0007 實體建立、登記、移除之介面（資源管理為上下游線索）
- 證據：原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算一致）。PE `.text` VA `0x401000`/raw `0x400`、section size `0x7D01F0`（以 `objdump -h` 檢視）；唯讀，未執行遊戲。
- GitHub：`we88ec3-prog/ttr_anal_multi` `main`；沿 T08-185～188 證據線索接續。以下皆以 RVA 映射實際機器碼獨立檢視；舊筆記不取代第一手驗證。

## 本段實質研究結果及證據等級

1. **已確認** 取得資源 `0x007DCFB0` 在 `0x007DCFBA` 先 `inc [ebx+0x60]`，再以 `owner+0x64` 鎖保護 `+0x7C/+0x80` 指標陣列；非空取尾端指標走 `0x007BE5B0` 重設，空陣列則 `push 0x7C; call 0x00891268` 配置。增量發生在配置是否成功之前。

2. **已確認** `0x007BE5F0` 中存在 `owner+0x60` 減量與 `0x007DD1A0` 條件回收鏈，但在既有靜態窗口之外不能假定所有 wrapper、NULL 或失敗分支均成對。

3. **已確認** `0x007DD1A0` 依 owner+0x44 判斷是排隊復用還是進入立即釋放分支。`+0x5C` 另由 manager 引用終止流程使用，不等於 `+0x60`。

4. **尚待驗證** 取得端 `+0x60++` 與釋放端 `+0x60--` 不足以證明異常與配置失敗下的嚴格平衡；需對所有返回點、間接析構與被呼叫者的成功/失敗分支逐條審計。

## 相關函式與前段差異

前段 181 定位 pool pop，本段用取得與解除引用兩端並列對照：`+0x60` 代表同一管理器局部活動數的候選含義，**不是** 已證明引用計數全局不變式。

## E8 相對位移重新實算（僅 byte 候選，不是完整 CFG）

- 目標 `0x007DCFB0`：2 候選：`0x007B8275` (`e8364d0200`), `0x007F6FDC` (`e8cf5ffeff`)
- 目標 `0x007BE5F0`：42 候選：`0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`), `0x004D2632` (`e8b9bf2e00`), `0x004D26BE` (`e82dbf2e00`), `0x004D2772` (`e879be2e00`), `0x004D287D` (`e86ebd2e00`), `0x00543B98` (`e853aa2700`), `0x00543FDF` (`e80ca62700`), `0x0054480B` (`e8e09d2700`), `0x00550B7D` (`e86eda2600`), `0x00550DAE` (`e83dd82600`), `0x00550EF9` (`e8f2d62600`), `0x00550EFE` (`e8edd62600`), `0x00550FB5` (`e836d62600`), `0x00552380` (`e86bc22600`)；其餘略
- 目標 `0x007DD1A0`：2 候選：`0x007A8741` (`e85a4a0300`), `0x007BE60F` (`e88ceb0100`)

**限制**：此掃描在 `.text` 每 byte 搜索 `E8 + signed rel32`，可能包含非指令邊界，亦不包含 FF/2、vtable 或反常 CFG；只可當交叉參照候選。

## 有界資料流與 ABI 注意

下列地址窗口從明示 VA 分段反組譯；函式入口／呼叫慣例需依 prologue、callsite 和實際 CFG 共同確認。若觀察到 `+0x44/+0x5C/+0x60` 等相同欄位，**只有在 pointer provenance 相同時**才視為同一結構；不得以同 offset 合併 actor、resource、registry、wrapper。

## 待查問題及下一段入口

1. 逐條列舉 `0x007DCFB0` alloc 失敗／子項 alloc 失敗的每個返回值。
2. 調查跨 thread `+0x60++` 位於鎖外是否另有上層同步前提。
3. 追蹤 `0x007BE5F0` 被多個 caller 重複使用時的實參指標型別。

## 附錄：原始 BIN 組語（objdump x86 Intel，指定 VA 有界解碼）

### `0x007DCFB0` ～ `0x007DD100`

```asm
  7dcfb0:	55                   	push   ebp
  7dcfb1:	8b ec                	mov    ebp,esp
  7dcfb3:	83 ec 10             	sub    esp,0x10
  7dcfb6:	53                   	push   ebx
  7dcfb7:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dcfba:	ff 43 60             	inc    DWORD PTR [ebx+0x60]
  7dcfbd:	56                   	push   esi
  7dcfbe:	57                   	push   edi
  7dcfbf:	8d 7b 64             	lea    edi,[ebx+0x64]
  7dcfc2:	57                   	push   edi
  7dcfc3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dcfc9:	8b 43 7c             	mov    eax,DWORD PTR [ebx+0x7c]
  7dcfcc:	3b 83 80 00 00 00    	cmp    eax,DWORD PTR [ebx+0x80]
  7dcfd2:	74 36                	je     0x7dd00a
  7dcfd4:	8b 83 80 00 00 00    	mov    eax,DWORD PTR [ebx+0x80]
  7dcfda:	8b 70 fc             	mov    esi,DWORD PTR [eax-0x4]
  7dcfdd:	8b c6                	mov    eax,esi
  7dcfdf:	e8 cc 15 fe ff       	call   0x7be5b0
  7dcfe4:	8b 83 80 00 00 00    	mov    eax,DWORD PTR [ebx+0x80]
  7dcfea:	39 43 7c             	cmp    DWORD PTR [ebx+0x7c],eax
  7dcfed:	74 09                	je     0x7dcff8
  7dcfef:	83 c0 fc             	add    eax,0xfffffffc
  7dcff2:	89 83 80 00 00 00    	mov    DWORD PTR [ebx+0x80],eax
  7dcff8:	57                   	push   edi
  7dcff9:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dcfff:	8b c6                	mov    eax,esi
  7dd001:	5f                   	pop    edi
  7dd002:	5e                   	pop    esi
  7dd003:	5b                   	pop    ebx
  7dd004:	8b e5                	mov    esp,ebp
  7dd006:	5d                   	pop    ebp
  7dd007:	c2 04 00             	ret    0x4
  7dd00a:	57                   	push   edi
  7dd00b:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd011:	6a 7c                	push   0x7c
  7dd013:	e8 50 42 0b 00       	call   0x891268
  7dd018:	33 ff                	xor    edi,edi
  7dd01a:	83 c4 04             	add    esp,0x4
  7dd01d:	3b c7                	cmp    eax,edi
  7dd01f:	74 15                	je     0x7dd036
  7dd021:	d9 43 48             	fld    DWORD PTR [ebx+0x48]
  7dd024:	51                   	push   ecx
  7dd025:	8b cb                	mov    ecx,ebx
  7dd027:	d9 1c 24             	fstp   DWORD PTR [esp]
  7dd02a:	e8 b1 07 fe ff       	call   0x7bd7e0
  7dd02f:	8b f0                	mov    esi,eax
  7dd031:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  7dd034:	eb 05                	jmp    0x7dd03b
  7dd036:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  7dd039:	8b f7                	mov    esi,edi
  7dd03b:	8b 43 50             	mov    eax,DWORD PTR [ebx+0x50]
  7dd03e:	2b 43 4c             	sub    eax,DWORD PTR [ebx+0x4c]
  7dd041:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  7dd044:	c1 f8 02             	sar    eax,0x2
  7dd047:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  7dd04a:	3b c7                	cmp    eax,edi
  7dd04c:	0f 86 92 00 00 00    	jbe    0x7dd0e4
  7dd052:	eb 02                	jmp    0x7dd056
  7dd054:	33 ff                	xor    edi,edi
  7dd056:	6a 0c                	push   0xc
  7dd058:	e8 0b 42 0b 00       	call   0x891268
  7dd05d:	83 c4 04             	add    esp,0x4
  7dd060:	3b c7                	cmp    eax,edi
  7dd062:	74 0b                	je     0x7dd06f
  7dd064:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7dd067:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  7dd06a:	c6 00 00             	mov    BYTE PTR [eax],0x0
  7dd06d:	8b f8                	mov    edi,eax
  7dd06f:	8b 4b 4c             	mov    ecx,DWORD PTR [ebx+0x4c]
  7dd072:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7dd075:	8b 04 91             	mov    eax,DWORD PTR [ecx+edx*4]
  7dd078:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7dd07b:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7dd07e:	8d 4d 08             	lea    ecx,[ebp+0x8]
  7dd081:	89 7d 08             	mov    DWORD PTR [ebp+0x8],edi
  7dd084:	3b c8                	cmp    ecx,eax
  7dd086:	73 2f                	jae    0x7dd0b7
  7dd088:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  7dd08b:	8d 55 08             	lea    edx,[ebp+0x8]
  7dd08e:	3b ca                	cmp    ecx,edx
  7dd090:	77 25                	ja     0x7dd0b7
  7dd092:	8b fa                	mov    edi,edx
  7dd094:	2b f9                	sub    edi,ecx
  7dd096:	c1 ff 02             	sar    edi,0x2
  7dd099:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  7dd09c:	75 08                	jne    0x7dd0a6
  7dd09e:	8d 46 04             	lea    eax,[esi+0x4]
  7dd0a1:	e8 8a a8 fb ff       	call   0x797930
  7dd0a6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7dd0a9:	85 c0                	test   eax,eax
  7dd0ab:	74 20                	je     0x7dd0cd
  7dd0ad:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  7dd0b0:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  7dd0b3:	89 10                	mov    DWORD PTR [eax],edx
  7dd0b5:	eb 16                	jmp    0x7dd0cd
  7dd0b7:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  7dd0ba:	75 08                	jne    0x7dd0c4
  7dd0bc:	8d 46 04             	lea    eax,[esi+0x4]
  7dd0bf:	e8 6c a8 fb ff       	call   0x797930
  7dd0c4:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7dd0c7:	85 c0                	test   eax,eax
  7dd0c9:	74 02                	je     0x7dd0cd
  7dd0cb:	89 38                	mov    DWORD PTR [eax],edi
  7dd0cd:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
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
  7dd0fe:	cc                   	int3
  7dd0ff:	cc                   	int3
```

### `0x007BE5F0` ～ `0x007BE675`

```asm
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be652:	c3                   	ret
  7be653:	cc                   	int3
  7be654:	cc                   	int3
  7be655:	cc                   	int3
  7be656:	cc                   	int3
  7be657:	cc                   	int3
  7be658:	cc                   	int3
  7be659:	cc                   	int3
  7be65a:	cc                   	int3
  7be65b:	cc                   	int3
  7be65c:	cc                   	int3
  7be65d:	cc                   	int3
  7be65e:	cc                   	int3
  7be65f:	cc                   	int3
  7be660:	b8 15 00 00 00       	mov    eax,0x15
  7be665:	c3                   	ret
  7be666:	cc                   	int3
  7be667:	cc                   	int3
  7be668:	cc                   	int3
  7be669:	cc                   	int3
  7be66a:	cc                   	int3
  7be66b:	cc                   	int3
  7be66c:	cc                   	int3
  7be66d:	cc                   	int3
  7be66e:	cc                   	int3
  7be66f:	cc                   	int3
  7be670:	55                   	push   ebp
  7be671:	8b ec                	mov    ebp,esp
  7be673:	56                   	push   esi
  7be674:	8b                 	mov    esi,ecx
```

### `0x007DD1A0` ～ `0x007DD1EB`

```asm
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
  7dd1b5:	56                   	push   esi
  7dd1b6:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd1bc:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7dd1bf:	8d 45 0c             	lea    eax,[ebp+0xc]
  7dd1c2:	e8 89 e1 fd ff       	call   0x7bb350
  7dd1c7:	56                   	push   esi
  7dd1c8:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd1ce:	5e                   	pop    esi
  7dd1cf:	5f                   	pop    edi
  7dd1d0:	5b                   	pop    ebx
  7dd1d1:	5d                   	pop    ebp
  7dd1d2:	c2 08 00             	ret    0x8
  7dd1d5:	85 ff                	test   edi,edi
  7dd1d7:	74 0e                	je     0x7dd1e7
  7dd1d9:	e8 72 06 fe ff       	call   0x7bd850
  7dd1de:	57                   	push   edi
  7dd1df:	e8 28 40 0b 00       	call   0x89120c
  7dd1e4:	83 c4 04             	add    esp,0x4
  7dd1e7:	5f                   	pop    edi
  7dd1e8:	5b                   	pop    ebx
  7dd1e9:	5d                   	pop    ebp
  7dd1ea:	c2               	ret    0x8
```