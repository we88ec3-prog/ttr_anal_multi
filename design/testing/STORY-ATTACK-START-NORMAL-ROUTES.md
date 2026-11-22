# Q119：主線起手事件、每輪護衛與正常結算

後續有[另存AI變體的初始清除範例](STORY-AUTHORED-EARLY-CLEAR-ROUTES.md)；它是獨立r2，
不改寫本頁r1起手路線及初始清除未驗的歷史界線。

2026-11-22，SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
承接[起手訊號契約](../scenario-content/MONSTER-ATTACK-START-SIGNALS.md)及主線循環既有
正常入口，補齊Story adapter的新增事件證據。原版主程式、資源及使用者存檔保持唯讀。

[新候選](../scenario-content/story-q119-attack-start.scenario.json)沿用四張圖、原版BND、
敘事場景序列、NPC／組成隊伍入口、三輪上限、停止機關與玩家資源延續。只在首圖增加：

1. 初始組 Model1001／PRE1 實際 `legacy-melee` 起手，產生 `story-attack-started`。
2. 起手或初始組 WaveCleared 任一成立，產生 `story-guards-trigger`；後者是明示替代來源，
   不偽造起手，不把護衛略過。
3. FlagDelayElapsed 等0.4秒產生 `story-guards-ready`，允許一名同圖已有模型的護衛生成。
   護衛使用原出生座標與4點擊殺EXP，沒有新增模型、AI、opcode或Client資源。
4. 上述四旗標加入既有 `story-lap` reset scope。重返首圖須重新接受一次實際起手／替代來源，
   不沿用上一輪已滿足的延遲。原 `lap-cleared` 仍須必要敵群及增援全部清完才成立。

管理端在隔離DB工作副本以既有 `story-q119-loops` profile預覽、保存及下載四檔配套：
scenario／AI／experiencePolicy／manifest。最低／最高預覽為5936／5984 EXP、最多8訪，
policy位元組保持原版；兩次下載一致。此批使用HTTP，沒有瀏覽器GUI或自動發布。

| 路線 | 訪問 | 擊倒數 | 擊倒EXP | 一次任務結算EXP | 合計保存EXP |
|---|---:|---:|---:|---:|---:|
| 舊版機關停止對照 | 4 | 13 | 52 | 5880 | 5932 |
| 舊版三輪上限對照 | 8 | 23 | 92 | 5880 | 5972 |
| 新版機關停止 | 4 | 14 | 56 | 5880 | 5936 |
| 新版三輪上限 | 8 | 26 | 104 | 5880 | 5984 |

5880由固定任務5850、末圖清場10及完成20組成。擊倒經驗逐訪即時保存，不在最終結算重複
計入。新增護衛每輪4 EXP，停止與三輪分別多4／12。兩種新版路線都完成原敘事、結果確認、
一次Q119入帳、Q120游標及Town1／Map182同隊返回。

[完整收據](../scenario-content/story-attack-start-validation.json)綁定來源、實際保存配套、
四條正常TCP及三個獨立Host。TCP使用同程序測試時計，分開原版／新版停止與上限。
獨立Host使用真實時間，跑舊版停止對照及新版停止／上限。每次正常移動後、玩家攻擊前，
唯讀Server診斷觀察實際起手、初始組仍未清除與到期護衛；上限路線在首圖第1／2／3次訪問
均有獨立visit ID、重新產生的起手事件與延遲，沒有注入旗標、強制清敵或調整Host時計。

Story診斷新增既有FlagDelayTimers的唯讀投影。測試工具原先只計初始組，現在包括順序／定時
必要波的擊倒數與經驗，空場時仍等未出場必要波；這不是放寬通關條件。原版兩條TCP與獨立
停止對照仍保持5932／5972的既有結果。

Host／Inspect／Admin Release零警告／錯誤；HappyPath776項，零失敗／跳過。隔離Admin／Host
已停止，來源DB不變，未替換目前服務。這是準備教學／Q15前置後的正常NPC／編成／戰鬥流程，
不是自然全新帳號旅程。

界線：READ_ONLY_SERVER_DIAGNOSTIC_NOT_CLIENT_ACK；不宣稱Client動畫或自主AI。
本批完整路線走存活敵人起手；初始組清除替代來源未另跑完整場次。指定v2、人測、自然新帳號
與既有暫緩的錯誤／重登／故障／安全／併發／壓測保留。Story／RAID／普通Case693新增事件
各有自己的工程收據，不能因此宣稱全部MEF或所有內容已完成。
