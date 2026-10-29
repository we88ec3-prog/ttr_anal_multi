# T16-110 修訂原稿（REV）— Quest 14／子研究④：Client S→C 接收資料契約、處理副作用與 S00 Server 規格交接

> **修訂日期：2026-10-30T00:23:49+08:00（Asia/Taipei）。研究狀態：T16-110 原稿的本地勘誤／擴充，不啟動另一個正式段號。** 本文前半是本次修訂後的權威解讀；後半附上未改寫的 T16-110 歷史全文供完整 assembly 回溯。原稿的「必須取得官方 Server 封包紀錄才能完成本子研究」判斷已撤回。本文也不把任何候選命令猜成 Quest14 專屬完成回覆。

- **原件**：KR `Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` 11,241,597 bytes、SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`，本次再次實際 hash 核對。原件唯讀，沒有啟動或修改 Client，沒有執行 Server。
- PE `.text` VA `0x401000`, raw `0x400` → raw=VA-`0x400C00`；`.rdata` VA `0xBD2000`, raw `0x7D0600`；`.data` VA `0xD61000`, raw `0x95E800`。RTTI pointer 必須依其自身分節映射。工具：`hashlib`、`struct`、GNU `objdump` x86。
- **GitHub 當次唯讀基線**：`main=e7416169fd20e4fcb0fe2c0b4d6207e4c9b443bc`，`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b`，compare **behind=1 / ahead=22**；沒有使用者授權 Commit/Push，因此**本地只修訂 T16-110，不宣稱開始新正式段號或完成 branch sync**。最新 T16 inbox 無 owner_task=T16 的已分派 RR；原版 `RR-0005` 屬 T02 的 login/Connect handoff，與本研究無涉，未刪除。
- T01 `READY_FOR_REVIEW` 尚不等於 FULL-PASS，既有驗證狀態原樣保留。使用者明示本次先完成 Quest14-④；已存在的 T01 退回事項獨立排程。

## 1. 對使用者疑問的正式更正：專案早已寫明 Server/Client/S00 分工

下列是本次逐檔核實的**專案權威條款**，不是本研究另創政策：

| 權威來源 | 原文件所規定 | Quest14-④ 的處置 |
|---|---|---|
| `02-PROJECT-SHARED-INSTRUCTIONS.md`「完整驗證成果復用、跨 Task 與 Server 責任」 | 終極目標是原版 Client + 新相容 Server；**不要求還原原版 Server 內部演算法、資料庫或決策**；原版 Server 未知本身**不是**Client 逆向未完成原因 | 撤回以未取得原版 Server 捕獲／實作作為停段理由；用 Client parser、writer、UI 條件產出相容資料需求 |
| 同檔「S00 規格設計」 | S00 負責 SPEC/GAP/TEST/ADR **規格整合及發布，並非 Server 程式實作** | 把 Server 策略、任務狀態與保存需求列入 S00 待規劃工作包；不要求 T16 寫 Server |
| `03-PROJECT-T16-INSTRUCTIONS.md` §1–4 | T16 的核心是 Client 雙向封包＋Client 更新、NPC/UI；原版 Server 通關、任務前置、DB 實作屬待開發 Server；**不能把未知 Client wire 欄位全丟給 Server** | 每種已證 Client 接收條件、欄位與副作用明列；Quest14 專屬 mapping 缺失仍依規則保留 Client GAP，不能粉飾已驗證 |
| `kr/tasks/T16/task.json` `excluded_scope` / `acceptance` | 原版 Server 內部勝敗、解鎖及 DB 非 T16 驗收阻塞；T16 要保存 Client 端到端矩陣、Client 未解與 Server 開發接口 | 以有界資料契約與殘餘 Client gap 交付，而非要求官方 Server trace |
| `governance/s00-workflow.md` | S00 依證據建立 SPEC、ADR、GAP、TEST，**UNKNOWN 的必要 Client 欄位不得升 STABLE** | 允許先產生 DRAFT/GAP/測試方案，不把未知 Quest14 status serializer 猜成 `0x41/42/7F` |

**政策更正精確界線**：沒有原版 Server 封包樣本 ≠ Client 已分析完畢；也 ≠ Client 分析不能進展。Quest14 的**原版 Server 判定、持久化、獎勵及主線解鎖算法**可明確移交 S00。反之，**原版 Client 真正把哪條 S→C 命令識別為 Quest14 完成、必要字段與 UI consumer**仍屬 Client 研究事項：只要 BIN 可進一步辨識就應繼續，無法證明時列出具體 GAP，而非歸咎 Server 不能提供官方 trace。

## 2. Quest14-④ 的完成定義與現況

**本次完成的可交付單位是「已定位 S→C 命令候選的 Client 可解析契約、接收分派、記錄狀態與通知副作用，以及 Server 設計需填補資料的需求界線」**。這項工作已覆蓋三組具實際 handler 的原生 payload/parser 並完整明列錯誤路徑；保留下一批定向 Client GAP。**尚不能宣稱找到了「Quest14 專屬完成消息」或「Quest14 UI 完成狀態確定變更」，不能稱 Quest14 的完整特定雙向 wire 正式核實，也不能標 T01 FULL-PASS。**

| Quest14 子研究 | 狀態 | 這個狀態真正涵蓋的內容 |
|---|---|---|
| ① Quest14 XML/前置 | **資源已確認** | QuestInfo id14 的原始 attributes／無 Demands；Quest16 宣告依賴 Quest14 |
| ② 玩家觸發 | 部分 | TutorialMain Lua `RequestStartScenario(14)`/`IsScenarioEnded(14)` 是 scenario domain；與 QuestInfo ID14 不宣稱同一 wire domain |
| ③ C→S | 部分 | 本地 word `0x40` 發送 builder／通用傳輸路徑，不擅稱為 Quest14 completion C→S |
| **④ S→C／Client 狀態／UI** | **本次 Client 契約與需求分析已交付；Quest14 專屬映射未證** | 通用 channel2/Scene 路由、`0x41/0x42/0x7F` payload/record/events 已核；Quest14 完成通知身份、UI listener/效果是 Client GAP |
| ⑤ 完成並解鎖 Quest16 | 未閉合（另項） | Server 任務前置/完成/解鎖屬 Server 設計，Client 的 Quest16 可接 UI 需另行核對 |

## 3. Quest14 原始靜態需求（不能當作封包格式）

在 GitHub `main` 的 `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt` **直接重新讀取**，原文 Quest14 如下：

```xml
<Quest id="14" type="3" town="0" field="18" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-이실리아">
  <CompleteAction type="1" />
  <AcceptAction type="1" />
</Quest>
```

- `Quest 16` 實有 `<Demands><Demand id="14" /></Demands>`；Quest15 前置宣告 ID16。靜態宣告只證 Client 靜態資源的前置 key，不證 Server 是在何時發送什麼。
- `QuestTalk.xml` 4322 entries 中找不到 `id=14/15/16`，這不是任務不存在的證據。
- `Event.stp` 原始 Lua5.1 chunk `TutorialMain.lua` 的 proto（原始行起點131）常數表存在 `RequestStartScenario`, `14.0`, `IsScenarioEnded`，opcode 指令索引 `016–023` 是 `Tutorial.RequestStartScenario(14)` 後呼叫 `Tutorial.IsScenarioEnded(14)`，`024–029` 用 `FALSE` 比較與 coroutine yield/jump 循環；**這證明教學腳本有本地輪詢，但不代表 QuestInfo id14 任務狀態已完成**。

## 4. Client S→C 解析與輸出契約（本次交付核心）

### 4.1 通用接收入口與可達條件

原生路徑（跨 T02／T16，只引用已限定同版資料）：

```text
IOCP/WSARecv → 0x807B40 transport 解框
    → 0x8040A0 / 0xFC10D0 中繼（實際 lane/gate 取決於 record）
    → 0x804740 → worker vtable+0 → 0x4930E0
    → channel == 2 且 length > 0
    → payload[0:2] little-endian command index
    → Client 16-byte command table / 全域 fallback
    → current Scene vtable+4 / 0x4C4670：表 B override 優先，表 A fallback
    → 實際選中 handler（下列三類）
```

這個**條件性 Client 端可達性**不等於確認 Quest14/任何 Server 當次真的傳送相同 ID。`0x4930E0` 接收 channel !=2、len==0 不會依這條分支送入 scene handler；不同場景 tableB 若覆寫相同 index，下面表 A handler 不一定執行。`0x1A68/0x0BBB` 屬 transport header，不是任務 payload 首 WORD。**命令編號在 S→C 與 C→S 不必是相同語義**，例如 C→S 0x42 角色選擇與此處 Scene index66 不是同一規格。

### 4.2 可從 Client 直接定義的三個候選 S→C payload

| Scene 預設 handler 索引 / 函式 | 此 handler 對已解框 payload 的可證欄位 | 接收後 Client 寫入／事件 | 重要不可保證事項 |
|---|---|---|---|
| `0x0041` → `0x4B2310` | offset `+0` cmd:u16；後面重複 `value:u16` (`+2+4i`)、`record_key:u16` (`+4+4i`)；`N = max(0,floor((len-2)/4))`。**2+4N 是整齊記錄長度，不是原版唯一合法長度** | `0x53DB30` 對 owner 的 0x14-byte、0x18-byte 兩組記錄，以 record+2 匹配 `record_key`，寫 `record+8 = value`；之後 `0x58AAD0(F4266)` | 未命中記錄不會生成新記錄；不足一筆仍可發事件。不能把 record_key=14 或 value=1 認為官方完成標誌 |
| `0x0042` → `0x4B2190` | `+0 cmd:u16`，`+2 signed key:i16`；`+4` 起變長 entry，entry[1] subtype 1..11。entry 長度：1/3=15、2/5/11=11、4/6=13、7/8=10、9=9、10=直接終止 | `0x500110` 先把 key 寫入最多20個 WORD 的 local key 槽（去重/滿額不上列）；通過長度/subtype gate 的 entry 經 `0x53D840` 更新 `[FAB134]` 的 0x18-byte 記錄，`record+0x14 = message key`。下游 `0x500E00` 可依 record 過濾 UI 候選 | `len<=4` 仍可能先新增 key，但不處理 entries；subtype 9 跳過 writer、10 終止；記錄變動不代表 Quest14 完成 |
| `0x007F` → `0x4B23C0` | `+0 cmd:u16`；`+2` 起 subtype 位於每筆 entry[1]，類型1..8；增量長度 1/3=15、2/5=11、4/6=13、7/8=10 | 在 `Obj_40F060()+4` 下的 0x14-byte 記錄列表中，`0x53D5E0` 對 entry[4:6] key 取得／更新記錄的多個欄位；每筆處理後投遞本地 `F4266` | entry[4:6] **不是已證 Quest ID**；len<=2 或 subtype 非法走退出；本地通知不是 S→C wire ACK |

**關於 S00 必需資料的精確拆分**：對以上三種 handler，Client 端**已經知道如何解析其欄位**。但這不等於 **Quest14 必須收到這三種消息**，也不等於已得知「Quest14 正確完成數值」。S00 若要啟動 compatibility prototype，這三個是可供白箱與測試的候選 schema，必須標 `Client static parser confirmed / Quest14 effect unmapped`；不可給出 `Quest14Complete = 41 00 01 00 0e 00` 之類猜造規格。

### 4.3 UI 與事件產生／消費者：更正假交叉驗證

1. `0x4B239C`、`0x4B24A2` 在 **0x41/0x7F 實際 handler** 分支可確認 push literal `0xF4266` 呼叫 `0x58AAD0`。`0x53DB0C` 的 reset 函式 push `0xF426F` 呼叫同一發送器。這些是**Client 本地事件**，不等於 S→C 命令。
2. **重要新原生反證**：`0x5DF3A0` 雖然 `mov eax,0xF4266; ret`，但其唯一 RDATA 函式指標出現在 `0xC25894`，對應 vtable `0xC2588C` 的 `+0x08` slot。其 COL `0xC730B0` type descriptor `0xF83AF4` 原始 RTTI 名稱是 **`.?AVCItemSlotMailAttachmentSlotRead@FUI@@`**。建構者 `0x5DF470` 在 `0x5DF4C9` 將 vptr `0xC2588C` 安裝在配置 0x2A8-byte 的物品欄控制物件。因此原 T16-110 以 `0x5DF3A0` 佐證 **Quest14 UI listener** 的說法**不成立**：它屬郵件附件 UI 物件，雖數值碰巧相同，不能證明 Quest14 事件被這個 listener 消費。
3. `0x635CA0` 以 `0x500950`/`0x500E00` 候選列表的非空狀態寫 UI 控制物件 `+0xB4/+0xB5`。`0x638E60` 從 TalkBox dialog 的 `this+4` child 讀旗標。**沒有這兩物件 alias 及 Quest14 特定 ID 的閉合證據**，因此不能稱 Quest14 UI 亮燈已證。
4. `0x41` 的 0x18-byte 類型 `record+4==3` 下，額外的 `0xF8D91C` tree hit 可觸發 `0x558200` 將相關指標投遞 `0xFC1AC4`；tree miss 只略過附加動作，**不回滾已完成的 record+8 writer**。這是 Client 本地額外佇列，不是對 Server 的完成回覆。

### 4.4 CFG 及失敗分支的 Server-facing 測試矩陣

| 測試前置與輸入 | Client 原始可見效果 | 建議 S00 TEST（*proposed*, 沒有實際執行） |
|---|---|---|
| channel≠2 或 `0x4930E0` len=0 | 不透過此 scene業務分派 | 檢查訊息不能被錯放於其他通道 |
| Scene tableB override index65/66/127 | 不一定選用本文表A handler | 先對照所用 Scene subtype/handler table |
| 0x41 len=2 且無記錄 | 不寫 record；仍投遞 F4266 | 空項事件不得作完成狀態成功證據 |
| 0x41 `(value,key)` 但 key 不存在 | 不寫 +8；仍投遞 F4266 | 先建記錄，再驗證更新；交換 key/value 應不命中（在設計測試中） |
| 0x41 有匹配 key，0x14/0x18 records | 各命中記錄 +8 改為 value | 一致性的 state diff：確認記錄欄位值 |
| 0x41 第二組 subtype!=3 或附加 tree miss | +8 寫入仍可成立；附加 queue 分支不走 | 不以缺少 queue item 判定更新失敗 |
| 0x42 len=4 | 可能 register key；無變長 entry 寫入 | 驗證 key/list 和完整 record 分開 |
| 0x42 20-slot 已滿／重複 key | 滿額不增加；重複不重複插入 | 驗證列表有界性與去重 |
| 0x42 subtype 9/10/其他非法 | 9 跳過 writer；10退出；非法直接出口 | 測試不同 subtype 的差異而非一律 update |
| 0x7F subtype 1..8 / 非法 | 有效型別走 0x14-record add/update；非法退出 | 依表中真實增量生成*合成測試向量*，不得稱官方封包 |
| 0x7F 空/短 payload | 不建立記錄；通常不會進 per-entry F4266 | 空記錄不可保證 refresh |
| `IsScenarioEnded(14)` 返回 true | Lua 繼續下一個本地步驟（不會因此直接寫 Quest14 的 XML status） | scenario 結算狀態與 Quest14 完成狀態分開記錄 |

## 5. S00 規格交接：把 Server 行為列為開發需求，而非官方抓包要求

**以下都是待 S00 受理／規劃的提案；尚未建立或變更遠端 SPEC/GAP/RR/ADR/TEST 台帳，也沒有指派或通知其他 Agent。** S00 是設計統籌，不是 Server code 實作。

| 拆分 | S00 應建立的工作項 | 依據與驗收邊界 | Owner 建議 |
|---|---|---|---|
| **Client bounded contract** | Quest14 S→C 三組候選 `0x41/0x42/0x7F` 的限定格式、channel/scene preconditions 與 writer/events；以 T01 限定主張審核後收入 DRAFT | 已證本研究 §4 / 先前 T16-110 ASM；不把候選升 Quest14 official opcode | T16 原稿供證；S00 統整；T02 提供 transport |
| **Client GAP-Q14-S2C-IDENTITY** | 找到 Quest14 實際使用的 S→C cmd/業務 key 及 handler（如果存在）；是否另走非這三條通知；定位 Quest14 UI 接收者 | **純 Client 項目，不能推給 Server 設計**。需追實際可達 CClient callback table/scene override、Quest14 間接 source/consumer；沒有官方封包也應繼續以 BIN 調查 | T16，必要時 T06/T07 支援；由 S00 建有精確問題的 RR（**非既有 RR-0005**） |
| **Server-only Quest14 state** | 設計角色範圍 Quest14 active/progress/completable/completed 的 authoritative 狀態、如何判定 Scenario14 完成、合法重試/退出、冪等、清單和獎勵政策 | 原始 Client 不可能告知原版 Server 如何做合法勝敗與 DB；由 S00 提案 ADR，另 repo 實作。業務映射未完成時不發明 Client 完成消息字節 | S00 ADR/SPEC；Server 實作方；T14 結算、T15 持久化 |
| **Server ↔ Client compatibility** | 依日後核實的 handler 做正確 notification/snapshot、長度／字段／順序／錯誤處理；若下發 `0x41` 更新，應先有相應 key 的可命中 record；若 UI 必須刷新，須核對 event/consumer | 兼容性依已核實的 Client 狀態機；不得把 `0x41/42/7F` 推定為 Quest14 官方 ACK | S00 SPEC/GAP/TEST；T02/T06/T16 |
| **跨功能** | 依 `QuestInfo` demand14 → Quest16 可接清單需求；Scenario14/T07回場景、T14關卡結果、T15角色重登保存、T06 UI 門檻 | 這些是 downstream 的正式接口，非 T16-④ 需要還原的原版 Server 內部演算法 | S00 統整跨 Task；各 Task 保留主責 |
| **運作／可玩** | 無修改 Client 的合成測試及最終端到端 Quest14/16 解鎖驗收 | synthetic vector 僅測 Client parser，不能單憑 synthetic 聲稱原版 Server 實際行為 | 實作方+S00 TEST；驗收尚未進行 |

### 5.1 接受一個 Server-only GAP 的準則

`Quest14 completion decision`、`Quest16 unlock policy`、`reward settlement`、`relogin quest persistence` 這些不必從原版 Server 抓包才能開始規劃；可以由 S00 登記明示非原版保證的設計決策，之後交實作方。而 `Quest14-specific wire opcode/field` 若原始 Client parser 未辨認，**不能因 Server 需自己實作便宣稱 T16 內的必要 Client ABI 已確認**；此仍是分離的 Client GAP，不能升 `SPEC STABLE`。

### 5.2 供 S00 直接複製的工作包（待審，非已派工）

```yaml
scope: KR Quest14 client S2C contract / tutorial quest progression
source: T16-110-REV local Markdown; not a pushed Git blob
native_client:
  confirmed:
    - channel2 payload first word routes scene callbacks conditionally
    - scene tableA 0x41 -> 4B2310, value/key pair -> 53DB30 -> record+8, local F4266
    - scene tableA 0x42 -> 4B2190, key + variable entries -> 500110/53D840
    - scene tableA 0x7F -> 4B23C0, variable entries -> 53D5E0, local F4266
  unknown:
    - true QuestInfo id14-specific S2C handler and field/tag mapping
    - actual Quest14 NPC/UI consumer and its state field
    - whether Quest14 progress uses scene override or another command
server_design:
  - per-character Quest14 authoritative lifecycle; decision policy is new Server ADR
  - Scenario14 outcome acceptance; idempotency/retry/disconnect and snapshot
  - Quest16 availability derived from new Server policy consistent with XML Demand14
  - exact Client-compatible replies only after verified Client fields; no guessed bytes
review:
  T01: native bounded byte-claim review
  S00: SPEC/GAP/ADR/TEST draft intake
  runtime: not tested
status: proposed_for_S00_not_submitted
```

## 6. 重新執行的 BIN-first 補強與反證（本次新增）

- 全檔 DWORD immediate/reference 查證 `0x5DF3A0` 只出現在 RDATA `VA 0xC25894`（raw `0x823E94`）；`0xC2588C` vtable 指標在 `.text` 共有 `0x5DF4CB`, `0x5DF55E`, `0x5DF85E`，前兩個已定向核對為物件安裝。COL `0xC730B0` 的 TypeDescriptor pointer= `0xF83AF4`，其 type name 是 `. ?AVCItemSlotMailAttachmentSlotRead@FUI@@`（不帶空白實際字串 `.?AVCItemSlotMailAttachmentSlotRead@FUI@@`）。**與 Quest 完成 UI 無關的 vtable**，不能當作 Quest listener 證據。
- Scene table A 即時計算：`0x4ADF4D` 註冊 offset `+0x20C` index `(0x20C-4)/8=65`；`0x4ADF3D` 註冊 `+0x214` index66；`0x4ADF5D` 註冊 `+0x3FC` index127。直系 Scene tableB 可覆寫，因此命令索引是有條件對應。
- `0x4B24CC` 原始8個 DWORD 跳表 little-endian targets = `4B2431,4B2439,4B2431,4B2441,4B2439,4B2441,4B2449,4B2449`；type長度分別 `15,11,15,13,11,13,10,10`。`0x4B22E0` 11個 DWORD target 中 index10 是直接退出 `0x4B22C6`。下列原生段落與歷史全文可重現驗證。

### Q14 參考：Scene table A 的三個 handler 註冊

VA `0x004ADF3D..0x004ADF6D`，raw `0x000AD33D..0x000AD36D`，48 bytes；slice SHA256 `44557c168bce236829d16741c9c5852fa74efe66b0fadbaf2eb29dbf4435edc7`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
```

### Q14 S2C 0x41：定長值／key與局部事件

VA `0x004B2310..0x004B23BC`，raw `0x000B1710..0x000B17BC`，172 bytes；slice SHA256 `fb0975abdd7d1c0e632f5f17ebd6da9a153f3de6f8dc91ca150eb49251a89c3b`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  4b2310:	55                   	push   ebp
  4b2311:	8b ec                	mov    ebp,esp
  4b2313:	6a ff                	push   0xffffffff
  4b2315:	68 7e c7 93 00       	push   0x93c77e
  4b231a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2320:	50                   	push   eax
  4b2321:	56                   	push   esi
  4b2322:	57                   	push   edi
  4b2323:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2328:	33 c5                	xor    eax,ebp
  4b232a:	50                   	push   eax
  4b232b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b232e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2334:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b2337:	83 f8 02             	cmp    eax,0x2
  4b233a:	73 04                	jae    0x4b2340
  4b233c:	33 ff                	xor    edi,edi
  4b233e:	eb 06                	jmp    0x4b2346
  4b2340:	8d 78 fe             	lea    edi,[eax-0x2]
  4b2343:	c1 ef 02             	shr    edi,0x2
  4b2346:	85 ff                	test   edi,edi
  4b2348:	74 22                	je     0x4b236c
  4b234a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b234d:	83 c6 02             	add    esi,0x2
  4b2350:	e8 0b cd f5 ff       	call   0x40f060
  4b2355:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  4b2358:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b235b:	66 8b 56 02          	mov    dx,WORD PTR [esi+0x2]
  4b235f:	51                   	push   ecx
  4b2360:	50                   	push   eax
  4b2361:	e8 ca b7 08 00       	call   0x53db30
  4b2366:	83 c6 04             	add    esi,0x4
  4b2369:	4f                   	dec    edi
  4b236a:	75 e4                	jne    0x4b2350
  4b236c:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2373:	75 27                	jne    0x4b239c
  4b2375:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b237c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2383:	e8 f8 50 0d 00       	call   0x587480
  4b2388:	68 c0 cc bc 00       	push   0xbcccc0
  4b238d:	e8 88 ff 3d 00       	call   0x89231a
  4b2392:	83 c4 04             	add    esp,0x4
  4b2395:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b239c:	68 66 42 0f 00       	push   0xf4266
  4b23a1:	e8 2a 87 0d 00       	call   0x58aad0
  4b23a6:	83 c4 04             	add    esp,0x4
  4b23a9:	33 c0                	xor    eax,eax
  4b23ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b23ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b23b5:	59                   	pop    ecx
  4b23b6:	5f                   	pop    edi
  4b23b7:	5e                   	pop    esi
  4b23b8:	8b e5                	mov    esp,ebp
  4b23ba:	5d                   	pop    ebp
  4b23bb:	c2                   	.byte 0xc2
```

### Q14 S2C 0x7F：變長錄入與分支

VA `0x004B23C0..0x004B24B4`，raw `0x000B17C0..0x000B18B4`，244 bytes；slice SHA256 `a660818367ac122b57dbb41f102387ab752fe483bbfef39f123371f6204a635a`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  4b23c0:	55                   	push   ebp
  4b23c1:	8b ec                	mov    ebp,esp
  4b23c3:	6a ff                	push   0xffffffff
  4b23c5:	68 de 54 94 00       	push   0x9454de
  4b23ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b23d0:	50                   	push   eax
  4b23d1:	53                   	push   ebx
  4b23d2:	56                   	push   esi
  4b23d3:	57                   	push   edi
  4b23d4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b23d9:	33 c5                	xor    eax,ebp
  4b23db:	50                   	push   eax
  4b23dc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b23df:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b23e5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b23e8:	be 02 00 00 00       	mov    esi,0x2
  4b23ed:	03 fe                	add    edi,esi
  4b23ef:	e8 6c cc f5 ff       	call   0x40f060
  4b23f4:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  4b23f7:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4b23fa:	8b 03                	mov    eax,DWORD PTR [ebx]
  4b23fc:	3b c1                	cmp    eax,ecx
  4b23fe:	74 0e                	je     0x4b240e
  4b2400:	50                   	push   eax
  4b2401:	8b d1                	mov    edx,ecx
  4b2403:	e8 68 7e 04 00       	call   0x4fa270
  4b2408:	83 c4 04             	add    esp,0x4
  4b240b:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  4b240e:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4b2411:	3b de                	cmp    ebx,esi
  4b2413:	0f 86 9b 00 00 00    	jbe    0x4b24b4
  4b2419:	0f b6 47 01          	movzx  eax,BYTE PTR [edi+0x1]
  4b241d:	48                   	dec    eax
  4b241e:	89 7d 08             	mov    DWORD PTR [ebp+0x8],edi
  4b2421:	83 f8 07             	cmp    eax,0x7
  4b2424:	0f 87 8a 00 00 00    	ja     0x4b24b4
  4b242a:	ff 24 85 cc 24 4b 00 	jmp    DWORD PTR [eax*4+0x4b24cc]
  4b2431:	83 c7 0f             	add    edi,0xf
  4b2434:	83 c6 0f             	add    esi,0xf
  4b2437:	eb 16                	jmp    0x4b244f
  4b2439:	83 c7 0b             	add    edi,0xb
  4b243c:	83 c6 0b             	add    esi,0xb
  4b243f:	eb 0e                	jmp    0x4b244f
  4b2441:	83 c7 0d             	add    edi,0xd
  4b2444:	83 c6 0d             	add    esi,0xd
  4b2447:	eb 06                	jmp    0x4b244f
  4b2449:	83 c7 0a             	add    edi,0xa
  4b244c:	83 c6 0a             	add    esi,0xa
  4b244f:	3b f3                	cmp    esi,ebx
  4b2451:	76 0d                	jbe    0x4b2460
  4b2453:	68 bc 6c bf 00       	push   0xbf6cbc
  4b2458:	e8 03 b7 23 00       	call   0x6edb60
  4b245d:	83 c4 04             	add    esp,0x4
  4b2460:	e8 fb cb f5 ff       	call   0x40f060
  4b2465:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b2468:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b246b:	51                   	push   ecx
  4b246c:	50                   	push   eax
  4b246d:	e8 6e b1 08 00       	call   0x53d5e0
  4b2472:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2479:	75 27                	jne    0x4b24a2
  4b247b:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b2482:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2489:	e8 f2 4f 0d 00       	call   0x587480
  4b248e:	68 c0 cc bc 00       	push   0xbcccc0
  4b2493:	e8 82 fe 3d 00       	call   0x89231a
  4b2498:	83 c4 04             	add    esp,0x4
  4b249b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b24a2:	68 66 42 0f 00       	push   0xf4266
  4b24a7:	e8 24 86 0d 00       	call   0x58aad0
  4b24ac:	83 c4 04             	add    esp,0x4
  4b24af:	e9 5d ff ff ff       	jmp    0x4b2411
```

### Q14 0x41 下游：命中、更新及附加 queue gate

VA `0x0053DB30..0x0053DC7B`，raw `0x0013CF30..0x0013D07B`，331 bytes；slice SHA256 `9948e7e9b39423e9a2bacd908fbaddb85e97186a979a5e01b2adb79061716d3e`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  53db30:	55                   	push   ebp
  53db31:	8b ec                	mov    ebp,esp
  53db33:	6a ff                	push   0xffffffff
  53db35:	68 6c a2 93 00       	push   0x93a26c
  53db3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53db40:	50                   	push   eax
  53db41:	83 ec 0c             	sub    esp,0xc
  53db44:	53                   	push   ebx
  53db45:	56                   	push   esi
  53db46:	57                   	push   edi
  53db47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53db4c:	33 c5                	xor    eax,ebp
  53db4e:	50                   	push   eax
  53db4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  53db52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53db58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53db5b:	8b 07                	mov    eax,DWORD PTR [edi]
  53db5d:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db60:	74 1b                	je     0x53db7d
  53db62:	0f bf ca             	movsx  ecx,dx
  53db65:	0f b7 70 02          	movzx  esi,WORD PTR [eax+0x2]
  53db69:	3b f1                	cmp    esi,ecx
  53db6b:	75 08                	jne    0x53db75
  53db6d:	66 8b 75 0c          	mov    si,WORD PTR [ebp+0xc]
  53db71:	66 89 70 08          	mov    WORD PTR [eax+0x8],si
  53db75:	83 c0 14             	add    eax,0x14
  53db78:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db7b:	75 e8                	jne    0x53db65
  53db7d:	8b 5f 10             	mov    ebx,DWORD PTR [edi+0x10]
  53db80:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53db83:	0f 84 f0 00 00 00    	je     0x53dc79
  53db89:	0f bf c2             	movsx  eax,dx
  53db8c:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  53db8f:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  53db93:	3b 4d f0             	cmp    ecx,DWORD PTR [ebp-0x10]
  53db96:	0f 85 d1 00 00 00    	jne    0x53dc6d
  53db9c:	66 83 7b 04 03       	cmp    WORD PTR [ebx+0x4],0x3
  53dba1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  53dba5:	66 89 53 08          	mov    WORD PTR [ebx+0x8],dx
  53dba9:	0f 85 be 00 00 00    	jne    0x53dc6d
  53dbaf:	f6 05 a4 d9 f8 00 01 	test   BYTE PTR ds:0xf8d9a4,0x1
  53dbb6:	0f b7 73 0c          	movzx  esi,WORD PTR [ebx+0xc]
  53dbba:	75 27                	jne    0x53dbe3
  53dbbc:	83 0d a4 d9 f8 00 01 	or     DWORD PTR ds:0xf8d9a4,0x1
  53dbc3:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  53dbca:	e8 51 e5 fd ff       	call   0x51c120
  53dbcf:	68 90 cc bc 00       	push   0xbccc90
  53dbd4:	e8 41 47 35 00       	call   0x89231a
  53dbd9:	83 c4 04             	add    esp,0x4
  53dbdc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dbe3:	8b 15 1c d9 f8 00    	mov    edx,DWORD PTR ds:0xf8d91c
  53dbe9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  53dbec:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dbf0:	8b ca                	mov    ecx,edx
  53dbf2:	75 14                	jne    0x53dc08
  53dbf4:	39 70 0c             	cmp    DWORD PTR [eax+0xc],esi
  53dbf7:	7d 05                	jge    0x53dbfe
  53dbf9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  53dbfc:	eb 04                	jmp    0x53dc02
  53dbfe:	8b c8                	mov    ecx,eax
  53dc00:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc02:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dc06:	74 ec                	je     0x53dbf4
  53dc08:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  53dc0b:	3b ca                	cmp    ecx,edx
  53dc0d:	74 0a                	je     0x53dc19
  53dc0f:	3b 71 0c             	cmp    esi,DWORD PTR [ecx+0xc]
  53dc12:	7c 05                	jl     0x53dc19
  53dc14:	8d 45 ec             	lea    eax,[ebp-0x14]
  53dc17:	eb 06                	jmp    0x53dc1f
  53dc19:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53dc1c:	8d 45 e8             	lea    eax,[ebp-0x18]
  53dc1f:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc21:	3b c2                	cmp    eax,edx
  53dc23:	74 48                	je     0x53dc6d
  53dc25:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  53dc28:	85 f6                	test   esi,esi
  53dc2a:	74 41                	je     0x53dc6d
  53dc2c:	f6 05 c0 1a fc 00 01 	test   BYTE PTR ds:0xfc1ac0,0x1
  53dc33:	75 27                	jne    0x53dc5c
  53dc35:	b8 01 00 00 00       	mov    eax,0x1
  53dc3a:	09 05 c0 1a fc 00    	or     DWORD PTR ds:0xfc1ac0,eax
  53dc40:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53dc43:	e8 b8 a4 01 00       	call   0x558100
  53dc48:	68 a0 de bc 00       	push   0xbcdea0
  53dc4d:	e8 c8 46 35 00       	call   0x89231a
  53dc52:	83 c4 04             	add    esp,0x4
  53dc55:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dc5c:	8b 46 20             	mov    eax,DWORD PTR [esi+0x20]
  53dc5f:	50                   	push   eax
  53dc60:	bf c4 1a fc 00       	mov    edi,0xfc1ac4
  53dc65:	e8 96 a5 01 00       	call   0x558200
  53dc6a:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53dc6d:	83 c3 18             	add    ebx,0x18
  53dc70:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53dc73:	0f 85 16 ff ff ff    	jne    0x53db8f
  53dc79:	8b                   	.byte 0x8b
  53dc7a:	4d                   	dec    ebp
```

### Q14 key register: 20個 WORD 與去重滿格 gate

VA `0x00500110..0x00500153`，raw `0x000FF510..0x000FF553`，67 bytes；slice SHA256 `7eae3ef8339a1b6443d88e2ab6b21f71d181be4a78e6931796eb55f30de17b93`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  500110:	33 c0                	xor    eax,eax
  500112:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500118:	53                   	push   ebx
  500119:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500120:	0f b7 19             	movzx  ebx,WORD PTR [ecx]
  500123:	3b de                	cmp    ebx,esi
  500125:	74 2a                	je     0x500151
  500127:	40                   	inc    eax
  500128:	83 c1 02             	add    ecx,0x2
  50012b:	83 f8 14             	cmp    eax,0x14
  50012e:	7c f0                	jl     0x500120
  500130:	33 c0                	xor    eax,eax
  500132:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500138:	66 83 39 00          	cmp    WORD PTR [ecx],0x0
  50013c:	74 0b                	je     0x500149
  50013e:	40                   	inc    eax
  50013f:	83 c1 02             	add    ecx,0x2
  500142:	83 f8 14             	cmp    eax,0x14
  500145:	7c f1                	jl     0x500138
  500147:	5b                   	pop    ebx
  500148:	c3                   	ret
  500149:	66 89 b4 47 d0 5e 00 	mov    WORD PTR [edi+eax*2+0x5ed0],si
  500150:	00 
  500151:	5b                   	pop    ebx
  500152:	c3                   	ret
```

### Q14 非直覺 UI 反證：Mail slot vptr 直接安裝

VA `0x005DF470..0x005DF4CF`，raw `0x001DE870..0x001DE8CF`，95 bytes；slice SHA256 `7c31a5db60110adab2809f9b2ed32cc70c6d43dc47d831daf85db094aabaf5fe`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  5df470:	55                   	push   ebp
  5df471:	8b ec                	mov    ebp,esp
  5df473:	6a ff                	push   0xffffffff
  5df475:	68 38 b5 92 00       	push   0x92b538
  5df47a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5df480:	50                   	push   eax
  5df481:	51                   	push   ecx
  5df482:	56                   	push   esi
  5df483:	57                   	push   edi
  5df484:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5df489:	33 c5                	xor    eax,ebp
  5df48b:	50                   	push   eax
  5df48c:	8d 45 f4             	lea    eax,[ebp-0xc]
  5df48f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5df495:	68 a8 02 00 00       	push   0x2a8
  5df49a:	e8 c9 2b 2b 00       	call   0x892068
  5df49f:	8b f0                	mov    esi,eax
  5df4a1:	83 c4 04             	add    esp,0x4
  5df4a4:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  5df4a7:	33 ff                	xor    edi,edi
  5df4a9:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5df4ac:	3b f7                	cmp    esi,edi
  5df4ae:	74 32                	je     0x5df4e2
  5df4b0:	8b ce                	mov    ecx,esi
  5df4b2:	e8 19 79 ff ff       	call   0x5d6dd0
  5df4b7:	89 be 98 02 00 00    	mov    DWORD PTR [esi+0x298],edi
  5df4bd:	89 be a0 02 00 00    	mov    DWORD PTR [esi+0x2a0],edi
  5df4c3:	89 be a4 02 00 00    	mov    DWORD PTR [esi+0x2a4],edi
  5df4c9:	c7 06 8c 58 c2 00    	mov    DWORD PTR [esi],0xc2588c
```

### Q14 F4266 的 RTTI mail-slot virtual slot

VA `0x005DF3A0..0x005DF3B6`，raw `0x001DE7A0..0x001DE7B6`，22 bytes；slice SHA256 `5e28b851b6c59f1230f9523e30c71f40f4f9d5de113cf36d1b25fc035f9a92fa`。以已知函式入口／局部分支定向核對；切片含任意函式中間起點時不得將第一條錯位解碼當可達指令。

```asm
  5df3a0:	b8 66 42 0f 00       	mov    eax,0xf4266
  5df3a5:	c3                   	ret
  5df3a6:	cc                   	int3
  5df3a7:	cc                   	int3
  5df3a8:	cc                   	int3
  5df3a9:	cc                   	int3
  5df3aa:	cc                   	int3
  5df3ab:	cc                   	int3
  5df3ac:	cc                   	int3
  5df3ad:	cc                   	int3
  5df3ae:	cc                   	int3
  5df3af:	cc                   	int3
  5df3b0:	b8 48 56 c2 00       	mov    eax,0xc25648
  5df3b5:	c3                   	ret
```

## 7. 三輪及「完成」用語修正（不假造新輪次）

- **原有第一輪**：`0x41 -> 0x4B2310 -> 0x53DB30` 完整定長 record 槽資料解析／更新，失配/短長度分支與 F4266 event。
- **原有第二輪**：`0x42 -> 0x4B2190 -> 0x500110 / 0x53D840`，確認20-slot key 去重、entry subtype，及其他 callback 的 competing writer。
- **原有第三輪**：`0x7F -> 0x4B23C0 -> 0x53D5E0` 資料初始化，與 `0x41` 更新路徑於同一 0x14-byte record container 的有界接合及本地 event；本次新增對 0x7F 跳表的來源重算與 mail-slot RTTI 獨立交叉更正。
- **修訂後結案**：Quest14-④ 的「**Client 靜態 S→C 候選資料格式／parser/記錄/UI事件契約分析、未知與 S00 handoff**」有界完成，**不再以缺乏原版 Server trace 當作研究阻塞**；「**Quest14 專屬 S→C opcode/必需欄位與 UI completion 關聯**」仍是具體 Client GAP，不能報「完整封包已確認」。這樣能使 S00 繼續規劃 Server（獨立完成狀態），也保留 T16 需分析的 Client native identity 工作（不以 Server 替代）。

## 8. 來源與歷史保存

以下附錄是**T16-110 最初原稿全文，包含已被本文更正之舊停止理由**。保留是為讓原始機器碼、ABI、步驟、反例與 SHA 可以逐條核對；**如與本文衝突，以上 §1～7 修訂結論為準**，不把附錄歷史措辭當現況。

---

# 附錄 A — T16-110 原始完整技術筆記（歷史未改寫，已被前述修正）

# T16-110 — Quest 14／子研究④：原生 S→C `0x41`、`0x42` 不同更新器、key/狀態容器、通知及證據阻塞（BIN-first，三輪）

- 研究者：chatgpt-web roy。研究時間：`2026-10-30T00:09:58+08:00`，Asia/Taipei。**只研究 Quest 14 的第④子研究**；此研究是 T16-109 的定向加深，不把局部 wire candidate 當實際 Quest14 completion。
- 唯讀原始檔 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。兩個檔案**本輪重新讀取及 SHA 驗證**，未執行客戶端、未修改任一原件、未執行 Server，無 packet capture。
- PE mapping：`.text` VA `0x401000`, raw `0x400`，該段 `raw=VA-0x400C00`；`.rdata` VA `0xBD2000`, raw `0x7D0600`；`.data` VA `0xD61000`, raw `0x95E800`（範圍需檢查 raw size）。x86 反組譯採原始 bytes 定向 GNU `objdump`；不把 Ghidra 推測、Git 摘要或本地 UI 事件常數當真實 wire。
- 開工核對 GitHub `main=43c51f579cada3aa6257eb8467f65af281c3585b`、`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b`；compare ahead 22、behind 0，故 T16 已含 main。T16 inbox 目前無所屬 RR；T01 43 項來源更正為 `READY_FOR_REVIEW` 等待審核，並非 FULL-PASS。`RR-0005` 是 T02 登入/連線工作，**與本研究無關且本次沒有刪改**。使用者本輪指定 Q14-4 優先；未 Commit／Push。
- 權威文件：`02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T16-INSTRUCTIONS.md`；參照 T16-108、T16-109 已下載完整原稿、GitHub 的 43 筆送審及 T16-101/102/105；所有新斷言以本輪原始 BIN 分支驗證。

## 0. 結論、完成判定與不能跳過的阻塞

**本輪新增實質原生證據**：從 Scene 的預設 handler table 找到與既有 `index66→0x4B2190` 平行的 **`index65→0x4B2310`**，其 S→C payload 由 2-byte command word 後的 N 筆 **`(value:u16, record_key:u16)`** 構成；`0x53DB30` 分別在 0x14-byte 和 0x18-byte 結構之 `+0x2` 欄位比對第二 WORD，匹配後將第一 WORD 寫到記錄的 `+0x8`。命中特定 `record+0x4==3` 且索引查找成功時，會走 `0x558200` 輔助佇列分支。`0x4B2310` 在有/無 N 筆資料下都會派發本地事件 `0x000F4266`。

**另一個重要更正**：舊 `index66/0x4B2190` 的 `0x500110` **不是唯一來自 S→C 的 writer**：`0x502270` 的 GUI/查表處理亦能呼叫 `0x500110`，該 callback 註冊於 `0xFAB2A0` **另一組本地 handler table index 64**。單憑 key 清單包含 `14`，無法證明是 Server 宣告 Quest14 完成。

**Q14-4 尚不能完整閉合**：沒有原版 Quest14 結算 S→C payload / opcode / 角色狀態與 Quest14 XML ID 的明確映射，也沒有已證明「該筆更新令 Quest14 完成 UI 與 Quest16 解鎖」的完整實際 caller。`0x41` 與 `0x42` 目前是由 Client 的 **命令表 index + 有條件 S→C 分派鏈**支援的可解析格式；**不是已取得 Quest14 實際封包紀錄**。兩條資料路徑都可能是其他事件或目標的計數/列表，不允許虛構 `41 00 ..` 封包代替 Quest14 完成。所有可由這兩條明確入口追得的 writer、消費者和失敗分支已向下查證；缺少原始 Server/遊玩封包樣本時，Quest14 的特定業務配對遇到不可由本地 bytes 唯一決定的**證據限制**。

**本段正式結果：Quest14-④「Client 通用處理機制：明確進展；Quest14 專用完成狀態：阻塞，未完成」**。不能因三輪已查就標完整完成。

## 1. 五個子研究進度（每次回報使用固定表）

| Quest | ①資源與前置 | ②玩家觸發 | ③C→S 發送 | ④ S→C 回覆、Client state/UI | ⑤完成及解鎖 Quest16 |
|---|---|---|---|---|---|
| **Quest14 教學－伊希莉亞** | **資源已確認**（QuestInfo id14） | 部分（Scenario14 Lua，不等同 Quest14 result） | 部分（0x40 本地 builder） | **本輪研究；共用 S→C `0x41/0x42` 解析確認，Quest14 專屬配對 BLOCKED** | 未閉合 |

版本獨立：`QuestInfo.xml` 的 Quest14 實有 `id=14,type=3,town=0,field=18,level=1,giver=10027,finisher=10027,subtype=1`，`CompleteAction type=1`、`AcceptAction type=1`，**沒有 `<Demands>` 子元素**；這是 T16-108 已透過 GitHub 原 XML 驗證的靜態資源。`QuestTalk.xml` 4322 條無 id14/15/16，並不否定三筆 QuestInfo 存在。`TutorialMain.lua` 使用 `RequestStartScenario(14)` 及 `IsScenarioEnded(14)`：同一數值並不證明 Lua scenario domain 是 QuestInfo domain 或 `0x41` record_key。Quest16 XML `<Demand id=14>` 只證前置宣告，非 Server 實際通知。

## 2. 第一輪 — `0x41` 的 S→C handler：原生索引、逐筆 ABI、兩種記錄更新

### 2.1 分派擔保的是「具條件可能到達」，不是實際封包

- 根據本輪直接 BIN `0x4ADF4D`：在 Scene base callback table 註冊 `[obj+0x20C]=0x4B2310`，`0x20C=4+(65×8)`；同初始化 `0x4ADF3D` 註冊 `[obj+0x214]=0x4B2190`，索引66。`0x4B1BF0` 位在 `0x1C4` 對應索引56，**另外一種 reset/scene 路徑**，不可當 Quest14 finish。
- 已核 T16-109 的 `0x804740` 通用 reader → `0x4930E0` 在 channel 2 且 len 非零時抽 payload 首 WORD → CClient 16-byte callback table (`0x48AAD0`) → 全域 8-byte fallback (`0x4B7EC0`) → current Scene vtable `+4` → `0x4C4670` 表 B 優先、表 A 後備。此段以**已有相同 SHA 原生附錄**復用，不將每條虛擬邊無條件拼成實際執行。Scene 有效／表 B[65或66] 未覆寫、上層 command table 指向 default、連線 channel 2 都是必要條件。不能用 Scene table slot 叫物理封包頭 magic，封包 framing 先在 `0x807B40` 處理。
- 原生 `0x4B2310` `len` 從 `[ebp+0xC]`；`len<2` 取0；否則 `n=floor((len-2)/4)`。從 `payload+2` 逐筆 `movzx ECX,word [ESI]`（**第一WORD**），`mov DX,word [ESI+2]`（**第二WORD**）。`0x40F060` 取得客戶端 owner，再用 owner `+0x4` 作 `0x53DB30` 參數。它是 **(first_word=value, second_word=match_key)**；若反寫為 key/value 就與 `0x53DB30` 的 `DX` 比對方向矛盾。
- 這條 `0x41` 處理器只用整數除法取整後筆數；多出的尾部0～3 bytes 不進該 loop；`len` 過短時仍會進入最後事件 `0x58AAD0(0xF4266)`。**尚未證實** upstream 對超大長度的所有防護，不能將此當安全的完整官方協定規格。

### 2.2 `0x53DB30`：同 key 比對兩類 local records，與 `0x53D840` 不同

本輪下游直接原生指令得：

| Source | key compare | 值 writer | 步長 | 特殊副作用 |
|---|---|---|---|---|
| owner+0x4 object 的 `[+0,+4)` 第一組 | `word [record+0x2] == DX`（第二 WORD） | `word [record+0x8] = [EBP+0xC]`（第一 WORD） | **0x14** | 無本段已證特殊事件 |
| 同 owner `+0x4` 的 `[+0x10,+0x14)` 第二組 | `word [record+0x2] == DX` | `word [record+0x8] = [EBP+0xC]` | **0x18** | 只有 `[record+0x4]==3` 並且特定 tree 查找命中時 `0x558200` 處理 `candidate+0x20`，不能通稱 Quest 完成 UI |

`0x53DB30` 第二組進一步讀 `word [record+0xC]` 查 `[0xF8D91C]` 樹狀索引，再從 payload 取得 `+0x20` 入 `0xFC1AC4` 管理的佇列；任何 tree miss、container empty、type!=3 都不會執行這條附加分支。`0x558200` 在 `0xFC1AC4` 內有 `0x804260` 佇列路徑或配置 0x2C 物件後 enqueue 的分支，所以**不是直接證實的 UI 畫面刷新**。而 `0x4B2310` 最後在另一層呼叫 `0x58AAD0(0x000F4266)`：其本地 event identity 由 `0x5DF3A0: mov eax,0xF4266; ret` 可獨立佐證，仍非網路 opcode。

### 2.3 精確有界 C/C++ 偽碼

```cpp
// 此為 Scene tableA[65] 選中、有效 context 下的 client callback。
// 不表示原版 Server 確實以此方式標記 Quest14 完成。
void SceneCmd65_4B2310(uint8_t* payload, uint32_t len) {
    uint32_t n = (len < 2) ? 0 : (len - 2) / 4;
    auto* p = payload + 2;
    for (uint32_t i = 0; i < n; ++i, p += 4) {
       uint16_t value = read_u16_le(p);
       uint16_t recordKey = read_u16_le(p + 2);
       auto* clientOwner = Obj_40F060();
       UpdateByKey_53DB30(clientOwner->field4, value, recordKey);
    }
    PostLocalEvent_58AAD0(0x000F4266);
}

void UpdateByKey_53DB30(Owner* o, uint16_t value, uint16_t key) {
    for (auto* r = o->records20.begin; r != o->records20.end; r+=20)
      if (r->word2 == key) r->word8 = value;
    for (auto* r = o->records24.begin; r != o->records24.end; r+=24)
      if (r->word2 == key) {
        r->word8 = value;
        if (r->word4 == 3) {
           // only when auxiliary tree lookup resolves a real node:
           MaybeAuxQueue_558200(r->word0C);
        }
      }
}
```

**ABI 注意**：`53DB30` 第二參數即 stack `[EBP+0xC]` 是 value，而 record key 以 **DX 非標準額外寄存器**傳入；`0x4B235B` 才是 `mov dx,word [esi+2]`。實際類型名不明；此偽碼僅重現指令中確定的局部 CFG，未處理真實 SEH / allocation 失敗完整策略。

## 3. 第二輪 — 排除 `0x42` 混同、辨識本地 key 另一 producer

### 3.1 `0x42` 的操作不同於 `0x41`

- `0x4B2190` 是 Scene tableA index66；先由 `[payload+2]` (signed word) 對全域 `0xFAB2A0` 呼叫 `0x500110`。`0x500110` 掃描 `object+0x5ED0` **20 個 WORD**，若 key 已存在返回；若找不到但有空 WORD 槽寫入；滿額無法新增。
- `0x4B2190` 對 `len<=4` 返回（但 **key-list writer 在此 gate 之前已執行**）；其後 `entry[1]` 的 subtype 1..11，10 直接退出，9 跳過 `0x53D840`，其它依 9/10/11/13/15 byte 不等增量 cursor。`0x53D840` 用 `[0xFAB134]` 的 0x18-byte 動態記錄 owner，依 `entry+4` 比對 `record+2`，更新多個欄位，並以 `record+0x14` 保存 message `[payload+2]` key。
- **這個 record owner 是 `[0xFAB134]`；`0x41` 使用 `Obj_40F060()+4` 的雙區段容器。** 兩者可能經其他程式相關，但原生並沒有證明「同一個 Quest14完成 bit」。Index 66 的 `0x42` 本地 key、entry record 的 `0x18` 及 `0x41` 的 `0x14/0x18` 都應保留自己的 object base。
- `0x500E00` 用 `FAB2A0+0x5ED0` 與 `[FAB134]` 0x18 記錄作列表條件過濾；`0x635CA0` 再透過 `0x500950/0x500E00` 的結果非空寫 TalkBox 相關 `+0xB4/+0xB5`。`0x638E60` 讀的是 `[dialog+4]+0xB4/+0xB5` 的子物件而非 `dialog+0xB4`。**單憑共同下游 UI gate 不可把 bool=1 翻成 Quest14 已交付。**

### 3.2 同一 `0x500110` 還有非接收函式 caller（確實為反例）

- 對 `.text` 原始 `E8 rel32` 掃描，`0x500110` 恰有兩個本機直接 callsite：`0x4B2206`（本段 index66）及 **`0x502389`**。有限掃描不能排除其他 virtual/jump caller。
- `0x5020B0` 初始化全域 `0xFAB2A0` owner 的 3029-entry 8-byte callback/context table，初值 callable `0x4B7D40`；`0x5020CF mov [0xFAB4A4],0x502270`，其距 `FAB2A0+4` 為 `0x200`，因此 index64。此表**不是** CClient 16byte 表、也不是 current Scene 指標指向的動態 Scene object 表。- `0x502270` 接到一個獨立的事件/資料記錄 `[arg+0x2]`；在通過 `[arg+4]==0` 等條件後，先透過 `0x58AA50` 生本地 event `0xF4281`、`0xF438B`，接著在 `0x50237C` 取 `word[arg+2]`，於 `0x502389` 以 `ESI=that word, EDI=owner` 呼叫 **同一個 `0x500110`**，再進入 `0x500240` 與 `0x503D20` 本地資料查找。它雖亦為 handler callback，但**是否由網路進入這個 table 尚未證實**，故精確分類為「另一個 callback producer」，不能武斷稱純 UI 人工操作，也不可把 key 當 server-only。
- 由此反證「key list 新增即 S2C 告知完成」的簡化假設。且此 local callback index64 即 `0x40` 並不等於 Lua `RequestStartScenario(14)` 發送 builder WORD `0x40` 的方向／語意。

## 4. 第三輪 — 另一條 Scene record updater `0x7F`、狀態通知的回溯及封包契約界線

- Scene base `0x4ADF5D` 註冊 `[obj+0x3FC]=0x4B23C0`，索引 `(0x3FC-4)/8 = 127 = 0x7F`。`0x4B23C0` 讀 `[data+2]` 變長 entries，依 subtype 1..8 的跳表前進；呼叫 `0x53D5E0` 對 **`Obj_40F060()+4`** 的另一段 **0x14-byte 記錄**建立/更新；後續呼叫本地事件 `0x58AAD0(0xF4266)`。這表示 `0x41` 更新器可作用於一個由另一接收 handler 先建立的容器；但 **不能由這種資料流共用而判定它必然是 Quest14 任務紀錄**。
- `0x53D5E0` 在 `record+0x2` 以 `word[entry+4]` 作 key，建立或選中每條 20-byte record，寫入 `record+0/2/4/6/8/A/10`（不同 subtype 分支有不同欄位），因此 `0x41` 以相同 `record+0x2` 查找及 `+0x8` 更新具已證的 **record-init → progress-update** 共用結構。多個 Scene handler index 分工不等於已配對的伺服器時序；沒有 captures，不可推定 `0x7F` 一定先於 `0x41`。
- `0x4B2310` 和 `0x4B23C0` 各自最後投遞 `0xF4266`，`0x53DA80` reset 函式另投遞 `0xF426F`；這些屬於本地 UI/event bus 訊號。`0x5DF3A0` 以常數返回 `0xF4266` 供本地類型辨識，可當事件存在的獨立交叉驗證，但**真正接收端 listener、畫面哪一欄改、Quest14 完成圖示是否亮**，仍沒有對應的 Quest14 identity writer/consumer。
- `0x53DB30` 的特別 branch 會用記錄 `+0xC` 查 `[0xF8D91C]` 查找表，命中才向 `[0xFC1AC4]` 佇列投遞 `candidate+0x20`。`0x558200` 裡有 `0x804260` 後備/追加和配置 0x2C 的流程，故不能稱這一呼叫「發送 Server ACK」或「UI 已顯示 Quest16」。查不到相應 tree key 不代表該 record 未更新：`+8` writer 在 tree lookup 之前執行。
- 再次核對 `T16-108` 的 `TutorialMain.lua` Part2 `RequestStartScenario(14)`/`IsScenarioEnded(14)` 並無原始 Server result payload、Client 角色 quest writer、真正 NPC UI runtime 對應。`0x14` 是 Lua scenario input；不能把本輪的 16bit key `0x0E`（若有）當作已確認的 Quest14 id。

### 4.1 限定條件封包 / record 格式清單（作逆向測試設計，**不直接發送 Server**）

| 原生下游候選 index | 客戶端 payload 的靜態結構 | 本地效果 | Quest14 狀態 |
|---|---|---|---|
| `0x41` → `0x4B2310` | `[cmd:u16=0x0041][N * (value:u16,recordKey:u16)]`, `N=floor((len-2)/4)` | 兩組 record 搜尋、`+8` writer、`F4266` 事件 | **沒有 Quest14 特定配對** |
| `0x42` → `0x4B2190` | `[cmd:u16=0x0042][key:i16][entries:variable]`；entry subtype 1..11，10退出、9 跳過 writer | register 20-slot key，更新 0x18-entry vector / UI filter候選 | **沒有 Quest14 特定配對** |
| `0x7F` → `0x4B23C0` | `[cmd:u16=0x007F][entries:variable]`；entry subtype 1..8 | update/init 0x14-record list，`F4266` 事件 | **沒有 Quest14 特定配對** |

格式是**在特定 scene handler 被呼叫時**對 `payload` 的解析，並不是宣稱 Server 真的把 Quest14 成功事件送成這些封包；同數字可能在不同方向存在不同含意，亦不可把 transport header `0x1A68/0x0BBB` 當此處的業務索引。

## 5. 錯誤、失敗、反證與一致性檢查

| 條件 | Client 原生路徑 | 對 Quest14-4 的限制 |
|---|---|---|
| `0x4930E0` len=0 或 channel!=2 | 不進 Scene 業務 handler | 不能由 TCP 收到資料推斷 Quest14 更新 |
| Client/global/Scene callback 有 override，或 current Scene null | 默認 index65/66/127 路徑不必然到達 | 需要當次 client state 或全部 writer 證明特定場景的 dispatch table |
| `0x41` 長度不足2或剩餘不足一組4-byte | `n=0`，仍 dispatch `F4266` | event 有發≠Quest14已完成 |
| `0x41` 記錄 key 未找到 | `0x53DB30` 沒有相應 `+8` writer；事件仍可發出 | 訊息存在≠狀態改變 |
| `0x41` 第二組記錄 subtype !=3，或額外 tree miss | `+8` writer可已執行，但不投遞 `[FC1AC4]` 佇列 | 沒出現附加通知≠資料未更新 |
| `0x42` len<=4 | `0x500110` 仍可能寫入 20-slot key，但不建立 record | key 存在≠Quest complete |
| `0x42` subtype9/10 或輸入長度不足 | 9 跳過 record writer，10退出，邊界誤用可能經 error log | 不能補造 S2C 結果、不可稱 serializer 安全 |
| `0x7F` subtype/長度不符 | 跳表型別 gate 或 log，不一定完整建立 0x14 record | 不能假設某個 key 一定存在 |
| `0x500110` 20槽已滿 | 無空位置則不增加；找到同key則 dedup | 需要 role/session 重載時序，非 Server 必然發完可見 |
| `0x502270` 的本地 handler callback 也會填同一 key slot | 只有快照無法判斷 key 是哪條路寫入 | 必須 trace call origin 和實際封包 |
| `IsScenarioEnded(14)` true | Lua 的本地輪詢值 | **不直接表示 QuestInfo id14完成或 Quest16開放** |

## 6. 解除阻塞所需最小證據與驗證工作

**Client 待逆向（仍可對原始 Client 做定向研究，但目前的單一 Q14-4 業務配對受限）：**

1. **最優先**：取得包含成功完成 Scenario14、失敗/退出（若可能）、接回教學、Quest14 狀態更新前後的**同版本原版 Client 收包 trace**：抓每筆已解封 payload、channel、長度與 frame type，在可重現玩家流程中比對差分；若能記錄 `0x4930E0` 中當前指標 + `0x4B2310/0x4B2190/0x4B23C0` 的實際是否執行、owner+0x4 記錄及 `FAB134` 狀態，能直接解開是哪種 message。
2. 對已定位的三個 handler 進行 **instrumented read-only state snapshot（取得授權且不 patch Client）**，抓 byte 並綁定時間戳與 QuestInfo id14 UI：前後比較 0x14/0x18-record key 和 quest map 條目欄位。此操作目前不在此離線環境；若無原版 Server，也可由已核准白箱 harness 提供測試，但測試輸入必須標 `synthetic`，不可稱官方封包。
3. 若第一步無法取得：提供原版 Server 封包 serializer/可靠 KR packet captures，或另行能作原始 Client runtime 觀察的環境。要辨別 `Quest14` 具體業務ID，至少需要客戶端實際該次 UI 觀測與位址斷點對照，或更明確在 BIN 靜態獨立引用 `QuestInfo id14` 的已證 writer/consumer；不能靠 XML 恰有 14 猜。
4. 只在確認 Quest14-specific result writer 後，再由 `0x58AAD0(0xF4266)` 的 listener/刷新 controller 追到 UI 圖示、Npc 10027/Quest16 available。這是下一研究實作與可玩驗收，不屬原版 Server 內部演算法逆向。

**Server 待開發：** 角色範圍 Quest14 狀態機／冪等進度更新、有效 Scenario14 結算觸發、相容下發與失敗分支、重登快照。`0x41/0x42/0x7F` 的結構可當 **Client 可解析候選** 作獨立白箱測試，**不得直接宣告 Quest14 成功封包格式**。原版 Server 內部判定如何寫 DB 並不是 T16 必須還原的規則。

**跨功能待整合：** T02 收發/WSA/IOCP、T07 Scene pointer 與 scene type、T14 scenario 結算，T15 保存，T06 Quest UI 控件、T03 首登。未取得上述同版資料前不能把各 Task 局部進展拼成完整 Quest14 原生結算。

**待遊玩驗證：** 原版客戶端完整完成 Scenario14→Quest14完成→Quest16可接的實際 UI/遊玩尚無驗收數據。

### 最小差分測試方案（明確為測試設計而非已執行測試）

```text
A. 取得原版 Client 進入 Scenario14 前 channel=2 的 scene & callback table snapshot
B. 分別記錄 Scenario14成功、失敗/退出後的 S→C frame + decoded payload
C. 對每筆入站訊息記下 0x4930E0 首WORD、0x4B2310/2190/23C0 hit、0x53DB30/53D840 fields diff
D. 同步記錄 NPC10027／Quest14 UI 的可見結果、Quest16 是否可接
E. 重複一次重登，辨別本地 key list/records 是否為 snapshot 還是通知
F. 只有相同版本、相同前置狀態、差分一致時，才能建立 Quest14-specific 協定 claim；否則列出反例
```

## 7. 三輪查證記錄與停止條件

| Round | 真正執行的工作 | 成果與未閉合 |
|---|---|---|
| 第1輪 T16-110 | 原始 `.text` 註冊表索引65/66及 `0x4B2310→0x53DB30`，重算 ABI / 兩個向量 span / record+8 writer，核對 local F4266 | 取得以往缺少的 0x41 結構、精確 key/value 方向；仍不能稱 Quest14 completed |
| 第2輪 T16-110-2 | 全 `.text` direct E8 xrefs 比較 `0x500110`兩條 caller，沿 0x5020B0/0x502270 逆查本地 table index64；與 0x42/FAB134/500E00 UI filter對照 | 證明 20 key 槽可由另一 callback 更新，推翻「key=server任務完成通知」過度外推 |
| 第3輪 T16-110-3 | 沿 index127 0x4B23C0/53D5E0（相同 owner 20-byte records）→ 0x41 更新器及 0xF4266/0xF426F local event，追 0x558200 附加 queue 的條件分支、數種失敗/空集合情境 | 形成原生 **record 初始化/更新/本地通知** 有界鏈；未找到 Quest14 id/實際結算 response 及 UI consumer identity，故以具體不可驗證的原版 Server/Runtime evidence gap 停止本子研究而非宣告完成 |

**停止正當性：** 使用者要求「完整完成 Quest14-4；除非碰到無法繼續的問題並回報」。本輪已三次沿不同原生候選深入到資料 writer、event queue 和 competing producer；**現階段只有原始 BIN + Event STP + 靜態 QuestInfo，沒有實際原版 Quest14 成功/失敗的 S→C 資料與 memory/GUI 差分**。這些資料不包含 Server 的具體回覆樣本，無法唯一確認 Quest14 專屬 payload/角色完成效果。不能用猜測或補送合成封包宣稱已解決。完整可重現原始 assembly 保存在附錄；取得上述新資料可沿已定位地址精確接續。

## 8. 原始 BIN bytes/disassembly 完整證據（所有列出 slice 皆為本輪獨立驗 hash）

### Scene table registration slot65/66/127

- VA half-open: `0x004ADF1D..0x004ADF6D`; raw `0x000AD31D..0x000AD36D`, bytes `80`, slice SHA256 `6309ed2cf1add0e9c8d9d687ed044413566878288ce42c8ef97777f902a1cda6`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
```

### Client receive channel/first word

- VA half-open: `0x004930E0..0x00493160`; raw `0x000924E0..0x00092560`, bytes `128`, slice SHA256 `5c7e1b4f2e3b2d473c67ec77dec8065f878ea7b70cd20af90cdae11b45ad89ab`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2                   	.byte 0xc2
  49315f:	10                   	.byte 0x10
```

### Scene 8-byte dispatcher

- VA half-open: `0x004C4670..0x004C46F0`; raw `0x000C3A70..0x000C3AF0`, bytes `128`, slice SHA256 `2deecc04ff570b803612ebcd2157d86b0659367b80cc081f6a10de1a9c8c5223`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
```

### Scene base table fallback

- VA half-open: `0x004FDA30..0x004FDAB0`; raw `0x000FCE30..0x000FCEB0`, bytes `128`, slice SHA256 `8971f7efd3f376924501e28533aedd383ac11425ad7554d3d7bd880839e73b74`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
```

### Scene cmd 65 / 0x0041 handler

- VA half-open: `0x004B2310..0x004B23BE`; raw `0x000B1710..0x000B17BE`, bytes `174`, slice SHA256 `f4da15c719acf725cfd54a32e28ec98383ce731061b61183136d94817d2f1182`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4b2310:	55                   	push   ebp
  4b2311:	8b ec                	mov    ebp,esp
  4b2313:	6a ff                	push   0xffffffff
  4b2315:	68 7e c7 93 00       	push   0x93c77e
  4b231a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2320:	50                   	push   eax
  4b2321:	56                   	push   esi
  4b2322:	57                   	push   edi
  4b2323:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2328:	33 c5                	xor    eax,ebp
  4b232a:	50                   	push   eax
  4b232b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b232e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2334:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b2337:	83 f8 02             	cmp    eax,0x2
  4b233a:	73 04                	jae    0x4b2340
  4b233c:	33 ff                	xor    edi,edi
  4b233e:	eb 06                	jmp    0x4b2346
  4b2340:	8d 78 fe             	lea    edi,[eax-0x2]
  4b2343:	c1 ef 02             	shr    edi,0x2
  4b2346:	85 ff                	test   edi,edi
  4b2348:	74 22                	je     0x4b236c
  4b234a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b234d:	83 c6 02             	add    esi,0x2
  4b2350:	e8 0b cd f5 ff       	call   0x40f060
  4b2355:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  4b2358:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b235b:	66 8b 56 02          	mov    dx,WORD PTR [esi+0x2]
  4b235f:	51                   	push   ecx
  4b2360:	50                   	push   eax
  4b2361:	e8 ca b7 08 00       	call   0x53db30
  4b2366:	83 c6 04             	add    esi,0x4
  4b2369:	4f                   	dec    edi
  4b236a:	75 e4                	jne    0x4b2350
  4b236c:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2373:	75 27                	jne    0x4b239c
  4b2375:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b237c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2383:	e8 f8 50 0d 00       	call   0x587480
  4b2388:	68 c0 cc bc 00       	push   0xbcccc0
  4b238d:	e8 88 ff 3d 00       	call   0x89231a
  4b2392:	83 c4 04             	add    esp,0x4
  4b2395:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b239c:	68 66 42 0f 00       	push   0xf4266
  4b23a1:	e8 2a 87 0d 00       	call   0x58aad0
  4b23a6:	83 c4 04             	add    esp,0x4
  4b23a9:	33 c0                	xor    eax,eax
  4b23ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b23ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b23b5:	59                   	pop    ecx
  4b23b6:	5f                   	pop    edi
  4b23b7:	5e                   	pop    esi
  4b23b8:	8b e5                	mov    esp,ebp
  4b23ba:	5d                   	pop    ebp
  4b23bb:	c2 0c 00             	ret    0xc
```

### 20/24-byte record progress writer

- VA half-open: `0x0053DB30..0x0053DC8B`; raw `0x0013CF30..0x0013D08B`, bytes `347`, slice SHA256 `ccfedccca810f72c748c4b1855c1038ef4e9befa4367dd7d74705d9a81bfc0c2`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  53db30:	55                   	push   ebp
  53db31:	8b ec                	mov    ebp,esp
  53db33:	6a ff                	push   0xffffffff
  53db35:	68 6c a2 93 00       	push   0x93a26c
  53db3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53db40:	50                   	push   eax
  53db41:	83 ec 0c             	sub    esp,0xc
  53db44:	53                   	push   ebx
  53db45:	56                   	push   esi
  53db46:	57                   	push   edi
  53db47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53db4c:	33 c5                	xor    eax,ebp
  53db4e:	50                   	push   eax
  53db4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  53db52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53db58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53db5b:	8b 07                	mov    eax,DWORD PTR [edi]
  53db5d:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db60:	74 1b                	je     0x53db7d
  53db62:	0f bf ca             	movsx  ecx,dx
  53db65:	0f b7 70 02          	movzx  esi,WORD PTR [eax+0x2]
  53db69:	3b f1                	cmp    esi,ecx
  53db6b:	75 08                	jne    0x53db75
  53db6d:	66 8b 75 0c          	mov    si,WORD PTR [ebp+0xc]
  53db71:	66 89 70 08          	mov    WORD PTR [eax+0x8],si
  53db75:	83 c0 14             	add    eax,0x14
  53db78:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  53db7b:	75 e8                	jne    0x53db65
  53db7d:	8b 5f 10             	mov    ebx,DWORD PTR [edi+0x10]
  53db80:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53db83:	0f 84 f0 00 00 00    	je     0x53dc79
  53db89:	0f bf c2             	movsx  eax,dx
  53db8c:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  53db8f:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  53db93:	3b 4d f0             	cmp    ecx,DWORD PTR [ebp-0x10]
  53db96:	0f 85 d1 00 00 00    	jne    0x53dc6d
  53db9c:	66 83 7b 04 03       	cmp    WORD PTR [ebx+0x4],0x3
  53dba1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  53dba5:	66 89 53 08          	mov    WORD PTR [ebx+0x8],dx
  53dba9:	0f 85 be 00 00 00    	jne    0x53dc6d
  53dbaf:	f6 05 a4 d9 f8 00 01 	test   BYTE PTR ds:0xf8d9a4,0x1
  53dbb6:	0f b7 73 0c          	movzx  esi,WORD PTR [ebx+0xc]
  53dbba:	75 27                	jne    0x53dbe3
  53dbbc:	83 0d a4 d9 f8 00 01 	or     DWORD PTR ds:0xf8d9a4,0x1
  53dbc3:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  53dbca:	e8 51 e5 fd ff       	call   0x51c120
  53dbcf:	68 90 cc bc 00       	push   0xbccc90
  53dbd4:	e8 41 47 35 00       	call   0x89231a
  53dbd9:	83 c4 04             	add    esp,0x4
  53dbdc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dbe3:	8b 15 1c d9 f8 00    	mov    edx,DWORD PTR ds:0xf8d91c
  53dbe9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  53dbec:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dbf0:	8b ca                	mov    ecx,edx
  53dbf2:	75 14                	jne    0x53dc08
  53dbf4:	39 70 0c             	cmp    DWORD PTR [eax+0xc],esi
  53dbf7:	7d 05                	jge    0x53dbfe
  53dbf9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  53dbfc:	eb 04                	jmp    0x53dc02
  53dbfe:	8b c8                	mov    ecx,eax
  53dc00:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc02:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  53dc06:	74 ec                	je     0x53dbf4
  53dc08:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  53dc0b:	3b ca                	cmp    ecx,edx
  53dc0d:	74 0a                	je     0x53dc19
  53dc0f:	3b 71 0c             	cmp    esi,DWORD PTR [ecx+0xc]
  53dc12:	7c 05                	jl     0x53dc19
  53dc14:	8d 45 ec             	lea    eax,[ebp-0x14]
  53dc17:	eb 06                	jmp    0x53dc1f
  53dc19:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53dc1c:	8d 45 e8             	lea    eax,[ebp-0x18]
  53dc1f:	8b 00                	mov    eax,DWORD PTR [eax]
  53dc21:	3b c2                	cmp    eax,edx
  53dc23:	74 48                	je     0x53dc6d
  53dc25:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  53dc28:	85 f6                	test   esi,esi
  53dc2a:	74 41                	je     0x53dc6d
  53dc2c:	f6 05 c0 1a fc 00 01 	test   BYTE PTR ds:0xfc1ac0,0x1
  53dc33:	75 27                	jne    0x53dc5c
  53dc35:	b8 01 00 00 00       	mov    eax,0x1
  53dc3a:	09 05 c0 1a fc 00    	or     DWORD PTR ds:0xfc1ac0,eax
  53dc40:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53dc43:	e8 b8 a4 01 00       	call   0x558100
  53dc48:	68 a0 de bc 00       	push   0xbcdea0
  53dc4d:	e8 c8 46 35 00       	call   0x89231a
  53dc52:	83 c4 04             	add    esp,0x4
  53dc55:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53dc5c:	8b 46 20             	mov    eax,DWORD PTR [esi+0x20]
  53dc5f:	50                   	push   eax
  53dc60:	bf c4 1a fc 00       	mov    edi,0xfc1ac4
  53dc65:	e8 96 a5 01 00       	call   0x558200
  53dc6a:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53dc6d:	83 c3 18             	add    ebx,0x18
  53dc70:	3b 5f 14             	cmp    ebx,DWORD PTR [edi+0x14]
  53dc73:	0f 85 16 ff ff ff    	jne    0x53db8f
  53dc79:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  53dc7c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  53dc83:	59                   	pop    ecx
  53dc84:	5f                   	pop    edi
  53dc85:	5e                   	pop    esi
  53dc86:	5b                   	pop    ebx
  53dc87:	8b e5                	mov    esp,ebp
  53dc89:	5d                   	pop    ebp
  53dc8a:	c2                   	.byte 0xc2
```

### Aux event queue append and allocation

- VA half-open: `0x00558200..0x005582A8`; raw `0x00157600..0x001576A8`, bytes `168`, slice SHA256 `2beaac90a9648368137427ff2c8081ec86273138bdc3f7f18b5985e6ad9fbea3`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  558200:	55                   	push   ebp
  558201:	8b ec                	mov    ebp,esp
  558203:	51                   	push   ecx
  558204:	83 7f 24 00          	cmp    DWORD PTR [edi+0x24],0x0
  558208:	56                   	push   esi
  558209:	7e 13                	jle    0x55821e
  55820b:	8d 45 08             	lea    eax,[ebp+0x8]
  55820e:	50                   	push   eax
  55820f:	8d 77 0c             	lea    esi,[edi+0xc]
  558212:	e8 49 c0 2a 00       	call   0x804260
  558217:	5e                   	pop    esi
  558218:	8b e5                	mov    esp,ebp
  55821a:	5d                   	pop    ebp
  55821b:	c2 04 00             	ret    0x4
  55821e:	6a 2c                	push   0x2c
  558220:	c7 47 24 12 00 00 00 	mov    DWORD PTR [edi+0x24],0x12
  558227:	e8 3c 90 33 00       	call   0x891268
  55822c:	83 c4 04             	add    esp,0x4
  55822f:	85 c0                	test   eax,eax
  558231:	74 47                	je     0x55827a
  558233:	0f 57 c0             	xorps  xmm0,xmm0
  558236:	f3 0f 10 0d 10 59 c5 	movss  xmm1,DWORD PTR ds:0xc55910
  55823d:	00 
  55823e:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  558244:	f3 0f 11 40 0c       	movss  DWORD PTR [eax+0xc],xmm0
  558249:	f3 0f 11 40 10       	movss  DWORD PTR [eax+0x10],xmm0
  55824e:	f3 0f 11 40 14       	movss  DWORD PTR [eax+0x14],xmm0
  558253:	f3 0f 11 48 18       	movss  DWORD PTR [eax+0x18],xmm1
  558258:	f3 0f 11 40 1c       	movss  DWORD PTR [eax+0x1c],xmm0
  55825d:	f3 0f 10 05 e8 56 c5 	movss  xmm0,DWORD PTR ds:0xc556e8
  558264:	00 
  558265:	f3 0f 11 40 20       	movss  DWORD PTR [eax+0x20],xmm0
  55826a:	c7 40 24 23 00 00 00 	mov    DWORD PTR [eax+0x24],0x23
  558271:	c7 40 28 00 00 00 00 	mov    DWORD PTR [eax+0x28],0x0
  558278:	eb 02                	jmp    0x55827c
  55827a:	33 c0                	xor    eax,eax
  55827c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55827f:	51                   	push   ecx
  558280:	50                   	push   eax
  558281:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  558284:	e8 87 fb ff ff       	call   0x557e10
  558289:	8b 37                	mov    esi,DWORD PTR [edi]
  55828b:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  55828e:	8d 55 fc             	lea    edx,[ebp-0x4]
  558291:	52                   	push   edx
  558292:	50                   	push   eax
  558293:	56                   	push   esi
  558294:	e8 67 54 1f 00       	call   0x74d700
  558299:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  55829c:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  5582a1:	2b d1                	sub    edx,ecx
  5582a3:	83 fa 01             	cmp    edx,0x1
  5582a6:	73 0a                	jae    0x5582b2
```

### Aux queue cleanup/processor

- VA half-open: `0x00558590..0x005585EC`; raw `0x00157990..0x001579EC`, bytes `92`, slice SHA256 `1eeaf08c0bf10f8654423cd86ff58a79a0084228acd0a06dfa57ee6ecba3097c`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  558590:	e8 1b 00 00 00       	call   0x5585b0
  558595:	a1 c4 1a fc 00       	mov    eax,ds:0xfc1ac4
  55859a:	50                   	push   eax
  55859b:	e8 6c 8c 33 00       	call   0x89120c
  5585a0:	59                   	pop    ecx
  5585a1:	c3                   	ret
  5585a2:	cc                   	int3
  5585a3:	cc                   	int3
  5585a4:	cc                   	int3
  5585a5:	cc                   	int3
  5585a6:	cc                   	int3
  5585a7:	cc                   	int3
  5585a8:	cc                   	int3
  5585a9:	cc                   	int3
  5585aa:	cc                   	int3
  5585ab:	cc                   	int3
  5585ac:	cc                   	int3
  5585ad:	cc                   	int3
  5585ae:	cc                   	int3
  5585af:	cc                   	int3
  5585b0:	8b 0d c4 1a fc 00    	mov    ecx,DWORD PTR ds:0xfc1ac4
  5585b6:	8b 01                	mov    eax,DWORD PTR [ecx]
  5585b8:	89 09                	mov    DWORD PTR [ecx],ecx
  5585ba:	8b 0d c4 1a fc 00    	mov    ecx,DWORD PTR ds:0xfc1ac4
  5585c0:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  5585c3:	c7 05 c8 1a fc 00 00 	mov    DWORD PTR ds:0xfc1ac8,0x0
  5585ca:	00 00 00 
  5585cd:	3b 05 c4 1a fc 00    	cmp    eax,DWORD PTR ds:0xfc1ac4
  5585d3:	74 17                	je     0x5585ec
  5585d5:	56                   	push   esi
  5585d6:	8b 30                	mov    esi,DWORD PTR [eax]
  5585d8:	50                   	push   eax
  5585d9:	e8 2e 8c 33 00       	call   0x89120c
  5585de:	83 c4 04             	add    esp,0x4
  5585e1:	8b c6                	mov    eax,esi
  5585e3:	3b 35 c4 1a fc 00    	cmp    esi,DWORD PTR ds:0xfc1ac4
  5585e9:	75 eb                	jne    0x5585d6
  5585eb:	5e                   	pop    esi
```

### Scene cmd 66 / 0x0042 handler

- VA half-open: `0x004B2190..0x004B22D5`; raw `0x000B1590..0x000B16D5`, bytes `325`, slice SHA256 `1aa57867ef8d07d2a76bf8a0b46f44da57721a29f0178538fb8683c875511907`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
```

### 20-slot key list duplicate and full gates

- VA half-open: `0x00500110..0x00500153`; raw `0x000FF510..0x000FF553`, bytes `67`, slice SHA256 `7eae3ef8339a1b6443d88e2ab6b21f71d181be4a78e6931796eb55f30de17b93`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  500110:	33 c0                	xor    eax,eax
  500112:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500118:	53                   	push   ebx
  500119:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500120:	0f b7 19             	movzx  ebx,WORD PTR [ecx]
  500123:	3b de                	cmp    ebx,esi
  500125:	74 2a                	je     0x500151
  500127:	40                   	inc    eax
  500128:	83 c1 02             	add    ecx,0x2
  50012b:	83 f8 14             	cmp    eax,0x14
  50012e:	7c f0                	jl     0x500120
  500130:	33 c0                	xor    eax,eax
  500132:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500138:	66 83 39 00          	cmp    WORD PTR [ecx],0x0
  50013c:	74 0b                	je     0x500149
  50013e:	40                   	inc    eax
  50013f:	83 c1 02             	add    ecx,0x2
  500142:	83 f8 14             	cmp    eax,0x14
  500145:	7c f1                	jl     0x500138
  500147:	5b                   	pop    ebx
  500148:	c3                   	ret
  500149:	66 89 b4 47 d0 5e 00 	mov    WORD PTR [edi+eax*2+0x5ed0],si
  500150:	00 
  500151:	5b                   	pop    ebx
  500152:	c3                   	ret
```

### Quest-related owner callback table registration

- VA half-open: `0x005020B0..0x0050214B`; raw `0x001014B0..0x0010154B`, bytes `155`, slice SHA256 `7073c50506cb3cc426e96a2ec5334c8164671294e9c57c127c372180bddfa9b5`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  5020b0:	b8 a8 b2 fa 00       	mov    eax,0xfab2a8
  5020b5:	ba 40 7d 4b 00       	mov    edx,0x4b7d40
  5020ba:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  5020bf:	90                   	nop
  5020c0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  5020c3:	89 08                	mov    DWORD PTR [eax],ecx
  5020c5:	83 c0 08             	add    eax,0x8
  5020c8:	3d 50 11 fb 00       	cmp    eax,0xfb1150
  5020cd:	7c f1                	jl     0x5020c0
  5020cf:	c7 05 a4 b4 fa 00 70 	mov    DWORD PTR ds:0xfab4a4,0x502270
  5020d6:	22 50 00 
  5020d9:	89 0d a8 b4 fa 00    	mov    DWORD PTR ds:0xfab4a8,ecx
  5020df:	89 15 9c b4 fa 00    	mov    DWORD PTR ds:0xfab49c,edx
  5020e5:	89 0d a0 b4 fa 00    	mov    DWORD PTR ds:0xfab4a0,ecx
  5020eb:	c7 05 cc b4 fa 00 d0 	mov    DWORD PTR ds:0xfab4cc,0x5027d0
  5020f2:	27 50 00 
  5020f5:	89 0d d0 b4 fa 00    	mov    DWORD PTR ds:0xfab4d0,ecx
  5020fb:	c7 05 d4 b4 fa 00 40 	mov    DWORD PTR ds:0xfab4d4,0x502b40
  502102:	2b 50 00 
  502105:	89 0d d8 b4 fa 00    	mov    DWORD PTR ds:0xfab4d8,ecx
  50210b:	c7 05 dc b4 fa 00 40 	mov    DWORD PTR ds:0xfab4dc,0x503040
  502112:	30 50 00 
  502115:	89 0d e0 b4 fa 00    	mov    DWORD PTR ds:0xfab4e0,ecx
  50211b:	c7 05 c4 b5 fa 00 c0 	mov    DWORD PTR ds:0xfab5c4,0x5030c0
  502122:	30 50 00 
  502125:	89 0d c8 b5 fa 00    	mov    DWORD PTR ds:0xfab5c8,ecx
  50212b:	c7 05 cc b5 fa 00 d0 	mov    DWORD PTR ds:0xfab5cc,0x5035d0
  502132:	35 50 00 
  502135:	89 0d d0 b5 fa 00    	mov    DWORD PTR ds:0xfab5d0,ecx
  50213b:	c7 05 1c b6 fa 00 70 	mov    DWORD PTR ds:0xfab61c,0x502170
  502142:	21 50 00 
  502145:	89 0d 20 b6 fa 00    	mov    DWORD PTR ds:0xfab620,ecx
```

### Alternative callback local-event and key-list writer

- VA half-open: `0x00502270..0x00502400`; raw `0x00101670..0x00101800`, bytes `400`, slice SHA256 `6806614581eb8f2da31120882b99bc958375fd33b58b691b18196855963dbaa2`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  502270:	55                   	push   ebp
  502271:	8b ec                	mov    ebp,esp
  502273:	6a ff                	push   0xffffffff
  502275:	68 a8 41 94 00       	push   0x9441a8
  50227a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502280:	50                   	push   eax
  502281:	81 ec a4 00 00 00    	sub    esp,0xa4
  502287:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50228c:	33 c5                	xor    eax,ebp
  50228e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  502291:	53                   	push   ebx
  502292:	56                   	push   esi
  502293:	57                   	push   edi
  502294:	50                   	push   eax
  502295:	8d 45 f4             	lea    eax,[ebp-0xc]
  502298:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50229e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5022a1:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  5022a4:	33 ff                	xor    edi,edi
  5022a6:	89 8d 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],ecx
  5022ac:	3b c7                	cmp    eax,edi
  5022ae:	0f 85 16 04 00 00    	jne    0x5026ca
  5022b4:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5022bb:	75 24                	jne    0x5022e1
  5022bd:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  5022c4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5022c7:	e8 b4 51 08 00       	call   0x587480
  5022cc:	68 c0 cc bc 00       	push   0xbcccc0
  5022d1:	e8 44 00 39 00       	call   0x89231a
  5022d6:	83 c4 04             	add    esp,0x4
  5022d9:	83 ce ff             	or     esi,0xffffffff
  5022dc:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5022df:	eb 03                	jmp    0x5022e4
  5022e1:	83 ce ff             	or     esi,0xffffffff
  5022e4:	6a 18                	push   0x18
  5022e6:	e8 7d ef 38 00       	call   0x891268
  5022eb:	83 c4 04             	add    esp,0x4
  5022ee:	3b c7                	cmp    eax,edi
  5022f0:	74 1e                	je     0x502310
  5022f2:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  5022f5:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5022f8:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5022fb:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5022fe:	c7 40 10 81 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4281
  502305:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50230b:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  50230e:	eb 02                	jmp    0x502312
  502310:	33 c0                	xor    eax,eax
  502312:	50                   	push   eax
  502313:	e8 38 87 08 00       	call   0x58aa50
  502318:	83 c4 04             	add    esp,0x4
  50231b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502322:	75 23                	jne    0x502347
  502324:	b8 01 00 00 00       	mov    eax,0x1
  502329:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
  502355:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  502359:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  50235c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  50235f:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  502362:	c7 40 10 8b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438b
  502369:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50236f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502372:	eb 02                	jmp    0x502376
  502374:	33 c0                	xor    eax,eax
  502376:	50                   	push   eax
  502377:	e8 d4 86 08 00       	call   0x58aa50
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5023b2:	50                   	push   eax
  5023b3:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5023b9:	8b ce                	mov    ecx,esi
  5023bb:	89 bd 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],edi
  5023c1:	e8 5a 19 00 00       	call   0x503d20
  5023c6:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5023c9:	8b 85 50 ff ff ff    	mov    eax,DWORD PTR [ebp-0xb0]
  5023cf:	3b c6                	cmp    eax,esi
  5023d1:	0f 84 d5 03 00 00    	je     0x5027ac
  5023d7:	8d 58 10             	lea    ebx,[eax+0x10]
  5023da:	85 db                	test   ebx,ebx
  5023dc:	0f 84 ca 03 00 00    	je     0x5027ac
  5023e2:	8b 43 3c             	mov    eax,DWORD PTR [ebx+0x3c]
  5023e5:	83 e8 02             	sub    eax,0x2
  5023e8:	74 51                	je     0x50243b
  5023ea:	48                   	dec    eax
  5023eb:	75 5f                	jne    0x50244c
  5023ed:	e8 ce 30 f0 ff       	call   0x4054c0
  5023f2:	6a 18                	push   0x18
  5023f4:	e8 6f ee 38 00       	call   0x891268
  5023f9:	83 c4 04             	add    esp,0x4
  5023fc:	85 c0                	test   eax,eax
  5023fe:	74 2e                	je     0x50242e
```

### 0x18-record parser main fields

- VA half-open: `0x0053D840..0x0053D93A`; raw `0x0013CC40..0x0013CD3A`, bytes `250`, slice SHA256 `eafaef04bce5d550f0bb5cacb5d8254dd075225e4c4a7311dfe423dc35023b1e`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81 c9 00 01 00 00    	or     ecx,0x100
  53d92a:	c1 e1 10             	shl    ecx,0x10
  53d92d:	0b ca                	or     ecx,edx
  53d92f:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d932:	5f                   	pop    edi
  53d933:	5b                   	pop    ebx
  53d934:	8b e5                	mov    esp,ebp
  53d936:	5d                   	pop    ebp
  53d937:	c2 08 00             	ret    0x8
```

### Quest filter gated record+14 lookup

- VA half-open: `0x00500E56..0x00500F65`; raw `0x00100256..0x00100365`, bytes `271`, slice SHA256 `ad1a8a64f833f53960a7ff4f3792df4aa5c465aa3475e11582c0c8973514e27d`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  500e56:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500e59:	05 d0 5e 00 00       	add    eax,0x5ed0
  500e5e:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  500e62:	c7 44 24 14 14 00 00 	mov    DWORD PTR [esp+0x14],0x14
  500e69:	00 
  500e6a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  500e6e:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  500e71:	66 85 ff             	test   di,di
  500e74:	0f 84 e4 00 00 00    	je     0x500f5e
  500e7a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  500e7d:	8b b2 ac 5e 00 00    	mov    esi,DWORD PTR [edx+0x5eac]
  500e83:	8d 44 24 18          	lea    eax,[esp+0x18]
  500e87:	0f bf df             	movsx  ebx,di
  500e8a:	50                   	push   eax
  500e8b:	8d 44 24 20          	lea    eax,[esp+0x20]
  500e8f:	8b ce                	mov    ecx,esi
  500e91:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500e95:	e8 86 2e 00 00       	call   0x503d20
  500e9a:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  500e9d:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  500ea1:	3b c6                	cmp    eax,esi
  500ea3:	0f 84 b5 00 00 00    	je     0x500f5e
  500ea9:	83 c0 10             	add    eax,0x10
  500eac:	0f 84 ac 00 00 00    	je     0x500f5e
  500eb2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  500eb5:	39 48 2c             	cmp    DWORD PTR [eax+0x2c],ecx
  500eb8:	0f 85 a0 00 00 00    	jne    0x500f5e
  500ebe:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  500ec5:	75 29                	jne    0x500ef0
  500ec7:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  500ece:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  500ed5:	00 
  500ed6:	e8 b5 dd fd ff       	call   0x4dec90
  500edb:	68 30 ce bc 00       	push   0xbcce30
  500ee0:	e8 35 14 39 00       	call   0x89231a
  500ee5:	83 c4 04             	add    esp,0x4
  500ee8:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  500eef:	ff 
  500ef0:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  500ef5:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  500ef8:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  500efb:	3b c1                	cmp    eax,ecx
  500efd:	74 18                	je     0x500f17
  500eff:	90                   	nop
  500f00:	66 39 78 14          	cmp    WORD PTR [eax+0x14],di
  500f04:	75 0a                	jne    0x500f10
  500f06:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  500f0a:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  500f0e:	7c 4e                	jl     0x500f5e
  500f10:	83 c0 18             	add    eax,0x18
  500f13:	3b c1                	cmp    eax,ecx
  500f15:	75 e9                	jne    0x500f00
  500f17:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500f1a:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  500f20:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  500f24:	51                   	push   ecx
  500f25:	8d 44 24 24          	lea    eax,[esp+0x24]
  500f29:	8b ce                	mov    ecx,esi
  500f2b:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500f2f:	e8 ec 2d 00 00       	call   0x503d20
  500f34:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500f38:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500f3b:	74 05                	je     0x500f42
  500f3d:	83 c0 10             	add    eax,0x10
  500f40:	eb 02                	jmp    0x500f44
  500f42:	33 c0                	xor    eax,eax
  500f44:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  500f48:	85 c0                	test   eax,eax
  500f4a:	74 12                	je     0x500f5e
  500f4c:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500f50:	74 0c                	je     0x500f5e
  500f52:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500f55:	8d 44 24 18          	lea    eax,[esp+0x18]
  500f59:	e8 b2 2d f4 ff       	call   0x443d10
  500f5e:	83 44 24 10 02       	add    DWORD PTR [esp+0x10],0x2
  500f63:	ff                   	.byte 0xff
  500f64:	4c                   	dec    esp
```

### Dialog vector flags consumer

- VA half-open: `0x00635CA0..0x00635E40`; raw `0x002350A0..0x00235240`, bytes `416`, slice SHA256 `1fa87269a7dade8b75541a046d613e8a2086c20b6322407c486f59495cb67815`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  635ca0:	55                   	push   ebp
  635ca1:	8b ec                	mov    ebp,esp
  635ca3:	6a ff                	push   0xffffffff
  635ca5:	68 04 8a 94 00       	push   0x948a04
  635caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  635cb0:	50                   	push   eax
  635cb1:	83 ec 40             	sub    esp,0x40
  635cb4:	53                   	push   ebx
  635cb5:	56                   	push   esi
  635cb6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  635cbb:	33 c5                	xor    eax,ebp
  635cbd:	50                   	push   eax
  635cbe:	8d 45 f4             	lea    eax,[ebp-0xc]
  635cc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  635cea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635cee:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635cf5:	75 21                	jne    0x635d18
  635cf7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635cfe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  635d02:	e8 59 a1 ec ff       	call   0x4ffe60
  635d07:	68 00 cf bc 00       	push   0xbccf00
  635d0c:	e8 09 c6 25 00       	call   0x89231a
  635d11:	83 c4 04             	add    esp,0x4
  635d14:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635d34:	75 21                	jne    0x635d57
  635d36:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635d3d:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  635d41:	e8 1a a1 ec ff       	call   0x4ffe60
  635d46:	68 00 cf bc 00       	push   0xbccf00
  635d4b:	e8 ca c5 25 00       	call   0x89231a
  635d50:	83 c4 04             	add    esp,0x4
  635d53:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
  635d8a:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  635d8d:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635d90:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  635d93:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  635d97:	8b 87 b8 00 00 00    	mov    eax,DWORD PTR [edi+0xb8]
  635d9d:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  635da0:	2b 48 40             	sub    ecx,DWORD PTR [eax+0x40]
  635da3:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  635da8:	f7 e9                	imul   ecx
  635daa:	c1 fa 03             	sar    edx,0x3
  635dad:	8b c2                	mov    eax,edx
  635daf:	c1 e8 1f             	shr    eax,0x1f
  635db2:	03 c2                	add    eax,edx
  635db4:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  635db7:	0f 84 82 00 00 00    	je     0x635e3f
  635dbd:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  635dc0:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  635dc3:	8b 97 b8 00 00 00    	mov    edx,DWORD PTR [edi+0xb8]
  635dc9:	8b 5a 40             	mov    ebx,DWORD PTR [edx+0x40]
  635dcc:	03 5d ec             	add    ebx,DWORD PTR [ebp-0x14]
  635dcf:	53                   	push   ebx
  635dd0:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  635dd3:	e8 c8 e5 ee ff       	call   0x5243a0
  635dd8:	85 c0                	test   eax,eax
  635dda:	74 5a                	je     0x635e36
  635ddc:	8b 03                	mov    eax,DWORD PTR [ebx]
  635dde:	39 45 e8             	cmp    DWORD PTR [ebp-0x18],eax
  635de1:	7d 03                	jge    0x635de6
  635de3:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  635de6:	8d 45 f0             	lea    eax,[ebp-0x10]
  635de9:	3b c6                	cmp    eax,esi
  635deb:	73 2d                	jae    0x635e1a
  635ded:	8b c8                	mov    ecx,eax
  635def:	39 4d d4             	cmp    DWORD PTR [ebp-0x2c],ecx
  635df2:	77 26                	ja     0x635e1a
  635df4:	8b d8                	mov    ebx,eax
  635df6:	2b 5d d4             	sub    ebx,DWORD PTR [ebp-0x2c]
  635df9:	c1 fb 02             	sar    ebx,0x2
  635dfc:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635dff:	75 0b                	jne    0x635e0c
  635e01:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e04:	e8 a7 8c ea ff       	call   0x4deab0
  635e09:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e0c:	85 f6                	test   esi,esi
  635e0e:	74 20                	je     0x635e30
  635e10:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  635e13:	8b 04 9a             	mov    eax,DWORD PTR [edx+ebx*4]
  635e16:	89 06                	mov    DWORD PTR [esi],eax
  635e18:	eb 16                	jmp    0x635e30
  635e1a:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635e1d:	75 0b                	jne    0x635e2a
  635e1f:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e22:	e8 89 8c ea ff       	call   0x4deab0
  635e27:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e2a:	85 f6                	test   esi,esi
  635e2c:	74 02                	je     0x635e30
  635e2e:	89 1e                	mov    DWORD PTR [esi],ebx
  635e30:	83 c6 04             	add    esi,0x4
  635e33:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635e36:	83 45 ec 24          	add    DWORD PTR [ebp-0x14],0x24
  635e3a:	ff 4d e4             	dec    DWORD PTR [ebp-0x1c]
  635e3d:	75 84                	jne    0x635dc3
  635e3f:	8b                   	.byte 0x8b
```

### Scene cmd 127/0x7f record-init handler

- VA half-open: `0x004B23C0..0x004B24CC`; raw `0x000B17C0..0x000B18CC`, bytes `268`, slice SHA256 `553202dfad5be11603a53b66103e3a8bcfdd5d80e75c16626562bba0f3720f5c`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  4b23c0:	55                   	push   ebp
  4b23c1:	8b ec                	mov    ebp,esp
  4b23c3:	6a ff                	push   0xffffffff
  4b23c5:	68 de 54 94 00       	push   0x9454de
  4b23ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b23d0:	50                   	push   eax
  4b23d1:	53                   	push   ebx
  4b23d2:	56                   	push   esi
  4b23d3:	57                   	push   edi
  4b23d4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b23d9:	33 c5                	xor    eax,ebp
  4b23db:	50                   	push   eax
  4b23dc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b23df:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b23e5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b23e8:	be 02 00 00 00       	mov    esi,0x2
  4b23ed:	03 fe                	add    edi,esi
  4b23ef:	e8 6c cc f5 ff       	call   0x40f060
  4b23f4:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  4b23f7:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4b23fa:	8b 03                	mov    eax,DWORD PTR [ebx]
  4b23fc:	3b c1                	cmp    eax,ecx
  4b23fe:	74 0e                	je     0x4b240e
  4b2400:	50                   	push   eax
  4b2401:	8b d1                	mov    edx,ecx
  4b2403:	e8 68 7e 04 00       	call   0x4fa270
  4b2408:	83 c4 04             	add    esp,0x4
  4b240b:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  4b240e:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4b2411:	3b de                	cmp    ebx,esi
  4b2413:	0f 86 9b 00 00 00    	jbe    0x4b24b4
  4b2419:	0f b6 47 01          	movzx  eax,BYTE PTR [edi+0x1]
  4b241d:	48                   	dec    eax
  4b241e:	89 7d 08             	mov    DWORD PTR [ebp+0x8],edi
  4b2421:	83 f8 07             	cmp    eax,0x7
  4b2424:	0f 87 8a 00 00 00    	ja     0x4b24b4
  4b242a:	ff 24 85 cc 24 4b 00 	jmp    DWORD PTR [eax*4+0x4b24cc]
  4b2431:	83 c7 0f             	add    edi,0xf
  4b2434:	83 c6 0f             	add    esi,0xf
  4b2437:	eb 16                	jmp    0x4b244f
  4b2439:	83 c7 0b             	add    edi,0xb
  4b243c:	83 c6 0b             	add    esi,0xb
  4b243f:	eb 0e                	jmp    0x4b244f
  4b2441:	83 c7 0d             	add    edi,0xd
  4b2444:	83 c6 0d             	add    esi,0xd
  4b2447:	eb 06                	jmp    0x4b244f
  4b2449:	83 c7 0a             	add    edi,0xa
  4b244c:	83 c6 0a             	add    esi,0xa
  4b244f:	3b f3                	cmp    esi,ebx
  4b2451:	76 0d                	jbe    0x4b2460
  4b2453:	68 bc 6c bf 00       	push   0xbf6cbc
  4b2458:	e8 03 b7 23 00       	call   0x6edb60
  4b245d:	83 c4 04             	add    esp,0x4
  4b2460:	e8 fb cb f5 ff       	call   0x40f060
  4b2465:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b2468:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b246b:	51                   	push   ecx
  4b246c:	50                   	push   eax
  4b246d:	e8 6e b1 08 00       	call   0x53d5e0
  4b2472:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2479:	75 27                	jne    0x4b24a2
  4b247b:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b2482:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2489:	e8 f2 4f 0d 00       	call   0x587480
  4b248e:	68 c0 cc bc 00       	push   0xbcccc0
  4b2493:	e8 82 fe 3d 00       	call   0x89231a
  4b2498:	83 c4 04             	add    esp,0x4
  4b249b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b24a2:	68 66 42 0f 00       	push   0xf4266
  4b24a7:	e8 24 86 0d 00       	call   0x58aad0
  4b24ac:	83 c4 04             	add    esp,0x4
  4b24af:	e9 5d ff ff ff       	jmp    0x4b2411
  4b24b4:	33 c0                	xor    eax,eax
  4b24b6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b24b9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b24c0:	59                   	pop    ecx
  4b24c1:	5f                   	pop    edi
  4b24c2:	5e                   	pop    esi
  4b24c3:	5b                   	pop    ebx
  4b24c4:	8b e5                	mov    esp,ebp
  4b24c6:	5d                   	pop    ebp
  4b24c7:	c2 0c 00             	ret    0xc
  4b24ca:	8b ff                	mov    edi,edi
```

### 20-byte record initialisation from cmd127

- VA half-open: `0x0053D5E0..0x0053D69F`; raw `0x0013C9E0..0x0013CA9F`, bytes `191`, slice SHA256 `545d03c0e4ca003455c4cfdfccce72022596c01a5cc9b1426b682103c1c89b3d`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  53d5e0:	55                   	push   ebp
  53d5e1:	8b ec                	mov    ebp,esp
  53d5e3:	83 ec 14             	sub    esp,0x14
  53d5e6:	53                   	push   ebx
  53d5e7:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  53d5ea:	56                   	push   esi
  53d5eb:	57                   	push   edi
  53d5ec:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d5ef:	8b 37                	mov    esi,DWORD PTR [edi]
  53d5f1:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  53d5f4:	2b ce                	sub    ecx,esi
  53d5f6:	b8 67 66 66 66       	mov    eax,0x66666667
  53d5fb:	f7 e9                	imul   ecx
  53d5fd:	c1 fa 03             	sar    edx,0x3
  53d600:	8b c2                	mov    eax,edx
  53d602:	c1 e8 1f             	shr    eax,0x1f
  53d605:	03 c2                	add    eax,edx
  53d607:	b9 00 00 00 00       	mov    ecx,0x0
  53d60c:	74 23                	je     0x53d631
  53d60e:	0f b7 7b 04          	movzx  edi,WORD PTR [ebx+0x4]
  53d612:	8d 56 02             	lea    edx,[esi+0x2]
  53d615:	66 39 3a             	cmp    WORD PTR [edx],di
  53d618:	74 0a                	je     0x53d624
  53d61a:	41                   	inc    ecx
  53d61b:	83 c2 14             	add    edx,0x14
  53d61e:	3b c8                	cmp    ecx,eax
  53d620:	72 f3                	jb     0x53d615
  53d622:	eb 0a                	jmp    0x53d62e
  53d624:	8d 04 89             	lea    eax,[ecx+ecx*4]
  53d627:	8d 34 86             	lea    esi,[esi+eax*4]
  53d62a:	85 f6                	test   esi,esi
  53d62c:	75 26                	jne    0x53d654
  53d62e:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d631:	33 c0                	xor    eax,eax
  53d633:	33 c9                	xor    ecx,ecx
  53d635:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  53d638:	33 d2                	xor    edx,edx
  53d63a:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  53d63d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53d640:	8d 45 ec             	lea    eax,[ebp-0x14]
  53d643:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  53d646:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  53d649:	e8 b2 06 00 00       	call   0x53dd00
  53d64e:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  53d651:	83 ee 14             	sub    esi,0x14
  53d654:	0f b6 43 01          	movzx  eax,BYTE PTR [ebx+0x1]
  53d658:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  53d65c:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  53d660:	66 89 0e             	mov    WORD PTR [esi],cx
  53d663:	66 8b 53 04          	mov    dx,WORD PTR [ebx+0x4]
  53d667:	66 89 56 02          	mov    WORD PTR [esi+0x2],dx
  53d66b:	8a 43 03             	mov    al,BYTE PTR [ebx+0x3]
  53d66e:	88 46 0a             	mov    BYTE PTR [esi+0xa],al
  53d671:	0f b6 4b 06          	movzx  ecx,BYTE PTR [ebx+0x6]
  53d675:	89 4e 10             	mov    DWORD PTR [esi+0x10],ecx
  53d678:	8a 13                	mov    dl,BYTE PTR [ebx]
  53d67a:	88 56 0b             	mov    BYTE PTR [esi+0xb],dl
  53d67d:	80 3b 02             	cmp    BYTE PTR [ebx],0x2
  53d680:	75 08                	jne    0x53d68a
  53d682:	b8 ff 00 00 00       	mov    eax,0xff
  53d687:	66 89 06             	mov    WORD PTR [esi],ax
  53d68a:	0f b6 43 01          	movzx  eax,BYTE PTR [ebx+0x1]
  53d68e:	48                   	dec    eax
  53d68f:	83 f8 07             	cmp    eax,0x7
  53d692:	0f 87 74 01 00 00    	ja     0x53d80c
  53d698:	ff 24 85 18 d8 53 00 	jmp    DWORD PTR [eax*4+0x53d818]
```

### 0x18/0x14 record reset and F426F local event

- VA half-open: `0x0053DA80..0x0053DB2C`; raw `0x0013CE80..0x0013CF2C`, bytes `172`, slice SHA256 `85123ad324db047f9847bd8b32efec5f7fa950fc7f006e6a3d63ecc057aa7281`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  53da80:	55                   	push   ebp
  53da81:	8b ec                	mov    ebp,esp
  53da83:	6a ff                	push   0xffffffff
  53da85:	68 de 49 92 00       	push   0x9249de
  53da8a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53da90:	50                   	push   eax
  53da91:	51                   	push   ecx
  53da92:	56                   	push   esi
  53da93:	57                   	push   edi
  53da94:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53da99:	33 c5                	xor    eax,ebp
  53da9b:	50                   	push   eax
  53da9c:	8d 45 f4             	lea    eax,[ebp-0xc]
  53da9f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53daa5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53daa8:	33 c9                	xor    ecx,ecx
  53daaa:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  53daad:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  53dab0:	88 48 3c             	mov    BYTE PTR [eax+0x3c],cl
  53dab3:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  53dab6:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  53dab9:	8b 70 20             	mov    esi,DWORD PTR [eax+0x20]
  53dabc:	3b f1                	cmp    esi,ecx
  53dabe:	74 19                	je     0x53dad9
  53dac0:	8b d1                	mov    edx,ecx
  53dac2:	3b c9                	cmp    ecx,ecx
  53dac4:	74 10                	je     0x53dad6
  53dac6:	66 8b 3a             	mov    di,WORD PTR [edx]
  53dac9:	66 89 3e             	mov    WORD PTR [esi],di
  53dacc:	83 c2 02             	add    edx,0x2
  53dacf:	83 c6 02             	add    esi,0x2
  53dad2:	3b d1                	cmp    edx,ecx
  53dad4:	75 f0                	jne    0x53dac6
  53dad6:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  53dad9:	b8 01 00 00 00       	mov    eax,0x1
  53dade:	84 05 d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,al
  53dae4:	75 26                	jne    0x53db0c
  53dae6:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  53daec:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  53daf3:	e8 88 99 04 00       	call   0x587480
  53daf8:	68 c0 cc bc 00       	push   0xbcccc0
  53dafd:	e8 18 48 35 00       	call   0x89231a
  53db02:	83 c4 04             	add    esp,0x4
  53db05:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  53db0c:	68 6f 42 0f 00       	push   0xf426f
  53db11:	e8 ba cf 04 00       	call   0x58aad0
  53db16:	83 c4 04             	add    esp,0x4
  53db19:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  53db1c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  53db23:	59                   	pop    ecx
  53db24:	5f                   	pop    edi
  53db25:	5e                   	pop    esi
  53db26:	8b e5                	mov    esp,ebp
  53db28:	5d                   	pop    ebp
  53db29:	c2 04 00             	ret    0x4
```

### Local F4266 identity virtual method

- VA half-open: `0x005DF3A0..0x005DF3B6`; raw `0x001DE7A0..0x001DE7B6`, bytes `22`, slice SHA256 `5e28b851b6c59f1230f9523e30c71f40f4f9d5de113cf36d1b25fc035f9a92fa`.
- `objdump` 定向原始片段，**區間頭尾如果不在指令界線或含跳表，無效的邊界位元組不可當作真實 CFG**。

```asm
  5df3a0:	b8 66 42 0f 00       	mov    eax,0xf4266
  5df3a5:	c3                   	ret
  5df3a6:	cc                   	int3
  5df3a7:	cc                   	int3
  5df3a8:	cc                   	int3
  5df3a9:	cc                   	int3
  5df3aa:	cc                   	int3
  5df3ab:	cc                   	int3
  5df3ac:	cc                   	int3
  5df3ad:	cc                   	int3
  5df3ae:	cc                   	int3
  5df3af:	cc                   	int3
  5df3b0:	b8 48 56 c2 00       	mov    eax,0xc25648
  5df3b5:	c3                   	ret
```

## 9. 維護、驗證與 Git 狀態

- 直接 E8 rel32 bounded scan：`0x500110` → `0x4B2206`, `0x502389`；`0x53DB30` → `0x4B2361`；`0x53D840` → `0x4B22BC`；`0x53D5E0` → `0x4B246D`；`0x558200` → `0x53DC65`,`0x55837C`。掃描指令第一 byte 命中不構成完整反組譯 xref 語義；上述 callsite 各有本輪局部 asm 指令支援。
- Source crossrefs：T16-108/109 本地完整原稿；GitHub T16-101/102/105、T03/T02 共同接收證據；本輪對不等價 route/owner 重新獨立驗證。2016、Quest14、0x0E、local F4266 等命名空間一律維持不同欄位，不用相同數字畫等號。
- **僅在本地建立 Markdown**，未 Git Commit／Push；本地檔案沒有 Git blob SHA，更不等於 T01 FULL-PASS 或 S00 SPEC STABLE。阻塞屬 Quest14-specific 原始 S→C/Client state/UI 對照資料不足，不是完成了 Quest14-4。

