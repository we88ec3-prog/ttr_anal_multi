# T16-101 — KR [0x00FAB134] owner / 0x18-byte record writer / quest-list consumer (BIN-first)

- 研究者：chatgpt-web roy；台北時間：20261028-231613。
- 版本：KR Tartaros.bin 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原始 BIN 唯讀，不執行程式。`.text` VA − raw = `0x400C00`；以下地址依原始檔案位元組靜態反組譯。使用原有 T16-100 作導航，不替代實證。
- GitHub 啟動時 main `baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，工作分支 ahead=13, behind=0；不需新 Merge commit。

## 研究問題和已證結果

T16-100 中 `[0x00FAB134]` 指向不同於 `[0x00FB114C]` 的執行期聚合物件。**本段重大新發現**：BIN 確認 `0x4DECE0` 一帶配置與初始化 **0x40-byte owner**，`0x4DED1E` 寫入全域；`0x4B22BC` 直接將 owner 送入 `0x53D840`，後者明確對 owner 的 `+0x10/+0x14` 管理的 0x18-byte 記錄作搜尋／更新，並依輸入位元組填多種欄位。此為 T16-100 缺失的**真實記錄 writer**，但從 caller 的 `[ebp+8]` 取資料不等於已核實是網路 recv handler，須另追其上游及封包 parser。

## 原生確證 owner 生命週期

- `0x4DECDD push 0x40`，`0x4DECE4 call 0x891268` → 初值清零多個欄位 → `0x4DED1E mov [0xFAB134],eax`。owner 0x40 bytes；不能誤讀 `0x4DED1C push 0x18` 為 owner 配置大小，該 push 屬**下一次記憶體配置**。
- `0x4DF048` 取該全域指標，`0x4DF054 call 0x53D590`，`0x4DF05A call 0x89120C`，`0x4DF062` 清空全域。這是可核對的清理鏈。
- owner `+0x10/+0x14` 為 0x18-byte 記錄區間 begin/end；`0x53D840` 使用 `(end-begin)/24` 與每次 `+0x18` 的迴圈搜尋，故不宜把 `[FAB134]` 本身稱為 record array 首地址。

## 分離的 writer

| VA | 原生指令／來源 | 已確認寫入或動作 | 解讀邊界 |
|---|---|---|---|
| 0x4AECF3 | `mov word [ecx+0x30],ax` | `[owner+0x30]`，來源 `[EBX-4]` | 上游用途 unknown |
| 0x4AED3E | `mov word [eax+0x32],dx` | `[owner+0x32]`，來源 `[EBX-4]` | 不得當 quest step |
| 0x4B1C9B–0x4B1CA7 | `[ebx+0]/[ebx+4]/[ebx+8]` | `[owner+0x34]` DWORD、`+0x38` DWORD、`+0x3C` BYTE | 僅原生欄位拷貝，未核實 wire 格式 |
| 0x4B22BC | `push edx; push eax; call 0x53D840` | owner 加上一個 16-bit 參數傳給真正 0x18 record writer | `ESI` 另承載輸入來源；尚需上游身份 |
| 0x53D8BA–0x53D8E6 | `mov [record+...]` | 更新 `+0x14,+0x04,+0x00,+0x02,+0x0A,+0x10,+0x0B` | 由不同寬度原始輸入轉換，後續 type switch 仍待逐支核對 |

### 0x53D840 的可證資料流

1. 參數 `[EBP+8]` 是 owner；讀 `owner+0x14 - owner+0x10` 得位元組範圍，除以 `0x18` 得 record count。函式使用 `ESI` 指向一筆輸入，其來源需追 caller 更前段。
2. 以 `word [input+4]` 對比 `word [record+2]`；找到則復用 record，否則 `0x5F84F0` 擴展資料並選取末筆 record。
3. `word [record+0x14]` 來自 `[EBP+0x0C]`；`record+0x4`、`+0x0`、`+0x2` 等由 `input` 各偏移轉換。`input[0]==2` 時 `record+0x0 = 0x00FF`。
4. `input[1]` 轉成 jump-table index，表示之後存在多種 record payload 型態。尚未完成每個分支的完整語意，因此不能把它定義為 quest accept/complete state。

## 0x500E00、0x5001B6 消費關聯

`0x500EF0` 透過同一 global 的 `owner+0x10/+0x14` 遍歷，與 T16-100 先前消費者一致；`0x5001B6` 亦取相同兩個邊界並檢查 `record+0x14`、`+0x08/+0x06`。即記錄來源存在 writer → 其他列表/檢查 consumer 的有界原生鏈，但由誰觸發各處 reader/UI 刷新尚未證實。

## 研究輪次

- **T16-101 第一輪**：完整二進位 immediate 引用搜索（20 個 bytes 命中候選，逐個區分有效指令）；找到 0x40 owner init/free、明確數筆欄位 writer。已產生重大新主張。
- **T16-101-2 第二輪**：深入 `0x4B22BC → 0x53D840` 的 0x18-byte 真正 record writer、key matching、append/update branch 與消費者。達重大上下游功能鏈；第三輪未啟動（符合 02 門檻，不是跳段）。
- **T16-101-3**：未啟動，理由如上。

## 玩家情境／Server 相容狀態矩陣

| 玩家／事件情境 | Client input / gate | C→S | S→C | 本地 state / UI | Server 相容要求／缺口 |
|---|---|---|---|---|---|
| 載入／初始化 | 0x4DECE0 owner 配置 | unknown | unknown | `[FAB134]` 0x40 owner | 不從初始化猜封包 |
| 收到一筆疑似記錄更新 | 0x4B22BC 的 caller input 尚未溯源 | unknown | **unknown opcode/len/handler** | 0x53D840 依 key 對 0x18 record 更新/附加（原生已確認本地 writer） | 必須將外層 caller 接到 recv dispatcher 才能稱網路狀態 |
| 檢查可用列表 | 0x500E00 使用 owner 的記錄區 | unknown | unknown | 比較 record 數值、略過某些條目 | 實際 NPC/UI 反應待查 |
| Quest16→Quest15 | 未發現 verified quest ID-to-state mapping | unknown | unknown | unknown | 原版 Server 判定及任務前置未知 |

## 反證與限制

- 此 owner 不是 T16-92 `[0xFB114C]` QuestInfo/QuestTalk 主 map；不可以名字相近或 consumer 接近推定同一結構。
- 從 `0x53D840` 的 input bytes 不能反推完整 S→C wire packet；需要明確來源、frame boundary、dispatcher、handler 範圍。
- 沒有原始 Server 程式／網路 capture；不猜測 Quest opcode、Quest16/15 映射或獎勵/解鎖演算法。
- Static xref 範圍是 little-endian 地址 bytes，不涵蓋所有透過暫存器/指標間接訪問的引用；20 hits 不是 20 個驗證過的 caller。

## 下一段 T16-102 建議

優先找 `0x4B22BC` 的外層函式起點、實際呼叫者與輸入 `ESI` 的來源，沿 T02 receive parser/opcode dispatch 串接；必要時先分析 `0x53D840` jump table 的每個 record subtype。再追 `0x500E00` 的具體 NPC/UI 更新與 Quest16→Quest15 資源 ID 相互關係。避免無目標反覆研究通用網路層。

## 原始機器碼／位址證據附錄

以下為直接從 KR BIN `.text` raw 切片反組譯，所有 VA 可依 VA−0x400C00 回算 raw。切片起始有可能落在前指令中間：**只以完整、地址可對齊且與上下文一致的指令判讀**，不得以起頭未對齊 bytes 判定函式語意。

### global owner allocation @ `0x004DECE0` (raw `0x000DE0E0`)

```asm
  4dece0:	30 b1 fa 00 e8 7f    	xor    BYTE PTR [ecx+0x7fe800fa],dh
  4dece6:	25 3b 00 83 c4       	and    eax,0xc483003b
  4deceb:	04 3b                	add    al,0x3b
  4deced:	c6                   	(bad)
  4decee:	74 2a                	je     0x4ded1a
  4decf0:	89 30                	mov    DWORD PTR [eax],esi
  4decf2:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4decf5:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  4decf8:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  4decfb:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  4decfe:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  4ded01:	33 c9                	xor    ecx,ecx
  4ded03:	89 70 20             	mov    DWORD PTR [eax+0x20],esi
  4ded06:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  4ded09:	89 70 28             	mov    DWORD PTR [eax+0x28],esi
  4ded0c:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  4ded0f:	b9 38 00 00 00       	mov    ecx,0x38
  4ded14:	66 89 48 34          	mov    WORD PTR [eax+0x34],cx
  4ded18:	eb 02                	jmp    0x4ded1c
  4ded1a:	33 c0                	xor    eax,eax
  4ded1c:	6a 18                	push   0x18
  4ded1e:	a3 34 b1 fa 00       	mov    ds:0xfab134,eax
  4ded23:	89 35 40 b1 fa 00    	mov    DWORD PTR ds:0xfab140,esi
  4ded29:	e8 3a 25 3b 00       	call   0x891268
  4ded2e:	83 c4 04             	add    esp,0x4
  4ded31:	3b c6                	cmp    eax,esi
  4ded33:	0f 84 65 02 00 00    	je     0x4def9e
  4ded39:	a3                   	.byte 0xa3
```

### owner release @ `0x004DF048` (raw `0x000DE448`)

```asm
  4df048:	8b 35 34 b1 fa 00    	mov    esi,DWORD PTR ds:0xfab134
  4df04e:	3b f3                	cmp    esi,ebx
  4df050:	74 16                	je     0x4df068
  4df052:	8b fe                	mov    edi,esi
  4df054:	e8 37 e5 05 00       	call   0x53d590
  4df059:	57                   	push   edi
  4df05a:	e8 ad 21 3b 00       	call   0x89120c
  4df05f:	83 c4 04             	add    esp,0x4
  4df062:	89 1d 34 b1 fa 00    	mov    DWORD PTR ds:0xfab134,ebx
  4df068:	8b 0d 30 b1 fa 00    	mov    ecx,DWORD PTR ds:0xfab130
  4df06e:	3b cb                	cmp    ecx,ebx
  4df070:	74 0e                	je     0x4df080
  4df072:	8b                   	.byte 0x8b
```

### write 0x30 @ `0x004AECD7` (raw `0x000AE0D7`)

```asm
  4aecd7:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4aecdc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4aece0:	8d 78 20             	lea    edi,[eax+0x20]
  4aece3:	8d 43 fc             	lea    eax,[ebx-0x4]
  4aece6:	e8 b5 f0 08 00       	call   0x53dda0
  4aeceb:	66 8b 43 fc          	mov    ax,WORD PTR [ebx-0x4]
  4aecef:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4aecf3:	66 89 41 30          	mov    WORD PTR [ecx+0x30],ax
  4aecf7:	eb 49                	jmp    0x4aed42
  4aecf9:	3c 06                	cmp    al,0x6
  4aecfb:	75 45                	jne    0x4aed42
```

### write 0x32 @ `0x004AED35` (raw `0x000AE135`)

```asm
  4aed35:	66 8b 53 fc          	mov    dx,WORD PTR [ebx-0x4]
  4aed39:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4aed3e:	66 89 50 32          	mov    WORD PTR [eax+0x32],dx
  4aed42:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4aed46:	40                   	inc    eax
  4aed47:	83 c3 1a             	add    ebx,0x1a
  4aed4a:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  4aed4e:	3b                   	.byte 0x3b
```

### write 0x34/38/3c @ `0x004B1C91` (raw `0x000B1091`)

```asm
  4b1c91:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4b1c94:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4b1c96:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b1c9b:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  4b1c9e:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  4b1ca1:	89 50 38             	mov    DWORD PTR [eax+0x38],edx
  4b1ca4:	8a 4b 08             	mov    cl,BYTE PTR [ebx+0x8]
  4b1ca7:	88 48 3c             	mov    BYTE PTR [eax+0x3c],cl
  4b1caa:	75 24                	jne    0x4b1cd0
  4b1cac:	09 3d 44 92 fd 00    	or     DWORD PTR ds:0xfd9244,edi
  4b1cb2:	c7                   	.byte 0xc7
  4b1cb3:	44                   	inc    esp
  4b1cb4:	24 20                	and    al,0x20
  4b1cb6:	02 00                	add    al,BYTE PTR [eax]
	...
```

### record update caller @ `0x004B22AA` (raw `0x000B16AA`)

```asm
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
```

### record writer 0x53d840 @ `0x0053D840` (raw `0x0013CC40`)

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81                   	.byte 0x81
  53d925:	c9                   	leave
```

### consumer 0x500E00 selected @ `0x00500EF0` (raw `0x001002F0`)

```asm
  500ef0:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  500ef5:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  500ef8:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  500efb:	3b c1                	cmp    eax,ecx
  500efd:	74 18                	je     0x500f17
  500eff:	90                   	nop
  500f00:	66 39 78 14          	cmp    WORD PTR [eax+0x14],di
  500f04:	75 0a                	jne    0x500f10
  500f06:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  500f0a:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  500f0e:	7c 4e                	jl     0x500f5e
  500f10:	83 c0 18             	add    eax,0x18
  500f13:	3b c1                	cmp    eax,ecx
  500f15:	75 e9                	jne    0x500f00
  500f17:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500f1a:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  500f20:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  500f24:	51                   	push   ecx
  500f25:	8d 44 24 24          	lea    eax,[esp+0x24]
  500f29:	8b ce                	mov    ecx,esi
  500f2b:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500f2f:	e8 ec 2d 00 00       	call   0x503d20
  500f34:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500f38:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500f3b:	74 05                	je     0x500f42
  500f3d:	83 c0 10             	add    eax,0x10
  500f40:	eb 02                	jmp    0x500f44
  500f42:	33 c0                	xor    eax,eax
  500f44:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  500f48:	85 c0                	test   eax,eax
```

### another consumer 0x5001B6 @ `0x005001B6` (raw `0x000FF5B6`)

```asm
  5001b6:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  5001bb:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5001be:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5001c1:	3b c1                	cmp    eax,ecx
  5001c3:	74 17                	je     0x5001dc
  5001c5:	66 39 70 14          	cmp    WORD PTR [eax+0x14],si
  5001c9:	75 0a                	jne    0x5001d5
  5001cb:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  5001cf:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  5001d3:	7c 52                	jl     0x500227
  5001d5:	83 c0 18             	add    eax,0x18
  5001d8:	3b c1                	cmp    eax,ecx
  5001da:	75 e9                	jne    0x5001c5
  5001dc:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5001df:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5001e3:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  5001e9:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
```