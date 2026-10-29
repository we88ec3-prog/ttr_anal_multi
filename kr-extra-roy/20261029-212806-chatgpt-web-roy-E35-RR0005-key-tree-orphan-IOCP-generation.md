# E35 — RR-0005：Connect 的 key tree 取代／孤兒 Conn、partial-failure 半關閉與 IOCP 物件重用界線

**本地完成時間**：2026-10-29T21:28:06+08:00（Asia/Taipei）。**研究工作分支**：預備 `extra/roy1`，本文件純本地未 Commit／Push。**RR 台帳狀態**：截至 GitHub main `e751b18922d205d86dea9f280cfd060f62752bc7`，RR-0005=`client_version=kr`, `owner_task=T02`, `priority=P0`, `status=PENDING`, `dispatch.state=QUEUED`, `dispatch.claim=null`。使用者明確要求**待 T01 整合完成再認領**；本次不變更 main、RR owner、claim、submission、任何 branch；本篇無 Git blob SHA。`extra/roy1` 開工版本 `6e16fd7260297f90dde6dc18bb8bc9d278f05af3`。其他 RR-0001/0004（傳輸封裝）及 T03/RR-0003（登入0x13）只作有界引用，不認領。

**原件校驗**：`Tartaros.bin` 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。分析只對 KR BIN 直接讀取 i386 bytes，用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00` 回譯 `.text`；`.text` raw offset0x400 ↔ VA 0x401000，故 raw = VA−0x400C00；`.rdata` raw0x7D0600 ↔ VA0xBD2000。所有本篇組語行直接由當次 BIN 反組譯抽取，保存 VA 和原 bytes；未執行、hook、連線、修改 Client。復用 GitHub main `kr-bulk-roy/<此 SHA>/functions/*.c` 的相同位址偽碼做導航，其內容不取代 BIN，亦非自動 T01 FULL-PASS。

**治理核對**：已重讀專案 `02-PROJECT-SHARED-INSTRUCTIONS.md` 及最新 main 的 `AGENTS.md`、T02 README/task.json、T01 README、`research/dispatch/README.md`、`inbox/T02.md`、RR 台帳及 `shared/verified-knowledge`，T02 README 無本輪需先處理的 T01 `NEEDS_FIX/FIXING` 欄位。T01 已審核的 `CK-CLIENT-ERASE-NEXT-ITERATOR-01` 指向 `0x7B6890` 的**純樹節點**處理，只能用於相同條件及 ABI，不能延伸成 Conn* cleanup 或任意 Server 行為。E31 的 node+0xC key、node+0x10 Conn*，與 E32–E34 的連線生命週期共同做本段入口。

## 0. 核心新增結論與證據級別

1. **原生有界已確認 — transport vtable slot ABI**：`.rdata` 連續表自 `0xC51748` 起 `+0x10 -> 0x8069A0`（按 key 找 Conn、將資料送入其 app queue）、`+0x18 -> 0x806AD0`（配置／Connect／取代 key tree node）、`+0x1C -> 0x806F60`（按直接 Conn* `shutdown(s,1)`）、`+0x20 -> 0x806F80`（按 key 找 Conn 後 `shutdown(s,1)`）、`+0x24 -> 0x806FC0`（按 Conn* 條件式 `shutdown(s,2)+closesocket`）、`+0x14 -> 0x806A00`（`WSARecv` post）。`+0x20(key,1)` 的第二參數在 `0x806F80` 沒有業務作用；不是 `closesocket` 或 keyed tree erase。此表不是 FUI RTTI 表。
2. **原生有界已確認 — half-close failure branches**：`0x4957C0` **先** connect key0/0x20E0，再 key2/0x20DE；只要一方成功、一方失敗，對成功 key 呼叫 virtual `+0x20`；該方法僅以 OS `shutdown(SD_SEND)`，該 caller 在失敗分支**未呼叫** `+0x14`/`+0x24`、未設 `A0B0`、未從 key tree erase。故不可稱為完整清理；是否別處最終 close 未證。
3. **原生有界已確認 — key tree 分工**：`0x806AD0` 成功建立 socket、完成選項設定與 IOCP 關聯之後，對相同 key 執行 `0x8438C0` lookup；若舊 node 存在，以 `0x7B6890` erase **node**，再分配 `0x18` node 寫入 `(key, new Conn*)` 並插入。`0x7B6890` 不解引用 node+0x10 作 full close，`0x806AD0` 也未對 old Conn 呼叫 `0x806FC0`。因此 **same-key replacement 並不是 old socket disposal**；若舊 Conn 未從其他通路關閉，其與 key tree 脫鉤的生命週期仍是 Client 待逆向。
4. **原生有界已確認 — delayed recycle 的閘僅依 send-post 計數**：`0x805B40` 在 pool+0x48 取回 Conn* 時只以 `Conn+A0B8==0` 判斷可否進 `0x805F50` reset/放回 pool+0x10；`0x806A00` 已 post 的 receive OVERLAPPED `Conn+A030` 不會在這支函式另行核對「recv outstanding 計數」。`0x806CF0` 的 IOCP GQCS 使用 completion-key **原 Conn***，所以在已 close、send count=0、recv completion 尚未被取走的假設下，存在**跨世代使用同一指標的風險條件**。尚不能聲稱實際觀察 UAF 或資料損毀：`Conn*` 由 pool 重用，不是此處直接 free，而且 Windows completion 排程未追 runtime。
5. **原生有界已確認 — connect/setsockopt error 直返未見 `closesocket`**：`0x806AD0` `connect==SOCKET_ERROR` 或三個 `setsockopt` 之一失敗，轉 `0x805AF0`/pool+0x48 然後 return zero；在本函式的這些路徑**沒有對剛建立的 SOCKET 執行 closesocket**，`0x805AF0` 也沒有 socket API，只做 pool 計數／list 操作。若後來 `0x805B40 → 0x805F50`，FD 被重設為 `-1`，本鏈看不到 closesocket。這是**有界的可能 handle 泄漏/孤兒風險**，不能無條件聲稱全程序必然永久泄漏。
6. **原生有界已確認 — key sender 不檢 socket 狀態**：`0x8069A0` 按 key 搜尋 node+0x10 Conn*，有值就可能呼叫 `0x8060D0` 入列；沒有檢 `Conn+A0A8`、`A0AC` 或 SOCKET有效性。當長度=0時更直接回傳1。因此 **key lookup 成功、甚至 enqueue 成功都不代表 key 的 socket 存活或已提交 wire send**。若舊 key map 保留同一指標而 Conn 已回 pool 重用，可能產生 stale-key alias；這是基於具體條件的**合理風險推論**，非已證執行事件。

RR-0005 尚未閉合：各 key 的**第一個確切 wire frame / first S2C reply**、跨連線競態及完整 map 清除者需繼續；不可依硬編碼 port 推出官方部署政策。以下各節保留直接機器碼與反證範圍。

## 1. 第一輪：transport vtable、精確 key lookup 與選服 partial-failure

### 1.1 實際 `.rdata` 表的 dword 定位與函式對應

在 BIN `.rdata` raw `0x84FD48` 起按 DWORD 讀，轉 VA `0xC51748`，得到（值均直接從檔案讀取，非猜測函式表）：

| 表 entry VA | slot offset | pointer | 本段確認的限定用途 |
|---|---:|---|---|
| `0xC51748` | +0x00 | `0x806670` | constructor/destructor 類方法；本段非主題 |
| `0xC5174C` | +0x04 | `0x806CF0` | GQCS/IOCP worker |
| `0xC51750` | +0x08 | `0x806850` | IOCP work item/event helper |
| `0xC51754` | +0x0C | `0x8068B0` | WSASend post |
| `0xC51758` | +0x10 | `0x8069A0` | key→Conn app enqueue |
| `0xC5175C` | +0x14 | `0x806A00` | WSARecv post（直接 Conn*） |
| `0xC51760` | +0x18 | `0x806AD0` | key-specific socket connect + indexed insert |
| `0xC51764` | +0x1C | `0x806F60` | direct Conn* `shutdown(s,1)` |
| `0xC51768` | +0x20 | `0x806F80` | key→Conn `shutdown(s,1)` |
| `0xC5176C` | +0x24 | `0x806FC0` | Conn* full close and delayed recycle list |
| `0xC51770` | +0x28 | `0x807090` | pre-existing socket IOCP association/recv post (no key insert seen) |

`0xC51744` 是前置的 `0xC812E8` pointer，這個相鄰數字不代表它是 slot0；至少上述 pointer sequence 與 `0x4957C0`/`0x495610` 使用的 offset 完全吻合。請勿將 `0xC51748` 的傳輸表誤認成 E32 `FUI::CServerSelectDialog` vtable `0xC1C394`。

### 1.2 key→Conn 只做 lookup（讀 node+0x10），並非 liveness check：`0x8069A0`

依此函式的 raw bytes，先 `0x8438C0` 在 transport `self+0x18` 的 tree 搜尋指定 key；取得 node 後只檢它是否 sentinel 及 `node+0x10` 是否 nonzero；`param3==0` 直接回1，否則 `ecx=Conn*` 呼叫 `0x8060D0`。沒有在這個方法讀取 Conn SOCKET、`A0A8`/`A0AC` 或 send outstanding。

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
```
**`0x8438C0` 的鍵條件**：這個方法以有序樹節點的 `node+0xC` 相對於輸入 key 做 lower-bound；於輸出前有 `candidate.key <= request` 的排除檢查，搭配遍歷 `candidate.key >= request`，在有效 key/tree invariant 下才是 exact-key-or-sentinel。不是任意 node 或任意最小 key 的查找。以下仍只對正常合法樹條件有效。

```asm
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
  843924:	c2 04 00             	ret    0x4
  843927:	cc                   	int3
  843928:	cc                   	int3
  843929:	cc                   	int3
  84392a:	cc                   	int3
  84392b:	cc                   	int3
  84392c:	cc                   	int3
  84392d:	cc                   	int3
  84392e:	cc                   	int3
  84392f:	cc                   	int3
  843930:	b8 3c af f7 00       	mov    eax,0xf7af3c
  843935:	c3                   	ret
  843936:	cc                   	int3
  843937:	cc                   	int3
  843938:	cc                   	int3
  843939:	cc                   	int3
  84393a:	cc                   	int3
  84393b:	cc                   	int3
  84393c:	cc                   	int3
  84393d:	cc                   	int3
  84393e:	cc                   	int3
  84393f:	cc                   	int3
  843940:	55                   	push   ebp
  843941:	8b ec                	mov    ebp,esp
  843943:	6a ff                	push   0xffffffff
  843945:	68 31 e3 90 00       	push   0x90e331
  84394a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  843950:	50                   	push   eax
  843951:	83 ec 10             	sub    esp,0x10
```
### 1.3 按 key shutdown 不會移除 key：`0x806F80` 與 +0x1C 的直接 socket 版

`0x806F80` 重用同一 `0x8438C0` tree lookup；若 node/Conn* 有效，讀 `Conn->socket` 並用 `push 1` 呼叫 WinSock `shutdown`。函式返回時沒有 `0x7B6890`、`0x805A80`、`0x806FC0` 呼叫或 `A0B0` 寫入；其 stack `ret 8` 並不代表使用第二參數作 graceful-close wait。`+0x1C/0x806F60` 是直接 Conn* 的 SD_SEND，兩者輸入不同。

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
### 1.4 `0x4957C0` partial success/failure 的精確兩條路徑

- `key0=0x20E0` Connect 先執行（return `EDI`）；`key2=0x20DE` Connect 後執行（return `EBX`），兩者都透過 `+0x18 → 0x806AD0`。
- **key0 成、key2 失**：`0x49597E..0x4959AD` 發送 `+0x20(key=0,arg2=1)`，走 `0x806F80` 的 `shutdown(SD_SEND)`，回傳零。這一分支沒有 `WSARecv(+0x14)`、沒有 `closesocket(+0x24)`、沒有 `A0B0=1`。
- **key0 失、key2 成**：`0x4959B0..0x4959DB` 發送 `+0x20(key=2,arg2=1)`，同樣只有 shutdown；key0、key2 皆失則不發 shutdown，回傳零。
- **兩個都成**：才進 old BF60 清 queue/0x007E/A0B0，Sleep400，對 key0 enqueue 0x0001/0x39，才分別 `+0x14(Conn0)`、`+0x14(Conn2)`，更新 BF64/BF68。單條 connect 已成功**不等於**同 caller 已 post WSARecv。

```asm
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
```
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
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
```
**限定結論**：現有部分失敗返回 path，成功一方的 Conn socket 仍被 keyed tree 引用（在同一函式中未 erase），且只執行 SD_SEND；原生 `closesocket` 的其他所有呼叫者、外部 TCP 關閉、timeout 及後續重試都不包含在這段直接證據。不能把這個 failure branch 誤記為「釋放 key0/key2 slot」。

## 2. 第二輪：key tree 同鍵覆蓋與 connect 失敗清理的兩個獨立 ownership hole

### 2.1 `0x806AD0` Connect 完成後才覆蓋 key map，舊 Conn* 未在覆蓋路徑 dispose

- `0x806B16` 先從 `pool+0x10` 取得/配置新 Conn*；`0x806B2A/0x806B33` 設定 Conn+`A0B4=2` 及 Conn+`A080` ；取得 hostname、WSASocket、connect。
- `0x806C32` 起設定三個 socket options；`0x806C87` 執行 `CreateIoCompletionPort(socket,port,completionKey=Conn*,0)`。
- `0x806C91..0x806C9E` 依 `self+0x18` keyed tree 對當次 key 做 `0x8438C0`，`0x806CA7` 比對 sentinel；若舊 node 存在，`0x806CB3` 對 **node** 呼叫 `0x7B6890`，不呼叫 close 舊 Conn。
- `0x806CB8..0x806CD2` 分配 `(key, Conn*)` 的 `0x18` node、insert；`0x806CDD mov eax,ebx` **證明 +0x18 在成功返回新 Conn***，這點比舊 `0x806ad0.c` 的 void 錯誤原型更精準。

```asm
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
  806cea:	c2               	ret    0x10
```
`0x7B6890` 由 T01 另有 **CK-CLIENT-ERASE-NEXT-ITERATOR-01** 有界 FULL-PASS：它是 tree-node unlink/rebalance/free，不能推論 node+0x10 Conn* 亦被 full close。E31 也證明 `0x57EF20` 寫 node+0xC key、+0x10 Conn*；此節在 BIN 再回歸核對成功 Connect 語意。

### 2.2 兩種「舊 Conn」的不同結果：切換 key vs 相同 key 再 Connect

| 情境 | 直接路徑 | BIN 證成 | 不得擴張 |
|---|---|---|---|
| `key0` 上已存 old Conn A，新 `key0` 成功 Connect B | `0x806AD0` find/erase old tree node，insert `key0→B` | **已證 old node 移除，未在這條路徑 close A** | A 必然泄漏、A 其他執行緒永不回收均未證 |
| `key0` 上 old Conn A 經 `+0x24` 已 close 並回池，後來 `key1` 使用同 Conn 物件 A | `0x806FC0→805A80→490FE0→805B40→805F50→805950→806AD0(key1)` | 各步有原生證據；`+0x24`/pool reset 範圍內沒有 tree erase | 是否真抽到同地址 A、其他地方清 old key 尚未知；**stale-key→new-Conn alias 是條件性風險** |
| `key0` Connect成功、`key2` Connect失敗 | `0x49597E→806F80(key0)` | 在 failure caller 僅 SD_SEND，成功 key tree node 未移除，沒 post recv | OS 當下回收 socket、Server ACK／自動清理不成立 |
| `connect()` / `setsockopt()` 同函式失敗 | `0x806AD0→805AF0` | 直接 `return 0`，**尚未插 key tree**，失敗支線無 `closesocket` | 要區分「無 key node」與「SOCKET handle 已釋放」 |

### 2.3 `0x806AD0` connect failure / 3種 setsockopt failure 分支的排他證據

`WSASocket` 的回傳存在 `Conn[0]`；連線失敗後 `0x806BD4/0x806BFB` 呼叫 `0x805AF0` 並 `xor eax,eax; ret 0x10`。三個 `setsockopt` 任一回傳 `-1` 也跳至 `0x806C00` 同一條零返回。從取得 SOCKET 到返回的所有可達路徑中，這些 fail 分支均無 `0xBD25D4` (`closesocket`) API 或 `+0x24` 虛擬呼叫；也沒有對 key tree insert。`0x805AF0` 自己只處理 pool 的 list / count、Conn+0x14，並不關 FD。此處是**有界的失敗清理缺漏**，日後 Server 實作不能假定失敗的 Client 從不保留半成品 socket。

```asm
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
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
```asm
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
```
**路徑唯一性檢查**：本輪解析全 `.text` 中 direct `E8 → 0x805AF0` 僅 `0x806BD4`、`0x806BFB`；`0x805A80` direct call 為 `0x807045`。若存在 indirect call 仍可能漏掉，所以只是**明確可重現的直接 xref 結果**，不是全程序生命週期的全域否證。

### 2.4 key map 不應等同 free Conn 池：`0x806FC0` vs `0x805B40`

真正 full-close `0x806FC0` 在 `A0A8==0` 且 socket 有效時：以 `param2` 低 byte 判斷是否加 `setsockopt(0xffff,0x80)`，接著 `shutdown(s,2)`、`closesocket(s)`、`0x805A80(Conn*)` delayed list。沒有對自己 transport keyed tree 的 `0x8438C0/0x7B6890` 搜尋/移除。後面 `0x805B40` 收 Conn 時也沒有逐 key tree cleanup；只於 send-post `A0B8==0` 的範圍內 `0x805F50` reset、push pool free deque。這**不是全程沒有任何移除機制的證明**，但已足以反駁「在 full-close 方法內必同步解除 keyed map」。

```asm
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
```asm
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
## 3. 第三輪：IOCP recv outstanding、pool 重用與跨世代的證據邊界

### 3.1 Conn 的兩個 OVERLAPPED 與實際 completion-key 是 raw `Conn*`

- `Conn+A030` 是 `WSARecv` OVERLAPPED；`0x806A0A` 構造 `Conn+A030`，`0x806A4C` 透過 Winsock import post recv。`0x806CF0` 的成功分支判斷 `returnedOverlapped == completionKeyConn+A030`，再 parser/read callback；某些路徑會再呼叫 vtable+0x14 重發 receive。
- `Conn+A050` 是 `WSASend` OVERLAPPED；`0x8068B0` submit 後於成功或 `WSA_IO_PENDING` 分支對 **Conn+A0B8** 遞增；`0x806CF0` 的 send completion 或 GQCS 失敗但可辨識 send overlapped 路徑，對同欄位 `InterlockedDecrement`。
- `0x806AD0` 的 `CreateIoCompletionPort` completion key 傳入 `Conn*` (`0x806C84 push ebx`)；`0x806CF0` 自 GQCS 取得 completion key，後續直接將此 pointer 與 overlapped offset 比對。沒有看到在這些分支先比對 session/generation token、tree key 或 FD identity。

```asm
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
```
```asm
  806c7c:	a0 f9 ff ff 8b       	mov    al,ds:0x8bfffff9
  806c81:	10 6a 00             	adc    BYTE PTR [edx+0x0],ch
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
```
```asm
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
```
```asm
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
```
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
```
### 3.2 pool recycle 只檢 A0B8，未另核對 recv pending 或 object generation

`0x805B40` 先檢 closed list 的條件，後在 pool+0x48 list 取 `Conn*`，於 `Conn+A0B8==0` 直接調用 `0x805F50`，將 SOCKET 設為 `0xFFFFFFFF`、active flag 重設、outbound queue 重設；之後將 Conn* 放回 pool free deque。`0x805950` 若 free deque 非空則取回**相同記憶體物件**、再做一次 `0x805F50`、設 `A0AC=1`、pool+0x44 參考計數++；由下一輪 `0x806AD0` 對此物件呼叫 `WSASocket/connect`，沒有在這條路徑清運 keyed tree 其他 node 指向其地址。

```asm
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
```
```asm
  805950:	55                   	push   ebp
  805951:	8b ec                	mov    ebp,esp
  805953:	6a ff                	push   0xffffffff
  805955:	68 2b 5a 91 00       	push   0x915a2b
  80595a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805960:	50                   	push   eax
  805961:	83 ec 0c             	sub    esp,0xc
  805964:	53                   	push   ebx
  805965:	56                   	push   esi
  805966:	57                   	push   edi
  805967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80596c:	33 c5                	xor    eax,ebp
  80596e:	50                   	push   eax
  80596f:	8d 45 f4             	lea    eax,[ebp-0xc]
  805972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805978:	8b f9                	mov    edi,ecx
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
  8059fe:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  805a01:	74 5b                	je     0x805a5e
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8         	call   0x891268
```
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
```
### 3.3 不能過度推論：這是「物件世代」而非已證 UAF

1. `Conn+A0B8` 是 send outstanding 計數，原生 `0x806A00` post recv 並未對 `A0B8` 遞增；因此 **`A0B8==0` 不能作「全部 recv/send completion 都已清空」的必要充分條件**。
2. `0x806CF0` 會讀 GQCS completion key 中的 Conn*；若 late recv completion 在 pool reset 且同物件已給新 socket 使用之後發生，存在對舊 session 的 completion 使用新 generation object state 的條件性風險，須由 runtime trace/更多 producer/其他同步保證反證或確認。
3. 不能聲稱 `closesocket` 保證立即完成所有 IOCP 結果或 Conn 立即 free；本案 `Conn*` 是 pool 裡可重用的 heap 物件，嚴格用 **stale completion / generation alias**，不要未驗先寫 use-after-free。
4. 即使 keyed-map 沒有在 full close 本身 unlink，也可能在其他未知函式／全域 teardown 清除；本段 claim 僅限已查路徑，不能下「全局永遠 stale」絕對結論。

### 3.4 其他明確有界的初始收發路徑

- `0x806AD0` 是同步 Connect + socket options + IOCP 關聯 + tree map insert，**自己沒有 `WSARecv`/`WSASend` payload call**；它回傳新 Conn* 給 caller。
- `0x495610` login：`mode=0 && client+BF60 != null` 直接返回1，不重新檢 socket liveness；`mode!=0` 對 key0/key2/有條件 key1 發 +0x20(SD_SEND) 並清 BF60，然後於 legacy port `0x20DF` key1 Connect。成功後先 `+0x14(Conn1)` post WSARecv，再設 BF60，`Sleep(500)`，回1。**沒有在此函式內 enqueue 0x0081**；該候選由上層 `0x495280/0x6D64C0` 另呼叫。
- `0x6D64C0` 在成功呼叫 `0x495610` 後透過 `0x6D6B70` 構成 `0x0081` 的 `0x38=56-byte` app payload 並透過 virtual +0x10(key1) queue；不證第一 wire frame。
- `0x4957C0` dual success：在真正 `+0x14` 收包 post **之前**，先對新 key0 `+0x10(0,localPayload,0x39)` queue；同一 caller 沒有對 key2 直接 enqueue 業務 payload；worker 可並行，所以既不證首個 WSASend，也不證首次 reply。
- `0x8069A0` 的 virtual sender 對 key node存在、Conn pointer非零即接受到 app queue；`param3=0` 可直接回1而**不 enqueue**，提醒不要把 success return1一律當 queued/send。`0x8060D0` 另有其自己的 enqueue guard。

```asm
  495675:	89 3d c0 41 f9 00    	mov    DWORD PTR ds:0xf941c0,edi
  49567b:	75 25                	jne    0x4956a2
  49567d:	b8 01 00 00 00       	mov    eax,0x1
  495682:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  495688:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  49568c:	e8 ff be 04 00       	call   0x4e1590
  495691:	68 80 cc bc 00       	push   0xbccc80
  495696:	e8 7f cc 3f 00       	call   0x89231a
  49569b:	83 c4 04             	add    esp,0x4
  49569e:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4956a2:	6a 0a                	push   0xa
  4956a4:	68 fc d1 be 00       	push   0xbed1fc
  4956a9:	6a 0b                	push   0xb
  4956ab:	68 c4 41 f9 00       	push   0xf941c4
  4956b0:	e8 49 e9 3f 00       	call   0x893ffe
  4956b5:	83 c4 10             	add    esp,0x10
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
```
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
  495968:	b8 01 00 00 00       	mov    eax,0x1
```
### 3.5 具體可驗證的可重入／重試情境（僅作測試設計，不宣稱實測）

| 測試 case | 觸發方式 | 預期檢查的 Client 內部現象 | 仍缺的 runtime evidence |
|---|---|---|---|
| A key0 成/key2 失 | 僅 key0 server 可連而 key2 不可 | `+0x20(key0)` 的 `shutdown(SD_SEND)`；key0 map node 仍存在，該 caller 無 `+0x14`/full-close | SOCKET lifetime、retry 對 key0 node/old Conn handling |
| B key0 失/key2 成 | 僅 key2 server 可連 | `+0x20(key2)` 半關閉；與 A 對稱 | 同上 |
| C same-key retry | 先成功 connect(key1)，再 forced connect(key1) | 新 `0x806AD0` 移除 old key1 node；node+0x10 Conn* 不在此處 close | old Conn* 是否另外 close／延後池 / IOCP |
| D close→reuse different key | 關閉 old key0，再建立 key1，強制 pool 命中同 Conn* | 驗證 old key0 是否仍能命中 node+0x10，是否 alias key1 Conn* | 其他 map removal/teardown、pool reuse 實際順序 |
| E close with recv pending | 已 post WSARecv，full-close 後不立即處理 completion | `A0B8==0` 允許 pool reset，但 recv OVERLAPPED 是否晚到、是否有世代 guard | GQCS 時序、外部同步與 Windows OS 行為 |
| F connect() failed | 拒絕服務端口/異常網路 | `0x806AD0` failure → `0x805AF0`；檢查 handle count 是否成長 | 實際 WinSock handle/OS 釋放條件 |

上述只供日後合規測試契約；專案政策禁止本研究執行原始 Client，除非另有合法環境／使用者確認的測試作業。

## 4. 來源反證、證據分級與影響 RR-0005 的可供 T01/S00 整合主張

| 精確主張 | 本段等級 | 直接 BIN 依據 | 限制 |
|---|---|---|---|
| key lookup → slot+0x10 Conn pointer；`+0x10` 按 key 入列不驗 socket state | 原生有界確認 | 0x8069A0–0x8069F3 / 0x8438C0 | 有效 key/tree、後續 queue guard 另論 |
| partial connect failure 只對成功 key 發 `shutdown(1)`，當前 caller 未完整 close | 原生有界確認 | 0x49597E–0x4959DB / 0x806F80–0x806FBA | 不排除下游/其他執行緒另有 cleanup |
| Connect 同鍵覆蓋 = old node erase + new node insert；沒有同路徑舊 Conn close | 原生有界確認 | 0x806C91–0x806CEB，T01 7B6890 有界結論 | 不可推論全域永久泄漏 |
| Connect / setsockopt failure 以 pool list 返回0，該條路徑沒有 closesocket | 原生有界確認 | 0x806B8C–0x806C13 / 0x806C34–0x806C79 | 待其他 path/WinSock runtime 驗證 |
| IOCP completion key 是原 Conn*；recv/send OVERLAPPED+0xA030/+0xA050 | 原生有界確認 | 0x806C82–0x806C87 / 0x806A0A–0x806A4C / 0x806DCF–0x806EAB | 看靜態局部，不宣稱實際 interleave |
| delayed recycle 只以 A0B8==0 作正向重用閘，未檢 recv outstanding | 原生有界確認 | 0x805BA6–0x805BB7 / 0x805950 | 其他同步/OS completion safety 未證 |
| old key alias 到新世代 Conn、late recv completion 影響新世代 | **合理的條件性風險，不是實測事實** | 合併前述各條功能鏈 | 必須實測或補上「absence of other cleanup」的完整追查 |

**否證/限制清單**：

- 不把 `shutdown(SD_SEND)` 當 `closesocket`；不把同鍵 tree node erase 當 conn/socket disposal。
- 不把 `A0B8==0` 當所有 overlapped recv 都已完成；但也不直接聲稱必然造成 UAF。
- 不把 `0x8069A0` return1 當正常封包必達；它在 length0 會 return1不入列。
- 不把 `0x4957C0` 的 `Sleep(400)` 當所有 key 的 wire frame 全序。
- 不把 `0x20DF/0x20E0/0x20DE` 的 KR Client 靜態 port 當部署／Server 官方 endpoint 設計要求。
- 不把 T01 的 tree erase FULL-PASS 自動擴成整篇 E35 或 T02 FULL-PASS；不使用本篇直接修改 claims/verified-knowledge。

## 5. 四類剩餘工作與 E36 入口

**Client 待逆向**：完整排查 keyed-tree 在 transport destructor/flush/stop (`0x806670`、`0x807090`、上游 singleton teardown) 是否另有 clear/delete；建全局 `.rdata` transport vtable xrefs 和所有 `+0x24`/`+0x20` callsites，確認 `old key` 的其他持有者；找 `Client+BF60/BF64/BF68` 失敗重試／斷線時的實際 writer/clear；補 `0x8069A0` queue→active gate 的實際 per-conn first WSASend、first S2C parse/dispatch。進一步對 `0x806CF0` recv failed GQCS completion (0 bytes、success) 的 late arrival 再做 generation-safe 界線。

**Server 待開發**：連線交換過程應能容忍 Client 對一條成功 socket 發 SD_SEND、且未必立即 close/receive；Server 對錯誤／重試/斷線的兼容策略屬自訂設計，需 ADR 明確標示，不能冒稱原版部署語意。系統設計不得依 local key tree return1 推斷封包交付成功。

**跨功能待整合**：T02 RR-0005 owner 類型；T02 RR-0001/0004 framing／first wire 只引用；T03 RR-0003/0008 對 `0x13` 與 UI payload 只引用；T01 原生證據與 S00 風險分流/規格審查分別處理，依使用者要求在這輪**等待 T01 整合後才認領**。

**待遊玩驗證**：同版 KR Client ↔ 人工測試 Server 的 socket tracing (handle ID, key, Conn pointer/generation, address/port, post WSARecv/WSASend, complete, full-close, map erase, object reuse) 與 pcap/ETW 誤差檢核；本段沒有執行 Client，也不能得出真實 first C2S/S2C frame 結果。

## 6. 三輪深入與重現操作／完整性

- **Round1**：核實 `0xC51748` vtable、`0x8069A0` keyed sender、`0x806F80` key shutdown 與 `0x4957C0` partial failure，找到原來沒有閉合的「成功連線卻只半關閉」分支；已達重大新發現門檻。
- **Round2**：反查 `0x806AD0` 的 same-key `0x8438C0→0x7B6890→0x57EF20→0x57E850`、connect/setsockopt fail 轉 pool+0x48 而非 close，完成限定 ownership 對照。
- **Round3**：沿 IOCP completion-key=Conn*、`A030/A050`、`A0B8`、`0x805B40→0x805F50→0x805950`，確認 delayed recycle 的**send-only** gate 並界定可能跨世代競態；不把 race scenario 冒充故障實測。雖首輪已達門檻，仍向下驗至這兩輪。

本地重驗：

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
python /mnt/data/e35_scan.py           # 在已驗 SHA 的 BIN .text 範圍掃 direct-E8 與 dword immediate（僅導航）
python /mnt/data/e35_extract.py        # 23 組指令範圍直接 objdump，保存 1889 lines machine-code evidence
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x806990 --stop-address=0x8069f6 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x806b82 --stop-address=0x806ceb /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x805b40 --stop-address=0x805c68 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x806cf0 --stop-address=0x806f56 /mnt/data/Tartaros.bin
```

`e35_raw_snippets.txt` 是本地輔助全量摘錄，正式重要原生 excerpts 已納入此 Markdown。若工具由中間 instruction 開始產生 `(bad)`，該片段不作指令證據，改用下文一致的 true function entry/branch 起點。所有地址取 KR 版本專用，未代入 TC。

GitHub：**未 Commit、未 Push、未認領 RR、未提交 T01/S00**。下一段 E36 若仍接 RR-0005，優先要把 keyed-map **所有不同入口的清除者**與 transport singleton teardown 補閉合，並追 Conn 斷線 callback 如何更新 `Client+BF60/BF64/BF68`；其次才補 0x13→UI 本地事件橋接；各 connection first wire 仍需真實時序與 path cover，不可硬猜。
