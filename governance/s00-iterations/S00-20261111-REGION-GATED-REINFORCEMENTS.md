# S00：玩家區域條件與清波延遲共同控制增援

類別：SERVER_DESIGN_CHOICE／自訂關卡功能，NOT_NATIVE_MEF。
接續順序波次執行器；不是Client自主生怪，也不新增傳檔opcode或修改Client。

## 可重用內容規則

每筆`reinforcements`可選填`activationRegion`，未填或null沿用原本清波＋延遲規則：

```json
{
  "id": "corridor-reinforcement",
  "delaySeconds": 2,
  "activationRegion": {"x": 520, "y": 500, "radius": 3},
  "encounters": [{"model": 1009, "x": 526, "y": 500}]
}
```

此處數值為合成測試設定，不是正式地圖配置。座標採目前地圖的Server世界座標，
不採小地圖像素；region也不會自動建立原生傳送點／效果或觸發C2S事件。

產生下一波必須同時滿足：

1. 上一波所有怪物已由Server戰鬥層判定死亡。
2. 從確認清波的單調時鐘起，`delaySeconds`已到期。
3. 若有region，玩家當下的Server位置位於圓內，邊界包含在內。

先進圈但延遲未到，不會提早生怪；延遲到期時已離圈，繼續等待進圈。
這是當下位置條件，不是記憶曾經踏入的事件；也不做兩次Poll間的掃掠路徑判定。
每波僅生成一次，之後游標前進。最後一波之前不發布勝利、戰後劇情或開門。
既有玩家資源、冷卻、怪物ID分配與死亡移除期限保持原順序波次規則。

一般故事node及馮德斯兩圖adapter均使用同一條件與戰鬥執行路徑。
載入時驗證有限X/Y及正有限半徑、所有怪物出生點，以及region中心可站立。
中心通過不等於整個圓面可走，正式關卡仍需逐圖配置與實機。
故事診斷列出下一波ID、delaySeconds、activationRegion；不代表Client已知或接受此條件。
條件、計時與波次游標只屬副本實例，不加入主線存檔。

## 交付與驗證界線

更新後[完整schema](../../design/scenario-content/local-scenario-definition.schema.json)
SHA256為`8e53732a5300cd1bc56f73dce1ddcd4f08da16c42d39fded889730c4978cd60d`。
前一版無區域條件的schema另存
[順序波次初版](../../design/scenario-content/local-scenario-definition-waves-v1.schema.json)，
保留舊版精確bytes及既有SHA。

4項相關正流程測試通過，包含延遲與區域的交集、離圈後等待、只生一次、
資源保留、一般故事內容編譯及既有順序波次。Host Release建置通過。
314項受影響正流程回歸通過（包含上述相關項目）；不執行延期的錯誤／重登／安全／壓測套件。

區域增援已隨v92啟用；原v91兩組人測已有平移觀察，末端動作仍待修。
正式關卡尚未新增region內容，也沒有新的實機通過主張。
定時並行增援已另外實作，見S00-20261111-TIMED-REINFORCEMENTS.md；
條件分支、任務旗標／道具條件及Boss階段仍未完成。

## 可交付的內容範例（v92）

新增[區域／順序增援編寫說明](../../design/scenario-content/REGION-WAVE-AUTHORING.md)
及獨立region-wave-example.scenario.json。範例經v92 typed loader與實例Enter載入成功，
含第一波、區域條件第二波、純延遲第三波。JSON SHA256：
`2bf0b3e9fab7e3ab23efc5c7fee1089404db9c47f5bc190e9cf4f307c697498b`。
這是作者示範，未替換正式內容、未驗證全部BND幾何或Client人測；
不將載入成功算作原生MEF、完整場景或怪物AI通過。
