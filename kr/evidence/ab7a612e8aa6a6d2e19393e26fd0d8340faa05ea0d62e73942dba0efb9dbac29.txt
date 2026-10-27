# T16-32 — QuestInfo／QuestTalk 載入器與主線驗收缺口（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：將 XML 載入器同封包／Lua／UI 觀察比較；證據不足時明示主線與任務權威阻塞。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x00504740`–`0x005048A0`（81 行）

```asm
  504740:	55                   	push   ebp
  504741:	8b ec                	mov    ebp,esp
  504743:	83 e4 f8             	and    esp,0xfffffff8
  504746:	6a ff                	push   0xffffffff
  504748:	68 3d 42 92 00       	push   0x92423d
  50474d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504753:	50                   	push   eax
  504754:	81 ec 48 02 00 00    	sub    esp,0x248
  50475a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50475f:	33 c4                	xor    eax,esp
  504761:	89 84 24 40 02 00 00 	mov    DWORD PTR [esp+0x240],eax
  504768:	53                   	push   ebx
  504769:	56                   	push   esi
  50476a:	57                   	push   edi
  50476b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  504770:	33 c4                	xor    eax,esp
  504772:	50                   	push   eax
  504773:	8d 84 24 58 02 00 00 	lea    eax,[esp+0x258]
  50477a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84 24 64 02 00 00 	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	ff ff ff ff 
  50485b:	83 c4 04             	add    esp,0x4
  50485e:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  504865:	94 23 bf 00 
  504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  504870:	72 10                	jb     0x504882
  504872:	8b 84 24 78 01 00 00 	mov    eax,DWORD PTR [esp+0x178]
  504879:	50                   	push   eax
  50487a:	e8 8d c9 38 00       	call   0x89120c
  50487f:	83 c4 04             	add    esp,0x4
  504882:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  504889:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504890:	0f 00 00 00 
  504894:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50489b:	c6 84 24 78 01   	mov    BYTE PTR [esp+0x178],0x0
  5048a2:	 
```

### VA `0x00505570`–`0x005056D0`（90 行）

```asm
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e 00       	call   0x6edb60
  50565d:	c7 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],0xffffffff
  505664:	ff ff ff ff 
  505668:	83 c4 04             	add    esp,0x4
  50566b:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505672:	00 
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50567a:	72 0d                	jb     0x505689
  50567c:	8b 44 24 70          	mov    eax,DWORD PTR [esp+0x70]
  505680:	50                   	push   eax
  505681:	e8 86 bb 38 00       	call   0x89120c
  505686:	83 c4 04             	add    esp,0x4
  505689:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50568d:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505694:	0f 00 00 00 
  505698:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  50569f:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  5056a3:	e8 98 89 22 00       	call   0x72e040
  5056a8:	33 c0                	xor    eax,eax
  5056aa:	e9 7e 01 00 00       	jmp    0x50582d
  5056af:	e8 7c 13 00 00       	call   0x506a30
  5056b4:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5056b8:	3b c3                	cmp    eax,ebx
  5056ba:	0f 84 20 01 00 00    	je     0x5057e0
  5056c0:	eb 04                	jmp    0x5056c6
  5056c2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5056c6:	8d 78 44             	lea    edi,[eax+0x44]
  5056c9:	68 d0 d1 be 00       	push   0xbed1d0
  5056ce:	e8 cd          	call   0x7300a0
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
504794:	e8 97 a6 22 00       	call   0x72ee30
5047c6:	e8 45 a9 22 00       	call   0x72f110
5047fc:	e8 0b ca 38 00       	call   0x89120c
504825:	e8 16 98 22 00       	call   0x72e040
50483d:	e8 9e 9a 22 00       	call   0x72e2e0
50484b:	e8 10 93 1e 00       	call   0x6edb60
50487a:	e8 8d c9 38 00       	call   0x89120c
5055c1:	e8 6a 98 22 00       	call   0x72ee30
5055e7:	e8 24 9b 22 00       	call   0x72f110
505613:	e8 f4 bb 38 00       	call   0x89120c
505635:	e8 06 8a 22 00       	call   0x72e040
50564a:	e8 91 8c 22 00       	call   0x72e2e0
505658:	e8 03 85 1e 00       	call   0x6edb60
505681:	e8 86 bb 38 00       	call   0x89120c
5056a3:	e8 98 89 22 00       	call   0x72e040
5056af:	e8 7c 13 00 00       	call   0x506a30
5056ce:	e8 cd          	call   0x7300a0
```

### 比較與跳轉（前 55 筆）

```asm
5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
5047b5:	73 07                	jae    0x5047be
5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
5047d3:	74 5c                	je     0x504831
5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
5047f2:	72 10                	jb     0x504804
50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
504842:	3b c7                	cmp    eax,edi
504844:	75 69                	jne    0x5048af
504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
504870:	72 10                	jb     0x504882
5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
5055dc:	73 04                	jae    0x5055e2
5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
5055f0:	74 4f                	je     0x505641
505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
50560c:	72 0d                	jb     0x50561b
50563c:	e9 ec 01 00 00       	jmp    0x50582d
50564f:	3b c3                	cmp    eax,ebx
505651:	75 5c                	jne    0x5056af
505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
50567a:	72 0d                	jb     0x505689
5056aa:	e9 7e 01 00 00       	jmp    0x50582d
5056b8:	3b c3                	cmp    eax,ebx
5056ba:	0f 84 20 01 00 00    	je     0x5057e0
5056c0:	eb 04                	jmp    0x5056c6
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