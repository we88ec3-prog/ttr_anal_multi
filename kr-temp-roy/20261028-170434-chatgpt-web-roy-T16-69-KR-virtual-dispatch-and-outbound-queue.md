# KR T16-69 — Scenario 4-byte message 的具體 virtual target 與出站佇列

- 日期：2026-10-28T17:04:34+08:00；研究員：chatgpt-web roy；僅 KR；未執行／修改二進位檔。
- BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，大小 `12472320`。
- EXE SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `objdump -h` `.text` VA `0x00401000`, raw `0x400`；`.rdata` VA `0x00BD2000`, raw `0x007D0600`；`.data` VA `0x00D61000`, raw `0x0095E800`。`.text` raw=`VA-0x400C00`，`.rdata` raw=`VA-0x401A00`；不得跨 section 混用。
- GitHub `main` 本次只讀 `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、T16 README/task.json、T16-66/T16-68；未 commit/push。GitHub 主資料內容是導航與前段證據，不當作本輪 BIN 已驗證的替代。

## 新發現與證據分級

**原生已確認 A**：全域 `[0x00FBA854]` 存入的物件於建構時 vptr=`0x00C51748`（`0x8046F7: mov dword [esi],0xC51748`，`0x80470F: mov [0xFBA854],ecx`）；上游分配 `push 0x5C`，呼叫 `0x803D60` 初始化，緊接著以 vtable +8 間接初始化呼叫。注意另有兩個清理位置 `0x803F76` 和 `0x8045EE`；後者先在非 null 時呼叫 vtable[0] 並歸零。因此原先無法確認動態目標的問題在此初始化路徑上已解開，但不排除其他初始化路徑／未知替換者。

**原生已確認 B**：在 `.rdata` `0x00C51748` 讀到 vtable pointer 順序：`0x806670, 0x806CF0, 0x806850, 0x8068B0, 0x8069A0, 0x806A00, 0x806AD0, 0x806F60, 0x806F80, 0x806FC0, 0x807090`。因此 vtable byte offset `+0x10` 精確落於 `0x008069A0`。此 vtable 位址 raw `0x0084FD48`、`+0x10` raw `0x0084FD58`；函式 raw=`0x00405DA0`。

**原生已確認 C**：`0x8069A0` 以第一參數（場景 producer 此處為 0）在 `[this+0x18]` 容器中查找節點；找到且 node `+0x10` 指標有效、第三參數非零時，把第二參數 buffer 與第三參數 length 轉交 `0x8060D0`。producer `0x004AA4D0` 供 `0, &{0x0040,u16(value)}, 4`。`0x8069D4`–`0x8069EB` 保持 caller buffer pointer、length，不重新解析為 Quest ID。查找失敗或 length=0 時的返回路徑不進此複製函式。

**原生已確認 D**：`0x8060D0` 接收長度 (`[ebp+0x0C]`) 與指標 (`[ebp+0x08]`)：先檢查 `[esi+0xA0A4]` 是否超過 `0x12C`，超過即 return 0；否則取緩衝節點 `0x807470`，若 `len<=0x1000`，以 `0x89DBD0` 複製至 `[node+8]` 並令 `[node+4]=len`，再以 `0x806060` 將 node 追加至 `[esi+0xA074]` 鏈表並設 `[esi+0xA024]=1`。`0x806060` 的鏈表更新、鎖操作與設 flag 是佇列存在的第一手證據；不能僅靠此認定 OS socket 已傳輸。

**部分確認**：`[0xFBA854]` object / `[this+0x18]` key map / 目標 connection pointer 的具體語意仍為暫定；`0x8060D0` 的 `0x12C` 比較只是物件欄位 gate，不可解釋為封包長度門檻。`0x1000` 是此複製分支上限，不等於整體 wire payload 最大值；大於上限的路徑仍會入列，需要單獨核實規格。

**unknown**：`0x806060` 之後由哪個 worker 消費 `[+0xA074]` 出站佇列、是否經 framing/encryption 到 `send`/`WSASend`；`0x0040` 何時變為實際 wire opcode；Server 是否 ACK；Quest16/15 變化與 S→C handler。不能推定原版 server 內部完成／保存規則。

## 記憶體與分支資料流

```text
Lua RequestStartScenario (前段已確認，T16-65/66/68)
    → 0x004AA4D0: uint16_t tag=0x0040; uint16_t value=(uint16_t)input
    → gate [0xFBA798]==0
    → object [0xFBA854] (初始化路徑 0x80470F 指向 vptr=0xC51748)
    → vptr[4] == 0x8069A0(0, buffer, 4)
    → lookup key=0 in this+0x18 container
         ↳ not found / null value: return 0 (no queue proof)
         ↳ len == 0: return 1 (no queue proof)
         ↳ found and len>0: 0x8060D0(connection, buffer, len)
              ↳ [connection+0xA0A4] > 300: return 0
              ↳ 0x807470 alloc/acquire outbound node
              ↳ len<=4096: memcpy(node+8,buf,len); node+4=len
              ↳ 0x806060 append [connection+0xA074]; [connection+0xA024]=1
              ↳ [socket writer not yet identified]
```

## 有界 C++ 偽碼（非官方型別）

```cpp
int CandidateDispatch::method4(uint32_t channel, const void* bytes, uint32_t len) {
  auto connection = lookup(this->map_at_0x18, channel);
  if (!connection) return 0;
  if (len == 0) return 1;
  return enqueue_candidate(connection, bytes, len);
}
int enqueue_candidate(Conn* c, const void* bytes, uint32_t n) {
  if (c->field_A0A4 > 300) return 0;
  Node* node = acquire_node();
  if (n <= 0x1000) { copy(node->data8, bytes, n); node->length4=n; }
  append_list(c->list_A074, node);
  c->flag_A024 = 1;
  return 1;
}
```

以上 `Node/Conn`、`map`、`copy`、`append_list` 都是推導命名。`0x806060` 使用 `esi` 非標準顯式 thiscall register，需要按 call site 保留實際暫存器與呼叫約定，不可直接照偽碼編譯。

## 玩家情境 × C→S/S→C 證據矩陣

| 玩家情境 | 本地 gate | C→S 已證實 | S→C | Client Quest/NPC/UI | Server 待開發 |
|---|---|---|---|---|---|
| Lua 發 `RequestStartScenario(n)` | `[FBA798]==0`；channel0 lookup 有效；非零 len；後端 queue count gate | `40 00 nn nn` 進入 local outbound queue（有條件）；**正式 wire opcode unknown** | unknown | unknown | 解譯/回覆待配對；不能推定官方接受規則 |
| 教學關卡完成 | unknown | unknown | unknown | unknown | 依實際 client consumer 另行制定完成通知 |
| Quest16 完成、Quest15 變可接 | unknown | unknown | unknown | unknown | Quest 解鎖／狀態更新介面待查，不等於官方內部算法 |
| 玩家點擊接 Quest15 | unknown | unknown | unknown | unknown | 接受／拒絕接口待第一手封包證據 |
| 重登恢復 | unknown | unknown | unknown | unknown | P2；登入 snapshot／保存方向待查 |

## 三輪門檻與停止原因

- **T16-69（第1輪）已達重大新發現門檻**：解決前段確切 virtual target 未知問題，完成 `0x004AA4D0 → [0xFBA854] vtable+0x10 → 0x8069A0 → 0x8060D0 → 0x806060` 的可驗證有界 local queue 路徑；故第 2 輪 `T16-69-2`、第 3 輪 `T16-69-3` **未啟動**，不是以 xref 數量充數。
- **這不代表完整網路封包／S→C 關閉**，後續 T16-70 應優先 `0x8061A0` queue consumer、`0x806AD0` read side、對 T02 socket writer；從 socket receive 反向定位 Quest/NPC handler；以及 NPC quest acceptance C→S。
- 跨 Task 只讀、不修改 T02/T07/T14/T15。沒有使用者明確要求，本輪沒有 commit/push。

## 原生 assembly 附錄（BIN objdump，精確地址範圍）

### 全域指標初始化與物件 vptr (`0x008046d7`–`0x00804717`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008046d7 <.text+0x4036d7>:
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
```

### 全域指標的釋放與清零 (`0x008045dc`–`0x008045f4`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008045dc <.text+0x4035dc>:
  8045dc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8045e2:	3b cb                	cmp    ecx,ebx
  8045e4:	74 0e                	je     0x8045f4
  8045e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  8045e8:	8b 02                	mov    eax,DWORD PTR [edx]
  8045ea:	6a 01                	push   0x1
  8045ec:	ff d0                	call   eax
  8045ee:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
```

### 另一個清理位置 (`0x00803f59`–`0x00803f7c`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00803f59 <.text+0x402f59>:
  803f59:	8b 57 50             	mov    edx,DWORD PTR [edi+0x50]
  803f5c:	6a ff                	push   0xffffffff
  803f5e:	52                   	push   edx
  803f5f:	c7 47 4c 01 00 00 00 	mov    DWORD PTR [edi+0x4c],0x1
  803f66:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  803f6c:	8b 47 50             	mov    eax,DWORD PTR [edi+0x50]
  803f6f:	50                   	push   eax
  803f70:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  803f76:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
```

### 虛方法目標 (`0x008069a0`–`0x008069f6`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

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
  8069f3:	c2 0c 00             	ret    0xc
```

### 下游封包資料複製與佇列入口 (`0x008060f5`–`0x00806191`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008060f5 <.text+0x4050f5>:
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2 08 00             	ret    0x8
```

### 佇列節點插入 (`0x00806060`–`0x008060ce`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00806060 <.text+0x405060>:
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2 04 00             	ret    0x4
```

### 緩衝配置入口 (`0x00807470`–`0x008074df`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00807470 <.text+0x406470>:
  807470:	55                   	push   ebp
  807471:	8b ec                	mov    ebp,esp
  807473:	8b 47 28             	mov    eax,DWORD PTR [edi+0x28]
  807476:	83 ec 10             	sub    esp,0x10
  807479:	53                   	push   ebx
  80747a:	56                   	push   esi
  80747b:	50                   	push   eax
  80747c:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807482:	83 7f 1c 00          	cmp    DWORD PTR [edi+0x1c],0x0
  807486:	0f 85 8d 00 00 00    	jne    0x807519
  80748c:	33 db                	xor    ebx,ebx
  80748e:	8b ff                	mov    edi,edi
  807490:	68 0c 10 00 00       	push   0x100c
  807495:	e8 ce 9d 08 00       	call   0x891268
  80749a:	8b f0                	mov    esi,eax
  80749c:	33 c0                	xor    eax,eax
  80749e:	83 c4 04             	add    esp,0x4
  8074a1:	3b f0                	cmp    esi,eax
  8074a3:	74 1f                	je     0x8074c4
  8074a5:	68 00 10 00 00       	push   0x1000
  8074aa:	50                   	push   eax
  8074ab:	8d 4e 08             	lea    ecx,[esi+0x8]
  8074ae:	51                   	push   ecx
  8074af:	89 06                	mov    DWORD PTR [esi],eax
  8074b1:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  8074b4:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8074ba:	e8 a1 73 09 00       	call   0x89e860
  8074bf:	83 c4 0c             	add    esp,0xc
  8074c2:	eb 02                	jmp    0x8074c6
  8074c4:	33 f6                	xor    esi,esi
  8074c6:	8b 47 2c             	mov    eax,DWORD PTR [edi+0x2c]
  8074c9:	8d 50 01             	lea    edx,[eax+0x1]
  8074cc:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  8074cf:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8074d5:	8d 45 fc             	lea    eax,[ebp-0x4]
  8074d8:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  8074db:	50                   	push   eax
  8074dc:	8d 77 0c             	lea    esi,[edi+0xc]
```

### 原始 4-byte message producer (`0x004aa4d0`–`0x004aa509`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004aa4d0 <.text+0xa94d0>:
  4aa4d0:	55                   	push   ebp
  4aa4d1:	8b ec                	mov    ebp,esp
  4aa4d3:	51                   	push   ecx
  4aa4d4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4aa4db:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4aa4df:	b8 40 00 00 00       	mov    eax,0x40
  4aa4e4:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4aa4e8:	66 89 4d fe          	mov    WORD PTR [ebp-0x2],cx
  4aa4ec:	75 15                	jne    0x4aa503
  4aa4ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4aa4f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa4f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4aa4f9:	6a 04                	push   0x4
  4aa4fb:	8d 45 fc             	lea    eax,[ebp-0x4]
  4aa4fe:	50                   	push   eax
  4aa4ff:	6a 00                	push   0x0
  4aa501:	ff d2                	call   edx
  4aa503:	8b e5                	mov    esp,ebp
  4aa505:	5d                   	pop    ebp
  4aa506:	c2 04 00             	ret    0x4
```