# T10-111 — KR WSARecv／WSASend 發起端、IOCP OVERLAPPED 身份、分類 writer：BIN-first 研究原稿

研究時間：20261028-204203 Asia/Taipei；使用者授權提交到 `t10/roy/chatgpt-web`，不改 `main`。唯讀反組譯，未執行、修改、注入或連線原版 Client。第一手檔案 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。BIN PE32 `.text` VA401000/raw400，對所列 `.text` VA 以 raw=VA−400C00；IAT 地址從 BIN PE import directory 的 `objdump -p` 對應核對。不同函式、結構相同 offset 不直接混淆。本段以 T10-110 已確認的 `0x806CF0` IOCP→`0x807B40` 作起點，追**提交 I/O 的發起端**，不是重述接收 queue。

## 1. 重大發現與具體原生證據

### 1.1 IAT 導向的唯一直接呼叫點（範圍受限）

BIN PE imports：`0xBD25B8=WSASend`，`0xBD25BC=WSARecv`，`0xBD25CC=WSAGetLastError`。在原始 `.text` raw `[0x400,0x7D0600)` 搜尋精確機器碼 `FF 15 <IAT addr little-endian>`，WSASend 一處 `0x806912`，WSARecv 一處 `0x806A4C`。此「一處」僅代表這種**直接 IAT memory-call 編碼**，不排除先把 IAT 讀入寄存器、別名、動態 API 或其他模組。兩個點均由 `objdump` 確認為指令邊界；不能以唯一命中宣稱所有 socket I/O 只經這兩處。

### 1.2 出站 `0x8068B0 → WSASend`：key+0xA050 確為 send OVERLAPPED

從 `[ebp+8]` 取得 key-like connection object `ESI`，先檢查 buffer 引數 `[ebp+C]` 與 length `[ebp+10]` 非零，並要求 `[ESI+0xA0A8]==0`。`0x8068DE` 計算 `ESI+0xA050`，將前 5 DWORD 初始化為0，`0x8068FC` 將 caller buffer pointer 寫入 `[ESI+0xA068]`，`0x806905` 寫 `[ESI+0xA064]=length`（對同一局部 WSABUF 的 `buf` 和 `len`）。`0x806909` 壓入 socket `[ESI]`，呼叫 `WSASend` 的 ABI 可重組為：

```cpp
WSASend(socket=key->socket,
        lpBuffers=&(key->A050_plus_14_WSABUF), dwBufferCount=1,
        lpNumberOfBytesSent=&stack_argC_temp_zero,
        dwFlags=0, lpOverlapped=&key->A050,
        lpCompletionRoutine=NULL);
```

`WSASend` 的 WSA_IO_PENDING `0x3E5`（997）分支與同步成功都會對 `key+0xA0B8` 觸發 IAT 互鎖函式（地址 `0xBD2284`；本段未再命名其完整 import），但函式返回值分別 `2`（pending）與 `1`（同步成功）；非 pending 失敗返回 `0`，參數不合法/已有 gate 返回 `-1`。**這些是 Client API 返回狀態，不是伺服器確認動作。**

此函式的 OVERLAPPED identity 恰與 T10-110 worker `0x806E7D..806ECA` 檢查 `completedOv == key+0xA050` 相符，故該條 worker 分支**方向可由發起端確定為傳送完成事件**，不再只靠偏移猜測。仍須追特定玩法 000A builder 是否交給此 API 的 caller、是否立即送或合併。

### 1.3 入站 `0x806A00 → WSARecv`：key+0xA030 確為 receive OVERLAPPED

`0x806A06` 取 `[ebp+8]` 為 key-like 物件 `ESI`。`0x806A0A` 計算 `ESI+0xA030` 並清除最初五個 DWORD；`0x806A22` 取 `ESI+0x5018` 作 buffer 指標，`0x806A2B` 存到 `[ESI+0xA048]`（WSABUF.buf），`0x806A3B` 在 `[ESI+0xA044]` 放長度 `0x1000`（WSABUF.len）。`0x806A4C` 呼叫 IAT `WSARecv`。原生 push 順序重組：

```cpp
DWORD flags=0, receivedImmediate=0;
WSARecv(socket=key->socket,
        lpBuffers=&(key->A030_plus_14_WSABUF), dwBufferCount=1,
        lpNumberOfBytesRecvd=&receivedImmediate,
        lpFlags=&flags, lpOverlapped=&key->A030,
        lpCompletionRoutine=NULL);
```

失敗返回 SOCKET_ERROR(-1) 時，`WSAGetLastError()==0x3E5` 為 pending 的可容忍分支；其他錯誤走 owner virtual+0x24、寫 `[key+0xA0A8]=1` 並返回0。非錯誤／pending 之後呼叫 `0x8065B0`，只有返回1才走 owner virtual+0x24；本輪未把 `0x8065B0` 猜成 socket 收包成功回覆。`0x806A00` 返回1是**提交/維護讀取的局部回傳**，不是收到應用資料的證明。

與 T10-110 比對：worker `0x806DE4` 檢查 `completedOv == key+0xA030`，`0x806E08` 在 gate 成立時呼叫 `0x807B40`。現在可將**同一 OVERLAPPED 地址**從 `WSARecv` 的提交端延續到 IOCP completion consumer；原先「接收方向需等發起端驗證」的限制在此條局部鏈解除。注意接收 buffer 來自 `key+0x5018`，解析累積區 `key+0x18`；兩個 buffer **不是同一地址**，具體搬運／複製在 worker/其前置邏輯中，未將其錯認為直接同一塊記憶體。

### 1.4 `0x806AD0` 新確認 Queue category writer `key+0xA080`

`0x806B1B` 取得 allocated key object 為 EBX，`0x806B25 mov eax,[ebp+0x14]` 從其 **第四個 stack argument** 取分類值，`0x806B29` 將 `[EBX+0xA0B4]=2`，`0x806B33 mov [EBX+0xA080],eax`。因此前段 T10-108/109 在 parser/queue 路徑讀取的 `key+0xA080` 有了清楚的 **producer**：連線初始化/建立函式 `0x806AD0` 的傳入 arg14，而不是由 packet K/opcode 或 `0x489920` 計算。呼叫此初始化函式的**實際 caller/arg14 語義及全部可能值**仍未完成；不能宣稱 `arg14=2` 是每個遊戲場景固定值，也不能將此分類等同 wire opcode。

`0x806B7C` 呼叫另一 IAT，`0x806B8C` 呼叫 IAT 對 socket 做地址綁定；從本段只據 native push 及 PE import 可見關聯；不將 `0x806AD0` 強行當成某一玩法連線的唯一入口。`[key+0xA0B4]=2` 與 `[key+0xA080]=arg14` 是**不同欄位**，前者常數2不能偷換成 queue category2。

### 1.5 I/O callback 的有界方向校正

```text
建立 key object：0x806AD0
  key+0xA080 = arg14           (連線 queue 分類候選)
  key+0xA0B4 = 2               (不同狀態欄位)

提交接收：0x806A00
  socket=[key+0]
  OVERLAPPED=&key+0xA030; WSABUF=(len=0x1000, buf=[key+0x5018])
  WSARecv IAT 0xBD25BC
     → IOCP 0x806CF0 worker; completedOv == key+0xA030
     → gate key+0xA0AC → 0x807B40 frame consumer
     → 0x807DAD → 0x8040A0 category queue
     → 0x804740 → conditional 0x4930E0 app header key

提交傳送：0x8068B0
  socket=[key+0]
  OVERLAPPED=&key+0xA050; WSABUF=(len=caller supplied, buf=caller supplied)
  WSASend IAT 0xBD25B8
     → IOCP 0x806CF0 worker; completedOv == key+0xA050
     → 0x8077B0 / worker counters/cleanup (不是接收 parser)
```

上圖為多段不同函式**條件式接合**，不代表所述函式在所有模式/connection state 都會順利執行，或已證明某次 Z 普攻的實際收發。

## 2. 分支、反證與舊稿更正

- **已證**：WSARecv/WSASend 的 imported symbol、call site、WSABUF 和 OVERLAPPED 的對應、兩種不同 IOCP identity，`0x806AD0` 的 category writer。
- **部分證實**：`WSARecv→IOCP→frame→queue→app dispatcher` 的有界本機處理骨架；未證明特定網路 session 下 queue classification 值、同一個封包從 network 到 actor motion 的完整對應。
- **仍未知**：`0x806AD0` caller 的 arg14 實際來源，`key+0xA0AC` gate writer/語義，`0x5452C0` C2S000A builder 最終怎麼到 `0x8068B0`，S2C motion key13 的 receive frame/from wire 對應，actor 本地 vs remote 時序，Server combo/cancel 規則。
- **否證界線**：IAT direct-call 只有一處不是 API 全域唯一使用的證明；WSARecv 取樣 0x1000 是 Client 接收 buffer 長度不是所有 wire 封包固定大小；key+0xA0B4 兩的常數不等於分類2；`0x3E5` pending 不是 Server gameplay error。

## 3. 玩家操作 × Client 判斷 × C→S × S→C × 動作/分工

| 玩家／環境情境 | Client 本地條件 | C→S | S→C | Client 動作效果 | 分工與證據 |
|---|---|---|---|---|---|
| 短按 Z、目前 bank 確實 Key44→ID13 | phase1/2 → controller bit0（前段已證條件） | `000A` 準備鏈前段已確認；**本段新增通用 WSASend 出口，未證兩者直接連接** | 通用 WSARecv/IOCP/parser 已證；尚未證實某回覆與 Z 對應 | 先播、等回覆、其他玩家看到動作皆 unknown | 封包與動畫關聯未閉合 |
| 連按／長按／放開 Z | phase1/2/3，覆寫 bank / listener 仍有前段條件 | 送包次數／重複處理未知 | 回覆次數／時序未知 | combo、取消未知 | 不使用自造時窗 |
| 技能施放中按 Z／鍵盤移動／滑鼠移動 | 需要技能 phase 及兩種移動 producer | 是否送包未知 | 所需回覆未知 | 可否中斷/延遲未知 | 待專題核對 |
| WSARecv 完成 OV=A030、gate 開放 | 取得 I/O 完成 bytes, parser 讀 frame | 不屬上行 | 原生已確認 socket read→completion→frame 條件鏈 | parser 本身不代表動作 | OS callback 不等於 game ack |
| WSASend 提交 OV=A050 | 成功/pending 都可進 completion 後續 | 通用 socket 送出 native API 已證；無特定 gameplay key | 不由此支鏈確認 | 不代表技能已生效 | Client vs Server 分清 |
| key 初始化 arg14=2 | `key+A080=2` 可作 category 選擇前提 | 無自動攻擊發送 | 可進 category2 app callback 的必要前提之一 | app key0→ParamUpdate，尚未證特定角色動作 | 連線分類與 opcode 區分 |

## 4. 三輪規則及下段研究

本段第 **1 輪已達重大新發現門檻**：兩個 API 提交者與前段兩個 IOCP OVERLAPPED 完全匹配，加上 queue category 的原生 writer。故 `T10-111-2`／`T10-111-3` **未啟動**；不是宣稱 P0 完成。下一段 T10-112 應追 `0x806AD0` 的 vtable/間接 caller 及 arg14 來源、`0x806A00` 重發起 read 的路徑、`0x8068B0` 上游送出 queue 與 C2S000A 的最後連線，另需把 app key13 motion consumer 對回真實 queue category/actor 條件，才能回答玩家 Z 普攻是否先行播放。

## 5. 可重現命令、原始 assembly 證據

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -p Tartaros.bin | grep -Ei 'WSASend|WSARecv|WSAGetLastError'
objdump -D -Mintel --start-address=0x8068b0 --stop-address=0x80699b Tartaros.bin
objdump -D -Mintel --start-address=0x806a00 --stop-address=0x806acd Tartaros.bin
objdump -D -Mintel --start-address=0x806ad0 --stop-address=0x806c75 Tartaros.bin
```

完整指令視窗取自本次 BIN `objdump`，不把下列 assembly 所有無關指令冒充為已理解的玩法語義。


### WSASend entry: VA `0x8068b0..0x80699b` / raw `0x405cb0..0x405d9b`

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


### WSARecv entry: VA `0x806a00..0x806acd` / raw `0x405e00..0x405ecd`

```asm
00806a00 <.text+0x405a00>:
  806a00:	55                   	push   ebp
  806a01:	8b ec                	mov    ebp,esp
  806a03:	51                   	push   ecx
  806a04:	53                   	push   ebx
  806a05:	56                   	push   esi
  806a06:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806a09:	57                   	push   edi
  806a0a:	8d 86 30 a0 00 00    	lea    eax,[esi+0xa030]
  806a10:	8b f9                	mov    edi,ecx
  806a12:	33 c9                	xor    ecx,ecx
  806a14:	89 08                	mov    DWORD PTR [eax],ecx
  806a16:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  806a19:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  806a1c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  806a1f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  806a22:	8b 8e 18 50 00 00    	mov    ecx,DWORD PTR [esi+0x5018]
  806a28:	6a 00                	push   0x0
  806a2a:	50                   	push   eax
  806a2b:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  806a2e:	8d 48 14             	lea    ecx,[eax+0x14]
  806a31:	8d 45 fc             	lea    eax,[ebp-0x4]
  806a34:	50                   	push   eax
  806a35:	8d 45 08             	lea    eax,[ebp+0x8]
  806a38:	50                   	push   eax
  806a39:	6a 01                	push   0x1
  806a3b:	c7 01 00 10 00 00    	mov    DWORD PTR [ecx],0x1000
  806a41:	8b 16                	mov    edx,DWORD PTR [esi]
  806a43:	51                   	push   ecx
  806a44:	52                   	push   edx
  806a45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806a4c:	ff 15 bc 25 bd 00    	call   DWORD PTR ds:0xbd25bc
  806a52:	83 f8 ff             	cmp    eax,0xffffffff
  806a55:	75 54                	jne    0x806aab
  806a57:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806a5d:	8b d8                	mov    ebx,eax
  806a5f:	81 fb e5 03 00 00    	cmp    ebx,0x3e5
  806a65:	74 44                	je     0x806aab
  806a67:	8b 17                	mov    edx,DWORD PTR [edi]
  806a69:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806a6c:	6a 00                	push   0x0
  806a6e:	56                   	push   esi
  806a6f:	8b cf                	mov    ecx,edi
  806a71:	ff d0                	call   eax
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2               	ret    0x4
```


### Connection category writer and socket setup: VA `0x806ad0..0x806c75` / raw `0x405ed0..0x406075`

```asm
00806ad0 <.text+0x405ad0>:
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
  806b4f:	e8 7c 70 09 00       	call   0x89dbd0
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  806b88:	51                   	push   ecx
  806b89:	50                   	push   eax
  806b8a:	89 03                	mov    DWORD PTR [ebx],eax
  806b8c:	ff 15 c4 25 bd 00    	call   DWORD PTR ds:0xbd25c4
  806b92:	83 f8 ff             	cmp    eax,0xffffffff
  806b95:	75 7f                	jne    0x806c16
  806b97:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806b9b:	74 19                	je     0x806bb6
  806b9d:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806ba3:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806ba6:	50                   	push   eax
  806ba7:	68 ac 16 c5 00       	push   0xc516ac
  806bac:	6a 02                	push   0x2
  806bae:	e8 4d 98 ee ff       	call   0x6f0400
  806bb3:	83 c4 0c             	add    esp,0xc
  806bb6:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806bbd:	75 35                	jne    0x806bf4
  806bbf:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806bc6:	74 27                	je     0x806bef
  806bc8:	e8 93 43 c9 ff       	call   0x49af60
  806bcd:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bd3:	53                   	push   ebx
  806bd4:	e8 17 ef ff ff       	call   0x805af0
  806bd9:	33 c0                	xor    eax,eax
  806bdb:	5f                   	pop    edi
  806bdc:	5e                   	pop    esi
  806bdd:	5b                   	pop    ebx
  806bde:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806be2:	33 cc                	xor    ecx,esp
  806be4:	e8 18 a4 08 00       	call   0x891001
  806be9:	8b e5                	mov    esp,ebp
  806beb:	5d                   	pop    ebp
  806bec:	c2 10 00             	ret    0x10
  806bef:	e8 0c 44 c9 ff       	call   0x49b000
  806bf4:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bfa:	53                   	push   ebx
  806bfb:	e8 f0 ee ff ff       	call   0x805af0
  806c00:	33 c0                	xor    eax,eax
  806c02:	5f                   	pop    edi
  806c03:	5e                   	pop    esi
  806c04:	5b                   	pop    ebx
  806c05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806c09:	33 cc                	xor    ecx,esp
  806c0b:	e8 f1 a3 08 00       	call   0x891001
  806c10:	8b e5                	mov    esp,ebp
  806c12:	5d                   	pop    ebp
  806c13:	c2 10 00             	ret    0x10
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff                 	call   edi
```