# T08-144 — Verified .text source row coordinate repair worksheet

歷史來源 `kr-temp-roy/20261027-210935-chatgpt-web-roy-T08-144-B-producer-consumer-link-and-vtable-limit.md`，原blob `d1af4d9f33eaf7f55c72cc98f6c79169d867f58b`；T01 mapping-findings blob `4216e87c6f424e88df83b8d45d515897b8d37e38`；原始 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**本篇復用T01已核原生ASM row，並非本次逐列獨立BIN重驗，也不代表全文語義修復或FULL-PASS。**

真PE .text VA0x401000/raw0x400，raw=VA−0x400C00；以下只訂正已核 code rows。不得自動移動 .rdata中絕對vtable值、指標立即值、全域欄位、其他區段。

|舊source VA|真PE code VA|真raw|原始機器碼|舊VA的不同bytes|由E8新VA重算目的地|
|---|---|---|---|---|---|
|`0x7a69d9`|`0x7a65d9`|`0x3a59d9`|`8b 35 38 a8 fb 00`|`fe ff ff 1f 2b d1`|—|
|`0x7a69df`|`0x7a65df`|`0x3a59df`|`8b 86 b8 00 00 00`|`83 fa 01 73 0a 68`|—|
|`0x7a69e5`|`0x7a65e5`|`0x3a59e5`|`83 c7 0c`|`34 20 bf`|—|
|`0x7a69e8`|`0x7a65e8`|`0x3a59e8`|`8d 4d ec`|`00 e8 42`|—|
|`0x7a69eb`|`0x7a65eb`|`0x3a59eb`|`89 7d ec`|`71 0d 00`|—|
|`0x7a69ee`|`0x7a65ee`|`0x3a59ee`|`3b c8`|`41 89`|—|
|`0x7a6a32`|`0x7a6632`|`0x3a5a32`|`3b 86 bc 00 00 00`|`d0 8b b7 a0 00 00`|—|
|`0x7a6a38`|`0x7a6638`|`0x3a5a38`|`75 0b`|`00 0f`|—|
|`0x7a6a3a`|`0x7a663a`|`0x3a5a3a`|`8d 86 b4 00 00 00`|`b6 58 29 85 f6 74`|—|
|`0x7a6a40`|`0x7a6640`|`0x3a5a40`|`e8 eb 12 ff ff`|`48 85 db 0f 84`|0x00797930|
|`0x7a6a45`|`0x7a6645`|`0x3a5a45`|`8b 86 b8 00 00 00`|`6d 01 00 00 8b 06`|—|
|`0x7a6a4b`|`0x7a664b`|`0x3a5a4b`|`85 c0`|`8d 4c`|—|
|`0x7a6a4d`|`0x7a664d`|`0x3a5a4d`|`74 02`|`24 08`|—|
|`0x7a6a4f`|`0x7a664f`|`0x3a5a4f`|`89 38`|`51 8d`|—|
|`0x7a6a51`|`0x7a6651`|`0x3a5a51`|`83 86 b8 00 00 00 04`|`48 34 8d 44 24 10 89`|—|
|`0x7bb664`|`0x7bb264`|`0x3ba664`|`8b 86 b8 00 00 00`|`08 8b 5d 08 c1 f8`|—|
|`0x7bb66a`|`0x7bb26a`|`0x3ba66a`|`2b 86 b4 00 00 00`|`02 83 f8 20 0f 8f`|—|
|`0x7bb670`|`0x7bb270`|`0x3ba670`|`8b 9e c4 00 00 00`|`5c fd ff ff 8b 55`|—|
|`0x7bb676`|`0x7bb276`|`0x3ba676`|`c1 f8 02`|`14 8b 4d`|—|
|`0x7bb679`|`0x7bb279`|`0x3ba679`|`3b d8`|`18 83`|—|
|`0x7bb67b`|`0x7bb27b`|`0x3ba67b`|`76 02`|`ec 0c`|—|
|`0x7bb67d`|`0x7bb27d`|`0x3ba67d`|`8b d8`|`8b c4`|—|
|`0x7bb6f0`|`0x7bb2f0`|`0x3ba6f0`|`8b 8e b4 00 00 00`|`3b 51 89 75 f8 89`|—|
|`0x7bb6f6`|`0x7bb2f6`|`0x3ba6f6`|`8b 0c b9`|`50 08 e8`|—|
|`0x7bb6f9`|`0x7bb2f9`|`0x3ba6f9`|`8b 11`|`73 01`|—|
|`0x7bb6fb`|`0x7bb2fb`|`0x3ba6fb`|`8b 42 04`|`00 00 8b`|—|
|`0x7bb6fe`|`0x7bb2fe`|`0x3ba6fe`|`ff d0`|`4d 10`|—|
|`0x7bb700`|`0x7bb300`|`0x3ba700`|`47`|`8b`|—|
|`0x7bb701`|`0x7bb301`|`0x3ba701`|`3b fb`|`55 14`|—|
|`0x7bb703`|`0x7bb303`|`0x3ba703`|`72 eb`|`8b 75`|—|
|`0x7bbc76`|`0x7bb876`|`0x3bac76`|`8b 45 08`|`e8 65 d1`|—|
|`0x7bbc79`|`0x7bb879`|`0x3bac79`|`8b 0e`|`fd ff`|—|
|`0x7bbc7b`|`0x7bb87b`|`0x3bac7b`|`8b 11`|`68 e0`|—|
|`0x7bbc7d`|`0x7bb87d`|`0x3bac7d`|`8b 52 08`|`d2 bc 00`|—|
|`0x7bbc80`|`0x7bb880`|`0x3bac80`|`53`|`e8`|—|
|`0x7bbc81`|`0x7bb881`|`0x3bac81`|`8b 1f`|`95 66`|—|
|`0x7bbc83`|`0x7bb883`|`0x3bac83`|`89 45 fc`|`0d 00 83`|—|
|`0x7bbc86`|`0x7bb886`|`0x3bac86`|`8d 45 0c`|`c4 04 89`|—|
|`0x7bbc89`|`0x7bb889`|`0x3bac89`|`50`|`5d`|—|
|`0x7bbc8a`|`0x7bb88a`|`0x3bac8a`|`ff d2`|`fc 68`|—|
|`0x7bbc8c`|`0x7bb88c`|`0x3bac8c`|`dd 5d f4`|`ec 76 fb`|—|
|`0x7bbc8f`|`0x7bb88f`|`0x3bac8f`|`8b 03`|`00 ff`|—|
|`0x7bbc91`|`0x7bb891`|`0x3bac91`|`8b 50 08`|`15 4c 22`|—|
|`0x7bbc94`|`0x7bb894`|`0x3bac94`|`8d 4d 0c`|`bd 00 8b`|—|
|`0x7bbc97`|`0x7bb897`|`0x3bac97`|`51`|`47`|—|
|`0x7bbc98`|`0x7bb898`|`0x3bac98`|`8b cb`|`28 8b`|—|
|`0x7bbc9a`|`0x7bb89a`|`0x3bac9a`|`ff d2`|`30 3b`|—|
|`0x7bbc9c`|`0x7bb89c`|`0x3bac9c`|`dc 5d f4`|`f0 0f 84`|—|

本篇舊座標行數48，T01已核相符48；可重算E8 site數1。未核整體可達CFG、所有非E8間接caller與 vtable真實target，更不能復用錯誤source原有「已完成」聲稱。T01 `LEGACY-MAPPING-001`仍NEEDS_FIX。
