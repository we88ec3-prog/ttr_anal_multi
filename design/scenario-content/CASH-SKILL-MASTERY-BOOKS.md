# 商城技能熟練度書的購買與使用

2026-11-18。分析基準 `055f27de71b82ef41ee133fd025fda3b187cc71d`；私有 Server 基準 `72bf3e83ef41e958805de1a876abfda70bcb6f3d`。本批接續商城付款／領取與既有[技能學習](../runtime-content/SKILL-PRACTICE-PROTOCOL.md)，不改 Client 或原件，實機及換版仍暫停。

## 原件與有界結論

[唯讀驗證器](../../governance/client-variants/20261118-cash-shop/verify_mastery_books.py)核對 Table.stp、既有封裝 reader、Product、ItemTable2、ItemUsableTable 與商城目錄的固定 SHA。[來源收據](../../governance/client-variants/20261118-cash-shop/mastery-books-verification.json)保存全部身份及逐項結果。原始檔與完整遊戲 member 留本機。

| Product | Item | 技能熟練度 | 永久單件價格 | 堆疊／冷卻群組 |
|---|---|---:|---:|---|
| 18209 | 16537 | 2,000 | 32 | 255／6 |
| 18210 | 16538 | 5,000 | 64 | 255／6 |

兩列 ItemUsable 都恰有一個 Action 5／priority 5，其 VALUE 與 Item 的「技能熟練度」說明相符。本結論限定這兩件商品，不把所有 Action 5 或所有 class 21 的用途一概外推。角色 EXP、戰鬥 SP、CP 與技能熟練度保持分開。原表只證冷卻群組 6；本批沿用 Server 既有的 group 6／1,000ms，是 SERVER_DESIGN_CHOICE，沒有宣稱官服秒數已還原。

## 原子入帳與餘額

正常廣場或村莊的已擁有角色可用既有 C2S `0021`，指定實際背包格與 Product。既有保管箱購買／領取先建立帳號擁有的書；使用只扣指定格一件，保留其他格。Server 在同一 SQLite 寫入交易中驗目前 lease／帳號、已存書及冷卻，扣書並累計道具熟練度，再提交。

角色進度初始化與 Host 原有 `EnableStoryMasteryAsync` 入口新增可重入的 `local_expedition_mastery_items(account_id,credited)`。此為相容服內部資料表，沒有往主線任務獎勵帳本塞入虛構 quest。既有已存主線熟練度及學習花費均保留：可用餘額為主線獎勵合計＋已用道具合計－技能學習花費。學習仍用原資格、逐級成本與保存規則；讀取以 64-bit 計算合計及扣除，再保留既有 32-bit 餘額表示。

提交後回覆 `002C` 背包及錢包更新、既有 `002A` standalone profile 熟練度快照、`00B7` 群組冷卻。`002A +6` 使用既有已分析的熟練度欄位；沒有借用技能學習成功視窗 `0128` 當作書籍成功 ACK，也沒有新增 opcode。這是沿既有欄位的 Server adapter 選擇，指定 v2 的提示及面板更新仍待驗。

`002A +0x0E` 必須同時填入已保存 Garnet，來源為既有[商城餘額欄位](../../governance/client-variants/20261118-cash-shop/BALANCE-AND-STORAGE.md)的 `4E2B72..4E2B7B` 原 BIN／v2 視窗。舊 standalone 熟練度發布刻意跳過非零 Garnet 帳號；本批補齊該欄並解除這個舊限制。使用時從同一扣書交易取得 Garnet；登入時由已授權錢包讀回。不能只填熟練度而把商城餘額寫零。公會及其他次要狀態仍維持既有 standalone 限定範圍。

連線內熟練度狀態同時更新，後續學習不能繼續用舊餘額；普通登入從資料庫重建相同餘額。角色 EXP、CP、主線 checkpoint、LeeLoo 與 BP 不因熟練度書改變；Garnet 只於前面的付款交易扣除。

## 正常流程驗證範圍

兩種專項案例各購買兩本、付款及領取，使用第一本後重開儲存層，核對熟練度、剩餘一本及一秒群組冷卻。以新餘額學習伊希莉亞 Practice 53 的 Lv.1，扣除既有成本 100；測試時鐘正常前進一秒，再使用第二本。最終餘額分別為 3,900／9,900，技能及空背包保存，其他錢包欄位保留。此為 OFFLINE_SYNTHETIC 正流程，並非原版畫面。

專項帳號的伊希莉亞原為 Lv.2，以已載 EXP policy 的曲線建立 Lv.5 隔離資格夾具，使 Practice 53 符合原有資格；這筆測試準備不是自然升級證據，正常新帳號路線由獨立 TCP 案例覆蓋。首次完整回歸曾因漏掉等級準備而得到原有的 status 4；第二次準備曾誤用尚未建立馮德斯前置資料的任務 EXP 接口。兩次失敗收據都保留，改用明示的等級夾具後再驗，不降低技能限制或繞過正式任務入口。

既有新帳號正常登入／教學／主線之後的 TCP 商城案例增加 Product 18209。購物車由五列改為六列，共付 338，Garnet 1,000→662；再次登入讀回六筆保管箱，正常領取後用實際格發 `0021`。檢查 `002C → 002A → 00B7` 與熟練度增加 2,000，末次正常登入恢復新餘額，書已消耗、CP 5,000、主線快照與其他資產不變。此例沿用合成碰撞，不作原版 BND／Client 視覺的證明。

CS-04 保留指定 v2 實際使用、提示、熟練度面板及技能學習。未執行陰性、重送、故障或壓測；其他特殊商品、髮型／染色、時限、套裝與完整商城仍待開發／驗收。

最終 Release Host 與檢查器建置均為 0 warning／0 error；三個商城專項 3/3、完整 `Category=HappyPath` **573/573** 通過。[工程收據](cash-mastery-books-validation.json)保存各回合 TRX 的實際計數、結果與 SHA，初始失敗及啟動中止不覆寫。商城餘額的原 BIN／指定 v2 固定視窗驗證也再次通過；這是唯讀來源核對，不是執行 Client。

首次完整回歸的 TCP 末次登入缺少熟練度快照。先將測試擴為保留登入三段全部回覆仍失敗，進一步追到舊 `ReadStandaloneSkillWalletAsync` 的 Garnet 非零略過條件，才修正上述 Server 欄位與發布條件。測試仍要求唯一 `002A`、精確新熟練度及 Garnet 662；沒有藉放寬斷言或重複發包處理。首次 testhost 的 90 秒啟動逾時與前兩次完整回歸的三項失敗收據另存，沒有覆寫成成功。
