# T08-149 — T01 LEGACY-MAPPING 原始FAILED報告的保守修正版v3：CDoll primary B producer與secondary record ABI

**研究者** chatgpt-web roy；2026-10-31 Asia/Taipei；一手檔KR Tartaros.bin (12,472,320 bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)；PE .text VA401000/raw400⇒code raw=VA−400C00；.rdata VA BD2000/raw7D0600。非code絕對常數／vtable表值不能機械減0x400。

## 明確取代的舊來源和退回範圍

**原稿保留原地並維持T01 FAILED**：`kr-temp-roy/20261027-222934-chatgpt-web-roy-T08-149-ctor-callers-and-b-entry-vtable-abi.md`；blob `7743ed6e56742780d400627bfbbffae316defec8`；SHA256 `1a71276cdc2d168345dca1957b2cc0a4a453ad1b3da581a974158065308d5367`。這是 `T01-RETURN-T08-LEGACY-MAPPING-001` 作者端**替代新source**，不沿用舊原稿未在此重證的肯定主張。

本版本將「有效函式入口被錯誤聲稱為半指令或ABI不符」的判斷明確**撤回**；真PE `0x7A8310=55 8B EC 83 E4 F8`、`0x7A8E10=55 8B EC 83 EC 0C`、`0x4CA660=8B 49 0C 85 C9`、`0x7A3920=85 C9 74 09`；這些在原始BIN是有效入口，不是壞vtable。0x7A63C0為CDoll primary表欄+8 virtual producer，E8直接搜尋沒有命中不能排除可達。T01本源mapping rows：0條全部有T01 `affine_candidate_equal=true` 的物理位址對照；其他主張須單獨由原生證據審核。

## 限定可引用、已更正的Client結論

CDoll主vptr 0xC4F67C +8 真0x7A63C0，是B producer直接持於vtable的唯一DWORD來源（raw0x84DC84）。secondary vptr 0xC4F6C0 +4 7A8310（record execute）/+8 7A8E10（3D平方距離）；舊針對7A8310不完整指令「不相容ABI」判斷**撤回**。

**具CFG/RTTI/constructor/VTable證據的新原生技術稿**：[20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；[T08-152獨立原生真PE table邊界](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)、[134～151交付](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)。只承認上述有界內容；其餘歷史舊主張，包括錯位的caller、未核的helper名稱、原版Server決策與全體生命週期安全，**在本新版本正式撤回／UNKNOWN**。

**明示限制**：尚缺真正primary slot+8的scene caller及所有runtime type，B→22桶因果未證。

## 本篇T01真PE錯行對照：0行

本來源無T01的逐列mapping-findings；下方列舉本次獨立原始BIN重核的真PE函式入口及hex，作為該篇替代source的可重現核驗錨點。

## 新獨立BIN-first入口hex重核（非舊T01表）

- `0x7A63C0`：`55 8b ec 6a ff 68 76 bd 92 00`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。
- `0x7A8E10`：`55 8b ec 83 ec 0c 8b 45 08`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。
- `0x7A3920`：`85 c9 74 09 8b 01 8b 50 08 6a 01 ff d2 c3`（真PE .text raw=VA−0x400C00，2026-10-31以本地原件重新核對）；僅此片段未構成完整CFG證明。

## 再驗／完成責任分離

**已證Client**：本篇§限定source中可引用的具體函式/表界/資料流；**Client仍待**：尚缺真正primary slot+8的scene caller及所有runtime type，B→22桶因果未證。；**Server待開發**：依T02證實wire而不是此Client內部候選排序或record registry猜原版Server；**跨功能/待遊玩驗證**：T01逐項對本**新blob**審核，T06/T07/T14場景和S00政策/實機另行驗證。

**狀態判定**：此為新的、有意收窄肯定主張的作者端修正版，**不能**自行代表T01 FULL-PASS/LEGACY RESOLVED。歷史版本FAILED不刪，未來如T01判定仍不足，須按具體原生爭點再修。T08-202不因本次T01勘誤推進而完成。
