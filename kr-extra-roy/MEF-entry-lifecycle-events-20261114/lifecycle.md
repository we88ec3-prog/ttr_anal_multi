# MEF 替代工作第三輪：普通場景 Q sequence、Tutorial 協程及生命週期

本稿為 `extra/roy1` 的靜態研究子稿。目標是判斷哪些執行工作已能交給 Client 腳本，及一般戰鬥常駐工作還缺哪一段原生契約。沒有執行 Client、Lua、封包或伺服器；沒有修改原件、Client、Server、Git 分支或索引。

- 固定 main 基準：`552e05a024505a3773095f951c285216051ce2a1`。
- 指派時工作 HEAD：`2d9896d`；前輪 parser／executor／storage 成果已發布，本文不重做前置 VM 的 72 個 stub、六個 callback 或原生 MEF 否定搜尋。
- 原始 BIN：`project_sources/02-Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始資源：`project_sources/06-Event.stp`，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- 完整原件視窗：`native-windows.json` 與 `native-windows.asm`；61 窗、8,115 bytes。每窗含 VA、raw offset、長度、hex 及 SHA256。
- Lua 證據：`lua-prototypes-evidence.json`。將既有 JSON 的原始成員位置回到 Event.stp，XOR FF 解碼，以唯讀 Lua 5.1 結構解析器核對所有 code words、constants 及結構欄位；三份資源共 93 個 proto、1,536 個 instruction words，保存本輪引用的 19 個 proto。這是資料解析及來源核對，不是執行或 T01 FULL-PASS。

## 1. 這輪的實質進展

**普通 `CMissionField` 內，已選中且載入成功的有限 Q sequence 可以持續得到 Client 更新。** 它的排程不是由 `CScenarioField` 專屬 update 呼叫，而是由共同的 `CClient` 更新函式獨立呼叫。配合入口支線新核的 `0047 → 561760`、`quest != 0` 不受 type 4／9／`0x19`（十進位 25）那段篩選限制，可建立「普通副本選定 sequence → 正式 VM → global qco 更新」的正向鏈。這項結論仍要求既有 lookup、資源及雙 VM 條件成立，不代表任意路徑或任意函式都能啟動。

**另有一條不以 Q manager `+28` 啟用狀態為前提的 `tco` 持續 runner，且可閉合進場、更新、子任務等待、取消及離場。** 原件將它接到 `Scene::CTutorial`，另在 `Scene::CExpedition` 的 Synopsis 啟用期間及指定回顧 UI 裡使用。它是有限且有明確 context 的正向能力，不能直接宣稱普通副本同樣會更新 `tco`。

因此，本輪不再停留於「MoCo 未知」。已經把 native 由誰呼叫、何時有 tick、兩個任務集合如何分開、停止由誰發動、哪些離場 hook 確實取消，逐項閉合。尚缺的 MoCo 內部時間單位、錯誤政策及普通戰鬥常駐橋接，被縮小為具體界線。

## 2. 共同外層更新：普通副本的正向排程證據

### 2.1 `490FE0` 同時容納 current field update 與 global Q update

原件 `C05AA4` vtable 的 `+30` 是 `490FE0`；`C05AA0 → COL C6940C → type descriptor F7DD1C` 的 RTTI 名稱為 `.?AVCClient@@`。COL offset 為 8，因此本文不把函式內 owner 相對欄位任意換算成最外層 CClient 結構偏移。

| 區段 | 原始資料流 | 含義 |
|---|---|---|
| `491020–491025` | `[ebp+8] → [esp+20]` | 保存更新呼叫者傳入的 owner，後續讀 owner `+BFCC`。 |
| `491CA7–491CAD` | owner `+BFCC != 0` 跳過 field update 群 | 本輪直接證明欄位及分支；沒有追 writer，故不進一步命名此欄語意。 |
| `491CD8 → 489CB0` | getter 返回 `&FD2CF8`；`491CDD` 讀其 `+5EAC` | 取得當前 scene instance。 |
| `491CE7–491CEC` | 非空 scene → vtable `+18` | 呼叫當前場景自己的更新。 |
| `491E71–491E7C` | 同 owner `+BFCC != 0` 跳到 `491F43` | 另一次共同閘門，包住 global Q 更新。 |
| `491ED0 → 422F40` | getter 經初始化後明確返回 `&FB73C0` | Q manager 是全域 singleton，不是 current field instance。 |
| `491ED5–491ED7` | ECX = `&FB73C0` → `561520` | 共同外層直接更新 Q manager。 |

**精確拓樸：** `423060 → 4ADB10` 本身沒有呼叫 `561520`；兩者是在 `490FE0` 的不同子路徑被更新。current scene `+18` 的回傳值在 `491CEE` 存到 local `+18`，後面的 Q gate 與呼叫不依賴該回傳值。不能將「普通副本自己的 update 沒找到 Lua call」推成普通副本不能執行已啟用的 Q sequence。

### 2.2 `561520` 的實際閘門

`561549` 以 ECX 保存 manager 到 EDI。以下 offset 都屬於 `M = &FB73C0`，不能套到 Tutorial owner 或 field instance。

| 欄位／操作 | 原件 | 本輪可證結論 |
|---|---|---|
| `M+28`／絕對 `FB73E8` | `561587` 比較 0；零跳 `5615E0` | 未啟用 Q scene 時，跳過 `f_doCoTask`。 |
| current controller `+58` | `5615BF` 取 `[FBA7A4]`，`5615C4` 寫 1 | Q scene 活動時會改動 controller 狀態。本輪未將該欄直接命名為「封鎖所有戰鬥」。 |
| `M+2C`／絕對 `FB73EC` | `5615C7` 比較 0；非零跳 `5615E0` | 額外的停泵條件。原件 constructor 寫 0；本輪沒有閉合其可用的非零 writer，不能自造 Pause／Resume API。 |
| `M+0` | `5615CD` 取 wrapper | 使用前輪已證的正式全域 Lua wrapper。 |
| 命名執行 | `5615D3` 推入 `C106A0 = "f_doCoTask"`；`5615D8 → 6F4DD0` | 以 0 個參數、0 個回傳值要求呼叫該全域函式。 |
| `M+1C` actor tree | `5615E0` 起遍歷；`5615F8` call actor vtable `+20` | actor 更新位於 coroutine gate 之後；即使上述 gate 跳過 coroutine call，也仍走這段。 |

已證的門檻是 outer owner `+BFCC == 0`、`M+28 != 0`、`M+2C == 0`，並且必須有**有效的 current controller**：`5615BF–5615C4` 直接寫 `[FBA7A4]+58`，沒有 NULL gate。入口不檢查 scene 型別，不能解讀成沒有 controller 的 context 也安全。這些條件不要求 `currentScene` 必須等於 `CScenarioField`。入口支線的 `561760` 確認成立後，普通副本能承載有限的本地場景編排。**這不等於已證明可令 `M+28` 長期維持啟用而仍保留完整一般戰鬥、操作及後續切圖語意。**

**同輪追加補證：** [controller-input.md](controller-input.md) 已沿三種已知 controller 的共用 consumer 追到 `+58` 的效果：相關控制 row 的移動位元與動作量會被清零，既有 `000A` 仍可送出零控制 row，該旗標在消費末端清除。這縮小了本節原先保留的未知；仍沒有將它說成所有攻擊／技能／世界更新一律停止。Q 的有限演出能力與不影響一般操作的常駐 battle runner 應分別判定。

## 3. 兩個 Lua 任務集合的 owner

| 對象 | owner／建立 | 更新入口 | 完成／取消入口 |
|---|---|---|---|
| `qco` | qbase proto 0：`qco = MoCo.new()`；native Q manager `M = &FB73C0` | `561520 → f_doCoTask → qco:doCoTask(Q.EndCutScene)` | `561DB0 → f_removeAllCoroutines → qco:removeAllCoroutines()` |
| `tco` | TutorialBase proto 0：另一次 `MoCo.new()`；native Tutorial owner `T = &FC0F84` | `4A8B90 → t_doCoTask → tco:doCoTask(Q.EndCutScene)` | `t_removeCoroutine(handle)`／`t_removeAllCoroutines()`；Tutorial 離場明確呼叫後者 |

兩者共用前輪已核的全域 wrapper `W = &FDF3C8`，但 `qco`、`tco` 是兩次建立的 Lua 物件。共用 VM 不等於共用任務集合。

- `56060B` 將 W 存入 `M+0`；`56060D → 565E40` 註冊 Q。
- `560796 / 5607A2 / 5607AE / 5607BA` 依序載入 `Coroutine.lua`、`Boot.lua`、`Logic.lua`、`Event/qbase.lua`。
- `4A88EB` 將傳入的 W 存入 Tutorial owner `+0`；`4A89B6 → 6F4A50` 載入 `Event/TutorialBase.lua`。初始化呼叫者對 W／T 的實參精確證據承接前輪 `parser.md`。

`M+28` 是 Q scene 啟用欄位；`T+34 = FC0FB8` 是 `t_doCoTask` 回傳值經轉換後的狀態欄位；兩者不可混為同一個「腳本是否仍活著」旗標。

## 4. Tutorial 的進場、執行與離場已閉合

### 4.1 場景型別及 hook 來源

`4C4AD5` 寫入 vptr `C073E8`。原件 `C073E4 → COL C69E04 → F7E1E0` 指到 `.?AVCTutorial@Scene@@`；這不是根據位址鄰近或反編譯名稱推測。

| vtable slot | 原件 target | 本輪行為 |
|---|---:|---|
| `+10` | `4C4B10` | 進場初始化，準備 Tutorial 資料／controller，載入 TutorialMain 並呼入口。 |
| `+14` | `4C4D60` | 移除 tco 所有任務，清理 native 追蹤表。 |
| `+18` | `4C4DF0` | base update 後固定呼叫 `4A8B90`。 |

共同換 scene 函式 `4B7D50` 已由原件重核：`4B7D6E` 先呼舊 scene vtable `+14`，`4B7D80` 再呼舊 destructor，`4B7D82` 清舊指標；`4B7DA7` 安裝新 scene，`4B7DBC` 呼新 vtable `+10`。因此 Tutorial 的進退場 hook 確實接在共同換場景生命週期上。

### 4.2 進場到腳本入口

`4C4B10` 在 `4C4C95` 呼 `4A8C20(T)` 準備資料；controller 為重用既有 kind 4 或由 `4C4CF2 → 548B90` 建立，`4C4D01` 寫入 `[FBA7A4]`。這不是把一般 Mission controller 原封不動當成 Tutorial controller。

`4C4D3A` 令 ESI = `&FC0F84`，`4C4D3F → 4A8A60`。後者：

1. 清理／初始化 Tutorial 相關集合與介面狀態。
2. 在原有發送條件允許時組 `C2S 000C`、長度 6、參數 1；這是既有 Tutorial 啟動流程的一部分，不能把檔案放到磁碟便算完成整合。
3. `4A8B64 → 6F4A50("Event/TutorialMain.lua")`。
4. `4A8B74 → 6F4DD0("Tutorial_EntryPoint", 0, 0)`。

TutorialMain proto 9 的 `Tutorial_EntryPoint` 呼 `t_executeCoFunction(TutorialMain)`。TutorialBase proto 1 直接給出契約：

```lua
-- 從位元碼還原的控制關係；未執行、非本輪部署檔。
return tco:registerCoroutine(tco:createCoroutine(f))
```

這個載入 caller 直接走正式 VM 的 `6F4A50`，沒有先呼 `55D6A0`。若 Tutorial 腳本接著呼本地 Q sequence，該 sequence 仍有自己的前置／正式 VM 條件；不能把這個區別擴大成所有 `.seq` 都免前置載入。

### 4.3 持續 tick 與回傳值契約

`4C4DF0` 先在 `4C4E14` 呼 `4ADB10`，更新其他 native 管理器後，在 `4C4E85` 推 T、`4C4E8A → 4A8B90`。此完整函式沒有檢查 `M+28`。

`4A8B90` 取 `T+0` 的 wrapper，以 `4AD0A0(W, 1, "t_doCoTask")` 要求一個 Lua 回傳值。然後：

- `4A8BB7–4A8BC2` 接受 Lua number（tag 3）或可轉數值的 string（tag 4）。
- `4A8BCC → 6F7760` 的字串轉換失敗，或其他 tag，寫 `T+34 = 0`。
- 成功分支 `4A8BED` 用 `FISTP` 把數值轉為整數，再於 `4A8BF5–4A8BFA` 依該整數是否非零寫 0／1。

因此自訂相容 `t_doCoTask` 若提供回傳值，必須遵守這個**數值回傳契約**；Lua boolean `true` 不會被這個 helper 當作非零數值。這也不能用 C wrapper 的 `EAX = 1` 推定腳本數值恆為 1：wrapper 的 EAX 常是回傳槽數量。

TutorialBase proto 2 的實際函式是：

```lua
return tco:doCoTask(Q.EndCutScene)
```

這證明 `Q.EndCutScene` 被當作參數傳入 MoCo。缺少 MoCo 函式體時，本文不將它指定成「所有任務正常結束時一定呼叫」或「只在錯誤時呼叫」。

### 4.4 等待子場景、取消子任務與離場

TutorialMain proto 1 `PlayAndWaitForScene(a,b)` 先呼 `Tutorial.StartCutScene(a,b)`，再迴圈查 `Tutorial.IsCutSceneRunning()`，與全域 `FALSE` 比較；尚未結束時呼 `yield()`，回到查詢點；離開迴圈後再有一次 `yield()`。這裡不把 `FALSE` 擅自替換成 Lua boolean，亦不把一次 yield 換算成固定毫秒。

其查詢 API 的 native 鏈已閉合：`4AACC0` 把 `4A97B0` 存進 `FE1830`，以名稱 `IsCutSceneRunning` 綁定 `4AC270`；wrapper `4AC2AD` 間接呼該 target，target `4A97FE` 讀 `FB73E8`。wrapper 把實際 EAX 轉為 Lua number 入棧，然後才回傳「1 個值」。

TutorialMain proto 7／8 的控制關係進一步證明了任務生命週期：

- 建立子任務後保存 `t_executeCoFunction` 的回傳值，作為後續 alive／remove 查詢的 handle；本輪沒有假定該 handle 的 Lua 內部型別。
- `t_isCoroutineAlive(handle)` 仍成立時，反覆檢查 `Tutorial.IsSynopsisSkipped()` 或指定 `Tutorial.GetControlStatus(...)`，中間呼 `yield()`。
- skip／控制條件成立後，呼 `t_removeCoroutine(handle)`；TutorialMain 的指定分支還先呼 `Tutorial.StopCutScene()`，然後刪除子任務。
- `StopCutScene` 由 `4AAD60 → FE1834 = 4A9820`、wrapper `4AC2E0` 間接呼叫。`4A987E → 5624B0(M,0)`，後接 `562250` 的介面清理；不是只把 tco 的 native 狀態欄位改零。
- TutorialBase proto 4／5 分別轉呼 `tco:removeCoroutine(handle)` 與 `tco:isCoroutineAlive(handle)`。沒有引入新 opcode 或猜測新的 Server callback。

離場則由 `4C4D60` 的 `4C4DC2` 呼 `t_removeAllCoroutines`，接 `4C4DCC → 4A9DB0(T)`。TutorialBase proto 3 將前者轉成 `tco:removeAllCoroutines()`。後者遍歷 T `+14` 的 native tree，把其 pointee `+14` 清零，釋放 tree nodes、重設哨兵及 count，並清理畫面相關集合。這是確切的 native 追蹤表清理；沒有把它說成「所有遊戲 actor 都被析構」或「整個 Lua VM 被關閉」。

**可實作內容的含義：** Tutorial 已有 Client 本地父子任務、等待使用者／native 狀態變化、取消子任務及離場全取消的機制。這些本地控制可以接替 Server 逐步下指令的編排工作。但它的 context、資料與 native API 都帶有 Tutorial 條件，仍不能將同一份腳本直接視為普通副本的常駐波次控制器。

## 5. 另外兩個 tco caller 的限制

本輪對 `.text` 中 `E8 rel32 → 4A8B90` 作候選掃描，只有三個直接 call；每一筆均已回到原件指令邊界確認。此列舉範圍不包含所有可能的間接呼叫，不能升格成「全機沒有其他 Lua runner」。

| 原件 caller | owner/context 證據 | tick 條件 | native 完成行為 |
|---|---|---|---|
| `4C4E8A` | `CTutorial` vtable `C073E8+18 → 4C4DF0` | 共同場景更新已抵達本函式後，無 `M+28` gate | 離場 `+14 → 4C4D60` 全取消 tco。 |
| `4C19AE` | `CExpedition` vtable `C07280+18 → 4C1930`；COL `C69C70`／type `F7E138` | field `+BD78 != 0` | `FC0FB8 == 0` 後移除全部 tco、清 native table，再 `4C2050`。 |
| `47CA45` | `47C980` 從傳入 owner 的 `+FC → +CC → +DC` 取得 UI；vtable `+4` 回傳類型 id 必須 `0x12D` | 該 UI `+26C` byte 非零 | `FC0FB8 == 0` 後呼 `47B6B0` 等收尾。這不是普通 field 通用呼叫。 |

Expedition gate 的 writer 已閉合：`4C1FCE` 把 field `+BD78` 寫 1，`4C1FFC → 4A89C0` 載入同一 `Event/TutorialMain.lua`，但呼的是 `Synopsis_EntryPoint`。TutorialMain proto 10 再註冊 `PlaySynopsisMain`。結束時 `4C20B6` 再呼 `t_removeAllCoroutines`、`4C20C0` 清追蹤表、`4C20CA` 將 field `+BD78` 清零。這條是明確啟用期間的 Synopsis runner。

## 6. Q scene 的結束與停止

### 6.1 `Q.EndCutScene → 561DB0`

`565FC0` 在 Q 表登記 `EndCutScene` 的 target `561DB0`（`FE2780`）；名稱資料位於 `D6A260`。本輪完整保存該 target 的兩條模式分支。

| 模式 | 啟用清除 | coroutine 操作 | 後續狀態 |
|---|---|---|---|
| `M+89 == 0` | `561F60` 檢 `M+28`；`561F69` 清零 | `562022–56202D` 呼 `f_removeAllCoroutines` | 根據 `M+38/+3C` 做既有結束決策／回報；還原 `M+84` 與 `M+88` 對應狀態，清 `+38/+3C`。 |
| `M+89 != 0` | `561DED` 檢 `M+28`；`561DF6` 清零 | `561E36–561E42` 呼 `f_removeAllCoroutines` | `47E640` 查後續 scene；非零於 `561EF3 → 565720` 啟動下一段，否則走回顧介面收尾。 |

`f_removeAllCoroutines` 是 qbase proto 3，操作 **qco**。EndCutScene 內兩次可辨的命名呼叫都是此名字，沒有在這兩個窗內呼 `t_removeAllCoroutines`。因此父 Tutorial 任務可以跨越子 Q scene，透過查 `M+28` 判斷子場景是否已結束；不必將兩種 coroutine owner 混成同一個。

### 6.2 `5624B0(M, arg)` 是較大的停止／清理路徑

`56251E` 要求 `M+28 != 0` 才進後續清理；`562687–56269D` 對同 M 依序呼 `563FA0`、`563A70`、`562B00`，另重設對話、畫面／其他既有 native 狀態；最後 `56288C → 561DB0`。本輪沒有把這些未深入的 cleanup callees 全部重新命名成 actor destructor。

已核兩個外部 caller：

- `Tutorial.StopCutScene → 4A987E → 5624B0(M,0)`。
- `CMissionField` 的 **S2C `0031` handler** `4BCA90`：`4BCB1D` 推 0，`4BCB1F` 取 M，`4BCB24 → 5624B0`。它還發本機 `F4267` 介面事件。這是封包 handler，並非 field 的 `+14` 離場 hook。

入口支線另證 `0038` 在 `4B1D07` 推 0、`4B1D09` 取 M、`4B1D0E → 5624B0`，然後才在 `4B1D13` 進入 `0038` 自身後續預載分派。這只能確定該 handler 內的先後順序，**不能保證此停止早於 `005F / 4B7D50` 的場景安裝**；`005F` 可能已在 `0038` 之前處理。不同停止 caller 的涵蓋情境需要按路徑整合，不能僅因某一路有 cleanup 就宣稱任何離圖皆保證取消。

## 7. 普通場景與離場對照：能力正向、限制精確

| 場景 | update slot／行為 | exit slot／行為 | 本輪結論 |
|---|---|---|---|
| `CMissionField` | `C0705C+18 = 423060`；先 `4ADB10`，另跑 `+BD54/+BD58` 倒數與 C2S `0031` | `+14 = 4BBF10`；呼 `553740` 清指定集合 | 共同外層 global Q pump 仍可更新已啟用的 Q sequence。此 field update 本身沒有額外的 tco call；其 exit hook 本身也沒有直接呼兩個 removeAll 函式。 |
| `CScenarioField` | `C073B4+18 = 4ADB10` | `+14 = 8DC2F0` 空 hook | 不可把專名 CScenarioField 誤當唯一 Q executor；它同樣依賴共同外層 Q pump。 |
| `CTutorial` | `C073E8+18 = 4C4DF0`，加跑 tco | `+14 = 4C4D60` | 有不依賴 `M+28` 的額外任務泵，且離場有明確全取消。 |
| `CExpedition` | `C07280+18 = 4C1930`，只於 `+BD78` 啟用 Synopsis 時加跑 tco | `+14 = 8DC2F0` 空 hook | 已證 Synopsis 完成路徑自行關 gate；未以空離場 hook 推定在所有中斷路徑都會取消。 |

`4ADB10` 本身遍歷 `FB79F4..FB79F8` 內物件並呼其 vtable `+20`，再呼 field vtable `+24`。本輪沒有窮舉這些間接 callback 的所有 concrete types，因此對 ordinary field 的結論是「尚未閉合另一條無 Q 啟用旗標的通用 battle runner」，不是「已證全 Client 不存在」。

**取消與銷毀要分開：** Q manager 和 Tutorial owner 都是全域持有的物件；field destructor 不會因為 owner 指標恰好存在就自動等同 Lua thread destruction。本輪可直接證明的是特定 hook／停止路徑呼到各自 removeAll，及 native tracking tree 的清理。Lua coroutine 物件何時被 GC、異常被移除後是否還有其他引用，仍需 MoCo 原件或後續有界追蹤。

## 8. 新腳本的實作契約

| 要接替的 Server 操作 | Client 現有能力 | 可以開始的內容 | 不可逕行承諾的延伸 |
|---|---|---|---|
| 每一步對話、鏡頭、指定事件 actor 動作的編排 | 已證 Q sequence／qco；普通 field 有共同 pump | 以入口支線的選擇鏈與前輪已證 Q API 製作有限場景序列，Server 只啟動／收結束結果 | 不能因序列可跑，就把普通怪 AI、死亡事件或戰鬥控制完整轉給腳本。 |
| 等待某段場景播放完再繼續本地教學 | TutorialMain 已用 `IsCutSceneRunning + yield` 等待 | 在合法 Tutorial context 實作父子任務與非阻塞等待 | 不推定其等待單位是秒／毫秒，亦不將 Tutorial API 變成普通關卡 API。 |
| 本地 skip／取消某個子任務 | tco 有 handle、alive、remove；native StopCutScene 可終止 qco | 依同一 handle 生命周期建立可取消教學／Synopsis 流程 | 缺少 MoCo 函式體時，不保證任務錯誤、重入、取消當前 task 的精確策略。 |
| 離圖收掉全部腳本 | Tutorial exit hook 已證，Q 有指定 stop caller | 把 Tutorial 離場與有限 Q 明確終止列入整合契約 | 普通 scene 的所有切換／斷線／重入情境尚未形成單一保證。 |
| 一般戰鬥持續計時、清怪→下一波 | native 持續 tick 存在；ordinary Q 與 Tutorial tco 的適用條件已縮小 | 可開始有限 sequence prototype，並保留工作來源／狀態分層 | 仍缺普通 battle 合法啟用及取消橋接、死亡／清組事件和 EntityId／AI 對齊，不能標成 MEF 替代完成。 |

### 雙 VM 條件仍有效

本輪沒有改寫前輪契約：普通 `.seq` 的前置 VM 與正式 VM 不同；前置 Register 會立即呼場景函式做蒐集，wait／yield stub 不會真的讓出，`lb` 並非該 VM 已證的可用表。故不能把只在正式 VM 成立的長期迴圈直接放進未分階段的前置執行路徑。TutorialMain 入口本身的直接正式載入不能解除所有子 sequence 的條件。

這是 Client 既有契約，不應推給 Server 自行猜測；同樣不能以「讓 Server 繼續下每一步命令」替代使用者要求的 Client 腳本接管。

## 9. 剩餘事項及可驗收終點

### Client 待逆向

1. **普通 battle 常駐工作契約。** 已有 ordinary finite Q sequence 正向鏈；同輪 `controller-input.md` 另已閉合 `+58` 對既有控制 word 的抑制。仍需能保留一般操作的合法啟用／更新方式，以及其餘戰鬥封包／UI／取消條件，不能假定保持 `M+28` 不會干擾操作。驗收終點是可指出 ordinary field 的合法註冊／啟動位置、每次 tick 的實際 owner、終止與重入條件，不要求把整個遊戲反編譯。
2. **wait 與 MoCo 內部政策。** 精確缺口是 `Coroutine.lua` 13 個 proto 的原始 bytes／完整可追溯解碼，以讀取 `doCoTask`、`createCoroutine`、`registerCoroutine`、`wait` 等對時間、resume 結果、錯誤與移除的判斷。驗收終點為時間來源／單位、正常完成與錯誤分支、移除時機及 callback 條件。官方 MEF 原件不是必要前提。
3. **ordinary 全路徑取消。** 已證 Tutorial exit、Q End/Stop 與特定 handler；還需按需要支援的普通關卡切圖／斷線／重試情境核對取消到達性，特別是普通 field exit hook 沒有直接 qco removeAll。驗收終點是每一個受支援情境能指出 stop/cancel 路徑及下一場不沿用舊任務的條件。
4. **戰鬥事件與實體一致性。** 清怪／死亡如何讓腳本知道、腳本生成的實體如何和 Server EntityId 對齊、普通 AI 接管，屬其餘支線；本輪 tick 能力不替代那些證據。

### Server 待開發

- 提供與已證 lookup／載入條件相符的選擇資料、觸發內容和既有必要回覆；不猜官方內部策略。
- 若使用 Tutorial 流程，遵守其進場／controller／`000C` 等既有相容介面。不能只送 `.mef` 字節後期待自動成為 Tutorial 任務。
- 記錄哪些編排已移到 Client 執行、Server 還保留哪些真實業務工作；不要把 Server 代跑波次列為「MEF 完成」。

### 跨功能待整合

- 入口支線的 `0047 / 561760` 與本輪共同 pump、前輪雙 VM／Q API、結束回報，串成一個有限 sequence prototype。
- Tutorial prototype 可沿本輪完整 init/update/cancel/exit 生命週期，但須保留 context 限制。

### 待遊玩驗證

- 正常遊玩下有限 sequence 是否按預期更新及回報；skip、離圖、重入後是否殘留任務；同場多人／隊伍狀態是否影響流程。
- 這些是靜態契約整合後的驗收，不能用尚無 runtime trace 否定本輪已證的 call chain，也不能以 source hash 相符宣稱已可玩。

## 10. 來源界線與修正記錄

### 已復用

- `kr-extra-roy/20261114-190624-chatgpt-web-roy1-MEF-parser-executor-storage.md` 及其 `executor.md`、`parser.md`：正式／前置 VM、Q/lb/Tutorial wrapper 身分、protected call、標準 Lua coroutine 原生 resume/yield、雙 VM 限制。
- `shared/integrations/T01-20261029-semantic-review/t16/native-functions.json`：函式導航與 unreviewed pseudocode；本輪新增 native 主張均以原件窗為準。
- 三份 pinned T16 Lua JSON：本輪回到原始 Event.stp 再解析核對；Git commit、path、blob、JSON hash 及原始成員位置都保存在 `source-manifest.json`。
- 入口支線本輪原稿：`entry.md`。與本主稿同次發布；本稿不冒稱該支線入口已由本作者完整重做。

### 不得誤述的四點

1. 之前未取得 Coroutine.lua，不等於既有研究從未讀過它。S00 feasibility 的「兩版啟動 Lua 的檔案讀取範圍」明載兩版檔案相同，Coroutine.lua 13 proto，引用 `anal/SHARED-LUA-LOADING-AND-TUTORIAL-BOUNDARY.md`。本輪提供的 originals 和 pinned T16 JSON 沒有其 bytes；承認既有分析，僅保留本輪無法重驗細部政策的界線。
2. 「qco 受 CutScene 啟用旗標控制」不等於「只有 CScenarioField 能執行」。共同 outer update 已補正此歧義，ordinary finite Q sequence 是本輪正向結果。
3. `4BCA90` 是 `0031` handler，不能當 `CMissionField` exit hook。原件 exit 是 `4BBF10`。
4. `EAX=1` 可能表示 Lua C 函式回傳一個槽。前輪 GetObjectCount 的修正維持；本輪 `4AC270` 明確展示了「先把實際 native 值入棧，再 return 1」的正確對照。不要把 wrapper 返回值數量當成遊戲 count 或 task count。

## 11. 可重驗方式與交付清單

本分題的 61 個窗口已併入 `native-windows.json` 的 lifecycle 群組；`lua-prototypes-evidence.json` 保存三份原始 Lua 的來源與本輪 19 個引用 prototype。來源身分集中在 `source-manifest.json`。統一重驗命令見本目錄 `README.md`，由 `verify_evidence.py` 核對 PE／STPD／Lua 資料，沒有執行 Client 或 Lua。

本分題完成已界定的 scheduler／context／lifecycle 證據整理；一般戰鬥的完整 Client 接管仍屬階段性未完成。沒有宣稱找到原生 `.mef` 引擎，也沒有將既有 Lua 能力冒充官方格式已還原。
