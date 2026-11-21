# 有限入口重訪工作台

2026-11-22，SERVER_DESIGN_CHOICE，NOT_NATIVE_MEF。延續
[有限重訪契約](FINITE-ENTRY-REPEAT.md)，將同一編譯器接入管理端的已保存版本。
本項不新增 Client 行為或格式，不把 UI 匯出當實機通關。

只開放未展開的 Case693 七節點入口範本；已保存的關卡及 AI 必須通過原工作台
來源、圖序、旗標、AI 與 BND 檢查。操作以 draft ID、明確 revision、profile SHA
和 2～16 次為身份，不讀取未保存的文字或自動改成最新版本。

先顯示預覽：來源版本與雙 SHA、logical/chart/map 對照、原／新路線 EXP 和
一次性結算 EXP。旗標／profile 數量等編譯限制仍可能拒絕過大的計畫；不承諾
每份自訂內容都能展開至16次。下載再次從同一不可變版本編譯並驗證幾何及完整
Case693 adapter，保留每次旗標、道具成本與獎勵次數。

ZIP 保存來源關卡／AI、明確的 .repeat.json 計畫、編譯後 .scenario.json／
.monster-behavior.json、編譯 manifest 及工作台發佈 manifest。發佈 manifest
列每檔 SHA、來源 profile／draft／revision 和 Host opt-in 環境設定；ZIP 固定
檔名與時間，對相同來源／revision／次數逐位元組可重現。所有編譯 JSON 使用 LF。
匯出不更新草稿、不重寫資源、不改 DB 進度、不部署或重啟服務。

預覽及下載沿用 loopback 管理端與 antiforgery POST。沒有使用者可寫的輸出路徑。
管理員解壓至新目錄，依 manifest 設定 Scenario／AI 路徑、SHA 與有限重訪 mode，
完整 Host 預檢後再批次換版。原件、原草稿與歷史版本保留。

正流程驗證應涵蓋兩個重訪次數的預覽／實際 HTTP ZIP、來源與輸出 SHA、編譯
可重現性、固定 revision，再將實際下載的配套送入正常建隊 TCP 通關。Client
畫面、原生 MEF、自然新帳號升級及目前暫緩的非正流程套件維持分開待驗。

## 本批正流程證據

實際HTTP表單保存r1，再保存結算24EXP的r2。之後仍從r1預覽及兩次下載2／3次
配套，分別是92／96EXP，結算維持20EXP；同版本重複ZIP bytes相同，七個固定
檔名及六個內容SHA全部核對。來源關卡與AI保持原bytes。已停止自己的管理端。

實際下載的3次配套兩條正常TCP路線均經11→12→10→1→3→5或6→4→2，三次
入口各付出一個183；各一次96EXP結果、存檔及同隊回村，24枚投射物建立及清除。
工程角色4／Lv15、可控制時計、檢查器程序內正式gateway；不等於獨立Host遊戲通關。
瀏覽器點擊、指定v2、自然主線升級及非正流程測試未執行。

機器收據見 [finite-repeat-workbench-validation.json](finite-repeat-workbench-validation.json)。

Release Host／Inspector／Admin.Web 最終建置通過，HappyPath671／671。管理端新增2個配套正流程案例。初次helper可見性與route delegate分析器問題已修正；檢查器曾因運行中TCP鎖檔重建失敗，待原路線正常完成後重建，並以目前Release再次通過相同下載配套的兩路TCP，未把失敗嘗試改記通過。
