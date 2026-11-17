# P1 普通背景入口 B：對話框 FTC 首載、root owner、卸下與重入

日期：2026-11-18（Asia/Taipei）。工作分支 `extra/roy1`；固定來源 `15d9501c203c6f656461b64f578a50c96e38a5ff`。本分題只讀原件、追查 native 資料流並新增研究檔；沒有執行 Client、Lua、Server 或目標 DLL，沒有修改原件或建立分支。

## 1. 本輪結論與玩家能懂的進度

**本輪查清普通任務／Scenario 頁面究竟用哪份檔案建立對話框、如何保留同一個框，以及卸下後如何再次掛回。這條新閉合的鏈是原生 UI layout，還沒有成為「玩家照常走動和戰鬥時，新背景腳本自行開始、持續更新、離圖停止」的入口 B。**

真正新增的結果如下；既有 binding、caller、talk vtable 清冊沒有重算成新進度。

| 問題 | 本輪結果 | 玩家功能的意義 |
|---|---|---|
| 普通頁面要讀哪個對話框資源？ | resource 212 精確對到 `UI/Component/TalkBox_Scenario_Panel.FTC`；Master 指向 `UI/Component.stp` | 補件有明確檔名，能往實際對話框文字／圖片節點繼續追 |
| 前稿尚未定型的 owner／custom child hook 是誰？ | 首載先設 `talk+18=talk`；hook 為只有 `RET 0xC` 的 native 方法 | 已排除此具體 hook 偷帶另一個 script loader 的候選，並更正前稿過強敘述 |
| 重入會重新讀檔、重新建框嗎？ | 正常 descriptor cache 命中時回同一 `descriptor+C`；不重讀 FTC | 「框還在快取」不等於「新劇情已開始」或「舊劇情已完全停止」 |
| 普通頁面如何卸下它？ | 真實普通 page 的 uninitialize route 以 ID 212 detach，再移除 active map；有 descriptor 時保留框 | 原生 UI 的收尾與重用有了具體契約；不能當作背景 Lua 的取消完成確認 |
| child／dock 是否還能繼續靜態追？ | 補閉必要 type 200／1400 的 factory table 與三型 dock；保留 actual FTC 子圖 | 實際額外元件、圖片／文字屬性及後續 callback 仍要原件才能選出 |

**P1-B 狀態仍為 `NOT_CLOSED`。** 本輪有界 UI 首載／owner／cache／卸下鏈已分析閉合；「完整背景腳本功能」仍未完成。驗證器的 PASS 只表示本文列出的來源、原件窗口與契約可重現，不能改成 T01 FULL-PASS、Server 已完成或已可玩。〔[candidate-contracts.json](candidate-contracts.json)〕

## 2. 研究終點、既有成果與來源

B 的研究終點維持：普通 Mission／Scenario 的 current field/page 與一般輸入仍有效，由可達 producer 首次載入或登記**本次內容**，在同一 VM 持續 pump，並能識別 owner、取消及重入。建立 UI、登記 `ScenarioTalkTable`、具備 `DoFile` 或已存在的 coroutine API，都各自不能代替完整鏈。

本輪接前稿明列未展開的 `talk+18 → v+110`、`native child/dock factory` 及 manager 資源載入邊。沒有再掃已完成的 121 個 binding、33 個 marshaller、223 個 closure sink caller、91 個 talk vtable slot，也沒有重做 constructor／Rebind／clone 的結論。這些分別復用前稿 entry-b、comprehensive/events、ordinary-runner、trigger-callers。〔S004–S015〕

| 原件 | Bytes | SHA-256 |
|---|---:|---|
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `11-Master.stp` | 1,094,887 | `f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d` |

BIN 為 PE32/i386，ImageBase `0x400000`；VA→raw 依原件 section table。`native-evidence.json` 保存 **51 個完整函式、明確 prefix 或選定 factory fragment，5,213 bytes／1,817 條指令，38 個限定 data/RTTI 窗口**；另重驗前稿 11 個必要窗口以接起舊、新資料流。窗口種類逐項標示，prefix 不冒稱其餘 caller 已全部展開。完整可讀指令在 [native-evidence.asm](native-evidence.asm)。

[source-manifest.json](source-manifest.json) 固定 **86 個 Git source** 的 commit／path／blob／bytes／SHA-256；bulk C 只作導航。`read-set.json` 區分採用的 native 範圍、導航讀取及既有結果復用。共用指示與 main／T01／RR 開工基準由主線本輪核對；此分題不改正式台帳。

## 3. 先分清 page、binder、descriptor、manager

前稿已證：Mission／Scenario initializer 取得 cached `UICachingData<212,CScenarioTalkBox>`，把 window 放入 `page+B4`，talk constructor 綁正式 wrapper `FDF3C8` 並設 `FE3180`。本輪新增的是 **5A9F40／5A3840 之間的真正 receiver**，不是重新發現 namespace。〔復用 B02–B05〕

### 3.1 棧上 binder 的原始資料流

`596010` 起點以 `596038 mov esi,ecx` 保存原 page；但同時在 `596045` 將 `[ebp-20]` 寫成 **`C1920C`**，並清後續三個 DWORD。原 RTTI 是 `FUI::CFXUIBinder`。`596066` 產生 `page+B4` 的 destination 地址；`59606F lea edi,[ebp-20]` 才是傳入下一段的 owner。

`5A9F40` 的 ECX 是 descriptor，EDI 是上述 binder。它由 descriptor `v+10` 取得 `+C` window，由 `v+4` 取得 resource ID；`5A9F7A` 將 **EDI binder** 放入 ECX，再呼 `5A3840`。所以後者呼叫的 `+14/+18/+1C` 是 binder 方法，不能當作 page 方法。〔U01–U03；D01、D03；RTTI_BINDER〕

| 物件 | 本輪追到的欄位／方法 | 不可混用的地方 |
|---|---|---|
| page | `+B4` 保存 talk pointer；`+70/+74` attach/detach | page 不是 `5A3840` 的 ECX binder |
| 棧上 binder | `+4/+8/+C` 為待附加 window vector；`v+14=585690`，`v+18=404AA0`，`v+1C=585700` | 此 vector 不等於 Lua task queue |
| cached descriptor | `+4=212`，`+8` cache flag，`+C` talk pointer | resource ID、layout flag、window instance 不同 |
| `FAAFD8` cache manager | vptr `BFC9D8`；`v+28=44E120` 載入；`v+30=44E3F0` 移除 active entry | manager `+4` active map 與 `+14` descriptor registry 不同 |
| talk | `+18` root-resource owner、`+20` resource ID、`+24` UI context、`+60` attached page、`+9C` selected record | 相同 offset 不能跨物件直接解讀 |

`585690` 必要時呼 `44DFB0`，後者把 `FAAFD8` 寫成 `BFC9D8`，RTTI 為 `FUI::FXUICachingMgrCmdTarget`。這給出真正的 manager 型別和 virtual target，沒有停在「可能是一個 resource manager」。〔U04–U05；D02；RTTI_CACHE〕

## 4. resource 212 的來源已精確到一份 FTC

`585700` 由入參 ID 計算 `7*ID` 再乘 4，索引 **`E560B8 + ID*0x1C`** 的 wide-string object；容量欄大於 7 時取 heap pointer，否則取 inline buffer。對 ID 212，結果正是 **`E577E8`**。〔U06〕

原 BIN 的初始化 fragment：

```text
AD2991  push BEF0C8
AD2996  mov  ecx,E577E8
AD299F  call 402250
BEF0C8  L"UI/Component/TalkBox_Scenario_Panel.FTC"
```

`402250` 由 supplied wide string 初始化字串長度／容量；這個索引與 initializer 是同一 storage，並非只找到了名字相似的字串。這裡採正常 C++ 靜態初始化已完成的程式前提，不把 image 中該 storage 初始全零解讀成 runtime filename 為空。〔U07–U08；D11–D12〕

Master 原件又給出 `Master0z/UI/Component/AttachedPackage = UI/Component`，依既有 mount loader 接成 **`UI/Component.stp`**。PackingRules `ordinal=867`（0 起算），member offset `90777..90845`，extension slots 為 `ftc/fft/fcs/fis/fsd/etf/obj/空`，兩個旗標為 `[1,1]`，語意仍不命名。這是原件的精確 carrier 宣告，並非使用 `UI/LUA.stp` 或 `Field.stp` 猜出的對應。〔M01–M02；S009–S011〕

本輪可存取讀集仍沒有 `UI/Component.stp` 或該 FTC 的原始 payload；提供的本機 workspace 精確檔名查找沒有命中。這是已記錄材料範圍，**不聲稱使用者安裝目錄或所有歷史附件不存在此檔**。Master 宣告也不等於 runtime 已掛載、真正選到此份 bytes 或通過 UI reader。

## 5. 完整首載鏈到的是 native UI XML reader

### 5.1 manager 的三條路不能混在一起

`44E120` 先取 supplied window 的 `+4` instance ID，查 manager `+14` 的 descriptor registry。前稿 `597BC0` 正常配置成功後已用同一 `window+4` 登記 descriptor；這與 active map 的 resource ID 212 是兩種 key。〔U09；復用 B02〕

| 分支 | 真正執行路徑 | 成立條件／限制 |
|---|---|---|
| registry miss | `44E284 → 47F540 → 72F110`，成功後 `764520` | 通用 fallback；不是正常 descriptor 已登記的 talk 首載分支 |
| registry hit，descriptor `+8==0` | `44E1B7 → 764CF0 → 72F110`，成功後 `44E217 → 764520` | 本輪所追的正常 cached talk 第一次 layout load |
| registry hit，descriptor `+8!=0` | `44E245 → descriptor v+10`，取得 `descriptor+C`，再 `44E6C0` | 沒有重新開 FTC；回同一 cached window |

`764CF0` 轉換 path 並以同一 `TiXmlDocument` 呼 `72F110`；`72F189` 把 path 交 **`714770`** 開檔，成功才以 file object 呼 `72F260`，接著呼 file `v+4` 收尾。這是完整的檔名參數→實際 reader，不是以副檔名直接判斷用途。〔U09–U11〕

`72F260` 的既有 TiXml／EX 分流沿用先前完整 codec 成果；本輪沒有把通用 EX 解碼當成新的 MEF grammar。file parse 成功與下一步 UI ClassID/child deserialize 成功也分開判斷。〔S019；導航讀取 72F260／72EFC0〕

### 5.2 `CMDTARGET`、ClassID 和同一 root 的 receiver

`764520` 明確找 **`CMDTARGET`** 元素，讀 **`ClassID`**。有 supplied talk 時不需另呼 manager factory；`7645CF` 將 talk 放入 ESI，**`7645D1 mov [ebx+18],ebx`** 將 owner 設為自身，再呼 `776C60`。〔U12；D13–D14〕

`776C60` 再讀該元素 ClassID，與 receiver `v+4` 回值比較；相等才於 `776C94` 呼同一 receiver 的 `v+14`。talk 的 vtable 為 `C3EB44`，`v+4=40ECF0` 回 **53000**，`v+14=748C40` 是已完整分析的 inherited reader。ClassID 不相等會回 false，不能把任意 XML 塞給它當成成功的 talk 內容。〔U13、U18；D04；復用 B09〕

這條鏈沒有把 FTC bytes 直接交 Lua parser，也未取得新的本次 script filename/buffer。它閉合的是原生 UI 載入入口。

## 6. 前稿 owner 缺邊現在閉合，並有明確更正

前稿 §5.1 說 `749019` 的 receiver 是 `talk+18`，進一步寫成「它不是 talk 自己」。後半句超出當時證據。本輪已找到真正 upstream store，因此需依 [ERRATA.md](ERRATA.md) 更正：**在本條正常 root 首載路徑，`talk+18==talk`。**

完整關係：

1. `7645D1`：設定 root `+18=self`。
2. `748FF1`：reader 由原 root 的 `+18` 取 hook receiver；`748FF4` 先將 out-child 清 0。
3. `749013/749019`：呼該 receiver 的 `v+110`。
4. `C3EB44+110 = C3EC54 → 49AE10`；此方法只有 **`RET 0xC`**，不寫 out-child。
5. `74901B` 讀出的 child 仍為 0，走 `74902B → root v+60=746FE0 → 747000`。
6. `749044` 讓新 child 的 `+18` 繼承同一 root owner；其 ClassID 合格後才呼 child `v+14`。

此處是 void/out-parameter hook。不能誤稱 `49AE10` 「回傳 0」；它沒有設定 EAX。有效判定是 **out-child 先清零且 hook 沒寫它**，因此 fallback 成立。〔U12–U15；D05；復用 B09〕

這也不是全程式 `+18` alias 的普遍等式。別的 factory／load caller 仍須用其自己的 pointer provenance。新的確定結果只關閉這條已識別 root 的 custom hook。

## 7. 已前進到必要 child／dock；實際 layout 選取仍有精確缺件

### 7.1 四個 lookup 預期不能反造完整 FTC

前稿 `6BD4F0` 已證四個固定 child ID 與型別 helper。本輪把它們接到通用 factory 的原件 branch／jump-table／constructor：

| child ID | talk 儲存欄位 | helper 要求 ClassID | factory 與實例 |
|---:|---|---:|---|
| 1100 | `+84` | 200 | `7470F3`，alloc `0x158`，vptr `C49C6C`，RTTI `FoxUI::FXUIStatic` |
| 1200 | `+80` | 200 | 同上 |
| 2000 | `+88` | 1400 | `7476CA → 745040`，alloc `0xA8`，vptr `C4697C`，RTTI `FoxUI::FXUIPicture` |
| 2100 | `+8C` | 1400 | 同上 |

type 200：`ClassID-200` 的 compressed switch index 為 `7481F4[0]=0`，`7481BC[0]=7470F3`。type 1400：`ClassID-1301=99`，`74834B=1`，`7482D4=7476CA`。這些是原始 switch bytes 和選定 branch，不是只照反編譯 class name 推論。〔F01–F06；U17；D15–D22；復用 B20、B31–B32〕

Static 的 `v+14=75EB80 → 754C20` 接文字／樣式屬性；Picture 的 `v+14=744450` 先呼 base reader，再接 control reader。兩型的 `+104/+108/+10C/+114` 均指向 `5F5D10` 的單一 RET；`+110` 同樣是 `49AE10`。**這些是指定型別的槽位結果，不是所有 generic child 都沒有腳本的宣告。**〔U35–U38；D19–D22〕

目前不知道 FTC 是否真的提供這四個 node、是否有其他 node、各 node 的屬性與遞迴 children。BIN 中的 lookup 預期只能形成驗證條件，不能代替檔案內容。特別是 `74907E` 的 resource-selected child `v+14`、native text/image property 子圖與後續事件，仍須從實際 FTC rows 選出具體 receiver／參數後繼續追；不能用四個成功 lookup 的想像補成完整 layout。

### 7.2 dock factory 的小型有限集合已展開

原 root `v+64=746FD0 → 76E0C0` 只有三種接受值，其餘回 NULL：

| ClassID | 配置 | 原 vptr／RTTI | XML reader |
|---|---:|---|---|
| `0x103C4` | `0xC` | `C4D474`／`FXUIDockInfo` | `76E160`：numeric property 到 `+8` |
| `0x103C5` | `0x1C` | `C4D4B4`／`FXUIDockInfoLock` | `76E4F0`：numeric property，加既有固定矩形 reader |
| `0x103C6` | `0xC` | `C4D4F4`／`FXUIDockInfoOutter` | `76E160` |

factory 設定新物件的 instance counter 與基本欄位；兩個 reader 的直接目標是既有 numeric／rectangle helper，未出現新的 Lua content producer。這關閉前稿特別留下的 dock factory／reader 路徑。實際選哪種及其座標仍由 FTC 決定。〔U16、U39–U40、U44；D23–D25 及對應 RTTI〕

## 8. cache 重入不能當成新的劇情開始或成功確認

正常 descriptor 的 `+8` 初值為 0，getter `409510` 回此欄，setter `409520` 寫此欄。首載 file parse 成功後，`44E217` 呼 typed UI loader；其結果保存到 EDI，隨後 **`44E223 push 1 → descriptor v+C`**，這個 setter 前沒有檢查 typed loader 返回 pointer。〔U09、U19–U20；復用 B03〕

所以「descriptor+8 非零」只可按已證分支用作 cache 行為條件，不能單獨改名成「全部子元件、所有資產、所有 callback 均已成功」。本稿不以此推導實際載入失敗或可玩結果。

cache hit 的重入分支以 descriptor `v+10=5ADE20` 取同一 `+C` window，`44E6C0` 將 resource ID→window 放入 active map，寫 `window+20=212`，並將 pointer 加入 binder vector。上游 `5A3840` 清可見位、呼 window `v+94(0)`，`40B670` 才按 flags 做 native 初始化與 page `v+70` 附加。〔U03、U09、U32–U34〕

`40B670` 使用的 UI initialized bit21，與 descriptor `+8` 是另一個狀態。bit21 未設時才做 native `745590/745600`；後者呼 `v+108`、遞迴子樹，最後設 bit21。talk 的 `v+108` 是 RET；其 `+104` 是前稿已核的文字／style 方法。這些步驟沒有建立一個新的 script run ID，也沒有提供普通場景的 same-VM coroutine pump。〔U31–U32、U35、U45；D05；S012–S013〕

## 9. 真正 ordinary uninitialize 的取消／重入邊界

### 9.1 已接起具體 ordinary caller

本輪不只看一個泛用 remove 方法，而是由普通 page 的真實 vtable slot 接到 resource 212：

`CMissionFieldPage v+10C=5AD050` 與 `CScenarioFieldPage v+10C=5AFDC0`，都接到 `5AC500 → 599590 → 5A3CC0 → 5960B0 → 4095E0(resource 212)`。

這些上游窗口保留從真正函式起點到選定 call 的 prefix，未把 cleanup 中所有其他 UI 工作都納入本分題。實際頁面 uninitialize 被派送時，`5960F9` 明確 push `0xD4`。〔U21–U26；D08–D09〕

### 9.2 parent detach、active map erase、descriptor retention 是三個階段

`4095E0` 由 binder 找 active map 的 resource 212。window 非空且 `window+60` 非空時，以該 parent receiver 呼 `v+74(window)`。普通 page 的此槽為 **`746700`**：找到 list node，走 native state cleanup，將 **`window+60=0`**，傳播 UI manager pointer 0、解除相關 UI manager 關係，最後移除 parent list node。〔U27、U29、U41–U43；D06、D10〕

接著 `4095E0` 以 manager `v+30 → 44E3F0` 移除 active entry：

| 條件 | 動作 |
|---|---|
| active map 沒有此 resource ID | 回 false |
| window bit21 已設 | `745680` 先切換該位，再呼 window `v+10C`，遞迴 child tree |
| descriptor registry 以同一 `window+4` 命中 | `44E444 jne 44E45F`，跳過 window destructor，仍移除 active map node |
| descriptor registry miss | 額外 native cleanup，呼 window `v+1C(1)`，再移除 active map node |

正常 talk 的 descriptor 已由 `597BC0` 登記，所以在該 registry identity 沒有被另路變更的前提下，**普通卸下保留同一 descriptor/window**。其 `v+10C` 是單一 RET；之後重入回第 8 節 cache branch。descriptor destructor 與 talk destructor 的清除則是前稿另已核的回收鏈，不能與每次 page detach 合併。〔U28、U30、U35；復用 B02、B06、B35〕

因此已閉合的是 UI 的 attach→detach→cache reuse。它不證明任意 Lua coroutine 已停止、不證明所有舊 callback 已排空，也不是新的 owner generation。子樹 lifecycle 仍按實際 FTC 選定的 children 遞迴；本包沒有把未知額外 child callback 當作已全部核完。

## 10. B 還缺什麼，現在為何不能從這份讀集補成正例

| 缺邊 | 目前精確位置／已完成的排除 | 解除條件與接續動作 |
|---|---|---|
| resource-selected UI child／後續事件 | `74902B` factory 與 `74907E` child reader；root custom hook 已定型 no-op，必要兩型及 dock 已接實際 target | 取得同版 `UI/Component.stp` 或原選中 FTC，核 ClassID／node／property，才可選出額外 child vtable 和真正 callback |
| ordinary 本次 script 首次執行 | 本輪正向檔名只到 FTC/TiXml/native UI；沒有把本次 Lua bytes 送入 executor 的新 producer | 仍需一個普通可達的 filename/buffer/closure producer→有效 VM→first execute 鏈；不能自造一個 opcode 或把原指標 Rebind 當入口 |
| Q inactive 時持續 same-VM pump | native UI cache／`+108/+10C` initialization 是 UI lifecycle；已知 Q/T 的控制條件未改變 | 追到真正 ordinary frame/event owner 對同一 task 的 resume，而非只找到 generic per-frame 方法 |
| script owner／取消與重入 | 已證 UI window 會被保留；此 pointer 與 bit21 不是 script run token | 同一實際 script 入口的 owner writer、取消條件及重入順序；之後才可驗證 stale callback 是否隔離 |
| 普通 world/input/camera 全程保留 | 沒有完整背景執行鏈可供核全部 side effects | 在正向入口成立後逐段核 gate，再按允許流程做人測 |

阻塞不是「缺官方 Server 原始碼」，也不是泛稱「缺 runtime」。**目前缺失 FTC 正是攜帶實際 child 型別與屬性的來源；BIN 只有讀取機制與部分期望，不能還原未提供的 node 值。** 對更一般的 B 首次內容 producer，既有全域 Lua sink 讀集也只覆蓋已明列 E8/E9 和 literal 範圍，沒有證明 computed indirect call、其他模組或動態 global/metatable/registry 的全域不可能性。〔S016–S018〕

取得 FTC 後應直接從上述有限前緣接續，不重新掃 namespace 名稱或同一批 loader xref。Field／MapList／MEF grammar 的材料由同輪 P2 接續；它們和本輪 UI/Component 是不同問題。

## 11. Server 開發需求與整合建議

以下是本研究交接的相容性要求，不宣稱現有 Server 所有相關功能都尚未實作，也不假造官方 Server 內部規則。

| 類別 | 可直接執行的工作 |
|---|---|
| **Client 待逆向** | 補精確 FTC 並追實際 child/event；繼續查真正 ordinary script producer、pump、owner。未知 Client wire 不能轉嫁成 Server 可任意設計。 |
| **Server 開發需求** | 內容能力清單保留 `ordinary_B=false`；已證 Q/T 有限入口仍依原 gate 使用。Server 以 run／instance／generation 管理事件、取消、冪等及進度，不以 UI cache flag 或原始 pointer 當確認。 |
| **資源部署／跨功能整合** | 版本清單分開記錄 Master 宣告、真正選中 carrier/member hash、layout 驗證結果。新增 FTC 與舊資料採版本化檢查；按本輪四個 child ID/type 條件預檢，但不宣稱僅四個條件就是完整 layout grammar。 |
| **跨功能更正** | 採用 ERRATA 的 binder receiver 與 `root+18=self` 條件；UI/Component、UI/LUA、Field 各自維持 source/consumer，不合併名稱推定。 |
| **待遊玩驗證** | 原生正向背景入口建立後，才驗收走動、攻擊、相機、離圖取消及重入；本輪沒有 Client 執行結果。 |

玩家可理解的狀態是：**對話框的建立、收起和重用機制已更清楚；「戰鬥中常駐的新事件劇情」仍缺開始與持續執行的原生鏈，還不能說已可玩。**

## 12. 重跑與證據引用

```bash
python -B kr-extra-roy/MEF-P0-P1-P2-continuation-20261118/p1-entry/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --sources /path/to/project_sources
```

工具只讀來源，使用 `git show`／`rev-parse` 核 immutable objects，以 `objdump` 重新核 code windows，重算原件 SHA／VA→raw／逐指令 bytes，核 typed slots、關鍵 call/store、factory table、Master 的一份 member identity/hash 與一份有界 PackingRules 節錄，以及 897 筆 metadata row 的完整結構消費。M01 的 12 bytes 正好是完整 AttachedPackage member，因此只發布位置、長度、hash 與衍生 provider 名稱；verifier 在記憶體讀原件核對，不輸出完整原成員。沒有執行目標或任何解出的 member。

一般重跑應為 PASS；加 `--require-b` 時必須返回 **2／NOT_READY**，其 evidence checks 仍為 PASS，避免把研究重現與功能可用混淆。實際結果在 [verification-result.json](verification-result.json)。

| 引用 | 內容 |
|---|---|
| U01–U45、F01–F06、D01–D25、RTTI_* | [native-evidence.json](native-evidence.json) 的明確 code/data window；D07 刻意未使用，避免納入無關 slot |
| 復用 Bxx | 前稿固定 Git native-evidence 的指定窗口；本輪 verifier 再核原 BIN bytes，沒有重算成新 census |
| M01–M02 | [master-evidence.json](master-evidence.json)：M01 只有 AttachedPackage identity/hash 與衍生 provider；M02 是 92,450-byte PackingRules 中的 68-byte 必要 row 節錄 |
| S001–S086 | [source-manifest.json](source-manifest.json)：每一 Git source 的 immutable commit/blob/SHA |
| 研究讀集與未展開界線 | [read-set.json](read-set.json)、[candidate-contracts.json](candidate-contracts.json) |
| 更正 | [ERRATA.md](ERRATA.md)：舊句、原件反證與新條件 |

`artifact-manifest.json` 保存交付檔 hash；manifest 本身與 receipt 排除循環雜湊。本包沒有完整 BIN／STP、完整解包 member、可供執行的原遊戲腳本，沒有調整 Task owner、native_complete、RR 或正式驗收狀態。
