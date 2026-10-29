# E34 — RR-0005：Conn+A0B0 旗標到 WSASend 排程／IOCP 關閉，延後池物件重用的完整有界鏈

**研究時間**：2026-10-29T21:11:12+08:00（Asia/Taipei）。**研究線**：`extra/roy1`，此文件僅本地保存，未提交。**RR 登記**：主線 RR-0005 (`owner_task=T02, KR, P0, status=PENDING, dispatch.state=QUEUED, dispatch.claim=null`)；**使用者要求暫不認領**，等 T01 整合完畢才處理；本段未提交任何 RR state/owner，也未 Commit/Push。`RR-0001`/`RR-0004` 僅限引用傳輸框架，跨 Task T03/RR-0003 僅引用登入 handler。

**最新 GitHub（本段開工時）**：`main=e751b18922d205d86dea9f280cfd060f62752bc7`；`extra/roy1=6e16fd7260297f90dde6dc18bb8bc9d278f05af3`；直接查閱 `AGENTS.md`、`kr/tasks/T02/README.md` 與 `task.json`、`kr/tasks/T01/README.md`、`research/dispatch/README.md`、`research/dispatch/inbox/T02.md`、`research/requests/index.json`、`shared/verified-knowledge/README.md`，並檢查 T01 的整合分級。T02 README 未讀到本輪需要先解的 T01 `NEEDS_FIX` 項，使用者仍特別要求維持等待整合而只進行研究，不做正式認領。

**原始依據**：`/mnt/data/Tartaros.bin`，PE32/i386 12,472,320 bytes，SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**，本輪用 `sha256sum` 重新核對；`.text` VA 0x401000 raw offset 0x400, `.rdata` VA 0xBD2000 raw offset 0x7D0600, `.data` VA 0xD61000 raw offset 0x95E800。原始 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。第一手證據是 BIN section bytes 經 `objdump -d -M intel` 邊界直譯的組語（下述每段按 VA），**未執行、附加或修改 Client**。

**重用但不替代第一手證據**：GitHub main `kr-bulk-roy/9741d.../functions/` 的 `0x804a40.c`, `0x805190.c`, `0x806cf0.c`, `0x8068b0.c`, `0x806fc0.c`, `0x805b40.c`, `0x490fe0.c`, `0x805f50.c`, `0x8061a0.c`, `0x805a80.c` 等，皆實際讀取作導航並以相應 BIN 指令抽核；延續 E32 / E33 本地完整原稿（E32/33 尚未上傳 GitHub）。同時沿用 T03 先前 `0x13` 及 E32 RTTI 研究，**不把 decompile 自身或尚未 T01 驗證報告標為原生 FULL-PASS**。

## 0. 本段範圍、總結與證據等級

此段不是再找一次 WinSock API；要把 E33 已證 `0x806F80(+0x20)=shutdown(SD_SEND)`、`0x806FC0(+0x24)=有 guard 的 shutdown(SD_BOTH)+closesocket+延後 list`，接到真實的**事件旗標 writer、兩條發送排程路徑、IOCP result、pool recycle**，並檢查 key1 的 `0x007E` 舊登入斷線是否真的有順序／到達保證。結果取得多個可在原始 BIN 重驗的完整局部鏈；**仍不是 TCP first frame 實測**。

### 定義清楚的 Conn 欄位（只代表 Conn*，不能與 Client+BFxx 混用）

| Conn 相對偏移 | 本段原生用途 | 主要 raw VA |
|---|---|---|
| `+0xA024` | outbound buffer 尚有資料的 byte gate，在 send completion 後由 `A028>0` 派生 | `0x806EB1..0x806EB4`; queue `0x806060` |
| `+0xA028` | 已封裝 outbound stream 的待送 bytes（並非 application payload queue 個數） | `0x804B21`, `0x805273`, `0x806EAB` |
| `+0xA074/+0xA078` | app payload queue list/sz，`0x8061A0` 逐個轉成 ring frame | `0x8061A0`、`0x8063E0` |
| `+0xA0A8` | Conn 標為已停止／closed 的 guard；`0x806FC0` 入口以零值限制 closesocket | `0x806FF5`, `0x804B76`, `0x806F1F` |
| `+0xA0AC` | pool/queue 上「active/registered」旗標，send loops 與 `0x490FE0` 回收掃描用 | `0x804AC8`, `0x49108F` |
| `+0xA0B0` | **draining/stop-recv + close-request** 候選（以行為命名，非官方字段名）：舊 key1 在選服成功設 1；IOCP preamble fail 亦設 1；send schedulers 消費而呼叫 full-close | `0x49585E`, `0x806E23/6E6E`, `0x804B7C`, `0x8052D2` |
| `+0xA0B4` | send buffer/framing 特定阻塞模式 gate；不等同 close-request | `0x8061A0`，initializer `0x805DE3` |
| `+0xA0B8` | WSASend outstanding post counter；成功提交遞增，send completion 或失敗 completion 遞減；recycle 等其歸零 | `0x806961/697A`, `0x806EBD`, `0x806EF1`, `0x805BA6` |
| `+0xA0C0` | 將 Conn 加入 pool+0x28 delayed list 時記錄 tick；本次所追 `0x805B40` 未看到依 tick 做等待閘 | `0x805AA1`, `0x805B40..0x805C69` |
| `+0xA0D4` | Conn app payload queue CS，`0x8061A0` 入列/刪除同步 | `0x8061A0`, `0x806060` |

**有界新結論 A**：`A0B0=1` 不立即主動執行 `closesocket`，而是在 send stream 非空、沒有先前未完成 send 時，於同輪發送排程 `WSASend` 呼叫**之後**消費，故原始 Client 會在成功 post overlapped send **尚可能有 outstanding A0B8** 時 full close；其後 Conn* 物件由另一層等 counter=0 後才能轉入 pool reuse。這不構成對遠端已收到 `0x007E` 的證明。

**有界新結論 B**：`0x490FE0` (Client loop) 掃 `pool+0x28` closed/delayed list，對 `A0AC!=0` 的 Conn 進行 disconnected notification（限定 `client+0xBF58 == Conn*` 才觸發特定 login module virtual `+0x10(1)`），將 Conn* 加到 `pool+0x48` list 並清 `Conn+0x14`；之後呼叫 `0x805B40`，先從 `+0x28` 清理已被標 `+0x14==0` 的條目，再對 `+0x48` 中 **`A0B8==0`** 的物件 `0x805F50` reset，轉移進 pool+0x10 可重用容器。這是首次在本線閉合到的「worker → delayed list → client-loop → recycle」路徑；**仍未證 keyed-tree 完整解除所有舊 Conn* 參照**。

## 1. 第一輪：舊 key1 `0x007E` 的 `A0B0` 消費者與兩個 send scheduler

### 1.1 源頭：`0x4957C0` dual success 後對 old login Conn 設定 stop 欄位

E32/E33 已驗：key0(legacy 0x20E0) 與 key2(legacy 0x20DE) 均連線成功，若 `client+BF60` 保存舊登入 Conn*，則清 pending app queue (`0x8063E0`)→ 對舊 Conn 入列本地 `0x007E/2-byte`（`0x8060D0`）→ `oldConn+A0B0=1` → `client+BF60=0`；四個步驟在同一指令流程，但 **0x007E 僅進佇列**，不代表 `WSASend` 已呼叫。此地址命名不是「收到 server disconnect ack」。

```asm
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
```


### 1.2 發送排程器一：`0x804A40`，條件鏈並非「旗標設了便立即關」

每次循環先檢 `Conn+A0AC != 0`，以 `0x8061A0(Conn*)` 嘗試從 `A074` 的 app payload queue 轉換寫入 outbound ring；進入發送分支需要 **`Conn+A028 != 0` 且當次進入檢查 `Conn+A0B8 <= 0`**（`0x804B21/804B2E`）。以 transport vtable `+0x0C` 將 `Conn+0x5020` 中已封裝 bytes，長度 `[Conn+A028]` 提交 WSASend。其返回值 0 代表送出排程失敗（清 queue+full close）。**不論返回值為否，只要之後 A0B0 非零，這一輪會呼叫 `+0x24(Conn*,0)` 並寫 `Conn+A0A8=1`。**

關鍵順序（原生源碼地址，不是推測）：`0x804B21` 待送 bytes -> `0x804B2E` outstanding -> `0x804B5A` virtual +0x0C -> `0x804B5C` test result -> `0x804B7C` test A0B0 -> `0x804B93` virtual +0x24 -> `0x804B95` set A0A8。


```asm
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
  804b95:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
```


### 1.3 發送排程器二：`0x805190` multi-thread worker 的相同關閉邊界

`0x804D20` 由 `__beginthread(0x805190, 0, workerArgs)` 建立 worker；`0x805190` 對該 worker 的 Conn pool index subset 掃描，等 Event，結構與 `0x804A40` 相近但不是相同函式。`0x805273` 檢 outbound `A028>0`，`0x805280` 檢 `A0B8<=0`，`0x8052AC` virtual +0x0C，`0x8052D2` 檢 `A0B0`，`0x8052E9` virtual+0x24，`0x8052EB` 標 A0A8。

因此兩條 scheduler 都確實消費同一欄位，不是僅 single thread fallback; 但**不能憑靜態路徑斷言某一版本一定啟用哪條 worker**（取決於 thread 初始化及調度）。


```asm
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
  8052d2:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  8052d9:	74 1a                	je     0x8052f5
  8052db:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052e1:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052e3:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052e6:	6a 00                	push   0x0
  8052e8:	56                   	push   esi
  8052e9:	ff d2                	call   edx
  8052eb:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052f2:	00 00 00
```


### 1.4 跨週期停止／可能停滯情況

(1) 若已設 `A0B0=1`，但 `0x8061A0` 還沒把應用 payload 轉成 outbound ring（故 `A028=0`），兩 scheduler 會在 early branch **跳過 A0B0 full-close gate**。不能只看 A0B0 說已 close；是否會在後續循環變成 A028>0 要另驗證。

(2) 若 `A028>0` 但 `A0B8>0`（上一個 overlapped send 未完成），同樣先跳過 send/close gate。只有 completion 驅動 A0B8 歸零才可能再進此分支。

(3) 若檢查時 `A0B8==0`，進入 `+0x0C`，`0x8068B0` 會在 WSASend 返回成功或 WSA_IO_PENDING 時 `InterlockedIncrement(A0B8)`。**但排程沒有在 test A0B0 之前重查 A0B8**；因此可能同一輪已提交尚未 completion 的 IO 就執行 full close。這正是「關閉 FD」與「回收 Conn*」必須分開分析的原因。

(4) `0x804B9B..804C42` 與 `0x8052F5..80539C` 另有反覆送不出 (`A0A4>300`) / `A0B4==2` 的 fault-disconnect branch，和 `A0B0=1` 造成的 stop branch 不同。不要把前者的 queue purge/其他 virtual+0x1C 套用到選服舊連線。


```asm
  804b9b:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  804ba2:	01 00 00
  804ba5:	0f 8e 9d 00 00 00    	jle    0x804c48
  804bab:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  804bb2:	0f 85 90 00 00 00    	jne    0x804c48
  804bb8:	56                   	push   esi
  804bb9:	e8 22 18 00 00       	call   0x8063e0
  804bbe:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  804bc1:	8b b8 8c 00 00 00    	mov    edi,DWORD PTR [eax+0x8c]
  804bc7:	85 ff                	test   edi,edi
  804bc9:	74 51                	je     0x804c1c
  804bcb:	8b 8e a0 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0a0]
  804bd1:	8b 96 90 a0 00 00    	mov    edx,DWORD PTR [esi+0xa090]
  804bd7:	8b 86 9c a0 00 00    	mov    eax,DWORD PTR [esi+0xa09c]
  804bdd:	51                   	push   ecx
  804bde:	8b 8e 8c a0 00 00    	mov    ecx,DWORD PTR [esi+0xa08c]
  804be4:	52                   	push   edx
  804be5:	8b 96 98 a0 00 00    	mov    edx,DWORD PTR [esi+0xa098]
  804beb:	50                   	push   eax
  804bec:	8b 86 88 a0 00 00    	mov    eax,DWORD PTR [esi+0xa088]
  804bf2:	51                   	push   ecx
  804bf3:	8b 8e 94 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa094]
  804bf9:	52                   	push   edx
  804bfa:	8b 96 84 a0 00 00    	mov    edx,DWORD PTR [esi+0xa084]
  804c00:	50                   	push   eax
  804c01:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804c07:	51                   	push   ecx
  804c08:	8b 0e                	mov    ecx,DWORD PTR [esi]
  804c0a:	52                   	push   edx
  804c0b:	50                   	push   eax
  804c0c:	51                   	push   ecx
  804c0d:	68 38 14 c5 00       	push   0xc51438
  804c12:	6a 02                	push   0x2
  804c14:	e8 e7 b7 ee ff       	call   0x6f0400
  804c19:	83 c4 30             	add    esp,0x30
  804c1c:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  804c23:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804c29:	8b 11                	mov    edx,DWORD PTR [ecx]
  804c2b:	75 0d                	jne    0x804c3a
  804c2d:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  804c30:	56                   	push   esi
  804c31:	ff d0                	call   eax
  804c33:	e8 d8 13 00 00       	call   0x806010
  804c38:	eb 08                	jmp    0x804c42
  804c3a:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  804c3d:	6a 00                	push   0x0
  804c3f:	56                   	push   esi
  804c40:	ff d0                	call   eax
  804c42:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
```


## 2. 第二輪：WSASend post → completion/decrement → guarded close（不把 close 當完成送達）

### 2.1 `0x8068B0` 是 send scheduler 的 virtual +0x0C target

E19–E25 已研究過其 WSASend 地址，本段針對 RR-0005 再核 raw：`Conn+A050` 為 OVERLAPPED，`Conn+A064`（A050+0x14）是 WSABUF length，`Conn+A068` 為 buffer pointer；`Conn+A0B8` 成功/IO_PENDING 時 `InterlockedIncrement`，**非 pending error 返回 0 不加計數**。注意 local `WSASend` post 成功也**不代表對端 ACK 收到指定應用 payload**。在同一 scheduler 本輪的 `A0B0` 分支仍可進 `0x806FC0`。


```asm
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
```


### 2.2 `0x806CF0` IOCP worker：GET completion 的三種停止入口

`GetQueuedCompletionStatus` 返回 `(bytes=local_28, completionKey=local_20, ov=local_24)`；此 `local_20` 由 `0x806AD0` 在 `CreateIoCompletionPort(socket,port, (ULONG_PTR)Conn*,0)` 存入 **Conn***，非 key0/key1/key2 整數，切不可與 transport keyed tree key 混用。

分支 ① `GQCS` 失敗但 `ov != NULL`，若是 send OVERLAPPED (`Conn+A050`) 先 `InterlockedDecrement(A0B8)`；然後只有 A0B8==0 時才呼叫 `+0x24(Conn*,0)` 並設 `A0A8=1`。這可建立「失敗 completion 遞減／有界 full close」。

分支 ② `GQCS` 成功、`bytes==0`，直接呼叫 `+0x24(Conn*,0)`，標 A0A8；`+0x24` 自身仍有 `A0A8==0`+socket!=0/-1 guard，故 repeated invocation 不等同 repeated closesocket。

分支 ③ `ov == Conn+A030` 為 receive complete：若 `A0AC!=0` 才解碼 `0x807B40`，成功 (`0x807B40` 返回非 0) 再呼叫 `+0x14` 重新 post WSARecv；解析失敗則檢查 `A0B0`，若零才設一，**這條 branch 本身未呼叫 +0x24，也未再次 post recv**。這是另一個 A0B0 原生 writer/consumer，不能寫成「收到 0x13 後立即斷線」。

分支 ④ `ov == Conn+A050` 成功送出 `bytes>0`：呼叫 `0x8077B0` drain send buffer，更新 `A024` gate，然後 `InterlockedDecrement(A0B8)`，**只消耗本地 output buffer 和 outstanding counter**，不能說對端一定已解析此 payload。


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


### 2.3 本段對 E33 `+0x24` 的重要細化

`0x806FC0` 先鎖 pool+0x34，只有 `Conn+A0A8 == 0 && socket!=0 && socket!=-1` 才對 socket 做 `setsockopt(SO_LINGER)`（flag 低 byte 為0的支路）、`shutdown(sock, SD_BOTH)`、`closesocket(sock)`，再 `0x805A80(Conn*)` 放入 pool+0x28 列表。接著外部呼叫者可能寫 `Conn+A0A8=1`。這個 guard 證明 **多個 worker 對同一物件呼叫 +0x24 不代表多次 OS close**，但**沒有證明 queue 一定 flush 完成或 keyed map erase**。


```asm
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
```


## 3. 第三輪：延後回收的實際 caller / 生命週期與初始 frame 上界

### 3.1 `0x805A80` 的受限角色：加入 `pool+0x28` 等待 Client loop 處理

只有 Conn 尚未在 `pool+0x28` 名單，才寫 `Conn+A0C0=GetTickCount()` 並插入節點；**此函式不呼叫 closesocket、不查 keyed tree、不回收 Conn* 本體**。已在 E33 限定，但本段將它接到新可驗下游。


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


### 3.2 `0x490FE0` 主循環會把「已關閉的 Conn*」從 delayed list 轉往回收名單

`0x490FE0` 在 pool+0x34 critical section 下枚舉 `pool+0x28`；只處理 `Conn+A0AC!=0` 的成員。它輸出 disconnected 訊息；當 `client+BF58` **等於**該 Conn* 時才會經 `DAT_00FBACD4` login module virtual+0x10(1) 發通知（此 `BF58` **不是** E32/E33 用於舊 login `BF60`，不得強行當同一 slot）。接著同一 Conn* 被加入 **`pool+0x48`** list，並將 `Conn+0x14=0`；同一 cycle 再 `0x491203: call 0x805B40(pool)`，在這之前沒有證據顯示 keyed transport+0x18 map 已解除對 Conn* 的參照。`0x490FE0` 的 caller 在此段未全追到，故不主張固定每幀時間。


```asm
  491071:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491077:	8b 4a 28             	mov    ecx,DWORD PTR [edx+0x28]
  49107a:	8b 01                	mov    eax,DWORD PTR [ecx]
  49107c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  491080:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  491084:	3b c1                	cmp    eax,ecx
  491086:	0f 84 4a 01 00 00    	je     0x4911d6
  49108c:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  49108f:	39 b3 ac a0 00 00    	cmp    DWORD PTR [ebx+0xa0ac],esi
  491095:	75 0b                	jne    0x4910a2
  491097:	8b 00                	mov    eax,DWORD PTR [eax]
  491099:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  49109d:	e9 2c 01 00 00       	jmp    0x4911ce
  4910a2:	a1 04 f7 fd 00       	mov    eax,ds:0xfdf704
  4910a7:	bf 01 00 00 00       	mov    edi,0x1
  4910ac:	03 c7                	add    eax,edi
  4910ae:	50                   	push   eax
  4910af:	68 68 58 c0 00       	push   0xc05868
  4910b4:	a3 04 f7 fd 00       	mov    ds:0xfdf704,eax
  4910b9:	e8 a6 20 40 00       	call   0x893164
  4910be:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4910c2:	83 c4 08             	add    esp,0x8
  4910c5:	39 98 58 bf 00 00    	cmp    DWORD PTR [eax+0xbf58],ebx
  4910cb:	75 50                	jne    0x49111d
  4910cd:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4910d4:	75 35                	jne    0x49110b
  4910d6:	09 3d d0 ac fb 00    	or     DWORD PTR ds:0xfbacd0,edi
  4910dc:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4910e3:	89 35 d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,esi
  4910e9:	e8 12 52 24 00       	call   0x6d6300
  4910ee:	68 70 d6 bc 00       	push   0xbcd670
  4910f3:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4910f8:	e8 1d 12 40 00       	call   0x89231a
  4910fd:	83 c4 04             	add    esp,0x4
  491100:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491107:	ff ff ff ff
  49110b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491111:	3b ce                	cmp    ecx,esi
  491113:	74 08                	je     0x49111d
  491115:	8b 11                	mov    edx,DWORD PTR [ecx]
  491117:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  49111a:	57                   	push   edi
  49111b:	ff d0                	call   eax
  49111d:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491122:	3b c6                	cmp    eax,esi
  491124:	75 56                	jne    0x49117c
  491126:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  49112c:	74 0c                	je     0x49113a
  49112e:	e8 2d 9e 00 00       	call   0x49af60
  491133:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491138:	eb 42                	jmp    0x49117c
  49113a:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  491141:	75 2f                	jne    0x491172
  491143:	09 3d 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,edi
  491149:	68 08 12 fc 00       	push   0xfc1208
  49114e:	89 bc 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],edi
  491155:	e8 06 43 37 00       	call   0x805460
  49115a:	68 70 e6 bc 00       	push   0xbce670
  49115f:	e8 b6 11 40 00       	call   0x89231a
  491164:	83 c4 04             	add    esp,0x4
  491167:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49116e:	ff ff ff ff
  491172:	b8 08 12 fc 00       	mov    eax,0xfc1208
  491177:	a3 58 a8 fb 00       	mov    ds:0xfba858,eax
  49117c:	ff 48 44             	dec    DWORD PTR [eax+0x44]
  49117f:	8b 78 48             	mov    edi,DWORD PTR [eax+0x48]
  491182:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  491185:	8d 70 48             	lea    esi,[eax+0x48]
  491188:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  49118c:	51                   	push   ecx
  49118d:	52                   	push   edx
  49118e:	57                   	push   edi
  49118f:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  491193:	e8 68 c5 2b 00       	call   0x74d700
  491198:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  49119b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  4911a0:	2b d1                	sub    edx,ecx
  4911a2:	83 fa 01             	cmp    edx,0x1
  4911a5:	72 46                	jb     0x4911ed
  4911a7:	41                   	inc    ecx
  4911a8:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4911ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4911ae:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4911b1:	89 01                	mov    DWORD PTR [ecx],eax
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
```


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
```


### 3.3 `0x805B40`：兩種 list 分別清理，outstanding sender=0 才轉入可重用容器

首輪枚舉 `pool+0x28` (closed/delayed) list，若其 Conn+0x14==0，刪掉這條 delayed-list **節點**。這不是 socket FD close，也不等於 free Conn*。

次輪枚舉 `pool+0x48` (回收待處置) list，必須 **`Conn+A0B8==0`** 才 `0x805F50` 重設 Conn（socket 置 -1, A0AC=0, stream/reset state），把 Conn* 加入 pool+0x10 deque 作下一次 `0x805950` 候選，再刪掉 `pool+0x48` list node。`A0B8>0` 則保持在 list，等待未完成發送 completion。**本輪未在 `0x805B40` 找到基於 `A0C0` 的最短等待毫秒數；不要捏造延後回收時間。**

此為 RR-0005 的可重驗完整局部鏈：

```text
old login Conn*(BF60) queued 0x007E and A0B0=1 (0x4957C0)
  -> scheduler 0x804A40 or 0x805190
      [A0AC!=0; app queue -> ring; A028>0; precheck A0B8<=0]
      -> transport+0x0C 0x8068B0 WSASend; maybe increments A0B8
      -> if A0B0!=0, +0x24 0x806FC0 closesocket and enqueue pool+0x28
  -> IOCP 0x806CF0 completion may decrement A0B8 / drain buffer
  -> Client loop 0x490FE0 polls pool+0x28 under pool CS;
        if A0AC!=0 -> notify (BF58-specific) -> pool+0x48 ; Conn+0x14=0
        -> call 0x805B40
              clears pool+0x28 list nodes with Conn+0x14==0
              for pool+0x48 list, if A0B8==0:
                   0x805F50 resets Conn; append Conn* into pool+0x10 deque
                   remove pool+0x48 list node
  -> 0x805950 may acquire pooled Conn* in future
```

**關鍵風險/限制**：`A0B8` 是 send post counter，不證實所有 receive/IOCP callback 已完成；本次在 `0x490FE0/0x805B40` 未看到對 transport+0x18 keyed tree 的 erase。這只導出 **尚未消除 stale key→Conn* 風險的靜態研究缺口**，不能直接報成原版必然 use-after-free／漏 socket，也不能拿這個結論修改 Client 或給 Server 擬議修補。下次應核 keyed tree 的其他 caller / teardown，使 map→pool 兩種 lifetime 真正閉合。


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
```


```asm
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
```


### 3.4 重設的原生條件與下一次連線的 queue 初始狀態

`0x805F50` 將 socket 設 `INVALID_SOCKET(-1)`，清 `A0AC`, ring send state, counters, `A0B0`, `A0A8` 等，並由 `0x8063E0` 清 app payload queue，作為 pool object 重用準備。新 socket 是 `0x806AD0` 在 `0x805950` 取 object / 新分配後呼叫 WSASocket/connect；**並非 `0x805F50` 直接做重連或重新開 FD**。要注意 `0x805F50` 一次 reset 不等於傳輸 keyed index 已刪舊 key。


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


### 3.5 本地 `0x007E` / `0x0081` / `0x0001` 到 WSASend 的**靜態候選順序**，不是已抓到首包

E32/E33 的三個 app payload producer（全部使用 vtable `+0x10` 找 key-specific Conn* enqueue）：

| Conn key / 舊版靜態 port | 已證首次候選 payload producer（依此直接 caller 內） | app payload bytes | enqueue → 已證後續有條件鏈 | 不可聲稱 |
|---|---|---:|---|---|
| old login key1 / `0x20DF` | `0x4957C0` 雙成功時 old Conn 有效：`0x007E` | 2 | `0x8060D0` → `0x806060` queue → `0x8061A0` framed send ring → scheduler → `0x8068B0` | 必然送達、一定先於 key0 的新 `0x0001` |
| new login key1 / `0x20DF` | E33 `0x495280 → 0x6D64C0 → 0x6D6B70`: `0x0081` | 0x38 (=56) | 同一 queue→frame→WSASend | 正常初始登入必然第一個 TCP frame、後端必須依此 timeouts |
| new choice key0 / `0x20E0` | E32 `0x4957C0`: `0x0001` | 0x39 (=57) | 同一 queue→frame→WSASend | UI 點擊後必先送至 wire、第一 S2C reply 固定 |
| new choice key2 / `0x20DE` | `0x4957C0` 成功建立並 `+0x14` post WSARecv，但**本 caller 無可證其立即 enqueue 的業務 payload** | 未證 | 有新的 Conn* 及 receive post，不可推斷 first C2S | 「key2 不送任何封包」或特定 port 的官方身份 |

當 `Conn+A02C`/frame writer 模式允許且 queue/ring capacity 成功時，`0x8061A0` 會選 `0x807830` （0BBB header=6 bytes）或 fallback `0x807A70`（1A68 header=4 bytes）；**此處長度 2、56、57 都是 payload bytes**。因此假設成功封裝一個應用 payload、不合併其他應用命令時，對應條件性 local framed sizes：`0x007E` 2+6=8 / 2+4=6；`0x0081` 56+6=62 / 56+4=60；`0x0001` 57+6=63 / 57+4=61。這僅是可用於 future conformance test 的候選長度，`0x8061A0` 有失敗/容量 gate，**不代表每條 socket 的第一條 wire payload**。不假設 header mode、特殊壓縮/CRC、選服 server 行為或各 worker 競態。

成功建立的 key0/key2 在本 caller 先後做 Connect，回收 old login local `0x007E`、等待 `Sleep(400)`、queue `0x0001` 並先後 post WSARecv；這是 caller 指令順序，不等於跨 socket 的 send 提交順序（worker 存在並行）或 Server ACK 順序。保留 `RR-0001/0004` 的 framing/first-frame 對應缺口。

### 3.6 反證及上游尚未閉合

- **否證「選服 old Conn 直接 shutdown/closesocket」**：`0x4957C0` 自己只 queue+flag；後續依 scheduler 的 `A028`/`A0B8` gate 進 full-close；少一個條件便不能推出 close 已發生。
- **否證「WSASend 被呼叫＝收到 0x007E」**：送出提交與完成、遠端 TCP 接收、Server parser 處理至少四層不同；`0x806CF0` 僅可證本機 GQCS completion。
- **否證「close 立即 free Conn*」**：`+0x24` 插 pool+0x28；`0x490FE0` 移 pool+0x48；`0x805B40` 依 `A0B8==0` 才 reset/requeue。`closesocket` 後 Conn* 可暫留處理名單。
- **否證「IOCP 收包 preamble 異常直接關連線」**：`0x806E23..0x806E6E` 是對 A0B0 的 set/skip，不自行 +0x24。
- **保持未知**：first actual WSASend / first recv reply，`A0B0` 已設且 `A028` 長期為零的最後清理手段，`0x805B40` 之外是否有 keyed-tree erase before reuse，recv completion race、各 key Conn pointer 在 UI/receive callback 的清理，`client+0x67FA` writer 與 FUI F4243→70A bridge。

## 4. RR-0005 可整合「限定主張」草案與四類待辦

以下可供日後 T01/S00 依流程參考，**不是正式 `CLAIMS_EXTRACTED/SPEC_CONSUMABLE/NATIVE_VERIFIED`，沒有改台帳或提交**。

| 有界主張 | 分類 | 精確證據 | 限制 |
|---|---|---|---|
| 在 key0/key2 dual success、舊 BF60 非 null 下，old Conn 0x007E 入列後設 A0B0=1；不立即 close | BIN native 已確認的局部 | 0x495817..0x49586F | queue 可能失敗、async 缺失 |
| 單線/多線 scheduler 都在 A028>0 / A0B8<=0 的 send branch 消費 A0B0 並叫 +0x24 | BIN native 已確認的有界路徑 | 0x804B21..0x804B95 / 0x805273..0x8052EB | 需正確初始化與分支、未定調度順序 |
| 成功 WSASend post 遞增 A0B8；completion 遞減；same pass A0B0→close 可能發生於尚有 outstanding send | BIN native 已確認的條件序列 | 0x806961..0x806989 / 0x806EBd..0x806EC4 / 0x804B5A..0x804B95 | 不能推斷 remote application received |
| `0x490FE0` 從 delayed list 分出 Conn、`0x805B40` 依 A0B8 gate reset/reuse | BIN native 已確認的局部生命週期 | 0x491071..0x491208 / 0x805B40..0x805C68 | 沒證明全面 keyed tree/recv callback ownership |
| `0x806CF0` parser fail 設 A0B0 而不在該分支直接 closesocket | BIN native 已確認的單分支 | 0x806DF2..0x806E78 | parser 其他錯誤可另有 +0x24 |

**Client 待逆向**：① keyed tree entry 與 Conn* 的 delete/reuse reconciliation；② close 後 recv outstanding 的其他消除/guard；③ 各連線各自 first wire frame / first S2C response；④ `0x13` UI dispatch/選服事件 source，`client+0x67FA` writer；⑤ `A0B0=1/A028=0` 是否依其他 tick 機制收束。這些是 **GAP-NET-0002 的 Client side**，不應丟給未實作的 Server。

**Server 待開發**：相容測試需考慮 KR Client 對 old Conn 的可能 half/full close、到達時間非保證、new key0/key1 local command 的 bounded shapes 及先後；官方 port 的硬碼不是部署指定值。Session ownership、登出確認、timing/retry/backoff、IP/port 自定義以 ADR 標識，不能冒充官方原版 Server 內部規則。未取得 Client 端 first response，不能直接提升 SPEC 至 STABLE。

**跨功能待整合**：T02 `RR-0005` 原始網路主責；T02 `RR-0001/0004` 只處 framing first wire；T03/RR-0003 `0x13` 與 UI link；T01 限定原生審核；S00 收件/SPEC 使用。因使用者要求暫不認領，**本段只產出本地原稿，RR 保持 QUEUED**。

**待遊玩驗證**：需同版 Client/測試 Server pcapng 及分 socket key/port 的 time stamps、`WSASend` post/completion/close，核對可能未送出 0x007E、重連 key1/初始 key0 message 的真正第一個 payload。沒有 runtime trace，本段只給靜態條件與 future test vectors。

## 5. 原料與停止標準、後續 E35

- 原件 `Tartaros.bin`, `Tartaros.exe`, `Event.stp` 均已在 Project，**不請求重傳**；`pcapng`、Ghidra/REA 是可選動態/類型驗證材料，不妨礙下一段 BIN-first。
- **Round 1 (E34)**：找到 `A0B0` consumers `0x804A40`、`0x805190`，並以 raw BIN 串接 old login queue flag → two schedulers +0x24；達「重要新有界功能鏈」門檻。
- **Round 2**：沿 `0x8068B0` WSASend `A0B8++`、`0x806CF0` IOCP `A0B8--`、收包 parser-fail `A0B0=1`，加入 close-after-post 的真實競態限制，不誤判 flush guarantee。
- **Round 3**：沿 `0x806FC0` → `0x805A80(pool+0x28)` → `0x490FE0` → `0x805B40` → `0x805F50(pool+0x10)`，閉合延後回收**局部**路徑；仍保留 keyed map ownership gap。
- 第 1 輪已達重大 BIN 驗證門檻，本段額外擴展後兩輪；**沒有開 E34-2 / E34-3**，不是省略深入驗證。
- **E35 優先**：一、追 transport keyed map `+0x18` 中 old node/Conn* 的其他 erase、是否在 `0x490FE0` 或 `0x805B40` 之外解除鍵；二、查 close 後 `0x806CF0` recv completion 對重用 object 的 gate；三、追 `0x8060D0/0x806060` 到 `0x8061A0` 的主體識別與首包 scheduler，避免將入列視為傳輸成功；四、適度回到 FUI `F4243/F4241 → 0x70A/0x578` 的 event bridge。

## 6. 重驗命令與 provenance

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -h /mnt/data/Tartaros.bin | head -18
objdump -d -M intel /mnt/data/Tartaros.bin | grep -n '0xa0b0'
objdump -d -M intel --start-address=0x804A40 --stop-address=0x804C70 /mnt/data/Tartaros.bin
objdump -d -M intel --start-address=0x805190 --stop-address=0x8053B9 /mnt/data/Tartaros.bin
objdump -d -M intel --start-address=0x806CF0 --stop-address=0x806F56 /mnt/data/Tartaros.bin
objdump -d -M intel --start-address=0x805B40 --stop-address=0x805C70 /mnt/data/Tartaros.bin
objdump -d -M intel --start-address=0x490FE0 --stop-address=0x491233 /mnt/data/Tartaros.bin
```

- `kr-bulk-roy/<target SHA>/functions/0x806cf0.c`, `/0x804a40.c`, `/0x805190.c`, `/0x805b40.c`, `/0x490fe0.c` 等在 `main` 直接 fetch，僅作 machine-code 導航與 CFG 交叉。
- `extra/roy1/kr-extra-roy/` 的 E19–E31 是既有原稿；E32/E33 是本地會話生成的全文 Markdown，**本段未假稱已經合併進 main 或 T01 認領成功**。
- 原生指令時間與排程具有 runtime race；沒有目標執行、socket trace、S2C capture，絕不以靜態先後宣稱實際 wire order。

**GitHub 權限結果**：全程 GitHub read-only、BIN read-only；**無 Commit、無 Push、無 RR owner/CLAIMED、無 T01 FULL-PASS/S00 SPEC 狀態修改**。
