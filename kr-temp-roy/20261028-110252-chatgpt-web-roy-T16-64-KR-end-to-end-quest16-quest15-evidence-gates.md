# T16-64 — KR 教學 Lua 與 Quest16／Quest15 原生權威閉環：現有證據與優先驗證序列

- 對象：**KR T16 only**，《星空幻想 Online》任務與劇情流程；分析日期 `20261028-110252`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 唯讀原件：`/mnt/data/Tartaros.bin`；大小 `12,472,320` bytes；本次 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `.text` 核驗 VA `0x00401000` / raw `0x400`，在本段地址使用 `raw = VA - 0x00400C00`；實際取 `Tartaros.bin` 機器碼，再由 GNU objdump `-m i386 -M intel` 靜態解碼，不執行客戶端。
- GitHub 先前基準為 main `ce87b59efc2712535d04f0cd212ebe0323df23d7`（查詢時），延續 T16-57～60；不改 catalog、owner、其他任務；**不檢查 TC**。
- 分級：`原生已確認` = 這次可核驗的位元組／直線組語；`部分確認` = caller 和 callee 意義尚有條件；`合理推測` = 待證；`資訊缺失` = 沒有原件證據。線性反組譯在跳轉／函式邊界外可能混入非程式位元組，不自稱完成 CFG。

## T16-61～63 精確結論整合（非重複新發現）

| 邊 | 本次已取得 bytes/CFG 事實 | 是否足以驗收 Quest16→Quest15 | 下一必需材料 |
|---|---|---|---|
| `TutorialMain` 腳本呼叫 API | T16-46 Lua 5.1 proto 6 有 `RequestStartScenario`, `IsScenarioEnded`；T16-61 native 參數轉 int | 否；未驗證實際 request ID | Lua proto6 數值常數與綁定之精確 caller |
| callback 進 native | `0x4AC9E0→0x4ACB70→call [ebp+8]`；`[0xFE187C]` 被讀取，型別不符傳 0 | 否；callback writer 未確認 | 全域 `0xFE187C` 初始化／寫入，以及 packet enqueue |
| quest condition 名稱 | `0x53FDB6` 起四個 slot 透過 `0x53FEB0` 寫入，child `0x72E2E0`, `0x7300A0`, `0x4A8680` | 否；屬 local node parsing | `0x4A8680` 資料語義與真正 quest state consumer |
| Quest 定義載入 | `0x504370→0x504740→0x505570` 同一 EDI pointer、B8 sentinel 初始化 | 否；目前無 15/16 欄位正文 | `QuestInfo.xml` 原文（SHA 下列） |
| scenario14 result / TUTO return | T14/T07 範圍；原始 server ACK 尚缺 | 否 | 原生伺服器／封包事件及合法結算 |
| Quest16 completed | 無角色 scope 的 writer/ACK | **否** | server writer + client notify + persisted field |
| Quest15 acceptable | 無原始 QuestInfo id15 欄位或權威判定 | **否** | quest prerequisite schema + server validation |
| reload/relogin | 無 T15 scope reader/store | **否** | 角色登入前後的原生 snapshot |

## 必須避免的反證錯誤

- `0x4ACB70` 返回 `EAX=0` 與 `0x4AC9E0` 返回 `EAX=1` 是 Lua/native wrapper return conventions，非「關卡失敗／成功」。
- `IsScenarioEnded` 只可代表 client 查詢某個結束狀態，不可推出關卡**勝利**或官方獎勵。
- `HasQuest` 字串與 `0x40` slot-object 是 XML/節點解析線索，不是持久化 Quest 資料庫結構。
- 原版 `005F type6` 與歷史修補版 tutorial patch 各自隔離；不自動修改／執行原 client。

## 續接大型研究優先順序（T16-65 起）

1. 從 BIN 追 `[0x00FE187C]` 所有 writer：定位實際 native callback 對應與可能的 scenario request queue。需保留完整 `mov/call` 指令邊界、函式 CFG、使用者及初始化時序。
2. 精確解析 `0x004A8680` 與 `0x0053FEB0` 的資料處理，區分解析器與任務狀態查詢的真實 consumer；不要把通用 key-value/node helper 寫成 Quest 狀態邏輯。
3. 優先取得真正 `QuestInfo.xml` id15/id16／`TutorialBase.lua` body，以 SHA256 驗證，對應 Lua 指令/原生 reader 的參數。
4. 跨 Task 僅引用 T14 scenario 結算、T07 scene return、T15 持久化與 T02 封包主責成果；不更改他人筆記或方法 owner。
5. 端到端驗收必須覆蓋 `scenario14合法完成 → 伺服器完成 Quest16 → 正式提供 Quest15 → 登出登入進度保持`，每條箭頭標原始來源/正反證。

## 此次分段總結與 Git 狀態

本次是 **KR BIN 原生 callback ABI／XML node consumer／reader 初始化** 三條互相獨立的深度研究；沒有取得 Quest15/16 server state 的閉合證據。本地 Markdown 完整原稿預計提交 `kr-temp-roy/`，由提交後遠端讀回核對，未完成前不聲稱 push 成功。不研究 TC、不修改原程式或 catalog/owner。

## 目前仍缺的原件（DEFERRED-LOCAL-RESOURCE）

| 來源 | 來源 SHA256 | 目前不足的內容及影響 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | 缺具體 function bodies，無法確證全教學回呼 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 尚無 Quest15、Quest16 元素原文及前置規則 |
| Quest16 server 狀態 writer／原生 ACK、角色持久化來源 | unknown | 不能證明 Quest16 已完成、Quest15 可接或重登續接 |

不可把 T01 的來源稽核、QuestTalk 缺少兩筆的局部切片、或歷史 fixture 視為上述缺口已解。

