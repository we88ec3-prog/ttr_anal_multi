# T03 — 固定研究設定（ChatGPT Project 參考文件）

> 新建：2026-10-28。此文件只記 **T03 長期適用**的工作範圍、Client↔Server 封包分析與驗收方式。大型批次、三輪深入門檻（`NNN`／`NNN-2`／`NNN-3`）、BIN-first、完整 Markdown、GitHub 協作與提交授權，均以 `02-PROJECT-SHARED-INSTRUCTIONS.md` 為準。**短期進度、入口位址及最近 Commit 僅放 `04-T03-NEXT-CHAT.md`。**

## 0. T03 專用分支與新對話同步（2026-10-28）

- **唯一 T03 工作分支：`t03/roy/chatgpt-web`**，repository `we88ec3-prog/ttr_anal_multi`。T03 後續技術原稿及專屬文件獲明確提交授權時，**只 Commit／Push 至此分支**，不得直接推 `main`。既有 `main` 原稿不搬移、不重寫；不改其他 Task、catalog 或 owner。
- **每次新對話開始，尚未做任何新的 T03 正式研究前，先查遠端最新 `main` 與 `t03/roy/chatgpt-web`，將最新 `main` Merge 進 `t03/roy/chatgpt-web`，並核對結果**。方向固定 `main → t03/roy/chatgpt-web`，絕非反向；若合併有衝突、工具不支援、無法確認合併已成功，必須明示阻塞，**停止新的正式研究段落**，不可謊稱同步或直接覆寫文件充當 Merge。需要合併 `t03` 回 `main` 時必須另外取得使用者明確指示。
- 「每次新對話先 Merge main」是本 Task 的**使用者明確指定同步程序**；不得擴充成平時可以自動推送研究筆記。**研究新段落的 Commit／Push 仍只在使用者明確要求時執行**；提交後逐檔遠端讀回核對，回報 commit、分支與 URL。
- `03` 僅記長期規則；兩分支最近 commit、最新正式段號、欠缺的特定證據列在使用者新對話單次提供的 `04-T03-NEXT-CHAT.md`。**新對話啟動指令由使用者在對話訊息獨立提供，不放入 `04` 文件**。

## 1. 正式任務範圍

- Task ID：`T03`，KR《星空幻想 Online／Tartaros Online》**登入與角色選擇**。研究玩家啟動登入、驗證帳號、選伺服器／群組／頻道、讀取角色清單、選擇角色、連線切換，以及進入遊戲世界以前由 Client 執行的本地狀態／UI 轉換。
- **Client-first**：核心問題是玩家操作後，原版 Client 實際**送出哪些 C→S 封包**；Client 收到**哪些 S→C 封包**，由哪個 handler 消費、修改哪些欄位或 UI，才進入下一個畫面或切換連線。對資料的接收與轉換需分清原始 wire 格式、本地 parser 輸出及 UI 結構。
- 原版 Server 內部認證演算法、帳號存儲、密碼規則、分流政策、資料庫與新建角色邏輯若無第一手資料，不以還原它們為 T03 的驗收前提；依 Client 已證收發需求列為 **Server 待開發／相容介面**，不得把本機 Python Server、fixture 或測試常數當作原版規則。
- 目前只研究 **KR**。TC 版本、封包識別、字串、地址均不得直接套用。

## 2. 責任邊界及依賴

- **T02** 主責底層 socket、framing、分派及連線層通用行為；T03 負責登入／選服／角色清單／選角的業務封包及 Client 效果。
- **T04** 主責角色建立、角色狀態與出生／世界初值；T03 只研究 Client 如何接收角色清單與可用旗標、如何呈現與提交選擇，不決定世界內角色初值。
- **T05** 主責真正場景／城鎮轉入與選角後世界切換；T03 研究選角發包、回包及移交接口，不接管場景初始化。
- **T06** 主責 UI 資源、控件身份與存在性；T03 負責登入／角色 UI 由哪些業務狀態與回覆驅動。
- 保留 `kr/tasks/T03/task.json` 既有 `owner=roy`、`state=in_progress`、`native_complete=false` 與既存登記，不自動變更 owner／catalog；跨 Task 只引用已確認證據。

## 3. 優先序：完整玩家操作與雙向封包

### P0：登入及驗證

- 從使用者輸入／按鈕 → Client 格式化與轉換（包含歷史已核的字串寬度／MD5 文字鏈）→ C→S packet builder／queue／socket，逐一確認 opcode domain、資料長度、欄位來源、連線 endpoint、前置條件與失敗分支。
- 追 S→C 認證／結果碼 → 具體 handler → 本地狀態與 UI 消費，確認成功／失敗如何改變畫面、是否切線；**原版結果規則不可由本機測試伺服器猜補**。

### P0：選服、群組／頻道與連線切換

- 玩家選擇伺服器／群組／頻道 → row/selection 狀態 → C→S 查詢或選擇封包 → S→C 清單／結果 → UI 更新與新連線；逐個查證有無發包、封包欄位、時序、舊連線結束及新連線建立的關係。
- 對已知 `group/channel`、`register` 參數、`mode40/52/54` parser 等歷史成果，先讀限定範圍；避免重複已核對的小型函式而不前進到完整選服功能鏈。

### P0：角色清單、選角、進入遊戲

- S→C 角色名單、可用狀態／欄位 → parser／state writer → UI 名單與選角控件；玩家點選角色 → C→S 選角封包 → S→C 確認／拒絕 → Client 轉移／移交 T05。
- 特別核對角色清單到 UI 的 **producer、delivery、consumer** 和結果旗標，不把 5C、`F4247`、`F42EF` 等歷史記錄中的代號未驗證即認定為 wire opcode；必須確認命名空間與實際位元組。

### P1：錯誤、重試、重新連線

- 原生 Client 是否有 timeout、拒絕／斷線、重試、取消、重選角色及回到登入畫面的流程；核對 C→S、S→C 及 UI 層，不以未找到發包等於沒有發包。

## 4. 原始資料與證據分級

- 主要來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`、版本相符的 KR 資源及實際封包（若有）。**每次重新檢查實際檔案與 SHA、PE section**，地址以原始 BIN 校正；既有反編譯只作定位。
- GitHub：`we88ec3-prog/ttr_anal_multi`；任務正式來源 `kr/tasks/T03/{README.md,task.json}`。完整反編譯導航 `kr-bulk-roy/<KR BIN SHA>/{functions,raw}/`，按需求取函式；先讀 GitHub `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`。
- 逐項標記 **原生已確認／部分確認／合理推測／AI 替代／資訊缺失／Server 待開發**，對 opcode、帳號規則、角色初值、登入結果、端點、長度、時間不猜值。已確認的局部 parser、字串或 UI 函式，不能冒稱完整登入／選角可玩驗收。
- 不執行或修改目標程式、原始資料；不得自行提交 EXE/BIN 或原始封裝；有新證據更正既有說法時保留舊結論與反證。

## 5. 每段交付及驗收

- 每段研究以**一條完整玩家情境**為核心，提供矩陣：`玩家行為 → Client 本地條件 → C→S（opcode/len/fields/是否確實送出）→ S→C（opcode/len/fields/handler）→ Client state/UI/連線結果 → Server 待開發接口 → unknown`。
- 完整 Markdown 保留來源 SHA、VA/raw、真實 assembly、分支／CFG、caller／callee、函式資料流、buffer/structure offset、封包方向、偽碼、否證範圍、依賴與下一入口。對話只報主要玩家可感知成果、未知與 GitHub 狀態。
- 遵守共用三輪深入門檻；沒有實質新發現時，同一段依序加深 `NNN-2`、必要時 `NNN-3`，不得只改段號、重列函式清單；實際輪次記入同一完整原稿。
- 不設定虛構的「完成百分比」；**研究完成不等於可遊玩**，Client 雙向收發和畫面反應需要能獨立驗證。

## 6. 新對話與 GitHub 權限

1. 閱讀 `02-PROJECT-SHARED-INSTRUCTIONS.md`、本 `03`、使用者單次上傳的 `04-T03-NEXT-CHAT.md`。
2. **先執行上述 `main → t03/roy/chatgpt-web` Merge**，讀回確認同步成功；再以同步後的工作分支讀 Task、證據、跨 Task 接口與已有審核原稿，先去重再分析。
3. 使用 KR BIN-first 大型批次追新入口；不能取得實體檔時將缺口具體交由本地驗證，不把缺失說成原版不存在。
4. **只有使用者明確要求時才提交新研究成果，且目標限定 `t03/roy/chatgpt-web`**；即使沒提交要求仍保存完整 Markdown 供下載。`04-T03-NEXT-CHAT.md` 是新對話單次上傳文件，**不自動推送 GitHub**；啟動訊息由使用者另外複製。
