# S00 Iteration 19 — 新帳號到新手教學完成：跨模組整合與驗收閉環

日期：2026-10-31（Asia/Taipei）。**S00 設計草案；非正式 SPEC、RR、REQ、GAP、TEST，也非原版 Client 已可遊玩證明。**

## 1. 基準、權威與邊界

- 規格主庫：`we88ec3-prog/ttr_anal_multi`；本輪基準 main `3888decfc2f22d4b23aaad949696ec3df5f9a2d5`。
- 前置規劃：`governance/s00-iterations/` 的 Iteration 16（E00–E12）、17（E13–E26）、18（E17-A～J）。
- Server 開發銜接：`we88ec3-prog/ttr_server_roy/docs/S00-TUTORIAL-COMBAT-IMPLEMENTATION-PLAN.md`，其 C05-A～J 是獨立實作構想；**不是**上游正式批准的 Client protocol。
- KR Tartaros.bin SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（沿用既有記錄；本次未重新讀取二進位）。TC 不共用 KR opcode。
- 原版 Client 的啟動、附加、網路連線及封包擷取未授權；不得用合成測試替代。
- 權威台帳仍為 `research/requests/index.json`、`design/requirements/index.json`、`design/gaps/index.json`、`spec/spec-index.json` 與 `conformance/test-index.json`；本輪不自建重複台帳、不自動升級狀態。

## 2. 產品級完整旅程與停止條件

| 階段 | 邊界與最小輸入 | 可觀察的驗收結果 | 尚需閉合的重點 |
|---|---|---|---|
| A：連線/登入 | 匹配 KR 版本的 frame、連線、帳號/Session | 明確的登入成功或失敗，避免跨連線身分混淆 | T02/T03 正向 wire 配對與錯誤路徑 |
| B：新帳號/角色 | 經授權的帳號、角色清單、零角色 UI、創角 | 新帳號能合法建立並持久化第一個角色；重送不重複建立 | T03/T04/T06 創角 producer/consumer、UI readiness |
| C：選角/進場 | 選定角色、合法 world/scene 遷移 | Client 顯示正確角色，實際進入新手教學準備畫面 | T03/T05/T07/T16 scene owner 與初始化 |
| D：教學戰鬥 | Scenario/Scene/Encounter namespace 分立，E17-A～J | 敵人出現、AI/玩家動作、技能及傷害可判定，無重放/假勝利 | T08/T09/T10/T11/T12/T13/T14；T02 transport |
| E：教程結算 | 合法 objective proof、encounter settlement | Scenario 結束一次，Quest14 獨立完成，Quest16 可用性正確 | T14/T16/T07 正向鏈與例外 |
| F：教學離場與重登 | 正確的出口場景與持久化進度 | 進入非教程可操作場景；斷線、重登後狀態不倒退/重領 | T15/T16；Server owner/persistence ADR |

上述是**驗收目標**，不表示 native wire 時序已被證明。任何一個必需階段只具 Client handler、UI animation、resource hint 或 synthetic fixture，都只能標示「部分已設計／待驗證」，不得稱整條流程完成。

## 3. 跨模組契約移交：每個 gate 必填的驗收包

每個步驟必須用同一欄位骨架交接，不要求發明未證數值：

1. `Gate ID`（沿用 E00–E26 或 E17-A～J）、前後狀態、角色／帳號／Connection／Scene Instance 所有權。
2. `Client version + source SHA`、native producer/consumer（具體函式位址/資源來源）、方向（LOCAL/C2S/S2C）、byte/frame 範圍與失敗條件；未知填 `UNKNOWN`。
3. `Upstream REQ/RR/GAP/SPEC/CLM/TEST` 的**真實**既有 ID；若無則 `UNREGISTERED / REVIEW_REQUIRED`，不得偽造 ID。
4. Server domain action、狀態轉移、責任模組、重入／併發／拒絕策略（標成 `SERVER_POLICY_PROPOSED`，直到 ADR 批准）。
5. 正向、反向、重放、跨角色、斷線、崩潰恢復各種情境；測試級別和執行證據分開列。
6. 下游可觀察 Client 結果與補證 owner；只證 handler 不算 E2E proof。

## 4. 最小 E2E 因果契約與同步邊界

```text
Network/Session (C01/C02) 
  -> Account + Roster + Create (C02/C03)
  -> Select + Scene Admission (C03/C04)
  -> Tutorial Encounter (C05-A)
  -> Spawn Registry (C05-B)
  -> Actor Authority + Motion (C05-C/D)
  -> Basic/Skill Intent Ledger (C05-E)
  -> Combat Result (C05-F)
  -> Objective + Encounter Settlement (C05-G)
  -> Quest Turn-in + Tutorial Exit (C04/C05-H)
  -> Login/Resume consistency (C02/C05-H)
```

每段只傳明確版本化的 domain event / correlation ID；**這不是官方封包順序**。角色擁有權、scene instance 及會話世代（connection generation）要在入口重驗。舊連線不可寫入新會話，跨場敵人/技能不可操作；重送同一 Action/Result/Settlement 不得雙扣 HP、雙生成或雙發獎勵。未知原生 owner、Skill ID、Spawn Plan、Quest condition 不得藉由自訂 fixture 隱形補值。

## 5. 四級驗收，不可混淆

| 層 | 可聲稱的成果 | 禁止的推論 |
|---|---|---|
| `DESIGN_ONLY` | 文件依賴、接口與待驗證情境完整 | 不算測試已執行 |
| `SYNTHETIC_DOMAIN` | 自造假資料在 Server 單元/整合測試符合本地策略 | 不代表 Client 可讀官方 packet |
| `NATIVE_STATIC_BOUND` | 指定 KR SHA 下具正向 native producer/consumer 與可重現範圍 | 只證局部 Client 靜態行為，不代表實際跑通 |
| `ORIGINAL_CLIENT_E2E` | 需單獨授權、隔離環境、版本/連線/測試紀錄，從新帳號走到離場及重登 | 未執行前一律 `NOT_RUN` |

如果缺少 wire producer/consumer/scene prerequisite，該 gate 保持 `BLOCKED`；不能僅因 synthetic 測試通過而升為兼容。

## 6. Iteration 19 的四項交付包（全部是本輪規劃，不是已執行）

- **I19-P1 新手 E2E Gate Trace**：建立 E00–E26 與 E17-A～J 的依賴/證據映射；以現有台帳查證，列出精確 blocker，不修改正式 ID 或狀態。前提：現有 Iteration 16–18 正式歸檔已存在。
- **I19-P2 戰鬥最小閉環**：挑一個合法 tutorial player action、至少一個有來源證明的 enemy spawn、monster response、damage/death、objective result，建立 direction-specific 最小 native proof；若任何一環缺乏來源，只能是 synthetic target。先詢問 T08/T11/T12/T13/T14 原有結果，避免新建重複 RR。
- **I19-P3 角色到教學交接**：以 roster→creation→selection→scene init→Scenario14 admission 驗證角色所有權和 UI-ready；與 T03 RR-0002 / RR-0008 等既有研究去重。
- **I19-P4 持久化與恢復**：定義 encounter settlement 和 Quest turn-in 不同 transaction、併發 fencing、crash-after-commit、斷線重登的負向測試；屬 Server 自訂政策先提 ADR，不能稱原版行為。

### 建議的研究追蹤順序

1. 優先關閉 E00–E16 中會阻止角色進教學的關鍵鏈，再做 E17 局部驗收。
2. E17 先確認 enemy spawn、玩家技能與戰鬥結果的**同場景正向因果**，而非先猜數值、波次與 cooldown。
3. T13/T02 的 AI/owner 模型採 **UNKNOWN→來源證據→ADR 選擇** 路徑，禁止預設原版為完全 Server-authoritative。
4. 只有正向結果與 Quest 完成/解鎖/離場各自有證據，才逐步串 E18–E26。
5. Server repo 先做 synthetic domain 實作測試；獨立向上游提交 `FB` 關於缺失契約，不自動調整 upstream SPEC pin。

## 7. 候選測試情境（均 PLANNED / NOT_RUN）

- `I19-T01` 空帳號登入至零角色畫面：清單 UI 可用，無偽造角色。
- `I19-T02` 創角重送及斷線：至多一個角色，重新登入一致。
- `I19-T03` 選角至 Scenario 入場：角色、場景、instance 映射一致。
- `I19-T04` 同一 spawn key 重送：不產生重複敵人；無來源 spawn plan 不宣稱 Client 已顯示。
- `I19-T05` AI controller/owner 切換：不重複攻擊、不接受舊 lease。
- `I19-T06` 一次普通攻擊及技能：合法接受/拒絕/取消與資源計費一致。
- `I19-T07` 傷害/死亡重放：不重複扣血、不接受死者行動。
- `I19-T08` 目標未完成或生成配置缺失：不可產生勝利。
- `I19-T09` Scenario settlement/Quest14 turn-in/Quest16 解鎖三者分離，重登不重領。
- `I19-T10` 中途斷線、退出教學、重登：正確 resume 或明確阻止，無跨角色污染。
- `I19-T11` 未知 KR command/未證 frame：native adapter fail closed。
- `I19-T12` 真 KR Client 完整 E2E：**NOT_RUN / NEEDS_EXPLICIT_AUTHORIZATION**。

## 8. 本輪無法宣稱完成的部分

- 新建正式 RR：**沒有**；候選研究問題須由 S00 在既有研究佇列去重後正式派工。
- 新建正式 REQ/GAP/SPEC/TEST 或升級其驗證狀態：**沒有**。
- 新 BIN-first 逆向、正式 T01 FULL-PASS、Client runtime：**沒有**。
- Server code 修改、CI 執行、正式 Client↔Server 互通：**沒有**。

## 9. 下一輪建議

Iteration 20 應做 **逐 gate 現有證據映射與正式 RR 去重審核**，從登入/角色 UI、創角、選角到 Scene/Scenario 認領，再對 E17-B/F/G/H 開 native proof 清單。只有確認原有 RR 未覆蓋且符合正式工作流，才補發研究需求；不要把本次候選規劃直接當已接受需求。
