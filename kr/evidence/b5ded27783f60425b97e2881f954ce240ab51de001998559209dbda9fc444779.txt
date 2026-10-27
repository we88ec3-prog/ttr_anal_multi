# T16-15 — KR `0x00FE18DC` 插入端、一次性初始化與 reader/writer 鍵域

- 研究時間：20261028-020402 Asia/Taipei（本機 UTC 時間換算）
- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。
- 分支基準：本批開始時 GitHub `main` `69911d157697ede14e1507109b936620416048a8`，但提交前必須再核對。
- 證據策略：本批的機器碼來自當前唯讀 KR BIN 直接 objdump；無法取得原版 Lua/XML 正文或 TC BIN，業務語義不得假定。
- 原始檔沒有執行、附加或修改；只提交分析者個人目錄完整 Markdown，保留其他任務的 owner 與 catalog。

## 目標
補 T16-10 parser writer 與 T16-13 runtime reader 的雙向鏈。關鍵判斷是「共享容器的程式碼事實」能否證明「任務狀態語義」（目前不行）。

## 直接 BIN 彙編
`0x0053FD00..0x0053FE29`：記錄配置、候選欄位與索引插入

```asm
0053fd00 <.text+0x13ed00>:
  53fd00:	3b c6                	cmp    eax,esi
  53fd02:	0f 84 16 01 00 00    	je     0x53fe1e
  53fd08:	68 d0 d1 be 00       	push   0xbed1d0
  53fd0d:	8d 78 44             	lea    edi,[eax+0x44]
  53fd10:	e8 8b 03 1f 00       	call   0x7300a0
  53fd15:	3b c6                	cmp    eax,esi
  53fd17:	74 1e                	je     0x53fd37
  53fd19:	83 c0 30             	add    eax,0x30
  53fd1c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53fd20:	72 02                	jb     0x53fd24
  53fd22:	8b 00                	mov    eax,DWORD PTR [eax]
  53fd24:	3b c6                	cmp    eax,esi
  53fd26:	74 0f                	je     0x53fd37
  53fd28:	50                   	push   eax
  53fd29:	e8 86 1a 35 00       	call   0x8917b4
  53fd2e:	83 c4 04             	add    esp,0x4
  53fd31:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  53fd35:	eb 04                	jmp    0x53fd3b
  53fd37:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  53fd3b:	6a 40                	push   0x40
  53fd3d:	e8 26 15 35 00       	call   0x891268
  53fd42:	83 c4 04             	add    esp,0x4
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
```

`0x004AE848..0x004AE8D0`：延遲初始化與索引消費

```asm
004ae848 <.text+0xad848>:
  4ae848:	f6 05 c8 18 fe 00 01 	test   BYTE PTR ds:0xfe18c8,0x1
  4ae84f:	75 2b                	jne    0x4ae87c
  4ae851:	83 0d c8 18 fe 00 01 	or     DWORD PTR ds:0xfe18c8,0x1
  4ae858:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x6
  4ae85f:	06 00 00 00 
  4ae863:	e8 08 11 09 00       	call   0x53f970
  4ae868:	68 10 e8 bc 00       	push   0xbce810
  4ae86d:	e8 a8 3a 3e 00       	call   0x89231a
  4ae872:	83 c4 04             	add    esp,0x4
  4ae875:	89 b4 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],esi
  4ae87c:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  4ae87f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4ae883:	52                   	push   edx
  4ae884:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae888:	b9 dc 18 fe 00       	mov    ecx,0xfe18dc
  4ae88d:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4ae891:	e8 2a 50 39 00       	call   0x8438c0
  4ae896:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4ae89a:	3b 0d e0 18 fe 00    	cmp    ecx,DWORD PTR ds:0xfe18e0
  4ae8a0:	74 2e                	je     0x4ae8d0
  4ae8a2:	8a 43 fd             	mov    al,BYTE PTR [ebx-0x3]
  4ae8a5:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  4ae8a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4ae8ac:	8b 0d ec 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe18ec
  4ae8b2:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  4ae8b6:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae8ba:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4ae8bf:	89 74 24 48          	mov    DWORD PTR [esp+0x48],esi
  4ae8c3:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  4ae8c7:	e8 d4 02 09 00       	call   0x53eba0
  4ae8cc:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae8d0:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4ae8d4:	eb 41                	jmp    0x4ae917
```

## 查核結果
1. `0x53FD3B push 0x40` → 配置後初始化多組偏移 (`+0x00...+0x38`)； `0x53FDC6..0x53FDF7` 將 `HasQuest`、`HasCompletableQuest`、`HasScenario` 三個候選節點向不同 `+0x10/+0x20/+0x30` 局部目標展開。
2. `0x53FDF7` 把 `[esp+0x18]` 存成鍵候選，`0x53FE03` 取 global index `0xFE18DC`，`0x53FE0C` 呼叫節點配置、`0x53FE17` 呼叫樹插入。這是**客戶端本機索引建立**。
3. `0x4AE848` 以 `test byte ptr [0xFE18C8],1` 判斷是否初始化；未初始化時設 bit、呼叫 `0x53F970`，再以 callback `0xBCE810` 登記。隨後以 `[ebx]` WORD 作 key lookup。
4. 由 initializer `0x53F970` 到 writer 迴圈 (`0x53FD..`) 的完整資料來源、同一 ID 命名空間尚需證明。即便 global address 一致，也不足以推論這是任務進度。
5. 同一欄名可能是「條件描述」而非玩家已完成的動態狀態。`HasQuest` 是 parser key，不能將其轉為 DB flag。

## 版本／名稱與反證
未找到原版 XML 實體檔；`QuestInfo.xml`、`QuestTalk.xml` 是已知路徑引用，不代表此解析器已被證明屬於其中一份檔案。KR BIN 中不同呼叫點需分開登記；TC 缺實檔，不能拿 KR 的整數 key 直接比對。

## 待查
- `0x53F970` caller/callee、root resource address 與完整跳入 `0x53FD00` 路徑。
- insertion payload `+0x10` 的 constructor/destructor 和使用時型別。
- 靜態「HasQuest」屬性與動態任務通知是否真正相關。

## 統一證據定性
- **原生已確認**：精確 x86 位址、指令、可辨識的比較與資料搬移。
- **部分確認**：資料結構模式；未還原型別、上游物件語義或真正業務含義。
- **合理推測**：可能為通用 tree/vector 元件，僅根據指令形態。
- **資訊缺失**：任務 ID、教學步驟、首次主線、權威伺服器、跨登入保存、TC 對應。
- **AI 替代／待補開發**：本段沒有使用 AI fixture 作為原生證據，也沒有進行實作。

## KR/TC、跨 Task 邊界與驗收
| 項目 | KR | TC | 是否可玩驗收 |
|---|---|---|---|
| 此處指令路徑 | KR BIN 直接驗證，精確 VA 如下 | 原始 TC BIN 未提供，不能套 KR 位址 | 未測試 |
| 教學進度/主線任務 | 尚無原版 Lua/XML 和伺服器資料 | unknown | 未測試 |
| 任務封包與伺服器權威 | 未追到已證實的 quest-state writer | unknown | 未測試 |

T16 只研究任務資料消費及進度語義。T02 負責封包框架；T03/T04 已存在角色狀態；T07 場景進出；T14 關卡結果；T15 資料保存。不得將通用容器機制認領為新 T16 主責方法。

## 下一段交接
T16-16 將本批直接原生證據對照任務封包、教學入口與主線完成缺口，建立實際可供下一研究者執行的優先工作矩陣。