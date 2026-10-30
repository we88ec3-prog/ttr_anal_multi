# T08-152 — T01 LEGACY-MAPPING 原始FAILED報告的保守修正版v3：真PE RTTI COL分段、vtable及producer xref

**研究者** chatgpt-web roy；2026-10-31 Asia/Taipei；一手檔KR Tartaros.bin (12,472,320 bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)；PE .text VA401000/raw400⇒code raw=VA−400C00；.rdata VA BD2000/raw7D0600。非code絕對常數／vtable表值不能機械減0x400。

## 明確取代的舊來源和退回範圍

**原稿保留原地並維持T01 FAILED**：`kr-temp-roy/20261027-225400-chatgpt-web-roy-T08-152-vtable-entry-boundary-negative-xrefs.md`；blob `6d50d49aa523a589714a76159169072b2a994145`；SHA256 `c45b741cedea059422e5f2ba09da316d1fdb19b359e75df00d3cbd92d0eb8584`。這是 `T01-RETURN-T08-LEGACY-MAPPING-001` 作者端**替代新source**，不沿用舊原稿未在此重證的肯定主張。

本版本將「有效函式入口被錯誤聲稱為半指令或ABI不符」的判斷明確**撤回**；真PE `0x7A8310=55 8B EC 83 E4 F8`、`0x7A8E10=55 8B EC 83 EC 0C`、`0x4CA660=8B 49 0C 85 C9`、`0x7A3920=85 C9 74 09`；這些在原始BIN是有效入口，不是壞vtable。0x7A63C0為CDoll primary表欄+8 virtual producer，E8直接搜尋沒有命中不能排除可達。T01本源mapping rows：9條全部有T01 `affine_candidate_equal=true` 的物理位址對照；其他主張須單獨由原生證據審核。

## 限定可引用、已更正的Client結論

獨立T01補證已對原始PE RTTI完成分段：CDoll primary0xC4F67C +8=7A63C0，secondary0xC4F6C0 [+0 7AAA90,+4 7A8310,+8 7A8E10]；C4F6CC是下一COL；Ref_count<CDoll>0xC0760C +0=4CA660 +4=7A3920。除明確vtable DWORD命中以外，直接E8掃描零命中不是「不可達」證據。

**具CFG/RTTI/constructor/VTable證據的新原生技術稿**：[20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；[T08-152獨立原生真PE table邊界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)、[134～151交付](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)。只承認上述有界內容；其餘歷史舊主張，包括錯位的caller、未核的helper名稱、原版Server決策與全體生命週期安全，**在本新版本正式撤回／UNKNOWN**。

**明示限制**：需追真scene virtual caller、跨CModel/22桶的因果、borrowed entry的生存期。

## 本篇T01真PE錯行對照：9行

|old VA|PE correct VA|native bytes (T01 provenance)|E8/E9 target recomputed|
|---|---|---|---|
|0x7a8e07|0x7a8a07|`d9 9b b4 00 00 00`|—|
|0x7a8e0d|0x7a8a0d|`d9 83 d8 00 00 00`|—|
|0x7a8e13|0x7a8a13|`de d9`|—|
|0x7a8e15|0x7a8a15|`df e0`|—|
|0x7a391d|0x7a351d|`33 d2`|—|
|0x7a391f|0x7a351f|`83 c4 04`|—|
|0x7a3922|0x7a3522|`3b c2`|—|
|0x7a3924|0x7a3524|`74 2e`|—|
|0x7a3926|0x7a3526|`8b 4e 04`|—|

## 再驗／完成責任分離

**已證Client**：本篇§限定source中可引用的具體函式/表界/資料流；**Client仍待**：需追真scene virtual caller、跨CModel/22桶的因果、borrowed entry的生存期。；**Server待開發**：依T02證實wire而不是此Client內部候選排序或record registry猜原版Server；**跨功能/待遊玩驗證**：T01逐項對本**新blob**審核，T06/T07/T14場景和S00政策/實機另行驗證。

**狀態判定**：此為新的、有意收窄肯定主張的作者端修正版，**不能**自行代表T01 FULL-PASS/LEGACY RESOLVED。歷史版本FAILED不刪，未來如T01判定仍不足，須按具體原生爭點再修。T08-202不因本次T01勘誤推進而完成。
