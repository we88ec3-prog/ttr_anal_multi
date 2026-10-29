# E49 — RR-0005／KR T02：Pool singleton getter 更正、Conn 雙佇列回收、frame parser 消費規則、S2C ABI 長度契約（目標導向十子段）

- **研究者**：chatgpt-web roy；**檔案時間（台灣）**：`2026-10-30T01:45:08+08:00`；**正式段號**：`E49`。`E49.1…E49.10` 為同段研究單元，非十個正式段號。
- **承接**：E48 完整原稿 `20261030-010130-chatgpt-web-roy-E48-RR0005-close-failure-IOCP-frame-dispatch.md`、E41–E47；第一手是本機 `/mnt/data/Tartaros.bin`，**12,472,320 bytes**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次已重算。沒有執行遊戲、動態 trace、Server 實例或 pcap。
- **GitHub 經核對基準**：`main=075411db2978b17c864ec4df6694126d306c8351`、`extra/roy1=7905e8e189f50463e89b8d35bcf531c19a447a41`；RR-0005 `KR/T02/P0/PENDING/QUEUED`，claim/submission 均 null；T02 README blob `33477dbef9519828a0b48f180a8a2305fac016d4`，共用已驗證庫 README blob `e72d78367b7f8ad91e3f443ca2f2848a1910f0eb`。此筆為研究者獨立原稿，不代表正式 RR 認領、S00 接受或 T01 FULL-PASS。
- **研究目標**：以選服 S2C→record→`0x4957C0` 雙 Connect 為上游，向下閉合 `key/Conn close→pool 入列→pool 回收重置→IOCP/WSARecv→frame decoder 的 incomplete/corrupt/complete 行為→queue owner→application dispatcher 0x0013/0x007A→記錄寫入的資料長度責任`。優先原生否證 E48 的「49B070 為 map detach」及調查同一 TCP buffer 多 frame 的消費與回值；即使有重大發現也不提前停止。
- **證據分層**：N＝本次原始 machine code 直接查到；C＝在列出前提下之嚴格條件式結論；U＝靜態證據不足/需要 runtime。`Conn`、`Manager`、`Pool` 等仍是用途暫名，不代表官方 debug symbols。
- **VA 映射**：以下 asm 僅取 `.text`，raw=`VA-0x400C00`；對 `.rdata`、全域資料不誤套。不能把 `Conn+0xA02C` 與 `Conn+0xA080` 混為一談，不能把 packet buffer 長度與 handler 每筆記錄的結構下界混為一談。
- **停止條件 B**：完成十個大型研究子段後強制停止；端到端單一真實 session、第一筆 wire 與 Server 回覆、完整最小 payload 契約仍未閉合。重大修正**不是**停止原因。

## 0. E49 經原件證實的優先結論與 E48 更正

1. **關鍵更正**：E48 把 `0x49B070` 描述為「map detach」不成立。`0x49B070` 本身只是一個 **`FBA858` singleton getter／lazy initializer**，不收 Conn 參數；`0x80703E` 呼叫它取得 Pool 指標後，`mov edi,eax`；`0x807045` 接著呼叫 `0x805A80`，才是操作 pool+0x28 追蹤 linked list。這條 **不是 active key-map 除名** 的原生證據。上一段描述必須撤銷。
2. `0x805A80` 遍歷 `Pool+0x28` sentinel 的 list 以 `node+8 == Conn*` 判重，未找到才將 `Conn+A0C0` 設為一個計時類來源回傳值、建立新的 node，`Pool+0x2C++`。不是在該方法內 free Conn，也不保證立即回池。
3. `0x805B40` 是另一個由 `0x491203` 呼叫的周期性掃描：先整理 `Pool+0x28`、再掃描 `Pool+0x48`，其 `Conn+A0B8==0` 條件成立時呼叫 `0x805F50` 重設 Conn，再放入 pool 的 block/vector。**這些操作是獨立的狀態/容器，不可視為一次同步 close 完成**。
4. `0x805F50` 確有 `Conn[0]=-1`、`Conn+0xA0AC=0`、`Conn+0xA0A8=0`、`Conn+0xA080=2` 等初始化；但在完整方法 `0x805F50..0x80600E` **未看到將 `Conn+0xA02C`（framing mode）改回2的寫入**。`0xA080` 是另一欄位：切勿再把重置 key/lane 當作 framing mode 重置。
5. `0x807B40` 可識別 `(len,magic)` 的三種 header 大小 4/6/8；**未知 magic 仍保持 4B 預設 header**。對 checksum 或 decompress 失敗，透過 `0x807D7F` 跳過 payload-copy，卻仍計算 `len+header` 消費量並可能處理後續 frame；與解析器最後回傳 `1/0` 不同。
6. `0x807E50` copy 的上限是 `0x1000`，並設定 queue node 的 `+4=payload_length`；其返回值在 `0x807D7A` 呼叫後沒有立即用 `test/cmp` 判斷，隨後依 queue node+4 決定走 `0x804310→0x8076F0` 空節點回收或 `0x489920→0x8040A0` 帶 key 分派。**不要把 decoder 接受 frame 誤解為特定 command 一定到達業務 handler**。
7. `0x4C4670` 的三參數 ABI 仍確定，但 `0x4C37A0`、`0x4C3C10` 的 handler-local length 下界及 nested list count 安全性未由同一套上游證據全部完成，不能用 transport 上限 `0x1000` 替代。

## E49.1 — 否證與校正：`0x49B070` 是 pool singleton getter，非 Conn／key-map detach

**研究問題**：E48.2 所述 `0x806FC0 → 0x49B070 → 0x805A80`，第一個函式會不會從 active map 移除 Conn？

**N：caller/callee/ABI**：`0x49B070` 無 `push ebp` 引入參數也沒有 `[esp+4]`/`[ebp+8]` 讀取；其 CFG 只檢查 `FBA858` 是否為零、其次看 `FBA85C`，按條件呼叫 `0x49AF60` 或 `0x49B000`，最後由 EAX 回傳 `FBA858`。兩個被呼叫者在可見路徑均與 `FC1208` lazy pool/static initializer 關聯。`0x806FC0` 在呼叫 `0x49B070` 前把 **Conn* 放在 `push edi` 傳給 caller 後續**，`0x49B070` 沒有使用這個堆疊參數（真正的 `0x805A80` 以 `[ebp+8]` 取此值）。因此「0x49B070 是 map erase」在參數和寫入端均被反證。

**C：更正後資料流**：`pool = get_pool_singleton(); pool_list_insert_if_absent(pool, Conn*)`。不宣稱 active key→Conn mapping 在其他方法永遠不會移除，只限定此 call chain 內未證明。

**U／缺口**：若要確定 active map erase 的確切時刻，須繼續追 `Manager+0x18` map 的 erase writer 及 key 重連路徑；`0x49B070` 不可再被當成 erase 證據。

**N／Singleton getter／分支**（原件 `.text` VA `0x0049B070..0x0049B096`，起始 raw `0x9A470`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  49b070:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  49b075:	85 c0                	test   eax,eax
  49b077:	75 1d                	jne    0x49b096
  49b079:	39 05 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,eax
  49b07f:	74 0b                	je     0x49b08c
  49b081:	e8 da fe ff ff       	call   0x49af60
  49b086:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  49b08b:	c3                   	ret
  49b08c:	e8 6f ff ff ff       	call   0x49b000
  49b091:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  49b096:	c3                   	ret
```

**N／lazy initializer 來源**（原件 `.text` VA `0x0049AF93..0x0049AFE7`，起始 raw `0x9A393`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  49af93:	68 08 12 fc 00       	push   0xfc1208
  49af98:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49af9f:	e8 bc a4 36 00       	call   0x805460
  49afa4:	68 70 e6 bc 00       	push   0xbce670
  49afa9:	e8 6c 73 3f 00       	call   0x89231a
  49afae:	83 c4 04             	add    esp,0x4
  49afb1:	c7 05 58 a8 fb 00 08 	mov    DWORD PTR ds:0xfba858,0xfc1208
  49afb8:	12 fc 00 
  49afbb:	c7 45 f0 08 12 fc 00 	mov    DWORD PTR [ebp-0x10],0xfc1208
  49afc2:	68 08 12 fc 00       	push   0xfc1208
  49afc7:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  49afce:	e8 8d a4 36 00       	call   0x805460
  49afd3:	68 50 af 49 00       	push   0x49af50
  49afd8:	e8 3d 73 3f 00       	call   0x89231a
  49afdd:	83 c4 04             	add    esp,0x4
  49afe0:	c7 05 5c a8 fb 00 00 	mov    DWORD PTR ds:0xfba85c,0x0
  49afe7:	00 00 00 
```

**N／Conn close → getter → pool list call**（原件 `.text` VA `0x0080702D..0x0080704A`，起始 raw `0x40642D`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff ff       	call   0x805a80
  80704a:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
```

## E49.2 — `0x805A80`：Pool+0x28 雙向串列去重、節點插入與時間戳

**研究問題**：真正被 `0x806FC0` 叫到的 `0x805A80` 對 Conn 做何事？會不會直接 free / erase key？

**N／CFG**：本函式以 `EDI=Pool`，`[ebp+8]=Conn*` 為參數，讀 `Pool+0x28` sentinel 的 `next`，循 `node.next` 扫描到 sentinel；比較 `node+8 == Conn*` 成功則跳 `0x805ADD`（直接 return）。未找到才呼叫 IAT `0xBD22D4` 並存至 `Conn+A0C0`（只能稱 tick-like，這裡沒有依 import 名稱核實 API）。其後透過 `0x74D700` 分配 list-node，在 `Pool+0x28` 尾部插入 `Conn*`，並遞增 `Pool+0x2C`。

**N／container 型別**：`Pool+0x28` 是堆配置的 12-byte sentinel node（`0x8054CE..0x8054ED`），`Pool+0x2C` 初始 0；insert 使用 `Pool+0x28` 的雙向 `next,prev`（`0x805AA7` 後）。此方法沒有 socket lookup、`shutdown`、`closesocket`、I/O cancel、Conn free 或 Manager map erase 指令。

**C／重入**：同一 Conn* 在該 list 中尚未移除時再次呼叫，duplicate guard 避免重複插入**此一串列**；但這不是全域 close-once、race-free、引用計數完整的保證。Mutex 來自外層 `0x806FC0`，方法本身沒有建立額外 mutex。

**U**：tick 來源 precise API / `A0C0` 的延時門檻消費者、是否有其他 caller 直接進入 805A80、pool 重新綁定時的跨執行緒順序。

**N／Pool list initializer**（原件 `.text` VA `0x008054CE..0x008054ED`，起始 raw `0x4048CE`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  8054ce:	6a 0c                	push   0xc
  8054d0:	89 5e 2c             	mov    DWORD PTR [esi+0x2c],ebx
  8054d3:	e8 90 bd 08 00       	call   0x891268
  8054d8:	83 c4 04             	add    esp,0x4
  8054db:	3b c3                	cmp    eax,ebx
  8054dd:	0f 84 94 00 00 00    	je     0x805577
  8054e3:	89 46 28             	mov    DWORD PTR [esi+0x28],eax
  8054e6:	89 00                	mov    DWORD PTR [eax],eax
  8054e8:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  8054eb:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
```

**N／linked-list 去重／插入**（原件 `.text` VA `0x00805A80..0x00805ADF`，起始 raw `0x404E80`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
  805adf:	c2 04 00             	ret    0x4
```

## E49.3 — `0x491203 → 0x805B40`：兩個 list 掃描、pool block 回收的條件式分層

**研究問題**：close 後何時「真的可重用」？`Pool+0x28` 與 `Pool+0x48` 是同一條 list 嗎？

**N／caller**：主 Client 週期循環在 `0x491203` 呼叫 `0x805B40(Pool*)`，相鄰序列涉及 `Pool+0x48` list 的遞減計數、結點操作及 mutex 放開；這不等同於 `0x806FC0` 當場回收。

**N／第一段**：`0x805B49..0x805B88` 先掃 `Pool+0x28`；取 `node+8` 的 Conn 指標並測 `Conn+0x14`。當 `Conn+0x14==0`，將該 **list node** 從雙向串列摘除、釋放 node，並 `Pool+0x2C--`；這段沒有 `free(Conn*)`。若不為零，保留 node 並跳下一個。

**N／第二段**：`0x805B88..0x805C68` 轉而掃 **`Pool+0x48`**，透過 `node+8` 取得 Conn，檢查 `Conn+A0B8`。該欄位 **等於0** 才呼叫 `0x805F50` reset，並將 Conn 指標插回 `Pool+0x10` 的 indexed block/vector，之後移除 `Pool+0x48` node，`Pool+0x4C--`。非零分支略過此 Conn。

**C／生命週期**：關 socket、加入 `Pool+0x28` 追蹤、`Pool+0x48` 進一步處理、`A0B8` 允許 reset、`Pool+0x10` 可重用存放，是**多個可見動作**；不能在沒有中間 producer/caller 及 async I/O 實際 completion 的情況下強行畫成每次都按該順序執行。

**U**：`Pool+0x48` 的完整 producer、`Conn+0x14` 與 `A0B8` 的交叉引用語意、何時對每個 Conn 最後一筆 overlapped completion 已結束，仍需更全面 runtime evidence。

**N／週期 caller**（原件 `.text` VA `0x004911D6..0x00491233`，起始 raw `0x905D6`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  4911d6:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  4911dc:	75 1e                	jne    0x4911fc
  4911de:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  4911e4:	74 11                	je     0x4911f7
  4911e6:	e8 75 9d 00 00       	call   0x49af60
  4911eb:	eb 0f                	jmp    0x4911fc
  4911ed:	68 34 20 bf 00       	push   0xbf2034
  4911f2:	e8 39 c9 3e 00       	call   0x87db30
  4911f7:	e8 04 9e 00 00       	call   0x49b000
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  491233:	bf 01 00 00 00       	mov    edi,0x1
```

**N／第一條 list 刪節點門檻**（原件 `.text` VA `0x00805B40..0x00805B88`，起始 raw `0x404F40`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
```

**N／第二條 list 的 gate／重設**（原件 `.text` VA `0x00805B88..0x00805C67`，起始 raw `0x404F88`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  805b88:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  805b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  805b8d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805b90:	3b c1                	cmp    eax,ecx
  805b92:	75 0f                	jne    0x805ba3
  805b94:	5f                   	pop    edi
  805b95:	5e                   	pop    esi
  805b96:	5b                   	pop    ebx
  805b97:	8b e5                	mov    esp,ebp
  805b99:	5d                   	pop    ebp
  805b9a:	c2 04 00             	ret    0x4
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
```

## E49.4 — Conn 的 reset 實際寫入：`0x805F50` 未重設 `A02C` framing mode

**研究問題**：E46–E47 提出 Conn 被重用後 framing mode 可能沿用。此次能用重設函式反證／實證嗎？

**N**：`0x805D90...0x805E2E` 所在 Conn 建構路徑配置 socket 緩衝並呼叫 `0x805F50`，初始化物件內與 I/O 相關狀態。`0x805B40` 的回池分支也呼叫同一 `0x805F50`。其方法 `0x805F50..0x80600E` 從 `Conn[0]=-1` 到 `A0AC=0, A0A8=0, A080=2, A0B4=1`、內部指標/計數器的逐欄重設都可由原件逐條檢查。

**重要區分**：`0x805FD0 MOV [esi+0xA080],2` **不是** `Conn+0xA02C`。`A080` 是別的 Conn 欄位（E47 視為連線 lane/key）；真正 framing mode `A02C` 在 E46 `0x805D02` 新建路徑寫 2。這份 805F50 所列所有指令**沒有 `A02C=2`**。因此若同一 Conn 已被修改 A02C，僅調 805F50 不足以強制恢復 mode2。

**C**：`A080=2` 的 runtime 覆寫可能由上層真正 Connect key 再次修改；不能因 reset 寫入 2 就把每次重連都認為 key2，也不能推定重用後 framing 一定不變（其他 writer 仍可能介入）。

**U**：所有間接 A02C writer、完整 Conn 再次 checkout path，以及 allocator 的「舊物件重用 vs 新配置」分支仍未合併證明。

**N／Conn 建構中 reset 呼叫**（原件 `.text` VA `0x00805DD7..0x00805E2C`，起始 raw `0x4051D7`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  805dd7:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805ddd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  805de3:	89 8e b4 a0 00 00    	mov    DWORD PTR [esi+0xa0b4],ecx
  805de9:	89 9e b8 a0 00 00    	mov    DWORD PTR [esi+0xa0b8],ebx
  805def:	6a 18                	push   0x18
  805df1:	89 9e bc a0 00 00    	mov    DWORD PTR [esi+0xa0bc],ebx
  805df7:	e8 6c b4 08 00       	call   0x891268
  805dfc:	8b f8                	mov    edi,eax
  805dfe:	83 c4 04             	add    esp,0x4
  805e01:	3b fb                	cmp    edi,ebx
  805e03:	74 0e                	je     0x805e13
  805e05:	68 a0 0f 00 00       	push   0xfa0
  805e0a:	57                   	push   edi
  805e0b:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805e11:	eb 02                	jmp    0x805e15
  805e13:	33 ff                	xor    edi,edi
  805e15:	89 be d4 a0 00 00    	mov    DWORD PTR [esi+0xa0d4],edi
  805e1b:	e8 30 01 00 00       	call   0x805f50
  805e20:	89 b6 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],esi
  805e26:	89 b6 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],esi
  805e2c:	8b c6                	mov    eax,esi
```

**N／Conn 指定欄位實際 reset**（原件 `.text` VA `0x00805F50..0x0080600E`，起始 raw `0x405350`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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
```

**N／Pool new Conn 配置 0xA0D8**（原件 `.text` VA `0x00805760..0x0080579E`，起始 raw `0x404B60`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  805760:	33 f6                	xor    esi,esi
  805762:	68 d8 a0 00 00       	push   0xa0d8
  805767:	e8 fc ba 08 00       	call   0x891268
  80576c:	83 c4 04             	add    esp,0x4
  80576f:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805772:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805775:	3b c6                	cmp    eax,esi
  805777:	74 0d                	je     0x805786
  805779:	50                   	push   eax
  80577a:	e8 21 05 00 00       	call   0x805ca0
  80577f:	8b d0                	mov    edx,eax
  805781:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  805784:	eb 05                	jmp    0x80578b
  805786:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  805789:	8b d6                	mov    edx,esi
  80578b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805792:	8b 43 38             	mov    eax,DWORD PTR [ebx+0x38]
  805795:	89 82 c8 a0 00 00    	mov    DWORD PTR [edx+0xa0c8],eax
  80579b:	8b 4b 3c             	mov    ecx,DWORD PTR [ebx+0x3c]
  80579e:	89 8a cc a0 00 00    	mov    DWORD PTR [edx+0xa0cc],ecx
```

## E49.5 — Socket Close / IOCP 完成：同步關閉 ≠ queue 所有權轉移

**研究問題**：`0x806F80` key-based close 與 `0x806FC0` Conn-based close 是否都完成 key-map erase 或清除 in-flight I/O？

**N**：`0x806F80` 依 `Manager+0x18` 中 key 查到 Conn，讀 `Conn[0]` 作 socket 並呼叫 IAT `0xBD25C8`（shutdown API），立即 return；它本身**沒有** `Pool+0x28` list 插入。`0x806FC0` 在 pool mutex 下，`Conn+A0A8` 非零／socket 為 0/-1 時跳過 close；否則 setsockopt (條件式)、shutdown、closesocket，接 `0x49B070` singleton、`0x805A80(Conn*)` 入 `Pool+0x28` 追蹤。這只是具體分支，**沒有直接證據宣稱 Manager key-map 同步刪除**。

**N／IOCP**：`0x806CF0` `GetQueuedCompletionStatus` 回零、completion key 或 OVERLAPPED 為零、RECV (`Conn+A030`)、SEND (`Conn+A050`) 的分支各自不同。`0x806E08` 在 RECV 分支呼叫 decoder，decoder 回 1 走再 post receive 的 virtual slot +0x14；回 0 可能標記 `Conn+A0B0=1`；SEND completion 做 buffer 消費、`Conn+A024` 維護及 `SetEvent(Conn+A0B8)`。不能把 IOCP 失敗事件一概視為 close 已完成。

**C／可能風險**：函式不檢查 CreateIoCompletionPort association API 成功與否的 E48 觀察，在此仍成立；但這不等於現實環境必然失敗。Close flags 與其他 outstanding overlapped 的 races 需 runtime trace 才能精確排序。

**U**：active key-map erase 的準確位置、各 completion handler 對 Conn+0x14/0xA0B8 的 writer 關係、invalid socket 重連 key 不一致分支。

**N／按 key close 的短路／socket**（原件 `.text` VA `0x00806F80..0x00806FBA`，起始 raw `0x406380`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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

**N／按 Conn close 的 gate／pool tracking**（原件 `.text` VA `0x00806FC0..0x0080708D`，起始 raw `0x4063C0`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
  80704a:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  807051:	5f                   	pop    edi
  807052:	5e                   	pop    esi
  807053:	75 27                	jne    0x80707c
  807055:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  80705c:	74 19                	je     0x807077
  80705e:	e8 fd 3e c9 ff       	call   0x49af60
  807063:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807069:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  80706c:	50                   	push   eax
  80706d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807073:	5d                   	pop    ebp
  807074:	c2 08 00             	ret    0x8
  807077:	e8 84 3f c9 ff       	call   0x49b000
  80707c:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807082:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  807085:	50                   	push   eax
  807086:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80708c:	5d                   	pop    ebp
  80708d:	c2 08 00             	ret    0x8
```

**N／completion receive/send gate**（原件 `.text` VA `0x00806DE4..0x00806EC4`，起始 raw `0x4061E4`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
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
```

## E49.6 — Frame decoder 的長度、magic、incomplete/invalid exit 和 buffer 消費規則

**研究問題**：`0x807B40` 在一個 TCP recv buffer 內，如何辨識「不足一個 frame」、「invalid length」、「unknown magic」、「完整 frame」？這些結果的 return0/1 是否相同？

**N／入口與 buffer**：`0x807B85` 從 `[ebp+8]` 取 Conn 參數，將新增 byte 數加至 `EDX(buffer)+0x5000` read-end 指標；至少 `4` bytes 才開始讀 `u16 payloadLen` 與 `u16 magic`。payloadLen `==0` 或 `>0x1000` 跳 `0x807E1D`，回傳 0。**若接收到完整 header 卻缺 payload**，`0x807C3C cmp ecx,eax; jg 0x807DDA`，保留未消費 bytes，後續回1；這和 invalid length 返回0不同。

**N／header**：`magic==0x2633` 使用 8B；`magic==0x0BBB` 6B；`0x1A68`、`0x22D7` 使用 4B；不符合四者亦保留預設 4B → plain path。此處未實施 magic 白名單拒絕。

**N／remainder**：每完成一個有界 frame，`0x807DB2` 以原 frame len + 選定 header-size 推進 EBX；若剩餘 `>=4` 則迴圈下一 frame。尾端 `0x807DDA..807E14` 針對不足 header 的剩餘內容執行 `0x8912F0` (memmove-like) 至接收 buffer 起點，更新 end pointer，返回1。若內部 pointer bounds 失敗，跳 0 branch。這是**incomplete frame 可以跨 recv 拼接**的具體原生條件式支撐。

**U**：單次 recv 的同步／異步分段位置、當期 Conn 收到的實際 byte 序列、任意 malformed 情況的實際 exception/heap 狀態；無法用靜態路徑直接宣稱 wire 已驗證。

**N／frame magic／payloadLen gate**（原件 `.text` VA `0x00807B85..0x00807C44`，起始 raw `0x406F85`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
  807c44:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
```

**N／相鄰 frame 和剩餘 byte 轉移／回值**（原件 `.text` VA `0x00807DB2..0x00807E42`，起始 raw `0x4071B2`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
  807dd4:	eb 04                	jmp    0x807dda
  807dd6:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dda:	8b b7 00 50 00 00    	mov    esi,DWORD PTR [edi+0x5000]
  807de0:	8d 87 00 50 00 00    	lea    eax,[edi+0x5000]
  807de6:	2b f3                	sub    esi,ebx
  807de8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807dec:	8d 0c 1e             	lea    ecx,[esi+ebx*1]
  807def:	3b df                	cmp    ebx,edi
  807df1:	72 2a                	jb     0x807e1d
  807df3:	3b d8                	cmp    ebx,eax
  807df5:	73 26                	jae    0x807e1d
  807df7:	3b cf                	cmp    ecx,edi
  807df9:	72 22                	jb     0x807e1d
  807dfb:	3b c8                	cmp    ecx,eax
  807dfd:	73 1e                	jae    0x807e1d
  807dff:	85 f6                	test   esi,esi
  807e01:	78 1a                	js     0x807e1d
  807e03:	56                   	push   esi
  807e04:	53                   	push   ebx
  807e05:	57                   	push   edi
  807e06:	e8 e5 94 08 00       	call   0x8912f0
  807e0b:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  807e0f:	83 c4 0c             	add    esp,0xc
  807e12:	03 fe                	add    edi,esi
  807e14:	89 38                	mov    DWORD PTR [eax],edi
  807e16:	b8 01 00 00 00       	mov    eax,0x1
  807e1b:	eb 02                	jmp    0x807e1f
  807e1d:	33 c0                	xor    eax,eax
  807e1f:	8b 8c 24 38 20 00 00 	mov    ecx,DWORD PTR [esp+0x2038]
  807e26:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  807e2d:	59                   	pop    ecx
  807e2e:	5f                   	pop    edi
  807e2f:	5e                   	pop    esi
  807e30:	5b                   	pop    ebx
  807e31:	8b 8c 24 20 20 00 00 	mov    ecx,DWORD PTR [esp+0x2020]
  807e38:	33 cc                	xor    ecx,esp
  807e3a:	e8 c2 91 08 00       	call   0x891001
  807e3f:	8b e5                	mov    esp,ebp
  807e41:	5d                   	pop    ebp
  807e42:	c2 04 00             	ret    0x4
```

## E49.7 — `0x0BBB`、`0x2633` 與 unknown header 的受控 parser 向量、錯幀後繼續處理

**研究問題**：checksum/解壓失敗是否終止整個 TCP stream？如何構造**純離線測試向量**區分「完整/損壞/未知 magic」且不冒稱執行了遊戲？

**N／0BBB**：`0x807D33` 首 byte XOR `0xB6`；`0x807D50` 後續每一 encoded byte XOR 前一 **decoded** byte；累加 decoded byte 為 u16 sum、`0x807D66` 與 frame+4 的 u16 checksum 比對。bad sum → `0x807D7F`，不走 `0x807E50`。good sum → decoded buffer 入 payload copy path。

**N／2633**：`0x807CD2` seed XOR `0x7C`，後續相同 previous-decoded chaining；`0x807D0E` 呼叫 `0x727190` 解碼到上限 `0x1000`，回傳非零跳 `0x807D7F`。其 header 8B，不能把 0BBB checksum 公式套入 2633。

**N／錯誤迴圈**：對 checksum fail／decompress fail，`0x807D7F` 仍由 node 的 `+4` 是否為零決定回收或派送，然後 `0x807DB2` 推進 consumed bytes，剩餘足夠則回 `0x807BB0` 讀下一 frame。*這是沒有立即把整條 TCP close 的靜態證據*，不是所有惡意 malformed buffer 安全的認證。

**C／離線控制向量（不注入到遊戲與網路）**：以兩個 plaintext command bytes `13 00` 作最小 payload，checksum = `0x0013`，encoded body `A5 13`，故 0BBB 正常 frame 為 `02 00 BB 0B 13 00 A5 13`；將 checksum 改為 `14 00` 是 checksum mismatch 的分支候選；未知 magic `34 12` + payload `13 00` 為 `02 00 34 12 13 00`，在本層依 4B/plain 路徑。這些**只是 parser 分支向量**，不是有效 login `0x0013`（該 handler 會讀取更深欄位），不可對業務層直接發送或視為可玩封包。

**U**：0x727190 的內部壓縮格式合法輸入與回傳分支、跨 recv source buffers 的實際時序、損壞 frame 後 Server 是否繼續傳送另一筆命令。

**N／2633 XOR／decompress／fail target**（原件 `.text` VA `0x00807CD2..0x00807D2A`，起始 raw `0x4070D2`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
```

**N／0BBB checksum／fallback**（原件 `.text` VA `0x00807D2C..0x00807D7F`，起始 raw `0x40712C`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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
```

**N／checksum fail 後的隊列與消費**（原件 `.text` VA `0x00807D7F..0x00807DD4`，起始 raw `0x40717F`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
  807dd4:	eb 04                	jmp    0x807dda
```

## E49.8 — Decode queue 物件所有權：`807E50` copy 到 `804310/8076F0` vs `489920/8040A0`

**研究問題**：decoder 找到 frame 後何時真正進應用層？錯誤或不完整 frame 是不是可能流入業務 handler？

**N／node**：`0x8075B0` 以 `0x100C` malloc 類呼叫建立 payload node、node+8 是 0x1000 byte buffer、`node+4` 是 length、`node+0x1008` 是索引類欄位。`0x807E50` 查 `ESI <= 0x1000`，將 `ESI` byte copy 到 `node+8`，最後 `node+4=ESI`，回傳 byte1；若超過則回 AL=0。

**N／drop vs dispatch**：`0x807D83..0x807DB2` 即使沒有成功 `0x807E50` copy，也測 `node+4`：為0則呼叫 `0x804310` 找到資源 owner，再 `0x8076F0` 將 node 的 +0/+4 清零並放回原接收池；非零則用 `Conn+A080` 作一個識別參數，`0x489920` 選 application-side 全域隊列，`0x8040A0` 進一步排入。此時 decoder 本身**尚未執行 `0x0013`/`0x007A` handler**。

**N／event 後端**：`0x806E08` 以 `Conn+0x18` 的 receive buffer 跑 decoder，再看其 **整體 bool**，為非零嘗試再 post WSARecv。將 queue presence 和 parser bool 等同是錯誤的。

**C／安全界線**：錯誤 checksum 走 `0x807D7F`，由於 node+4 未被設為有效長度，當前 node 通常走資源池回收；這不證明全部非標準 frame 均無例外，亦不保證 application handler 自身會拒絕缺欄位 payload。

**U**：`0x8040A0` 佇列 pop 時與 `0x804740` callback gate 的同一 frame 對應、其他 thread 對 node+4 的可見性、可接受 payload 的 schema validation 來源。

**N／node 新建與 1000B buffer**（原件 `.text` VA `0x008075D0..0x00807624`，起始 raw `0x4069D0`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  8075d0:	68 0c 10 00 00       	push   0x100c
  8075d5:	e8 8e 9c 08 00       	call   0x891268
  8075da:	8b f0                	mov    esi,eax
  8075dc:	33 c0                	xor    eax,eax
  8075de:	83 c4 04             	add    esp,0x4
  8075e1:	3b f0                	cmp    esi,eax
  8075e3:	74 1f                	je     0x807604
  8075e5:	68 00 10 00 00       	push   0x1000
  8075ea:	50                   	push   eax
  8075eb:	8d 4e 08             	lea    ecx,[esi+0x8]
  8075ee:	51                   	push   ecx
  8075ef:	89 06                	mov    DWORD PTR [esi],eax
  8075f1:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  8075f4:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8075fa:	e8 61 72 09 00       	call   0x89e860
  8075ff:	83 c4 0c             	add    esp,0xc
  807602:	eb 02                	jmp    0x807606
  807604:	33 f6                	xor    esi,esi
  807606:	8b 47 2c             	mov    eax,DWORD PTR [edi+0x2c]
  807609:	8d 50 01             	lea    edx,[eax+0x1]
  80760c:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  80760f:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  807615:	8d 45 fc             	lea    eax,[ebp-0x4]
  807618:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  80761b:	50                   	push   eax
  80761c:	8d 77 3c             	lea    esi,[edi+0x3c]
  80761f:	e8 3c cc ff ff       	call   0x804260
  807624:	8b 77 30             	mov    esi,DWORD PTR [edi+0x30]
```

**N／payload copy node+4 writer**（原件 `.text` VA `0x00807E50..0x00807E78`，起始 raw `0x407250`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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

**N／失敗/成功不同目的地**（原件 `.text` VA `0x00807D7F..0x00807DB2`，起始 raw `0x40717F`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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

**N／node 回池使長度清零**（原件 `.text` VA `0x008076F0..0x00807729`，起始 raw `0x406AF0`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  8076f0:	55                   	push   ebp
  8076f1:	8b ec                	mov    ebp,esp
  8076f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8076f6:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  8076fc:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  807703:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  807706:	56                   	push   esi
  807707:	50                   	push   eax
  807708:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80770e:	8d 4d 08             	lea    ecx,[ebp+0x8]
  807711:	51                   	push   ecx
  807712:	8d 77 3c             	lea    esi,[edi+0x3c]
  807715:	e8 46 cb ff ff       	call   0x804260
  80771a:	8b 57 58             	mov    edx,DWORD PTR [edi+0x58]
  80771d:	ff 4f 54             	dec    DWORD PTR [edi+0x54]
  807720:	52                   	push   edx
  807721:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807727:	5e                   	pop    esi
  807728:	5d                   	pop    ebp
  807729:	c2 04 00             	ret    0x4
```

## E49.9 — Application ABI 與 `0x0013/0x007A` 長度責任：不能以 4096 上限取代結構 min-size

**研究問題**：`0x4C4670` 的第二參數是否必然在各 handler 內保證 payload 完整？`0x4C3080` 是否收到顯式可用 buffer 長度？

**N／dispatcher**：`0x4C4670` 取 `[ebp+0x10]` 16-bit command 做 sign extend、索引 8B stride callback；已註冊時將 `[ebp+0x8]`、`[ebp+0xC]`、`[ebp+0x10]` 三參數原樣 push 給 handler；未註冊時以同組參數呼叫 `0x4FDA30`。因此第二個 DWORD **有被攜帶**，但是是否為每個子 handler 被強制檢查的 byte count 還需追其來源/類型。

**N／handler**：`0x4C3C10` 直接使用 `payload+2` DWORD 以及 `payload+6` 指標（呼叫 `0x4C3080`），完全不讀 `[ebp+0xC]`；`0x4C37A0` 在 `payload+0x20`、`+0x90` 以及 `+0x92` 等路徑有讀取，實際 call `0x4C3080` 時用 `payload+0x1C` 的值與 `payload+0x92` 指標；沒有在該入口使用外部顯式 byteLength 作 min-size check。

**N／nested schema**：`0x4C3080` 讀 list start 的 WORD group id、BYTE rowCount 後每筆固定 `0x0A` 的 record，將 `child+4..+7` 格式化為 IPv4，使用 `0x507510/0x507610` 建立選服 record。它沒有傳入整個 buffer 的 end pointer。`0x807B40` 只保證每個 transport payloadLen `1..0x1000` 且需完整 frame，**不能由此推得** `0x0013` 成功分支的 payload >= 該 branch 的最高讀取 offset、`0x007A` 至少6 bytes、或 `rowCount *10` 必定落在範圍內。

**C／端到端約束**：S00 如要產生能給現有 Client 使用的可實作 schema，必須明示 `0x0013`/`0x007A` 各自最小可用長度、固定 prefix、group count、nested rowCount ×10 與適用條件；此 E49 靜態研究**尚不能把這些作為全部已驗證的安全邊界**。

**U**：上游是否有共用 schema validator、`0x4FDA30` 的每命令特別校驗、框架次級對照表 writer 與 T03 UI 行為，需查回到實際 caller/writer 才可定論。

**N／次級 command dispatcher 的 3 參數原樣傳遞**（原件 `.text` VA `0x004C4670..0x004C46ED`，起始 raw `0xC3A70`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
  4c46ed:	c2 0c 00             	ret    0xc
```

**N／0x007A handler 的無明確 length gate**（原件 `.text` VA `0x004C3C10..0x004C3C25`，起始 raw `0xC3010`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  4c3c10:	55                   	push   ebp
  4c3c11:	8b ec                	mov    ebp,esp
  4c3c13:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c3c16:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4c3c19:	51                   	push   ecx
  4c3c1a:	8d 48 06             	lea    ecx,[eax+0x6]
  4c3c1d:	e8 5e f4 ff ff       	call   0x4c3080
  4c3c22:	33 c0                	xor    eax,eax
  4c3c24:	5d                   	pop    ebp
  4c3c25:	c2 0c 00             	ret    0xc
```

**N／0x0013 handler 對 list reader 的實參**（原件 `.text` VA `0x004C39C3..0x004C3A2B`，起始 raw `0xC2DC3`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
  4c39c3:	8a 96 86 00 00 00    	mov    dl,BYTE PTR [esi+0x86]
  4c39c9:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  4c39cf:	88 95 b4 fb ff ff    	mov    BYTE PTR [ebp-0x44c],dl
  4c39d5:	e8 c6 11 f4 ff       	call   0x404ba0
  4c39da:	8b f8                	mov    edi,eax
  4c39dc:	8a 85 b4 fb ff ff    	mov    al,BYTE PTR [ebp-0x44c]
  4c39e2:	8d 8e 87 00 00 00    	lea    ecx,[esi+0x87]
  4c39e8:	51                   	push   ecx
  4c39e9:	8d 97 99 68 00 00    	lea    edx,[edi+0x6899]
  4c39ef:	6a 05                	push   0x5
  4c39f1:	52                   	push   edx
  4c39f2:	88 87 98 68 00 00    	mov    BYTE PTR [edi+0x6898],al
  4c39f8:	e8 5c 01 3d 00       	call   0x893b59
  4c39fd:	89 9f a0 68 00 00    	mov    DWORD PTR [edi+0x68a0],ebx
  4c3a03:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  4c3a06:	83 c4 0c             	add    esp,0xc
  4c3a09:	50                   	push   eax
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
  4c3a1c:	75 0b                	jne    0x4c3a29
  4c3a1e:	8b bd b0 fb ff ff    	mov    edi,DWORD PTR [ebp-0x450]
  4c3a24:	e8 47 f7 ff ff       	call   0x4c3170
  4c3a29:	33 c0                	xor    eax,eax
  4c3a2b:	e9 34 01 00 00       	jmp    0x4c3b64
```

**N／nested record count 與 bytes**（原件 `.text` VA `0x004C30A5..0x004C312D`，起始 raw `0xC24A5`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
```

## E49.10 — 端到端條件式閉合與失敗對照：Connect→Close／Pool→IOCP→Queue→Handler

**研究問題**：把前九個子段聚合後，哪些是*已閉合的原生局部鏈*、哪些是*同一 session 的未驗證時序*？找出最小可操作的後續研究入口，而不是以有重大發現提前停止。

**N／可銜接的 native 局部鏈**：

```text
E44/E45 S2C 0x0013 / 0x007A
  → handler 0x4C37A0 / 0x4C3C10 → 0x4C3080
  → FE1B54 選服容器 → UI 0x66B910 → 0x66C620→0x66C090
  → 0x4957C0 → Manager vtable create 0x806AD0 → Conn / socket connect
  → [各自依條件] key0 本地 0x0001/57B enqueue、0x8068B0 WSASend
  → [各自依條件] 0x806A00 WSARecv → IOCP 0x806CF0
  → receive+0xA030 → 0x807B40 frame parser
  → 0x807E50 payload node+4 → 0x489920 / 0x8040A0 app queue
  → 0x804740 / 0x80486D → 0x4930E0 → 0x48AAD0
  → 0x494360 → 0x4FDA30 → 0x4B7EC0 → 0x4C4670 → handler

另一個清理分支：
  key close: 0x806F80 → shutdown(socket), not synchronous pool reclaim
  Conn close: 0x806FC0 → shutdown+closesocket
       → singleton accessor 0x49B070 → Pool+0x28 insert 0x805A80
  loop 0x491203 → 0x805B40：list+0x28/0x48 分流、有條件 reset 0x805F50
```

**重要界線**：每個箭頭在指定 receiver/slot 已成立的條件下有原生呼叫或 writer/reader 關係；**整條鏈不可被稱為同一連線真實發生的時序**。特別是同一 Login S2C 是否正是引發 choice UI／雙 Connect 的觸發事件、key0 和 key2 哪條先完成、first on-wire header/command，皆未觀測。`0x49B070` 已明確**從「map detach」更正為「singleton getter」**。

**故障行為對照**：

| 事件 | 本段 native 支撐 | 不可過度推論 |
|---|---|---|
| key close `0x806F80` | 依 key 查 socket、shutdown | 不是同步 Conn free/map erase |
| Conn close `0x806FC0` | socket close、pool mutex、`0x805A80` list insert | 不是必然所有 overlapped 已完成 |
| 重複 list insert | `805a90` node+8 比對 Conn* | 不是所有 list 的全域 close-once |
| pool tick sweep | `491203`→`805B40` | 不是每次 Conn 都立即 reset |
| 0x0BBB checksum fail | `807d6a`→`807d7f` | 不是整條 TCP disconnect |
| 0x2633 decode fail | `807d16`→`807d7f` | 不是 command handler fail |
| unknown 4B magic | `807c2a`→`807c34` default4 | 不是業務 command 已接受 |
| incomplete frame | `807c3e`→`807dda` retained remainder | 不是 invalid length exit 0 |
| malformed `0x0013/0x007A` | handler-local 缺顯式 length gate | 不等於已確認 exploit，亦不表示 Server 可忽略 schema |

**U／動態解除條件**：在合法可控測試環境中，用同一 session correlation ID 記錄 Connect key+socket、Conn pointer reuse、first enqueue、WSASend WSABUF/header bytes、GQCS completion key+bytes、WSARecv buffer fragments、`0x807B40` decoder result、app queue node len/key、0x0013/0x007A handler input length、UI F94294/FE1B54 變化。若無 trace，靜態推論到此即應停止；禁止以合成向量當作真實 wire。

**後續 E50 精確問題**：1) 以 `0x805A80` producer + `0x805B40` consumer 定向核對 `Pool+0x48` 的所有 caller/list writers、`Conn+A0B8` close/reset 生命週期及 `Pool+0x28` time-like gate；2) trace `0x806AD0` key-map insertion 後的 erase writer，確認同 key 重連殘留映射；3) `0x807B40` 回0/回1與 `0x806CF0` 的再收 gate 全部對齊；4) `0x4C4670` 第二參數最源頭和各 S2C record parser 的 size contract，若能取得合法觀測，補首筆封包動態證據。

**N／connect 收包 IOCP 的 decoder/再接收邊界**（原件 `.text` VA `0x00806DF2..0x00806E32`，起始 raw `0x4061F2`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
```

**N／send completion buffer 與 Event 更新**（原件 `.text` VA `0x00806E7D..0x00806EC4`，起始 raw `0x40627D`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

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
```

**N／manager connect/enqueue handler**（原件 `.text` VA `0x008069A0..0x00806AD0`，起始 raw `0x405DA0`；`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）：

```asm
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
  8069f6:	cc                   	int3
  8069f7:	cc                   	int3
  8069f8:	cc                   	int3
  8069f9:	cc                   	int3
  8069fa:	cc                   	int3
  8069fb:	cc                   	int3
  8069fc:	cc                   	int3
  8069fd:	cc                   	int3
  8069fe:	cc                   	int3
  8069ff:	cc                   	int3
  806a00:	55                   	push   ebp
  806a01:	8b ec                	mov    ebp,esp
  806a03:	51                   	push   ecx
  806a04:	53                   	push   ebx
  806a05:	56                   	push   esi
  806a06:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806a09:	57                   	push   edi
  806a0a:	8d 86 30 a0 00 00    	lea    eax,[esi+0xa030]
  806a10:	8b f9                	mov    edi,ecx
  806a12:	33 c9                	xor    ecx,ecx
  806a14:	89 08                	mov    DWORD PTR [eax],ecx
  806a16:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  806a19:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  806a1c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  806a1f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  806a22:	8b 8e 18 50 00 00    	mov    ecx,DWORD PTR [esi+0x5018]
  806a28:	6a 00                	push   0x0
  806a2a:	50                   	push   eax
  806a2b:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  806a2e:	8d 48 14             	lea    ecx,[eax+0x14]
  806a31:	8d 45 fc             	lea    eax,[ebp-0x4]
  806a34:	50                   	push   eax
  806a35:	8d 45 08             	lea    eax,[ebp+0x8]
  806a38:	50                   	push   eax
  806a39:	6a 01                	push   0x1
  806a3b:	c7 01 00 10 00 00    	mov    DWORD PTR [ecx],0x1000
  806a41:	8b 16                	mov    edx,DWORD PTR [esi]
  806a43:	51                   	push   ecx
  806a44:	52                   	push   edx
  806a45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
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
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2 04 00             	ret    0x4
  806acf:	cc                   	int3
  806ad0:	55                   	push   ebp
```

## 附錄 A：離線純函式 sanity vectors（不執行 Client、不發網路封包）

以下演算法僅**逐條轉錄** `0x807D33..0x807D6A` 所能確認的 `0x0BBB` checksum+XOR 分支，用來檢查報告給出的 bytes，而非原版完整壓縮／I/O 模擬：

```python
def encode_0bbb(payload: bytes) -> bytes:
    assert 1 <= len(payload) <= 0x1000
    checksum = sum(payload) & 0xFFFF
    encrypted = bytes([payload[0] ^ 0xB6] +
                      [payload[i] ^ payload[i-1] for i in range(1,len(payload))])
    return (len(payload).to_bytes(2,'little') + b'\xBB\x0B' +
            checksum.to_bytes(2,'little') + encrypted)

assert encode_0bbb(b'\x13\x00').hex(' ') == '02 00 bb 0b 13 00 a5 13'
# checksum mismatch: header 13 00 -> 14 00, body unchanged
# unknown magic plain parser route: 02 00 34 12 13 00
```

- `0BBB` sample `02 00 BB 0B 13 00 A5 13`；decodes bytes `13 00`，sum `0x13`。
- checksum mismatch `02 00 BB 0B 14 00 A5 13`；同 payload 不符，會進 `0x807D7F` skip-copy 分支。
- unknown magic/plain `02 00 34 12 13 00`；本層使用預設 4B header，與次級 command schema 的接受程度無關。
- valid+invalid 連續候選 buffer `02 00 BB 0B 14 00 A5 13 | 02 00 34 12 13 00`：理論上 `len+header` 消費8B後，可再次讀下一個 4B header；此為 CFG 導出的**條件式**，不是 live socket trace。
- 不構造任何精確 `0x2633` 有效壓縮位元流：`0x727190` 的壓縮格式/解壓機制尚未在 E49 全部驗證，偽造測資會降低可信度。

## 附錄 B：可再現的靜態核證指令

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x49b070 --stop-address=0x49b097 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x805a80 --stop-address=0x805ae0 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x805b40 --stop-address=0x805c69 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x805f50 --stop-address=0x806010 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x807b40 --stop-address=0x807e79 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x4c4670 --stop-address=0x4c46ee /mnt/data/Tartaros.bin
```

## 附錄 C：研究結束狀態、未解分類與交接

| 分類 | E49 之後具體範圍 | 下一步解除條件 |
|---|---|---|
| **Client 待逆向** | active key-map erase 真正 writer；Pool+0x48 producer、Conn+14/A0B8 lifecycle；A02C 各 writer；0x0013/0x007A 的 nested 最小合法 payload schema；0x727190 完整格式 | 基於本段地址做 writer/caller 交叉驗證，禁止使用 49B070 冒充 map erase |
| **跨功能待整合** | 選服 record、UI event、雙 Connect、首次 app queue 與登入/選角狀態的同一次 session 因果 | 共用 trace id 或更多 native gate writer/reader；與 T03 串接 |
| **待遊玩驗證** | first key0/key2 WSASend、Server 首回覆、close/retry、Conn pool 重用及 framing mode 改寫 | 合法測試環境的可回溯 packet+function trace |
| **Server 待開發** | 相容 endpoint/framing/合法命令 schema 與失敗回應策略，依 S00 設計另行決定；不是原版內部算法必須復原 | S00 登記有限原生 claim，未證 native 欄位不得捏造成官方格式 |

**E49 停止原因**：`B`，本次已達 **10 個大型分析子段**；尚未達 `A`，無 C 類新阻塞宣稱。重大更正 `0x49B070` getter 本身未使研究停段。**GitHub**：使用者本次未授權 Commit/Push，故未修改 GitHub，RR-0005 保持 PENDING/QUEUED/unclaimed。此 Markdown 是本地完整原稿而非 Git 既存 blob。**下一正式段號：E50**。

