# KR T16-68 — scenario 請求到 Quest16/Quest15 原生證據驗收與交接

- 研究日期：20261028-110904 Asia/Taipei；分析者 `chatgpt-web roy`；**僅 KR T16**。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。實際讀取 `/mnt/data/Tartaros.bin`（唯讀）；未啟動遊戲或呼叫任何原版 API。
- PE `.text` 有效映射：VA `0x00401000`, raw `0x400`；下列 `.text` 函式轉檔案位移使用 `raw = VA - 0x00400C00`，跨 section 必須重算。
- 證據術語：原生已確認=本次直接 BIN 原始位元組與逐指令反組譯；部分確認=指標來源／語意尚未對齊；unknown=缺少原始資料。

## 1. 跨段新進度與目前證據門檻

| 關係 | 原生證據 | 是否閉合 | 限制 |
|---|---|---|---|
| `0x4AB8B8` callback slot writer | `[FE187C]=0x4AA4D0` 靜態 direct `mov` | **local slot confirmed** | 初始化時序未驗證 |
| Lua bridge -> `0x4AA4D0` | `0x4AC9E0` 讀 slot、`0x4ACB70` 間接呼叫 | **partially confirmed** | 可能其他間接 writer |
| `0x4AA4D0` -> message | 4 bytes: `0x0040` tag + 16-bit value；`[FBA798]==0` 才呼叫 vtable `+0x10` | **local buffer confirmed** | socket/packet owner 尚未對應 |
| server accepts scenario request | 只有 local virtual call | unknown | T02/T07/T14 server evidence |
| scenario14 success -> Quest16 completed | 無 server writer/result | unknown | 不可視 Lua ended = victory |
| Quest16 -> Quest15 available | 缺 QuestInfo id15/16 原文 | unknown | 並非 id 數值遞減即前置 |
| relogin progress restored | 無 T15 role scoped snapshot | unknown | 不推定 checkpoint 等於 server state |

## 2. 可反駁的實測條件

1. 由 `0xFBA854` object vptr 確認具體 vtable `+0x10` callee；如果只是本地 queue，須繼續向 socket IO 追，不可就地結束。
2. 在下游 packet 分派或 T02 客戶端 receiver 證明 `0x0040` 真正 domain；如沒有，保留「4-byte message type 0x40」而不直接叫 ScenarioStart。
3. 取得 `QuestInfo.xml` id15、id16 原始 XML elements 與 SHA，核對 schema prerequisites；避免以 `QuestTalk` 開頭缺 15/16 推論任務不存在。
4. 取得 `TutorialBase.lua` 確定 setup／callback；Lua `IsScenarioEnded` 不代表 T14 server result success。
5. 對 T15 持久化 reader／T07 回 TUTO／T14 official reward 只記介面需求，不修改其主責、方法或分析原稿。

## 3. DEFERRED-LOCAL-RESOURCE

| 檔案／來源 | SHA | 所缺內容 | 阻塞 |
|---|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | Lua 函式 bodies/opcode | 教學 trigger/end callback |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | Quest15/16 原始元素 | 官方前置依賴 |
| KR server Quest writer / ACK | unknown | actual serializer, persist writer | 完成後通知 |
| T15 role scoped quest snapshot | unknown | login/logout read/write | 重登恢復 |

## 4. 下次優先序

- 不再重掃同一 callback slot；直接追 `0xFBA854` 的 vtable `+0x10`，連接封包狀態更新 / T02 分派。
- 如果無法取得完整網路鏈，改用本地可驗證的 `QuestInfo.xml` 原件或更深的 client quest-state consumer CFG；保留未知而不偽造完成。
- Git：只允許追加 `kr-temp-roy/` 本輪四份完整原稿，不更改其他 Task／catalog／owner；提交後必須 read-back SHA。
