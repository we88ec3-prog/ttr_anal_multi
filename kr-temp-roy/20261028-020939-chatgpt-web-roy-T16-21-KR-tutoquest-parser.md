# T16-21 — TutoQuest 表單解析與條件分支

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. TutoQuest lookup is an XML-like key lookup candidate; no evidence for character quest completion。證據分級：局部程式碼已確認、任務業務語義未確認。
2. HasQuest fields are parsed into a local output object; provenance is unresolved。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x005321A0`–`0x00532370`（137 條可解析行；原始 bytes 位於每行 instruction 欄）

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
  53235f:	33 c0                	xor    eax,eax
  532361:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  532365:	8d 70 ff             	lea    esi,[eax-0x1]
  532368:	68 9c f1 c0 00       	push   0xc0f19c
  53236d:	83 c7 44             	add    edi,0x44
```

### VA `0x0053FD40`–`0x0053FE30`（76 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  53fd40:	35 00 83 c4 04       	xor    eax,0x4c48300
  53fd45:	3b c6                	cmp    eax,esi
  53fd47:	74 29                	je     0x53fd72
  53fd49:	89 30                	mov    DWORD PTR [eax],esi
  53fd4b:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  53fd4e:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  53fd51:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  53fd54:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  53fd57:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  53fd5a:	89 70 20             	mov    DWORD PTR [eax+0x20],esi
  53fd5d:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
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
  53fe2e:	c7 84      	mov    DWORD PTR [esp+0xc0],0xffffffff
  53fe35:	    
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x5321aa` | call | `0x532d70` |
| `0x5321b6` | call | `0x5325d0` |
| `0x5321c2` | call | `0x5325d0` |
| `0x5321d3` | call | `0x89120c` |
| `0x532200` | call | `0x89120c` |
| `0x532221` | call | `0x89120c` |
| `0x532232` | call | `0x72e3c0` |
| `0x53224c` | call | `0x72e2e0` |
| `0x53225e` | call | `0x72e360` |
| `0x53227c` | call | `0x7300a0` |
| `0x532295` | call | `0x8917b4` |
| `0x5322a1` | jmp | `0x5322a7` |
| `0x5322ac` | call | `0x7300a0` |
| `0x5322c5` | call | `0x8917b4` |
| `0x5322cf` | jmp | `0x5322d3` |
| `0x5322d8` | call | `0x7300a0` |
| `0x5322f1` | call | `0x8917b4` |
| `0x5322fd` | jmp | `0x532303` |
| `0x532320` | call | `0x821c50` |
| `0x53232b` | call | `0x517bf0` |
| `0x53233c` | call | `0x7300a0` |
| `0x532355` | call | `0x8917b4` |
| `0x53235d` | jmp | `0x532361` |
| `0x53fd70` | jmp | `0x53fd76` |
| `0x53fd7d` | call | `0x72e2e0` |
| `0x53fd8b` | call | `0x72e2e0` |
| `0x53fd99` | call | `0x72e2e0` |
| `0x53fda9` | call | `0x72e2e0` |
| `0x53fdbd` | call | `0x53feb0` |
| `0x53fdd0` | call | `0x53feb0` |
| `0x53fde1` | call | `0x53feb0` |
| `0x53fdf2` | call | `0x53feb0` |
| `0x53fe0c` | call | `0x57ef20` |
| `0x53fe17` | call | `0x57e850` |

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
