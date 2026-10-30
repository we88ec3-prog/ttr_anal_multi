# T01 — KR T10 主張整合接續：early/middle R1 交叉裁決、Phase Writer / Reader / Reset / Local Command 原生定向 R2

**交付狀態：階段性完成（40 組候選已交叉整理；127 篇 canonical 登記尚未完成）**  
**研究對象：** KR `Tartaros.bin`（12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`），`Tartaros.exe`（2,594,816 bytes；SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`）。原件唯讀，沒有執行、patch、附加遊戲，沒有原版 Server 或 wire capture。  
**GitHub 基準：** `we88ec3-prog/ttr_anal_multi`，`main@5a38070c762855b73f5fb563f0e673df5e1f940f`。這是**本地完整交付稿，尚未 Commit/Push**；使用者本輪要求「繼續驗證與整合」，未明確指示 Git 提交，本輪遵守共用 02 規範，只在本機保存。

## 1. 開工依據、工作目標及交付範圍

已核對當時最新 main、`AGENTS.md`、`kr/tasks/T01/{README.md,task.json}`、T10 README 既有原生退回、`research/dispatch/inbox/T01.md` 與 `research/requests/index.json`。T01 收件箱有 RR-0001/0003/0004/0006/0007 `IN_REVIEW`，但本次因延續使用者上一輪指定的 T08/T10 合併與驗證整合，優先處理 **T10 canonical 整合未完工作**；未替 S00 結案或修改 T02/T03 原稿。T10 沒有本次派遣的 S00 RR，`RR-0002` 等 T03 流程也不屬 T01 可代為研究或結案。

**來源及前情：**

- [T10 前次 T01 階段保存](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/handoffs/t01-t10-roy-20261029/README.md)：127 篇 T10 完整來源已 R0 登記；49 early、44 middle 原稿在舊輪已有具體 R1 source-level proposal，34 late 尚無完整提案；舊索引當時未完成 canonical。
- [early/proposal.json](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/handoffs/t01-t10-roy-20261029/early/proposal.json)：blob `6cdb8a3a1232e19f7fa42ef9df2c4872713beab9`，49 篇來源、24 個候選群；原作者/前次 integrator 在該檔記錄具體 source_refs 與 conflict handling。**本輪重讀 proposal 結構、40 群的 assertion、level、衝突與 reuse，不等於重新全文閱讀全部 93 篇來源。**
- [middle/proposal.json](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/handoffs/t01-t10-roy-20261029/middle/proposal.json)：blob `c2040f02c7f5d9f431ec5d17aa6749960242a193`，44 篇來源、16 個候選群；保留既有 rejected scope。
- [T08/T10 合併與前次四條有界主張](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/research/handoffs/t01-20261030-t08-t10-branch-merge/20261030-151422-chatgpt-web-roy-T01-T08-T10-merge-bounded-R2.md)：blob `e468599ffb45167e29730669330dfc800e869d95`；`SRC-0363/0379/0383/0384` 已 `CONFLICT_CHECKED`，對應 `CLM-COMBAT-0001..0004` **PARTIAL**。本輪不要重建同一四條。
- [既有作者更正及 T01 退回](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/tasks/T10/README.md)，以及 `shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md`、`shared/integrations/T01-20261029-continuation-02/t10/decisions.json`。舊 `FAILED`、`NEEDS_FIX`、`NEEDS_QUALIFICATION` 不因新文件或抽樣機器碼通過而改狀態。

**本次研究終點：** 先為 early/middle 的 **40 個提案群**找出可相互復用、衝突隔離、需原生 R2 的精確界線；實際抽取 KR BIN 驗證 phase writer、reader/reset 分離、>500 計時、WORD output slot、internal command68、既有 C2S000A / S2C key13 核心界面。未讀全量 source 的相應部分保持 `R1 CANDIDATE`，不得將下述「合併候選」一律升為正式 `CONFLICT_CHECKED`。

## 2. 證據驗證工具及內容

本輪重新計算原件 SHA256；以 PE `.text` VA `0x401000`/raw `0x400` 得 `raw=VA−0x400C00`；`.rdata` VA `0xBD2000`/raw `0x7D0600` 得 `raw=VA−0x401A00`。使用 Python `hashlib`、`struct`、GNU `objdump -D -b binary -m i386 -M intel`，*不用錯位視窗的假指令當證據*。`FBxxxx`／`FExxxx` 等 runtime global 不可直接套 `.text` 映射取得初始化值。完整位元組區段 SHA256、十多項機器碼 assertion、vtable 結果在同批 `T01_T10_20261030_native_validation.json`；重現用 `T01_T10_20261030_verify_native.py`。

### 2.1 非零 phase writer 的存在：先前缺口的精確更新

**已確認的局部鏈**：

```asm
4914AC  B9 30 88 FB 00         mov ecx,0xFB8830
4914B1  E8 CA FF 23 00         call 0x6D1480
6D14AB  8B F9                  mov edi,ecx
6D1915  8B 45 B8               mov eax,[ebp-48h] ; 保存的 this
6D191B  05 D4 07 00 00         add eax,0x7D4
6D1920  BE 08 00 00 00         mov esi,8
6D1925  8A 48 D8               mov cl,[eax-28h] ; 先前位置狀態
6D1928  3A 4A FF               cmp cl,[edx-1]  ; 新取樣 byte
6D1930  83 C9 40               or ecx,40h     ; 變動分支
6D1933  C1 E9 06               shr ecx,6
6D1938  C1 E9 06               shr ecx,6     ; 相等分支
6D193B  83 E1 02               and ecx,2
6D193E  88 08                  mov [eax],cl
6D19AF  83 C0 05               add eax,5
6D19B5  4E                     dec esi        ; 共 8*5 = 40 bytes
6D19B6  0F 85 69 FF FF FF      jne 6D1925
6D19CD  F3 A5                  rep movsd      ; 另存 40-byte state
6D19CF  8B 8B 10 08 00 00      mov ecx,[ebx+810h]
6D19D5  2B 8B 0C 08 00 00      sub ecx,[ebx+80Ch]
6D19F2  88 8C 13 D4 07 00 00   mov [ebx+edx+7D4h],cl ; record override
```

`0x6D193E..6D19B6` 中比較 old/new 高位 `0x80` 時，phase 被合成為 0/1/2/3：相等時保留 previous high-bit → 0/2；不同時 OR 0x40，shift 得 1/3（**這是由機器碼算式推得的局部相位編碼，不等於特定物理鍵或輸入模式的完整語義**）。繼而 `+0x80C/+0x810` 的 8-byte entries 以 entry DWORD 作索引、entry+4 byte 作覆寫值，**可能蓋過該相位計算**。這是 prior `middle-phase-writer-gap`、`early-writer-search-boundary` 不能再泛稱「原始 BIN 沒有 nonzero writer」的直接證據；其原 proposal 的歷史時間點和研究限制保留。

**仍未知：** 此覆寫 vector 的全部 producer、索引是否合法、有無上游 bound/check、real-time active bank、Key44→ID13 是否在當次事件有效，以及 `5961C0` 和 controller 的完整同 tick consumer。不能只在本地 `6D19F2` 看不到 index guard 就報成可利用的安全漏洞。`6D1480` 每條例外/return 尚未全文 R3。

### 2.2 reader 的兩種域，與 reset 的 ABI 不混用

```asm
6D4D05 lea eax,[esi-0x2711]       ; 0x2711 = 10001
6D4D0B cmp eax,0x270E           ; 0x270E = 9998
6D4D15 ja  6D4D70              ; unsigned out-of-range
6D4D45 mov ecx,0xFDF630        ; 10001..19999 special tree
6D4D4D call 0x82EF00
6D4D93 cmp esi,0x27             ; normal 0..39
6D4D96 ja  6D4DAE              ; out-of-range returns zero
6D4D98 movzx eax,byte [esi+0xFB9004]
6D4DAE xor eax,eax
```

`0x6D4CE0` 是查詢：index 在 10001..19999 時查特殊樹 `FDF630`；其餘落在普通域 0..39 時讀 `FB9004[esi]`；其他值回 0（不把 `0..39` guard 擴張到其他函式）。在 `0x6D4A30` reset 路徑中：

```asm
6D4A5B cmp byte [ebp+8],0
6D4A62 je  6D4B0A                ; 兩支不同的 reset 分支
6D4A93 xor eax,eax
6D4A9C mov dword [FB9004],eax
6D4AA1 mov dword [FB9008],eax
...                             ; 每 4 bytes store 一次，至 FB9028
6D4AC9 mov dword [FB9028],eax   ; 10*DWORD=40 bytes
6D4AEE mov edi,0xFDF630
6D4AF3 call 0x823850            ; special tree reset route
6D4B69 xor eax,eax              ; 另一分支也有普通清零
6D4B6B..6D4B98                  ; 同樣 10 DWORD zero
```

`0x6D4CAE` 是 `0x6D4A30` 內部的位址，**不是與 6D4CE0 同函式**，不能搬用 reader `cmp esi,0x27`；也不能在未核對跳分支與同執行緒狀態前，把 062 稿的特別初始化早於普通清零排列當作通用 reset 時序。現有 `T01-RETURN-T10-062-001`／`063-001` 更正保留。reset 何時呼叫、每次 UI 模式如何切換仍未完全驗。

### 2.3 500 數值嚴格大於，不是普攻 cancel/window

`0x547240` 讀取 global `FB9014`（透過 `0x547290`），依 `[esi]` state 0..3 跳 `0x547370` 表（四項目標 `5472A7,5472DB,5472F6,54734B`，本輪 raw DWORD 驗證）。在其中一條有條件狀態：

```asm
5472FF call dword ptr [0xBD25A0] ; 既有稿以 import table 識別 timeGetTime
547305 sub eax,[esi+4]
547308 cmp eax,0x1F4            ; 500
54730D jbe 54735E               ; <=500 不觸發該轉換
54730F mov [esi+4],edi
547317 mov dword [esi],3
```

這支持「以 unsigned 差值 **嚴格 >500** 轉移」的有界 Client 靜態條件。沒有將其綁定 Key44、Z連段、V長按或原版 Server 的 combo timing。對 wraparound、全部 jump-table 分支及 import 名稱依存舊審核，非新全文認證。

### 2.4 既有退回的指令邊界：兩條原生反證重現

- `0x5467F1 8B 55 10` 是 `mov edx,[ebp+10h]`，**真正的 WORD store** 在 `0x5467F4 66 89 1A`；舊 007 不能把 `5467F1` 當作 store 地址。`early-input-merge` 的有界 bit 合成不因此全面作廢，但錯位地址的主張仍必須排除。
- `0x59642E E9 7A 01 00 00` 是跳到 `5965AD` 的 5-byte JMP，`0x596430` 落在 immediate 中；真正 `call 6D4CE0` 是 `59643F E8 9C E8 13 00`。這直接重現 `T01-RETURN-T10-056-EVIDENCE-001` 的假 CALL 問題。錯位視窗的 bytes 存在不代表錯位反組譯已成真正控制流。
- `0x6D4BAC C7 45 FC 04 00 00 00` 是 7-byte DWORD write，`0x6D4BB0` 在 immediate 內；直到 `6D4BC2` 才是獨立 `add esp,4`。沿用 T10-055 限定修正，不以 `6D4BB0` 為有效指令起點。

### 2.5 local command68 與 C2S000A 是不同命名空間

`0x548918` 的 loop：`ESI=0x1C` (28)，每次 ESI++／EBX++；`5489B0 cmp esi,0x26`、`jl 548920`，因此正常迴圈檢查 28..37（10 項）。`548957 movzx eax,byte [esi+FB9004]`，`54895E cmp eax,1`，`54897E cmp [FBA798],0`，`548985 mov ecx,0x68`，`54898D` 寫 WORD 0x68、`548992` 寫一個 byte，`548998..5489AC` 只在 gate 合格呼叫 `FBA854 vtable+10`，傳固定 selector 0、指向局部資料及長度 3。這些是 **internal local 0x68 建包／條件送出**，不是普攻十連段，且不能與 `0x000A`（`0x5452C0` 的另一應用封包）或 `S2C key13` 等同。既有 T10-115 已見 `000A` 頭 6 bytes、每 row 5 bytes；T10-119 的 key13 每 row 9 bytes、actor virtual+58；T10-120 的七張表 +58 指向 `4C8C30` 寫 actor+B0。以上現有四條 CLM 已登錄，本輪只交叉驗證，**沒有新 Server ACK/cancel/motion 因果**。

## 3. 40 個 proposal 群的本輪跨 early/middle 去重決議草案

下表的「採納」只表示可作為**來源限定、已查衝突的 canonical 候選**，不是已將 93 份來源全量升級或建立正式 claim。本輪以兩份 proposal 的 `source_refs` 精確路徑、blob、行號作權威來源；以下群組名稱保留原始原稿 key，沒有抄寫成新研究段號。類似的描述合併導航，但必須保留各群不同的函式、物件和 source subset。

| 候選功能分群 | early group key | middle group key | 裁決與關鍵限制 |
|---|---|---|---|
| A. phase 非零 producer / writer | `early-writer-search-boundary` | `middle-phase-writer-gap` | **歷史 UNKNOWN → 新的局部非零 writer 已找到**，參照 6D1480/6D19F2；但 device→active bank→caller 全鏈仍 PARTIAL，不能把原未知記錄直接翻為全程 confirmed。 |
| B. ordinary/special byte reader | `early-state-reset-read` | `middle-state-reader` | 採納 6D4CE0 有界 read，0..39 與 10001..19999 分域；和清零、phase writer 分離。 |
| C. ordinary reset / indexed clear | `early-state-reset-read` | `middle-state-clear` | 採納 6D4A30 局部 reset；062/063 已 REFUTED 的跨函式 guard／順序不得進 canonical。 |
| D. timed state sampler | `early-timer` | `middle-state-flag-boundary` | 採納 547240 >500；**不得**轉義為 combo/cancel/V 行為窗口。 |
| E. 3-way bits and physical input composition | `early-input-merge`, `early-direction-synthesis`, `early-pointer-branches` | `middle-state-flag-boundary` | 保留 546780/546850/546B50/546D50 的各路輸出及方向合成，不能全稱 Z；007 store 位址 5467F4。 |
| F. bank layout / work bank | `early-bank-layout` | `middle-working-bank` | 3 個 0x280-bank、bank2 runtime workcopy 是候選，不能等同 XML Type2；當前玩家 active bank 需再驗。 |
| G. XML loader and fallback | `early-keymap-loader` | `middle-xml-resource` | 6D08F0、KeyMapping Type/Key/MapButton/ModKey；來源 defaults 不等玩家實際操作，不能自行填成 Z 普攻設定。 |
| H. query-to-vector and map formatting | `early-mapping-query`, `early-vector-copy` | `middle-mapping-query`, `middle-mapping-format` | 保留 6D4DC0 lookup、4A8680 append-copy、594610/594A80 format 三層，不把格式化視為 phase writer；special branch 可 lookup-or-create，不冒稱唯讀。 |
| I. external config pairs | `early-bank-layout` | `middle-external-pairs` | 6D0D10 外來整數對與 bank2 vector 是資料初始化候選，無完整使用者存檔實體/格式結論。 |
| J. polymorphic UI/action consumption | `early-phase-routing` | `middle-polymorphic-consumer`, `middle-fb73e8-mode` | 5961C0 / 59624E 等讀取 byte、按 actor vtable +EC/+F0 判斷；FB73E8 僅 ID13/14 局部，不能推所有 motion/cancel 已閉合。 |
| K. command68 | `early-command68` | `middle-command68` | 本輪重新以 BIN 確認 548918 的 28..37、狀態 1、FBA798、local 3-byte 0x68；不是十連段，也不自動成 Server 特定 ACK。 |
| L. command22 local interface | `early-command22` | — | 保留 FB9015..18、50C640/50CAC0 限定路徑；與 0x68、0x000A 及 9-byte key13 獨立。 |
| M. availability/SkillMatrix | `early-availability`, `early-matrix-tree` | — | 54F270/81A8E0 的 flags/4×11 WORD matrix 只做可用性/查找；T10-103 的 tick gate 和資料例外仍需按來源分離，不自推 motion。 |
| N. actor state and actual instance identity | `early-actor-state-read`, `early-selector-setter`, `early-factory-init`, `early-registration`, `early-instance-identity` | — | 欄位 +3E8、C07B44 virtual 等只可保留各自 owner/receiver 限定；`CLM-CLIENT-0030` 只能在既有證據適用範圍復用，無完整同一instance閉合。 |
| O. SubAI side channels | `early-subai-slots`, `early-subai-count`, `early-candidate-fallback` | — | stride16、counter >60、參數7/9、549C60 fallback 皆是 SubAI 路徑；026 函式歸屬反證隔離；不是普通攻擊段數或 V蓄氣。 |
| P. effects vs combo authority | `early-combo-boundary` | `middle-motion-authority-gap` | 保留 UNKNOWN，無法從 Input phase、500ms、SubAI >60 或 0.65 自訂常數判定原版 combo/本機預播、motion完成與 Server 裁決。 |
| Q. literal site census | — | `middle-literal-census` | 直接引用掃描所得原始 operand 與有效指令起點；列舉七個 literal xref 不能證明所有 indirect writer 已排除。 |
| R. 舊失敗時序裁決 | — | `middle-reset-order-refuted`, `middle-clear-guard-refuted` | **沿用 REFUTED**：062/063 精確錯誤不成為正面規格；同文件的其他獨立來源限定論述不連坐否定。 |

以上 A～R **18 個主題群**是對 early/middle 40 個有重疊 proposal key 的研究分群，不是「40 個已有 VERIFIED 的結論變 18 個 FULL_PASS」。來源內一部分 key 在多個群被引用是必要的交叉界面，不是 duplicate claim id。phase-writer、reader/reset、internal command68 均已定向查原 BIN；其餘未再做新 R2 者保留原先 proposal level，並保留來源與衝突而非自動推索引。

## 4. T10 R1 canonical 狀態及資料庫擬更新原則（尚未寫入 Git）

本輪起始權威 

- `research/intake/index.json`：473 SRC；其中 T10 127 份來源前一輪 R0 已登記；T10 最晚 22 篇 `SRC-0363..SRC-0384`。
- `research/claims/index.json`：124 CLM；前次 `CLM-COMBAT-0001..0004` 均 `PARTIAL`。
- `research/requests/index.json`：維持原狀；沒有專屬 T10 RR，在 T01 驗證時不能代替 S00 新派工。

**本地整合建議：**

1. 繼續將 early/middle 的 40 個 proposal group，依 A～R 與作者精確 source refs 做 **逐來源逐主張去重**。已明確 SRC ↔ CLM 關聯的，只新增限定 additional source ref，不複製正式 claim；一項群組的品質不繼承到未查的全篇原稿。實際修正式索引之前應重讀完整 93 份 origin source 及既有 claim 表，必要時驗證原始位元組；僅靠這份 cross-map 不應把它們全部升為 `CONFLICT_CHECKED`。
2. T10 **late 34 篇仍缺整體可提交的 R1 proposal**；其中 22 篇 T10-101～120 在 main，前次已有 4 篇抽樣 R2，其餘 18 篇 R0；對最後段號必須按 exact path/blobs 處理 101/102 雙版本。下一批先讀 late 剩餘原稿的 *actual narrative*、相鄰函式和 ABI，採新研究對照 matrix；有原生衝突再按風險進 R2。
3. 比對新的 `6D1480` writer 與舊 `middle-phase-writer-gap` 是 **證據時間線更新**，不是原稿錯誤：早期搜尋未命中不能直接標 REFUTED；但「目前仍不存在任何 writer」的肯定式泛稱不能沿用。
4. 不因本地 R2 子視窗已一致而升任一來源至 `FULL_PASS_DOCUMENT_SCOPED`，也不把 `CLM-COMBAT-0001..0004` 從 `PARTIAL` 升成 `NATIVE_VERIFIED`。T01 新 R1 及來源登記是 S00 後續工作導航，不取代 S00 單獨的 SPEC 審核和 Server 實作。
5. 不變更舊 T10 README 的 055/056、007/026/062/063 等 `NEEDS_FIX`／`NEEDS_QUALIFICATION`；新 evidence 僅附再現位置，原作者提交新勘誤/報告 blob，T01 才能依流程轉 READY_FOR_REVIEW→RESOLVED。

## 5. 四類缺口與精確後續入口

**Client 待逆向：** `6D1480` override vector `+80C/+810` 所有 producer 和 entry index guard；實體 DI keyboard 在 active bank 下的 Key44→ID13 穩定條件、consumer `5961C0` 至 controller bit0 的同 tick ABI、`5452C0` 5-byte row 原始欄位與實際 S2C key13 是否有 C2S 000A 因果、具體 motion clip/cancel/next-action queue 的 writer / lifecycle。應以 actor instance、virtual method、實際 caller/callee 沿用之前 `T10-101..120` 的 BIN 級導航。

**Server 待開發：** 相容 Server 對原版 Client 已確認的 `0x000A` 及其他本地 request 的回應、角色動作和狀態權威判定；不能把 Client `547240` 的 >500 或 internal 0x68/0x22 當原版 Server combo 規則。

**跨功能待整合：** T02 framing/IOCP 對 T10 selector=0 pending queue 的實際連線、T09/角色 vtable motion、T08 actor 生命週期；引用時保留來源版本與不同 offset 基準。

**待遊玩驗證：** 任何真實按鍵→wire packet、Server→Client actor motion、一對一 ACK 或 UI/技能實際播放，皆無原版 Client+Server 執行/抓包證據。本批僅靜態驗證，不報可玩。

## 6. 可再現驗證／停點

已生成同批本地驗證腳本 `T01_T10_20261030_verify_native.py` 和結果 `T01_T10_20261030_native_validation.json`。15 段定向 [start,end) SHA256 加 exact opcode assertions、七張 actor vtable `+0x58`、transport vtable、547240 state jump table，以及原件 SHA，在本輪重新跑過。**這是可再現的 R2 限定驗證**，並未安裝執行原版 Client、執行所有 127 篇作者原始腳本或重新審閱全部 T10 native pseudocode。

**結論：** 本階段完成 40-group proposal cross-area canonical *規劃/衝突裁決候選* 和 15 個 native 視窗重驗，仍留有 127 篇全量 source-to-claim 逐項發佈工作及 34 late 原稿全面 R1；不能把階段輸出當任務完成。使用者未授權 Commit，因此 GitHub main 保持 `5a38070c762855b73f5fb563f0e673df5e1f940f`（截至此輪讀取），應在使用者下一次明確允許推送時先重新檢查 branch head 和三個索引的最新 blob SHA，防止覆蓋其他 Agent。
