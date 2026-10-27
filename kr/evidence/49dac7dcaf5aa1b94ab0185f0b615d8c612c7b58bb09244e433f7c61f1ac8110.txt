# T16-31 — Synopsis／Tutorial 腳本入口的轉移條件（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：保留 0xFBA798 未命名旗標與 Lua 入口連線，未取得腳本時不猜教學步驟。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x004A89A0`–`0x004A8A65`（60 行）

```asm
  4a89a0:	2e 00 00             	add    BYTE PTR cs:[eax],al
  4a89a3:	50                   	push   eax
  4a89a4:	e8 f7 2e 00 00       	call   0x4ab8a0
  4a89a9:	50                   	push   eax
  4a89aa:	e8 91 2f 00 00       	call   0x4ab940
  4a89af:	68 64 68 c0 00       	push   0xc06864
  4a89b4:	8b ce                	mov    ecx,esi
  4a89b6:	e8 95 c0 24 00       	call   0x6f4a50
  4a89bb:	8b e5                	mov    esp,ebp
  4a89bd:	5d                   	pop    ebp
  4a89be:	c3                   	ret
  4a89bf:	cc                   	int3
  4a89c0:	55                   	push   ebp
  4a89c1:	8b ec                	mov    ebp,esp
  4a89c3:	6a ff                	push   0xffffffff
  4a89c5:	68 7e a4 93 00       	push   0x93a47e
  4a89ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a89d0:	50                   	push   eax
  4a89d1:	57                   	push   edi
  4a89d2:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a89d7:	33 c5                	xor    eax,ebp
  4a89d9:	50                   	push   eax
  4a89da:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a89dd:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a89e3:	8d 7e 14             	lea    edi,[esi+0x14]
  4a89e6:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a89ed:	00 00 00 
  4a89f0:	e8 2b 8a 3a 00       	call   0x851420
  4a89f5:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  4a89fc:	75 27                	jne    0x4a8a25
  4a89fe:	83 0d 54 73 fb 00 01 	or     DWORD PTR ds:0xfb7354,0x1
  4a8a05:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8a0c:	e8 bf a9 0a 00       	call   0x5533d0
  4a8a11:	68 00 d1 bc 00       	push   0xbcd100
  4a8a16:	e8 ff 98 3e 00       	call   0x89231a
  4a8a1b:	83 c4 04             	add    esp,0x4
  4a8a1e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a8a25:	c7 05 b4 73 fb 00 01 	mov    DWORD PTR ds:0xfb73b4,0x1
  4a8a2c:	00 00 00 
  4a8a2f:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8a31:	68 7c 68 c0 00       	push   0xc0687c
  4a8a36:	e8 15 c0 24 00       	call   0x6f4a50
  4a8a3b:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8a3d:	6a 00                	push   0x0
  4a8a3f:	6a 00                	push   0x0
  4a8a41:	68 94 68 c0 00       	push   0xc06894
  4a8a46:	e8 85 c3 24 00       	call   0x6f4dd0
  4a8a4b:	83 c4 0c             	add    esp,0xc
  4a8a4e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8a51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8a58:	59                   	pop    ecx
  4a8a59:	5f                   	pop    edi
  4a8a5a:	8b e5                	mov    esp,ebp
  4a8a5c:	5d                   	pop    ebp
  4a8a5d:	c3                   	ret
  4a8a5e:	cc                   	int3
  4a8a5f:	cc                   	int3
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
```

### VA `0x004A8A60`–`0x004A8B96`（89 行）

```asm
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
  4a8a74:	53                   	push   ebx
  4a8a75:	57                   	push   edi
  4a8a76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8a7b:	33 c5                	xor    eax,ebp
  4a8a7d:	50                   	push   eax
  4a8a7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a8a81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8a87:	8d 7e 04             	lea    edi,[esi+0x4]
  4a8a8a:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a8a91:	00 00 00 
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a99:	8d 7e 14             	lea    edi,[esi+0x14]
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8aa1:	bb 01 00 00 00       	mov    ebx,0x1
  4a8aa6:	83 cf ff             	or     edi,0xffffffff
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ab1:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a8ab7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac3:	68 00 d1 bc 00       	push   0xbcd100
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8acd:	83 c4 04             	add    esp,0x4
  4a8ad0:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8ad3:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8ae1:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4a8ae7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8aef:	68 c0 cc bc 00       	push   0xbcccc0
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8af9:	83 c4 04             	add    esp,0x4
  4a8afc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
  4a8b7c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8b7f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8b86:	59                   	pop    ecx
  4a8b87:	5f                   	pop    edi
  4a8b88:	5b                   	pop    ebx
  4a8b89:	8b e5                	mov    esp,ebp
  4a8b8b:	5d                   	pop    ebp
  4a8b8c:	c3                   	ret
  4a8b8d:	cc                   	int3
  4a8b8e:	cc                   	int3
  4a8b8f:	cc                   	int3
  4a8b90:	55                   	push   ebp
  4a8b91:	8b ec                	mov    ebp,esp
  4a8b93:	83 ec 18             	sub    esp,0x18
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
4a89a4:	e8 f7 2e 00 00       	call   0x4ab8a0
4a89aa:	e8 91 2f 00 00       	call   0x4ab940
4a89b6:	e8 95 c0 24 00       	call   0x6f4a50
4a89f0:	e8 2b 8a 3a 00       	call   0x851420
4a8a0c:	e8 bf a9 0a 00       	call   0x5533d0
4a8a16:	e8 ff 98 3e 00       	call   0x89231a
4a8a36:	e8 15 c0 24 00       	call   0x6f4a50
4a8a46:	e8 85 c3 24 00       	call   0x6f4dd0
4a8a94:	e8 b7 ad 37 00       	call   0x823850
4a8a9c:	e8 7f 89 3a 00       	call   0x851420
4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
4a8aea:	e8 91 e9 0d 00       	call   0x587480
4a8af4:	e8 21 98 3e 00       	call   0x89231a
4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
4a8b5b:	ff d2                	call   edx
4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
```

### 比較與跳轉（前 55 筆）

```asm
4a89f5:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
4a89fc:	75 27                	jne    0x4a8a25
4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
4a8aaf:	75 22                	jne    0x4a8ad3
4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
4a8adf:	75 1e                	jne    0x4a8aff
4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
4a8b0a:	74 07                	je     0x4a8b13
4a8b11:	eb 05                	jmp    0x4a8b18
4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
4a8b1e:	75 13                	jne    0x4a8b33
4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
4a8b46:	75 15                	jne    0x4a8b5d
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