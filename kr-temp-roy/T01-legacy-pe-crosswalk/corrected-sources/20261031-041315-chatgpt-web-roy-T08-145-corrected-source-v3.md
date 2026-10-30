# T08-145 — T01 LEGACY-MAPPING-001 原稿全文主張取代版 v3：Host CDoll constructor與secondary vfptr

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei。原始KR `Tartaros.bin`：12,472,320bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA0x401000/raw0x400⇒code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。**rdata DWORD本身為絕對函式位址，不可從table值扣0x400。**

## 失效歷史和replacement scope

- 原來源 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-145-embedded-vptr-construction-candidate.md`，Git blob `f65fa24deba3bb11bb7e95c4fa04468b27b10f06`，SHA256 `f91d72b3726b1b8a7e9dc87bf5fc1679a6e2e8010da196a7312d7a4ffa14881b`，保留為**FAILED**；不破壞、不改寫。
- T01正式退回 `T01-RETURN-T08-LEGACY-MAPPING-001`。原稿wrong raw0 instruction decoding/call boundary/ABI導致含code VA的原生肯定主張不可繼承。本v3把所有超出下面**已明定有界主張**的舊主張正式**撤回為UNKNOWN**，以重新列出保守結論及完整來源映射的**新技術來源**交T01複驗。
- T01既有mapping-findings對此篇38列全有真PE minus-0x400 byte match；只重定位被該source實際證實的code-row（T01前手核驗），並非連同vtable/immediate/common data address全部平移。

## 修正後可檢驗的原生結論

原件RTTI確認所謂Host是IS3D::CDoll；0x7A4C50建構，寫CDoll+0x0C vfptr 0xC4F6C0；其+4/+8真正入口分別7A8310、7A8E10。舊+0x400錯位scan導致「指令中段」反證**撤回**。

**根入口／dataflow／反例的完整BIN-first支援稿**：[20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md](../../20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md)，及[獨立RTTI/COL續證](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；不得把本段限定關係提升成Server生成規則。

**獨立語義反證（T01明示）**：The quoted vtable code targets conflict with valid instruction entry/ABI.；T01決定 `RETRACT_FALSE_ENTRY_CONFLICT`。本版明確撤回「0x7A8310/0x7A8E10/0x4CA660/0x7A3920落在指令中段」等舊判斷；分別在真PE 7A8310=55 8B EC 83 E4 F8、7A8E10=55 8B EC 83 EC 0C、4CA660=8B 49 0C 85 C9、7A3920=85 C9 74 09等有效入口。

**重要未閉合界線**：embedded借用指標在析構/virtual call期間是否可被其他线程使用不可從局部直接斷言。

## 全部T01明列的錯誤code-row修正版（38列）

每一列byte來自T01的 `mapping-findings.json` 已核Tartaros.bin資料；E8/E9用**真VA+len+有號位移**計算，不引用舊反組譯的相對目的地。這個表屬機器碼座標與直接rel32層次；並不單獨證明完整入口CFG或間接vtable動態型別。對不在表內的原稿句子一律不沿用，避免「局部修碼、其餘舊文字仍錯」問題。

|舊VA（T01 FAILED）|新真PE VA|相同原始bytes|direct E8/E9真target|
|---|---|---|---|
|0x7a5077|0x7a4c77|`8b 75 08`|—|
|0x7a507a|0x7a4c7a|`33 db`|—|
|0x7a507c|0x7a4c7c|`89 5d fc`|—|
|0x7a507f|0x7a4c7f|`c7 46 04 4c f6 c4 00`|—|
|0x7a5086|0x7a4c86|`c7 46 08 78 f8 c0 00`|—|
|0x7a508d|0x7a4c8d|`c7 46 0c 6c f6 c4 00`|—|
|0x7a5094|0x7a4c94|`89 5e 10`|—|
|0x7a5097|0x7a4c97|`89 5e 14`|—|
|0x7a509a|0x7a4c9a|`c6 45 fc 04`|—|
|0x7a509e|0x7a4c9e|`8b 45 0c`|—|
|0x7a50a1|0x7a4ca1|`8d 4e 2c`|—|
|0x7a50a4|0x7a4ca4|`51`|—|
|0x7a50a5|0x7a4ca5|`c7 06 7c f6 c4 00`|—|
|0x7a50ab|0x7a4cab|`c7 46 04 90 f6 c4 00`|—|
|0x7a50b2|0x7a4cb2|`c7 46 08 b0 f6 c4 00`|—|
|0x7a50b9|0x7a4cb9|`c7 46 0c c0 f6 c4 00`|—|
|0x7a50c0|0x7a4cc0|`89 46 18`|—|
|0x7a50c3|0x7a4cc3|`89 5e 1c`|—|
|0x7a50c6|0x7a4cc6|`88 5e 20`|—|
|0x7a50c9|0x7a4cc9|`89 5e 24`|—|
|0x7a50cc|0x7a4ccc|`c6 46 28 01`|—|
|0x7a50d0|0x7a4cd0|`e8 4b 03 00 00`|0x7A5020|
|0x7a50d5|0x7a4cd5|`c6 45 fc 05`|—|
|0x7a51b9|0x7a4db9|`c6 42 14 01`|—|
|0x7a51bd|0x7a4dbd|`8b 86 80 00 00 00`|—|
|0x7a51c3|0x7a4dc3|`c6 40 15 01`|—|
|0x7a51c7|0x7a4dc7|`c7 86 8c 00 00 00 01`|—|
|0x7a51ce|0x7a4dce|`00 00 00`|—|
|0x7a51d1|0x7a4dd1|`89 9e 90 00 00 00`|—|
|0x7a51f5|0x7a4df5|`c7 86 a8 00 00 00 02`|—|
|0x7a51fc|0x7a4dfc|`00 00 00`|—|
|0x7a51ff|0x7a4dff|`89 9e ac 00 00 00`|—|
|0x7a5205|0x7a4e05|`89 9e b0 00 00 00`|—|
|0x7a52c4|0x7a4ec4|`89 9e 1c 01 00 00`|—|
|0x7a52ca|0x7a4eca|`89 9e 20 01 00 00`|—|
|0x7a52d0|0x7a4ed0|`89 9e 24 01 00 00`|—|
|0x7a52d6|0x7a4ed6|`89 9e 28 01 00 00`|—|
|0x7a52dc|0x7a4edc|`d9 96 2c 01 00 00`|—|

## 新版合法主張／引用與T01驗收

- **Client已證**：上述精確來源及引用原生證據內明示限定的函式/物件/欄位。
- **Client待逆向**：embedded借用指標在析構/virtual call期間是否可被其他线程使用不可從局部直接斷言。；其他原稿未在本v3具體列出的功能、ABI與生存期亦均為未知，非已通過。
- **Server待開發**：需依T02已驗wire設計，不推原版Server決策。
- **跨功能／遊玩**：T01需以本新blob完成獨立FULL-PASS驗證；跨T02/T06/T07/T14與S00規格，及動態場景測試另算。
- **狀態**：本稿為**作者端修訂提交候選**；沒有任何權限宣告已獲T01審核，舊版本仍FAILED；整個LEGACY-MAPPING-001在T01獨立驗收之前維持NEEDS_FIX。
