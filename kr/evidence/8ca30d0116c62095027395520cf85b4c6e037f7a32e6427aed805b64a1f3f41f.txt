# T10-31 — 0x549C60 技能候選 7/9 的參數傳遞、actor fallback 與矩陣界線

## 本段動機
T10-30 見 1/2 actor 狀態選擇 7/9 呼叫 0x549C60。需要驗證 7/9 經何處處理，避免直接命名 V 技能 tier 或冷卻結束。

## 第一手發現
- `0x549C60` 透過 `0x54AA60` 對最初兩個參數作候選設定，`0x548D20` 對 `[ebp+0x14]` 作額外數值轉換；此處回傳值 EAX 低16位保存在 EDI（`movzx edi,ax`）。
- 模型資料來源是 `this+0x50` 的 actor +0x88 WORD，拒絕 model >9；使用 hero record stride 0x210，必須滿足 hero record +0x5C 非零；接著對 +0x1F4 指向的資料記錄讀 byte。這與 T10-29 controller 的 skill tier 資料存取**形狀一致**，但不證明是相同 actor 物件實例或同一個 action。
- `0x549D29` 先比較 arg+0x10 是否為 `-1`，是就以 actor+0x3E8 覆蓋這個參數；因此 **-1 是一個回退到 actor state 的候選 sentinel**，至少在此函式確定。這為 T10-30 的 7/9 呼叫澄清：其 `-1` 參數會促使 state fallback，7/9 則是另外的參數，不能當作 tier。
- `0x549D54` 接 `0x54F270` availability predicate，成功後將輸出 mask 低15位更新，寫 [0m`[this + 0xAC + slot*16] = 4`，並用目標座標差計算角度寫 `this+0x74`。**這是 SubAI 的候選及方向更新，不是施放完成或資源消耗**。

## 逐址原始組語

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x00549C60–0x00549D29
```asm
00549c60 <.text+0x148c60>:
  549c60:	55                   	push   ebp
  549c61:	8b ec                	mov    ebp,esp
  549c63:	83 e4 f8             	and    esp,0xfffffff8
  549c66:	6a ff                	push   0xffffffff
  549c68:	68 de ed 93 00       	push   0x93edde
  549c6d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  549c73:	50                   	push   eax
  549c74:	83 ec 14             	sub    esp,0x14
  549c77:	53                   	push   ebx
  549c78:	57                   	push   edi
  549c79:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  549c7e:	33 c4                	xor    eax,esp
  549c80:	50                   	push   eax
  549c81:	8d 44 24 20          	lea    eax,[esp+0x20]
  549c85:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  549c8b:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  549c8e:	50                   	push   eax
  549c8f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  549c92:	8b ce                	mov    ecx,esi
  549c94:	e8 c7 0d 00 00       	call   0x54aa60
  549c99:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  549c9c:	33 d2                	xor    edx,edx
  549c9e:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  549ca2:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  549ca6:	e8 75 f0 ff ff       	call   0x548d20
  549cab:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  549cb2:	0f b7 f8             	movzx  edi,ax
  549cb5:	8b 46 60             	mov    eax,DWORD PTR [esi+0x60]
  549cb8:	8d 0c 40             	lea    ecx,[eax+eax*2]
  549cbb:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  549cc0:	8b 5c 88 10          	mov    ebx,DWORD PTR [eax+ecx*4+0x10]
  549cc4:	75 25                	jne    0x549ceb
  549cc6:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  549ccd:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  549cd1:	e8 ba 78 f9 ff       	call   0x4e1590
  549cd6:	68 80 cc bc 00       	push   0xbccc80
  549cdb:	e8 3a 86 34 00       	call   0x89231a
  549ce0:	83 c4 04             	add    esp,0x4
  549ce3:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  549cea:	ff 
  549ceb:	8b 56 50             	mov    edx,DWORD PTR [esi+0x50]
  549cee:	0f b7 82 88 00 00 00 	movzx  eax,WORD PTR [edx+0x88]
  549cf5:	8b 0d 04 43 f9 00    	mov    ecx,DWORD PTR ds:0xf94304
  549cfb:	83 f8 09             	cmp    eax,0x9
  549cfe:	0f 87 ef 00 00 00    	ja     0x549df3
  549d04:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  549d0a:	03 c1                	add    eax,ecx
  549d0c:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  549d10:	0f 84 dd 00 00 00    	je     0x549df3
  549d16:	85 c0                	test   eax,eax
  549d18:	0f 84 d5 00 00 00    	je     0x549df3
  549d1e:	05 f4 01 00 00       	add    eax,0x1f4
  549d23:	0f 84 ca 00 00 00    	je     0x549df3
```

### VA 0x00549D29–0x00549E05
```asm
00549d29 <.text+0x148d29>:
  549d29:	83 7d 10 ff          	cmp    DWORD PTR [ebp+0x10],0xffffffff
  549d2d:	75 09                	jne    0x549d38
  549d2f:	8b 8a e8 03 00 00    	mov    ecx,DWORD PTR [edx+0x3e8]
  549d35:	89 4d 10             	mov    DWORD PTR [ebp+0x10],ecx
  549d38:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  549d3b:	33 d2                	xor    edx,edx
  549d3d:	38 50 02             	cmp    BYTE PTR [eax+0x2],dl
  549d40:	51                   	push   ecx
  549d41:	0f 95 c2             	setne  dl
  549d44:	8b cb                	mov    ecx,ebx
  549d46:	8a 04 02             	mov    al,BYTE PTR [edx+eax*1]
  549d49:	88 44 24 14          	mov    BYTE PTR [esp+0x14],al
  549d4d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  549d51:	52                   	push   edx
  549d52:	8b c7                	mov    eax,edi
  549d54:	e8 17 55 00 00       	call   0x54f270
  549d59:	85 c0                	test   eax,eax
  549d5b:	74 2d                	je     0x549d8a
  549d5d:	66 8b 46 72          	mov    ax,WORD PTR [esi+0x72]
  549d61:	8b 96 08 01 00 00    	mov    edx,DWORD PTR [esi+0x108]
  549d67:	66 33 c7             	xor    ax,di
  549d6a:	b9 ff 7f 00 00       	mov    ecx,0x7fff
  549d6f:	66 23 c1             	and    ax,cx
  549d72:	66 31 46 72          	xor    WORD PTR [esi+0x72],ax
  549d76:	03 d2                	add    edx,edx
  549d78:	b8 01 00 00 00       	mov    eax,0x1
  549d7d:	c7 84 d6 ac 00 00 00 	mov    DWORD PTR [esi+edx*8+0xac],0x4
  549d84:	04 00 00 00 
  549d88:	eb 04                	jmp    0x549d8e
  549d8a:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  549d8e:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  549d92:	85 c9                	test   ecx,ecx
  549d94:	74 5d                	je     0x549df3
  549d96:	85 c0                	test   eax,eax
  549d98:	74 59                	je     0x549df3
  549d9a:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  549d9d:	d9 81 a4 00 00 00    	fld    DWORD PTR [ecx+0xa4]
  549da3:	d8 a0 a4 00 00 00    	fsub   DWORD PTR [eax+0xa4]
  549da9:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  549dad:	d9 81 a0 00 00 00    	fld    DWORD PTR [ecx+0xa0]
  549db3:	d8 a0 a0 00 00 00    	fsub   DWORD PTR [eax+0xa0]
  549db9:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  549dbd:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  549dc1:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  549dc5:	e8 00 50 3b 00       	call   0x8fedca
  549dca:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  549dce:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  549dd2:	51                   	push   ecx
  549dd3:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  549dd9:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  549ddd:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  549de1:	d9 1c 24             	fstp   DWORD PTR [esp]
  549de4:	e8 67 16 f7 ff       	call   0x4bb450
  549de9:	83 c4 04             	add    esp,0x4
  549dec:	88 46 74             	mov    BYTE PTR [esi+0x74],al
  549def:	c6 46 4c 00          	mov    BYTE PTR [esi+0x4c],0x0
  549df3:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  549df7:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  549dfe:	59                   	pop    ecx
  549dff:	5f                   	pop    edi
  549e00:	5b                   	pop    ebx
  549e01:	8b e5                	mov    esp,ebp
  549e03:	5d                   	pop    ebp
  549e04:	c2                   	.byte 0xc2
```

### VA 0x0054F270–0x0054F330
```asm
0054f270 <.text+0x14e270>:
  54f270:	55                   	push   ebp
  54f271:	8b ec                	mov    ebp,esp
  54f273:	53                   	push   ebx
  54f274:	56                   	push   esi
  54f275:	8b f1                	mov    esi,ecx
  54f277:	a8 c0                	test   al,0xc0
  54f279:	0f 85 a6 00 00 00    	jne    0x54f325
  54f27f:	8b c8                	mov    ecx,eax
  54f281:	83 e1 01             	and    ecx,0x1
  54f284:	74 08                	je     0x54f28e
  54f286:	a8 02                	test   al,0x2
  54f288:	74 04                	je     0x54f28e
  54f28a:	b3 04                	mov    bl,0x4
  54f28c:	eb 44                	jmp    0x54f2d2
  54f28e:	66 85 c9             	test   cx,cx
  54f291:	74 08                	je     0x54f29b
  54f293:	a8 04                	test   al,0x4
  54f295:	74 04                	je     0x54f29b
  54f297:	b3 05                	mov    bl,0x5
  54f299:	eb 37                	jmp    0x54f2d2
  54f29b:	8b d0                	mov    edx,eax
  54f29d:	83 e2 02             	and    edx,0x2
  54f2a0:	74 08                	je     0x54f2aa
  54f2a2:	a8 04                	test   al,0x4
  54f2a4:	74 04                	je     0x54f2aa
  54f2a6:	b3 06                	mov    bl,0x6
  54f2a8:	eb 28                	jmp    0x54f2d2
  54f2aa:	66 85 c9             	test   cx,cx
  54f2ad:	74 04                	je     0x54f2b3
  54f2af:	b3 01                	mov    bl,0x1
  54f2b1:	eb 1f                	jmp    0x54f2d2
  54f2b3:	66 85 d2             	test   dx,dx
  54f2b6:	74 04                	je     0x54f2bc
  54f2b8:	b3 02                	mov    bl,0x2
  54f2ba:	eb 16                	jmp    0x54f2d2
  54f2bc:	a8 04                	test   al,0x4
  54f2be:	74 04                	je     0x54f2c4
  54f2c0:	b3 03                	mov    bl,0x3
  54f2c2:	eb 0e                	jmp    0x54f2d2
  54f2c4:	a8 08                	test   al,0x8
  54f2c6:	74 04                	je     0x54f2cc
  54f2c8:	b3 07                	mov    bl,0x7
  54f2ca:	eb 06                	jmp    0x54f2d2
  54f2cc:	a8 10                	test   al,0x10
  54f2ce:	74 55                	je     0x54f325
  54f2d0:	b3 0a                	mov    bl,0xa
  54f2d2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54f2d5:	0f b7 4e 02          	movzx  ecx,WORD PTR [esi+0x2]
  54f2d9:	50                   	push   eax
  54f2da:	51                   	push   ecx
  54f2db:	e8 10 05 ec ff       	call   0x40f7f0
  54f2e0:	e8 3b 9f 2c 00       	call   0x819220
  54f2e5:	85 c0                	test   eax,eax
  54f2e7:	75 08                	jne    0x54f2f1
  54f2e9:	33 c0                	xor    eax,eax
  54f2eb:	5e                   	pop    esi
  54f2ec:	5b                   	pop    ebx
  54f2ed:	5d                   	pop    ebp
  54f2ee:	c2 08 00             	ret    0x8
  54f2f1:	50                   	push   eax
  54f2f2:	8a 45 0c             	mov    al,BYTE PTR [ebp+0xc]
  54f2f5:	8a cb                	mov    cl,bl
  54f2f7:	e8 e4 b5 2c 00       	call   0x81a8e0
  54f2fc:	0f b7 c0             	movzx  eax,ax
  54f2ff:	66 85 c0             	test   ax,ax
  54f302:	74 e5                	je     0x54f2e9
  54f304:	8b d0                	mov    edx,eax
  54f306:	83 c6 04             	add    esi,0x4
  54f309:	56                   	push   esi
  54f30a:	8d 45 08             	lea    eax,[ebp+0x8]
  54f30d:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  54f310:	e8 cb 01 00 00       	call   0x54f4e0
  54f315:	33 c9                	xor    ecx,ecx
  54f317:	39 48 04             	cmp    DWORD PTR [eax+0x4],ecx
  54f31a:	0f 94 c1             	sete   cl
  54f31d:	8b c1                	mov    eax,ecx
  54f31f:	5e                   	pop    esi
  54f320:	5b                   	pop    ebx
  54f321:	5d                   	pop    ebp
  54f322:	c2 08 00             	ret    0x8
  54f325:	5e                   	pop    esi
  54f326:	b8 01 00 00 00       	mov    eax,0x1
  54f32b:	5b                   	pop    ebx
  54f32c:	5d                   	pop    ebp
  54f32d:	c2 08 00             	ret    0x8
```

### VA 0x0081A8E0–0x0081A909
```asm
0081a8e0 <.text+0x4198e0>:
  81a8e0:	55                   	push   ebp
  81a8e1:	8b ec                	mov    ebp,esp
  81a8e3:	3c 04                	cmp    al,0x4
  81a8e5:	73 1c                	jae    0x81a903
  81a8e7:	80 f9 0b             	cmp    cl,0xb
  81a8ea:	73 17                	jae    0x81a903
  81a8ec:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  81a8ef:	0f b6 c0             	movzx  eax,al
  81a8f2:	6b c0 0b             	imul   eax,eax,0xb
  81a8f5:	0f b6 c9             	movzx  ecx,cl
  81a8f8:	03 c1                	add    eax,ecx
  81a8fa:	66 8b 44 42 04       	mov    ax,WORD PTR [edx+eax*2+0x4]
  81a8ff:	5d                   	pop    ebp
  81a900:	c2 04 00             	ret    0x4
  81a903:	33 c0                	xor    eax,eax
  81a905:	5d                   	pop    ebp
  81a906:	c2 04 00             	ret    0x4
```

## 矩陣與組合交叉確認
`0x54F270` 將 bit0/1/2 的單項和兩項組合映射至 key 1..6，另 bit3->key7、bit4->key10；`0x81A8E0` 適用 tier [0,3]、key [0,10]。這能容納使用者所述 Z/X/C 單鍵與組合，但 **7/9 在 SubAI `0x549C60` 入口是參數，不可直接等於「matrix key7/key9」**；必須沿 `0x548D20` 的轉換和 `0x54AA60` 後才能證實。

## 偽碼與未解
```cpp
uint32_t selectedTier = (argTier == -1) ? actor->field3E8 : argTier;
if (model<=9 && heroTable[model].valid) {
   uint8_t sample = choose(heroRecordAt1F4);
   if (skillAvailable(candidateFlags, sample, selectedTier, skillContext)) {
      stateSlot4 = 4;
      updateSelectedMaskAndHeading();
   }
}
```
未解：`0x548D20` 使 7/9 變成何種 flags、`0x54AA60` 是否改寫候選集、actor+0x3E8 真正 writer。以上仍不能回答 V 點按/長按或普攻接技能之動畫合法窗口。
