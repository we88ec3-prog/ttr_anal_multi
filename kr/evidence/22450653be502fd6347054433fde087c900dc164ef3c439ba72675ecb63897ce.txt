# T08-104 — 分桶消費迴圈、內嵌與全域陣列所有權辨識

- 研究者：`chatgpt-web roy`
- 台灣時間：`2026-10-27T14:16:45.084326+08:00`
- 原始 BIN：`Tartaros.bin`
- SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與既有交接相符。
- 機器碼資料：從原 BIN 以 GNU objdump -Mintel 產生的 `/mnt/data/t08_103_disasm.txt`，本段逐一核對。
- 確認程度：下列「已確認」僅保證機器碼操作及可追蹤的資料流，不代表原始 C++ 符號。

## 一、核心成果與重要更正

1. **找到真的「讀取 entries → 呼叫虛擬函式 → 清空 count」消費流程**：`0x007D1710～0x007D1758`，位於包含 `0x007D14xx～0x007D17xx` 的大型函式中。它處理索引 19～21 (`0x13...0x15`) 的分桶，透過 `vtable+0x0C` 呼叫每個元素，並逐桶清零計數；後續 `0x007D1780` 另以 22 次迴圈清零另一組桶計數。
2. **這個消費者不是已證明的 `[0x00FB7740]` 全域堆積分桶消費者**。其指標來自 `ebx` 管理器內嵌陣列，起點 `ebx+0x2604C`，而非從全域記憶體 `0x00FB7740` 讀取。兩種表雖共用桶跨度 0x2004，也不能合併為同一物件。這修正了本段初步尋找消費者時的歸屬錯誤。
3. `0x0079A3C0` 是另一個**參數化分桶寫入器**：載入 `manager+0x98` 的指標，動態取得桶索引，依 stride `0x2004` 與 count<0x800 追加。這說明多套桶共用程式模式，僅搜尋 stride 無法確認全域緩衝的讀取來源。
4. `0x007D1620`、`0x007D16A0` 使用管理器 `ebx` 下的其他隊列（`+0x18030/+0x1A030`、`+0x24048/+0x26048`），分別以虛擬方法 `+0x0C` 及不同參數執行處理。顯示同一管理器具有多階段資料提交機制。
5. 原始 `0x00FB76B0` 六平面緩衝的非零係數寫入者，**仍未找到**。本段沒有將任何 `+0x60` 或近似 float 比較解讀為相機矩陣。

## 二、內嵌分桶：已驗證消費與清零

入口階段：`0x007D16F8` 設定桶索引 `edx=0x13`、指標 `eax=ebx+0x2604C`，循環至 `edx==0x16`；因此遍歷三桶，索引 19～21。每桶為 `entries[2048]` + `count`，跨度 `0x2004`。

```asm
  7d16f8:	ba 13 00 00 00       	mov    edx,0x13
  7d16fd:	8d 83 4c 60 02 00    	lea    eax,[ebx+0x2604c]
  7d1703:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  7d1707:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d170b:	83 fa 16             	cmp    edx,0x16
  7d170e:	73 37                	jae    0x7d1747
  7d1710:	33 ff                	xor    edi,edi
  7d1712:	39 b8 00 20 00 00    	cmp    DWORD PTR [eax+0x2000],edi
  7d1718:	7e 23                	jle    0x7d173d
  7d171a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7d1720:	8b 0c b8             	mov    ecx,DWORD PTR [eax+edi*4]
  7d1723:	8b 01                	mov    eax,DWORD PTR [ecx]
  7d1725:	52                   	push   edx
  7d1726:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d1729:	56                   	push   esi
  7d172a:	ff d2                	call   edx
  7d172c:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  7d1730:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  7d1734:	47                   	inc    edi
  7d1735:	3b b8 00 20 00 00    	cmp    edi,DWORD PTR [eax+0x2000]
  7d173b:	7c e3                	jl     0x7d1720
  7d173d:	c7 80 00 20 00 00 00 	mov    DWORD PTR [eax+0x2000],0x0
  7d1744:	00 00 00 
  7d1747:	42                   	inc    edx
  7d1748:	05 04 20 00 00       	add    eax,0x2004
  7d174d:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  7d1751:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d1755:	83 fa 16             	cmp    edx,0x16
  7d1758:	7c b4                	jl     0x7d170e
```

虛擬呼叫形式近似：

```cpp
// 示意，未證實原始類名
for (unsigned bucket = 19; bucket < 22; ++bucket) {
    auto &b = manager->embeddedBuckets[bucket];
    for (int i = 0; i < b.count; ++i) {
        auto *entry = b.entries[i];
        entry->vtable->method_0C(entry, renderContext, bucket);
    }
    b.count = 0;
}
```

這個伪碼中的 `embeddedBuckets[bucket]` 為方便描述，實際機器碼基底 `ebx+0x2604C` 對應其內嵌陣列的後三桶，**沒有證明管理器前面所有桶都是這種統一型別**。

## 三、同一函式的其他分段隊列

```asm
  7d15d4:	a1 90 79 fb 00       	mov    eax,ds:0xfb7990
  7d15d9:	83 e8 00             	sub    eax,0x0
  7d15dc:	0f 84 a1 00 00 00    	je     0x7d1683
  7d15e2:	48                   	dec    eax
  7d15e3:	0f 85 a7 00 00 00    	jne    0x7d1690
  7d15e9:	6a 01                	push   0x1
  7d15eb:	8b f7                	mov    esi,edi
  7d15ed:	e8 be 01 00 00       	call   0x7d17b0
  7d15f2:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  7d15f6:	6a 01                	push   0x1
  7d15f8:	8b f3                	mov    esi,ebx
  7d15fa:	e8 61 03 00 00       	call   0x7d1960
  7d15ff:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  7d1603:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7d1605:	8b 91 e4 00 00 00    	mov    edx,DWORD PTR [ecx+0xe4]
  7d160b:	6a 00                	push   0x0
  7d160d:	68 98 00 00 00       	push   0x98
  7d1612:	56                   	push   esi
  7d1613:	ff d2                	call   edx
  7d1615:	33 ff                	xor    edi,edi
  7d1617:	39 bb 30 a0 01 00    	cmp    DWORD PTR [ebx+0x1a030],edi
  7d161d:	7e 1f                	jle    0x7d163e
  7d161f:	90                   	nop
  7d1620:	8b 8c bb 30 80 01 00 	mov    ecx,DWORD PTR [ebx+edi*4+0x18030]
  7d1627:	8b 01                	mov    eax,DWORD PTR [ecx]
  7d1629:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  7d162d:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  7d1630:	6a 0c                	push   0xc
  7d1632:	52                   	push   edx
  7d1633:	ff d0                	call   eax
  7d1635:	47                   	inc    edi
  7d1636:	3b bb 30 a0 01 00    	cmp    edi,DWORD PTR [ebx+0x1a030]
  7d163c:	7c e2                	jl     0x7d1620
  7d163e:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  7d1642:	6a 01                	push   0x1
  7d1644:	c7 83 30 a0 01 00 00 	mov    DWORD PTR [ebx+0x1a030],0x0
  7d164b:	00 00 00 
  7d164e:	8b 17                	mov    edx,DWORD PTR [edi]
  7d1650:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  7d1653:	6a 01                	push   0x1
  7d1655:	6a 01                	push   0x1
  7d1657:	8b cf                	mov    ecx,edi
  7d1659:	ff d0                	call   eax
  7d165b:	6a 00                	push   0x0
  7d165d:	e8 4e 01 00 00       	call   0x7d17b0
  7d1662:	6a 00                	push   0x0
  7d1664:	8b f3                	mov    esi,ebx
  7d1666:	e8 f5 02 00 00       	call   0x7d1960
```

```asm
  7d1677:	6a 00                	push   0x0
  7d1679:	68 98 00 00 00       	push   0x98
  7d167e:	50                   	push   eax
  7d167f:	ff d2                	call   edx
  7d1681:	eb 0b                	jmp    0x7d168e
  7d1683:	8b fe                	mov    edi,esi
  7d1685:	6a 00                	push   0x0
  7d1687:	8b f3                	mov    esi,ebx
  7d1689:	e8 d2 02 00 00       	call   0x7d1960
  7d168e:	8b f7                	mov    esi,edi
  7d1690:	33 ff                	xor    edi,edi
  7d1692:	39 bb 48 60 02 00    	cmp    DWORD PTR [ebx+0x26048],edi
  7d1698:	7e 20                	jle    0x7d16ba
  7d169a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7d16a0:	8b 8c bb 48 40 02 00 	mov    ecx,DWORD PTR [ebx+edi*4+0x24048]
  7d16a7:	8b 01                	mov    eax,DWORD PTR [ecx]
  7d16a9:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d16ac:	6a 12                	push   0x12
  7d16ae:	56                   	push   esi
  7d16af:	ff d2                	call   edx
  7d16b1:	47                   	inc    edi
  7d16b2:	3b bb 48 60 02 00    	cmp    edi,DWORD PTR [ebx+0x26048]
  7d16b8:	7c e6                	jl     0x7d16a0
  7d16ba:	68 a8 76 fb 00       	push   0xfb76a8
  7d16bf:	c7 83 48 60 02 00 00 	mov    DWORD PTR [ebx+0x26048],0x0
  7d16c6:	00 00 00 
  7d16c9:	e8 22 8f fc ff       	call   0x79a5f0
  7d16ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  7d16d2:	33 ff                	xor    edi,edi
  7d16d4:	eb 0e                	jmp    0x7d16e4
```

觀察：多處 `count` 被清零，且虛擬方法 `+0x0C` 重複出現；並有渲染器/處理器風格的 `+0xE4/+0x104` 虛擬呼叫。但是否與遊戲畫面繪製直接對應，需沿傳入 render/context 物件的 vtable 身分再確認。

## 四、通用桶追加器：`0x0079A3C0`

```asm
  79a3c0:	56                   	push   esi
  79a3c1:	8b b1 98 00 00 00    	mov    esi,DWORD PTR [ecx+0x98]
  79a3c7:	85 c0                	test   eax,eax
  79a3c9:	75 09                	jne    0x79a3d4
  79a3cb:	8b 17                	mov    edx,DWORD PTR [edi]
  79a3cd:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  79a3d0:	8b cf                	mov    ecx,edi
  79a3d2:	ff d0                	call   eax
  79a3d4:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  79a3da:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  79a3e1:	03 c6                	add    eax,esi
  79a3e3:	5e                   	pop    esi
  79a3e4:	81 f9 00 08 00 00    	cmp    ecx,0x800
  79a3ea:	7d 09                	jge    0x79a3f5
  79a3ec:	89 3c 88             	mov    DWORD PTR [eax+ecx*4],edi
  79a3ef:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
  79a3f5:	c3                   	ret
```

從 `manager+0x98` 得到桶基底（不是直接解參照 `[0x00FB7740]`），虛擬方法 `+0x04` 取得索引，然後 `index * 0x2004` 定位。此實作使用 `count < 0x800` 上限。未找到其 `manager+0x98` 一定指向全域桶的決定性賦值證據。

## 五、與前段真正全域桶生產者區分

第103段已確認：

- `0x0079CDA8`、`0x007BED5B`、`0x007CD7C9`、`0x007D34EB`、`0x007F23B0`：直接取得 `[0x00FB7740]`，追加項目。
- `0x007FECE9`：固定第10桶偏移 `0x14028/0x16028` 追加。
- `0x00798F26～0x00798F78`：全域桶 heap 配置與初始化。

本段新的消費者用 `ebx+...` 取得指標，**不能反向認定它就是上述全域桶讀者**。真正的全域桶讀者可能是呼叫者將全域位址注入 `manager+0x98`、某個繪圖管理器、或完全其他未找到的別名路徑。這三者皆屬假設。

## 六、下一步追查

1. 追蹤 `0x007D14xx` 大型消費函式的直接呼叫者，與 `ebx` 管理器配置、大小及類型，驗證此消費鏈屬於何種調度。
2. 針對管理器 `+0x98` 的寫入者與 `0x0079A3C0` 呼叫者，確認是否存在 `[0x00FB7740]` 的別名注入。
3. 全域桶的讀取需以**實際指標別名**驗證，不能僅用 stride `0x2004` 的相似性替代。
4. 六平面緩衝 `0x00FB76B0` 的內容寫入者仍需沿參數與非全域指標尋找。
5. 場景物件 `vtable+0x20` 的主更新迴圈仍未與本段流程相連。

## 七、證據附錄與相關路徑

### 主要消費者所在函式前段

```asm
  7d1414:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  7d1418:	51                   	push   ecx
  7d1419:	c7 44 24 20 01 00 00 	mov    DWORD PTR [esp+0x20],0x1
  7d1420:	00 
  7d1421:	8b 07                	mov    eax,DWORD PTR [edi]
  7d1423:	8b 90 e8 00 00 00    	mov    edx,DWORD PTR [eax+0xe8]
  7d1429:	6a 1c                	push   0x1c
  7d142b:	57                   	push   edi
  7d142c:	ff d2                	call   edx
  7d142e:	8b 07                	mov    eax,DWORD PTR [edi]
  7d1430:	8b 88 e4 00 00 00    	mov    ecx,DWORD PTR [eax+0xe4]
  7d1436:	6a 00                	push   0x0
  7d1438:	6a 1c                	push   0x1c
  7d143a:	57                   	push   edi
  7d143b:	ff d1                	call   ecx
  7d143d:	83 bb 08 60 00 00 00 	cmp    DWORD PTR [ebx+0x6008],0x0
  7d1444:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  7d144b:	00 
  7d144c:	7e 26                	jle    0x7d1474
  7d144e:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  7d1452:	8b 8c 93 08 40 00 00 	mov    ecx,DWORD PTR [ebx+edx*4+0x4008]
  7d1459:	8b 01                	mov    eax,DWORD PTR [ecx]
  7d145b:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d145e:	6a 02                	push   0x2
  7d1460:	56                   	push   esi
  7d1461:	ff d2                	call   edx
  7d1463:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  7d1467:	40                   	inc    eax
  7d1468:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7d146c:	3b 83 08 60 00 00    	cmp    eax,DWORD PTR [ebx+0x6008]
  7d1472:	7c da                	jl     0x7d144e
  7d1474:	6a 01                	push   0x1
  7d1476:	c7 83 08 60 00 00 00 	mov    DWORD PTR [ebx+0x6008],0x0
  7d147d:	00 00 00 
  7d1480:	8b 06                	mov    eax,DWORD PTR [esi]
  7d1482:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d1485:	6a 01                	push   0x1
  7d1487:	6a 01                	push   0x1
  7d1489:	8b ce                	mov    ecx,esi
  7d148b:	ff d2                	call   edx
  7d148d:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  7d1491:	8b 07                	mov    eax,DWORD PTR [edi]
  7d1493:	8b 90 e4 00 00 00    	mov    edx,DWORD PTR [eax+0xe4]
  7d1499:	51                   	push   ecx
  7d149a:	6a 1c                	push   0x1c
  7d149c:	57                   	push   edi
  7d149d:	ff d2                	call   edx
  7d149f:	56                   	push   esi
  7d14a0:	8b fb                	mov    edi,ebx
  7d14a2:	e8 e9 07 00 00       	call   0x7d1c90
  7d14a7:	8b 06                	mov    eax,DWORD PTR [esi]
  7d14a9:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d14ac:	6a 01                	push   0x1
  7d14ae:	6a 01                	push   0x1
  7d14b0:	6a 01                	push   0x1
  7d14b2:	8b ce                	mov    ecx,esi
  7d14b4:	ff d2                	call   edx
  7d14b6:	68 04 77 fb 00       	push   0xfb7704
  7d14bb:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7d14c1:	6a 05                	push   0x5
  7d14c3:	68 a8 76 fb 00       	push   0xfb76a8
  7d14c8:	e8 53 a0 fc ff       	call   0x79b520
  7d14cd:	33 ff                	xor    edi,edi
```

### 消費、清理末尾

```asm
  7d175a:	8b 16                	mov    edx,DWORD PTR [esi]
  7d175c:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  7d175f:	6a 01                	push   0x1
  7d1761:	6a 01                	push   0x1
  7d1763:	6a 01                	push   0x1
  7d1765:	8b ce                	mov    ecx,esi
  7d1767:	ff d0                	call   eax
  7d1769:	81 c3 00 20 00 00    	add    ebx,0x2000
  7d176f:	b8 16 00 00 00       	mov    eax,0x16
  7d1774:	eb 0a                	jmp    0x7d1780
  7d1776:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  7d177d:	8d 49 00             	lea    ecx,[ecx+0x0]
  7d1780:	c7 03 00 00 00 00    	mov    DWORD PTR [ebx],0x0
  7d1786:	81 c3 04 20 00 00    	add    ebx,0x2004
  7d178c:	48                   	dec    eax
  7d178d:	75 f1                	jne    0x7d1780
  7d178f:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  7d1793:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7d179a:	59                   	pop    ecx
  7d179b:	5f                   	pop    edi
  7d179c:	5e                   	pop    esi
  7d179d:	5b                   	pop    ebx
  7d179e:	8b e5                	mov    esp,ebp
  7d17a0:	5d                   	pop    ebp
  7d17a1:	c2 04 00             	ret    0x4
```

### 全域桶生產者實例，對照所有權

```asm
  7fec8d:	8b 16                	mov    edx,DWORD PTR [esi]
  7fec8f:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7fec92:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7fec98:	8b ce                	mov    ecx,esi
  7fec9a:	ff d0                	call   eax
  7fec9c:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7feca2:	8b 8c 38 00 20 00 00 	mov    ecx,DWORD PTR [eax+edi*1+0x2000]
  7feca9:	03 c7                	add    eax,edi
  7fecab:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7fecb1:	7d 09                	jge    0x7fecbc
  7fecb3:	89 34 88             	mov    DWORD PTR [eax+ecx*4],esi
  7fecb6:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
  7fecbc:	8b 46 30             	mov    eax,DWORD PTR [esi+0x30]
  7fecbf:	8b 48 68             	mov    ecx,DWORD PTR [eax+0x68]
  7fecc2:	8b 50 6c             	mov    edx,DWORD PTR [eax+0x6c]
  7fecc5:	8b 40 70             	mov    eax,DWORD PTR [eax+0x70]
  7fecc8:	89 4d e0             	mov    DWORD PTR [ebp-0x20],ecx
  7feccb:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7fecd1:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  7fecd4:	d9 45 e8             	fld    DWORD PTR [ebp-0x18]
  7fecd7:	d9 81 d8 00 00 00    	fld    DWORD PTR [ecx+0xd8]
  7fecdd:	89 55 e4             	mov    DWORD PTR [ebp-0x1c],edx
  7fece0:	de d9                	fcompp
  7fece2:	df e0                	fnstsw ax
  7fece4:	f6 c4 41             	test   ah,0x41
  7fece7:	75 21                	jne    0x7fed0a
  7fece9:	8b 15 40 77 fb 00    	mov    edx,DWORD PTR ds:0xfb7740
  7fecef:	8b 8a 28 60 01 00    	mov    ecx,DWORD PTR [edx+0x16028]
  7fecf5:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7fecfb:	7d 0d                	jge    0x7fed0a
  7fecfd:	89 b4 8a 28 40 01 00 	mov    DWORD PTR [edx+ecx*4+0x14028],esi
  7fed04:	ff 82 28 60 01 00    	inc    DWORD PTR [edx+0x16028]
  7fed0a:	8b 86 88 00 00 00    	mov    eax,DWORD PTR [esi+0x88]
  7fed10:	85 c0                	test   eax,eax
```

所有地址均為 VA；函式角色是本研究暫定命名，並非恢復的正式遊戲符號。