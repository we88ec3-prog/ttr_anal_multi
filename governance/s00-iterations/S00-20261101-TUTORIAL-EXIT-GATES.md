# S00：蘋果招募後的教學出口閘門與有限觀測

本輪是原目標「新帳號完成新手任務後進入廣場」的接續，尚未達成。
沒有新增人工結果，REQ-0015 招募人測仍待回。沒有重新啟動／附加 Client 或執行 Lua；
本機 v4 服務保持原樣，未因診斷變更中斷使用者測試。

## 舊來源中必須沿用的更正

唯讀引用 `anal-multi/kr-temp-roy/T07/completion-closure/` 的
NPC-ROUTE-CORRECTION.md、TUTORIAL-PLAZA-CLOSURE-INTERFACE.md、CORRECTIONS.md，
及 T14/T14-SCENARIO14-CONTRACT.md。這些原作者交付仍有待整合／部分確認限制；
本輪不代替原作者修改 owner、不把整份交付升 FULL-PASS。

1. **撤回 NPC category3 必發 C2S001C 的假說。** 舊 DEVELOPMENT-HANDOFF 等文字較早，
   後續 NPC-ROUTE-CORRECTION 明確指出 544070 的 category3 走本機 F4388／F43D9；
   544020 發001C 的介面在其他分支，不能依先前提案猜001D完成回覆。
2. 第一戰 scenario14 的 TUTO 短004C/ID14，只寫等待旗標。一般 QuestMgr 的5030C0
   路由是0064，不能因相似命名混用；通知成功不證明教學16已提交／獎勵已領取。
3. scene1000/14 的3F回報早於 TutorialMain 額外 yield／提示8，也可能來自場景載入失敗路徑。
   提示8只更新教學 UI，不是已確認的完整出口 ACK。不能以固定延遲或任意 heartbeat
   當作 Lua 清理完成、招募確認或 Quest16 正式結算。
4. 任務15是廣場後的下一階段，不是離教學前置。15/1開場不能提早記任務15完成。

## 本次資源交叉核對

原始 KR BIN SHA256仍
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
本輪唯讀解析目前 Table.stp（carrier SHA
`ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`）：
QuestInfo member SHA
`5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。

- Quest14：type3、town0、field18、giver/finisher10027、AcceptAction/CompleteAction type1。
- Quest16：type2、town0、Demand14、giver/finisher10027、RewardsEtc16 包含 type2/value50。
  此處只確認原始欄位，**不把 type2 擅自命名為金幣／經驗／其他獎勵**。
- 最後教學 checkpoint10016 與任務 giver10027不能因外觀或名稱相近就改成相同 ID。
  T07已比較原始備份並保留此差異，不能用改表消除缺口。

目前資源與原始備份的關係沿 T07 有限比較引用，不將整套資源稱為未修改原始 Client。
QuestTalk 的缺少指定列也不能推定 Quest16 不存在或不需要結算。

## Server 下一版已準備的觀測

既有安全 JSONL 只記 opcode／長度，無法分辨上述1000系列不同劇情；這會讓後續卡點
難以與人測對齊。本輪在**已持久化 Server 首戰勝利且已返回**的 connection 增加
四種固定名稱事件：Scene10Reported、Scene12Reported、Scene13Reported、Scene14Reported。
只接受精確8-byte候選3F/1000/{10,12,13,14}/1；不記原始 body、帳密、自由文字或任意ID。

名稱刻意使用 **Reported**。這只證明 Server 收到符合形狀的回報，不能排除載入失敗、
證明玩家已確認招募、證明原 Lua 完整結束或形成正式完成／獎勵權威。
不新增封包、不改原招募授權、不寫 Quest14/16完成、不建立廣場、不設定完成計時器。
此變更尚未部署到 v4，不能用它解讀 v4 舊 metadata。

13個 HappyPath 合成案例通過：既有首戰正常列依序送10/12、取得蘋果、送14，再收正常
heartbeat；檢查四種事件進入安全日誌，且14之後沒有多餘結算／換場回覆，原 ownership
及 revision查詢仍通過。測試曾遇區域變數名稱衝突與讀取寫入中檔案的共享模式錯誤，
修正測試後同組重跑通過；沒有執行延期異常／重送／競態測試。

## 尚待完成的出口設計與實測

| 段落 | 必須補足的證據／開發 | 驗收限制 |
| --- | --- | --- |
| 招募／最後劇情 | 蘋果實際招募及玩家確認、最後提示／NPC行為，對照有限回報 | v4人測未回，不以模擬3F算通過 |
| Quest14/16 | 達標、提交、獎勵ID域與合法消息／後端策略，原角色／進度保存 | 50的type語意未證，不先填獎勵或完成bitmap |
| 離TUTO | 找到合法完成／退出入口；若採明示Server重建策略，須說明與原生未知的界線 | 不用固定延遲、heartbeat、最後3F單獨冒充完整完成 |
| 廣場安裝 | 引用CSquare69／43有限接口；最後map reset後重建角色、綁定、ready與輸入credit | 43不是通用ready；不再唯一等待B0 |
| Map／NPC／位置 | 釐清Town5、物理selector與候選可走位置；NPC與互動點分開配置 | 劇情NPC／靜態可走不證官方spawn |
| 完成判定 | 同一次登入，全部教學、必要任務與廣場場景／角色／NPC、移動停止及無殘窗 | send成功、CI、完成flag或重登都不能單獨結案 |

重送、錯序、錯世代、斷線恢復、過期lease、交易／傳送失敗與安全／壓測仍列待測；
目前先完成正常教學至廣場。normative pin與formal admission均不變，未新建正式RR或改他人工作狀態。
