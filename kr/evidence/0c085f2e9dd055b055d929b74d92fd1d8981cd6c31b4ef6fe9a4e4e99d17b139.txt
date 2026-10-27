# T16-19 — 客戶端封包分派與關聯 callback 邊界

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. need match event code, payload size, role context and actual mutation before assigning quest authority。證據分級：局部程式碼已確認、任務業務語義未確認。
2. handler call path alone does not prove quest completion。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x004C4670`–`0x004C4810`（140 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
  4c46f0:	8b c6                	mov    eax,esi
  4c46f2:	e8 59 96 fe ff       	call   0x4add50
  4c46f7:	68 a8 5e 00 00       	push   0x5ea8
  4c46fc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4702:	6a 00                	push   0x0
  4c4704:	50                   	push   eax
  4c4705:	c7 06 b4 73 c0 00    	mov    DWORD PTR [esi],0xc073b4
  4c470b:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x53434546
  4c4712:	45 43 53 
  4c4715:	e8 46 a1 3d 00       	call   0x89e860
  4c471a:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c471f:	89 86 50 5f 00 00    	mov    DWORD PTR [esi+0x5f50],eax
  4c4725:	89 86 20 5f 00 00    	mov    DWORD PTR [esi+0x5f20],eax
  4c472b:	83 c4 0c             	add    esp,0xc
  4c472e:	c7 86 4c 5f 00 00 30 	mov    DWORD PTR [esi+0x5f4c],0x4c5930
  4c4735:	59 4c 00 
  4c4738:	c7 86 1c 5f 00 00 40 	mov    DWORD PTR [esi+0x5f1c],0x436c40
  4c473f:	6c 43 00 
  4c4742:	8b c6                	mov    eax,esi
  4c4744:	c3                   	ret
  4c4745:	cc                   	int3
  4c4746:	cc                   	int3
  4c4747:	cc                   	int3
  4c4748:	cc                   	int3
  4c4749:	cc                   	int3
  4c474a:	cc                   	int3
  4c474b:	cc                   	int3
  4c474c:	cc                   	int3
  4c474d:	cc                   	int3
  4c474e:	cc                   	int3
  4c474f:	cc                   	int3
  4c4750:	55                   	push   ebp
  4c4751:	8b ec                	mov    ebp,esp
  4c4753:	83 e4 f8             	and    esp,0xfffffff8
  4c4756:	6a ff                	push   0xffffffff
  4c4758:	68 67 6b 93 00       	push   0x936b67
  4c475d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4763:	50                   	push   eax
  4c4764:	83 ec 08             	sub    esp,0x8
  4c4767:	57                   	push   edi
  4c4768:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c476d:	33 c4                	xor    eax,esp
  4c476f:	50                   	push   eax
  4c4770:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c4774:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c477a:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4c4781:	75 29                	jne    0x4c47ac
  4c4783:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4c478a:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4c4791:	00 
  4c4792:	e8 f9 a4 01 00       	call   0x4dec90
  4c4797:	68 30 ce bc 00       	push   0xbcce30
  4c479c:	e8 79 db 3c 00       	call   0x89231a
  4c47a1:	83 c4 04             	add    esp,0x4
  4c47a4:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4c47ab:	ff 
  4c47ac:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c47b2:	85 c9                	test   ecx,ecx
  4c47b4:	74 2b                	je     0x4c47e1
  4c47b6:	83 3d ac a7 fb 00 03 	cmp    DWORD PTR ds:0xfba7ac,0x3
  4c47bd:	75 09                	jne    0x4c47c8
  4c47bf:	8b f9                	mov    edi,ecx
  4c47c1:	e8 8a 07 08 00       	call   0x544f50
  4c47c6:	eb 56                	jmp    0x4c481e
  4c47c8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c47ca:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4c47cd:	ff d2                	call   edx
  4c47cf:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c47d5:	85 c9                	test   ecx,ecx
  4c47d7:	74 08                	je     0x4c47e1
  4c47d9:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c47db:	8b 10                	mov    edx,DWORD PTR [eax]
  4c47dd:	6a 01                	push   0x1
  4c47df:	ff d2                	call   edx
  4c47e1:	68 c8 00 00 00       	push   0xc8
  4c47e6:	e8 7d ca 3c 00       	call   0x891268
  4c47eb:	83 c4 04             	add    esp,0x4
  4c47ee:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  4c47f2:	c7 44 24 18 03 00 00 	mov    DWORD PTR [esp+0x18],0x3
  4c47f9:	00 
  4c47fa:	85 c0                	test   eax,eax
  4c47fc:	74 08                	je     0x4c4806
  4c47fe:	50                   	push   eax
  4c47ff:	e8 8c 2b 08 00       	call   0x547390
  4c4804:	eb 02                	jmp    0x4c4808
  4c4806:	33 c0                	xor    eax,eax
  4c4808:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4c480f:	ff 
```

### VA `0x004B2730`–`0x004B2860`（78 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  4b2730:	55                   	push   ebp
  4b2731:	8b ec                	mov    ebp,esp
  4b2733:	83 e4 f8             	and    esp,0xfffffff8
  4b2736:	6a ff                	push   0xffffffff
  4b2738:	68 4e 6d 93 00       	push   0x936d4e
  4b273d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2743:	50                   	push   eax
  4b2744:	83 ec 18             	sub    esp,0x18
  4b2747:	53                   	push   ebx
  4b2748:	56                   	push   esi
  4b2749:	57                   	push   edi
  4b274a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b274f:	33 c4                	xor    eax,esp
  4b2751:	50                   	push   eax
  4b2752:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b2756:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b275c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b275f:	83 f8 02             	cmp    eax,0x2
  4b2762:	73 04                	jae    0x4b2768
  4b2764:	33 d2                	xor    edx,edx
  4b2766:	eb 0d                	jmp    0x4b2775
  4b2768:	8d 48 fe             	lea    ecx,[eax-0x2]
  4b276b:	b8 ab aa aa aa       	mov    eax,0xaaaaaaab
  4b2770:	f7 e1                	mul    ecx
  4b2772:	c1 ea 03             	shr    edx,0x3
  4b2775:	85 d2                	test   edx,edx
  4b2777:	0f 84 2f 01 00 00    	je     0x4b28ac
  4b277d:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b2780:	83 c6 04             	add    esi,0x4
  4b2783:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  4b2787:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b278e:	75 29                	jne    0x4b27b9
  4b2790:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b2797:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b279e:	00 
  4b279f:	e8 ec c4 02 00       	call   0x4dec90
  4b27a4:	68 30 ce bc 00       	push   0xbcce30
  4b27a9:	e8 6c fb 3d 00       	call   0x89231a
  4b27ae:	83 c4 04             	add    esp,0x4
  4b27b1:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b27b8:	ff 
  4b27b9:	0f b7 56 fe          	movzx  edx,WORD PTR [esi-0x2]
  4b27bd:	8d 44 24 14          	lea    eax,[esp+0x14]
  4b27c1:	50                   	push   eax
  4b27c2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4b27c6:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4b27cb:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4b27cf:	e8 2c c7 37 00       	call   0x82ef00
  4b27d4:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4b27d8:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4b27de:	0f 84 bb 00 00 00    	je     0x4b289f
  4b27e4:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b27e7:	85 c0                	test   eax,eax
  4b27e9:	0f 84 b0 00 00 00    	je     0x4b289f
  4b27ef:	83 b8 a8 03 00 00 00 	cmp    DWORD PTR [eax+0x3a8],0x0
  4b27f6:	0f 57 c0             	xorps  xmm0,xmm0
  4b27f9:	8a 98 b0 00 00 00    	mov    bl,BYTE PTR [eax+0xb0]
  4b27ff:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4b2805:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4b2809:	89 88 d8 00 00 00    	mov    DWORD PTR [eax+0xd8],ecx
  4b280f:	f3 0f 11 44 24 20    	movss  DWORD PTR [esp+0x20],xmm0
  4b2815:	8b 54 24 20          	mov    edx,DWORD PTR [esp+0x20]
  4b2819:	89 90 dc 00 00 00    	mov    DWORD PTR [eax+0xdc],edx
  4b281f:	8b 16                	mov    edx,DWORD PTR [esi]
  4b2821:	0f b7 4e 08          	movzx  ecx,WORD PTR [esi+0x8]
  4b2825:	89 90 c0 00 00 00    	mov    DWORD PTR [eax+0xc0],edx
  4b282b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  4b282e:	89 90 c4 00 00 00    	mov    DWORD PTR [eax+0xc4],edx
  4b2834:	89 88 c8 00 00 00    	mov    DWORD PTR [eax+0xc8],ecx
  4b283a:	c7 80 d4 00 00 00 01 	mov    DWORD PTR [eax+0xd4],0x1
  4b2841:	00 00 00 
  4b2844:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4b2846:	89 88 e8 00 00 00    	mov    DWORD PTR [eax+0xe8],ecx
  4b284c:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  4b284f:	89 90 ec 00 00 00    	mov    DWORD PTR [eax+0xec],edx
  4b2855:	75 48                	jne    0x4b289f
  4b2857:	83 b8 70 03 00 00 00 	cmp    DWORD PTR [eax+0x370],0x0
  4b285e:	88 98        	mov    BYTE PTR [eax+0x3a4],bl
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x4c4694` | call | `0x4fda30` |
| `0x4c46af` | call | `0x8928be` |
| `0x4c46df` | call | `0x6edb60` |
| `0x4c46f2` | call | `0x4add50` |
| `0x4c4715` | call | `0x89e860` |
| `0x4c4792` | call | `0x4dec90` |
| `0x4c479c` | call | `0x89231a` |
| `0x4c47c1` | call | `0x544f50` |
| `0x4c47c6` | jmp | `0x4c481e` |
| `0x4c47e6` | call | `0x891268` |
| `0x4c47ff` | call | `0x547390` |
| `0x4c4804` | jmp | `0x4c4808` |
| `0x4b2766` | jmp | `0x4b2775` |
| `0x4b279f` | call | `0x4dec90` |
| `0x4b27a9` | call | `0x89231a` |
| `0x4b27cf` | call | `0x82ef00` |

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
