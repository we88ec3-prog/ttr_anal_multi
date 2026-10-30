# T08-143 — T01 LEGACY-MAPPING-001 原稿全文主張取代版 v3：B vector grow／alias處理

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei。原始KR `Tartaros.bin`：12,472,320bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA0x401000/raw0x400⇒code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。**rdata DWORD本身為絕對函式位址，不可從table值扣0x400。**

## 失效歷史和replacement scope

- 原來源 `kr-temp-roy/20261027-210935-chatgpt-web-roy-T08-143-B-vector-growth-and-alias-safety.md`，Git blob `0c5f49419fdb626eca8d007186bffbe22c4c8349`，SHA256 `0f4ccd229c80d70be28cd0422e29d63ae27ace825cf80a6606890ce9d0c19ba6`，保留為**FAILED**；不破壞、不改寫。
- T01正式退回 `T01-RETURN-T08-LEGACY-MAPPING-001`。原稿wrong raw0 instruction decoding/call boundary/ABI導致含code VA的原生肯定主張不可繼承。本v3把所有超出下面**已明定有界主張**的舊主張正式**撤回為UNKNOWN**，以重新列出保守結論及完整來源映射的**新技術來源**交T01複驗。
- T01既有mapping-findings對此篇70列全有真PE minus-0x400 byte match；只重定位被該source實際證實的code-row（T01前手核驗），並非連同vtable/immediate/common data address全部平移。

## 修正後可檢驗的原生結論

真0x7A63C0 appends +0x0C embedded CDoll entry，grow helper真0x797930；需要保留begin/end/cap分開的指標別名分支，不能直接稱為發新Actor。

**根入口／dataflow／反例的完整BIN-first支援稿**：[20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md](../../20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md)，及[獨立RTTI/COL續證](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)；不得把本段限定關係提升成Server生成規則。

**此源沒有單獨新增T01語義反證**；仍保留原生函式邊界/存活期限制。

**重要未閉合界線**：無實機證明每種alias都無UAF；capacity/entry生存期仍待下游。

## 全部T01明列的錯誤code-row修正版（70列）

每一列byte來自T01的 `mapping-findings.json` 已核Tartaros.bin資料；E8/E9用**真VA+len+有號位移**計算，不引用舊反組譯的相對目的地。這個表屬機器碼座標與直接rel32層次；並不單獨證明完整入口CFG或間接vtable動態型別。對不在表內的原稿句子一律不沿用，避免「局部修碼、其餘舊文字仍錯」問題。

|舊VA（T01 FAILED）|新真PE VA|相同原始bytes|direct E8/E9真target|
|---|---|---|---|
|0x7a69d9|0x7a65d9|`8b 35 38 a8 fb 00`|—|
|0x7a69df|0x7a65df|`8b 86 b8 00 00 00`|—|
|0x7a69e5|0x7a65e5|`83 c7 0c`|—|
|0x7a69e8|0x7a65e8|`8d 4d ec`|—|
|0x7a69eb|0x7a65eb|`89 7d ec`|—|
|0x7a69ee|0x7a65ee|`3b c8`|—|
|0x7a69f0|0x7a65f0|`73 40`|—|
|0x7a69f2|0x7a65f2|`8b 8e b4 00 00 00`|—|
|0x7a69f8|0x7a65f8|`8d 55 ec`|—|
|0x7a69fb|0x7a65fb|`3b ca`|—|
|0x7a69fd|0x7a65fd|`77 33`|—|
|0x7a69ff|0x7a65ff|`8b fa`|—|
|0x7a6a01|0x7a6601|`2b f9`|—|
|0x7a6a03|0x7a6603|`c1 ff 02`|—|
|0x7a6a06|0x7a6606|`3b 86 bc 00 00 00`|—|
|0x7a6a0c|0x7a660c|`75 0b`|—|
|0x7a6a0e|0x7a660e|`8d 86 b4 00 00 00`|—|
|0x7a6a14|0x7a6614|`e8 17 13 ff ff`|0x797930|
|0x7a6a19|0x7a6619|`8b 86 b4 00 00 00`|—|
|0x7a6a1f|0x7a661f|`8d 3c b8`|—|
|0x7a6a22|0x7a6622|`8b 86 b8 00 00 00`|—|
|0x7a6a28|0x7a6628|`85 c0`|—|
|0x7a6a2a|0x7a662a|`74 25`|—|
|0x7a6a2c|0x7a662c|`8b 0f`|—|
|0x7a6a2e|0x7a662e|`89 08`|—|
|0x7a6a30|0x7a6630|`eb 1f`|—|
|0x7a6a32|0x7a6632|`3b 86 bc 00 00 00`|—|
|0x7a6a38|0x7a6638|`75 0b`|—|
|0x7a6a3a|0x7a663a|`8d 86 b4 00 00 00`|—|
|0x7a6a40|0x7a6640|`e8 eb 12 ff ff`|0x797930|
|0x7a6a45|0x7a6645|`8b 86 b8 00 00 00`|—|
|0x7a6a4b|0x7a664b|`85 c0`|—|
|0x7a6a4d|0x7a664d|`74 02`|—|
|0x7a6a4f|0x7a664f|`89 38`|—|
|0x7a6a51|0x7a6651|`83 86 b8 00 00 00 04`|—|
|0x7a6a58|0x7a6658|`e8 73 19 09 00`|0x837FD0|
|0x797d30|0x797930|`56`|—|
|0x797d31|0x797931|`8b f0`|—|
|0x797d33|0x797933|`8b 16`|—|
|0x797d35|0x797935|`8b 46 04`|—|
|0x797d38|0x797938|`2b c2`|—|
|0x797d3a|0x79793a|`c1 f8 02`|—|
|0x797d3d|0x79793d|`3d fe ff ff 3f`|—|
|0x797d42|0x797942|`76 0a`|—|
|0x797d44|0x797944|`68 78 23 bf 00`|—|
|0x797d49|0x797949|`e8 e2 61 0e 00`|0x87DB30|
|0x797d4e|0x79794e|`8b 4e 08`|—|
|0x797d51|0x797951|`2b ca`|—|
|0x797d53|0x797953|`40`|—|
|0x797d54|0x797954|`c1 f9 02`|—|
|0x797d57|0x797957|`3b c1`|—|
|0x797d59|0x797959|`76 23`|—|
|0x797d5b|0x79795b|`57`|—|
|0x797d5c|0x79795c|`8b d1`|—|
|0x797d5e|0x79795e|`d1 ea`|—|
|0x797d60|0x797960|`bf ff ff ff 3f`|—|
|0x797d65|0x797965|`2b fa`|—|
|0x797d67|0x797967|`3b f9`|—|
|0x797d69|0x797969|`5f`|—|
|0x797d6a|0x79796a|`73 04`|—|
|0x797d6c|0x79796c|`33 c9`|—|
|0x797d6e|0x79796e|`eb 02`|—|
|0x797d70|0x797970|`03 ca`|—|
|0x797d72|0x797972|`3b c8`|—|
|0x797d74|0x797974|`73 02`|—|
|0x797d76|0x797976|`8b c8`|—|
|0x797d78|0x797978|`51`|—|
|0x797d79|0x797979|`e8 02 00 00 00`|0x797980|
|0x797d7e|0x79797e|`5e`|—|
|0x797d7f|0x79797f|`c3`|—|

## 新版合法主張／引用與T01驗收

- **Client已證**：上述精確來源及引用原生證據內明示限定的函式/物件/欄位。
- **Client待逆向**：無實機證明每種alias都無UAF；capacity/entry生存期仍待下游。；其他原稿未在本v3具體列出的功能、ABI與生存期亦均為未知，非已通過。
- **Server待開發**：需依T02已驗wire設計，不推原版Server決策。
- **跨功能／遊玩**：T01需以本新blob完成獨立FULL-PASS驗證；跨T02/T06/T07/T14與S00規格，及動態場景測試另算。
- **狀態**：本稿為**作者端修訂提交候選**；沒有任何權限宣告已獲T01審核，舊版本仍FAILED；整個LEGACY-MAPPING-001在T01獨立驗收之前維持NEEDS_FIX。
