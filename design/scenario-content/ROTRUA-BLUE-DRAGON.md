# 羅特魯亞主線 Q148、Q149

QuestInfo 的前置是 Q147 → Q148 → Q149，兩個任務均要求 Lv.21，由 NPC 10055 啟動。Q148 播 Scene 1，Q149 播 Scene 1 後進單人編隊。Field 41 對應 Case 118，Chart 的唯一 NodeLink 依序指定地圖 819～824，各圖選擇率 100%。 [QuestInfo](../../kr-temp-roy/T06/evidence/original-QuestInfo.xml)

| 地圖 | BND | 入場／清場場景 | 候選群組 | 怪物 HP |
|---:|---|---|---|---|
| 819 | icecrystal12.bnd | 無 | 2 | 132 × 2 |
| 820 | icecrystal08.bnd | 2／無 | 43 | 132 × 2 |
| 821 | icecrystal10.bnd | 3／無 | 34 | 132 × 2 |
| 822 | icecrystal13.bnd | 4／無 | 34 | 132 × 2 |
| 823 | icecrystal14.bnd | 5／6 | 45、46 | 頭目 1125／PRE 1 為 572，1124 為 132 |
| 824 | icecrystal11.bnd | 無／7 | 8 | 132 × 2 |

頭目演出 Scene 5 建立 1124、1125，兩者在來源 Cluster 都有記錄。候選指定 1125 為必要頭目。Scene 6 暫時載入 icecrystal13X，放在 823 的清場時點，完成後回到原戰鬥圖出口。打完第六圖和 Scene 7 才可結算，結果返回後在地圖 199 播 Scene 8。逐圖群組、演出觸發、頭目指定及出入口為 Server 試行設定。 [六圖配置](rotrua-blue-dragon.append.json)

| 原件與測試目錄一致的解碼成員 | SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_Bluedragon_01.xml | `0547435b51809f5d3f18ebbb51e091012001e0319fecbd7efcaf40e8bd12c9a9` |
| Field/Cluster/CLUST_S_Bluedragon_01.xml | `5aee5154fc8cb888891734fa203cd25226d52f7e13076652cecbce63604bb734` |
| Event/Sequences/Rotrua_Bluedragon_Boss.seq | `dd8bda901fa45437379858256291e21fd7af659ba2f64f8c319a76382d97458b` |
| Event/Sequences/Rotrua_Bluedragon_Boss_Clear.seq | `2cb4d5aa8674434a6e246c4f3f69d3f45bbcee197677bd658775969f3ec81e44` |

Q149 採原表 type 2 的 58,744 EXP 與 type 4 的 2,628 LeeLoo。type 3 的 180 用途待證。經驗政策 v9 延續舊門檻和獎勵。 [錢包政策](rotrua-q149.story-wallet.json)

將附表追加至 Q147 版本，`version` 設 `rotrua-q149-candidate-v1`，`sourceBaselineSha256` 設附表 SHA-256 `69bb8ea44dfaff975b6be2dcdd28ed53aa63db582ea116d222c9fdc6b48c3dca`，並把舊版雜湊與任務序列加到 `previousVersions`。合併主線 SHA 為 `289c554ba28c112872c805b2dcb40435e5870715ebe3856535cf53370a51e430`，Q119 覆寫改綁該 SHA。基線關卡圖 SHA 為 `03d895c890762b39fe2ee9df130cafd188191d432454f894859b373185ae2df6`，啟用成長與覆寫後為 `73cdaceca44cd7ff028c5f86b0209a401f4cefe84628695ded7b19a49f4a0f71`。

原版碰撞離線走完六張地圖，核對傷害總和、末兩圖劇情、結算與回村存檔。測試角色維持 Lv.21、累計 541,151 EXP、滿血 1,000。v2 實際演出與操作待驗。
