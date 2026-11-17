# MEF 全能力續查：正常 End 之後的鏡頭、圖片、音樂、世界呈現與明確回收

研究日期：2026-11-17（Asia/Taipei）。工作分支：`extra/roy1`。本輪讀回遠端 HEAD 為 `0d76b827dfda0deb263e2692281ec304747652f8`；main 仍為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。前輪 `MEF-full-surface-native-continuation-20261116` 尚未發布；本包與前輪一起提供累積、可核對的交付，不把未推送檔案冒稱遠端研究。

**整體目標仍是全功能分析；本次屬階段性交付，並未宣稱所有 MEF 功能完成。** 已完成的有界增量，是將已知公開能力接到「Q 正常結束後是否繼續、如何辨認停止、哪些狀態留存、真正回收作用於誰」；其餘逐項保留在全能力矩陣和下一輪工作表。A1 是有限插播的最小規格，不是已部署／遊玩通過；B 的全程正常戰鬥操控入口仍未閉合。官方 MEF 首次 loader／grammar 未證，本文所有新組合均屬 **NOT_NATIVE_MEF 相容內容設計**。

## 1. 研究終點、復用與本輪結果

使用者要求全面搜尋而不是只追一條可用路。為避免重複 R11 的 API 翻譯與前輪註冊掃描，本次先重跑已知入口集合，再將正式 121 個名稱各自對應到功能、owner、適用情境、可觀察結果、收尾與 Server 責任。完整表是 [capability-lifecycle.tsv](capability-lifecycle.tsv)，可讀分組是 [CAPABILITIES.md](CAPABILITIES.md)，機讀分組是 [feature-families.json](feature-families.json)。

本輪靜態子題的終點不是「新增若干函式」，而是以下問題全部有有界答案：

1. 原始 Q normal End 清的是何種狀態，是否等同各效果 owner 的清理？
2. 鏡頭、音樂、圖片、世界繪製／慢動作／黑邊在 End 後有哪些獨立 consumer？
3. Stop、Detach、透明、inactive、到點、釋放、刪除，哪些不是同一件事？
4. 對已保留的物件，有沒有真正可呼叫的清理，以及其影響範圍和等待條件？
5. 哪些內容可以不依賴第二次 Lua callback 自然結束，哪些一定還需要合法收尾入口？

| 子題 | 本輪裁決 | 證據邊界 |
|---|---|---|
| 正常 End 與 owner 清理 | 清 Q active／原 qco，並走既有回報及設定恢復；不是所有效果 reset | 原始 globals/bindings、正常初始化、normal 而非 review 分支 |
| KeyFrame／附著相機 | 存在不依 Q active 的 native 更新；Stop 可阻止其 apply，Detach 只清 current，快照另行還原 | 同一相機 owner 未被其他功能替換；不承諾任意 XML 成功 |
| 有限飛行圖片 | fade／hold／fadeout → phase0 → alive0 → release／deleting destructor／tree erase | 有效資源、有限計數、合格 manager tick；不承諾固定毫秒 |
| 永久停留圖片 | 第七參數可令 hold=-1；不會靠自然階段結束 | Q 只存最後一個 handle，重複建立不自動回收舊圖 |
| BGM | native worker 獨立於 qco；normal End 不直接停它；真正 Stop 是全共享 pool | 不含所有聲音系統／裝置錯誤，音訊輸出仍須原有前提 |
| 隱藏世界角色、慢動作、黑邊 | 各有獨立 flag 和 consumer；normal End 不替內容配對還原 | 只對列明欄位與消費路徑，不把一個 flag 說成全引擎開關 |
| 保留的 Q actors | StopObject 不是刪除；DeleteAllObject 真正析構／清樹，並等待模型 job | 全 Q 樹作用域；無需 active，但仍要有合法 Lua 呼叫時機 |

這些結論使「短暫啟動後讓 native 自行完成」更接近可實作，但沒有創造普通戰鬥背景 Lua runner、怪物 AI、死亡／清組 getter 或新的檔案傳送 opcode。

## 2. 第一手來源與全面搜尋的實際範圍

KR BIN：12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386，ImageBase `0x400000`。VA 與 raw 依真正 PE section mapping，尤其 `.rdata`／`.data` 不使用 `.text` 的簡式偏移。

Event.stp：11,241,597 bytes，SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。本輪透過固定 data-only parser 重核前輪選定 qbase 資料；沒有執行 Lua、主程式、Server、遊戲 API 或封包。

### 2.1 全面盤點沿用，沒有重算成新發現

前輪相同原件的 registrar／sink census 本次實跑再通過：121 正常名稱、1 個預掃描重名、223 個 C closure sink 的直接呼叫點、11 個 library-table registrar 直接呼叫點。122 筆同型 registrar 均核名稱、native slot、closure 與真正 E8 caller；其他 sink 呼叫已分成 Rebind、prepass、正式 globals、語言支援等類別。這些細節和範圍保留於前輪包，未用「沒有新字串」代替檢查。

本輪將 121 名稱分為 36 個分析功能群組。**36 是整理分類，不是36種獨立玩法；121包含alias、4個stub及1個不可靠計數query。** 不同 owner 或相同函式地址不能僅因名稱相近混為一種能力。

此直接集合不包含所有 computed call、內聯 closure 建構、外部 DLL 或 runtime table 改寫。因此「此集合已覆蓋」不等於「整個程式所有可能 MEF 接口已窮盡」。B 與官方 MEF 的既有精確陰性範圍直接沿用，不重掃 OnYes、舊 MapList aliases 或全部 STP 檔名。

### 2.2 本輪新增證據形式

[native-evidence.json](native-evidence.json) 保存 50 個完整函式或明列的指令區間、原始 hex、SHA、VA、raw、exclusive end，以及24個指令錨點、9個資料區間和14條 direct call。全文可讀組譯在 [native-evidence.asm](native-evidence.asm)。所有50個區間本輪重新從原件解碼，合計8,526 bytes／2,530個指令起點；不是全程式覆蓋率。

- `CURRENT_JOIN`：本次為 End 後持續／收尾問題建立的原件連接，不表示各 API 本身首次被發現。
- `REUSED_*`：先前結果的必要比對／接點，不計作新能力。
- `SYN`：由所見分支推導的分析模型，並非遊戲執行結果。
- `NOT_DEPLOYED / NOT_TESTED`：目前所有新整合內容都保留此狀態，不提升正式 Task／RR／T01。

## 3. 共同前提：normal End 停止腳本，不是 owner 總清理

`normal_and_review_end` 保存完整 `561DB0..5620AA`。`M=FB73C0`；`M+89` 選 review/normal。本文採 normal branch `561F60` 起，且原始 qbase、註冊 target、正式 VM 與 current scene 已正常初始化，沒有另加 hook 或替換全域函式。

```text
561F60  test M+28 active；inactive → tail
561F69  M+28 = 0
561F76  checkpoint presentation owner+14 = 1
...     依 quest/confirmation/seen 執行既有 003F／wait 政策
562022  push "f_removeAllCoroutines"
56202D  call 4AD0A0
56207B  恢復原保存設定
56208B  恢復 GameInfo+68C4
```

前輪已由原 qbase 證明 `f_removeAllCoroutines` 與 `ClearObjects→Q.DeleteAllObject` 是不同函式。此原 End 分支並沒有直接呼叫本輪的圖片取消、全部 Q actors 回收、全 BGM Stop、相機 Stop、世界顯示恢復、慢動作清除或黑邊隱藏。

這是 normal 分支、原 callback 語意與下列 owner consumer 的合成證據，**不是任意經改寫 globals／callee 都絕無其他 side effect 的全稱定理**。review 分支另有下一幕和音樂處理，不應套用本節的 normal 音樂裁決。外部轉場、renderer teardown、其他功能取代 owner，也會改變後續行為。

`active_stop` 的 bulk cleanup 仍受 Q active gate 控制，故「先 End，再 Stop 當 reset」不能補救所有保留效果。若打算讓效果跨 End 持續，必須在 End 前已有明確的自然終點或下一個合法收尾入口；已被移除的 qco 不會替內容在未來自動執行 `wait; cleanup`。

## 4. 鏡頭：可繼續，但停止、解除工作、還原是三個不同動作

### 4.1 同一 owner 與不依 Q active 的更新

R11 已有 binding、XML、插值與 snapshot 的完整有界分析。本輪重接的關鍵是 `491CA7..491CD8`：在 Client `+BFCC` 合格條件下，先處理 controller、CameraEffect，再取得 `FB7620` current work，非NULL則於 **491CD6 呼 v+14**。這發生在 field／Q 更新之前；不是 qco resume 產生的時鐘。

KeyFrame vtable `C0FD20` 的 +4／+8／+C／+14／+20 分別指向 `54E080` apply、`54E230` Play、`54E260` Stop、`54E270` Tick、`54E310` IsEnded。`54E970` Load 將 current 指到既有 KeyFrame。前輪已證 XML／資源有效性，本次不猜檔名、easing enum 或任意座標。

### 4.2 一個刻意核掉的錯誤推論

Tick 最後會呼 apply，**不代表 Stop 後仍不停寫相機**。apply 的完整 body 在 **54E0A9** 先檢查 `[work+40]` playing；為0即到54E218返回。`54E260` 正是把這個欄位清0。因此在這個確定的 KeyFrame 類型下，Stop 會阻止選定 apply 的寫入。不能只看 tick 的尾呼就漏掉真正 consumer 的 gate。

相反地，normal Q End 沒有把這個 playing 清0；current仍相同、native tick仍合格時，它可在 Q inactive 後繼續按原 framepos 推進與套用相機。到尾或停止後，沒有從這些函式得到自動 snapshot pop 的契約。

### 4.3 三種收尾與觀察的精確差異

| 操作／狀態 | 原件作用 | 不代表的事 |
|---|---|---|
| `CameraWorks.Stop()` | current非NULL則呼v+C；KeyFrame清playing，Attach型設stop flag | 沒有還原開始前的相機快照 |
| `Q.DetachCamera()` | **563954 寫 FB7620=0** | 沒有Stop舊work，也沒有pop快照 |
| `EndCameraOverride`／`Tutorial.PopCamera(label)` | 沿既有共享snapshot restore/erase路徑 | 不是可盲目重試的idempotent reset；label不合可能繼續耗掉別人的frame |
| `CameraWorks.IsEnded()` | null直接1；KeyFrame停止或進度超尾也1 | 不保證曾成功載入、不保證自然播完、不保證已回到玩家視角 |

Attach camera 的 current 為 `FB766C`，Q slot存於FB7670。具體 vtable `C0FD48` 之 +4=54E340、+C=54E570、+10=54E580，Stop設定+38，apply/tick都遵守該gate。它查的是 Q物件與模型 `CAMERA_DUMMY01`，不是任意world EntityId。

**相容內容要求（設計）**：若本內容確實取得了目前工作與自己的snapshot，收尾先停止自己的work、再按政策解除current、最後配對還原snapshot；若owner已被別的內容替換，不得盲停／pop。沒有原生Lua owner token可憑空讀回；排他與已知baseline需由整合層提供。這不是新官方鏡頭 API。

## 5. 世界繪製、慢動作、黑邊：三個不能靠 End 自動復原的狀態

### 5.1 世界繪製 gate 只對選定路徑有效

`world_owner` 的 `40F0B4` 返回 `FAB130`。draw caller **492B19→40F060，492B1E ESI=EAX，492B20→4E0540**，讓設定者與消費者的同一 owner 成立。

- `Q.DisableObjRender` 在 **5647F7** 設 `FAB1D8=1`，即 world+A8。
- `Q.EnableObjRender` 在 **564864** 清同欄位。
- draw **4E0551** 檢查+A8，非零跳過 current controller v+34 及 world tree `4E1470`。

draw 函式前面仍有另一個owner虛呼叫，不把此flag稱為「整張畫面全部不可見」。世界simulation、Server判定也沒有因這個gate自動停止。正常 End 未清此flag；若內容自己隱藏世界，必須明定何時由持有者恢復。不能把0x2輸入mask解除當成角色可見性的證明。

### 5.2 慢動作還有另一個 countdown

`565697`／`565704` 分別設／清 `FAB1E0`，即 world+B0。世界 animation caller **492599..4925AA** 明確把 `FAB130` 與 delta傳給 `4E0200`，receiver不是猜測。

`4E028E..4E02D6` 的條件為：

```text
if world.countdown(+AC) > 0 or world.slowFlag(+B0) != 0:
    selectedActorDelta = inputDelta * 0.20000000298023224
    countdown = max(0, countdown - inputDelta)
else:
    selectedActorDelta = inputDelta
```

倍率來自原件QWORD `C55890`；是選定actor animation工作的delta，不是Server時計、所有physics或所有UI的0.2倍。工作物件vtable `C0CF2C` 首槽 `4E0520` 最後以該delta呼actor v+24。

**清 `EndSlowMotion` 只清+B0；若+AC仍正，當次依然縮放。** 不把「一次clear呼叫返回」當成所有角色立即正常速度。normal End不替它清+B0；active Stop有自己的clear，但不是inactive總reset。

### 5.3 黑邊有自己的持有旗標

Show／Hide在 `FE36E0+C=FE36EC` 設1／0。`55ECC0` draw只要求texture存在與+C非0；`564747→55ECC0` 與 `492EEE→5646E0` 接到main render，不看Q active。

因此黑邊可以在End之後保留。內容若要求回到無黑邊的戰鬥畫面，須明確Hide；即使world顯示、Fade透明和輸入mask都正常，也不會替代這項後置條件。

上述三類共享欄位沒有本次已證的通用「取得原值＋own token＋還原」Lua接口。設計不得先盲改再假設把它清0就一定恢復正確baseline；最小功能應在已有排他和正常baseline時使用，或根本不碰這些狀態。

## 6. 飛行圖片：從啟動到真正 release／delete／erase

### 6.1 正確參數、型別與識別碼

沿用原binding `Q.FlyingObject` 的精確7參數：path、X%、Y%、fade-in count、hold count、fade-out count、numeric holdForever。`564987` 檢查第7個整數，非0把hold改成 **-1**。它建立 `CFlyingImage`，vptr `C10748`，放進共用 `FB7358` 的樹；取得的是內部DWORD handle，不是world ID，也沒有向Lua建立可靠新handle返回值。

**564A44只把最新handle寫到Q的M+40**。再次建立圖片沒有在此對舊M+40自動呼取消。因此，重複建立hold=-1圖片，再只呼一次 `Q.DelFlyingObject`，不能宣稱所有舊圖片都已回收。

### 6.2 更新與繪製不依賴 Q active

main同一合格更新中，`491ED7→561520` Q tick之後，**491F27→422ED0**取同一FB7358，**491F2D→5537F0**處理圖片。render另由 **492EF5→422ED0、492EFA→5539A0**。這條native來源在normal End移除qco後仍可使用，不需要被移除的Lua工作再次resume。

manager還有group排隊／delay規則，draw也有owner+5C及group gate。結論是「在原有native gate持續滿足時可推進與繪製」，不是每個畫面frame必到，也不是計數可直接換算毫秒。

### 6.3 五階段與兩個不同的完成時點

原件 `553B60..553C50` 的switch資料在 **553C50..553C64**，與code分開保存。

| phase | update作用 | 重要界線 |
|---:|---|---|
| 1 | delay+24正值則遞減並返回；到期改phase2並fall-through | group排隊仍可延後；不是固定wall-clock |
| 2 | 遞減fade-in remaining+28，算alpha；剩餘非正時alpha255、phase3 | 不自動刪除 |
| 3 | hold+30正值遞減；恰0改phase4；負非零返回不變 | **hold=-1會停留** |
| 4 | 遞減fade-out remaining+2C，算alpha；到尾alpha0、phase0 | **此時alive仍可能為1** |
| 0 | `553B79` 把+14 alive設0 | 後續manager才作實體回收 |

manager在 **55387C** 呼v+14 Tick，**553885** 呼v+24 `80F010` 讀alive。為0才依序在 **553892** 呼v+8 release `553DE0`、**55389C** 呼deleting destructor `553E40(1)`、**5538A7** 呼tree erase。

release把texture+44經資源虛方法釋放並清pointer；deleting destructor處理字串heap及物件本身。因而這條鏈不是只看「alpha=0」就猜記憶體已回收，而是有實際release／delete／erase consumer。

### 6.4 取消與正常結束

`Q.DelFlyingObject` 沒有Q active gate，但只能在合法Lua呼叫時機執行；它用M+40找點，**564ADD寫alive0**，**564AE4把handle設-1**。這不是同步完整destructor，實體仍要等合格manager tick。若current handle已被新圖覆蓋，舊圖不在本次取消範圍。

因此有限圖片（合法texture、有限hold、正常計數、owner不被替換）可作為「A短暫啟動後由native自行回收」的候選；它比永久停留圖更少依賴下一次Lua入口。仍未配置真實texture／hash，沒有新增可部署seq。永久停留模式則必須先有可靠的持有及取消入口，不能靠End自動補上。

## 7. 背景音樂：持續播放不是資源洩漏，但清理範圍很大

R11已核音樂載入、16個stream、fade、loop、SoundFile／SoundChannel等。本輪僅把normal End與實際worker／Stop的生命週期接起來，不重做音訊codec或把已知播放能力當新發現。

`6D9067..6D907B` 建立functor：vptr `C40FEC`，receiver+4=`FC0FC8`，callback+8=`6D9870`，交 `6D8D20` 建native thread。vtable+8的`4FACD0`取+4作receiver，尾跳+8 callback。worker `6D9870..6D9970`在lock中處理雙slot及fade，放鎖後Sleep(33)，不以qco／Q.active作其處理gate。

正常 End 不直接Stop這個player；所選same-context原owner仍可依原工作緒繼續。這可用於正常BGM，但必須與「有限音效播完」、「某段語音完成」、「Script成功」分開。

`Q.StopMusic` **56455C→6D9CC0** 的真實作用：遍歷 `FC16A0..FC16E0` 共16個stream pointer，對非NULL呼v+2C；清fade list、primary/secondary名稱、pointer與pending。具體 `C51BF4+2C=80EB30` 先等待其作業旗標清除，再停輸出、釋放stream。不是只釋放本內容剛播放的那一軌，也沒有保證固定時間返回。

R11的 `StopMusicWithFadeOut` 則只降gain，不能當release；同名Play可不重新開始。內容應選「保留已啟動BGM」或「明確切回指定合法音軌／Stop政策」，而不是結束時無差別Stop所有pool。沒有Lua單次播放ID，不能憑空設計可靠的per-track owner控制。

## 8. Q演出物件：停步、查詢與回收

前輪已證Q actor tick、animation和draw在End後仍可能運行。本輪補真正收尾：

- `Q.StopObject(slot)` (`5637E0..56382F`) 查Q樹，切action1/rate1後在 **563821清actor+E2的0x8000**。它不析構、不移除slot，不是world怪物停止同步指令。
- `Q.IsAllObjectsStopped`遍歷Q樹看同一movement bit；空樹亦回1。不能用它證明模型釋放或Server群組死亡。
- `Q.DeleteAllObject` (`563A70..563C37`) 不要求M+28 active。對全樹actor呼v+14及deleting destructor；**563B1D→823850清樹**。之後清其他Q資料，提交native model job並等待event。這是全Q-owner範圍的真實清理，不是單slot API，也不保證非阻塞。

`Q.DeleteObject` 正常target仍是stub。後續相容內容若要回收先前保留角色，必須已知全部Q樹皆為自身持有，且有真正可達的新Lua入口。下一次Q Start本身也可能重整模型依賴，所以「另外啟動一個清理scene一定無其他影響」仍是待整合，不因DeleteAll沒有active gate就直接宣稱完成。

## 9. 可用組合與不應使用的捷徑

| 組合 | 目前有界能力 | 必須先補齊的契約 |
|---|---|---|
| A1一次切point | 已提交最小規格，無需留後續native工作 | 實際point/發布品與實機；不修改A1既有鍵政策 |
| 短暫啟動有限圖片，End後自行淡出回收 | 本輪完整native phase與release鏈成立 | 合法texture／hash、確定有限模式、same-owner條件及畫面驗收 |
| 短暫啟動FadeIn，End後自然透明 | 前輪完整tick/draw／alpha歸零成立 | graphics已初始化、正數count、共享Fade排他；不能當完成ACK |
| 角色走位後保留在場上 | 前輪native移動＋本輪Stop/全量回收區別 | 真實slot/model/action/座標、owner與真正後續回收入口 |
| 跨End播放鏡頭或BGM | native工作可持續 | 相機快照／共享音軌恢復政策；播放狀態與成功分開 |
| End後才想等Lua自動清理 | 不成立於已移除qco的原流程 | 需要另一個已證合法entry；不能把native tick當Lua callback |
| End→inactive Stop當萬用reset | 已有反證 | 必要清理在End前做，或走真正有界的公共cleanup |
| 任意clear共享flag／pop共享stack | 不可作一般安全恢復 | 確認baseline、ownership及配對紀錄，避免破壞其他系統 |

有限插播、原native持續、全程不中斷B三者始終分開。上列組合沒有新增普通怪的攻擊AI、命中、HP、清組、掉落或交易權威；這些業務規則列Server開發，未知的Client事件／身份橋則保持Client待逆向。

## 10. 全功能目標的剩餘分工與下一條證據

全功能矩陣不使用一個總百分比掩蓋層級：同一列可以是native效果已證、內容規格未綁定、Server未實作、遊玩未驗收。

**Client待逆向**：官方MEF filename／bytes到首次reader/parser的正向鏈；普通戰鬥B的非Q首次入口；普通world EntityId／死亡／群組結果的可靠Lua觀察；超出本次sink模板的computed/inline/module註冊只在有具體來源時擴充。B的下一候選仍是已定型CScenarioTalkBox+9C的其他writer或FE3184/6BD620的合法間接caller；既有OnYes等陰性不重做。

**跨功能待整合**：本輪36功能群組中多數已有原生子鏈，但每個發布品仍需真實資源、ABI、owner、自然終點或合法cleanup入口。優先有限圖片／FadeIn，再相機／角色／音訊等共享持有能力；不要先混成一段全部效果。

**Server待開發**：通關、開放、服務、資產、持久化、快照／差量、run排他、等待解除、內容版本／資源選路。這些不是等待原版Server內部實作才能做的Client分析阻塞；詳 [SERVER-HANDOFF.md](SERVER-HANDOFF.md)。

**待遊玩驗證**：選定內容正常路徑的真實frame／畫面／聲音／操作恢復和Server一致性。本輪保持不執行遊戲的限制，不能以此未測抹掉已可證的靜態效果，也不能用合成測試假稱遊玩通過。

分析順序、交付條件與具體下一證據見 [NEXT-ANALYSIS.md](NEXT-ANALYSIS.md)。對尚未查盡的其他靜態分支標「未完成／未查」，不把它們一律寫成不可推進的證據阻塞。

## 11. 實際驗證、可重跑範圍與發布狀態

[verify_evidence.py](verify_evidence.py) 只讀原BIN與研究資料，重核SHA、PE mapping、50組窗口、逐指令端點、24錨點、9組資料、14條direct calls、16個明確virtual slots，以及前輪有界全registrar盤點與選定qbase。36功能群組和121名稱保證無漏列／重列，且保留binding四元組。

[models.py](models.py) 和 [test_models.py](test_models.py) 的32個案例是 **SYN**：正常值的圖片階段、鏡頭stop/detach/restore區別、sticky flags、慢動作OR條件、最後handle、Stop-vs-delete與保守plan檢查。不是原Client模擬器，不覆蓋所有浮點、配置失敗、搶占、driver或UI條件；不能獨立證明原生行為。

本輪實際輸出是 [verification-result.json](verification-result.json)。PASS只證所列來源與機械／模型一致性，不是全程式語義形式化證明、T01 FULL-PASS、RR ACCEPTED或Server實作完成。

本環境GitHub連線只提供讀取工具，找不到create/update操作；CLI沒有可用推送通路。本輪未建立新commit／更新遠端ref。累積研究patch包含前輪尚未發布原稿與本輪全部交付檔，套用與雜湊驗證另存於發布包。不得把本機檔案或計算出的Git blob hash當成已存在的遠端提交。
