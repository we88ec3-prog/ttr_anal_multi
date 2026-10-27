# KR T10/T11 交界研究 — T10-23 四個技能 availability 呼叫者比較

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 交叉參照
既有 GitHub T11 audit 限定四個直接 E8 call site：`0x5462DD`、`0x54827F`、`0x549C0E`、`0x549D54`。本段直接從本地 BIN 擷取四個位置附近，以 caller-specific 實參來源與 return 消費進行比較。

- `0x5462DD`：控制器取得 `0x546780` 輸入後，用 actor+0x3E8、矩陣索引與局部旗標做判斷；回傳非零寫堆疊 local flag。
- `0x54827F`：在角色狀態 `+0x158` 和 `0x4C9ED0` 閘控後，從另一筆 output word 的低 15 位組裝 flag，查 availability；返回非零則設 local flag。與 `0x5462DD` 是兩個不同 control paths，**不能因共用 callee 就稱為普攻接技能**。
- `0x549C0E`：既有 `SubAI` condition 相關路徑，呼叫前有 actor+0x3C8/+0x3CC/+0x3D0 資源或限制判斷；返回非零繼續測 `[ebp+0x14]` 及 actor+0x3E8，比純輸入合成多了一層語意 gate。
- `0x549D54`：另一條 condition 相關路徑，返回非零後會更新 object+0x72 的 WORD 及 `object + (object+0x108)*16 + 0xAC` 中 DWORD 為 4；這是確實**寫入暫定狀態欄位**的證據，但無法由該常數單獨判定為 cooldown、連段段數或取消窗口。

## 更正與分工
先前 T10 研究觸及 `0x54F270`，應將它在 T11 追蹤清單中標為「已有 partial validated callsites」；T10 不複製冷卻／消耗核心所有權。普攻與技能有交會路徑，不表示同一招式分類，也未核實兩招連接時接受次序。

## 下一段
T10-24 提出以 actor motion state / action queues 為核心的交會驗證框架，避免一直在 UI 或 matrix lookup 迴圈中打轉。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 0054823D..00548293
```asm
0054823d <.data+0x14763d>:
  54823d:	0e                   	push   cs
  54823e:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  548241:	b9 00 80 00 00       	mov    ecx,0x8000
  548246:	66 21 4f 02          	and    WORD PTR [edi+0x2],cx
  54824a:	eb 44                	jmp    0x548290
  54824c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  54824f:	66 8b 40 02          	mov    ax,WORD PTR [eax+0x2]
  548253:	ba ff 7f 00 00       	mov    edx,0x7fff
  548258:	66 23 c2             	and    ax,dx
  54825b:	74 30                	je     0x54828d
  54825d:	8b 8e e8 03 00 00    	mov    ecx,DWORD PTR [esi+0x3e8]
  548263:	33 d2                	xor    edx,edx
  548265:	38 57 02             	cmp    BYTE PTR [edi+0x2],dl
  548268:	51                   	push   ecx
  548269:	0f 95 c2             	setne  dl
  54826c:	8a 14 3a             	mov    dl,BYTE PTR [edx+edi*1]
  54826f:	88 54 24 1c          	mov    BYTE PTR [esp+0x1c],dl
  548273:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  548277:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  54827b:	51                   	push   ecx
  54827c:	8b 4a 10             	mov    ecx,DWORD PTR [edx+0x10]
  54827f:	e8 ec 6f 00 00       	call   0x54f270
  548284:	85 c0                	test   eax,eax
  548286:	74 56                	je     0x5482de
  548288:	c6 44 24 13 01       	mov    BYTE PTR [esp+0x13],0x1
  54828d:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  548290:	8b 86 58       	mov    eax,DWORD PTR [esi+0x158]
```

### VA 00549BD8..00549C39
```asm
00549bd8 <.data+0x148fd8>:
  549bd8:	8b 46 60             	mov    eax,DWORD PTR [esi+0x60]
  549bdb:	8b 15 a4 a7 fb 00    	mov    edx,DWORD PTR ds:0xfba7a4
  549be1:	8d 0c 40             	lea    ecx,[eax+eax*2]
  549be4:	8b 54 8a 10          	mov    edx,DWORD PTR [edx+ecx*4+0x10]
  549be8:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  549bec:	33 c9                	xor    ecx,ecx
  549bee:	38 48 02             	cmp    BYTE PTR [eax+0x2],cl
  549bf1:	0f 95 c1             	setne  cl
  549bf4:	8a 04 01             	mov    al,BYTE PTR [ecx+eax*1]
  549bf7:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  549bfa:	88 44 24 28          	mov    BYTE PTR [esp+0x28],al
  549bfe:	e8 1d f1 ff ff       	call   0x548d20
  549c03:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  549c06:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  549c0a:	57                   	push   edi
  549c0b:	51                   	push   ecx
  549c0c:	8b ca                	mov    ecx,edx
  549c0e:	e8 5d 56 00 00       	call   0x54f270
  549c13:	85 c0                	test   eax,eax
  549c15:	74 21                	je     0x549c38
  549c17:	83 7d 14 00          	cmp    DWORD PTR [ebp+0x14],0x0
  549c1b:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  549c22:	00 
  549c23:	74 13                	je     0x549c38
  549c25:	8b 56 50             	mov    edx,DWORD PTR [esi+0x50]
  549c28:	39 ba e8 03 00 00    	cmp    DWORD PTR [edx+0x3e8],edi
  549c2e:	74 08                	je     0x549c38
  549c30:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  549c37:	00 
  549c38:	8b             	mov    eax,DWORD PTR [esp+0x18]
```

### VA 00549D29..00549D90
```asm
00549d29 <.data+0x149129>:
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
  549d8e:	8b 4c            	mov    ecx,DWORD PTR [esp+0x18]
```