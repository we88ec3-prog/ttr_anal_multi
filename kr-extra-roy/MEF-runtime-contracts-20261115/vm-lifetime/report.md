# MEF 共用 VM：建構、重用、例外與銷毀

本分題承接 [上輪 parser／executor](../../MEF-complete-flow-20261115/parser-executor/report.md) 與 [腳本生命週期](../../MEF-complete-flow-20261115/script-lifecycle/report.md)，解答「換 `.mef` 是否得到乾淨環境」「何時釋放 Lua state」「能否用關閉 VM 取消單一腳本」。工作 parent 為 `a16841ac67638da4b29605f186f355722e8cf106`；導航來源固定在 main `ba5f96dfa94d734cbded291fb8887f50426bfa77`。沒有執行 Client、Lua 或修改原資源。

## 1. 結論與適用範圍

**正式執行與預掃描是兩個分開建立、平常會重用的 Lua state。載入下一個內容不等於換一個乾淨 VM。** 正式 wrapper 的直接建構入口以 singleton guard 保護，並登記程序結束用的析構函式；預掃描也有相同型態的生命週期。每次預掃描另有「清 native collection／music string、重新綁定、執行」流程，未重新建構 state。

這不是「絕不重建」的證明：兩個 guard 都有實際 C++ unwind 清除路徑。本輪把這些清除動作連回 caller 的 exception metadata，區分建構／登記例外和一般 Lua loader 的 status-return 失敗。亦沒有把有限 direct-call／literal census 當成所有間接呼叫的排除證明。

`.mef` 的原始 bytes 可以經既有資源 reader 取得；chunk、closure、global、coroutine 進入 VM 後是記憶體物件。**這不等於原始 `.mef` 一定另存在某個固定磁碟目錄，也不等於執行完成會把原始檔寫回。** 實際來源路徑與 ordinary／package 分流沿用 [上輪資源契約](../../MEF-complete-flow-20261115/resource-gates/report.md)。本分題證明的是讀取後 state 的存活邊界，沒有新增磁碟 cache 主張。

## 2. 所有權與地址

| 對象 | 地址／欄位 | 實際用途與所有權 | 原件 record |
|---|---|---|---|
| 正式 wrapper `W` | `FDF3C8`；`+0=L`、`+4=cursor`、`+8=owns` | `6F4380` 建立 state，設定 cursor=0、owns=1 | V01、V08 |
| 正式 guard | `FDF3D4` bit 0 | 建構前測試／設定；例外 unwind 可清除 | F01–F21、EH 系列 |
| 預掃描 owner `P` | `FE1EEC`；`+0=Lp`、`+4=Wp` | `55C610` 另呼叫 `6F74B0` 建立獨立 state | P01、P03 |
| 預掃描 wrapper `Wp` | 配置 12 bytes；`+0=Lp`、`+4=0`、`+8=0` | 借用 owner 的 state；owner 負責真正關閉 | P01、P02 |
| 預掃描 guard | `FE1EE8` bit 0 | 8 個受保護建構點；例外 unwind 可清除 | C01–C08、EH 系列 |
| native binding 的區域 wrapper | 代表函式的 `[EBP-18]`；owns 在 `[EBP-10]` | 從 Lua callback 參數取得 state，初始 owns=0 | B01–B06、BE1–BE3 |

`FDF3C8`、`FE1EEC` 等位於 PE 的 virtual／BSS 範圍，不能假造為原檔中的 runtime 值。本包保存的是引用這些地址的指令與靜態 metadata；原件 offset 均在各 record 的 `raw` 欄。

### 2.1 正式 state 的唯一直接絕對寫入

在 raw-backed `.text/.rdata/.data` 搜尋 `FDF3C8` 的 42 個 DWORD occurrence，逐一回到實際指令邊界分類。其直接絕對 store 為：

- `6F4383 → 6F74B0` 配置新 state。
- `6F4396 mov [FDF3C8],eax` 寫入 state pointer。
- `6F439B [FDF3CC]=0`，`6F43A5 [FDF3D0]=1`。

其他命中是傳遞 wrapper 地址或讀取其 state；**不能由此排除經 alias 的任意動態寫入**。但它足以否定「每次 `.mef` loader 都在這個全域建立另一個 state」的無證據假設。

## 3. 受保護建構與 atexit

`49B230` 提供最短完整代表：`49B257` 測 guard、`49B25D` 已建構則跳過；`49B25F` 設 bit；`49B26C` 呼叫 `6F4380`；接著 push `BCE6D0`、`49B276 → 89231A`；最後回傳固定 wrapper 地址。

對 `6F4380` 的有限 E8／E9 census 得到 **21 個 E8、0 個 E9、0 個函式地址 DWORD literal**。21 個 E8 全部是 guard → constructor → `push BCE6D0` → `89231A`，不是 21 個不同 VM。部分 site 屬於相同函式的不同控制分支。

`55C610` 同樣得到 **8 個 E8、0 個 E9、0 個函式 literal**，全部登記 `BCF290`。正式 21 個 `BCE6D0` literal、預掃描 8 個 `BCF290` literal，分別對應這些登記點。

`89231A` 的 CRT function-pointer 登記實作、保存 register 與冷初始化已由 [上輪 native-aliases](../../MEF-complete-flow-20261115/native-aliases/report.md) 往內確認；此處沿用固定來源，不重新把 CRT 當新的 MEF reader。原始窗口保存在該分題 `native-records.json`，來源 pin 列於本包 manifest。

這裡的「登記」指 caller 確實呼叫 atexit 型登記函式：`89231A` 將內層回值轉成 0／-1，這些 caller 未檢查其回值。**程序結束時能走所列析構，以登記成功且正常走退出處理為前提**，不是對配置／登記失敗或異常終止也必定釋放的保證。

### 3.1 guard 並非永不清除

`FDF3D4` 有 78 個 literal：42 個對應 21 次測試／設位，另外 36 個對應 **18 個不同 unwind clear action** 的讀／寫。`FE1EE8` 有 30 個 literal：16 個建構 guard 操作、14 個對應 **7 個不同 unwind clear action**。

這些 action 實際為：

```text
mov eax,[guard]
and eax,FFFFFFFE
mov [guard],eax
ret
```

本輪對涉及的 **25 個 caller functions** 保存了 prologue 安裝的 FS:0 handler、handler 的 FuncInfo 指標、unwind-map entry 及 action bytes。29 個建構點對應的 metadata entry 可共用 action，所以 entry 數與 unique action 數不同，不能加總為新的函式數。

**能確立的只有 C++ unwind 邊界允許 guard 被清除；不能推成每次 Lua syntax/runtime error 都會重建 VM。** 上輪 `6F4A50`／Q／Tutorial 的 status-return 路徑，沒有因這些例外 metadata 就自動變成 VM-reset 邏輯。亦未證明建構失敗的所有 allocator／CRT 邊界都能恢復後繼續遊戲。

## 4. 預掃描每次清什麼

`55D6A0..55D7D3` 保存完整入口到 return：

1. `55E2E0` 清 owner `+8` 的收集容器。
2. `402A70` 重設 owner `+18` 的 music string。
3. 重新註冊六個既有收集 binding。
4. `55D7C2 → 6F4A50` 使用 owner `+4` 的同一 wrapper 執行內容。
5. 回傳 owner `+8`；此路徑沒有以 loader status 中止或回報成功。

此函式內沒有建立新 state 的 `6F74B0`，也沒有改用另一個正式 wrapper。**native collection reset 與 Lua global reset 是兩件不同的事。** 腳本本身可以賦值覆寫 globals；本結論不代表所有 global 保持原值，而是 native prepass 沒有提供每檔全新環境的保證。

開發新內容時，應分開定義「本次預掃描結果」「正式執行狀態」「是否成功載入」；不可把非空舊 global 或上一輪 task table 當成本輪成功證據。雙 VM 的可用 binding 差異與同一內容可能執行兩次的契約，承接上輪 script-lifecycle；本輪未放寬。

## 5. 正常銷毀與借用 wrapper

### 5.1 正式 VM

`BCE6D0` 比較 `[FDF3D0]`，非零才讀 `[FDF3C8]`，在 `BCE6DF` 呼叫 `6F75F0`。這是前述登記的全域析構目標；以登記成功且正常退出處理為前提，不是已證實的單次過場 callback。

### 5.2 預掃描 VM

`BCF290 → 55C720`。`55C720` 先取 `Wp`，僅當 `Wp+8 != 0` 才關閉 wrapper 的 state；正常建構把它設為 0，因此接下來只釋放 wrapper 配置並清 `FE1EF0`。之後 `55C78C` 取 `[FE1EEC]`，`55C791 → 6F75F0` 真正關閉 owner 擁有的 state。

這說明為何預掃描 wrapper 的 owns=0 不能解讀成「預掃描 state 不需釋放」：**釋放責任在外層 owner。** 僅憑這條正常初始化路徑，也不能證明其他任意 mutation 都不會造成雙重 close。

### 5.3 native callback 的區域 wrapper

通用 destructor `6F4410` 先測 `[wrapper+8]`，非零才 tail-jump `6F75F0`。有限 census 有三個 E9 upstream：`9383C3`、`938633`、`9387D3`，各自從 `[EBP-18]` 取區域 wrapper。其代表 callback 分別為 `568BC0`（Q.EnableInput）、`569D20`、`4AC270`（Tutorial binding）；三者 prologue 都把 owns 設 0。各 family 的 EH handler、FuncInfo、unwind-map→cleanup 亦附原件。

此證據證明代表 binding **初始借用**既有 Lua state，不能把 wrapper 的 stack cleanup 誤當 VM 銷毀。沒有宣稱對所有任意 indirect target 做過不可變性證明。

## 6. 關閉 state 的範圍是整個 VM

在 `6F75F0`，`6F75F7` 取 incoming state 的 `+10` global state，`6F75FB` 再取其 `+70` main thread。`6F7532` 的建立端已證明 `global+70` 寫入 main state。

後續關閉 upvalues、處理 finalizer、進入 `6F7300` 釋放 VM 所屬容器，最後 `6F7384` 透過 `global+0C` allocator 以 new-size=0 釋放 state block。預設 allocator 由 `6F7528` 寫為 `6F7170`。這些原件資料流顯示：**不能把 close state 當成移除單一 MoCo task 或只卸載一個 `.mef`。** 若傳入 coroutine state，它仍先找回同一 global state 的 main thread。

這裡只核對關閉入口與釋放範圍；沒有把所有 GC／CRT／第三方 finalizer 實作列為已逐函式閉合。MoCo list 的移除語意見本輪 [scheduler](../scheduler/report.md)。

## 7. 有限集合與驗證

| Target | `.text` E8 candidates | `.text` E9 candidates | 指定三節 raw-backed DWORD literals |
|---|---:|---:|---:|
| `6F4380` 正式建構 | 21 | 0 | 0 |
| `55C610` 預掃描建構 | 8 | 0 | 0 |
| `6F74B0` 新 state | 2 | 0 | 0 |
| `6F4410` wrapper destructor | 0 | 3 | 0 |
| `6F75F0` state close | 3 | 1 | 0 |
| `55C720` 預掃描 destructor | 1 | 0 | 0 |
| `BCE6D0` 正式 atexit target | 0 | 0 | 21 |
| `BCF290` 預掃描 atexit target | 0 | 0 | 8 |

`6F75F0` 三個 E8 為 `55C774`、`55C791`、`BCE6DF`，一個 E9 為 `6F4418`。`6F74B0` 兩個 E8 分別在正式／預掃描建構內。這些是對指定 target 的有限 byte candidate set，先計數再由指令／caller 語意核對；不擴張為「沒有任何計算產生的函式指標」。

本包 **352 records、292 code windows、2,288 個含重疊指令記錄、9,806 bytes 的窗口總長**。它們包含短指令、重疊窗和靜態表，**不是 352 個互不重複函式**。9 份導航偽碼正文已讀；其餘導航只 pin 函式起點 tree metadata，明列 `contents_read_this_round=false`。source pin 共 46 項。

```sh
python -B kr-extra-roy/MEF-runtime-contracts-20261115/vm-lifetime/verify_evidence.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

檢查 [native-windows.json](native-windows.json) 的 raw／VA／完整 bytes／SHA、以 objdump 重新判斷 instruction endpoint、重算 [candidate-sets.json](candidate-sets.json)、檢查 [lifetime-relations.json](lifetime-relations.json) 的 guard／atexit／EH／ownership anchors，以及固定來源 tree identity。PASS 不表示所有遊戲路徑都已執行驗收。

## 8. 對 MEF 與 Server 開發的要求

| 類別 | 應實作或遵守的契約 | 本輪不能代替的驗收 |
|---|---|---|
| 新 `.mef` 內容 | 明確初始化本次 globals／task list；完成與取消各有內容層 cleanup；預掃描不得提前造成正式遊戲副作用 | 真正入口呼叫、重複啟動與失敗後恢復 |
| Server 開發需求 | instance／phase／run-id／取消與完成去重由 Server 狀態機持有；不能以 Client 共享 global 值推定本輪完成 | 既有封包與權威狀態的整合驗收 |
| Server 開發需求 | 資源版本與發布一致性；新執行只能選中已可讀、可解析且契約相符的內容 | ordinary／package 實際供應方式與首次 caller 閉合 |
| Client 逆向剩餘 | 正常流程首次選中並執行新 `.mef` 的 caller；普通戰鬥事件與 Lua callback／entity identity 連線 | 不由本輪 VM 所有權研究自動補齊 |

可著手實作與驗證上述狀態及內容契約。**本輪沒有證明新 `.mef` 已串起完整正常遊玩流程，也沒有提供／要求關閉共用 VM 的 workaround。**
