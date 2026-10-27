# T08-096 — 名稱管理器的註冊/查找/釋放、0x8C 物件初始化與 provider 間接生命週期

- 研究者：`chatgpt-web roy`
- 台灣時間：`2026-10-27T11:00:27.816664+08:00`
- BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與交接值一致。
- 方法：原始 BIN 直接執行 `objdump -d -Mintel`，以下地址與指令為實際驗證；函式名均為暫定功能描述。
- 範圍：T08-096，承接 T08-093～095。對 GitHub 提交以操作回傳為準。

## 研究結論與新的函式

**已確認**：`0x007B84xx`（包含 `0x007B84E0–0x007B866D`）是一條名稱型共用管理物件的取得流程：先調用 `0x007B86F0` 進行名稱查詢，命中時讀取節點 `+0x24` 指標並調整指向物件的 `+0x5C` 持有計數；未命中時可透過格式/資料來源介面取得資料、配置 0x8C-byte 管理物件並呼叫 `0x007DCEE0` 初始化，最後交給 `0x007B82D0` 登記。這比過去只知道 `0x007BDF90` 讀取 `node+0x24` 更接近名稱供應者的建立來源。

- `0x007B84F7` 呼叫 `0x007B86F0`；`0x007B851F mov eax,[ecx+24h]` 取現存 node 持有的關聯物件；`0x007B8522 inc dword ptr [eax+5Ch]` 增加引用/持有計數。
- `0x007B85A4 push 8Ch` 與 `0x007B85A9 call 0x00891268` 是明確的 **0x8C bytes 配置**；`0x007B85B7 call 0x007DCEE0` 初始化該物件。`0x007B85CB` 透過外部多型來源 `vtable+0x10`；`0x007B85DE` 使用另一個 `vtable+0x34`；成功條件下 `0x007B8642 call 0x007DD2A0` 與 `0x007B864E call 0x007B82D0`。
- `0x007DCEE0` 將全域 `0x00FBA844` 遞增並保存 `object+0x00`，將 `+0x44,+0x4C,+0x50,+0x54,+0x60,+0x7C,+0x80,+0x84` 清零，`+0x5C=1`，初始化 `+0x64` 同步結構；`object+0x04` 寫入 C 字串。**注意**該 0x8C bytes 物件內 `+0x80`，不是第95段尚未定位的 binding `+0x80`，嚴禁混為同型。
- `0x007B82D0` 首先用傳入名稱與 tree 進行唯一性查詢；若已存在，`0x007B8395 xor eax,eax` 返回失敗；其條件成立時在 `0x007B83A6 ... mov [ecx+44h],eax` 可依 `tree+0x30` 修改傳入物件的 `+0x44`；餘下將進入樹節點建構/插入（原始詳見附錄）。
- `0x007DC510` 是同一名稱集合的移除者，先以名稱查找 `0x007B86F0`，命中後 `0x007DC599 mov edi,[eax+24h]`，`0x007DC5A3 call [vtable+0x0C]`；若返回 0，呼叫 `vtable+0x00`（push 1）並透過 `0x007B8680` 刪除名稱樹節點。**不能把此處 +0x0C 命名為引用計數遞減而未驗證實作**；但條件性銷毀關係已明確。
- `0x007BDF90`（前段）從 `node+0x24` 派送 `vtable+0x10` 取得 item binding；**重要型別區分**：本段配置的 0x8C-byte 管理物件與 `node+0x24` 關聯物件存在緊密路徑，但 `0x007B82D0` 的節點實際寫入追蹤仍須確認所有中間物件/別名，不能未經證實視為 binding 本體。

## 部分關鍵 BIN 指令

```asm
007B84F7 call 007B86F0
007B851F mov eax, [ecx+24h]
007B8522 inc dword ptr [eax+5Ch]
007B85A4 push 08Ch
007B85A9 call 00891268
007B85B7 call 007DCEE0
007B8642 call 007DD2A0
007B864E call 007B82D0

007DCEE0 mov eax, [00FBA844h]
007DCEE5 inc eax
007DCEE7 mov [esi], eax
007DCF05 mov dword ptr [esi+5Ch], 1
007DCF0C mov [esi+60h], ebx
007DCF18 mov [esi+7Ch], ebx

007DC599 mov edi,[eax+24h]
007DC59E mov edx,[eax+0Ch]
007DC5A3 call edx
007DC5B4 push 1
007DC5B8 call edx
007DC5C2 call 007B8680
```

## 暫定 C++ 偽程式碼

```cpp
struct NamedManagedObject_8C { // partial, confirmed allocation 0x8C
  uint32_t identity;      // +0x00; monotonic global 0x00FBA844
  char name[/* bounded by total structure */]; // starts +0x04; do not assume fixed-length without further disasm
  // ...
  uint32_t modeFlag;      // +0x44
  void* dataBegin;        // +0x4C
  void* dataEnd;          // +0x50
  void* dataCapacity;     // +0x54
  uint32_t holdCount;     // +0x5C, initialized 1; known increment during cache hit
  uint32_t activeCount;   // +0x60
  // +0x64 synchronization primitive initialized with imported routine
  void* reusedBegin;      // +0x7C
  void* reusedEnd;        // +0x80
  void* reusedCapacity;   // +0x84
};

void* getOrCreateNamedObject(const char* name) {
  auto node = treeFind(name); // 0x007B86F0
  if (node != sentinel) {
    void* managed = node->payload_24;
    ++managed->holdCount_5C;
    return managed;
  }
  // Intermediate virtual resource loading and success checks abbreviated.
  void* raw = allocate(0x8C);
  void* managed = initialize_007DCEE0(raw, name);
  if (externalSourceHasExpectedContent()) {
    populate_007DD2A0(name, managed);
    insert_007B82D0(name, tree, managed);
  }
  return /* actual branch-dependent outcome; review assembly */;
}

bool removeByName_007DC510(const char* name) {
  auto node=treeFind(name);
  if (node == sentinel) return false; // exact return semantics provisional
  auto provider=node->payload_24;
  auto result=provider->virtual_0C();
  if (result == 0) { provider->virtual_00(1); treeErase(node); }
  return result; // semantics of return unconfirmed
}
```

## 分支 / 指標來源待驗證

1. `0x007B82D0` 插入處如何分配 0x28-byte node 並將 `+0x24` 與傳入指標連結：需要逐分支跟完整參數寄存器/堆疊；目前已確認呼叫鏈及重用支線，沒有聲稱完成所有 tree-node 寫入者。
2. `node+0x24 -> vtable+0x10` 實作函式及返回 binding 的 allocation/vtable 尚未定位。
3. `binding+0x80` 寫入者不等同 0x8C 管理器 +0x80；目前不足以將不同類型欄位合併。
4. `vtable+0x0C` in removal 的回傳值是否真正是最後持有者條件，需該 slot implementation。就目前而言只能稱 `result == 0` 導致移除。
5. `0x007DD2A0` 會經資料解析/多型來源路徑，還需確認成功碼、失敗清理與所有回滾。
6. 場景物件 `vtable+0x20` 真正上層迴圈依然未定位，不得將 provider/binding 的同位移虛擬槽混淆。

## 與前段連結

T08-093 以資源 `+0x6C` 完成標誌連結回收；T08-094 擴充活躍管理器更新；T08-095 從 `0x007BDF90` 確認 item 綁定之名稱索引；本段提供該名稱索引的重用/建立/刪除鏈及 0x8C 管理物件 field init / holdCount 與全域 identity。

## 原始機器碼附錄（objdump -d -Mintel /mnt/data/Tartaros.bin）

### 0x007B82D0 — 登記入口與名稱唯一性

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

```

### 0x007B84xx — provider 建立與重用分支

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b83e0 <.text+0x3b73e0>:
  7b83e0:	54                   	push   esp
  7b83e1:	24 5c                	and    al,0x5c
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
  7b8474:	cc                   	int3
  7b8475:	cc                   	int3
  7b8476:	cc                   	int3
  7b8477:	cc                   	int3
  7b8478:	cc                   	int3
  7b8479:	cc                   	int3
  7b847a:	cc                   	int3
  7b847b:	cc                   	int3
  7b847c:	cc                   	int3
  7b847d:	cc                   	int3
  7b847e:	cc                   	int3
  7b847f:	cc                   	int3
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
  7b8674:	cc                   	int3
  7b8675:	cc                   	int3
  7b8676:	cc                   	int3
  7b8677:	cc                   	int3
  7b8678:	cc                   	int3
  7b8679:	cc                   	int3
  7b867a:	cc                   	int3
  7b867b:	cc                   	int3
  7b867c:	cc                   	int3
  7b867d:	cc                   	int3
  7b867e:	cc                   	int3
  7b867f:	cc                   	int3
  7b8680:	55                   	push   ebp
  7b8681:	8b ec                	mov    ebp,esp
  7b8683:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b8686:	53                   	push   ebx
  7b8687:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b868a:	57                   	push   edi
  7b868b:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  7b868e:	83 c0 08             	add    eax,0x8
  7b8691:	e8 4a 9f d9 ff       	call   0x5525e0
  7b8696:	23 c7                	and    eax,edi
  7b8698:	39 46 24             	cmp    DWORD PTR [esi+0x24],eax
  7b869b:	77 09                	ja     0x7b86a6
  7b869d:	d1 ef                	shr    edi,1
  7b869f:	83 c9 ff             	or     ecx,0xffffffff
  7b86a2:	2b cf                	sub    ecx,edi
  7b86a4:	03 c1                	add    eax,ecx
  7b86a6:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  7b86a9:	8d 0c c2             	lea    ecx,[edx+eax*8]
  7b86ac:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86af:	39 51 04             	cmp    DWORD PTR [ecx+0x4],edx
  7b86b2:	75 1d                	jne    0x7b86d1
  7b86b4:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86b6:	75 11                	jne    0x7b86c9
  7b86b8:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86bb:	89 11                	mov    DWORD PTR [ecx],edx
  7b86bd:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  7b86c0:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86c3:	89 54 c1 04          	mov    DWORD PTR [ecx+eax*8+0x4],edx
  7b86c7:	eb 10                	jmp    0x7b86d9
  7b86c9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b86cc:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b86cf:	eb 08                	jmp    0x7b86d9
  7b86d1:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86d3:	75 07                	jne    0x7b86dc
  7b86d5:	8b 12                	mov    edx,DWORD PTR [edx]
  7b86d7:	89 11                	mov    DWORD PTR [ecx],edx
  7b86d9:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86dc:	52                   	push   edx
  7b86dd:	53                   	push   ebx
  7b86de:	8d 7e 04             	lea    edi,[esi+0x4]
  7b86e1:	e8 3a 14 f6 ff       	call   0x719b20
  7b86e6:	5f                   	pop    edi
  7b86e7:	8b c3                	mov    eax,ebx
  7b86e9:	5b                   	pop    ebx
  7b86ea:	5d                   	pop    ebp
  7b86eb:	c2 08 00             	ret    0x8
  7b86ee:	cc                   	int3
  7b86ef:	cc                   	int3

```

### 0x007DC510 — 名稱移除與多型清理

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc3c0 <.text+0x3db3c0>:
  7dc3c0:	d0 5d c2             	rcr    BYTE PTR [ebp-0x3e],1
  7dc3c3:	08 00                	or     BYTE PTR [eax],al
  7dc3c5:	cc                   	int3
  7dc3c6:	cc                   	int3
  7dc3c7:	cc                   	int3
  7dc3c8:	cc                   	int3
  7dc3c9:	cc                   	int3
  7dc3ca:	cc                   	int3
  7dc3cb:	cc                   	int3
  7dc3cc:	cc                   	int3
  7dc3cd:	cc                   	int3
  7dc3ce:	cc                   	int3
  7dc3cf:	cc                   	int3
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
  7dc44e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  7dc451:	51                   	push   ecx
  7dc452:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  7dc455:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7dc458:	e8 4c 4c 0b 00       	call   0x8910a9
  7dc45d:	68 a8 57 c8 00       	push   0xc857a8
  7dc462:	8d 55 e4             	lea    edx,[ebp-0x1c]
  7dc465:	52                   	push   edx
  7dc466:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  7dc46d:	e8 7e 05 0c 00       	call   0x89c9f0
  7dc472:	cc                   	int3
  7dc473:	cc                   	int3
  7dc474:	cc                   	int3
  7dc475:	cc                   	int3
  7dc476:	cc                   	int3
  7dc477:	cc                   	int3
  7dc478:	cc                   	int3
  7dc479:	cc                   	int3
  7dc47a:	cc                   	int3
  7dc47b:	cc                   	int3
  7dc47c:	cc                   	int3
  7dc47d:	cc                   	int3
  7dc47e:	cc                   	int3
  7dc47f:	cc                   	int3
  7dc480:	55                   	push   ebp
  7dc481:	8b ec                	mov    ebp,esp
  7dc483:	53                   	push   ebx
  7dc484:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dc487:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7dc48a:	56                   	push   esi
  7dc48b:	8b 30                	mov    esi,DWORD PTR [eax]
  7dc48d:	57                   	push   edi
  7dc48e:	8d 7b 04             	lea    edi,[ebx+0x4]
  7dc491:	3b f0                	cmp    esi,eax
  7dc493:	74 1d                	je     0x7dc4b2
  7dc495:	33 db                	xor    ebx,ebx
  7dc497:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7dc49a:	3b cb                	cmp    ecx,ebx
  7dc49c:	74 0b                	je     0x7dc4a9
  7dc49e:	8b 01                	mov    eax,DWORD PTR [ecx]
  7dc4a0:	8b 10                	mov    edx,DWORD PTR [eax]
  7dc4a2:	6a 01                	push   0x1
  7dc4a4:	ff d2                	call   edx
  7dc4a6:	89 5e 24             	mov    DWORD PTR [esi+0x24],ebx
  7dc4a9:	8b 36                	mov    esi,DWORD PTR [esi]
  7dc4ab:	3b 37                	cmp    esi,DWORD PTR [edi]
  7dc4ad:	75 e8                	jne    0x7dc497
  7dc4af:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dc4b2:	57                   	push   edi
  7dc4b3:	e8 88 61 d7 ff       	call   0x552640
  7dc4b8:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc4ba:	8b 73 10             	mov    esi,DWORD PTR [ebx+0x10]
  7dc4bd:	8d 53 10             	lea    edx,[ebx+0x10]
  7dc4c0:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  7dc4c3:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7dc4c6:	3b f0                	cmp    esi,eax
  7dc4c8:	74 17                	je     0x7dc4e1
  7dc4ca:	8b c8                	mov    ecx,eax
  7dc4cc:	3b c0                	cmp    eax,eax
  7dc4ce:	74 0e                	je     0x7dc4de
  7dc4d0:	8b 39                	mov    edi,DWORD PTR [ecx]
  7dc4d2:	89 3e                	mov    DWORD PTR [esi],edi
  7dc4d4:	83 c1 04             	add    ecx,0x4
  7dc4d7:	83 c6 04             	add    esi,0x4
  7dc4da:	3b c8                	cmp    ecx,eax
  7dc4dc:	75 f2                	jne    0x7dc4d0
  7dc4de:	89 72 04             	mov    DWORD PTR [edx+0x4],esi
  7dc4e1:	8b 02                	mov    eax,DWORD PTR [edx]
  7dc4e3:	8d 4d 08             	lea    ecx,[ebp+0x8]
  7dc4e6:	51                   	push   ecx
  7dc4e7:	50                   	push   eax
  7dc4e8:	b9 10 00 00 00       	mov    ecx,0x10
  7dc4ed:	e8 9e 07 00 00       	call   0x7dcc90
  7dc4f2:	5f                   	pop    edi
  7dc4f3:	5e                   	pop    esi
  7dc4f4:	c7 43 20 07 00 00 00 	mov    DWORD PTR [ebx+0x20],0x7
  7dc4fb:	c7 43 24 08 00 00 00 	mov    DWORD PTR [ebx+0x24],0x8
  7dc502:	5b                   	pop    ebx
  7dc503:	5d                   	pop    ebp
  7dc504:	c2 04 00             	ret    0x4
  7dc507:	cc                   	int3
  7dc508:	cc                   	int3
  7dc509:	cc                   	int3
  7dc50a:	cc                   	int3
  7dc50b:	cc                   	int3
  7dc50c:	cc                   	int3
  7dc50d:	cc                   	int3
  7dc50e:	cc                   	int3
  7dc50f:	cc                   	int3
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

```

### 0x007DCEE0 — 0x8C bytes 管理物件初始化

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
  7dcf40:	53                   	push   ebx
  7dcf41:	56                   	push   esi
  7dcf42:	8b 77 4c             	mov    esi,DWORD PTR [edi+0x4c]
  7dcf45:	33 db                	xor    ebx,ebx
  7dcf47:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf4a:	74 1d                	je     0x7dcf69
  7dcf4c:	8d 64 24 00          	lea    esp,[esp+0x0]
  7dcf50:	8b 06                	mov    eax,DWORD PTR [esi]
  7dcf52:	3b c3                	cmp    eax,ebx
  7dcf54:	74 0b                	je     0x7dcf61
  7dcf56:	50                   	push   eax
  7dcf57:	e8 b0 42 0b 00       	call   0x89120c
  7dcf5c:	83 c4 04             	add    esp,0x4
  7dcf5f:	89 1e                	mov    DWORD PTR [esi],ebx
  7dcf61:	83 c6 04             	add    esi,0x4
  7dcf64:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf67:	75 e7                	jne    0x7dcf50
  7dcf69:	8b 47 7c             	mov    eax,DWORD PTR [edi+0x7c]
  7dcf6c:	3b c3                	cmp    eax,ebx
  7dcf6e:	74 09                	je     0x7dcf79
  7dcf70:	50                   	push   eax
  7dcf71:	e8 96 42 0b 00       	call   0x89120c
  7dcf76:	83 c4 04             	add    esp,0x4
  7dcf79:	8d 47 64             	lea    eax,[edi+0x64]
  7dcf7c:	50                   	push   eax
  7dcf7d:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  7dcf80:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  7dcf86:	89 9f 84 00 00 00    	mov    DWORD PTR [edi+0x84],ebx
  7dcf8c:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  7dcf92:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  7dcf95:	3b c3                	cmp    eax,ebx
  7dcf97:	74 09                	je     0x7dcfa2
  7dcf99:	50                   	push   eax
  7dcf9a:	e8 6d 42 0b 00       	call   0x89120c
  7dcf9f:	83 c4 04             	add    esp,0x4
  7dcfa2:	5e                   	pop    esi
  7dcfa3:	89 5f 4c             	mov    DWORD PTR [edi+0x4c],ebx
  7dcfa6:	89 5f 50             	mov    DWORD PTR [edi+0x50],ebx
  7dcfa9:	89 5f 54             	mov    DWORD PTR [edi+0x54],ebx
  7dcfac:	5b                   	pop    ebx
  7dcfad:	c3                   	ret
  7dcfae:	cc                   	int3
  7dcfaf:	cc                   	int3

```

### 0x007DD2A0 — 資料載入/解析協助程式

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dd2a0 <.text+0x3dc2a0>:
  7dd2a0:	55                   	push   ebp
  7dd2a1:	8b ec                	mov    ebp,esp
  7dd2a3:	83 e4 f8             	and    esp,0xfffffff8
  7dd2a6:	6a ff                	push   0xffffffff
  7dd2a8:	68 ed 25 92 00       	push   0x9225ed
  7dd2ad:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dd2b3:	50                   	push   eax
  7dd2b4:	81 ec 68 01 00 00    	sub    esp,0x168
  7dd2ba:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dd2bf:	33 c4                	xor    eax,esp
  7dd2c1:	89 84 24 60 01 00 00 	mov    DWORD PTR [esp+0x160],eax
  7dd2c8:	53                   	push   ebx
  7dd2c9:	56                   	push   esi
  7dd2ca:	57                   	push   edi
  7dd2cb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dd2d0:	33 c4                	xor    eax,esp
  7dd2d2:	50                   	push   eax
  7dd2d3:	8d 84 24 78 01 00 00 	lea    eax,[esp+0x178]
  7dd2da:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dd2e0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7dd2e3:	33 db                	xor    ebx,ebx
  7dd2e5:	8d b4 24 84 00 00 00 	lea    esi,[esp+0x84]
  7dd2ec:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  7dd2f0:	8b f9                	mov    edi,ecx
  7dd2f2:	89 9c 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],ebx
  7dd2f9:	89 9c 24 88 00 00 00 	mov    DWORD PTR [esp+0x88],ebx
  7dd300:	e8 1b e9 f3 ff       	call   0x71bc20
  7dd305:	b8 0f 00 00 00       	mov    eax,0xf
  7dd30a:	88 9c 24 4c 01 00 00 	mov    BYTE PTR [esp+0x14c],bl
  7dd311:	89 84 24 64 01 00 00 	mov    DWORD PTR [esp+0x164],eax
  7dd318:	89 9c 24 60 01 00 00 	mov    DWORD PTR [esp+0x160],ebx
  7dd31f:	88 9c 24 50 01 00 00 	mov    BYTE PTR [esp+0x150],bl
  7dd326:	89 9c 24 80 01 00 00 	mov    DWORD PTR [esp+0x180],ebx
  7dd32d:	89 44 24 7c          	mov    DWORD PTR [esp+0x7c],eax
  7dd331:	8b c7                	mov    eax,edi
  7dd333:	89 5c 24 78          	mov    DWORD PTR [esp+0x78],ebx
  7dd337:	88 5c 24 68          	mov    BYTE PTR [esp+0x68],bl
  7dd33b:	8d 50 01             	lea    edx,[eax+0x1]
  7dd33e:	8b ff                	mov    edi,edi
  7dd340:	8a 08                	mov    cl,BYTE PTR [eax]
  7dd342:	40                   	inc    eax
  7dd343:	84 c9                	test   cl,cl
  7dd345:	75 f9                	jne    0x7dd340
  7dd347:	2b c2                	sub    eax,edx
  7dd349:	50                   	push   eax
  7dd34a:	57                   	push   edi
  7dd34b:	8d 4c 24 70          	lea    ecx,[esp+0x70]
  7dd34f:	e8 1c 57 c2 ff       	call   0x402a70
  7dd354:	c6 84 24 80 01 00 00 	mov    BYTE PTR [esp+0x180],0x1
  7dd35b:	01 
  7dd35c:	8b 44 24 68          	mov    eax,DWORD PTR [esp+0x68]
  7dd360:	be 10 00 00 00       	mov    esi,0x10
  7dd365:	39 74 24 7c          	cmp    DWORD PTR [esp+0x7c],esi
  7dd369:	73 04                	jae    0x7dd36f
  7dd36b:	8d 44 24 68          	lea    eax,[esp+0x68]
  7dd36f:	68 e0 d1 be 00       	push   0xbed1e0
  7dd374:	50                   	push   eax
  7dd375:	e8 f6 73 f3 ff       	call   0x714770
  7dd37a:	8b f8                	mov    edi,eax
  7dd37c:	83 c4 08             	add    esp,0x8
  7dd37f:	3b fb                	cmp    edi,ebx
  7dd381:	75 04                	jne    0x7dd387
  7dd383:	32 c0                	xor    al,al
  7dd385:	eb 36                	jmp    0x7dd3bd
  7dd387:	8b 17                	mov    edx,DWORD PTR [edi]
  7dd389:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  7dd38c:	8b cf                	mov    ecx,edi
  7dd38e:	ff d0                	call   eax
  7dd390:	8b 17                	mov    edx,DWORD PTR [edi]
  7dd392:	8b f0                	mov    esi,eax
  7dd394:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  7dd397:	8b cf                	mov    ecx,edi
  7dd399:	ff d0                	call   eax
  7dd39b:	50                   	push   eax
  7dd39c:	8d 8c 24 88 00 00 00 	lea    ecx,[esp+0x88]
  7dd3a3:	e8 98 bf cb ff       	call   0x499340
  7dd3a8:	8b 17                	mov    edx,DWORD PTR [edi]
  7dd3aa:	8a d8                	mov    bl,al
  7dd3ac:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7dd3af:	83 c4 04             	add    esp,0x4
  7dd3b2:	8b cf                	mov    ecx,edi
  7dd3b4:	ff d0                	call   eax
  7dd3b6:	8a c3                	mov    al,bl
  7dd3b8:	be 10 00 00 00       	mov    esi,0x10
  7dd3bd:	84 c0                	test   al,al
  7dd3bf:	0f 94 c3             	sete   bl
  7dd3c2:	c6 84 24 80 01 00 00 	mov    BYTE PTR [esp+0x180],0x0
  7dd3c9:	00 
  7dd3ca:	39 74 24 7c          	cmp    DWORD PTR [esp+0x7c],esi
  7dd3ce:	72 0d                	jb     0x7dd3dd
  7dd3d0:	8b 4c 24 68          	mov    ecx,DWORD PTR [esp+0x68]
  7dd3d4:	51                   	push   ecx
  7dd3d5:	e8 32 3e 0b 00       	call   0x89120c
  7dd3da:	83 c4 04             	add    esp,0x4
  7dd3dd:	84 db                	test   bl,bl
  7dd3df:	74 59                	je     0x7dd43a
  7dd3e1:	c7 84 24 80 01 00 00 	mov    DWORD PTR [esp+0x180],0xffffffff
  7dd3e8:	ff ff ff ff 
  7dd3ec:	39 b4 24 64 01 00 00 	cmp    DWORD PTR [esp+0x164],esi
  7dd3f3:	72 10                	jb     0x7dd405
  7dd3f5:	8b 94 24 50 01 00 00 	mov    edx,DWORD PTR [esp+0x150]
  7dd3fc:	52                   	push   edx
  7dd3fd:	e8 0a 3e 0b 00       	call   0x89120c
  7dd402:	83 c4 04             	add    esp,0x4
  7dd405:	8d 84 24 84 00 00 00 	lea    eax,[esp+0x84]
  7dd40c:	50                   	push   eax
  7dd40d:	c7 84 24 68 01 00 00 	mov    DWORD PTR [esp+0x168],0xf
  7dd414:	0f 00 00 00 
  7dd418:	c7 84 24 64 01 00 00 	mov    DWORD PTR [esp+0x164],0x0
  7dd41f:	00 00 00 00 
  7dd423:	c6 84 24 54 01 00 00 	mov    BYTE PTR [esp+0x154],0x0
  7dd42a:	00 
  7dd42b:	e8 60 e8 f3 ff       	call   0x71bc90
  7dd430:	b8 05 40 00 80       	mov    eax,0x80004005
  7dd435:	e9 8b 05 00 00       	jmp    0x7dd9c5
  7dd43a:	8b 8c 24 84 00 00 00 	mov    ecx,DWORD PTR [esp+0x84]
  7dd441:	68 08 fe c0 00       	push   0xc0fe08
  7dd446:	8d 7c 24 28          	lea    edi,[esp+0x28]
  7dd44a:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  7dd44e:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  7dd452:	e8 e9 e5 f3 ff       	call   0x71ba40
  7dd457:	8b 00                	mov    eax,DWORD PTR [eax]
  7dd459:	33 db                	xor    ebx,ebx
  7dd45b:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7dd45f:	3b c3                	cmp    eax,ebx
  7dd461:	75 54                	jne    0x7dd4b7
  7dd463:	c7 84 24 80 01 00 00 	mov    DWORD PTR [esp+0x180],0xffffffff
  7dd46a:	ff ff ff ff 
  7dd46e:	39                   	.byte 0x39
  7dd46f:	b4                   	.byte 0xb4

```

### 0x007B8680 — tree erase、0x007B86F0 tree lookup

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b8680 <.text+0x3b7680>:
  7b8680:	55                   	push   ebp
  7b8681:	8b ec                	mov    ebp,esp
  7b8683:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b8686:	53                   	push   ebx
  7b8687:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b868a:	57                   	push   edi
  7b868b:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  7b868e:	83 c0 08             	add    eax,0x8
  7b8691:	e8 4a 9f d9 ff       	call   0x5525e0
  7b8696:	23 c7                	and    eax,edi
  7b8698:	39 46 24             	cmp    DWORD PTR [esi+0x24],eax
  7b869b:	77 09                	ja     0x7b86a6
  7b869d:	d1 ef                	shr    edi,1
  7b869f:	83 c9 ff             	or     ecx,0xffffffff
  7b86a2:	2b cf                	sub    ecx,edi
  7b86a4:	03 c1                	add    eax,ecx
  7b86a6:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  7b86a9:	8d 0c c2             	lea    ecx,[edx+eax*8]
  7b86ac:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86af:	39 51 04             	cmp    DWORD PTR [ecx+0x4],edx
  7b86b2:	75 1d                	jne    0x7b86d1
  7b86b4:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86b6:	75 11                	jne    0x7b86c9
  7b86b8:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86bb:	89 11                	mov    DWORD PTR [ecx],edx
  7b86bd:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  7b86c0:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86c3:	89 54 c1 04          	mov    DWORD PTR [ecx+eax*8+0x4],edx
  7b86c7:	eb 10                	jmp    0x7b86d9
  7b86c9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b86cc:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b86cf:	eb 08                	jmp    0x7b86d9
  7b86d1:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86d3:	75 07                	jne    0x7b86dc
  7b86d5:	8b 12                	mov    edx,DWORD PTR [edx]
  7b86d7:	89 11                	mov    DWORD PTR [ecx],edx
  7b86d9:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86dc:	52                   	push   edx
  7b86dd:	53                   	push   ebx
  7b86de:	8d 7e 04             	lea    edi,[esi+0x4]
  7b86e1:	e8 3a 14 f6 ff       	call   0x719b20
  7b86e6:	5f                   	pop    edi
  7b86e7:	8b c3                	mov    eax,ebx
  7b86e9:	5b                   	pop    ebx
  7b86ea:	5d                   	pop    ebp
  7b86eb:	c2 08 00             	ret    0x8
  7b86ee:	cc                   	int3
  7b86ef:	cc                   	int3
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
  7b873d:	3b c8                	cmp    ecx,eax
  7b873f:	0f 84 d5 00 00 00    	je     0x7b881a
  7b8745:	8d 41 08             	lea    eax,[ecx+0x8]
  7b8748:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  7b874b:	8b 79 10             	mov    edi,DWORD PTR [ecx+0x10]
  7b874e:	bb 10 00 00 00       	mov    ebx,0x10
  7b8753:	39 59 14             	cmp    DWORD PTR [ecx+0x14],ebx
  7b8756:	72 02                	jb     0x7b875a
  7b8758:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b875a:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  7b875d:	8b d6                	mov    edx,esi
  7b875f:	3b d6                	cmp    edx,esi
  7b8761:	73 00                	jae    0x7b8763
  7b8763:	8b d6                	mov    edx,esi
  7b8765:	3b f7                	cmp    esi,edi
  7b8767:	72 02                	jb     0x7b876b
  7b8769:	8b d7                	mov    edx,edi
  7b876b:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  7b876e:	72 02                	jb     0x7b8772
  7b8770:	8b 00                	mov    eax,DWORD PTR [eax]
  7b8772:	52                   	push   edx
  7b8773:	8b d0                	mov    edx,eax
  7b8775:	e8 f6 f6 c4 ff       	call   0x407e70
  7b877a:	83 c4 04             	add    esp,0x4
  7b877d:	85 c0                	test   eax,eax
  7b877f:	75 0b                	jne    0x7b878c
  7b8781:	3b f7                	cmp    esi,edi
  7b8783:	72 09                	jb     0x7b878e
  7b8785:	3b f7                	cmp    esi,edi
  7b8787:	0f 95 c0             	setne  al
  7b878a:	85 c0                	test   eax,eax
  7b878c:	79 16                	jns    0x7b87a4
  7b878e:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b8791:	8b 02                	mov    eax,DWORD PTR [edx]
  7b8793:	8b 75 f8             	mov    esi,DWORD PTR [ebp-0x8]
  7b8796:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  7b8799:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7b879c:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  7b879f:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  7b87a2:	eb 8c                	jmp    0x7b8730
  7b87a4:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7b87a7:	83 78 1c 10          	cmp    DWORD PTR [eax+0x1c],0x10
  7b87ab:	8b 58 18             	mov    ebx,DWORD PTR [eax+0x18]
  7b87ae:	72 05                	jb     0x7b87b5

```