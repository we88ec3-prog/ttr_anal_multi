# Server／內容開發交接：三個切片的責任與完成門檻

本文件供S00去重採納；不另建正式RR、不更改他人owner、不修改正式Server。完整來源見 [REPORT](REPORT.md)。

| 工作 | 可先實作的Server責任 | Client證據／不能假設 |
|---|---|---|
| Case103轉場 | 保存node1→2及Map191/192、合法出口授權、採用的spawn政策、generation切換 | 原圖表不提供出口座標；BND零值不是合法spawn證書 |
| Actor／relation發布 | 建立world快照與0008 relation、嚴格typed字段、兩者在000A之前 | 0008的relationKey是u32，000A的actorId為u16；missing actor不會晚到補播 |
| Reset／重綁 | 0008 reset、0012 controller reset之後按政策重發正確binding；清楚保存舊/新快照 | reset不同map，不能靠0014或sameMap重送補回角色／points |
| Loading／ready／Q | 各自狀態與排程、對應run的End處理、過期發送阻擋 | 0014 mask1、00EB mask2、Q busy與UI capture不同；沒有現成全域ready ACK |
| Point／A1 | 0027完整集合在0012之後；唯一(category,key)；一次A1已配置鍵與資源版本 | setter不新增、不回可靠success；003F不是point命中證明 |
| 外觀切片 | 保留actor lifetime、model/part/variant、可信舊variant、獨立apply/restore內容發布 | 0047不帶任意avatar參數；不把modelID當worldId；metadata可能早於可見apply |
| 模型依賴 | 綁指定descriptor及資源hash，保持actor有效至原生工作完成的適當生命週期 | Action回值、End或等待解除不是模型已套用ACK；無此Lua getter不能假造 |
| 通關／群組 | 權威成員、生命期、死亡去重、勝敗與獎勵保存 | native目標欄位及00DF不等於可靠清組事件；這些規則不要求交給Lua |
| 服務與資產 | 商品／強化／背包等原子提交與相容結果 | 外觀item是呈現資源，非背包授予；Native效果不自行保存資產 |

## 可驗收正常路徑（未執行）

在已採用的Case103/Map191配置，記錄出口意圖與權威狀態；排除舊內容／generation；按偏序發Map192、角色、relation、控制及完整points，安排loading與ready。只有畫面、碰撞、角色控制、互動點與Servernode均正確，才驗A1或外觀切片。

外觀正常切片記錄同一actorId/model及原variant，有限入口啟動單次操作，分別觀察可見apply與輸入解除，再用獨立合法內容恢復。不能只因收到003F就grant外觀裝備或保存成功。

本輪只運行離線格式與證據檢查，遊戲異常／重登／併發等暫緩測試不擅自執行。

## 明確缺件，不需把整個Client重新解包

1. 原始出口／出生資料，或S00採用的相容配置與正常驗收責任；保留W3候選為候選即可。
2. 指定角色類別0/model1/PRE1/FILE stem soma的實際avatar descriptor／所需資產，及當次world/關聯快照；依已證79E980/79FBC0 reader追精確member，不猜副檔名。
3. 真正world結果到Lua的新typed橋接證據。沒有橋接不妨礙Server先完成權威判定及有限內容觸發，但不得因此稱Client死亡callback已存在。
