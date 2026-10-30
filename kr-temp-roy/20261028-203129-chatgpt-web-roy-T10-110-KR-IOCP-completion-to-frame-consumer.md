# T10-110 — KR IOCP completion 來源與收送分流至 frame consumer（BIN-first）

## 0. 研究前提、來源與保護邊界

2026-10-28 Asia/Taipei；`t10/roy/chatgpt-web`，已核對 `main` fully merged。T10-109 的 queue 類別與空 record 是上一段；本段從 T10-108 的 `0x807B40` 逆向追到真正 OS completion consumer，而非重述 queue helper。僅對 KR PE32 唯讀反組譯；不執行程式、不修改原 BIN、無現場封包樣本、不推測原版 Server 行為。反編譯原稿與 repo 只用來導覽。保留前一段結論，若推進證據有別僅在本段註明更新，不覆蓋舊稿。

- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次從檔案重算。
- EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本次重算。
- `.text` VA `0x401000`, raw `0x400`, size `0x7D01F0`；`raw = VA - 0x400C00`。`.rdata` VA `0xBD2000`, raw `0x7D0600`。`.data` VA `0xD61000`, raw `0x95E800`；zero-fill 全域不能套 raw 公式。
- 工具 `objdump -D -Mintel`, `objdump -p`, `sha256sum`；下面每個 VA 窗口均從本次 BIN 重新反組譯，地址以實際指令為準。搜尋 E8 呼叫候選不當作所有 indirect caller 的窮舉。

## 1. 第 1 輪：從接收 frame 真實 caller 逆追 IOCP

### 1.1 `0x806CF0` 為 completion worker 的直接證據

`0x806D30..806D67` 判斷 lazy-init byte `0xFE33B4 bit0`，沒有初始化時呼叫 IAT `[0xBD2278] = CreateIoCompletionPort`（由 `objdump -p` 的 PE import name table 一手核定）；結果存在 `[0xFE33B8]`，另有 `0xFE33BC/0xFE33C0` 初始化。這是 completion port 的建立路徑，不等於特定 TCP socket 的 `WSARecv` 發起已證。

接著 `0x806D6F..806D8A` push `INFINITE = -1`、overlapped 輸出 `[ebp-0x20]`、key 輸出 `[ebp-0x1c]`、bytesTransferred 輸出 `[ebp-0x24]` 和 port handle，call `[0xBD2274] = GetQueuedCompletionStatus`。此 OS API 的標準 ABI 正好與 native push 方向相符，五次 push 從右至左列於下面原生反組譯窗口。返回 `EAX=0` 跳 `0x806ECF` 分支；返回非零才處理 key/type。

回傳值的「success」是 OS completion call 層級，**不是 Server 確認普攻或技能的結果**。`0x806D92` 讀 key `[ebp-0x1c]`，若等於1跳 `0x806F2E`；不是應用層 opcode1。`0x806DE4` 以 `(key+0xA030)==overlapped` 作分支比對，不能將 overlapped 的類別直接稱 socket packet ID。

### 1.2 收到完成事件之後的分流

`0x806DE4..806E1C` 當 `overlapped == key+0xA030` 時，更新 worker counters `[owner+0x2C]` / `+0x3C`。gate `[key+0xA0AC]` 非零才以 `EDX=key+0x18`、`push key` 呼叫 `0x807B40`。呼叫返回 EAX 非零時，依 worker `vtable+0x14` call；EAX=0 則檢查 `[key+0xA0B0]` 並進入不同的清理/記錄分支。**這裡的回呼是 socket worker callback 類候選，不是 actor 動作回呼**。

另一分支 `0x806E7D..806ECA` 針對 `overlapped == key+0xA050`，更新 `[worker+0x28]/+0x38`，當 `[key+0xA0AC]` gate 非零，呼叫 `0x8077B0`，接著以 `[key+0xA028]>0` 寫 `[key+0xA024]`，再對 `[key+0xA0B8]` 呼叫 IAT InterlockedDecrement。此分支沒有呼叫 `0x807B40`；不能逕自認成同一個收包解析器，也不能僅憑相反 overlapped offset 宣稱就是「send completion」（需查提交 I/O 的發起者）。

**新增重要邊界**：Key 的 `+0xA030/+0xA050` 分別與 overlapped identity 比對，與先前已知 `+0xA080` queue category 完全不同。`+0xA0AC` 是本段分支 gate，尚未證實它與連線可用、socket state 或 gameplay 旗標的業務語義。所有 offset 都要帶 key/worker 物件 provenance。

### 1.3 `0x807B40` 的實際入口協定

上一段研究的 parser entry 精確入口是 `0x807B40`，**不是 `0x807B60`**（後者是 prologue 內部 `call 0x8B0670` 的下一條指令）。本次 E8 rel32 逐 byte scan 找到直接 caller `0x806E08`；反組譯確認 `e8 33 0d 00 00`。進入時 `EDX=key+0x18`，`ECX` 是 GetQueuedCompletionStatus 寫入 `[ebp-0x24]` 的 transferred bytes（後續 `0x806DE4` 來自 `[ebp-0x24]`），stack arg `[ebp+8]=key`。parser `0x807B85 mov eax,[ebp+8]` / `mov edi,edx` / `add [edi+0x5000],ecx` 是 Native 支持的資料 append。

解析器對 `+0x5000` 當前 buffer end／累積接收長度做運算，首 WORD payload length 0 或 >4096 時退出、依第二 WORD 選通常4、特例6/8 bytes 前綴；T10-108 已核。這些前綴屬 **Client memory 中分框**，還沒有證明 raw socket 未經改造的 wire framing schema。

### 1.4 明確排除：`0x807A70` 是另一條 outgoing construction

`0x80623A` 是 `0x807A70` 的確認直接 caller，caller 從 `[esi+0x501c]` 指向不同 pending buffer，push 來源及長度，再進 `0x807A70`。後者寫 frame marker `0x1A68` 與原長度 WORD（`0x807A8A..807A93`），以 `len+4<=0x1000`/非零與空間 overlap 條件為界，於 `0x807AE9..AF2` 呼叫 copy helper，把資料寫到 owner 的 pending-buffer。該函式成功返回 EAX=1，失敗 EAX=0、`ret 8`；不能把 marker `0x1A68` 當普通攻擊 opcode、也不能把它視作接收 parser 原始資料。

此功能可以定為**輸出緩衝中的 frame 組建**，但還不等於證明後續 WSA socket send 被呼叫；需從 `+0x501C` 寫出 consumer/IOCP 發起者向下追。此處與 `0x807B40` 是兩個不同 caller 的反證。

## 2. 可重現的最小控制／資料流

```text
0x806CF0 completion worker
  0x806D57 CreateIoCompletionPort (lazy-init)
  0x806D84 GetQueuedCompletionStatus(port, &bytes, &key, &ov, INFINITE)
    ├── returned false → 0x806ECF, special/error handling (未全審)
    ├── key==1 → 0x806F2E (special handling 未全審)
    ├── ov==key+0xA030
    │    ├── worker +0x2C += bytes; worker +0x3C++
    │    ├── key+0xA0AC != 0 → 0x807B40(key, EDX=key+0x18, ECX=bytes)
    │    └── parser true → worker virtual+0x14(key)
    └── ov==key+0xA050
         ├── worker +0x28 += bytes; worker +0x38++
         ├── gate → 0x8077B0 (方向待發起者確認)
         └── InterlockedDecrement(key+0xA0B8)

0x80623A → 0x807A70 (marker0x1A68, pending frame), NOT recv parser
0x807B40 → 0x807D7F..0x807DAD (frame transform/copy → category queue)
  → 0x8040A0 → 0x804100/0x804740 → conditional callback 0x4930E0
```

本段不宣稱上述兩條分支均為單一 socket、更不以 `0x4930E0` 的 key0 當作普攻 response proof。`0x807B40` 成功返回的條件需對全部例外分支再審，不能將每個 OS completion 都算為已解析 packet。

## 3. 玩家情境 × Client × C→S × S→C × 動作／分工矩陣

| 玩家操作／條件 | Client 原生已確認 | C→S 實際發送 | S→C 收到／handler | Client 動作結果 | 伺服器責任／證據 |
|---|---|---|---|---|---|
| 玩家短按 Z，bank 已映射 ID13 | T10-101/102 原稿條件式 input→000A；本段未補 input與 socket send call | 000A 本地建構鏈有既證條件；socket write 未由本段新增驗證 | IOCP 成功完成與 `0x807B40` 解析鏈有界，但無此按鍵的回覆 mapping | 起手先播／等回覆 unknown | Client/T02交叉依賴；原版 Server 規則 unknown |
| 玩家連按／長按／放開 Z | 同上，phase1/2/3 有 native producer，但 dispatch/網路頻率不等於 phase 數量 | 次數/時序 unknown | 封包回覆節奏 unknown | 連段／取消 unknown | 禁止自造0.65秒 |
| 操作觸發接收 completion 且 gate 開放 | key+0xA030 identity、`+0xA0AC` gate → parser | 非本函式職責 | **原生已確認 IOCP→frame consumer**，frame 內容仍需拆包 | 若 parsed true 呼叫 worker virtual+0x14，非 actor motion 證據 | socket T02共用，T10僅引用必要接口 |
| 完成事件 key+0xA050 | 已證 native counter/callback 路徑，不在本窗口進 parser | 方向／send API 待證 | 不經 `0x807B40` 支鏈 | 不代表拒絕或播放動作 | 事件類別與 gameplay 仍 unknown |
| 收到可分派的分類2 buffer 且 header K=0 | T10-106/108 處理成 `4930E0→ParamUpdate` 條件鏈 | 非此支鏈 | queue 資料 header K=0 可改特定 actor property4 | 未證 attack motion 或 Server 接受 | app key 仍非完整 wire header/ack proof |

## 4. 證據分級／反證範圍

- **已確認**：PE import name 透過原 BIN IAT 查表；本段精確 `0x806D57` port init、`0x806D84` completion wait、`0x806E08` parser direct call、`0x80623A` output frame builder call、overlapped pointer equality、gate/counter/return follow-up。來源是本次原生 disassembly。
- **部分確認**：IOCP received bytes→frame consumer→queue 與 K0 consumer 的*條件式鏈*；沒有跨所有 error/early return，也沒確保 runtime key 值與 app state。
- **未知**：`WSARecv`/`WSASend`/`ReadFile` 的具體提交位置、真正 socket handle 和 class type、完整原始 wire 到 decrypted buffer、queue 類別2何時生成、所有 actor motion handler 從 socket 的完整到達性、短按Z真正發包次數、原版 Server acceptance/cancel window。
- **否證**：此輪直接 E8 搜尋對 `0x807B40` 只命中 `0x806E08`，對 `0x807A70` 只命中 `0x80623A`（限定 `.text` byte scan，不排除間接 jump）；`0x1A68` 在本地輸出框架中為 marker，不是已證 app packet opcode。此前 `0x807B60` 稱呼應修正為 `0x807B40` entry。

## 5. 輪次與未解

**第1輪達標**：完整新追 `GetQueuedCompletionStatus` IAT→key/overlapped identity→native receive frame parser caller；有真實上游方向區分與分支返回值，以及另一個 output frame builder 直接 caller。這是相較 T10-108/109 新的核心資料流，屬共用 02 的重要增量，因此 `T10-110-2/110-3` 未啟動。這只代表本段 IOCP completion 主題有新閉環，不是原版普攻 network/motion FULL PASS。

**T10-111 候選**：從 `key+0xA030/+0xA050` 的 overlapped 發起者定位 `WSARecv/WSASend` 或 `ReadFile/WriteFile` exact IAT，追 socket handle、gate `[key+0xA0AC]` writer；同時追 queue `category2` producer、000A outbound actual send、S2C motion dispatcher to local/remote actor。若主要線索落 T02，引用／交接不改 T02。原版 Server 完全未建議用 fixture 代替。

## 6. 原生指令附錄（BIN 直接擷取；以下內容均以此作為可重現證據）


### IOCP worker entry and completion result — VA 0x00806cf0..0x00806e35, raw 0x004060f0..0x00406235

```asm
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
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
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f             	movzx  ecx,BYTE PTR [eax+0xb]
```


### Receive/other completion branches — VA 0x00806e7d..0x00806ee0, raw 0x0040627d..0x004062e0

```asm
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
  806edd:	8d 90 30       	lea    edx,[eax+0xa030]
```


### Receive parser entry — VA 0x00807b40..0x00807bd0, raw 0x00406f40..0x00406fd0

```asm
  807b40:	55                   	push   ebp
  807b41:	8b ec                	mov    ebp,esp
  807b43:	83 e4 f8             	and    esp,0xfffffff8
  807b46:	6a ff                	push   0xffffffff
  807b48:	68 be 98 90 00       	push   0x9098be
  807b4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807b53:	50                   	push   eax
  807b54:	51                   	push   ecx
  807b55:	b8 24 20 00 00       	mov    eax,0x2024
  807b5a:	e8 11 8b 0a 00       	call   0x8b0670
  807b5f:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b64:	33 c4                	xor    eax,esp
  807b66:	89 84 24 20 20 00 00 	mov    DWORD PTR [esp+0x2020],eax
  807b6d:	53                   	push   ebx
  807b6e:	56                   	push   esi
  807b6f:	57                   	push   edi
  807b70:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b75:	33 c4                	xor    eax,esp
  807b77:	50                   	push   eax
  807b78:	8d 84 24 38 20 00 00 	lea    eax,[esp+0x2038]
  807b7f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
```


### Outgoing pending-frame construction — VA 0x008061f0..0x00806270, raw 0x004055f0..0x00405670

```asm
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
  80626f:	8b               	mov    ecx,DWORD PTR [ebp-0x10]
```


### Outgoing frame header and bounds — VA 0x00807a70..0x00807b3e, raw 0x00406e70..0x00406f3e

```asm
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
  807b3b:	c2 08 00             	ret    0x8
```


### Receive parser queue producer bridge — VA 0x00807d7f..0x00807db5, raw 0x0040717f..0x004071b5

```asm
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
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
```