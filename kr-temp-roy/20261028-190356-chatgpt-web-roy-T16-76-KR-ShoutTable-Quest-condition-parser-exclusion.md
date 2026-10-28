# KR T16-76 — ShoutTable 中的 Quest 條件解析入口與任務封包的證據排除

- 研究時間：20261028-190356 Asia/Taipei。研究者：chatgpt-web roy。僅 KR。原檔只讀，未啟動、修改或附加 Client。
- KR BIN：SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，大小 `12,472,320` bytes。KR EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE section 直接用 `objdump -h` 核對：
| section | VA | raw | Size |
|---|---:|---:|---:|
| `.text` | `0x00401000` | `0x00000400` | `0x007D01F0` |
| `.rdata` | `0x00BD2000` | `0x007D0600` | `0x0018E07C` |
| `.data` | `0x00D61000` | `0x0095E800` | `0x0022B800` |
- 段號：T16-76，沿 T16-75 的 localization-enum 勘誤，反向找 Quest 字串的真正引用者。原稿在當前輪形成，沒有用 GitHub 舊筆記代替機器碼驗證。

## 結論摘要／證據級別

1. **原生已確認**：三個字串 `HasQuest`、`HasCompletableQuest`、`HasScenario` 位於 KR `.rdata`，被 `.text` 同一片段 `0x0053FD84..0x0053FDAE` 直接引用，經 `0x0072E2E0` 做名稱選取。
2. **原生已確認**：該流程建立 0x40-byte 的暫存紀錄，對四種條件欄位 `Normal`、`HasQuest`、`HasCompletableQuest`、`HasScenario` 分別解析並寫入暫存紀錄的偏移 0x00、0x10、0x20、0x30，再將紀錄放入容器；另從 ShoutTable 元素抽取 `talkidx`。
3. **合理語意分類但不推定封包**：鄰近 `Table/ShoutTable.xml`、`ShoutTable`、`Shout`、`talkidx` 與上述 XML-like element access，這是「喊話／對話條件設定解析」鏈的強證據，**不是**任務接取 C→S、完成 S→C 的 handler 證據。
4. **unknown**：容器後續消費者是否根據任務狀態改變喊話；Quest cache writer、NPC accept producer、wire opcode、S→C ACK、Quest16→Quest15 關係，均未解出。沒有 socket 流量或 QuestInfo.xml 原件可閉合。

## T16-76 第 1 輪：從非 localization 的 Quest 字串回溯 xref

字串與最直接的原生 VA/raw：

| string | string raw | string VA | 指標精確 raw 命中 (.text) |
|---|---:|---:|---|
| `HasQuest` | `0x80DAEC` | `0xC0F4EC` | `raw=0x13F185 / VA=0x53FD85` |
| `HasCompletableQuest` | `0x80DAF8` | `0xC0F4F8` | `raw=0x13F193 / VA=0x53FD93` |
| `HasScenario` | `0x80DB0C` | `0xC0F50C` | `raw=0x13F1A3 / VA=0x53FDA3` |

三個字串的 little-endian 指標在 BIN 各只有此一已列精確命中；此結果**只適用對完整指標常數的 bytewise 搜尋**，不排除執行時由其他構造或間接參考取得字串。`Normal` 的直接 `push` 位於同一段 `0x53FD76`。

`0x53FD3B` 先配置 **0x40 bytes** 並將其中已見欄位置零：`[eax+0x00,+0x04,+0x08,+0x10,+0x14,+0x18,+0x20,+0x24,+0x28,+0x30,+0x34,+0x38]`。不應推定所有 0x40 bytes 均已初始化，亦不宜將此大小視為 Quest 狀態封包長度。

```asm
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
```

### 已確認的四欄資料流

- `0x53FD76` / `0x53FD84` / `0x53FD92` / `0x53FDA2` 依序以字串鍵查詢元素內容（callee `0x72E2E0`），結果各存入局部變數。
- 若查到對應元素：`0x53FDBB` 使用暫存紀錄原位址；`0x53FDCA` 用 `record+0x10`；`0x53FDDD` 用 `record+0x20`；`0x53FDEE` 用 `record+0x30`，各呼叫 `0x53FEB0`。
- 最後 `0x53FDF7..0x53FE1C` 透過 `0x57EF20` / `0x57E850` 對 `[0xFE18DC]` 相關容器插入或轉移，當前尚未解明容器的全型別與所有權。這是資料設定的存入，而**非**經證明的 Quest cache writer。

## T16-76-2：追 `0x53FEB0` 條件欄位解析，避免誤用

```asm
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0 00       	push   0xc0f4a0
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53febf:	8b f0                	mov    esi,eax
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fec5:	57                   	push   edi
  53fec6:	8b 06                	mov    eax,DWORD PTR [esi]
  53fec8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  53fecb:	8b ce                	mov    ecx,esi
  53fecd:	ff d2                	call   edx
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fed3:	68 a8 f4 c0 00       	push   0xc0f4a8
  53fed8:	8d 78 44             	lea    edi,[eax+0x44]
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee4:	83 c0 30             	add    eax,0x30
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feed:	8b 00                	mov    eax,DWORD PTR [eax]
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
  53fef3:	50                   	push   eax
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53fef9:	83 c4 04             	add    esp,0x4
  53fefc:	eb 02                	jmp    0x53ff00
  53fefe:	33 c0                	xor    eax,eax
  53ff00:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53ff03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff06:	8d 45 fc             	lea    eax,[ebp-0x4]
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff0e:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  53ff11:	85 f6                	test   esi,esi
  53ff13:	75 b1                	jne    0x53fec6
  53ff15:	5f                   	pop    edi
  53ff16:	5e                   	pop    esi
  53ff17:	8b e5                	mov    esp,ebp
  53ff19:	5d                   	pop    ebp
  53ff1a:	c2               	ret    0x4
```

解析流程使用鍵 `Shout`、`talkidx`（分別 VA `0xC0F4A0` / `0xC0F4A8`）；其中含有虛呼叫 `vtable+0x14` 以及 `0x7300A0` lookup，取得非空欄位後經 `0x8917B4` 轉成數值，再轉入 `0x4A8680` 容器 helper。參數／所有權尚未完整證實，不能把函式臆稱為任務 ACK decoder。

`0x4A8680` 的部分可直接觀察行為是以 `EDI` 指向 begin/end/capacity 型容器，計算迭代器相對位置，按需要呼叫 `0x6D6240` 擴容並移動 4-byte 元素。這是本地向量樣式容器操作，**沒有**已驗證的 socket queue／S→C payload 連結。

```asm
  4a8680:	56                   	push   esi
  4a8681:	8b f0                	mov    esi,eax
  4a8683:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a8686:	3b f0                	cmp    esi,eax
  4a8688:	73 30                	jae    0x4a86ba
  4a868a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a868c:	3b ce                	cmp    ecx,esi
  4a868e:	77 2a                	ja     0x4a86ba
  4a8690:	2b f1                	sub    esi,ecx
  4a8692:	c1 fe 02             	sar    esi,0x2
  4a8695:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a8698:	75 0c                	jne    0x4a86a6
  4a869a:	b9 01 00 00 00       	mov    ecx,0x1
  4a869f:	8b c7                	mov    eax,edi
  4a86a1:	e8 9a db 22 00       	call   0x6d6240
  4a86a6:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86a9:	85 c0                	test   eax,eax
  4a86ab:	74 29                	je     0x4a86d6
  4a86ad:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a86af:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  4a86b2:	89 10                	mov    DWORD PTR [eax],edx
  4a86b4:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86b8:	5e                   	pop    esi
  4a86b9:	c3                   	ret
  4a86ba:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a86bd:	75 0c                	jne    0x4a86cb
  4a86bf:	b9 01 00 00 00       	mov    ecx,0x1
  4a86c4:	8b c7                	mov    eax,edi
  4a86c6:	e8 75 db 22 00       	call   0x6d6240
  4a86cb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86ce:	85 c0                	test   eax,eax
  4a86d0:	74 04                	je     0x4a86d6
  4a86d2:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a86d4:	89 08                	mov    DWORD PTR [eax],ecx
  4a86d6:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86da:	5e                   	pop    esi
  4a86db:	c3                   	ret
```

## T16-76-3：周邊 XML reader 的邊界與拒絕誤判

`0x53FCED` 讀取 `[esi+0x18]` 子項，`0x53FCF5..0x53FCFC` 呼叫子項 `vtable+0x14`，`0x53FD08..0x53FD31` 使用 `0xBED1D0` 文字鍵讀取內容並經數值解析，`0x53FD3B` 才配置暫存條件物件。獨立 disassembly：

```asm
  53fcea:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  53fced:	85 db                	test   ebx,ebx
  53fcef:	0f 84 34 01 00 00    	je     0x53fe29
  53fcf5:	8b 13                	mov    edx,DWORD PTR [ebx]
  53fcf7:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  53fcfa:	8b cb                	mov    ecx,ebx
  53fcfc:	ff d0                	call   eax
  53fcfe:	33 f6                	xor    esi,esi
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
  53fd3b:	6a                 	push   0x40
```

此 XML-like parser 不是原版 Server 的 Quest writer，且 Quest 條件名稱只說明 *ShoutTable 的設定欄位可能依 Quest 狀態選擇*；缺乏「從哪裡取得角色 Quest 狀態」及「哪個 handler 修改該狀態」兩項原始證據，因此目前不可說已還原 Quest progress。

三輪搜尋均有可檢查的第一手證據，但**未達 Quest C→S/S→C 完整業務閉環**。依專案三輪規範可在此停於 T16-76，下一段 T16-77 改用 NPC button callback／真正 cache writer 或 T02 業務 opcode dispatcher 作入口，不在 `HasQuest` 字串做無意義重掃。

## 玩家情境矩陣

| 玩家場景 | Client local gate | C→S | S→C | Client UI／任務效果 | Server 相容設計 |
|---|---|---|---|---|---|
| NPC 對話／喊話 | `ShoutTable` 對 `HasQuest` 等條件有原生 parser；實際 predicate 消費者未知 | unknown | unknown | 實際台詞選擇未知 | 依正式封包與 Client predicate consumer 後續補證 |
| NPC 接 Quest | unknown | unknown | unknown | 接取結果 unknown | 接受／拒絕等 wire 契約待 Client 補證 |
| Quest 完成 | unknown | unknown | unknown | state cache writer unknown | 完成/解鎖回覆必須先查 Client consumer |
| Quest16 → Quest15 | unknown | unknown | unknown | 未證原版依賴 | 不推定官方 Server 內部規則 |

## 尚需查證／交接

- 從 NPC Quest list `CQuestListDlg`（RTTI 字串見 raw `0xB82D81`）所屬真實 callback 往上追。RTTI 的存在不是對應 C→S 的證據。
- 從 `0x53FEB0` 被存入的四個本地條件陣列找 runtime consumer，檢查是否只讀既有 Quest snapshot。此為 P1，不能取代 P0 封包查找。
- T02 的 network frame/opcode 分派為跨 Task 已有工作，任何引用都需明確對照其版本與原生證據；本次未聲稱 Quest wire opcode 已確認。
- `Table/QuestInfo.xml`、`Event/TutorialBase.lua` 尚未取得第一手原件；不自行猜任務前置。

## GitHub

這是一份本段完整的原始技術筆記，僅可放 `kr-temp-roy/`。不修改其他 task/owner/catalog；是否 commit/push 與讀回驗證以本回合實際 GitHub 結果為準。