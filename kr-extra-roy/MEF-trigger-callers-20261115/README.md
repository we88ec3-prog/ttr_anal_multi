# MEF 觸發 caller 證據包

對應主稿：[誰觸發 MEF](../20261115-001734-chatgpt-web-roy1-MEF-trigger-callers.md)。

**已證 Server 地圖流程可觸發 TRIGGER 名稱查詢；尚未證實新 `.mef` 的首次載入、執行 caller。** 本包將新補到的 UI／Lua／資源名稱 consumer 分開，保存可重驗的原件資料與陰性結論界線。

## 1. 分題入口

| 分題 | 這一輪新增的工作 | 主要文件 |
|---|---|---|
| root 別名與名稱用途 | `FB7470` 直接 literal 候選、指定保存值的後續；新名稱 consumer 閉合為 DamageSound | [native-root/report.md](native-root/report.md) |
| native 按名稱執行 Lua | 三種 execution wrapper 的 name／argument provenance、11 個零引數 callback caller | [named-calls/report.md](named-calls/report.md) |
| 動態路徑與 callback body | qbase 相機／地形 helper 的具體 native target；三個旗標 callback 的原件 body | [script-consumers/report.md](script-consumers/report.md) |
| 其他 parser 與 UI 入口 | `debug.debug` inline parser、require 模板來源、Synopsis 的兩條正常 UI 上游 | [alternate-entry/report.md](alternate-entry/report.md) |

主稿負責統合結論及 Server 開發要求；分題稿保留數值條件、資料流、復用範圍與未涵蓋的間接路徑。所有 native 位址均為固定 KR BIN 的 VA，不混用 raw offset 或其他 Client 版本。

## 2. 原件與版本

| 原件 | 大小 | SHA-256 |
|---|---:|---|
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `06-Event.stp` | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

工作分支 `extra/roy1`，parent `0a2503db089a4867cff5ef8bf6d7689333f12fd1`；main 參照固定 `e66dadaa721671919cbbeb228ae3f26ad990c9e3`。原件唯讀。PE32 i386 的 section 映射由原件 header 計算，沒有對未落盤的 BSS 位址杜撰 bytes。

完整 pin 見 [source-manifest.json](source-manifest.json)：119 個不同 commit/path 來源，包含舊報告與導航偽碼。統合時另以現有原始內容副本重核其中 117 個的 Git blob／SHA-256；其他來源保留分題組包時的內容身分。統一重驗器以 `git ls-tree` 核對 119 個 tree pins，不為了內容重驗觸發 partial clone 的缺失 blob 下載。原件結論以 BIN/STP 為主，這兩種來源核對範圍不混稱。

## 3. 本包數量與界線

| 資料組 | 原件 records | 記錄 bytes | 其他定向核對 |
|---|---:|---:|---|
| native-root | 213 | 9,494 | 155 個精確 root literal、120 個 containing functions；指定 E8、vtable 與保存值覆寫 |
| named-calls | 37（24 code、13 strings） | 3,258 | 4 個 target、17 個 E8 callsite；限定 E9／absolute pointer 集合 |
| script-consumers | 19（14 code、5 strings） | 1,814 | 3 個選定 members、7 個 qbase prototypes、root binding、14 個 call operands 與間接 binding |
| alternate-entry | 81（37 code、16 data、28 strings） | 7,752 | 11 個限定 targets、stdlib registration、2 組 RTTI、UI switch、import |
| **合計** | **350** | **22,318** | 刻意保留分題重疊窗口，不代表唯一 bytes 覆蓋率或完成百分比 |

`script-consumers/read-set.json` 另揭露本輪實際讀過的 1,843 個 scripts 加一份相機 member。該全 script 陰性先前 S00 已有，本輪只保留讀集／版本對照，**不列為新的全掃研究成果**。新內容證據是選定的 Lua operands、相機與地形 consumer，以及 callback bodies。

本包沒有提交原始 BIN／STP、完整解包 member、既有偽碼副本或 scratch 索引。`artifact-manifest.json` 記錄本包主稿、分題稿、證據、程式和 source manifest 的身分；它排除自己與稍後產生的驗證結果，避免循環 hash。

## 4. 唯讀重驗

在具有同版原件及固定 commits 的 repository 執行：

```sh
python -B kr-extra-roy/MEF-trigger-callers-20261115/verify_evidence.py \
  --originals /absolute/path/to/project_sources \
  --repo /absolute/path/to/ttr_anal_multi
```

統一程式會先檢查原件、包內檔案與固定資料 parser 的身分，再重算 named-call 的限定候選並呼叫同包三個分題驗證器。Lua／STPD 只作資料解析；原件只交 `objdump` 解碼。需要 Python 3、Git 和 `objdump`。

本輪實際命令使用：

```sh
python -B kr-extra-roy/MEF-trigger-callers-20261115/verify_evidence.py \
  --originals /workspace/scratch/b43c6175f310/project_sources \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

輸出保存在 [verification-result.json](verification-result.json)。結果 `PASS_BOUNDED_STATIC_EVIDENCE` 只表示固定資料、有限候選、明確 operand／slot 與來源 pins 一致；不是 whole-program 不可達證明，也不是遊玩驗收。

## 5. 交叉審查與修訂

兩項容易誤接的鏈有獨立原件複核：

- named-call 支線的 23 個原 code windows、13 字串、17 個 E8 callsite 及四個目標的限定 E9／literal 集合已交叉核對。審查後補入 `49B230..49B292` 完整 getter，讓 `CheckConfirmMessage` 的 wrapper 來源 `FDF3C8` 可在本包直接重驗；最終為 24 個 code windows。另把名稱參數寫成精確的 `[ebp+0x10]`，修正 protected-call 的 callback 方向。
- Synopsis UI 支線的 30 個相關 windows 及主要虛擬槽／switch 已交叉核對。保留 control 綁定成功與 current page 型態條件；`page+0x144==0` 只限制初始化入口，不加到 control event 入口；不替 control 700 或 `0x578` 猜可見操作名稱，也不把內部 event 改稱 wire opcode。

復用範圍也已統一：Boot／Logic／Coroutine／ai 和既有 TutorialMain 後續內容不是本輪新缺檔；前稿 loader、0047、review、bootstrap 等結果直接引用。這些修訂沒有改變原件或拓展驗收狀態。

## 6. 研究狀態

本輪回答目前能指認的名稱查詢觸發者，並補清其他真實 loader／executor 的來源。仍需新的正向資料流，才能把「新增 MEF 已交付」接成「原版 Client 首次載入並執行」。任意 computed alias、runtime 全域重綁、未取得外部模組等未被本包形式化排除。

Server 的既有事件排程、交付與遊戲規則需求可依主稿進行；未知 Client caller 不以自訂 opcode 或假設性 ACK 補上。沒有執行 Client、Lua、Server、封包試送或遊玩驗證；不提升 T01 FULL-PASS、RR ACCEPTED 或 MEF 整體完成狀態。
