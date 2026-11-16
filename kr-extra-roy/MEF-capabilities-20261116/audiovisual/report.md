# R11：`.mef` 的鏡頭、音樂音效、淡入淡出與轉場能力

## 1. 本輪結論與證據範圍

**這版 Client 已具備可供事件腳本組合的完整視聽演出鏈。** 在既有 KR Lua 執行器與合法事件 caller 中，相容的事件腳本可以載入並播放關鍵幀鏡頭、以角色位置作相對偏移、即時改變鏡頭位置與方向／距離、產生相機位置振動、播放背景音樂與一般／語音音效、改變畫面覆蓋色與透明度，以及製作擷取畫面的多層放大淡出轉場。這些結論均已沿公開 binding、參數轉換、具體 native owner、更新／繪製或音訊 consumer 交叉核對；不是只將函式名稱翻成能力。[B01–B28、C01–C35、M00–M29、S01–S18、F01–F16、T01–T11]

原版 `.mef` 樣本及其原生首次載入／格式仍沿用總報告的待逆向界線；本文證明的是已存在的腳本演出能力，不將檔案副檔名視為可達 caller。

本輪也確認了幾個直接影響內容開發的語意：

- `Q.MoveCamera` 與 `Q.SetCameraPoint` 是同一 native setter；它們立即改位置，沒有「移動幾秒」的參數。
- `Q.RotCamera` 的第三個參數進入鏡頭局部 Z 距離；前兩個才是角度，直接採弧度進入旋轉計算。
- KeyFrame 真正增加播放幀的邊是主更新 `491CD6 → v+14 → 54E270`；R10 的另一條 `492426 → v+10` 對 KeyFrame 為空操作，兩條不可混用。
- 原版 `PlayCamera` 會等待 `CameraWorks.IsEnded()`；音樂、音效、淡入淡出與 `Transition` 的常用 qbase helper 通常只 `yield` 一次，沒有等待實際結束。
- `StopMusicWithFadeOut` 把音量係數降到零；這條實作沒有隨之呼叫 stream 的 Stop／釋放。真正停止與釋放串流的公開入口為 `StopMusic`。
- `Fade.End(0)` 只停 alpha 更新，保留當時遮罩；繪製端不檢查 active。要取消覆蓋須使用非零整數 clear 參數，或讓淡入完成。
- `SetFinalMusic` 寫的是後續 `RestoreMap` 使用的字串；一般分支實際是追加，而非每次覆寫，更不是當場播放。[C08–C35、M03、M10、M14、M18、M21、M24–M29、F04–F06；qbase P11、P14–P16、P21–P23、P37、P47–P52]

### 1.1 原件與固定來源

| 來源 | 固定身分／用途 |
|---|---|
| `02-Tartaros.bin` | 12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32/i386，image base `0x400000` |
| `06-Event.stp` | 11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `Event/qbase.lua` 選定成員 | block id 7378，原 carrier offset 10618896，11836 bytes；解碼 SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`；全結構 76 prototypes／906 words，本包只交付 19 個相關 prototype |
| 固定 main | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；bulk `.c` 僅導航，實際語意依原件機器碼 |
| 固定 R10 父稿 | `af97bbd29c892e031eef7a3bc3a98cb79f1be729`；復用 Q/Tutorial binding inventory、既有 cleanup 與純位元組 Lua parser |

`source-manifest.json` 保存每個 Git path、commit、blob、byte length、SHA-256；`native-windows.json` 保存每段 VA／raw offset／hex／SHA-256 與逐指令 ASM，`native-windows.asm` 為方便人工查閱的同內容。本文方括號中的代號可直接定位 `native-windows.json.records[].id`；`Bxx` 指 `bindings.json` 中的對應 registrar／closure／name／initializer call 四種原件證據。Lua 證據以 `lua-evidence.json` 中的 P 編號定位。此輪沒有執行原 Client、Lua chunk 或 Server，沒有修改原始資源。

## 2. 可直接用於內容設計的能力表

下表的「等待」是**原版 helper 已存在的行為**，不是對所有入口自動成立的保證。資源名、位置、角度與其他數值仍須來自已存在且相容的內容；本報告不猜造檔名或任意值域。

| 能力 | 原版入口與呼叫輸入 | 實際效果與生命期 | 原版等待方式 |
|---|---|---|---|
| 播放資源定義的鏡頭 | `CameraWorks.Load(path)`；`LoadRel(path,x,y,z)`；`Play()` | 選用共用 KeyFrame；載入 XML 關鍵幀，必要時替每點加偏移；`Play` 重設幀與 playing | `PlayCamera(name,flag,x,y,z)` 組路徑後輪詢 IsEnded；`PlayCameraNoWait` 不等 |
| 直接播放絕對／現相機相對鏡頭 | `Q.PlayCameraWorks(path,relativeInt)` | 零用絕對載入；非零以**當時相機位置**為偏移，隨即 Play | native 本體不等待；可用既有 `WaitForCamera` |
| 跳轉鏡頭進度 | `Q.SkipCamera(k)` | 當前進度加 `trunc(float(k)/R)`，KeyFrame setter 有尾端上界；`R` 為 native rate getter | qbase `SkipCamera(k)` 只 yield |
| 即時改鏡頭位置 | `Q.SetCameraPoint(x,y,z)`／`Q.MoveCamera(x,y,z)` | 同 target `562E10`，覆寫當前相機三位置欄位；後續鏡頭 owner 更新仍可再覆寫 | qbase `MoveCamera` 直接呼叫，不等待 |
| 改方向與距離 | `Q.RotCamera(angleZ,angleX,distance)` | 前兩數為弧度旋轉，第三數是局部鏡頭 Z 距離 | qbase `RotCamera` 直接呼叫，不等待 |
| 相機位置振動 | `Q.CameraEffect(limit,a,divisor)` | 登記 type10；正弦偏移加在相機第三位置分量；逐更新完成，不回 handle | qbase `CameraEffect(waitFlag,limit,a,divisor)` 可估算 wait，或 yield |
| 有標籤的相機保存／恢復 | `Tutorial.PushCamera(label)`／`PopCamera(label)` | 保存共用相機 0x48-byte 記錄；pop 會恢復並刪除記錄後再比對 label，標籤不合會繼續回退 | 同步 native 操作；不是動畫完成等待 |
| 套用預設鏡頭 | `Tutorial.ApplyDefaultCamera()` | 套設定中的 angleX、distance，存在 leader 時使用其 heading 推算 angleZ；不是 Pop 的同義詞 | 無等待 |
| 背景音樂 | `Q.PlayMusic(path,loopInt)`／`Tutorial.PlayMusic(path,loopInt)` | 共用 primary BGM slot；音樂工作緒選用原生 stream driver；同名請求被略過 | qbase `PlayMusic(name)` 加 `Sound/` 並使用原版 `TRUE`，之後只 yield |
| 停音樂／音樂淡出 | `Q.StopMusic()`／`Q.StopMusicWithFadeOut(msInt)` | 前者停 pool 內 16 個 stream；後者按轉換後的時間參數降低兩音軌 gain | helper 只 yield；淡出無完成 callback |
| 設後續恢復音樂 | `Q.SetFinalMusic(name)` | 修改 Q 的 final-music 字串；RestoreMap 組 `Sound/` 前綴使用；見 §5.5 的追加及 fallback 規則 | 無等待；不立即發聲 |
| 一般音效／對話語音 | `Q.PlaySound(path)`／`Q.PlayTalkSound(path)` | 查快取 SoundFile，排原生載入／播放訊息；Talk 另把資源 group 指向 Voice 或既有 fallback | helper 只 yield；不回播放 ID 或完成狀態 |
| 淡出／淡入畫面 | `Q.FadeOut(count)`／`Q.FadeIn(count)`；同義底層 `Fade.Start(dir,count)` | 改共用 alpha overlay；count 是合格 native 更新次數的分母。dir0：0→255；非零：255→0 | qbase Q helper 只 yield；Phase 使用既有 `wait(30)`，不是完成 getter |
| 保留／清除遮罩 | `Fade.End(clearInt)` | 停 alpha tick；非零額外清 alpha。零可保留畫面遮罩 | 同步狀態寫入 |
| 改遮罩色 | `Q.FadeColor(packedColor)` | 填寫共用 32×32 texture 的 packed color；alpha 仍由 Fade 控制 | helper 只 yield |
| 多層畫面轉場 | `Q.Transition(layers,fadeRate)` | 擷取畫面 texture，中心放大若干層並降低 alpha；完成後釋放 capture | qbase `Transition()` 固定用已見 `(2,120)`，只 yield |

證據：鏡頭 [C01–C35、U01–U09]；音訊 [M00–M29、S01–S18]；遮罩／轉場 [F01–F16、T01–T11]；原版包裝 [P11、P14–P16、P21–P23、P37、P44–P45、P47–P52、P64、P67、P74]。

## 3. 公開介面、型別與共用 owner

### 3.1 Binding 與 ABI 是分開核對的

本包保存 28 個正向視聽入口：16 個 Q、5 個 CameraWorks、5 個 Tutorial、2 個 Fade。每筆都有 `root / namespace_initializer / registrar / callsite / native / slot / closure / name_va`，並直接驗證 registrar 中的 `C7 05 <slot> <native>`、名字 push、closure push 與 root 的 rel32 call。[B01–B28、B_Q_namespace、B_Q_root、B_TUT_root、C01–C02、U09、F01–F02]

| namespace | 共用 owner／receiver | 開發上的含意 |
|---|---|---|
| Q | `M=FB73C0`；binding receiver slot `FE2778` | 演出狀態、地圖與 final-music 等是 Q 管理器共用欄位 |
| CameraWorks | `FE1E28=&FB7620`；`FB7620` 為 current pointer；KeyFrame `FB7624` | Load／LoadRel 會改 current owner；不是每次呼叫建立互不影響的獨立 player |
| Tutorial camera | native 直接使用 `[FB76E8]`／`[FB7620]` | 與 Q／CameraWorks 共用正在使用的相機及快照堆疊 |
| Fade | `FE1F30=&FE2744`，正式 VM wrapper `FDF3C8` | Fade.Start／End 與 Q.FadeIn／Out／Color 操作同一遮罩 |
| 音樂 | `PM=FC0FC8`，primary `PM+34=FC0FFC`、secondary `PM+6C=FC1034` | Q 與 Tutorial 的背景音樂請求會替換同一 primary slot；StopMusic 影響同一 pool |
| 音效 | `S=FAB028`，SoundFile／SoundChannel 原生物件 | Q 不另外持有可讓腳本逐音效回收的 handle |

整數 marshaller 接受 Lua number，或可被原數字轉換器讀取的 string，再以 x87 `FISTP` 轉 signed 32-bit；其他 tag 走零。`FISTP` 本身受當時 FPU rounding mode 影響，不能把這些 ABI 一概寫成「必定截斷小數」。內容應提供整數輸入，不依賴小數邊界。三座標／角度 marshaller 則讀 Lua double，再轉 native float。字串入口接受原 string，或 native `6FB5D0` 成功轉換的值；轉換失敗可得到 null，而後續若直接 strlen 並沒有一致的安全 fallback，因此必須提供有效字串。[A_I1、A_I2、A_I3、A_SI、A_S1、A_F3、A_COLOR、A_CW_S、A_CW_SFFF、A_TUT_SI、A_TUT_S、A_FADE_I1、A_FADE_I2]

**不可把 Lua boolean 當這些整數 flag 的一般替代品。** 原版的 `TRUE` 等 global 及原 helper 的比較是其內容契約的一部分；native numeric marshaller 對 tag boolean 並不按「非零為真」轉換。普通副作用 closure 雖然最末以 C return1 返回，卻沒有壓入新的 success／completion ACK；原 qbase 對這些呼叫也以不取結果方式執行。`CameraWorks.IsEnded` 是本範圍中特別核實會壓入**數字**結果的 getter。[各 Bxx_closure、A_*；C07、B21_closure；P11、P21–P23、P37、P44–P52]

### 3.2 五個 CameraWorks 與兩個 Fade 的精確 tuple

| namespace.member | root／namespace initializer | registrar | native slot → target | Lua closure | name VA |
|---|---|---|---|---|---|
| CameraWorks.Load | 54E750／54EA20 | 54EB00 | FE1E2C → 54E970 | 54EE40 | D6A5E0 |
| CameraWorks.LoadRel | 同上 | 54EBA0 | FE1E30 → 54E990 | 54EEA0 | D6A5E8 |
| CameraWorks.Play | 同上 | 54EC40 | FE1E34 → 54E9E0 | 54EF00 | D6A5F0 |
| CameraWorks.Stop | 同上 | 54ECE0 | FE1E38 → 54E9F0 | 54EF60 | D6A5F8 |
| CameraWorks.IsEnded | 同上 | 54ED80 | FE1E3C → 54EA00 | 54EFC0 | D6A600 |
| Fade.Start | 55E680／55E850 | 55E930 | FE1F34 → 55E740 | 55EA90 | D6A5C4 |
| Fade.End | 同上 | 55E9D0 | FE1F38 → 55E770 | 55EAF0 | D6A5CC |

以上是一般成員，不把 `Rebind` 算入玩法能力。完整機讀資料在 `bindings.json`；原件字串、closure、registrar bytes 與各初始化 call 均可由 verifier 重新對照。

## 4. 鏡頭鏈：如何開始、如何動、何時等完

### 4.1 載入與相對位置有兩種不同來源

`CameraWorks.Load(path)` 將 current pointer 設為 KeyFrame，呼叫 `796EE0` 載入。`LoadRel(path,x,y,z)` 做同樣載入，再由 `7974D0` 將提供的三分量向量逐一加到關鍵幀位置。loader 使用 `cameraworks`／`keyframe` 元素，讀 `framepos`、位置、pivot 以及 `pitch/yaw/roll/dist/easing/easingtype` 欄位；這能支撐資源定義的鏡頭位置、方向、距離及插值。但本包沒有把未驗證的 easing 數值全表、任意 XML 或不存在的資源名當成合法內容。[C03–C04、C12–C13、C21、STR*]

原版 qbase `PlayCameraNoWait(name,flag,x,y,z)` 有五個參數。它先複製給定 offset；若 numeric flag 不等於 0，就加 `Q.GetLeaderPosN(0/1/2)`，然後組 `Event/CameraWorks/` 與 name，呼叫 `CameraWorks.LoadRel(path,offsets)`，再 `CameraWorks.Play()`。它**一律**使用 LoadRel，沒有改呼叫 Q.PlayCameraWorks。[P14]

`Q.PlayCameraWorks(path,relativeInt)` 的相對分支則從當時 `[FB76E8]+C/+10/+14` 取得相機位置。這和上述 helper 的 leader-relative 計算不是同一個座標來源。兩種方式均有正向入口；使用者需要按內容目的選擇。[C08、P14]

### 4.2 KeyFrame 播放、實際 tick 與可觀察結束

KeyFrame vtable `C0FD20` 的實際類型由 RTTI `CCameraWorks_KeyFrame@CameraWorks` 固定。其相關 slots 為：+8 Play→54E230、+C Stop→54E260、+10→476430 空操作、+14 Tick→54E270、+18 GetFrame→54E2C0、+1C SetFrame→54E2D0、+20 IsEnded→54E310。[V_KEYFRAME、C14–C20、C35]

Play 只有在 vector 非空時才設定 playing=1、frame=0、segment=0；空 vector 直接清 playing。主更新在 `CClient+BFCC==0` 的路徑上先處理 CameraEffect，再取 current CameraWorks，非 null 才 call `v+14`。KeyFrame tick 依最後一個 key 的 framepos 判斷是否仍可推進；可推進則先插值，再將 current frame 加 1，最後呼叫 virtual apply。apply 把位置、pivot 與距離寫到當前相機，主 visual update 再於 `4924A8→797EC0` 將相機欄位套到實際 transform。[C14、C16–C17、C21–C25]

這裡的進度是**合格 native update 的幀計數**，不是傳入毫秒 delta。R10 核過的 `492426→v+10(delta)` 仍存在，AttachSceneObj 可用它；KeyFrame 的該 slot 是 ret4，不能用它解釋 KeyFrame 自動播放。本輪新增 +14 實際進度邊，才完成這條正向鏡頭鏈。[C22、C34–C35；固定父稿 presentation/report.md]

`CameraWorks.IsEnded()` current 為 null 時回 native1；KeyFrame 在 playing 清零、或 frame 大於尾端時回1，否則0，closure 推入 Lua number。qbase `WaitForCamera` 先 yield，再於數字結果等於0時呼叫 `wait(100)` 並回到查詢；非0就返回。因此可寫出根據 native 播放狀態等待的鏡頭流程，而不用自行猜片長。[C07、C20、B21_closure、P11、P15]

兩個邊界須保留。第一，空／失敗載入後 Play 可以直接呈現 ended；IsEnded 是播放狀態，不是資源成功 ACK。第二，tick 的「插值→frame++→apply」順序，而 apply 又檢查增加後的 frame 是否仍不大於最後 framepos，因此不能額外承諾最後 key pose 一定在 ended 前被套用。這不是缺少播放能力，而是內容尾幀設計與驗收要依原實作確認的邊界。[C12、C14、C16–C17、C20]

`Q.SkipCamera(k)` 取 `R=[FBA7CC]+1360`，以 float 做 `k/R`，由 `CVTTSS2SI` 截斷後加當前 native frame，再 call current `v+1C`。KeyFrame setter 將超過尾端的值夾回最後 framepos，沒有同時看見負值下界夾取；因此不把 k 宣稱為毫秒或任意可安全負跳的時間軸。qbase 只在此之後 yield。[C09、C18–C19、M28、P16]

### 4.3 即時鏡頭 setter 與位置振動

`SetCameraPoint`、`MoveCamera` 共用 `562E10`：arg1/2/3→camera+C/+10/+14，並清 camera+CC。`RotCamera` 寫 arg1→+20、arg2→+18、arg3→+24。實際 `797EC0` 將 +24 送到局部平移 `(0,0,distance)`，將 +18／+1C／+20 分別送入三個旋轉 helper；本 API 沒有改 +1C。兩個已用角度直接進 sin/cos，所以不能把第三數寫成 roll，也不能將角度說成度數。[C10–C11、C25–C29]

Q.CameraEffect 接三個整數。它在 `FD8C28` 的 32 筆、每筆 0x14-byte 紀錄中先拒絕任何 type>10 的狀態，再尋找空 type0；滿了即返回，沒有 success ACK。新記錄設 type10、t=0、limit=arg1（僅 arg1==0 時用40.0）、a=arg2、divisor=arg3。每次 effect tick 先把當前相機+28恢復為設定值，再按 active records 更新；type10 計算：

`cameraOffset = sin(t) * (a - t) / divisor`

然後 t 增加原件常數 `1.0471975803375244`；新 t 大於 limit 時清該 record type。`797EC0` 將此 +28 offset 加在相機位置第三分量。多筆 active record 依序寫同一欄位，不能當成逐項相加混音式效果；參數 divisor 必須由內容保證非零。[C30–C33、C25、K_EFFECT_STEP、K_EFFECT_ZERO_DEFAULT]

qbase 額外提供第一個 `waitFlag`：相等於原版 `TRUE` 時，呼叫 `wait(limit*33.333333333333336)`，否則 yield。這是腳本估算節奏，沒有檢查 native record 是否分配成功或真的已結束；若 limit=0，native 用40.0而 helper 乘原輸入0，兩者更不能視為完成協定。[P52、C30–C33]

### 4.4 Tutorial 共用相機能力的界線

`Tutorial.PushCamera(label)` 是實際 snapshot：將 `[FB76E8]+C` 開始的相機資料透過 `798900` 加入同一相機的 +A0 容器，然後把傳入 label 寫到新尾記錄。`Tutorial.PopCamera(label)` 直接交給 `7986E0`，共用 R10 已證的破壞式 labeled pop：先 restore、erase，再比對名字；不合會記錄 fault 並繼續。它確實能保存／還原相機，但內容須配對自身 push/pop，不應當成查詢任意標籤且不影響其他 frame 的 map。[U03–U04、U07–U08；固定父稿 presentation/report.md]

`Tutorial.StopCameraWorks()` 對 current 非 null call v+C，沒有替代 snapshot pop。`ApplyDefaultCamera()` 無輸入，調用 `54C410(FBAAF8)`，採設定欄位 FB9094（camera+18）與 FB907C（camera+24）；當 leader 存在時依其 heading byte 與既有 lookup 加 π 得到 camera+20。另有 `FBAAF8+40` 非零時發既有 F4358 UI 通知的分支。這是套回預設視角策略，不是還原 PushCamera 時的三維位置。[U02、U05–U06]

## 5. 音樂：非同步播放、循環、停止與後續音軌

### 5.1 Q 與 Tutorial 的 PlayMusic 可完成什麼

兩者都接 filename string 加 integer loop flag，最後到 `6D9B30(PM,path,flag,volumeWord)`，receiver 是 primary slot `FC0FFC`。Q 的音量來源包括原設定 FB90EA 與 FB935C，再經既有 gain 轉換；Tutorial 入口使用 FB90EA 的既有轉換路徑，沒有看到 Q 同樣的前置 FB935C 乘法。因此它們共享 player／slot，而不是兩個獨立音樂系統；也不把兩者設定音量處理稱為完全逐指令同義。[M01、U01、A_SI、A_TUT_SI]

request 先以 case-insensitive filename 比較 current slot 字串。相同便直接返回，連新的 loop flag 也不重設；若要明確重播，不能假定重複 PlayMusic 同名就會重頭播放。不同名字且舊 voice 存在時，設定 FB9335 選擇立即 Stop 或將舊 voice 放入3.0參數的 fade list。接著記錄新名稱、loop、volume，設定 start delay 並喚醒原生工作緒。fade list 中仍有音量係數大於1/3時選2.0延遲，否則0.01；這些是 native rate 單位的計算參數，不是已測得的實際開聲延遲。[M04、M12、K_OLD_FADE、K_FADE_THRESHOLD、K_DELAY_OVERLAP、K_DELAY_NORMAL]

### 5.2 實際播放 consumer 已閉合

`CMusicPlayer` 建立的 native functor 寫入 receiver FC0FC8 與 callback 6D9870，交 `6D8D20` 建 AlarmedThread。AlarmedThread 以 event 喚醒，對保存的 functor call v+8；實際 thunk 4FACD0 用保存 receiver 與 callback 執行音樂 worker。worker 在 critical section 中處理兩個 current slots 與 fade list，最後 Sleep(33)。此為既有原生音訊工作緒，不是 Lua timer registration。[M00、M05–M08、V_MUSIC_FUNCTOR]

pending start 每次減 `1/R`；到期進 `6D9E10`，在 16 筆 stream pool 中選非 busy instance。pool 的初始化 `80C950` 明確建 `CStreamDriver` vptr C51BF4，Play slot+14=80E940，Stop slot+2C=80EB30，busy slot+30=80ED00，gain slot+48/+4C=80EB90/80EBC0。`80E940` 檢查 filename 與已初始化輸出、建立具 RTTI 的 `COGGStream`、開檔／綁輸出、啟動播放並設 playing；load／device／busy pool 的失敗均可讓聲音未開始。[M09、M11、M15–M21、V_STREAM、V_OGG_STREAM]

主 Client 更新另會 `49133A→80CA10` 對 pool 的16項 call v+10；具體 `80E7D0` 在 playing 與非零 loop flag 下檢查輸出終止狀態，必要時 rewind stream 並重新啟動。這支援 loop 參數的實際效果，不僅保存一個未被讀取的整數。合法資源是否可由此 COGGStream 成功載入仍須依原內容，不能由類別名擴張為所有音訊格式相容。[M17、M22–M23]

### 5.3 Stop 與 FadeOut 的差別

`Q.StopMusic()` 到 `6D9CC0`，在 player lock 內呼叫全部 16 個 instance 的 v+2C，清 fade list、primary 與 secondary 的字串／pointer／pending delay。具體 80EB30 會等待自己的作業旗標清零，清 playing，停止輸出並釋放 stream。[M02、M14、M18]

`Q.StopMusicWithFadeOut(msInt)` 先將整數除以1000.0，再交 `6D9DA0`；後者清兩個 pending delay，把正在播放的 primary/secondary voice 移入 fade list，再清其名稱。每次 `6D9A10` 將 factor 減 `1/R/duration`，夾至0，交 stream+4C；額外 player mute byte 可使係數直接乘0。stream+4C只夾 factor 至[0,1]、轉 gain 並更新 volume，沒有 Stop 呼叫。factor 到0的狀態也沒有跟進 v+2C。故本輪確證的是**漸弱至靜音**，不能把函式名稱直接解釋為釋放音軌或讓 pool slot 立刻可重新使用。[M03、M10、M12–M13、M21、K_MILLISECONDS]

時間參數是原 ABI 的毫秒轉秒形態，但實際 worker 以 rate 倒數遞減並 Sleep(33)；工作緒排程與當時 R 都參與結果。不可把傳入1000推論成經量測保證恰一秒完成，也不應依賴零／負 duration，因 native 無一致的合法化處理。[M03、M08–M10、M28]

### 5.4 原版 helper 與完成觀察

qbase `PlayMusic(name)` 先組 `Sound/`＋name，將原版 `TRUE` 傳入 Q.PlayMusic；`StopMusic()`、`StopMusicWithFadeOut(value)` 各自直接呼叫 native。三者都只 yield 一次，沒有查 native voice 狀態，也沒有回傳播放完成時間。這足以做背景音樂開始／切換／停播與視覺節奏同步；若事件進度必須取決於某段聲音結束，不能把這三個 helper 當成已具備該完成事件。[P21–P23]

### 5.5 SetFinalMusic 不是立即 PlayMusic

`M+44` 是 std::string，其長度是 `M+54`。`SetFinalMusic` 的原件行為為：null 不變；首字元通過 whitespace predicate 時清空；其他情形以 `401FC0` **追加**輸入字串，該 helper 複製到舊 length 並增加 length。空字串不是 whitespace，追加0長度不會清除舊內容。重複呼叫非空名稱可能造成名稱串接，內容必須知道此版本行為。[M24–M25]

實際音樂消費在 `Q.RestoreMap` 563FA0。final string 非空時組 `Sound/`＋M+44，向 primary slot 發 loop=1的請求，再處理 map 對應 secondary slot；空字串走既有 map-secondary 路徑。Q.Stop 的 active 分支在字串為空時會先從既有 metadata `55FFC0` 取得 fallback、寫入 M+44，再呼叫 RestoreMap。本包沿用 R10 已證 Stop 的清理順序，並不把 normal End 一概寫成一定呼叫此 final-string 音樂消費。[M26–M29；固定父稿 presentation/report.md 的 q_end/q_stop]

## 6. 音效與語音：實際資源、佇列與 group

`Q.PlaySound(path)`／`Q.PlayTalkSound(path)` 接一個字串，組 native string 後向 `SoundManager FAB028` 查 `80AB00`；有回 resource 才 call v+14。新 resource 是 `MoonSound::SoundFile`，constructor 寫入原件 vtable C51B20，v+14→80D550 再呼叫 v+10→80D590；它取得 native output、建立 `SoundChannel`，並排入 command0的播放訊息。這裡 Q 不回傳 SoundChannel handle。[S01–S06、S10、S18、V_SOUND_FILE、V_SOUND_CHANNEL]

載入與播放佇列的 consumer 可具體到原生 worker：`80AFE0` 以 SoundManager receiver 與80B360建 native functor/thread；80B360反覆泵 `80E100`。80E100取出0x18-byte訊息，call target自身的 callback。resource 的 callback 為 vtable C51B48→80D8B0，依 ready/loading/failed 狀態呼叫具體 SoundFile.Load 80DD00。channel 的 callback C519D8→80CC90 檢查 target identity；resource ready 時將 position／flag交給 output+18啟動、套group並解除pending；failed則解除pending並標可收尾；仍在載入就重新排隊。[S07–S15、V_SOUND_RESOURCE_CALLBACK、V_SOUND_CHANNEL、V_SOUND_FUNCTOR]

這不是任意字串都能響的承諾。除了 manager 的資源開關、裝置／output與檔案可讀性外，在 `FBA860==0` 時，新載入還有原件前綴檢查，接受 `Scenario/`、`Prologue/`、`Voice/` 的分支；其他未登錄資源走明確拒絕訊息並設 failed。已有快取／預先登錄資源及不同全域模式不可混成同一拒絕條件。報告只保存上述檢查本身，沒有掃描整個聲音包來猜完整合法檔名表。[S03、S09、STR*]

PlayTalkSound 在成功取得 channel 後另查 `Voice` group，沒有找到則用既有 dummy group fallback；實際寫入的是 `channel+4` 所指 SoundFile 的 +8 group，而非建立新的 Lua voice owner。因 SoundFile 是快取資源，不能把這一欄位誤稱為只影響該單次 channel 的獨立設定。native channel 的後續 group消費在80CBE0，main更新80B410負責依pending、driver狀態與release條件回收channel，並遞減resource hold counter；不是以Lua coroutine消失當成音效停止。[S02–S04、S10–S12、S16–S17]

原 qbase `PlaySound`、`PlayTalkSound` 都直接傳入提供的 path，沒有像 PlayMusic 自動加 `Sound/`，之後僅 yield。兩者沒有在本介面提供完成 getter、每次播放 ID 或取消此單一音效的 API。因此可以串接語音、音效及對話畫面，但使用這些 helper 本身不能證明台詞聲音播完後才推進。[P47–P48、S01–S02]

## 7. Fade 與 Transition：兩套不同的畫面效果

### 7.1 Fade 共用遮罩：狀態、建立、更新、繪製

`F=FE2744` 的欄位為 texture pointer +0、width +4、height +8、active +C、alpha +10、dir +14、count +18、elapsed +1C。constructor設預設寬高1024／768並註冊 Fade namespace；它本身不配置 texture。graphics setup 路徑 `48F469→560AA0` 才配置 32×32 texture、格式0x15、初始填色FF000000；graphics teardown `48FC68→561010` 釋放並清 pointer。因此在正確初始化的 Client 畫面環境才具有實際 overlay，單有Lua binding不代表畫面資源已就緒。[F01–F02、F11–F12、F15–F16]

`Fade.Start(dir,count)` 將 dir與count存下、elapsed=0、active=1，初alpha為dir0時0，非零時255。Q.FadeOut(count)／FadeIn(count)直接寫同樣欄位，分別相當於dir0／1。[F03、F07–F08、A_FADE_I2]

`55E790` 每次 active update先 elapsed++，把整數elapsed與count作浮點相除、乘255後轉整數。dir0為alpha上升，達255後保持255，**active沒有清零**；dir非零為255減上述值，降到0後清alpha及active。它沒有delta參數；count是合格update計數的分母。`Q.update 561520` 在檢查Q active/pause之前已呼叫此 tick，所以不能將Q coroutine的pause直接當成視覺遮罩的pause。count0會走除零，不把它當合法的「立即完成」值。[F05、F13、K_ALPHA；固定父稿 runtime/presentation 的 outer gates]

繪製端55E7F0只檢查texture非null與alpha>1，依目前寬高放大tile，以alpha高byte加white RGB進texture v+24；由Q presentation再被main render呼叫。`Fade.End(0)`清active但保留alpha，繪製仍可持續；非零clear另清alpha，才取消覆蓋。可把這個差別用於停住遮罩或恢復可見畫面，而不是假設End無參數一定消除黑幕。[F04–F06、F14]

`FadeColor(packedInt)` 填的是共用texture本體，不更改count或alpha。native734470依texture格式寫32-bit或既有16-bit packed格式；此graphics初始化使用0x15。這提供彩色覆蓋效果，但腳本輸入仍是原版整數色碼，不是新增的RGBA四參數API；overlay繪製alpha與texture色／alpha各有角色。[F09–F11、A_COLOR]

### 7.2 原版 Fade 節奏

Q.FadeOut／FadeIn／FadeColor helper都只yield；qbase Phase1在g_transitionIdx=3的分支使用 `Fade.Start(0,30)`，之後 `wait(30)`；RevPhase1相應使用 `Fade.Start(1,30)` 與同樣wait值。這是原件的既有內容組合，沒有讀取Fade完成旗標。因 native是update計數、wait是另一套排程，保留原本呼叫值，不自行換算成保證完成時間。[P49–P51、P67、P74、F03–F05]

### 7.3 Transition：擷取當時畫面並放大、淡化

Transition使用另一個owner `X=FD2BB8`。constructor先disabled，graphics setup明確將enabled設1；teardown釋放capture、清phase及enabled。Client setup將預設layers=8、fadeRate=120。`Q.Transition(a,b)` 把兩個整數送738100；disabled即返回。任一輸入為-1時整對改用既有defaults，否則用兩個輸入；再釋放舊capture、清captured、phase=1、defer=1。[T01–T03、T07–T09]

下一個合格delta update先耗一次defer並置FBA7DC；之後 `7347F0` 從graphics surface擷取texture，保存capture尺寸。未被owner+134的freeze gate擋住時，delta有上界0.1；phase1初始化每層scale與alpha後進phase2，scale按層序增加、alpha減fadeRate×delta。第一層alpha到0時釋放capture並phase=0。[T04、T06、T10、K_TRANSITION_SCALE、K_TRANSITION_MAXDELTA]

main render `492FE6→7382F0` 只在phase2、有capture且layers>0時繪製，依新舊尺寸比與每層scale，居中以各自alpha畫同一擷取texture。這能做出畫面影像逐層放大的轉場，和Fade單色覆蓋的機制不同。原件中scale及alpha兩陣列各32項；request本體沒有幫layers做32上界檢查，不應把任意整數作成可選特效值域。原 qbase已證的實際組合是 `Q.Transition(2,120)`，本報告只推薦復用已核內容而不猜造數值表。[T02–T05、T11、P37]

此介面沒有本輪已證的公共Transition.IsEnded或Lua callback。helper僅yield；若要安排後續事件，需用原版內容已建立的節奏與可觀察事件，而不能虛構完成ACK。[P37、T01–T05]

## 8. Server 如何配合、可開始開發與尚需確認的範圍

### 8.1 現在可以開始的內容／Server工作

這些能力已能支撐「進入事件→建立演出狀態→相機／對話／音樂音效／轉場組合→按既有end/cancel路徑離開」的視聽事件。Server要配合的是**既有事件入口與資料契約**：提供合法scene/subscene/map等既有識別值與狀態、控制觸發條件、處理既有完成／取消／重入訊息，並保有進度與獎勵等權威狀態。不要為本地相機float setter、texture alpha或音效thread另發明新的Server執行器。[本包各能力鏈；固定父稿完整entry/control-flow與presentation清理契約]

可以據此直接開發的具體工作如下。

1. **內容能力選用表與參數檢查**：區分direct Q API與qbase helper；檢查字串、int/float、已見flag與顏色形式，禁止把有零分母的參數當「立即完成」。鏡頭採有效原資源與同一座標系，Fade／Transition使用已核實原值與狀態。
2. **既有事件資料與資源版本的對照**：Server需要知道其觸發的事件，在目標Client版本中具有相容MEF／Lua／CameraWorks／Sound資源；本包未新增下載、任意Lua注入或音訊檔名協定。
3. **進度、完成與取消的Server權威規則**：既有完成或取消回覆到達時核對該玩家與事件狀態、處理重複及過期回覆；不能以本地一個yield或音樂fade呼叫完成當作權威事件完成。
4. **有依據的驗收項目**：KeyFrame實際tick/IsEnded、同名音樂重播條件、fade後保留遮罩、相機snapshot標籤配對、resource/device失敗情況均已有精確檢查位置，可在授權的實際Client測試階段驗收，不需先猜API。

上述第2、3項屬Server開發需求；資源格式／參數、未知Client getter或callback、最後pose實際畫面等仍屬Client／內容驗收或待逆向事項，不把未證的Client介面移交成Server可以猜造的wire。

### 8.2 保留的具體邊界

| 已知能力 | 本輪沒有額外承諾的事 | 下一步要有什麼證據 |
|---|---|---|
| KeyFrame可載入、持續更新、查結束 | 任意camera資源成功；尾幀pose必顯示；可同時有多個獨立current player | 特定資源的原件schema／實際Client演出驗收；若需新增並行owner，另核既有實作 |
| 可以播放／停止／淡出音樂 | 每個PlayMusic都會立即重播；淡出必釋放；傳入毫秒保證牆鐘時間 | 指定合法音軌與device、worker排程的實際驗收；不可用新Lua ACK補空白 |
| 可以發一般／語音音效 | 任意檔名可載入；每次呼叫可由Lua辨識或等待聲音結束 | 既有Sound登錄／檔案、或另找到實際公開聲音observer；本包不宣稱全Client不存在 |
| 可以改覆蓋色與淡入淡出 | End(0)必清畫面；count是毫秒；Q.pause必凍結Fade | 依已證狀態設計；若要不同時間base，需查明既有API而不是改說已證語意 |
| 可以做擷取畫面轉場 | 任意layer count安全；有公開完成callback | 有界層數與有效graphics狀態；若需要完成observer，追實際公開binding與consumer |
| Tutorial可保存／回退相機 | Pop只查找且不改動不匹配frame；ApplyDefault等同保存點還原 | 按已證snapshot順序、label及預設視角邏輯配對使用 |

本輪停止於這些能力鏈已能從腳本輸入一路說明到具體效果consumer與主要生命期。沒有再次把研究中心放在「一般戰鬥能否完全取代Server」，沒有重掃全Client globals，也沒有把未檢視的API集合當成全程式不存在。

## 9. 可重跑驗證與交付

本包已實際執行驗證並取得 **PASS**：310個native records（221段code）、34,654 bytes節錄、10,590條保存指令、28個binding、19個原qbase prototype、8組typed vtables、191個固定Git pins，合計13,042項檢查；詳見 `verification-result.json`。其中54條明列direct edges、35個語意錨點、20個typed virtual target與11組能力契約均已對原件核對。

從任意cwd以驗證器的實際路徑執行（僅讀取原件、證據與本地固定Git objects）：

```bash
python -B verify_evidence.py \
  --bin /absolute/path/02-Tartaros.bin \
  --event-stp /absolute/path/06-Event.stp \
  --repo /absolute/path/ttr_anal_multi
```

驗證器確認原件身分、PE映射、全部excerpt與ASM bytes、28個binding tuple、typed vtable／RTTI、重要direct/virtual/dataflow約束、來源Git pins，以及重新讀取原STP選定qbase成員後的19個prototype、其root assignment與operands。它不執行Lua／Client，不fetch，不寫原件或repo。輸出的PASS只代表這些可重跑靜態證據成立，並非已進入遊戲完成音畫驗收。

正式交付allowlist：`report.md`、`bindings.json`、`contracts.json`、`lua-evidence.json`、`native-windows.json`、`native-windows.asm`、`source-manifest.json`、`verify_evidence.py`、`verification-result.json`、`deliverables-manifest.json`。`_work/`只供scratch分析，不發布；原BIN、STP及完整解碼成員均不在allowlist。
