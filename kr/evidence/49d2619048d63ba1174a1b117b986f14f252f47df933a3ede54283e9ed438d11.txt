# T16-26 — 兩個註冊 handler 的資料讀取與狀態寫入（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：追 handler 傳入參數、條件與下游；未確認任務語義以前維持候選。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x004AE4D0`–`0x004AE640`（98 行）

```asm
  4ae4d0:	55                   	push   ebp
  4ae4d1:	8b ec                	mov    ebp,esp
  4ae4d3:	83 e4 f8             	and    esp,0xfffffff8
  4ae4d6:	6a ff                	push   0xffffffff
  4ae4d8:	68 db 0c 94 00       	push   0x940cdb
  4ae4dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ae4e3:	50                   	push   eax
  4ae4e4:	81 ec 38 01 00 00    	sub    esp,0x138
  4ae4ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ae4ef:	33 c4                	xor    eax,esp
  4ae4f1:	89 84 24 30 01 00 00 	mov    DWORD PTR [esp+0x130],eax
  4ae4f8:	53                   	push   ebx
  4ae4f9:	56                   	push   esi
  4ae4fa:	57                   	push   edi
  4ae4fb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ae500:	33 c4                	xor    eax,esp
  4ae502:	50                   	push   eax
  4ae503:	8d 84 24 48 01 00 00 	lea    eax,[esp+0x148]
  4ae50a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ae510:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4ae513:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4ae516:	83 f8 02             	cmp    eax,0x2
  4ae519:	73 04                	jae    0x4ae51f
  4ae51b:	33 d2                	xor    edx,edx
  4ae51d:	eb 0d                	jmp    0x4ae52c
  4ae51f:	8d 48 fe             	lea    ecx,[eax-0x2]
  4ae522:	b8 4f ec c4 4e       	mov    eax,0x4ec4ec4f
  4ae527:	f7 e1                	mul    ecx
  4ae529:	c1 ea 03             	shr    edx,0x3
  4ae52c:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  4ae530:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  4ae537:	00 
  4ae538:	85 d2                	test   edx,edx
  4ae53a:	0f 84 18 08 00 00    	je     0x4aed58
  4ae540:	83 c3 06             	add    ebx,0x6
  4ae543:	eb 0b                	jmp    0x4ae550
  4ae545:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4ae54c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4ae550:	b8 01 00 00 00       	mov    eax,0x1
  4ae555:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4ae559:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4ae55f:	75 2e                	jne    0x4ae58f
  4ae561:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4ae567:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x0
  4ae56e:	00 00 00 00 
  4ae572:	e8 19 07 03 00       	call   0x4dec90
  4ae577:	68 30 ce bc 00       	push   0xbcce30
  4ae57c:	e8 99 3d 3e 00       	call   0x89231a
  4ae581:	83 c4 04             	add    esp,0x4
  4ae584:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae58b:	ff ff ff ff 
  4ae58f:	0f b7 53 fc          	movzx  edx,WORD PTR [ebx-0x4]
  4ae593:	8d 44 24 18          	lea    eax,[esp+0x18]
  4ae597:	50                   	push   eax
  4ae598:	8d 44 24 58          	lea    eax,[esp+0x58]
  4ae59c:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4ae5a1:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4ae5a5:	e8 56 09 38 00       	call   0x82ef00
  4ae5aa:	8b 08                	mov    ecx,DWORD PTR [eax]
  4ae5ac:	3b 0d 3c b1 fa 00    	cmp    ecx,DWORD PTR ds:0xfab13c
  4ae5b2:	0f 85 8a 07 00 00    	jne    0x4aed42
  4ae5b8:	0f b6 43 fc          	movzx  eax,BYTE PTR [ebx-0x4]
  4ae5bc:	0f b6 7b fe          	movzx  edi,BYTE PTR [ebx-0x2]
  4ae5c0:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4ae5c3:	4f                   	dec    edi
  4ae5c4:	8b d0                	mov    edx,eax
  4ae5c6:	c1 e2 08             	shl    edx,0x8
  4ae5c9:	0b fa                	or     edi,edx
  4ae5cb:	c1 e7 10             	shl    edi,0x10
  4ae5ce:	0b f9                	or     edi,ecx
  4ae5d0:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4ae5d4:	83 f8 07             	cmp    eax,0x7
  4ae5d7:	0f 87 a6 07 00 00    	ja     0x4aed83
  4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
  4ae5e4:	68 44 04 00 00       	push   0x444
  4ae5e9:	e8 7a 2c 3e 00       	call   0x891268
  4ae5ee:	83 c4 04             	add    esp,0x4
  4ae5f1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae5f5:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  4ae5fc:	01 00 00 00 
  4ae600:	85 c0                	test   eax,eax
  4ae602:	74 0e                	je     0x4ae612
  4ae604:	8b 53 0e             	mov    edx,DWORD PTR [ebx+0xe]
  4ae607:	52                   	push   edx
  4ae608:	50                   	push   eax
  4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
  4ae60e:	8b f0                	mov    esi,eax
  4ae610:	eb 02                	jmp    0x4ae614
  4ae612:	33 f6                	xor    esi,esi
  4ae614:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae61b:	ff ff ff ff 
  4ae61f:	e8 7c 65 f5 ff       	call   0x404ba0
  4ae624:	8b 80 50 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f50]
  4ae62a:	39 43 0e             	cmp    DWORD PTR [ebx+0xe],eax
  4ae62d:	0f 85 e4 02 00 00    	jne    0x4ae917
  4ae633:	e8 68 65 f5 ff       	call   0x404ba0
  4ae638:	8b 90 24 69 00 00    	mov    edx,DWORD PTR [eax+0x6924]
  4ae63e:	0f b7              	movzx  eax,WORD PTR [ebx]
```

### VA `0x004AEDB0`–`0x004AEF00`（94 行）

```asm
  4aedb0:	55                   	push   ebp
  4aedb1:	8b ec                	mov    ebp,esp
  4aedb3:	83 e4 f8             	and    esp,0xfffffff8
  4aedb6:	6a ff                	push   0xffffffff
  4aedb8:	68 8c 97 93 00       	push   0x93978c
  4aedbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4aedc3:	50                   	push   eax
  4aedc4:	81 ec 30 05 00 00    	sub    esp,0x530
  4aedca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aedcf:	33 c4                	xor    eax,esp
  4aedd1:	89 84 24 28 05 00 00 	mov    DWORD PTR [esp+0x528],eax
  4aedd8:	53                   	push   ebx
  4aedd9:	56                   	push   esi
  4aedda:	57                   	push   edi
  4aeddb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aede0:	33 c4                	xor    eax,esp
  4aede2:	50                   	push   eax
  4aede3:	8d 84 24 40 05 00 00 	lea    eax,[esp+0x540]
  4aedea:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aedf0:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4aedf3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4aedf6:	83 f8 02             	cmp    eax,0x2
  4aedf9:	73 04                	jae    0x4aedff
  4aedfb:	33 d2                	xor    edx,edx
  4aedfd:	eb 0d                	jmp    0x4aee0c
  4aedff:	8d 48 fe             	lea    ecx,[eax-0x2]
  4aee02:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  4aee07:	f7 e1                	mul    ecx
  4aee09:	c1 ea 02             	shr    edx,0x2
  4aee0c:	85 d2                	test   edx,edx
  4aee0e:	0f 84 ab 03 00 00    	je     0x4af1bf
  4aee14:	83 c6 06             	add    esi,0x6
  4aee17:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4aee1b:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aee22:	75 2f                	jne    0x4aee53
  4aee24:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aee2b:	c7 84 24 48 05 00 00 	mov    DWORD PTR [esp+0x548],0x0
  4aee32:	00 00 00 00 
  4aee36:	e8 55 fe 02 00       	call   0x4dec90
  4aee3b:	68 30 ce bc 00       	push   0xbcce30
  4aee40:	e8 d5 34 3e 00       	call   0x89231a
  4aee45:	83 c4 04             	add    esp,0x4
  4aee48:	c7 84 24 48 05 00 00 	mov    DWORD PTR [esp+0x548],0xffffffff
  4aee4f:	ff ff ff ff 
  4aee53:	0f b7 56 fc          	movzx  edx,WORD PTR [esi-0x4]
  4aee57:	8d 44 24 18          	lea    eax,[esp+0x18]
  4aee5b:	50                   	push   eax
  4aee5c:	8d 44 24 30          	lea    eax,[esp+0x30]
  4aee60:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4aee65:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4aee69:	e8 92 00 38 00       	call   0x82ef00
  4aee6e:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  4aee72:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4aee78:	0f 84 34 03 00 00    	je     0x4af1b2
  4aee7e:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4aee81:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  4aee85:	85 c0                	test   eax,eax
  4aee87:	0f 84 25 03 00 00    	je     0x4af1b2
  4aee8d:	0f b6 5e fc          	movzx  ebx,BYTE PTR [esi-0x4]
  4aee91:	0f b6 4e fe          	movzx  ecx,BYTE PTR [esi-0x2]
  4aee95:	0f b7 16             	movzx  edx,WORD PTR [esi]
  4aee98:	c1 e3 08             	shl    ebx,0x8
  4aee9b:	49                   	dec    ecx
  4aee9c:	0b d9                	or     ebx,ecx
  4aee9e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4aeea4:	8b 01                	mov    eax,DWORD PTR [ecx]
  4aeea6:	c1 e3 10             	shl    ebx,0x10
  4aeea9:	0b da                	or     ebx,edx
  4aeeab:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4aeeae:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  4aeeb2:	ff d2                	call   edx
  4aeeb4:	8b f8                	mov    edi,eax
  4aeeb6:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4aeeba:	85 ff                	test   edi,edi
  4aeebc:	0f 84 24 01 00 00    	je     0x4aefe6
  4aeec2:	8d 44 24 4c          	lea    eax,[esp+0x4c]
  4aeec6:	50                   	push   eax
  4aeec7:	e8 a4 81 01 00       	call   0x4c7070
  4aeecc:	bf 01 00 00 00       	mov    edi,0x1
  4aeed1:	89 bc 24 48 05 00 00 	mov    DWORD PTR [esp+0x548],edi
  4aeed8:	d9 84 24 ec 00 00 00 	fld    DWORD PTR [esp+0xec]
  4aeedf:	d9 46 06             	fld    DWORD PTR [esi+0x6]
  4aeee2:	df e9                	fucomip st,st(1)
  4aeee4:	dd d8                	fstp   st(0)
  4aeee6:	9f                   	lahf
  4aeee7:	f6 c4 44             	test   ah,0x44
  4aeeea:	7a 14                	jp     0x4aef00
  4aeeec:	d9 84 24 f0 00 00 00 	fld    DWORD PTR [esp+0xf0]
  4aeef3:	d9 46 0a             	fld    DWORD PTR [esi+0xa]
  4aeef6:	df e9                	fucomip st,st(1)
  4aeef8:	dd d8                	fstp   st(0)
  4aeefa:	9f                   	lahf
  4aeefb:	f6 c4 44             	test   ah,0x44
  4aeefe:	7b 28                	jnp    0x4aef28
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
4ae572:	e8 19 07 03 00       	call   0x4dec90
4ae57c:	e8 99 3d 3e 00       	call   0x89231a
4ae5a5:	e8 56 09 38 00       	call   0x82ef00
4ae5e9:	e8 7a 2c 3e 00       	call   0x891268
4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
4ae61f:	e8 7c 65 f5 ff       	call   0x404ba0
4ae633:	e8 68 65 f5 ff       	call   0x404ba0
4aee36:	e8 55 fe 02 00       	call   0x4dec90
4aee40:	e8 d5 34 3e 00       	call   0x89231a
4aee69:	e8 92 00 38 00       	call   0x82ef00
4aeeb2:	ff d2                	call   edx
4aeec7:	e8 a4 81 01 00       	call   0x4c7070
```

### 比較與跳轉（前 55 筆）

```asm
4ae516:	83 f8 02             	cmp    eax,0x2
4ae519:	73 04                	jae    0x4ae51f
4ae51d:	eb 0d                	jmp    0x4ae52c
4ae538:	85 d2                	test   edx,edx
4ae53a:	0f 84 18 08 00 00    	je     0x4aed58
4ae543:	eb 0b                	jmp    0x4ae550
4ae559:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
4ae55f:	75 2e                	jne    0x4ae58f
4ae5ac:	3b 0d 3c b1 fa 00    	cmp    ecx,DWORD PTR ds:0xfab13c
4ae5b2:	0f 85 8a 07 00 00    	jne    0x4aed42
4ae5d4:	83 f8 07             	cmp    eax,0x7
4ae5d7:	0f 87 a6 07 00 00    	ja     0x4aed83
4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
4ae600:	85 c0                	test   eax,eax
4ae602:	74 0e                	je     0x4ae612
4ae610:	eb 02                	jmp    0x4ae614
4ae62a:	39 43 0e             	cmp    DWORD PTR [ebx+0xe],eax
4ae62d:	0f 85 e4 02 00 00    	jne    0x4ae917
4aedf6:	83 f8 02             	cmp    eax,0x2
4aedf9:	73 04                	jae    0x4aedff
4aedfd:	eb 0d                	jmp    0x4aee0c
4aee0c:	85 d2                	test   edx,edx
4aee0e:	0f 84 ab 03 00 00    	je     0x4af1bf
4aee1b:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
4aee22:	75 2f                	jne    0x4aee53
4aee72:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
4aee78:	0f 84 34 03 00 00    	je     0x4af1b2
4aee85:	85 c0                	test   eax,eax
4aee87:	0f 84 25 03 00 00    	je     0x4af1b2
4aeeba:	85 ff                	test   edi,edi
4aeebc:	0f 84 24 01 00 00    	je     0x4aefe6
4aeee7:	f6 c4 44             	test   ah,0x44
4aeefb:	f6 c4 44             	test   ah,0x44
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