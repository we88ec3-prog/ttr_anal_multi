# Wing 傳送卷軸：普通狩獵與 RAID 的 Server 候選

2026-11-18，分析基準 `7344eeb65198e2dd61684b66cf811021765ed8f5`，私有 Server 基準 `e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4`。本輪新增實際道具消耗與同場位置轉移候選，並將原生已證部分、Server 選點政策及未完成事項分開；不是原服傳送選點或原生 MEF 還原完成。

## 固定來源與可採用的部分

| 來源 | 核對結果 |
|---|---|
| Product／Item | Product 5342 → Item 5308「윙(순간이동)」，class 13、堆疊 255、COOLTIME group 3 |
| Item 說明 | 瞬間移動到傳送點，須傳送點已開放。沒有秒數或目的座標 |
| ItemUsable | 唯一 Action 10／priority 5，沒有選點參數 |
| CashProduct | 100 件：16 Garnet；200 件：24 Garnet |
| 原背包使用路徑 | `5FFF60` 的 class-13 switch 走 `600454`，比較目前 mode 4／9／28，經 `60049B → 4A39F0` 產生既有八位元組 `0021`，options=0 |
| 原位置更新 | `4ADD6F` 取 `4AFB80`、`4ADE71` 寫入 `+B4`（`4+8*0016`）登記位置 consumer；`4AFC6A` 分出 0016 的立即位置路徑，保留它既有 actor／兩個 float 形狀 |

[唯讀驗證器](../../governance/client-variants/20261118-cash-shop/verify_wing.py)核對四個 Table member、原 BIN 與指定 v2 全檔 SHA、class-13 的兩層 switch 資料以及 16 個指令錨點。[收據](../../governance/client-variants/20261118-cash-shop/wing-source-verification.json) SHA-256 `cb57535163e38af84379d29fa39ee49381004943154ed4ba2483c5c6d4c7689f`。四個有界區段的 797 筆列示指令、2,984 bytes 均與兩版原檔對應，沒有將全函式或本功能提升 FULL-PASS。

[局部指令](../../governance/client-variants/20261118-cash-shop/wing-instructions.txt)、[擷取程式](../../governance/client-variants/20261118-cash-shop/DumpWingInstructions.java)、[既有 bulk 來源索引](../../governance/client-variants/20261118-cash-shop/wing-source-index.json)可追溯。REA session 核對目標為固定 KR BIN；其 analysis activity 仍為 not_observed。本輪使用既有 bulk 導航及 Ghidra 12.1.4 的獨立唯讀 PE 匯入、`-noanalysis`，只反組譯上述窗口；原件不寫入，專屬暫存 project 已由 headless 刪除。原 Client／Lua 均未執行，正式方法 owner、RR 與驗收狀態未改。

這些證據**沒有證明原服的傳送點選擇規則**，也沒有把 category 1 的 Server 手動互動點當成原生傳送點。mode 28 的道具使用入口可見，其場景用途仍待核對。現行 Server 劇情場使用 mode 2。

## Server 選點與使用政策

目的地採 `SERVER_DESIGN_CHOICE`：目前普通狩獵場或 RAID 節點的已編排主出口 `node.Portal`。該出口必須已由本實例解鎖，座標須可站立，角色須存活、可操作且未處於施放／受擊鎖定。多出口圖仍選主出口，沒有目的地選單或新封包欄位；不自動改選分支、移村、進下一圖或結算。這是相容服候選點，不宣稱與官方 telepoint 身分相同。

背包 `0021` 按實際格、快捷 `0022` 按已有綁定使用同一交易。SQLite 同時檢查租約、格位、商品、群組冷卻並扣一件，沿既有 `002C`、快捷總量及 `00B7` 發布。群組 3 暫沿既有 4 秒時間策略，與完全復活卷軸及 CP 書的同群鎖定共用；**官方 Wing 秒數仍 UNKNOWN**，不能把 4 秒寫成原表事實。

提交後，Server 停止移動與排隊輸入，取消當前普通發散／玩家返回投射物等既有 ReleaseEncounterInputs 所處理的狀態；保留同一 combat instance、HP／SP／MP、技能冷卻、怪物、波次、地面物品及任務／結算權威。Pose 設位保留面向並重設移動積分起點，發既有 `000B／000C／0016`。沒有生怪或重建地圖；玩家仍須到出口按 Z，才走原有驗證與換圖。畫面、特效與操作手感待 v2。

交易資料版本 V29 只擴充快捷欄的 Product CHECK 以接受 5342。V28 的既有綁定與其他資產原樣複製，髮型資料及商城價格目錄不變。任務 Q2844 發放的同一 Product 也可進這條用物路徑；本輪付款合成不替代該任務的既有自然取得證據。

## 離線與合成驗證

`CashWingPositiveTests.cs` 的八例涵蓋普通場與 RAID 1／2／3，各自背包及快捷使用。隔離帳號經既有教學取得伊希莉亞，再買 100＋200 件 Wing 與 200 本回復之書，Garnet 1,000 → 904；Wing 分 255／45。以保存的 5238 綁定建 V28 夾具後遷移 V29，再綁 Wing 總數 300。普通場實際清怪並等待主出口解鎖，移動後使用一次；回覆位置等於候選點，快捷 299，4 秒冷卻。背包路徑從 45 扣為 44，快捷路徑從 255 扣為 254。

核對同一戰鬥物件、資源、技能冷卻與節點／圖／路線／出口狀態／拾取／經驗／完成狀態，重開 store 保存兩個綁定、資產與冷卻；使用本身不換圖，再明確按 Z 才進下一圖並保留資源。普通地面與 RAID 地面都是明示的合成 bounds，沒有本輪原版 BND 走位或 TCP 執行。初跑最後一步誤填固定出口鍵 1 而失敗，修正為從實例已開出口取實際鍵後通過；失敗與成功 TRX 保留。之後再補正常角色取得及 RAID 2／3 個別夾具，共八例通過，原版 BND 逐圖落點與指定 v2 仍另驗。

Release Host／檢查器已建置通過。從前批已停止的隔離 DB 副本啟動 `-IncludeCashShop -PreflightOnly -IsolatedPorts`，V28 → V29 成功，商城與髮型 pins 保持；Host 自動退出且四個隔離埠無 listener。收據、完整 HappyPath 與限制見 [驗證索引](cash-wing-validation.json)。本輪未替換實機 Host、未操作 Client。

## GAME_RUNTIME_OBSERVATION：CS-08 與剩餘工作

既有缺口是 5342 可付費／任務領取但一般使用沒有效果。此修正只交付上述 Server 候選。CS-08 待集中排程：正常買 Wing 並領取、綁快捷，到普通場與 RAID 1 分別驗背包／快捷，在主出口已開後使用；記錄落點、面向、背包及快捷扣量、冷卻、資源、怪物／地面物及手動 Z 的後續。若 Client 顯示的真正 telepoint 與候選不同，記錄類別、座標與啟用事件，調整 Server 編排，不能將候選直接標原版一致。

官方選點／啟用與多點政策、Wing 原秒數與特效、mode 28 場景用途及後續接入、原版 BND 逐圖落點及指定 v2 仍待完成。其他 class-13 的解除狀態與隊伍抗擊退用途仍獨立待開發。整體商城目標維持未完成。
