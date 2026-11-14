# 馮德斯一般副本 Stage 1／Case 1

[關卡定義](phindos-stage1-case1.scenario.json)與維護者目前採用的設定逐位元組相同，SHA-256 為 `baa48fb43ec35420167be093e331c74fb2cbc0590da720f0626898ff2c6f64d2`。此範例使用公開的 [Server 關卡 JSON schema](local-scenario-definition.schema.json)，標示 `NOT_NATIVE_MEF`。圖表與群組來源的檔名和雜湊保存在定義內。出生點、怪物配置、出口半徑、必掉卷軸和 100 通關經驗是 Server 的候選規則。 [Case 1 的來源與碰撞分析](../../governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md#case-1-的-server-關卡定義候選)

| 節點 | 地圖 | 怪物數 | 碰撞資源 | SHA-256 |
|---:|---:|---:|---|---|
| 10 | 1 | 2 | `mushroom01.bnd` | `2d6052c29a1045d44c14834a9f8313ae2731861d1014b890dd4d9f8091d6f5d4` |
| 7 | 4 | 4 | `mushroom04.bnd` | `bd3dbb89aaf14c59550fe3b42378b1d3c20f4d7f38d661eddbda8c894128ee00` |
| 6 | 8 | 4 | `mushroom07.bnd` | `01375baecf167f5d51dcf24e37f380256f7ef9ac0858db1ad4e5c632e20b139c` |
| 3 | 12 | 4 | `mushroom09.bnd` | `d60169e1cc26ff742b5db164f9262376755ca0925c34dadc40aa07412d5b5104` |
| 2 | 19 | 1 | `mushroom12.bnd` | `0adeeef7c1a183642a3e49a321e80c191b6dd3c8243f4e2f4ff7d16b5290c653` |

1. 正常入口在馮德斯的單人隊伍大廳。Server 確認帳號已抵達馮德斯、目前可自由行動、角色已擁有且是單人隊長，再接受既有 `0008` 開場候選。
2. 開場設置場景與 Case，進入第一張圖。每張圖獨立使用地圖 ID 與節點鍵，建立該圖怪物及關閉的出口。清場開出口後，玩家到出口按 Z 才換圖。
3. 地圖 19 的必要頭目為 `1086/PRE1`。擊倒後建立 Product 183、外觀 162，走近按 Space 後以交易入包。清場並確認最終出口後才記入通關經驗。 [掉落與拾取規格](GROUND-LOOT.md)
4. 結算確認後回村，保留隊伍時可再次開始。兩場各自提交經驗，主線不因一般副本推進。

離線可用持有的五份原版 BND 核對出生點至怪物、出口的可達性，再用 Server 戰鬥與移動處理走完五張圖。驗收應看到怪物數依序 2、4、4、4、1，只有終點掉落 Product 183，終點出口產生結算。正常登入、建隊、連刷、道具入包與 Client 顯示由 TS-37 驗收。 [批次驗收 TS-37](../testing/S00-CONTENT-BATCH-TESTS.md)
