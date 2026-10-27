# T08-099 — 釐清 `0x00FE173C` 雙重全域名稱容器與 Provider 型別衝突

- 研究者：`chatgpt-web roy`
- 研究時間：`2026-10-27T11:55:52.967860+08:00`（Asia/Taipei，實際系統時間）
- PE 原始證據：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（比對交接值：一致）
- 分析方式：GNU objdump PE32 x86，Intel assembly；本段沒有更動 BIN/EXE。
- Commit：**未提交**（本段無提交指令）。
- 證據等級：**靜態機器碼驗證**。沒有動態執行或確認真實 runtime vtable。

## 重要結論：前段「同一名稱容器中混入非多型物件」的衝突可由兩個相鄰容器消解

**已確認：** `0x00FE173C` 同時具有「全域指標欄位本身的 VA」與「該欄位內容指向的 heap 索引物件」兩種不同語義：

1. `0x007B7DA0` 配置 `0x2C` bytes heap 物件，呼叫 `0x007DC3D0` 初始化，將其指標寫入 **`[0x00FE173C]`**。
2. 同一 `0x007B7DA0` 隨即在 **`0x00FE1740`** 起初始化另一組**內嵌式**名稱樹。`[0x00FE1744]` 是配置的 0x28 bytes 哨兵指標；`[0x00FE1748]` 初始化為 0（元素計數）；其餘欄位於 `0x00FE1750～0x00FE1758` 初始化。這個實體不是 `[0x00FE173C]` 所指的 0x2C bytes heap 物件。
3. `0x007D7133 push esi; 0x007D7134 push 0x00FE173C; 0x007D7139 call 0x007B82D0`：**傳入的是全域指標欄位的地址，不是其 DWORD 內容**。`0x007B82D0` 將 `[ebp+8]` 存入 `ebx`，讀取 `[ebx+8]` 指向的哨兵（此時 `0x00FE1744`），並更新 `[ebx+0xC]`（此時 `0x00FE1748`）作計數：實際操作的是相鄰的 **內嵌名稱樹**。其記憶體結構相當於前置 4-byte header 加 tree at +4，而不是 heap 索引的指標解參照。
4. `0x007BDF90` 的 `0x007BE009 mov esi,[0x00FE173C]` 取得 heap 索引物件，`0x007BE04A call 0x007B86F0` 查詢該物件，從結果 `node+0x24` 讀取 payload，再對 payload 首 DWORD 作 vptr 並呼叫 `+0x10`。
5. 因此：**0x8C 管理物件登記在內嵌樹中，不是已證明登記在 heap 名稱索引中的 Provider**。兩者雖共用 `0x007B86F0` 查詢演算法及 `node+0x24` 節點結構，但所傳入的 container 不同，且不能合併其 payload 型別。

這是本段實質新發現，並應修正 T08-098 尚未解決的「同一 registry / payload 型別衝突」。此結論並**不**證明真正 Binding Provider 的 vtable；那仍是下一段研究目標。

## 記憶體視圖（機器碼驗證）

| VA / 欄位 | 物件範疇 | 根據 | 結論 |
|---|---|---|---|
| `[0x00FE173C]` | 全域 DWORD | `0x007B7DEE` | 指向 heap-allocated 0x2C bytes hash/name index |
| `0x00FE1740` | 相鄰內嵌樹起點 | `0x007B7DF6` | 非 heap 0x2C 名稱索引 |
| `[0x00FE1744]` | 內嵌樹哨兵 | `0x007B7E17` | 新配置 0x28 bytes 節點 |
| `[0x00FE1748]` | 內嵌樹計數 | `0x007B7E05` | 初始化為零；登記增量 |
| `[0x00FE1750～0x00FE1758]` | 相鄰管理欄位 | `0x007B7E2D～0x007B7E39` | 歸零，精確含義待追 |
| `[0x00FE1770] & 1` | 靜態初始化旗標 | `0x007D70FD～0x007D7115` | 決定是否只初始化一次 |
| `0x8C manager +0x00` | 順序 ID | `0x007DCEE0～0x007DCEE9` | **不是 vptr** |
| `nameNode +0x24` | 名稱樹節點 payload | `0x00719C09～0x00719C0C` | 型別由 container / 插入者決定 |

### register / calling convention 防混淆

`0x007B82D0` 使用 `ECX` 傳入字串名稱，`[EBP+8]` 傳入容器基址，`[EBP+0xC]` 傳入要存到 node 的 payload。

`0x007D712F mov ecx,[esp+0x14]`（名稱字串指標），`push esi`（0x8C manager 指標），`push 0x00FE173C`（**地址常數**），`call 0x007B82D0`；callee 內 `0x007B830A mov ebx,[ebp+8]`，`0x007B8355 mov ecx,[ebx+8]`，`0x007B83EB mov eax,[ebx+8]`，`0x007B8419 mov [ebx+0xC],ecx`。因此實際以 `0x00FE1744` 為哨兵欄位，`0x00FE1748` 為元素數欄位。

相對地，`0x007BDF90` 先使用 `mov esi,[0x00FE173C]`，再 `mov eax,esi` 呼叫 `0x007B86F0`，是**指標內容**；其索引 `+4` 為哨兵、`+0x10` 為 bucket 陣列，與相鄰樹的欄位來源不同。

## 本段新確認 / 重新分類函式

| VA | 暫定功能 | 驗證級別 |
|---|---|---|
| `0x007B7DA0` | 初始化 heap 名稱索引及相鄰內嵌名稱樹（兩個容器） | 已確認 |
| `0x007DCEE0` | 0x8C manager 建構、分配遞增 ID | 已確認 |
| `0x007D7139` | 向相鄰內嵌名稱樹登記 0x8C manager | 已確認 |
| `0x007B82D0` | 通用樹節點依名稱登記，基址+4 為樹結構 | 已確認 |
| `0x00719B90` | 建構 0x28 bytes 名稱樹節點 | 已確認 |
| `0x007BDF90` | 使用 heap 索引查詢 binding provider 並呼叫 `vtable+0x10` | 已確認呼叫；provider 實作未知 |
| `0x007B86F0` | 以傳入的容器作名稱查找；非固定全域容器 | 已確認 |
| `0x007DC510` | 以傳入索引清理 payload；不可自動當成 manager | 已確認呼叫 / 語義局限 |

## 偽程式碼（暫命名）

```cpp
// 一組相鄰全域變數；以下 layout 僅在研究到的欄位程度確立。
struct NameGlobals {
    HashNameIndex2C* heapIndex;  // 0x00FE173C (contents are pointer)
    // EmbeddedTree at 0x00FE1740; scalar first member unknown
    uint8_t treeHeader;          // 0x00FE1740 + padding
    TreeNode28* treeSentinel;    // 0x00FE1744
    uint32_t treeCount;          // 0x00FE1748
    // other fields ...
};

void RegisterManagerName(const char* name, ResourceManager8C* manager) {
    // The container argument is ADDRESS of heapIndex field,
    // so the callee operates the adjacent embedded tree at offset +4.
    RegisterTreeNode(name, (void*)0x00FE173C, manager);
}

Binding* ResolveBinding(Item* item) {
    HashNameIndex2C* table = *(HashNameIndex2C**)0x00FE173C;
    NameNode28* node = FindName(table, item->name);
    if (node && node->payload) {
        // Provider is NOT proven to be ResourceManager8C.
        return node->payload->virtual_10();
    }
    return nullptr;
}
```

## 對先前段落的修正與研究界線

- T08-097 的 `0x00719B90` node +0x24 寫入推導仍成立，但不代表所有容器 payload 共享 C++ 型別。
- T08-098 的「名稱索引衝突」由 **容器身分混用** 所解釋。`0x007D7139` 不是 heap `0x2C` 索引 provider 登記的證據。
- 避免沿此誤解推導虛構 vtable 或誤把 manager 順序 ID 執行為指標。
- 尚未找到 **heap 名稱索引的實際 provider 插入者**；需從 `0x007DC3D0` / 內部 bucket+0x10 的寫入者另尋。
- binding `+0x80` 的初始化/寫入與場景 object `vtable+0x20` 的間接調度仍未確認。

## 下一段 T08-100 建議

搜尋 heap name index 的直接建立/插入，追 `0x007DC660` / `0x007DCA10` 與 `0x007DC3D0` 及 `0x007B86F0` 的成員寫入，分清向 heap 容器登記多型 Provider 的確切路徑；取得實際 vptr 常量後才能定位 `vtable+0x10`、`binding+0x80`。

## 原始機器碼附錄（BIN / objdump -Mintel）

以下指令按明確起點擷取；`objdump` 設定 `--start-address`、`--stop-address`，**僅函式片段**，不將範圍內非函式首的反組譯誤當新函式。

### 全域兩套容器初始化 (0x007b7da0–0x007b7e68)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b7da0 <.text+0x3b6da0>:
  7b7da0:	55                   	push   ebp
  7b7da1:	8b ec                	mov    ebp,esp
  7b7da3:	6a ff                	push   0xffffffff
  7b7da5:	68 f1 9f 90 00       	push   0x909ff1
  7b7daa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7b7db0:	50                   	push   eax
  7b7db1:	83 ec 18             	sub    esp,0x18
  7b7db4:	56                   	push   esi
  7b7db5:	57                   	push   edi
  7b7db6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7b7dbb:	33 c5                	xor    eax,ebp
  7b7dbd:	50                   	push   eax
  7b7dbe:	8d 45 f4             	lea    eax,[ebp-0xc]
  7b7dc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7b7dc7:	6a 2c                	push   0x2c
  7b7dc9:	e8 9a 94 0d 00       	call   0x891268
  7b7dce:	83 c4 04             	add    esp,0x4
  7b7dd1:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  7b7dd4:	33 f6                	xor    esi,esi
  7b7dd6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7b7dd9:	3b c6                	cmp    eax,esi
  7b7ddb:	74 08                	je     0x7b7de5
  7b7ddd:	50                   	push   eax
  7b7dde:	e8 ed 45 02 00       	call   0x7dc3d0
  7b7de3:	eb 02                	jmp    0x7b7de7
  7b7de5:	33 c0                	xor    eax,eax
  7b7de7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7b7dee:	a3 3c 17 fe 00       	mov    ds:0xfe173c,eax
  7b7df3:	8a 45 f3             	mov    al,BYTE PTR [ebp-0xd]
  7b7df6:	bf 40 17 fe 00       	mov    edi,0xfe1740
  7b7dfb:	6a 28                	push   0x28
  7b7dfd:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  7b7e00:	a2 40 17 fe 00       	mov    ds:0xfe1740,al
  7b7e05:	89 35 48 17 fe 00    	mov    DWORD PTR ds:0xfe1748,esi
  7b7e0b:	e8 58 94 0d 00       	call   0x891268
  7b7e10:	83 c4 04             	add    esp,0x4
  7b7e13:	3b c6                	cmp    eax,esi
  7b7e15:	74 51                	je     0x7b7e68
  7b7e17:	a3 44 17 fe 00       	mov    ds:0xfe1744,eax
  7b7e1c:	89 00                	mov    DWORD PTR [eax],eax
  7b7e1e:	a1 44 17 fe 00       	mov    eax,ds:0xfe1744
  7b7e23:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7b7e26:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7b7e2d:	89 35 50 17 fe 00    	mov    DWORD PTR ds:0xfe1750,esi
  7b7e33:	89 35 54 17 fe 00    	mov    DWORD PTR ds:0xfe1754,esi
  7b7e39:	89 35 58 17 fe 00    	mov    DWORD PTR ds:0xfe1758,esi
  7b7e3f:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  7b7e43:	d9 e8                	fld1
  7b7e45:	6a 08                	push   0x8
  7b7e47:	d9 1d 68 17 fe 00    	fstp   DWORD PTR ds:0xfe1768
  7b7e4d:	e8 de 4d 02 00       	call   0x7dcc30
  7b7e52:	b8 3c 17 fe 00       	mov    eax,0xfe173c
  7b7e57:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7b7e5a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b7e61:	59                   	pop    ecx
  7b7e62:	5f                   	pop    edi
  7b7e63:	5e                   	pop    esi
  7b7e64:	8b e5                	mov    esp,ebp
  7b7e66:	5d                   	pop    ebp
  7b7e67:	c3                   	ret
```

### 名稱樹登記入口與參數來源 (0x007d70ca–0x007d7146)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d70ca <.text+0x3d60ca>:
  7d70ca:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d70ce:	8d 44 24 10          	lea    eax,[esp+0x10]
  7d70d2:	e8 79 42 fe ff       	call   0x7bb350
  7d70d7:	d9 05 50 59 c5 00    	fld    DWORD PTR ds:0xc55950
  7d70dd:	bf 10 00 00 00       	mov    edi,0x10
  7d70e2:	d9 5e 48             	fstp   DWORD PTR [esi+0x48]
  7d70e5:	39 7c 24 54          	cmp    DWORD PTR [esp+0x54],edi
  7d70e9:	72 0a                	jb     0x7d70f5
  7d70eb:	8b 44 24 40          	mov    eax,DWORD PTR [esp+0x40]
  7d70ef:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7d70f3:	eb 08                	jmp    0x7d70fd
  7d70f5:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  7d70f9:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  7d70fd:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7d7104:	75 29                	jne    0x7d712f
  7d7106:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7d710d:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0xb
  7d7114:	0b 
  7d7115:	e8 86 0c fe ff       	call   0x7b7da0
  7d711a:	68 90 e7 bc 00       	push   0xbce790
  7d711f:	e8 f6 b1 0b 00       	call   0x89231a
  7d7124:	83 c4 04             	add    esp,0x4
  7d7127:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d712e:	04 
  7d712f:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  7d7133:	56                   	push   esi
  7d7134:	68 3c 17 fe 00       	push   0xfe173c
  7d7139:	e8 92 11 fe ff       	call   0x7b82d0
  7d713e:	85 c0                	test   eax,eax
  7d7140:	0f 85 a4 00 00 00    	jne    0x7d71ea
```

### 0x8C 管理器配置與初始化 (0x007d6f48–0x007d6f8b)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d6f48 <.text+0x3d5f48>:
  7d6f48:	8b ce                	mov    ecx,esi
  7d6f4a:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7d6f50:	57                   	push   edi
  7d6f51:	e8 0a 57 00 00       	call   0x7dc660
  7d6f56:	68 8c 00 00 00       	push   0x8c
  7d6f5b:	e8 08 a3 0b 00       	call   0x891268
  7d6f60:	83 c4 04             	add    esp,0x4
  7d6f63:	85 c0                	test   eax,eax
  7d6f65:	74 1c                	je     0x7d6f83
  7d6f67:	83 7c 24 54 10       	cmp    DWORD PTR [esp+0x54],0x10
  7d6f6c:	8b 7c 24 40          	mov    edi,DWORD PTR [esp+0x40]
  7d6f70:	73 04                	jae    0x7d6f76
  7d6f72:	8d 7c 24 40          	lea    edi,[esp+0x40]
  7d6f76:	8b f0                	mov    esi,eax
  7d6f78:	e8 63 5f 00 00       	call   0x7dcee0
  7d6f7d:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  7d6f81:	eb 08                	jmp    0x7d6f8b
  7d6f83:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  7d6f8a:	00
```

### 樹容器插入與哨兵 (0x007b8307–0x007b8454)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b8307 <.text+0x3b7307>:
  7b8307:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b830a:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b830d:	8b f9                	mov    edi,ecx
  7b830f:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7b8313:	8b c7                	mov    eax,edi
  7b8315:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  7b831c:	00 
  7b831d:	c7 44 24 34 00 00 00 	mov    DWORD PTR [esp+0x34],0x0
  7b8324:	00 
  7b8325:	c6 44 24 24 00       	mov    BYTE PTR [esp+0x24],0x0
  7b832a:	8d 70 01             	lea    esi,[eax+0x1]
  7b832d:	8d 49 00             	lea    ecx,[ecx+0x0]
  7b8330:	8a 08                	mov    cl,BYTE PTR [eax]
  7b8332:	40                   	inc    eax
  7b8333:	84 c9                	test   cl,cl
  7b8335:	75 f9                	jne    0x7b8330
  7b8337:	2b c6                	sub    eax,esi
  7b8339:	50                   	push   eax
  7b833a:	57                   	push   edi
  7b833b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  7b833f:	e8 2c a7 c4 ff       	call   0x402a70
  7b8344:	8d 54 24 24          	lea    edx,[esp+0x24]
  7b8348:	52                   	push   edx
  7b8349:	8d 44 24 20          	lea    eax,[esp+0x20]
  7b834d:	c7 44 24 74 00 00 00 	mov    DWORD PTR [esp+0x74],0x0
  7b8354:	00 
  7b8355:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b8358:	50                   	push   eax
  7b8359:	8d 43 04             	lea    eax,[ebx+0x4]
  7b835c:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  7b8360:	e8 8b 03 00 00       	call   0x7b86f0
  7b8365:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  7b8369:	39 4c 24 1c          	cmp    DWORD PTR [esp+0x1c],ecx
  7b836d:	c7 44 24 70 ff ff ff 	mov    DWORD PTR [esp+0x70],0xffffffff
  7b8374:	ff 
  7b8375:	0f 95 44 24 13       	setne  BYTE PTR [esp+0x13]
  7b837a:	83 7c 24 38 10       	cmp    DWORD PTR [esp+0x38],0x10
  7b837f:	72 0d                	jb     0x7b838e
  7b8381:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  7b8385:	52                   	push   edx
  7b8386:	e8 81 8e 0d 00       	call   0x89120c
  7b838b:	83 c4 04             	add    esp,0x4
  7b838e:	80 7c 24 13 00       	cmp    BYTE PTR [esp+0x13],0x0
  7b8393:	74 07                	je     0x7b839c
  7b8395:	33 c0                	xor    eax,eax
  7b8397:	e9 b8 00 00 00       	jmp    0x7b8454
  7b839c:	b8 01 00 00 00       	mov    eax,0x1
  7b83a1:	39 43 30             	cmp    DWORD PTR [ebx+0x30],eax
  7b83a4:	7c 07                	jl     0x7b83ad
  7b83a6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  7b83aa:	89 41 44             	mov    DWORD PTR [ecx+0x44],eax
  7b83ad:	8b c7                	mov    eax,edi
  7b83af:	c7 44 24 54 0f 00 00 	mov    DWORD PTR [esp+0x54],0xf
  7b83b6:	00 
  7b83b7:	c7 44 24 50 00 00 00 	mov    DWORD PTR [esp+0x50],0x0
  7b83be:	00 
  7b83bf:	c6 44 24 40 00       	mov    BYTE PTR [esp+0x40],0x0
  7b83c4:	8d 50 01             	lea    edx,[eax+0x1]
  7b83c7:	8a 08                	mov    cl,BYTE PTR [eax]
  7b83c9:	40                   	inc    eax
  7b83ca:	84 c9                	test   cl,cl
  7b83cc:	75 f9                	jne    0x7b83c7
  7b83ce:	2b c2                	sub    eax,edx
  7b83d0:	50                   	push   eax
  7b83d1:	57                   	push   edi
  7b83d2:	8d 4c 24 48          	lea    ecx,[esp+0x48]
  7b83d6:	e8 95 a6 c4 ff       	call   0x402a70
  7b83db:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  7b83df:	89 54 24 5c          	mov    DWORD PTR [esp+0x5c],edx
  7b83e3:	c7 44 24 70 01 00 00 	mov    DWORD PTR [esp+0x70],0x1
  7b83ea:	00 
  7b83eb:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b83ee:	8b 38                	mov    edi,DWORD PTR [eax]
  7b83f0:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  7b83f3:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  7b83f7:	51                   	push   ecx
  7b83f8:	52                   	push   edx
  7b83f9:	57                   	push   edi
  7b83fa:	e8 91 17 f6 ff       	call   0x719b90
  7b83ff:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  7b8402:	ba fe ff ff 07       	mov    edx,0x7fffffe
  7b8407:	2b d1                	sub    edx,ecx
  7b8409:	83 fa 01             	cmp    edx,0x1
  7b840c:	73 0a                	jae    0x7b8418
  7b840e:	68 34 20 bf 00       	push   0xbf2034
  7b8413:	e8 18 57 0c 00       	call   0x87db30
  7b8418:	41                   	inc    ecx
  7b8419:	89 4b 0c             	mov    DWORD PTR [ebx+0xc],ecx
  7b841c:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7b841f:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  7b8422:	89 01                	mov    DWORD PTR [ecx],eax
  7b8424:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  7b8427:	8b 02                	mov    eax,DWORD PTR [edx]
  7b8429:	50                   	push   eax
  7b842a:	83 c0 08             	add    eax,0x8
  7b842d:	50                   	push   eax
  7b842e:	8d 44 24 24          	lea    eax,[esp+0x24]
  7b8432:	50                   	push   eax
  7b8433:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7b8436:	e8 45 8c 01 00       	call   0x7d1080
  7b843b:	83 7c 24 54 10       	cmp    DWORD PTR [esp+0x54],0x10
  7b8440:	72 0d                	jb     0x7b844f
  7b8442:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  7b8446:	51                   	push   ecx
  7b8447:	e8 c0 8d 0d 00       	call   0x89120c
  7b844c:	83 c4 04             	add    esp,0x4
  7b844f:	b8 01 00 00 00       	mov    eax,0x1
```

### Binding 解析的全域指標解參照 (0x007bdfcf–0x007be094)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdfcf <.text+0x3bcfcf>:
  7bdfcf:	eb 03                	jmp    0x7bdfd4
  7bdfd1:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7bdfd4:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7bdfdb:	8b 18                	mov    ebx,DWORD PTR [eax]
  7bdfdd:	75 27                	jne    0x7be006
  7bdfdf:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7bdfe6:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bdfed:	e8 ae 9d ff ff       	call   0x7b7da0
  7bdff2:	68 90 e7 bc 00       	push   0xbce790
  7bdff7:	e8 1e 43 0d 00       	call   0x89231a
  7bdffc:	83 c4 04             	add    esp,0x4
  7bdfff:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be006:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7be009:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7be00f:	8b c1                	mov    eax,ecx
  7be011:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be018:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be01f:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be023:	8d 78 01             	lea    edi,[eax+0x1]
  7be026:	8a 10                	mov    dl,BYTE PTR [eax]
  7be028:	40                   	inc    eax
  7be029:	84 d2                	test   dl,dl
  7be02b:	75 f9                	jne    0x7be026
  7be02d:	2b c7                	sub    eax,edi
  7be02f:	50                   	push   eax
  7be030:	51                   	push   ecx
  7be031:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7be034:	e8 37 4a c4 ff       	call   0x402a70
  7be039:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7be03c:	50                   	push   eax
  7be03d:	8d 4d c8             	lea    ecx,[ebp-0x38]
  7be040:	51                   	push   ecx
  7be041:	8b c6                	mov    eax,esi
  7be043:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7be04a:	e8 a1 a6 ff ff       	call   0x7b86f0
  7be04f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be056:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7be05a:	72 0c                	jb     0x7be068
  7be05c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7be05f:	52                   	push   edx
  7be060:	e8 a7 31 0d 00       	call   0x89120c
  7be065:	83 c4 04             	add    esp,0x4
  7be068:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  7be06b:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be072:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be079:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be07d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7be080:	74 11                	je     0x7be093
  7be082:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  7be085:	85 c9                	test   ecx,ecx
  7be087:	74 0a                	je     0x7be093
  7be089:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be08b:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7be08e:	ff d2                	call   edx
  7be090:	89 43 08             	mov    DWORD PTR [ebx+0x8],eax
  7be093:	83                   	.byte 0x83
```

### 名稱樹條件刪除 (0x007dc570–0x007dc5be)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc570 <.text+0x3db570>:
  7dc570:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dc573:	e8 78 c1 fd ff       	call   0x7b86f0
  7dc578:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7dc57f:	83 7d cc 10          	cmp    DWORD PTR [ebp-0x34],0x10
  7dc583:	72 0c                	jb     0x7dc591
  7dc585:	8b 55 b8             	mov    edx,DWORD PTR [ebp-0x48]
  7dc588:	52                   	push   edx
  7dc589:	e8 7e 4c 0b 00       	call   0x89120c
  7dc58e:	83 c4 04             	add    esp,0x4
  7dc591:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc594:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7dc597:	74 33                	je     0x7dc5cc
  7dc599:	8b 78 24             	mov    edi,DWORD PTR [eax+0x24]
  7dc59c:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc59e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7dc5a1:	8b cf                	mov    ecx,edi
  7dc5a3:	ff d2                	call   edx
  7dc5a5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  7dc5a8:	3b c3                	cmp    eax,ebx
  7dc5aa:	0f 85 8a 00 00 00    	jne    0x7dc63a
  7dc5b0:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc5b2:	8b 10                	mov    edx,DWORD PTR [eax]
  7dc5b4:	6a 01                	push   0x1
  7dc5b6:	8b cf                	mov    ecx,edi
  7dc5b8:	ff d2                	call   edx
  7dc5ba:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc5bd:	50                   	push   eax
```

### 0x8C 物件 ID 初始化 (0x007dcee0–0x007dcf3e)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dcee0 <.text+0x3dbee0>:
  7dcee0:	a1 44 a8 fb 00       	mov    eax,ds:0xfba844
  7dcee5:	40                   	inc    eax
  7dcee6:	53                   	push   ebx
  7dcee7:	89 06                	mov    DWORD PTR [esi],eax
  7dcee9:	33 db                	xor    ebx,ebx
  7dceeb:	a3 44 a8 fb 00       	mov    ds:0xfba844,eax
  7dcef0:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  7dcef3:	68 a0 0f 00 00       	push   0xfa0
  7dcef8:	8d 46 64             	lea    eax,[esi+0x64]
  7dcefb:	89 5e 4c             	mov    DWORD PTR [esi+0x4c],ebx
  7dcefe:	89 5e 50             	mov    DWORD PTR [esi+0x50],ebx
  7dcf01:	89 5e 54             	mov    DWORD PTR [esi+0x54],ebx
  7dcf04:	50                   	push   eax
  7dcf05:	c7 46 5c 01 00 00 00 	mov    DWORD PTR [esi+0x5c],0x1
  7dcf0c:	89 5e 60             	mov    DWORD PTR [esi+0x60],ebx
  7dcf0f:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  7dcf15:	8d 56 04             	lea    edx,[esi+0x4]
  7dcf18:	89 5e 7c             	mov    DWORD PTR [esi+0x7c],ebx
  7dcf1b:	89 9e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ebx
  7dcf21:	89 9e 84 00 00 00    	mov    DWORD PTR [esi+0x84],ebx
  7dcf27:	8b c7                	mov    eax,edi
  7dcf29:	2b d7                	sub    edx,edi
  7dcf2b:	eb 03                	jmp    0x7dcf30
  7dcf2d:	8d 49 00             	lea    ecx,[ecx+0x0]
  7dcf30:	8a 08                	mov    cl,BYTE PTR [eax]
  7dcf32:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  7dcf35:	40                   	inc    eax
  7dcf36:	3a cb                	cmp    cl,bl
  7dcf38:	75 f6                	jne    0x7dcf30
  7dcf3a:	8b c6                	mov    eax,esi
  7dcf3c:	5b                   	pop    ebx
  7dcf3d:	c3                   	ret
```

### 0x28 節點配置/複製 (0x00719b90–0x00719c18)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00719b90 <.text+0x318b90>:
  719b90:	55                   	push   ebp
  719b91:	8b ec                	mov    ebp,esp
  719b93:	6a ff                	push   0xffffffff
  719b95:	68 11 21 91 00       	push   0x912111
  719b9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  719ba0:	50                   	push   eax
  719ba1:	83 ec 10             	sub    esp,0x10
  719ba4:	53                   	push   ebx
  719ba5:	56                   	push   esi
  719ba6:	57                   	push   edi
  719ba7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  719bac:	33 c5                	xor    eax,ebp
  719bae:	50                   	push   eax
  719baf:	8d 45 f4             	lea    eax,[ebp-0xc]
  719bb2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  719bb8:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  719bbb:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  719bbe:	6a 28                	push   0x28
  719bc0:	e8 a3 76 17 00       	call   0x891268
  719bc5:	8b f8                	mov    edi,eax
  719bc7:	33 c0                	xor    eax,eax
  719bc9:	83 c4 04             	add    esp,0x4
  719bcc:	89 7d 10             	mov    DWORD PTR [ebp+0x10],edi
  719bcf:	3b f8                	cmp    edi,eax
  719bd1:	74 67                	je     0x719c3a
  719bd3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  719bd6:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  719bd9:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  719bdc:	8d 77 08             	lea    esi,[edi+0x8]
  719bdf:	89 0f                	mov    DWORD PTR [edi],ecx
  719be1:	89 57 04             	mov    DWORD PTR [edi+0x4],edx
  719be4:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  719be7:	89 75 0c             	mov    DWORD PTR [ebp+0xc],esi
  719bea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  719bee:	3b f0                	cmp    esi,eax
  719bf0:	74 1d                	je     0x719c0f
  719bf2:	6a ff                	push   0xffffffff
  719bf4:	50                   	push   eax
  719bf5:	c7 46 14 0f 00 00 00 	mov    DWORD PTR [esi+0x14],0xf
  719bfc:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  719bff:	53                   	push   ebx
  719c00:	8b ce                	mov    ecx,esi
  719c02:	88 06                	mov    BYTE PTR [esi],al
  719c04:	e8 37 94 ce ff       	call   0x403040
  719c09:	8b 43 1c             	mov    eax,DWORD PTR [ebx+0x1c]
  719c0c:	89 46 1c             	mov    DWORD PTR [esi+0x1c],eax
  719c0f:	8b c7                	mov    eax,edi
  719c11:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  719c14:	64                   	fs
  719c15:	89                   	.byte 0x89
  719c16:	0d                   	.byte 0xd
	...
```

### 名稱樹查找使用的 container+4 (0x007b86f0–0x007b873d)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b86f0 <.text+0x3b76f0>:
  7b86f0:	55                   	push   ebp
  7b86f1:	8b ec                	mov    ebp,esp
  7b86f3:	83 ec 10             	sub    esp,0x10
  7b86f6:	53                   	push   ebx
  7b86f7:	56                   	push   esi
  7b86f8:	8b f0                	mov    esi,eax
  7b86fa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b86fd:	57                   	push   edi
  7b86fe:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  7b8701:	e8 da 9e d9 ff       	call   0x5525e0
  7b8706:	23 c7                	and    eax,edi
  7b8708:	39 46 24             	cmp    DWORD PTR [esi+0x24],eax
  7b870b:	77 09                	ja     0x7b8716
  7b870d:	d1 ef                	shr    edi,1
  7b870f:	83 c9 ff             	or     ecx,0xffffffff
  7b8712:	2b cf                	sub    ecx,edi
  7b8714:	03 c1                	add    eax,ecx
  7b8716:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  7b8719:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b871c:	8d 04 c2             	lea    eax,[edx+eax*8]
  7b871f:	8b 10                	mov    edx,DWORD PTR [eax]
  7b8721:	8b ca                	mov    ecx,edx
  7b8723:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7b8726:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  7b8729:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7b872c:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  7b872f:	90                   	nop
  7b8730:	3b d6                	cmp    edx,esi
  7b8732:	75 04                	jne    0x7b8738
  7b8734:	8b c6                	mov    eax,esi
  7b8736:	eb 05                	jmp    0x7b873d
  7b8738:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  7b873b:	8b 00                	mov    eax,DWORD PTR [eax]
```

### 資源建立路徑前段 (0x007d6f16–0x007d6f65)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d6f16 <.text+0x3d5f16>:
  7d6f16:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7d6f1d:	75 29                	jne    0x7d6f48
  7d6f1f:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7d6f26:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x8
  7d6f2d:	08 
  7d6f2e:	e8 6d 0e fe ff       	call   0x7b7da0
  7d6f33:	68 90 e7 bc 00       	push   0xbce790
  7d6f38:	e8 dd b3 0b 00       	call   0x89231a
  7d6f3d:	83 c4 04             	add    esp,0x4
  7d6f40:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d6f47:	04 
  7d6f48:	8b ce                	mov    ecx,esi
  7d6f4a:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7d6f50:	57                   	push   edi
  7d6f51:	e8 0a 57 00 00       	call   0x7dc660
  7d6f56:	68 8c 00 00 00       	push   0x8c
  7d6f5b:	e8 08 a3 0b 00       	call   0x891268
  7d6f60:	83 c4 04             	add    esp,0x4
  7d6f63:	85 c0                	test   eax,eax
```