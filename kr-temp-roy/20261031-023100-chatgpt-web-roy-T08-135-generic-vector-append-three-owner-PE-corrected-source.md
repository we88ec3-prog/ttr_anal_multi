# T08-135 — Pointer-vector append 真 PE helper、三種 owner 身分及 B 生產者排除（BIN-first 修正版）

- 作者 `chatgpt-web roy`，日期 2026-10-31 Asia/Taipei；KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 舊來源 `kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-135-vector-append-owner-isolation.md`，舊Git blob `b473d309ff90aaf638935c6a55a6d6b84f90b251` 原樣保留。T01 `LEGACY-MAPPING-001` 的舊原稿為 FAILED；本來源係新主張候選，非FULL-PASS。
- 真PE `.text` VA `0x401000`, raw `0x400`；全部下列原始code從 `raw=VA-0x400C00` 讀取並核對；`.rdata`另有專屬mapping。

## 1. 本次獨立由原始BIN重新解碼的helper入口與兩路插入

舊source `0x7BB750` 真PE為 **`0x7BB350`**。`EDI`指向vector `{begin:+0,end:+4,capacity:+8}` 三指標；`EAX`為指向一個待附加DWORD值的地址，不是entry物件本身。

```asm
7BB350 56                   push esi
7BB351 8B F0                mov esi,eax
7BB353 8B 47 04             mov eax,[edi+4]       ; old_end
7BB356 3B F0                cmp esi,eax
7BB358 73 2B                jae 0x7BB385         ; source not before end
7BB35A 8B 0F                mov ecx,[edi]         ; begin
7BB35C 3B CE                cmp ecx,esi
7BB35E 77 25                ja 0x7BB385         ; source before begin
7BB360 2B F1                sub esi,ecx
7BB362 C1 FE 02             sar esi,2            ; index if source aliases vector
7BB365 3B 47 08             cmp eax,[edi+8]      ; end == capacity?
7BB368 75 07                jne 0x7BB371
7BB36A 8B C7                mov eax,edi
7BB36C E8 BF C5 FD FF       call 0x797930       ; capacity growth
7BB371 8B 47 04             mov eax,[edi+4]
7BB374 85 C0                test eax,eax
7BB376 74 24                je 0x7BB39C
7BB378 8B 0F                mov ecx,[edi]        ; refresh begin after grow
7BB37A 8B 14 B1             mov edx,[ecx+esi*4] ; source by recomputed index
7BB37D 89 10                mov [eax],edx
7BB37F 83 47 04 04          add dword [edi+4],4
7BB383 5E                   pop esi
7BB384 C3                   ret
7BB385 3B 47 08             cmp eax,[edi+8]
7BB388 75 07                jne 0x7BB391
7BB38A 8B C7                mov eax,edi
7BB38C E8 9F C5 FD FF       call 0x797930
7BB391 8B 47 04             mov eax,[edi+4]
7BB394 85 C0                test eax,eax
7BB396 74 04                je 0x7BB39C
7BB398 8B 0E                mov ecx,[esi]        ; dereference source slot
7BB39A 89 08                mov [eax],ecx
7BB39C 83 47 04 04          add dword [edi+4],4
7BB3A0 5E                   pop esi
7BB3A1 C3                   ret
```

**新確認／釐清**：若來源slot位於舊vector儲存區內，擴容後舊slot可能失效，因此先以`(source-begin)>>2`保留索引，再從新begin取值；非alias來源直接讀`[esi]`。兩條擴容處原生E8都指 **`0x797930`**，不是舊記號`0x797D30`。`0x797930`可見 `begin/end/capacity`運算與`max_size`檢查 `0x3FFFFFFE`；但本篇不宣稱整個allocator異常路均安全或可呼叫成原始 STL 名。

## 2. 三條已經在BIN確認的相同helper caller，容器分別不同

| 真call site / bytes | 緊貼caller之容器來源 | E8目標 | 分類 |
|---|---|---|---|
| `0x7BB223: E8 28 01 00 00` | `0x7BB21A add edi,0xA4`；`0x7BB220 lea eax,[ebp+0xC]` | `0x7BB350` | owner +A4 A-vector append，不是B |
| `0x7E83FA: E8 51 2F FD FF` | `0x7E83F7 lea edi,[esi+0x20]`; `0x7E83F3 lea eax,[esp+0x14]` | `0x7BB350` | selected record +20 vector，不是B |
| `0x7B92D1: E8 7A 20 00 00` | `0x7B92CB lea edi,[ebx+0x7C]`; `0x7B92CE lea eax,[ebp-0x30]` | `0x7BB350` | group/owner +7C sub-vector，不是B |

分別由原始BIN真 `E8` 位址加五再加signed rel32 計算；例如`0x7B92D1+5+0x207A=0x7BB350`。舊稿三call-site `7BB623/7E87FA/7B96D1` 與舊callee `7BB750` 均是source顯示位址高0x400。此三條不證明本helper其他caller不存在：只說**這三條確定不是**目前已知全域manager的B-vector `+B4` 寫入者。

## 3. 生命週期與負面證據（不能錯判B producer不存在）

- 真 `0x7B8A50` global owner constructor分別初始化 A-vector `+A4/+A8/+AC`、B-vector `+B4/+B8/+BC`；max-selected `+C4` 初始4。`0x7BB240` B consumer讀 B 三指標與C4；末尾只是 `B.end=B.begin` 的**邏輯清空**，不等於free所有payload。
- 真析構 `0x7B8C80 -> 0x7B8CB0` 的 `0x7B8DCF` 讀B.begin、`0x7B8DDA E8 2D 84 0D 00 →0x89120C`釋放B backing allocation，然後 `0x7B8DE2/7B8DE8/7B8DEE` 將B三個指標歸零。這是buffer釋放，**沒有直接逐項payload destructor證據**。
- 如果有人在其他函式以 `lea edi,[manager+0xB4]` 加call本泛用helper，或者先把B-vector別名保存到別的owner，單純搜尋`mov [reg+0xB8]`會漏掉它。因此舊T08-135的排除只能限定三條caller與局部區間，絕不能轉為全域B writer缺席。

## 4. 受影響原稿與下一步

- T08-134：真 `0x7E86E0` → `0x7E8A00` 名稱key查找；135此處record+20 append可能在同一資料系統中，**與B consumer仍不同容器**。
- T08-136/139/140：應引用真 `0x7BB240`、`0x7BB3B0` priority selection以及相關vtable+4/+8；ABI未知的間接呼叫不能因同slot-offset解作同型別。
- 未完成：完整B producer/xrefs、所有alias、B entry真實constructor與vptr、是否寫入22桶、runtime資料、Client packet引入流程。`LEGACY-MAPPING-001` 仍NEEDS_FIX，T01嚴格FULL-PASS尚未執行。

## 5. 玩家情境／Server介面界線

|情境|Client確證資料操作|玩家可見|Server未知|續追查|
|---|---|---|---|---|
|先登記name-key再執行優先項|三類不同vector各有有界append；B有獨立consumer，兩者不可混同|尚無畫面結果證據|何種S2C觸發、22桶因果、原版波次都未證|B producer alias與entry fn4真目標；T02 framing分開|

Client待逆向、Server待開發、跨功能待整合、待遊玩驗證四種狀態均與T01的原生勘誤狀態分離。
