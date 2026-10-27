# T16-17 — T02 frame handler 表：初始化範圍與業務界線

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. handler table entries carry function address and paired constant; no quest command classification from handler address alone。證據分級：局部程式碼已確認、任務業務語義未確認。
2. large repeated initialization with counter 0xBD5 indicates table setup, not direct server quest state writer。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x004ADD50`–`0x004ADF00`（89 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
  4addac:	c7 40 04 f0 fa 4a 00 	mov    DWORD PTR [eax+0x4],0x4afaf0
  4addb3:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4addb6:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4addb9:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4addbc:	c7 40 5c 60 fe 4a 00 	mov    DWORD PTR [eax+0x5c],0x4afe60
  4addc3:	89 48 60             	mov    DWORD PTR [eax+0x60],ecx
  4addc6:	c7 40 64 30 01 4b 00 	mov    DWORD PTR [eax+0x64],0x4b0130
  4addcd:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  4addd0:	c7 40 6c c0 01 4b 00 	mov    DWORD PTR [eax+0x6c],0x4b01c0
  4addd7:	89 48 70             	mov    DWORD PTR [eax+0x70],ecx
  4addda:	c7 80 7c 05 00 00 d0 	mov    DWORD PTR [eax+0x57c],0x4b03d0
  4adde1:	03 4b 00 
  4adde4:	89 88 80 05 00 00    	mov    DWORD PTR [eax+0x580],ecx
  4addea:	c7 40 74 40 6c 43 00 	mov    DWORD PTR [eax+0x74],0x436c40
  4addf1:	89 48 78             	mov    DWORD PTR [eax+0x78],ecx
  4addf4:	c7 80 fc 09 00 00 40 	mov    DWORD PTR [eax+0x9fc],0x4b1940
  4addfb:	19 4b 00 
  4addfe:	89 88 00 0a 00 00    	mov    DWORD PTR [eax+0xa00],ecx
  4ade04:	c7 40 7c d0 19 4b 00 	mov    DWORD PTR [eax+0x7c],0x4b19d0
  4ade0b:	89 88 80 00 00 00    	mov    DWORD PTR [eax+0x80],ecx
  4ade11:	c7 80 84 00 00 00 30 	mov    DWORD PTR [eax+0x84],0x4b1a30
  4ade18:	1a 4b 00 
  4ade1b:	89 88 88 00 00 00    	mov    DWORD PTR [eax+0x88],ecx
  4ade21:	c7 80 8c 00 00 00 70 	mov    DWORD PTR [eax+0x8c],0x4b1a70
  4ade28:	1a 4b 00 
  4ade2b:	89 88 90 00 00 00    	mov    DWORD PTR [eax+0x90],ecx
  4ade31:	c7 80 1c 02 00 00 90 	mov    DWORD PTR [eax+0x21c],0x4b1a90
  4ade38:	1a 4b 00 
  4ade3b:	89 88 20 02 00 00    	mov    DWORD PTR [eax+0x220],ecx
  4ade41:	c7 80 94 00 00 00 f0 	mov    DWORD PTR [eax+0x94],0x4b24f0
  4ade48:	24 4b 00 
  4ade4b:	89 88 98 00 00 00    	mov    DWORD PTR [eax+0x98],ecx
  4ade51:	c7 80 a4 00 00 00 30 	mov    DWORD PTR [eax+0xa4],0x4c5930
  4ade58:	59 4c 00 
  4ade5b:	89 88 a8 00 00 00    	mov    DWORD PTR [eax+0xa8],ecx
  4ade61:	c7 80 ac 00 00 00 20 	mov    DWORD PTR [eax+0xac],0x4b2620
  4ade68:	26 4b 00 
  4ade6b:	89 88 b0 00 00 00    	mov    DWORD PTR [eax+0xb0],ecx
  4ade71:	89 90 b4 00 00 00    	mov    DWORD PTR [eax+0xb4],edx
  4ade77:	89 88 b8 00 00 00    	mov    DWORD PTR [eax+0xb8],ecx
  4ade7d:	c7 80 c4 00 00 00 30 	mov    DWORD PTR [eax+0xc4],0x4b2730
  4ade84:	27 4b 00 
  4ade87:	89 88 c8 00 00 00    	mov    DWORD PTR [eax+0xc8],ecx
  4ade8d:	c7 80 d4 00 00 00 d0 	mov    DWORD PTR [eax+0xd4],0x4b28d0
  4ade94:	28 4b 00 
  4ade97:	89 88 d8 00 00 00    	mov    DWORD PTR [eax+0xd8],ecx
  4ade9d:	c7 80 dc 00 00 00 80 	mov    DWORD PTR [eax+0xdc],0x4ae380
  4adea4:	e3 4a 00 
  4adea7:	89 88 e0 00 00 00    	mov    DWORD PTR [eax+0xe0],ecx
  4adead:	c7 80 3c 01 00 00 f0 	mov    DWORD PTR [eax+0x13c],0x4b2af0
  4adeb4:	2a 4b 00 
  4adeb7:	89 88 40 01 00 00    	mov    DWORD PTR [eax+0x140],ecx
  4adebd:	c7 80 44 02 00 00 e0 	mov    DWORD PTR [eax+0x244],0x4b32e0
  4adec4:	32 4b 00 
  4adec7:	89 88 48 02 00 00    	mov    DWORD PTR [eax+0x248],ecx
  4adecd:	c7 80 0c 01 00 00 d0 	mov    DWORD PTR [eax+0x10c],0x4b2cd0
  4aded4:	2c 4b 00 
  4aded7:	89 88 10 01 00 00    	mov    DWORD PTR [eax+0x110],ecx
  4adedd:	c7 80 14 01 00 00 40 	mov    DWORD PTR [eax+0x114],0x4b3040
  4adee4:	30 4b 00 
  4adee7:	89 88 18 01 00 00    	mov    DWORD PTR [eax+0x118],ecx
  4adeed:	c7 80 34 01 00 00 60 	mov    DWORD PTR [eax+0x134],0x4b3060
  4adef4:	30 4b 00 
  4adef7:	89 88 38 01 00 00    	mov    DWORD PTR [eax+0x138],ecx
  4adefd:	c7 80 ec     	mov    DWORD PTR [eax+0x8ec],0x4b3060
  4adf04:	   
```

### VA `0x004B7D30`–`0x004B7DE0`（77 條可解析行；原始 bytes 位於每行 instruction 欄）

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
  4b7ddf:	c7       	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	   
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x4b7d5a` | call | `0x6edc70` |
| `0x4b7dad` | call | `0x6edd00` |

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
