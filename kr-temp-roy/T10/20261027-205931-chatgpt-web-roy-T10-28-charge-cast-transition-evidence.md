# KR T10-28 — T10／T11 交界：蓄氣改招及普攻／技能互接的證據矩陣

原始資料：`/mnt/data/Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）。研究日期：2026-10-27（Asia/Taipei）。

**方法**：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`，先核實完整函式的入口和跳轉邊界；未執行、注入或改寫客戶端。組語是 BIN 第一手證據；T10-24 與 GitHub T11 既有審核作交叉參考，不替代機器碼。未命名函式、物件欄位的語義均為候選。

**使用者補充（研究需求，非由 BIN 證明）**：按鍵可自訂；六種輸入 Z、X、C、Z+X、Z+C、X+C；V 點按／長按影響技能且包含 Z；普攻／技能有交互接續。研究不能將字母按鍵硬對映到 mask。

## 研究目標與本次範圍

統整本批對使用者新需求的影響；額外展開 `0x54A050` 對 4/5/6 狀態與候選目標的查詢，以區分 SubAI 技能狀態與玩家 charge 動作。明確列出「普攻→技能」「技能→普攻」「V 蓄氣後改招」尚缺哪一條完整邊。

## 第一手組語摘錄

```asm
  54a050:	55                   	push   ebp
  54a051:	8b ec                	mov    ebp,esp
  54a053:	83 e4 f8             	and    esp,0xfffffff8
  54a056:	6a ff                	push   0xffffffff
  54a058:	68 1e 6a 93 00       	push   0x936a1e
  54a05d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  54a063:	50                   	push   eax
  54a064:	83 ec 10             	sub    esp,0x10
  54a067:	53                   	push   ebx
  54a068:	56                   	push   esi
  54a069:	57                   	push   edi
  54a06a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54a06f:	33 c4                	xor    eax,esp
  54a071:	50                   	push   eax
  54a072:	8d 44 24 20          	lea    eax,[esp+0x20]
  54a076:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  54a07c:	8b f1                	mov    esi,ecx
  54a07e:	8b be 08 01 00 00    	mov    edi,DWORD PTR [esi+0x108]
  54a084:	03 ff                	add    edi,edi
  54a086:	8b 84 fe ac 00 00 00 	mov    eax,DWORD PTR [esi+edi*8+0xac]
  54a08d:	33 db                	xor    ebx,ebx
  54a08f:	83 f8 04             	cmp    eax,0x4
  54a092:	74 0e                	je     0x54a0a2
  54a094:	83 f8 05             	cmp    eax,0x5
  54a097:	74 09                	je     0x54a0a2
  54a099:	83 f8 06             	cmp    eax,0x6
  54a09c:	0f 85 3a 01 00 00    	jne    0x54a1dc
  54a0a2:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  54a0a9:	75 25                	jne    0x54a0d0
  54a0ab:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  54a0b2:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  54a0b6:	e8 d5 4b f9 ff       	call   0x4dec90
  54a0bb:	68 30 ce bc 00       	push   0xbcce30
  54a0c0:	e8 55 82 34 00       	call   0x89231a
  54a0c5:	83 c4 04             	add    esp,0x4
  54a0c8:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  54a0cf:	ff 
  54a0d0:	8b 8c fe b0 00 00 00 	mov    ecx,DWORD PTR [esi+edi*8+0xb0]
  54a0d7:	8d 54 24 10          	lea    edx,[esp+0x10]
  54a0db:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  54a0df:	52                   	push   edx
  54a0e0:	8d 44 24 18          	lea    eax,[esp+0x18]
  54a0e4:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  54a0e9:	e8 12 4e 2e 00       	call   0x82ef00
  54a0ee:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  54a0f2:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  54a0f8:	0f 84 c7 00 00 00    	je     0x54a1c5
  54a0fe:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  54a101:	85 c0                	test   eax,eax
  54a103:	0f 84 bc 00 00 00    	je     0x54a1c5
  54a109:	8b 88 58 01 00 00    	mov    ecx,DWORD PTR [eax+0x158]
  54a10f:	85 c9                	test   ecx,ecx
  54a111:	0f 84 ae 00 00 00    	je     0x54a1c5
  54a117:	83 79 34 00          	cmp    DWORD PTR [ecx+0x34],0x0
  54a11b:	0f 85 a4 00 00 00    	jne    0x54a1c5
  54a121:	d9 46 64             	fld    DWORD PTR [esi+0x64]
  54a124:	d8 a0 a0 00 00 00    	fsub   DWORD PTR [eax+0xa0]
  6d0930:	8d 44 24 24          	lea    eax,[esp+0x24]
  6d0934:	50                   	push   eax
  6d0935:	b9 88 08 c4 00       	mov    ecx,0xc40888
  6d093a:	e8 f1 e4 05 00       	call   0x72ee30
  6d093f:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0x0
  6d0946:	00 00 00 00 
  6d094a:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  6d094e:	bb 10 00 00 00       	mov    ebx,0x10
  6d0953:	39 5c 24 58          	cmp    DWORD PTR [esp+0x58],ebx
  6d0957:	73 04                	jae    0x6d095d
  6d0959:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  6d095d:	6a 00                	push   0x0
  6d095f:	8d 74 24 28          	lea    esi,[esp+0x28]
  6d0963:	e8 a8 e7 05 00       	call   0x72f110
  6d0968:	84 c0                	test   al,al
  6d096a:	0f 84 f8 02 00 00    	je     0x6d0c68
  6d0970:	68 a0 08 c4 00       	push   0xc408a0
  6d0975:	8b c6                	mov    eax,esi
  6d0977:	e8 64 d9 05 00       	call   0x72e2e0
  6d097c:	8b f0                	mov    esi,eax
  6d097e:	85 f6                	test   esi,esi
  6d0980:	74 1a                	je     0x6d099c
  6d0982:	8b 16                	mov    edx,DWORD PTR [esi]
  6d0984:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  6d0987:	8b ce                	mov    ecx,esi
  6d0989:	ff d0                	call   eax
  6d098b:	85 c0                	test   eax,eax
  6d098d:	74 0d                	je     0x6d099c
  6d098f:	8b 16                	mov    edx,DWORD PTR [esi]
  6d0991:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  6d0994:	8b ce                	mov    ecx,esi
  6d0996:	ff d0                	call   eax
  6d0998:	8b f0                	mov    esi,eax
  6d099a:	eb 02                	jmp    0x6d099e
  6d099c:	33 f6                	xor    esi,esi
  6d099e:	68 ac 08 c4 00       	push   0xc408ac
  6d09a3:	8d 7e 44             	lea    edi,[esi+0x44]
  6d09a6:	e8 f5 f6 05 00       	call   0x7300a0
  6d09ab:	85 c0                	test   eax,eax
  6d09ad:	74 19                	je     0x6d09c8
  6d09af:	83 c0 30             	add    eax,0x30
  6d09b2:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  6d09b5:	72 02                	jb     0x6d09b9
  6d09b7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d09b9:	85 c0                	test   eax,eax
  6d09bb:	74 0b                	je     0x6d09c8
  6d09bd:	50                   	push   eax
  6d09be:	e8 f1 0d 1c 00       	call   0x8917b4
  6d09c3:	83 c4 04             	add    esp,0x4
  6d09c6:	eb 02                	jmp    0x6d09ca
  6d09c8:	33 c0                	xor    eax,eax
  6d09ca:	a3 34 90 fb 00       	mov    ds:0xfb9034,eax
  6d09cf:	bf b8 08 c4 00       	mov    edi,0xc408b8
  6d09d4:	8b c6                	mov    eax,esi
  6d09d6:	e8 85 d9 05 00       	call   0x72e360
  6d09db:	8b d8                	mov    ebx,eax
  6d09dd:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  6d09e1:	85 db                	test   ebx,ebx
  6d09e3:	0f 84 63 02 00 00    	je     0x6d0c4c
  6d09e9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6d09f0:	68 fc 71 c0 00       	push   0xc071fc
  6d09f5:	8d 7b 44             	lea    edi,[ebx+0x44]
  6d09f8:	e8 a3 f6 05 00       	call   0x7300a0
  6d09fd:	85 c0                	test   eax,eax
  6d09ff:	0f 84 6c 01 00 00    	je     0x6d0b71
  6d0a05:	83 c0 30             	add    eax,0x30
  6d0a08:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d0a0c:	72 02                	jb     0x6d0a10
  6d0a0e:	8b 00                	mov    eax,DWORD PTR [eax]
  6d0a10:	85 c0                	test   eax,eax
  6d0a12:	0f 84 59 01 00 00    	je     0x6d0b71
  6d0a18:	50                   	push   eax
  6d0a19:	e8 96 0d 1c 00       	call   0x8917b4
  6d0a1e:	8b f0                	mov    esi,eax
  6d0a20:	83 c4 04             	add    esp,0x4
  6d0a23:	83 fe 03             	cmp    esi,0x3
  6d0a26:	0f 83 66 02 00 00    	jae    0x6d0c92
  6d0a2c:	bf c0 08 c4 00       	mov    edi,0xc408c0
  6d0a31:	8b c3                	mov    eax,ebx
  6d0a33:	e8 28 d9 05 00       	call   0x72e360
  6d0a38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6d0a3c:	85 c0                	test   eax,eax
  6d0a3e:	0f 84 ee 01 00 00    	je     0x6d0c32
  6d0a44:	8d 34 b6             	lea    esi,[esi+esi*4]
  6d0a47:	03 f6                	add    esi,esi
  6d0a49:	03 f6                	add    esi,esi
  6d0a4b:	03 f6                	add    esi,esi
  6d0a4d:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  6d0a51:	8b b0 94 00 00 00    	mov    esi,DWORD PTR [eax+0x94]
```

## 逐層分析與新結論

**獨立功能鏈 A — 通用動作可用性**：`0x546780` 合成輸入→`0x546100` 控制器處理→`0x54F270` flags + tier 驗證→`0x819220` 矩陣→`0x81A8E0` key/ID→`0x54F4E0` entry。已確認「輸入可用性 predicate」，沒有確認「動畫開始、技能扣藍、技能冷卻開始、接續窗口」。不能因普攻 Z 也屬技能就把這條當已經定位 combo 事件。

**獨立功能鏈 B — SubAI 目標／技能狀態**：`0x549D54` predicate 成功時寫 slot state 4；`0x549E10` 依幾何／目標資訊讀寫 state 1/2/3；`0x54A050` 認可 4、5、6 的 slot state，經全域 `0xFAB138` 樹以 slot+4 的候選 ID 找目標，再檢查 target+0x158/+0x34 的狀態與方向／距離。這是更多**與技能狀態關聯**的原版機器碼，但 state 4/5/6 不等於 V 三個蓄氣級別。

**通用配置與 V**：`0x6D08F0` 從 `Table/KeyMapping.xml` 讀入 KeyMapping、DefaultType、Type、Key；`0x6D0A23 cmp esi,3` 限制三組銀行的 index，載入每組 key row 的 16-byte slot。不同設定 Bank 並非自動等於三段蓄氣。用户能改按鍵意味著任何以 ASCII 0x5A 去找 Z skill ID 的方法都不可靠。

**四個必須閉環的銜接問題**：
1. Z 連按續普攻：要找 action pressed edge 進入 motion queue 與前段動作完成的 read。
2. Z held 續普攻：要找按住 state 的持續 writer／sampler；同一 action 是否在 motion window 再次消費。
3. 普攻→技能：要找初始普攻的 motion state/phase，轉向新的 skill key/tier 的 accept/cancel gate；只看到 availability 不能證明取消。
4. 技能→普攻：要找技能 motion completion 的 state reset 及 Z action 再許可；避免混同 SubAI 的 target reset。
5. V 點按 vs 長按及蓄氣改招：要找實際 V 訊息在 KeyMapping 的動作索引，以及兩種操作更改哪個 `tier` / queue field 的機器碼。

**本批跨 T11 候選整理（不更動其 owner）**：確立 skill availability=`0x54F270`；skill ID matrix=`0x819220/0x81A8E0`；存取/插入=`0x54F4E0`；SubAI state writer=`0x549D7D`、`0x549E76/0x549EAA/0x54A022`；SubAI 4/5/6 consumer=`0x54A050`；必須分開於玩家輸入事件分發=`0x5961C0`。

**追查順序優化**：與其繼續單純掃 FB9014，應以動作 ID→客戶端 motion 控制器→動作完成通知→下一段 accept 反推，再向 KeyMapping 映射回溯 Z/X/C/V。

## 證據分級及限制

- **已確認**：上述精確地址及機器碼、可見的記憶體讀寫和條件分支。
- **合理假說**：上述流程可能與 T10／T11 通用技能層相關；只把適合的欄位列為候選，不預先認作玩家蓄氣或普攻。
- **尚未驗證**：V 按鍵來源、四 tier 的實際觸發條件、Z/X/C 各自的映射值、連按 vs 長按、動畫完結時的下一招消費、扣除資源與冷卻 writer。
- **協作**：僅新增個人 `kr-temp-roy/T10/` 的交界分析；正式 T11 owner/task.json 和其他 Agent 筆記不修改。

## 後續定向追查

下一組 T10-29～32：查 `0x54A050` 的 caller/vtable 與 4/5/6 writer；查 `0x546100` 的 motion 入列 consumer、`0x54F270` 非零冷卻 writer、`0x6D4CE0` 正常非零鍵盤 state producer。取得真正 KeyMapping.xml 前不得命名按鍵 bit。