# T16-62 — KR `HasQuest` 相關節點欄位消費者 `0x0053FEB0` 與 `0x004A8680`

- 對象：**KR T16 only**，《星空幻想 Online》任務與劇情流程；分析日期 `20261028-110252`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 唯讀原件：`/mnt/data/Tartaros.bin`；大小 `12,472,320` bytes；本次 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `.text` 核驗 VA `0x00401000` / raw `0x400`，在本段地址使用 `raw = VA - 0x00400C00`；實際取 `Tartaros.bin` 機器碼，再由 GNU objdump `-m i386 -M intel` 靜態解碼，不執行客戶端。
- GitHub 先前基準為 main `ce87b59efc2712535d04f0cd212ebe0323df23d7`（查詢時），延續 T16-57～60；不改 catalog、owner、其他任務；**不檢查 TC**。
- 分級：`原生已確認` = 這次可核驗的位元組／直線組語；`部分確認` = caller 和 callee 意義尚有條件；`合理推測` = 待證；`資訊缺失` = 沒有原件證據。線性反組譯在跳轉／函式邊界外可能混入非程式位元組，不自稱完成 CFG。

## 本次較前段新增的實證

1. `0x0053FDB6`、`0x0053FDCA`、`0x0053FDDD`、`0x0053FDEE` 皆在非零節點時呼叫 `0x0053FEB0`，其**輸出槽**以 `+0x00/+0x10/+0x20/+0x30` 的方式落在一個 `0x40` bytes 暫存物件（分配於 `0x0053FD3B`）。
2. `0x0053FEB0` 的 `push 0x00C0F4A0; call 0x0072E2E0` 是在**每個輸入節點內**再查一個子欄位。得到子節點後，執行其 `vtable+0x14` 間接呼叫，並以返回者 `+0x44` 作後續查找起點。
3. 子欄位 `0x00C0F4A8` 的查找由 `0x007300A0` 執行，找到後將 `node+0x30` 的短字串／堆字串資料透過 `0x008917B4` 轉換，再以 `EAX=local-address`、`EDI=[ebp+8]` 交付 `0x004A8680`。
4. 迴圈由 `mov esi,[esi+0x40]` 跳回 `0x0053FEC6`，直至 `ESI==0`。所以 `0x0053FEB0` 是**遍歷元素、轉換欄位、送往目的槽**的 consumer，不是本地 Quest 完成判斷，更不是 server writer。

## 直接字節與組語

- VA 0x0053FDB2 / raw 0x0013F1B2: 85 ff 74 0c 8b 4c 24 14 51 8b c7 e8 ee 00 00 00 8b 7c 24 14 85 f6 74 0b 8d 57 10 52 8b c6 e8 db 00 00 00 8b 44 24 20 85 c0 74 09 8d 4f 20 51 e8 ca 00 00 00 8b 44 24 1c 85 c0 74 09 8d 57 30 52 e8 b9 00 00 00 8b
- VA 0x0053FEB0 / raw 0x0013F2B0: 55 8b ec 51 56 68 a0 f4 c0 00 e8 21 e4 1e 00 8b f0 85 f6 74 51 57 8b 06 8b 50 14 8b ce ff d2 85 c0 74 3b 68 a8 f4 c0 00 8d 78 44 e8 c0 01 1f 00 85 c0 74 1a 83 c0 30 83 78 14 10 72 02 8b 00 85 c0 74 0b 50 e8 bb 18 35 00 83 c4 04 eb 02 33 c0 8b 7d 08 89 45 fc 8d 45 fc e8

```asm
0053fdb2 <.data+0x13f1b2>:
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8           	call   0x57e850
```

```asm
0053feb0 <.data+0x13f2b0>:
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0 00       	push   0xc0f4a0
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53febf:	8b f0                	mov    esi,eax
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fec5:	57                   	push   edi
  53fec6:	8b 06                	mov    eax,DWORD PTR [esi]
  53fec8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  53fecb:	8b ce                	mov    ecx,esi
  53fecd:	ff d2                	call   edx
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fed3:	68 a8 f4 c0 00       	push   0xc0f4a8
  53fed8:	8d 78 44             	lea    edi,[eax+0x44]
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee4:	83 c0 30             	add    eax,0x30
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feed:	8b 00                	mov    eax,DWORD PTR [eax]
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
  53fef3:	50                   	push   eax
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53fef9:	83 c4 04             	add    esp,0x4
  53fefc:	eb 02                	jmp    0x53ff00
  53fefe:	33 c0                	xor    eax,eax
  53ff00:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53ff03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff06:	8d 45 fc             	lea    eax,[ebp-0x4]
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff0e:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  53ff11:	85 f6                	test   esi,esi
  53ff13:	75 b1                	jne    0x53fec6
  53ff15:	5f                   	pop    edi
  53ff16:	5e                   	pop    esi
  53ff17:	8b e5                	mov    esp,ebp
  53ff19:	5d                   	pop    ebp
  53ff1a:	c2               	ret    0x4
```

## 限定的資料流模型

```text
XML-like node (EBX)
  ├─ name lookup 0x72E2E0 (HasQuest family)
  ├─ selected nodes EDI/ESI/stack locals
  ├─ 0x40-byte result object; four 0x10-spaced slots
  └─ if node != null => 0x53FEB0(node, &slot[n])
                     └─ child lookup (C0F4A0)
                        └─ virtual call [vptr+0x14]
                           └─ child[+0x44] + 0x7300A0(C0F4A8)
                              └─ small-string / parsed-value → 0x4A8680
```

`0x004A8680` 的完整效應／目的槽 ownership 尚待直接 CFG 審核；由此不推出 `HasQuest` 的 true/false、server quest flags、Quest16 完成及 Quest15 解鎖條件。也不能將此 `0x40` 物件等同全域 `[0x00FE18DC]` 的持久化資料。

## 目前仍缺的原件（DEFERRED-LOCAL-RESOURCE）

| 來源 | 來源 SHA256 | 目前不足的內容及影響 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | 缺具體 function bodies，無法確證全教學回呼 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 尚無 Quest15、Quest16 元素原文及前置規則 |
| Quest16 server 狀態 writer／原生 ACK、角色持久化來源 | unknown | 不能證明 Quest16 已完成、Quest15 可接或重登續接 |

不可把 T01 的來源稽核、QuestTalk 缺少兩筆的局部切片、或歷史 fixture 視為上述缺口已解。

