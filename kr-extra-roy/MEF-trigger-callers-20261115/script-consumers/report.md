# `.mef` 觸發分析：既有 Event 腳本的動態路徑 consumer 與 native 命名 callback

日期：2026-11-15（Asia/Taipei）。工作分支沿用 `extra/roy1`；本支線不修改 repository、原件或資源，不執行 Client／Lua。

## 一、結論與本次新增範圍

**這條支線仍未取得「既有正常事件腳本把 `.mef` 路徑交給 Lua 檔案 loader」的正向 caller。** 但已把兩個確實具有動態檔名能力、容易與腳本載入混淆的 consumer 接到 native 目標，並把主線新發現的三個 native 命名 callback 接回 qbase 原件 body：

| 原生事件可達的腳本操作 | 這次確認的 consumer | 對 `.mef` 觸發問題的影響 |
|---|---|---|
| `PlayCameraNoWait(name, ...)` 拼接 `Event/CameraWorks/` + name | `CameraWorks.LoadRel` → C closure → `54E990` → `7974D0` → `796EE0`，以 `cameraworks/keyframe` 查找相機資料 | 確認這條動態名稱是相機資源 consumer；沒有把拼好的字串交給已辨識的 Lua 檔案 loader |
| `LoadMap(name)` | `Q.LoadMap` → C closure → `563C40` → splitpath → `7C1E00` 的地形資源鏈 | 場景腳本可選本機地形；這個 `LoadMap` 名稱本身不能當作 MapList.TRIGGER／MEF 執行入口 |
| native 呼叫 `OnYesTriggered` | qbase proto 5，設定 `g_yesTriggered=TRUE` | 已接回旗標 setter，沒有檔名字串或函式呼叫指令 |
| native 呼叫 `OnEndTalk` | qbase proto 9，設定 `g_scenePlaying=FALSE` | 已接回對話／場景旗標 setter，沒有檔名字串或函式呼叫指令 |
| native 呼叫 `CheckConfirmMessage` | qbase proto 19，讀 yes/no 旗標並回傳數字 0／1 | 已接回結果判斷，不是後續腳本載入 callback |

以上是**選定資料流的正向用途證明**，不是全 Client 不可能經間接路徑載入 `.mef` 的證明，也不是執行期 trace。主線提供 native → 三個 callback 名稱的原生呼叫證據；本支線負責名稱 → 原件 closure → body。

## 二、舊成果復用及避免重做的界線

固定基準 main：`e66dadaa721671919cbbeb228ae3f26ad990c9e3`。來源 `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md` 的 Git blob 為 `e3422673ebd928d90f998b792cb513f10b28b69b`，整份 SHA-256 為 `dcb12f0ae59e048775841545c111c84379c11a350639d7f44a8c846d4ff5a0bc`。

該稿已包含以下成果，本報告直接復用，**不列為本輪新發現**：

1. Event.stp 的 1,840 個 `.seq` 與 3 個 `.lua` 已做完整內容檢查；文字檔未見 `load/loadstring/loadfile/dofile/require` 直接呼叫，bytecode 未見對應常數。這個範圍不能排除所有間接呼叫。
2. `boot.lua`、`Logic.lua`、`Coroutine.lua`、`ai.lua` 的原件已有完整 bytecode 解析結果，分別 1、1、13、8 個 prototypes；已知內容及 loader 陰性結論見原稿的「兩版啟動 Lua 的檔案讀取範圍」。**不能把這次工作目錄沒有那些散檔改寫成「Boot 尚未分析、因此現在阻塞」**。
3. UI/Table 啟動 Lua 及其三個明列 `DoFile` 目標已有前稿證據；不重掃作新成果。
4. `7C1E00` 的 `.fld` 路徑與 `716740` 本機資源查找已有原件核對；本輪補的是 qbase 的 `LoadMap` 至此 consumer 的橋接。

此外，`kr-extra-roy/MEF-entry-lifecycle-events-20261114/entry.md` 已把 SceneList `(15,2)` 接到 `scenario_tuto1_1.seq`，其 `LoadMap` 字串為 `Square03D.fld`；`MEF-parser-executor-storage-20261114/parser.md` 已證同一正式 Lua wrapper 的 `Q` namespace 建立（`560609/56060D/565E40`，slot `FE2774`）。這些完整路徑、Git blob、內容 hash 均固定在 `source-manifest.json`。

本支線起初重讀了既有 1,843 個 Event scripts，讀集保留在 `read-set.json`，其中的 corpus 陰性只屬舊結果的重複核對。收到舊稿範圍提醒後，研究轉向上表的具體動態 consumer 與 native callback，沒有把重複全讀充作新成果。讀集另外納入一份與正向資料流直接對應的 `.cam`，因此共有 1,844 個已讀 member 身分記錄；這不是全 STP 內容掃描。

## 三、原件、位址與重驗方式

| 原件 | 大小 | SHA-256 |
|---|---:|---|
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `06-Event.stp` | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

Lua/STPD 解析器復用既有 `MEF-parser-executor-storage-20261114/verify_evidence.py`，SHA-256 `8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56`。Lua 僅當資料讀取，header 為 `1b4c75615100010404040800`，instruction PC 全部從 0 起算。以下 native 位址均為此 BIN 的 VA，image base `0x400000`。

`selected-script-evidence.json` 保存三個選定 member 的 STPD block/實體 offset/原始與還原 hash、七個 qbase prototype 的全部短指令序列、root binding 與少量 `.seq` 原文。`native-script-consumers.json` 保存 14 個原始 native 視窗及 5 個字串；每個視窗有 VA、raw offset、長度、bytes、SHA-256。`native-script-consumers.asm` 是同一組視窗的 objdump 產物。五份 Ghidra 函式偽碼只作導航，其 Git blob／SHA 固定於 manifest，主證據使用 BIN bytes。

重驗：

```sh
python -B verify_evidence.py \
  --originals /workspace/scratch/b43c6175f310/project_sources \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

此驗證不產生 pycache、不執行 Lua／遊戲、不修改來源。它核對原件、三個選定 member、root closure 配對、七個 prototypes、Lua operands、14 個 native 視窗、14 個直接 call 的 rel32 operand、間接 binding bytes，以及實際讀集的身分 hash。讀集核對只驗證已讀資料版本，不重做 loader 搜尋。

## 四、正常場景腳本的實際檔名資料流

### 4.1 從已有正向事件入口取例

選定 `Event/Sequences/scenario_tuto1_1.seq`，不是從全部字串任選一份檔案。其對應 SceneList `(15,2)` 已由 entry.md 證明。STPD block `7133`，raw/stored offset `9865232`，長度 `1087`，解碼 SHA-256 `a4a308265b97fa9e048ebf4a30abb40f5fe8a7a3dc934ab911dd47fc3a7341f8`。必要原文為：

```lua
-- 原檔第 3 行
function scenario_tuto1_1()
-- 原檔第 9 行
    LoadMap("Square03D.fld")
-- 原檔第 26 行
    PlayCameraNoWait("scenario_tuto1_1.cam", 0, 0.00, 0.00, 0.00)
-- 原檔第 44 行
Register(scenario_tuto1_1)
```

上述片段是非連續必要摘錄。`Register` 傳的是函式值，並不是把 `scenario_tuto1_1` 當檔名再載入。qbase proto 75（chunk code offset `0x2DCC`）讀 `f_registerCoroutine` 與 `coroutine.create`，把參數函式交給 `coroutine.create`，再把結果交給 `f_registerCoroutine`。該 coroutine 建立／排程機制沿用既有 executor 證據，不因有間接 function value 就推導出任意路徑 loader。

### 4.2 qbase 相機名稱拼接有完整操作數

qbase member：block `7378`，stored offset `10618896`，長度 `11836`；還原／解碼 SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`。root PC 42 `CLOSURE`、PC 43 `SETGLOBAL` 將 proto 14 綁成 `PlayCameraNoWait`，不是僅憑字串常數推定。

proto 14 的 code offset `0xE70`，五個參數，選定 path dataflow 如下；完整 proto 包含前段座標處理，保存在 JSON。

| PC | 指令／操作數 | 資料流 |
|---:|---|---|
| 20 | `LOADK R8, K5` | `R8="Event/CameraWorks/"` |
| 21 | `MOVE R9, R0` | 取第一個參數 filename |
| 22 | `CONCAT R8, R8, R9` | 實際拼接相機目錄與 filename |
| 23–24 | `GETGLOBAL R9, CameraWorks`; `GETTABLE R9,R9,LoadRel` | 確定 callable 是 namespace 的 `LoadRel` field |
| 25–28 | 把 `R8,R5,R6,R7` 搬至 `R10..R13` | 路徑與三個座標值 |
| 29 | `CALL A=9,B=5,C=1` | 4 個參數、忽略結果 |
| 30–32 | 取得 `CameraWorks.Play`; `CALL A=9,B=1,C=1` | 接續播放 |

這份已知場景的完整目標是 `Event/CameraWorks/scenario_tuto1_1.cam`。

### 4.3 `CameraWorks.LoadRel` 的間接 native 目標已閉合

| 證據視窗 | 關鍵位置 | 已確認行為 |
|---|---|---|
| CAM01–CAM02 | `54E8C2`、`54E8D0`、`54EA2B`、`54EA37`、`54EA68` | 以正式 wrapper `FDF3C8` 建 `CameraWorks` table；wrapper 存 `FE1E24`，native owner 存 `FE1E28` |
| CAM03 | `54EBB8` | 寫入 `FE1E30=54E990`，因此不是未解析的函式指標 |
| CAM03 | `54EBF8`、`54EC09`、`54EC0E`、`54EC1B` | 以 `LoadRel` 字串及 C closure `54EEA0` 裝入 table field |
| CAM04–CAM05 | `54EEDA → 54F0A0` | Lua wrapper 進參數 marshaller |
| CAM05 | `54F0A6`、`54F0B5`、`54F17F..54F1BE`、`54F1EE` | 讀 slot `FE1E30`；由 Lua top 的第 4 個參數位置取路徑，傳三個 float；`call [ebp-8]` 目標為 `54E990` |
| CAM06–CAM07 | `54E99B`、`54E9C4`、`7974D2` | path 留在 EDX，經 `7974D0` 交 `796EE0`；讀取後才加上相對座標 |
| CAM08 | `796F22`、`796F30`、`796F55`、`796F62..796F73` | 原 path 交讀取流程；以字串 `cameraworks`、`keyframe` 呼叫節點查找 |

直接對應的原件 `.cam`（block `4857`，offset `5103632`，長度 `331`，SHA-256 `a76cbea2a79247144715a3887c00f4afccdfed3c3c1530bdc30c73a59756355f`）是 XML，root `cameraworks`，含 framepos 0、20 兩個 `keyframe`，每個有 `position` 與 `pivot`。

**已證的是相機 XML consumer 與其 path 來源。** 改副檔名本身不能把這條 native 鏈變成 Lua／MEF 執行器；本輪沒有主張檔案副檔名能決定解析器，也沒有主張任何未知內容的 `.mef` 不可能被某種 XML reader 打開。

### 4.4 `Q.LoadMap` 是另一個可變名稱 consumer

root PC 134→135 將 proto 60 綁成 `LoadMap`；proto code offset `0x2533`，完整 body 僅五個 words：

```text
GETGLOBAL R1, Q
GETTABLE  R1, R1, LoadMap
MOVE      R2, R0
CALL      A=1, B=2, C=1
RETURN    A=0, B=1
```

native 橋接依序是：

1. `5606E8 → 567500` 進 `Q` 初始化的 `LoadMap` binder；同一 `Q` namespace 的來源沿用前稿。
2. `567518` 寫入 `FE2808=563C40`；`567558` 推入 `LoadMap`；`567569` 以 `569760` 建 C closure。
3. `569796` 讀 `FE2808`，`56979C` 作參數傳入 `56A300`。`56A300` 取 Lua string pointer，`56A352: call [ebp+8]` 呼叫 `563C40`。
4. `563C80` 取 filename；`563D14` 取回同一參數；`563D37 → 8968E3` 分離檔名，`563D41/563D45` 把 basename buffer 交 `7C1E00`。
5. `7C1E00` 的後續 `.fld` 本機地形資源查找沿用 S00 既有原件證據。

因此這份 scene 的 `Square03D.fld` 是本機地形資料入口。該檔名不經本輪的 `MapList.TRIGGER` 查找，也沒有出現在這個 argument flow 的 Lua 檔案載入介面。這一結論只涵蓋這條 `Q.LoadMap` 路徑；其他 MapList consumer 由主線另查。

## 五、native 命名 callback 接回 qbase 原件

主線本輪找到 native 依名稱呼叫 `CheckConfirmMessage`、`OnYesTriggered`、`OnEndTalk`。本支線並未重新宣稱所有 native call-site 的完整性，而是核對這三個 global 在原版 qbase 中的綁定及完整 body。

| 名稱 | root 綁定 PC | prototype／code offset | 完整 body 的效果 |
|---|---:|---|---|
| `OnYesTriggered` | 24 `CLOSURE` → 25 `SETGLOBAL` | proto 5／`0xA7E` | `GETGLOBAL TRUE`；`SETGLOBAL g_yesTriggered`；`RETURN` |
| `OnEndTalk` | 32 → 33 | proto 9／`0xBC2` | `GETGLOBAL FALSE`；`SETGLOBAL g_scenePlaying`；`RETURN` |
| `CheckConfirmMessage` | 52 → 53 | proto 19／`0x11BE` | 以 GETGLOBAL、EQ、JMP、LOADK、RETURN 判斷 yes/no flag |

`CheckConfirmMessage` 的分支按 Lua 5.1 `EQ A=1` 的 skip-next 規則重建為：

```lua
-- 行為重建，非原始 Lua 文字檔
if g_noTriggered ~= FALSE then
    return 0
elseif g_yesTriggered ~= FALSE then
    return 1
end
return 0
```

不能把它簡寫成「有 yes 就一定 true」；no flag 的非 FALSE 分支優先回 0。三份完整 prototype 都沒有 `CALL`、`TAILCALL` 或 `CLOSURE`，也沒有外部檔名參數。這補閉了主線 native 命名呼叫 → qbase 旗標邏輯的界線，沒有增加一個隱藏檔案 loader。

## 六、已證、未證與 Server 需求

**已確認：**在固定原件 qbase 的上述 binding 未被其他程式改寫的前提下，選定 filename dataflow 通往相機 XML／地形資源，三個 callback body 只處理旗標與返回值。這些結論有完整選定 Lua operands 與 native 綁定 bytes 支持。

**仍未證：**其他未辨識 native 間接 loader、全域／table field 的執行期改寫、其他執行環境的動態 alias，是否能構成 `.mef` caller。本報告沒有逐一封閉整個 Lua VM 可變環境，故不以字串陰性作全程式不可能性結論。其他支線的 MapList.TRIGGER consumer、Synopsis、require/searchers 應與本報告合併評估，不能用此報告替它們結案。

| 類別 | 本支線留下的事項 |
|---|---|
| Client 待逆向 | `.mef` 內容／名稱真正進入既有 Lua 檔案 loader 的正向 caller 仍未由本支線找到；主線繼續檢查具體其他入口與間接目標，不需重掃本次已閉合的 camera/map consumer |
| Server 待開發 | 在不修改原版 Client 的目標下，Server 應依已證事件／場景選擇介面觸發封裝腳本，維護對應的任務／場景狀態；不能假定將任意 `.mef` filename 填入既有 scene／map 欄位即可讓它執行 |
| 跨功能待整合 | 接合已證的 native scene callback、場景協程、對話結果與 Server 狀態轉移；同時保留相機／地形名字與 script entry 的不同用途 |
| 待遊玩驗證 | 實際場景完成、yes/no callback 與 native 狀態回復順序，需要後續原版 Client 驗收；本輪僅提供靜態條件，不冒充已跑通 |

Server 內部業務規則可以由相容 Server 自行設計，不作 Client 分析的阻塞理由；但尚未找到的 Client `.mef` 觸發介面不能改寫為 Server 已有可用 wire 契約。

## 七、交付邊界

建議納入 repository 的檔案：`report.md`、`source-manifest.json`、`selected-script-evidence.json`、`native-script-consumers.json`、`native-script-consumers.asm`、`read-set.json`、`verify_evidence.py`。本地 `decoded/`、`compiled-prototypes-scratch.json`、`pseudocode-navigation-scratch.json` 為 scratch 全內容導航資料，不隨報告提交。

本報告的 `PASS` 僅表示上述固定原件與有界 evidence／operands 重驗成功，不代表 T01 FULL-PASS、RR ACCEPTED、整體 `.mef` 觸發問題已解決，或原版 Client 已完成遊玩驗收。
