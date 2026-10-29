# E50 — RR-0005／KR T02：active key-map replace、Pool+48 雙 producer、A0B8 原生 Interlocked I/O 計數與 S2C 長度下界（目標導向 10 大子段）

**正式段號 E50**；E50.1–E50.10 是同一研究交付的 10 個大型分析單元；不因某個重大發現提前停止。

- **實際生成時間（Asia/Taipei）**：`2026-10-30T02:25:53+08:00`；**研究者**：`chatgpt-web roy`。**BIN first**，離線只讀，未執行目標、未聯網、未附加遊戲。
- **唯一原始客戶端**：`/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`objdump -p` 讀原生 PE imports；`.text` 用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`，raw=`VA-0x400C00`；此映射不得誤套 `.rdata` IAT。
- **GitHub 開工核對**：`main=54747b31a1c093704785d43b9c599f4bf7fb3907`，`extra/roy1=7905e8e189f50463e89b8d35bcf531c19a447a41`。已讀 main 的 `AGENTS.md`、`kr/tasks/T02/{README.md,task.json}`、T01 README、research dispatch/inbox、RR index、shared verified README。RR-0005 `KR/T02/P0/PENDING/QUEUED`，claim/submission=null；本次**只是研究與原稿上傳**，不是在 `main` 認領或讓 S00 接受。
- **E49 交接**：`20261030-014508-chatgpt-web-roy-E49-RR0005-pool-getter-recycle-parser-ABI-boundaries.md`，已核實其 `0x49B070 getter != map erase` 更正；本次沿 owner、async counter、manager tree、parser 10 個方向深化。
- **分級**：N 為原生 machine code 或原生 PE import 直接證據；C 為具前提的條件式資料流推論；U 為缺 live trace 或其他 writer/caller 的未解。所有 `Conn/Pool/Manager` 僅用途暫名。

## E50 摘要與正式停止原因

**重大實證 1**：新增 `0x806CB3→0x7B6890` **相同 key 再連線的 map tree node erase**，隨後 `0x57EF20→0x57E850` 建立新 Conn key mapping，修正 E48 的錯誤 map erase 入口。

**重大實證 2**：`Pool+0x48` **正向 producer** 至少兩類：`0x806BD4／0x806BFB→0x805AF0` 的 **Connect 失敗**，及 `0x8066A0` 的 **network manager teardown inline enqueue**。`0x806FC0→0x805A80` 是 Pool+28 另一路追蹤。

**重大實證 3**：由原件 PE import table 確認 `0xBD2284=InterlockedIncrement`、`0xBD227C=InterlockedDecrement`；`Conn+A0B8` 是 **pending async I/O counter**，非 event；E48/E49 如有 `SetEvent` 說法需改正。

**停止 B**：10 子段達上限，仍欠同一次實際登入的 first wire/Server reply、舊 Conn ownership、全部 outstanding IO 平衡與 handler length；不假稱 RR Accepted／T01 FULL-PASS／Server 可玩。

## E50.1 — First-hand IAT：`A0B8` 是 atomic pending-I/O counter，不是 HANDLE

**研究問題**：E48/E49 對 `Conn+A0B8` 曾使用事件或 signal 的語彙，該欄位的合法型別與 API 到底是什麼？

**N／獨立證據 1**：原始 PE32 具有 import directory；`objdump -p Tartaros.bin` KERNEL32 import 對照為：`0x007D227C InterlockedDecrement`、`0x007D2280 InterlockedExchange`、`0x007D2284 InterlockedIncrement`（runtime ImageBase 0x400000，所以指令的 IAT VA 對應 `0xBD227C/80/84`）；`0x007D2278 CreateIoCompletionPort`、`0x007D2274 GetQueuedCompletionStatus`。**這不是依呼叫上下文猜 WinAPI 名稱**，是 PE 的 IDT/IAT 函式名稱。

**N／獨立證據 2**：已證 WSASend post path 以 `LEA ...,[Conn+A0B8]` 取欄位地址，`PUSH` 至 `call [0xBD2284]`；IOCP completion 使用 `call [0xBD227C]`。`0x805DE9` 初始 `mov [Conn+A0B8],ebx` 且 EBX=0；`0x805B40` 以 `cmp [Conn+A0B8],0` 作 reset gating。此組和 Interlocked 增減的 API 語意互相吻合。

**結論 N**：`Conn+A0B8` 對這套可見路徑是**pending operation atomic counter**，不是 Win32 event handle。E48/E49 曾把這些呼叫說成 `SetEvent` 的部分應撤銷；不能使用先前的 event 語意解釋回收 gate。`Conn+A0BC` 是另一個 DWORD，`0x8065F1` 使用 `InterlockedExchange` 時傳其地址，**不可與 A0B8 混名**。

**C／條件**：每一次成功排隊及其完成（含失敗完成）應維持增減匹配；但沒有動態 trace，**不宣稱每種 error/Cancel path 的平衡已證實**。所有本段欄位均是 Conn base（不可混 Pool/Manager 同 offset）。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00805ddd–0x00805df2`；`.text` raw `0x4051dd–0x4051f2`。

```asm
00805ddd <.data+0x4051dd>:
  805ddd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  805de3:	89 8e b4 a0 00 00    	mov    DWORD PTR [esi+0xa0b4],ecx
  805de9:	89 9e b8 a0 00 00    	mov    DWORD PTR [esi+0xa0b8],ebx
  805def:	6a 18                	push   0x18
  805df1:	89         	mov    DWORD PTR [esi+0xa0bc],ebx
```

`VA 0x00806956–0x0080698e`；`.text` raw `0x405d56–0x405d8e`。

```asm
00806956 <.data+0x405d56>:
  806956:	c4 14 5f             	les    edx,FWORD PTR [edi+ebx*2]
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
```

`VA 0x00806ea8–0x00806ed0`；`.text` raw `0x4062a8–0x4062d0`。

```asm
00806ea8 <.data+0x4062a8>:
  806ea8:	e4 33                	in     al,0x33
  806eaa:	f6 39                	idiv   BYTE PTR [ecx]
  806eac:	b0 28                	mov    al,0x28
  806eae:	a0 00 00 0f 97       	mov    al,ds:0x970f0000
  806eb3:	c1 88 88 24 a0 00 00 	ror    DWORD PTR [eax+0xa02488],0x0
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b               	mov    ecx,DWORD PTR [ebp-0x20]
```

`VA 0x00806ed5–0x00806f12`；`.text` raw `0x4062d5–0x406312`。

```asm
00806ed5 <.data+0x4062d5>:
  806ed5:	84 56 fe             	test   BYTE PTR [esi-0x2],dl
  806ed8:	ff                   	(bad)
  806ed9:	ff 8b 45 e4 8d 90    	dec    DWORD PTR [ebx-0x6f721bbb]
  806edf:	30 a0 00 00 3b ca    	xor    BYTE PTR [eax-0x35c50000],ah
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45              	mov    eax,DWORD PTR [ebp-0x1c]
```

`VA 0x00805ba0–0x00805bbc`；`.text` raw `0x404fa0–0x404fbc`。

```asm
00805ba0 <.data+0x404fa0>:
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
```

## E50.2 — Manager+0x18 active key-map：有界的 key lookup、node、value 身分

**研究問題**：先前以 `0x49B070` 錯認的「active key-map erase」如何定界？能否先確認真正 map 的 object layout？

**N**：`0x8069A0`（send-by-key）與 `0x806F80`（shutdown-by-key）均把 `ECX=Manager+0x18` 傳入 `0x8438C0`；`0x8438C0` 使用 comparator `node+0xC` 對 32-bit key 比大小，回傳 iterator；呼叫端將 `[iterator]` 與 `[Manager+0x1C]` 的 tree end/sentinel 比對。命中後以 `[node+0x10]` 取得 `Conn*`，在 `0x806F80` 再解 `Conn[0]` 為 socket 並呼叫 WS2_32 IAT ordinal 22 `0xBD25C8`（原生 import 只列 ordinal22，未用臆測取代 DLL 符號）。`0x8069A0` 再依 0/非 0 payload pointer 進入 `0x8060D0`。

**N／資料結構**：比較鍵值位於 node+0x0C、值在 node+0x10；`Manager+0x18` 是以 key 作索引的 tree-map 子物件，`Manager+0x1C` 代表 end/sentinel，兩者**不是同一個 Conn 偏移**。可以由兩個 caller 的局部資料流互證。

**反證**：`0x806F80` 僅 lookup→socket 指令，沒有 `0x7B6890` 或類似 erase；`0x806FC0` 也不是 map erase。本段先不宣稱 close 就會清除 key-to-Conn 對照。

**U**：其他 manager clone、競態與所有可能的 indirect callback 尚未全集成。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x008069a0–0x008069f6`；`.text` raw `0x405da0–0x405df6`。

```asm
008069a0 <.data+0x405da0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c 00             	ret    0xc
```

`VA 0x00806f80–0x00806fbd`；`.text` raw `0x406380–0x4063bd`。

```asm
00806f80 <.data+0x406380>:
  806f80:	55                   	push   ebp
  806f81:	8b ec                	mov    ebp,esp
  806f83:	51                   	push   ecx
  806f84:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f87:	56                   	push   esi
  806f88:	8b f1                	mov    esi,ecx
  806f8a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  806f8d:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  806f90:	51                   	push   ecx
  806f91:	8d 4e 18             	lea    ecx,[esi+0x18]
  806f94:	8d 45 fc             	lea    eax,[ebp-0x4]
  806f97:	e8 24 c9 03 00       	call   0x8438c0
  806f9c:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  806f9f:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  806fa2:	5e                   	pop    esi
  806fa3:	74 12                	je     0x806fb7
  806fa5:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  806fa8:	85 c0                	test   eax,eax
  806faa:	74 0b                	je     0x806fb7
  806fac:	8b 10                	mov    edx,DWORD PTR [eax]
  806fae:	6a 01                	push   0x1
  806fb0:	52                   	push   edx
  806fb1:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806fb7:	8b e5                	mov    esp,ebp
  806fb9:	5d                   	pop    ebp
  806fba:	c2 08 00             	ret    0x8
```

`VA 0x008438c0–0x00843925`；`.text` raw `0x442cc0–0x442d25`。

```asm
008438c0 <.data+0x442cc0>:
  8438c0:	55                   	push   ebp
  8438c1:	8b ec                	mov    ebp,esp
  8438c3:	51                   	push   ecx
  8438c4:	53                   	push   ebx
  8438c5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  8438c8:	56                   	push   esi
  8438c9:	8b f1                	mov    esi,ecx
  8438cb:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  8438ce:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  8438d1:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438d5:	75 1e                	jne    0x8438f5
  8438d7:	57                   	push   edi
  8438d8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  8438da:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  8438e0:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  8438e3:	7d 05                	jge    0x8438ea
  8438e5:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  8438e8:	eb 04                	jmp    0x8438ee
  8438ea:	8b d1                	mov    edx,ecx
  8438ec:	8b 09                	mov    ecx,DWORD PTR [ecx]
  8438ee:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438f2:	74 ec                	je     0x8438e0
  8438f4:	5f                   	pop    edi
  8438f5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  8438f8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  8438fb:	3b d1                	cmp    edx,ecx
  8438fd:	74 16                	je     0x843915
  8438ff:	8b 33                	mov    esi,DWORD PTR [ebx]
  843901:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  843904:	7c 0f                	jl     0x843915
  843906:	8d 4d 08             	lea    ecx,[ebp+0x8]
  843909:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84390b:	5e                   	pop    esi
  84390c:	89 08                	mov    DWORD PTR [eax],ecx
  84390e:	5b                   	pop    ebx
  84390f:	8b e5                	mov    esp,ebp
  843911:	5d                   	pop    ebp
  843912:	c2 04 00             	ret    0x4
  843915:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  843918:	8d 4d fc             	lea    ecx,[ebp-0x4]
  84391b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84391d:	5e                   	pop    esi
  84391e:	89 08                	mov    DWORD PTR [eax],ecx
  843920:	5b                   	pop    ebx
  843921:	8b e5                	mov    esp,ebp
  843923:	5d                   	pop    ebp
  843924:	c2               	ret    0x4
```

## E50.3 — 原生相同 key 重連：`806C9E` find → `7B6890` erase → new node insert

**研究問題**：真正的 key-map erase writer 是否存在？當 key 重複，程式如何替換？

**N／上游**：`0x806AD0` 的連線成功路徑，先進 `0x806620` (completion port access)；然後 `0x806C94 LEA ESI,[Manager+0x18]`，`0x806C9E call 0x8438C0` 查找 `[ebp+0x10]` key。若 iterator != end，`0x806CB3 call 0x7B6890`；否則跳到後續配置插入。

**N／erase helper**：`0x7B6890` 從 `node+0x15` 非 sentinel 驗證出發，操作紅黑樹 parent/left/right 和 color；在 `0x7B6AC3` 對 node 呼叫 `0x89120C` free，`0x7B6ADC` 遞減 `map+8` size。故真正被證實的是**key-map tree node erase**，而非關 socket 或毀掉 Conn。

**N／再插入**：`0x806CBB` 將新連線 key 和 `EBX=新 Conn*` 整理到 stack；`0x806CC7 call 0x57EF20` 建立 0x18-byte tree node，其中 `node+0xC=key`、`node+0x10=Conn*`；`0x806CD2 call 0x57E850` 以 key 比較插入 map。`0x57E850` 的成功分支設定 return flag+4=1，碰撞分支 flag+4=0；與 replace 前 find 成功的流程獨立。

**C／正確範圍**：**同 key Connect 成功路徑**會先移除舊 tree node 再插入新一筆，但沒有在此片段看到對舊 `Conn*` 自動 shutdown/close 的相同論證。故不能等同「重新連線會保證關閉舊 socket」。關閉與其餘引用可能走別的 teardown/callback 或 race，需要另證。

**反證 E48/E49**：`0x49B070` 永遠不是這段 map erase 的正向 writer；本段閉合的 writer 是 `0x806CB3 → 0x7B6890`。

**U**：key replacement 前舊 Conn 的 ownership、是否可能產生 orphan/leak、在 reconnect 時是否有外層先 close，均不能光靠該內部片段決定。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00806c7b–0x00806cea`；`.text` raw `0x40607b–0x4060ea`。

```asm
00806c7b <.data+0x40607b>:
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp
```

`VA 0x007b6890–0x007b68c6`；`.text` raw `0x3b5c90–0x3b5cc6`。

```asm
007b6890 <.data+0x3b5c90>:
  7b6890:	55                   	push   ebp
  7b6891:	8b ec                	mov    ebp,esp
  7b6893:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b6896:	83 ec 08             	sub    esp,0x8
  7b6899:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b689d:	74 0a                	je     0x7b68a9
  7b689f:	68 28 d2 be 00       	push   0xbed228
  7b68a4:	e8 d4 72 0c 00       	call   0x87db7d
  7b68a9:	53                   	push   ebx
  7b68aa:	56                   	push   esi
  7b68ab:	8b d8                	mov    ebx,eax
  7b68ad:	57                   	push   edi
  7b68ae:	8d 45 10             	lea    eax,[ebp+0x10]
  7b68b1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b68b4:	e8 e7 7d ce ff       	call   0x49e6a0
  7b68b9:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b68bb:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b68bf:	74 05                	je     0x7b68c6
  7b68c1:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7b68c4:	eb 17                	jmp    0x7b68dd
```

`VA 0x007b6ab8–0x007b6aed`；`.text` raw `0x3b5eb8–0x3b5eed`。

```asm
007b6ab8 <.data+0x3b5eb8>:
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2 0c              	ret    0xc
```

`VA 0x0057ef20–0x0057ef60`；`.text` raw `0x17e320–0x17e360`。

```asm
0057ef20 <.data+0x17e320>:
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
```

`VA 0x0057e850–0x0057e8a0`；`.text` raw `0x17dc50–0x17dca0`。

```asm
0057e850 <.data+0x17dc50>:
  57e850:	55                   	push   ebp
  57e851:	8b ec                	mov    ebp,esp
  57e853:	83 ec 08             	sub    esp,0x8
  57e856:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  57e859:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e85c:	53                   	push   ebx
  57e85d:	57                   	push   edi
  57e85e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  57e861:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  57e864:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e868:	b1 01                	mov    cl,0x1
  57e86a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e86d:	75 1f                	jne    0x57e88e
  57e86f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  57e872:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  57e875:	8b f8                	mov    edi,eax
  57e877:	0f 9c c1             	setl   cl
  57e87a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e87d:	84 c9                	test   cl,cl
  57e87f:	74 04                	je     0x57e885
  57e881:	8b 00                	mov    eax,DWORD PTR [eax]
  57e883:	eb 03                	jmp    0x57e888
  57e885:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  57e888:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e88c:	74 e4                	je     0x57e872
  57e88e:	8b df                	mov    ebx,edi
  57e890:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  57e893:	84 c9                	test   cl,cl
  57e895:	74 3a                	je     0x57e8d1
  57e897:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  57e89a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  57e89d:	3b 38                	cmp    edi,DWORD PTR [eax]
  57e89f:	75                 	jne    0x57e8c3
```

`VA 0x0057e8e0–0x0057e915`；`.text` raw `0x17dce0–0x17dd15`。

```asm
0057e8e0 <.data+0x17dce0>:
  57e8e0:	0c 50                	or     al,0x50
  57e8e2:	8b c7                	mov    eax,edi
  57e8e4:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  57e8e7:	e8 14 d4 ec ff       	call   0x44bd00
  57e8ec:	8b 08                	mov    ecx,DWORD PTR [eax]
  57e8ee:	5f                   	pop    edi
  57e8ef:	89 0e                	mov    DWORD PTR [esi],ecx
  57e8f1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8f5:	8b c6                	mov    eax,esi
  57e8f7:	5b                   	pop    ebx
  57e8f8:	8b e5                	mov    esp,ebp
  57e8fa:	5d                   	pop    ebp
  57e8fb:	c2 08 00             	ret    0x8
  57e8fe:	e8 09 29 31 00       	call   0x89120c
  57e903:	83 c4 04             	add    esp,0x4
  57e906:	5f                   	pop    edi
  57e907:	89 1e                	mov    DWORD PTR [esi],ebx
  57e909:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  57e90d:	8b c6                	mov    eax,esi
  57e90f:	5b                   	pop    ebx
  57e910:	8b e5                	mov    esp,ebp
  57e912:	5d                   	pop    ebp
  57e913:	c2 08              	ret    0x8
```

## E50.4 — Conn pool acquire 與執行前置：`805950` 從 reuse 或 new `0xA0D8` 取得

**研究問題**：Connect 取得 Conn 的來源與 `Pool+0x44` 計數如何進入池生命週期？

**N／reuse**：`0x806B0E → 0x805950(1)` 使用 Pool+0x34 mutex；若 `Pool+0x20!=0`，從 `Pool+0x10` vector 取得 Conn，`0x8059C6..0x8059E2` 減少可用數；`0x8059E9` 對 Conn 呼叫 `0x805F50` reset，再設 `Conn+A0AC=1`、`Pool+0x44++`。

**N／new**：若可用數為零且允許 new，`0x805A03 push 0xA0D8; call 0x891268` 取得新 Conn，`0x805A1B call 0x805CA0` 建構；之後繼承 Pool+38/+3C/+40 參數並準備標記 `A0AC=1`。在 `0x805950` 的 new 支線未出現與 reuse 相同的 `Pool+0x44++`，需要注意此差異；不可任意假設 Pool+44 是 active Conn 總數。

**N／重用模式**：`0x805F50` reset 方法未把 `Conn+A02C` 恢復 mode2（E46/E49 已核對），因此 pooled Conn 的重新使用和 fresh constructor `0x805D02` setting mode2 構成不同前提。這裡不強推所有重連都用 0BBB。

**失敗分支**：`0x806B1D test ebx,ebx` 為零就跳尾部回空；`0x806B92 cmp connect_res,-1` 走失敗子圖。建構內可能 alloc 失敗還有 catch/rethrow path；不因「有 return Conn*」斷言 socket 已 connected。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x0080597a–0x00805a00`；`.text` raw `0x404d7a–0x404e00`。

```asm
0080597a <.data+0x404d7a>:
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39 75              	cmp    DWORD PTR [ebp+0x8],esi
```

`VA 0x00805a00–0x00805a67`；`.text` raw `0x404e00–0x404e67`。

```asm
00805a00 <.data+0x404e00>:
  805a00:	08 74 5b 68          	or     BYTE PTR [ebx+ebx*2+0x68],dh
  805a04:	d8 a0 00 00 e8 5b    	fsub   DWORD PTR [eax+0x5be80000]
  805a0a:	b8 08 00 83 c4       	mov    eax,0xc4830008
  805a0f:	04 89                	add    al,0x89
  805a11:	45                   	inc    ebp
  805a12:	08 89 75 fc 3b c6    	or     BYTE PTR [ecx-0x39c4038b],cl
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
  805a5e:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  805a61:	52                   	push   edx
  805a62:	ff 15 48 22 bd     	call   DWORD PTR ds:0xbd2248
```

`VA 0x00806b0e–0x00806b40`；`.text` raw `0x405f0e–0x405f40`。

```asm
00806b0e <.data+0x405f0e>:
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
  806b3f:	0f             	movsx  ecx,WORD PTR [eax+0xa]
```

`VA 0x00805f50–0x0080600d`；`.text` raw `0x405350–0x40540d`。

```asm
00805f50 <.data+0x405350>:
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
```

## E50.5 — 正式填補 `Pool+0x48` writer：Connect 失敗只由 `806BD4/806BFB → 805AF0`

**研究問題**：E49 留下的 `Pool+0x48 producer` 是否可能具體定位？該路徑為何安排回收且如何改 `Conn+0x14`？

**N／直接 XREF**：用 `Tartaros.bin` 原始 bytes 逐 byte 對 E8 的 signed relative displacement 檢查，在此模組 `.text` 針對 `0x805AF0` 發現**兩個直接 CALL**：`0x806BD4` 與 `0x806BFB`，兩者均在 `0x806AD0` Connect 失敗回復分支。這是已檢查範圍的直接 call 清單，不代表間接 call 不存在。

**N／writer**：`0x805AF3 dec [Pool+0x44]`，`0x805AF7` 取 `Pool+0x48` sentinel，`0x805B03 call 0x74D700` 插入 list node，`0x805B25 mov [Pool+0x4C],...+1`，最終 `0x805B30 mov [Conn+0x14],0`。這證明 `Pool+0x48` **不是 E49 尚無 producer 的未知容器**；至少有明確 Connect failure producer。它不在此處呼叫 `Conn free`，也未保證原 socket 在失敗前已被 closesocket。

**C／失敗路徑**：socket `connect` 返回 -1 或後續 `setsockopt` 某一個返回 -1，均可轉回 `0x806C00`，將 Conn 放到延後回收 list；已建立的 socket 失敗是否即刻由其他函式 close 尚待查。因為 `Pool+0x44` 在 reused Conn 的 acquire 時被 +1，在此失敗時 -1，此值較適合作**部分可見 leased Conn balance**，不是可直接定義為總 active connection 数。

**反證**：`Pool+48` 不是由 `0x806FC0`（Conn-based close）直接 enqueue；該處呼叫 `0x805A80` 操作的是 **Pool+28**。兩條不得合併成同一步。

**U**：還需把 native memory/layout 分類的 virtual callers、manager teardown 與可能 exception branch 列入 complete-writer inventory，不能因兩個 direct xrefs 就宣稱所有可能 producer。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00806b80–0x00806c16`；`.text` raw `0x405f80–0x406016`。

```asm
00806b80 <.data+0x405f80>:
  806b80:	bd 00 6a 10 8d       	mov    ebp,0x8d106a00
  806b85:	4c                   	dec    esp
  806b86:	24 20                	and    al,0x20
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
```

`VA 0x00805af0–0x00805b3b`；`.text` raw `0x404ef0–0x404f3b`。

```asm
00805af0 <.data+0x404ef0>:
  805af0:	55                   	push   ebp
  805af1:	8b ec                	mov    ebp,esp
  805af3:	ff 4e 44             	dec    DWORD PTR [esi+0x44]
  805af6:	57                   	push   edi
  805af7:	8b 7e 48             	mov    edi,DWORD PTR [esi+0x48]
  805afa:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  805afd:	8d 45 08             	lea    eax,[ebp+0x8]
  805b00:	50                   	push   eax
  805b01:	51                   	push   ecx
  805b02:	57                   	push   edi
  805b03:	e8 f8 7b f4 ff       	call   0x74d700
  805b08:	8b 4e 4c             	mov    ecx,DWORD PTR [esi+0x4c]
  805b0b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  805b10:	2b d1                	sub    edx,ecx
  805b12:	83 fa 01             	cmp    edx,0x1
  805b15:	73 0a                	jae    0x805b21
  805b17:	68 34 20 bf 00       	push   0xbf2034
  805b1c:	e8 0f 80 07 00       	call   0x87db30
  805b21:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  805b24:	41                   	inc    ecx
  805b25:	89 4e 4c             	mov    DWORD PTR [esi+0x4c],ecx
  805b28:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  805b2b:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  805b2e:	89 01                	mov    DWORD PTR [ecx],eax
  805b30:	c7 42 14 00 00 00 00 	mov    DWORD PTR [edx+0x14],0x0
  805b37:	5f                   	pop    edi
  805b38:	5d                   	pop    ebp
  805b39:	c2 04              	ret    0x4
```

`VA 0x00806fc0–0x00807049`；`.text` raw `0x4063c0–0x406449`。

```asm
00806fc0 <.data+0x4063c0>:
  806fc0:	55                   	push   ebp
  806fc1:	8b ec                	mov    ebp,esp
  806fc3:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806fca:	75 15                	jne    0x806fe1
  806fcc:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806fd3:	74 07                	je     0x806fdc
  806fd5:	e8 86 3f c9 ff       	call   0x49af60
  806fda:	eb 05                	jmp    0x806fe1
  806fdc:	e8 1f 40 c9 ff       	call   0x49b000
  806fe1:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  806fe6:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  806fe9:	56                   	push   esi
  806fea:	57                   	push   edi
  806feb:	51                   	push   ecx
  806fec:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806ff2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  806ff5:	83 bf a8 a0 00 00 00 	cmp    DWORD PTR [edi+0xa0a8],0x0
  806ffc:	8b 37                	mov    esi,DWORD PTR [edi]
  806ffe:	75 4a                	jne    0x80704a
  807000:	85 f6                	test   esi,esi
  807002:	74 46                	je     0x80704a
  807004:	83 fe ff             	cmp    esi,0xffffffff
  807007:	74 41                	je     0x80704a
  807009:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  80700d:	75 1e                	jne    0x80702d
  80700f:	6a 04                	push   0x4
  807011:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  807014:	51                   	push   ecx
  807015:	68 80 00 00 00       	push   0x80
  80701a:	68 ff ff 00 00       	push   0xffff
  80701f:	56                   	push   esi
  807020:	c7 45 0c 01 00 00 00 	mov    DWORD PTR [ebp+0xc],0x1
  807027:	ff 15 ac 25 bd 00    	call   DWORD PTR ds:0xbd25ac
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff        	call   0x805a80
```

## E50.6 — 第二條 `Pool+0x48` producer：網路 Manager 析構逐項轉移

**研究問題**：除了 Connect failure，是否還有全域管理器結束時直接操作同一 list 的 native 寫入？

**N**：`0x806670` wrapper 呼叫 `0x8066A0`；該函式設定 vptr `0xC51748`，從 `Manager+0x1C` 的 tree root/sentinel 進行非空走訪。每筆節點讀 `[node+0x10]`（Conn*），在 `0x80673F` `dec [Pool+0x44]`，`0x806751 call 0x74D700` 寫入 `Pool+0x48` list，`0x80676A` 更新 `Pool+0x4C`，`0x806778 mov [Conn+0x14],0`。這一條**和 `0x805AF0` 在 producer 效果等價，但 upstream 不同**。

**N／iterator**：`0x80677F..0x8067C8` 追 tree next node，於到達 manager sentinel 後 `0x806821 call 0x803EC0` 完成其餘資源清理。該函式不是每次 socket close 都呼叫的證據；從 `0x806670` 的解構 wrapper 而來，應標註 manager teardown，不可視為正常網路 disconnect。

**C**：對析構時 tree 可達的 Conn*，它們可以被轉入 Pool+48 等待 outstanding I/O counter 閉合；**析構與 IOCP thread 同時狀態未知**，不能宣稱所有 Conn 一定安全回收。**對 E49 的修正**：`Pool+0x48` producer 至少兩類已證；`0x8066A0` inline producer 並非對 `0x805AF0` 的 direct call。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00806670–0x00806690`；`.text` raw `0x405a70–0x405a90`。

```asm
00806670 <.data+0x405a70>:
  806670:	55                   	push   ebp
  806671:	8b ec                	mov    ebp,esp
  806673:	56                   	push   esi
  806674:	8b f1                	mov    esi,ecx
  806676:	56                   	push   esi
  806677:	e8 24 00 00 00       	call   0x8066a0
  80667c:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  806680:	74 09                	je     0x80668b
  806682:	56                   	push   esi
  806683:	e8 84 ab 08 00       	call   0x89120c
  806688:	83 c4 04             	add    esp,0x4
  80668b:	8b c6                	mov    eax,esi
  80668d:	5e                   	pop    esi
  80668e:	5d                   	pop    ebp
  80668f:	c2               	ret    0x4
```

`VA 0x008066a0–0x008066ed`；`.text` raw `0x405aa0–0x405aed`。

```asm
008066a0 <.data+0x405aa0>:
  8066a0:	55                   	push   ebp
  8066a1:	8b ec                	mov    ebp,esp
  8066a3:	6a ff                	push   0xffffffff
  8066a5:	68 d6 44 91 00       	push   0x9144d6
  8066aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8066b0:	50                   	push   eax
  8066b1:	51                   	push   ecx
  8066b2:	53                   	push   ebx
  8066b3:	56                   	push   esi
  8066b4:	57                   	push   edi
  8066b5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8066ba:	33 c5                	xor    eax,ebp
  8066bc:	50                   	push   eax
  8066bd:	8d 45 f4             	lea    eax,[ebp-0xc]
  8066c0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8066c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  8066c9:	c7 07 48 17 c5 00    	mov    DWORD PTR [edi],0xc51748
  8066cf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  8066d6:	8b 47 1c             	mov    eax,DWORD PTR [edi+0x1c]
  8066d9:	8b 30                	mov    esi,DWORD PTR [eax]
  8066db:	3b f0                	cmp    esi,eax
  8066dd:	0f 84 ed 00 00 00    	je     0x8067d0
  8066e3:	8b 3d 58 a8 fb 00    	mov    edi,DWORD PTR ds:0xfba858
  8066e9:	85 ff                	test   edi,edi
  8066eb:	75 4f                	jne    0x80673c
```

`VA 0x0080673c–0x0080677e`；`.text` raw `0x405b3c–0x405b7e`。

```asm
0080673c <.data+0x405b3c>:
  80673c:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  80673f:	ff 4f 44             	dec    DWORD PTR [edi+0x44]
  806742:	8b 5f 48             	mov    ebx,DWORD PTR [edi+0x48]
  806745:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806748:	8d 4d f0             	lea    ecx,[ebp-0x10]
  80674b:	51                   	push   ecx
  80674c:	52                   	push   edx
  80674d:	53                   	push   ebx
  80674e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806751:	e8 aa 6f f4 ff       	call   0x74d700
  806756:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  806759:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  80675e:	2b d1                	sub    edx,ecx
  806760:	83 fa 01             	cmp    edx,0x1
  806763:	0f 82 d1 00 00 00    	jb     0x80683a
  806769:	41                   	inc    ecx
  80676a:	89 4f 4c             	mov    DWORD PTR [edi+0x4c],ecx
  80676d:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  806770:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  806773:	89 01                	mov    DWORD PTR [ecx],eax
  806775:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806778:	c7 40 14 00 00 00  	mov    DWORD PTR [eax+0x14],0x0
```

`VA 0x0080677e–0x0080683b`；`.text` raw `0x405b7e–0x405c3b`。

```asm
0080677e <.data+0x405b7e>:
  80677e:	00 80 7e 15 00 75    	add    BYTE PTR [eax+0x7500157e],al
  806784:	3d 8b 46 08 80       	cmp    eax,0x8008468b
  806789:	78 15                	js     0x8067a0
  80678b:	00 75 16             	add    BYTE PTR [ebp+0x16],dh
  80678e:	8b f0                	mov    esi,eax
  806790:	8b 06                	mov    eax,DWORD PTR [esi]
  806792:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  806796:	75 2a                	jne    0x8067c2
  806798:	8b f0                	mov    esi,eax
  80679a:	8b 06                	mov    eax,DWORD PTR [esi]
  80679c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067a0:	74 f6                	je     0x806798
  8067a2:	eb 1e                	jmp    0x8067c2
  8067a4:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  8067a7:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067ab:	75 13                	jne    0x8067c0
  8067ad:	8d 49 00             	lea    ecx,[ecx+0x0]
  8067b0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  8067b3:	75 0b                	jne    0x8067c0
  8067b5:	8b f0                	mov    esi,eax
  8067b7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  8067ba:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067be:	74 f0                	je     0x8067b0
  8067c0:	8b f0                	mov    esi,eax
  8067c2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  8067c5:	3b 71 1c             	cmp    esi,DWORD PTR [ecx+0x1c]
  8067c8:	0f 85 15 ff ff ff    	jne    0x8066e3
  8067ce:	8b f9                	mov    edi,ecx
  8067d0:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  8067d7:	75 35                	jne    0x80680e
  8067d9:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  8067e0:	33 c0                	xor    eax,eax
  8067e2:	50                   	push   eax
  8067e3:	50                   	push   eax
  8067e4:	50                   	push   eax
  8067e5:	6a ff                	push   0xffffffff
  8067e7:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  8067ec:	a3 bc 33 fe 00       	mov    ds:0xfe33bc,eax
  8067f1:	a3 c0 33 fe 00       	mov    ds:0xfe33c0,eax
  8067f6:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  8067fc:	68 b0 0b bd 00       	push   0xbd0bb0
  806801:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806806:	e8 0f bb 08 00       	call   0x89231a
  80680b:	83 c4 04             	add    esp,0x4
  80680e:	be b8 33 fe 00       	mov    esi,0xfe33b8
  806813:	e8 08 17 00 00       	call   0x807f20
  806818:	8b cf                	mov    ecx,edi
  80681a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  806821:	e8 9a d6 ff ff       	call   0x803ec0
  806826:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806829:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806830:	59                   	pop    ecx
  806831:	5f                   	pop    edi
  806832:	5e                   	pop    esi
  806833:	5b                   	pop    ebx
  806834:	8b e5                	mov    esp,ebp
  806836:	5d                   	pop    ebp
  806837:	c2 04 00             	ret    0x4
  80683a:	68           	push   0xbf2034
```

## E50.7 — Pending-I/O counter 完整條件式生命周期：post increment、completion decrement

**研究問題**：Pool+0x48 不立刻回用 Conn 的 gate 是否與 IOCP in-flight 數可精確相連？

**N／send**：`0x8068B0` 準備 WSASend，完成 post call `0x806920` 檢查其錯誤與 `0x3E5 (WSA_IO_PENDING)`。對成功/處理中的返回，`0x806961` 或 `0x80697A` `add esi,0xA0B8 ; push esi ; call [0xBD2284]`，即 `InterlockedIncrement(&Conn.A0B8)`。

**N／recv**：`0x806A00` 準備 WSARecv，部分 return 分支若判定可繼續由 `0x806ABF` 進入 virtual close；本段結合 `0x806CF0` 可見完成事件的對應減計數。`0x806CF0` 在成功 SEND completion `0x806EC3..` 用 `InterlockedDecrement(&A0B8)`，在部分失敗 completion `0x806EF1..` 也減；隨後讀值 `0x806F00`，只有 `==0` 才能進入 virtual close/cleanup 路徑。

**N／pool**：`0x805BA6` 同樣以 `Conn+A0B8==0` 才執行 `0x805F50` reset。即兩個不同 consumer 使用同一 outstanding-op 邊界；不是事件信號/WaitForSingleObject。

**C／受限於靜態**：increment 發生在 WSASend 調用**之後**的可見成功或 pending 路徑，而異常時回 0；無完整跨 thread/happens-before 驗證，不能推安全性、atomic counter 永不為負或所有 WSARecv 都有匹配增計數；這是必要的 runtime 故障測試點。

**新增具體命名建議**：`Conn+A0B8` 記為 `pending_io_ops`（用途暫名），而不是 `event_handle`。`Conn+A0BC` 另有 InterlockedExchange gate，功能仍須覆查。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x008068b0–0x008068fd`；`.text` raw `0x405cb0–0x405cfd`。

```asm
008068b0 <.data+0x405cb0>:
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
  8068fc:	89               	mov    DWORD PTR [eax+0x18],edi
```

`VA 0x00806910–0x00806995`；`.text` raw `0x405d10–0x405d95`。

```asm
00806910 <.data+0x405d10>:
  806910:	00 00                	add    BYTE PTR [eax],al
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
```

`VA 0x00806a3a–0x00806a76`；`.text` raw `0x405e3a–0x405e76`。

```asm
00806a3a <.data+0x405e3a>:
  806a3a:	01 c7                	add    edi,eax
  806a3c:	01 00                	add    DWORD PTR [eax],eax
  806a3e:	10 00                	adc    BYTE PTR [eax],al
  806a40:	00 8b 16 51 52 c7    	add    BYTE PTR [ebx-0x38adaeea],cl
  806a46:	45                   	inc    ebp
  806a47:	fc                   	cld
  806a48:	00 00                	add    BYTE PTR [eax],al
  806a4a:	00 00                	add    BYTE PTR [eax],al
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
  806a73:	c7 86 a8     	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	   
```

`VA 0x00806e7d–0x00806f2c`；`.text` raw `0x40627d–0x40632c`。

```asm
00806e7d <.data+0x40627d>:
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
  806f29:	e9 02 fe         	jmp    0x806d30
```

`VA 0x00805ba0–0x00805bc3`；`.text` raw `0x404fa0–0x404fc3`。

```asm
00805ba0 <.data+0x404fa0>:
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b 57 1c             	mov    edx,DWORD PTR [edi+0x1c]
  805bc2:	83               	add    edi,0x10
```

## E50.8 — Delay recycle 的兩條清理 list、`Conn+0x14` 的具體作用邊界

**研究問題**：`Pool+0x28` 的 close tracking 與 `Pool+0x48` 的 pending recycle 是否可視為同一資源節點？

**N**：`0x806FC0` 在 socket 非空且 `Conn+A0A8==0` 的條件下調用 `closesocket`，再 `0x805A80` 追加 **Pool+0x28**，設 `Conn+A0C0=GetTickCount()`（本段經 IAT 名稱直接驗證）；`0x805B40` 第一個 loop 掃 Pool+28，若 `Conn+0x14==0` 即刪除 **追蹤 list node**，沒有 reset Conn。第二個 loop 掃 Pool+48，只有 `A0B8==0` 才 reset Conn、寫回 Pool+0x10 vector，移除 list node、`Pool+0x4C--`。

**N／寫入 `Conn+0x14`**：`0x805B30`（Connect failure）與 `0x806778`（manager teardown）各清零此值。這可解釋為使 Pool+28 追蹤節點可被清理的同步標記之一，但**該欄位的完整型別（flags/refcount）需查其餘 writer**。不要把 `0x14==0` 和 `A0B8==0` 當成相同判斷。

**N／Pool+44**：在 reuse acquire `0x8059F9` +1、Connect failure `0x805AF3` -1、Manager teardown `0x80673F` -1，與 `Pool+4C`（Pool+48 list node count）分開。不能隨意將前者命名為 socket 數、後者命名為活躍連線數。

**C／可證失敗對照**：`Conn+14!=0` 時 Pool+28 追蹤節點保留；`A0B8!=0` 時 Pool+48 復用停止；兩個條件**獨立**。究竟何處把 Conn+14 由非零改零的全集，需再掃描與 runtime 記錄。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00806fc0–0x0080704a`；`.text` raw `0x4063c0–0x40644a`。

```asm
00806fc0 <.data+0x4063c0>:
  806fc0:	55                   	push   ebp
  806fc1:	8b ec                	mov    ebp,esp
  806fc3:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806fca:	75 15                	jne    0x806fe1
  806fcc:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806fd3:	74 07                	je     0x806fdc
  806fd5:	e8 86 3f c9 ff       	call   0x49af60
  806fda:	eb 05                	jmp    0x806fe1
  806fdc:	e8 1f 40 c9 ff       	call   0x49b000
  806fe1:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  806fe6:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  806fe9:	56                   	push   esi
  806fea:	57                   	push   edi
  806feb:	51                   	push   ecx
  806fec:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806ff2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  806ff5:	83 bf a8 a0 00 00 00 	cmp    DWORD PTR [edi+0xa0a8],0x0
  806ffc:	8b 37                	mov    esi,DWORD PTR [edi]
  806ffe:	75 4a                	jne    0x80704a
  807000:	85 f6                	test   esi,esi
  807002:	74 46                	je     0x80704a
  807004:	83 fe ff             	cmp    esi,0xffffffff
  807007:	74 41                	je     0x80704a
  807009:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  80700d:	75 1e                	jne    0x80702d
  80700f:	6a 04                	push   0x4
  807011:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  807014:	51                   	push   ecx
  807015:	68 80 00 00 00       	push   0x80
  80701a:	68 ff ff 00 00       	push   0xffff
  80701f:	56                   	push   esi
  807020:	c7 45 0c 01 00 00 00 	mov    DWORD PTR [ebp+0xc],0x1
  807027:	ff 15 ac 25 bd 00    	call   DWORD PTR ds:0xbd25ac
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff ff       	call   0x805a80
```

`VA 0x00805a80–0x00805ae0`；`.text` raw `0x404e80–0x404ee0`。

```asm
00805a80 <.data+0x404e80>:
  805a80:	55                   	push   ebp
  805a81:	8b ec                	mov    ebp,esp
  805a83:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  805a86:	8b 01                	mov    eax,DWORD PTR [ecx]
  805a88:	56                   	push   esi
  805a89:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a8c:	3b c1                	cmp    eax,ecx
  805a8e:	74 0b                	je     0x805a9b
  805a90:	39 70 08             	cmp    DWORD PTR [eax+0x8],esi
  805a93:	74 48                	je     0x805add
  805a95:	8b 00                	mov    eax,DWORD PTR [eax]
  805a97:	3b c1                	cmp    eax,ecx
  805a99:	75 f5                	jne    0x805a90
  805a9b:	ff 15 d4 22 bd 00    	call   DWORD PTR ds:0xbd22d4
  805aa1:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  805aa7:	8b 77 28             	mov    esi,DWORD PTR [edi+0x28]
  805aaa:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  805aad:	8d 45 08             	lea    eax,[ebp+0x8]
  805ab0:	50                   	push   eax
  805ab1:	51                   	push   ecx
  805ab2:	56                   	push   esi
  805ab3:	e8 48 7c f4 ff       	call   0x74d700
  805ab8:	8b 4f 2c             	mov    ecx,DWORD PTR [edi+0x2c]
  805abb:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  805ac0:	2b d1                	sub    edx,ecx
  805ac2:	83 fa 01             	cmp    edx,0x1
  805ac5:	73 0a                	jae    0x805ad1
  805ac7:	68 34 20 bf 00       	push   0xbf2034
  805acc:	e8 5f 80 07 00       	call   0x87db30
  805ad1:	41                   	inc    ecx
  805ad2:	89 4f 2c             	mov    DWORD PTR [edi+0x2c],ecx
  805ad5:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805ad8:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  805adb:	89 01                	mov    DWORD PTR [ecx],eax
  805add:	5e                   	pop    esi
  805ade:	5d                   	pop    ebp
  805adf:	c2               	ret    0x4
```

`VA 0x00805b40–0x00805b95`；`.text` raw `0x404f40–0x404f95`。

```asm
00805b40 <.data+0x404f40>:
  805b40:	55                   	push   ebp
  805b41:	8b ec                	mov    ebp,esp
  805b43:	83 ec 18             	sub    esp,0x18
  805b46:	53                   	push   ebx
  805b47:	56                   	push   esi
  805b48:	57                   	push   edi
  805b49:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805b4c:	8b 5f 28             	mov    ebx,DWORD PTR [edi+0x28]
  805b4f:	8b 03                	mov    eax,DWORD PTR [ebx]
  805b51:	3b c3                	cmp    eax,ebx
  805b53:	74 33                	je     0x805b88
  805b55:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  805b58:	83 79 14 00          	cmp    DWORD PTR [ecx+0x14],0x0
  805b5c:	75 24                	jne    0x805b82
  805b5e:	8b 30                	mov    esi,DWORD PTR [eax]
  805b60:	3b 47 28             	cmp    eax,DWORD PTR [edi+0x28]
  805b63:	74 19                	je     0x805b7e
  805b65:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b68:	89 32                	mov    DWORD PTR [edx],esi
  805b6a:	8b 08                	mov    ecx,DWORD PTR [eax]
  805b6c:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b6f:	50                   	push   eax
  805b70:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805b73:	e8 94 b6 08 00       	call   0x89120c
  805b78:	83 c4 04             	add    esp,0x4
  805b7b:	ff 4f 2c             	dec    DWORD PTR [edi+0x2c]
  805b7e:	8b c6                	mov    eax,esi
  805b80:	eb 02                	jmp    0x805b84
  805b82:	8b 00                	mov    eax,DWORD PTR [eax]
  805b84:	3b c3                	cmp    eax,ebx
  805b86:	75 cd                	jne    0x805b55
  805b88:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  805b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  805b8d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805b90:	3b c1                	cmp    eax,ecx
  805b92:	75 0f                	jne    0x805ba3
  805b94:	5f                   	pop    edi
```

`VA 0x00805b9d–0x00805c69`；`.text` raw `0x404f9d–0x405069`。

```asm
00805b9d <.data+0x404f9d>:
  805b9d:	8d 49 00             	lea    ecx,[ecx+0x0]
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b 57 1c             	mov    edx,DWORD PTR [edi+0x1c]
  805bc2:	83 c7 10             	add    edi,0x10
  805bc5:	03 d0                	add    edx,eax
  805bc7:	f6 c2 03             	test   dl,0x3
  805bca:	75 11                	jne    0x805bdd
  805bcc:	83 c0 04             	add    eax,0x4
  805bcf:	c1 e8 02             	shr    eax,0x2
  805bd2:	39 47 08             	cmp    DWORD PTR [edi+0x8],eax
  805bd5:	77 06                	ja     0x805bdd
  805bd7:	57                   	push   edi
  805bd8:	e8 93 13 e3 ff       	call   0x636f70
  805bdd:	8b 5f 0c             	mov    ebx,DWORD PTR [edi+0xc]
  805be0:	03 5f 10             	add    ebx,DWORD PTR [edi+0x10]
  805be3:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  805be6:	8b f3                	mov    esi,ebx
  805be8:	c1 ee 02             	shr    esi,0x2
  805beb:	3b c6                	cmp    eax,esi
  805bed:	77 02                	ja     0x805bf1
  805bef:	2b f0                	sub    esi,eax
  805bf1:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  805bf4:	83 3c b0 00          	cmp    DWORD PTR [eax+esi*4],0x0
  805bf8:	75 14                	jne    0x805c0e
  805bfa:	6a 10                	push   0x10
  805bfc:	e8 67 b6 08 00       	call   0x891268
  805c01:	83 c4 04             	add    esp,0x4
  805c04:	85 c0                	test   eax,eax
  805c06:	74 63                	je     0x805c6b
  805c08:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  805c0b:	89 04 b1             	mov    DWORD PTR [ecx+esi*4],eax
  805c0e:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  805c11:	8b 04 b2             	mov    eax,DWORD PTR [edx+esi*4]
  805c14:	83 e3 03             	and    ebx,0x3
  805c17:	8d 1c 98             	lea    ebx,[eax+ebx*4]
  805c1a:	85 db                	test   ebx,ebx
  805c1c:	74 05                	je     0x805c23
  805c1e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805c21:	89 0b                	mov    DWORD PTR [ebx],ecx
  805c23:	ff 47 10             	inc    DWORD PTR [edi+0x10]
  805c26:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805c29:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805c2c:	8b 30                	mov    esi,DWORD PTR [eax]
  805c2e:	3b 47 48             	cmp    eax,DWORD PTR [edi+0x48]
  805c31:	74 19                	je     0x805c4c
  805c33:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c36:	89 32                	mov    DWORD PTR [edx],esi
  805c38:	8b 08                	mov    ecx,DWORD PTR [eax]
  805c3a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c3d:	50                   	push   eax
  805c3e:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805c41:	e8 c6 b5 08 00       	call   0x89120c
  805c46:	83 c4 04             	add    esp,0x4
  805c49:	ff 4f 4c             	dec    DWORD PTR [edi+0x4c]
  805c4c:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805c4f:	eb 05                	jmp    0x805c56
  805c51:	8b 00                	mov    eax,DWORD PTR [eax]
  805c53:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805c56:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  805c59:	3b 4f 48             	cmp    ecx,DWORD PTR [edi+0x48]
  805c5c:	0f 85 3e ff ff ff    	jne    0x805ba0
  805c62:	5f                   	pop    edi
  805c63:	5e                   	pop    esi
  805c64:	5b                   	pop    ebx
  805c65:	8b e5                	mov    esp,ebp
  805c67:	5d                   	pop    ebp
  805c68:	c2               	ret    0x4
```

## E50.9 — S2C 0x007A／0x0013 對選服 record 的下界：結構算式不是已檢查的 guard

**研究問題**：如何把連線上游選服表資料需要的最小 bytes 描述成可測而不捏造已存在的驗證？

**N／0x007A**：`0x4C3C13` 讀 `DWORD payload+2` 作 group count，`0x4C3C1A LEA [payload+6]` 傳給 `0x4C3080`；該方法每個 group 在 `0x4C30BE` 讀 `WORD group[0]`、`0x4C30C9` 讀 `BYTE group[2]` child count，`0x4C30C1` 將 child 指標移至 group+3；每個 child `0x4C30FF ADD EDI,0xA`，讀 child+4..+7 IPv4 octets，child+8 enabled，child+9 另一欄位，child 0..1 還會在 enabled 分支讀 WORD。此為確定的讀取與游標步長。

**C／至少需求**：若輸入由 `0x007A` handler 傳入，包含 G 個群組、各群組 Ni 個 child，必須使 `payload_len >= 6 + Σ(i=1..G)(3+10*Ni)` 才能容納本函式的已證**靜態讀取偏移**。這是**由 code 推導出的資料需求/測試 oracle**，不等於 Client 真正做了此比較。4-byte G 若不受控也可能耗時；潛在整數溢位/緩衝風險須交獨立安全測試，不能以無執行驗證的推算宣告可利用性。

**N／handler ABI**：`0x4C4670` 在 dispatch 有 `(payload*, length_or_second_arg, command)` 三參數；但是 `0x4C3C10` 僅讀 `[ebp+8]` 作 payload，直接使用 payload+2/+6，未在該函式作 `cmp length`。`0x4C3080` 只收 group_count，而非剩餘 bytes，loop 內也沒有剩餘長度比較。`0x4C37A0` 讀 payload+0x16 的 count/flag 等欄位，另外條件式進到共享解析器；其各分支的完整最小長度仍未證明。

**界線／反證**：transport `0x1000` 是 `copy` 上限，不保證業務層 group list 合法；若 Server 要相容，必須正確產生實際可被 Client 解析的結構，而不是以 4096 任意填補。本段的長度推導是供 S00 的有限規格候選，未經 T01 FULL-PASS 不能自行升格。

**U**：首次真實 `0x0013` 分支與 `0x007A` 線上樣本、sender 合法 group bounds、上游解壓後保證，以及 UI 是否立即切換，仍無 trace。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x004c3c10–0x004c3c26`；`.text` raw `0xc3010–0xc3026`。

```asm
004c3c10 <.data+0xc3010>:
  4c3c10:	55                   	push   ebp
  4c3c11:	8b ec                	mov    ebp,esp
  4c3c13:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c3c16:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4c3c19:	51                   	push   ecx
  4c3c1a:	8d 48 06             	lea    ecx,[eax+0x6]
  4c3c1d:	e8 5e f4 ff ff       	call   0x4c3080
  4c3c22:	33 c0                	xor    eax,eax
  4c3c24:	5d                   	pop    ebp
  4c3c25:	c2               	ret    0xc
```

`VA 0x004c3080–0x004c3150`；`.text` raw `0xc2480–0xc2550`。

```asm
004c3080 <.data+0xc2480>:
  4c3080:	55                   	push   ebp
  4c3081:	8b ec                	mov    ebp,esp
  4c3083:	83 e4 f8             	and    esp,0xfffffff8
  4c3086:	83 ec 24             	sub    esp,0x24
  4c3089:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c308e:	33 c4                	xor    eax,esp
  4c3090:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4c3094:	53                   	push   ebx
  4c3095:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c3098:	56                   	push   esi
  4c3099:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  4c309f:	57                   	push   edi
  4c30a0:	83 c6 08             	add    esi,0x8
  4c30a3:	8b f9                	mov    edi,ecx
  4c30a5:	e8 96 11 00 00       	call   0x4c4240
  4c30aa:	85 db                	test   ebx,ebx
  4c30ac:	0f 84 98 00 00 00    	je     0x4c314a
  4c30b2:	89 5c 24 0c          	mov    DWORD PTR [esp+0xc],ebx
  4c30b6:	8b 15 54 1b fe 00    	mov    edx,DWORD PTR ds:0xfe1b54
  4c30bc:	8b df                	mov    ebx,edi
  4c30be:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4c30c1:	83 c7 03             	add    edi,0x3
  4c30c4:	e8 47 44 04 00       	call   0x507510
  4c30c9:	80 7b 02 00          	cmp    BYTE PTR [ebx+0x2],0x0
  4c30cd:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c30d1:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4c30d8:	00 
  4c30d9:	76 65                	jbe    0x4c3140
  4c30db:	eb 03                	jmp    0x4c30e0
  4c30dd:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c30e0:	8b f7                	mov    esi,edi
  4c30e2:	0f b6 46 07          	movzx  eax,BYTE PTR [esi+0x7]
  4c30e6:	0f b6 4e 06          	movzx  ecx,BYTE PTR [esi+0x6]
  4c30ea:	0f b6 56 05          	movzx  edx,BYTE PTR [esi+0x5]
  4c30ee:	50                   	push   eax
  4c30ef:	0f b6 46 04          	movzx  eax,BYTE PTR [esi+0x4]
  4c30f3:	51                   	push   ecx
  4c30f4:	52                   	push   edx
  4c30f5:	50                   	push   eax
  4c30f6:	68 50 b0 bf 00       	push   0xbfb050
  4c30fb:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  4c30ff:	83 c7 0a             	add    edi,0xa
  4c3102:	e8 29 12 00 00       	call   0x4c4330
  4c3107:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  4c310b:	83 c4 14             	add    esp,0x14
  4c310e:	85 c9                	test   ecx,ecx
  4c3110:	74 1d                	je     0x4c312f
  4c3112:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4c3115:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c3119:	52                   	push   edx
  4c311a:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  4c311e:	50                   	push   eax
  4c311f:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4c3123:	50                   	push   eax
  4c3124:	a1 54 1b fe 00       	mov    eax,ds:0xfe1b54
  4c3129:	50                   	push   eax
  4c312a:	e8 e1 44 04 00       	call   0x507610
  4c312f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4c3133:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  4c3137:	40                   	inc    eax
  4c3138:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c313c:	3b c1                	cmp    eax,ecx
  4c313e:	72 a0                	jb     0x4c30e0
  4c3140:	ff 4c 24 0c          	dec    DWORD PTR [esp+0xc]
  4c3144:	0f 85 6c ff ff ff    	jne    0x4c30b6
  4c314a:	68 43 42 0f 00       	push   0xf4243
  4c314f:	e8           	call   0x58aad0
```

`VA 0x004c4670–0x004c46ee`；`.text` raw `0xc3a70–0xc3aee`。

```asm
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
  4c46ed:	c2               	ret    0xc
```

`VA 0x004c37ce–0x004c3830`；`.text` raw `0xc2bce–0xc2c30`。

```asm
004c37ce <.data+0xc2bce>:
  4c37ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c37d1:	33 db                	xor    ebx,ebx
  4c37d3:	8d 46 20             	lea    eax,[esi+0x20]
  4c37d6:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c37dc:	89 8d b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],ecx
  4c37e2:	66 39 18             	cmp    WORD PTR [eax],bx
  4c37e5:	74 3a                	je     0x4c3821
  4c37e7:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  4c37ed:	53                   	push   ebx
  4c37ee:	53                   	push   ebx
  4c37ef:	68 00 04 00 00       	push   0x400
  4c37f4:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4c37fa:	51                   	push   ecx
  4c37fb:	6a ff                	push   0xffffffff
  4c37fd:	50                   	push   eax
  4c37fe:	53                   	push   ebx
  4c37ff:	52                   	push   edx
  4c3800:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  4c3806:	6a 32                	push   0x32
  4c3808:	8d 85 f0 fb ff ff    	lea    eax,[ebp-0x410]
  4c380e:	50                   	push   eax
  4c380f:	68 97 00 00 00       	push   0x97
  4c3814:	68 00 a7 fb 00       	push   0xfba700
  4c3819:	e8 cd 20 3d 00       	call   0x8958eb
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8           	call   0x891268
```

## E50.10 — 整合 RR-0005：選服到 key-map replace／pool 兩條回收模式及下一段阻塞

**研究問題**：本次 10 子段能否真正閉合 RR-0005 的端到端鏈，哪些應留待動態測試而不可憑靜態想像？

**N/C：已證條件式鏈**：`S2C 0x0013/0x007A → 對應 handler → 0x4C3080 解 group/child IPv4 → FE1B54 之 record+0xC → 0x66B910 UI 消費 → 0x66C620/0x66C090 玩家選擇 → 0x4957C0 key0/key2 連線（0x20E0/0x20DE） → Network Manager 0x806AD0(Conn) → Pool 0x805950 acquire → connect/setsockopt/CompletionPort → Manager+18 key-map find/erase/insert → 初始 application queue（E45 已有 key0 57-byte 0x0001 候選） → encode/WSASend → IOCP receive+dispatch`。上半段來自 E44/E45；本段新增 **同 key map erase/insert 明確 writer**、**失敗 Pool+48 producer** 及 **Interlocked pending I/O 的 gate**。

**N／失敗矩陣**：1) Connect/setsockopt -1：`806BD4/806BFB→805AF0→Pool+48`、`Conn+14=0`，之後 `805B40` 只有 A0B8==0 才 reset；2) Conn-based close：`806FC0→closesocket→805A80→Pool+28`，不是 map erase；3) network manager destructor：`8066A0` 迭代 key-map 並 inline 移入 Pool+48，與 normal close 不同；4) 相同 key 新 Connect 成功：`806CB3→7B6890` 擦掉舊 map **node**，`806CC7/806CD2` 建立新 key node，不能推論舊 Conn 同步 close/free；5) IOCP completion 零/失敗與 pending counter 仍由各個 branch 控制，非一律重新 recv。

**本段成果判定**：`Pool+48 producer`、`A0B8` atomic counter 型別、`Manager+18` 重連 key-map erase writer **三項 E49 缺口取得原生解答**。但整條 RR-0005 **未達 A**：沒有活體登入 trace、first WSASend/首回覆、S2C `0x0013/0x007A` 真實合法 payload、全部 key lifecycle／retry gates。

**10 子段強制停止 B**：重大發現不作停段理由；累積 E50.1–.10 十個主題後依使用者停止規則交接 E51。

**後續 E51 優先序**：① 同 key 替換前舊 Conn* ownership 與 socket 關閉的缺漏；② `Conn+14` 所有 writer 與 pool28/pool48 cross-list 競態；③ `A0B8` send/recv post 成功與 pending completion 的增減對稱；④ 將 E50 有界證據與 T03 0x0013 UI 状態跨 Task 串接；⑤ 取得合法測試環境的第一筆 key0/key2 frame 和 Server 首回覆，保留部署端點決策與 legacy static port 分離。

**未解分類**：Client 待逆向：舊 Conn 清理、A02C 的其他 writer、所有 post/IOCP 平衡、0x0013 payload 全部分支；跨功能待整合：登入 S2C→UI→同一 session connect 時序；待遊玩驗證：wire/pcap、重連、Pool 重用；Server 待開發：對已證 Client parser/連線合約實作對應相容回覆，不冒稱原版 Server 策略。

**BIN 原生 Assembly（E50 現場重讀）**：

`VA 0x00806c91–0x00806cea`；`.text` raw `0x406091–0x4060ea`。

```asm
00806c91 <.data+0x406091>:
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp
```

`VA 0x00806bd3–0x00806c16`；`.text` raw `0x405fd3–0x406016`。

```asm
00806bd3 <.data+0x405fd3>:
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
```

`VA 0x00806e00–0x00806e33`；`.text` raw `0x406200–0x406233`。

```asm
00806e00 <.data+0x406200>:
  806e00:	2c ff                	sub    al,0xff
  806e02:	ff                   	(bad)
  806e03:	ff 8d 50 18 50 e8    	dec    DWORD PTR [ebp-0x17afe7b0]
  806e09:	33 0d 00 00 85 c0    	xor    ecx,DWORD PTR ds:0xc0850000
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74                 	je     0x806e6e
```

`VA 0x00805b9f–0x00805bc3`；`.text` raw `0x404f9f–0x404fc3`。

```asm
00805b9f <.data+0x404f9f>:
  805b9f:	00 8b 45 fc 8b 70    	add    BYTE PTR [ebx+0x708bfc45],cl
  805ba5:	08 8b 8e b8 a0 00    	or     BYTE PTR [ebx+0xa0b88e],cl
  805bab:	00 89 75 f8 85 c9    	add    BYTE PTR [ecx-0x367a078b],cl
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b 57 1c             	mov    edx,DWORD PTR [edi+0x1c]
  805bc2:	83               	add    edi,0x10
```

`VA 0x004c30df–0x004c313f`；`.text` raw `0xc24df–0xc253f`。

```asm
004c30df <.data+0xc24df>:
  4c30df:	00 8b f7 0f b6 46    	add    BYTE PTR [ebx+0x46b60ff7],cl
  4c30e5:	07                   	pop    es
  4c30e6:	0f b6 4e 06          	movzx  ecx,BYTE PTR [esi+0x6]
  4c30ea:	0f b6 56 05          	movzx  edx,BYTE PTR [esi+0x5]
  4c30ee:	50                   	push   eax
  4c30ef:	0f b6 46 04          	movzx  eax,BYTE PTR [esi+0x4]
  4c30f3:	51                   	push   ecx
  4c30f4:	52                   	push   edx
  4c30f5:	50                   	push   eax
  4c30f6:	68 50 b0 bf 00       	push   0xbfb050
  4c30fb:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  4c30ff:	83 c7 0a             	add    edi,0xa
  4c3102:	e8 29 12 00 00       	call   0x4c4330
  4c3107:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  4c310b:	83 c4 14             	add    esp,0x14
  4c310e:	85 c9                	test   ecx,ecx
  4c3110:	74 1d                	je     0x4c312f
  4c3112:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4c3115:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c3119:	52                   	push   edx
  4c311a:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  4c311e:	50                   	push   eax
  4c311f:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4c3123:	50                   	push   eax
  4c3124:	a1 54 1b fe 00       	mov    eax,ds:0xfe1b54
  4c3129:	50                   	push   eax
  4c312a:	e8 e1 44 04 00       	call   0x507610
  4c312f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4c3133:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  4c3137:	40                   	inc    eax
  4c3138:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c313c:	3b c1                	cmp    eax,ecx
  4c313e:	72                 	jb     0x4c30e0
```

## 附錄 A：反證、可再現核對與 import API 原文

`objdump -p /mnt/data/Tartaros.bin` KERNEL32 的原始 import name 對照（printed VMA 0x007D22xx；執行時 IAT 0x00BD22xx）：

```text
007d2274 GetQueuedCompletionStatus
007d2278 CreateIoCompletionPort
007d227c InterlockedDecrement
007d2280 InterlockedExchange
007d2284 InterlockedIncrement
007d22d4 GetTickCount
```

E50 的任何本地 opcode/disasm 證據均可用：

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -p /mnt/data/Tartaros.bin | grep -A 12 'CreateIoCompletionPort'
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806c91 --stop-address=0x806cea /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x805af0 --stop-address=0x805b40 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8066a0 --stop-address=0x806840 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806ec0 --stop-address=0x806f2e /mnt/data/Tartaros.bin
```

**E8 direct XREF 的限定算法**：在 PE `.text` 起始 raw/VMA 對應內，遇到 opcode `E8` 用 `callsite_va+5+sign_extend32(rel32)` 求 target；原始 bytes 搜尋可以捕捉從 instruction immediate 中間誤命中的假陽性，故用目標的原生 caller 重新 disassemble 確認邊界。在 `0x805AF0` 上得到 `0x806BD4` 和 `0x806BFB`，且這兩個 caller 都已從 `0x806AD0` 之 CFG 核實。此列舉**不是完整間接 caller 證明**。

## 附錄 B：E49→E50 更正清單

| 舊描述 | 本次第一手修正 | 確認程度 |
|---|---|---|
| `0x49B070` 是 key-map erase | 它是 Pool singleton getter；實際 key-map node erase 為 `0x806CB3→0x7B6890` | N（限定同 key replace 成功鏈） |
| `Pool+0x48` writer 不明 | Connect 失敗的 `0x805AF0` 與 Manager 析構的 inline `0x8066A0` 均有 producer | N（至少兩類） |
| `Conn+A0B8` 被 SetEvent、event handle | PE import 證明 `0xBD2284=InterlockedIncrement`、`0xBD227C=InterlockedDecrement`，zero gate 為 pending I/O count | N（相關路徑） |
| close 必定移除 active map | `0x806F80`、`0x806FC0` 目前不見 erase；同 key replacement 才有確定 `7B6890` | N/未證他路徑 |
| 0x007A 結構已由上游強制驗證 | 只能算出 `6+Σ(3+10Ni)` 至少被讀取的資料需求，不能冒稱檢查存在 | C/U |

## 附錄 C：完整交接／提交狀態

此份為 **E50 原始全量分析**，非單純摘要或將 E49 重新改名。範圍限定 KR 原生 Client `Tartaros.bin`；`0x0013/0x007A` handler 部分是跨 T03 入口復核，不覆寫 T03 主責原稿。下一正式段號 E51。研究證據深度不代表程式現場執行，所有 first-wire claims 仍待 trace。

**GitHub**：使用者明確授權本次 E50 完成後 Commit/Push。應連同尚未提交的 E46–E49 完整原稿上傳 `extra/roy1` 的 `kr-extra-roy/`，在 git 完成後回報實際 SHA/每份 blob；不得把尚未在 main 公開的研究原稿當作 RR 正式認領。
