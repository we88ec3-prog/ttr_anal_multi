# T08-144 — T01 LEGACY-MAPPING-001 原稿全文主張取代版 v3：B producer→consumer和slot界線

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei。原始KR `Tartaros.bin`：12,472,320bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA0x401000/raw0x400⇒code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。**rdata DWORD本身為絕對函式位址，不可從table值扣0x400。**

## 失效歷史和replacement scope

- 原來源 `kr-temp-roy/20261027-210935-chatgpt-web-roy-T08-144-B-producer-consumer-link-and-vtable-limit.md`，Git blob `d1af4d9f33eaf7f55c72cc98f6c79169d867f58b`，SHA256 `fb859db1033cd807a4ff43c2ce776505a50d54e7406b9b4c50b1e380807645ba`，保留為**FAILED**；不破壞、不改寫。
- T01正式退回 `T01-RETURN-T08-LEGACY-MAPPING-001`。原稿wrong raw0 instruction decoding/call boundary/ABI導致含code VA的原生肯定主張不可繼承。本v3把所有超出下面**已明定有界主張**的舊主張正式**撤回為UNKNOWN**，以重新列出保守結論及完整來源映射的**新技術來源**交T01複驗。
- T01既有mapping-findings對此篇48列全有真PE minus-0x400 byte match；只重定位被該source實際證實的code-row（T01前手核驗），並非連同vtable/immediate/common data address全部平移。

## 修正後可檢驗的原生結論

CDoll primary+8=7A63C0寫B，B consumer真7BB240依entry vtable+8 score、+4 execute，在CDoll embedded+0x0C可對上7A8E10與7A8310；嚴禁把vtable+0x0C跨到下一個RTTI COL。

**根入口／dataflow／反例的完整BIN-first支援稿**：[20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md](../../20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md)，及[獨立RTTI/COL續證](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；不得把本段限定關係提升成Server生成規則。

**此源沒有單獨新增T01語義反證**；仍保留原生函式邊界/存活期限制。

**重要未閉合界線**：B→22桶因果、其他runtime entry型別及player結果仍未閉合。

## 全部T01明列的錯誤code-row修正版（48列）

每一列byte來自T01的 `mapping-findings.json` 已核Tartaros.bin資料；E8/E9用**真VA+len+有號位移**計算，不引用舊反組譯的相對目的地。這個表屬機器碼座標與直接rel32層次；並不單獨證明完整入口CFG或間接vtable動態型別。對不在表內的原稿句子一律不沿用，避免「局部修碼、其餘舊文字仍錯」問題。

|舊VA（T01 FAILED）|新真PE VA|相同原始bytes|direct E8/E9真target|
|---|---|---|---|
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
|0x7bb664|0x7bb264|`8b 86 b8 00 00 00`|—|
|0x7bb66a|0x7bb26a|`2b 86 b4 00 00 00`|—|
|0x7bb670|0x7bb270|`8b 9e c4 00 00 00`|—|
|0x7bb676|0x7bb276|`c1 f8 02`|—|
|0x7bb679|0x7bb279|`3b d8`|—|
|0x7bb67b|0x7bb27b|`76 02`|—|
|0x7bb67d|0x7bb27d|`8b d8`|—|
|0x7bb6f0|0x7bb2f0|`8b 8e b4 00 00 00`|—|
|0x7bb6f6|0x7bb2f6|`8b 0c b9`|—|
|0x7bb6f9|0x7bb2f9|`8b 11`|—|
|0x7bb6fb|0x7bb2fb|`8b 42 04`|—|
|0x7bb6fe|0x7bb2fe|`ff d0`|—|
|0x7bb700|0x7bb300|`47`|—|
|0x7bb701|0x7bb301|`3b fb`|—|
|0x7bb703|0x7bb303|`72 eb`|—|
|0x7bbc76|0x7bb876|`8b 45 08`|—|
|0x7bbc79|0x7bb879|`8b 0e`|—|
|0x7bbc7b|0x7bb87b|`8b 11`|—|
|0x7bbc7d|0x7bb87d|`8b 52 08`|—|
|0x7bbc80|0x7bb880|`53`|—|
|0x7bbc81|0x7bb881|`8b 1f`|—|
|0x7bbc83|0x7bb883|`89 45 fc`|—|
|0x7bbc86|0x7bb886|`8d 45 0c`|—|
|0x7bbc89|0x7bb889|`50`|—|
|0x7bbc8a|0x7bb88a|`ff d2`|—|
|0x7bbc8c|0x7bb88c|`dd 5d f4`|—|
|0x7bbc8f|0x7bb88f|`8b 03`|—|
|0x7bbc91|0x7bb891|`8b 50 08`|—|
|0x7bbc94|0x7bb894|`8d 4d 0c`|—|
|0x7bbc97|0x7bb897|`51`|—|
|0x7bbc98|0x7bb898|`8b cb`|—|
|0x7bbc9a|0x7bb89a|`ff d2`|—|
|0x7bbc9c|0x7bb89c|`dc 5d f4`|—|

## 新版合法主張／引用與T01驗收

- **Client已證**：上述精確來源及引用原生證據內明示限定的函式/物件/欄位。
- **Client待逆向**：B→22桶因果、其他runtime entry型別及player結果仍未閉合。；其他原稿未在本v3具體列出的功能、ABI與生存期亦均為未知，非已通過。
- **Server待開發**：需依T02已驗wire設計，不推原版Server決策。
- **跨功能／遊玩**：T01需以本新blob完成獨立FULL-PASS驗證；跨T02/T06/T07/T14與S00規格，及動態場景測試另算。
- **狀態**：本稿為**作者端修訂提交候選**；沒有任何權限宣告已獲T01審核，舊版本仍FAILED；整個LEGACY-MAPPING-001在T01獨立驗收之前維持NEEDS_FIX。
