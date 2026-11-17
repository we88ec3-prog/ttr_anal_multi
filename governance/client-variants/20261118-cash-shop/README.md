# 點數商城購物車與保管箱的收發接線

強化保護材料接續：[付款與鐵匠串接](../../../design/scenario-content/CASH-ENHANCEMENT-PROTECTION.md)、[來源驗證器](verify_protection.py)及[收據](protection-source-verification.json)。已分開六種材料的 Grade／SafetyID 與價格；5523／27484 有付費使用合成證據，高品級裝備路線及指定 v2 仍待完成。

完全復活卷軸接續：[付費取得與戰鬥串接](../../../design/scenario-content/CASH-COMPLETE-REVIVAL.md)、[原表核對](verify_revival.py)與[來源收據](revival-source-verification.json)。付款／領取／復活資源與保存有離線證據，原視聽、死亡懲罰／評級恢復及指定 v2 仍未完成。

髮型／染髮接續：[商城髮型與染髮用品](../../../design/scenario-content/CASH-HAIR-STYLE-AND-DYE.md)提供原 Action 13／14、0070 頭部語意、原 Hair.ipk／描述檔的來源及獨立 Server 投影；用途、交易、正常驗證及實機待測分開記錄。

2026-11-18 S00 限定來源核對。工作基準為本庫 `02758e1a027fcd1a69dcb94ef3073990eaded7eb`、Server `94b4ddc61e08101afd2334d0916ed0d0bca2df43`。本批將商城來源導航推進到購物車請求、結果 consumer 與保管箱領取請求。Server 付款及入包接線仍待後述條件閉合。

同日接續 [商城餘額與保管箱欄位](BALANCE-AND-STORAGE.md)，追加固定餘額 consumer、19-byte 保管箱列及 Server 餘額發布規劃。前批 13 個來源視窗與收據保留，新增部分有自己的來源索引與檢查收據。

使用固定 SHA 的原 KR BIN、指定 v2 及 Table.stp。原件保持唯讀，沒有遊戲、Lua 或 Server 執行。來源擷取使用 Ghidra 12.1.4 的 PE32 loader、`-readOnly -noanalysis` 與局部反組譯，配合先前保存的 Ghidra 偽碼閱讀。REA 的前次字串查詢逾時後，進一步核對發現沙箱內 `java -version` 無法完成；本批改用沙箱外的唯讀 Ghidra 工作，原本的本任務分析助手已核對後結束。

本批覆蓋以下特定資料流與原件位元組，並未進行整個函式的 T01 全文審核。正式 SPEC／REQ／RR 狀態仍依原台帳。 [來源索引](source-index.json) · [局部指令](instructions.txt) · [檢查收據](verification-result.json)

## 購物車確認

`699000` 的 `0578` 控制項分支在按鈕命中時呼叫 `698D40`。`698D57` 初始化命令 `00AC`，`698EAD..698ED0` 將每列寫成七個 bytes，`698F01..698F16` 按當前長度送出。發送槽第一個參數為 0，具體連線與現行 Server transport 的對應仍待接線核對。

| C2S application 偏移 | 已核對內容 |
|---|---|
| +0 u16 | 命令 `00AC` |
| +2 起，每列 7 bytes | Product u32、選定價格列的第一個 byte、該價格列 +4 的 byte、額外選項 byte |

原商品物件 `+54h` 指向價格列，每列 12 bytes。選項資料由物件 `+64h`、每列 24 bytes 取第一個 byte，未選取時為 0。這三個 byte 的最終業務名稱需連同原表 parser 及 UI 選項補核。

封包沒有獨立的列數欄位。從初始長度 2 開始，每列加 7；已累積九列後，處理下一列前先送出再重設。一般九列 request 長度為 65。Server 後續 parser 應依 `2 + 7*N` 核對，正常 Client 單次分批上限九列。購物車跨批的原服原子性與費用規則仍未知。

## 購買結果

player-state 登錄 `4E209F` 將 `4E3C50` 寫入 `+6FCh`，按既有每 opcode 八個 bytes 的表格規則對應 S2C `00DF`。`4E3C50` 把封包指標與長度帶入 UI 事件 `F4287`，既存 `59B9E0` 分派至購物車 `699260`。

`6992DE` 讀封包 +2 的有號狀態，跳表 `6995C4` 的五項目的位址分別為 `6992F3,6992F3,6994C5,6994F8,69952B`。狀態 1、2 走同一結果視窗建立分支，3、4、5 走不同提示。這是本地 UI consumer 的分支語義，Server 仍需定義何時可對應發布結果。

| S2C application 偏移 | 已核對內容 |
|---|---|
| +0 u16 | 命令 `00DF` |
| +2 i8 | 結果狀態 |
| +3 起，每列 16 bytes | consumer 讀前三個 DWORD；第二個與購物車 Product 比較，第三個與目前價格選項索引加一比較 |

`699357..69936D` 對長度減 3 再右移 4 得列數。`699375..699389` 複製前三個 DWORD，第四個 UI 欄先填 0，再由匹配購物車項目補值。線上列的第四個 DWORD 在本次路徑未見讀取。無完整列時，consumer 會從本地購物車建立結果清單；這條顯示分支本身不足以判定付款或道具取得。

C2S 普通任務開窗回報也使用 `00DF`。實作須按方向分派各自的 parser。

## 商城保管箱領取

`69C490` 的 `070A` 分支交給 `69C550`。該函式依目前保管箱項目查 Product／Item。普通入包分支先找一般背包可用格，`69C8F1..69C926` 送十個 bytes。

| C2S application 偏移 | 已核對內容 |
|---|---|
| +0 u16 | 一般領取 `00AD` |
| +2 u32 | 所選保管箱記錄第一個 DWORD |
| +6 u32 | 同一記錄第二個 DWORD |

這兩個 DWORD 應先保留為不透明的保管箱記錄鍵。其來源、生命週期與背包物品 metadata 的關係尚待核對。`69C6FC` 的 Item class 30 分支改送 `00AF`，同樣長度 10，需沿該類型的使用效果另外處理。

S2C `00AD` 由 `4E1F5F` 登錄 `4E2670 → 50A560`。`50A560` 讀 +2 有號狀態與 +3、+4 兩個 byte，轉為 `F428B`。兩個 byte 的業務名稱、成功後的一般背包發布及保管箱移除順序待接續。S2C `00AE` 則由 `4E1F6F` 登錄 `4E2690 → 50A5F0`，零狀態下按 `(length-3)/8` 處理列並發 UI 事件。這些已定位接收器可縮小後續追查範圍。

## 原表與 Server 接續

原 Table.stp SHA-256 為 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。解碼 `Table/CashProduct.xml` 的 SHA-256 為 `77b3f5d521f3c01948210f8c0895c6eb4e5b7d9a4bc6914e11d6608fd4bcd5e3`。共 1,311 個不同 Product，均有 `PRICE_LIST`。表內保留 NOW_SELLING、SELLING_STATE、SELLING_TYPE 和起訖日期。

Product 27461、27462、27484 的單件價格欄分別為 18、29、141。這三筆原表數字與既有 CP／強化材料分析相符。實際扣款幣別、餘額 consumer、限期與上架政策尚須完整追查；舊表的 NOW_SELLING 不能直接當成目前 Server 的供貨決策。

後續接線依序完成以下項目。

1. 沿商品表 parser 與 UI 價格選項，定出 `00AC` 三個 byte 的型別、付款幣別與價格查詢。
2. 核對商城開窗、餘額與保管箱初始化。先固定記錄鍵的建立和發布，再接領取。
3. Server 在同一交易內扣款並建立可領取記錄，領取時提交保管箱移除及一般背包入包。共用租約、裝備 ID、metadata 與資產更新元件。
4. 補上 `00DF` 結果與 `00AD` 領取結果的發布條件，逐項核對 UI 訊息、保管箱和一般背包。
5. 正常購買一件裝備與一件堆疊商品，接已有換裝、銷毀、銀行及保存流程，再安排指定 v2 批次驗收。

## 重跑

`verify.py` 核對三份來源整檔 SHA、13 個原 BIN／指定 v2 位元組視窗、原商品表 member SHA、商品唯一性及三筆既有引用。工具只讀檔，收據的 `runtimeVerified` 與 `serverCheckoutImplemented` 保留 false。

```powershell
python -B governance/client-variants/20261118-cash-shop/verify.py --bin E:/Tartaros/workspace/Tartaros.bin --v2 E:/Tartaros/workspace/Tartaros.ip-zh-tw-only-v2.exe --table E:/Tartaros/origin/Table.stp
```

局部反組譯腳本為 [DumpCashInstructions.java](DumpCashInstructions.java)。將其放入工作輸出目錄後，用 Ghidra `analyzeHeadless` 的 `-import <BIN> -readOnly -noanalysis -loader-loadLibraries false -scriptPath <腳本目錄> -postScript DumpCashInstructions.java <新輸出.txt> -deleteProject` 重跑。輸出是原件指令與本次 Ghidra 解碼，另需按本頁列出的資料流閱讀。
