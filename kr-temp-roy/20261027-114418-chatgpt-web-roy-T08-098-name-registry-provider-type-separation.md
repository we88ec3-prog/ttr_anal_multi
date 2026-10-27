# T08-098 — 全域名稱索引與 0x8C 管理器的型別分離、0x68 登記載體來源

- 研究者：`chatgpt-web roy`
- 台灣時間：2026-10-27T11:44:18+08:00
- BIN：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（一致）
- 分析方法：PE `.text` 使用 `objdump -d -Mintel`，函式直接呼叫以 PE 映射與 E8 rel32 解碼交叉核對。
- 狀態：本段 **未提交 GitHub**。

## 本段核心新發現（嚴格分開已確認與推測）

### 已確認 A：前段存在必須修正的 C++ 型別等價推論

1. `0x007DCEE0` 初始化的 0x8C bytes 管理物件第一個 DWORD 是遞增計數：`mov [esi],eax`，而不是 vtable 常量。`+0x5C` 持有計數初始化為 1、`+0x64` 為同步結構、`+0x7C～0x84` 為復用池管理。由此**不可**將這個 0x8C 物件直接視作在 `0x007BDF90` 執行 `mov eax,[ecx]; call [eax+0x10]` 的多型 Provider。
2. `0x007B8480` 名稱查找與建立路徑確實會將 0x8C 管理物件交 `0x007B82D0` 登記，但 `0x007B82D0` 是可由不同呼叫來源使用的**通用樹節點登記函式**。因此不能只靠 `node+0x24` 相同就把所有名稱索引的元素類型合併。
3. `0x007BDF90` 使用全域 `0x00FE173C` 指向的名稱索引結構查找，回傳的 `node+0x24` 必須具有可呼叫 `vtable+0x10` 的物件配置；它不可能僅由先前 0x8C 管理器的首 DWORD ID 證實。

### 已確認 B：找出另一個向同一名稱索引登記的具體入口

- `0x007D7139` 直接呼叫 `0x007B82D0`；參數是全域名稱容器指標位址 `0x00FE173C` 及先前保存在 `esi` 的物件指標。
- 呼叫前 `0x007D6F8B` 配置 `0x68` bytes 物件，經 `0x007D6790` 初始化，再於 `0x007D702D` 配置第二個 `0x68` bytes 物件；這些物件被放入先前分配的 `0x8C` 管理器內 `+0x4C` 起的容器。
- `0x007D6790` 的前段將傳入資料複製到目標，末段呼叫 `0x00898BA0` 以 0x40 bytes 複製來源資料到目標，因此新建 `0x68` 物件的第 0 DWORD 來源需追查該拷貝來源；**尚不能直接確證該物件一定含有效 vtable**。
- `0x007B7DA0` 建立 `0x00FE173C` 指向的 0x2C bytes 全域索引，另在相鄰 `0x00FE1740` 初始化其他嵌入式結構。兩者不可混成同一個指標或同一物件。

### 已確認 C：全域名稱索引與局部名稱容器的區別

`0x007DC3D0`：以 0x2C bytes 建構全域索引，`+0x04` 配置 0x28 bytes 哨兵節點，`+0x08` 計數歸零，`+0x10～0x18` 為內部陣列邊界；`0x007BDF90` 從 `0x00FE173C` 取得索引。

`0x007B8480`：呼叫 `0x007B86F0` 時使用上游 `[ebp+0x08]` 載入的管理上下文所附容器（以 `ebx+0x04` 取址），而非此處直接硬編碼 `0x00FE173C`；其直接呼叫者為 `0x00550CAB, 0x007AE968, 0x007B07A2, 0x007F7116`。名稱樹節點結構雖可共用，內含的指標目標類型**不能默認共用**。

### 已確認 D：名稱解析綁定具體機器碼

```asm
007BE009 mov esi, dword ptr ds:[0xFE173C]
007BE04A call 0x007B86F0
007BE082 mov ecx,[eax+0x24]       ; nameNode->payload
007BE089 mov eax,[ecx]            ; payload 的首 DWORD 作間接表指標
007BE08B mov edx,[eax+0x10]
007BE08E call edx
007BE090 mov [ebx+0x08],eax        ; item->binding
```

**確切實作地址尚未找到**；vtable 指向哪個常量及 binding+0x80 寫入者均保持 open。另 `0x007DC510` 對相應 nameNode payload 呼叫 slot `+0x0C`，條件成立才呼叫 slot `+0x00` 並移除節點，可能幫助定位 payload 的共同 vtable，但現在無足夠證據把它命名成 refcount 或 destructor。

## 資料流與暫定偽程式碼

```cpp
// 偽程式碼，型別暫命名；不同 registry 的 payload 型別必須隔離
struct NameNode { /* links/key */ void* payload; /* +0x24 */ };
struct ResourceManager8C {
    uint32_t sequentialId; // +0x00, 非 vptr
    uint8_t unknown04[0x40];
    int mode;              // +0x44
    // template vector at +0x4C..+0x54
    // refcount +0x5C, activeCounter +0x60, lock +0x64,
    // reuse vector +0x7C..+0x84
};

void ResolveBinding(Resource* resource) {
    for (Item* item : resource->items) {
        NameNode* node = FindNameNode(globalRegistry, item->name);
        if (node != end && node->payload != nullptr) {
            // payload MUST be validated independently from ResourceManager8C
            item->binding = node->payload->virtual_10();
        }
    }
}

// 此呼叫把一個由 0x68 初始化路徑取得的指標登錄於全域名稱樹：
RegisterName(globalRegistry, name, descriptor68);
```

## 直接 E8 rel32 呼叫參照（僅直接呼叫，不含虛擬或 jump）

- `0x007B8480`：4 處，0x00550CAB, 0x007AE968, 0x007B07A2, 0x007F7116
- `0x007B82D0`：2 處，0x007B864E, 0x007D7139
- `0x007BDF90`：1 處，0x007DD0EC
- `0x007DC510`：1 處，0x007DD17D
- `0x007DCEE0`：2 處，0x007B85B7, 0x007D6F78

## 待追查（T08-099）

1. 沿 `0x007D6790` 的 0x40-byte memcpy 源頭定位 0x68 descriptor 的首 DWORD，判定是否保存 vtable 或函式表指標。
2. 交叉參照 `0x007D7139` 的名稱來源與相應 `0x007D6Fxx` 配置鏈，確認哪一種 descriptor 真正寫入 `0x00FE173C`。
3. 分離 `0x007B8480` 各直接呼叫者傳入的局部索引物件，不把 `ResourceManager8C` 與全域登記 payload 合併。
4. 透過 `0x007DC510` 的 `vtable+0x0C`、`+0x00` 與 `0x007BDF90` 的 `+0x10`，搜尋共享 vtable 及類別建構器。
5. 從 binding 配置者追查 `binding+0x80` 初始化與更新。場景物件 vtable+0x20 主迴圈仍未找到。

## BIN 反組譯證據附錄

以下為完整指定函式範圍內的反組譯片段。地址按照映像 VA 顯示；不代表所有輸出範圍起訖均為完整函式邊界。

### global registry initialization: `0x007B7DA0～0x007B7E60`

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
  7b7e5a:	64                   	fs
  7b7e5b:	89                   	.byte 0x89
  7b7e5c:	0d                   	.byte 0xd
  7b7e5d:	00 00                	add    BYTE PTR [eax],al
	...

```

### registry constructor: `0x007DC3D0～0x007DC450`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc3d0 <.text+0x3db3d0>:
  7dc3d0:	55                   	push   ebp
  7dc3d1:	8b ec                	mov    ebp,esp
  7dc3d3:	6a ff                	push   0xffffffff
  7dc3d5:	68 a6 9d 90 00       	push   0x909da6
  7dc3da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc3e0:	50                   	push   eax
  7dc3e1:	83 ec 10             	sub    esp,0x10
  7dc3e4:	56                   	push   esi
  7dc3e5:	57                   	push   edi
  7dc3e6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc3eb:	33 c5                	xor    eax,ebp
  7dc3ed:	50                   	push   eax
  7dc3ee:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dc3f1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc3f7:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  7dc3fa:	8a 45 0b             	mov    al,BYTE PTR [ebp+0xb]
  7dc3fd:	88 07                	mov    BYTE PTR [edi],al
  7dc3ff:	33 f6                	xor    esi,esi
  7dc401:	6a 28                	push   0x28
  7dc403:	89 77 08             	mov    DWORD PTR [edi+0x8],esi
  7dc406:	e8 5d 4e 0b 00       	call   0x891268
  7dc40b:	83 c4 04             	add    esp,0x4
  7dc40e:	3b c6                	cmp    eax,esi
  7dc410:	74 3c                	je     0x7dc44e
  7dc412:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7dc415:	89 00                	mov    DWORD PTR [eax],eax
  7dc417:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7dc41a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7dc41d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7dc420:	89 77 10             	mov    DWORD PTR [edi+0x10],esi
  7dc423:	89 77 14             	mov    DWORD PTR [edi+0x14],esi
  7dc426:	89 77 18             	mov    DWORD PTR [edi+0x18],esi
  7dc429:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  7dc42d:	d9 e8                	fld1
  7dc42f:	6a 08                	push   0x8
  7dc431:	d9 5f 28             	fstp   DWORD PTR [edi+0x28]
  7dc434:	e8 f7 07 00 00       	call   0x7dcc30
  7dc439:	8b c7                	mov    eax,edi
  7dc43b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dc43e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dc445:	59                   	pop    ecx
  7dc446:	5f                   	pop    edi
  7dc447:	5e                   	pop    esi
  7dc448:	8b e5                	mov    esp,ebp
  7dc44a:	5d                   	pop    ebp
  7dc44b:	c2 04 00             	ret    0x4
  7dc44e:	8d                   	.byte 0x8d
  7dc44f:	4d                   	dec    ebp

```

### name manager registration: `0x007B8480～0x007B8674`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b8480 <.text+0x3b7480>:
  7b8480:	55                   	push   ebp
  7b8481:	8b ec                	mov    ebp,esp
  7b8483:	6a ff                	push   0xffffffff
  7b8485:	68 80 26 92 00       	push   0x922680
  7b848a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7b8490:	50                   	push   eax
  7b8491:	83 ec 4c             	sub    esp,0x4c
  7b8494:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7b8499:	33 c5                	xor    eax,ebp
  7b849b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7b849e:	53                   	push   ebx
  7b849f:	56                   	push   esi
  7b84a0:	57                   	push   edi
  7b84a1:	50                   	push   eax
  7b84a2:	8d 45 f4             	lea    eax,[ebp-0xc]
  7b84a5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7b84ab:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b84ae:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b84b1:	8b fa                	mov    edi,edx
  7b84b3:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  7b84b6:	8b c7                	mov    eax,edi
  7b84b8:	8b f1                	mov    esi,ecx
  7b84ba:	89 5d a8             	mov    DWORD PTR [ebp-0x58],ebx
  7b84bd:	c7 45 cc 0f 00 00 00 	mov    DWORD PTR [ebp-0x34],0xf
  7b84c4:	c7 45 c8 00 00 00 00 	mov    DWORD PTR [ebp-0x38],0x0
  7b84cb:	c6 45 b8 00          	mov    BYTE PTR [ebp-0x48],0x0
  7b84cf:	8d 48 01             	lea    ecx,[eax+0x1]
  7b84d2:	8a 10                	mov    dl,BYTE PTR [eax]
  7b84d4:	40                   	inc    eax
  7b84d5:	84 d2                	test   dl,dl
  7b84d7:	75 f9                	jne    0x7b84d2
  7b84d9:	2b c1                	sub    eax,ecx
  7b84db:	50                   	push   eax
  7b84dc:	57                   	push   edi
  7b84dd:	8d 4d b8             	lea    ecx,[ebp-0x48]
  7b84e0:	e8 8b a5 c4 ff       	call   0x402a70
  7b84e5:	8d 4d b8             	lea    ecx,[ebp-0x48]
  7b84e8:	51                   	push   ecx
  7b84e9:	8d 55 ac             	lea    edx,[ebp-0x54]
  7b84ec:	52                   	push   edx
  7b84ed:	8d 43 04             	lea    eax,[ebx+0x4]
  7b84f0:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7b84f7:	e8 f4 01 00 00       	call   0x7b86f0
  7b84fc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7b8503:	83 7d cc 10          	cmp    DWORD PTR [ebp-0x34],0x10
  7b8507:	72 0c                	jb     0x7b8515
  7b8509:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  7b850c:	50                   	push   eax
  7b850d:	e8 fa 8c 0d 00       	call   0x89120c
  7b8512:	83 c4 04             	add    esp,0x4
  7b8515:	8b 5b 08             	mov    ebx,DWORD PTR [ebx+0x8]
  7b8518:	8b 4d ac             	mov    ecx,DWORD PTR [ebp-0x54]
  7b851b:	3b cb                	cmp    ecx,ebx
  7b851d:	74 1c                	je     0x7b853b
  7b851f:	8b 41 24             	mov    eax,DWORD PTR [ecx+0x24]
  7b8522:	ff 40 5c             	inc    DWORD PTR [eax+0x5c]
  7b8525:	8b 45 b0             	mov    eax,DWORD PTR [ebp-0x50]
  7b8528:	85 c0                	test   eax,eax
  7b852a:	74 05                	je     0x7b8531
  7b852c:	8b 49 24             	mov    ecx,DWORD PTR [ecx+0x24]
  7b852f:	89 08                	mov    DWORD PTR [eax],ecx
  7b8531:	b8 01 00 00 00       	mov    eax,0x1
  7b8536:	e9 c6 00 00 00       	jmp    0x7b8601
  7b853b:	8b c6                	mov    eax,esi
  7b853d:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7b8544:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7b854b:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7b854f:	8d 50 01             	lea    edx,[eax+0x1]
  7b8552:	8a 08                	mov    cl,BYTE PTR [eax]
  7b8554:	40                   	inc    eax
  7b8555:	84 c9                	test   cl,cl
  7b8557:	75 f9                	jne    0x7b8552
  7b8559:	2b c2                	sub    eax,edx
  7b855b:	50                   	push   eax
  7b855c:	56                   	push   esi
  7b855d:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7b8560:	e8 0b a5 c4 ff       	call   0x402a70
  7b8565:	8b c7                	mov    eax,edi
  7b8567:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7b856e:	8d 50 01             	lea    edx,[eax+0x1]
  7b8571:	8a 08                	mov    cl,BYTE PTR [eax]
  7b8573:	40                   	inc    eax
  7b8574:	84 c9                	test   cl,cl
  7b8576:	75 f9                	jne    0x7b8571
  7b8578:	2b c2                	sub    eax,edx
  7b857a:	50                   	push   eax
  7b857b:	57                   	push   edi
  7b857c:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7b857f:	e8 3c 9a c4 ff       	call   0x401fc0
  7b8584:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7b8588:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  7b858b:	73 03                	jae    0x7b8590
  7b858d:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7b8590:	68 e0 d1 be 00       	push   0xbed1e0
  7b8595:	50                   	push   eax
  7b8596:	e8 d5 c1 f5 ff       	call   0x714770
  7b859b:	8b d8                	mov    ebx,eax
  7b859d:	83 c4 08             	add    esp,0x8
  7b85a0:	85 db                	test   ebx,ebx
  7b85a2:	74 49                	je     0x7b85ed
  7b85a4:	68 8c 00 00 00       	push   0x8c
  7b85a9:	e8 ba 8c 0d 00       	call   0x891268
  7b85ae:	83 c4 04             	add    esp,0x4
  7b85b1:	85 c0                	test   eax,eax
  7b85b3:	74 0b                	je     0x7b85c0
  7b85b5:	8b f0                	mov    esi,eax
  7b85b7:	e8 24 49 02 00       	call   0x7dcee0
  7b85bc:	8b f0                	mov    esi,eax
  7b85be:	eb 02                	jmp    0x7b85c2
  7b85c0:	33 f6                	xor    esi,esi
  7b85c2:	8b 03                	mov    eax,DWORD PTR [ebx]
  7b85c4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7b85c7:	6a 02                	push   0x2
  7b85c9:	6a 01                	push   0x1
  7b85cb:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7b85ce:	51                   	push   ecx
  7b85cf:	8b cb                	mov    ecx,ebx
  7b85d1:	ff d2                	call   edx
  7b85d3:	8b 03                	mov    eax,DWORD PTR [ebx]
  7b85d5:	8b 50 34             	mov    edx,DWORD PTR [eax+0x34]
  7b85d8:	6a 00                	push   0x0
  7b85da:	6a 00                	push   0x0
  7b85dc:	8b cb                	mov    ecx,ebx
  7b85de:	ff d2                	call   edx
  7b85e0:	66 8b 45 b4          	mov    ax,WORD PTR [ebp-0x4c]
  7b85e4:	3c 3c                	cmp    al,0x3c
  7b85e6:	75 37                	jne    0x7b861f
  7b85e8:	80 fc 3f             	cmp    ah,0x3f
  7b85eb:	74 3b                	je     0x7b8628
  7b85ed:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7b85f1:	72 0c                	jb     0x7b85ff
  7b85f3:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7b85f6:	52                   	push   edx
  7b85f7:	e8 10 8c 0d 00       	call   0x89120c
  7b85fc:	83 c4 04             	add    esp,0x4
  7b85ff:	33 c0                	xor    eax,eax
  7b8601:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7b8604:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b860b:	59                   	pop    ecx
  7b860c:	5f                   	pop    edi
  7b860d:	5e                   	pop    esi
  7b860e:	5b                   	pop    ebx
  7b860f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  7b8612:	33 cd                	xor    ecx,ebp
  7b8614:	e8 e8 89 0d 00       	call   0x891001
  7b8619:	8b e5                	mov    esp,ebp
  7b861b:	5d                   	pop    ebp
  7b861c:	c2 08 00             	ret    0x8
  7b861f:	3c 45                	cmp    al,0x45
  7b8621:	75 ca                	jne    0x7b85ed
  7b8623:	80 fc 58             	cmp    ah,0x58
  7b8626:	75 c5                	jne    0x7b85ed
  7b8628:	8b 03                	mov    eax,DWORD PTR [ebx]
  7b862a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7b862d:	8b cb                	mov    ecx,ebx
  7b862f:	ff d2                	call   edx
  7b8631:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  7b8634:	bb 10 00 00 00       	mov    ebx,0x10
  7b8639:	39 5d e8             	cmp    DWORD PTR [ebp-0x18],ebx
  7b863c:	73 03                	jae    0x7b8641
  7b863e:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7b8641:	56                   	push   esi
  7b8642:	e8 59 4c 02 00       	call   0x7dd2a0
  7b8647:	8b 45 a8             	mov    eax,DWORD PTR [ebp-0x58]
  7b864a:	56                   	push   esi
  7b864b:	50                   	push   eax
  7b864c:	8b cf                	mov    ecx,edi
  7b864e:	e8 7d fc ff ff       	call   0x7b82d0
  7b8653:	8b 45 b0             	mov    eax,DWORD PTR [ebp-0x50]
  7b8656:	85 c0                	test   eax,eax
  7b8658:	74 02                	je     0x7b865c
  7b865a:	89 30                	mov    DWORD PTR [eax],esi
  7b865c:	39 5d e8             	cmp    DWORD PTR [ebp-0x18],ebx
  7b865f:	72 0c                	jb     0x7b866d
  7b8661:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  7b8664:	51                   	push   ecx
  7b8665:	e8 a2 8b 0d 00       	call   0x89120c
  7b866a:	83 c4 04             	add    esp,0x4
  7b866d:	b8 01 00 00 00       	mov    eax,0x1
  7b8672:	eb 8d                	jmp    0x7b8601

```

### node insertion: `0x007B82D0～0x007B8474`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b82d0 <.text+0x3b72d0>:
  7b82d0:	55                   	push   ebp
  7b82d1:	8b ec                	mov    ebp,esp
  7b82d3:	83 e4 f8             	and    esp,0xfffffff8
  7b82d6:	6a ff                	push   0xffffffff
  7b82d8:	68 80 4e 91 00       	push   0x914e80
  7b82dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7b82e3:	50                   	push   eax
  7b82e4:	83 ec 58             	sub    esp,0x58
  7b82e7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7b82ec:	33 c4                	xor    eax,esp
  7b82ee:	89 44 24 50          	mov    DWORD PTR [esp+0x50],eax
  7b82f2:	53                   	push   ebx
  7b82f3:	56                   	push   esi
  7b82f4:	57                   	push   edi
  7b82f5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7b82fa:	33 c4                	xor    eax,esp
  7b82fc:	50                   	push   eax
  7b82fd:	8d 44 24 68          	lea    eax,[esp+0x68]
  7b8301:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  7b8454:	8b 4c 24 68          	mov    ecx,DWORD PTR [esp+0x68]
  7b8458:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b845f:	59                   	pop    ecx
  7b8460:	5f                   	pop    edi
  7b8461:	5e                   	pop    esi
  7b8462:	5b                   	pop    ebx
  7b8463:	8b 4c 24 50          	mov    ecx,DWORD PTR [esp+0x50]
  7b8467:	33 cc                	xor    ecx,esp
  7b8469:	e8 93 8b 0d 00       	call   0x891001
  7b846e:	8b e5                	mov    esp,ebp
  7b8470:	5d                   	pop    ebp
  7b8471:	c2 08 00             	ret    0x8

```

### node copy constructor: `0x00719B90～0x00719C40`

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
  719c14:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  719c1b:	59                   	pop    ecx
  719c1c:	5f                   	pop    edi
  719c1d:	5e                   	pop    esi
  719c1e:	5b                   	pop    ebx
  719c1f:	8b e5                	mov    esp,ebp
  719c21:	5d                   	pop    ebp
  719c22:	c2 0c 00             	ret    0xc
  719c25:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  719c28:	51                   	push   ecx
  719c29:	e8 de 75 17 00       	call   0x89120c
  719c2e:	83 c4 04             	add    esp,0x4
  719c31:	33 c0                	xor    eax,eax
  719c33:	50                   	push   eax
  719c34:	50                   	push   eax
  719c35:	e8 b6 2d 18 00       	call   0x89c9f0
  719c3a:	8d 55 10             	lea    edx,[ebp+0x10]
  719c3d:	52                   	push   edx
  719c3e:	8d                   	.byte 0x8d
  719c3f:	4d                   	dec    ebp

```

### global registry registration caller: `0x007D6F40～0x007D71EA`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d6f40 <.text+0x3d5f40>:
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
  7d6f8b:	6a 68                	push   0x68
  7d6f8d:	e8 d6 a2 0b 00       	call   0x891268
  7d6f92:	83 c4 04             	add    esp,0x4
  7d6f95:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d6f99:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x9
  7d6fa0:	09 
  7d6fa1:	85 c0                	test   eax,eax
  7d6fa3:	74 6a                	je     0x7d700f
  7d6fa5:	83 7b 14 10          	cmp    DWORD PTR [ebx+0x14],0x10
  7d6fa9:	d9 ee                	fldz
  7d6fab:	d9 54 24 24          	fst    DWORD PTR [esp+0x24]
  7d6faf:	d9 54 24 28          	fst    DWORD PTR [esp+0x28]
  7d6fb3:	d9 54 24 2c          	fst    DWORD PTR [esp+0x2c]
  7d6fb7:	72 04                	jb     0x7d6fbd
  7d6fb9:	8b 13                	mov    edx,DWORD PTR [ebx]
  7d6fbb:	eb 02                	jmp    0x7d6fbf
  7d6fbd:	8b d3                	mov    edx,ebx
  7d6fbf:	d9 e8                	fld1
  7d6fc1:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  7d6fc5:	51                   	push   ecx
  7d6fc6:	d9 1c 24             	fstp   DWORD PTR [esp]
  7d6fc9:	d9 43 78             	fld    DWORD PTR [ebx+0x78]
  7d6fcc:	6a 00                	push   0x0
  7d6fce:	6a 01                	push   0x1
  7d6fd0:	83 ec 0c             	sub    esp,0xc
  7d6fd3:	8b cc                	mov    ecx,esp
  7d6fd5:	89 31                	mov    DWORD PTR [ecx],esi
  7d6fd7:	8b 74 24 40          	mov    esi,DWORD PTR [esp+0x40]
  7d6fdb:	89 71 04             	mov    DWORD PTR [ecx+0x4],esi
  7d6fde:	8b 74 24 44          	mov    esi,DWORD PTR [esp+0x44]
  7d6fe2:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  7d6fe5:	8b 73 6c             	mov    esi,DWORD PTR [ebx+0x6c]
  7d6fe8:	83 ec 0c             	sub    esp,0xc
  7d6feb:	8b cc                	mov    ecx,esp
  7d6fed:	89 31                	mov    DWORD PTR [ecx],esi
  7d6fef:	8b 73 70             	mov    esi,DWORD PTR [ebx+0x70]
  7d6ff2:	89 71 04             	mov    DWORD PTR [ecx+0x4],esi
  7d6ff5:	8b 73 74             	mov    esi,DWORD PTR [ebx+0x74]
  7d6ff8:	83 ec 08             	sub    esp,0x8
  7d6ffb:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  7d6ffe:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7d7002:	8b f0                	mov    esi,eax
  7d7004:	d9 1c 24             	fstp   DWORD PTR [esp]
  7d7007:	52                   	push   edx
  7d7008:	e8 83 f7 ff ff       	call   0x7d6790
  7d700d:	eb 02                	jmp    0x7d7011
  7d700f:	33 c0                	xor    eax,eax
  7d7011:	8b 74 24 1c          	mov    esi,DWORD PTR [esp+0x1c]
  7d7015:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d701c:	04 
  7d701d:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d7021:	8d 7e 4c             	lea    edi,[esi+0x4c]
  7d7024:	8d 44 24 10          	lea    eax,[esp+0x10]
  7d7028:	e8 23 43 fe ff       	call   0x7bb350
  7d702d:	6a 68                	push   0x68
  7d702f:	e8 34 a2 0b 00       	call   0x891268
  7d7034:	83 c4 04             	add    esp,0x4
  7d7037:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d703b:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0xa
  7d7042:	0a 
  7d7043:	85 c0                	test   eax,eax
  7d7045:	74 79                	je     0x7d70c0
  7d7047:	83 7b 4c 10          	cmp    DWORD PTR [ebx+0x4c],0x10
  7d704b:	d9 ee                	fldz
  7d704d:	d9 54 24 24          	fst    DWORD PTR [esp+0x24]
  7d7051:	8d 53 38             	lea    edx,[ebx+0x38]
  7d7054:	d9 54 24 28          	fst    DWORD PTR [esp+0x28]
  7d7058:	d9 54 24 2c          	fst    DWORD PTR [esp+0x2c]
  7d705c:	d9 54 24 34          	fst    DWORD PTR [esp+0x34]
  7d7060:	d9 54 24 38          	fst    DWORD PTR [esp+0x38]
  7d7064:	d9 54 24 3c          	fst    DWORD PTR [esp+0x3c]
  7d7068:	72 02                	jb     0x7d706c
  7d706a:	8b 12                	mov    edx,DWORD PTR [edx]
  7d706c:	d9 e8                	fld1
  7d706e:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  7d7072:	51                   	push   ecx
  7d7073:	d9 14 24             	fst    DWORD PTR [esp]
  7d7076:	6a 00                	push   0x0
  7d7078:	6a 01                	push   0x1
  7d707a:	83 ec 0c             	sub    esp,0xc
  7d707d:	8b cc                	mov    ecx,esp
  7d707f:	89 31                	mov    DWORD PTR [ecx],esi
  7d7081:	8b 74 24 40          	mov    esi,DWORD PTR [esp+0x40]
  7d7085:	89 71 04             	mov    DWORD PTR [ecx+0x4],esi
  7d7088:	8b 74 24 44          	mov    esi,DWORD PTR [esp+0x44]
  7d708c:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  7d708f:	8b 74 24 4c          	mov    esi,DWORD PTR [esp+0x4c]
  7d7093:	83 ec 0c             	sub    esp,0xc
  7d7096:	8b cc                	mov    ecx,esp
  7d7098:	89 31                	mov    DWORD PTR [ecx],esi
  7d709a:	8b 74 24 5c          	mov    esi,DWORD PTR [esp+0x5c]
  7d709e:	89 71 04             	mov    DWORD PTR [ecx+0x4],esi
  7d70a1:	8b 74 24 60          	mov    esi,DWORD PTR [esp+0x60]
  7d70a5:	83 ec 08             	sub    esp,0x8
  7d70a8:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  7d70ab:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7d70af:	8b f0                	mov    esi,eax
  7d70b1:	d9 1c 24             	fstp   DWORD PTR [esp]
  7d70b4:	52                   	push   edx
  7d70b5:	e8 d6 f6 ff ff       	call   0x7d6790
  7d70ba:	8b 74 24 1c          	mov    esi,DWORD PTR [esp+0x1c]
  7d70be:	eb 02                	jmp    0x7d70c2
  7d70c0:	33 c0                	xor    eax,eax
  7d70c2:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d70c9:	04 
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
  7d7146:	6a 29                	push   0x29
  7d7148:	68 e0 01 c5 00       	push   0xc501e0
  7d714d:	8d 8c 24 80 00 00 00 	lea    ecx,[esp+0x80]
  7d7154:	c7 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],0xf
  7d715b:	0f 00 00 00 
  7d715f:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  7d7166:	88 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],al
  7d716d:	e8 fe b8 c2 ff       	call   0x402a70
  7d7172:	6a ff                	push   0xffffffff
  7d7174:	6a 00                	push   0x0
  7d7176:	53                   	push   ebx
  7d7177:	8d 8c 24 84 00 00 00 	lea    ecx,[esp+0x84]
  7d717e:	c6 84 24 cc 00 00 00 	mov    BYTE PTR [esp+0xcc],0xc
  7d7185:	0c 
  7d7186:	e8 45 ad c2 ff       	call   0x401ed0
  7d718b:	6a 07                	push   0x7
  7d718d:	68 0c 02 c5 00       	push   0xc5020c
  7d7192:	8d 8c 24 80 00 00 00 	lea    ecx,[esp+0x80]
  7d7199:	e8 22 ae c2 ff       	call   0x401fc0
  7d719e:	6a ff                	push   0xffffffff
  7d71a0:	6a 00                	push   0x0
  7d71a2:	8d 54 24 48          	lea    edx,[esp+0x48]
  7d71a6:	52                   	push   edx
  7d71a7:	8d 8c 24 84 00 00 00 	lea    ecx,[esp+0x84]
  7d71ae:	e8 1d ad c2 ff       	call   0x401ed0
  7d71b3:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  7d71b7:	39 bc 24 8c 00 00 00 	cmp    DWORD PTR [esp+0x8c],edi
  7d71be:	73 04                	jae    0x7d71c4
  7d71c0:	8d 44 24 78          	lea    eax,[esp+0x78]
  7d71c4:	6a 00                	push   0x0
  7d71c6:	68 14 02 c5 00       	push   0xc50214
  7d71cb:	50                   	push   eax
  7d71cc:	6a 00                	push   0x0
  7d71ce:	ff 15 90 24 bd 00    	call   DWORD PTR ds:0xbd2490
  7d71d4:	39 bc 24 8c 00 00 00 	cmp    DWORD PTR [esp+0x8c],edi
  7d71db:	72 0d                	jb     0x7d71ea
  7d71dd:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  7d71e1:	50                   	push   eax
  7d71e2:	e8 25 a0 0b 00       	call   0x89120c
  7d71e7:	83 c4 04             	add    esp,0x4

```

### 0x68 descriptor initializer: `0x007D6790～0x007D67F0`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d6790 <.text+0x3d5790>:
  7d6790:	55                   	push   ebp
  7d6791:	8b ec                	mov    ebp,esp
  7d6793:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  7d6796:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  7d6799:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  7d679c:	d9 5e 40             	fstp   DWORD PTR [esi+0x40]
  7d679f:	8b 55 1c             	mov    edx,DWORD PTR [ebp+0x1c]
  7d67a2:	d9 45 10             	fld    DWORD PTR [ebp+0x10]
  7d67a5:	89 46 48             	mov    DWORD PTR [esi+0x48],eax
  7d67a8:	d9 5e 44             	fstp   DWORD PTR [esi+0x44]
  7d67ab:	8b 45 20             	mov    eax,DWORD PTR [ebp+0x20]
  7d67ae:	d9 45 34             	fld    DWORD PTR [ebp+0x34]
  7d67b1:	89 4e 4c             	mov    DWORD PTR [esi+0x4c],ecx
  7d67b4:	d9 5e 64             	fstp   DWORD PTR [esi+0x64]
  7d67b7:	8b 4d 24             	mov    ecx,DWORD PTR [ebp+0x24]
  7d67ba:	89 56 50             	mov    DWORD PTR [esi+0x50],edx
  7d67bd:	8b 55 28             	mov    edx,DWORD PTR [ebp+0x28]
  7d67c0:	89 46 54             	mov    DWORD PTR [esi+0x54],eax
  7d67c3:	8a 45 2c             	mov    al,BYTE PTR [ebp+0x2c]
  7d67c6:	89 4e 58             	mov    DWORD PTR [esi+0x58],ecx
  7d67c9:	8a 4d 30             	mov    cl,BYTE PTR [ebp+0x30]
  7d67cc:	89 56 5c             	mov    DWORD PTR [esi+0x5c],edx
  7d67cf:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7d67d2:	6a 40                	push   0x40
  7d67d4:	52                   	push   edx
  7d67d5:	56                   	push   esi
  7d67d6:	88 46 60             	mov    BYTE PTR [esi+0x60],al
  7d67d9:	88 4e 61             	mov    BYTE PTR [esi+0x61],cl
  7d67dc:	e8 bf 23 0c 00       	call   0x898ba0
  7d67e1:	83 c4 0c             	add    esp,0xc
  7d67e4:	8b c6                	mov    eax,esi
  7d67e6:	5d                   	pop    ebp
  7d67e7:	c2 30 00             	ret    0x30
  7d67ea:	cc                   	int3
  7d67eb:	cc                   	int3
  7d67ec:	cc                   	int3
  7d67ed:	cc                   	int3
  7d67ee:	cc                   	int3
  7d67ef:	cc                   	int3

```

### 0x8c manager initializer: `0x007DCEE0～0x007DCF40`

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
  7dcf3e:	cc                   	int3
  7dcf3f:	cc                   	int3

```

### binding lookup: `0x007BDF90～0x007BE0ED`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf90 <.text+0x3bcf90>:
  7bdf90:	55                   	push   ebp
  7bdf91:	8b ec                	mov    ebp,esp
  7bdf93:	6a ff                	push   0xffffffff
  7bdf95:	68 b6 8a 91 00       	push   0x918ab6
  7bdf9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7bdfa0:	50                   	push   eax
  7bdfa1:	83 ec 2c             	sub    esp,0x2c
  7bdfa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7bdfa9:	33 c5                	xor    eax,ebp
  7bdfab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7bdfae:	53                   	push   ebx
  7bdfaf:	56                   	push   esi
  7bdfb0:	57                   	push   edi
  7bdfb1:	50                   	push   eax
  7bdfb2:	8d 45 f4             	lea    eax,[ebp-0xc]
  7bdfb5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7bdfbb:	8b f1                	mov    esi,ecx
  7bdfbd:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7bdfc0:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  7bdfc3:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7bdfc6:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7bdfc9:	0f 84 f4 00 00 00    	je     0x7be0c3
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
  7be093:	83 7b 08 00          	cmp    DWORD PTR [ebx+0x8],0x0
  7be097:	75 13                	jne    0x7be0ac
  7be099:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7be09c:	6a 00                	push   0x0
  7be09e:	50                   	push   eax
  7be09f:	68 ec fc c4 00       	push   0xc4fcec
  7be0a4:	6a 00                	push   0x0
  7be0a6:	ff 15 90 24 bd 00    	call   DWORD PTR ds:0xbd2490
  7be0ac:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7be0af:	8b 4d cc             	mov    ecx,DWORD PTR [ebp-0x34]
  7be0b2:	83 c0 04             	add    eax,0x4
  7be0b5:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7be0b8:	3b 41 08             	cmp    eax,DWORD PTR [ecx+0x8]
  7be0bb:	0f 85 10 ff ff ff    	jne    0x7bdfd1
  7be0c1:	8b f1                	mov    esi,ecx
  7be0c3:	56                   	push   esi
  7be0c4:	e8 87 00 00 00       	call   0x7be150
  7be0c9:	c7 46 74 01 00 00 00 	mov    DWORD PTR [esi+0x74],0x1
  7be0d0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7be0d3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7be0da:	59                   	pop    ecx
  7be0db:	5f                   	pop    edi
  7be0dc:	5e                   	pop    esi
  7be0dd:	5b                   	pop    ebx
  7be0de:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  7be0e1:	33 cd                	xor    ecx,ebp
  7be0e3:	e8 19 2f 0d 00       	call   0x891001
  7be0e8:	8b e5                	mov    esp,ebp
  7be0ea:	5d                   	pop    ebp
  7be0eb:	c3                   	ret
  7be0ec:	cc                   	int3

```

### name based deletion: `0x007DC510～0x007DC5CD`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc510 <.text+0x3db510>:
  7dc510:	55                   	push   ebp
  7dc511:	8b ec                	mov    ebp,esp
  7dc513:	6a ff                	push   0xffffffff
  7dc515:	68 b0 49 91 00       	push   0x9149b0
  7dc51a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc520:	50                   	push   eax
  7dc521:	83 ec 44             	sub    esp,0x44
  7dc524:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc529:	33 c5                	xor    eax,ebp
  7dc52b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7dc52e:	53                   	push   ebx
  7dc52f:	56                   	push   esi
  7dc530:	57                   	push   edi
  7dc531:	50                   	push   eax
  7dc532:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dc535:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc53b:	8b fa                	mov    edi,edx
  7dc53d:	33 db                	xor    ebx,ebx
  7dc53f:	8b c7                	mov    eax,edi
  7dc541:	8b f1                	mov    esi,ecx
  7dc543:	c7 45 cc 0f 00 00 00 	mov    DWORD PTR [ebp-0x34],0xf
  7dc54a:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  7dc54d:	88 5d b8             	mov    BYTE PTR [ebp-0x48],bl
  7dc550:	8d 50 01             	lea    edx,[eax+0x1]
  7dc553:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc555:	40                   	inc    eax
  7dc556:	3a cb                	cmp    cl,bl
  7dc558:	75 f9                	jne    0x7dc553
  7dc55a:	2b c2                	sub    eax,edx
  7dc55c:	50                   	push   eax
  7dc55d:	57                   	push   edi
  7dc55e:	8d 4d b8             	lea    ecx,[ebp-0x48]
  7dc561:	e8 0a 65 c2 ff       	call   0x402a70
  7dc566:	8d 45 b8             	lea    eax,[ebp-0x48]
  7dc569:	50                   	push   eax
  7dc56a:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc56d:	51                   	push   ecx
  7dc56e:	8b c6                	mov    eax,esi
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
  7dc5be:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc5c1:	51                   	push   ecx
  7dc5c2:	e8 b9 c0 fd ff       	call   0x7b8680
  7dc5c7:	8b 45 b0             	mov    eax,DWORD PTR [ebp-0x50]
  7dc5ca:	eb 6e                	jmp    0x7dc63a
  7dc5cc:	8b                   	.byte 0x8b

```

### binding update gate: `0x007BDF40～0x007BDF90`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf40 <.text+0x3bcf40>:
  7bdf40:	55                   	push   ebp
  7bdf41:	8b ec                	mov    ebp,esp
  7bdf43:	53                   	push   ebx
  7bdf44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf47:	56                   	push   esi
  7bdf48:	57                   	push   edi
  7bdf49:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf4c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf4f:	33 f6                	xor    esi,esi
  7bdf51:	c1 ff 02             	sar    edi,0x2
  7bdf54:	85 ff                	test   edi,edi
  7bdf56:	74 31                	je     0x7bdf89
  7bdf58:	eb 06                	jmp    0x7bdf60
  7bdf5a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf60:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf63:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf66:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf69:	85 c9                	test   ecx,ecx
  7bdf6b:	74 17                	je     0x7bdf84
  7bdf6d:	80 38 00             	cmp    BYTE PTR [eax],0x0
  7bdf70:	75 12                	jne    0x7bdf84
  7bdf72:	83 b9 80 00 00 00 00 	cmp    DWORD PTR [ecx+0x80],0x0
  7bdf79:	75 09                	jne    0x7bdf84
  7bdf7b:	8b c1                	mov    eax,ecx
  7bdf7d:	8b 10                	mov    edx,DWORD PTR [eax]
  7bdf7f:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  7bdf82:	ff d0                	call   eax
  7bdf84:	46                   	inc    esi
  7bdf85:	3b f7                	cmp    esi,edi
  7bdf87:	72 d7                	jb     0x7bdf60
  7bdf89:	5f                   	pop    edi
  7bdf8a:	5e                   	pop    esi
  7bdf8b:	5b                   	pop    ebx
  7bdf8c:	5d                   	pop    ebp
  7bdf8d:	c2 04 00             	ret    0x4

```

### another binding dispatcher: `0x007BDF00～0x007BDF40`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf00 <.text+0x3bcf00>:
  7bdf00:	55                   	push   ebp
  7bdf01:	8b ec                	mov    ebp,esp
  7bdf03:	53                   	push   ebx
  7bdf04:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf07:	56                   	push   esi
  7bdf08:	57                   	push   edi
  7bdf09:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf0c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf0f:	33 f6                	xor    esi,esi
  7bdf11:	c1 ff 02             	sar    edi,0x2
  7bdf14:	85 ff                	test   edi,edi
  7bdf16:	74 21                	je     0x7bdf39
  7bdf18:	eb 06                	jmp    0x7bdf20
  7bdf1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf20:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf23:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf26:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf29:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bdf2b:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7bdf2e:	8b 52 20             	mov    edx,DWORD PTR [edx+0x20]
  7bdf31:	50                   	push   eax
  7bdf32:	ff d2                	call   edx
  7bdf34:	46                   	inc    esi
  7bdf35:	3b f7                	cmp    esi,edi
  7bdf37:	72 e7                	jb     0x7bdf20
  7bdf39:	5f                   	pop    edi
  7bdf3a:	5e                   	pop    esi
  7bdf3b:	5b                   	pop    ebx
  7bdf3c:	5d                   	pop    ebp
  7bdf3d:	c2 08 00             	ret    0x8

```