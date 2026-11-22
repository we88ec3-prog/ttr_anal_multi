# 副本節點訪次與機關帳本 V2

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。實作
[DRAFT循環計畫](DYNAMIC-LOOP-EXECUTION-PLAN.md)的訪次及扣款基礎；尚未放行
有環來源圖，也沒有宣稱完整動態loop、旗標作用域或原生MEF完成。

## Runtime身分

每次有效Enter由Server建立不可變NodeVisit={id,sequence,node,nodeVisit}，
id為非零GUID，sequence是本場進入順序，nodeVisit是同一logical node已進入次數。
第一次Enter之前沒有訪次。fork複製既有歷史及計數，不產生新身分；其後在fork
進入下一圖只改該副本，來源不變，未採用的規劃不會扣款或外發紀錄。
換圖等待Enter時，最後已進入的訪次仍保留為歷史；active互動仍要求Entered。
wire chart/map、點key、角色與任務權威均沿用原介面，不把訪次塞入Client封包。

權重及旗標條件出口的快照改以visit GUID索引，另記Visit／VisitSequence，
歷史依實際訪問順序輸出。當前查詢同時核對訪次的node與游標；fork／換圖／
結算保留紀錄。內容定義沒有新增欄位，所以舊JSON與固定編譯配套SHA不變。
診斷與正常副本完成摘要包含currentVisit／nodeVisits，與舊node/map路線並列。

## 已提交扣款

LocalScenarioGateConsumption增加末尾可選Visit，缺省為空GUID，保留舊領域
呼叫的去重語意。正式世界adapter只從目前instance取得非零訪次，不接受C2S
提供visit；提交回旗標時同時比對run、內容SHA、node及visit。每筆成本仍先
經授權帳號／角色、共用背包與SQLite交易提交，成功receipt才可設立機關旗標。
新帳本主鍵是account/run/node/visit/interaction，因而兩個合法訪次可以各扣一次。
它並未單獨解除重訪時既有機關旗標，仍需後續旗標作用域及循環控制。

## V1遷移與相容性

第一筆已授權機關操作在原有交易內確認舊V1 component，再檢查canonical表
是否已有visit_id。V1表會改名local_scenario_gate_consumptions_legacy_v1保留，
新版同名canonical表複製全部歷史欄位並加空GUID訪次；不刪舊表／改寫歷史值。
visit_id使用與既有SqliteLocalDatabase.Id相同的帶連字號36字元GUID格式。
空GUID為00000000-0000-0000-0000-000000000000，也是SQL欄位缺省，讓原有
未帶訪次的寫入維持舊身分語意。V2 marker為獨立
local_scenario_gate_visit_component(version=2,
LOCAL_SCENARIO_GATE_CONSUMPTION_V2_NOT_NATIVE_MEF)，保留舊V1 marker。
新訪次使用新主鍵；既有帳本的帳號、run、node、key、hash、角色、商品、數量
與提交時間都保留。未知component仍拒絕，不把異常資料庫當成成功遷移。

## 驗證邊界

正流程涵蓋：Enter建立／fork不新增／下一圖新身分／來源fork隔離；既有V1
歷史7件及時間保留到canonical空訪次與舊表；相同run/node/key的兩個新訪次
分別扣2與3件，只新扣5件；舊缺省呼叫仍可用。初次測試曾抓到GUID格式不一致，
已修正後重跑，不能把初次失敗列成通過。

正常TCP另核對訪次歷史與每圖快照、分支選擇、機關ledger及完成摘要相符。
使用準備角色4／Lv15，既有條件分支與三輪固定prefix控制組，不把固定展開
當成同logical node實際循環。指定v2、自然新帳號、獨立Host遊戲驗收另列待驗；
重送／重登續關、併發、故障與壓測按既有清單暫緩。

## 最終證據

[工程收據](scenario-visits-validation.json)包含四條正常TCP：條件兩路各88EXP，
固定三輪prefix兩路各128EXP，均存檔回原村原隊伍。逐圖訪次GUID唯一、順序
連續，完成摘要與每圖快照一致；機關SQL記錄與目前訪次相同，分支記錄亦綁
對應訪次。prefix每條三筆扣款，仍是不同logical aliases，不是同節點循環通過。
舊單房／兩房六個編譯配套bytes保持相同。隔離Host載入相符prefix配套及128EXP
後停止，僅證配置。三個Release建置零警告、零錯誤；685項HappyPath全通過。
