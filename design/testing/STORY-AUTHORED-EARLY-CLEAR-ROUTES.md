# Q119：先清初始組的明示替代分支

2026-11-22，SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
承接[Story起手路線](STORY-ATTACK-START-NORMAL-ROUTES.md)，本批另存AI變體，不能把結果
當成未變更舊版角色配置的提前清場證據。原版Client、資源及現用服務沒有變更。

原r1的正常角色與普通攻擊，在清完兩名初始敵人前已產生起手事件。取消等待起手的工程探查
仍觀察到該事件，故不能宣稱原r1已走「未起手先清除」。它的完整出招通關控制仍保持。

本批在隔離工作台複製原草稿資料庫、保存同一草稿的r2，r1下載位元組保持不變。
新增[關卡](../scenario-content/story-q119-early-clear.scenario.json)與
[AI配套](../scenario-content/story-q119-early-clear.monster-behavior.json)：

- 只讓首圖兩名初始敵人使用 `story-initial-delay-v1`。此profile完整複製
  `legacy-melee-v1`，只改ID與 `startDelaySeconds=30`。
- 血量60、傷害15、追擊／移動／冷卻／招式保持；護衛仍用原AI，沒有延後所有敵人。
- 原起手訊號、初始WaveCleared替代來源、0.4秒護衛旗標延遲、每輪scope重置、圖序、機關、
  三輪上限與獎勵均保持。30秒是自有編排設定，不是原版規則或通用死亡政策。

因此可在正常玩家攻擊下清除初始組，觀察 `story-initial-cleared` → `story-guards-trigger`
→ 0.4秒 → `story-guards-ready`，且初始 `story-attack-started` 與起手事件集合保持空。
護衛仍須實際生成並擊倒；不能以初始組清除直接結算。護衛本身可以照原AI出招，空集合只
表示觀察初始組的訊號未發生，不表示整場沒有怪物攻擊。

停止與三輪正常路線分別4／8訪、14／26次擊倒、56／104擊倒EXP、一次5880任務EXP，
合計保存5936／5984並同隊回Town1／Map182，Q119一次入帳及Q120游標保持。
上限在首圖第1／2／3訪各有獨立visit ID及重新成立的初始清除／延遲旗標。
這些是準備教學／Q15前置後的正常NPC／編成／戰鬥，未注入旗標、修改HP或強制清怪。

## GAME_RUNTIME_OBSERVATION：Story配套的地形預檢遺漏AI

分類為工程工具的OFFLINE_SYNTHETIC，不是Client實機問題。Server基準`8b0d04d`的配套
reader可讀回r2，但獨立Host驅動接著呼叫 `--export-story-loop-terrain` 時失敗，尚未啟動
該r2 Host。原匯出入口只載入預設AI，沒有傳入已配對的AI檔；新增profile ID因而缺席。
原碼與失敗階段支持此成因，不能把完整配套reader通過誤當所有部署前置均已使用配套。

修正需求及實作：地形匯出保留舊命令，另外接受AI路徑／SHA成對參數，使用同一配套驗證
場景，輸出 `monsterBehaviorSha256`；獨立Host驅動傳入reader核對過的同版AI，並保存地形
匯出的stdout／stderr。原r1與新r2都經此路徑再驗證，沒有放寬未知AI檢查。

[最終收據](../scenario-content/story-early-clear-validation.json)分開r1出招控制、r2停止與
三輪的正常TCP及真實時計獨立Host，綁定原／新scenario、AI、policy、地形預檢SHA及
當版DLL。工作台r1不可變、r2四檔配套與policy位元組保持已核；HappyPath776項、
三Release零警告／錯誤。隔離Host／Admin停止，來源DB保持。

界線：這是明示30秒初始AI的新r2，並未證未修改r1以目前角色可先於其2秒起手清場。
普通Case693／RAID的完整提前擊倒替代路線仍各自待辦。Server診斷不是ClientACK、
Client自主AI或指定v2人測；自然新帳號及既有暫緩測試仍分開，整體MEF目標未完成。
