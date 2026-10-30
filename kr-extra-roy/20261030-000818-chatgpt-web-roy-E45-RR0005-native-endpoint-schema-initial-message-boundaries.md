# E45 — RR-0005／KR T02：`0x0013/0x007A` → IPv4 文字 endpoint → 選服 Connect → 初始 queue/frame/receive 的有界 native 契約（目標導向 10 子段）

**分析者**：chatgpt-web roy；**研究記錄**：2026-10-30T00:08:18+08:00。本檔 E45.1–E45.10 是**同一個正式 E45 段號**。使用者明確採用研究目標導向最多 10 個大型分析子段：**不得因局部重大發現提前停段**。本次停止條件 **B，完成第 10 個分析子段，但未得到授權執行原版 Client／無官方 network trace，無法證明 live first-wire 與整個 runtime 連接順序**。十段分別查不同的原生上／下游，逐段列明問題、Assembly、可證與未證，不以「搜尋函式」代替分析。

## 研究目標、版本、協作狀態

**端到端目標**：依 E44 已追通的 `S2C native command 0x0013 / 0x007A → 4C3080 → FE1B54 choice records → 66C090 → 4957C0`，繼續解出 **(a)** S2C 記錄長度與分支限制、**(b)** 真正交給 Winsock Connect 的 endpoint bytes 與選服 gate、**(c)** key0/key2 成功／失敗與回收、**(d)** 所謂初始 C2S queue 封包到 framing／WSASend 的條件、**(e)** server 首回覆進入 decoder／callback 的可達條件與 runtime manager identity。若無 live trace，逐條列出明確可執行的本地動態驗證條件，而非填造伺服器回覆資料。

**第一手原件**：本次直接讀 `/mnt/data/Tartaros.bin`，大小 `12,472,320` bytes，重新核算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386，`.text VA=0x401000, raw=0x400`、`.rdata VA=0xBD2000, raw=0x7D0600`、`.data VA=0xD61000, raw=0x95E800`。本檔指令來自 `objdump -d -M intel` **對原始 PE 檔直接反組譯**；反編譯資料及 E40–E44 歷史稿只作路徑導航。靜態閱讀，**沒有執行／附加／修改原版 Client，沒有 pcap 或官方 Server binary**。`N` = 本段 BIN bytes／指令可核實；`C` = 有明確 runtime 前置的條件性鏈；`U` = 未證或需要獨立動態資料；`H` = 合理但尚未閉合假說。沒有 T01 FULL-PASS 或 S00 RR ACCEPTED 的自動資格。

**GitHub 基準**：同一對話沿用此前開工完整讀取的 `main=43c51f579cada3aa6257eb8467f65af281c3585b`、`extra/roy1=34d1a55b21df78ac1c025872e641fe23dfe52645`；本輪使用者**明確要求研究完成後 Push Git**，需在寫入前核對遠端 branch lease 並讀回 Git blob，批次提交所有可取得、屬自己的、尚未提交完整 E41–E45 原稿（若確實尚未上傳），**只推 `extra/roy1` 的 `kr-extra-roy/`，不得推 main、RR 台帳或他人 Task**。RR-0005 先前核對為 `PENDING/QUEUED; claim=null; submission=null`，本輪未獲正式認領授權；`Git Push != RR CLAIMED`。具體提交結果在完成外部操作後另行記錄，**本稿先不預填成功 SHA**。

## 核心新結論（精確、有限）

- **N（E45 新）**：E44 只寫 `record+0xC` 為「endpoint 候選字串」；現在自 BIN 精確證明 `0x4C3080` 從每個十位元組 child 的 `+4/+5/+6/+7` 讀四個 octet，對 `.rdata 0xBFB050` 的格式字串 `%d.%d.%d.%d` 使用 `0x4C4330` 格式化；`0x507610` 將其複製到建構中的 `0x60`-byte record 之 `+0x0C`，`0x507B10` 將整個 record 原樣 append，`0x507750` 回傳此 `record+0x0C`，UI 選取後 `0x4957C0` 把同一地址傳入 key0 和 key2 connect。**Client 使用由 inbound octets 組成的點分十進位 IPv4 ASCII endpoint**，不是 UI label，也不是憑舊配置猜的主機名。這是原生 build→store→lookup→Connect 的新閉合有界資料鏈。
- **N（E45 新）**：`record+4` 從 `507610` 的 ECX 入口寫入，而該 ECX 由 `4C3107` 的 `BYTE child[8]` 產生且有 `child[8]!=0` guard。`record+8` 為 `child[9]`（由 EDX 傳入）而 `record+0` 是 `child[0..1]` 的 WORD。故 UI `5078C0` 的 gate DWORD 並非未知 Server 後製的任意 `record+4`：可追至**同一 10B child 的 byte8**；這也解釋 UI 對值 `0/4/5` 的不同判斷，但語意／服務角色仍未知。
- **N/C**：`0x4C37A0` 在 mode 0 及非空 UTF16 文字前提，從 `payload+0x92` 解析 `[payload+0x1C]` 個 outer groups；每 group header 3B，`child_count` 個 10B，沒有在 `0x4C3080` 找到拿 callback 的 `len` 逐項檢查。因此可列 **必要資料長度關係**，但不能稱為 Client 已實作的安全 bounds 允收規格。mode 5 與其他值有獨立 CFG，不應混成成功 schema。
- **N/C**：`0x4957C0` 對**同一**文字 endpoint 分別用 manager virtual+0x18 建立 transport key0/`0x20E0` 與 key2/`0x20DE`（兩者 lane 參數 2）；只有兩個 Conn* 均非零才本地 queue `0x0001`、長度 `0x39` 到 key0，並保存 `Client+BF64/+BF68`。前段對第一筆 wire 的嚴格限制依舊：**local enqueue ≠ WSASend ≠ 最早 wire frame**。

---

## E45.1 — `0x0013` success/mode5/error 的 CFG 與 byte 讀取域

**研究問題**：0x13 的成功分支可以說到多大程度？`len` 是否真有保護各個高位 offset 的檢查？

**原生結果／條件**：`4C37CE` 把 callback 第一 stack 參數當 payload；最初即讀 `WORD [payload+0x20]`，mode 分支讀 `[payload+0x16]`。mode=5 跳 `4C382D..4C3944`（本地物件與訊號）；mode!=5 且 byte16!=0 跳 `4C3A30`（`login failed: %d` literal at C072E4、建立/派發本地事件），唯 mode=0 且 `payload+2` UTF-16 字串非空才進 `4C3979..4C3A10`，取 `+0x17/+0x18/+0x86/+0x87/+0x8C/+0x90/+0x1C/+0x92`。本地分支的最大 fixed data read 為 `BYTE [+0x90]`（若忽略被 unbounded 文字 scan 的範圍），純形式上的 fixed-offset bytes 必須至少 0x91；若 group_count>0 還需後續變長內容。直接 scan `+2` 文字沒有以入口長度限制其搜尋範圍。

**剩餘缺口與反證邊界**：在此函式的已檢視入口至 mode0 parser call 範圍內沒有 `cmp [ebp+0xc]` 對 payload len 的安全門檻。不可由此宣稱原版 Server 一定安全接受任意長度，也不可把 0x91 當成完整有效 packet schema；若 UTF-16 無 NUL，會越過任何固定下界。mode5 不是 parser branch。

**有界 schema 算式**：`needed_fixed_read_end >= +0x90 + 1=0x91 bytes`（指 0x13 mode0 分支已觀察的固定 offset）；除此還需要 `0x13 payload+2` 的 UTF16 NUL，及 `+0x92` 起至少 `sum(3+10*count_i)` bytes；本算式是研究者推算的**必要記憶體讀取上界**，不是原始 Client 檢查。


### Native assembly — 0x13 入口、調試字串與模式 gate（VA `0x004C37CE..0x004C3834`；`.text` raw `0x000C2BCE..0x000C2C34`）

```asm
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
```

### Native assembly — mode5 的本地處理直到跳離（VA `0x004C3876..0x004C3951`；`.text` raw `0x000C2C76..0x000C2D51`）

```asm
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
```

### Native assembly — mode0 文字與高位欄位 / 共享 parser（VA `0x004C3951..0x004C3A30`；`.text` raw `0x000C2D51..0x000C2E30`）

```asm
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
```

### Native assembly — 非零且非5 狀態與尾部（VA `0x004C3A30..0x004C3B78`；`.text` raw `0x000C2E30..0x000C2F78`）

```asm
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
  4c3b77:	e8                   	.byte 0xe8
```

## E45.2 — `0x007A` adapter 與變長列表的精確迴圈／長度模型

**研究問題**：0x13 和 0x7A 能共用的最小記錄 layout 是什麼？outer count 及 subcount 從哪裡讀，會否阻擋溢出？

**原生結果／條件**：`4C3C10` 的入口 `[payload+2] DWORD=outer_count`、`ECX=payload+6`；`4C37A0` mode0 用 `[payload+0x1C]` 和 `payload+0x92`。二者進同一 `4C3080(ECX=groups, stack1=count)`。這個 parser `4C30BE` 讀 group_id WORD、`4C30C9` 讀 child_count BYTE，`4C30C1` 先加3，內圈每筆讀 `child+4..+9` 並在 `4C30FF` 加10；`4C3133..4C313E` 迴圈至 child_count，`4C3140` outer_count--，最後本地事件 `0xF4243`。`0x4C30A5 call 4C4240` 先操作資料表；不能無證據把它命名為 parse bounds。

**剩餘缺口與反證邊界**：此函式沒有以第二個 stack 參數表示可用 byte length 的設計；它收到的 stack arg 是**outer group count**。沒有 upstream `callback len` 的逐筆 remaining guard 原生證據。`outer_count=0` 走 event 不讀 group；`child_count=0` 只前進3 bytes；對非零 count，所需長度 `header3 + each child10` 累加，且仍未處理整數溢位、超大數量或短包的動態行為。不能直接用此推定官方 Server 的完整部署包。

**形式必要長度模型**：`0x7A: total>=6 + Σ(3+10*n_i)`；`0x13 mode0: total>=0x92 + Σ(3+10*n_i)`（`n_i` 為每個 group header byte2）；必須另滿足各模式其他已讀固定欄位與 NUL 文字。`0x7A` header count 讀取本身至少要求6 bytes。此為靜態 **READ footprint**，不是引擎已有的 `validate_length()`。


### Native assembly — 0x7A 轉交共享列表 parser（VA `0x004C3C10..0x004C3C30`；`.text` raw `0x000C3010..0x000C3030`）

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
  4c3c28:	cc                   	int3
  4c3c29:	cc                   	int3
  4c3c2a:	cc                   	int3
  4c3c2b:	cc                   	int3
  4c3c2c:	cc                   	int3
  4c3c2d:	cc                   	int3
  4c3c2e:	cc                   	int3
  4c3c2f:	cc                   	int3
```

### Native assembly — 列表 group/child 迭代及 completion event（VA `0x004C3080..0x004C316B`；`.text` raw `0x000C2480..0x000C256B`）

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

### Native assembly — 0x13 使用不同 offset 的共同 parser call（VA `0x004C39F8..0x004C3A1C`；`.text` raw `0x000C2DF8..0x000C2E1C`）

```asm
  4c39f8:	e8 5c 01 3d 00       	call   0x893b59
  4c39fd:	89 9f a0 68 00 00    	mov    DWORD PTR [edi+0x68a0],ebx
  4c3a03:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  4c3a06:	83 c4 0c             	add    esp,0xc
  4c3a09:	50                   	push   eax
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
```

## E45.3 — 最重要新結論：`child[4..7]` → 點分 IPv4 ASCII → `record+0xC` → Connect

**研究問題**：E44 尚不明確的 `record+0xC` 究竟是什麼？四個位元組如何跨 helper、record append、查找而不變？

**原生結果／條件**：`4C30E2..4C30F5` 逐一 `movzx` child offset4/5/6/7；`4C30F6 push 0xBFB050`，`4C3102 call 4C4330`，此 wrapper 呼叫 `0x891E89`（其引數包含 output、20-byte cap 與格式）。BIN `.rdata[0xBFB050]` 明確是 ASCII `%d.%d.%d.%d\0`。輸出位於 `4C3080` 之 stack `esp+0x18`；`4C3115` 將 &output 作為 507610 的第四個 stack 參數。`507641..50765F` 把這來源複製到 `[ebp-0x64]` 的 0x14-byte buffer，而 `[ebp-0x70]` 是本地 record 起點，故 `-0x64 - (-0x70)=+0xC`。`50771E lea eax,[ebp-0x70]` 傳到 `507B10`，後者 `mov ecx,0x18; rep movsd` 複製 exactly 0x60 bytes。`507750` 在匹配時用 `lea output, [record+0xC]`、`66C1A0/66C240` push 同一指標至 `4957C0`，後者把它當兩次 Connect 的 host arg。這證成**從 S2C 4 octets 到 2 條 socket 使用的文字 IP**，不必臆測是 UI label。

**剩餘缺口與反證邊界**：建構時 string formatting 使用 `%d`（輸入 0..255 零擴展）、正常情況 output 可為形如 255.255.255.255 的文字；究竟 `0x891E89` 的 NUL、截斷或語系行為及 `0x893B59` 實際 CRT 慣例需另查函式／實際 trace。此處證明 Client **來源與文字形式**，沒有證實 DNS 解析後實際 sockaddr bytes，也不證官方主機值或 IP 可用。尤其 `0x4957C0` 能接任意字串並不表示每個記錄都是公開合法地址。

**原生資料 bytes**（`.rdata` raw = `VA−0x401A00`）：`0xBFB050` raw `0x7F9650`：`25 64 2e 25 64 2e 25 64 2e 25 64 00 45 51` = ASCII `%d.%d.%d.%d\0`。

**record 來源矩陣（僅 `507610` 建構之 0x60-byte 值）**：`record+0 DWORD <- child[0..1] WORD zero-extension`；`record+4 DWORD <- child[8] BYTE zero-extension (ECX)`；`record+8 DWORD <- child[9] BYTE zero-extension (EDX)`；`record+0xC..0x1F <- formatted ASCII IP text, bounded destination 0x14B`；其餘 slot 帶全域 lookup／其他輔助字串，不擅定義欄位。


### Native assembly — 4 octets、格式字串、輸出與 subrecord 交給 writer（VA `0x004C30DB..0x004C3130`；`.text` raw `0x000C24DB..0x000C2530`）

```asm
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
  4c312f:	8b                   	.byte 0x8b
```

### Native assembly — 輸出文字格式化 wrapper（VA `0x004C4330..0x004C4348`；`.text` raw `0x000C3730..0x000C3748`）

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
```

### Native assembly — record source fields、+0xC 20-byte copy（VA `0x0050763E..0x00507665`；`.text` raw `0x00106A3E..0x00106A65`）

```asm
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
  507664:	83                   	.byte 0x83
```

### Native assembly — 0x60-byte append，非 alias（VA `0x00507B10..0x00507B74`；`.text` raw `0x00106F10..0x00106F74`）

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

### Native assembly — record+0xC address resolver的命中/返回（VA `0x00507750..0x005078B8`；`.text` raw `0x00106B50..0x00106CB8`）

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
  5078b7:	cc                   	int3
```

### Native assembly — 兩條 Connect 共用相同 host pointer（VA `0x004957D0..0x00495815`；`.text` raw `0x00094BD0..0x00094C15`）

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
  495811:	0f                   	.byte 0xf
  495812:	84 67 01             	test   BYTE PTR [edi+0x1],ah
```

## E45.4 — UI choice 二鍵、`record+4` gate 的確切來源、`F94294` 限定負面證據

**研究問題**：選服的 gate 是哪個 S2C byte？是否找到 F94294 的非零直接 writer，使兩條 UI 分支能做實際時序？

**原生結果／條件**：`507610` 在開頭 `507654 mov [ebp-6C],ecx`，從 `4C3107 movzx ecx,byte [child+8]` 來，且只有 `[child+8]!=0` 的 branch 呼叫此 writer；它儲存成 `record+4 DWORD`。`5078C0` 以 matching group/record 查回此欄位，`66C090` 將其放 EBX，另 507750 找 host 放 ESI；`66C17B..66C273` 依 `[F94294]!=0` 和 EBX 不同值進 4957C0 或本地 UI fallback。針對 `.text` 中 literal little-endian 地址 `0xF94294` 的完整 byte-occurrence scan 只有 **`0x4E16C1`（直接 clear）和 `0x66C180`（gate read）**；這是嚴格限定 **直接絕對地址 operands** 的 writer read result，不是全域所有 indirect alias 的窮盡結論。

**剩餘缺口與反證邊界**：對於 UI 特定事件 `0x709/0x70A/0x578` 的實際玩家先後、`F94294` 是否被間接 alias 或 memset 寫成非零、不同 `record+4` 值的完整業務語意，仍須通用 dataflow 或動態證據。尤其 `record+4` 值由 child[8] 非零才能 append，這不等同它只有 1，也不能把 4/5 直接解釋成「封鎖／滿載／維護」而無證。

**直接 literal-xref byte 掃描**：`0xF94294` 的 exact DWORD occurrences at instruction data offsets = `0x004E16C1`, `0x0066C180`. 掃描本 PE `.text` 的 4-byte 序列，不代表所有解碼指令都確認或任何 indirect write 都沒有；本組二位置經附近反組譯確認。


### Native assembly — UI 資料 / event to selector（VA `0x0066B910..0x0066B985`；`.text` raw `0x0026AD10..0x0026AD85`）

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
  66b983:	e8                   	.byte 0xe8
  66b984:	b8                   	.byte 0xb8
```

### Native assembly — UI 2-key record resolver（VA `0x0066C090..0x0066C17E`；`.text` raw `0x0026B490..0x0026B57E`）

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
  66c14f:	75 2a                	jne    0x66c17b
  66c151:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  66c158:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  66c15f:	00 
  66c160:	e8 2b 54 e7 ff       	call   0x4e1590
  66c165:	68 80 cc bc 00       	push   0xbccc80
  66c16a:	e8 ab 61 22 00       	call   0x89231a
  66c16f:	83 c4 04             	add    esp,0x4
  66c172:	83 cf ff             	or     edi,0xffffffff
  66c175:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  66c179:	eb 03                	jmp    0x66c17e
  66c17b:	83 cf ff             	or     edi,0xffffffff
```

### Native assembly — F94294 branch and calls（VA `0x0066C17B..0x0066C273`；`.text` raw `0x0026B57B..0x0026B673`）

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

### Native assembly — direct clear of F94294（VA `0x004E16B3..0x004E16D5`；`.text` raw `0x000E0AB3..0x000E0AD5`）

```asm
  4e16b3:	89 1d 8c 42 f9 00    	mov    DWORD PTR ds:0xf9428c,ebx
  4e16b9:	88 1d 90 42 f9 00    	mov    BYTE PTR ds:0xf94290,bl
  4e16bf:	89 1d 94 42 f9 00    	mov    DWORD PTR ds:0xf94294,ebx
  4e16c5:	89 1d 98 42 f9 00    	mov    DWORD PTR ds:0xf94298,ebx
  4e16cb:	c7 05 9c 42 f9 00 ff 	mov    DWORD PTR ds:0xf9429c,0xffff
  4e16d2:	ff 00 00 
```

## E45.5 — 同一 IPv4 host 的 key0/key2 Connect 成敗、port 與舊 Conn 資源

**研究問題**：當 UI 選中的文字 endpoint 進 4957C0，兩條連線如何編號、先後呼叫、失敗回傳及舊連線處理？

**原生結果／條件**：`4957D0` 取 `[FBA854]` manager vtable+0x18，`4957DB..4957EA` 以 **host pointer EBX** 和 port `0x20E0`、transport key0、application lane2 建第一 Conn；`4957EC..495803` 同 EBX 配 port `0x20DE`、key2、lane2 建第二。`495807` 檢查 key0 result=0 走 `4959B0`，`49580F` 若 key2=0 走 `49597E`（其中有 manager vtable+0x20 和錯誤文字）；兩個都非零才走 `495817`。成功後若 `Client+BF60` 有舊 Conn，`495838 call 8063E0`、`495853 call 8060D0` local enqueue 舊Conn WORD 0x007E、設 `oldConn+A0B0=1`、清 `Client+BF60`；再準備新本地 payload；`49594F/495959` 對兩新 Conn 各作 vtable+0x14，最後 `49595B..495962` 寫回 `Client+BF64=key0Conn/Client+BF68=key2Conn`。

**剩餘缺口與反證邊界**：固定 port 是 KR client literal，不是 Server 部署推薦。`Conn pointer != connection established`（可能 async 與中途連線）。若 key0 成功/key2 失敗，局部分支只證錯誤回調/清理，不代表整個 socket lifetime 可免 leak；E35 已對條件性 orphan 做過研究。本段沒官方輸出封包 trace；亦不能以 CPU 指令先呼叫 key0 認定 wire first packet 一定來自 key0。


### Native assembly — 兩個 Connect vtable+0x18及兩個 failure gate（VA `0x004957C0..0x0049581F`；`.text` raw `0x00094BC0..0x00094C1F`）

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
  49581e:	74                   	.byte 0x74
```

### Native assembly — 舊 BF60 Conn 0x007E queue/close gate（VA `0x00495820..0x0049587D`；`.text` raw `0x00094C20..0x00094C7D`）

```asm
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
```

### Native assembly — 保存新 Conn 並返回（VA `0x0049592A..0x0049597E`；`.text` raw `0x00094D2A..0x00094D7E`）

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
```

### Native assembly — key2 fail/error return（VA `0x0049597E..0x004959B0`；`.text` raw `0x00094D7E..0x00094DB0`）

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
```

### Native assembly — key0 fail/error return（VA `0x004959B0..0x004959DF`；`.text` raw `0x00094DB0..0x00094DDF`）

```asm
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
  4959db:	e8                   	.byte 0xe8
  4959dc:	21                   	.byte 0x21
  4959dd:	b6 3f                	mov    dh,0x3f
```

## E45.6 — 成功 Connect 後第一個本地 C2S payload：`0x0001`、57 bytes、來源限定

**研究問題**：這段成功 Conn 之後到底準備哪個 payload；是否有第一個 wire bytes 的 native 證據？

**原生結果／條件**：`49587D..4958B0` 初始化 stack payload：WORD 0x0001 at `EBP-0x40`，後續 0/1 常數；`4958B3` 取 404BA0 全域物件 `+67E0 DWORD` 放 `EBP-3E`，`4958C1..4958EC` 把全域文字 `[+67E4]` / `[+67FA]` 複製到兩個各最多0x0A 的 byte buffers；`4958F1..495927` 從 `+6898/+6899/+68A0` 複製 status/5 bytes/DWORD。`49592A..49593D` 透過 `[FBA854].vtable+0x10` 傳 `key=0`, `payload ptr=&EBP-0x40`, `length=0x39` (57 bytes) local send；後續 vtable+0x14 設連線相關 active 狀態，`BF64/BF68` 寫回。這比只喊 opcode0x0001 更確實地確認來源／大小，但這裡**不是 sendto/WSASend**。

**剩餘缺口與反證邊界**：目前未證送出 57-byte local buffer 在同一時間立即離開 Winsock；其排入連線 FIFO、background scheduler/IOCP 及 frame mode 包裝會改變實際傳輸 bytes。也不宜將 `0x0001` 推為所有連線最早 application command（舊 key1 0x007E 可能排在前），更不能由此聲稱 Server 第一個 S2C 的 opcode。完整 payload 某些字串的編碼/是否 NUL、固定 0x39 的所有 byte 位置還需對 CRT copy 定義補證。


### Native assembly — packet stack 0x0001 與固定/文字欄位（VA `0x0049587D..0x0049592A`；`.text` raw `0x00094C7D..0x00094D2A`）

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
```

### Native assembly — manager virtual send→57B + socket 激活（VA `0x0049592A..0x0049596B`；`.text` raw `0x00094D2A..0x00094D6B`）

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
  495968:	b8                   	.byte 0xb8
  495969:	01 00                	add    DWORD PTR [eax],eax
```

### Native assembly — local packet queue entry 的 length/data（VA `0x008060D0..0x0080618F`；`.text` raw `0x004054D0..0x0040558F`）

```asm
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  80618e:	c2                   	.byte 0xc2
```

## E45.7 — 從本地 queue 經 Conn mode 到 framing／WSASend 的有條件鏈

**研究問題**：為何 C2S local enqueue 不能等同 first wire？兩種 frame encoding、write scheduler、error conditions 分別何在？

**原生結果／條件**：`8060D0` 有 `Conn+A0A4<=0x12C` backpressure gate、`packet len<=0x1000` 的 bounded memcpy；之後 call `806060` 追加待送 queue。`804A40` 針對 active Conn `A0AC!=0` 呼叫 `8061A0` flush queue；根據 `Conn+A02C` signed BYTE 在 `806202` 取得 mode，mode 0 走 `807A70` plaintext `0x1A68`，非零嘗試 `807830` 的 `0x0BBB` packet/加擾，`807830` 返回0時 fallback plaintext。`807830` 檢查 `payload_len+6<=0x1000`、buffer <=0x4000，並在 local buffer 頭寫 magic word + length；`8068B0` 只在 buffer pointer/length 非零及 Conn 未 A0A8 close 時呼叫 imported `WSASend`。`WSASend` 可回 immediate／IO_PENDING（0x3E5），pending 不表示 wire complete。

**剩餘缺口與反證邊界**：`Conn+A02C` 除已核零初始化／非零候選 alias 外尚缺完整 runtime writes；兩條 socket 的實際 frame 類型、時序、第一個 WSASend completion 與 wire serialization 都不能只靠 static CFG 決定。`807830` 封裝失敗可能 fallback，不可說使用 0BBB 必然。`804A40` flush gate `A0B8` unfinished send count 和 delayed recycle 仍須配合 E34，不可用「queued first」預測 first-wire。

**frame 類型≠native command**：外層 marker `0x0BBB`、`0x1A68`，局部 C2S command `0x0001` 為不同層；不能把 0BBB 當作選服命令。


### Native assembly — C2S local enqueue 容器、長度及背壓（VA `0x008060F5..0x0080618F`；`.text` raw `0x004054F5..0x0040558F`）

```asm
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
  80618e:	c2                   	.byte 0xc2
```

### Native assembly — mode 分支/加擾與 fallback（VA `0x008061F6..0x00806257`；`.text` raw `0x004055F6..0x00405657`）

```asm
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b                   	.byte 0x3b
  806255:	9e                   	sahf
  806256:	74                   	.byte 0x74
```

### Native assembly — 0BBB encoder guard 及 header magic（VA `0x00807867..0x008078B6`；`.text` raw `0x00406C67..0x00406CB6`）

```asm
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
```

### Native assembly — scheduler flush/close gates（VA `0x00804AC3..0x00804B9D`；`.text` raw `0x00403EC3..0x00403F9D`）

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
  804b9b:	81                   	.byte 0x81
  804b9c:	be                   	.byte 0xbe
```

### Native assembly — 實際 WSASend / pending（VA `0x008068B0..0x0080699B`；`.text` raw `0x00405CB0..0x00405D9B`）

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
  80699a:	c2                   	.byte 0xc2
```

## E45.8 — WSARecv/IOCP → framed command → FC10D0 queue → 0x0013 第二層處理的條件

**研究問題**：能否從 socket 回覆推到 0x13 的實際 handler？兩個層級的長度／lane／table gate 如何影響結論？

**原生結果／條件**：`806CF0` receive IOCP success 到 `806E08 call 807B40`，`807B40` 先讀 frame payload len WORD（`0<len<=0x1000`），觀察 `0x2633/0x0BBB/0x1A68/0x22D7` marker 和 header size (4/6/8)，做 frame `decoded packet`；`807D9E` 用 `Conn+A080` 把 packet 塞 FC10D0 application lane。`490FE0` 主循環 holder `Client C+0x148` 透過 `804740→80486D` vptr[0]；當該 vptr 為 C05AEC、lane==2、payload WORD 0x0013、FD2CF8 首層 default 和第二層 receiver 非零時，`4930E0→48AAD0→494360→4FDA30→4B7EC0→4C4670→4C37A0`。同理 0x007A→4C3C10。`0x4C3220` 真正安裝二級 handler；`0x4C2F90→4B7D50` 註冊 receiver。

**剩餘缺口與反證邊界**：這是充分列明依賴的**static conditional reachability proof**，不是收到 socket reply 的 runtime witness。若 Conn+A080 非2、frame checksum 失敗、payload 空、handler 被覆寫/receiver 消失、Client 不在該 mainloop，鏈不成立。沒有證明某次選服後「Server 第一筆 S2C」一定是0x13或0x7A，也不能拿 `0x13` 作每一 Conn/transport key 的固定協定入口。


### Native assembly — IOCP receive success→parser caller（VA `0x00806DE4..0x00806E23`；`.text` raw `0x004061E4..0x00406223`）

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
```

### Native assembly — receive header marker/length parser（VA `0x00807B85..0x00807C44`；`.text` raw `0x00406F85..0x00407044`）

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
```

### Native assembly — decoded packet enqueue + app lane（VA `0x00807D7F..0x00807DB2`；`.text` raw `0x0040717F..0x004071B2`）

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

### Native assembly — UI mainloop sends C+148 holder to pump（VA `0x0049197F..0x00491990`；`.text` raw `0x00090D7F..0x00090D90`）

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6                   	.byte 0xf6
```

### Native assembly — packet callback dynamic call（VA `0x00804837..0x00804877`；`.text` raw `0x00403C37..0x00403C77`）

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
```

### Native assembly — S2C command lane gate（VA `0x004930E0..0x0049315F`；`.text` raw `0x000924E0..0x0009255F`）

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

### Native assembly — secondary table registration（VA `0x004C2F94..0x004C2FDA`；`.text` raw `0x000C2394..0x000C23DA`）

```asm
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
  4c2fd9:	c3                   	ret
```

## E45.9 — manager C+8 identity、登記／生命週期：能驗什麼，不能宣告什麼

**研究問題**：`C+8` 對 callback holder 已證但 manager+4 的動態接收者到底是誰？本 E45 能把重要 missing source gate 再縮小嗎？

**原生結果／條件**：`4A3041` 建構 local C，`4A304B lea esi,[esp+34]` 是同一 stack `C+8`，`4A305A call 6DEB40`（ESI=this-like C+8），`6DEB40` 在 callback vptr+0x20 成功後 lazy init manager `FBA7CC` 並將同一 ESI 反覆 push 給 `6E1860/6E1930/...` 註冊 manager 的 +0x398/+0x39C 等 callback slots；`6DEBCB..6DEC33` 繼續 callback 登錄、註冊 event hooks。但**這些 field 不是 manager+4**。另一 `6E4F90` 第二 stack arg 經 `6E5530→6E65A0`、`6E6871 mov [manager+4],esi` 為正向 writer，最後可 6DFA50→vptr+0x30 進 mainloop，已在 E43 證實。此段新增負面型別區分：`6DEB40→6E1860` 寫 `manager+0x398`、`6E1930` 寫 `manager+0x39C`，**不能把它們誤用作 `manager+4` 的身份證明**。`6DEB40` 的啟動還有多個 virtual call/早退。

**剩餘缺口與反證邊界**：`6E4F90` 外部 arg 是否就是此 `C+8` 或由 `vtable+0x40` 輸出，需要精確 caller/active session 答案；`manager+0x398` 是另一欄。只因 6DEB40 以 C+8 註冊其他 manager slots，**不能宣稱 manager+4=C+8 在當次收包時成立**。shutdown `6DEC90` 與 `6E9F9C` 可能清除指標；沒有 outstanding IO 的生命周期保證。這是保留已驗與未驗的明確阻塞，而非擅以相似偏移補缺。


### Native assembly — Client C+8 實際建立與 manager 註冊（VA `0x004A3041..0x004A306B`；`.text` raw `0x000A2441..0x000A246B`）

```asm
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
```

### Native assembly — 6DEB40 manager 多 callback slot 註冊（VA `0x006DEB40..0x006DEC15`；`.text` raw `0x002DDF40..0x002DE015`）

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
```

### Native assembly — manager+0x398 / +0x39C 明確不同 writer（VA `0x006E18F3..0x006E1923`；`.text` raw `0x002E0CF3..0x002E0D23`）

```asm
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

### Native assembly — 通用初始化 call 6E65A0（VA `0x006E5525..0x006E5540`；`.text` raw `0x002E4925..0x002E4940`）

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

### Native assembly — manager+4 真正正向 writer（VA `0x006E6843..0x006E6883`；`.text` raw `0x002E5C43..0x002E5C83`）

```asm
  6e6843:	c0 a3 cc a7 fb 00 80 	shl    BYTE PTR [ebx+0xfba7cc],0x80
  6e684a:	3d 09 3d d6 00       	cmp    eax,0xd63d09
  6e684f:	00 8b b5 04 ff ff    	add    BYTE PTR [ebx-0xfb4b],cl
  6e6855:	ff 8b f8 74 10 68    	dec    DWORD PTR [ebx+0x681074f8]
  6e685b:	c8 a4 fb 00          	enter  0xfba4,0x0
  6e685f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6865:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e686a:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6871:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  6e6874:	8b 3d 48 22 bd 00    	mov    edi,DWORD PTR ds:0xbd2248
  6e687a:	74 0c                	je     0x6e6888
  6e687c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6881:	ff d7                	call   edi
```

### Native assembly — manager+4 清空/teardown（VA `0x006E9F81..0x006E9FB8`；`.text` raw `0x002E9381..0x002E93B8`）

```asm
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
  6e9fb5:	0f                   	.byte 0xf
  6e9fb6:	84                   	.byte 0x84
  6e9fb7:	b1                   	.byte 0xb1
```

## E45.10 — 端到端矩陣、反證與本地驗收需求：停止 B

**研究問題**：十個子段後是否達成最初的端到端目標？若未達成，如何向 E46 或本地研究者交付可操作證據缺口？

**原生結果／條件**：本輪獲得有 native bytes 支援的**新增閉合子鏈**：`S2C cmd 0x13(mode0)/0x7A → 4C3080(child[4..7]) → 4C4330("%d.%d.%d.%d") → 507610(record+0xC, record+4 from child[8]) → 507B10(0x60B append) → 507750(record+0xC pointer) → 66C090→4957C0(key0/0x20E0,key2/0x20DE) → [兩Conn非NULL] local queue key0 0x0001/0x39B → 8060D0→804A40→8061A0→WSASend (mode/socket scheduler conditional)`。上行收包 `WSARecv/IOCP→807B40→FC10D0→callback→0x13` 在 lane、receiver、table、有效 frame 下同樣有條件成立。這將 E44 的 endpoint 未知改成精確的四 octets 來源與 IPv4 ASCII 格式；仍不能證 live handoff 時序和 Server 的第一包值。已在前九子段逐項核對重要 caller/callee/CFG、bytes、運行 gate、失敗/清理和反證。

**剩餘缺口與反證邊界**：沒有原版 Server/pcap、也未獲使用者准許執行/patch KR Client，不能證兩 Conn 的 first wire/first reply；管理者 `+4` active C+8 身份與真正多執行緒時序仍 U。雖得到新的重大子鏈，但使用者本輪 A 條件是**完整目標**，尚未達成；本段已滿 **10 個大型子段**，依停止規則 **B** 結束，後續另由 E46 接力，而不延伸 E45.11。

**玩家情境驗收矩陣**：

| 事件 | Client Native 本段可證 | C2S／S2C | Server 接口與未證 | 分級 |
|---|---|---|---|---|
| 收到 `0x13` mode0 | 非空 UTF16、成功分支進 list parser | S2C 0x0013 是 decoded command WORD | 必須有 mode/文字/列表與可用 frame；第一筆 socket reply 未知 | N/C |
| 收到 `0x7A` | +2 outer count / +6 list 進同 parser | S2C 0x007A native command | 不知道是否一定先前收到 0x13 | N/C/U |
| 解析四 bytes host | child[4..7] → ASCII `%d.%d.%d.%d` → `record+0xC` | inbound 資料造成 Client host string | Server 生成 endpoint 政策與實際原版 IP 未知 | N |
| 玩家選擇記錄 | 同兩鍵查 `record+4` gate、`record+0xC` host | 沒有直接在選擇函式送獨立業務命令；調 Connect | UI 狀態/非零 gate時序未證 | N/C |
| 雙 Conn 建立 | 同 host 的 key0 20E0、key2 20DE，lane2 | C2S key0 local 0x0001/57B | 並非已送到 Server，wire header依 Conn mode | N/C/U |
| 失敗/重試 | key0/key2 NULL 分支、舊 BF60 0x007E、partial cleanup | 可能有舊局部封包 | 無法驗證首次連線完成/重試全序 | N/C/U |
| 取得第一個回覆 | 收包成功時可進 app FIFO、二層 dispatcher | first S2C identity/時序 UNKNOWN | 需 pcap/受控 server trace | C/U |

**四類缺口／明確解除條件**：

1. **Client 待逆向**：`manager+4` 在真實 active session 是否等於 C+8；`Conn+A02C` 的正向 mode writer／first frame；`0x13/0x7A` callback 長度驗證鏈與 utf16 NUL；所有 runtime callback overrides；`record+4` 各值含義及 F94294 alias。解除：調用圖與到達點證據、或在取得用戶明確執行授權後產出精確 VA 和 object identity 的 runtime trace。
2. **Server 待開發**：在可被 Client 接受的已證 read footprint 上構造合理的 S2C group/child payload，與可接通的 IPv4 endpoint/port；登入政策與重試策略另以 ADR 建模，非官方猜測。由 S00 規格設計負責，不能此時宣告 STABLE。
3. **跨功能待整合**：T02 此有界 native 網路與 E44 source，T03 的 command 0x13 UI／認證前置，T01 FULL-PASS claims（目前並未單憑這份報告升格），S00 `GAP-NET-0002`。此稿不動他人 owner/catalog。
4. **待遊玩驗證**：合法授權前不得啟動 Client；需同一 session 的 Connect attempts、socket id/Conn* vs key mapping、實際 WSASend buffers and completion、WSARecv decoded first command、UI 轉移/失敗對照。沒有這些不得發佈 live first message order / 可玩驗收。

**E46 交接優先序**：`6E4F90` 第二參數的真實 C+8 來源→每個 Conn 的 A02C alias writer/首個 wire header→`4C37A0` 分支中 len/guard 上游→UI 可能拒絕 Connect 的 gate/回復路徑，盡量使用 native hook 具體影響；若無合法 trace，把缺口明交本地驗證，勿重跑 E45 的四 octets string discovery。


### Native assembly — 以原始 byte 重驗 IPv4 data origin/format（VA `0x004C30E0..0x004C312F`；`.text` raw `0x000C24E0..0x000C252F`）

```asm
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

### Native assembly — 以原始 byte 重驗 record+0xC copy/append（VA `0x0050763E..0x0050765F`；`.text` raw `0x00106A3E..0x00106A5F`）

```asm
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
```

### Native assembly — 以原始 byte 重驗 record→Connect（VA `0x0066C17B..0x0066C1B2`；`.text` raw `0x0026B57B..0x0026B5B2`）

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
  66c1af:	8b                   	.byte 0x8b
  66c1b0:	82                   	.byte 0x82
  66c1b1:	f0                   	lock
```

### Native assembly — 以原始 byte 重驗 key0/key2 first local send（VA `0x004957D0..0x0049580F`；`.text` raw `0x00094BD0..0x00094C0F`）

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
```

### Native assembly — 以原始 byte 重驗 first local payload length（VA `0x0049592A..0x0049596B`；`.text` raw `0x00094D2A..0x00094D6B`）

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
  495968:	b8                   	.byte 0xb8
  495969:	01 00                	add    DWORD PTR [eax],eax
```

---

## 原始證據重現／版本與責任界線

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -d -M intel --start-address=0x4c37a0 --stop-address=0x4c3b80 Tartaros.bin
objdump -d -M intel --start-address=0x4c3080 --stop-address=0x4c316b Tartaros.bin
objdump -d -M intel --start-address=0x507610 --stop-address=0x507741 Tartaros.bin
objdump -d -M intel --start-address=0x507b10 --stop-address=0x507b74 Tartaros.bin
objdump -d -M intel --start-address=0x507750 --stop-address=0x5078b8 Tartaros.bin
objdump -d -M intel --start-address=0x4957c0 --stop-address=0x4959df Tartaros.bin
objdump -d -M intel --start-address=0x804a40 --stop-address=0x804c40 Tartaros.bin
objdump -d -M intel --start-address=0x8061a0 --stop-address=0x806260 Tartaros.bin
objdump -d -M intel --start-address=0x807b40 --stop-address=0x807e50 Tartaros.bin
```

數量與證據：恰 10 個研究子段 E45.1–E45.10；所有 ASM 窗口來自本次原生 BIN 而非 GitHub snippets；針對每個窗口已註明入/出參數與有界條件，選用重複片段僅用於跨單元核對；未自稱全函式語意或所有計算分支正式 T01 FULL-PASS。當前研究的「完成」是本輪研究交付，**不是 RR-0005 已正式 CLAIMED/SUBMITTED/ACCEPTED**，GitHub Push 與 S00 台帳是兩套工作。
