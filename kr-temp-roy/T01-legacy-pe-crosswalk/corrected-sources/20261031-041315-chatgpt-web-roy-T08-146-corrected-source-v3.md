# T08-146 — T01 LEGACY-MAPPING-001 原稿全文主張取代版 v3：正確vtable入口和RTTI COL表界

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei。原始KR `Tartaros.bin`：12,472,320bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA0x401000/raw0x400⇒code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。**rdata DWORD本身為絕對函式位址，不可從table值扣0x400。**

## 失效歷史和replacement scope

- 原來源 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-146-vtable-slots-and-rdata-section-mapping.md`，Git blob `c80e130172d127172992f00f044a5af89e994174`，SHA256 `be5f18390b669a16b02d056e1e9dc5805c8fc29d2abce7b0abf34cc0b991d16e`，保留為**FAILED**；不破壞、不改寫。
- T01正式退回 `T01-RETURN-T08-LEGACY-MAPPING-001`。原稿wrong raw0 instruction decoding/call boundary/ABI導致含code VA的原生肯定主張不可繼承。本v3把所有超出下面**已明定有界主張**的舊主張正式**撤回為UNKNOWN**，以重新列出保守結論及完整來源映射的**新技術來源**交T01複驗。
- T01既有mapping-findings對此篇41列全有真PE minus-0x400 byte match；只重定位被該source實際證實的code-row（T01前手核驗），並非連同vtable/immediate/common data address全部平移。

## 修正後可檢驗的原生結論

CDoll secondary table 0xC4F6C0真三method [+0 7AAA90,+4 7A8310,+8 7A8E10]，C4F6CC為下一個std::tr1::_Ref_count<ModelReleaseSpec> COL指標，不是第四method；4CA660和7A3920均是有效PE stub，不能再稱為半指令。

**根入口／dataflow／反例的完整BIN-first支援稿**：[20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)，及[獨立RTTI/COL續證](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；不得把本段限定關係提升成Server生成規則。

**獨立語義反證（T01明示）**：The quoted vtable code targets conflict with valid instruction entry/ABI.；T01決定 `RETRACT_FALSE_ENTRY_CONFLICT`。本版明確撤回「0x7A8310/0x7A8E10/0x4CA660/0x7A3920落在指令中段」等舊判斷；分別在真PE 7A8310=55 8B EC 83 E4 F8、7A8E10=55 8B EC 83 EC 0C、4CA660=8B 49 0C 85 C9、7A3920=85 C9 74 09等有效入口。

**重要未閉合界線**：不同類別vtable的slot相同不代表同一語義；仍待真dynamic dispatch site。

## 全部T01明列的錯誤code-row修正版（41列）

每一列byte來自T01的 `mapping-findings.json` 已核Tartaros.bin資料；E8/E9用**真VA+len+有號位移**計算，不引用舊反組譯的相對目的地。這個表屬機器碼座標與直接rel32層次；並不單獨證明完整入口CFG或間接vtable動態型別。對不在表內的原稿句子一律不沿用，避免「局部修碼、其餘舊文字仍錯」問題。

|舊VA（T01 FAILED）|新真PE VA|相同原始bytes|direct E8/E9真target|
|---|---|---|---|
|0x7a8300|0x7a7f00|`55`|—|
|0x7a8301|0x7a7f01|`8b ec`|—|
|0x7a8303|0x7a7f03|`83 ec 4c`|—|
|0x7a8306|0x7a7f06|`a1 20 1f d6 00`|—|
|0x7a830b|0x7a7f0b|`33 c5`|—|
|0x7a830d|0x7a7f0d|`89 45 f8`|—|
|0x7a8310|0x7a7f10|`83 bf ac 00 00 00 00`|—|
|0x7a8317|0x7a7f17|`8b 45 08`|—|
|0x7a831a|0x7a7f1a|`d9 00`|—|
|0x7a831c|0x7a7f1c|`53`|—|
|0x7a831d|0x7a7f1d|`d9 5d e0`|—|
|0x7a8320|0x7a7f20|`56`|—|
|0x7a8321|0x7a7f21|`d9 40 04`|—|
|0x7a8324|0x7a7f24|`d9 5d e4`|—|
|0x7a8327|0x7a7f27|`8b 55 e4`|—|
|0x7a832a|0x7a7f2a|`d9 40 08`|—|
|0x7a832d|0x7a7f2d|`8b 45 e0`|—|
|0x7a8330|0x7a7f30|`d9 5d e8`|—|
|0x7a8333|0x7a7f33|`89 45 b8`|—|
|0x7a8336|0x7a7f36|`d9 01`|—|
|0x7a8338|0x7a7f38|`8b 45 e8`|—|
|0x7a833b|0x7a7f3b|`d9 5d e0`|—|
|0x7a833e|0x7a7f3e|`89 55 bc`|—|
|0x7a8341|0x7a7f41|`d9 41 04`|—|
|0x7a8344|0x7a7f44|`89 45 c0`|—|
|0x7a8347|0x7a7f47|`d9 5d e4`|—|
|0x7a834a|0x7a7f4a|`8b 55 e4`|—|
|0x7a834d|0x7a7f4d|`d9 41 08`|—|
|0x7a8350|0x7a7f50|`8b 4d e0`|—|
|0x7a8353|0x7a7f53|`d9 5d e8`|—|
|0x7a8356|0x7a7f56|`8b 45 e8`|—|
|0x7a8359|0x7a7f59|`89 4d c4`|—|
|0x7a835c|0x7a7f5c|`89 55 c8`|—|
|0x7a835f|0x7a7f5f|`89 45 cc`|—|
|0x7a8362|0x7a7f62|`74 27`|—|
|0x7a8364|0x7a7f64|`8b 47 1c`|—|
|0x7a8367|0x7a7f67|`85 c0`|—|
|0x7a8369|0x7a7f69|`74 20`|—|
|0x7a836b|0x7a7f6b|`83 78 14 00`|—|
|0x7a836f|0x7a7f6f|`74 1a`|—|
|0x7a8371|0x7a7f71|`8b 8f ac 00 00 00`|—|

## 新版合法主張／引用與T01驗收

- **Client已證**：上述精確來源及引用原生證據內明示限定的函式/物件/欄位。
- **Client待逆向**：不同類別vtable的slot相同不代表同一語義；仍待真dynamic dispatch site。；其他原稿未在本v3具體列出的功能、ABI與生存期亦均為未知，非已通過。
- **Server待開發**：需依T02已驗wire設計，不推原版Server決策。
- **跨功能／遊玩**：T01需以本新blob完成獨立FULL-PASS驗證；跨T02/T06/T07/T14與S00規格，及動態場景測試另算。
- **狀態**：本稿為**作者端修訂提交候選**；沒有任何權限宣告已獲T01審核，舊版本仍FAILED；整個LEGACY-MAPPING-001在T01獨立驗收之前維持NEEDS_FIX。
