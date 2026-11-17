# 商城餘額與保管箱欄位

2026-11-18 接續 [購買與領取收發](README.md)。沿用原 KR BIN、指定 v2 和 Table.stp 的固定 SHA。新增局部反組譯在 [storage-instructions.txt](storage-instructions.txt)，[verify_balance.py](verify_balance.py) 會重跑前批來源檢查，再核對新增的 13 個原 BIN／v2 視窗。

## 商城餘額

`4E1590` 的 CGlobalStatus 原物件基址為 `F8D9E0`。`4E1659` 初始化 `F9424C`，即基址 `+686Ch`。`698BB4..698BBE` 讀取此值，與購物車合計比較，再更新可購買狀態。

player-state 登錄 `4E208F` 將 `4E3BC0` 寫到表 `+6ECh`，對應 S2C `00DD`。該 handler 在 `4E3BE6..4E3BEF` 將封包 +2 的 DWORD 寫到同一 `+686Ch`，並以 `F4286` 發 UI 更新事件。`59B9E0 → 59C2F0` 接到適用視窗的餘額顯示處理。

| 欄位 | 格式 |
|---|---|
| S2C application | `command:u16=00DD, balance:u32`，6 bytes |
| 一般角色狀態中的同一欄 | `002A/+0Eh:u32`，由 `4E2B72..4E2B7B` 寫到 `+686Ch` |
| 購物車使用的值 | `F9424C`，原指令採有號比較 |

本機 Server 沿用已有錢包的 `Garnet` 作此商城餘額。這項幣別映射是 Server 決策；本批固定的是原 Client 欄位、consumer 與 UI 更新路徑。官方付款管道、各種充值貨幣的規則及本機餘額取得方式仍待另定。

正常世界載入時，先讀已授權資產，再以 `00DD` 發布當前值。已啟用銀行擴充、扣除本機設定的 Garnet 費用成功後，發布 `00C4` 容量結果，再發布同筆提交回傳的 Garnet 值。不能以扣款前快照推算回覆。

合成正例沿用銀行測試的原始 120、費用 50，預期提交為 70。回覆的餘額 application 為 `DD 00 46 00 00 00`。下一次讀取已存資產後應重新發布 70。零起始餘額為 `DD 00 00 00 00 00`。指定 v2 顯示和操作仍待批次驗收。

## 商城保管箱

`4E20DF`、`4E20EF` 分別把 `4E3FB0`、`4E3FD0` 登錄到表 `+714h`、`+71Ch`，對應 S2C `00E2` 與 `00E3`。

| application | 已核對的 consumer 行為 |
|---|---|
| `00E2` | `4E3FB0 → 50AC70` 先清除保管箱集合，再從 +2 以 19-byte 列追加 |
| `00E3` | `4E3FD0 → 50ADA0` 從 +2 以 19-byte 列處理；列 +8 的 DWORD 為 0 時用前兩 DWORD 移除記錄，非零時追加 |

`50B070` 把每列完整的四個 DWORD、一個 WORD 和最後一個 byte 複製入集合。增量的非零分支採追加。更新既有同鍵記錄時，需要先依已證移除形狀處理舊記錄，再發新列，避免在 Client 留下重複項目。

| 列內偏移 | 本次可採用的含義 |
|---|---|
| +0、+4，各 u32 | 保管箱記錄鍵；與 C2S `00AD` 的兩個 DWORD 一致。Server 後續須保存其所有權 |
| +8 u32 | Product，UI 再接 Item 表；0 用於增量移除 |
| +0C u32 | UI 以此值加 `0x93A80`，即 604,800 秒，供時限顯示。其時間基準及原服保留規則仍待補核 |
| +10、+11、+12，各 u8 | 數量／期間／選項的候選欄位。UI 的三個用途已定位，最終型別及效果須沿商品與領取完成路徑閉合 |

保管箱的記錄鍵與一般背包 item metadata 分別追查。領取的應用層請求沒有送出目的背包格。Server 入包後仍需用已核對的背包格位更新發布提交結果。

## 商品價格列

既存 `511E40` 依序讀 `QTY`、`PERIOD`、`PRICE`，暫存為三個 DWORD，再交 `52EF90` 複製成 12-byte 列。這對應前批購物車從價格列 +0、+4 取低 byte。完整原表共有 1,411 筆價格選項，QTY 為 1、10、11、50、100、200，PERIOD 為 0、7、15、30、90，本表沒有 OPTION_LIST。

正常購買的列可接為 Product、數量 byte、期間 byte、選項 byte。原表的 PRICE 應由 Server 根據 Product 與精確選項查出，請求沒有傳入價格。期間商品與保管箱期限、領取後的使用期限仍須分別核對，不能因取得 PERIOD 就直接套用同一到期規則。

## 尚未完成的交易

本輪先實作已閉合的餘額發布。商城入口、上架政策、付款取得、保存購買記錄、領取入包、期間與附加選項仍是後續工作。保管箱 snapshot／delta 先作接線輸入，Server 尚未新增對應保存或領取交易。完整實機正常購物旅程仍待排程。

Host 與離線檢查器 Release 建置通過，563 項 HappyPath 合成全通過。銀行案例核對提交後 `00C4 → 00DD` 的順序、70 的實際資料庫保存值，以及正常廣場初始化重新發布。完整原版 BND 新帳號旅程仍完成 Q144，存於 Town 3 圖 199，並通過護甲跨村存取、Q2852 同登入銜接、RAID 1～3 和三本經驗書使用。離線旅程收據 SHA-256 為 `dfac63219f34fd5de87b0462c5d62b4ed722fd3da787b1f658b9d4b7bb2fcb4e`。此收據驗證旅程回歸，非零餘額的封包和保存由銀行合成正例核對。指定 v2 的餘額與銀行畫面仍待 TS-06。

重跑新增來源檢查。

```powershell
python -B governance/client-variants/20261118-cash-shop/verify_balance.py --bin E:/Tartaros/workspace/Tartaros.bin --v2 E:/Tartaros/workspace/Tartaros.ip-zh-tw-only-v2.exe --table E:/Tartaros/origin/Table.stp
```
