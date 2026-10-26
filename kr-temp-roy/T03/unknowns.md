# KR T03 缺口 — 待整合

目前parser、auth/helper/result/server-list、角色UI/RTTI/control、選服呼叫、command2角色清單資料橋接與局部UI更新消費者的有限原生證據已整合。原生欄位及政策界線見AUTH-NATIVE-REVIEW.md；另見CHARACTER-UI-REVIEW.md、SERVER-CHOICE-REVIEW.md、ROSTER-INTERFACE-REVIEW.md及ROSTER-UI-UPDATE-REVIEW.md。正式內容雜湊對應見changes.json，這份持續更新的缺口表每次版本分開追溯。不要重做成功查詢。舊逾時已解決，失敗紀錄保留。

- 本登入用法的literal空格/&分割與空token轉交已有helper/assembly依據；上游launcher如何處理輸入、OS quoting、任意編碼與失敗路徑仍未閉合。不要以已驗證的內部literal分割宣稱完整啟動器規格。
- E8/000F欄位寬度與MD5/codepage資料流已有原生依據；E8尾部+104..109、共同client+BF80值的業務意義、執行時ACP與錯誤／超界契約仍缺失，不自行補零或猜成官方version/region。
- 官方帳號驗證、失敗／重試、ticket 與連線時序缺失。account_store.py 的名稱限制、雜湊、ticket/lease 是本機替代；需官方規格或同 SHA 原生消費路徑，不能用其程式碼反證官方行為。
- T02 的傳輸封裝／連線時序尚未閉合；僅引用，不重新定義。阻塞端到端登入驗收。
- 角色清單／場景 bootstrap 與0x42對廣場回應的關聯仍不能從fixture名稱驗收。command2→記錄+5C→672F00讀取的資料橋接已確認；完整初始化／事件／資源前置仍缺，世界內初值交T04，場景回應／轉場交T05。
- 本輪不執行遊戲；所有靜態結果不能聲稱已恢復可玩流程。

## 入口補證後的縮小範圍

原歷史缺少的 login_test_server.py 已以完全相符 SHA 7385c9a5… 補得。已確認該來源快照407行的登入分支為 E8/112，411行呼叫 credentials；此來源缺口已局部解除。仍未知目前部署用哪個入口、其他服務是否有000F處理、官方驗證與錯誤／重試時序。新增證據不解除 native auth 欄位、T02 或角色／場景依賴。

## 選服及選角補證後的具體交接

- T02：66C090僅在特定row+4分支及有效row+C指標下呼叫4957C0；資料lookup及70A/578事件輸入已確認。仍需連線／重試／名稱copy契約與實際成功條件。不能把row+4的0/4/5命名官方狀態，也不能由localhost fixture推回endpoint來源。
- T04：4D4150寫+5C、4B7F00清單分段／選取及672F00消費位置已同SHA補證；仍缺真實角色名單、初值與授權來源。client ID<=9不是官方可用角色規則，不能用合成[1,3]或literal1／零值消除缺口。
- T05：F4247已有5A67D0局部消費分支，但訂閱／投遞與42之後場景前置未閉合；F42EF路由仍缺。不能用43/69固定配對宣稱轉場成功。
- T06：control12000/18000及選服F0/F4/F8物件在同版本資源的名稱／存在性未驗證。原生數值ID配對不等於實際按鈕標籤。
- T03後續候選：F4246/F4278產生／投遞、F42EF路由，以及D63DCC讀取者／F94294來源。先查共用成果與原生引用定位，再向整合者登記具體範圍；不能因一個callee出現就收編其他任務核心。

## 工具與排除限制

- 4B7F00 high-pcode/def-use標示截斷；本輪只接受另以assembly區塊與原檔位元組核對的局部事實，沒有接受完整callback語意。
- 4E5FB0觀察為TeamRank相關更新，已排除「通用角色清單刷新通知」描述；沒有沿rank計算展開。
- 4B7DC0為共用場景收包表初始化，先前T03候選已更正T02主責、roy不認領，只引用command2槽。
- roster session33920因idle_deadline正常close，exit0與關閉結果已保存；沒有執行中工具。讀既有結果不重啟引擎；若後續新查詢必要，再用新的獨立session標籤並保留舊證據。

已整合的小成果不能當作上述依賴已完成。後續開發可依已驗證的欄位／分支建立相容介面，但未知尾部、官方帳密／token政策與世界數值不得補猜；任何本機政策要繼續標AI替代。
