# S00 — Server 需求來源與證據品質（2026-10-30）

**本政策把「需求從哪裡來」與「它已被證實到什麼程度」分開。** 原始遊戲程式碼、合法執行時觀察、玩家／管理員需求均可**直接提出 Server 需求候選**，不必先取得另外兩種來源。單一有界 Client code finding 即可登記候選需求；不等於已證官方 Server 實際送包、Server MUST 或已完成互通驗收。

## 一、使用者確認的三個正式入口（ACTIVE）

| origin | 何時發現 | 可提的需求類型 | 須分清的界線 |
| --- | --- | --- | --- |
| `CODE_ANALYSIS`（程式碼分析） | **任一 Txx** 研究遇到 Client 組包／發包、收包 handler、等待 Server 結果、錯誤分支、狀態轉換或需要資料服務的呼叫 | Server 收取 C2S、可能要提供的 S2C、連線/錯誤/Session／狀態需求；尚不清楚 opcode 也能登記明確待查條件 | 有本地 producer/consumer ≠ 原版 Server 實際傳過此包；「可被 Client 處理」≠「每次登入必須發」 |
| `RUNTIME_OBSERVATION`（直接執行遊戲） | 在**已另行授權**、合法的離線／測試環境，觀察實際遊戲行為、合法紀錄、封包或 UI 操作 | 某個實際可重現的請求／回覆、狀態順序、失敗／重試要求 | 必須記錄版本、環境、步驟、原始觀測與不確定；一次現象不是所有情況的政策 |
| `USER_REQUEST`（玩家／管理員需求） | 玩家、管理員或維護者指定功能、管理動作、玩法、權限及 UX | Server 新功能、管理流程、權限、資料保存、運維、產品需求 | **需求是真實的設計輸入，但不是原版 Client 相容性證據**；若舊 Client 無介面，須標記 Server-only 或需新 Client／另行授權修改 |

三個入口是**平行的需求發現管道，不是三關驗證**。需求可有多個來源；只出現一種也應入庫。需求審查依實際證據品質進行，而非要求至少兩種來源交叉背書。

## 二、另外建議的來源（PROPOSED，先不強制啟用）

| 建議 | 來源例子 | 值得納入的原因 | 限制 |
| --- | --- | --- | --- |
| `CLIENT_RESOURCES`（遊戲資源／設定） | XML、Lua、場景檔、任務／UI 資料、版本化的客戶端資源 | 程式碼未直接顯示的任務條件、場景映射、配置欄位，可能暴露需要 Server 維持的狀態 | 靜態資源鍵不是封包命令；不證明真正 Server 何時觸發 |
| `HISTORICAL_PROTOCOL_ARTIFACT`（歷史協定與舊 Server 文件） | 合法保存的歷史封包、伺服器設定、舊版端點／日志、公開技術協定記錄 | 可補充真實消息配對、版本差異及 Server 曾用的資料型態 | 必須查來源、版本、權限、時間與可信度；第三方記憶或未驗證文件只當研究線索 |
| `IMPLEMENTATION_FEEDBACK`（實作與測試回饋） | 獨立 Server stub 整合測試、離線 conformance 失敗、授權的回歸測試、維護缺陷 | 實作時會發現流程中缺少 reply/error/timeout、管理功能與規格矛盾 | 合成測試只能證工具／新 Server 的行為，不能冒充原 Client 觀察 |
| `EXTERNAL_DOCUMENTATION`（官方資料／玩家行為文件） | 版本化官方手冊、過往發行資訊、可信玩法說明 | 補足遊戲功能、管理規則或版本需求背景 | 外部文字不能單獨決定 payload byte layout；社群報告需標明未核實 |

是否將這四類設為正式 `origin` 枚舉應由維護者另行決定；目前只記錄為候選補充類別，**不阻塞前三類工作的收件**。

## 三、每次發現到 Server 需求的處理（適用所有 T01–T16）

1. 研究者在原稿標示「Server需求候選」與方向：`SERVER_RECEIVE` (Client C2S)、`SERVER_SEND` (Client S2C)、`STATE_OR_POLICY`（狀態/管理/權限）。沒有確定的包號或方向時填 `UNKNOWN`，不得猜值。
2. 記下 Client 版本/SHA、原始觸發來源（Native VA/raw/函式/事件，或完整執行記錄，或需求敘述）、條件/負例、能證實與尚未知部分；若是 Native 分析，沿用 T01 source/intake、CLM、RR 的引用方式。
3. **不強制新增 RR 才能提出需求**。先在研究原稿保留候選，S00 於主線整合時去重並登記 [Server 需求候選索引](../spec/server-requirements/index.json)；只在缺少特定 Client 原生證據且既有 RR 未涵蓋時建立新 RR。
4. S00 將候選分類為 Client 相容約束（本地源碼條件已知）、待驗證的 Server 收發／狀態假設、或 Server 自行設計的功能/政策；建立對應 SPEC/GAP/ADR/TEST 影響，保留異議、來源及歷史，避免同一發現重複開不同編號。
5. **入庫不代表發布**。需實作的 packet MUST 依精確 Client source-backed layout/狀態批准；Server-only 的使用者需求可經正式 ADR/設計審核轉為應實作規格，而不需要假造 Client 會收該封包。
6. 任意一類需求都可要求後續測試，但**執行原版 Client 或連接原版 Server 仍須本專案另行明確授權**。不得因 `RUNTIME_OBSERVATION` 被列為來源就默認允許啟動。

## 四、來源、證據與決策三軸

| 軸 | 用途 | 不應混淆 |
| --- | --- | --- |
| 來源 `origin` | 是在 code、runtime 或使用者需求哪裡發現需求 | 不表示已由幾個獨立來源支持 |
| 證據 `evidence_status` | `CLIENT_STATIC_BOUNDED`、`RUNTIME_RECORDED`、`USER_INTENT_ONLY`、`UNVERIFIED` | 本地程式碼分析可支持**有限**約束，不等於真實原 Server 回覆 |
| 決策 `status` | 先 `CANDIDATE`；必要時另由正式流程形成 SPEC/ADR | 不自動變成 `SPEC STABLE`、`RR ACCEPTED`、`NATIVE_VERIFIED` 或可遊玩 Server |

**例子：**在 T03 程式碼中確認 LOGIN scene 有 S2C `0x0013` handler，這已足以提出「Server 將來可能要提供合法 `0x0013` 回覆」候選，不需要玩家去執行遊戲才能登記；但是「E8 登入後 Server 第一包必定是 `0x0013`」仍 UNKNOWN，不能寫成已證的規範性 MUST。

另一個例子：管理員要求 GM 封鎖帳號，是可直接登記的 `USER_REQUEST`，日後經 Server-only 設計與權限審核可納入實作規格；**無須尋找舊版 Client 的 GM 封包來證明需求存在**。

## 五、發布及責任

- 此候選索引由 **S00** 維護。Txx 在原作者 Markdown 中提出，不自行更動其他 Task 的研究、原始證據或 S00 正式狀態。
- 使用者明確提出的需求可直接在研究/規劃/管理需求單出現，不必依附於一筆已有封包的 RR。
- `CODE_ANALYSIS` 來源可立即建立具證據的候選與 DRAFT 規格；如果內容不足，掛 GAP 與明確缺口。後續的合法動態驗證是提高把握度的方法，不是強制的第二道來源門檻。
- 建議來源尚未正式採納之前，仍可作研究引用及規格草案背景，但不要標成官方相容證據。

目前專案 Source/CLM/RR/SPEC 的驗證流程維持獨立；[Iteration 10](S00-20261030-ITERATION-10.md) 仍聚焦 RR3/6/7 條件式收發鏈，不能因候選被建立就提升成熟度。
