# T08-152 — Verified .text source row coordinate repair worksheet

歷史來源 `kr-temp-roy/20261027-225400-chatgpt-web-roy-T08-152-vtable-entry-boundary-negative-xrefs.md`，原blob `6d50d49aa523a589714a76159169072b2a994145`；T01 mapping-findings blob `4216e87c6f424e88df83b8d45d515897b8d37e38`；原始 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**本篇復用T01已核原生ASM row，並非本次逐列獨立BIN重驗，也不代表全文語義修復或FULL-PASS。**

真PE .text VA0x401000/raw0x400，raw=VA−0x400C00；以下只訂正已核 code rows。不得自動移動 .rdata中絕對vtable值、指標立即值、全域欄位、其他區段。

|舊source VA|真PE code VA|真raw|原始機器碼|舊VA的不同bytes|由E8新VA重算目的地|
|---|---|---|---|---|---|
|`0x7a8e07`|`0x7a8a07`|`0x3a7e07`|`d9 9b b4 00 00 00`|`cc cc cc cc cc cc`|—|
|`0x7a8e0d`|`0x7a8a0d`|`0x3a7e0d`|`d9 83 d8 00 00 00`|`cc cc cc 55 8b ec`|—|
|`0x7a8e13`|`0x7a8a13`|`0x3a7e13`|`de d9`|`83 ec`|—|
|`0x7a8e15`|`0x7a8a15`|`0x3a7e15`|`df e0`|`0c 8b`|—|
|`0x7a391d`|`0x7a351d`|`0x3a291d`|`33 d2`|`cc cc`|—|
|`0x7a391f`|`0x7a351f`|`0x3a291f`|`83 c4 04`|`cc 85 c9`|—|
|`0x7a3922`|`0x7a3522`|`0x3a2922`|`3b c2`|`74 09`|—|
|`0x7a3924`|`0x7a3524`|`0x3a2924`|`74 2e`|`8b 01`|—|
|`0x7a3926`|`0x7a3526`|`0x3a2926`|`8b 4e 04`|`8b 50 08`|—|

本篇舊座標行數9，T01已核相符9；可重算E8 site數0。未核整體可達CFG、所有非E8間接caller與 vtable真實target，更不能復用錯誤source原有「已完成」聲稱。T01 `LEGACY-MAPPING-001`仍NEEDS_FIX。
