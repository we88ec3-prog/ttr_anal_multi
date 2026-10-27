# T16-30 — TutoQuest 與 HasQuest 條件解析（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：核對 0x72E2E0 子節點查找及 0x53FEB0 寫入目標，區分設定表與角色持久化。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x005321A0`–`0x00532360`（133 行）

```asm
  5321a0:	4c                   	dec    esp
  5321a1:	0e                   	push   cs
  5321a2:	00 00                	add    BYTE PTR [eax],al
  5321a4:	50                   	push   eax
  5321a5:	56                   	push   esi
  5321a6:	8d 7c 24 40          	lea    edi,[esp+0x40]
  5321aa:	e8 c1 0b 00 00       	call   0x532d70
  5321af:	8d b4 24 48 01 00 00 	lea    esi,[esp+0x148]
  5321b6:	e8 15 04 00 00       	call   0x5325d0
  5321bb:	8d b4 24 8c 01 00 00 	lea    esi,[esp+0x18c]
  5321c2:	e8 09 04 00 00       	call   0x5325d0
  5321c7:	83 7c 24 54 08       	cmp    DWORD PTR [esp+0x54],0x8
  5321cc:	72 0d                	jb     0x5321db
  5321ce:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  5321d2:	51                   	push   ecx
  5321d3:	e8 34 f0 35 00       	call   0x89120c
  5321d8:	83 c4 04             	add    esp,0x4
  5321db:	33 d2                	xor    edx,edx
  5321dd:	83 bc 24 a8 00 00 00 	cmp    DWORD PTR [esp+0xa8],0x8
  5321e4:	08 
  5321e5:	c7 44 24 54 07 00 00 	mov    DWORD PTR [esp+0x54],0x7
  5321ec:	00 
  5321ed:	89 5c 24 50          	mov    DWORD PTR [esp+0x50],ebx
  5321f1:	66 89 54 24 40       	mov    WORD PTR [esp+0x40],dx
  5321f6:	72 10                	jb     0x532208
  5321f8:	8b 84 24 94 00 00 00 	mov    eax,DWORD PTR [esp+0x94]
  5321ff:	50                   	push   eax
  532200:	e8 07 f0 35 00       	call   0x89120c
  532205:	83 c4 04             	add    esp,0x4
  532208:	88 9c 24 e8 01 00 00 	mov    BYTE PTR [esp+0x1e8],bl
  53220f:	83 bc 24 c4 00 00 00 	cmp    DWORD PTR [esp+0xc4],0x10
  532216:	10 
  532217:	72 10                	jb     0x532229
  532219:	8b 8c 24 b0 00 00 00 	mov    ecx,DWORD PTR [esp+0xb0]
  532220:	51                   	push   ecx
  532221:	e8 e6 ef 35 00       	call   0x89120c
  532226:	83 c4 04             	add    esp,0x4
  532229:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  53222d:	bf 7c f1 c0 00       	mov    edi,0xc0f17c
  532232:	e8 89 c1 1f 00       	call   0x72e3c0
  532237:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  53223b:	3b c3                	cmp    eax,ebx
  53223d:	0f 85 bf fb ff ff    	jne    0x531e02
  532243:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  532247:	68 a4 f1 c0 00       	push   0xc0f1a4
  53224c:	e8 8f c0 1f 00       	call   0x72e2e0
  532251:	3b c3                	cmp    eax,ebx
  532253:	0f 84 f7 02 00 00    	je     0x532550
  532259:	bf 7c f1 c0 00       	mov    edi,0xc0f17c
  53225e:	e8 fd c0 1f 00       	call   0x72e360
  532263:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  532267:	3b c3                	cmp    eax,ebx
  532269:	0f 84 e1 02 00 00    	je     0x532550
  53226f:	90                   	nop
  532270:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  532274:	83 c7 44             	add    edi,0x44
  532277:	68 b0 f1 c0 00       	push   0xc0f1b0
  53227c:	e8 1f de 1f 00       	call   0x7300a0
  532281:	3b c3                	cmp    eax,ebx
  532283:	74 1e                	je     0x5322a3
  532285:	83 c0 30             	add    eax,0x30
  532288:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53228c:	72 02                	jb     0x532290
  53228e:	8b 00                	mov    eax,DWORD PTR [eax]
  532290:	3b c3                	cmp    eax,ebx
  532292:	74 0f                	je     0x5322a3
  532294:	50                   	push   eax
  532295:	e8 1a f5 35 00       	call   0x8917b4
  53229a:	83 c4 04             	add    esp,0x4
  53229d:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5322a1:	eb 04                	jmp    0x5322a7
  5322a3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  5322a7:	68 b4 f1 c0 00       	push   0xc0f1b4
  5322ac:	e8 ef dd 1f 00       	call   0x7300a0
  5322b1:	3b c3                	cmp    eax,ebx
  5322b3:	74 1c                	je     0x5322d1
  5322b5:	83 c0 30             	add    eax,0x30
  5322b8:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5322bc:	72 02                	jb     0x5322c0
  5322be:	8b 00                	mov    eax,DWORD PTR [eax]
  5322c0:	3b c3                	cmp    eax,ebx
  5322c2:	74 0d                	je     0x5322d1
  5322c4:	50                   	push   eax
  5322c5:	e8 ea f4 35 00       	call   0x8917b4
  5322ca:	83 c4 04             	add    esp,0x4
  5322cd:	8b f0                	mov    esi,eax
  5322cf:	eb 02                	jmp    0x5322d3
  5322d1:	33 f6                	xor    esi,esi
  5322d3:	68 b8 f1 c0 00       	push   0xc0f1b8
  5322d8:	e8 c3 dd 1f 00       	call   0x7300a0
  5322dd:	3b c3                	cmp    eax,ebx
  5322df:	74 1e                	je     0x5322ff
  5322e1:	83 c0 30             	add    eax,0x30
  5322e4:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5322e8:	72 02                	jb     0x5322ec
  5322ea:	8b 00                	mov    eax,DWORD PTR [eax]
  5322ec:	3b c3                	cmp    eax,ebx
  5322ee:	74 0f                	je     0x5322ff
  5322f0:	50                   	push   eax
  5322f1:	e8 be f4 35 00       	call   0x8917b4
  5322f6:	83 c4 04             	add    esp,0x4
  5322f9:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5322fd:	eb 04                	jmp    0x532303
  5322ff:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  532303:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  532307:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53230b:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  53230f:	8d 7c 24 2c          	lea    edi,[esp+0x2c]
  532313:	be 98 1e fe 00       	mov    esi,0xfe1e98
  532318:	89 54 24 2c          	mov    DWORD PTR [esp+0x2c],edx
  53231c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  532320:	e8 2b f9 2e 00       	call   0x821c50
  532325:	50                   	push   eax
  532326:	56                   	push   esi
  532327:	8d 74 24 40          	lea    esi,[esp+0x40]
  53232b:	e8 c0 58 fe ff       	call   0x517bf0
  532330:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  532334:	68 90 f1 c0 00       	push   0xc0f190
  532339:	83 c7 44             	add    edi,0x44
  53233c:	e8 5f dd 1f 00       	call   0x7300a0
  532341:	3b c3                	cmp    eax,ebx
  532343:	74 1a                	je     0x53235f
  532345:	83 c0 30             	add    eax,0x30
  532348:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53234c:	72 02                	jb     0x532350
  53234e:	8b 00                	mov    eax,DWORD PTR [eax]
  532350:	3b c3                	cmp    eax,ebx
  532352:	74 0b                	je     0x53235f
  532354:	50                   	push   eax
  532355:	e8 5a f4 35 00       	call   0x8917b4
  53235a:	83 c4 04             	add    esp,0x4
  53235d:	eb 02                	jmp    0x532361
  53235f:	33                 	xor    eax,eax
```

### VA `0x0053FD60`–`0x0053FE40`（67 行）

```asm
  53fd60:	89 70 28             	mov    DWORD PTR [eax+0x28],esi
  53fd63:	89 70 30             	mov    DWORD PTR [eax+0x30],esi
  53fd66:	89 70 34             	mov    DWORD PTR [eax+0x34],esi
  53fd69:	89 70 38             	mov    DWORD PTR [eax+0x38],esi
  53fd6c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  53fd70:	eb 04                	jmp    0x53fd76
  53fd72:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
  53fe29:	bb 10 00 00 00       	mov    ebx,0x10
  53fe2e:	c7 84 24 c0 00 00 00 	mov    DWORD PTR [esp+0xc0],0xffffffff
  53fe35:	ff ff ff ff 
  53fe39:	c7 44 24 34 94 23 bf 	mov    DWORD PTR [esp+0x34],0xbf2394
  53fe40:	 
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
5321aa:	e8 c1 0b 00 00       	call   0x532d70
5321b6:	e8 15 04 00 00       	call   0x5325d0
5321c2:	e8 09 04 00 00       	call   0x5325d0
5321d3:	e8 34 f0 35 00       	call   0x89120c
532200:	e8 07 f0 35 00       	call   0x89120c
532221:	e8 e6 ef 35 00       	call   0x89120c
532232:	e8 89 c1 1f 00       	call   0x72e3c0
53224c:	e8 8f c0 1f 00       	call   0x72e2e0
53225e:	e8 fd c0 1f 00       	call   0x72e360
53227c:	e8 1f de 1f 00       	call   0x7300a0
532295:	e8 1a f5 35 00       	call   0x8917b4
5322ac:	e8 ef dd 1f 00       	call   0x7300a0
5322c5:	e8 ea f4 35 00       	call   0x8917b4
5322d8:	e8 c3 dd 1f 00       	call   0x7300a0
5322f1:	e8 be f4 35 00       	call   0x8917b4
532320:	e8 2b f9 2e 00       	call   0x821c50
53232b:	e8 c0 58 fe ff       	call   0x517bf0
53233c:	e8 5f dd 1f 00       	call   0x7300a0
532355:	e8 5a f4 35 00       	call   0x8917b4
53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
53fdbd:	e8 ee 00 00 00       	call   0x53feb0
53fdd0:	e8 db 00 00 00       	call   0x53feb0
53fde1:	e8 ca 00 00 00       	call   0x53feb0
53fdf2:	e8 b9 00 00 00       	call   0x53feb0
53fe0c:	e8 0f f1 03 00       	call   0x57ef20
53fe17:	e8 34 ea 03 00       	call   0x57e850
```

### 比較與跳轉（前 55 筆）

```asm
5321c7:	83 7c 24 54 08       	cmp    DWORD PTR [esp+0x54],0x8
5321cc:	72 0d                	jb     0x5321db
5321dd:	83 bc 24 a8 00 00 00 	cmp    DWORD PTR [esp+0xa8],0x8
5321f6:	72 10                	jb     0x532208
53220f:	83 bc 24 c4 00 00 00 	cmp    DWORD PTR [esp+0xc4],0x10
532217:	72 10                	jb     0x532229
53223b:	3b c3                	cmp    eax,ebx
53223d:	0f 85 bf fb ff ff    	jne    0x531e02
532251:	3b c3                	cmp    eax,ebx
532253:	0f 84 f7 02 00 00    	je     0x532550
532267:	3b c3                	cmp    eax,ebx
532269:	0f 84 e1 02 00 00    	je     0x532550
532281:	3b c3                	cmp    eax,ebx
532283:	74 1e                	je     0x5322a3
532288:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
53228c:	72 02                	jb     0x532290
532290:	3b c3                	cmp    eax,ebx
532292:	74 0f                	je     0x5322a3
5322a1:	eb 04                	jmp    0x5322a7
5322b1:	3b c3                	cmp    eax,ebx
5322b3:	74 1c                	je     0x5322d1
5322b8:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
5322bc:	72 02                	jb     0x5322c0
5322c0:	3b c3                	cmp    eax,ebx
5322c2:	74 0d                	je     0x5322d1
5322cf:	eb 02                	jmp    0x5322d3
5322dd:	3b c3                	cmp    eax,ebx
5322df:	74 1e                	je     0x5322ff
5322e4:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
5322e8:	72 02                	jb     0x5322ec
5322ec:	3b c3                	cmp    eax,ebx
5322ee:	74 0f                	je     0x5322ff
5322fd:	eb 04                	jmp    0x532303
532341:	3b c3                	cmp    eax,ebx
532343:	74 1a                	je     0x53235f
532348:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
53234c:	72 02                	jb     0x532350
532350:	3b c3                	cmp    eax,ebx
532352:	74 0b                	je     0x53235f
53235d:	eb 02                	jmp    0x532361
53fd70:	eb 04                	jmp    0x53fd76
53fdb2:	85 ff                	test   edi,edi
53fdb4:	74 0c                	je     0x53fdc2
53fdc6:	85 f6                	test   esi,esi
53fdc8:	74 0b                	je     0x53fdd5
53fdd9:	85 c0                	test   eax,eax
53fddb:	74 09                	je     0x53fde6
53fdea:	85 c0                	test   eax,eax
53fdec:	74 09                	je     0x53fdf7
53fe21:	3b de                	cmp    ebx,esi
53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
```

## D. 資料流與局部偽碼

```cpp
// 以下僅是抽象的有界行為，非官方函式名稱，未自動確認函式 ABI。
void investigated_entry(UnknownContext* ctx, UnknownPayload* input) {
    // Refer to raw assembly above for exact push/this/stack args.
    // Conditional and call-site details must be traced into callees.
    // Native quest_step_id, writer, server_authority: unknown.
}
```

研究上，`eax/ecx/edx` 值必須依函式入口與呼叫約定回溯，不能跨不同物件將相同 offset 當相同欄位。字串與 handler 表不構成正式 Quest 型別的證明。

## E. 節點矩陣與跨 Task 協作

| 節點 | 前置／角色狀態 | 入口／可觀察內容 | 伺服器權威 | state writer | UI／通知 | 下一步／重登 |
|---|---|---|---|---|---|---|
| 本段查核候選 | unknown | 見第 B 節實際 assembly | unknown | unknown | unknown | unknown |
| Tutorial 完成 → 主線任務 | unknown | Lua／XML 類型已有歷史地址線索，實體內容缺失 | unknown | unknown | unknown | unknown |

- `T02` 保留傳輸與 opcode 基底分派主責；本段只研究 Quest 業務連接是否可證實。
- `T03/T04` 保留登入／角色初始化；本段不設定角色初值。
- `T07/T14` 保留場景進出與勝敗結算；不將通關直接等同任務完成。
- `T15` 保留儲存與恢復底層；目前 Quest 欄位持久化鍵 unknown。
- `TC` 仍只有目標 SHA 與資料來源索引，本段沒有 TC BIN 直接驗證。

## F. 分析與可玩性驗收獨立

| 檢驗項目 | 結論 |
|---|---|
| KR 原始 BIN SHA | 已驗證 |
| 指定 VA 機器碼存在 | 已驗證 |
| 本段地址屬 Quest business handler | 尚待驗證 |
| 教學完整步驟 | 資源缺失 |
| 第一個主線 ID／NPC | 資源缺失 |
| 伺服器任務寫入／重登續接 | 未閉環 |
| 真實遊玩測試 | 未執行，未通過驗收 |

## G. 下一步與未解事項

1. 依 B 節 `call` 目標做選擇性的全域 caller/callee / writer-consumer 交叉參照，優先找明確 Quest payload 而非任意 handler。
2. 從版本匹配的原版 `Event/TutorialMain.lua`、`Table/QuestInfo.xml`、`Table/QuestTalk.xml` 取得真正 quest IDs／觸發條件，避免 fixture 補猜。
3. 將 Quest 通知的 T02 opcode 及 T16 writer 對接；未找到時保留 `unknown` 而不是填假值。
4. TC 版本只在取得原始對應來源與 hash 後獨立驗證；不沿用 KR VA。

## H. 提交說明

此為完整可回溯的本批**限定範圍原始技術原稿**，不是整個任務業務鏈已復原之證明。來源檔唯讀，未執行或修改客戶端，未改其他 Task 的 owner、catalog 或原稿。