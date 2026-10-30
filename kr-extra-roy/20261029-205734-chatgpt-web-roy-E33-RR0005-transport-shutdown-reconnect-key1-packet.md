# E33 — RR-0005：transport shutdown≠close、登入 key1 重建後 0x0081 payload 與初始收發界線

**日期／時間**：2026-10-29T20:57:34+08:00，Asia/Taipei。**作業線**：`extra/roy1`（研究草稿本地，未 Commit／Push）。**上一段**：`20261029-204628-chatgpt-web-roy-E32-RR0005-login-UI-RTTI-connection-lifecycle.md`（本地可讀、尚未上 Git）。**GitHub 開工快照**：`main=e751b18922d205d86dea9f280cfd060f62752bc7`，`extra/roy1=6e16fd7260297f90dde6dc18bb8bc9d278f05af3`；RR 唯一台帳 `RR-0005: version=kr, owner_task=T02, priority=P0, status=PENDING, dispatch.state=QUEUED`。未認領、未修改 RR。初期入口閱讀 `AGENTS.md`、`kr/tasks/T02/README.md`、`research/dispatch/README.md`、`research/dispatch/inbox/T02.md`、`research/requests/index.json`、`shared/verified-knowledge/README.md` 與 E32、E26～E31、T03 既有有界成果。

## 0. 原件、避重與本段突破

| 來源 | 版本／存在 | 用途 |
|---|---|---|
| `Tartaros.bin` | 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪直接重算 | **第一手原始 PE32/x86 machine-code、.rdata 函式表、PE import**，唯讀、不執行 |
| `Tartaros.exe` | SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；與既有 KR 證據相符 | 版本對照，不將它誤當 12MB 的 game BIN |
| `Event.stp` | SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；已有 E01/E06 原生 STP/Lua/SceneList 研究 | 本段連線追查不需再次解碼或請使用者重傳 |
| `kr-bulk-roy/<BIN SHA>/functions/`，`main` | 直接讀取 `0x806f80.c`、`0x806fc0.c`、`0x806f60.c`、`0x806a00.c`、`0x805a80.c`、`0x6d64c0.c`、`0x6d6b70.c`、`0x6d6350.c`、`0x6d6400.c` 等 | 實際利用 decompiler 名稱與流程導航；下述關鍵語意逐條對 BIN 驗證，不把 bulk 本身當第一手證據 |
| T03 main 既有 `AUTH-NATIVE-REVIEW.md`／`SERVER-CHOICE-REVIEW.md`、T01 整合索引 | 已看過；T03 的登入 `0x13` 寫入與 UI table 既有研究，E32 已補 RTTI/data bridge | 不重做已驗的登入 payload、STP/scene、`0x66C620` class owner、`0x7B6890` erase |

**原生 PE 映射**：`.text VA=raw+0x400C00`；`.rdata raw=VA−0xBD2000+0x7D0600`。本段新發現不是「每個 socket 首筆已抓到」，而是精確區分 transport 的三種 socket 操作、找出 key1 重新連線後的新 56-byte payload 與上下游函式，再界定現有首包障礙。

**T01/S00 權限與交叉**：`shared/verified-knowledge/` 僅是符合限定 FULL-PASS 的有界主張庫，`research/intake`／`research/claims` 的 REGISTERED／CLAIMS_EXTRACTED／SPEC_CONSUMABLE 也是可復用但不自動升格的材料；本 E33 為未審原始研究，不冒稱 FULL-PASS、S00 RR ACCEPTED、SPEC STABLE。T03 README 有獨立 WSASend layout NEEDS_FIX 退回；本報告不更動他 Task、且保留 `connection+A050=OVERLAPPED / connection+A064=WSABUF / connection+A0B8=counter` 的更正。

## 第一輪：原生 transport vtable 安裝、+0x20 只有半關閉，+0x24 才是實際 closesocket

### 1.1 確立同一 vtable 的四個 slot 與安裝

在 `.rdata` 直接解 LE32，`0xC51744` 為 RTTI COL 候選，`0xC51748` 是本 transport 的**實際 vtable 首址**，`0x8046F7` 的 `mov [esi],0xC51748` 安裝進使用 `0x803D60` 初始化的物件，隨後 `0x80470F` 寫到全域 `0xFBA854`。另一個安裝點 `0x8066C9` 是相關 teardown 期間的 vptr 重設（不能把它誤當建立新 socket）。

| vtable slot | `.rdata` entry VA / raw | target VA / raw | 原生子流程 |
|---|---|---|---|
| `+0x10` | `0xC51758` / `0x84FD58` | `0x8069A0` / `0x405DA0` | 依 key 查 Conn* 並 enqueue（既有 E27） |
| `+0x14` | `0xC5175C` / `0x84FD5C` | `0x806A00` / `0x405E00` | 連線 WSARecv post／特定失敗呼叫 +0x24 |
| `+0x18` | `0xC51760` / `0x84FD60` | `0x806AD0` / `0x405ED0` | 建立 socket/Connect、IOCP、keyed tree（E28～E31） |
| **`+0x1C`** | `0xC51764` / `0x84FD64` | `0x806F60` / `0x406360` | 對直接 Conn* socket 呼叫 shutdown(SD_SEND) |
| **`+0x20`** | `0xC51768` / `0x84FD68` | `0x806F80` / `0x406380` | 以 **key** 查 tree，若有 Conn* → shutdown(SD_SEND)；**無 closesocket/tree erase** |
| **`+0x24`** | `0xC5176C` / `0x84FD6C` | `0x806FC0` / `0x4063C0` | 特定 guard 下 shutdown(SD_BOTH) → closesocket → pool 回收/登記 |

```asm
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
  8066c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  8066c9:	c7 07 48 17 c5 00    	mov    DWORD PTR [edi],0xc51748
  8066cf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
```

**首要更正（與 E32/E30 追溯）**：此前在不知 target 時把 `vtable+0x20(key,1)` 泛稱「close/removal 類呼叫」。現在查明它**是 shutdown(SD_SEND) 的有界路徑**，不是完整關閉/從 map 刪除，且第二個 stack 參數在 `0x806F80` 中未參與分支（`ret 8` 清兩個參數）。不能反過來聲稱它必然保持連線長時間可用；只是此 leaf 沒有 full close 或 key removal。

### 1.2 PE import 可直接驗證，非僅憑函式名稱／參數數量

原始 `Tartaros.bin` 的 PE import descriptor（`objdump -p`）直接列 `DLL Name: WS2_32.dll`，IAT `0xBD25C8` 是 **ordinal 22**（WinSock `shutdown`），`0xBD25D4` 是 **ordinal 3**（`closesocket`），`0xBD25AC` 是 **ordinal 21**（`setsockopt`）；原 BIN 對應 import thunk dwords 分別為 `0x80000016`／`0x80000003`／`0x80000015`。而 `0xBD25BC` 是具名 `WSARecv`。這是 PE import 證據、callsite 引數及 bulk 反編譯三方向互證。

`0x806F60` 直接吃 Conn*，以其首 dword socket 為第一引數 `shutdown(sock,1)`：

```asm
  806f60:	55                   	push   ebp
  806f61:	8b ec                	mov    ebp,esp
  806f63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f66:	8b 08                	mov    ecx,DWORD PTR [eax]
  806f68:	6a 01                	push   0x1
  806f6a:	51                   	push   ecx
  806f6b:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806f71:	5d                   	pop    ebp
  806f72:	c2               	ret    0x4
```

`0x806F80` 先以 transport+0x18 tree 查 key，end-sentinel 或 node+0x10 Conn* 為 null 則跳過；否則對 Conn 的首 dword socket 進行 `shutdown(sock,1)`，其中 `how=1` 是 **SD_SEND**，不等於關閉接收方向，也不等於 `closesocket`：

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

因此 `0x495610` mode 非零所呼叫的 `+0x20(key0,1)`, `+0x20(key2,1)`, `+0x20(key1,1)`，及 `0x4957C0` 對 Connect 成功一方的失敗清理，**只能在此證實執行 lookup + shutdown(SD_SEND) 呼叫**。不能標成已釋放 FD、已移除 key1/0/2 或已完成 graceful close。也不能把 `0x7B6890` tree node free 當成這次的 socket FD close。

### 1.3 真正含 closesocket 的 transport `+0x24` 與 guard

`0x806FC0(Conn*, flag)` 在 transport global pool 的 critical-section 下檢查 `Conn+A0A8==0` 且 Conn 的 socket 值不為 0 / -1，才進行：若 flag 低 byte 為 0，先設定 `setsockopt(sock, SOL_SOCKET=0xFFFF, SO_LINGER=0x80, ...)`，然後 `shutdown(sock,2)`（SD_BOTH）與 `closesocket(sock)`，再呼叫 `0x49B070(Conn*)`，並以 `0x805A80(Conn*)` 將該 Conn* 記錄於 pool+0x28 的 list（`0x805A80` 本身由 E32 及本輪 bulk+BIN 重看為列表插入＋tick，不是再次關閉 FD）。

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
  80704a:	83       	cmp    DWORD PTR ds:0xfba858,0x0
```

**否證界線**：`0x806FC0` 沒有在此函式內對 transport keyed tree+0x18 做 `0x7B6890` erase；它用的是 global pool 管理。Conn* 的 `+A0A8` guard、worker callback 與其餘完整 lifetime 仍要串接，不能據此聲稱樹一定沒有在其他 worker 移除，也不能假設每個 shutdown(SD_SEND) 都必定隨後呼叫 +0x24。`0x806F80` 與 `0x806FC0` 是兩個不同獨立 virtual slots、不同 selector 型別。

**第一輪結果**：原生可重驗的 vtable target 與 WinSock API / argument 直接閉合，是 RR-0005 先前未知、對失敗/重連責任有實質影響的重大新發現；依全 Task 三輪門檻此時已可結束正式 E33，但本輪繼續定向擴展上下游，避免把第一個 close call 誤認全程生命週期。

## 第二輪：WSARecv post 異常呼叫 full-close、Conn pool 與 key tree 的三個分離層次

### 2.1 `+0x14`（0x806A00）：WSARecv 初始提交的錯誤支路會到 `+0x24`

`0x495610` 新 key1 成功後、`0x4957C0` 新 key0/key2 成功後呼叫 transport vtable `+0x14(Conn*)`。原始 `0x806A00` 在 Conn+`A030` 起建 `WSARecv` Overlapped/WSABUF 參數，`[Conn+A044]=0x1000`，buffer 來自 `[Conn+0x5018]`。若 `WSARecv` 返回 SOCKET_ERROR 且 `WSAGetLastError()!=997 (WSA_IO_PENDING)`：呼叫同一 transport `vtable+0x24(Conn*,0)`，再寫 `Conn+A0A8=1`，返回 0。正常/IO_PENDING 續走 `0x8065B0`，若該 helper 回 1 也再呼叫 `+0x24(Conn*,0)`；最後回傳 1。`0x8065B0` 涉及其它狀態/時間閘門，不能直接命名 timeout 已驗收。

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
```

**新增路徑**：`0x4957C0` 成功雙連線 → `+0x14(key0Conn)`、`+0x14(key2Conn)` 立即各 post receive；若非 pending 例外才可從此分支實際走 +0x24 / shutdown+closesocket。這是可證「full close 的條件性 caller」，**與選服失敗分支直接 `+0x20` 半關閉不同**。也不是在沒有 runtime 時就能斷言哪一條 socket 在玩家畫面上先關閉。

### 2.2 Reconnect/duplicate key 的三個獨立資料結構

- **Transport keyed tree** 位於 transport+0x18。`0x806AD0` 連線正常建立後以 `0x8438C0` 查 key；若命中 `0x7B6890` 執行 node erase/free，再以 `0x57EF20`（0x18-byte node，key at +0x0C, Conn* at +0x10）和 `0x57E850` 插入新 key/Conn*。E30/E31 已核實。**單純 map 換指標不能直接當成 FD 已關閉。**
- **Conn pool 本體**：`0x805950` 成功配置/取用 `0xA0D8` bytes Conn，失敗的 `connect`/`setsockopt` branch 走 `0x805AF0` 把物件交還其 pool list；`0x805AF0` 自身無 `closesocket`。不要把 pool 釋放/重用和 socket FD 操作混淆。
- **Conn pool delayed list**：`0x806FC0` 真 full-close 後呼叫 `0x805A80` 加入 pool+0x28 路徑，`0x805A80` 會更新 `Conn+A0C0` tick 與列表成員。不可自動等同 transport+0x18 key tree 已 clean。

`0x806AD0` 非成功分支原生 `0x806BD3/806BFA → 0x805AF0`，在該局部沒有 `closesocket`；**只記 leaf/branch 範圍，不提升成「必然 socket leak」**（仍需全物件 destructor／其他工作執行緒補證）。`0x806F80` 的 lookup 使用 Conn* 但不 erase；`0x806FC0` 可以真正呼叫 OS close 但不含 keyed remove；兩者不能互相代換。

```asm
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
```

### 2.3 狀態／所有權界線

`0x806FC0` 的 guard `Conn+A0A8 == 0` 與 `0x806A00` 異常回收後 `Conn+A0A8=1` 構成**有界的防重複 close 連結**；但 `0x806FC0` 自身不在所示分支無條件寫 `A0A8=1`，其他 caller 是否也設置、是否有多執行緒競爭／refcount，尚未完整驗證。`0x4957C0` 在舊 login Conn 上執行 `0x8063E0` 待發訊息清空、enqueue `0x007E`、寫 `oldConn+A0B0=1` 及 BF60 清零，這些**不是 +0x24**；應先追 `A0B0` consumer 而非推測舊 FD 立刻 close。

## 第三輪：原生 key1 重新連接的 `0x0081`／56-byte 本地 queue 新候選

### 3.1 找到 `0x495610(mode=1)` 的特定 caller 與 payload 構造者

E32 已羅列 `0x495610` 六個 direct E8 callers：`0x6D6377, 0x6D6424, 0x6D6508, 0x6D65C8, 0x6D670C, 0x6D696C`。本輪查原始 BIN `0x6D64C0`：

1. `0x6D64C0` 的輸入非零 gate 成立後，`0x6D64FF push 1`，並將 host 指標與 `[FB1318]` Client context 推入 `0x495610`，**明確要求 mode=1**。
2. 若 `0x495610` 回零，`0x6D650F` 直接跳返回 0 的分支，不會組裝本段新 56-byte payload。成功則 `0x6D651B` 呼叫 `0x6D6B70` 以暫存 buffer 為 ESI。
3. `0x6D6B70` 寫 little-endian word `0x0081` 至 buffer+0；buffer+2 為 caller ECX dword；其後兩個 10-wide-string 目的欄位在 +6、+26；buffer+46、+47..50、+51、+52..55 保留初始化/後續內容。具體使用者姓名/票券語意沒有原版 Server 保證。
4. `0x6D6520` 以 `0x404BA0` 讀 `client+0x6898` 寫 buffer+46；`0x6D652F..6546` 複製 `client+0x6899` 至 +47 起、copy capacity5；`0x6D6549..655A` 以 `client+0x68A0` 寫 buffer+52 dword。
5. `0x6D6554..656A` 經 `[FBA854]` vtable `+0x10(key=1, buffer, length=0x38)` 將**本地 56-byte payload** 交予 key1 queue，接著返回 1；和 `0x4957C0` 對 key0 的 `0x39`（57-byte）payload 是**不同 conn key、不同訊息格式、不同呼叫條件**。

```asm
  6d64c0:	55                   	push   ebp
  6d64c1:	8b ec                	mov    ebp,esp
  6d64c3:	83 e4 f8             	and    esp,0xfffffff8
  6d64c6:	83 ec 3c             	sub    esp,0x3c
  6d64c9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d64ce:	33 c4                	xor    eax,esp
  6d64d0:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d64d4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d64d7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d64d9:	56                   	push   esi
  6d64da:	8b f1                	mov    esi,ecx
  6d64dc:	85 c0                	test   eax,eax
  6d64de:	75 14                	jne    0x6d64f4
  6d64e0:	33 c0                	xor    eax,eax
  6d64e2:	5e                   	pop    esi
  6d64e3:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  6d64e7:	33 cc                	xor    ecx,esp
  6d64e9:	e8 13 ab 1b 00       	call   0x891001
  6d64ee:	8b e5                	mov    esp,ebp
  6d64f0:	5d                   	pop    ebp
  6d64f1:	c2 08 00             	ret    0x8
  6d64f4:	83 c0 0c             	add    eax,0xc
  6d64f7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d64fb:	72 02                	jb     0x6d64ff
  6d64fd:	8b 00                	mov    eax,DWORD PTR [eax]
  6d64ff:	6a 01                	push   0x1
  6d6501:	50                   	push   eax
  6d6502:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6507:	50                   	push   eax
  6d6508:	e8 03 f1 db ff       	call   0x495610
  6d650d:	85 c0                	test   eax,eax
  6d650f:	74 cf                	je     0x6d64e0
  6d6511:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6d6514:	8b d6                	mov    edx,esi
  6d6516:	57                   	push   edi
  6d6517:	8d 74 24 08          	lea    esi,[esp+0x8]
  6d651b:	e8 50 06 00 00       	call   0x6d6b70
  6d6520:	e8 7b e6 d2 ff       	call   0x404ba0
  6d6525:	8a 88 98 68 00 00    	mov    cl,BYTE PTR [eax+0x6898]
  6d652b:	88 4c 24 32          	mov    BYTE PTR [esp+0x32],cl
  6d652f:	e8 6c e6 d2 ff       	call   0x404ba0
  6d6534:	05 99 68 00 00       	add    eax,0x6899
  6d6539:	50                   	push   eax
  6d653a:	8d 54 24 37          	lea    edx,[esp+0x37]
  6d653e:	6a 05                	push   0x5
  6d6540:	52                   	push   edx
  6d6541:	e8 13 d6 1b 00       	call   0x893b59
  6d6546:	83 c4 0c             	add    esp,0xc
  6d6549:	e8 52 e6 d2 ff       	call   0x404ba0
  6d654e:	8b 80 a0 68 00 00    	mov    eax,DWORD PTR [eax+0x68a0]
  6d6554:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d655a:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d655e:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d6560:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6563:	6a 38                	push   0x38
  6d6565:	8b c6                	mov    eax,esi
  6d6567:	50                   	push   eax
  6d6568:	6a 01                	push   0x1
  6d656a:	ff d2                	call   edx
  6d656c:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  6d6570:	5e                   	pop    esi
  6d6571:	33 cc                	xor    ecx,esp
  6d6573:	b8 01 00 00 00       	mov    eax,0x1
  6d6578:	e8 84 aa 1b 00       	call   0x891001
  6d657d:	8b e5                	mov    esp,ebp
  6d657f:	5d                   	pop    ebp
  6d6580:	c2 08              	ret    0x8
```

`0x6D6B70` 的全部範圍直接 BIN：

```asm
  6d6b70:	55                   	push   ebp
  6d6b71:	8b ec                	mov    ebp,esp
  6d6b73:	89 4e 02             	mov    DWORD PTR [esi+0x2],ecx
  6d6b76:	33 c9                	xor    ecx,ecx
  6d6b78:	b8 81 00 00 00       	mov    eax,0x81
  6d6b7d:	66 89 06             	mov    WORD PTR [esi],ax
  6d6b80:	89 4e 06             	mov    DWORD PTR [esi+0x6],ecx
  6d6b83:	89 4e 0a             	mov    DWORD PTR [esi+0xa],ecx
  6d6b86:	89 4e 0e             	mov    DWORD PTR [esi+0xe],ecx
  6d6b89:	8d 46 06             	lea    eax,[esi+0x6]
  6d6b8c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  6d6b8f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  6d6b92:	89 4e 1a             	mov    DWORD PTR [esi+0x1a],ecx
  6d6b95:	89 4e 1e             	mov    DWORD PTR [esi+0x1e],ecx
  6d6b98:	57                   	push   edi
  6d6b99:	8d 7e 1a             	lea    edi,[esi+0x1a]
  6d6b9c:	89 4f 08             	mov    DWORD PTR [edi+0x8],ecx
  6d6b9f:	89 4f 0c             	mov    DWORD PTR [edi+0xc],ecx
  6d6ba2:	89 4f 10             	mov    DWORD PTR [edi+0x10],ecx
  6d6ba5:	88 4e 2e             	mov    BYTE PTR [esi+0x2e],cl
  6d6ba8:	89 4e 2f             	mov    DWORD PTR [esi+0x2f],ecx
  6d6bab:	88 4e 33             	mov    BYTE PTR [esi+0x33],cl
  6d6bae:	89 4e 34             	mov    DWORD PTR [esi+0x34],ecx
  6d6bb1:	85 d2                	test   edx,edx
  6d6bb3:	74 0e                	je     0x6d6bc3
  6d6bb5:	6a 0a                	push   0xa
  6d6bb7:	52                   	push   edx
  6d6bb8:	6a 0a                	push   0xa
  6d6bba:	50                   	push   eax
  6d6bbb:	e8 3e d4 1b 00       	call   0x893ffe
  6d6bc0:	83 c4 10             	add    esp,0x10
  6d6bc3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d6bc6:	85 c0                	test   eax,eax
  6d6bc8:	74 0e                	je     0x6d6bd8
  6d6bca:	6a 0a                	push   0xa
  6d6bcc:	50                   	push   eax
  6d6bcd:	6a 0a                	push   0xa
  6d6bcf:	57                   	push   edi
  6d6bd0:	e8 29 d4 1b 00       	call   0x893ffe
  6d6bd5:	83 c4 10             	add    esp,0x10
  6d6bd8:	8b c6                	mov    eax,esi
  6d6bda:	5f                   	pop    edi
  6d6bdb:	5d                   	pop    ebp
  6d6bdc:	c2               	ret    0x4
```

**堆疊位移交叉核對**：caller `0x6D6516 push EDI` 後 `lea ESI,[ESP+8]` 供 `0x6D6B70`，callee `ret 4` 消掉該 stack arg，回到 caller 的 ESP 後新 `ESI = ESP+4`；所以 caller `[ESP+0x32]` 相對 buffer 是 +0x2E（46）、`[ESP+0x37]` 是 +0x33（51）起的 narrow5、`[ESP+0x38]` 是 +0x34（52）的 DWORD，與 `0x6D6B70` 初始化零區精確吻合。若忽略 `ret 4`，會錯把 token 複製當作覆蓋 UTF-16 第二欄。

### 3.2 +0x13 回覆 cache 與 key1/0 兩種 queue 都有欄位相依

T03 已確認 `0x4C37A0` 在特定 status=0/名稱非空時寫 `client+0x6898 / +0x6899 / +0x68A0`；E32 已證 `0x4957C0` 亦讀它們構造 **key0 `0x39`**。本輪新增 `0x6D64C0` 在 `0x495610(mode=1)` 成功後，以同一批 cache 欄位構造 **key1 `0x38`**。這形成兩條**有界資料來源橋**，但不證明正常初次登入必定同時送兩包、也不證兩個 server 套用同一 token 驗證政策。

| 原生記憶體欄位 | `0x13` callback producer（既有 T03/E32） | key1 `0x0081 / 0x38` | key0 `0x0001 / 0x39`（E32） |
|---|---|---|---|
| `+0x6898` byte | response `+0x86` | buffer+46 | buffer+27 |
| `+0x6899` narrow capacity5 | response `+0x87` | buffer+47..51 | buffer+28..32 |
| `+0x68A0` DWORD | response `+0x8C` | buffer+52..55 | buffer+33..36 |
| `+0x67E0`、`+0x67E4` | response `+0x18`／`+2` | **不由 0x6D64C0 這條已證 producer 直接讀取** | key0 buffer+2/+6 |
| `+0x67FA` UTF16 | 未在 0x13 已證 producer 查到來源 | **沒有本次直接讀取** | key0 buffer+37 起，來源另待查 |

**重要方向警戒**：`0x0081`、`0x0001` 是 local payload 的首 word，因已達 key-specific queue，可作 **C→S payload command 候選**，但仍未得到每 socket first WSASend frame 與 parser 的端到端 proof。`0x39` / `0x38` 是 queue payload 大小，不是有頭部的實際 TCP frame 大小；`0x70A/0x578` 則只是 FUI event code，`0xF4241/0xF4243` 亦是本地通知 ID，全部不能混用。

### 3.3 再往上找到 `0x6D64C0` 唯一直接 caller `0x49542A`

全 `.text` raw `E8 rel32` 位元掃描（再用 objdump 確認指令邊界）找到 `0x6D64C0` 的直接 caller `0x49542A`。`0x495280` 上下文先建立 `CLoginModuleGSP` 全域實例 `0xFBACD4`、`0x4953D7 push 0xBB8; call Sleep`，之後 `0x49541B` 從 caller 輸入 struct 取欄位：`EDI=input+0x16`、`ECX=input+2`，`ESI` 源於 `[F93930]`，傳 `&FBACD4` 與 `ESI` 作為 stack args 呼叫 `0x6D64C0`。此證明具體初始化／登入相關上游，不再是孤立的 0x0081 builder。

```asm
  4953d1:	8b 35 30 39 f9 00    	mov    esi,DWORD PTR ds:0xf93930
  4953d7:	68 b8 0b 00 00       	push   0xbb8
  4953dc:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4953e2:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4953e9:	75 30                	jne    0x49541b
  4953eb:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4953f2:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4953f9:	00 
  4953fa:	89 1d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,ebx
  495400:	e8 fb 0e 24 00       	call   0x6d6300
  495405:	68 70 d6 bc 00       	push   0xbcd670
  49540a:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  49540f:	e8 06 cf 3f 00       	call   0x89231a
  495414:	83 c4 04             	add    esp,0x4
  495417:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  49541b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  49541e:	56                   	push   esi
  49541f:	8d 78 16             	lea    edi,[eax+0x16]
  495422:	8d 48 02             	lea    ecx,[eax+0x2]
  495425:	68 d4 ac fb 00       	push   0xfbacd4
  49542a:	e8 91 10 24 00       	call   0x6d64c0
  49542f:	85 c0                	test   eax,eax
  495431:	75 14                	jne    0x495447
  495433:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  495437:	68 c8 59 c0 00       	push   0xc059c8
  49543c:	83 c2 08             	add    edx,0x8
  49543f:	e8 bc 98 24 00       	call   0x6ded00
  495444:	83 c4 04             	add    esp,0x4
  495447:	33 c0                	xor    eax,eax
  495449:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  49544d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495454:	59                   	pop    ecx
  495455:	5f                   	pop    edi
  495456:	5e                   	pop    esi
  495457:	5b                   	pop    ebx
  495458:	8b e5                	mov    esp,ebp
  49545a:	5d                   	pop    ebp
  49545b:	c2               	ret    0xc
```

**保留限制**：`0x495280` 的外層函式/呼叫源、此路徑在初啟／重連是否必然執行、其輸入 struct 欄位實際業務語意、其他 worker concurrent queue，仍未全核。不可把 `Sleep(3000)`、`Sleep(500)` 當成官方 Server 的等待契約或重新連線保證。`0x495610 mode=1` 表示進入 half-shutdown/重新 Connect 分支，**不代表已觀察到 socket reconnect success 或 0x81 是網路第一包**。

### 3.4 關鍵事件與線路比較（截至 E33）

```text
S→C auth handler table slot 0x13 -> 0x4C37A0 (T03/E32)
       status==0 & nonempty name -> client fields +6898/+6899/+68A0 ; +67E0/+67E4
       0x4C3080 group/row -> local F4243 notification
       conditional 0x4C3170 -> local F4241 notification
            [notice → server selection GUI event producer NOT YET PROVED]
FUI::CServerSelectDialog 0x66C620 event +0x70A/+0x578 (E32 RTTI/vptr confirmed)
 -> 0x66C090 row/choice gate -> 0x4957C0
       -> key0 / port 0x20E0 and key2 / port 0x20DE Connect
       -> on both success: old key1 queue drain +0x007E -> key0 payload 0x39 enqueue
       -> +0x14 WSARecv post for key0/key2 ; store BF64/BF68
       -> on partial failure: +0x20(key,1) = shutdown(SD_SEND), NOT full close

0x495280 (startup/login-associated native caller)
 -> 0x49542A -> 0x6D64C0
 -> 0x495610(mode=1): +0x20 key0/key2/key1 half-shutdown; Connect key1 / port 0x20DF
 -> on success: 0x6D6B70 builds command0x0081 56-byte buffer
 -> +0x10(key1, payload0x38) enqueue
 -> actual first wire frame/response STILL UNKNOWN

+0x14 WSARecv post -> error (non-WSA_IO_PENDING) -> +0x24 (0x806FC0)
   if Conn+A0A8==0 and FD valid: shutdown(SD_BOTH); closesocket; delayed-pool list
   does NOT prove keyed tree removal or complete all-worker ownership
```

## 4. RR-0005 玩家情境 × 連線/收發/狀態矩陣

| 情境 | 已確認 Client gate/action | 已確認 local C→S 候選 | S→C/first actual wire | Client state/ownership | 證據/結論 |
|---|---|---|---|---|---|
| 0x13 auth result status0/非空名稱 | T03 `0x4C37A0` 寫 session fields、`0x4C3080` group rows + local notifications | 此 handler 未證直接發 key0/key1 特定訊息 | 完整原始 first response/frame 未閉合 | Cache 可供稍後選服與重建 key1 的 payload 讀取 | **原生局部資料依賴已證**；event relay 不明 |
| 選服操作可達 `0x4957C0` | 選取 row/+F94294 條件與 FUI event identity；雙 Conn 結果非零 | key0 `0x39`（首 word `0x0001`）入列；舊 login `0x007E` 兩 bytes 入列 | 真正 first wire frame、S2C reply 未證 | new BF64/BF68, key0/2 WSARecv post | **有條件可達、非保證網路首包** |
| 選服 key0 成功/key2 失敗或反之 | `0x4957C0` partial branch | 不進正常 key0 `0x39` | 無成功新序列可證 | +0x20(key,1) 是 **shutdown SD_SEND**，不是 full close | **重大更正**，不能把失敗列成 OS socket 完全釋放 |
| `0x495610(mode=1)` 切線/重建 login | +0x20(key0,key2,key1) half-shutdown；新 key1 `0x20DF` Connect | 若 `0x6D64C0` caller 成功，key1 command `0x0081`, `0x38` queue | 無 key1 first WSASend/incoming 時序 proof | BF60 更新 + `Sleep(500)`；舊 key node 僅在 Connect 成功 insert 時可能被替代 | 原生 caller & payload 局部完成，重連/官方時序未知 |
| key1 Connect 失敗 | `0x495610` 返回 0，`PostQuitMessage(0)` | 當次 `0x6D64C0` 不送 0x81 | 未知 | 未構成可恢復自動 retry loop | **葉子失敗分支已證**；其他 caller 可再次呼叫 |
| `+0x14` WSARecv non-pending error | guard `WSARecv==-1` 且 error!=997 | 不適用 | receive post failure，不是正常 server result | vtable+24 → (guard 成立) shutdown BOTH + closesocket、`Conn+A0A8=1` | **可證的 full-close 路徑**，但未證 tree erase |

## 5. 反證／錯誤訂正與四類後續項

**直接否證或縮小**：

- E30/E32 對 `transport+0x20(key,1)` 的「close/removal 類」泛稱：改為**具體 `shutdown(SD_SEND)`**；沒有 `closesocket`、map erase。
- `0x7B6890` 只 free tree node；`0x805AF0` 只重入 connection pool；`0x8063E0` 只清待發隊列；不能以任一個冒充 FD close。相對地 `0x806FC0` 的確有 `closesocket`，但不是所有錯誤 branch 都會到它。
- `0x6D6B70` 的 `0x0081` 與 `0x4957C0` 的 `0x0001` 不可看成同一 handshake。`key1` 與 `key0` queue 不可混；local event `0xF4243/0x70A` 不是 wire opcode。
- 看到 +0x24 full close 並不證實 worker 類型、完全清理 all references、經過所有 errors 的 wait/retry；未知保持未知。

**Client 待逆向**：`0x806F80` 半關閉後什麼時候呼叫 `0x806FC0` full-close；`Conn+A0A8/A0B0` writer/consumer；keyed map 的 remove 跟 delayed list / worker callback 交錯；`0x495280` 上游和 `0x6D64C0` 走向的 runtime 觸發條件；`F4243/F4241` 的 UI delivery/visible state；key0/key1/key2 首筆實際 WSASend 與首次接收 frame、0x13→UI event 的精確投遞鏈。

**Server 待開發**：對 KR Client 相容所需的 0x20DF/20E0/20DE 連線/本地 payload 形狀、異常重連與關閉行為制定有證據限制的 DRAFT SPEC/GAP，並把實際部署 IP/port、帳號驗證／token 發放／失效、超時與重試策略以自訂政策 ADR 區隔；**不以舊版硬碼 port 當作推薦部署規格**。不得把無證據的第一筆 S2C 固定寫入 Server。

**跨功能待整合**：T02 `RR-0005` owner 主責、`RR-0001/0004` framing mode，T03 `RR-0003` 0x13/事件及 `RR-0002` 選角，T05 場景切換；不能改 RR owner/state 或 T03 原稿。`GAP-NET-0002` 可由本報告供有限主張補證，但沒有推送也沒有提交接受。

**待遊玩驗證**：仍需同版 Client 與測試相容 Server 的實際 socket trace/pcap 驗證每個 key 的第一次 C2S/S2C、WSARecv pending/完成、半關閉後遠端處理/真正 FD close、UI retry。**目前沒有抓包**，任何此類表格都是 static conditional contract，不是觀察紀錄。

### 材料盤點／可選提供清單

| 材料 | 用途 | 是否阻塞 E34 靜態分析 |
|---|---|---|
| `Tartaros.bin`, `Tartaros.exe`, `Event.stp`, Event/SceneList, tutorial Lua | 已有原件、歷史解碼可重建；**不要再次要求提供** | 不阻塞 |
| `pcapng` 或按 socket/port 分流的動態 trace，附 Client/測試 Server 版本、timestamp、重新登入與選服成功/失敗路徑 | 驗證每條連線的真正首次 frame/response 與 shutdown/close 順序 | **不阻塞本地靜態研究；阻塞真正 wire 實測驗收** |
| 若日後找不到 FUI 選服 controls 標籤，額外同版 UI pack/manifest（具相對路徑） | 讓 F0/F4/F8 控件標籤對應玩家可視 UI；對 transport 核心無必要 | 不阻塞 |
| 同 SHA 的 Ghidra/REA 匯出、完整 runtime socket log | 補 indirect callback 與 worker lifecycle、第一包競態的可驗工具 | 可選，無此亦能繼續 BIN-first |

## 6. 三輪研究是否達標、下一段入口

- **第一輪**：從實際 transport vptr 安裝與 PE WS2_32 imports 閉合 vtable+0x20 → shutdown(SD_SEND)、+0x24 → shutdown(SD_BOTH)/closesocket；這是直接解決 E32 的主要未知，**達重大新原生證據**。
- **第二輪**：實際追 `+0x14 WSARecv` error path → `+0x24` full-close 與 guard，分清 keyed tree、Conn pool 和 delayed list；未把 leaf 綜合成完整 FD lifetime。
- **第三輪**：追 `0x495280 → 0x49542A → 0x6D64C0 → 0x495610(mode=1) → 0x6D6B70 → key1+0x10`，確認 `0x0081`、`0x38`、同一登入 cache 的位置，獨立於 key0 `0x39`；用 stack ret4 解出精確偏移，形成重大新 C→S 候選。
- **正式段號**：本次只 E33，已多項重大新發現且三個主題都完成證據採集；不另啟 `E33-2` / `E33-3`，其未啟動不是因無解而跳段，因第1輪已達 02 的研究門檻、後兩輪仍做功能延伸。
- **E34 優先**：沿 `0x806CF0`/IOCP worker 的 `+0x24` 真 close / map key eviction 鏈、`A0B0` consume/close 排程；對 `0x495280` caller/`0x13` notice → FUI event 70A 的有界 upstream 做去重；核實 `0x0081` key1 queue 與 key0 `0x39` 在 first wire 條件的 scheduler ordering（不只找同名函式）。

### 重驗指令（均唯讀）

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe /mnt/data/Event.stp
objdump -p /mnt/data/Tartaros.bin | grep -A16 'DLL Name: WS2_32.dll'
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806f80 --stop-address=0x807090 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806a00 --stop-address=0x806ad0 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6d64c0 --stop-address=0x6d6583 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6d6b70 --stop-address=0x6d6bdd /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4953d1 --stop-address=0x49545c /mnt/data/Tartaros.bin
```

**GitHub**：本次只讀，`main`/`extra/roy1` 無 commit/Push；此檔為實際產出的**本地完整 Markdown**，未有遠端 Git blob/SHA，不得稱為 `SUBMITTED`、`ACCEPTED`。未變動其他 Task 原稿、RR 狀態與 T01 審核。
