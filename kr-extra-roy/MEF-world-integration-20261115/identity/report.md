# MEF 替代流程：普通世界物件的 Lua 身分、Server 接管與生命週期

日期：2026-11-15。作業分支由整合者維持 `extra/roy1`；本子題僅讀原件與固定 Git 來源，在 scratch 產生分析證據，未修改 Client、Server、repo、索引或分支，未執行或附加 Client／Lua。

## 1. 結論與可實作界線

**本地 `lb.CreateObjectEx` 建出的 CMonster 可以進入 Server 封包使用的同一個世界 ID 索引；這提供有條件的更新能力，尚不構成可可靠取代 Server 生怪的身分契約。** 本輪閉合的限制是：

1. 已發表的 lb 契約仍成立：`CreateObjectEx` 沒有把原生 `actor+04` 的 EntityId 推回 Lua。本輪檢查的具體新候選也沒有補上任意世界物件的 ID／存活狀態 reader。`Q.GetLeaderPosN` 確實 push number，但讀的是當前控制器領隊的位置分量；`Tutorial.IsCharacterAvailable` 確實 push 數值 0／1，但忽略輸入 key，固定看 `CCharStatus[2]+5C`。[沿用來源 S1；原件 I20–I31、D08–D09、D18a–c]
2. 唯一 ID 插入成功後，`0001/0016/000B` 的已查 lookup／共通 writer 不分「本地建立」或「0007 建立」。若 Server 已確知目前唯一 ID，且物件、控制器與封包欄位符合既有契約，可以命中本地 CMonster 並改位置／控制資料。本輪已追過 virtual 到實際欄位寫入，沒有停在第一個 virtual。[I01–I12、D03]
3. **`0007` 不是採用或對帳既有物件的指令。** 只要世界樹已有同 ID，`4AE5B2 → 4AED42` 直接跳過整列；不比較 model、不覆寫來源 row 欄位、不重新套用狀態，也不把舊物件換成本地新物件。[I06]
4. 重複本地 ID 的插入同樣不替換舊物件：`4DFF30` 只警告並返回；`4A0F70` 隨後仍遞增計數器，且在 attach 參數非零時仍可能把新物件交給控制器。因此「索引裡的 A」與「控制器持有的新 B」可以在此分支具有相同數值 ID。後續 Server lookup 仍取索引中的 A。[I01–I05；D07]
5. **EntityId 不能只當任意 16 位流水號。** 本地使用 `F7DE04` 的低 16 位，原件初值 1001（`0x03E9`）；`0007` miss 分支卻按 ID 的低 byte 選類別。低 byte `E9` 會進錯誤路徑，而不是建立 CMonster。`001A` 還有低 byte `2/8/9` 的其他布局前置處理，不能從共同世界索引推導「任何本地 ID 都能安全套用任何封包」。[I01、I06–I07、I13–I14；D01–D02、D19]

因此本輪把**身分回報、可靠對帳與 typed ID 一致性列為 Server／內容開發的前置契約；完成之前不能宣告生怪已交由新 MEF 接手。** 已知 Server world spawn 契約只作尚未替代部分的比較基準，不把持續由 Server 生怪當作 MEF 接手的完成方案，也不把猜測同步的 counter 當網路 EntityId。這是由目前 Client 契約推導的開發需求，不是宣稱所有替代途徑都不存在。

## 2. 證據身分、覆蓋與既有成果

### 2.1 原件與記錄

原件為 `02-Tartaros.bin`，SHA256：

`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`

大小 12,472,320 bytes，PE32／i386，ImageBase `0x00400000`。以下 VA 均為此原件的靜態 VA，不是執行期位址。程式碼區本輪所用映射為 `raw = VA − 0x400C00`；資料一律按 PE section 映射，不能沿用程式碼常數。[native-windows.json 的 binary／sections]

`native-windows.json` 保存每筆 VA、exclusive end、raw offset、完整 hex、SHA256 與解碼結果；`native-windows.asm` 提供可閱讀反組譯。I01–I43 是程式碼窗口，D01–D19（其中 D17／D18 各三筆）是資料、跳表、vtable、字串及 RTTI。所有窗口由原件重新取回，沒有把 Ghidra 型別或反編譯變數當原件事實。

### 2.2 固定來源與沿用項目

完整 pin 見 `source-manifest.json`，每筆均含 commit、完整 repo path、Git blob SHA1、SHA256 與長度。

| 代號 | 固定來源 | 本輪用途 |
|---|---|---|
| S1 | main `060ed5163a67308f15aa32a91f3a6661e6e5b106`：`kr-extra-roy/MEF-entry-lifecycle-events-20261114/identity.md`；blob `758b286d6773e304d8b361b421d4ed142ca14280` | 沿用 lb 14 項註冊、CreateObjectEx 沒有 ID push、SetActorAvatar／Attach／Detach 的 world ID 語義 |
| S2 | 同一 main：`kr-extra-roy/MEF-entry-lifecycle-events-20261114/events.md`；blob `f112c4468f4bfe53733084b2a37b4f63404c2c67` | 沿用 `000C → CDeadState`、死亡與 `001A` 移除的區別、普通 controller getter 界線 |
| S3 | 同一 main：`governance/s00-iterations/S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md`；blob `09f81ccaee78afaed549ac700bcced71768a17c0` | 普通 Single／Formation／Tutorial controller 與 model 1036 範圍 |
| S4 | 同一 main：`governance/client-variants/20261109-mef-town-services/scenario-controls.md`；blob `ffbdde4083c56020d068eb86859212b01285e0ad` | 既有控制封包與場景控制基線 |
| S5 | parent `acc5b1e6d856bd31456fe2806044c3a09d5bbb43`：`kr-extra-roy/MEF-entry-lifecycle-events-20261114/controller-input.md`；blob `60a517ae2a0cfed734c6c68a1774eb68e094cc8f` | `000A` producer、mapper 與條件式 neutral-row fallback |
| S6 | 同一 parent：`kr-extra-roy/MEF-parser-executor-storage-20261114/executor.md`；blob `9bb84b5f173636024e4bb58ada8e190e52209c55` | Lua executor、namespace 與回值 ABI 基線 |
| S7 | 同一 parent：`kr-extra-roy/MEF-runtime-contracts-20261115/input-lifecycle/tables.json`；blob `51c6ec4c268e99d8e2f75425166272e93e8d36c0` | 沿用有限 Q 64 項 binding inventory；此檔不在固定 main，故不能錯 pin 到 main |

Bulk 導航來源均固定 main `060ed516…`，路徑格式為 `kr-bulk-roy/9741…be91/functions/0x<VA>.c`。manifest 中的 72 筆 bulk pin 是本輪取得的導航集合，**不是 72 個函式都完成所有控制流或全程式窮舉的宣稱**。下面逐候選與原件窗口才是本輪主張的界線。

不重做已完成的 `.mef`／STP 副檔名搜尋、FB74C0 名稱 alias 掃描、空 `GetObjectCount`、三槽 getter 陰性、CDeadState 顯示鏈。原生 MEF parser 是否另有實現，不能由本輪 Lua／world actor 證據推出。

## 3. 具體 Lua reader：有真回值，但身分域不同

### 3.1 `Q.GetLeaderPosN(n)`

註冊鏈完整可核：`566880` 在 `566898` 寫 `FE27B8=564610`，以 `GetLeaderPosN`（`D6A338`）註冊 closure `568FE0`；closure 在 `56901A` 呼叫 `56B590`。[I20–I22、D08]

`56B590` 把最後一個 Lua 參數轉整數，呼叫原生目標後，於 `56B607` 將回值寫為 QWORD，`56B609` 寫型別 3，`56B610` 將 Lua top 增加 `0x10`。這是實際數值回傳，與 S1 所述 `CreateObjectEx` 外層只回 `EAX=1`、未 push 原生 ID 的情形不同。[I22；S1]

原生 `564610` 的語義是：

| 步驟 | 原件位置與效果 |
|---|---|
| 取得 actor | `564620–56462B` 讀 current controller `FBA7A4` 並呼叫 vtable `+20` |
| 閉合 known target | Single／Formation／Tutorial 三表的 `+20` 都是 `5452B0`；該函式用既有 `v+1C(0)` 取第 0 槽，沿用已證 getter 語義 |
| 取得三分量 | 非 null actor 經 `v+50` 填三個 float；CMonster 的 target 是 `4C8FA0` |
| 返回哪一個 | `n=0/1/2` 分別返回三分量；其他值或 null leader 返回 `0.0` |
| 實際 position consumer | `4C8FA0` 在 model 條件滿足且 `7A7B30` 成功時使用 model position，否則讀 `actor+A0/A4/A8` |

[I23–I25、D03–D06；S2]

這個 reader 的輸入是**座標分量選擇器**，不是世界 ID、Q object slot 或任意 actor index。原生函式本身沒有 Q-active 檢查；在該 VM 已有 Q binding、current controller 有效且 leader 存在時，能讀當前領隊位置。它仍不會列舉世界物件，不讀 `actor+04`、HP 或 FSM 狀態。即使用 attach 改變領隊，所得座標也沒有附帶穩定身分，不能用「座標為零」判定物件不存在或死亡。

### 3.2 `Tutorial.IsCharacterAvailable(arg)`

`4AB260` 寫 `FE1854=4A9F00`，以 `D6ACB0` 的 API 名註冊 `4AC5E0`；closure 經 `4ACF90` 於 `4ACFFE/4AD005/4AD007` 真正 push Lua number。[I26–I28、D09]

然而 native `4A9F00` **完全不讀傳入 stack argument**。它只讀 `[F94304]`，檢查 base `+47C` 是否非零，以 `base+420`／零得到返回數值 1／0。[I29]

`4E199E–4E19E4` 證實 `F94304` 來自十個、每個 stride `0x210` 的物件陣列；constructor `4D3D00` 設置 vtable `C0CBB0`、初始化 `+5C` 為零，RTTI 為 `CCharStatus`。因此 `0x47C = 2×0x210 + 0x5C`，是固定第 2 項，並非以輸入 EntityId 查世界樹。[I30–I31、D18a–c]

可實作契約只寫到「固定 CCharStatus 第 2 項的非零檢查，回 Lua number 0／1」。本輪未沿其所有 writer 定義完整業務名稱，不把 `+5C` 擴稱為任意世界 actor 的 alive、HP 或存在旗標。Lua number `0` 也不等於 Lua boolean `false`；呼叫者須照數值契約比較。

### 3.3 其餘具體名稱候選的有界排除

| 候選與追查範圍 | 原件結果 | 為何不能當本題 getter |
|---|---|---|
| `AI`／`AILINK`：`54B6B0`、`54B470`、`808730/808940`、`8095D0` | `54B6CA` 查 XML 的 AILINK，`54B6DE/54B83F` 查 AI child／next sibling；`808730` 讀 `Table/AI/AI_List.xml` 並查 AILIST／ITEMLIST；`54B470` 建 native condition/action 物件，`8095D0` 將字串與 native 指標存 C++ map | 此具體「註冊」是 native AI factory map，不是 Lua C closure／userdata getter。不能把 AI XML 的 action ID 當世界 EntityId |
| `Actor`：`7D37B0 → 7C6430` | `7D37C9` 把 Actor 名稱傳給 native scene-node 命名搜尋 | 此 literal 入口不是 Lua 世界索引 reader |
| `SetID`：`831770` 中的具體 attribute 入口 | `8318CE` push SetID，`8318D3` 呼叫 XML attribute helper，`8318EC` 做整數轉換 | 是設定資料的欄位，不是已註冊的 Lua SetID 方法 |

[I32–I39、D10–D16；同名函式的固定 bulk 導航 pin]

此表只排除列出的候選與分支。沒有宣稱所有 namespace、所有 AI virtual target、所有未辨識 Lua userdata 都不存在 EntityId API。採用先前有限 binding inventory，再追具體可疑入口，沒有把全檔關鍵字未命中當證明。

## 4. 本地建立物件實際進入哪裡

### 4.1 三個不同的量

| 量 | 本輪原件表示 | 不應混用 |
|---|---|---|
| 世界 EntityId | `actor+04` 的 WORD；`4DFF30` zero-extend 成世界樹 DWORD key | 不是 model ID、Q object slot 或 C++ pointer |
| actor class／model 複合值 | `actor+88`，由 class 高位與 model 低 WORD 組成；local 與 0007 各有自己的 producer | 不能因 model 1036 是 CMonster，就推論任意 EntityId 都具網路 monster 型別 |
| 記憶體物件 | 世界樹 node `+10` 的 actor pointer；controller 也能另持 actor pointer | 同數值 ID 不保證所有 pointer 參照的是同一個 actor |

`4A0F70` 對普通正值 model `10..10000` 使用 CMonster 建構路徑；例如既有 ordinary model 1036 在此範圍。`4A104F` 讀 `F7DE04` 的 WORD，`4A105F` 寫入 `actor+04`，`4A11B6` 呼叫 `4DFF30`，`4A11BB` 以 DWORD 遞增 counter。`4A10A4` 可核 EDI=1。[I01；S1、S3]

原件 `F7DE04` 的初始 raw 值為 `e9 03 00 00`，即 1001；這是 PE 初始值，**不是本輪讀到的執行期第一隻怪 ID**。本輪不假設進圖會重設 counter，不假設每個 Client 的呼叫數相同，也不把低 16 位截斷及可能回繞忽略掉。[D01；I01]

### 4.2 索引節點與 collision

`4DFF30` 使用 world owner `FAB130` 的 `+08`（`FAB138`）作 map receiver，`+0C`（`FAB13C`）是 sentinel。`57EF20` 分配 `0x18` bytes，node `+0C` 存 DWORD key，`+10` 存 actor pointer。`82EF00` 以 unsigned DWORD 比較 key。[I02–I04]

不存在 key 時，`4DFF30 → 57EF20 → 82F200` 走 unique insertion。已有 key 時，`4DFF6A → 4DFF90` 只發重複角色警告並返回；該分支沒有換 key、替換 pointer、修改舊 actor 或銷毀新 actor。generic insertion 的重複 fallback 也只釋放新配置的 tree node，保留既有 iterator，不釋放 payload actor。[I02、I05；D07]

呼叫端 `4A0F70` 沒有依插入成功與否重試／回傳失敗；它繼續增 counter。attach 參數非零時，以新物件 ESI 呼叫 current controller 的 `v+04`／`v+10`。已證普通 Single 的 `v+04=545040` 在有空槽時保存該 pointer；滿槽等條件仍適用。[I01；S1、S3]

可推導的碰撞案例是：

| 時點 | 世界樹 | 新本地 actor B | 後續含 ID K 的 Server lookup |
|---|---|---|---|
| 原先已有 A，key K | K → A | 尚未建立 | A |
| B 也被配到 K，`4DFF30` 發警告 | 仍是 K → A | 此分支沒有釋放 B | A |
| 呼叫端繼續且 attach 成功 | 仍是 K → A | controller 可能持有 B | 仍是 A |

這是依指標與控制流作出的靜態推論。不能進一步宣稱 B 永遠洩漏、所有後續清理都找不到 B，或某一次實機已發生碰撞；本輪只證明該插入流程沒有完成 B 的世界索引擁有權移轉，也沒有提供 Lua 可見的成功／ID 契約。

## 5. 為何補發 `0007` 不能採用本地 actor

### 5.1 hit 在型別與內容之前就跳過

共同 dispatcher 的 `+3C`（`7×8+4`）指向 `4AE4D0`。在 handler-view 中，長度 L≥2 時，以 `floor((L−2)/26)` 讀 row；row 從 buffer `+2` 開始，WORD ID 在 row `+0`。這裡只陳述 handler 所見 buffer，不另造外層 wire framing。[I06、I42]

`4AE58F–4AE5B2` 先找世界 ID。若結果非 sentinel，直接跳至 `4AED42` 增 row index、前進 26 bytes。這個判斷尚未讀 node 的 actor pointer，因此連「key 已存在但 pointer 為空」也不會落入新建分支。正常返回的 `EAX=0x100` 是 handler 結果，不是每個 actor 的採用 ACK。[I06]

miss 分支較後面才寫入新 actor 的資訊：`4AEB1C` 寫 `actor+9C` 的來源 row DWORD，`4AEB26` 寫 `actor+90` 的來源 row byte（擴成 DWORD），`4AEB30` 寫 ID，`4AEB3A` 呼叫 `v+3C` 設 class/model，接著設定位置、方向、速度等，再插入世界樹。hit 全部跳過。[I06]

本輪不把 `+9C` 的精確業務語義擅稱為 server owner 欄位；可確定的是補發 hit **不會更新它**。local base actor 原本 `+9C=0`、`+90=0x7F` 的建構初值也不會因該 `0007` hit 而被 row 內容取代。[I41、I06]

### 5.2 miss 的 typed ID 條件

`4AE5B8` 讀 ID 的低 byte，`4AE5D4/4AE5D7` 驗其是否大於 7，再經 `4AED90` 跳表：[I06、D02]

| ID 低 byte | miss 分支 |
|---|---|
| `0` | `4AE5E4`，character factory |
| `1` | `4AE671`，CMonster factory |
| `2..5` | `4AED83`，error helper |
| `6` | `4AE80A`，NPC factory |
| `7` | `4AE8D6`，另一 actor factory；本輪不命名其完整業務類別 |
| `>7` | `4AED83`，error helper |

本地初始低 16 位 `0x03E9` 的 low byte 是 `E9`。若該 key 已存在，補發 `0007` 只跳過；若先移除而 key 不存在，再發同 ID，會走 error，而不是「這次就採用」。`4AED88 → 6EDC70` 的原件包含訊息視窗呼叫與 `6EDCE9 INT3`，後面另呼叫 `8939B3`；本輪不將此稱作可回復的 skip，不聲稱經實機觀察的 crash 型態，也不把錯誤後的未知恢復行為當通過契約。[I06–I07]

對 CMonster，Server 至少要遵守 `0007` 所要求 low byte 1；這不等於本輪已還原全部 EntityId 分配規則。其他型別可用範圍、保留值及跨場次回收仍須按既有 Server world 契約處理。

## 6. 後續更新與刪除：哪些是真正可用的能力

下表的共同前置是：world map 已正常建立、ID 唯一指向有效 actor、current controller 有效、handler-view 長度及 row 資料正確，且目標物件的原生型別／欄位布局符合該封包的使用條件。**「沒有來源 gate」僅限表列 lookup 與已閉合的 writer；不代表所有封包、所有下游虛擬函式或所有資料值都無限制。**

| 已有封包 | 已閉合鏈與效果 | 仍保留的限制 |
|---|---|---|
| `0001`／`0016` → `4AFB80` | `4AFC26 → 82EF00(FAB138)`；取 node `+10`。`4AFC77/80` 寫 `actor+E8/EC` 目標，`0001` 分支算 `目標−A0/A4` 寫 D8/DC；`0016` 清 D8/DC，經 `v+44 → 4C8B90 → 4CAB80` 寫 A0/A4，方向 `v+58 → 4C8C30` 寫 B0 | missing／null actor 只警告跳過；leader 比較影響 controller+74。render 分支另有 model、+370、+3A8 等條件。本輪不把 target write 等同所有 AI／戰鬥完成 |
| `000B` → `4AFE60` | `4AFEFE → 82EF00(FAB138)`；`4B00E5` 寫 E0、`4B00EF` 寫 E4、`4B00F8 → v+58 → 4C8C30` 寫 B0 | row 會先組控制資料，位置非零／距離判斷決定部分修正；leader 分支另影響 controller/render 欄位。不能從此推出所有技能結果可任意合成 |
| `000C` | 沿用 S2：world ID 到 actor FSM，可在既有 state slot 等 gate 成立時進 CDeadState 等已證狀態 | 本輪沒有重做死亡顯示，也沒有新增 ordinary death → Lua 身分通知的證據 |
| `001A` → `4B28D0` | 先查 world ID，再做按 ID low byte 的前置；正常返回後到 `4B2AC2 → 4DFBC0`，依實際 vtable 清理、delete actor、erase node | 低 byte 特殊布局前置不能省略；移除不是死亡事件或群清 callback |

[I08–I18、D03；S2]

### 6.1 001A 已追到實際釋放

在 handler-view L≥4 時，`001A` 從 buffer `+4` 讀 `floor((L−4)/2)` 個 WORD ID。lookup miss／null actor 警告跳過；hit 經前置處理及控制器三槽 ID 比對後，將原 row ID 傳給 `4DFBC0`。[I13]

`4DFBC0` 再次查 key，呼叫 actor `v+14`，再呼叫 `v+00(1)`，清 node `+10`，最後 `7B6890` 刪 node。對本輪 local CMonster：

- vtable `C0C9DC+14 → 4D1F80 → 4C8360` 是清理入口。
- vtable `C0C9DC+00 → 4D18D0` 呼叫 `4C7B90` 做 destructor 清理；因參數 bit 1 成立，`4D18F2 → 89120C` 釋放 actor。
- `7B6AC7 → 89120C` 釋放 tree node，並在 count 非零時遞減 count。

[I15–I18、D03；完整 cleanup 的固定 bulk 導航]

因此不是只看到 `001A` diagnostic 而猜刪除：對滿足前置、世界索引中確實指向該 CMonster 的物件，已閉合到實際 destructor／heap free／erase。正常移除後相同 key lookup 失敗，直到別處重新插入；這本身沒有提供 instance generation 或 Lua callback。

### 6.2 不能跳過的 ID low-byte 前置

`4B299B` 讀的是**實際 actor+04** 的 WORD，並依 AL 分支：

- low byte `0/1/6/7`：進 model 顏色／效果重置區，並受 `+15C`、`+370` 等條件限制。
- low byte `2/8/9`：`4B2A25` 檢查 `actor+F4 != 0`、`+124 == 0`，且 `float(+134)/float(+130)` 大於原件 double `0.6000000238418579` 時，呼叫 `4CC8B0`。
- 其餘值：不走上述兩類前置，仍可進共同 controller／移除段。

[I13、D19]

`4CC8B0` 會把 `+F8` 作分支、把 `+128` 作 ID 或位置、讀 `+10C/+110/+114/+118` 等，並把 `+124` 寫成 1。[I14] 這不是通用 CMonster 布局；S2 已辨識 CActor FSM state 陣列就在 `+F4` 後方。**不應將任意 local counter ID 恰好 low byte `2/8/9` 的 CMonster，自動視為與該前置函式相容。** 實際 gate 可能使 helper 不被呼叫；本輪沒有測試它一定會進入或一定崩潰，只指出共同 map lookup 不足以證明全範圍可安全移除。

例如原始 counter 值 1001 的 `E9` 不觸發此特殊前置，故不能反向誇大成「本地怪全都無法移除」。正確界線是**封包、目前 ID 與實際物件布局逐一配對**；Server 不能以任意流水 ID 取代 typed world ID 契約。

### 6.3 世界索引的生命週期

另核 `4DFE90`：它遍歷 owner 的 map node，對非空 actor 同樣呼叫 `v+14`、`v+00(1)`，再 `823850` 清 tree nodes，最後清 controller。[I19] 已成功進 map 的本地 actor 因而受同一索引清理流程管理。這只說明該 clear consumer 的效果；本輪沒有重新盤點每一種換圖／重新載入是否一定呼叫它，也沒有把未成功入 map 的碰撞物件 B 視為必然被這個 traversal 清掉。

## 7. attach 不能充當可靠的 ID 回報

既有 `000A` 控制 row 的 producer 確實可能寫出 actor ID，不能因 CreateObjectEx 沒有 Lua ID 回值，就全局宣稱 Client 從不把本地 ID 送出。需要分開檢查能否當「每次本地生怪的可配對 ACK」。[S5]

本輪沿 attach 後普通 Single／Tutorial 的 mapper `546100`，在 `5461F0` 讀 actor+88 的 model 低 WORD，`5461FD` 比較 9，`546200` 對較大 model 跳至 `54615A` 返回 AL=0。ordinary monster 1036 無法靠此分支產生正常新控制 row。model≤9 也仍須通過 CCharStatus[model]+5C 等 gate。[I40]

S5 的舊控制 bit／Q+58 neutral-row fallback 仍可能在特定前態送一筆 row；它不是每個 `CreateObjectEx` 呼叫都會發生、能跟 spawn 請求一一配對、帶成功與 generation 的身分 ACK。因此此具體候選不補足 Server 所需的 ID 回報，並非證明所有未查的 C2S 路徑都不能攜帶該 ID。

## 8. 可操作情境矩陣

| 情境 | 目前可以採用的契約 | 不能聲稱的能力 |
|---|---|---|
| Lua 只要建立本地外觀／有限場景 actor | 已閉合 factory 與插入流程可作靜態能力依據，仍須滿足資源／runtime 前置 | 不自動取得 Lua EntityId、多人一致性、Server 戰鬥權威 |
| Server 另有已證方法確知唯一 ID K，且物件布局一致 | 表列 world update handler 可對 K 命中的 actor 更新；已證 native 欄位 consumer | 不等於本輪已找到這個可靠 ID 來源 |
| Server 補發同 K 的 `0007` | 若 key 存在，整 row 跳過，可作 duplicate skip 行為理解 | 不採用、不覆寫 metadata、不 remap、不確認同一 actor |
| 先刪除本地 K 再發同 K 的 `0007` | miss 必須重新滿足 low-byte factory 契約 | `03E9` 等任意本地流水 ID 不因先刪除而成為合法 monster ID |
| 新舊 actor 碰撞同 K | 後續 lookup 取世界樹中保留的舊 pointer | 不保證 attach 的新 pointer 與 world lookup 指向同一物件 |
| 移除已索引本地 CMonster | 在該 ID 的前置／布局條件成立且正常返回後，001A 確實清理、delete、erase | 不等於 death／group-clear 事件已回到 Lua |
| Lua 想知道某怪是否死亡／消失 | 本輪具體新 getter 未提供這個一般 world 身分狀態 | 不可用 GetLeaderPosN=0 或 IsCharacterAvailable(key)=0 代替 |

## 9. Server 開發需求、Client 未知與待驗證

### Server 開發需求

1. **維持權威物件身分表。** 以副本／場次、generation、typed EntityId 與 model／class 分開記錄；分配、重用、刪除時遵守已知封包類別。不要以 Client 初始 counter 1001 或各端預期呼叫次數推算 ID。
2. **在替換 Server spawn 之前補上可靠對帳條件。** 必須存在已證的 Client 可用途徑，讓 Server 能知道「這個 instance 裡，新建的是哪一個 actor、ID 是多少、是否真的插入成功」。本輪列為能力缺口；未捏造新 opcode、未修改 Client，也不把未證實的 CreateObjectEx 回值當這個途徑。
3. **不要以 `0007` hit 作 owner／model 更新或接管。** Server 須避免碰撞並使用與目標一致的既有更新契約；可靠身分橋尚未完成時，應把生怪下放標為未完成的 Server／內容開發需求。既有 Server world spawn 只作未替代基準；後續驗收要確認停用目標 Server 生怪操作後，新內容仍建立正確物件，且更新、移除與場次切換一致。
4. **按實際目標型別發送後續狀態與移除。** exact-ID 查找能命中是必要條件，還須考慮 `001A` typed prelude、FSM slot、controller、資源與資料範圍。Server 對群組成員、死亡／移除去重與關卡判定保留明確紀錄，不能把外觀移除當 Lua 已知的群清事件。

### Client 仍未知的範圍

- 有限已查 lb／Q inventory 與本輪具體候選之外，是否另有可取得普通 actor ID、狀態、generation 或可配對身分 ACK 的入口，尚未閉合；這不是全程式不存在的證明。
- 全部 typed EntityId 範圍／保留值、local counter 在所有 mode 與場次的重設時機、所有非 map 持有者的清理，不在本輪窮舉範圍。
- ordinary death／group clear 到 Lua 的一般 observer，沿用既有事件報告的缺口；位置／固定 roster 旗標陽性不能補成這條橋。

### 待整合／實機驗證

本輪 PASS 只指唯讀靜態證據一致。未執行 Client／Lua、未送測試封包、未驗多人、reload 或長時間 ID 回收。後續整合若具備可靠身分來源，應先測唯一合法 typed ID 的 spawn／update／delete，再測重複 row、漏失／重送與場次切換；不能把本輪 bounded static PASS 寫成可完整替代 Server 戰鬥或原生 MEF 的功能 PASS。

## 10. 重現與驗證結果

最小交付檔：`report.md`、`native-windows.json`、`native-windows.asm`、`source-manifest.json`、`verify_evidence.py`、`verification-result.json`。`capture_evidence.py` 是可選的重新擷取工具；`sources/`、`exploratory/`、候選字串暫存不需發表。

唯讀驗證命令範例：

```bash
python -B verify_evidence.py --bin /path/to/02-Tartaros.bin --repo /path/to/ttr_anal_multi
```

verifier 對原件 SHA256、PE mapping、每段 raw／hex／SHA256、完整 instruction 邊界、選定 branch/call、vtable target 與固定 Git commit/path/blob 做檢查；Git 使用 `GIT_NO_LAZY_FETCH=1`、`GIT_OPTIONAL_LOCKS=0`，不 checkout、不 fetch、不改索引。為防止 objdump 在截斷最後一條 instruction 時仍印出完整 mnemonic，重新解碼會讀過所選 end 邊界再核對完整長度。

本次結果為 `PASS`：43 個 code windows，共 9,331 code bytes；23 個 data records；33 個選定語義／控制流檢查；8 個 vtable target 檢查；79 個固定來源 pin。數字與最終 artifact SHA256 以 `verification-result.json` 為準。
