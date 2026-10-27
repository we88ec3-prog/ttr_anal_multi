# KR T08-158 — gameinfo receiver and composite key abi

- 研究時間：2026-10-28T01:52:16+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：唯讀 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，GNU objdump 對 PE `.text` VA 反組譯。
- 正式 Task：GitHub KR T08 只負責 `0007` 實體建立／登記／移除的資料介面；dispatch 框架屬 T02、場景重置屬 T06/T07，僅交叉參照，不更動其他任務。
- 分級：**原始 bytes**／**已證局部 data-flow**／**有條件推論**／**未知**。線性反組譯與直接呼叫搜尋不代表完整 CFG；外部封包來源與 runtime 未驗證。
- 參照：`T08-153`、`T08-154`、`T08-155`、`T08-156`；上批保留的映射差異與 `T01-20261027-05` 部分驗收限制持續適用。
- 無遊戲執行、修改主程式、服務或存檔。本文不是可直接部署的 C++ 原始碼。

## 核心修正：`0x40F060` 不是 key converter

原先 T08-154/156 曾將 `4B3739 call 40F060` 概述為「轉換／定位複合 key」。本段透過 BIN 原始指令**否定**「把 key 作運算轉換」說法。`0x40F060` 進入後處理一次性初始化位元與 SEH，最後 `mov eax,0x00FAB130`，`ret`；caller 的已 `push` DWORD **仍留在 stack**。因 `4DFC90` 使用 `eax` 作 receiver 並以 `ret 4` 清掉一個參數，這實際是 `GameInfo* receiver` 取得器。這不是對舊全文的 native 驗收，只是此指定鏈的直接修正。

### 1. getter 的逐指令證據

```asm
  40f060:	55                   	push   ebp
  40f061:	8b ec                	mov    ebp,esp
  40f063:	83 e4 f8             	and    esp,0xfffffff8
  40f066:	6a ff                	push   0xffffffff
  40f068:	68 ee 61 94 00       	push   0x9461ee
  40f06d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  40f073:	50                   	push   eax
  40f074:	51                   	push   ecx
  40f075:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  40f07a:	33 c4                	xor    eax,esp
  40f07c:	50                   	push   eax
  40f07d:	8d 44 24 08          	lea    eax,[esp+0x8]
  40f081:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  40f087:	b8 01 00 00 00       	mov    eax,0x1
  40f08c:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  40f092:	75 20                	jne    0x40f0b4
  40f094:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  40f09a:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  40f0a1:	00 
  40f0a2:	e8 e9 fb 0c 00       	call   0x4dec90
  40f0a7:	68 30 ce bc 00       	push   0xbcce30
  40f0ac:	e8 69 32 48 00       	call   0x89231a
  40f0b1:	83 c4 04             	add    esp,0x4
  40f0b4:	b8 30 b1 fa 00       	mov    eax,0xfab130
  40f0b9:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  40f0bd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  40f0c4:	59                   	pop    ecx
  40f0c5:	8b e5                	mov    esp,ebp
  40f0c7:	5d                   	pop    ebp
  40f0c8:	c3                   	ret
```

`0x40F087 mov eax,1` / `test [0xFAB22C],al` 控制初始化；`0x40F0A2 call 0x4DEC90` 並配合初始化告知；`0x40F0B4 mov eax,0xFAB130` 是 return value 設定。一次性 flag 不等於每次呼叫都先執行清表，也不等於這個 getter 可以生成 actor。

### 2. 4B3710 實際參數路徑

```asm
  4b3720:	8d 78 fe             	lea    edi,[eax-0x2]
  4b3723:	d1 ef                	shr    edi,1
  4b3725:	85 ff                	test   edi,edi
  4b3727:	74 21                	je     0x4b374a
  4b3729:	56                   	push   esi
  4b372a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b372d:	83 c6 02             	add    esi,0x2
  4b3730:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4b3733:	0d 00 00 00 06       	or     eax,0x6000000
  4b3738:	50                   	push   eax
  4b3739:	e8 22 b9 f5 ff       	call   0x40f060
  4b373e:	e8 4d c5 02 00       	call   0x4dfc90
  4b3743:	83 c6 02             	add    esi,0x2
  4b3746:	4f                   	dec    edi
  4b3747:	75 e7                	jne    0x4b3730
  4b3749:	5e                   	pop    esi
  4b374a:	33 c0                	xor    eax,eax
  4b374c:	5f                   	pop    edi
  4b374d:	5d                   	pop    ebp
  4b374e:	c2               	ret    0xc
```

| 位址 | 指令 | 值與生命期 |
|---|---|---|
| 4B3730 | `movzx eax, word [esi]` | 提取 raw WORD |
| 4B3733 | `or eax,0x06000000` | 保留低16 bits，設定高 byte `06` |
| 4B3738 | `push eax` | DWORD 放在 stack 供下游 callee |
| 4B3739 | `call 40F060` | EAX 取得 `0xFAB130` 接收器；不 pop stack key |
| 4B373E | `call 4DFC90` | EAX receiver + 一個 stack argument |
| 4B3743 | `add esi,2` | 下個 WORD |

### 3. 4DFC90 的遍歷和比較

```asm
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
  4dfd34:	c2 04              	ret    0x4
```

`4DFC96 lea edi,[eax+8]` 把 receiver 的 `+8` tree 定位；`4DFCB0` 讀 node+10 actor 指標；對 `actor+0x88` 的欄位與 `[ebp+8]` 做 DWORD 比較。匹配則走對象清理和 tree erase，但 node 迭代細節需依 erase 後返回 iterator 驗證，不能假設在刪除節點後仍 dereference 已釋放舊指標。`0x4DFC90` 為條件式篩選，而非 0007 的直接按 actor ID 刪除。

### 4. 型別與 ABI 限制

```cpp
// 把已證的寄存器/堆疊關係改寫為可讀形式；不是正式符號名稱。
GameInfoLike* getGameInfoCandidate() { initOnceCandidate(); return (GameInfoLike*)0x00FAB130; }
void handleCompositeIds(const uint8_t* data, uint32_t length) {
    unsigned n = length >= 2 ? (length - 2) / 2 : 0;
    for (unsigned i = 0; i < n; ++i) {
        uint32_t key = (uint32_t)readLE16(data + 2 + 2*i) | 0x06000000;
        removeMatchingActorField88(getGameInfoCandidate(), key);
    }
}
```

- **已確認**：直接機器碼 `4B3733` OR、`4B3738` push、`40F0B4` 固定返回 EAX、`4DFC96` +8 tree。
- **修正**：`40F060` 不是 key→key 的 converter；若需記錄 provenance，標註「GameInfo getter + lazy init」。
- **未知**：複合 key `0x06000000 | word` 與服務端 packet opcode/資源 category 的正式含義、`actor+0x88` 是否為 script marker key。
- **分工**：opcode dispatch 請由 T02 與 T08 共用索引交叉引用，不能因本段 caller 指令而另填 catalog owner。

## 下一步

T08-159 深挖 single erase vs linked resource/tree 的清理邊界、虛擬 +0/+14、skip branch，避免把 tree free 認成 actor free。