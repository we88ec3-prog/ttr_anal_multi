# MEF 入口、生命週期、事件與身分：原件證據包

[主報告](../20261114-192949-chatgpt-web-roy1-MEF-entry-lifecycle-events.md) 整合本輪開發判斷、已證能力、Client 待逆向與 Server 開發需求。分支為既有 `extra/roy1`，本輪只新增 `kr-extra-roy` 研究稿；沒有修改原版 Client、Lua 或 STP。

本包的目標是判斷哪些工作可以交由 Client 腳本接手，以及缺少的實際入口／事件／身分契約。它沒有以 Server 自有 JSON 已能編排內容取代 Client 接手驗收，也沒有以取得官方 `.mef` 原件作為必要前置。

## 閱讀順序

| 原稿 | 內容 |
|---|---|
| [entry.md](entry.md) | 0047 前端虛擬分派、雙鍵 selector、SceneList 生命週期、開機固定 Lua、review UI 與 ID 域 |
| [lifecycle.md](lifecycle.md) | 普通場景的共用 Q pump、Tutorial tco、父子任務、停止／離場與 context 限制 |
| [events.md](events.md) | EntityId 到 CDeadState、診斷與 getter 排除、Tutorial 互動 writer→Lua→動作及物件佈局 |
| [identity.md](identity.md) | lb 建立物件的真正回傳契約、數值參數、世界 ID consumer 與本地計數器界線 |
| [controller-input.md](controller-input.md) | Q 的 controller+58 writer、三種控制器 consumer、移動／動作 word 清零與既有 000A 輸出界線 |

入口與 lifecycle 已互相核對場景型別、有效 controller 前置、0038 的局部偏序；identity 的 CreateObjectEx 回傳／attach 參數，以及 events 的 getter／旗標 reader／controller 佈局另有跨題原件複核。這些複核不變更 T01／S00 的正式驗收狀態。

## 證據檔案

| 檔案 | 用途與界線 |
|---|---|
| [native-windows.json](native-windows.json)／[native-windows.asm](native-windows.asm) | 合併各題原件視窗；每筆有 group、source_id、VA、raw、長度、bytes、SHA-256。重疊視窗保留，不把 byte 總數當完整度百分比。 |
| [native-relations.json](native-relations.json) | 選定 call、RTTI、vtable slots 與零初始化虛擬尾區；不是完整 call graph。 |
| [upstream-xrefs.json](upstream-xrefs.json) | 12 個指定入口目標的 E8／literal 候選；候選須配原件窗口，不含所有間接呼叫。 |
| [death-targeted-call-candidates.json](death-targeted-call-candidates.json) | 三個事件分題目標的直接 call 候選，空列表不等於函式不可達。 |
| [lb-bindings.json](lb-bindings.json) | 有界的 14 個原生 lb 註冊器、名稱、callback slot、target 與 wrapper；不是所有 runtime Lua globals 的封閉集合。 |
| [local-counter-literal-refs.json](local-counter-literal-refs.json) | 單一 F7DE04 的 `.text` 絕對 operand 範圍，排除計算 alias；不能據此保證跨圖重設或多人 ID 一致。 |
| [selected-entry-resources.json](selected-entry-resources.json) | 七個指定原資源：SceneList／MapList／CaseList 選定列與四份 sequence 的選定行，包含載體與成員 hash。 |
| [lua-prototypes-evidence.json](lua-prototypes-evidence.json) | 三個原始 Lua chunk 的來源與 19 個引用 prototype；完整指令字、常數、結構及解碼位置。 |
| [tutorial-script-evidence.json](tutorial-script-evidence.json) | Tutorial native 事件的實際 Lua consumer 片段；PC 從 0 起算，保存原件／還原 bytes 與常數。 |
| [source-manifest.json](source-manifest.json) | 原件身分、最新 main 查核基準、工作 parent、固定 Git source blobs 與各資料的角色。 |
| [verify_evidence.py](verify_evidence.py)／[verification-result.json](verification-result.json) | 統一唯讀重驗器與本輪結果；不執行 Client 或 Lua。 |

原件完整 SHA-256：

- BIN：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- Event.stp：`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- Table.stp：`09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。

## 重驗

在 repository 根目錄，以 Python 3 執行以下命令。三個原件路徑由持有人提供，原件不包含在本證據包。

```bash
python kr-extra-roy/MEF-entry-lifecycle-events-20261114/verify_evidence.py \
  --bin /path/to/originals/02-Tartaros.bin \
  --event-stp /path/to/originals/06-Event.stp \
  --table-stp /path/to/originals/07-Table.stp \
  --repo /path/to/ttr_anal_multi \
  --out /path/to/scratch/verification-result.json
```

重驗器復用同 repository 中前稿的 `MEF-parser-executor-storage-20261114/verify_evidence.py`，先核其 SHA-256 為 `8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56`，再使用其中的 PE、STPD 與 Lua chunk **資料解析**函式。它不呼叫該腳本的舊 `main()`，也不執行所讀 Lua。

`--repo` 要求 Git object database 內有 manifest 宣告的來源 commit／blob；使用它可核每個 commit/path/blob 身分，並比對三份先前完整 Lua 解碼。省略時仍核原件與本包選定資料，輸出會明列未進行完整 repository source 核對。本次保存的結果包含 `--repo` 核對。

輸出路徑不得覆蓋原件或其他證據輸入。不提供 `--out` 時只印 JSON 結果。驗證成功僅表示來源、記錄 bytes、有限候選範圍與選定資料一致；不表示不存在其他原生路徑，不表示原生 `.mef` 格式已知，也不是 T01 FULL-PASS、S00 ACCEPTED 或遊玩驗收。
