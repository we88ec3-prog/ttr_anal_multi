# E66 — RR-0002：Square Scene 啟動後的 C→S `0x0043`、雙 Singleton 身分反證與 Scene 專屬 0x68／0x6A handlers

研究日期：2026-10-30 Asia/Taipei；研究者 `chatgpt-web roy`；唯一研究工作分支 `extra/roy1`。來源：KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本研究直接依原始 BIN 反組譯及 RTTI bytes；不執行目標、不建立模擬成功的官方 Server 封包、不修改 Client。接續 E61–E65；RR-0002 正式 `IN_PROGRESS`。

> **本輪正向進展**：當 Client 接收到 app `S→C 0x0069 / subtype 7` 且建立、啟動 `CSquare` 成功時，新的 scene virtual+0x10=`0x4BBC10` 會（有條件）建立本地 **`C→S 0x0043`、len4**；`XX` 欄位來自 `CSquareUserData+0x18`，`YY=0x0A`。`S→C 0x0069` +3/+4 寫到的 `FE1A88` 卻是另一個 **`CSquareChannelState`** singleton。不能把 C→S 0x43 與原有 S→C 0x43 handler 或 C→S 0x42 混淆；**依然沒有原版 Server 對 C→S 0x42 的確切回覆配對證據**。

## 1. 功能鏈新閉合：S2C69/7 → CSquare construction → scene manager → scene entry → C2S43

1. T02 first-level app index 0x69 進 `0x4B9090`；`0x4B90C1` 讀 signed payload[2]，值7 時進 `0x4B90DF`，分配 0xBD54，`0x4B90F0` 呼叫 `0x4BBB70` 創建 native `CSquare@Scene@@` vptr `0xC06FB0`；`0x4B90FD` 呼叫 scene manager `0x4B7D50`。
2. `0x4B7D50` 清理舊 scene、寫 scene manager+0x5EAC 的新 scene 指標，再在 `0x4B7DB2..4B7DBC` 從 vptr+0x10 間接 call；從原件讀取 `0xC06FB0+0x10` 的 DWORD 是 `0x4BBC10`。
3. `0x4BBC10` 在 `0x4BBE5F` 讀全域 pointer `[0xFE1AA0]`、`0x4BBE66` 取其 `+0x18` DWORD 低8位；`0x4BBE7F` 檢查 `[0xFBA798]==0`，建立 LE16 0x0043、byte XX、byte 0x0A，並在 gate 成立時對 `[0xFBA854] vtable+0x10` 以 slot0、payload length4 本地 enqueue。這是 **outbound app payload candidate**，不表示 socket write 已完成。
4. `0x4BB7AA..4BB801` 的另一路原生函式也從 `CSquareUserData+0x18` 建出相同 `43 00 XX 0A` payload，帶不同場景/物件前置副作用。不能因第二個 producer 同命令就臆稱它屬原版 Server 的選角回覆。
5. 本項允許相容測試的順序僅限**Client 本地**：`S2C 0x0069/7` 條件成功 → scene manager entry → C2S 0x0043 enqueue。尚缺 Server 何時/為何送0x69、是否與此前選角0x42成一個交易的第一手證據。

## 2. 兩個容易混淆的 singleton：原生 RTTI 和不同 writer 證明不同

原生 PE `.rdata` vptr前一個 DWORD 是 COL；COL+0xC 的 TypeDescriptor，+8 ANSI 類名。原始 image：

| vtable | COL | TypeDescriptor | 原生名稱 | 指標初始化 | 狀態位置 |
|---|---|---|---|---|---|

| `0x00C0DDA4` | `0x00C6B8E0` | `0x00F7EEEC` | `.?AVCSquareUserData@@` | 0x506BBE -> global FE1AA0 | +0x18 active index / +0x1C count / +0x20 flag |

| `0x00C0DD84` | `0x00C6B834` | `0x00F7EE98` | `.?AVCSquareChannelState@@` | 0x506C0F -> global FE1A88 | +0x18/+0x1C channel/subtype fields |

| `0x00C06FB0` | `0x00C699E4` | `0x00F7E01C` | `.?AVCSquare@Scene@@` | 0x4BBB78 -> scene vptr | +0x10 scene entry 0x4BBC10 |


- `0x506B9F..0x506BCD` 分配 0x24 byte 的 `CSquareUserData`，將 `FE1AA0` 寫為新配置指標，並初始化 `+0x18=0`、`+0x1C=1`、`+0x20=0`；`0x50863E` 對此全域寫 0 是解構路径，不是對角色 ID 的更改。
- `0x506BF0..0x506C1A` 另配置 0x20 byte `CSquareChannelState`，存於**不同全域變數** `FE1A88`，其中 `+0x18=0`、`+0x1C=0`。
- `0x4B91EE..0x4B9212` 於 S2C69 處理後，將 payload[3]、payload[4] 兩個 byte 寫入 `[FE1A88]+0x18/+0x1C`，而不是 `[FE1AA0]`；原件證明不可能將兩個全域「名稱相似」就視為相同。其間沒有證據說 payload+3/4 對應角色永久識別。
- `0x4BBFA0` 是 scene 區的另一個 S2C 消費者，把 `[FE1AA0]+0x1C` 改為 payload[2]，並循 `floor((len−3)/8)` 處理後續欄位、通知本地 event `0xF4249`。這是 Square 可見的列表/數量資料來源，不是 C2S0x42 核准結果。
- `0x66FC52` 與 `0x66FEED..0x66FF21` 以及 `0x508970` 表明 `[FE1AA0]+0x18` 還可由 UI 選擇／左右移動／有效值檢查更新；`0x508970` 成功設值後亦會產生 `43 00 XX 0A`。因此該 C2S43 byte 不能直接叫 selected-character ID 或 0x69 所帶回的 byte。

## 3. Scene-specific inbound command 與兩層 dispatch 的索引

Scene 內的 handler 表由 `0x4ADD50` 建立，0x4C4670 依 `scene+0x5EAC+8*command` 對應獨立的每場景處理槽。在 native CSquare ctor（`0x4BBB70..0x4BBC0B`）裡，`0x4BBBA0` 註冊：

| Scene handler address at object | scene command index | installed code ptr | known bounded effect |
|---|---|---|---|

| `+0x5FA4` | `0x1F` | `0x4C5C50` | base/common scene handler |

| `+0x5FD4` | `0x25` | `0x4C5C50` | base/common scene handler |

| `+0x61EC` | `0x68` | `0x4BC050` | CSquareChannelState +0x18 from payload+2; remainder 2-byte records |

| `+0x61FC` | `0x6A` | `0x4BBFA0` | CSquareUserData+0x1C count and 8-byte records, event F4249 |

| `+0x6204` | `0x6B` | `0x4BBAE0` | CSquare-specific scene entry (still need full effect signature) |


以相同偏移對照 `CExpedition` ctor `0x4C14E1..0x4C14F2`：Scene `+0x60FC`（index0x4A）→ `0x4C21D0`，Scene `+0x61EC`（index0x68）→ `0x4C21F0`。後者也讀 payload+2、以 (len−3)/2 複製雙 byte 記錄到 `CSquareChannelState`。**同一 S2C command 0x68 的行為受當前 active scene 影響**，不能從一個場景的 handler 推論全遊戲相同。

`0x4BBFA0` 在 `0x4BBFA7` 讀 payload+2 並寫 `CSquareUserData+0x1C`；其 records 計數 `len<3?0:(len−3)/8`。`0x4BC050` 在 `0x4BC089` 讀 payload+2 並寫 `CSquareChannelState+0x18`；其 records 計數 `len<3?0:(len−3)/2`。兩者的規格完全不同，亦不同於 command2 的 65-byte header+53-byte record。

**指標與長度風險**：此處的 `(len−3)/stride` 計數並不是對 payload[2] 的讀取前做完整邊界檢查；若總 payload 長度<3，仍已讀 +2。不可把本研究的最短欄位說成遊戲安全接受任意截斷資料。也不能推定所有 payload 都被 Server 合法產出。

## 4. 由 Server 相容設計看通訊階段，而非錯誤的 `0x42 → 0x43` +1 推理

```text
已證 Client：    UI -> C2S 0x0042  [XX/YY 由 caller 提供；slot0, len4]
                          ||
                          ||   原版 Server 交易配對尚未查得
                          ||
已證 Client：   S2C 0x0069/7  -> CSquare ctor -> active scene -> CSquare::entry 0x4BBC10
                                                             -> C2S 0x0043 [XX=CSquareUserData+18, YY=0x0A]
                  S2C 0x0068   -> active scene consumer (Square/Expedition 定義有差)
                  S2C 0x006A   -> Square CSquareUserData+1C + records/event
```

原版 Server 對 C2S42 的批准／拒絕和 S2C69 的時序仍未知；但上述 C2S43 是可驗證的 Client 端「場景啟動後，若 send-gate 成立就排入佇列」行為。其 `YY=0x0A` 是指令直接賦值，不是猜的 role index。原版 Server 處理 0x43 的用途則不能從 Client C2S 建構推回其內部演算法。

## 5. 已驗證前提與負面結論清單

| Claim | native verdict | 證據 |
|---|---|---|
| 0x69 subtype7 可啟動 CSquare | 確認（有效 object/scene 及無資源例外條件） | 4B90DF/4BBB70/4B7D50/vptr+10→4BBC10 |
| CSquare entry 必定在網路 wire 立即送成功 | **不成立**；FBA798 gate，Tx queue/IOCP 是另一階段 | 4BBE7F–4BBEB1 |
| C2S43 是 4-byte 指令 43 00 XX 0A | 已證本地 buffer | 4BBE86–4BBEAF、5089B0–5089D7、4BB7D6–4BB801 |
| C2S43 的 XX 是從 S2C69 payload[3] | **不成立**；來源是 FE1AA0 +0x18，不同 FE1A88 | 4BBE5F..4BBE94、4B9202..4B9212、506BBF/506C0F RTTI |
| S2C0x42/43 就是選角核准結果 | 仍無證據，不得擅自配對 | E61/E62/E63 全部既有消費反證 |
| C2S42 實際被原版 Server 以 S2C69/7 回覆 | UNKNOWN；只有 Client 可接受該 S2C 的局部行為證據 | E64/E65 本地 scene chain 及本輪 C2S43，無 server capture |
| S2C0x68/0x6A 具有場景限定的不同列表語意 | 已證受 active scene table 和各自 handler 限定，具體欄位仍只按寬度 | 4BBBA0..BBC0B、4C14E1..F2、4BBFA0..4BC149 |

## 6. 後續仍需補的 RR 重要鏈節

**Client 待逆向**：C2S0x42 sender/role index 如何被應用於後續 UI/CSquare player identity；其失敗或取消回覆的明確消費者；S2C 0x60、69、68、6A 的跨場景實際收發條件是否有其他外層 gate，`CSquareUserData` 在何時初始化/釋放及是否與同一連線 slot 相關。

**原版 Server 待證／Server 待開發**：成功／失敗的官方 reply opcode、資料順序、票據、角色授權及初始化欄位；這些不能由 Client 反組譯的存在推知。

**跨功能待整合**：T02 app dispatch/lane/queue/transport；T04 role record identity與初值；T05 CSquare world entry與初始化；T06 UI 控件與索引。

**待遊玩驗證**：在可靠 Client/Server 分離環境進行 S2C69/7 的合成測試，記錄 C2S43 的具體 byte、Conn slot、資源載入和失敗情況；不能把合成測試當原版官方協定。

RR-0002 有**重要新 Client-first 正向橋接**，但未閉合其 acceptance 所要求的「實際選角回覆配對」，故**尚不宣稱 SUBMITTED／ACCEPTED**。

## 7. 重現與原生指令（所有下列範圍直接取同一 Tartaros.bin）

```python
from pathlib import Path
import struct,hashlib
b=Path('Tartaros.bin').read_bytes()
assert hashlib.sha256(b).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def off(v):
    return v-0x401a00 if 0xbd2000<=v<0xd61000 else (v-0x402800 if v>=0xd61000 else v-0x400c00)
def U32(v):return struct.unpack_from('<I',b,off(v))[0]
assert U32(0xc06fb0+0x10)==0x4bbc10
assert U32(0xc0dda4-4) != U32(0xc0dd84-4)
assert (0x61ec-0x5eac)//8==0x68
assert (0x61fc-0x5eac)//8==0x6a
assert (0x6204-0x5eac)//8==0x6b
```

### S2C 0x69→CSquare subtype7 and FE1A88 writers：`0x4B90BE..0x4B9218`

```asm
  4b90be:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b90c1:	0f be 48 02          	movsx  ecx,BYTE PTR [eax+0x2]
  4b90c5:	8d 41 f9             	lea    eax,[ecx-0x7]
  4b90c8:	83 f8 11             	cmp    eax,0x11
  4b90cb:	0f 87 5b 01 00 00    	ja     0x4b922c
  4b90d1:	0f b6 90 4c 92 4b 00 	movzx  edx,BYTE PTR [eax+0x4b924c]
  4b90d8:	ff 24 95 38 92 4b 00 	jmp    DWORD PTR [edx*4+0x4b9238]
  4b90df:	68 54 bd 00 00       	push   0xbd54
  4b90e4:	e8 7f 81 3d 00       	call   0x891268
  4b90e9:	83 c4 04             	add    esp,0x4
  4b90ec:	85 c0                	test   eax,eax
  4b90ee:	74 07                	je     0x4b90f7
  4b90f0:	e8 7b 2a 00 00       	call   0x4bbb70
  4b90f5:	eb 02                	jmp    0x4b90f9
  4b90f7:	33 c0                	xor    eax,eax
  4b90f9:	8b f8                	mov    edi,eax
  4b90fb:	8b f3                	mov    esi,ebx
  4b90fd:	e8 4e ec ff ff       	call   0x4b7d50
  4b9102:	e8 99 ba f4 ff       	call   0x404ba0
  4b9107:	c7 80 a8 69 00 00 07 	mov    DWORD PTR [eax+0x69a8],0x7
  4b910e:	00 00 00 
  4b9111:	e9 ab 00 00 00       	jmp    0x4b91c1
  4b9116:	68 54 bd 00 00       	push   0xbd54
  4b911b:	e8 48 81 3d 00       	call   0x891268
  4b9120:	8b f0                	mov    esi,eax
  4b9122:	83 c4 04             	add    esp,0x4
  4b9125:	85 f6                	test   esi,esi
  4b9127:	74 25                	je     0x4b914e
  4b9129:	e8 22 4c ff ff       	call   0x4add50
  4b912e:	c7 06 7c 6f c0 00    	mov    DWORD PTR [esi],0xc06f7c
  4b9134:	c7 05 74 a6 d6 00 55 	mov    DWORD PTR ds:0xd6a674,0x44535155
  4b913b:	51 53 44 
  4b913e:	e8 5d 23 00 00       	call   0x4bb4a0
  4b9143:	8b fe                	mov    edi,esi
  4b9145:	8b f3                	mov    esi,ebx
  4b9147:	e8 04 ec ff ff       	call   0x4b7d50
  4b914c:	eb 73                	jmp    0x4b91c1
  4b914e:	33 f6                	xor    esi,esi
  4b9150:	8b fe                	mov    edi,esi
  4b9152:	8b f3                	mov    esi,ebx
  4b9154:	e8 f7 eb ff ff       	call   0x4b7d50
  4b9159:	eb 66                	jmp    0x4b91c1
  4b915b:	68 54 bd 00 00       	push   0xbd54
  4b9160:	e8 03 81 3d 00       	call   0x891268
  4b9165:	83 c4 04             	add    esp,0x4
  4b9168:	85 c0                	test   eax,eax
  4b916a:	74 07                	je     0x4b9173
  4b916c:	e8 ff 29 00 00       	call   0x4bbb70
  4b9171:	eb 02                	jmp    0x4b9175
  4b9173:	33 c0                	xor    eax,eax
  4b9175:	8b f8                	mov    edi,eax
  4b9177:	8b f3                	mov    esi,ebx
  4b9179:	e8 d2 eb ff ff       	call   0x4b7d50
  4b917e:	e8 1d ba f4 ff       	call   0x404ba0
  4b9183:	c7 80 a8 69 00 00 17 	mov    DWORD PTR [eax+0x69a8],0x17
  4b918a:	00 00 00 
  4b918d:	eb 32                	jmp    0x4b91c1
  4b918f:	68 54 bd 00 00       	push   0xbd54
  4b9194:	e8 cf 80 3d 00       	call   0x891268
  4b9199:	83 c4 04             	add    esp,0x4
  4b919c:	85 c0                	test   eax,eax
  4b919e:	74 07                	je     0x4b91a7
  4b91a0:	e8 cb 29 00 00       	call   0x4bbb70
  4b91a5:	eb 02                	jmp    0x4b91a9
  4b91a7:	33 c0                	xor    eax,eax
  4b91a9:	8b f8                	mov    edi,eax
  4b91ab:	8b f3                	mov    esi,ebx
  4b91ad:	e8 9e eb ff ff       	call   0x4b7d50
  4b91b2:	e8 e9 b9 f4 ff       	call   0x404ba0
  4b91b7:	c7 80 a8 69 00 00 18 	mov    DWORD PTR [eax+0x69a8],0x18
  4b91be:	00 00 00 
  4b91c1:	b8 01 00 00 00       	mov    eax,0x1
  4b91c6:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4b91cc:	75 20                	jne    0x4b91ee
  4b91ce:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b91d4:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b91db:	00 
  4b91dc:	e8 af 83 02 00       	call   0x4e1590
  4b91e1:	68 80 cc bc 00       	push   0xbccc80
  4b91e6:	e8 2f 91 3d 00       	call   0x89231a
  4b91eb:	83 c4 04             	add    esp,0x4
  4b91ee:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b91f1:	0f be 41 02          	movsx  eax,BYTE PTR [ecx+0x2]
  4b91f5:	39 05 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,eax
  4b91fb:	74 05                	je     0x4b9202
  4b91fd:	a3 2c 39 f9 00       	mov    ds:0xf9392c,eax
  4b9202:	0f b6 51 03          	movzx  edx,BYTE PTR [ecx+0x3]
  4b9206:	a1 88 1a fe 00       	mov    eax,ds:0xfe1a88
  4b920b:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  4b920e:	0f b6 49 04          	movzx  ecx,BYTE PTR [ecx+0x4]
  4b9212:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  4b9215:	33 c0                	xor    eax,eax
  4b9217:	8b             	mov    ecx,DWORD PTR [esp+0x18]
```

### CSquare scene ctor / custom scene handler table：`0x4BBB70..0x4BBC0C`

```asm
  4bbb70:	56                   	push   esi
  4bbb71:	8b f0                	mov    esi,eax
  4bbb73:	e8 d8 21 ff ff       	call   0x4add50
  4bbb78:	c7 06 b0 6f c0 00    	mov    DWORD PTR [esi],0xc06fb0
  4bbb7e:	c7 05 74 a6 d6 00 52 	mov    DWORD PTR ds:0xd6a674,0x53515552
  4bbb85:	55 51 53 
  4bbb88:	e8 13 00 00 00       	call   0x4bbba0
  4bbb8d:	8b c6                	mov    eax,esi
  4bbb8f:	5e                   	pop    esi
  4bbb90:	c3                   	ret
  4bbb91:	cc                   	int3
  4bbb92:	cc                   	int3
  4bbb93:	cc                   	int3
  4bbb94:	cc                   	int3
  4bbb95:	cc                   	int3
  4bbb96:	cc                   	int3
  4bbb97:	cc                   	int3
  4bbb98:	cc                   	int3
  4bbb99:	cc                   	int3
  4bbb9a:	cc                   	int3
  4bbb9b:	cc                   	int3
  4bbb9c:	cc                   	int3
  4bbb9d:	cc                   	int3
  4bbb9e:	cc                   	int3
  4bbb9f:	cc                   	int3
  4bbba0:	68 a8 5e 00 00       	push   0x5ea8
  4bbba5:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4bbbab:	6a 00                	push   0x0
  4bbbad:	50                   	push   eax
  4bbbae:	e8 ad 2c 3e 00       	call   0x89e860
  4bbbb3:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4bbbb8:	83 c4 0c             	add    esp,0xc
  4bbbbb:	c7 86 a4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fa4],0x4c5c50
  4bbbc2:	5c 4c 00 
  4bbbc5:	89 86 a8 5f 00 00    	mov    DWORD PTR [esi+0x5fa8],eax
  4bbbcb:	c7 86 d4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fd4],0x4c5c50
  4bbbd2:	5c 4c 00 
  4bbbd5:	89 86 d8 5f 00 00    	mov    DWORD PTR [esi+0x5fd8],eax
  4bbbdb:	c7 86 ec 61 00 00 50 	mov    DWORD PTR [esi+0x61ec],0x4bc050
  4bbbe2:	c0 4b 00 
  4bbbe5:	89 86 f0 61 00 00    	mov    DWORD PTR [esi+0x61f0],eax
  4bbbeb:	c7 86 fc 61 00 00 a0 	mov    DWORD PTR [esi+0x61fc],0x4bbfa0
  4bbbf2:	bf 4b 00 
  4bbbf5:	89 86 00 62 00 00    	mov    DWORD PTR [esi+0x6200],eax
  4bbbfb:	c7 86 04 62 00 00 e0 	mov    DWORD PTR [esi+0x6204],0x4bbae0
  4bbc02:	ba 4b 00 
  4bbc05:	89 86 08 62 00 00    	mov    DWORD PTR [esi+0x6208],eax
  4bbc0b:	c3                   	ret
```

### CSquare scene entry / C2S43 queue path：`0x4BBC10..0x4BBF09`

```asm
  4bbc10:	55                   	push   ebp
  4bbc11:	8b ec                	mov    ebp,esp
  4bbc13:	83 e4 f8             	and    esp,0xfffffff8
  4bbc16:	6a ff                	push   0xffffffff
  4bbc18:	68 3d 49 94 00       	push   0x94493d
  4bbc1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bbc23:	50                   	push   eax
  4bbc24:	83 ec 10             	sub    esp,0x10
  4bbc27:	53                   	push   ebx
  4bbc28:	56                   	push   esi
  4bbc29:	57                   	push   edi
  4bbc2a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bbc2f:	33 c4                	xor    eax,esp
  4bbc31:	50                   	push   eax
  4bbc32:	8d 44 24 20          	lea    eax,[esp+0x20]
  4bbc36:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bbc3c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4bbc43:	bf 01 00 00 00       	mov    edi,0x1
  4bbc48:	75 29                	jne    0x4bbc73
  4bbc4a:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4bbc50:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  4bbc57:	00 
  4bbc58:	e8 13 45 0a 00       	call   0x560170
  4bbc5d:	68 10 d1 bc 00       	push   0xbcd110
  4bbc62:	e8 b3 66 3d 00       	call   0x89231a
  4bbc67:	83 c4 04             	add    esp,0x4
  4bbc6a:	83 cb ff             	or     ebx,0xffffffff
  4bbc6d:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbc71:	eb 03                	jmp    0x4bbc76
  4bbc73:	83 cb ff             	or     ebx,0xffffffff
  4bbc76:	6a 00                	push   0x0
  4bbc78:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4bbc7d:	e8 2e 68 0a 00       	call   0x5624b0
  4bbc82:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4bbc89:	75 20                	jne    0x4bbcab
  4bbc8b:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4bbc91:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4bbc95:	e8 d6 44 0a 00       	call   0x560170
  4bbc9a:	68 10 d1 bc 00       	push   0xbcd110
  4bbc9f:	e8 76 66 3d 00       	call   0x89231a
  4bbca4:	83 c4 04             	add    esp,0x4
  4bbca7:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbcab:	e8 a0 65 0a 00       	call   0x562250
  4bbcb0:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bbcb6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bbcb8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4bbcbb:	ff d2                	call   edx
  4bbcbd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4bbcc4:	be 02 00 00 00       	mov    esi,0x2
  4bbcc9:	75 20                	jne    0x4bbceb
  4bbccb:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4bbcd1:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4bbcd5:	e8 b6 2f 02 00       	call   0x4dec90
  4bbcda:	68 30 ce bc 00       	push   0xbcce30
  4bbcdf:	e8 36 66 3d 00       	call   0x89231a
  4bbce4:	83 c4 04             	add    esp,0x4
  4bbce7:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbceb:	68 30 b1 fa 00       	push   0xfab130
  4bbcf0:	e8 9b 41 02 00       	call   0x4dfe90
  4bbcf5:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4bbcfc:	75 24                	jne    0x4bbd22
  4bbcfe:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4bbd04:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  4bbd0b:	00 
  4bbd0c:	e8 7f 2f 02 00       	call   0x4dec90
  4bbd11:	68 30 ce bc 00       	push   0xbcce30
  4bbd16:	e8 ff 65 3d 00       	call   0x89231a
  4bbd1b:	83 c4 04             	add    esp,0x4
  4bbd1e:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbd22:	68 48 b1 fa 00       	push   0xfab148
  4bbd27:	c7 05 28 b2 fa 00 00 	mov    DWORD PTR ds:0xfab228,0x0
  4bbd2e:	00 00 00 
  4bbd31:	e8 3a 53 02 00       	call   0x4e1070
  4bbd36:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bbd3c:	83 c4 04             	add    esp,0x4
  4bbd3f:	85 c9                	test   ecx,ecx
  4bbd41:	74 2e                	je     0x4bbd71
  4bbd43:	39 35 ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,esi
  4bbd49:	75 0e                	jne    0x4bbd59
  4bbd4b:	8b f9                	mov    edi,ecx
  4bbd4d:	e8 fe 91 08 00       	call   0x544f50
  4bbd52:	bf 01 00 00 00       	mov    edi,0x1
  4bbd57:	eb 51                	jmp    0x4bbdaa
  4bbd59:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bbd5b:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4bbd5e:	ff d2                	call   edx
  4bbd60:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bbd66:	85 c9                	test   ecx,ecx
  4bbd68:	74 07                	je     0x4bbd71
  4bbd6a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bbd6c:	8b 10                	mov    edx,DWORD PTR [eax]
  4bbd6e:	57                   	push   edi
  4bbd6f:	ff d2                	call   edx
  4bbd71:	68 c0 00 00 00       	push   0xc0
  4bbd76:	e8 ed 54 3d 00       	call   0x891268
  4bbd7b:	83 c4 04             	add    esp,0x4
  4bbd7e:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4bbd82:	c7 44 24 28 05 00 00 	mov    DWORD PTR [esp+0x28],0x5
  4bbd89:	00 
  4bbd8a:	85 c0                	test   eax,eax
  4bbd8c:	74 08                	je     0x4bbd96
  4bbd8e:	50                   	push   eax
  4bbd8f:	e8 ac c7 08 00       	call   0x548540
  4bbd94:	eb 02                	jmp    0x4bbd98
  4bbd96:	33 c0                	xor    eax,eax
  4bbd98:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbd9c:	8b 10                	mov    edx,DWORD PTR [eax]
  4bbd9e:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4bbda3:	8b c8                	mov    ecx,eax
  4bbda5:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4bbda8:	ff d0                	call   eax
  4bbdaa:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4bbdb1:	75 24                	jne    0x4bbdd7
  4bbdb3:	09 3d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,edi
  4bbdb9:	c7 44 24 28 0b 00 00 	mov    DWORD PTR [esp+0x28],0xb
  4bbdc0:	00 
  4bbdc1:	e8 ba b6 0c 00       	call   0x587480
  4bbdc6:	68 c0 cc bc 00       	push   0xbcccc0
  4bbdcb:	e8 4a 65 3d 00       	call   0x89231a
  4bbdd0:	83 c4 04             	add    esp,0x4
  4bbdd3:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbdd7:	39 35 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,esi
  4bbddd:	74 08                	je     0x4bbde7
  4bbddf:	89 35 f0 ad fa 00    	mov    DWORD PTR ds:0xfaadf0,esi
  4bbde5:	eb 05                	jmp    0x4bbdec
  4bbde7:	e8 b4 eb 0c 00       	call   0x58a9a0
  4bbdec:	6a 18                	push   0x18
  4bbdee:	e8 75 54 3d 00       	call   0x891268
  4bbdf3:	33 f6                	xor    esi,esi
  4bbdf5:	83 c4 04             	add    esp,0x4
  4bbdf8:	3b c6                	cmp    eax,esi
  4bbdfa:	74 1c                	je     0x4bbe18
  4bbdfc:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  4bbdff:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  4bbe02:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  4bbe05:	c7 40 10 3b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf433b
  4bbe0c:	c7 00 54 7b c4 00    	mov    DWORD PTR [eax],0xc47b54
  4bbe12:	c6 40 14 01          	mov    BYTE PTR [eax+0x14],0x1
  4bbe16:	8b f0                	mov    esi,eax
  4bbe18:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  4bbe1f:	75 25                	jne    0x4bbe46
  4bbe21:	83 0d d0 ad fa 00 01 	or     DWORD PTR ds:0xfaadd0,0x1
  4bbe28:	c7 44 24 28 0c 00 00 	mov    DWORD PTR [esp+0x28],0xc
  4bbe2f:	00 
  4bbe30:	e8 5b 1b 29 00       	call   0x74d990
  4bbe35:	68 70 cc bc 00       	push   0xbccc70
  4bbe3a:	e8 db 64 3d 00       	call   0x89231a
  4bbe3f:	83 c4 04             	add    esp,0x4
  4bbe42:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbe46:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  4bbe4a:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4bbe4e:	51                   	push   ecx
  4bbe4f:	be 6c 5c f9 00       	mov    esi,0xf95c6c
  4bbe54:	e8 07 84 34 00       	call   0x804260
  4bbe59:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4bbe60:	8b 15 a0 1a fe 00    	mov    edx,DWORD PTR ds:0xfe1aa0
  4bbe66:	8b 5a 18             	mov    ebx,DWORD PTR [edx+0x18]
  4bbe69:	75 14                	jne    0x4bbe7f
  4bbe6b:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  4bbe72:	68 10 cf bc 00       	push   0xbccf10
  4bbe77:	e8 9e 64 3d 00       	call   0x89231a
  4bbe7c:	83 c4 04             	add    esp,0x4
  4bbe7f:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4bbe86:	b8 43 00 00 00       	mov    eax,0x43
  4bbe8b:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  4bbe90:	88 5c 24 16          	mov    BYTE PTR [esp+0x16],bl
  4bbe94:	c6 44 24 17 0a       	mov    BYTE PTR [esp+0x17],0xa
  4bbe99:	75 16                	jne    0x4bbeb1
  4bbe9b:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4bbea1:	8b 11                	mov    edx,DWORD PTR [ecx]
  4bbea3:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4bbea6:	6a 04                	push   0x4
  4bbea8:	8d 44 24 18          	lea    eax,[esp+0x18]
  4bbeac:	50                   	push   eax
  4bbead:	6a 00                	push   0x0
  4bbeaf:	ff d2                	call   edx
  4bbeb1:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  4bbeb8:	75 29                	jne    0x4bbee3
  4bbeba:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  4bbec1:	c7 44 24 28 0d 00 00 	mov    DWORD PTR [esp+0x28],0xd
  4bbec8:	00 
  4bbec9:	e8 82 48 21 00       	call   0x6d0750
  4bbece:	68 30 d5 bc 00       	push   0xbcd530
  4bbed3:	e8 42 64 3d 00       	call   0x89231a
  4bbed8:	83 c4 04             	add    esp,0x4
  4bbedb:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4bbee2:	ff 
  4bbee3:	83 25 30 88 fb 00 fe 	and    DWORD PTR ds:0xfb8830,0xfffffffe
  4bbeea:	68 f8 aa fb 00       	push   0xfbaaf8
  4bbeef:	e8 1c 05 09 00       	call   0x54c410
  4bbef4:	33 c0                	xor    eax,eax
  4bbef6:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4bbefa:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bbf01:	59                   	pop    ecx
  4bbf02:	5f                   	pop    edi
  4bbf03:	5e                   	pop    esi
  4bbf04:	5b                   	pop    ebx
  4bbf05:	8b e5                	mov    esp,ebp
  4bbf07:	5d                   	pop    ebp
  4bbf08:	c3                   	ret
```

### additional C2S43 producer：`0x4BB7A9..0x4BB806`

```asm
  4bb7a9:	00 f6                	add    dh,dh
  4bb7ab:	05 14 13 fb 00       	add    eax,0xfb1314
  4bb7b0:	01 8b 0d a0 1a fe    	add    DWORD PTR [ebx-0x1e55ff3],ecx
  4bb7b6:	00 8b 59 18 75 13    	add    BYTE PTR [ebx+0x13751859],cl
  4bb7bc:	09 3d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,edi
  4bb7c2:	68 10 cf bc 00       	push   0xbccf10
  4bb7c7:	e8 4e 6b 3d 00       	call   0x89231a
  4bb7cc:	83 c4 04             	add    esp,0x4
  4bb7cf:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4bb7d6:	ba 43 00 00 00       	mov    edx,0x43
  4bb7db:	66 89 54 24 14       	mov    WORD PTR [esp+0x14],dx
  4bb7e0:	88 5c 24 16          	mov    BYTE PTR [esp+0x16],bl
  4bb7e4:	c6 44 24 17 0a       	mov    BYTE PTR [esp+0x17],0xa
  4bb7e9:	75 16                	jne    0x4bb801
  4bb7eb:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4bb7f1:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bb7f3:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4bb7f6:	6a 04                	push   0x4
  4bb7f8:	8d 54 24 18          	lea    edx,[esp+0x18]
  4bb7fc:	52                   	push   edx
  4bb7fd:	6a 00                	push   0x0
  4bb7ff:	ff d0                	call   eax
  4bb801:	f6 05 14 7c fb   	test   BYTE PTR ds:0xfb7c14,0x1
```

### C2S43 index setter：`0x508970..0x5089DB`

```asm
  508970:	55                   	push   ebp
  508971:	8b ec                	mov    ebp,esp
  508973:	53                   	push   ebx
  508974:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  508977:	83 fb ff             	cmp    ebx,0xffffffff
  50897a:	75 05                	jne    0x508981
  50897c:	8b 58 18             	mov    ebx,DWORD PTR [eax+0x18]
  50897f:	eb 08                	jmp    0x508989
  508981:	3b 58 1c             	cmp    ebx,DWORD PTR [eax+0x1c]
  508984:	7d 51                	jge    0x5089d7
  508986:	89 58 18             	mov    DWORD PTR [eax+0x18],ebx
  508989:	b8 01 00 00 00       	mov    eax,0x1
  50898e:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  508994:	75 13                	jne    0x5089a9
  508996:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  50899c:	68 10 cf bc 00       	push   0xbccf10
  5089a1:	e8 74 99 38 00       	call   0x89231a
  5089a6:	83 c4 04             	add    esp,0x4
  5089a9:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5089b0:	b8 43 00 00 00       	mov    eax,0x43
  5089b5:	66 89 45 08          	mov    WORD PTR [ebp+0x8],ax
  5089b9:	88 5d 0a             	mov    BYTE PTR [ebp+0xa],bl
  5089bc:	c6 45 0b 0a          	mov    BYTE PTR [ebp+0xb],0xa
  5089c0:	75 15                	jne    0x5089d7
  5089c2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5089c8:	8b 11                	mov    edx,DWORD PTR [ecx]
  5089ca:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  5089cd:	6a 04                	push   0x4
  5089cf:	8d 45 08             	lea    eax,[ebp+0x8]
  5089d2:	50                   	push   eax
  5089d3:	6a 00                	push   0x0
  5089d5:	ff d2                	call   edx
  5089d7:	5b                   	pop    ebx
  5089d8:	5d                   	pop    ebp
  5089d9:	c2 04              	ret    0x4
```

### CSquareUserData and CSquareChannelState init：`0x506B8F..0x506C29`

```asm
  506b8f:	f3 ff 6a 24          	repz jmp FWORD PTR [edx+0x24]
  506b93:	e8 d0 a6 38 00       	call   0x891268
  506b98:	83 c4 04             	add    esp,0x4
  506b9b:	3b c3                	cmp    eax,ebx
  506b9d:	74 36                	je     0x506bd5
  506b9f:	c7 40 04 40 6d bf 00 	mov    DWORD PTR [eax+0x4],0xbf6d40
  506ba6:	8d 48 04             	lea    ecx,[eax+0x4]
  506ba9:	c7 00 a4 dd c0 00    	mov    DWORD PTR [eax],0xc0dda4
  506baf:	c7 01 ac dd c0 00    	mov    DWORD PTR [ecx],0xc0ddac
  506bb5:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  506bb8:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  506bbb:	89 58 10             	mov    DWORD PTR [eax+0x10],ebx
  506bbe:	a3 a0 1a fe 00       	mov    ds:0xfe1aa0,eax
  506bc3:	89 58 18             	mov    DWORD PTR [eax+0x18],ebx
  506bc6:	c7 40 1c 01 00 00 00 	mov    DWORD PTR [eax+0x1c],0x1
  506bcd:	88 58 20             	mov    BYTE PTR [eax+0x20],bl
  506bd0:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  506bd3:	eb 03                	jmp    0x506bd8
  506bd5:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  506bd8:	8d 45 f0             	lea    eax,[ebp-0x10]
  506bdb:	8b fe                	mov    edi,esi
  506bdd:	e8 2e d1 f3 ff       	call   0x443d10
  506be2:	6a 20                	push   0x20
  506be4:	e8 7f a6 38 00       	call   0x891268
  506be9:	83 c4 04             	add    esp,0x4
  506bec:	3b c3                	cmp    eax,ebx
  506bee:	74 2f                	je     0x506c1f
  506bf0:	c7 40 04 40 6d bf 00 	mov    DWORD PTR [eax+0x4],0xbf6d40
  506bf7:	8d 48 04             	lea    ecx,[eax+0x4]
  506bfa:	c7 00 84 dd c0 00    	mov    DWORD PTR [eax],0xc0dd84
  506c00:	c7 01 8c dd c0 00    	mov    DWORD PTR [ecx],0xc0dd8c
  506c06:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  506c09:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  506c0c:	89 58 10             	mov    DWORD PTR [eax+0x10],ebx
  506c0f:	a3 88 1a fe 00       	mov    ds:0xfe1a88,eax
  506c14:	89 58 18             	mov    DWORD PTR [eax+0x18],ebx
  506c17:	89 58 1c             	mov    DWORD PTR [eax+0x1c],ebx
  506c1a:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  506c1d:	eb 03                	jmp    0x506c22
  506c1f:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  506c22:	8d 45 f0             	lea    eax,[ebp-0x10]
  506c25:	8b fe                	mov    edi,esi
  506c27:	e8 e4          	call   0x443d10
```

### UI click left/right write current index：`0x66FED0..0x66FF61`

```asm
  66fed0:	55                   	push   ebp
  66fed1:	8b ec                	mov    ebp,esp
  66fed3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66fed6:	81 78 10 78 05 00 00 	cmp    DWORD PTR [eax+0x10],0x578
  66fedd:	75 7e                	jne    0x66ff5d
  66fedf:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  66fee2:	8b 91 00 01 00 00    	mov    edx,DWORD PTR [ecx+0x100]
  66fee8:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66feeb:	75 15                	jne    0x66ff02
  66feed:	a1 a0 1a fe 00       	mov    eax,ds:0xfe1aa0
  66fef2:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  66fef5:	49                   	dec    ecx
  66fef6:	78 65                	js     0x66ff5d
  66fef8:	51                   	push   ecx
  66fef9:	e8 72 8a e9 ff       	call   0x508970
  66fefe:	5d                   	pop    ebp
  66feff:	c2 04 00             	ret    0x4
  66ff02:	8b 91 04 01 00 00    	mov    edx,DWORD PTR [ecx+0x104]
  66ff08:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66ff0b:	75 18                	jne    0x66ff25
  66ff0d:	a1 a0 1a fe 00       	mov    eax,ds:0xfe1aa0
  66ff12:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  66ff15:	41                   	inc    ecx
  66ff16:	3b 48 1c             	cmp    ecx,DWORD PTR [eax+0x1c]
  66ff19:	7d 42                	jge    0x66ff5d
  66ff1b:	51                   	push   ecx
  66ff1c:	e8 4f 8a e9 ff       	call   0x508970
  66ff21:	5d                   	pop    ebp
  66ff22:	c2 04 00             	ret    0x4
  66ff25:	8b 91 08 01 00 00    	mov    edx,DWORD PTR [ecx+0x108]
  66ff2b:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66ff2e:	75 09                	jne    0x66ff39
  66ff30:	e8 7b fd ff ff       	call   0x66fcb0
  66ff35:	5d                   	pop    ebp
  66ff36:	c2 04 00             	ret    0x4
  66ff39:	8b 91 0c 01 00 00    	mov    edx,DWORD PTR [ecx+0x10c]
  66ff3f:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66ff42:	75 09                	jne    0x66ff4d
  66ff44:	e8 e7 fd ff ff       	call   0x66fd30
  66ff49:	5d                   	pop    ebp
  66ff4a:	c2 04 00             	ret    0x4
  66ff4d:	8b 91 10 01 00 00    	mov    edx,DWORD PTR [ecx+0x110]
  66ff53:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66ff56:	75 05                	jne    0x66ff5d
  66ff58:	e8 83 fe ff ff       	call   0x66fde0
  66ff5d:	5d                   	pop    ebp
  66ff5e:	c2 04 00             	ret    0x4
```

### Square 0x6A inbox handler：`0x4BBFA0..0x4BC043`

```asm
  4bbfa0:	55                   	push   ebp
  4bbfa1:	8b ec                	mov    ebp,esp
  4bbfa3:	83 e4 f8             	and    esp,0xfffffff8
  4bbfa6:	51                   	push   ecx
  4bbfa7:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4bbfaa:	0f b6 50 02          	movzx  edx,BYTE PTR [eax+0x2]
  4bbfae:	8b 0d a0 1a fe 00    	mov    ecx,DWORD PTR ds:0xfe1aa0
  4bbfb4:	53                   	push   ebx
  4bbfb5:	56                   	push   esi
  4bbfb6:	89 51 1c             	mov    DWORD PTR [ecx+0x1c],edx
  4bbfb9:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4bbfbc:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  4bbfbf:	8d 71 0c             	lea    esi,[ecx+0xc]
  4bbfc2:	57                   	push   edi
  4bbfc3:	3b d0                	cmp    edx,eax
  4bbfc5:	74 26                	je     0x4bbfed
  4bbfc7:	8b 4c 24 0c          	mov    ecx,DWORD PTR [esp+0xc]
  4bbfcb:	51                   	push   ecx
  4bbfcc:	50                   	push   eax
  4bbfcd:	8b ca                	mov    ecx,edx
  4bbfcf:	e8 6c cb 04 00       	call   0x508b40
  4bbfd4:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4bbfd8:	8b 3e                	mov    edi,DWORD PTR [esi]
  4bbfda:	52                   	push   edx
  4bbfdb:	8b d8                	mov    ebx,eax
  4bbfdd:	e8 ae cb 04 00       	call   0x508b90
  4bbfe2:	8b 0d a0 1a fe 00    	mov    ecx,DWORD PTR ds:0xfe1aa0
  4bbfe8:	83 c4 0c             	add    esp,0xc
  4bbfeb:	89 1e                	mov    DWORD PTR [esi],ebx
  4bbfed:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4bbff0:	83 f8 03             	cmp    eax,0x3
  4bbff3:	73 04                	jae    0x4bbff9
  4bbff5:	33 c0                	xor    eax,eax
  4bbff7:	eb 06                	jmp    0x4bbfff
  4bbff9:	83 c0 fd             	add    eax,0xfffffffd
  4bbffc:	c1 e8 03             	shr    eax,0x3
  4bbfff:	85 c0                	test   eax,eax
  4bc001:	74 2a                	je     0x4bc02d
  4bc003:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4bc006:	83 c6 07             	add    esi,0x7
  4bc009:	8b f8                	mov    edi,eax
  4bc00b:	eb 09                	jmp    0x4bc016
  4bc00d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4bc010:	8b 0d a0 1a fe 00    	mov    ecx,DWORD PTR ds:0xfe1aa0
  4bc016:	0f b7 46 fe          	movzx  eax,WORD PTR [esi-0x2]
  4bc01a:	0f b7 56 fc          	movzx  edx,WORD PTR [esi-0x4]
  4bc01e:	50                   	push   eax
  4bc01f:	52                   	push   edx
  4bc020:	8b 16                	mov    edx,DWORD PTR [esi]
  4bc022:	e8 39 c6 04 00       	call   0x508660
  4bc027:	83 c6 08             	add    esi,0x8
  4bc02a:	4f                   	dec    edi
  4bc02b:	75 e3                	jne    0x4bc010
  4bc02d:	68 49 42 0f 00       	push   0xf4249
  4bc032:	e8 99 ea 0c 00       	call   0x58aad0
  4bc037:	83 c4 04             	add    esp,0x4
  4bc03a:	5f                   	pop    edi
  4bc03b:	5e                   	pop    esi
  4bc03c:	33 c0                	xor    eax,eax
  4bc03e:	5b                   	pop    ebx
  4bc03f:	8b e5                	mov    esp,ebp
  4bc041:	5d                   	pop    ebp
  4bc042:	c2               	ret    0xc
```

### Square 0x68 inbox handler：`0x4BC050..0x4BC14B`

```asm
  4bc050:	55                   	push   ebp
  4bc051:	8b ec                	mov    ebp,esp
  4bc053:	83 e4 f8             	and    esp,0xfffffff8
  4bc056:	83 ec 14             	sub    esp,0x14
  4bc059:	53                   	push   ebx
  4bc05a:	56                   	push   esi
  4bc05b:	8b 35 88 1a fe 00    	mov    esi,DWORD PTR ds:0xfe1a88
  4bc061:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4bc064:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  4bc067:	57                   	push   edi
  4bc068:	3b ca                	cmp    ecx,edx
  4bc06a:	74 1d                	je     0x4bc089
  4bc06c:	8b c2                	mov    eax,edx
  4bc06e:	3b d2                	cmp    edx,edx
  4bc070:	74 14                	je     0x4bc086
  4bc072:	8b 38                	mov    edi,DWORD PTR [eax]
  4bc074:	89 39                	mov    DWORD PTR [ecx],edi
  4bc076:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  4bc079:	89 79 04             	mov    DWORD PTR [ecx+0x4],edi
  4bc07c:	83 c0 08             	add    eax,0x8
  4bc07f:	83 c1 08             	add    ecx,0x8
  4bc082:	3b c2                	cmp    eax,edx
  4bc084:	75 ec                	jne    0x4bc072
  4bc086:	89 4e 0c             	mov    DWORD PTR [esi+0xc],ecx
  4bc089:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4bc08c:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4bc090:	89 46 18             	mov    DWORD PTR [esi+0x18],eax
  4bc093:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4bc096:	83 f8 03             	cmp    eax,0x3
  4bc099:	73 04                	jae    0x4bc09f
  4bc09b:	33 c0                	xor    eax,eax
  4bc09d:	eb 05                	jmp    0x4bc0a4
  4bc09f:	83 c0 fd             	add    eax,0xfffffffd
  4bc0a2:	d1 e8                	shr    eax,1
  4bc0a4:	85 c0                	test   eax,eax
  4bc0a6:	0f 84 9d 00 00 00    	je     0x4bc149
  4bc0ac:	83 c1 03             	add    ecx,0x3
  4bc0af:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4bc0b3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4bc0b7:	eb 0d                	jmp    0x4bc0c6
  4bc0b9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4bc0c0:	8b 35 88 1a fe 00    	mov    esi,DWORD PTR ds:0xfe1a88
  4bc0c6:	0f b6 39             	movzx  edi,BYTE PTR [ecx]
  4bc0c9:	0f b6 59 01          	movzx  ebx,BYTE PTR [ecx+0x1]
  4bc0cd:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4bc0d0:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  4bc0d4:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  4bc0d8:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  4bc0dc:	3b c8                	cmp    ecx,eax
  4bc0de:	73 37                	jae    0x4bc117
  4bc0e0:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4bc0e3:	8d 54 24 18          	lea    edx,[esp+0x18]
  4bc0e7:	3b ca                	cmp    ecx,edx
  4bc0e9:	77 2c                	ja     0x4bc117
  4bc0eb:	8b fa                	mov    edi,edx
  4bc0ed:	2b f9                	sub    edi,ecx
  4bc0ef:	c1 ff 03             	sar    edi,0x3
  4bc0f2:	3b 46 10             	cmp    eax,DWORD PTR [esi+0x10]
  4bc0f5:	75 08                	jne    0x4bc0ff
  4bc0f7:	8d 4e 08             	lea    ecx,[esi+0x8]
  4bc0fa:	e8 81 d0 07 00       	call   0x539180
  4bc0ff:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4bc102:	85 c0                	test   eax,eax
  4bc104:	74 2a                	je     0x4bc130
  4bc106:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4bc109:	8b 14 f9             	mov    edx,DWORD PTR [ecx+edi*8]
  4bc10c:	89 10                	mov    DWORD PTR [eax],edx
  4bc10e:	8b 4c f9 04          	mov    ecx,DWORD PTR [ecx+edi*8+0x4]
  4bc112:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4bc115:	eb 19                	jmp    0x4bc130
  4bc117:	3b 46 10             	cmp    eax,DWORD PTR [esi+0x10]
  4bc11a:	75 08                	jne    0x4bc124
  4bc11c:	8d 4e 08             	lea    ecx,[esi+0x8]
  4bc11f:	e8 5c d0 07 00       	call   0x539180
  4bc124:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4bc127:	85 c0                	test   eax,eax
  4bc129:	74 05                	je     0x4bc130
  4bc12b:	89 38                	mov    DWORD PTR [eax],edi
  4bc12d:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  4bc130:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4bc134:	83 46 0c 08          	add    DWORD PTR [esi+0xc],0x8
  4bc138:	83 c1 02             	add    ecx,0x2
  4bc13b:	ff 4c 24 14          	dec    DWORD PTR [esp+0x14]
  4bc13f:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4bc143:	0f 85 77 ff ff ff    	jne    0x4bc0c0
  4bc149:	68 4a          	push   0xf424a
```

### Expedition scene handler table：`0x4C14AE..0x4C1508`

```asm
  4c14ae:	68 a8 5e 00 00       	push   0x5ea8
  4c14b3:	88 42 15             	mov    BYTE PTR [edx+0x15],al
  4c14b6:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c14bc:	57                   	push   edi
  4c14bd:	50                   	push   eax
  4c14be:	c7 05 74 a6 d6 00 44 	mov    DWORD PTR ds:0xd6a674,0x45585044
  4c14c5:	50 58 45 
  4c14c8:	e8 93 d3 3d 00       	call   0x89e860
  4c14cd:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c14d2:	89 86 00 61 00 00    	mov    DWORD PTR [esi+0x6100],eax
  4c14d8:	89 86 f0 61 00 00    	mov    DWORD PTR [esi+0x61f0],eax
  4c14de:	83 c4 0c             	add    esp,0xc
  4c14e1:	c7 86 fc 60 00 00 d0 	mov    DWORD PTR [esi+0x60fc],0x4c21d0
  4c14e8:	21 4c 00 
  4c14eb:	c7 86 ec 61 00 00 f0 	mov    DWORD PTR [esi+0x61ec],0x4c21f0
  4c14f2:	21 4c 00 
  4c14f5:	8b c6                	mov    eax,esi
  4c14f7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c14fa:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c1501:	59                   	pop    ecx
  4c1502:	5f                   	pop    edi
  4c1503:	5e                   	pop    esi
  4c1504:	8b e5                	mov    esp,ebp
  4c1506:	5d                   	pop    ebp
  4c1507:	c2               	ret    0x4
```

### Expedition S2C 0x68 inbox handler：`0x4C21F0..0x4C22B5`

```asm
  4c21f0:	55                   	push   ebp
  4c21f1:	8b ec                	mov    ebp,esp
  4c21f3:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c21f6:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4c21fa:	8b 15 88 1a fe 00    	mov    edx,DWORD PTR ds:0xfe1a88
  4c2200:	89 42 18             	mov    DWORD PTR [edx+0x18],eax
  4c2203:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c2206:	83 ec 08             	sub    esp,0x8
  4c2209:	83 f8 03             	cmp    eax,0x3
  4c220c:	73 04                	jae    0x4c2212
  4c220e:	33 c0                	xor    eax,eax
  4c2210:	eb 05                	jmp    0x4c2217
  4c2212:	83 c0 fd             	add    eax,0xfffffffd
  4c2215:	d1 e8                	shr    eax,1
  4c2217:	85 c0                	test   eax,eax
  4c2219:	0f 84 92 00 00 00    	je     0x4c22b1
  4c221f:	53                   	push   ebx
  4c2220:	83 c1 03             	add    ecx,0x3
  4c2223:	56                   	push   esi
  4c2224:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c2227:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  4c222a:	57                   	push   edi
  4c222b:	eb 03                	jmp    0x4c2230
  4c222d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c2230:	0f b6 39             	movzx  edi,BYTE PTR [ecx]
  4c2233:	0f b6 59 01          	movzx  ebx,BYTE PTR [ecx+0x1]
  4c2237:	8b 35 88 1a fe 00    	mov    esi,DWORD PTR ds:0xfe1a88
  4c223d:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4c2240:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4c2243:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4c2246:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4c2249:	3b c8                	cmp    ecx,eax
  4c224b:	73 36                	jae    0x4c2283
  4c224d:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4c2250:	8d 55 f8             	lea    edx,[ebp-0x8]
  4c2253:	3b ca                	cmp    ecx,edx
  4c2255:	77 2c                	ja     0x4c2283
  4c2257:	8b fa                	mov    edi,edx
  4c2259:	2b f9                	sub    edi,ecx
  4c225b:	c1 ff 03             	sar    edi,0x3
  4c225e:	3b 46 10             	cmp    eax,DWORD PTR [esi+0x10]
  4c2261:	75 08                	jne    0x4c226b
  4c2263:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c2266:	e8 15 6f 07 00       	call   0x539180
  4c226b:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4c226e:	85 c0                	test   eax,eax
  4c2270:	74 2a                	je     0x4c229c
  4c2272:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4c2275:	8b 14 f9             	mov    edx,DWORD PTR [ecx+edi*8]
  4c2278:	89 10                	mov    DWORD PTR [eax],edx
  4c227a:	8b 4c f9 04          	mov    ecx,DWORD PTR [ecx+edi*8+0x4]
  4c227e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4c2281:	eb 19                	jmp    0x4c229c
  4c2283:	3b 46 10             	cmp    eax,DWORD PTR [esi+0x10]
  4c2286:	75 08                	jne    0x4c2290
  4c2288:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c228b:	e8 f0 6e 07 00       	call   0x539180
  4c2290:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4c2293:	85 c0                	test   eax,eax
  4c2295:	74 05                	je     0x4c229c
  4c2297:	89 38                	mov    DWORD PTR [eax],edi
  4c2299:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  4c229c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c229f:	83 46 0c 08          	add    DWORD PTR [esi+0xc],0x8
  4c22a3:	83 c1 02             	add    ecx,0x2
  4c22a6:	ff 4d 0c             	dec    DWORD PTR [ebp+0xc]
  4c22a9:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c22ac:	75 82                	jne    0x4c2230
  4c22ae:	5f                   	pop    edi
  4c22af:	5e                   	pop    esi
  4c22b0:	5b                   	pop    ebx
  4c22b1:	33 c0                	xor    eax,eax
  4c22b3:	8b e5                	mov    esp,ebp
```

### Square state/reset：`0x66FC52..0x66FC7C`

```asm
  66fc52:	a1 a0 1a fe 00       	mov    eax,ds:0xfe1aa0
  66fc57:	53                   	push   ebx
  66fc58:	c6 40 20 01          	mov    BYTE PTR [eax+0x20],0x1
  66fc5c:	c7 40 18 00 00 00 00 	mov    DWORD PTR [eax+0x18],0x0
  66fc63:	e8 e8 fa ff ff       	call   0x66f750
  66fc68:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  66fc6c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66fc73:	59                   	pop    ecx
  66fc74:	5f                   	pop    edi
  66fc75:	5e                   	pop    esi
  66fc76:	5b                   	pop    ebx
  66fc77:	8b e5                	mov    esp,ebp
  66fc79:	5d                   	pop    ebp
  66fc7a:	c3                   	ret
  66fc7b:	90                   	nop
```


## 8. 來源修正與外部證據界線

E65 只確認 `CSquare` vtbl+0x10 的 *entry target* `0x4BBC10`，沒有展開其後面的 C2S43；本篇補完整生產者，**不改寫 E65 原稿**。E63 已把 0x47B5C0 所屬 ScenarioReview RTTI 反證記錄，仍不當選角首次進世界。此篇所有原始指令為本輪直接提取，不以先前筆記當新 bytes 驗證。沒有使用原版 Client 運行、Server 程式或擷取記錄，不能宣稱 request42 的官方 reply。
