# KR T10-24 — 普攻與技能連接的功能鏈證據矩陣

研究日期：2026-10-27 Asia/Taipei。KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；BIN 唯讀、PE .text VA 0x401000/raw 0x400。T10 普攻／T11 技能施放共用邊界，未執行目標，符號名稱暫定。本 GitHub 版是有證據摘錄的研究筆記；完整且更長的 objdump 連續節錄保存在另附本地長版原稿，兩者不是逐字一致。

## 本批核心發現
控制器 `0x546780 -> 0x546100 -> 0x54F270` 連結了輸入結果與技能可用性 gate；`0x54F270 -> 0x40F7F0/0x819220 -> 0x81A8E0 -> 0x54F4E0` 連結矩陣 key 與狀態容器。這是已確認跨 T10/T11 呼叫鏈，但 **不是**技能發動、連段續接或招式互相 cancel 的完整閉環。

## 轉換四象限
| 假說 | BIN 進度 | 需要證據 |
|---|---|---|
| Z 連按續段 | 未證實 | Z/action row、motion completion、下一次 input consumer |
| Z held 自動續段 | 未證實 | held writer、動畫終了重採樣、next action |
| 普攻中接技能 | 僅 availability gate 已證實 | 同 actor current motion 到 skill accept/cancel/queue |
| 技能後接普攻 | 僅共用狀態來源已證實 | skill completion、state reset、held/pressed accept |

## T11 待研究標記
確定 T11 相關：0x54F270 availability、0x819220/0x81A8E0 matrix mapping、0x54F4E0 cooldown-entry 容器查找（有插入副作用）。部分引用自既有 T11：0x549980 SubAI condition。可能相連但欄位意義不足：0x549D54 成功後狀態寫入、0x5961C0 phase event dispatcher、0x547240 timeGetTime 500ms。**不可直接當技能規則**：0x50C640 cmd 0x22、0x548918 cmd 0x68、純 matrix lookup、0.65 秒本地替代連段窗。

## 下一批 T10-25～28 / T11
優先找 actor+0x3E8 的所有 writer、0x549D7D 狀態 4 的 reader/clear、0x54F4E0 的剩餘時間非零 writer。需實際 Table/KeyMapping.xml 核定 Z。最後才比較四種接續路徑；不得覆寫其他 Task 目錄或自行補原版 timer 值。

## 範圍
本段是 T10 主導的跨 T11 技術關聯研究，不重編 T11 專屬分段，也不修改 T11 owner/task.json。