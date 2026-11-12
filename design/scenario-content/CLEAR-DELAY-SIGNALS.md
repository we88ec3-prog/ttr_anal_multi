# 清場後延遲訊號

Server 自訂關卡 `LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF` 可使用 `ClearDelayElapsed` 產生一次性的實例旗標。它適用於勝利後等待才開門，或延遲開放下一個手動操作。

```json
{
  "signals": [
    { "flag": "exit-ready", "event": "ClearDelayElapsed", "delaySeconds": 2 }
  ],
  "portal": {
    "x": 426,
    "y": 385,
    "radius": 6,
    "key": 81,
    "preRegisterClosed": true,
    "condition": { "requiredFlags": ["exit-ready"] }
  }
}
```

這段應併入既有節點。座標與 key 是示例，正式節點使用該圖已驗證的出口。手動互動點也可在 `interaction.requiredFlags` 引用同一旗標。每個訊號的 `delaySeconds` 須大於 0 且不超過 3600，可使用小數。此事件不帶 `region` 或 `interaction`；其他事件的 `delaySeconds` 須省略或為 null。 [JSON Schema](local-scenario-definition.schema.json)

## 執行順序

1. 整個怪群達成既有清場條件後，Server 記錄清場。清場事件本身不授予延遲旗標。
2. 同一節點首次在清場後觀察到有效的 Server 玩家位置時開始計時。主線在 Portal 階段提交後初始化，因此等待存檔和清場劇情的時間不算在延遲內。既有測試場則在清場當輪觀察位置。
3. 到期後的首次正常更新鎖存旗標，重算出口及互動點。其他條件仍須同時成立。出口使用既有的點狀態更新，玩家仍須靠近並按 Z 才會換場或進結算。
4. 旗標只在當次實例有效，可隨同一關卡的後續節點保留。每個節點有自己的計時起點。複製主線狀態時保留該節點的計時起點，未提交的副本不會改寫原實例。登出後未完成副本仍重新開始。

一般主線與共用關卡測試執行器支援此訊號。固定兩段的馮德斯前導仍維持其既有資料範圍。此功能由 Server 時鐘及事件驅動，原生 `.mef`、Client 本地生成與 AI 自主決策的驗證狀態維持待證。
