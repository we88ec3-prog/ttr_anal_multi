# T01 → S00 — T16-126～133、Quest16 補充與 T16-117 勘誤有界驗收

2026-10-30 Asia/Taipei。T01 整合基準 `main=d7cc4459b72b8f8ecd1027ca3be8707fe8aa5737`；T16 來源工作分支 `t16/roy/chatgpt-web=ad70b74e4c3a5ced9e8fde80741a8694b16a1b5e`（對原 main ahead 12/behind 1）。**僅將 T16 原始 Git blob 精確收件到 main；不對 T16 分支做 main→T16 Merge、也不搬運分支 README 覆寫主線。**

## 驗收判決

**PASS：T01 限定 R0/R1 與所列 R2，可供 S00 做 Client evidence 導航、DRAFT SPEC、GAP/TEST 規劃。**  
**NOT FULL_PASS：**不代表九篇以上完整原稿的所有肯定主張、完整 CFG/virtual alias、原版 Server 協定、Quest15/16 可玩流程、原版回覆因果已驗證；不升 `NATIVE_VERIFIED`、`SPEC_CONSUMABLE`、`SPEC STABLE` 或 RR ACCEPTED。

## 1. 精確 R0 身分與歷史隔離

從分支原樣引用 T16-126、127、128、129、130、131、132、133 八篇，`Quest16-study2-closed-native-recheck` 補充文件（**不是正式 T16-134 段號**），以及 T16-117 逐項勘誤。**10 個 Git blob 原封不動**，在 `research/intake/index.json` 新增 SRC-0483～0492，包含來源 UTF-8 SHA256、Git SHA 與 KR 原件版本；原有 T16-117 歷史 `REFUTED` 判決及原稿均不覆寫。原始 43 個已 RESOLVED 通知不改。

唯讀原件核對：
- KR `Tartaros.bin` 12,472,320 B，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- `Event.stp` 11,241,597 B，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`
- `Table.stp` 5,248,784 B，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`
- PE .text VA0x401000/raw0x400，故 code raw=`VA-0x400C00`；.rdata VA0xBD2000/raw0x7D0600，故 rdata raw=`VA-0x401A00`。

## 2. 本輪獨立 R2 原件複驗及失敗路徑

使用原始 KR BIN、Event STP 逐 byte / SHA256 驗證原稿所列 **40/40 個原生／資源片段**（其中正式 T16-117 erratum 的 8/8、四幕 Lua、編譯 qbase-like chunk 均在內），另外 **14/14 指令起始／vtable anchor** 驗證通過。獨立驗證器取值及每段原始完整 ASM 仍以作者原稿、`revalidate.py` 與本次工作附帶的 `t16_native_audit.json` 為追溯；**雜湊一致只是其限定機器碼證據，不自動賦予原稿全部語意 FULL-PASS**。原始 Lua5.1 chunk 的 75 個 nested function 語意沒有逐項重新解碼驗收。

重要有界 byte/CFG 交叉確認：
- `0x543755`：actor `+0xF6` WORD ID writer；`0x543778`：actor `+0xF4` WORD kind writer；`[0xC0F7FC+0x64] = 0x544070`，kind3 的 F43D9 必須通過額外 world/event gate。
- `0x5B7F93` action dispatcher，`0x5B8460` byte case + `0x5B8394` DWORD jump 表。原始表：`F438A→case0xB→5B7FED`、`F438B→case0xC→5B7FFF`、`F43D9→case0x1E→5B8167`。F43D9 與兩種 TalkBox mode event **不是同一 action**。
- `0x50210B` 寫 `0xFAB4DC=0x503040`，相對 dispatch base `0xFAB2A4`、stride 8，index `0x47`；`0x503095` 從 application `+2,+4` 讀兩個 signed WORD，通過其他條件送本地 controller `0x561760`。不能把人工 `47 00 0F 00 03 00` 視為抓包。
- `0x561F69` 清 controller pending `+0x28`，**早於**較後的 C2S 0x3F gate。失敗不能假設 pending 一直保留等下輪重送。
- `0x47DE40` 是 Table/SceneList 的 CHAPTER/SCENARIO/SCENE 資料結構；`0x5607D0` 是 Event/SceneList 的 (questIdx,sceneIdx)→funcName。兩者不同索引：`0x47E890` FIRST，`0x47E640` NEXT，`0x565720` 在自身 gate 下查 Event map。沒有獨立 Table rows 證明 chapterIdx=Quest15、scene3 在具體清單第幾位。
- Event.stp 四幕本體（XOR FF 原始檔 offsets）：Scene1 `96943E..9696A6`，Scene2 `96883E..968C4F`，Scene3 `8C1C3E..8C2276`，Scene4 `96903E..9691D8`；qbase-like Lua5.1 signature 位於 `A20810`。這些可以證資源存在、靜態字面與部分 callback，但**不能**證 server quest award 或 Pindos Scene3 必然播放。

## 3. T16 各來源可交 S00 的主張（均 PARTIAL）

| 原稿 | 新增 CLM | 正面限定內容 | 未解／不得規範化 |
| --- | --- | --- | --- |
| T16-126 | CLM-QUEST-0013 | NPC kind/id writer、F43D9→type2 giver first-match、獨立 mode2 UI | 物件實際生存與 C2S→S2C 配對 |
| T16-127 | CLM-QUEST-0014 | C2S 1C 取 nested kind/id；controller 3F 及 send/clear gate | 1C不是QuestID、queue不等wire |
| T16-128 | CLM-QUEST-0015 | S2C 46/6F/47 與40/45分開，前置鍵／排除／mode3 UI | 無官方先後/ACK |
| T16-129 | CLM-QUEST-0016 | Event雙鍵 loader、Quest15四幕Lua／Pindos | 四幕不保證在遊玩中依順序執行 |
| T16-130 | CLM-QUEST-0017 | Table vs Event 兩套SceneList；FIRST/NEXT | Table chapterIdx rows 未獨立取得 |
| T16-131 | CLM-QUEST-0018 | S2C47兩WORD→controller與多種本地writer | 15/3 wire fixture不等原版封包 |
| T16-132 | CLM-QUEST-0019 | FIRST/NEXT busy/no-successor/不同GUI gate | RestoreMap不等立即NEXT |
| T16-133 | CLM-QUEST-0020 | 四段 Lua與qbase-like compiled chunk／Q binder | 75 nested prototypes未逐一R3 |
| Quest16補充 | 重用 QUEST-0005/0010 | 不創新 T16 段號；保留 mode2 UI 正確界線 | 舊的 NPC→mode1 推論不能復活 |
| 117勘誤 | 重用 QUEST-0006/0007 | 原泛化肯定主張維持 REFUTED、補精確反證 | 不能把 REFUTED 當正面Server契約 |

## 4. T16-117 唯一尚未結案退回：RESOLVED（有界）

`T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 的作者獨立勘誤 Git blob `1c5efb4a0bfd07c7fbdf2bb1fcc48c4386c4f2ba`，明確逐段更正舊 D.1/D.3/F/G/H 及下游引用。T01 用原始 BIN 重新複驗 8 個 SHA slice **8/8 pass**：
```asm
00636BD6 83 F8 01                 cmp eax,1       ; mode1
00636BFF C7 40 10 02 44 0F 00     mov [eax+0x10],0xF4402
00636DF8 81 7E 10 02 44 0F 00     cmp [esi+0x10],0xF4402
00636E7C 8B 8F 88 00 00 00        mov ecx,[edi+0x88] ; ptr
00636E82 66 8B 11                 mov dx,word [ecx]
0063655D 89 87 80 00 00 00        mov [edi+0x80],eax ; QuestID separate
```
`0x4B3510` 有**另一條獨立 0x36 producer**，不得由 mode1 限定直接推出「mode2 絕無可能由其他路徑送 0x36」。因此此固定退回可由 NEEDS_FIX → RESOLVED，**不能**修改 `CLM-QUEST-0007 REFUTED` 舊判決，也不令 T16-117 原稿全文通過。本批只在 main `kr/tasks/T16/README.md` 的 T01 退回專區更新該項；其他 43 RESOLVED 與原始 T16 文件未更動。

## 5. S00 的下一步與不得越界

- **Client 待逆向**：Table/SceneList 原始 chapterIdx/sceneId 真正 rows；Quest15 progress→Scene3/16 mode2 submit 的業務 producer；上行 1C/3F 和 0x40/46/47 的正負配對/實際 Conn。
- **Server 待開發**：任務接取、前置、失敗、結算、持久化、獎勵政策自行 ADR 決策，不能冒充原版 Server 內部規則。
- **跨 Task 待整合**：T02 framing/socket、T07 場景、T08 NPC、T06 UI、T14 battle、T15 snapshot。
- **待遊玩驗證**：沒有啟動原版 Client、取得原版 Server pcap、模擬真實進村或任務遊玩成功。
- 最新 main RR 台帳**沒有 T16 owner 的研究請求**，故不增/不改 RR；不更動既有 SPEC/GAP/TEST，不以 R2 source SHA 直接升級 S00 ACCEPTED 或 FULL_PASS。

## 保全與查驗

所有新的完整原稿 SHA 已在 `research/intake/index.json`；本批新增 SRC-0483..0492、CLM-QUEST-0013..0020，歷史 refuted、已解決通知保留。主線沒有合併 T16 分支 README 或所有分支歷史，也不改 `kr/tasks/T16/task.json`、owners、catalog 和 `shared/verified-knowledge`。可重跑本批縮減的定位驗證器：[revalidate.py](revalidate.py)；原稿附錄保留大範圍 native assembly 與原始 hash。
