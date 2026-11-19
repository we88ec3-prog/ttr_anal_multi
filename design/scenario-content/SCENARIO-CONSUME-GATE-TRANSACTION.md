# 消耗道具機關：交易層契約

狀態：**STORE_READY，WORLD／AUTHORING_WIRING_OPEN**。
這是交易層交付當時的範圍；後續[世界與JSON編排接線](SCENARIO-CONSUME-GATE-WORLD.md)
已有正常旅程證據，專用表單與Client驗收仍未完成。
本批只實作既有 SQLite 資產服務內的原子扣物與機關操作收據，尚未把此能力
接成可遊玩的機關。既有 BagQuantityReached 仍是唯讀持有量 latch，不能
用它假裝已扣除道具；既有手動互動也保持原規則。

## 來源與正常完成順序

[11月18日整合報告](../../research/handoffs/t01-20261118-extra-roy1-mef-sync/REPORT.md)
允許有限 Server 設計引用，不構成原生全文驗收。
具體開發契約來自[規則擴充E4](../../kr-extra-roy/MEF-P0-level-execution-20261118/rules-scheduling/extension-contracts.json)：
既有交易 owner 中驗證 SessionLease、扣除明確 Product／quantity，和操作
收據一起提交；提交成功後才投影機關，不因預覽、輪詢、演出完成或任意
Client旗標而扣除。

本批另核對現行正常清場程式：StageOne 須等
PendingStageOneDefeatExperience 為 null 才提交 GroupCleared；結果提交也有
同一門檻。因此未為這段已存在的順序另改程式，亦未新增實機驗收主張。

## Server-owned operation

輸入由已准入的 Server 關卡呼叫者建構，不是新Client封包：
有效 SessionLease、非空 run GUID、64位十六進位內容SHA、node1～65535、
非零interaction鍵、已持有角色1～9、非零uint Product、quantity1～255。
SHA正規化為小寫；inventory依帳號共用，role保留參與者所有權界線。

交易服務本身核對 lease 和已持有角色，但**不自行證明 run／節點正在遊玩**。
後續 world adapter 必須依當前內容版本、run、節點、距離、角色、機關前置與
唯一互動身份產生這份可信操作，不能讓外部直接選任意成本或收據鍵。

operation身份為 account＋run＋node＋interaction，收據綁定內容SHA、角色、
Product、quantity與提交時間。相同身份不得換成本重新扣除。已存在且完全
符合者回傳當前資產與 PreviouslyCommitted，不再產生扣物差額；此重送分支
已有防護實作，但依排程未執行重送測試，也不宣稱整場跨登入恢復已完成。

## 同筆交易內容

在現有資產服務的立即寫入交易中：

1. 讀取授權的已提交資產及參與者所有權。
2. 檢查版本1專用組件與既有機關操作收據。
3. 對指定Product，依slot次序選擇 EquipmentId為null的共用堆疊；不取銀行、
   裝備中物品或獨立裝備。所有被選堆疊須有既有metadata。
4. 核對總量，扣除精確數量；空堆疊刪除，保留者沿用slot與metadata。
5. 保存機關操作收據，再讀取同交易的完整資產，提交後回傳資產與變動格。

未提交不回傳成功收據；失敗時由交易回復，不設世界旗標。新組件由此授權
操作首次需要時在同交易建立，不需要修改既有TownTrade版本或即刻遷移玩家庫。
這是 `LOCAL_SCENARIO_GATE_CONSUMPTION_V1_NOT_NATIVE_MEF`，不是官方MEF格式。

## 本批驗證與尚未完成部分

隔離資料庫正常購買／領取兩批Product5238共400件，形成255／145兩堆疊，
另保留一件獨立時裝。第一個機關操作扣250，得到5／145；第二個不同機關
操作扣10，移除5件堆疊、另一堆疊剩140。兩筆持久收據共260，回應變動格
與保存資產一致，時裝及Garnet／LeeLoo／BattlePoint不變。
這是資產服務的成功旅程，不是同一操作重送，也不是實際遊戲機關通關。
測試資金／帳號與現有教學準備沿用既有隔離fixture。

見[驗證收據](scenario-consume-gate-store-validation.json)。尚須完成：

- schema／內容成本欄位與商品供應、角色、獨立物品政策驗證。
- world操作准入、當前run／版本綁定及提交後才設旗標。
- 正常背包、快捷列計數及機關／出口狀態的提交後發布。
- 編排介面、實際供應與消耗的整條正常關卡旅程。
- 指定Client實機；跨登入run恢復、重送、拒絕、故障、安全及壓測依既有待測表。

正式Host、管理端與玩家資料本批不啟用新操作，Client與原件保持。
Host與檢查器Release建置零警告／零錯誤，新增聚焦正流程1項及完整
634項HappyPath均通過。通過範圍不擴及上述尚未接線與暫緩測試項目。
