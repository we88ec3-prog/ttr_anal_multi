# 入場後計時旗標

`NodeDelayElapsed` 可在怪物仍存活時觸發增援或啟用互動點。把事件放在地圖節點的 `signals`，填入唯一的 `flag` 與大於 0、至多 3600 秒的 `delaySeconds`。增援與互動可用 `requiredFlags` 讀取旗標。出口也可要求旗標，仍須通過該出口的清場與其他條件。

```json
{ "flag": "ambush-ready", "event": "NodeDelayElapsed", "delaySeconds": 5 }
```

一般主線在 Server 提交入場劇情完成、開始允許戰鬥時開始計時。沒有入場劇情的節點在進場時開始。共用測試場在建立節點時開始。旗標在 Server 首次達到門檻的戰鬥更新設立，當次更新即可生成已符合條件的增援。每張圖重新起算，已設立的旗標則在同一副本保留。播放清場劇情時不下發事件，劇情結束後更新時計入經過的時間。`ClearDelayElapsed` 仍從清場完成並進入出口階段起算。

[Q119 範例](story-q119-node-delay.scenario.json)沿用資源延續版，第一圖 632 在入場劇情結束五秒後增援一隻怪，即使初始兩隻都還活著。增援自己的延遲設定為 0 秒，出場時間由旗標控制。範例 SHA-256 為 `65686fbecddb51d0701574691f99516189f57f8931052c93b6bf1a9af2717ce6`。這個時間與增援位置為 Server 候選編排，沿用 `NOT_NATIVE_MEF` 定義。 [外部關卡載入方式](STORY-SCENARIO-OVERRIDES.md)
