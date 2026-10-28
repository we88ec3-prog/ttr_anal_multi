# T16-99 — Quest 畫面模式選擇、靜態索引過濾與 pointer vector 消費鏈（BIN-first）

研究者 chatgpt-web roy；台北時間 20261028-230501。來源 KR `Tartaros.bin`，大小 12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。只做離線唯讀反組譯，不執行／修改客戶端。工作分支 `t16/roy/chatgpt-web`，本段授權提交；沒有推送 main。

## 0. Git 前置同步

原查 `main=baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，工作分支落後 2 個 commits。先建立雙親 merge `085784828a9d7b6fc66d79195e8d604b980c5fb1`，遠端 compare `behind=0`，才啟動本研究。

## 1. 方法／地址

使用原始 BIN 機器碼，由 PE header 檢驗 `.text`: VA 0x401000、raw 0x400，故 `.text` raw = VA - `0x400C00`。以下 assembly 由 `objdump -D -M intel --start-address ...` 直接對原件重現；檢查 `E8 rel32` 的 call target 與資料流。`0xFB1170～0xFB1198` 不在檔案 `.data` section 載入範圍（`.data` VA 0xD61000、大小 0x22B800，end 0xF8C800），所以不得以 `VA-0x402800` 去讀任意檔案 raw 當成這段全域初始化值；必須另找 runtime writer／重定位。此項修正原始資料採集邊界。

## 2. 第一輪：確認 Quest 所在 UI 物件有三條模式化資料選擇路徑

`0x62E759` 先讀 `[EBX+0xF4]`：等於 0 跳 `0x62F640`，等於 1 跳 `0x62F4C0`，等於 2 跳 `0x62F580`，其餘不走三種選擇器。分流後 `0x62F1F0` 與物件的 `[EBX+0x124]` 後續消費共同執行。這是具體模式分流，不能逕自命名為「任務已接／未接／完成」等三態；模式語意尚無直接證據。

Mode 0：`0x62F640` 用 `[EBX+0x114]` / `[EBX+0x118]` 指標陣列作輸出，先將 end 重置至 begin；由 `0xFB1170` 逐 2 bytes 掃描至 `0xFB1198`，對非零 WORD key 經全域 `[0xFB114C]` 呼叫 `0x503D20`。非 sentinel 命中時取 `node+0x10`，且 `*[payload+4] == 1` 才把該 payload 指標交給 `0x443D10` 插入 vector。反之跳過。推導掃描跨度 `0x28/2=20` 個 WORD **欄位槽**，但各 key 的實際初始化值未知，且 `0xFB1170` 不應當作 XML 或 wire payload。

**更正前段 T16-92 assembly 截錄的誤讀風險：** 0x62F726 命中時 `add eax,0x10`，隨後 `jmp 0x62F72D`，不會執行 0x62F72B 的 `xor eax,eax`；只有 sentinel 分支才清零。不能因截錄兩條相鄰指令誤稱成功分支也必然變 0。這是由分支 CFG 核驗的關鍵差異。

Mode 1：`0x62F4C0` 將陣列清空後，從 `[EBX+0xF8]` 經 `0x500950` 產生集合，接續共同 `0x62FA90`。Mode 2：`0x62F580` 是另一條獨立選擇器，具體 key 來源須延續查證。共同 `0x62FA90` 先呼叫 `0x62F780` 處理陣列，接著以 `(end - begin)/4` 遍歷陣列，每筆取指標，再以 `record+0x2C` 進入 `0x500E00`；對象顯示／控制語意尚不充分。至此形成「模式選擇 → Quest map/filter/list → 共同 consumer」有界原生鏈。

## 3. 第二輪：確認真正 vector 插入器／使用者和反證

`0x443D10` 不是網路 packet builder：它使用 `EDI` 指向含 begin/end/capacity 三指標的容器，當 end==capacity 呼叫 `0x4DEAB0` 擴充，`mov [eax],edx` 或 `mov [eax],ecx` 存入一個 DWORD，並 `add [edi+4],4`。其 `ESI` 初值為指向 payload 指標的 stack local `[EBP-0x10]`，即 append 4-byte pointer。成功查表不等於任何網路寫出。

共同 consumer `0x62FA90` 的 `[EDI+0x114]/[EDI+0x118]` 與 Mode 0 output 同源；`0x62FAF1～0x62FB18` 將差值除 4 並讀取 `[begin+index*4]`，所以是同一 pointer vector 的讀端。這個真正 downstream 比僅列出 xref 更具體。`0x62FAE5` 還可能調用 `0x6438F0`，但目前不命名為 Quest 網路事件。唯一已在本次局部 `.text` 原始 E8 rel32 掃描中驗證的 `0x62F640` 直接 caller 為 `0x62E764`；此覆蓋僅為 direct E8 scan，不排除間接呼叫。

## 4. 第三輪門檻／有界否證

第一輪已取得三路 mode selector 與靜態 Quest map 的資料流連接；第二輪確認真正的 4-byte pointer vector append 及共同 consumer，屬可回溯 BIN 的重要上下游新發現，故依共用三輪規則**第三輪未啟動**。未發現傳統 receive parser → dynamic Quest writer 的完整鏈，不能推斷不存在。尤其不能把 `0xFB1170` 的 runtime key 陣列視為伺服器 S→C snapshot，不能把模式 0/1/2 當成官方任務狀態，亦不得憑 `0x500E00` 的名稱推斷任何 wire opcode。

## 5. 玩家情境矩陣

| 情境 | Client 本地條件 | C→S | S→C | Client 已證效果 | Server 待開發／unknown |
|---|---|---|---|---|---|
| UI/Quest 瀏覽物件 mode=0 | `[EBX+0xF4]==0`；遍歷 20 個 16-bit 槽，key 非零且 Quest payload +4==1 | unknown | unknown | vector 新增符合條件的 Quest payload 指標，呼叫共同 consumer | 20 槽 key 初始化者、具體 UI 標記語意未知 |
| mode=1 | `[EBX+0xF4]==1`；讀 `[EBX+0xF8]` | unknown | unknown | `0x500950` 產生資料 → 共同 consumer | mode 業務語意 unknown |
| mode=2 | `[EBX+0xF4]==2` | unknown | unknown | 另一選擇器 `0x62F580` | mode 業務語意 unknown |
| 接取／交付 Quest | NPC callback 尚未閉合 | unknown | unknown | 未證實此三態為網路任務流程 | Client handler 與相容 Server 收發仍待原生查證 |
| Quest16→Quest15 | 實際 Quest state writer 未定位 | unknown | unknown | unknown | 原版 Server 判定無資料、列待開發 |

## 6. 偽碼（有界，變數名稱暫定）

```cpp
void refreshQuestRelatedView(View* view) {
    switch (view->mode_f4) {
      case 0:
        clear(view->pointers_114_118);
        for (uintptr_t a = 0xFB1170; a < 0xFB1198; a += 2) {
          uint16_t id = read_runtime_u16(a);
          if (!id) continue;
          auto* payload = quest_global_map_lookup(id); // [FB114C], 0x503D20
          if (payload && *(uint32_t*)((uint8_t*)payload + 4) == 1)
             append_ptr(view->pointers_114_118, payload); // 0x443D10
        }
        consume_pointer_list(view); // 0x62FA90
        break;
      case 1: selector_from_f8(view); consume_pointer_list(view); break;
      case 2: selector_mode2(view); consume_pointer_list(view); break;
      default: break;
    }
    // other local methods follow all paths
}
```

## 7. 下一正式段 T16-100

優先查 `0x500950`、`0x500E00` 的資料來源及共同 consumer 遍歷後真正的 UI 控件更新，並反查 `[0xFB1170..0xFB1198)` 的寫入者。重要的是另外獨立由 T02 已確認 receive dispatcher 尋找 Quest 業務 handler、state cache writer、NPC 接取 C→S 實體，不要把 XML loader／本地 UI pointer vector 重覆當作網路證據。

## 8. 原始組語節錄（所有區段直接從 KR BIN 讀取）

### Quest mode dispatch (VA `0x62E749`–`0x62E78A`; raw `0x22DB49`–`0x22DB8A`)

```asm
0062e749 <.text+0x22d749>:
  62e749:	8b 8b 08 01 00 00    	mov    ecx,DWORD PTR [ebx+0x108]
  62e74f:	8b 01                	mov    eax,DWORD PTR [ecx]
  62e751:	8b 90 c8 00 00 00    	mov    edx,DWORD PTR [eax+0xc8]
  62e757:	ff d2                	call   edx
  62e759:	8b 83 f4 00 00 00    	mov    eax,DWORD PTR [ebx+0xf4]
  62e75f:	85 c0                	test   eax,eax
  62e761:	75 08                	jne    0x62e76b
  62e763:	53                   	push   ebx
  62e764:	e8 d7 0e 00 00       	call   0x62f640
  62e769:	eb 18                	jmp    0x62e783
  62e76b:	83 f8 01             	cmp    eax,0x1
  62e76e:	75 08                	jne    0x62e778
  62e770:	53                   	push   ebx
  62e771:	e8 4a 0d 00 00       	call   0x62f4c0
  62e776:	eb 0b                	jmp    0x62e783
  62e778:	83 f8 02             	cmp    eax,0x2
  62e77b:	75 06                	jne    0x62e783
  62e77d:	53                   	push   ebx
  62e77e:	e8 fd 0d 00 00       	call   0x62f580
  62e783:	8b fb                	mov    edi,ebx
  62e785:	e8 66 0a 00 00       	call   0x62f1f0
```

### Mode 0 list build (VA `0x62F640`–`0x62F773`; raw `0x22EA40`–`0x22EB73`)

```asm
0062f640 <.text+0x22e640>:
  62f640:	55                   	push   ebp
  62f641:	8b ec                	mov    ebp,esp
  62f643:	6a ff                	push   0xffffffff
  62f645:	68 5c 69 94 00       	push   0x94695c
  62f64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  62f650:	50                   	push   eax
  62f651:	83 ec 08             	sub    esp,0x8
  62f654:	53                   	push   ebx
  62f655:	56                   	push   esi
  62f656:	57                   	push   edi
  62f657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  62f65c:	33 c5                	xor    eax,ebp
  62f65e:	50                   	push   eax
  62f65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  62f662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  62f668:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f66b:	8b 8b 18 01 00 00    	mov    ecx,DWORD PTR [ebx+0x118]
  62f671:	8b b3 14 01 00 00    	mov    esi,DWORD PTR [ebx+0x114]
  62f677:	3b f1                	cmp    esi,ecx
  62f679:	74 21                	je     0x62f69c
  62f67b:	8b c1                	mov    eax,ecx
  62f67d:	2b c1                	sub    eax,ecx
  62f67f:	c1 f8 02             	sar    eax,0x2
  62f682:	8d 3c 85 00 00 00 00 	lea    edi,[eax*4+0x0]
  62f689:	57                   	push   edi
  62f68a:	51                   	push   ecx
  62f68b:	56                   	push   esi
  62f68c:	e8 5f 1c 26 00       	call   0x8912f0
  62f691:	83 c4 0c             	add    esp,0xc
  62f694:	03 fe                	add    edi,esi
  62f696:	89 bb 18 01 00 00    	mov    DWORD PTR [ebx+0x118],edi
  62f69c:	bb 70 11 fb 00       	mov    ebx,0xfb1170
  62f6a1:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62f6a8:	bf 01 00 00 00       	mov    edi,0x1
  62f6ad:	75 26                	jne    0x62f6d5
  62f6af:	09 3d 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,edi
  62f6b5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  62f6bc:	e8 9f 07 ed ff       	call   0x4ffe60
  62f6c1:	68 00 cf bc 00       	push   0xbccf00
  62f6c6:	e8 4f 2c 26 00       	call   0x89231a
  62f6cb:	83 c4 04             	add    esp,0x4
  62f6ce:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62f6d5:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  62f6d8:	85 f6                	test   esi,esi
  62f6da:	74 6e                	je     0x62f74a
  62f6dc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62f6e3:	75 22                	jne    0x62f707
  62f6e5:	09 3d 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,edi
  62f6eb:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62f6ee:	e8 6d 07 ed ff       	call   0x4ffe60
  62f6f3:	68 00 cf bc 00       	push   0xbccf00
  62f6f8:	e8 1d 2c 26 00       	call   0x89231a
  62f6fd:	83 c4 04             	add    esp,0x4
  62f700:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62f707:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  62f70a:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  62f710:	8d 45 f0             	lea    eax,[ebp-0x10]
  62f713:	50                   	push   eax
  62f714:	8d 45 ec             	lea    eax,[ebp-0x14]
  62f717:	8b ce                	mov    ecx,esi
  62f719:	e8 02 46 ed ff       	call   0x503d20
  62f71e:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  62f721:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  62f724:	74 05                	je     0x62f72b
  62f726:	83 c0 10             	add    eax,0x10
  62f729:	eb 02                	jmp    0x62f72d
  62f72b:	33 c0                	xor    eax,eax
  62f72d:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  62f730:	85 c0                	test   eax,eax
  62f732:	74 16                	je     0x62f74a
  62f734:	39 78 04             	cmp    DWORD PTR [eax+0x4],edi
  62f737:	75 11                	jne    0x62f74a
  62f739:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  62f73c:	8d 45 f0             	lea    eax,[ebp-0x10]
  62f73f:	81 c7 14 01 00 00    	add    edi,0x114
  62f745:	e8 c6 45 e1 ff       	call   0x443d10
  62f74a:	83 c3 02             	add    ebx,0x2
  62f74d:	81 fb 98 11 fb 00    	cmp    ebx,0xfb1198
  62f753:	0f 8c 48 ff ff ff    	jl     0x62f6a1
  62f759:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  62f75c:	e8 2f 03 00 00       	call   0x62fa90
  62f761:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  62f764:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  62f76b:	59                   	pop    ecx
  62f76c:	5f                   	pop    edi
  62f76d:	5e                   	pop    esi
  62f76e:	5b                   	pop    ebx
  62f76f:	8b e5                	mov    esp,ebp
  62f771:	5d                   	pop    ebp
  62f772:	c2               	ret    0x4
```

### Mode 1 selector (VA `0x62F4E5`–`0x62F57D`; raw `0x22E8E5`–`0x22E97D`)

```asm
0062f4e5 <.text+0x22e4e5>:
  62f4e5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f4e8:	8b 8b 18 01 00 00    	mov    ecx,DWORD PTR [ebx+0x118]
  62f4ee:	8b b3 14 01 00 00    	mov    esi,DWORD PTR [ebx+0x114]
  62f4f4:	8d bb 14 01 00 00    	lea    edi,[ebx+0x114]
  62f4fa:	3b f1                	cmp    esi,ecx
  62f4fc:	74 21                	je     0x62f51f
  62f4fe:	8b c1                	mov    eax,ecx
  62f500:	2b c1                	sub    eax,ecx
  62f502:	c1 f8 02             	sar    eax,0x2
  62f505:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  62f50c:	53                   	push   ebx
  62f50d:	51                   	push   ecx
  62f50e:	56                   	push   esi
  62f50f:	e8 dc 1d 26 00       	call   0x8912f0
  62f514:	83 c4 0c             	add    esp,0xc
  62f517:	03 de                	add    ebx,esi
  62f519:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  62f51c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f51f:	b8 01 00 00 00       	mov    eax,0x1
  62f524:	84 05 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,al
  62f52a:	75 26                	jne    0x62f552
  62f52c:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  62f532:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  62f539:	e8 22 09 ed ff       	call   0x4ffe60
  62f53e:	68 00 cf bc 00       	push   0xbccf00
  62f543:	e8 d2 2d 26 00       	call   0x89231a
  62f548:	83 c4 04             	add    esp,0x4
  62f54b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62f552:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  62f558:	57                   	push   edi
  62f559:	50                   	push   eax
  62f55a:	68 a0 b2 fa 00       	push   0xfab2a0
  62f55f:	e8 ec 13 ed ff       	call   0x500950
  62f564:	8b cb                	mov    ecx,ebx
  62f566:	e8 25 05 00 00       	call   0x62fa90
  62f56b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  62f56e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  62f575:	59                   	pop    ecx
  62f576:	5f                   	pop    edi
  62f577:	5e                   	pop    esi
  62f578:	5b                   	pop    ebx
  62f579:	8b e5                	mov    esp,ebp
  62f57b:	5d                   	pop    ebp
  62f57c:	c2               	ret    0x4
```

### Mode 2 selector (VA `0x62F5A5`–`0x62F63F`; raw `0x22E9A5`–`0x22EA3F`)

```asm
0062f5a5 <.text+0x22e5a5>:
  62f5a5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f5a8:	8b 8b 18 01 00 00    	mov    ecx,DWORD PTR [ebx+0x118]
  62f5ae:	8b b3 14 01 00 00    	mov    esi,DWORD PTR [ebx+0x114]
  62f5b4:	8d bb 14 01 00 00    	lea    edi,[ebx+0x114]
  62f5ba:	3b f1                	cmp    esi,ecx
  62f5bc:	74 21                	je     0x62f5df
  62f5be:	8b c1                	mov    eax,ecx
  62f5c0:	2b c1                	sub    eax,ecx
  62f5c2:	c1 f8 02             	sar    eax,0x2
  62f5c5:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  62f5cc:	53                   	push   ebx
  62f5cd:	51                   	push   ecx
  62f5ce:	56                   	push   esi
  62f5cf:	e8 1c 1d 26 00       	call   0x8912f0
  62f5d4:	83 c4 0c             	add    esp,0xc
  62f5d7:	03 de                	add    ebx,esi
  62f5d9:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  62f5dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f5df:	b8 01 00 00 00       	mov    eax,0x1
  62f5e4:	84 05 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,al
  62f5ea:	75 26                	jne    0x62f612
  62f5ec:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  62f5f2:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  62f5f9:	e8 62 08 ed ff       	call   0x4ffe60
  62f5fe:	68 00 cf bc 00       	push   0xbccf00
  62f603:	e8 12 2d 26 00       	call   0x89231a
  62f608:	83 c4 04             	add    esp,0x4
  62f60b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62f612:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  62f618:	57                   	push   edi
  62f619:	50                   	push   eax
  62f61a:	68 a0 b2 fa 00       	push   0xfab2a0
  62f61f:	e8 dc 17 ed ff       	call   0x500e00
  62f624:	8b cb                	mov    ecx,ebx
  62f626:	e8 65 04 00 00       	call   0x62fa90
  62f62b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  62f62e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  62f635:	59                   	pop    ecx
  62f636:	5f                   	pop    edi
  62f637:	5e                   	pop    esi
  62f638:	5b                   	pop    ebx
  62f639:	8b e5                	mov    esp,ebp
  62f63b:	5d                   	pop    ebp
  62f63c:	c2 04 00             	ret    0x4
```

### Vector insertion (VA `0x443D10`–`0x443D62`; raw `0x43110`–`0x43162`)

```asm
00443d10 <.text+0x42d10>:
  443d10:	56                   	push   esi
  443d11:	8b f0                	mov    esi,eax
  443d13:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  443d16:	3b f0                	cmp    esi,eax
  443d18:	73 2b                	jae    0x443d45
  443d1a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  443d1c:	3b ce                	cmp    ecx,esi
  443d1e:	77 25                	ja     0x443d45
  443d20:	2b f1                	sub    esi,ecx
  443d22:	c1 fe 02             	sar    esi,0x2
  443d25:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  443d28:	75 07                	jne    0x443d31
  443d2a:	8b c7                	mov    eax,edi
  443d2c:	e8 7f ad 09 00       	call   0x4deab0
  443d31:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  443d34:	85 c0                	test   eax,eax
  443d36:	74 24                	je     0x443d5c
  443d38:	8b 0f                	mov    ecx,DWORD PTR [edi]
  443d3a:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  443d3d:	89 10                	mov    DWORD PTR [eax],edx
  443d3f:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  443d43:	5e                   	pop    esi
  443d44:	c3                   	ret
  443d45:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  443d48:	75 07                	jne    0x443d51
  443d4a:	8b c7                	mov    eax,edi
  443d4c:	e8 5f ad 09 00       	call   0x4deab0
  443d51:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  443d54:	85 c0                	test   eax,eax
  443d56:	74 04                	je     0x443d5c
  443d58:	8b 0e                	mov    ecx,DWORD PTR [esi]
  443d5a:	89 08                	mov    DWORD PTR [eax],ecx
  443d5c:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  443d60:	5e                   	pop    esi
  443d61:	c3                   	ret
```

### Downstream vector consumer (VA `0x62FAEB`–`0x62FB90`; raw `0x22EEEB`–`0x22EF90`)

```asm
0062faeb <.text+0x22eaeb>:
  62faeb:	57                   	push   edi
  62faec:	e8 8f fc ff ff       	call   0x62f780
  62faf1:	8b 87 18 01 00 00    	mov    eax,DWORD PTR [edi+0x118]
  62faf7:	2b 87 14 01 00 00    	sub    eax,DWORD PTR [edi+0x114]
  62fafd:	33 c9                	xor    ecx,ecx
  62faff:	c1 f8 02             	sar    eax,0x2
  62fb02:	89 44 24 5c          	mov    DWORD PTR [esp+0x5c],eax
  62fb06:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  62fb0a:	3b c3                	cmp    eax,ebx
  62fb0c:	0f 8e 0b 09 00 00    	jle    0x63041d
  62fb12:	8b 97 14 01 00 00    	mov    edx,DWORD PTR [edi+0x114]
  62fb18:	8b 34 8a             	mov    esi,DWORD PTR [edx+ecx*4]
  62fb1b:	89 74 24 24          	mov    DWORD PTR [esp+0x24],esi
  62fb1f:	3b f3                	cmp    esi,ebx
  62fb21:	0f 84 e9 08 00 00    	je     0x630410
  62fb27:	c6 44 24 1f 00       	mov    BYTE PTR [esp+0x1f],0x0
  62fb2c:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  62fb30:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  62fb34:	89 5c 24 38          	mov    DWORD PTR [esp+0x38],ebx
  62fb38:	89 9c 24 98 00 00 00 	mov    DWORD PTR [esp+0x98],ebx
  62fb3f:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62fb46:	75 29                	jne    0x62fb71
  62fb48:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  62fb4f:	c6 84 24 98 00 00 00 	mov    BYTE PTR [esp+0x98],0x1
  62fb56:	01 
  62fb57:	e8 04 03 ed ff       	call   0x4ffe60
  62fb5c:	68 00 cf bc 00       	push   0xbccf00
  62fb61:	e8 b4 27 26 00       	call   0x89231a
  62fb66:	83 c4 04             	add    esp,0x4
  62fb69:	c6 84 24 98 00 00 00 	mov    BYTE PTR [esp+0x98],0x0
  62fb70:	00 
  62fb71:	8b 4e 2c             	mov    ecx,DWORD PTR [esi+0x2c]
  62fb74:	8d 44 24 30          	lea    eax,[esp+0x30]
  62fb78:	50                   	push   eax
  62fb79:	51                   	push   ecx
  62fb7a:	68 a0 b2 fa 00       	push   0xfab2a0
  62fb7f:	e8 7c 12 ed ff       	call   0x500e00
  62fb84:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  62fb88:	8b 54 24 30          	mov    edx,DWORD PTR [esp+0x30]
  62fb8c:	2b c2                	sub    eax,edx
  62fb8e:	c1 f8              	sar    eax,0x2
```