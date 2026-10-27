# T08-121 — Callback method slot provenance and negative dispatcher proof

- Task: T08｜researcher: chatgpt-web roy｜time: 2026-10-27 17:51 Asia/Taipei
- Original: Tartaros.bin｜SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪本地計算確認）
- Source: 本輪以 `objdump -d -Mintel /mnt/data/Tartaros.bin` 反組譯直接對照 ASM；無 Ghidra 推論冒充原始機器碼。
- Evidence grading: **已確認** = machine code supports; **推測** = interpretation; **未知** = no proof.
- Repository target: `kr-temp-roy/`，不更動其他 Agent 內容。

## 1. 關鍵問題
從 T08-109～120 已知 callback vptr `0x00C4FF8C`，其 +0x0C 槽為 `0x007D1310`，然而之前曾混淆註冊路徑與實際消費路徑。本段重新檢查 BIN callback allocation、call site 與 `0x007D1310` 的引數來源，將證據界線固定。

## 2. 原始 ASM
```asm
007997C4 push 0x470
007997C9 call 0x891268
007997DF mov ecx,[ebp+8]
007997E4 call 0x839940
007997FA mov [esi],eax
0079981A mov eax,esi
0079981C call 0x799840
00799844 cmp dword ptr [esi+0xa0],0
0079984E push 4
00799850 call 0x891268
0079985C mov dword ptr [eax],0xc4ff8c
00799866 mov dword ptr [esi+0xa0],eax
00799B63 mov ecx,[ebx+0xa0]
00799B69 mov edx,[ecx]
00799B6B mov eax,[edx+4]
00799B6E call eax
```
vtable readout（.rdata VA 0xBD2000, raw offset 0x7D0600）：`0xC4FF8C` 的 +00=`0x007D12E0`、+04=`0x005F5D10`、+08=`0x005F5D10`、+0C=`0x007D1310`（從 T08-109 之 BIN 證據沿用並核對分派路徑）。

```asm
007D1398 mov esi,[0xfb76a8]
007D139E push 0xfb76a8
007D13A7 call 0x79a5f0
007D13C4 mov ebx,[ebp+8]
007D13C7 cmp dword ptr [ebx+0x4004],0
007D13DC mov ecx,[ebx+edx*4+0x2004]
007D13E5 mov edx,[eax+0xc]
007D13EA push esi
007D13EB call edx
007D1405 mov dword ptr [ebx+0x4004],0
```
**已確認** `0x00799B6E` 派送的是 callback 的 +0x04；不能藉此認定 `0x007D1310` 的真正 caller。另一方面，`0x007D1310` 的 bucket base 由 `[EBP+8]` 外部實參取得，不能只因 layout 相同就把它識別為 `[0x00FB7740]`。

## 3. 概念偽碼（部分）
```cpp
Callback* ensureCallback(Handle* h) {
    if (!h->callback_A0) {
        auto *p = (Callback*)alloc(4);
        p->vptr = 0x00C4FF8C;
        h->callback_A0 = p;
    }
    return h->callback_A0;
}
void dispatchKnownRoute(Handle* h) { h->callback_A0->virtual04(); }
void unknownExternalVirtual0C(Callback*, BucketOwner* owner);
```

## 4. 待查/後續
- 尚無 `callback->vtable+0x0C` 的上游派送點與 owner 實參的完整控制流。
- 不能誤稱已找到全域 consumer。
- T08-122 再區分全域22桶配置、寫入與讀取。