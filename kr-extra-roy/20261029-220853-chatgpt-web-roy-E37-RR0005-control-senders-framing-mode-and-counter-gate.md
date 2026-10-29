# E37 — RR-0005：key0／key2 控制訊息的原生 C2S 來源、0BBB 首包封裝與 F93934 gate 更正

**研究時間**：`2026-10-29T22:08:53+08:00`（Asia/Taipei）；研究者：`chatgpt-web roy`。
**客戶端**：KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次實際重算）；全程僅離線讀取，不執行／附加目標，也不改原件。
**位址**：PE `.text` 正式 VA、原始 `.text` raw=`VA-0x400C00`；其他 section 不套用此映射。匯入函式及指令識別以原件 `objdump` 驗證，`kr-bulk-roy` 反編譯僅作導航。

**GitHub 核對**：`main=e751b18922d205d86dea9f280cfd060f62752bc7`，`extra/roy1=4ab2accf76fe038b41cca1e2896586446903b3de`（包含 E32–E36 完整五份原稿）；本段截至開工仍為 `RR-0005/KR/T02/P0/PENDING/QUEUED`，claim/submission=null，無 T02 驗收退回的 `NEEDS_FIX/FIXING` 專區。已核對 `AGENTS.md`、T02 README/task.json 主責、派工規則／T02 inbox／RR index、T01 共用 FULL-PASS 索引，網路相關仍是有限研究，不屬 FULL-PASS。

**範圍**：依 E36 指定的「第一筆 outbound、key2 真正應用發送、stage/BF64/BF68」邊界，跨 `0x490FE0`、`0x4B8xxx`、`0x4957C0`、`0x805CA0`、`0x805F50`、`0x8061A0`、`0x807830` 等以原始 BIN 深化；不覆寫 E32–E36 原稿。

## 0. 本段相對 E36 的關鍵增量

1. **已確認 native local enqueue**：主循環有 **key0、2-byte payload `0x0010`** 路徑（`0x491C3A..0x491C9C`），條件為 `F93934<5`，`Client+BF68 != -1`、`FBA7AC !=0`、`BF68<=0x21`，且 `FBA798==0` 才實際呼叫 `virtual+0x10`。這與選服 `0x4957C0` 的 key0 57-byte `0x0001` 是**不同的 producer**。
2. **已確認 native local enqueue**：`0x4B8C8F..0x4B8CF8` 有 **key2、10-byte payload、第一 WORD `0x0BB9`**；後面四個 byte 源自 `F941C0`，再四個 byte 源自指標 `([esp+0x28] 指向的結構)+6`；限 `FBA798==0`。不能稱它「key2 第一個 wire」，但已填補 E36 的「沒有任何 key2 C2S 候選」缺口。
3. **已確認 native local enqueue**：同一大型函式 `0x4B8D3B..0x4B8D64` **key0、2-byte payload `0x00A0`**。隨後 `0x4B8D8A..0x4B8D95` 寫入 `FD8BFC=timeGetTime()`、`FD8C00=1`，打開 `0x490FE0` 一分鐘以上才可能 enqueue **key0、2-byte payload `0x00A7`** 的 timer gate。它們都是應用層 producer，不是 Server 內部規則。
4. **已確認正向選擇，有限**：新 `Conn` 在 `0x805D02` 被設定 `Conn+A02C=2`，`0x8061A0` 對 **非 0 的 A02C 先試 `0x807830` 的 `0x0BBB` 6-byte header**；成功直接跳過 `0x1A68`，失敗才進入 `0x807A70` plain 4-byte header。`0x805F50` pool reset 不直接寫 A02C。此證據將 E34 的「模式可能是 BBB 或 1A68」精化為 **新配置且 mode 未被間接改寫、ring 可用時優先 BBB**，但不能替代線上 pcap。
5. **重大表述更正**：E36 暫稱 `F93934` 為 `phase`，本段 `.text` little-endian exact-address scan 只找到 `0x4E15DA` 初始化零、`0x4947E3` **sub 1**、`0x491A76` 讀 gate；並且 `0x494780` 被註冊為某物件 `+0x398` 的 callback。**未見直接 increment/設5**。因此不能斷言 `>=5` 是成功進遊戲後的正常 `phase` 分支；暫稱 `F93934 signed gate/counter`。此為反證而非所有 possible indirect writers 的完備不存在證明。

## 1. Round 1：新 key0/key2 local sender 的位置、條件與順序

**問題**：E36 已證選服函式 local `0x0001` 僅 enqueue key0，但無法因此斷言 key0 第一個 wire 或 key2 無應用 payload。這輪從 `0x490FE0` 主循環、`0x4B8xxx` 其他 C2S 產生器追向共同 transport vtable `+0x10=0x8069A0`、queue helper `0x8060D0`，不假定 OS WSASend 線程順序。

### 1.1 C2S application producers（本輪新限定表）

| 程序位置 | transport key | payload LE16 起始 | 長度 byte | 成立前提 | 注意 |
|---|---:|---:|---:|---|---|
| `0x49593D`（E36） | 0 | `0x0001` | 57 | key0 & key2 Connect 同時成功，進入選服 success | 不是「first wire」已證 |
| `0x491C70..0x491C83` | 0 | `0x0010` | 2 | signed F93934<5 + BF68 countdown/timer + `FBA798==0` | 在選服成功後是否先 enqueue 未證 |
| `0x4B8D3B..0x4B8D62` | 0 | `0x00A0` | 2 | 該處函式實際走到、`FBA798==0` | 對應大函式此前還有其他 C2S |
| `0x49129D..0x4912C2` | 0 | `0x00A7` | 2 | `FD8C00 !=0`，timer 差 >=60,000，`FBA798==0` | `FD8C00` 於 4B8D95 開啟，但重連時會清零 |
| `0x4B8C8F..0x4B8CF8` | 2 | `0x0BB9` | 10 | 該函式走到、`FBA798==0` | 10B 的兩個後續 DWORD 來源已定位，但語意未知 |
| `0x6D64C0`（E33） | 1 | `0x0081` | 56 | mode1 key1 Connect 成功後 | 不等於登入協定所有可能的 first C2S |
| `0x49583x`（E32–E36） | 1 old | `0x007E` | 2 | 換服時 BF60 non-null | 進入 queue 不等於 send/ack |

**Native 指令觀察**：`0x490FE0` 包含兩個獨立 timer producer；`0x4B8xxx` 的 key2 0x0BB9 是首次查到的可見局部應用生產者，**不是**在 `0x4957C0` 內創造，更不能由此推定其實際執行必定晚於選服 success。多執行緒 + 發送佇列意味著本地產生先後不等同全域網路 first frame。

### 1.2 主循環：key0 的 0x0010 產生、BF68 讀寫與 FBA798 guard

`0x491C3A` 讀 `Client+BF68`；`0x491C4F` 比較 signed `0x21`；`0x491C59` 寫 `0xFA0`；`0x491C63` 寫本地 WORD `0x0010`；`0x491C68` 與 `0x491C70` 決定是否執行 virtual send；`0x491C7B..83` push `(length=2, src=stack, key=0)`；`0x491C85..0x491C8B` 另更新 timeGetTime 和 BF64。只有在指定分支才有 enqueue。

```asm
  491c3a:	8b 87 68 bf 00 00    	mov    eax,DWORD PTR [edi+0xbf68]
  491c40:	33 f6                	xor    esi,esi
  491c42:	83 f8 ff             	cmp    eax,0xffffffff
  491c45:	74 60                	je     0x491ca7
  491c47:	39 35 ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,esi
  491c4d:	74 58                	je     0x491ca7
  491c4f:	83 f8 21             	cmp    eax,0x21
  491c52:	7f 4a                	jg     0x491c9e
  491c54:	b8 10 00 00 00       	mov    eax,0x10
  491c59:	c7 87 68 bf 00 00 a0 	mov    DWORD PTR [edi+0xbf68],0xfa0
  491c60:	0f 00 00
  491c63:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  491c68:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  491c6e:	75 15                	jne    0x491c85
  491c70:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491c76:	8b 11                	mov    edx,DWORD PTR [ecx]
  491c78:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  491c7b:	6a 02                	push   0x2
  491c7d:	8d 44 24 18          	lea    eax,[esp+0x18]
  491c81:	50                   	push   eax
  491c82:	56                   	push   esi
  491c83:	ff d2                	call   edx
  491c85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  491c8b:	89 87 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],eax
  491c91:	e8 0a 2f f7 ff       	call   0x404ba0
  491c96:	ff 80 54 5f 00 00    	inc    DWORD PTR [eax+0x5f54]
  491c9c:	eb 09                	jmp    0x491ca7
  491c9e:	83 c0 df             	add    eax,0xffffffdf
  491ca1:	89 87 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],eax
  491ca7:	39         	cmp    DWORD PTR [edi+0xbfcc],esi
```

### 1.3 主循環：key0 的 0x00A7 / 60,000ms 時間門

`FD8C00==0` 直接跳過。若時間差 `timeGetTime-FD8BFC >= 0xEA60`，先把 WORD `0x00A7` 寫入 stack，僅在 `FBA798==0` 呼叫 `(key0, &payload, 2)`；不管這一 guard，仍寫 `FD8BFC=now`。這是 Client 定時控制 producer，並非官方 Server 必須以同樣 timer 計算的證據。

```asm
  49127b:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  491281:	39 35 00 8c fd 00    	cmp    DWORD PTR ds:0xfd8c00,esi
  491287:	74 46                	je     0x4912cf
  491289:	ff d3                	call   ebx
  49128b:	8b f8                	mov    edi,eax
  49128d:	8b d7                	mov    edx,edi
  49128f:	2b 15 fc 8b fd 00    	sub    edx,DWORD PTR ds:0xfd8bfc
  491295:	81 fa 60 ea 00 00    	cmp    edx,0xea60
  49129b:	72 2d                	jb     0x4912ca
  49129d:	b8 a7 00 00 00       	mov    eax,0xa7
  4912a2:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  4912a7:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  4912ad:	75 15                	jne    0x4912c4
  4912af:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4912b5:	8b 11                	mov    edx,DWORD PTR [ecx]
  4912b7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4912ba:	6a 02                	push   0x2
  4912bc:	8d 44 24 18          	lea    eax,[esp+0x18]
  4912c0:	50                   	push   eax
  4912c1:	56                   	push   esi
  4912c2:	ff d2                	call   edx
  4912c4:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4912ca:	bf 01 00 00 00       	mov    edi,0x1
  4912cf:	f6       	test   BYTE PTR ds:0xfc0fc0,0x1
```

### 1.4 key2：0x0BB9、10 bytes 的 payload writer（含兩個 DWORD 來源）

`0x4B8C8F` store WORD `0x0BB9`；`0x4B8CC6` 檢查 `FBA798==0`；`0x4B8CD1` `mov ecx,[F941C0]`；`0x4B8CD7` 取 `[edx+6]`；`0x4B8CDA/DE` 寫其後的兩個 DWORD；`0x4B8CEF..F8` 推入 `(0x0A, &stack payload, key2)` 呼叫 virtual+0x10。此為 native 確認的 local packet layout，無法命名欄位的正式業務意義。

```asm
  4b8c88:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8c8f:	b8 b9 0b 00 00       	mov    eax,0xbb9
  4b8c94:	66 89 44 24 1c       	mov    WORD PTR [esp+0x1c],ax
  4b8c99:	75 2b                	jne    0x4b8cc6
  4b8c9b:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8ca2:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x21
  4b8ca9:	21 00 00 00
  4b8cad:	e8 de 88 02 00       	call   0x4e1590
  4b8cb2:	68 80 cc bc 00       	push   0xbccc80
  4b8cb7:	e8 5e 96 3d 00       	call   0x89231a
  4b8cbc:	83 c4 04             	add    esp,0x4
  4b8cbf:	89 bc 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],edi
  4b8cc6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8ccd:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  4b8cd1:	8b 0d c0 41 f9 00    	mov    ecx,DWORD PTR ds:0xf941c0
  4b8cd7:	8b 42 06             	mov    eax,DWORD PTR [edx+0x6]
  4b8cda:	89 4c 24 1e          	mov    DWORD PTR [esp+0x1e],ecx
  4b8cde:	89 44 24 22          	mov    DWORD PTR [esp+0x22],eax
  4b8ce2:	75 16                	jne    0x4b8cfa
  4b8ce4:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8cea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8cec:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8cef:	6a 0a                	push   0xa
  4b8cf1:	8d 44 24 20          	lea    eax,[esp+0x20]
  4b8cf5:	50                   	push   eax
  4b8cf6:	6a 02                	push   0x2
  4b8cf8:	ff d2                	call   edx
  4b8cfa:	bb 01 00 00 00       	mov    ebx,0x1
  4b8cff:	84         	test   BYTE PTR ds:0xfb1378,bl
```

### 1.5 同一 sender 的 key0 0x00A0，以及啟用 0x00A7 timer

`0x4B8D3B` 寫 WORD 0x00A0；`0x4B8D4E..0x4B8D62` 以 `(key0, payload, 2)` 呼叫 virtual+0x10。`0x4B8D8A..0x4B8D95`：`FD8BFC=timeGetTime()`、`FD8C00=EBX`，而 `EBX=1` 的來源在 `0x4B8CFA`；此設計允許主循環開始計時送 0x00A7。

```asm
  4b8d31:	be 80 13 fb 00       	mov    esi,0xfb1380
  4b8d36:	e8 45 29 08 00       	call   0x53b680
  4b8d3b:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8d42:	b8 a0 00 00 00       	mov    eax,0xa0
  4b8d47:	66 89 44 24 28       	mov    WORD PTR [esp+0x28],ax
  4b8d4c:	75 16                	jne    0x4b8d64
  4b8d4e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8d54:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8d56:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8d59:	6a 02                	push   0x2
  4b8d5b:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  4b8d5f:	50                   	push   eax
  4b8d60:	6a 00                	push   0x0
  4b8d62:	ff d2                	call   edx
  4b8d64:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4b8d6b:	75 1d                	jne    0x4b8d8a
  4b8d6d:	09 1d f8 8b fd 00    	or     DWORD PTR ds:0xfd8bf8,ebx
  4b8d73:	68 10 e3 bc 00       	push   0xbce310
  4b8d78:	c7 05 fc 8b fd 00 00 	mov    DWORD PTR ds:0xfd8bfc,0x0
  4b8d7f:	00 00 00
  4b8d82:	e8 93 95 3d 00       	call   0x89231a
  4b8d87:	83 c4 04             	add    esp,0x4
  4b8d8a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  4b8d90:	a3 fc 8b fd 00       	mov    ds:0xfd8bfc,eax
  4b8d95:	89 1d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,ebx
  4b8d9b:	33                 	xor    eax,eax
```

### 1.6 key0 0x00A0 呼叫者的 EBX=1 與其他 key0 控制 producer

`0x4B8CFA mov ebx,1`，後續沒有改 EBX 的直接指令（所展示範圍）；注意函式內多處 virtual send 還會用 caller-saved registers，實際參數已在各 call 前以 push 確認。

```asm
  4b8cfa:	bb 01 00 00 00       	mov    ebx,0x1
  4b8cff:	84 1d 78 13 fb 00    	test   BYTE PTR ds:0xfb1378,bl
  4b8d05:	75 2a                	jne    0x4b8d31
  4b8d07:	09 1d 78 13 fb 00    	or     DWORD PTR ds:0xfb1378,ebx
  4b8d0d:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x22
  4b8d14:	22 00 00 00
  4b8d18:	e8 03 0f 08 00       	call   0x539c20
  4b8d1d:	68 b0 cf bc 00       	push   0xbccfb0
  4b8d22:	e8 f3 95 3d 00       	call   0x89231a
  4b8d27:	83 c4 04             	add    esp,0x4
  4b8d2a:	89 bc 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],edi
  4b8d31:	be 80 13 fb 00       	mov    esi,0xfb1380
  4b8d36:	e8 45 29 08 00       	call   0x53b680
  4b8d3b:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8d42:	b8 a0 00 00 00       	mov    eax,0xa0
  4b8d47:	66 89 44 24 28       	mov    WORD PTR [esp+0x28],ax
  4b8d4c:	75 16                	jne    0x4b8d64
  4b8d4e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8d54:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8d56:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8d59:	6a 02                	push   0x2
  4b8d5b:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  4b8d5f:	50                   	push   eax
  4b8d60:	6a 00                	push   0x0
  4b8d62:	ff d2                	call   edx
  4b8d64:	f6       	test   BYTE PTR ds:0xfd8bf8,0x1
```

### 1.7 選服原稿：key0 57-byte producer、key2 post-recv 與 slot writes

E36 已確認的成功路径摘錄，只用來在本段將多 producer 與選服關聯：它在 key0 queue 後 post WSARecv key0/key2，末尾寫 BF64/BF68。

```asm
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00         	mov    eax,0x1
```

### 1.8 Round 1 狀態及不可拼接的缺口

- 第一輪本身已得到兩條新 local sender（key2 0x0BB9／key0 0x00A0），達到**重大新發現**門檻；為避免「首 wire」誤認並核對意外覆寫／模式，本段另外做 Round2/3。
- `0x4B8xxx` sender 的上游 handler/caller 仍需定位；本段只說「該指令路徑執行時會 enqueue」，**不聲稱 key2 第一筆回覆應是何物**。
- 對 `0x0010`、`0x00A7`、`0x00A0` 等 local command，沒有官方 opcode 命名證據，暫用 numeric ID；它們的固定 port/service owner 須另由 connection map/pcap 驗證。

## 2. Round 2：key0/key1/key2 初次本地 framing 的模式優先順序

**問題**：E34 對 `0x0BBB`/`0x1A68` 都保留可能；然而對**新 Conn** 能否收窄預設選擇？同時要分開「local payload → ring → WSASend post → IOCP completion → Server actual receive」各層，不以某個層次代表整條 wire。

### 2.1 狀態完整性校驗：A02C direct-displacement occurrences

在原始 `.text raw[0x400,0x7D0600)` 搜 little-endian `0x0000A02C`，只找到：

```text
0x00805D04
0x00806205
```

前者在 `0x805D02` 為 `mov byte ptr [esi+0xA02C],2`，後者在 `0x806202` 為 `movsx eax,byte ptr [esi+0xA02C]`。這是對**該 imm32 displacement pattern** 的完整 scan，不排除基址經加法、`memcpy`、其他二進位模組、動態函式參數／pointer alias 改寫，更不能用來聲稱無 runtime 加密切換。

### 2.2 Conn 新配置直接初始化 mode=2

新 Conn 建構 `0x805CA0`：先配置／初始化接收 ring，接著在 `0x805D02` 寫入 mode=2。從 `0x805950` 無既有 pool 物件時會 `malloc(0xA0D8)` → 此函式。

```asm
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
```

### 2.3 發送工作路徑依 A02C 選擇 BBB 然後回退 plain

`0x8061A0` 從 queue 抓 `payload length`，`0x806202` 讀 mode。**只有 mode==0** 在 `0x806218 je 0x80622F` 直接略過 BBB；非 0 先 call `0x807830`，`test eax,eax`，成功跳 `0x80624F`，失敗才走 `0x807A70`。這證明**優先序，不是全域恆定 wire mode**。

```asm
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
```

### 2.4 BBB writer：長度／輸出 ring guard、固定標記 0BBB、XOR 加總

`0x807870` 對 stack 填入 length/marker `0x0BBB`；校驗 `payload+6<=0x1000`、`payload!=0`、`ringUsage + framedBytes<=0x4000` 及 ring pointer 在界內。正常路徑 `0x8078FD..0x80790D` 對第一 BYTE 做 `^0xB6`，後續 XOR／累加，不能將 `0x7D81` 的高 WORD 直接當作獨立 wire marker。

```asm
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
  807923:	83               	cmp    edx,0x2
```

### 2.5 BBB writer：prefix/checksum 寫入與成功／失敗 return

`0x8079F6` 寫 `[ringWriter]` 4-byte prefix（LE16 payload length + `0x0BBB`），`0x8079F8` 寫 checksum word；再 copy encoded data、增加 ring used、移動 ring write pointer；成功 EAX=1。否則 fallback EAX=0。CRC/checksum 的具體公式涉及 byte loop，不可僅憑一般字詞套用標準 CRC。

```asm
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
  807a6c:	c2               	ret    0x8
```

### 2.6 平文 fallback writer：0x1A68 與 return

當 mode==0 或 `0x807830` 返回0，`0x807A70` 於 capacity/length 合法時寫 LE16(len)、LE16(0x1A68)、後接原 payload，成功返回1；失敗返回0。注意 E34 先前的 ring size limit 與成功條件。

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
```

### 2.7 pool 重用 helper：沒有重設 A02C 的局部區段

`0x805F50` 會 reset SOCKET=-1、Conn+A0B0/發送計數/隊列資料等，但在此 helper 沒有直寫 `A02C`。對直接復用原 Conn 而言，mode 由之前連線保留的可能性不能排除。

```asm
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
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86        	mov    DWORD PTR [esi+0xa0c0],eax
```

### 2.8 對已知 payload 的本地 framed-size 推論（非封包實測）

| 原生 local payload | payload bytes | 若 BBB 成功（payload+6） | 若回退 plain 成功（payload+4） |
|---|---:|---:|---:|
| key0 選服 `0x0001` | 57 | 63 | 61 |
| key1 `0x0081` | 56 | 62 | 60 |
| key1 old `0x007E` | 2 | 8 | 6 |
| key0 `0x0010` | 2 | 8 | 6 |
| key0 `0x00A0` | 2 | 8 | 6 |
| key0 `0x00A7` | 2 | 8 | 6 |
| key2 `0x0BB9` | 10 | 16 | 14 |

以上只在單次成功 framing 且沒有其他 local coalescing/queue fallback 時成立。**無 pcap/WSASend args 實測就不能聲稱整條第一個 wire 的內容／長度；更不能說 Server 回覆已還原**。

Round2 判定：已取得「新 Conn mode 初始化 → queue writer mode branch → BBB success/fallback → ring」的可核對有界功能鏈，深化了 E34 的參數模型。

## 3. Round 3：F93934 counter gate、R/R 修正及網路控制路徑限制

**問題**：E36 對 BF64/BF68 的用途隨「phase」而異，但 `F93934` 真正的 writer 是否支援 phase 0→5 的說法？如果沒有，如何安全解讀 key0 heartbeat 和 all-key `shutdown`？

### 3.1 原件地址定位與分類

在 `.text raw[0x400,0x7D0600)` 搜 `LE32(0x00F93934)`，結果：

```text
0x00491A78
0x004947E5
0x004E15DC
```

這三個 immediate 使用者分別是 `0x491A76` 的 signed compare gate、`0x4947E3` 的 `sub [global],1` 以及 `0x4E15DA` 的 zero initializer。此 **static direct-address negative result** 並不涵蓋透過 `&F93930 + 4`、暫存器間接定位、其他 module 或 IAT 等機制更動，不可把「未發現」寫成全程不可達。

### 3.2 原生全域初始化：F93934=0

`0x4E1590` 構造鄰近 F9392C/30/34/38...，其中 `0x4E15DA` 是直接 `mov [F93934],0`。

```asm
  4e15c4:	c7 05 e0 d9 f8 00 5c 	mov    DWORD PTR ds:0xf8d9e0,0xc0d15c
  4e15cb:	d1 c0 00
  4e15ce:	89 1d 2c 39 f9 00    	mov    DWORD PTR ds:0xf9392c,ebx
  4e15d4:	89 1d 30 39 f9 00    	mov    DWORD PTR ds:0xf93930,ebx
  4e15da:	89 1d 34 39 f9 00    	mov    DWORD PTR ds:0xf93934,ebx
  4e15e0:	89 1d 38 39 f9 00    	mov    DWORD PTR ds:0xf93938,ebx
  4e15e6:	89 1d 44 39 f9 00    	mov    DWORD PTR ds:0xf93944,ebx
```

### 3.3 將 callback `0x494780` 安裝到 object+0x398

`0x49319E` 為該 callback 的直接 imm32 常數引用。這是**函式指標安裝**證據，不等於已識別 callback 的所有呼叫者。不能直接把該 callback 稱作「登入成功事件」或伺服器階段 writer。

```asm
  49318c:	00 00                	add    BYTE PTR [eax],al
  49318e:	00 00                	add    BYTE PTR [eax],al
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
  4931b4:	ba           	mov    edx,0x4943b0
```

### 3.4 callback 執行時以 sub 1 更新 F93934

`0x4947E3` 的 `sub DWORD PTR [F93934],1` 對全域計數作減法，後續用 `timeGetTime()`/其他狀態計算並更新 Client+BF74。沒有從此函式看到 `add 1`、`mov 5` 等操作。不能把此 sub 證成時間或 Server 登入狀態。

```asm
  4947ae:	bb 01 00 00 00       	mov    ebx,0x1
  4947b3:	84 1d 90 43 f9 00    	test   BYTE PTR ds:0xf94390,bl
  4947b9:	75 28                	jne    0x4947e3
  4947bb:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  4947c1:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4947c8:	00
  4947c9:	e8 c2 cd 04 00       	call   0x4e1590
  4947ce:	68 80 cc bc 00       	push   0xbccc80
  4947d3:	e8 42 db 3f 00       	call   0x89231a
  4947d8:	83 c4 04             	add    esp,0x4
  4947db:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4947e2:	ff
  4947e3:	29 1d 34 39 f9 00    	sub    DWORD PTR ds:0xf93934,ebx
  4947e9:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  4947ef:	ff d3                	call   ebx
  4947f1:	2b 86 6c bf 00 00    	sub    eax,DWORD PTR [esi+0xbf6c]
  4947f7:	d1 e8                	shr    eax,1
  4947f9:	3d d0 07 00 00       	cmp    eax,0x7d0
  4947fe:	76 1a                	jbe    0x49481a
  494800:	b8 05 40 00 80       	mov    eax,0x80004005
  494805:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  494809:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  494810:	59                   	pop    ecx
  494811:	5f                   	pop    edi
  494812:	5e                   	pop    esi
  494813:	5b                   	pop    ebx
  494814:	8b e5                	mov    esp,ebp
  494816:	5d                   	pop    ebp
  494817:	c2 0c 00             	ret    0xc
  49481a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  49481d:	89 86 74 bf 00 00    	mov    DWORD PTR [esi+0xbf74],eax
  494823:	8b               	mov    esi,DWORD PTR [ecx+0x2]
```

### 3.5 F93934 >=5 的 all-key SD_SEND 與 <5 的 BF68 countdown 分支

`0x491A76 cmp [F93934],5; jl 0x491C3A`；若不跳，連續呼叫 transport vtable+0x20 對 0、1、2 做 `shutdown(SD_SEND)`，然後進入錯誤／結束流程。無法藉此聲稱「遊戲某階段正常切換時必定關三連線」。

```asm
  491a76:	83 3d 34 39 f9 00 05 	cmp    DWORD PTR ds:0xf93934,0x5
  491a7d:	0f 8c b7 01 00 00    	jl     0x491c3a
  491a83:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491a8a:	75 2f                	jne    0x491abb
  491a8c:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491a93:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xf
  491a9a:	0f 00 00 00
  491a9e:	e8 ed fa 04 00       	call   0x4e1590
  491aa3:	68 80 cc bc 00       	push   0xbccc80
  491aa8:	e8 6d 08 40 00       	call   0x89231a
  491aad:	83 c4 04             	add    esp,0x4
  491ab0:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491ab7:	ff ff ff ff
  491abb:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491ac1:	c7 05 38 39 f9 00 01 	mov    DWORD PTR ds:0xf93938,0x1
  491ac8:	00 00 00
  491acb:	8b 01                	mov    eax,DWORD PTR [ecx]
  491acd:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ad0:	6a 01                	push   0x1
  491ad2:	6a 00                	push   0x0
  491ad4:	ff d2                	call   edx
  491ad6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491adc:	8b 01                	mov    eax,DWORD PTR [ecx]
  491ade:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ae1:	6a 01                	push   0x1
  491ae3:	6a 01                	push   0x1
  491ae5:	ff d2                	call   edx
  491ae7:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491aed:	8b 01                	mov    eax,DWORD PTR [ecx]
  491aef:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491af2:	6a 01                	push   0x1
  491af4:	6a 02                	push   0x2
  491af6:	ff d2                	call   edx
  491af8:	8b f7                	mov    esi,edi
  491afa:	e8 a1 d2 24 00       	call   0x6deda0
  491aff:	68 00 59 c0 00       	push   0xc05900
  491b04:	e8 f7 c1 25 00       	call   0x6edd00
  491b09:	83 c4 04             	add    esp,0x4
  491b0c:	e8 bf 88 25        	call   0x6ea3d0
```

### 3.6 low gate 的 BF68 countdown／0x0010 sender（上下游驗證）

低 gate 分支把 BF68 視作 signed integer 計數，按 `0x21` 扣減或重設 `0xFA0`，條件成立時把 0x0010 控制訊息 enqueue key0，另更新 BF64 時間。E36 在選服成功把 BF64/BF68 寫成 Conn*。因此不能無條件將這兩個偏移套同一個型別／固定 phase；**實際相依寫入是否會衝突需要執行緒／情境證據**。

```asm
  491c3a:	8b 87 68 bf 00 00    	mov    eax,DWORD PTR [edi+0xbf68]
  491c40:	33 f6                	xor    esi,esi
  491c42:	83 f8 ff             	cmp    eax,0xffffffff
  491c45:	74 60                	je     0x491ca7
  491c47:	39 35 ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,esi
  491c4d:	74 58                	je     0x491ca7
  491c4f:	83 f8 21             	cmp    eax,0x21
  491c52:	7f 4a                	jg     0x491c9e
  491c54:	b8 10 00 00 00       	mov    eax,0x10
  491c59:	c7 87 68 bf 00 00 a0 	mov    DWORD PTR [edi+0xbf68],0xfa0
  491c60:	0f 00 00
  491c63:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  491c68:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  491c6e:	75 15                	jne    0x491c85
  491c70:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491c76:	8b 11                	mov    edx,DWORD PTR [ecx]
  491c78:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  491c7b:	6a 02                	push   0x2
  491c7d:	8d 44 24 18          	lea    eax,[esp+0x18]
  491c81:	50                   	push   eax
  491c82:	56                   	push   esi
  491c83:	ff d2                	call   edx
  491c85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  491c8b:	89 87 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],eax
  491c91:	e8 0a 2f f7 ff       	call   0x404ba0
  491c96:	ff 80 54 5f 00 00    	inc    DWORD PTR [eax+0x5f54]
  491c9c:	eb 09                	jmp    0x491ca7
  491c9e:	83 c0 df             	add    eax,0xffffffdf
  491ca1:	89 87 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],eax
  491ca7:	39 b7 cc bf 00     	cmp    DWORD PTR [edi+0xbfcc],esi
```

### 3.7 E36 措辭修正（append-only，不覆寫舊稿）

- 舊 E36 詞彙「`F93934 phase`」只具「conditional gate」機器碼佐證；本段降為 `signed gate/counter`。直接 initializer=0 + direct subtract=1 並未推出典型「階段依序遞增至5」行為。此為**修正界線**，不是可證定值序列。
- 舊 E36 的 `BF68` 低 gate timer 與選服成功 Conn* 分層屬真實地址的兩種存取，但**不能在不證時間相斥前直接推斷二者安全或互斥**。反之也不聲稱實際漏洞。
- `0x0010` 與 `0x00A7` 以及同函式 `0x00A0`、key2 `0x0BB9` 的出現，使「key0 唯一首筆本地 producer 是選服 `0x0001`」不成立；但**不等於它們一定先於 `0x0001`、或該報文一定發給遊戲伺服器**。
- `F93934>=5` all-key half-close 在原件有可達指令分支，但尚無證據表明 Client 於有效互動中自然達到 `>=5`。不把它推薦為 Server 正常流程設計依據。

## 4. 本段收斂、四類交接與後續 E38

**三輪門檻**：Round1 發現 key2 `0x0BB9` 和 key0 `0x00A0/0x0010/0x00A7` 的 local producers，屬新增 native 功能鏈；Round2 確認所有新 Conn 默認 A02C=2 的 BBB 優先 framing 與 plain fallback 條件；Round3 補上 F93934 直接 writer/callback 反證，修正「phase」表述；三輪都有原件指令，已達重大實質增量，本段 E37 結束。沒有推進其他 Task 的主責 business parser。

**Client 待逆向**：`0x4B8xxx` local sender 的入站 packet/callback 入口及時序；key2 `0x0BB9` 載荷後兩個 DWORD 業務語義、首次 S2C reply 與 UI；`F93934` 透過別名/參照可能的 writer；A02C indirect writer；`BF68` 兩用途的有效動態交錯；Conn key map/close 後的存活與 FD generations。

**Server 待開發**：僅用已證的 Client application payload、frame writer/reader 和容忍失敗順序建立相容介面測試；不宣告官方 Server 的 0x0010/0x00A0/0x00A7/0x0BB9 正式語意，不假設官方 port 20DF/20E0/20DE 即部署規格。

**跨功能待整合**：本段新 key2 packet 與 key0 控制 producer 可能影響 T03 選服後行為、T02 framing 的 CLM/SPEC 和測試契約；供 T01/S00 依新風險分流萃取有限主張，不自行升格 FULL-PASS 或更動 RR。與 E32–E36 分別保留原稿及 git blob。

**待遊玩驗證**：需要獲授權的實際 socket trace 來核對 `(key, session Conn*, SOCKET handle, payload, framed ring, WSASend post/completion, remote S2C packet)`；原 Client 在本段未執行。對 BF64/BF68 需記錄主循環 gate 與選服成功的相對時序，不能以靜態二進位推斷競態一定發生。

**E38 下一個具體主題**：從 `0x4B8xxx` sender 的 enclosing function/handler 逆查 key2 0x0BB9 上游、收包解析與 `FD8C00` 控制打開的真正事件；再把 incoming key2 首回覆與 local `0x0BB9` 構成閉合的定向因果鏈。若發現只是遊戲特定晚期功能而非登入後初發，應明確降級「選服首包」之關聯，不強行嫁接。

## 5. 可重現性／機器碼掃描策略

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x4B8C88 --stop-address=0x4B8D00 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x491C3A --stop-address=0x491CA8 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x8061E6 --stop-address=0x806251 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x807867 --stop-address=0x807A6D Tartaros.bin
```

Python direct-address scan proof (address locator, not an indirect-writer exhaustive proof):

```python
from pathlib import Path
import struct
b = Path('Tartaros.bin').read_bytes()
for v in (0xA02C, 0xF93934, 0xFD8C00):
    p=struct.pack('<I', v)
    start=0x400; hits=[]
    while (start := b.find(p,start,0x7D0600)) >= 0:
        hits.append(hex(start+0x400C00))
        start += 1
    print(hex(v), hits)
```

**GitHub／RR 權限**：本次沒有明確 Commit/Push 授權，E37 保留本地完整 Markdown，不修改 `main`、`extra/roy1`、RR、T01/S00 結論；檔案已有內容，但只有未來提交並遠端核對 blob 後才具有 Git SHA 證據。
