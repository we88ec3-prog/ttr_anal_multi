# T10-114 — KR 傳輸虛表 → WSASend 呼叫鏈：BIN-first 原稿

## 0. 來源與研究邊界

2026-10-28 Asia/Taipei；原始唯讀 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本機本輪重算。PE32 `.text` VA 0x401000/raw 0x400、`raw = VA − 0x400C00`；`.rdata` VA 0xBD2000/raw 0x7D0600、`raw = VA − 0x401A00`。未執行、修改原始程式或使用自製 Server 模擬證據。已有 T10-111～113 原稿僅供選擇研究入口，本段重讀實際 BIN bytes 與 vtable DWORD。

研究主題：T10-113 仍未確定全域 `0xFBA854` 物件的虛函式 `+0xC` 究竟是否走 T10-111 所見 `WSASend`；本段從實際物件配置、虛表指派、兩個獨立 caller 的 ABI、API 成功/失敗分支予以閉合。這是**可證的通用傳輸層呼叫鏈**；不推論等同短按 Z 一定送包。

## 1. 本輪新結論與原生證據

### 1.1 `0xFBA854` 不再是無類別的虛呼叫：constructor + store

- `0x8046D7 push 0x5C`、`0x8046D9 call 0x891268` 配置 `0x5C` bytes **傳輸層管理物件**。當配置結果 ESI 非零，`0x8046F1 push esi` → `0x8046F2 call 0x803D60` 先構造基底；`0x8046F7 mov [esi],0xC51748` 實際指派虛表。
- `0x80470F mov [0xFBA854],ecx` 在同一控制路徑保存實際物件 `ECX`；`0x80470A..715` 立即取虛表 `+8` 並呼叫。這是同一個物件的正向來源，不需只因多個使用點讀 `FBA854` 就猜物件型態。
- 證據邊界：靜態 constructor/存入正確；是否有其他執行期替換 `FBA854` 或改寫 vptr 尚未窮盡。上文不是保證任何時刻都採同一 vptr 的動態觀察。

### 1.2 讀 `.rdata` 連續 DWORD 的真實 vtable

原生 `.rdata` VA `0xC51748`（raw `0x84fd48`）讀取：

| slot | vtable VA | 原始 DWORD target | 有界用途 |
|---:|---:|---:|---|
| `+0x0` | `0xC51748` | `0x00806670` | destructor 候選/virtual0 未完整審查 |
| `+0x4` | `0xC5174C` | `0x00806CF0` | IOCP worker |
| `+0x8` | `0xC51750` | `0x00806850` | port init / association |
| `+0xC` | `0xC51754` | `0x008068B0` | **實際 WSASend wrapper** |
| `+0x10` | `0xC51758` | `0x008069A0` | 按索引查找並入列 |
| `+0x14` | `0xC5175C` | `0x00806A00` | WSARecv wrapper |
| `+0x18` | `0xC51760` | `0x00806AD0` | 初始化連線 |
| `+0x1C` | `0xC51764` | `0x00806F60` | 未審核 |
| `+0x20` | `0xC51768` | `0x00806F80` | 未審核 |
| `+0x24` | `0xC5176C` | `0x00806FC0` | 斷線/回報候選 |
| `+0x28` | `0xC51770` | `0x00807090` | 未審核 |

`0xC51748+0xC=0xC51754` 的 DWORD **等於 `0x8068B0`**。其原始 4 bytes 為 `B0 68 80 00`。`0x8068B0` 的 WIN32 `WSASend` 指令 `0x806912: FF 15 B8 25 BD 00`，IAT `0xBD25B8=WSASend` 已由 T10-111 及本輪實機 BIN 片段核對。**同時具備 constructor store + function pointer table + caller `call edx` + API call，過去未定的 virtual target 已閉合。**

### 1.3 兩個分開的傳送 pump caller，實參與阻斷條件

**`0x804B21..0x804B5A`**：`[esi+0xA028]!=0` 有待送資料，`[esi+0xA0B8]<=0` 無正數未完成 I/O，`0x804B42 mov ecx,[0xFBA854]`，`0x804B48 mov edx,[ecx]`，`0x804B4A mov edx,[edx+0xC]`，依序 `push &localResult` / `push [esi+0xA028]` / `push esi+0x5020` / `push esi`；`0x804B5A call edx`。

**`0x805280..0x8052AC`**：相同的 gate `+A028`/`+A0B8`、同一全域虛物件、相同四個 stack arguments，`0x8052AC call edx`。這不是自動保證兩個 pump 同時觸發；各自外層狀態條件與排程未全審。

兩處接到 `0x8068B0` 時，該 callee 的 `[ebp+8]` = 連線物件、`[ebp+C]` = `connection+0x5020` 資料指標、`[ebp+10]` = `connection+0xA028` 長度、`[ebp+14]` = `&localResult`。這不是指向 frame 緩衝的 copy 函式，而是取得 socket `[connection]` 並提交單一 `WSABUF` 給 Winsock 的實際路徑。兩呼叫點返回 EAX=0 才進本地故障處理 `0x8063E0` 與傳輸物件 virtual+0x24；非零返回（包含 1、2）沿各自正常支線繼續。

### 1.4 `WSASend` 的四種本地返回／完成狀態（不是 Server ACK）

`0x8068B6` 檢查指標非零、`0x8068C3` 檢查長度非零、`0x8068D1` 檢查 `[connection+0xA0A8]==0`；不符時 `0x806993` 返回 -1。通過後在 `connection+0xA050` 建置 OVERLAPPED，`+0xA064` 設長度，`+0xA068` 指向原始呼叫端 `+0x5020`，以 `socket=[connection]` 呼叫 IAT `WSASend`。

- 送出 API 直接成功：`0x80697A..806990`，本地回傳1，Interlocked 計數 `connection+0xA0B8` 增加。
- `WSAGetLastError()==0x3E5`（WSA_IO_PENDING）：`0x806961..806977`，本地回傳2，計數同樣增加。
- 其他 SOCKET_ERROR：`0x806935..80695E`，記錄/返回0；該 pump 的 EAX=0 失敗支線才成立。
- 指標/長度/gate 早期拒絕：返回 -1；兩個 pump 都以 `test eax,eax; jne` 判斷，**-1 非零也不進 EAX=0 的故障分支**，不能把「非零」解釋成已完成實際 socket 傳送。

`WSASend` 成功與 pending 都是 **OS 套接字 API 層級**，非原版 Server 判定接受普攻。`key+0xA050` 的 completion 與 T10-110/111 的 IOCP 另一分支配對，但本段未重審其全部回收。

### 1.5 這次對 T10-113 的新增與更正

T10-113 已確認 Pending Frame → `0xFBA854` virtual+0xC 但將實作保留 unknown。此次透過 `0x8046F7`、`.rdata C51754` 及 `0x806912` 讓 **原本 unknown 的虛目標在這組已確認類型下成為已確認**。無需覆寫 T10-113 原稿，只在本段標記證據進展。這不自動補上 T10-101/103 的玩家 ID13 → `0x5452C0` 建包結果進入 `0x8069A0` 的資料 provenance。

## 2. 封包 C→S 條件鏈與真正剩餘缺口

```text
T10-101～103：玩家映射 ID13 → 相容條件下 C2S 000A 建構（已有局部 evidence）
      [缺少該 builder → 指定連線/待送 queue 的直接 provenance]
T10-112：0x8069A0 → 0x8060D0 → 0x806060 Pending List
          0x8061A0 → 0x807A70 / 0x807830 → +0x5020 frame
T10-113：0x804B5A / 0x8052AC → 0xFBA854 vtable+0xC
T10-114：0x80470F store FBA854 ← 0xC51748 table
          0xC51754 → 0x8068B0 → 0x806912 WSASend
```

**關鍵限制**：上圖橫跨不同函式的條件式鏈。由本次可將「待送 buffer → 真正 socket API」連起來；但還**不能**宣稱 `0x5452C0` 封包一定經上述唯一連線，也不能填每次短按的送包次數與時點。仍欠 `0x5452C0` 的 output sink → 連線選擇/索引 → `0x8069A0` 的具體 caller/ABI。沒有任何原始 Server 端的接受/拒絕規則或真實封包 capture，本段不把 socket 完成事件變成動作同步 ACK。

## 3. 玩家情境矩陣（已確認／未知必分清）

| 情境 | Client 本地判斷 | C→S | S→C | 角色動作 | 責任與分級 |
|---|---|---|---|---|---|
| 單次短按 Z、目前 bank ID13 | 前段確認 phase1/2 對應 bit0，但受映射/UI等條件限制 | 000A 在有界分支可建構；**本段已證通用 frame → WSASend，不證該次一定送出** | 此次未追 000A 回覆 | 先播／等回覆 unknown | Client 部分確定、Server unknown |
| Z 長按/重按/放開 | 同上，phase 2/3 與不同 gate | 包數、節奏 unknown | unknown | combo/cancel unknown | 不填虛構時窗 |
| skill 施放中 Z | 技能 phase 和 input gate 待追 | 是否送包 unknown | unknown | 本地擋下/排隊 unknown | T10/T11 介面 |
| Pending buffer 有長度且未完成 I/O<=0 | `[conn+A028]>0` 與 `[conn+A0B8]<=0`，且其他外層條件成立 | **可證**傳給 `WSASend` 的一段通用送出管線 | OS IOCP 傳送完成，不是 game ack | 不由本段啟動 actor motion | 原生已確認通用層 |
| 參數不合法/連線 gate 不可用 | WSASend wrapper 直接返回 -1 | 此 caller 本輪**不提交** socket API | 不代表 Server 拒絕 | 不證明角色動作停止 | 本地 gate 已確認 |
| SOCKET_ERROR 且不是 pending | `WSASend` wrapper 返回0，pump 走 failure callback | OS send failure | 無法由本函式推 Server 回覆 | 不等於普通攻擊取消 | 本地 native |

## 4. 輪次、可重現檢查與下一步

**本正式段第1輪已達標**：原本 unresolved 的全域虛呼叫已由「allocation → constructor → store → vtable DWORD → 虛呼叫 → Winsock IAT」鏈條直接閉合，並新增 -1/0/1/2 回傳值對兩個 pump 的行為差異。這是足以和舊原稿區別的原生實質新發現，故 `T10-114-2` 與 `-3` 未啟動；整體 T10 普攻 socket/actor motion 仍未完整。

下一正式段建議 **T10-115**：從 C2S 000A packet builder 實際 sink/selector 追到 `0x8069A0` 或不同寫出路徑；若實作不相同則保留各類 transport。另一方向是從 `0x4930E0` 的分類2 app key13 及實際 actor motion handler 查是否存在本地預播、其他玩家廣播差異。連段的時窗、技能取消、Server 允許條件都不得猜。只在已審核證據下提出 Server 相容介面。

## 5. 第一手原始機器碼／反組譯附錄

以下為本次 `objdump -D -Mintel` 自 KR BIN 擷取。每窗 VA 在標題、對應 raw 由 `.text` 換算，vtable DWORD 來自 `.rdata` 原始 bytes。線性 disassembly 可能在不屬指令的地址給出錯誤解碼；核心入口與分支均由周邊控制流程驗證。

### 全域傳輸物件建立：VA `0x008046C0..0x00804730`；raw `0x403AC0..0x403B30`

```asm
008046c0 <.text+0x4036c0>:
  8046c0:	e8 9b 68 c9 ff       	call   0x49af60
  8046c5:	eb 05                	jmp    0x8046cc
  8046c7:	e8 34 69 c9 ff       	call   0x49b000
  8046cc:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  8046d1:	50                   	push   eax
  8046d2:	e8 49 10 00 00       	call   0x805720
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00  	mov    DWORD PTR fs:0x0,ecx
```

### 傳輸虛表配置/目標：VA `0x008068B0..0x00806927`；raw `0x405CB0..0x405D27`

```asm
008068b0 <.text+0x4058b0>:
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15        	call   DWORD PTR ds:0xbd25cc
```

### 傳輸返回值：VA `0x00806920..0x0080699B`；raw `0x405D20..0x405D9B`

```asm
00806920 <.text+0x405920>:
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2               	ret    0x10
```

### 第一發送迴圈：VA `0x00804B21..0x00804B9B`；raw `0x403F21..0x403F9B`

```asm
00804b21 <.text+0x403b21>:
  804b21:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  804b28:	0f 84 1d 01 00 00    	je     0x804c4b
  804b2e:	8b 86 b8 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0b8]
  804b34:	85 c0                	test   eax,eax
  804b36:	0f 8f 0f 01 00 00    	jg     0x804c4b
  804b3c:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  804b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b48:	8b 11                	mov    edx,DWORD PTR [ecx]
  804b4a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  804b4d:	8d 7d ec             	lea    edi,[ebp-0x14]
  804b50:	57                   	push   edi
  804b51:	50                   	push   eax
  804b52:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  804b58:	50                   	push   eax
  804b59:	56                   	push   esi
  804b5a:	ff d2                	call   edx
  804b5c:	85 c0                	test   eax,eax
  804b5e:	75 1c                	jne    0x804b7c
  804b60:	56                   	push   esi
  804b61:	e8 7a 18 00 00       	call   0x8063e0
  804b66:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b6c:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b6e:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b71:	6a 00                	push   0x0
  804b73:	56                   	push   esi
  804b74:	ff d2                	call   edx
  804b76:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b7c:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  804b83:	74 16                	je     0x804b9b
  804b85:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b8d:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b90:	6a 00                	push   0x0
  804b92:	56                   	push   esi
  804b93:	ff d2                	call   edx
  804b95:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
```

### 第二發送迴圈：VA `0x00805280..0x008052D2`；raw `0x404680..0x4046D2`

```asm
00805280 <.text+0x404280>:
  805280:	8b 96 b8 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0b8]
  805286:	85 d2                	test   edx,edx
  805288:	0f 8f 1b 01 00 00    	jg     0x8053a9
  80528e:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  805294:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  80529a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80529c:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  80529f:	8d 7d f4             	lea    edi,[ebp-0xc]
  8052a2:	57                   	push   edi
  8052a3:	50                   	push   eax
  8052a4:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  8052aa:	50                   	push   eax
  8052ab:	56                   	push   esi
  8052ac:	ff d2                	call   edx
  8052ae:	85 c0                	test   eax,eax
  8052b0:	75 20                	jne    0x8052d2
  8052b2:	56                   	push   esi
  8052b3:	e8 28 11 00 00       	call   0x8063e0
  8052b8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052be:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052c0:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052c3:	6a 00                	push   0x0
  8052c5:	56                   	push   esi
  8052c6:	ff d2                	call   edx
  8052c8:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052cf:	00 00 00
```

### 出站緩衝 frame consumer：VA `0x008061A0..0x00806230`；raw `0x4055A0..0x405630`

```asm
008061a0 <.text+0x4051a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b               	mov    eax,DWORD PTR [ebp-0x10]
```