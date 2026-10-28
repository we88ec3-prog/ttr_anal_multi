# T03-5 — KR 選角 command 42 由佇列 dequeue 至 6/4-byte transport-frame builder

- 研究者 `chatgpt-web roy`；本機 Asia/Taipei：2026-10-28T21:33:16.412156+08:00
- 原始證據：`/mnt/data/Tartaros.bin`，大小 12472320，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE section 重新由 objdump header 取得 `.text` VA `0x401000` raw `0x400`，`.rdata` VA `0xBD2000` raw `0x7D0600`，`.data` VA `0xD61000` raw `0x95E800`；本文 `.text` 指令 raw = VA - `0x400C00`。未執行/修補/附加客戶端。
- GitHub 本段開始時 `main`→`t03/roy/chatgpt-web` 已包含最新主線（`behind_by=0`）。上次 T03-4 已確認 `[FBA854]` vtable+10 `0x8069A0`→`0x8060D0`→`0x806060` copy/enqueue；**本文不重報舊成果作新發現**。T02 主責 socket/framing 通用實作，T03 僅以選角 command42 為介面使用與界限。

## 1. 第 1 輪：佇列真正 dequeue 與 transport-frame 封裝者

這輪依原始 `.text` 直接反組譯 `0x8061A0`：

- `0x8061CB` 讀 `esi+0xA0D4` lock handle，透過 `[0xBD224C]` 進入同步；`0x8061E6` 讀 `esi+0xA074` linked-list sentinel；若 `sentinel->next==sentinel`，`0x8061F0` 跳到 `0x8063BA`，沒有 encode。
- 若非空，`0x8061F6 mov edi,[ebx+8]` 取 entry payload 對象；`0x8061F9 mov edx,[edi+4]` 取 queue item 長度，`0x8061FC lea eax,[edi+8]` 取實際存儲的 bytes。由 T03-4 copy/append 已知對應原始 command42 的 4-byte buffer，但需注意更前面的 UI gate、channel、queue 容量等條件。
- `0x806202 movsx eax,byte [esi+0xA02C]` 是模式選擇：值 0 直接走 `0x807A70`；非零值先走 `0x807830`，該方法返回非零時跳到清理當前節點 `0x80624F`，否則**再嘗試** `0x807A70`。此為可觀察兩個有序的 frame encode 路徑；其業務模式名稱未證。
- `0x80623A call 0x807A70` 返回值為 0 時 `0x806246 je 0x8063A4`，不走當前節點清理；返回非零時 `0x80624F` 將 queue node 摘鏈，`0x80626A call 0x89120C` 釋放節點、`0x806275 dec [esi+0xA078]`。所以 **queue 成功出列與 frame builder 成功具有直接原生因果關係**。不可從此推測 `send()` 已執行或 remote server 已收到。
- `0x8063A4` 若 `esi+0xA0B4==1` 且本次未完成任何節點，將 local return flag 設 0，否則初始值為 1；`0x8063C7` 回傳。不能把返回值 1 改寫成所有 queue bytes 已送達。

## 2. 兩條 frame builder：原始前綴與上限

### 2.1 0x807A70：4-byte 前綴（無中間 encode）

- `0x807A84 lea ebx,[edx+4]` 計算 `payload_length+4`，`0x807A8A mov eax,0x1A68`、`0x807A8F mov word [ebp-2],ax`、`0x807A93 mov word [ebp-4],dx`。注意 `0x1A68` 只是 local `word [ebp-2]`，此後的本條主要成功路徑 **只從 `[ebp-4]` 取 dword 給 `[writeptr]`**，但兩個 word 在 stack 位置連續，組成 `[length_low16,0x1A68]`，即 4-byte 前綴 `len16 little-endian | 68 1A`。`0x807AE9 mov [eax],ecx` 將這 4 bytes 寫至 send staging buffer，再以 `0x89DBD0` 複製 payload。
- 限制 `len+4 <= 0x1000`、`len != 0`、`pending_bytes + (len+4) <= 0x4000`、write cursor range；失敗返回 0，成功更新 `edi+0x500C` 累計長度及 `edi+0x5004` write cursor，返回 1。
- 對原始 `42 00 XX YY`（長度4），若這個分支被選中，**進 staging buffer 的 8-byte 片段**可描述為 `04 00 68 1A 42 00 XX YY`。這是局部緩衝格式，不自動證實最終 TCP wire 上即同此序列。

### 2.2 0x807830：6-byte 前綴與 XOR 資料轉換

- `0x80786D` 計算 `payload_length+6`，`0x807870` 將 local dword 設 `0x7D810BBB`，`0x80787A` 存 `uint16 length`，組合 6-byte prefix；在 `0x8079F6` 寫 4-byte local 值、`0x8079F8` 寫 2-byte 計算後的檢查值；`0x807A0E` 複製長度為原始 `len` 的轉換資料。
- `0x8078FD` 起先處理首 byte `xor 0xB6`，後續 `0x807967–0x80799C` 逐 bytes 以鄰近輸入 bytes 做 XOR，並計算累積值；末尾 `0x8079BD–0x8079D0` 處理單數筆數狀態，最後 `0x8079DD` 合併校驗和並寫入前綴的 bytes `+4`。**這是已驗證 Client 本地 framing/編碼，而非一句「可能壓縮」的猜測**。無法從這段推定網路加密密鑰來源、Server 解碼器或所有模式。
- 限制 `len+6<=0x1000`、`len != 0`、`pending_bytes+(len+6)<=0x4000`、cursor range；未達則返回 0。local 常數 `0x7D810BBB` 在暫存中是 `BB 0B 81 7D`，但 **`0x8079F6` 寫出時僅前 4 bytes（length16 + BB 0B），`0x8079F8` 在 offset+4 寫入 2-byte checksum，因此 81 7D 不會作為本路徑的最終固定前綴輸出**。成功分支的 6-byte 前綴為 `len16 | BB 0B | checksum16`。該中間 magic 不是業務 opcode。

### 2.3 需保留的校正：前綴 0x1A68 的 stack 實際位置

`0x807A8F` / `0x807A93` 兩個 16-bit 存取相鄰而非同位；`mov eax,0x1A68`+`mov [ebp-2],ax` 確保前綴高 16-bit 是 `0x1A68`。對於純額外包裝測試，先驗證 staging buffer 前綴，不應以記憶體 `word` 排列自行改寫成 bytes `68 1A 04 00`。

## 3. 與 T03 業務封包的界線與可玩影響

| 玩家情境 | 本地/queue 條件 | Client-to-Server 已證 | S→C 原生 pairing | 玩家可見後果 |
|---|---|---|---|---|
| 選角 UI `0x70A`、記錄 `+5C !=0` | `FBA798==0`、slot0 存在、copy/queue 成功 | 上段 `42 00 XX 00` 可進 queue；本段確認 queue drain 並據模式封成 4-byte 或 6-byte 前綴格式 | **未確立** | 未證，不能宣稱進入世界 |
| 模式0，長度4 | queue entry存在、cursor等條件合格 | staging 片段 `04 00 68 1A 42 00 XX YY` | unknown | unknown |
| 模式非零 | queue entry 存在、0x807830 成功 | +6 prefix XOR encode，再入 staging；轉換後 payload 不可視為原始 42 00 XX YY | unknown | unknown |
| 模式非零，但 0x807830 失敗 | 0x806228 return0 | 嘗試 fallback 0x807A70；其成功才摘鏈 | unknown | unknown |
| staging 緩衝不足或 write cursor 異常 | 0x807A70/0x807830 returns0 | 節點維持待送或按後續状態處理，這段不能宣稱成功送出 | unknown | unknown |

- **沒有證據**讓 `42→43/69` 從本機 fixture 升級為官方 Server response pairing。這兩個 frame builder 處理各類命令，是 T02 通用接口；T03 不修改 T02 owner/catalog。
- `0x8061A0` 的第二、後續 consumer 及 staging buffer→WinSock send 的真正出口仍待查；也需連接 S→C decode／dispatcher→T03 回覆 handler，才可對完整 Client↔Server 遊玩鏈做驗收。
- 原始 server 缺失；本次不可反推 Server 認證／選角許可規則。完整 packet scheduling、event time、threading 未驗證。

## 4. 交付與三輪深入門檻

1. 第 1 輪 T03-5：已實際執行，發現 `0x8061A0` dequeue → 依 mode 呼叫 `0x807830` 或 `0x807A70` → framing buffer 建構 → dequeue 項移除與狀態回傳。兩個新 frame builder 的原生前綴、容量條件與 payload transform 亦經現有 BIN 核驗。這是重大新原生功能鏈，因此本段結束。
2. 第 2 輪 T03-5-2：未啟動，第 1 輪已超過重大增量門檻。
3. 第 3 輪 T03-5-3：未啟動，理由同上。

## 5. 原生反組譯完整定向摘錄

原始命令：`objdump -d -Mintel --start-address=VA --stop-address=VA /mnt/data/Tartaros.bin`；每行 bytes 來自 BIN section；在 `.text` 中 `raw=VA-0x400C00`。以下保留重要分支完整指令（有些長函式因範圍大於選讀，截取局部；均標明範圍）。

### Queue drain and two encoder call sites — 0x8061A0..0x80627B

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

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
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]

```

### Queue drain linked-list removal and completion — 0x80624F..0x8063DE

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0080624f <.text+0x40524f>:
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
  80627b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806282:	8b d9                	mov    ebx,ecx
  806284:	75 27                	jne    0x8062ad
  806286:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80628d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806294:	e8 87 0e 00 00       	call   0x807120
  806299:	68 90 0b bd 00       	push   0xbd0b90
  80629e:	e8 77 c0 08 00       	call   0x89231a
  8062a3:	83 c4 04             	add    esp,0x4
  8062a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  8063d4:	59                   	pop    ecx
  8063d5:	5f                   	pop    edi
  8063d6:	5e                   	pop    esi
  8063d7:	5b                   	pop    ebx
  8063d8:	8b e5                	mov    esp,ebp
  8063da:	5d                   	pop    ebp
  8063db:	c2 04 00             	ret    0x4

```

### Alternative drain 0x8063e0 — 0x8063E0..0x806535

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008063e0 <.text+0x4053e0>:
  8063e0:	55                   	push   ebp
  8063e1:	8b ec                	mov    ebp,esp
  8063e3:	6a ff                	push   0xffffffff
  8063e5:	68 fe 98 90 00       	push   0x9098fe
  8063ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8063f0:	50                   	push   eax
  8063f1:	83 ec 18             	sub    esp,0x18
  8063f4:	53                   	push   ebx
  8063f5:	56                   	push   esi
  8063f6:	57                   	push   edi
  8063f7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8063fc:	33 c5                	xor    eax,ebp
  8063fe:	50                   	push   eax
  8063ff:	8d 45 f4             	lea    eax,[ebp-0xc]
  806402:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  806408:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  80640b:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806411:	50                   	push   eax
  806412:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806418:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  80641e:	8b 18                	mov    ebx,DWORD PTR [eax]
  806420:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  806423:	3b d8                	cmp    ebx,eax
  806425:	0f 84 fe 00 00 00    	je     0x806529
  80642b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806432:	75 27                	jne    0x80645b
  806434:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80643b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806442:	e8 d9 0c 00 00       	call   0x807120
  806447:	68 90 0b bd 00       	push   0xbd0b90
  80644c:	e8 c9 be 08 00       	call   0x89231a
  806451:	83 c4 04             	add    esp,0x4
  806454:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80645b:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806460:	8b 73 08             	mov    esi,DWORD PTR [ebx+0x8]
  806463:	50                   	push   eax
  806464:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  806467:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80646d:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  806473:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  80647a:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  80647f:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  806485:	03 c8                	add    ecx,eax
  806487:	f6 c1 03             	test   cl,0x3
  80648a:	75 18                	jne    0x8064a4
  80648c:	83 c0 04             	add    eax,0x4
  80648f:	c1 e8 02             	shr    eax,0x2
  806492:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  806498:	77 0a                	ja     0x8064a4
  80649a:	68 64 33 fe 00       	push   0xfe3364
  80649f:	e8 cc 0a e3 ff       	call   0x636f70
  8064a4:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8064aa:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8064b0:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  8064b5:	8b f7                	mov    esi,edi
  8064b7:	c1 ee 02             	shr    esi,0x2
  8064ba:	3b c6                	cmp    eax,esi
  8064bc:	77 02                	ja     0x8064c0
  8064be:	2b f0                	sub    esi,eax
  8064c0:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  8064c6:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  8064ca:	75 1b                	jne    0x8064e7
  8064cc:	6a 10                	push   0x10
  8064ce:	e8 95 ad 08 00       	call   0x891268
  8064d3:	83 c4 04             	add    esp,0x4
  8064d6:	85 c0                	test   eax,eax
  8064d8:	0f 84 a8 00 00 00    	je     0x806586
  8064de:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  8064e4:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  8064e7:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  8064ec:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  8064ef:	83 e7 03             	and    edi,0x3
  8064f2:	8d 04 b9             	lea    eax,[ecx+edi*4]
  8064f5:	85 c0                	test   eax,eax
  8064f7:	74 05                	je     0x8064fe
  8064f9:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  8064fc:	89 10                	mov    DWORD PTR [eax],edx
  8064fe:	b8 01 00 00 00       	mov    eax,0x1
  806503:	01 05 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,eax
  806509:	29 05 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,eax
  80650f:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806514:	50                   	push   eax
  806515:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80651b:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  80651d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  806520:	0f 85 05 ff ff ff    	jne    0x80642b
  806526:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806529:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  80652f:	8b 01                	mov    eax,DWORD PTR [ecx]
  806531:	89 09                	mov    DWORD PTR [ecx],ecx
  806533:	8b                   	.byte 0x8b
  806534:	8e                   	.byte 0x8e

```

### Encoded 6-byte prefix branch — 0x807830..0x807A6D

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00807830 <.text+0x406830>:
  807830:	55                   	push   ebp
  807831:	8b ec                	mov    ebp,esp
  807833:	b8 38 10 00 00       	mov    eax,0x1038
  807838:	e8 33 8e 0a 00       	call   0x8b0670
  80783d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807842:	33 c5                	xor    eax,ebp
  807844:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  807847:	53                   	push   ebx
  807848:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80784b:	56                   	push   esi
  80784c:	8b f1                	mov    esi,ecx
  80784e:	8b 06                	mov    eax,DWORD PTR [esi]
  807850:	57                   	push   edi
  807851:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  807854:	50                   	push   eax
  807855:	89 b5 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],esi
  80785b:	89 9d d4 ef ff ff    	mov    DWORD PTR [ebp-0x102c],ebx
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01 00 00 00       	mov    eax,0x1
  807912:	89 95 f8 ef ff ff    	mov    DWORD PTR [ebp-0x1008],edx
  807918:	3b f8                	cmp    edi,eax
  80791a:	0f 86 c9 00 00 00    	jbe    0x8079e9
  807920:	8d 57 ff             	lea    edx,[edi-0x1]
  807923:	83 fa 02             	cmp    edx,0x2
  807926:	0f 8c 8d 00 00 00    	jl     0x8079b9
  80792c:	8d 8d fd ef ff ff    	lea    ecx,[ebp-0x1003]
  807932:	83 c7 fd             	add    edi,0xfffffffd
  807935:	8b d3                	mov    edx,ebx
  807937:	2b d1                	sub    edx,ecx
  807939:	8d b5 fc ef ff ff    	lea    esi,[ebp-0x1004]
  80793f:	2b cb                	sub    ecx,ebx
  807941:	2b f3                	sub    esi,ebx
  807943:	d1 ef                	shr    edi,1
  807945:	47                   	inc    edi
  807946:	89 8d d0 ef ff ff    	mov    DWORD PTR [ebp-0x1030],ecx
  80794c:	8d 4c 3f 01          	lea    ecx,[edi+edi*1+0x1]
  807950:	8d 43 01             	lea    eax,[ebx+0x1]
  807953:	89 b5 c8 ef ff ff    	mov    DWORD PTR [ebp-0x1038],esi
  807959:	89 8d e0 ef ff ff    	mov    DWORD PTR [ebp-0x1020],ecx
  80795f:	eb 06                	jmp    0x807967
  807961:	8b b5 c8 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1038]
  807967:	8a 08                	mov    cl,BYTE PTR [eax]
  807969:	03 f0                	add    esi,eax
  80796b:	0f b6 1c 16          	movzx  ebx,BYTE PTR [esi+edx*1]
  80796f:	32 d9                	xor    bl,cl
  807971:	0f b6 c9             	movzx  ecx,cl
  807974:	66 01 8d ec ef ff ff 	add    WORD PTR [ebp-0x1014],cx
  80797b:	8a 48 01             	mov    cl,BYTE PTR [eax+0x1]
  80797e:	88 1e                	mov    BYTE PTR [esi],bl
  807980:	0f b6 18             	movzx  ebx,BYTE PTR [eax]
  807983:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  807989:	32 d9                	xor    bl,cl
  80798b:	0f b6 c9             	movzx  ecx,cl
  80798e:	66 01 8d f4 ef ff ff 	add    WORD PTR [ebp-0x100c],cx
  807995:	88 1c 06             	mov    BYTE PTR [esi+eax*1],bl
  807998:	83 c0 02             	add    eax,0x2
  80799b:	4f                   	dec    edi
  80799c:	75 c3                	jne    0x807961
  80799e:	8b 85 e0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1020]
  8079a4:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8079a7:	8b b5 cc ef ff ff    	mov    esi,DWORD PTR [ebp-0x1034]
  8079ad:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  8079b3:	8b 8d dc ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1024]
  8079b9:	3b c7                	cmp    eax,edi
  8079bb:	73 1a                	jae    0x8079d7
  8079bd:	8a 14 03             	mov    dl,BYTE PTR [ebx+eax*1]
  8079c0:	8a 5c 03 ff          	mov    bl,BYTE PTR [ebx+eax*1-0x1]
  8079c4:	32 da                	xor    bl,dl
  8079c6:	0f b6 d2             	movzx  edx,dl
  8079c9:	66 01 95 f8 ef ff ff 	add    WORD PTR [ebp-0x1008],dx
  8079d0:	88 9c 05 fc ef ff ff 	mov    BYTE PTR [ebp+eax*1-0x1004],bl
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2 08 00             	ret    0x8
  807a4d:	8b 8d f0 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1010]
  807a53:	51                   	push   ecx
  807a54:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a5a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a5d:	5f                   	pop    edi
  807a5e:	5e                   	pop    esi
  807a5f:	33 cd                	xor    ecx,ebp
  807a61:	33 c0                	xor    eax,eax
  807a63:	5b                   	pop    ebx
  807a64:	e8 98 95 08 00       	call   0x891001
  807a69:	8b e5                	mov    esp,ebp
  807a6b:	5d                   	pop    ebp
  807a6c:	c2                   	.byte 0xc2

```

### Plain 4-byte prefix branch — 0x807A70..0x807B3C

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00807a70 <.text+0x406a70>:
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
  807b19:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  807b1c:	52                   	push   edx
  807b1d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b23:	5e                   	pop    esi
  807b24:	33 c0                	xor    eax,eax
  807b26:	5b                   	pop    ebx
  807b27:	8b e5                	mov    esp,ebp
  807b29:	5d                   	pop    ebp
  807b2a:	c2 08 00             	ret    0x8
  807b2d:	56                   	push   esi
  807b2e:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b34:	5e                   	pop    esi
  807b35:	33 c0                	xor    eax,eax
  807b37:	5b                   	pop    ebx
  807b38:	8b e5                	mov    esp,ebp
  807b3a:	5d                   	pop    ebp
  807b3b:	c2                   	.byte 0xc2

```