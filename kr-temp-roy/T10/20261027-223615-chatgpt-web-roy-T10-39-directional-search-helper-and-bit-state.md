# T10-39 — 方向探索 helper、256 候選迭代與狀態位的誤判排除（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 深度分析
1. 【確認】`0x545F30` 先檢查全域 `0xFAB1D0`；空指標直接往 `0x5460E4` 返回分支。這是 helper 的資源前提，非技能可用性矩陣。
2. 【確認】`0x545FF3` 取得 byte 參數 `edi`，以 `edi*8` 索引 `0xFB8020`、`0xFB8024` 的兩個 float，再與第二參數浮點運算，組成二維座標；`0x546050` 對全域資料 `0xFAB1D0` 呼叫 `0x82CDF0`。即此 helper 實際處理方向樣本和空間位置比較，而不是單純鍵值判斷。
3. 【確認】`0x5464C0` 首先將輸入的 byte 寫出到指標 `[ebp+0x14]`，再依 `[ebp+0x8]` 是否非零在 `0x5464D7` 分支。這個 BYTE 也是方向候選值，不能因其為輸入索引就當 skill matrix key。
4. 【確認】`0x546595` 呼叫 `0x545F30`；返回非零時轉入不同修正路徑。另一條 `0x546700` 起使用 `ebx` 作循環計數，每輪查一次 `0x545F30`，直到結果為零或 `ebx==0x100`。最大 256 是方向/量化索引搜尋上限，**不是 V 蓄氣時間、連段數或按鍵重試次數**。
5. 【確認】`0x54672C` 路徑將 BYTE `bl` 減 `0x80` 並試查一次方向，返回含成功/失敗狀態。因此 `0x5464C0` 有多種方向解析策略，不能將它等同一般連招選擇。
6. 【確認】`0x4C90C0` 僅在傳入參數非零且 actor `+0x3A8` 先前為零時設定 `+0x3A8`；參數為零時清除。若 actor `+0x370`、`+0x15C` 非零，還會走從屬虛擬回呼；此函式管理的是另一個明確旗標，不是 `+0x3E8` setter。
## 偽碼（只表示已確認的條件，不補猜角度規則）
```cpp
bool sample_direction(point_ctx, unsigned char direction, float distance) {
  if (!global_FAB1D0) return /* limited path */;
  float dx=table_FB8020[direction*2] * distance;
  float dy=table_FB8024[direction*2] * distance;
  // form candidate position and query 0x82CDF0
}
int adjust_direction(..., unsigned char dir, uint8_t *out) {
  *out=dir;
  if (mode==0) { /* multi-branch sampling */ }
  else { /* subtract 0x80 and probe */ }
  // fallback may try up to 0x100 samples
}
void set_actor_3A8(actor*a, bool enable) {
  if (enable && !a->field_3A8) { /* optional 15C callback */ a->field_3A8=enable; }
  else if (!enable && a->field_3A8) a->field_3A8=0;
}
```
## 重要限制
- 現在有更強反證：`0x5464C0` 以及 `0x545F30` 方向取樣循環 **不宜作為普攻→技能 cancel 或 V charge level 證據**。這是從局部機器碼而非功能名稱得出的否定性成果。
- 需另外定位真正矩陣 4-tier writer、鍵映射非零 writer 與動作動畫 callback。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x545f88–0x54607f
```asm
00545f88 <.text+0x144f88>:
  545f88:	8b 0d d0 b1 fa 00    	mov    ecx,DWORD PTR ds:0xfab1d0
  545f8e:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  545f92:	85 c9                	test   ecx,ecx
  545f94:	0f 84 4a 01 00 00    	je     0x5460e4
  545f9a:	f3 0f 10 45 0c       	movss  xmm0,DWORD PTR [ebp+0xc]
  545f9f:	0f 2e 05 6c 56 c5 00 	ucomiss xmm0,DWORD PTR ds:0xc5566c
  545fa6:	9f                   	lahf
  545fa7:	f6 c4 44             	test   ah,0x44
  545faa:	7a 21                	jp     0x545fcd
  545fac:	8b c6                	mov    eax,esi
  545fae:	e8 3d 6e 2e 00       	call   0x82cdf0
  545fb3:	f7 d8                	neg    eax
  545fb5:	1b c0                	sbb    eax,eax
  545fb7:	40                   	inc    eax
  545fb8:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  545fbc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  545fc3:	59                   	pop    ecx
  545fc4:	5f                   	pop    edi
  545fc5:	5e                   	pop    esi
  545fc6:	5b                   	pop    ebx
  545fc7:	8b e5                	mov    esp,ebp
  545fc9:	5d                   	pop    ebp
  545fca:	c2 08 00             	ret    0x8
  545fcd:	8b 1d 18 7c fb 00    	mov    ebx,DWORD PTR ds:0xfb7c18
  545fd3:	8b 06                	mov    eax,DWORD PTR [esi]
  545fd5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  545fd8:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  545fdc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  545fe0:	f6 c3 01             	test   bl,0x1
  545fe3:	75 0e                	jne    0x545ff3
  545fe5:	83 cb 01             	or     ebx,0x1
  545fe8:	89 1d 18 7c fb 00    	mov    DWORD PTR ds:0xfb7c18,ebx
  545fee:	e8 dd e9 ef ff       	call   0x4449d0
  545ff3:	0f b6 7d 08          	movzx  edi,BYTE PTR [ebp+0x8]
  545ff7:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  545ffa:	d9 c0                	fld    st(0)
  545ffc:	33 f6                	xor    esi,esi
  545ffe:	d8 0c fd 20 80 fb 00 	fmul   DWORD PTR [edi*8+0xfb8020]
  546005:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  546009:	d8 0c fd 24 80 fb 00 	fmul   DWORD PTR [edi*8+0xfb8024]
  546010:	d9 5c 24 20          	fstp   DWORD PTR [esp+0x20]
  546014:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  546018:	dd 05 28 57 c5 00    	fld    QWORD PTR ds:0xc55728
  54601e:	dc c9                	fmul   st(1),st
  546020:	d9 c9                	fxch   st(1)
  546022:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  546026:	d8 4c 24 20          	fmul   DWORD PTR [esp+0x20]
  54602a:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  54602e:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  546032:	d8 44 24 14          	fadd   DWORD PTR [esp+0x14]
  546036:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  54603a:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  54603e:	d8 44 24 28          	fadd   DWORD PTR [esp+0x28]
  546042:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  546046:	eb 08                	jmp    0x546050
  546048:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  54604f:	90                   	nop
  546050:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  546054:	8d 44 24 14          	lea    eax,[esp+0x14]
  546058:	e8 93 6d 2e 00       	call   0x82cdf0
  54605d:	85 c0                	test   eax,eax
  54605f:	74 7d                	je     0x5460de
  546061:	f6 c3 01             	test   bl,0x1
  546064:	75 08                	jne    0x54606e
  546066:	83 cb 01             	or     ebx,0x1
  546069:	e8 62 e9 ef ff       	call   0x4449d0
  54606e:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  546071:	46                   	inc    esi
  546072:	d9 c0                	fld    st(0)
  546074:	d8 0c fd 20 80 fb 00 	fmul   DWORD PTR [edi*8+0xfb8020]
  54607b:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
```

### VA 0x5464c0–0x5465a0
```asm
005464c0 <.text+0x1454c0>:
  5464c0:	55                   	push   ebp
  5464c1:	8b ec                	mov    ebp,esp
  5464c3:	83 e4 f8             	and    esp,0xfffffff8
  5464c6:	83 ec 18             	sub    esp,0x18
  5464c9:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  5464cd:	53                   	push   ebx
  5464ce:	8a 5d 10             	mov    bl,BYTE PTR [ebp+0x10]
  5464d1:	57                   	push   edi
  5464d2:	8b 7d 14             	mov    edi,DWORD PTR [ebp+0x14]
  5464d5:	88 1f                	mov    BYTE PTR [edi],bl
  5464d7:	0f 85 4f 02 00 00    	jne    0x54672c
  5464dd:	f6 05 18 7c fb 00 01 	test   BYTE PTR ds:0xfb7c18,0x1
  5464e4:	75 0c                	jne    0x5464f2
  5464e6:	83 0d 18 7c fb 00 01 	or     DWORD PTR ds:0xfb7c18,0x1
  5464ed:	e8 de e4 ef ff       	call   0x4449d0
  5464f2:	0f 57 c0             	xorps  xmm0,xmm0
  5464f5:	d9 ee                	fldz
  5464f7:	0f b6 c3             	movzx  eax,bl
  5464fa:	8b 0c c5 20 80 fb 00 	mov    ecx,DWORD PTR [eax*8+0xfb8020]
  546501:	8b 14 c5 24 80 fb 00 	mov    edx,DWORD PTR [eax*8+0xfb8024]
  546508:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  54650c:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  546510:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546514:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  54651a:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  546520:	e8 a5 88 3b 00       	call   0x8fedca
  546525:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  546529:	f6 05 18 7c fb 00 01 	test   BYTE PTR ds:0xfb7c18,0x1
  546530:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  546534:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  54653a:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  54653e:	75 0c                	jne    0x54654c
  546540:	83 0d 18 7c fb 00 01 	or     DWORD PTR ds:0xfb7c18,0x1
  546547:	e8 84 e4 ef ff       	call   0x4449d0
  54654c:	d9 05 24 88 fb 00    	fld    DWORD PTR ds:0xfb8824
  546552:	51                   	push   ecx
  546553:	d8 4c 24 10          	fmul   DWORD PTR [esp+0x10]
  546557:	d9 7c 24 0c          	fnstcw WORD PTR [esp+0xc]
  54655b:	0f b7 44 24 0c       	movzx  eax,WORD PTR [esp+0xc]
  546560:	0d 00 0c 00 00       	or     eax,0xc00
  546565:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  546569:	d9 6c 24 10          	fldcw  WORD PTR [esp+0x10]
  54656d:	db 5c 24 10          	fistp  DWORD PTR [esp+0x10]
  546571:	8a 44 24 10          	mov    al,BYTE PTR [esp+0x10]
  546575:	d9 6c 24 0c          	fldcw  WORD PTR [esp+0xc]
  546579:	88 44 24 0c          	mov    BYTE PTR [esp+0xc],al
  54657d:	8b 4c 24 0c          	mov    ecx,DWORD PTR [esp+0xc]
  546581:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  546584:	dc 0d 70 5a c5 00    	fmul   QWORD PTR ds:0xc55a70
  54658a:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  54658e:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546592:	d9 1c 24             	fstp   DWORD PTR [esp]
  546595:	51                   	push   ecx
  546596:	8b ce                	mov    ecx,esi
  546598:	e8 93 f9 ff ff       	call   0x545f30
  54659d:	85 c0                	test   eax,eax
  54659f:	74                   	.byte 0x74
```

### VA 0x5466f8–0x546774
```asm
005466f8 <.text+0x1456f8>:
  5466f8:	33 db                	xor    ebx,ebx
  5466fa:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  546700:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  546704:	51                   	push   ecx
  546705:	d9 1c 24             	fstp   DWORD PTR [esp]
  546708:	53                   	push   ebx
  546709:	8b ce                	mov    ecx,esi
  54670b:	e8 20 f8 ff ff       	call   0x545f30
  546710:	85 c0                	test   eax,eax
  546712:	74 d5                	je     0x5466e9
  546714:	43                   	inc    ebx
  546715:	81 fb 00 01 00 00    	cmp    ebx,0x100
  54671b:	7c e3                	jl     0x546700
  54671d:	8a 4d 10             	mov    cl,BYTE PTR [ebp+0x10]
  546720:	33 c0                	xor    eax,eax
  546722:	88 0f                	mov    BYTE PTR [edi],cl
  546724:	5f                   	pop    edi
  546725:	5b                   	pop    ebx
  546726:	8b e5                	mov    esp,ebp
  546728:	5d                   	pop    ebp
  546729:	c2 10 00             	ret    0x10
  54672c:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  54672f:	80 eb 80             	sub    bl,0x80
  546732:	dc 0d 70 5a c5 00    	fmul   QWORD PTR ds:0xc55a70
  546738:	51                   	push   ecx
  546739:	88 5c 24 10          	mov    BYTE PTR [esp+0x10],bl
  54673d:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  546741:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  546745:	8b ce                	mov    ecx,esi
  546747:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  54674b:	33 ff                	xor    edi,edi
  54674d:	d9 1c 24             	fstp   DWORD PTR [esp]
  546750:	52                   	push   edx
  546751:	e8 da f7 ff ff       	call   0x545f30
  546756:	85 c0                	test   eax,eax
  546758:	75 10                	jne    0x54676a
  54675a:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  54675d:	88 19                	mov    BYTE PTR [ecx],bl
  54675f:	8d 47 01             	lea    eax,[edi+0x1]
  546762:	5f                   	pop    edi
  546763:	5b                   	pop    ebx
  546764:	8b e5                	mov    esp,ebp
  546766:	5d                   	pop    ebp
  546767:	c2 10 00             	ret    0x10
  54676a:	8b c7                	mov    eax,edi
  54676c:	5f                   	pop    edi
  54676d:	5b                   	pop    ebx
  54676e:	8b e5                	mov    esp,ebp
  546770:	5d                   	pop    ebp
  546771:	c2 10 00             	ret    0x10
```

### VA 0x4c90c0–0x4c913a
```asm
004c90c0 <.text+0xc80c0>:
  4c90c0:	55                   	push   ebp
  4c90c1:	8b ec                	mov    ebp,esp
  4c90c3:	51                   	push   ecx
  4c90c4:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  4c90c8:	53                   	push   ebx
  4c90c9:	57                   	push   edi
  4c90ca:	74 55                	je     0x4c9121
  4c90cc:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c90d3:	75 5f                	jne    0x4c9134
  4c90d5:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c90dc:	8a 86 b0 00 00 00    	mov    al,BYTE PTR [esi+0xb0]
  4c90e2:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  4c90e5:	88 86 a4 03 00 00    	mov    BYTE PTR [esi+0x3a4],al
  4c90eb:	74 23                	je     0x4c9110
  4c90ed:	8b 9e 5c 01 00 00    	mov    ebx,DWORD PTR [esi+0x15c]
  4c90f3:	85 db                	test   ebx,ebx
  4c90f5:	74 19                	je     0x4c9110
  4c90f7:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4c90fa:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  4c90fd:	50                   	push   eax
  4c90fe:	e8 8d b9 f7 ff       	call   0x444a90
  4c9103:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  4c9106:	8d 4b 04             	lea    ecx,[ebx+0x4]
  4c9109:	f3 0f 11 04 24       	movss  DWORD PTR [esp],xmm0
  4c910e:	ff d2                	call   edx
  4c9110:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c9113:	89 86 a8 03 00 00    	mov    DWORD PTR [esi+0x3a8],eax
  4c9119:	5f                   	pop    edi
  4c911a:	5b                   	pop    ebx
  4c911b:	8b e5                	mov    esp,ebp
  4c911d:	5d                   	pop    ebp
  4c911e:	c2 04 00             	ret    0x4
  4c9121:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c9128:	74 0a                	je     0x4c9134
  4c912a:	c7 86 a8 03 00 00 00 	mov    DWORD PTR [esi+0x3a8],0x0
  4c9131:	00 00 00 
  4c9134:	5f                   	pop    edi
  4c9135:	5b                   	pop    ebx
  4c9136:	8b e5                	mov    esp,ebp
  4c9138:	5d                   	pop    ebp
  4c9139:	c2                   	.byte 0xc2
```