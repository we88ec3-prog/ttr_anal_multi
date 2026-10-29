# T10 REBASE-01 — 整合證據基準與輸入狀態／命令 0x68 BIN-first 定向驗證

- 記錄時間：2026-10-28T01:24:22+08:00
- 研究標的：KR Tartaros.bin，純靜態只讀分析；無遊戲執行、無 Hook、無修改。
- repo：we88ec3-prog/ttr_anal_multi；已經從 GitHub connector 讀取正式 T10/T11、AGENTS、HANDOFF 和 T01-20261027-05 的 README / accepted-claims / resolutions / pending；近期 commit 列表首項 `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`，**未透過分支 ref API 證實就是 main HEAD**；不以此宣稱 HEAD 完成校準。
- GitHub 無寫入；本筆記為本機新成果。既有 1–44 原稿尚未全部逐份讀回比對，不宣稱已完成全量 rebase。

## 來源與 PE 映射

- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- 原始 BIN PE header 由 GNU objdump 實際讀出：.text VA=0x401000 raw=0x400，.rdata VA=0xBD2000 raw=0x7D0600，.data VA=0xD61000 raw=0x95E800；下述 VA 全在 BIN .text。注意 T08 過去 PE/flat 映射差異需對每個來源核實；此處以原始 PE section header + objdump 直接證據。
- `0x547240` raw：`0x547240 - 0x401000 + 0x400 = 0x146640`。
- `0x548918` raw `0x548918 - 0x401000 + 0x400 = 0x147D18`。

## 整合後可採信範圍

| 議題 | 現階段分類 | 精確限制 |
|---|---|---|
| `0x547240` 狀態機與 `>500ms` | 本段 BIN 局部分支確認 | 僅時間差比較；不等於普攻 combo / cancel window |
| `0x548918` `28..37` | 本段 BIN 控制流確認 | 為特殊命令索引迴圈；不等於十段連擊 |
| 自訂 Z/X/C/V | 玩家行為觀察、尚缺直接映射鏈 | Z 只是預設，不可硬映為 VK_Z |
| 一般/擴展鍵 phase 1/3 | T01 限定原稿 | 不稱 keydown/keyup，尚缺非零 writer |
| 3 路輸入 OR 與 byte 優先選擇 | T01 限定原稿 | 不可合併成一種語義 |
| controller index 5 / SubAI >60 | T01 有界來源線索 | 不等於玩家 V 或蓄氣秒數 |
| actor +0x3E8, skill predicate `0x54F270` | 33–44 交接線索 | 同 offset 不同類型須分；predicate 非 cast/cancel writer |
| 普攻連段、動畫完成、動作排隊 | 缺口 | 不可套用自製 `CHAIN_WINDOW=0.65` |

## 原始 bytes 證據 A：0x547240

`esi` 指向至少兩個 DWORD 的狀態記錄（本段僅推論欄位佈局，未證明類別所有權）。`[esi]` 為狀態 0–3 dispatch，`[esi+4]` 保存 timeGetTime 返回的 tick，global byte `[0xFB9014]` 被讀取。`[0xBD25A0]` 是 IAT 間接呼叫，歷史來源標記 timeGetTime；尚需從 PE imports 獨立確認符號。

- 0x5472A7/0x5472B5：若讀到 byte 1 或 2，呼叫 IAT，將 EAX 寫入 `[esi+4]`，`[esi]=2`，返回 1。
- 0x5472F6 起：byte 既不是 3、也不是 0 時，取新 tick 減去 `[esi+4]`；在 `cmp eax,0x1F4` 之後採用 **`jbe`**，意味著只有無符號差值嚴格大於 500 才走狀態 3、返回 3 的路徑。
- 另一條 phase/狀態路徑將 `[esi]` 與 `[esi+4]` 清零並返回 2 或 4；**未證其對應 V 的點放/長按，亦未證定時輪詢頻率**。
- 完整函式的跳表四個入口尚需要以 .text data 及函式入口邊界交叉確認；不能依本段推測全函式完整 CFG。

[code block separately checked in preflight]

## 原始 bytes 證據 B：0x548918

- 0x548918 `xor ebx,ebx`，0x54891A `lea esi,[ebx+0x1c]`；迴圈 0x548952 上限比較 `esi,0x27` 並在 0x5489B0 比較 `esi,0x26` 循環，實際處理 index **28,29,...,37**（10 筆）；index38 跳出。
- 0x548957 從 `[esi+0xFB9004]` 讀 phase byte，0x54895E 僅接受值 1；此為 *consumer*，**不是非零 phase producer**。
- 0x548985 將 WORD `0x68` 寫 stack 命令結構 `[esp+0x14]`；0x548992 設事件 byte 1；若 `[0xFBA798]==0`，以 `[0xFBA854]` 指向物件的 virtual+0x10 送出（參數順序為 push 3 / ptr / 0，實際 ABI 及接收端需驗）。
- 0x5489C1 後另有 WORD 7 與先前 stack byte 分支；這不是把 0x68 直接命名普通攻擊或技能。
- 本段顯示 `0xFB9004 + index` 參與命令候選；仍需沿 writer → controller → actor 實例鏈確認是否是玩家自訂按鍵所生的 state。

[code block separately checked in preflight]

## 最小資料流及未閉合上下游

1. 尚缺 `KeyMapping.xml` 真正 action row、fallback 與載入函式到玩家輸入 state 的實參鏈。
2. `FB9004+index` phase **reader** 已有原始 bytes；要找寫入非零值的 writer（含間接寫、memcpy、物件換 bank）及鍵位釋放時的改寫。
3. `0x547240` state/tick consumer 跟 index 28–37 間尚未證同一 action；不用 500ms 推 V 蓄氣或 Z 續段。
4. `0x548918` 送 command 0x68 至 virtual+0x10 的 receiver 實體尚未證 actor cast/attack 的目的地，須辨認 packet dispatch 與 motion queue owner。
5. 待證普攻續段觸發為 Z 重按或 Z held、技能互銜接 queue/cancel 與 motion completion 回報；不得假設固定取消窗口。

## 新段號策略與後續

- 使用 `T10-REBASE-01` 獨立標記整合基準後的新研究，避免將未完成重核誤記為舊 T10-45；舊 1–44 不改寫。
- 待逐一讀回 `kr-temp-roy` 舊原稿與 `source-review-status.json`，依來源 SHA 連結相應 accepted-claims / resolutions 才能完成全量 rebase 矩陣。
- 先從 input nonzero writer 與 command 0x68 receiver 追到 controller、actor/action transition；完成之後再調整研究優先順序至 V tap/held 與連段排隊。

## 版本與權限

本筆記只建立本機副本；沒有 Commit、Push、改 owner、改 catalog、修改其他 Task。正式 main HEAD 與 1–44 全量核對仍待補證。