# T08-135 — T01 LEGACY-MAPPING-001 取代原稿之原生修正版 v3：通用vector appender與多owner身分

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。**KR第一手原件**：Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA0x401000/file raw0x400 → **code raw=VA−0x400C00**；.rdata依VA0xBD2000/raw0x7D0600，不可一律平移vtable DWORD。

## 歷史FAILED與本新版使用方式

- 原始錯誤source **保留不覆寫**：`kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-135-vector-append-owner-isolation.md`，Git blob `b473d309ff90aaf638935c6a55a6d6b84f90b251`、SHA256 `941ebeb55dd4594238fd9428c4e62bac2b8057cf0ba6a39ec05bd197a64013c7`。
- T01返回 `T01-RETURN-T08-LEGACY-MAPPING-001`。本篇改以**新的、保守可重審內容取代舊全文肯定主張**；未在下節明確重新列出之其它舊主張（包括舊程式碼相對地址、未驗CFG、ABI與執行時必然性），**正式撤回為UNKNOWN**，不隨舊原稿一起繼承。
- T01映射列：127 筆，全部有 `affine_candidate_equal=true`，由T01原生已核 `mapping-findings.json`復用，**不是本稿獨立重新解碼1263行**。完整code row在§原始位址對照；非code constants/硬編vptr不能一律減0x400。

## 新版有界原生技術結論（取代舊版）

真0x7BB350執行泛用ptr vector append，需由caller ECX/EDI及vector begin/end/cap判定所修改實體。已追到多個不同owner；不能把找到一個E8就當B-vector的全部producer。

**完整入口CFG／bytes、真物件擁有者與反例另附先前BIN-first修訂：** [20261031-023100-chatgpt-web-roy-T08-135-generic-vector-append-three-owner-PE-corrected-source.md](../../20261031-023100-chatgpt-web-roy-T08-135-generic-vector-append-three-owner-PE-corrected-source.md)。這份修正版只承認這些可查的有限主張；參考[本批交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[正確RTTI COL表界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**反例與明示未知**：未證所有函式指標/別名writer；CDoll的B enqueue與generic helper分離。

## T01原始證據逐行映射：127／127 bytes相符

此為來源 code-row 的座標/byte修正表。E8/E9計算目標由**新VA + instructionLength + signed rel32**重算；其他分支/間接call target不能只看文本自動推論，另依根函式CFG定位。不將表值vtable與原始immediate整體重定位。

|舊標籤VA（FAILED）|正確VA（T01映射）|Tartaros.bin原始code bytes|由E8/E9真VA重算的直接目標|
|---|---|---|---|
|0x7bb750|0x7bb350|`56`|—|
|0x7bb751|0x7bb351|`8b f0`|—|
|0x7bb753|0x7bb353|`8b 47 04`|—|
|0x7bb756|0x7bb356|`3b f0`|—|
|0x7bb758|0x7bb358|`73 2b`|—|
|0x7bb75a|0x7bb35a|`8b 0f`|—|
|0x7bb75c|0x7bb35c|`3b ce`|—|
|0x7bb75e|0x7bb35e|`77 25`|—|
|0x7bb753|0x7bb353|`8b 47 04`|—|
|0x7bb756|0x7bb356|`3b f0`|—|
|0x7bb758|0x7bb358|`73 2b`|—|
|0x7bb75a|0x7bb35a|`8b 0f`|—|
|0x7bb75c|0x7bb35c|`3b ce`|—|
|0x7bb75e|0x7bb35e|`77 25`|—|
|0x7bb760|0x7bb360|`2b f1`|—|
|0x7bb762|0x7bb362|`c1 fe 02`|—|
|0x7bb760|0x7bb360|`2b f1`|—|
|0x7bb762|0x7bb362|`c1 fe 02`|—|
|0x7bb765|0x7bb365|`3b 47 08`|—|
|0x7bb768|0x7bb368|`75 07`|—|
|0x7bb76a|0x7bb36a|`8b c7`|—|
|0x7bb76c|0x7bb36c|`e8 bf c5 fd ff`|0x797930|
|0x7bb771|0x7bb371|`8b 47 04`|—|
|0x7bb774|0x7bb374|`85 c0`|—|
|0x7bb765|0x7bb365|`3b 47 08`|—|
|0x7bb768|0x7bb368|`75 07`|—|
|0x7bb76a|0x7bb36a|`8b c7`|—|
|0x7bb76c|0x7bb36c|`e8 bf c5 fd ff`|0x797930|
|0x7bb771|0x7bb371|`8b 47 04`|—|
|0x7bb774|0x7bb374|`85 c0`|—|
|0x7bb776|0x7bb376|`74 24`|—|
|0x7bb778|0x7bb378|`8b 0f`|—|
|0x7bb76a|0x7bb36a|`8b c7`|—|
|0x7bb76c|0x7bb36c|`e8 bf c5 fd ff`|0x797930|
|0x7bb771|0x7bb371|`8b 47 04`|—|
|0x7bb774|0x7bb374|`85 c0`|—|
|0x7bb776|0x7bb376|`74 24`|—|
|0x7bb778|0x7bb378|`8b 0f`|—|
|0x7bb77a|0x7bb37a|`8b 14 b1`|—|
|0x7bb77d|0x7bb37d|`89 10`|—|
|0x7bb774|0x7bb374|`85 c0`|—|
|0x7bb776|0x7bb376|`74 24`|—|
|0x7bb778|0x7bb378|`8b 0f`|—|
|0x7bb77a|0x7bb37a|`8b 14 b1`|—|
|0x7bb77d|0x7bb37d|`89 10`|—|
|0x7bb77f|0x7bb37f|`83 47 04 04`|—|
|0x7bb783|0x7bb383|`5e`|—|
|0x7bb785|0x7bb385|`3b 47 08`|—|
|0x7bb788|0x7bb388|`75 07`|—|
|0x7bb78a|0x7bb38a|`8b c7`|—|
|0x7bb78c|0x7bb38c|`e8 9f c5 fd ff`|0x797930|
|0x7bb791|0x7bb391|`8b 47 04`|—|
|0x7bb794|0x7bb394|`85 c0`|—|
|0x7bb796|0x7bb396|`74 04`|—|
|0x7bb798|0x7bb398|`8b 0e`|—|
|0x7bb791|0x7bb391|`8b 47 04`|—|
|0x7bb794|0x7bb394|`85 c0`|—|
|0x7bb796|0x7bb396|`74 04`|—|
|0x7bb798|0x7bb398|`8b 0e`|—|
|0x7bb79a|0x7bb39a|`89 08`|—|
|0x7bb79c|0x7bb39c|`83 47 04 04`|—|
|0x7bb7a0|0x7bb3a0|`5e`|—|
|0x7bb7a1|0x7bb3a1|`c3`|—|
|0x7bb798|0x7bb398|`8b 0e`|—|
|0x7bb79a|0x7bb39a|`89 08`|—|
|0x7bb79c|0x7bb39c|`83 47 04 04`|—|
|0x7bb7a0|0x7bb3a0|`5e`|—|
|0x7bb7a1|0x7bb3a1|`c3`|—|
|0x7bb7a2|0x7bb3a2|`cc`|—|
|0x7bb7a3|0x7bb3a3|`cc`|—|
|0x7bb7a4|0x7bb3a4|`cc`|—|
|0x7bb79c|0x7bb39c|`83 47 04 04`|—|
|0x7bb7a0|0x7bb3a0|`5e`|—|
|0x7bb7a1|0x7bb3a1|`c3`|—|
|0x7bb7a2|0x7bb3a2|`cc`|—|
|0x7bb7a3|0x7bb3a3|`cc`|—|
|0x7bb7a4|0x7bb3a4|`cc`|—|
|0x7bb7a5|0x7bb3a5|`cc`|—|
|0x7bb7a6|0x7bb3a6|`cc`|—|
|0x7bb61a|0x7bb21a|`81 c7 a4 00 00 00`|—|
|0x7bb620|0x7bb220|`8d 45 0c`|—|
|0x7bb623|0x7bb223|`e8 28 01 00 00`|0x7BB350|
|0x7bb628|0x7bb228|`8b 4d f4`|—|
|0x7bb62b|0x7bb22b|`64 89 0d 00 00 00 00`|—|
|0x7bb632|0x7bb232|`59`|—|
|0x7bb633|0x7bb233|`5f`|—|
|0x7bb634|0x7bb234|`5e`|—|
|0x7bb623|0x7bb223|`e8 28 01 00 00`|0x7BB350|
|0x7bb628|0x7bb228|`8b 4d f4`|—|
|0x7bb62b|0x7bb22b|`64 89 0d 00 00 00 00`|—|
|0x7bb632|0x7bb232|`59`|—|
|0x7bb633|0x7bb233|`5f`|—|
|0x7bb634|0x7bb234|`5e`|—|
|0x7bb635|0x7bb235|`5b`|—|
|0x7bb636|0x7bb236|`8b e5`|—|
|0x7e87f3|0x7e83f3|`8d 44 24 14`|—|
|0x7e87f7|0x7e83f7|`8d 7e 20`|—|
|0x7e87fa|0x7e83fa|`e8 51 2f fd ff`|0x7BB350|
|0x7e87ff|0x7e83ff|`8b 4c 24 58`|—|
|0x7e8803|0x7e8403|`64 89 0d 00 00 00 00`|—|
|0x7e880a|0x7e840a|`59`|—|
|0x7e880b|0x7e840b|`5f`|—|
|0x7e880c|0x7e840c|`5e`|—|
|0x7e87fa|0x7e83fa|`e8 51 2f fd ff`|0x7BB350|
|0x7e87ff|0x7e83ff|`8b 4c 24 58`|—|
|0x7e8803|0x7e8403|`64 89 0d 00 00 00 00`|—|
|0x7e880a|0x7e840a|`59`|—|
|0x7e880b|0x7e840b|`5f`|—|
|0x7e880c|0x7e840c|`5e`|—|
|0x7e880d|0x7e840d|`5b`|—|
|0x7e880e|0x7e840e|`8b 4c 24 40`|—|
|0x7b96cb|0x7b92cb|`8d 7b 7c`|—|
|0x7b96ce|0x7b92ce|`8d 45 d0`|—|
|0x7b96d1|0x7b92d1|`e8 7a 20 00 00`|0x7BB350|
|0x7b96d6|0x7b92d6|`8b 45 d0`|—|
|0x7b96d9|0x7b92d9|`8b 4d f4`|—|
|0x7b96dc|0x7b92dc|`64 89 0d 00 00 00 00`|—|
|0x7b96e3|0x7b92e3|`59`|—|
|0x7b96e4|0x7b92e4|`5f`|—|
|0x7b96d1|0x7b92d1|`e8 7a 20 00 00`|0x7BB350|
|0x7b96d6|0x7b92d6|`8b 45 d0`|—|
|0x7b96d9|0x7b92d9|`8b 4d f4`|—|
|0x7b96dc|0x7b92dc|`64 89 0d 00 00 00 00`|—|
|0x7b96e3|0x7b92e3|`59`|—|
|0x7b96e4|0x7b92e4|`5f`|—|
|0x7b96e5|0x7b92e5|`5e`|—|
|0x7b96e6|0x7b92e6|`5b`|—|

## 作為新source的完備邊界與T01再驗

- **Client已證**：本稿所列具名真PE函式、指定有條件分支、來源正確的code rows。
- **Client待逆向**：未證所有函式指標/別名writer；CDoll的B enqueue與generic helper分離。，以及原稿未被本版重新主張的所有語義。
- **Server待開發**：需要由T02可驗wire定義輸入/輸出，不能由本地queue、render函式猜原版Server出怪/畫面時序。
- **跨功能/遊玩待驗證**：T01仍需以新Git blob逐個主張/全部CFG驗證；S00規格與T02/T06/T07/T14場景分別審核。**本篇不是T01 FULL-PASS，也不對24篇整體退回自行RESOLVED。**
