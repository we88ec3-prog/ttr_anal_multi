# T10-082 — KR KeyMapping 13–16：BIN 直接交叉引用、映射 bank、輸入狀態與派送邊界

- 時間：2026-10-28T09:49:26.564836+08:00
- 適用：KR `Tartaros.bin`，只讀靜態調查。未執行、附加、修改遊戲。
- SHA256 BIN：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本次以 `sha256sum` 重新取得並一致。
- PE 段由 `objdump -h` 直接核對：`.text` VMA `0x401000` raw `0x400`, Size `0x7D01F0`；`.rdata` VMA `0xBD2000` raw `0x7D0600`；`.data` VMA `0xD61000` raw `0x95E800`。下方全部 VA 在該版本範圍。
- 來源銜接：T10-081 已提交原稿 `kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md`；正式原件 `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt` 與 `kr/evidence/6c019693bf60589feb2f3ff6aec651f83ddc0d8103e1358f0ad9c19caf8ac973.txt`，由 GitHub 讀取比對。
- repo 正式 T10 範圍「輸入、連段及取消」，`kr/tasks/T10/task.json` 目前 `owner: null`, `state: unclaimed`；不代整合者修改 owner/catalog。

## 核心進展與結論界線

**已確認**：`0x6D4DC0` 是使用 `(MapButton + mode*40)*16` 定位 bank 內部 vector/list 的輸出查詢；`0x594610` 多次以常量 13/14/15/16 呼叫，且結果立即進入 UI/文字建構路徑，不得視為戰鬥執行者。`0x6D1A70` 的 `mode*0x280` 及 `0x6D0750` 的三 bank 初始化提供獨立交叉驗證。`0x5961C0` 透過 `0x6D4CE0` 讀取狀態碼 1/3 並派送 vtable +0xEC/+0xF0；兩路目前尚**未閉合**到角色 motion/queue/cancel，也沒有在此批取得非零 phase writer。

## A. 檔案資源與版型（原始 XML；不等於目前玩家自訂設定）

`KeyMapping.xml` `DefaultType=0`：Type0 `(MapButton,Key,ModKey)` = `(13,44,0),(14,45,0),(15,46,0),(16,47,0)`；Type1 為 `(10,44,0),(11,46,0),(12,47,0)`，Type1 另外分配 MapButton13..16 至 Key36..39，**不是** Type1 沒有 MapButton13..16。Type1 **沒有直接列出 Key45/ModKey0**，仍無 runtime fallback 結論。Z/X/C/V 只是 DirectInput DIK 相容解讀，尚缺 producer 確證。

`KeyMappingExtra.xml` 另有 105xx/110xx；特別 Type1 `(MapButton10509, Key45, ModKey29)`，因此「Type1 沒有 Key45」只對**基本表且 ModKey0**成立，不能對 Extra 或完整 runtime 鍵位作全域否定。

## B. BIN 查詢函式 0x6D4DC0：參數、索引、輸出

由 0x6D4DE8: `eax=[ebp+0xC]` 為第二個整數 `mode`；`ebx=[ebp+0x8]` 為第一個整數 MapButton。 `edi=ecx` 是輸出 vector 指標。若 `(MapButton-0x2711)<=0x270E` 走特殊高 ID 映射，**普通 ID=13..16 必走 0x6D4EE6 一般 bank 分支**：

```asm
006d4de8  mov eax,[ebp+0xc]
006d4deb  mov ebx,[ebp+0x8]
006d4df0  lea ecx,[ebx-0x2711]
006d4df6  cmp ecx,0x270e
006d4dfc  ja 0x6d4ee6
006d4ee6  lea edx,[eax+eax*4]
006d4ee9  lea ebx,[ebx+edx*8]
006d4eec  xor esi,esi
006d4eee  shl ebx,0x4
006d4ef4  lea ebx,[ebx+0xfb8834]
006d4f30  mov eax,[ebx+0x4]
006d4f33  sub eax,[ebx]
006d4f35  sar eax,0x2
006d4f38  cmp esi,eax
006d4f81  mov edx,[ebx]
006d4f83  mov esi,[edx+esi*4]
006d4fe9  mov [eax],esi
006d4feb  add dword ptr [edi+0x4],0x4
```

因此 `address = 0xFB8834 + 0x10*MapButton + 0x280*mode`。位址中內部以 vector begin/end 動態容器取值，填充 `edi` 的 DWORD 陣列（`0x6D4F70..0x6D4FFA`）。不是讀取 `0xFB9004` 即時鍵位狀態，也不是根據 MapButton 執行招式。當 `mode=2` 查詢 13..16 時基址偏移為 `0x500+{0xD0,0xE0,0xF0,0x100}`，即 `0xFB8E04/0xFB8E14/0xFB8E24/0xFB8E34`（各 slot 的 vector 起始欄位）。

**重要**：MapButton 為 XML/設定的 ID，`0x6D4DC0` 查的是其對應鍵碼列表；mode2 不能僅憑呼叫處直接當 Type0 或 Type1。

## C. bank 選取與第三 bank（新直接證據）

```asm
006d0775 push 0x6d08e0
006d077a push 0x6d08c0
006d077f push 3
006d0781 push 0x280
006d0788 push 0xfb8834
006d079a call 0x892003
006d07ce call 0x6d08f0
006d0808 push 2
006d080a call 0x6d1a70

006d1a93 mov ebx,[ebp+0x8]
006d1a96 cmp ebx,3
006d1a9f lea eax,[ebx+ebx*4]
006d1aa2 shl eax,7
006d1aa5 add eax,0xfb8834
006d1aaa mov [0xfb902c],eax
006d1ab4 mov [0xfb9030],ebx
006d1b02 mov [0xfb9004],eax  ; 前一行 xor eax,eax
```

由此證明初始化建構**三個每段 0x280 byte 的 bank**；函式啟動後以 mode=2 設定選取指標，但第三 bank 的**資料生成與是否複製/反映玩家目前設定**尚需由 `0x6D08F0`, `0x6D0D10`, `0x6D1BE0`, save/load 追溯，絕不可單純認定 mode2 等於 XML Type2（XML 僅有 idx0/1）。`0x4A1440` 另一處以 mode=0/1 形成來源 bank，再 `push 0xFB8D34` (mode2 bank) 與來源並呼叫 `0x6D1BE0`；此為**可驗證的 bank 複製候選／流程**，尚待逐指令審核其複製方向與何時被呼叫：

```asm
004a1493 mov eax,[ebp+0x8]
004a149a cmp eax,1
004a149f lea eax,[eax+eax*4]
004a14a2 shl eax,7
004a14a5 add eax,0xfb8834
004a14aa push eax
004a14ab push 0xfb8d34
004a14b0 call 0x6d1be0
```

## D. MapButton 13–16 在 0x594610 的常量 caller

`0x594610` 首先查詢 `MapButton=edi, mode=2` (`0x594664 push 2; 0x594666 push edi; 0x594672 call 0x6D4DC0`)，隨後對 `edi==0x18/0x19` 有特殊分支：

- `0x5946BB push 2`, `0x5946BD push 0x0D`, `0x5946CB call 0x6D4DC0`; `0x594713 push 2`, `0x594715 push 0x0E`, `0x59471B call`。
- `0x5947ED push 2`, `0x5947EF push 0x0E`, `0x5947FD call`; `0x594845 push 2`, `0x594847 push 0x0F`, `0x59484D call`。
- `0x59491F push 2`, `0x594921 push 0x0D`, `0x59492F call`; `0x594977 push 2`, `0x594979 push 0x0F`, `0x59497F call`。
- 其後還有 `0x594CD4` 等多次 lookup；需逐一確認不同入口／分支是否用 16（原始 x86 call sites 已由全 `.text` 掃描列舉）。

上述取出的 vector 元素在 `0x5946E6..0x5946FF`、`0x594732..0x594753` 依 `[ebp+0xC]` 布林分支經 `0x594A80` 或 `0x594570` 包裝，並呼叫 `0x4041F0`，符合**文字/控制介面形成路徑**；沒有證據是角色 motion writer。任何 UI 配鍵顯示與命令執行必須嚴格分離。

## E. 執行時狀態 reader 與多型 dispatch：0x6D4CE0 / 0x5961C0

```asm
006d4d05 lea eax,[esi-0x2711]
006d4d0b cmp eax,0x270e
006d4d93 cmp esi,0x27
006d4d98 movzx eax,byte ptr [esi+0xfb9004]
006d4d6f ret
006d4dae xor eax,eax

005961ed mov eax,ebx
005961ef call 0x761010
0059624b mov [ebp-0x24],edi
0059624e call 0x6d4ce0
00596267 cmp eax,1
00596275 mov eax,[edx+0xec]
0059627b push edi
0059627c call eax
005962bc cmp eax,3
005962ce mov eax,[edx+0xf0]
005962d4 push edi
005962d5 call eax
00596386 inc edi
00596387 cmp edi,0x28
0059638a jl 0x596245
```

**已確認**：`0x6D4CE0` 特殊 key domain `0x2711..0x4E1F` 會查 `0xFDF630` 管理的節點 `+0x10`，正常 domain `0..39` 回傳 `[0xFB9004 + esi]` 的 byte。`0x5961C0` 遍歷 40 個普通 ID `edi=0..39`，檢查狀態等於 1/3，透過 `+0xEC`/`+0xF0` 多型槽位及額外子物件樹傳播輸入事件。但注意呼叫 `0x6D4CE0` 前 `esi` 與 `edi` 的寄存器路徑必須繼續核實（初段 `esi=edi` 是零，後段可能會調整）；不可由 `push edi` 推斷 reader 直接讀 `edi`。目前未確定方法槽位屬哪個戰鬥角色類別。

**已確認的清除，非非零 writer**：`0x6D1B00..0x6D1B2F` 在更換 bank 時對 `0xFB9004..0xFB9028` 逐 dword 清零；`0x6D4A9C..0x6D4ACE`、`0x6D4B6B..0x6D4B98`、`0x6D4CAE mov byte [esi+0xFB9004],0` 均為清除路徑。未定位直接設為 1/3 的 writer，仍可能以別名指標、base+offset、callback 或完整 block copy 寫入。

## F. 全 `.text` 靜態 literal caller 掃描

此次對 SHA 核對 BIN 執行 `objdump -d -Mintel` 逐行搜尋 `call 0x6D4DC0`：主要集中 `0x594672..0x5959F4`；另找到 `0x5CD68A`, `0x5CE5BA`, `0x62B5BA`, `0x650E96/0x650F48/0x650FF6/0x6510A4`。`0x6D4CE0` 可見 caller `0x59624E`, `0x59643F`。這僅是**直接 E8 相對 call**清單，不含間接呼叫、tail call 或多態轉送。不可認定掃描涵蓋所有控制器 consumer。

## G. 待解／下一階段 T10-83 優先路線

1. **非零 phase writer**：追 `0xFB9004` 的所有 alias/range 寫入，先從持有已選定 bank 指標 `0xFB902C` 的輸入事件 producer / 0x6D0D10 callbacks 延伸，包含寫入 1/3 或批次移動；將 `0x5961C0` 的 `edi/esi` 實際流核對至每一個 ID。
2. **實體鍵碼來源**：查 DirectInput 初始化及 keyboard state acquisition (`GetDeviceState`/DIK?)、Key44..47 實際進入映射資料的 producer；不把慣例當機器碼結論。
3. **mode2 來源/持久化**：細讀 `0x6D1BE0`, `0x4A1440`, `0x6D0D10` 與其 caller，確認 Type0/Type1、第三 bank、使用者自訂和 Type1 Key45 fallback。注意 `0x4A1440` 僅接受 0/1。
4. **consumer→角色動作**：解析派送目標之具體 vtable 實體與 method `+0xEC/+0xF0`，跨至角色 controller/motion/queue/cancel；不以 UI 查詢 `0x594610` 假稱攻擊。
5. **MapButton16 精確 UI 路徑**：追 `0x594C..0x595A` 一系列查詢確切 caller 入口與常量，避免推斷。
6. 原版 Z 連打／持按、V tap/hold 與取消時間仍缺 native 證據；`CHAIN_WINDOW=0.65` 是本機替代，不得填入原版。


## H. 追加 BIN-first 深入：自訂 bank2 載入的強證據

`0x6D0D10` **不是普通輸入鍵盤 producer**；它在 `0x6D0750` 初始化後、特定條件（`[0xFB91E9]==2`）下被呼叫，具有檔案/設定資料讀取後寫入第三 bank 的明確結構：

```asm
006d07fa cmp byte ptr [0xfb91e9],2
006d0803 call 0x6d0d10
006d0d24 push 0xbed1e0
006d0d2f push 0xc408d8
006d0d3d call 0x891892
006d0d45 cmp dword ptr [ebp-0x108],0
006d0d4b je 0x6d0e97
006d0d51 mov eax,0xfb8d34
006d0d56 call 0x6d0700
006d0d92 call 0x897618
006d0dca call 0x895f8c
006d0dd2 cmp eax,2
006d0dd7 mov esi,[ebp-0x114]
006d0ddd mov edi,[ebp-0x110]
006d0de3 shl esi,4
006d0de6 add esi,0xfb8d34
006d0dec mov eax,[esi+4]
```

`0x6D0D10` 的解析 loop 以 `0x895F8C` 的返回值 2 為分支，得到兩個整數後，用第一個整數 `<<4` 指向 mode2 bank 元素、第二整數作為即將插入的 DWORD 值；**可確定有一條從外部設定字串/資料→mode2 vector 的回填路徑**。外部設定的實際檔名、編碼格式、何時由使用者保存，尚未從被呼叫者和字串 `0xBED1E0/0xC408D8/0xC408E8` 完成解碼；故不應把此路徑直接稱為某特定存檔的完整格式。

`0x6D1BE0` 的入口另確認 `ebp+8` 與 `ebp+0xC` 是連續向量範圍指標，逐 `0x10` bytes 的 vector slot 進行複製/調整（`0x6D1BFD lea esi,[ecx+4]`, `0x6D1C03 lea ecx,[esi-4]`, `0x6D1C0E mov ecx,[ebx+esi]`），與 `0x4A1440` 由 mode0/1 整個 bank 更新 mode2 的用法相符。這使 mode2 確認是**可覆寫/可回填的工作 bank**，但是否即時有效仍須追 `0xFB902C` consumer。

## I. 其他 MapButton16 直接 caller

不同於 `0x594610` 的 13–15 特定格式展示路徑，於 `0x5CD67C push 0x10; 0x5CD68A call 0x6D4DC0` 找到另一條 `MapButton16` 的**直接 caller**。由於第二參數需檢查前置指令、結果需繼續追消費者，暫不認定它就是 V 的戰鬥動作。`0x5CE5BA` 另外明確查 `MapButton22, mode2`；這提供區分 UI/設定函式群的後續 xref 入口。

## 完成度／版本管理

本段確認了**基本映射與執行時 reader/事件派送的不同層級**，未構成「完整動作鏈」還原。報告保存已明確驗證片段及未閉合點；**未 Commit、未 Push、未改 repo 檔案、未上傳任何原始遊戲檔**。