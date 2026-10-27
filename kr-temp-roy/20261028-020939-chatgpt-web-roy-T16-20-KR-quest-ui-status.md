# T16-20 — QUESTSTATE 與 QUEST_READY 的 UI 消費者

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. two native strings may reflect local display, not persisted player quest data。證據分級：局部程式碼已確認、任務業務語義未確認。
2. UI identifier use is not a server-authoritative writer。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x00502460`–`0x00502580`（89 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  502460:	00 00                	add    BYTE PTR [eax],al
  502462:	00 8b 17 8b 42 4c    	add    BYTE PTR [ebx+0x4c428b17],cl
  502468:	8b cf                	mov    ecx,edi
  50246a:	ff d0                	call   eax
  50246c:	8b 08                	mov    ecx,DWORD PTR [eax]
  50246e:	8b b7 5c 01 00 00    	mov    esi,DWORD PTR [edi+0x15c]
  502474:	89 4d e4             	mov    DWORD PTR [ebp-0x1c],ecx
  502477:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  50247a:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  50247d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  502480:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
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
  50256f:	73 03                	jae    0x502574
  502571:	8d 75 c8             	lea    esi,[ebp-0x38]
  502574:	e8 b7 1b f3 ff       	call   0x434130
  502579:	8d 50 04             	lea    edx,[eax+0x4]
  50257c:	89 10                	mov    DWORD PTR [eax],edx
  50257e:	8d 48              	lea    ecx,[eax+0x8]
```

### VA `0x00502850`–`0x00502970`（81 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  502850:	74 2a                	je     0x50287c
  502852:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502855:	83 ca ff             	or     edx,0xffffffff
  502858:	50                   	push   eax
  502859:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50285c:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50285f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
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
  50294e:	e8 9d ed ff ff       	call   0x5016f0
  502953:	8b f0                	mov    esi,eax
  502955:	83 cf ff             	or     edi,0xffffffff
  502958:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  50295b:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  502962:	75 23                	jne    0x502987
  502964:	83 0d 54 73 fb 00 01 	or     DWORD PTR ds:0xfb7354,0x1
  50296b:	c7 45 fc 03 00   	mov    DWORD PTR [ebp-0x4],0x3
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x502491` | call | `0x7a7100` |
| `0x50249e` | jmp | `0x5024ab` |
| `0x5024ea` | call | `0x49b140` |
| `0x5024f4` | call | `0x551f20` |
| `0x502502` | call | `0x4ffd90` |
| `0x502518` | call | `0x5740f0` |
| `0x502545` | call | `0x402b70` |
| `0x502564` | call | `0x401fc0` |
| `0x502574` | call | `0x434130` |
| `0x502872` | call | `0x58aa50` |
| `0x502877` | jmp | `0x502b1d` |
| `0x50287f` | call | `0x58aa50` |
| `0x502884` | jmp | `0x502b1d` |
| `0x50288e` | call | `0x422f40` |
| `0x502895` | call | `0x561760` |
| `0x5028b4` | call | `0x40b310` |
| `0x5028d0` | call | `0x80a3a0` |
| `0x5028da` | call | `0x89231a` |
| `0x5028ee` | call | `0x80ab00` |
| `0x502911` | call | `0x89120c` |
| `0x502928` | call | `0x891268` |
| `0x50294e` | call | `0x5016f0` |

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
