# S00 ↔ T01–T16：研究請求收件、認領、回報、審查制度

**正式內部工作流程（2026-10-29）。** 此程序不包含 Agent 自動喚醒，也不開放外部 Issues。只有 GitHub `main` 上已發布的紀錄才對其他獨立對話／Agent 具有共同可見性。 `research/requests/index.json` 是唯一權威請求台帳；各 Task 的 `inbox/Txx.md` 是可重新產生的唯讀視圖，禁止手改、不要複製第二份狀態。

## Task 啟動的必要順序

1. **先確認 main 最新 SHA**（如 `git fetch origin main`），閱讀 `AGENTS.md` 與對應版本 `kr/tasks/Txx/README.md` 或 `tc/tasks/Txx/README.md` 既有 T01 退回專區及 `kr/tasks/Txx/task.json`；不可用舊快照誤認未派工。
2. 閱讀本 Task [收件箱](inbox/T03.md)（依 Task ID 選相應檔）及 [RR 台帳](../requests/index.json)，必要時 `python -B research/dispatch/dispatch.py show T03 --version kr --version kr`（TC 改 `tc`）；**不得跨 KR/TC 認領**。
3. **先處理 T01 NEEDS_FIX／FIXING 的已核准退回優先級**；再按本次明確使用者指示及 P0、P1…研究請求排序。若使用者指定工作範圍不同，以指示為準並記錄延後理由。沒有待辦時續原 Task 計畫。
4. 如需接手 RR，先檢查最新 main 是否仍為 `QUEUED`，確認自身 Task 為 owner，於**個人工作分支**提出 `CLAIMED` 更新（包含 actor、工作分支、當次 main SHA）。**認領更新經審核合併到 main 才算公開認領**；若他人已認領，不得覆蓋。無提交權／未授權 Push 時先提供變更交 S00 協調，不能聲稱鎖定。
5. 認領後改 `IN_PROGRESS`，依原 Task BIN-first、來源 SHA、精確證據/未知、修正與提交規則進行定向研究。只研究 RR 所需的**最小阻斷問題**；不要覆蓋原作者原稿、task.json 或其他主責。
6. 完成時將完整 Markdown 分析存入原 Task 研究位置或明確的交接文件，提供 repo 相對路徑、Git blob SHA、Client KR/TC 及原件 SHA、函式/offset/分支證據、結論適用條件、反證、未解問題、受影響 SPEC/GAP/TEST，再將 RR 改為 `SUBMITTED` 並更新原台帳。
7. T01 可在 `IN_REVIEW` 做必要的來源/原生證據核對，**其原有「T01 驗收退回事項」是另一條嚴格品質流程**。S00 對有限證據與規格影響進行審核，若不足標 `NEEDS_REVISION`；能滿足該 RR 精確完成條件才由 S00 記錄 `ACCEPTED`、附來源與規格結果。即使 RR ACCEPTED，也不自動將 GAP 標 RESOLVED、CLM 升為 NATIVE_VERIFIED 或 SPEC 升 STABLE。
8. `BLOCKED` 必須附可操作解除條件；S00 重新確認可行時再 `QUEUED`。不可刪除舊事件／改 ID 逃避審查；已 ACCEPTED 的新問題另開新 RR。

## 狀態與唯一寫入入口

| 狀態 | 誰處理 | 下一步 |
| --- | --- | --- |
| `QUEUED` | S00 建立與指派 Task | Task Agent 認領 → CLAIMED |
| `CLAIMED` | 指定的 Task Agent，已記錄 actor/branch/main base SHA | IN_PROGRESS |
| `IN_PROGRESS` | 同一認領者做限定研究 | SUBMITTED 或 BLOCKED |
| `SUBMITTED` | 研究者提交具檔案 blob SHA 的 Markdown 報告 | T01/S00 → IN_REVIEW |
| `IN_REVIEW` | T01（原生驗收）／S00（規格整合） | S00 ACCEPTED 或 NEEDS_REVISION |
| `NEEDS_REVISION` | 來源 Task 重新認領/修正 | CLAIMED |
| `BLOCKED` | 研究者說明阻斷，S00 協調 | QUEUED |
| `ACCEPTED` | S00 記錄已審核的 SPEC/CLM/GAP/TEST 結果 | 本 RR 結案 |
| `CANCELLED` | S00 決定不再進行，保留歷史 | 另開新 RR |

原 RR 既有 `status`（PENDING/ACTIVE/RESOLVED/BLOCKED/CANCELLED）由程序同步；**不可只修改其中一個欄位**。所有流轉都寫入 append-only `dispatch.events`，CI 檢查順序；CI 不替代 Git merge 的併發衝突審核或原生語意審查。

## 操作範例（在 repo 根目錄；只修改本機 checkout）

```powershell
python -B research/dispatch/dispatch.py show T03
python -B research/dispatch/dispatch.py transition RR-0008 CLAIMED --version kr --actor "t03-agent" --branch "t03/rr-0008" --base "<當時 main 40碼 SHA>" --note "認領選角回覆的定向補證"
python -B research/dispatch/dispatch.py transition RR-0008 IN_PROGRESS --version kr --actor "t03-agent" --note "開始讀取既有來源與有界原生補證"
python -B research/dispatch/dispatch.py transition RR-0008 SUBMITTED --version kr --actor "t03-agent" --report "kr-temp-roy/研究交接.md" --note "完成有界回覆 handler 分析與殘餘未知"
python -B research/dispatch/dispatch.py transition RR-0008 IN_REVIEW --version kr --actor "T01" --note "開始核對來源 blob 及必要 native 反證"
python -B research/dispatch/dispatch.py transition RR-0008 ACCEPTED --version kr --actor "S00" --note "已核對 RR 完成條件，更新 S00 規格" --outcome "SPEC-FLOW-0001"
python -B research/dispatch/dispatch.py check
```

以上是**示例，不表示 RR-0008 真的已認領或完成**；報告檔需要存在。CLI 不會自動 Git commit／push，須遵守使用者的每次授權。若工作分支與 main 有競爭更新，重新 fetch、核對最新 RR 及所有 append-only 事件再合併；不要 force push。

## T01、S00 與研究者的權限界線

- S00 建立 RR、指派 owner_task（只依現有 task.json 主責）、評估回報對 SPEC/GAP/TEST 影響；不更動 Txx 原稿內容。
- Txx 只對自己的 RR 認領／研究／回報，不自行結案或變更其他 owner；T01 原有退回優先規則不變。
- T01 仍在 Task README 退回專區維護精確 native 的 NEEDS_FIX 等標記，與本表的 NEEDS_REVISION 完全**不同**；不得因本請求已接受就把 FAILED/PARTIAL 自動升為 FULL-PASS。
- GitHub Actions 只檢查 schema、歷史狀態、來源 SHA、收件箱/開工入口一致；**不代表 Agent 已獲通知、原生 BIN 已驗證、Server 已實際運作或原版遊戲可玩**。


**雙版本規範**：KR 與 TC 的 Task 名稱相同，但原始 SHA、位址、分包語意不可互借。RR `owner_task=T03` 且 `client_version=kr` **只屬 KR T03**；TC T03 需 `client_version=tc` 的獨立 RR 與對應 GAP，沒有時不構成待辦。CLI 的 `--version kr|tc` 會在認領／回報時阻擋版本不符。
