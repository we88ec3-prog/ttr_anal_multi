# 現有 Server 內容與 P0 的精確接點

本節只讀 `main@03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已發布的四份 JSON：主線候選、Q119 外部關卡、現有 schema、正式需求索引。完整 Git blob／SHA／byte length 見 [來源](source-manifest.json)，重算結果見 [server-context.json](server-context.json) 與 [驗證結果](verification-result.json)。沒有讀取或執行外部 Server 程式，也沒有修改目前主線內容。

## 1. Q119/3 的現行位置

| Server 節點順序 | 原 Chart sourceNode | Map ID | 候選選定 cluster | 入場 scene | 清場 scene |
|---|---|---|---|---|---|
| 1 | 4 | 632 | 1 | 119/2 | 無 |
| 2 | 3 | 633 | 2 | 無 | 無 |
| 3 | 2 | 634 | 3 | 無 | 無 |
| 4 | 1 | 635 | 4 | **119/3** | **119/4** |

主線的返回 scene 是 **119/5**。此表忠實反映當前 `alsmeer-full-mainline-content-candidate.json`，不宣稱官方 trigger 次序；來源明示 scene placement、finite cluster 與位置屬 Server 候選政策。原 Chart 的 `sourceNode=1` 不能直接當作 Server 第一節點。

Q119/3 的原 Q 演出使用模型 1086；目前 Server 候選末圖的 encounter models 是 `[1001,1001,1001,1022]`。這是兩個不同角色集合。Q slot、模型 ID、world EntityId、Server encounter index、原 Cluster 編號均不能互換。本輪的原資源依賴盤點不能自行把候選 boss 1022 改成 1086，也不能把某一個原 Cluster 變體宣告為 Server 已採用。

## 2. 外部關卡檔不直接包含 Lua 呼叫或 scene 動作

`story-q119-clear-scene.scenario.json` 以主線 SHA `14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c` 作配對來源；它的四個 node 保留地圖順序和有限怪物模型順序，末圖 portal 的 `preRegisterClosed=true`。名稱含 `clear-scene` 不表示檔內有任意 `PlayScene` 動作。scene 鍵與階段仍由配對的主線內容提供。

已發布的 `local-scenario-definition.schema.json` 在 root、definition、node、rule 四層都是 `additionalProperties=false`。現有 rule event 僅 `Entry`、`GroupCleared`、`InteractZ`；action 僅 `SpawnGroup`、`UnlockPortal`、`NextNode`、`Result`。因此不能把本包 P0 呼叫計畫、資源證據或 owner 契約直接塞進該 schema，亦不能自稱新增的 `PlayScene` 已被現有 Server 支援。

本包是分析與開發輸入。實作者應在原 Server／內容工具維護線中，沿既有版本機制接入這些檢查；若確須擴 schema，需明確版本化並更新相應讀取器。本輪不另造官方格式、傳輸 opcode 或正式需求台帳。

## 3. S00 收件與已完成能力

REQ-0019、REQ-0021 在固定讀集仍為 `CANDIDATE`，關聯 `SPEC-FLOW-0001`、`SPEC-SCENE-0001`、`SPEC-CHAR-0001` 及既有 GAP。本輪只增加可採用分析，不改這些狀態。

現有主線已保存外部關卡、旗標、波次、點位、出口、資源延續與結算等工程成果；P0 的實作工作是把 ABI／真實資源／owner 及退出檢查接入這條線。不能把本次新增需求寫成整個 Server 從零開始，也不能將先前合成或人測結果擴張為本次新內容已驗收。

## 4. 重跑

```bash
python -B verify_context.py --repo /path/to/ttr_anal_multi
```

程式先驗精確來源身分，再重建四節點對照、來源配對、scene 階段、schema 界線及兩個需求的現有狀態，並逐 bytes 比對已保存衍生 JSON。`PASS` 僅表示這個文件／資料對照可重現；所有 Client、Lua、Server 執行旗標及部署旗標均為 false。
