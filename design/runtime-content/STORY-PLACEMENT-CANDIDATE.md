# 後續主線的顯式副本配置候選

分類：SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。沿用已存在的有限單人副本；不聲稱原版生怪位置、波次或原生MEF格式。

現況：33個後續主線節點的怪物位置由程式固定以出生點偏移產生；出口位置取map層、key用節點序號、觸發半徑固定6。這些策略不能讓每張圖獨立調整。

候選擴充：LocalStoryNode可選 encounterSpawns（model/x/y）與 portal（x/y/radius/key）。沒有新欄位的舊內容保持原有配置。顯式 encounterSpawns 的模型順序及數量必須與 encounterModels相同，保留原來源模型成員關係；座標有限且通過現行靜態BND檢查。出口key非零、半徑有限且正、位置可站立。這只是靜態檢查，不等於通道底端、大型傳送陣外觀與生成安全距離已實機驗收。

Server載入時解析配置；進場及入場劇情後重建均使用同一份怪物配置。清怪後出口的顯示座標、互動key與Server距離檢查必須讀同一配置，避免畫面位置與實際可觸發位置不同。

不改原生封包格式、角色操控、AI權威、HP／傷害、敘事持久化或正式獎勵。不是將檔案傳給Client執行；與未來原生MEF解析器分開。

驗證：舊33節點等價配置、JSON讀取保留顯式配置，以及World實際進場／劇情後重建／清怪顯示出口／指定key互動。維持正流程測試；格式錯誤、安全與重送案例延後。

範例：`encounterSpawns: [{model:1001,x:790,y:740}]`、`portal: {x:820,y:740,radius:6,key:71}`。欄位只屬本地Server JSON；不等同原版檔案或對Client傳送JSON。現有出口封包的radius仍經原生0.8比例處理；Server授權半徑沿用配置值，因此不可將配置半徑誤稱為精確的畫面效果大小。

`materialize_story_placements.py`可把舊程式候選偏移完整實體化成JSON，不改位置／數量；必要參數為input、expected-sha256、output，輸出採新檔，保留舊內容SHA與任務ID lineage。此轉換不驗證靜態碰撞，須再經Server loader；也不宣稱現有候選位置已符合每圖的生成距離或出口要求。
