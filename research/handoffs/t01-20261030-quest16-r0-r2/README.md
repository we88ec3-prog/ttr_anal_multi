# T01 — Quest16 R0/R1/R2 原生驗收與正式有限整合（2026-10-30）

本次 GitHub main 基準：`c973e9223527d28f65762cc8458e12da9f9ebe39`。KR BIN 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE .text VA 0x401000/raw0x400，.rdata VA 0xBD2000/raw 0x7D0600。研究者 T01 / chatgpt-web roy。來源只從 t16/roy/chatgpt-web 以原樣 Git blobs 匯入，不合併整分支，不改原稿。原生 BIN 僅離線唯讀。

## 精確來源與收件狀態

| 來源 | SRC | Git blob SHA | 文件路徑 |
|---|---|---|---|
| T16-117 | SRC-0457 | `388b9100362ed43ec65ba1f7504f73518dce5d44` | `kr-temp-roy/20261030-034517-chatgpt-web-roy-T16-117-KR-Quest14-study5-Quest16-type2-unlock-UI-C2S-S2C.md` |
| T16-121 | SRC-0458 | `e5d48e09ac8604ac39ce0dc584bb20308d927b54` | `kr-temp-roy/20261030-094522-chatgpt-web-roy-T16-121-KR-Quest16-study2-closed-NPC-event-S2C-0040-F438B-mode2-TalkBox.md` |
| T16-122 | SRC-0459 | `d056bb2d0ff4ee136e13f2ff8c034434a61b2d87` | `kr-temp-roy/20261030-100618-chatgpt-web-roy-T16-122-KR-Quest16-study3-NPC-C2S-001C-003F-0036-mode2-and-sender-queue.md` |
| T16-123 | SRC-0460 | `0df4598be826c4b6fea0627278b77b3026ecd52e` | `kr-temp-roy/20261030-101735-chatgpt-web-roy-T16-123-KR-Quest16-study4-S2C-0040-0064-0065-0072-0074-state-UI-native.md` |

本批四份來源均完成 R0 身分核對和 R1 有界主張／衝突查對，integration_status=CONFLICT_CHECKED，**不代表 R3 原稿全文通過**。其中 T16-117 為帶有舊版錯誤主張的歷史原稿，T16-121/122 提供新的限定更正，T16-123 提供其他入站狀態效果。全部來源 SHA256 逐項存於 research/intake/index.json，原始 blob 不重寫。

## 新增六項限定主張（全庫已按主題區分）

| ID | Evidence | 原生有限結論 | 不可擴大推論 |
|---|---|---|---|
| CLM-QUEST-0002 | PARTIAL | S2C application 0x40 state0 事件、排除及候選；state1 文字通知 | 不保證官方 ACK/可玩 |
| CLM-QUEST-0003 | PARTIAL | 0x74 增加 prereq WORD，0x72 重置有效 vector | Server 全量快照順序未知 |
| CLM-QUEST-0004 | PARTIAL | 0x64 單筆及 0x65 二十筆 exclusion 清除 | 不是完成任務的 Server 內部結論 |
| CLM-QUEST-0005 | PARTIAL | 本地事件 F438A/F438B 分別走不同 action | 不等於 wire opcode |
| CLM-QUEST-0006 | PARTIAL | F4402/0x636E10 producer 讀 `WORD*([TalkBox+0x88])` 作 0x36 的欄位 | 不證明就是 QID16，亦不能套 mode2 |
| CLM-QUEST-0007 | REFUTED | T16-117 mode1..3 都走 F4402→0x36(QID16) 的舊泛化主張 | 不表示 mode2 任何可能路徑都不能送 0x36 |

## 第一手 R2：機器碼區間與有界分派

T16-123 原生 x86 機器碼原始切片 9/9 全部獨立 SHA256 匹配，共 2,797 bytes；這僅證原始片段一致並支持下面經追查的限定控制流，不代表全文所有 CFG、caller 或業務結論通過。

| Slice | VA [start,end) | bytes | 實際 SHA256（PASS） |
|---|---|---:|---|
| S01 | `0x5020B0..0x50216C` | 188 | `80ab1089ef84293bcc16cf7607a597f9e9a3063d071e5a1e0645290f0634317b` |
| S02 | `0x502270..0x50244C` | 476 | `cf1fef9f4b650486cd74640a2608503d77d2ca4ff87f25fe4f2e8cfb33b6865a` |
| S03 | `0x50244C..0x5026CA` | 638 | `ca01f109a7f7fb43b867d2d119e9e836525781e6ba17cbf77f69cfc3fe53fe65` |
| S04 | `0x5026CA..0x5027CC` | 258 | `c69ece0370a485f1de335936ac7c17ec185cc0c05dc59bcc825e558734615976` |
| S05 | `0x5030C0..0x5031F4` | 308 | `9d1a61e5088ffd31e6a59a2318d541e024447029ff2b14573f5530c0a3b45c8f` |
| S06 | `0x5031F4..0x5033A7` | 435 | `95f9629cb184da708e309e8ca0cce45f411a46e439ad52b72811434fae91a85b` |
| S07 | `0x5033B0..0x503430` | 128 | `39097103f591ef595c9c70f845faa9275a57a7551f59a2e08a41205479e5db46` |
| S08 | `0x44B4E0..0x44B535` | 85 | `b5a2fe407e5e314cd5f15ae066a851f4071f45aefee716bd4f208d01a73bf8db` |
| S09 | `0x5035D0..0x5036E9` | 281 | `0f8c8f5253271de5ba67b801e4320037c9b9d6528d2850bc80cf7ceb1c8169e5` |

Client application handler table `0xFAB2A4` 每槽 8 bytes；原生註冊 writers `0x5020CF/0x5020EB/0x50211B/0x50212B/0x50213B/0x50214B/0x50215B` 分別對應 0x40→0x502270、0x45→0x5027D0、0x64→0x5030C0、0x65→0x5035D0、0x6F→0x502170、0x72→0x5033B0、0x74→0x503400。這是 business handler 索引，不構成整個 TCP frame 或原版 Server 發送政策。

local event action jump table：F438A→case0B→0x5B7FED，F438B→case0C→0x5B7FFF，F43D9→case1E→0x5B8167。`0x5022A1` 讀 pkt+4 state、`0x502355` 讀 WORD pkt+2、`0x502362/36F` 寫 F438B/QID 至 event、`0x502377` enqueue；要等另外的 event dispatch/資源/配置條件才可能顯示 UI。`0x503400` 將 WORD+2 append 到 QuestOwner+5EB0 vector 再 `0x500240` 重算；`0x5033B0` 重設有效 end；`0x64/0x65` 操作不同的 +5ED0 二十格 exclusion。

## T16-117 舊版 mode2→0x36 過度推論的定向反證

```asm
00636BBE 8B 87 90 00 00 00       mov eax,[edi+0x90]     ; TalkBox mode
00636BD6 83 F8 01                cmp eax,1              ; mode1 gate
00636BD9 0F 85 A5 00 00 00       jne 00636C84
00636BFF C7 40 10 02 44 0F 00    mov dword [eax+0x10],0xF4402
00636DF8 81 7E 10 02 44 0F 00    cmp dword [esi+0x10],0xF4402
00636E01 E8 0A 00 00 00          call 00636E10
00636E7C 8B 8F 88 00 00 00       mov ecx,[edi+0x88]     ; QuestTalk record
00636E82 66 8B 11                mov dx,word [ecx]      ; not stored QID+0x80
00636E85 B8 36 00 00 00          mov eax,0x36
00636E8A 66 89 45 FC             mov word [ebp-4],ax
00636E8E 66 89 55 FE             mov word [ebp-2],dx
0063655D 89 87 80 00 00 00       mov [edi+0x80],eax     ; QID stored separately
```

上述反證只否定「mode1..3 都由同一 F4402 直接發 0x36,QID16」的**一般性因果證明**。另存在 `0x4B3510` 分支的獨立 0x36 producer，不能反過來認定 mode2 絕對沒有任何 0x36 連線途徑。T16-122 已提出較精確說法，但尚非正式針對117的作者勘誤。

## 正式退回與未完成界線

新建 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` = NEEDS_FIX。T16 作者保留原 117，提交逐項列出 D.1/D.3 修正的新 erratum/blob 及下游引用查核，更新 READY_FOR_REVIEW；T01 確實複驗後才 RESOLVED。已結案的43筆 T16 舊退回不重新開啟。

Client 待逆向：mode2 真正 submit producer、Inbound framing 最小安全長度、Quest16 接受/完成 S2C 正負配對、實際 UI 與 NPC 入口；Server 待開發：任務保存、解鎖、成功/拒絕和獎勵策略，不能假裝還原原版演算法；跨功能待整合 T02/T06/T07/T14/T15/T16；待遊玩驗證：原始 Client 與 Server 連線/任務流程。無 FULL-PASS/NATIVE_VERIFIED/SPEC_CONSUMABLE/S00 RR 或 SPEC 升格；318篇舊全文審核、T10尚未整合127篇皆不變。

