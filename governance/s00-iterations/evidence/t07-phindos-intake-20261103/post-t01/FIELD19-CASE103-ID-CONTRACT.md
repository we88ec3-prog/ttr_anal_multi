# Field19／Case103：0038預載key的原生查證

roy，待整合。原BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；REA6.5.0／Ghidra12.1.4既有bulk，Python3.10.6／Capstone5.0.7僅核對檔案bytes。原始Table carrier SHA09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442。未改client／Server，未啟動或附加。

## 重要結論：class叫Stage，字典key卻是CASE ID

原生0038／4B1BF0的type2、type6分支讀WORD message+7給540980，經541AE0查FD8EFC的字典。53E3F0解析`Table/_CaseList.xml`，將`ID`存record+0、`STAGE`存+4。53E5E3取record+0組pair(key,record*)，57EF20把pair複製到tree node+0C/+10，再57E850依node+0C比較。48CB20原件bytes明示將FD8EFC傳入53E3F0；541B4B查找端同用FD8EFC。因此**WORD+7對此預載路徑是Case ID，不是STAGE欄位、更不是Quest或Map ID**。

原件字串另核對：BFB82C=`ID`、C0D574=`STAGE`、C0F3E4=`Table/_CaseList.xml`。Stage::Release字樣只證明類別命名，不能據此直接把欄位叫Field19並填19。此處的明確鍵來源補足前批仍未定案之處。

| 域 | 馮德斯道路已查值 | 證據／限制 |
|---|---|---|
|任務Quest|15|原始QuestInfo type2、field19、giver/finisher10338，沒有AcceptAction/CompleteAction|
|邏輯STAGE／Quest.field|19|Case103的STAGE=19，Quest15.field=19；不能直接取代其他域|
|CASE／0038 type2/6的WORD+7預載key|103|原始CaseList中STAGE19唯一該列；按ID做字典key的原生鏈已閉合|
|MapChart節點|1→2|CHART_S_pathofpindus_01，第一節點type0、第二type1，對應191／192；x/y是graph呈現資料，不能作出生座標|
|實體Map selector|191、192|原始MapList的TRIGGER=S_pathofpindus01/02.mef；MAP=scenario_pathofpindus01/02D；BOUND=scenario_pathofpindus01/02|
|村落資源|town001D|Quest15/3現用seq與T06既有Map182資源關聯可引用；不因此證明合法進村context／出生位置|

原始Case19屬STAGE6（reservoir）；Case15亦不是本次Case103。因此在這個預載欄位填19或15，會查到其他案例而非馮德斯道路。現有教學Server0038把scenario14直接放+7的做法，雖有局部可玩回報，也不能作一般副本原生規則：原始Case14其實STAGE4/fullmoon。此處只記錄ID域風險，不修改已手動驗收的前段教學，也不聲稱因此已證先前執行錯誤／崩潰。

## 尚未由此推導出的欄位

0038+3在town type0有TownID用途；其他類型會寫map/field manager+90等欄位。尚未完整查其consumer與+5語意，本次不把+3填191或19當作已證。0038整體至少讀到+8只是入口存取下限；沒有恢復完整官方長度或後端序列。

004E/0028的選定ID也不能因已知Case103就改成103：本輪只已證004E WORD+2保留並在0028回送，最終它與Quest15/Field19的合法要求鏈仍待查。0012則確為獨立DWORD Map selector。不同域務必在Server資料結構中分開保存，避免用一個scenario變數通吃。

一般Scenario使用005F/type2，與0038/type2的數值域彼此獨立；保留前批安裝/reset/ready偏序。Case預載成功不等於實體map、bounds、角色生成／控制綁定或任務勝利成功。

## 相鄰結果接口的有限排除

原生base callback S2C004B→4B34F0只把WORD+2存主物件+6860；此處本身未設TUTO完成旗標或回城。S2C004D→4B3510會轉發C2S0036＋WORD message+2（4bytes，FBA798==0），並非村落安裝入口。這些有限行為不足以決定任務成功／發獎；一般Scenario仍不可套用TUTO獨有004C handler。

## 保存與後續

case103-evidence.json保存原始Case／Map選定列、來源SHA、8項有限核對。Field.stp目前carrier SHA18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a；chart／cluster是現用資源快照，不宣稱pristine。cluster只描述可能群組與預載，不把COUNT列相加當官方總擊殺／波次或勝利條件。

接續需查：004E ID來源與一般0028回覆、0038+3/+5 consumer、最後map節點的達成回報與村劇情15/3時機；之後才完整化雙向旅行、村／廣場合法位置與重綁。T01本批尚未包含此新結論，不把新增快取或8項check當作可玩驗收。
