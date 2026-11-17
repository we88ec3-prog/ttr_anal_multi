# 真實資源的精確補件與解除條件

這是本輪兩個原場景的原件需求，不是對使用者安裝目錄的缺檔判定，也不是新正式 RR。現有資料已能閉合函式內容、已到達依賴、選取規則與生命期；下列材料決定是否能繼續閉合 exact runtime selection 及完整 payload。

## 1. 優先補同一版本的選取環境

| 材料 | 為何必要 | 取得後的精確動作 |
|---|---|---|
| `Master.stp` 及其 `AttachedPackage` 對應載體 | 決定 directory provider；不是任意 STP 集合就能推斷掛載關係 | 固定 carrier hash，解析 `Master0z` 樹、順序與成功 binding；保留重複路徑來源 |
| `fcs.flu`，或同版本生成的完整 CHA_ABF／MAP_FLD scan entry 與目錄 | 原模型／地圖按 normalized basename 查 entry，entry 再提供 directory／filename | 用首筆 entry 保留規則重算選檔；區分 cache 與 scan；記錄實際所選 bytes |
| 原 Client 版本、鬆散檔根目錄、包／覆寫來源 | 同 basename 的候選存在不保證該版安裝選到它 | 把 package、loose file、cache 和 override 的實際身份綁到同一 context |

這些材料先於把 `Mon/02_Stoncken.abf` 或 `Mon/00_Alphonso.abf` 直接改寫成 `Character/...`。既有 Base 候選內容已解析，無需再次全量掃描同包。

## 2. 缺少的 13 個選定模型 descriptor

這些是 Q2440/5 的 Actor.FILE 正規化 basename 候選，**不是已知 runtime 完整路徑**。Q model 使用 admitted ID row，PRE 不作 key。

| Q model ID | 需要的 descriptor basename | 正式建立／原內容涉及的 action |
|---:|---|---|
| 1478 | `N01_Soma.abf` | 1、4 |
| 1479 | `N02_Pipa.abf` | 1、4 |
| 1480 | `N03_Sblm.abf` | 1、4 |
| 1481 | `N04_Isla.abf` | 1、4 |
| 1482 | `N05_Aelt.abf` | 1、4 |
| 1483 | `N06_Grnt.abf` | 1、4 |
| 1484 | `N07_Crmd.abf` | 1、4 |
| 1485 | `N08_Ruko.abf` | 1、4 |
| 1486 | `N09_Epds.abf` | 1、4 |
| 2064 | `11_SupplyCabH.abf` | 1、4 |
| 10107 | `07_Mimi.abf` | 1、4 |
| 10320 | `14_Alster.abf` | 1、4、51 |
| 10323 | `14_Tommy.abf` | 1、4 |

已解析的 Q119 model 1086 為 `02_Stoncken.abf`，所需 action 1、4、8、11、101、103；Q2440 model 102 為 `00_Alphonso.abf`，所需 action 1、4。這兩份 descriptor 仍需綁實際 selected entry，且引用的 GB3、texture、effect／sound 等 payload 尚未齊全。

取得 13 份 descriptor 後，只沿本場景實際使用／引擎隱含的路徑解析 base、TextureList、Animation、Avatar、Mesh、Face、effect／sound 等後代，新增其真實依賴。缺 descriptor 前不虛構完整後代清單。

## 3. 其他已到達的原件前緣

| 類別 | 精確材料／索引入口 | 需要保留的差別 |
|---|---|---|
| 附件 | `Character/Cha/Items.ipk`、Include 子檔及所選 descriptor／payload | 9 個顯式附件與 15 個 default item 查詢各列；default lookup 可合法 miss，不等於保證有附件 |
| 地圖 | `mushroom12D.fld`、`town014S.fld` 的真正 MAP_FLD entry、FLD 與後代 | `town014S` 不與 `town014` 自動合併；BND metadata 不代替 geometry／visual resources |
| 對話頭像 | `Image/TalkNPC.xml` 及所選 face／portrait 圖 | 12 個文字列已在現有 active table 原件解析；頭像另需 bytes 和 resolver 選取 |
| 對話聲音 | `Sound/Scenario/%02d/Locale`、相應 `V%05d.ogg`／native 候選格式 | 版本遍歷、Locale 排除與實際資源開啟結果決定選擇，不能硬選最大版本或副檔名 |
| Prolog | Prolog 19 所引用的 7 張 DDS、10 個語音候選及當前 UI 資源 | 表格文字存在、圖片候選與聲音格式選取分開 |
| 直接圖片 | `Image/Prologue/Aisen00_1.dds` | 原函式生命期可證，不代表 texture 會載入成功 |
| music／sound／effect | [依賴前緣](content-dependencies/dependency-frontier.json) 的精確 path 或 basename | direct literal 與 descriptor 派生來源分列，保持檔案大小、hash、carrier 與 member |
| 共用 context | 對話／Prolog／image 的 frame／font、先前 map／camera／music state | 必須指定入口基準；不能因 scene 本身沒宣告就假定這些資源或狀態已滿足 |

精確逐項列表以 [scene-dependencies.json](content-dependencies/scene-dependencies.json) 與 [dependency-frontier.json](content-dependencies/dependency-frontier.json) 為準。前緣條目數是目前已知圖的缺邊數，不是所有安裝缺檔數，也不是完整遊戲資源數。

## 4. 本輪已搜索的界線

本輪使用本機原附件與已有 Base／W1-W2-W3 載體，讀取選定 member；對專案檔案標題做精確與一次簡化重試，並核對 `ttr` 資料夾完整 17 項清單。沒有新增相關載體。舊的 fcs／Character／Field／Mon 精確查無結果直接復用，不重複當新進展。[source-availability.json](source-availability.json)

另對固定 `source-map-v2.json` 的 3,187 筆 `original_path` 作指定資源模式比對，沒有找到 Master／fcs／Items／TalkNPC 或相應 descriptor／載體的映射。這只證明該版 source-map 的有界比對結果，**不證明整個 repository 或使用者安裝不存在這些檔案**。

`Boot.lua`、`Logic.lua`、`Coroutine.lua` 已從該既有 Git 證據找回原 bytes 並核 SHA，故它們不再列作本輪待補原件。原文件標題搜尋結果不會推翻 Git 中實有原件；實際安裝選取則仍須綁同版本環境。

## 5. 補件後的解除條件

先確認版本與 SHA，再重算選取和僅新增的依賴；每個被選 member 保留 carrier／offset／長度／hash／parser 結果。對已取得 descriptor 的新後代持續展開，直到所選場景必要依賴閉合。可合法缺省的項目須有原生分支證據及明確內容政策，不能直接忽略。

只有當所選版本的索引、mount、所有必要 bytes 與 context 前提可追溯時，才有理由把資源 gate 從 BLOCKED 改為具備整合條件。實際 parse／render、正常結束及遊玩還原仍另驗，不以存在於 ZIP 或 STP 的一個 basename 代替。
