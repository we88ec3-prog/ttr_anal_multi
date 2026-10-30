# T10-113 — KR 出站 Pending Frame pump 的兩個更新 caller、virtual transport gate 與索引式 enqueue bridge

## 0. 範圍／版本／前置驗證

日期：20261028-205943 Asia/Taipei。研究依 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T10-INSTRUCTIONS.md`。KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。原生 BIN x86 PE `.text` VA 0x401000、raw 0x400，換算 `raw=VA-0x400C00`；`.rdata` VA 0xBD2000/raw 0x7D0600。所有下面 assembly 重新直接從 BIN 反組譯；不執行 Client、無真實封包抓取。與既有 T10-101～112 及其他 Task 隔離，研究記錄不更寫原稿；僅 `t10/roy/chatgpt-web` 提交，絕不推 main。

本段重要目標：T10-112 只建立 `0x8060D0→0x806060` 待送 list 與 `0x8061A0` pump，但不知 pump caller 及真正送出條件。本段確認實際 caller／virtual transport gate／上層 enqueue bridge，並嚴格標記未閉合的 vtable 分派。T10-111 的 `0x8068B0` 是 Winsock 送出 API 原生實作，不代表本段每個上游虛呼叫必然等於該函式。

## 1. 第一輪重大新 native 結果

### 1.1 `0x8061A0` 的兩個直接 caller（已確認）

對 `.text` raw `[0x400,0x7D0600)` 每個 byte 搜尋 `E8 rel32` target 0x8061A0，原始命中 `0x804AD6`、`0x805228`；各處再以 objdump 證實是指令邊界，並檢視 ECX/ESI 物件來源及返回值。不能以兩個 `E8` 斷言無間接 caller。

第一更新鏈 `0x804AC3..0x804B1A` 從 array 取 `ESI=connection`，`[esi+A0AC] !=0` 才執行 `push esi; call 8061A0`；回傳非零時更新 `+A094`，依 `+A0A4` 與常數 5 減少/清空累積狀態；回傳零且上層 flag 非零則 `+A084` 與 `+A0A4` 增量。這是 Client 本地節流／管理資料，不是遊戲技能冷卻時間。

第二更新鏈 `0x805215..0x80526C` 從另一 array 取 `ESI=connection`，同樣必須 `+A0AC !=0`，`push esi; call 8061A0`，返回非零時 `++[esi+A094]` 與減小/清空 `+A0A4`；失敗時依 caller+0x10 的旗標更新 `+A084`、`+A0A4 +=5`。兩條 caller 來源不同，不能假設同時在同一幀發生、或是收包 ack 的不同版本。

### 1.2 待送緩衝 → transport virtual+0xC（已確認）

第一 caller 在 `0x804B21` 檢查 `[esi+A028] !=0`，`0x804B2E` 檢查 `[esi+A0B8] <=0`；只有通過才準備：

```asm
804b3c mov eax,[esi+0xa028]    ; pending bytes/length
804b42 mov ecx,[0xfba854]      ; global transport interface
804b48 mov edx,[ecx]
804b4a mov edx,[edx+0xc]       ; slot +C
804b4d lea edi,[ebp-0x14]
804b50 push edi                ; caller result/output
804b51 push eax                ; pending length
804b52 lea eax,[esi+0x5020]
804b58 push eax                ; pending buffer
804b59 push esi                ; connection
804b5a call edx                ; virtual transport call
804b5c test eax,eax
```

第二 caller 在 `0x805273..0x8052D2` 重現同樣 gate：`[esi+A028] !=0`、`[esi+A0B8] <=0`、`ecx=[0xFBA854]`、`edx=[vptr+0xC]`，push `(result*, pendingLen, esi+0x5020, esi)`，`0x8052AC call edx`。這是**可驗證的真正交給 transport abstraction 的出站觸發點**，而不是 `0x8061A0` 自己直接呼叫 WSASend。注意 transport `virtual+C` 與 connection `0xC51748 virtual+C=0x8068B0` 是**不同物件的虛函式表**，尚未確認 FBA854 實際 vptr 是否採後者，也不可自行接為同一函式。

回傳0時第一 caller `0x804B60→0x8063E0`，後續 `virtual+0x24` callback，設 `[esi+A0A8]` 相關 gate；第二 caller `0x8052B2→0x8063E0`、另一個 `virtual+0x24` callback，設 `[esi+A0A8]=1`。當 `[esi+A0B8]>0` 即不進本次送出 gate，**不代表封包丟棄**；此前已組建 pending buffer 的清空/重試需另查。

### 1.3 `0x8069A0` 上游索引式 enqueue bridge（已確認，但 caller 待查）

`0x8069A0` 先由 `ECX+0x18` tree 及 stack+8 的 key 呼叫 `0x8438C0` 查找，並檢查返回 iterator 與 `ESI+0x1C` sentinel；缺 key / node+0x10 為0時直接 return0。若 stack+0x10（長度）為0，則 return1；非零時 `0x8069E6..0x8069EB` 將 stack+0xC 的 buffer pointer、stack+0x10 的 length push 給 `0x8060D0`。這提供「查得合法索引→入連線 Pending List」的**另一個原生邊界**，不是 000A opcode 已確認，更不能將 stack+8 key 當作 wire opcode。此函式 `ret 0xC`，必須先找到其所有 caller 才能定位具體 gameplay producer。

### 1.4 對真正 socket API 的接合等級

T10-111 已證 connection vtable `0xC51748+0xC=0x8068B0` (`WSASend`)，以及對應 `+0x14=0x806A00` (`WSARecv`)。本次重新從 `.rdata` 讀取連續 DWORD：`C51748=806670`, `C5174C=806CF0`, `C51750=806850`, `C51754=8068B0`, `C51758=8069A0`, `C5175C=806A00`, `C51760=806AD0`。這是 connection class 的表，而前述 caller `0x804B42/0x805294` 從全域 `[FBA854]` 取得 **transport interface** 類指標，所以必須查 FBA854 設定者和 virtual+0xC target，再確認其是否委派 connection vtable+C。**兩種 vptr 絕不直接混用**。

## 2. 資料流表

| 主題 | Native 已確認 | 未知／不應推論 |
|---|---|---|
| Pending List | 8060D0→806060 寫入 connection+A074，8061A0 按 mode 封裝至 +501C/+5020 | 排程是否每 tick flush、具體玩法封包是否已到 |
| 第一個 pump caller | 804AD6 的上游 array element 作 connection，A0AC gate，之後檢查 A028/A0B8 | 與第二 caller 是否同時觸發 |
| 第二個 pump caller | 805228 的上游 array element 作 connection，相同 gate，之後送 transport | 發生條件及 update thread 當下狀態 |
| socket 輸出交接 | FBA854 global 的 virtual+C，帶 connection/buffer/len/result* | 實際 virtual target、是否等於 WSASend wrapper |
| 索引式 producer | 8069A0 查 tree，非零 len 才 call 8060D0 | 哪個 sender 或 000A 產生此索引，真正 op header |
| wsasend native | 8068B0 的 IAT WSASend 已證，connection 表 +C 指向它 | 上述 FBA854 表是否直接或間接調用它 |

## 3. 玩家操作 × Client × C→S × S→C × 動作與分工

| 操作 | Client 已證 | C→S | S→C | 動作結果 | 證據／Server 待辦 |
|---|---|---|---|---|---|
| 短按 Z、Key44→ID13 成立 | T10-101～103 有 phase/bit0/SkillMatrix 下游；本輪找到一般 outgoing pump 的條件 | 000A 本地準備已證；**未連到 8069A0 或 FBA854 target**，不宣稱每次按鍵必送 | 尚無此操作對應回包完整資料流 | 動作何時起播 unknown | 需要 C2S sender 與 S2C motion event 因果 |
| 長按、連按、放開 | 已證 phase 型態，但本輪未辨送包次數 | unknown | unknown | 連段/取消 unknown | 不能補造時窗 |
| connection A028>0、A0B8<=0、A0AC!=0 | 可進 virtual transport+C | 有條件進傳送抽象層，不保證 OS socket success | 本段不處理收包 | 不是 gameplay ack | 具體實作 FBA854 vtable 待核 |
| connection A0B8>0 | 此 pump 送出 gate 不成立 | 不能判定已丟失或重送 | unknown | unknown | OS overlapped pending 與 drain 待追 |
| 索引 key 無 node 或 node+10==0 | 8069A0 不交給 8060D0 | 在此入口未發起 pending enqueue | unknown | none in this subchain | 其他 sender 未排除 |
| 非零 len 有效索引 | 8069A0 call 8060D0 | 僅代表本地佇列接收，尚非 WSASend 成功 | unknown | unknown | 需找此索引來源 |

## 4. 三輪研究深度與下一入口

本段第1輪取得兩個原生 pump caller + 實際 pending-buffer 虛擬 transport 送出 gate、回傳失敗分支，及 `0x8069A0` 查索引→入列的局部入口，構成此前尚缺的 transport-facing **實質資料流進展**；符合 `02` 共用重大新發現門檻，故本段 `T10-113-2/-3` 未啟動。**這不是玩法封包／動畫的 FULL PASS**。

T10-114 優先：靜態逆向 `[FBA854]` 的 writer/具體 vtable+C target，找 `0x8069A0` caller、`0x5452C0` 實際送包至 connection 的索引映射；閉合 `WSASend` 實際動態 ABI。其次確認 S2C key13 motion 是否適用本地/遠端 actor；不重述 socket 通用 helper。T02 socket 底層只引用接口，不變動其 Task owner/notes。

## 5. 原生組譯附件（此次重新自 BIN 擷取；包含重要前後分支）

### pending pump: VA 0x8061a0..0x80627c; raw 0x4055a0..0x40567c

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
  80627b:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```

### pump caller A: VA 0x804ac0..0x804b98; raw 0x403ec0..0x403f98

```asm
00804ac0 <.text+0x403ac0>:
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
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
  804b95:	89 9e a8       	mov    DWORD PTR [esi+0xa0a8],ebx
```

### pump caller B: VA 0x805210..0x8052d5; raw 0x404610..0x4046d5

```asm
00805210 <.text+0x404210>:
  805210:	eb 03                	jmp    0x805215
  805212:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805215:	8b 09                	mov    ecx,DWORD PTR [ecx]
  805217:	8b 34 b9             	mov    esi,DWORD PTR [ecx+edi*4]
  80521a:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  805221:	0f 84 85 01 00 00    	je     0x8053ac
  805227:	56                   	push   esi
  805228:	e8 73 0f 00 00       	call   0x8061a0
  80522d:	85 c0                	test   eax,eax
  80522f:	74 28                	je     0x805259
  805231:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805237:	ff 86 94 a0 00 00    	inc    DWORD PTR [esi+0xa094]
  80523d:	83 f8 05             	cmp    eax,0x5
  805240:	73 0c                	jae    0x80524e
  805242:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  805249:	00 00 00 
  80524c:	eb 1e                	jmp    0x80526c
  80524e:	83 c0 fb             	add    eax,0xfffffffb
  805251:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  805257:	eb 13                	jmp    0x80526c
  805259:	80 7b 10 00          	cmp    BYTE PTR [ebx+0x10],0x0
  80525d:	74 0d                	je     0x80526c
  80525f:	ff 86 84 a0 00 00    	inc    DWORD PTR [esi+0xa084]
  805265:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  80526c:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  805273:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  80527a:	0f 84 29 01 00 00    	je     0x8053a9
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
  8052d2:	83 be b0     	cmp    DWORD PTR [esi+0xa0b0],0x0
```

### connection dispatch bridge: VA 0x8069a0..0x8069f5; raw 0x405da0..0x405df5

```asm
008069a0 <.text+0x4059a0>:
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
  8069f3:	c2 0c              	ret    0xc
```

### enqueue contextual caller: VA 0x495817..0x49586a; raw 0x94c17..0x94c6a

```asm
00495817 <.text+0x94817>:
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86      	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:
```

### connection vtable constructor: VA 0x8066c6..0x8066e0; raw 0x405ac6..0x405ae0

```asm
008066c6 <.text+0x4056c6>:
  8066c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  8066c9:	c7 07 48 17 c5 00    	mov    DWORD PTR [edi],0xc51748
  8066cf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  8066d6:	8b 47 1c             	mov    eax,DWORD PTR [edi+0x1c]
  8066d9:	8b 30                	mov    esi,DWORD PTR [eax]
  8066db:	3b f0                	cmp    esi,eax
  8066dd:	0f 84 ed       	je     0x8067d0
```