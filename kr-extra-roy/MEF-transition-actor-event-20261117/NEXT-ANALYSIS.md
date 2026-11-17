# 下一階段建議：先解除可落地切片的資料門檻，再追唯一事件缺邊

## 1. 優先：把Case103轉場profile真正綁成一個版本

依本輪列出的缺值，取得原出口配置或由S00選定重建政策，明記portal category/key、世界XY/radius、Map192 spawn、控制關聯record與world actor快照。把候選與採用紀錄分開，對所採值保留來源與正常驗收責任。

本輪0008→000A依賴已閉合，不需要再從最上游登入重掃。先以小工具核對同一profile完整性、字典分域與發布偏序；缺值即阻止發布，不填0。Server可同時實作generation／outbox／權威node；這不是Client逆向阻塞。

完成門檻：一份沒有未知部署欄位的相容profile及可追溯來源，另行正常流程實機驗收。BND零值及格式PASS都不代替人測。

## 2. 並行：取得一個真實avatar descriptor，而不是改查更多API

以已證source model(category0,ID1,PRE1,FILE=soma)沿79E980模型目錄、79FBC0的(part<<16)|variant查找，記精確carrier/member及descriptor欄位。選一個實際支援的part、新variant與原variant，確定需要的資源，綁到一個Server已知world actor。

接著由內容／Server規劃獨立apply與restore入口；不重用A1的32760去覆蓋切點目的，不把數字相同當實體相同。這能先交付一個真實外觀功能，而不用等所有戰鬥事件轉交Lua。

完成門檻：descriptor存在且consumer一致、世界身分跨兩操作不變、有限退出與資源狀態分開可觀察。沒有descriptor只保留條件式規格，不造可見性承諾。

## 3. 定向深查：CAIControl／world結果的Lua出口

本輪新的writer和reader已定型，下一條證據必須能把54AA60或同一typed資料域連到真正registered wrapper／callable consumer。先沿候選wrapper的callee資料流及其返回值push查證，而不是再次廣搜dead/count名稱。

若目標改為死亡／群清，須先定位同一EntityId/lifetime的死亡／移除原因writer；不得將000E的target選擇、predicate4C96B0、00DF任務意圖代稱死亡完成。若沒有新正向入口，保留有界阻塞，先由Server權威判定＋既有0047有限內容觸發完成實際功能。官方MEF格式及B入口另線保留，不讓它們阻塞已有A類切片。

## 交付與效率

每輪必須說明「解除了哪個功能阻塞、增加哪個可實作契約、尚缺哪條資料流」。引用已證來源，只對缺邊追加BIN-first；模型測試數／指令數不是功能完成率。新的部署值採用／遊戲執行仍遵守授權，不由研究者默認。
