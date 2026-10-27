# T08-131 — `0x00FBA838` 全域物件、候選佇列、部分排序比較器與生命週期

研究日期：2026-10-27（Asia/Taipei）；本輪 **未 Commit / Push**。

## 1. 證據與限制

- 第一手檔案：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新實測。
- 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=VA` 對選定 BIN 切片反組譯；切片起始 file offset=`VA-0x401000`，這是 T08-130 已對該碼段確認可對應的映射，並非通用 PE 映射假設。
- 舊段 T08-129 已確立 `0x0079A320` 的全域22桶呼叫；T08-130 已確認其前置 `0x007BB640`。本段只追新的排序/物件鏈，不將兩套容器混稱。
- 這是靜態證據，未做執行斷點、記憶體監視或場景觸發。沒有完整標準 C++ 符號，語義性命名僅為暫名。

## 2. 本輪新增：全域 `0x00FBA838` 的建構與釋放

全域槽被 `0x007AAF41` 之後的初始路徑使用：

```asm
007AAF41 cmp dword ptr [0x00FBA838],0
007AAF48 jne 0x007AAF7D
007AAF4A push 0x10C
007AAF4F call 0x00891668          ; heap allocation
007AAF65 push eax
007AAF66 call 0x007B8E50          ; constructor
007AAF6F cmp dword ptr [0x00FBA838],0
007AAF78 mov [0x00FBA838],eax    ; publish object pointer
```

**確認**：這個全域槽指向的是由 `0x007B8E50` 建構的約 `0x10C` bytes 物件，不是全域 22 桶 (`[0x00FB7740]`) 的本體，也不是可直接將槽地址當物件位址。

其相反的回收路徑：

```asm
007AAFB5 mov ecx,[0x00FBA838]
007AAFC6 mov eax,[ecx]
007AAFC8 mov edx,[eax+4]
007AAFCB push 1
007AAFCC call edx
007AAFCE mov [0x00FBA838],edi     ; EDI=0 in this path
```

**確認**：程式對該物件虛表 `+4` 進行帶 `1` 的釋放式呼叫，隨後清空全域槽；實際 destructor 身分需要追查 `vptr=0x00C4FC8C` 的實體目標才可命名。

## 3. `0x007B8E50` 建構兩組獨立陣列及預設限制

```asm
007B8E78 mov edi,[ebp+8]          ; newly allocated object
007B8E80 mov dword ptr [edi],0x00C4FC8C
...
007B8F64 mov [edi+0xA4],ebx       ; EBX=0
007B8F6A mov [edi+0xA8],ebx
007B8F70 mov [edi+0xAC],ebx
007B8F76 mov [edi+0xB4],ebx
007B8F7C mov [edi+0xB8],ebx
007B8F82 mov [edi+0xBC],ebx
007B8F88 mov dword ptr [edi+0xC4],4
007B8F92 mov [edi+0xC8],ebx
007B8F98 mov [edi+0xCC],ebx
007B8F9E mov [edi+0xD0],ebx
```

**確認**：`+A4/+A8/+AC`、`+B4/+B8/+BC`、`+C8/+CC/+D0` 均以三 DWORD 方式清零；其中 `+B4/+B8` 被 consumer `0x007BB640` 當作陣列 begin/end 使用。`+C4` 的建構時預設值是整數 `4`，因此一般預設最多處理 **4 個 entry**，但不能推定執行期間此值永遠為 4。

特別注意：另一個方法 `0x007BB550` 會在 `0x007BB61A` 把 `EDI` 指到 `+A4` 並呼叫陣列插入助手 `0x007BB750`，**不是**本段 consumer 的 `+B4` 陣列；不可將這個寫入當成 `+B4` 的直接 producer。後續另需找寫 `+B8` 的非建構操作或從其他容器搬移至 `+B4` 的函式。

## 4. `0x007BB640`：全範圍與受限前段的明確差別

```asm
007BB664 mov eax,[esi+0xB8]       ; end
007BB66A sub eax,[esi+0xB4]       ; end-begin
007BB670 mov ebx,[esi+0xC4]       ; requested cap
007BB676 sar eax,2                ; element count
007BB679 cmp ebx,eax
007BB67B jbe 0x007BB67F
007BB67D mov ebx,eax              ; n=min(cap,count)
...
007BB6AF mov eax,[0x00FB76E8]
007BB6B4 mov edi,[eax+0x0C]
007BB6B7 mov edx,[esi+0xB4]
007BB6C2 mov [ecx],edi
007BB6C4 mov edi,[eax+0x10]
007BB6C7 mov eax,[eax+0x14]
007BB6CA mov [ecx+4],edi
007BB6CD mov [ecx+8],eax          ; 12-byte key context
007BB6D0 mov eax,[esi+0xB8]
007BB6D6 push eax                 ; last=end
007BB6D7 lea eax,[edx+ebx*4]
007BB6DA push eax                 ; middle=begin+4*n
007BB6DB push edx                 ; first=begin
007BB6DC call 0x007BB7B0
007BB6E1 add esp,0x18             ; 3 ptr + 12-byte context
```

**確認**：`0x007BB7B0` 接到 `first, middle, last` 三個指標，其中 `middle` 限定「要優先處理的前 n 筆」，而 `last` 指向整個陣列末尾。這與單純對前 n 筆做局部排序不同：後端排序程序收到 *整個* `[first,last)` 及前段界址 `[first,middle)`。

**強合理推測**：從三界址參數、在大範圍採分割、在短範圍採小排序助手（見 §5）判斷，該函式很可能是 C++ `partial_sort` 或同等的 top-N selection+sort 實作。要宣稱原始 STL 精確模板仍需更多比對，現階段使用「三界址部分排序候選」。

## 5. `0x007BB7B0` 的排序算法及元素的比較介面

```asm
007BB7B3 mov eax,[ebp+0x10]       ; last
007BB7BA mov ebx,[ebp+8]          ; first
007BB7BD sub eax,ebx
007BB7BF sar eax,2
007BB7C4 cmp eax,0x20
007BB7C7 jle 0x007BBA74          ; shorter range branch
007BB804 call 0x007BBAA0         ; partition/helper
...
007BBA8D push eax                 ; last
007BBA8E mov ecx,ebx             ; first
007BBA90 call 0x007BBB90         ; short-range helper
```

比較序列出現在本函式多處，例如：

```asm
007BB816 mov eax,[esi]            ; current entry pointer
007BB818 mov ecx,[esi-4]          ; other entry pointer
007BB81B mov edx,[ecx]           ; vtable
007BB81D mov edx,[edx+8]
007BB823 lea eax,[ebp-0x1C]     ; address of 12-byte context
007BB826 push eax
007BB827 call edx                 ; virtual +8 -> x87 return
007BB829 fstp qword ptr [ebp-0x10]
007BB82C mov ecx,[ebp-8]
007BB82F mov eax,[ecx]
007BB831 mov eax,[eax+8]
007BB834 lea edx,[ebp-0x1C]
007BB837 push edx
007BB838 call eax                 ; another entry virtual +8
007BB83A fcomp qword ptr [ebp-0x10]
007BB83D fnstsw ax
007BB83F test ah,0x41
```

**確認**：比較並非一般整數欄位，而是對兩個 entry 物件各呼叫 `vtable+8`，取得浮點值（第二個值保留於 x87 stack，第一個先存 qword），再執行浮點比較。共同 context 是 `0x00FB76E8` 所指物件 `+0x0C/+0x10/+0x14` 三 DWORD 的快照。

不能僅憑其數量為 3 就命名為世界座標或相機位置：目前僅證實 12 bytes／三 DWORD 與浮點比較結果；它們對排序值的影響取決於不同 entry 的虛擬方法 `+8` 實作，尚未解析。也不應在未解明 `fnstsw/test ah` 及 NaN 分支前過度指定升冪／降冪在所有情況的行為。

## 6. 輔助比較／分割方法 `0x007BBC70`

```asm
007BBC79 mov ecx,[esi]
007BBC7B mov edx,[ecx]
007BBC7D mov edx,[edx+8]
007BBC86 lea eax,[ebp+0x0C]
007BBC89 push eax
007BBC8A call edx
007BBC8C fstp qword ptr [ebp-0x0C]
007BBC8F mov eax,[ebx]
007BBC91 mov edx,[eax+8]
007BBC94 lea ecx,[ebp+0x0C]
007BBC97 push ecx
007BBC98 mov ecx,ebx
007BBC9A call edx
007BBC9C fcomp qword ptr [ebp-0x0C]
007BBC9F fnstsw ax
007BBCA1 test ah,0x41
007BBCA4 jne 0x007BBCAE
007BBCA6 mov ecx,[edi]
007BBCA8 mov eax,[esi]
007BBCAA mov [esi],ecx
007BBCAC mov [edi],eax
```

**確認**：`0x007BBC70` 同樣透過 entry 虛表 `+8` 取得以同一 context 評分的浮點值並比較，條件成立時交換兩個指標槽。這強化了前述「按動態浮點評分排序，而非直接按 entry 地址或建立順序排序」的結論。

## 7. 消費階段與清空語義

```asm
007BB6E4 xor edi,edi
007BB6E6 test ebx,ebx
007BB6F0 mov ecx,[esi+0xB4]
007BB6F6 mov ecx,[ecx+edi*4]
007BB6F9 mov edx,[ecx]
007BB6FB mov eax,[edx+4]
007BB6FE call eax                 ; process entry's virtual +4
007BB700 inc edi
007BB701 cmp edi,ebx
007BB703 jb 0x007BB6F0
007BB705 mov ecx,[esi+0xB8]
007BB70B mov edi,[esi+0xB4]
007BB711 cmp edi,ecx
007BB715 mov eax,ecx
007BB717 sub eax,ecx              ; eax=0, unlike a normal copy length
007BB719 sar eax,2
007BB71C lea ebx,[eax*4]
007BB723 push ebx
007BB724 push ecx
007BB725 push edi
007BB726 call 0x008916F0
007BB72E add ebx,edi
007BB730 mov [esi+0xB8],ebx      ; end=begin
```

**確認**：執行最多 n 個 entry 的 `vtable+4`，然後清空整個佇列的可見區間（end 設回 begin）。依本 BIN 指令，複製助手收到 length=0；不能聲稱其搬動或釋放陣列中的每個 entry。即使超過上限的 entry 沒執行虛表 `+4`，同樣會從可見陣列消失；但 entry 其他 owner／引用壽命仍需另外追查。

## 8. 析構側佐證：三組陣列獨立配置

在物件回收相關路徑 `0x007B91A5～0x007B9213`：

```asm
007B91A5 mov eax,[ebx+0xC8]
007B91B4 push eax
007B91B5 call 0x0089160C          ; if nonnull
007B91BD mov [ebx+0xC8],esi      ; ESI=0
007B91C3 mov [ebx+0xCC],esi
007B91C9 mov [ebx+0xD0],esi
007B91CF mov eax,[ebx+0xB4]
007B91D9 push eax
007B91DA call 0x0089160C          ; if nonnull
007B91E2 mov [ebx+0xB4],esi
007B91E8 mov [ebx+0xB8],esi
007B91EE mov [ebx+0xBC],esi
007B91F4 mov eax,[ebx+0xA4]
007B91FE push eax
007B91FF call 0x0089160C          ; if nonnull
007B9207 mov [ebx+0xA4],esi
007B920D mov [ebx+0xA8],esi
007B9213 mov [ebx+0xAC],esi
```

**確認**：各陣列的 begin 指標分別被傳入 free helper，並各自將三指標歸零；支持三套容器各有自己的 backing storage。這只證實 backing allocation 回收，仍**不代表其中每個 entry 指向的多型物件必被這段析構所刪除**。

## 9. 精簡偽碼（暫名，非真實簽名）

```cpp
struct QueueOwnerCandidate {                  // from 0x007B8E50
    // vptr at +0, other fields omitted
    void** array_A_begin;  // +A4 (different vector)
    void** array_A_end;    // +A8
    void** array_A_cap;    // +AC
    void** queue_begin;    // +B4
    void** queue_end;      // +B8
    void** queue_cap;      // +BC
    uint32_t dispatch_limit; // +C4, initialized to 4
    // +C8/+CC/+D0 third vector
};

// Consumer uses QueueOwnerCandidate* passed in ESI.
void process_queue_007BB640(QueueOwnerCandidate* q) {
    size_t total = (q->queue_end - q->queue_begin);
    size_t n = min<size_t>(q->dispatch_limit, total);
    auto context = snapshot_3_dwords(*(void**)0x00FB76E8, 0xC, 0x10, 0x14);
    partial_sort_candidate(q->queue_begin, q->queue_begin+n, q->queue_end,
        [&](auto a, auto b) {
            return compare_x87(a->virtual_08(context), b->virtual_08(context));
        });
    for (size_t i=0; i<n; ++i) q->queue_begin[i]->virtual_04();
    q->queue_end = q->queue_begin;   // visible queue cleared
}
```

簽名、省略的初始化 guard、例外處理、x87 順序與容器欄位別名等均需以 asm 為準；`partial_sort_candidate` **不是已證實原始函式名稱**。未核實溢位、負容量、空指標、例外等完整邊界。

## 10. 與 T08-129／130 的功能鏈及目前缺口

```text
0x007AAF41..7D       global owner creation
    -> alloc 0x10C -> 0x007B8E50 -> [0x00FBA838]

0x004931FD / 0x006DD3EB
    -> 0x0079A320 dispatcher
       -> 0x0079B460 core snapshot
       -> ESI=[0x00FBA838]
       -> 0x007BB640 (this study)
          -> +B4/+B8 queue, n=min(+C4, count), default +C4=4
          -> 3-DWORD comparison context from [0x00FB76E8]+C..14
          -> 0x007BB7B0 -> 0x007BBAA0, 0x007BBB90, 0x007BBC70
             -> entry->vtable+8 floating score
          -> first n entry->vtable+4
          -> +B8=+B4 (clear visible queue)
       -> callback->vtable+0C -> 0x007D1310
          -> global 22 buckets [0x00FB7740]
```

**分離邊界**：兩個佇列/桶的確在同一個 dispatcher 串接，但當前不能證明 queue entry 的 `vtable+4` 必然生產全域桶 entry；那需要對 entry 具體 vtable 身分與其 `+4` 執行目標建立新證據。

**本輪未解**：
1. `+B4/+B8` 的非建構 append/writer 尚未完整定位；不可拿 `0x007BB550` 的 `+A4` 插入混充。
2. 具體 entry 類別/vtable、slot `+8` 的評分公式及其是否代表距離或可視程度仍未知。
3. `[0x00FB76E8]` 的 `+0C/+10/+14` 值來源與語義尚未追完。
4. 執行頻率、超過 top-N 的其他 owner 與實際 runtime 行為未驗證。

**建議 T08-132**：反查 `+B4/+B8` 真正 producer（先以 `0x00C4FC8C` 虛表可達的方法及 `0x007B8E50` 同族成員函式縮小範圍）；解析 entry 具體 `vtable+8` 評分與 `+4` 執行函式；建立是否輸出到 global 22-bucket 的精確橋接或排除證據。可另外核對 `0x007BB7B0` 是否 STL partial_sort 編譯器實作，但不是確立新資料流的前提。

GitHub：**本輪未 Commit／Push**。此 Markdown 為 T08-131 獨立技術研究原稿。