# Master 原件、P0 資源掛載與實際載入器閉合分析

日期：2026-11-17（Asia/Taipei）。工作 branch：`extra/roy1`；來源基準 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa`。原件僅讀，未執行 Client、Lua、封裝內程式或 Server。

## 1. 本輪結論與完成邊界

新提供的 `Master.stp` 已實際取得、逐 member 解碼、獨立重走完整索引。**「缺 Master 原件、無法知道掛載宣告」這一項已閉合**。899 個 member 包含 897 個 `AttachedPackage`、1 個 `EncFlag`、1 個 `PackingRules`；897 個 binding 與 897 筆 PackingRules 全部一對一相符，沒有未消費尾端 bytes、重複 ASCII casefold 虛擬目錄或同名 carrier。[M1–M3]

同時補上上一輪特別保留的實際 render loader 缺邊：兩個已取得模型的 base mesh 在條件成立時改取 `.emf`；Prolog／直接 image 及 model TextureList 的實際 consumer 在原路徑 probe 為零時改取 `.etf`。這次有真正的 caller、receiver、分支與原 BIN bytes，已不再只是另一條驗檔路徑或 PackingRules 副檔名的類比。[N1–N5]

**Master 沒有增加模型、FLD、圖片或聲音 payload。** 原兩場景的 132 個已到達 dependency node 已全部重新接到新掛載資訊；108 個原前緣仍有原件／選取 context 未滿足。其中 17 筆舊的「缺 Master」說明已被本輪新事實取代，其他缺口逐條保留。13 個模型 descriptor 原件依然未取得，因而也不能捏造其尚未展開的後代。[M4–M5]

這份成果的完成單位是完整 Master 宣告、選定資源路由與載入分支的有界靜態分析，不是完整 P0 payload ready、整個 Client 的語意驗收或遊玩通過。現行 `resource_ready=false`，`--require-ready` 必須回傳 2。[V]

## 2. 原件身份與完整索引

| 項目 | 實際讀取結果 |
|---|---|
| 上傳名稱／本機載體 | `Master.stp`／`11-Master.stp` |
| bytes | 1,094,887 |
| SHA-256 | `f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d` |
| 外部檔頭 | `STPD` |
| 內部 root | `Master0z`，kind 2 |
| 完整索引節點 | 1,808：899 files、908 directories、1 root |
| AttachedPackage | 897，全部 materialize 並保留 offset／block ID／長度／hash |
| PackingRules | 92,450 bytes；SHA `692ebd0e3cf89e64ed7b504c761c3f754d0b24dd2fa0279d2c6d1ea43e1eb0a0` |

沿用已固定 SHA 的 STPD reader；另寫獨立、有界限的樹走訪，比較所有 path／block ID 與完整消費位置。只把 member provenance、hash、必要選取關係與本輪新增的分析程式放 Git；沒有上傳 Master 原檔、完整解出 member 或完整 PackingRules 原文。[M1–M3]

PackingRules 的本檔實際資料形狀為 `u32 recordCount`，每筆接兩個 `u16 length + ASCII bytes` 字串、兩個 byte、八個長度字串。897 筆走到精確 EOF；第一個字串對上 AttachedPackage carrier，第二個字串正規化後對上虛擬目錄。兩個 byte 的用途保留為 `UNASSIGNED`，不替它們命名成壓縮、加密或遞迴開關。副檔名字串是本檔觀測到的 extension slots，不擴充成封裝工具的完整輸入規格或原生 MEF grammar。[M2]

### 2.1 `EncFlag=5` 不能代入 `EncSetting`

本 Master 只有 `Master0z/EncFlag`，4 bytes little endian 值 5，沒有 `EncSetting`。原 BIN `713740` 在 `713819` 傳入的明確字串是 `C44168: EncSetting`，`717410` 做指定 property name 的查找；找不到時 `71386A` 使用先前設成 1 的 local value。root 中其他 file 不會因值也是整數便自動取代指定 property。[M2；N1]

因此本輪可以確定宣告資料與所查 property 不同，並閉合此查找的 default 分支；**不能把 EncFlag 的 5 描述為 native EncSetting**。本輪也沒有為 EncFlag／PackingRules 推定其他未識別 consumer。

## 3. 掛載路由與選檔要分開

原生已知鏈仍是 `48BD30 → 713740 → 7135B0`。每個目錄透過 `714D50` 註冊／重用，`AttachedPackage` 作 carrier basename，`715620` 加 `.stp` 並嘗試開啟；只有成功分支才將 provider 寫入虛擬目錄。新 Master 沒有重複 ASCII casefold 目錄，所以這份宣告本身沒有同目錄覆寫競爭；缺失 carrier 或開啟失敗的實際結果仍未觀測。[N1；M2]

`714C50` 是**父 provider 先查，父查不到才遞迴子目錄**。例如 `Character/Mon/Avatar/02_Stoncken/...` 會先經 `Character/Mon/Base.stp` 的 provider，再於 miss 時落到 avatar provider。不能把它實作成只取最長 prefix 的路由器，也不能跳過已掛載父 provider 中可能存在的檔案。[N1；M4]

| 已由 Master 指定的虛擬目錄 | 指定 carrier | 本輪材料狀態 |
|---|---|---|
| `Event` | `Event.stp` | 已有原件，root `Event` 相符 |
| `Table` | `Table.stp` | 已有原件，root `Table` 相符 |
| `Map/BoundMap` | `Map/BoundMap.stp` | 已有原件，root `BoundMap` 相符 |
| `Character/Mon` | `Character/Mon/Base.stp` | 已有的 `Base.stp` root 為 `Mon`，是結構相符候選 |
| `Character/Cha`、`Character/Npc`、`Character/Obj` | 各自的 `Base.stp` | 三個不同完整路徑；不能用現有 Mon/Base 代替 |
| `Character/Mon/Avatar/02_Stoncken` | `Character/Mon/Avatar/02_Stoncken.stp` | carrier 原件未取得 |
| `Character/Mon/Avatar/00_Alphonso` | `Character/Mon/Avatar/00_Alphonso.stp` | carrier 原件未取得 |
| `Image`、`Image/Prologue` | `Image/Base.stp`、`Image/Prologue.stp` | carrier 原件未取得 |
| `Field` | `Field.stp` | 有明確掛載宣告；完整 carrier 未取得 |
| `Map/MiniMap` | `Map/MiniMap.stp` | carrier 原件未取得 |
| `UI/Component` 等 10 個 UI 目錄 | 對應 10 個不同 UI carrier | 具體 mapping 已列在 M2 |

前四個原件的結構配對可以重驗；尚未觀測使用者實際安裝的 deployment pathname／覆寫來源，不以結構相符取代 installed-byte identity。本輪再次讀取上一輪的 50 個 selected STP member，逐一比對原 metadata／decoded SHA；沒有重新跑完整 Event 或 ABI census 充當新進展。[M4；V]

### 3.1 十五模型的最小下一批材料

Master 的同 stem avatar 目錄讓補件有明確搜尋目標，但 **Actor.FILE basename 與 avatar 目錄同名，仍不是 CHA_ABF cache 已選到該 descriptor 的證據**。`selected-resource-routes.json` 對每個模型保留這項條件，`native_selected_path=null`。[M4]

- 1086／`02_Stoncken` 與 102／`00_Alphonso`：已解析 Mon/Base 中的 descriptor。若 CHA_ABF 選到這些原件、entry directory 為 `Character/Mon/`、resource `+F4=0`，則 prefix 可具體化為 `Character/Mon/Avatar/<RelativePath>`。
- 1478–1486：Master 給出 `Character/Npc/Avatar/N01_Soma` 到 `N09_Epds`。需 `Character/Npc/Base.stp` 的真正 descriptor，再展開每筆 RelativePath／BaseFile／動作／材質。
- 10107、10320、10323：同樣需 Npc/Base 中的 `07_Mimi.abf`、`14_Alster.abf`、`14_Tommy.abf`，avatar 指向也已存在。
- 2064：需 `Character/Obj/Base.stp` 的 `11_SupplyCabH.abf`，再接 `Character/Obj/Avatar/11_SupplyCabH.stp`。
- 九個顯式附件與十五模型的 default attachment attempt 都由明確 `Character/Cha/Items.ipk` 起步，故原件需求是 `Character/Cha/Base.stp` 及其實際 Include／所選後代。default descriptor lookup 合法 miss 的舊原生邊界不變，不能用 missing default attachment 自動判場景失敗。

兩個 FLD basename `mushroom12D.fld`／`town014S.fld` 仍需真實 MAP_FLD entry。**Field 的 extension slots 是 `xml`、`mef`，不提供這兩個 FLD 的完整路徑**；`town014S` 也不因鄰近名稱而與 `town014` 合併。[M2、M4；既有 P0 resource report]

## 4. 新增的真正 render loader 分支

### 4.1 Base mesh：`.gb3`／`.emf` 有條件選擇

先復用 descriptor directory／RelativePath／BaseFile 的上游證據，再沿真實 base reload `7C4310 → 7D0920` 追到 `79BCE0`。`7D0920` 先查 resident mesh record；已存在且狀態可用時可直接取得它，不能假定每次 acquire 都會讀檔。首次需要物理載入才進下表分支。[N2]

| 條件 | 選出的 path／loader |
|---|---|
| manager `+300` 即 `FB79A8` 為 0 | 保留原檔名，`7CBEE0` |
| `FB79A8 != 0`，且 `714550(original) != 0` | 保留原檔名，`7CBEE0` |
| `FB79A8 != 0`，且 `714550(original) == 0` | 保留 drive、directory、stem，改 `.emf`，`7CBF70` |

`FB79A8` 由 normal `798DE0` 的 `716440` 結果設定；後者明確開 `fcs.flu`。這讓 fcs 不只是 basename 索引來源，也影響此 mesh loader 的 packed 分支。兩種 selected path 最終都開 `714770`；packed 路徑另經 `7CC000`，本輪未取得被選 mesh bytes，故不宣稱檔案格式或 render 成功。[N2]

這項證據限定真正跟到的 base mesh consumer，沒有把它無條件外推到所有 animation、ASD、音效或其他引擎格式。兩個已解析 base reference 新增可核對的條件候選 `Stoncken_BASE.emf`、`Alphonso_BASE.emf`，不把修改副檔名視為資源已存在。[M4]

### 4.2 Image texture：`.dds`／`.etf` 不是任意 fallback

Prolog 的上游 `55F370 → 736B00` 已固定；本輪把 `736B00` 建出的 secondary vtable `C4583C` 的 `+4` 精確讀成 `73ABE0`，追到 `737D40` 的 image-info adapter，再於非負結果時進 `737F40` 的 texture-create adapter。後者也呼叫相同 `737D40`。[N3]

Q2440/5 的 direct FlyingImage 有另一條獨立 consumer：`560030 → 734330 → 7340C0 → 737D40／737F40`。它的 path 與第二參數 0 由 `56005B` 傳入；`734387` 再以 path／0／新 texture object 呼叫初始化。`7340C0` 不檢查 image-info return 就繼續 texture-create，所以前段「非負才繼續」只適用 Prolog 的 `73ABE0`，不能套用到 direct image。[N3]

`737D40` 先呼叫 `714550(original)`。非零時直接使用原路徑 file adapter；零時才由 `714AA0 → 714970` 保留路徑與 stem 改成 `.etf`，再以 `714770` 開啟。讀入後有 `716EB0` 條件解碼、transform，並把 buffer `+8`／length `-8` 交 memory adapter。未提供 payload 時，這只閉合「哪個檔名、哪條載入分支」；不能證明 header／資料長度／圖形 API 接受結果。[N3–N4]

**原路徑 probe 成功但後續 decode／adapter 失敗，不會因這個失敗自動回頭試 ETF。** 亦需 graphic device／owner 初始化等入口前提。新資源預檢不應單獨用 DDS 缺席判 missing，也不能無條件將每個 DDS 改名成 ETF。

### 4.3 Model texture 也有實際 consumer，並非只看到 image helper

已公開的 model TextureList 上游把 key／完整 path 送進 `FE1AE0`。本輪固定 normal `7BB970` 的指標安裝為 `7BC2C0`，該函式複製 key／path 進同一 manager 的 request queue `+34`。實際 caller `7AAD40` 於 `7AAE50` 檢查 `FE1AC0` 初始化旗標，必要時呼叫 `7BB970`，再於 `7AAE7B` 把同一 manager `FE1AC8` 傳給 `7BBB90`。後者建立 worker `7BCA20`，worker 從該 queue 取 path 並以 texture adapter 呼叫 `737D40`。因此這條 model texture consumer 的 ETF 分支有獨立的 queue／worker／receiver 來源鏈。[N5]

worker 在 selected attempt 後把 texture-record `+1C` 設為 1，包括載入沒有成功的分支。**這個 processed 位不是 texture success，也不是全場景 queue-drain ACK。** 沿用 P0 lifecycle 的 owner／世代與結束邊界，不用它偷換 render 驗收。

也已核到真正 adapter 終點：model worker 寫入 `C455F8`，其 `+4 → 737F00`；image texture-create 用 `C45604+4 → 738000`。兩者都呼原 PE import `BD2624 = d3dx9_32.dll!D3DXCreateTextureFromFileInMemoryEx`。image-info 的另一張表 `C45610+4 → 738070` 則到 `BD2628 = D3DXGetImageInfoFromFileInMemory`。這些 vtable、葉函式及原 import descriptor／ILT／IAT／name 均保存原件窗口，足以區分資訊查詢與 texture 建立的 consumer；仍沒有執行 DLL 或觀測 device／payload 接受成功。[N3、N5]

兩個 model texture、十筆 Prolog picture reference 與一筆 direct image，共 13 筆 conditional ETF request；另加兩個 base mesh 的 EMF request，合計 15 筆，去重後是 12 個不同 packed path。全部已接上 Master provider 候選，全部仍要求實際載體 bytes 與選取結果。[M4；V]

## 5. 聲音、MEF 與未宣告路由

Master 的 Sound 子樹只宣告 `Sound/Scenario/00` 到 `12`，以及 `Sound/Scenario/Prologue`。native Talk voice 候選遍歷仍是 32 到 0；本 Master 沒有 13–32 的 provider 不等於 those version 已全局不存在，因為還有既有 loose-source／前綴條件，不能把 source declaration 的缺席擴張為安裝缺檔。[M2、M4；既有 P0 voice consumer]

`Sound/BGM024.ogg`、`BGM147.ogg`、`BGM148.ogg` 與選定 Stoncken 音效沒有對應的 Master provider。這次會要求原音效檔或有效原安裝來源，**不發明 `Sound/BGM.stp`／Monster 包名**。132 個 node 中有 122 個能得到至少一個已宣告 provider；其餘 10 個包括仍待 group entry 的 FLD 或沒有 provider 的已知 sound path。122 不是成功載入數。[M4]

Field 規則第 879 筆的 extension slots 實際出現 `xml`、`mef`，並有 `Field → Field.stp` 的 AttachedPackage。這是本輪新取得的真正原件線索，足以把下一批 carrier 收斂到 Field。Master 內自身沒有 `.mef` 或 `.lua` member；UI/LUA 的規則有 `lua` slot，另指 `UI/LUA.stp`。這些都不能證明 MEF 內容格式、傳送 opcode、首次 script entry 或普通場景的同 VM pump。[M2；與 sibling entry-b 合讀]

對本輪新定位的 Field／Stoncken／Prologue／UI Lua 原件做精確 title 搜尋及一次簡化檢索，未取得新封裝；只找回已在用的同大小 Base 和既有研究文件。這是本輪可存取材料的界線，不是對使用者磁碟／所有歷史附件的全局不存在判定。完整 Master 已使用提供的本機副本，不因搜尋介面未列出而否認它。[A]

## 6. Server 可直接採用的開發需求

以既有 REQ-0019／REQ-0021 的版本化內容前置條件對接下列設計，正式收件／接受仍由 S00 處理；本研究不變更狀態。

1. **資源版本清單**：固定 BIN、Master、fcs 或等價 scan inventory、實際載體與所選 member hash。Master 的宣告和已觀測成功的 runtime binding 分成不同欄位。
2. **保留實際路由規則**：父 provider 先查、子 provider 後查；basename cache 第一筆保留、Actor admitted ID 最後賦值等既有不同規則分別記錄，避免用單一 dictionary 策略代替三個 resolver。
3. **加入 consumer 特定 packed policy**：base mesh 與 texture 的條件各自建模；原路徑存在但 decode 失敗，不能臆造 native 第二次嘗試。Server 的 preflight 結果使用 required／optional 視覺政策，但不能改寫 Client 已證行為。
4. **queue processed 與內容完成分離**：model texture processed flag、場景 End、003F、qco 消失與全資源成功／排空是不同觀測。Server 自己維護 run、entity generation、取消與去重的生命期要求。
5. **原件缺口精確補件**：Field／fcs、三個 category Base、指定 avatar／圖片／語音先於全遊戲擴掃；取得每份 descriptor 後只追本場景實際到達的後代。Server 劇情、戰鬥權威、事件路由、獎勵策略等由 Server 開發承擔，不等原版 Server 內部規則逆向。

## 7. 驗證與引用

本輪實際 replay：7 份原件、34 個固定 Git source、899 個 Master member、1,808 個獨立索引 node、897 個 rule join、50 個前輪 selected member、23 個新增 native window（10,275 bytes／3,128 instructions）、14 個既有 window、4 個原生字串、5 個 typed vtable record、2 個原 PE import。三種 PackingRules 截斷／尾端多 bytes／錯誤 count 的 analyzer 負例均拒絕。上述都是有界分析工具及來源檢查，未執行目標。[V]

| 引用 | 檔案／範圍 |
|---|---|
| M1 | [source-manifest.json](source-manifest.json)：Git commit／blob／SHA／bytes 與原件身份 |
| M2 | [master-summary.json](master-summary.json)：完整計數、51 個必要 provider、selected rule facts |
| M3 | [master-member-evidence.json](master-member-evidence.json)：全部 899 member 的位置／hash，不含 payload |
| M4 | [selected-resource-routes.json](selected-resource-routes.json)：132 node、15 model search target、packed 分支與條件 |
| M5 | [p0-frontier-delta.json](p0-frontier-delta.json)：108 個前緣的新舊差異 |
| N1 | [native-evidence.json](native-evidence.json)：Master property／reused mount windows |
| N2 | 同檔：mesh path、acquire、兩種讀法、cache flag／fcs reader windows |
| N3 | 同檔：image typed ctor、load、texture create adapter、common read |
| N4 | 同檔：texture rewrite wrapper／body、`.etf` 字串 |
| N5 | 同檔：model texture init、enqueue、worker start、worker |
| V | [verification-result.json](verification-result.json)、[verify_evidence.py](verify_evidence.py) |
| A | [../source-availability.json](../source-availability.json)：本輪有限搜尋範圍 |

原 T01 20261117 審查已重跑前輪來源，保留 bounded／PARTIAL 的整合邊界；本輪來源固定在該版後接續。沒有改寫舊報告、正式 Task owner、native_complete、RR／S00 驗收或 gameplay 狀態。
