# KR T10-27 — 三按鍵組合旗標、四層技能矩陣與 V 蓄氣假說邊界

原始資料：`/mnt/data/Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）。研究日期：2026-10-27（Asia/Taipei）。

**方法**：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`，先核實完整函式的入口和跳轉邊界；未執行、注入或改寫客戶端。組語是 BIN 第一手證據；T10-24 與 GitHub T11 既有審核作交叉參考，不替代機器碼。未命名函式、物件欄位的語義均為候選。

**使用者補充（研究需求，非由 BIN 證明）**：按鍵可自訂；六種輸入 Z、X、C、Z+X、Z+C、X+C；V 點按／長按影響技能且包含 Z；普攻／技能有交互接續。研究不能將字母按鍵硬對映到 mask。

## 研究目標與本次範圍

專門驗證 `0x54F270` 的 flags→key 條件先後和 `0x81A8E0` 的 tier/key 索引，將使用者提到的六組 Z/X/C 與 V 變化轉成可驗證的候選矩陣模型，並明確指出目前無法證實的實際映射。

## 第一手組語摘錄

```asm
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

## 逐層分析與新結論

**控制流程與優先序（直接指令）**：`0x54F277 test al,0xC0` 有任一高位就走 `0x54F325 return 1`；否則從低位依 `bit0&bit1→key4`、`bit0&bit2→key5`、`bit1&bit2→key6` 的優先順序檢查。若沒有兩位組合，檢查 bit0→key1、bit1→key2、bit2→key3，再查 bit3→key7、bit4→key10。不匹配亦走 return1。**此分類的 bit 是內部技能旗標，不是鍵盤 Z/X/C 的物理掃描碼**，要連到可自訂 KeyMapping 才能命名。

**關鍵陷阱：** 若三個低位同時為 1，函式首先命中 bit0+bit1（key4），不會「自動」出現第七種三鍵技能。若混合低位及 bit3/bit4，會先命中低位。在沒有更上游 normalizer 的證據前，只能把它解釋為優先序。`0xC0` return1 分支跳過矩陣，既不是技能發動成功，也不是 V 長按已成功；可能是特殊動作免檢查，需要 caller 驗證。

**矩陣第一手**：`0x81A8E3 cmp al,4`、`0x81A8E7 cmp cl,0xB`，超出直接回0；`0x81A8EC..FF` 以 `WORD [matrix + 4 + 2*(tier*11 + key)]` 取技能 ID。可見 4 tier × 11 keys 的索引形狀，**但 4 個 tier 代表何種遊戲狀態、是否全由 V 控制仍未知**。

**可驗證的假說矩陣**（內部 bit→實際按鍵尚待確認）：
| flags | key | 已證實 | 不得先下的結論 |
|---|---:|---|---|
| 0x1 | 1 | 單 bit | Z |
| 0x2 | 2 | 單 bit | X |
| 0x4 | 3 | 單 bit | C |
| 0x3 | 4 | 兩 bit | Z+X |
| 0x5 | 5 | 兩 bit | Z+C |
| 0x6 | 6 | 兩 bit | X+C |
| 0x8 | 7 | 特殊 bit | V 點按 |
| 0x10 | 10 | 特殊 bit | V 長按 |

**不同 tier 的同一 key** 確實可能得到不同 WORD skill ID，這是與蓄氣後技能變化相容的資料結構，但不是蓄氣導致 tier 改變的原始證據。

**冷卻／可用性邊界**：`0x54F2D5` 讀 object+2 model WORD，查 `0x40F7F0→0x819220→0x81A8E0`；有 skill ID 時 `0x54F310` 進入可能**插入節點**的 `0x54F4E0`，`0x54F317` 比較 node payload +4 是否為 0。這既不是資源扣除也不是 cooldown timer 寫入。

## 證據分級及限制

- **已確認**：上述精確地址及機器碼、可見的記憶體讀寫和條件分支。
- **合理假說**：上述流程可能與 T10／T11 通用技能層相關；只把適合的欄位列為候選，不預先認作玩家蓄氣或普攻。
- **尚未驗證**：V 按鍵來源、四 tier 的實際觸發條件、Z/X/C 各自的映射值、連按 vs 長按、動畫完結時的下一招消費、扣除資源與冷卻 writer。
- **協作**：僅新增個人 `kr-temp-roy/T10/` 的交界分析；正式 T11 owner/task.json 和其他 Agent 筆記不修改。

## 後續定向追查

沿 KeyMapping.xml 實際檔案尋找「實體鍵→動作 bit」，沿 `0x5462DD` 的 tier 引數 producer 尋找 V 事件對其的寫入；再分析 tier 進入動畫／施放 callback 前後的採樣時機。