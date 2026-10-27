# T16-29 — QUESTSTATE 與 QUEST_READY 顯示物件鏈（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：兩個 UI 字串的直接引用與資料構造，禁止由 UI 反推伺服器狀態。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x00502470`–`0x00502570`（81 行）

```asm
  502470:	5c                   	pop    esp
  502471:	01 00                	add    DWORD PTR [eax],eax
  502473:	00 89 4d e4 8b 50    	add    BYTE PTR [ecx+0x508be44d],cl
  502479:	04 89                	add    al,0x89
  50247b:	55                   	push   ebp
  50247c:	e8 8b 40 08 89       	call   0x8958650c
  502481:	45                   	inc    ebp
  502482:	ec                   	in     al,dx
  502483:	33 c0                	xor    eax,eax
  502485:	3b f0                	cmp    esi,eax
  502487:	74 17                	je     0x5024a0
  502489:	39 87 70 03 00 00    	cmp    DWORD PTR [edi+0x370],eax
  50248f:	74 0f                	je     0x5024a0
  502491:	e8 6a 4c 2a 00       	call   0x7a7100
  502496:	d9 9d 54 ff ff ff    	fstp   DWORD PTR [ebp-0xac]
  50249c:	33 c0                	xor    eax,eax
  50249e:	eb 0b                	jmp    0x5024ab
  5024a0:	0f 57 c0             	xorps  xmm0,xmm0
  5024a3:	f3 0f 11 85 54 ff ff 	movss  DWORD PTR [ebp-0xac],xmm0
  5024aa:	ff 
  5024ab:	d9 85 54 ff ff ff    	fld    DWORD PTR [ebp-0xac]
  5024b1:	66 8b 7f 04          	mov    di,WORD PTR [edi+0x4]
  5024b5:	dc 05 78 5e c5 00    	fadd   QWORD PTR ds:0xc55e78
  5024bb:	83 ec 08             	sub    esp,0x8
  5024be:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  5024c1:	0f b7 d7             	movzx  edx,di
  5024c4:	d8 45 ec             	fadd   DWORD PTR [ebp-0x14]
  5024c7:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  5024ca:	c7 45 d4 98 da c0 00 	mov    DWORD PTR [ebp-0x2c],0xc0da98
  5024d1:	89 45 d8             	mov    DWORD PTR [ebp-0x28],eax
  5024d4:	d9 5d ec             	fstp   DWORD PTR [ebp-0x14]
  5024d7:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  5024da:	d9 e8                	fld1
  5024dc:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  5024df:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  5024e3:	d9 ee                	fldz
  5024e5:	d9 1c 24             	fstp   DWORD PTR [esp]
  5024e8:	51                   	push   ecx
  5024e9:	52                   	push   edx
  5024ea:	e8 51 8c f9 ff       	call   0x49b140
  5024ef:	8d 55 d0             	lea    edx,[ebp-0x30]
  5024f2:	8b c8                	mov    ecx,eax
  5024f4:	e8 27 fa 04 00       	call   0x551f20
  5024f9:	8b 43 28             	mov    eax,DWORD PTR [ebx+0x28]
  5024fc:	89 85 50 ff ff ff    	mov    DWORD PTR [ebp-0xb0],eax
  502502:	e8 89 d8 ff ff       	call   0x4ffd90
  502507:	8b f0                	mov    esi,eax
  502509:	8d 8d 50 ff ff ff    	lea    ecx,[ebp-0xb0]
  50250f:	51                   	push   ecx
  502510:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  502516:	8b ce                	mov    ecx,esi
  502518:	e8 d3 1b 07 00       	call   0x5740f0
  50251d:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  502520:	8b 85 54 ff ff ff    	mov    eax,DWORD PTR [ebp-0xac]
  502526:	3b c6                	cmp    eax,esi
  502528:	74 7f                	je     0x5025a9
  50252a:	8d 70 10             	lea    esi,[eax+0x10]
  50252d:	bf 10 00 00 00       	mov    edi,0x10
  502532:	39 7e 14             	cmp    DWORD PTR [esi+0x14],edi
  502535:	72 02                	jb     0x502539
  502537:	8b 36                	mov    esi,DWORD PTR [esi]
  502539:	85 f6                	test   esi,esi
  50253b:	74 6c                	je     0x5025a9
  50253d:	68 a4 da c0 00       	push   0xc0daa4
  502542:	8d 4d c8             	lea    ecx,[ebp-0x38]
  502545:	e8 26 06 f0 ff       	call   0x402b70
  50254a:	8b c6                	mov    eax,esi
  50254c:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  502553:	8d 50 01             	lea    edx,[eax+0x1]
  502556:	8a 08                	mov    cl,BYTE PTR [eax]
  502558:	40                   	inc    eax
  502559:	84 c9                	test   cl,cl
  50255b:	75 f9                	jne    0x502556
  50255d:	2b c2                	sub    eax,edx
  50255f:	50                   	push   eax
  502560:	56                   	push   esi
  502561:	8d 4d c8             	lea    ecx,[ebp-0x38]
  502564:	e8 57 fa ef ff       	call   0x401fc0
  502569:	8b 75 c8             	mov    esi,DWORD PTR [ebp-0x38]
  50256c:	39 7d dc             	cmp    DWORD PTR [ebp-0x24],edi
  50256f:	73                 	jae    0x502574
```

### VA `0x00502860`–`0x00502950`（68 行）

```asm
  502860:	70 0c                	jo     0x50286e
  502862:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  502869:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50286f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502872:	e8 d9 81 08 00       	call   0x58aa50
  502877:	e9 a1 02 00 00       	jmp    0x502b1d
  50287c:	33 c0                	xor    eax,eax
  50287e:	50                   	push   eax
  50287f:	e8 cc 81 08 00       	call   0x58aa50
  502884:	e9 94 02 00 00       	jmp    0x502b1d
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
  50289a:	bf 0f 00 00 00       	mov    edi,0xf
  50289f:	68 b8 da c0 00       	push   0xc0dab8
  5028a4:	8d 47 fc             	lea    eax,[edi-0x4]
  5028a7:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5028aa:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5028ad:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  5028b0:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  5028b4:	e8 57 8a f0 ff       	call   0x40b310
  5028b9:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5028bc:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  5028c3:	75 21                	jne    0x5028e6
  5028c5:	83 0d d4 b0 fa 00 01 	or     DWORD PTR ds:0xfab0d4,0x1
  5028cc:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  5028d0:	e8 cb 7a 30 00       	call   0x80a3a0
  5028d5:	68 d0 cd bc 00       	push   0xbccdd0
  5028da:	e8 3b fa 38 00       	call   0x89231a
  5028df:	83 c4 04             	add    esp,0x4
  5028e2:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  5028e6:	68 28 b0 fa 00       	push   0xfab028
  5028eb:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5028ee:	e8 0d 82 30 00       	call   0x80ab00
  5028f3:	3b c6                	cmp    eax,esi
  5028f5:	74 09                	je     0x502900
  5028f7:	8b 10                	mov    edx,DWORD PTR [eax]
  5028f9:	8b c8                	mov    ecx,eax
  5028fb:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5028fe:	ff d0                	call   eax
  502900:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  502907:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  50290b:	72 0c                	jb     0x502919
  50290d:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  502910:	51                   	push   ecx
  502911:	e8 f6 e8 38 00       	call   0x89120c
  502916:	83 c4 04             	add    esp,0x4
  502919:	68 c4 00 00 00       	push   0xc4
  50291e:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  502921:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  502924:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  502928:	e8 3b e9 38 00       	call   0x891268
  50292d:	83 c4 04             	add    esp,0x4
  502930:	89 45 98             	mov    DWORD PTR [ebp-0x68],eax
  502933:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  50293a:	3b c6                	cmp    eax,esi
  50293c:	74 17                	je     0x502955
  50293e:	83 7b 60 08          	cmp    DWORD PTR [ebx+0x60],0x8
  502942:	8d 4b 4c             	lea    ecx,[ebx+0x4c]
  502945:	72 02                	jb     0x502949
  502947:	8b 09                	mov    ecx,DWORD PTR [ecx]
  502949:	6a 02                	push   0x2
  50294b:	51                   	push   ecx
  50294c:	8b f0                	mov    esi,eax
  50294e:	e8 9d          	call   0x5016f0
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
50247c:	e8 8b 40 08 89       	call   0x8958650c
502491:	e8 6a 4c 2a 00       	call   0x7a7100
5024ea:	e8 51 8c f9 ff       	call   0x49b140
5024f4:	e8 27 fa 04 00       	call   0x551f20
502502:	e8 89 d8 ff ff       	call   0x4ffd90
502518:	e8 d3 1b 07 00       	call   0x5740f0
502545:	e8 26 06 f0 ff       	call   0x402b70
502564:	e8 57 fa ef ff       	call   0x401fc0
502872:	e8 d9 81 08 00       	call   0x58aa50
50287f:	e8 cc 81 08 00       	call   0x58aa50
50288e:	e8 ad 06 f2 ff       	call   0x422f40
502895:	e8 c6 ee 05 00       	call   0x561760
5028b4:	e8 57 8a f0 ff       	call   0x40b310
5028d0:	e8 cb 7a 30 00       	call   0x80a3a0
5028da:	e8 3b fa 38 00       	call   0x89231a
5028ee:	e8 0d 82 30 00       	call   0x80ab00
5028fe:	ff d0                	call   eax
502911:	e8 f6 e8 38 00       	call   0x89120c
502928:	e8 3b e9 38 00       	call   0x891268
50294e:	e8 9d          	call   0x5016f0
```

### 比較與跳轉（前 55 筆）

```asm
502485:	3b f0                	cmp    esi,eax
502487:	74 17                	je     0x5024a0
502489:	39 87 70 03 00 00    	cmp    DWORD PTR [edi+0x370],eax
50248f:	74 0f                	je     0x5024a0
50249e:	eb 0b                	jmp    0x5024ab
502526:	3b c6                	cmp    eax,esi
502528:	74 7f                	je     0x5025a9
502532:	39 7e 14             	cmp    DWORD PTR [esi+0x14],edi
502535:	72 02                	jb     0x502539
502539:	85 f6                	test   esi,esi
50253b:	74 6c                	je     0x5025a9
502559:	84 c9                	test   cl,cl
50255b:	75 f9                	jne    0x502556
50256c:	39 7d dc             	cmp    DWORD PTR [ebp-0x24],edi
50256f:	73                 	jae    0x502574
502877:	e9 a1 02 00 00       	jmp    0x502b1d
502884:	e9 94 02 00 00       	jmp    0x502b1d
5028bc:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
5028c3:	75 21                	jne    0x5028e6
5028f3:	3b c6                	cmp    eax,esi
5028f5:	74 09                	je     0x502900
502907:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
50290b:	72 0c                	jb     0x502919
50293a:	3b c6                	cmp    eax,esi
50293c:	74 17                	je     0x502955
50293e:	83 7b 60 08          	cmp    DWORD PTR [ebx+0x60],0x8
502945:	72 02                	jb     0x502949
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