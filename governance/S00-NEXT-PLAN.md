# S00 下一階段規劃（Phase B 收斂 → Phase C 回饋閉環）

日期：2026-10-29。主責 S00；規格、證據與實作庫分離。此為**規劃與驗收清單**，不是已驗證的原版 Server 架構或可遊玩的成果。機器工作包以 [s00-roadmap.json](s00-roadmap.json) 為準。

## 目前基線（規格準備度，不是原生相容性成績）

- KR 7 份 SPEC：全為 `DRAFT/PARTIAL`，沒有 `REVIEWED/STABLE`。
- 7 項 GAP：全部 OPEN，其中多項 P0 是登入/選角相容性的實質阻塞。
- 8 筆 RR：全部 QUEUED；目前沒有 Txx Agent 的正式認領、研究提交或 S00 回報驗收。
- 5 個 TEST：全部 OFFLINE_SYNTHETIC；未實測原始 Client，未測獨立 Server 封包來回。
- TC 研究 Task 仍獨立存在，但**目前 S00 KR SPEC/CLM/RR 不可直接轉用 TC**。TC 另做同版本證據與規格計畫後才展開。

## 先完成一個 Server-facing vertical slice

```text
B-NET [T02] framers / real first exchange / connection mode
  └─ B-AUTH [T03 + T02] E8/000F → result/status → channel/choice/handoff
      └─ B-CHAR [T03 + T04/T05/T06] roster → choice 0x42 → real success/failure → init
          ├─ B-CONTRACT [獨立、只讀 SPEC 的 implementer] 方向別契約驗收
          └─ B-SCENE [T03 + T05/T07/T16] scene state writer → scene resources
B-CONTRACT → C-ENV [獨立 Server repo 建置與回饋]
```

注意：這是**研究依賴順序**，非已發現 Client 真正的封包順序；B-CHAR 並非確證登入總是先出現哪個 connection slot。B-SCENE 在 S00 裏屬可獨立封鎖的延伸工作包；完整進入世界流程要完成它，但先把 B-CONTRACT 的登入/清單最小契約驗收出來可減少重複研究。

| 工作包 | 級別 | 最先要閉合的未知 | 指派使用已存在 RR | 可驗收成果 |
|---|---|---|---|---|
| **B-NET** | P0 | 連線下首個實際 C2S/S2C frame、mode/slot/pipeline、必要異常回退 | T02：RR-0001 / 0004 / 0005 | 完整的 frame+connection 方向別契約、source-backed vectors |
| **B-AUTH** | P0 | E8/000F 使用條件、登入 S2C 真實配對、選服/連線 handoff | T03：RR-0003；T02：RR-0005 / 0007 | Auth/session request-reply map 與 error/status gate |
| **B-CHAR** | P0 | command2 的 65-byte header、選角 0x42 的成功/失敗回覆、清單後初始化 | T03：RR-0002；T02：RR-0007 | Server 可依文件產生/讀取的角色清單/選角契約 |
| **B-SCENE** | P1（視是否擋住 B-CHAR 調整） | 選角回覆 → scene state → `0x565720` 上游 writer | T03：RR-0008，參照 `extra/roy1` | 場景轉移條件與 script 資源依賴；不猜 `(1001,1)` wire |
| **B-CONTRACT** | P0 交付門檻 | 交出 SPEC 後其他開發者仍須看原稿才能猜的缺口 | S00 規格稽核；T01 必要的來源主張查核 | 使用 SPEC + TEST 的獨立契約驗收報告 |
| **C-ENV** | 後續 | Server 技術決策、隔離測試、Client 實際相容性 | 不在此 repo 寫 Server 程式 | 可公開的 FB、後端自訂 ADR、實作回饋閉環 |

## 即使 RR ACCEPTED，為什麼 SPEC 仍可能不成熟？

**一個研究請求結案 ≠ 一條完整 Server 契約。** RR 的完成只是研究者針對「限定問題」交付可核對證據；SPEC 需另外核對方向別訊息、必要欄位、前後順序、資料版本、異常分支、可重現測試、Server 自訂政策與待補資料。缺少任何阻塞性的項目就保留 GAP。規格 DRAFT → REVIEWED → STABLE 的正式決定由 S00 維護者審核，CI 不自動升級。

研究主張的最低交付：Client 原始 SHA、檔案 blob/source SHA、VA/raw、caller/callee 及條件、byte layout、反例/不成立條件、方向與連線階段、受影響 SPEC/GAP/TEST；需要強 native 保證時由 T01 做原有嚴格複驗，不把部分抽查升為 FULL-PASS。

## 收發矩陣與測試門檻

使用 [Phase B 訊息矩陣](../spec/session-account/phase-b-message-matrix.md) 記錄六類邊界。每個格子應填來源、方向、連線階段、Client handler、Server 需要的 I/O、成功與錯誤條件、至少一項正向及一項負向測試；沒有證據請寫 UNKNOWN，別以地方測試器保守拒絕策略冒充 Client 原生行為。

必須區別：

1. `OFFLINE_SYNTHETIC`：人造 payload 的局部 codec/shape 測試，只能證明工具內一致性。
2. `EVIDENCE_BACKED_VECTOR`（未建立 TEST 類別）：以原始證據支撐的 frame/payload 方向別向量；需要另外的測試等級與驗收規則，不能直接改現有 TEST status。
3. `SERVER_CONFORMANCE`（未建立）：另一 Server repo 在隔離測試中對照正式 SPEC 的測試，不是原版 Client 真機成功。
4. `ORIGINAL_CLIENT_COMPATIBILITY`（未建立）：經使用者另行授權後，實際原始 Client 與本地測試 Server 的連線/交互驗證；須報告啟動條件和結果，嚴禁擅自執行原版 Client。

**目前全部測試僅為第 1 類**。第 2–4 類是未來需要的證據／驗收類型，不代表已有工具或資料。

## Server 開發交付包（不包含實際 Server 程式碼）

B-CONTRACT 的工作交付須有：

- 協定 wire spec：frame、payload、方向、跨連線時序、欄位與 byte 邊界；
- Session/state spec：登入結果、失敗處理、角色清單、選角、scene handoff 的明確狀態，與未知處理；
- 契約樣例與測試：正向／負向、版本與來源證據；「Client 容忍未知 marker」等不能以合成測試決定；
- Server 專屬 ADR：帳號資料庫、帳密保存、session token、並發、port/host 配置等**自訂選擇**，不冒稱原版官方 Server 的實際實作；
- 一份 spec-only 實作者回饋：不看 `kr/evidence/` 或反組譯原稿能否理解接口。若不行，回填 GAP。

只把必要的契約傳給開發者；公開儲存庫不放實際帳號/憑證、個人資料、私人 Server dump 或商業資源全文。

## S00 每次開工／交付

1. 先核對 `main`、[RR 台帳](../research/requests/index.json) 與 [GAP 台帳](../design/gaps/index.json) 是否較上次變動。
2. 執行 `python -B governance/check_s00_readiness.py` 取得各工作包現在的阻塞與研究狀態；**程式的綠燈只代表文檔/索引機械一致性**。
3. 優先處理新收到的 `SUBMITTED` 報告與 T01 限定複驗。沒有新研究成果就繼續完成可編寫的 Server ADR 提案和測試設計，不重做已知的 BIN caller。
4. 提交新的有界 CLM、更新 SPEC/GAP/TEST，對未能證實的 wire 值保留 UNKNOWN。
5. 明確列出本次新增了多少真正可交付的契約、哪個 GAP 被限定證據解決，避免將「文檔增加」宣稱為 Server 可玩性提高。

## 仍需使用者明確授權的事項

- 原版 Client 執行、附加、網路抓包或對原版線上 Server 的互動；
- 產生或修改實際 Server 實作庫（本公開規格 repo 不擺正式 Server 程式）；
- 修改既有歷史原稿、變更其他 Task owner 與推翻 T01 原本的退回/全文驗收制度；
- 從內部研究請求制度轉為 GitHub Issues／外部公開提交管道。

完整階段 B 的研究仍須由 T02/T03 Agent **下次開工自行認領**，本規劃不會自動喚醒它們。
