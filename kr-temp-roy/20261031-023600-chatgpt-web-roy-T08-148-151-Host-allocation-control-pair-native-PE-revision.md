# T08-148～151 — Host 0x170 分配、0x10 控制區塊、兩階段引用釋放：真PE ABI與函式目標修訂

研究者 `chatgpt-web roy`；2026-10-31 Asia/Taipei。KR `Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。僅唯讀原件；PE `.text` VA0x401000 raw0x400，`raw=VA−0x400C00`；`.rdata` VA0xBD2000 raw0x7D0600。本文逐項由原生bytes核對入口與direct E8目的地；不把舊報所有地址一律減0x400。

歷史來源保留不變及原T01 FAILED：
- T08-148 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-148-priority-entry-dynamic-identification-plan.md` blob `731256d9263379c95a6a4c608b5ac22d727df14f`（探索計畫，並非所有語義已完成）。
- T08-149 `kr-temp-roy/20261027-222934-chatgpt-web-roy-T08-149-ctor-callers-and-b-entry-vtable-abi.md` blob `7743ed6e56742780d400627bfbbffae316defec8`。
- T08-150 `kr-temp-roy/20261027-223858-chatgpt-web-roy-T08-150-shared-control-block-construction-and-owner-transfer.md` blob `8d2d45fa3eb94840ff4ae6b459ea38b04c254f50`。
- T08-151 `kr-temp-roy/20261027-224426-chatgpt-web-roy-T08-151-control-block-two-stage-release-and-host-dispatch-boundaries.md` blob `d16ed4d133e88986f1f5867d287b2f44934f89a9`。

## 1. 三條真正PE的0x170 Host分配與構建（T08-149 原錯位）

舊版引用 `0x4C825D/0x4C850F/0x6DC3EA` 均有source原始碼座標高0x400；真PE的三個direct E8 caller為 `0x4C7E5D,0x4C810F,0x6DBFEA`，其真目標都為 **0x7A4C50**（非舊記號0x7A5050），每條前置配置0x170 bytes：

```asm
4C7E3F: 68 70 01 00 00        push 0x170
4C7E44: E8 1F 94 3C 00        call 0x891268
4C7E58: 0F B7 CE              movzx ecx,si
4C7E5B: 51                    push ecx
4C7E5C: 50                    push eax
4C7E5D: E8 EE CD 2D 00        call 0x7A4C50
4C7E7B: E8 E0 25 00 00        call 0x4CA460  ; shared control creator

4C80EF: 68 70 01 00 00        push 0x170
4C80F4: E8 6F 91 3C 00        call 0x891268
4C810F: E8 3C CB 2D 00        call 0x7A4C50
6DBFCD: 68 70 01 00 00        push 0x170
6DBFD2: E8 91 52 1B 00        call 0x891268
6DBFEA: E8 61 8C 0C 00        call 0x7A4C50
```

這證明三處可達的**本地分配/建構配對**；但不證明所有Host只從這三處產生、分配結果恆非null、哪個高階玩家事件或哪一幀會把該Host放入B。

## 2. 真控制區塊建立 0x4CA460（非舊0x4CA860）

```asm
4CA460: 55 8B EC             push ebp;mov ebp,esp
4CA489: 8B 5D 0C           mov ebx,[ebp+0xC]
4CA48E: 6A 10              push 0x10
4CA493: E8 D0 6D 3C 00     call 0x891268
4CA4A4: 89 48 04           mov [eax+4],ecx
4CA4A7: 89 48 08           mov [eax+8],ecx
4CA4AA: C7 00 0C 76 C0 00 mov [eax],0xC0760C
4CA4B5: 8B 75 08           mov esi,[ebp+8]
4CA4BA: E8 01 8D 2D 00     call 0x7A31C0   ; pointer-pair transfer helper
4CA4C7: 8D 47 08           lea eax,[edi+8]   ; secondary reference count
4CA4CF: F0 0F C1 08        lock xadd [eax],ecx
4CA4D3: 8B 4B 14           mov ecx,[ebx+0x14]
4CA4DA: 8D 51 08           lea edx,[ecx+8]
4CA4E0: F0 0F C1 02        lock xadd [edx],eax
4CA4ED: 89 7B 14           mov [ebx+0x14],edi
4CA4F0: 89 5B 10           mov [ebx+0x10],ebx
```

原始 `.rdata` vtable `0xC0760C`（raw `0x805C0C`）首4個DWORD是 `0x4CA660,0x7A3920,0x7A3950,0x7848C0`。前兩slot在**真正PE**位址均為合法短函式入口：

```asm
4CA660: 8B 49 0C   mov ecx,[ecx+0x0C]
4CA663: 85 C9      test ecx,ecx
4CA665: 74 08      je 0x4CA66F
4CA667: 8B 01      mov eax,[ecx]
4CA669: 8B 10      mov edx,[eax]
4CA66B: 6A 01      push 1
4CA66D: FF D2      call edx
4CA66F: C3         ret

7A3920: 85 C9      test ecx,ecx
7A3922: 74 09      je 0x7A392D
7A3924: 8B 01      mov eax,[ecx]
7A3926: 8B 50 08   mov edx,[eax+8]
7A3929: 6A 01      push 1
7A392B: FF D2      call edx
7A392D: C3         ret
```

舊T08-151的「此vtable指入指令中段，析構ABI疑點」在真PE下至少上述兩slot **被反證**：它們都是已成立的有效PE指令入口（使用 this=ECX），而不是必須重定位的錯指針。當然 **slot+0與+4屬不同呼叫**：前者對control+0xC所指Host對象vtable+0，後者對control+?指標再叫其+8；精確執行上下文需傳參追查，不能直接把兩個都命名為同一種free。

## 3. 真pair持有者替換及兩階段引用計數（T08-150/151）

舊source `0x4E1360` 真PE為 **`0x4E0F60`**：

```asm
4E0F60: 55 8B EC             push ebp;mov ebp,esp
4E0F6E: 3B F0               cmp esi,eax
4E0F72: 8B 48 04            mov ecx,[eax+4]
4E0F75: 89 50 04            mov [eax+4],edx
4E0F78: 8B 10               mov edx,[eax]
4E0F7A: C7 00 00 00 00 00   mov dword [eax],0
4E0F80: 8B 77 04            mov esi,[edi+4]  ; old control
4E0F83: 89 4F 04            mov [edi+4],ecx  ; new control
4E0F86: 89 17               mov [edi],edx    ; new Host pointer
4E0F88: 85 F6               test esi,esi
4E0F8C: 8D 46 04            lea eax,[esi+4] ; old strong count
4E0F92: F0 0F C1 08         lock xadd [eax],ecx
4E0F96: 75 1D               jne 0x4E0FB5   ; nonzero old count
4E0F9E: FF D0               call eax        ; old control slot0
4E0FA0: 8D 4E 08            lea ecx,[esi+8] ; old weak/control count
4E0FA6: F0 0F C1 11         lock xadd [ecx],edx
4E0FAA: 75 09               jne 0x4E0FB5
4E0FB3: FF D2               call edx        ; old control slot1
```

由第一手BIN精確可見：在old control非null且strong count原值為1的路徑，先進slot0清理，再減weak/control count，weak原值為1時才進slot1。**不是**每次pair替換必定釋放Host或control；也不能把控制塊 `+0x04/+0x08` 混作B vector `+0xB4/+B8`。原T08-150所稱另一pair helper `0x7A35C0` 真為 **`0x7A31C0`**，native也有 `7A31D5 lock xadd [edi+4]`、`7A31E9 lock xadd [edi+8]` 以及兩個條件虛擬呼叫，是對照路徑但需保留caller差異。

## 4. 生命週期與B producer的尚缺owner關聯

T08-145～147新稿已證Host constructor真 `0x7A4C50`寫 `Host+0xC` = `0xC4F6C0`，Host析構真 `0x7A5651`恢復initial `0xC4F66C`；producer真 `0x7A63C0`在正常條件下將 `Host+0xC` 入B vector。**沒有**因3個Host allocation + 控制對本身就證明每一個特定Host都必然呼叫producer、在被B消費之前未析構，或B consumer的slot+4執行當下一定vptr C4F6C0。

早期T08-149稱「全BIN沒有 `0x7A67C0` direct E8」在 **地址已查明錯誤**後必須重做真`0x7A63C0`的直接/間接xref，不能將舊negative scan提升為「producer不可達」。T08-148還是一份**當時探索計畫**；原先擔心B-entry具體vtable未識別的未知，部分可由新原生 `C4F6C0 +0x04 = 0x7A8310`、`+0x08=0x7A8E10`解析，但仍不能當作已驗所有runtime多型狀態。

## 5. 待修T01條件與Server分工

|對象|已證Client|尚需Client|Server/S00界線|
|---|---|---|---|
|Host配置與control|三個0x170 allocation→7A4C50，0x10 control→pair移交，兩階段原子count條件釋放|具體owner引用網絡、同key重用、跨場景Host析構與B借用安全|不能由持有者/引用計數猜原版Server生成政策|
|B entry|Host+0xC vptr C4F6C0，fn4記錄登記及fn8距離平方（在正常vptr條件下）|所有producer caller、動態生命週期、接到全域22桶的真正函式鏈|Client待逆向、Server待開發、跨T02協定、待遊玩驗證分別管理|

T01 `LEGACY-MAPPING-001` **仍NEEDS_FIX**：本篇對148～151提供有限原生PE source修訂和錯位目標更正，但不是4篇各自全文FULL-PASS，也未證網路封包或全部間接CFG。
