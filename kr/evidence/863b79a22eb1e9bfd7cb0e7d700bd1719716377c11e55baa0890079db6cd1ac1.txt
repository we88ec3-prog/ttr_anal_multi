# T16-18 — T02 接收佇列與任務通知入口候選

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. network recv and client queue are generic transport/dispatch candidates。證據分級：局部程式碼已確認、任務業務語義未確認。
2. no quest-specific payload semantics established from these snippets。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x00807B40`–`0x00807C90`（90 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  807b40:	55                   	push   ebp
  807b41:	8b ec                	mov    ebp,esp
  807b43:	83 e4 f8             	and    esp,0xfffffff8
  807b46:	6a ff                	push   0xffffffff
  807b48:	68 be 98 90 00       	push   0x9098be
  807b4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807b53:	50                   	push   eax
  807b54:	51                   	push   ecx
  807b55:	b8 24 20 00 00       	mov    eax,0x2024
  807b5a:	e8 11 8b 0a 00       	call   0x8b0670
  807b5f:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b64:	33 c4                	xor    eax,esp
  807b66:	89 84 24 20 20 00 00 	mov    DWORD PTR [esp+0x2020],eax
  807b6d:	53                   	push   ebx
  807b6e:	56                   	push   esi
  807b6f:	57                   	push   edi
  807b70:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b75:	33 c4                	xor    eax,esp
  807b77:	50                   	push   eax
  807b78:	8d 84 24 38 20 00 00 	lea    eax,[esp+0x2038]
  807b7f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
  807c44:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  807c4b:	75 2f                	jne    0x807c7c
  807c4d:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  807c54:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0x0
  807c5b:	00 00 00 00 
  807c5f:	e8 bc f4 ff ff       	call   0x807120
  807c64:	68 90 0b bd 00       	push   0xbd0b90
  807c69:	e8 ac a6 08 00       	call   0x89231a
  807c6e:	83 c4 04             	add    esp,0x4
  807c71:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0xffffffff
  807c78:	ff ff ff ff 
  807c7c:	bf 58 33 fe 00       	mov    edi,0xfe3358
  807c81:	e8 2a f9 ff ff       	call   0x8075b0
  807c86:	8d 3c 1e             	lea    edi,[esi+ebx*1]
  807c89:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807c8c:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
```

### VA `0x004930E0`–`0x00493210`（101 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80 47 49 00       	mov    edx,0x494780
  4931a3:	89 90 98 03 00 00    	mov    DWORD PTR [eax+0x398],edx
  4931a9:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931ae:	89 90 48 10 00 00    	mov    DWORD PTR [eax+0x1048],edx
  4931b4:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931b9:	89 90 c8 03 00 00    	mov    DWORD PTR [eax+0x3c8],edx
  4931bf:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931c4:	89 90 08 04 00 00    	mov    DWORD PTR [eax+0x408],edx
  4931ca:	ba 60 48 49 00       	mov    edx,0x494860
  4931cf:	89 90 38 04 00 00    	mov    DWORD PTR [eax+0x438],edx
  4931d5:	ba 90 4a 49 00       	mov    edx,0x494a90
  4931da:	89 90 48 04 00 00    	mov    DWORD PTR [eax+0x448],edx
  4931e0:	ba d0 4c 49 00       	mov    edx,0x494cd0
  4931e5:	89 90 f8 04 00 00    	mov    DWORD PTR [eax+0x4f8],edx
  4931eb:	ba 50 47 49 00       	mov    edx,0x494750
  4931f0:	89 90 78 09 00 00    	mov    DWORD PTR [eax+0x978],edx
  4931f6:	ba f0 59 49 00       	mov    edx,0x4959f0
  4931fb:	89 90 a8 0f 00 00    	mov    DWORD PTR [eax+0xfa8],edx
  493201:	ba 60 5a 49 00       	mov    edx,0x495a60
  493206:	89 90 28 0f 00 00    	mov    DWORD PTR [eax+0xf28],edx
  49320c:	ba b0 43 49        	mov    edx,0x4943b0
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x807b5a` | call | `0x8b0670` |
| `0x807bab` | jmp | `0x807bb0` |
| `0x807bfa` | jmp | `0x807c34` |
| `0x807c16` | jmp | `0x807c34` |
| `0x807c5f` | call | `0x807120` |
| `0x807c69` | call | `0x89231a` |
| `0x807c81` | call | `0x8075b0` |
| `0x493115` | call | `0x6db1f0` |

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
