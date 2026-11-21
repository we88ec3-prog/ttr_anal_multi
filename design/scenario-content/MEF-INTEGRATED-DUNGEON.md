# MEF 完整副本：Case 693 整合版

2026-11-21。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。沿用現行 scenario V1、MonsterBehavior 與既有 Server 權威，不宣稱還原官方 MEF 容器或 Client 自主 AI。

## 內容與入口

使用逢德斯村 Stage 462 / Case 693 的原版地形、節點、兩條分支及必要頭目。獨立檔 `phindos-stage462-case693-integrated.scenario.json`，保留基線與舊版。正常流程：廣場建一人隊 → 逢德斯村 → 選 Stage 462 / Case 693 → 開始 → 10 → 1 → 3 → 5 或 6 → 4 → 2 → 結算 → 原村莊隊伍。

- 節點 10：擊敗入口敵人、拾取 Product 183，在出口互動機關消耗 1 個。SQLite 扣除與帳本先提交，背包／快捷數量先發布，才解鎖出口；同時關閉出口區域的 Server 傷害機關。
- 節點 1：保留清怪後依序增援；增加入場計時增援，所有波次完成才開門。
- 節點 3：清怪後啟動分支機關；兩個出口都要求已通過入口機關及分支機關，選一條並於節點 4 匯合。
- 節點 2：初始護衛清除後召出頭目波次；頭目波次剩餘血量達 75% 時召出階段增援。出口必須等待頭目死亡、階段發生、所有增援清除及清場延遲。
- 原有擊殺經驗保留；三名新增敵人各 4 EXP，兩條路線均預期共 88 EXP（68 擊殺 + 20 通關）。掉落、機關耗材、經驗與結算沿用既有持久化服務。

頭目階段是 Server 血量門檻與增援編排，不代表新的原生動畫或變身。機關是既有 checkpoint / marker 與 Server 區域傷害，不代表 Client 動態碰撞。不得增加未證實 opcode、修改 Client 或覆寫原件。

## 驗證範圍

兩條路線各用獨立 SQLite 測試帳號、準備好的 Lv15 角色及已完成教學／Q15 進度，經正式廣場建隊與村莊選關 handler，使用原版 BND 移動、戰鬥、拾取、機關、結算及返回同一隊伍。逐波證明頭目血量旗標在頭目仍存活時觸發；核對耗材帳本、內容 SHA、保存經驗與單次正常結算。

此為離線／合成正流程，不是全新帳號全程升級、TCP 端到端或指定 v2 Client 實機通過。實機需由使用者正常操作驗收兩條分支、checkpoint 顯示與頭目增援；重送／重連／併發／故障等維持待測。

## 完成收據

[整合內容](phindos-stage462-case693-integrated.scenario.json) SHA256
`424b8d5afc3aa822e286e384c7924334ac3800b3b748c6fe521e048b5ce59026`。
[機器可讀收據](mef-integrated-dungeon-validation.json) 保留兩路徑原收據 SHA、耗材帳本、存活頭目階段與結算證據。

- 兩路線 `10,1,3,5/6,4,2` 均通過正常建隊入口、原 BND 戰鬥、互動、通關、原村隊伍返回與 88 EXP 保存。
- 節點 1 計時增援在零擊殺時加入；依序增援在三名敵人擊敗後加入。頭目房初始護衛死亡後頭目加入，兩名階段護衛加入時頭目仍為 ACTIVE、只擊敗一名初始護衛且出口未開。
- 機關帳本為實際內容 SHA／node10／interaction11／role4／Product183／qty1，掉落拾取提供耗材，扣除後餘額0，背包與快捷數量先於出口開放發布。
- Release Host、檢查器皆零警告／零錯誤。HappyPath **640/640**，零失敗／略過；TRX SHA `14bd18550040a8a359b279c404c030dc87cb6e69dc294777a952df2cd48bf363`。
- 隔離實際 Host 啟動檢查通過：Case693 min/max88，其餘694～696仍76；未替換目前商城測試 Host/Admin，沒有操作 Client。

私有工具 `tools/check-mef-integrated-dungeon.py` 重新執行兩路線並核對上述證據；參數為 `--analysis-directory`、`--bounds`、`--output`。驗證輸出在 `E:/Tartaros/workspace/outputs/mef-integrated-20261121`。

啟動腳本 `tools/start-phindos-acceptance-host.ps1` 新增 `-IncludeIntegratedDungeon`，檢查兩庫內容 SHA。此設定獨立於 `-IncludeCombatGrowth`／`-IncludeDungeonEquipment`／`-IncludeRotruaStory` 比較版本；不開旗標則保留既有內容。Stage462仍依既有規則輪替Case693／694，694並未改成整合版。首次Case693可測此內容，其他帳號須先正常完成教學／Q15及滿足角色等級；不得以此開啟未解鎖村莊。

`GAME_RUNTIME_OBSERVATION`：本輪為新增的 OFFLINE_SYNTHETIC 整合證據，沒有新的指定 v2 實機結果；入口、機關顯示／互動、兩條分支與頭目階段至返回村莊列為實機待驗。傷害地板沿用既有 Server hazard 單元正流程保護，完整路線證明的是機關旗標與通關整合，不宣稱新原生視覺／碰撞或 Client CPU 卸載。
