# 同場連續的兩個循環區段

2026-11-22；SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
分析基準266ee30e5、私有Server4c91c489。通用領域引擎原已可描述平面互不重疊body；
本批把正常Case693入口、編輯與配套交付接成同一場的兩個區段，不把它稱為巢狀或原生MEF。

[獨立候選](phindos-stage462-case693-sequential-loops.scenario.json) SHA256
`0f5aab43e34ae8c6cb916fc4d4aa36ee29c0819cde8df50cf185f3038cede08b`，
AI仍為 `d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
舊prefix／branch候選保持不變，來源chart、map、原出口與BND保持；沒有新wire opcode或Client檔。

正常入口的同一explicit mode現在允許Case693的10/1前綴及3/5/6/4分支body同場存在，
或只啟用其中一段。每個已開放body最多一份，仍禁固定alias混用；既有通用SCC、body邊界、
旗標與狀態圖檢查全部保留。每段由自身ID計數，不因另一段離開或重訪而重用迴圈輪數。
不重啟mission run，角色資源、背包、已提交資產與整場旗標延續，最後只結算一次。

入口段10/1使用prefix-attempt重置entry-paid及offering-made，保留supplies-ready。
每輪10掉183×1且機關11消耗1；1掉183×2，可選機關41消耗2；背包達3設supplies-ready。
退出後才進入3/5或6/4分支段；branch-attempt只重置本段開關、聚合／延遲與可選機關旗標，
保留先前入口付款及supplies-ready等整場事實。分支段的停止旗標branch-supplies-ready改為背包達6，
每輪各選一條岔路掉183×1，4的可選41消耗1。兩段各最多三輪。

不操作可選41：入口第二輪袋中4，分支第二輪袋中6，各段由自己的停止旗標離開；
共11次實際訪問、124EXP，含最後一次20EXP，頭目後袋中183×7。
每輪正常操作兩段的41：入口每輪袋中0、分支每輪袋中0，兩段都因三輪上限離開；
共16次實際訪問、160EXP，頭目後袋中183×1。機關成本為入口11三次、1的41三次、4的41三次，
共九筆不同visit的同run領域提交，數量分別1／2／1，不把相同互動鍵41跨房混同。
以上為這兩條具體操作清單，不宣稱用目前袋中數量就能還原任意歷史保留旗標。

保守EXP界限88～160，最大16次實際訪問、19個分析state；不是將兩個body上限做無意義乘積。
其中每輪分支只走5或6之一，不同時算兩條路。最小88是控制流保守界限，不是這個成本候選已測的最短玩法。
兩輪／三輪、首選3／6交替的四條正常TCP皆完成124／160EXP存檔，回原村同隊。
逐路另外核對prefix重置次數、branch重置次數及跨段保留的entry-paid／supplies-ready或offering-made。
這四路的遊戲邏輯在檢查器程序內，與完整獨立Host證據分開。

管理端新增 `case-693-sequential-loops`，使用四個
`TARTAROS_ADMIN_STRUCTURED_MULTI_LOOP_{SCENARIO_PATH,SCENARIO_SHA256,BEHAVIOR_PATH,BEHAVIOR_SHA256}`
及既有BND目錄。profile固定來源與兩段body；可各自改ID、上限、停止旗標及重置／保留規則，
或停用某段。切換「編輯區段」只編所選body，套用時保留其他段；Server仍重驗全部JSON與AI。
暫時停用後也可從同profile啟用原區段，不允許把它改為其他body或跨段中間跳轉。

HTTP r1保留3/3，r2改為2/4，r3停用入口、保留分支4。各版ZIP皆由相同draft/revision
產生三個成對檔，r2/r3保存後r1下載bytes不變。未保存預覽不增加資料庫版本。
完整Host獨立載入三版，界限分別88/160、88/156、88/136後停止。
實際下載r2另以正常TCP完成入口兩輪／分支四輪156EXP；r3只有分支四輪136EXP，皆存檔回原隊。

啟動器可選 `-IncludeSequentialLoops` 使用固定新候選；下載配套用
`-ScenarioBundleProfile sequential` 加manifest路徑／SHA，先以固定雙段profile重驗成對內容，
再啟動Host。原prefix／branch匯入方式不變。保存／下載不會自動替換現用服務或Client。

管理頁實際驗入口2／分支3預覽140EXP，切到分支4後156EXP，停用入口後136EXP，
重新啟用入口2恢復156EXP。畫面見[預覽](sequential-loops-preview.png)，未保存此瀏覽器編輯。
精確候選、版本、路線與門檻見本批驗證收據；原生MEF、指定v2、自然新帳號、其他adapter與巢狀／跨body仍OPEN。

`GAME_RUNTIME_OBSERVATION`：同一r1成對下載稿已另啟完整Host，以真實時間、正常TCP輸入完成
兩段三輪、16次實際訪問、160EXP→39160存檔，回原村同隊。兩段決定的輪次為1/2/3、1/2/3，
各因自身上限離開，沒有共享第一段計數；九筆不同visit的成本及183×1終袋守恆，completion一次。
實際22枚投射物建立並回收；與控制時計TCP的24枚分開記錄，不要求真實時間產生相同招式數。
這是準備角色4/Lv15及教學/Q15前提，不是自然新帳號或Client人測。測後Host及隔離管理端都已停止。

三個Release零警告／錯誤，709/709 HappyPath通過、零略過。精確路線及原始收據SHA見
[本批驗證收據](sequential-loops-validation.json)。

TRX SHA256 `260b942b2448dd386106e9d8312811534cfb151dfa7d69b7c0234c58b3fce1c5`。
