# T16-23 — QuestInfo 與 QuestTalk 表格讀取、資料來源阻塞

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. XML file names have direct code references; actual external XML resources not supplied。證據分級：局部程式碼已確認、任務業務語義未確認。
2. quest IDs, stages, NPCs and early mainline prerequisites remain unknown。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x00504740`–`0x00504900`（110 條可解析行；原始 bytes 位於每行 instruction 欄）

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
  50489b:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  5048a2:	00 
  5048a3:	e8 98 97 22 00       	call   0x72e040
  5048a8:	33 c0                	xor    eax,eax
  5048aa:	e9 29 0c 00 00       	jmp    0x5054d8
  5048af:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  5048b2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5048b6:	3b c7                	cmp    eax,edi
  5048b8:	0f 84 c0 0b 00 00    	je     0x50547e
  5048be:	8b ff                	mov    edi,edi
  5048c0:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  5048c4:	51                   	push   ecx
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5048ce:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5048d5:	01 
  5048d6:	8b 11                	mov    edx,DWORD PTR [ecx]
  5048d8:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5048db:	ff d0                	call   eax
  5048dd:	8d 78 44             	lea    edi,[eax+0x44]
  5048e0:	68 d0 d1 be 00       	push   0xbed1d0
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  5048ea:	bb 10 00 00 00       	mov    ebx,0x10
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f3:	83 c0 30             	add    eax,0x30
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74                 	je     0x50490c
```

### VA `0x00505570`–`0x00505720`（116 條可解析行；原始 bytes 位於每行 instruction 欄）

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
  5056ce:	e8 cd a9 22 00       	call   0x7300a0
  5056d3:	3b c3                	cmp    eax,ebx
  5056d5:	74 1a                	je     0x5056f1
  5056d7:	83 c0 30             	add    eax,0x30
  5056da:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5056de:	72 02                	jb     0x5056e2
  5056e0:	8b 00                	mov    eax,DWORD PTR [eax]
  5056e2:	3b c3                	cmp    eax,ebx
  5056e4:	74 0b                	je     0x5056f1
  5056e6:	50                   	push   eax
  5056e7:	e8 c8 c0 38 00       	call   0x8917b4
  5056ec:	83 c4 04             	add    esp,0x4
  5056ef:	eb 02                	jmp    0x5056f3
  5056f1:	33 c0                	xor    eax,eax
  5056f3:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5056f7:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  5056fb:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  5056ff:	51                   	push   ecx
  505700:	8d 44 24 20          	lea    eax,[esp+0x20]
  505704:	8b ce                	mov    ecx,esi
  505706:	e8 15 e6 ff ff       	call   0x503d20
  50570b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  50570f:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  505712:	0f 84 92 00 00 00    	je     0x5057aa
  505718:	8d 71 10             	lea    esi,[ecx+0x10]
  50571b:	3b f3                	cmp    esi,ebx
  50571d:	0f 84 87       	je     0x5057aa
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x504794` | call | `0x72ee30` |
| `0x5047c6` | call | `0x72f110` |
| `0x5047fc` | call | `0x89120c` |
| `0x504825` | call | `0x72e040` |
| `0x50482c` | jmp | `0x5054d8` |
| `0x50483d` | call | `0x72e2e0` |
| `0x50484b` | call | `0x6edb60` |
| `0x50487a` | call | `0x89120c` |
| `0x5048a3` | call | `0x72e040` |
| `0x5048aa` | jmp | `0x5054d8` |
| `0x5048c5` | call | `0x4ff920` |
| `0x5048e5` | call | `0x7300a0` |
| `0x5055c1` | call | `0x72ee30` |
| `0x5055e7` | call | `0x72f110` |
| `0x505613` | call | `0x89120c` |
| `0x505635` | call | `0x72e040` |
| `0x50563c` | jmp | `0x50582d` |
| `0x50564a` | call | `0x72e2e0` |
| `0x505658` | call | `0x6edb60` |
| `0x505681` | call | `0x89120c` |
| `0x5056a3` | call | `0x72e040` |
| `0x5056aa` | jmp | `0x50582d` |
| `0x5056af` | call | `0x506a30` |
| `0x5056c0` | jmp | `0x5056c6` |
| `0x5056ce` | call | `0x7300a0` |
| `0x5056e7` | call | `0x8917b4` |
| `0x5056ef` | jmp | `0x5056f3` |
| `0x505706` | call | `0x503d20` |

## 資料流與局部偽碼（抽象表示；不冒充正式 class/function 名稱）

```cpp
// 每個 node/packet 的實際型別、生命週期、寫入者未證實；務必以下方 BIN 指令為準。
void native_window_observation_unknown(Context *ctx) {
    // Inspect the branch/call edges in the assembly windows above.
    // Do not map unknown payload to player quest-state without evidence.
}
```

## 證據政策及跨 Task 責任
- KR：直接唯讀解析原始 x86 PE32 BIN；不執行、不修改遊戲。任何位址均為 KR VA。
- T02 分派框架、T03 登入、T04 創角初始化、T07 場景、T14 勝敗結算、T15 保存機制仍為各自任務主責。T16 只研究任務業務語義與介面；不修改他人 owner/catalog。
- 原生已確認 = 對應 bytes / 指令確實存在；部分確認 = 控制流程尚未閉環；合理推測 = 待測；資訊缺失 = 無法取得資源或證據。不得把歷史 AI/fixture 或 `005F type6` 修補當原版事實。
- KR 任務 Lua/XML 正文未提供；TC 原生檔未提供，TC SHA 只使用 GitHub `shared/targets.json` 登記，不轉用 KR VA/ID/判斷。

## tutorial-node-matrix / early-mainline-flow / KR–TC 差異
| 流程節點 | KR 原生入口或資料線索 | 觸發條件 | 原版 server writer | 回覆／UI | 下一狀態 | TC 同項 |
|---|---|---|---|---|---|---|
| Tutorial 腳本路徑 | `Event/TutorialMain.lua` / `Tutorial_EntryPoint` | unknown | unknown | unknown | unknown | unknown |
| Synopsis | `Synopsis_EntryPoint` | unknown | unknown | unknown | unknown | unknown |
| Quest 定義 | `Table/QuestInfo.xml` 路徑 | unknown | unknown | unknown | unknown | unknown |
| NPC/對話候選 | `Table/QuestTalk.xml` 路徑 | unknown | unknown | unknown | unknown | unknown |
| 教學完成→首主線 | 未定位原生閉環 | unknown | unknown | unknown | unknown | unknown |

**重要反證：** 客戶端載入 Lua、索引 XML 或顯示 `QUEST_READY` 皆不足以斷定官方後端曾接受、寫入及持久化任務進度。TC 原生功能無法對照，不能以 KR 推定相同。

## source-inventory / evidence-level

| version | source | SHA / status | evidence |
|---|---|---|---|
| KR | Original BIN | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | current direct bytes/assembly |
| KR | Lua/XML external content | 未取得 | 路徑引用不代表原始檔內容存在 |
| KR | historical notification/fixture | GitHub 索引/前批技術筆記 | 僅線索；未據此推定 native Quest 規則 |
| TC | `shared/targets.json` 中候選映像 | `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`（未直接驗證） | 不得跨版套地址 |

## cross-task-interfaces / acceptance-matrix

| 接口 / 驗收 | 本段結論 | 待 T16 查核 |
|---|---|---|
| T02 → T16 packet | frame/dispatch 仍需業務鍵值與 payload 證明 | quest message command、原版 payload schema |
| T03/T04 → T16 | 已有角色為輸入，不重做角色初值 | tutorial state source and conditions |
| T07/T14 → T16 | 任務對關卡結果的消費未驗證 | result event→quest writer |
| T15 ↔ T16 | 原版持久化未驗證 | per-character flags and relogged snapshot |
| KR 原生技術分析 | 上列指定窗口機器碼直接確認 | 延伸 CFG 和呼叫者映射 |
| 原版端到端教學可玩 | 未測試、不可聲稱完成 | 封包重放與後端原版證據 |

## 未解項目與下一步

- 沿分派表找到確定的 quest command/handler，再核對 packet 欄位來源、長度和狀態寫入；不能用 QUEST READY 字串推定。
- 取得原版 Lua/XML 真實內容，抽取教學節點／QuestInfo ID 與 NPC、對話／前置條件。
- 確認 server acknowledgement → client field consumer → next progression，依任務記錄 writer/reader；必要時引用 T02/T14/T15 已登記主責。
- 如果該片段僅反映共用初始化/容器，保留非任務反證，不繼續無界泛化。

## GitHub 狀態
本原稿於提交之前生成；實際遠端 commit SHA 以提交後驗證結果為準。
