# 怪物招式起手訊號

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。補齊怪物出招到MEF事件的接線，
不是Client自主AI、命中回報或新網路opcode。

新增MonsterAttackStarted訊號，使用monsterModel、monsterPre、attackId及waveId配對；
waveId省略代表初始組。只在戰鬥執行器真正確定起手、保存攻擊／冷卻並建立既有動作封包後
通知目前副本。選招候選、接近、尚未滿足條件、延遲命中或投射物移除不能冒充起手。
同訊號旗標每個有效作用域一次；正常Enter／loop重置及fork保持既有生命週期。

事件只設旗標，不在怪物列舉中直接插入怪物；增援繼續在既有怪物更新後的排程階段求值，
旗標後延遲仍從正常節點時計首次觀察起算。消費此旗標的招式條件不取消已起手招式。

結構載入先檢查該波實際存在對應模型／變體，配套AI驗證再核對真實招式ID。
聯合旗標／生怪／攻擊前置的固定點不得靠自己的起手旗標，或尚未可生成的自己波次啟動。
可達性是既有「玩家能移動、戰鬥並使條件成立」假設下的能力分析，不保證任意HP區間、
時間、禁用旗標與玩家操作組合都會實際起手；選定候選仍須正常路線驗證。

候選將既有Case693頭目階段增援改為：75%HP階段成立後，等同一存活頭目真正開始
phase-two-shot。FlagsCountReached 對起手旗標與 boss-defeated 取至少一項，產生
boss-guards-trigger，再由 FlagDelayElapsed 啟動0.75秒增援延遲。
其他波次／機關、兩分支、88EXP與原村同隊返回保持。提前擊倒走明示替代來源，
不會冒稱曾出招；增援未清除仍不能結算。

## GAME_RUNTIME_OBSERVATION：提前擊倒與必要增援

分類 OFFLINE_SYNTHETIC／SERVER_DESIGN_CHOICE。只靠起手旗標的草稿有可達性風險：
玩家若在第二階段出招前正常擊倒頭目，必要增援永遠等不到事件。靜態能力分析只能證明
招式有可用路徑，不能保證每次操作都會發生。修正是上述明示的擊倒替代來源，不在引擎
偽造起手事件，也不略過必要波次。新增正流程案例透過實際玩家普通攻擊擊倒1HP頭目，
證明沒有起手旗標／事件、替代來源可生成增援、增援存活仍鎖出口。

## 驗證與交付

[完整收據](monster-attack-start-validation.json)記錄最終來源、保存第三版與實際Host。
來源關卡 SHA-256 `0da3df175d7750791b67722a392e96551d04c31bda7b68aaa64f2d0d7e037c28`；
來源AI `d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
保存第三版關卡 `e1d3b5bcb9430b9f44233a24c5be7e24323b006f47e579b265f658245f7a33db`；
AI `1da219eed214eb67da8e41510989304a0cbd2ebfc525952dab5012269dac03a0`。
GUI序列化使AI位元組改變，解析語意保持相同，不宣稱位元組相同。

- Host、Inspect、Admin Release建置均零警告／錯誤；HappyPath 776/776，零失敗／跳過。
  新增五項正流程涵蓋真正起手、精確模型／PRE／波次配對、fork與loop重置、攻擊前置
  與波次的聯合鏈，以及提前擊倒替代來源。已起手傷害不因新旗標取消。
- 來源版及保存第三版各走兩條正常TCP分支；四條均保存88EXP並原村同隊返回。
  舊延遲候選兩條對照也保持88EXP。入口沿用既有建隊／進村／選關adapter。
- 保存第三版另由獨立即時Host跑完六圖、88EXP入帳及同隊回村。唯讀Server診斷依序
  記錄：階段已達但未起手且延遲未開始、Entity513／Model1086／PRE1／boss-arrival
  實際 phase-two-shot 起手、0.75秒後頭目仍存活時增援。分類
  READ_ONLY_SERVER_DIAGNOSTIC_NOT_CLIENT_ACK，不是Client動畫或自主AI確認。
- 工作台實際GUI顯示及編輯事件欄位，第二版改名連動引用並成功保存；第三版透過HTTP
  保存替代來源。三版配對ZIP及舊版均保留、下載校驗一致。服務腳本與來源、CSP／SRI
  一致。隔離Admin與Host已停止，來源DB不變；未替換使用者服務或Client資源。

Schema已鏡像及解析，typed載入器與正常路線通過；沒有使用獨立JSON Schema引擎
作完整驗證。775項早期結果及第一、二版只保留為歷史，不代替最終776項及第三版證據。

後續：[RAID1～3正常路線](../testing/RAID-ATTACK-START-NORMAL-ROUTES.md)已另批補齊。
以下保留本批快照及原收據界線，不將後批結果回填到本批證據。

本批新增事件的遊玩證據限一般Case693；Story／RAID回呼已接線並建置，須另做正常路線。
提前擊倒替代來源有實際戰鬥領域測試，完整TCP／Host此次走存活頭目出招分支。
指定v2、人測與自然全新帳號主線待驗；錯誤、重送／重登、故障、安全、併發與壓測維持待測。
這批擴充不宣稱全部MEF或原生格式已完成。
