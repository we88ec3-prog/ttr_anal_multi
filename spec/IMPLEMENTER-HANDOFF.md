# S00 獨立 Server 實作者可用性審核（Spec-only handoff）

**DRAFT REVIEW WORKSHEET。不是 Server 產品驗收、原版 Client 動態測試或 T01 FULL-PASS。**

研究者的原始反組譯不能用來代替 SPEC：請讓獨立實作者只閱讀 `spec/`、`conformance/` 與**經正式批准**的 `ADR`；不要給他們 `kr/evidence/` 或歷史逆向草稿當作補齊封包的捷徑。

## 可以進行的審核

1. 依 [方向別封包矩陣](session-account/phase-b-message-matrix.md) 將 transport frame、payload command、會話狀態、角色清單、選角回覆與 Client 資源依賴分開。每個 S2C/C2S 必要欄位必須有明確版本、型別、位元組偏移及範圍。
2. 依 [覆蓋度矩陣](../conformance/contract-coverage.json) 逐項問：「這個具體位元組需要從哪個 Spec 得到？首筆訊息何時出現？失敗時怎麼辦？測試向量的來源是哪裡？」
3. 對任何 UNKNOWN 或 PARTIAL，**停在有界測試器／純協定解析器**，不得推定 Server 端已能與原版 Client 登入互通。規範性輸出不得引用未批准的 ADR。
4. 分別審查傳輸狀態、Client-compatible data shape 和 Server 自訂資料存取策略，不能把 Client 對本地欄位的消費方式延伸為官方 Server DB schema。
5. 使用 `python -B governance/check_contract_coverage.py --check` 做結構與來源一致性檢查；腳本即使 PASS，也**不是**原始 Client 互通測試。
6. 紀錄不足處交回 S00；只有與既有 GAP/RR 不重複的新問題才增建研究請求。禁止由回報者自行把 SPEC 升級成 STABLE。

## 每份可交付契約需要的資訊

| 問題 | 必填，不可推測 |
| --- | --- |
| Wire 身份 | KR/TC sha、方向、外框 marker / header、payload command 的精確關係 |
| 實際通路 | socket/slot、pipeline、frame mode、握手/Session 前提；區分 local buffer 與 TCP 實收 |
| Layout | 長度上下限、endian、欄位偏移、陣列次數與編碼（未證明值標 opaque） |
| Message flow | C2S 請求與實際 S2C handler 配對、成功/失敗分支與下一個狀態 |
| Error | malformed、分段/合包、checksum 等 Client 已證實/未證實行為分清楚 |
| Test origin | 合成資料 vs 原生來源-backed trace vs Server unit vs Client runtime |
| Backend policy | 私有 Server repo 的選擇與理由，不能冒稱原版 Server 的實作 |

## 回報範本

```text
Review ID: REVIEW-B-CONTRACT-...
Reviewed spec commit: <40-digit sha>
Client build + original SHA: kr / <sha>
Scoped message or state: <description>
What I can implement from spec alone: <bounded list>
What I cannot implement: <specific field, length, direction, or transition>
Expected vs observed (if test authorized): <without private data>
Evidence category: OFFLINE_SYNTHETIC | SOURCE_BACKED | SERVER_CONFORMANCE | ORIGINAL_CLIENT_COMPATIBILITY
Affected SPEC/GAP/RR: ...
Recommendation: retain DRAFT, draft new targeted RR only when not already covered
```

Current policy: only `OFFLINE_SYNTHETIC` evidence-backed *locally by handcrafted data*, and no complete login→selection exchange. **Do not claim an independent implementation review was actually performed just because this worksheet exists.**

Potential Server-only design proposals [ADR-0001..0003](../design/decisions/README.md) remain PROPOSED / NON-NORMATIVE. S00 roadmap and gap sources remain [here](../governance/S00-NEXT-PLAN.md).


## S00 Server 需求來源與候選（不代表發布契約）

Server 實作者可閱讀 [三種需求來源與分類](../governance/S00-SERVER-REQUIREMENT-SOURCES.md)、[SRQ 候選索引](server-requirements/index.json) 作**需求盤點**。CODE_ANALYSIS 來源能直接提出有界 Server_SEND / SERVER_RECEIVE 候選；RUNTIME_OBSERVATION 必須在另行授權下有實際記錄；USER_REQUEST 包括玩家／管理員功能及其提供的舊協定／歷史 Server 附件。來源是收件入口，不是必須同時具備的三份原生證據。SRQ CANDIDATE 不等於已核准 wire MUST、Client 相容性、原版 Server 業務政策或可直接實作的完成規格。
