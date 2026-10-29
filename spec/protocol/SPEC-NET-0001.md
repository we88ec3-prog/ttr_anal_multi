# SPEC-NET-0001 — KR Network framing (draft pilot)

**狀態：DRAFT / UNKNOWN；非正式協定實作指南。**

- Client: KR；Tartaros.bin SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Source owner: T02；可查 `kr/tasks/T02/README.md` 與現有原始分析。
- **目前已確認可發布的完整 framing 契約：尚未建立。** 不填寫猜測長度、opcode、欄位、登入時序。
- 輸入（C2S）：待查 frame 結構及 mode；輸出（S2C）：待查 frame 結構/長度/順序。
- Server 行為：先作需求盤點；不得將一般 TCP 假設冒稱 Client 已證實。
- 相關缺口：`GAP-NET-0001`；補證請求：`RR-0001`；目前通過的 TEST：無。
- 升級條件：列出足以供第三方實作的精確接收/傳送規則、出錯時的處理、來源條件及對應測試。機械性 SHA/指令 byte 核對不能代替必要語意驗證。

此頁僅為流程示例，不取代 T02 現有局部已確認的事實，也不代表已完成其整合。
