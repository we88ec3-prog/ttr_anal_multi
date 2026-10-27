# T08-105 — 全域桶與六係數的靜態直接引用盤點（部分完成）

時間：20261027-155733 Asia/Taipei；未提交 GitHub。原始 BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與專案指定值一致。使用 `/mnt/data/Tartaros.bin` 直接讀取位元組並以 objdump x86 反組譯；本次未完成跨函式資料流與間接別名的全域證明。

## 本次新增直接引用證據

| 全域 | `.text` 內立即數直接引用 VA |
|---|---|
| `0x00FB7740` | `0x00798F79`, `0x007995A7`, `0x007995BC`, `0x0079CDAA`, `0x007BED5D`, `0x007CD7CB`, `0x007D34ED`, `0x007D357C`, `0x007DC36B`, `0x007DF5A9`, `0x007E6A54`, `0x007F24B0`, `0x007F96EF`, `0x007FEC94`, `0x007FECEB` |
| `0x00FB76B0` | `0x0049DAFD`, `0x004AA322`, `0x004C9BED`, `0x0055B43B`, `0x0055B629`, `0x00798E9D`, `0x00799640`, `0x00799653`, `0x007A5D46`, `0x007E10EA`, `0x007E4356`, `0x007F25A1`, `0x007F3032`, `0x007F754C`, `0x007F98C0`, `0x007FE49A` |

上述列表是逐位元組搜尋 little-endian 32-bit 絕對地址，**不是完整交叉引用**，可能包含非指令命中，也不能找出透過指標別名的讀寫者。需逐個指令邊界驗證。

## 已直接反組譯驗證

### `0x007F2520`：六係數讀取者，而非寫入者

```asm
007F254F mov eax,[esi+0x88]
007F2555 mov ecx,[eax+0x68]
007F2558 mov edx,[eax+0x6c]
007F255B mov eax,[eax+0x70]
007F2599 fld dword ptr [esi+0xb0]
007F259F mov edx,[0x00FB76B0]
007F25C0 call 0x00838860
007F25CE mov [esi+0x80],eax
```

呼叫前 `[ebp-0x18/-0x14/-0x10]` 暫存三個分量，配合 `esi+0xB0` 第四分量，以 16 bytes stack 參數傳入；返回值先由 `sete` 轉換為布林再寫 `esi+0x80`。**未對六係數內容寫入**。

### `0x007D170B`：管理器內嵌桶消費（不是全域桶的已證 consumer）

```asm
007D16FD lea eax,[ebx+0x2604c]
007D170B cmp edx,0x16
007D1720 mov ecx,[eax+edi*4]
007D1723 mov eax,[ecx]
007D1726 mov edx,[eax+0x0c]
007D172A call edx
007D173D mov dword ptr [eax+0x2000],0
007D1748 add eax,0x2004
007D1780 mov dword ptr [ebx],0
007D1786 add ebx,0x2004
```

`edx` 初始為 `0x13`，因此第一段只消費桶 19、20、21；後續清空 22 桶 count。`eax` 來自 `ebx+0x2604C`，不是讀取 `[0x00FB7740]`。對 entry 執行 `vtable+0x0C`，兩參數由 `push esi`、`push edx` 提供。需從完整函式入口追溯 `ebx` 的所有者。

### 全域桶與係數引用的邊界

`[0x00FB7740]` 直接引用有 15 處（含初始化/清理/生產者）；`[0x00FB76B0]` 有 16 處（含初始化/清理/讀取者）。**不能**因係數的直接引用多數用 `mov edx,[global]` 就推斷不存在間接寫入者；反之應對每一處的下游 `edx` 記憶體寫入進行追蹤。

## 待完成（T08-105 延伸或 T08-106）

1. 對係數引用 `0x0049DAFD, 0x004AA322, 0x004C9BED, 0x0055B43B, 0x0055B629, 0x007A5D46, 0x007E10EA, 0x007E4356, 0x007F3032, 0x007F98C0, 0x007FE49A` 各自反組譯至實際 `fstp [edx+...]` 或讀取鏈，判斷是否寫入內容。
2. 追蹤全域桶所有直接引用的容器基址，尤其 `0x007FECEB` 的第10桶來源與管理器清零者。
3. 回溯 `0x007D170B` 的 `ebx` 來源、entry vtable 候選實作及呼叫頻率；不得直接命名場景主更新。
4. 從確實消費全域桶的函式再追至 `0x00C07554+0x20`，目前無直接連結證據。

## 偽碼（僅已確認的內嵌桶片段）

```cpp
// owner is an as-yet unidentified manager object (EBX).
for (int bucket = 19; bucket < 22; ++bucket) {
    auto* entries = (uint8_t*)owner + 0x2604C + bucket * 0x2004;
    int count = *(int*)(entries + 0x2000);
    for (int i = 0; i < count; ++i)
        entries[i]->vtable[3](entries[i], context, bucket);
    *(int*)(entries + 0x2000) = 0;
}
// A separate 22-count reset loop follows.
```

**證據分級：** 直接 BIN 位元組及上列 ASM 已確認；函式角色、owner 真正類型、全域桶 consumer、係數實際寫入者、相機視錐語義及場景主更新鏈尚未確認。此稿為本段已完成的部分調查，**不宣稱完成 T08-105 全部目標**。