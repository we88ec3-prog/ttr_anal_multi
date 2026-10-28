# T01 FULL-PASS 共用知識整合規則（不按 Task 分類）

2026-10-28 生效。此規則適用 T01 後續驗收與整合；不代表既有內容已經通過全面驗證。

## 一、基本原則

T01 對**完整通過原生驗證的明確結論或子流程**，建立跨 Task 共用知識，而不是按 T01～T16 分類。閱讀者不需要先知道原研究 Task 才能找到或使用結論。**不分類指正式成果的查找、呈現及索引方式；不是刪除原稿、作者、Task 來源、審核責任、Git blob SHA。** KR／TC／其他版本必須分別限定原件，不得混用位址、opcode、資源或結論。

## 二、FULL-PASS 嚴格准入

以下條件全部具備，才可把結論放入正式已驗證共用索引：

1. 指定原件版本、SHA256、PE section、VA/raw 映射；引用可重現。
2. **限定結論內的每個實質肯定主張**都有原生指令／資料佐證，適當查證指令邊界、CFG、caller/callee、資料流、反例及上下游；不能只靠 SHA、抽樣 bytes、局部算術、檔案上傳成功、靜態字串或 AI 推測。
3. 逐條記錄驗證範圍、方法、證據位置、原稿路徑與 Git blob SHA、審核者、日期、限制及 FULL-PASS 決議。
4. 不存在尚未裁決而足以推翻結論的證據衝突／驗收退回；不得以最新檔案或時間戳取代裁決。
5. **FULL-PASS 是精確主張／有界子流程層級，不自動代表整份報告、整個函式、整個 Task、Server 實作或玩家功能完成。** 對於尚未核對的上下游明示 unknown。

## 三、共用知識入口

- T01 將符合上述標準的內容寫入 `shared/verified-knowledge/`，以**玩家功能、協定、資料結構或跨功能流程**提供不按 Task 分類的入口；使用非 Task 維度的獨立結論 ID。
- 每個條目必含：結論、原件版本、精確 FULL-PASS 範圍、上下游關係、證據與 SHA、來源及審核 metadata、相關未解 Client 區段、相容 Server 待開發需求、遊玩驗證狀態、已知限制及更正關聯。
- 與 `shared/catalog.json`、各 Task 的 task.json／owner／method registry 並存：Task 僅作為研究分工、追溯與退回責任，不作為共用成果查找或使用的前提。
- 多個來源重複同一原生事實時整合為一條可檢索結論，保留每個來源與審核關聯；不刪除原稿、不搬動原始證據。

## 四、未達 FULL-PASS 的內容

- PARTIAL、source-only、bounded-reviewed、PENDING、BLOCKED、NEEDS_FIX、AI／fixture、樣本 bytes 核對等一律維持來源與審核追蹤，不得以已驗證的正式結論呈現。
- 如提供未驗證內容的跨功能導航，必須清楚標記「非 FULL-PASS」，不得混入無標示的正式知識。
- 更正、撤銷及再驗證必須保留歷史 SHA、原錯誤、影響範圍與修正版；依 `AGENTS.md` 既有退回程序複驗。

## 五、Client 與 Server 責任邊界

- 原生分析重點是**Client 能實際證實的行為**：輸入輸出、封包建立／發送、收包解析、狀態、UI、劇情及場景回應。
- 原版 Server 如何內部計算任務前置、戰鬥勝負、解鎖、資料庫保存，不需要還原原版 Server 演算法，應分類為 **Server 待開發**；未知 Client 訊息格式與 Client 行為則分類為 **Client 待逆向**。
- 玩家功能尚不可玩應分開標明跨功能整合、Server 待開發、遊玩待驗證，不得以此撤銷已驗證且範圍正確的 Client 局部主張。

## 六、工作程序

1. 按來源 SHA 與 blob 版本接收、去重，保留原 Task、原作者及待驗證資料。
2. 對每個擬提升的**明確主張／子流程**完成原生逐項驗證，遇錯依既有退回流程通知來源 Task。
3. 僅對 FULL-PASS 的精確部分建立 `shared/verified-knowledge/` 共用條目；其他範圍繼續保留在待審核來源。
4. 建立跨功能上下游引用，並分開記錄 Client 待逆向、Server 待開發和待遊玩驗證。
5. 每批記錄新增／更新／撤銷的 FULL-PASS 結論、精確適用範圍、來源 blob SHA 與審核依據；更正時核對受影響引用者。
6. 只有使用者當次明確授權 Commit／Push 才提交研究；本規則本次修改屬使用者明確授權。

## 七、歷史資料與隔離

- 先前 `accepted-claims`、`source-review-status`、bulk review、來源 SHA／byte 核對、bounded acceptance 不會因本規則自動成為 FULL-PASS；必須逐條符合第二節。
- 保留現有 Task 分工、owner、catalog、退回狀態、工作分支及所有歷史原稿，不做破壞性搬移或全面重新分類。
