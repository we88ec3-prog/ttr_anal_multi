# T08-134 — T01 LEGACY-MAPPING-001 獨立修正版 v3：name-key檢索與兩上游

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei；**原始 KR Client** Tartaros.bin, 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA `0x401000`, raw `0x400` ⇒ `raw=VA−0x400C00`；.rdata VA `0xBD2000`, raw `0x7D0600`。原件／版本及修正版分開，不移動或覆寫舊原稿。

## 1. 精確失效原稿與替代裁決

- **歷史原稿，仍FAILED**：`kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-134-two-caller-record-name-routing.md`；blob `e00a3e06649983687ef227f550a756fee78a6128`；SHA256 `56390d32bb5e68b36d0bb7a3f168328712df1a0a852bd82730b34e4328f14194`。
- **T01退回ID**：`T01-RETURN-T08-LEGACY-MAPPING-001`。原稿的錯誤根因是whole-file BIN從file raw0錯當.text code起點，導致指令標籤普遍相對真PE偏 +0x400；原始假code/rel32目標及推論不能逐字保留。若屬真正.rdata DWORD內容，不可一律減0x400。
- **此v3修正版是替代技術來源**：僅以下明列、有原生支持的肯定主張為有效修正主張；原稿其它未重新列入的肯定語句**正式撤回，不供引用**。這是作者側勘誤交件、**不是**T01獨立全文FULL-PASS或LEGACY退回RESOLVED。
- **已完成映射檢查**：T01原始 `mapping-findings.json` 此篇共 128 行，逐行 `affine_candidate_equal=true` 的 128 行；此表只聲稱T01所核對的同byte PE座標，**不能當成每行重新獨立反組譯及ABI驗證**。

## 2. 修正後可引用的函式、owner、資料流與條件

新根入口0x7E86E0處理name-key tree，call0x7E8A00比較／查找；owner與registry不同指標來源需分別追溯，不因offset相同併成單一容器。

**原生詳細核對**：[`20261031-023000-chatgpt-web-roy-T08-134-name-key-tree-PE-CFG-corrected-source.md`](../../20261031-023000-chatgpt-web-roy-T08-134-name-key-tree-PE-CFG-corrected-source.md)。該source提供真PE入口附近機器碼、根CFG／vtable owner，對本篇主張的影響不應用「整篇直平移」取代；同類交叉補證在 [134～151交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[T08-152 RTTI](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**否證／剩餘邊界**：lookup是否找到及插入副作用要以成功條件判定。

## 3. 原稿每一個T01已核錯誤code-row的PE定位（共 128 行）

本表欄位依T01已讀取原始BIN `mapping-findings.json` 做精確T08-134 source-row crosswalk；其中direct `E8/E9 rel32` 目標以**新的真PE VA + 5 + signed displacement** 重算，不能複製原稿相對目標。仍須從函式入口驗證CFG和其他跳轉邊界。這裡不是全面代替完整disassembly，也不改任何非code的字面常數或.rdata指標。

|T01原標籤VA|新PE真VA|真PE byte（T01讀BIN）|可重算direct相對目標|
|---|---|---|---|
|0x7e8b0e|0x7E870E|`8b 5d 08`|—|
|0x7e8b11|0x7E8711|`8b f9`|—|
|0x7e8b13|0x7E8713|`53`|—|
|0x7e8b14|0x7E8714|`8b c7`|—|
|0x7e8b16|0x7E8716|`89 9d 68 ff ff ff`|—|
|0x7e8b1c|0x7E871C|`e8 df 02 00 00`|0x7E8A00|
|0x7e8b21|0x7E8721|`8b f0`|—|
|0x7e8b23|0x7E8723|`3b 77 04`|—|
|0x7e8b1c|0x7E871C|`e8 df 02 00 00`|0x7E8A00|
|0x7e8b21|0x7E8721|`8b f0`|—|
|0x7e8b23|0x7E8723|`3b 77 04`|—|
|0x7e8b26|0x7E8726|`74 12`|—|
|0x7e8b28|0x7E8728|`8d 46 0c`|—|
|0x7e8b2b|0x7E872B|`8b d3`|—|
|0x7e8b2d|0x7E872D|`e8 fe 26 cb ff`|0x49AE30|
|0x7e8b32|0x7E8732|`84 c0`|—|
|0x7e8b23|0x7E8723|`3b 77 04`|—|
|0x7e8b26|0x7E8726|`74 12`|—|
|0x7e8b28|0x7E8728|`8d 46 0c`|—|
|0x7e8b2b|0x7E872B|`8b d3`|—|
|0x7e8b2d|0x7E872D|`e8 fe 26 cb ff`|0x49AE30|
|0x7e8b32|0x7E8732|`84 c0`|—|
|0x7e8b34|0x7E8734|`0f 84 8c 00 00 00`|—|
|0x7e8b3a|0x7E873A|`33 db`|—|
|0x7e8b28|0x7E8728|`8d 46 0c`|—|
|0x7e8b2b|0x7E872B|`8b d3`|—|
|0x7e8b2d|0x7E872D|`e8 fe 26 cb ff`|0x49AE30|
|0x7e8b32|0x7E8732|`84 c0`|—|
|0x7e8b34|0x7E8734|`0f 84 8c 00 00 00`|—|
|0x7e8b3a|0x7E873A|`33 db`|—|
|0x7e8b3c|0x7E873C|`89 5d bc`|—|
|0x7e8b3f|0x7E873F|`c7 45 d4 0f 00 00 00`|—|
|0x7e8b2d|0x7E872D|`e8 fe 26 cb ff`|0x49AE30|
|0x7e8b32|0x7E8732|`84 c0`|—|
|0x7e8b34|0x7E8734|`0f 84 8c 00 00 00`|—|
|0x7e8b3a|0x7E873A|`33 db`|—|
|0x7e8b3c|0x7E873C|`89 5d bc`|—|
|0x7e8b3f|0x7E873F|`c7 45 d4 0f 00 00 00`|—|
|0x7e8b46|0x7E8746|`89 5d d0`|—|
|0x7e8b49|0x7E8749|`88 5d c0`|—|
|0x7e8b3a|0x7E873A|`33 db`|—|
|0x7e8b3c|0x7E873C|`89 5d bc`|—|
|0x7e8b3f|0x7E873F|`c7 45 d4 0f 00 00 00`|—|
|0x7e8b46|0x7E8746|`89 5d d0`|—|
|0x7e8b49|0x7E8749|`88 5d c0`|—|
|0x7e8b4c|0x7E874C|`89 5d dc`|—|
|0x7e8b4f|0x7E874F|`89 5d e0`|—|
|0x7e8b52|0x7E8752|`89 5d e4`|—|
|0x7e8b5b|0x7E875B|`8b 8d 68 ff ff ff`|—|
|0x7e8b61|0x7E8761|`50`|—|
|0x7e8b62|0x7E8762|`51`|—|
|0x7e8b63|0x7E8763|`8d 95 6c ff ff ff`|—|
|0x7e8b69|0x7E8769|`52`|—|
|0x7e8b6a|0x7E876A|`e8 11 0c 00 00`|0x7E9380|
|0x7e8b6f|0x7E876F|`8d 85 6c ff ff ff`|—|
|0x7e8b75|0x7E8775|`50`|—|
|0x7e8b6a|0x7E876A|`e8 11 0c 00 00`|0x7E9380|
|0x7e8b6f|0x7E876F|`8d 85 6c ff ff ff`|—|
|0x7e8b75|0x7E8775|`50`|—|
|0x7e8b76|0x7E8776|`8b cf`|—|
|0x7e8b78|0x7E8778|`c6 45 fc 01`|—|
|0x7e8b7c|0x7E877C|`e8 2f 0b 00 00`|0x7E92B0|
|0x7e8b81|0x7E8781|`50`|—|
|0x7e8b82|0x7E8782|`56`|—|
|0x7a89ce|0x7A85CE|`83 bb 50 01 00 00 00`|—|
|0x7a89d5|0x7A85D5|`75 2a`|—|
|0x7a89d7|0x7A85D7|`d9 05 c0 56 c5 00`|—|
|0x7a89dd|0x7A85DD|`8b 15 38 a8 fb 00`|—|
|0x7a89e3|0x7A85E3|`d9 5c 24 38`|—|
|0x7a89e7|0x7A85E7|`51`|—|
|0x7a89e8|0x7A85E8|`d9 ee`|—|
|0x7a89ea|0x7A85EA|`8d 4c 24 18`|—|
|0x7a89e7|0x7A85E7|`51`|—|
|0x7a89e8|0x7A85E8|`d9 ee`|—|
|0x7a89ea|0x7A85EA|`8d 4c 24 18`|—|
|0x7a89ee|0x7A85EE|`d9 1c 24`|—|
|0x7a89f1|0x7A85F1|`52`|—|
|0x7a89f2|0x7A85F2|`8d 54 24 40`|—|
|0x7a89f6|0x7A85F6|`e8 85 24 01 00`|0x7BAA80|
|0x7a89fb|0x7A85FB|`89 83 50 01 00 00`|—|
|0x7a89f6|0x7A85F6|`e8 85 24 01 00`|0x7BAA80|
|0x7a89fb|0x7A85FB|`89 83 50 01 00 00`|—|
|0x7a8a01|0x7A8601|`8b 9b 50 01 00 00`|—|
|0x7a8a07|0x7A8607|`85 db`|—|
|0x7a8a09|0x7A8609|`74 12`|—|
|0x7a8a0b|0x7A860B|`a1 38 a8 fb 00`|—|
|0x7a8a10|0x7A8610|`8b 88 8c 00 00 00`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a89fb|0x7A85FB|`89 83 50 01 00 00`|—|
|0x7a8a01|0x7A8601|`8b 9b 50 01 00 00`|—|
|0x7a8a07|0x7A8607|`85 db`|—|
|0x7a8a09|0x7A8609|`74 12`|—|
|0x7a8a0b|0x7A860B|`a1 38 a8 fb 00`|—|
|0x7a8a10|0x7A8610|`8b 88 8c 00 00 00`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a8a17|0x7A8617|`51`|—|
|0x7a8a01|0x7A8601|`8b 9b 50 01 00 00`|—|
|0x7a8a07|0x7A8607|`85 db`|—|
|0x7a8a09|0x7A8609|`74 12`|—|
|0x7a8a0b|0x7A860B|`a1 38 a8 fb 00`|—|
|0x7a8a10|0x7A8610|`8b 88 8c 00 00 00`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a8a17|0x7A8617|`51`|—|
|0x7a8a18|0x7A8618|`e8 23 fc 03 00`|0x7E8240|
|0x7a8a0b|0x7A860B|`a1 38 a8 fb 00`|—|
|0x7a8a10|0x7A8610|`8b 88 8c 00 00 00`|—|
|0x7a8a16|0x7A8616|`53`|—|
|0x7a8a17|0x7A8617|`51`|—|
|0x7a8a18|0x7A8618|`e8 23 fc 03 00`|0x7E8240|
|0x7a8a1d|0x7A861D|`8b 4c 24 54`|—|
|0x7a8a21|0x7A8621|`5f`|—|
|0x7a8a22|0x7A8622|`5e`|—|
|0x7babd3|0x7BA7D3|`8b 8e a4 00 00 00`|—|
|0x7babd9|0x7BA7D9|`8b 14 99`|—|
|0x7babdc|0x7BA7DC|`8b 42 34`|—|
|0x7babdf|0x7BA7DF|`8b 0d 38 a8 fb 00`|—|
|0x7babe5|0x7BA7E5|`8b 91 8c 00 00 00`|—|
|0x7babeb|0x7BA7EB|`50`|—|
|0x7babec|0x7BA7EC|`52`|—|
|0x7babed|0x7BA7ED|`e8 4e da 02 00`|0x7E8240|
|0x7babdc|0x7BA7DC|`8b 42 34`|—|
|0x7babdf|0x7BA7DF|`8b 0d 38 a8 fb 00`|—|
|0x7babe5|0x7BA7E5|`8b 91 8c 00 00 00`|—|
|0x7babeb|0x7BA7EB|`50`|—|
|0x7babec|0x7BA7EC|`52`|—|
|0x7babed|0x7BA7ED|`e8 4e da 02 00`|0x7E8240|
|0x7babf2|0x7BA7F2|`43`|—|
|0x7babf3|0x7BA7F3|`3b df`|—|

## 4. 舊稿全文主張的修復與撤回規則

本稿以**取代**而非在原稿上修修補補方式修復T01反證。上游caller、callee、branch path、ABI、物件身分和資源安全，**只以§2具體限定證據成立**；T01在原source列出但未被此版本採納的其它段落（例如未驗證全體caller、原版Server決策、全物件生命週期）一律標為**撤回／未知**，不被原版結尾「已解決」等詞自動繼承。

- **Client已證**：§2指定子鏈、§3修正映射所在的code bytes（限實際通路/狀態）。
- **Client待逆向**：lookup是否找到及插入副作用要以成功條件判定。 及其它沒有入口根CFG支撐的分支。
- **Server待開發**：相容Server應依T02已驗wire提供資料；不得由本稿推斷原版Server出怪波次/排序時機。
- **跨功能／遊玩待驗證**：T01原生逐主張複驗；T02封包、T06/T07場景與S00設計整合，實機尚未驗收。

## 5. 檢核與驗收要求

T01需對此**新的精確blob**而非歷史FAILED source按條件逐項複驗：先核每條修正座標與原生bytes，再核§2肯定主張的真CFG、owner來源、資料流/反例。未重新審核時不得將本文標為FULL-PASS；舊原稿的FAILED歷史也不得因新檔提交而刪除。
