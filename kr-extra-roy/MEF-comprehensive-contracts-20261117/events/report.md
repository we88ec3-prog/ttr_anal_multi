# MEF 可觀察結果：16 個正常查詢的資料來源與普通事件缺邊

研究日期：2026-11-17（Asia/Taipei）。固定分支基線 `extra/roy1 @ 5ef4ab8870ea1c65c6c7497901302d851f5c7a51`；main 基線 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。只讀 KR BIN，沒有執行遊戲、Lua 或 Server，沒有改原件／正式 Task／RR。本文是新增完整技術原稿。

## 1. 本輪回答的範圍

**本輪把正常登記介面的「腳本實際能讀到什麼」整理成封閉的、有來源的查詢表。** 121 個正式名稱的 closure／marshaller 審計另由同輪 ABI 分題處理；在其中 16 個查詢型新數值 producer，本分題逐一讀完 native getter body，核對 receiver、來源欄位、參數作用、空值／停止／重用的歧義。`lb.DoFile` 的另一路新數值回傳屬載入器結果，不是遊戲觀察查詢；`lb.GetObjectCount` 沒有產生可靠新 count，亦不列入這 16 項。

原版可供腳本觀察的內容包含教學控制旗標、指定角色／領隊條件、Q 演出狀態、Q 物件停步、鏡頭工作、Prolog／Book、位置分量及本機時計。**沒有一個已核查詢提供任意普通 world EntityId 的死亡、移除原因、生命期或群組結果。** 這是這組正常綁定的介面契約，不是全程式不存在其他 callback 的宣告。

另對前輪提出的 `CScenarioTalkBox+9C` 新 producer 方向追加定型檢查：核對該 concrete vtable 相對其 base 的完整 91 槽、7 個 override 槽與 class 專用方法，未取得新的獨立選定資料 writer。正向已知 `Lua→open→對話→OnEndTalk` 繼續成立，但尚未因此建立普通場景不經 Q 的首次入口 B。

### 已復用、沒有當成新發現的部分

- 122 個同型 registrar／121 正式名稱、223 個 closure sink caller 的 census，沿用 `MEF-full-surface-native-continuation-20261116`。
- `000E→CScenarioField→CAIControl→54AA60` 的 typed native 資料鏈，沿用 `MEF-transition-actor-event-20261117/WORLD-EVENTS.md`。
- Tutorial 提示點的 `writer→GetControlStatus→原版Lua續行`，沿用 R14；`004C→IsScenarioEnded` 的場景限制、OnYes／OnEndTalk 的已排除首次入口，沿用 world-integration／one-shot。
- Q 停步、相機 Stop／IsEnded、Prolog／Book 與 UI latch 的原生效果，沿用原能力章及 observers／feature-lifecycle。
- CAIControl 的完整動作決策屬既有 T10／T13 研究範圍。`CLM-COMBAT-0035/0036/0037` 與 T10-26/30/31 保留 PARTIAL／衝突界線，不藉此次引用提升品質或重作全套 AI。

新增價值是**完整觀察出口的資料域和歧義對照**、特定 skip writer 與 active gate 的先後關係，以及 concrete talk class 的未查 override／selected writer 範圍收斂。這讓內容工具可以驗證等待條件，而不再由 `Is...` 或 `Get...` 名稱猜事件語意。

## 2. 原件與重核

KR `Tartaros.bin`：12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32/i386，ImageBase `0x400000`。所有 VA→raw 由實際 PE section table 換算。

- [native-evidence.json](native-evidence.json)：39 個完整函式／明列前綴，6,100 bytes、1,818 個指令；4 個資料窗口、4 組限定候選 census、typed vtable 與 selected writers。
- [native-evidence.asm](native-evidence.asm)：相同窗口的逐指令內容。
- [observation-catalog.json](observation-catalog.json)：16 項查詢的機讀契約。
- [source-manifest.json](source-manifest.json)：24 份固定 Git 來源的 commit/path/blob/SHA-256；同輪 ABI 不冒充已發布來源。
- [verification-result.json](verification-result.json)：實際 PASS；只代表所列 bytes／指令邊界／來源一致。

工具為 GNU objdump 與 Python 標準庫。既有 Ghidra bulk 文字只作導航，不生成新的全量反編譯、不執行歷史未知腳本。verifier 只讀原件；它不測遊玩、Server 實作、T01 FULL-PASS 或官方 MEF grammar。

```bash
python -B verify_evidence.py --bin /path/to/Tartaros.bin --repo /path/to/ttr_anal_multi
```

`--repo` 可選；提供時核對固定來源 commit 的全部 24 個 blob。無 `--repo` 仍核 native 與查詢表。輸出 JSON 可另行保存；程式不修改原件或 Git。

## 3. 正常查詢介面的完整資料域

本表「正常」指既有 registrar 及 receiver 綁定未被任意 Rebind／Lua table 替換的條件。沒有把裸指標重綁、越界索引或非預期物件 layout 當成正常內容功能。

| 名稱／native | 真正來源與可觀察值 | 可作的等待／分支 | 必須排除的誤讀 |
|---|---|---|---|
| `lb.GetTime`／`4A0B70` | 跳到 `BD25A0`，PE import 明確為 `WINMM.timeGetTime` | 已有合法 pump 中的本機有限差值 | 自動 timer callback、Server 時鐘或新 resume 來源 |
| `Tutorial.IsSynopsisSkipped`／`4A9320` | `FBA7A0` DWORD | 指定 Synopsis/Tutorial skip 分支 | 任意最近演出取消或成功結果 |
| `Tutorial.IsCutSceneRunning`／`4A97B0` | lazy-init 後讀 `FB73E8`（Q `M+28`） | 既有 Q active 是否仍在 | `0` 保證自然完成或所有 owner 清理 |
| `Tutorial.IsCharacterAvailable`／`4A9F00` | 固定 roster index 2（零起算，第 3 筆）的有效標記 | 該固定教學角色可用性 | 按傳入參數查任意人物、world actor 存活 |
| `Tutorial.GetControlStatus`／`4A9FB0` | current controller `+B4+4*k` | 合法 Tutorial 控制／提示進度 | 任意普通 controller 的事件槽、事件佇列 |
| `Tutorial.GetTutorialState`／`4A9FD0` | current controller `+134` | 已證 Tutorial UI state | world FSM、任務完成或怪物群清 |
| `Tutorial.IsIsiliaFound`／`4AA240` | 固定 world key `F000`，再過相機／幾何／畫面 gate | 指定教學角色符合可見條件 | 任意 EntityId 存在或死亡通知 |
| `Tutorial.CheckLeader`／`4AA4A0` | current controller `v+20` 取得領隊，檢查 actor `+88 WORD==3` | 固定領隊條件 | 回傳領隊 EntityId、任意角色比較 |
| `Tutorial.IsLeaderDialogOpened`／`54E740` | 正常 Tutorial owner `FC0F84+38` 的記錄旗標 | 已證教學 UI 操作分支 | 當幀視窗實際可見性保證 |
| `Tutorial.IsScenarioEnded`／`4AA510` | Tutorial owner `+4` keyed map 的 DWORD | 同一 Tutorial 生命期中的 scenario key | 普通 Mission/Scenario 的 `004C` 死亡／清組通知 |
| `CameraWorks.IsEnded`／`54EA00` | current work 非空則 `v+20`；空直接 1 | 同一已取得鏡頭工作停止／完成條件 | 必然曾載入成功、自然播完或快照已還原 |
| `Q.IsCutSceneRunning`／`489CF0` | 正常 Q receiver `+28` | Q active | 成功／取消原因或呈現全回收 |
| `Q.GetLeaderPosN`／`564610` | current controller 領隊 `v+50` 的分量 0/1/2 | 領隊位置分量 | 物件 handle／EntityId 或存在性 ACK |
| `Q.IsAllObjectsStopped`／`564880` | Q 樹每個 actor `+E2` 的 movement bit `8000` | 已知 Q actor 集合全部停止移動 | 動畫播完、world 死亡、群清或刪除 |
| `Q.IsPrologRunning`／`564C50` | lazy-init 後讀 Prolog `FC1B18` 的 state | 同一 Prolog 生命期 | Q.Dialogue、ScenarioTalk、遊戲任務完成 |
| `Q.IsBookFlying`／`565270` | lazy-init 後讀 Book `FC1BF8+74=FC1C6C` | 同一 Book 序列狀態 | 一般圖片 handle、資源已載入或任務完成 |

所有查詢值均按本輪 ABI 的數值回傳契約使用。Lua 的 `0` 仍為 truthy，因此內容應明確比較預期數值；不以 `if Is...()` 直接推定 boolean。函式名含 `Is` 不改變它的實際 Lua 值型別。

## 4. 四項會直接影響內容工具的細節

### 4.1 IsCharacterAvailable 的參數沒有選擇功能

完整 `4A9F00..4A9F86`：

```text
4A9F54  mov eax,[F94304]
4A9F59  cmp dword [eax+47Ch],0
4A9F60  jne 4A9F66
4A9F62  xor eax,eax
...
4A9F66  add eax,420h
4A9F6D  test eax,eax
4A9F6F  setne cl
...
4A9F83  ret 4
```

整個 body 沒有讀 `[ebp+8]`。`0x420=2*0x210`，因此是固定 roster index 2，`+0x47C=0x420+0x5C` 為該筆標記。先前介面雖有一個數值引數，**它不能用來改查不同角色**。這項數值索引只表示原資料位置，不擅自命名為未查原表的人物。

內容 lint 可直接阻擋「以 `IsCharacterAvailable(entityId)` 等待任意 world entity 建立／死亡」的寫法。Server 若需要角色可用性，仍應提供其權威 roster；不能把這個固定 probe 擴成世界存在查詢。

### 4.2 固定可見性與一般存在查詢不同

`IsIsiliaFound` 在 `4AA27C` 寫入固定 WORD `F000`，以 `FAB138` 查世界樹。missing node 或 null actor 直接返回 0。命中後取得 actor 位置，依相機 mode 決定是否呼 `838800`，再做距離和投影／螢幕判斷。

窗口中的常數由原件數據核對：`C55770` float=150，`C557E8` double=100。選定分支要求距離低於150；投影座標要在距畫面邊緣100的內部。比較與實際 render尺寸取值均保留在完整 body，不把看到畫面提示文字當成這些條件的證據。

所以回0至少可能包含「固定 key 不在 world」「actor 指標為空」「相機 gate 不通過」「太遠」「投影不在限定畫面區」。它沒有傳回失敗原因、可選 EntityId、死亡原因或 generation；**回0不等於該actor已死亡**。本輪不擴充 `838800` 所有其他 caller 或任意 camera subclass 的語義。

### 4.3 GetLeaderPosN 的零有多重含義

`564620..56463C` 取 current controller `v+20` 的領隊，再用 actor `v+50` 填局部 vector。selector 0、1、2 分別讀三個 float；沒有領隊或 selector 不符則到 `564685`，`564688 FLDZ` 返回0。

這個0與合法坐標分量0不能區分。內容必須先建立同一controller／領隊前提並限制selector；不能以三次數值讀取自創一個可靠的 EntityId／lifetime，也不能把0當「尚未收到Server actor」的ACK。

### 4.4 Synopsis skip 的寫入早於 Q.active gate

完整 getter 只有 `mov eax,[FBA7A0]; ret`。原件 `.text/.rdata/.data` 對 `FBA7A0` 的 literal候選只有4處，已定位到三個producer／一個getter：

| 原件位置 | 正常作用 |
|---|---|
| `4A89E6` | `Synopsis_EntryPoint` 的 native entry 前綴清0 |
| `4A8A8A` | `Tutorial_EntryPoint` 的 native entry 前綴清0 |
| `4A9320` | 本 getter 讀值 |
| `562514` | Q.Stop 選定條件設1 |

Q.Stop 的實際順序是：

```text
if first_argument != 0
   and M.quest == 1000
   and M.scene in {15,16,17,18}:
    FBA7A0 = 1
if M.active == 0:
    skip_active_bulk
```

guard 的 `M+38`／`M+3C` 與 `M+28` 是正常 Q manager 的欄位，不移植到別種 receiver。重要的是 `562514` store 在 `56251E` active 比較之前。**即使目前 Q inactive，若仍保留這組 key 且合法 caller 傳入非零參數，這條前綴仍可設 skip flag。** 這是原件控制流推論，沒有執行遊戲證明任何特定UI操作必然觸發。

因此此旗標沒有「最近一次新 run」的內建身分；它不是所有取消的記錄，也不是只由 active 演出成功跳過所產生。Server／內容應保留自己的run與取消分類，不以這一個值提交任務或獎勵。

## 5. CAIControl 的原生 reader 為什麼仍不是腳本觀察出口

前輪已證普通結果row寫到 `CAIControl=FB7A28` 的三槽 target狀態，再由 `54AA60` 依模式／selector選world actor pointer。本輪從原件補核兩個直接consumer的完整body：

| 原件call／完整consumer | 回值實際用途 |
|---|---|
| `549686→54AA60`，`549660..5498B9` | actor位置與方向計算、path／距離候選；最後寫本CAIControl輸入WORD `+72` 與方向byte `+74` |
| `549C94→54AA60`，`549C60..549E07` | 候選動作／可用性配合actor；寫輸入WORD、slot狀態／方向，而非push Lua值 |

這些與 T10 的既有 partial動作分析相符。本輪不重新定義所有參數7／9、tier、技能可用性或普通怪物AI，也不把「有原生consumer」寫成腳本已可呼叫它。

在16個正常query的確定來源表中，沒有項目回傳這個CAIControl target、world ID／lifetime／reason結構或事件佇列。`GetControlStatus` 的 typed來源是 Tutorial current controller進度；`IsAllObjectsStopped` 是Q樹；名稱相近或同offset不能把它們接到CAIControl。

本輪指定 `54AA60` 的 E8/E9 候選仍為上述兩個E8；沒有literal指標候選。這個有限census與16項query契約可以排除這些具體接法，**不排除所有計算式alias、外部模組、未登記C closure或其他native callback**。普通 world typed結果→合法Lua出口仍是Client待逆向；Server可獨立實作權威事件後使用已有有限內容啟動。

## 6. B 首次入口：對話 concrete 類型再縮小一個未查範圍

### 6.1 這次新增的是 typed override／方法檢查

前輪已查 `open` 只由Lua啟動、`OnEndTalk` 為零引數固定callback。本輪不重跑OnYes頁面路由，而從 `CScenarioTalkBox` 的concrete vptr `C3EB44` 出發，與base vtable `C4909C` 比對整個 `0x16C` bytes（91槽）。7個不同槽如下：

| vtable offset | target | body的相關用途 |
|---|---:|---|
| `+1C` | `6BCF60` | deleting destructor |
| `+BC` | `636F20` | 矩形寬度調整後交base geometry helper |
| `+EC` | `6BD5A0` | 已有manual key推進／skip-confirm內部事件 |
| `+104` | `6BD540` | 已建立child文字／style與顯示 |
| `+114` | `6BD4F0` | 取得固定child IDs並存入 `+80/+84/+88/+8C` |
| `+140` | `6BD4C0` | manual event==0x64時next |
| `+15C` | `6BD4C0` | 同一event方法alias |

專用constructor/destructor、row render、next、open/start/hide、UI hide/show、receiver登記與Rebind亦讀完。這些window逐指令核對後，對其**直接 `this+9C` store**只有三筆：

- `6BCED9`：constructor清0。
- `6BD682`：open依雙鍵查原表後寫selected pointer；查無時也寫0。
- `6BD7CD`：hide在callback及隱藏之後清0。

7個override槽沒有新增從普通網路事件建立selected record的專用方法；`start`與`next`仍先要求selected非空。這是一個比「全程式搜尋+9C」更有型別約束的負面結果。

### 6.2 FE3184 間接呼叫也沒有新的候選

對已知slot `FE3184` 的raw literal候選：`6BDB1A`為registrar store的位址operand，`6BE0A0`為 `ScenarioTalkTable.open` marshaller讀取native target。native target `6BD620` 無直接E8/E9 caller，literal指標為 `6BDB1E` 的registrar immediate。正式 closure為 `6BDEB0`（同輪ABI核對）；本包完整收錄的 marshaller `6BE090..6BE191` 正常callee仍為上述open，沒有world event payload producer。

receiver `FE3180` 的 Rebind存在，`6BDE20..6BDE32` 讀已保存VM／轉換參數再寫receiver；它沒有建selected record或第一次載入腳本。不能用任意receiver pointer替換繞過原生可達性問題。

### 6.3 保留的界線

這次不是全程式alias分析：沒有把所有繼承base方法的任意callback、computed alias、外部DLL或可改寫VM全域形式化排除。可以結束的是「concrete override及class專用方法是否多出一個明顯selected producer」這個有界候選題；B整體仍未完成。

下一次要解除B，需有新的實際field/page事件→typed talk owner／另一合法Lua caller的正向證據。重掃同一3個selected stores、FE3184 literal、OnYes或MapList字串不算進展。

## 7. 可直接交給內容／Server開發的要求

以下為相容內容與Server設計要求，標為 **NOT_NATIVE_MEF**；不創造原版新opcode或冒稱官方MEF格式。

1. **內容工具使用白名單式觀察契約。** 每項等待記 `query、typed context、producer、expected numeric value、reset owner、same-run condition、timeout/cancel action`。合法參數域與新回值型別由ABI章共同檢查。
2. **把開始、停止、成功、取消及清理分欄。** `IsEnded==1`、`IsCutSceneRunning==0`、空Q樹的停止、skip latch及Prolog／Book的0都不能單獨代表這些欄位全成立。
3. **普通world事件由Server權威保存。** 至少保存instance、EntityId、lifetime／spawn generation、group、cause及當次流程結果；這些為Server自訂欄位，不塞入未知原生wire欄位。已有Client事件以已證封包與有限內容入口續接。
4. **Tutorial旗標重用必須管理原生reset。** 32格progress與Scenario map各自有原用途／清除時點，不能與ordinary world event相互代用。不要以數字相同認定scenario key、point key和EntityId是同一身分。
5. **持續輪詢先確認pump。** getter存在不會使Lua coroutine自動resume；A有限插播與B不接管首次入口分開驗收。沒有可靠query的效果以已證自然生命期或有來源的次序契約處理，不能創造成功ACK。
6. **後續正常流程驗收**逐一確認固定角色／point、相機owner、End後輸入與呈現結果，並把Server提交結果另驗。此次靜態檢查沒有執行這些驗收。

## 8. 結案與四類缺口

| 類別 | 本輪之後的狀態 |
|---|---|
| **已閉合的有界靜態項目** | 16個正常query來源／空值和歧義表、指定skip guard前綴、talk concrete override與專用方法的selected直接writer範圍、CAIControl兩個reader consumer輸出型態 |
| **Client待逆向** | 普通world typed event到真正Lua入口；B的普通場景首次producer；官方MEF filename/bytes→reader→grammar。未假稱全面完成。 |
| **Server待開發** | 權威world／group結果、run/generation及取消去重、已有內容觸發與任務／獎勵提交。原版Server內部未知不阻塞這些需求規劃。 |
| **跨功能待整合** | 觀察白名單與ABI／資源／合法caller聯合預驗；取得和清理owner的同run契約。 |
| **待遊玩驗證** | 真實Client的內容啟動、正常返回、畫面／聲音／操作恢復，以及Server權威進度一致性。 |

本包的PASS不等於正式RR接受、T01 FULL-PASS、Server已實作、官方MEF已還原或整體可玩。
