# T16-25 — 封包預設處理器與任務業務分派邊界（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：查預設處理器是否直接解析任務 payload；handler 表地址不等於任務 opcode。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x004B7D30`–`0x004B7E70`（104 行）

```asm
  4b7d30:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d32:	ff 60 08             	jmp    DWORD PTR [eax+0x8]
  4b7d35:	cc                   	int3
  4b7d36:	cc                   	int3
  4b7d37:	cc                   	int3
  4b7d38:	cc                   	int3
  4b7d39:	cc                   	int3
  4b7d3a:	cc                   	int3
  4b7d3b:	cc                   	int3
  4b7d3c:	cc                   	int3
  4b7d3d:	cc                   	int3
  4b7d3e:	cc                   	int3
  4b7d3f:	cc                   	int3
  4b7d40:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
  4b7d45:	cc                   	int3
  4b7d46:	cc                   	int3
  4b7d47:	cc                   	int3
  4b7d48:	cc                   	int3
  4b7d49:	cc                   	int3
  4b7d4a:	cc                   	int3
  4b7d4b:	cc                   	int3
  4b7d4c:	cc                   	int3
  4b7d4d:	cc                   	int3
  4b7d4e:	cc                   	int3
  4b7d4f:	cc                   	int3
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7       	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	   
```

### VA `0x004B7D40`–`0x004B7E80`（94 行）

```asm
  4b7d40:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
  4b7d45:	cc                   	int3
  4b7d46:	cc                   	int3
  4b7d47:	cc                   	int3
  4b7d48:	cc                   	int3
  4b7d49:	cc                   	int3
  4b7d4a:	cc                   	int3
  4b7d4b:	cc                   	int3
  4b7d4c:	cc                   	int3
  4b7d4d:	cc                   	int3
  4b7d4e:	cc                   	int3
  4b7d4f:	cc                   	int3
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7 05 e4 31 fd 00 60 	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	9c 4b 00 
  4b7e79:	89 0d e8 31 fd 00    	mov    DWORD PTR ds:0xfd31e8,ecx
  4b7e7f:	c7       	mov    DWORD PTR ds:0xfd34d4,0x4b9d30
  4b7e86:	   
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
4b7d6e:	ff d2                	call   edx
4b7d80:	ff d2                	call   edx
4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
4b7dbc:	ff d2                	call   edx
4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
4b7d6e:	ff d2                	call   edx
4b7d80:	ff d2                	call   edx
4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
4b7dbc:	ff d2                	call   edx
```

### 比較與跳轉（前 55 筆）

```asm
4b7d32:	ff 60 08             	jmp    DWORD PTR [eax+0x8]
4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
4b7d51:	85 ff                	test   edi,edi
4b7d53:	75 0a                	jne    0x4b7d5f
4b7d65:	85 c9                	test   ecx,ecx
4b7d67:	74 23                	je     0x4b7d8c
4b7d76:	85 c9                	test   ecx,ecx
4b7d78:	74 12                	je     0x4b7d8c
4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
4b7d51:	85 ff                	test   edi,edi
4b7d53:	75 0a                	jne    0x4b7d5f
4b7d65:	85 c9                	test   ecx,ecx
4b7d67:	74 23                	je     0x4b7d8c
4b7d76:	85 c9                	test   ecx,ecx
4b7d78:	74 12                	je     0x4b7d8c
4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
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