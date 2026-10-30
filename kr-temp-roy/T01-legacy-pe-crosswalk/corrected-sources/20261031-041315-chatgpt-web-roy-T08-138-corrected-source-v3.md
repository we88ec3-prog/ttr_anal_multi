# T08-138 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：manager RTTI／vtable與entry型別

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-138-manager-vtable-and-entry-type-boundary.md`，Git blob `0f57fa53734a801984402bb13ac15617a3e01e76`、SHA256 `198e399a99ab642013057452ce739d5d455d5b3dbb299c819cfdfb228298ca29`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：27 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

原生.rdata manager vtable 0xC4FC8C是指標表，DWORD均是已定位的**絕對VA**，不能平移−0x400；CDoll secondary vptr另為0xC4F6C0，兩表不能因槽位位移相同而混用。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md](../../20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：仍須以真正constructor/vptr source判斷每個callsite的receiver type及具體回傳值。

## T01原始證據逐行映射：27／27 bytes相符

此為來源 code-row 的座標/byte修正表。E8/E9計算目標由**新VA + instructionLength + signed rel32**重算；其他分支/間接call target不能只看文本自動推論，另依根函式CFG定位。不將表值vtable與原始immediate整體重定位。

|舊標籤VA（FAILED）|正確VA（T01映射）|Tartaros.bin原始code bytes|由E8/E9真VA重算的直接目標|
|---|---|---|---|
|0x7b8e78|0x7b8a78|`8b 7d 08`|—|
|0x7b8e7b|0x7b8a7b|`33 db`|—|
|0x7b8e7d|0x7b8a7d|`89 5d fc`|—|
|0x7b8e80|0x7b8a80|`c7 07 8c fc c4 00`|—|
|0x7b8e86|0x7b8a86|`be 0f 00 00 00`|—|
|0x7b8e8b|0x7b8a8b|`89 77 18`|—|
|0x7b8e8e|0x7b8a8e|`89 5f 14`|—|
|0x7b8e91|0x7b8a91|`88 5f 04`|—|
|0x7b8e94|0x7b8a94|`89 77 34`|—|
|0x7b8e97|0x7b8a97|`89 5f 30`|—|
|0x7b8e9a|0x7b8a9a|`88 5f 20`|—|
|0x7b8e9d|0x7b8a9d|`89 5f 3c`|—|
|0x7aafa9|0x7aaba9|`33 c5`|—|
|0x7aafab|0x7aabab|`50`|—|
|0x7aafac|0x7aabac|`8d 45 f4`|—|
|0x7aafaf|0x7aabaf|`64 a3 00 00 00 00`|—|
|0x7aafb5|0x7aabb5|`8b 0d 38 a8 fb 00`|—|
|0x7aafbb|0x7aabbb|`33 ff`|—|
|0x7aafbd|0x7aabbd|`bb 01 00 00 00`|—|
|0x7aafc2|0x7aabc2|`3b cf`|—|
|0x7aafc4|0x7aabc4|`74 0e`|—|
|0x7aafc6|0x7aabc6|`8b 01`|—|
|0x7aafc8|0x7aabc8|`8b 50 04`|—|
|0x7aafcb|0x7aabcb|`53`|—|
|0x7aafcc|0x7aabcc|`ff d2`|—|
|0x7aafce|0x7aabce|`89 3d 38 a8 fb 00`|—|
|0x7aafd4|0x7aabd4|`83 ce ff`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：仍須以真正constructor/vptr source判斷每個callsite的receiver type及具體回傳值。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
