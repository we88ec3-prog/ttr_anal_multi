# E42 — RR-0005 / KR T02：以端到端功能鏈為目標的十個大型原生研究子段

**研究時間**：2026-10-29T23:24:55+08:00（Asia/Taipei）；**研究者**：chatgpt-web roy；**正式段號**：E42，**本稿 E42.1–E42.10 為同一正式段號的研究子段**，不是十個正式段號。

**研究目標（先設定，再拆分）**：在 E41 已建立的 `C+8 → Client+148 → 4930E0 → 48AAD0 → 494360 → 4FDA30` 條件式入站路由基礎上，嘗試閉合「事件框架實際註冊 Client／runtime manager 擁有有效物件 → 登入／選服觸發既定 key0/1/2 Connect → 首筆應用層送出及 receive → IOCP / FC10D0 → 具體分派器／回覆副作用 → 錯誤、斷線、重試／頁面銜接」的**單一玩家流程**。只要尚未閉合整條功能鏈，就算找出重大 writer/reader/handler 也**繼續研究**，除非十子段上限或真實證據阻塞。

**本次停止判定**：**B — 已完成 10 個有明確研究問題、BIN 證據與剩餘缺口的分析子段**；尚未達到 A（完整 first wire、登入到選服 UI、特定 key transport 來源與 runtime manager writer 仍不完整）。遇到局部阻塞不偽造；保留 E43 交接。**並未因局部重大發現而提前停止。**

**第一手資料與管控**：原始 `Tartaros.bin` 大小 **12,472,320 bytes**、重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32/i386 KR。主要工具離線 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`、Python 獨立 LE32 / CALL rel32 搜索。**沒有執行、附加或修改原遊戲，也沒有官方 Server、實際 pcap 或 socket trace。** 不把非原生 fixture/用戶端補丁當作官方網路封包證據。

**GitHub 同一對話開工快照沿用**：`main=43c51f579cada3aa6257eb8467f65af281c3585b`、`extra/roy1=34d1a55b21df78ac1c025872e641fe23dfe52645`，沿用 E41 已完成的新對話首次 `AGENTS.md`/T02/RR 台帳檢查，**本次不宣稱又重新取得最新 main**。RR5 上述快照為 `PENDING/QUEUED`、`claim=null`、`submission=null`。使用者未授權 Commit/Push，**本次僅本地 Markdown，沒有 Git blob、未認領 RR，也未寫任何 Task、S00、T01。** 舊 E40/E41 是定位和交叉界限，新增證據仍直接查本次 BIN。

**映射**：`.text` VA `0x401000` raw `0x400`、`raw=VA−0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`、`raw=VA−0x401A00`；`.data` globals 另有獨立區段偏移，不用 `.text` 計算。`objdump -b binary` 顯示的 `.data+offset` 只是「整檔被當作 binary」的節標籤，**不等於實際 PE .data 區段**。

## 0. 子段結構與嚴格證據分級

| 子段 | 功能鏈角色 | 本次目的 | 結果分類 |
|---|---|---|---|
| 1 | manager allocation/init | 驗證 manager+4 初始值和同步來源 | 原生有界確認 |
| 2 | Client+8 框架註冊 | 實際建立 C+8 並交事件框架，向 manager 探索 | 原生確認 + 尚缺 alias |
| 3 | manager+4 lookup / writer | 尋找使 0x6DFBE0 返回 C+8 的正向 writer | 確認讀取；寫入未閉合 |
| 4 | 清理／失效 | 觀察 manager+4 清零及 teardown gate | 新增原生清理邊界 |
| 5 | OS tick → recv FIFO → callback | 核對真正 callback 條件和 lane/return | 有條件閉合 |
| 6 | callback → two-tier dispatcher | 雙表、命令解碼和 bounds/fallback | 有條件閉合；first response 未知 |
| 7 | key1 Connect and callers | 從實際呼叫者追到 key1 0x20DF、失敗處理 | 有界確認 |
| 8 | key0/key2 Connect + local initial payload | key0 0x20E0、key2 0x20DE 建立與失敗/遞送 | 有界確認；first wire 未知 |
| 9 | 選服上游實際 gates | 0x66C090 分支通往 4957C0 的條件 | 新增原生上游分支 |
| 10 | first S2C／login result／驗收界限 | 對齊 message handler、副作用、缺失的端到端事實 | 缺口定界，B 停止 |

**分級字典**：`N` = 本次 BIN bytes / 指令及局部控制流程已證；`C` = 已證構件在明列條件下可達；`H` = 合理但未能在本次原始證據閉合；`U` = 尚未證實／禁止冒稱。靜態 `N/C` **不是 T01 的 FULL-PASS 認定**。

## E42.1 — 事件 manager 物件配置與初始 +4 欄位

**研究問題：**FBA7CC 指向的是甚麼配置，首次讀 manager+4 時有甚麼初始值？

**分析結果（第一手／推測區分）：** **N**：`0x6DFBE0` 在 `[FBA7CC]==0` 時嘗試配置 `0x1380` bytes，非零配置結果交 `0x6DF3D0`，寫回 `[FBA7CC]`；`0x6DF3D0 → 0x6DF660` 使用 `0x89E860` 清零 `0x1350` bytes，範圍包含 manager `+0x4`。`0x6DFBE0` 隨後讀 `[manager+4]`。因此 **剛配置且無後續 writer 時會讀到 NULL**；E41 之「manager+4 必是 C+8」不成立為無條件主張。manager 是共享 global ownership 路線，並非 C 的內嵌次級 vptr。`0x6DF6D0` 也有獨立 lazy allocation，不能把這兩者重複呼叫計成兩個 manager。`0x6DF660` 還操作全域鎖 `FBA4C8` 及旗標 `D63D09`。

**剩餘缺口：** 正向 `manager+4 = C+8` 的 setter 仍未知；calloc/清零後如果真實更新不成功，`6DFA50` 的 `if(!esi)` gate 就不會進 virtual+0x30。不能把 getter 的存在等同註冊成功。

**原件指令 `6DFBE0 lazy manager getter，含 +4 讀取`（VA `0x6dfbe0`–`0x6dfc3a`，`.text raw=VA−0x400C00`）：**

```asm
  6dfbe0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6dfbe5:	85 c0                	test   eax,eax
  6dfbe7:	75 1f                	jne    0x6dfc08
  6dfbe9:	68 80 13 00 00       	push   0x1380
  6dfbee:	e8 75 16 1b 00       	call   0x891268
  6dfbf3:	83 c4 04             	add    esp,0x4
  6dfbf6:	85 c0                	test   eax,eax
  6dfbf8:	74 07                	je     0x6dfc01
  6dfbfa:	e8 d1 f7 ff ff       	call   0x6df3d0
  6dfbff:	eb 02                	jmp    0x6dfc03
  6dfc01:	33 c0                	xor    eax,eax
  6dfc03:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6dfc08:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc0f:	56                   	push   esi
  6dfc10:	8b f0                	mov    esi,eax
  6dfc12:	74 0b                	je     0x6dfc1f
  6dfc14:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc19:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6dfc1f:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc26:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  6dfc29:	74 0b                	je     0x6dfc36
  6dfc2b:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc30:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6dfc36:	8b c6                	mov    eax,esi
  6dfc38:	5e                   	pop    esi
  6dfc39:	c3                   	ret
```

**原件指令 `6DF660 manager 初始化／清零`（VA `0x6df660`–`0x6df6c4`，`.text raw=VA−0x400C00`）：**

```asm
  6df660:	53                   	push   ebx
  6df661:	e8 7a bf 00 00       	call   0x6eb5e0
  6df666:	68 50 13 00 00       	push   0x1350
  6df66b:	6a 00                	push   0x0
  6df66d:	56                   	push   esi
  6df66e:	e8 ed f1 1b 00       	call   0x89e860
  6df673:	83 c4 0c             	add    esp,0xc
  6df676:	b3 01                	mov    bl,0x1
  6df678:	68 c8 a4 fb 00       	push   0xfba4c8
  6df67d:	88 1d 09 3d d6 00    	mov    BYTE PTR ds:0xd63d09,bl
  6df683:	ff 15 ec 22 bd 00    	call   DWORD PTR ds:0xbd22ec
  6df689:	83 c8 ff             	or     eax,0xffffffff
  6df68c:	88 9e 09 03 00 00    	mov    BYTE PTR [esi+0x309],bl
  6df692:	88 9e fd 02 00 00    	mov    BYTE PTR [esi+0x2fd],bl
  6df698:	88 9e d1 02 00 00    	mov    BYTE PTR [esi+0x2d1],bl
  6df69e:	88 9e 1a 03 00 00    	mov    BYTE PTR [esi+0x31a],bl
  6df6a4:	88 9e d3 02 00 00    	mov    BYTE PTR [esi+0x2d3],bl
  6df6aa:	89 86 44 03 00 00    	mov    DWORD PTR [esi+0x344],eax
  6df6b0:	89 86 48 03 00 00    	mov    DWORD PTR [esi+0x348],eax
  6df6b6:	89 86 30 03 00 00    	mov    DWORD PTR [esi+0x330],eax
  6df6bc:	89 86 58 03 00 00    	mov    DWORD PTR [esi+0x358],eax
  6df6c2:	5b                   	pop    ebx
  6df6c3:	c3                   	ret
```

**原件指令 `6DF3D0 manager 本體尾端初始化`（VA `0x6df3d0`–`0x6df419`，`.text raw=VA−0x400C00`）：**

```asm
  6df3d0:	d9 ee                	fldz
  6df3d2:	56                   	push   esi
  6df3d3:	8b f0                	mov    esi,eax
  6df3d5:	dd 96 50 13 00 00    	fst    QWORD PTR [esi+0x1350]
  6df3db:	dd 9e 58 13 00 00    	fstp   QWORD PTR [esi+0x1358]
  6df3e1:	b8 01 00 00 00       	mov    eax,0x1
  6df3e6:	d9 ee                	fldz
  6df3e8:	89 86 70 13 00 00    	mov    DWORD PTR [esi+0x1370],eax
  6df3ee:	d9 9e 78 13 00 00    	fstp   DWORD PTR [esi+0x1378]
  6df3f4:	89 86 74 13 00 00    	mov    DWORD PTR [esi+0x1374],eax
  6df3fa:	dd 05 30 57 c5 00    	fld    QWORD PTR ds:0xc55730
  6df400:	c7 86 60 13 00 00 1e 	mov    DWORD PTR [esi+0x1360],0x1e
  6df407:	00 00 00 
  6df40a:	dd 9e 68 13 00 00    	fstp   QWORD PTR [esi+0x1368]
  6df410:	e8 4b 02 00 00       	call   0x6df660
  6df415:	8b c6                	mov    eax,esi
  6df417:	5e                   	pop    esi
  6df418:	c3                   	ret
```

## E42.2 — Client+8 真正入口與基底事件框架初始化

**研究問題：**誰在原生堆疊上建立 Client，傳向哪些 framework 順序？

**分析結果（第一手／推測區分）：** **N**：`0x4A3041` 得到完整 Client `C=&stack[0x2C]`、`0x4A3046` 呼叫 `0x48AB70`，`0x4A304B` 取 `ESI=&stack[0x34] = C+8`，再 `0x4A305A` 進 `0x6DEB40`。`0x6DEB40` 先從 `[ESI].vptr+0x20` 執行 initializer，失敗會標 `[ESI+2C]=1` 並返回 `0x80004005`。成功才做一次 lazy manager allocation，還依序呼叫一批 `0x6E18xx` 設定 manager 內其他回呼、`0x6DFD60` 及 `[ESI].vptr+0x28`；後續呼叫 `0x6E2850`。`0x48AC9A` 安裝的 holder vptr `C05AEC` 與 `C+8` base vptr `C05AA4` 是**不同物件偏移**。本次沒有把 `0x6E18xx` 的 manager `+0x398/+0x39C` listener 誤指作 `manager+4`。

**剩餘缺口：** 雖然 `C+8` 明確被 framework 消費，仍未看到最後把此指標送入 `[FBA7CC]+4` 的直接 store/具別名的間接 store；`0x6E2850` 也執行多層 COM/vtable 調用，若指標透過它們儲存，必須另有實際 caller/target 證明。

**原件指令 `完整 C、C+8 引用與起始框架`（VA `0x4a302b`–`0x4a306c`，`.text raw=VA−0x400C00`）：**

```asm
  4a302b:	85 c0                	test   eax,eax
  4a302d:	74 ca                	je     0x4a2ff9
  4a302f:	e8 4c a6 fa ff       	call   0x44d680
  4a3034:	8b 08                	mov    ecx,DWORD PTR [eax]
  4a3036:	85 c9                	test   ecx,ecx
  4a3038:	74 07                	je     0x4a3041
  4a303a:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a303c:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4a303f:	ff d0                	call   eax
  4a3041:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  4a3045:	51                   	push   ecx
  4a3046:	e8 25 7b fe ff       	call   0x48ab70
  4a304b:	8d 74 24 34          	lea    esi,[esp+0x34]
  4a304f:	c7 84 24 c0 c0 00 00 	mov    DWORD PTR [esp+0xc0c0],0x1
  4a3056:	01 00 00 00 
  4a305a:	e8 e1 ba 23 00       	call   0x6deb40
  4a305f:	e8 dc bb 23 00       	call   0x6dec40
  4a3064:	8b fe                	mov    edi,esi
  4a3066:	e8 25 bc 23 00       	call   0x6dec90
  4a306b:	e8           	call   0x44d680
```

**原件指令 `框架初始化成功／失敗／listener 設定`（VA `0x6deb40`–`0x6dec3f`，`.text raw=VA−0x400C00`）：**

```asm
  6deb40:	8b 06                	mov    eax,DWORD PTR [esi]
  6deb42:	8b 48 20             	mov    ecx,DWORD PTR [eax+0x20]
  6deb45:	57                   	push   edi
  6deb46:	56                   	push   esi
  6deb47:	ff d1                	call   ecx
  6deb49:	85 c0                	test   eax,eax
  6deb4b:	74 1f                	je     0x6deb6c
  6deb4d:	8d 56 40             	lea    edx,[esi+0x40]
  6deb50:	52                   	push   edx
  6deb51:	68 d8 11 c4 00       	push   0xc411d8
  6deb56:	e8 62 45 1b 00       	call   0x8930bd
  6deb5b:	83 c4 08             	add    esp,0x8
  6deb5e:	c7 46 2c 01 00 00 00 	mov    DWORD PTR [esi+0x2c],0x1
  6deb65:	b8 05 40 00 80       	mov    eax,0x80004005
  6deb6a:	5f                   	pop    edi
  6deb6b:	c3                   	ret
  6deb6c:	83 3d cc a7 fb 00 00 	cmp    DWORD PTR ds:0xfba7cc,0x0
  6deb73:	75 1f                	jne    0x6deb94
  6deb75:	68 80 13 00 00       	push   0x1380
  6deb7a:	e8 e9 26 1b 00       	call   0x891268
  6deb7f:	83 c4 04             	add    esp,0x4
  6deb82:	85 c0                	test   eax,eax
  6deb84:	74 07                	je     0x6deb8d
  6deb86:	e8 45 08 00 00       	call   0x6df3d0
  6deb8b:	eb 02                	jmp    0x6deb8f
  6deb8d:	33 c0                	xor    eax,eax
  6deb8f:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6deb94:	56                   	push   esi
  6deb95:	e8 c6 2c 00 00       	call   0x6e1860
  6deb9a:	83 c4 04             	add    esp,0x4
  6deb9d:	56                   	push   esi
  6deb9e:	e8 8d 2d 00 00       	call   0x6e1930
  6deba3:	83 c4 04             	add    esp,0x4
  6deba6:	56                   	push   esi
  6deba7:	e8 54 2e 00 00       	call   0x6e1a00
  6debac:	83 c4 04             	add    esp,0x4
  6debaf:	56                   	push   esi
  6debb0:	e8 1b 2f 00 00       	call   0x6e1ad0
  6debb5:	83 c4 04             	add    esp,0x4
  6debb8:	56                   	push   esi
  6debb9:	e8 22 33 00 00       	call   0x6e1ee0
  6debbe:	83 c4 04             	add    esp,0x4
  6debc1:	56                   	push   esi
  6debc2:	e8 49 32 00 00       	call   0x6e1e10
  6debc7:	83 c4 04             	add    esp,0x4
  6debca:	56                   	push   esi
  6debcb:	e8 70 31 00 00       	call   0x6e1d40
  6debd0:	83 c4 04             	add    esp,0x4
  6debd3:	56                   	push   esi
  6debd4:	e8 c7 2f 00 00       	call   0x6e1ba0
  6debd9:	83 c4 04             	add    esp,0x4
  6debdc:	56                   	push   esi
  6debdd:	e8 8e 30 00 00       	call   0x6e1c70
  6debe2:	83 c4 04             	add    esp,0x4
  6debe5:	e8 86 16 00 00       	call   0x6e0270
  6debea:	e8 c1 33 00 00       	call   0x6e1fb0
  6debef:	e8 6c 70 00 00       	call   0x6e5c60
  6debf4:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6debf7:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6debfa:	8b 56 28             	mov    edx,DWORD PTR [esi+0x28]
  6debfd:	8b 7e 24             	mov    edi,DWORD PTR [esi+0x24]
  6dec00:	50                   	push   eax
  6dec01:	51                   	push   ecx
  6dec02:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  6dec05:	52                   	push   edx
  6dec06:	33 d2                	xor    edx,edx
  6dec08:	e8 c3 38 00 00       	call   0x6e24d0
  6dec0d:	83 c4 0c             	add    esp,0xc
  6dec10:	e8 4b 11 00 00       	call   0x6dfd60
  6dec15:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6dec18:	8b 06                	mov    eax,DWORD PTR [esi]
  6dec1a:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  6dec1d:	56                   	push   esi
  6dec1e:	ff d1                	call   ecx
  6dec20:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6dec23:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6dec26:	56                   	push   esi
  6dec27:	68 50 ae 6e 00       	push   0x6eae50
  6dec2c:	68 10 ae 6e 00       	push   0x6eae10
  6dec31:	50                   	push   eax
  6dec32:	51                   	push   ecx
  6dec33:	e8 18 3c 00 00       	call   0x6e2850
  6dec38:	83 c4 14             	add    esp,0x14
  6dec3b:	33 c0                	xor    eax,eax
  6dec3d:	5f                   	pop    edi
  6dec3e:	c3                   	ret
```

**原件指令 `manager callback initializer 一例（+398 而非 +4）`（VA `0x6e1890`–`0x6e1923`，`.text raw=VA−0x400C00`）：**

```asm
  6e1890:	00 00                	add    BYTE PTR [eax],al
  6e1892:	53                   	push   ebx
  6e1893:	56                   	push   esi
  6e1894:	57                   	push   edi
  6e1895:	8b 3d 4c 22 bd 00    	mov    edi,DWORD PTR ds:0xbd224c
  6e189b:	8b f0                	mov    esi,eax
  6e189d:	74 0c                	je     0x6e18ab
  6e189f:	68 c8 a4 fb 00       	push   0xfba4c8
  6e18a4:	ff d7                	call   edi
  6e18a6:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e18ab:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e18b2:	8b 1d 48 22 bd 00    	mov    ebx,DWORD PTR ds:0xbd2248
  6e18b8:	c7 86 64 03 00 00 a0 	mov    DWORD PTR [esi+0x364],0x6eaea0
  6e18bf:	ae 6e 00 
  6e18c2:	74 0c                	je     0x6e18d0
  6e18c4:	68 c8 a4 fb 00       	push   0xfba4c8
  6e18c9:	ff d3                	call   ebx
  6e18cb:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e18d0:	85 c0                	test   eax,eax
  6e18d2:	75 1f                	jne    0x6e18f3
  6e18d4:	68 80 13 00 00       	push   0x1380
  6e18d9:	e8 8a f9 1a 00       	call   0x891268
  6e18de:	83 c4 04             	add    esp,0x4
  6e18e1:	85 c0                	test   eax,eax
  6e18e3:	74 07                	je     0x6e18ec
  6e18e5:	e8 e6 da ff ff       	call   0x6df3d0
  6e18ea:	eb 02                	jmp    0x6e18ee
  6e18ec:	33 c0                	xor    eax,eax
  6e18ee:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e18f3:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e18fa:	8b f0                	mov    esi,eax
  6e18fc:	74 07                	je     0x6e1905
  6e18fe:	68 c8 a4 fb 00       	push   0xfba4c8
  6e1903:	ff d7                	call   edi
  6e1905:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e190c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6e190f:	89 86 98 03 00 00    	mov    DWORD PTR [esi+0x398],eax
  6e1915:	74 07                	je     0x6e191e
  6e1917:	68 c8 a4 fb 00       	push   0xfba4c8
  6e191c:	ff d3                	call   ebx
  6e191e:	5f                   	pop    edi
  6e191f:	5e                   	pop    esi
  6e1920:	5b                   	pop    ebx
  6e1921:	5d                   	pop    ebp
  6e1922:	c3                   	ret
```

## E42.3 — runtime manager+4 writer／讀者反查與直接 CALL XREF

**研究問題：**能否從所有主要 loader / getter xref 中找到 manager+4 的非零 writer，把 E41 條件式改成無條件？

**分析結果（第一手／推測區分）：** **N**：從 `0x6DFBE0` 的 `mov esi,[esi+4]` 可知它只回傳 manager+4，而非欄位地址。`0x6DFA50` 的 `0x6DFA62` 首先呼叫 getter，`0x6DFA72` 若為 NULL 則直接跳出，不解 vptr。另一分支以 `0x6DFBE0` 再取、`push eax` 同時當 this 與 explicit pointer 呼叫 vtable+0x30。全 `.text` raw byte 搜尋 x86 `E8 rel32` 候選精確 target 得到（**rel32 命中仍需以指令邊界辨真**）：`0x495610`: `0x6d6377`, `0x6d6424`, `0x6d6508`, `0x6d65c8`, `0x6d670c`, `0x6d696c`; `0x4957c0`: `0x66c1a7`, `0x66c247`; `0x6dfbe0`: `0x555797`, `0x5557e4`, `0x555831`, `0x555872`, `0x6d5159`, `0x6d57c9`, `0x6dfa62`, `0x6dfac9`, `0x6dfad8`, `0x6e539c`, `0x6e53a9`, `0x6e698b`, `0x6e6aa5`, `0x6e6b08`, `0x6e6bae`, `0x6e6bc5`, `0x6e6c36`, `0x6e7b98`, `0x6e818d`, `0x6e8242`, `0x6e8295`, `0x6e93a3`, `0x6e9580`, `0x6e982a`, `0x6e9c54`; `0x6dfa50`: `0x6e6935`, `0x6e702a`; `0x6deb40`: `0x4a305a`。另在實際反組譯 `0x401000–0x911000` 文字中，檢查 `mov reg,ds:0xFBA7CC` 後到 `ret` 的有限 window，只有 `0x6E9F9C` 發現對同一暫存器 `ESI+4` 的寫入，且為**清零**（參見 E42.4）。此否定搜尋只是該模式/視窗的限定結果，不能排除 `manager*` 透過參數、虛擬函式、記憶體 alias 或更後段原生程式碼寫入。

**剩餘缺口：** 正向 setter 尚未閉合；某些對 `manager*` 寫入的函式可能是間接呼叫、別名存放或跨模組 callback。未執行 runtime，因此不能保證誰將 C+8 登錄至欄位。這是整條入站「實際特定 callback」的主要阻塞。

**原件指令 `6DFA50 的 runtime getter + null gate + vtable+30`（VA `0x6dfa50`–`0x6dfb15`，`.text raw=VA−0x400C00`）：**

```asm
  6dfa50:	55                   	push   ebp
  6dfa51:	8b ec                	mov    ebp,esp
  6dfa53:	83 ec 18             	sub    esp,0x18
  6dfa56:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6dfa5b:	33 c5                	xor    eax,ebp
  6dfa5d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
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
  6dfae7:	e8 e4 a8 00 00       	call   0x6ea3d0
  6dfaec:	84 c0                	test   al,al
  6dfaee:	75 72                	jne    0x6dfb62
  6dfaf0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6dfaf5:	85 c0                	test   eax,eax
  6dfaf7:	75 1f                	jne    0x6dfb18
  6dfaf9:	68 80 13 00 00       	push   0x1380
  6dfafe:	e8 65 17 1b 00       	call   0x891268
  6dfb03:	83 c4 04             	add    esp,0x4
  6dfb06:	85 c0                	test   eax,eax
  6dfb08:	74 07                	je     0x6dfb11
  6dfb0a:	e8 c1 f8 ff ff       	call   0x6df3d0
  6dfb0f:	eb 02                	jmp    0x6dfb13
  6dfb11:	33 c0                	xor    eax,eax
  6dfb13:	a3 cc          	mov    ds:0xfba7cc,eax
```

**原件指令 `manager+4 getter 的受鎖讀取`（VA `0x6dfc08`–`0x6dfc3a`，`.text raw=VA−0x400C00`）：**

```asm
  6dfc08:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc0f:	56                   	push   esi
  6dfc10:	8b f0                	mov    esi,eax
  6dfc12:	74 0b                	je     0x6dfc1f
  6dfc14:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc19:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6dfc1f:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6dfc26:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  6dfc29:	74 0b                	je     0x6dfc36
  6dfc2b:	68 c8 a4 fb 00       	push   0xfba4c8
  6dfc30:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6dfc36:	8b c6                	mov    eax,esi
  6dfc38:	5e                   	pop    esi
  6dfc39:	c3                   	ret
```

## E42.4 — manager+4 的失效、teardown 與 stale callback 風險

**研究問題：**可否證明註冊指標不是永久有效，並找到失效 writer？

**分析結果（第一手／推測區分）：** **N（本次新增有界失效路徑）**：在 `0x6E9F81` 讀取 `[FBA7CC]` 到 `ESI`，於 `0x6E9F9C` 在可選 global lock 保護區把 `[ESI+4]=EBX`，而此基本區段的 `0x6E9F3C` 把 `EBX=0`；因此是**明確 `manager+4=0` writer**。下游依 `[EBP+8]` 決定是否還釋放 `[manager+0xC]`，隨後可見其他清理，不可推論完全清除所有 IOCP outstanding packets。另一基底 shutdown `0x6DEC90` 在 guard 後讀 `FBA7CC`、調 `0x6E9AE0`、釋放 manager、寫 global =0；其後呼叫 `[EDI].vptr+0x24`。這證實 lifecycle 有至少兩層「manager+4 無效」與「manager 物件本體釋放」，**禁止把指標持續存在當不變式**。

**剩餘缺口：** 未證實 `0x6E9F..` 與 shutdown 在所有 Connect close/Client dtor 路徑的真正執行次序；也未驗證 IOCP worker 接到排隊 packet 之後是否持有 Conn / holder lifetime 保證。不能從靜態 clear 推定已發生 UAF 或 race。

**原件指令 `manager+4 = 0 與後續釋放路徑`（VA `0x6e9f3c`–`0x6ea01e`，`.text raw=VA−0x400C00`）：**

```asm
  6e9f3c:	33 db                	xor    ebx,ebx
  6e9f3e:	3b c3                	cmp    eax,ebx
  6e9f40:	76 18                	jbe    0x6e9f5a
  6e9f42:	50                   	push   eax
  6e9f43:	68 a8 14 c4 00       	push   0xc414a8
  6e9f48:	e8 70 91 1a 00       	call   0x8930bd
  6e9f4d:	68 04 09 04 80       	push   0x80040904
  6e9f52:	e8 19 06 00 00       	call   0x6ea570
  6e9f57:	83 c4 0c             	add    esp,0xc
  6e9f5a:	39 1d cc a7 fb 00    	cmp    DWORD PTR ds:0xfba7cc,ebx
  6e9f60:	75 1f                	jne    0x6e9f81
  6e9f62:	68 80 13 00 00       	push   0x1380
  6e9f67:	e8 fc 72 1a 00       	call   0x891268
  6e9f6c:	83 c4 04             	add    esp,0x4
  6e9f6f:	3b c3                	cmp    eax,ebx
  6e9f71:	74 07                	je     0x6e9f7a
  6e9f73:	e8 58 54 ff ff       	call   0x6df3d0
  6e9f78:	eb 02                	jmp    0x6e9f7c
  6e9f7a:	33 c0                	xor    eax,eax
  6e9f7c:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e9f81:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6e9f87:	8b 3d 4c 22 bd 00    	mov    edi,DWORD PTR ds:0xbd224c
  6e9f8d:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9f93:	74 07                	je     0x6e9f9c
  6e9f95:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9f9a:	ff d7                	call   edi
  6e9f9c:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  6e9f9f:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9fa5:	74 0b                	je     0x6e9fb2
  6e9fa7:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9fac:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e9fb2:	38 5d 08             	cmp    BYTE PTR [ebp+0x8],bl
  6e9fb5:	0f 84 b1 00 00 00    	je     0x6ea06c
  6e9fbb:	39 1d cc a7 fb 00    	cmp    DWORD PTR ds:0xfba7cc,ebx
  6e9fc1:	75 1f                	jne    0x6e9fe2
  6e9fc3:	68 80 13 00 00       	push   0x1380
  6e9fc8:	e8 9b 72 1a 00       	call   0x891268
  6e9fcd:	83 c4 04             	add    esp,0x4
  6e9fd0:	3b c3                	cmp    eax,ebx
  6e9fd2:	74 07                	je     0x6e9fdb
  6e9fd4:	e8 f7 53 ff ff       	call   0x6df3d0
  6e9fd9:	eb 02                	jmp    0x6e9fdd
  6e9fdb:	33 c0                	xor    eax,eax
  6e9fdd:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e9fe2:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6e9fe8:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9fee:	74 07                	je     0x6e9ff7
  6e9ff0:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9ff5:	ff d7                	call   edi
  6e9ff7:	8b 76 0c             	mov    esi,DWORD PTR [esi+0xc]
  6e9ffa:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6ea000:	74 0b                	je     0x6ea00d
  6ea002:	68 c8 a4 fb 00       	push   0xfba4c8
  6ea007:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6ea00d:	3b f3                	cmp    esi,ebx
  6ea00f:	74 09                	je     0x6ea01a
  6ea011:	56                   	push   esi
  6ea012:	e8 f5 71 1a 00       	call   0x89120c
  6ea017:	83 c4 04             	add    esp,0x4
  6ea01a:	39 1d cc a7      	cmp    DWORD PTR ds:0xfba7cc,ebx
```

**原件指令 `Framework shutdown 中 global manager free`（VA `0x6dec90`–`0x6decf3`，`.text raw=VA−0x400C00`）：**

```asm
  6dec90:	83 7f 2c 00          	cmp    DWORD PTR [edi+0x2c],0x0
  6dec94:	56                   	push   esi
  6dec95:	74 07                	je     0x6dec9e
  6dec97:	b8 05 40 00 80       	mov    eax,0x80004005
  6dec9c:	5e                   	pop    esi
  6dec9d:	c3                   	ret
  6dec9e:	e8 fd 14 00 00       	call   0x6e01a0
  6deca3:	85 c0                	test   eax,eax
  6deca5:	74 13                	je     0x6decba
  6deca7:	83 f8 01             	cmp    eax,0x1
  6decaa:	74 0e                	je     0x6decba
  6decac:	50                   	push   eax
  6decad:	68 04 12 c4 00       	push   0xc41204
  6decb2:	e8 06 44 1b 00       	call   0x8930bd
  6decb7:	83 c4 08             	add    esp,0x8
  6decba:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6decc0:	85 f6                	test   esi,esi
  6decc2:	74 23                	je     0x6dece7
  6decc4:	e8 17 ae 00 00       	call   0x6e9ae0
  6decc9:	68 c8 a4 fb 00       	push   0xfba4c8
  6decce:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  6decd4:	56                   	push   esi
  6decd5:	e8 32 25 1b 00       	call   0x89120c
  6decda:	83 c4 04             	add    esp,0x4
  6decdd:	c7 05 cc a7 fb 00 00 	mov    DWORD PTR ds:0xfba7cc,0x0
  6dece4:	00 00 00 
  6dece7:	8b 07                	mov    eax,DWORD PTR [edi]
  6dece9:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  6decec:	57                   	push   edi
  6deced:	ff d1                	call   ecx
  6decef:	33 c0                	xor    eax,eax
  6decf1:	5e                   	pop    esi
  6decf2:	c3                   	ret
```

## E42.5 — mainloop 的 callback holder／lane／stop gate

**研究問題：**即使 manager+4 正向 writer 未閉合，這條已確認構件之間，在何種條件下真的被執行？

**分析結果（第一手／推測區分）：** **C/N**：`0x6DFA50` `6DFBE0` getter 非空且非退出狀態時，`[obj.vptr+0x30](obj)`；若 `obj==C+8`，`[C+8].vptr=C05AA4` 的 `+0x30` 為 `490FE0`，它於 `0x491983` 從**explicit object arg** `obj+0x140` 得到 `holder=C+148`。`0x804740` 接受 holder，從已證 FC10D0 app FIFO pop，`0x80486D` 以 holder.vptr+0 呼叫 callback（四個入參：`Conn*、payload、len、lane`），call 完畢先回收 packet block，之後根據 callback 回值決定目前 lane 是否停止 drain。`Conn+A080` 是 lane selector，不能拿它等價 transport key2。此處前面 E40 已核 producer `806CF0→807B40→807D9E→489920→8040A0`，本次只抽關鍵新檢驗範圍確認接合，不重新替整份 E40 主張做 T01 全文驗收。

**剩餘缺口：** manager+4 的真實寫入、Conn* refcount、排隊之後被 socket close / pool recycle 的動態時序及任務 tick 間的 interleave 尚無 runtime 證據；virtual+0x30 的成功 path 是條件式而非必然。

**原件指令 `主循環 E41 已證 holder 算式`（VA `0x49196e`–`0x4919a7`，`.text raw=VA−0x400C00`）：**

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
  4919a6:	0c
```

**原件指令 `接收 FIFO pop 與 virtual0 ABI`（VA `0x804837`–`0x80488b`，`.text raw=VA−0x400C00`）：**

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
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
```

**原件指令 `回收完成後 stop gate`（VA `0x804993`–`0x8049cd`，`.text raw=VA−0x400C00`）：**

```asm
  804993:	01 73 50             	add    DWORD PTR [ebx+0x50],esi
  804996:	83 7d 08 02          	cmp    DWORD PTR [ebp+0x8],0x2
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
  8049c7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
```

## E42.6 — 0x4930E0 與兩層 signed command table 的具體約束

**研究問題：**進入 callback 後，哪些命令可以到 global handler，哪些一定不能冒稱完整？

**分析結果（第一手／推測區分）：** **N/C**：`0x4930E0` 先讀 payload 的 `WORD` command，`len==0` 返回零，若 `lane!=2` 也不進 `C+0x200`。`lane==2` 從 `C+0x148+0xB8=C+0x200` 取 secondary vptr+4 (`48AAD0`)，依 signed16 `cmd` 使用前端 **16-byte stride** table，default callback `494360`，exception 另有 special override；`494360` tail-jump 到 `[FD2CF8.vptr+4] = 4FDA30`，第二層才採 **8-byte stride** 登記值（E38 index 2→4B7F00, index0x0BD2→4B8DC0）。`0x493170` 初始化 `0xBD5=3029` 個前端 slot，這不是上游 bounds check；`0x4930E0` 在 `len<2` 時讀 WORD 的防護沒有在此函式看到，且兩層對 signed negative / index 超界的 upstream guard 尚缺，不能宣稱漏洞已經可由遠端利用。回傳 `0x80004005` 在本地會走 logging/fallback，不是 Server status。

**剩餘缺口：** 第一層 dynamic overwrite 是否改 index2/0BD2、manager `C` identity、真正收到的 command (尤其 T03 0x13 vs 本地 UI state) 均未經封包 trace 確認。不能把「2 或 0BD2 slot 登記」寫作「選服後 first S2C 2/0BD2」。

**原件指令 `0x4930E0 的 lane==2/this adjust 入口`（VA `0x4930e0`–`0x493160`，`.text raw=VA−0x400C00`）：**

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
  49315e:	c2 10              	ret    0x10
```

**原件指令 `第一層 signed command callback`（VA `0x48aad0`–`0x48ab67`，`.text raw=VA−0x400C00`）：**

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
  48ab65:	c2 0c              	ret    0xc
```

**原件指令 `第二層 signed command callback`（VA `0x4fda30`–`0x4fdab2`，`.text raw=VA−0x400C00`）：**

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
  4fdab0:	c2 0c              	ret    0xc
```

## E42.7 — key1 0x495610：實際 caller 組、連線開關與狀態提交

**研究問題：**誰呼叫 key1 Connect，第三參數如何控制舊連線及本地條件？

**分析結果（第一手／推測區分）：** **N（相對 E41 的功能鏈增量）**：原件精確 CALL rel32 候選中 `0x495610` 有六個 upstream `0x6D6377/6424/6508/65C8/670C/696C`；在 `0x6D6350` 實際已對齊的 caller，先檢查 `[ESI]` 來源物件非零，從 C++ 短字串／heap 分流取出 `+0x0C` 所指字串，將 `FB1318` 作 Client pointer、字串作 host、第三參數 `0` 呼叫 `495610`；如果返回零，走後續通知/錯誤處理，不能認為一定已完成 socket handoff。`0x6D64C0` 的另一 caller 傳第三參數 `1`，且只有 connect 返回非零才繼續準備後續本地資料；所以第三參數 `0/1` 在多個入口實際不同。`0x495610` 若第三參數非零，先重設 `FD8C00/FD8BFC` 及對管理器 virtual+0x20 進行狀態更新；它對舊 `BF60` 可能調整，再以 transport map key1、port `0x20DF` 及第四參數 application lane2 建立連線。Connect 成功設 `[C+BF60]` 為新 Conn*；失敗回傳0、按其分支清理/通知；`0x20DF` 只能稱原生 legacy literal，非新 Server 部署建議。

**剩餘缺口：** 六個 caller 的所有 UI 行為/原版登入結果條件未與 T03 0x13 handler 閉合；沒有實際目標主機 authority、是否預先 DNS/重試、key1 first over-the-wire frame 的證明。

**原件指令 `key1 caller 之一（第三參數 0）`（VA `0x6d6350`–`0x6d6383`，`.text raw=VA−0x400C00`）：**

```asm
  6d6350:	55                   	push   ebp
  6d6351:	8b ec                	mov    ebp,esp
  6d6353:	83 ec 0c             	sub    esp,0xc
  6d6356:	56                   	push   esi
  6d6357:	8b f0                	mov    esi,eax
  6d6359:	8b 06                	mov    eax,DWORD PTR [esi]
  6d635b:	85 c0                	test   eax,eax
  6d635d:	0f 84 8f 00 00 00    	je     0x6d63f2
  6d6363:	83 c0 0c             	add    eax,0xc
  6d6366:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d636a:	72 02                	jb     0x6d636e
  6d636c:	8b 00                	mov    eax,DWORD PTR [eax]
  6d636e:	6a 00                	push   0x0
  6d6370:	50                   	push   eax
  6d6371:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6376:	50                   	push   eax
  6d6377:	e8 94 f2 db ff       	call   0x495610
  6d637c:	85 c0                	test   eax,eax
  6d637e:	75 69                	jne    0x6d63e9
  6d6380:	8b 15 18       	mov    edx,DWORD PTR ds:0xfb1318
```

**原件指令 `key1 caller 之二（第三參數 1）`（VA `0x6d64c0`–`0x6d6516`，`.text raw=VA−0x400C00`）：**

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
```

**原件指令 `key1 0x495610 重要 gate / Connect / BF60 assign`（VA `0x4956b8`–`0x4957a0`，`.text raw=VA−0x400C00`）：**

```asm
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
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
```

## E42.8 — key0/key2 0x4957C0：雙 Connect／舊 key1 暫存及 local send

**研究問題：**是否同時建立兩條 Conn？失敗哪一條時如何釋放？local 0x0001 能否稱 wire first？

**分析結果（第一手／推測區分）：** **N**：`0x4957C0` 通過 global manager vtable+0x18 依序建立 **key0 / port 0x20E0 / lane2** 和 **key2 / port 0x20DE / lane2**，分別保存 `EDI`、`EBX`。`EDI==0` 跳 `0x4959B0`，若 `EBX` 已非零則有其專屬管理器 virtual+0x20 清理；`EBX==0` 跳 `0x49597E` 並對已成功的 `EDI` 清理、返回0。兩者都成功時，若存在舊 `[Client+BF60]`，本地 enqueue 老 key1 `WORD 0x007E, 2 bytes` 並寫 `Conn+A0B0=1`，然後置 `BF60=0`。此時已有連線切換的 native 局部條件，但 **enqueue 非保證 send**。接著整理本地 `0x39` bytes buffer 以 `WORD 0x0001` 起頭，向 key0 的管理器 virtual+0x10 local send，後用 virtual+0x14 處理兩個新 Conn，將 `[Client+BF64]=EDI / [Client+BF68]=EBX`。不得把 `[BF68]` 一律視作 Conn*，E36 已發現不同狀態復用。此函式回傳1代表本地流程分支完成，不能代表已收到 Server 首次回覆。

**剩餘缺口：** key0/key2 真實 socket 完成連線、WSASend scheduler 封裝後第一個 wire frame、不同 socket 相互送達次序、key1 close 的完成 ack、重試與遠端答覆仍未知。Conn A080=2 是應用 lane，不是 map key。

**原件指令 `兩個原生 vtable+18 Connect 與早期失敗條件`（VA `0x4957d0`–`0x49582d`，`.text raw=VA−0x400C00`）：**

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
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
```

**原件指令 `舊 key1 本地 007E / A0B0 pending`（VA `0x495832`–`0x495872`，`.text raw=VA−0x400C00`）：**

```asm
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
```

**原件指令 `key0 本地 0x0001 buffer/0x39 local send`（VA `0x49587d`–`0x49595b`，`.text raw=VA−0x400C00`）：**

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
```

**原件指令 `兩個獨立失敗返回區塊`（VA `0x49597e`–`0x4959e5`，`.text raw=VA−0x400C00`）：**

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
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b e5                	mov    esp,ebp
  4959e2:	5d                   	pop    ebp
  4959e3:	c2 04              	ret    0x4
```

## E42.9 — 0x66C090 選服/流程 callback 的上游 gate 深入

**研究問題：**哪些可證的 predicate 真正讓 0x4957C0 被叫用？能否追成 T03 0x13 結果？

**分析結果（第一手／推測區分）：** **N（本次真正新增上游判斷）**：`0x66C090` 不是 Connect 函式；它從入口 object+0xF0/+0xF4 的 nested pointer `+0xCC/+0xDC/+0x20` 取兩個本地值，透過 `0x5078C0`、`0x507750` 取得 `EBX`、`ESI` 兩個結果。`F94294!=0 && EBX!=0 && ESI!=0` 時於 `0x66C1A7` call `4957C0`；若前述條件不滿足，會在 `0x66C21D` 使用 `EBX==4`、`EBX==0`、`EBX==5` 的分支，另有 `ESI!=0` 且非那些值的 `0x66C247` call `4957C0`。此處兩個 call 都預先 `push ESI`，但之後**未在 call 後立即使用 EAX 作為成功條件**；所以不能把 `4957C0` 的 return 1 當成 `66C090` 立刻進入下一 UI 的證據。`0x66C1AC..C1CB` 反而檢查入口 object 的 `+F0 → +CC → +DC`；另一分支 `0x66C24C` 走 `0x42C530` 本地結果寫至 `D63DCC`。`0x5078C0/507750` 在本段未逐項跨 UI / T03 所有欄位解釋，故 EBX=4/5 只能稱本地判斷碼，不能直接當登入 result code。

**剩餘缺口：** 尚未從 wire S2C command `0x0013` / T03 response 的具體 writer 證明 F94294、EBX、ESI 正是登入成功及特定 server choice；尚未閉合資料來源的唯一性。只可把它當「條件式到兩條 Connect」原生分支，不等於已知 Server 必回哪個 opcode。

**原件指令 `0x66C090 入口、本地查值與 5078C0/507750`（VA `0x66c090`–`0x66c150`，`.text raw=VA−0x400C00`）：**

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
  66c14f:	75                 	jne    0x66c17b
```

**原件指令 `F94294 && EBX && ESI 第一種 Connect gate`（VA `0x66c17b`–`0x66c1d1`，`.text raw=VA−0x400C00`）：**

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
  66c1d0:	8b             	mov    ecx,DWORD PTR [esp+0x20]
```

**原件指令 `EBX 4/0/5 特例／第二種 Connect gate`（VA `0x66c21d`–`0x66c274`，`.text raw=VA−0x400C00`）：**

```asm
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
  66c271:	c2 04 00             	ret    0x4
```

## E42.10 — first inbound 與 RR-0005 所需一條真正玩家閉環：三個不足證據的分界

**研究問題：**完整第一筆封包的方向/長度/回覆、key 關係、Client 畫面改變是否都能由本次 BIN 獨立證明？

**分析結果（第一手／推測區分）：** **N/C/U 嚴格分離**：E40 原件已支援在 receive completion 成功時 `806CF0→807B40` 解析成 packet+8，並依 `Conn+A080` 入 `FC10D0`；E41/E42 在 manager+4 正向物件確為 `C+8` 且 lane=2、payload 有效、前端 slot 未覆寫的前提下，`80486D→4930E0→48AAD0→494360→4FDA30` 才把某個 command 交給 `4B7F00`（index 2）或 `4B8DC0`（index 0xBD2）。`4B7F00` 在 handler 自己從 param1 讀 DWORD `+2` 等資料寫入 `F93930`、字串和多個 state，並有 key0/key2 local C2S producer；`4B8DC0` 有兩段文字及 key2 local response。**不能由上游表註冊值和本地 sender 反推這兩個 command 是第一筆、必然會到達或是哪個 Conn key 先收到**。`0x4957C0` 的最初 local `0x0001/0x39` 不能直接視為 on-wire first frame，因 scheduler、封包模式 `Conn+A02C`、IOCP pending 和跨 socket 競爭。T03 的 `0x13` 與前端命令表、選服 choice UI 的動態鏈仍缺 direct BIN writer/consumer，所有 server-owned 內容只能列待定。此輪不對 T03 原稿越權提升/認領。

**剩餘缺口：** **停止條件 B**：本次十個子段已完成；剩餘的正向 manager+4 setter、`0x5078C0/507750` 完整業務來源、T03 0x13 資料到 `0x66C090` 的實際 writer、逐 Conn first WSASend/receive 時序、對應 UI effect / runtime pcap，均沒有足夠原生證據閉合。下次 E43 若仍只有同一 BIN，可以針對這些阻塞做更精確的別名追蹤；涉及官方 Server response/實際 wire 仍需合法動態測試資料，不能靠靜態搜尋宣稱不存在。

**原件指令 `S2C success IOCP 喂給 parser`（VA `0x806df2`–`0x806e23`，`.text raw=VA−0x400C00`）：**

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
```

**原件指令 `packet pool producer：由 Conn+A080 app lane 入 FC10D0`（VA `0x807d7f`–`0x807db2`，`.text raw=VA−0x400C00`）：**

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

**原件指令 `dispatcher 命令 nibble / fallback 邊界`（VA `0x4fda30`–`0x4fda63`，`.text raw=VA−0x400C00`）：**

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
```

**原件指令 `index2 handler 的第一段讀取及 state writer`（VA `0x4b8038`–`0x4b8088`，`.text raw=VA−0x400C00`）：**

```asm
  4b8038:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b803f:	8b 57 02             	mov    edx,DWORD PTR [edi+0x2]
  4b8042:	89 15 30 39 f9 00    	mov    DWORD PTR ds:0xf93930,edx
  4b8048:	75 2b                	jne    0x4b8075
  4b804a:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8051:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x3
  4b8058:	03 00 00 00 
  4b805c:	e8 2f 95 02 00       	call   0x4e1590
  4b8061:	68 80 cc bc 00       	push   0xbccc80
  4b8066:	e8 af a2 3d 00       	call   0x89231a
  4b806b:	83 c4 04             	add    esp,0x4
  4b806e:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8075:	6a 14                	push   0x14
  4b8077:	8d 47 0c             	lea    eax,[edi+0xc]
  4b807a:	50                   	push   eax
  4b807b:	6a 15                	push   0x15
  4b807d:	68 f2 38 f9 00       	push   0xf938f2
  4b8082:	e8 77 bf 3d 00       	call   0x893ffe
  4b8087:	83               	add    esp,0x10
```

## 11. 結論：本段以「功能鏈完整度」而非函式數量作標準

### 11.1 確認的非孤立整鏈（*conditional*，不是 first wire）

```text
[main/Client C] -> C+8 -> 0x6DEB40 framework init
                               | -> manager FBA7CC initial allocation and state
                               |    manager+4 positive writer UNKNOWN
                               v
0x6DFA50 -> 0x6DFBE0 -> manager+4 == C+8 ?  [necessary gate, UNPROVEN]
   -> vptr[C+8]+30 -> 490FE0 -> holder (C+8)+140 = C+148
      -> 804740 -> FC10D0 pop -> holder.vptr[0] = 4930E0
         -> app lane==2 -> C+200.vptr+4 = 48AAD0
           -> first-tier 16B/entry callback (default 494360; override possible)
             -> FD2CF8.vptr+4 = 4FDA30
               -> second-tier 8B/entry callback (2 / 0xBD2 conditional)

[choice-like branch 66C090]
  -> 5078C0 / 507750 local results + F94294 / EBX / ESI gates
    -> 4957C0 -> key0 Connect (20E0), key2 Connect (20DE)
      -> old key1 local 007E; key0 local 0001/57B; store BF64/BF68
[other caller pathways] -> 495610 -> key1 Connect (20DF), store BF60
  -> 806CF0 -> 807B40 -> FE3358 packet block -> FC10D0 app lane
  -> conditional Client callback as above
```

此圖僅代表各局部 BIN 主張已連成**條件式可達**架構，並非同一個已捕獲的官方登入 session；其跨線缺口以 `UNKNOWN` 保留。

**有界偽碼：明確標記尚未觀察的必要前置與相依路徑（不是可執行的原版重建）**：

```cpp
// C = 0x4A3041 所使用的 Client 主體；sub = C + 8。
// 本次沒有證明 mgr->field4 何時被設成 sub，故此賦值不能當作已證代碼。
auto *mgr = GetLazyManager_FBA7CC();          // 0x6DFBE0/0x6DF3D0 附近
// 只證明新配置經初始化 +4 初始為零，以及 0x6E9F9C 可再次清零。
if (mgr && mgr->field4 /* UNKNOWN nonzero writer */) {
    auto *sub = mgr->field4;                  // 究竟是否 C+8 仍需 writer 證據
    // vtable+0x30 可能通往 0x490FE0；僅表示已證的條件式 dispatch。
    DispatchIfVtableMatches(sub);
}

// 0x66C090：以下 result A/B 不擅自命名為登入成功碼或伺服器狀態。
int resultA = Function_5078C0(/* native inputs, not fully typed */);
int resultB = Function_507750(/* native inputs, not fully typed */);
if (Global_F94294 != 0 && resultA != 0 && resultB != 0) {
    Function_4957C0(/* arguments from this particular callsite */);
} else if (resultA != 0 && resultA != 4 && resultA != 5 && resultB != 0) {
    Function_4957C0(/* alternative callsite, inspect actual arguments */);
}
// 此精簡條件樹只保留兩條正向連線分支；不代表全 0x66C090 CFG。

// 條件性的入站路由；connLane 由 Conn+A080 提供，與 transport key 互不等同。
if (packet_is_valid && manager_field4_is_Client_C_plus_8 && connLane == 2) {
    // pop/pump 0x804740 / virtual call 0x80486D
    // 0x4930E0 → 0x48AAD0 → (default 0x494360) → 0x4FDA30
    // 16-byte 前端與 8-byte 後端均須受實際索引、覆寫和有效長度限制。
    DispatchConditionalNativeCommand(payload, length, command);
}
```

`resultA/resultB` 的 if 判斷是對兩個 `0x4957C0` 正向入口的摘要，並非對 `0x66C090` 全部 return/失敗路徑的形式還原；其完整 compare/jump 序列與 CALL 參數仍以上文 E42.9 原生指令為準。

### 11.2 RR5 玩家情境與欄位完成度矩陣

| 玩家情境/來源 | 目前 Client 本地可證 | C→S（原生有界） | S→C / handler | UI 與切線 | 完成度 |
|---|---|---|---|---|---|
| 已知 key1 Connect caller | 6D63xx 多處 host string / 參數 0/1 → 495610 | key1 port `20DF` 的 Connect，送出 first wire 未證 | 未知 | BF60 成功持有 Conn*；登入 UI 依賴未證 | 部分 N |
| `66C090` 條件成立 | local 5078C0/507750 + F94294/EBX/ESI predicate | 4957C0 兩個 Connect；key0 local `0001/57B`；old key1 local `007E` | 任何 first S2C 尚未追到 | BF64/BF68 有條件持有新 Conn；真實 UI 改變不明 | 部分 N |
| 收到某條 conn 的有效應用 payload | 806CF0 / 807B40 → FC10D0 | handler 可再 local enqueue，不能推 first wire | lane=2 且 manager+4=C+8 時可進 4930E0/48AAD0 | 命令可改 state；畫面更新/選服映射未知 | C |
| index 2 已註冊並被實際觸發 | global stride8 index2 = 4B7F00 | key0/key2 多筆 local sender，彼此 wire 先後未證 | handler param1 讀 state，非首筆證據 | 非必然登入結果 | 部分 N+C |
| index 0xBD2 已註冊並被實際觸發 | global stride8 index=0xBD2 | key2 local `0BCC`／`0BD1` 由另一 handler | 兩段文字 / state 可能更新 | UI effect not bound | 部分 N+C |

### 11.3 不把四類缺口互相推卸

1. **Client 待逆向（T02）**：`manager+4` 非零 writer/alias、callback lifetime、`F94294 / EBX / ESI` 由真實登入/選服 callback 寫入的精確鏈、key0/1/2 分包與首發首收、Connect close/retry/slot 同步、signed command 上游 bounds。
2. **Server 待開發**：依已驗 Client wire 欄位實作相容回覆、端點部署/帳號和選服規則；**不能把 `0x20DF/20E0/20DE` 舊 Client 常數當網路部署建議**，也不能猜官方 response bytes。
3. **跨功能待整合**：T03 主責登入 `0x13`／UI、角色清單及選角的業務結果，T02 提供連線/框架/dispatcher；T01 共用限定 FULL-PASS 和 S00 GAP-NET-0002 須依流程正式整合，不能自行改他人筆記或台帳。
4. **待遊玩驗證**：缺原版 KR 實際 end-to-end authorized client/socket trace、確切 Server 回覆、各連線 first wire、畫面轉換與斷線重試；靜態 `N` 不等於可玩。

### 11.4 下個正式段號 E43 接手的精確原生問題（避免重做 E40/E41）

- 對正向 `manager+4` writer 先分析 `0x6DF3D0 / 0x6DFBE0 / 0x6DFA50` 的 alias 驗證與傳入 manager pointer 的間接 setter；已證 `0x6E9F9C` 是清零 writer，不能用它代替正向 writer。針對 `6E2850` COM/vtable 註冊、`6DEB40` 初始化到 manager 及 teardown 的確切條件作導引。
- `0x66C090` 的 `0x5078C0` / `0x507750`：追出 EBX / ESI 的真正語義與 producer，向 T03 `0x13` 及 server choice UI 方向做跨 Task 限定引用；逐條封包要確認 wire 命名空間，不能只由 `EBX=4/5` 命名登入狀態。
- 從 `0x495610/4957C0` per-Conn 建立後沿 `0x8068B0` WSASend scheduler / `A02C` mode / `0x806CF0` WSARecv 拆清楚 real first wire 的條件與競爭；要求真實 pcap/受權動態 trace 才能確定遠端回覆/全局順序。
- 逐一核對 `C+0x208 + cmd*16` 的非 initializer writer，釐清 index 2 / 0xBD2 的 override 可能性；signed negative index / len<2 是本地 bounds 證據缺口，**不是已確認 exploitable vulnerability**。

### 11.5 本次與 E41 比較的實質增量

- E41 已得次級物件/虛擬轉送；**E42 新增 manager 初始 `+4=0` 與 shutdown `0x6E9F9C` 精確清零 writer**，使「永遠 vptr 可調」的說法更嚴格受生命週期約束。
- 新用原始機器碼從 `0x66C090` 追到**兩個** `0x4957C0` caller 的不同條件分支，並抽出 `F94294`、`EBX/ESI` predicate；不能把 return 1 自動等同 UI success。
- 同一 BIN 的 `0x495610` 多個 caller 可確認 host string 和第三參數 0/1 的條件差異，不再僅從 Connect 函式自身推論 key1 時序。
- 系統性確認即使各中間元件已可局部連結，**缺正向 manager writer、T03 結果到選服 gate、per-key 第一筆實際 wire**；到第十子段仍未滿 A，所以強制 B 停止，未把重大發現當整段提前停止理由。

## 12. 重現與負面搜尋邊界

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6dfbe0 --stop-address=0x6dfc3a Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6e9f81 --stop-address=0x6e9fb2 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x66c090 --stop-address=0x66c274 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4957c0 --stop-address=0x4959e5 Tartaros.bin
```

**注意：**raw `E8 rel32` 搜索為「候選引用」，可能命中資料中同樣 5 bytes；需核函式指令邊界才能提高為 direct call。對 `manager+4` 的寫入否定搜尋僅涵蓋列出的直接全域 load + 同暫存器 store 模式（以及局部函式調閱），**不是全二進位任意 alias 指標寫入的形式證明**。在沒有原版 Client 執行權限及官方 socket trace 時，`first wire` / `first S2C` / 自動重試及可玩結果**均應維持 U**。

---

**保留原稿及提交狀態**：本檔為單次 E42 完整 10 子段 Markdown，未 Commit/Push，未產生 Git blob；如日後獲授權，目標應是 `extra/roy1` 的 `kr-extra-roy/`，先核對遠端目標分支與競爭變更。RR-0005 仍依首次 main 快照未認領。

