# 正常建房進村：操作意圖與驗證範圍

2026-11-08；KR 原 BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## Client 操作意圖

Matching 的 EID17000 是「進入村莊」（마을 입장），EID15000 是「建立隊伍」（파티 생성）。兩者不是相同事件：前者在無現有隊伍時產生 F42E1 bool1，後者產生 bool0。前者控制項儲存在 panel+110，後者在 panel+118；不可將面板欄位與建立對話框的同偏移欄位當成同一物件。

建立對話框 68C790 先發送0053，再發005E／0060。其 dialog+110 與選定類型分支可以發布 F4390；5B6250 是進村預檢，現有隊伍分支可經 4A3620 發送003D。補查 5B7750 的 F42E1 case→5B7590：事件型別105C4通過後，將 event+14 的 bool 傳給 page+238 所指對話框的68C5B0；原始指令68C70A將值寫入 dialog+110。因此這個 bool setter 已有有限靜態接線證據，但整個 dispatcher 並未完成原始 switch table 全文語意驗收。008E／008F 本身更新隊伍歸屬及介面，不代表已換場。

可重現的有限證據見 [collector](../../governance/client-variants/20261108-normal-village-entry/collect_entry_intent.py) 與 [metadata](../../governance/client-variants/20261108-normal-village-entry/entry-intent-bounded-v1.json)。兩份 UI member 均核對 origin 與工作副本解碼內容相等；公開內容僅為來源 SHA、有限標籤與指令視窗，不包含完整資源。這不是全函式語意 FULL-PASS，也不是官方 Server 回覆擷取。

## Server 驗證必須分開記錄

原有正常通關測試的前段使用 TCP／SQLite，但其中後續 normal-party helper 直接呼叫 `LocalExpeditionConnection.HandleAsync`。因此原有「位於完整 TCP 測試內」的描述不能推導出建房進村段落也經過 TCP。

新增的獨立段落應使用已正常完成教學及首次村落劇情、尚未進行 debug 跳轉的同一 authenticated primary TCP lane：連續0053、005E、003D，核對001C／008E／008F／008A、載入起始0023與0069；收到0043後核對村落 context、map、NPC、互動區與0024。測試不使用進度指定或直接寫入帳號任務進度。

一次 stream write 不保證作業系統只產生一次 receive；這驗證正常 TCP framing 與順序，不能稱為強制單一收包測試，也不代表 Client 必然自行發送003D。實際按鈕操作與進村顯示仍須另行驗收。多人、故障、重送等暫緩項目不因這次補測而恢復執行。

## 本次結果

11項受影響的正常通關參數組合全部通過，0失敗／0略過，其中完整教學與主線組合實際執行新增 TCP 段落。沒有修改正式 Server 程式或重啟 Host。保留三次開發中失敗紀錄：漏列0023、沿用換場前座標、舊 helper 固定 listing key1；修正的是測試預期與後續行走起點，沒有削弱封包序列或改動正式行為。精確結果及 SHA 見 [validation](../../governance/client-variants/20261108-normal-village-entry/tcp-validation-v1.json)。
