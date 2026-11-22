# 主線副本的入場演出播放政策

2026-11-23後續：[圖形工作台](STORY-ENTRY-SCENE-WORKBENCH.md)已完成三種選項、四保存版、
歷史讀回及來源範圍控制。四TCP／兩真實時計Host維持5984EXP與同隊回村，793HappyPath通過。
下方JSON-only／GUI待辦為前批界線；指定v2與其餘演出功能仍分開追蹤。

2026-11-23。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。接續 M07／M12 的內容播放政策，
沿用已綁定敘事版本的原場景鍵；不是新增 SEQ／Lua 或普通場景常駐 runner。

## 作者欄位

Story scenario 的逐節點定義可加：

```json
"entryScenePolicy": "FirstVisit"
```

| 值 | 此節點每次 Enter 的行為 |
|---|---|
| 省略或 EveryVisit | 每次派送原敘事該節點的完整 EnterScenes 序列，保持舊行為 |
| FirstVisit | 本場此節點 NodeVisit=1 走完整原序列；NodeVisit>1 直接交接戰鬥 |

「首次」以既有 scenario instance 的逐節點訪次計數為準，不以 loop 輪次、進圖次數、
連線、帳號或 Client seen 檔判斷。分支第一次到達的新節點仍播放自己的序列；本場多次返回
同節點則沿原 NodeVisit。未完成任務重建新 instance 時重新適用首訪，不聲稱永久播放一次。

欄位為 nullable 並於 null 時不寫出，舊檔與既有序列化保持。catalog 只接受具有
`SERVER_STORY_NAVIGATION` 來源的 `story-quest-*`，實際 Story 配置再核敘事 SHA、任務、
節點數、地圖與模型順序。普通狩獵場／RAID 沒有借用這個欄位派送任意 scene。

## 交接與權威

入口選角及每次出口規劃先在既有新建／fork instance 的 Enter 記錄訪次，依該次政策決定
EnterScene 或 Encounter；仍經原進度提交才發布節點與戰鬥。播放時的 Scene 及 SceneReported
讀相同有效序列。略過時沒有偽造003F，也不建立等待不存在回報的演出 phase。

FirstVisit 只省掉後續重訪的入場序列派送；IntroScenes、ClearScenes、ReturnScenes、
頭目／清場規則、點集重建、擊倒EXP及最後任務獎勵都沿原流程。實際派送0047與合成玩家
003F分開記錄，不能把任一回報當作 Client 確曾播放；seen／輸入與原內容生命期限制仍依
[既有交接分析](../../kr-extra-roy/MEF-level-functional-closure-20261118/finite-handoff/report.md)。

唯讀診斷 `entryPresentation` 顯示政策、目前訪次、sourceScenes 與 effectiveScenes；
它不是新的 wire 欄位或 Client ACK。此次作者入口是 JSON／HTTP 保存配套，專用圖形選單待接。

## 候選與證據

[Q119候選](story-q119-monster-defeat-firstvisit-entry.scenario.json)只比既有逐輪擊倒候選
多 node1 的 `entryScenePolicy=FirstVisit`，其餘 JSON 語意完全相同；原候選／基線保留。
候選 SHA256 `31f4f544ee0183298891c3a2ffdb2cd04b16be0d69a0ee86072fa043ca7f3464`。

[收據](story-entry-scene-policy-validation.json) SHA256
`0a1761e1160055b9e3c4aaa79239c1a8f436461739d72bf691dcc30d5e555f97`。

- 三個新 HappyPath 正流程驗省略／EveryVisit／FirstVisit，三輪訪次1,2,1,2,1,2,3,4，
  原場景鍵與順序、每節點有效序列、一次結果與一次敘事完成。最終793項全通過，零失敗／跳過。
- 工作台實際HTTP預覽／保存及兩次相同四檔ZIP，scenario／AI／experiencePolicy／manifest
  SHA配對；預覽仍為5936～5984EXP、最大8訪。未操作或替換現用Admin／DB。
- 五條測試時計TCP：兩條原structured控制5932／5972、新候選停止／三輪5936／5984，
  加原逐輪擊倒候選三輪5984控制。直接比只差一欄的擊倒版本：原場景2派送／回報三次，
  新版各一次，逐訪地圖與擊倒經驗一致；全部Q119場景派送／回報序列逐項核對，非只看總數。
- 兩個保存配套獨立真實時計Host走正常登入／廣場建隊／進村／NPC／編隊／戰鬥，停止4訪
  及三輪8訪各只派送／回報一次場景2。每輪初始及具名擊倒旗標重新成立；保存5936／5984EXP、
  一次Q119獎勵5880EXP／40mastery、Q120游標及Town1Map182原隊返回，SQLite唯讀核對。
- Host／Inspect／Admin三個Release零警告／錯誤，三份Python工具語法通過。來源DB SHA保持，
  所有本批隔離Admin／Host停止，現用服務、使用者資料與Client原件保持。
- 更新執行器／公開schema，並修正私有文件schema的既有落後；三份現行schema bytes一致，
  SHA256 `acd72e28e1f1897a0dbbadcacb362fad9e9622e5ff98075929f7b7e584838fc2`。
  文件鏡像同步不代表本批新增了其中既已存在的循環／分支功能。

`GAME_RUNTIME_OBSERVATION`：本批是OFFLINE_SYNTHETIC／LOOPBACK_TCP工程證據，沒有新指定v2
畫面／按鍵驗收。原生播放結果、自然新帳號、其他副本／圖形政策編輯與既有暫緩的重送、重連、
邊界、故障、併發、安全及壓測仍分開追蹤。派送減少不直接當CPU或Client卸載量；整體MEF仍未完成。
