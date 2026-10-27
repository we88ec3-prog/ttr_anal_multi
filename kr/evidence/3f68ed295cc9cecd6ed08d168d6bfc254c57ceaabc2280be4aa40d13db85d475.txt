# T10-34 — actor-derived vtable ownership、selector setter 與玩家 gate 的類型邊界（BIN-first）

- 分析：20261027-221624（Asia/Taipei）；起始段 T10-34，未重編 T10-33。
- 原始資料：`/mnt/data/Tartaros.bin`，PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新 `sha256sum` 驗證）。
- 反組譯：`objdump -d -Mintel -j .text`；只靜態讀取，不執行/附加。原版資源未修改。
- GitHub：未 Commit、未 Push；T11 只作交界，不修改 owner、其他 Agent 內容。

## A. 此段實質新證據與區別於 T10-33 的結果

### A1. **確定** 0xC07B44 vtable 的建構期安裝，不再只是孤立的 `.rdata` 函式指標

`0x4CD6F0` **由函式入口**追查，在 `0x4CD718` 取得參數物件 `edi`，`0x4CD71C` 呼叫基底初始化 `0x4C7070`，隨後 `0x4CD728` 寫 `[edi]=0xC07B44`，`0x4CD72E` 寫 `[edi+0xF0]=0xC07BCC`。`0x4C7070` 自身曾設 `[ebx]=0xC07554` 以及 `[ebx+0xF0]=0xC075DC`；因此這是**可由直接指令支持的衍生階段 vptr 覆寫**。

`0xC07B70 - 0xC07B44 = 0x2C`，`0xC07B70 -> 0x4CE7F0`，從而確認 **這個衍生物件的 primary vtable slot +0x2C 指向 selector dispatcher**。這不是 setter 的直接 caller：執行時若走多型分派，需要找到 `call [vptr+0x2C]` 與正確 receiver 來源。

**重要範圍收斂：** 0x4CE7F0 不再只稱 actor-like 任意物件中的非零 writer，而是 `0x4CD6F0` 所建構、繼承 `0x4C7070` layout 的物件家族中的 virtual setter。尚缺 RTTI 名稱與 `0x546100` 直接使用的 actor 指標相等的可追蹤證據，因此不宣稱已證明玩家實體。

### A2. 分派器的 selector 與值不同維度（獨立可驗證）

入口使用 `movsx ecx,word [ebp+8]` 導入 selector、`selector-1 <= 29` 做界限；在 selector 5 對應的 jump-table 分支用 `movsx ecx,word [ebp+0xC]` 取得 value，寫入 `[ebx+0x3E8]`。緊接檢查舊 `[ebx+0x364]` 是否存在，並呼叫 cleanup/helper；當寫入值為 1 才走額外後續邏輯。可從此判定這不是單純裸 setter，而包含關聯狀態生命週期處理。未見可證實 V 按壓時長的分支。

### A3. 玩家 gate 的關聯性與反證

`0x546100` 由 controller actor `edi` 讀 `[edi+0x3E8]`，在 `0x5462DD` `call 0x54F270` 前作參數。這與上述 selector setter 共享 offset，但**不是函式調用連線**。`0x546338` 讀取 `[0xFB9009]` 是 index 5 的狀態陣列入口，與 setter selector 5 屬不同索引空間。本次尚未找出 action ID 及 nonzero writer。

## B. 選取的第一手 x86 指令

```asm
  4cd718:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4cd71b:	57                   	push   edi
  4cd71c:	e8 4f 99 ff ff       	call   0x4c7070
  4cd721:	33 db                	xor    ebx,ebx
  4cd723:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4cd726:	6a 30                	push   0x30
  4cd728:	c7 07 44 7b c0 00    	mov    DWORD PTR [edi],0xc07b44
  4cd72e:	c7 87 f0 00 00 00 cc 	mov    DWORD PTR [edi+0xf0],0xc07bcc
  4cd735:	7b c0 00 
  4cd738:	89 9f 20 04 00 00    	mov    DWORD PTR [edi+0x420],ebx
  4cd73e:	89 9f 24 04 00 00    	mov    DWORD PTR [edi+0x424],ebx
  4cd744:	e8 1f 3b 3c 00       	call   0x891268
  4ce81b:	8b d9                	mov    ebx,ecx
  4ce81d:	0f bf 4d 08          	movsx  ecx,WORD PTR [ebp+0x8]
  4ce821:	8d 41 ff             	lea    eax,[ecx-0x1]
  4ce824:	83 f8 1d             	cmp    eax,0x1d
  4ce827:	0f 87 fe 02 00 00    	ja     0x4ceb2b
  4ce82d:	0f b6 80 88 eb 4c 00 	movzx  eax,BYTE PTR [eax+0x4ceb88]
  4ce834:	ff 24 85 5c eb 4c 00 	jmp    DWORD PTR [eax*4+0x4ceb5c]
  4ce90a:	0f bf 4d 0c          	movsx  ecx,WORD PTR [ebp+0xc]
  4ce90e:	8b 83 64 03 00 00    	mov    eax,DWORD PTR [ebx+0x364]
  4ce914:	89 8b e8 03 00 00    	mov    DWORD PTR [ebx+0x3e8],ecx
  4ce91a:	85 c0                	test   eax,eax
  4ce91c:	74 27                	je     0x4ce945
  4ce91e:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4ce922:	8d 70 24             	lea    esi,[eax+0x24]
  4ce925:	74 05                	je     0x4ce92c
  4ce927:	e8 c4 fc 2e 00       	call   0x7be5f0
  4ce92c:	8b bb 64 03 00 00    	mov    edi,DWORD PTR [ebx+0x364]
  4ce932:	85 ff                	test   edi,edi
  4ce934:	74 0f                	je     0x4ce945
  4ce936:	e8 75 94 ff ff       	call   0x4c7db0
  4ce93b:	c7 83 64 03 00 00 00 	mov    DWORD PTR [ebx+0x364],0x0
  4ce942:	00 00 00 
  4ce945:	83 bb e8 03 00 00 01 	cmp    DWORD PTR [ebx+0x3e8],0x1
  4ce94c:	0f 85 ec 01 00 00    	jne    0x4ceb3e
  5462b0:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  5462b4:	8b 8f e8 03 00 00    	mov    ecx,DWORD PTR [edi+0x3e8]
  5462ba:	33 d2                	xor    edx,edx
  5462bc:	38 56 02             	cmp    BYTE PTR [esi+0x2],dl
  5462bf:	51                   	push   ecx
  5462c0:	0f 95 c2             	setne  dl
  5462c3:	8a 14 32             	mov    dl,BYTE PTR [edx+esi*1]
  5462c6:	88 54 24 28          	mov    BYTE PTR [esp+0x28],dl
  5462ca:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  5462ce:	51                   	push   ecx
  5462cf:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5462d2:	8d 14 49             	lea    edx,[ecx+ecx*2]
  5462d5:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5462d9:	8b 4c 91 10          	mov    ecx,DWORD PTR [ecx+edx*4+0x10]
  5462dd:	e8 8e 8f 00 00       	call   0x54f270
  5462e2:	85 c0                	test   eax,eax
  5462e4:	74 07                	je     0x5462ed
  5462e6:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5462eb:	eb 19                	jmp    0x546306
  5462ed:	83 bf e8 03 00 00 00 	cmp    DWORD PTR [edi+0x3e8],0x0
  5462f4:	74 07                	je     0x5462fd
```

## C. vtable 局部清單（從 BIN little-endian 讀 `.rdata`）

| vtable address | entry | slot offset from 0xC07B44 |
|---|---|---|
| `0xC07B44` | `0x4CDAA0` | `0x00` |
| `0xC07B48` | `0x5F5D10` | `0x04` |
| `0xC07B64` | `0x4CDD40` | `0x20` |
| `0xC07B68` | `0x4CDE30` | `0x24` |
| `0xC07B6C` | `0x4CE270` | `0x28` |
| **`0xC07B70`** | **`0x4CE7F0`** | **`0x2C`** |
| `0xC07B74` | `0x4CDBA0` | `0x30` |
| `0xC07B78` | `0x4C8060` | `0x34` |

此清單是原檔 raw 位元組反解的靜態表；相鄰表、RTTI 起點另須驗證，不對整個範圍任意定義型別。

## D. 類型／資料流關係（只畫已獲得的邊）

```text
0x4C7070 base layout constructor
     ^  call at 0x4CD71C
0x4CD6F0 derived constructor --[edi]--> [edi].vptr = 0xC07B44
                                            +0x2C -> 0x4CE7F0
                                                       | selector 5, value from stack WORD
                                                       v
                                              [this+0x3E8] = value
                                              [this+0x364] cleanup / value=1 side effects

0x546100 controller --[edi actor pointer]--> [edi+0x3E8]
                                                |
                                                v
                                          0x54F270 predicate

[**缺失的身份與事件連線：derived instance == controller actor? ; input source -> virtual call?**]
```

## E. 偽碼（部分已確認，型別暫名）

```cpp
struct DerivedActorCandidate; // RTTI 未證
DerivedActorCandidate* construct_4CD6F0(void* obj, ...) {
    construct_4C7070(obj, ...); // 已見直接 call
    *(uintptr_t*)((char*)obj + 0x0) = 0x00C07B44; // confirmed
    *(uintptr_t*)((char*)obj + 0xF0) = 0x00C07BCC; // confirmed
    // additional owned object allocation and initialization ...
    return (DerivedActorCandidate*)obj; // 研究性摘要，不表示原函式確切 return ABI
}
void virtual_slot_2C_4CE7F0(int16_t selector, int16_t value) {
    if (selector == 5) {
        this_field_3E8 = (int32_t)value;
        // if (this_field_364) cleanup / release
        // if (this_field_3E8 == 1) further branch
    }
}
```

## F. 對 T10 全面課題的貢獻與仍缺的環節

**本段確定：** 建構函式 → 衍生類型 vptr → slot +0x2C → setter dispatcher → selector 5 → 欄位 +0x3E8 的靜態原生鏈。這是一條比 T10-33 更完整的**物件／虛擬分派鏈**。

**未確認：** RTTI 類名；primary vtable +0x2C 所有可能的 virtual callsite；某個 callsite 如何提供 selector=5；玩家控制器 actor instance 是否必然屬於此 vtable；selector 5 是否由伺服器、腳本、動畫或玩家 V 產生；Z/X/C/V 的 XML 設定 row 和非零按鍵 writer；4 tier 實際選擇、普攻/技能 motion/cancel/queue 的因果鏈。不要將任何缺口命名為原版已證機制。

### 建議後續定向分析（T10-35 起）

1. 靠近 `0x4CD6F0` 與 `0x4C7070` 的 RTTI / 物件分配 caller 查 actor 來源，再在 `0x546100` 取得的 actor 指標類型作同一性驗證。
2. 在 `.text` 中找所有 `[vptr+0x2C]` 讀取 → register indirect call，交叉整理 receiver 型別，回推 selector=5 的產生者（可能由 script/network/simulation 觸發，待證）。
3. 獨立追 `0x6D08F0` XML fallback mapping 和 `0xFB9004+index` 的非零 writer，避免與 setter selector 數字巧合污染結論。
4. 追 `0x546100` gate 向 motion/queue/cancel 輸出串接，必要時僅引用 T11/T12 證據，維持 Task 邊界。

## G. 完成判定

本段已完成**建構函式、vtable owner、虛擬方法指標、setter side effects 的深度分析**；大系統尚有缺口不阻止此段交付。未提交 GitHub。