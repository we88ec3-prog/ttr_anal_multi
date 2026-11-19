# 商城獨立商品表讀取路徑

2026-11-19，使用者明確要求先確認商城實際讀取路徑，再修改新的主程式工作副本，讓其讀取獨立商城檔；原件與舊版保留。商城管理完成、推送後暫停開發。此授權只涵蓋這次商城讀取與配套，不解除遊戲執行／附加限制。

本頁為固定 KR BIN／指定 v2 的有界靜態分析。既有偽碼、原件位元組、Ghidra 12.1.4 的 PE32 `readOnly / noanalysis` 局部指令互相核對；沒有執行 Client、呼叫其 API、修改原件或變更正式 Task／catalog 驗收狀態。23 份偽碼身份、21 個原 BIN／v2 對照視窗及兩份指令輸出的 SHA 見 [來源索引](source-index.json)。這不是整個函式的 FULL-PASS。

## 真正使用的檔名與 consumer

原 BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；指定 v2 SHA `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。下列有界視窗在兩檔相同。

`511E40` 是商城商品表 parser。`511E90` 的 `MOV ECX,0xC0E098` 指向完整 NUL 結尾字串 `Table/CashProduct.xml`（raw offset `0x80C698`），`511EA3` 呼叫 `72F110`。只看偽碼會遺漏 ECX 的檔名參數；本輪直接核對指令，不能把 `72F110(0)` 誤解成未指定檔名。

`72F110` 將檔名存進 document 的字串，呼叫 `714770` 取得檔案物件，再交給 `72F260`。後者讀取檔案內容並區分 `EX` 包裝與普通 XML，普通 UTF-8 XML 不需要再做 STP 封裝。

`714770` 先嘗試 `713910` 的 package lookup；`714C50` 依邏輯目錄前綴匹配 package。沒有相符 package 時，可進入 `714030` 的普通檔案路徑。`717B60` 只探測前兩 bytes 是否為 gzip magic `1F 8B`；普通 XML 不走 compressed-file 分支，而由 `713CC0` 的既有 `_fopen` 開啟。`714030` 可先試既有設定的磁碟前綴，再試原路徑，因此仍需保持既有遊戲根目錄啟動方式。

## 校驗 provider 已追到實際實作

這次沒有忽略 `713CC0` 開檔後的可選 callback，也不修改、停用或繞過它。

`48BD30` 註冊 package manager `FBA814 = &FE48E0`，並把 `FBA818 / FBA81C` 設為 `&FE37A0`。`48B2E0` 將 FE37A0 初始化為 `MD5ChecksumProvider`，vtable 位於 `0xC05A8C`，前三項依序為 `48B9C0 / 48BB60 / 48BB80`。`48B730` 讀取 `Integrity.xml` 的 `PATCH`，再由 `48B380` 建立名稱與 checksum 索引；`48B380` 對 `.stp` 條目另行處理，不把其封裝 checksum 當成鬆散 XML 的 checksum。

`48B9C0` 先由 `48B8C0` 將查詢檔名轉小寫、反斜線轉正斜線，再查既有索引。命中時複製 16 bytes，`48BB1D: b001` 明確回傳 `AL = 1`；未命中時清空輸出，`48BB3F: 32c0` 明確回傳 `AL = 0`。`.ogg` 與 `locale` 結尾另有既有分支，本次 `.xml` 不使用這些分支。

`713CC0` 把實際檔名及 16-byte 輸出傳入該 callback。`713D74..713D76` 檢查 AL；為零時直接到 `713DB0` 回傳已開啟的 StdFile。只有回傳非零才計算實際內容並比對 checksum。這是原有 provider 的條件行為，沒有新增豁免或改掉校驗指令。

原版與現用 `Integrity.xml` 完全相同，SHA `ac36b7d55956941929c8451c09f7c23afdb63776b600eb24b50c5abd678916a8`。唯讀解開 EX mode 0 後為 800,193 bytes，SHA `5451ee848e2536dff798b9582d185aacd43c8a71fe6b948098df3b2cdb9870fb`，內容宣告 euc-kr；依此解碼再 parse，共 **7,086 個 XML elements（含根），其中 6,504 個 FILE elements**。不是 7,086 筆檔案。

本次完整檔名索引中沒有 `tc_mall/cashtable.xml`，也沒有 CashProduct 鬆散檔項目。配合上述 AL 與 consumer 分支，此固定 manifest 下的新獨立檔走既有 index-miss／普通 XML 載入路徑；**不需要修改 Integrity.xml**。原始 manifest、解出的原始 XML 與遊戲 binary 不上 Git。

## 最小工作副本修改

在指定 v2 衍生的新檔，只把唯一完整字串改成 `TC_Mall/CashTable.xml`。舊、新路徑都是 21 bytes，加 NUL 後都是 22 bytes。保留原 offset、NUL、指令、PE header／section 配置、其餘表檔與既有 IP／翻譯修改；不改全域 loader 或任何 checksum 分支。

這會讓該商城 parser 使用獨立檔名，之後更新商品列表與 Garnet 價格只需更新這份獨立 XML 及相符的 Server 目錄，不必每次重產 `Table.stp`。管理端配套仍須固定草稿版本、核對 XML／Server 標價與 tuple，保留來源、舊版、輸出 SHA；不得只改其中一邊。沒有自動下載或新增傳檔 opcode。

`511CA0` 先建立全域 `CCashShopTable @ FB1354`，再呼叫 `511E40`。`4146B0` 及 `697710` 等現成 UI 取表路徑受 `FB1350` bit 0 guard 保護，並登記 `atexit`。這支持採用「**完整退出遊戲，再啟動新工作副本**」的更新流程；不宣稱每次開商城或按寶石重整就會重新讀商品表，這次也不新增熱重載。

## 列表與上架欄位

`511E40` 將 `NOW_SELLING / SELLING_STATE / SELLING_TYPE / SHOP_TYPE / SELL_START_DAY / SELL_END_DAY` 保存到 row。它建立全部 row 的 vector 與 Product map，本身沒有依日期刪除 row。

有界 consumer `416020` 遍歷 `FB1358..FB135C` 全部 rows，先要求 `NOW_SELLING != 0`，並要求 `end == 0 || current <= end`。`SELLING_TYPE == 1 / 2` 再分流到特別分類；start/end 也影響這些分類。其他 type 按 Item class 與既有條件進入 `415F70` 等流程。

因此從原版模板新增商品時，不能只增加 XML row 卻保留已過期的日期。配套可明示採用管理上架政策：列入商品的 `NOW_SELLING = 1`、`SELLING_STATE = 0`、start `2000-01-01T00:00:00`、end `2037-12-31T23:59:59`，並保留其餘分類／商品資料。NOW 與有效 end 有直接 consumer 依據；SELLING_STATE 取 0 是沿用目前工作表的管理政策，本段並未證明它是所有畫面顯示的必要值。這些值不是原服今日供貨政策，也不開放尚未實作的商品效果。

## 舊版失敗與本次驗證界線

先前 v5 的人工失敗是「NPC 頭頂名稱仍為韓文」，不是本次商城獨立檔的驗收。當時只改封裝路徑，沒有涵蓋真正直接 XML reader；後續 v6 改 direct-reader 字串仍有自己的實機待驗限制。不能把那次失敗當成所有鬆散 XML 都不能讀，也不能把本次靜態檢查宣稱為成功的實機結果。

本批工程交付與原件保持檢查由修改工具及管理端配套收據記錄。指定新 Client 的啟動、商城分類、改價／新增／移除列表、正常購買與領取仍須使用者操作驗收。尚未實測前，狀態保持 `STATIC_SOURCE_VERIFIED / DESIGNATED_CLIENT_PENDING`。不宣稱熱重載、全商品效果或整個 native 函式完成驗收。
