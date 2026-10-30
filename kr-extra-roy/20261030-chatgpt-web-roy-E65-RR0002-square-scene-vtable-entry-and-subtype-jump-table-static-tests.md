# E65 — RR-0002：由 S2C 場景分派閉合到 CSquare 進入方法；subtype 原始跳表重算、合成邊界與選角配對缺口

日期：2026-10-30 Asia/Taipei。研究者 chatgpt-web roy。唯一研究分支 extra/roy1。原件 KR Tartaros.bin（12,472,320 bytes）SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。唯讀 BIN-first，沒有執行 Client 或原版 Server，也沒有原版 Server 成功登入／選角封包擷取。

**交付等級：native bounded Client static evidence（可審查增量）。RR-0002 正式狀態仍 IN_PROGRESS；不能宣告完整 selection request → original Server reply → Client scene 的因果鏈已驗收。** 前段研究 E61/E62/E63/E64 在同一分支原樣保存，勿重複提昇證據等級。

## 1. 本輪增量：CSquare 真正 scene-entry 的 indirect call 已閉合

0x4B7DC0 所安裝的全域 first-level app S2C command table，使：

- app command 0x0060 → handler 0x4B8F50 → ctor 0x4C13E0 → native RTTI CExpedition@Scene@@ vptr 0xC07280 → scene manager 0x4B7D50。
- app command 0x0069 → handler 0x4B9090；合法 subtype 7/23/24 建造 native RTTI CSquare@Scene@@ vptr 0xC06FB0 → scene manager 0x4B7D50。subtype21 為 native CDuelSquare vptr 0xC06F7C，另一路；不可混稱 Square。
- app command 0x005F → handler 0x4B99C0；其 subtype 6 可建 native CDuelField@Scene@@ vptr 0xC0710C。

**新驗證：**從原始 .rdata vtable bytes 以 PE VA→raw 0x401A00 讀取，CSquare vptr 0xC06FB0 的前7個 DWORD 依序為：
0x4C5940, 0x4C4670, 0x422810, 0x4227F0, **0x4BBC10**, 0x4BBF10, 0x4BBF80。
CExpedition vptr 0xC07280 的前7個 DWORD 為：
0x4C1530, 0x4C4670, 0x422810, 0x4227F0, **0x4C15C0**, 0x8DC2F0, 0x4C1930。
CDuelSquare vptr 0xC06F7C 的 slot+0x10 則是 0x4BB540。

0x4B7D50 原始 BIN x86 指令證明「替換場景 → 啟動新場景」，非只寫類別名：

    4b7d50 push ecx
    4b7d51 test edi,edi
    4b7d53 jne 4b7d5f
    4b7d55 push 0xc06dcc
    4b7d5a call 0x6edc70            ; log, 不作安全返回
    4b7d5f mov ecx,[esi+0x5eac]     ; existing scene
    4b7d65 test ecx,ecx
    4b7d67 je 4b7d8c
    4b7d69 mov eax,[ecx]
    4b7d6b mov edx,[eax+0x14]
    4b7d6e call edx                 ; previous scene vtbl+0x14
    4b7d70 mov ecx,[esi+0x5eac]
    4b7d76 test ecx,ecx
    4b7d78 je 4b7d8c
    4b7d7a mov eax,[ecx]
    4b7d7c mov edx,[eax]
    4b7d7e push 1
    4b7d80 call edx                 ; previous scene vtbl+0
    4b7d82 mov [esi+0x5eac],0
    4b7da7 mov [esi+0x5eac],edi     ; install new
    4b7dad call 0x6edd00            ; trace/log
    4b7db2 mov eax,[edi]
    4b7db4 mov edx,[eax+0x10]
    4b7dba mov ecx,edi
    4b7dbc call edx                 ; new scene vtbl+0x10
    4b7dbf ret

因此 S2C 0x69/7 在分配與初始化成功且不觸發資源/初始化異常的條件下，會走 CScene manager→CSquare::virtual+0x10，即具體 0x4BBC10。S2C 0x60 同一 manager 走 Expedition virtual+0x10 = 0x4C15C0。這是新的 Client 可用相容性驗證切點。

**額外風險：**在 0x4B7D50 中 EDI 為 NULL 時先 log 卻無直接 return，之後仍於 0x4B7DB2 解參照 EDI。不能宣稱 OOM/NULL 路徑會安全忽略；亦不能只因內部 alloc 成功就認為 Client 能完成場景建立。

## 2. 原件跳表重算：0x69 與 0x5F 的 subtype 必須分開

本輪不是採用偽碼 switch 列表，而是直接從原始 BIN 的 .text VA/raw=0x400C00 提取兩組跳表 bytes，重算所有 18/27 項分派，包含 error entries。

S2C 0x69：0x4B90C1 的 movsx ecx,BYTE [payload+2]；0x4B90C5 計算 subtype−7；0x4B90C8 檢查 unsigned <= 0x11。index array at 0x4B924C，原始 18 bytes：

    00 04 04 04 04 04 04 04 04 04 04 04 04 04 01 04 02 03

jump pointers at 0x4B9238（20 bytes）：

    DF 90 4B 00 16 91 4B 00 5B 91 4B 00 8F 91 4B 00 2C 92 4B 00

index0→0x4B90DF (subtype7→CSquare), index1→0x4B9116 (21→CDuelSquare), index2→0x4B915B (23→CSquare), index3→0x4B918F (24→CSquare), index4→0x4B922C（error/log）。subtype8..20、22 均映射 index4。其它 signed bytes 出界也去 0x4B922C。

S2C 0x5F：0x4B9A26 讀 unsigned [payload+2]，0x4B9A3B 減 2，0x4B9A3E 檢查 unsigned <= 0x1A。0x4B9B74 的 27 bytes：

    00 07 01 07 02 07 07 03 07 07 07 07 07 07 07 07 07 07 07 07 07 07 07 04 05 07 06

jump pointers at 0x4B9B54（**8** DWORD，包含 index7 的 default，不是只有7 DWORD）：

    0x4B9A55 0x4B9A76 0x4B9A95 0x4B9ACC 0x4B9AE4 0x4B9AFE 0x4B9B18 0x4B9B3B

非 default subtypes：2,4,6,9,25,26,28；其中 6→0x4B9A95→CDuelField。E64/較早摘要只列7個有效 handler 而未明說 index7 第8個 fallback entry；本段補齊，防止未來解析器把跳表長度寫錯。

## 3. 合成靜態測試向量（不是原版 Server 封包，也沒有執行 Client）

使用獨立 Python3 對原始 BIN byte ranges 直接讀取，重新解讀 little-endian table values，將 each subtype 映射到組合語言 jump target，逐項 0x69 18 種／0x5F 27 種，結果與上表一致。簡化可重現程序：

    raw = open('Tartaros.bin','rb').read()
    read = lambda va,n: raw[va-0x400c00:va-0x400c00+n]
    import struct
    map69 = read(0x4b924c,18)
    jmp69 = struct.unpack('<5I',read(0x4b9238,20))
    assert [s for s in range(7,25) if jmp69[map69[s-7]] != 0x4b922c] == [7,21,23,24]
    map5f = read(0x4b9b74,27)
    jmp5f = struct.unpack('<8I',read(0x4b9b54,32))
    assert [s for s in range(2,29) if jmp5f[map5f[s-2]] != 0x4b9b3b] == [2,4,6,9,25,26,28]

此測試只重算分派表，**沒有測試 WSASend、Server reply、Client runtime 或資源有效性**。0x4B9090 讀 payload+2/+3/+4 但未在函式本體逐項驗證其整體 length；由 T02 app queue 的資料長度及上層協定提供有效物件為前提，不能將 5-byte 隨機合成 payload 宣稱可進廣場。

## 4. 針對 RR-0002 的真正缺口與反證

先前 E61/E62/E63/E64、這一 E65 已完整交付以下 **Client 局部原生**：

- C2S request app payload 42 00 XX YY，0x4A3B80，len4，FBA798==0 才交 send queue；三個上層 UI caller 有不同的驗證條件，不能把 XX 當全域永久角色 ID。
- S2C command2 roster 65-byte prefix + 每筆 53-byte，4D4150 在合法 ID/記錄前提下設 record+0x5C。
- S2C 0x42 的 0x4B2190 操作 FAB2A0 ID table；0x47D610 ScenarioReview UI 讀該表，不能從同數字直接解讀為選角成功。S2C 0x43 的 0x4B1A90 移除特定 type6 物件，也不能靠 +1 猜配對。
- S2C0x60 建造 Expedition 並 local enqueue C2S F5；S2C0x69/7 確定經 0x4B7D50 切換到 CSquare::entry 0x4BBC10；S2C0x5F/6 是 DuelField。
- 0x47B5C0→0x565720 的場景雙鍵來源已由 RTTI 證明為 ScenarioReview 類別，沒有首次選角教學的正向連結。
- **仍無 native 正向證據**：哪一筆原版 Server S2C 實際是「對 C2S42 的成功/失敗回覆」、其欄位／到達順序、selected XX/YY 到 CSquare 登入玩家物件之鏈，以及是否先 0x60 後 0x69。上面每條單獨 Scene handler 有原生依據，但不能直接畫 C2S42→S2C69/7 的因果邊。

**研究目標判定**：在已取得的 Client 原生資料下，可以產出完整、有界、可重現的 Client 分派與場景切換契約，但無法單憑 static Client 逆推出原版 Server 真實 request/reply pairing 和角色授權策略。研究者不會虛構其值，也不會擅自修改 RR 的 acceptance_criteria。

## 5. 建議的解除阻塞與可操作測試

A. 原版 Server (或可信的原版 wire capture) 若可取得：需要 C2S 42 前後所有 key0/key1/key2 app packets，包含外框、確切 transport/Conn、選角 XX/YY、S2C success/error marker、角色身份及其實際順序、UI/scene trace。這是證明「original reply」的最短正向依據；目前無此證據。

B. 若僅能使用原版 KR Client 和自製相容 Server：以官方以外的**合成** 0x69 subtype7／0x60 和錯誤 subtype22、0x5F subtype6，分別在有效初始化/資源前提下測試 0x4B7D50、0x4BBC10、0x4C15C0、FBA798 send queue，並確認場景進入是否需要已選角色 ID；必須清楚記錄它只證相容性、不是官方 packet。這類 runtime 測試此處未執行。

C. 若 S00 決定此 RR 可用「Client static bounded compatibility contract」作為交付完成條件，S00 應明確定義有界 acceptance/新 RR 拆分 original Server wire unknown；研究者本輪不自行降低標準。保留 T02 framing/connection、T04 權威初值、T05 scene/quest、T06 UI 資源的分工。

**最終：RR-0002 仍 ACTIVE/IN_PROGRESS；本稿是新增可審查證據，不是聲稱完整 RR-0002 已完成，也不是 T01 FULL-PASS／S00 ACCEPTED。**

## 來源與原件追溯

- E61 Git blob fc1d4845b3e1647a963e07b0838e05108e4218ca（C2S42、roster）
- E62 Git blob 88ebd073cc14f2dee47d712ce9086346b8f62ace（S2C42/43 與反證）
- E63 Git blob 3232b05dbc0d3878aeae206bc84f5726bf2b93bf（930行 raw assembly、SceneReview RTTI）
- E64 Git blob 715636b667f47e42a31d50590ffd39d75e93f4b7（Expedition/Square RTTI + E63 完整 assembly 附錄）
- E65 本篇的新 jump-table 機器位元組與 vtbl+0x10 原生閉合。
