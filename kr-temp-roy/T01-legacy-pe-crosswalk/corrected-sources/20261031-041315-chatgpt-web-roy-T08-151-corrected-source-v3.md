# T08-151 — T01 LEGACY-MAPPING 原始FAILED報告的保守修正版v3：shared-control強弱引用與析構順序

**研究者** chatgpt-web roy；2026-10-31 Asia/Taipei；一手檔KR Tartaros.bin (12,472,320 bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)；PE .text VA401000/raw400⇒code raw=VA−400C00；.rdata VA BD2000/raw7D0600。非code絕對常數／vtable表值不能機械減0x400。

## 明確取代的舊來源和退回範圍

**原稿保留原地並維持T01 FAILED**：`kr-temp-roy/20261027-224426-chatgpt-web-roy-T08-151-control-block-two-stage-release-and-host-dispatch-boundaries.md`；blob `d16ed4d133e88986f1f5867d287b2f44934f89a9`；SHA256 `19b2d083511ae8cd297ef86cc237a2ba64885af794b83c0638484f8ccadf9b99`。這是 `T01-RETURN-T08-LEGACY-MAPPING-001` 作者端**替代新source**，不沿用舊原稿未在此重證的肯定主張。

本版本將「有效函式入口被錯誤聲稱為半指令或ABI不符」的判斷明確**撤回**；真PE `0x7A8310=55 8B EC 83 E4 F8`、`0x7A8E10=55 8B EC 83 EC 0C`、`0x4CA660=8B 49 0C 85 C9`、`0x7A3920=85 C9 74 09`；這些在原始BIN是有效入口，不是壞vtable。0x7A63C0為CDoll primary表欄+8 virtual producer，E8直接搜尋沒有命中不能排除可達。T01本源mapping rows：0條全部有T01 `affine_candidate_equal=true` 的物理位址對照；其他主張須單獨由原生證據審核。

## 限定可引用、已更正的Client結論

0x4E0F60處理holder pair替換及strong→weak條件釋放；0x4CA660/0x7A3920真有效短wrapper；C4F6CC其實下一Ref_count<ModelReleaseSpec> COL不是CDoll第四槽。撤回「目標在半指令」及混用vtable的推論。

**具CFG/RTTI/constructor/VTable證據的新原生技術稿**：[20261031-023600-chatgpt-web-roy-T08-148-151-Host-allocation-control-pair-native-PE-revision.md](../../20261031-023600-chatgpt-web-roy-T08-148-151-Host-allocation-control-pair-native-PE-revision.md)；[T08-152獨立原生真PE table邊界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)、[134～151交付](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)。只承認上述有界內容；其餘歷史舊主張，包括錯位的caller、未核的helper名稱、原版Server決策與全體生命週期安全，**在本新版本正式撤回／UNKNOWN**。

**明示限制**：不能從靜態局部稱strong/weak引用全局沒有UAF；B entry仍為借用。

## 本篇T01真PE錯行對照：0行

本來源無T01的逐列mapping-findings；下方列舉本次獨立原始BIN重核的真PE函式入口及hex，作為該篇替代source的可重現核驗錨點。

## 新獨立BIN-first入口hex重核（非舊T01表）

- `0x4CA660`：`8b 49 0c 85 c9 74 08 8b 01 8b 10 6a 01 ff d2 c3`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。
- `0x7A3920`：`85 c9 74 09 8b 01 8b 50 08 6a 01 ff d2 c3`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。
- `0x4E0F60`：`55 8b ec 83 ec 0c 56 8d 75 f8`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。

## 再驗／完成責任分離

**已證Client**：本篇§限定source中可引用的具體函式/表界/資料流；**Client仍待**：不能從靜態局部稱strong/weak引用全局沒有UAF；B entry仍為借用。；**Server待開發**：依T02證實wire而不是此Client內部候選排序或record registry猜原版Server；**跨功能/待遊玩驗證**：T01逐項對本**新blob**審核，T06/T07/T14場景和S00政策/實機另行驗證。

**狀態判定**：此為新的、有意收窄肯定主張的作者端修正版，**不能**自行代表T01 FULL-PASS/LEGACY RESOLVED。歷史版本FAILED不刪，未來如T01判定仍不足，須按具體原生爭點再修。T08-202不因本次T01勘誤推進而完成。
