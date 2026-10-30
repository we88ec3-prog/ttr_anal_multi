# T16-115 — Quest14 子研究④：S→C 進度回覆、Scenario14 狀態與 QuestInfo 任務 UI 分層（BIN-first）

- 日期：20261030-030953 Asia/Taipei；作者：chatgpt-web roy；版本：KR。
- 原始來源：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- Git 開工核對：`main=9b21d12d6c97a7b5183c7ad87c1ba0e7512e2020`，`t16/roy/chatgpt-web=afde51ba3be5ffd539f58d21724b916057c89821`；當時 behind=2（主分支同步是後續維運動作，未經使用者要求不研究 Commit/Push）。
- 源碼地址：原始 BIN `.text` raw = VA − `0x400C00`；下列所有 19 個 slice 都由本輪原件與 objdump 計算且附 SHA256，非僅轉述既有報告。
- 既有主要來源：`T16-110-REV`（S2C `0x41/0x42/0x7F`）、`T16-111`（Scenario `0x4C`）、`T16-114`（Quest14 `0x36` C2S）。
- 研究目標：限定 Client 解析/寫入/消費；Server 的任務通關判定、保存、獎勵及解鎖交 S00，而不是等待原版 Server 封包紀錄。

## 1. 結論與明確完成界線

**可有界閉合**：在 `Scene::CTutorial` 活躍、接收分派到索引 `0x4C` 時，S2C business payload 最小讀取字節為 `4C 00 0E 00`（命令16bit + Scenario ID=14 的16bit），`0x4C4F20` 將 `0xFC0F88` 的 map[14] 寫成 DWORD `1`。Lua `Tutorial.IsScenarioEnded(14)` 使用同一 map 的 reader；未命中插入初值0。這是**Scenario14 結束回覆處理與 Lua 消費**，不是 QuestInfo ID14 的 completed/可交付旗標。`0x4A8A60` 在教學初始化會清掉該 map，所以先後順序重要。

**本次另獨立再查**：base Scene 接收表的三組業務命令 `0x41`、`0x42`、`0x7F` 分別更新固定記錄進度、可變 subtype 記錄與建立/更新記錄。它們是 Client 可解析的別種 S2C schema，但**尚沒有任何一條能由原生可達鏈證明是 QuestInfo ID14 的接受/完成/交付 ACK 或 Quest16 可接通知**。不能因存在 `0x41` 的 `(value,key)` 或 `0x42` 的 key 就推造 Quest14 完成值。`F4266` 是本地通知，非已證 quest UI listener。

**嚴格狀態**：子研究④的 *Scenario14 S2C/flag/Lua* 已完成；*QuestInfo ID14 之執行期 accept/completed 與 UI 受影響字段* **未閉合**。若將兩者混稱「Quest14-④ 全部原生證明」，會誤導 S00 開發。

## 2. Quest14 五項子研究狀態

| 子研究 | 狀態 | 已證／未證 |
|---|---|---|
| ① 靜態任務資源 | 已完成 | QuestInfo XML id14 type3、field18、NPC10027，Quest16 Demand14 |
| ② 玩家觸發 | 有界完成 | Tutorial Part1/Part2、伊希莉亞本地距離 gating；正式 XML 接取事件未必獨立存在 |
| ③ C→S | 有界完成 | Scenario14 `40 00 0E 00`；TalkBox 特定 mode/action 條件下 `36 00 0E 00`；不能定義 mode=接受/交付 |
| **④ S→C／狀態／UI** | **Scenario 已閉合；正式 Quest 未閉合** | `0x4C4F20` 與 Lua Scenario map；`0x41/0x42/0x7F` 的 record writers；Quest14 active/completed UI 語意未證 |
| ⑤ Quest14 完成→Quest16 解鎖 | 未閉合 | QuestInfo demand 已證；動態完成/解鎖 UI 及通知未證 |

## 3. 三輪深入：本次重新查證的有界主張

### 第一輪：Scenario14 真正的 S2C 回覆與本地 writer

1. CTutorial 建構時，在 `this+0x5EAC` 起的 8-byte-stride Scene override 表，`this+0x610C` 設為函式 `0x4C4F20`。`(0x610C-0x5EAC)/8=76=0x4C`；不是 base Scene index `0x41`、`0x42` 或 `0x7F`。
2. `0x4930E0 → 0x4C4670` 是有 `channel==2` 與場景分派條件的路由；只有 active CTutorial override 時才能具體選中上列 handler，不能對任意 scene 假設相同回覆。
3. `0x4C4F20` 從 payload `+2` 讀取 WORD key，`0x4C2880` 對 scenario map 進行查找/建立，`mov [ptr],1`；`0x4AA510` 對同 map 查出值，再由 Lua binding `0x4ACF90` 回傳。`map` miss 的預設 value=0；因此 Lua 等待不是讀取任意垃圾。
4. `0x4A8A60` 教學初始化會清除同一 map；若初始狀態被重設，原先收到的 key14 結束旗標不能假設保留。
5. **ABI**：`4C 00 0E 00` 是能滿足該 handler 所讀前四 bytes 的 *conditional Client app payload*；不是原版 Server 封包擷取、不含 0x1A68/0x0BBB 傳輸層 framing、不能據此推稱所有相關場景都只收 4 bytes。handler 本身未顯示對 `len>=4` 的局部檢查，不應忽略外層 framing/分派層。

### 第二輪：排除誤把通用進度 record 當成 Quest14 狀態

| cmd (S2C Scene table A) | handler / 本地 writers | 讀取 schema | 明確的 Client 副作用 | 不得冒稱 |
|---|---|---|---|---|
| 0x41 | 0x4B2310 → 0x53DB30 | `WORD cmd` + 反覆 `WORD value; WORD record_key`，N≤floor((len−2)/4) | 對已存在的 owner 0x14/0x18-byte records，以 `record+2` 比對 key，命中改 `record+8`；局部事件 F4266 | 不能設定 Quest14 completed=1；miss 不新建記錄 |
| 0x42 | 0x4B2190 → 0x500110／0x53D840 | `WORD cmd; WORD signed key; subtype-var-entries`；subtype1..11，10退出，9略過 writer | 對最多20個WORD的清單去重登記 key；符合 gate 者建／改 0x18-byte record | key是否 QuestID、record+0x14 是否 Quest14 semantic 未證 |
| 0x7F | 0x4B23C0 → 0x53D5E0 | `WORD cmd; variable entries` subtype1..8 | 建立／更新 0x14-byte record、投遞 F4266 | entry[4:6] 不能自動說是 QuestInfo ID |

收到 `0x41` payload 時，即使沒有命中記錄也可能發 F4266；不能用「有事件」作任務成功判斷。`0x42` 的 `len<=4` 情形可能只登記 key，並無實際 0x18-byte 記錄 writer；須分開驗證。`0x7F` 無合法 entry 時不等於「任務完成失敗」。

### 第三輪：Quest14 對話 C2S 與 UI consumer 的歧義及可交付 Server contract

1. `T16-114` 追出 QuestInfo `id` 在 XML record 第一 DWORD → QuestInfo map `[0xFB114C]` → `0x500F90` 讀取相同 value record → TalkBox `dialog+0x88` → `0x636E10` 取低 WORD 發 `36 00 0E 00`；僅在 mode1/2/3 中、特定 confirm event `0x6A7`、全域發送 gate開啟時成立。它**沒有在 C2S 這四字節中帶 mode/accept/complete 意圖**；因此即使找到本次三個 S2C writers，也不能按 `0x36` 本身反算 S2C 回覆必是哪個。
2. UI flag `0x635CA0` 使用 `0x500950`／`0x500E00` 的向量非空結果寫物件 `+0xB4/+0xB5`，但 **未驗證此控制物件等於 Quest14 特定 NPC / UI 或記錄 alias**。`0x5DF3A0` 回傳同值 `F4266` 是郵件附件 RTTI slot，不能當 Quest14 事件 listener；此為 T16-110-REV 已修正之反例。
3. Server 開發需按 **已實證的 parser 契約**產生適當資料：Scenario14 收到命令 `0x4C` + key14 的條件式反應已可交付 S00 設 DRAFT。QuestInfo14 正式任務 accept/completed/Quest16 availability 應先交由 S00 訂 authoritative state、轉移策略、錯誤/冪等與持久化 ADR；但 **Quest14 專屬 S2C opcode/key/欄位與 UI callback 仍屬 Client 研究缺口**，不能由 S00 猜字節補齊。
4. 真正可用的後續 Client 研究入口是：將 Quest14 畫面實際事件 `event+0x14` 與動態 map `FAB134`／`FAB2A0` 的 writer、`0x635CA0` 及 active Scene 的 tableB override 做端到端 alias／精確欄位配對，而不是再搜尋「Server 如何判定 Quest14 完成」。

## 4. 嚴格失敗分支與可生成的有界測試案例（設計，未實測）

| 測試前提 / message | 原生 handler 路徑預期 | 驗收性質 |
|---|---|---|
| CTutorial active, channel2, `4C 00 0E 00`，init已完成 | map[14]←1，Lua IsScenarioEnded(14)→1 | conditional Client ABI；未作 runtime test |
| 先 `4C 00 0E 00`，後再 init | map clear 可能抹去該狀態 | conditional ordering |
| 其他 Scene，`4C 00 0E 00` | 不保證 CTutorial handler 可達 | scene override proof required |
| CTutorial active, `4C 00 0F 00` | map[15]←1；不意味 map[14]←1 | key separation |
| `0x41` with unmatched `record_key` | 不寫指定既有 record；仍可能 F4266 | record provenance |
| `0x42` 只有四字節、無 entries | 可能 key 登記，但不寫 0x18-byte entry | field gate |
| `0x7F` 非法 subtype | 不按合法 subtype writer 路徑處理 | negative gate |
| Quest14 `36 00 0E 00` 確認後 | Client 只能確定送出；未證特定S2C Quest14 ACK | no made-up Server semantics |

## 5. S00 交接（待登記、未改遠端正式台帳）

- `SPEC-DRAFT-Q14-SCENARIO`: KR `Scene::CTutorial` 接收 channel2 cmd `0x4C`, `scenario_id:u16`, map value=1；附上場景初始化重設及 Lua consumer 條件。注意與 QuestInfo ID namespace 隔離。
- `GAP-T16-Q14-QUESTSTATE-CLIENT`: 找到 QuestInfo ID14 接取／交付／完成用的 Client S2C opcode、key 及 runtime owner 更新欄位，以及 NPC UI listener。T16 原生事實缺口，尚未關閉；不得偽造 packet bytes。
- `ADR-Q14-SERVER-POLICY-PROPOSED`: 由 S00 決定 Quest14 authoritative 完成判定、Quest16 Demand14 availability 策略、重試/重登/持久化；並調 T14/T15 協作。Server 政策未知**不是 T16 原生分析阻塞**。
- `TEST-Q14-S2C-CONDITIONAL`: 上節 conditional parser 測試；**尚未執行原版 Client runtime 實測**，無法直接宣稱 compatible Server 已可玩。
- 不是現有 RR-0005（其 owner=T02），也**尚未提交到任何正式 S00 台帳**。

## 6. 證據方法與校正：同名 Quest vs Scenario 禁止自動等同

- XML QuestInfo ID14 的 `type=3`, `town=0`, `field=18`, `level=1`, `giver=finisher=10027`, `AcceptAction type=1`, `CompleteAction type=1` 和 Quest16 Demand14 由原始完整 QuestInfo.xml 取值；它是**靜態資源**。
- Lua `Tutorial.RequestStartScenario(14)` / `IsScenarioEnded(14)` 的數值 14 是 native Scenario map key；**未證與 QuestInfo Record 14 共享生命週期**。
- 0x41/0x42/0x7F 接收表的記錄鍵不應無根據直接命名為 Quest14 完成度。
- 在沒有直接 alias 與 Writer→Reader CFG 時，負責任的結案判定是 **Scenario14 S2C 已閉合，Quest14 quest-state 尚有確切原生 GAP**；不能只用「Server 行為交由 S00」遮掩真實 Client ABI 未知。

## 7. 19 組原始 BIN 有界組語附錄

每組的 slice bytes SHA256 可依 `raw=VA-0x400C00` 重算，後面為 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 的唯讀輸出。切片起始可能不是函式真正入口的情況須用上下文與可達 CFG 判讀；不能因反組譯器將跳表當指令而猜語意。完整輸出保留以免聊天摘要壓縮原生證據。

### client_dispatch VA `0x004930E0–0x00493270`, raw `0x000924E0–0x00092670`, SHA256 `f2c62ef501b31c669c443e2da3f093b2e903084ac431dce991db98f05f8d4bc4`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004930e0 <.data+0x924e0>:
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
  49320c:	ba b0 43 49 00       	mov    edx,0x4943b0
  493211:	89 90 08 09 00 00    	mov    DWORD PTR [eax+0x908],edx
  493217:	ba b0 43 49 00       	mov    edx,0x4943b0
  49321c:	89 90 98 04 00 00    	mov    DWORD PTR [eax+0x498],edx
  493222:	ba b0 43 49 00       	mov    edx,0x4943b0
  493227:	89 90 e8 03 00 00    	mov    DWORD PTR [eax+0x3e8],edx
  49322d:	ba b0 43 49 00       	mov    edx,0x4943b0
  493232:	89 90 48 06 00 00    	mov    DWORD PTR [eax+0x648],edx
  493238:	ba b0 43 49 00       	mov    edx,0x4943b0
  49323d:	89 90 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],edx
  493243:	ba b0 43 49 00       	mov    edx,0x4943b0
  493248:	89 90 c8 04 00 00    	mov    DWORD PTR [eax+0x4c8],edx
  49324e:	ba b0 43 49 00       	mov    edx,0x4943b0
  493253:	89 90 18 15 00 00    	mov    DWORD PTR [eax+0x1518],edx
  493259:	ba b0 43 49 00       	mov    edx,0x4943b0
  49325e:	89 90 d8 04 00 00    	mov    DWORD PTR [eax+0x4d8],edx
  493264:	ba b0 43 49 00       	mov    edx,0x4943b0
  493269:	89 90 18 08 00 00    	mov    DWORD PTR [eax+0x818],edx
  49326f:	ba           	mov    edx,0x4943b0
```

### scene_dispatch VA `0x004C4670–0x004C476B`, raw `0x000C3A70–0x000C3B6B`, SHA256 `dc6cdc26664d8350469bed46479e1f4123936a2610d3e0d00f7f1e091a933e27`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4670 <.data+0xc3a70>:
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
  4c4768:	a1 20 1f         	mov    eax,ds:0xd61f20
```

### tutorial_ctor VA `0x004C4AC0–0x004C4B3B`, raw `0x000C3EC0–0x000C3F3B`, SHA256 `799b4fe0f8078f0de0915818014c5807ad3590628f86abd2438e3c8d991362ef`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4ac0 <.data+0xc3ec0>:
  4c4ac0:	8b c6                	mov    eax,esi
  4c4ac2:	e8 89 92 fe ff       	call   0x4add50
  4c4ac7:	68 a8 5e 00 00       	push   0x5ea8
  4c4acc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4ad2:	6a 00                	push   0x0
  4c4ad4:	50                   	push   eax
  4c4ad5:	c7 06 e8 73 c0 00    	mov    DWORD PTR [esi],0xc073e8
  4c4adb:	c7 05 74 a6 d6 00 4f 	mov    DWORD PTR ds:0xd6a674,0x5455544f
  4c4ae2:	54 55 54 
  4c4ae5:	e8 76 9d 3d 00       	call   0x89e860
  4c4aea:	83 c4 0c             	add    esp,0xc
  4c4aed:	c7 86 0c 61 00 00 20 	mov    DWORD PTR [esi+0x610c],0x4c4f20
  4c4af4:	4f 4c 00 
  4c4af7:	c7 86 10 61 00 00 75 	mov    DWORD PTR [esi+0x6110],0xbf2375
  4c4afe:	23 bf 00 
  4c4b01:	8b c6                	mov    eax,esi
  4c4b03:	c3                   	ret
  4c4b04:	cc                   	int3
  4c4b05:	cc                   	int3
  4c4b06:	cc                   	int3
  4c4b07:	cc                   	int3
  4c4b08:	cc                   	int3
  4c4b09:	cc                   	int3
  4c4b0a:	cc                   	int3
  4c4b0b:	cc                   	int3
  4c4b0c:	cc                   	int3
  4c4b0d:	cc                   	int3
  4c4b0e:	cc                   	int3
  4c4b0f:	cc                   	int3
  4c4b10:	55                   	push   ebp
  4c4b11:	8b ec                	mov    ebp,esp
  4c4b13:	83 e4 f8             	and    esp,0xfffffff8
  4c4b16:	6a ff                	push   0xffffffff
  4c4b18:	68 51 a5 93 00       	push   0x93a551
  4c4b1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4b23:	50                   	push   eax
  4c4b24:	83 ec 08             	sub    esp,0x8
  4c4b27:	53                   	push   ebx
  4c4b28:	56                   	push   esi
  4c4b29:	57                   	push   edi
  4c4b2a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4b2f:	33 c4                	xor    eax,esp
  4c4b31:	50                   	push   eax
  4c4b32:	8d 44 24 18          	lea    eax,[esp+0x18]
  4c4b36:	64 a3 00 00 00     	mov    fs:0x0,eax
```

### tutorial_init VA `0x004C4D28–0x004C4D76`, raw `0x000C4128–0x000C4176`, SHA256 `933e779f1c2a3274b12106fb267a53e0fb5a013374d8ab6678bf765c89e8b7f0`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4d28 <.data+0xc4128>:
  4c4d28:	ff 68 70             	jmp    FWORD PTR [eax+0x70]
  4c4d2b:	db bc 00 e8 e7 d5 3c 	fstp   TBYTE PTR [eax+eax*1+0x3cd5e7e8]
  4c4d32:	00 83 c4 04 89 5c    	add    BYTE PTR [ebx+0x5c8904c4],al
  4c4d38:	24 20                	and    al,0x20
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4c4d4a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4d51:	59                   	pop    ecx
  4c4d52:	5f                   	pop    edi
  4c4d53:	5e                   	pop    esi
  4c4d54:	5b                   	pop    ebx
  4c4d55:	8b e5                	mov    esp,ebp
  4c4d57:	5d                   	pop    ebp
  4c4d58:	c3                   	ret
  4c4d59:	cc                   	int3
  4c4d5a:	cc                   	int3
  4c4d5b:	cc                   	int3
  4c4d5c:	cc                   	int3
  4c4d5d:	cc                   	int3
  4c4d5e:	cc                   	int3
  4c4d5f:	cc                   	int3
  4c4d60:	55                   	push   ebp
  4c4d61:	8b ec                	mov    ebp,esp
  4c4d63:	6a ff                	push   0xffffffff
  4c4d65:	68 ce 3e 93 00       	push   0x933ece
  4c4d6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4d70:	50                   	push   eax
  4c4d71:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
```

### tutorial_reply_4c VA `0x004C4F20–0x004C4F9B`, raw `0x000C4320–0x000C439B`, SHA256 `3b64b497e11b9350c22095f5fe0e7824ab0d30a9842104163e8d7e9c83b79352`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4f20 <.data+0xc4320>:
  4c4f20:	55                   	push   ebp
  4c4f21:	8b ec                	mov    ebp,esp
  4c4f23:	6a ff                	push   0xffffffff
  4c4f25:	68 9e 76 92 00       	push   0x92769e
  4c4f2a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4f30:	50                   	push   eax
  4c4f31:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4f36:	33 c5                	xor    eax,ebp
  4c4f38:	50                   	push   eax
  4c4f39:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4f3c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4f42:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4f49:	75 27                	jne    0x4c4f72
  4c4f4b:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  4c4f52:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4f59:	e8 52 5f fb ff       	call   0x47aeb0
  4c4f5e:	68 70 db bc 00       	push   0xbcdb70
  4c4f63:	e8 b2 d3 3c 00       	call   0x89231a
  4c4f68:	83 c4 04             	add    esp,0x4
  4c4f6b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4f72:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c4f75:	0f b7 48 02          	movzx  ecx,WORD PTR [eax+0x2]
  4c4f79:	8d 55 08             	lea    edx,[ebp+0x8]
  4c4f7c:	b8 88 0f fc 00       	mov    eax,0xfc0f88
  4c4f81:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c4f84:	e8 f7 d8 ff ff       	call   0x4c2880
  4c4f89:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  4c4f8f:	33 c0                	xor    eax,eax
  4c4f91:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4f94:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
```

### scenario_map VA `0x004C2880–0x004C2950`, raw `0x000C1C80–0x000C1D50`, SHA256 `127b41aa06db4bf335991d024c50fa15f178e61cda0e0d55b67de9bb3aa833d1`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c2880 <.data+0xc1c80>:
  4c2880:	55                   	push   ebp
  4c2881:	8b ec                	mov    ebp,esp
  4c2883:	83 ec 0c             	sub    esp,0xc
  4c2886:	53                   	push   ebx
  4c2887:	56                   	push   esi
  4c2888:	8b f0                	mov    esi,eax
  4c288a:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4c288d:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4c2890:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4c2894:	57                   	push   edi
  4c2895:	8b d9                	mov    ebx,ecx
  4c2897:	75 1b                	jne    0x4c28b4
  4c2899:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4c289b:	eb 03                	jmp    0x4c28a0
  4c289d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c28a0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  4c28a3:	7d 05                	jge    0x4c28aa
  4c28a5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4c28a8:	eb 04                	jmp    0x4c28ae
  4c28aa:	8b d8                	mov    ebx,eax
  4c28ac:	8b 00                	mov    eax,DWORD PTR [eax]
  4c28ae:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4c28b2:	74 ec                	je     0x4c28a0
  4c28b4:	3b 5e 04             	cmp    ebx,DWORD PTR [esi+0x4]
  4c28b7:	74 07                	je     0x4c28c0
  4c28b9:	8b 02                	mov    eax,DWORD PTR [edx]
  4c28bb:	3b 43 0c             	cmp    eax,DWORD PTR [ebx+0xc]
  4c28be:	7d 2d                	jge    0x4c28ed
  4c28c0:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4c28c2:	8d 7d f8             	lea    edi,[ebp-0x8]
  4c28c5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  4c28c8:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c28cf:	e8 4c c6 0b 00       	call   0x57ef20
  4c28d4:	53                   	push   ebx
  4c28d5:	8d 55 fc             	lea    edx,[ebp-0x4]
  4c28d8:	52                   	push   edx
  4c28d9:	8b ce                	mov    ecx,esi
  4c28db:	e8 00 91 fe ff       	call   0x4ab9e0
  4c28e0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4c28e3:	83 c0 10             	add    eax,0x10
  4c28e6:	5f                   	pop    edi
  4c28e7:	5e                   	pop    esi
  4c28e8:	5b                   	pop    ebx
  4c28e9:	8b e5                	mov    esp,ebp
  4c28eb:	5d                   	pop    ebp
  4c28ec:	c3                   	ret
  4c28ed:	5f                   	pop    edi
  4c28ee:	5e                   	pop    esi
  4c28ef:	8d 43 10             	lea    eax,[ebx+0x10]
  4c28f2:	5b                   	pop    ebx
  4c28f3:	8b e5                	mov    esp,ebp
  4c28f5:	5d                   	pop    ebp
  4c28f6:	c3                   	ret
  4c28f7:	cc                   	int3
  4c28f8:	cc                   	int3
  4c28f9:	cc                   	int3
  4c28fa:	cc                   	int3
  4c28fb:	cc                   	int3
  4c28fc:	cc                   	int3
  4c28fd:	cc                   	int3
  4c28fe:	cc                   	int3
  4c28ff:	cc                   	int3
  4c2900:	55                   	push   ebp
  4c2901:	8b ec                	mov    ebp,esp
  4c2903:	51                   	push   ecx
  4c2904:	50                   	push   eax
  4c2905:	8b ce                	mov    ecx,esi
  4c2907:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c290e:	e8 0d 00 00 00       	call   0x4c2920
  4c2913:	83 c4 04             	add    esp,0x4
  4c2916:	8b c6                	mov    eax,esi
  4c2918:	8b e5                	mov    esp,ebp
  4c291a:	5d                   	pop    ebp
  4c291b:	c3                   	ret
  4c291c:	cc                   	int3
  4c291d:	cc                   	int3
  4c291e:	cc                   	int3
  4c291f:	cc                   	int3
  4c2920:	55                   	push   ebp
  4c2921:	8b ec                	mov    ebp,esp
  4c2923:	6a ff                	push   0xffffffff
  4c2925:	68 72 e4 91 00       	push   0x91e472
  4c292a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c2930:	50                   	push   eax
  4c2931:	81 ec 2c 01 00 00    	sub    esp,0x12c
  4c2937:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c293c:	33 c5                	xor    eax,ebp
  4c293e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c2941:	53                   	push   ebx
  4c2942:	56                   	push   esi
  4c2943:	57                   	push   edi
  4c2944:	50                   	push   eax
  4c2945:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c2948:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c294e:	33 d2                	xor    edx,edx
```

### scenario_read VA `0x004AA510–0x004AA578`, raw `0x000A9910–0x000A9978`, SHA256 `19e874c5db79f43613afe7f4c64c55286488b05066dc5de32e2fbb96b090fde0`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa510 <.data+0xa9910>:
  4aa510:	55                   	push   ebp
  4aa511:	8b ec                	mov    ebp,esp
  4aa513:	8d 41 04             	lea    eax,[ecx+0x4]
  4aa516:	8d 55 08             	lea    edx,[ebp+0x8]
  4aa519:	e8 62 83 01 00       	call   0x4c2880
  4aa51e:	8b 00                	mov    eax,DWORD PTR [eax]
  4aa520:	5d                   	pop    ebp
  4aa521:	c2 04 00             	ret    0x4
  4aa524:	cc                   	int3
  4aa525:	cc                   	int3
  4aa526:	cc                   	int3
  4aa527:	cc                   	int3
  4aa528:	cc                   	int3
  4aa529:	cc                   	int3
  4aa52a:	cc                   	int3
  4aa52b:	cc                   	int3
  4aa52c:	cc                   	int3
  4aa52d:	cc                   	int3
  4aa52e:	cc                   	int3
  4aa52f:	cc                   	int3
  4aa530:	55                   	push   ebp
  4aa531:	8b ec                	mov    ebp,esp
  4aa533:	51                   	push   ecx
  4aa534:	53                   	push   ebx
  4aa535:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4aa538:	56                   	push   esi
  4aa539:	8b f1                	mov    esi,ecx
  4aa53b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  4aa53e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  4aa541:	80 79 41 00          	cmp    BYTE PTR [ecx+0x41],0x0
  4aa545:	75 1f                	jne    0x4aa566
  4aa547:	57                   	push   edi
  4aa548:	0f b7 3b             	movzx  edi,WORD PTR [ebx]
  4aa54b:	eb 03                	jmp    0x4aa550
  4aa54d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4aa550:	66 39 79 0c          	cmp    WORD PTR [ecx+0xc],di
  4aa554:	7d 05                	jge    0x4aa55b
  4aa556:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  4aa559:	eb 04                	jmp    0x4aa55f
  4aa55b:	8b d1                	mov    edx,ecx
  4aa55d:	8b 09                	mov    ecx,DWORD PTR [ecx]
  4aa55f:	80 79 41 00          	cmp    BYTE PTR [ecx+0x41],0x0
  4aa563:	74 eb                	je     0x4aa550
  4aa565:	5f                   	pop    edi
  4aa566:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4aa569:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  4aa56c:	3b d1                	cmp    edx,ecx
  4aa56e:	74 18                	je     0x4aa588
  4aa570:	66 8b 33             	mov    si,WORD PTR [ebx]
  4aa573:	66 3b 72 0c          	cmp    si,WORD PTR [edx+0xc]
  4aa577:	7c                 	jl     0x4aa588
```

### scenario_req VA `0x004AA4D0–0x004AA510`, raw `0x000A98D0–0x000A9910`, SHA256 `71263a85ac0ab468ae0aba3f19dfd1da6a42ef2f687f0415a3567ddb70366227`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa4d0 <.data+0xa98d0>:
  4aa4d0:	55                   	push   ebp
  4aa4d1:	8b ec                	mov    ebp,esp
  4aa4d3:	51                   	push   ecx
  4aa4d4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4aa4db:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4aa4df:	b8 40 00 00 00       	mov    eax,0x40
  4aa4e4:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4aa4e8:	66 89 4d fe          	mov    WORD PTR [ebp-0x2],cx
  4aa4ec:	75 15                	jne    0x4aa503
  4aa4ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4aa4f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa4f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4aa4f9:	6a 04                	push   0x4
  4aa4fb:	8d 45 fc             	lea    eax,[ebp-0x4]
  4aa4fe:	50                   	push   eax
  4aa4ff:	6a 00                	push   0x0
  4aa501:	ff d2                	call   edx
  4aa503:	8b e5                	mov    esp,ebp
  4aa505:	5d                   	pop    ebp
  4aa506:	c2 04 00             	ret    0x4
  4aa509:	cc                   	int3
  4aa50a:	cc                   	int3
  4aa50b:	cc                   	int3
  4aa50c:	cc                   	int3
  4aa50d:	cc                   	int3
  4aa50e:	cc                   	int3
  4aa50f:	cc                   	int3
```

### quest_dialog_send VA `0x00636DE0–0x00636EBD`, raw `0x002361E0–0x002362BD`, SHA256 `cedb8421b8e7fcc97231d30dfc14f0bcb09af39a75d8e18717fe250dc2e9d17e`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636de0 <.data+0x2361e0>:
  636de0:	55                   	push   ebp
  636de1:	8b ec                	mov    ebp,esp
  636de3:	56                   	push   esi
  636de4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  636de7:	57                   	push   edi
  636de8:	8b f9                	mov    edi,ecx
  636dea:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636df0:	8b 01                	mov    eax,DWORD PTR [ecx]
  636df2:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  636df5:	56                   	push   esi
  636df6:	ff d2                	call   edx
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
  636e06:	5f                   	pop    edi
  636e07:	5e                   	pop    esi
  636e08:	5d                   	pop    ebp
  636e09:	c2 04 00             	ret    0x4
  636e0c:	cc                   	int3
  636e0d:	cc                   	int3
  636e0e:	cc                   	int3
  636e0f:	cc                   	int3
  636e10:	55                   	push   ebp
  636e11:	8b ec                	mov    ebp,esp
  636e13:	51                   	push   ecx
  636e14:	85 f6                	test   esi,esi
  636e16:	74 28                	je     0x636e40
  636e18:	8b 06                	mov    eax,DWORD PTR [esi]
  636e1a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  636e1d:	8b ce                	mov    ecx,esi
  636e1f:	ff d2                	call   edx
  636e21:	3d bd 05 01 00       	cmp    eax,0x105bd
  636e26:	75 04                	jne    0x636e2c
  636e28:	8b c6                	mov    eax,esi
  636e2a:	eb 16                	jmp    0x636e42
  636e2c:	6a 00                	push   0x0
  636e2e:	68 c0 1f bf 00       	push   0xbf1fc0
  636e33:	68 18 21 bf 00       	push   0xbf2118
  636e38:	6a 00                	push   0x0
  636e3a:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  636e40:	33 c0                	xor    eax,eax
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
  636eb9:	3d a8 06 00        	cmp    eax,0x6a8
```

### talkbox_mode VA `0x00636620–0x006366F6`, raw `0x00235A20–0x00235AF6`, SHA256 `38f71e6dcc7447d20290b65ec65b19be80737fcbca0ed6454b3a4b4cffe1807e`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636620 <.data+0x235a20>:
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
  6366ed:	8b 17                	mov    edx,DWORD PTR [edi]
  6366ef:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  6366f5:	8b                 	mov    ecx,edi
```

### quest_s2c_41 VA `0x004B2310–0x004B23BD`, raw `0x000B1710–0x000B17BD`, SHA256 `82c8b1814ef88a988f84cf8f1674cbf424fb68b02252641dbab79cce02ec8646`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b2310 <.data+0xb1710>:
  4b2310:	55                   	push   ebp
  4b2311:	8b ec                	mov    ebp,esp
  4b2313:	6a ff                	push   0xffffffff
  4b2315:	68 7e c7 93 00       	push   0x93c77e
  4b231a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2320:	50                   	push   eax
  4b2321:	56                   	push   esi
  4b2322:	57                   	push   edi
  4b2323:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2328:	33 c5                	xor    eax,ebp
  4b232a:	50                   	push   eax
  4b232b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b232e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2334:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b2337:	83 f8 02             	cmp    eax,0x2
  4b233a:	73 04                	jae    0x4b2340
  4b233c:	33 ff                	xor    edi,edi
  4b233e:	eb 06                	jmp    0x4b2346
  4b2340:	8d 78 fe             	lea    edi,[eax-0x2]
  4b2343:	c1 ef 02             	shr    edi,0x2
  4b2346:	85 ff                	test   edi,edi
  4b2348:	74 22                	je     0x4b236c
  4b234a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b234d:	83 c6 02             	add    esi,0x2
  4b2350:	e8 0b cd f5 ff       	call   0x40f060
  4b2355:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  4b2358:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b235b:	66 8b 56 02          	mov    dx,WORD PTR [esi+0x2]
  4b235f:	51                   	push   ecx
  4b2360:	50                   	push   eax
  4b2361:	e8 ca b7 08 00       	call   0x53db30
  4b2366:	83 c6 04             	add    esi,0x4
  4b2369:	4f                   	dec    edi
  4b236a:	75 e4                	jne    0x4b2350
  4b236c:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2373:	75 27                	jne    0x4b239c
  4b2375:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b237c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2383:	e8 f8 50 0d 00       	call   0x587480
  4b2388:	68 c0 cc bc 00       	push   0xbcccc0
  4b238d:	e8 88 ff 3d 00       	call   0x89231a
  4b2392:	83 c4 04             	add    esp,0x4
  4b2395:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b239c:	68 66 42 0f 00       	push   0xf4266
  4b23a1:	e8 2a 87 0d 00       	call   0x58aad0
  4b23a6:	83 c4 04             	add    esp,0x4
  4b23a9:	33 c0                	xor    eax,eax
  4b23ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b23ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b23b5:	59                   	pop    ecx
  4b23b6:	5f                   	pop    edi
  4b23b7:	5e                   	pop    esi
  4b23b8:	8b e5                	mov    esp,ebp
  4b23ba:	5d                   	pop    ebp
  4b23bb:	c2 0c              	ret    0xc
```

### quest_s2c_42 VA `0x004B2190–0x004B22D6`, raw `0x000B1590–0x000B16D6`, SHA256 `f83a520440167d05feba4c2ef7e1ed5efa499494d242637c6cb4e23845da2e50`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b2190 <.data+0xb1590>:
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
```

### quest_s2c_7f VA `0x004B23C0–0x004B24BC`, raw `0x000B17C0–0x000B18BC`, SHA256 `cc881e41c8dcb04dae86bb02571c530f3507233d54a52f2b57b962f4e0ad6209`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b23c0 <.data+0xb17c0>:
  4b23c0:	55                   	push   ebp
  4b23c1:	8b ec                	mov    ebp,esp
  4b23c3:	6a ff                	push   0xffffffff
  4b23c5:	68 de 54 94 00       	push   0x9454de
  4b23ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b23d0:	50                   	push   eax
  4b23d1:	53                   	push   ebx
  4b23d2:	56                   	push   esi
  4b23d3:	57                   	push   edi
  4b23d4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b23d9:	33 c5                	xor    eax,ebp
  4b23db:	50                   	push   eax
  4b23dc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b23df:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b23e5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b23e8:	be 02 00 00 00       	mov    esi,0x2
  4b23ed:	03 fe                	add    edi,esi
  4b23ef:	e8 6c cc f5 ff       	call   0x40f060
  4b23f4:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  4b23f7:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4b23fa:	8b 03                	mov    eax,DWORD PTR [ebx]
  4b23fc:	3b c1                	cmp    eax,ecx
  4b23fe:	74 0e                	je     0x4b240e
  4b2400:	50                   	push   eax
  4b2401:	8b d1                	mov    edx,ecx
  4b2403:	e8 68 7e 04 00       	call   0x4fa270
  4b2408:	83 c4 04             	add    esp,0x4
  4b240b:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  4b240e:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4b2411:	3b de                	cmp    ebx,esi
  4b2413:	0f 86 9b 00 00 00    	jbe    0x4b24b4
  4b2419:	0f b6 47 01          	movzx  eax,BYTE PTR [edi+0x1]
  4b241d:	48                   	dec    eax
  4b241e:	89 7d 08             	mov    DWORD PTR [ebp+0x8],edi
  4b2421:	83 f8 07             	cmp    eax,0x7
  4b2424:	0f 87 8a 00 00 00    	ja     0x4b24b4
  4b242a:	ff 24 85 cc 24 4b 00 	jmp    DWORD PTR [eax*4+0x4b24cc]
  4b2431:	83 c7 0f             	add    edi,0xf
  4b2434:	83 c6 0f             	add    esi,0xf
  4b2437:	eb 16                	jmp    0x4b244f
  4b2439:	83 c7 0b             	add    edi,0xb
  4b243c:	83 c6 0b             	add    esi,0xb
  4b243f:	eb 0e                	jmp    0x4b244f
  4b2441:	83 c7 0d             	add    edi,0xd
  4b2444:	83 c6 0d             	add    esi,0xd
  4b2447:	eb 06                	jmp    0x4b244f
  4b2449:	83 c7 0a             	add    edi,0xa
  4b244c:	83 c6 0a             	add    esi,0xa
  4b244f:	3b f3                	cmp    esi,ebx
  4b2451:	76 0d                	jbe    0x4b2460
  4b2453:	68 bc 6c bf 00       	push   0xbf6cbc
  4b2458:	e8 03 b7 23 00       	call   0x6edb60
  4b245d:	83 c4 04             	add    esp,0x4
  4b2460:	e8 fb cb f5 ff       	call   0x40f060
  4b2465:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b2468:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b246b:	51                   	push   ecx
  4b246c:	50                   	push   eax
  4b246d:	e8 6e b1 08 00       	call   0x53d5e0
  4b2472:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2479:	75 27                	jne    0x4b24a2
  4b247b:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b2482:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2489:	e8 f2 4f 0d 00       	call   0x587480
  4b248e:	68 c0 cc bc 00       	push   0xbcccc0
  4b2493:	e8 82 fe 3d 00       	call   0x89231a
  4b2498:	83 c4 04             	add    esp,0x4
  4b249b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b24a2:	68 66 42 0f 00       	push   0xf4266
  4b24a7:	e8 24 86 0d 00       	call   0x58aad0
  4b24ac:	83 c4 04             	add    esp,0x4
  4b24af:	e9 5d ff ff ff       	jmp    0x4b2411
  4b24b4:	33 c0                	xor    eax,eax
  4b24b6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b24b9:	64 89 0d     	mov    DWORD PTR fs:0x0,ecx
```

### quest_record_41 VA `0x0053DB30–0x0053DC90`, raw `0x0013CF30–0x0013D090`, SHA256 `fe14b34388e88ba0d88f7c79da76571883ef470f656b475efa0b38a0593e0e0c`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0053db30 <.data+0x13cf30>:
  53db30:	55                   	push   ebp
  53db31:	8b ec                	mov    ebp,esp
  53db33:	6a ff                	push   0xffffffff
  53db35:	68 6c a2 93 00       	push   0x93a26c
  53db3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53db40:	50                   	push   eax
  53db41:	83 ec 0c             	sub    esp,0xc
  53db44:	53                   	push   ebx
  53db45:	56                   	push   esi
  53db46:	57                   	push   edi
  53db47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53db4c:	33 c5                	xor    eax,ebp
  53db4e:	50                   	push   eax
  53db4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  53db52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53db58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53db5b:	8b 07                	mov    eax,DWORD PTR [edi]
  53db5d:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db60:	74 1b                	je     0x53db7d
  53db62:	0f bf ca             	movsx  ecx,dx
  53db65:	0f b7 70 02          	movzx  esi,WORD PTR [eax+0x2]
  53db69:	3b f1                	cmp    esi,ecx
  53db6b:	75 08                	jne    0x53db75
  53db6d:	66 8b 75 0c          	mov    si,WORD PTR [ebp+0xc]
  53db71:	66 89 70 08          	mov    WORD PTR [eax+0x8],si
  53db75:	83 c0 14             	add    eax,0x14
  53db78:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db7b:	75 e8                	jne    0x53db65
  53db7d:	8b 5f 10             	mov    ebx,DWORD PTR [edi+0x10]
  53db80:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53db83:	0f 84 f0 00 00 00    	je     0x53dc79
  53db89:	0f bf c2             	movsx  eax,dx
  53db8c:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  53db8f:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  53db93:	3b 4d f0             	cmp    ecx,DWORD PTR [ebp-0x10]
  53db96:	0f 85 d1 00 00 00    	jne    0x53dc6d
  53db9c:	66 83 7b 04 03       	cmp    WORD PTR [ebx+0x4],0x3
  53dba1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  53dba5:	66 89 53 08          	mov    WORD PTR [ebx+0x8],dx
  53dba9:	0f 85 be 00 00 00    	jne    0x53dc6d
  53dbaf:	f6 05 a4 d9 f8 00 01 	test   BYTE PTR ds:0xf8d9a4,0x1
  53dbb6:	0f b7 73 0c          	movzx  esi,WORD PTR [ebx+0xc]
  53dbba:	75 27                	jne    0x53dbe3
  53dbbc:	83 0d a4 d9 f8 00 01 	or     DWORD PTR ds:0xf8d9a4,0x1
  53dbc3:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  53dbca:	e8 51 e5 fd ff       	call   0x51c120
  53dbcf:	68 90 cc bc 00       	push   0xbccc90
  53dbd4:	e8 41 47 35 00       	call   0x89231a
  53dbd9:	83 c4 04             	add    esp,0x4
  53dbdc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dbe3:	8b 15 1c d9 f8 00    	mov    edx,DWORD PTR ds:0xf8d91c
  53dbe9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  53dbec:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dbf0:	8b ca                	mov    ecx,edx
  53dbf2:	75 14                	jne    0x53dc08
  53dbf4:	39 70 0c             	cmp    DWORD PTR [eax+0xc],esi
  53dbf7:	7d 05                	jge    0x53dbfe
  53dbf9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  53dbfc:	eb 04                	jmp    0x53dc02
  53dbfe:	8b c8                	mov    ecx,eax
  53dc00:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc02:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dc06:	74 ec                	je     0x53dbf4
  53dc08:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  53dc0b:	3b ca                	cmp    ecx,edx
  53dc0d:	74 0a                	je     0x53dc19
  53dc0f:	3b 71 0c             	cmp    esi,DWORD PTR [ecx+0xc]
  53dc12:	7c 05                	jl     0x53dc19
  53dc14:	8d 45 ec             	lea    eax,[ebp-0x14]
  53dc17:	eb 06                	jmp    0x53dc1f
  53dc19:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53dc1c:	8d 45 e8             	lea    eax,[ebp-0x18]
  53dc1f:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc21:	3b c2                	cmp    eax,edx
  53dc23:	74 48                	je     0x53dc6d
  53dc25:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  53dc28:	85 f6                	test   esi,esi
  53dc2a:	74 41                	je     0x53dc6d
  53dc2c:	f6 05 c0 1a fc 00 01 	test   BYTE PTR ds:0xfc1ac0,0x1
  53dc33:	75 27                	jne    0x53dc5c
  53dc35:	b8 01 00 00 00       	mov    eax,0x1
  53dc3a:	09 05 c0 1a fc 00    	or     DWORD PTR ds:0xfc1ac0,eax
  53dc40:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53dc43:	e8 b8 a4 01 00       	call   0x558100
  53dc48:	68 a0 de bc 00       	push   0xbcdea0
  53dc4d:	e8 c8 46 35 00       	call   0x89231a
  53dc52:	83 c4 04             	add    esp,0x4
  53dc55:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dc5c:	8b 46 20             	mov    eax,DWORD PTR [esi+0x20]
  53dc5f:	50                   	push   eax
  53dc60:	bf c4 1a fc 00       	mov    edi,0xfc1ac4
  53dc65:	e8 96 a5 01 00       	call   0x558200
  53dc6a:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53dc6d:	83 c3 18             	add    ebx,0x18
  53dc70:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53dc73:	0f 85 16 ff ff ff    	jne    0x53db8f
  53dc79:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  53dc7c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  53dc83:	59                   	pop    ecx
  53dc84:	5f                   	pop    edi
  53dc85:	5e                   	pop    esi
  53dc86:	5b                   	pop    ebx
  53dc87:	8b e5                	mov    esp,ebp
  53dc89:	5d                   	pop    ebp
  53dc8a:	c2 08 00             	ret    0x8
  53dc8d:	cc                   	int3
  53dc8e:	cc                   	int3
  53dc8f:	cc                   	int3
```

### quest_record_42 VA `0x0053D840–0x0053DB10`, raw `0x0013CC40–0x0013CF10`, SHA256 `2e51b1fd03403ad3eff0262885eae8a4d4ec13a682dc4b86923c80582ed2f1fc`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0053d840 <.data+0x13cc40>:
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81 c9 00 01 00 00    	or     ecx,0x100
  53d92a:	c1 e1 10             	shl    ecx,0x10
  53d92d:	0b ca                	or     ecx,edx
  53d92f:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d932:	5f                   	pop    edi
  53d933:	5b                   	pop    ebx
  53d934:	8b e5                	mov    esp,ebp
  53d936:	5d                   	pop    ebp
  53d937:	c2 08 00             	ret    0x8
  53d93a:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d93e:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d942:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d946:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d94a:	5f                   	pop    edi
  53d94b:	5b                   	pop    ebx
  53d94c:	8b e5                	mov    esp,ebp
  53d94e:	5d                   	pop    ebp
  53d94f:	c2 08 00             	ret    0x8
  53d952:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d956:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d95a:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d95e:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d962:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d966:	81 c9 00 00 00 03    	or     ecx,0x3000000
  53d96c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d96f:	5f                   	pop    edi
  53d970:	5b                   	pop    ebx
  53d971:	8b e5                	mov    esp,ebp
  53d973:	5d                   	pop    ebp
  53d974:	c2 08 00             	ret    0x8
  53d977:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d97b:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d97e:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53d982:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d986:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53d98a:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d98e:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53d992:	0f b7 56 0b          	movzx  edx,WORD PTR [esi+0xb]
  53d996:	49                   	dec    ecx
  53d997:	81 c9 00 04 00 00    	or     ecx,0x400
  53d99d:	c1 e1 10             	shl    ecx,0x10
  53d9a0:	0b ca                	or     ecx,edx
  53d9a2:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9a5:	5f                   	pop    edi
  53d9a6:	5b                   	pop    ebx
  53d9a7:	8b e5                	mov    esp,ebp
  53d9a9:	5d                   	pop    ebp
  53d9aa:	c2 08 00             	ret    0x8
  53d9ad:	8b 4e 07             	mov    ecx,DWORD PTR [esi+0x7]
  53d9b0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9b3:	5f                   	pop    edi
  53d9b4:	5b                   	pop    ebx
  53d9b5:	8b e5                	mov    esp,ebp
  53d9b7:	5d                   	pop    ebp
  53d9b8:	c2 08 00             	ret    0x8
  53d9bb:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9bf:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9c3:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9c7:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9cb:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9cf:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d9d3:	4a                   	dec    edx
  53d9d4:	81 ca 00 01 00 00    	or     edx,0x100
  53d9da:	c1 e2 10             	shl    edx,0x10
  53d9dd:	0b d1                	or     edx,ecx
  53d9df:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53d9e2:	5f                   	pop    edi
  53d9e3:	5b                   	pop    ebx
  53d9e4:	8b e5                	mov    esp,ebp
  53d9e6:	5d                   	pop    ebp
  53d9e7:	c2 08 00             	ret    0x8
  53d9ea:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9ee:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9f2:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9f6:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9fa:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9fe:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da01:	5f                   	pop    edi
  53da02:	5b                   	pop    ebx
  53da03:	8b e5                	mov    esp,ebp
  53da05:	5d                   	pop    ebp
  53da06:	c2 08 00             	ret    0x8
  53da09:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53da0d:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53da11:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53da15:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53da19:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da1d:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53da20:	5f                   	pop    edi
  53da21:	5b                   	pop    ebx
  53da22:	8b e5                	mov    esp,ebp
  53da24:	5d                   	pop    ebp
  53da25:	c2 08 00             	ret    0x8
  53da28:	0f b6 56 0a          	movzx  edx,BYTE PTR [esi+0xa]
  53da2c:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53da30:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da34:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53da38:	0f b7 56 07          	movzx  edx,WORD PTR [esi+0x7]
  53da3c:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da3f:	5f                   	pop    edi
  53da40:	5b                   	pop    ebx
  53da41:	8b e5                	mov    esp,ebp
  53da43:	5d                   	pop    ebp
  53da44:	c2 08 00             	ret    0x8
  53da47:	90                   	nop
  53da48:	0b d9                	or     ebx,ecx
  53da4a:	53                   	push   ebx
  53da4b:	00 3a                	add    BYTE PTR [edx],bh
  53da4d:	d9 53 00             	fst    DWORD PTR [ebx+0x0]
  53da50:	52                   	push   edx
  53da51:	d9 53 00             	fst    DWORD PTR [ebx+0x0]
  53da54:	77 d9                	ja     0x53da2f
  53da56:	53                   	push   ebx
  53da57:	00 ad d9 53 00 bb    	add    BYTE PTR [ebp-0x44ffac27],ch
  53da5d:	d9 53 00             	fst    DWORD PTR [ebx+0x0]
  53da60:	ea d9 53 00 09 da 53 	jmp    0x53da:0x90053d9
  53da67:	00 3f                	add    BYTE PTR [edi],bh
  53da69:	da 53 00             	ficom  DWORD PTR [ebx+0x0]
  53da6c:	3f                   	aas
  53da6d:	da 53 00             	ficom  DWORD PTR [ebx+0x0]
  53da70:	28 da                	sub    dl,bl
  53da72:	53                   	push   ebx
  53da73:	00 cc                	add    ah,cl
  53da75:	cc                   	int3
  53da76:	cc                   	int3
  53da77:	cc                   	int3
  53da78:	cc                   	int3
  53da79:	cc                   	int3
  53da7a:	cc                   	int3
  53da7b:	cc                   	int3
  53da7c:	cc                   	int3
  53da7d:	cc                   	int3
  53da7e:	cc                   	int3
  53da7f:	cc                   	int3
  53da80:	55                   	push   ebp
  53da81:	8b ec                	mov    ebp,esp
  53da83:	6a ff                	push   0xffffffff
  53da85:	68 de 49 92 00       	push   0x9249de
  53da8a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53da90:	50                   	push   eax
  53da91:	51                   	push   ecx
  53da92:	56                   	push   esi
  53da93:	57                   	push   edi
  53da94:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53da99:	33 c5                	xor    eax,ebp
  53da9b:	50                   	push   eax
  53da9c:	8d 45 f4             	lea    eax,[ebp-0xc]
  53da9f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53daa5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53daa8:	33 c9                	xor    ecx,ecx
  53daaa:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  53daad:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  53dab0:	88 48 3c             	mov    BYTE PTR [eax+0x3c],cl
  53dab3:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  53dab6:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  53dab9:	8b 70 20             	mov    esi,DWORD PTR [eax+0x20]
  53dabc:	3b f1                	cmp    esi,ecx
  53dabe:	74 19                	je     0x53dad9
  53dac0:	8b d1                	mov    edx,ecx
  53dac2:	3b c9                	cmp    ecx,ecx
  53dac4:	74 10                	je     0x53dad6
  53dac6:	66 8b 3a             	mov    di,WORD PTR [edx]
  53dac9:	66 89 3e             	mov    WORD PTR [esi],di
  53dacc:	83 c2 02             	add    edx,0x2
  53dacf:	83 c6 02             	add    esi,0x2
  53dad2:	3b d1                	cmp    edx,ecx
  53dad4:	75 f0                	jne    0x53dac6
  53dad6:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  53dad9:	b8 01 00 00 00       	mov    eax,0x1
  53dade:	84 05 d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,al
  53dae4:	75 26                	jne    0x53db0c
  53dae6:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  53daec:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  53daf3:	e8 88 99 04 00       	call   0x587480
  53daf8:	68 c0 cc bc 00       	push   0xbcccc0
  53dafd:	e8 18 48 35 00       	call   0x89231a
  53db02:	83 c4 04             	add    esp,0x4
  53db05:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53db0c:	68 6f 42 0f        	push   0xf426f
```

### quest_record_7f VA `0x0053D5E0–0x0053D755`, raw `0x0013C9E0–0x0013CB55`, SHA256 `5dfa64ffcc56bba0d13fffc15216b9d22694d2b5102813eababa081ebdf5417a`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0053d5e0 <.data+0x13c9e0>:
  53d5e0:	55                   	push   ebp
  53d5e1:	8b ec                	mov    ebp,esp
  53d5e3:	83 ec 14             	sub    esp,0x14
  53d5e6:	53                   	push   ebx
  53d5e7:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  53d5ea:	56                   	push   esi
  53d5eb:	57                   	push   edi
  53d5ec:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d5ef:	8b 37                	mov    esi,DWORD PTR [edi]
  53d5f1:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  53d5f4:	2b ce                	sub    ecx,esi
  53d5f6:	b8 67 66 66 66       	mov    eax,0x66666667
  53d5fb:	f7 e9                	imul   ecx
  53d5fd:	c1 fa 03             	sar    edx,0x3
  53d600:	8b c2                	mov    eax,edx
  53d602:	c1 e8 1f             	shr    eax,0x1f
  53d605:	03 c2                	add    eax,edx
  53d607:	b9 00 00 00 00       	mov    ecx,0x0
  53d60c:	74 23                	je     0x53d631
  53d60e:	0f b7 7b 04          	movzx  edi,WORD PTR [ebx+0x4]
  53d612:	8d 56 02             	lea    edx,[esi+0x2]
  53d615:	66 39 3a             	cmp    WORD PTR [edx],di
  53d618:	74 0a                	je     0x53d624
  53d61a:	41                   	inc    ecx
  53d61b:	83 c2 14             	add    edx,0x14
  53d61e:	3b c8                	cmp    ecx,eax
  53d620:	72 f3                	jb     0x53d615
  53d622:	eb 0a                	jmp    0x53d62e
  53d624:	8d 04 89             	lea    eax,[ecx+ecx*4]
  53d627:	8d 34 86             	lea    esi,[esi+eax*4]
  53d62a:	85 f6                	test   esi,esi
  53d62c:	75 26                	jne    0x53d654
  53d62e:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d631:	33 c0                	xor    eax,eax
  53d633:	33 c9                	xor    ecx,ecx
  53d635:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  53d638:	33 d2                	xor    edx,edx
  53d63a:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  53d63d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53d640:	8d 45 ec             	lea    eax,[ebp-0x14]
  53d643:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  53d646:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  53d649:	e8 b2 06 00 00       	call   0x53dd00
  53d64e:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  53d651:	83 ee 14             	sub    esi,0x14
  53d654:	0f b6 43 01          	movzx  eax,BYTE PTR [ebx+0x1]
  53d658:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  53d65c:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  53d660:	66 89 0e             	mov    WORD PTR [esi],cx
  53d663:	66 8b 53 04          	mov    dx,WORD PTR [ebx+0x4]
  53d667:	66 89 56 02          	mov    WORD PTR [esi+0x2],dx
  53d66b:	8a 43 03             	mov    al,BYTE PTR [ebx+0x3]
  53d66e:	88 46 0a             	mov    BYTE PTR [esi+0xa],al
  53d671:	0f b6 4b 06          	movzx  ecx,BYTE PTR [ebx+0x6]
  53d675:	89 4e 10             	mov    DWORD PTR [esi+0x10],ecx
  53d678:	8a 13                	mov    dl,BYTE PTR [ebx]
  53d67a:	88 56 0b             	mov    BYTE PTR [esi+0xb],dl
  53d67d:	80 3b 02             	cmp    BYTE PTR [ebx],0x2
  53d680:	75 08                	jne    0x53d68a
  53d682:	b8 ff 00 00 00       	mov    eax,0xff
  53d687:	66 89 06             	mov    WORD PTR [esi],ax
  53d68a:	0f b6 43 01          	movzx  eax,BYTE PTR [ebx+0x1]
  53d68e:	48                   	dec    eax
  53d68f:	83 f8 07             	cmp    eax,0x7
  53d692:	0f 87 74 01 00 00    	ja     0x53d80c
  53d698:	ff 24 85 18 d8 53 00 	jmp    DWORD PTR [eax*4+0x53d818]
  53d69f:	66 8b 4b 09          	mov    cx,WORD PTR [ebx+0x9]
  53d6a3:	66 89 4e 06          	mov    WORD PTR [esi+0x6],cx
  53d6a7:	66 8b 53 07          	mov    dx,WORD PTR [ebx+0x7]
  53d6ab:	66 89 56 08          	mov    WORD PTR [esi+0x8],dx
  53d6af:	0f b6 43 0b          	movzx  eax,BYTE PTR [ebx+0xb]
  53d6b3:	0f b7 4b 0d          	movzx  ecx,WORD PTR [ebx+0xd]
  53d6b7:	48                   	dec    eax
  53d6b8:	0d 00 01 00 00       	or     eax,0x100
  53d6bd:	c1 e0 10             	shl    eax,0x10
  53d6c0:	0b c1                	or     eax,ecx
  53d6c2:	5f                   	pop    edi
  53d6c3:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  53d6c6:	5e                   	pop    esi
  53d6c7:	5b                   	pop    ebx
  53d6c8:	8b e5                	mov    esp,ebp
  53d6ca:	5d                   	pop    ebp
  53d6cb:	c2 08 00             	ret    0x8
  53d6ce:	66 8b 53 09          	mov    dx,WORD PTR [ebx+0x9]
  53d6d2:	66 89 56 06          	mov    WORD PTR [esi+0x6],dx
  53d6d6:	66 8b 43 07          	mov    ax,WORD PTR [ebx+0x7]
  53d6da:	5f                   	pop    edi
  53d6db:	66 89 46 08          	mov    WORD PTR [esi+0x8],ax
  53d6df:	5e                   	pop    esi
  53d6e0:	5b                   	pop    ebx
  53d6e1:	8b e5                	mov    esp,ebp
  53d6e3:	5d                   	pop    ebp
  53d6e4:	c2 08 00             	ret    0x8
  53d6e7:	66 8b 4b 09          	mov    cx,WORD PTR [ebx+0x9]
  53d6eb:	66 89 4e 06          	mov    WORD PTR [esi+0x6],cx
  53d6ef:	66 8b 53 07          	mov    dx,WORD PTR [ebx+0x7]
  53d6f3:	66 89 56 08          	mov    WORD PTR [esi+0x8],dx
  53d6f7:	0f b7 43 0b          	movzx  eax,WORD PTR [ebx+0xb]
  53d6fb:	0d 00 00 00 03       	or     eax,0x3000000
  53d700:	5f                   	pop    edi
  53d701:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  53d704:	5e                   	pop    esi
  53d705:	5b                   	pop    ebx
  53d706:	8b e5                	mov    esp,ebp
  53d708:	5d                   	pop    ebp
  53d709:	c2 08 00             	ret    0x8
  53d70c:	0f b6 4b 06          	movzx  ecx,BYTE PTR [ebx+0x6]
  53d710:	89 4e 10             	mov    DWORD PTR [esi+0x10],ecx
  53d713:	0f b6 53 08          	movzx  edx,BYTE PTR [ebx+0x8]
  53d717:	66 89 56 06          	mov    WORD PTR [esi+0x6],dx
  53d71b:	0f b6 43 07          	movzx  eax,BYTE PTR [ebx+0x7]
  53d71f:	66 89 46 08          	mov    WORD PTR [esi+0x8],ax
  53d723:	0f b6 4b 09          	movzx  ecx,BYTE PTR [ebx+0x9]
  53d727:	0f b7 53 0b          	movzx  edx,WORD PTR [ebx+0xb]
  53d72b:	49                   	dec    ecx
  53d72c:	81 c9 00 04 00 00    	or     ecx,0x400
  53d732:	c1 e1 10             	shl    ecx,0x10
  53d735:	0b ca                	or     ecx,edx
  53d737:	5f                   	pop    edi
  53d738:	89 4e 0c             	mov    DWORD PTR [esi+0xc],ecx
  53d73b:	5e                   	pop    esi
  53d73c:	5b                   	pop    ebx
  53d73d:	8b e5                	mov    esp,ebp
  53d73f:	5d                   	pop    ebp
  53d740:	c2 08 00             	ret    0x8
  53d743:	80 7e 0a 00          	cmp    BYTE PTR [esi+0xa],0x0
  53d747:	8b 43 07             	mov    eax,DWORD PTR [ebx+0x7]
  53d74a:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  53d74d:	74 5c                	je     0x53d7ab
  53d74f:	e8 6c 7d ec ff       	call   0x4054c0
  53d754:	6a                 	push   0x18
```

### quest_consumer VA `0x00500E00–0x00500F74`, raw `0x00100200–0x00100374`, SHA256 `c8d29ea11e46bfde58379e7a615d6ca38729a12da70e1360c33054455e0a3999`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500e00 <.data+0x100200>:
  500e00:	55                   	push   ebp
  500e01:	8b ec                	mov    ebp,esp
  500e03:	83 e4 f8             	and    esp,0xfffffff8
  500e06:	6a ff                	push   0xffffffff
  500e08:	68 4e 6d 93 00       	push   0x936d4e
  500e0d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  500e13:	50                   	push   eax
  500e14:	83 ec 18             	sub    esp,0x18
  500e17:	53                   	push   ebx
  500e18:	56                   	push   esi
  500e19:	57                   	push   edi
  500e1a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  500e1f:	33 c4                	xor    eax,esp
  500e21:	50                   	push   eax
  500e22:	8d 44 24 28          	lea    eax,[esp+0x28]
  500e26:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  500e2c:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  500e2f:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  500e32:	8b 33                	mov    esi,DWORD PTR [ebx]
  500e34:	3b f1                	cmp    esi,ecx
  500e36:	74 1e                	je     0x500e56
  500e38:	8b c1                	mov    eax,ecx
  500e3a:	2b c1                	sub    eax,ecx
  500e3c:	c1 f8 02             	sar    eax,0x2
  500e3f:	8d 3c 85 00 00 00 00 	lea    edi,[eax*4+0x0]
  500e46:	57                   	push   edi
  500e47:	51                   	push   ecx
  500e48:	56                   	push   esi
  500e49:	e8 a2 04 39 00       	call   0x8912f0
  500e4e:	83 c4 0c             	add    esp,0xc
  500e51:	03 fe                	add    edi,esi
  500e53:	89 7b 04             	mov    DWORD PTR [ebx+0x4],edi
  500e56:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500e59:	05 d0 5e 00 00       	add    eax,0x5ed0
  500e5e:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  500e62:	c7 44 24 14 14 00 00 	mov    DWORD PTR [esp+0x14],0x14
  500e69:	00 
  500e6a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  500e6e:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  500e71:	66 85 ff             	test   di,di
  500e74:	0f 84 e4 00 00 00    	je     0x500f5e
  500e7a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  500e7d:	8b b2 ac 5e 00 00    	mov    esi,DWORD PTR [edx+0x5eac]
  500e83:	8d 44 24 18          	lea    eax,[esp+0x18]
  500e87:	0f bf df             	movsx  ebx,di
  500e8a:	50                   	push   eax
  500e8b:	8d 44 24 20          	lea    eax,[esp+0x20]
  500e8f:	8b ce                	mov    ecx,esi
  500e91:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500e95:	e8 86 2e 00 00       	call   0x503d20
  500e9a:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  500e9d:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  500ea1:	3b c6                	cmp    eax,esi
  500ea3:	0f 84 b5 00 00 00    	je     0x500f5e
  500ea9:	83 c0 10             	add    eax,0x10
  500eac:	0f 84 ac 00 00 00    	je     0x500f5e
  500eb2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  500eb5:	39 48 2c             	cmp    DWORD PTR [eax+0x2c],ecx
  500eb8:	0f 85 a0 00 00 00    	jne    0x500f5e
  500ebe:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  500ec5:	75 29                	jne    0x500ef0
  500ec7:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  500ece:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  500ed5:	00 
  500ed6:	e8 b5 dd fd ff       	call   0x4dec90
  500edb:	68 30 ce bc 00       	push   0xbcce30
  500ee0:	e8 35 14 39 00       	call   0x89231a
  500ee5:	83 c4 04             	add    esp,0x4
  500ee8:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  500eef:	ff 
  500ef0:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  500ef5:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  500ef8:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  500efb:	3b c1                	cmp    eax,ecx
  500efd:	74 18                	je     0x500f17
  500eff:	90                   	nop
  500f00:	66 39 78 14          	cmp    WORD PTR [eax+0x14],di
  500f04:	75 0a                	jne    0x500f10
  500f06:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  500f0a:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  500f0e:	7c 4e                	jl     0x500f5e
  500f10:	83 c0 18             	add    eax,0x18
  500f13:	3b c1                	cmp    eax,ecx
  500f15:	75 e9                	jne    0x500f00
  500f17:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500f1a:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  500f20:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  500f24:	51                   	push   ecx
  500f25:	8d 44 24 24          	lea    eax,[esp+0x24]
  500f29:	8b ce                	mov    ecx,esi
  500f2b:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500f2f:	e8 ec 2d 00 00       	call   0x503d20
  500f34:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500f38:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500f3b:	74 05                	je     0x500f42
  500f3d:	83 c0 10             	add    eax,0x10
  500f40:	eb 02                	jmp    0x500f44
  500f42:	33 c0                	xor    eax,eax
  500f44:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  500f48:	85 c0                	test   eax,eax
  500f4a:	74 12                	je     0x500f5e
  500f4c:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500f50:	74 0c                	je     0x500f5e
  500f52:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500f55:	8d 44 24 18          	lea    eax,[esp+0x18]
  500f59:	e8 b2 2d f4 ff       	call   0x443d10
  500f5e:	83 44 24 10 02       	add    DWORD PTR [esp+0x10],0x2
  500f63:	ff 4c 24 14          	dec    DWORD PTR [esp+0x14]
  500f67:	0f 85 fd fe ff ff    	jne    0x500e6a
  500f6d:	b8 01 00 00 00       	mov    eax,0x1
  500f72:	8b 4c            	mov    ecx,DWORD PTR [esp+0x28]
```

### quest_ui VA `0x00635CA0–0x00635D90`, raw `0x002350A0–0x00235190`, SHA256 `9ad3479b084e8ba2aba5f5aac09cc26281172542c96f3fc4f83cdae6b94b80cc`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00635ca0 <.data+0x2350a0>:
  635ca0:	55                   	push   ebp
  635ca1:	8b ec                	mov    ebp,esp
  635ca3:	6a ff                	push   0xffffffff
  635ca5:	68 04 8a 94 00       	push   0x948a04
  635caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  635cb0:	50                   	push   eax
  635cb1:	83 ec 40             	sub    esp,0x40
  635cb4:	53                   	push   ebx
  635cb5:	56                   	push   esi
  635cb6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  635cbb:	33 c5                	xor    eax,ebp
  635cbd:	50                   	push   eax
  635cbe:	8d 45 f4             	lea    eax,[ebp-0xc]
  635cc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  635cea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635cee:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635cf5:	75 21                	jne    0x635d18
  635cf7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635cfe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  635d02:	e8 59 a1 ec ff       	call   0x4ffe60
  635d07:	68 00 cf bc 00       	push   0xbccf00
  635d0c:	e8 09 c6 25 00       	call   0x89231a
  635d11:	83 c4 04             	add    esp,0x4
  635d14:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635d34:	75 21                	jne    0x635d57
  635d36:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635d3d:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  635d41:	e8 1a a1 ec ff       	call   0x4ffe60
  635d46:	68 00 cf bc 00       	push   0xbccf00
  635d4b:	e8 ca c5 25 00       	call   0x89231a
  635d50:	83 c4 04             	add    esp,0x4
  635d53:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
  635d8a:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  635d8d:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
```

### record_lookup VA `0x00500F90–0x00500FDE`, raw `0x00100390–0x001003DE`, SHA256 `120048589ce6fb31c17ff0f2d8dbf9ff6ed5ef1ce35f8d555623021e44c75138`

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500f90 <.data+0x100390>:
  500f90:	55                   	push   ebp
  500f91:	8b ec                	mov    ebp,esp
  500f93:	83 ec 08             	sub    esp,0x8
  500f96:	56                   	push   esi
  500f97:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500f9d:	8d 55 fc             	lea    edx,[ebp-0x4]
  500fa0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500fa3:	52                   	push   edx
  500fa4:	8d 45 f8             	lea    eax,[ebp-0x8]
  500fa7:	8b ce                	mov    ecx,esi
  500fa9:	e8 72 2d 00 00       	call   0x503d20
  500fae:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500fb1:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500fb4:	5e                   	pop    esi
  500fb5:	74 07                	je     0x500fbe
  500fb7:	83 c0 10             	add    eax,0x10
  500fba:	8b e5                	mov    esp,ebp
  500fbc:	5d                   	pop    ebp
  500fbd:	c3                   	ret
  500fbe:	33 c0                	xor    eax,eax
  500fc0:	8b e5                	mov    esp,ebp
  500fc2:	5d                   	pop    ebp
  500fc3:	c3                   	ret
  500fc4:	cc                   	int3
  500fc5:	cc                   	int3
  500fc6:	cc                   	int3
  500fc7:	cc                   	int3
  500fc8:	cc                   	int3
  500fc9:	cc                   	int3
  500fca:	cc                   	int3
  500fcb:	cc                   	int3
  500fcc:	cc                   	int3
  500fcd:	cc                   	int3
  500fce:	cc                   	int3
  500fcf:	cc                   	int3
  500fd0:	55                   	push   ebp
  500fd1:	8b ec                	mov    ebp,esp
  500fd3:	83 e4 f8             	and    esp,0xfffffff8
  500fd6:	6a ff                	push   0xffffffff
  500fd8:	68 86 01 94 00       	push   0x940186
  500fdd:	64         	mov    eax,fs:0x0
```

