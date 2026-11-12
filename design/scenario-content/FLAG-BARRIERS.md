# 旗標控制通行屏障

主線外部關卡可在節點加入 `barriers`，每個矩形指定一個開啟旗標。旗標由既有的清場、延遲、區域或互動事件產生。Server 只根據目前已提交的副本狀態開放通行，同一副本內已設立的旗標會保留。其他副本不共用屏障狀態。

```json
{
  "barriers": [
    { "minX": 385, "minY": 389, "maxX": 387, "maxY": 395, "opensWithFlag": "exit-gate-open" }
  ],
  "signals": [
    { "flag": "exit-gate-open", "event": "ClearDelayElapsed", "delaySeconds": 5 }
  ]
}
```

每節點最多 16 個矩形。左上界包含在內，右下界排除，使用 BND 格中心落點判定整格是否封閉。重疊格須等所有涵蓋它的屏障開啟。矩形需在地圖內，玩家與怪物出生點及事件區中心須避開封閉格。旗標須由本節點或每條可達路徑上的前置事件產生。若屏障與事件位置分隔兩側，仍需實際驗證玩家能從可達側操作開門。

玩家走路與技能位移、怪物移動、尋路、投射物，以及直接命中與互動，都使用該副本的碰撞。屏障開啟會清除怪物舊的繞路結果。BND 原有牆面仍然有效。門與出口開關可共用旗標，也可各自設定條件。

本實作用於 Server 的通行與戰鬥判定。Client 的 3D 門、開門動畫及本地移動碰撞仍待對應。測試頁的座標是 Server 依輸入估計的位置。

## Q119 候選

[Q119 屏障版](story-q119-barrier.scenario.json) SHA-256 為 `38d0b2526afcda8f2862fffd88c9cfaa74ddd89f1fa7d9f8b78e938b3ecb2d83`。第四圖 635 的出生點與出口之間有一段短屏障，清場劇情結束後五秒，同一旗標解除通行限制並開啟出口。座標與五秒為 Server 候選編排，使用 `NOT_NATIVE_MEF` 格式。 [載入方式](STORY-SCENARIO-OVERRIDES.md)

地圖 `mushroom12.bnd` 的 SHA-256 為 `0adeeef7c1a183642a3e49a321e80c191b6dd3c8243f4e2f4ff7d16b5290c653`。沿出生點 `(379.5, 391.5)` 到出口 `(391.5, 391.5)` 每 0.25 單位取樣，兩層 BND 皆可走。疊加屏障後，直線上 `x=385.0` 至 `386.75` 的樣點封閉。實機驗收另列 GB-01。 [批次測試表](../testing/S00-CONTENT-BATCH-TESTS.md)

## 遊戲內開關標記

屏障可加上 `marker`，指定 `key`、`x`、`y` 和 `radius`。Server 使用既有 category 0 點呈現開關。原版 Client 的 `0048` 處理器會找已登記的 key 和 category，更新狀態，再由 category 0 分支選擇傳送點特效。 [Client 點狀態證據](../../governance/client-variants/20261109-mef-town-services/scenario-controls.md)

入場或劇情後重建地圖時，`0027` 完整清單會重新登記標記並反映已提交旗標。旗標在場內改變時，Server 發送一次對應的 `0048`。標記按 Z 不會開門、換圖或結算。由於 Client 可能在標記開啟後選到該點，標記互動圈須避開真出口、可操作的機關及其他屏障標記，中心也須在可走格。每節點完整點位清單上限為 32。這個標記沿用傳送點外觀，實際顯示與 3D 門動畫仍待分別驗證。

[Q119 標記版](story-q119-barrier-marker.scenario.json)的 SHA-256 為 `0c16eeb12cb7aafa19ed91e9e7eeab35f6edb887324ca7ff9ddf5008ef724c34`。在第四圖的 `(384.5, 393.5)` 放置 key 65011、半徑 1 的標記。中心的兩層靜態碰撞格均可走，與出口 `(391.5, 391.5)` 的互動圈分離。與 GB-01 的屏障使用同一旗標，可併測 GB-02。
