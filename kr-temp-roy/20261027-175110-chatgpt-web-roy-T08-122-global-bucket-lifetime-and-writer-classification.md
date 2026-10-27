# T08-122 — Global 22-bucket allocation, lifecycle, and producer boundary

- Task: T08｜researcher: chatgpt-web roy｜time: 2026-10-27 17:51 Asia/Taipei
- Original: Tartaros.bin｜SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪本地計算確認）
- Source: 本輪以 `objdump -d -Mintel /mnt/data/Tartaros.bin` 反組譯直接對照 ASM；無 Ghidra 推論冒充原始機器碼。
- Evidence grading: **已確認** = machine code supports; **推測** = interpretation; **未知** = no proof.
- Repository target: `kr-temp-roy/`，不更動其他 Agent 內容。

## 1. 新的直接生命週期複驗
全域 `[0x00FB7740]` 是指向配置的指標槽，不是內嵌桶的第一個 entries array；配置時預留 `0x2C058` bytes。迴圈 `EDX=0x15` 遞減到 0，把各桶 count 位置寫0。每桶步長 `0x2004`；22個桶的理論 bytes=22×0x2004=`0x2C058`。

```asm
00798F21 mov edi,1
00798F26 push 0x2c058
00798F4F call 0x891268
00798F5B mov edx,0x15
00798F60 lea ecx,[eax+0x2000]
00798F66 mov dword ptr [ecx],ebx
00798F68 add ecx,0x2004
00798F6E sub edx,edi
00798F70 jns 0x798f66
00798F78 mov ds:0xfb7740,eax
```

配置釋放（未表示發生在任一普通 frame 的末尾）：
```asm
007995A6 mov eax,ds:0xfb7740
007995AB xor edi,edi
007995AD cmp eax,edi
007995AF je 0x7995c0
007995B1 push eax
007995B2 call 0x89120c
007995BA mov dword ptr ds:0xfb7740,edi
```

## 2. 多個實際 producer 具有一致的入桶條件
本輪從第一手機器碼另核對 `0x007DC369`、`0x007DF5A7`、`0x007E6A52`、`0x007F96ED`：

```asm
007DC364 mov edx,[edi]
007DC366 mov eax,[edx+4]
007DC369 mov esi,ds:0xfb7740
007DC371 call eax
007DC373 imul eax,eax,0x2004
007DC379 mov ecx,[eax+esi+0x2000]
007DC382 cmp ecx,0x800
007DC38A mov [eax+ecx*4],edi
007DC38D inc dword ptr [eax+0x2000]

007DF5A2 mov eax,[esi]
007DF5A4 mov edx,[eax+4]
007DF5A7 mov edi,ds:0xfb7740
007DF5AF call edx
007DF5B1 imul eax,eax,0x2004
007DF5B7 mov ecx,[eax+edi+0x2000]
007DF5C0 cmp ecx,0x800
007DF5C8 mov [eax+ecx*4],esi
007DF5CB inc dword ptr [eax+0x2000]

007E6A4D mov eax,[esi]
007E6A4F mov edx,[eax+4]
007E6A52 mov edi,ds:0xfb7740
007E6A5A call edx
007E6A5C imul eax,eax,0x2004
007E6A62 mov ecx,[eax+edi+0x2000]
007E6A6B cmp ecx,0x800
007E6A73 mov [eax+ecx*4],esi
007E6A76 inc dword ptr [eax+0x2000]
```

上述虛槽+0x04 回傳桶號，接著檢查 count < 2048、寫入物件 pointer、增加 count；具體 C++ 類型不同，不能因相同 +0x04 便視作同一 class。

## 3. 指標別名
舊 T08-107 已證實呼叫者傳 `ECX=0x00FB76A8` 給 `0x0079A3C0`，函式取 `[ECX+0x98]` = `[0x00FB7740]`；這只確認 producer 路徑。與 `0x007D1310` 消費其他 owner 的可能性沒有衝突。

## 4. 概念偽碼
```cpp
struct Bucket { void* entries[2048]; unsigned count; }; // 0x2004
Bucket* globalBuckets; // 22 buckets
void enqueue(Object* object) {
  auto kind=object->virtual04();
  auto& b=globalBuckets[kind];
  if (b.count<2048) b.entries[b.count++]=object;
}
```

## 5. 邊界
- **已確認** 配置、count 初始化、釋放與實際多路生產者。
- **未知** 正常運作時 count 清零者/逐筆 consumer，以及無效桶號邊界檢查（本段片段未顯示）；不應假設輸入 type 一定 0～21。
- T08-123 追其中一條調度鏈，不將陣列配置函式誤稱 frame loop。