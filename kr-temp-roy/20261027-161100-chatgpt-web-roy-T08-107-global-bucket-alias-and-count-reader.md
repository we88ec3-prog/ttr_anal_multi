# T08-107 — Global bucket alias proof and count-reader chain

研究者：chatgpt-web roy；2026-10-27 Asia/Taipei。未提交 GitHub。

## 來源與驗證

- 本地 `/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與 T08 固定指令一致。
- 使用本地 `objdump -d -Mintel` 的 `.text` 反組譯產物 `t08_disasm.txt` 搜尋，重要位置由實際地址及機器碼核對。
- 延續 T08-105、106，本段不重複建立結構；以下修正其指標別名的未知狀態。

## 主要新發現 A：`0x0079A3C0` 這條路徑確實插入全域桶

```asm
007D35F7  b9 a8 76 fb 00        mov ecx,0x00FB76A8
007D35FC  8b fb                 mov edi,ebx
007D35FE  8b 43 08              mov eax,[ebx+0x08]
007D3601  e8 ba 6d fc ff        call 0x0079A3C0
0079A3C0  56                    push esi
0079A3C1  8b b1 98 00 00 00     mov esi,[ecx+0x98]
0079A3D4  69 c0 04 20 00 00     imul eax,eax,0x2004
0079A3DA  8b 8c 30 00 20 00 00  mov ecx,[eax+esi+0x2000]
0079A3EC  89 3c 88              mov [eax+ecx*4],edi
0079A3EF  ff 80 00 20 00 00     inc DWORD PTR [eax+0x2000]
```

`0x00FB76A8 + 0x98 = 0x00FB7740`，因此在這條呼叫路徑內，`ESI=[0x00FB7740]`。注意 `0x007D3569` 也跳往 `0x007D3601`，而其前有 `mov ecx,0x00FB76A8`（`0x007D3559`）；`0x007D35EE` 也是明確設定 ECX。這是由 caller 實值證明的別名，不是僅因結構同型而猜測。

`0x0079A3C0` 為可重用、以 ECX 指定容器指標持有者的 helper；**只對上述已證明 caller**可說是全域桶，其他 hypothetical caller 仍須各自追蹤。靜態 `.text` 搜尋 `call 0x79a3c0` 僅直接找到 `0x007D3601`（不排除間接調用或另類跳入）。

## 主要新發現 B：全域桶 count 的真實讀取者

直接 caller：

```asm
00492DAD  e8 8e 19 fa ff        call 0x00434740
00492DB2  8b c8                 mov ecx,eax
00492DB4  e8 77 8c 30 00        call 0x0079BA30
00492DB9  c7 05 0c f7 fd 00 1e 00 00 00  mov DWORD PTR [0x00FDF70C],0x1e
0043478E  b8 a8 76 fb 00        mov eax,0x00FB76A8
```

`0x00434740` 有一次性初始化檢查，最後回傳全域管理器固定地址 `0x00FB76A8`。故此 caller 傳入 `ECX=0x00FB76A8`，`0x0079BA30` 以 `ESI=ECX` 存放，再讀取 `ESI+0x98`，與 `[0x00FB7740]` 相同。

```asm
0079BA5C  8b f1                 mov esi,ecx
0079BA5E  8b 86 98 00 00 00     mov eax,[esi+0x98]
0079BA64  8b 80 10 a0 00 00     mov eax,[eax+0xA010]
0079BA6A  50                    push eax
0079BA6B  8d 8d f0 fe ff ff     lea ecx,[ebp-0x110]
0079BA71  68 d4 f3 c4 00        push 0x00C4F3D4
0079BA76  51                    push ecx
0079BA77  e8 b3 70 0f 00        call 0x00892B2F
0079BAA3  8b 86 98 00 00 00     mov eax,[esi+0x98]
0079BAA9  8b 80 4c 80 02 00     mov eax,[eax+0x2804C]
0079BAEB  8b 86 98 00 00 00     mov eax,[esi+0x98]
0079BAF1  8b 80 44 40 02 00     mov eax,[eax+0x24044]
```

桶 `i` 的 count 在 `base + i*0x2004 + 0x2000`：

- `0xA010 = 4*0x2004+0x2000`：第4桶（零起算）；
- `0x2804C = 19*0x2004+0x2000`：第19桶；
- `0x24044 = 17*0x2004+0x2000`：第17桶。

它們作為 `0x00892B2F` 格式化函式的參數，接著參與文字組裝；這是 **count reader/診斷或輸出使用者**，**並非**逐筆 `entries[i]` 的派送 consumer。從 `0x00492DB9` 設定 `0x00FDF70C=0x1E`，且前面檢查此值，可推測某種間隔輸出；但未建立確切時間單位或更新頻率。

## 與內嵌 consumer 的區分，仍成立

```asm
007D16F8  ba 13 00 00 00        mov edx,0x13
007D16FD  8d 83 4c 60 02 00     lea eax,[ebx+0x2604C]
007D1720  8b 0c b8              mov ecx,[eax+edi*4]
007D1723  8b 01                 mov eax,[ecx]
007D1726  8b 50 0c              mov edx,[eax+0x0c]
007D172A  ff d2                 call edx
007D173D  c7 80 00 20 00 00 00 00 00 00  mov DWORD PTR [eax+0x2000],0
```

這條 consumer 從 `EBX+0x2604C` 直接獲得內嵌桶位置，不讀 `[0x00FB7740]`；即使上述第19桶同為數字19，也**不能**證實兩者的相同性。它的 `entry->vtable+0x0C` 派送已核實，但須另行回溯 EBX 的物件來源與布局，才可說明時序及持有關係。

## 六係數寫入者：狀態及限制

本段未發現 `[0x00FB76B0]` 所指向 0x60-byte buffer 的非初始化內容寫入者。先前 T08-105/106 `0x00798E4D～0x00798E93` 為清零初始化，`0x00838800/0x00838860` 為測試讀者。不得將其命名為已確認的相機視錐。

## C++ 暫定偽碼（只對已確認呼叫脈絡）

```cpp
constexpr uintptr_t gManager = 0x00FB76A8;
struct Bucket { void* entries[2048]; int32_t count; };
// 靜態地址別名：gManager+0x98==0x00FB7740
Bucket* buckets = *reinterpret_cast<Bucket**>(gManager+0x98);

void insertVia79A3C0(int bucketIndex, void* entry) {
    Bucket& bucket = buckets[bucketIndex];
    if (bucket.count < 2048) {
        bucket.entries[bucket.count] = entry;
        ++bucket.count;
    }
}

void countLogger79BA30() {
    auto b4  = buckets[4].count;
    auto b19 = buckets[19].count;
    auto b17 = buckets[17].count;
    // values passed through formatting pipeline; exact presentation TBD
}
```

注意：`bucketIndex` 在 `0x0079A3C0` 中可能由 entry vtable+4 取得；此偽碼僅呈現已驗證的核心寫入機制，不能當原始 C++ 程式碼。

## 已確認 / 推測 / 待驗證

**已確認**：從 `0x007D3601` 呼叫的 `0x0079A3C0` 是 `[0x00FB7740]` 的 producer；從 `0x00492DB4` 呼叫的 `0x0079BA30` 是同一全域 22 桶若干 count 的 reader；`0x007D170B` 使用 `EBX+0x2604C` 內嵌桶。

**推測**：`0x0079BA30` 是週期性狀態紀錄或診斷輸出，未核實完整字串及頻率；不可叫作渲染調度。

**待驗證**：全域桶的 `entries[i]` consumer 與 count reset；`EBX` 所持內嵌桶的類型與配置；六係數正常更新 writer；場景 vtable `0x00C07554+0x20` 主調度鏈。

## 下一段 T08-108

1. 搜尋 `0x00FB7740` global buffer 的間接 read/clear（尤其 count 清零），從可能的 manager 迭代呼叫者反溯。
2. 回溯 `0x007D170B` 的 EBX 指標來源及建構／生命週期，區分真正內嵌桶與全域22桶所有權。
3. 從六係數 buffer 下游使用的寄存器指標再往上追尋 store (`fstp`, `movss`, `memcpy`)，不只靠絕對地址 xrefs。

## Git 狀態

本地完整原稿，沒有 Commit、沒有 Push；上一段未提交 T08-105 初稿、T08-105 延伸、T08-106 均未覆寫。