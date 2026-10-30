# T08-140 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：B隊列和22桶因果邊界

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-140-B-queue-to-global-bucket-evidence-boundary.md`，Git blob `471e5946d67fd02ad4f4390e6dedbfd1c2040430`、SHA256 `f26b853cd5ae343739f07838333c3f30ba9acfe21848ecf639bb328535d9654d`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：35 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

真0x7BB240 consume B queue並可能觸發CDoll secondary+4 0x7A8310 keyed registry；全域22桶另由CModel primary+8 0x7D3470條件寫入[FB7740]。兩種不同IRenderable派生並非同一this。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md](../../20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：B entry fn4→CModel建立/22桶的實際跨物件欄位和時序**尚未證實**。

## T01原始證據逐行映射：35／35 bytes相符

此為來源 code-row 的座標/byte修正表。E8/E9計算目標由**新VA + instructionLength + signed rel32**重算；其他分支/間接call target不能只看文本自動推論，另依根函式CFG定位。不將表值vtable與原始immediate整體重定位。

|舊標籤VA（FAILED）|正確VA（T01映射）|Tartaros.bin原始code bytes|由E8/E9真VA重算的直接目標|
|---|---|---|---|
|0x7bb6e4|0x7bb2e4|`33 ff`|—|
|0x7bb6e6|0x7bb2e6|`85 db`|—|
|0x7bb6e8|0x7bb2e8|`74 1b`|—|
|0x7bb6ea|0x7bb2ea|`8d 9b 00 00 00 00`|—|
|0x7bb6f0|0x7bb2f0|`8b 8e b4 00 00 00`|—|
|0x7bb6f6|0x7bb2f6|`8b 0c b9`|—|
|0x7bb6f9|0x7bb2f9|`8b 11`|—|
|0x7bb6fb|0x7bb2fb|`8b 42 04`|—|
|0x7bb6fe|0x7bb2fe|`ff d0`|—|
|0x7bb700|0x7bb300|`47`|—|
|0x7bb701|0x7bb301|`3b fb`|—|
|0x7bb703|0x7bb303|`72 eb`|—|
|0x7bb705|0x7bb305|`8b 8e b8 00 00 00`|—|
|0x7bb70b|0x7bb30b|`8b be b4 00 00 00`|—|
|0x7bb711|0x7bb311|`3b f9`|—|
|0x7bb713|0x7bb313|`74 21`|—|
|0x7bb715|0x7bb315|`8b c1`|—|
|0x7bb717|0x7bb317|`2b c1`|—|
|0x7bb719|0x7bb319|`c1 f8 02`|—|
|0x7bb71c|0x7bb31c|`8d 1c 85 00 00 00 00`|—|
|0x7bb723|0x7bb323|`53`|—|
|0x7bb724|0x7bb324|`51`|—|
|0x7bb725|0x7bb325|`57`|—|
|0x7bb726|0x7bb326|`e8 c5 5f 0d 00`|0x8912F0|
|0x7bb72b|0x7bb32b|`83 c4 0c`|—|
|0x7bb72e|0x7bb32e|`03 df`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bb736|0x7bb336|`8b 4d f4`|—|
|0x7bb739|0x7bb339|`64 89 0d 00 00 00 00`|—|
|0x7bb740|0x7bb340|`59`|—|
|0x7bb741|0x7bb341|`5f`|—|
|0x7bb742|0x7bb342|`5b`|—|
|0x7bb743|0x7bb343|`8b e5`|—|
|0x7bb745|0x7bb345|`5d`|—|
|0x7bb746|0x7bb346|`c3`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：B entry fn4→CModel建立/22桶的實際跨物件欄位和時序**尚未證實**。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
