# T08-132 — T01 LEGACY-MAPPING-001 獨立修正版 v3：第二調度者與A/B owner

**作者** chatgpt-web roy；2026-10-31 Asia/Taipei；**原始 KR Client** Tartaros.bin, 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 .text VA `0x401000`, raw `0x400` ⇒ `raw=VA−0x400C00`；.rdata VA `0xBD2000`, raw `0x7D0600`。原件／版本及修正版分開，不移動或覆寫舊原稿。

## 1. 精確失效原稿與替代裁決

- **歷史原稿，仍FAILED**：`kr-temp-roy/20261027-190000-chatgpt-web-roy-T08-132-second-queue-caller-and-producer-boundary.md`；blob `3d35052d8bc09d70fe1394b6ac9380a5454b73a9`；SHA256 `f51573aa23825e6d4785c979da55c1758509c3dcfa569e15fee289d68db27438`。
- **T01退回ID**：`T01-RETURN-T08-LEGACY-MAPPING-001`。原稿的錯誤根因是whole-file BIN從file raw0錯當.text code起點，導致指令標籤普遍相對真PE偏 +0x400；原始假code/rel32目標及推論不能逐字保留。若屬真正.rdata DWORD內容，不可一律減0x400。
- **此v3修正版是替代技術來源**：僅以下明列、有原生支持的肯定主張為有效修正主張；原稿其它未重新列入的肯定語句**正式撤回，不供引用**。這是作者側勘誤交件、**不是**T01獨立全文FULL-PASS或LEGACY退回RESOLVED。
- **已完成映射檢查**：T01原始 `mapping-findings.json` 此篇共 0 行，逐行 `affine_candidate_equal=true` 的 0 行；此表只聲稱T01所核對的同byte PE座標，**不能當成每行重新獨立反組譯及ABI驗證**。

## 2. 修正後可引用的函式、owner、資料流與條件

有另一consumer caller路徑，A array與B vector由不同欄位/不同指標來源提供；排除generic append是特定B producer的單一實現，真正CDoll producer另由0x7A63C0入B。

**原生詳細核對**：[`20261031-020700-chatgpt-web-roy-T08-132-LEGACY-MAPPING-PE-second-caller-A-B-boundary-revision.md`](../../20261031-020700-chatgpt-web-roy-T08-132-LEGACY-MAPPING-PE-second-caller-A-B-boundary-revision.md)。該source提供真PE入口附近機器碼、根CFG／vtable owner，對本篇主張的影響不應用「整篇直平移」取代；同類交叉補證在 [134～151交付索引](../../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)、[T08-152 RTTI](../../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)。

**否證／剩餘邊界**：不能用直接E8負證排除virtual caller，不宣稱B→bucket因果。

## 3. 原稿每一個T01已核錯誤code-row的PE定位（共 0 行）

本表欄位依T01已讀取原始BIN `mapping-findings.json` 做精確T08-132 source-row crosswalk；其中direct `E8/E9 rel32` 目標以**新的真PE VA + 5 + signed displacement** 重算，不能複製原稿相對目標。仍須從函式入口驗證CFG和其他跳轉邊界。這裡不是全面代替完整disassembly，也不改任何非code的字面常數或.rdata指標。

沒有T01逐列映射：改由下述已提交獨立修訂原生入口證據處理。

## 4. 舊稿全文主張的修復與撤回規則

本稿以**取代**而非在原稿上修修補補方式修復T01反證。上游caller、callee、branch path、ABI、物件身分和資源安全，**只以§2具體限定證據成立**；T01在原source列出但未被此版本採納的其它段落（例如未驗證全體caller、原版Server決策、全物件生命週期）一律標為**撤回／未知**，不被原版結尾「已解決」等詞自動繼承。

- **Client已證**：§2指定子鏈、§3修正映射所在的code bytes（限實際通路/狀態）。
- **Client待逆向**：不能用直接E8負證排除virtual caller，不宣稱B→bucket因果。 及其它沒有入口根CFG支撐的分支。
- **Server待開發**：相容Server應依T02已驗wire提供資料；不得由本稿推斷原版Server出怪波次/排序時機。
- **跨功能／遊玩待驗證**：T01原生逐主張複驗；T02封包、T06/T07場景與S00設計整合，實機尚未驗收。

## 5. 檢核與驗收要求

T01需對此**新的精確blob**而非歷史FAILED source按條件逐項複驗：先核每條修正座標與原生bytes，再核§2肯定主張的真CFG、owner來源、資料流/反例。未重新審核時不得將本文標為FULL-PASS；舊原稿的FAILED歷史也不得因新檔提交而刪除。
