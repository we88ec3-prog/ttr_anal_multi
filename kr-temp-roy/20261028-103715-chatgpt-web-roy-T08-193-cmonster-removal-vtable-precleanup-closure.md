# T08-193 — CMonster 之 actor 移除虛擬分派 → 128 槽資源預清理直接閉合

- 研究者：`chatgpt-web roy`；研究時間：2026-10-28T10:37:19.202051+08:00
- 段號：**T08-193**。依使用者規則，只有第一輪無重大發現／完整進展才深入 193-2，仍不足才進 193-3；本次第一輪找到可原始驗證的具體虛擬分派閉合，故**193-2、193-3 未啟動**，亦未進入 T08-194。
- 原始檔案：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重算）。
- GitHub 研究基準：最新 `main` 已查核，T08-192 原始全文已閱讀（`kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md`）。
- 工具：GNU `objdump -d -Mintel` 對原始 PE32 以**VA 窗口**反組譯，Python `struct` 讀回 `.rdata` 中原始 vtable DWORD；未執行、未注入客戶端。
- PE section header：`.text VA 0x00401000/raw 0x400`；`.rdata VA 0x00BD2000/raw 0x007D0600`（均自原始檔 header 核對）。
- 證據分級：**已確認**為本次 BIN bytes、明確 vptr 寫入、slot 取值與有界 call；**部分確認**為跨 runtime 物件類型；**尚待驗證**包括其他衍生類別與全域 owner。

## 一、第一輪研究（193）— 重大進展與停止條件

### 1. 先前缺口

T08-188～192 已知 `0x004DFBC0` 個別移除會針對樹節點 `node+0x10` 取出的 actor 發出 `vtable+0x14` 呼叫，再以 `vtable+0x00(1)` 作 deleting destructor，最後 `0x007B6890` 刪樹節點。此前不能將 `call eax` 直接寫死為一個函式，因 actor 的動態型別未定。

### 2. 新完成的 CMonster 靜態型別個案閉合

`0x004D1710` CMonster 建構入口先呼叫 `0x004C7070`，再在 `0x004D1749` 寫入主 vptr **`0x00C0C9DC`**，於 `0x004D174F` 寫入 `object+0xF0` 次級 vptr `0x00C0CA64`。

從原始 `.rdata` vptr `0x00C0C9DC` 讀出的關鍵槽：

| slot offset | 實際表地址 | 原始 DWORD 目標 |
|---|---|---|
| `+0x00` | `0x00C0C9DC` | `0x004D18D0` |
| `+0x04` | `0x00C0C9E0` | `0x005F5D10` |
| `+0x08` | `0x00C0C9E4` | `0x004CA880` |
| `+0x10` | `0x00C0C9EC` | `0x004D1F70` |
| `+0x14` | `0x00C0C9F0` | `0x004D1F80` |
| `+0x18` | `0x00C0C9F4` | `0x008DC2F0` |
| `+0x20` | `0x00C0C9FC` | `0x004D1AE0` |

`0x004DFBF8～0x004DFC00` 對 `node+0x10` 所存 actor 呼叫主 vptr `+0x14`。**當且僅當該 actor 的實際 vptr 為上述 CMonster 主表**，目標是 `0x004D1F80`，此函式只呼叫 `0x004C8360` 然後回傳零值。這不是假設、不是 E8 自動掃描，而是**物件建構 vptr 寫入 + .rdata 表值 + 間接呼叫槽 + 目標函式 bytes** 的可回溯閉合。

同一移除函式 `0x004DFC02～0x004DFC11` 接著使用 vtable `+0x00` 搭配 `push 1` 呼叫 deleting destructor。對相同 CMonster vtable，該槽為 `0x004D18D0`，其 `0x004D18E6` 呼叫共用基底 `0x004C7B90`，再根據參數 bit 0 決定是否用 `0x0089120C` 釋放該 actor 指標。

所以 CMonster 型別下能夠表達**條件式**清理順序：

```text
scene actor registry 0x004DFBC0
  └─ lookup 0x0082EF00 → node payload [node+0x10] = actor*
       ├─ actor->vptr[0x14] → [0x00C0C9F0] = 0x004D1F80
       │    └─ direct E8 → 0x004C8360：特定欄位與 128 槽的 resource release 預清理
       ├─ actor->vptr[0x00](1) → [0x00C0C9DC] = 0x004D18D0
       │    └─ direct E8 → 0x004C7B90：共用基底析構
       │         └─ bit 0 → 0x0089120C：釋放 actor 記憶體
       └─ tree-node erase 0x007B6890
```

**這是新跨越 T08 正式 0007 actor 移除到共享資源釋放接口的具體多型個案**。不表示所有 actor 都是 CMonster，也不表示所有釋放都會進入 deferred pool drain。

### 3. `0x004C8360` 的精確 resource release 覆蓋範圍

這段使用 `ECX` 作基底，首先對 `actor+0x15C` 做額外的間接 `vptr+0x08` 處理（其型別尚未知），然後：

- `actor+0x364` 指向物件非空且該物件 `+0x24` 非零時，`0x004C838C call 0x007BE5F0`；傳入的是 `eax+0x24` 的地址，不是 actor 起始地址。
- `actor+0x164` 起的 DWORD 指標陣列逐一處理，**固定 `EBX=0x80`**，故 128 格。非空 entry 且 `entry+0x24 != 0` 時，`0x004C83AF call 0x007BE5F0`，每格跨 4 bytes。
- `0x004C8360` 只觀察到呼叫解除引用，並未在此迴圈逐槽回填零；不得把它等同 `0x004C83C0` 的狀態更新/清理，也不能斷言 128 格全有資源。
- `0x007BE5F0` 後續可連到 `0x007DD1A0` 的資源回收/池分支（T08-173～192），但此處**不等於**在 `0x004DFBC0` 中直接執行 `0x007DD1F0` drain。

### 4. ABI 與動態型別的重要限制

- `0x004DFBC0` 的 `ESI` 是場景 registry owner，`EDI` 是查到的樹節點，`[EDI+0x10]` 是 actor 指標，**三者不是同一物件**。
- `0x004D1F80` 是 CMonster 的 `vtable+0x14` 個案，不可直接稱全部 scene actor 都呼叫這函式；其他派生表須獨立核對。
- `0x004D18D0` 是刪除析構入口，`0x004C7B90` 是基底析構；`0x004C8360` 則是清理前的資源解除引用。三者不同階段。
- 共用底層資源的 `owner+0x44/+0x60/+0x7C` 不可和 actor 同位移混用，仍未完成 actor→wrapper→resource→manager 實際指標同源證明。

## 二、193-2 深入判定

**未啟動。** 193 第一輪已完成從 CMonster 建構 vptr、主表索引、actor removal 動態分派到具體資源 release 函式的跨層閉合，滿足「重大發現或完整進展」的使用者停止條件。不應為湊三輪重複分析既有內容。

## 三、193-3 深入判定

**未啟動**，原因同上。不因尚有更多未解問題就視本段重大成果不存在。

## 四、原始 .text E8 候選（不是完整 caller CFG）

掃描 `.text` 每一原始 byte，計算 `site+5+signed(rel32)`，僅代表候選 direct-call bytes，不涵蓋 vtable、間接呼叫；命中不等於 CFG 可達。此處 vtable 的真正證據另依 `.rdata` DWORD。

| 目標 VA | 候選數 | 位址與 E8 bytes |
|---|---:|---|
| `0x004d1f80` | 0 | 無 direct E8 候選 |
| `0x004c8360` | 3 | `0x004cec14:e84797ffff`, `0x004d1f80:e8db63ffff`, `0x004d2864:e8f75affff` |
| `0x004d18d0` | 0 | 無 direct E8 候選 |
| `0x004dfbc0` | 2 | `0x004aa057:e8645b0300`, `0x004b2ac2:e8f9d00200` |
| `0x004c7b90` | 7 | `0x004aefdd:e8ae8b0100`, `0x004c7b66:e825000000`, `0x004cdb7e:e80da0ffff`, `0x004d0cb6:e8d56effff`, `0x004d1193:e8f869ffff`, `0x004d18e6:e8a562ffff`, `0x004d22e3:e8a858ffff` |

## 五、待驗證／下段方向

1. 其他場景型別是否覆寫 `vtable+0x14`，先由具體建構 vptr 原始 bytes 和各表指標證明，不套用 CMonster。
2. `0x004C8360` 首個 `actor+0x15C` 子物件 vptr `+0x08` 的真正型別/目標，仍需從該物件構造與 vptr 寫入追蹤。
3. 逐步證實 component `+0x24` 到 `0x007BE5F0`、資源所屬 manager、binding 的全來源，以及先清理與後續基底析構是否有共享資源再次解除引用的防護。
4. `0x004DFE90` 整表清理是否對 CMonster 採相同 `+0x14` 預清理，以及其他分支與失敗路徑。不能只以個別 erase 推定全部。
5. 正式 T08 任務只研究 actor 建立/登記/移除的資料界面，不推演伺服器生成時機、波次、AI 或關卡進出決策。

## 六、原始 BIN 反組譯（指定 VA 有界窗口，未修改原始 bytes）

### `0x004dfbc0..0x004dfc2c`

```asm
004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
```

### `0x004d1710..0x004d17c8`

```asm
004d1710 <.text+0xd0710>:
  4d1710:	55                   	push   ebp
  4d1711:	8b ec                	mov    ebp,esp
  4d1713:	6a ff                	push   0xffffffff
  4d1715:	68 b9 08 91 00       	push   0x9108b9
  4d171a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4d1720:	50                   	push   eax
  4d1721:	51                   	push   ecx
  4d1722:	53                   	push   ebx
  4d1723:	56                   	push   esi
  4d1724:	57                   	push   edi
  4d1725:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4d172a:	33 c5                	xor    eax,ebp
  4d172c:	50                   	push   eax
  4d172d:	8d 45 f4             	lea    eax,[ebp-0xc]
  4d1730:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4d1736:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4d1739:	57                   	push   edi
  4d173a:	e8 31 59 ff ff       	call   0x4c7070
  4d173f:	33 db                	xor    ebx,ebx
  4d1741:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4d1744:	0f 57 c0             	xorps  xmm0,xmm0
  4d1747:	6a 3c                	push   0x3c
  4d1749:	c7 07 dc c9 c0 00    	mov    DWORD PTR [edi],0xc0c9dc
  4d174f:	c7 87 f0 00 00 00 64 	mov    DWORD PTR [edi+0xf0],0xc0ca64
  4d1756:	ca c0 00 
  4d1759:	89 9f 20 04 00 00    	mov    DWORD PTR [edi+0x420],ebx
  4d175f:	89 9f 28 04 00 00    	mov    DWORD PTR [edi+0x428],ebx
  4d1765:	f3 0f 11 87 2c 04 00 	movss  DWORD PTR [edi+0x42c],xmm0
  4d176c:	00 
  4d176d:	89 9f 30 04 00 00    	mov    DWORD PTR [edi+0x430],ebx
  4d1773:	e8 f0 fa 3b 00       	call   0x891268
  4d1778:	8b f0                	mov    esi,eax
  4d177a:	83 c4 04             	add    esp,0x4
  4d177d:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4d1780:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4d1784:	3b f3                	cmp    esi,ebx
  4d1786:	74 19                	je     0x4d17a1
  4d1788:	8b c7                	mov    eax,edi
  4d178a:	8d 4b 03             	lea    ecx,[ebx+0x3]
  4d178d:	e8 9e 9a ff ff       	call   0x4cb230
  4d1792:	c7 06 cc 77 c0 00    	mov    DWORD PTR [esi],0xc077cc
  4d1798:	c7 46 34 01 00 00 00 	mov    DWORD PTR [esi+0x34],0x1
  4d179f:	eb 02                	jmp    0x4d17a3
  4d17a1:	33 f6                	xor    esi,esi
  4d17a3:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4d17a7:	8b 5e 08             	mov    ebx,DWORD PTR [esi+0x8]
  4d17aa:	83 bc 9f f4 00 00 00 	cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
  4d17b1:	00 
  4d17b2:	74 0d                	je     0x4d17c1
  4d17b4:	68 3c 75 c0 00       	push   0xc0753c
  4d17b9:	e8 a2 c3 21 00       	call   0x6edb60
  4d17be:	83 c4 04             	add    esp,0x4
  4d17c1:	89 b4 9f f4 00 00 00 	mov    DWORD PTR [edi+ebx*4+0xf4],esi
```

### `0x004d1f70..0x004d1f90`

```asm
004d1f70 <.text+0xd0f70>:
  4d1f70:	e8 cb 62 ff ff       	call   0x4c8240
  4d1f75:	33 c0                	xor    eax,eax
  4d1f77:	c3                   	ret
  4d1f78:	cc                   	int3
  4d1f79:	cc                   	int3
  4d1f7a:	cc                   	int3
  4d1f7b:	cc                   	int3
  4d1f7c:	cc                   	int3
  4d1f7d:	cc                   	int3
  4d1f7e:	cc                   	int3
  4d1f7f:	cc                   	int3
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
  4d1f88:	cc                   	int3
  4d1f89:	cc                   	int3
  4d1f8a:	cc                   	int3
  4d1f8b:	cc                   	int3
  4d1f8c:	cc                   	int3
  4d1f8d:	cc                   	int3
  4d1f8e:	cc                   	int3
  4d1f8f:	cc                   	int3
```

### `0x004d18d0..0x004d1900`

```asm
004d18d0 <.text+0xd08d0>:
  4d18d0:	55                   	push   ebp
  4d18d1:	8b ec                	mov    ebp,esp
  4d18d3:	56                   	push   esi
  4d18d4:	8b f1                	mov    esi,ecx
  4d18d6:	c7 06 dc c9 c0 00    	mov    DWORD PTR [esi],0xc0c9dc
  4d18dc:	c7 86 f0 00 00 00 64 	mov    DWORD PTR [esi+0xf0],0xc0ca64
  4d18e3:	ca c0 00 
  4d18e6:	e8 a5 62 ff ff       	call   0x4c7b90
  4d18eb:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4d18ef:	74 09                	je     0x4d18fa
  4d18f1:	56                   	push   esi
  4d18f2:	e8 15 f9 3b 00       	call   0x89120c
  4d18f7:	83 c4 04             	add    esp,0x4
  4d18fa:	8b c6                	mov    eax,esi
  4d18fc:	5e                   	pop    esi
  4d18fd:	5d                   	pop    ebp
  4d18fe:	c2                   	.byte 0xc2
  4d18ff:	04                   	.byte 0x4
```

### `0x004c8360..0x004c83c0`

```asm
004c8360 <.text+0xc7360>:
  4c8360:	53                   	push   ebx
  4c8361:	56                   	push   esi
  4c8362:	57                   	push   edi
  4c8363:	8b f9                	mov    edi,ecx
  4c8365:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4c836b:	85 c0                	test   eax,eax
  4c836d:	74 0a                	je     0x4c8379
  4c836f:	8d 48 08             	lea    ecx,[eax+0x8]
  4c8372:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c8374:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c8377:	ff d2                	call   edx
  4c8379:	8b 87 64 03 00 00    	mov    eax,DWORD PTR [edi+0x364]
  4c837f:	85 c0                	test   eax,eax
  4c8381:	74 0e                	je     0x4c8391
  4c8383:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c8387:	8d 70 24             	lea    esi,[eax+0x24]
  4c838a:	74 05                	je     0x4c8391
  4c838c:	e8 5f 62 2f 00       	call   0x7be5f0
  4c8391:	81 c7 64 01 00 00    	add    edi,0x164
  4c8397:	bb 80 00 00 00       	mov    ebx,0x80
  4c839c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4c83a0:	8b 07                	mov    eax,DWORD PTR [edi]
  4c83a2:	85 c0                	test   eax,eax
  4c83a4:	74 0e                	je     0x4c83b4
  4c83a6:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c83aa:	8d 70 24             	lea    esi,[eax+0x24]
  4c83ad:	74 05                	je     0x4c83b4
  4c83af:	e8 3c 62 2f 00       	call   0x7be5f0
  4c83b4:	83 c7 04             	add    edi,0x4
  4c83b7:	4b                   	dec    ebx
  4c83b8:	75 e6                	jne    0x4c83a0
  4c83ba:	5f                   	pop    edi
  4c83bb:	5e                   	pop    esi
  4c83bc:	33 c0                	xor    eax,eax
  4c83be:	5b                   	pop    ebx
  4c83bf:	c3                   	ret
```

### `0x004c7b90..0x004c7c20`

```asm
004c7b90 <.text+0xc6b90>:
  4c7b90:	55                   	push   ebp
  4c7b91:	8b ec                	mov    ebp,esp
  4c7b93:	6a ff                	push   0xffffffff
  4c7b95:	68 b9 d9 90 00       	push   0x90d9b9
  4c7b9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c7ba0:	50                   	push   eax
  4c7ba1:	83 ec 0c             	sub    esp,0xc
  4c7ba4:	53                   	push   ebx
  4c7ba5:	56                   	push   esi
  4c7ba6:	57                   	push   edi
  4c7ba7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c7bac:	33 c5                	xor    eax,ebp
  4c7bae:	50                   	push   eax
  4c7baf:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c7bb2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c7bb8:	8b d9                	mov    ebx,ecx
  4c7bba:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  4c7bbd:	c7 03 54 75 c0 00    	mov    DWORD PTR [ebx],0xc07554
  4c7bc3:	c7 83 f0 00 00 00 dc 	mov    DWORD PTR [ebx+0xf0],0xc075dc
  4c7bca:	75 c0 00 
  4c7bcd:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  4c7bd4:	8b bb 68 03 00 00    	mov    edi,DWORD PTR [ebx+0x368]
  4c7bda:	85 ff                	test   edi,edi
  4c7bdc:	74 3b                	je     0x4c7c19
  4c7bde:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7be1:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4c7be5:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7be8:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7bea:	50                   	push   eax
  4c7beb:	51                   	push   ecx
  4c7bec:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7bef:	8b c7                	mov    eax,edi
  4c7bf1:	e8 da be 36 00       	call   0x833ad0
  4c7bf6:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  4c7bfa:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7bfd:	50                   	push   eax
  4c7bfe:	e8 09 96 3c 00       	call   0x89120c
  4c7c03:	83 c4 04             	add    esp,0x4
  4c7c06:	57                   	push   edi
  4c7c07:	e8 00 96 3c 00       	call   0x89120c
  4c7c0c:	83 c4 04             	add    esp,0x4
  4c7c0f:	c7 83 68 03 00 00 00 	mov    DWORD PTR [ebx+0x368],0x0
  4c7c16:	00 00 00 
  4c7c19:	8b b3 60 01 00 00    	mov    esi,DWORD PTR [ebx+0x160]
  4c7c1f:	33                   	.byte 0x33
```