# S00：Quest15開場NPC／對話目錄與控制恢復候選

目前目標為全新帳號正常進入馮德斯村，本輪準備廣場第一段的正常接續；未部署或要求玩家重測。

## 原始Table資源的實查

[唯讀檢查器](../inspect_quest15_intro_catalog.py)／
[精確載體、member SHA、欄位與文字存在metadata](evidence/S00-20261102-QUEST15-INTRO-CATALOG.json)。
原始Table載體仍為09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442。

- npctable NPC10338的TYPE為10，名稱테티스，GUILD為시나리오 담당관；NPC自身talk ids為28724／28725／28726。
- Quest15/scene1的Event body呼叫OpenTalkScene(3,22)，見前輪已釘SHA腳本資料。
- ScenarioTalkTable的Scenario id3／scene22列char10338與talk2314～2319，共6列。
- 這6個文字記錄存在於TalkTableSet列出的Table/TalkTable/02_Lenart.xml；本輪不公開原始對話本文。

NPC自身對話組與腳本對話組不同，不把28724混進場景3/22；
Scenario id3也不能直接當TalkTableSet第三個檔案。NPC表TYPE10、actor category、scene mode、Quest ID分域。
這是精確資源連結與存在性，未全文驗證文字／NPC dispatcher，也不保證Client當場一定選中Quest15。

## Server候選：只恢復現有廣場控制

明示前置發布模式下，廣場bootstrap已準備過committed snapshot，且廣場仍loaded、
有現存Server pose、沒有戰鬥時，精確3F／Quest15／scene1／value1 receipt可觸發：

1. 清除requested movement並停止現有Server pose，回報目前位置，不另選新spawn。
2. 重送相同owned actor／alias的bind及既有candidate Parameters。
3. 發送PrimaryQuest15IntroReported這個固定metadata事件，不記原始payload、NPC欄位或帳密。

這是因演出RestoreMap後可能需恢復binding／輸入的**Server重建候選**，不是已證原版必發ACK。
queued snapshot／receipt都不是Client delivery／演出成功證書。Value1也可能由清理路徑產生，
故此receipt不會完成Quest15、發獎、切新scene、重建NPC或傳送玩家至村落。
Parameters仍是本候選既有廣場顯示／速度配置，沒有新增戰鬥傷害或可持久化資產授予。
未啟用發布的v10／原路徑不進此handler，沒有讓任意一般3F重設控制。

## 驗證及接續

26個HappyPath通過。新增模式的正常TCP旅程在收到完整6F、廣場player/NPC後，
送source-shaped intro receipt並核對停止位置900/900、相同alias／entity bind，
再正常移動及放開到906/900；讀取實際journal確認固定IntroReported事件。
獨立SQL仍只有keys14/16及pending entitlement，沒有Quest15 key／付款／進村紀錄。
這是合成正常旅程，不是假裝點過真NPC或看完真對話；沒有live換版／migration／Client修改。

目前仍需閉合：NPC10338實際選項／1C事件欄位、15/1之後的接取與場景排程，
以及普通Town1 controller／合法spawn。第一段能恢復控制不代表2～4段與進村已完成。
W2明日工作卡已補本目錄與最新實作狀態，保留所有未證項。
