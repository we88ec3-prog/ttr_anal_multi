# Tartaros Server 規格入口（Phase B 試行）

**目前 3 份 KR 規格均為 DRAFT / PARTIAL，尚無 STABLE，也不包含完整 TC 相容性。** 與 `shared/targets.json` 的 Client SHA 嚴格對應。第三方 Server 可以參考有限確定的形狀與條件，但不得將整個登入／選角流程視為已閉合。

| 規格 | 已萃取的局部內容 | 仍缺 |
|---|---|---|
| [SPEC-NET-0001](protocol/SPEC-NET-0001.md) | 1A68 / 0BBB framing、模式 fallback、局部收端 | 握手、模式、0x2633 與 socket 時序 |
| [SPEC-AUTH-0001](session-account/SPEC-AUTH-0001.md) | E8/0F 出站 payload、局部登入結果 | 認證政策、opaque 欄位、完整回覆與切線 |
| [SPEC-CHAR-0001](session-account/SPEC-CHAR-0001.md) | command2 65+53*N 清單與 UI record | 角色正式資料、選角回覆、初始化與轉場 |

[規格索引](spec-index.json) → [8 條 bounded CLM](../research/claims/index.json) → [3 份來源 SRC / SHA](../research/intake/index.json)。所有新主張為 PARTIAL，未升格 NATIVE_VERIFIED。[GAP](../design/gaps/index.json)、[研究請求](../research/requests/index.json)、[離線合成測試](../conformance/README.md) 可查詢未完成部分。

**測試資料是手工合成，不是擷取的原版遊戲封包。** Server 程式碼、DB、運行及部署留在獨立實作庫；S00 不強制特定語言或架構，未證的 Server 決策另立 ADR。外部 Issues 目前不受理。
