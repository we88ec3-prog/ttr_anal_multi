# KR S00 派工 RR-0001～RR-0008：跨 Task BIN-first 定向研究審計

生成時間：2026-10-29T18:19:52+08:00。

## 來源／限制
- 原件 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪已在容器重新計算。
- GitHub main RR 台帳讀回 blob SHA `6f652f1b763a4198bbc580f86cb9f7703001ffc3`；8 筆皆 KR／QUEUED／PENDING（此項以讀取當時為準）。
- main 比較基準 `5cb495f4561833e0a123bbded14b76266ac1f201`；研究工作 `extra/roy1` 遠端 E01–E18 可供跨參照。此報告未做 RR CLAIMED / SUBMITTED 更新。
- 研究只讀原件，不執行原客戶端，不臆造原生封包、版本相異 offset 或 Server 內部規則。下列 objdump 為限定 VA 視窗，**並非完整 CFG 或 runtime 驗證**。
- `.text` 偏移換算 `raw=VA−0x400C00`；應留意起始於指令中間可能產生錯誤反組譯，僅使用函式入口與已知實際指令邊界。

## 逐 RR 主張矩陣
| RR | Task | 優先 | 本輪直接驗證的程度 | 可交付 S00 的現況 |
|---|---|---|---|---|
| RR-0001 | T02 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0002 | T03 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0003 | T03 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0004 | T02 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0005 | T02 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0006 | T02 | P1 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0007 | T02 | P1 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |
| RR-0008 | T03 | P0 | 原始 BIN 指定入口／限定組語視窗 | 部分來源支援；未達 acceptance criteria |

## 一手機器碼視窗及定向評估

### RR-0001 — 初始連線 framing／第一筆雙向交換
**主責／優先**：T02／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：已有 WSASend、WSARecv/IOCP 與 dispatch 的靜態入口。
**完成條件與缺口**：仍需對每個 connection 綁定第一個 send builder、實際 frame type 與第一個 receive dispatch，並確認 A02C mode 在該次連線的取值。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x8068B0..0x806940`（raw `0x405CB0..0x405D40`）：

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
  80693d:	ff 15 a0       	call   DWORD PTR ds:0xbd25a0

```

`VA 0x806CF0..0x806D80`（raw `0x4060F0..0x406180`）：

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
  806d7f:	8d               	lea    eax,[ebp-0x24]

```

`VA 0x4930E0..0x493160`（raw `0x924E0..0x92560`）：

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

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0002 — 選角 C→S 欄位、S→C 回覆
**主責／優先**：T03／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：歷史 T03 有選角 0x42 輸出及 UI 本地資料鏈，與 E17/E18 scene state 證據分離。
**完成條件與缺口**：必須精確定位接收方向 0x42 的 handler、status/拒絕分支、角色 record 的權威來源、後續 scene handoff，不能把同數值雙向混同。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x4930E0..0x493160`（raw `0x924E0..0x92560`）：

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

`VA 0x47B5C0..0x47B655`（raw `0x7A9C0..0x7AA55`）：

```asm
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6 05 64 0f fc 00  	test   BYTE PTR ds:0xfc0f64,0x1

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0003 — E8/000F 認證與 0x13 結果
**主責／優先**：T03／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：T03 README 指出 E8/000F 字串轉碼和 MD5 文字鏈、0x13 result 與 group/channel 部分已有人核對。
**完成條件與缺口**：補 E8 opaque tail 的 bytes/來源、實際 codepage、0x13 消費者條件、群組陣列界限及連線移交，不可從 AI server 反推。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x4930E0..0x493160`（raw `0x924E0..0x92560`）：

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

`VA 0x495610..0x495690`（raw `0x94A10..0x94A90`）：

```asm
  495610:	55                   	push   ebp
  495611:	8b ec                	mov    ebp,esp
  495613:	83 e4 f8             	and    esp,0xfffffff8
  495616:	6a ff                	push   0xffffffff
  495618:	68 7c 1c 94 00       	push   0x941c7c
  49561d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  495623:	50                   	push   eax
  495624:	83 ec 08             	sub    esp,0x8
  495627:	53                   	push   ebx
  495628:	56                   	push   esi
  495629:	57                   	push   edi
  49562a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49562f:	33 c4                	xor    eax,esp
  495631:	50                   	push   eax
  495632:	8d 44 24 18          	lea    eax,[esp+0x18]
  495636:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49563c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  49563f:	33 ff                	xor    edi,edi
  495641:	83 ce ff             	or     esi,0xffffffff
  495644:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  49564b:	75 21                	jne    0x49566e
  49564d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  495654:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  495658:	e8 33 bf 04 00       	call   0x4e1590
  49565d:	68 80 cc bc 00       	push   0xbccc80
  495662:	e8 b3 cc 3f 00       	call   0x89231a
  495667:	83 c4 04             	add    esp,0x4
  49566a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  49566e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  495675:	89 3d c0 41 f9 00    	mov    DWORD PTR ds:0xf941c0,edi
  49567b:	75 25                	jne    0x4956a2
  49567d:	b8 01 00 00 00       	mov    eax,0x1
  495682:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  495688:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  49568c:	e8 ff be 04        	call   0x4e1590

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0004 — A02C 初始化與 0BBB fallback
**主責／優先**：T02／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：A02C 初始化 0x805D02、0x8061A0 條件處理是既有疑點。
**完成條件與缺口**：追全部 alias writer 與 mode 切換 CFG，確認是否真有 plaintext fallback 以及必須同時成立的 failure 條件；單一 comparison 不足。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x805CE0..0x805D55`（raw `0x4050E0..0x405155`）：

```asm
  805ce0:	c4 04 3b             	les    eax,FWORD PTR [ebx+edi*1]
  805ce3:	fb                   	sti
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
  805d50:	89 86 50 a0 00     	mov    DWORD PTR [esi+0xa050],eax

```

`VA 0x806160..0x8061E0`（raw `0x405560..0x4055E0`）：

```asm
  806160:	00 77 14             	add    BYTE PTR [edi+0x14],dh
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
  80618e:	c2 08 00             	ret    0x8
  806191:	cc                   	int3
  806192:	cc                   	int3
  806193:	cc                   	int3
  806194:	cc                   	int3
  806195:	cc                   	int3
  806196:	cc                   	int3
  806197:	cc                   	int3
  806198:	cc                   	int3
  806199:	cc                   	int3
  80619a:	cc                   	int3
  80619b:	cc                   	int3
  80619c:	cc                   	int3
  80619d:	cc                   	int3
  80619e:	cc                   	int3
  80619f:	cc                   	int3
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0

```

`VA 0x8061E0..0x806250`（raw `0x4055E0..0x405650`）：

```asm
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
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
  80624f:	8b                 	mov    ecx,DWORD PTR [ebx]

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0005 — 登入結果→Connect／關閉重試／slot
**主責／優先**：T02／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：Connect 的兩個已知 native function 入口可以直接重新定位。
**完成條件與缺口**：需交叉 T03 0x13 result、UI 選擇狀態、endpoint、socket 關閉／重試及每次 Connect 的首送 frame；不可當作官方部署 port 政策。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x495610..0x4956B0`（raw `0x94A10..0x94AB0`）：

```asm
  495610:	55                   	push   ebp
  495611:	8b ec                	mov    ebp,esp
  495613:	83 e4 f8             	and    esp,0xfffffff8
  495616:	6a ff                	push   0xffffffff
  495618:	68 7c 1c 94 00       	push   0x941c7c
  49561d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  495623:	50                   	push   eax
  495624:	83 ec 08             	sub    esp,0x8
  495627:	53                   	push   ebx
  495628:	56                   	push   esi
  495629:	57                   	push   edi
  49562a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49562f:	33 c4                	xor    eax,esp
  495631:	50                   	push   eax
  495632:	8d 44 24 18          	lea    eax,[esp+0x18]
  495636:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49563c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  49563f:	33 ff                	xor    edi,edi
  495641:	83 ce ff             	or     esi,0xffffffff
  495644:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  49564b:	75 21                	jne    0x49566e
  49564d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  495654:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  495658:	e8 33 bf 04 00       	call   0x4e1590
  49565d:	68 80 cc bc 00       	push   0xbccc80
  495662:	e8 b3 cc 3f 00       	call   0x89231a
  495667:	83 c4 04             	add    esp,0x4
  49566a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  49566e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
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

```

`VA 0x4957C0..0x495860`（raw `0x94BC0..0x94C60`）：

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
  49585e:	c7 80      	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	   

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0006 — 0x2633/0x22D7 壓縮 parser 與校驗失敗
**主責／優先**：T02／P1。
**既有研究（來源記錄，未重新認證其全部語意）**：原生 parser 0x807B40 與錯誤/物件處理 0x807E50 可直接核對。
**完成條件與缺口**：追 marker 與長度的真實座標、0x727190 返回/失敗、checksum 不符寫入、pool/free 所有權與對 Server 相容端影響；絕不能假設 checksum mismatch 自動斷線。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x807B40..0x807BE0`（raw `0x406F40..0x406FE0`）：

```asm
  807b40:	55                   	push   ebp
  807b41:	8b ec                	mov    ebp,esp
  807b43:	83 e4 f8             	and    esp,0xfffffff8
  807b46:	6a ff                	push   0xffffffff
  807b48:	68 be 98 90 00       	push   0x9098be
  807b4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807b53:	50                   	push   eax
  807b54:	51                   	push   ecx
  807b55:	b8 24 20 00 00       	mov    eax,0x2024
  807b5a:	e8 11 8b 0a 00       	call   0x8b0670
  807b5f:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b64:	33 c4                	xor    eax,esp
  807b66:	89 84 24 20 20 00 00 	mov    DWORD PTR [esp+0x2020],eax
  807b6d:	53                   	push   ebx
  807b6e:	56                   	push   esi
  807b6f:	57                   	push   edi
  807b70:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b75:	33 c4                	xor    eax,esp
  807b77:	50                   	push   eax
  807b78:	8d 84 24 38 20 00 00 	lea    eax,[esp+0x2038]
  807b7f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  807bdd:	c7 44 24     	mov    DWORD PTR [esp+0x20],0x4
  807be4:	 

```

`VA 0x807BD0..0x807C55`（raw `0x406FD0..0x407055`）：

```asm
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
  807c44:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  807c4b:	75 2f                	jne    0x807c7c
  807c4d:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  807c54:	c7       	mov    DWORD PTR [esp+0x2040],0x0
  807c5b:	    

```

`VA 0x807E50..0x807ED0`（raw `0x407250..0x4072D0`）：

```asm
  807e50:	55                   	push   ebp
  807e51:	8b ec                	mov    ebp,esp
  807e53:	81 fe 00 10 00 00    	cmp    esi,0x1000
  807e59:	76 06                	jbe    0x807e61
  807e5b:	32 c0                	xor    al,al
  807e5d:	5d                   	pop    ebp
  807e5e:	c2 04 00             	ret    0x4
  807e61:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807e64:	56                   	push   esi
  807e65:	50                   	push   eax
  807e66:	8d 4f 08             	lea    ecx,[edi+0x8]
  807e69:	51                   	push   ecx
  807e6a:	e8 61 5d 09 00       	call   0x89dbd0
  807e6f:	83 c4 0c             	add    esp,0xc
  807e72:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  807e75:	b0 01                	mov    al,0x1
  807e77:	5d                   	pop    ebp
  807e78:	c2 04 00             	ret    0x4
  807e7b:	cc                   	int3
  807e7c:	cc                   	int3
  807e7d:	cc                   	int3
  807e7e:	cc                   	int3
  807e7f:	cc                   	int3
  807e80:	55                   	push   ebp
  807e81:	8b ec                	mov    ebp,esp
  807e83:	83 e4 f8             	and    esp,0xfffffff8
  807e86:	83 ec 2c             	sub    esp,0x2c
  807e89:	53                   	push   ebx
  807e8a:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  807e8d:	56                   	push   esi
  807e8e:	57                   	push   edi
  807e8f:	8d 44 24 14          	lea    eax,[esp+0x14]
  807e93:	50                   	push   eax
  807e94:	ff 15 18 21 bd 00    	call   DWORD PTR ds:0xbd2118
  807e9a:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807e9e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807ea1:	8d 7c 3f 02          	lea    edi,[edi+edi*1+0x2]
  807ea5:	89 79 04             	mov    DWORD PTR [ecx+0x4],edi
  807ea8:	33 c9                	xor    ecx,ecx
  807eaa:	8b c7                	mov    eax,edi
  807eac:	ba 04 00 00 00       	mov    edx,0x4
  807eb1:	f7 e2                	mul    edx
  807eb3:	0f 90 c1             	seto   cl
  807eb6:	f7 d9                	neg    ecx
  807eb8:	0b c8                	or     ecx,eax
  807eba:	51                   	push   ecx
  807ebb:	e8 7d 5d 07 00       	call   0x87dc3d
  807ec0:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807ec3:	83 c4 04             	add    esp,0x4
  807ec6:	33 f6                	xor    esi,esi
  807ec8:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  807ecb:	85 ff                	test   edi,edi
  807ecd:	7e 43                	jle    0x807f12
  807ecf:	8d             	lea    edx,[esp+0x10]

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0007 — S→C command-to-scene/auth/roster/selection dispatch
**主責／優先**：T02／P1。
**既有研究（來源記錄，未重新認證其全部語意）**：channel2 dispatcher 在 0x4930E0；部分 actor/scene handler 已有歷史原稿。
**完成條件與缺口**：需建立 auth、roster command2、selection 各自受哪個 switch/callback 轉派的地址、狀態前置與 payload 邊界，不枚舉全部命令。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x4930E0..0x4931A0`（raw `0x924E0..0x925A0`）：

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
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80          	mov    edx,0x494780

```

`VA 0x47B5C0..0x47B655`（raw `0x7A9C0..0x7AA55`）：

```asm
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6 05 64 0f fc 00  	test   BYTE PTR ds:0xfc0f64,0x1

```

**判定**：本輪驗證這些入口的機器碼真實存在與局部控制條件；但未具備該 RR 所需的完整 wire/consumer/時序因果鏈。保留 `UNKNOWN`，不能標為 `SUBMITTED` 或 `ACCEPTED`。

### RR-0008 — 選角回覆→scene key/writer→tutorial
**主責／優先**：T03／P0。
**既有研究（來源記錄，未重新認證其全部語意）**：E06/E08/E13/E16 與 E17/E18 已有 XML/seq、索引與 local writer；EndCutScene 可重入。
**完成條件與缺口**：必須從 0x42 S→C 接收 handler 追寫入 object+0x248 或 scene pair；否則 1001/1 只是 XML 靜態映射，不是首登 wire 或必然行為。

**本輪直接 BIN 證據（`objdump`，有限視窗）**：

`VA 0x47B5C0..0x47B655`（raw `0x7A9C0..0x7AA55`）：

```asm
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c