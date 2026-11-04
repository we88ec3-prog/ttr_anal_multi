# S00：Quest15進村事件與Town1碰撞資格核對

接續[目前進村目標](S00-20261102-PHINDOS-ENTRY-MILESTONE.md)，本輪取得會直接影響
開發順序的資源證據，並實作私有Server碰撞檢查工具的馮德斯模式；尚未換版或要求人測。

## 事件資源的精確範圍

[唯讀檢查器](../inspect_phindos_entry_sequences.py)／
[各member SHA、場景對應與呼叫序列](evidence/S00-20261102-PHINDOS-ENTRY-SEQUENCES.json)。
本地Event載體SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
它可能包含歷史翻譯；本輪釘定實際bytes，不宣稱是未修改的原始KR Event包。
先前原始Table的SceneList是CHAPTERTABLE，本次Event/SceneList是SCENESET，兩者不可混用。

| Quest15 scene | Event function | 這四個body內實際可見的行為 |
| --- | --- | --- |
| 1 | Square_Tutorial01 | LoadMap Square03D.fld；CreateObject10338；OpenTalkScene(3,22) |
| 2 | scenario_tuto1_1 | 同廣場演出map；建立10338與隊伍演出模型；talk15/16/17/25及鏡頭／角色動作 |
| 3 | pindos_talkevent | LoadMap town001D.map；隊伍演出與NPC10047；talk18/24/20/21、DoProlog(1) |
| 4 | scenario_tuto2_1 | transition0、HideOriginalObjs0、空LoadMap；沒有實際對話／actor建立呼叫 |

四個body結尾都DeleteAllObject、RestoreMap，再RevPhase1。這是腳本的實際呼叫，
helper內部效果、外部排程與網路訊息仍須追清；不得只因第三段LoadMap就宣告村落就緒。
這四個body沒有明示生怪或啟動戰鬥的呼叫，**不證明外部helper／任務流程沒有必經戰鬥**。
因此不能把scenario_tuto檔名當成Field19戰鬥規格，也不能據此直接跳過Field19。

## 私有Server碰撞資格核對

新增town001 BND pin及LocalTutorialInspect的`--phindos182`模式。
從既有BoundMap載體SHA `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`
唯讀抽取本機新副本，member SHA為
`30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6`。
現有v0靜態層讀取器正常完成解壓、尺寸／層檢查，無需改版本或all-clear fallback。
未修改BND原件、地圖或Client。Field19的v2 BND仍未獲本讀取器支援。

| Scene15/3演出座標 | 現有Server靜態判定CanStand |
| --- | --- |
| 751,416 | false |
| 760,416 | false |
| 755,429 | false |
| 755,421 | false |
| 734,744（NPC演出座標） | true |

這證實**不能把演出隊員座標原樣當本候選一般村落出生點**；
並非對Client所有碰撞／高度或官服spawn的FULL-PASS結論。
最後一點可走也不授權拿NPC演出點替代玩家正常spawn。
工具Release build零警告／錯誤，實際讀取上述BND與五點核對成功。
此驗證不等同遊戲進村或主線互動成功，沒有必要重跑無關完整測試。

## 對Server接續的實際要求

- 優先閉合廣場NPC事件與Quest15場景啟動／結束的consumer，分清事件兩個欄位與Quest ID；
  原有6B C2S1C producer不自動證明其欄位值或唯一回覆。
- 原SPEC已限定S2CB6為有條件的冒險團UI路線，不能拿來猜作四段scene的啟動封包。
- 對已授權／已提交的前置與Quest狀態發送相應UI／scene；不能捏造Quest16完成key來開放Quest15。
- 在切入一般Town1前取得合法正常玩家位置與scene/controller，執行context/map/bounds/actor/NPC/control。
  村落劇情RestoreMap及其角色建立不是普通世界初始化。

不變更正式規格批准／原生驗收。本輪不是官服後端復原或MEF還原，現有三怪AI仍由Server候選程式控制。
