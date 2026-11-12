# 關卡旗標控制增援

Server 自訂關卡的 `reinforcements` 與 `timedReinforcements` 可指定 `requiredFlags`。所有旗標、既有計時及可選的 `activationRegion` 都須成立才生成該波。未設定旗標的舊資料沿用原有行為。

```json
{
  "id": "checkpoint-reinforcement",
  "delaySeconds": 1,
  "requiredFlags": ["point-used"],
  "encounters": [{ "model": 1001, "x": 377.5, "y": 291.5 }]
}
```

- 順序增援從當前怪物清空時起算延遲。定時增援從遭遇開始時起算。若延遲已到，取得旗標後在後續更新生成，不會再起算一次。
- 旗標最多 16 個且不得重複。可引用進入本節點前每條路徑都必然取得的旗標，或本節點可在整場清場前產生的旗標，例如區域進入或無須清場的手動互動。
- 待生成的波次會阻止整場清場。因此本節點的整場清場旗標、清場延遲旗標，以及依賴這兩種旗標的互動，不可用來解鎖該節點增援。內容載入時檢查此依賴。
- 波次成立後只生成一次，沿用 Server 的怪物實體配號、資源與冷卻處理。劇情、出口及存檔仍依原有流程提交。

獨立測試場使用圖 193。先清第一隻怪，回進場提示圈按 Z 取得旗標，第二隻怪才出現。清第二隻後，玩家仍須到出口按 Z 才進結算。地圖座標沿用已檢查的互動測試場。這是 `NOT_NATIVE_MEF` 的 Server 內容定義。 [JSON Schema](local-scenario-definition.schema.json)
