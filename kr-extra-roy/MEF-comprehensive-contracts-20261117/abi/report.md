# 正常腳本綁定的參數、回傳值與內容預驗契約

## 1. 本輪閉合的問題

以 KR BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、分支基準 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51` 為準，本輪逐項核對已知 **121 個正常綁定的 closure、33 個實際參數轉接函式**，並把參數個數、左右順序、Lua 型別轉換、結果寫入整理成可用於內容工具的完整表。

這不是重新把前輪 122 registrar／223 closure sink 盤點當成新功能；已知名稱與 native 作用沿固定來源復用。新增的是每個名稱到實際 ABI 的閉合，以及能直接阻擋錯誤內容的只讀預驗器。原件證據含 159 個完整函式、21,204 bytes、7,074 條已解碼指令；它們是此題的讀集，**不是全程式覆蓋率或 T01 FULL-PASS**。

| 有界結果 | 數量 | 精確意義 |
|---|---:|---|
| 正常 namespace 名稱 | 121 | 與固定 registrar 名稱集合一致，不包括語言庫、prepass 或全域 loader |
| 實際參數轉接函式 | 33 | 含共用模板與特定轉接，不是33種遊戲功能 |
| 不讀使用者參數的綁定 | 44 | 作者仍應傳空參數列；附加參數不構成功能 |
| 明確建立新 Lua number 的綁定 | 17 | 16個觀察查詢，加上有歧義的 lb.DoFile status |
| 未由 binding 建立新值 | 104 | EAX=1是結果槽數；不可推論成功／新ID／完成 |

完整每名稱資料見 [ABI-CATALOG.md](ABI-CATALOG.md)、[abi-contracts.json](abi-contracts.json)；每個轉接函式的整數 input index、float tag reader、FISTP／FSTP、字串轉換和輸出 top 變更，都有原始 VA。

## 2. 所有輸入按 stack 尾端取值，沒有一般參數數量防線

正常 closure 從固定 native slot、receiver slot取目前指標，將 Lua state交給轉接函式；轉接器由最後 N 個 TValue 取參數，不以名稱上的 self／某種自動 default 補足欄位。`0x6F50F0` 的普通負 index 路徑直接計算 `L.top + index*16`，並沒有正 index 路徑那種 top 上界檢查。

例：`Tutorial.SetCheckPointStatus` 經 `4ACBF0` 讀 `-1,-2,-3`，推 native 的順序仍是 `(key,category,status)`；`Q.CreateObject` 經 `56A710` 讀九格，其中第3、4格為 float，其餘為整數。`CameraWorks.LoadRel` 是 `(string,float,float,float)`。完整表不依反編譯錯誤 float 暫存型別推斷，而是以原始 FISTP／FSTP 與 push順序核對。

**內容政策：使用精確個數、dot-call與明確值。** 多加尾端引數會移動整個取值窗口；少引數不能視為補 nil／補0。原生沒有檢查不代表作者可以安全少傳。Colon附加前端 self有時未影響 suffix，但本輪不把這種偶然容忍當成獨立API。

此規則是為相容內容制定的較嚴格預驗政策，不聲稱原Client會主動拒絕所有不合政策的呼叫。

## 3. 數值開關與 Lua 布林有兩套不同規則

### 3.1 一般整數／浮點轉接

整數模板例如 `4ACB70`／`56A430`，先檢查 TValue type3數字；type4字串會經 `6F7760` 嘗試完整數值解析。數字經 x87 `FISTP DWORD` 轉為有符號整數，其他型別或解析失敗走0分支。浮點模板同樣限定數字／可解析字串，但以 `FSTP DWORD` 傳單精度。

`true`與`false`都是 Lua boolean type1，**兩者在這些數值模板都落到0**。例如 `Tutorial.SetKeymapEnabled(true)`不能表達已證的數值1分支；`Q.ShowObject(slot,true)`不能據此要求顯示；圖片 holdForever也必須按其數值契約處理。

FISTP的非整數捨入受當時FPU控制狀態影響。新內容工具應要求有限、已是整數且落在 signed32 範圍的值，不依賴隱式捨入、NaN、溢位或數字字串。packed bit-field也須先按實際消費者與signed表示確認，不能把任意正的32位無符號值直接當可精確轉換的整數。

### 3.2 對話 open 的第三參數是明確例外

`ScenarioTalkTable.open` 的 `6BE090` 在 `6BE0AF..6BE0D1` 直接讀最後 TValue 的 tag/value：只有nil或boolean false為0；其餘為1。前兩參數仍走整數轉換。

| 傳入值（該格確實存在） | 整數開關收到 | open第三參數收到 |
|---|---:|---:|
| `0` | 0 | 1 |
| `1` | 1 | 1 |
| `false` | 0 | 0 |
| `true` | 0 | 1 |
| 字串 `"0"` | 0 | 1 |
| 空字串 | 0 | 1 |
| `nil` | 0 | 0 |

因此不能替所有功能套一個「bool通用轉換」。對話自動模式應傳明確 `false`；數值開關則用來源已證的整數0／1。表中的nil指明確佔有一格的nil，**不包含缺少引數**。

## 4. 字串參數與資源存在是兩個檢查

字串模板接受type4；type3可由 `6FB5D0` 以 `%.14g` 轉成字串並更新原TValue。其他型別產生NULL。這條轉換鏈不是檔案存在檢查，也不提供合法路徑或相依資源。

新內容預驗採非空、不含NUL的明確字串，避免錯把number格式化的結果當模型／相機／音效路徑。實際資源是否由package選中、版本和hash是否符合、owner是否初始化，仍交由[資源預驗](../resources/report.md)與既有loader契約處理。不可由字串型別PASS提升為可播放。

## 5. 回傳1不等於成功，number也不等於可當boolean

121個正常closure都以EAX=1結束。這是Lua C callback的結果個數。只有17個binding／marshaller另外在當前Lua stack寫入type3、數值並把top加16；其餘104個沒有在這一層建立新結果。

Lua call engine的 `6FE360 → 6FE375/37A/37D → 6FE4C0` 結果搬移契約已在[前輪executor](../../MEF-parser-executor-storage-20261114/executor.md)核實，直接復用。未push時不能把既有stack結果當native成功、物件數、world EntityId或完成ACK；本輪也不為所有native副作用猜一個固定的舊slot值。

16個觀察query是本地時間、Q/Tutorial執行狀態、教學狀態／進度、固定角色或領隊條件、領隊位置分量、相機／序章／書本狀態。它們都回**number**而非Lua boolean；0在Lua仍為true。應按個別query契約比較數值，不能寫泛用 `if query() then 成功`。它們各自的typed owner、writer和誤判邊界見[事件觀察分析](../events/report.md)。

第17個是 `lb.DoFile`：`4A2A70`確實把native結果推成number，但原件 `4A1230`資源開啟失敗回0，`6F4C20`執行成功亦回0。**0無法單獨證明檔案已載入。** 大寫全域`DoFile`另有自己的current-state與0/1契約，並不在此121名稱表；既有[模組入口規格](../../MEF-end-to-end-20261116/entry/report.md)要求當次export/version與正確phase，不能交換同名loader。

## 6. 名稱／簽章存在但不能充當任意能力

四個已確認stub與不可靠count query保留原狀：`Q.DeleteObject`、`Q.BalloonTalk`、`Tutorial.InsertObject`、`lb.PrintCurrSceneID`以及`lb.GetObjectCount`。本工具不把它們當成功能入口。

`Q.Book`和`Tutorial.IsCharacterAvailable`雖各接受一個整數，已查native不以該參數選任意書本／角色。`Tutorial.SetUIPage`沒有任意page參數。數值ABI正確亦不會把Q slot變成world ID、把ShopNo變成NPC ID，或讓沒有一般world事件producer的getter突然成為清波通知。

## 7. 可直接使用的只讀內容預驗工具

`validate_calls.py`讀一份宣告式JSON呼叫計畫，拒絕：不在固定集合的名稱、stub/count誤用、參數數量不符、數值欄位放boolean／非整數／非有限值、對話boolean欄位放0、讀取沒有producer的結果，以及把結果當通用成功。

JSON形式是新分析工具的輸入格式，明確為 **NOT_NATIVE_MEF**；工具不產生可部署SEQ、不解釋官方MEF、不讀寫遊戲記憶體、不執行Lua、不送封包。成功只回`ABI_PASS_ONLY`，`deployment_ready`永遠為false，並列出typed identity、資源、owner、prepass/formal、Server與遊玩驗證等剩餘門檻。

```bash
python -B validate_calls.py review-call-plan.json
python -B verify_evidence.py --bin /path/to/Tartaros.bin
```

`validation-examples.json`及`validation-results.json`是此工具的合成驗收資料，專門檢查已由原件證明的ABI陷阱；不是原生遊戲執行結果。原始byte核對結果另在`verification-result.json`。

## 8. Server與內容工具需求

沿既有REQ-0019／REQ-0021脈絡，S00可整合以下需求，而非新建平行正式台帳：內容發布前按綁定版本驗ABI；保存typed IDs、完整參數和依賴hash；把命令已發起、query數值、native自然終點、Server業務提交分開；不要用無producer的返回值做成功或授權決策。內容的真正入口、資源選取與同場景第二次使用另依本輪其他章節。

本分題的121名稱ABI已完成所列靜態目標；官方MEF完整格式、所有動態綁定、全部native功能body與可玩完成不在這個完成聲明中。來源與衍生偽碼導航pin見[source-manifest.json](source-manifest.json)，原始證據見[native-evidence.asm](native-evidence.asm)。
