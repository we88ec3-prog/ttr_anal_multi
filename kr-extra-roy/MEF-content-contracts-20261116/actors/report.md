# 正式 Q actor：可指定 slot、實際型別與刪除生命週期

日期：2026-11-16（Asia/Taipei）。狀態：**本輪選定的 Q actor producer／binding／consumer／清理鏈已閉合；MEF 替代 Server 世界生怪仍為 partial。**

本報告的直接成果是：內容可以預先指定 `Q.CreateObject` 的 slot，之後以同一個 slot 操作該 Q 物件；不必先從 Create 回值取得 ID。但這個 slot 屬於 Q 自己的索引，建立的具體物件一律是 `CEventActor`。已證流程尚未把它接成 Server 世界索引中的普通怪物，也沒有提供 spawn 成功／身分 ACK。

另一個會直接影響實作的結果是：正常註冊的 **`Q.DeleteObject` 原生目標只有 `ret 4`**。同 slot 再 Create 會保留舊索引，新配置 actor 在所查重複返回路徑沒有對應清理。因此內容不能用「DeleteObject 後重建同 slot」作為替換或回收策略。真正閉合到 actor destructor、heap free 與 tree clear 的接口是 `Q.DeleteAllObject`，作用範圍為整個 Q actor 索引。[A05–A23、A26–A27]

本輪沒有執行 Client、Lua、遊戲資源或測試封包。提出的新內容規範屬於開發建議；沒有把自訂 Lua／`.mef` 內容稱作官方格式。

## 1. 原件、範圍與引用方式

| 項目 | 固定身分／範圍 |
|---|---|
| 工作 parent | `88b22bcd750ea219bfc56580139396d0ee677644`，沿 `extra/roy1` |
| bulk 導航 main | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；使用固定 commit，不依賴可能落後的 `origin/main` |
| 主要原件 | `02-Tartaros.bin`，12,472,320 bytes，PE32 i386，image base `00400000` |
| 原件 SHA256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 本輪新閉合對象 | 正式 `Q.CreateObject`、`Q.MoveObject`、`Q.DeleteObject`、`Q.DeleteAllObject`、`Q.ShowObject`，以及其具體 actor／容器／清理下游 |
| 沿用而不重做 | `lb.CreateObjectEx` 無新 ID push、世界 `0007` duplicate skip、世界更新／移除的 typed ID 前置、`Q.GetLeaderPosN` 的位置語義、`Tutorial.IsCharacterAvailable` 的固定 `CCharStatus` 語義 |
| 同輪分工 | prepass／資源橋接見 [bridge/report.md](../bridge/report.md)；停止／Tutorial observer 見 [observers/report.md](../observers/report.md) |

下文 `[Axx]` 是 [native-windows.json](native-windows.json) 中同名原件記錄，包含 VA、exclusive end、raw offset、原始 hex、SHA256 與完整指令邊界；可讀組譯見 [native-windows.asm](native-windows.asm)。`[D01/D02/D_TYPE]` 是 CEventActor 的 vtable／COL／RTTI 原件。選定 binding、欄位及算術向量另見 [contracts.json](contracts.json)。

每個 bulk 函式的 `commit/path/git_blob_sha1/SHA256/size` 及沿用報告 pin 均在 [source-manifest.json](source-manifest.json)。bulk 反編譯只用於導航；本輪原生結論以 BIN 的 bytes、控制流與資料來源為依據。這是選定呼叫鏈的分析，不是全程式 API 不存在證明。

相關既有契約：

- [前輪 world identity 與封包採用限制](../../MEF-world-integration-20261115/identity/report.md)。
- [較早 actor／事件身分分析](../../MEF-entry-lifecycle-events-20261114/identity.md)。
- [Q 入口與生命週期](../../MEF-entry-lifecycle-events-20261114/lifecycle.md)。
- [parser／executor 與 binding 契約](../../MEF-parser-executor-storage-20261114/executor.md)。
- [正式 Q inventory、輸入與生命週期](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)。

## 2. 對新內容可承諾的能力

| 需求 | 本輪可採用的契約 | 使用上的界線 |
|---|---|---|
| 內容自行決定物件名稱 | 可用整數 slot 作 Q-local 索引鍵 | 正式索引用完整 DWORD；另有低 WORD／低 BYTE 投影，見第 4 節 |
| 建立可演出的 actor | `Q.CreateObject` 配置並設定 `CEventActor`，最後插入 Q 索引 | 資源與雙 VM 前置須滿足；未提供 Lua 可見的成功／ID 契約 |
| 操作既有 Q 物件 | `Q.MoveObject(slot,x,y,direction)` 以同 slot 查 Q 索引並設位置／方向 | miss 時直接返回；不能以此查普通世界 EntityId |
| 顯示或隱藏 | `Q.ShowObject(slot,0/1)` 寫 actor 的 render gate | 此操作不移除索引、不釋放 actor，也沒有停止 actor update 的契約 |
| 以同 slot 重建取代 | 所查 unique insertion 保留舊索引；新節點被丟棄 | 不能當 replace／upsert；重複建立的 actor 在該返回路徑沒有清理 |
| 刪除單一物件 | 正常 `Q.DeleteObject` binding 指向只有 `ret 4` 的函式 | 此固定接口沒有實作單一刪除 |
| 清空整組 Q 物件 | `Q.DeleteAllObject()` 遍歷 Q 索引，cleanup、delete actor，再清 tree | 不得據此推論 Lua coroutine、世界怪物或每一個外部持有者也同步結束 |
| 回報世界身分或死亡 | 本輪五個接口沒有補上這項能力 | 既有世界 ID 與同輪 observer 契約須另外滿足 |

[A01–A41、D01/D02/D_TYPE]

因此，對「劇情建立、移動、顯示／隱藏、全組清理」這類工作，已有具體且可由內容指定的物件參照方式；對「讓 MEF 接手 Server 生怪並參與權威世界、死亡與群清」這個目標，Q slot 陽性還不能直接通過整合驗收。

## 3. 是哪個 VM、namespace 與原生 receiver

### 3.1 正常註冊鏈

`48D76B..48D77A` 把正式 Lua wrapper `W=FDF3C8` 與 Q manager `M=FB73C0` 交給 `560600`。初始化進 `565E40`，建立 `Q` table，並在 `565E4B` 把原生 receiver 寫入 `FE2778`。本輪五個 registrar 都在這條正式初始化鏈上；不是僅從 API 名字猜測可用 namespace。[A01–A03、N_Q]

| Lua 名稱 | registrar | 目標指標儲存處 | 原生 target | Lua closure | marshaller |
|---|---:|---:|---:|---:|---:|
| `Q.CreateObject` | `566560` | `FE27A4` | `562EC0` | `568E00` | `56A710` |
| `Q.MoveObject` | `566600` | `FE27A8` | `5632D0` | `568E60` | `56AAA0` |
| `Q.DeleteObject` | `5666A0` | `FE27AC` | `476430` | `568EC0` | `56A430` |
| `Q.DeleteAllObject` | `567460` | `FE2804` | `563A70` | `569700` | 無參數，closure 直接呼叫目標 |
| `Q.ShowObject` | `567320` | `FE27FC` | `564900` | `569640` | `56A220` |

[A05–A10、A18–A21、A28–A29、A39–A41；名稱 bytes 見 `N_CreateObject` 等記錄]

這個結論固定在正常啟動的註冊狀態。Lua table 被後續腳本覆寫、原生指標重新綁定或不同 VM 的 prepass binding，不應被混入同一契約；prepass 和正式 Q 的不同用途由 [bridge/report.md](../bridge/report.md) 說明。

### 3.2 `CreateObject` 的九個參數

可供內容規範的順序為：

`Q.CreateObject(slot, model, x, y, direction, animation, show, avatar, item)`

`56A710` 從 Lua stack 的最後九格 `-1..-9` 讀參數，最後倒序構成原生九參數呼叫；本段沒有以參數總數拒絕錯誤呼叫。內容應固定九個參數，不依賴缺省補值或尾端多餘參數的效果。[A10]

| 序號 | 內容欄位 | Lua → native 轉換 | 已閉合的 consumer |
|---:|---|---|---|
| 1 | `slot` | number／可轉數值字串 → x87 `FISTP` signed DWORD | Q map key 用完整 DWORD；actor ID 用低 BYTE；prepass 查找用低 WORD |
| 2 | `model` | 同上 | signed range 選 type byte；model 低 WORD 與 type 組成 model key |
| 3 | `x` | number／數值字串 → double → float32 | actor `v+44` 的位置輸入 |
| 4 | `y` | 同上 | actor `v+44` 的位置輸入 |
| 5 | `direction` | number／數值字串 → `FISTP` signed DWORD | `v+58=4C8C30` 實際讀低 BYTE |
| 6 | `animation` | number／數值字串 → `FISTP` signed DWORD | actor `v+68`；另一參數固定 float `1.0` |
| 7 | `show` | number／數值字串 → `FISTP` signed DWORD | `563292` 寫 actor `+42C` |
| 8 | `avatar` | number／數值字串 → `FISTP` signed DWORD | 低 WORD 到 actor `+388`；signed `model<10` 且 avatar 為 0 時調為 1 |
| 9 | `item` | number／數值字串 → `FISTP` signed DWORD | 非零且對應 render owner 有效時，附件路徑使用低 WORD |

[A10–A13、A37]

這裡的數值型別是 Lua type 3，字串型別是 type 4；其他型別或無法取得數值時落到零值。整數轉換使用 x87 `FISTP`，本輪沒有建立當下 FPU rounding mode，因此不把它描述為「無條件朝零截斷」。內容可先限制為已驗證的有限整數，避免依賴小數、溢位或特殊浮點值的處理。`show` 亦應採數字 `0/1`；Lua boolean `true` 不是這個 marshaller 的數值 1。[A10、A29]

### 3.3 沒有新 actor ID push

`56AA2B` 以保存的 Q receiver 呼叫 native；`56AA30` 清 EAX 並返回，沒有把 native 結果寫到 Lua stack。外層 `568E42` 的 `EAX=1` 是 C closure 宣告的結果數，不是新 actor ID，也沒有出現將 actor pointer／ID 轉成新 Lua number／handle 的 producer。[A09–A10]

因此新內容應自己保存 slot，不把 `CreateObject` 的表面回值當 spawn 成功或 EntityId。本輪不經執行去認定 Lua 實際取到哪個既有 stack 值；只把「沒有新 ID push」作為可以由原件支持的接口界線。

## 4. 三種 slot／ID 投影及具體 actor 型別

### 4.1 相同輸入分別成為不同的鍵

| 用途 | 原件產生方式 | 位置與寬度 |
|---|---|---|
| 正式 Q 物件索引 | `563284` 讀完整第一參數，`563298` 傳為 node key | unsigned DWORD 比較的 Q tree key |
| prepass 依賴查找 | `56319C movzx edx,WORD [ebp+8]`，查 `M+70` | slot 低 16 bits |
| actor 自身 ID | `562F45` 讀 slot 低 BYTE，`562F4D` 放在臨時 WORD 高 BYTE，`562F82` 寫 actor `+04` | `((slot & 0xFF) << 8) | typeByte` |
| model 複合值 | `562F7F` 取 model 低 WORD，`562F88` 將 type 左移 24，經 `v+3C` 設入 | `(typeByte << 24) | (model & 0xFFFF)`，寫 actor `+88/+8C` |

[A11、A13、A14、A16]

Q tree 中的 key 既不是低 BYTE actor ID，也不是低 WORD prepass key。以下是**依指令算式產生的 SYN 向量，沒有執行遊戲**；model 固定為 1036，type byte 為 1：

| 內容 slot | 正式 Q key | prepass key | actor `+04` |
|---:|---:|---:|---:|
| 1 | 1 | 1 | `0101` |
| 257 | 257 | 257 | `0101` |
| 65537 | 65537 | 1 | `0101` |

這三個 slot 可以落在三個不同 Q key，卻產生相同 actor ID；其中 1 與 65537 又共用依賴查找 key。這只是投影與 alias 的算術結果，不是三個模型已成功載入或三個 actor 已在實機共存的證明。[A11；contracts.json 的 `slot_arithmetic_vectors`]

新內容規範可自行限制 slot 在 `0..255` 且不重複，以避開這兩種截窄 alias。此範圍是保守的內容／Server 設計政策，**不是原生 Q map 的 256 個上限，也不是合法 typed world ID 的認證**；slot 0、保留值、資源與業務語義仍須由所選內容規範決定。

### 4.2 type byte 由 model 的 signed 範圍決定

| 原生 signed model 比較 | type byte |
|---|---:|
| `<10` | 0 |
| `10..9999` | 1 |
| `10000..10999` | 6 |
| `11000..20999` | 7 |
| `>=21000` | 呼叫 `6EDB60` diagnostic 後使用 0 |

[A11 的 `562EFA/562F05/562F14/562F23`]

負數同樣會符合 signed `<10`，因此這個分支表不能當「所有列出數值都是有效模型」的證明。`>=21000` 的 diagnostic 分支也不等於資源載入成功。前輪 `lb.CreateObjectEx` 的型別分界不可直接搬來套用這個 Q target。

### 4.3 所有分支都建立 `CEventActor`

`562F48` 配置 `0x438` bytes，`562F68` 一律進 `4D0B80`。constructor 在 `4D0BB8` 設 primary vptr `C0C824`，在 `4D0BBE` 設 actor `+F0` 的 secondary vptr `C0C8AC`；兩個 COL 的 type descriptor 都是 `.?AVCEventActor@@`。model range 並未在這裡改成 CMonster／NPC 的 constructor。[A11–A12、D01/D02/D_TYPE]

| 本輪用到的 CEventActor virtual slot | 實際 target | 契約用途 |
|---|---:|---|
| `+00` | `4D0CA0` | deleting destructor |
| `+14` | `4C8360` | native cleanup |
| `+20` | `4D0F80` | actor update |
| `+28` | `4D0FC0` | render gate |
| `+3C` | `4C6FB0` | model key 寫入 |
| `+44` | `4C8B90` | position setter |
| `+58` | `4C8C30` | direction setter，讀低 BYTE |
| `+68` | `4C8DA0` | animation 呼叫入口 |

[D01；本輪對位原件見 A13、A23–A25、A31、A33、A37；位置完整 setter 沿用前輪 identity 原件]

因此，actor `+04` 的 low byte 恰為 1，或 model 是已知怪物模型，都不能把此物件直接當成世界 CMonster。需要同時確認具體型別、索引擁有者、後續 consumer 與網路身分契約。

## 5. Q 私有索引與可用的 slot 操作

### 5.1 正式 publish 的 receiver 是 `M+18`

Q manager 建構片段 `560197..560237` 自行配置 `0x18` bytes 的 sentinel，將其寫到 `FB73DC`，設自連結／nil 狀態，清 count `FB73E0`。正常 M 下的索引位置如下：[A04]

| 對象 | receiver | sentinel pointer | count |
|---|---:|---:|---:|
| Q actor tree | `M+18 = FB73D8` | `M+1C = FB73DC` | `M+20 = FB73E0` |
| 既有 world actor tree | `FAB138` | `FAB13C` | 依前輪 world map 契約 |

Create 完成設定後，`56328B` 將 receiver 加 `18`；`563298/56329C` 分別放入 slot DWORD 與 actor pointer；`5632A0→57EF20` 配置節點，`5632AB→82F200` 進 unique insertion。node `+0C` 是 key，`+10` 是 actor pointer。[A11、A14–A15]

對照已選定的 `lb.SetActorAvatar` consumer，`4A0BEE` 明確把 `FAB138` 放入 ECX 再查找；本輪 `Q.MoveObject`、`Q.ShowObject` 則使用 `M+18`。世界 ID 與 Q slot 的整數值相等，不會讓兩個 receiver 變成同一棵 tree。[A17、A30、A35；前輪 world identity]

**在完整 `562EC0..5632C5` 的已選定直接呼叫與 publish 路徑中，正向證實的是 Q tree 插入；沒有 `4DFF30` 世界 registrar 的直接呼叫。** 本報告沒有窮舉所有資源函式、base constructor、引擎 virtual target 或其他未選入口，因此不將這個結果寫成「全程式絕無另一條世界註冊橋」。目前可採用的契約是 Q-local actor，不能把未證實的隱含世界註冊當成開發前提。[A11、A14–A17、A35；前輪 `4DFF30` producer 契約]

### 5.2 `MoveObject` 以完整 slot 找同一個 actor

`Q.MoveObject(slot,x,y,direction)` 的 `56AAA0` 讀最後四個參數；slot／direction 走整數轉換，x／y 走 float32。native `5632D0` 在 `5632E3` 取 `M+18`，`5632E9→82EF00` 以完整 DWORD slot 查找；hit 後讀 node `+10`，呼叫 actor `v+44`、`v+58`，miss 則返回。[A16–A17、A39–A41]

這閉合了一條內容可用的身分鏈：**內容定義 slot → Create 存 key／pointer → Move 查同 key → 操作對應 CEventActor**。它解決的是 Q-local 物件參照；沒有以 actor ID、model ID 或記憶體 pointer 替代 slot。

### 5.3 正式 Create 亦會使用 prepass 依賴

`56319C` 將 slot 截成 WORD，`5631A0` 讀 `M+70`，`5631B2→826280` 查 prepass record。命中後取 record `+8` 的 action set，從節點 `+0C` 讀 WORD action；再對模型資源的 `+D4` tree 查找與呼叫對應 action virtual method。[A11]

這條 consumer 是原生存在的，但 record 的 producer 規則、first Create 決定 model、重複 slot 不換 model、action 0 的分支差異、實際 CMotion／animation request 下游，均由同輪 [bridge/report.md](../bridge/report.md) 完整閉合。本報告不重複擴大為「只要正式 Create 有 model 參數，就保證 prepass 已替它備齊依賴」。

## 6. 重複 slot：舊索引留下，新 actor 不成為替換

`57EF20` 建立 node 時，會複製 key 與 actor pointer。`82F200` 對同 key 的 duplicate 分支在 `82F2AE→89120C` **只釋放新 node**；回傳的是原有 iterator，並把插入成功 flag 設為 false。這條 helper 沒有取出新 node 的 actor pointer 來呼叫 destructor。[A14–A15]

`Q.CreateObject` 在 `5632AB` 呼叫插入後立刻進 epilogue，沒有檢查 iterator／成功 flag，沒有重試新 key，也沒有沿 duplicate 分支 cleanup 新配置的 actor。[A11]

| 步驟 | Q tree 中 slot K | 新配置的 actor B |
|---|---|---|
| 原先已有 actor A | `K → A` | 尚未建立 |
| 再執行 Create K | 還是 `K → A` | 已經配置、建構與設定 |
| unique insertion 判定 duplicate | 保留原 node／pointer | 新 tree node 被釋放，B 沒有成為該 key 的 payload |
| `MoveObject(K,…)`／`ShowObject(K,…)` | consumer 命中 A | 不會因同 slot 而改用 B |
| 後來 `DeleteAllObject()` | traversal 走 Q tree 中的 A | 不能假定此 traversal 也能找到未被插入的 B |

[A11、A14–A17、A22、A30]

這是對指標和控制流的靜態推導，沒有把一次實機洩漏大小、所有其他 owner 或永遠無法回收當成已知。足以支持的開發限制是：**同一 Q tree 生命週期內禁止重複 Create 相同 slot；不要把 unique insertion 誤當成 upsert。**

## 7. 個別刪除、隱藏與整組清除的差異

### 7.1 `Q.DeleteObject(slot)` 在正常 binding 下沒有刪除 body

`5666A0` 註冊 `FE27AC=476430`；closure `568EC0` 經 `56A430` 轉最後一個參數為整數，再呼叫已保存的 target。原件 `476430..476433` 是完整三 bytes：

```text
VA 00476430  raw 00075830  C2 04 00  ret 4
```

[A06、A18–A20]

這個函式沒有 Q tree lookup、actor cleanup、heap free 或 node erase。它不是「等待未查的下游才刪除」：所註冊目標本身就直接返回。因此「DeleteObject(K) → CreateObject(K,…)」仍會遇到第 6 節的 duplicate 行為。

界線限定為這個原件、正常初始化與固定 target；並未宣稱所有其他 namespace、Lua 自行包裝、後續重綁或未查原生入口都沒有個別刪除能力。

### 7.2 `ShowObject` 是 render gate

`56A220` 把最後兩個參數轉整數，native `564900` 在 `564911/564917` 查 `M+18`。命中後 `56492F` 只寫 node actor 的 `+42C`；miss 返回。因 marshaller 只接受 number／數值字串，內容應使用 `0/1`，不要以 Lua boolean 當同一 ABI。[A28–A30]

renderer `4D0FC0` 檢查 `+42C`：零時回零，非零跳入 `4C88F0`。Q render traversal `5616F0..561753` 逐 node 呼叫 actor `v+28`，所以這個欄位確實有顯示 consumer。[A31–A32]

另一方面，Q update traversal `5615E0..56163E` 仍按 node `+10` 呼叫 `v+20`；CEventActor `4D0F80` 進 `4C8580`、`4D0DD0`，這段未檢查 `+42C`。所以「隱藏」不能當成物件已停止 update、已刪除、slot 可重用或 Lua task 已取消的證據。[A33–A34]

移動旗標及 `Q.IsAllObjectsStopped` 的完整 writer／tick／getter 契約見 [observers/report.md](../observers/report.md)。本輪不因名字含 Stopped 就把其結果定義為死亡或群清。

### 7.3 `DeleteAllObject` 確實進入 cleanup／delete／tree clear

closure `569700` 在 `569736` 讀 `FE2778`，`56973C` 呼叫 `FE2804=563A70`。native 從 `[M+1C]` 的 sentinel 遍歷 Q tree，對非 null 的 node `+10` actor 執行：[A07、A21–A22]

1. `563ABB/563AC0` 呼叫 actor `v+14`。CEventActor 的 target 是 `4C8360`，處理模型／effect owner 的 native cleanup。
2. `563AC6` push 1，`563ACA` 呼叫 `v+00`。target `4D0CA0` 呼叫 base destructor `4C7B90`，並因 delete bit 成立，在 `4D0CC2→89120C` 釋放 actor 本體。
3. 完成 actor traversal 後，`563B1A` 取 `M+18`，`563B1D→823850` 清除 tree。其 `73EBA0` helper 遞迴釋放 node，最後恢復 sentinel 自連結與 count 0。

[A22–A27、D01]

本輪也包含 `4C7B90` 的 destructor body，可核 native 容器、FSM states 與相關 release 路徑；對進一步動態引擎目標仍保留所選範圍，不主張所有資源後端行為已窮盡。`563A70` 後段另安排 native 資源 job、等待 handle、清 `M+60`；這不是 Lua coroutine 完成 ACK，亦沒有由靜態原件推導延遲保證。[A22、A24–A25]

現有 Stop 路徑的片段 `562687..5626A2` 先 RestoreMap，`562694→563A70` 再清 Q objects，後面進 camera override cleanup。這提供了 **Stop 的某條既有路徑會呼叫實際清除** 的正向來源；不能把所有 `.mef` 結束、Lua return、Q 尾端或換圖一概視為已走過同一路徑。[A38；既有 lifecycle 報告]

## 8. 對 MEF 串接的實際影響

### 8.1 已可開始設計的內容部分

可以先把「可演出的 Q-local 物件」列成內容 manifest：每個物件有固定 slot、model、依賴 action、初始位置／方向／顯示、avatar／item；同一次 Q tree 生命週期只 Create 一次。後續動作以相同 slot 發給 Move／Show；若某物件演出結束，可隱藏並保留 slot，待整組清理後再開始下一次生命週期。[A10–A17、A22、A28–A34]

這是根據已證 ABI 與容器行為提出的內容設計，並不保證隱藏物件的 update 成本為零，也不把它當成單一資源釋放。正式執行時機、prepass 資源、Q 啟停與 task scheduler，仍須與同輪 runner／bridge 契約共同使用。

### 8.2 世界生怪替代尚未由此完成

Q slot 能讓 Lua 找到自己建立的 CEventActor，是實質的身分能力；但 Server 的世界運作仍需要有唯一且可配對的 typed EntityId、實際世界索引、相容的 concrete class、可確認的建立／失敗結果，以及死亡／移除／群清的狀態來源。這些不能由 Q slot 算式自動推出。[A11–A17、A35；前輪 world identity；同輪 observers]

因此後續整合應分清要下放的是「場景演出物件」還是「可戰鬥世界 actor」。如果目標是後者，驗收必須在停用該目標的 Server spawn 操作後，仍能證明 Client 內容建立了可對帳的正確世界物件，並完成更新、移除與跨場次一致性。保留原 Server 生怪只能作未替代的比較基準，不能把它計入 MEF 已接手生怪的成功條件。

## 9. Server 開發需求、仍未知與驗證界線

### Server 開發需求

1. **定義內容物件身分表。** 分開記錄內容 instance／generation、Q slot、model／type 與 world EntityId；不得以三者數值相等當作同一身分。若採 `0..255` slot 政策，明示其用途是避免投影 alias，並校驗所有 slot 唯一。[第 4–5 節]
2. **在送出內容前檢查固定 ABI 與依賴。** Create 恰九參數、Move 恰四參數、Show 恰兩參數，數字欄位限制為所選有效範圍；show 用 0/1。prepass 的 first Create、model、action 記錄須能滿足正式 consumer，不能靠正式階段臨時改 model 補救。[第 3 節；bridge]
3. **禁止同一生命週期重複 Create slot。** 正常 DeleteObject 不會釋放 slot；Show 不會釋放 slot。重試／重送要用內容 instance 的明確狀態與去重政策處理，不得把相同 Create 再送一次當作可靠的重試。[第 6–7 節]
4. **規劃全組清理與取消。** 對這組已證接口，實際物件回收是 DeleteAllObject；須和演出排程、取消、重新進入、換圖、舊 generation 失效的規則配合。actor 已清除不能作 Lua task 已結束的唯一條件。[第 7 節；既有 lifecycle]
5. **若要接手世界生怪，補上可驗收的世界身分橋。** Server 要能配對「哪個 instance、哪個 actor、是否建立成功、世界索引與型別是否一致」。本輪沒有證實可直接提供它的 Q API，不創造新的現有 opcode／handle getter，也不把 C closure 的結果數當 ACK。[第 3.3、5、8.2 節]
6. **狀態與群清須採其已證資料來源。** render gate、Q movement 停止、Tutorial 狀態及 world death／remove 是不同 consumer 契約；Server 規則要明確選用並去重，不能把畫面消失當作死亡或權威群清。[第 7 節；observers；前輪 world identity]

### 尚未閉合的 Client 能力

- 在本輪選定五個接口之外，是否另有可將 Q actor 註冊／轉交世界索引、返回一般 actor ID／generation 或提供可配對 spawn ACK 的入口，仍未完成；這是有界未知，不是全程式陰性。
- Q actor 的全部外部持有者、duplicate 新 actor 是否存在別處可回收路徑、所有 constructor／資源 virtual callee 的世界索引副作用，沒有做全圖窮舉；目前不可依賴它們作整合前提。
- 世界怪物的生命值、普通死亡到 Lua、可靠 group membership／清組 observer，不能由本輪 Q slot／Show／DeleteAll 單獨補成。已選新 observer 的肯定與否定結果以同輪報告為準。

### 尚未執行的整合驗證

本輪沒有實機建立、重載、多人同步、封包測試或長時間回收測試。PASS 的意思是原件 bytes、ABI、選定控制流、table 與 Git 來源身分一致；不是官方 MEF 格式驗證、runtime 成功率驗證或完整 Server spawn 替代測試。

## 10. 唯讀重現與結果

交付檔為本報告、[native-windows.json](native-windows.json)、[native-windows.asm](native-windows.asm)、[contracts.json](contracts.json)、[source-manifest.json](source-manifest.json)、[verify_evidence.py](verify_evidence.py)、[verification-result.json](verification-result.json)。只保留選定原件範圍與證據；未附整份 BIN 或新解出的原遊戲 member。

在具有固定 Git objects、Python 3 與 GNU objdump 的環境，以原件重跑：

```bash
python -B verify_evidence.py --bin /path/to/02-Tartaros.bin --repo /path/to/ttr_anal_multi
```

若證據另置，可加 `--evidence-dir /path/to/actors`。verifier 對原件 SHA256、PE raw mapping、每段 hex／SHA256、連續解碼及完整最後指令、五組 registrar、兩個 RTTI-backed vtable、選定 call／欄位、三個 slot 與八個 model 算術向量、60 個固定來源 pin 做核對。Git 使用 `GIT_NO_LAZY_FETCH=1`、`GIT_OPTIONAL_LOCKS=0`、`GIT_TERMINAL_PROMPT=0`、`GIT_NO_REPLACE_OBJECTS=1` 與停用 origin promisor 的讀取，不 fetch、不 checkout、不改索引。程式只把結果輸出 stdout。[verify_evidence.py]

本次結果為 **PASS**：52 個原件記錄，其中 41 個 code windows；合計 7,511 bytes、2,345 條指令；54 項選定檢查；5 個 binding、2 個 vtable、60 個 source pins 及 60 份實際 source contents；3 個 slot 算術向量、8 個 model 分類向量。Client／Lua 執行旗標均為 false。完整數字與逐項檢查以 [verification-result.json](verification-result.json) 為準。
