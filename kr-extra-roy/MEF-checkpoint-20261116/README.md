# MEF R12 原生互動點能力證據包

本次工作以**MEF 可以做到哪些事**為研究目標，接續 [R11 能力手冊](../20261116-113220-chatgpt-web-roy1-MEF-capabilities.md)，不要求普通戰鬥由 MEF 完全取代 Server。補到完整正向流：Server `0027` 安裝集合、Server `0048`／Lua `SetCheckPointStatus` 更新同一點、Client 距離及類別消費、特定 `001C` C2S fallback。

- [完整繁中研究主稿](../20261116-MEF-checkpoint-lifecycle.md)：原件地址／資料流／欄位表／實際能力及 Server 分工
- [Server 開發需求](server-handoff.md)：可據以實作的整合規格與驗收
- [JSON 版 Application 契約](checkpoint-contract.json)：0027／0048／001C、typed identity 與適用限制
- [25 組原件證據錨點](evidence.json)：BIN VA/raw/hex，沒有上傳完整 BIN／EXE／STP
- [唯讀驗證程式](verify_evidence.py)、[實際核對記錄](verification-result.json)

重跑：`python -B verify_evidence.py --bin /path/to/Tartaros.bin --evidence evidence.json`；要求原始 KR BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。結果只代表限定的機器碼與欄位一致性，不是全程式覆蓋、T01 FULL-PASS、Client／Server 執行、遊玩或新 MEF 格式可用性驗收。

分支 `extra/roy1`；開工時 `main=03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已是 `f8f2c8bdbb984a7571e7bd7591941f1ddda08889` 的祖先。未建立 branch、未修改 Client／Server／正式 Task／RR。原版 `MapList.TRIGGER` 的 MEF 首次讀檔與 grammar 尚未閉合，不能把互動點更新 opcode 當 MEF 傳檔命令。
