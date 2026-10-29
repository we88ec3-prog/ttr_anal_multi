# T01 — Source intake record template (SRC-*)

- `id`: SRC-0001（必須唯一）
- `client_version`: kr / tc（不可跨版本繼承位址）
- `target_sha256`: 對應 `shared/targets.json` 的原始檔 hash
- `source_file`: 原稿的 Repo 相對路徑
- `source_blob_sha`: 該檔的 Git blob SHA-1；不能以 commit SHA 取代
- `source_sha256`: 該來源檔內容 SHA256
- `integration_status`: REGISTERED / CLAIMS_EXTRACTED / CONFLICT_CHECKED / SPEC_CONSUMABLE
- `claim_ids`: 明確 bounded 主張 ID，沒有主張不可升至 CLAIMS_EXTRACTED
- `conflict_disposition`: 對照矛盾與版本修正後的結論，不能無理由留空後標 SPEC_CONSUMABLE
- `original_document_review_status`: 從既有台帳引用歷史狀態，不得覆寫；可包含原台帳連結。

T01 不從原稿路徑或短段號自動推導主張、也不依「來源 SHA 一致」宣告語意通過。後續來源修正版使用新的 SRC/來源 blob SHA，舊版保持原狀。
