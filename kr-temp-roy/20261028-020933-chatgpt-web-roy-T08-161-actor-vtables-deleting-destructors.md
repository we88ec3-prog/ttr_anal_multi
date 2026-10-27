# KR T08-161 — CMonster / CEventActor vtable 與 delete flag(1) 消歧

- 研究時間：20261028-020933 Asia/Taipei；研究者：`chatgpt-web roy`。
- 第一手來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；靜態唯讀 GNU objdump（PE32 i386），禁止執行或附加。
- GitHub 研究基準：`main` 於研究起始查得 `3fb7b8f6da6fd670cd2fb1e1db739e4f9dc2045b`（其他任務可能同時更新，提交時必須重新確認）；正式 T08 = `0007` 實體建立／登記／移除，網路 dispatch 僅提供 T02 引用邊界。
- 文件類型：新的完整分析原稿，非正式 catalog native semantic acceptance。證據分級：[BYTE] 原始機器碼、[FLOW] 可由指令支持的局部資料流、[INFER] 推論、[OPEN] 未解。
- 地址統一採 PE VA；`.text` VA 0x401000 對 file raw 0x400；禁止使用 flat `VA-0x401000` 混充 PE raw。
- 先前 T08-153～160 及 T01-20261027-05 限定審核仍有效。

## 問題與結果

[BYTE] CMonster 候選建構 `0x4D1710` 設置 `object+0x00=0x00C0C9DC`、`object+0xF0=0x00C0CA64`；腳本 CEventActor `0x4D0B80` 設置 `+0x00=0x00C0C824`、`+0xF0=0x00C0C8AC`。這些是不同派生 vtable，T08-159 所留的 slot+0x00 實際入口已可具體消歧。

| vtable | class 證據來源 | slot+0x00 | slot+0x14 | 備註 |
|---|---|---|---|---|
| `0xC0C9DC` | `4D1710` 物件起始 vptr | `4D18D0` | `4D1F80` | CMonster 候選 |
| `0xC0C824` | `4D0B80` 物件起始 vptr | `4D0CA0` | `4C8360` | CEventActor 候選 |

[BYTE] `0x4D18D0` / `0x4D0CA0` 都重新寫入各自派生 vptr、呼叫共同 `0x4C7B90`，測試 stack 參數低位 bit1，成立才將物件傳給 `0x89120C`；返回自身指標且 `ret 4`。這在兩個具體入口支持 **deleting-destructor wrapper** 的有限解釋（非每一種 Actor 都有同樣 destructor）。

[BYTE] `0x4D1F80` 為精短 thunk：先 `call 0x4C8360`，然後 `xor eax,eax; ret`；CEventActor `slot+0x14` 直接是 `0x4C8360`。因此兩類表面指向不同 slot+14，但相同下游釋放/解除引用 helper 的事實可直接確認，**不能將 +14 混成 destructor**。

[FLOW] `0x4DFBC0` 從樹節點 `+0x10` 取 actor，先呼叫該 actor 的 slot+0x14（無先行 null check），隨後重新讀 payload，非空才 push 1 並呼叫 slot+0x00，再設 payload=0，最後 `call 0x7B6890` erase tree node。具體入口與析構次序已在 T08-159 保存，此段補齊 CMonster/CEventActor 的動態目標。

[OPEN] `0x4C7B90` 本身是否釋放全部附屬資源、`0x89120C` 的分配器來源、其他 Actor 派生 vtable、`+0xF0` 次級 vtable 的特定 receiver 都尚未獨立驗完整 CFG。

## 與既有結論之增量

1. 過往 T08-159 認為 actor vptr+0/14 的派生目標尚未定位，本段至少具體定位**兩個**由建構函式寫入的 vtable 與 slot 值。
2. `slot+14` 不等於最終刪除：在 CMonster 分支先使用短 thunk，再轉至共享 cleanup；CEventActor 直接調共享 cleanup。
3. `slot+0(1)` 具有條件式物件記憶體 release 機器碼支持；但其他派生型別不能由這兩個入口泛化。

## C++ 型態的保守偽碼

```cpp
// Only models the two concrete observed vtables.
Actor *monsterDeletingWrapper(Actor *self, unsigned flags) {
    self->vptr = 0xC0C9DC; self->secondary = 0xC0CA64;
    baseCleanup(self); // 4C7B90
    if (flags & 1) operatorDeleteLike(self); // 89120C
    return self;
}

int monsterPreRemove(Actor *self) {
    sharedCleanup(self); // 4C8360
    return 0;
}
```


## 原始機器碼錨點：兩派生類別

### 4D1710 — CMonster 候選建構開頭
```asm
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
```

### 4D0B80 — CEventActor 候選建構與 vptr 賦值
```asm
  4d0ba6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4d0ba9:	57                   	push   edi
  4d0baa:	e8 c1 64 ff ff       	call   0x4c7070
  4d0baf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4d0bb6:	6a 3c                	push   0x3c
  4d0bb8:	c7 07 24 c8 c0 00    	mov    DWORD PTR [edi],0xc0c824
  4d0bbe:	c7 87 f0 00 00 00 ac 	mov    DWORD PTR [edi+0xf0],0xc0c8ac
  4d0bc5:	c8 c0 00 
```

### 4D18D0 — CMonster deleting-wrapper
```asm
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
```

### 4D0CA0 — CEventActor deleting-wrapper
```asm
  4d0ca0:	55                   	push   ebp
  4d0ca1:	8b ec                	mov    ebp,esp
  4d0ca3:	56                   	push   esi
  4d0ca4:	8b f1                	mov    esi,ecx
  4d0ca6:	c7 06 24 c8 c0 00    	mov    DWORD PTR [esi],0xc0c824
  4d0cac:	c7 86 f0 00 00 00 ac 	mov    DWORD PTR [esi+0xf0],0xc0c8ac
  4d0cb3:	c8 c0 00 
  4d0cb6:	e8 d5 6e ff ff       	call   0x4c7b90
  4d0cbb:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4d0cbf:	74 09                	je     0x4d0cca
  4d0cc1:	56                   	push   esi
  4d0cc2:	e8 45 05 3c 00       	call   0x89120c
  4d0cc7:	83 c4 04             	add    esp,0x4
  4d0cca:	8b c6                	mov    eax,esi
  4d0ccc:	5e                   	pop    esi
  4d0ccd:	5d                   	pop    ebp
  4d0cce:	c2                   	.byte 0xc2
```

## 證據與不變限制

- 使用者要求本段保留完整 trace，而非強行將 caller 確定為封包 opcode；只在 PE 映射及 opcode 所支援範圍下說話。
- 對於歷史已判定有不同內容的 flat dump，採用 PE 頭與具體位置實際 bytes，不跨視角複製反組譯結論。
- 靜態反組譯未含執行時各派生類別的所有實際 vptr；不得推論全域 exhaustive caller 或 runtime 時序。
- 不修改 `kr/tasks/T08/task.json`、`shared/catalog.json`、別人任務文件；commit 僅研究者個人 `kr-temp-roy/`。