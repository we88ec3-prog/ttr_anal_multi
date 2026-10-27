# T08-108 — 管理器調度、幾何測試與全域桶的證據界線

研究者：chatgpt-web roy；2026-10-27 16:13 Asia/Taipei。原稿，供 GitHub `kr-temp-roy/`。本段延續 105–107。

## 證據來源及方法

- `/mnt/data/Tartaros.bin`，SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本回合重新計算，吻合 T08 固定指令）。
- 對 PE32 `.text` 使用 `objdump -d -Mintel` 原始 BIN 反組譯，檔案 `t08_disasm.txt`；以下為 VA 及指令位元組。
- 本段未發現可充分證實全域桶 `entries[i]` consumer / 清零者或六係數正常運作寫入者，不能宣稱兩項已解決。

## 發現一：`0x007D1310` 並非直接接受全域桶指標

函式開頭：

```asm
007D1398  8b 35 a8 76 fb 00     mov esi,DWORD PTR ds:0xfb76a8
007D139E  68 a8 76 fb 00        push 0xfb76a8
007D13A3  89 74 24 14           mov DWORD PTR [esp+0x14],esi
007D13A7  e8 44 92 fc ff        call 0x79a5f0
007D13AC  8b f8                 mov edi,eax
007D13C4  8b 5d 08              mov ebx,DWORD PTR [ebp+0x8]
007D13C7  83 bb 04 40 00 00 00  cmp DWORD PTR [ebx+0x4004],0
007D13D8  8b 54 24 14           mov edx,DWORD PTR [esp+0x14]
007D13DC  8b 8c 93 04 20 00 00  mov ecx,DWORD PTR [ebx+edx*4+0x2004]
007D13E3  8b 01                 mov eax,DWORD PTR [ecx]
007D13E5  8b 50 0c              mov edx,DWORD PTR [eax+0xc]
007D13E8  6a 01                 push 1
007D13EA  56                    push esi
007D13EB  ff d2                 call edx
007D13F6  3b 83 04 40 00 00     cmp eax,DWORD PTR [ebx+0x4004]
007D1405  c7 83 04 40 00 00 00  mov DWORD PTR [ebx+0x4004],0
```

分離：`ESI=[0x00FB76A8]` 是管理器內一欄位的 **值**；`push 0x00FB76A8` 是地址；`EBX=[EBP+8]` 另為 caller 所提供之分桶擁有者。`EBX+0x2004` entry、`EBX+0x4004` count 的讀取與清零，只能證明這個參數指向至少兩桶的內嵌配置，**不能**直接宣稱 EBX 就是 `[0x00FB7740]`。須追查 caller 的第二層指標來源。

此處透過 `entry->vtable[3]`（`+0x0C`）派送，並給出參數 `ESI` 與 `1`；實際虛表目標仍待定位。

## 發現二：`0x0079B520` 幾何閘門與調度，不是全域桶逐項 consumer 的直接證據

`0x007D13FE` 有 `push 3` 與 `push 0x00FB76A8`，呼叫 `0x0079B520`：

```asm
0079B528  8b 75 08              mov esi,[ebp+8]
0079B52C  56                    push esi
0079B52D  e8 be f0 ff ff        call 0x79a5f0
0079B539  8b 07                 mov eax,[edi]
0079B53B  8b 88 d4 00 00 00     mov ecx,[eax+0xd4]
0079B541  6a 00                 push 0
0079B543  53                    push ebx
0079B544  57                    push edi
0079B545  ff d1                 call ecx
0079B548  83 fb 08              cmp ebx,8
0079B54D  8b 45 0c              mov eax,[ebp+0xc]
0079B550  83 c0 fe              add eax,-2
0079B55C  ff 24 85 f8 b8 79 00  jmp DWORD PTR [eax*4+0x79b8f8]
0079B563  8b 86 d0 02 00 00     mov eax,[esi+0x2d0]
0079B569  2b 86 cc 02 00 00     sub eax,[esi+0x2cc]
0079B571  c1 f8 07              sar eax,7
0079B592  8b 9e cc 02 00 00     mov ebx,[esi+0x2cc]
0079B59B  83 7b 78 00           cmp DWORD PTR [ebx+0x78],0
0079B5B9  d9 43 4c              fld DWORD PTR [ebx+0x4c]
0079B5BC  8b 56 08              mov edx,[esi+8]
0079B5DA  e8 81 d2 09 00        call 0x838860
0079B5F4  8b 17                 mov edx,[edi]
0079B5F6  8b 8a d4 00 00 00     mov ecx,[edx+0xd4]
0079B604  8b 82 cc 00 00 00     mov eax,[edx+0xcc]
0079B610  ff d0                 call eax
```

確定這個函式具有 `0x80` bytes stride 的候選資料項，根據 `esi+0x2cc/0x2d0` 的範圍計算數量；`edx=[esi+8]` 傳入 `0x00838860`，使六半空間測試的**係數指標**來自本地管理器的 `+8` 欄位，而不是函式內直接讀取 `[0x00FB76B0]`。在 caller 為 `push 0x00FB76A8` 的路徑中，`esi+8` 地址正是 `0x00FB76B0`，從而形成幾何係數讀取的另一條經過驗證的**別名路徑**。

`edi` 為 `0x0079A5F0` 回傳之多型調度物件；`vtable+0xD4 / +0xCC` 分別有 dispatch 呼叫。這些虛函式作用未解析前，不宜斷言渲染、更新或全域桶 `entries[i]` 消費。

## 發現三：直接全域桶存取仍以插入者為主

對 BIN 中 `[0x00FB7740]` 的 15 個直接引用核對（T08-106/107 已詳記）：

`0x00798F78`, `0x007995A6`, `0x007995BA`, `0x0079CDA8`, `0x007BED5B`, `0x007CD7C9`, `0x007D34EB`, `0x007D357A`, `0x007DC369`, `0x007DF5A7`, `0x007E6A52`, `0x007F24AE`, `0x007F96ED`, `0x007FEC92`, `0x007FECE9`。

抽樣核查三個以前未在摘要逐項詳述的路徑：

```asm
007DC369 mov esi,DWORD PTR ds:0xfb7740
007DC373 imul eax,eax,0x2004
007DC379 mov ecx,[eax+esi+0x2000]
007DC38A mov [eax+ecx*4],edi
007DC38D inc DWORD PTR [eax+0x2000]

007DF5A7 mov edi,DWORD PTR ds:0xfb7740
007DF5B1 imul eax,eax,0x2004
007DF5B7 mov ecx,[eax+edi+0x2000]
007DF5C8 mov [eax+ecx*4],esi
007DF5CB inc DWORD PTR [eax+0x2000]

007E6A52 mov edi,DWORD PTR ds:0xfb7740
007E6A5C imul eax,eax,0x2004
007E6A62 mov ecx,[eax+edi+0x2000]
007E6A73 mov [eax+ecx*4],esi
007E6A76 inc DWORD PTR [eax+0x2000]
```

三者都有 count `<0x800` 條件。其模式為**生產者**，不是消費者。跨函式 manager `+0x98` 別名必須按 caller 單獨追蹤（T08-107 確認 `0x007D3601 -> 0x0079A3C0` 為一條全域桶 producer）。

## 暫定偽碼與型別界線

```cpp
// 只是依原始 ASM 轉寫，不宣稱真實 C++ 類別。
void dispatchManagerBuckets(BucketOwner* owner) {
    auto& b = owner->embeddedBuckets[1]; // offset +0x2004
    for (int i=0; i<b.count; ++i)
        b.entries[i]->vtable_0C(/* manager payload, stage=1 */);
    b.count=0;
    dispatchStages((void*)0x00FB76A8, 3);
}

void dispatchStages(Manager* manager, int mode) {
    auto* sink = getDispatchObject(manager); // call 0x79A5F0
    // vtable +D4 etc. with mode-dependent paths
    for (auto& record : manager->records_0x80) {
        if (record.enabled && geometryFilter(manager->planesAtOffset8, record))
            sink->virtualCC(/* bucket/item arguments */);
    }
}
```

第二個偽碼只是 0x79B520 部分分支的概念轉寫，並非全覆蓋；stage enum 和實際欄位語義待查。

## 與 T08-105～107 的關係及狀態

- **新增已確認**：`0x0079B520` 使用管理器 `+8` 的係數指標；在 `0x007D13FE` caller 傳入 `0x00FB76A8` 地址時確定對應 `[0x00FB76B0]`。與直接引用之外的間接幾何讀者串聯。
- **再次確認**：`0x007D1310` 的分桶 `EBX` 來自函式參數，與係數管理器 `ESI` 是不同來源，不能把分桶消費者直接併到全域桶。
- **未解**：全域桶真正 entries consumer / count reset；六係數正常非零填值函式；所有調度虛方法實作。
- **T08-109 建議**：往上追 `0x007D1310` caller 的 `owner` 來源，再解析 `0x0079A5F0` 與 `+0xCC/+0xD4` 的虛表目標；同時對 `[0x00FB76B0]` 之 manager+8 別名尋找寫入端。

GitHub：本次原稿應連同未提交的 T08-105（兩份）、106、107 由使用者本次授權推送；未取得遠端回讀前不可宣稱成功。