# MapList root 保存值跨 callee 的續追：冷初始化、具體 virtual target 與剩餘界線

研究批次：2026-11-15 06:07 Asia/Taipei 起；接續 `extra/roy1` 的 `.mef` 完整使用流程階段分析。本文是原件靜態研究子稿，不代表整個 `.mef` 使用流程已完成，也不代表 T01 FULL-PASS。

## 1. 本輪回答了什麼

前稿已找到 MapList 根指標 `FB7470` 的保存值，但若只看 caller 的顯式參數，無法排除 ESI／EDI 跨過通用 helper 或間接呼叫後再被使用。本輪沿四組指定保存值，補查 callee 的首次功能性讀取、覆寫、callee-save 堆疊保存／恢復，以及恢復後的下一個 call。

**在本輪列出的原生應用程式路徑中，沒有新增「以保存的 MapList root 讀取 `+0x50` TRIGGER 名稱，再首次載入 `.mef`」的正向 caller。** 新增成果是把先前未具體化的數個間接 target 與冷 helper 落到原件：`FBA854` sender、`FB7B78` 的兩種實作、`FBA7A4` 的已識別實作，以及 `6D9B30` 的舊資源清理鏈。這些 target 都能繼續核對 incoming EDI；不能僅以「它看起來是通用 helper」排除。

**保存的 root 確實會進入 callee-save 堆疊，也會在 callee 返回前恢復。** 本輪沒有把這種保存說成值已永久消滅；遇到恢復後仍有 call 的情況，已另追。例如 `80EB51 pop edi` 恢復 root 後，`80EB61`、`80EB6E` 還會呼叫內層 virtual method，兩個 target 皆已再落實。這一點是本輪相對前稿的必要補充。

本稿的陰性結論仍有明確範圍：任意 runtime callback、CRT 例外處理、外部 DLL 內部，以及沒有被本輪具體 writer 鏈覆蓋的其他計算式寫入，不在全程式閉包內。它們沒有因此被提升為 `.mef` 入口，也沒有被宣稱全數不存在。

### 1.1 來源與固定版本

| 項目 | 固定身分 |
|---|---|
| 原件 | `02-Tartaros.bin`，12,472,320 bytes |
| 原件 SHA-256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 本輪工作來源 | `67021e609f56e45981aecf45533bdad084039a47`，`extra/roy1` |
| 主代理核對的 main | `909754f28bd2e54c8ede00e3a56021cf59facd14`，未 merge |
| 共用規範原檔 | `09-02-PROJECT-SHARED-INSTRUCTIONS.md`，SHA-256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43` |
| 原件執行／修改 | 無；未執行 Client／Lua，未修改原件 |

精確 Git path／blob pin 及本輪實際讀取層級見 [source-manifest.json](source-manifest.json)。四份前稿檔案核對了目前本地內容與固定 Git blob；其他函式來源只核對固定 tree entry 作位址導覽，**沒有把未重讀的反編譯內容寫成已讀／已驗證**。

### 1.2 明確復用的前稿結論

以下均是復用，不列為本輪新發現：MapList root=`FB7470`；TRIGGER collection=`root+0x50/+0x54`；`4F6E80` 讀取 `+0xE0/+0xE4`；`4F6B20`、`4F6B80`、`4F6D20` 各自已分析的表用途；四個保存 root 的 caller 位置；其他已在 caller 內覆寫的短 alias；前稿直接 root／accessor／initializer 的候選清冊；`+0xA0` DamageSound 支線的資源類型。

本輪未重做 `.mef` 名稱清查、`FB74C0` literal 全掃、155／32／165 舊清冊，也未把既有陰性當成新陰性。前稿基準是固定 commit 下的 `kr-extra-roy/MEF-trigger-callers-20261115/native-root/`。

## 2. 方法與「閉合」的限定

追蹤值是已確定等於 `FB7470` 的 incoming ESI／EDI，不是「任意名字相同的暫存器」。每個 callee 都區分四件事：

1. `push esi/edi`、SEH prologue 保存：值仍存在於堆疊，不能當成功能消費，也不能當成全程消滅。
2. 對 root 做 dereference、傳成參數，或寫入 owner／global：才是需要沿新 alias 繼續追的功能性使用。
3. `mov/lea/xor` 由另一來源定義暫存器：原 root 在該暫存器內消失，但堆疊保存值仍可能恢復。
4. `pop` 恢復後的 call：重新把 root 視為 live，另查其下游。單純 `mov edi,edi` 是 NOP，不能算消滅。

本輪原件記錄位於 [native-records.json](native-records.json)／[native-records.asm](native-records.asm)，每個窗口含 VA、raw offset、完整 hex、SHA-256 與 objdump 指令。`F-*` 是指定 callee 窗口，`R-*` 是復用 caller 的必要交接位置重核，`W-*` 是具體 writer 上下文，`VT-*` 是原始 vtable 資料。窗口名稱不是原生符號，也不代表整個函式的所有業務語意已審核。

`callee-dataflow.json` 保存四組路徑、29 個關鍵覆寫點、20 個 virtual binding、23 個定向 receiver writer 候選及其剩餘界線。這些數量用於重驗完整性，並非研究完成的判準。

暫存器先被覆寫，只能證明**這個 incoming root 值**未沿該 register 成為後續輸入；不代表整個 callee 及其所有子函式在任何狀態下都不會從別的 global／參數另行取得腳本入口。本稿是指定保存值的資料流續追，沒有用它替代全程式腳本可達性分析。

## 3. `491FCC` 的 ESI：`804A40/804FC0` 與冷 helper

### 3.1 caller 的生命期

`491FC7 call 425330` 返回 root；`491FCC mov esi,eax` 保存它。前稿已確認 `491FCE → 4F6B80` 的用途。本輪接續其後的可達分支：owner `EBX+0x90` 非零時，caller 在 `491FE4 mov esi,ebx` 覆寫 root；為零時，`491FDD call 804A40` 保留原 ESI 到 callee；後續共同經過 `491FEC call 804FC0`。caller 最後 `492005 pop esi` 恢復自己的上一層值。證據：`R-491FCC`。

### 3.2 冷初始化已追過第一層

| callee | incoming ESI 的實際處理 | 覆寫前仍有的 call | 正常返回 |
|---|---|---|---|
| `804A40` | `804A4D push esi`；`804A75 mov esi,[FBA858]` 才覆寫 | `804A4F` 的 IAT `BD25A0`；可選 `49AF60`／`49B000` | `804C65 pop esi`；其後無 call |
| `49AF60` | 本體不讀寫 ESI | 固定 `FC1208` 傳入 `805460`；固定 destructor 指標登記至 `89231A` | ESI 保留返回 |
| `49B000` | 本體不讀寫 ESI | 同一固定 `FC1208 → 805460`，及 `89231A` | ESI 保留返回 |
| `805460` | 保存後，`805488 mov esi,[ebp+8]`；參數是 `FC1208` | 覆寫前無 call | `80554B pop esi`；其後無 call |
| `804FC0` | `804FDF push esi`；下一條 `804FE0 mov esi,[ebx+0x3C]` | 覆寫前無 call | `80517F pop esi`；其後無 call |

`BD25A0` 的原始 PE import 是 `WINMM.dll!timeGetTime`。caller 沒有把 root 推成此 import 的引數；DLL 內部本輪未解碼。`49AF60/49B000` 寫 `FBA858` 的值為固定 `FC1208`，不是 incoming ESI。這不是「看見全域寫入就推定 root 逃逸」。

`89231A → 8922DE` 也沒有停在函式名稱：SEH prologue 的 `8A0B30` 將 ESI／EDI 保存；`893773 → 8A7257` 在 `8A7260` 以固定 lock-table 計算值覆寫 ESI；`8921F7` 在 `8921FF` 以 DecodePointer IAT 覆寫 ESI，正常登記的內容來自其顯式 function-pointer 參數；`8A0B75` 再恢復保存值。這些堆疊保存／返回不構成 TRIGGER reader。共用 CRT／外部邊界見第 7 節。

**限定結論：** 指定冷 helper 沒有把 root ESI 複製為可供 `.mef` loader 使用的新 owner/global alias；主 caller 的 live ESI 最後按上述位置消滅。這補完了前稿的冷 helper 檢查，不是全程式 `.mef` 支援與否的證明。

## 4. `53CC33` 的 EDI：`4054C0 → 587480` 與 font virtual call

`53CC2E call 425330`、`53CC33 mov edi,eax` 之後，前稿的 `4F6B20` 查表結果已知。本輪追入可選的 `4054C0 → 587480` 冷初始化。`587480` 本體不功能性讀取 EDI；它呼叫的通用配置／字串／常駐物件初始化需要再分類，不能一律以無顯式 EDI 參數排除。

### 4.1 固定 helper 與 vector callback

| 路線 | 本輪原件結果 |
|---|---|
| `7703F0` | `77041B xor edi,edi` 在任何下游 call 前覆寫 |
| `5CA940` | `5CA968 mov edi,[ebp+8]` 在任何下游 call 前覆寫 |
| `734EF0` | `734F1B xor edi,edi` 在任何下游 call 前覆寫；返回前 `7350BE pop edi` 後僅接 security-cookie helper |
| `41F3E0 → 75F1D0`、`7701E0`、`770DA0` | 本體沒有 incoming EDI 功能性讀取；正常配置路徑到第 7 節的配置器邊界，失敗 throw 明列保留 |
| `74D990 → 74D8D0/74D760` | 前者不使用 EDI；後者只傳固定記憶體範圍給 memset |
| `74D990 → 892003` | 不是未知 callback：三次 caller 明確傳入 `74D950`、`74D970`、`74D970`；這兩個 constructor 均不使用 EDI；顯式 destructor callback 為 `5F5D10` |

三次 vector constructor 的 native callsite 是 `74DC0B`、`74DC27`、`74DC46`；`892027 call [ebp+0x14]` 的實參由 caller stack 可落實。這裡避免因看見一般 function pointer 就永久停在「未知間接 call」。證據：`F-74D990`、`F-892003`、`F-74D950`、`F-74D970`。

### 4.2 `73586E` 的兩個 target

`5876F0 → 735850` 的引數包含固定 `FB7B70`；callee 讀 `[arg+8] = [FB7B78]`，取 vtable `+0x28`，於 `73586E call eax` 呼叫。EDI 在這個 call 前只有保存，直到 `73587B lea edi,[esp+0x1C]` 才覆寫，因此必須解析該 target。

原件 writer 是 `735004 call 73CF50` 後的 `735009 mov [FB7B78],eax`。`73CF50` 依 `[FBA820]` 分兩支：

| 建構分支 | 最終 vtable | 原始 `+0x28` slot | target 的首次 incoming EDI 處理 |
|---|---|---|---|
| `[FBA820] != 1`；配置 `0x28` bytes | `73CF93` 寫 `C45F94` | `C45FBC = 73BB50` | `73BB6A mov edi,ecx`，此前沒有 call |
| `[FBA820] == 1`；配置 `0x54` bytes，`73CFD1 → 73C450` | `73C487` 寫 `C45FEC` | `C46014 = 73C5B0` | `73C5E6 mov edi,0xF`，此前沒有 call |

兩個 target 都先覆寫 root，再執行自身欄位處理。它們返回前恢復 EDI，之後只進 security-cookie helper；回到 `735850` 後的 `73587B` 再覆寫，正常尾端 `73589D pop edi` 只恢復 caller，不再呼叫下游。`7351E5` 的另一個 direct writer 是析構歸零，不是第二個未知 provider。

**限定結論：** 這條冷初始化的實際 virtual call 不使用 incoming MapList root 作 receiver 或資料參數。最外 caller 後續的已知字串 constructor 保存／覆寫路徑仍成立，`53CC5E mov edi,[ebp-0x48]` 結束這個 root 的 caller 生命期。沒有新增 TRIGGER reader。證據：`R-53CC33`、`W-735009`、`W-7351E5`、`F-73CF50`、兩張 `VT-C45*` 及對應 target 窗口。

## 5. `4D607F` 的 EDI：world 冷初始化與固定 sender

caller 經 `4F6D20` 成功分支後，可進 `40F060 → 4DEC90`，後續仍可能經既有 `4DFAD0`、`414680`、`4A4240`。前稿只證明若干直接 callee 本體未讀 incoming EDI；本輪補上 `4DEC90` 與 sender 的實際下游。

### 5.1 `4DEC90` 的固定 helper

`4DD700 → 4DD8F0` 本體沒有 incoming EDI 功能性讀取。`4E1130` 的正常配置路徑進 `7A31C0`，在 `7A31C8 mov edi,[esi+4]` 覆寫後才呼叫其他函式。`6D6BE0` 在 `6D6C0B xor edi,edi` 覆寫後才呼叫其他函式。配置／throw 的精確保留界線見第 7 節。

### 5.2 `FBA7A4` 的舊物件與替換物件

`4DEC90` 於 `4DEEA7` 取得 `[FBA7A4]`。若有物件且 `[FBA7AC]==0`，`4DEEC5 mov edi,ecx` 先覆寫 root，再進 `544F50`；不能把此後的 EDI 當成 MapList root。

若舊物件存在且 tag 非零，root 仍 live，實際會到：

- `4DEED3`：舊物件 vtable `+0x28`。
- `4DEEE4`：仍存在的舊物件 vtable `+0x00`，顯式參數 `1`。
- 建立替換物件後的 `4DEF19`：新物件 vtable `+0x24`。

本輪只為這些實際 receiver 定向查 direct literal writers，再沿前置配置／constructor 取得以下 final vtable；沒有重掃 MapList root 或全部 BSS。

| final vtable | 具體建構來源／代表 writer | 舊物件 `+0x28` | 舊物件 `+0x00` |
|---|---|---|---|
| `C0FA6C` | `544C40` 後 caller 寫 final vtable；例如 `42456F` | `8DC2F0` | `544E50` |
| `C0F99C` | `5471E0` 或 caller 直接寫 final vtable；包括本次 `4DEF0F` | `8DC2F0` | `547200` |
| `BFB5A4` | `444210`，writer `436AF2` | `5486E0` | `4442D0` |
| `C0FA14` | `547390`，writer `456612/4C4812` | `547C80` | `5475D0` |
| `C0FAC4` | `548540`，例如 writer `4BB758` | `5486E0` | `548600` |
| `C0FB1C` | `548B90`，writer `4C4D01` | `8DC2F0` | `548C80` |

`8DC2F0` 的原件只有 `xor eax,eax; ret`。`547C80` 在 `547C82 mov edi,ecx` 覆寫；`5486E0` 在 `5486E1 mov edi,ecx` 覆寫，兩者都在後續 call 前完成。

析構 wrapper 不能只看第一層：`544E50/547200/548C80 → 544E80`，`544EA8 mov edi,ecx`；`4442D0 → 444300`，`444324 mov edi,[ebp+8]`；`5475D0 → 547600`，`547633 mov edi,[esi+0xB8]`；`548600 → 548630`，`548654 mov edi,[ebp+8]`。各 target 均在第一個功能性下游 call 前把 EDI 換成自身物件／欄位來源。返回 wrapper 後的 free 呼叫仍保留 root，已列入第 7 節的 named import／CRT 範圍。

新物件 `5471E0` 安裝 `C0F99C`，其 `+0x24` 原件為 `8DC2F0`。這也閉合 `4DEF19`，不留下無 target 的「初始化 virtual call」。

此集合是**已定位 writer 路徑的實作集合**；不是對任意計算式寫入／記憶體損壞下所有可能 vtable 的全程式排除。完整 writer 候選及 constructor 上下文保存在 `callee-dataflow.json.selected_receiver_writers`、`W-*` 與 `F-*`。

### 5.3 `4A4240 → [FBA854].vtable+0x10` 已解析

`4A4240` 建立前稿已知的固定 16-byte `0x00C6` 發送資料。在 `[FBA798]==0` 時，`4A4276` 取 `[FBA854]`，`4A4289 call eax` 呼叫其 `+0x10`，三個顯式參數是 `0`、本地 packet pointer、`0x10`。本輪沒有替這個 packet 新增未證語意，也沒有把它說成傳送 `.mef` 內容。

重要的新原件連線如下：

```text
8046F7  C7 06 48 17 C5 00       [new object] = C51748
80470F  89 0D 54 A8 FB 00       FBA854 = object
C51758  A0 69 80 00             vtable +10 = 8069A0
```

`FBA854` 另兩個 direct writer `803F76`、`8045EE` 是析構／清理後歸零。這些直接 writer 原件上下文與零值來源都已保存。

`8069A0` 不讀 incoming EDI，先進 `8438C0` 查 receiver 自身的 `+0x18/+0x1C` collection。`8438D8 mov edi,[ebx]` 在任何下游 call 前覆寫 incoming root；該函式沒有 call。無連線／長度零的分支直接返回；有有效物件且長度非零才於 `8069EB → 8060D0`。

`8060D0` 在 `80614F mov edi,FE3358` 覆寫 root 前，只有可能的 `807120` 冷初始化與 `89231A`。`807120` 在 `8071DB mov edi,eax` 取得配置結果前，正常分支只經配置器；其後寫 `FE3380` 的 EDI 已是新配置物件，**不是 incoming root**。`8072A7 pop edi` 恢復後無 call。`8060D0` 最後 `806188 pop edi` 後亦無 call。

因此 sender 的解析沒有導出 MapList TRIGGER 消費者。原 caller 正常 cleanup 到 `4D6587 pop edi`，這個 root 的生命期結束。證據：`F-4A4240`、`W-80470F`、`VT-C51748`、`F-8069A0`、`F-8438C0`、`F-8060D0`、`F-807120`、`R-4D6587`。

## 6. `4B4152/4BAD73/6D9616`：長 caller 的保存 root

這三個 caller 以 EDI 傳 `FB7470` 給前稿已確認的 `4F6E80`，再保存返回的資源名稱。在此後的長路徑中，EDI root 仍可能跨過可選初始化與其他 call。本輪沒有把 `4F6E80` 的已知 `+0xE0/+0xE4` 用途重新當新發現。

### 6.1 共用 helper

`54F850` 在 `54FA92 mov edi,0x1E` 前沒有 call；此後雖有大量以 EDI 寫 owner/global 的指令，所寫的是已覆寫的值。`550226 pop edi` 後沒有 call。

`402A70` 的一般路徑在 `402AD8 mov edi,[ebp+0xC]` 覆寫；其較早的重疊字串分支可進 `403040`，後者在 `40304E mov edi,[ecx+0x10]` 覆寫後才有後續 call。`6D8D20` 在第二條 `6D8D21 xor edi,edi` 覆寫。`6D9280` 在 `6D92BF mov edi,edx` 覆寫後才進相關處理。

`6D8E50` 本體沒有 incoming EDI 的功能性讀取；其選定下游已按上述字串／配置／常駐初始化路線核對。`6DAA70 → 6DACB0 → 8FF5A0` 只將明確浮點值傳到算術 helper；正常運算窗口未見 EDI root 作功能性輸入。一般 CRT 數學錯誤分派仍保留第 7 節的有限未知，沒有擴張成音效或 CRT 全函式庫研究。

### 6.2 `6D9BD7` 的舊資源 virtual target

`6D9B30` 的 ESI 是 caller 傳來的 channel／資源欄位 owner，**不是 incoming root EDI**。若舊名稱與新名稱不同且 `[ESI]` 有物件，`[FB9335]==0` 分支在 `6D9BD7` 呼叫該舊物件 vtable `+0x2C`。直到 `6D9C7A mov edi,1` 才覆寫 root，因此此 call 需要具體 target。

本輪沒有僅憑函式名稱推測資源類型。原件 producer／writer 鏈為：

1. `48E4B3` 推入固定 pool `FC16A0`，`48E4B8 → 80C950`。
2. `80C950` 每項配置 `0x40` bytes；`80C98E` 寫 vtable `C51BF4`；`80C9BE` 寫入傳入 pool 的索引槽。
3. 固定 background callback 建構於 `6D9067/6D9074`：wrapper vtable `C40FEC`，owner=`FC0FC8`，function pointer=`6D9870`。`4FACD0` 依 wrapper `+4/+8` 轉交。
4. `6D9870 → 6D9970 → 6D9E10`，後者選 `FC16A0` pool entry；成功時 `6D9ED6 mov [ebx],esi` 把該 entry 存入 channel 的 `[0]`。
5. `C51BF4+0x2C` 的原始 DWORD 是 `80EB30`，故在上述 producer 綁定下，`6D9BD7` 可具體落到 `80EB30`。

這一 producer 連線只用來解析 live-root 所經過的 virtual target，沒有順便宣稱整個 audio worker 排程與格式已完整逆向。

### 6.3 必須繼續追 `80EB51 pop edi` 之後

`80EB30` 的等待分支先 `80EB40 push edi`、`80EB41 mov edi,[BD2304]`（`KERNEL32!Sleep`），等待後 `80EB51 pop edi`。**這裡恢復了原 root，因此後面的兩個 call 仍是本題必要路徑。**

| callsite | 具體 receiver writer | 原始 slot → target | incoming EDI 結果 |
|---|---|---|---|
| `80EB61`，資源物件 `+0x14` 的 vtable `+8` | `80E766` 寫 `C51EEC`，`80E78E` 保存至物件 `+0x14` | `C51EF4 → 80FED0` | 有活動資源時 `80FEDD lea edi,[esi+0x10]` 先覆寫；無活動資源直接返回且不讀 EDI |
| `80EB6E`，資源物件 `+0x10` 的 vtable `+0` | `80E985` 寫 `C51F40`，`80E9CD` 保存至物件 `+0x10` | `C51F40 → 8109A0` | 本體不讀 EDI，只把 `[resource+4]` 傳 `libvorbisfile!ov_clear` 與 free |

`80FED0` 在 root 已被覆寫之後才呼叫 OpenAL imports；其可辨識的原始 import 名稱是 `alSourceStop`、`alDeleteSources`、`alDeleteBuffers`。`8109A0` 的 `BD26C0` 原始 import 是 `libvorbisfile.dll!ov_clear`。這提供實際資源清理類型的第一手來源，也使此路徑不必停在抽象的未知 backend。

本輪沒有發現 incoming root 被寫入 channel `[0]`：該 writer `6D9ED6` 寫的是 pool entry，當時所用 EDI 也已由 background worker 的 owner 重定義。必須區分「同一暫存器名稱」與「同一 root 值」。

### 6.4 caller 最後消滅位置

| 原 root 定義 | caller 末端 |
|---|---|
| `4B4152 mov edi,FB7470` | `4B421D mov edi,0x10` |
| `4BAD73 mov edi,FB7470` | `4BAEAD/4BAEB4` 換成固定字串位址 |
| `6D9616 mov edi,FB7470` | `6D9675 pop edi` |

這些 caller 位置是前稿已列的生命期終點；本輪新增的是中途可達冷 callee 與 virtual target 的檢查。沒有新增 `root+0x50` reader 或 `.mef` 首次載入。

## 7. 仍保留 incoming register 的精確界線

以下都已追到具體地址，不以「Runtime Evidence 不足」籠統代替尚未查的 native call。它們是本文有限陰性的外圍，不是新找到的 `.mef` trigger。

| 界線 | 已有原件證據 | 本文沒有聲稱的部分 |
|---|---|---|
| 配置失敗 callback | `891268` 先試 `892068`；返回零時 `891275 → 89E977`。`89E982` 對 `[F8CB78]` DecodePointer，非零時 `89E98F call eax`。呼叫前沒有覆寫 incoming EDI | 未在本輪重新追所有 runtime new-handler 設定者及任意 callback；不宣稱其全數不會觀察保存的 register |
| 一般 CRT 數學錯誤分派 | `901C69` 相關錯誤出口可到 `8A647F`；`8A649D` 可 DecodePointer，`8A6531` 等位置間接呼叫。正常算術窗口與動態 callback 邊界分開保存 | 未把全部 CRT math-error、特殊浮點控制字、錯誤尾支線及 user callback 做成全函式庫閉包 |
| 無效參數／C++ throw／cookie failure | 字串 helper 的 invalid-parameter 路徑、冷 constructor 配置失敗後 `8910A9/89C9F0`，以及 `891001` cookie mismatch 出口可進一般 exception/error infrastructure | 未解析任意錯誤處理 callback 與 stack unwind 全圖；不能從正常返回推定這些 exceptional exits 全部無 alias |
| 外部 DLL | PE import 描述、IAT 與實際傳入的 stack 參數已保存；包括 `timeGetTime`、HeapAlloc/HeapFree、critical-section API、`ov_clear` 等 | 沒有外部 DLL 本體的逐指令證明。這是已命名的模組界線，並非未知遊戲 loader target |
| receiver 的其他寫入可能性 | 本輪對 `FBA854/FBA7A4/FB7B78` 做定向 direct literal writer 查找，並追了本題所需的 pool／field producer | 未做任意 computed alias、所有 BSS 或全程式 pointer-analysis；不能保證受覆寫／損壞／其他未辨識 provider 影響時只出現表中 vtable |

正常配置路徑的原件仍有實質證據：`8920AD` 是 `HeapAlloc`，`8920B3 mov edi,eax` 後才處理結果；`8920E1 pop edi` 恢復後沒有新的 call。free 正常路徑在 `892112` 以顯式 heap／buffer 參數呼叫 `HeapFree`。memset 的一般大量寫入路徑在 `89E88D mov edi,ecx` 先覆寫，另一路 `8B1BD3` 使用向量操作，未消費 incoming EDI。這些證據足以說明本輪應用程式資料流，但不會把上述外圍自動升格為「全程式不支援 `.mef`」。

### 7.1 保存與逃逸的精確用語

「本輪未發現 root 的新 owner/global alias」不等於「root 從未被寫到任何記憶體」。`push esi/edi`、SEH prologue 是明確的堆疊保存；本文逐條記錄其恢復點。正常 return 恢復的是 caller 約定的保存值，不是把 root 交給 resource loader。

本輪沒有已識別的原生 producer，能把上述 runtime callback 接成「消費 incoming root 的 `.mef` loader」。因此保留它們的有限未知；對任意 runtime callback 或外部模組繼續擴張 callee-save 圖，已超出本題指定保存值與可辨識應用程式 consumer 的範圍。這些外圍不列成新的 `.mef` 支援證據。

## 8. 對 `.mef` 串接與 Server 開發的影響

### 已確認的影響

前稿的 MapList root alias 候選不能再僅因跨過未解析的 `FBA854` sender、`FBA7A4` 舊物件 callback、font virtual 或資源 `+0x2C` 就被當成有希望的 `.mef` 首次載入 caller；這幾個具體候選本輪已提供實際 receiver、vtable 與 register 資料流。它們的應用程式 consumer 分別是既有發送物件、常駐物件初始化／析構、固定 UI/font backend 與音訊資源清理。

### Client 待逆向

真正的「TRIGGER 名稱如何首次進入 `.mef` loader」若尚未在其他正向入口鏈閉合，仍是獨立的 Client 原生問題。本輪候選陰性不能替代該 caller，也不能推出整個程式絕無支援。任意 `.mef` 支援的全程式否定並非本稿完成狀態。

### Server 待開發

Server 仍應依已確認 Client 接收／啟動介面提供相容資料與時序；不能用本輪的 `0x00C6` 固定 sender 或一般 callback 自訂成一個未證實的「傳 `.mef`」介面。本稿沒有新增 Server 下發 `.mef` 的 opcode、wire schema 或 Client 接收 parser，故不產生猜填欄位的實作需求。

若主稿已有可用的固定腳本／既存載入機制，Server 所需的玩家條件、資料準備、回覆與狀態整合應列入 Server 開發需求；官方 Server 的內部決策未知不應被寫成 Client 逆向 blocker。本文只提供 root alias 候選的有界排除依據。

### 跨功能待整合與待遊玩驗證

本輪應與主稿的正向 trigger／parser／executor／腳本生命週期合併閱讀，不能單憑此子稿宣布 `.mef` 已串接或可玩。所有結論是靜態證據；未執行 Client／Lua，也沒有新增 runtime 遊玩通過結果。

## 9. 重驗、交付與範圍狀態

執行方法：

```bash
python -B verify_native.py --bin /path/to/02-Tartaros.bin --repo /path/to/ttr_anal_multi --check-disassembly --output verification-result.json
```

驗證器從原件唯讀取得 PE 映射、整檔 hash、198 個窗口與 31,268 bytes 的逐項 hex/hash；重解 150 個 code windows，包含窗口末端不得截斷指令的檢查；再核對 29 個覆寫位置、20 個 virtual binding、23 個 receiver writer 及 13 個 PE import 名稱。`--repo` 用固定 commit 的 `git ls-tree` 核對 134 個 source pin；只有標記已讀的 4 份來源再核對本地內容 hash，沒有用 `git show` 隱式大量下載反編譯 blob。

本次結果見 [verification-result.json](verification-result.json)：**PASS**。它代表包內原件／位址／綁定與固定來源一致，**不代表語意陰性可自動機器證明、不代表整個函式／整份 `.mef` 研究 FULL-PASS，也不代表 Server 可玩**。

### 最小提交檔案

- `report.md`：本分題完整原稿。
- `native-records.json`、`native-records.asm`：原件窗口、VA/raw/hex/hash 與指令。
- `callee-dataflow.json`：保存值路徑、覆寫點、具體 virtual binding、定向 writer 候選與剩餘界線。
- `source-manifest.json`：固定來源身分與讀取層級。
- `verify_native.py`、`verification-result.json`：可重驗方法與本次結果。

探索用的各函式 `.asm`、first-use navigation、literal 候選粗表、package builder 不必另外提交；必要證據已併入上述檔案。repo、分支與原件由本子代理保持未修改，交由主代理按使用者既有授權整合發布。

**本分題狀態：** 指定的應用程式 callee／virtual target 已按本稿範圍完成續追；一般 runtime callback、外部模組與其他未覆蓋 writer 明確保留。對完整 `.mef` 使用流程而言，這是階段性分析，不是首次載入 caller 已找到或全程式無支援的宣告。
