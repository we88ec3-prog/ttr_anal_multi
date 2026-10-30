# T08-136 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：B consumer／selection後的logical clear

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-136-priority-queue-consumer-reset-boundary.md`，Git blob `31bb246001362c2e15f4d94defdbd116add31204`、SHA256 `409a919a0b47243becca3f79e13b9d814c19a3bd730f8b3e38d56f4c323d307f`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：168 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

真0x7BB240接B-vector consumer；以0x7BB3B0條件排序，逐項per-entry多型virtual指令可計score/執行；B queue結尾的end reset是**logical clear**，不是釋放所有buffer、entry或Host。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md](../../20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：必要的選中entry實際類型、例外處理、B與全域bucket因果仍未全域驗證。

## T01原始證據逐行映射：168／168 bytes相符

此為來源 code-row 的座標/byte修正表。E8/E9計算目標由**新VA + instructionLength + signed rel32**重算；其他分支/間接call target不能只看文本自動推論，另依根函式CFG定位。不將表值vtable與原始immediate整體重定位。

|舊標籤VA（FAILED）|正確VA（T01映射）|Tartaros.bin原始code bytes|由E8/E9真VA重算的直接目標|
|---|---|---|---|
|0x7bb664|0x7bb264|`8b 86 b8 00 00 00`|—|
|0x7bb66a|0x7bb26a|`2b 86 b4 00 00 00`|—|
|0x7bb670|0x7bb270|`8b 9e c4 00 00 00`|—|
|0x7bb676|0x7bb276|`c1 f8 02`|—|
|0x7bb679|0x7bb279|`3b d8`|—|
|0x7bb67b|0x7bb27b|`76 02`|—|
|0x7bb67d|0x7bb27d|`8b d8`|—|
|0x7bb67f|0x7bb27f|`f6 05 e8 79 fb 00 01`|—|
|0x7bb670|0x7bb270|`8b 9e c4 00 00 00`|—|
|0x7bb676|0x7bb276|`c1 f8 02`|—|
|0x7bb679|0x7bb279|`3b d8`|—|
|0x7bb67b|0x7bb27b|`76 02`|—|
|0x7bb67d|0x7bb27d|`8b d8`|—|
|0x7bb67f|0x7bb27f|`f6 05 e8 79 fb 00 01`|—|
|0x7bb686|0x7bb286|`75 27`|—|
|0x7bb688|0x7bb288|`83 0d e8 79 fb 00 01`|—|
|0x7bb679|0x7bb279|`3b d8`|—|
|0x7bb67b|0x7bb27b|`76 02`|—|
|0x7bb67d|0x7bb27d|`8b d8`|—|
|0x7bb67f|0x7bb27f|`f6 05 e8 79 fb 00 01`|—|
|0x7bb686|0x7bb286|`75 27`|—|
|0x7bb688|0x7bb288|`83 0d e8 79 fb 00 01`|—|
|0x7bb68f|0x7bb28f|`c7 45 fc 00 00 00 00`|—|
|0x7bb696|0x7bb296|`e8 45 db fd ff`|0x798DE0|
|0x7bb6af|0x7bb2af|`a1 e8 76 fb 00`|—|
|0x7bb6b4|0x7bb2b4|`8b 78 0c`|—|
|0x7bb6b7|0x7bb2b7|`8b 96 b4 00 00 00`|—|
|0x7bb6bd|0x7bb2bd|`83 ec 0c`|—|
|0x7bb6c0|0x7bb2c0|`8b cc`|—|
|0x7bb6c2|0x7bb2c2|`89 39`|—|
|0x7bb6c4|0x7bb2c4|`8b 78 10`|—|
|0x7bb6c7|0x7bb2c7|`8b 40 14`|—|
|0x7bb6d0|0x7bb2d0|`8b 86 b8 00 00 00`|—|
|0x7bb6d6|0x7bb2d6|`50`|—|
|0x7bb6d7|0x7bb2d7|`8d 04 9a`|—|
|0x7bb6da|0x7bb2da|`50`|—|
|0x7bb6db|0x7bb2db|`52`|—|
|0x7bb6dc|0x7bb2dc|`e8 cf 00 00 00`|0x7BB3B0|
|0x7bb6e1|0x7bb2e1|`83 c4 18`|—|
|0x7bb6e4|0x7bb2e4|`33 ff`|—|
|0x7bb6d7|0x7bb2d7|`8d 04 9a`|—|
|0x7bb6da|0x7bb2da|`50`|—|
|0x7bb6db|0x7bb2db|`52`|—|
|0x7bb6dc|0x7bb2dc|`e8 cf 00 00 00`|0x7BB3B0|
|0x7bb6e1|0x7bb2e1|`83 c4 18`|—|
|0x7bb6e4|0x7bb2e4|`33 ff`|—|
|0x7bb6e6|0x7bb2e6|`85 db`|—|
|0x7bb6e8|0x7bb2e8|`74 1b`|—|
|0x7bb6dc|0x7bb2dc|`e8 cf 00 00 00`|0x7BB3B0|
|0x7bb6e1|0x7bb2e1|`83 c4 18`|—|
|0x7bb6e4|0x7bb2e4|`33 ff`|—|
|0x7bb6e6|0x7bb2e6|`85 db`|—|
|0x7bb6e8|0x7bb2e8|`74 1b`|—|
|0x7bb6ea|0x7bb2ea|`8d 9b 00 00 00 00`|—|
|0x7bb6f0|0x7bb2f0|`8b 8e b4 00 00 00`|—|
|0x7bb6f6|0x7bb2f6|`8b 0c b9`|—|
|0x7bb6f0|0x7bb2f0|`8b 8e b4 00 00 00`|—|
|0x7bb6f6|0x7bb2f6|`8b 0c b9`|—|
|0x7bb6f9|0x7bb2f9|`8b 11`|—|
|0x7bb6fb|0x7bb2fb|`8b 42 04`|—|
|0x7bb6fe|0x7bb2fe|`ff d0`|—|
|0x7bb700|0x7bb300|`47`|—|
|0x7bb701|0x7bb301|`3b fb`|—|
|0x7bb703|0x7bb303|`72 eb`|—|
|0x7bb6f9|0x7bb2f9|`8b 11`|—|
|0x7bb6fb|0x7bb2fb|`8b 42 04`|—|
|0x7bb6fe|0x7bb2fe|`ff d0`|—|
|0x7bb700|0x7bb300|`47`|—|
|0x7bb701|0x7bb301|`3b fb`|—|
|0x7bb703|0x7bb303|`72 eb`|—|
|0x7bb705|0x7bb305|`8b 8e b8 00 00 00`|—|
|0x7bb70b|0x7bb30b|`8b be b4 00 00 00`|—|
|0x7bac79|0x7ba879|`e8 c2 09 00 00`|0x7BB240|
|0x7bac7e|0x7ba87e|`8b 45 e4`|—|
|0x7bac81|0x7ba881|`8b 08`|—|
|0x7bac83|0x7ba883|`8b 51 08`|—|
|0x7bac86|0x7ba886|`50`|—|
|0x7bac87|0x7ba887|`ff d2`|—|
|0x7bac89|0x7ba889|`8b 4d f4`|—|
|0x7bac8c|0x7ba88c|`64 89 0d 00 00 00 00`|—|
|0x7bb705|0x7bb305|`8b 8e b8 00 00 00`|—|
|0x7bb70b|0x7bb30b|`8b be b4 00 00 00`|—|
|0x7bb711|0x7bb311|`3b f9`|—|
|0x7bb713|0x7bb313|`74 21`|—|
|0x7bb715|0x7bb315|`8b c1`|—|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb70b|0x7bb30b|`8b be b4 00 00 00`|—|
|0x7bb711|0x7bb311|`3b f9`|—|
|0x7bb713|0x7bb313|`74 21`|—|
|0x7bb715|0x7bb315|`8b c1`|—|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb711|0x7bb311|`3b f9`|—|
|0x7bb713|0x7bb313|`74 21`|—|
|0x7bb715|0x7bb315|`8b c1`|—|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb715|0x7bb315|`8b c1`|—|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb736|0x7bb336|`8b 4d f4`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb736|0x7bb336|`8b 4d f4`|—|
|0x7bb739|0x7bb339|`64 89 0d 00 00 00 00`|—|
|0x7bb740|0x7bb340|`59`|—|
|0x7bb741|0x7bb341|`5f`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb736|0x7bb336|`8b 4d f4`|—|
|0x7bb739|0x7bb339|`64 89 0d 00 00 00 00`|—|
|0x7bb740|0x7bb340|`59`|—|
|0x7bb741|0x7bb341|`5f`|—|
|0x7bb742|0x7bb342|`5b`|—|
|0x7bb743|0x7bb343|`8b e5`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb736|0x7bb336|`8b 4d f4`|—|
|0x7bb739|0x7bb339|`64 89 0d 00 00 00 00`|—|
|0x7bb740|0x7bb340|`59`|—|
|0x7bb741|0x7bb341|`5f`|—|
|0x7bb742|0x7bb342|`5b`|—|
|0x7bb743|0x7bb343|`8b e5`|—|
|0x7bb745|0x7bb345|`5d`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：必要的選中entry實際類型、例外處理、B與全域bucket因果仍未全域驗證。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
