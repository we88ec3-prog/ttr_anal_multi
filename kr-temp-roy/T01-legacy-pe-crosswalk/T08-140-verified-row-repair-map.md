# T08-140 — Verified .text source row coordinate repair worksheet

歷史來源 `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-140-B-queue-to-global-bucket-evidence-boundary.md`，原blob `471e5946d67fd02ad4f4390e6dedbfd1c2040430`；T01 mapping-findings blob `4216e87c6f424e88df83b8d45d515897b8d37e38`；原始 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**本篇復用T01已核原生ASM row，並非本次逐列獨立BIN重驗，也不代表全文語義修復或FULL-PASS。**

真PE .text VA0x401000/raw0x400，raw=VA−0x400C00；以下只訂正已核 code rows。不得自動移動 .rdata中絕對vtable值、指標立即值、全域欄位、其他區段。

|舊source VA|真PE code VA|真raw|原始機器碼|舊VA的不同bytes|由E8新VA重算目的地|
|---|---|---|---|---|---|
|`0x7bb6e4`|`0x7bb2e4`|`0x3ba6e4`|`33 ff`|`4d fc`|—|
|`0x7bb6e6`|`0x7bb2e6`|`0x3ba6e6`|`85 db`|`89 50`|—|
|`0x7bb6e8`|`0x7bb2e8`|`0x3ba6e8`|`74 1b`|`04 8b`|—|
|`0x7bb6ea`|`0x7bb2ea`|`0x3ba6ea`|`8d 9b 00 00 00 00`|`55 18 03 cf 8d 34`|—|
|`0x7bb6f0`|`0x7bb2f0`|`0x3ba6f0`|`8b 8e b4 00 00 00`|`3b 51 89 75 f8 89`|—|
|`0x7bb6f6`|`0x7bb2f6`|`0x3ba6f6`|`8b 0c b9`|`50 08 e8`|—|
|`0x7bb6f9`|`0x7bb2f9`|`0x3ba6f9`|`8b 11`|`73 01`|—|
|`0x7bb6fb`|`0x7bb2fb`|`0x3ba6fb`|`8b 42 04`|`00 00 8b`|—|
|`0x7bb6fe`|`0x7bb2fe`|`0x3ba6fe`|`ff d0`|`4d 10`|—|
|`0x7bb700`|`0x7bb300`|`0x3ba700`|`47`|`8b`|—|
|`0x7bb701`|`0x7bb301`|`0x3ba701`|`3b fb`|`55 14`|—|
|`0x7bb703`|`0x7bb303`|`0x3ba703`|`72 eb`|`8b 75`|—|
|`0x7bb705`|`0x7bb305`|`0x3ba705`|`8b 8e b8 00 00 00`|`08 83 c4 04 8b c4`|—|
|`0x7bb70b`|`0x7bb30b`|`0x3ba70b`|`8b be b4 00 00 00`|`89 08 8b 4d 18 89`|—|
|`0x7bb711`|`0x7bb311`|`0x3ba711`|`3b f9`|`50 04`|—|
|`0x7bb713`|`0x7bb313`|`0x3ba713`|`74 21`|`8d 14`|—|
|`0x7bb715`|`0x7bb315`|`0x3ba715`|`8b c1`|`33 8b`|—|
|`0x7bb717`|`0x7bb317`|`0x3ba717`|`2b c1`|`fe 52`|—|
|`0x7bb719`|`0x7bb319`|`0x3ba719`|`c1 f8 02`|`2b fb 89`|—|
|`0x7bb71c`|`0x7bb31c`|`0x3ba71c`|`8d 1c 85 00 00 00 00`|`48 08 e8 4d 01 00 00`|—|
|`0x7bb723`|`0x7bb323`|`0x3ba723`|`53`|`8b`|—|
|`0x7bb724`|`0x7bb324`|`0x3ba724`|`51`|`7d`|—|
|`0x7bb725`|`0x7bb325`|`0x3ba725`|`57`|`0c`|—|
|`0x7bb726`|`0x7bb326`|`0x3ba726`|`e8 c5 5f 0d 00`|`8b 4d 10 8b 55`|0x008912F0|
|`0x7bb72b`|`0x7bb32b`|`0x3ba72b`|`83 c4 0c`|`14 83 c4`|—|
|`0x7bb72e`|`0x7bb32e`|`0x3ba72e`|`03 df`|`04 8b`|—|
|`0x7bb730`|`0x7bb330`|`0x3ba730`|`89 9e b8 00 00 00`|`c4 89 08 8b 4d 18`|—|
|`0x7bb736`|`0x7bb336`|`0x3ba736`|`8b 4d f4`|`8b f7 57`|—|
|`0x7bb739`|`0x7bb339`|`0x3ba739`|`64 89 0d 00 00 00 00`|`2b 7d fc 89 50 04 2b`|—|
|`0x7bb740`|`0x7bb340`|`0x3ba740`|`59`|`f3`|—|
|`0x7bb741`|`0x7bb341`|`0x3ba741`|`5f`|`89`|—|
|`0x7bb742`|`0x7bb342`|`0x3ba742`|`5b`|`48`|—|
|`0x7bb743`|`0x7bb343`|`0x3ba743`|`8b e5`|`08 e8`|—|
|`0x7bb745`|`0x7bb345`|`0x3ba745`|`5d`|`27`|—|
|`0x7bb746`|`0x7bb346`|`0x3ba746`|`c3`|`01`|—|

本篇舊座標行數35，T01已核相符35；可重算E8 site數1。未核整體可達CFG、所有非E8間接caller與 vtable真實target，更不能復用錯誤source原有「已完成」聲稱。T01 `LEGACY-MAPPING-001`仍NEEDS_FIX。
