# T08-097 — 名稱樹節點 +0x24 實際寫入、Provider 指標來源與 binding 間接調度

- 研究者：`chatgpt-web roy`
- 時間（Asia/Taipei）：`2026-10-27T11:10:50+08:00`
- 研究檔案：`Tartaros.bin`；SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（已與交接值驗證一致）
- 狀態：本段不提交 GitHub；新發現以原始 BIN 為依據。

## 摘要與本段實質突破

**已確認：名稱樹節點確實在 `0x00719B90` 配置 0x28 bytes；節點 `+0x24` 保存由 `0x007B82D0` 第二參數傳入的 0x8C-byte 管理物件指標。** 這是 T08-095 `node+0x24` 經 `vtable+0x10` 取得 binding 之上游來源的關鍵銜接。此前 T08-096 僅建立兩端路徑，未完整核對節點寫入。

### 已確認的新增證據

1. `0x007B8641 push esi; 0x007B864A push esi; 0x007B864B push eax; 0x007B864C mov ecx,edi; 0x007B864E call 0x007B82D0`：`esi` 為 `0x007B85A4` 申請並以 `0x007DCEE0` 初始化的 0x8C-byte 管理物件；呼叫 `0x007B82D0` 前它作為第二個堆疊參數，第一參數為名稱相關指標。
2. `0x007B8307 mov eax,[ebp+0x0C]`、`0x007B830F mov [esp+0x14],eax`：登記函式接收並保留關聯物件指標；`0x007B83DB mov edx,[esp+0x14]` 與 `0x007B83DF mov [esp+0x5C],edx`：裝入供樹節點複製的臨時值。
3. `0x007B83FA call 0x00719B90`：配置樹節點；建構函式 `0x00719BBB push 0x28`、`0x00719BC0 call 0x00891268`；`0x00719C09 mov eax,[ebx+0x1C]`、`0x00719C0C mov [esi+0x1C],eax`，其中 `esi=node+0x08`，所以 **`node+0x24 ← tempValue+0x1C`**。
4. `0x007BDF90` 內 `0x007BE082 mov ecx,[eax+0x24]`、`0x007BE089 mov eax,[ecx]`、`0x007BE08B mov edx,[eax+0x10]`、`0x007BE08E call edx`、`0x007BE090 mov [ebx+0x08],eax`：透過名稱樹節點之管理物件的 vtable slot +0x10 得到 binding 並寫回 item+0x08。
5. `0x007BDF40` 以 `cmp dword ptr [ecx+0x80],0` 後虛擬呼叫 `vtable+0x18`；`0x007BDF00` 直接對 item 的 binding 呼叫 `vtable+0x20` 並帶入一個參數。兩者是否指向同一實作類別，仍未知。
6. `0x007B82D0` 有先查詢同名節點的阻擋路徑：`0x007B8395 xor eax,eax`；只有未命中時才會配置新節點。`0x007B8419 mov [ebx+0x0C],ecx` 增加容器計數，`0x007B841C mov [edi+0x04],eax` 與 `0x007B8436 call 0x007D1080` 完成樹鏈結／修正。

## 暫定結構與指標身分

```cpp
struct NameTreeNode_28 {            // 0x28 bytes；部分偏移待續證
    void* left_or_parent;          // +0x00 暫定 RB-tree 鏈結
    void* right_or_parent;         // +0x04 暫定 RB-tree 鏈結
    std::string key;              // +0x08 .. +0x23, 依字串建構流程暫定
    void* provider;                // +0x24 已確認：+0x08 payload 之 +0x1C
};

struct NameProvider_8C {          // 0x8C bytes；非 binding 本身
    uint32_t identity;            // +0x00 由 0x00FBA844 分配
    char name[/* variable layout*/]; // +0x04 起字串；實際長度須另證
    // ...
    uint32_t holdCount;           // +0x5C
    uint32_t activeCount;         // +0x60
    // +0x64 同步結構，+0x7C .. +0x84 復用陣列
};

struct ResourceItem {
    // ...
    const char* name;             // +0x04
    void* binding;                // +0x08，從 provider 虛擬 slot +0x10 回傳
};
```

> 注意：`NameProvider_8C+0x80` 是復用容器的一部分；而 `binding+0x80` 是 T08-092 的條件欄位，兩者**不相同**。`node+0x24` 絕不等同 binding 指標。

### 暫定 C++ 偽程式碼（按 BIN 呼叫/資料流重建）

```cpp
bool registerNamedProvider(const char* key, NameProvider_8C* provider, NameTree* tree) {
    if (tree->contains(key)) return false;
    if (tree->field30 >= 1) provider->field44 = 1;
    TmpPair temp;
    temp.key = key;
    temp.provider = provider;   // temporary payload +0x1C
    auto node = allocate_28_and_copy_payload(temp);
    // node+0x24 = temp.provider;
    tree->insertAndRebalance(node); // 0x007D1080 and surrounding code
    return true;
}

void resolveResourceBinding(ResourceItem* item) {
    auto node = lookupName(item->name);
    if (node != sentinel && node->provider) {
        item->binding = node->provider->vtable[0x10/4](node->provider);
    }
}
```

## 調用者 / 被調用者與研究鏈

- `0x007B84xx → 0x007B85A4 (malloc 0x8C) → 0x007DCEE0 (provider 初始化) → 0x007DD2A0 (處理資源內容) → 0x007B82D0 (登記) → 0x00719B90 (配置並拷貝 node)`。
- `0x007BDF90 → 0x007B86F0 (名稱索引) → node+0x24 (provider) → vtable+0x10 → item+0x08 (binding)`。
- `0x007BDF00 → item+0x08 → vtable+0x20`；`0x007BDF40 → item+0x08 + guard(binding+0x80==0) → vtable+0x18`。
- `0x007BE0F0` 解除關聯（見 T08-095）；具體虛擬實作仍未確認。

## 限制與後續未解決清單

1. **未定位** `NameProvider_8C` 的實際 vtable：`0x007DCEE0` 並未在函式開頭寫入 vtable；該物件作為 provider 的直接類型仍不應僅憑 `node+0x24` 推定完全同型。下一段應確認 `vtable+0x10` 在此 0x8C-byte 對象上的方法如何建立 binding、以及 vtable 是否處於嵌套物件中。這是目前最重要的型別不確定性。
2. `binding+0x80` 的寫入者/初始值仍待驗證；與 provider+0x80 嚴格區分。
3. `node+0x24` 的建立路徑已確定，但 `0x007D1080` 紅黑樹修正細節可作後續研究。
4. 上游進入 `0x007B84xx` 的所有呼叫者及 provider 回傳值的消費位置仍不完整。
5. 場景物件 `vtable+0x20` 主更新迴圈仍待獨立定位，不能與 binding slot +0x20 混淆。

## 原始 BIN 機器碼附錄（objdump -d -Mintel）

### 名稱登記/節點插入 — 007B82D0–007B8474
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

### 節點配置與值建構 — 00719B90–00719C60
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
  719c3e:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  719c41:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  719c44:	e8 60 74 17 00       	call   0x8910a9
  719c49:	68 a8 57 c8 00       	push   0xc857a8
  719c4e:	8d 45 e4             	lea    eax,[ebp-0x1c]
  719c51:	50                   	push   eax
  719c52:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  719c59:	e8 92 2d 18 00       	call   0x89c9f0
  719c5e:	cc                   	int3
  719c5f:	cc                   	int3

```

### 上層查找/建立/傳入引數 — 007B84E0–007B8674
```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b84e0 <.text+0x3b74e0>:
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

### 依名稱解析binding — 007BDF90–007BE0F0
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
  7be0ed:	cc                   	int3
  7be0ee:	cc                   	int3
  7be0ef:	cc                   	int3

```

### binding零參數調度 — 007BDF40–007BDF90
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

### binding有參數調度 — 007BDF00–007BDF40
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

### 管理器資源建立 — 007DCEE0–007DCF40
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