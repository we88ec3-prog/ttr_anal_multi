# 整合副本交付與測試入口

2026-11-23當版：[頭目查詢索引回歸](../scenario-content/BOSS-SELECTION-INDEX.md)以相同原BND／
flag-delay整合內容完成兩路舊／新完整TCP回包對照及新版獨立真實時計Host六圖、波次／機關／
分支／頭目階段／一次88EXP入庫與同村同隊返回。三Release與790HappyPath通過，隔離Host停止。
本批是執行器查詢改善，未增加或改寫關卡玩法；指定v2與自然新帳號仍分開待驗。

2026-11-23最新：[怪物 HP 工作台及保存版通關](../scenario-content/MONSTER-HP-WORKBENCH.md)
沿用波次／頭目階段／機關／分支／結算，保存版四條完整TCP及兩個最終真實時間獨立Host
均88EXP入庫、原村同隊返回；三Release與782HappyPath通過。下方舊版測試數及範圍保留歷史，
指定v2人測與自然新帳號全程仍待驗，未聲稱原生MEF完成。

2026-11-22當版回歸：[RAID循環批次的原整合控制](RAID-LOOP-COMPLETE-ROUTES.md)
使用最終Release Host重新走完整正常入口與六房、消耗機關／波次／分支／頭目、一次88EXP保存及原村同隊返回。
準備角色4Lv15、初始39000EXP；此為獨立程序／真實時間，不是自然新帳號或指定v2實機。
精確階段／timer快照仍由下方既有同程序證據支持，沒有提升為原生MEF。

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。本次要求的完整副本採用逢德斯村 Stage462 / Case693，沿用已整合的內容與正式 Server handler。本輪修正舊整合檢查器對機關帳本的比對，納入目前 V2 的訪次身分，再驗證兩條完整分支；沒有將既有成果當成本輪新增玩法。

## 本輪範圍

| 要求 | 同一場副本中的行為 | 正流程驗證 |
|---|---|---|
| 正常入口 | 廣場建立一人隊、進逢德斯村、選 Stage462 / Case693、開始 | 真正 loopback 登入及 primary 交接，遊戲意圖走 socket 與正式 gateway |
| 波次 | 第二房計時增援、依序增援 | 零擊殺時加入計時增援；三名敵人擊敗後加入下一波 |
| 機關 | 首房拾取 Product183、互動消耗一個並開門 | SQLite 已提交帳本；庫存／快捷數量先於出口開放，扣款綁目前訪次 |
| 分支 | 第三房清場、按開關，選出口3或6 | 兩路分別經 node5 / node6，在 node4 匯合 |
| 頭目階段 | 頭目出現、75%血量門檻增援 | 頭目仍 ACTIVE 時兩名護衛加入，出口保持關閉 |
| 結算與回村 | 全部清除、等待清場延遲、最終出口及結果確認 | 各路一次88EXP保存，返回同村原隊伍 |

來源與內容細節見[原整合規格](../scenario-content/MEF-INTEGRATED-DUNGEON.md)，TCP時計與準備帳號限制見[TCP驗證契約](MEF-INTEGRATED-TCP-ROUTES.md)。本輪[交付收據](integrated-dungeon-delivery-validation.json)另存，保留既有歷史收據。

整合版與投射物版各兩條分支、共四路皆通過；各保存88EXP並返回原村同一隊伍。投射物版每路五枚建立／清除，最小版保持零枚。Host、檢查器、Admin.Web三個Release建置零警告／零錯誤，HappyPath **689/689**通過、零失敗／略過。帳本保留run及有效入口visit，六個節點訪次按路線順序各建立一次。

## 配套與啟動選擇

- 最小整合：`-IncludeIntegratedDungeon`，scenario SHA `424b8d5afc3aa822e286e384c7924334ac3800b3b748c6fe521e048b5ce59026`，AI SHA `fcd7437c891d6ceff3b7584831eb931ab8fe522156cb3cae69def5324cd38701`。
- 相同完整副本加既有投射物呈現：`-IncludeIntegratedProjectileVisuals`，scenario SHA `29f4e12f69e849d39835f0d1317a1d94c1b0c0798361d49f745f4fe84c6d1ebc`，AI SHA `eaf55a1723fff3ba3b5cf52c9286e6d7e7f1264bb1049b15b732cbca49903864`。它自動包含整合版，不需再開其他比較候選。

私有 Server 的 `tools/start-phindos-acceptance-host.ps1` 需要 Workspace、AnalysisDirectory、BoundsDirectory、獨立且已完成遷移的測試 Database 及新 LogDirectory，完整命令見私有 `docs/LOCAL-MEF-INTEGRATED-DUNGEON.md`。一般測試埠為8414/8415/8416、health5082；加 `-PreflightOnly -IsolatedPorts` 僅做暫時啟動預檢並自動停止自身程序，不代表遊戲已通關。

Case693 仍是 opt-in 配套，Stage462 依既有規則輪替693/694；694保持原內容。本輪沒有替換使用者正在使用的 Host、管理端或資料庫。測試角色仍須滿足既有教學／Q15與等級資格，不用管理指令跳關。

## 驗收界線

這批是準備角色4／Lv15、教學與Q15進度的 OFFLINE_SYNTHETIC + LOOPBACK_TCP，使用檢查器程序內的正式 Server 元件與原版BND。並非自然新帳號升級、另啟部署Host的遊戲通關，或指定v2 Client實機驗收。控制時計及封包計數不當效能或畫面ACK。

`GAME_RUNTIME_OBSERVATION`：沒有新增 Client 人測結果。正常入口、機關顯示／互動、兩條分支、頭目增援、投射物呈現與結果回村仍待使用者實機驗收。原生MEF容器／解析／傳檔、Client自主生怪及完整AI移轉、動態循環與其他未完成MEF功能維持各自追蹤；完成本副本不代表整體MEF完成。非正流程維持既有待測安排。
