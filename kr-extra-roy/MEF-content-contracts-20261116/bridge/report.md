# 新 `.mef` 串接的雙 VM 內容與資源契約

日期：2026-11-16（Asia/Taipei）。本輪開始：02:41:01。

本子題以原件 `02-Tartaros.bin`（SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）為裁決。反編譯導航固定於 `main@03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；沿用分析固定於本輪父提交 `88b22bcd750ea219bfc56580139396d0ee677644`。沒有執行 Client、Lua 或新內容，也沒有修改原件。

## 1. 本輪閉合的鏈與結論

前輪已知道正常 Q scene 先在預掃描 VM 執行 `.seq`，再於正式 VM 載入；`DoFile` 能將另一個可解析的內容檔載入目前 Lua state。本輪補上的問題是：**若 `.seq` 只留下 `DoFile(new.mef)`，原本的預掃描究竟會漏掉什麼？**

已沿原件接出：

> 全域 `CreateObject/AniObject/WalkObject/WarpObject` 的預掃描 callback → 以 low WORD 槽號建立模型／動作集合 → 正常 Q 啟動建立模型工作並等待 → 模型 catalog 的資源欄位 → 正式 `Q.CreateObject` 用槽號取回動作集合 → 模型動作表 → 具體 `IS3D::CMotion` → 動畫資源請求與 receiver 登記。

這已足以制定「新增 `.seq` bridge + 可由已知 Lua loader 解析的新增 `.mef` 模組」的依賴產生規則。**這仍是有條件的新內容整合設計；沒有證明原版 `.mef` 的第一個 caller，也不是還原官方 `.mef` 專屬語法。** 名稱／副檔名不會自動使檔案被發現或執行。

實作時須把有限、可完成的預掃描宣告與正式 coroutine 行為分開產生，並保持兩者使用相同模型與動作依賴。不能把預掃描 callback 的返回、模型工作 event 或 `DoFile` 的狀態值當成「這次 `.mef` 已完成遊戲操作」的 ACK。

完整原件位址、raw offset、bytes、反組譯與 SHA-256 在 [native-windows.json](native-windows.json)；45 個語意錨點及 29 條直接呼叫在 [contracts.json](contracts.json)。本報告的「證實」限於這些選定鏈與已固定的前輪證據。

## 2. 先釐清兩種執行階段

沿用的 loader／VM 基礎見 [parser／executor 報告](../../MEF-complete-flow-20261115/parser-executor/report.md) 與 [VM lifetime](../../MEF-runtime-contracts-20261115/vm-lifetime/report.md)。本輪再次核實 `55D6A0` 的實際 reset／callback／load 順序。

| 項目 | 預掃描 | 正式 Q scene |
|---|---|---|
| owner | `P = FE1EEC`；其 Lua VM 與正式 VM 分離 | Q owner `M`，正式 wrapper／Lua state |
| `.seq` 行為 | `55D6A0 → 6F4A50`；`Register` callback `55D560` 立即 protected-call scene | 正式 `Register` 使用既有 qbase／qco 路徑登記 coroutine |
| 本輪觀察的 Create／Ani／Walk／Warp | 全域 C callback，只收集資源 | 正式全域包裝與 `Q.*` native 操作演出物件 |
| 清理範圍 | 每次 `55D6A0` 清 native collector 與 music 字串 | 依 Q 的建立／End／清理流程 |
| VM 狀態 | native collector 清空不等於重新建立 Lua VM；globals 可能跨次留存 | 共用 state／模組 exports 也須處理舊值 |
| 是否保證 callback 失敗中止整條啟動 | 否；`55D6A0` 在 loader 後直接回傳 `P+8`，未把 loader 狀態傳成 gate | 仍須依正式 loader、coroutine 與明確終止契約判讀 |

`55D6A0` 的原件順序為 `55D6B1 → 55E2E0` 清 collector、`55D6C3 → 402A70` 清 `P+18`，再覆寫六個全域名稱，最後 `55D7C2 → 6F4A50`、回傳 collector。前輪已核過初始化的 72 個全域 no-op（其中五個在每次載入時由有效 callback 覆寫，PlayMusic 另外新增），以及預掃描 Q namespace 的限制；本輪沒有將它們升格為正式功能。

**沒有從此處取得官方 stage flag。** `DoFile` 是否存在可以是受控新內容的條件設計，但前提是保留名稱、已核對 VM 初始化且所有載入內容不污染該名稱。因為 VM 持續存在，不能在文件中把「通常沒有 `DoFile`」寫成不可破壞的階段識別 API。

## 3. 預掃描 callback 的精確輸入契約

### 3.1 參數是從 stack 尾端讀取

`55C940/55CCE0/55CED0/55D220` 使用 `6F50F0` 與負索引，並非固定正索引。下表的第 n 參數只在**恰好傳入表列數量**時成立；多傳參數會移動實際讀取窗口。這是本輪直接核過的 ABI 細節。

| 全域預掃描 callback | native | stack 索引 | 有效收集欄位 | 缺值／條件 |
|---|---|---|---|---|
| `CreateObject` | `55C940` | `-9..-1` | 第 1 槽號、第 2 model、第 6 action | 先轉 32-bit integer，再進 collector；使用欄位無法轉數值時走 0 分支 |
| `AniObject` | `55CCE0` | `-3..-1` | 第 1 槽號、第 2 action | 第 3 參數被讀取但不影響此 collector；不存在槽號就略過 |
| `WalkObject` | `55CED0` | `-7..-1` | 第 1 槽號、第 5 數值 gate、第 6 action | gate 為 0 不收集；負 action 改成 4；不存在槽號就略過 |
| `WarpObject` | `55D220` | `-7..-1` | 第 1 槽號、第 6 數值 gate、第 7 action | gate 為 0 不收集；負 action 改成 1；不存在槽號就略過 |
| `PlayMusic` | `55D5E0` | 目前 stack 最後一個參數 | 字串寫至 `FE1F04 = P+18` | 可轉換值會轉字串；每次成功寫入覆蓋前值 |
| `Register` | `55D560` | 依既有 scene callback 契約 | 同步執行 scene 以產生上述宣告 | 不會替這個 VM 建立可等待遊戲事件的長駐 runner |

數值 conversion 在原件使用 Lua number／可轉數字字串及 x87 `FISTP`。本輪 SYN 範例限定已是可表示的 32-bit 整數，沒有模擬 x87 rounding、NaN、無限大或溢位。內容產生器應拒絕這些輸入，也應以數字 `0/1` 表示這些 numeric gate；不能假定傳 Lua boolean 就等於 native 整數。

正式全域 `WalkObject` 包裝的七個參數與 native `Q.WalkObject` 的六個參數不同，見 [observers 報告](../observers/report.md)。新內容的產生器必須選定 API 層級，不能把全域 wrapper 的參數表直接套到 `Q.*`。

### 3.2 Collector 的三種限制

`55C810` 將 slot 轉為 low WORD，存入 `P+8` 的 map。每個 value 是 `0x14` bytes record；record 的 `+0` 為 **WORD model ID**，`+4` 為 action set owner，`+8` 為 action sentinel，action node `+0C` 為 **WORD action ID**。`55E5B0` 與 `412B40` 證明 action 使用 unsigned WORD 比較並去重。

**第一個限制是 model 不會因同 key 再次 Create 而更新。** `55C85A` 分出 hit／miss；hit 路徑在 `55C888` 直接跳到 action 插入，沒有重建／改寫 record model。這不只影響字面相同的 slot，也影響 `slot & 0xFFFF` 相同的不同數值。

**第二個限制是宣告順序。** Ani／Walk／Warp 只找已存在的 collector record，不會為未知 slot 暫存待合併依賴。因此把 action 放在 Create 之前會漏掉這個 action；正式場景後來可否依其他路徑補載，不屬於這個 collector 的保證。

**第三個限制是預設 action 的檢查發生在截斷之前，且只在新 record 路徑。** 新 record 的整數 action 恰為 0 才被 `55C8DC` 改為 1；既有 record 再收到 0，會加入 WORD 0；新 record 收到 65536，也會截成 WORD 0，並不觸發前面的整數零判斷。

| SYN 操作（非原生 `.mef` 格式） | 得到的 collector | 實作含義 |
|---|---|---|
| Create `(1,100,0)`，再 Create `(65537,200,6)` | slot 1／model 100／actions `{1,6}` | low WORD 碰撞；第二個 model 未取代第一個 |
| Create `(7,100,2)`，再 Create `(7,200,0)` | model 100／actions `{0,2}` | 重複 Create 的 0 不變成 1 |
| Create `(3,100,65536)` | model 100／actions `{0}` | 先檢查 int zero，後截 WORD |
| Ani `(4,9)` 後才 Create `(4,100,1)` | actions `{1}` | 動作先宣告不會被追補 |
| Create、預掃描 `ClearObjects`／`Q.DeleteAllObject` no-op、同槽再 Create | 仍是第一個 model，actions 聯集 | 腳本內清理名稱不重置 native collector |

八個可重算反例完整存於 [synthetic-contracts.json](synthetic-contracts.json)，均標為 `SYN / NOT_NATIVE_MEF`。在本文對照的腳本清理名稱與正常重新載入路徑中，前兩者不重置 collector，`55D6A0` 則在新一次預掃描前明確清空這組 native 收集資料；此事不能推出 Lua globals 也已清空。

## 4. 正常 scene 的模型工作：等待的對象是什麼

`561AF3 → 55D6A0` 返回後，`561AFA` 把 collector 指標寫入 `M+70`。接下來：

1. `561AF8` 配置 **0x1C** bytes 工作物件；`+0` 是 event handle，`+4` 為 level，`+8` 是 BYTE replace flag，`+0C/+10/+14` 是 DWORD model vector。
2. `561B38` 設 level 3，`561B3F` 設 replace flag 1。逐 collector record 以 `MOVZX WORD [record]` 取 model，再由 `4A8680` 加入 vector。這段每個 record 一筆，沒有在此依 model ID 去重。
3. `561BF9 → 79DCE0` 交給 `R = FC0E90`。`R+68/+6C` 為目前 pending job 的指標／control pair。
4. `79DD23` 若已有 pending job，這次 publisher 回傳 0；可接收時呼叫 `CreateEventW`，再由 `7A0DA0` 發布 shared pair。
5. 模型 manager constructor `79CF40` 傳入 worker `79DEA0`。選定 worker branch 在 `79E083 → 7A03B0` 處理工作，`79E08E` 呼叫 `SetEvent`，接著清 pending pair。
6. 呼叫端 `561C03` 執行 `WaitForSingleObject(handle, INFINITE)`，`561C0A` 關 handle，處理既有的待完成資源物件後，`561C7D → 6F4A50` 正式載入 `.seq`。

這裡的 API 名稱不是靠反編譯猜測：已核原件 IAT／import string（WaitForSingleObject、CloseHandle、CreateEventW、SetEvent 與兩個 critical-section API）。`7A0DA0` 先把 local pair 清零；只有 incoming control 非零且 `47C250` 成功取得引用，才經 `7A0DC9 → 7A31C0` 複製來源 pair。`7A0DD4/7A0DDA` 發布這組 local pair，因此條件失敗時發布的是零 pair。反編譯導航把部分 copied local 顯示為常數 0，不能拿來斷言成功分支也只寫零；同樣不能把所有入參情況都說成成功發布同一 job。此處以原件分支與 dataflow 裁決。

### 4.1 為何 event 不是成功憑證

`7A03B0` 會先按 replace／level 釋放適用層級的既有資源引用，再走本次 model vector。若 model catalog 找不到 ID，`7A0674` 直接跳過該 model；若 catalog 已有 resource `+54`，不重跑 reader；若尚未有 resource，`7A0689 → 79D570` 嘗試讀取。它沒有把「每個 model／action 都有效」聚合為交給 scene 的成功布林值。

`79D570` 讀 catalog record 的 `+1C/+38` 字串交給 `7AC4C0`，成功才把產生的 resource 寫入 record `+54`。`7AC4C0` 開啟資源、識別 XML 輸入並透過 `CharacterList` 路徑呼叫 `7AEE60`。本輪只核其中建立 motion 的段落，**未聲稱完成整份模型 XML schema**。

更關鍵的是正常 caller 的 `WaitForSingleObject` 返回值並未檢查；緊接著就 CloseHandle 與後續載入。publisher 因忙碌返回 0、event API 失敗、catalog 缺 ID 等狀況，都不能由這段控制流程自動推出「scene 已被安全拒絕」。這是內容驗證與執行結果設計必須補上的需求，不是網路完成 ACK。

## 5. Collector 如何被正式物件消費

正式 `Q.CreateObject → 562EC0` 的物件型別／ID／所有權見 [actors 報告](../actors/report.md)。本子題接其模型資源部分。

若 model catalog 不存在該 ID 或 record `+54` 為空，`5630C0` 起將 full DWORD model ID 加入 `M+60` 集合，再 `56310E → 541610` 提出 on-demand 工作。這個工作仍配置 `0x1C`，level 為 `0xFF`，replace flag 為 0，並走相同 publish／wait／close。**因此「未被預掃描列入」不等於必然完全無法建立物件；已有另一條按需模型請求。** 反過來說，這也不能證明所有漏宣告的動作、貼圖或失敗情況都會自動恢復。

接著只有在 `M+70 != 0` 且 model resource 存在時，這段才做預掃描動作預載：

| 原件 | 動作 |
|---|---|
| `56318C`、`563193` | 先要求 model 的 action 1、4，經 `7C57F0` 查表與呼叫 |
| `56319C` | 正式 Q slot 取 low WORD |
| `5631B2 → 826280` | 在 `M+70` collector 找該 slot |
| `5631D4` | 逐 action node 讀 WORD action ID |
| `5631E1/5631EB` | 在 model resource `+D4` 動作表查 key |
| `563204` | action `v+8` 返回 ID，與要求值比對 |
| `563214` | 匹配才呼叫 action `v+24` |

XML 動作建立段 `7B08AC..7B0968` 配置 `0xD8` 的 motion，呼叫 `7DA950`，並把 descriptor 的 WORD action ID 對應物件插入同一個 model `+D4` 表。constructor 的 vptr、COL、type descriptor 把它確定為 **`.?AVCMotion@IS3D@@`**；`v+8 = 7DA910`、`v+24 = 7DAB20`。

### 5.1 `CMotion::v+24` 是資源請求

`7DAB20` 檢查 owning motion `+D4` 是否已為 1；若沒有且檔名字串非空，組合 prefix 與檔名，配置 `0x2C` request，設其排序值為 `WORD motionID × 1000`，呼叫 `7B61D0(FD9420, request, motion+4)`。`7B61D0` 在 critical section 中分配序號，登記 request 與雙向 receiver 索引；呼叫回來後 `7DAC5D` 才把 motion `+D4` 設為 1。

secondary vtable 的唯一首槽 `7DB270` 接收 `motion+4`。因此 receiver 的 `+D0` 是 owning motion 的 `+D4`，receiver 的 `+CC` 是 owning motion 的 `+D0`；原件在 request marker 非零時將 callback 的第二參數寫入 owning motion `+D0`。這裡刻意區分兩種 `this`，避免把欄位錯移四個 bytes。

本輪證明的是**具體請求 producer、receiver 登記與 receiver 寫入契約**。沒有把完整動畫工作執行緒、callback 的全部間接 callers、資源解析成功條件或 render 成果全部升為已證實。因此 `7C57F0` 返回 1 只表示其查到相符動作並呼叫 `v+24`；不等於這個動作已載完、更不等於已播放完。

## 6. 新內容應產生的內容與執行順序

建議由同一份新內容規劃產出下列兩個單元；這是開發設計，不是原版檔案改寫，也未在本輪產生可部署 `.seq/.mef`。

| 單元 | 必備內容 | 必須拒絕的情況 |
|---|---|---|
| 新 `.seq` bridge 的預掃描部分 | 有限的 slot→model 宣告；先 Create 再列 action；符合各全域 callback 的 exact arity；所需 music 宣告 | 同 low WORD slot 指向多個 model、越界／非整數 ID、依遊戲事件才能結束的 loop、只有 `Q.*` 呼叫卻期待全域 collector 自動知道依賴 |
| 新 `.seq` bridge 的正式部分 | 在已成立的 Q coroutine／環境中載入選定新模組，檢查 loader 數值狀態，取得當次有效 export，再進 entry | 把 `DoFile` 當 module-table return；用 `if DoFile(...) then` 分辨 0／1；在 loader protected C 邊界內直接進入需要 yield 的長流程 |
| 新 `.mef` 模組 | 已知 parser 可讀的 Lua 內容；有限 top-level；具版本的 export／entry；明確結束與取消處理 | 宣稱它是官方 MEF opcode 格式；依賴不存在／無回傳的 native API；把返回／等待完成當操作已獲 Server 承認 |
| 發布／選取資料 | 明確資源路徑、內容版本與 hash、SceneList／stage 選取條件、依賴 catalog 與有效 action 集合 | 檔案雖存在但無可達 caller；舊 archive／快取覆蓋新內容；只有設計路徑卻宣告已在原版觸發 |

正式模組載入建議遵循這個**設計順序**：清理同名舊 export → `DoFile` → 檢查數值 **0 成功／1 失敗** → 驗證本次 export 與版本 → 在 loader 返回後由既有 Lua coroutine 呼叫 entry。`DoFile` 不回傳模組 table，而且 0 與 1 在 Lua 都是 truthy；前輪已核這些 loader 契約。本輪不據此假設所有失敗都可完整 rollback。

預掃描不會自動進入由正式 `DoFile` 才載入的 `.mef` 取得依賴；因此必須由內容產生器同步輸出依賴宣告。動態選擇的模型／動作若不在有限宣告集合內，需另有已驗證的按需載入策略，不能以想像補齊。

## 7. Server 開發需求與驗收界線

本專案以 MEF 真正承接指定 Server 操作為目的；下表為 **Server 開發需求**。原有 Server 繼續完成那些指定操作只能作比較基線，不能計入 MEF 替代完成。

| 需求 | 本輪可直接提供的契約 | 完成驗收仍須取得的結果 |
|---|---|---|
| 內容產生／驗證 | 兩階段依賴一致、slot/model/action 位寬、first-model 與 exact arity | 用實際已核 catalog/action 集合拒絕缺依賴內容；不以 SYN model IDs 當存在資源 |
| 第一個新內容 caller | 延用可條件整合的 `.seq → DoFile(new.mef)` 設計與本輪預掃描規則 | 真正可選取的新資料、原有 loader 可達、版本／archive 優先序匹配的授權驗證 |
| 完成／失敗協定 | 已排除 prepass return、model event、motion helper return 當 gameplay ACK | 執行個體、內容版本、完成／失敗與取消結果能對應同一操作；格式若新訂須標自訂，不能冒充既有命令 |
| 普通戰鬥持續執行 | 本輪沒有把資源 worker 或 Q actor 原生更新誤作背景 Lua runner | 證明普通場景可用的持續排程／controller 忙碌解除／取消契約，見 [ordinary-runner](../ordinary-runner/report.md) |
| 真正戰鬥物件與事件 | Q slot／演出物件與停止 observer 的限制已更明確 | world 物件身分／死亡或群組清空事件可被目標 MEF 流程正確消費；見 [actors](../actors/report.md)、[observers](../observers/report.md) |

有限演出內容可以依這份契約開始做新內容產生器、模組 loader adapter 與離線驗證器；目前證據仍不足以宣告「普通戰鬥操作已由 `.mef` 完整接管」。

## 8. 可重現驗證

```sh
python kr-extra-roy/MEF-content-contracts-20261116/bridge/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi
```

輸入只讀；驗證會核原件身分、所有選定 bytes／反組譯、負參數索引、IAT、RTTI、直接 call、SYN 整數反例與固定 commit 的來源內容。Git lazy fetch 被關閉，沒有額外網路拉取。

[validation-result.json](validation-result.json) 為 PASS：50 範圍、32 code windows、11,717 bytes、3,573 指令、45 個 exact anchors、29 個直接 call、6 個 import、4 組 callback 參數窗口、8 個 SYN 反例、55 個來源 pins 與 55 個內容雜湊。**這是靜態原件一致性 PASS，不是 Client 執行測試、Lua 執行測試、端到端遊戲驗收或 T01 FULL-PASS。**
