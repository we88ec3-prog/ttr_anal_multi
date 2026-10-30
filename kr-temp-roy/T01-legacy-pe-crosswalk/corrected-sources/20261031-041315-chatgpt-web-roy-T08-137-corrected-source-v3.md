# T08-137 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：B vector writer xref負面界線

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-137-B-writer-xref-audit.md`，Git blob `39bb9462451fa62b890c7e5c1fca225d9eb70ed6`、SHA256 `743d440522984fd858696417bf637ab9de47786e888c376f2df54476e8e63360`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：35 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

舊稿只做direct field xref的局部掃描不能排除虛擬間接入列：真0x7A63C0經CDoll primary vtable C4F67C+8可向全域[FBA838] owner+0xB4/B8/Bc append CDoll+0x0C。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md](../../20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：直接CALL E8零命中不代表producer不存在；實際scene虛擬caller依舊待查。

## T01原始證據逐行映射：35／35 bytes相符

此為來源 code-row 的座標/byte修正表。E8/E9計算目標由**新VA + instructionLength + signed rel32**重算；其他分支/間接call target不能只看文本自動推論，另依根函式CFG定位。不將表值vtable與原始immediate整體重定位。

|舊標籤VA（FAILED）|正確VA（T01映射）|Tartaros.bin原始code bytes|由E8/E9真VA重算的直接目標|
|---|---|---|---|
|0x7b8f76|0x7b8b76|`89 9f b4 00 00 00`|—|
|0x7b8f7c|0x7b8b7c|`89 9f b8 00 00 00`|—|
|0x7b8f82|0x7b8b82|`89 9f bc 00 00 00`|—|
|0x7b91cf|0x7b8dcf|`8b 83 b4 00 00 00`|—|
|0x7b91e2|0x7b8de2|`89 b3 b4 00 00 00`|—|
|0x7b91e8|0x7b8de8|`89 b3 b8 00 00 00`|—|
|0x7b91ee|0x7b8dee|`89 b3 bc 00 00 00`|—|
|0x7bb664|0x7bb264|`8b 86 b8 00 00 00`|—|
|0x7bb66a|0x7bb26a|`2b 86 b4 00 00 00`|—|
|0x7bb6b7|0x7bb2b7|`8b 96 b4 00 00 00`|—|
|0x7bb6d0|0x7bb2d0|`8b 86 b8 00 00 00`|—|
|0x7bb6f0|0x7bb2f0|`8b 8e b4 00 00 00`|—|
|0x7bb705|0x7bb305|`8b 8e b8 00 00 00`|—|
|0x7bb70b|0x7bb30b|`8b be b4 00 00 00`|—|
|0x7bb730|0x7bb330|`89 9e b8 00 00 00`|—|
|0x7bddb0|0x7bd9b0|`d9 94 24 b8 00 00 00`|—|
|0x7bdeba|0x7bdaba|`d9 94 24 b8 00 00 00`|—|
|0x7be5b7|0x7be1b7|`89 bc 24 b8 00 00 00`|—|
|0x7be5c5|0x7be1c5|`89 94 24 b4 00 00 00`|—|
|0x7be723|0x7be323|`d9 9c 24 bc 00 00 00`|—|
|0x7be760|0x7be360|`89 84 24 b4 00 00 00`|—|
|0x7be772|0x7be372|`89 8c 24 b8 00 00 00`|—|
|0x7bed2f|0x7be92f|`89 88 b8 00 00 00`|—|
|0x7b91c3|0x7b8dc3|`89 b3 cc 00 00 00`|—|
|0x7b91c9|0x7b8dc9|`89 b3 d0 00 00 00`|—|
|0x7b91cf|0x7b8dcf|`8b 83 b4 00 00 00`|—|
|0x7b91d5|0x7b8dd5|`3b c6`|—|
|0x7b91d7|0x7b8dd7|`74 09`|—|
|0x7b91d9|0x7b8dd9|`50`|—|
|0x7b91da|0x7b8dda|`e8 2d 84 0d 00`|0x89120C|
|0x7b91df|0x7b8ddf|`83 c4 04`|—|
|0x7b91e2|0x7b8de2|`89 b3 b4 00 00 00`|—|
|0x7b91e8|0x7b8de8|`89 b3 b8 00 00 00`|—|
|0x7b91ee|0x7b8dee|`89 b3 bc 00 00 00`|—|
|0x7b91f4|0x7b8df4|`8b 83 a4 00 00 00`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：直接CALL E8零命中不代表producer不存在；實際scene虛擬caller依舊待查。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
