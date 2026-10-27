# T16-01 — KR Tutorial / Quest 起始鏈：第一手 BIN 搜尋、程式碼引用、TC 證據缺口

- 分析日期 Asia/Taipei：20261028-012351
- Repository：https://github.com/we88ec3-prog/ttr_anal_multi
- 分析時 main HEAD：`52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`（遠端直接讀取）
- 原始 KR 來源：唯讀 `/mnt/data/Tartaros.bin`，大小 12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- KR EXE 補充來源：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本段未將它誤作反組譯來源
- TC 原始資料：未取得；`shared/targets.json` 記載 TC `Tartaros.bin` SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`，長度 4692992，僅索引尚未直接驗證。
- 分段性質：**首次實際原生 x86 BIN 指令核對，未完成後端語義或完整教程步驟復原**。
- 禁止改動：未改 GitHub、任何 Task owner/catalog、遊戲原件；未執行／附加客戶端。

## 1. 工作範圍與版本政策

T16 以既有角色為輸入，負責 Tutorial 與跨關卡任務／主線狀態；T04 初始化、T03 登入、T07 關卡、T14 結算、T15 儲存、T02 封包框架保留其主責。`AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md` 已讀；以伺服器封包與資料恢復優先。GitHub KR/TC `task.json` 均為 `owner:null,state:unclaimed,native_complete:false`，規劃不等於 catalog 已登記。`HANDOFF.md` 更正「原始 005F type6 不等於歷史 Tutorial 修補」保持有效。T01 source-only 不能推論全函式語義審核完成。

## 2. PE header / VA ↔ raw 直接檢查

`objdump -h` 從目前原始 PE 確認以下映射：

| section | VA start | raw start | virtual/data size |
|---|---:|---:|---:|
| .text | `0x00401000` | `0x00000400` | `0x007D01F0` |
| .rdata | `0x00BD2000` | `0x007D0600` | `0x0018E07C` |
| .data | `0x00D61000` | `0x0095E800` | `0x0022B800` |
| .rsrc | `0x00FE9000` | `0x00B8A000` | `0x0005AF58` |

對 .rdata 字串，`VA=raw-0x007D0600+0x00BD2000`。Xref 為直接掃描 .text 的 4-byte 小端常數後再以 `objdump -D -Mintel` 查證；單純常數命中不可直接歸類成已完整控制流。

## 3. 來源盤點 / source-inventory

| version | source | provenance | evidence / limit |
|---|---|---|---|
| KR | 本次 BIN | SHA 如上／原生 PE | 直接驗證字串與參照指令 |
| KR | `Event/TutorialBase.lua`, `Event/TutorialMain.lua` | BIN 中的 ASCII 路徑 | 只證實載入或登錄路徑參照，**沒有取得 Lua 內容** |
| KR | `Table/QuestInfo.xml`, `Table/QuestTalk.xml` | BIN 中資源路徑 | XML **實體檔案未取得**；不能解出真實 quest/step ID |
| KR | `Table/ScenarioBookContents.xml`, `Table/QuestCameraWorks.xml` | BIN 路徑 | 入口字串而非 XML schema 本身 |
| KR | `QUESTSTATE`, `QUEST_READY`, `TutoQuest`, `HasQuest`, `HasCompletableQuest`, `HasScenario` | BIN 字串及指令 | UI／XML 欄位詞；是否 server 權威未知 |
| KR | `QUEST-STATE-NOTIFICATIONS`, `MAINLINE-FLOW`, `48-tutorial-battle-fixture` | repo 歷史線索 | 不把 fixture、patch 或測試資料視為原版 |
| TC | `shared/targets.json` 所述客戶端 | repo index only | 沒有 TC BIN/表格內容；不得套 KR VA/ID |

## 4. KR 字串到 x86 指令引用索引

直接定位 ASCII 以 NUL/邊界為準，列表記錄字串起點、預期 VA、其中一個在 .text 查到的引用 VA。`HasQuest` 等只保留同字串首地址；未把字串中的子串當額外功能。

| native identifier | .rdata VA | code xref VA | confidence |
|---|---:|---:|---|
| `Event/TutorialBase.lua` | `0x00C06864` | `0x004A89B0` | BIN bytes + instruction reference confirmed |
| `Event/TutorialMain.lua` | `0x00C0687C` | `0x004A8A32` | BIN bytes + instruction reference confirmed |
| `Tutorial_EntryPoint` | `0x00C068A8` | `0x004A8B70` | BIN bytes + instruction reference confirmed |
| `Table/QuestInfo.xml` | `0x00C0DB48` | `0x0050478C` | BIN bytes + instruction reference confirmed |
| `Table/QuestTalk.xml` | `0x00C0DB5C` | `0x005055B9` | BIN bytes + instruction reference confirmed |
| `QUESTSTATE` | `0x00C0DA98` | `0x005024CD` | BIN bytes + instruction reference confirmed |
| `QUEST_READY` | `0x00C0DAB8` | `0x005028A0` | BIN bytes + instruction reference confirmed |
| `TutoQuest` | `0x00C0F1A4` | `0x00532248` | BIN bytes + instruction reference confirmed |
| `HasQuest` | `0x00C0F4EC` | `0x0053FD85` | BIN bytes + instruction reference confirmed |
| `HasCompletableQuest` | `0x00C0F4F8` | `0x0053FD93` | BIN bytes + instruction reference confirmed |
| `HasScenario` | `0x00C0F50C` | `0x0053FDA3` | BIN bytes + instruction reference confirmed |
| `Table/ScenarioBookContents.xml` | `0x00C0DAC4` | `0x00503936` | BIN bytes + instruction reference confirmed |
| `Table/QuestCameraWorks.xml` | `0x00C10774` | `0x0056BF86` | BIN bytes + instruction reference confirmed |

### 4.1 新確認的 Tutorial 腳本鏈

- `0x004A89AF`: `push 0x00C06864` (`Event/TutorialBase.lua`)，`0x004A89B6: call 0x006F4A50`。證實該路徑作為函式參數；**尚待驗證 0x6F4A50 的實際腳本載入語義與失敗路徑**。
- `0x004A8A31`: `push 0x00C0687C` (`Event/TutorialMain.lua`)，`0x004A8A36: call 0x006F4A50`；後續 `0x004A8A41: push 0x00C06894`，`0x004A8A46: call 0x006F4DD0`；`0xC06894` 的字串須另外確認，不可命名教學完成事件。
- `0x004A8B5F` 再引用 `Event/TutorialMain.lua` 並呼叫 `0x006F4A50`；`0x004A8B6F` 傳 `Tutorial_EntryPoint` 給 `0x006F4DD0`，另外兩個 push 參數為 0。這是一條**可重現的教學入口函式呼叫路徑**，但沒有證明條件為初登／教學旗標、也無法由函式名稱推論伺服器狀態寫入。
- `0x004A8B33`: 檢查全域 `[0x00FBA798]`；零值路徑走間接 vtable `+0x10` 呼叫，前面 `push 0x6`。未經上下游驗證，**0x6 不能當任務進度 ID 或封包 005F type6**。

### 4.2 Quest 與主線來源鏈

- `0x0050478B: mov ecx,0x00C0DB48` (`Table/QuestInfo.xml`)，`call 0x0072EE30`：原生檔名被程式使用；**尚未證實 XML 檔案存在、完整 schema 或讀取成功**。
- `0x005055B9` 附近有 `Table/QuestTalk.xml` 常數引用，待完整解析該函式的 parser、輸出結構與 NPC／對話 key。
- `0x00532247: push 0x00C0F1A4` (`TutoQuest`)，`call 0x0072E2E0`，結果與零比較；可確認文字/鍵名匹配路徑，不能直接當教學狀態寫入者。
- `0x0053FD84`, `0x0053FD92`, `0x0053FDA2`: 依序將 `HasQuest`, `HasCompletableQuest`, `HasScenario` 交給 `0x0072E2E0` 查找，回傳值若非零分別呼叫 `0x0053FEB0`，輸出指向結構的 `+0x10`, `+0x20`, `+0x30`。這些偏移是本條**局部輸出結構欄位**，不是持久化任務旗標。
- `QUESTSTATE`、`QUEST_READY` 在 `0x005024CA`, `0x0050289F` 均可查到直接引用，主要是介面構造／顯示候選；沒有找到證明原生 server 存儲權威的證據。

## 5. 原始彙編節錄（本次直接 BIN 反組譯）

### Tutorial base registration — `0x004A899F..0x004A89BF`

```asm
  4a899f:	5d                   	pop    ebp
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
```

### Tutorial main registration — `0x004A8A25..0x004A8A5E`

```asm
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
```

### Tutorial entry initialization — `0x004A8B2F..0x004A8B8D`

```asm
  4a8b2f:	00 83 c4 04 83 3d    	add    BYTE PTR [ebx+0x3d8304c4],al
  4a8b35:	98                   	cwde
  4a8b36:	a7                   	cmps   DWORD PTR ds:[esi],DWORD PTR es:[edi]
  4a8b37:	fb                   	sti
  4a8b38:	00 00                	add    BYTE PTR [eax],al
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
```

### QuestInfo XML reference — `0x00504780..0x005047A2`

```asm
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
```

### QuestTalk XML reference — `0x0050559F..0x005055DA`

```asm
  50559f:	00 33                	add    BYTE PTR [ebx],dh
  5055a1:	c4 50 8d             	les    edx,FWORD PTR [eax-0x73]
  5055a4:	84 24 a8             	test   BYTE PTR [eax+ebp*4],ah
  5055a7:	00 00                	add    BYTE PTR [eax],al
  5055a9:	00 64 a3 00          	add    BYTE PTR [ebx+eiz*4+0x0],ah
  5055ad:	00 00                	add    BYTE PTR [eax],al
  5055af:	00 8b 45 08 8d 4c    	add    BYTE PTR [ebx+0x4c8d0845],cl
  5055b5:	24 24                	and    al,0x24
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c            	cmp    DWORD PTR [esp+0x58],edi
```

### Quest state display construction — `0x005024BE..0x005024FB`

```asm
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
  5024f9:	8b 43              	mov    eax,DWORD PTR [ebx+0x28]
```

### Quest ready UI reference — `0x00502889..0x005028BD`

```asm
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
  5028bc:	f6       	test   BYTE PTR ds:0xfab0d4,0x1
```

### TutoQuest text lookup — `0x0053222D..0x0053226E`

```asm
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
  532269:	0f 84 e1 02 00     	je     0x532550
```

### HasQuest/HasCompletableQuest/HasScenario lookups — `0x0053FD76..0x0053FDF7`

```asm
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
```

## 6. 局部偽碼（只抽取本次可確定的指令操作）

```cpp
// 此段是 instruction-level abstract，不是已復原的正式 C++ API 名稱。
void candidate_tutorial_entry(Context *ctx) {
    // 0x4A8B33 路徑有以全域旗標保護的間接呼叫（意義 unknown）。
    unknown_6F4A50(ctx->field0, "Event/TutorialMain.lua");
    unknown_6F4DD0(ctx->field0, "Tutorial_EntryPoint", 0, 0);
}
void candidate_quest_presence_parser(...) {
    auto a = unknown_72E2E0(..., "HasQuest");
    auto b = unknown_72E2E0(..., "HasCompletableQuest");
    auto c = unknown_72E2E0(..., "HasScenario");
    if (a) unknown_53FEB0(a, localOutput + 0x10);
    if (b) unknown_53FEB0(b, localOutput + 0x20);
    if (c) unknown_53FEB0(c, localOutput + 0x30);
}
```

**限制**：前置 `ctx`、輸出變數語義與各 callee 未封閉檢查。偽碼為幫助重現的意向表示，不替代指令。

## 7. tutorial-node-matrix（只填已確定欄）

| node / ID | prerequisites | entry & trigger | server authority | writer | client/UI indication | next / retry / resume | evidence |
|---|---|---|---|---|---|---|---|
| tutorial script base | unknown | code `0x4A89AF` passes `Event/TutorialBase.lua` to `0x6F4A50` | unknown | unknown | unknown | unknown | native partial |
| tutorial main | unknown | `0x4A8A31`, `0x4A8B5F` pass `Event/TutorialMain.lua` | unknown | unknown | unknown | unknown | native partial |
| tutorial entry call | unknown | `0x4A8B6F` uses `Tutorial_EntryPoint` with `0x6F4DD0` | unknown | unknown | unknown | unknown | native partial |
| tutorial quest label | unknown | `TutoQuest` at `0x532247` key lookup | unknown | unknown | candidate data/UI field | unknown | native partial |
| quest presence fields | unknown | `HasQuest/HasCompletableQuest/HasScenario` at `0x53FD84+` | unknown | unknown | candidate parsed flags | unknown | native partial |
| tutorial complete → mainline | unknown | unknown | unknown | unknown | unknown | unknown | missing |

## 8. early-mainline-flow / KR-TC comparison

`T03/T04 existing role → [tutorial applicable? unknown] → Tutorial_EntryPoint (call identified only) → [step transitions unknown] → [completion unknown] → [first mainline quest ID unknown] → [NPC/scene/turn-in unknown] → [next unlock unknown]`。

| cross-version field | KR | TC | compare |
|---|---|---|---|
| client SHA | directly hashed, above | manifest only, above | distinct source; no RVA reuse |
| tutorial Lua filename | present in KR BIN | unknown | cannot assert equivalent |
| QuestInfo/QuestTalk XML reference | present in KR BIN | unknown | no schema or semantic match confirmed |
| quest/step ID | unknown | unknown | comparison blocked |
| NPC, scene, mainline ID | unknown | unknown | comparison blocked |
| packet command / persistence | unknown | unknown | comparison blocked |

## 9. cross-task-interfaces

| Boundary | T16-needed input/output | observed in T16-01 | request to owner |
|---|---|---|---|
| T03 / T04 → T16 | existing character identity and tutorial state | no confirmed field | exact field provenance; do not invent defaults |
| T02 ↔ T16 | frame handler + quest command payload | only quest UI labels, not frame traced | find native command dispatch interface |
| T07/T14 → T16 | scene results to quest progress update | not yet proven | result to notification evidence |
| T15 ↔ T16 | persisted quest progress and re-login restore | not yet proven | persistence key namespace/source |
| T06 / content → T16 | NPC / scenario / table asset values | file names only | original XML/Lua/resource files required |

## 10. acceptance-matrix / 反證及未解問題

| test | native verified | playable verified | note |
|---|---|---|---|
| KR SHA + PE mapping | yes | not tested | native source is correct |
| Tutorial Lua path xref and candidate call | yes, bounded | not tested | callee not fully reversed |
| Tutorial first-step / every step | no | not tested | Lua data unavailable |
| Quest XML path xref | yes, bounded | not tested | XML content unavailable |
| Server authoritative progress writer | no | not tested | packet/DB chain unresolved |
| tutorial → first mainline closed loop | no | not tested | no quest IDs claimed |
| TC comparison by version | metadata only | not tested | TC original absent |

**已排除的錯誤推導：** `005F type6` 不直接等於 Tutorial；本段的 `push 6` 也不能倒推封包碼；Quest 顯示字串不等於可持久化進度；歷史 fixture 不能證明官方原版完成規則；KR VA 不等於 TC VA。

**下一批高價值查核：**
1. 對 `0x006F4A50/0x006F4DD0` 追 caller/callee、Lua 初始化上下文、參數/狀態來源、Tutorial_EntryPoint return/handler。
2. 對 `0x0050478B` / QuestInfo、`0x005055B9` / QuestTalk 的實際 parser 與表資料做結構抽取，取得第一批原生 quest/step IDs。
3. 對 `0x0053FD76..0x0053FDF7` 的解析輸出逆向追 consumer，區分 UI 標誌和 server 回報。
4. 沿 T02 dispatch / native notification 追 task state mutation，校對歷史 `QUEST-STATE-NOTIFICATIONS`、`005F type6` 原始更正。
5. 取得版本匹配的 KR Lua/XML 及 TC 客戶端資源；現階段禁止猜測教學步驟或自行重啟 TC 解殼。

## 11. Commit status

Local-only artifact. **No git commit, push, branch modification or task claim was performed.**