# 下一階段分析：先交可實作切片，僅追尚缺的正向連接

## 建議第一優先：指定普通轉場的資料綁定與排程規格

本輪已分清005F、0012、S2C000A、0027/0048、loading0023/24、ready0014與Q等待的native效果。下一輪不要重掃這些getter／handler；應選定一個已有資料來源的普通轉場，把「精確實體與點」接到既有規格。

可先以既有W2的Case103／Field19／Map191→192作資料導航，**不是預設它已可立即部署**。先讀W2/W3原圖表與BND證據，取得其精確來源carrier／blob，補真正portal key、出生資料、角色關聯record和必要前置。MapList／CaseList的字面關係本輪已固定；重複列相同ID不是新成果。

交付終點：一份具來源的normal transition binding與偏序規格，逐項說明何時清points、是否重建world actor、何時S2C000A及0014、A1在哪個phase可用，以及沒有真實ACK時Server如何記錄「未驗證」。未知資料保持未綁定，不能用合成座標當官服值。

## 第二優先：已知 world ID 的本地操作，而不是再猜本地生怪ID

先以Server已建立且識別可靠的world actor作一個內容切片，例如已證的外觀／附件操作。這可避開CreateObjectEx沒有ID回值的缺口，但仍須閉合具體模型、參數、引用與退出。

受限的Tutorial.DeleteObject另成一題：只有lowbyte0的known-worldID投影，且須先證明不受controller持有或有合法解綁。不要用它作普通怪物刪除。網路001A會清整槽的影響，應在前述轉場規格處理倖存actor重綁。

交付終點：同一worldID與物件型別從建立到操作、清理和Server下一步均一致。不得以Qslot或pointkey代用。

## 第三優先：普通 world 結果到 Lua 的缺邊

目前有「000C→state3／native顯示」與「001A→world erase」；沒有普通 `(EntityId,lifetime,reason/group)` 結果到Lua的完整契約。

下一次應從實際producer分流出發，限定一個問題：
- 能否在普通controller/context找到保存該worldID的事件容器，並追到已註冊getter真正push值？
- 或能否找到原生callback caller攜帶相同身分，且有合法普通入口和完成／取消政策？

只有caller、receiver、型別與payload有正向來源才擴展。已排除的OnYes普通page、教學004C、Q停步、Book/Prolog、圖片回收，不因又搜到字串就重開。B的首次入口也不與這題混成「只要能tick就算觀察到了死亡」。

交付終點：完整有身分的正向鏈；或限定的候選讀集、真正阻塞地址／型別與解除證據。不能用「Server發自訂opcode」跳過未修改Client不會處理的部分。

## 第四優先：有界地追轉場 world clear caller

[read-set.json](read-set.json)已列`4DFE90`的11個E8候選；不是11條都已語意審核。只選與第一優先指定流程相關的caller，回到完整所屬函式，確認它在何種packet／phase清world、是否先處理controller與其他引用。

這樣可補「舊actor能否保留」的真正consumer條件，而不用再次全程式掃描erase函式。sameMap的0012不能當作代替這項證據的reset。

## 效率與完成標準

把每條線保存成「已證native效果、具體缺邊、Server需求、資料綁定、實機待驗」五個欄位。舊證據用固定commit/path/blob引用，原件相同不反覆重做全量反編譯與121介面盤點。驗證器只重驗變更與必要連接，完整整合時再回歸。

完成一個切片的衡量是：能否指出一個實際使用者效果、同一身分／場景、正確的開始與結束，以及誰仍負責權威結果。指令數、檔案數、API名稱數不是功能完成率。

原生MEF首次載入／grammar保持獨立研究；沒有新的第一手caller資料時，不要讓它阻擋A1、普通轉場Server規格及上述已證本地能力整合。
