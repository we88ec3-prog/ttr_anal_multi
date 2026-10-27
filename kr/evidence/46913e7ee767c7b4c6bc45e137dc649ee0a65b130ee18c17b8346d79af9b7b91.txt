# T10-35 — 衍生 actor 物件的雙路建構來源、selector 5 後處理與控制器證據界線（BIN-first）

- 時間：2026-10-27 22:18:46 Asia/Taipei。
- 證據：`/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本段重新校驗。
- 靜態分析：`objdump -d -Mintel -j .text`，不執行、修改或附加目標。
- 繼承 T10-33、T10-34 已核對結論；本段增量研究，不替代舊文。GitHub 未 Commit／Push。

## 一、這次新增的可核證結論

### A. `0x4CD6F0` 有兩個直接 callsite，且所屬上游並不相同

全 `.text` 指令搜尋 `call 0x4CD6F0`，觀察到 `0x4A0FD8` 與 `0x4AE609` 兩條直接呼叫路徑。這是**直接 call 的枚舉，不包含 indirect call 或函式指標**，不可聲稱所有建構源已窮盡。

**來源 1：`0x4A0F70` 附近工廠樣流程**

```asm
4a0f9c: mov edi,DWORD PTR [ebp+0x8]
4a0fa3: cmp edi,0xa
4a0fa8: cmp edi,0x2710
4a0fb8: push 0x444
4a0fbd: call 0x891268
4a0fc5: mov DWORD PTR [esp+0x14],eax
4a0fd1: test eax,eax
4a0fd3: je 0x4a1043
4a0fd5: push 0x0
4a0fd7: push eax
4a0fd8: call 0x4cd6f0
4a0fdf: cmp ebx,0x1
4a0fe4: push 0x434
4a0ffd: push eax
4a0ffe: call 0x4d1710
4a1019: cmp ebx,0x6
4a101e: push 0x42c
4a103b: push eax
4a103c: call 0x4d2120
```

上游依參數及條件分派到三種不同大小配置/初始化，`0x444` 對應 `0x4CD6F0`，其餘是 `0x4D1710` / `0x4D2120` 類別候選。此處能明確保證 `0x4CD6F0` 不是全域唯一的物件建構類型。`0x4A0F70` 的確切函式入口需函式邊界交叉驗證，此標記只作區域稱呼。

**來源 2：`0x4AE5xx` 資料驅動的類型分派**

```asm
4ae58f: movzx edx,WORD PTR [ebx-0x4]
4ae5a5: call 0x82ef00
4ae5ac: cmp ecx,DWORD PTR ds:0xfab13c
4ae5b8: movzx eax,BYTE PTR [ebx-0x4]
4ae5bc: movzx edi,BYTE PTR [ebx-0x2]
4ae5c0: movzx ecx,WORD PTR [ebx]
4ae5d4: cmp eax,0x7
4ae5dd: jmp DWORD PTR [eax*4+0x4aed90]
4ae5e4: push 0x444
4ae5e9: call 0x891268
4ae604: mov edx,DWORD PTR [ebx+0xe]
4ae607: push edx
4ae608: push eax
4ae609: call 0x4cd6f0
4ae60e: mov esi,eax
4ae624: mov eax,DWORD PTR [eax+0x5f50]
4ae62a: cmp DWORD PTR [ebx+0xe],eax
```

這條路徑先用字節類型（0..7）選分支，再依資料 `+0xE` 的欄位建立衍生物件；緊接著跟全域上下文的一個 `+0x5F50` 值比較。可以確定是**由資料欄位驅動建構並受條件分支控制**。`ebx` 究竟是網路封包、載入暫存或內部序列化資料，尚未完成來源追溯；不能稱已證明 server 直接驅動 selector=5。

### B. `0x4CD6F0` 所建構物件大小與附屬資源生命週期

```asm
4cd718: mov edi,DWORD PTR [ebp+0x8]
4cd71b: push edi
4cd71c: call 0x4c7070
4cd728: mov DWORD PTR [edi],0xc07b44
4cd72e: mov DWORD PTR [edi+0xf0],0xc07bcc
4cd738: mov DWORD PTR [edi+0x420],ebx
4cd73e: mov DWORD PTR [edi+0x424],ebx
4cd744: call 0x891268
4cd78d: mov DWORD PTR [edi+0x42c],eax
4cd793: call 0x891268
```

結合配置來源，該建構分支要求 `0x444` bytes 的物件容量，`+0x42C` 等欄位在配置內。已確認的 `[this+0x42c]` 等欄位是*附屬資源/子物件指標候選*，不把它們命名成技能蓄氣器。

### C. vptr 清理階段回填與附屬物件釋放

`0x4CDAF8` 位於 `0x4CDAD0` 入口之下：

```asm
4cdaf5: mov esi,DWORD PTR [ebp+0x8]
4cdaf8: mov DWORD PTR [esi],0xc07b44
4cdafe: mov DWORD PTR [esi+0xf0],0xc07bcc
4cdb0d: mov ecx,DWORD PTR [esi+0x42c]
4cdb13: cmp ecx,ebx
4cdb17: mov eax,DWORD PTR [ecx]
4cdb19: mov edx,DWORD PTR [eax]
4cdb1b: push 0x1
4cdb1d: call edx
4cdb1f: mov DWORD PTR [esi+0x42c],ebx
4cdb25: mov ecx,DWORD PTR [esi+0x430]
4cdb2f: mov eax,DWORD PTR [ecx]
4cdb31: mov edx,DWORD PTR [eax]
4cdb33: push 0x1
4cdb35: call edx
4cdb37: mov DWORD PTR [esi+0x430],ebx
```

即使入口名稱沒有符號證據，這仍是強力的**衍生類物件資源清理**跡象：vptr 恢復、檢查子物件、虛擬釋放、置零。這支持 vtable `0xC07B44` 在生命週期的兩端都有效；但 vptr 回填不能解作角色戰鬥狀態重設。

### D. selector=5 不只改一個欄位，還可能重新生成從屬物件

T10-34 已知 `0x4CE7F0` primary slot +0x2C 的分派。此段向下延伸 selector=5 的 value=1 分支，直接觀察到虛擬函式 +0x4C，以及新建從屬結果寫回 `+0x364`。

```asm
4ce90a: movsx ecx,WORD PTR [ebp+0xc]
4ce90e: mov eax,DWORD PTR [ebx+0x364]
4ce914: mov DWORD PTR [ebx+0x3e8],ecx
4ce91a: test eax,eax
4ce927: call 0x7be5f0
4ce936: call 0x4c7db0
4ce93b: mov DWORD PTR [ebx+0x364],0x0
4ce945: cmp DWORD PTR [ebx+0x3e8],0x1
4ce94c: jne 0x4ceb3e
4ce954: mov edx,DWORD PTR [ebx]
4ce956: mov eax,DWORD PTR [edx+0x4c]
4ce965: mov ecx,ebx
4ce985: call eax
4ce987: movzx ecx,WORD PTR [ebx+0x4]
4ce98e: call 0x49b140
4ce998: call 0x551f90
4ce99d: mov DWORD PTR [ebx+0x364],eax
```

此資料流顯示 `0x364` 先被解除/清除，條件值等於 1 時有重建路徑，指標最後回填。`0x49B140` 和 `0x551F90` 必須各自確認返回 ABI 與建立物件語意；目前僅能說與從屬狀態重建相關，不能解釋成 V 蓄氣結束或某普攻技能生成。

## 二、現階段類型證據與作用圖

```text
argument-driven factory @ 0x4A0Fxx  -- alloc 0x444 --> 0x4CD6F0
serialized/data-driven @ 0x4AE5xx -- alloc 0x444 --> 0x4CD6F0
                                                |
                                                v
                                        0x4C7070 base
                                                |
                                                v
                                         vptr 0xC07B44
                                                |
                         +0x2C -> 0x4CE7F0(selector,value)
                                                |
                                    selector=5 writes +0x3E8
                                                |
                                     if value=1, rebuild +0x364

0x4CDAD0 cleaning stage: restore vptr; release +0x42C/+0x430

controller 0x546100: reads actor +0x3E8 -> 0x54F270
             [identity and event bridge is not established]
```

### 不應混為同一索引空間的數字

1. `0x4AE5D4` 的 data record type 0..7。
2. `0x4CE7F0` 的 selector 1..30。
3. `0xFB9004 + index` 的輸入狀態陣列。
4. `0x54F270` 的技能 matrix key / flags。

即使它們出現數值 5 或 7，沒有跨模組寄存器/參數資料流就**不認定互相映射**。

## 三、局部偽碼：分派來源（推導摘要，符號未證）

```cpp
Candidate *make_variant_by_argument(int type, ...) {
    if (/* original branch for 0x444 */) {
        void *mem = alloc(0x444);
        return mem ? construct_4CD6F0(mem, 0) : nullptr;
    }
    if (/* branch for 0x434 */) return construct_4D1710(alloc(0x434));
    if (/* branch for 0x42C */) return construct_4D2120(alloc(0x42c));
    return /* unreviewed path */;
}

void DerivedCandidate::set_selector_value(int16_t selector, int16_t value) {
    if (selector == 5) {
        field_3E8 = int(value);
        release_or_cleanup(field_364);  // underlying implementations need review
        field_364 = nullptr;
        if (field_3E8 == 1) {
            auto candidate = virtual_slot_4C(/* 2 float arguments */);
            field_364 = helper_551F90(helper_49B140(field_04), /* local data and candidate */);
        }
    }
}
```

註：上段 `helper_551F90` 的擷取略去實際寄存器與堆疊細節；不能視為已確認的 C++ 真實宣告。

## 四、明確缺口、反證與後續焦點

| 議題 | 狀態 | 證據與限制 |
|---|---|---|
| 兩個直接 constructor callers | 已確認 | `0x4A0FD8`, `0x4AE609` |
| `0x444` bytes 衍生類配置 | 已確認於兩路 | `0x4A0FB8`, `0x4AE5E4` |
| 物件 vptr +0x2C setter | 已確認 | `0x4CD728`，表 `0xC07B70` |
| selector=5 之 value=1 條件再生 | 部分確認 | `0x4CE945..0x4CE99D` |
| 讀入 record 就是 network packet | 尚待驗證 | 缺 `0x4AE5xx` 上游資料生產與來源 |
| setter receiver == 玩家 controller actor | 尚待驗證 | 同 offset 不是同指標證明 |
| 玩家 V 點按/held 對應 selector 5 | 尚待驗證 | 缺按鍵 writer → setter 路徑 |
| Z/X/C/V configurable mapping | 尚待驗證 | 需要 XML row/非零 input writer |
| 普攻/技能 queue, cancel, motion | 尚待驗證 | 須追控制器動作輸出鏈 |

下一段以 `0x4AE5xx` record 上游、vtable +0x2C 的真正 indirect callsite、`0x4CE9xx` 建立的從屬物件消費者三者為先；並行追 `0x546100` controller receiver 如何來源到相同類型。不要先把 data-driven constructor 等同 network packet/玩家按鍵。

## 五、結案標準

T10-35 已有實質且可回溯的兩個建構來源、條件再生副作用與析構生命週期原生證據，深度研究已完成；並**未**宣稱重建完整的玩家蓄氣或普攻-技能功能鏈。下一段 T10-36。無 Commit/Push。