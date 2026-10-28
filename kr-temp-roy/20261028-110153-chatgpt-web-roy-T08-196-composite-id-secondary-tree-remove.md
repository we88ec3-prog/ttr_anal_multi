# T08-196 — 依複合 ID 條件移除與 key 移除之兩棵索引路徑界線

- 研究時間：`2026-10-28T11:01:53.006713+08:00`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 第一手：韓版 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪已重算），檔案唯讀。
- PE `.text`：VA `0x00401000`、file raw `0x400`；`.rdata`：VA `0x00BD2000`、raw `0x007D0600`。只在節區內用 `raw=0x400+(VA-0x401000)`。
- 接續 T08-193；`CMonster` 名稱承襲先前研究，缺原始 class symbol 的其他欄位/呼叫一律暫稱。所有結論限靜態路徑，不能推定 runtime 全部型別。

## 研究輪次與達標判定

**196 第一輪取得具體新增控制流證據**：`0x004DFC90` 對 `owner+0x18` 的第二樹、`actor+0x88` 複合 ID 有獨立篩選移除功能，並走自己的節點迭代與清理，不是對 `0x004DFBC0` 的同義包裝。已形成完整可辨功能鏈，故 196-2、196-3 未啟動。

## 1. 兩類鍵／owner 分離

| 入口 | 樹基底 | 匹配依據 | 移除時節點 payload |
|---|---|---|---|
| `0x004DFBC0` | `owner+0x08`，sentinel 在 `owner+0x0C` | `[ebp+8]` 交給 `0x0082EF00` | `node+0x10` actor |
| `0x004DFC90` | `owner+0x18`，sentinel 在 `owner+0x1C` | `cmp [actor+0x88], [ebp+8]` | `node+0x10` actor |
| `0x004DFE90` | `owner+0x08`，sentinel `owner+0x0C` | 全表遍歷 | `node+0x10` actor |

`0x004DFC90` 的 `EDI=[EAX+0x08]`（從 owner `EAX`），然後遍歷 `owner+0x18` 樹，取 `node+0x10` actor，`0x004DFCB6` 比較 actor `+0x88` 和入參。相等時 `0x004DFCBE–C3` virtual `+0x14` 清理，`0x004DFCCC–D2` deleting destructor `+0x00(1)`，將 node payload 零化，並 `0x004DFCE1 call 0x007B6890` 刪節點。

相對於 `0x004DFBC0` 使用 `0x0082EF00` 按 key 查找後單點 erase，`0x004DFC90` 是**依 actor `+0x88` 複合 ID 遍歷第二索引的條件刪除**。不能直接說兩個樹是完全獨立的 actor 所有權或某個一定只是引用，因為兩條皆能調用 deleting destructor；要確認第二棵樹建構/插入與與第一棵共用 actor 指標的避免 double-free 策略。

## 2. 可能的雙表生命週期風險（推論，非既成 bug）

如果同一 actor 指標同時存在兩棵樹，兩條路徑都有 virtual deleting destructor，因此上游應有某種節點移除/同步或不相交的填入條件；目前尚未確認 writer/互斥或同步機制，**不能宣稱原生程式一定 double-free，也不能斷言同步已完善**。本段有界結論是兩棵不同位置的樹、兩種判定以及兩條各自會清理 actor 的路徑。

## 3. CMonster 特定型別交集

以上兩個入口的 `vtable+0x14` 是動態分派；若 payload 是已建構 `0x00C0C9DC` CMonster，則 slot 指向 `0x004D1F80 → 0x004C8360`。而在其他派生 actor 或被覆寫 vptr 情況，仍須單獨驗證其表目標。

## 4. 待查與下一段

1. 第二棵樹 `owner+0x18` 的建構/插入者、key 的唯一性、payload 的配置與第一棵樹的交集。
2. `actor+0x88` 複合 ID 寫入者及其和 actor `+0x04` key 的關係，不能僅依位移推出 ID 格式。
3. `0x004DFC90` 的外層 caller/事件及兩棵樹共享 actor 的破壞避免機制。
4. 保持 0007 介面範圍；不推 server 波次或 spawn timing。

## 原始組語

### VA `0x004DFBC0–0x004DFC2C`

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
### VA `0x004DFC90–0x004DFD40`

```asm
004dfc90 <.text+0xdec90>:
  4dfc90:	55                   	push   ebp
  4dfc91:	8b ec                	mov    ebp,esp
  4dfc93:	51                   	push   ecx
  4dfc94:	56                   	push   esi
  4dfc95:	57                   	push   edi
  4dfc96:	8d 78 08             	lea    edi,[eax+0x8]
  4dfc99:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4dfc9c:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfc9e:	3b f0                	cmp    esi,eax
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfcaf:	90                   	nop
  4dfcb0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dfcb6:	39 81 88 00 00 00    	cmp    DWORD PTR [ecx+0x88],eax
  4dfcbc:	75 2c                	jne    0x4dfcea
  4dfcbe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcc0:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfcc3:	ff d0                	call   eax
  4dfcc5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcc8:	85 c9                	test   ecx,ecx
  4dfcca:	74 0f                	je     0x4dfcdb
  4dfccc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcce:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfcd0:	6a 01                	push   0x1
  4dfcd2:	ff d0                	call   eax
  4dfcd4:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfcdb:	56                   	push   esi
  4dfcdc:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfcdf:	51                   	push   ecx
  4dfce0:	57                   	push   edi
  4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
  4dfce6:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfce8:	eb 40                	jmp    0x4dfd2a
  4dfcea:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfcee:	75 3a                	jne    0x4dfd2a
  4dfcf0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfcf3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfcf7:	75 16                	jne    0x4dfd0f
  4dfcf9:	8b f0                	mov    esi,eax
  4dfcfb:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfcfd:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd01:	75 27                	jne    0x4dfd2a
  4dfd03:	8b f0                	mov    esi,eax
  4dfd05:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfd07:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd0b:	74 f6                	je     0x4dfd03
  4dfd0d:	eb 1b                	jmp    0x4dfd2a
  4dfd0f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfd12:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd16:	75 10                	jne    0x4dfd28
  4dfd18:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfd1b:	75 0b                	jne    0x4dfd28
  4dfd1d:	8b f0                	mov    esi,eax
  4dfd1f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfd22:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd26:	74 f0                	je     0x4dfd18
  4dfd28:	8b f0                	mov    esi,eax
  4dfd2a:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  4dfd2d:	75 81                	jne    0x4dfcb0
  4dfd2f:	5f                   	pop    edi
  4dfd30:	5e                   	pop    esi
  4dfd31:	8b e5                	mov    esp,ebp
  4dfd33:	5d                   	pop    ebp
  4dfd34:	c2 04 00             	ret    0x4
  4dfd37:	cc                   	int3
  4dfd38:	cc                   	int3
  4dfd39:	cc                   	int3
  4dfd3a:	cc                   	int3
  4dfd3b:	cc                   	int3
  4dfd3c:	cc                   	int3
  4dfd3d:	cc                   	int3
  4dfd3e:	cc                   	int3
  4dfd3f:	cc                   	int3
```
### VA `0x004DFE90–0x004DFF23`

```asm
004dfe90 <.text+0xdee90>:
  4dfe90:	55                   	push   ebp
  4dfe91:	8b ec                	mov    ebp,esp
  4dfe93:	53                   	push   ebx
  4dfe94:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dfe97:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  4dfe9a:	56                   	push   esi
  4dfe9b:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe9d:	57                   	push   edi
  4dfe9e:	3b f0                	cmp    esi,eax
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  4dfea5:	85 ff                	test   edi,edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeab:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfeae:	8b cf                	mov    ecx,edi
  4dfeb0:	ff d2                	call   edx
  4dfeb2:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeb4:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfeb6:	6a 01                	push   0x1
  4dfeb8:	8b cf                	mov    ecx,edi
  4dfeba:	ff d2                	call   edx
  4dfebc:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfec5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    esi,eax
  4dfecd:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfecf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    esi,eax
  4dfed7:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfed9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfee4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4dfef0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    esi,eax
  4dfef7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfefa:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    esi,eax
  4dff02:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    edi,[ebx+0x8]
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dff15:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dff17:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dff1a:	ff d2                	call   edx
  4dff1c:	5f                   	pop    edi
  4dff1d:	5e                   	pop    esi
  4dff1e:	5b                   	pop    ebx
  4dff1f:	5d                   	pop    ebp
  4dff20:	c2 04 00             	ret    0x4
```