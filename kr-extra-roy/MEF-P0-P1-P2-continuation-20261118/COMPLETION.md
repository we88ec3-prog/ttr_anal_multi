# P0／P1／P2 八項完成判定

本表逐項對應 [原 ANALYSIS-PLAN](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md) 的 3 項 P0、4 項 P1、1 項 P2。固定原件與既有研究來源見 [source-manifest.json](source-manifest.json)，機器狀態見 [status.json](status.json)。

**八項都有分析處置；整體原生能力與玩家可用條件尚未全部閉合。** 本輪完成的是新的有界證據、已完成證據的整合、候選裁決及精確續析條件。缺原件／正向接點的研究目標仍是 BLOCKED／NOT_CLOSED，不以完成報告代替達成目標。

## 1. 八項對照

| 原工作項 | 已有成果與本輪處置 | 原生分析判定 | 尚缺的完成條件 |
|---|---|---|---|
| P0 採用勘誤與 ABI | 沿用 121 bindings／33 marshallers／15 項勘誤的固定證據；與本輪介面 receiver 勘誤分開 | 指定原件、已列介面契約有界已證；本輪採用既有結果 | Server／內容工具實際採用、整合及正常流程驗收 |
| P0 內容真實依賴 | Master 掛載樹、base mesh／texture 分流沿用；新增完整 cache record／讀取失效／重複 group／實體掃描順序與局部 fallback 的精確契約 | 選檔算法的指定問題已證；**實際 winner 與 payload 仍受阻** | 同版 fcs 或可證明實際選取的 loose 資料；選中素材及實際接受結果 |
| P0 執行與收尾 | 沿用 22 owners、20 cleanup edges、3 run profiles；沒有把新 UI cache 生命期當 script run 收尾 | 已列 owner 契約有界已證 | 編排實作與共享 owner 組合、取消／重入、返回操控等正常流程驗收 |
| P1 第一個完整正常旅程 | 沿用 Q119 前置→5 段 SEQ→4 戰鬥節點→結果→119/5 返回→Q120 的十步資料流程 | 真實資料流程已分析；不是已實際通關 | 素材、Server 整合、權威結果／資產保存、完整正常旅程 |
| P1 擴充所有功能族 | 七個指定功能族各有真例，完整保留資料、入口、退出及來源限制 | **7／7 指定族的真實例契約已分析** | 各例完整 payload、共享 owner 組合、遊玩；不推論所有內容皆可用 |
| P1 普通背景首次入口 B | 新證 resource 212 的 FTC 路徑、binder／manager receiver、talk `+18=self`、no-op custom factory、移出與 cache 重入 | UI resource／生命期的缺邊閉合；**B 本身仍 NOT_CLOSED** | 實際 FTC／子元件／callback；第一次內容執行、同 VM pump、script owner 取消與重入 |
| P1 world 結果到 Lua | 沿用 HP／SP／MP、視覺記錄、HUD／AI、死亡 FSM／erase 等 producer 終點；底層 Lua sink 候選已有後稿分類，本輪去重 | **NOT_CLOSED_NO_PROVEN_ENDPOINT** | 真正結果 bridge 的 writer／registration／storage、run／generation 身分、同 VM consumer |
| P2 官方 MEF 格式 | 將 Master Field、STP、PackingRules、MapList 名稱、Lua parser、外部 schema 拆開；核後續 alias 證據並補 partial-DI 勘誤 | 指定候選已裁決；**原格式／executor 仍 BLOCKED** | 真實 MEF bytes 與正向 consumer／parser／executor；再導出最小 grammar 與拒絕條件 |

新分題：[P0](p0-selection/)、[P1](p1-entry/)、[P2](p2-format/)。復用定位：[REUSED-EVIDENCE](REUSED-EVIDENCE.md)。

## 2. 本輪真正閉合的邊

### P0：從「開得到 index」拆出「index 足夠用」

完整 reader 顯示開檔成功後的正常返回會使初始化跳過全部預設 group 與全域 scan；header／group／entry 的讀取沒有以完整性檢查作為該返回條件。讀取格式與實體掃描順序可從 BIN 證明，實際 fcs record 與安裝目錄則尚未提供。離線 inspector 的結構拒絕規則是內容檢查政策，不冒充原 Client 對損壞輸入的保證。

因此「未知選檔算法」已有更完整的答案；「這一次真正載入哪個檔案」仍沒有。`resource_ready=false` 維持，舊缺件前緣不因 reader 已分析而減少。

### P1：具體 UI 首次載入、取消與重入

一般 Mission／Scenario 的 helper 使用棧上的 binder，而不是將所有 virtual receiver 都視作 page。resource 212 有明確 FTC 路徑；選定 reader 將 talk 的 `+18` 設為 talk 本身，其 `+110` custom factory 是 no-op，該分支轉往通用 native child factory。

普通頁面移出時可 detach 並移出 active manager，而 cache descriptor 正常命中時保留物件；重入取既有 descriptor 的 instance 再掛回。這是 UI cache 的有界契約，不能代替「本次 script run 的取消／重啟」證據。實際 child／layout／後續事件由缺失 FTC 選擇，保留下一段來源需求。

### P2：縮短一條錯誤保留的 alias 生命期

舊稿將 `4BAD73` 保存於 EDI 的 root alias 延伸過久。`4BADC2 mov di,[FB90EA]` 已改寫低 16 位，後續不能再沿用「原 root 未改變」的證明。這是 partial overwrite；不把它寫成 EDI 全 32 位清空，也不宣稱對所有可能數值必然不相等。修正該證明邊界沒有帶來新的 MEF reader。

## 3. 最後保留的條件

| 條件 | 本輪狀態 | 為什麼尚未通過 |
|---|---|---|
| Master 已取得／掛載宣告 | 已通過 | 使用同一固定原件，前輪全樹證據可復用 |
| 所選資源完整且真正可載入 | 未通過 | 缺實際 selection context 與 payload；cache 開啟本身不足 |
| 普通背景第一次腳本執行 | 未通過 | UI 建立已證，仍沒有完整正向 load／execute／pump 鏈 |
| world 結果送進原腳本 | 未通過 | 有 world producer 與 Lua 能力，尚缺兩者的具體同生命期接點 |
| 官方 MEF grammar／executor | 未通過 | 目前沒有已核真實 MEF payload 或其 consumer |
| Server 開發／整合 | 本輪只交需求 | 既有工程由現有 owner 去重採用；不以靜態 Client 分析替代實作 |
| 實際遊玩 | 未進行 | 研究驗證不等於聲畫、操控、通關與保存驗收 |

精確補件見 [SOURCE-REQUEST](SOURCE-REQUEST.md)，Server 的可並行路徑見 [SERVER-REQUIREMENTS](SERVER-REQUIREMENTS.md)。不存在一個可以用目前證據填成「P0／P1／P2 全部可玩」的百分比。
