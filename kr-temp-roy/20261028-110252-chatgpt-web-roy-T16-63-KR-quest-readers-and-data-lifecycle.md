# T16-63 — KR QuestInfo／QuestTalk 初始化呼叫與 reader 資料生命週期

- 對象：**KR T16 only**，《星空幻想 Online》任務與劇情流程；分析日期 `20261028-110252`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 唯讀原件：`/mnt/data/Tartaros.bin`；大小 `12,472,320` bytes；本次 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `.text` 核驗 VA `0x00401000` / raw `0x400`，在本段地址使用 `raw = VA - 0x00400C00`；實際取 `Tartaros.bin` 機器碼，再由 GNU objdump `-m i386 -M intel` 靜態解碼，不執行客戶端。
- GitHub 先前基準為 main `ce87b59efc2712535d04f0cd212ebe0323df23d7`（查詢時），延續 T16-57～60；不改 catalog、owner、其他任務；**不檢查 TC**。
- 分級：`原生已確認` = 這次可核驗的位元組／直線組語；`部分確認` = caller 和 callee 意義尚有條件；`合理推測` = 待證；`資訊缺失` = 沒有原件證據。線性反組譯在跳轉／函式邊界外可能混入非程式位元組，不自稱完成 CFG。

## 新增組語驗證

- `0x00504370` 的初始化路徑在 `0x0050439F` 以 `push 0xB8` 配置一個資料管理物件的內嵌分桶／樹 sentinel，並將指標放到 `[EDI+4]`，`[EDI+8]` 清零；把 sentinel 自指於 `+0,+4,+8` 並將 `+0xB4/+0xB5` 置 `1`。這些是**局部結構事實**，不代表 Quest 的持久化狀態表。
- `0x005043E5` 推入同一個 `EDI`，`call 0x00504740` 後，`0x005043EE` 再 `push EDI; call 0x00505570`，兩個 reader 同一初始化函式有序連接。
- `0x005043F4` 以 `LEA EDX,[EBP-0xB8]` 呼叫 `0x004FF920`，其後還有全域懶初始化資料 `0x00FE5AE4/0x00FE5AC4` 與 `0x005740F0`；尚未逐步證明與 Quest 15/16 元素的連結。
- 目前 `QuestInfo.xml` 的完整來源 SHA 雖由 T01 索引標識，但無法在本地直接取得對應 XML 全文，**不可**填寫 id15/16 前置或 NPC 欄位。

## 關鍵原始位元組

- VA 0x0050439F / raw 0x0010379F: 68 b8 00 00 00 89 bd 8c fe ff ff 89 77 08 e8 b6 ce 38 00 83 c4 04 3b c6 0f 84 65 01 00 00 89 47 04 89 00 8b 47 04 89 40 04 8b 47 04 89
- VA 0x005043E5 / raw 0x001037E5: 57 89 75 fc e8 52 03 00 00 57 e8 7c 11 00 00 8d 95 48 ff ff

```asm
00504370 <.data+0x103770>:
  504370:	55                   	push   ebp
  504371:	8b ec                	mov    ebp,esp
  504373:	6a ff                	push   0xffffffff
  504375:	68 a3 42 92 00       	push   0x9242a3
  50437a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504380:	50                   	push   eax
  504381:	81 ec 78 01 00 00    	sub    esp,0x178
  504387:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50438c:	33 c5                	xor    eax,ebp
  50438e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  504391:	53                   	push   ebx
  504392:	56                   	push   esi
  504393:	50                   	push   eax
  504394:	8d 45 f4             	lea    eax,[ebp-0xc]
  504397:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50439d:	33 f6                	xor    esi,esi
  50439f:	68 b8 00 00 00       	push   0xb8
  5043a4:	89 bd 8c fe ff ff    	mov    DWORD PTR [ebp-0x174],edi
  5043aa:	89 77 08             	mov    DWORD PTR [edi+0x8],esi
  5043ad:	e8 b6 ce 38 00       	call   0x891268
  5043b2:	83 c4 04             	add    esp,0x4
  5043b5:	3b c6                	cmp    eax,esi
  5043b7:	0f 84 65 01 00 00    	je     0x504522
  5043bd:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  5043c0:	89 00                	mov    DWORD PTR [eax],eax
  5043c2:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043c5:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5043c8:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043cb:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5043ce:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043d1:	bb 01 00 00 00       	mov    ebx,0x1
  5043d6:	88 98 b4 00 00 00    	mov    BYTE PTR [eax+0xb4],bl
  5043dc:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  5043df:	88 99 b5 00 00 00    	mov    BYTE PTR [ecx+0xb5],bl
  5043e5:	57                   	push   edi
  5043e6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5043e9:	e8 52 03 00 00       	call   0x504740
  5043ee:	57                   	push   edi
  5043ef:	e8 7c 11 00 00       	call   0x505570
  5043f4:	8d 95 48 ff ff ff    	lea    edx,[ebp-0xb8]
  5043fa:	52                   	push   edx
  5043fb:	e8 20 b5 ff ff       	call   0x4ff920
  504400:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  504403:	c7 85 48 ff ff ff 61 	mov    DWORD PTR [ebp-0xb8],0xea61
  50440a:	ea 00 00 
  50440d:	c7 85 4c ff ff ff 02 	mov    DWORD PTR [ebp-0xb4],0x2
  504414:	00 00 00 
  504417:	84 1d e4 5a fe 00    	test   BYTE PTR ds:0xfe5ae4,bl
  50441d:	75 24                	jne    0x504443
  50441f:	09 1d e4 5a fe 00    	or     DWORD PTR ds:0xfe5ae4,ebx
  504425:	68 c4 5a fe 00       	push   0xfe5ac4
  50442a:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  50442e:	e8 0d 08 08 00       	call   0x584c40
  504433:	68 90 f3 bc 00       	push   0xbcf390
  504438:	e8 dd de 38 00       	call   0x89231a
  50443d:	83 c4 04             	add    esp,0x4
  504440:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  504443:	8d 85 98 fe ff ff    	lea    eax,[ebp-0x168]
  504449:	50                   	push   eax
  50444a:	8d 85 94 fe ff ff    	lea    eax,[ebp-0x16c]
  504450:	b9 c4 5a fe 00       	mov    ecx,0xfe5ac4
  504455:	c7 85 98 fe ff ff 0e 	mov    DWORD PTR [ebp-0x168],0x30e
  50445c:	03 00 00 
  50445f:	e8 8c fc 06 00       	call   0x5740f0
  504464:	8b 85 94 fe ff ff    	mov    eax,DWORD PTR [ebp-0x16c]
  50446a:	3b 05 c8 5a fe 00    	cmp    eax,DWORD PTR ds:0xfe5ac8
  504470:	74 0d                	je     0x50447f
  504472:	83 78 24 08          	cmp    DWORD PTR [eax+0x24],0x8
  504476:	8d 50 10             	lea    edx,[eax+0x10]
  504479:	72 0a                	jb     0x504485
  50447b:	8b 12                	mov    edx,DWORD PTR [edx]
  50447d:	eb 06                	jmp    0x504485
  50447f:	cc                   	int3
```

## 記憶體結構初稿（有限範圍）

| 接收物件 | 位移 | 被證實的初始化／用途 | 尚待驗證 |
|---|---|---|---|
| EDI object | `+0x04` | 被設為 `alloc(0xB8)` 的 sentinel／管理物件 | 其正式型別及 key/value 生命週期 |
| EDI object | `+0x08` | 本段設為 0 | 是否計數；非任務進度推定 |
| allocated node | `+0x00/+0x04/+0x08` | 三個自我指標 | 樹或容器的完整操作語義 |
| allocated node | `+0xB4/+0xB5` | 被設為 `1` | 是 flags，但具體位元意義不明 |
| `EDI` | call args | 兩次依序傳給 `0x504740`, `0x505570` | reader 實際成功／錯誤回傳及資料格式 |

## 需要續查的真實 call graph

`0x504370 → 0x504740 (QuestInfo reader candidate) → 0x505570 (QuestTalk reader candidate) → 0x4FF920`。這是初始化／本地快取鏈，不是 server completed quest writer。後續應對兩個 reader 的解析 loop、讀取檔名及節點 id 反查、分配／釋放與 client quest state 消費者做完整驗收，和 T15 的持久化保存責任分開。

## 目前仍缺的原件（DEFERRED-LOCAL-RESOURCE）

| 來源 | 來源 SHA256 | 目前不足的內容及影響 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | 缺具體 function bodies，無法確證全教學回呼 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 尚無 Quest15、Quest16 元素原文及前置規則 |
| Quest16 server 狀態 writer／原生 ACK、角色持久化來源 | unknown | 不能證明 Quest16 已完成、Quest15 可接或重登續接 |

不可把 T01 的來源稽核、QuestTalk 缺少兩筆的局部切片、或歷史 fixture 視為上述缺口已解。

