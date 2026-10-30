# E67 — RR-0002：KR Client 選角訊息與 Square 實際後續封包界線、原版 Server 回覆配對證據阻塞記錄

**日期** 2026-10-30 Asia/Taipei；**研究者** `chatgpt-web roy`；**唯一工作分支** `extra/roy1`，不得另開分支。來源 `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。BIN-first 離線靜態，只使用原始 PE bytes／GNU objdump 和 GitHub 既有有界筆記，沒有執行 KR Client、沒有原版 Server、沒有原版成功選角 pcap。保存 E61～E66 全文，不覆寫；不宣稱 T01 FULL-PASS、S00 ACCEPTED、SPEC STABLE 或可玩。

## 1. RR 原題與完成條件逐一判定

`RR-0002` 原題：Which C2S selection fields and S2C reply fields/order does original Client require? Preserve unknown values; reuse T02/T04 contracts. `GAP-CHAR-0001` completion：command2 header fields, role record authority/initialization, actual selection request+responses and scene transition with scoped evidence and relevant Client tests.

| acceptance 子目標 | 2026-10-30 直接證據/來源 | 能否作有界 Client 契約 | 剩餘必要證據 |
|---|---|---|---|
| C2S selection request | N：0x4A3B80 本地 `42 00 XX YY`，4B，FBA798==0 才 vtable+10(slot0,buf,len4)；UI caller 0x5F47F5/0x5F48F7/0x673EAA | 是，列條件、來源與 ID domain 仍未知 | 官方角色選擇政策由 Server 自行設計；不能把 XX 當永久角色 ID |
| S2C roster / role flag | N：first-level cmd2→0x4B7F00；header65B，+53B records；0x4D4150 對合格角色索引寫 record+5C=1 | 是，需有效資源與完整記錄/字串終止 | T04 角色權威初值、總資料實作與 UI 資源 |
| S2C selection success/error reply identity and fields | 靜態 Client 正向找到 S2C 0x42→0x4B2190、0x43→0x4B1A90，都是**其他 local effects**；另 S2C0x69/7 有 CSquare scene effect；沒有證據證明哪一個是原版 Server 對 C2S42 的 response | **無法宣稱官方配對/結果成功或拒絕** | 可信的原版 Server capture 或 Server side protocol/source、可再查的原生 Client response-state writer 新證據 |
| Scene transition | N：S2C69/7→0x4B9090→CSquare ctor 0x4BBB70→0x4B7D50→CSquare virtual+10 0x4BBC10 | 是，僅作具條件的 scene switch，可獨立測試 | 何時、因何交易發 S2C69；C2S42 的 Server 是否批准與場景資料有效性 |
| Client-side subsequent response | N：CSquare entry `0x4BBC10` → `C2S 43 00 XX 0A` len4，`XX=CSquareUserData+18`；用戶操作 index setter `0x508970` 也會再送 C2S43 | 是，列 FBA798 gate、Tx enqueue vs wire | C2S43 原版 Server service/ack、實際 socket/key、runtime ordering |
| Scene-specific inbound messages | N：CSquare handler 0x68→0x4BC050（ChannelState），0x6A→0x4BBFA0（UserData/count/records/F4249），0x6B→0x4BBAE0；Expedition 0x68→0x4C21F0 | 是，僅在 active scene 有該槽/條件成立時 | 官方何時送/是否選角初始化、runtime 及最短完整 schema |

**整體判定：Client 可獨立驗證的相容性接口有實質新閉合，但『原版 Server 對 C2S42 的實際 reply opcode/fields/sequence』的必要正向來源仍不存在。本研究者不能改寫 RR 原題或自行宣布完整達標。**

## 2. 新的封包方向反證，避免誤用同命令整數

- C2S `0x0042` / len4：`0x4A3B80`，本地選角／入口 UI request；沒有本函式內的 request-ID matching table/store，也不追蹤 socket write success。
- **C2S `0x0043` / len4**：`0x4BBC10` Square entry、`0x4BB7CF` 另一 producer、`0x508970` index setter；都是 `43 00 index 0A`。其中 index 來自 `CSquareUserData+18`，不是 C2S42 直接拷貝。
- S2C `0x0043`：first-level fallback/base scene `0x4B1A90` 處理物件清理；並**沒有**因為同為 0x43 而變成上述 C2S43 的入站回覆或選角批准。
- S2C `0x0042`：base scene `0x4B2190` 處理本地 review/list（E62/E63 已有 RTTI 反證）；不是足以命名為選角成功的證據。
- S2C `0x0069 subtype7`：建立 CSquare，產生的**下一筆本地 candidate C2S43** 需滿足 manager/ctor/entry/Tx gate，跨 socket 的真正順序由原版 trace 決定。
- S2C `0x0068/0x006A`：只有在活躍 CSquare 場景內，才有此次列出的專用 handler；它們不是全域角色清單 command2，也不是選角結果代號的證明。

## 3. 新增 native 證據驗證矩陣：兩個 Singleton 絕不能合併

| Global variable | native vptr / RTTI | init/owner | 重要欄位或 consumer |
|---|---|---|---|

| `FE1AA0` | `0xC0DDA4`, `.?AVCSquareUserData@@`; COL `0xC6B8E0` TypeDescriptor `0xF7EEEC` | 0x506BBE | +18 current UI index, +1C count; 0x4BBC10 and 0x508970 form C2S43 |

| `FE1A88` | `0xC0DD84`, `.?AVCSquareChannelState@@`; COL `0xC6B834` TypeDescriptor `0xF7EE98` | 0x506C0F | +18/+1C set by S2C69 payload+3/+4; 0x68 in Square uses +18 from its own payload+2 |


原生 `0x506BBE` 分配/寫 `FE1AA0`；`0x506C0F` 寫的是 `FE1A88`。它們是兩個不同類別、不同的 data global pointer。從 `.text` 直接 4-byte immediate 搜尋，對 `FE1AA0` 具有多個讀與寫（0x506BBE 初始化、0x50863E 清除、0x66FC53 `+18=0`），而 `FE1A88` 有自身另一路初始化與寫入。此掃描只能界定 direct refs，不能排除所有間接 alias；本案不以直接 xref 陰性作全程不存在之證明。

## 4. 全域 scene 切換有其他入口；0x69/7 不是唯一進場路徑的反證

對 `.text` 靜態掃描 E8 rel32 指向 `0x4B7D50`，在 raw bytes 內找到下列**候選 CALL 指令位置**（逐個未必都具相同呼叫語意，勿把 xref 數量當實際事件次數）：

`0x48F73C`, `0x49535F`, `0x4B9031`, `0x4B90FD`, `0x4B9147`, `0x4B9154`, `0x4B9179`, `0x4B91AD`, `0x4B92C5`, `0x4B93A5`, `0x4B9495`, `0x4B9562`, `0x4B97F0`, `0x4B993C`, `0x4B9B36`, `0x4B9BF6`, `0x4B9CC6`, `0x4B9DB5`, `0x4C2FD0`.


已定向反組譯確認的相關直接呼叫有 `0x4B9031` (S2C60)、`0x4B90FD` (S2C69 subtype7)、`0x4B9147` (subtype21)、`0x4B9179` (subtype23)、`0x4B91AD` (subtype24)，還有另一組場景／網路處理呼叫者。只有 E8 callsite 並不能證明當時已成功選角，更沒有原版 Server 何時送 packet 的動態資訊。

`0x4B7D50` 在進入新場景前先對舊場景呼叫 vtable+0x14 與 vtable+0（清除），再寫 scene manager+0x5EAC，最後對新物件呼叫 vtable+0x10。這是 Client scene lifecycle，不是登入回覆配對。此函式對 NULL EDI 呼叫 error logger 後沒有立即 return，不能假設無效 scene 安全恢復。

## 5. Client-first 可重現的合成測試規劃（無 runtime）

本輪只驗原始機器碼、不執行 Client：

1. 驗 `0x4A3B91` 原始 `b8 42`、`0x4A3BAD..4A3BB5` 的 `push 4 / ptr / slot0 / vcall`。
2. 驗 `0x4BBE86..4BBEB1` 建構 `43 00 index 0A`，並以非零 FBA798 跳過 enqueue。
3. 驗 `0x5089B0..5089D7` 有第二 producer，index>=count 時跳出，合法時同樣 enqueue `0x43`，但沒有發送成功回報。
4. 驗 `0x4BBBDB/EB` 的 CSquare scene table `+0x61EC/+0x61FC/+0x6204` 各對應 index0x68/0x6A/0x6B；`0x4C14E1/EB` 的 Expedition scene index0x4A/0x68 則是不同函式。
5. 測試分成「合成 Server 送有效 S2C69/7 → Client 是否產生 C2S43」、「在 Square scene 收 S2C6A/68 → 列表/狀態是否更新」與「壞 subtype 資源／錯誤碼」；**沒有官方 Server trace 的情況下，合成結果不可當原版官方 wire sequence**。
6. 錯誤與失敗路徑必須測試主動無效 frame、短 payload 與資源失敗。S2C69 已先讀 payload+2，不能因測試碼能構造5B payload便宣稱 Client 任意短包安全。Square enter C2S43 受 FBA798 等態，parser/lane/Conn 仍依 T02。

## 6. 原版 Server 回覆無法推得：可操作的解除阻塞條件

原版成功選角／拒絕序列的正向證據至少需要下列一組：

**A. 原版 wire capture（首選）**：同一版本 KR Client 的全程 key0/key1/key2 交易，標註選角按鈕時間、C2S42 的 XX/YY、所有後續 S2C app command/marker、完整 body/status、玩家是否進到 Square/Expedition／失敗 UI、以及同一時間的其他 Client C2S（尤其 C2S43）。解碼及 slot 必須可重算，避免把單一封包當 request-reply。

**B. 原版 Server 協定/處理器原始碼或可驗證反組譯**：可證 C2S42 handler 如何選 success/error reply、資料欄位、交易順序與拒絕 policy；仍需 Client handler/scene gate 核對。

**C. 新 Client 原生正向證據**：若能找到尚未查到的 selected role writer／response-state coupling，須有原始 BIN 指令、上游 caller/具體資料來源、與 0x4A3B80 的因果條件；不能單憑命令數值附近（42→43）或場景名字猜出官方 pairing。

上述 A、B 無法從現有靜態 Client BIN 憑空產生；C 仍可繼續查，但目前關鍵候選 S2C42/43、S2C69、C2S42/43、SceneReview 以及 Square data 已逐一以第一手原件定向驗證，**沒有正向配對證據**。若 S00 要改為只驗 Client 相容接口，須由 S00 更改或拆分完成標準、並明確保存原版成功/拒絕回覆未知，新 RR 才能分派；研究者不可自行改動。

若沒有 A/B/C 新證據，按 02 研究規則應以 **RR-0002 BLOCKED（具解除條件）** 回報，而不是以 E66 新發現或原稿篇幅作為完成標準。T01 可先限定審查 E61–E67 的 Client facts，但這不等於 RR 本身已 ACCEPTED。

## 7. Native Bytes/Disassembly Appendix（前次未存的關鍵邊緣）

### C2S 0x42 和鄰接 C2S 0x44，兩條並非 S2C ACK — VA `0x4A3B80..0x4A3BEF`

```asm
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2 08 00             	ret    0x8
  4a3bbd:	cc                   	int3
  4a3bbe:	cc                   	int3
  4a3bbf:	cc                   	int3
  4a3bc0:	55                   	push   ebp
  4a3bc1:	8b ec                	mov    ebp,esp
  4a3bc3:	51                   	push   ecx
  4a3bc4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3bcb:	b8 44 00 00 00       	mov    eax,0x44
  4a3bd0:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a3bd4:	75 15                	jne    0x4a3beb
  4a3bd6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3bdc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a3bde:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a3be1:	6a 02                	push   0x2
  4a3be3:	8d 45 fe             	lea    eax,[ebp-0x2]
  4a3be6:	50                   	push   eax
  4a3be7:	6a 00                	push   0x0
  4a3be9:	ff d2                	call   edx
  4a3beb:	8b e5                	mov    esp,ebp
  4a3bed:	5d                   	pop    ebp
  4a3bee:	c3                   	ret
```

### scene manager actual vptr+0x10 entry — VA `0x4B7D50..0x4B7DC0`

```asm
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```

### app 0x69 subtype branch body + state writers — VA `0x4B90BC..0x4B9217`

```asm
  4b90bc:	8b d9                	mov    ebx,ecx
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
```

### CSquare ctor table patching — VA `0x4BBBA0..0x4BBC0C`

```asm
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

### CSquare entry 0x43 local producer — VA `0x4BBE5F..0x4BBEB3`

```asm
  4bbe5f:	01 8b 15 a0 1a fe    	add    DWORD PTR [ebx-0x1e55feb],ecx
  4bbe65:	00 8b 5a 18 75 14    	add    BYTE PTR [ebx+0x1475185a],cl
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
  4bbeb1:	f6 05      	test   BYTE PTR ds:0xfb7c14,0x1
```

### CSquare current index update C2S43 — VA `0x508970..0x5089DA`

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
  5089d9:	c2               	ret    0x4
```

### CExpedition app 0x68 scene table assignment — VA `0x4C14DE..0x4C1508`

```asm
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

### CSquare specific command 0x6A payload and event — VA `0x4BBFA0..0x4BC043`

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

### CSquare specific command 0x68 payload — VA `0x4BC050..0x4BC14B`

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


## 8. 研究交付鏈、責任分離與最終判定

- E61 (blob `fc1d4845b3e1647a963e07b0838e05108e4218ca`): C2S42/roster C2S/S2C and candidate negative audit。
- E62 (blob `88ebd073cc14f2dee47d712ce9086346b8f62ace`): inbound 42/43 local effects, previous scene caller negative audit。
- E63 (blob `3232b05dbc0d3878aeae206bc84f5726bf2b93bf`): native RTTI ScenarioReview UI counterexample。
- E64 (blob `715636b667f47e42a31d50590ffd39d75e93f4b7`): app S2C60/69/5F and real CExpedition/CSquare native scene。
- E65 (blob `38b224caa99a3c2c9dc0b797f00b5cd16a790fda`): CSquare vtbl+0x10 entry, raw subtype tables。
- E66 (Git blob to verify separately): Square local outgoing C2S43 and active scene 0x68/6A handlers with native RTTI。
- E67 本篇：Client/static bounded acceptance matrix and exact unblock evidence; submit for S00 disposition only as BLOCKED if no actual original reply proof。

**Client 待逆向**：真實選角 reply-state writer／選擇 index 到 avatar identity 的關聯若另有原生證據，應在同一 RR 恢復後追查。**Server 待開發**：新 Server 的角色授權/重試、成功與失敗策略，但不能冒稱官方。**跨功能待整合**：T02/T04/T05/T06 的界面。**待遊玩驗證**：可重現合成 Client compatibility tests 和原版 pcap 比較。最終不宣稱 RR 完成或遊戲可玩。
