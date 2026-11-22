# Q119：每輪指定怪物擊倒與一次主線結算

2026-11-23。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
接續[指定怪物擊倒契約](../scenario-content/MONSTER-DEFEAT-SIGNALS.md)與
[RAID工程路線](RAID-MONSTER-DEFEAT-NORMAL-ROUTES.md)，補Story adapter的新事件正常通關。

[候選關卡](../scenario-content/story-q119-monster-defeat.scenario.json) SHA256
`41725485cec481d1dfb6f8d013a92262013d6487c4aa5af662c603a4a75fd19a`。
從原structured-loop版本衍生，保持四圖、原BND／出生點／模型、敘事場景與NPC／編隊入口、
兩房循環、三輪上限、停止機關、原獎勵政策及玩家資源延續。只在首圖加入：

1. 第一名初始1001設明示測試HP1，其餘初始怪保持原血量；同模型／PRE1初始組的第一筆實際
   擊倒產生 `story-guard-defeated`，不要求必要頭目或全組清除。
2. 該旗標後0.4秒產生 `story-guards-ready`，讓具名波 `story-defeat-guards`生成一名同圖已有
   模型、座標與4EXP的護衛。複製發生在HP1覆寫之前，護衛沒有繼承1HP。
3. 指定具名波的1001／PRE1擊倒產生 `story-helper-defeated`，與初始組同模型成員分開匹配。
   首圖出口另要求兩項擊倒旗標，所有必要波與原清場仍須完成。
4. 三個新旗標加進 `story-lap`，與原lap-cleared每輪重置；原停止旗標仍保留。

1HP屬作者測試值，不是原版平衡。事件選擇任一相符初始成員的首次擊倒；本批實際為Entity257。
每輪可重用戰鬥Entity號，訪次以獨立CurrentVisit.Id及序號區分，不能只憑Entity判斷跨輪事件。

## 保存與正常路線

隔離Admin使用原 `story-q119-loops` 表單預覽／保存、完整來源與AI／BND檢查；最低／最高
5936／5984EXP、最多8訪。四檔配套scenario／AI／experiencePolicy／manifest與實際ZIP均保存，
兩次下載bytes一致，政策檔保持原版精確位元組。這批只有HTTP，沒有新瀏覽器GUI或自動發布主張。

| 路線 | 訪問 | 擊倒數／EXP | 一次Q119獎勵 | 保存EXP增量 |
|---|---:|---:|---:|---:|
| 原版停止控制 | 4 | 13／52 | 5880 | 5932 |
| 原版三輪控制 | 8 | 23／92 | 5880 | 5972 |
| 新版停止機關 | 4 | 14／56 | 5880 | 5936 |
| 新版三輪上限 | 8 | 26／104 | 5880 | 5984 |

5880為固定任務5850、末圖清場10、完成20；擊倒EXP逐訪即時保存，不在結果重算。
四條實際loopback TCP走正常NPC／組成隊伍、敘事ACK、原BND移動與攻擊、停止機關或上限、
結果確認及原村同隊返回。新版分別一輪／三輪各有初始與具名擊倒事實；開始時當輪四旗標皆未成立、
事實列表清空，三輪訪次序號1／3／5、nodeVisit1／2／3且GUID互異。
初始守衛死亡時另一名初始成員仍有正HP，全組未清除；具名護衛的waveId及Entity另行核對。
原版兩條控制保持原經驗且沒有新擊倒觀察。

保存版另經兩個獨立真實時計Host跑停止／上限，正常登入、NPC／編隊及完整4／8訪通關。
外部只讀診斷逐輪觀察相同重置與兩事件；停止版觀察守衛擊倒時同伴仍40HP。
SQLite再次獨立核對一次Q119的5880EXP／40熟練度、角色累計增量5936／5984、Q120游標，
兩路Town1／Map182原村同隊返回。診斷與敘事ACK都不當Client實際播放或自主AI證據。

## 驗證與界線

[最終收據](../scenario-content/story-monster-defeat-validation.json)綁定來源、ZIP與各元件、
四TCP／兩Host／逐訪事實、DLL、SQLite與TRX。SHA256
`3d126cd6e89a54cf3189a6727b21d019416df32e776f157e188974ae1b988a08`。
三Release建置零警告／錯誤，**786/786 HappyPath**通過，零失敗／略過；Python語法亦通過。
本批資料編排與檢查器覆蓋已有事件核心，不新增鏡像單元測試。
政策雜湊核對使用實際startup.storyBundle.settings，初次讀取器誤猜平面欄位已更正，未重跑遊戲。

原件、舊候選、種子DB及現用服務／Client不變；隔離Admin與兩個Host均停止。
輸出：workspace `outputs/story-monster-defeat-workbench-20261123`、
`story-monster-defeat-tcp-20261123`、`story-monster-defeat-hosts-20261123`。

`GAME_RUNTIME_OBSERVATION`：此為準備角色／教學及Q15前置的工程路線，不是自然新帳號全程。
普通副本、RAID與Story的新事件證據各自成立，不外推所有關卡、Client動畫／自主AI或原生MEF。
指定v2人測、錯誤／邊界、重送、重登／重連、併發、故障、安全及壓測仍待排程，整體目標持續。
