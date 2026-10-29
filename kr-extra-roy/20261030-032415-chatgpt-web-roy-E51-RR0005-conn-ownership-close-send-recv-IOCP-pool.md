# E51 — RR-0005／KR T02：Conn ownership、same-key replace、close/Pool、WSASend/WSARecv、IOCP 與初始封包（15 個目標導向研究單元）

- **正式段號**：E51（E51.1～E51.15 是同一份正式段號內的研究單元，不是 15 份獨立報告）。
- **本地成稿時間 Asia/Taipei**：`2026-10-30T03:24:15+08:00`；研究識別 `chatgpt-web roy`。
- **證據**：原始 KR `/mnt/data/Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；靜態唯讀，不執行、修改或附加遊戲。
- **遠端首次開工核對（讀取時點）**：`main=b333883409e7895c0a1ebb67b71346b499804c2a`，`extra/roy1=29f3c50ff64d8f788d05d9846dbaac17b4e27745`；E50 既有 blob `f4bd62ce69cf96cc35b566bf62721a586f4f51c7`，檔名 `kr-extra-roy/20261030-022552-chatgpt-web-roy-E50-RR0005-map-replacement-pool48-atomic-IO-lifecycle.md`。
- **RR-0005 真實狀態**：KR、owner T02、GAP-NET-0002、P0；`status=PENDING`、`dispatch.state=QUEUED`、`claim=null`、`submission=null`。本次既無 Git 提交授權，也不修改台帳；**本檔尚未 Commit／Push，沒有遠端 blob SHA**。
- **GitHub 開工來源**：最新 main 的 `AGENTS.md`、`kr/tasks/T02/README.md` 與 `task.json`、`kr/tasks/T01/README.md`、`research/dispatch/README.md`、`research/dispatch/inbox/T02.md`、`research/requests/index.json`、`shared/verified-knowledge/README.md`、`shared/integrations/T01-BULK-20261026-02/README.md`、`spec/protocol/T02-EVIDENCE-INVENTORY.md`；T02 README **沒有獨立「## T01 驗收退回事項」現行專節**，不能因此推稱其他 Task 的審查結果可被提升。共用 FULL-PASS 的七筆有界條目目前**未提供 RR-0005 完整端到端的驗收結果**。
- **E50 只供導航與已證基線**；本輪用獨立 BIN 原件重新跑全部下列功能節點的 disassembly、raw/VA 與 IAT/vtable。T03 handler 與業務語意只引用，不接管其 owner。

## 證據方法、符號與限制

`N` = 本輪原始 PE / code bytes 可直接確認；`C` = 明確前提下的 CFG、所有權與資料流條件推論；`U` = 靜態無法閉合（尤其並發、間接 writer、真正 wire、Server 端點與 UI 實際執行）。`Conn`、`Pool`、`Manager` 都是暫名；不能從同 offset 推出同型別。

原生 PE32 `.text`：VMA `0x401000`、file raw `0x400`、size `0x7D01F0`，所以指令 raw=`VA−0x400C00`；`.rdata` VMA `0xBD2000`、file raw `0x7D0600`，故該段 raw=`VA−0x401A00`；`.data` VMA `0xD61000`、file raw `0x95E800`。本輪以 `objdump -h` 和 `objdump -p` 從**原件**重新確認。下列反組譯以 `.text` 從 raw `0x400` 擷取的原始 bytes，將其調整起點 VMA 為 `0x401000`，**從已知函式入口解碼**，避免 E50 部分任意起點的 `(bad)` 假指令。虛擬 target 先從 `.rdata` 原始 32-bit little-endian table 映射，再以 caller 進行交叉確認。


## E51.1 — 版本、API import、管理器 vtable 與 ABI 重新定位

**研究問題**：核實真正的 Winsock/IOCP/atomic API 入口與各種互不相同的虛擬方法，避免把「按 key shutdown」誤作「依 Conn closesocket」。

**N：`.rdata` 中 vtable `0xC51748` 的實際 DWORD 指向**：`+00→0x806670`（deleting destructor）；`+04→0x806CF0`（IOCP worker）；`+08→0x806850`（thread registration）；`+0C→0x8068B0`（WSASend post）；`+10→0x8069A0`（依 key 排出站）；`+14→0x806A00`（WSARecv post）；`+18→0x806AD0`（Connect）；`+1C→0x806F60`（簡單 shutdown）；`+20→0x806F80`（shutdown-by-key）；`+24→0x806FC0`（close-by-Conn／Pool+28）；`+28→0x807090`（另一條 Conn 配置＋IOCP 關聯）。相應原始 bytes 由 `.rdata raw 0x84FD48` 起逐 DWORD 小端解碼（注意 **不是** `.text` bias）。

**N：原始 PE import**：`IAT VA 0xBD2274=GetQueuedCompletionStatus`、`0xBD2278=CreateIoCompletionPort`、`0xBD227C=InterlockedDecrement`、`0xBD2280=InterlockedExchange`、`0xBD2284=InterlockedIncrement`、`0xBD22D4=GetTickCount`、`0xBD25B8=WSASend`、`0xBD25BC=WSARecv`。部分 WS2_32 IAT 是以 ordinal import，不能假裝 PE name table 全部寫了 `shutdown/connect/closesocket`；依 ordinal 和 32-bit ABI 推導 `0xBD25C8` 為 shutdown、`0xBD25D4` 為 closesocket，並把名稱來源標清楚。

**ABI**：vtable 的四位元組位移是 slot byte offset；`Manager` 以 ECX 傳 this；`0x806AD0` 對外使用堆疊四個 4-byte 參數並 `ret 0x10`。`0x806F80` 是 `ret 8`；`0x806FC0` 是 `ret 8`；`0x8069A0` 是 `ret 0xC`，和 selection caller 的 push 數相符。

**反證**：E50/E48 不應因指向某個 connection 的 shutdown 就推稱其所有資源或 key-map node 被釋放。此處只確認本 vtable 的 method dispatch，不能宣稱所有動態物件都使用同一 vtable。


```text
VA 0x00C51748  raw 0x0084FD48  little-endian DWORD 0x00806670  bytes 70 66 80 00
VA 0x00C5174C  raw 0x0084FD4C  little-endian DWORD 0x00806CF0  bytes f0 6c 80 00
VA 0x00C51750  raw 0x0084FD50  little-endian DWORD 0x00806850  bytes 50 68 80 00
VA 0x00C51754  raw 0x0084FD54  little-endian DWORD 0x008068B0  bytes b0 68 80 00
VA 0x00C51758  raw 0x0084FD58  little-endian DWORD 0x008069A0  bytes a0 69 80 00
VA 0x00C5175C  raw 0x0084FD5C  little-endian DWORD 0x00806A00  bytes 00 6a 80 00
VA 0x00C51760  raw 0x0084FD60  little-endian DWORD 0x00806AD0  bytes d0 6a 80 00
VA 0x00C51764  raw 0x0084FD64  little-endian DWORD 0x00806F60  bytes 60 6f 80 00
VA 0x00C51768  raw 0x0084FD68  little-endian DWORD 0x00806F80  bytes 80 6f 80 00
VA 0x00C5176C  raw 0x0084FD6C  little-endian DWORD 0x00806FC0  bytes c0 6f 80 00
VA 0x00C51770  raw 0x0084FD70  little-endian DWORD 0x00807090  bytes 90 70 80 00
```


**BIN 原生指令摘錄**（原件 `.text`：0x00806F60–0x00806FC0；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  806f60:	55                   	push   ebp
  806f61:	8b ec                	mov    ebp,esp
  806f63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f66:	8b 08                	mov    ecx,DWORD PTR [eax]
  806f68:	6a 01                	push   0x1
  806f6a:	51                   	push   ecx
  806f6b:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806f71:	5d                   	pop    ebp
  806f72:	c2 04 00             	ret    0x4
  806f75:	cc                   	int3
  806f76:	cc                   	int3
  806f77:	cc                   	int3
  806f78:	cc                   	int3
  806f79:	cc                   	int3
  806f7a:	cc                   	int3
  806f7b:	cc                   	int3
  806f7c:	cc                   	int3
  806f7d:	cc                   	int3
  806f7e:	cc                   	int3
  806f7f:	cc                   	int3
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
  806fbd:	cc                   	int3
  806fbe:	cc                   	int3
  806fbf:	cc                   	int3
```


## E51.2 — same-key replacement：舊 Conn* 是否被保存或釋放？

**研究問題**：新 Conn 已成功建置並完成 IOCP 註冊後，以同 key 取代舊 map node 時，舊 Conn* 是否沿本函式繼續可達？

**N：`0x806C91–0x806CD2`**：`[ebp+0x10]` 為 key，`Manager+0x18` 為 active tree（它的 `+4` 為 sentinel）；`0x8438C0` 找到 node，`[esp+0x14] != Manager+0x1C` 時，直接呼叫 `0x7B6890` erase（實參為 tree、local iterator 與舊 node）；接著將相同 key 以及 **EBX 新 Conn*** 交 `0x57EF20→0x57E850` 建新 node。此段沒有 `mov oldConn,[node+0x10]` 的保留動作；erase 之後局部暫存被覆寫成 key/newConn。

**N：互相補強**：active tree node 的 `+0xC` 存 key、`+0x10` 存 Conn*；erase helper 會 detach/free **tree node**，而非依 value 指標呼叫 `0x806FC0`。此 Conn 的 socket 保存在 `Conn+0x00`；node free 不能變成 socket close。

**C：遺失條件**：如果舊 Conn* 的唯一 owner 是這棵 active map，而且其餘 callback/Pool list 不持有舊指標，新 node 插入後舊 Conn 會失去該 map 的可達性。這是**靜態可能性**，不是已觀測 leak。`0x495610` 曾對 key0/key2 呼叫 shutdown，但那不是 close-by-Conn；`0x4957C0` 本函式也未先關閉所有舊 Conn。

**未解**：上游是否持有別名、是否有未建模背景清理／例外 branch、同 key 重連在真實 UI 是否會重入。見 E51.15 的測試契約。


**BIN 原生指令摘錄**（原件 `.text`：0x00806C7B–0x00806CEA；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
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
```


**BIN 原生指令摘錄**（原件 `.text`：0x008438C0–0x00843925；raw=VA−0x400C00；來源 SHA 見文件首）：

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
```


## E51.3 — key shutdown 與 Conn close 的完全不同 API/side effect

**N：`0x806F80`（vtable+0x20）** 用 active tree 找指定 key，若找到 node+0x10 非空則讀 `Conn+0` socket，執行 `push 1; push socket; call [0xBD25C8]`，ABI 是 `shutdown(s,SD_SEND)` 類型；沒有在這個函式呼叫 closesocket／Pool enqueue／map erase。找不到 key 直接退出。

**N：`0x806FC0`（vtable+0x24）** 先取 Pool mutex `Pool+0x34`；當 `Conn+A0A8==0` 且 socket 非 0、非 -1 時，可先呼叫 setsockopt linger 類操作（取決於第二個參數），然後呼叫 `[0xBD25C8]` shutdown 和 `[0xBD25D4]` closesocket，隨後 `0x49B070` 取 Pool 單例、`0x805A80` 寫 Pool+0x28。這一段無 map erase。其餘返回／mutex release 見完整反組譯。

**對照：`0x4957C0` 當 key2 連線失敗時對 key0 用 vtable `+0x20`；當 key0 失敗而 key2 成功時，對 key2 用同個 `+0x20`。這不是 vtable `+0x24`，故只是 shutdown。**

**反證**：不能將「呼叫 +0x20，之後 no map entry」當作事實；也不能將 `0x806FC0` 追蹤 Pool+28 解釋為已 erase Manager+18 active key node。

**未解**：非同步完成如何呼叫 +0x24、close-by-key 之後何時轉 full close、closesocket 同時是否存在 outstanding receive。


**BIN 原生指令摘錄**（原件 `.text`：0x00806FC0–0x00807090；raw=VA−0x400C00；來源 SHA 見文件首）：

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


## E51.4 — Pool+0x28：正常 close producer、去重與 timestamp

**N**：`0x806FC0→0x805A80`。在 `0x805A80`，以 `Pool+0x28` list sentinel 遍歷 `[node+8] == Conn*`；若已存在，跳到 `0x805ADD` 不重複插入；若不存在，在 `0x805A9B` 呼叫 `GetTickCount()` 存入 `Conn+A0C0`，`0x74D700` 新建 list node，`Pool+0x2C++`。故 Pool+28 是 close 側的**去重追蹤**，不是緊接著的 free vector。

**N**：`0x805B40` 的第一個 loop 只見 `Conn+0x14==0` 便 detach/free 該 **Pool+28 的 list node** 並 `Pool+0x2C--`；沒有將 Conn 送到 Pool+0x10 reuse vector。反向條件 `Conn+14 != 0` 才保留，timestamp 雖寫入但該 loop **未拿 A0C0 與 GetTickCount 比較**；不得因存在 tick 欄位就推稱此 loop 具固定時間 TTL。

**C／需調查**：如 Conn+14 從 reset 起為 0 且之後未變動，Pool+28 的節點可在下一次 sweep 刪除；真正 Conn 是否還被 map 持有是另一個問題。未找到非零 writer 不等於排除透過 alias/memcpy 或其他 module 寫入。


**BIN 原生指令摘錄**（原件 `.text`：0x00805A80–0x00805AE2；raw=VA−0x400C00；來源 SHA 見文件首）：

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


## E51.5 — Conn+0x14 寫入者清查與有限負面證據

**N／真實寫入者**：`0x805F6D mov [ESI+0x14],EBX`，EBX 在 reset 入口 `xor ebx,ebx` 為 0；`0x805B30 mov [EDX+0x14],0`（Connect fail 入 Pool+48）；`0x806778 mov [EAX+0x14],0`（manager destructor 迭代 tree 的 Conn value）。`0x805B58 cmp [ECX+0x14],0` 為 Pool+28 消費讀取。

**本輪掃描覆蓋**：對原始 `.text`，從 `0x805000–0x808000` 的連續 disassembly（只是保守網路模組窗口，不代表全程解碼正確）篩選 `mov DWORD PTR [reg+0x14]`，在物件已經由 pool/new/manager tree 證明為 Conn 的指令中找到上述三種**清零**；沒有確認一條 Conn+0x14 的非零直接 writer。`0x805B58` 的 consume 是**條件式機制**，不能自行命名為 reference-count 或 elapsed-time counter。

**重要區別**：`Manager+0x14`、`Pool+0x14`、node+0x14 和 `Conn+0x14` 不是同一欄位；對 `[eax+0x14]` 的全域盲 grep 即便有大量 hit，也不能當作 Conn writer。並且正向 writer 可能是 `lea reg,[Conn+14]` 後外部函式寫入、向量 copy、相對基底改寫或 DMA/原生別名，尚不能宣稱完全窮盡。

**U／具體可解除方式**：以 Ghidra SSA/REA p-code 所有 `[Conn+14]` 的 address-taken 與 alias 交叉參照，加合法重連測試時的硬體 write breakpoint，才能真正閉合。


**BIN 原生指令摘錄**（原件 `.text`：0x00805F50–0x00805F85；raw=VA−0x400C00；來源 SHA 見文件首）：

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
```


## E51.6 — Pool+0x48：Connect failure 與 manager teardown 兩個 producer

**N**：`0x805AF0` 只在目前已查到的 direct E8 callsite `0x806BD4`、`0x806BFB` 被呼叫；兩個都來自 `0x806AD0` 的 connect/setsockopt 失敗回路。該函式 `Pool+44--`、`Pool+48` 增列、`Pool+4C++`、`Conn+14=0`。`0x8066A0` manager dtor 不經 `0x805AF0`，直接對 Manager tree 中 `[node+0x10]` 的 Conn* 寫相同 Pool+48 list，並遞減 Pool+44、增加 Pool+4C、寫 Conn+14=0。兩條 upstream 不同。

**N／失敗路徑**：`0x806B8C` call connect；返回 -1 跳 `0x806B97...0x806BD4/806BFB`。後續多次 setsockopt 返回 -1 跳 `0x806C00`。這些 enqueue 操作本身不呼叫 closesocket；**socket 仍可能持有非 -1 值**。`0x805F50` reset 會先將 `Conn+0` 設 -1、呼叫 `0x8063E0` 處理其內部 queue，但 `0x8063E0` 當前已查區域未見直接 `[0xBD25D4]` closesocket。這是**潛在資源生命週期缺口**，仍可能有外部清理或 OS teardown，不能逕稱實際 leak。

**C／owner hazard**：manager destructor 只遍歷 active tree 現在還可達的 Conn；若先前 same-key replace 移掉舊節點，單靠 destructor 的這一條 producer 不能找到舊 Conn。

**證據邊界**：E8 byte scanner 可列直接 call site，但不是所有 indirect/vtable/exception 呼叫。


**BIN 原生指令摘錄**（原件 `.text`：0x00805AF0–0x00805B40；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  805af0:	55                   	push   ebp
  805af1:	8b ec                	mov    ebp,esp
  805af3:	ff 4e 44             	dec    DWORD PTR [esi+0x44]
  805af6:	57                   	push   edi
  805af7:	8b 7e 48             	mov    edi,DWORD PTR [esi+0x48]
  805afa:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  805afd:	8d 45 08             	lea    eax,[ebp+0x8]
  805b00:	50                   	push   eax
  805b01:	51                   	push   ecx
  805b02:	57                   	push   edi
  805b03:	e8 f8 7b f4 ff       	call   0x74d700
  805b08:	8b 4e 4c             	mov    ecx,DWORD PTR [esi+0x4c]
  805b0b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  805b10:	2b d1                	sub    edx,ecx
  805b12:	83 fa 01             	cmp    edx,0x1
  805b15:	73 0a                	jae    0x805b21
  805b17:	68 34 20 bf 00       	push   0xbf2034
  805b1c:	e8 0f 80 07 00       	call   0x87db30
  805b21:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  805b24:	41                   	inc    ecx
  805b25:	89 4e 4c             	mov    DWORD PTR [esi+0x4c],ecx
  805b28:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  805b2b:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  805b2e:	89 01                	mov    DWORD PTR [ecx],eax
  805b30:	c7 42 14 00 00 00 00 	mov    DWORD PTR [edx+0x14],0x0
  805b37:	5f                   	pop    edi
  805b38:	5d                   	pop    ebp
  805b39:	c2 04 00             	ret    0x4
  805b3c:	cc                   	int3
  805b3d:	cc                   	int3
  805b3e:	cc                   	int3
  805b3f:	cc                   	int3
```


**BIN 原生指令摘錄**（原件 `.text`：0x00806736–0x0080677F；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  806736:	89 3d 58 a8 fb 00    	mov    DWORD PTR ds:0xfba858,edi
  80673c:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  80673f:	ff 4f 44             	dec    DWORD PTR [edi+0x44]
  806742:	8b 5f 48             	mov    ebx,DWORD PTR [edi+0x48]
  806745:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806748:	8d 4d f0             	lea    ecx,[ebp-0x10]
  80674b:	51                   	push   ecx
  80674c:	52                   	push   edx
  80674d:	53                   	push   ebx
  80674e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806751:	e8 aa 6f f4 ff       	call   0x74d700
  806756:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  806759:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  80675e:	2b d1                	sub    edx,ecx
  806760:	83 fa 01             	cmp    edx,0x1
  806763:	0f 82 d1 00 00 00    	jb     0x80683a
  806769:	41                   	inc    ecx
  80676a:	89 4f 4c             	mov    DWORD PTR [edi+0x4c],ecx
  80676d:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  806770:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  806773:	89 01                	mov    DWORD PTR [ecx],eax
  806775:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806778:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
```


## E51.7 — Pool recycle consumer／reuse/new 的所有權與 counter 範圍

**N**：`0x805B40` 第一個 loop 清 Pool+28 的追蹤節點；第二個 loop 須先 `Conn+A0B8==0`，才呼叫 `0x805F50` reset、把 Conn 寫入 `Pool+0x10` 的 vector 結構、刪除 Pool+48 節點並 `Pool+4C--`。`A0B8!=0` 時，迭代下一節點，保持待回收狀態；不應宣稱這是 `Conn+14` 檢查。

**N**：`0x805950` reuse 支線（Pool+20 非零）取 vector item、`0x805F50` reset、設 `A0AC=1` 並 `Pool+44++`；new 支線 `malloc(0xA0D8)`、`0x805CA0` constructor、繼承 Pool+38/3C/40，`A0AC=1`，但不在相同位置執行 Pool+44++。兩支的 Pool+44 計數不對稱，因此不能命名為全系統 socket count。

**重要 E51 觀察**：reset `0x805F50` 沒有重設 `A0B8`，而是依 Pool+48 consumer 的零值 gate 避免有 pending SEND 的回收時重複使用；reset 亦沒有重設 `A02C` mode，而 new constructor 將其寫成 2。此二者使 pooled 重連不可盲目假設為 fresh mode2。

**U**：Pool+48 重複加入時可能的 node 所有權與例外分支、未列出的 client-level 壽命 owner、mutex 使用是否全程保護 list，以及 reset 與 IOCP worker 的並發順序，仍不能從 static 單執行緒 CFG 完全證明。


**BIN 原生指令摘錄**（原件 `.text`：0x00805B40–0x00805CA0；raw=VA−0x400C00；來源 SHA 見文件首）：

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
  805c68:	c2 04 00             	ret    0x4
  805c6b:	8d 55 f4             	lea    edx,[ebp-0xc]
  805c6e:	52                   	push   edx
  805c6f:	8d 4d e8             	lea    ecx,[ebp-0x18]
  805c72:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  805c79:	e8 2b b4 08 00       	call   0x8910a9
  805c7e:	68 a8 57 c8 00       	push   0xc857a8
  805c83:	8d 45 e8             	lea    eax,[ebp-0x18]
  805c86:	50                   	push   eax
  805c87:	c7 45 e8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x18],0xbd2ca4
  805c8e:	e8 5d 6d 09 00       	call   0x89c9f0
  805c93:	cc                   	int3
  805c94:	cc                   	int3
  805c95:	cc                   	int3
  805c96:	cc                   	int3
  805c97:	cc                   	int3
  805c98:	cc                   	int3
  805c99:	cc                   	int3
  805c9a:	cc                   	int3
  805c9b:	cc                   	int3
  805c9c:	cc                   	int3
  805c9d:	cc                   	int3
  805c9e:	cc                   	int3
  805c9f:	cc                   	int3
```


**BIN 原生指令摘錄**（原件 `.text`：0x00805950–0x00805A80；raw=VA−0x400C00；來源 SHA 見文件首）：

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
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
  805a5e:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  805a61:	52                   	push   edx
  805a62:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  805a68:	8b c6                	mov    eax,esi
  805a6a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805a6d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805a74:	59                   	pop    ecx
  805a75:	5f                   	pop    edi
  805a76:	5e                   	pop    esi
  805a77:	5b                   	pop    ebx
  805a78:	8b e5                	mov    esp,ebp
  805a7a:	5d                   	pop    ebp
  805a7b:	c2 04 00             	ret    0x4
  805a7e:	cc                   	int3
  805a7f:	cc                   	int3
```


## E51.8 — WSASend post 的分支完整增量矩陣

**N**：`0x8068B0` 檢查 `sendBuf != 0`、長度非零與 `Conn+A0A8 == 0`；將 `Conn+A050` 作為 SEND OVERLAPPED，寫入 WSABUF pointer/len 後呼叫 `[0xBD25B8] WSASend`。`return != SOCKET_ERROR` → `0x80697A` `InterlockedIncrement(&Conn+A0B8)` 並回 1；`return == SOCKET_ERROR` 且 `WSAGetLastError()==0x3E5`（WSA_IO_PENDING）→ `0x806961` 同加一、回 2；其餘 error → 回 0、不加一；gate failed → 回 -1、不加一。

**逐邊 delta**：`invalid input/Conn closing: Δ=0, ret=-1`；`WSASend synchronous completion: Δ=+1, ret=1`；`WSA_IO_PENDING: Δ=+1, ret=2`；`other immediate error: Δ=0, ret=0`。即使 immediate success，OVERLAPPED socket 與 IOCP 關聯仍可能有 completion event，不能自以為同步成功就沒有完成通知而先減一。

**重要負面**：send increment 在 API 返回後才執行；是否有 completion thread 在 increment 前看見同一 OVERLAPPED 是**未確認的 happens-before**。此報告不假裝 Win32 runtime 測試已證明 safe ordering。

**C**：本路徑計數更精確叫「已接受／pending SEND completion 計數」，不應在未找出 recv 增量前命名為 all async I/O counter。


**BIN 原生指令摘錄**（原件 `.text`：0x008068B0–0x008069A0；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2 10 00             	ret    0x10
  80699d:	cc                   	int3
  80699e:	cc                   	int3
  80699f:	cc                   	int3
```


## E51.9 — WSARecv post：不增加 A0B8，A0BC 是另一個 gate

**本輪新的重大勘誤（N）**：`0x806A00–0x806ACC` 的整個函式，無論 `WSARecv` 立即成功或 `WSA_IO_PENDING`，都**沒有對 `Conn+A0B8` 呼叫 InterlockedIncrement**。它將 `Conn+A030` 作為 RECEIVE OVERLAPPED，`[Conn+5018]` 作 WSABUF buffer，最大接收 `0x1000`，而後呼叫 `[0xBD25BC] WSARecv`。立即錯誤且不是 `0x3E5` 時走 vtable+24 close、設 `Conn+A0A8=1`、回 0。成功或 pending 時先 `call 0x8065B0`，若回 1 又觸發 vtable+24 close，最後回 1。

**N：`0x8065B0`** 讀 `Conn+A0C8`／`Conn+A0B4`／`Conn+A0BC`，必要時以 `InterlockedIncrement/InterlockedExchange` 作用於 **A0BC**，並使用 GetTickCount 與 `A0C4/A0D0` 執行條件判斷。此不是 A0B8 的 SEND outstanding counter。計數器字段不可以因同樣 Interlocked API 而混寫。

**C／界線**：`A0B8` 在本 native module 的明確 post/completion 對只涵蓋 SEND；RECV completion 即使發生也不必然觸發 A0B8 的 decrement。這**修正 E50 把它概括為 pending async I/O（收+發合計）的過度命名**；更適合暫稱「已 post SEND 的 completion 追蹤計數（已證路徑）」。若未知 writer 在別處 post recv，仍須重新驗證，不能寫成全程只會用 SEND。

**U**：有無跨執行緒 multiple concurrent WSARecv 使用相同 `Conn+A030`、接收緩衝區的別名與生命週期、post 之後立即 close 的 race，靜態無法全部閉合。


**BIN 原生指令摘錄**（原件 `.text`：0x00806A00–0x00806AD0；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
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
```


**BIN 原生指令摘錄**（原件 `.text`：0x008065B0–0x00806620；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  8065b0:	83 be c8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0c8],0x0
  8065b7:	75 03                	jne    0x8065bc
  8065b9:	33 c0                	xor    eax,eax
  8065bb:	c3                   	ret
  8065bc:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  8065c3:	74 f4                	je     0x8065b9
  8065c5:	8b 86 bc a0 00 00    	mov    eax,DWORD PTR [esi+0xa0bc]
  8065cb:	53                   	push   ebx
  8065cc:	8b 1d d4 22 bd 00    	mov    ebx,DWORD PTR ds:0xbd22d4
  8065d2:	57                   	push   edi
  8065d3:	8d be bc a0 00 00    	lea    edi,[esi+0xa0bc]
  8065d9:	85 c0                	test   eax,eax
  8065db:	75 08                	jne    0x8065e5
  8065dd:	ff d3                	call   ebx
  8065df:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  8065e5:	8b 0f                	mov    ecx,DWORD PTR [edi]
  8065e7:	3b 8e cc a0 00 00    	cmp    ecx,DWORD PTR [esi+0xa0cc]
  8065ed:	7e 21                	jle    0x806610
  8065ef:	6a 00                	push   0x0
  8065f1:	57                   	push   edi
  8065f2:	ff 15 80 22 bd 00    	call   DWORD PTR ds:0xbd2280
  8065f8:	ff d3                	call   ebx
  8065fa:	2b 86 c4 a0 00 00    	sub    eax,DWORD PTR [esi+0xa0c4]
  806600:	3b 86 d0 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa0d0]
  806606:	73 0f                	jae    0x806617
  806608:	5f                   	pop    edi
  806609:	b8 01 00 00 00       	mov    eax,0x1
  80660e:	5b                   	pop    ebx
  80660f:	c3                   	ret
  806610:	57                   	push   edi
  806611:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806617:	5f                   	pop    edi
  806618:	33 c0                	xor    eax,eax
  80661a:	5b                   	pop    ebx
  80661b:	c3                   	ret
  80661c:	cc                   	int3
  80661d:	cc                   	int3
  80661e:	cc                   	int3
  80661f:	cc                   	int3
```


## E51.10 — IOCP success：OVERLAPPED 身分、recv parser 與 SEND decrement 分離

**N**：`0x806CF0` worker 經 `[0xBD2274] GetQueuedCompletionStatus` 取得 completionKey (`[ebp-0x1c]` = Conn*)、OVERLAPPED (`[ebp-0x20]`)、transferBytes (`[ebp-0x24]`)。`completionKey==1` 走 thread termination 特例；OVERLAPPED 為 null 時主要進記錄/返回 loop（`0x806DA5`）；OVERLAPPED 非 null 且 `transferBytes==0` 才在 `0x806DC7` 呼叫 vtable `+0x24` close、`A0A8=1`。

**N：成功 RECV completion**：`lpOverlapped==Conn+A030`：更新 Worker+2C 的 transferred byte count、Worker+3C 事件數，檢查 `Conn+A0AC`，呼叫 `0x807B40` frame parser；parser 非零時呼叫 vtable+0x14 重貼 WSARecv；parser 零值則按 Conn+A0B0 及 logging 狀態進行標記，回 loop。**此 path 沒有 A0B8 decrement**。

**N：成功 SEND completion**：`lpOverlapped==Conn+A050`：更新 Worker+28/+38，若 Conn+A0AC 非零，呼叫 `0x8077B0` 下游 queue 消費；寫 `Conn+A024` 依 A028 是否仍有資料；最後 `0x806EC3` 呼叫 `InterlockedDecrement(&Conn+A0B8)`，回到 completion loop。

**反證**：E50 先前以「send/recv completion 都會減 A0B8」的概括是錯的；在原件可見的完整成功分支，**recv 沒有減一，send 才有減一**。原生 pointer equality 比對，不是僅依 key/slot 名稱判斷收發完成。


**BIN 原生指令摘錄**（原件 `.text`：0x00806D6F–0x00806ECD；raw=VA−0x400C00；來源 SHA 見文件首）：

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
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
```


## E51.11 — IOCP failure／zero-byte／close 的餘額與分歧

**N：GetQueuedCompletionStatus 回 0** 時進入 `0x806ECF`，先檢查 OVERLAPPED 非 null。若指向 `Conn+A050`，`0x806EF1` 對 A0B8 呼叫 InterlockedDecrement；若指向 `Conn+A030`，跳過該 decrement；若是不認識的 OVERLAPPED，亦未看到 counter decrement。緊接著讀 `Conn+A0B8`：只有 ==0 才呼叫 vtable `+0x24` close 並寫 `Conn+A0A8=1`，非零回 loop。

**N：GetQueuedCompletionStatus 回非零時的零位元組分支**：`0x806D9E` 的 EDX 是 OVERLAPPED 指標；`0x806DA1` 比對 EDX==0，若為 null 則記錄/返回 loop。若 OVERLAPPED 非 null，`0x806DC0` 才取 `transferBytes` 到 ECX，`0x806DC3 cmp ecx,0`，零位元組轉 `0x806DC7` 呼叫 vtable `+0x24` close 並標記 `A0A8=1`。注意 `0x806D92 cmp eax,1` 是 **completion key 判斷**，絕不是 bytes==1；這三個判斷（key、OVERLAPPED 是否 null、bytes==0）必須彼此獨立。

**C／具體風險**：如果 recv failure 和未完成 send 並存，`A0B8>0` 時 error completion 不立即走 +24；等 send completion 完成後，在成功 SEND branch 只減 counter 然後回 loop，**不能從目前單一 CFG 直接保證一定再次觸發 close**。此可能會有其他失敗 completion／外部清理，須另證。

**N／cancel 未閉合**：目前函式未見 `CancelIoEx` 或 shutdown 作為每個失敗 completion 的共通步驟；不能假稱 `cancel→IOCP complete→decrement→reuse` 在所有 WinSock 情況必定平衡。


**BIN 原生指令摘錄**（原件 `.text`：0x00806ECF–0x00806F56；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
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
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
  806f2e:	8b 5b 58             	mov    ebx,DWORD PTR [ebx+0x58]
  806f31:	3b de                	cmp    ebx,esi
  806f33:	74 10                	je     0x806f45
  806f35:	68 f4 16 c5 00       	push   0xc516f4
  806f3a:	56                   	push   esi
  806f3b:	8b fb                	mov    edi,ebx
  806f3d:	e8 be 94 ee ff       	call   0x6f0400
  806f42:	83 c4 08             	add    esp,0x8
  806f45:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  806f48:	5f                   	pop    edi
  806f49:	5e                   	pop    esi
  806f4a:	33 cd                	xor    ecx,ebp
  806f4c:	5b                   	pop    ebx
  806f4d:	e8 af a0 08 00       	call   0x891001
  806f52:	8b e5                	mov    esp,ebp
  806f54:	5d                   	pop    ebp
  806f55:	c3                   	ret
```


## E51.12 — IOCP worker / receive parser / queue，與 counter 的先後界線

**N**：`0x806850` vtable+8 初始化 IOCP global 與 worker queue thread 入口；`0x806CF0` vtable+4 是實際 GQCS loop。`0x806D57` 的全零參數和 `INVALID_HANDLE_VALUE` 用於建立 completion port；`0x806C87` 將 socket 與同一 port 關聯，completionKey 為 `Conn*`。`0x806E08` 呼叫 `0x807B40`，原生 parser 開頭先檢查至少 4 bytes，再區分 `0x2633/0x0BBB/0x1A68/0x22D7` marker 與長度；這不代表登入時實際採用哪一種首包 marker。

**N：另一 Conn 建立路徑** `0x807090` 以 Pool.acquire(false) 建 conn，複製 0x00–0x10 source metadata，直接關聯 IOCP，隨後對它 post WSARecv；未經 `0x806AD0` 的 key-map insert。這是 Conn 可能存在於 active map 之外的**具體 native 反例**。不能把 Manager+18 map 當作所有 Conn 唯一集合，也不能把 `805950` 的每個 caller 都視為重新 Connect。

**C**：`0x807090` 的 inbound metadata source/外部持有者需要上游 virtual caller 才能定義 owner；它不等於 same-key old Conn owner 問題已解。


**BIN 原生指令摘錄**（原件 `.text`：0x00807090–0x0080711A；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  807090:	55                   	push   ebp
  807091:	8b ec                	mov    ebp,esp
  807093:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  80709a:	53                   	push   ebx
  80709b:	56                   	push   esi
  80709c:	8b d9                	mov    ebx,ecx
  80709e:	75 15                	jne    0x8070b5
  8070a0:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8070a7:	74 07                	je     0x8070b0
  8070a9:	e8 b2 3e c9 ff       	call   0x49af60
  8070ae:	eb 05                	jmp    0x8070b5
  8070b0:	e8 4b 3f c9 ff       	call   0x49b000
  8070b5:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  8070bb:	6a 00                	push   0x0
  8070bd:	e8 8e e8 ff ff       	call   0x805950
  8070c2:	8b f0                	mov    esi,eax
  8070c4:	85 f6                	test   esi,esi
  8070c6:	75 06                	jne    0x8070ce
  8070c8:	5e                   	pop    esi
  8070c9:	5b                   	pop    ebx
  8070ca:	5d                   	pop    ebp
  8070cb:	c2 08 00             	ret    0x8
  8070ce:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8070d1:	8b 08                	mov    ecx,DWORD PTR [eax]
  8070d3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  8070d6:	89 0e                	mov    DWORD PTR [esi],ecx
  8070d8:	8b 10                	mov    edx,DWORD PTR [eax]
  8070da:	89 56 04             	mov    DWORD PTR [esi+0x4],edx
  8070dd:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8070e0:	89 4e 08             	mov    DWORD PTR [esi+0x8],ecx
  8070e3:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  8070e6:	89 56 0c             	mov    DWORD PTR [esi+0xc],edx
  8070e9:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  8070ec:	57                   	push   edi
  8070ed:	8b 3e                	mov    edi,DWORD PTR [esi]
  8070ef:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  8070f2:	e8 29 f5 ff ff       	call   0x806620
  8070f7:	8b 08                	mov    ecx,DWORD PTR [eax]
  8070f9:	6a 00                	push   0x0
  8070fb:	56                   	push   esi
  8070fc:	51                   	push   ecx
  8070fd:	57                   	push   edi
  8070fe:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  807104:	8b 13                	mov    edx,DWORD PTR [ebx]
  807106:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  807109:	56                   	push   esi
  80710a:	8b cb                	mov    ecx,ebx
  80710c:	ff d0                	call   eax
  80710e:	5f                   	pop    edi
  80710f:	5e                   	pop    esi
  807110:	b8 01 00 00 00       	mov    eax,0x1
  807115:	5b                   	pop    ebx
  807116:	5d                   	pop    ebp
  807117:	c2 08 00             	ret    0x8
```


**BIN 原生指令摘錄**（原件 `.text`：0x00807B94–0x00807C40；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
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
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```


## E51.13 — 初始 key0/key2 連線與 57-byte 0x0001 本地發送

**N：`0x4957C0` 的兩次 Connect** 分別 `port=0x20E0,key=0,pipeline=2` 與 `port=0x20DE,key=2,pipeline=2`；兩個結果分別存 EDI/EBX，在雙成功分支 `0x495935` 呼叫 manager vtable+0x10 (0x8069A0) 送 `key0`、`len=0x39=57`，其 stack buffer `0x495884` 寫入首 WORD `0x0001`；`0x495943` 及 `0x495951` 分別經 vtable+0x14 (0x806A00) 在兩條 Conn 上 post receive。最後新 Conn 指標存入 `Client-like+0xBF64/+0xBF68`。出站 payload 其他位元組在 `0x4958B3` 之後從本機 state/field copy，不能隨意宣告由 Server 配發。

**N：錯誤分支的對照**：兩條都成功才走初始 key0 排隊和兩次 recv post。key0 成功但 key2 失敗 → `0x49597E–0x49598D` 呼叫 **shutdown-by-key(0,1)**；key0 失敗但 key2 成功 → `0x4959C1–0x4959D0` 呼叫 **shutdown-by-key(2,1)**。兩個都失敗則進 failure message return 0；先前 `0x806AD0` Connect failure 已加入 Pool+48，與上述 shutdown 不是同一清理路徑。

**N：`0x8069A0`** 若 key 不存在回 0；若 len=0 回 1；否則 `0x8060D0` 受本地 queue guard (`Conn+A0A4>0x12c`) 與 `len<=0x1000` 資料複製條件影響。接續 queue→frame→WSASend 仍有排程和分支，**`0x495935` 不構成實際首筆 wire 已送出的觀測**。legacy 0x20E0/0x20DE 只說明此 Client 的靜態參數，不能推給新 Server 要用相同部署 port。

**C：同 key identity hazard**：若再次執行 `0x4957C0`，active map node 由 `806AD0` 換成新 Conn，`Client-like+BF64/BF68` 指標也被覆寫；此前尚需是否曾透過其他 callback 關閉/回收舊 Conn 才能排除遺失 reference 的可能。


**BIN 原生指令摘錄**（原件 `.text`：0x004957C0–0x004959E6；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
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
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
  495872:	68 90 01 00 00       	push   0x190
  495877:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
  4958e9:	6a 0a                	push   0xa
  4958eb:	51                   	push   ecx
  4958ec:	e8 0d e7 3f 00       	call   0x893ffe
  4958f1:	c6 45 da 01          	mov    BYTE PTR [ebp-0x26],0x1
  4958f5:	e8 a6 f2 f6 ff       	call   0x404ba0
  4958fa:	8a 90 98 68 00 00    	mov    dl,BYTE PTR [eax+0x6898]
  495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
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
  4959e0:	8b e5                	mov    esp,ebp
  4959e2:	5d                   	pop    ebp
  4959e3:	c2 04 00             	ret    0x4
```


**BIN 原生指令摘錄**（原件 `.text`：0x008069A0–0x00806A00；raw=VA−0x400C00；來源 SHA 見文件首）：

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
```


## E51.14 — 登入結果、選服 UI 與 key1 過渡：同一 session 時序不可虛構

**來源分離**：T03／E44–E45 既有有界研究發現特定 `S2C 0x0013/0x007A` handler (`0x4C37A0/0x4C3C10`) → `0x4C3080` IPv4 解析 → `FE1B54` endpoint record（+0xC）→ `0x66B910` 選服 UI → `0x66C620/0x66C090` 選擇 → `0x4957C0`。本輪沒有冒充重新逐行驗證整份 T03 的所有業務函式；此鏈**僅在各已證條件同時成立時**成立。

**本輪 N：另一個上游 `0x495610`** 在 `[ebp+0x10]!=0` 時，對 Manager vtable+0x20 依次 shutdown key0、key2；然後對輸入 host/port `0x20DF`、key1 做新的 Connect（見 `0x49574E–0x49575B`）；若成功即以 vtable+0x14 post WSARecv，將 Conn 存入 `Client-like+BF60`，Sleep `0x1F4`；失敗則 return 0。此過渡函式即便有 shutdown key0/2，也**未證 closesocket 與 map erase**。`0x4957C0` 與 `0x495610` 在不同階段，有自己的條件和 slot identity，不應合併成一次無條件關線。

**負面範圍**：`0x007A` 需要的 `6+Σ(3+10Ni)` 是 handler 遍歷時最低 read-need，不是上游已執行的長度 guard。此輪沒抓合法登入封包、同一次 runtime 的 S2C→TCP connect→初始首個 WSASend→Server 首回覆→UI 更新。**S00 可以拿去當 bounded draft/interface evidence，但不能據此認為 RR 完成、Server 原始行為已復刻或 T01 FULL-PASS**。

**進一步去重**：主體封包業務 parser 歸 T03；T02 本輪只維護 transport ownership、close、IOCP 與本地 enqueue 的連結，任何跨 Task 推論都以 C 分級。


**BIN 原生指令摘錄**（原件 `.text`：0x004956E0–0x004957B8；raw=VA−0x400C00；來源 SHA 見文件首）：

```asm
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
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2 0c 00             	ret    0xc
```


## E51.15 — 端到端狀態矩陣、反證、停止條件、E52 精確交接

以下狀態模型僅描述上列 **static branch 上可證的條件**；不可外推真正執行期唯一時序。


| 情境 | key-map 變更 | socket API / Pool | A0B8 變化 | 第一筆業務 packet | 等級／未證 |
|---|---|---|---|---|---|
| key0、key2 首次 Connect 成功 | `806AD0` 每個 key 查既存→必要時 erase node→insert Conn | `CreateIoCompletionPort` bind；`495943/951` post recv | post recv **沒有** +1 | `495935` key0 enqueue `0x0001/57` | N 本地；wire U |
| 同 key 重新 Connect 成功 | 舊 tree node erase，新 node value=新 Conn | `806C91–CD2` **不直接 close 舊 Conn** | 舊 Conn 的 send outstanding 未知 | 依 caller 條件 | N / old Conn owner U |
| connect/setsockopt 立即失敗 | 新 Conn 尚未插入 active map | `805AF0→Pool+48`，`Conn+14=0` | recycle 只有 zero 才 reset | 不保證有 | N；socket dispose U |
| key0 成功、key2 失敗 | key0 可能已插入 map | 透過 +0x20 **shutdown key0**；未見 erase | 如先前 send 仍依 completion | 57-byte 不 enqueue | N；full close U |
| key0 失敗、key2 成功 | key2 可能已插入 map | 透過 +0x20 **shutdown key2** | 同上 | 57-byte 不 enqueue | N；full close U |
| Conn-based close | 無當場 map erase | `shutdown/closesocket→Pool+28`，重複去重 | 此處不重設 counter | 未決 | N；後續 owner U |
| Manager destructor | 遍歷當時**可達**的 map values | inline `Pool+48`，清 Conn+14 | Pool consumer gate A0B8==0 | 不適用 | N；已被替換 old Conn U |
| SEND post accepted/pending | 無 | `WSASend` | +1 | 不等於 server 收到 | N |
| SEND completion success/error | 無 | `GQCS`，A050 | -1 | 不等於 server ACK | N |
| RECV completion success/error | 無 | `GQCS`，A030 | 本輪此 branch 無 ±1 | parser→callback/post recv 條件式 | N |
| Pool+48 recycle | 無 | `A0B8==0` 才 reset/vector reuse | 讀 0，不直接增減 | 不適用 | N；并發安全 U |

**以事件公式表達已證收送計數（不是全 OS correctness 定理）**：

```text
S = number of WSASend accepted / WSA_IO_PENDING branches at 80697A/806961
C = number of IOCP completion branches reaching 806EC3 or 806EF1 for Conn+A050
visible_delta_A0B8 = S - C
for 806A00 WSARecv success/pending and 806CF0 Conn+A030 completion: visible_delta_A0B8 = 0
```

此等式僅計上列已辨識路徑，不能據此認定 S=C 在所有實際執行中成立。特別是 `post-return increment` 對 `completion-thread decrement` 的相對順序、同 Conn 重連、close-by-key 只 shutdown、Pool+48 reset 和 socket handle 生命周期可能存在需要 dynamic trace 的競態。

### 明確反證 / 更正（對 E46–E50 舊稱呼）

1. `0x49B070` 是 Pool singleton getter，不是 active key-map erase；真正 same-key node erase 是 `806CB3→7B6890`。
2. `Conn+A0B8` 不可叫 Win32 event handle，也不能概括為**全部 SEND+RECV outstanding I/O**：本輪在完整 `806A00` 沒有 recv increment；在 `806CF0` 的 recv completion 沒有 decrement。已證的是 SEND-side increment/decrement subset。
3. `0x806F80` close-by-key 其實 only shutdown，不等於 `0x806FC0` closesocket + Pool+28。
4. Pool+28 是 timestamp/list tracking、掃描移除 node；Pool+48 是以 A0B8 zero gate 才把 Conn reset/reuse；兩個回收階段不可合併。
5. `0x805F50` reset 不保證重新設定 `Conn+A02C`；first wire marker `0x0BBB/0x1A68` 仍無實測。
6. manager destructor 迭代 active key-map 現值，不能收攏此前已被 replacement erase 而在其他位置沒有 reference 的舊 Conn。
7. `0x4957C0` 57-byte payload 在 key0 本地交給 vtable+10，不是可宣稱「已在 wire 上收到 Server 回覆」的封包捕捉。

### 後續阻塞與負面搜尋精確範圍

- **Client 待逆向**：`Conn+0x14` 全域 alias writer（本輪只做已知模組直接寫入及 reset/Pool producer 查核，無全程靜態 SSA）；same-key replacement 前的 caller-level old Conn owner；管理器 teardown 的 indirect clear；`0x8063E0` 的下游資源收尾；Pool+48 與 pending receive 并發的 memory-safety；A02C 非零 writer；send increment vs IOCP completion 的 happens-before。
- **跨功能待整合**：T03 角色／選服 UI 的特定 S2C handler 成功失敗條件與 `495610/4957C0` 的實際單 session 交替；合法 0x0013/0x007A 和 0x0001 payload 的 fields/opcode namespace；T05 後續 scene handoff。
- **待遊玩驗證**：依法取得可用環境觀察重連 key0/key2、新舊 Conn 位址與 socket handle、pending send/recv 計數時間序、`GQCS` 完成類型、shutdown 後 closesocket 時機、真正首個 wire bytes 和 S2C 首回覆，配合 Wireshark/ETW 或監測中斷點；本輪沒有執行遊戲或封包抓取。
- **Server 待開發**：依已證的各 key/port role、封裝 parser 的可接受 message range、業務回覆界面實作相容 Server；不能以 legacy port 值直接代替新 Server 的部署設計，也不能猜原版 Session policy。

### E52 可操作補證入口（不自動展開另段）

1. 對 `0x4957C0` 的全部間接上游及 `Client-like+BF64/BF68` 所有 read/write 建立 SSA/alias ledger；設計 same-key reconnect 的「舊 Conn address / map-node address / socket HANDLE / Pool28 Pool48 membership」測試，補 owner。
2. 由 `0x806FC0` 的 vtable+24 callers（特別 `806A67`、`806DC7`、`806F0E`）追有無 map erase、是否在 shutdown-by-key 後必接 close。
3. `0x806A00` / `0x8068B0` / `0x806CF0` 每個返回與完成分支建立 trace table，核對 A0B8 與 A0BC 不混，檢查 `WSA_IO_PENDING` 之外 error／cancel／zero-byte。
4. 對 `0x805F50→0x8063E0` 的下游 class/dtor/queue 做 resource reachability；確認失敗 connect 未關 socket 的 owner。
5. 繼續以 S2C 0x0013/007A 真正 parser、選服的 `0x495610/4957C0` 調用順序與 key0 初始 packet 作針對性跨 Task 精確驗證；若要宣稱 first wire 必須有 runtime capture。

### 正式停止原因：B（15 個大型研究單元上限）

已完成 E51.1–E51.15 **十五個各有主題、有對應原生函式／分支／反證的研究單元**。重大新發現（recv 不增 A0B8、vtable +20 shutdown-only、Pool+28 去重、獨立 807090 Conn 路徑）**沒有提前終止研究**。達本次明確上限後停止，不以全部缺口閉合自居；RR-0005 仍 QUEUED、T01 FULL-PASS 與 S00 SPEC/STABLE 均不因本檔自動改變。

**Git 狀態：未 Commit，未 Push。** 本地 Markdown 是唯一新 E51 完整交付檔；請於取得使用者下一次明確提交授權時再核對 `extra/roy1` remote HEAD、路徑衝突與 main 授權邊界後上傳原稿，逐檔讀回驗證。


## 附錄 A — 原始指令附錄／執行可再現命令

以下為本輪實際重新反組譯、關係推導用的函式全段或重點範圍（對應原始 BIN 的 .text；不含 runtime patch）。已明確標示片段而非假裝每一個下游函式都逐行核完；與上文的節點交叉使用。若下列區間超出實際函式的 ret，尾端 int3 只是填充 bytes。

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -h /mnt/data/Tartaros.bin
objdump -p /mnt/data/Tartaros.bin | grep -E 'GetQueuedCompletionStatus|CreateIoCompletionPort|Interlocked|WSASend|WSARecv|GetTickCount'
# 例：將 .text 從原始檔 raw 0x400 擷取，再從已知函式入口解碼：
dd if=/mnt/data/Tartaros.bin of=e51-text.bin bs=1 skip=1024 count=8192496 status=none
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x806ad0 --stop-address=0x806cea e51-text.bin
```

**注意**：上面 dd 的 count 應以實際 `objdump -h` `.text Size=0x7D01F0` 換算為十進位（已在本輪採 section 方式重讀）；使用者可直接採 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00` 對完整 BIN 從函式開頭驗證。不從任意位元組地址硬切以免產生 E50 中段 `(bad)` 問題。


**BIN 原生指令摘錄**（Connect full（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

```asm
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
  806b4f:	e8 7c 70 09 00       	call   0x89dbd0
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
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
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
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
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
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
```


**BIN 原生指令摘錄**（Ctor/Pool+14 and A0B8 init（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

```asm
  805ca0:	55                   	push   ebp
  805ca1:	8b ec                	mov    ebp,esp
  805ca3:	6a ff                	push   0xffffffff
  805ca5:	68 dc 99 90 00       	push   0x9099dc
  805caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805cb0:	50                   	push   eax
  805cb1:	83 ec 10             	sub    esp,0x10
  805cb4:	53                   	push   ebx
  805cb5:	56                   	push   esi
  805cb6:	57                   	push   edi
  805cb7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805cbc:	33 c5                	xor    eax,ebp
  805cbe:	50                   	push   eax
  805cbf:	8d 45 f4             	lea    eax,[ebp-0xc]
  805cc2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805cc8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805ccb:	8d 46 18             	lea    eax,[esi+0x18]
  805cce:	6a 18                	push   0x18
  805cd0:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805cd6:	e8 8d b5 08 00       	call   0x891268
  805cdb:	8b f8                	mov    edi,eax
  805cdd:	33 db                	xor    ebx,ebx
  805cdf:	83 c4 04             	add    esp,0x4
  805ce2:	3b fb                	cmp    edi,ebx
  805ce4:	74 0e                	je     0x805cf4
  805ce6:	68 a0 0f 00 00       	push   0xfa0
  805ceb:	57                   	push   edi
  805cec:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805cf2:	eb 02                	jmp    0x805cf6
  805cf4:	33 ff                	xor    edi,edi
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
  805d24:	33 c0                	xor    eax,eax
  805d26:	89 86 30 a0 00 00    	mov    DWORD PTR [esi+0xa030],eax
  805d2c:	89 86 34 a0 00 00    	mov    DWORD PTR [esi+0xa034],eax
  805d32:	89 86 38 a0 00 00    	mov    DWORD PTR [esi+0xa038],eax
  805d38:	89 86 3c a0 00 00    	mov    DWORD PTR [esi+0xa03c],eax
  805d3e:	89 86 40 a0 00 00    	mov    DWORD PTR [esi+0xa040],eax
  805d44:	89 9e 48 a0 00 00    	mov    DWORD PTR [esi+0xa048],ebx
  805d4a:	89 9e 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],ebx
  805d50:	89 86 50 a0 00 00    	mov    DWORD PTR [esi+0xa050],eax
  805d56:	89 86 54 a0 00 00    	mov    DWORD PTR [esi+0xa054],eax
  805d5c:	89 86 58 a0 00 00    	mov    DWORD PTR [esi+0xa058],eax
  805d62:	89 86 5c a0 00 00    	mov    DWORD PTR [esi+0xa05c],eax
  805d68:	89 86 60 a0 00 00    	mov    DWORD PTR [esi+0xa060],eax
  805d6e:	89 9e 68 a0 00 00    	mov    DWORD PTR [esi+0xa068],ebx
  805d74:	6a 0c                	push   0xc
  805d76:	89 9e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ebx
  805d7c:	e8 e7 b4 08 00       	call   0x891268
  805d81:	83 c4 04             	add    esp,0x4
  805d84:	3b c3                	cmp    eax,ebx
  805d86:	0f 84 b6 00 00 00    	je     0x805e42
  805d8c:	89 86 74 a0 00 00    	mov    DWORD PTR [esi+0xa074],eax
  805d92:	89 00                	mov    DWORD PTR [eax],eax
  805d94:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805d9a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  805d9d:	33 c0                	xor    eax,eax
  805d9f:	b9 01 00 00 00       	mov    ecx,0x1
  805da4:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  805da7:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805dad:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805db3:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805db9:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805dbf:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805dc5:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805dcb:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805dd1:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
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
  805e2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805e31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805e38:	59                   	pop    ecx
  805e39:	5f                   	pop    edi
  805e3a:	5e                   	pop    esi
  805e3b:	5b                   	pop    ebx
  805e3c:	8b e5                	mov    esp,ebp
  805e3e:	5d                   	pop    ebp
  805e3f:	c2 04 00             	ret    0x4
```


**BIN 原生指令摘錄**（Manager teardown tail（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

```asm
  8066a0:	55                   	push   ebp
  8066a1:	8b ec                	mov    ebp,esp
  8066a3:	6a ff                	push   0xffffffff
  8066a5:	68 d6 44 91 00       	push   0x9144d6
  8066aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8066b0:	50                   	push   eax
  8066b1:	51                   	push   ecx
  8066b2:	53                   	push   ebx
  8066b3:	56                   	push   esi
  8066b4:	57                   	push   edi
  8066b5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8066ba:	33 c5                	xor    eax,ebp
  8066bc:	50                   	push   eax
  8066bd:	8d 45 f4             	lea    eax,[ebp-0xc]
  8066c0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8066c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  8066c9:	c7 07 48 17 c5 00    	mov    DWORD PTR [edi],0xc51748
  8066cf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  8066d6:	8b 47 1c             	mov    eax,DWORD PTR [edi+0x1c]
  8066d9:	8b 30                	mov    esi,DWORD PTR [eax]
  8066db:	3b f0                	cmp    esi,eax
  8066dd:	0f 84 ed 00 00 00    	je     0x8067d0
  8066e3:	8b 3d 58 a8 fb 00    	mov    edi,DWORD PTR ds:0xfba858
  8066e9:	85 ff                	test   edi,edi
  8066eb:	75 4f                	jne    0x80673c
  8066ed:	39 3d 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,edi
  8066f3:	74 0d                	je     0x806702
  8066f5:	e8 66 48 c9 ff       	call   0x49af60
  8066fa:	8b 3d 58 a8 fb 00    	mov    edi,DWORD PTR ds:0xfba858
  806700:	eb 3a                	jmp    0x80673c
  806702:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  806709:	75 26                	jne    0x806731
  80670b:	83 0d 00 12 fc 00 01 	or     DWORD PTR ds:0xfc1200,0x1
  806712:	68 08 12 fc 00       	push   0xfc1208
  806717:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  80671b:	e8 40 ed ff ff       	call   0x805460
  806720:	68 70 e6 bc 00       	push   0xbce670
  806725:	e8 f0 bb 08 00       	call   0x89231a
  80672a:	83 c4 04             	add    esp,0x4
  80672d:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  806731:	bf 08 12 fc 00       	mov    edi,0xfc1208
  806736:	89 3d 58 a8 fb 00    	mov    DWORD PTR ds:0xfba858,edi
  80673c:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  80673f:	ff 4f 44             	dec    DWORD PTR [edi+0x44]
  806742:	8b 5f 48             	mov    ebx,DWORD PTR [edi+0x48]
  806745:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806748:	8d 4d f0             	lea    ecx,[ebp-0x10]
  80674b:	51                   	push   ecx
  80674c:	52                   	push   edx
  80674d:	53                   	push   ebx
  80674e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806751:	e8 aa 6f f4 ff       	call   0x74d700
  806756:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  806759:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  80675e:	2b d1                	sub    edx,ecx
  806760:	83 fa 01             	cmp    edx,0x1
  806763:	0f 82 d1 00 00 00    	jb     0x80683a
  806769:	41                   	inc    ecx
  80676a:	89 4f 4c             	mov    DWORD PTR [edi+0x4c],ecx
  80676d:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  806770:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  806773:	89 01                	mov    DWORD PTR [ecx],eax
  806775:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806778:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
  80677f:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  806783:	75 3d                	jne    0x8067c2
  806785:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  806788:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  80678c:	75 16                	jne    0x8067a4
  80678e:	8b f0                	mov    esi,eax
  806790:	8b 06                	mov    eax,DWORD PTR [esi]
  806792:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  806796:	75 2a                	jne    0x8067c2
  806798:	8b f0                	mov    esi,eax
  80679a:	8b 06                	mov    eax,DWORD PTR [esi]
  80679c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067a0:	74 f6                	je     0x806798
  8067a2:	eb 1e                	jmp    0x8067c2
  8067a4:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  8067a7:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067ab:	75 13                	jne    0x8067c0
  8067ad:	8d 49 00             	lea    ecx,[ecx+0x0]
  8067b0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  8067b3:	75 0b                	jne    0x8067c0
  8067b5:	8b f0                	mov    esi,eax
  8067b7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  8067ba:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067be:	74 f0                	je     0x8067b0
  8067c0:	8b f0                	mov    esi,eax
  8067c2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  8067c5:	3b 71 1c             	cmp    esi,DWORD PTR [ecx+0x1c]
  8067c8:	0f 85 15 ff ff ff    	jne    0x8066e3
  8067ce:	8b f9                	mov    edi,ecx
  8067d0:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  8067d7:	75 35                	jne    0x80680e
  8067d9:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  8067e0:	33 c0                	xor    eax,eax
  8067e2:	50                   	push   eax
  8067e3:	50                   	push   eax
  8067e4:	50                   	push   eax
  8067e5:	6a ff                	push   0xffffffff
  8067e7:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  8067ec:	a3 bc 33 fe 00       	mov    ds:0xfe33bc,eax
  8067f1:	a3 c0 33 fe 00       	mov    ds:0xfe33c0,eax
  8067f6:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  8067fc:	68 b0 0b bd 00       	push   0xbd0bb0
  806801:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806806:	e8 0f bb 08 00       	call   0x89231a
  80680b:	83 c4 04             	add    esp,0x4
  80680e:	be b8 33 fe 00       	mov    esi,0xfe33b8
  806813:	e8 08 17 00 00       	call   0x807f20
  806818:	8b cf                	mov    ecx,edi
  80681a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  806821:	e8 9a d6 ff ff       	call   0x803ec0
  806826:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806829:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806830:	59                   	pop    ecx
  806831:	5f                   	pop    edi
  806832:	5e                   	pop    esi
  806833:	5b                   	pop    ebx
  806834:	8b e5                	mov    esp,ebp
  806836:	5d                   	pop    ebp
  806837:	c2 04 00             	ret    0x4
```


**BIN 原生指令摘錄**（Send key（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

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
```


**BIN 原生指令摘錄**（Conn close（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

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


**BIN 原生指令摘錄**（Recv post（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

```asm
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
```


**BIN 原生指令摘錄**（Send post（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2 10 00             	ret    0x10
  80699d:	cc                   	int3
  80699e:	cc                   	int3
  80699f:	cc                   	int3
```


**BIN 原生指令摘錄**（IOCP worker（完整函式區間 / source from original BIN）；來源 SHA 見文件首）：

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
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
  806f2e:	8b 5b 58             	mov    ebx,DWORD PTR [ebx+0x58]
  806f31:	3b de                	cmp    ebx,esi
  806f33:	74 10                	je     0x806f45
  806f35:	68 f4 16 c5 00       	push   0xc516f4
  806f3a:	56                   	push   esi
  806f3b:	8b fb                	mov    edi,ebx
  806f3d:	e8 be 94 ee ff       	call   0x6f0400
  806f42:	83 c4 08             	add    esp,0x8
  806f45:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  806f48:	5f                   	pop    edi
  806f49:	5e                   	pop    esi
  806f4a:	33 cd                	xor    ecx,ebp
  806f4c:	5b                   	pop    ebx
  806f4d:	e8 af a0 08 00       	call   0x891001
  806f52:	8b e5                	mov    esp,ebp
  806f54:	5d                   	pop    ebp
  806f55:	c3                   	ret
```


## 附錄 B — 交叉參照、資料結構與索引

| Native target | 在原 `.text` 用 E8 relative bytes 搜到的 direct CALL 候選（再依 caller 函式邊界核對） | 語意／限制 |
|---|---|---|
| `805950` | `806B16`, `8070BD` | pool acquire，第二個為額外 Conn/IOCP path |
| `805A80` | `807045` | close-by-Conn tracking |
| `805AF0` | `806BD4`, `806BFB` | Connect failure，**不包括 inline manager destructor** |
| `805B40` | `491203` | delay recycle sweep |
| `805F50` | `8059E9`, `805BB7`, `805E1B`, `805E9E` | reuse/constructor/reset；部分為 cleanup/exception path |
| `8066A0` | `806677` | manager destructor wrapper |
| `807B40` | `806E08` | GQCS recv path parser |
| `4957C0` | `66C1A7`, `66C247` | 選服 UI 入口；直接候選須依 caller CFG 解碼，且不涵蓋 indirect |

**類別 offset（暫名）**：`Manager+0x18` active-key tree；`Manager+0x1C` sentinel；`node+0xC` key、`node+0x10` Conn*；`Pool+0x10` reuse vector、`Pool+0x20` available count、`Pool+0x28` close-tracking list、`Pool+0x2C` tracking node count、`Pool+0x34` critical section、`Pool+0x44` 部分 lease count、`Pool+0x48` recycle list、`Pool+0x4C` recycle list count；`Conn+0x00` socket、`Conn+0x14` 待釐清 flag/ref、`Conn+A02C` frame mode、`Conn+A030` recv OVERLAPPED、`Conn+A050` send OVERLAPPED、`Conn+A0A8` close flag、`Conn+A0AC` activity flag、`Conn+A0B8` 已證 SEND completion atomic count、`Conn+A0BC` 另一 Interlocked gate、`Conn+A0C0` close tracking tick。所有名稱不代表已存在官方 C++ symbol。

**歷史出處**：E44/E45 的 S2C→UI→Connect 部分依 `extra/roy1` 原稿，E50 的 SHA 與 GitHub README/政策已在首頁明列；本段所有引用的 critical network code 重新從 SHA256 對應之 BIN 驗證。對話未取得真實封包，故任何 first-wire/Server reply 皆仍 U。

