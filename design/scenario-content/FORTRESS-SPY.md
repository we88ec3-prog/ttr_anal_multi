# 失落要塞 Q255～Q257

KR QuestInfo 的 Demand 依序為 Q254 → Q255 → Q256 → Q257 → Q258。Q255、Q256 由 NPC 10044 開始，建議 Lv.25。Q257 由 NPC 10057 開始，建議 Lv.26。Q256 的原表報酬為 76,284 EXP、3,060 LeeLoo。type 3 的 200 暫未入帳。

Q255 依序播放 Scene 1、2。接續的 Q256 在編隊前播放 Scene 1，原始序列的地圖參數為空。Field 47／Case 123 的 Chart 只有節點 1，對應邏輯圖 908、地形 `town004N`、碰撞 `town004.bnd`。進圖播放 Scene 2，其中原始劇情出現 1049、1050、1051，且三者均有 Cluster 記錄。Server 候選把群組 1、2、3 的三隻怪同場配置，每隻 147 HP，清掉全部才進入後續演出。

| 時點 | Scene | 序列載入的地形 |
|---|---|---|
| 進戰鬥圖 | 2 | town004N |
| 清場後 | 3、4、5、6 | town004N、town004N、crow11X、town004N |
| 結算確認 | 回圖 510 | 可移動的失落要塞 |
| 和 NPC 10057 對話 | Q257 Scene 1、2、3 | 依既有劇情序列播放 |

四段清場序列皆呼叫 `RestoreMap()`。Server 候選在一次清場後依 SceneList 順序播完四段，再開圖 908 的出口。原版把四段分配到哪些觸發事件仍待取證，crow11X 目前只由第三段清場演出載入。點位採已核對的 BND 連通區，怪物群組與時序屬 `NOT_NATIVE_MEF` 的 Server 配置。 [配置與碰撞雜湊](fortress-spy.append.json)

| KR 原始資源 | 解碼 SHA-256 |
|---|---|
| CHART_S_Spy_01.XML | `8338066d188697ef18e4a7f0712ed8b783f7342d2e541596be18b2e3d6b7d199` |
| CLUST_S_Spy_01.xml | `983dbcd1f8228e22a3bb6c1313eb9f777b3dfe32b91fee254e71a24b8fded791` |
| Fortress_Spy_Stage01_Clear.seq | `dbd2e5042ea94499dd33f16dc01173ab4bae50b3717e722f59f264bb59bc4e79` |
| Fortress_Spy_Stage01_Clear2.seq | `ddc10c6a51d8b7b8d3e0e3419e98e6d3e481f0b9a16b4d22f34a35ed6e944f91` |
| Fortress_Spy_Stage01_Clear3.seq | `8ae68151c9e7505242b67cdc7bf84fbc9493d615461e80e201919afb42237661` |
| Fortress_Spy_Stage01_Clear4.seq | `8905b372c6dc6719a50fd1ac095a2389a47e334d4dd709efb162ca93aab6a9d3` |

原版 BND 離線流程已核對劇情命令順序、出口、報酬與 Q257 完成存檔。樣本從 797,389 EXP 升至 873,673 EXP，結算後由 Lv.25 升到 Lv.27，最大 HP 1,150。指定 v2 的演出切換、操作恢復與出口可見性仍待驗收。
