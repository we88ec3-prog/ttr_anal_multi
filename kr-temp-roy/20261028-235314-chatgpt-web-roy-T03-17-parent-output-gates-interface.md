# T03-17 — KR 0x49197F 父物件 output-slot 來源及上游虛擬介面控制流程（BIN-first）

- 研究者：chatgpt-web roy
- 日期：2026-10-28 Asia/Taipei（本段同日）
- 原件：`Tartaros.bin`，實際重新 `sha256sum` = `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE 格式：x86 PE32；`.text` VA 0x401000 / raw 0x400，VA→raw = VA − 0x400C00。
- 研究依據：原生 `objdump -D -M intel --section=.text`；先前 T03-14～16 原稿及 GitHub T03 `task.json`；不執行、不修改客戶端。
- 初始同步：`main...t03/roy/chatgpt-web` 為 ahead，`behind_by=0`；本段不需額外 Merge。共用 FULL-PASS 目錄目前未提供已提升的正式條目；依 T01 歷史索引保留既存 partial evidence 的限制。

## 摘要／本段新證據

將先前 T03-15／16 的「上游虛擬輸出槽」精確連回其**分支 gate、接收介面來源及後處理**：

1. `0x491808` 呼叫 IAT `0xBD2478`（參數 `0x2C`）；`0x491812` 若 AL==0，**直接跳到 0x49192B**，兩個 `vtable+0x48` 路徑都不執行。該 IAT 的 API 名稱本段未從 import-directory 逐條綁定，不猜。
2. 若 gate 通過，依 `byte[0xFB9225]==1` 分為 `0x491894` 與 `0x4918DB`。兩路均從當前另一資料物件 `[local_source+0x10]` 得到介面指標，並以 **`[interface.vtable+0x48]`** 呼叫，且使用同一規格的輸出槽。這個介面 **不是** `parent+0x140` 的 worker vtable。
3. 第二分支在 `0x49190F` 另外呼叫 `0x6D7840`。此函式在 `0x6D785F` 再透過另外的 `vtable+0x30` 取得中介結果，`0x6D789D` 自有一次 `vtable+0x48`、`0x6D78B6` 間接 IAT 呼叫與 `0x6D78CA` 下游 call `0x6D79B0`。這是另一層物件/介面呼叫，不能把相同 vtable 位移視為同一方法。
4. `0x49197F` 以 `mov edi,[esp+0x20]` 讀取暫存輸出槽，`0x491983` 取 `edi+0x140`，`0x49198A` 呼叫 `0x804740`。此處**沒有額外的空指標檢查**；其前置條件仍需在上游虛擬方法實作確認。不得由該缺口推導必定崩潰，也不得推論 Server 回包型別。
5. 當前未證實父物件的堆積配置、新物件 vtable 安裝或 worker `vtable+0` 的真正 target。此段是上游界面選擇與 gate 的原生功能鏈，不是選角結果 handler。

## 第一輪：分支 gate、來源指標與 output slot

```asm
491808: 6a 2c                  push 0x2c
49180a: ff 15 78 24 bd 00     call dword ptr [0xbd2478]
491810: 84 c0                  test al,al
491812: 0f 84 13 01 00 00     je 0x49192b
491867: 80 3d 25 92 fb 00 01 cmp byte ptr [0xfb9225],1
491892: 75 47                  jne 0x4918db
4918a5: 8b 4c 24 3c           mov ecx,[esp+0x3c]
4918a9: 8b 41 10              mov eax,[ecx+0x10]
4918af: 8d 4c 24 14           lea ecx,[esp+0x14]
4918b3: 51                    push ecx
4918b4: 53                    push ebx
4918b5: 53                    push ebx
4918b6: 89 5c 24 20           mov [esp+0x20],ebx
4918ba: 8b 10                 mov edx,[eax]
4918bc: 8b 52 48              mov edx,[edx+0x48]
4918bf: 53                    push ebx
4918c0: 50                    push eax
4918c1: ff d2                 call edx
4918db: 68 dc 58 c0 00        push 0xc058dc
4918e4: e8 a7 04 f7 ff        call 0x401d90
4918e9: 8b 74 24 3c           mov esi,[esp+0x3c]
4918ed: 8b 46 10              mov eax,[esi+0x10]
4918f3: 8d 54 24 14           lea edx,[esp+0x14]
4918f7: 52                    push edx
4918f8: 53                    push ebx
4918f9: 53                    push ebx
4918fa: 89 5c 24 20           mov [esp+0x20],ebx
4918fe: 8b 08                 mov ecx,[eax]
491900: 53                    push ebx
491901: 50                    push eax
491902: 8b 41 48              mov eax,[ecx+0x48]
491905: ff d0                 call eax
49190f: 51                    push ecx
491910: 8b 4e 10              mov ecx,[esi+0x10]
491913: e8 28 5f 24 00        call 0x6d7840
```

**Stack alias constraint:** `0x4918AF` / `0x4918F3` 計算的 `esp+0x14` 在後續數個 `push` 之後，對應 `0x4918B6` / `0x4918FA` 的 `esp+0x20`；兩個寫入將指標槽設為 EBX（此段以作為零值的 EBX 使用），準備交由介面改寫。必須依各條路徑 ESP 變化分析，不直接將任意兩個同偏移的 `esp` 位址視為同一槽。

## 第二輪：output interface 後的釋放與另一支系

```asm
4918c3: 8b 44 24 14           mov eax,[esp+0x14]
4918d3: ff 15 f4 25 bd 00     call dword ptr [0xbd25f4]
4918d9: eb 40                 jmp 0x49191b
491907: 8b 54 24 14           mov edx,[esp+0x14]
49190b: 8d 4c 24 34           lea ecx,[esp+0x34]
491913: e8 28 5f 24 00        call 0x6d7840
49191b: 8b 44 24 14           mov eax,[esp+0x14]
49191f: 3b c3                 cmp eax,ebx
491921: 74 08                 je 0x49192b
491923: 8b 10                 mov edx,[eax]
491925: 50                    push eax
491926: 8b 42 08              mov eax,[edx+0x8]
491929: ff d0                 call eax
49196e: 8b 0d d4 ac fb 00     mov ecx,[0xfbacd4]
491974: 3b cb                 cmp ecx,ebx
491976: 74 07                 je 0x49197f
491978: 8b 11                 mov edx,[ecx]
49197a: 8b 42 08              mov eax,[edx+8]
49197d: ff d0                 call eax
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
```

`0x49191B` 的 pointer 及 `0x49196E` 的全域 pointer 都透過虛擬 offset+8 後處理，可能是不同 COM/ref-counted objects，但「釋放」的確定語意需要完整 vtable／IAT 名稱；此輪僅聲稱**條件性虛擬 call**。

`0x6D7840` 內部證據：
```asm
6d785f: 8b 06                 mov eax,[esi]
6d7861: 8b 50 30              mov edx,[eax+0x30]
6d786b: ff d2                 call edx
6d7891: 8b 08                 mov ecx,[eax]
6d789d: 8b 41 48              mov eax,[ecx+0x48]
6d78a0: ff d0                 call eax
6d78b6: ff 15 14 26 bd 00     call dword ptr [0xbd2614]
6d78ca: e8 e1 00 00 00        call 0x6d79b0
```
這裡的 `vtable+0x48` 來自 `0x6D788B` 讀出的新 interface，與 `0x4918C1/905` 的來源無直接 identity 證據。

## 第三輪：向父物件建構回溯並排除虛假關聯

`0x48BE50` 繼續顯示為外部父物件 argument：
```asm
48be50: 55                    push ebp
48be90: 8b 5d 08              mov ebx,[ebp+8]
48c0e0: 8d bb 40 01 00 00     lea edi,[ebx+0x140]
48c0e6: e8 65 85 37 00        call 0x804650
```
這不是父物件 `new` 的直接證據。對照接收 worker `0x80486D`：
```asm
804858: 8b 13                 mov edx,[ebx]
80485a: 8b 12                 mov edx,[edx]
80486d: ff d2                 call edx
```
現階段**沒有**證據證明 `0x4918C1/0x491905` 的上游 interface vtable 就是 `0x80486D` 的 worker vtable；也沒有實作目標，不能反推 command 0x42 的 S→C response opcode。此次特別排除將 `0x6D7840` 所使用相同 offset+0x48 直接合併為同一 callback。

## 玩家功能／驗證狀態

| 路徑 | Client 本地 gate | C→S | S→C | UI/world | 等級 |
|---|---|---|---|---|---|
| 選角確認 | 既有 T03-3 的角色+0x5C、FBA798 gates | command 0x42 本地 builder→queue→frame→WSASend 通用機制（T03-3～6，保留每筆是否真正出網限制） | command42 真正 reply opcode、handler 不明 | 選角成功與 T05 轉場未確認 | partial |
| 接收資料處理 | 本輪的 `0x491808` gate、兩路 virtual output、`0x49197F` pointer | 無新 C→S 識別 | `0x804740` 收件 bucket 處理但 callback 未解析 | worker 執行/控制流程已知，遊戲狀態未知 | 原生有界 |
| 渲染/介面呼叫鏈 | 分支依 `0xFB9225` | 不證明選角發包 | `0x6D7840` 多層介面 call | 精確效果未解析 | 原生有界 |

分類：**Client 待逆向**：`parent+0x140` 實際配置及 vtable，`worker vtable+0`，選角業務 S→C handler；**Server 待開發**：在查明原生 Client 格式後實作相容回覆，而不是猜官方後台；**跨功能待整合**：T05 世界進入；**待遊玩驗證**：原版 Client ↔ 相容 Server。

## 停止依據及 T03-18

三輪均進行：1) 上游 gate／來源與 stack alias，2) 另一 branch 的 `0x6D7840` 及下游虛擬回呼，3) 對照 `0x48BE50` parent 初始化與真正 worker callback 反證。正式目標 vtable 仍未找到；本段的新貢獻是**完整、有條件的上游虛擬輸出→worker 呼叫鏈**及排除相同 vtable offset 的假陽性。

T03-18 應針對 `[local_source+0x10]` 的 concrete interface/vtable 建立點及 `0x4918C1/905` 的實際 target 做追查；如果該 interface 是圖形/系統功能，應明確界定並轉回 `parent+0x140` 的 constructor／slot0 來源。避免無證據擴寫 T02/T05 或 Server 原版邏輯。
