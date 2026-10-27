# T16-28 — 註冊 handler 後段處理與通知候選（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：以原生機器碼判定是否存在可觀察的任務狀態修改或只處理場景資料。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x004AFAF0`–`0x004AFC50`（124 行）

```asm
  4afaf0:	55                   	push   ebp
  4afaf1:	8b ec                	mov    ebp,esp
  4afaf3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4afaf6:	83 f8 02             	cmp    eax,0x2
  4afaf9:	73 04                	jae    0x4afaff
  4afafb:	33 d2                	xor    edx,edx
  4afafd:	eb 0d                	jmp    0x4afb0c
  4afaff:	8d 48 fe             	lea    ecx,[eax-0x2]
  4afb02:	b8 ab aa aa aa       	mov    eax,0xaaaaaaab
  4afb07:	f7 e1                	mul    ecx
  4afb09:	c1 ea 02             	shr    edx,0x2
  4afb0c:	85 d2                	test   edx,edx
  4afb0e:	74 64                	je     0x4afb74
  4afb10:	53                   	push   ebx
  4afb11:	56                   	push   esi
  4afb12:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4afb15:	57                   	push   edi
  4afb16:	83 c6 04             	add    esi,0x4
  4afb19:	8b da                	mov    ebx,edx
  4afb1b:	eb 03                	jmp    0x4afb20
  4afb1d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4afb20:	0f b7 56 fe          	movzx  edx,WORD PTR [esi-0x2]
  4afb24:	89 55 0c             	mov    DWORD PTR [ebp+0xc],edx
  4afb27:	e8 34 f5 f5 ff       	call   0x40f060
  4afb2c:	8b f8                	mov    edi,eax
  4afb2e:	8d 45 0c             	lea    eax,[ebp+0xc]
  4afb31:	50                   	push   eax
  4afb32:	8d 4f 08             	lea    ecx,[edi+0x8]
  4afb35:	8d 45 08             	lea    eax,[ebp+0x8]
  4afb38:	e8 c3 f3 37 00       	call   0x82ef00
  4afb3d:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4afb40:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4afb43:	74 07                	je     0x4afb4c
  4afb45:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  4afb48:	85 c9                	test   ecx,ecx
  4afb4a:	75 0f                	jne    0x4afb5b
  4afb4c:	68 88 6a c0 00       	push   0xc06a88
  4afb51:	e8 0a e0 23 00       	call   0x6edb60
  4afb56:	83 c4 04             	add    esp,0x4
  4afb59:	eb 10                	jmp    0x4afb6b
  4afb5b:	0f b7 46 02          	movzx  eax,WORD PTR [esi+0x2]
  4afb5f:	8b 11                	mov    edx,DWORD PTR [ecx]
  4afb61:	8b 52 2c             	mov    edx,DWORD PTR [edx+0x2c]
  4afb64:	50                   	push   eax
  4afb65:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4afb68:	50                   	push   eax
  4afb69:	ff d2                	call   edx
  4afb6b:	83 c6 06             	add    esi,0x6
  4afb6e:	4b                   	dec    ebx
  4afb6f:	75 af                	jne    0x4afb20
  4afb71:	5f                   	pop    edi
  4afb72:	5e                   	pop    esi
  4afb73:	5b                   	pop    ebx
  4afb74:	33 c0                	xor    eax,eax
  4afb76:	5d                   	pop    ebp
  4afb77:	c2 0c 00             	ret    0xc
  4afb7a:	cc                   	int3
  4afb7b:	cc                   	int3
  4afb7c:	cc                   	int3
  4afb7d:	cc                   	int3
  4afb7e:	cc                   	int3
  4afb7f:	cc                   	int3
  4afb80:	55                   	push   ebp
  4afb81:	8b ec                	mov    ebp,esp
  4afb83:	83 e4 f8             	and    esp,0xfffffff8
  4afb86:	6a ff                	push   0xffffffff
  4afb88:	68 1e 6e 93 00       	push   0x936e1e
  4afb8d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4afb93:	50                   	push   eax
  4afb94:	83 ec 40             	sub    esp,0x40
  4afb97:	53                   	push   ebx
  4afb98:	56                   	push   esi
  4afb99:	57                   	push   edi
  4afb9a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4afb9f:	33 c4                	xor    eax,esp
  4afba1:	50                   	push   eax
  4afba2:	8d 44 24 50          	lea    eax,[esp+0x50]
  4afba6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4afbac:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4afbaf:	83 f8 02             	cmp    eax,0x2
  4afbb2:	73 04                	jae    0x4afbb8
  4afbb4:	33 d2                	xor    edx,edx
  4afbb6:	eb 0d                	jmp    0x4afbc5
  4afbb8:	8d 48 fe             	lea    ecx,[eax-0x2]
  4afbbb:	b8 cd cc cc cc       	mov    eax,0xcccccccd
  4afbc0:	f7 e1                	mul    ecx
  4afbc2:	c1 ea 03             	shr    edx,0x3
  4afbc5:	33 db                	xor    ebx,ebx
  4afbc7:	3b d3                	cmp    edx,ebx
  4afbc9:	0f 86 ab 01 00 00    	jbe    0x4afd7a
  4afbcf:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4afbd2:	83 c7 04             	add    edi,0x4
  4afbd5:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4afbd9:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4afbdd:	eb 03                	jmp    0x4afbe2
  4afbdf:	90                   	nop
  4afbe0:	33 db                	xor    ebx,ebx
  4afbe2:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4afbe9:	75 25                	jne    0x4afc10
  4afbeb:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4afbf2:	89 5c 24 58          	mov    DWORD PTR [esp+0x58],ebx
  4afbf6:	e8 95 f0 02 00       	call   0x4dec90
  4afbfb:	68 30 ce bc 00       	push   0xbcce30
  4afc00:	e8 15 27 3e 00       	call   0x89231a
  4afc05:	83 c4 04             	add    esp,0x4
  4afc08:	c7 44 24 58 ff ff ff 	mov    DWORD PTR [esp+0x58],0xffffffff
  4afc0f:	ff 
  4afc10:	0f b7 57 fe          	movzx  edx,WORD PTR [edi-0x2]
  4afc14:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4afc18:	50                   	push   eax
  4afc19:	8d 44 24 24          	lea    eax,[esp+0x24]
  4afc1d:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4afc22:	89 54 24 20          	mov    DWORD PTR [esp+0x20],edx
  4afc26:	e8 d5 f2 37 00       	call   0x82ef00
  4afc2b:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4afc2f:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4afc35:	74 07                	je     0x4afc3e
  4afc37:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  4afc3a:	3b f3                	cmp    esi,ebx
  4afc3c:	75 12                	jne    0x4afc50
  4afc3e:	68 b0 6a c0 00       	push   0xc06ab0
  4afc43:	e8 18 df 23 00       	call   0x6edb60
  4afc48:	83 c4 04             	add    esp,0x4
  4afc4b:	e9 19 01 00 00       	jmp    0x4afd69
```

### VA `0x004AFE60`–`0x004AFFC0`（93 行）

```asm
  4afe60:	55                   	push   ebp
  4afe61:	8b ec                	mov    ebp,esp
  4afe63:	83 e4 f8             	and    esp,0xfffffff8
  4afe66:	6a ff                	push   0xffffffff
  4afe68:	68 1e 6e 93 00       	push   0x936e1e
  4afe6d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4afe73:	50                   	push   eax
  4afe74:	83 ec 40             	sub    esp,0x40
  4afe77:	53                   	push   ebx
  4afe78:	56                   	push   esi
  4afe79:	57                   	push   edi
  4afe7a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4afe7f:	33 c4                	xor    eax,esp
  4afe81:	50                   	push   eax
  4afe82:	8d 44 24 50          	lea    eax,[esp+0x50]
  4afe86:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4afe8c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4afe8f:	83 f8 02             	cmp    eax,0x2
  4afe92:	73 04                	jae    0x4afe98
  4afe94:	33 c0                	xor    eax,eax
  4afe96:	eb 06                	jmp    0x4afe9e
  4afe98:	83 c0 fe             	add    eax,0xfffffffe
  4afe9b:	c1 e8 03             	shr    eax,0x3
  4afe9e:	85 c0                	test   eax,eax
  4afea0:	0f 84 65 02 00 00    	je     0x4b010b
  4afea6:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4afea9:	83 c3 06             	add    ebx,0x6
  4afeac:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  4afeb0:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4afeb4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4afebb:	75 29                	jne    0x4afee6
  4afebd:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4afec4:	c7 44 24 58 00 00 00 	mov    DWORD PTR [esp+0x58],0x0
  4afecb:	00 
  4afecc:	e8 bf ed 02 00       	call   0x4dec90
  4afed1:	68 30 ce bc 00       	push   0xbcce30
  4afed6:	e8 3f 24 3e 00       	call   0x89231a
  4afedb:	83 c4 04             	add    esp,0x4
  4afede:	c7 44 24 58 ff ff ff 	mov    DWORD PTR [esp+0x58],0xffffffff
  4afee5:	ff 
  4afee6:	0f b7 7b fc          	movzx  edi,WORD PTR [ebx-0x4]
  4afeea:	8b c7                	mov    eax,edi
  4afeec:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4afef0:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4afef4:	51                   	push   ecx
  4afef5:	8d 44 24 24          	lea    eax,[esp+0x24]
  4afef9:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4afefe:	e8 fd ef 37 00       	call   0x82ef00
  4aff03:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4aff07:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4aff0d:	74 07                	je     0x4aff16
  4aff0f:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  4aff12:	85 f6                	test   esi,esi
  4aff14:	75 12                	jne    0x4aff28
  4aff16:	68 d8 6a c0 00       	push   0xc06ad8
  4aff1b:	e8 40 dc 23 00       	call   0x6edb60
  4aff20:	83 c4 04             	add    esp,0x4
  4aff23:	e9 d2 01 00 00       	jmp    0x4b00fa
  4aff28:	66 0f be 43 ff       	movsx  ax,BYTE PTR [ebx-0x1]
  4aff2d:	8b 54 24 2e          	mov    edx,DWORD PTR [esp+0x2e]
  4aff31:	8a 4b fe             	mov    cl,BYTE PTR [ebx-0x2]
  4aff34:	66 c1 e0 0f          	shl    ax,0xf
  4aff38:	81 e2 ff 7f 00 00    	and    edx,0x7fff
  4aff3e:	66 0b c2             	or     ax,dx
  4aff41:	ba 00 80 00 00       	mov    edx,0x8000
  4aff46:	66 23 c2             	and    ax,dx
  4aff49:	66 89 44 24 2e       	mov    WORD PTR [esp+0x2e],ax
  4aff4e:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  4aff51:	66 89 7c 24 2c       	mov    WORD PTR [esp+0x2c],di
  4aff56:	33 ff                	xor    edi,edi
  4aff58:	88 4c 24 30          	mov    BYTE PTR [esp+0x30],cl
  4aff5c:	66 3b c7             	cmp    ax,di
  4aff5f:	0f 84 bb 00 00 00    	je     0x4b0020
  4aff65:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  4aff69:	66 3b cf             	cmp    cx,di
  4aff6c:	0f 84 ae 00 00 00    	je     0x4b0020
  4aff72:	0f 57 c0             	xorps  xmm0,xmm0
  4aff75:	f3 0f 2a c0          	cvtsi2ss xmm0,eax
  4aff79:	f3 0f 11 44 24 34    	movss  DWORD PTR [esp+0x34],xmm0
  4aff7f:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  4aff83:	0f 57 c0             	xorps  xmm0,xmm0
  4aff86:	f3 0f 2a c1          	cvtsi2ss xmm0,ecx
  4aff8a:	f3 0f 11 44 24 38    	movss  DWORD PTR [esp+0x38],xmm0
  4aff90:	8b 44 24 38          	mov    eax,DWORD PTR [esp+0x38]
  4aff94:	89 96 e8 00 00 00    	mov    DWORD PTR [esi+0xe8],edx
  4aff9a:	89 86 ec 00 00 00    	mov    DWORD PTR [esi+0xec],eax
  4affa0:	d9 86 e8 00 00 00    	fld    DWORD PTR [esi+0xe8]
  4affa6:	d8 a6 a0 00 00 00    	fsub   DWORD PTR [esi+0xa0]
  4affac:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  4affb0:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  4affb4:	d9 5c 24 3c          	fstp   DWORD PTR [esp+0x3c]
  4affb8:	d9 86 ec 00 00 00    	fld    DWORD PTR [esi+0xec]
  4affbe:	d8 a6        	fsub   DWORD PTR [esi+0xa4]
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
4afb27:	e8 34 f5 f5 ff       	call   0x40f060
4afb38:	e8 c3 f3 37 00       	call   0x82ef00
4afb51:	e8 0a e0 23 00       	call   0x6edb60
4afb69:	ff d2                	call   edx
4afbf6:	e8 95 f0 02 00       	call   0x4dec90
4afc00:	e8 15 27 3e 00       	call   0x89231a
4afc26:	e8 d5 f2 37 00       	call   0x82ef00
4afc43:	e8 18 df 23 00       	call   0x6edb60
4afecc:	e8 bf ed 02 00       	call   0x4dec90
4afed6:	e8 3f 24 3e 00       	call   0x89231a
4afefe:	e8 fd ef 37 00       	call   0x82ef00
4aff1b:	e8 40 dc 23 00       	call   0x6edb60
```

### 比較與跳轉（前 55 筆）

```asm
4afaf6:	83 f8 02             	cmp    eax,0x2
4afaf9:	73 04                	jae    0x4afaff
4afafd:	eb 0d                	jmp    0x4afb0c
4afb0c:	85 d2                	test   edx,edx
4afb0e:	74 64                	je     0x4afb74
4afb1b:	eb 03                	jmp    0x4afb20
4afb40:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
4afb43:	74 07                	je     0x4afb4c
4afb48:	85 c9                	test   ecx,ecx
4afb4a:	75 0f                	jne    0x4afb5b
4afb59:	eb 10                	jmp    0x4afb6b
4afb6f:	75 af                	jne    0x4afb20
4afbaf:	83 f8 02             	cmp    eax,0x2
4afbb2:	73 04                	jae    0x4afbb8
4afbb6:	eb 0d                	jmp    0x4afbc5
4afbc7:	3b d3                	cmp    edx,ebx
4afbc9:	0f 86 ab 01 00 00    	jbe    0x4afd7a
4afbdd:	eb 03                	jmp    0x4afbe2
4afbe2:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
4afbe9:	75 25                	jne    0x4afc10
4afc2f:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
4afc35:	74 07                	je     0x4afc3e
4afc3a:	3b f3                	cmp    esi,ebx
4afc3c:	75 12                	jne    0x4afc50
4afc4b:	e9 19 01 00 00       	jmp    0x4afd69
4afe8f:	83 f8 02             	cmp    eax,0x2
4afe92:	73 04                	jae    0x4afe98
4afe96:	eb 06                	jmp    0x4afe9e
4afe9e:	85 c0                	test   eax,eax
4afea0:	0f 84 65 02 00 00    	je     0x4b010b
4afeb4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
4afebb:	75 29                	jne    0x4afee6
4aff07:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
4aff0d:	74 07                	je     0x4aff16
4aff12:	85 f6                	test   esi,esi
4aff14:	75 12                	jne    0x4aff28
4aff23:	e9 d2 01 00 00       	jmp    0x4b00fa
4aff5c:	66 3b c7             	cmp    ax,di
4aff5f:	0f 84 bb 00 00 00    	je     0x4b0020
4aff69:	66 3b cf             	cmp    cx,di
4aff6c:	0f 84 ae 00 00 00    	je     0x4b0020
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