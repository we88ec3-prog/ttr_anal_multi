# S00：末段劇情後廣場出口候選接線

REQ-0017 是使用者回報「蘋果招募後開始兩段劇情，結束後應轉場回廣場，卻留在原地」。
目前私庫 Handler 在收到末段scene1000/14後沒有廣場 transition，只記receipt。
這是確切缺少實作的分支；不是已證Client缺檔／MEF接收或任務資源錯誤。
戰鬥仍第一優先；本輪在v6人測結果待回期間開發後續，不替換正在測的版本。

## 舊來源與新核對

唯讀參考本機舊T07 `completion-closure/` 的介面、NPC-ROUTE-CORRECTION及
V6-RESOURCE-PATH-HANDOFF。這些舊分析不是本輪新原生驗收；本輪重核必要入口，
沒有照抄整套舊Python Server，也沒有執行其中含程序／Frida的helper。

- TutorialMain的既存限定流程：首戰14返回後1000/10、12→招募4→checkpoint4→
  1000/13→等待角色2與本機招募確認→1000/14→額外yield／提示8。
  Lua與qbase來源限制沿用先前蘋果招募報告；提示8不是自動安裝廣場的證明。
- category3 NPC走本機F4388/F43D9 UI事件；不能拿通用544020 sender推成該NPC必發1C，
  也不猜1D回覆。這個舊更正保留，未以碰觸NPC繞過目前出口。
- 原始KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
  既存Ghidra `4B9090` SHA `d31cab226005d9f6a81e85cf825638b4182f8ce16283b1c91c0262e534fde299`：
  payload+2 signed type7建CSquare／切場景；+3/+4兩個byte後寫context欄位，業務語意未閉合。
  `4BBC10` SHA `2e667eac98533d19bf480e4bf0cb98005a5ff812c999aeed45897d82759e8e78`：
  清舊資料、使用Single controller／UI2，條件式送4-byte43，尾byte0A。
  43發生於初始化流程，不是完整map-ready或全部欄位安裝完成ACK。
- [兩個原檔bytes視窗](evidence/S00-20261101-SQUARE-EXIT-ANCHORS.json)由
  `inspect_tutorial_exit_sources.py`讀原始PE，核對場景建構／切換、尾欄位讀取、
  controller建構與43組包。初版檢查器的暫存器／立即值寫法假設不符原件，已按實際
  ECX讀取、EAX=43再存AX更正；不是原始程式變動。限定first-ret範圍不是完整CFG／callee語意驗收。

Map511→square001的資源配對、Town5清單／劇情Square03D與官方玩家spawn不可混為一談。
候選仍選map511、900/900，不稱官方Town5映射。來源BoundMap.stp SHA
`07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`，
square001.bnd SHA `97a87b26f7d3f5c80ea4039a4cf7ca9dce664c78004aaa6e03e17bad77af24a3`。
[新靜態核對](evidence/S00-20261101-SQUARE-EXIT-BOUNDS.json)包含兩個教學BND與該廣場BND：
廣場768×768格／world1536×1536；900/900、906/900、900/906的兩個來源層皆0。
這只證選定靜態格，非動態碰撞／官方spawn或實際可走。工具修正以world/grid比例取cell，
不能把world900直接當768格的column900。

## 明示的Server相容策略

新增獨立 `LOCAL_WORKING_COPY_TUTORIAL_EXIT_CANDIDATE`，現有COMBAT模式不自動開啟。
需要原有world／首戰配置與額外絕對路徑square BND；Host在啟動前釘SHA並檢查入口短走廊。
沒有all-clear fallback或等玩家走到最後才發現資源路徑不對。

| 階段 | 實作條件／輸出 | 不代表什麼 |
| --- | --- | --- |
| 同登入首戰 | Server判勝已持久化、world已返回 | 不接受Client通知直接授勝 |
| 後續劇情 | 同connection精確3F/1000/10、12、13、14／status1依序；13須先完成正常Pinko grant，末段角色4/2皆擁有 | 所有權不獨立證本機招募確認；3F也有載入失敗producer |
| 廣場pending | 末段後停止舊pose，送69/type7/tail1/1；清Server舊pose並等待本次pending的43 | type與tail不冒稱完整官方reply，沒有.5秒偽完成 |
| init progress | 收4-byte43／末byte0A，中間byte保持opaque；發map511→reset→metadata/player/stats/resources/kit→bind→timing→14 | 43不是map-ready；資料送完不是玩家已到達 |
| 正常控制 | 使用廣場BND建立新Server pose900/900；沿用移動、停止與單角色重綁 | 不證原版高度／動態碰撞與實際畫面 |

既有主線Session/lease檢查與實際帳號alias保留；沒有另建Session或修改帳號資料。
不重跑6E、不猜NPC1C回覆、不把任務15當前置，不在每個bootstrap重新reset。
scene14 receipt日誌改以「首戰曾返回」為條件，避免出口pending狀態使同一事件漏記；
receipt仍不是完成證書。

## 仍未完成的驗收

這是相容候選，**不聲稱已找到官方Quest16提交／完整Lua退出ACK**。3F載入失敗與正常結束
可能有相同shape，順序／Server勝利只能縮小條件，不能宣稱已區分。重建動作緊接14與Lua清理／
額外yield的實際交錯仍需人測，不用固定等待掩蓋。

沒有寫Quest14/16/15完成、沒有發獎勵、沒有tutorial_completed持久旗標或重登直入廣場。
廣場NPC與互動、真實載入畫面、同登入角色／鏡頭／控制、完整正常Quest16結算及完成持久化仍待補。
因此REQ-0017、人測與整體「新帳號完成教學→廣場」均未結案，不能以新綠測試替代。

## 驗證與接續

16個HappyPath cases通過，原6個Theory rows保留出口OFF；第7列走真TCP／SQLite新帳號，
經正常登入、命名、三怪首戰／X成本與Z、勝利／返回、招募、四段receipt，再69→43→
廣場重建／綁定、Server短距離移動停止及heartbeat；獨立DB查詢保留原有角色／首戰結果。
使用人工構造BND和受控clock，來源BND另如上核對，未執行遊戲或證明loading／UI。
Host Release build零警告／錯誤。208方法／10正向／198待測，沒有擴跑其他類別。

反例／重播／重複43／晚B0、錯序／載入失敗、斷線／重登／逾時、過期lease、partial-send、
DB故障、安全／併發／壓測仍只記待測；本輪不執行。先等戰鬥v6實際回報，再把已準備的
戰鬥與出口修正組成有用連測版本，不為本輪源碼開發中斷目前服務。
normative pin／formal admission、Task owner、APPROVED狀態不變。
