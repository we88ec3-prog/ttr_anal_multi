# 毒霧森林 Q446／Q447

韓版 QuestInfo 的順序為 Q445 → Q446 → Q447。Q446 由村莊 9 的 NPC 10085 開始，Q447 改找同村 NPC 10087，兩者均要求 Lv.34。

Q446 對應 Field 73／Case 137，單圖 1114，場景 town006D 使用 town006.bnd。Scene 1 在編隊前播放，Scene 2 在入圖時播放，Scene 3 在清場後播放。Server 候選配置採群組 16 的一隻 1137，以及群組 3 的三隻 1135。原始資料尚未證實其中有必要頭目，當前四隻皆使用普通怪尺度。Lv.34、無裝備的參考攻擊量為 60，每隻 180 HP，全圖 720 HP；位置及群組組合待實機核對。 [關卡配置與碰撞雜湊](poison-tagarog.append.json)

| KR 來源 | 解碼 SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_TagarogAttack_01.XML | `fa8f7f7c29a191e612234aa198f4983a57686c48097b5d31d365a9277214bd3f` |
| Field/Cluster/CLUST_S_TagarogAttack_01.xml | `62ab321da8c17de21122f620ce7117b093376335ada60d594a3495ae880ba3f6` |
| Q446 Scene 2 | `3bbb2c5d71bd0c31065365cf5581fa7b1fe73b2390069ca93fb0cacf9b8d0304` |
| Q446 Scene 3 | `51b026865606ce968ed58681da00da43d865e39b3cce1ad0d9e6c6d6507714bb` |
| Q447 Scene 1，Poison_Fifth_Talkevent | `b8a33d62e74b668a3a3bbb596d85102fbe4992588682e465cb55b9f91bd8ba8c` |

Q446 結算發放 163,039 EXP、3,024 LeeLoo，原表 type 3 的 200 暫未入帳。結算回圖 1086。Q447 為單段對話，結束後仍在圖 1086。原版 BND 離線流程已走通 1114、核對回村與存檔，樣本維持 Lv.34，累計 2,689,677 EXP。指定 v2 Client 的出怪、演出、走格及戰鬥節奏待批次驗收。 [錢包政策](poison-q446.story-wallet.json)
