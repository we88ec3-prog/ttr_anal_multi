# E64 — RR-0002：Expedition → Square 原生類型與 S2C 0x0069 subtype 7 的場景建立；選角配對仍未知

> KR BIN-first 原生研究，2026-10-30，chatgpt-web roy，唯一工作分支 extra/roy1。本稿將 E64 新發現與 E63 的 930 行原生證據附錄完整保存於同一檔供 T01/S00 核對。RR-0002 仍在 IN_PROGRESS；未執行 Client 或原版 Server。
>
> 來源：Tartaros.bin 12,472,320 bytes；SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。

## 一、RTTI 原件直接確立的 Client 場景類型

從原始 PE 的 vptr[-1] CompleteObjectLocator → COL+0x0C TypeDescriptor → TypeDescriptor+8 ASCII 原生名稱，並獨立驗證 .rdata raw=VA−0x401A00、.data raw=VA−0x402800：

| 原始 native RTTI 名稱 | vptr VA | 建構或 vptr writer |
|---|---|---|
| .?AVCExpedition@Scene@@ | 0xC07280 | 0x4C13E0，0x4C1423 |
| .?AVCSquare@Scene@@ | 0xC06FB0 | 0x4BBB70，0x4BBB78 |
| .?AVCDuelSquare@Scene@@ | 0xC06F7C | 0x4B912E |
| .?AVCDuelField@Scene@@ | 0xC0710C | 0x4B9AAD |
| .?AVCMissionRoom@Scene@@ | 0xC07098 | 0x4B937E |
| .?AVCScenarioDecision@Scene@@ | 0xC07374 | 0x4B97D1 |

這些類別和 E63 已確認的 FUI::CScenarioReviewSceneItem／ChapterItem 完全不同。劇情回顧 UI 的 0x47B5C0 / object+0x248 → 0x565720 不可作為「選角成功→首次教學」的證據。

## 二、S2C command 0x0060 的正向場景功能鏈

0x4B7DC0 在 FD2FFC 註冊 0x4B8F50，依 (FD2FFC−FD2CFC)/8=0x60 得 app command 0x60（和外層 framing marker 不同）。0x4B8F50:

1. 0x4B9004 分配 0xBD8C bytes，0x4B9022 呼叫 0x4C13E0，建構原生 CExpedition@Scene 及 vptr C07280；存在配置失敗分支，不能保證任何輸入都成功。
2. 0x4B9031 以新建 Scene 呼叫 0x4B7D50，切換 Client current scene 的有界路徑。
3. 0x4B9036/0x4B9039 載入 payload pointer、payload length，0x4B903E 呼叫 0x4C22C0 消費資料，後者還有 scene state、資源與位元組欄位的額外前提。
4. 0x4B904F 寫 WORD 0x00F5，只有 FBA798==0 才由 0x4B9056..4B906A 透過 send vtable+0x10 本地 slot0 len2 enqueue。它不等於 wire-first 或官方必然回覆。

這條 native 證據與既有合成測試記錄的 0x60 後 C2S F5 相容；不可將合成測試當官方 Server 行為。

## 三、S2C command 0x0069 的 scene subtype 和 Byte 欄位

0x4B7E0F 將 0x4B9090 寫到 FD3044；(FD3044−FD2CFC)/8=0x69。0x4B90C1 將 payload+2 讀作 signed BYTE，減7，限 0..0x11，經 0x4B924C 的18-byte remap table 與 0x4B9238 的五 DWORD branch table。

| subtype (payload+2) | Native handler 分支 | 結果 |
|---|---|---|
| 7 | 0x4B90DF | 0x4BBB70 建 CSquare、0x4B7D50 更新 active Scene、Client+0x69A8=7 |
| 21 | 0x4B9116 | CDuelSquare vptr C06F7C、0x4B7D50 |
| 23 | 0x4B915B | CSquare、0x4B7D50、Client+0x69A8=23 |
| 24 | 0x4B918F | CSquare、0x4B7D50、Client+0x69A8=24 |
| 其他 | 0x4B922C 或 range fallback | 不經上面有效 scene-switch 分支；不能推定成功 |

0x4B91EE..4B9212 另將 payload+2 更新 F9392C，讀 payload+3/+4 寫入 FE1A88+0x18/+0x1C。此局部消費至少需要含 app cmd WORD 在內的五個 payload bytes，但沒有證據允許拿五個隨機 bytes 作完整合法封包。解析正常、lane2 分派、場景物件與資源仍是必要前提。

因此可以肯定的是「Client 接受符合前提的 S2C 0x69/7 可在本地建立 CSquare」。尚不能肯定「原版 Server 在收到 C2S 0x42 後一定回 S2C 0x69/7」。

## 四、S2C command 0x005F 是另一組 scene 狀態

0x4B7EAF 註冊 FD2FF4=0x4B99C0，index 0x5F；0x4B9A26 讀 unsigned BYTE payload+2，減2後限制 0..26。由 0x4B9B74／0x4B9B54 兩層跳表解析有效 subtype 2、4、6、9、25、26、28，其中 subtype6 可達 CDuelField vptr C0710C；其它 path 可呼叫 0x4C46F0、0x4BC6A0、0x4BDBA0、0x4C54E0、0x4564F0、0x4369D0、0x422FB0。不能把 0x5F/6 與 0x69/7 混為同一場景或封包。

## 五、RR-0002 選角的已證與未證

- 已證 N：玩家 UI 依條件呼叫 0x4A3B80，產生 C2S app payload 42 00 XX YY、長4，受 FBA798==0 與 vtable slot0 send gate；角色清單 command2 是 65-byte prefix + 每筆53 bytes，透過 0x4D4150 在合法記錄條件下設定 +0x5C 可用狀態。
- 已證 N：在獨立有效 app message 分派條件下，S2C 0x60 建 CExpedition 並可引發 C2S F5；S2C 0x69/7 建 CSquare；S2C 0x5F/6 建 CDuelField。
- 已證 N：S2C 0x42 的基底 handler 0x4B2190 寫 FAB2A0，ScenarioReview UI 的 0x47D610 讀該表；S2C 0x43 的基底 handler 0x4B1A90 走 type6 物件移除。不能用數值 42/43 直接宣稱成功／失敗回覆。
- 不足 U：C2S 0x42 真正配對的 S2C 批准／拒絕命令、fields、實際先後、進入 Square 角色實體與所選索引的資料鏈，以及首次教學/廣場到底是如何由原版 Server 決定。原始 Client 的 generic scene handler 不能回答原版 Server 選擇哪個回覆。
- 相容 Server 可提出未驗證的測試假說：在正確 Client 初始化、適當 framing/lane/Conn 及 roster/UI 可用的情況下，測試選角 C2S 42 後是否能用合法 S2C 69/7 進入 Square；需要實際執行/pcap 驗證，尚未執行、絕不能標記原版 wire。
- RR-0008/T05 仍負責首次教學與場景雙鍵的真實啟用條件，T04 負責角色權威初值，T02 的網路解碼順序和 T03 的 UI business sender 不可互相冒充。

## 研究結束條件與當前狀態

這一輪確立了具體的 native CExpedition→CSquare 條件候選與 Scene Review 假路徑的反證，但 RR-0002 的正式 acceptance 要求實際 selection request+reply/scene contract，沒有肯定配對與成功/錯誤資料流，**RR-0002 仍應保持 ACTIVE/IN_PROGRESS**，不得改為 SUBMITTED/ACCEPTED。後續需要 Client 內 selected-ID/Scene owner writer 的有界因果證據，或原版 Server 的實際回覆封包，及可驗證 Client runtime trace；不足證據時不可只靠「猜某個 opcode 是 request+1」補成規格。

## 原始 assembly 與既有證據

下方完整保留 E63 原始 930 行證據及函式範圍，涵蓋 0x4B8F50、0x4B9090、0x4B99C0、0x4B7DC0、0x4B2190、0x47B5C0、0x47D530、Scenario Review RTTI xrefs；本稿新增的 scene 類別 RTTI 由上述位址的實際 PE bytes 可定向重算。

---


# E63 — RR-0002：Scenario Review 原生 RTTI 反證、選角 `0x42` 與接收 `0x42` 的資料容器區隔、三種場景 S2C 指令與未知配對

> **狀態：RR-0002 ACTIVE/IN_PROGRESS，新增完整靜態證據；未達使用者要求的「真實選角回覆配對」研究終點，故不以本稿冒稱已完成。**
>
> 研究者：`chatgpt-web roy`，日期 2026-10-30 (Asia/Taipei)。研究唯一分支 `extra/roy1`，接續已提交 E61 `fc1d4845b3e1647a963e07b0838e05108e4218ca`、E62 `88ebd073cc14f2dee47d712ce9086346b8f62ace`。不新開分支。原件：KR `Tartaros.bin` (12,472,320 bytes) SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；只用檔案 raw byte + GNU objdump 及 Python 位元組核對；沒有執行 Client、沒有原版 Server 記錄。

## 一、研究問題與本批新結果（不縮小 RR）

RR-0002 的必要終點：`C2S 0x0042` 的 `XX/YY` 欄位／UI 前提；`S2C 0x0002` 長 header 與 53-byte roster、角色可用性；**實際**選角批准／拒絕的 opcode、欄位、順序和 scene transition。後三個的證據不能用數值猜測。

新發現：

1. **N（原件正向）：**`0x47B480` 的 vptr 是 `0xC02F3C`，RTTI 明示 `.?AVCScenarioReviewSceneItem@FUI@@`；`0x47B0E0` 的 vptr 是 `0xC02D9C`，RTTI 明示 `.?AVCScenarioReviewChapterItem@FUI@@`。`0x47B2B0` 用來源條目 `+0` 寫目的 `SceneItem+0x248`；`0x47D290` 呼叫 `0x47B2B0` 及場景回顧 UI 方法。`0x47D530` 將此資料透過 `0x47B5C0 → 0x565720` 雙鍵查表／場景腳本讀取。它至少有 **Scenario Review 來源**，不能把整條視為「登入選角後首次教學」證據。
2. **N（原件正向）：**`S2C application cmd 0x0042` 的基底 callback `0x4B2190` 透過 `0x500110` 更新 `0xFAB2A0` 表；`0x47D610`（Scenario Review UI 附近）用 `0xFAB2A0` 作為 `0x503440` 的參數以查取／比較值。因此 `S2C 0x42` 有 scenario-review 資料消費路徑，不能因 `C2S` 恰好也是 `0x42` 就命名為選角成功。此關係沒有證明 `S2C 0x42` **只**能做回顧系統，也未排除間接其他 consumer。
3. **N（第一層入口）：**`0x4B7DC0` 原始記憶體寫入確認全域第一層 `S2C 0x0060→0x4B8F50`、`0x0069→0x4B9090`、`0x005F→0x4B99C0`，與 `0x0002→0x4B7F00` 並列。不能將 `0x0060`、`0x0069` 識別為 `0x0042` 的回覆，只能分別列出它們的 Client native 效果。
4. **N（場景變更）：**`0x4B8F50`（0x60）可建立新 scene 物件、呼叫 `0x4B7D50` 替換 active scene、用 payload 和 length 呼叫 `0x4C22C0`，在 `[0xFBA798]==0` 時建立 `WORD 0x00F5`、vtable+0x10 slot0 長2本地發送。這是條件的 scene bootstrap / response event，不是選角 `0x42` 的已證 immediate reply。
5. **N（場景變更）：**`0x4B9090`（0x69）依 payload byte+2 的 *signed* subtype 跳表，已驗 subtype `{7,21,23,24}` 可達有效分支，並可呼叫 `0x4B7D50` 更新 current scene；其他 subtype 多數分支到 log/error。`payload+3/+4` 亦可能寫入 `FE1A88+0x18/+0x1C`。沒有 request identity match。
6. **N（場景變更）：**`0x4B99C0`（0x5F）依 payload byte+2 的 *unsigned* subtype 跳表，支持 `{2,4,6,9,25,26,28}` 的不同路由，包括場景換入、現有狀態方法、`4B7D50`；其他值不依此處直接進 scene。對是否為選角回覆沒有正向來源。
7. **U：**還沒有一條 Client native 因果鏈證明，某個 `S2C` 實際由原版 Server 作為 `C2S 42` 批准／拒絕而送出，也沒有可由原始 Client 靜態單獨確認的跨 socket wire-first 排序。報告不再使用 `C2S42 → S2C43/69` 這種猜測配對。

## 二、RTTI 指標、資料段正確換算與反證

`.text`：`VA 0x401000` raw `0x400`，指令 `raw=VA−0x400C00`；`.rdata`：`VA 0xBD2000` raw `0x7D0600`，因此 `raw=VA−0x401A00`；`.data` / `.bss` 須按 section virtual/raw 覆蓋分辨，不直接讀虛擬 zero-fill。RTTI `TypeDescriptor` 位址 `0xF7D890/0xF7D864` 位於資料區，需按 `.data` 換算 `raw=VA−0x402800`，不可誤用 `.rdata` 位址偏移。

| 帶 vptr 的物件 | ctor/vptr write | vptr 指標 | vptr[-1] COL | COL+0x0C TypeDescriptor | +8 原生 ANSI RTTI name |
|---|---|---|---|---|---|
| ScenarioReviewChapterItem | `0x47B13D` | `0xC02D9C` | `0xC68B30` | `0xF7D890` | `.?AVCScenarioReviewChapterItem@FUI@@` |
| ScenarioReviewSceneItem | `0x47B4DC` | `0xC02F3C` | `0xC68ACC` | `0xF7D864` | `.?AVCScenarioReviewSceneItem@FUI@@` |

執行式是 PE32 / MSVC RTTI 格式；上述名稱是原始 RTTI 文字，不是研究者自創 class 名。

場景 key writer 的 parent/callee：

- `0x47B2B0` 參數 EDI=this（來源資料型式尚須限定）、`EBX=[EBP+8]` 目標 SceneItem，`0x47B2EF mov [EBX+0x248],EAX`，其中 `EAX=[EDI+0]`；`0x47B2E6 lea esi,[ebx+0x24c]` 後由 `0x4026E0` 字串操作更新 `+0x24C`。這是**UI 記錄拷貝**，不是從接收封包 `payload` 直接搬到 world state。
- `0x47D290` 的 `0x47D36D call 0x47B2B0` 前，`ECX=[tree_node+0x10]`；`EDI` 為由 GUI 物件 virtual+0x04 回傳 `0x12D` 條件選出的 SceneItem 類物件。它遍歷 `owner+0x110` tree，而不是已識別的 T02 app queue。
- `0x47D530` 的 `0x47D558..0x47D56A` 讀 `source+0x248/+0x24C`、寫 `target+0x120/+0x11C`；之後 `0x47D5B7 call 0x47B5C0`，source object 類型由上述 RTTI 同族與 caller 路徑限定。`0x47B5C0` 另讀 `this+0x248`、外部 arg 入 `0x565720`，但 `0x565720` 亦被 EndCutScene 重用（E16），所以進入 reader 不等於首次選角進世界。
- 上述不排除 Client 其它非 review scene owner 也呼叫 `0x565720`；只是**已追到的 0x47B5C0 caller 不能充作選角回覆正向因果**。

## 三、S2C0x42 對 scenario review 狀態的證據

`0x4ADD50` base scene table 在 `0x4ADF3D` 寫 `base+0x214=0x4B2190`；`(0x214−4)/8=0x42`。第一層 default path `0x4B7EC0` 需要 non-null active scene，才會委託 scene vtable+4；目前 LOGIN scene `0x4C3220` 無明確二層覆寫 `0x42`，但會落基底。這不是 Client 應從原版 Server 收到某個 reply 的證據。

`0x4B2190` 接收 `[EBP+8]=payload`，於 `0x4B21FD` 以 **signed WORD [payload+2]** 作 ESI，`EDI=0xFAB2A0`，`0x4B2206 call 0x500110`：更新最多20筆 WORD 的表（詳細見 E62 `0x500110`）。`length>4` 才根據 `payload[5]` 選取子項；部分支線走 `0x53D840` 24-byte record。沒有本地 `selected-character index` 的字節比較，也無 `0x4B7D50/0x565720` 直接 call。

**新增反證**：ScenarioReview UI 相關 `0x47D610` 在 `0x47D693 push 0xFAB2A0`、`0x47D698 call 0x503440`，使用同一全域表做項目查詢；此函式位於 `0x47D530` 所建場景回顧 UI 呼叫的另一層。能建立 `S2C42 state container → scenario review UI consumer` 的同一儲存空間關係，不能因此推斷那是選角成功/失敗結果。

## 四、全域第一層 callback 表中實際的 scene 消費者

`0x4B7DC0` 把 `FD2CFC + 8*index` 設成 default `0x4B7EC0`，再覆寫特定索引：

| index / app S2C cmd（在符合 T02 lane2 與 Client delegate 條件下） | handler pointer 原生寫入位置 | handler | 有界作用 |
|---|---|---|---|
| `0x0002` | `0x4B7DDF → FD2D0C` | `0x4B7F00` | 多用途 bootstrap，含角色 65+53*n 依條件複製 |
| `0x005F` | `0x4B7EAF → FD2FF4` | `0x4B99C0` | 分 subtype 切換 UI／scene |
| `0x0060` | `0x4B7DFF → FD2FFC` | `0x4B8F50` | scene 建置、資料消費與 C2S0xF5 本地 enqueue |
| `0x0069` | `0x4B7E0F → FD3044` | `0x4B9090` | subtype 導向 scene 與狀態寫入 |

**0x60：** `0x4B9004` 分配 `0xBD8C`、`0x4B9022` 呼叫 `0x4C13E0` 初始化（存在配置失敗分支）；`0x4B9031 call 0x4B7D50`、`0x4B903E call 0x4C22C0`（stack arg 為已建的 scene 與 payload，ECX 是 `[EBP+0x0C]` 長度）；其後 `0x4B904F WORD 0x00F5`，若 `[0xFBA798]==0` 於 vtable+0x10 送出 slot0 len2。`0x4C22C0` 存在 `payload+2` 以後的資料讀取、條件 `scene+BD70==2` 與可能大量資料處理，**不等於拿任意合成 0x60 封包就能安全完成初始化**。

**0x69：** `0x4B90C1 movsx ecx,BYTE [payload+2]`；`ecx−7` 限在 0..0x11，另有 jump table index。已從 BIN 原始表 bytes 列舉非 error 分支：subtype `7→0x4B90DF`、`21→0x4B9116`、`23→0x4B915B`、`24→0x4B918F`，其他值落 `0x4B922C` 錯誤日誌（未證實運行時是否終止）。成功分支調 `0x4B7D50`、可能設定 Client+`0x69A8=7/23/24`、以及 `payload+3/+4` 寫 `FE1A88+0x18/+0x1C`。存在場景切換的正向 Client handler，但不證它**由 C2S42 觸發**。

**0x5F：** `0x4B9A26 movzx eax,BYTE [payload+2]`；`eax−2` 限 0..0x1A。跳表支援 subtype `{2,4,6,9,25,26,28}` 的多種分支，包含 `0x4C46F0/0x4BC6A0/0x4BDBA0/0x4C54E0/0x4564F0/0x4369D0/0x422FB0`；部分會設定 vptr 並 `0x4B7D50` 換 scene，其他值預設返回，並不等於 `0x69` 的 subtype／欄位。`0x5F` 同樣無 C2S42 request identity 匹配。

## 五、RR-0002 交付矩陣／下一步

| 必答項 | 結果 | 是否足以宣稱 Client 靜態目標完成 |
|---|---|---|
| C2S 選角 request payload | 原始 `0x4A3B80` bytes 已證，`42 00 XX YY`；三 UI caller 的條件和 `XX/YY` 來源在 E61/T03-3 | 完成局部 |
| 角色 roster 來源／可用性 | `0x4B7F00` 65+53*n 有界、`0x4D4150` 各 record copy、availability+5C，另 `0x4E2730` 2+53*n 不混用 | 完成局部；官方授權／header 全語意 U |
| S2C42/43 app 處理 | 基底 `0x4B2190` scene-review global，`0x4B1A90` 類型6物件回收 | **不足以命名選角 reply** |
| S2C60/69/5F scene handler | 本輪正向確認第一層 table + 條件 scene change；原件可達跳表與 C2S F5 | **條件性的 scene event，不構成 selection response pairing** |
| Client acceptance/rejection wire | **U：**未見 C2S42→某 S2C status opcode/field 之正向因果或原版 Server wire 實錄 | 未完成 |
| Selection→world/tutorial | E16/本輪否證以 scenario-review item 當 selected-character；0x565720 還有 EndCutScene 重入 | 未完成（RR-0008/T05 關聯） |
| Client/Server 動態 | 本機歷史合成 fixture 的成功／失敗 UI 與 0x60→F5 可作線索，不是原版 Server 證據 | 需 runtime capture/實測 |

### 精確後續研究點

1. 在 `0x4B9090` 的 subtype `(7,21,23,24)` 追 scene class RTTI、物件初始化與 Client+0x69A8 writer/consumer；和 T03 選角 UI 回呼後的狀態對照，搜尋真正接收 role-success 的候選。
2. 在 `0x4B99C0` 的 subtype `(2,4,6,9,25,26,28)` 追 scene object 與當前 login scene 的切線前提，找是否存在 selected ID 消費。
3. 在 `0x4B8F50` 及 `0x4C22C0` 檢查 payload+2.. 條件、最小長度、角色-ID/scene record writer；把 `S2C60` 定位為世界 bootstrap 還是選角前場景初始化，不以歷史合成 fixture 推斷原版先後。
4. `0x4A3B80` 對象只有 vtable+0x10 local enqueue；需以真正 `S2C` handler 的 scene role / selected-index writer 才能配對 request，不要僅憑數值 42 或收發時間。
5. 若所有可由 Client 原件追的可達路徑已檢，仍無原版 Server 發送順序，必須以有界未知將 Server 行為列為補證，不能杜撰 `42→43/69`。

## 六、可重現的來源與測試

- `.text` `raw=VA−0x400C00`；以下 appendix 直接 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=X --stop-address=Y Tartaros.bin`。
- 用 `<vtable−4> → COL`、`COL+0x0C → TypeDescriptor`、`TypeDescriptor+8` 讀原生 RTTI 字串；避免把通用 `.text` `+0x248` displacement 當唯一 writer。
- jump-table 檢查：`0x4B9238` 的五個 DWORD branches + `0x4B924C` 的 18 個 BYTE 索引，`0x4B9B54` 的八個 DWORD branches + `0x4B9B74` 的 27 個 BYTE 索引。直接解析原件 table，不把 table data 當 objdump 的 executable assembly。
- T02 network dispatch/frame 定義採用 E59/E60 有界證據，與 app cmd 及 frame marker 區分；E61/E62 完整證據按 Git blob SHA 保留。
- 本稿所有合成 opcode subtype 列舉都只是**靜態跳表驗算**，未啟動 Client，不冒稱觀察到官方 wire。

## 附錄 — 原生 BIN 指令節選（保留原始位址與 hex opcode）

### Scene review ChapterItem ctor/vptr

`Tartaros.bin` .text VA `0x0047b0f0..0x0047b185`，原生反組譯（終點不含）：

```asm
  47b0f0:	55                   	push   ebp
  47b0f1:	8b ec                	mov    ebp,esp
  47b0f3:	6a ff                	push   0xffffffff
  47b0f5:	68 68 9c 91 00       	push   0x919c68
  47b0fa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b100:	50                   	push   eax
  47b101:	51                   	push   ecx
  47b102:	56                   	push   esi
  47b103:	57                   	push   edi
  47b104:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b109:	33 c5                	xor    eax,ebp
  47b10b:	50                   	push   eax
  47b10c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b10f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b115:	8b f1                	mov    esi,ecx
  47b117:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b11a:	e8 61 97 2d 00       	call   0x754880
  47b11f:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b125:	33 ff                	xor    edi,edi
  47b127:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47b12a:	50                   	push   eax
  47b12b:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b131:	e8 ea 03 30 00       	call   0x77b520
  47b136:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b13d:	c7 06 9c 2d c0 00    	mov    DWORD PTR [esi],0xc02d9c
  47b143:	c7 86 48 02 00 00 ff 	mov    DWORD PTR [esi+0x248],0xffffffff
  47b14a:	ff ff ff 
  47b14d:	c7 86 60 02 00 00 07 	mov    DWORD PTR [esi+0x260],0x7
  47b154:	00 00 00 
  47b157:	89 be 5c 02 00 00    	mov    DWORD PTR [esi+0x25c],edi
  47b15d:	33 c9                	xor    ecx,ecx
  47b15f:	66 89 8e 4c 02 00 00 	mov    WORD PTR [esi+0x24c],cx
  47b166:	89 be 68 02 00 00    	mov    DWORD PTR [esi+0x268],edi
  47b16c:	89 be 6c 02 00 00    	mov    DWORD PTR [esi+0x26c],edi
  47b172:	8b c6                	mov    eax,esi
  47b174:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b177:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b17e:	59                   	pop    ecx
  47b17f:	5f                   	pop    edi
  47b180:	5e                   	pop    esi
  47b181:	8b e5                	mov    esp,ebp
  47b183:	5d                   	pop    ebp
  47b184:	c3                   	ret
```

### Scene review SceneItem ctor/vptr

`Tartaros.bin` .text VA `0x0047b490..0x0047b515`，原生反組譯（終點不含）：

```asm
  47b490:	50                   	push   eax
  47b491:	51                   	push   ecx
  47b492:	53                   	push   ebx
  47b493:	56                   	push   esi
  47b494:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b499:	33 c5                	xor    eax,ebp
  47b49b:	50                   	push   eax
  47b49c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b49f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b4a5:	8b f1                	mov    esi,ecx
  47b4a7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b4aa:	e8 d1 93 2d 00       	call   0x754880
  47b4af:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b4b5:	33 db                	xor    ebx,ebx
  47b4b7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47b4ba:	50                   	push   eax
  47b4bb:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b4c1:	e8 5a 00 30 00       	call   0x77b520
  47b4c6:	83 c8 ff             	or     eax,0xffffffff
  47b4c9:	89 86 48 02 00 00    	mov    DWORD PTR [esi+0x248],eax
  47b4cf:	89 86 4c 02 00 00    	mov    DWORD PTR [esi+0x24c],eax
  47b4d5:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b4dc:	c7 06 3c 2f c0 00    	mov    DWORD PTR [esi],0xc02f3c
  47b4e2:	c7 86 64 02 00 00 07 	mov    DWORD PTR [esi+0x264],0x7
  47b4e9:	00 00 00 
  47b4ec:	89 9e 60 02 00 00    	mov    DWORD PTR [esi+0x260],ebx
  47b4f2:	33 c9                	xor    ecx,ecx
  47b4f4:	66 89 8e 50 02 00 00 	mov    WORD PTR [esi+0x250],cx
  47b4fb:	88 9e 6c 02 00 00    	mov    BYTE PTR [esi+0x26c],bl
  47b501:	89 9e 70 02 00 00    	mov    DWORD PTR [esi+0x270],ebx
  47b507:	8b c6                	mov    eax,esi
  47b509:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b50c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b513:	59                   	pop    ecx
  47b514:	5e                   	pop    esi
```

### Scene item ID writer from ChapterItem

`Tartaros.bin` .text VA `0x0047b2d8..0x0047b310`，原生反組譯（終點不含）：

```asm
  47b2d8:	8b f9                	mov    edi,ecx
  47b2da:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47b2dd:	8b 07                	mov    eax,DWORD PTR [edi]
  47b2df:	6a ff                	push   0xffffffff
  47b2e1:	6a 00                	push   0x0
  47b2e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  47b2e6:	8d b3 4c 02 00 00    	lea    esi,[ebx+0x24c]
  47b2ec:	51                   	push   ecx
  47b2ed:	8b ce                	mov    ecx,esi
  47b2ef:	89 83 48 02 00 00    	mov    DWORD PTR [ebx+0x248],eax
  47b2f5:	e8 e6 73 f8 ff       	call   0x4026e0
  47b2fa:	56                   	push   esi
  47b2fb:	8d b3 e8 00 00 00    	lea    esi,[ebx+0xe8]
  47b301:	e8 fa c4 2d 00       	call   0x757800
  47b306:	83 7f 04 16          	cmp    DWORD PTR [edi+0x4],0x16
  47b30a:	b8 01 00 00 00       	mov    eax,0x1
  47b30f:	0f         	jle    0x47b39b
```

### Scene object runtime handoff to scene reader

`Tartaros.bin` .text VA `0x0047d530..0x0047d608`，原生反組譯（終點不含）：

```asm
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
  47d5bc:	57                   	push   edi
  47d5bd:	e8 2e f8 ff ff       	call   0x47cdf0
  47d5c2:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5c8:	8b 31                	mov    esi,DWORD PTR [ecx]
  47d5ca:	e8 41 00 00 00       	call   0x47d610
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
  47d5f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d5fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d602:	59                   	pop    ecx
  47d603:	5f                   	pop    edi
  47d604:	5e                   	pop    esi
  47d605:	8b e5                	mov    esp,ebp
  47d607:	5d                   	pop    ebp
```

### Scene review tree-to-item population

`Tartaros.bin` .text VA `0x0047d2f0..0x0047d3d2`，原生反組譯（終點不含）：

```asm
  47d2f0:	eb 11                	jmp    0x47d303
  47d2f2:	eb 0c                	jmp    0x47d300
  47d2f4:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47d2fb:	eb 03                	jmp    0x47d300
  47d2fd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d300:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  47d303:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  47d309:	8b 88 cc 00 00 00    	mov    ecx,DWORD PTR [eax+0xcc]
  47d30f:	85 c9                	test   ecx,ecx
  47d311:	74 49                	je     0x47d35c
  47d313:	8b 81 ac 00 00 00    	mov    eax,DWORD PTR [ecx+0xac]
  47d319:	2b 81 a8 00 00 00    	sub    eax,DWORD PTR [ecx+0xa8]
  47d31f:	c1 f8 02             	sar    eax,0x2
  47d322:	83 fa ff             	cmp    edx,0xffffffff
  47d325:	7e 35                	jle    0x47d35c
  47d327:	3b d0                	cmp    edx,eax
  47d329:	7d 31                	jge    0x47d35c
  47d32b:	8b 81 a8 00 00 00    	mov    eax,DWORD PTR [ecx+0xa8]
  47d331:	8b 3c 90             	mov    edi,DWORD PTR [eax+edx*4]
  47d334:	85 ff                	test   edi,edi
  47d336:	74 24                	je     0x47d35c
  47d338:	8b 17                	mov    edx,DWORD PTR [edi]
  47d33a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  47d33d:	8b cf                	mov    ecx,edi
  47d33f:	ff d0                	call   eax
  47d341:	3d 2d 01 00 00       	cmp    eax,0x12d
  47d346:	74 16                	je     0x47d35e
  47d348:	6a 00                	push   0x0
  47d34a:	68 c0 1f bf 00       	push   0xbf1fc0
  47d34f:	68 18 21 bf 00       	push   0xbf2118
  47d354:	6a 00                	push   0x0
  47d356:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  47d35c:	33 ff                	xor    edi,edi
  47d35e:	ff 45 f0             	inc    DWORD PTR [ebp-0x10]
  47d361:	3b b3 10 01 00 00    	cmp    esi,DWORD PTR [ebx+0x110]
  47d367:	74 69                	je     0x47d3d2
  47d369:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  47d36c:	57                   	push   edi
  47d36d:	e8 3e df ff ff       	call   0x47b2b0
  47d372:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47d379:	75 27                	jne    0x47d3a2
  47d37b:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  47d382:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d389:	e8 52 09 00 00       	call   0x47dce0
  47d38e:	68 f0 da bc 00       	push   0xbcdaf0
  47d393:	e8 82 4f 41 00       	call   0x89231a
  47d398:	83 c4 04             	add    esp,0x4
  47d39b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d3a2:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  47d3a5:	3b 05 78 0f fc 00    	cmp    eax,DWORD PTR ds:0xfc0f78
  47d3ab:	8b 8f 6c 02 00 00    	mov    ecx,DWORD PTR [edi+0x26c]
  47d3b1:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d3b3:	8b 92 94 00 00 00    	mov    edx,DWORD PTR [edx+0x94]
  47d3b9:	0f 94 c0             	sete   al
  47d3bc:	0f b6 c0             	movzx  eax,al
  47d3bf:	50                   	push   eax
  47d3c0:	ff d2                	call   edx
  47d3c2:	8b 8f 6c 02 00 00    	mov    ecx,DWORD PTR [edi+0x26c]
  47d3c8:	8b 01                	mov    eax,DWORD PTR [ecx]
  47d3ca:	8b 90 c8 00 00 00    	mov    edx,DWORD PTR [eax+0xc8]
  47d3d0:	ff d2                	call   edx
```

### Scenario Review global FAB2A0 UI consumer

`Tartaros.bin` .text VA `0x0047d610..0x0047d6d0`，原生反組譯（終點不含）：

```asm
  47d610:	55                   	push   ebp
  47d611:	8b ec                	mov    ebp,esp
  47d613:	83 e4 f8             	and    esp,0xfffffff8
  47d616:	6a ff                	push   0xffffffff
  47d618:	68 4c 7e 94 00       	push   0x947e4c
  47d61d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d623:	50                   	push   eax
  47d624:	83 ec 2c             	sub    esp,0x2c
  47d627:	53                   	push   ebx
  47d628:	56                   	push   esi
  47d629:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d62e:	33 c4                	xor    eax,esp
  47d630:	50                   	push   eax
  47d631:	8d 44 24 38          	lea    eax,[esp+0x38]
  47d635:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d63b:	8d 87 1c 01 00 00    	lea    eax,[edi+0x11c]
  47d641:	50                   	push   eax
  47d642:	8d 8f 0c 01 00 00    	lea    ecx,[edi+0x10c]
  47d648:	8d 44 24 10          	lea    eax,[esp+0x10]
  47d64c:	e8 6f 62 3c 00       	call   0x8438c0
  47d651:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  47d658:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  47d65c:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47d65f:	75 29                	jne    0x47d68a
  47d661:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  47d668:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  47d66f:	00 
  47d670:	e8 eb 27 08 00       	call   0x4ffe60
  47d675:	68 00 cf bc 00       	push   0xbccf00
  47d67a:	e8 9b 4c 41 00       	call   0x89231a
  47d67f:	83 c4 04             	add    esp,0x4
  47d682:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  47d689:	ff 
  47d68a:	83 c6 24             	add    esi,0x24
  47d68d:	56                   	push   esi
  47d68e:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  47d692:	51                   	push   ecx
  47d693:	68 a0 b2 fa 00       	push   0xfab2a0
  47d698:	e8 a3 5d 08 00       	call   0x503440
  47d69d:	c7 44 24 40 01 00 00 	mov    DWORD PTR [esp+0x40],0x1
  47d6a4:	00 
  47d6a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  47d6a9:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  47d6ad:	2b ce                	sub    ecx,esi
  47d6af:	c1 f9 02             	sar    ecx,0x2
  47d6b2:	33 c0                	xor    eax,eax
  47d6b4:	49                   	dec    ecx
  47d6b5:	74 19                	je     0x47d6d0
  47d6b7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  47d6bd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d6c0:	8b 1c 86             	mov    ebx,DWORD PTR [esi+eax*4]
  47d6c3:	40                   	inc    eax
  47d6c4:	3b 13                	cmp    edx,DWORD PTR [ebx]
  47d6c6:	0f 84 bc 00 00 00    	je     0x47d788
  47d6cc:	3b c1                	cmp    eax,ecx
  47d6ce:	72 f0                	jb     0x47d6c0
```

### S2C42 current handler writes FAB2A0

`Tartaros.bin` .text VA `0x004b21bc..0x004b2230`，原生反組譯（終點不含）：

```asm
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
  4b222b:	0f 87 95 00 00     	ja     0x4b22c6
```

### Global S2C primary handler registration

`Tartaros.bin` .text VA `0x004b7dc0..0x004b7ebf`，原生反組譯（終點不含）：

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7 05 e4 31 fd 00 60 	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	9c 4b 00 
  4b7e79:	89 0d e8 31 fd 00    	mov    DWORD PTR ds:0xfd31e8,ecx
  4b7e7f:	c7 05 d4 34 fd 00 30 	mov    DWORD PTR ds:0xfd34d4,0x4b9d30
  4b7e86:	9d 4b 00 
  4b7e89:	89 0d d8 34 fd 00    	mov    DWORD PTR ds:0xfd34d8,ecx
  4b7e8f:	c7 05 24 2d fd 00 30 	mov    DWORD PTR ds:0xfd2d24,0x4b9630
  4b7e96:	96 4b 00 
  4b7e99:	89 0d 28 2d fd 00    	mov    DWORD PTR ds:0xfd2d28,ecx
  4b7e9f:	c7 05 0c 2e fd 00 70 	mov    DWORD PTR ds:0xfd2e0c,0x4b9770
  4b7ea6:	97 4b 00 
  4b7ea9:	89 0d 10 2e fd 00    	mov    DWORD PTR ds:0xfd2e10,ecx
  4b7eaf:	c7 05 f4 2f fd 00 c0 	mov    DWORD PTR ds:0xfd2ff4,0x4b99c0
  4b7eb6:	99 4b 00 
  4b7eb9:	89 0d f8 2f fd 00    	mov    DWORD PTR ds:0xfd2ff8,ecx
```

### S2C60 init, active-scene update and F5 send

`Tartaros.bin` .text VA `0x004b8f50..0x004b9081`，原生反組譯（終點不含）：

```asm
  4b8f50:	55                   	push   ebp
  4b8f51:	8b ec                	mov    ebp,esp
  4b8f53:	83 e4 f8             	and    esp,0xfffffff8
  4b8f56:	6a ff                	push   0xffffffff
  4b8f58:	68 67 91 94 00       	push   0x949167
  4b8f5d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b8f63:	50                   	push   eax
  4b8f64:	83 ec 08             	sub    esp,0x8
  4b8f67:	53                   	push   ebx
  4b8f68:	56                   	push   esi
  4b8f69:	57                   	push   edi
  4b8f6a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b8f6f:	33 c4                	xor    eax,esp
  4b8f71:	50                   	push   eax
  4b8f72:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b8f76:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b8f7c:	8b f1                	mov    esi,ecx
  4b8f7e:	bb 01 00 00 00       	mov    ebx,0x1
  4b8f83:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4b8f89:	75 28                	jne    0x4b8fb3
  4b8f8b:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4b8f91:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b8f98:	00 
  4b8f99:	e8 e2 e4 0c 00       	call   0x587480
  4b8f9e:	68 c0 cc bc 00       	push   0xbcccc0
  4b8fa3:	e8 72 93 3d 00       	call   0x89231a
  4b8fa8:	83 c4 04             	add    esp,0x4
  4b8fab:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b8fb2:	ff 
  4b8fb3:	39 1d ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,ebx
  4b8fb9:	74 08                	je     0x4b8fc3
  4b8fbb:	89 1d f0 ad fa 00    	mov    DWORD PTR ds:0xfaadf0,ebx
  4b8fc1:	eb 05                	jmp    0x4b8fc8
  4b8fc3:	e8 d8 19 0d 00       	call   0x58a9a0
  4b8fc8:	84 1d 90 43 f9 00    	test   BYTE PTR ds:0xf94390,bl
  4b8fce:	75 24                	jne    0x4b8ff4
  4b8fd0:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  4b8fd6:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4b8fda:	e8 b1 85 02 00       	call   0x4e1590
  4b8fdf:	68 80 cc bc 00       	push   0xbccc80
  4b8fe4:	e8 31 93 3d 00       	call   0x89231a
  4b8fe9:	83 c4 04             	add    esp,0x4
  4b8fec:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b8ff3:	ff 
  4b8ff4:	33 ff                	xor    edi,edi
  4b8ff6:	39 3d 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,edi
  4b8ffc:	74 06                	je     0x4b9004
  4b8ffe:	89 3d 2c 39 f9 00    	mov    DWORD PTR ds:0xf9392c,edi
  4b9004:	68 8c bd 00 00       	push   0xbd8c
  4b9009:	e8 5a 82 3d 00       	call   0x891268
  4b900e:	83 c4 04             	add    esp,0x4
  4b9011:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4b9015:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4b901c:	00 
  4b901d:	3b c7                	cmp    eax,edi
  4b901f:	74 08                	je     0x4b9029
  4b9021:	50                   	push   eax
  4b9022:	e8 b9 83 00 00       	call   0x4c13e0
  4b9027:	8b f8                	mov    edi,eax
  4b9029:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b9030:	ff 
  4b9031:	e8 1a ed ff ff       	call   0x4b7d50
  4b9036:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b9039:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b903c:	50                   	push   eax
  4b903d:	57                   	push   edi
  4b903e:	e8 7d 92 00 00       	call   0x4c22c0
  4b9043:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b904a:	b9 f5 00 00 00       	mov    ecx,0xf5
  4b904f:	66 89 4c 24 10       	mov    WORD PTR [esp+0x10],cx
  4b9054:	75 16                	jne    0x4b906c
  4b9056:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b905c:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b905e:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b9061:	6a 02                	push   0x2
  4b9063:	8d 44 24 14          	lea    eax,[esp+0x14]
  4b9067:	50                   	push   eax
  4b9068:	6a 00                	push   0x0
  4b906a:	ff d2                	call   edx
  4b906c:	33 c0                	xor    eax,eax
  4b906e:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4b9072:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b9079:	59                   	pop    ecx
  4b907a:	5f                   	pop    edi
  4b907b:	5e                   	pop    esi
  4b907c:	5b                   	pop    ebx
  4b907d:	8b e5                	mov    esp,ebp
  4b907f:	5d                   	pop    ebp
  4b9080:	c2               	ret    0xc
```

### S2C69 scene-switch cases

`Tartaros.bin` .text VA `0x004b9090..0x004b9238`，原生反組譯（終點不含）：

```asm
  4b9090:	55                   	push   ebp
  4b9091:	8b ec                	mov    ebp,esp
  4b9093:	83 e4 f8             	and    esp,0xfffffff8
  4b9096:	6a ff                	push   0xffffffff
  4b9098:	68 3e 71 94 00       	push   0x94713e
  4b909d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b90a3:	50                   	push   eax
  4b90a4:	83 ec 08             	sub    esp,0x8
  4b90a7:	53                   	push   ebx
  4b90a8:	56                   	push   esi
  4b90a9:	57                   	push   edi
  4b90aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b90af:	33 c4                	xor    eax,esp
  4b90b1:	50                   	push   eax
  4b90b2:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b90b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b90bc:	8b d9                	mov    ebx,ecx
  4b90be:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b90c1:	0f be 48 02          	movsx  ecx,BYTE PTR [eax+0x2]
  4b90c5:	8d 41 f9             	lea    eax,[ecx-0x7]
  4b90c8:	83 f8 11             	cmp    eax,0x11
  4b90cb:	0f 87 5b 01 00 00    	ja     0x4b922c
  4b90d1:	0f b6 90 4c 92 4b 00 	movzx  edx,BYTE PTR [eax+0x4b924c]
  4b90d8:	ff 24 95 38 92 4b 00 	jmp    DWORD PTR [edx*4+0x4b9238]
  4b90df:	68 54 bd 00 00       	push   0xbd54
  4b90e4:	e8 7f 81 3d 00       	call   0x891268
  4b90e9:	83 c4 04             	add    esp,0x4
  4b90ec:	85 c0                	test   eax,eax
  4b90ee:	74 07                	je     0x4b90f7
  4b90f0:	e8 7b 2a 00 00       	call   0x4bbb70
  4b90f5:	eb 02                	jmp    0x4b90f9
  4b90f7:	33 c0                	xor    eax,eax
  4b90f9:	8b f8                	mov    edi,eax
  4b90fb:	8b f3                	mov    esi,ebx
  4b90fd:	e8 4e ec ff ff       	call   0x4b7d50
  4b9102:	e8 99 ba f4 ff       	call   0x404ba0
  4b9107:	c7 80 a8 69 00 00 07 	mov    DWORD PTR [eax+0x69a8],0x7
  4b910e:	00 00 00 
  4b9111:	e9 ab 00 00 00       	jmp    0x4b91c1
  4b9116:	68 54 bd 00 00       	push   0xbd54
  4b911b:	e8 48 81 3d 00       	call   0x891268
  4b9120:	8b f0                	mov    esi,eax
  4b9122:	83 c4 04             	add    esp,0x4
  4b9125:	85 f6                	test   esi,esi
  4b9127:	74 25                	je     0x4b914e
  4b9129:	e8 22 4c ff ff       	call   0x4add50
  4b912e:	c7 06 7c 6f c0 00    	mov    DWORD PTR [esi],0xc06f7c
  4b9134:	c7 05 74 a6 d6 00 55 	mov    DWORD PTR ds:0xd6a674,0x44535155
  4b913b:	51 53 44 
  4b913e:	e8 5d 23 00 00       	call   0x4bb4a0
  4b9143:	8b fe                	mov    edi,esi
  4b9145:	8b f3                	mov    esi,ebx
  4b9147:	e8 04 ec ff ff       	call   0x4b7d50
  4b914c:	eb 73                	jmp    0x4b91c1
  4b914e:	33 f6                	xor    esi,esi
  4b9150:	8b fe                	mov    edi,esi
  4b9152:	8b f3                	mov    esi,ebx
  4b9154:	e8 f7 eb ff ff       	call   0x4b7d50
  4b9159:	eb 66                	jmp    0x4b91c1
  4b915b:	68 54 bd 00 00       	push   0xbd54
  4b9160:	e8 03 81 3d 00       	call   0x891268
  4b9165:	83 c4 04             	add    esp,0x4
  4b9168:	85 c0                	test   eax,eax
  4b916a:	74 07                	je     0x4b9173
  4b916c:	e8 ff 29 00 00       	call   0x4bbb70
  4b9171:	eb 02                	jmp    0x4b9175
  4b9173:	33 c0                	xor    eax,eax
  4b9175:	8b f8                	mov    edi,eax
  4b9177:	8b f3                	mov    esi,ebx
  4b9179:	e8 d2 eb ff ff       	call   0x4b7d50
  4b917e:	e8 1d ba f4 ff       	call   0x404ba0
  4b9183:	c7 80 a8 69 00 00 17 	mov    DWORD PTR [eax+0x69a8],0x17
  4b918a:	00 00 00 
  4b918d:	eb 32                	jmp    0x4b91c1
  4b918f:	68 54 bd 00 00       	push   0xbd54
  4b9194:	e8 cf 80 3d 00       	call   0x891268
  4b9199:	83 c4 04             	add    esp,0x4
  4b919c:	85 c0                	test   eax,eax
  4b919e:	74 07                	je     0x4b91a7
  4b91a0:	e8 cb 29 00 00       	call   0x4bbb70
  4b91a5:	eb 02                	jmp    0x4b91a9
  4b91a7:	33 c0                	xor    eax,eax
  4b91a9:	8b f8                	mov    edi,eax
  4b91ab:	8b f3                	mov    esi,ebx
  4b91ad:	e8 9e eb ff ff       	call   0x4b7d50
  4b91b2:	e8 e9 b9 f4 ff       	call   0x404ba0
  4b91b7:	c7 80 a8 69 00 00 18 	mov    DWORD PTR [eax+0x69a8],0x18
  4b91be:	00 00 00 
  4b91c1:	b8 01 00 00 00       	mov    eax,0x1
  4b91c6:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4b91cc:	75 20                	jne    0x4b91ee
  4b91ce:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b91d4:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b91db:	00 
  4b91dc:	e8 af 83 02 00       	call   0x4e1590
  4b91e1:	68 80 cc bc 00       	push   0xbccc80
  4b91e6:	e8 2f 91 3d 00       	call   0x89231a
  4b91eb:	83 c4 04             	add    esp,0x4
  4b91ee:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b91f1:	0f be 41 02          	movsx  eax,BYTE PTR [ecx+0x2]
  4b91f5:	39 05 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,eax
  4b91fb:	74 05                	je     0x4b9202
  4b91fd:	a3 2c 39 f9 00       	mov    ds:0xf9392c,eax
  4b9202:	0f b6 51 03          	movzx  edx,BYTE PTR [ecx+0x3]
  4b9206:	a1 88 1a fe 00       	mov    eax,ds:0xfe1a88
  4b920b:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  4b920e:	0f b6 49 04          	movzx  ecx,BYTE PTR [ecx+0x4]
  4b9212:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  4b9215:	33 c0                	xor    eax,eax
  4b9217:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4b921b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b9222:	59                   	pop    ecx
  4b9223:	5f                   	pop    edi
  4b9224:	5e                   	pop    esi
  4b9225:	5b                   	pop    ebx
  4b9226:	8b e5                	mov    esp,ebp
  4b9228:	5d                   	pop    ebp
  4b9229:	c2 0c 00             	ret    0xc
  4b922c:	51                   	push   ecx
  4b922d:	68 28 6e c0 00       	push   0xc06e28
  4b9232:	e8 39 4a 23 00       	call   0x6edc70
  4b9237:	90                   	nop
```

### S2C5F scene-switch cases

`Tartaros.bin` .text VA `0x004b99c0..0x004b9b50`，原生反組譯（終點不含）：

```asm
  4b99c0:	55                   	push   ebp
  4b99c1:	8b ec                	mov    ebp,esp
  4b99c3:	83 e4 f8             	and    esp,0xfffffff8
  4b99c6:	6a ff                	push   0xffffffff
  4b99c8:	68 3e 71 94 00       	push   0x94713e
  4b99cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b99d3:	50                   	push   eax
  4b99d4:	83 ec 08             	sub    esp,0x8
  4b99d7:	53                   	push   ebx
  4b99d8:	56                   	push   esi
  4b99d9:	57                   	push   edi
  4b99da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b99df:	33 c4                	xor    eax,esp
  4b99e1:	50                   	push   eax
  4b99e2:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b99e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b99ec:	8b d9                	mov    ebx,ecx
  4b99ee:	b8 01 00 00 00       	mov    eax,0x1
  4b99f3:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4b99f9:	75 28                	jne    0x4b9a23
  4b99fb:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b9a01:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b9a08:	00 
  4b9a09:	e8 82 7b 02 00       	call   0x4e1590
  4b9a0e:	68 80 cc bc 00       	push   0xbccc80
  4b9a13:	e8 02 89 3d 00       	call   0x89231a
  4b9a18:	83 c4 04             	add    esp,0x4
  4b9a1b:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b9a22:	ff 
  4b9a23:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b9a26:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4b9a2a:	39 05 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,eax
  4b9a30:	74 05                	je     0x4b9a37
  4b9a32:	a3 2c 39 f9 00       	mov    ds:0xf9392c,eax
  4b9a37:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4b9a3b:	83 c0 fe             	add    eax,0xfffffffe
  4b9a3e:	83 f8 1a             	cmp    eax,0x1a
  4b9a41:	0f 87 f4 00 00 00    	ja     0x4b9b3b
  4b9a47:	0f b6 80 74 9b 4b 00 	movzx  eax,BYTE PTR [eax+0x4b9b74]
  4b9a4e:	ff 24 85 54 9b 4b 00 	jmp    DWORD PTR [eax*4+0x4b9b54]
  4b9a55:	68 54 bd 00 00       	push   0xbd54
  4b9a5a:	e8 09 78 3d 00       	call   0x891268
  4b9a5f:	83 c4 04             	add    esp,0x4
  4b9a62:	85 c0                	test   eax,eax
  4b9a64:	0f 84 c6 00 00 00    	je     0x4b9b30
  4b9a6a:	8b f0                	mov    esi,eax
  4b9a6c:	e8 7f ac 00 00       	call   0x4c46f0
  4b9a71:	e9 bc 00 00 00       	jmp    0x4b9b32
  4b9a76:	68 5c bd 00 00       	push   0xbd5c
  4b9a7b:	e8 e8 77 3d 00       	call   0x891268
  4b9a80:	83 c4 04             	add    esp,0x4
  4b9a83:	85 c0                	test   eax,eax
  4b9a85:	0f 84 a5 00 00 00    	je     0x4b9b30
  4b9a8b:	e8 10 2c 00 00       	call   0x4bc6a0
  4b9a90:	e9 9d 00 00 00       	jmp    0x4b9b32
  4b9a95:	68 54 bd 00 00       	push   0xbd54
  4b9a9a:	e8 c9 77 3d 00       	call   0x891268
  4b9a9f:	8b f0                	mov    esi,eax
  4b9aa1:	83 c4 04             	add    esp,0x4
  4b9aa4:	85 f6                	test   esi,esi
  4b9aa6:	74 1e                	je     0x4b9ac6
  4b9aa8:	e8 a3 42 ff ff       	call   0x4add50
  4b9aad:	c7 06 0c 71 c0 00    	mov    DWORD PTR [esi],0xc0710c
  4b9ab3:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x44554546
  4b9aba:	45 55 44 
  4b9abd:	e8 de 40 00 00       	call   0x4bdba0
  4b9ac2:	8b fe                	mov    edi,esi
  4b9ac4:	eb 6e                	jmp    0x4b9b34
  4b9ac6:	33 f6                	xor    esi,esi
  4b9ac8:	8b fe                	mov    edi,esi
  4b9aca:	eb 68                	jmp    0x4b9b34
  4b9acc:	68 5c bd 00 00       	push   0xbd5c
  4b9ad1:	e8 92 77 3d 00       	call   0x891268
  4b9ad6:	83 c4 04             	add    esp,0x4
  4b9ad9:	85 c0                	test   eax,eax
  4b9adb:	74 53                	je     0x4b9b30
  4b9add:	e8 fe b9 00 00       	call   0x4c54e0
  4b9ae2:	eb 4e                	jmp    0x4b9b32
  4b9ae4:	68 54 bd 00 00       	push   0xbd54
  4b9ae9:	e8 7a 77 3d 00       	call   0x891268
  4b9aee:	83 c4 04             	add    esp,0x4
  4b9af1:	85 c0                	test   eax,eax
  4b9af3:	74 3b                	je     0x4b9b30
  4b9af5:	8b f0                	mov    esi,eax
  4b9af7:	e8 f4 c9 f9 ff       	call   0x4564f0
  4b9afc:	eb 34                	jmp    0x4b9b32
  4b9afe:	68 54 bd 00 00       	push   0xbd54
  4b9b03:	e8 60 77 3d 00       	call   0x891268
  4b9b08:	83 c4 04             	add    esp,0x4
  4b9b0b:	85 c0                	test   eax,eax
  4b9b0d:	74 21                	je     0x4b9b30
  4b9b0f:	8b f0                	mov    esi,eax
  4b9b11:	e8 ba ce f7 ff       	call   0x4369d0
  4b9b16:	eb 1a                	jmp    0x4b9b32
  4b9b18:	68 5c bd 00 00       	push   0xbd5c
  4b9b1d:	e8 46 77 3d 00       	call   0x891268
  4b9b22:	83 c4 04             	add    esp,0x4
  4b9b25:	85 c0                	test   eax,eax
  4b9b27:	74 07                	je     0x4b9b30
  4b9b29:	e8 82 94 f6 ff       	call   0x422fb0
  4b9b2e:	eb 02                	jmp    0x4b9b32
  4b9b30:	33 c0                	xor    eax,eax
  4b9b32:	8b f8                	mov    edi,eax
  4b9b34:	8b f3                	mov    esi,ebx
  4b9b36:	e8 15 e2 ff ff       	call   0x4b7d50
  4b9b3b:	33 c0                	xor    eax,eax
  4b9b3d:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4b9b41:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b9b48:	59                   	pop    ecx
  4b9b49:	5f                   	pop    edi
  4b9b4a:	5e                   	pop    esi
  4b9b4b:	5b                   	pop    ebx
  4b9b4c:	8b e5                	mov    esp,ebp
  4b9b4e:	5d                   	pop    ebp
  4b9b4f:	c2               	ret    0xc
```

### C2S42 original request builder

`Tartaros.bin` .text VA `0x004a3b80..0x004a3bbb`，原生反組譯（終點不含）：

```asm
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2               	ret    0x8
```

### S2C60 scene payload consumed

`Tartaros.bin` .text VA `0x004c22c0..0x004c2333`，原生反組譯（終點不含）：

```asm
  4c22c0:	55                   	push   ebp
  4c22c1:	8b ec                	mov    ebp,esp
  4c22c3:	83 e4 f8             	and    esp,0xfffffff8
  4c22c6:	6a ff                	push   0xffffffff
  4c22c8:	68 79 96 93 00       	push   0x939679
  4c22cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c22d3:	50                   	push   eax
  4c22d4:	83 ec 28             	sub    esp,0x28
  4c22d7:	53                   	push   ebx
  4c22d8:	56                   	push   esi
  4c22d9:	57                   	push   edi
  4c22da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c22df:	33 c4                	xor    eax,esp
  4c22e1:	50                   	push   eax
  4c22e2:	8d 44 24 38          	lea    eax,[esp+0x38]
  4c22e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c22ec:	8b f1                	mov    esi,ecx
  4c22ee:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c22f1:	33 c9                	xor    ecx,ecx
  4c22f3:	83 fe 02             	cmp    esi,0x2
  4c22f6:	73 04                	jae    0x4c22fc
  4c22f8:	33 ff                	xor    edi,edi
  4c22fa:	eb 14                	jmp    0x4c2310
  4c22fc:	83 c6 fe             	add    esi,0xfffffffe
  4c22ff:	b8 db 4b 68 2f       	mov    eax,0x2f684bdb
  4c2304:	f7 e6                	mul    esi
  4c2306:	2b f2                	sub    esi,edx
  4c2308:	d1 ee                	shr    esi,1
  4c230a:	8d 3c 32             	lea    edi,[edx+esi*1]
  4c230d:	c1 ef 04             	shr    edi,0x4
  4c2310:	83 bb 70 bd 00 00 02 	cmp    DWORD PTR [ebx+0xbd70],0x2
  4c2317:	0f 85 19 02 00 00    	jne    0x4c2536
  4c231d:	d9 83 68 bd 00 00    	fld    DWORD PTR [ebx+0xbd68]
  4c2323:	8b c7                	mov    eax,edi
  4c2325:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  4c2329:	d9 83 60 bd 00 00    	fld    DWORD PTR [ebx+0xbd60]
  4c232f:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
```


## 檢核與分級

- 原始 client 可證（N）：固定指令 bytes、函式參數、RTTI 類別文字、table slot、局部 sender、事件處理器、場景狀態更新。
- 部分（P）：必要條件下 S2C handler 到場景切換的可達性；global dispatch/scene owner 依 T02 既有條件。
- 資訊缺失（U）：原版 Server 是哪個 S2C 回應 C2S42、正式角色結果碼與欄位、首次正常進入遊戲實際長度/順序/slot、跨 socket wire、角色權威資料與 first tutorial policy。
- AI 替代：`login_protocol.py` 的固定 roster 與 room fixtures、既有合成封包測試；不得上升為 Native。
- 跨功能：T03 RR-0002 selection、RR-0008 首次教學、T02 transport、T04 role authority、T05 scene、T06 UI；T01 原件審核/S00 決策未替代。

**本稿結論：有重大新原生界線，仍不是 RR-0002 完成報告。保存 E63 以接續，正式台帳必須保持 IN_PROGRESS 直至把真實 selection response contract 補證，或有可操作的阻塞條件走 BLOCKED。**
