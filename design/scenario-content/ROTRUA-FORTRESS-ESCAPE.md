# 羅特魯亞 Q246／Q247 至失落要塞 Q248

KR 任務資料的接續順序為 Q149 → Q246 → Q247 → Q248。Q246、Q247 的城鎮為 3、NPC 為 10012，Q247 建議等級 21。Q248 的城鎮為 4、NPC 為 10057，開頭兩段使用 `town004S`、`town004N`。第四村原名 `버려진요새`，台版顯示「失落要塞」。

| 資料 | 核對結果 |
| --- | --- |
| Field 43／Case 119 | Chart 節點順序 6 → 1 → 2 → 3 → 4 → 5；Server 邏輯圖為 886 → 887 → 888 → 889 → 890 → 891。 |
| Q247 戰鬥演出 | Scene 2 對應 crow09（888），Scene 3 至 6 依序使用 crow07（889），Scene 7 為 crow02 首領圖（891），Scene 8 為首領清場。 |
| Q247 返回演出 | Scene 9 載入 `town004N` 並呼叫 `DoProlog4`。Server 在此後將角色安裝到可移動城鎮圖 510，儲存城鎮 4，再提供 Q248。 |
| 任務報酬 | QuestInfo type 2 為 58,744 EXP，type 4 為 2,628 LeeLoo。type 3 的 200 尚未確認用途。 |
| 失落要塞 NPC | 《TownList》記錄 10013、10014、10015、10041、10042、10044、10045、10046、10057。 |

Chart SHA-256 為 `4c61b3811463ac32cfa14be800e30f4ec79f59d5a99d48e1eb87dd2eb306a6d3`，Cluster 為 `84e94324d09c1c9ba41990a522adbe1cc4462d8ec41f179e726ae5f520236776`，`town004.bnd` 為 `bf3b47dd518e5191cc0f0f74b9fbb58d9f609350ed04432fb55453a157594314`。

[接續資料](rotrua-fortress-escape.append.json) 記錄可行走格上的 Server 候選出生點、出口與 NPC 座標，以及重建怪物群。依現有 [成長規格](ROLE-AND-MONSTER-GROWTH.md) 設普通怪 132 HP、首領 572 HP，末圖讓首領和普通怪同場。開場 Lv.21 角色基礎最大 HP 為 1,000。成長政策 v11 自 590,000 EXP 起升 Lv.22，讓進入第四村的樣本角色在回村時達 1,025 最大 HP。錢包獎勵見 [入帳規格](fortress-growth.story-wallet.json)。關卡資料為 `NOT_NATIVE_MEF`。

Release 離線正流程已使用原版 BND 完成六圖，核對場景順序、HP、報酬、地圖 510、城鎮存檔與 Q248 的兩段演出。測試角色的累計經驗由 541,151 增至 599,895，並收到 2,628 LeeLoo。指定 v2 的顯示、出入口手感、戰鬥節奏及 Q248 之後的流程仍待驗收。
