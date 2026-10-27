# KR T10/T11 交界研究 — T10-22 T11 技能矩陣與剩餘計時 gate

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 核心結論
`0x54F270..0x54F32F` 為有界獨立函式；直接檢查 input flag byte：若含 `0xC0`，跳過矩陣檢查直接回傳 1。其他位元組先映射 key（單鍵 1/2/3、組合鍵 4/5/6、bit8 -> 7、bit16 -> 10），接著從 `[esi+2]` 讀 model WORD 與 caller 提供的第二索引查矩陣。`0x819220` 回傳非零才可呼叫 `0x81A8E0`，取得矩陣 WORD skill ID。查到 ID 後進入 `0x54F4E0` 的樹，檢測記錄 `+4` DWORD 是否為零：相等則回 1。這是 *predicate*，不是冷卻啟動器。

與 T10-1/T10-4 既有查詢結論交叉核對：`0x54F4E0` 找不到 key 時可能新增節點，因此即使 `0x54F270` 在語意上是 availability check，也**不等於所有記憶體寫入皆無副作用**。但新增節點本身不足以證實冷卻開始。

## T11 候選標記
- `0x54F270`：**T11 可用性 / 檢查**，已直接確立用在 T10 控制器。
- `0x819220` + `0x81A8E0`：矩陣解析 / key lookup，**不是 T11 施放裁決本身**。
- `0x54F4E0`：含容器插入的 cooldown 記錄查找，需追實際 timer writer。

## 偽碼
```cpp
bool availability(ctx, byte flags, tier, secondary) {
 if (flags & 0xC0) return true; // 特例
 unsigned key = classify(flags); // 1..7,10 / fallback
 if (!key) return true;
 Matrix* m = matrixLookup(ctx->modelWord2, secondary);
 if (!m) return false;
 int id = matrixKey(m,tier,key);
 if (!id) return false;
 Node* node = cooldownMapLookupOrInsert(ctx+4,id);
 return node->remainingWord4 == 0;
}
```
**不保證完全複製參數順序**；`0x54F4E0` 可能修改樹結構。

## 下一段
與其他 `0x54F270` 呼叫者比對，分別判定 actor 控制器與 SubAI 決策何處交錯。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 0054F270..0054F330
```asm
0054f270 <.data+0x14e670>:
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