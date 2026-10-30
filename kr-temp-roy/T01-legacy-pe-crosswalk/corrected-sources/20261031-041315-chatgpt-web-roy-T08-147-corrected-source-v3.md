# T08-147 — T01 LEGACY-MAPPING 原始FAILED報告的保守修正版v3：CDoll secondary析構vptr與借用指標

**研究者** chatgpt-web roy；2026-10-31 Asia/Taipei；一手檔KR Tartaros.bin (12,472,320 bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)；PE .text VA401000/raw400⇒code raw=VA−400C00；.rdata VA BD2000/raw7D0600。非code絕對常數／vtable表值不能機械減0x400。

## 明確取代的舊來源和退回範圍

**原稿保留原地並維持T01 FAILED**：`kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-147-subobject-vptr-destruction-lifetime-boundary.md`；blob `795ae00b864bfb7929546313975550b437dbdab1`；SHA256 `c7cbb0e28060c28ffadb6823aaad86f35835a8d7253c459d2d73417335d973e9`。這是 `T01-RETURN-T08-LEGACY-MAPPING-001` 作者端**替代新source**，不沿用舊原稿未在此重證的肯定主張。

本版本將「有效函式入口被錯誤聲稱為半指令或ABI不符」的判斷明確**撤回**；真PE `0x7A8310=55 8B EC 83 E4 F8`、`0x7A8E10=55 8B EC 83 EC 0C`、`0x4CA660=8B 49 0C 85 C9`、`0x7A3920=85 C9 74 09`；這些在原始BIN是有效入口，不是壞vtable。0x7A63C0為CDoll primary表欄+8 virtual producer，E8直接搜尋沒有命中不能排除可達。T01本源mapping rows：43條全部有T01 `affine_candidate_equal=true` 的物理位址對照；其他主張須單獨由原生證據審核。

## 限定可引用、已更正的Client結論

真0x7A5651回寫embedded CDoll secondary vptr到0xC4F66C；其後析構/record/control pointer釋放須與另一路B vector持有的CDoll+0x0C借用指標分開。7A8310/7A8E10是有效PE入口，舊mid-instruction推論撤回。

**具CFG/RTTI/constructor/VTable證據的新原生技術稿**：[20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md](../../20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md)；[T08-152獨立原生真PE table邊界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)、[134～151交付](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)。只承認上述有界內容；其餘歷史舊主張，包括錯位的caller、未核的helper名稱、原版Server決策與全體生命週期安全，**在本新版本正式撤回／UNKNOWN**。

**明示限制**：不能從一個析構寫vptr處即判定runtime懸空或保證無競態。

## 本篇T01真PE錯行對照：43行

|old VA|PE correct VA|native bytes (T01 provenance)|E8/E9 target recomputed|
|---|---|---|---|
|0x7a5a26|0x7a5626|`8d 53 2c`|—|
|0x7a5a29|0x7a5629|`52`|—|
|0x7a5a2a|0x7a562a|`c6 45 fc 04`|—|
|0x7a5a2e|0x7a562e|`e8 ed fa ff ff`|0x7A5120|
|0x7a5a33|0x7a5633|`c6 45 fc 03`|—|
|0x7a5a37|0x7a5637|`8b 4b 14`|—|
|0x7a5a3a|0x7a563a|`85 c9`|—|
|0x7a5a3c|0x7a563c|`74 13`|—|
|0x7a5a3e|0x7a563e|`8d 41 08`|—|
|0x7a5a41|0x7a5641|`83 ca ff`|—|
|0x7a5a44|0x7a5644|`f0 0f c1 10`|—|
|0x7a5a48|0x7a5648|`75 07`|—|
|0x7a5a4a|0x7a564a|`8b 01`|—|
|0x7a5a4c|0x7a564c|`8b 50 04`|—|
|0x7a5a4f|0x7a564f|`ff d2`|—|
|0x7a5a51|0x7a5651|`c7 43 0c 6c f6 c4 00`|—|
|0x7a5a58|0x7a5658|`c7 43 08 78 f8 c0 00`|—|
|0x7a5a5f|0x7a565f|`c7 43 04 4c f6 c4 00`|—|
|0x7a5a66|0x7a5666|`c7 03 68 f4 c4 00`|—|
|0x7a5a6c|0x7a566c|`8b 4d f4`|—|
|0x7a5a6f|0x7a566f|`64 89 0d 00 00 00 00`|—|
|0x7a5a76|0x7a5676|`59`|—|
|0x7a5a77|0x7a5677|`5f`|—|
|0x7a5a78|0x7a5678|`5e`|—|
|0x7a5a79|0x7a5679|`5b`|—|
|0x7a5a7a|0x7a567a|`8b e5`|—|
|0x7a5a7c|0x7a567c|`5d`|—|
|0x7a5a7d|0x7a567d|`c2 04 00`|—|
|0x7a69d9|0x7a65d9|`8b 35 38 a8 fb 00`|—|
|0x7a69df|0x7a65df|`8b 86 b8 00 00 00`|—|
|0x7a69e5|0x7a65e5|`83 c7 0c`|—|
|0x7a69e8|0x7a65e8|`8d 4d ec`|—|
|0x7a69eb|0x7a65eb|`89 7d ec`|—|
|0x7a69ee|0x7a65ee|`3b c8`|—|
|0x7a6a32|0x7a6632|`3b 86 bc 00 00 00`|—|
|0x7a6a38|0x7a6638|`75 0b`|—|
|0x7a6a3a|0x7a663a|`8d 86 b4 00 00 00`|—|
|0x7a6a40|0x7a6640|`e8 eb 12 ff ff`|0x797930|
|0x7a6a45|0x7a6645|`8b 86 b8 00 00 00`|—|
|0x7a6a4b|0x7a664b|`85 c0`|—|
|0x7a6a4d|0x7a664d|`74 02`|—|
|0x7a6a4f|0x7a664f|`89 38`|—|
|0x7a6a51|0x7a6651|`83 86 b8 00 00 00 04`|—|

## 再驗／完成責任分離

**已證Client**：本篇§限定source中可引用的具體函式/表界/資料流；**Client仍待**：不能從一個析構寫vptr處即判定runtime懸空或保證無競態。；**Server待開發**：依T02證實wire而不是此Client內部候選排序或record registry猜原版Server；**跨功能/待遊玩驗證**：T01逐項對本**新blob**審核，T06/T07/T14場景和S00政策/實機另行驗證。

**狀態判定**：此為新的、有意收窄肯定主張的作者端修正版，**不能**自行代表T01 FULL-PASS/LEGACY RESOLVED。歷史版本FAILED不刪，未來如T01判定仍不足，須按具體原生爭點再修。T08-202不因本次T01勘誤推進而完成。
