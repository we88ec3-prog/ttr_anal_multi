# RAID 1～3：普通守衛與具名護衛擊倒事件

後續：[Story Q119正常路線](STORY-MONSTER-DEFEAT-NORMAL-ROUTES.md)已另批補齊；下方Story待驗保留本批快照。

2026-11-23。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
承接[指定怪物擊倒契約](../scenario-content/MONSTER-DEFEAT-SIGNALS.md)，補該事件在 RAID
先前只有回呼接線的工程驗證缺口。不回填舊收據，不變更原生格式或 Client 驗收。

三份候選由固定原版範本衍生，前四圖、五圖順序、所有出生點、必要頭目、成長與獎勵政策保持。
只在末圖把第一名非頭目守衛的 `maximumHealth` 設成1，並加入：

1. 初始組該模型／PRE的 `MonsterDefeated` → `raid-guard-defeated`。
2. `FlagDelayElapsed` 等0.5秒 → `raid-guards-ready`。
3. 一名原同圖守衛模型、PRE與座標的具名增援 `raid-defeat-guards`；護衛沿用原成長HP，
   沒有繼承測試守衛的1HP覆寫。
4. 該具名波次的 `MonsterDefeated` → `raid-helper-defeated`；出口另要求兩個擊倒旗標。

1HP是明示作者測試值，不是原服平衡。普通守衛不成為必要頭目；原頭目仍必須擊倒，所有
增援／死亡移除／清場條件保持。觀察任一初始相符成員和具名波成員的事件，各自只記首次事實。

| RAID | Stage／Case | 原必要頭目 | 普通守衛模型／PRE | 保存獎勵 |
|---|---|---|---|---|
| 1 | 50／88 | 1159／1 | 1158／1 | 2274一本 |
| 2 | 51／89 | 1088／5 | 1027／1 | 2275一本 |
| 3 | 52／90 | 1184／1 | 1020／1 | 2276一本 |

來源候選：

- [RAID1](../scenario-content/phindos-raid1-stage50-case88-monster-defeat.scenario.json)
- [RAID2](../scenario-content/alsmeer-raid2-stage51-case89-monster-defeat.scenario.json)
- [RAID3](../scenario-content/rotrua-raid3-stage52-case90-monster-defeat.scenario.json)

## 正常入口、擊倒觀察與結算

三份候選經隔離管理端既有 `raid-1`／`raid-2`／`raid-3` HTTP 表單保存、完整驗證，下載
同版scenario／AI／manifest；每份兩次下載bytes相同，配套解析內容與候選相同。
本批沒有操作瀏覽器GUI，也沒有發布到現用服務。精確來源及配套SHA見[機器收據](../scenario-content/raid-monster-defeat-validation.json)。

三條原版控制與三條保存版實際loopback TCP，使用準備角色4／Lv17、原裝備與回復卷軸，
正常登入、廣場建隊、RAID選擇與開始、五張原BND移動／戰鬥、結果確認及返回廣場。
末圖檢查器透過正常移動與攻擊先打指定守衛，沒有直接設HP、注入旗標或強制清敵。
逐次擊倒後讀取不可變診斷快照，證明初始守衛實際死亡時頭目仍有正HP、具名護衛另有不同
Entity及正確waveId；其他同模型初始怪物不冒充該具名波次。原版沒有新事件事實。

三個保存版另由獨立部署Host、真實時計完整走五圖；只讀診斷觀察相同兩事件，初始守衛
擊倒時頭目仍活、全組尚未清除。此與程序內測試時計TCP分開，不當Client ACK。
每場只發對應經驗書一本、CP保持3000；錢包、裝備、角色EXP、故事狀態與其他背包保持，
僅正常使用的回復卷軸扣件。書在廣場重新啟用前發布。RAID沿用成功返回廣場並清理隊伍，
不是普通狩獵場的原村同隊返回。

首場RAID3已清完末房，檢查器走出口時因額外三格避牆間距找不到路徑，未完成返回，保留
`raid3-before-clearance-fallback`失敗證據，不列通過。檢查器現在依序嘗試3／2／1／0格額外間距，
仍使用相同原BND阻擋格；縮小間距所得路徑逐段核對可見性，不跳過Server碰撞或傳送角色。
另以合成一格寬轉彎通道做獨立阻擋格抽樣檢查，該fixture不是原BND或Client碰撞驗收。
原兩場Host與六條TCP保留，只補驗RAID3。收據分列前兩場舊planner與第三場新版SHA，
不主張三場使用相同Python檢查器，也不主張新一場必然需要fallback。

## 建置、保存與界線

最終收據SHA256：`088a7fedbe087a68e9d93133b88dba2e4d9963a50061ec423d3a5659c71b5972`。

三個Release建置零警告／錯誤，**786/786 HappyPath**通過，零失敗／略過；
本批為資料編排及正常路線工具接線，沿用擊倒核心四個正流程，不增加重複單元測試。
原版候選保持原檔；新檔及配套可獨立載入。Source DB未改，隔離Admin與三個Host都停止，
現用服務與Client原件不變。輸出在workspace的 `outputs/raid-monster-defeat-workbench-20261123`、
`raid-monster-defeat-tcp-20261123` 與 `raid-monster-defeat-hosts-20261123`。

`GAME_RUNTIME_OBSERVATION`：只包含上述準備角色的正常工程流程。Story新事件正常路線仍待驗，
指定v2、人測、自然新帳號、Client自主AI及原生MEF格式不提高狀態。錯誤／邊界、重送、
重登／重連、併發、故障、安全與壓測仍待排程；整體MEF目標未完成。
