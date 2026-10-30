# T08-133 — T01 LEGACY-MAPPING-001 獨立修正版 v3：registry與vector append

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei；**原始 KR Client** Tartaros.bin, 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA `0x401000`, raw `0x400` ⇒ `raw=VA−0x400C00`；.rdata VA `0xBD2000`, raw `0x7D0600`。原件／版本及修正版分開，不移動或覆寫舊原稿。

## 1. 精確失效原稿與替代裁決

- **歷史原稿，仍FAILED**：`kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-133-record-registry-7E8640.md`；blob `f466864d5317543d7f78863ede38355773eb25b9`；SHA256 `5b6e115eb417d49e9083561ee1bba14f9fc7e900a6edaccc580b2168afdf004a`。
- **T01退回ID**：`T01-RETURN-T08-LEGACY-MAPPING-001`。原稿的錯誤根因是whole-file BIN從file raw0錯當.text code起點，導致指令標籤普遍相對真PE偏 +0x400；原始假code/rel32目標及推論不能逐字保留。若屬真正.rdata DWORD內容，不可一律減0x400。
- **此v3修正版是替代技術來源**：僅以下明列、有原生支持的肯定主張為有效修正主張；原稿其它未重新列入的肯定語句**正式撤回，不供引用**。這是作者側勘誤交件、**不是**T01獨立全文FULL-PASS或LEGACY退回RESOLVED。
- **已完成映射檢查**：T01原始 `mapping-findings.json` 此篇共 127 行，逐行 `affine_candidate_equal=true` 的 127 行；此表只聲稱T01所核對的同byte PE座標，**不能當成每行重新獨立反組譯及ABI驗證**。

## 2. 修正後可引用的函式、owner、資料流與條件

原舊0x7E8640→真0x7E8240 keyed registry；真0x7E86E0→0x7E8A00為查找支線，0x7BB350為通用append helper，不能把所有append都視為同一record owner。

**原生詳細核對**：[`20261031-020700-chatgpt-web-roy-T08-133-LEGACY-MAPPING-PE-registry-revision.md`](../../20261031-020700-chatgpt-web-roy-T08-133-LEGACY-MAPPING-PE-registry-revision.md)。該source提供真PE入口附近機器碼、根CFG／vtable owner，對本篇主張的影響不應用「整篇直平移」取代；同類交叉補證在 [134～151交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[T08-152 RTTI](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**否證／剩餘邊界**：record registry建立與B entry fn4在所有分支必然調用尚未證明。

## 3. 原稿每一個T01已核錯誤code-row的PE定位（共 127 行）

本表欄位依T01已讀取原始BIN `mapping-findings.json` 做精確T08-133 source-row crosswalk；其中direct `E8/E9 rel32` 目標以**新的真PE VA + 5 + signed displacement** 重算，不能複製原稿相對目標。仍須從函式入口驗證CFG和其他跳轉邊界。這裡不是全面代替完整disassembly，也不改任何非code的字面常數或.rdata指標。

|T01原標籤VA|新PE真VA|真PE byte（T01讀BIN）|可重算direct相對目標|
|---|---|---|---|
|0x7e8677|0x7E8277|`8b 45 0c`|—|
|0x7e867a|0x7E827A|`ff 80 cc 3e 00 00`|—|
|0x7e8680|0x7E8280|`8b 5d 08`|—|
|0x7e8683|0x7E8283|`33 d2`|—|
|0x7e8685|0x7E8285|`89 44 24 14`|—|
|0x7e8689|0x7E8289|`8d b8 b0 3e 00 00`|—|
|0x7e868f|0x7E828F|`39 10`|—|
|0x7e8691|0x7E8291|`0f 85 ac 00 00 00`|—|
|0x7e8680|0x7E8280|`8b 5d 08`|—|
|0x7e8683|0x7E8283|`33 d2`|—|
|0x7e8685|0x7E8285|`89 44 24 14`|—|
|0x7e8689|0x7E8289|`8d b8 b0 3e 00 00`|—|
|0x7e868f|0x7E828F|`39 10`|—|
|0x7e8691|0x7E8291|`0f 85 ac 00 00 00`|—|
|0x7e8697|0x7E8297|`83 7f 14 10`|—|
|0x7e869b|0x7E829B|`72 04`|—|
|0x7e8689|0x7E8289|`8d b8 b0 3e 00 00`|—|
|0x7e868f|0x7E828F|`39 10`|—|
|0x7e8691|0x7E8291|`0f 85 ac 00 00 00`|—|
|0x7e8697|0x7E8297|`83 7f 14 10`|—|
|0x7e869b|0x7E829B|`72 04`|—|
|0x7e869d|0x7E829D|`8b 0f`|—|
|0x7e869f|0x7E829F|`eb 02`|—|
|0x7e86a1|0x7E82A1|`8b cf`|—|
|0x7e86d0|0x7E82D0|`50`|—|
|0x7e86d1|0x7E82D1|`8d 4b 04`|—|
|0x7e86d4|0x7E82D4|`c7 44 24 64 00 00 00`|—|
|0x7e86db|0x7E82DB|`00`|—|
|0x7e86dc|0x7E82DC|`e8 ff 03 00 00`|0x7E86E0|
|0x7e86e1|0x7E82E1|`bb 10 00 00 00`|—|
|0x7e86e6|0x7E82E6|`c7 44 24 60 ff ff ff`|—|
|0x7e86ed|0x7E82ED|`ff`|—|
|0x7e8718|0x7E8318|`83 3e 00`|—|
|0x7e871b|0x7E831B|`0f 85 d2 00 00 00`|—|
|0x7e8721|0x7E8321|`c7 06 01 00 00 00`|—|
|0x7e8727|0x7E8327|`39 5f 14`|—|
|0x7e872a|0x7E832A|`72 04`|—|
|0x7e872c|0x7E832C|`8b 17`|—|
|0x7e872e|0x7E832E|`eb 02`|—|
|0x7e8730|0x7E8330|`8b d7`|—|
|0x7e8743|0x7E8343|`83 7f 14 10`|—|
|0x7e8747|0x7E8347|`72 04`|—|
|0x7e8749|0x7E8349|`8b 0f`|—|
|0x7e874b|0x7E834B|`eb 02`|—|
|0x7e874d|0x7E834D|`8b cf`|—|
|0x7e874f|0x7E834F|`8b c1`|—|
|0x7e8751|0x7E8351|`c7 44 24 48 0f 00 00`|—|
|0x7e8758|0x7E8358|`00`|—|
|0x7e8788|0x7E8388|`e8 53 03 00 00`|0x7E86E0|
|0x7e878d|0x7E838D|`bb 10 00 00 00`|—|
|0x7e8792|0x7E8392|`c7 44 24 60 ff ff ff`|—|
|0x7e879a|0x7E839A|`8b f0`|—|
|0x7e879c|0x7E839C|`39 5c 24 48`|—|
|0x7e87a0|0x7E83A0|`72 0d`|—|
|0x7e87a2|0x7E83A2|`8b 44 24 34`|—|
|0x7e87f3|0x7E83F3|`8d 44 24 14`|—|
|0x7e87f7|0x7E83F7|`8d 7e 20`|—|
|0x7e87fa|0x7E83FA|`e8 51 2f fd ff`|0x7BB350|
|0x7e87ff|0x7E83FF|`8b 4c 24 58`|—|
|0x7e8803|0x7E8403|`64 89 0d 00 00 00 00`|—|
|0x7e880a|0x7E840A|`59`|—|
|0x7e880b|0x7E840B|`5f`|—|
|0x7e880c|0x7E840C|`5e`|—|
|0x7e87fa|0x7E83FA|`e8 51 2f fd ff`|0x7BB350|
|0x7e87ff|0x7E83FF|`8b 4c 24 58`|—|
|0x7e8803|0x7E8403|`64 89 0d 00 00 00 00`|—|
|0x7e880a|0x7E840A|`59`|—|
|0x7e880b|0x7E840B|`5f`|—|
|0x7e880c|0x7E840C|`5e`|—|
|0x7e880d|0x7E840D|`5b`|—|
|0x7e880e|0x7E840E|`8b 4c 24 40`|—|
|0x7e881c|0x7E841C|`c2 08 00`|—|
|0x7e881f|0x7E841F|`cc`|—|
|0x7e8820|0x7E8420|`55`|—|
|0x7e8821|0x7E8421|`8b ec`|—|
|0x7e8823|0x7E8423|`6a ff`|—|
|0x7e8825|0x7E8425|`68 58 78 93 00`|—|
|0x7e882a|0x7E842A|`64 a1 00 00 00 00`|—|
|0x7e8830|0x7E8430|`50`|—|
|0x7a8a0b|0x7A860B|`a1 38 a8 fb 00`|—|
|0x7a8a10|0x7A8610|`8b 88 8c 00 00 00`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a8a17|0x7A8617|`51`|—|
|0x7a8a18|0x7A8618|`e8 23 fc 03 00`|0x7E8240|
|0x7a8a1d|0x7A861D|`8b 4c 24 54`|—|
|0x7a8a21|0x7A8621|`5f`|—|
|0x7a8a22|0x7A8622|`5e`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a8a17|0x7A8617|`51`|—|
|0x7a8a18|0x7A8618|`e8 23 fc 03 00`|0x7E8240|
|0x7a8a1d|0x7A861D|`8b 4c 24 54`|—|
|0x7a8a21|0x7A8621|`5f`|—|
|0x7a8a22|0x7A8622|`5e`|—|
|0x7a8a23|0x7A8623|`5b`|—|
|0x7a8a24|0x7A8624|`33 cc`|—|
|0x7a8a18|0x7A8618|`e8 23 fc 03 00`|0x7E8240|
|0x7a8a1d|0x7A861D|`8b 4c 24 54`|—|
|0x7a8a21|0x7A8621|`5f`|—|
|0x7a8a22|0x7A8622|`5e`|—|
|0x7a8a23|0x7A8623|`5b`|—|
|0x7a8a24|0x7A8624|`33 cc`|—|
|0x7a8a26|0x7A8626|`e8 d6 89 0e 00`|0x891001|
|0x7a8a2b|0x7A862B|`8b e5`|—|
|0x7babd9|0x7BA7D9|`8b 14 99`|—|
|0x7babdc|0x7BA7DC|`8b 42 34`|—|
|0x7babdf|0x7BA7DF|`8b 0d 38 a8 fb 00`|—|
|0x7babe5|0x7BA7E5|`8b 91 8c 00 00 00`|—|
|0x7babeb|0x7BA7EB|`50`|—|
|0x7babec|0x7BA7EC|`52`|—|
|0x7babed|0x7BA7ED|`e8 4e da 02 00`|0x7E8240|
|0x7babf2|0x7BA7F2|`43`|—|
|0x7babdf|0x7BA7DF|`8b 0d 38 a8 fb 00`|—|
|0x7babe5|0x7BA7E5|`8b 91 8c 00 00 00`|—|
|0x7babeb|0x7BA7EB|`50`|—|
|0x7babec|0x7BA7EC|`52`|—|
|0x7babed|0x7BA7ED|`e8 4e da 02 00`|0x7E8240|
|0x7babf2|0x7BA7F2|`43`|—|
|0x7babf3|0x7BA7F3|`3b df`|—|
|0x7babf5|0x7BA7F5|`72 dc`|—|
|0x7babeb|0x7BA7EB|`50`|—|
|0x7babec|0x7BA7EC|`52`|—|
|0x7babed|0x7BA7ED|`e8 4e da 02 00`|0x7E8240|
|0x7babf2|0x7BA7F2|`43`|—|
|0x7babf3|0x7BA7F3|`3b df`|—|
|0x7babf5|0x7BA7F5|`72 dc`|—|
|0x7babf7|0x7BA7F7|`83 be 8c 00 00 00 00`|—|
|0x7babfe|0x7BA7FE|`74 0d`|—|

## 4. 舊稿全文主張的修復與撤回規則

本稿以**取代**而非在原稿上修修補補方式修復T01反證。上游caller、callee、branch path、ABI、物件身分和資源安全，**只以§2具體限定證據成立**；T01在原source列出但未被此版本採納的其它段落（例如未驗證全體caller、原版Server決策、全物件生命週期）一律標為**撤回／未知**，不被原版結尾「已解決」等詞自動繼承。

- **Client已證**：§2指定子鏈、§3修正映射所在的code bytes（限實際通路/狀態）。
- **Client待逆向**：record registry建立與B entry fn4在所有分支必然調用尚未證明。 及其它沒有入口根CFG支撐的分支。
- **Server待開發**：相容Server應依T02已驗wire提供資料；不得由本稿推斷原版Server出怪波次/排序時機。
- **跨功能／遊玩待驗證**：T01原生逐主張複驗；T02封包、T06/T07場景與S00設計整合，實機尚未驗收。

## 5. 檢核與驗收要求

T01需對此**新的精確blob**而非歷史FAILED source按條件逐項複驗：先核每條修正座標與原生bytes，再核§2肯定主張的真CFG、owner來源、資料流/反例。未重新審核時不得將本文標為FULL-PASS；舊原稿的FAILED歷史也不得因新檔提交而刪除。
