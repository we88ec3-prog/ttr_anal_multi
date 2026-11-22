# 指定怪物擊倒訊號

2026-11-23。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
補普通怪物個別擊倒到 MEF 規則的事件橋。既有 `BossDefeated`、整波清除與
[出招起手](MONSTER-ATTACK-START-SIGNALS.md)保持；不把普通守衛改成必要頭目來取得事件。

## 資料與觸發契約

新增 `MonsterDefeated`，同一份 scenario V1 可宣告：

```json
{"flag":"guard-fell","event":"MonsterDefeated","monsterModel":1009,"monsterPre":1,"waveId":null}
```

`monsterModel`為1～65535、`monsterPre`為1～255；省略／null `waveId`只觀察初始組，
具名值只觀察該順序或定時波次。必須在本節點實際出生定義中有相符的模型／PRE。
此事件沒有 `attackId`、區域、互動或延遲欄位；需要延遲時另接 `FlagDelayElapsed`。
同組有多個相符成員時，第一個實際擊倒即成立，不代表全部相符成員或整組清除。
不選擇任意世界Entity，也不由 Client 傳入成功布林值。

只在已接受的正傷害將目前敵人 HP 降至0時通知當前副本。血量更新、死亡動作／移除排程
及原擊倒EXP累計保持，既有普通任務擊倒回呼仍執行；新增事件在該回呼之後、必要頭目
回呼及落地掉落之前，僅提交旗標與首次匹配的 Entity／Model／PRE／WaveId 事實。
這不表示EXP／任務／背包已完成持久化；原提交與結算gate仍各自生效。
死亡動畫結束、移除封包、換圖、讀取診斷不能冒充擊倒。

事件要求當前節點已進入且戰鬥時計開放。索引按wave/model/PRE分派，沒有觀察者的舊內容
不建立事件事實。回呼不直接插入怪物；增援沿用敵人更新之後的排程位置，旗標延遲在
正常節點更新首次觀察時起算。頭目、原波、所有必要增援及投射物等清場條件沒有放寬。

每個尚未成立的旗標只保留第一筆匹配事實。入圖清空當圖觀察，旗標依既有reset scope／
保留規則處理；已保留的旗標不重新記錄。fork複製目前事實而不共用可變容器，實際loop
重訪且旗標重置後可重新成立。Entity只標識該訪次的實際戰鬥物件，不是永久身分。

載入先檢查來源怪物及欄位，再沿既有生怪／旗標固定點，只有已可生成的怪物組能提供
擊倒旗標；不能靠尚未可生成的自己波次死亡來解鎖自己。所有必要怪物清除後，該節點
宣告的擊倒事實可加入後續路徑的保證集合。AI引用旗標仍經同一配套可達性檢查。
能力分析沿用玩家可移動並擊倒敵人的假設，不取代每份內容的正常操作驗證。

## 作者範例與工程證據

[Case693候選](phindos-stage462-case693-monster-defeat.scenario.json) SHA256
`a6a55bcb15e0a7fc8f5a141b63ec23af75e51f2f1f8e750190cd790d73c702cb`。
從flag-delay版本c0b22c41衍生，原BND／機關／分支／末房頭目及88EXP政策保持。
node1把第一名普通怪改成已使用模型1009、HP1；同伴1022設定HP120。這是明示作者測試值，
不是原服守衛配置或平衡。初始守衛擊倒→0.25秒旗標延遲→原定時增援；
`entry-ambush`中1022擊倒→允許原順序增援，出口另要求兩個擊倒事實。node1沒有requiredBoss。

管理端「旗標與互動訊號」新增此事件、怪物組／模型／PRE欄位，隱藏不適用的招式ID。
同一元件保留起手事件的招式欄位。實際瀏覽器r2把初始旗標改名guard-fell，r3把具名波
旗標改名ambush-fell，相關延遲、波次及出口引用同步；歷史r1再讀仍保持原名。
三版同版scenario／AI／manifest ZIP精確重讀及歷史不變；AI表單LF→CRLF使bytes不同，
只主張語意相同。候選與保存版除這兩次精確旗標改名外語意相同。

來源r1及保存r3各兩條正常TCP分支，正式登入、廣場建隊、進村選關、戰鬥／拾取／機關、
頭目、結算與同隊回原村，均一次88EXP入庫。增援出生快照證明：守衛Entity257已0HP，
同伴Entity513仍100HP，guard旗標成立；後續具名事件指向Entity769、wave entry-ambush，
不是初始同模型同伴。原flag-delay兩條舊控制仍88EXP，沒有新事件事實。
讀取器初次誤用既有agent未提供的WaveId，修正為原出生座標識別同伴；成功來源TCP未重跑。

保存r3另由獨立真實時計Host正常六房通關、88EXP保存及原村同隊返回；只讀診斷獨立觀察
普通守衛擊倒且同伴仍活、未整組清除，以及具名增援的事件。它們不是Client ACK。
準備角色4／Lv15／教學與Q15前置，不是自然新帳號全程。

[機器收據](monster-defeat-validation.json)綁定來源／鏡像schema、三版配套、四新TCP／兩舊控制、
獨立Host、Web CSP／SRI、DLL、畫面及TRX。三Release零警告／錯誤，**786 HappyPath**
通過，零失敗／略過；四項新正流程覆蓋實際擊倒共存、模型／PRE／波次與首次事實、
生怪依賴鏈、fork及實際loop重置。最終測試使用兩名合法具名波成員的完整fixture。
收據SHA256：`61574b98f46d1cf20d6b90974ceb6dfdefe67c316a21918a69f5824c56e2b7aa`。
Schema已鏡像／解析、typed載入與工作台保存通過，沒有宣稱獨立JSON Schema引擎完整驗證。

`GAME_RUNTIME_OBSERVATION`：本批普通Case693工程通關。Story／RAID／內容測試場回呼已接線，
新事件在這些adapter的正常路線仍待驗；指定v2、人測、自然新帳號、Client自主AI及原生格式
不提高狀態。數值錯誤／邊界、重送／重連、併發、故障、安全與壓測維持待測。
原件、種子DB及現用Host／Admin不變，只停止自己的隔離服務，整體MEF目標保持進行。
