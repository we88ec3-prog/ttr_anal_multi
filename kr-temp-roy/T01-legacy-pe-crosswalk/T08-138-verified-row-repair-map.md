# T08-138 — Verified .text source row coordinate repair worksheet

來源 `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-138-manager-vtable-and-entry-type-boundary.md`（歷史 blob `0f57fa53734a801984402bb13ac15617a3e01e76`）；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。T01 原始 crosswalk blob `4216e87c6f424e88df83b8d45d515897b8d37e38`。**本工作表復用 T01 對各保存機器碼的原生比對；不是本次獨立逐列驗算、原稿全文修正或 FULL-PASS。**

修正條件：PE .text raw=VA−0x400C00；**只**修本表已證原始機器碼坐標。不要位移 .rdata 絕對指標、立即值、普通資料位址；也不得直接將函式語義標完成。

|舊稿誤碼VA|真 PE VA|raw offset|已存原生bytes|舊VA實際bytes|E8 真目的地|
|---|---|---|---|---|---|
|`0x7b8e78`|`0x7b8a78`|`0x3b7e78`|`8b 7d 08`|`71 dc ff`|—|
|`0x7b8e7b`|`0x7b8a7b`|`0x3b7e7b`|`33 db`|`8b 4e`|—|
|`0x7b8e7d`|`0x7b8a7d`|`0x3b7e7d`|`89 5d fc`|`04 51 e8`|—|
|`0x7b8e80`|`0x7b8a80`|`0x3b7e80`|`c7 07 8c fc c4 00`|`88 83 0d 00 8b 43`|—|
|`0x7b8e86`|`0x7b8a86`|`0x3b7e86`|`be 0f 00 00 00`|`58 33 f6 83 c4`|—|
|`0x7b8e8b`|`0x7b8a8b`|`0x3b7e8b`|`89 77 18`|`04 3b c6`|—|
|`0x7b8e8e`|`0x7b8a8e`|`0x3b7e8e`|`89 5f 14`|`74 14 8b`|—|
|`0x7b8e91`|`0x7b8a91`|`0x3b7e91`|`88 5f 04`|`7b 5c e8`|—|
|`0x7b8e94`|`0x7b8a94`|`0x3b7e94`|`89 77 34`|`e8 7b c8`|—|
|`0x7b8e97`|`0x7b8a97`|`0x3b7e97`|`89 5f 30`|`ff 8b 53`|—|
|`0x7b8e9a`|`0x7b8a9a`|`0x3b7e9a`|`88 5f 20`|`58 52 e8`|—|
|`0x7b8e9d`|`0x7b8a9d`|`0x3b7e9d`|`89 5f 3c`|`6b 83 0d`|—|
|`0x7aafa9`|`0x7aaba9`|`0x3a9fa9`|`33 c5`|`ff 68`|—|
|`0x7aafab`|`0x7aabab`|`0x3a9fab`|`50`|`80`|—|
|`0x7aafac`|`0x7aabac`|`0x3a9fac`|`8d 45 f4`|`db bc 00`|—|
|`0x7aafaf`|`0x7aabaf`|`0x3a9faf`|`64 a3 00 00 00 00`|`e8 66 73 0e 00 83`|—|
|`0x7aafb5`|`0x7aabb5`|`0x3a9fb5`|`8b 0d 38 a8 fb 00`|`c4 04 89 5d fc bf`|—|
|`0x7aafbb`|`0x7aabbb`|`0x3a9fbb`|`33 ff`|`90 0e`|—|
|`0x7aafbd`|`0x7aabbd`|`0x3a9fbd`|`bb 01 00 00 00`|`fc 00 e8 bc 24`|—|
|`0x7aafc2`|`0x7aabc2`|`0x3a9fc2`|`3b cf`|`ff ff`|—|
|`0x7aafc4`|`0x7aabc4`|`0x3a9fc4`|`74 0e`|`f6 05`|—|
|`0x7aafc6`|`0x7aabc6`|`0x3a9fc6`|`8b 01`|`c0 1b`|—|
|`0x7aafc8`|`0x7aabc8`|`0x3a9fc8`|`8b 50 04`|`fe 00 01`|—|
|`0x7aafcb`|`0x7aabcb`|`0x3a9fcb`|`53`|`75`|—|
|`0x7aafcc`|`0x7aabcc`|`0x3a9fcc`|`ff d2`|`23 83`|—|
|`0x7aafce`|`0x7aabce`|`0x3a9fce`|`89 3d 38 a8 fb 00`|`0d c0 1b fe 00 01`|—|
|`0x7aafd4`|`0x7aabd4`|`0x3a9fd4`|`83 ce ff`|`c7 45 fc`|—|

本來源27列，T01記錄的exact matches=27；本表算出0列E8目標。來源仍為T01退回的 FAILED；下一步需從真正函式入口重建 reachable CFG、caller/callee、ABI、所有型別與原稿肯定主張。不能因一個位址表完成而標RESOLVED。
