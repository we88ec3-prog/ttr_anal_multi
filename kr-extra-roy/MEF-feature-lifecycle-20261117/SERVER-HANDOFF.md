# Server／內容開發交接：保留效果、明確完成與共享資源收尾

本文件接續既有REQ-0019／REQ-0021與A1脈絡，供S00去重整合；不是新正式RR台帳，不改owner或驗收狀態。原件、反證與精確地址見 [REPORT.md](REPORT.md)。方案均為 **NOT_NATIVE_MEF 相容內容**。

## 1. 新增可用性

有限插播初始化某些本地效果後，normal End移除qco，但原native owner仍能推進。有限圖片可自然釋放；FadeIn可自然透明；相機、BGM、演出角色可依各自owner繼續。這些能力不用全部等待B的持續Lua入口才能研究／規格化，但初始Q仍會接管，不能標成全程不中斷戰鬥。

## 2. Server待開發與內容工具責任

| 工作 | 玩家情境／原生介面 | 必須實作的責任 | 禁止誤認 |
|---|---|---|---|
| 權威觸發 | 通關／抵達／NPC互動後啟用有限內容 | Server判定合法開始、玩家/instance/scene對齊、排他 | 不要求Client自行裁定通關／獎勵 |
| 發布品固定 | 已知SceneList/0047及原resource loader | build/hash/資源鍵/實際選路、簽入資料綁定 | 檔案落地不是已載入；不新增MEF傳檔opcode |
| 功能分類 | 同步切point、有限圖片、相機／角色／BGM持有 | 每個內容聲明是即時修改、自然終止或需cleanup；設計用metadata不塞進原wire | native animation tick不是Lua背景runner |
| 單玩家排他與baseline | 相機/Fade/letterbox/world flags/music共享 | Server及內容整合層保存本次取得項、已知baseline與互斥策略 | 沒有已證Luaowner token就不得假稱能回讀所有持有人 |
| 圖片策略 | Q只保存最後handle；finite／hold=-1不同 | 初版優先單張有限圖；永久圖先有合法取消入口；不得多張hold靠一次Del | alpha0不等於當時已delete；圖片消失不等於任務成功 |
| 相機收尾 | Stop、Detach、快照Pop不同 | 在own current前提按順序停止／解除／配對restore，處理失敗／替換 | IsEnded1涵蓋null/stopped/失敗，不是完整播畢ACK |
| Q actor生命周期 | StopObject/IsAllStopped/DeleteAllObject | 所有slot/model/action有來源；清全部Q樹前證明排他；處理model job等待 | Q actor不是網路怪；stub DeleteObject不是單slot刪除 |
| 可見性與速度 | world+A8、world+B0及+AC、letterbox+C | normal End前後依政策恢復／明確保留，操作恢復與畫面恢復分開驗收 | 清input mask不還原角色、慢動作或黑邊 |
| 音樂政策 | 共用雙slot／16stream；fade不release | 決定保留、切回已知音軌或全Stop；避免誤停其他服務音軌 | StopMusic不是per-run單軌取消；靜音不表示slot已釋放 |
| 收尾及結果 | 已有003F/00EB/A1執行狀態 | 狀態機、可靠發送、instance與版本對帳、逾時不盲重送 | 003F只報特定結束分支，無效或skip也可回報；不當效果成功 |
| 資產／任務保存 | 買賣／強化／開門／掉落／進度 | 權威驗證、原子更新、持久化、重入完整快照 | 本地外觀／面板／提示不授予資產 |

## 3. 初版內容限制（候選設計，不是已分配部署規格）

A1的已提交內容鍵、單次政策與point用途保持不變，不能把新音畫功能偷偷塞進同一版本。下一項內容另綁定有來源的SceneList鍵與完整資源hash，不在本稿任意猜填。

建議先選一個**有限圖片**或**FadeIn自然透明**。正常路徑：有版本的資源可見→合法A入口→Start尾段完成→正式callback用direct binding啟動→正常End／等待解除→native推進→自然終點／回收。所有有等待的global helper與direct binding必須分開，不能無意加yield改變時間契約。

若選有限圖片：需要合法存在texture與精確path/hash；數值輸入用明確number；明定finite hold（第7參數0）、淡入/出正數，使用原實際更新計數而非猜毫秒。若選FadeIn：原graphics已配置texture，正數count、exclusive Fade owner，並接受初始遮罩效果。兩者都沒有已證的通用Client成功ACK，因此Server業務結果不由視覺完成判定。

## 4. 正常流程驗收（只定義，不執行）

1. 版本、場景、原資源選路與本次owner成立。
2. 舊業務狀態合法且只有本次內容取得共享效果。
3. 合法入口執行一次，不被seen／busy跳過；setter／native啟動各別記錄。
4. normal End／003F／00EB與控制器恢復依現有規格完成；不額外塞wire run token。
5. 效果依指定自然終點或明確收尾結束，畫面／聲音／world visibility等後置條件成立。
6. Server權威進度、資產與場景持久化一致；有限本地效果不被保存成永久業務條件。

錯誤、重入、取消、跨圖及共享owner競爭保留為後續驗收契約，遵守現行先正常流程的測試排程，不在本輪啟動遊戲／壓測。

## 5. 不歸給Server猜補的Client缺口

官方MEF格式／首次loader、B非Q首次入口、普通world結果的可靠typed Lua reader/callback仍由Client證據回答；Server不得自行發明原Client不讀的payload、函式名或通用事件。這些缺口與Server通關／交易／資料庫策略分開。32個SYN檢查及原件PASS也不代表Server程式已完成。
