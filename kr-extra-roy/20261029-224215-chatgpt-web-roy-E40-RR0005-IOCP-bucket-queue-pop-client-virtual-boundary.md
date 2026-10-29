# E40 — RR-0005：IOCP 接收、按 Conn 欄位分桶、應用主循環 pop、Client 虛擬回呼的 BIN-first 閉合鏈與欠缺的 vtable 尾段

**研究者／日期**：chatgpt-web roy；2026-10-29T22:42:15+08:00 (Asia/Taipei)。**研究**：KR / T02 / RR-0005 / E40；**本段使用者授權**：完成研究後把本地待提交 E37–E40 完整原稿 Push 到 GitHub 專用 `extra/roy1`；**不授權 RR 正式認領或修改台帳／main**。與使用者此前要求相同，本次不重讀整套 GitHub，而沿用本對話已見到的 `main` RR 快照，提交前只執行 branch concurrency SHA check。上一分析 E39 base 是 main `217a0358fceceb03a5cb02cd19d401206364bead` (僅 AGENTS 更新) / `extra/roy1=4ab2accf76fe038b41cca1e2896586446903b3de`；提交前才重新確認遠端當下 head。

**第一手資料**：`Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際重算）。只執行靜態 BIN 指令解碼／立即數 xref，未執行遊戲、附加 process、呼叫遊戲 API、接入現有 Server 或做 pcap。此為 T02 原始研究，**不是 T01 FULL-PASS**。

**地址**：所有函式以 PE `.text` VA；原始檔 `.text raw=VA−0x400C00`。vtable `.rdata VA−raw=0x401A00`；`.data` 另有映射，禁止沿用 `.text` 偏移。

## 0. 研究問題、分級結果與前段 E39 勘誤

E39 已證 `0x807B40` 在解 frame 後呼叫 `0x807E50` 複製 payload；但誤把 `0x807E50` 的 memcpy destination 稱為「packet queue element」後就停在未知 consumer。本段 E40 直接沿著 native branch：**`0x807B40` 不只是複製 payload，它在 payload length 非零的分支，隨後實際呼叫 `0x489920` 和 `0x8040A0` 將 packet pointer 入 `FC10D0` 的分桶 FIFO。主循環 `0x490FE0` → `0x804740` 從同一 `FC10D0` 調 `0x804100` pop，並向應用物件發虛擬 callback。**

| ID | 已確認的有限原生主張 | 關鍵 BIN 指令 | 等級 |
|---|---|---|---|
| E40-C01 | IOCP success receive path `0x806E08` call `0x807B40`，以 Conn* 為 stack arg；`0x807B40` 的 complete frame 解出 payload | `0x806E04..0x806E1C`, `0x807C7C..0x807D7F` | 已證 |
| E40-C02 | `0x8075B0` 從 FE3358 pool 取回／補配置 `0x100C` byte packet block；`0x807E50` 在 `len<=0x1000` 時複製到 packet+8 並存 len 在 +4 | `0x807C7C..0x807C8C`, `0x8075D0..0x80765A`, `0x807E50..0x807E78` | 已證（詳 E39） |
| E40-C03 | 解碼分支之後 `0x807D8B` 將 `Conn*` 寫入 `pkt+0`；len≠0 時 `0x807D9E` 從 `Conn+A080` 讀 lane，`0x807DAB` 呼叫 `0x489920`，`0x807DAD` 呼叫 `0x8040A0` 入應用分桶 queue | `0x807D7F..0x807DB2`, `0x489920..0x489981`, `0x8040A0..0x8040F6` | **本輪重大突破** |
| E40-C04 | 新建 Conn `A080` 由 `0x806B33` 取 `0x806AD0` 第四個 stack arg；重置 helper `0x805FD0` 設成 2。原先 key0/1/2 Connect 第四參數皆 2，所以 **A080=2 並非 transport key 值** | `0x806B25..0x806B39`, `0x805FD0..0x805FDA`, `0x4957C0`, `0x495610` | 已證，修正錯誤身分對應 |
| E40-C05 | 主循環 `0x491983` 用 `Client+0x140` 作為 callback holder，`0x49198A` 每輪調 `0x804740`；該 helper `0x804100` 從**相同 `FC10D0` 分桶 queue** pop packet pointer，並在 `0x80486D` 呼叫 `holder.vptr[0]` 轉交 `pkt+0 / pkt+8 / pkt+4 / bucket` | `0x49197F..0x49198F`, `0x804837..0x80486F` | **本輪重大突破** |
| E40-C06 | callback 後 `0x8048D3..0x804993` 清空 packet+0/+4，將 packet ptr 送回 `FE33A*` free deque；此流程跨 `FC10D0` 應用 queue 和 `FE3358` packet pool | `0x8048D3..0x804993` | 已證，不等於 Conn pool lifetime |
| E40-C07 | `0x4930E0` 確實出現在 **Client 另一個 secondary vtable `0xC05AEC` 的 offset0**，並於 constructor `0x48AC9A` 寫入 `Client+0x148`；但 `0x804740` receiver 是 `Client+0x140`，其 vptr 由 `holder+0` 取得，所以**目前尚差 `Client+0x140 → 0xC05AEC` 的精確指向證據**。不能因同 Client 就宣告端到端已 reach `0x4930E0` | `.rdata C05AEC=0x4930E0`、`0x48AC81..0x48ACA6`, `0x80485A..0x80486D` | 已證兩個局部，未證中間別名 |

**總結**：這一段已實際閉合「具體 Conn* 的 IOCP frame → packet pool → 應用 bucket FIFO → 主循環 pop → 封包 callback 間接呼叫」，是 E39 最大缺口的實質進展；尚缺的是 `0x80486D` 的**準確 virtual target**、與 `0x4930E0`/`0x494360`、`0x4FDA30` 以及實際 transport key0/1/2 的一一映射。未找到這些，不聲稱 wire command 2/0BD2 必定走此路徑。

## Round 1（原始段號 E40）：自 IOCP 解碼到 app bucket queue 的完整生產者鏈

### 1.1 原始結構與 pool／queue 勘誤

1. `FE3358` 是 lock-protected 的 **packet block pool**：`0x8075B0` 初始化 `0x100C` byte blocks（`packet+8` 是 0x1000 bytes payload），不是 application FIFO 本身。過去 E39「只複製到 packet queue」應更精確表述為**copy into packet block, then separately enqueue**。
2. `FC10D0` 是另一個獨立的 **multi-lane app queue container**：由 `0x803FF0` 建立、`0x489920` lazy get，`0x8040A0` producer、`0x804100` consumer。主循環觸發 `0x804740` 每輪按 lane 消費。
3. `pkt+0=Conn*`、`pkt+4=payload length`、`pkt+8=payload bytes`。`0x807D8B` 寫來源 Conn*；`0x80485F..0x80486D` 按上述順序推回呼參數，尾端多傳的 lane 值不等於 transport key。
4. `Conn+A080` 是 application queue lane selector。在 Conn pool `0x805F50` reset 設 2、`0x806AD0` connect 把第四參數寫進 A080；三個連線的 Connect caller 都傳最後參數 2。這說明此偏移不可能無條件當 transport key0/1/2，亦不證它永遠不在其他狀態修改。
5. `FC10D0` 各 lane 實際使用雙 buffer/三 segment FIFO (`+0x128` side toggle, each stage 0x18)；本段只主張 queue end-to-end routing，沒有將動態容器 invariant 全部形式驗證為無競態。

### 1.2 IOCP 使用 Conn* 呼叫 parser

`0x806DE4` 檢查 receive OVERLAPPED 是 `Conn+A030`、`0x806DF8` active guard、`0x806E08` call `0x807B40`。它只建立 socket completion 與 parser 的參數連結，不將其等同 transport key。

```asm
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39         	cmp    DWORD PTR [eax+0xa0b0],esi
```

### 1.3 payload pool 的配置與單次 frame boundary

`0x807C7C` 令 EDI=FE3358 packet pool；`0x807C81` call `0x8075B0` 取 block，EAX 成為 packet* 保存到 `[esp+28]`。同一函式先確認 payload length 1..0x1000、frame header bytes 和 buffer available。

```asm
  807c30:	04 00                	add    al,0x0
  807c32:	00 00                	add    BYTE PTR [eax],al
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
  807c90:	8d 0c 3e             	lea    ecx,[esi+edi*1]
  807c93:	3b 7c 24 14          	cmp    edi,DWORD PTR [esp+0x14]
  807c97:	0f 82 39 01 00 00    	jb     0x807dd6
  807c9d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807ca1:	81 c2 00       	add    edx,0x5000
```

### 1.4 非零 packet 才入 application queue，零 packet recycle

`0x807D7A` 呼叫 `0x807E50` 複製，`0x807D8B` 把原 `Conn*` 寫到 `packet+0`；`0x807D83` 檢查 `packet+4` 長度。零 -> `0x804310`/`0x8076F0` 回 pool；非零 -> `0x807D9E` 讀 `Conn+A080`、`0x807DA6` push pkt*、`0x807DAB` call `0x489920` get FC10D0、`0x807DAD` call `0x8040A0`。原 E39 的 queue gap 在這裡閉合至 enqueue。

```asm
  807d2c:	83 7c 24 1c 00       	cmp    DWORD PTR [esp+0x1c],0x0
  807d31:	74 44                	je     0x807d77
  807d33:	8a 07                	mov    al,BYTE PTR [edi]
  807d35:	34 b6                	xor    al,0xb6
  807d37:	0f b6 c8             	movzx  ecx,al
  807d3a:	8b d1                	mov    edx,ecx
  807d3c:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  807d40:	ba 01 00 00 00       	mov    edx,0x1
  807d45:	88 44 24 2c          	mov    BYTE PTR [esp+0x2c],al
  807d49:	3b f2                	cmp    esi,edx
  807d4b:	76 19                	jbe    0x807d66
  807d4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  807d50:	8a 04 3a             	mov    al,BYTE PTR [edx+edi*1]
  807d53:	32 44 14 2b          	xor    al,BYTE PTR [esp+edx*1+0x2b]
  807d57:	42                   	inc    edx
  807d58:	88 44 14 2b          	mov    BYTE PTR [esp+edx*1+0x2b],al
  807d5c:	0f b6 c0             	movzx  eax,al
  807d5f:	66 03 c8             	add    cx,ax
  807d62:	3b d6                	cmp    edx,esi
  807d64:	72 ea                	jb     0x807d50
  807d66:	66 39 4b 04          	cmp    WORD PTR [ebx+0x4],cx
  807d6a:	75 13                	jne    0x807d7f
  807d6c:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d70:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  807d74:	51                   	push   ecx
  807d75:	eb 03                	jmp    0x807d7a
  807d77:	57                   	push   edi
  807d78:	8b f8                	mov    edi,eax
  807d7a:	e8 d1 00 00 00       	call   0x807e50
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
```

### 1.5 FC10D0 lazy getter

此 getter 在 `FC10CC` lazy guard 下呼叫 `0x803FF0` 初始化 FC10D0，並返回 `EAX=0xFC10D0`。`0x807DAD` 所用 queue 基址有完整原件來源。

```asm
  489920:	55                   	push   ebp
  489921:	8b ec                	mov    ebp,esp
  489923:	6a ff                	push   0xffffffff
  489925:	68 ae 66 90 00       	push   0x9066ae
  48992a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  489930:	50                   	push   eax
  489931:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  489936:	33 c5                	xor    eax,ebp
  489938:	50                   	push   eax
  489939:	8d 45 f4             	lea    eax,[ebp-0xc]
  48993c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  489942:	b8 01 00 00 00       	mov    eax,0x1
  489947:	84 05 cc 10 fc 00    	test   BYTE PTR ds:0xfc10cc,al
  48994d:	75 1f                	jne    0x48996e
  48994f:	09 05 cc 10 fc 00    	or     DWORD PTR ds:0xfc10cc,eax
  489955:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  48995c:	e8 8f a6 37 00       	call   0x803ff0
  489961:	68 90 dc bc 00       	push   0xbcdc90
  489966:	e8 af 89 40 00       	call   0x89231a
  48996b:	83 c4 04             	add    esp,0x4
  48996e:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  489973:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  489976:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  48997d:	59                   	pop    ecx
  48997e:	8b e5                	mov    esp,ebp
  489980:	5d                   	pop    ebp
  489981:	c3                   	ret
```

### 1.6 multi-lane producer 的 ring stage 選擇

`0x8040A0` 將 `packet*` 經 `0x804260` 插入 `FC10D0` 對應 lane/stage，持有 `+0x124` lock；`0x8040E1` 對 lane 2 有額外 event signal。不得將 bucket 2 誤認 socket transport key2。

```asm
  8040a0:	55                   	push   ebp
  8040a1:	8b ec                	mov    ebp,esp
  8040a3:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  8040a9:	53                   	push   ebx
  8040aa:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8040ad:	56                   	push   esi
  8040ae:	50                   	push   eax
  8040af:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8040b5:	33 d2                	xor    edx,edx
  8040b7:	38 94 3b 28 01 00 00 	cmp    BYTE PTR [ebx+edi*1+0x128],dl
  8040be:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8040c1:	0f 94 c2             	sete   dl
  8040c4:	51                   	push   ecx
  8040c5:	8d 04 5a             	lea    eax,[edx+ebx*2]
  8040c8:	8d 04 40             	lea    eax,[eax+eax*2]
  8040cb:	8d 34 c7             	lea    esi,[edi+eax*8]
  8040ce:	e8 8d 01 00 00       	call   0x804260
  8040d3:	8b 8f 24 01 00 00    	mov    ecx,DWORD PTR [edi+0x124]
  8040d9:	51                   	push   ecx
  8040da:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8040e0:	5e                   	pop    esi
  8040e1:	83 fb 02             	cmp    ebx,0x2
  8040e4:	5b                   	pop    ebx
  8040e5:	75 0d                	jne    0x8040f4
  8040e7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  8040ed:	52                   	push   edx
  8040ee:	ff 15 d0 20 bd 00    	call   DWORD PTR ds:0xbd20d0
  8040f4:	5d                   	pop    ebp
  8040f5:	c2 08              	ret    0x8
```

### 1.7 key/lane 身分：Conn+A080 = connect 第四參數

從 `0x806AD0` 第四參數 (`[ebp+14]`) 複製到新 Conn A080。key map 的 key 另在第三參數 (`[ebp+10]`)，兩者不是同一 offset。

```asm
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15        	call   DWORD PTR ds:0xbd25c0
```

### 1.8 物件 pool reset 的預設 lane=2

`0x805FD0` 在 reset helper 內 `mov [esi+A080],2`，可由 `0x805950` 的 reused Conn 進入；不等於每條連線目前 map key 都是2。

```asm
  805fc8:	00 56 89             	add    BYTE PTR [esi-0x77],dl
  805fcb:	9e                   	sahf
  805fcc:	a8 a0                	test   al,0xa0
  805fce:	00 00                	add    BYTE PTR [eax],al
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
```

### Round 1 停止門檻

**本輪已達重大增量**：補上 E39 尚未找到的 producer `807D9E→489920→8040A0` 和真正 FIFO 容器 `FC10D0`。按照 shared 規則，本段在第一輪即有資格結束而改下一段；本段仍選擇深入 Round2/3，以確認同一 queue 消費、來源 Conn 指標是否丟失、以及 callback 是否能接上 `4930E0`，避免過度提升結論。

## Round 2（E40-2，加深相同問題）：同一 queue 的主循環 consumer 與 packet block recycling

這輪關鍵不是另一個無關 feature，而是接續 **同一個 `FC10D0`**：`0x490FE0` 的 `0x49198A` call 到 `0x804740`，後者以 `0x804100` 從 `FC10D0` pop packet pointer；即使不能辨認目標 vtable，已能證明消息在主循環被取出，且來源 Conn* 在 callback 入口仍保留。

### 2.1 `0x490FE0` 每輪呼叫 app queue pump

在 `0x491983` 將 `[esp+20]` 的 Client 指標加 `0x140`，push 給 `0x804740`。此 caller 是前段 E34 已識別的 Client 主循環，不是 IOCP worker。

```asm
  49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
```

### 2.2 主循環 queue pump + 雙緩衝/計數

`0x804740` 初始獲得 `EBX=[EBP+8]`，對應 Client+140，並令 EDI/ESI 指向該 holder 的統計／局部 counter。接下來 `EBX` 在 `0x804837` 以 lane index=0 開始，對 FC10D0 多 lane 做 pop。

```asm
  804768:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80476b:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  804772:	75 27                	jne    0x80479b
  804774:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  80477b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804782:	e8 69 f8 ff ff       	call   0x803ff0
  804787:	68 90 dc bc 00       	push   0xbcdc90
  80478c:	e8 89 db 08 00       	call   0x89231a
  804791:	83 c4 04             	add    esp,0x4
  804794:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80479b:	a1 f0 11 fc 00       	mov    eax,ds:0xfc11f0
  8047a0:	6a 01                	push   0x1
  8047a2:	50                   	push   eax
  8047a3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  8047aa:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8047b0:	33 c0                	xor    eax,eax
  8047b2:	8d 7b 04             	lea    edi,[ebx+0x4]
  8047b5:	b9 0b 00 00 00       	mov    ecx,0xb
  8047ba:	8d 73 30             	lea    esi,[ebx+0x30]
  8047bd:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047bf:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  8047c2:	89 45 ac             	mov    DWORD PTR [ebp-0x54],eax
  8047c5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  8047c8:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  8047cb:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  8047ce:	89 45 bc             	mov    DWORD PTR [ebp-0x44],eax
  8047d1:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  8047d4:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  8047d7:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  8047da:	66 89 45 d0          	mov    WORD PTR [ebp-0x30],ax
  8047de:	b9 0b 00 00 00       	mov    ecx,0xb
  8047e3:	8d 75 a8             	lea    esi,[ebp-0x58]
  8047e6:	8d 7b 30             	lea    edi,[ebx+0x30]
  8047e9:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047eb:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8047f1:	ff d7                	call   edi
  8047f3:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  8047f9:	89 43 30             	mov    DWORD PTR [ebx+0x30],eax
  8047fc:	2b 43 10             	sub    eax,DWORD PTR [ebx+0x10]
  8047ff:	8d 51 fc             	lea    edx,[ecx-0x4]
  804802:	3b c2                	cmp    eax,edx
  804804:	76 0d                	jbe    0x804813
  804806:	c7 45 ec 04 00 00 00 	mov    DWORD PTR [ebp-0x14],0x4
  80480d:	c6 43 58 01          	mov    BYTE PTR [ebx+0x58],0x1
  804811:	eb 03                	jmp    0x804816
  804813:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  804816:	33 f6                	xor    esi,esi
  804818:	89 73 50             	mov    DWORD PTR [ebx+0x50],esi
  80481b:	89 73 54             	mov    DWORD PTR [ebx+0x54],esi
  80481e:	ff d7                	call   edi
  804820:	89 43 38             	mov    DWORD PTR [ebx+0x38],eax
  804823:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  804826:	83 fe 02             	cmp    esi,0x2
  804829:	75 0c                	jne    0x804837
  80482b:	ff d7                	call   edi
  80482d:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  804830:	c7 43 54 00 00 00 00 	mov    DWORD PTR [ebx+0x54],0x0
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0          	mov    eax,0xfc10d0
```

### 2.3 取出 packet，回呼的四參數

`0x804841` call `0x804100`，`0x804850` 進入非空分支；`0x80485F mov eax,[packet+4]`、`0x804864 lea eax,[packet+8]`、`0x804868 mov eax,[packet]`，`0x804862..0x80486D` 依序 push `(lane, len, payload, Conn*)` 呼叫 `[holder.vptr+0]`。這個 `Conn*` 是原先 IOCP `0x807D8B` 寫入，不是新生成的 application socket。

```asm
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
  8048a3:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```

### 2.4 回呼後 packet block 回收

`0x8048D3..0x8048D9` 清零 packet 前兩個 DWORD；之後使用另一組 `FE33A0..B0` queue 將剛處理的 packet 指標送回可重用鏈。**這是 packet block pool 回收**，不得拿來取代 `Conn` pool `0x805B40` 的 reset/gating。

```asm
  8048a3:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  8048aa:	75 27                	jne    0x8048d3
  8048ac:	b8 01 00 00 00       	mov    eax,0x1
  8048b1:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  8048b7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  8048ba:	e8 61 28 00 00       	call   0x807120
  8048bf:	68 90 0b bd 00       	push   0xbd0b90
  8048c4:	e8 51 da 08 00       	call   0x89231a
  8048c9:	83 c4 04             	add    esp,0x4
  8048cc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8048d3:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  8048d9:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  8048e0:	8b 0d b0 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b0
  8048e6:	51                   	push   ecx
  8048e7:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8048ed:	a1 a4 33 fe 00       	mov    eax,ds:0xfe33a4
  8048f2:	8b 15 a0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33a0
  8048f8:	03 d0                	add    edx,eax
  8048fa:	f6 c2 03             	test   dl,0x3
  8048fd:	75 18                	jne    0x804917
  8048ff:	83 c0 04             	add    eax,0x4
  804902:	c1 e8 02             	shr    eax,0x2
  804905:	39 05 9c 33 fe 00    	cmp    DWORD PTR ds:0xfe339c,eax
  80490b:	77 0a                	ja     0x804917
  80490d:	68 94 33 fe 00       	push   0xfe3394
  804912:	e8 59 26 e3 ff       	call   0x636f70
  804917:	a1 a0 33 fe 00       	mov    eax,ds:0xfe33a0
  80491c:	03 05 a4 33 fe 00    	add    eax,DWORD PTR ds:0xfe33a4
  804922:	8b 0d 9c 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe339c
  804928:	8b f8                	mov    edi,eax
  80492a:	c1 ef 02             	shr    edi,0x2
  80492d:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  804930:	3b cf                	cmp    ecx,edi
  804932:	77 02                	ja     0x804936
  804934:	2b f9                	sub    edi,ecx
  804936:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  80493c:	83 3c ba 00          	cmp    DWORD PTR [edx+edi*4],0x0
  804940:	75 1e                	jne    0x804960
  804942:	6a 10                	push   0x10
  804944:	e8 1f c9 08 00       	call   0x891268
  804949:	83 c4 04             	add    esp,0x4
  80494c:	85 c0                	test   eax,eax
  80494e:	0f 84 b8 00 00 00    	je     0x804a0c
  804954:	8b 0d 98 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3398
  80495a:	89 04 b9             	mov    DWORD PTR [ecx+edi*4],eax
  80495d:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  804960:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  804966:	8b 0c ba             	mov    ecx,DWORD PTR [edx+edi*4]
  804969:	83 e0 03             	and    eax,0x3
  80496c:	8d 04 81             	lea    eax,[ecx+eax*4]
  80496f:	85 c0                	test   eax,eax
  804971:	74 02                	je     0x804975
  804973:	89 30                	mov    DWORD PTR [eax],esi
  804975:	8b 15 b0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33b0
  80497b:	be 01 00 00 00       	mov    esi,0x1
  804980:	01 35 a4 33 fe 00    	add    DWORD PTR ds:0xfe33a4,esi
  804986:	29 35 ac 33 fe 00    	sub    DWORD PTR ds:0xfe33ac,esi
  80498c:	52                   	push   edx
  80498d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  804993:	01 73 50             	add    DWORD PTR [ebx+0x50],esi
  804996:	83 7d 08 02          	cmp    DWORD PTR [ebp+0x8],0x2
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b               	mov    eax,DWORD PTR [ebp+0x8]
```

### 2.5 drain/recheck 多 lane，非單一 packet

`0x8049AD` 再次 `call 0x804100` 以 drain 當前 lane，沒有資料後 ESI 遞增至6。主循環收包 pump 會掃描多個 lane（不代表全部 0..5 都是 net-key）。

```asm
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
  8049c7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049cd:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8049d0:	83 fe 02             	cmp    esi,0x2
  8049d3:	75 05                	jne    0x8049da
  8049d5:	ff d7                	call   edi
  8049d7:	89 43 44             	mov    DWORD PTR [ebx+0x44],eax
  8049da:	46                   	inc    esi
  8049db:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  8049de:	83 fe 06             	cmp    esi,0x6
  8049e1:	0f 8c 3f fe ff ff    	jl     0x804826
  8049e7:	ff d7                	call   edi
```

### 2.6 consumer queue pop 的第一階段

讀 `FC10D0` stage ring pointers，成功時把 packet* 寫到 caller 提供 `[EBP+8]` 輸出槽，依 ring count 減少，`AL=1`；空時另走分支。傳參 `EAX` 指向 queue singleton、第二參數是 lane、第一參數是 packet*out。

```asm
  804100:	55                   	push   ebp
  804101:	8b ec                	mov    ebp,esp
  804103:	83 ec 0c             	sub    esp,0xc
  804106:	53                   	push   ebx
  804107:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  80410a:	56                   	push   esi
  80410b:	8b f0                	mov    esi,eax
  80410d:	8a 8c 33 28 01 00 00 	mov    cl,BYTE PTR [ebx+esi*1+0x128]
  804114:	0f b6 c1             	movzx  eax,cl
  804117:	8d 14 1b             	lea    edx,[ebx+ebx*1]
  80411a:	03 c2                	add    eax,edx
  80411c:	8d 04 40             	lea    eax,[eax+eax*2]
  80411f:	83 7c c6 10 00       	cmp    DWORD PTR [esi+eax*8+0x10],0x0
  804124:	57                   	push   edi
  804125:	8d 3c c6             	lea    edi,[esi+eax*8]
  804128:	89 55 0c             	mov    DWORD PTR [ebp+0xc],edx
  80412b:	74 69                	je     0x804196
  80412d:	8d 45 f4             	lea    eax,[ebp-0xc]
  804130:	8b cf                	mov    ecx,edi
  804132:	e8 d9 e0 d3 ff       	call   0x542210
  804137:	8b 08                	mov    ecx,DWORD PTR [eax]
  804139:	33 db                	xor    ebx,ebx
  80413b:	3b cb                	cmp    ecx,ebx
  80413d:	75 04                	jne    0x804143
  80413f:	33 d2                	xor    edx,edx
  804141:	eb 02                	jmp    0x804145
  804143:	8b 11                	mov    edx,DWORD PTR [ecx]
  804145:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  804148:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  80414b:	8b c1                	mov    eax,ecx
  80414d:	c1 e8 02             	shr    eax,0x2
  804150:	83 e1 03             	and    ecx,0x3
  804153:	3b f0                	cmp    esi,eax
  804155:	77 02                	ja     0x804159
  804157:	2b c6                	sub    eax,esi
  804159:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  80415c:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  80415f:	8b 0c 88             	mov    ecx,DWORD PTR [eax+ecx*4]
  804162:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  804165:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  804168:	89 0a                	mov    DWORD PTR [edx],ecx
  80416a:	3b c3                	cmp    eax,ebx
  80416c:	74 1d                	je     0x80418b
  80416e:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  804171:	ff 47 0c             	inc    DWORD PTR [edi+0xc]
  804174:	03 d2                	add    edx,edx
  804176:	03 d2                	add    edx,edx
  804178:	3b 57 0c             	cmp    edx,DWORD PTR [edi+0xc]
  80417b:	77 03                	ja     0x804180
  80417d:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  804180:	48                   	dec    eax
  804181:	89 47 10             	mov    DWORD PTR [edi+0x10],eax
  804184:	3b c3                	cmp    eax,ebx
  804186:	75 03                	jne    0x80418b
  804188:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  80418b:	5f                   	pop    edi
  80418c:	5e                   	pop    esi
  80418d:	b0 01                	mov    al,0x1
  80418f:	5b                   	pop    ebx
  804190:	8b e5                	mov    esp,ebp
  804192:	5d                   	pop    ebp
  804193:	c2 08 00             	ret    0x8
```

### Round 2 停止門檻

這輪已把 `FC10D0` 的 producer/consumer 使用同一地址精確閉合，完成 **IOCP decoded packet → mainloop callback invocation** 的 functional chain。需保留三個局限：(1) 並不保證網路連線 key0/1/2 對應 lane 0/1/2；(2) 尚未指認 holder.vptr[0] 的唯一本地 target；(3) socket source `Conn*` 在 callback 入口仍在，但未證它一定用於幫助 Server opcode 定義。

## Round 3（E40-3，反證校驗）：Client secondary virtual callback 與命令分派表，不能硬合的 8-byte 指標差

這輪針對 E39 未證的 `0x4930E0` 連接做**原件 vtable 地址與 constructor 實寫位置的反證核對**：已有 `C05AEC` virtual method=4930E0，然而 `0x804740` 讀 vptr 的 receiver 是 Client+140；該方法的 constructor 實寫 offset 是 Client+148。這差異是實際位址，不可因「同個 Client」忽略，必須追 pointer alias 或 thunk。

### 3.1 初始化 Client secondary subobject +0x148 的 vptr=0xC05AEC

`0x48AC81` 先 `lea eax,[edi+148]`；`0x48AC87 call 0x804380`；`0x48AC9A mov [eax],C05AEC`。`0x48ACA0` 同時將 Client 主 vptr 設為 C05A9C；不能混同主物件、secondary subobject 與 Client+140 packet pump receiver。

```asm
  48ac75:	00 8b 55 f0 8d 77    	add    BYTE PTR [ebx+0x778df055],cl
  48ac7b:	08 e8                	or     al,ch
  48ac7d:	1f                   	pop    ds
  48ac7e:	3e 25 00 8d 87 48    	ds and eax,0x48878d00
  48ac84:	01 00                	add    DWORD PTR [eax],eax
  48ac86:	00 e8                	add    al,ch
  48ac88:	f4                   	hlt
  48ac89:	96                   	xchg   esi,eax
  48ac8a:	37                   	aaa
  48ac8b:	00 c7                	add    bh,al
  48ac8d:	87 00                	xchg   DWORD PTR [eax],eax
  48ac8f:	02 00                	add    al,BYTE PTR [eax]
  48ac91:	00 38                	add    BYTE PTR [eax],bh
  48ac93:	5b                   	pop    ebx
  48ac94:	c0 00 c6             	rol    BYTE PTR [eax],0xc6
  48ac97:	45                   	inc    ebp
  48ac98:	fc                   	cld
  48ac99:	07                   	pop    es
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	   
```

### 3.2 destruct/reinit 路徑同樣使用 Client+148

`0x48B1C5` 也是直接 `mov [esi+148],0xC05AEC`。這與前述 constructor 互相核對，不是以相鄰 table 猜測。

```asm
  48b1b5:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  48b1b8:	c7 06 9c 5a c0 00    	mov    DWORD PTR [esi],0xc05a9c
  48b1be:	c7 46 08 a4 5a c0 00 	mov    DWORD PTR [esi+0x8],0xc05aa4
  48b1c5:	c7 86 48 01 00 00 ec 	mov    DWORD PTR [esi+0x148],0xc05aec
  48b1cc:	5a c0 00 
  48b1cf:	c7 86 00 02 00 00 04 	mov    DWORD PTR [esi+0x200],0xc05b04
  48b1d6:	5b c0 00 
  48b1d9:	c7       	mov    DWORD PTR [ebp-0x4],0x6
```

### 3.3 0xC05AEC 的第一個 virtual method 確實抽應用 command

`0x4930E4` 從第二參數（payload pointer）讀 `WORD command`，`0x493108` 檢查第四參數 `==2` 時呼叫 Client+0xB8 的 virtual+4。這代表一個**可能的 downstream**，但 E40 在 `0x80486D` 尚未證 holder.vptr[0] 在當時指向這個方法。

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
  49315e:	c2 10              	ret    0x10
```

### 3.4 警示：pump caller 傳入的是 Client+0x140，不是 +0x148

比較 Round2 的 `0x491983 lea ebx,[edi+140]` 與上面 secondary vptr write `Client+148`。沒有 direct XREF 可直接把 `holder+0` 等同 `C05AEC`；若 vptr 實際來自動態指標填入或較大繼承物件，要在下一段定位。

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37        	call   0x804740
```

### 3.5 非影響事實的全檔 bounded static scan

`0x4930E0` 在原件 `.rdata` 的 function-pointer DWORD 出現於 `0xC05AEC`，符合上列 constructor 寫入的 vptr。這是 static table 確認，**不是**該 caller 只可能有一條 dynamic path 的保證。對 `Conn+A080` 之 direct-offset 寫入，目前發現 `0x805FD0` 的 reset default 和 `0x806B33` 的 Connect fourth arg producer；仍可能存在間接 alias writer，因此 bucket=2 只在已查 callsite／其前後狀態成立。

### 3.6 以 pseudocode 標識已證和未證邊

```cpp
// Native bounded flow. Comments about pointer target are deliberately conditional.
struct PacketBlock { void* sourceConn; uint32_t len; uint8_t payload[0x1000]; /* +0x1008 aux */ };

// Called from IOCP recv-completion only if network/parser guards allow.
bool frame_parse(Conn* conn) {
    // parse framing / optional decode (0x2633/0BBB/0x1A68/0x22D7)
    PacketBlock* p = pool_FE3358_acquire();   // 807C7C/807C81
    bounded_copy(p->payload, decoded, len);   // 807D7A -> 807E50
    p->sourceConn = conn;                      // 807D8B
    if (p->len == 0) { pool_recycle(p); return ...; }
    uint32_t bucket = conn->field_A080;       // 807D9E; NOT transport key
    queue_FC10D0_enqueue(bucket, p);          // 489920 -> 8040A0
    return ...;
}

// Called on Client/main loop via 49198A; callback target unknown without vptr proof.
void mainloop_pump(Holder* h) {
    for (int lane = 0; lane < 6; ++lane) {
        PacketBlock* p;
        while (queue_FC10D0_pop(lane, &p)) {
            h->vptr[0](p->sourceConn, p->payload, p->len, lane); // 80486D
            packet_pool_return(p);                                  // 8048D3 onward
        }
    }
}

// Different native fact: object at Client+0x148 has vptr C05AEC whose first slot
// is 0x4930E0, but holder passed above starts at Client+0x140; the alias is unproven.
```

**Pseudocode 注意**：packet len 的 `<=0x1000` 邊界與 queue node 失敗／壅塞狀況由多個 helper 判斷，以上只是聚合資料流，非經測試可編譯 C++ 或完全 cover 所有 exception/cleanup/zero-copy branches。為避免把網路 port 作為強制部署建議，本文從未把 0x20DF/0x20E0/0x20DE 之外的任何 endpoint 角色宣告為唯一權威。

### Round 3 最終判定與修正

**已證**：`0x807D9E`/`0x807DAD`，`0x8040A0`，`0x804100`，`0x80486D` 形成清楚的 producer→consumer→dispatch 邊。**未證**：`0x80486D` 的 holder.vptr[0] 實際是否為 `0x4930E0`，`0x4930E0` 是否經過 Client+0xB8 轉送至 E39 `0x4FDA30`，以及這套系統在選服後實際第一個 socket/transport key、S2C command、遠端回覆序列。

## 4. RR5 的四類交付與下一段 E41

| 類別 | 已證／未解 | 應交付／測試 |
|---|---|---|
| **Client 待逆向** | `Client+140` holder 的 vptr/constructor alias：找出 `0x80486D` 具體 target，判斷是否 `0x4930E0` 或獨立 middleware；測 `Conn*` 如何於 callback 維持 lifetime | 追 `0x491983` object + `0x48AC9A` vptr 差8、`0x804650` 沒設定 `[holder+0]` 的間接 writer |
| **Client 待逆向** | transport keyed tree `key 0/1/2` 和 `Conn+A080` app bucket/lane 的分離已證，仍須在 callback 處追 key map lookup | 不把 key2==bucket2，S2C opcode 關聯從確切 dispatcher 才成立 |
| **Client 待逆向** | queue full/error、zero-length、bad BBB checksum 和 packet pool reset 的各分支細化 | 靜態 source map，非 runtime fault |
| **Server 待開發** | 能以本段確認的包 block 橋接設計相容回覆環境，尚無 first valid S2C payload 或 app state complete | DRAFT test notes only，不宣稱官方內部規則 |
| **跨功能待整合** | T02 queue bridging+framing、T03 login/choice UI、T01 limited claims、S00 GAP-NET-0002 | 等 T01 範圍審核後再採用，不改 FULL-PASS |
| **待遊玩驗證** | 原版 KR Client 的 key0/key1/key2 first sent／received、payload 正確排序、UI transition | 本段沒有 pcap/Client execution，不能宣稱可正常選服 |

**E41 下一題**：優先鎖定 `Client+0x140` holder 的建構寫入／callback vptr 與 `Client+0x148` C05AEC secondary vtable 的相互作用；若確認是中間 8 bytes adaptor，則以原件 native 建立 `0x80486D → 0x4930E0 → Client+0xB8 → 0x494360 → 0x4FDA30` 有界鏈；若不同則維持不同 pipeline，避免誤導 Server 設計。

## 5. 再現與三輪處理聲明

- **Round 1**：查 `806E08 → 807B40 → 807E50 → 807D9E → 489920 → 8040A0`，取得重大 packet queue producer + lane 分離新發現，達標。
- **Round 2**：查 `49198A → 804740 → 804100 → callback → packet pool recycle`，取得同 queue consumer/producer 確切閉合，達標。
- **Round 3**：查 `48AC9A/48B1C5` vptr、`C05AEC` 靜態目標與 `80486D` object offset，證明兩個接收器位址差8且不能冒認同一 vptr target；完成反證界定。

本段實際執行 **三輪**（即 E40、E40-2、E40-3 都歸同一個正式段號 E40）；三輪均新增證據，沒有把下一號提前用於重複分析。R1 已達 shared 停止門檻但續作 R2/R3 為了修正 E39 的 queue gap 和目標身份。其間從未更改原始檔。

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x806DE4 --stop-address=0x806E24 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x807D2C --stop-address=0x807DB2 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x804837 --stop-address=0x8048A4 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x48AC75 --stop-address=0x48ACB3 Tartaros.bin
```

**Git 保全**：此原稿與 E37/E38/E39 均須在 `extra/roy1` 另行提交，遠端讀回比對完整 Git blob SHA。尚未經 push+readback 前不得說已交付。台帳 RR5 仍依前次 main 快照 PENDING/QUEUED/claim=null（使用者仍要求暫不認領），不自動設定 SUBMITTED/ACCEPTED。
