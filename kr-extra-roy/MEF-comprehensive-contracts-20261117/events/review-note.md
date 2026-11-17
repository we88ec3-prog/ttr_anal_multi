# ABI 與事件觀察的交叉審查

審查日期：2026-11-17。審查者：事件分題。只讀同輪 ABI 的四份指定檔案，並與本分題原件核對的 16 個 getter／對話方法比對；沒有修改 ABI 原稿、重跑全量原件審計或執行 Client／Lua／Server。

## 結論

**指定範圍內沒有發現需要阻擋整合的錯誤。** 這是文件／機讀契約／預驗程式的交叉審查，不代替 ABI 原件 verifier，也不宣告全部 native 功能或動態重綁已驗證。

| 核對項目 | 結果 |
|---|---|
| 121 正常名稱、17 新 number、16 query、104 無新 binding 值 | 與事件表完全相符；第 17 項正確單列 lb.DoFile |
| 16 個 query 的集合、native VA、新回值型別 | 全部一致，均為 number |
| 44 個不讀使用者參數的名稱 | JSON 統計與報告一致 |
| Markdown 121 列與 JSON 簽章 | 名稱集合、數目、左至右參數種類全部一致 |
| 33 marshaller 的整數／float input index | 與各自 argument_kinds 在 suffix window 的位置全部一致 |
| Lua truthiness 例外 | 只有 ScenarioTalkTable.open 第三參數；0 為真、false 為假，與事件分題的 A8 manual gate 一致 |
| 預驗器型別及回值限制 | bool 不被 Python int 子類關係意外放行；無 producer 不能 read_number；不把任意結果當通用 ACK |
| 對話 closure／marshaller 分層 | ABI 正確為 6BDEB0／6BE090；事件原稿已依交叉審查修正用詞 |

一般數值參數收到 boolean 時走數值轉接的 0 分支，與對話最後一格的 Lua truthiness 規則不同；新回傳的 number 0 又仍屬 Lua true。報告已分清這三個位置的規則，沒有用單一「bool 轉換」混寫。

IsCharacterAvailable／Book 的形式參數不代表可選任意角色／書本；IsScenarioEnded 僅在已證 Tutorial owner 契約下使用；GetObjectCount 不能當可靠 count。ABI 原稿與事件來源分析一致。

## 保留的預驗邊界

`validate_calls.py` 有意只給 ABI_PASS_ONLY。它不判斷 Q.GetLeaderPosN selector 必須 0/1/2、32 個 Tutorial 控制槽各自的保留用途、receiver type、同一 run／owner 或無 leader 時的座標 0 歧義。這些屬 typed 語意與事件契約的下一層；現有 remaining_checks 與 deployment_ready=false 已避免把 ABI 通過誤寫成可部署。後續整合內容工具時應引用 observation-catalog.json，而不是移除這個界線。

本次參數順序核對以四份指定檔案中的已核原件 index 紀錄為依據；沒有冒稱重新逐一反編譯 121 個 native 功能本體。對話 truthiness 與 getter 型別來源另由事件分題的原件窗口支援。

## 審查時的檔案版本

以下 SHA-256 固定本次讀取內容；後續改稿需重核受影響部分。

| ABI 檔案 | SHA-256 |
|---|---|
| `report.md` | `c208093fe5d5c9dc7bf8aaef021204a9a4bface1565e0df2171d80fc5fbf3877` |
| `ABI-CATALOG.md` | `94fd989a82d835b57ed379d66fc10ac92cdc210b7297b162aa8bf0d419805ed8` |
| `abi-contracts.json` | `a09195efd91d50390088fd10cfc46b2ae806dae0c968643ff50e17b599f19916` |
| `validate_calls.py` | `8eb55cb8cf49140768edbdb7b1e1aa5a7d1c82500eb9e0d3db2b31d2472514df` |
