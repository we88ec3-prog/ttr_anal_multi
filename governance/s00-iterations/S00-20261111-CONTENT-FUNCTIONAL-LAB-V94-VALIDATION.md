# S00：v94功能場驗證

對應穩定契約S00-20261111-CONTENT-FUNCTIONAL-LAB-V94.md；原v93資料另存
functional-lab-v93.scenario.json與functional-lab-v93.monster-behavior.json，保留精確bytes。
現行functional-lab兩份JSON已改指v94契約的實際SHA，沒有用標籤摘要冒充文件SHA。

五項相關正常流程驗證通過：三種場景入場及生怪距離、清怪後回進場位置仍可生成
無區域限制的第三隻、獨立區域場在圈外等待並顯示ENTER_REGION、返回進場處才生成。
原位姿／物件生命週期、兩類時鐘與不提交正式任務的保護維持。
實際BND檢查三組的玩家／全部怪物出生點及97點走道皆可走；沒有宣稱圓面／動態碰撞通過。

新Scenario SHA256 `8d3bab165a6ee0db7de1a03ec3720dc96a20a71e1be64a01ce3719027c451a63`。
新Behavior SHA256 `9cb926d45a4c81083a5791e069b618e5ebee919bc63c906fe38e0e8cce0fe989`。
部署、完整受影響回歸與人測結果分開追加；這份資料仍是NOT_NATIVE_MEF。
新怪物選招能力未配置於這些場景，不能由本輪人測替其驗收。

332項受影響的HappyPath旅程回歸通過，包括新選招與舊近戰相容行為。
不執行延期的負向／安全／重登／壓測。新場景實機仍待部署後補測。
