# T08-194 — 整表刪除之多型預清理、析構與後續 callback

- 研究時間：`2026-10-28T11:01:53.006713+08:00`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 第一手：韓版 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪已重算），檔案唯讀。
- PE `.text`：VA `0x00401000`、file raw `0x400`；`.rdata`：VA `0x00BD2000`、raw `0x007D0600`。只在節區內用 `raw=0x400+(VA-0x401000)`。
- 接續 T08-193；`CMonster` 名稱承襲先前研究，缺原始 class symbol 的其他欄位/呼叫一律暫稱。所有結論限靜態路徑，不能推定 runtime 全部型別。

## 研究輪次與達標

**194 第一輪達標：重大新證據。** 此次新增原始 BIN 對 `0x004DFE90` 全表迴圈的完整有界核對，證明它與 `0x004DFBC0` 單件移除的 `vtable+0x14 → vtable+0x00(1)` 順序一致，但不採同一個逐節點 erase 路徑。故 194-2、194-3 均未啟動。

## 1. 全表清理迴圈的明確操作

- `0x004DFE94` owner 自 `[ebp+8]`，`0x004DFE97` 取 owner `+0x0C` 所存樹哨兵，接著取得迭代節點；`0x004DFEA2` 以 `node+0x10` 取得 actor。
- `0x004DFEA5` 若 actor 非零，`0x004DFEA9–B0` 從 actor 主 vtable `+0x14` 呼叫預清理；`0x004DFEB2–BA` 再取主 vtable `+0x00`，`push 1` 呼叫 deleting destructor。
- `0x004DFEBC–0x004DFF05` 以樹左右子節點/父節點及 sentinel flag 控制中序遍歷，**這是一條針對整棵場景 actor 樹的預清理/析構迴圈，而不只是一個 `free` 呼叫**。
- 迴圈完結 `0x004DFF07` 進入 `0x00823850`（樹容器清理）。`0x004DFF0F` 另外讀全域 `[0x00FBA7A4]`，`0x004DFF17–1A` 呼叫其 vtable `+0x14`，其具體業務語意沒有型別來源可證，不稱「廣播角色死亡」。
- 此函式沒有在每次遍歷個別節點時直接呼叫 `0x007B6890`，與 `0x004DFBC0` 的定點 erase 不同。

## 2. 與 T08-193 CMonster 型別個案結合

已見 CMonster 建構的主 vptr `0x00C0C9DC`；其 `+0x14` 為 `0x004D1F80`，後接 `0x004C8360` 及其中的 `0x007BE5F0`。因此 **如果**全表迭代 `node+0x10` 的實際 vptr 仍為該主表，那麼整表清理會走相同的資源預清理；若被其他派生表覆寫，需另外解析。

完整限定鏈：`0x004DFE90 → node+0x10 actor → virtual +0x14 → [CMonster 個案 0x004D1F80] → 0x004C8360 → 0x007BE5F0`，下一步 `virtual +0x00(1) → [CMonster 個案 0x004D18D0] → 0x004C7B90`。此處 **不等於** `0x007DD1F0` 直接 drain；資源與 actor 的 owner 類型必須區分。

## 3. 偽碼（僅已驗有界路徑）

```cpp
void clear_all_actors(ActorRegistry* reg) {
    auto* sentinel = reg->tree_sentinel_0C;
    for (auto* node = first_node(sentinel); node != sentinel; node = successor(node)) {
        auto* actor = node->payload_10;
        if (actor != nullptr) {
            actor->vtable[0x14 / 4](actor);
            actor->vtable[0x00 / 4](actor, 1);
        }
    }
    destroy_tree_nodes_823850(&reg->tree_at_08);
    unknown_global_object_FBA7A4->vtable[0x14 / 4](...);
}
```

上段為語意摘要，不是可編譯原碼；遍歷時的 `successor` 及 callback ABI 應以附錄實際組語為準。

## 4. 限制與下段

1. 尚未證明所有主 vptr 都是 `0x00C0C9DC`；指向 vtable 的真正動態型別須由每個建構路徑重驗。
2. 應確認 `[0x00FBA7A4]` 全域物件的 vptr 實際型別與 `+0x14` callback，而不依名稱猜用途。
3. 未有例外保證與多執行緒破壞時序的 runtime 証據；靜態迴圈不是完整生命週期協定。

## 原始組語核對

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
### VA `0x004D1F80–0x004D1F88`

```asm
004d1f80 <.text+0xd0f80>:
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
```
### VA `0x004D18D0–0x004D1901`

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
  4d18fe:	c2 04 00             	ret    0x4
```