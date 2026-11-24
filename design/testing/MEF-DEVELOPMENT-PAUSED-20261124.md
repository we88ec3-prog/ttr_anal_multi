# MEF 開發與測試暫停交接

2026-11-24，依使用者「請暫停並更新開發與測試進度後上git」停止持續開發。
目標狀態已設為 `paused`；整體 MEF／Server 目標尚未完成，不標記完成或阻塞。
本次只更新交接與測試索引，不新增功能、不啟動或重跑測試。

## 已發布功能基準

分析庫 main：`ffd14d88cbe1533d4fa50e82a73f31490d5f5bd6`。
私有 Server main：`37560583ce6e4d9c3296d3539b1adc88355cc033`。
這是暫停文件前的功能基準，兩庫在開始整理時皆乾淨且與遠端 main 一致；後續僅追加本交接提交。

| 範圍 | 已完成的工程成果 | 證據入口與界線 |
|---|---|---|
| Case693 完整副本 | 正常廣場建隊、進村選關、波次／機關／兩分支／頭目階段、結算、原村原隊伍返回；保持既有版本 | [整合副本交付](INTEGRATED-DUNGEON-DELIVERY.md)。準備角色的合成／TCP／獨立 Host 證據，非自然新帳號或指定 v2 人測 |
| 必要頭目血量 | `BossHealthReached` 依 requiredBoss 的 model／PRE／wave 與個別 HP 判定，護衛不加入分母；管理選項、schema、獨立配套已提交 | [契約與範例](../scenario-content/BOSS-HEALTH-SIGNALS.md)。75%／50% 各兩條完整 TCP；獨立實際時計 Host 只涵蓋 r1 的一條分支 |
| 一般主線返村演出 | 已確認成功／結果接受後，可跳過 ReturnScene 並保留正常成功結算，不偽造003F | [成功返村跳過](../scenario-content/STORY-SUCCESSFUL-RETURN-SKIP.md)。Q119 TCP／Host；Q132 另有 domain 終點與目的村比較 |
| Q15 到村演出 | scene3／4 跳過仍由正常授權流程保存 stage4，保留自動私密一人隊伍；同連線完成 Q117 NPC 後返廣場 | [Q15成功到村](../scenario-content/QUEST15-SUCCESSFUL-RETURN-SKIP.md)。兩條 TCP／兩個獨立 Host，實機待驗 |
| Q15 開場取消 | scene1 本機演出約定／Server scene2 取消不建立階段或授予進村資格；同連線正常重開兩圖後才 stage4 | [Q15開場取消](../scenario-content/QUEST15-INTRO-ABANDON.md)。兩條 TCP／兩個獨立 Host；Town5／廣場映射仍為既有 Server 候選 |

## 最新測試基準

最新一批不是本次暫停時新執行；以下核對的是已保存收據：

- Release Host、LocalTutorialInspect、Admin.Web 均零警告／錯誤。
- **827 HappyPath 全通過，零失敗／略過**。TRX SHA256：
  `642082c1702ffca8573779a90cf6a7d22dc61c6bf43726d8f82079d82f638c3d`。
- 頭目血量兩個 HTTP 保存／匯出版、四條 TCP：每路一次88 EXP、同村同隊返回。
  階段增援時頭目180／240或120／240 HP，同波護衛1140／1200或1080／1200 HP，組血量仍高於所選門檻。
- r1 獨立實際時計 Host 通關88 EXP；正常綁定並消耗已拾取的183復活續戰。
  停止後 SQL 副本讀回累積39088、一次完成、入口成本183×1、回村183×1。
- JavaScript 語法、實際回應位元組、CSP／SRI、三份 schema 一致性與生產載入驗證已核對。
  **這不等於新選項的瀏覽器互動通過**。

[完整收據](boss-health-signals-20261124.receipt.json)，SHA256：
`2fb0cb82cab7a82f2ca391e4d0448b8548279258bcdbc1e0e6f8e96cd09e42dc`。
失敗的測試範本／HTTP cookie／檢查器倒地與快捷綁定等收據保留，沒有混入成功數。

## 明確未完成與恢復入口

1. 新「必要頭目血量」選項的實際瀏覽器操作：選取、切換事件、百分比欄位、保存、重載與歷史版。
   暫停前只讀取 computer-use 操作規則，**尚未啟動本輪新管理端或執行瀏覽器輸入**，無新增通過紀錄。
2. `BossHealthReached` 在主線／RAID 的完整定向路線；共用執行器已接入，但不能用 Case693 代填各 adapter 驗收。
3. 指定 `Tartaros.ip-zh-tw-only-v2.exe` 的正常入口、演出中斷、鏡頭／輸入、NPC與返廣場、頭目階段等人工驗收。
   自然全新帳號到Q144、Town3／Map199仍須完成指定版本實機驗收。
4. 原生 MEF 容器／載入傳入、Client自主生怪與完整AI移交仍未閉合。
   現有 Server 關卡格式與本次功能一律 **NOT_NATIVE_MEF**；不得宣稱已開發原生 MEF 檔。
5. 重送／重登、故障、併發、安全、壓測等維持[既有暫緩清單](TUTORIAL-HAPPY-PATH-AND-DEFERRED-TESTS.md)，
   沒有因正流程通過改列完成。商城與其他系統也不因本次827項總數而獲得整體實機通過認定。

待使用者明確要求恢復後，先由上述瀏覽器未完成項接續；沿用固定來源與既有陰性範圍，
只對新增／變更載體補 MEF 來源檢查，不重掃已做過的整週路線。
使用既有 normal bundle／新資料庫副本驗證，保留原件與舊版；不自動改現用服務或 Client。

暫停未關閉或換版使用者原有 Server／管理端。上一批隔離 Host 已在收據確認停止；本次沒有新增測試服務。
公開分析保存本文件／規格／schema／收據；實作留在私有 Server 庫。
實際工作目錄仍是 workspace 下 `s00-runtime-dev` 與 `server-runtime-dev`，直接 main、保留歷史、不 force push。
