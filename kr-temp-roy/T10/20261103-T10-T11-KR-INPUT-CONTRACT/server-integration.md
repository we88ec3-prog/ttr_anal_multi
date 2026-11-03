# KR 0A → Server 意圖適配與 S00 交接

日期：2026-11-03（Asia/Taipei）。本文件是可據以實作的適配契約與證據邊界；**沒有修改或部署 Server，也沒有新真人驗收結論。** 原件、controller CFG、欄位來源詳見 [input-contract.md](input-contract.md)；動作生命週期與時間詳見 [action-buffer-state-machine.md](action-buffer-state-machine.md)；精確來源碼見 [evidence-index.md](evidence-index.md)。

## 1. P0：先移除錯誤前提，再判定實際卡住在哪一層

**8000不是方向held；action-only row一般不能區分「方向仍按＋Z」和「已放方向＋Z」。** 正常廣場Single的546100可把這兩個不同輸入歷史編成同一個row；相同heading與先前moving紀錄也不能保證消歧。這是資料已經合併的問題，不能由Server加一條固定last-key或Z強停規則還原。[N-5461；N-SQUARE；S-W01]

本輪P0可以立即解除的是**把缺陷修復建立在錯誤Client規格上的阻塞**：S00可以實作無損row觀測、分開wire移動報告／action候選／已執行狀態，並核對既有新診斷中的實際輸入與回覆。不應宣稱僅憑這份靜態資料，就已恢復玩家「held方向連點Z可走、released方向只Z不續走」的兩種情境。

### 1.1 正常廣場同值反例

前提：Type0或等價mapping、正常Single callback、actor/table/FSM與availability條件允許M1保留、owner+58=0、batch可送，collector的held方向恰等於actor目前B0=h。

```text
history A: direction held + Z  -> {actor=1234, word=0001, byte5=h}
history B: direction released + Z, no other heading source
                                  -> {actor=1234, word=0001, byte5=h}
wire in either history: 34 12 01 00 h
```

這是符號輸出，不是抓包。任何只讀這些相同觀測、卻必須在A「繼續移動」、B「停止移動」的確定性Server分支，都缺少能選正確分支的資訊。沿用上一個moving會偏向A，遇B可能續走；看到action就清moving會偏向B，遇A可能卡移動。**兩個預設都不是physical鍵狀態的可靠解碼。**[N-5461；S-W00-116]

這不排除完整實測中存在可用的direction-only／neutral rows，也不排除某個具體Server回覆造成Client FSM卡住。這些必須查現有row內容及S2C時間線，不能從只有152筆opcode／長度的舊log補算。[使用者現場描述；N-5452；N-STATE]

### 1.2 最小分流順序（以既有診斷為來源，不要求改Client）

| 既有診斷若顯示 | 可判定的層 | S00應核對的下一項 |
|---|---|---|
| 保持方向、Z釋放間隔確有8000 rows，但Server未發相容moving=1狀態 | Server適配／規則／回覆 | 是否仍有Z鎖、錯誤actor歸屬、同actorrow去重、固定動作分支或狀態機吞掉movement候選 |
| 0A只有action-only／neutral，而Server最近對廣場Z送了000D | Client接收狀態可能影響之後輸出，仍須核對完整時序 | 000D要求FSM13；其+2C/+30預設0，後續是否有正確state轉換；不能只以motion播完推理FSM必已恢復 |
| 0A有word0，而Server仍以舊moving執行 | Server的移動生命週期 | 這筆是何種producer／override；是否真的採用舊moving作持續政策；不能把它說成Client仍held |
| held+Z與released+Z整段可觀測rows仍相同 | 協定資訊不可辨識 | 明列產品行為與可觀測性衝突，保留需求待決；不得用未公開heuristic宣稱還原 |
| 同actor一包有多row | producer順序／合併策略 | 保留全部row和原順序，不能先last-wins後拿結果分析按鍵 |
| 0A很久不送 | 發送／state／availability／UI等gates | 區分沒有row、credit不足、latch gate、state gate與transport；不能把沉默當release或仍held |

以上是讀取診斷的判定路徑，**不是聲稱新診斷已出現任何一項**。現在已知仍只有依序四正向＋Z的整體未通過回報；沒有四組獨立結果，v16尚未通過。

## 2. application decoder：先保全所有觀測

0A application內容（外層framing另採既有T10-115）：

```text
offset 0 : u16le command = 0x000A
offset 2 : u32le application_header_raw = [F93944] at build time
offset 6 : rows, each 5 bytes
           u16le actor_id
           u16le raw_word
           u8    raw_byte5
```

正常builder長度為`6+5*N`。row沒有keyboard-edge序號、按鍵timestamp、每次Z計數或producer標籤。headerDWORD的業務身份未閉合，保留原值，不能借名叫nonce、held bitmap或timestamp。[S-W03T；S-T115；N-5452]

建議的**Server適配結構**如下；這些是設計欄位名，不冒稱原版Server C++型別：

```text
InputBatchObserved
  receive_ordinal                    # Server本地順序
  received_at_monotonic               # Server接收時間，不是Client按鍵時刻
  application_header_raw_u32
  scene_context                      # 來自已知session/scene
  controller_provenance              # known / inferred / unknown；帶來源
  rows[]                             # 不排序、不去重
    row_ordinal
    actor_id
    raw_word_u16
    raw_byte5_u8
    raw_row_bytes[5]

InputRowObservation
  source = (receive_ordinal, row_ordinal)
  action_field_low15 = raw_word & 0x7fff
  reported_move_bit = (raw_word & 0x8000) != 0
  observed_heading_or_state_byte = raw_byte5
  producer_kind = Known546100 | Known5480E0 | Known546EF0 | Override | Unknown
  heading_provenance = CollectorNow | ActorB0BeforeCallback |
                       ServerE4Feedback | LocalAICandidate | Unknown
  physical_direction_held = UNKNOWN
  physical_pressed_edges = UNKNOWN
  physical_released_edges = UNKNOWN
```

`producer_kind`與heading來源**不在wire內**。scene／actor roster可協助限定，但同actor可同時出現在RowA和RowB，僅靠row index或actor ID不一定足以指定producer。無閉合來源時保留Unknown，不把推測提升成Known。[S-W00-116；N-5452；N-CONTROLLERS]

### 2.1 可直接做的無損規則

1. 每個batch保留原始header、所有rows及順序；單row與多row使用同一解析器。
2. 分別取low15與highbit，保留raw_word。收到兩者均非零時不要直接判不合法；Formation副角色有不同producer。
3. 不把low15直接當key code或一串技能事件。mask3／5是有獨立consumer的候選組合，不能拆成「Z一次、X一次」或「Z一次、C一次」。
4. 不把RowB的bit2叫實體X：已證546EF0可由目標距離>70設這個bit。
5. 不把fifth byte無條件當最後一次physical方向；根據已知producer保留候選heading、B0快照、E4回授或AI狀態來源。
6. 不從兩個相同rows推兩次pressed，不以相同row去重證明沒有第二次pressed。兩種推論都超出wire保存的資訊。
7. 不用Server接收clock推算確切Client按鍵edge時間。frame取樣、latch、發送節流與transport均在兩者之間。

上述規則由producer／collector／batch資料流支持，沒有指定任何官方Server動作選擇演算法。[S-W01；S-W03C；N-5452；N-5461；N-ROWB]

## 3. 從觀測到有限意圖：保留unknown而不是暗設按鍵政策

對已知正常546100 producer，可產生下列事件。未識別producer時只產生RawObservation，保留更多解釋可能。

| raw內容 | 可產生事件 | 可附帶的結論 | 不可附帶的結論 |
|---|---|---|---|
| low15=0、8000=1 | `MovementReported(value=true, heading)` | producer報告移動位元為1 | 方向鍵一定held、一定可通行、一定已位移 |
| low15=0、8000=0 | `MovementReported(value=false, heading)`／neutral觀測 | producer這次不報移動；可來自release、gates、override等 | 一定收到物理release edge |
| low15!=0、8000=0 | `ActionMaskObserved(mask, heading)`與`MovementReported(false, reason=action-gated-or-unknown)` | 正常546100可能因保留action略過移動分支 | 方向已release，或方向仍held；不是自帶兩種事實的full-key snapshot |
| low15!=0、8000=1 | 保留兩個獨立觀測並檢查producer | 不能套546100定理；Formation等路徑另核 | 全域不合法、應強制丟棄action或movement |
| 沒有此actor row | `NoObservation`（若需要） | 這個batch沒有該actor資料 | 物理released、仍held、動作已完成 |

`reported_move_bit=false`是確定的wire值；`physical_direction_held=unknown`是確定的資訊限制。這兩個欄位要同時保留，不能用unknown吞掉原始0，也不能用原始0冒充物理release。[N-5461]

實際`MovementExecution`是否依某一事件開始、停止或暫停，是Server policy。若相容方案決定依wire報告改變權威moving，需明寫其場景與動作交錯政策；若決定短暫保留移動，也須明寫為候選，不能稱從held位元讀出。這份工作包不偷偷選其中一種來掩蓋同值反例。

## 4. 移動、動作與狀態回覆要獨立提交

建議Server維持三個不同的狀態紀錄：

| Server紀錄 | 證據對應 | 用途 |
|---|---|---|
| `LastInputObservation` | 最後收到的原始0A row及其來源 | 稽核輸入，不當作執行狀態 |
| `AuthoritativeMovement` | Server自行決策後發出的000B值 | moving、heading、position；記錄決策原因與來源row |
| `ActionExecution`／`ClientFSMDirective`／`MotionDirective` | 000C、000D各自欄位 | action是否受理、選擇哪個motion／state、開始／結束依哪個政策；三者不合成一個pending旗標 |

### 4.1 必須遵守的下行相容性

以下FSM／B0 concrete consumer以已核實的CActor／CCharacter為範圍；actor存在且相應state slot有效才成立。

- `000B` 的flag bit0會成為actor E2.bit15；heading更新E4與B0；位置另有correction gates。
- `000D`的heading會由v58套用，`4C8A90`要求FSM13，再把motion WORD／float交v68；**它不直接清E2 moving**。
- `000C state5`對已核CCharacter可進CAttackedState並由entry提交motion9；`000D motion9`仍先要求SkillState13，不能只因畫面motion碼相同就當同一狀態。
- `000E`走scene結果consumer；不能採11/1 P0B的controller-vtable解讀而省略結果路徑。
- `012A`是skill-key timer更新／reset；`00DA`只補0A發送額度。都不是待處理動作被消費的ack。

這些是Client會怎樣讀資料的要求；官方Server對每次普攻／技能／受擊應送哪些row、順序、時間與數值，須分開列為尚未證實的policy。[S-W04；S-W06；N-STATE；N-TIMER；N-RESULT；N-DA]

### 4.2 可直接改善診斷而不新增Client假設

對Server每次狀態決策，保存`source input row → interpretation → policy version → actual outbound messages`的關聯。若發出000D卻沒有000B／000C相關轉換，紀錄這是有意保持、未決，或程式遺漏。**紀錄Server自己的決策與已發封包，不等於聲稱Client已ACK或畫面已完成。**

應優先查正常廣場Z是否被Server誤映為戰鬥施放並反覆發000D；這是待核對假設，不是本輪已證缺陷。單就native介面，讓actor留在state13可能抑制之後的collector／movement輸出；是否發生在v16，現有資訊不足。不得為了測這個假設直接改Client或編造新抓包。

## 5. action mask → skill候選的邊界

### 5.1 已證的本地predicate，可作相容性參考

在Type0、單一fresh mask、正常player路徑，Z/X/C候選bits為1/2/4。`54F270`以3→matrix col4、5→col5、6→col6，單bits1/2/4→col1/2/3；其他bits與特殊分支保留原碼。mask7在**此predicate**先命中col4。[S-W03C；S-W05]

Server可保存這個映射作`LocalAvailabilityInterpretation`，但不得據此證明：

- Client確實同時按下兩鍵，而非跨送包gate累積。
- Server應啟動兩個技能，或只依某個固定鍵優先。
- matrix候選一定可施放、資源足夠、命中，或已消費pending。
- 全部actor、全部controller都把相同low15當同一個物理動作。

### 5.2 若Server需要pending，請把候選政策明放在另一層

```text
ActionCandidate
  source_batch, source_row
  actor, scene, raw_mask
  observed_heading, heading_provenance
  server_observed_at
  availability_interpretation

ServerPendingAction                 # 可選Server設計，並非native已證型別
  candidate_reference
  chosen_action                      # 由明示policy產生
  queued_at_server
  expiry_rule = Unspecified | PolicyRef
  replace_rule = Unspecified | PolicyRef
  heading_rule = Unspecified | PolicyRef
  interruption_rule = Unspecified | PolicyRef
  resource_commit_rule = Unspecified | PolicyRef
```

可直接完成的是觀測與候選建模；如果現有Server已採basic1／skill-latest1／0.4s，可以把它們以明確policy版本繼續比較，**不能在native contract中把它們改標已確認**。本輪不替S00核准這些值，也不以固定last-key或Z強停完成`Unspecified`欄位。

## 6. 現行 Server 候選逐項對照

| 使用者提供的候選 | 與Client證據相符部分 | 不相符／未證部分 | 適配要求 |
|---|---|---|---|
| 廣場讀8000作moving | 可保存為該row的reported move bit | 不能當physical held；不能單靠action-only辨release；不保證可通行 | 分離report、held未知、執行狀態，檢查實際row與回覆 |
| 戰鬥動作抑制移動 | 546100 retained low15確實略過movement寫位 | 不是全控制器通則；Formation副角色不同；000D不自清E2；官方技能移動政策未知 | 用具體producer／state限定，不做全域action優先 |
| 普攻一個pending | Client有一個共享WORD latch | 沒有一個獨立basic-slot容器證據；OR不保存次數 | 標Server候選 |
| 技能一個最新pending | timer同key可覆寫counter | timer不是pending skill；action OR不是latest-wins | 標Server候選，與input adapter隔離 |
| 0.4s期限 | 可用Server monotonic clock實作候選 | send ms gates、/33 visits、actor418都不證此值 | 保留未知native時間，不換算猜填 |
| 固定action分支 | 54F270本地predicate確有分支順序 | 不能推正式Server普攻／技能仲裁與cancel優先 | 每項政策帶來源或標替代設計 |

## 7. 最小正常時序驗證契約

本輪不執行遊戲、Server或測試腳本。以下供現行診斷收件後對照；不增加異常、相反鍵、重登、併發等測試。

### 7.1 每次正常試驗應分段，而不是只記一個總結

對單一方向依序標記：方向按下→保持→Z按下／釋放／再次按下→方向釋放而Z繼續→方向重按→Z停止且只改方向。四正向＋Z及四斜向＋Z、左上＋X、左上＋Z＋X、Z＋C的條件式預期在CSV。**按鍵時刻來自真人分段標記，不從封包反推。**

每段可利用既有診斷核對：原0A header、每筆row ordinal／actor／word／byte5、接收時刻、Server採用的move／action決策、對應000B／000C／000D／000E／012A／DA發送時刻、場景／actor角色與policy版本。若目前診斷未包含某欄，只列缺件；不得聲稱已收集到。

### 7.2 三類判讀結果

| 結果 | 能證明什麼 | 不能證明什麼 |
|---|---|---|
| raw row與本契約條件式規則一致 | 該次producer假設受到支持；可定位Server後續行為 | 全controller FULL-PASS或所有按鍵都已通過 |
| raw row不同，但controller／UI／actor state未知 | 有需要補上下文的差異 | 直接宣布原件錯、任一方向獨立fail或改Client |
| 正常序列畫面與Servertrace都符合需求 | 這一組情境可提交真人驗收證據 | 尚未測的其他方向／組合自動PASS |

舊152筆只有opcode與長度，缺raw row；不能列入這些逐段比對。v14／v15／v16狀態按使用者描述保留，不靠推測重新判定。

## 8. S00 收件與責任邊界

| 類型 | 本輪交接 |
|---|---|
| 可立即整合的Client介面 | context-aware 0A無損觀測、highbit非held、動作mask／heading時點、完整0A gates、S2C movement／FSM／motion／結果／timer分離 |
| 需要修正的既有認知 | 廣場不是548350；Row5不是一律B0；5467F4才WORD store；000E receiver是scene；DA index是00DA；sender clock可證ms |
| Server待開發需求 | 可觀測移動與動作的仲裁、pending策略、選招、cost/CD事件、動作／受擊結束與cancel政策；目前未知的原版時間保留未知 |
| Client待逆向 | 已列出的精確下游與欄位命名缺口；不把此類缺口整批推給Server，見action-buffer與證據附錄 |
| 跨功能待整合 | 對接既有S00技能／教學工作卡與W04/W05/W06；需求ID由S00去重納入現有REQ/SPEC/GAP/TEST，不另建平行台帳 |
| 待遊玩驗證 | 新診斷尚無結果；本輪沒有修復／通過宣告 |

目前無對應T10/T11的現行RR；未自改CLAIMED、SUBMITTED、ACCEPTED、T01退回或FULL-PASS。未Commit／Push本輪研究；只有既有T10分支的本機main同步merge。這些檔案可供S00檢視與實作，不等於規格已STABLE或Server已部署。
