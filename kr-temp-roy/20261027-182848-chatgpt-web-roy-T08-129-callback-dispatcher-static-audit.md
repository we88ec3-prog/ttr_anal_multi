# T08-129 — Callback dispatcher 與 bucket owner 靜態追查（階段性原稿）

時間：20261027-182848 Asia/Taipei。未 Commit / Push。

## 原始來源
- `/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重新計算）。
- PE `.text` VA 0x00401000 對檔案 0x400；下列指令以此映射擷取並使用 GNU objdump x86 反組譯。
- 上輪 T08-128 接棒與 T08 固定規範為背景，非本輪獨立驗證。

## 本輪直接機器碼證據

### 0x00799840 callback 配置與非 dispatcher 路徑
```asm
00799844 cmp dword ptr [esi+0A0h],0
0079984e push 4
00799850 call 00891268
0079985c mov dword ptr [eax],00C4FF8Ch
00799866 mov [esi+0A0h],eax
0079986c mov ebx,[esi+09Ch]
00799872 mov esi,[ebx+4]
00799875 sub esi,[ebx]
00799879 sar esi,2
00799882 mov ecx,[eax+edi*4]
00799885 mov edx,[ecx]
00799887 mov eax,[edx+10h]
0079988a call eax
```
已確認：callback 配置 4 bytes，存 manager+0xA0；同函式迴圈派送**另一集合**的 vtable+0x10，不能混作 callback+0x0C。

### 0x007997A0 與 0x00839940 的建構鏈
```asm
007997c4 push 470h
007997c9 call 00891268
007997df mov ecx,[ebp+8]
007997e4 call 00839940
007997fa mov [esi],eax
0079981c call 00799840
00839986 mov dword ptr [edi],00C53F44h
00839992 mov [edi+0ECh],esi
```
已確認 0x007997A0 配置 0x470 bytes 並呼叫 0x00839940 建構；`0x007997FA` 將結果存入 `[esi]`，接續 0x00799840。此處尚無 callback+0x0C 呼叫或 owner 身分證明。

### 0x007D1310 讀取 owner 的實際機器碼
```asm
007D1398 mov esi,[00FB76A8h]
007D139e push 00FB76A8h
007D13a7 call 0079A5F0
007D13c4 mov ebx,[ebp+8]
007D13c7 cmp dword ptr [ebx+4004h],0
007D13dc mov ecx,[ebx+edx*4+2004h]
007D13e3 mov eax,[ecx]
007D13e5 mov edx,[eax+0Ch]
```
已確認：owner 為 stack argument `[EBP+8]`，不是在此直接從 `[0x00FB7740]` 讀取。`[0x00FB76A8]` 的讀取屬另一流程，不能據此推定 owner。

### vtable 檔案證據
檔案 offset `0x84E58C` 起的 DWORD：
```
0x84E58C: 007D12E0
0x84E590: 005F5D10
0x84E594: 005F5D10
0x84E598: 007D1310
```
以 `.rdata` 映射，`0x84E58C` 對應 VA `0x00C4FF8C`。callback vtable+0x0C = 0x007D1310，直接核實。

## 靜態反查結果與限制
- 在本輪掃描的 `.text` 區間（檔案 offset 0x400 至 0x7D0600）未找到以 `E8 rel32` **直接** call 0x007D1310 的指令候選。這符合虛擬呼叫可能性，但不能證明無其他呼叫途徑。
- 對 0x007D1310 的 little-endian VA `10 13 7D 00` 進行全檔逐 byte 搜尋，僅在 vtable 項目（file 0x84E598）發現一次。這不是所有控制流的完備枚舉。
- **尚未找到 callback vtable+0x0C 的真正 dispatcher，也尚未證明 owner == `[0x00FB7740]`。** 不應宣稱已完成主問題。

## 資料流（目前可證）
`0x007997A0 -> 0x00839940` 建構 0x470 bytes 物件；`0x007997A0 -> 0x00799840` 懶建立 callback，存於 manager+0xA0。callback vptr `0x00C4FF8C` 的 slot +0x0C 指向 `0x007D1310`；該方法的 bucket owner 來自 caller stack argument。缺少 callback 註冊至真正 dispatcher 及 caller push owner 的鏈。

## 暫定偽碼
```cpp
void init_manager(Manager* m, void* parent) {
    auto* core = allocate(0x470);
    construct_00839940(core, parent); // register semantics not established
    m->core = core;
    init_callback_00799840(m);
}
void callback_slot_0C(Callback* self, BucketOwner* owner) {
    // only verified owner extraction; full body covered in earlier T08 notes
    auto* buckets = owner; // from [ebp+8]
    // virtual dispatch on bucket entries; reset counts in later body
}
```

## 後續優先方向
1. 追 manager+0xA0 的全部間接讀取者，以及 `0x00839940` core 對 callback 的註冊入口。
2. 在候選間接呼叫 `call [vptr+0x0C]` 位置，逆推 ECX 與 stack push 的 owner，並比對全域 `[0x00FB7740]` 的指標值。
3. 如靜態鏈不可見，動態斷點於 0x007D1310 記錄 ECX、`[ESP+4]`、return address、`[0x00FB7740]`；此方案**尚未執行**。
4. 本輪僅為階段性結果；不應將 T08-129 標記為 dispatcher 問題已解決。