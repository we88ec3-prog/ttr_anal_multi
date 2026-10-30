# T08-139 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：B comparator ABI與兩個caller

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-139-B-comparator-ABI-and-two-callers.md`，Git blob `5ce4138eabb80f1a859b4801f075a56e4ac8167f`、SHA256 `7589bfcce37cad641da1b1021f52f2099ab93d4045afd6c6113fac7476eb1766`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：109 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

真0x7BB3B0為選取/排序，0x7BB870為comparative helper；entry secondary vptr+8可動態指0x7A8E10，按3D分量計平方距離score而非畫面上必然的排序結論。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md](../../20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：caller與target物件類型受vptr壽命限制，不能把距離score擴成Server出怪優先級。

## T01原始證據逐行映射：109／109 bytes相符

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
|0x7bb686|0x7bb286|`75 27`|—|
|0x7bb688|0x7bb288|`83 0d e8 79 fb 00 01`|—|
|0x7bb68f|0x7bb28f|`c7 45 fc 00 00 00 00`|—|
|0x7bb696|0x7bb296|`e8 45 db fd ff`|0x798DE0|
|0x7bb69b|0x7bb29b|`68 e0 d2 bc 00`|—|
|0x7bb6a0|0x7bb2a0|`e8 75 70 0d 00`|0x89231A|
|0x7bb6a5|0x7bb2a5|`83 c4 04`|—|
|0x7bb6a8|0x7bb2a8|`c7 45 fc ff ff ff ff`|—|
|0x7bb6af|0x7bb2af|`a1 e8 76 fb 00`|—|
|0x7bb6b4|0x7bb2b4|`8b 78 0c`|—|
|0x7bb6b7|0x7bb2b7|`8b 96 b4 00 00 00`|—|
|0x7bb6bd|0x7bb2bd|`83 ec 0c`|—|
|0x7bb6c0|0x7bb2c0|`8b cc`|—|
|0x7bb6c2|0x7bb2c2|`89 39`|—|
|0x7bb6c4|0x7bb2c4|`8b 78 10`|—|
|0x7bb6c7|0x7bb2c7|`8b 40 14`|—|
|0x7bb6ca|0x7bb2ca|`89 79 04`|—|
|0x7bb6cd|0x7bb2cd|`89 41 08`|—|
|0x7bb6d0|0x7bb2d0|`8b 86 b8 00 00 00`|—|
|0x7bb6d6|0x7bb2d6|`50`|—|
|0x7bb6d7|0x7bb2d7|`8d 04 9a`|—|
|0x7bb6da|0x7bb2da|`50`|—|
|0x7bb6db|0x7bb2db|`52`|—|
|0x7bb6dc|0x7bb2dc|`e8 cf 00 00 00`|0x7BB3B0|
|0x7bb6e1|0x7bb2e1|`83 c4 18`|—|
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
|0x7bbc70|0x7bb870|`55`|—|
|0x7bbc71|0x7bb871|`8b ec`|—|
|0x7bbc73|0x7bb873|`83 ec 0c`|—|
|0x7bbc76|0x7bb876|`8b 45 08`|—|
|0x7bbc79|0x7bb879|`8b 0e`|—|
|0x7bbc7b|0x7bb87b|`8b 11`|—|
|0x7bbc7d|0x7bb87d|`8b 52 08`|—|
|0x7bbc80|0x7bb880|`53`|—|
|0x7bbc81|0x7bb881|`8b 1f`|—|
|0x7bbc83|0x7bb883|`89 45 fc`|—|
|0x7bbc86|0x7bb886|`8d 45 0c`|—|
|0x7bbc89|0x7bb889|`50`|—|
|0x7bbc8a|0x7bb88a|`ff d2`|—|
|0x7bbc8c|0x7bb88c|`dd 5d f4`|—|
|0x7bbc8f|0x7bb88f|`8b 03`|—|
|0x7bbc91|0x7bb891|`8b 50 08`|—|
|0x7bbc94|0x7bb894|`8d 4d 0c`|—|
|0x7bbc97|0x7bb897|`51`|—|
|0x7bbc98|0x7bb898|`8b cb`|—|
|0x7bbc9a|0x7bb89a|`ff d2`|—|
|0x7bbc9c|0x7bb89c|`dc 5d f4`|—|
|0x7bbc9f|0x7bb89f|`df e0`|—|
|0x7bbca1|0x7bb8a1|`f6 c4 41`|—|
|0x7bbca4|0x7bb8a4|`75 08`|—|
|0x7bbca6|0x7bb8a6|`8b 0f`|—|
|0x7bbca8|0x7bb8a8|`8b 06`|—|
|0x7bbcaa|0x7bb8aa|`89 0e`|—|
|0x7bbcac|0x7bb8ac|`89 07`|—|
|0x7bbcae|0x7bb8ae|`8b 55 fc`|—|
|0x79a376|0x799f76|`83 c4 04`|—|
|0x79a379|0x799f79|`89 5d fc`|—|
|0x79a37c|0x799f7c|`6a 00`|—|
|0x79a37e|0x799f7e|`68 50 32 fe 00`|—|
|0x79a383|0x799f83|`e8 68 50 03 00`|0x7CEFF0|
|0x79a388|0x799f88|`57`|—|
|0x79a389|0x799f89|`e8 d2 10 00 00`|0x79B060|
|0x79a38e|0x799f8e|`8b 35 38 a8 fb 00`|—|
|0x79a394|0x799f94|`e8 a7 12 02 00`|0x7BB240|
|0x79a399|0x799f99|`8b 8f a0 00 00 00`|—|
|0x79a39f|0x799f9f|`8b 01`|—|
|0x79a3a1|0x799fa1|`8b 97 98 00 00 00`|—|
|0x79a3a7|0x799fa7|`8b 40 0c`|—|
|0x79a3aa|0x799faa|`52`|—|
|0x79a3ab|0x799fab|`ff d0`|—|
|0x79a3ad|0x799fad|`8b 0f`|—|
|0x79a3af|0x799faf|`8b 11`|—|
|0x7bac62|0x7ba862|`83 c6 2c`|—|
|0x7bac65|0x7ba865|`4b`|—|
|0x7bac66|0x7ba866|`75 ec`|—|
|0x7bac68|0x7ba868|`8b 5d ec`|—|
|0x7bac6b|0x7ba86b|`8b 75 e8`|—|
|0x7bac6e|0x7ba86e|`8b 45 f0`|—|
|0x7bac71|0x7ba871|`40`|—|
|0x7bac72|0x7ba872|`89 45 f0`|—|
|0x7bac75|0x7ba875|`3b c3`|—|
|0x7bac77|0x7ba877|`72 ac`|—|
|0x7bac79|0x7ba879|`e8 c2 09 00 00`|0x7BB240|
|0x7bac7e|0x7ba87e|`8b 45 e4`|—|
|0x7bac81|0x7ba881|`8b 08`|—|
|0x7bac83|0x7ba883|`8b 51 08`|—|
|0x7bac86|0x7ba886|`50`|—|
|0x7bac87|0x7ba887|`ff d2`|—|
|0x7bac89|0x7ba889|`8b 4d f4`|—|
|0x7bac8c|0x7ba88c|`64 89 0d 00 00 00 00`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：caller與target物件類型受vptr壽命限制，不能把距離score擴成Server出怪優先級。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
