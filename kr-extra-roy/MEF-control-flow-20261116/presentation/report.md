# MEF R10：演出資源持有、原生清理與完成條件

本分題補上「腳本已停止」到「畫面與資源已恢復」之間的原生流程。原件為 `02-Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。所有新結論由 PE raw mapping、原始 bytes、重新反組譯、實際 callsite／receiver／vtable 支持；既有 Q 綁定與輸入協定沿用固定 public R9 commit，並重新核其原件立即值。未啟動 Client、未執行 Lua、未改遊戲資源。

證據入口：[原生視窗](native-windows.json)、[可讀 ASM](native-windows.asm)、[重要指令與綁定](native-assertions.json)、[固定來源](source-manifest.json)、[機器可讀契約](contracts.json)、[唯讀驗證器](verify_evidence.py)、[驗證結果](verification-result.json)。本稿與[外層 supervisor](../supervisor/report.md)、[演出完成觀察](../world/report.md)共同構成清理端契約。

## 1. 結論與範圍

**原生 End 不是 bulk cleanup；Stop 只有在 Q 仍 active 時才進入主要清理段。** 因此新內容不能先 End，再期待 Stop 修復地圖、相機與顯示狀態。相機 override 是依名稱回溯、會實際移除紀錄的堆疊；地圖備份卻只有一份；兩者都不能被當成任意重試的無狀態 reset。

可用的公開 `CameraWorks.Stop`、`CameraWorks.IsEnded` 只作用於目前 native camera owner。`Q.DetachCamera` 清除 current pointer，`Q.EndCameraOverride` 回復具名 snapshot，三者是不同動作。Letterbox、物件 render、慢動作與 sepia 也各有不同的 owner 和消費點。特別是 EndSepia 只發出 phase 4 請求，還需三次原生更新才能到 phase 0。

這些證據使「內層 entry 失敗後，外層仍可按持有紀錄收尾」成為具體的**條件式內容設計**，不是已存在的原生 `.mef` parser／executor，也不是 ordinary 背景 runner 已完成。可部署的合法 key、地圖、模型、時限仍未分配。

## 2. End 與 Stop：清理必須早於生命週期終止

| 路徑 | 原件控制點 | 真正效果與限制 |
|---|---|---|
| `Q.EndCutScene` → `0x561DB0` | normal non-review active 分支 `0x561F69` 先清 `M+0x28`；其後原本 confirmation／003F、qco removeAll 與 UI／key 路徑 | 本函式沒有 Stop 的 RestoreMap → DeleteAllObject → EndCameraOverride bulk 鏈。正常 coroutine return 也不會自動等價 End。 |
| native Stop → `0x5624B0` | `0x5624E7 xor esi,esi`；`0x56251E cmp [edi+0x28],esi`；`0x562521 je 0x562891` | inactive 會跳過主要清理。最前方另有參數／quest 1000／scene 15–18 特例，不應將整個 Stop 說成完全無副作用的 inactive no-op。 |
| active Stop 主段 | current CameraWorks virtual `+0x0C`；`0x56268B→0x563FA0`；`0x562694→0x563A70`；`0x56269D→0x562B00` | 依序停 camera works、RestoreMap、清 Q actors、pop camera override；需要有效原生 context。 |
| Stop 對演出 observer 的取消 writer | `0x5625F5 [0xFC1C6C]=ESI(0)`；`0x5626A2` 測 Stop 參數，非零才由 `0x5626D5/6DA` 選 `0xFC1B18` 並呼 `0x55F8A0` | Book active 在 RestoreMap 前直接清零；Prolog close 在 override pop 後且受參數 gate。兩個 observer 的 0 都不能單獨證明正常播畢。 |
| Stop 顯示／輸入收尾 | `0x5626ED` letterbox owner `+0x0C=0`；`0x56273F/745` sepia phase 4／argument 0；`0x562779` Q slow 0；`0x56281E` render 0；`0x56284A` input mask 清 mask `0x2`（bit index 1） | 各自處理特定 owner；不能推論世界模擬／所有 controller owner 均恢復。 |
| Stop 結尾 | `0x562883→0x553740` 共用 G selective sweep，`0x56288C→0x561DB0` | **End 最後才呼叫。** 此 sweep 依型別 `v+0x28` 選擇，不等於 Tutorial tracking 標記／清空；Skip／Scaling 恆回 1 而被保留。 |

`M` 為 Q manager `0xFB73C0`。上述地址均是完整指令起點。End 的 nonzero quest confirmation gate、skip 也可能送 003F 的反例、00EB 並不清 Q active/list/controller，沿用 [R9 完整流程](../../MEF-end-to-end-20261116/flow-contract.json)與 [R6 輸入生命週期](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)。本輪沒有將 003F 改造成「腳本執行／清理成功 ACK」。

**可重現的靜態反例：** 若 active End 已使 `M+0x28=0`，隨後 Stop 在 `0x562521` 跳到 `0x562891`，上述地圖／actor／override 清理 callsites 均不會執行。這是分支證據，不是推測畫面效果。Q 的已核 63 個一般名稱加 Rebind 中沒有 `Q.Stop`；不要將 native Stop 位址直接當成現成 Lua API。

## 3. Camera override：有名稱的 snapshot stack，會吞掉不匹配紀錄

### 3.1 真正 push 的內容

`Q.BeginCameraOverride 0x562A60` 取得 current camera `C=[0xFB76E8]`，把 `C+0x0C` 數值 snapshot 加入 `C+0xA0/+0xA4` vector。`0x798900` 每筆配置 `0x48` bytes：前 `0x2C` 是 11 個 DWORD，後面是字串物件。Begin 在 append 後，取 vector end−`0x1C`，把新最後一筆的字串標成 **`QSceneCam`**（原字串 `0xC1070C`，長 9）。這不是每次執行獨一無二的 run token。

### 3.2 pop 的副作用早於名稱核對

`Q.EndCameraOverride 0x562B00` 呼叫 `0x7986E0(C,"QSceneCam")`。原件順序為：

1. 由 `(end−begin)/0x48` 取得紀錄數；從最後一筆開始。
2. `0x79877C` 先將 11 個 DWORD 複製到 current camera `+0x0C`，並複製字串。
3. 移動／銷毀尾端紀錄，`0x798856` 將 end 減 `0x48`。
4. `0x798872` 才作不分大小寫名稱比較；相同於 `0x79887C` 跳到返回路徑。
5. 不同時記錄 `Popcamera Fault : Required %s, Popped %s`，`0x7988B4` 仍有紀錄便繼續 pop。

因此未配對 EndCameraOverride 可能移除別人的 camera snapshots。若有巢狀、同名的 QSceneCam，每次只到最近的同名紀錄為止；若已經被外部 Stop 消耗，內容層再重試 pop 也不能保證安全。

新內容須記錄本次成功取得的 override 層數與釋放狀態，禁止把 EndCameraOverride 放進不看 owner 的重試迴圈。多 run 並行／外部場景切換會破壞這個簡單 ledger 的前提，應交由跨功能整合的取消協定處理。

## 4. CameraWorks、AttachCamera 與 DetachCamera 的不同作用

### 4.1 公開名稱與實際 receiver

`0x54E750` 建立 current pointer `0xFB7620`、KeyFrame singleton `0xFB7624`、AttachSceneObj singleton `0xFB766C`，並在正式 VM `0xFDF3C8` 註冊 `CameraWorks`。namespace 初始化 `0x54EA20` 保存 VM 到 `0xFE1E24`、receiver 到 `0xFE1E28`。新核的兩個名稱為：

| Lua 名稱 | registrar／closure | native target | 作用 |
|---|---|---|---|
| `CameraWorks.Stop` | `0x54ECE0`／`0x54EF60` | slot `0xFE1E38` → `0x54E9F0` | 先解 current pointer；非 null 才 tail-call virtual `+0x0C`。 |
| `CameraWorks.IsEnded` | `0x54ED80`／`0x54EFC0` | slot `0xFE1E3C` → `0x54EA00` | null 回傳數值 1；非 null dispatch virtual `+0x20`，closure 推 Lua number。 |

IsEnded 的數值 0／1 必須用明確數值比較，不能直接以 Lua truthiness 判斷。Stop closure 的 native return 1 並非新推入的成功 ACK，不能用它證明 native camera owner 存在或成功恢復。

本輪 RTTI 及 9 個 slot 的界線由原始資料核實：Attach vtable `0xC0FD48`、COL `0xC6CAE8`、type `.?AVCCameraWorks_AttachSceneObj@CameraWorks@@`；KeyFrame vtable `0xC0FD20`、COL `0xC6CB34`、type `.?AVCCameraWorks_KeyFrame@CameraWorks@@`。緊接其後的 COL 不是第 10 個 virtual method。

### 4.2 Attach 使用 Q actor slot

`Q.AttachCamera 0x563830` 將轉入的數值寫到 attachment 的 `+4`（`0xFB7670`），令 current pointer 指向 `0xFB766C`，呼叫 virtual `+8`。實際 start `0x54E3C0` 保存 camera snapshot，從 **`0xFB73DC` Q tree** 依這個 slot 查找 node，再取 node `+0x10` 的 actor／render resource 與 `CAMERA_DUMMY01`。不是 ordinary world entity ID 查找，也沒有把 missing actor 轉成內容層成功 ACK。

主更新 `0x492410..0x492428` 取得 `[0xFB7620]`，把 frame delta 傳給 virtual `+0x10`。Attach 實際到 `0x54E580`，在 `+0x38==0` 時再查同一 Q slot／模型節點，更新 pose，進 `0x54E340` 套用。這是實際 native attachment frame consumer，沒有由此註冊或恢復任意 Lua closure。KeyFrame 同一 slot 指向 `0x476430` 的 `ret 4`；不能把這條 callsite 當成 KeyFrame 自己的進度來源，其其他 virtual 更新不在本項結論內。

Attach Stop `0x54E570` 只把 `+0x38=1`；Attach IsEnded `0x54E740` 讀該值。KeyFrame Stop `0x54E260` 清 `+0x40`，IsEnded `0x54E310` 依 playing／frame 條件回答；兩者的結果都不代表 Q coroutine、一般怪物或 Server 關卡完成。

`Q.DetachCamera 0x563900` 的關鍵寫入是 **`0x563954 [0xFB7620]=0`**。它沒有 pop camera override、沒有刪 Q actor、沒有呼叫 End，也沒有恢復舊 CameraWorks pointer。因此內容若持有 camera works，可先 Stop，再依需要 Detach；相機 snapshot 的平衡釋放仍是另一項工作。

## 5. LoadMap／RestoreMap：單一共用備份，非巢狀交易

`Q.LoadMap 0x563C40` 在非 null path 路徑，將 current camera 的 11 個 DWORD 複製到 **`M+0x30` 指向的同一 buffer**，將目前世界 map `0xFAB178` 存到 **`M+0x34`**，以 path basename 呼叫已知 FLD loader `0x7C1E00`。有 terrain camera 資料時，接著改 current camera。它沒有回傳可供內容使用的整體資源成功 ACK。

`M+0x30` 在 Q constructor `0x560170` 配置，`0x7CD2B0` 建立 default camera snapshot。這個初始值不等於本次內容進場前的 current camera。重複 LoadMap 會覆寫同一份數值與 map ID，不能假設任意層數的 RestoreMap 能回到最外層。

`Q.RestoreMap 0x563FA0` 使用 `M+0x34` 查相關表資源；關鍵 getter 的 receiver 是 **`0x564090 ECX=0xFB74B0` → `0x564095 call 0x4F7DF0`**，取得 map filename。這個 root 與尚未閉合的 MapList.TRIGGER `0xFB74C0` 不同，不能用此路徑宣稱原生 `.mef` 首載入者已找到。

還原尾端將當前 `0xFAB178` 再寫回 `M+0x34`（`0x56434D/353`），以取得的 filename 於 `0x56435C→0x7C1E00` 載入 FLD，再於 `0x56439A→0x798370` 套用 `M+0x30` 的 camera snapshot。故它會改變備份欄位，也不是可無限重試而不變的 restore。

條件式內容設計應要求本次確實有有效備份、沒有其他 run 覆寫、相關 table／FLD 可用。沒有這些前提時，應回報 cleanup 未完成，不能盲呼叫 RestoreMap。native Stop 的自有呼叫順序可供實作對齊，但不構成所有任意 Q 使用方式均有可逆 snapshot 的保證。

## 6. 顯示、慢動作與輸入各有 owner

世界 singleton `G=0xFAB130` 由 `0x40F060` 取得；constructor `0x4DEC90` 初始化 map `+0x48`、render `+0xA8`、慢動作 countdown `+0xAC`、Q slow flag `+0xB0`。

| 表面操作 | 真正寫入 | 新核的消費點 | 可成立的完成語義 |
|---|---|---|---|
| Disable／EnableObjRender | `0x5647A0`／`0x564810` 寫 `0xFAB1D8` 為 1／0 | main render `0x492B19→0x40F060`、`0x492B20→0x4E0540`；該函式以 `G+0xA8` gate controller virtual `+0x34` 及 world tree；`0x4E1470` 對 actor virtual `+0x28` | 只控制這段 world rendering。field render 在 gate 前仍呼叫；不能證明怪物／世界模擬停下。 |
| Start／EndSlowMotion | `0x565640`／`0x5656B0` 寫 `0xFAB1E0` | main `0x492599..0x4925AA` 傳 `G` 與 delta 至 `0x4E0200`；`G+0xAC>0` 或 `G+0xB0!=0` 時，以原件 double `0.20000000298023224`（約 `0.2`，bytes `000000a09999c93f`）縮放選定 actor animation delta | 清 Q flag 不會清獨立 countdown，也不影響 Server 時間。 |
| 同一 animation pass | field virtual `+0x18` 與最後 controller virtual `+0x30` 仍收原 delta | worker vtable `0xC0CF2C` → `0x4E0520`，把縮放後 float 傳 actor virtual `+0x24` | 不能將這個演出效果稱為統一世界時鐘。 |
| 獨立 controller owner | `0x4E0060` 在 `G+0xAC>0` 路徑置 controller `+0x58=1` | native world update | Q.EnableInput 清自己的 mask 不足以證明其他 owner 不再鎖控制。 |

本輪修正一項容易被 bulk 函式邊界誤導的讀法：EnableObjRender 完整 native 範圍只到 `0x56487E`；後面的 `0x564880` 是另一個 getter。不能用 bulk 下一個檔名 `0x564900` 當本函式終點，把兩者混作單一行為。

## 7. Letterbox 與 Sepia：flag release 與延後完成

### Letterbox

Show `0x564B00`、Hide `0x564B50` 控制 `0xFE36EC`，即 owner `0xFE36E0+0x0C`。原生 render callsite `0x492EEE→0x5646E0`，後者於 `0x564742` 設 `ESI=0xFE36E0`，`0x564747→0x55ECC0`。draw consumer 在 `0x55ECCA` 檢查 texture 非 null，`0x55ECD0/4` 檢查 `+0x0C!=0`，才作兩次 virtual `+0x24` 繪製。

因此 Hide 的旗標清除能停止這條後續 draw path；本輪沒有觀察實際呈現 frame，不宣稱 GPU 畫面已驗收。Stop 由 `0x55FF70` 取相同 owner 再清 `+0x0C`，不是另一個 UI 狀態。

### Sepia

Start `0x5655C0` 置 phase 1，End `0x565600` 置 phase 4，並將轉換參數寫到 `0xFE36D8`。End 的 closure `0x56A100` 經 `0x56A430` 作單一整數 marshalling；不得因為名稱叫 End 就猜它是無參數的完成 ACK。本輪沒有提出已驗證的時間參數。

`0x560090..0x560158` 是程式；**`0x560158..0x560170` 是六項 jump table 資料**。精確狀態為：

| 進入 phase | 本次更新結果 | 原件支點 |
|---|---|---|
| 1 | 選 effect mode 2，phase 2 | `0x5600AD..0x5600CF` |
| 2 | 選定 effect type 為 2 時寫其 `+0x7C`，phase 3 | `0x5600DA..0x5600F8` |
| 3 | 保持 | table → `0x56014F` |
| 4 | phase 5 | `0x560107` |
| 5 | phase 6 | `0x560116` |
| 6 | 清 mode、dispatch renderer 切換，phase 0 | `0x560123..0x560149` |

`Q` native update `0x561520` 在 active／Q coroutine gate 及 Q actor 更新之後，仍於 `0x56165A/65F` 呼叫此 updater。所以 End 請求之後，在 native frame 仍前進、相關 renderer context 有效且沒有其他寫者覆寫 phase 的前提下，**要再經 3 次呼叫才到 0**；不要求 qco 仍 active，但也不是 EndSepia return 當下完成。Stop 同樣只請求 phase 4。

## 8. 新內容清理契約與 Server 開發需求

外層 supervisor 持有 entry outcome 與 cleanup ledger。失敗後先停止新增內容工作；參照已核 native Stop 的主順序為 camera works → RestoreMap → DeleteAllObject → EndCameraOverride → display flags → G selective sweep → End，內容設計只挑選本 run 確實持有且仍有效的項目。具體 image 取消還須依型別與 owner 另選操作：只有 Tutorial.DestroyFlyingObjects 會先標記其 tracking 的 lifetime；Stop 的 sweep 本身不會做這一步，不能宣告 Tutorial 圖片全部取消。涉及共享 native owner 的動作必須明確知道本 run 仍擁有它；任何步驟錯誤均要保留，不能用「已呼叫 cleanup」覆蓋成「已恢復」。

建議結果模型至少分開 `entry_outcome`、`cleanup_attempted`、`cleanup_errors`、`pending_native_effects`、`original_003f_observed`、`server_authoritative_result`。這些是 **Server／新內容介面待開發欄位**，不是原件封包欄位或已存在 wire schema。本輪不新增 opcode、不虛構合法 key／座標／模型。

| 類別 | 本輪後的具體需求／未完成項 |
|---|---|
| Client 待逆向 | native MEF 首載入／schema／executor；ordinary 場景可控 Lua pump；typed ordinary actor death/group/result observer。此分題的 camera、map、display owner 不足以釋放這三個阻擋。 |
| Server 待開發 | 唯一 run 身分、場景世代、權威結果與取消原因；避免同一 Client 同時跑多個會共用 Q／camera／map snapshot 的演出；分別記錄原件 003F 與內容／清理結果。 |
| 跨功能待整合 | supervisor 與具備本輪 acquisition ledger 的內容介面；外部 Stop／場景切換／斷線的取消仲裁；ordinary entity 與 Q 演出 slot 的明確映射，禁止自動相等。 |
| 待遊玩驗證 | 成功、entry error、cleanup error、外部取消、缺資源、重入、無回應腳本、延後 sepia／image cleanup 的實際畫面與輸入恢復。本輪均未執行。 |

## 9. 停止條件與可重驗性

本分題的目標是閉合 **Q 已知演出副作用的 owner → 操作 → 實際消費 → 釋放順序**，不是重建整個 renderer 或宣告全程式沒有其他 owner。已新增：CameraWorks 綁定及實際 tick、Q-local attachment、具名 snapshot stack、單一 map backup 與不同 MapList root、world render／animation consumer、letterbox actual draw、sepia 狀態機及 End/Stop 分支反例。

仍不能由靜態證據取得「可部署資源已成功」「清理畫面與輸入已完成」「ordinary run 有可靠死亡／群組結果」；釋放條件分別是有效來源資料與合法配置、原生生命週期整合及實際驗收、真正的 ordinary executor／typed observation 證據。這些明確保留在上表，不以 verifier PASS 抹除。

驗證器僅讀原始 BIN 與固定 Git blobs，核 SHA／PE mapping／完整指令邊界／rel32／vtable／string／Q binding immediates／契約邊界；唯一可選輸出是結果 JSON。`PASS` 不等於 native 語義形式證明、Client 執行、Server 實作、T01 FULL-PASS 或 RR ACCEPTED。
