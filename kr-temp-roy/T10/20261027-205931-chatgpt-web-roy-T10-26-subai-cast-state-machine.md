# KR T10-26 — SubAI 技能候選狀態 1／2／3／4 與環境判定

原始資料：`/mnt/data/Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）。研究日期：2026-10-27（Asia/Taipei）。

**方法**：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`，先核實完整函式的入口和跳轉邊界；未執行、注入或改寫客戶端。組語是 BIN 第一手證據；T10-24 與 GitHub T11 既有審核作交叉參考，不替代機器碼。未命名函式、物件欄位的語義均為候選。

**使用者補充（研究需求，非由 BIN 證明）**：按鍵可自訂；六種輸入 Z、X、C、Z+X、Z+C、X+C；V 點按／長按影響技能且包含 Z；普攻／技能有交互接續。研究不能將字母按鍵硬對映到 mask。

## 研究目標與本次範圍

檢查 `0x549D54` 成功分支的狀態 `4` 寫入，向下沿相鄰獨立函式 `0x549E10` 查可見的 1→2、條件→3、失敗→1，辨識是否存在確實可用的「技能狀態機」。本段不宣稱為玩家 V 蓄氣。

## 第一手組語摘錄

```asm
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
  549e10:	55                   	push   ebp
  549e11:	8b ec                	mov    ebp,esp
  549e13:	83 e4 f8             	and    esp,0xfffffff8
  549e16:	83 ec 18             	sub    esp,0x18
  549e19:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  549e1c:	d9 46 64             	fld    DWORD PTR [esi+0x64]
  549e1f:	d8 a0 a0 00 00 00    	fsub   DWORD PTR [eax+0xa0]
  549e25:	53                   	push   ebx
  549e26:	33 c9                	xor    ecx,ecx
  549e28:	57                   	push   edi
  549e29:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  549e2d:	d9 46 68             	fld    DWORD PTR [esi+0x68]
  549e30:	d8 a0 a4 00 00 00    	fsub   DWORD PTR [eax+0xa4]
  549e36:	8b 86 08 01 00 00    	mov    eax,DWORD PTR [esi+0x108]
  549e3c:	03 c0                	add    eax,eax
  549e3e:	83 bc c6 ac 00 00 00 	cmp    DWORD PTR [esi+eax*8+0xac],0x1
  549e45:	01 
  549e46:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  549e4a:	8d 84 c6 ac 00 00 00 	lea    eax,[esi+eax*8+0xac]
  549e51:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  549e55:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  549e59:	dc c8                	fmul   st(0),st
  549e5b:	d9 c1                	fld    st(1)
  549e5d:	de ca                	fmulp  st(2),st
  549e5f:	de c1                	faddp  st(1),st
  549e61:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  549e65:	75 15                	jne    0x549e7c
  549e67:	f3 0f 10 44 24 10    	movss  xmm0,DWORD PTR [esp+0x10]
  549e6d:	0f 2f 05 d0 58 c5 00 	comiss xmm0,DWORD PTR ds:0xc558d0
  549e74:	76 06                	jbe    0x549e7c
  549e76:	c7 00 02 00 00 00    	mov    DWORD PTR [eax],0x2
  549e7c:	8b 96 0c 01 00 00    	mov    edx,DWORD PTR [esi+0x10c]
  549e82:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  549e86:	03 d2                	add    edx,edx
  549e88:	d9 44 d6 7c          	fld    DWORD PTR [esi+edx*8+0x7c]
  549e8c:	d9 c9                	fxch   st(1)
  549e8e:	df f1                	fcomip st,st(1)
  549e90:	dd d8                	fstp   st(0)
  549e92:	76 21                	jbe    0x549eb5
  549e94:	8b 86 08 01 00 00    	mov    eax,DWORD PTR [esi+0x108]
  549e9a:	83 c0 0b             	add    eax,0xb
  549e9d:	03 c0                	add    eax,eax
  549e9f:	89 0c c6             	mov    DWORD PTR [esi+eax*8],ecx
  549ea2:	8b 96 08 01 00 00    	mov    edx,DWORD PTR [esi+0x108]
  549ea8:	03 d2                	add    edx,edx
  549eaa:	c7 84 d6 ac 00 00 00 	mov    DWORD PTR [esi+edx*8+0xac],0x3
  549eb1:	03 00 00 00 
  549eb5:	8b 86 08 01 00 00    	mov    eax,DWORD PTR [esi+0x108]
  549ebb:	03 c0                	add    eax,eax
  549ebd:	8b 84 c6 ac 00 00 00 	mov    eax,DWORD PTR [esi+eax*8+0xac]
  549ec4:	83 f8 02             	cmp    eax,0x2
  549ec7:	74 09                	je     0x549ed2
  549ec9:	83 f8 03             	cmp    eax,0x3
  549ecc:	0f 85 6e 01 00 00    	jne    0x54a040
  549ed2:	8b 4e 50             	mov    ecx,DWORD PTR [esi+0x50]
  54a004:	8a 44 24 0f          	mov    al,BYTE PTR [esp+0xf]
  54a008:	0f b6 d3             	movzx  edx,bl
  54a00b:	66 c1 e2 0f          	shl    dx,0xf
  54a00f:	66 89 56 72          	mov    WORD PTR [esi+0x72],dx
  54a013:	88 46 74             	mov    BYTE PTR [esi+0x74],al
  54a016:	84 db                	test   bl,bl
  54a018:	75 1b                	jne    0x54a035
  54a01a:	8b 8e 08 01 00 00    	mov    ecx,DWORD PTR [esi+0x108]
  54a020:	03 c9                	add    ecx,ecx
  54a022:	c7 84 ce ac 00 00 00 	mov    DWORD PTR [esi+ecx*8+0xac],0x1
  54a029:	01 00 00 00 
  54a02d:	33 c0                	xor    eax,eax
  54a02f:	5f                   	pop    edi
  54a030:	5b                   	pop    ebx
  54a031:	8b e5                	mov    esp,ebp
  54a033:	5d                   	pop    ebp
  54a034:	c3                   	ret
  54a035:	b8 01 00 00 00       	mov    eax,0x1
  54a03a:	5f                   	pop    edi
  54a03b:	5b                   	pop    ebx
  54a03c:	8b e5                	mov    esp,ebp
  54a03e:	5d                   	pop    ebp
  54a03f:	c3                   	ret
  54a040:	5f                   	pop    edi
  54a041:	8b c1                	mov    eax,ecx
  54a043:	5b                   	pop    ebx
  54a044:	8b e5                	mov    esp,ebp
  54a046:	5d                   	pop    ebp
  54a047:	c3                   	ret
```

## 逐層分析與新結論

**函式邊界首先確認**：`0x549D54` 位於 `0x549980` 起始的 SubAI condition helper，其 `0x549E04 ret 0x10` 結束；`0x549E07..0x549E0F` 是 INT3，`0x549E10` 才是新的 prologue。不可將這兩個 caller 直接視為同一個主函式。

**`0x549D54` 的成功寫入**：`0x549D59 test eax,eax`；成功時讀 `[esi+0x72]`、`[esi+0x108]`，對 word+0x72 的低15位以 `[edi]` 派生遮罩改寫，然後 `0x549D7D` 將 `4` 寫到 `[esi + 0xAC + ([esi+0x108]*2)*8]`。實際 stride 為 `16`，不是把每段連擊索引直接變成四倍位址。該欄位與 `0x54F270` 的 cooldown entry 不是同一指標，**不能把 4 命名成冷卻倒數或 V 第四階段**。

**`0x549E10` 相鄰 helper 更接近實際狀態轉換**：使用 `[esi+0x50]` 物件 +0xA0/+0xA4 作座標差；`0x549E3E` 對 `[esi+0xAC+idx*16]` 比較 1；距離平方大於固定浮點常數 `0xC558D0` 時 `0x549E76` 把狀態設 2；另一個距離判斷通過時 `0x549EAA` 寫 3 並將其它欄位清零。分別讀狀態 2/3，查 `[esi+0xA8+otherIdx*16]` 的候選資料，再做對象／距離／幾何門檻與方向角度判定。

**重置分支**：`0x54A00F` 寫 `[esi+0x72]`，`0x54A013` 寫角度 byte +0x74；`0x54A020..0x54A029` 在分支失敗時將 slot state 設為 1，回傳 0；成功則回傳 1。這個 1/2/3/4 的有限狀態流程有具體寫入證據，但涉及 SubAI 物件、位置、尋找目標等判定，**更可能是技能選擇／目標評估的 AI 物件狀態，而不是玩家按 V 的蓄氣時長。**

**有限資料模型（非原簽名）**：
```cpp
int idx = obj->field108;
State* slot = (State*)((uint8_t*)obj + 0xAC + idx*16);
if (availability(...)) { updateMask(obj->word72); slot->state=4; }
// separate 0x549E10 routine: target/distance gates
if (slot->state==1 && distanceSq>limit) slot->state=2;
if (otherDistanceGate) slot->state=3;
if (recoveryFailure) slot->state=1;
```

**特別注意**：這不是從 1 線性計時到 4，且相鄰兩函式不保證使用同一個呼叫頻率。

## 證據分級及限制

- **已確認**：上述精確地址及機器碼、可見的記憶體讀寫和條件分支。
- **合理假說**：上述流程可能與 T10／T11 通用技能層相關；只把適合的欄位列為候選，不預先認作玩家蓄氣或普攻。
- **尚未驗證**：V 按鍵來源、四 tier 的實際觸發條件、Z/X/C 各自的映射值、連按 vs 長按、動畫完結時的下一招消費、扣除資源與冷卻 writer。
- **協作**：僅新增個人 `kr-temp-roy/T10/` 的交界分析；正式 T11 owner/task.json 和其他 Agent 筆記不修改。

## 後續定向追查

尋找該 16-byte slot 的初始化與 `0x54A050` 的接收／讀回，區分 AI 目標狀態與玩家 charge state；只有在 actor 欄位指標確實交會時才提出跨界共用。