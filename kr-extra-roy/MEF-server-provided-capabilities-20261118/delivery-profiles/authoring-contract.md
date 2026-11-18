# 自製 MEF：有限 Q 內容的作者契約

2026-11-18；研究基準 `60c1c1a5dc7a73902d9dbb50361d5148e8b30058`。本文件把 MEF 視為 Server 提供的玩法內容：Server 建置／發布內容，Client 用已存在的 Lua／SEQ 能力執行其中可本地完成的工作。這是研究規格，沒有產生或部署遊戲 `.seq`、執行 Lua 或改 Client。來源代碼見本目錄 [report.md](report.md) 與 [source-manifest.json](source-manifest.json)。

## 1. 一次啟動，可以包含多個本地步驟

有限 Q 已有第一次載入、協程、毫秒等待、正式遊戲 API 及正常 End；足以讓「先等一段時間，再開已存在的出口／服務點，最後收尾」由一份內容自行推進。Server 不需要為每個本地等待 tick 或每個中間演出步驟另發指令。這個 profile 接受 Q 演出期間的控制／UI 影響，**不要求先完成普通戰鬥背景 B**。[S03、S05、S07、S16]

以下重用 A1 已證的 local 階段判別與 setter／End 次序，但加入 `wait`，所以是**新有限內容設計**，並非聲稱原 A1-v1「單次 setter、無多步排程」規格已原樣包含此流程。`BOUND_POINT_KEY`、`BOUND_CATEGORY`、`BOUND_DELAY_MS` 都是建置時待綁定的整數 literal；沒有任意選用一個實機點或時間。範本本身不可直接部署。

```lua
-- AUTHORING SPECIFICATION ONLY. NOT AN INSTALLED GAME RESOURCE.
local formal_after_register = false

Register(function()
    if not formal_after_register then
        -- This example creates no model, animation, camera, or music dependency.
        -- The prepass must finish here without waits or gameplay side effects.
        return
    end

    wait(BOUND_DELAY_MS)
    Tutorial.SetCheckPointStatus(BOUND_POINT_KEY, BOUND_CATEGORY, 1)
    Q.EndCutScene()
    return
end)

formal_after_register = true
```

建置結果選用 ASCII Lua 5.1 文字、LF、無 BOM，交給已證 `Event/Sequences/<funcName>.seq` consumer。原 parser 依首 byte 區分 binary／text，並不要求內容工具復原官方 MEF grammar。內容產品可稱為 MEF；這裡的 `.seq` 是現有 Client adapter 所消費的路徑格式，不是另訂產品目標。[N02、N07、S03]

## 2. 為何前置不提前開門，正式才計時

| 時點 | 前置資源 VM | 正式 VM |
|---|---|---|
| 執行 chunk | 本次 local=false | 另一份本次 local=false |
| `Register` | native 同步呼入 callback，看 false，有限返回 | qbase 建 coroutine、加入 qco；此時沒有 resume |
| `Register` 正常返回 | local=true，但這個 callback 不在正式 qco | local=true，closure 保留這個 upvalue |
| 後續合格 Q tick | 不用此 VM 跑正式玩法 | callback 看 true，開始 wait／setter／End |

這是已證原 binding、正常非重入條件下的時序，不是新原生 stage flag。兩個 VM 都持續存在，不能以全域 `DoFile` 有沒有值猜階段。Register 必須**恰一個 Lua closure**：前置拿最後一個引數，正式 qbase 固定拿第一個，額外引數會破壞對應。[N05、S05]

不要將 setter、`End` 或任何 gameplay 操作搬到 chunk 頂層。native Start 在正式 loader 返回後仍會把 point 呈現 gate 設為 0；真正 callback 必須等後續 pump，才能讓 End 的 gate 還原出現在 Start 尾端之後。[N03、N04、A04–A07]

## 3. ABI、等待與完成界線

| 使用項目 | 精確作者契約 | 對玩家／Server 的含義 |
|---|---|---|
| `Register(f)` | 恰一個 Lua closure；不回成功 bool 或工作 handle | 登記成功不等於已執行或內容成功 |
| `wait(ms)` | 恰一個正常整數 number；本設計要求非負、有限、經內容政策核准 | 基於 `lb.GetTime→timeGetTime`；先 yield，後續 resume 才比較經過毫秒 |
| `wait(0)` | 仍先讓出一次 | 不等於立刻完成，也不保證恰一畫面 frame |
| `Tutorial.SetCheckPointStatus(key,category,1)` | 恰三個整數 number；本設計 category 僅 0／2／3，key 由已綁定完整點快照取得 | 修改已存在且匹配的點。不是建立出口，也沒有可靠成功回值 |
| `Q.EndCutScene()` | 恰零引數；在自己持有的有限 Q 工作尾端明確呼叫 | End 之後立即 return，不再 wait、不新增工作 |
| `0047` | application 6 bytes：`u16 opcode, i16 quest, i16 scene` | 只選已載入 SceneList 的雙鍵，沒有檔名、script bytes、point 或任意變數欄位 |
| `003F` | application 8 bytes：`u16 opcode, low16 quest, low16 scene, u16 1` | 末欄是固定值，沒有表示本次 setter、module、任務或獎勵成功 |
| `00EB` | application 2 bytes，適用於既有等待解除路徑 | 清相關 dialog／mask2；不 Stop Q、不返回新 ACK、不證全部輸入 owner 已還原 |

Q 更新要求 active、unpaused、主迴圈更新 gate 允許。loading 可以繼續收網路命令，卻跳過 Q 更新；因此不能承諾準點觸發或給固定最大等待時間。timer marshalling 有 signed32 邊界，舊 scheduler 已證其跨界差值限制；自製內容應採短有限流程，不把這個 timer 當跨日可靠排程器。[N04、N15–N17、S01、S07]

**正常 `return` 不代替 End。** MoCo 的 `doCoTask` 固定只收 self，qbase 傳入的 `Q.EndCutScene` callback 未被轉交給實際 executor。成功 return 的 coroutine 也不在同一輪直接刪除。內容自己負責顯式 End；取消／移除 list 不會替 suspended body 跑尾端清理。[L01–L08、S07]

最小示例採 quest0 完成政策時，Server 在匹配該 run 的 003F 後才安排 00EB；不要在 0047 後預先送 00EB，因為 End 後面可能重新置等待。seen-skip 也能送 003F 而沒有載本次內容。非零 quest 的正常 End 另受 `CheckConfirmMessage==1` gate，不能把既有 119 雙鍵直接當必回報的無確認通道。[N06、N18、S05、S16]

## 4. 加入多步演出時，怎樣編寫前置宣告

上例不建立新素材，所以前置可直接 return。日後在同一正式 coroutine 依次加入角色、動作、音樂、相機、對話等，只要求每項實際 API 的 context／資源／owner 契約滿足；不要求 B。可讓多個 phase 在一次 Start 中排序，避免 Server 逐段定時派送。[S05、S15]

| 前置全域 helper | 恰當 arity | 前置真正收集的資料 |
|---|---:|---|
| `CreateObject` | 9 | slot 第 1、model 第 2、action 第 6；先宣告 slot |
| `AniObject` | 3 | slot 第 1、action 第 2；未知 slot 不暫存 |
| `WalkObject` | 7 | slot 第 1、gate 第 5、action 第 6；負 action 改 4 |
| `WarpObject` | 7 | slot 第 1、gate 第 6、action 第 7；負 action 改 1 |
| `PlayMusic` | 此設計固定 1 | 最後一次字串覆寫先前值；不是任意音樂集合 |

前置 `wait` 等 72 個名稱是 stub；不能在前置寫「等怪死」之類迴圈。直接 `Q.*`、`Tutorial.*`、`lb.*` 不因正式環境存在就能在前置使用。前置 callback 發生錯誤後可以留下部分 collector，而外層繼續，不能依 native 返回認定宣告齊全。[S03、S05]

同一份建置規劃應同時輸出有限依賴宣告與正式動作。collector slot／model／action 的低 WORD、first-model-wins，與正式 DWORD slot、actor 身分低 BYTE 是不同約束；拒絕截斷碰撞與同 slot 不同 model。中途 `Q.DeleteAllObject` 清全 Q tree／level3；只能在確實持有整組時使用，也不提供所有資產工作 drain ACK。這些是有用的內容建置檢查，不是全功能都必須補齊全部素材的理由。[S05、S15]

## 5. 可選的多檔 module，與單檔的選擇

最小有限內容使用上述單檔就夠。若多個場景共享程式，已有原件支持正式 callback 中以全域大寫 `DoFile(MODULE_RESOURCE_PATH)` 載入一份自製 module；路徑由自己的發布 manifest 分配，不能冒稱已存在預設 `Field/*.mef` 入口。[S05]

module 頂層必須有限、無 yield，只建立本次 export／entry。caller 先清自己獨占的舊 export，要求 DoFile 的回值**等於數字 0**，核當次 export、version、entry；待 DoFile 返回，才直接用 Lua 呼入 entry。0／1 在 Lua 都 truthy，因此 `if DoFile(path)` 不合契約；module 的 `return table` 亦不是這個 API 的公開回值。需要 yield 的 entry 不能放在同 thread 的 pcall／xpcall 中假裝有 finally；可選的 outer／inner coroutine 監督方案見既有 supervisor，但不消除外部取消與 owner 關閉限制。[N19、S05、S25]

## 6. 發布輸入、完成輸出與綁定門檻

[delivery-manifest.template.json](delivery-manifest.template.json) 是 **Server／建置器資料**，Client 不會自行解析這份 JSON。它將以下事實分開保存：

1. 選定 profile、有效 Client hash、內容 release／hash、正式資源路徑及可見 provider。
2. 使用已有 selector 置換內容，或新增 SceneList row；合併索引的雙鍵、funcName、路徑唯一性及既有呼叫者影響。
3. 本次連線／Client epoch／field instance／generation、目標點的精確快照與唯一身分、Q 排他與預期控制條件。
4. 「已發布」「已送觸發」「收到 End 回報」「解除已排送」「實際效果已驗」「業務已提交」六個不同結果。

有限範本的 emit 是既有 End／003F 路徑，**沒有新增成功通知**。Server MEF coordinator 應記錄 run、內容版本、已使用鍵及 desired state，並保留結果未證狀態；內容可以減少逐步指令，不能靠不存在的 ACK 自動決定存檔。實際重進場景仍由 Server 所持的進度資料恢復相符點快照。[S16]

舊 A1 的 `quest=0, scene=32760, funcName=compat_point_once_a_v1` 在本份原 SceneList 的衝突為 0；這只是已發布研究提案，**不是原生保留區，也不是本次新內容已部署的鍵**。加 wait 或擴大功能後必須有新版本／選取政策；不要同一 Client 程序中熱換同鍵內容。實際合併索引及其他內容發布者仍需重新檢查。本文件新 profile 的 selector、時間、point 與 release 仍為 null／UNBOUND。[S16、R01]
