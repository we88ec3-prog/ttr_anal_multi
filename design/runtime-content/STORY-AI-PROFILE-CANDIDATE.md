# 主線遭遇使用共用AI設定：實驗性Server資料契約

狀態：SERVER_DESIGN_CANDIDATE／NOT_NATIVE_MEF；不是APPROVED ADR、STABLE SPEC或官方AI。用途是讓不同Server實作者重用資料接線，與原生Client未知分開。

## 資料與載入

既有LOCAL_STORY_NAVIGATION_CANDIDATE_V1_NOT_MEF的每個scenario.nodes項目，可額外提供字串`aiProfile`，未提供時為`legacy-melee-v1`。這是具名參照，不能放任意可執行腳本或Client檔案路徑。

AI設定仍來自LOCAL_MONSTER_BEHAVIOR_V1_NOT_NATIVE_MEF、nativeMef=false的既有MonsterBehavior JSON，內容必須以精確SHA載入，profile authority保持SERVER_RECONSTRUCTION_NOT_NATIVE_MEF。啟動時逐node解析名稱，名稱不存在不得回退到另一組數值後繼續。

資料流程：Host載入共用MonsterBehavior catalog→驗證入口兩圖及後續主線node→World進場與劇情後重建均按node取得同一profile→建立遭遇。不是只把名稱寫進文件，實際HP、速度、攻擊動作、距離、節奏及傷害都由既有profile驅動。

## 適用與相容

- 舊內容未寫aiProfile時保持原有預設；現行33個後續主線遭遇節點均可讀，不更改任務ID／地圖／人物／場景／已完成前綴／保存revision。
- Host將入口兩圖已核對的同一catalog交給後續主線，不再讓後續遭遇自行讀embedded預設而忽略外部AI設定。
- 測試診斷顯示monsterBehaviorSha256及遭遇階段aiProfile，作為來源查核；不寫正式角色／任務完成進度。
- 每node目前共用一個profile；混合群組的逐物種／逐怪策略尚未實作，不能稱完整怪物AI。一般近戰追逐演算法仍是Server候選；此欄只指定已支援的行為參數組。
- 教學固定遭遇、生成安全距離、波次／條件、原生MEF reader、ClientMEF傳輸、完整技能命中／特性及官方數值另有缺口。

## 驗證範圍

正流程整合以不同具名profile證明：同一主線node在進場劇情重建後仍以90HP而非預設60、指定motion108而非原攻擊動作、5點而非15點傷害執行；後一node可沿用legacy。這些數值只屬隔離合成fixture，不作正式平衡。

若只改AiProfile內容本身，須遵守既有content SHA／PreviousVersions規則，不繞過主線版本驗證。本輪程式預設相容既有v34內容，沒有改現行storyJSON或AIJSON／SHA，不需要更動DB或舊歷史來源。

原生MEF完成條件仍是已驗真實樣本、格式、引用及執行鏈；本資料契約不解除該門檻。
