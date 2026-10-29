# E44 — RR-0005 / KR T02：native S2C `0x0013`／`0x007A` → secondary dispatcher → 選服表 writer → UI → Connect（研究目標導向 10 大子段）

**研究者**：chatgpt-web roy；**本地記錄時間**：2026-10-29T23:49:44+08:00 (Asia/Taipei)。**正式段號 E44**；E44.1–E44.10 是同一段號內的研究單元，非十個正式段號。**停止條件 B**：完成10個大型深度子段，研究目標未達所有第一筆 wire 與實際序列閉合，故第十段後強制交付 E45 接續；**不是**以重大發現為停止原因。

**研究目標**：沿 E43 的 `FE1B54` selected record／runtime callback 生命週期，完整追查「KR S2C 登入回覆命令 → 解析並建立群組/伺服器資料 → UI 顯示與玩家選取 → Client 的 Connect slot/port → 本地 first send／first receive」之證據鏈。優先以原生指令與真正的動態條件為邊界，不以一個重要新函式就停止。

**第一手檔案**：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次實際重算）。PE32 i386。`.text`: VA `0x401000`, raw `0x400`，故 `raw=VA−0x400C00`；`.rdata`: VA `0xBD2000`, raw `0x7D0600`，故 `raw=VA−0x401A00`；`.data`: VA `0xD61000`, raw `0x95E800`，另映射。讀檔不執行、不附加、不修改原版 Client 或二進位。每段的 assembly 由 `objdump -d -M intel --start-address --stop-address` 對**本次原始 PE** 指令解碼，不借用 decompiler 替代。局部片段輸出首/尾如接觸未知指令邊界，以已確認的 CALL/branch 位址為準，無效半指令不採證。

**開工來源**：遵守本對話先前首次 GitHub 核對基準：`main=43c51f579cada3aa6257eb8467f65af281c3585b`、`extra/roy1=34d1a55b21df78ac1c025872e641fe23dfe52645`；最新 main **未重新查詢**（依 AGENTS 同對話後續段落不例行再次全讀）。RR-0005 在已讀當時快照是 KR/T02/P0、`PENDING/QUEUED`，`claim=null/submission=null`。**無正式認領、不 Commit、不 Push、不修改 main／RR 台帳／T01／S00／其他 Task。** 本稿僅本地完整原稿，不是 Git blob、FULL-PASS、RR ACCEPTED、SPEC STABLE、可玩驗收。

## 本次摘要：從「選服表來源不明」提升為「S2C 0x13 conditional parser → UI → Connect」

**最重要新增發現**：E43 在 `FE1B54` 發現兩個 reader（`5078C0`/`507750`）並接上 `66C090→4957C0`，但沒有 upstream writer。E44 查到 `FE1B54` 的實際 constructor/writer（`5073E0`, `4C3080`, `507510`, `507610`），再往上追到二層 dispatch：`4B7EC0` → `4C4670` → 二級 **index0x13 handler `4C37A0`**（以及 **index0x7A handler `4C3C10`**）。`4C37A0` 的 `payload+0x16==0` 非空文字分支真的會調用相同 `4C3080`。這比單獨證明全域 object constructor、table、Connect caller 更進一步，完成了 **有明確條件的業務 S2C response to choice/connect**。

**仍未完全完成**：manager 真實 C+8 object identity、合法 payload 最小長度／字串 bounds、Server 首次命令來源、Connect slot wire 時序、各連線 first frame/first S2C、失敗／重試時的實際 UI 影響。必須留待 E45，不偽稱 wire first 或可玩。

**原生證據分級**：`N` 指本次可由原件逐地址驗證的 writer、index、branch、CALL；`C` 指有明確前置條件才成立的連續 chain；`U` 指缺少原件、runtime/pcap 或上下游證明；`H` 是有方向但沒有 native closure 的假說。即使 N 鏈能串接，仍不得自動提升全部為 FULL-PASS。

| VA | 原始 .text raw | 作用 |
|---|---:|---|
| `0x4B7EC0` | `0xB72C0` | 第一層 default fallback |
| `0x4C2F90` | `0xC2390` | 第二 manager 註冊 |
| `0x4C3220` | `0xC2620` | 第二層 callback writer |
| `0x4C4670` | `0xC3A70` | 第二層 command dispatch |
| `0x4C37A0` | `0xC2BA0` | native index0x13 callback |
| `0x4C3C10` | `0xC3010` | native index0x7A callback |
| `0x4C3080` | `0xC2480` | 選服資料 parser |
| `0x5073E0` | `0x1067E0` | FE1B54 constructor |
| `0x507510` | `0x106910` | group lookup/writer |
| `0x507610` | `0x106A10` | record append |
| `0x66B910` | `0x26AD10` | UI record consumer |
| `0x66C620` | `0x26BA20` | UI event handler |
| `0x66C090` | `0x26B490` | choice lookup → Connect |
| `0x4957C0` | `0x94BC0` | key0/key2 Connect |

## E44.1 — 研究基準、IOCP 應用收包橋接與 Client 次級座標

**具體問題**：此次完整鏈起點、封包四參數、Client callback 路徑是否足以連到業務命令而不是孤立 parser？

**BIN 原生結論／範圍**：`0x807D9E/0x807DAD` 以 Conn+A080 lane 送 FC10D0；`0x491983` 使用 C+8 執行 callback holder `(C+8)+0x140=C+0x148`；`0x80486D` virtual[0] 在已安裝 C05AEC 時是 `0x4930E0`；`0x4930E0` 僅 len != 0 且 lane==2 時轉 `Client+0xB8` 的 vptr+4，即 `0x48AAD0`，再按 signed WORD 轉向第一層命令表。重點為驗證此次 parser 可用的精確入口前置條件，E40/E41 已證 producer/pump 全文不重做。

**尚缺與反證**：管理器持有的實體是否在所觀察時刻必然是 C+8、動態 vptr 是否被覆寫、Conn lane 是否維持2、原生 frame 解出何種 first command，均不由靜態指令保證。不能把 lane 2 認作 transport key2。

**分類**：已證 N=指令和局部調用；條件閉合 C=正確 C+8、lane2、非空 payload；U=實際 runtime 送入某次登入資料。

### BIN 指令：IOCP payload enqueue（`0x807D7F–0x807DB2`）

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
```

### BIN 指令：mainloop holder 計算（`0x49197F–0x491990`）

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6                   	.byte 0xf6
```

### BIN 指令：FIFO callback（`0x804837–0x804876`）

```asm
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b                   	.byte 0x2b
  804875:	45                   	inc    ebp
```

### BIN 指令：Client 收件 gate（`0x4930E0–0x49315F`）

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2                   	.byte 0xc2
```

### BIN 指令：前端 signed 命令表（`0x48AAD0–0x48AB66`）

```asm
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
  48ab64:	5d                   	pop    ebp
  48ab65:	c2                   	.byte 0xc2
```


## E44.2 — 重大新鏈：FD2CF8 第一層 default 委派到可替換次級 dispatcher

**具體問題**：`0x4FDA30` 在第一層沒有專屬 handler 的 command 到底落去哪裏？能否接到後續第二張命令表？

**BIN 原生結論／範圍**：`0x4B7DC0` 在 `FD2CFC` 起 8B stride 對 0xBD5 條目先寫預設 `0x4B7EC0`，再覆寫 index2/index0BD2 等；`0x4FDA30` 先取 `[FD2CF8+cmd*8+4]`，故未覆寫 index 時調 `0x4B7EC0`。此預設 handler 先檢查 `FD2CF8+0x5EAC` 所保存的次級 manager 非零，從其 vptr+4 tail-jump；空時只記錄並返回0。`0x4B7D50` 透過正向寫入 `FD2CF8+0x5EAC` 安裝此 manager，其上游 `0x4C2F90` 在 `0x4ADD50/0x4C3220` 初始化後實際呼叫 `0x4B7D50`。這是 E39/E43 之外補上的真實跨表委派鏈。

**尚缺與反證**：0x13、0x7A 第一層未遭其他 runtime callback 修改才會走 default；次級物件只有成功配置/註冊時才非零。vtable 或 table 不存在時不得宣告所有入站命令皆能轉發。

**關鍵分歧**：`0x4B7F00` / `0x4B8DC0` 是第一層 index2/index0BD2 特殊 override；`0x4C37A0`、`0x4C3C10` 是新的第二層 handler，不能錯當第一層函式。

### BIN 指令：第一層 3029 handlers 初始化及 index2 override（`0x4B7DC0–0x4B7E20`）

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7                   	.byte 0xc7
```

### BIN 指令：第一層查表及 fallback（`0x4FDA30–0x4FDAB0`）

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
```

### BIN 指令：generic handler 轉次級或空回（`0x4B7EC0–0x4B7EF0`）

```asm
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2                   	.byte 0xc2
```

### BIN 指令：manager replacing old instance（`0x4B7D50–0x4B7DBF`）

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
```

### BIN 指令：次級 handler instance 分配/註冊（`0x4C2F57–0x4C2FD9`）

```asm
  4c2f57:	68 5c bd 00 00       	push   0xbd5c
  4c2f5c:	e8 07 e3 3c 00       	call   0x891268
  4c2f61:	8b f0                	mov    esi,eax
  4c2f63:	83 c4 04             	add    esp,0x4
  4c2f66:	3b f7                	cmp    esi,edi
  4c2f68:	74 28                	je     0x4c2f92
  4c2f6a:	e8 e1 ad fe ff       	call   0x4add50
  4c2f6f:	c7 06 fc 72 c0 00    	mov    DWORD PTR [esi],0xc072fc
  4c2f75:	89 be 54 bd 00 00    	mov    DWORD PTR [esi+0xbd54],edi
  4c2f7b:	89 be 58 bd 00 00    	mov    DWORD PTR [esi+0xbd58],edi
  4c2f81:	c7 05 74 a6 d6 00 49 	mov    DWORD PTR ds:0xd6a674,0x4c4f4749
  4c2f88:	47 4f 4c 
  4c2f8b:	e8 90 02 00 00       	call   0x4c3220
  4c2f90:	eb 02                	jmp    0x4c2f94
  4c2f92:	33 f6                	xor    esi,esi
  4c2f94:	b8 01 00 00 00       	mov    eax,0x1
  4c2f99:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  4c2f9f:	75 28                	jne    0x4c2fc9
  4c2fa1:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  4c2fa7:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  4c2fae:	6e c0 00 
  4c2fb1:	89 3d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,edi
  4c2fb7:	e8 04 4e ff ff       	call   0x4b7dc0
  4c2fbc:	68 f0 dc bc 00       	push   0xbcdcf0
  4c2fc1:	e8 54 f3 3c 00       	call   0x89231a
  4c2fc6:	83 c4 04             	add    esp,0x4
  4c2fc9:	8b fe                	mov    edi,esi
  4c2fcb:	be f8 2c fd 00       	mov    esi,0xfd2cf8
  4c2fd0:	e8 7b 4d ff ff       	call   0x4b7d50
  4c2fd5:	5f                   	pop    edi
  4c2fd6:	33 c0                	xor    eax,eax
  4c2fd8:	5e                   	pop    esi
```


## E44.3 — 第二層 vtable+4 與 0x0013／0x007A 實際 handler 註冊

**具體問題**：次級接收器是哪個 vtable？命令 0x0013 / 0x007A 是本地事件還是第二層 command table 的索引？

**BIN 原生結論／範圍**：`0x4C2F6F` 安裝 vptr `C072FC`；PE .rdata `C072FC[1]=0x4C4670`。`0x4C4670` 以 signed WORD 在 `esi+0x5EAC+index*8` 取函式，存在則呼叫，否則回退 `0x4FDA30`。`0x4C3220` 先 memset 次級 array 長度 `0x5EA8=0xBD5*8`，再寫入 `ESI+0x5F44 = 0x4C37A0` (index `(0x5F44-0x5EAC)/8=0x13`)、`ESI+0x627C = 0x4C3C10` (index `0x7A`)、`ESI+0x6054 = 0x4C3B90` (index `0x35`)。故在已註冊且第一層為 default 時，S2C 解碼後 command WORD=0x0013 可落在 `4C37A0`，command WORD=0x007A 落在 `4C3C10`。此前 E39 誤以為 FD2CF8 的 default 無下游，本次已指令級補證。

**尚缺與反證**：索引值是 **解碼 payload 的 native command WORD**，不是 frame 類型 0x0BBB/0x1A68 或 UI event 0x70A/0x578；運行時 dispatcher 物件型別/版本、未驗證的覆寫及負 signed index 仍是界線。

**`.rdata` 原件 DWORD（raw=VA−0x401A00）**：

```text
0xC072FC: 0x004C5940 0x004C4670 0x00422810 0x004227F0
0xC06EB4: 0x004C5940 0x004FDA30 0x00422810 0x004227F0
0xC05AEC: 0x004930E0 0x005F5D10 0x0049AE20 0x0049AE10
0xC05B04: 0x0049ADF0 0x0048AAD0 0x00422810 0x004227F0
```

**算式**：`0x5EA8 / 8=3029=0xBD5`，`0x5F44−0x5EAC=0x98=19*8`，`0x627C−0x5EAC=0x3D0=122*8`。

### BIN 指令：次級實際 vptr 安裝（`0x4C2F57–0x4C2F8D`）

```asm
  4c2f57:	68 5c bd 00 00       	push   0xbd5c
  4c2f5c:	e8 07 e3 3c 00       	call   0x891268
  4c2f61:	8b f0                	mov    esi,eax
  4c2f63:	83 c4 04             	add    esp,0x4
  4c2f66:	3b f7                	cmp    esi,edi
  4c2f68:	74 28                	je     0x4c2f92
  4c2f6a:	e8 e1 ad fe ff       	call   0x4add50
  4c2f6f:	c7 06 fc 72 c0 00    	mov    DWORD PTR [esi],0xc072fc
  4c2f75:	89 be 54 bd 00 00    	mov    DWORD PTR [esi+0xbd54],edi
  4c2f7b:	89 be 58 bd 00 00    	mov    DWORD PTR [esi+0xbd58],edi
  4c2f81:	c7 05 74 a6 d6 00 49 	mov    DWORD PTR ds:0xd6a674,0x4c4f4749
  4c2f88:	47 4f 4c 
  4c2f8b:	e8                   	.byte 0xe8
  4c2f8c:	90                   	nop
```

### BIN 指令：第二層 array memset 和 index 寫入（`0x4C3220–0x4C32DC`）

```asm
  4c3220:	68 a8 5e 00 00       	push   0x5ea8
  4c3225:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c322b:	6a 00                	push   0x0
  4c322d:	50                   	push   eax
  4c322e:	e8 2d b6 3d 00       	call   0x89e860
  4c3233:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c3238:	83 c4 0c             	add    esp,0xc
  4c323b:	c7 86 44 5f 00 00 a0 	mov    DWORD PTR [esi+0x5f44],0x4c37a0
  4c3242:	37 4c 00 
  4c3245:	89 86 48 5f 00 00    	mov    DWORD PTR [esi+0x5f48],eax
  4c324b:	c7 86 54 60 00 00 90 	mov    DWORD PTR [esi+0x6054],0x4c3b90
  4c3252:	3b 4c 00 
  4c3255:	89 86 58 60 00 00    	mov    DWORD PTR [esi+0x6058],eax
  4c325b:	c7 86 7c 62 00 00 10 	mov    DWORD PTR [esi+0x627c],0x4c3c10
  4c3262:	3c 4c 00 
  4c3265:	89 86 80 62 00 00    	mov    DWORD PTR [esi+0x6280],eax
  4c326b:	c7 86 b4 66 00 00 10 	mov    DWORD PTR [esi+0x66b4],0x4c3d10
  4c3272:	3d 4c 00 
  4c3275:	89 86 b8 66 00 00    	mov    DWORD PTR [esi+0x66b8],eax
  4c327b:	c7 86 bc 66 00 00 30 	mov    DWORD PTR [esi+0x66bc],0x4c3c30
  4c3282:	3c 4c 00 
  4c3285:	89 86 c0 66 00 00    	mov    DWORD PTR [esi+0x66c0],eax
  4c328b:	c7 86 84 68 00 00 b0 	mov    DWORD PTR [esi+0x6884],0x4c3fb0
  4c3292:	3f 4c 00 
  4c3295:	89 86 88 68 00 00    	mov    DWORD PTR [esi+0x6888],eax
  4c329b:	c7 86 cc 66 00 00 60 	mov    DWORD PTR [esi+0x66cc],0x4c4160
  4c32a2:	41 4c 00 
  4c32a5:	89 86 d0 66 00 00    	mov    DWORD PTR [esi+0x66d0],eax
  4c32ab:	c7 86 c4 66 00 00 90 	mov    DWORD PTR [esi+0x66c4],0x4c4090
  4c32b2:	40 4c 00 
  4c32b5:	89 86 c8 66 00 00    	mov    DWORD PTR [esi+0x66c8],eax
  4c32bb:	c7 86 8c 68 00 00 f0 	mov    DWORD PTR [esi+0x688c],0x4c3df0
  4c32c2:	3d 4c 00 
  4c32c5:	89 86 90 68 00 00    	mov    DWORD PTR [esi+0x6890],eax
  4c32cb:	c7 86 94 68 00 00 d0 	mov    DWORD PTR [esi+0x6894],0x4c3ed0
  4c32d2:	3e 4c 00 
  4c32d5:	89 86 98 68 00 00    	mov    DWORD PTR [esi+0x6898],eax
  4c32db:	c3                   	ret
```

### BIN 指令：有 override 就直接執行，無 override fallback（`0x4C4670–0x4C46EE`）

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
  4c46ed:	c2                   	.byte 0xc2
```

### BIN 指令：次級預設第一層 callback 建構（`0x4ADD50–0x4ADD6F`）

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
```


## E44.4 — 0x0013 入口：登入結果分支與選服資料直接傳向 parser

**具體問題**：新找到的 S2C native command 0x13 到底讀哪些分支？是否真的把選服記錄傳給資料表？

**BIN 原生結論／範圍**：`0x4C37A0` 是第二層 index0x13 callback。`0x4C3821` 檢查 `payload+0x16` 的 BYTE：等於5時先走獨立分支 (`0x4C382D` 起建立本地事件/狀態，`0x4C3933` 處另呼叫 network manager vptr+0x20)，不等於5且=0時沿 `0x4C3949→0x4C3951`。此=0分支先掃 `payload+2` 的 UTF-16 零終止文字，空字串走 `0x4C3A30` 錯誤；非空則把 payload+0x18、+0x17、+0x90、+0x86/0x87/0x8C 分別寫入本地 Client 相關欄位，**然後**在 `0x4C3A03` 以 `push [payload+0x1C]`、`ECX=payload+0x92` 呼叫 `0x4C3080`。因此在該分支下 `0x13 inbound → choice list parser` 是直接 CALL，不再只憑不同 Task 推測。

**尚缺與反證**：`0x4C37A0` 的 `[ebp+0xC]` 長度在列出的關鍵分支沒有明顯 guard；不能推定最小安全封包長度、UTF-16 字串保證終止、記錄計數權威，也不能將 `payload+0x16==5` 等同原版 Server 驗證失敗的完整語義。`0x58AAD0` 提交本地事件不是 wire send。

**可建立的有界命題**：已知解析 path 中 `(payload+0x16)==0 && *(UTF16*)(payload+2) != 0` → `4C3080(payload+0x92, *(DWORD*)(payload+0x1C))`；其餘狀態仍分支特定。

### BIN 指令：S2C 0x13 handler 完整主要 CFG（`0x4C37A0–0x4C3B80`）

```asm
  4c37a0:	55                   	push   ebp
  4c37a1:	8b ec                	mov    ebp,esp
  4c37a3:	6a ff                	push   0xffffffff
  4c37a5:	68 3c 07 94 00       	push   0x94073c
  4c37aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c37b0:	50                   	push   eax
  4c37b1:	81 ec 4c 04 00 00    	sub    esp,0x44c
  4c37b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c37bc:	33 c5                	xor    eax,ebp
  4c37be:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c37c1:	53                   	push   ebx
  4c37c2:	56                   	push   esi
  4c37c3:	57                   	push   edi
  4c37c4:	50                   	push   eax
  4c37c5:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c37c8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c37ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c37d1:	33 db                	xor    ebx,ebx
  4c37d3:	8d 46 20             	lea    eax,[esi+0x20]
  4c37d6:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c37dc:	89 8d b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],ecx
  4c37e2:	66 39 18             	cmp    WORD PTR [eax],bx
  4c37e5:	74 3a                	je     0x4c3821
  4c37e7:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  4c37ed:	53                   	push   ebx
  4c37ee:	53                   	push   ebx
  4c37ef:	68 00 04 00 00       	push   0x400
  4c37f4:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4c37fa:	51                   	push   ecx
  4c37fb:	6a ff                	push   0xffffffff
  4c37fd:	50                   	push   eax
  4c37fe:	53                   	push   ebx
  4c37ff:	52                   	push   edx
  4c3800:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  4c3806:	6a 32                	push   0x32
  4c3808:	8d 85 f0 fb ff ff    	lea    eax,[ebp-0x410]
  4c380e:	50                   	push   eax
  4c380f:	68 97 00 00 00       	push   0x97
  4c3814:	68 00 a7 fb 00       	push   0xfba700
  4c3819:	e8 cd 20 3d 00       	call   0x8958eb
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8 34 da 3c 00       	call   0x891268
  4c3834:	8b f8                	mov    edi,eax
  4c3836:	83 c4 04             	add    esp,0x4
  4c3839:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c383f:	33 c0                	xor    eax,eax
  4c3841:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c3844:	3b f8                	cmp    edi,eax
  4c3846:	74 4a                	je     0x4c3892
  4c3848:	33 c9                	xor    ecx,ecx
  4c384a:	50                   	push   eax
  4c384b:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c3852:	68 fc d1 be 00       	push   0xbed1fc
  4c3857:	8d 8d b8 fb ff ff    	lea    ecx,[ebp-0x448]
  4c385d:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c3864:	00 00 00 
  4c3867:	89 85 c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],eax
  4c386d:	e8 ee e8 f3 ff       	call   0x402160
  4c3872:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c3876:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c387a:	8d 95 b8 fb ff ff    	lea    edx,[ebp-0x448]
  4c3880:	52                   	push   edx
  4c3881:	bb 01 00 00 00       	mov    ebx,0x1
  4c3886:	57                   	push   edi
  4c3887:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c388d:	e8 6e 06 29 00       	call   0x753f00
  4c3892:	50                   	push   eax
  4c3893:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4c389a:	e8 b1 71 0c 00       	call   0x58aa50
  4c389f:	83 ce ff             	or     esi,0xffffffff
  4c38a2:	83 c4 04             	add    esp,0x4
  4c38a5:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c38a8:	f6 c3 01             	test   bl,0x1
  4c38ab:	74 35                	je     0x4c38e2
  4c38ad:	83 bd cc fb ff ff 08 	cmp    DWORD PTR [ebp-0x434],0x8
  4c38b4:	72 0f                	jb     0x4c38c5
  4c38b6:	8b 85 b8 fb ff ff    	mov    eax,DWORD PTR [ebp-0x448]
  4c38bc:	50                   	push   eax
  4c38bd:	e8 4a d9 3c 00       	call   0x89120c
  4c38c2:	83 c4 04             	add    esp,0x4
  4c38c5:	33 ff                	xor    edi,edi
  4c38c7:	33 c9                	xor    ecx,ecx
  4c38c9:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c38d0:	00 00 00 
  4c38d3:	89 bd c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],edi
  4c38d9:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c38e0:	eb 02                	jmp    0x4c38e4
  4c38e2:	33 ff                	xor    edi,edi
  4c38e4:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4c38eb:	75 2e                	jne    0x4c391b
  4c38ed:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4c38f4:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  4c38fb:	89 3d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,edi
  4c3901:	e8 fa 29 21 00       	call   0x6d6300
  4c3906:	68 70 d6 bc 00       	push   0xbcd670
  4c390b:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4c3910:	e8 05 ea 3c 00       	call   0x89231a
  4c3915:	83 c4 04             	add    esp,0x4
  4c3918:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c391b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3921:	3b cf                	cmp    ecx,edi
  4c3923:	74 08                	je     0x4c392d
  4c3925:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3927:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4c392a:	57                   	push   edi
  4c392b:	ff d0                	call   eax
  4c392d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3933:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3935:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  4c3938:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c393e:	6a 01                	push   0x1
  4c3940:	6a 01                	push   0x1
  4c3942:	ff d0                	call   eax
  4c3944:	e9 10 02 00 00       	jmp    0x4c3b59
  4c3949:	84 d2                	test   dl,dl
  4c394b:	0f 85 df 00 00 00    	jne    0x4c3a30
  4c3951:	8d 7e 02             	lea    edi,[esi+0x2]
  4c3954:	8b c7                	mov    eax,edi
  4c3956:	8d 48 02             	lea    ecx,[eax+0x2]
  4c3959:	89 8d a8 fb ff ff    	mov    DWORD PTR [ebp-0x458],ecx
  4c395f:	90                   	nop
  4c3960:	66 8b 08             	mov    cx,WORD PTR [eax]
  4c3963:	83 c0 02             	add    eax,0x2
  4c3966:	66 85 c9             	test   cx,cx
  4c3969:	75 f5                	jne    0x4c3960
  4c396b:	2b 85 a8 fb ff ff    	sub    eax,DWORD PTR [ebp-0x458]
  4c3971:	d1 f8                	sar    eax,1
  4c3973:	0f 84 b7 00 00 00    	je     0x4c3a30
  4c3979:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  4c397c:	e8 1f 12 f4 ff       	call   0x404ba0
  4c3981:	89 98 e0 67 00 00    	mov    DWORD PTR [eax+0x67e0],ebx
  4c3987:	e8 14 12 f4 ff       	call   0x404ba0
  4c398c:	85 ff                	test   edi,edi
  4c398e:	74 13                	je     0x4c39a3
  4c3990:	6a 0a                	push   0xa
  4c3992:	57                   	push   edi
  4c3993:	05 e4 67 00 00       	add    eax,0x67e4
  4c3998:	6a 0b                	push   0xb
  4c399a:	50                   	push   eax
  4c399b:	e8 5e 06 3d 00       	call   0x893ffe
  4c39a0:	83 c4 10             	add    esp,0x10
  4c39a3:	0f b6 7e 17          	movzx  edi,BYTE PTR [esi+0x17]
  4c39a7:	e8 f4 11 f4 ff       	call   0x404ba0
  4c39ac:	89 b8 b4 68 00 00    	mov    DWORD PTR [eax+0x68b4],edi
  4c39b2:	8a 9e 90 00 00 00    	mov    bl,BYTE PTR [esi+0x90]
  4c39b8:	e8 e3 11 f4 ff       	call   0x404ba0
  4c39bd:	88 98 b0 68 00 00    	mov    BYTE PTR [eax+0x68b0],bl
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
  4c3a30:	0f be ca             	movsx  ecx,dl
  4c3a33:	51                   	push   ecx
  4c3a34:	68 e4 72 c0 00       	push   0xc072e4
  4c3a39:	e8 22 a1 22 00       	call   0x6edb60
  4c3a3e:	6a 34                	push   0x34
  4c3a40:	e8 23 d8 3c 00       	call   0x891268
  4c3a45:	8b f8                	mov    edi,eax
  4c3a47:	83 c4 0c             	add    esp,0xc
  4c3a4a:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c3a50:	33 c0                	xor    eax,eax
  4c3a52:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  4c3a59:	3b f8                	cmp    edi,eax
  4c3a5b:	74 4a                	je     0x4c3aa7
  4c3a5d:	50                   	push   eax
  4c3a5e:	33 d2                	xor    edx,edx
  4c3a60:	68 fc d1 be 00       	push   0xbed1fc
  4c3a65:	8d 8d d4 fb ff ff    	lea    ecx,[ebp-0x42c]
  4c3a6b:	c7 85 e8 fb ff ff 07 	mov    DWORD PTR [ebp-0x418],0x7
  4c3a72:	00 00 00 
  4c3a75:	89 85 e4 fb ff ff    	mov    DWORD PTR [ebp-0x41c],eax
  4c3a7b:	66 89 95 d4 fb ff ff 	mov    WORD PTR [ebp-0x42c],dx
  4c3a82:	e8 d9 e6 f3 ff       	call   0x402160
  4c3a87:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4c3a8b:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c3a8f:	8d 85 d4 fb ff ff    	lea    eax,[ebp-0x42c]
  4c3a95:	50                   	push   eax
  4c3a96:	bb 02 00 00 00       	mov    ebx,0x2
  4c3a9b:	57                   	push   edi
  4c3a9c:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c3aa2:	e8 59 04 29 00       	call   0x753f00
  4c3aa7:	50                   	push   eax
  4c3aa8:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  4c3aaf:	e8 9c 6f 0c 00       	call   0x58aa50
  4c3ab4:	83 ce ff             	or     esi,0xffffffff
  4c3ab7:	83 c4 04             	add    esp,0x4
  4c3aba:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c3abd:	f6 c3 02             	test   bl,0x2
  4c3ac0:	74 35                	je     0x4c3af7
  4c3ac2:	83 bd e8 fb ff ff 08 	cmp    DWORD PTR [ebp-0x418],0x8
  4c3ac9:	72 0f                	jb     0x4c3ada
  4c3acb:	8b 8d d4 fb ff ff    	mov    ecx,DWORD PTR [ebp-0x42c]
  4c3ad1:	51                   	push   ecx
  4c3ad2:	e8 35 d7 3c 00       	call   0x89120c
  4c3ad7:	83 c4 04             	add    esp,0x4
  4c3ada:	33 ff                	xor    edi,edi
  4c3adc:	33 d2                	xor    edx,edx
  4c3ade:	c7 85 e8 fb ff ff 07 	mov    DWORD PTR [ebp-0x418],0x7
  4c3ae5:	00 00 00 
  4c3ae8:	89 bd e4 fb ff ff    	mov    DWORD PTR [ebp-0x41c],edi
  4c3aee:	66 89 95 d4 fb ff ff 	mov    WORD PTR [ebp-0x42c],dx
  4c3af5:	eb 02                	jmp    0x4c3af9
  4c3af7:	33 ff                	xor    edi,edi
  4c3af9:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4c3b00:	75 2e                	jne    0x4c3b30
  4c3b02:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4c3b09:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  4c3b10:	89 3d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,edi
  4c3b16:	e8 e5 27 21 00       	call   0x6d6300
  4c3b1b:	68 70 d6 bc 00       	push   0xbcd670
  4c3b20:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4c3b25:	e8 f0 e7 3c 00       	call   0x89231a
  4c3b2a:	83 c4 04             	add    esp,0x4
  4c3b2d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c3b30:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3b36:	3b cf                	cmp    ecx,edi
  4c3b38:	74 08                	je     0x4c3b42
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
  4c3b7f:	c2                   	.byte 0xc2
```


## E44.5 — 0x007A 補充清單與共同變長 parser／迴圈欄位

**具體問題**：登入後可否再由不同 native command 重建同一份選服資料？共同 parser 具體吃哪種 record 編碼？

**BIN 原生結論／範圍**：`0x4C3C10`（次級 index0x7A）讀 `[payload+2]` DWORD 作 outer_count，並用 `ECX=payload+6`、`push outer_count` 進 `0x4C3080`；`0x4C3080` 對每個 outer entry 首先讀 WORD group_id、BYTE subcount (entry+2)，資料從 entry+3 開始；每個 subentry 從10-byte 位置擷取 `[+4..+7]` 四個 BYTE 供 `4C4330` 字串組合，當 `[+8]!=0` 時把 DWORD group object、WORD [+0]、BYTE [+8]/[+9] 傳給 `0x507610`；`EDI` 每筆內層增加 `0xA`，外層指標由本次迭代 EDI 結尾接續。`0x4C314A` local event `0xF4243` 只在循環結束後觸發。這是兩種 command 共同的列表解析器，而非兩種完全獨立的表。

**尚缺與反證**：分支只證實 **原生 parser 的條件性讀取和結構步幅**，沒有包含上游總長的範圍檢查證明；outer_count 由收到的資料指定，若長度不足不得推稱 Client 一定拒絕。`0xF4243` 是本地 UI/event 訊號，不是 wire opcode。

**僅列原生讀取而非可直接投產的 schema**：`outer[0..1] = group WORD`、`outer[2]=child_count BYTE`、`child[i]` stride10，選用 [+0 WORD,+4..7 BYTE,+8 BYTE,+9 BYTE]；需按實際 buffer len 複驗。

### BIN 指令：index 0x7A adapter（`0x4C3C10–0x4C3C26`）

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
  4c3c25:	c2                   	.byte 0xc2
```

### BIN 指令：共同群組/子記錄解析及通知（`0x4C3080–0x4C316B`）

```asm
  4c3080:	55                   	push   ebp
  4c3081:	8b ec                	mov    ebp,esp
  4c3083:	83 e4 f8             	and    esp,0xfffffff8
  4c3086:	83 ec 24             	sub    esp,0x24
  4c3089:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c308e:	33 c4                	xor    eax,esp
  4c3090:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4c3094:	53                   	push   ebx
  4c3095:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c3098:	56                   	push   esi
  4c3099:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  4c309f:	57                   	push   edi
  4c30a0:	83 c6 08             	add    esi,0x8
  4c30a3:	8b f9                	mov    edi,ecx
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
  4c312f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4c3133:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  4c3137:	40                   	inc    eax
  4c3138:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c313c:	3b c1                	cmp    eax,ecx
  4c313e:	72 a0                	jb     0x4c30e0
  4c3140:	ff 4c 24 0c          	dec    DWORD PTR [esp+0xc]
  4c3144:	0f 85 6c ff ff ff    	jne    0x4c30b6
  4c314a:	68 43 42 0f 00       	push   0xf4243
  4c314f:	e8 7c 79 0c 00       	call   0x58aad0
  4c3154:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  4c3158:	83 c4 04             	add    esp,0x4
  4c315b:	5f                   	pop    edi
  4c315c:	5e                   	pop    esi
  4c315d:	5b                   	pop    ebx
  4c315e:	33 cc                	xor    ecx,esp
  4c3160:	e8 9c de 3c 00       	call   0x891001
  4c3165:	8b e5                	mov    esp,ebp
  4c3167:	5d                   	pop    ebp
  4c3168:	c2 04 00             	ret    0x4
```

### BIN 指令：子項文字格式化 helper（`0x4C4330–0x4C43B4`）

```asm
  4c4330:	55                   	push   ebp
  4c4331:	8b ec                	mov    ebp,esp
  4c4333:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c4336:	8d 45 0c             	lea    eax,[ebp+0xc]
  4c4339:	50                   	push   eax
  4c433a:	51                   	push   ecx
  4c433b:	6a 14                	push   0x14
  4c433d:	52                   	push   edx
  4c433e:	e8 46 db 3c 00       	call   0x891e89
  4c4343:	83 c4 10             	add    esp,0x10
  4c4346:	5d                   	pop    ebp
  4c4347:	c3                   	ret
  4c4348:	cc                   	int3
  4c4349:	cc                   	int3
  4c434a:	cc                   	int3
  4c434b:	cc                   	int3
  4c434c:	cc                   	int3
  4c434d:	cc                   	int3
  4c434e:	cc                   	int3
  4c434f:	cc                   	int3
  4c4350:	8b 46 40             	mov    eax,DWORD PTR [esi+0x40]
  4c4353:	85 c0                	test   eax,eax
  4c4355:	74 09                	je     0x4c4360
  4c4357:	50                   	push   eax
  4c4358:	e8 af ce 3c 00       	call   0x89120c
  4c435d:	83 c4 04             	add    esp,0x4
  4c4360:	c7 46 40 00 00 00 00 	mov    DWORD PTR [esi+0x40],0x0
  4c4367:	c7 46 44 00 00 00 00 	mov    DWORD PTR [esi+0x44],0x0
  4c436e:	c7 46 48 00 00 00 00 	mov    DWORD PTR [esi+0x48],0x0
  4c4375:	c3                   	ret
  4c4376:	cc                   	int3
  4c4377:	cc                   	int3
  4c4378:	cc                   	int3
  4c4379:	cc                   	int3
  4c437a:	cc                   	int3
  4c437b:	cc                   	int3
  4c437c:	cc                   	int3
  4c437d:	cc                   	int3
  4c437e:	cc                   	int3
  4c437f:	cc                   	int3
  4c4380:	55                   	push   ebp
  4c4381:	8b ec                	mov    ebp,esp
  4c4383:	56                   	push   esi
  4c4384:	8b f1                	mov    esi,ecx
  4c4386:	56                   	push   esi
  4c4387:	c7 06 74 73 c0 00    	mov    DWORD PTR [esi],0xc07374
  4c438d:	e8 ae 62 ff ff       	call   0x4ba640
  4c4392:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4c4396:	74 09                	je     0x4c43a1
  4c4398:	56                   	push   esi
  4c4399:	e8 6e ce 3c 00       	call   0x89120c
  4c439e:	83 c4 04             	add    esp,0x4
  4c43a1:	8b c6                	mov    eax,esi
  4c43a3:	5e                   	pop    esi
  4c43a4:	5d                   	pop    ebp
  4c43a5:	c2 04 00             	ret    0x4
  4c43a8:	cc                   	int3
  4c43a9:	cc                   	int3
  4c43aa:	cc                   	int3
  4c43ab:	cc                   	int3
  4c43ac:	cc                   	int3
  4c43ad:	cc                   	int3
  4c43ae:	cc                   	int3
  4c43af:	cc                   	int3
  4c43b0:	55                   	push   ebp
  4c43b1:	8b ec                	mov    ebp,esp
  4c43b3:	6a                   	.byte 0x6a
```


## E44.6 — FE1B54 表的實際建構、嵌套插入與 0x60-byte 記錄

**具體問題**：`0x4C3080` 寫入的表與 E43 UI 使用的 `FE1B54` 是否同一物件？vector 元素結構與生命週期是什麼？

**BIN 原生結論／範圍**：`0x506AD0` 在建構整體列表環境時配置 `0x20` bytes，呼叫 `0x5073E0`；其 `0x50740B` **把傳入的物件存入全域 `[FE1B54]`**、以 vptr C0DCE4/C0DCEC 初始化並在 `+8` 建立嵌入容器。`0x4C3080` 的 `0x4C30B6` 再讀相同 `[FE1B54]`，呼叫 `0x507510` 將 group_id 解析/選擇 group handle；`0x4C3124` 再把相同 `[FE1B54]` 當第1 stack 參數傳入 `0x507610`。其後 `0x507610→0x507B10` 在群組內 `vector` 的 `[start,end,cap]` 上以 `0x60` bytes 步幅追加／複製 (`0x507b64 movs DWORD*0x18`、`0x507b6b end +=0x60`)。因此新找到的真實正向資料 writer 與 E43 使用的 selected record resolver 在**同一實例全域**相接。

**尚缺與反證**：不能單從向量步幅定義 record 各業務欄位；初始化失敗、重建、destructor `0x5074EE` 清 FE1B54、`0x507AF6/507C90` 其他清零路徑均可能使指標無效。沒有動態執行保證 UI 讀取在填完後。

### BIN 指令：上層環境配置 FE1B54 object（`0x506AD0–0x506B91`）

```asm
  506ad0:	55                   	push   ebp
  506ad1:	8b ec                	mov    ebp,esp
  506ad3:	6a ff                	push   0xffffffff
  506ad5:	68 68 99 92 00       	push   0x929968
  506ada:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  506ae0:	50                   	push   eax
  506ae1:	51                   	push   ecx
  506ae2:	53                   	push   ebx
  506ae3:	56                   	push   esi
  506ae4:	57                   	push   edi
  506ae5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  506aea:	33 c5                	xor    eax,ebp
  506aec:	50                   	push   eax
  506aed:	8d 45 f4             	lea    eax,[ebp-0xc]
  506af0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  506af6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  506af9:	33 db                	xor    ebx,ebx
  506afb:	89 1e                	mov    DWORD PTR [esi],ebx
  506afd:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  506b00:	89 5e 08             	mov    DWORD PTR [esi+0x8],ebx
  506b03:	8d 7e 10             	lea    edi,[esi+0x10]
  506b06:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  506b09:	89 1f                	mov    DWORD PTR [edi],ebx
  506b0b:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  506b0e:	89 5f 08             	mov    DWORD PTR [edi+0x8],ebx
  506b11:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  506b15:	6a 38                	push   0x38
  506b17:	89 5e 20             	mov    DWORD PTR [esi+0x20],ebx
  506b1a:	89 5e 24             	mov    DWORD PTR [esi+0x24],ebx
  506b1d:	e8 46 a7 38 00       	call   0x891268
  506b22:	83 c4 04             	add    esp,0x4
  506b25:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  506b28:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  506b2c:	3b c3                	cmp    eax,ebx
  506b2e:	74 08                	je     0x506b38
  506b30:	50                   	push   eax
  506b31:	e8 7a da 01 00       	call   0x5245b0
  506b36:	eb 02                	jmp    0x506b3a
  506b38:	33 c0                	xor    eax,eax
  506b3a:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  506b3e:	3b c3                	cmp    eax,ebx
  506b40:	74 08                	je     0x506b4a
  506b42:	83 c0 04             	add    eax,0x4
  506b45:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  506b48:	eb 03                	jmp    0x506b4d
  506b4a:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  506b4d:	8d 45 f0             	lea    eax,[ebp-0x10]
  506b50:	e8 bb d1 f3 ff       	call   0x443d10
  506b55:	6a 20                	push   0x20
  506b57:	e8 0c a7 38 00       	call   0x891268
  506b5c:	83 c4 04             	add    esp,0x4
  506b5f:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  506b62:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  506b66:	3b c3                	cmp    eax,ebx
  506b68:	74 08                	je     0x506b72
  506b6a:	50                   	push   eax
  506b6b:	e8 70 08 00 00       	call   0x5073e0
  506b70:	eb 02                	jmp    0x506b74
  506b72:	33 c0                	xor    eax,eax
  506b74:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  506b78:	3b c3                	cmp    eax,ebx
  506b7a:	74 08                	je     0x506b84
  506b7c:	83 c0 04             	add    eax,0x4
  506b7f:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  506b82:	eb 03                	jmp    0x506b87
  506b84:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  506b87:	8d 45 f0             	lea    eax,[ebp-0x10]
  506b8a:	8b fe                	mov    edi,esi
  506b8c:	e8 7f d1 f3 ff       	call   0x443d10
```

### BIN 指令：全域 FE1B54 寫入與初始化（`0x5073E0–0x507480`）

```asm
  5073e0:	55                   	push   ebp
  5073e1:	8b ec                	mov    ebp,esp
  5073e3:	6a ff                	push   0xffffffff
  5073e5:	68 e3 64 90 00       	push   0x9064e3
  5073ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5073f0:	50                   	push   eax
  5073f1:	83 ec 10             	sub    esp,0x10
  5073f4:	53                   	push   ebx
  5073f5:	56                   	push   esi
  5073f6:	57                   	push   edi
  5073f7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5073fc:	33 c5                	xor    eax,ebp
  5073fe:	50                   	push   eax
  5073ff:	8d 45 f4             	lea    eax,[ebp-0xc]
  507402:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  507408:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  50740b:	89 3d 54 1b fe 00    	mov    DWORD PTR ds:0xfe1b54,edi
  507411:	33 db                	xor    ebx,ebx
  507413:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  507416:	c7 47 04 40 6d bf 00 	mov    DWORD PTR [edi+0x4],0xbf6d40
  50741d:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  507421:	c7 07 e4 dc c0 00    	mov    DWORD PTR [edi],0xc0dce4
  507427:	c7 47 04 ec dc c0 00 	mov    DWORD PTR [edi+0x4],0xc0dcec
  50742e:	8d 77 08             	lea    esi,[edi+0x8]
  507431:	6a 08                	push   0x8
  507433:	89 1e                	mov    DWORD PTR [esi],ebx
  507435:	e8 2e 9e 38 00       	call   0x891268
  50743a:	83 c4 04             	add    esp,0x4
  50743d:	3b c3                	cmp    eax,ebx
  50743f:	74 3f                	je     0x507480
  507441:	89 06                	mov    DWORD PTR [esi],eax
  507443:	33 c9                	xor    ecx,ecx
  507445:	89 08                	mov    DWORD PTR [eax],ecx
  507447:	33 d2                	xor    edx,edx
  507449:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50744c:	8b 06                	mov    eax,DWORD PTR [esi]
  50744e:	89 30                	mov    DWORD PTR [eax],esi
  507450:	53                   	push   ebx
  507451:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  507454:	89 5e 08             	mov    DWORD PTR [esi+0x8],ebx
  507457:	89 5e 0c             	mov    DWORD PTR [esi+0xc],ebx
  50745a:	89 5e 10             	mov    DWORD PTR [esi+0x10],ebx
  50745d:	e8 d3 ed 38 00       	call   0x896235
  507462:	a3 a8 a7 fb 00       	mov    ds:0xfba7a8,eax
  507467:	83 c4 04             	add    esp,0x4
  50746a:	8b c7                	mov    eax,edi
  50746c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  50746f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  507476:	59                   	pop    ecx
  507477:	5f                   	pop    edi
  507478:	5e                   	pop    esi
  507479:	5b                   	pop    ebx
  50747a:	8b e5                	mov    esp,ebp
  50747c:	5d                   	pop    ebp
  50747d:	c2 04 00             	ret    0x4
```

### BIN 指令：nested group record allocator（`0x507510–0x507601`）

```asm
  507510:	55                   	push   ebp
  507511:	8b ec                	mov    ebp,esp
  507513:	6a ff                	push   0xffffffff
  507515:	68 76 73 91 00       	push   0x917376
  50751a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  507520:	50                   	push   eax
  507521:	83 ec 5c             	sub    esp,0x5c
  507524:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  507529:	33 c5                	xor    eax,ebp
  50752b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  50752e:	53                   	push   ebx
  50752f:	56                   	push   esi
  507530:	57                   	push   edi
  507531:	50                   	push   eax
  507532:	8d 45 f4             	lea    eax,[ebp-0xc]
  507535:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50753b:	8b f9                	mov    edi,ecx
  50753d:	33 db                	xor    ebx,ebx
  50753f:	8b f2                	mov    esi,edx
  507541:	89 5d e0             	mov    DWORD PTR [ebp-0x20],ebx
  507544:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  507547:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  50754a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  50754d:	b8 01 00 00 00       	mov    eax,0x1
  507552:	89 7d a0             	mov    DWORD PTR [ebp-0x60],edi
  507555:	84 05 30 1b fe 00    	test   BYTE PTR ds:0xfe1b30,al
  50755b:	75 1e                	jne    0x50757b
  50755d:	09 05 30 1b fe 00    	or     DWORD PTR ds:0xfe1b30,eax
  507563:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  507566:	e8 85 85 f7 ff       	call   0x47faf0
  50756b:	68 b0 ea bc 00       	push   0xbceab0
  507570:	e8 a5 ad 38 00       	call   0x89231a
  507575:	83 c4 04             	add    esp,0x4
  507578:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  50757b:	0f b7 c7             	movzx  eax,di
  50757e:	8d 4d 98             	lea    ecx,[ebp-0x68]
  507581:	89 45 98             	mov    DWORD PTR [ebp-0x68],eax
  507584:	51                   	push   ecx
  507585:	8d 45 9c             	lea    eax,[ebp-0x64]
  507588:	b9 34 1b fe 00       	mov    ecx,0xfe1b34
  50758d:	e8 1e c7 ff ff       	call   0x503cb0
  507592:	8b 45 9c             	mov    eax,DWORD PTR [ebp-0x64]
  507595:	3b 05 38 1b fe 00    	cmp    eax,DWORD PTR ds:0xfe1b38
  50759b:	74 0d                	je     0x5075aa
  50759d:	83 c0 10             	add    eax,0x10
  5075a0:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  5075a4:	72 0e                	jb     0x5075b4
  5075a6:	8b 00                	mov    eax,DWORD PTR [eax]
  5075a8:	eb 0a                	jmp    0x5075b4
  5075aa:	0f b7 d7             	movzx  edx,di
  5075ad:	8b 04 95 04 a1 d6 00 	mov    eax,DWORD PTR [edx*4+0xd6a104]
  5075b4:	50                   	push   eax
  5075b5:	8d 45 a4             	lea    eax,[ebp-0x5c]
  5075b8:	6a 1e                	push   0x1e
  5075ba:	50                   	push   eax
  5075bb:	e8 8d b8 38 00       	call   0x892e4d
  5075c0:	8b 7e 18             	mov    edi,DWORD PTR [esi+0x18]
  5075c3:	83 c4 0c             	add    esp,0xc
  5075c6:	8d 4d a0             	lea    ecx,[ebp-0x60]
  5075c9:	51                   	push   ecx
  5075ca:	83 c6 08             	add    esi,0x8
  5075cd:	56                   	push   esi
  5075ce:	e8 cd 05 00 00       	call   0x507ba0
  5075d3:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  5075d6:	3b c3                	cmp    eax,ebx
  5075d8:	74 09                	je     0x5075e3
  5075da:	50                   	push   eax
  5075db:	e8 2c 9c 38 00       	call   0x89120c
  5075e0:	83 c4 04             	add    esp,0x4
  5075e3:	8b c7                	mov    eax,edi
  5075e5:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5075e8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5075ef:	59                   	pop    ecx
  5075f0:	5f                   	pop    edi
  5075f1:	5e                   	pop    esi
  5075f2:	5b                   	pop    ebx
  5075f3:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  5075f6:	33 cd                	xor    ecx,ebp
  5075f8:	e8 04 9a 38 00       	call   0x891001
  5075fd:	8b e5                	mov    esp,ebp
  5075ff:	5d                   	pop    ebp
  507600:	c3                   	ret
```

### BIN 指令：十位元輸入→record 附加（`0x507610–0x507741`）

```asm
  507610:	55                   	push   ebp
  507611:	8b ec                	mov    ebp,esp
  507613:	6a ff                	push   0xffffffff
  507615:	68 2e 73 91 00       	push   0x91732e
  50761a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  507620:	50                   	push   eax
  507621:	81 ec 84 00 00 00    	sub    esp,0x84
  507627:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50762c:	33 c5                	xor    eax,ebp
  50762e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  507631:	53                   	push   ebx
  507632:	56                   	push   esi
  507633:	57                   	push   edi
  507634:	50                   	push   eax
  507635:	8d 45 f4             	lea    eax,[ebp-0xc]
  507638:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50763e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  507641:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  507644:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  507647:	8b 75 0c             	mov    esi,DWORD PTR [ebp+0xc]
  50764a:	50                   	push   eax
  50764b:	8d 45 9c             	lea    eax,[ebp-0x64]
  50764e:	6a 14                	push   0x14
  507650:	50                   	push   eax
  507651:	89 7d 90             	mov    DWORD PTR [ebp-0x70],edi
  507654:	89 4d 94             	mov    DWORD PTR [ebp-0x6c],ecx
  507657:	89 55 98             	mov    DWORD PTR [ebp-0x68],edx
  50765a:	e8 fa c4 38 00       	call   0x893b59
  50765f:	b8 01 00 00 00       	mov    eax,0x1
  507664:	83 c4 0c             	add    esp,0xc
  507667:	84 05 30 1b fe 00    	test   BYTE PTR ds:0xfe1b30,al
  50766d:	75 26                	jne    0x507695
  50766f:	09 05 30 1b fe 00    	or     DWORD PTR ds:0xfe1b30,eax
  507675:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  50767c:	e8 6f 84 f7 ff       	call   0x47faf0
  507681:	68 b0 ea bc 00       	push   0xbceab0
  507686:	e8 8f ac 38 00       	call   0x89231a
  50768b:	83 c4 04             	add    esp,0x4
  50768e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  507695:	0f b7 ce             	movzx  ecx,si
  507698:	0f b7 ff             	movzx  edi,di
  50769b:	c1 e1 10             	shl    ecx,0x10
  50769e:	0b cf                	or     ecx,edi
  5076a0:	8d 55 88             	lea    edx,[ebp-0x78]
  5076a3:	89 4d 88             	mov    DWORD PTR [ebp-0x78],ecx
  5076a6:	52                   	push   edx
  5076a7:	8d 45 8c             	lea    eax,[ebp-0x74]
  5076aa:	b9 44 1b fe 00       	mov    ecx,0xfe1b44
  5076af:	e8 3c 87 f7 ff       	call   0x47fdf0
  5076b4:	8b 45 8c             	mov    eax,DWORD PTR [ebp-0x74]
  5076b7:	3b 05 48 1b fe 00    	cmp    eax,DWORD PTR ds:0xfe1b48
  5076bd:	74 0d                	je     0x5076cc
  5076bf:	83 c0 10             	add    eax,0x10
  5076c2:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  5076c6:	72 0b                	jb     0x5076d3
  5076c8:	8b 00                	mov    eax,DWORD PTR [eax]
  5076ca:	eb 07                	jmp    0x5076d3
  5076cc:	8b 04 bd 2c a1 d6 00 	mov    eax,DWORD PTR [edi*4+0xd6a12c]
  5076d3:	6a ff                	push   0xffffffff
  5076d5:	50                   	push   eax
  5076d6:	8d 45 b0             	lea    eax,[ebp-0x50]
  5076d9:	6a 1e                	push   0x1e
  5076db:	50                   	push   eax
  5076dc:	e8 1d c9 38 00       	call   0x893ffe
  5076e1:	83 c4 10             	add    esp,0x10
  5076e4:	56                   	push   esi
  5076e5:	8d 4b 08             	lea    ecx,[ebx+0x8]
  5076e8:	8d 85 7c ff ff ff    	lea    eax,[ebp-0x84]
  5076ee:	e8 1d ab 03 00       	call   0x542210
  5076f3:	8b f0                	mov    esi,eax
  5076f5:	8d 85 70 ff ff ff    	lea    eax,[ebp-0x90]
  5076fb:	e8 b0 3d 00 00       	call   0x50b4b0
  507700:	8b 08                	mov    ecx,DWORD PTR [eax]
  507702:	85 c9                	test   ecx,ecx
  507704:	74 02                	je     0x507708
  507706:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507708:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  50770b:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  50770e:	3b d0                	cmp    edx,eax
  507710:	77 02                	ja     0x507714
  507712:	2b c2                	sub    eax,edx
  507714:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507717:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  50771a:	83 c2 40             	add    edx,0x40
  50771d:	52                   	push   edx
  50771e:	8d 45 90             	lea    eax,[ebp-0x70]
  507721:	e8 ea 03 00 00       	call   0x507b10
  507726:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  507729:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  507730:	59                   	pop    ecx
  507731:	5f                   	pop    edi
  507732:	5e                   	pop    esi
  507733:	5b                   	pop    ebx
  507734:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  507737:	33 cd                	xor    ecx,ebp
  507739:	e8 c3 98 38 00       	call   0x891001
  50773e:	8b e5                	mov    esp,ebp
  507740:	5d                   	pop    ebp
```

### BIN 指令：每筆 0x60 bytes vector append（`0x507B10–0x507B74`）

```asm
  507b10:	55                   	push   ebp
  507b11:	8b ec                	mov    ebp,esp
  507b13:	53                   	push   ebx
  507b14:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  507b17:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  507b1a:	56                   	push   esi
  507b1b:	8b f0                	mov    esi,eax
  507b1d:	57                   	push   edi
  507b1e:	3b f1                	cmp    esi,ecx
  507b20:	73 2f                	jae    0x507b51
  507b22:	8b 03                	mov    eax,DWORD PTR [ebx]
  507b24:	3b c6                	cmp    eax,esi
  507b26:	77 29                	ja     0x507b51
  507b28:	2b f0                	sub    esi,eax
  507b2a:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  507b2f:	f7 ee                	imul   esi
  507b31:	c1 fa 04             	sar    edx,0x4
  507b34:	8b f2                	mov    esi,edx
  507b36:	c1 ee 1f             	shr    esi,0x1f
  507b39:	03 f2                	add    esi,edx
  507b3b:	3b 4b 08             	cmp    ecx,DWORD PTR [ebx+0x8]
  507b3e:	75 07                	jne    0x507b47
  507b40:	8b cb                	mov    ecx,ebx
  507b42:	e8 69 01 00 00       	call   0x507cb0
  507b47:	8d 34 76             	lea    esi,[esi+esi*2]
  507b4a:	c1 e6 05             	shl    esi,0x5
  507b4d:	03 33                	add    esi,DWORD PTR [ebx]
  507b4f:	eb 0c                	jmp    0x507b5d
  507b51:	3b 4b 08             	cmp    ecx,DWORD PTR [ebx+0x8]
  507b54:	75 07                	jne    0x507b5d
  507b56:	8b cb                	mov    ecx,ebx
  507b58:	e8 53 01 00 00       	call   0x507cb0
  507b5d:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  507b60:	85 ff                	test   edi,edi
  507b62:	74 07                	je     0x507b6b
  507b64:	b9 18 00 00 00       	mov    ecx,0x18
  507b69:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  507b6b:	83 43 04 60          	add    DWORD PTR [ebx+0x4],0x60
  507b6f:	5f                   	pop    edi
  507b70:	5e                   	pop    esi
  507b71:	5b                   	pop    ebx
  507b72:	5d                   	pop    ebp
  507b73:	c2                   	.byte 0xc2
```

### BIN 指令：析構清全域（`0x5074B0–0x507509`）

```asm
  5074b0:	55                   	push   ebp
  5074b1:	8b ec                	mov    ebp,esp
  5074b3:	56                   	push   esi
  5074b4:	57                   	push   edi
  5074b5:	8b f9                	mov    edi,ecx
  5074b7:	8d 77 08             	lea    esi,[edi+0x8]
  5074ba:	c7 07 e4 dc c0 00    	mov    DWORD PTR [edi],0xc0dce4
  5074c0:	c7 47 04 ec dc c0 00 	mov    DWORD PTR [edi+0x4],0xc0dcec
  5074c7:	e8 74 cd fb ff       	call   0x4c4240
  5074cc:	8b 06                	mov    eax,DWORD PTR [esi]
  5074ce:	50                   	push   eax
  5074cf:	e8 38 9d 38 00       	call   0x89120c
  5074d4:	83 c4 04             	add    esp,0x4
  5074d7:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  5074db:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  5074e1:	c7 47 04 40 6d bf 00 	mov    DWORD PTR [edi+0x4],0xbf6d40
  5074e8:	c7 07 fc dc c0 00    	mov    DWORD PTR [edi],0xc0dcfc
  5074ee:	c7 05 54 1b fe 00 00 	mov    DWORD PTR ds:0xfe1b54,0x0
  5074f5:	00 00 00 
  5074f8:	74 09                	je     0x507503
  5074fa:	57                   	push   edi
  5074fb:	e8 0c 9d 38 00       	call   0x89120c
  507500:	83 c4 04             	add    esp,0x4
  507503:	8b c7                	mov    eax,edi
  507505:	5f                   	pop    edi
  507506:	5e                   	pop    esi
  507507:	5d                   	pop    ebp
  507508:	c2                   	.byte 0xc2
```


## E44.7 — 資料 table 真正消費者：UI 列表、選擇事件、兩級 key

**具體問題**：FE1B54 的 writer 與玩家 UI 何處有讀取連結？本地 0x709/0x70A/0x578 如何區分？

**BIN 原生結論／範圍**：`0x66B910` 明確 `[FE1B54]+8` 作列表來源傳 `0x66C720`，接著遍歷 UI `+0xFC/+0x100` records、以 `0x66C830` 建立/更新控件。`0x66C620` 的本地事件比對 `0x709`、`0x70A`、`0x578`，其中 `0x70A` 在事件 item 身分符合 `[ESI+0xF4]->+0x20` 時，先清三個 UI 控件，再將選擇上下文內的 `+0x20` 設為 ECX 呼叫 `0x66C090`；`0x578` 同樣先清控件，以 `ECX=0` 呼叫 `0x66C090`。`0x66C090` 從 `[UI+F0/F4] → CC → DC → +20` 取得兩個 key，缺失回 `-1`，在 FE1B54 上呼叫 `5078C0/507750`。這形成真正的 `S2C 0x13 → FE1B54 record → UI lists → selection action` 主體。

**尚缺與反證**：`0x709/0x70A/0x578` 是本地 event/code，不是收到的 S2C WORD 0x0013 或 0x007A；畫面實際顯示、玩家何時選完、行為順序仍無 runtime trace。表格中控件 +0x20 是 UI identity/selection key，不能與 Conn+A080 lane 混同。

**玩家場景**：收到列表資料後可能建立兩層選項；選取某項滿足 item identity 才進 resolver/Connect。不能宣稱網路登入成功必然直接開選服視窗。

### BIN 指令：列表 UI 查全域容器及 populate（`0x66B910–0x66BA05`）

```asm
  66b910:	55                   	push   ebp
  66b911:	8b ec                	mov    ebp,esp
  66b913:	83 e4 f8             	and    esp,0xfffffff8
  66b916:	6a ff                	push   0xffffffff
  66b918:	68 a8 cf 93 00       	push   0x93cfa8
  66b91d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  66b923:	50                   	push   eax
  66b924:	83 ec 38             	sub    esp,0x38
  66b927:	53                   	push   ebx
  66b928:	56                   	push   esi
  66b929:	57                   	push   edi
  66b92a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  66b92f:	33 c4                	xor    eax,esp
  66b931:	50                   	push   eax
  66b932:	8d 44 24 48          	lea    eax,[esp+0x48]
  66b936:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  66b93c:	a1 54 1b fe 00       	mov    eax,ds:0xfe1b54
  66b941:	83 c0 08             	add    eax,0x8
  66b944:	50                   	push   eax
  66b945:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  66b949:	51                   	push   ecx
  66b94a:	e8 d1 0d 00 00       	call   0x66c720
  66b94f:	8d 44 24 20          	lea    eax,[esp+0x20]
  66b953:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  66b957:	c7 44 24 50 00 00 00 	mov    DWORD PTR [esp+0x50],0x0
  66b95e:	00 
  66b95f:	e8 fc ca e6 ff       	call   0x4d8460
  66b964:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  66b967:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  66b96d:	8b 87 fc 00 00 00    	mov    eax,DWORD PTR [edi+0xfc]
  66b973:	81 c7 fc 00 00 00    	add    edi,0xfc
  66b979:	3b c1                	cmp    eax,ecx
  66b97b:	74 1e                	je     0x66b99b
  66b97d:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  66b981:	52                   	push   edx
  66b982:	51                   	push   ecx
  66b983:	e8 b8 1a 00 00       	call   0x66d440
  66b988:	8b f0                	mov    esi,eax
  66b98a:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  66b98d:	50                   	push   eax
  66b98e:	8b c6                	mov    eax,esi
  66b990:	e8 6b e6 f3 ff       	call   0x5aa000
  66b995:	83 c4 0c             	add    esp,0xc
  66b998:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  66b99b:	8d 44 24 14          	lea    eax,[esp+0x14]
  66b99f:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  66b9a3:	e8 68 68 ed ff       	call   0x542210
  66b9a8:	8b 74 24 1c          	mov    esi,DWORD PTR [esp+0x1c]
  66b9ac:	8b 5c 24 28          	mov    ebx,DWORD PTR [esp+0x28]
  66b9b0:	3b f3                	cmp    esi,ebx
  66b9b2:	74 2b                	je     0x66b9df
  66b9b4:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  66b9b8:	85 c0                	test   eax,eax
  66b9ba:	75 04                	jne    0x66b9c0
  66b9bc:	33 c9                	xor    ecx,ecx
  66b9be:	eb 02                	jmp    0x66b9c2
  66b9c0:	8b 08                	mov    ecx,DWORD PTR [eax]
  66b9c2:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  66b9c5:	8b c6                	mov    eax,esi
  66b9c7:	3b d6                	cmp    edx,esi
  66b9c9:	77 02                	ja     0x66b9cd
  66b9cb:	2b c2                	sub    eax,edx
  66b9cd:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  66b9d0:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  66b9d3:	52                   	push   edx
  66b9d4:	57                   	push   edi
  66b9d5:	e8 56 0e 00 00       	call   0x66c830
  66b9da:	46                   	inc    esi
  66b9db:	3b f3                	cmp    esi,ebx
  66b9dd:	75 d5                	jne    0x66b9b4
  66b9df:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  66b9e2:	56                   	push   esi
  66b9e3:	e8 38 00 00 00       	call   0x66ba20
  66b9e8:	56                   	push   esi
  66b9e9:	e8 e2 01 00 00       	call   0x66bbd0
  66b9ee:	8d 74 24 2c          	lea    esi,[esp+0x2c]
  66b9f2:	e8 49 88 e5 ff       	call   0x4c4240
  66b9f7:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  66b9fb:	50                   	push   eax
  66b9fc:	e8 0b 58 22 00       	call   0x89120c
  66ba01:	83 c4 04             	add    esp,0x4
  66ba04:	8b                   	.byte 0x8b
```

### BIN 指令：UI event 0x709/0x70A/0x578 各分支（`0x66C620–0x66C71B`）

```asm
  66c620:	55                   	push   ebp
  66c621:	8b ec                	mov    ebp,esp
  66c623:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c626:	56                   	push   esi
  66c627:	8b f1                	mov    esi,ecx
  66c629:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  66c62c:	81 f9 09 07 00 00    	cmp    ecx,0x709
  66c632:	75 33                	jne    0x66c667
  66c634:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  66c637:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c63d:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  66c640:	75 0b                	jne    0x66c64d
  66c642:	56                   	push   esi
  66c643:	e8 88 f5 ff ff       	call   0x66bbd0
  66c648:	5e                   	pop    esi
  66c649:	5d                   	pop    ebp
  66c64a:	c2 04 00             	ret    0x4
  66c64d:	8b 96 f4 00 00 00    	mov    edx,DWORD PTR [esi+0xf4]
  66c653:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66c656:	0f 85 bc 00 00 00    	jne    0x66c718
  66c65c:	56                   	push   esi
  66c65d:	e8 ae fe ff ff       	call   0x66c510
  66c662:	5e                   	pop    esi
  66c663:	5d                   	pop    ebp
  66c664:	c2 04 00             	ret    0x4
  66c667:	81 f9 0a 07 00 00    	cmp    ecx,0x70a
  66c66d:	75 55                	jne    0x66c6c4
  66c66f:	8b 8e f4 00 00 00    	mov    ecx,DWORD PTR [esi+0xf4]
  66c675:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  66c678:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  66c67b:	0f 85 97 00 00 00    	jne    0x66c718
  66c681:	57                   	push   edi
  66c682:	8b 78 18             	mov    edi,DWORD PTR [eax+0x18]
  66c685:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c687:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c68d:	6a 00                	push   0x0
  66c68f:	ff d2                	call   edx
  66c691:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c697:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c699:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c69f:	6a 00                	push   0x0
  66c6a1:	ff d2                	call   edx
  66c6a3:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c6a9:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6ab:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6b1:	6a 00                	push   0x0
  66c6b3:	ff d2                	call   edx
  66c6b5:	8b 4f 20             	mov    ecx,DWORD PTR [edi+0x20]
  66c6b8:	56                   	push   esi
  66c6b9:	e8 d2 f9 ff ff       	call   0x66c090
  66c6be:	5f                   	pop    edi
  66c6bf:	5e                   	pop    esi
  66c6c0:	5d                   	pop    ebp
  66c6c1:	c2 04 00             	ret    0x4
  66c6c4:	81 f9 78 05 00 00    	cmp    ecx,0x578
  66c6ca:	75 4c                	jne    0x66c718
  66c6cc:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c6d2:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  66c6d5:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  66c6d8:	75 3e                	jne    0x66c718
  66c6da:	8b 8e f4 00 00 00    	mov    ecx,DWORD PTR [esi+0xf4]
  66c6e0:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6e2:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6e8:	6a 00                	push   0x0
  66c6ea:	ff d2                	call   edx
  66c6ec:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c6f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6f4:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6fa:	6a 00                	push   0x0
  66c6fc:	ff d2                	call   edx
  66c6fe:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c704:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c706:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c70c:	6a 00                	push   0x0
  66c70e:	ff d2                	call   edx
  66c710:	56                   	push   esi
  66c711:	33 c9                	xor    ecx,ecx
  66c713:	e8 78 f9 ff ff       	call   0x66c090
  66c718:	5e                   	pop    esi
  66c719:	5d                   	pop    ebp
  66c71a:	c2                   	.byte 0xc2
```

### BIN 指令：UI selection 兩個 key / resolver（`0x66C090–0x66C14F`）

```asm
  66c090:	55                   	push   ebp
  66c091:	8b ec                	mov    ebp,esp
  66c093:	83 e4 f8             	and    esp,0xfffffff8
  66c096:	6a ff                	push   0xffffffff
  66c098:	68 7a 61 94 00       	push   0x94617a
  66c09d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  66c0a3:	50                   	push   eax
  66c0a4:	83 ec 10             	sub    esp,0x10
  66c0a7:	53                   	push   ebx
  66c0a8:	56                   	push   esi
  66c0a9:	57                   	push   edi
  66c0aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  66c0af:	33 c4                	xor    eax,esp
  66c0b1:	50                   	push   eax
  66c0b2:	8d 44 24 20          	lea    eax,[esp+0x20]
  66c0b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  66c0bc:	8b f9                	mov    edi,ecx
  66c0be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  66c0c1:	8b 81 f0 00 00 00    	mov    eax,DWORD PTR [ecx+0xf0]
  66c0c7:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c0cd:	85 c0                	test   eax,eax
  66c0cf:	74 1c                	je     0x66c0ed
  66c0d1:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c0d7:	85 c0                	test   eax,eax
  66c0d9:	75 09                	jne    0x66c0e4
  66c0db:	83 c8 ff             	or     eax,0xffffffff
  66c0de:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0e2:	eb 11                	jmp    0x66c0f5
  66c0e4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c0e7:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0eb:	eb 08                	jmp    0x66c0f5
  66c0ed:	c7 44 24 10 ff ff ff 	mov    DWORD PTR [esp+0x10],0xffffffff
  66c0f4:	ff 
  66c0f5:	85 ff                	test   edi,edi
  66c0f7:	75 2b                	jne    0x66c124
  66c0f9:	8b 81 f4 00 00 00    	mov    eax,DWORD PTR [ecx+0xf4]
  66c0ff:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c105:	85 c0                	test   eax,eax
  66c107:	74 18                	je     0x66c121
  66c109:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c10f:	85 c0                	test   eax,eax
  66c111:	75 07                	jne    0x66c11a
  66c113:	83 c8 ff             	or     eax,0xffffffff
  66c116:	8b f8                	mov    edi,eax
  66c118:	eb 0a                	jmp    0x66c124
  66c11a:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c11d:	8b f8                	mov    edi,eax
  66c11f:	eb 03                	jmp    0x66c124
  66c121:	83 cf ff             	or     edi,0xffffffff
  66c124:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
```


## E44.8 — 完整 record lookup → 主題 Connect，含 F94294 兩條 CFG

**具體問題**：有原生證據能把收到的表格記錄指標實際變成 socket Connect 的 endpoint 參數嗎？

**BIN 原生結論／範圍**：`5078C0`／`507750` 都對選取的兩個 key 先比對群組、再在每筆 `0x60` 記錄中匹配；前者返回 `[record+4]` 的 DWORD 到 EBX，後者返回 **`record+0xC` 地址**到 ESI。`0x66C17E` 以 `[F94294]!=0` 作首路 gate，且 `EBX!=0/ESI!=0` 時 `0x66C1A0 push ESI; 0x66C1A7 call 4957C0`；否則 `0x66C21D` alternate 以 EBX 不為4/0/5 且 ESI 非零也 `0x66C240 push ESI; 0x66C247 call 4957C0`。`0x4957C0` 在此呼叫上下文把 endpoint record+0xC 當參數，經 network manager vtable+0x18 分別提交 key0/port0x20E0/lane2 與 key2/port0x20DE/lane2，然後經雙 socket 成功條件調度 local outgoing payload。**這是本段從 native 0x0013 列表源一路經 UI to Connect 的重要全鏈增量。**

**尚缺與反證**：`F94294` 對已見原件只確認 `0x4E16BF` 的直接初始化為0；沒有一般非零 writer 的全集證明。`0x4957C0` 連接返回值只能證明 Connect 呼叫返回/本地 queue，並非 server 已接收、DNS/IP 的實際權威、兩連線 wire ordering。固定 port 不是建議部署配置。

### BIN 指令：查 record+0xC 指標（`0x507750–0x5078B7`）

```asm
  507750:	55                   	push   ebp
  507751:	8b ec                	mov    ebp,esp
  507753:	83 ec 24             	sub    esp,0x24
  507756:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  507759:	57                   	push   edi
  50775a:	33 c9                	xor    ecx,ecx
  50775c:	33 ff                	xor    edi,edi
  50775e:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  507761:	85 d2                	test   edx,edx
  507763:	0f 84 45 01 00 00    	je     0x5078ae
  507769:	53                   	push   ebx
  50776a:	8d 58 08             	lea    ebx,[eax+0x8]
  50776d:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  507770:	56                   	push   esi
  507771:	57                   	push   edi
  507772:	8d 45 e8             	lea    eax,[ebp-0x18]
  507775:	8b cb                	mov    ecx,ebx
  507777:	e8 94 aa 03 00       	call   0x542210
  50777c:	8b f0                	mov    esi,eax
  50777e:	8d 45 dc             	lea    eax,[ebp-0x24]
  507781:	e8 2a 3d 00 00       	call   0x50b4b0
  507786:	8b 08                	mov    ecx,DWORD PTR [eax]
  507788:	85 c9                	test   ecx,ecx
  50778a:	74 02                	je     0x50778e
  50778c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  50778e:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507791:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507794:	3b d0                	cmp    edx,eax
  507796:	77 02                	ja     0x50779a
  507798:	2b c2                	sub    eax,edx
  50779a:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  50779d:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  5077a0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5077a3:	39 02                	cmp    DWORD PTR [edx],eax
  5077a5:	74 11                	je     0x5077b8
  5077a7:	47                   	inc    edi
  5077a8:	3b 7d f4             	cmp    edi,DWORD PTR [ebp-0xc]
  5077ab:	72 c4                	jb     0x507771
  5077ad:	5e                   	pop    esi
  5077ae:	5b                   	pop    ebx
  5077af:	33 c0                	xor    eax,eax
  5077b1:	5f                   	pop    edi
  5077b2:	8b e5                	mov    esp,ebp
  5077b4:	5d                   	pop    ebp
  5077b5:	c2 08 00             	ret    0x8
  5077b8:	57                   	push   edi
  5077b9:	8d 45 dc             	lea    eax,[ebp-0x24]
  5077bc:	8b cb                	mov    ecx,ebx
  5077be:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5077c1:	e8 4a aa 03 00       	call   0x542210
  5077c6:	8b f0                	mov    esi,eax
  5077c8:	8d 45 e8             	lea    eax,[ebp-0x18]
  5077cb:	e8 e0 3c 00 00       	call   0x50b4b0
  5077d0:	8b 08                	mov    ecx,DWORD PTR [eax]
  5077d2:	85 c9                	test   ecx,ecx
  5077d4:	74 02                	je     0x5077d8
  5077d6:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5077d8:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5077db:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  5077de:	3b d0                	cmp    edx,eax
  5077e0:	77 02                	ja     0x5077e4
  5077e2:	2b c2                	sub    eax,edx
  5077e4:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  5077e7:	8b 04 81             	mov    eax,DWORD PTR [ecx+eax*4]
  5077ea:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  5077ed:	2b 48 40             	sub    ecx,DWORD PTR [eax+0x40]
  5077f0:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  5077f5:	f7 e9                	imul   ecx
  5077f7:	c1 fa 04             	sar    edx,0x4
  5077fa:	8b fa                	mov    edi,edx
  5077fc:	c1 ef 1f             	shr    edi,0x1f
  5077ff:	03 fa                	add    edi,edx
  507801:	bb 00 00 00 00       	mov    ebx,0x0
  507806:	74 a5                	je     0x5077ad
  507808:	89 5d 08             	mov    DWORD PTR [ebp+0x8],ebx
  50780b:	eb 03                	jmp    0x507810
  50780d:	8d 49 00             	lea    ecx,[ecx+0x0]
  507810:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  507813:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  507816:	52                   	push   edx
  507817:	8d 45 dc             	lea    eax,[ebp-0x24]
  50781a:	e8 f1 a9 03 00       	call   0x542210
  50781f:	8b f0                	mov    esi,eax
  507821:	8d 45 e8             	lea    eax,[ebp-0x18]
  507824:	e8 87 3c 00 00       	call   0x50b4b0
  507829:	8b 08                	mov    ecx,DWORD PTR [eax]
  50782b:	85 c9                	test   ecx,ecx
  50782d:	74 02                	je     0x507831
  50782f:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507831:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507834:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507837:	3b d0                	cmp    edx,eax
  507839:	77 02                	ja     0x50783d
  50783b:	2b c2                	sub    eax,edx
  50783d:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507840:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507843:	8b 42 40             	mov    eax,DWORD PTR [edx+0x40]
  507846:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  507849:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  50784c:	39 0c 02             	cmp    DWORD PTR [edx+eax*1],ecx
  50784f:	74 14                	je     0x507865
  507851:	83 45 08 60          	add    DWORD PTR [ebp+0x8],0x60
  507855:	43                   	inc    ebx
  507856:	3b df                	cmp    ebx,edi
  507858:	72 b6                	jb     0x507810
  50785a:	5e                   	pop    esi
  50785b:	5b                   	pop    ebx
  50785c:	33 c0                	xor    eax,eax
  50785e:	5f                   	pop    edi
  50785f:	8b e5                	mov    esp,ebp
  507861:	5d                   	pop    ebp
  507862:	c2 08 00             	ret    0x8
  507865:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  507868:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  50786b:	50                   	push   eax
  50786c:	8d 45 dc             	lea    eax,[ebp-0x24]
  50786f:	e8 9c a9 03 00       	call   0x542210
  507874:	8b f0                	mov    esi,eax
  507876:	8d 45 e8             	lea    eax,[ebp-0x18]
  507879:	e8 32 3c 00 00       	call   0x50b4b0
  50787e:	8b 08                	mov    ecx,DWORD PTR [eax]
  507880:	85 c9                	test   ecx,ecx
  507882:	74 02                	je     0x507886
  507884:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507886:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507889:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  50788c:	3b d0                	cmp    edx,eax
  50788e:	77 02                	ja     0x507892
  507890:	2b c2                	sub    eax,edx
  507892:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507895:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507898:	8b 4a 40             	mov    ecx,DWORD PTR [edx+0x40]
  50789b:	8d 04 5b             	lea    eax,[ebx+ebx*2]
  50789e:	5e                   	pop    esi
  50789f:	c1 e0 05             	shl    eax,0x5
  5078a2:	5b                   	pop    ebx
  5078a3:	8d 44 01 0c          	lea    eax,[ecx+eax*1+0xc]
  5078a7:	5f                   	pop    edi
  5078a8:	8b e5                	mov    esp,ebp
  5078aa:	5d                   	pop    ebp
  5078ab:	c2 08 00             	ret    0x8
  5078ae:	8b c1                	mov    eax,ecx
  5078b0:	5f                   	pop    edi
  5078b1:	8b e5                	mov    esp,ebp
  5078b3:	5d                   	pop    ebp
  5078b4:	c2 08 00             	ret    0x8
```

### BIN 指令：查 record+4 的欄位（`0x5078C0–0x507A27`）

```asm
  5078c0:	55                   	push   ebp
  5078c1:	8b ec                	mov    ebp,esp
  5078c3:	83 ec 24             	sub    esp,0x24
  5078c6:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  5078c9:	57                   	push   edi
  5078ca:	33 c9                	xor    ecx,ecx
  5078cc:	33 ff                	xor    edi,edi
  5078ce:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  5078d1:	85 d2                	test   edx,edx
  5078d3:	0f 84 45 01 00 00    	je     0x507a1e
  5078d9:	53                   	push   ebx
  5078da:	8d 58 08             	lea    ebx,[eax+0x8]
  5078dd:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  5078e0:	56                   	push   esi
  5078e1:	57                   	push   edi
  5078e2:	8d 45 e8             	lea    eax,[ebp-0x18]
  5078e5:	8b cb                	mov    ecx,ebx
  5078e7:	e8 24 a9 03 00       	call   0x542210
  5078ec:	8b f0                	mov    esi,eax
  5078ee:	8d 45 dc             	lea    eax,[ebp-0x24]
  5078f1:	e8 ba 3b 00 00       	call   0x50b4b0
  5078f6:	8b 08                	mov    ecx,DWORD PTR [eax]
  5078f8:	85 c9                	test   ecx,ecx
  5078fa:	74 02                	je     0x5078fe
  5078fc:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5078fe:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507901:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507904:	3b d0                	cmp    edx,eax
  507906:	77 02                	ja     0x50790a
  507908:	2b c2                	sub    eax,edx
  50790a:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  50790d:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507910:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  507913:	39 02                	cmp    DWORD PTR [edx],eax
  507915:	74 11                	je     0x507928
  507917:	47                   	inc    edi
  507918:	3b 7d f4             	cmp    edi,DWORD PTR [ebp-0xc]
  50791b:	72 c4                	jb     0x5078e1
  50791d:	5e                   	pop    esi
  50791e:	5b                   	pop    ebx
  50791f:	33 c0                	xor    eax,eax
  507921:	5f                   	pop    edi
  507922:	8b e5                	mov    esp,ebp
  507924:	5d                   	pop    ebp
  507925:	c2 08 00             	ret    0x8
  507928:	57                   	push   edi
  507929:	8d 45 dc             	lea    eax,[ebp-0x24]
  50792c:	8b cb                	mov    ecx,ebx
  50792e:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  507931:	e8 da a8 03 00       	call   0x542210
  507936:	8b f0                	mov    esi,eax
  507938:	8d 45 e8             	lea    eax,[ebp-0x18]
  50793b:	e8 70 3b 00 00       	call   0x50b4b0
  507940:	8b 08                	mov    ecx,DWORD PTR [eax]
  507942:	85 c9                	test   ecx,ecx
  507944:	74 02                	je     0x507948
  507946:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507948:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  50794b:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  50794e:	3b d0                	cmp    edx,eax
  507950:	77 02                	ja     0x507954
  507952:	2b c2                	sub    eax,edx
  507954:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507957:	8b 04 81             	mov    eax,DWORD PTR [ecx+eax*4]
  50795a:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  50795d:	2b 48 40             	sub    ecx,DWORD PTR [eax+0x40]
  507960:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  507965:	f7 e9                	imul   ecx
  507967:	c1 fa 04             	sar    edx,0x4
  50796a:	8b fa                	mov    edi,edx
  50796c:	c1 ef 1f             	shr    edi,0x1f
  50796f:	03 fa                	add    edi,edx
  507971:	bb 00 00 00 00       	mov    ebx,0x0
  507976:	74 a5                	je     0x50791d
  507978:	89 5d 08             	mov    DWORD PTR [ebp+0x8],ebx
  50797b:	eb 03                	jmp    0x507980
  50797d:	8d 49 00             	lea    ecx,[ecx+0x0]
  507980:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  507983:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  507986:	52                   	push   edx
  507987:	8d 45 dc             	lea    eax,[ebp-0x24]
  50798a:	e8 81 a8 03 00       	call   0x542210
  50798f:	8b f0                	mov    esi,eax
  507991:	8d 45 e8             	lea    eax,[ebp-0x18]
  507994:	e8 17 3b 00 00       	call   0x50b4b0
  507999:	8b 08                	mov    ecx,DWORD PTR [eax]
  50799b:	85 c9                	test   ecx,ecx
  50799d:	74 02                	je     0x5079a1
  50799f:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5079a1:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5079a4:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  5079a7:	3b d0                	cmp    edx,eax
  5079a9:	77 02                	ja     0x5079ad
  5079ab:	2b c2                	sub    eax,edx
  5079ad:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  5079b0:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  5079b3:	8b 42 40             	mov    eax,DWORD PTR [edx+0x40]
  5079b6:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5079b9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5079bc:	39 0c 02             	cmp    DWORD PTR [edx+eax*1],ecx
  5079bf:	74 14                	je     0x5079d5
  5079c1:	83 45 08 60          	add    DWORD PTR [ebp+0x8],0x60
  5079c5:	43                   	inc    ebx
  5079c6:	3b df                	cmp    ebx,edi
  5079c8:	72 b6                	jb     0x507980
  5079ca:	5e                   	pop    esi
  5079cb:	5b                   	pop    ebx
  5079cc:	33 c0                	xor    eax,eax
  5079ce:	5f                   	pop    edi
  5079cf:	8b e5                	mov    esp,ebp
  5079d1:	5d                   	pop    ebp
  5079d2:	c2 08 00             	ret    0x8
  5079d5:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  5079d8:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  5079db:	50                   	push   eax
  5079dc:	8d 45 dc             	lea    eax,[ebp-0x24]
  5079df:	e8 2c a8 03 00       	call   0x542210
  5079e4:	8b f0                	mov    esi,eax
  5079e6:	8d 45 e8             	lea    eax,[ebp-0x18]
  5079e9:	e8 c2 3a 00 00       	call   0x50b4b0
  5079ee:	8b 08                	mov    ecx,DWORD PTR [eax]
  5079f0:	85 c9                	test   ecx,ecx
  5079f2:	74 02                	je     0x5079f6
  5079f4:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5079f6:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5079f9:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  5079fc:	3b d0                	cmp    edx,eax
  5079fe:	77 02                	ja     0x507a02
  507a00:	2b c2                	sub    eax,edx
  507a02:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507a05:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507a08:	8b 4a 40             	mov    ecx,DWORD PTR [edx+0x40]
  507a0b:	8d 04 5b             	lea    eax,[ebx+ebx*2]
  507a0e:	5e                   	pop    esi
  507a0f:	c1 e0 05             	shl    eax,0x5
  507a12:	8b 44 01 04          	mov    eax,DWORD PTR [ecx+eax*1+0x4]
  507a16:	5b                   	pop    ebx
  507a17:	5f                   	pop    edi
  507a18:	8b e5                	mov    esp,ebp
  507a1a:	5d                   	pop    ebp
  507a1b:	c2 08 00             	ret    0x8
  507a1e:	8b c1                	mov    eax,ecx
  507a20:	5f                   	pop    edi
  507a21:	8b e5                	mov    esp,ebp
  507a23:	5d                   	pop    ebp
  507a24:	c2 08 00             	ret    0x8
```

### BIN 指令：UI 並行 gate 與 Connect 正常返回（`0x66C17B–0x66C273`）

```asm
  66c17b:	83 cf ff             	or     edi,0xffffffff
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
  66c1ac:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  66c1af:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  66c1b5:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c1bb:	85 c0                	test   eax,eax
  66c1bd:	74 43                	je     0x66c202
  66c1bf:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c1c5:	85 c0                	test   eax,eax
  66c1c7:	75 1c                	jne    0x66c1e5
  66c1c9:	8b c7                	mov    eax,edi
  66c1cb:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c1d0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c1d4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c1db:	59                   	pop    ecx
  66c1dc:	5f                   	pop    edi
  66c1dd:	5e                   	pop    esi
  66c1de:	5b                   	pop    ebx
  66c1df:	8b e5                	mov    esp,ebp
  66c1e1:	5d                   	pop    ebp
  66c1e2:	c2 04 00             	ret    0x4
  66c1e5:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c1e8:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c1ed:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c1f1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c1f8:	59                   	pop    ecx
  66c1f9:	5f                   	pop    edi
  66c1fa:	5e                   	pop    esi
  66c1fb:	5b                   	pop    ebx
  66c1fc:	8b e5                	mov    esp,ebp
  66c1fe:	5d                   	pop    ebp
  66c1ff:	c2 04 00             	ret    0x4
  66c202:	89 3d cc 3d d6 00    	mov    DWORD PTR ds:0xd63dcc,edi
  66c208:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c20c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c213:	59                   	pop    ecx
  66c214:	5f                   	pop    edi
  66c215:	5e                   	pop    esi
  66c216:	5b                   	pop    ebx
  66c217:	8b e5                	mov    esp,ebp
  66c219:	5d                   	pop    ebp
  66c21a:	c2 04 00             	ret    0x4
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
  66c25a:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c25f:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c263:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c26a:	59                   	pop    ecx
  66c26b:	5f                   	pop    edi
  66c26c:	5e                   	pop    esi
  66c26d:	5b                   	pop    ebx
  66c26e:	8b e5                	mov    esp,ebp
  66c270:	5d                   	pop    ebp
  66c271:	c2                   	.byte 0xc2
  66c272:	04                   	.byte 0x4
```

### BIN 指令：雙連線 port/key/ lane（`0x4957C0–0x495817`）

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
```

### BIN 指令：F94294 直接重設（`0x4E16B3–0x4E16D5`）

```asm
  4e16b3:	89 1d 8c 42 f9 00    	mov    DWORD PTR ds:0xf9428c,ebx
  4e16b9:	88 1d 90 42 f9 00    	mov    BYTE PTR ds:0xf94290,bl
  4e16bf:	89 1d 94 42 f9 00    	mov    DWORD PTR ds:0xf94294,ebx
  4e16c5:	89 1d 98 42 f9 00    	mov    DWORD PTR ds:0xf94298,ebx
  4e16cb:	c7 05 9c 42 f9 00 ff 	mov    DWORD PTR ds:0xf9429c,0xffff
  4e16d2:	ff 00 00 
```


## E44.9 — 失敗／重試／第一筆 wire 的嚴格分界

**具體問題**：選服成功路徑周圍最可能錯誤地推成已 wire 完成的地方在哪裏？socket 失敗及本地封包有何先後限制？

**BIN 原生結論／範圍**：`0x495807` 先檢查 key0 return，再 `0x49580F` 檢查 key2 return，分別去 `0x4959B0` / `0x49597E` 的失敗處理；成功路徑會對舊 `+BF60` 連線 local enqueue `0x007E` 並設 `Conn+A0B0=1`、清舊 pointer，隨後組織並 queue 新 key0 `0x0001` 的 payload 和新 key1/其他本地訊息。`0x49595B` 保存兩條新 Conn pointer 到 `+BF64/+BF68`。在 `0x4C37A0` mode5 路徑有 manager virtual+0x20 等控制，但沒有跨 IOCP 及 ACK trace。`0x807D7F` 只在有解出的有效 payload 後把 packet 交給 app FIFO；它不提供「是哪個 socket first S2C」的確定答案。

**尚缺與反證**：沒有官方 pcap/成功 connect socket trace。local queue 的先後不能取代 WSASend 完成序；尚未找到可比對的 server 首 reply / key0 key2 事件代與每次連線 reset 時序。把 key1 舊 0x007E、key0 新 0x0001 寫成「first wire」屬越證；也不把錯誤分支判斷視為重試策略完整。

**不能混淆**：native command `0x0013`／`0x007A` 是解碼 payload 中 WORD；key0 `0x0001`／key1 `0x007E` 是不同方向/階段的本地 C2S producer；`0x0BBB/0x1A68` 是更外層 framing；`0x70A/0x578` 是 UI event。

### BIN 指令：key0/key2 Connect 與 failure branch（`0x4957C0–0x495817`）

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
```

### BIN 指令：舊 key1 close-signal、排隊與重置（`0x495817–0x49587C`）

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
  495877:	ff                   	.byte 0xff
  495878:	15                   	.byte 0x15
  495879:	04 23                	add    al,0x23
  49587b:	bd                   	.byte 0xbd
```

### BIN 指令：本地組包及送入 queue（`0x49587D–0x495970`）

```asm
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
  49596e:	8b                   	.byte 0x8b
  49596f:	4d                   	dec    ebp
```

### BIN 指令：兩個 Connect 失敗/解除（`0x49597E–0x4959D8`）

```asm
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
```

### BIN 指令：IOCP 解碼後 queue（`0x807D7F–0x807DB2`）

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
```


## E44.10 — Runtime 物件一致性、負面搜尋適用界線、完整鏈驗收矩陣

**具體問題**：研究最大進展已產生，是否足以宣稱實際登入全功能鏈無條件閉合？若不足，精確缺口與下一段入口何在？

**BIN 原生結論／範圍**：`0x6E4F90` 保存 stack param2 至 `[ebp−0x208]`，`0x6E5530` 以之作 ECX 呼叫 `0x6E65A0`，`0x6E6871` 將該局部 pointer 寫 `[FBA7CC]+4`；成功後 `0x6E6935` 呼叫 `0x6DFA50`，後者在合法實體與 gate 下用 vptr+0x30 走 Client 主循環。這些關係保持 E43 的 N/C 分級，並與本次新的 0x0013 二級 callback path 合併。取得重大新 chain 仍繼續完成全部 10 單元；**停止 B（10 個子段）**，因實際 manager 所持物件 identity、0x13 input 最小合法長度及 key/first-wire 仍未全部核實。

**尚缺與反證**：實際 Client C+8 的正向來源沒有在通用 `6E4F90` caller 全部完成 identity proof；無法由 static dispatch 表消去 runtime table overwrite、Conn A080 lane、二級 manager null、網路時序之不確定性。`0x4C37A0` 欄位只有限定分支原生已證，不能據此直接製作完整可信 Server 0x13 回包。

### 本段實際有界 end-to-end（不是無條件現場 trace）

```text
OS WSARecv/IOCP success → decoded payload (E40)
 → FE3358 packet block → FC10D0 multi-lane FIFO (E40)
 → 0x804740 pop → Client C+0x148 virtual0 → 0x4930E0  [lane == 2, len != 0]
 → 0x48AAD0 signed command → 0x494360 → FD2CF8/0x4FDA30
 → [index 0x13 default] 0x4B7EC0 → FD2CF8+0x5EAC installed receiver
 → receiver vptr+4=0x4C4670 → secondary index0x13=0x4C37A0
 → [payload+0x16 == 0; UTF16 at +2 nonempty] 0x4C3080
 → 0x507510/0x507610 update FE1B54 choice data
 → 0x66B910 UI record consumer → 0x66C620 UI event (0x70A/0x578)
 → 0x66C090 resolves two keys → 0x5078C0 field+4 and 0x507750 record+0xC
 → [guard valid] 0x4957C0 → key0/key2 Connect/local outgoing queue
 → [WSASend/first S2C/actual UI transition] UNKNOWN

Alternate inbound payload command WORD 0x007A:
 → FD2CF8 default 0x4B7EC0 → secondary 0x4C4670(index0x7A)
 → 0x4C3C10 → 0x4C3080 (same FE1B54 table consumer path)
```

### E43 以來的最重要突破

- **新增並確定**：第一層 0x4B7EC0 不是終點，它在第二層物件存在時導向 0x4C4670。
- **新增並確定**：第二層 0x0013 對應 `0x4C37A0`、0x007A 對應 `0x4C3C10`，兩者都有進選服資料解析器的本地路徑。
- **新增並確定**：選服資料不只由 507750/5078C0 被讀取；`0x4C3080→507510/507610` 明確是它的 inbound producer，已可從該 `0x13` response 列表一路追到 UI selection 與 network connect。
- **不得越證**：條件式功能鏈不等於完整 wire protocol 或實際登入成功；沒有真正第一個 socket send/recv 序列，也沒有可用來發布 Server STABLE 的完整最小 input schema。


### BIN 指令：通用 manager API 收 p2（`0x6E4F90–0x6E4FBA`）

```asm
  6e4f90:	55                   	push   ebp
  6e4f91:	8b ec                	mov    ebp,esp
  6e4f93:	81 ec 18 02 00 00    	sub    esp,0x218
  6e4f99:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6e4f9e:	33 c5                	xor    eax,ebp
  6e4fa0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  6e4fa3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6e4fa6:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  6e4fa9:	53                   	push   ebx
  6e4faa:	89 85 f8 fd ff ff    	mov    DWORD PTR [ebp-0x208],eax
  6e4fb0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e4fb5:	56                   	push   esi
  6e4fb6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6e4fb9:	57                   	push   edi
```

### BIN 指令：pointer 轉至實際 manager writer（`0x6E5525–0x6E5540`）

```asm
  6e5525:	00 00                	add    BYTE PTR [eax],al
  6e5527:	83 c4 04             	add    esp,0x4
  6e552a:	8b 8d f8 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x208]
  6e5530:	e8 6b 10 00 00       	call   0x6e65a0
  6e5535:	8b f0                	mov    esi,eax
  6e5537:	85 f6                	test   esi,esi
  6e5539:	0f 89 c5 fe ff ff    	jns    0x6e5404
  6e553f:	83                   	.byte 0x83
```

### BIN 指令：成功 writer（`0x6E6813–0x6E6883`）

```asm
  6e6813:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6e6815:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  6e6818:	57                   	push   edi
  6e6819:	ff d2                	call   edx
  6e681b:	89 bd 04 ff ff ff    	mov    DWORD PTR [ebp-0xfc],edi
  6e6821:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6826:	85 c0                	test   eax,eax
  6e6828:	75 1f                	jne    0x6e6849
  6e682a:	68 80 13 00 00       	push   0x1380
  6e682f:	e8 34 aa 1a 00       	call   0x891268
  6e6834:	83 c4 04             	add    esp,0x4
  6e6837:	85 c0                	test   eax,eax
  6e6839:	74 07                	je     0x6e6842
  6e683b:	e8 90 8b ff ff       	call   0x6df3d0
  6e6840:	eb 02                	jmp    0x6e6844
  6e6842:	33 c0                	xor    eax,eax
  6e6844:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e6849:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6850:	8b b5 04 ff ff ff    	mov    esi,DWORD PTR [ebp-0xfc]
  6e6856:	8b f8                	mov    edi,eax
  6e6858:	74 10                	je     0x6e686a
  6e685a:	68 c8 a4 fb 00       	push   0xfba4c8
  6e685f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6865:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e686a:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6871:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  6e6874:	8b 3d 48 22 bd 00    	mov    edi,DWORD PTR ds:0xbd2248
  6e687a:	74 0c                	je     0x6e6888
  6e687c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6881:	ff d7                	call   edi
```

### BIN 指令：下游 consumer 延續（`0x6DFA60–0x6DFAE7`）

```asm
  6dfa60:	53                   	push   ebx
  6dfa61:	56                   	push   esi
  6dfa62:	e8 79 01 00 00       	call   0x6dfbe0
  6dfa67:	8b f0                	mov    esi,eax
  6dfa69:	e8 62 a9 00 00       	call   0x6ea3d0
  6dfa6e:	84 c0                	test   al,al
  6dfa70:	75 75                	jne    0x6dfae7
  6dfa72:	85 f6                	test   esi,esi
  6dfa74:	74 71                	je     0x6dfae7
  6dfa76:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6dfa7b:	85 c0                	test   eax,eax
  6dfa7d:	75 1f                	jne    0x6dfa9e
  6dfa7f:	68 80 13 00 00       	push   0x1380
  6dfa84:	e8 df 17 1b 00       	call   0x891268
  6dfa89:	83 c4 04             	add    esp,0x4
  6dfa8c:	85 c0                	test   eax,eax
  6dfa8e:	74 07                	je     0x6dfa97
  6dfa90:	e8 3b f9 ff ff       	call   0x6df3d0
  6dfa95:	eb 02                	jmp    0x6dfa99
  6dfa97:	33 c0                	xor    eax,eax
  6dfa99:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6dfa9e:	50                   	push   eax
  6dfa9f:	e8 bc fa ff ff       	call   0x6df560
  6dfaa4:	6a 00                	push   0x0
  6dfaa6:	84 c0                	test   al,al
  6dfaa8:	74 28                	je     0x6dfad2
  6dfaaa:	ff 15 d4 24 bd 00    	call   DWORD PTR ds:0xbd24d4
  6dfab0:	6a f4                	push   0xfffffff4
  6dfab2:	e8 b9 03 00 00       	call   0x6dfe70
  6dfab7:	50                   	push   eax
  6dfab8:	ff 15 d0 24 bd 00    	call   DWORD PTR ds:0xbd24d0
  6dfabe:	56                   	push   esi
  6dfabf:	8b c8                	mov    ecx,eax
  6dfac1:	e8 3a fc ff ff       	call   0x6df700
  6dfac6:	83 c4 04             	add    esp,0x4
  6dfac9:	e8 12 01 00 00       	call   0x6dfbe0
  6dface:	6a 01                	push   0x1
  6dfad0:	eb 0d                	jmp    0x6dfadf
  6dfad2:	ff 15 d4 24 bd 00    	call   DWORD PTR ds:0xbd24d4
  6dfad8:	e8 03 01 00 00       	call   0x6dfbe0
  6dfadd:	6a 00                	push   0x0
  6dfadf:	8b 08                	mov    ecx,DWORD PTR [eax]
  6dfae1:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  6dfae4:	50                   	push   eax
  6dfae5:	ff d2                	call   edx
```

---

## 客戶端／Server／跨 Task／可玩四類缺口

| 類型 | 當前有界已證內容 | 缺少的具體證據／解除條件 |
|---|---|---|
| **Client 待逆向** | command 0x0013/0x007A 有條件抵達 secondary dispatcher；0x0013 的特定 branch 寫 FE1B54；UI event 可觸發 4957C0 | 確認 0x13 最小 bounds、read.length 可接受、manager C+8 identity、F94294 非零 writer、記錄+0xC 具體 host 字元編碼/長度、完整 close/retry 狀態；不同 socket 首次 send/receive |
| **Server 待開發** | Client 消費至少兩類 response 的 list 結構，並依記錄選取 Connect host + 固定 native port；各欄位名只能用 offset | 等 Client wire schema 成立後再制定相容端點、帳號／選服政策與錯誤回覆；官方 Server 內部演算法沒有 native client 證據、不得代填 |
| **跨功能待整合** | T02 帶條件的 networking/dispatch 與 T03 auth/UI 的原生 chain 已新增共同地址 | T03 0x13 完整原稿及其登入 C2S/畫面代碼、T01 有界審核、S00 `GAP-NET-0002/SPEC-AUTH/SPEC-FLOW` 的命名/前置一致性，不在本研究擅改他人成果 |
| **待遊玩驗證** | 不執行原版 Client，只有 static BIN proof | 獲授權的 socket/payload trace、成功／失敗選服 UI、連線正常關閉/重試與同一 session first WSASend/first WSARecv，比對新 Server 行為 |

## 下一正式段號 E45（只接續未閉合項目）

1. `0x4C37A0` 的 **payload/len** 對 `+0x92` 及 `[+0x1C]` 的內層數量如何形成原生最小合法 schema，`0x4C3080` 是否自行做記錄 bounds；精確地分成 `0x13` mode0/mode5/error。
2. 原生 `record+0xC` 是字串或 struct，沿 `0x507610→0x507B10` 與 `0x4957C0` vptr connect 追實際 endpoint bytes，區別 UI label、host、授權 server address。
3. 檢查 `0x4B7DC0` 之外 FD2CF8 0x13 的 runtime override alias、二級 `0x4C3220` 初始化與 `0x4C2F90` 註冊的時間先後；避免將靜態可達誤寫成一定收到。
4. 從 `0x4957C0` 的 key0/key2 成功/失敗到 `0x8068B0` WSASend 與 `0x806CF0` IOCP receive 的個別 Conn lifetime、第一筆確認的 wire frame/response，需可驗證 socket ordering 或其他等價第一手資料。
5. 收斂 `6E4F90` 具體 `C+8` writer 來源，確認與 `0x4C2F90` 之次級接收器生命週期同一有效 session；真實 runtime trace 若沒有就清楚留 U。

**停段與權限**：已完成 E44.1–E44.10，按使用者指定 **B 10子段強制交付**；未擅自研究 E44.11；沒有 Commit/Push，RR-0005 保持當次已讀快照下的未認領，沒有更新遠端。尚未得到本次端到端目標 A（包含 first wire/response）的要求。

## 重現與範圍

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -d -M intel --start-address=0x4c3220 --stop-address=0x4c32dc Tartaros.bin
objdump -d -M intel --start-address=0x4c37a0 --stop-address=0x4c3b80 Tartaros.bin
objdump -d -M intel --start-address=0x4c3080 --stop-address=0x4c316b Tartaros.bin
objdump -d -M intel --start-address=0x507610 --stop-address=0x507741 Tartaros.bin
objdump -d -M intel --start-address=0x66c090 --stop-address=0x66c273 Tartaros.bin
```

靜態 native xref/反組譯無法證明 unseen indirect dynamic handler、外部配置的 callbacks 或相同 session 收發排序；未進行網路連線或修改二進位。原本 E41–E43 的 Markdown 原稿保留；本次補足的跨表委派與入站 writer 以 E44 獨立原稿更正缺口，不覆寫歷史檔案。
