# S00：任務前置集合發布編碼候選

接續 REQ-0017、ADR-0007 與 [T16 收件](S00-20261101-T16-QUEST-SETTLEMENT-INTAKE.md)。
本輪將已有的有限接收布局轉成私有 Server 編碼器；沒有增加原生分析主張、CLM、
GAME_RUNTIME_OBSERVATION 或正式核准。這是未接線的實作準備，不是完成任務的替代品。

## 來源與布局

沿用 [完整 bitmap 分析](S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md) 的目標 SHA、
502170／44AB70／44AA10 保存偽碼 SHA，以及 T16 收件的 503400／44B4E0 限定用途。
沒有重跑遊戲或改 Client，也未取得官服流量。

- `006F`：2-byte opcode 後接 little-endian DWORD bitmap，沒有額外 count；
  第 n 個 DWORD 的第 b bit 代表 WORD key `n*32+b`。接收先清原集合。
- `0074`：2-byte opcode 後接 WORD key，追加單一 prerequisite。
- prerequisite 集合的發布不能決定接取、完成、獎勵或教學 terminal。尤其不能將
  Scenario14 勝利、最後 3F 或廣場初始化直接當成 14／16 合法完成。

## 私有 Server 實作界線

`KrQuestPrerequisiteCandidateProtocol` 分開完整 snapshot 與單 key addition API。
snapshot 先複製呼叫者提供的集合，再依最高 key 配置 bitmap 並設定 bits；輸入必須是同一
owner／已提交版本的完整集合。方法本身沒有資料庫權威、交易、角色作用域或結算權限。
呼叫者仍須由未完成的結算／發布服務提供正確集合；目前沒有任何 live adapter 呼叫。
空集合編碼會清 Client 狀態，因此不可拿來當缺資料時的預設回覆。

正流程合成案例使用明確例向量：`{14,16}` → `6f0000400100`；加上 key40 後完整
snapshot 為 `6f000040010000010000`，addition 為 `74002800`。接收規則獨立解碼後仍保留
14／16／40，避免把 delta 誤當 full snapshot。這些是假設已提交集合的測資，不是目前
測試帳號的完成狀態。新增一個 HappyPath 案例，全體 17 個通過；未執行邊界／錯誤／
重送／重登／併發／故障等暫緩案例。未因此宣稱 Client 相容或正式 conformance 通過。

## 仍待完成

QPLAN-PUBLISH 只多了編碼器，仍非完成：合法 Quest14／16 轉移、資料庫保存、獎勵類型、
owner／版本與提交後發布、實際 UI／廣場驗收均未補齊。沒有向遊戲發送 6F／74，沒有改
schema／獎勵／完成旗標，沒有換版。既有 v7 人工結果卡繼續有效，完整目標仍未達成。
