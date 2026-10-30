# T08-130 — T01 LEGACY-MAPPING-001 獨立修正版 v3：dispatcher、B佇列與兩個上游caller

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei；**原始 KR Client** Tartaros.bin, 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA `0x401000`, raw `0x400` ⇒ `raw=VA−0x400C00`；.rdata VA `0xBD2000`, raw `0x7D0600`。原件／版本及修正版分開，不移動或覆寫舊原稿。

## 1. 精確失效原稿與替代裁決

- **歷史原稿，仍FAILED**：`kr-temp-roy/20261027-185041-chatgpt-web-roy-T08-130-dispatcher-phase-and-queue-lifecycle.md`；blob `5e7a513b87ea08a9f920377e526be8b444d79ab3`；SHA256 `6edbab44eb64e39f1c51dc9317eb5563cb801e755d223daa501d44e446b6971b`。
- **T01退回ID**：`T01-RETURN-T08-LEGACY-MAPPING-001`。原稿的錯誤根因是whole-file BIN從file raw0錯當.text code起點，導致指令標籤普遍相對真PE偏 +0x400；原始假code/rel32目標及推論不能逐字保留。若屬真正.rdata DWORD內容，不可一律減0x400。
- **此v3修正版是替代技術來源**：僅以下明列、有原生支持的肯定主張為有效修正主張；原稿其它未重新列入的肯定語句**正式撤回，不供引用**。這是作者側勘誤交件、**不是**T01獨立全文FULL-PASS或LEGACY退回RESOLVED。
- **已完成映射檢查**：T01原始 `mapping-findings.json` 此篇共 21 行，逐行 `affine_candidate_equal=true` 的 21 行；此表只聲稱T01所核對的同byte PE座標，**不能當成每行重新獨立反組譯及ABI驗證**。

## 2. 修正後可引用的函式、owner、資料流與條件

指令地址舊0x7BB640需以真0x7BB240按入口重新建CFG；與全域22桶的0x799F20分離；B consumer可在條件下選priority entries及per-entry slot，而不能從程式碼相鄰推B→22桶生效。

**原生詳細核對**：[`20261031-020700-chatgpt-web-roy-T08-130-LEGACY-MAPPING-PE-dispatcher-vector-revision.md`](../20261031-020700-chatgpt-web-roy-T08-130-LEGACY-MAPPING-PE-dispatcher-vector-revision.md)。該source提供真PE入口附近機器碼、根CFG／vtable owner，對本篇主張的影響不應用「整篇直平移」取代；同類交叉補證在 [134～151交付索引](../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[T08-152 RTTI](../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**否證／剩餘邊界**：producer必然在同一幀進全域bucket未證；A/B兩向量不是同一field。

## 3. 原稿每一個T01已核錯誤code-row的PE定位（共 21 行）

本表欄位依T01已讀取原始BIN `mapping-findings.json` 做精確T08-130 source-row crosswalk；其中direct `E8/E9 rel32` 目標以**新的真PE VA + 5 + signed displacement** 重算，不能複製原稿相對目標。仍須從函式入口驗證CFG和其他跳轉邊界。這裡不是全面代替完整disassembly，也不改任何非code的字面常數或.rdata指標。

|T01原標籤VA|新PE真VA|真PE byte（T01讀BIN）|可重算direct相對目標|
|---|---|---|---|
|0x79a37c|0x799F7C|`6a 00`|—|
|0x79a37e|0x799F7E|`68 50 32 fe 00`|—|
|0x79a383|0x799F83|`e8 68 50 03 00`|0x7CEFF0|
|0x79a388|0x799F88|`57`|—|
|0x79a389|0x799F89|`e8 d2 10 00 00`|0x79B060|
|0x79a38e|0x799F8E|`8b 35 38 a8 fb 00`|—|
|0x79a394|0x799F94|`e8 a7 12 02 00`|0x7BB240|
|0x79a399|0x799F99|`8b 8f a0 00 00 00`|—|
|0x79a39f|0x799F9F|`8b 01`|—|
|0x79a3a1|0x799FA1|`8b 97 98 00 00 00`|—|
|0x79a3a7|0x799FA7|`8b 40 0c`|—|
|0x79a3aa|0x799FAA|`52`|—|
|0x79a3ab|0x799FAB|`ff d0`|—|
|0x79a3ad|0x799FAD|`8b 0f`|—|
|0x79a3af|0x799FAF|`8b 11`|—|
|0x79a3b1|0x799FB1|`8b 42 0c`|—|
|0x79a3b4|0x799FB4|`be 01 00 00 00`|—|
|0x79a3b9|0x799FB9|`56`|—|
|0x79a3ba|0x799FBA|`56`|—|
|0x79a3bb|0x799FBB|`56`|—|
|0x79a3bc|0x799FBC|`ff d0`|—|

## 4. 舊稿全文主張的修復與撤回規則

本稿以**取代**而非在原稿上修修補補方式修復T01反證。上游caller、callee、branch path、ABI、物件身分和資源安全，**只以§2具體限定證據成立**；T01在原source列出但未被此版本採納的其它段落（例如未驗證全體caller、原版Server決策、全物件生命週期）一律標為**撤回／未知**，不被原版結尾「已解決」等詞自動繼承。

- **Client已證**：§2指定子鏈、§3修正映射所在的code bytes（限實際通路/狀態）。
- **Client待逆向**：producer必然在同一幀進全域bucket未證；A/B兩向量不是同一field。 及其它沒有入口根CFG支撐的分支。
- **Server待開發**：相容Server應依T02已驗wire提供資料；不得由本稿推斷原版Server出怪波次/排序時機。
- **跨功能／遊玩待驗證**：T01原生逐主張複驗；T02封包、T06/T07場景與S00設計整合，實機尚未驗收。

## 5. 檢核與驗收要求

T01需對此**新的精確blob**而非歷史FAILED source按條件逐項複驗：先核每條修正座標與原生bytes，再核§2肯定主張的真CFG、owner來源、資料流/反例。未重新審核時不得將本文標為FULL-PASS；舊原稿的FAILED歷史也不得因新檔提交而刪除。
