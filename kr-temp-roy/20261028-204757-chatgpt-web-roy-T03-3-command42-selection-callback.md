# T03-3 — KR 選角確認 UI 事件、原生 command 0x42 送出與三條 caller 比較

日期：2026-10-28T20:47:57.427094+08:00；研究者：chatgpt-web roy；Target：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；不執行、不修補 Client。主題為 T03 登入與選角，不接管 T02/T04/T05/T06。

## 0. GitHub 及上一段去重

上一段 `T03-LOGIN-01/02` 已提交於 T03 工作分支，本段正式命名 **T03-3**，不再用 LOGIN。`main` 於本輪研究前已實際合入工作分支，當時 Merge SHA `1ea811445d8af76bd4e8f532ae49964dd0d9ca65`。本段只新增 command42 的 click callback 條件、三處直接 caller 的分類、送出閘及等待回覆缺口。過去報告早已局部確認 0x4A3B80 的 4-byte buffer；該函式本體不是新發現，**新增是 0x5F46D0 的事件來源與可用旗標控制鏈接及另一入口的差異**。

實測 PE：`.text` VMA `0x401000` raw `0x400`，故所引 `.text` 指令 raw=`VA-0x400C00`；`.rdata` VMA `0xBD2000` raw `0x7D0600`；`.data` VMA `0xD61000` raw `0x95E800`。所有以下 assembly 由原始檔 `objdump -d -Mintel` 定向取出，不是僅由偽碼產生。函式暫名，不能推定 class 或 UI control 正式名稱。

## 1. 第一輪：玩家選角確認 → UI event → command42 → 送出虛擬呼叫

事件物件 `event+0x10` 是本地 UI 事件域，**不等於 wire opcode**：

- `0x5F46D0` 從 `[event+0x10]` 扣 `0x578`、再扣 `0x192`：`0x70A` 進 `0x5F477E`；接著 `dec` 對應 `0x70B` 進 `0x5F46FB`；`0x578` 則進 `0x5F47FF`，不可把這三者混同。
- `0x70A` 分支要求 `[event+8] == [[receiver+0x84]+0x20]`；由 `[[receiver+0x84]+0xCC]+0xDC+0x20` 經有界 null 條件取得 index，null 時暫定 index=-1，再加 1，寫至 `[receiver+0xC8]`。因此它不是任意 Client 玩家 ID；index 的實際 UI 選擇來源還需控件型別補證。
- `0x5F47B3` 呼叫 `0x404BA0`，從所返物件 `+0x6924` 取角色記錄陣列；`unsigned index <=9` 且 `record = base + index*0x210` 的 `[record+0x5C] != 0` 才到 `0x5F47E7`；失敗直接到 `0x5F4903`，不走此路徑的 command42。
- 成立後呼叫 `0x414680`（真實副作用未命名），`push 0`、`push [receiver+0xC8]`，於 `0x5F47F5 call 0x4A3B80`。因此已將「可用記錄 → 選角 C→S builder」建立有界原生 call chain。
- `0x4A3B80` 的 stack buffer 共 4 bytes：`word [ebp-4]=0x0042`、`byte [ebp-2]=arg1`、`byte [ebp-1]=arg2`。條件 `[0xFBA798]==0` 時取 `[0xFBA854]` 物件 vtable `+0x10`，依 `push 4`, `push &buffer`, `push 0` 呼叫。這是 **Client 發送介面調用** 已證，最終 socket write/完整 framing 屬 T02，這裡不自行宣稱所有狀態必然成功送到線上。

## 2. 第二個 click 分支及其他直接 caller 比對

- `0x70B` 選擇分支由同 callback 建立 `F4246` UI 事件，向事件系統投遞；這與 `0x70A` 發 command42 的分支不同。
- `0x578` 分支透過 `receiver+0xBC/+0xB4/+0xC0/+0xB8` 控件比較，分流 UI 事件及兩種額外 command42 call `0x5F48F7`：其中 `[receiver+0xCC]` 非 0 會阻擋；通過者以 `[receiver+0xC8]` 與第二 byte `0` 或 `2` 呼叫 builder，之後 `[receiver+0xCC]=1`。這兩條 **沒有在該子分支內重複進行 `record+0x5C` 檢查**，不能把 0x70A gate 套用到所有 command42。
- `0x673DA0` 的 UI event `0x578` 有 control identity 對比：`[event+8] == [[receiver+0xC0]+0x20]` 對應建 F42EF；另一 control 對比 `[[receiver+0xDC]+0x20]` 時 `0x673EAA` 以 `(receiver+0xD8, 0)` 呼叫 command42。此路徑**沒有 0x5F46D0 的 +5C gate**，不能認定角色清單有效性一定相同。
- 在 `.text` file range raw `[0x400,0x7D05F0)` 搜尋 5-byte `E8 rel32` 目的地為 `0x4A3B80`，候選呼叫位址恰好三處 `0x5F47F5`, `0x5F48F7`, `0x673EAA`，並經定向反組譯確認；只限 **直接 E8 caller 搜尋**，不排除 indirect call / thunk / 其他 builder。

## 3. 動作矩陣

| 玩家/本地情境 | Client gate | C→S 請求 | S→C / 結果 | 分工 |
|---|---|---|---|---|
| `0x70A` 且控件 identity 相符、index<=9、record+5C非零 | 皆已證 | `0x42` + index byte + `0`，在 FBA798==0 時呼叫 send v+10 with slot0, length4 | **未知**；不能把 fixture 43/69 當原版回覆 | T03/T02 |
| `0x70A` 但 index>9 或 +5C=0 | 此 callback 證實走返回 | 該分支不呼叫 4A3B80 | 未證 | T03 |
| `0x70B` | UI/control 有界 | 建 F4246 事件，不是同一段 42 send | UI 更新狀態仍看 handler | T03/T06 |
| `0x578` 且匹配 receiver+B4/B8，cc=0 | 控件比對、cc閘 | `0x42` + `[receiver+C8]` + `0`/`2`，發送另受 FBA798 gate | 未證 | T03/T02 |
| `0x578` 且匹配 673DA0 的 receiver+DC | 控件比對 | `0x42` + `[receiver+D8]` + `0`，gate相同 | 未證 | T03/T02/T05 |

## 4. 封包及程式語意邊界

已證指令序列是在內存中建立 **little-endian** `42 00 XX YY`。`0x42` 在此函式是 16-bit 命令欄位；未證明這 4 bytes 等於無 framing 的完整 TCP wire packet。`XX` 來自 caller 傳入的低 8 位，`YY` 為 0/2，具體業務意義及 Server 驗證政策未知。`FBA798` 的 writer、物件 `FBA854` 的 virtual target/sock queue 均不能擅自假設。`0x673DA0` 的 UI +DC click 和 `0x5F46D0` 的 0x70A click 沒有證據可以視為同一選角對話框。

## 5. 未完成／後續入口

1. T02：由 `FBA854` 物件 vtable `+0x10` 確認 framing、queue、實際 socket write；`FBA798` producer/狀態。
2. T03：追 `0x5F46D0` 及 `0x673DA0` UI dialog 註冊、初始化、誰觸發 `0x70A`/`0x578`；`receiver+C8/D8/CC` 的初始化與重設、錯誤/重試。
3. T03/T05：從原生 S→C dispatcher 找 command42 對應的**實際**批准/拒絕 handler，角色/連線狀態 writer 與世界/廣場切換入口；目前 **不得**認定 42→43/69 原版 pairing。
4. T04/T06：角色選擇 index 與真實 roster identity、UI 控件身份／資源，避免把 index 或 type 0/2 猜成玩家持久化ID/登入模式。

## 6. 輪次門檻

第一輪已取得完整、可驗證的新 UI callback → record +5C gate → command 42 builder → send interface 鏈接，並額外辨別兩個不共享 gate 的直接 caller，達到 02 文件「重大原生增量」門檻；本段第二、三輪**未啟動**。不稱完整選角端到端可玩，因為接收確認/拒絕及場景轉場尚未查明。

## 7. 原生 x86 disassembly （摘錄，保留對照區間）

### S1 送出建構器

```asm
004a3b80 <.text+0xa2b80>:
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2 08 00             	ret    0x8
```


### S2 UI 事件分派與可用旗標

```asm
005f46d0 <.text+0x1f36d0>:
  5f46d0:	55                   	push   ebp
  5f46d1:	8b ec                	mov    ebp,esp
  5f46d3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5f46d6:	56                   	push   esi
  5f46d7:	8b f1                	mov    esi,ecx
  5f46d9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  5f46dc:	81 e9 78 05 00 00    	sub    ecx,0x578
  5f46e2:	0f 84 17 01 00 00    	je     0x5f47ff
  5f46e8:	81 e9 92 01 00 00    	sub    ecx,0x192
  5f46ee:	0f 84 8a 00 00 00    	je     0x5f477e
  5f46f4:	49                   	dec    ecx
  5f46f5:	0f 85 08 02 00 00    	jne    0x5f4903
  5f46fb:	8b 8e 84 00 00 00    	mov    ecx,DWORD PTR [esi+0x84]
  5f4701:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5f4704:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f4707:	0f 85 f6 01 00 00    	jne    0x5f4903
  5f470d:	8b 81 cc 00 00 00    	mov    eax,DWORD PTR [ecx+0xcc]
  5f4713:	85 c0                	test   eax,eax
  5f4715:	74 0f                	je     0x5f4726
  5f4717:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  5f471d:	85 c0                	test   eax,eax
  5f471f:	74 05                	je     0x5f4726
  5f4721:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  5f4724:	eb 03                	jmp    0x5f4729
  5f4726:	83 c8 ff             	or     eax,0xffffffff
  5f4729:	40                   	inc    eax
  5f472a:	6a 18                	push   0x18
  5f472c:	89 86 c8 00 00 00    	mov    DWORD PTR [esi+0xc8],eax
  5f4732:	e8 31 cb 29 00       	call   0x891268
  5f4737:	83 c4 04             	add    esp,0x4
  5f473a:	85 c0                	test   eax,eax
  5f473c:	0f 84 0c 01 00 00    	je     0x5f484e
  5f4742:	8b b6 c8 00 00 00    	mov    esi,DWORD PTR [esi+0xc8]
  5f4748:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  5f474b:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f4752:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f4759:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f4760:	c7 40 10 46 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4246
  5f4767:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  5f476d:	8b f0                	mov    esi,eax
  5f476f:	e8 2c 03 e1 ff       	call   0x404aa0
  5f4774:	e8 a7 b8 15 00       	call   0x750020
  5f4779:	5e                   	pop    esi
  5f477a:	5d                   	pop    ebp
  5f477b:	c2 04 00             	ret    0x4
  5f477e:	8b 8e 84 00 00 00    	mov    ecx,DWORD PTR [esi+0x84]
  5f4784:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  5f4787:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  5f478a:	0f 85 73 01 00 00    	jne    0x5f4903
  5f4790:	8b 81 cc 00 00 00    	mov    eax,DWORD PTR [ecx+0xcc]
  5f4796:	85 c0                	test   eax,eax
  5f4798:	74 0f                	je     0x5f47a9
  5f479a:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  5f47a0:	85 c0                	test   eax,eax
  5f47a2:	74 05                	je     0x5f47a9
  5f47a4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  5f47a7:	eb 03                	jmp    0x5f47ac
  5f47a9:	83 c8 ff             	or     eax,0xffffffff
  5f47ac:	40                   	inc    eax
  5f47ad:	89 86 c8 00 00 00    	mov    DWORD PTR [esi+0xc8],eax
  5f47b3:	e8 e8 03 e1 ff       	call   0x404ba0
  5f47b8:	8b 88 24 69 00 00    	mov    ecx,DWORD PTR [eax+0x6924]
  5f47be:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f47c4:	83 f8 09             	cmp    eax,0x9
  5f47c7:	0f 87 36 01 00 00    	ja     0x5f4903
  5f47cd:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  5f47d3:	03 c1                	add    eax,ecx
  5f47d5:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  5f47d9:	0f 84 24 01 00 00    	je     0x5f4903
  5f47df:	85 c0                	test   eax,eax
  5f47e1:	0f 84 1c 01 00 00    	je     0x5f4903
  5f47e7:	e8 94 fe e1 ff       	call   0x414680
  5f47ec:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f47f2:	6a 00                	push   0x0
  5f47f4:	50                   	push   eax
  5f47f5:	e8 86 f3 ea ff       	call   0x4a3b80
  5f47fa:	5e                   	pop    esi
  5f47fb:	5d                   	pop    ebp
  5f47fc:	c2 04 00             	ret    0x4
  5f47ff:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5f4802:	8b 8e bc 00 00 00    	mov    ecx,DWORD PTR [esi+0xbc]
  5f4808:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f480b:	75 52                	jne    0x5f485f
  5f480d:	6a 14                	push   0x14
  5f480f:	e8 54 ca 29 00       	call   0x891268
  5f4814:	83 c4 04             	add    esp,0x4
  5f4817:	85 c0                	test   eax,eax
  5f4819:	74 33                	je     0x5f484e
  5f481b:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  5f4821:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f4828:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f482f:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f4836:	c7 40 10 48 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4248
  5f483d:	8b f0                	mov    esi,eax
  5f483f:	e8 5c 02 e1 ff       	call   0x404aa0
  5f4844:	e8 d7 b7 15 00       	call   0x750020
  5f4849:	5e                   	pop    esi
  5f484a:	5d                   	pop    ebp
  5f484b:	c2 04 00             	ret    0x4
  5f484e:	33 f6                	xor    esi,esi
  5f4850:	e8 4b 02 e1 ff       	call   0x404aa0
  5f4855:	e8 c6 b7 15 00       	call   0x750020
  5f485a:	5e                   	pop    esi
  5f485b:	5d                   	pop    ebp
  5f485c:	c2 04 00             	ret    0x4
  5f485f:	8b 96 b4 00 00 00    	mov    edx,DWORD PTR [esi+0xb4]
  5f4865:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  5f4868:	75 16                	jne    0x5f4880
  5f486a:	80 be cc 00 00 00 00 	cmp    BYTE PTR [esi+0xcc],0x0
  5f4871:	0f 85 8c 00 00 00    	jne    0x5f4903
  5f4877:	e8 04 fe e1 ff       	call   0x414680
  5f487c:	6a 00                	push   0x0
  5f487e:	eb 70                	jmp    0x5f48f0
  5f4880:	8b 8e c0 00 00 00    	mov    ecx,DWORD PTR [esi+0xc0]
  5f4886:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f4889:	75 4a                	jne    0x5f48d5
  5f488b:	6a 14                	push   0x14
  5f488d:	e8 d6 c9 29 00       	call   0x891268
  5f4892:	83 c4 04             	add    esp,0x4
  5f4895:	85 c0                	test   eax,eax
  5f4897:	74 2e                	je     0x5f48c7
  5f4899:	8b f0                	mov    esi,eax
  5f489b:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  5f48a1:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f48a8:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f48af:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f48b6:	c7 40 10 fe 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43fe
  5f48bd:	e8 de 29 e1 ff       	call   0x4072a0
  5f48c2:	5e                   	pop    esi
  5f48c3:	5d                   	pop    ebp
  5f48c4:	c2 04 00             	ret    0x4
  5f48c7:	33 c0                	xor    eax,eax
  5f48c9:	8b f0                	mov    esi,eax
  5f48cb:	e8 d0 29 e1 ff       	call   0x4072a0
  5f48d0:	5e                   	pop    esi
  5f48d1:	5d                   	pop    ebp
  5f48d2:	c2 04 00             	ret    0x4
  5f48d5:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  5f48db:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  5f48de:	75 23                	jne    0x5f4903
  5f48e0:	80 be cc 00 00 00 00 	cmp    BYTE PTR [esi+0xcc],0x0
  5f48e7:	75 1a                	jne    0x5f4903
  5f48e9:	e8 92 fd e1 ff       	call   0x414680
  5f48ee:	6a 02                	push   0x2
  5f48f0:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f48f6:	50                   	push   eax
  5f48f7:	e8 84 f2 ea ff       	call   0x4a3b80
  5f48fc:	c6 86 cc 00 00 00 01 	mov    BYTE PTR [esi+0xcc],0x1
  5f4903:	5e                   	pop    esi
  5f4904:	5d                   	pop    ebp
  5f4905:	c2 04 00             	ret    0x4
```


### S3 另一 UI 事件入口

```asm
00673da0 <.text+0x272da0>:
  673da0:	55                   	push   ebp
  673da1:	8b ec                	mov    ebp,esp
  673da3:	6a ff                	push   0xffffffff
  673da5:	68 3c 62 91 00       	push   0x91623c
  673daa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  673db0:	50                   	push   eax
  673db1:	56                   	push   esi
  673db2:	57                   	push   edi
  673db3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  673db8:	33 c5                	xor    eax,ebp
  673dba:	50                   	push   eax
  673dbb:	8d 45 f4             	lea    eax,[ebp-0xc]
  673dbe:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  673dc4:	8b f1                	mov    esi,ecx
  673dc6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  673dc9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  673dcc:	81 f9 78 05 00 00    	cmp    ecx,0x578
  673dd2:	0f 85 ea 00 00 00    	jne    0x673ec2
  673dd8:	8b 8e c0 00 00 00    	mov    ecx,DWORD PTR [esi+0xc0]
  673dde:	8b 49 20             	mov    ecx,DWORD PTR [ecx+0x20]
  673de1:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  673de4:	3b c1                	cmp    eax,ecx
  673de6:	0f 85 a1 00 00 00    	jne    0x673e8d
  673dec:	6a 18                	push   0x18
  673dee:	e8 75 d4 21 00       	call   0x891268
  673df3:	83 c4 04             	add    esp,0x4
  673df6:	83 cf ff             	or     edi,0xffffffff
  673df9:	85 c0                	test   eax,eax
  673dfb:	74 27                	je     0x673e24
  673dfd:	8b b6 d8 00 00 00    	mov    esi,DWORD PTR [esi+0xd8]
  673e03:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  673e06:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  673e09:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  673e0c:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  673e13:	c7 40 10 ef 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42ef
  673e1a:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  673e20:	8b f0                	mov    esi,eax
  673e22:	eb 02                	jmp    0x673e26
  673e24:	33 f6                	xor    esi,esi
  673e26:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  673e2d:	75 23                	jne    0x673e52
  673e2f:	83 0d d0 ad fa 00 01 	or     DWORD PTR ds:0xfaadd0,0x1
  673e36:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  673e3d:	e8 4e 9b 0d 00       	call   0x74d990
  673e42:	68 70 cc bc 00       	push   0xbccc70
  673e47:	e8 ce e4 21 00       	call   0x89231a
  673e4c:	83 c4 04             	add    esp,0x4
  673e4f:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  673e52:	8b 0d d4 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bd4
  673e58:	85 c9                	test   ecx,ecx
  673e5a:	74 0b                	je     0x673e67
  673e5c:	8b 11                	mov    edx,DWORD PTR [ecx]
  673e5e:	8b 82 5c 01 00 00    	mov    eax,DWORD PTR [edx+0x15c]
  673e64:	56                   	push   esi
  673e65:	ff d0                	call   eax
  673e67:	85 f6                	test   esi,esi
  673e69:	0f 84 e0 00 00 00    	je     0x673f4f
  673e6f:	8b 16                	mov    edx,DWORD PTR [esi]
  673e71:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  673e74:	6a 01                	push   0x1
  673e76:	8b ce                	mov    ecx,esi
  673e78:	ff d0                	call   eax
  673e7a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  673e7d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  673e84:	59                   	pop    ecx
  673e85:	5f                   	pop    edi
  673e86:	5e                   	pop    esi
  673e87:	8b e5                	mov    esp,ebp
  673e89:	5d                   	pop    ebp
  673e8a:	c2 04 00             	ret    0x4
  673e8d:	8b 8e dc 00 00 00    	mov    ecx,DWORD PTR [esi+0xdc]
  673e93:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  673e96:	0f 85 b3 00 00 00    	jne    0x673f4f
  673e9c:	e8 df 07 da ff       	call   0x414680
  673ea1:	8b 96 d8 00 00 00    	mov    edx,DWORD PTR [esi+0xd8]
  673ea7:	6a 00                	push   0x0
  673ea9:	52                   	push   edx
  673eaa:	e8 d1 fc e2 ff       	call   0x4a3b80
  673eaf:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  673eb2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  673eb9:	59                   	pop    ecx
  673eba:	5f                   	pop    edi
  673ebb:	5e                   	pop    esi
  673ebc:	8b e5                	mov    esp,ebp
  673ebe:	5d                   	pop    ebp
  673ebf:	c2 04 00             	ret    0x4
```