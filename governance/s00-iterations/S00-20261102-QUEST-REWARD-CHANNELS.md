# S00：Quest獎勵欄位與Client顯示對應

分類：原始KR主程式的有限儲存／UI連結分析；非官方Server規則、非整份函式FULL-PASS。
本次未執行／附加Client，未修改原始主程式或資源。

## 可重現來源

- 原始BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始Table載體SHA256：`09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
- 解碼QuestInfo SHA256：`5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。
- [唯讀檢核工具](../inspect_quest_reward_channels.py)與[15個指令視窗／資源列結果](evidence/S00-20261102-QUEST-REWARD-CHANNELS.json)。工具要求上述SHA，依PE區段映射與Capstone解碼，不採單一位址偏移套所有區段。

## 已核對的連結

`504740`載入RewardsEtc。`5048C0`以`esp+64`初始化本地Quest紀錄，
`504D96`將type減1並由`505554`六個DWORD分支。各分支寫入位置減去紀錄起點如下：

| RewardsEtc type | 分支 | 紀錄offset |
| --- | --- | --- |
| 1 | 504DE2 | 80 |
| 2 | 504DF4 | 88 |
| 3 | 504DEB | 84 |
| 4 | 504DFD | 7C |
| 5 | 504E06 | 8C |
| 6 | 504E0F | 90 |

UI `634740`在`63478A/634790`保存ECX紀錄指標；呼叫點`6342E7→6342F6`、
`634300→63430F`傳入Quest紀錄，與UI自身物件參數分開。
`634E6A/634E71`檢查／取紀錄+88，`634EC1`取該數值；
`634F2B`選文字key15F。`D6891C`的12-byte文字列將15F連至`kQuestRewardPartyExp`。
因此**type2對應Client的PartyExp顯示欄位**，不能把Quest16的50直接當貨幣。

type4寫紀錄+7C；`6350F0`讀此欄，`63515B`選key163，
其文字為`kQuestRewardLeeloo`。本次只閉合這兩個UI顯示連結；
其他type的儲存offset不等於其所有使用流程均已驗證。
兩段顯示路線均乘`F94364`；尚未證明該顯示倍率就是Server實發倍率。

| Quest | 前置Quest | RewardsEtc原始列 |
| --- | --- | --- |
| 14 | 無 | 無 |
| 16 | 14 | type2 value50 |
| 15 | 16 | type2 value2800；type4 value468 |

## Server開發需求與限制

將PartyExp與Leeloo分開建模；先閉合合法完成條件、Server權威成功紀錄、
角色／隊伍經驗歸屬及等級換算、現有餘額來源與Client更新協定，再實作交易式結算。
以完成事件的唯一鍵避免重複獎勵，提交成功後才發布對應Quest完成及餘額狀態。
目前沒有據此新增發獎、改DB或傳送6F／74完成位元。

Quest16 value50是資源原值，不能單憑PartyExp標籤推定官方內部單位、
等級曲線、發獎時機、轉換算法或封包。抵達廣場也不自動證明Quest14／16合法完成。
此項為可開發規劃及仍需補證的協定缺口，正式規格批准狀態不變。
