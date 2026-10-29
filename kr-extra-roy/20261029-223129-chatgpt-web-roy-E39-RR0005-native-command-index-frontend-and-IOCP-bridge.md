# E39 — RR-0005：由 S2C command 參數進入 dense callback table 的確切原生 ABI、Client 兩層轉送與 IOCP frame/queue 分界

**研究者**：chatgpt-web roy；**研究時間**：`2026-10-29T22:31:29+08:00`（Asia/Taipei）。  
**任務**：KR / T02 / RR-0005 / P0；接續 E38。**狀態**：按照上次已讀 `main=e751b18922d205d86dea9f280cfd060f62752bc7` 的 RR 台帳 `PENDING/QUEUED`、claim=null；本次使用者明確要求更新共享 AGENTS 與繼續研究，**沒有要求把 E39 原稿 Commit／Push、沒有要求正式認領**。  
**Git 修改**：正式文件名是 `AGENTS.md`（不是 `AGENT.md`），本次已更新 `main`；commit `217a0358fceceb03a5cb02cd19d401206364bead`。變更內容為「只在新 ChatGPT 對話第一次作全面 GitHub 啟動讀取，續段沿用上下文；明確 Git 任務、未讀原生來源、競爭或提交前 SHA 核驗除外」。本研究沿用舊的 RR snapshot，不能冒稱更新前後 main RR 狀態完全相同。

**原始證據**：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次實際重算）；PE32 x86 `.text raw=VA-0x400C00`，`.rdata raw=VA-0x401A00`（原件 `objdump -h`）。只對 BIN 離線靜態反組譯，沒有執行原版遊戲、附加程序、網路封包擷取，也不使用原版 Server 源碼。既有 E32–E38 的未證命題不在本段偷偷升級驗證等級。

**本段具體問題**：E38 已證 `0x4B7DC0` 初始化 stride8 callback table（index2→0x4B7F00、index0xBD2→0x4B8DC0），但未證實 command index 來源。E39 從 **table virtual dispatch `0x4FDA30`、Client callback forwarding `0x494360`、Client 入口 `0x4930E0`、IOCP frame parser `0x807B40`** 逐層核對，區分三種「index」和兩條不同的 table，避免把同數值的 offset 誤用。

## 結論摘要（主張等級限定）

| 代號 | 本輪發現 | 等級／完整性 |
|---|---|---|
| E39-C01 | `0x4FDA30` 確實從第三個 stack 參數讀 **signed 16-bit command**，用 `base+8*command+4` 取 callback 並間接呼叫；`0x4B7DC0` 正建立此 table 於 `FD2CF8` | **已確認：table dispatch ABI** |
| E39-C02 | table 的 index 2 直接對 `0x4B7F00`；index0xBD2 對 `0x4B8DC0`，不再只是「函式指標在 index2」，而是 **當上游傳入 command=2/0xBD2 且用該 table dispatch 時會選該 handler** | **已確認：有條件 dispatch** |
| E39-C03 | `0x494360` 透過已知 singleton FD2CF8 的 vtable+4 尾跳轉，故在目前 `C06EB4` vptr 完整設定下會進入 `0x4FDA30` | **已確認：一層轉送** |
| E39-C04 | `0x493170` 另建**不同**的 Client callback 表（3029 項 stride0x10，從 `client+0x208`），其中一些 index 會指向 `0x494360`，而別的 index 指向 `0x4943B0` | **已確認：不同 table，勿混用** |
| E39-C05 | `0x4930E0` 的 inbound-like 門檻從 `param2` 讀 16-bit command，`param4==2` 才呼叫 `Client+0xB8` 物件的 virtual+4 | **已確認：一個獨立的上游 delegate；尚未證與 FD2CF8 唯一路徑相連** |
| E39-C06 | `0x807B40` 完成 frame 判定/解碼後用 `0x807E50` 先複製 payload 到內部 packet queue；不在此一段直接呼叫 `0x4FDA30` | **已確認：IOCP 收包與應用 handler 有隊列邊界** |
| E39-C07 | 尚未發現從具體 SOCKET key→queue 消費者→`0x4930E0`/`0x494360` → FD2CF8 的**完全閉合路徑** | **Client 待逆向；不得稱 first S2C wire 及 Server 必須即時回 0xBD2** |

**本段主要突破**：先前的「表索引」可提升為真正的 **command-indexed table ABI**；但是不能在缺少 queue consumer + 具體 transport key 的鏈路時把它直接等價成全網路 S2C opcode。這個分級更精確，既可支援相容 Server 的 bounded 設計，又避免作過強推論。

## Round 1 — 從真正的 virtual table lookup 核對 command-index ABI

### 1.1 .rdata vtable 和 .data table 層次

原始 BIN 的 `.rdata` 正確 VA→raw 映射為 `VA-0x401A00`，不要把 `.text VA-0x400C00` 用在資料段，也不要錯偏移 0x1000。原件讀取 `C06EB4` 的前四個 DWORD 為：

```text
0xc06eb4 0x4c5940
0xc06eb8 0x4fda30
0xc06ebc 0x422810
0xc06ec0 0x4227f0
``` 

主線歷史初始化 `0x489CC3`、`0x4C2FA7` 把 vptr `0xC06EB4` 寫到 `FD2CF8`，`0x4B7DC0` 初始化 callback array 由 `FD2CFC` 開始，每 entry 8 bytes；vtable+4 是 `0x4FDA30`。callback 函式被呼叫時使用的 `ECX` 是 FD2CF8 singleton 物件起點，不是 `FD2CFC` 元素位址。

嚴格 layout：

```text
FD2CF8: vptr = C06EB4 -> [0]=4C5940, [+4]=4FDA30
FD2CFC:  handler[0] pointer = 4B7EC0
FD2D00:  handler[0] aux = BF2375
FD2D04:  handler[1] pointer = 4B7EC0
FD2D08:  handler[1] aux = BF2375
FD2D0C:  handler[2] pointer = 4B7F00
FD2D10:  handler[2] aux = BF2375
...
FD8B8C:  handler[0x0BD2] pointer = 4B8DC0
FD8B90:  handler[0x0BD2] aux = BF2375
```

注意 `0x4FDA30` 的索引方式是 `[ECX+EDI*8+4]`，ECX 指 FD2CF8；因此 index0 正好 FD2CFC，**不是** `FD2CF8+index*8` 的 vptr。這一點比 E38 的地址推論多出真正的消費證據。

### 1.2 完整 command → callback target / missing-target fallback

最關鍵原生指令：`0x4FDA37 mov ecx,[ebp+0x10]`，`0x4FDA3B movsx edi,cx`，`0x4FDA3E mov eax,[esi+edi*8+4]`。非零則在 `0x4FDA8A call [ebp-4]` 傳入原本三個 stack args；零則走 `vtable+0x0C` default。**第三個參數是 16-bit 有號索引**，不是 unsigned 32-bit 整數。此函式自身沒有明顯 0..0xBD4 範圍檢查；是否有上游校驗是另一個問題，不據此聲稱存在可用漏洞。

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
```

### 1.3 Table constructor: 3029 slots + known overrides

原件 `0x4B7DD0` 把 fallback 寫 `[eax-4]`，`0x4B7DD3` 把 metadata 寫 `[eax]`，每次 `add eax,8`，以 `0xFD8BA8` 為迴圈界；總共 `0xBD5=3029` 個 slots。`0x4B7DDF`、`0x4B7DEF` 直接覆寫表 index2、index0xBD2。還有其他覆寫，不能當成只有兩種命令。

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7 05 e4 31 fd 00 60 	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	9c 4b 00 
  4b7e79:	89 0d e8 31 fd 00    	mov    DWORD PTR ds:0xfd31e8,ecx
  4b7e7f:	c7 05 d4 34 fd 00 30 	mov    DWORD PTR ds:0xfd34d4,0x4b9d30
  4b7e86:	9d 4b 00 
  4b7e89:	89 0d d8 34 fd 00    	mov    DWORD PTR ds:0xfd34d8,ecx
  4b7e8f:	c7 05 24 2d fd 00 30 	mov    DWORD PTR ds:0xfd2d24,0x4b9630
  4b7e96:	96 4b 00 
  4b7e99:	89 0d 28 2d fd 00    	mov    DWORD PTR ds:0xfd2d28,ecx
  4b7e9f:	c7 05 0c 2e fd 00 70 	mov    DWORD PTR ds:0xfd2e0c,0x4b9770
  4b7ea6:	97 4b 00 
  4b7ea9:	89 0d 10 2e fd 00    	mov    DWORD PTR ds:0xfd2e10,ecx
  4b7eaf:	c7 05 f4 2f fd 00 c0 	mov    DWORD PTR ds:0xfd2ff4,0x4b99c0
  4b7eb6:	99 4b 00 
  4b7eb9:	89 0d f8 2f fd 00    	mov    DWORD PTR ds:0xfd2ff8,ecx
  4b7ebf:	c3                   	ret
```

### 1.4 限定的 dispatch 公式

```cpp
// 0x4FDA30; 客戶端本地 callback table，不預設這裡已證 Client 全部 network path
HRESULT Dispatch(void* buffer, int length, short command) {
    auto index = (int16_t)command; // movsx edi,cx
    Callback* f = table[index].function; // [FD2CF8 + index*8 + 4]
    if (!f) return virtual_fallback(buffer, length, command);
    return f(buffer, length, command);  // actual callback ABI inferred from push at 4FDA79..88
}
```

符合 command=2 時可落在 handler `0x4B7F00`，符合 command=0x0BD2 時可落在 `0x4B8DC0`。但 **0x4B7F00 裡的 0BB9 是 C2S 結果，不是 opcode 的自動回覆型別識別**。對 `index>=0x8000` signed conversion 可能變負，屬缺前置 bounds proof 的一項限制，沒有外部可控性證據。

**Round 1 已重大達標**：本輪已從消費者證明 table 實際以 signed command 取 callback，而非只有 static writer；依共享規則可結束，因 user 要求完整大批次，本段再做兩輪不同面向上下游驗證。

## Round 2 — Client callback table 和 FD2CF8 handler table 是不同兩層

### 2.1 Callback routing `0x494360` 實際叫的是誰

### 2.2 0x494360 取得 FD2CF8 vptr+4，保留 packet 三參數

`0x49439C` 產生 `ECX=0xFD2CF8`，`0x4943A1` 讀 `vptr`，`0x4943A6` 取 vtable+4，`0x4943AA jmp edx`。vptr 在 `0x489CB0/0x4C2F90` lazy initialization 時設定 `0xC06EB4`，即 `[C06EB8]=0x4FDA30`。原生 `0x494360` 本身不覆寫傳入的三個 stack 參數，以 tail jump 保留 command index。

```asm
  494360:	55                   	push   ebp
  494361:	8b ec                	mov    ebp,esp
  494363:	b8 01 00 00 00       	mov    eax,0x1
  494368:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  49436e:	75 2c                	jne    0x49439c
  494370:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  494376:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  49437d:	6e c0 00 
  494380:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  494387:	00 00 00 
  49438a:	e8 31 3a 02 00       	call   0x4b7dc0
  49438f:	68 f0 dc bc 00       	push   0xbcdcf0
  494394:	e8 81 df 3f 00       	call   0x89231a
  494399:	83 c4 04             	add    esp,0x4
  49439c:	b9 f8 2c fd 00       	mov    ecx,0xfd2cf8
  4943a1:	a1 f8 2c fd 00       	mov    eax,ds:0xfd2cf8
  4943a6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4943a9:	5d                   	pop    ebp
  4943aa:	ff e2                	jmp    edx
```

### 2.3 Client callback table：3029 stride16 entries, generic handler pointer

`0x493170` 收到 EAX object base，用 `EDX=EAX+0x210` 開始向 `[EDX-8]` 寫 `0x494360`、`[EDX-4]` 零、`[EDX]` 常數 `0xBF2375`，每個 entry 步幅 `0x10`，總數 `ESI=0xBD5`（3029）。之後特殊 slot 改寫 0x494780 / 0x4943B0 等。這個 **Client object callback table 與 `FD2CF8+4+8*index` 是不同表**；前者 stride16 且受其他 callback 覆寫，後者 stride8 且只有其自己的 metadata。

```asm
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
  4931cf:	89         	mov    DWORD PTR [eax+0x438],edx
```

### 2.4 另一個 Client callback entry +0x14A8 = 0x494360

`0x494088` 對 `eax+0x14A8` 放 `0x494360`，這是在 Client table index `(0x14A8-0x208)/0x10=0x12A` 的位置（若同一完整 entry-base）。**index0x12A 是外層 Client callback index，不等於內層 FD2CF8 index0x0002。** 不可拿這個例子說 S2C 0x12A 即為 0x0002 的 wire alias。

```asm
  49406f:	00 00                	add    BYTE PTR [eax],al
  494071:	ba b0 43 49 00       	mov    edx,0x4943b0
  494076:	89 90 48 14 00 00    	mov    DWORD PTR [eax+0x1448],edx
  49407c:	89 b0 4c 14 00 00    	mov    DWORD PTR [eax+0x144c],esi
  494082:	89 88 50 14 00 00    	mov    DWORD PTR [eax+0x1450],ecx
  494088:	ba 60 43 49 00       	mov    edx,0x494360
  49408d:	89 90 a8 14 00 00    	mov    DWORD PTR [eax+0x14a8],edx
  494093:	89 b0 ac 14 00 00    	mov    DWORD PTR [eax+0x14ac],esi
  494099:	89 88 b0 14 00 00    	mov    DWORD PTR [eax+0x14b0],ecx
  49409f:	ba           	mov    edx,0x4943b0
```

### 2.5 0x4943B0 的其他 default-callback 轉送，非 FD2CF8

`0x4943B0` 會先檢查並初始化 `F94390` 對應的全域狀態，再從 `F8D9E0` 實例取得 vtable+4 轉送。雖然與 `0x494360` 具有相同三參數 callback 形狀，**這個 default path 不是 FD2CF8**；因此 Client table 中不是所有 cmd 都導向 `0x4FDA30`。

```asm
  4943b0:	55                   	push   ebp
  4943b1:	8b ec                	mov    ebp,esp
  4943b3:	83 e4 f8             	and    esp,0xfffffff8
  4943b6:	6a ff                	push   0xffffffff
  4943b8:	68 0e f8 93 00       	push   0x93f80e
  4943bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4943c3:	50                   	push   eax
  4943c4:	51                   	push   ecx
  4943c5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4943ca:	33 c4                	xor    eax,esp
  4943cc:	50                   	push   eax
  4943cd:	8d 44 24 08          	lea    eax,[esp+0x8]
  4943d1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4943d7:	b8 01 00 00 00       	mov    eax,0x1
  4943dc:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4943e2:	75 28                	jne    0x49440c
  4943e4:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4943ea:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4943f1:	00 
  4943f2:	e8 99 d1 04 00       	call   0x4e1590
  4943f7:	68 80 cc bc 00       	push   0xbccc80
  4943fc:	e8 19 df 3f 00       	call   0x89231a
  494401:	83 c4 04             	add    esp,0x4
  494404:	c7 44 24 10 ff ff ff 	mov    DWORD PTR [esp+0x10],0xffffffff
  49440b:	ff 
  49440c:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  49440f:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  494412:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  494415:	50                   	push   eax
  494416:	a1 e0 d9 f8 00       	mov    eax,ds:0xf8d9e0
  49441b:	51                   	push   ecx
  49441c:	52                   	push   edx
  49441d:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  494420:	b9 e0 d9 f8 00       	mov    ecx,0xf8d9e0
  494425:	ff d2                	call   edx
  494427:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  49442b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  494432:	59                   	pop    ecx
  494433:	8b e5                	mov    esp,ebp
  494435:	5d                   	pop    ebp
  494436:	c2 0c 00             	ret    0xc
  494439:	cc                   	int3
```

### 2.6 `Client+0xB8` inbound-like 方法：已證 command 來源與 gate

這個入口 `0x4930E0` 能直接從 `param2` buffer 讀第一個 WORD，但它呼叫的是 `Client+B8` 成員之 vtable+4，而非直接 `FD2CF8`；我們不能把這兩者直接合一。其具體條件：

- `[ebp+0xC]` 指向 buffer，`0x4930ED movzx edi,word [eax]` 提取 command；
- `[ebp+0x10]` 非 0 才進一步處理；
- `[ebp+0x14] == 2` 才走 `Client+B8` vtable+4（其餘路徑回傳 0）；
- 虛呼叫前依序壓入從 buffer 取得的命令與其他參數。回傳值與 `0x100` 比較，並附加 `Client+BE8C` 非零 gate。這條是**可能的前端命令路由**，但成員 `Client+B8` 的實際 vptr +4 對象及它與 `0x494360` 的連接尚需原件證據。

### 2.7 Inbound-like Client virtual 0x4930E0：buffer WORD / 2-byte gate / delegate

這個函式在可見正常路徑先讀 `WORD [param2]`，然後要求 param3 non-null、param4等於2。它通過 `Client+B8` 的虛函式表 slot+4 對未知 delegate 分派；與 `0x494360` 的 singleton FD2CF8 不是一個已直接證明的 same-object address。

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

### 2.8 誰安裝這個 Client 表？

`0x48C02A` 在物件成功建立分支呼叫 `0x493170`，把上述 callback registry 裝在物件 `(EBX-8)`；因此不只是一段孤立無 caller 的表填充。另已在 `.rdata` 找到 `0x4930E0` function ptr，位於 `0xC05AEC`，是具體 vtable slot，不是無法被呼叫的裸函式。函式指標被配置≠已證 packet source socket；不推論運行時必定走到此分支。

### 2.9 實際 Client callback 建構 callsite：0x48C02A

`0x48C027 lea eax,[ebx-8]`，`0x48C02A call 0x493170`；驗證表建構的 native 使用者，而不是憑地址附近推論。

```asm
  48bff0:	68 c8 56 c0 00       	push   0xc056c8
  48bff5:	8b d3                	mov    edx,ebx
  48bff7:	e8 04 2d 25 00       	call   0x6ded00
  48bffc:	83 c4 04             	add    esp,0x4
  48bfff:	b8 05 40 00 80       	mov    eax,0x80004005
  48c004:	e9 3b 01 00 00       	jmp    0x48c144
  48c009:	8b 83 78 bf 00 00    	mov    eax,DWORD PTR [ebx+0xbf78]
  48c00f:	68 28 5b c0 00       	push   0xc05b28
  48c014:	68 f0 56 c0 00       	push   0xc056f0
  48c019:	50                   	push   eax
  48c01a:	68 fc 56 c0 00       	push   0xc056fc
  48c01f:	e8 dc 1c 26 00       	call   0x6edd00
  48c024:	83 c4 10             	add    esp,0x10
  48c027:	8d 43 f8             	lea    eax,[ebx-0x8]
  48c02a:	e8 41 71 00 00       	call   0x493170
  48c02f:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  48c036:	bf 01 00 00 00       	mov    edi,0x1
  48c03b:	75 13                	jne    0x48c050
  48c03d:	09 3d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,edi
  48c043:	68 10 cf bc 00       	push   0xbccf10
  48c048:	e8 cd 62 40 00       	call   0x89231a
  48c04d:	83 c4 04             	add    esp,0x4
  48c050:	83               	or     esi,0xffffffff
```

**Round2 達標結論**：Client callback table（stride16）、FD2CF8 callback table（stride8）以及兩個轉送函式 (`0x494360`, `0x4943B0`) 的不同落點均有 BIN 指令支持，降低將任意「handler index」擬作同一 wire command 的風險。

## Round 3 — network parser、packet queue、與 command dispatch 的未閉合 boundary

### 3.1 IOCP 完成後 frame parser 做的是 frame-size/marker/可解密 payload，不是直接 invoke 0x4FDA30

原始 `0x807B40` 從接收 ring 中讀 16-bit payload length、16-bit marker。認出 `0x2633` header8、`0x0BBB` header6、`0x1A68` 與 `0x22D7` header4（未識別 marker 默認 header4；它是否會因後續檢查而被拒絕要另看）。對 `0x0BBB` 對稱 XOR 及簡單 16-bit 加總校驗，產生 payload 複本。**最後先呼叫 `0x807E50` 將 payload 複製進 packet queue：這不是 `0x4FDA30`**。此境界也解釋為何 E37 不能憑 local enqueue 說它已 WSASend 成功。

### 3.2 frame header discriminator：2633／0BBB／1A68／22D7

`[EBX]` 長度需在 1..0x1000，認識的 marker 決定 `header length`，完整性 guard `payloadLen+header <= accumulated`。本段不把 frame marker 認作 handler opcode。

```asm
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
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```

### 3.3 BBB decode/checksum 與 queue-producer call 0x807E50

`0x807D66` 比較 `word [EBX+4]` 與計算總和；正常匹配後 push payload buffer、call `0x807E50`。其他 marker/特殊解碼路徑也可能呼叫該 queue producer。`0x807E50` 的輸入 `ESI` 是 payload length、`EDI` 是 queue element；不得與 Client handler 的 3-param ABI 混淆。

```asm
  807ccb:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  807cd0:	74 5a                	je     0x807d2c
  807cd2:	8a 17                	mov    dl,BYTE PTR [edi]
  807cd4:	80 f2 7c             	xor    dl,0x7c
  807cd7:	b8 01 00 00 00       	mov    eax,0x1
  807cdc:	88 54 24 2c          	mov    BYTE PTR [esp+0x2c],dl
  807ce0:	3b f0                	cmp    esi,eax
  807ce2:	76 10                	jbe    0x807cf4
  807ce4:	8a 0c 07             	mov    cl,BYTE PTR [edi+eax*1]
  807ce7:	32 4c 04 2b          	xor    cl,BYTE PTR [esp+eax*1+0x2b]
  807ceb:	40                   	inc    eax
  807cec:	88 4c 04 2b          	mov    BYTE PTR [esp+eax*1+0x2b],cl
  807cf0:	3b c6                	cmp    eax,esi
  807cf2:	72 f0                	jb     0x807ce4
  807cf4:	8d 94 24 2c 10 00 00 	lea    edx,[esp+0x102c]
  807cfb:	52                   	push   edx
  807cfc:	8b ce                	mov    ecx,esi
  807cfe:	8d 44 24 30          	lea    eax,[esp+0x30]
  807d02:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  807d06:	c7 44 24 1c 00 10 00 	mov    DWORD PTR [esp+0x1c],0x1000
  807d0d:	00 
  807d0e:	e8 7d f4 f1 ff       	call   0x727190
  807d13:	83 c4 04             	add    esp,0x4
  807d16:	85 c0                	test   eax,eax
  807d18:	75 65                	jne    0x807d7f
  807d1a:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
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
  807d7f:	8b             	mov    eax,DWORD PTR [esp+0x28]
```

### 3.4 0x807E50 僅複製 payload 到 queue element

`cmp esi,0x1000`，長度合法則將 `[EBP+8]` 指的 payload 拷到 `[EDI+8]`，寫 `[EDI+4]=ESI`，回傳 AL=1。沒有拆 header 後直接取得 cmd，也沒有在此處使用 FD2CF8 的 callback table。

```asm
  807e50:	55                   	push   ebp
  807e51:	8b ec                	mov    ebp,esp
  807e53:	81 fe 00 10 00 00    	cmp    esi,0x1000
  807e59:	76 06                	jbe    0x807e61
  807e5b:	32 c0                	xor    al,al
  807e5d:	5d                   	pop    ebp
  807e5e:	c2 04 00             	ret    0x4
  807e61:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807e64:	56                   	push   esi
  807e65:	50                   	push   eax
  807e66:	8d 4f 08             	lea    ecx,[edi+0x8]
  807e69:	51                   	push   ecx
  807e6a:	e8 61 5d 09 00       	call   0x89dbd0
  807e6f:	83 c4 0c             	add    esp,0xc
  807e72:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  807e75:	b0 01                	mov    al,0x1
  807e77:	5d                   	pop    ebp
  807e78:	c2 04 00             	ret    0x4
```

### 3.5 本輪找到的另一接收側 direct command 提取不等於 IOCP queue consumer 已閉合

- `0x4930E0` 指向應用/Client callback routing，明確 `movzx edi,WORD [packetBuffer]`；
- `0x4FDA30` 指向分派器，明確 `movsx edi,cx`、`callback = [this+index*8+4]`；
- `0x807B40` / `0x807E50` 則只做從 FD/socket 得到 packet payload → ring queue entry；
- **缺少的中間段**仍是：queue consumer 選出具體 Conn key，取 queue entry 的 buffer 與長度，如何拆 `WORD` command、如何 call `0x4930E0` 或某個 `0x494360` table callback，以及針對 key0/1/2 的限定。前面三個單點不能靠「看起來像」拼成端到端因果鏈。

### 3.6 刻意限定的 first S2C 與異常/重連交付

在 `0x4FDA30` 的 caller 傳入 `short=2` 時，**明確會選擇 handler `0x4B7F00`**，它會解析長資料並產生 key0 0x0026/0x0024/0x001F/0x0025/0x0015/...、key2 0x0BB9、key0 0x00A0，最後開啟 0x00A7 timer（詳 E37/E38）。從這點不能推斷 **實際 Server 的第一筆 S2C command 會是 2**：可能還有其他 handler、key、握手、Client 階段條件；沒有抓包亦不保證某路徑可以由 Server 模擬最小 payload 而通過全部 Client parser 及 UI。

同理 index0xBD2 的 `0x4B8DC0` 有條件發送 key2 0x0BCC/0x0BD1 是一個不同 handler；**未證** key2 的 0x0BB9 是它的直接 request 或收到哪個 server service 的 reply。對部署實務，legacy ports 20DF/20E0/20DE 是原生 static connect literal，未證 production topology recommendation。

### 3.7 三輪結案與下段研究目標

Round1 確認 `0x4FDA30` signed 16-bit indexed dispatch，完成 E38 的最大阻塞（table 用法），已達單段重大增量；Round2 梳理 Client callback table 的不同 stride與 routes；Round3 補 `0x807B40` 到 queue 的**明確邊界**，而不是假設直接連上 handler。三輪均以原件 native evidence 支援，不重複 E38 大段主題；因還沒串出唯一 SOCKET/key→queue consumer→FD2CF8，所以 E39 不是 RR 全部問題結案。

## 4. 設計輸出與可信層次（可供 T01/S00 分流）

| 類型 | 待辦 | 條件 |
|---|---|---|
| **Client 待逆向** | 檢索主循環的收包隊列 pop (`FE3358`/`0x8075B0` 附近) 與 `0x4930E0`/`0x494360` 的連接；記錄接收的 Conn/transport key，驗證 `cmd+len` 的來源與 bounds | 未閉合，下一段優先 |
| **Client 待逆向** | 解析 `0x4B7F00` 每個 varlen 欄位的最小合法 payload、`0x4B8DC0` 雙文字範圍，與 Server early replies 的真實次序 | 未閉合，不能產生完整 wire schema |
| **Server 待開發** | 只就已確認的 parser marker、local callback index 與 payload 形狀擬定相容性測試向量；不推測官方 Server 內部業務決策 | 目前僅 DRAFT 測試素材 |
| **跨功能待整合** | RR5 產物供 T02（framing/conn keys）、T03（login/choice UI）、T01（source validator）、S00（GAP-NET-0002）；其他 Task 可能對 index2 已有不同語意時以各自 blob 原證據協調 | 並存保留不同來源，不自行升級 FULL-PASS |
| **待遊玩驗證** | 規範允許後的獨立網路記錄，逐項驗證 key0/1/2 的第一個 app payload、frame header、WSASend completion、S2C backpressure/scene state | 沒有原版 Client 執行/pcap，不可驗收可玩 |

## 5. 引用來源、可重現性與下一段 E40

**第一手**：本次 `Tartaros.bin` PE32，原始 SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；以下為最小 native 再現命令：

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x4FDA30 --stop-address=0x4FDAB3 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x494360 --stop-address=0x4943AC Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x4930E0 --stop-address=0x493160 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x807B40 --stop-address=0x807E7B Tartaros.bin
```

**GitHub**：本回合 GitHub 寫入僅 `main/AGENTS.md`，commit `217a0358fceceb03a5cb02cd19d401206364bead`；E39 在本機保存，不提交 `extra/roy1`，沒有動 RR claim/state、T01 FULL-PASS、S00 SPEC。E37 和 E38 也仍是未提交的完整原稿；未來使用者如要求推送，按專屬分支一起提交並遠端核對 SHA。

**E40 指向**：`0x8075B0`/packet queue 元件的真正 consumer、`0x807B40` 的 `packet+len` 轉交、`0x4930E0` 的入口 call chain，目標是首度以 BIN 證明 `(source Conn*, transport key) → app cmd word → callback table → handler` 的端到端局部鏈，若發現另一個 app dispatch owner 應據實修正。分辨 receive side 的 `0x807E50` queue producer、`0x4FDA30` callback consumer 之間至少一層缺口；不要為達成形式「閉合」而造橋。
