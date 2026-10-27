# T08-130 — 全域 22 桶 dispatcher 的前後調度、暫存佇列及 caller 邊界

研究時間：2026-10-27 18:50:41 CST；**未 Commit / Push**。

## 1. 原始依據與查證方式

- 第一手來源：`Tartaros.bin`，本次 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（與 T08 既有來源識別相符）。
- 反組譯：GNU objdump，`-D -b binary -m i386 -M intel --adjust-vma=0x401000`，並以原始 bytes 定址核對。注意：此 BIN 本身具 PE/MZ header，但 **程式碼 byte 的實際 BIN 位移**對此段函式是 `VA-0x401000`，例如 `0x004931FD -> 0x000921FD`、`0x0079A399 -> 0x00399399`；PE header 宣稱 `.text` raw offset `0x400`，若套用 `VA-0x401000+0x400` 會讀到**不同 bytes**。這是來源布局需追查的實際不一致；不把 PE header 的 raw offset 說成已經驗證能正確抽碼。`.rdata` 需依自身 section map 另算。
- T08-129 已確立：`0x004931FD` / `0x006DD3EB` -> `0x0079A320`，`0x0079A3AB` 透過 `[EDI+0xA0]->vtable+0x0C` 呼叫 `0x007D1310`，並 push `[EDI+0x98]=[0x00FB7740]`。本輪以此為起點，不重做 owner 身分證明。
- 證據分級：以下引用原始指令為【確認】；「一次更新」、「每幀」、「渲染」、「死亡」均 **不是**本輪證實的原始名稱。

## 2. T08-130 新增調度順序

在同一個函式 `0x0079A320` 內，直接觀察到這組嚴格順序：

```asm
0079A37C  6A 00                 push 0
0079A37E  68 50 32 FE 00        push 0x00FE3250
0079A383  E8 68 50 03 00        call 0x007CF3F0
0079A388  57                    push edi
0079A389  E8 D2 10 00 00        call 0x0079B460
0079A38E  8B 35 38 A8 FB 00     mov esi,[0x00FBA838]
0079A394  E8 A7 12 02 00        call 0x007BB640
0079A399  8B 8F A0 00 00 00     mov ecx,[edi+0xA0]
0079A39F  8B 01                 mov eax,[ecx]
0079A3A1  8B 97 98 00 00 00     mov edx,[edi+0x98]
0079A3A7  8B 40 0C              mov eax,[eax+0x0C]
0079A3AA  52                    push edx
0079A3AB  FF D0                 call eax
0079A3AD  8B 0F                 mov ecx,[edi]
0079A3AF  8B 11                 mov edx,[ecx]
0079A3B1  8B 42 0C              mov eax,[edx+0x0C]
0079A3B4  BE 01 00 00 00        mov esi,1
0079A3B9  56                    push esi
0079A3BA  56                    push esi
0079A3BB  56                    push esi
0079A3BC  FF D0                 call eax
```

**確認**：`0x0079B460`（manager address 為 stack argument）及 `0x007BB640`（從全域 `0x00FBA838` 讀取到 `ESI`）都在 22 桶 consumer **之前**。consumer 後立即對 `manager->[+0]` 的 core vtable `+0x0C` 進行三個 literal `1` 的虛擬呼叫。core 的這個 `+0x0C` **不等於 callback 的 `+0x0C`**。前置三個 call 是否直接生產本次要消費的 entry，仍需各自追入後才能斷言。

## 3. `0x007BB640` 的指標容器與操作鏈

```asm
007BB664  mov eax,[esi+0xB8]
007BB66A  sub eax,[esi+0xB4]
007BB670  mov ebx,[esi+0xC4]
007BB676  sar eax,2
007BB679  cmp ebx,eax
007BB67B  jbe 0x007BB67F
007BB67D  mov ebx,eax
...
007BB6AF  mov eax,[0x00FB76E8]
007BB6B4  mov edi,[eax+0x0C]
007BB6B7  mov edx,[esi+0xB4]
...
007BB6D0  mov eax,[esi+0xB8]
007BB6D6  push eax
007BB6D7  lea eax,[edx+ebx*4]
007BB6DA  push eax
007BB6DB  push edx
007BB6DC  call 0x007BB7B0
...
007BB6E4  xor edi,edi
007BB6E6  test ebx,ebx
007BB6E8  je 0x007BB705
007BB6F0  mov ecx,[esi+0xB4]
007BB6F6  mov ecx,[ecx+edi*4]
007BB6F9  mov edx,[ecx]
007BB6FB  mov eax,[edx+4]
007BB6FE  call eax
007BB700  inc edi
007BB701  cmp edi,ebx
007BB703  jb 0x007BB6F0
...
007BB730  mov [esi+0xB8],ebx
```

【確認】`[ESI+0xB4]` / `[ESI+0xB8]` 被當作四位元組指標陣列的 `begin` / `end`；`[ESI+0xC4]` 為限制本輪處理數的欄位（實際處理數是 `min([+0xC4], (end-begin)/4)` 的 unsigned 比較）。`0x007BB7B0` 在處理前接受三個陣列界址，且函式內具浮點 comparator 與分割處理的跡象，**推測為排序／優先順序處理**，尚未證明排序鍵意義。接著對前 `EBX` 筆物件執行 `vtable+4`。

特別留意 `0x007BB705～0x007BB730`：

```asm
007BB705  mov ecx,[esi+0xB8]
007BB70B  mov edi,[esi+0xB4]
007BB711  cmp edi,ecx
007BB713  je 0x007BB736
007BB715  mov eax,ecx
007BB717  sub eax,ecx            ; always zero as disassembled
007BB719  sar eax,2
007BB71C  lea ebx,[eax*4]
007BB723  push ebx
007BB724  push ecx
007BB725  push edi
007BB726  call 0x008916F0
007BB72B  add esp,0x0C
007BB72E  add ebx,edi
007BB730  mov [esi+0xB8],ebx
```

【確認】此 BIN 指令流中 `sub eax,ecx` 的操作數相同，若無外部修補，傳 `0` bytes 給 `0x008916F0` 並將 end 指回 begin。它表現為**清空可見陣列長度**，不等於證明釋放所有 entry 所有權；亦不是 22 桶 count 清零。不能因 `0x008916F0` 被呼叫就聲稱真的複製了任何 bytes。此處的 atypical zero-length copy 值得在下一輪配合上游 writer 檢查。

## 4. `0x0079B460` 的資料依賴

```asm
0079B47D  mov ebx,[ebp+8]       ; caller push edi
0079B48F  mov esi,[ebx]         ; core pointer
0079B4BB  add esi,0x98
0079B4C1  mov ecx,0x0D
0079B4E7  rep movs dword ptr es:[edi],dword ptr ds:[esi]
0079B4FE  call 0x0089EC60
0079B525  call 0x00790F40
0079B533  call 0x00780C90
0079B56F  call 0x00780F80
```

【確認】讀取 `manager->[+0]` 指向的 core 物件自 `+0x98` 起 **13 個 DWORD（0x34 bytes）**，轉入 stack 暫存；之後出現多個幾何／浮點相關 call。由此可確立它不是無資料依賴的空 callback；但本輪尚未追到底層語義，不命名為 camera update、視錐更新，也不將其與 T08-118 六係數 writer 自動連接。

## 5. Dispatcher 後半的附加路徑（新生命週期線索）

```asm
0079A495  cmp dword ptr [edi+0x2C],0
0079A499  je 0x0079A740
0079A49F  cmp dword ptr [edi+0x38],0
0079A4A3  jne 0x0079A740
...
0079A6BE  mov eax,[edi+0x28]   ; list sentinel/head pointer
0079A6C1  mov ebx,[eax]
0079A6C3  cmp ebx,eax
0079A6C5  je 0x0079A6EF
0079A6C7  mov ecx,[ebx+8]      ; list-node payload
0079A6CF  push esi
0079A6D0  call eax             ; payload virtual method +8
0079A6D2  mov ecx,[ebx+8]
0079A6D5  test ecx,ecx
0079A6D7  je 0x0079A6E8
0079A6DD  push 1
0079A6DF  call eax             ; payload virtual method +0
0079A6E1  mov [ebx+8],0
0079A6E8  mov ebx,[ebx]
...
0079A6EF  mov ecx,[edi+0x28]
0079A6F4  mov [ecx],ecx
0079A6F9  mov [ecx+4],ecx
0079A6FC  mov dword ptr [edi+0x2C],0
0079A703  cmp eax,[edi+0x28]
0079A708  mov ebx,[eax]
0079A70B  call 0x0089160C    ; free node
...
0079A740  mov ecx,[edi+0x28]
0079A745  mov [ecx],ecx
0079A74A  mov [ecx+4],ecx
0079A74D  mov dword ptr [edi+0x2C],0
0079A754  cmp eax,[edi+0x28]
0079A760  mov esi,[eax]
0079A763  call 0x0089160C    ; free node (no payload vcall)
...
0079A777  mov ecx,[edi]
0079A77B  mov eax,[edx+0x0C]
0079A77E  push esi
0079A77F  push esi
0079A780  push esi
0079A781  call eax
```

【確認】`[EDI+0x28]` 持有雙向環狀鏈結串列的哨兵節點（從 `[head]` 遍歷、`[head]`/`[head+4]` 自指重置），`[EDI+0x2C]` 為清零的相關計數。當 `+0x2C != 0` 且 `+0x38 == 0` 時，會對每個 node 的 `+8` payload 嘗試兩種虛擬呼叫（`+8`、`+0`）後釋放 node；否則略過 payload 呼叫但**仍清空及釋放 node**。兩分支在 `0x0079A777` 匯合，再次呼叫 core vtable `+0x0C` 並帶三個 `1`。函式結尾另比較 `[edi+0x2CC]`、`[edi+0x2D0]`，不等時 call `0x0079C8B0`。不把這條 linked-list 路徑錯當 22 桶本身，也不把這些虛擬呼叫都稱為同一個 callback。

## 6. 兩個上游 caller：初始化 guard 與必經派送的差異

### Caller A：`0x004931FD`

```asm
004931CB  test byte ptr [0x00FB79E8],1
004931D2  jne 0x004931F8
004931D4  or dword ptr [0x00FB79E8],esi
004931E2  call 0x007991E0
...
004931F8  mov edi,0x00FB76A8
004931FD  call 0x0079A320
00493202  test byte ptr [0x00FB79E8],1
...
```

【確認】`0x007991E0` 在這一 caller 中只有 guard 不成立時執行；dispatcher call 位於合流點 `0x004931F8`，並**不受該 guard 跳過**。所以不能把其「初始化 guard」解讀成 dispatcher 的一次性執行保證。

### Caller B：`0x006DD3EB`

```asm
006DD3B6  test byte ptr [0x00FB79E8],1
006DD3BD  jne 0x006DD3E6
006DD3BF  or dword ptr [0x00FB79E8],1
006DD3CD  call 0x007991E0
...
006DD3E6  mov edi,0x00FB76A8
006DD3EB  call 0x0079A320
006DD3F0  mov eax,[esi]
006DD3F2  mov ecx,[eax+0xA8]
006DD3F8  push esi
006DD3F9  call ecx
```

【確認】同樣在 guard 分支合流後執行 dispatcher。其後緊接著另一個 `ESI` 物件的 `vtable+0xA8`；且同函式先前已對該 `ESI` 物件進行 `+0x94/+0x98/+0x9C/+0xA4/+0xAC/+0xE4` 等多個方法調用（VA `0x006DD2AB～0x006DD362`），形成一段密集的物件操作序列。缺乏動態觸發與完整更上游鏈，不能斷言它是每幀 scene update。

## 7. 與分桶 producer 的重要區分

`0x0079A7C0` 位於 dispatcher 結束 `ret`（`0x0079A7BE`）之後，是**不同函式**；它直接透過 `[ECX+0x98]` 取得 bucket owner，按 `bucketIndex*0x2004` 找 count，`count<2048` 才存 entry，然後 count++：

```asm
0079A7C1  mov esi,[ecx+0x98]
0079A7D4  imul eax,eax,0x2004
0079A7DA  mov ecx,[eax+esi+0x2000]
0079A7E4  cmp ecx,0x800
0079A7EA  jge 0x0079A7F5
0079A7EC  mov [eax+ecx*4],edi
0079A7EF  inc dword ptr [eax+0x2000]
```

【確認】這是相同 owner 版型的 producer；尚未確認它的所有 caller，或是否一定先於本次 consumer 發生。不能因二函式地址相鄰就把 producer 視為 dispatcher 內部步驟。

## 8. C++ 行為示意（類別名皆為研究暫名）

```cpp
void dispatcher_0079A320(Manager* m_in_EDI) {
    helper_007CF3F0(0x00FE3250, 0);
    helper_0079B460(m_in_EDI);                // copies 0x34 bytes of core+0x98 state
    auto* queueOwner = *(void**)0x00FBA838;  // passed implicitly in ESI
    helper_007BB640(queueOwner);              // orders/processes up to limited count
    m_in_EDI->callback->slot_0C(m_in_EDI->bucket_owner); // T08-129 proven
    m_in_EDI->core->slot_0C(1, 1, 1);         // distinct slot on distinct vtable
    helper_007CF3F0(/* staging arguments, see ASM */);
    // ... additional work ...
    if (m_in_EDI->count_2C != 0 && m_in_EDI->flag_38 == 0) {
        for (Node* node : m_in_EDI->list_28) {
            node->payload->slot_08(m_in_EDI->core /* actual pushed ESI at point */);
            if (node->payload) node->payload->slot_00(1);
            free_node(node);
        }
    } else {
        for (Node* node : m_in_EDI->list_28) free_node(node);
    }
    reset_list_head_and_count();
    m_in_EDI->core->slot_0C(1,1,1);
    // subsequent offset 0x2CC / 0x2D0 book-keeping
}
```

偽碼為縮約的**控制流骨架**，不應用來宣稱真實的原始 C++ signature、方法含義、呼叫頻率或 helper 間不影響隱藏暫存器；詳細依上述 ASM。`0x007BB640` 的 `ESI` 是 dispatcher 在 `0x0079A38E` 設定、從全域載入的值。

## 9. 完成項與未解邊界

**T08-130 已完成的靜態主題**：

1. BIN 確認 dispatcher 前置 helper → 全域 22 桶 consumer → core 虛擬方法 → 狀態條件／鏈結節點回收 → core 方法的**程式碼順序**。
2. `0x007BB640` 的指標陣列起迄、處理筆數限制、排序候選、前 N 筆的虛擬執行、最後 end 重置；與全域 22 桶為不同結構。
3. `0x0079B460` 拷貝 core `+0x98` 開始 0x34 bytes 的資料，含數值計算 helper，不能直接跳到「相機」語義。
4. 兩個 caller 中 guard 僅包圍 `0x007991E0`，**不會跳過後續 dispatcher**；不能推斷頻率，但可排除「由此 guard 強制只執行一次」之說。
5. `0x0079A7C0` producer 與 `0x0079A320` dispatcher 是**不同函式**；記錄 BIN 實際碼位移與 PE 宣告的不一致。

**待下一段 T08-131**：追 `0x007BB640` 容器填充者、`0x007BB7B0` comparator 究竟排序何種事件；分辨 `0x0079B460` 的 0x34-byte core snapshot 如何被使用；追 `0x004931FD` 與 `0x006DD3EB` 更上游的可達事件；若要確定逐幀呼叫頻率需 runtime instrumentation（尚未做）。

**GitHub：未 Commit／Push。本段為本地獨立完整研究原稿。**