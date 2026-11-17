# Server 開發需求與採用契約

本文件供既有 Server／內容 owner 去重採用，並非新建正式REQ／RR、接管他人工作或宣稱已實作。固定來源為 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa` 的內容候選、schema與[需求台帳](../../design/requirements/index.json)；完整pins在[source-manifest.json](source-manifest.json)。本輪不執行Server。

## 1. 可用基礎及分工

已有合法有限演出入口、121 binding的ABI／勘誤、22 owners的生命期契約、Q119實際scene資料、普通world消息、NPC／point／服務等原生adapter。先用這些已證路徑形成可驗收Server流程，不需要等待普通背景B或任意world→Lua接口。[P0／P1判定](P0-P1-COMPLETION.md)

Server持有權威run、instance、actor generation、HP、死亡／移除原因、敵群、任務、資產與持久進度；Client的畫面、Qslot、getter、FSM、erase及封包回報只是各自相容通道。內部增加eventSequence等欄位，不代表可把它們任意附在原Client不讀的wire上。[world契約](world-lua/contracts.json)

## 2. 建議實作順序與驗收

下列順序是本輪開發建議，沿用現有REQ脈絡；不重排正式產品台帳。驗收欄是後續應取得的工程／正常旅程證據，本輪僅完成分析輸入。

| 次序 | Server開發需求 | 最小具體產物 | 驗收要點／既有脈絡 |
|---:|---|---|---|
| 1 | 內容版本與typed selector | 將本版ABI、scene鍵、model ID／Qslot／world ID、Map／Field／ShopNo／NPC等分域；資源狀態綁hash | 錯誤arity、bool代number、stub／無回值ACK、未知B能力均拒絕；REQ-0010／0017／0018／0019／0021 |
| 2 | run／scene排程及生命期 | 每run的busy、current scene、合法起播／取消／timeout、owner退出與跨圖／重連策略 | 普通NPC既有本地起播分支不能再由001C無條件重播；003F／00EB各按有限語意，不當全owner完成；REQ-0017／0018／0019 |
| 3 | world權威及既有wire投影 | actor生命期鍵、HP snapshot、唯一Died transition、Removed(reason)、outbox／去重與世代檢查 | 0000比例、0034絕對值、000E效果、000C狀態、001A erase分開；不以畫面0、native bool或erase提交擊殺；REQ-0016與既有戰鬥owner |
| 4 | 四節點戰鬥／出口 | 依現行Entry／GroupCleared／InteractZ採用Cluster、合法點位及逐節點portal政策 | 前三節點清組後建立matching point；第四預登記關門後更新；001C檢instance、distance、資格與目標；REQ-0016／0019 |
| 5 | 結算、回城與後續進度 | result／任務／資產／等級原子提交、返回world snapshot、119/5與Q120接續 | 重送／重連不重複獎勵；Q119完成後Q120需level8、NPC10008；控制、NPC與持久資料一致；REQ-0019及其GAP-PROGRESS-0001脈絡 |
| 6 | 服務、教學與後續功能 | 原有服務context與交易serializer、背包／貨幣／強化／保存；Tutorial權威進度 | Shop2→NPC10030→Product2614→Item2607分域；校數量／價格／資格／消耗，成功後資產一致；依REQ-0021既定主線後功能順序及REQ-0010／0016教學脈絡 |

現行六項REQ-0010／0016／0017／0018／0019／0021在所固定台帳皆為CANDIDATE。本文件沒有提升或另外建立其正式狀態；服務例也不是宣稱REQ-0021已接受新的強化完整規格。[旅程既有需求摘錄](journey-families/data-evidence.json)

## 3. Q119 的具體編排接點

Quest119前置118、Town1、Field26、Case107、NPC10047。現行四節點為Map632／633／634／635，對應原Chart4／3／2／1與候選Cluster1／2／3／4；演出配置為119/2入node1、119/3入node4、119/4清node4、119/5返回。119/1仍有`LoadMap("")`及完整phase／restore，不因Blank名稱跳過。[十步旅程](journey-families/contracts.json)

| 節點 | `preRegisterClosed` | 開發端採用方式 |
|---:|---|---|
| 1–3 | false | 清組建立出口時先維持完整0027 point snapshot，再視需要更新；0048不創建不存在的點 |
| 4 | true | 入場snapshot含關閉的key4；清組前確認該matching point仍存在，再按0048更新 |

這是候選配置的發布契約，未宣稱現有Server實際已送對snapshot。0027替換共用集合，建立出口時必須保留同時仍應存在的NPC／shop／其他point；跨圖清集合後的舊delta不可作用於新context。內部generation／seq是Server責任，不能藉在legacy payload加未證欄位解決。[portal政策](journey-families/contracts.json)

現行外部scenario schema只接受events `Entry / GroupCleared / InteractZ`，actions `SpawnGroup / UnlockPortal / NextNode / Result`，多層`additionalProperties=false`。mainline候選的`enterScenes / clearScenes / returnScenes`在另一層。應接既有scene adapter／編排，或作明確版本擴充，不能把研究JSON或任意`PlayScene`直接當既有schema部署輸入。[原schema](../../design/scenario-content/local-scenario-definition.schema.json)、[context重驗](baseline-replay/server-context.json)

## 4. 驗收分層

先核內容schema、來源hash、ABI與typed IDs；再驗Server狀態、交易、serializer、重送／取消／重連及ID重用。最後依專案允許的正常Client流程觀察聲畫、輸入、可走動、NPC、完整結果／返回及持久進度。實際原件與資源選取未齊的profile不得被資料級PASS自動升成完整聲畫ready。[SOURCE-REQUEST](SOURCE-REQUEST.md)

圖形Q RestoreMap僅恢復所持視覺map／camera資料，不建立普通world actors／controller／points，也不替Server回城。B入口與world→Lua橋接若成為產品明確需求，另以具typed owner及事件身分的實作／原件證據驗收；現階段Server排程不假設這兩項已存在。
