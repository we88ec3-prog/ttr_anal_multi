# RAID 單場正常入口與匯出配套驗證

此模式獨立於舊完整主線檢查器，使用一次性 SQLite 準備帳號，走正常廣場、
建立一人隊伍、選 RAID、開始、五圖原 BND 走位／戰鬥／出口、成功結果、
確認返回廣場及交付經驗書。它是 `OFFLINE_SYNTHETIC` 應用層封包處理，
不等於 TCP、新帳號從零養成、指定 v2 Client 或原生 MEF 驗收。

## 準備條件與保存界線

角色 4／Lv.17 的經驗直接按固定 `rotrua-experience-candidate-v3.json` 門檻準備；
教學與 Q15 里程碑預先提交，沒有在本輪實際遊玩這些前置，也未宣稱完成 Q144。
既有主線資料與前置保存由同一故事 reader 載入；開始及結束的故事狀態必須相同。
這是準備帳號用例；既有新帳號 Q144／自然 RAID 收據仍保留原版本範圍。

裝備準備 Product 2725 武器及 11262 護甲，經正常穿戴封包裝入角色 4 的格 1／15。
HP 卷軸 Product 232 準備 20 件並綁正常快捷格 4；檢查器在 HP 低於 60% 且
四秒冷卻結束時模擬一次使用操作，核對扣件、冷卻及最大 HP 30% 的回復量。
這是測試輸入，不是 Server 新增自動喝藥。沒有降低怪物強度或改遊戲平衡來通過。

CP 使用現行每日刷新規則，入場前後均為 3,000；每場只出現一次成功結果，
提交／交付一本對應經驗書 2274、2275 或 2276。其餘背包、資金、穿戴實例、
角色 EXP 及故事狀態保持；卷軸剩餘量須與實際使用次數一致。
獎勵先經既有背包快照及新獎勵差量發布，在廣場啟用 `0024` 前確認可見。
正常成功返回會執行既有隊伍清理；不是主動離隊或失敗流程測試。

## 六場收據

[最終收據](raid-normal-route-validation.json)逐場保存內容、AI、原始輸出 SHA。
三個固定基準及工作台實際匯出的三份 AI 配套均通過，合計 30 次地圖載入。
每個 RAID 的基準／配套分別擊倒 16／20／18 隻怪；卷軸使用次數依戰鬥而異：
基準為 3／3／4 件，配套為 3／3／3 件。不能由這些數字推廣成官方平衡或所有
任意編輯稿均可通關。此檢查器不是通用機關／訊號求解器。

初期正流程嘗試在未配裝、以及只配裝但未使用回復品的情況倒地；保留診斷，
未選敗退、未等倒數結算或執行其他暫緩分支。最後採明示的普通裝備／卷軸前提。
另修正工具只查 `0029` 快照、漏查現有 `002C` 新獎勵差量的斷言；這不是
Server 發獎故障修復。最終六場均正常成功，遊戲／管理服務及玩家資料未更動。

## 重現

本批 Host／檢查器 Release 建置零警告、零錯誤，HappyPath 631／631 通過；
最終 TRX SHA 列於收據的 `validation`。本批沒有更換遊戲或管理服務。

在私有 Server 建置 Release 檢查器後執行：

```powershell
python -B tools/check-normal-raid-routes.py --analysis-directory E:/Tartaros/workspace/s00-runtime-dev --raid-bounds E:/Tartaros/workspace/outputs/early-raid-bounds --story-bounds E:/Tartaros/workspace/outputs/fresh-early-raid-story-bounds --output E:/Tartaros/workspace/outputs/raid-normal-route-new
```

此命令跑三個基準；`--raid 1` 可限定一場。以重複的
`--paired-bundle-directory <已解壓配套目錄>` 追加實際匯出版本。每個目錄須有一份
工作台清單與配對的兩個 JSON；先核對檔名、SHA 與 RAID 設定鍵，再啟動檢查。
每場 stdout／stderr 及矩陣摘要留在指定的新輸出目錄。

直接檢查器順序如下：

```text
--raid-normal-route <raid> <固定基準> <raidBounds>
<override或default> <overrideSHA或default> <AI或default> <AISHA或default>
<story> <storyBounds> <storySHA> <experience> <experienceSHA> <trade> <tradeSHA>
```

固定來源、曲線及目錄契約以工具內的 SHA 與原有 reader 為準。
Client 操作／換版、重登、重送、失敗、故障、安全與壓測仍各自待排程。
