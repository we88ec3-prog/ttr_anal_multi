# E36 — RR-0005：衍生／基底 transport 析構的雙 map 所有權、BF68 狀態相依重用與首次收發限定證據

**研究完成**：2026-10-29T21:40:09+08:00；**原件**：KR `Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`Tartaros.exe` 與 `Event.stp` 本段不執行亦不修改，主證為 `Tartaros.bin` i386 raw bytes。`.text` `raw=VA-0x400C00`，僅 `.text` 範圍採此式；反組譯命令固定 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00`。

**當次 Git 基準**：`main=e751b18922d205d86dea9f280cfd060f62752bc7`；`extra/roy1=6e16fd7260297f90dde6dc18bb8bc9d278f05af3`。來源：main `AGENTS.md`、`kr/tasks/T02/{README.md,task.json}`、`research/dispatch/{README.md,inbox/T02.md}`、`research/requests/index.json`、`shared/verified-knowledge/`、T01 受限 FULL-PASS（尤其 tree erase）、`kr-bulk-roy/<KR-SHA>/functions/*.c` 和 E26–E35。**RR-0005 主責仍是 KR T02，`QUEUED/PENDING`，未認領；本段及 E32–E35 僅作原稿發布，絕不修改台帳或 T01/S00 斷言。** 使用者於本次明確授權所有尚未提交完整分析 Push 到研究分支，但不構成 RR 認領授權。

## 0. 本次與 E35 相比的實質新證據

1. **已確認（有限）**：`0x806670` 的析構包装呼叫 `0x8066A0`；該類別在其對象 `+0x1C` 的 keyed-tree 中逐一取得 node+0x10 的 `Conn*`，移到 pool `+0x48` 並寫 `Conn+0x14=0`。其後 `0x807F20` 發出 per worker IOCP 結束訊息，等待工作執行緒終止，再呼叫 `0x803EC0`。這是先前未涵蓋的**整個 transport 物件的 teardown**，並非每次普通 `+0x24` close 必然執行。
2. **已確認（有限）**：`0x803EC0` **是另一個** base `CNetwork` 析構區段（vptr 從 `0xC51748` 換 `0xC51408`），對基底樹頭 `object+0x0C` 逐一執行 `closesocket(*node+0x10)`、`free(node+0x10)`；其後通知並等待基底工作執行緒停止，刪掉 base/derived 樹容器。`0x8066A0` 走訪的 `object+0x1C` **不是** `0x803EC0` 走訪的 `object+0x0C`，不能說 base close 必然覆蓋同一群 key0/key1/key2 socket。反過來也不能斷言整個析構「沒有 closesocket」。
3. **已確認（有限）**：`0x490FE0` 主迴圈在 `DAT_00F93934 < 5` 的分支 `0x491C3A`，以 **同一個 Client+BF68** 作為數值倒數／狀態計數（比較 `-1`, `0x21`，設成 `0xFA0` 或減 `0x21`），並於 `0x491C8B` 寫 `Client+BF64=timeGetTime()`；`0x4957C0` 的成功路徑則把 `Client+BF64/BF68` 寫成 key0/key2 的 `Conn*`。故兩 offset 具**階段相依的儲存用途**，先前 E35 的「這些欄位永遠是 slot」必須限縮到選服成功的上下文；並不自動證明兩個階段互斥的所有動態 interleave。
4. **已確認（有限）**：`0x490FE0` 在 `DAT_00F93934>=5` 的相鄰分支呼叫 transport `+0x20` 針對 key0/1/2 執行 `shutdown(SD_SEND)`，呈現全 key 半關閉的控制路徑，與 normal `0x4957C0` 轉服的 old key1 `0x007E` 排隊是**不同的觸發情境**。
5. **尚未確認**：`keyed tree` 對普通 close/remap 仍未有全面的 per-key erase；也未證 `BF60/BF64/BF68` 在一般 `closesocket` 後立即清零。不同建構／析構/狀態分支，不能拼成同一條一定發生的可玩時序。

## 1. Round 1：完整 transport 析構 ownership：derived keyed-map → IOCP join → base socket-map

### 1.1 關鍵拓樸／結構分層

| 指標/欄位 | 由誰訪問 | 本輪原始碼支持的語意 | 不可混淆 |
|---|---|---|---|
| object+0x1C (derived map head) | 0x8066A0、0x806AD0、0x806F80、0x8069A0 | keyed-tree，node+0xC key，node+0x10 Conn* | 不等於 base `+0xC` |
| object+0x0C (base map head) | 0x803EC0 | 基底 tree node+0x10 另一個值指標，`*value` 作 SOCKET 傳 `closesocket` | 不可自動推導 key0/1/2 也收錄於此樹 |
| global pool `DAT_FBA858+0x48` | 0x805A80、0x8066A0、0x805B40 | 延後回收清單；`Conn+A0B8` 是 send pending gate | 不是 socket map、不是保證 recv zero |
| `0x806670` | transport virtual destructor / wrapper | 呼叫 0x8066A0；有 flag 才 free outer object | 非一般 `+0x20`、`+0x24` |
| vptr `0xC51748` → `0xC51408` | 0x8066A0 / 0x803EC0 | derived `CIocpNetwork` → base `CNetwork` 析構鏈 | 此符號來自 kr-bulk/RTTI 線索；實際 vptr write 由 BIN 確認 |

不能把 `0x8066A0` 進 pool 的 `Conn*`、`0x803EC0` free 的 base entry payload、或 `0x7B6890` erase 的 0x18-byte 樹節點三者當成同一筆配置。此前 E31/T01 的 tree erase FULL-PASS 只保證正確連結/iterator/節點 free；不能據此提升 Conn 回收主張。

### 1.2 0x806670 析構 wrapper、0x8066A0 derived map 逐筆搬移與呼叫後續

注意 `0x8066C9` 改寫 vptr，`0x8066D6` 取 `[edi+0x1C]` 樹頭，`0x80673C` 取 `node+0x10`，`0x806775` 設 conn+0x14=0；`0x806813/0x806821` 分別是 IOCP workers join / base dtor call。

```asm
  806670:	55                   	push   ebp
  806671:	8b ec                	mov    ebp,esp
  806673:	56                   	push   esi
  806674:	8b f1                	mov    esi,ecx
  806676:	56                   	push   esi
  806677:	e8 24 00 00 00       	call   0x8066a0
  80667c:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  806680:	74 09                	je     0x80668b
  806682:	56                   	push   esi
  806683:	e8 84 ab 08 00       	call   0x89120c
  806688:	83 c4 04             	add    esp,0x4
  80668b:	8b c6                	mov    eax,esi
  80668d:	5e                   	pop    esi
  80668e:	5d                   	pop    ebp
  80668f:	c2 04 00             	ret    0x4
  806692:	cc                   	int3
  806693:	cc                   	int3
  806694:	cc                   	int3
  806695:	cc                   	int3
  806696:	cc                   	int3
  806697:	cc                   	int3
  806698:	cc                   	int3
  806699:	cc                   	int3
  80669a:	cc                   	int3
  80669b:	cc                   	int3
  80669c:	cc                   	int3
  80669d:	cc                   	int3
  80669e:	cc                   	int3
  80669f:	cc                   	int3
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

### 1.3 0x803EC0 base map 的 closesocket、free、thread stop

`[edi+0xC]` 是 base 樹頭，不是 derived `[edi+0x1C]`；`0x803F01` 取 node+0x10，`0x803F04..0D` 對其首 DWORD closesocket，`0x803F0D..16` 對 payload 指標 free。注意此處沒有對 Conn+A0B8 做正常 close 的等同推論。

```asm
  803ec0:	55                   	push   ebp
  803ec1:	8b ec                	mov    ebp,esp
  803ec3:	6a ff                	push   0xffffffff
  803ec5:	68 e5 9a 90 00       	push   0x909ae5
  803eca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  803ed0:	50                   	push   eax
  803ed1:	83 ec 0c             	sub    esp,0xc
  803ed4:	53                   	push   ebx
  803ed5:	56                   	push   esi
  803ed6:	57                   	push   edi
  803ed7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  803edc:	33 c5                	xor    eax,ebp
  803ede:	50                   	push   eax
  803edf:	8d 45 f4             	lea    eax,[ebp-0xc]
  803ee2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  803ee8:	8b f9                	mov    edi,ecx
  803eea:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  803eed:	c7 07 08 14 c5 00    	mov    DWORD PTR [edi],0xc51408
  803ef3:	33 db                	xor    ebx,ebx
  803ef5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  803ef8:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  803efb:	8b 30                	mov    esi,DWORD PTR [eax]
  803efd:	3b f0                	cmp    esi,eax
  803eff:	74 58                	je     0x803f59
  803f01:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  803f04:	8b 08                	mov    ecx,DWORD PTR [eax]
  803f06:	51                   	push   ecx
  803f07:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  803f0d:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  803f10:	50                   	push   eax
  803f11:	e8 f6 d2 08 00       	call   0x89120c
  803f16:	83 c4 04             	add    esp,0x4
  803f19:	38 5e 15             	cmp    BYTE PTR [esi+0x15],bl
  803f1c:	75 36                	jne    0x803f54
  803f1e:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  803f21:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  803f24:	75 15                	jne    0x803f3b
  803f26:	8b f0                	mov    esi,eax
  803f28:	8b 06                	mov    eax,DWORD PTR [esi]
  803f2a:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  803f2d:	75 25                	jne    0x803f54
  803f2f:	90                   	nop
  803f30:	8b f0                	mov    esi,eax
  803f32:	8b 06                	mov    eax,DWORD PTR [esi]
  803f34:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  803f37:	74 f7                	je     0x803f30
  803f39:	eb 19                	jmp    0x803f54
  803f3b:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  803f3e:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  803f41:	75 0f                	jne    0x803f52
  803f43:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  803f46:	75 0a                	jne    0x803f52
  803f48:	8b f0                	mov    esi,eax
  803f4a:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  803f4d:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  803f50:	74 f1                	je     0x803f43
  803f52:	8b f0                	mov    esi,eax
  803f54:	3b 77 0c             	cmp    esi,DWORD PTR [edi+0xc]
  803f57:	75 a8                	jne    0x803f01
  803f59:	8b 57 50             	mov    edx,DWORD PTR [edi+0x50]
  803f5c:	6a ff                	push   0xffffffff
  803f5e:	52                   	push   edx
  803f5f:	c7 47 4c 01 00 00 00 	mov    DWORD PTR [edi+0x4c],0x1
  803f66:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  803f6c:	8b 47 50             	mov    eax,DWORD PTR [edi+0x50]
  803f6f:	50                   	push   eax
  803f70:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  803f76:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
  803f7c:	8d 5f 18             	lea    ebx,[edi+0x18]
  803f7f:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  803f82:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  803f86:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  803f89:	8b 08                	mov    ecx,DWORD PTR [eax]
  803f8b:	50                   	push   eax
  803f8c:	51                   	push   ecx
  803f8d:	8d 75 e8             	lea    esi,[ebp-0x18]
  803f90:	8b c3                	mov    eax,ebx
  803f92:	e8 29 01 d5 ff       	call   0x5540c0
  803f97:	8b 5b 04             	mov    ebx,DWORD PTR [ebx+0x4]
  803f9a:	53                   	push   ebx
  803f9b:	e8 6c d2 08 00       	call   0x89120c
  803fa0:	8d 5f 08             	lea    ebx,[edi+0x8]
  803fa3:	83 c4 04             	add    esp,0x4
  803fa6:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  803fa9:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  803fad:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  803fb0:	8b 08                	mov    ecx,DWORD PTR [eax]
  803fb2:	50                   	push   eax
  803fb3:	51                   	push   ecx
  803fb4:	8d 75 ec             	lea    esi,[ebp-0x14]
  803fb7:	8b c3                	mov    eax,ebx
  803fb9:	e8 02 01 d5 ff       	call   0x5540c0
  803fbe:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  803fc1:	51                   	push   ecx
  803fc2:	e8 45 d2 08 00       	call   0x89120c
  803fc7:	83 c4 04             	add    esp,0x4
  803fca:	c7 07 fc 13 c5 00    	mov    DWORD PTR [edi],0xc513fc
  803fd0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  803fd3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  803fda:	59                   	pop    ecx
  803fdb:	5f                   	pop    edi
  803fdc:	5e                   	pop    esi
  803fdd:	5b                   	pop    ebx
  803fde:	8b e5                	mov    esp,ebp
  803fe0:	5d                   	pop    ebp
  803fe1:	c3                   	ret
```

### 1.4 0x807F20 IOCP shutdown sentinel 與 join

此函式呼叫 `PostQueuedCompletionStatus(...,CompletionKey=1,OVERLAPPED=0)` 給 worker，`WaitForMultipleObjects` 等待，關閉 thread handles；這是在 destructor path，未能擴大到每次 key remap。

```asm
  807f20:	53                   	push   ebx
  807f21:	57                   	push   edi
  807f22:	33 ff                	xor    edi,edi
  807f24:	39 7e 04             	cmp    DWORD PTR [esi+0x4],edi
  807f27:	7e 18                	jle    0x807f41
  807f29:	8b 1d 70 22 bd 00    	mov    ebx,DWORD PTR ds:0xbd2270
  807f2f:	90                   	nop
  807f30:	8b 06                	mov    eax,DWORD PTR [esi]
  807f32:	6a 00                	push   0x0
  807f34:	6a 01                	push   0x1
  807f36:	6a 00                	push   0x0
  807f38:	50                   	push   eax
  807f39:	ff d3                	call   ebx
  807f3b:	47                   	inc    edi
  807f3c:	3b 7e 04             	cmp    edi,DWORD PTR [esi+0x4]
  807f3f:	7c ef                	jl     0x807f30
  807f41:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  807f44:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  807f47:	6a ff                	push   0xffffffff
  807f49:	6a 01                	push   0x1
  807f4b:	51                   	push   ecx
  807f4c:	52                   	push   edx
  807f4d:	ff 15 b4 22 bd 00    	call   DWORD PTR ds:0xbd22b4
  807f53:	33 ff                	xor    edi,edi
  807f55:	39 7e 04             	cmp    DWORD PTR [esi+0x4],edi
  807f58:	7e 15                	jle    0x807f6f
  807f5a:	8b 1d c8 21 bd 00    	mov    ebx,DWORD PTR ds:0xbd21c8
  807f60:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  807f63:	8b 0c b8             	mov    ecx,DWORD PTR [eax+edi*4]
  807f66:	51                   	push   ecx
  807f67:	ff d3                	call   ebx
  807f69:	47                   	inc    edi
  807f6a:	3b 7e 04             	cmp    edi,DWORD PTR [esi+0x4]
  807f6d:	7c f1                	jl     0x807f60
  807f6f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  807f72:	5f                   	pop    edi
  807f73:	5b                   	pop    ebx
  807f74:	85 c0                	test   eax,eax
  807f76:	74 10                	je     0x807f88
  807f78:	50                   	push   eax
  807f79:	e8 bf 9d 08 00       	call   0x891d3d
  807f7e:	83 c4 04             	add    esp,0x4
  807f81:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  807f88:	c3                   	ret
  807f89:	cc                   	int3
  807f8a:	cc                   	int3
  807f8b:	cc                   	int3
  807f8c:	cc                   	int3
  807f8d:	cc                   	int3
  807f8e:	cc                   	int3
  807f8f:	cc                   	int3
  807f90:	55                   	push   ebp
  807f91:	8b ec                	mov    ebp,esp
  807f93:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807f96:	8b 01                	mov    eax,DWORD PTR [ecx]
  807f98:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  807f9b:	ff d2                	call   edx
  807f9d:	33 c0                	xor    eax,eax
  807f9f:	5d                   	pop    ebp
  807fa0:	c2 04 00             	ret    0x4
  807fa3:	cc                   	int3
  807fa4:	cc                   	int3
  807fa5:	cc                   	int3
  807fa6:	cc                   	int3
  807fa7:	cc                   	int3
  807fa8:	cc                   	int3
  807fa9:	cc                   	int3
  807faa:	cc                   	int3
  807fab:	cc                   	int3
  807fac:	cc                   	int3
  807fad:	cc                   	int3
  807fae:	cc                   	int3
  807faf:	cc                   	int3
  807fb0:	55                   	push   ebp
  807fb1:	8b ec                	mov    ebp,esp
  807fb3:	51                   	push   ecx
  807fb4:	53                   	push   ebx
  807fb5:	56                   	push   esi
  807fb6:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  807fb9:	2b 37                	sub    esi,DWORD PTR [edi]
  807fbb:	33 db                	xor    ebx,ebx
  807fbd:	c1 fe 02             	sar    esi,0x2
  807fc0:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  807fc3:	3b f3                	cmp    esi,ebx
  807fc5:	74 26                	je     0x807fed
  807fc7:	76 2b                	jbe    0x807ff4
  807fc9:	8d a4 24 00 00 00  	lea    esp,[esp+0x0]
```

### 1.5 第一輪的排除與局限

- 所有正向結論限定函式按合法物件／樹結構正常走到尾端；不能假定例外、mutex/IOCP race 或 OS 回收順序。
- derived map 迭代本身沒有 `closesocket`；**base** map 迭代有 `closesocket`。兩個集合不同，此後仍須追 **base map 的插入者和 key1/key0/key2 outbound Conn 是否也被插入**。
- 不能把析構時 `0x807F20` 全 worker join，當作普通 `0x806FC0`、partial failure 或 Same-key overwrite 的 generation fence；它們沒有在對應局部分支呼叫此函式。
- 本輪已達重大新發現門檻（先前未知的 base destructor `closesocket` + 兩 map 區分）；依使用者研究深度需求再延伸 Round2/3，非用函式清單充數。

## 2. Round 2：Client+BF60/BF64/BF68 寫入者、狀態 gate 與主循環斷線策略

### 2.1 靜態 `.text` immediate-offset 全掃描（定位，不等同每筆都是 writer）

對完整 `.text` raw `[0x400,0x7D0600)` 搜 `imm32 little-endian`：`BF60` 出現 11 次；`BF64` 出現 3 次；`BF68` 出現 12 次。**此掃描是候選存取位置**，未自動證明位址都屬同一實例；逐個 relevant 位置另用指令上下文核對。

```text
BF60: 48ACB8, 49570F, 495735, 49573D, 495796, 495819, 495834, 49584E, 49585A, 49586A, 4C3B60
BF64: 48ACBE, 491C8D, 49595D
BF68: 48ACC4, 491C3C, 491C5B, 491CA3, 495964, 5CC719, 626C9A, 6CE4C0, 6D3DAB, 72F5CD, 7DA2E0, 7DA33D
```

本次 `0x491C3A` 及 `0x4957C0` 使用同一由函式 Client 參數／已確認儲存槽導來的對象基址；其他遠端函式 `5CC719` 等**尚未做相同基址追蹤**，不因 offset 數字相同便套用。

### 2.2 0x48ACAD..0x48ACCA：三欄初始化為零

指令 `mov [edi+BF60/64/68],ebx` 需上游確認 EBX=0；此處提供三個 field 在特定 Client 初始化例程的相鄰清零證據。

```asm
  48aca9:	5a                   	pop    edx
  48acaa:	c0 00 c7             	rol    BYTE PTR [eax],0xc7
  48acad:	87 00                	xchg   DWORD PTR [eax],eax
  48acaf:	02 00                	add    al,BYTE PTR [eax]
  48acb1:	00 04 5b             	add    BYTE PTR [ebx+ebx*2],al
  48acb4:	c0 00 89             	rol    BYTE PTR [eax],0x89
  48acb7:	9f                   	lahf
  48acb8:	60                   	pusha
  48acb9:	bf 00 00 89 9f       	mov    edi,0x9f890000
  48acbe:	64 bf 00 00 89 9f    	fs mov edi,0x9f890000
  48acc4:	68 bf 00 00 89       	push   0x890000bf
  48acc9:	9f                   	lahf
  48acca:	6c                   	ins    BYTE PTR es:[edi],dx
  48accb:	bf           	mov    edi,0x87c70000
```

### 2.3 0x490FE0 主循環：Client 參數與 disconnected callback

`0x491020` 從入口 [ebp+8] 取 Client 參數，保存在 [esp+20]；走 pool+0x28 disconnected list，若 Client+BF58 匹配 conn 會觸發 callback。**沒有這裡直接清 BF60/BF64/BF68 的指令**，與同類 UI/slot 清除不可混淆。

```asm
  490fe0:	55                   	push   ebp
  490fe1:	8b ec                	mov    ebp,esp
  490fe3:	83 e4 f8             	and    esp,0xfffffff8
  490fe6:	6a ff                	push   0xffffffff
  490fe8:	68 d0 98 94 00       	push   0x9498d0
  490fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  490ff3:	50                   	push   eax
  490ff4:	81 ec 40 03 00 00    	sub    esp,0x340
  490ffa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  490fff:	33 c4                	xor    eax,esp
  491001:	89 84 24 38 03 00 00 	mov    DWORD PTR [esp+0x338],eax
  491008:	53                   	push   ebx
  491009:	56                   	push   esi
  49100a:	57                   	push   edi
  49100b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  491010:	33 c4                	xor    eax,esp
  491012:	50                   	push   eax
  491013:	8d 84 24 50 03 00 00 	lea    eax,[esp+0x350]
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49102f:	75 14                	jne    0x491045
  491031:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491037:	74 07                	je     0x491040
  491039:	e8 22 9f 00 00       	call   0x49af60
  49103e:	eb 05                	jmp    0x491045
  491040:	e8 bb 9f 00 00       	call   0x49b000
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  491055:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49105b:	75 14                	jne    0x491071
  49105d:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491063:	74 07                	je     0x49106c
  491065:	e8 f6 9e 00 00       	call   0x49af60
  49106a:	eb 05                	jmp    0x491071
  49106c:	e8 8f 9f 00 00       	call   0x49b000
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
```

### 2.4 `0x49197F` 恢復 EDI=Client param；`0x491A76` state gate → BF68 倒數或 all-key half shutdown

`0x49197F mov edi,[esp+20]` + `0x491A76 cmp [F93934],5` 是證明以下 BF68 writer 基址和分支可達性所需的上游配對。

```asm
  49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  49199f:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xc
  4919a6:	0c 00 00 00 
  4919aa:	e8 41 26 37 00       	call   0x803ff0
  4919af:	68 90 dc bc 00       	push   0xbcdc90
  4919b4:	e8 61 09 40 00       	call   0x89231a
  4919b9:	83 c4 04             	add    esp,0x4
  4919bc:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  4919c3:	ff ff ff ff 
  4919c7:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  4919ce:	0f b6 05 fa 11 fc 00 	movzx  eax,BYTE PTR ds:0xfc11fa
  4919d5:	8d 0c 40             	lea    ecx,[eax+eax*2]
  4919d8:	8b 34 cd 40 11 fc 00 	mov    esi,DWORD PTR [ecx*8+0xfc1140]
  4919df:	75 2f                	jne    0x491a10
  4919e1:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  4919e8:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xd
  4919ef:	0d 00 00 00 
  4919f3:	e8 f8 25 37 00       	call   0x803ff0
  4919f8:	68 90 dc bc 00       	push   0xbcdc90
  4919fd:	e8 18 09 40 00       	call   0x89231a
  491a02:	83 c4 04             	add    esp,0x4
  491a05:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491a0c:	ff ff ff ff 
  491a10:	33 c0                	xor    eax,eax
  491a12:	38 05 fa 11 fc 00    	cmp    BYTE PTR ds:0xfc11fa,al
  491a18:	0f 94 c0             	sete   al
  491a1b:	8d 14 40             	lea    edx,[eax+eax*2]
  491a1e:	8b 04 d5 40 11 fc 00 	mov    eax,DWORD PTR [edx*8+0xfc1140]
  491a25:	03 c6                	add    eax,esi
  491a27:	83 bf 20 c0 00 00 00 	cmp    DWORD PTR [edi+0xc020],0x0
  491a2e:	8d b7 20 c0 00 00    	lea    esi,[edi+0xc020]
  491a34:	74 03                	je     0x491a39
  491a36:	01 46 48             	add    DWORD PTR [esi+0x48],eax
  491a39:	e8 b2 94 24 00       	call   0x6daef0
  491a3e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491a45:	75 2f                	jne    0x491a76
  491a47:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491a4e:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xe
  491a55:	0e 00 00 00 
  491a59:	e8 32 fb 04 00       	call   0x4e1590
  491a5e:	68 80 cc bc 00       	push   0xbccc80
  491a63:	e8 b2 08 40 00       	call   0x89231a
  491a68:	83 c4 04             	add    esp,0x4
  491a6b:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491a72:	ff ff ff ff 
  491a76:	83 3d 34 39 f9 00 05 	cmp    DWORD PTR ds:0xf93934,0x5
  491a7d:	0f 8c b7 01 00 00    	jl     0x491c3a
  491a83:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491a8a:	75 2f                	jne    0x491abb
  491a8c:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491a93:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xf
  491a9a:	0f 00 00 00 
  491a9e:	e8 ed fa 04 00       	call   0x4e1590
  491aa3:	68 80 cc bc 00       	push   0xbccc80
  491aa8:	e8 6d 08 40 00       	call   0x89231a
  491aad:	83 c4 04             	add    esp,0x4
  491ab0:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491ab7:	ff ff ff ff 
  491abb:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491ac1:	c7 05 38 39 f9 00 01 	mov    DWORD PTR ds:0xf93938,0x1
  491ac8:	00 00 00 
  491acb:	8b 01                	mov    eax,DWORD PTR [ecx]
  491acd:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ad0:	6a 01                	push   0x1
  491ad2:	6a 00                	push   0x0
  491ad4:	ff d2                	call   edx
  491ad6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491adc:	8b 01                	mov    eax,DWORD PTR [ecx]
  491ade:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ae1:	6a 01                	push   0x1
  491ae3:	6a 01                	push   0x1
  491ae5:	ff d2                	call   edx
  491ae7:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491aed:	8b 01                	mov    eax,DWORD PTR [ecx]
  491aef:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491af2:	6a 01                	push   0x1
  491af4:	6a 02                	push   0x2
  491af6:	ff d2                	call   edx
  491af8:	8b f7                	mov    esi,edi
  491afa:	e8 a1 d2 24 00       	call   0x6deda0
```

### 2.5 `0x491C3A` 相依 BF68 writer（只在 state<5）

`BF68==-1` skip；全域 `FBA7AC==0` skip；`<=0x21` 設 `0xFA0` 並走 `+BF64=timeGetTime()`，`>0x21` 減 `0x21`。數字不能視為 socket pointer；無權將可能的 frame/timeout 單位命名為 official server timing。

```asm
  491c3a:	8b 87 68 bf 00 00    	mov    eax,DWORD PTR [edi+0xbf68]
  491c40:	33 f6                	xor    esi,esi
  491c42:	83 f8 ff             	cmp    eax,0xffffffff
  491c45:	74 60                	je     0x491ca7
  491c47:	39 35 ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,esi
  491c4d:	74 58                	je     0x491ca7
  491c4f:	83 f8 21             	cmp    eax,0x21
  491c52:	7f 4a                	jg     0x491c9e
  491c54:	b8 10 00 00 00       	mov    eax,0x10
  491c59:	c7 87 68 bf 00 00 a0 	mov    DWORD PTR [edi+0xbf68],0xfa0
  491c60:	0f 00 00 
  491c63:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  491c68:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  491c6e:	75 15                	jne    0x491c85
  491c70:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491c76:	8b 11                	mov    edx,DWORD PTR [ecx]
  491c78:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  491c7b:	6a 02                	push   0x2
  491c7d:	8d 44 24 18          	lea    eax,[esp+0x18]
  491c81:	50                   	push   eax
  491c82:	56                   	push   esi
  491c83:	ff d2                	call   edx
  491c85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  491c8b:	89 87 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],eax
  491c91:	e8 0a 2f f7 ff       	call   0x404ba0
  491c96:	ff 80 54 5f 00 00    	inc    DWORD PTR [eax+0x5f54]
  491c9c:	eb 09                	jmp    0x491ca7
  491c9e:	83 c0 df             	add    eax,0xffffffdf
  491ca1:	89 87 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],eax
  491ca7:	39 b7 cc bf 00 00    	cmp    DWORD PTR [edi+0xbfcc],esi
  491cad:	75 54                	jne    0x491d03
  491caf:	e8           	call   0x40f060
```

### 2.6 `0x4957C0` 的 Conn* 寫入（僅 success 路徑）

`0x49593D` 首先 queue key0 57 bytes，其後 `+0x14` 針對成功的 key0/key2 連線 post recv，末尾 `BF64=key0 Conn*`, `BF68=key2 Conn*`。對主迴圈前一個 timer 分支必須加 `state` 時間／主線條件。

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
  495973:	e8           	call   0x891001
```

### 2.7 S2C login failure 的 key1 shutdown 與 BF60 reset

`0x13` response failure/status5 分支會先呼叫 transport+0x20(key1) 的 shutdown 再 `Client+BF60=0`；這個清除與成功登入的 UI/選服資料更新是不同的回應路徑。

```asm
  4c3b3a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b3c:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4c3b3f:	57                   	push   edi
  4c3b40:	ff d2                	call   edx
  4c3b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3b48:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b4a:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4c3b4d:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c3b53:	6a 01                	push   0x1
  4c3b55:	6a 01                	push   0x1
  4c3b57:	ff d2                	call   edx
  4c3b59:	b8 05 40 00 80       	mov    eax,0x80004005
  4c3b5e:	89 be 60 bf 00 00    	mov    DWORD PTR [esi+0xbf60],edi
  4c3b64:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c3b67:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c3b6e:	59                   	pop    ecx
  4c3b6f:	5f                   	pop    edi
  4c3b70:	5e                   	pop    esi
  4c3b71:	5b                   	pop    ebx
  4c3b72:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c3b75:	33 cd                	xor    ecx,ebp
  4c3b77:	e8 85 d4 3c 00       	call   0x891001
  4c3b7c:	8b e5                	mov    esp,ebp
  4c3b7e:	5d                   	pop    ebp
  4c3b7f:	c2 0c 00             	ret    0xc
```

### 2.8 Writer/context/phase 對照（不要將值永久定型）

| context | 存取地址 | 值/效果 | 條件及意義邊界 |
|---|---|---|---|
| Client 初始化 | 0x48ACB6..0x48ACC8 | BF60/BF64/BF68 歸零 | 只表示初始值，不證所有 later reset |
| key1 login Connect | 0x495781..0x495796 | BF60 = key1 Conn* | connect successful + virtual+0x14 post recv |
| `0x13` failure/status5 | 0x4C3B42..0x4C3B64 | shutdown key1，BF60=0 | `shutdown(SD_SEND)` 不等 full close |
| 選服結果成功 | 0x49595B..0x495968 | BF64=key0 Conn*、BF68=key2 Conn* | 前提是兩個 connect 都成功；BF60 在同函式另行置零 |
| 主循環低 phase | 0x491A76 + 0x491C3A..0x491CA3 | BF68 timer-like，BF64 作 timeGetTime 輸出 | `F93934<5`，且 BF68!=−1、FBA7AC非0；不是 socket pointer proof |
| 主循環高 phase | 0x491ABB..0x491Bxx | shutdown keys0/1/2 & UI message | `F93934>=5`，不代表析構 / keyed map erase |

此雙用途不應簡化成「union 已經完全證明安全」。還需要上游狀態 writer 及同時序保證，否則仍有生命週期疑問。也不能武斷推斷選服成功後主循環必定不再進入低 phase；本段沒有把全域 `F93934` writer 全部閉合。

## 3. Round 3：第一次收發能確認到哪裡、不能保證到哪裡

### 3.1 靜態可證的局部 happens-before（非 OS 網路全序）

```
login/reconnect:
  0x495610 connect(key1, port0x20DF)
    -> success virtual+0x14(key1): 0x806A00, post WSARecv
  caller 0x6D64C0 (specific call context)
    -> 0x6D6B70 local payload 0x0081 / 0x38 bytes
    -> virtual+0x10(key1,...): 0x8069A0 -> 0x8060D0 queue
  send scheduler 0x804A40/0x805190 [asynchronous]
    -> 0x8061A0 local framing 0x0BBB / fallback0x1A68
    -> 0x8068B0 WSASend; IOCP worker 0x806CF0 completion

selection:
  0x4957C0 connect(key0,port0x20E0)
          connect(key2,port0x20DE)
   -> both success: old key1 0x007E enqueue + Conn+A0B0=1
   -> Sleep(400)  [not an acknowledgement or guaranteed delivery]
   -> virtual+0x10(key0,0x0001/57 bytes local)
   -> virtual+0x14(key0), then virtual+0x14(key2): post WSARecv
   -> BF64=Conn(key0), BF68=Conn(key2)
```

**限定證據**：以上只是限定函式內順序和已確認 scheduler/worker edges；在 `WSASend` 實際提交／response parser 路線上，仍受 queue draining、frame mode、I/O 排程與 S2C 網路結果制約。`WSARecv` post 與首個 S2C 成功解析沒有全序保證。部分 `virtual+0x10` 函式在 `length==0` 甚至可回 success without queue，不能等同已送達。

**key2 first C2S**：在 `0x4957C0` 兩個 success 的這支函式內**沒有**直接以 key2 呼叫 `virtual+0x10` 發送 payload；其最早 C2S 仍需找後續業務 callsite，不得把 key0 的 0x0001 payload 複製給 key2。**key1** 最早的 `0x0081` 是已確認的局部候選，尚不能宣稱所有 login 途徑的 first wire packet；並且一個已收到的 `0x13` response 不會由 E36 路徑證成這個候選就是該 response 的 C2S origin。

### 3.2 0x4957C0 connect 成功/部分失敗、local 57 bytes、送出和收包註冊

`0x4957C0` 用 keyed Connect、半關閉、old key1 0x007E、400ms、57 bytes key0 enqueue、post recv for 0/2。

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
  49596e:	8b 4d              	mov    ecx,DWORD PTR [ebp-0x4]
```

### 3.3 0x806AD0 connect/IOCP/map replacement（含 partial-error goto）

`0x806AD0` valid connection 與 (key,Conn*) node 注入衍生 map；`0x806C9x` 先 erase old node 再建立新 node，不是 closesocket。

```asm
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
; [remainder omitted: 7 lines; reproduce with command above]
```

### 3.4 0x806CF0 IOCP send/recv OVERLAPPED compare

`Recv OVERLAPPED = Conn+A030`；`Send OVERLAPPED = Conn+A050`，worker completion key `Conn*`；A0B8 tracked for send。非動態第一包證據。

```asm
  806dcf:	cb                   	retf
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
```

### 3.5 第一包與連線角色仍未能合法聲稱的結論

- `0x20DF`, `0x20E0`, `0x20DE` 是 **KR Client 執行檔內實參**，不是官方 Server 部署政策；是否應合併服務/代理轉發屬 S00 ADR。
- `0x495610` 的 `param3=0` + BF60 nonnull 快速 return1，沒有證實 OS liveness；此情況未必走新的 WSARecv/Connect；不能統稱「每次登入都建立 socket」。
- `0x4957C0` 選服失敗只有單邊成功時，成功方 `shutdown(SD_SEND)`，未來是否仍有 recv/close 必須追後續；若兩者都成功，舊 key1 0x007E 是入列，不是 ack。
- 不建立自訂 S2C opcodes、不把當地本機 `0xF4241/0xF4243` UI 通知當作網路命令。

## 4. 三輪門檻及下一段入口

- **Round1（重大突破，原生）**：查到 `0x8066A0 -> 0x807F20 -> 0x803EC0` 的 derived/base 析構鏈，獨立 map `+0x1C` 與 `+0x0C`；base map 原生 closesocket + free，不再誤說整個 transport teardown 沒有 close。已達重大新發現門檻。
- **Round2（新增、原生）**：全 BIN offset 候選 xref + `0x490FE0` 來源與 state gate，發現 BF68、BF64 的 phase-dependent scalar/counter 與 Conn* 寫入；另全 key shutdown 與 S2C status5 cleanup 互不相同。需要 phase writer 整體精確覆蓋才可證成功階段隔離。
- **Round3（功能鏈有限進展）**：將 connect/enqueue/recv-post/scheduler/WSASend 路線分三個 key 對照，排除無證據的「首 wire 已確認」說法；指出 key2 首次 C2S 尚無該處直接 queue。`0x806CF0`、`0x807F20` 的執行緒語意不能自動套用其它失敗分支。

### 四類剩餘問題

**Client 待逆向**：`base +0x0C` 的 insert/owner 與 `derived +0x1C` key0/1/2 是否重疊；特殊 `0x491A76` phase 變更的所有 writer/re-entry；normal `0x806FC0` close 後 per-key map 清理與 BF60/64/68 writer；key2 第一筆 C2S 和 first S2C reply 的真實 handler；IOCP event與 pool reuse 競態。上述是新 E37 首要方向。

**Server 待開發**：可容忍 `0x007E` 可能未實際送達、單邊 connect failure 的 SD_SEND，不將 Client local timer 0xFA0/0x21 當自動官方 heartbeat policy；無證據的回覆命令需保留 GAP。

**跨功能待整合**：T02 RR-0005 限定結論由 T01/S00 按新版有限主張整合審查，不聲稱正式認領或 T01 FULL-PASS；T03 RR-0003 的 `0x13` receive UI 分派另有專任，這裏只引用既有已證串接。

**待遊玩驗證**：若獲得允許之測試 trace，分別記錄 key、Conn pointer/世代、SOCKET handle、WSARecv/WSASend post + complete、兩 map node、`F93934` phase，協助驗證 first C2S/S2C 與 stale-pointer/race 是否真實發生。原 Client 不在本研究執行。

### 本段可供 T01/S00 有界萃取（不是已正式審核）

| Claim candidate | native evidence | limitation |
|---|---|---|
| `0x8066A0` derived map+0x1C 搬 pool、`0x807F20` stop、`0x803EC0` base+0xC closesocket | 本文 1.2–1.4 原生組語 | 需有效集合；不等於 normal close/same-key retry |
| `BF68` scalar vs Conn* 用途由 `F93934 < 5` 路徑 gate | 本文 2.3–2.6 | 沒證所有 phase 轉移，不能假設並發安全 |
| `0x4957C0` success 只把 57-byte local payload 送 key0 queue，且 key0/2 的 recv-post 發生於該 queue 之後 | 本文 2.6 / 3.2 | 不保證 first wire / no other producer from other thread |
| `.text` raw immediate offset candidate list | 本文 2.1、`e36_scan.py` | 這是索引，不是已審查所有 xref |

**現有 E32～E35 完整原稿不可覆寫**；本段只新增 E36 分析。Push 時 Git commit 應逐檔讀回驗證新 blob/branch head，保留 RR 狀態不變，不碰 T01 已審核內容。

### 可重現命令／來源

```bash
sha256sum Tartaros.bin
python -B e36_scan.py        # 地址導航輸出不是 CFG/full semantic proof
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x806670 --stop-address=0x80683a Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x803ec0 --stop-address=0x803fe2 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x49196e --stop-address=0x491aff Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00 --start-address=0x491c3a --stop-address=0x491cb0 Tartaros.bin
```

T01 共用知識 `CK-CLIENT-ERASE-NEXT-ITERATOR-01` 只對 `0x7B6890` 的限定 tree node unlink/iterator 成立；`kr-bulk-roy` 原件 functions 0x8066A0、0x803EC0、0x807F20、0x490FE0、0x4957C0 是導航資料，不取代本文 raw disasm。本篇未將原生推論升為正式 FULL-PASS、RR ACCEPTED、SPEC STABLE 或可玩實測。
