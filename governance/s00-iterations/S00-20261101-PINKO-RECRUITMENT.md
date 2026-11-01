# S00：首戰後蘋果家劇情與招募接續

下一段來源更正、有限劇情報告觀測與未閉合出口，見
[教學出口閘門](S00-20261101-TUTORIAL-EXIT-GATES.md)。v4人測版本保持原樣；
新增觀測尚未部署，不把它寫成已看到玩家後續劇情。

## 實際觀察與需求

使用者操作指定工作副本後回覆：「編隊頁關閉，戰鬥後返回／新劇情」；補充
「轉場太快我不確定是否有看到轉場畫面，須等更長的轉場確認，蘋果家劇情結束後就中斷無法繼續」。
REQ-0014 保留歷史失敗，追加 v3 首戰通過觀察；**載入畫面仍 UNCONFIRMED**。
新增 REQ-0015 / GAME_RUNTIME_OBSERVATION，處理蘋果家劇情後無法接續。
這不是使用者要求提早解鎖角色，也不是影片怪物數或 MEF 假說的需求。

測試主程式 SHA256：`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`，
為指定修改工作副本，不能冒稱原版 Client 相容性。原始 KR 分析目標 SHA256：
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
使用者操作本機 loopback v3，沒有附加／修改 Client。實際 v3 metadata 記錄
10:30:31.708 UTC C2S28、31.7409 UTC C2S09，10:30:36.8825 UTC Server 勝利持久化及返回。
metadata 沒有 body，不能僅據 opcode 宣稱已核對某個 scene ID。

## 已保存腳本與舊實作的分界

Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
TutorialMain.lua member SHA256
`662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`。
本機唯讀 bytecode metadata：Part2 / root.5 的 pc106–109 呼叫
PlayAndWaitForScene(1000,13)，pc113–122 反覆等待 IsCharacterAvailable(2)，
pc126–136 再顯示 PostUIMessage_EmployChar(2) 並等待玩家確認；之後 scene1000/14
及下一段 scenario 提示。沒有執行 Lua。

這包可能含歷史本地翻譯，不當成全套未修改原始資源；但上述精確腳本流與使用者阻點相符。
舊 `anal/new_expedition.py:unlock_pinko_after_scene` 也在 3F/1000/13/1 後發 role2 grant/stats，
只作歷史實作參考，不能以舊 Server 自訂判定冒充官方授權／完整原生 wire 契約。
故「欠缺 role2 更新造成等待」目前是有腳本支持的根因候選，須新版本人測確認。

## Server 候選規劃

1. 保留首戰同 connection 的 Server 勝利持久化與正常返回，不以客戶端任意完成通知授勝。
2. 只有已返回且 DB 當前 lease、既有 Isilia、首戰完成紀錄符合，並收到精確
   3F/1000/13/1 候選事件時，才在同 DB transaction 新增固定 role2/Pinko。
   不提供通用任意角色 grant；保留既有角色／名稱。
3. 新增 ownership 時更新 expedition／tutorial revision，再讀回 profile，發既有候選
   2B role grant 與 role2/level1 stats，供腳本的 IsCharacterAvailable(2) 繼續。
   不重跑 6E、不重置 TUTO、不跳過招募視窗或偽造 Quest14/16 完成。
4. 既有 global schema v2、兩個 component v1 不變，不需要新 migration。
   後續任務／裝備／第二段戰鬥／離場與廣場仍須繼續開發，不能以招募通過結案。

這是 opt-in working-copy candidate；normative pin
`dd69ec9de353a695d25c6db8e362ff471ea0c137` 不變，formal admission OFF/BLOCKED。

## 驗證與下一輪人工段落

13 個 HappyPath cases 通過；既有首戰旅程列延伸至場景通知、role2 grant/stats，
並以獨立 SQLite 查詢確認 role2 已保存、profile revision4。仍 207 方法／9 正向方法／198 暫緩。
合成資料採 temp DB、all-clear bounds、可控 clock，沒有證明實際 Client 招募／劇情接續。

人工段落：正常登入→移動／視角／切角→預設伊莉西亞首戰→返回→招募伊莉西亞→
蘋果家劇情→確認蘋果招募→下一段提示／入口即停；不進第二場或按跳過教學。
若遊戲實際順序不同，以畫面與 metadata 排查，不反覆重按。

角色重送、已取得角色、錯場景／順序、斷線恢復、過期 lease、並行交易、部分傳送與 DB 失敗
記入待測試，現在不執行。正常後續任務與完整戰鬥仍屬當前目標。

## v4 本機啟用紀錄

2026-11-01 11:17:21 UTC，以已授權的指定 Host 換版；同 DB、Admin 及 Client 保留，
沒有 migration。Network DLL SHA256
`6e3a7d4b6cb60f5f53212043ff455b39dabe5a343d9abcf5a744a8da204e9d21`；
Persistence DLL SHA256
`379abb75530d28279c9930f14b1c2e49a91b8d52aa3766b23732cb86ff3cc536`。
私庫 commit `3680210dd7a1ea415b712a615ebac57efa45b7a5` 的 CI run41301192148 success；
公開分析前一 commit `29e31970c87ebb03ecf4ac6b6af17963fa2873cd` CI run41301196968 success。
上述 CI 不證明本版招募人測成功；結果卡已送出，尚待回報。

## 預先核對後續，避免重用舊錯誤

已找到本機 T07 舊交付 `kr-temp-roy/T07/completion-closure/` 的
TUTORIAL-PLAZA-CLOSURE-INTERFACE.md、CORRECTIONS.md、FOLLOWUP-UI-AND-BOUNDS.md，
以及 post-t01/V9-PROVISIONAL-REENTRY-AND-UI-GAPS.md。這些是待整合的有限來源，
本輪只讀取／交叉對照，未把全部舊主張當作新的原生驗收或正式 spec。

- 首戰後依序為招募4、蘋果家、取得／確認角色2、1000/14、提示8。提示8只更新教學 UI，
  不足以當完整教學退出 ACK；任務15屬進廣場以後，不能提早完成。
- 舊 helper 誤稱 QuestMgr 5030C0 是004C；T07更正為0064。TUTO場景的短004C/14
  與 QuestMgr 結算不能混用；接續時須逐段重核，不照抄舊helper。
- 廣場 init／最後map reset會清除綁定；需在最後reset後重建並綁定。
  舊只等B0策略缺少依據，不能重犯；43也只作特定entry階段進度，不稱通用ready。
- Map511/Town5/900,900仍是候選配對與位置，靜態可走不等於官方spawn或實際可操作。
- 舊_LoadDisplay背景表／parser是後續調查線索，不表示轉場下載MEF；不靠固定等待假造完成。

下一段開發需結合實際招募與最後提示事件，補教學14/16、必要資料與場景交握，
再驗收同登入進廣場後的角色、NPC、移動和停止。沒有以首戰／招募代替完整目標。
