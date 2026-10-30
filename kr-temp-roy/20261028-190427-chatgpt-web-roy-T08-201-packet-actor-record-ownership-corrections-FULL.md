# T08-201 — 封包建立、關聯記錄與主樹移除：BIN-first 大型批次及歷史勘誤

研究者：`chatgpt-web roy`。本稿為續完修訂的完整研究原稿，合併實際進行的201與201-2；正式段號只有 T08-201，無 Commit／Push。時間與來源核對紀錄由文末產製程序填入。類別 CMonster 沿用既有研究名稱，未新增原始 C++ 符號證明；其他結構名稱均為行為暫名。

## 1. 結論與實質增量

1. **已確認，修正 T08-196：`0x004DFC90` 遍歷主樹 `owner+8`，不是次級樹。** `4DFC96: 8D 78 08` 是 `lea edi,[eax+8]`，不是讀取 `[eax+8]`；sentinel 是 `[owner+0xC]`。它以主樹 payload 的 `+0x88` 篩選，再執行預清理、deleting destructor、清空 payload 與 erase。原稿據此提出「兩棵樹都析構同一 actor」的前提不成立，不能保留為雙樹 double-free 證據。
2. **已確認，找到次級樹可追溯插入來源：`4AF530 → allocation(0x2C) → 4DFFB0 → 57EF20 → 57E850`。** 此路的 payload 首 DWORD 是封包給定的 key，不是 vptr；與 `0007` type 1 配置的 `0x434` CMonster 是不同配置實體。兩條路均明確傳入 `0x00FAB130` 作容器 owner，因此此處的 `+8/+0x18` 確屬同一全域容器，卻不是同一 payload 型別。
3. **已確認，封包欄位連成跨容器關聯：** `0007` 的 row+0 WORD 寫 actor+4，row+4 WORD 參與 composite，row+18 DWORD 寫 actor+0x9C 並查次級樹；命中且 record+4 為零時，`4C6E50` 寫 record+4=actor WORD key，查回主樹並把 actor+0x88 的低 WORD 寫 record+8。此路是數值 ID 關聯，不是把 actor 指標存到 record+4。
4. **已確認，命令 81 的移除域：** `4B3710` 從 buffer+2 起每兩 bytes 讀一 WORD，OR `0x06000000`，經 `40F060` 取得 `EAX=0xFAB130`，交 `4DFC90` 比對主樹 actor+0x88。因此刪除的是 composite 相等的所有主樹成員，而非以該 WORD 直接作主樹 key。這與命令 26 的 buffer+4、WORD key 指定移除不同。
5. **已確認，建立包重複 ID 在配置之前就被跳過：** `4AE58F–4AE5B2` 查主樹，命中直接跳 `4AED42` 前進下一列；這補上 T08-200 只看 registration duplicate 分支的 caller 缺口。不能推廣至所有 caller，也不能據此保證重入／競爭情況無洩漏。
6. **第一輪已確認、第二輪再深化，`actor+0x15C/+0x160` 是一對指標：** base ctor 以 pair 位址呼叫 `4CA460(pair,0)`，該路配置 `0x10` 控制區，`7A31C0` 寫 pair[0]=0、pair[1]=控制區；base dtor 對第二指標執行兩級原子計數釋放。這是 shared-ownership 形狀的原始證據，但不能把控制區 vptr `0xC0760C` 當作非空 child 的 vptr。第一輪到此尚未閉合；本次201-2已補證真正child為IS3D::CDoll、0x170配置／安裝者及child+8介面slot+8=7A57C0，詳6A。

本段201與201-2取得「建立包欄位 → actor key/composite writer → CDoll建構／安裝 → 主樹登記 → 次級數值關聯 → 移除／CDoll預清理與條件性最終釋放」的有界功能鏈，並否證歷史錯誤的雙樹析構前提。未聲稱 socket 到畫面或原版 Server 波次已完整還原。

續完版本交付前核對main為 `a7557de34a8b9c75b6a9b07204a118f8d1931e58`；與201-2起始SHA `4998575006af5fa777bd024fe9cf31a7924ce7c0` 比較，僅新增T16-78研究原稿，未改本稿T08來源。第一輪／第二輪各自記錄的舊HEAD保留作研究時間點，不再稱最新。

## 2. 遠端來源、規範與研究優先序

已讀本次 Project 的 02、T08 專屬 03 與上傳 `04-T08-NEXT-CHAT(8).md`。GitHub 另讀根 AGENTS、README、HANDOFF、修改政策、bulk 保存／審核索引、T08 README、task.json、本地追查矩陣、長期知識庫、T08-157、196、200 與相關 bulk 偽碼。來源均為 KR；沒有執行、附加、patch 原始程式，未變更 owner/catalog/task 或其他研究者檔案。

目前 main 的 T08 README 有 T01 退回 157、173、187、196，以及 LEGACY-MAPPING 群組 BLOCKED。**本段先處理直接影響封包移除／雙樹題目的 157、196，另補 173／187 的指定指令勘誤；不把有限更正寫成全文驗收通過。** 未推送，故 README 的 NEEDS_FIX 狀態未變；待使用者授權提交修稿後，才能提供新 Git blob SHA 並交 T01 複驗。無權自行標 RESOLVED。

`shared/catalog.json` 的 fetch_file 回應有 blob SHA 但 content 為空，另次 API 讀取 Transport closed，故本輪沒有聲稱已讀取完整 catalog 或完成新方法登記。遵從使用者直接研究／不提交範圍，只在自己的原稿補充有限證據；dispatcher 與一般容器 helper 僅作交叉引用，不接管 T02 或其他 Task 主責。

GitHub bulk 偽碼是衍生資料；本稿的關鍵指令、分支與表值均重回原始 BIN 驗證。不以偽碼漏引數、推定 prototype 或全量 objdump 的任意線性邊界作語意證據。

完成前再次查main已前進至 `88841d72a309cf7c66338c59ed5a29d1212e1980`；GitHub compare確認相對起始SHA只新增一份T16-75筆記，未變更本稿使用的T08／bulk／規範來源。因此保留起始固定版本作可重現依據，最新main核對值以此段為準，不能把起始SHA繼續稱作最新。

## 3. 第一輪 201：分派表與封包資料界面

### 3.1 handler 註冊與 opcode 界線

`4ADD50` 先初始化 `0xBD5` 個 8-byte 槽，handler 在 `base+4+8*i`，旁邊 DWORD 在 `base+8+8*i`；本輪只將 i 稱**本地 handler 表索引**。具體寫入：

| i | slot offset | handler | 原始寫入 VA |
|---|---|---|---|
| 7 | +0x3C | 4AE4D0 | 4ADD7E |
| 8 | +0x44 | 4AF530 | 4ADD98 |
| 10 | +0x54 | 4AF920 | 4ADDA2 |
| 26 | +0xD4 | 4B28D0 | 4ADE8D |
| 81 | +0x28C | 4B3710 | 4ADFBD |

**重要區分：本輪找到的次級樹生產者是索引 8 handler `4AF530`，不可把它直接叫作 S2C 000A。** 索引 10 的 handler 是另一個 `4AF920`。此表尚未連回完整 socket/framing/命令域解碼，所以本表不是原版 wire opcode 證明。0007 是承襲既有有界標記，新增確認範圍只到此本地註冊表。

### 3.2 0007 handler 的 row 定義

令 B 為 `[ebp+8]`，L 為 `[ebp+0xC]`；N=(L<2?0:floor((L-2)/26))。游標 EBX=B+6+26*i，因此 row R=B+2+26*i，EBX=R+4。前置 2 bytes 在本 handler 的計數路徑未解作含義；沒有檢查 remainder 必須為零。表中 offset 是 handler buffer，非包含傳輸層 framing 的 wire 絕對位移。

| row offset | 讀取方式 | 已證消費者／寫入 |
|---|---|---|
| +0..1 | WORD；另取低 BYTE | 主樹 key；低 BYTE 決定 type；4AEB30 寫 actor+4 |
| +2 | unsigned BYTE | 減 1 後參與 composite；若 0，減法下溢也必須按 32-bit 原樣保留 |
| +3 | BYTE | type6 路徑使用，4AE8A2；未定義完整語意 |
| +4..5 | WORD | composite 低 WORD；亦查外部表 |
| +6..13 | 兩 DWORD | vtable+0x44 的二維值來源；CMonster → 4C8B90 → 4CAB80 寫 +0xA0/+0xA4 |
| +14..17 | float load | vtable+0x5C，引數為 row+14 的 32-bit 值；物理量未命名 |
| +18..21 | DWORD | actor+0x9C；次級樹查找鍵，條件性建立 record 關聯 |
| +22 | BYTE | vtable+0x58；CMonster 表目標 4C8C30，寫 actor+0xB0 BYTE |
| +23 | BYTE | type1 actor+0x424；是否等於4決定 actor+0x428；另有外部狀態分支 |
| +24 | BYTE | actor+0x90 DWORD 零擴展 |
| +25 | BYTE | actor+0xF0 子介面 slot+8 入參；等於0x18另寫 actor+0xBC=1 |

composite 的精確運算（所有中間值按 uint32）：

```cpp
uint32_t composite = (((uint32_t(R[2]) - 1u) | (uint32_t(R[0]) << 8)) << 16)
                   | read_u16(R+4);
```

當 R[2]>=1 時可讀作高 BYTE 是 type、其次 BYTE 是 R[2]-1、低 WORD 為 R+4；R[2]==0 不可用這種簡化描述，因為下溢擴散。CMonster vtable+0x3C=`4C6FB0`，直接寫 actor+0x88 與 +0x8C；後續其他 writer 可能再改 +0x8C（`4C6FD0`），故不能視兩欄永遠等同。

### 3.3 全 type 分支與 CMonster 有界路徑

`4AED90` 是 jump table 資料，不能當 x86 指令。8 個 DWORD 由 BIN 直接讀出：type0→4AE5E4、1→4AE671、2/3/4/5→4AED83、6→4AE80A、7→4AE8D6；type>7 亦走 4AED83。配置大小依序 0x444、0x434、0x42C、0x428，建構目標 4CD6F0、4D1710、4D2120、4D1060。無 class symbol 的分支不臆造名稱。4AED83 呼叫診斷／終止相關 helper，其是否返回不在本段保證。

type1 成功配置後，`4D1710` 呼叫 base `4C7070`，主 vptr 寫 0xC0C9DC、+0xF0 vptr 寫 0xC0CA64。handler 另配置 0x48 bytes 輔助記錄（4AE69D）；其 +4 在 actor 新 key 寫入之前讀 actor+4，**不能誤稱為新封包 key**。該輔助記錄交 `56F5C0`，不是本輪 0x2C 次級樹 payload。

共用尾端順序為：額外資料查詢 → 欄位寫入 → composite virtual setter → 二維值 setter → BYTE setter → float setter → virtual+0x30 → type 特定旗標 → 主樹登記 → 次級關聯 → 其他狀態分支。已有 actor ID 直接跳列尾，不會在此建立新 CMonster。配置失敗的若干分支後仍有解參照，不能從局部空值分支推導整體 OOM 安全，也不在本輪宣稱 runtime crash。

二維值寫入及模型子介面傳遞是場景表現的靜態基礎，但**座標軸、單位、資源載入完成、實際 render 出現均未動態驗收**。

## 4. 兩樹 owner、payload 與數值別名

### 4.1 全域容器本體不是 `[0xFAB130]`

`4DEC90` 在全域地址 0xFAB130 起初始化多個欄位，其中 `[0xFAB130]` 是另外配置 0x5F24 後建構的 heap 物件；不能把該 heap 指標作本稿樹容器 owner。`40F060` 返回字面地址 **0xFAB130**。

| 本體位移 | 絕對地址 | 本輪確認 |
|---|---|---|
| +0x08 | FAB138 | 主樹容器起點 |
| +0x0C | FAB13C | 主樹 sentinel 指標；節點配置0x18 |
| +0x10 | FAB140 | 主樹計數初始化0 |
| +0x18 | FAB148 | 次級記錄樹容器起點 |
| +0x1C | FAB14C | 次級 sentinel 指標；節點配置0x18 |
| +0x20 | FAB150 | 次級計數初始化0 |
| +0xF8 | FAB228 | 次級 payload 的條件性快取指標 |

### 4.2 兩條插入者的配置來源

主樹 `4DFF30`：EAX=actor，stack arg=owner；讀 WORD actor+4，pair={zero_extended_key,actor}。`57EF20` 配置0x18節點，pair第一 DWORD→node+0xC、第二 DWORD→node+0x10。`82F200` 負責主樹插入；已存在時只在此作診斷，沒有直接銷毀 incoming actor。

次級 `4AF530`：N=(L<4?0:floor((L-4)/22))，row Q=B+4+22*i，EBX=Q+6。先以 read_u32(Q) 查 FAB148；未找到或既有 payload 為空才配置0x2C，初始化多數欄位，寫 record[0]=read_u32(Q)，然後 ECX=record、push FAB130，呼叫 `4DFFB0`。後者取 record[0] 作 key，pair={key,record}，`57EF20` 同樣把第二 DWORD 放入新 node+0x10，再經 `57E850` 插入。這證明兩樹可共用**節點 layout/helper**，並不代表共用 payload 型別。

`4DFFB0` 如 record[0]==[F93930] 就把 record 存 owner+0xF8。此記錄沒有 CMonster vptr，不能用 actor 的 vtable 析構 ABI 清理。

### 4.3 次級封包 row → record 欄位表

| Q offset | 寬度 | record offset | 備註 |
|---|---|---|---|
| +0 | DWORD | +0 | key；已有記錄亦覆寫相同 key |
| +4 | BYTE | +0x20 | 未命名狀態 |
| +5 | BYTE bits0/1 | +0x28/+0x29 | 分別抽取兩bit |
| +6 | DWORD | +0x0C | 原值複製 |
| +10 | DWORD | +0x10 | 原值複製 |
| +14 | WORD | +0x14 | 零擴展讀後以WORD寫 |
| +16 | WORD | +0x16 | WORD寫 |
| +18 | WORD | +0x18 | WORD寫 |
| +20 | signed WORD | +0x24 DWORD | movsx；不可當無號 |
| 衍生 | compare key==F93930 | +0x1C DWORD | 是否符合全域識別值 |

record+4/+8 在新配置時為0，由其他關聯函式填；不是此22-byte row的兩個原始指標欄位。

### 4.4 0007 和 record 的相交

主樹登記後若 row+18非零：以該DWORD查次級樹，命中 record 且 record+4==0，才呼叫 `4C6E50`。EDI=record，EAX=zero_extended read_u16(R)。此函式先寫 record+4=key，再經 `40F060`、主樹查找取 actor，將 actor+0x88 的低WORD零擴展寫 record+8；找不到則 record+8=0。

因此可確認一條雙向數值關聯：actor+0x9C 保存次級查找鍵，record+4 保存主樹查找鍵，record+8保存 composite低WORD。**沒有把這些 DWORD 直接強轉成 actor 指標的根據。** 先後收包順序是否另有補綁定、record更新後何時驅動畫面／控制器，不由這條路徑推廣。已有 record+4!=0 時此處不覆寫。

## 5. 移除功能鏈、所有權與清場邊界

### 5.1 四條主樹清理與一條次級清理

| 入口 | 容器／選取 | payload處理 | 節點處理 |
|---|---|---|---|
| 4DFBC0 | owner+8；WORD key查找 | actor virtual+0x14→virtual+0(1)→置零 | 7B6890 erase |
| 4DFC90 | owner+8；遍歷 actor+0x88 等值 | 同上 | erase回傳下一迭代位置；不匹配走successor |
| 4DFD40 | owner+8；actor+4低BYTE與輸入WORD比對 | 條件性child處理後，同上 | erase並接續 |
| 4DFE90 | owner+8；全部 | 非空actor預清理→析構 | 最後823850清樹；另有FBA7A4 callback |
| 4DFC30 | owner+0x18；DWORD key查找 | 清匹配owner+F8，非空payload交89120C | 7B6890 erase |

`4DFD40` 的外層 filter 是 zero_extended actor低BYTE 與輸入WORD相比；不是將 actor整個WORD key作比較。4DFE90的 callback 不等於 actor同一vtable，也沒有直接呼叫4E1070清次級樹。二者整批清場時序須追 caller，不能聲稱自動同步。

次級全清 `4E1070(FAB148)` 逐payload直接釋放，再清節點與count；本體中沒有清 owner+F8。`4AF530` 在 buffer+2 的WORD非零時，先明確寫 FAB228=0 再 call4E1070，這是**此 caller 可證的快取防懸掛動作**。不可推廣所有4E1070 caller均有相同保護。

### 5.2 命令 26 的完整有界 CFG（修 T08-157）

N=(L<4?0:floor((L-4)/2))；cursor=B+4，每回合 WORD key查主樹。缺失或payload空→診斷→4B2AC7前進，不中止整包。命中時：低BYTE 0/1/6/7條件性處理 child+0x15C及actor+0x370；低BYTE2/8/9有另一組元件／比例條件與4CC8B0；接著掃 FBA7A4 的三個控制槽，匹配可呼叫其slot+0x14；最後4B2AC2調4DFBC0(FAB130,key)，前進2並迴圈。回傳EAX=0、ret0xC。

有效指令為 `4B297A cmp eax,[FAB13C]`（六bytes）、`4B2980 je4B2989`、`4B2982 mov esi,[eax+0x10]`。舊稿從4B297C開始的cmp al／cli整段為指令中途錯位解碼，應撤回。成功／缺失分支與此完整窗口重新核對；原版wire域、死亡含義仍未知。

### 5.3 命令 81 和 composite writer 的關係

N=(L<2?0:floor((L-2)/2))；每筆 key=read_u16(B+2+2*i)，filter=0x06000000|key。此filter與0007建構的composite在type6、R[2]==1、低WORD相同時可直接相等；**這是代數相容條件，不是已證Server只發該組資料**。4DFC90可刪所有composite相同的主樹actor，因為其遍歷不在第一個命中後返回。沒有讀或銷毀次級0x2C記錄。

### 5.4 真實 CMonster 路徑與有界閉合

可追溯成功建立路徑：0007 type1 → alloc0x434 → 4D1710 → 4C7070 → vptr C0C9DC → handler欄位／setter → 4DFF30主樹插入。後續若命令26指定相同WORD key且主樹仍持有該CMonster：4B28D0 → 4DFBC0 → vtable+0x14=4D1F80 → 4C8360 → 非空資源slot+0x24呼叫7BE5F0（另有0x364及128槽0x164…）→ vtable+0=4D18D0(1) → 4C7B90 → 89120C(actor) → node payload置零 → node erase。

此鏈以**同key、動態vptr仍為CMonster、成功建構**為條件，不是保證每個封包key都走此鏈。4C8360先對 child 的 **child+8介面**取vptr再調slot+8；不是 `child vtable+8`。base dtor對child pair的control block釋放也不是此介面dispatch。

第一輪已確認0x2C與0x434的配置分離，所以舊稿假設的「兩樹同actor double delete」無法由這些路徑推出；也不能反向宣稱全程已證無double-free／無stale numeric association。主樹刪除後 record+4/+8是否清除，要追額外writer及時序，本輪留待查。

## 6. 第一輪的子物件 ABI 證據與當時尚未閉合部分（6A已續補）

`4C70C4` 取得actor+0x15C pair位址；先將兩DWORD零化再push0與pair調4CA460。4CA460配置0x10控制塊，vptr=C0760C、+4/+8計數初始1、+0xC=入參（此處0）；`7A31C0`對ESI指定pair寫入第一指標與控制區指標。base dtor 4C7C19先取actor+0x160，再將兩欄清0，依控制區+4與+8的lock xadd結果條件性調slot0／slot4。

**已確認：** 構造時first pointer為空、control pointer可非空；析構用的是control pointer。**合理推測：** 結構類似shared_ptr/strong-weak控制區；沒有編譯器／標準庫符號所以不定名具體模板。**尚待驗證：** 非空first pointer的安裝者、原始child配置與vptr、child+8介面slot+8具體目標。不能拿control區vtable去解child dispatch，也不能從初始空值推斷遊戲中永遠沒有child。

本輪以ctor、pair helper、dtor及清理consumer作反證交叉；沒有在此宣稱找齊所有writer。全text位元組／文字搜尋只用作候選定位，不作型別歸屬證明。

## 6A. T08-201-2：使用者要求續完後的深入補證（本次新增）

> 第一輪原稿於使用者再次要求「請完成201」前已交付並停止；本次按該指令重開同一段的補充深入輪，記為 **201-2**，不是202，也不倒寫為先前已做過。以下新增證據取代第一輪「非空child來源與slot尚未辨」的結論；第一輪範圍及原始過程仍如實保留。201-3未啟動，理由見更新後輪次表。

### 6A.1 從0007真正接到非空子物件

第一輪已證 `4AEB7D call [actor_vtable+0x30]`，但當時停在Actor欄位／pair初始狀態。現在直接讀 CMonster主表 `0xC0C9DC+0x30=0x4D1910`，並重解該目標：`4D1938 ESI=ECX(actor)`，`4D193C push0`、`4D193D push esi`、`4D193E call4C7DF0`。因此在0007 type1成功路徑，主樹登記前已有**具體的非空child配置／安裝**。

`4C7DF0(actor, flag)` 的成功路徑：

1. 以 `[actor+0x370]==0` 為建立門檻；若非0直接到成功返回，不重配。
2. 從actor+0x8C取ID，為0則用actor+0x88；`movzx ecx,si` 僅取低WORD作child建構參數。
3. `4C7E3F push0x170` → `4C7E44 call891268`；成功後 `4C7E5D call7A4C50(heap, low16_ID)`，回傳完整child基址D。
4. `4C7E66 push D`、push臨時pair地址，調4CA460，建立 `{D, control}`；控制區另外配置0x10 bytes，不能與D同一塊。
5. `4C7E80 EDI=actor+0x15C`，`4C7E86 EAX=&temporary_pair`，`4C7E92 call4E0F60`。該helper取出source兩DWORD並清空source，寫入destination兩DWORD，再對destination舊control作計數釋放；這是有原始指令支持的**pair所有權搬移**，不是只複製裸指標。
6. 以D呼叫7A6EA0(D,1,actor+0x388的WORD)；接著設actor+0x370=1，再把Actor既有二維值、BYTE、float與狀態傳向具體virtual setter。7A6EA0的內部外部資料／資源實際載入完成本段不擴大保證。
7. `4C7F8A`另配置0x30 bytes、7B4000建構並存actor+0x368；此物件不是0x170 child，也不是0x2C次級Actor記錄。第一輪提到的0x48輔助記錄亦為另一配置。

`4C8060` 是另一條已證的重建路徑：actor+0x370非0時先清旗標與pair、釋放舊control，再同樣配置0x170、7A4C50建構、4CA460包裝、4E0F60搬入，恢復各setter與旗標。本輪只把它作生命週期交叉證據，不宣稱已找出所有runtime呼叫時機。

### 6A.2 原始RTTI證明是 IS3D::CDoll 與 std::tr1 控制區

以下名字不再只是分析者暫名：本輪從原BIN的MSVC Complete Object Locator及TypeDescriptor讀出類名，並核對多個subobject的offset，沒有只採信Ghidra標籤。

| 對象／vptr | vtable VA | COL VA | COL offset | TypeDescriptor VA | 原始name |
|---|---|---|---|---|---|
| D+0 主介面 | C4F67C | C7FA7C | 0 | F8A718 | `.?AVCDoll@IS3D@@` |
| D+4 介面 | C4F690 | C7FA68 | 4 | F8A718 | 同上 |
| D+8 介面 | C4F6B0 | C7FA54 | 8 | F8A718 | 同上 |
| D+0xC 介面 | C4F6C0 | C7FA40 | 0xC | F8A718 | 同上 |
| pair第二指標control | C0760C | C69F48 | 0 | F7E264 | `.?AV?$_Ref_count@VCDoll@IS3D@@@tr1@std@@` |

`7A4CA5`寫D主vptr；`7A4CAB/CB2/CB9`分別寫D+4/+8/+C的最終vptr。前面 `7A4C7F`等base表寫入會被最終表覆蓋，不能停在base構造中間值。RTTI的subobject offset也與消費者的`lea ecx,[D+8]`相符。控制區+0xC存D；這是 `std::tr1::_Ref_count<IS3D::CDoll>` 的RTTI證據，無須再以未知child控制塊混稱。

**已確認的三種指標不得混用：** actor+0x15C=D（CDoll完整物件）；actor+0x160=C（控制塊）；預清理的ECX=I=D+8（CDoll次級介面）。RTTI僅證類名／layout，不直接證圖像、動畫或原版Server規則。

### 6A.3 先前未知的virtual target現已閉合

從真實CMonster移除路徑：4DFBC0或4DFC90取得Actor → 主vtable+0x14 → 4D1F80 → 4C8360。`4C8365 EAX=[actor+0x15C]=D`，`4C836F ECX=D+8=I`，`4C8372 EAX=[I]=C4F6B0`，`4C8374 EDX=[EAX+8]=7A57C0`，`4C8377 call edx`。**此處無須動態猜目標**，因為上游已閉合為7A4C50實際構造的CDoll。

| 介面 | slot | 表內原始target | 相關意義 |
|---|---|---|---|
| D主表C4F67C | +0 | 7A4FF0 | CDoll deleting destructor |
| I表C4F6B0 | +4 | 7A5790 | 另一路處理，不與預清理混稱 |
| I表C4F6B0 | +8 | **7A57C0** | 此Actor預清理具體目標 |
| control表C0760C | +0 | 4CA660 | 取control+0xC=D，調D deleting destructor(1) |
| control表C0760C | +4 | 7A3920 | 經control自身slot+8 deleting destructor(1) |

`7A57C0` 在ECX=I下工作，並未先subtract8；所有欄位需換回D基址：

| I-relative | D-relative | 觀察到的用途／清理 |
|---|---|---|
| +0x118 | +0x120 | 可選物件slot+8呼叫後置0 |
| +0x1C | +0x24 | 等於1才進入特定關聯資料遷移／清理；完成後置0 |
| +0x20 | +0x28 | 上述分支完成時BYTE設1 |
| +0x144/+0x148 | +0x14C/+0x150 | 8-byte條目陣列；每筆第二指標7D8890後free、置0，最後end=begin |
| +0x100 | +0x108 | 非0時7BE0F0解除Binding相關內容 |
| +0x104 | +0x10C | linked-list sentinel；node+8資源與node+C另一多型項 |
| +0x108 | +0x110 | linked-list計數；清理後0 |
| +0x110 | +0x118 | 最後置0的獨立欄位 |

這些欄位與Actor自己的+0x15C／+0x164等完全不是同一結構。`7A59E3 cmp edx,edx`令後續copy loop不可到達，實際由7A59FB將end設begin；Ghidra對該unreachable block的警告本輪由原始分支確認，不以錯位反組譯推論循環。

### 6A.4 CDoll介面清理到資源／manager的指標來源

在I+0x104串列逐節點：`N=[I+0x104]->next`、`R=[N+8]`、`M=[R]`。原始指令 `7A5A36 mov eax,[esi]`、`7A5A38 dec [eax+0x60]`，故此處的manager明確取自該resource首DWORD，不由Actor offset猜別名。

原生CFG為：

- R空：跳過resource，仍處理node+C項。
- R+0x74與R+0x78均非0：若signed M+0x44>=1，在M+0x64鎖範圍內將R append到M+0x7C／+0x80／+0x84指標陣列，必要時797930擴容，end增加4；**此分支沒有立即free R**。若M+0x44<1，直接走R析構／free。
- R+0x74或+0x78至少一個為0：若signed R+0x74>=1，先7BE0F0；然後7BD850與89120C(R)。
- node+C非0：調其slot+0x10，再slot+8；這個未知項不能因也有slot+8就叫CDoll。
- 把目前node從串列unlink並free，取已保存next繼續；完成後sentinel.next/prev回指自身、count=0，最後清I+0x110。容器本體及sentinel在本函式沒有free，留給更晚析構。

所以本段補上**真實CMonster→CDoll介面→CDoll持有resource list→resource明確manager→pool或free**的一條有界所有權鏈。這比第一輪僅知128個Actor狀態slot多出一條不同層次的實際consumer。不可把CDoll串列中的R直接等同每個Actor slot的wrapper，也不可據池append宣稱每frame drain。

`7A57C0`特定state==1分支還會建立0x38 bytes暫存項、搬移部分資料並呼叫79DE00；其對全域manager的行為超出本段完全命名範圍，原始窗口保留。Ghidra在此把暫存pair誤套成CRITICAL_SECTION等複雜型別，**本稿拒絕沿用這些局部偽碼型別**；實際Enter/Leave呼叫之IAT位置另以原BIN匯入表核對。

### 6A.5 Actor析構與CDoll釋放的銜接及防重覆邊界

主樹的預清理完成後，Actor deleting destructor `4D18D0(1) → 4C7B90`；base dtor先取C=[actor+0x160]、清Actor pair，然後以C+4作原子減一。減至0時調C表+0=4CA660；該函式讀C+0xC=D並透過D主表slot0=7A4FF0調(1)。`7A4FF7 call7A51C0(D)`完成CDoll destructor後，若flags&1則89120C(D)。再由control的第二級計數路徑處理C；control與D各自釋放，不是釋放D+8。

可驗證的防重覆範圍：預清理將D+0x24在特定分支置0，而CDoll dtor `7A520D cmp [D+0x24],1`因此跳過相同分支；預清理已把D+0x10C串列empty、D+0x110 count=0，所以dtor到`7A538E`可見空串列。D+0x14C陣列的條目已free並置0、end回begin，dtor稍後只free該陣列allocation。這些是**此順序與同一D的局部重覆清理避開證據**，不是全遊戲無double-free保證。

若另有strong owner，Actor釋放C不一定立刻觸發D析構；本輪沒有蒐齊所有shared owner，故不得把「Actor析構」與「CDoll記憶體立即釋放」視為無條件同步。預清理本身已有資源退役副作用，與最終D free是不同階段。

### 6A.6 往上補到實際handler表consumer，socket邊界仍明示

本輪新增證明handler表不是只寫不讀：`0x004FDA30`從第三引數低WORD以signed方式取index，從`this+4+8*index`讀handler，將原buffer、length、第三引數三者原樣push後在`4FDA8A call [ebp-4]`分派。因此第一輪的索引7／8／26／81可與這個consumer形成相同表layout的閉合，不再僅是註冊者線索。

進一步用具體多型對象證明owner：在已從4ADD50建構的0x5EAC bytes handler物件，主vptr=0xC072B4，其slot+4原值4FDA30；`4B7EC0`從另一owner+0x5EAC取該物件，讀vtable+4並tail-jump，保留原三引數。`48F6D9–48F6FF`配置／4ADD50／vptr設置後，以EDI傳入`4B7D50`；後者`4B7DA7`確實存入外層owner+0x5EAC。完整有界鏈為：

```text
0x5EAC handler物件配置 → 4ADD50填表 → vptr C072B4
    → 4B7D50 安裝到外層owner+5EAC
    → 4B7EC0 tail dispatch → slot+4=4FDA30
    → this+4+8*index → 4AE4D0 / 4AF530 / 4B28D0 / 4B3710
```

沒有把outer owner+0x5EAC誤認作其payload本身；也沒有把該0x5EAC handler物件與FAB130的0x5F24 heap物件混用。此分派窗口不檢查index範圍，不能只憑這裡推導完整封包驗證；上游socket、decryption/framing、第三引數來源與wire域仍交T02。這是**Client dispatcher→handler**已補閉，不是socket→玩家畫面全部完成。

### 6A.7 修訂後的證據分級與本地待查縮減

- **原生確認新增：** CMonster slot+0x30實目標與child建構、0x170配置、pair搬移、IS3D::CDoll／Ref_count RTTI、child+8 slot+8=7A57C0、CDoll resource-list與pool/free分流、控制塊最終釋放鏈、handler表consumer及具體owner安裝。
- **第一輪未知已解除（有界）：** 「CDoll非空來源」「該CMonster路徑的child+8 vptr及清理target」。不要再把這三項列成本地必須重新尋找的阻塞。
- **仍部分確認：** 其他Actor派生類是否共用CDoll、CDoll是否可在其他路徑被替換、所有strong owner、資源完整載入與畫面退場時序、79DE00的暫存遷移語意。不能把具體CDoll型別套到所有Actor。
- **資訊缺失：** wire/framing、實際Server觸發條件、波次／關卡事件、runtime可見驗收。新增靜態型別證據不等於這些資訊自動補齊。

更新玩家情境：0007 type1 → 4D1910 → CDoll allocation／安裝與值傳遞；26指定key或81 composite條件命中該Actor → CDoll介面預清理與資源退役 → strong count條件下最終析構。這使「收到資料後建立／消除模型側物件」的靜態證據更完整；畫面像素出現／消失及時序仍需另經授權的本地驗收。沒有AI替代實作。

### 6A.8 第二輪停止判定

201-2已取得第一輪最重要的未知virtual target、實際配置來源與manager consumer鏈，並以RTTI和ctor／dtor雙向交叉核對；符合02重大發現／完整有界鏈門檻。故本次正式完成201，**201-3未啟動**。本段不要求把整個遊戲socket、Server或render全部還原才停止，但必須保留上述具體邊界。


## 7. T01 退回處置與歷史修正清單

| 退回ID | 原主張／錯誤 | 本稿原始反證與修正 | 本次交付狀態 |
|---|---|---|---|
| T08-157-001 | 4B297C是指令起點；錯位cmp al/cli | 4B297A六byte cmp、2980 je、2982 mov；本稿重列整個handler與CFG | 有界修正版已提供；待提交及T01複驗 |
| T08-196-001 | 4DFC90操作owner+18次級樹、兩樹均析構actor | 4DFC96 LEA owner+8；4DFC30才是owner+18；本稿重列兩路CFG／payload來源 | 主要實質錯誤已更正；待提交及T01複驗 |
| T08-173-001 | 7B8006寫值需caller決定 | 7B7FFE mov ecx,1支配此迴圈；+44寫1。7B8030另有drain後寫0，兩路分開 | 指定writer已核對；未宣稱原稿全文重驗 |
| T08-187-001 | 7F6FC1 push0x30 | 7F6FBF=6A30；7F6FC1=8BF8 mov edi,eax；7F6FC3 allocator、7F6FDC acquire、7F700B寫wrapper+2C | 指定窗口已核對；未宣稱原稿全文重驗 |
| LEGACY-MAPPING | 舊flat來源與目前PE來源混用 | 本輪一律依PE節區映射，未取得舊flat檔實際版本／hash | BLOCKED保留；不可用本次映射全面覆寫舊稿 |

T08-196原稿blob `b1879330f55b5d7b6d38a697a46a0f40ce3b6aca`；157原稿blob `b67b6c415c63034607fadef59b0e4fc2892237e2`，本輪讀回相符。173/187修正屬退回指定窗口，不冒稱兩篇全文已重新審核。原稿均未覆寫；本稿提供明示勘誤。

## 8. 玩家情境、證據分級與本地驗收

| 收到何種原生資料 | handler／欄位 | writer與場景變化 | 玩家可見效果與等級 | 未證Server行為 | 本地待查 |
|---|---|---|---|---|---|
| 既有標記0007；本地索引7，2+26N | 4AE4D0，type/key/composite/二維值 | type1建CMonster，寫+A0/+A4，主樹登記，可能record數值關聯 | 原生確認：Client建立／寫入；部分確認：畫面實際出現 | 何時生成、位置策略、數量／波次決策資訊缺失 | T02實際wire域；資源完成／render觀察 |
| 本地索引8，4+22N | 4AF530，DWORD key等 | 更新0x2C記錄；條件快取；可先全清次級記錄 | 原生確認：資料寫入；畫面／控制效果資訊缺失 | 發送順序與同步規則未知 | 與0007先後到達的補綁定consumer |
| 命令26，本地索引26，4+2N | 4B28D0，WORD actor key | 主樹查找、前置副作用、預清理與析構 | 原生確認：刪除記憶體／索引；畫面消失時序部分確認 | 不能命名死亡包 | 收包trace、模型解除／render殘留時序 |
| 命令81，本地索引81，2+2N | 4B3710，WORD→06000000 OR | 主樹按actor+88篩選，全部相等者刪除 | 原生確認：選取與刪除；實際視覺未驗收 | type6在Server的用途、事件時機未知 | filter與真實封包、資源對應 |
| 000A、151、關卡事件／下一波／結果 | 本輪未閉合新鏈 | 不沿用索引8冒充000A；不新增事件8因果 | 資訊缺失 | 無Server不得推波次／OnDeath | T02/T06/T07/T14依主責補證 |

本輪沒有AI替代實作、沒有fixture值；「待補開發」僅指取得原生證據後才能制定相容實作／驗收，未交付可玩Server。

具體本地阻塞清單：

1. **T02收包域**：提供對應版本原生封包bytes及recv/framing到本地表索引的trace；驗收需能逐byte指出B、L包含範圍，不能只憑handler表索引稱wire opcode。
2. **次級所有writer／消費者**：追4DFFB0所有真實caller、FAB148插入可否繞過本入口、4DFC30與4E1070 callers；驗收記錄payload allocation provenance、快取清除與主樹刪後record+4/+8處置。當前只閉合4AF530來源，未稱所有插入者已找齊。
3. **child來源缺口本次已部分解除**：201-2已證本CMonster路徑的CDoll配置、pair搬移、四介面vptr與清理slot。剩餘要查其他派生Actor的替換路徑、所有strong owner及runtime時序；不要重做已閉合入口。
4. **可見結果**：完整DLL／資源／腳本及另經授權的唯讀診斷環境，觀察相同key建立、重複建立、26刪除、81篩選、重入場景；記錄數值關聯與畫面對照。當前不執行或附加原程式。
5. **Server與關卡決策**：合法可用原生Server或真實流量／資源證據；由T06/T07/T14主責確認下一波／事件／結果。Client handler不能單獨驗證發送原因。
6. **來源調和**：舊flat image的原始bytes、hash、產製方法與映射；未取得前LEGACY-MAPPING不得解除。

## 9. 三輪規則與停止判定

| 輪次 | 實際入口與工作 | 結果／停止理由 |
|---|---|---|
| 201第一輪 | 先讀T01退回，重解4DFC90/4B28D0；往0007、4AF530、4DFFB0、兩樹節點helper、composite setter、81 caller、ctor/pair/dtor交叉延伸 | 已取得重大新證據：不同payload生產來源、兩樹數值關聯、81主樹filter、建立前重複ID跳過與196反證；形成有界Client功能鏈，達02門檻，停止本段 |
| 201-2 | **已執行**：使用者再次要求完成201後補查4D1910→4C7DF0→7A4C50→4E0F60；RTTI、7A57C0、控制區析構與4FDA30 dispatcher | 實際child、未知virtual target、resource-list manager與表consumer均取得原始新證據；詳6A，達標後停止 |
| 201-3 | **未啟動** | 第二輪已達重大發現／完整有界鏈門檻；不虛構第三輪 |

本CMonster路徑的child來源與virtual target已在201-2閉合，剩餘socket／wire及runtime邊界給出具體驗收條件。本段沒有自動展開202。下段優先由T02已登記證據接回實際封包域，或查兩樹關聯在移除後的writer；不再將本段已完成的CDoll入口當未知重找。

## 10. 參考資料與驗證方法

遠端版本固定於本稿紀錄的main SHA；路徑如下（GitHub `we88ec3-prog/ttr_anal_multi`）：

- `kr/tasks/T08/README.md`、`task.json`、`LOCAL-FOLLOWUP-PACKET-STAGE-EFFECTS.md`。
- `kr-temp-roy/T08-KNOWLEDGE-BASE.md`；157／196／200完整原稿，檔名依本次04。
- `kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions/{0x4ae4d0.c,0x4af530.c,0x4add50.c}`，僅輔助。
- `AGENTS.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、bulk審核狀態索引。

使用GNU objdump的PE VA選窗；資料表用Python struct直接讀原始BIN，.text raw=VA-0x401000+0x400，.rdata raw=VA-0xBD2000+0x7D0600。下列附錄由指定起點重解；jump table獨立以DWORD列示，不將資料當代碼。全檔線性反組譯僅作xref候選搜尋；direct call還要回到caller窗口確認。

不是每個附錄helper都宣稱完整語意還原；附錄標出有界窗口。原始E8驗算、vtable實值、節區、原檔hash、輸出完整性檢查均附後。


### 核心偽碼（行為暫名，不是可直接部署原碼）

```cpp
// 只表達已驗成功路徑；錯誤／diagnostic helper的noreturn性質未擴大保證。
void packet7(B, L) {
  for (i=0; i < (L<2 ? 0 : (L-2)/26); ++i) {
    R = B+2+26*i;
    key = u16(R);
    if (main_find(&global_owner.tree8, key) != sentinel) continue;
    actor = construct_by_type(R[0]); // type1: alloc(0x434), ctor4D1710
    actor->word4=key;
    actor->dword9C=u32(R+18);
    actor->v3C(composite_from(R)); // CMonster: +88,+8C writer
    actor->v44(R+6,1); actor->v58(R[22]); actor->v5C(f32(R+14));
    // 其他已列於assembly的初始化、副作用在此省略，並非不存在。
    register_main(actor, &global_owner); // key=WORD actor+4
    if (u32(R+18)!=0) {
      rec=secondary_find(u32(R+18));
      if (rec && rec->dword4==0) {
        rec->dword4=key;
        found=main_find(key);
        rec->dword8=found ? u16(found+0x88) : 0;
      }
    }
  }
}
void packet_index8(B,L) {
  // 原碼在長度迴圈計算以前先讀B+2 WORD；此處不能推導短包安全。
  if (u16(B+2)!=0) { global_owner.cacheF8=0; clear_secondary(); }
  for (i=0;i<(L<4?0:(L-4)/22);++i) {
    Q=B+4+22*i; rec=secondary_find(u32(Q));
    if (!rec) {
      rec=allocate_2C_record(); rec->key=u32(Q);
      register_record(rec,&global_owner); // 不同於actor
    }
    update_record_fields(rec,Q); // 見欄位表
  }
}
void packet81(B,L) {
  for (i=0;i<(L<2?0:(L-2)/2);++i)
    erase_main_if_composite(&global_owner,0x06000000|u16(B+2+2*i));
}
```

`57E850` 的節點key比較使用signed `setl/jge`。duplicate支路釋放的是傳入的**候選node**，本窗口未釋放其payload記錄；不可把這視為duplicate record所有權完整回滾。4AF530在正常查到非空既有record時會直接復用，並不每次配置。所有插入／競爭路徑仍待查，不推導實際洩漏。

## 附錄A：本次來源與原始資料表

- 實際產製時間：`2026-10-28T19:18:24.053491+08:00`（Asia/Taipei）。
- 原始BIN：`02-Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 啟動器EXE亦可用但未當BIN替身；本輪未由EXE推導地址。
- 核對main HEAD：`7dd36c7fd9a2c1dc3697ace33ab001ac41bb881c`，GitHub branches/main與git ls-remote HEAD相符。
- [固定版本GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/tree/7dd36c7fd9a2c1dc3697ace33ab001ac41bb881c)。

```text

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         007d01f0  00401000  00401000  00000400  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .rdata        0018e07c  00bd2000  00bd2000  007d0600  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .data         0022b800  00d61000  00d61000  0095e800  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  3 .rsrc         0005af58  00fe9000  00fe9000  00b8a000  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
```

### CMonster主表（原始DWORD，非反編譯）

| slot | VA | raw | bytes | target |
|---|---|---|---|---|
| +0x0 | 0x00C0C9DC | 0x0080AFDC | `d0 18 4d 00` | 0x004D18D0 |
| +0x14 | 0x00C0C9F0 | 0x0080AFF0 | `80 1f 4d 00` | 0x004D1F80 |
| +0x30 | 0x00C0CA0C | 0x0080B00C | `10 19 4d 00` | 0x004D1910 |
| +0x3C | 0x00C0CA18 | 0x0080B018 | `b0 6f 4c 00` | 0x004C6FB0 |
| +0x40 | 0x00C0CA1C | 0x0080B01C | `d0 6f 4c 00` | 0x004C6FD0 |
| +0x44 | 0x00C0CA20 | 0x0080B020 | `90 8b 4c 00` | 0x004C8B90 |
| +0x58 | 0x00C0CA34 | 0x0080B034 | `30 8c 4c 00` | 0x004C8C30 |
| +0x5C | 0x00C0CA38 | 0x0080B038 | `40 8c 4c 00` | 0x004C8C40 |

### 0007 type jump table（資料）

| type | table VA | bytes | target |
|---|---|---|---|
| 0 | 0x004AED90 | `e4 e5 4a 00` | 0x004AE5E4 |
| 1 | 0x004AED94 | `71 e6 4a 00` | 0x004AE671 |
| 2 | 0x004AED98 | `83 ed 4a 00` | 0x004AED83 |
| 3 | 0x004AED9C | `83 ed 4a 00` | 0x004AED83 |
| 4 | 0x004AEDA0 | `83 ed 4a 00` | 0x004AED83 |
| 5 | 0x004AEDA4 | `83 ed 4a 00` | 0x004AED83 |
| 6 | 0x004AEDA8 | `0a e8 4a 00` | 0x004AE80A |
| 7 | 0x004AEDAC | `d6 e8 4a 00` | 0x004AE8D6 |

### 直接E8相對位移驗算

`target=callVA+5+signed_int32(displacement)`。逐項assert通過；並不涵蓋FF間接呼叫。

| call VA | raw | 原始5bytes | disp signed | target |
|---|---|---|---|---|
| 0x004AE692 | 0x000ADA92 | `e8 79 30 02 00` | 143481 | 0x004D1710 |
| 0x004AEC03 | 0x000AE003 | `e8 28 13 03 00` | 201512 | 0x004DFF30 |
| 0x004AF6EC | 0x000AEAEC | `e8 bf 08 03 00` | 198847 | 0x004DFFB0 |
| 0x004B3739 | 0x000B2B39 | `e8 22 b9 f5 ff` | -673502 | 0x0040F060 |
| 0x004B373E | 0x000B2B3E | `e8 4d c5 02 00` | 181581 | 0x004DFC90 |
| 0x004B2AC2 | 0x000B1EC2 | `e8 f9 d0 02 00` | 184569 | 0x004DFBC0 |
| 0x004DFF78 | 0x000DF378 | `e8 a3 ef 09 00` | 651171 | 0x0057EF20 |
| 0x004DFF82 | 0x000DF382 | `e8 79 f2 34 00` | 3469945 | 0x0082F200 |
| 0x004E0037 | 0x000DF437 | `e8 e4 ee 09 00` | 650980 | 0x0057EF20 |
| 0x004E0042 | 0x000DF442 | `e8 09 e8 09 00` | 649225 | 0x0057E850 |
| 0x004D1F80 | 0x000D1380 | `e8 db 63 ff ff` | -39973 | 0x004C8360 |
| 0x004D18E6 | 0x000D0CE6 | `e8 a5 62 ff ff` | -40283 | 0x004C7B90 |
| 0x004C83AF | 0x000C77AF | `e8 3c 62 2f 00` | 3105340 | 0x007BE5F0 |
| 0x004C70E1 | 0x000C64E1 | `e8 7a 33 00 00` | 13178 | 0x004CA460 |
| 0x004CA4BA | 0x000C98BA | `e8 01 8d 2d 00` | 2985217 | 0x007A31C0 |
| 0x007F6FDC | 0x003F63DC | `e8 cf 5f fe ff` | -106545 | 0x007DCFB0 |
| 0x004D193E | 0x000D0D3E | `e8 ad 64 ff ff` | -39763 | 0x004C7DF0 |
| 0x004C7E44 | 0x000C7244 | `e8 1f 94 3c 00` | 3970079 | 0x00891268 |
| 0x004C7E5D | 0x000C725D | `e8 ee cd 2d 00` | 3001838 | 0x007A4C50 |
| 0x004C7E7B | 0x000C727B | `e8 e0 25 00 00` | 9696 | 0x004CA460 |
| 0x004C7E92 | 0x000C7292 | `e8 c9 90 01 00` | 102601 | 0x004E0F60 |
| 0x004C810F | 0x000C750F | `e8 3c cb 2d 00` | 3001148 | 0x007A4C50 |
| 0x004C8140 | 0x000C7540 | `e8 1b 8e 01 00` | 101915 | 0x004E0F60 |
| 0x007A4FF7 | 0x003A43F7 | `e8 c4 01 00 00` | 452 | 0x007A51C0 |
| 0x007A5003 | 0x003A4403 | `e8 04 c2 0e 00` | 967172 | 0x0089120C |
| 0x007A5A0C | 0x003A4E0C | `e8 df 86 01 00` | 100063 | 0x007BE0F0 |
| 0x007A5AEF | 0x003A4EEF | `e8 5c 7d 01 00` | 97628 | 0x007BD850 |
| 0x007A5AF5 | 0x003A4EF5 | `e8 12 b7 0e 00` | 964370 | 0x0089120C |
| 0x0048F6EA | 0x0008EAEA | `e8 61 e6 01 00` | 124513 | 0x004ADD50 |
| 0x0048F73C | 0x0008EB3C | `e8 0f 86 02 00` | 165391 | 0x004B7D50 |

## 附錄B：原始BIN有界反組譯（含bytes）

所有stop為排他界線；含少量對齊int3。窗口終點若落入下一函式僅作鄰接上下文，不擴大語意主張。

### 本地handler表初始化有界窗口；不追socket：`0x004ADD50..0x004AE02D`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004add50 <.text+0xacd50>:
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
  4addac:	c7 40 04 f0 fa 4a 00 	mov    DWORD PTR [eax+0x4],0x4afaf0
  4addb3:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4addb6:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4addb9:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4addbc:	c7 40 5c 60 fe 4a 00 	mov    DWORD PTR [eax+0x5c],0x4afe60
  4addc3:	89 48 60             	mov    DWORD PTR [eax+0x60],ecx
  4addc6:	c7 40 64 30 01 4b 00 	mov    DWORD PTR [eax+0x64],0x4b0130
  4addcd:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  4addd0:	c7 40 6c c0 01 4b 00 	mov    DWORD PTR [eax+0x6c],0x4b01c0
  4addd7:	89 48 70             	mov    DWORD PTR [eax+0x70],ecx
  4addda:	c7 80 7c 05 00 00 d0 	mov    DWORD PTR [eax+0x57c],0x4b03d0
  4adde1:	03 4b 00 
  4adde4:	89 88 80 05 00 00    	mov    DWORD PTR [eax+0x580],ecx
  4addea:	c7 40 74 40 6c 43 00 	mov    DWORD PTR [eax+0x74],0x436c40
  4addf1:	89 48 78             	mov    DWORD PTR [eax+0x78],ecx
  4addf4:	c7 80 fc 09 00 00 40 	mov    DWORD PTR [eax+0x9fc],0x4b1940
  4addfb:	19 4b 00 
  4addfe:	89 88 00 0a 00 00    	mov    DWORD PTR [eax+0xa00],ecx
  4ade04:	c7 40 7c d0 19 4b 00 	mov    DWORD PTR [eax+0x7c],0x4b19d0
  4ade0b:	89 88 80 00 00 00    	mov    DWORD PTR [eax+0x80],ecx
  4ade11:	c7 80 84 00 00 00 30 	mov    DWORD PTR [eax+0x84],0x4b1a30
  4ade18:	1a 4b 00 
  4ade1b:	89 88 88 00 00 00    	mov    DWORD PTR [eax+0x88],ecx
  4ade21:	c7 80 8c 00 00 00 70 	mov    DWORD PTR [eax+0x8c],0x4b1a70
  4ade28:	1a 4b 00 
  4ade2b:	89 88 90 00 00 00    	mov    DWORD PTR [eax+0x90],ecx
  4ade31:	c7 80 1c 02 00 00 90 	mov    DWORD PTR [eax+0x21c],0x4b1a90
  4ade38:	1a 4b 00 
  4ade3b:	89 88 20 02 00 00    	mov    DWORD PTR [eax+0x220],ecx
  4ade41:	c7 80 94 00 00 00 f0 	mov    DWORD PTR [eax+0x94],0x4b24f0
  4ade48:	24 4b 00 
  4ade4b:	89 88 98 00 00 00    	mov    DWORD PTR [eax+0x98],ecx
  4ade51:	c7 80 a4 00 00 00 30 	mov    DWORD PTR [eax+0xa4],0x4c5930
  4ade58:	59 4c 00 
  4ade5b:	89 88 a8 00 00 00    	mov    DWORD PTR [eax+0xa8],ecx
  4ade61:	c7 80 ac 00 00 00 20 	mov    DWORD PTR [eax+0xac],0x4b2620
  4ade68:	26 4b 00 
  4ade6b:	89 88 b0 00 00 00    	mov    DWORD PTR [eax+0xb0],ecx
  4ade71:	89 90 b4 00 00 00    	mov    DWORD PTR [eax+0xb4],edx
  4ade77:	89 88 b8 00 00 00    	mov    DWORD PTR [eax+0xb8],ecx
  4ade7d:	c7 80 c4 00 00 00 30 	mov    DWORD PTR [eax+0xc4],0x4b2730
  4ade84:	27 4b 00 
  4ade87:	89 88 c8 00 00 00    	mov    DWORD PTR [eax+0xc8],ecx
  4ade8d:	c7 80 d4 00 00 00 d0 	mov    DWORD PTR [eax+0xd4],0x4b28d0
  4ade94:	28 4b 00 
  4ade97:	89 88 d8 00 00 00    	mov    DWORD PTR [eax+0xd8],ecx
  4ade9d:	c7 80 dc 00 00 00 80 	mov    DWORD PTR [eax+0xdc],0x4ae380
  4adea4:	e3 4a 00 
  4adea7:	89 88 e0 00 00 00    	mov    DWORD PTR [eax+0xe0],ecx
  4adead:	c7 80 3c 01 00 00 f0 	mov    DWORD PTR [eax+0x13c],0x4b2af0
  4adeb4:	2a 4b 00 
  4adeb7:	89 88 40 01 00 00    	mov    DWORD PTR [eax+0x140],ecx
  4adebd:	c7 80 44 02 00 00 e0 	mov    DWORD PTR [eax+0x244],0x4b32e0
  4adec4:	32 4b 00 
  4adec7:	89 88 48 02 00 00    	mov    DWORD PTR [eax+0x248],ecx
  4adecd:	c7 80 0c 01 00 00 d0 	mov    DWORD PTR [eax+0x10c],0x4b2cd0
  4aded4:	2c 4b 00 
  4aded7:	89 88 10 01 00 00    	mov    DWORD PTR [eax+0x110],ecx
  4adedd:	c7 80 14 01 00 00 40 	mov    DWORD PTR [eax+0x114],0x4b3040
  4adee4:	30 4b 00 
  4adee7:	89 88 18 01 00 00    	mov    DWORD PTR [eax+0x118],ecx
  4adeed:	c7 80 34 01 00 00 60 	mov    DWORD PTR [eax+0x134],0x4b3060
  4adef4:	30 4b 00 
  4adef7:	89 88 38 01 00 00    	mov    DWORD PTR [eax+0x138],ecx
  4adefd:	c7 80 ec 08 00 00 60 	mov    DWORD PTR [eax+0x8ec],0x4b3060
  4adf04:	30 4b 00 
  4adf07:	89 88 f0 08 00 00    	mov    DWORD PTR [eax+0x8f0],ecx
  4adf0d:	c7 80 44 01 00 00 d0 	mov    DWORD PTR [eax+0x144],0x4b1bd0
  4adf14:	1b 4b 00 
  4adf17:	89 88 48 01 00 00    	mov    DWORD PTR [eax+0x148],ecx
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
  4adf6d:	c7 80 4c 02 00 00 50 	mov    DWORD PTR [eax+0x24c],0x4b3350
  4adf74:	33 4b 00 
  4adf77:	89 88 50 02 00 00    	mov    DWORD PTR [eax+0x250],ecx
  4adf7d:	c7 80 5c 02 00 00 f0 	mov    DWORD PTR [eax+0x25c],0x4b34f0
  4adf84:	34 4b 00 
  4adf87:	89 88 60 02 00 00    	mov    DWORD PTR [eax+0x260],ecx
  4adf8d:	c7 80 6c 02 00 00 10 	mov    DWORD PTR [eax+0x26c],0x4b3510
  4adf94:	35 4b 00 
  4adf97:	89 88 70 02 00 00    	mov    DWORD PTR [eax+0x270],ecx
  4adf9d:	c7 80 74 02 00 00 70 	mov    DWORD PTR [eax+0x274],0x4b3570
  4adfa4:	35 4b 00 
  4adfa7:	89 88 78 02 00 00    	mov    DWORD PTR [eax+0x278],ecx
  4adfad:	c7 80 84 02 00 00 00 	mov    DWORD PTR [eax+0x284],0x4b3600
  4adfb4:	36 4b 00 
  4adfb7:	89 88 88 02 00 00    	mov    DWORD PTR [eax+0x288],ecx
  4adfbd:	c7 80 8c 02 00 00 10 	mov    DWORD PTR [eax+0x28c],0x4b3710
  4adfc4:	37 4b 00 
  4adfc7:	89 88 90 02 00 00    	mov    DWORD PTR [eax+0x290],ecx
  4adfcd:	c7 80 a4 04 00 00 f0 	mov    DWORD PTR [eax+0x4a4],0x4af1f0
  4adfd4:	f1 4a 00 
  4adfd7:	89 88 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],ecx
  4adfdd:	c7 80 f4 02 00 00 10 	mov    DWORD PTR [eax+0x2f4],0x4b3c10
  4adfe4:	3c 4b 00 
  4adfe7:	89 88 f8 02 00 00    	mov    DWORD PTR [eax+0x2f8],ecx
  4adfed:	c7 80 e4 02 00 00 a0 	mov    DWORD PTR [eax+0x2e4],0x4b3da0
  4adff4:	3d 4b 00 
  4adff7:	89 88 e8 02 00 00    	mov    DWORD PTR [eax+0x2e8],ecx
  4adffd:	c7 80 84 01 00 00 60 	mov    DWORD PTR [eax+0x184],0x4b3760
  4ae004:	37 4b 00 
  4ae007:	89 88 88 01 00 00    	mov    DWORD PTR [eax+0x188],ecx
  4ae00d:	c7 80 1c 03 00 00 e0 	mov    DWORD PTR [eax+0x31c],0x4b3ee0
  4ae014:	3e 4b 00 
  4ae017:	89 88 20 03 00 00    	mov    DWORD PTR [eax+0x320],ecx
  4ae01d:	c7 80 64 03 00 00 50 	mov    DWORD PTR [eax+0x364],0x4b4050
  4ae024:	40 4b 00 
  4ae027:	89 88 68 03 00 00    	mov    DWORD PTR [eax+0x368],ecx
```

### 0007完整code至jump table之前；不把表當code：`0x004AE4D0..0x004AED90`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ae4d0 <.text+0xad4d0>:
  4ae4d0:	55                   	push   ebp
  4ae4d1:	8b ec                	mov    ebp,esp
  4ae4d3:	83 e4 f8             	and    esp,0xfffffff8
  4ae4d6:	6a ff                	push   0xffffffff
  4ae4d8:	68 db 0c 94 00       	push   0x940cdb
  4ae4dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ae4e3:	50                   	push   eax
  4ae4e4:	81 ec 38 01 00 00    	sub    esp,0x138
  4ae4ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ae4ef:	33 c4                	xor    eax,esp
  4ae4f1:	89 84 24 30 01 00 00 	mov    DWORD PTR [esp+0x130],eax
  4ae4f8:	53                   	push   ebx
  4ae4f9:	56                   	push   esi
  4ae4fa:	57                   	push   edi
  4ae4fb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ae500:	33 c4                	xor    eax,esp
  4ae502:	50                   	push   eax
  4ae503:	8d 84 24 48 01 00 00 	lea    eax,[esp+0x148]
  4ae50a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ae510:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4ae513:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4ae516:	83 f8 02             	cmp    eax,0x2
  4ae519:	73 04                	jae    0x4ae51f
  4ae51b:	33 d2                	xor    edx,edx
  4ae51d:	eb 0d                	jmp    0x4ae52c
  4ae51f:	8d 48 fe             	lea    ecx,[eax-0x2]
  4ae522:	b8 4f ec c4 4e       	mov    eax,0x4ec4ec4f
  4ae527:	f7 e1                	mul    ecx
  4ae529:	c1 ea 03             	shr    edx,0x3
  4ae52c:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  4ae530:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  4ae537:	00 
  4ae538:	85 d2                	test   edx,edx
  4ae53a:	0f 84 18 08 00 00    	je     0x4aed58
  4ae540:	83 c3 06             	add    ebx,0x6
  4ae543:	eb 0b                	jmp    0x4ae550
  4ae545:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4ae54c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4ae550:	b8 01 00 00 00       	mov    eax,0x1
  4ae555:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4ae559:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4ae55f:	75 2e                	jne    0x4ae58f
  4ae561:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4ae567:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x0
  4ae56e:	00 00 00 00 
  4ae572:	e8 19 07 03 00       	call   0x4dec90
  4ae577:	68 30 ce bc 00       	push   0xbcce30
  4ae57c:	e8 99 3d 3e 00       	call   0x89231a
  4ae581:	83 c4 04             	add    esp,0x4
  4ae584:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae58b:	ff ff ff ff 
  4ae58f:	0f b7 53 fc          	movzx  edx,WORD PTR [ebx-0x4]
  4ae593:	8d 44 24 18          	lea    eax,[esp+0x18]
  4ae597:	50                   	push   eax
  4ae598:	8d 44 24 58          	lea    eax,[esp+0x58]
  4ae59c:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4ae5a1:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4ae5a5:	e8 56 09 38 00       	call   0x82ef00
  4ae5aa:	8b 08                	mov    ecx,DWORD PTR [eax]
  4ae5ac:	3b 0d 3c b1 fa 00    	cmp    ecx,DWORD PTR ds:0xfab13c
  4ae5b2:	0f 85 8a 07 00 00    	jne    0x4aed42
  4ae5b8:	0f b6 43 fc          	movzx  eax,BYTE PTR [ebx-0x4]
  4ae5bc:	0f b6 7b fe          	movzx  edi,BYTE PTR [ebx-0x2]
  4ae5c0:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4ae5c3:	4f                   	dec    edi
  4ae5c4:	8b d0                	mov    edx,eax
  4ae5c6:	c1 e2 08             	shl    edx,0x8
  4ae5c9:	0b fa                	or     edi,edx
  4ae5cb:	c1 e7 10             	shl    edi,0x10
  4ae5ce:	0b f9                	or     edi,ecx
  4ae5d0:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4ae5d4:	83 f8 07             	cmp    eax,0x7
  4ae5d7:	0f 87 a6 07 00 00    	ja     0x4aed83
  4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
  4ae5e4:	68 44 04 00 00       	push   0x444
  4ae5e9:	e8 7a 2c 3e 00       	call   0x891268
  4ae5ee:	83 c4 04             	add    esp,0x4
  4ae5f1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae5f5:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  4ae5fc:	01 00 00 00 
  4ae600:	85 c0                	test   eax,eax
  4ae602:	74 0e                	je     0x4ae612
  4ae604:	8b 53 0e             	mov    edx,DWORD PTR [ebx+0xe]
  4ae607:	52                   	push   edx
  4ae608:	50                   	push   eax
  4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
  4ae60e:	8b f0                	mov    esi,eax
  4ae610:	eb 02                	jmp    0x4ae614
  4ae612:	33 f6                	xor    esi,esi
  4ae614:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae61b:	ff ff ff ff 
  4ae61f:	e8 7c 65 f5 ff       	call   0x404ba0
  4ae624:	8b 80 50 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f50]
  4ae62a:	39 43 0e             	cmp    DWORD PTR [ebx+0xe],eax
  4ae62d:	0f 85 e4 02 00 00    	jne    0x4ae917
  4ae633:	e8 68 65 f5 ff       	call   0x404ba0
  4ae638:	8b 90 24 69 00 00    	mov    edx,DWORD PTR [eax+0x6924]
  4ae63e:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  4ae641:	83 f8 09             	cmp    eax,0x9
  4ae644:	0f 87 cd 02 00 00    	ja     0x4ae917
  4ae64a:	8b c8                	mov    ecx,eax
  4ae64c:	69 c9 10 02 00 00    	imul   ecx,ecx,0x210
  4ae652:	03 ca                	add    ecx,edx
  4ae654:	0f 84 bd 02 00 00    	je     0x4ae917
  4ae65a:	83 79 5c 00          	cmp    DWORD PTR [ecx+0x5c],0x0
  4ae65e:	0f 85 b3 02 00 00    	jne    0x4ae917
  4ae664:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ae666:	50                   	push   eax
  4ae667:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4ae66a:	ff d0                	call   eax
  4ae66c:	e9 a6 02 00 00       	jmp    0x4ae917
  4ae671:	68 34 04 00 00       	push   0x434
  4ae676:	e8 ed 2b 3e 00       	call   0x891268
  4ae67b:	83 c4 04             	add    esp,0x4
  4ae67e:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae682:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x2
  4ae689:	02 00 00 00 
  4ae68d:	85 c0                	test   eax,eax
  4ae68f:	74 0a                	je     0x4ae69b
  4ae691:	50                   	push   eax
  4ae692:	e8 79 30 02 00       	call   0x4d1710
  4ae697:	8b f0                	mov    esi,eax
  4ae699:	eb 02                	jmp    0x4ae69d
  4ae69b:	33 f6                	xor    esi,esi
  4ae69d:	6a 48                	push   0x48
  4ae69f:	c7 84 24 54 01 00 00 	mov    DWORD PTR [esp+0x154],0xffffffff
  4ae6a6:	ff ff ff ff 
  4ae6aa:	e8 b9 2b 3e 00       	call   0x891268
  4ae6af:	8b f8                	mov    edi,eax
  4ae6b1:	83 c4 04             	add    esp,0x4
  4ae6b4:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4ae6b8:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x3
  4ae6bf:	03 00 00 00 
  4ae6c3:	85 ff                	test   edi,edi
  4ae6c5:	74 78                	je     0x4ae73f
  4ae6c7:	0f b7 46 04          	movzx  eax,WORD PTR [esi+0x4]
  4ae6cb:	0f 57 c0             	xorps  xmm0,xmm0
  4ae6ce:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4ae6d1:	c7 07 07 00 00 00    	mov    DWORD PTR [edi],0x7
  4ae6d7:	c7 47 08 01 00 00 00 	mov    DWORD PTR [edi+0x8],0x1
  4ae6de:	c6 47 0c 01          	mov    BYTE PTR [edi+0xc],0x1
  4ae6e2:	8b 4b 02             	mov    ecx,DWORD PTR [ebx+0x2]
  4ae6e5:	89 4f 10             	mov    DWORD PTR [edi+0x10],ecx
  4ae6e8:	8b 53 06             	mov    edx,DWORD PTR [ebx+0x6]
  4ae6eb:	89 57 14             	mov    DWORD PTR [edi+0x14],edx
  4ae6ee:	f3 0f 11 44 24 3c    	movss  DWORD PTR [esp+0x3c],xmm0
  4ae6f4:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  4ae6f8:	89 4f 20             	mov    DWORD PTR [edi+0x20],ecx
  4ae6fb:	33 d2                	xor    edx,edx
  4ae6fd:	f3 0f 11 44 24 38    	movss  DWORD PTR [esp+0x38],xmm0
  4ae703:	8b 44 24 38          	mov    eax,DWORD PTR [esp+0x38]
  4ae707:	8d 4f 24             	lea    ecx,[edi+0x24]
  4ae70a:	f3 0f 11 47 18       	movss  DWORD PTR [edi+0x18],xmm0
  4ae70f:	89 47 1c             	mov    DWORD PTR [edi+0x1c],eax
  4ae712:	52                   	push   edx
  4ae713:	c7 41 14 07 00 00 00 	mov    DWORD PTR [ecx+0x14],0x7
  4ae71a:	c7 41 10 00 00 00 00 	mov    DWORD PTR [ecx+0x10],0x0
  4ae721:	68 fc d1 be 00       	push   0xbed1fc
  4ae726:	66 89 11             	mov    WORD PTR [ecx],dx
  4ae729:	e8 32 3a f5 ff       	call   0x402160
  4ae72e:	0f 57 c0             	xorps  xmm0,xmm0
  4ae731:	c7 47 40 00 00 00 00 	mov    DWORD PTR [edi+0x40],0x0
  4ae738:	f3 0f 11 47 44       	movss  DWORD PTR [edi+0x44],xmm0
  4ae73d:	eb 02                	jmp    0x4ae741
  4ae73f:	33 ff                	xor    edi,edi
  4ae741:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae748:	ff ff ff ff 
  4ae74c:	f6 05 c0 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3c0,0x1
  4ae753:	75 1e                	jne    0x4ae773
  4ae755:	83 0d c0 f3 fd 00 01 	or     DWORD PTR ds:0xfdf3c0,0x1
  4ae75c:	68 50 df bc 00       	push   0xbcdf50
  4ae761:	c7 05 c4 f3 fd 00 00 	mov    DWORD PTR ds:0xfdf3c4,0x0
  4ae768:	00 00 00 
  4ae76b:	e8 aa 3b 3e 00       	call   0x89231a
  4ae770:	83 c4 04             	add    esp,0x4
  4ae773:	a1 c4 f3 fd 00       	mov    eax,ds:0xfdf3c4
  4ae778:	57                   	push   edi
  4ae779:	50                   	push   eax
  4ae77a:	e8 41 0e 0c 00       	call   0x56f5c0
  4ae77f:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  4ae786:	0f b6 43 13          	movzx  eax,BYTE PTR [ebx+0x13]
  4ae78a:	89 86 24 04 00 00    	mov    DWORD PTR [esi+0x424],eax
  4ae790:	75 2f                	jne    0x4ae7c1
  4ae792:	83 0d b0 75 fb 00 01 	or     DWORD PTR ds:0xfb75b0,0x1
  4ae799:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x4
  4ae7a0:	04 00 00 00 
  4ae7a4:	e8 d7 55 04 00       	call   0x4f3d80
  4ae7a9:	68 e0 d1 bc 00       	push   0xbcd1e0
  4ae7ae:	e8 67 3b 3e 00       	call   0x89231a
  4ae7b3:	83 c4 04             	add    esp,0x4
  4ae7b6:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae7bd:	ff ff ff ff 
  4ae7c1:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4ae7c5:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  4ae7c9:	8d 54 24 18          	lea    edx,[esp+0x18]
  4ae7cd:	b9 70 74 fb 00       	mov    ecx,0xfb7470
  4ae7d2:	e8 99 92 04 00       	call   0x4f7a70
  4ae7d7:	80 78 61 00          	cmp    BYTE PTR [eax+0x61],0x0
  4ae7db:	75 1c                	jne    0x4ae7f9
  4ae7dd:	8b 86 68 03 00 00    	mov    eax,DWORD PTR [esi+0x368]
  4ae7e3:	33 c9                	xor    ecx,ecx
  4ae7e5:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  4ae7e9:	3b c1                	cmp    eax,ecx
  4ae7eb:	74 14                	je     0x4ae801
  4ae7ed:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae7f1:	89 48 24             	mov    DWORD PTR [eax+0x24],ecx
  4ae7f4:	e9 1e 01 00 00       	jmp    0x4ae917
  4ae7f9:	c7 44 24 20 01 00 00 	mov    DWORD PTR [esp+0x20],0x1
  4ae800:	00 
  4ae801:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae805:	e9 0d 01 00 00       	jmp    0x4ae917
  4ae80a:	68 2c 04 00 00       	push   0x42c
  4ae80f:	e8 54 2a 3e 00       	call   0x891268
  4ae814:	83 c4 04             	add    esp,0x4
  4ae817:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae81b:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x5
  4ae822:	05 00 00 00 
  4ae826:	85 c0                	test   eax,eax
  4ae828:	74 0c                	je     0x4ae836
  4ae82a:	50                   	push   eax
  4ae82b:	e8 f0 38 02 00       	call   0x4d2120
  4ae830:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4ae834:	eb 08                	jmp    0x4ae83e
  4ae836:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4ae83d:	00 
  4ae83e:	83 ce ff             	or     esi,0xffffffff
  4ae841:	89 b4 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],esi
  4ae848:	f6 05 c8 18 fe 00 01 	test   BYTE PTR ds:0xfe18c8,0x1
  4ae84f:	75 2b                	jne    0x4ae87c
  4ae851:	83 0d c8 18 fe 00 01 	or     DWORD PTR ds:0xfe18c8,0x1
  4ae858:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x6
  4ae85f:	06 00 00 00 
  4ae863:	e8 08 11 09 00       	call   0x53f970
  4ae868:	68 10 e8 bc 00       	push   0xbce810
  4ae86d:	e8 a8 3a 3e 00       	call   0x89231a
  4ae872:	83 c4 04             	add    esp,0x4
  4ae875:	89 b4 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],esi
  4ae87c:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  4ae87f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4ae883:	52                   	push   edx
  4ae884:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae888:	b9 dc 18 fe 00       	mov    ecx,0xfe18dc
  4ae88d:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4ae891:	e8 2a 50 39 00       	call   0x8438c0
  4ae896:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4ae89a:	3b 0d e0 18 fe 00    	cmp    ecx,DWORD PTR ds:0xfe18e0
  4ae8a0:	74 2e                	je     0x4ae8d0
  4ae8a2:	8a 43 fd             	mov    al,BYTE PTR [ebx-0x3]
  4ae8a5:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  4ae8a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4ae8ac:	8b 0d ec 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe18ec
  4ae8b2:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  4ae8b6:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae8ba:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4ae8bf:	89 74 24 48          	mov    DWORD PTR [esp+0x48],esi
  4ae8c3:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  4ae8c7:	e8 d4 02 09 00       	call   0x53eba0
  4ae8cc:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae8d0:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4ae8d4:	eb 41                	jmp    0x4ae917
  4ae8d6:	68 28 04 00 00       	push   0x428
  4ae8db:	e8 88 29 3e 00       	call   0x891268
  4ae8e0:	83 c4 04             	add    esp,0x4
  4ae8e3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae8e7:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x7
  4ae8ee:	07 00 00 00 
  4ae8f2:	85 c0                	test   eax,eax
  4ae8f4:	74 08                	je     0x4ae8fe
  4ae8f6:	50                   	push   eax
  4ae8f7:	e8 64 27 02 00       	call   0x4d1060
  4ae8fc:	eb 02                	jmp    0x4ae900
  4ae8fe:	33 c0                	xor    eax,eax
  4ae900:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae907:	ff ff ff ff 
  4ae90b:	0f b6 4b 13          	movzx  ecx,BYTE PTR [ebx+0x13]
  4ae90f:	89 88 20 04 00 00    	mov    DWORD PTR [eax+0x420],ecx
  4ae915:	8b f0                	mov    esi,eax
  4ae917:	85 f6                	test   esi,esi
  4ae919:	0f 84 64 04 00 00    	je     0x4aed83
  4ae91f:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  4ae926:	75 2f                	jne    0x4ae957
  4ae928:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  4ae92f:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x8
  4ae936:	08 00 00 00 
  4ae93a:	e8 01 e6 2e 00       	call   0x79cf40
  4ae93f:	68 80 db bc 00       	push   0xbcdb80
  4ae944:	e8 d1 39 3e 00       	call   0x89231a
  4ae949:	83 c4 04             	add    esp,0x4
  4ae94c:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae953:	ff ff ff ff 
  4ae957:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  4ae95a:	8d 44 24 14          	lea    eax,[esp+0x14]
  4ae95e:	50                   	push   eax
  4ae95f:	8d 44 24 30          	lea    eax,[esp+0x30]
  4ae963:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  4ae968:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4ae96c:	e8 1f 6e 06 00       	call   0x515790
  4ae971:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  4ae975:	3b 05 94 0e fc 00    	cmp    eax,DWORD PTR ds:0xfc0e94
  4ae97b:	74 0d                	je     0x4ae98a
  4ae97d:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4ae980:	83 78 54 00          	cmp    DWORD PTR [eax+0x54],0x0
  4ae984:	0f 85 23 01 00 00    	jne    0x4aeaad
  4ae98a:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4ae990:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ae992:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  4ae995:	ff d0                	call   eax
  4ae997:	85 c0                	test   eax,eax
  4ae999:	0f 84 cd 00 00 00    	je     0x4aea6c
  4ae99f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4ae9a6:	8b 88 9c 00 00 00    	mov    ecx,DWORD PTR [eax+0x9c]
  4ae9ac:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4ae9b0:	75 2f                	jne    0x4ae9e1
  4ae9b2:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4ae9b9:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x9
  4ae9c0:	09 00 00 00 
  4ae9c4:	e8 c7 02 03 00       	call   0x4dec90
  4ae9c9:	68 30 ce bc 00       	push   0xbcce30
  4ae9ce:	e8 47 39 3e 00       	call   0x89231a
  4ae9d3:	83 c4 04             	add    esp,0x4
  4ae9d6:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae9dd:	ff ff ff ff 
  4ae9e1:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4ae9e5:	8d 44 24 14          	lea    eax,[esp+0x14]
  4ae9e9:	50                   	push   eax
  4ae9ea:	8d 44 24 38          	lea    eax,[esp+0x38]
  4ae9ee:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4ae9f3:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4ae9f7:	e8 c4 4e 39 00       	call   0x8438c0
  4ae9fc:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  4aea00:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4aea06:	74 64                	je     0x4aea6c
  4aea08:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4aea0b:	85 c0                	test   eax,eax
  4aea0d:	74 5d                	je     0x4aea6c
  4aea0f:	80 78 20 05          	cmp    BYTE PTR [eax+0x20],0x5
  4aea13:	72 57                	jb     0x4aea6c
  4aea15:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4aea18:	51                   	push   ecx
  4aea19:	68 d8 69 c0 00       	push   0xc069d8
  4aea1e:	8d 54 24 7c          	lea    edx,[esp+0x7c]
  4aea22:	e8 59 92 00 00       	call   0x4b7c80
  4aea27:	83 c4 08             	add    esp,0x8
  4aea2a:	8d 54 24 74          	lea    edx,[esp+0x74]
  4aea2e:	52                   	push   edx
  4aea2f:	8d 4c 24 5c          	lea    ecx,[esp+0x5c]
  4aea33:	e8 18 38 f5 ff       	call   0x402250
  4aea38:	8d 44 24 58          	lea    eax,[esp+0x58]
  4aea3c:	50                   	push   eax
  4aea3d:	c7 84 24 54 01 00 00 	mov    DWORD PTR [esp+0x154],0xa
  4aea44:	0a 00 00 00 
  4aea48:	e8 73 0e f6 ff       	call   0x40f8c0
  4aea4d:	8b f8                	mov    edi,eax
  4aea4f:	e8 dc 80 02 00       	call   0x4d6b30
  4aea54:	8d 4c 24 58          	lea    ecx,[esp+0x58]
  4aea58:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aea5f:	ff ff ff ff 
  4aea63:	e8 d8 b9 04 00       	call   0x4fa440
  4aea68:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4aea6c:	f6 05 40 0e fc 00 01 	test   BYTE PTR ds:0xfc0e40,0x1
  4aea73:	75 2f                	jne    0x4aeaa4
  4aea75:	83 0d 40 0e fc 00 01 	or     DWORD PTR ds:0xfc0e40,0x1
  4aea7c:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xb
  4aea83:	0b 00 00 00 
  4aea87:	e8 e4 1c 09 00       	call   0x540770
  4aea8c:	68 60 db bc 00       	push   0xbcdb60
  4aea91:	e8 84 38 3e 00       	call   0x89231a
  4aea96:	83 c4 04             	add    esp,0x4
  4aea99:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aeaa0:	ff ff ff ff 
  4aeaa4:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4aeaa7:	51                   	push   ecx
  4aeaa8:	e8 63 2b 09 00       	call   0x541610
  4aeaad:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  4aeab4:	75 2f                	jne    0x4aeae5
  4aeab6:	83 0d b0 75 fb 00 01 	or     DWORD PTR ds:0xfb75b0,0x1
  4aeabd:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xc
  4aeac4:	0c 00 00 00 
  4aeac8:	e8 b3 52 04 00       	call   0x4f3d80
  4aeacd:	68 e0 d1 bc 00       	push   0xbcd1e0
  4aead2:	e8 43 38 3e 00       	call   0x89231a
  4aead7:	83 c4 04             	add    esp,0x4
  4aeada:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aeae1:	ff ff ff ff 
  4aeae5:	8d 54 24 14          	lea    edx,[esp+0x14]
  4aeae9:	b9 70 74 fb 00       	mov    ecx,0xfb7470
  4aeaee:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4aeaf2:	e8 79 8f 04 00       	call   0x4f7a70
  4aeaf7:	0f b6 50 61          	movzx  edx,BYTE PTR [eax+0x61]
  4aeafb:	8b 86 f0 00 00 00    	mov    eax,DWORD PTR [esi+0xf0]
  4aeb01:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aeb04:	89 96 1c 04 00 00    	mov    DWORD PTR [esi+0x41c],edx
  4aeb0a:	0f b6 53 15          	movzx  edx,BYTE PTR [ebx+0x15]
  4aeb0e:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4aeb14:	52                   	push   edx
  4aeb15:	ff d0                	call   eax
  4aeb17:	8b 43 0e             	mov    eax,DWORD PTR [ebx+0xe]
  4aeb1a:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb1c:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  4aeb22:	0f b6 43 14          	movzx  eax,BYTE PTR [ebx+0x14]
  4aeb26:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  4aeb2c:	66 8b 43 fc          	mov    ax,WORD PTR [ebx-0x4]
  4aeb30:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  4aeb34:	8b 42 3c             	mov    eax,DWORD PTR [edx+0x3c]
  4aeb37:	57                   	push   edi
  4aeb38:	8b ce                	mov    ecx,esi
  4aeb3a:	ff d0                	call   eax
  4aeb3c:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb3e:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4aeb41:	6a 01                	push   0x1
  4aeb43:	8d 43 02             	lea    eax,[ebx+0x2]
  4aeb46:	50                   	push   eax
  4aeb47:	8b ce                	mov    ecx,esi
  4aeb49:	ff d2                	call   edx
  4aeb4b:	0f b6 4b 12          	movzx  ecx,BYTE PTR [ebx+0x12]
  4aeb4f:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb51:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4aeb54:	51                   	push   ecx
  4aeb55:	8b ce                	mov    ecx,esi
  4aeb57:	ff d2                	call   edx
  4aeb59:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb5b:	d9 43 0a             	fld    DWORD PTR [ebx+0xa]
  4aeb5e:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4aeb61:	51                   	push   ecx
  4aeb62:	8b ce                	mov    ecx,esi
  4aeb64:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aeb67:	ff d2                	call   edx
  4aeb69:	80 7b 15 18          	cmp    BYTE PTR [ebx+0x15],0x18
  4aeb6d:	75 07                	jne    0x4aeb76
  4aeb6f:	c6 86 bc 00 00 00 01 	mov    BYTE PTR [esi+0xbc],0x1
  4aeb76:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb78:	8b 50 30             	mov    edx,DWORD PTR [eax+0x30]
  4aeb7b:	8b ce                	mov    ecx,esi
  4aeb7d:	ff d2                	call   edx
  4aeb7f:	8a 43 fc             	mov    al,BYTE PTR [ebx-0x4]
  4aeb82:	3c 01                	cmp    al,0x1
  4aeb84:	75 29                	jne    0x4aebaf
  4aeb86:	83 7c 24 20 00       	cmp    DWORD PTR [esp+0x20],0x0
  4aeb8b:	75 11                	jne    0x4aeb9e
  4aeb8d:	8b 86 68 03 00 00    	mov    eax,DWORD PTR [esi+0x368]
  4aeb93:	85 c0                	test   eax,eax
  4aeb95:	74 07                	je     0x4aeb9e
  4aeb97:	c7 40 24 00 00 00 00 	mov    DWORD PTR [eax+0x24],0x0
  4aeb9e:	33 c0                	xor    eax,eax
  4aeba0:	80 7b 13 04          	cmp    BYTE PTR [ebx+0x13],0x4
  4aeba4:	0f 94 c0             	sete   al
  4aeba7:	89 86 28 04 00 00    	mov    DWORD PTR [esi+0x428],eax
  4aebad:	eb 15                	jmp    0x4aebc4
  4aebaf:	3c 06                	cmp    al,0x6
  4aebb1:	75 11                	jne    0x4aebc4
  4aebb3:	8b 86 68 03 00 00    	mov    eax,DWORD PTR [esi+0x368]
  4aebb9:	85 c0                	test   eax,eax
  4aebbb:	74 07                	je     0x4aebc4
  4aebbd:	c7 40 24 00 00 00 00 	mov    DWORD PTR [eax+0x24],0x0
  4aebc4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aebcb:	75 2f                	jne    0x4aebfc
  4aebcd:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aebd4:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xd
  4aebdb:	0d 00 00 00 
  4aebdf:	e8 ac 00 03 00       	call   0x4dec90
  4aebe4:	68 30 ce bc 00       	push   0xbcce30
  4aebe9:	e8 2c 37 3e 00       	call   0x89231a
  4aebee:	83 c4 04             	add    esp,0x4
  4aebf1:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aebf8:	ff ff ff ff 
  4aebfc:	68 30 b1 fa 00       	push   0xfab130
  4aec01:	8b c6                	mov    eax,esi
  4aec03:	e8 28 13 03 00       	call   0x4dff30
  4aec08:	83 7b 0e 00          	cmp    DWORD PTR [ebx+0xe],0x0
  4aec0c:	0f 84 86 00 00 00    	je     0x4aec98
  4aec12:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aec19:	75 2f                	jne    0x4aec4a
  4aec1b:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aec22:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xe
  4aec29:	0e 00 00 00 
  4aec2d:	e8 5e 00 03 00       	call   0x4dec90
  4aec32:	68 30 ce bc 00       	push   0xbcce30
  4aec37:	e8 de 36 3e 00       	call   0x89231a
  4aec3c:	83 c4 04             	add    esp,0x4
  4aec3f:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aec46:	ff ff ff ff 
  4aec4a:	8b 4b 0e             	mov    ecx,DWORD PTR [ebx+0xe]
  4aec4d:	8d 54 24 14          	lea    edx,[esp+0x14]
  4aec51:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4aec55:	52                   	push   edx
  4aec56:	8d 44 24 34          	lea    eax,[esp+0x34]
  4aec5a:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4aec5f:	e8 5c 4c 39 00       	call   0x8438c0
  4aec64:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  4aec68:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4aec6e:	74 28                	je     0x4aec98
  4aec70:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  4aec73:	85 c9                	test   ecx,ecx
  4aec75:	74 21                	je     0x4aec98
  4aec77:	83 79 04 00          	cmp    DWORD PTR [ecx+0x4],0x0
  4aec7b:	75 1b                	jne    0x4aec98
  4aec7d:	0f b7 43 fc          	movzx  eax,WORD PTR [ebx-0x4]
  4aec81:	8b f9                	mov    edi,ecx
  4aec83:	e8 c8 81 01 00       	call   0x4c6e50
  4aec88:	80 7e 04 00          	cmp    BYTE PTR [esi+0x4],0x0
  4aec8c:	75 0a                	jne    0x4aec98
  4aec8e:	c7 86 98 00 00 00 01 	mov    DWORD PTR [esi+0x98],0x1
  4aec95:	00 00 00 
  4aec98:	8a 43 13             	mov    al,BYTE PTR [ebx+0x13]
  4aec9b:	3c 04                	cmp    al,0x4
  4aec9d:	75 5a                	jne    0x4aecf9
  4aec9f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aeca6:	75 2f                	jne    0x4aecd7
  4aeca8:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aecaf:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xf
  4aecb6:	0f 00 00 00 
  4aecba:	e8 d1 ff 02 00       	call   0x4dec90
  4aecbf:	68 30 ce bc 00       	push   0xbcce30
  4aecc4:	e8 51 36 3e 00       	call   0x89231a
  4aecc9:	83 c4 04             	add    esp,0x4
  4aeccc:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aecd3:	ff ff ff ff 
  4aecd7:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4aecdc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4aece0:	8d 78 20             	lea    edi,[eax+0x20]
  4aece3:	8d 43 fc             	lea    eax,[ebx-0x4]
  4aece6:	e8 b5 f0 08 00       	call   0x53dda0
  4aeceb:	66 8b 43 fc          	mov    ax,WORD PTR [ebx-0x4]
  4aecef:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4aecf3:	66 89 41 30          	mov    WORD PTR [ecx+0x30],ax
  4aecf7:	eb 49                	jmp    0x4aed42
  4aecf9:	3c 06                	cmp    al,0x6
  4aecfb:	75 45                	jne    0x4aed42
  4aecfd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aed04:	75 2f                	jne    0x4aed35
  4aed06:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aed0d:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x10
  4aed14:	10 00 00 00 
  4aed18:	e8 73 ff 02 00       	call   0x4dec90
  4aed1d:	68 30 ce bc 00       	push   0xbcce30
  4aed22:	e8 f3 35 3e 00       	call   0x89231a
  4aed27:	83 c4 04             	add    esp,0x4
  4aed2a:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aed31:	ff ff ff ff 
  4aed35:	66 8b 53 fc          	mov    dx,WORD PTR [ebx-0x4]
  4aed39:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4aed3e:	66 89 50 32          	mov    WORD PTR [eax+0x32],dx
  4aed42:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4aed46:	40                   	inc    eax
  4aed47:	83 c3 1a             	add    ebx,0x1a
  4aed4a:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  4aed4e:	3b 44 24 28          	cmp    eax,DWORD PTR [esp+0x28]
  4aed52:	0f 82 f8 f7 ff ff    	jb     0x4ae550
  4aed58:	b8 00 01 00 00       	mov    eax,0x100
  4aed5d:	8b 8c 24 48 01 00 00 	mov    ecx,DWORD PTR [esp+0x148]
  4aed64:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aed6b:	59                   	pop    ecx
  4aed6c:	5f                   	pop    edi
  4aed6d:	5e                   	pop    esi
  4aed6e:	5b                   	pop    ebx
  4aed6f:	8b 8c 24 30 01 00 00 	mov    ecx,DWORD PTR [esp+0x130]
  4aed76:	33 cc                	xor    ecx,esp
  4aed78:	e8 84 22 3e 00       	call   0x891001
  4aed7d:	8b e5                	mov    esp,ebp
  4aed7f:	5d                   	pop    ebp
  4aed80:	c2 0c 00             	ret    0xc
  4aed83:	68 c0 69 c0 00       	push   0xc069c0
  4aed88:	e8 e3 ee 23 00       	call   0x6edc70
  4aed8d:	8d 49 00             	lea    ecx,[ecx+0x0]
```

### 次級記錄handler完整code：`0x004AF530..0x004AF920`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004af530 <.text+0xae530>:
  4af530:	55                   	push   ebp
  4af531:	8b ec                	mov    ebp,esp
  4af533:	83 e4 f8             	and    esp,0xfffffff8
  4af536:	6a ff                	push   0xffffffff
  4af538:	68 4a 4e 94 00       	push   0x944e4a
  4af53d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4af543:	50                   	push   eax
  4af544:	83 ec 10             	sub    esp,0x10
  4af547:	53                   	push   ebx
  4af548:	56                   	push   esi
  4af549:	57                   	push   edi
  4af54a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4af54f:	33 c4                	xor    eax,esp
  4af551:	50                   	push   eax
  4af552:	8d 44 24 20          	lea    eax,[esp+0x20]
  4af556:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4af55c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4af55f:	33 f6                	xor    esi,esi
  4af561:	66 39 73 02          	cmp    WORD PTR [ebx+0x2],si
  4af565:	74 41                	je     0x4af5a8
  4af567:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af56e:	75 25                	jne    0x4af595
  4af570:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4af577:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4af57b:	e8 10 f7 02 00       	call   0x4dec90
  4af580:	68 30 ce bc 00       	push   0xbcce30
  4af585:	e8 90 2d 3e 00       	call   0x89231a
  4af58a:	83 c4 04             	add    esp,0x4
  4af58d:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af594:	ff 
  4af595:	68 48 b1 fa 00       	push   0xfab148
  4af59a:	89 35 28 b2 fa 00    	mov    DWORD PTR ds:0xfab228,esi
  4af5a0:	e8 cb 1a 03 00       	call   0x4e1070
  4af5a5:	83 c4 04             	add    esp,0x4
  4af5a8:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4af5ab:	83 f8 04             	cmp    eax,0x4
  4af5ae:	73 04                	jae    0x4af5b4
  4af5b0:	33 d2                	xor    edx,edx
  4af5b2:	eb 0d                	jmp    0x4af5c1
  4af5b4:	8d 48 fc             	lea    ecx,[eax-0x4]
  4af5b7:	b8 a3 8b 2e ba       	mov    eax,0xba2e8ba3
  4af5bc:	f7 e1                	mul    ecx
  4af5be:	c1 ea 04             	shr    edx,0x4
  4af5c1:	3b d6                	cmp    edx,esi
  4af5c3:	0f 86 39 03 00 00    	jbe    0x4af902
  4af5c9:	83 c3 0a             	add    ebx,0xa
  4af5cc:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  4af5d0:	eb 02                	jmp    0x4af5d4
  4af5d2:	33 f6                	xor    esi,esi
  4af5d4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af5db:	75 29                	jne    0x4af606
  4af5dd:	b8 01 00 00 00       	mov    eax,0x1
  4af5e2:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4af5e8:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  4af5ec:	e8 9f f6 02 00       	call   0x4dec90
  4af5f1:	68 30 ce bc 00       	push   0xbcce30
  4af5f6:	e8 1f 2d 3e 00       	call   0x89231a
  4af5fb:	83 c4 04             	add    esp,0x4
  4af5fe:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af605:	ff 
  4af606:	8b 53 fa             	mov    edx,DWORD PTR [ebx-0x6]
  4af609:	8d 44 24 14          	lea    eax,[esp+0x14]
  4af60d:	50                   	push   eax
  4af60e:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4af612:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4af617:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4af61b:	e8 a0 42 39 00       	call   0x8438c0
  4af620:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4af624:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4af62a:	74 0b                	je     0x4af637
  4af62c:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  4af62f:	3b fe                	cmp    edi,esi
  4af631:	0f 85 ba 00 00 00    	jne    0x4af6f1
  4af637:	6a 2c                	push   0x2c
  4af639:	e8 2a 1c 3e 00       	call   0x891268
  4af63e:	83 c4 04             	add    esp,0x4
  4af641:	3b c6                	cmp    eax,esi
  4af643:	74 25                	je     0x4af66a
  4af645:	33 c9                	xor    ecx,ecx
  4af647:	89 30                	mov    DWORD PTR [eax],esi
  4af649:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4af64c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  4af64f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  4af652:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  4af655:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  4af658:	89 70 1c             	mov    DWORD PTR [eax+0x1c],esi
  4af65b:	c7 40 24 ff ff ff ff 	mov    DWORD PTR [eax+0x24],0xffffffff
  4af662:	66 89 48 28          	mov    WORD PTR [eax+0x28],cx
  4af666:	8b f8                	mov    edi,eax
  4af668:	eb 02                	jmp    0x4af66c
  4af66a:	33 ff                	xor    edi,edi
  4af66c:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4af673:	8b 43 fa             	mov    eax,DWORD PTR [ebx-0x6]
  4af676:	89 07                	mov    DWORD PTR [edi],eax
  4af678:	75 29                	jne    0x4af6a3
  4af67a:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4af681:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  4af688:	00 
  4af689:	e8 02 1f 03 00       	call   0x4e1590
  4af68e:	68 80 cc bc 00       	push   0xbccc80
  4af693:	e8 82 2c 3e 00       	call   0x89231a
  4af698:	83 c4 04             	add    esp,0x4
  4af69b:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af6a2:	ff 
  4af6a3:	8b 15 30 39 f9 00    	mov    edx,DWORD PTR ds:0xf93930
  4af6a9:	33 c9                	xor    ecx,ecx
  4af6ab:	3b 17                	cmp    edx,DWORD PTR [edi]
  4af6ad:	0f 94 c1             	sete   cl
  4af6b0:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af6b7:	89 4f 1c             	mov    DWORD PTR [edi+0x1c],ecx
  4af6ba:	75 29                	jne    0x4af6e5
  4af6bc:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4af6c3:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  4af6ca:	00 
  4af6cb:	e8 c0 f5 02 00       	call   0x4dec90
  4af6d0:	68 30 ce bc 00       	push   0xbcce30
  4af6d5:	e8 40 2c 3e 00       	call   0x89231a
  4af6da:	83 c4 04             	add    esp,0x4
  4af6dd:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af6e4:	ff 
  4af6e5:	68 30 b1 fa 00       	push   0xfab130
  4af6ea:	8b cf                	mov    ecx,edi
  4af6ec:	e8 bf 08 03 00       	call   0x4dffb0
  4af6f1:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4af6f8:	8b 43 fa             	mov    eax,DWORD PTR [ebx-0x6]
  4af6fb:	89 07                	mov    DWORD PTR [edi],eax
  4af6fd:	75 29                	jne    0x4af728
  4af6ff:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4af706:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  4af70d:	00 
  4af70e:	e8 7d 1e 03 00       	call   0x4e1590
  4af713:	68 80 cc bc 00       	push   0xbccc80
  4af718:	e8 fd 2b 3e 00       	call   0x89231a
  4af71d:	83 c4 04             	add    esp,0x4
  4af720:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af727:	ff 
  4af728:	8b 37                	mov    esi,DWORD PTR [edi]
  4af72a:	33 c9                	xor    ecx,ecx
  4af72c:	39 35 30 39 f9 00    	cmp    DWORD PTR ds:0xf93930,esi
  4af732:	0f 94 c1             	sete   cl
  4af735:	89 4f 1c             	mov    DWORD PTR [edi+0x1c],ecx
  4af738:	8a 43 fe             	mov    al,BYTE PTR [ebx-0x2]
  4af73b:	88 47 20             	mov    BYTE PTR [edi+0x20],al
  4af73e:	8b 03                	mov    eax,DWORD PTR [ebx]
  4af740:	89 47 0c             	mov    DWORD PTR [edi+0xc],eax
  4af743:	0f b7 43 0a          	movzx  eax,WORD PTR [ebx+0xa]
  4af747:	66 89 47 16          	mov    WORD PTR [edi+0x16],ax
  4af74b:	0f b7 43 08          	movzx  eax,WORD PTR [ebx+0x8]
  4af74f:	66 89 47 14          	mov    WORD PTR [edi+0x14],ax
  4af753:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4af756:	89 47 10             	mov    DWORD PTR [edi+0x10],eax
  4af759:	0f b7 43 0c          	movzx  eax,WORD PTR [ebx+0xc]
  4af75d:	66 89 47 18          	mov    WORD PTR [edi+0x18],ax
  4af761:	8a 43 ff             	mov    al,BYTE PTR [ebx-0x1]
  4af764:	24 01                	and    al,0x1
  4af766:	88 47 28             	mov    BYTE PTR [edi+0x28],al
  4af769:	8a 43 ff             	mov    al,BYTE PTR [ebx-0x1]
  4af76c:	d0 e8                	shr    al,1
  4af76e:	24 01                	and    al,0x1
  4af770:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4af777:	88 47 29             	mov    BYTE PTR [edi+0x29],al
  4af77a:	0f b7 43 0e          	movzx  eax,WORD PTR [ebx+0xe]
  4af77e:	0f bf d0             	movsx  edx,ax
  4af781:	89 57 24             	mov    DWORD PTR [edi+0x24],edx
  4af784:	75 29                	jne    0x4af7af
  4af786:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4af78d:	c7 44 24 28 05 00 00 	mov    DWORD PTR [esp+0x28],0x5
  4af794:	00 
  4af795:	e8 f6 1d 03 00       	call   0x4e1590
  4af79a:	68 80 cc bc 00       	push   0xbccc80
  4af79f:	e8 76 2b 3e 00       	call   0x89231a
  4af7a4:	83 c4 04             	add    esp,0x4
  4af7a7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af7ae:	ff 
  4af7af:	3b 35 30 39 f9 00    	cmp    esi,DWORD PTR ds:0xf93930
  4af7b5:	0f 85 3a 01 00 00    	jne    0x4af8f5
  4af7bb:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af7c2:	0f b7 77 14          	movzx  esi,WORD PTR [edi+0x14]
  4af7c6:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  4af7ca:	75 29                	jne    0x4af7f5
  4af7cc:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4af7d3:	c7 44 24 28 06 00 00 	mov    DWORD PTR [esp+0x28],0x6
  4af7da:	00 
  4af7db:	e8 b0 f4 02 00       	call   0x4dec90
  4af7e0:	68 30 ce bc 00       	push   0xbcce30
  4af7e5:	e8 30 2b 3e 00       	call   0x89231a
  4af7ea:	83 c4 04             	add    esp,0x4
  4af7ed:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af7f4:	ff 
  4af7f5:	f6 05 78 13 fb 00 01 	test   BYTE PTR ds:0xfb1378,0x1
  4af7fc:	75 29                	jne    0x4af827
  4af7fe:	83 0d 78 13 fb 00 01 	or     DWORD PTR ds:0xfb1378,0x1
  4af805:	c7 44 24 28 07 00 00 	mov    DWORD PTR [esp+0x28],0x7
  4af80c:	00 
  4af80d:	e8 0e a4 08 00       	call   0x539c20
  4af812:	68 b0 cf bc 00       	push   0xbccfb0
  4af817:	e8 fe 2a 3e 00       	call   0x89231a
  4af81c:	83 c4 04             	add    esp,0x4
  4af81f:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af826:	ff 
  4af827:	56                   	push   esi
  4af828:	be 80 13 fb 00       	mov    esi,0xfb1380
  4af82d:	e8 9e b1 08 00       	call   0x53a9d0
  4af832:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4af839:	a3 58 72 fb 00       	mov    ds:0xfb7258,eax
  4af83e:	75 2a                	jne    0x4af86a
  4af840:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4af847:	c7 44 24 28 08 00 00 	mov    DWORD PTR [esp+0x28],0x8
  4af84e:	00 
  4af84f:	e8 2c 7c 0d 00       	call   0x587480
  4af854:	68 c0 cc bc 00       	push   0xbcccc0
  4af859:	e8 bc 2a 3e 00       	call   0x89231a
  4af85e:	83 c4 04             	add    esp,0x4
  4af861:	83 ce ff             	or     esi,0xffffffff
  4af864:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4af868:	eb 03                	jmp    0x4af86d
  4af86a:	83 ce ff             	or     esi,0xffffffff
  4af86d:	68 04 44 0f 00       	push   0xf4404
  4af872:	e8 59 b2 0d 00       	call   0x58aad0
  4af877:	66 8b 44 24 18       	mov    ax,WORD PTR [esp+0x18]
  4af87c:	83 c4 04             	add    esp,0x4
  4af87f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af886:	66 a3 20 b2 fa 00    	mov    ds:0xfab220,ax
  4af88c:	8b 7f 10             	mov    edi,DWORD PTR [edi+0x10]
  4af88f:	75 25                	jne    0x4af8b6
  4af891:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4af898:	c7 44 24 28 09 00 00 	mov    DWORD PTR [esp+0x28],0x9
  4af89f:	00 
  4af8a0:	e8 eb f3 02 00       	call   0x4dec90
  4af8a5:	68 30 ce bc 00       	push   0xbcce30
  4af8aa:	e8 6b 2a 3e 00       	call   0x89231a
  4af8af:	83 c4 04             	add    esp,0x4
  4af8b2:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4af8b6:	f6 05 1c 7f fc 00 01 	test   BYTE PTR ds:0xfc7f1c,0x1
  4af8bd:	75 25                	jne    0x4af8e4
  4af8bf:	83 0d 1c 7f fc 00 01 	or     DWORD PTR ds:0xfc7f1c,0x1
  4af8c6:	c7 44 24 28 0a 00 00 	mov    DWORD PTR [esp+0x28],0xa
  4af8cd:	00 
  4af8ce:	e8 2d ca 08 00       	call   0x53c300
  4af8d3:	68 d0 e1 bc 00       	push   0xbce1d0
  4af8d8:	e8 3d 2a 3e 00       	call   0x89231a
  4af8dd:	83 c4 04             	add    esp,0x4
  4af8e0:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4af8e4:	57                   	push   edi
  4af8e5:	b9 20 7f fc 00       	mov    ecx,0xfc7f20
  4af8ea:	e8 e1 d5 08 00       	call   0x53ced0
  4af8ef:	89 3d 24 b2 fa 00    	mov    DWORD PTR ds:0xfab224,edi
  4af8f5:	83 c3 16             	add    ebx,0x16
  4af8f8:	ff 4c 24 10          	dec    DWORD PTR [esp+0x10]
  4af8fc:	0f 85 d0 fc ff ff    	jne    0x4af5d2
  4af902:	b8 00 01 00 00       	mov    eax,0x100
  4af907:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4af90b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4af912:	59                   	pop    ecx
  4af913:	5f                   	pop    edi
  4af914:	5e                   	pop    esi
  4af915:	5b                   	pop    ebx
  4af916:	8b e5                	mov    esp,ebp
  4af918:	5d                   	pop    ebp
  4af919:	c2 0c 00             	ret    0xc
  4af91c:	cc                   	int3
  4af91d:	cc                   	int3
  4af91e:	cc                   	int3
  4af91f:	cc                   	int3
```

### 命令26完整code與正確缺失分支：`0x004B28D0..0x004B2AF0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b28d0 <.text+0xb18d0>:
  4b28d0:	55                   	push   ebp
  4b28d1:	8b ec                	mov    ebp,esp
  4b28d3:	83 e4 f8             	and    esp,0xfffffff8
  4b28d6:	6a ff                	push   0xffffffff
  4b28d8:	68 1c 6d 93 00       	push   0x936d1c
  4b28dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b28e3:	50                   	push   eax
  4b28e4:	83 ec 28             	sub    esp,0x28
  4b28e7:	53                   	push   ebx
  4b28e8:	56                   	push   esi
  4b28e9:	57                   	push   edi
  4b28ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b28ef:	33 c4                	xor    eax,esp
  4b28f1:	50                   	push   eax
  4b28f2:	8d 44 24 38          	lea    eax,[esp+0x38]
  4b28f6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b28fc:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b28ff:	83 f8 04             	cmp    eax,0x4
  4b2902:	73 04                	jae    0x4b2908
  4b2904:	33 c0                	xor    eax,eax
  4b2906:	eb 05                	jmp    0x4b290d
  4b2908:	83 c0 fc             	add    eax,0xfffffffc
  4b290b:	d1 e8                	shr    eax,1
  4b290d:	85 c0                	test   eax,eax
  4b290f:	0f 84 c1 01 00 00    	je     0x4b2ad6
  4b2915:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b2918:	83 c1 04             	add    ecx,0x4
  4b291b:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4b291f:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4b2923:	bb 01 00 00 00       	mov    ebx,0x1
  4b2928:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b292e:	75 28                	jne    0x4b2958
  4b2930:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b2936:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  4b293d:	00 
  4b293e:	e8 4d c3 02 00       	call   0x4dec90
  4b2943:	68 30 ce bc 00       	push   0xbcce30
  4b2948:	e8 cd f9 3d 00       	call   0x89231a
  4b294d:	83 c4 04             	add    esp,0x4
  4b2950:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  4b2957:	ff 
  4b2958:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4b295c:	0f b7 02             	movzx  eax,WORD PTR [edx]
  4b295f:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  4b2963:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4b2967:	51                   	push   ecx
  4b2968:	8d 44 24 24          	lea    eax,[esp+0x24]
  4b296c:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4b2971:	e8 8a c5 37 00       	call   0x82ef00
  4b2976:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b297a:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4b2980:	74 07                	je     0x4b2989
  4b2982:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  4b2985:	85 f6                	test   esi,esi
  4b2987:	75 12                	jne    0x4b299b
  4b2989:	68 e0 6c c0 00       	push   0xc06ce0
  4b298e:	e8 cd b1 23 00       	call   0x6edb60
  4b2993:	83 c4 04             	add    esp,0x4
  4b2996:	e9 2c 01 00 00       	jmp    0x4b2ac7
  4b299b:	0f b7 46 04          	movzx  eax,WORD PTR [esi+0x4]
  4b299f:	3a c3                	cmp    al,bl
  4b29a1:	74 0c                	je     0x4b29af
  4b29a3:	3c 06                	cmp    al,0x6
  4b29a5:	74 08                	je     0x4b29af
  4b29a7:	84 c0                	test   al,al
  4b29a9:	74 04                	je     0x4b29af
  4b29ab:	3c 07                	cmp    al,0x7
  4b29ad:	75 66                	jne    0x4b2a15
  4b29af:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4b29b6:	00 
  4b29b7:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4b29bd:	f3 0f 11 44 24 24    	movss  DWORD PTR [esp+0x24],xmm0
  4b29c3:	f3 0f 11 44 24 28    	movss  DWORD PTR [esp+0x28],xmm0
  4b29c9:	f3 0f 11 44 24 2c    	movss  DWORD PTR [esp+0x2c],xmm0
  4b29cf:	f3 0f 11 44 24 30    	movss  DWORD PTR [esp+0x30],xmm0
  4b29d5:	85 c0                	test   eax,eax
  4b29d7:	74 3c                	je     0x4b2a15
  4b29d9:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4b29e0:	74 33                	je     0x4b2a15
  4b29e2:	6a 00                	push   0x0
  4b29e4:	50                   	push   eax
  4b29e5:	e8 d6 52 2f 00       	call   0x7a7cc0
  4b29ea:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  4b29ee:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4b29f4:	83 ec 10             	sub    esp,0x10
  4b29f7:	8b cc                	mov    ecx,esp
  4b29f9:	89 11                	mov    DWORD PTR [ecx],edx
  4b29fb:	8b 54 24 38          	mov    edx,DWORD PTR [esp+0x38]
  4b29ff:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  4b2a02:	8b 54 24 3c          	mov    edx,DWORD PTR [esp+0x3c]
  4b2a06:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  4b2a09:	8b 54 24 40          	mov    edx,DWORD PTR [esp+0x40]
  4b2a0d:	89 51 0c             	mov    DWORD PTR [ecx+0xc],edx
  4b2a10:	e8 db 51 2f 00       	call   0x7a7bf0
  4b2a15:	0f b7 46 04          	movzx  eax,WORD PTR [esi+0x4]
  4b2a19:	3c 02                	cmp    al,0x2
  4b2a1b:	74 08                	je     0x4b2a25
  4b2a1d:	3c 08                	cmp    al,0x8
  4b2a1f:	74 04                	je     0x4b2a25
  4b2a21:	3c 09                	cmp    al,0x9
  4b2a23:	75 31                	jne    0x4b2a56
  4b2a25:	83 be f4 00 00 00 00 	cmp    DWORD PTR [esi+0xf4],0x0
  4b2a2c:	74 28                	je     0x4b2a56
  4b2a2e:	83 be 24 01 00 00 00 	cmp    DWORD PTR [esi+0x124],0x0
  4b2a35:	75 1f                	jne    0x4b2a56
  4b2a37:	d9 86 34 01 00 00    	fld    DWORD PTR [esi+0x134]
  4b2a3d:	d8 b6 30 01 00 00    	fdiv   DWORD PTR [esi+0x130]
  4b2a43:	dd 05 f0 57 c5 00    	fld    QWORD PTR ds:0xc557f0
  4b2a49:	d9 c9                	fxch   st(1)
  4b2a4b:	df f1                	fcomip st,st(1)
  4b2a4d:	dd d8                	fstp   st(0)
  4b2a4f:	76 05                	jbe    0x4b2a56
  4b2a51:	e8 5a 9e 01 00       	call   0x4cc8b0
  4b2a56:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4b2a5c:	66 8b 76 04          	mov    si,WORD PTR [esi+0x4]
  4b2a60:	33 c0                	xor    eax,eax
  4b2a62:	8d 51 0c             	lea    edx,[ecx+0xc]
  4b2a65:	8b 3a                	mov    edi,DWORD PTR [edx]
  4b2a67:	85 ff                	test   edi,edi
  4b2a69:	74 06                	je     0x4b2a71
  4b2a6b:	66 39 77 04          	cmp    WORD PTR [edi+0x4],si
  4b2a6f:	74 0c                	je     0x4b2a7d
  4b2a71:	03 c3                	add    eax,ebx
  4b2a73:	83 c2 0c             	add    edx,0xc
  4b2a76:	83 f8 03             	cmp    eax,0x3
  4b2a79:	7c ea                	jl     0x4b2a65
  4b2a7b:	eb 0c                	jmp    0x4b2a89
  4b2a7d:	83 f8 ff             	cmp    eax,0xffffffff
  4b2a80:	74 07                	je     0x4b2a89
  4b2a82:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b2a84:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b2a87:	ff d2                	call   edx
  4b2a89:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b2a8f:	75 24                	jne    0x4b2ab5
  4b2a91:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b2a97:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4b2a9b:	e8 f0 c1 02 00       	call   0x4dec90
  4b2aa0:	68 30 ce bc 00       	push   0xbcce30
  4b2aa5:	e8 70 f8 3d 00       	call   0x89231a
  4b2aaa:	83 c4 04             	add    esp,0x4
  4b2aad:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  4b2ab4:	ff 
  4b2ab5:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4b2ab9:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4b2abc:	51                   	push   ecx
  4b2abd:	b8 30 b1 fa 00       	mov    eax,0xfab130
  4b2ac2:	e8 f9 d0 02 00       	call   0x4dfbc0
  4b2ac7:	83 44 24 14 02       	add    DWORD PTR [esp+0x14],0x2
  4b2acc:	29 5c 24 18          	sub    DWORD PTR [esp+0x18],ebx
  4b2ad0:	0f 85 52 fe ff ff    	jne    0x4b2928
  4b2ad6:	33 c0                	xor    eax,eax
  4b2ad8:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  4b2adc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b2ae3:	59                   	pop    ecx
  4b2ae4:	5f                   	pop    edi
  4b2ae5:	5e                   	pop    esi
  4b2ae6:	5b                   	pop    ebx
  4b2ae7:	8b e5                	mov    esp,ebp
  4b2ae9:	5d                   	pop    ebp
  4b2aea:	c2 0c 00             	ret    0xc
  4b2aed:	cc                   	int3
  4b2aee:	cc                   	int3
  4b2aef:	cc                   	int3
```

### 命令81完整code：`0x004B3710..0x004B3751`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b3710 <.text+0xb2710>:
  4b3710:	55                   	push   ebp
  4b3711:	8b ec                	mov    ebp,esp
  4b3713:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b3716:	57                   	push   edi
  4b3717:	83 f8 02             	cmp    eax,0x2
  4b371a:	73 04                	jae    0x4b3720
  4b371c:	33 ff                	xor    edi,edi
  4b371e:	eb 05                	jmp    0x4b3725
  4b3720:	8d 78 fe             	lea    edi,[eax-0x2]
  4b3723:	d1 ef                	shr    edi,1
  4b3725:	85 ff                	test   edi,edi
  4b3727:	74 21                	je     0x4b374a
  4b3729:	56                   	push   esi
  4b372a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b372d:	83 c6 02             	add    esi,0x2
  4b3730:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4b3733:	0d 00 00 00 06       	or     eax,0x6000000
  4b3738:	50                   	push   eax
  4b3739:	e8 22 b9 f5 ff       	call   0x40f060
  4b373e:	e8 4d c5 02 00       	call   0x4dfc90
  4b3743:	83 c6 02             	add    esi,0x2
  4b3746:	4f                   	dec    edi
  4b3747:	75 e7                	jne    0x4b3730
  4b3749:	5e                   	pop    esi
  4b374a:	33 c0                	xor    eax,eax
  4b374c:	5f                   	pop    edi
  4b374d:	5d                   	pop    ebp
  4b374e:	c2 0c 00             	ret    0xc
```

### global owner取得者：`0x0040F060..0x0040F0C9`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0040f060 <.text+0xe060>:
  40f060:	55                   	push   ebp
  40f061:	8b ec                	mov    ebp,esp
  40f063:	83 e4 f8             	and    esp,0xfffffff8
  40f066:	6a ff                	push   0xffffffff
  40f068:	68 ee 61 94 00       	push   0x9461ee
  40f06d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  40f073:	50                   	push   eax
  40f074:	51                   	push   ecx
  40f075:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  40f07a:	33 c4                	xor    eax,esp
  40f07c:	50                   	push   eax
  40f07d:	8d 44 24 08          	lea    eax,[esp+0x8]
  40f081:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  40f087:	b8 01 00 00 00       	mov    eax,0x1
  40f08c:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  40f092:	75 20                	jne    0x40f0b4
  40f094:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  40f09a:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  40f0a1:	00 
  40f0a2:	e8 e9 fb 0c 00       	call   0x4dec90
  40f0a7:	68 30 ce bc 00       	push   0xbcce30
  40f0ac:	e8 69 32 48 00       	call   0x89231a
  40f0b1:	83 c4 04             	add    esp,0x4
  40f0b4:	b8 30 b1 fa 00       	mov    eax,0xfab130
  40f0b9:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  40f0bd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  40f0c4:	59                   	pop    ecx
  40f0c5:	8b e5                	mov    esp,ebp
  40f0c7:	5d                   	pop    ebp
  40f0c8:	c3                   	ret
```

### owner初始化有界窗口；兩sentinel與count：`0x004DEC90..0x004DEDAD`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dec90 <.text+0xddc90>:
  4dec90:	55                   	push   ebp
  4dec91:	8b ec                	mov    ebp,esp
  4dec93:	6a ff                	push   0xffffffff
  4dec95:	68 db 3d 93 00       	push   0x933ddb
  4dec9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4deca0:	50                   	push   eax
  4deca1:	83 ec 24             	sub    esp,0x24
  4deca4:	53                   	push   ebx
  4deca5:	56                   	push   esi
  4deca6:	57                   	push   edi
  4deca7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4decac:	33 c5                	xor    eax,ebp
  4decae:	50                   	push   eax
  4decaf:	8d 45 f4             	lea    eax,[ebp-0xc]
  4decb2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4decb8:	68 24 5f 00 00       	push   0x5f24
  4decbd:	c7 45 e8 30 b1 fa 00 	mov    DWORD PTR [ebp-0x18],0xfab130
  4decc4:	e8 9f 25 3b 00       	call   0x891268
  4decc9:	33 f6                	xor    esi,esi
  4deccb:	83 c4 04             	add    esp,0x4
  4decce:	3b c6                	cmp    eax,esi
  4decd0:	74 09                	je     0x4decdb
  4decd2:	8b c8                	mov    ecx,eax
  4decd4:	e8 27 ea ff ff       	call   0x4dd700
  4decd9:	eb 02                	jmp    0x4decdd
  4decdb:	33 c0                	xor    eax,eax
  4decdd:	6a 40                	push   0x40
  4decdf:	a3 30 b1 fa 00       	mov    ds:0xfab130,eax
  4dece4:	e8 7f 25 3b 00       	call   0x891268
  4dece9:	83 c4 04             	add    esp,0x4
  4decec:	3b c6                	cmp    eax,esi
  4decee:	74 2a                	je     0x4ded1a
  4decf0:	89 30                	mov    DWORD PTR [eax],esi
  4decf2:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4decf5:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  4decf8:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  4decfb:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  4decfe:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  4ded01:	33 c9                	xor    ecx,ecx
  4ded03:	89 70 20             	mov    DWORD PTR [eax+0x20],esi
  4ded06:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  4ded09:	89 70 28             	mov    DWORD PTR [eax+0x28],esi
  4ded0c:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  4ded0f:	b9 38 00 00 00       	mov    ecx,0x38
  4ded14:	66 89 48 34          	mov    WORD PTR [eax+0x34],cx
  4ded18:	eb 02                	jmp    0x4ded1c
  4ded1a:	33 c0                	xor    eax,eax
  4ded1c:	6a 18                	push   0x18
  4ded1e:	a3 34 b1 fa 00       	mov    ds:0xfab134,eax
  4ded23:	89 35 40 b1 fa 00    	mov    DWORD PTR ds:0xfab140,esi
  4ded29:	e8 3a 25 3b 00       	call   0x891268
  4ded2e:	83 c4 04             	add    esp,0x4
  4ded31:	3b c6                	cmp    eax,esi
  4ded33:	0f 84 65 02 00 00    	je     0x4def9e
  4ded39:	a3 3c b1 fa 00       	mov    ds:0xfab13c,eax
  4ded3e:	89 00                	mov    DWORD PTR [eax],eax
  4ded40:	a1 3c b1 fa 00       	mov    eax,ds:0xfab13c
  4ded45:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4ded48:	a1 3c b1 fa 00       	mov    eax,ds:0xfab13c
  4ded4d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4ded50:	8b 15 3c b1 fa 00    	mov    edx,DWORD PTR ds:0xfab13c
  4ded56:	bb 01 00 00 00       	mov    ebx,0x1
  4ded5b:	88 5a 14             	mov    BYTE PTR [edx+0x14],bl
  4ded5e:	a1 3c b1 fa 00       	mov    eax,ds:0xfab13c
  4ded63:	88 58 15             	mov    BYTE PTR [eax+0x15],bl
  4ded66:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4ded69:	6a 18                	push   0x18
  4ded6b:	89 35 50 b1 fa 00    	mov    DWORD PTR ds:0xfab150,esi
  4ded71:	e8 f2 24 3b 00       	call   0x891268
  4ded76:	83 c4 04             	add    esp,0x4
  4ded79:	3b c6                	cmp    eax,esi
  4ded7b:	0f 84 f9 01 00 00    	je     0x4def7a
  4ded81:	a3 4c b1 fa 00       	mov    ds:0xfab14c,eax
  4ded86:	89 00                	mov    DWORD PTR [eax],eax
  4ded88:	a1 4c b1 fa 00       	mov    eax,ds:0xfab14c
  4ded8d:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4ded90:	a1 4c b1 fa 00       	mov    eax,ds:0xfab14c
  4ded95:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4ded98:	8b 0d 4c b1 fa 00    	mov    ecx,DWORD PTR ds:0xfab14c
  4ded9e:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  4deda1:	8b 15 4c b1 fa 00    	mov    edx,DWORD PTR ds:0xfab14c
  4deda7:	88 5a 15             	mov    BYTE PTR [edx+0x15],bl
  4dedaa:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
```

### 兩樹getter：`0x004DFAA0..0x004DFB00`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfaa0 <.text+0xdeaa0>:
  4dfaa0:	55                   	push   ebp
  4dfaa1:	8b ec                	mov    ebp,esp
  4dfaa3:	51                   	push   ecx
  4dfaa4:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfaa7:	50                   	push   eax
  4dfaa8:	8d 4e 08             	lea    ecx,[esi+0x8]
  4dfaab:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfaae:	e8 4d f4 34 00       	call   0x82ef00
  4dfab3:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4dfab6:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  4dfab9:	75 08                	jne    0x4dfac3
  4dfabb:	33 c0                	xor    eax,eax
  4dfabd:	8b e5                	mov    esp,ebp
  4dfabf:	5d                   	pop    ebp
  4dfac0:	c2 04 00             	ret    0x4
  4dfac3:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4dfac6:	8b e5                	mov    esp,ebp
  4dfac8:	5d                   	pop    ebp
  4dfac9:	c2 04 00             	ret    0x4
  4dfacc:	cc                   	int3
  4dfacd:	cc                   	int3
  4dface:	cc                   	int3
  4dfacf:	cc                   	int3
  4dfad0:	55                   	push   ebp
  4dfad1:	8b ec                	mov    ebp,esp
  4dfad3:	83 ec 08             	sub    esp,0x8
  4dfad6:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfad9:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4dfadc:	51                   	push   ecx
  4dfadd:	8d 4e 18             	lea    ecx,[esi+0x18]
  4dfae0:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dfae3:	e8 d8 3d 36 00       	call   0x8438c0
  4dfae8:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4dfaeb:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  4dfaee:	75 06                	jne    0x4dfaf6
  4dfaf0:	33 c0                	xor    eax,eax
  4dfaf2:	8b e5                	mov    esp,ebp
  4dfaf4:	5d                   	pop    ebp
  4dfaf5:	c3                   	ret
  4dfaf6:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4dfaf9:	8b e5                	mov    esp,ebp
  4dfafb:	5d                   	pop    ebp
  4dfafc:	c3                   	ret
  4dfafd:	cc                   	int3
  4dfafe:	cc                   	int3
  4dfaff:	cc                   	int3
```

### 主樹單key／次級record erase／主樹composite erase：`0x004DFBC0..0x004DFD40`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    eax,DWORD PTR [esi+0xf8]
  4dfc55:	85 c0                	test   eax,eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    ecx,DWORD PTR [eax]
  4dfc5b:	3b 4d 08             	cmp    ecx,DWORD PTR [ebp+0x8]
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	mov    DWORD PTR [esi+0xf8],0x0
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4dfc6d:	85 c0                	test   eax,eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    esp,0x4
  4dfc7a:	57                   	push   edi
  4dfc7b:	8d 55 08             	lea    edx,[ebp+0x8]
  4dfc7e:	52                   	push   edx
  4dfc7f:	53                   	push   ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    edi
  4dfc86:	5b                   	pop    ebx
  4dfc87:	8b e5                	mov    esp,ebp
  4dfc89:	5d                   	pop    ebp
  4dfc8a:	c2 04 00             	ret    0x4
  4dfc8d:	cc                   	int3
  4dfc8e:	cc                   	int3
  4dfc8f:	cc                   	int3
  4dfc90:	55                   	push   ebp
  4dfc91:	8b ec                	mov    ebp,esp
  4dfc93:	51                   	push   ecx
  4dfc94:	56                   	push   esi
  4dfc95:	57                   	push   edi
  4dfc96:	8d 78 08             	lea    edi,[eax+0x8]
  4dfc99:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4dfc9c:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfc9e:	3b f0                	cmp    esi,eax
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfcaf:	90                   	nop
  4dfcb0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dfcb6:	39 81 88 00 00 00    	cmp    DWORD PTR [ecx+0x88],eax
  4dfcbc:	75 2c                	jne    0x4dfcea
  4dfcbe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcc0:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfcc3:	ff d0                	call   eax
  4dfcc5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcc8:	85 c9                	test   ecx,ecx
  4dfcca:	74 0f                	je     0x4dfcdb
  4dfccc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcce:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfcd0:	6a 01                	push   0x1
  4dfcd2:	ff d0                	call   eax
  4dfcd4:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfcdb:	56                   	push   esi
  4dfcdc:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfcdf:	51                   	push   ecx
  4dfce0:	57                   	push   edi
  4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
  4dfce6:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfce8:	eb 40                	jmp    0x4dfd2a
  4dfcea:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfcee:	75 3a                	jne    0x4dfd2a
  4dfcf0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfcf3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfcf7:	75 16                	jne    0x4dfd0f
  4dfcf9:	8b f0                	mov    esi,eax
  4dfcfb:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfcfd:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd01:	75 27                	jne    0x4dfd2a
  4dfd03:	8b f0                	mov    esi,eax
  4dfd05:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfd07:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd0b:	74 f6                	je     0x4dfd03
  4dfd0d:	eb 1b                	jmp    0x4dfd2a
  4dfd0f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfd12:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd16:	75 10                	jne    0x4dfd28
  4dfd18:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfd1b:	75 0b                	jne    0x4dfd28
  4dfd1d:	8b f0                	mov    esi,eax
  4dfd1f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfd22:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd26:	74 f0                	je     0x4dfd18
  4dfd28:	8b f0                	mov    esi,eax
  4dfd2a:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  4dfd2d:	75 81                	jne    0x4dfcb0
  4dfd2f:	5f                   	pop    edi
  4dfd30:	5e                   	pop    esi
  4dfd31:	8b e5                	mov    esp,ebp
  4dfd33:	5d                   	pop    ebp
  4dfd34:	c2 04 00             	ret    0x4
  4dfd37:	cc                   	int3
  4dfd38:	cc                   	int3
  4dfd39:	cc                   	int3
  4dfd3a:	cc                   	int3
  4dfd3b:	cc                   	int3
  4dfd3c:	cc                   	int3
  4dfd3d:	cc                   	int3
  4dfd3e:	cc                   	int3
  4dfd3f:	cc                   	int3
```

### 主樹type filter與全部清理：`0x004DFD40..0x004DFF30`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfd40 <.text+0xded40>:
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfe01:	ff d2                	call   edx
  4dfe03:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfe06:	85 c9                	test   ecx,ecx
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
  4dfe8a:	cc                   	int3
  4dfe8b:	cc                   	int3
  4dfe8c:	cc                   	int3
  4dfe8d:	cc                   	int3
  4dfe8e:	cc                   	int3
  4dfe8f:	cc                   	int3
  4dfe90:	55                   	push   ebp
  4dfe91:	8b ec                	mov    ebp,esp
  4dfe93:	53                   	push   ebx
  4dfe94:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dfe97:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  4dfe9a:	56                   	push   esi
  4dfe9b:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe9d:	57                   	push   edi
  4dfe9e:	3b f0                	cmp    esi,eax
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  4dfea5:	85 ff                	test   edi,edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeab:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfeae:	8b cf                	mov    ecx,edi
  4dfeb0:	ff d2                	call   edx
  4dfeb2:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeb4:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfeb6:	6a 01                	push   0x1
  4dfeb8:	8b cf                	mov    ecx,edi
  4dfeba:	ff d2                	call   edx
  4dfebc:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfec5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    esi,eax
  4dfecd:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfecf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    esi,eax
  4dfed7:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfed9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfee4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4dfef0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    esi,eax
  4dfef7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfefa:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    esi,eax
  4dff02:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    edi,[ebx+0x8]
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dff15:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dff17:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dff1a:	ff d2                	call   edx
  4dff1c:	5f                   	pop    edi
  4dff1d:	5e                   	pop    esi
  4dff1e:	5b                   	pop    ebx
  4dff1f:	5d                   	pop    ebp
  4dff20:	c2 04 00             	ret    0x4
  4dff23:	cc                   	int3
  4dff24:	cc                   	int3
  4dff25:	cc                   	int3
  4dff26:	cc                   	int3
  4dff27:	cc                   	int3
  4dff28:	cc                   	int3
  4dff29:	cc                   	int3
  4dff2a:	cc                   	int3
  4dff2b:	cc                   	int3
  4dff2c:	cc                   	int3
  4dff2d:	cc                   	int3
  4dff2e:	cc                   	int3
  4dff2f:	cc                   	int3
```

### 主樹與次級記錄登記完整code：`0x004DFF30..0x004E0060`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dff30 <.text+0xdef30>:
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2 04 00             	ret    0x4
  4dffaa:	cc                   	int3
  4dffab:	cc                   	int3
  4dffac:	cc                   	int3
  4dffad:	cc                   	int3
  4dffae:	cc                   	int3
  4dffaf:	cc                   	int3
  4dffb0:	55                   	push   ebp
  4dffb1:	8b ec                	mov    ebp,esp
  4dffb3:	83 e4 f8             	and    esp,0xfffffff8
  4dffb6:	6a ff                	push   0xffffffff
  4dffb8:	68 de ed 93 00       	push   0x93edde
  4dffbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4dffc3:	50                   	push   eax
  4dffc4:	83 ec 10             	sub    esp,0x10
  4dffc7:	53                   	push   ebx
  4dffc8:	56                   	push   esi
  4dffc9:	57                   	push   edi
  4dffca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4dffcf:	33 c4                	xor    eax,esp
  4dffd1:	50                   	push   eax
  4dffd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  4dffd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4dffdc:	8b f1                	mov    esi,ecx
  4dffde:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dffe1:	8b 3e                	mov    edi,DWORD PTR [esi]
  4dffe3:	b8 01 00 00 00       	mov    eax,0x1
  4dffe8:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4dffee:	75 28                	jne    0x4e0018
  4dfff0:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4dfff6:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  4dfffd:	00 
  4dfffe:	e8 8d 15 00 00       	call   0x4e1590
  4e0003:	68 80 cc bc 00       	push   0xbccc80
  4e0008:	e8 0d 23 3b 00       	call   0x89231a
  4e000d:	83 c4 04             	add    esp,0x4
  4e0010:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4e0017:	ff 
  4e0018:	3b 3d 30 39 f9 00    	cmp    edi,DWORD PTR ds:0xf93930
  4e001e:	75 06                	jne    0x4e0026
  4e0020:	89 b3 f8 00 00 00    	mov    DWORD PTR [ebx+0xf8],esi
  4e0026:	8b 06                	mov    eax,DWORD PTR [esi]
  4e0028:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4e002c:	8d 73 18             	lea    esi,[ebx+0x18]
  4e002f:	8d 7c 24 14          	lea    edi,[esp+0x14]
  4e0033:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4e0037:	e8 e4 ee 09 00       	call   0x57ef20
  4e003c:	50                   	push   eax
  4e003d:	56                   	push   esi
  4e003e:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  4e0042:	e8 09 e8 09 00       	call   0x57e850
  4e0047:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4e004b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4e0052:	59                   	pop    ecx
  4e0053:	5f                   	pop    edi
  4e0054:	5e                   	pop    esi
  4e0055:	5b                   	pop    ebx
  4e0056:	8b e5                	mov    esp,ebp
  4e0058:	5d                   	pop    ebp
  4e0059:	c2 04 00             	ret    0x4
  4e005c:	cc                   	int3
  4e005d:	cc                   	int3
  4e005e:	cc                   	int3
  4e005f:	cc                   	int3
```

### 次級樹全清完整code：`0x004E1070..0x004E1130`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e1070 <.text+0xe0070>:
  4e1070:	55                   	push   ebp
  4e1071:	8b ec                	mov    ebp,esp
  4e1073:	53                   	push   ebx
  4e1074:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4e1077:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4e107a:	56                   	push   esi
  4e107b:	8b 30                	mov    esi,DWORD PTR [eax]
  4e107d:	57                   	push   edi
  4e107e:	3b f0                	cmp    esi,eax
  4e1080:	74 5a                	je     0x4e10dc
  4e1082:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4e1085:	85 c0                	test   eax,eax
  4e1087:	74 09                	je     0x4e1092
  4e1089:	50                   	push   eax
  4e108a:	e8 7d 01 3b 00       	call   0x89120c
  4e108f:	83 c4 04             	add    esp,0x4
  4e1092:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4e1096:	75 3f                	jne    0x4e10d7
  4e1098:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4e109b:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4e109f:	75 1b                	jne    0x4e10bc
  4e10a1:	8b f0                	mov    esi,eax
  4e10a3:	8b 06                	mov    eax,DWORD PTR [esi]
  4e10a5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4e10a9:	75 2c                	jne    0x4e10d7
  4e10ab:	eb 03                	jmp    0x4e10b0
  4e10ad:	8d 49 00             	lea    ecx,[ecx+0x0]
  4e10b0:	8b f0                	mov    esi,eax
  4e10b2:	8b 06                	mov    eax,DWORD PTR [esi]
  4e10b4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4e10b8:	74 f6                	je     0x4e10b0
  4e10ba:	eb 1b                	jmp    0x4e10d7
  4e10bc:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4e10bf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4e10c3:	75 10                	jne    0x4e10d5
  4e10c5:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4e10c8:	75 0b                	jne    0x4e10d5
  4e10ca:	8b f0                	mov    esi,eax
  4e10cc:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4e10cf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4e10d3:	74 f0                	je     0x4e10c5
  4e10d5:	8b f0                	mov    esi,eax
  4e10d7:	3b 73 04             	cmp    esi,DWORD PTR [ebx+0x4]
  4e10da:	75 a6                	jne    0x4e1082
  4e10dc:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4e10df:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  4e10e2:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  4e10e6:	8b f7                	mov    esi,edi
  4e10e8:	75 24                	jne    0x4e110e
  4e10ea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4e10f0:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4e10f3:	51                   	push   ecx
  4e10f4:	8b cb                	mov    ecx,ebx
  4e10f6:	e8 a5 da 25 00       	call   0x73eba0
  4e10fb:	8b 36                	mov    esi,DWORD PTR [esi]
  4e10fd:	57                   	push   edi
  4e10fe:	e8 09 01 3b 00       	call   0x89120c
  4e1103:	83 c4 04             	add    esp,0x4
  4e1106:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4e110a:	8b fe                	mov    edi,esi
  4e110c:	74 e2                	je     0x4e10f0
  4e110e:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4e1111:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4e1114:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4e1117:	89 00                	mov    DWORD PTR [eax],eax
  4e1119:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4e111c:	5f                   	pop    edi
  4e111d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4e1120:	5e                   	pop    esi
  4e1121:	c7 43 08 00 00 00 00 	mov    DWORD PTR [ebx+0x8],0x0
  4e1128:	5b                   	pop    ebx
  4e1129:	5d                   	pop    ebp
  4e112a:	c3                   	ret
  4e112b:	cc                   	int3
  4e112c:	cc                   	int3
  4e112d:	cc                   	int3
  4e112e:	cc                   	int3
  4e112f:	cc                   	int3
```

### 共用node配置及pair複製：`0x0057EF20..0x0057EF90`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0057ef20 <.text+0x17df20>:
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
  57ef60:	8d 45 fc             	lea    eax,[ebp-0x4]
  57ef63:	50                   	push   eax
  57ef64:	8d 4d f0             	lea    ecx,[ebp-0x10]
  57ef67:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  57ef6a:	e8 3a 21 31 00       	call   0x8910a9
  57ef6f:	68 a8 57 c8 00       	push   0xc857a8
  57ef74:	8d 4d f0             	lea    ecx,[ebp-0x10]
  57ef77:	51                   	push   ecx
  57ef78:	c7 45 f0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x10],0xbd2ca4
  57ef7f:	e8 6c da 31 00       	call   0x89c9f0
  57ef84:	cc                   	int3
  57ef85:	cc                   	int3
  57ef86:	cc                   	int3
  57ef87:	cc                   	int3
  57ef88:	cc                   	int3
  57ef89:	cc                   	int3
  57ef8a:	cc                   	int3
  57ef8b:	cc                   	int3
  57ef8c:	cc                   	int3
  57ef8d:	cc                   	int3
  57ef8e:	cc                   	int3
  57ef8f:	cc                   	int3
```

### 次級unique insert完整code：`0x0057E850..0x0057E920`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0057e850 <.text+0x17d850>:
  57e850:	55                   	push   ebp
  57e851:	8b ec                	mov    ebp,esp
  57e853:	83 ec 08             	sub    esp,0x8
  57e856:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  57e859:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e85c:	53                   	push   ebx
  57e85d:	57                   	push   edi
  57e85e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  57e861:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  57e864:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e868:	b1 01                	mov    cl,0x1
  57e86a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e86d:	75 1f                	jne    0x57e88e
  57e86f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  57e872:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  57e875:	8b f8                	mov    edi,eax
  57e877:	0f 9c c1             	setl   cl
  57e87a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e87d:	84 c9                	test   cl,cl
  57e87f:	74 04                	je     0x57e885
  57e881:	8b 00                	mov    eax,DWORD PTR [eax]
  57e883:	eb 03                	jmp    0x57e888
  57e885:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  57e888:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e88c:	74 e4                	je     0x57e872
  57e88e:	8b df                	mov    ebx,edi
  57e890:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  57e893:	84 c9                	test   cl,cl
  57e895:	74 3a                	je     0x57e8d1
  57e897:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  57e89a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  57e89d:	3b 38                	cmp    edi,DWORD PTR [eax]
  57e89f:	75 22                	jne    0x57e8c3
  57e8a1:	52                   	push   edx
  57e8a2:	6a 01                	push   0x1
  57e8a4:	8d 55 0c             	lea    edx,[ebp+0xc]
  57e8a7:	8b c7                	mov    eax,edi
  57e8a9:	52                   	push   edx
  57e8aa:	8b f9                	mov    edi,ecx
  57e8ac:	e8 4f d4 ec ff       	call   0x44bd00
  57e8b1:	8b 00                	mov    eax,DWORD PTR [eax]
  57e8b3:	5f                   	pop    edi
  57e8b4:	89 06                	mov    DWORD PTR [esi],eax
  57e8b6:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8ba:	8b c6                	mov    eax,esi
  57e8bc:	5b                   	pop    ebx
  57e8bd:	8b e5                	mov    esp,ebp
  57e8bf:	5d                   	pop    ebp
  57e8c0:	c2 08 00             	ret    0x8
  57e8c3:	8d 45 fc             	lea    eax,[ebp-0x4]
  57e8c6:	e8 d5 0f fc ff       	call   0x53f8a0
  57e8cb:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  57e8ce:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e8d1:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  57e8d4:	52                   	push   edx
  57e8d5:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  57e8d8:	7d 24                	jge    0x57e8fe
  57e8da:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  57e8dd:	52                   	push   edx
  57e8de:	8d 45 0c             	lea    eax,[ebp+0xc]
  57e8e1:	50                   	push   eax
  57e8e2:	8b c7                	mov    eax,edi
  57e8e4:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  57e8e7:	e8 14 d4 ec ff       	call   0x44bd00
  57e8ec:	8b 08                	mov    ecx,DWORD PTR [eax]
  57e8ee:	5f                   	pop    edi
  57e8ef:	89 0e                	mov    DWORD PTR [esi],ecx
  57e8f1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8f5:	8b c6                	mov    eax,esi
  57e8f7:	5b                   	pop    ebx
  57e8f8:	8b e5                	mov    esp,ebp
  57e8fa:	5d                   	pop    ebp
  57e8fb:	c2 08 00             	ret    0x8
  57e8fe:	e8 09 29 31 00       	call   0x89120c
  57e903:	83 c4 04             	add    esp,0x4
  57e906:	5f                   	pop    edi
  57e907:	89 1e                	mov    DWORD PTR [esi],ebx
  57e909:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  57e90d:	8b c6                	mov    eax,esi
  57e90f:	5b                   	pop    ebx
  57e910:	8b e5                	mov    esp,ebp
  57e912:	5d                   	pop    ebp
  57e913:	c2 08 00             	ret    0x8
  57e916:	cc                   	int3
  57e917:	cc                   	int3
  57e918:	cc                   	int3
  57e919:	cc                   	int3
  57e91a:	cc                   	int3
  57e91b:	cc                   	int3
  57e91c:	cc                   	int3
  57e91d:	cc                   	int3
  57e91e:	cc                   	int3
  57e91f:	cc                   	int3
```

### record連結及composite setters：`0x004C6E50..0x004C6EA0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c6e50 <.text+0xc5e50>:
  4c6e50:	55                   	push   ebp
  4c6e51:	8b ec                	mov    ebp,esp
  4c6e53:	83 ec 08             	sub    esp,0x8
  4c6e56:	56                   	push   esi
  4c6e57:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4c6e5a:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c6e5d:	e8 fe 81 f4 ff       	call   0x40f060
  4c6e62:	8b f0                	mov    esi,eax
  4c6e64:	8d 45 fc             	lea    eax,[ebp-0x4]
  4c6e67:	50                   	push   eax
  4c6e68:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c6e6b:	8d 45 f8             	lea    eax,[ebp-0x8]
  4c6e6e:	e8 8d 80 36 00       	call   0x82ef00
  4c6e73:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4c6e76:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  4c6e79:	74 16                	je     0x4c6e91
  4c6e7b:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4c6e7e:	85 c0                	test   eax,eax
  4c6e80:	74 0f                	je     0x4c6e91
  4c6e82:	0f b7 88 88 00 00 00 	movzx  ecx,WORD PTR [eax+0x88]
  4c6e89:	89 4f 08             	mov    DWORD PTR [edi+0x8],ecx
  4c6e8c:	5e                   	pop    esi
  4c6e8d:	8b e5                	mov    esp,ebp
  4c6e8f:	5d                   	pop    ebp
  4c6e90:	c3                   	ret
  4c6e91:	c7 47 08 00 00 00 00 	mov    DWORD PTR [edi+0x8],0x0
  4c6e98:	5e                   	pop    esi
  4c6e99:	8b e5                	mov    esp,ebp
  4c6e9b:	5d                   	pop    ebp
  4c6e9c:	c3                   	ret
  4c6e9d:	cc                   	int3
  4c6e9e:	cc                   	int3
  4c6e9f:	cc                   	int3
```

### composite雙欄／單欄setter：`0x004C6FB0..0x004C6FE0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c6fb0 <.text+0xc5fb0>:
  4c6fb0:	55                   	push   ebp
  4c6fb1:	8b ec                	mov    ebp,esp
  4c6fb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c6fb6:	89 81 88 00 00 00    	mov    DWORD PTR [ecx+0x88],eax
  4c6fbc:	89 81 8c 00 00 00    	mov    DWORD PTR [ecx+0x8c],eax
  4c6fc2:	5d                   	pop    ebp
  4c6fc3:	c2 04 00             	ret    0x4
  4c6fc6:	cc                   	int3
  4c6fc7:	cc                   	int3
  4c6fc8:	cc                   	int3
  4c6fc9:	cc                   	int3
  4c6fca:	cc                   	int3
  4c6fcb:	cc                   	int3
  4c6fcc:	cc                   	int3
  4c6fcd:	cc                   	int3
  4c6fce:	cc                   	int3
  4c6fcf:	cc                   	int3
  4c6fd0:	55                   	push   ebp
  4c6fd1:	8b ec                	mov    ebp,esp
  4c6fd3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c6fd6:	89 81 8c 00 00 00    	mov    DWORD PTR [ecx+0x8c],eax
  4c6fdc:	5d                   	pop    ebp
  4c6fdd:	c2 04 00             	ret    0x4
```

### 二維setter與child+4介面傳遞：`0x004C8B90..0x004C8BE0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8b90 <.text+0xc7b90>:
  4c8b90:	55                   	push   ebp
  4c8b91:	8b ec                	mov    ebp,esp
  4c8b93:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c8b96:	56                   	push   esi
  4c8b97:	8b f1                	mov    esi,ecx
  4c8b99:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c8b9c:	50                   	push   eax
  4c8b9d:	51                   	push   ecx
  4c8b9e:	8b ce                	mov    ecx,esi
  4c8ba0:	e8 db 1f 00 00       	call   0x4cab80
  4c8ba5:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c8bac:	74 24                	je     0x4c8bd2
  4c8bae:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4c8bb4:	85 c0                	test   eax,eax
  4c8bb6:	74 1a                	je     0x4c8bd2
  4c8bb8:	8b 16                	mov    edx,DWORD PTR [esi]
  4c8bba:	53                   	push   ebx
  4c8bbb:	8d 58 04             	lea    ebx,[eax+0x4]
  4c8bbe:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  4c8bc1:	57                   	push   edi
  4c8bc2:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4c8bc4:	8b ce                	mov    ecx,esi
  4c8bc6:	ff d0                	call   eax
  4c8bc8:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  4c8bcb:	50                   	push   eax
  4c8bcc:	8b cb                	mov    ecx,ebx
  4c8bce:	ff d2                	call   edx
  4c8bd0:	5f                   	pop    edi
  4c8bd1:	5b                   	pop    ebx
  4c8bd2:	5e                   	pop    esi
  4c8bd3:	5d                   	pop    ebp
  4c8bd4:	c2 08 00             	ret    0x8
  4c8bd7:	cc                   	int3
  4c8bd8:	cc                   	int3
  4c8bd9:	cc                   	int3
  4c8bda:	cc                   	int3
  4c8bdb:	cc                   	int3
  4c8bdc:	cc                   	int3
  4c8bdd:	cc                   	int3
  4c8bde:	cc                   	int3
  4c8bdf:	cc                   	int3
```

### 二維底層writer：`0x004CAB80..0x004CABE0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cab80 <.text+0xc9b80>:
  4cab80:	55                   	push   ebp
  4cab81:	8b ec                	mov    ebp,esp
  4cab83:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4cab86:	d9 81 a0 00 00 00    	fld    DWORD PTR [ecx+0xa0]
  4cab8c:	d9 02                	fld    DWORD PTR [edx]
  4cab8e:	df e9                	fucomip st,st(1)
  4cab90:	dd d8                	fstp   st(0)
  4cab92:	9f                   	lahf
  4cab93:	f6 c4 44             	test   ah,0x44
  4cab96:	7a 13                	jp     0x4cabab
  4cab98:	d9 81 a4 00 00 00    	fld    DWORD PTR [ecx+0xa4]
  4cab9e:	d9 42 04             	fld    DWORD PTR [edx+0x4]
  4caba1:	df e9                	fucomip st,st(1)
  4caba3:	dd d8                	fstp   st(0)
  4caba5:	9f                   	lahf
  4caba6:	f6 c4 44             	test   ah,0x44
  4caba9:	7b 28                	jnp    0x4cabd3
  4cabab:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  4cabaf:	8b 02                	mov    eax,DWORD PTR [edx]
  4cabb1:	89 81 a0 00 00 00    	mov    DWORD PTR [ecx+0xa0],eax
  4cabb7:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  4cabba:	89 91 a4 00 00 00    	mov    DWORD PTR [ecx+0xa4],edx
  4cabc0:	74 11                	je     0x4cabd3
  4cabc2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4cabc4:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  4cabc7:	c7 81 ac 00 00 00 01 	mov    DWORD PTR [ecx+0xac],0x1
  4cabce:	00 00 00 
  4cabd1:	ff d2                	call   edx
  4cabd3:	5d                   	pop    ebp
  4cabd4:	c2 08 00             	ret    0x8
  4cabd7:	cc                   	int3
  4cabd8:	cc                   	int3
  4cabd9:	cc                   	int3
  4cabda:	cc                   	int3
  4cabdb:	cc                   	int3
  4cabdc:	cc                   	int3
  4cabdd:	cc                   	int3
  4cabde:	cc                   	int3
  4cabdf:	cc                   	int3
```

### BYTE setter：`0x004C8C30..0x004C8C40`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8c30 <.text+0xc7c30>:
  4c8c30:	55                   	push   ebp
  4c8c31:	8b ec                	mov    ebp,esp
  4c8c33:	8a 45 08             	mov    al,BYTE PTR [ebp+0x8]
  4c8c36:	88 81 b0 00 00 00    	mov    BYTE PTR [ecx+0xb0],al
  4c8c3c:	5d                   	pop    ebp
  4c8c3d:	c2 04 00             	ret    0x4
```

### CMonster構造與deleting destructor：`0x004D1710..0x004D1910`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1710 <.text+0xd0710>:
  4d1710:	55                   	push   ebp
  4d1711:	8b ec                	mov    ebp,esp
  4d1713:	6a ff                	push   0xffffffff
  4d1715:	68 b9 08 91 00       	push   0x9108b9
  4d171a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4d1720:	50                   	push   eax
  4d1721:	51                   	push   ecx
  4d1722:	53                   	push   ebx
  4d1723:	56                   	push   esi
  4d1724:	57                   	push   edi
  4d1725:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4d172a:	33 c5                	xor    eax,ebp
  4d172c:	50                   	push   eax
  4d172d:	8d 45 f4             	lea    eax,[ebp-0xc]
  4d1730:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4d1736:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4d1739:	57                   	push   edi
  4d173a:	e8 31 59 ff ff       	call   0x4c7070
  4d173f:	33 db                	xor    ebx,ebx
  4d1741:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4d1744:	0f 57 c0             	xorps  xmm0,xmm0
  4d1747:	6a 3c                	push   0x3c
  4d1749:	c7 07 dc c9 c0 00    	mov    DWORD PTR [edi],0xc0c9dc
  4d174f:	c7 87 f0 00 00 00 64 	mov    DWORD PTR [edi+0xf0],0xc0ca64
  4d1756:	ca c0 00 
  4d1759:	89 9f 20 04 00 00    	mov    DWORD PTR [edi+0x420],ebx
  4d175f:	89 9f 28 04 00 00    	mov    DWORD PTR [edi+0x428],ebx
  4d1765:	f3 0f 11 87 2c 04 00 	movss  DWORD PTR [edi+0x42c],xmm0
  4d176c:	00 
  4d176d:	89 9f 30 04 00 00    	mov    DWORD PTR [edi+0x430],ebx
  4d1773:	e8 f0 fa 3b 00       	call   0x891268
  4d1778:	8b f0                	mov    esi,eax
  4d177a:	83 c4 04             	add    esp,0x4
  4d177d:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4d1780:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4d1784:	3b f3                	cmp    esi,ebx
  4d1786:	74 19                	je     0x4d17a1
  4d1788:	8b c7                	mov    eax,edi
  4d178a:	8d 4b 03             	lea    ecx,[ebx+0x3]
  4d178d:	e8 9e 9a ff ff       	call   0x4cb230
  4d1792:	c7 06 cc 77 c0 00    	mov    DWORD PTR [esi],0xc077cc
  4d1798:	c7 46 34 01 00 00 00 	mov    DWORD PTR [esi+0x34],0x1
  4d179f:	eb 02                	jmp    0x4d17a3
  4d17a1:	33 f6                	xor    esi,esi
  4d17a3:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4d17a7:	8b 5e 08             	mov    ebx,DWORD PTR [esi+0x8]
  4d17aa:	83 bc 9f f4 00 00 00 	cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
  4d17b1:	00 
  4d17b2:	74 0d                	je     0x4d17c1
  4d17b4:	68 3c 75 c0 00       	push   0xc0753c
  4d17b9:	e8 a2 c3 21 00       	call   0x6edb60
  4d17be:	83 c4 04             	add    esp,0x4
  4d17c1:	89 b4 9f f4 00 00 00 	mov    DWORD PTR [edi+ebx*4+0xf4],esi
  4d17c8:	83 bf 58 01 00 00 00 	cmp    DWORD PTR [edi+0x158],0x0
  4d17cf:	75 06                	jne    0x4d17d7
  4d17d1:	89 b7 58 01 00 00    	mov    DWORD PTR [edi+0x158],esi
  4d17d7:	6a 38                	push   0x38
  4d17d9:	e8 8a fa 3b 00       	call   0x891268
  4d17de:	8b f0                	mov    esi,eax
  4d17e0:	83 c4 04             	add    esp,0x4
  4d17e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4d17e6:	b9 02 00 00 00       	mov    ecx,0x2
  4d17eb:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  4d17ee:	85 f6                	test   esi,esi
  4d17f0:	74 1d                	je     0x4d180f
  4d17f2:	8b c7                	mov    eax,edi
  4d17f4:	e8 37 9a ff ff       	call   0x4cb230
  4d17f9:	b8 01 00 00 00       	mov    eax,0x1
  4d17fe:	c7 06 b4 77 c0 00    	mov    DWORD PTR [esi],0xc077b4
  4d1804:	89 46 28             	mov    DWORD PTR [esi+0x28],eax
  4d1807:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  4d180a:	89 46 30             	mov    DWORD PTR [esi+0x30],eax
  4d180d:	eb 02                	jmp    0x4d1811
  4d180f:	33 f6                	xor    esi,esi
  4d1811:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4d1815:	8b 5e 08             	mov    ebx,DWORD PTR [esi+0x8]
  4d1818:	83 bc 9f f4 00 00 00 	cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
  4d181f:	00 
  4d1820:	74 0d                	je     0x4d182f
  4d1822:	68 3c 75 c0 00       	push   0xc0753c
  4d1827:	e8 34 c3 21 00       	call   0x6edb60
  4d182c:	83 c4 04             	add    esp,0x4
  4d182f:	89 b4 9f f4 00 00 00 	mov    DWORD PTR [edi+ebx*4+0xf4],esi
  4d1836:	83 bf 58 01 00 00 00 	cmp    DWORD PTR [edi+0x158],0x0
  4d183d:	75 06                	jne    0x4d1845
  4d183f:	89 b7 58 01 00 00    	mov    DWORD PTR [edi+0x158],esi
  4d1845:	6a 3c                	push   0x3c
  4d1847:	e8 1c fa 3b 00       	call   0x891268
  4d184c:	8b f0                	mov    esi,eax
  4d184e:	83 c4 04             	add    esp,0x4
  4d1851:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4d1854:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4d1858:	85 f6                	test   esi,esi
  4d185a:	74 22                	je     0x4d187e
  4d185c:	8b c7                	mov    eax,edi
  4d185e:	b9 05 00 00 00       	mov    ecx,0x5
  4d1863:	e8 c8 99 ff ff       	call   0x4cb230
  4d1868:	c7 46 38 09 00 00 00 	mov    DWORD PTR [esi+0x38],0x9
  4d186f:	c7 06 fc 77 c0 00    	mov    DWORD PTR [esi],0xc077fc
  4d1875:	c7 46 2c 01 00 00 00 	mov    DWORD PTR [esi+0x2c],0x1
  4d187c:	eb 02                	jmp    0x4d1880
  4d187e:	33 f6                	xor    esi,esi
  4d1880:	8b 5e 08             	mov    ebx,DWORD PTR [esi+0x8]
  4d1883:	83 bc 9f f4 00 00 00 	cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
  4d188a:	00 
  4d188b:	74 0d                	je     0x4d189a
  4d188d:	68 3c 75 c0 00       	push   0xc0753c
  4d1892:	e8 c9 c2 21 00       	call   0x6edb60
  4d1897:	83 c4 04             	add    esp,0x4
  4d189a:	89 b4 9f f4 00 00 00 	mov    DWORD PTR [edi+ebx*4+0xf4],esi
  4d18a1:	83 bf 58 01 00 00 00 	cmp    DWORD PTR [edi+0x158],0x0
  4d18a8:	8b c7                	mov    eax,edi
  4d18aa:	75 06                	jne    0x4d18b2
  4d18ac:	89 b7 58 01 00 00    	mov    DWORD PTR [edi+0x158],esi
  4d18b2:	c7 87 9c 03 00 00 01 	mov    DWORD PTR [edi+0x39c],0x1
  4d18b9:	00 00 00 
  4d18bc:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4d18bf:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4d18c6:	59                   	pop    ecx
  4d18c7:	5f                   	pop    edi
  4d18c8:	5e                   	pop    esi
  4d18c9:	5b                   	pop    ebx
  4d18ca:	8b e5                	mov    esp,ebp
  4d18cc:	5d                   	pop    ebp
  4d18cd:	c2 04 00             	ret    0x4
  4d18d0:	55                   	push   ebp
  4d18d1:	8b ec                	mov    ebp,esp
  4d18d3:	56                   	push   esi
  4d18d4:	8b f1                	mov    esi,ecx
  4d18d6:	c7 06 dc c9 c0 00    	mov    DWORD PTR [esi],0xc0c9dc
  4d18dc:	c7 86 f0 00 00 00 64 	mov    DWORD PTR [esi+0xf0],0xc0ca64
  4d18e3:	ca c0 00 
  4d18e6:	e8 a5 62 ff ff       	call   0x4c7b90
  4d18eb:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4d18ef:	74 09                	je     0x4d18fa
  4d18f1:	56                   	push   esi
  4d18f2:	e8 15 f9 3b 00       	call   0x89120c
  4d18f7:	83 c4 04             	add    esp,0x4
  4d18fa:	8b c6                	mov    eax,esi
  4d18fc:	5e                   	pop    esi
  4d18fd:	5d                   	pop    ebp
  4d18fe:	c2 04 00             	ret    0x4
  4d1901:	cc                   	int3
  4d1902:	cc                   	int3
  4d1903:	cc                   	int3
  4d1904:	cc                   	int3
  4d1905:	cc                   	int3
  4d1906:	cc                   	int3
  4d1907:	cc                   	int3
  4d1908:	cc                   	int3
  4d1909:	cc                   	int3
  4d190a:	cc                   	int3
  4d190b:	cc                   	int3
  4d190c:	cc                   	int3
  4d190d:	cc                   	int3
  4d190e:	cc                   	int3
  4d190f:	cc                   	int3
```

### CMonster預清理：`0x004D1F80..0x004D1F90`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1f80 <.text+0xd0f80>:
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
  4d1f88:	cc                   	int3
  4d1f89:	cc                   	int3
  4d1f8a:	cc                   	int3
  4d1f8b:	cc                   	int3
  4d1f8c:	cc                   	int3
  4d1f8d:	cc                   	int3
  4d1f8e:	cc                   	int3
  4d1f8f:	cc                   	int3
```

### base預清理完整code：`0x004C8360..0x004C83C0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8360 <.text+0xc7360>:
  4c8360:	53                   	push   ebx
  4c8361:	56                   	push   esi
  4c8362:	57                   	push   edi
  4c8363:	8b f9                	mov    edi,ecx
  4c8365:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4c836b:	85 c0                	test   eax,eax
  4c836d:	74 0a                	je     0x4c8379
  4c836f:	8d 48 08             	lea    ecx,[eax+0x8]
  4c8372:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c8374:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c8377:	ff d2                	call   edx
  4c8379:	8b 87 64 03 00 00    	mov    eax,DWORD PTR [edi+0x364]
  4c837f:	85 c0                	test   eax,eax
  4c8381:	74 0e                	je     0x4c8391
  4c8383:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c8387:	8d 70 24             	lea    esi,[eax+0x24]
  4c838a:	74 05                	je     0x4c8391
  4c838c:	e8 5f 62 2f 00       	call   0x7be5f0
  4c8391:	81 c7 64 01 00 00    	add    edi,0x164
  4c8397:	bb 80 00 00 00       	mov    ebx,0x80
  4c839c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4c83a0:	8b 07                	mov    eax,DWORD PTR [edi]
  4c83a2:	85 c0                	test   eax,eax
  4c83a4:	74 0e                	je     0x4c83b4
  4c83a6:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c83aa:	8d 70 24             	lea    esi,[eax+0x24]
  4c83ad:	74 05                	je     0x4c83b4
  4c83af:	e8 3c 62 2f 00       	call   0x7be5f0
  4c83b4:	83 c7 04             	add    edi,0x4
  4c83b7:	4b                   	dec    ebx
  4c83b8:	75 e6                	jne    0x4c83a0
  4c83ba:	5f                   	pop    edi
  4c83bb:	5e                   	pop    esi
  4c83bc:	33 c0                	xor    eax,eax
  4c83be:	5b                   	pop    ebx
  4c83bf:	c3                   	ret
```

### base ctor的pair初始化有界窗口：`0x004C7070..0x004C70EA`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7070 <.text+0xc6070>:
  4c7070:	55                   	push   ebp
  4c7071:	8b ec                	mov    ebp,esp
  4c7073:	6a ff                	push   0xffffffff
  4c7075:	68 dc da 90 00       	push   0x90dadc
  4c707a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c7080:	50                   	push   eax
  4c7081:	83 ec 24             	sub    esp,0x24
  4c7084:	53                   	push   ebx
  4c7085:	56                   	push   esi
  4c7086:	57                   	push   edi
  4c7087:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c708c:	33 c5                	xor    eax,ebp
  4c708e:	50                   	push   eax
  4c708f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c7092:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c7098:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c709b:	8b f3                	mov    esi,ebx
  4c709d:	e8 8e 36 00 00       	call   0x4ca730
  4c70a2:	8d 83 f0 00 00 00    	lea    eax,[ebx+0xf0]
  4c70a8:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c70af:	e8 dc 2e 00 00       	call   0x4c9f90
  4c70b4:	c7 83 f0 00 00 00 ec 	mov    DWORD PTR [ebx+0xf0],0xc075ec
  4c70bb:	75 c0 00 
  4c70be:	33 f6                	xor    esi,esi
  4c70c0:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c70c4:	8d 83 5c 01 00 00    	lea    eax,[ebx+0x15c]
  4c70ca:	56                   	push   esi
  4c70cb:	c7 03 54 75 c0 00    	mov    DWORD PTR [ebx],0xc07554
  4c70d1:	c7 83 f0 00 00 00 dc 	mov    DWORD PTR [ebx+0xf0],0xc075dc
  4c70d8:	75 c0 00 
  4c70db:	50                   	push   eax
  4c70dc:	89 30                	mov    DWORD PTR [eax],esi
  4c70de:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4c70e1:	e8 7a 33 00 00       	call   0x4ca460
  4c70e6:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
```

### pair控制區配置完整code含例外路徑：`0x004CA460..0x004CA520`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ca460 <.text+0xc9460>:
  4ca460:	55                   	push   ebp
  4ca461:	8b ec                	mov    ebp,esp
  4ca463:	6a ff                	push   0xffffffff
  4ca465:	68 20 89 90 00       	push   0x908920
  4ca46a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ca470:	50                   	push   eax
  4ca471:	51                   	push   ecx
  4ca472:	53                   	push   ebx
  4ca473:	56                   	push   esi
  4ca474:	57                   	push   edi
  4ca475:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ca47a:	33 c5                	xor    eax,ebp
  4ca47c:	50                   	push   eax
  4ca47d:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ca480:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ca486:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  4ca489:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4ca48c:	33 ff                	xor    edi,edi
  4ca48e:	6a 10                	push   0x10
  4ca490:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4ca493:	e8 d0 6d 3c 00       	call   0x891268
  4ca498:	83 c4 04             	add    esp,0x4
  4ca49b:	3b c7                	cmp    eax,edi
  4ca49d:	74 16                	je     0x4ca4b5
  4ca49f:	b9 01 00 00 00       	mov    ecx,0x1
  4ca4a4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4ca4a7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4ca4aa:	c7 00 0c 76 c0 00    	mov    DWORD PTR [eax],0xc0760c
  4ca4b0:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  4ca4b3:	8b f8                	mov    edi,eax
  4ca4b5:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4ca4b8:	57                   	push   edi
  4ca4b9:	53                   	push   ebx
  4ca4ba:	e8 01 8d 2d 00       	call   0x7a31c0
  4ca4bf:	85 db                	test   ebx,ebx
  4ca4c1:	74 30                	je     0x4ca4f3
  4ca4c3:	85 ff                	test   edi,edi
  4ca4c5:	74 0c                	je     0x4ca4d3
  4ca4c7:	8d 47 08             	lea    eax,[edi+0x8]
  4ca4ca:	b9 01 00 00 00       	mov    ecx,0x1
  4ca4cf:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4ca4d3:	8b 4b 14             	mov    ecx,DWORD PTR [ebx+0x14]
  4ca4d6:	85 c9                	test   ecx,ecx
  4ca4d8:	74 13                	je     0x4ca4ed
  4ca4da:	8d 51 08             	lea    edx,[ecx+0x8]
  4ca4dd:	83 c8 ff             	or     eax,0xffffffff
  4ca4e0:	f0 0f c1 02          	lock xadd DWORD PTR [edx],eax
  4ca4e4:	75 07                	jne    0x4ca4ed
  4ca4e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ca4e8:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4ca4eb:	ff d0                	call   eax
  4ca4ed:	89 7b 14             	mov    DWORD PTR [ebx+0x14],edi
  4ca4f0:	89 5b 10             	mov    DWORD PTR [ebx+0x10],ebx
  4ca4f3:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ca4f6:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ca4fd:	59                   	pop    ecx
  4ca4fe:	5f                   	pop    edi
  4ca4ff:	5e                   	pop    esi
  4ca500:	5b                   	pop    ebx
  4ca501:	8b e5                	mov    esp,ebp
  4ca503:	5d                   	pop    ebp
  4ca504:	c2 08 00             	ret    0x8
  4ca507:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ca50a:	85 c9                	test   ecx,ecx
  4ca50c:	74 08                	je     0x4ca516
  4ca50e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ca510:	8b 02                	mov    eax,DWORD PTR [edx]
  4ca512:	6a 01                	push   0x1
  4ca514:	ff d0                	call   eax
  4ca516:	6a 00                	push   0x0
  4ca518:	6a 00                	push   0x0
  4ca51a:	e8 d1 24 3d 00       	call   0x89c9f0
  4ca51f:	cc                   	int3
```

### pair交換／釋放helper完整code：`0x007A31C0..0x007A3230`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a31c0 <.text+0x3a21c0>:
  7a31c0:	55                   	push   ebp
  7a31c1:	8b ec                	mov    ebp,esp
  7a31c3:	53                   	push   ebx
  7a31c4:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  7a31c7:	57                   	push   edi
  7a31c8:	8b 7e 04             	mov    edi,DWORD PTR [esi+0x4]
  7a31cb:	85 ff                	test   edi,edi
  7a31cd:	74 29                	je     0x7a31f8
  7a31cf:	8d 47 04             	lea    eax,[edi+0x4]
  7a31d2:	83 c9 ff             	or     ecx,0xffffffff
  7a31d5:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  7a31d9:	75 39                	jne    0x7a3214
  7a31db:	8b 17                	mov    edx,DWORD PTR [edi]
  7a31dd:	8b 02                	mov    eax,DWORD PTR [edx]
  7a31df:	8b cf                	mov    ecx,edi
  7a31e1:	ff d0                	call   eax
  7a31e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  7a31e6:	83 ca ff             	or     edx,0xffffffff
  7a31e9:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  7a31ed:	75 17                	jne    0x7a3206
  7a31ef:	8b 07                	mov    eax,DWORD PTR [edi]
  7a31f1:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a31f4:	8b cf                	mov    ecx,edi
  7a31f6:	ff d2                	call   edx
  7a31f8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7a31fb:	5f                   	pop    edi
  7a31fc:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  7a31ff:	89 06                	mov    DWORD PTR [esi],eax
  7a3201:	5b                   	pop    ebx
  7a3202:	5d                   	pop    ebp
  7a3203:	c2 08 00             	ret    0x8
  7a3206:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7a3209:	5f                   	pop    edi
  7a320a:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  7a320d:	89 0e                	mov    DWORD PTR [esi],ecx
  7a320f:	5b                   	pop    ebx
  7a3210:	5d                   	pop    ebp
  7a3211:	c2 08 00             	ret    0x8
  7a3214:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7a3217:	5f                   	pop    edi
  7a3218:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  7a321b:	89 16                	mov    DWORD PTR [esi],edx
  7a321d:	5b                   	pop    ebx
  7a321e:	5d                   	pop    ebp
  7a321f:	c2 08 00             	ret    0x8
  7a3222:	cc                   	int3
  7a3223:	cc                   	int3
  7a3224:	cc                   	int3
  7a3225:	cc                   	int3
  7a3226:	cc                   	int3
  7a3227:	cc                   	int3
  7a3228:	cc                   	int3
  7a3229:	cc                   	int3
  7a322a:	cc                   	int3
  7a322b:	cc                   	int3
  7a322c:	cc                   	int3
  7a322d:	cc                   	int3
  7a322e:	cc                   	int3
  7a322f:	cc                   	int3
```

### base dtor有界窗口：pair與128槽迴圈：`0x004C7B90..0x004C7D10`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7b90 <.text+0xc6b90>:
  4c7b90:	55                   	push   ebp
  4c7b91:	8b ec                	mov    ebp,esp
  4c7b93:	6a ff                	push   0xffffffff
  4c7b95:	68 b9 d9 90 00       	push   0x90d9b9
  4c7b9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c7ba0:	50                   	push   eax
  4c7ba1:	83 ec 0c             	sub    esp,0xc
  4c7ba4:	53                   	push   ebx
  4c7ba5:	56                   	push   esi
  4c7ba6:	57                   	push   edi
  4c7ba7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c7bac:	33 c5                	xor    eax,ebp
  4c7bae:	50                   	push   eax
  4c7baf:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c7bb2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c7bb8:	8b d9                	mov    ebx,ecx
  4c7bba:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  4c7bbd:	c7 03 54 75 c0 00    	mov    DWORD PTR [ebx],0xc07554
  4c7bc3:	c7 83 f0 00 00 00 dc 	mov    DWORD PTR [ebx+0xf0],0xc075dc
  4c7bca:	75 c0 00 
  4c7bcd:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  4c7bd4:	8b bb 68 03 00 00    	mov    edi,DWORD PTR [ebx+0x368]
  4c7bda:	85 ff                	test   edi,edi
  4c7bdc:	74 3b                	je     0x4c7c19
  4c7bde:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7be1:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4c7be5:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7be8:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7bea:	50                   	push   eax
  4c7beb:	51                   	push   ecx
  4c7bec:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7bef:	8b c7                	mov    eax,edi
  4c7bf1:	e8 da be 36 00       	call   0x833ad0
  4c7bf6:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  4c7bfa:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7bfd:	50                   	push   eax
  4c7bfe:	e8 09 96 3c 00       	call   0x89120c
  4c7c03:	83 c4 04             	add    esp,0x4
  4c7c06:	57                   	push   edi
  4c7c07:	e8 00 96 3c 00       	call   0x89120c
  4c7c0c:	83 c4 04             	add    esp,0x4
  4c7c0f:	c7 83 68 03 00 00 00 	mov    DWORD PTR [ebx+0x368],0x0
  4c7c16:	00 00 00 
  4c7c19:	8b b3 60 01 00 00    	mov    esi,DWORD PTR [ebx+0x160]
  4c7c1f:	33 c0                	xor    eax,eax
  4c7c21:	89 83 60 01 00 00    	mov    DWORD PTR [ebx+0x160],eax
  4c7c27:	89 83 5c 01 00 00    	mov    DWORD PTR [ebx+0x15c],eax
  4c7c2d:	3b f0                	cmp    esi,eax
  4c7c2f:	74 29                	je     0x4c7c5a
  4c7c31:	8d 46 04             	lea    eax,[esi+0x4]
  4c7c34:	83 c9 ff             	or     ecx,0xffffffff
  4c7c37:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c7c3b:	75 1d                	jne    0x4c7c5a
  4c7c3d:	8b 16                	mov    edx,DWORD PTR [esi]
  4c7c3f:	8b 02                	mov    eax,DWORD PTR [edx]
  4c7c41:	8b ce                	mov    ecx,esi
  4c7c43:	ff d0                	call   eax
  4c7c45:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c7c48:	83 ca ff             	or     edx,0xffffffff
  4c7c4b:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c7c4f:	75 09                	jne    0x4c7c5a
  4c7c51:	8b 06                	mov    eax,DWORD PTR [esi]
  4c7c53:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c7c56:	8b ce                	mov    ecx,esi
  4c7c58:	ff d2                	call   edx
  4c7c5a:	8b bb 64 03 00 00    	mov    edi,DWORD PTR [ebx+0x364]
  4c7c60:	85 ff                	test   edi,edi
  4c7c62:	74 0f                	je     0x4c7c73
  4c7c64:	e8 47 01 00 00       	call   0x4c7db0
  4c7c69:	c7 83 64 03 00 00 00 	mov    DWORD PTR [ebx+0x364],0x0
  4c7c70:	00 00 00 
  4c7c73:	8d 83 64 01 00 00    	lea    eax,[ebx+0x164]
  4c7c79:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c7c7c:	c7 45 ec 80 00 00 00 	mov    DWORD PTR [ebp-0x14],0x80
  4c7c83:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c7c86:	8b 39                	mov    edi,DWORD PTR [ecx]
  4c7c88:	85 ff                	test   edi,edi
  4c7c8a:	74 3d                	je     0x4c7cc9
  4c7c8c:	8d 77 24             	lea    esi,[edi+0x24]
  4c7c8f:	e8 5c 69 2f 00       	call   0x7be5f0
  4c7c94:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7c97:	85 c9                	test   ecx,ecx
  4c7c99:	74 1c                	je     0x4c7cb7
  4c7c9b:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c7c9d:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  4c7ca0:	ff d0                	call   eax
  4c7ca2:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7ca5:	85 c9                	test   ecx,ecx
  4c7ca7:	74 0e                	je     0x4c7cb7
  4c7ca9:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c7cab:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  4c7cae:	ff d0                	call   eax
  4c7cb0:	c7 47 28 00 00 00 00 	mov    DWORD PTR [edi+0x28],0x0
  4c7cb7:	57                   	push   edi
  4c7cb8:	e8 4f 95 3c 00       	call   0x89120c
  4c7cbd:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c7cc0:	83 c4 04             	add    esp,0x4
  4c7cc3:	c7 01 00 00 00 00    	mov    DWORD PTR [ecx],0x0
  4c7cc9:	83 45 f0 04          	add    DWORD PTR [ebp-0x10],0x4
  4c7ccd:	ff 4d ec             	dec    DWORD PTR [ebp-0x14]
  4c7cd0:	75 b1                	jne    0x4c7c83
  4c7cd2:	8d bb f0 03 00 00    	lea    edi,[ebx+0x3f0]
  4c7cd8:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7cdb:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  4c7cdf:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7ce2:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7ce4:	50                   	push   eax
  4c7ce5:	51                   	push   ecx
  4c7ce6:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7ce9:	8b c7                	mov    eax,edi
  4c7ceb:	e8 d0 c3 08 00       	call   0x5540c0
  4c7cf0:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  4c7cf3:	57                   	push   edi
  4c7cf4:	e8 13 95 3c 00       	call   0x89120c
  4c7cf9:	8d bb 78 03 00 00    	lea    edi,[ebx+0x378]
  4c7cff:	83 c4 04             	add    esp,0x4
  4c7d02:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7d05:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  4c7d09:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7d0c:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7d0e:	50                   	push   eax
  4c7d0f:	51                   	push   ecx
```

### T08-173 writer指定窗口與disable入口：`0x007B7FD0..0x007B8068`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b7fd0 <.text+0x3b6fd0>:
  7b7fd0:	55                   	push   ebp
  7b7fd1:	8b ec                	mov    ebp,esp
  7b7fd3:	53                   	push   ebx
  7b7fd4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b7fd7:	56                   	push   esi
  7b7fd8:	57                   	push   edi
  7b7fd9:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b7fdb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b7fde:	8b 30                	mov    esi,DWORD PTR [eax]
  7b7fe0:	3b f0                	cmp    esi,eax
  7b7fe2:	74 11                	je     0x7b7ff5
  7b7fe4:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b7fe7:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7fe9:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7b7fec:	ff d2                	call   edx
  7b7fee:	8b 36                	mov    esi,DWORD PTR [esi]
  7b7ff0:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7b7ff3:	75 ef                	jne    0x7b7fe4
  7b7ff5:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b7ff8:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7ffa:	3b c1                	cmp    eax,ecx
  7b7ffc:	74 1c                	je     0x7b801a
  7b7ffe:	b9 01 00 00 00       	mov    ecx,0x1
  7b8003:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  7b8006:	89 4a 44             	mov    DWORD PTR [edx+0x44],ecx
  7b8009:	8b 00                	mov    eax,DWORD PTR [eax]
  7b800b:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b800e:	75 f3                	jne    0x7b8003
  7b8010:	5f                   	pop    edi
  7b8011:	5e                   	pop    esi
  7b8012:	89 4b 30             	mov    DWORD PTR [ebx+0x30],ecx
  7b8015:	5b                   	pop    ebx
  7b8016:	5d                   	pop    ebp
  7b8017:	c2 04 00             	ret    0x4
  7b801a:	5f                   	pop    edi
  7b801b:	5e                   	pop    esi
  7b801c:	c7 43 30 01 00 00 00 	mov    DWORD PTR [ebx+0x30],0x1
  7b8023:	5b                   	pop    ebx
  7b8024:	5d                   	pop    ebp
  7b8025:	c2 04 00             	ret    0x4
  7b8028:	cc                   	int3
  7b8029:	cc                   	int3
  7b802a:	cc                   	int3
  7b802b:	cc                   	int3
  7b802c:	cc                   	int3
  7b802d:	cc                   	int3
  7b802e:	cc                   	int3
  7b802f:	cc                   	int3
  7b8030:	55                   	push   ebp
  7b8031:	8b ec                	mov    ebp,esp
  7b8033:	53                   	push   ebx
  7b8034:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b8037:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b803a:	56                   	push   esi
  7b803b:	57                   	push   edi
  7b803c:	8b 38                	mov    edi,DWORD PTR [eax]
  7b803e:	3b f8                	cmp    edi,eax
  7b8040:	74 16                	je     0x7b8058
  7b8042:	8b 77 24             	mov    esi,DWORD PTR [edi+0x24]
  7b8045:	e8 a6 51 02 00       	call   0x7dd1f0
  7b804a:	c7 46 44 00 00 00 00 	mov    DWORD PTR [esi+0x44],0x0
  7b8051:	8b 3f                	mov    edi,DWORD PTR [edi]
  7b8053:	3b 7b 08             	cmp    edi,DWORD PTR [ebx+0x8]
  7b8056:	75 ea                	jne    0x7b8042
  7b8058:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b805a:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b805d:	8b 30                	mov    esi,DWORD PTR [eax]
  7b805f:	3b f0                	cmp    esi,eax
  7b8061:	74 11                	je     0x7b8074
  7b8063:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b8066:	8b 01                	mov    eax,DWORD PTR [ecx]
```

### T08-187 wrapper指定窗口，從有效call起點：`0x007F6FBA..0x007F700E`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f6fba <.text+0x3f5fba>:
  7f6fba:	e8 c1 11 fc ff       	call   0x7b8180
  7f6fbf:	6a 30                	push   0x30
  7f6fc1:	8b f8                	mov    edi,eax
  7f6fc3:	e8 a0 a2 09 00       	call   0x891268
  7f6fc8:	8b f0                	mov    esi,eax
  7f6fca:	83 c4 04             	add    esp,0x4
  7f6fcd:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7f6fd0:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7f6fd7:	85 f6                	test   esi,esi
  7f6fd9:	74 46                	je     0x7f7021
  7f6fdb:	57                   	push   edi
  7f6fdc:	e8 cf 5f fe ff       	call   0x7dcfb0
  7f6fe1:	d9 ee                	fldz
  7f6fe3:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  7f6fea:	c7 06 cc 11 c5 00    	mov    DWORD PTR [esi],0xc511cc
  7f6ff0:	d9 56 08             	fst    DWORD PTR [esi+0x8]
  7f6ff3:	d9 56 0c             	fst    DWORD PTR [esi+0xc]
  7f6ff6:	d9 56 10             	fst    DWORD PTR [esi+0x10]
  7f6ff9:	d9 56 14             	fst    DWORD PTR [esi+0x14]
  7f6ffc:	d9 56 18             	fst    DWORD PTR [esi+0x18]
  7f6fff:	d9 56 1c             	fst    DWORD PTR [esi+0x1c]
  7f7002:	d9 56 20             	fst    DWORD PTR [esi+0x20]
  7f7005:	d9 56 24             	fst    DWORD PTR [esi+0x24]
  7f7008:	d9 5e 28             	fstp   DWORD PTR [esi+0x28]
  7f700b:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
```

### 201-2 CMonster slot30入口到child建構caller：`0x004D1910..0x004D194F`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1910 <.text+0xd0910>:
  4d1910:	55                   	push   ebp
  4d1911:	8b ec                	mov    ebp,esp
  4d1913:	6a ff                	push   0xffffffff
  4d1915:	68 b8 9d 93 00       	push   0x939db8
  4d191a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4d1920:	50                   	push   eax
  4d1921:	83 ec 1c             	sub    esp,0x1c
  4d1924:	53                   	push   ebx
  4d1925:	56                   	push   esi
  4d1926:	57                   	push   edi
  4d1927:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4d192c:	33 c5                	xor    eax,ebp
  4d192e:	50                   	push   eax
  4d192f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4d1932:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4d1938:	8b f1                	mov    esi,ecx
  4d193a:	33 ff                	xor    edi,edi
  4d193c:	57                   	push   edi
  4d193d:	56                   	push   esi
  4d193e:	e8 ad 64 ff ff       	call   0x4c7df0
  4d1943:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4d1946:	8b 06                	mov    eax,DWORD PTR [esi]
  4d1948:	8b 50 64             	mov    edx,DWORD PTR [eax+0x64]
  4d194b:	8b ce                	mov    ecx,esi
  4d194d:	ff d2                	call   edx
```

### 201-2 child實際建立與rebuild完整code：`0x004C7DF0..0x004C8240`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7df0 <.text+0xc6df0>:
  4c7df0:	55                   	push   ebp
  4c7df1:	8b ec                	mov    ebp,esp
  4c7df3:	83 e4 f8             	and    esp,0xfffffff8
  4c7df6:	6a ff                	push   0xffffffff
  4c7df8:	68 3e 96 93 00       	push   0x93963e
  4c7dfd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c7e03:	50                   	push   eax
  4c7e04:	83 ec 10             	sub    esp,0x10
  4c7e07:	53                   	push   ebx
  4c7e08:	56                   	push   esi
  4c7e09:	57                   	push   edi
  4c7e0a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c7e0f:	33 c4                	xor    eax,esp
  4c7e11:	50                   	push   eax
  4c7e12:	8d 44 24 20          	lea    eax,[esp+0x20]
  4c7e16:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c7e1c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c7e1f:	33 ff                	xor    edi,edi
  4c7e21:	39 bb 70 03 00 00    	cmp    DWORD PTR [ebx+0x370],edi
  4c7e27:	0f 85 09 02 00 00    	jne    0x4c8036
  4c7e2d:	8b 83 8c 00 00 00    	mov    eax,DWORD PTR [ebx+0x8c]
  4c7e33:	8b f0                	mov    esi,eax
  4c7e35:	3b c7                	cmp    eax,edi
  4c7e37:	75 06                	jne    0x4c7e3f
  4c7e39:	8b b3 88 00 00 00    	mov    esi,DWORD PTR [ebx+0x88]
  4c7e3f:	68 70 01 00 00       	push   0x170
  4c7e44:	e8 1f 94 3c 00       	call   0x891268
  4c7e49:	83 c4 04             	add    esp,0x4
  4c7e4c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c7e50:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4c7e54:	3b c7                	cmp    eax,edi
  4c7e56:	74 0c                	je     0x4c7e64
  4c7e58:	0f b7 ce             	movzx  ecx,si
  4c7e5b:	51                   	push   ecx
  4c7e5c:	50                   	push   eax
  4c7e5d:	e8 ee cd 2d 00       	call   0x7a4c50
  4c7e62:	eb 02                	jmp    0x4c7e66
  4c7e64:	33 c0                	xor    eax,eax
  4c7e66:	50                   	push   eax
  4c7e67:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c7e6b:	83 ce ff             	or     esi,0xffffffff
  4c7e6e:	89 74 24 2c          	mov    DWORD PTR [esp+0x2c],esi
  4c7e72:	52                   	push   edx
  4c7e73:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4c7e77:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4c7e7b:	e8 e0 25 00 00       	call   0x4ca460
  4c7e80:	8d bb 5c 01 00 00    	lea    edi,[ebx+0x15c]
  4c7e86:	8d 44 24 14          	lea    eax,[esp+0x14]
  4c7e8a:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  4c7e91:	00 
  4c7e92:	e8 c9 90 01 00       	call   0x4e0f60
  4c7e97:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4c7e9b:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4c7e9f:	85 f6                	test   esi,esi
  4c7ea1:	74 29                	je     0x4c7ecc
  4c7ea3:	8d 46 04             	lea    eax,[esi+0x4]
  4c7ea6:	83 c9 ff             	or     ecx,0xffffffff
  4c7ea9:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c7ead:	75 1d                	jne    0x4c7ecc
  4c7eaf:	8b 16                	mov    edx,DWORD PTR [esi]
  4c7eb1:	8b 02                	mov    eax,DWORD PTR [edx]
  4c7eb3:	8b ce                	mov    ecx,esi
  4c7eb5:	ff d0                	call   eax
  4c7eb7:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c7eba:	83 ca ff             	or     edx,0xffffffff
  4c7ebd:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c7ec1:	75 09                	jne    0x4c7ecc
  4c7ec3:	8b 06                	mov    eax,DWORD PTR [esi]
  4c7ec5:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c7ec8:	8b ce                	mov    ecx,esi
  4c7eca:	ff d2                	call   edx
  4c7ecc:	0f b7 8b 88 03 00 00 	movzx  ecx,WORD PTR [ebx+0x388]
  4c7ed3:	8b 07                	mov    eax,DWORD PTR [edi]
  4c7ed5:	51                   	push   ecx
  4c7ed6:	6a 01                	push   0x1
  4c7ed8:	50                   	push   eax
  4c7ed9:	e8 c2 ef 2d 00       	call   0x7a6ea0
  4c7ede:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  4c7ee2:	74 0e                	je     0x4c7ef2
  4c7ee4:	8b 07                	mov    eax,DWORD PTR [edi]
  4c7ee6:	c6 40 20 01          	mov    BYTE PTR [eax+0x20],0x1
  4c7eea:	8b 07                	mov    eax,DWORD PTR [edi]
  4c7eec:	50                   	push   eax
  4c7eed:	e8 7e 0f 2e 00       	call   0x7a8e70
  4c7ef2:	8b 13                	mov    edx,DWORD PTR [ebx]
  4c7ef4:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4c7ef7:	6a 01                	push   0x1
  4c7ef9:	8d 83 a0 00 00 00    	lea    eax,[ebx+0xa0]
  4c7eff:	50                   	push   eax
  4c7f00:	8b cb                	mov    ecx,ebx
  4c7f02:	c7 83 70 03 00 00 01 	mov    DWORD PTR [ebx+0x370],0x1
  4c7f09:	00 00 00 
  4c7f0c:	ff d2                	call   edx
  4c7f0e:	0f b6 8b b0 00 00 00 	movzx  ecx,BYTE PTR [ebx+0xb0]
  4c7f15:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c7f17:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4c7f1a:	51                   	push   ecx
  4c7f1b:	8b cb                	mov    ecx,ebx
  4c7f1d:	ff d2                	call   edx
  4c7f1f:	83 bb a8 03 00 00 00 	cmp    DWORD PTR [ebx+0x3a8],0x0
  4c7f26:	8a 83 b0 00 00 00    	mov    al,BYTE PTR [ebx+0xb0]
  4c7f2c:	88 44 24 14          	mov    BYTE PTR [esp+0x14],al
  4c7f30:	75 2f                	jne    0x4c7f61
  4c7f32:	83 bb 70 03 00 00 00 	cmp    DWORD PTR [ebx+0x370],0x0
  4c7f39:	88 83 a4 03 00 00    	mov    BYTE PTR [ebx+0x3a4],al
  4c7f3f:	74 20                	je     0x4c7f61
  4c7f41:	8b 3f                	mov    edi,DWORD PTR [edi]
  4c7f43:	85 ff                	test   edi,edi
  4c7f45:	74 1a                	je     0x4c7f61
  4c7f47:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4c7f4b:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  4c7f4e:	50                   	push   eax
  4c7f4f:	e8 3c cb f7 ff       	call   0x444a90
  4c7f54:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  4c7f57:	8d 4f 04             	lea    ecx,[edi+0x4]
  4c7f5a:	f3 0f 11 04 24       	movss  DWORD PTR [esp],xmm0
  4c7f5f:	ff d2                	call   edx
  4c7f61:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c7f63:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  4c7f69:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4c7f6c:	51                   	push   ecx
  4c7f6d:	8b cb                	mov    ecx,ebx
  4c7f6f:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c7f72:	ff d2                	call   edx
  4c7f74:	d9 e8                	fld1
  4c7f76:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c7f78:	8b 50 68             	mov    edx,DWORD PTR [eax+0x68]
  4c7f7b:	51                   	push   ecx
  4c7f7c:	8b 8b 8c 03 00 00    	mov    ecx,DWORD PTR [ebx+0x38c]
  4c7f82:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c7f85:	51                   	push   ecx
  4c7f86:	8b cb                	mov    ecx,ebx
  4c7f88:	ff d2                	call   edx
  4c7f8a:	6a 30                	push   0x30
  4c7f8c:	e8 d7 92 3c 00       	call   0x891268
  4c7f91:	83 c4 04             	add    esp,0x4
  4c7f94:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c7f98:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  4c7f9f:	00 
  4c7fa0:	85 c0                	test   eax,eax
  4c7fa2:	74 09                	je     0x4c7fad
  4c7fa4:	8b f0                	mov    esi,eax
  4c7fa6:	e8 55 c0 2e 00       	call   0x7b4000
  4c7fab:	eb 02                	jmp    0x4c7faf
  4c7fad:	33 c0                	xor    eax,eax
  4c7faf:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4c7fb6:	ff 
  4c7fb7:	89 83 68 03 00 00    	mov    DWORD PTR [ebx+0x368],eax
  4c7fbd:	c7 40 24 01 00 00 00 	mov    DWORD PTR [eax+0x24],0x1
  4c7fc4:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c7fc6:	8b 50 4c             	mov    edx,DWORD PTR [eax+0x4c]
  4c7fc9:	8b cb                	mov    ecx,ebx
  4c7fcb:	ff d2                	call   edx
  4c7fcd:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7fcf:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c7fd2:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  4c7fd5:	8b 83 68 03 00 00    	mov    eax,DWORD PTR [ebx+0x368]
  4c7fdb:	f3 0f 10 05 8c 5a c5 	movss  xmm0,DWORD PTR ds:0xc55a8c
  4c7fe2:	00 
  4c7fe3:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4c7fe6:	89 50 14             	mov    DWORD PTR [eax+0x14],edx
  4c7fe9:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  4c7fec:	8b 83 68 03 00 00    	mov    eax,DWORD PTR [ebx+0x368]
  4c7ff2:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4c7ff8:	f3 0f 10 05 08 58 c5 	movss  xmm0,DWORD PTR ds:0xc55808
  4c7fff:	00 
  4c8000:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4c8004:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4c800a:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4c800e:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  4c8011:	89 50 20             	mov    DWORD PTR [eax+0x20],edx
  4c8014:	8b 9b 68 03 00 00    	mov    ebx,DWORD PTR [ebx+0x368]
  4c801a:	53                   	push   ebx
  4c801b:	8d 44 24 14          	lea    eax,[esp+0x14]
  4c801f:	c6 44 24 14 00       	mov    BYTE PTR [esp+0x14],0x0
  4c8024:	e8 a7 ce 2e 00       	call   0x7b4ed0
  4c8029:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4c8030:	00 
  4c8031:	f3 0f 11 40 0c       	movss  DWORD PTR [eax+0xc],xmm0
  4c8036:	b8 01 00 00 00       	mov    eax,0x1
  4c803b:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4c803f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c8046:	59                   	pop    ecx
  4c8047:	5f                   	pop    edi
  4c8048:	5e                   	pop    esi
  4c8049:	5b                   	pop    ebx
  4c804a:	8b e5                	mov    esp,ebp
  4c804c:	5d                   	pop    ebp
  4c804d:	c2 08 00             	ret    0x8
  4c8050:	6a 00                	push   0x0
  4c8052:	51                   	push   ecx
  4c8053:	e8 98 fd ff ff       	call   0x4c7df0
  4c8058:	c3                   	ret
  4c8059:	cc                   	int3
  4c805a:	cc                   	int3
  4c805b:	cc                   	int3
  4c805c:	cc                   	int3
  4c805d:	cc                   	int3
  4c805e:	cc                   	int3
  4c805f:	cc                   	int3
  4c8060:	55                   	push   ebp
  4c8061:	8b ec                	mov    ebp,esp
  4c8063:	83 e4 f8             	and    esp,0xfffffff8
  4c8066:	6a ff                	push   0xffffffff
  4c8068:	68 03 96 93 00       	push   0x939603
  4c806d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c8073:	50                   	push   eax
  4c8074:	83 ec 10             	sub    esp,0x10
  4c8077:	53                   	push   ebx
  4c8078:	56                   	push   esi
  4c8079:	57                   	push   edi
  4c807a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c807f:	33 c4                	xor    eax,esp
  4c8081:	50                   	push   eax
  4c8082:	8d 44 24 20          	lea    eax,[esp+0x20]
  4c8086:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c808c:	8b f1                	mov    esi,ecx
  4c808e:	33 c0                	xor    eax,eax
  4c8090:	39 86 70 03 00 00    	cmp    DWORD PTR [esi+0x370],eax
  4c8096:	0f 84 89 01 00 00    	je     0x4c8225
  4c809c:	8d be 5c 01 00 00    	lea    edi,[esi+0x15c]
  4c80a2:	89 86 70 03 00 00    	mov    DWORD PTR [esi+0x370],eax
  4c80a8:	8b 5f 04             	mov    ebx,DWORD PTR [edi+0x4]
  4c80ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4c80ae:	89 07                	mov    DWORD PTR [edi],eax
  4c80b0:	3b d8                	cmp    ebx,eax
  4c80b2:	74 29                	je     0x4c80dd
  4c80b4:	8d 43 04             	lea    eax,[ebx+0x4]
  4c80b7:	83 c9 ff             	or     ecx,0xffffffff
  4c80ba:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c80be:	75 1d                	jne    0x4c80dd
  4c80c0:	8b 13                	mov    edx,DWORD PTR [ebx]
  4c80c2:	8b 02                	mov    eax,DWORD PTR [edx]
  4c80c4:	8b cb                	mov    ecx,ebx
  4c80c6:	ff d0                	call   eax
  4c80c8:	8d 4b 08             	lea    ecx,[ebx+0x8]
  4c80cb:	83 ca ff             	or     edx,0xffffffff
  4c80ce:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c80d2:	75 09                	jne    0x4c80dd
  4c80d4:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c80d6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c80d9:	8b cb                	mov    ecx,ebx
  4c80db:	ff d2                	call   edx
  4c80dd:	8b 86 8c 00 00 00    	mov    eax,DWORD PTR [esi+0x8c]
  4c80e3:	8b d8                	mov    ebx,eax
  4c80e5:	85 c0                	test   eax,eax
  4c80e7:	75 06                	jne    0x4c80ef
  4c80e9:	8b 9e 88 00 00 00    	mov    ebx,DWORD PTR [esi+0x88]
  4c80ef:	68 70 01 00 00       	push   0x170
  4c80f4:	e8 6f 91 3c 00       	call   0x891268
  4c80f9:	83 c4 04             	add    esp,0x4
  4c80fc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c8100:	33 c9                	xor    ecx,ecx
  4c8102:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  4c8106:	3b c1                	cmp    eax,ecx
  4c8108:	74 0e                	je     0x4c8118
  4c810a:	0f b7 cb             	movzx  ecx,bx
  4c810d:	51                   	push   ecx
  4c810e:	50                   	push   eax
  4c810f:	e8 3c cb 2d 00       	call   0x7a4c50
  4c8114:	33 c9                	xor    ecx,ecx
  4c8116:	eb 02                	jmp    0x4c811a
  4c8118:	33 c0                	xor    eax,eax
  4c811a:	50                   	push   eax
  4c811b:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c811f:	83 cb ff             	or     ebx,0xffffffff
  4c8122:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  4c8126:	52                   	push   edx
  4c8127:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4c812b:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  4c812f:	e8 2c 23 00 00       	call   0x4ca460
  4c8134:	8d 44 24 14          	lea    eax,[esp+0x14]
  4c8138:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  4c813f:	00 
  4c8140:	e8 1b 8e 01 00       	call   0x4e0f60
  4c8145:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4c8149:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  4c814d:	85 db                	test   ebx,ebx
  4c814f:	74 29                	je     0x4c817a
  4c8151:	8d 43 04             	lea    eax,[ebx+0x4]
  4c8154:	83 c9 ff             	or     ecx,0xffffffff
  4c8157:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c815b:	75 1d                	jne    0x4c817a
  4c815d:	8b 13                	mov    edx,DWORD PTR [ebx]
  4c815f:	8b 02                	mov    eax,DWORD PTR [edx]
  4c8161:	8b cb                	mov    ecx,ebx
  4c8163:	ff d0                	call   eax
  4c8165:	8d 4b 08             	lea    ecx,[ebx+0x8]
  4c8168:	83 ca ff             	or     edx,0xffffffff
  4c816b:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c816f:	75 09                	jne    0x4c817a
  4c8171:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c8173:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c8176:	8b cb                	mov    ecx,ebx
  4c8178:	ff d2                	call   edx
  4c817a:	0f b7 86 88 03 00 00 	movzx  eax,WORD PTR [esi+0x388]
  4c8181:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4c8183:	50                   	push   eax
  4c8184:	6a 01                	push   0x1
  4c8186:	51                   	push   ecx
  4c8187:	e8 14 ed 2d 00       	call   0x7a6ea0
  4c818c:	8b 16                	mov    edx,DWORD PTR [esi]
  4c818e:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4c8191:	6a 01                	push   0x1
  4c8193:	8d 86 a0 00 00 00    	lea    eax,[esi+0xa0]
  4c8199:	50                   	push   eax
  4c819a:	8b ce                	mov    ecx,esi
  4c819c:	c7 86 70 03 00 00 01 	mov    DWORD PTR [esi+0x370],0x1
  4c81a3:	00 00 00 
  4c81a6:	ff d2                	call   edx
  4c81a8:	0f b6 8e b0 00 00 00 	movzx  ecx,BYTE PTR [esi+0xb0]
  4c81af:	8b 06                	mov    eax,DWORD PTR [esi]
  4c81b1:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4c81b4:	51                   	push   ecx
  4c81b5:	8b ce                	mov    ecx,esi
  4c81b7:	ff d2                	call   edx
  4c81b9:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c81c0:	8a 86 b0 00 00 00    	mov    al,BYTE PTR [esi+0xb0]
  4c81c6:	88 44 24 14          	mov    BYTE PTR [esp+0x14],al
  4c81ca:	75 30                	jne    0x4c81fc
  4c81cc:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c81d3:	88 86 a4 03 00 00    	mov    BYTE PTR [esi+0x3a4],al
  4c81d9:	74 21                	je     0x4c81fc
  4c81db:	8b 3f                	mov    edi,DWORD PTR [edi]
  4c81dd:	85 ff                	test   edi,edi
  4c81df:	74 1b                	je     0x4c81fc
  4c81e1:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4c81e5:	8d 5f 04             	lea    ebx,[edi+0x4]
  4c81e8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4c81ea:	50                   	push   eax
  4c81eb:	e8 a0 c8 f7 ff       	call   0x444a90
  4c81f0:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  4c81f3:	8b cb                	mov    ecx,ebx
  4c81f5:	f3 0f 11 04 24       	movss  DWORD PTR [esp],xmm0
  4c81fa:	ff d2                	call   edx
  4c81fc:	8b 06                	mov    eax,DWORD PTR [esi]
  4c81fe:	d9 86 b4 00 00 00    	fld    DWORD PTR [esi+0xb4]
  4c8204:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4c8207:	51                   	push   ecx
  4c8208:	8b ce                	mov    ecx,esi
  4c820a:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c820d:	ff d2                	call   edx
  4c820f:	d9 e8                	fld1
  4c8211:	8b 06                	mov    eax,DWORD PTR [esi]
  4c8213:	8b 50 68             	mov    edx,DWORD PTR [eax+0x68]
  4c8216:	51                   	push   ecx
  4c8217:	8b 8e 8c 03 00 00    	mov    ecx,DWORD PTR [esi+0x38c]
  4c821d:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c8220:	51                   	push   ecx
  4c8221:	8b ce                	mov    ecx,esi
  4c8223:	ff d2                	call   edx
  4c8225:	b8 01 00 00 00       	mov    eax,0x1
  4c822a:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4c822e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c8235:	59                   	pop    ecx
  4c8236:	5f                   	pop    edi
  4c8237:	5e                   	pop    esi
  4c8238:	5b                   	pop    ebx
  4c8239:	8b e5                	mov    esp,ebp
  4c823b:	5d                   	pop    ebp
  4c823c:	c3                   	ret
  4c823d:	cc                   	int3
  4c823e:	cc                   	int3
  4c823f:	cc                   	int3
```

### 201-2 pair搬移與舊control釋放完整code：`0x004E0F60..0x004E0FC0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e0f60 <.text+0xdff60>:
  4e0f60:	55                   	push   ebp
  4e0f61:	8b ec                	mov    ebp,esp
  4e0f63:	83 ec 0c             	sub    esp,0xc
  4e0f66:	56                   	push   esi
  4e0f67:	8d 75 f8             	lea    esi,[ebp-0x8]
  4e0f6a:	33 d2                	xor    edx,edx
  4e0f6c:	33 c9                	xor    ecx,ecx
  4e0f6e:	3b f0                	cmp    esi,eax
  4e0f70:	74 0e                	je     0x4e0f80
  4e0f72:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4e0f75:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4e0f78:	8b 10                	mov    edx,DWORD PTR [eax]
  4e0f7a:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  4e0f80:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  4e0f83:	89 4f 04             	mov    DWORD PTR [edi+0x4],ecx
  4e0f86:	89 17                	mov    DWORD PTR [edi],edx
  4e0f88:	85 f6                	test   esi,esi
  4e0f8a:	74 29                	je     0x4e0fb5
  4e0f8c:	8d 46 04             	lea    eax,[esi+0x4]
  4e0f8f:	83 c9 ff             	or     ecx,0xffffffff
  4e0f92:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4e0f96:	75 1d                	jne    0x4e0fb5
  4e0f98:	8b 16                	mov    edx,DWORD PTR [esi]
  4e0f9a:	8b 02                	mov    eax,DWORD PTR [edx]
  4e0f9c:	8b ce                	mov    ecx,esi
  4e0f9e:	ff d0                	call   eax
  4e0fa0:	8d 4e 08             	lea    ecx,[esi+0x8]
  4e0fa3:	83 ca ff             	or     edx,0xffffffff
  4e0fa6:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4e0faa:	75 09                	jne    0x4e0fb5
  4e0fac:	8b 06                	mov    eax,DWORD PTR [esi]
  4e0fae:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4e0fb1:	8b ce                	mov    ecx,esi
  4e0fb3:	ff d2                	call   edx
  4e0fb5:	8b c7                	mov    eax,edi
  4e0fb7:	5e                   	pop    esi
  4e0fb8:	8b e5                	mov    esp,ebp
  4e0fba:	5d                   	pop    ebp
  4e0fbb:	c3                   	ret
  4e0fbc:	cc                   	int3
  4e0fbd:	cc                   	int3
  4e0fbe:	cc                   	int3
  4e0fbf:	cc                   	int3
```

### 201-2 CDoll ctor完整code含失敗分支：`0x007A4C50..0x007A4FF0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a4c50 <.text+0x3a3c50>:
  7a4c50:	55                   	push   ebp
  7a4c51:	8b ec                	mov    ebp,esp
  7a4c53:	6a ff                	push   0xffffffff
  7a4c55:	68 63 79 90 00       	push   0x907963
  7a4c5a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7a4c60:	50                   	push   eax
  7a4c61:	83 ec 1c             	sub    esp,0x1c
  7a4c64:	53                   	push   ebx
  7a4c65:	56                   	push   esi
  7a4c66:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a4c6b:	33 c5                	xor    eax,ebp
  7a4c6d:	50                   	push   eax
  7a4c6e:	8d 45 f4             	lea    eax,[ebp-0xc]
  7a4c71:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7a4c77:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  7a4c7a:	33 db                	xor    ebx,ebx
  7a4c7c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7a4c7f:	c7 46 04 4c f6 c4 00 	mov    DWORD PTR [esi+0x4],0xc4f64c
  7a4c86:	c7 46 08 78 f8 c0 00 	mov    DWORD PTR [esi+0x8],0xc0f878
  7a4c8d:	c7 46 0c 6c f6 c4 00 	mov    DWORD PTR [esi+0xc],0xc4f66c
  7a4c94:	89 5e 10             	mov    DWORD PTR [esi+0x10],ebx
  7a4c97:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  7a4c9a:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  7a4c9e:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7a4ca1:	8d 4e 2c             	lea    ecx,[esi+0x2c]
  7a4ca4:	51                   	push   ecx
  7a4ca5:	c7 06 7c f6 c4 00    	mov    DWORD PTR [esi],0xc4f67c
  7a4cab:	c7 46 04 90 f6 c4 00 	mov    DWORD PTR [esi+0x4],0xc4f690
  7a4cb2:	c7 46 08 b0 f6 c4 00 	mov    DWORD PTR [esi+0x8],0xc4f6b0
  7a4cb9:	c7 46 0c c0 f6 c4 00 	mov    DWORD PTR [esi+0xc],0xc4f6c0
  7a4cc0:	89 46 18             	mov    DWORD PTR [esi+0x18],eax
  7a4cc3:	89 5e 1c             	mov    DWORD PTR [esi+0x1c],ebx
  7a4cc6:	88 5e 20             	mov    BYTE PTR [esi+0x20],bl
  7a4cc9:	89 5e 24             	mov    DWORD PTR [esi+0x24],ebx
  7a4ccc:	c6 46 28 01          	mov    BYTE PTR [esi+0x28],0x1
  7a4cd0:	e8 4b 03 00 00       	call   0x7a5020
  7a4cd5:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  7a4cd9:	6a 14                	push   0x14
  7a4cdb:	89 5e 54             	mov    DWORD PTR [esi+0x54],ebx
  7a4cde:	e8 85 c5 0e 00       	call   0x891268
  7a4ce3:	83 c4 04             	add    esp,0x4
  7a4ce6:	3b c3                	cmp    eax,ebx
  7a4ce8:	0f 84 cf 02 00 00    	je     0x7a4fbd
  7a4cee:	89 46 50             	mov    DWORD PTR [esi+0x50],eax
  7a4cf1:	89 00                	mov    DWORD PTR [eax],eax
  7a4cf3:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  7a4cf6:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7a4cf9:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  7a4cfc:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  7a4cff:	8b 56 50             	mov    edx,DWORD PTR [esi+0x50]
  7a4d02:	c6 42 10 01          	mov    BYTE PTR [edx+0x10],0x1
  7a4d06:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  7a4d09:	c6 40 11 01          	mov    BYTE PTR [eax+0x11],0x1
  7a4d0d:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  7a4d11:	6a 28                	push   0x28
  7a4d13:	89 5e 64             	mov    DWORD PTR [esi+0x64],ebx
  7a4d16:	e8 4d c5 0e 00       	call   0x891268
  7a4d1b:	83 c4 04             	add    esp,0x4
  7a4d1e:	3b c3                	cmp    eax,ebx
  7a4d20:	0f 84 2b 02 00 00    	je     0x7a4f51
  7a4d26:	89 46 60             	mov    DWORD PTR [esi+0x60],eax
  7a4d29:	89 00                	mov    DWORD PTR [eax],eax
  7a4d2b:	8b 46 60             	mov    eax,DWORD PTR [esi+0x60]
  7a4d2e:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7a4d31:	8b 46 60             	mov    eax,DWORD PTR [esi+0x60]
  7a4d34:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  7a4d37:	8b 4e 60             	mov    ecx,DWORD PTR [esi+0x60]
  7a4d3a:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  7a4d3e:	8b 56 60             	mov    edx,DWORD PTR [esi+0x60]
  7a4d41:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  7a4d45:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  7a4d49:	6a 28                	push   0x28
  7a4d4b:	89 5e 74             	mov    DWORD PTR [esi+0x74],ebx
  7a4d4e:	e8 15 c5 0e 00       	call   0x891268
  7a4d53:	83 c4 04             	add    esp,0x4
  7a4d56:	3b c3                	cmp    eax,ebx
  7a4d58:	0f 84 3b 02 00 00    	je     0x7a4f99
  7a4d5e:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  7a4d61:	89 00                	mov    DWORD PTR [eax],eax
  7a4d63:	8b 46 70             	mov    eax,DWORD PTR [esi+0x70]
  7a4d66:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7a4d69:	8b 46 70             	mov    eax,DWORD PTR [esi+0x70]
  7a4d6c:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  7a4d6f:	8b 46 70             	mov    eax,DWORD PTR [esi+0x70]
  7a4d72:	c6 40 20 01          	mov    BYTE PTR [eax+0x20],0x1
  7a4d76:	8b 4e 70             	mov    ecx,DWORD PTR [esi+0x70]
  7a4d79:	c6 41 21 01          	mov    BYTE PTR [ecx+0x21],0x1
  7a4d7d:	c6 45 fc 08          	mov    BYTE PTR [ebp-0x4],0x8
  7a4d81:	6a 18                	push   0x18
  7a4d83:	89 9e 84 00 00 00    	mov    DWORD PTR [esi+0x84],ebx
  7a4d89:	e8 da c4 0e 00       	call   0x891268
  7a4d8e:	83 c4 04             	add    esp,0x4
  7a4d91:	3b c3                	cmp    eax,ebx
  7a4d93:	0f 84 dc 01 00 00    	je     0x7a4f75
  7a4d99:	89 86 80 00 00 00    	mov    DWORD PTR [esi+0x80],eax
  7a4d9f:	89 00                	mov    DWORD PTR [eax],eax
  7a4da1:	8b 86 80 00 00 00    	mov    eax,DWORD PTR [esi+0x80]
  7a4da7:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7a4daa:	8b 86 80 00 00 00    	mov    eax,DWORD PTR [esi+0x80]
  7a4db0:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  7a4db3:	8b 96 80 00 00 00    	mov    edx,DWORD PTR [esi+0x80]
  7a4db9:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  7a4dbd:	8b 86 80 00 00 00    	mov    eax,DWORD PTR [esi+0x80]
  7a4dc3:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  7a4dc7:	c7 86 8c 00 00 00 01 	mov    DWORD PTR [esi+0x8c],0x1
  7a4dce:	00 00 00 
  7a4dd1:	89 9e 90 00 00 00    	mov    DWORD PTR [esi+0x90],ebx
  7a4dd7:	89 9e 94 00 00 00    	mov    DWORD PTR [esi+0x94],ebx
  7a4ddd:	89 9e 98 00 00 00    	mov    DWORD PTR [esi+0x98],ebx
  7a4de3:	c6 45 fc 0a          	mov    BYTE PTR [ebp-0x4],0xa
  7a4de7:	d9 ee                	fldz
  7a4de9:	89 9e a0 00 00 00    	mov    DWORD PTR [esi+0xa0],ebx
  7a4def:	89 9e a4 00 00 00    	mov    DWORD PTR [esi+0xa4],ebx
  7a4df5:	c7 86 a8 00 00 00 02 	mov    DWORD PTR [esi+0xa8],0x2
  7a4dfc:	00 00 00 
  7a4dff:	89 9e ac 00 00 00    	mov    DWORD PTR [esi+0xac],ebx
  7a4e05:	89 9e b0 00 00 00    	mov    DWORD PTR [esi+0xb0],ebx
  7a4e0b:	d9 96 b4 00 00 00    	fst    DWORD PTR [esi+0xb4]
  7a4e11:	d9 e8                	fld1
  7a4e13:	89 9e c4 00 00 00    	mov    DWORD PTR [esi+0xc4],ebx
  7a4e19:	d9 96 b8 00 00 00    	fst    DWORD PTR [esi+0xb8]
  7a4e1f:	89 9e c8 00 00 00    	mov    DWORD PTR [esi+0xc8],ebx
  7a4e25:	d9 96 c0 00 00 00    	fst    DWORD PTR [esi+0xc0]
  7a4e2b:	89 9e cc 00 00 00    	mov    DWORD PTR [esi+0xcc],ebx
  7a4e31:	d9 c9                	fxch   st(1)
  7a4e33:	c7 86 e8 00 00 00 01 	mov    DWORD PTR [esi+0xe8],0x1
  7a4e3a:	00 00 00 
  7a4e3d:	d9 96 bc 00 00 00    	fst    DWORD PTR [esi+0xbc]
  7a4e43:	6a 10                	push   0x10
  7a4e45:	d9 96 d8 00 00 00    	fst    DWORD PTR [esi+0xd8]
  7a4e4b:	d9 96 dc 00 00 00    	fst    DWORD PTR [esi+0xdc]
  7a4e51:	d9 96 e0 00 00 00    	fst    DWORD PTR [esi+0xe0]
  7a4e57:	d9 c9                	fxch   st(1)
  7a4e59:	d9 96 e4 00 00 00    	fst    DWORD PTR [esi+0xe4]
  7a4e5f:	d9 c9                	fxch   st(1)
  7a4e61:	d9 96 ec 00 00 00    	fst    DWORD PTR [esi+0xec]
  7a4e67:	d9 96 f0 00 00 00    	fst    DWORD PTR [esi+0xf0]
  7a4e6d:	d9 96 f4 00 00 00    	fst    DWORD PTR [esi+0xf4]
  7a4e73:	d9 9e fc 00 00 00    	fstp   DWORD PTR [esi+0xfc]
  7a4e79:	89 9e 00 01 00 00    	mov    DWORD PTR [esi+0x100],ebx
  7a4e7f:	89 9e 08 01 00 00    	mov    DWORD PTR [esi+0x108],ebx
  7a4e85:	d9 96 f8 00 00 00    	fst    DWORD PTR [esi+0xf8]
  7a4e8b:	d9 9e 04 01 00 00    	fstp   DWORD PTR [esi+0x104]
  7a4e91:	89 9e 10 01 00 00    	mov    DWORD PTR [esi+0x110],ebx
  7a4e97:	e8 cc c3 0e 00       	call   0x891268
  7a4e9c:	83 c4 04             	add    esp,0x4
  7a4e9f:	3b c3                	cmp    eax,ebx
  7a4ea1:	0f 84 aa 00 00 00    	je     0x7a4f51
  7a4ea7:	d9 05 a4 5a c5 00    	fld    DWORD PTR ds:0xc55aa4
  7a4ead:	89 86 0c 01 00 00    	mov    DWORD PTR [esi+0x10c],eax
  7a4eb3:	89 00                	mov    DWORD PTR [eax],eax
  7a4eb5:	8b 86 0c 01 00 00    	mov    eax,DWORD PTR [esi+0x10c]
  7a4ebb:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7a4ebe:	89 9e 18 01 00 00    	mov    DWORD PTR [esi+0x118],ebx
  7a4ec4:	89 9e 1c 01 00 00    	mov    DWORD PTR [esi+0x11c],ebx
  7a4eca:	89 9e 20 01 00 00    	mov    DWORD PTR [esi+0x120],ebx
  7a4ed0:	89 9e 24 01 00 00    	mov    DWORD PTR [esi+0x124],ebx
  7a4ed6:	89 9e 28 01 00 00    	mov    DWORD PTR [esi+0x128],ebx
  7a4edc:	d9 96 2c 01 00 00    	fst    DWORD PTR [esi+0x12c]
  7a4ee2:	d9 96 30 01 00 00    	fst    DWORD PTR [esi+0x130]
  7a4ee8:	8b c6                	mov    eax,esi
  7a4eea:	d9 9e 34 01 00 00    	fstp   DWORD PTR [esi+0x134]
  7a4ef0:	d9 e8                	fld1
  7a4ef2:	d9 9e 38 01 00 00    	fstp   DWORD PTR [esi+0x138]
  7a4ef8:	c7 86 3c 01 00 00 01 	mov    DWORD PTR [esi+0x13c],0x1
  7a4eff:	00 00 00 
  7a4f02:	89 9e 40 01 00 00    	mov    DWORD PTR [esi+0x140],ebx
  7a4f08:	89 9e 44 01 00 00    	mov    DWORD PTR [esi+0x144],ebx
  7a4f0e:	89 9e 48 01 00 00    	mov    DWORD PTR [esi+0x148],ebx
  7a4f14:	89 9e 4c 01 00 00    	mov    DWORD PTR [esi+0x14c],ebx
  7a4f1a:	89 9e 50 01 00 00    	mov    DWORD PTR [esi+0x150],ebx
  7a4f20:	89 9e 54 01 00 00    	mov    DWORD PTR [esi+0x154],ebx
  7a4f26:	89 9e 5c 01 00 00    	mov    DWORD PTR [esi+0x15c],ebx
  7a4f2c:	89 9e 60 01 00 00    	mov    DWORD PTR [esi+0x160],ebx
  7a4f32:	89 9e 64 01 00 00    	mov    DWORD PTR [esi+0x164],ebx
  7a4f38:	89 9e 68 01 00 00    	mov    DWORD PTR [esi+0x168],ebx
  7a4f3e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7a4f41:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7a4f48:	59                   	pop    ecx
  7a4f49:	5e                   	pop    esi
  7a4f4a:	5b                   	pop    ebx
  7a4f4b:	8b e5                	mov    esp,ebp
  7a4f4d:	5d                   	pop    ebp
  7a4f4e:	c2 08 00             	ret    0x8
  7a4f51:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  7a4f54:	51                   	push   ecx
  7a4f55:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  7a4f58:	89 5d 0c             	mov    DWORD PTR [ebp+0xc],ebx
  7a4f5b:	e8 49 c1 0e 00       	call   0x8910a9
  7a4f60:	68 a8 57 c8 00       	push   0xc857a8
  7a4f65:	8d 55 e4             	lea    edx,[ebp-0x1c]
  7a4f68:	52                   	push   edx
  7a4f69:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  7a4f70:	e8 7b 7a 0f 00       	call   0x89c9f0
  7a4f75:	8d 45 0c             	lea    eax,[ebp+0xc]
  7a4f78:	50                   	push   eax
  7a4f79:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  7a4f7c:	89 5d 0c             	mov    DWORD PTR [ebp+0xc],ebx
  7a4f7f:	e8 25 c1 0e 00       	call   0x8910a9
  7a4f84:	68 a8 57 c8 00       	push   0xc857a8
  7a4f89:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  7a4f8c:	51                   	push   ecx
  7a4f8d:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  7a4f94:	e8 57 7a 0f 00       	call   0x89c9f0
  7a4f99:	8d 55 f0             	lea    edx,[ebp-0x10]
  7a4f9c:	52                   	push   edx
  7a4f9d:	8d 4d d8             	lea    ecx,[ebp-0x28]
  7a4fa0:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  7a4fa3:	e8 01 c1 0e 00       	call   0x8910a9
  7a4fa8:	68 a8 57 c8 00       	push   0xc857a8
  7a4fad:	8d 45 d8             	lea    eax,[ebp-0x28]
  7a4fb0:	50                   	push   eax
  7a4fb1:	c7 45 d8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x28],0xbd2ca4
  7a4fb8:	e8 33 7a 0f 00       	call   0x89c9f0
  7a4fbd:	8d 45 f0             	lea    eax,[ebp-0x10]
  7a4fc0:	50                   	push   eax
  7a4fc1:	8d 4d d8             	lea    ecx,[ebp-0x28]
  7a4fc4:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  7a4fc7:	e8 dd c0 0e 00       	call   0x8910a9
  7a4fcc:	68 a8 57 c8 00       	push   0xc857a8
  7a4fd1:	8d 4d d8             	lea    ecx,[ebp-0x28]
  7a4fd4:	51                   	push   ecx
  7a4fd5:	c7 45 d8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x28],0xbd2ca4
  7a4fdc:	e8 0f 7a 0f 00       	call   0x89c9f0
  7a4fe1:	cc                   	int3
  7a4fe2:	cc                   	int3
  7a4fe3:	cc                   	int3
  7a4fe4:	cc                   	int3
  7a4fe5:	cc                   	int3
  7a4fe6:	cc                   	int3
  7a4fe7:	cc                   	int3
  7a4fe8:	cc                   	int3
  7a4fe9:	cc                   	int3
  7a4fea:	cc                   	int3
  7a4feb:	cc                   	int3
  7a4fec:	cc                   	int3
  7a4fed:	cc                   	int3
  7a4fee:	cc                   	int3
  7a4fef:	cc                   	int3
```

### 201-2 CDoll deleting destructor：`0x007A4FF0..0x007A5020`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a4ff0 <.text+0x3a3ff0>:
  7a4ff0:	55                   	push   ebp
  7a4ff1:	8b ec                	mov    ebp,esp
  7a4ff3:	56                   	push   esi
  7a4ff4:	8b f1                	mov    esi,ecx
  7a4ff6:	56                   	push   esi
  7a4ff7:	e8 c4 01 00 00       	call   0x7a51c0
  7a4ffc:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  7a5000:	74 09                	je     0x7a500b
  7a5002:	56                   	push   esi
  7a5003:	e8 04 c2 0e 00       	call   0x89120c
  7a5008:	83 c4 04             	add    esp,0x4
  7a500b:	8b c6                	mov    eax,esi
  7a500d:	5e                   	pop    esi
  7a500e:	5d                   	pop    ebp
  7a500f:	c2 04 00             	ret    0x4
  7a5012:	cc                   	int3
  7a5013:	cc                   	int3
  7a5014:	cc                   	int3
  7a5015:	cc                   	int3
  7a5016:	cc                   	int3
  7a5017:	cc                   	int3
  7a5018:	cc                   	int3
  7a5019:	cc                   	int3
  7a501a:	cc                   	int3
  7a501b:	cc                   	int3
  7a501c:	cc                   	int3
  7a501d:	cc                   	int3
  7a501e:	cc                   	int3
  7a501f:	cc                   	int3
```

### 201-2 CDoll destructor完整code：`0x007A51C0..0x007A5680`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a51c0 <.text+0x3a41c0>:
  7a51c0:	55                   	push   ebp
  7a51c1:	8b ec                	mov    ebp,esp
  7a51c3:	6a ff                	push   0xffffffff
  7a51c5:	68 c6 92 93 00       	push   0x9392c6
  7a51ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7a51d0:	50                   	push   eax
  7a51d1:	83 ec 10             	sub    esp,0x10
  7a51d4:	53                   	push   ebx
  7a51d5:	56                   	push   esi
  7a51d6:	57                   	push   edi
  7a51d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a51dc:	33 c5                	xor    eax,ebp
  7a51de:	50                   	push   eax
  7a51df:	8d 45 f4             	lea    eax,[ebp-0xc]
  7a51e2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7a51e8:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7a51eb:	c7 03 7c f6 c4 00    	mov    DWORD PTR [ebx],0xc4f67c
  7a51f1:	c7 43 04 90 f6 c4 00 	mov    DWORD PTR [ebx+0x4],0xc4f690
  7a51f8:	c7 43 08 b0 f6 c4 00 	mov    DWORD PTR [ebx+0x8],0xc4f6b0
  7a51ff:	c7 43 0c c0 f6 c4 00 	mov    DWORD PTR [ebx+0xc],0xc4f6c0
  7a5206:	c7 45 fc 0d 00 00 00 	mov    DWORD PTR [ebp-0x4],0xd
  7a520d:	83 7b 24 01          	cmp    DWORD PTR [ebx+0x24],0x1
  7a5211:	0f 85 44 01 00 00    	jne    0x7a535b
  7a5217:	6a 38                	push   0x38
  7a5219:	e8 4a c0 0e 00       	call   0x891268
  7a521e:	83 c4 04             	add    esp,0x4
  7a5221:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  7a5224:	33 f6                	xor    esi,esi
  7a5226:	c6 45 fc 0e          	mov    BYTE PTR [ebp-0x4],0xe
  7a522a:	3b c6                	cmp    eax,esi
  7a522c:	74 08                	je     0x7a5236
  7a522e:	50                   	push   eax
  7a522f:	e8 4c 04 00 00       	call   0x7a5680
  7a5234:	eb 02                	jmp    0x7a5238
  7a5236:	33 c0                	xor    eax,eax
  7a5238:	50                   	push   eax
  7a5239:	8d 45 e8             	lea    eax,[ebp-0x18]
  7a523c:	c6 45 fc 0d          	mov    BYTE PTR [ebp-0x4],0xd
  7a5240:	50                   	push   eax
  7a5241:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  7a5244:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  7a5247:	e8 34 55 00 00       	call   0x7aa780
  7a524c:	c6 45 fc 0f          	mov    BYTE PTR [ebp-0x4],0xf
  7a5250:	8b 75 e8             	mov    esi,DWORD PTR [ebp-0x18]
  7a5253:	8b 4b 18             	mov    ecx,DWORD PTR [ebx+0x18]
  7a5256:	8d 53 2c             	lea    edx,[ebx+0x2c]
  7a5259:	52                   	push   edx
  7a525a:	8d 7e 08             	lea    edi,[esi+0x8]
  7a525d:	89 0e                	mov    DWORD PTR [esi],ecx
  7a525f:	e8 cc 04 00 00       	call   0x7a5730
  7a5264:	8b 43 1c             	mov    eax,DWORD PTR [ebx+0x1c]
  7a5267:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  7a526a:	8d 43 6c             	lea    eax,[ebx+0x6c]
  7a526d:	8d 7e 28             	lea    edi,[esi+0x28]
  7a5270:	3b f8                	cmp    edi,eax
  7a5272:	74 1f                	je     0x7a5293
  7a5274:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a5277:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a5279:	50                   	push   eax
  7a527a:	51                   	push   ecx
  7a527b:	8d 75 e4             	lea    esi,[ebp-0x1c]
  7a527e:	8b c7                	mov    eax,edi
  7a5280:	e8 9b 1e f3 ff       	call   0x6d7120
  7a5285:	8d 43 6c             	lea    eax,[ebx+0x6c]
  7a5288:	50                   	push   eax
  7a5289:	8b c7                	mov    eax,edi
  7a528b:	e8 c0 4e 00 00       	call   0x7aa150
  7a5290:	8b 75 e8             	mov    esi,DWORD PTR [ebp-0x18]
  7a5293:	8d 7b 6c             	lea    edi,[ebx+0x6c]
  7a5296:	c7 43 1c 00 00 00 00 	mov    DWORD PTR [ebx+0x1c],0x0
  7a529d:	e8 ce 28 df ff       	call   0x597b70
  7a52a2:	8b 83 a0 00 00 00    	mov    eax,DWORD PTR [ebx+0xa0]
  7a52a8:	33 ff                	xor    edi,edi
  7a52aa:	3b c7                	cmp    eax,edi
  7a52ac:	74 14                	je     0x7a52c2
  7a52ae:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a52b0:	ff 49 2c             	dec    DWORD PTR [ecx+0x2c]
  7a52b3:	50                   	push   eax
  7a52b4:	e8 53 bf 0e 00       	call   0x89120c
  7a52b9:	83 c4 04             	add    esp,0x4
  7a52bc:	89 bb a0 00 00 00    	mov    DWORD PTR [ebx+0xa0],edi
  7a52c2:	83 ec 08             	sub    esp,0x8
  7a52c5:	8b c4                	mov    eax,esp
  7a52c7:	89 38                	mov    DWORD PTR [eax],edi
  7a52c9:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7a52cc:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  7a52cf:	89 65 e4             	mov    DWORD PTR [ebp-0x1c],esp
  7a52d2:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7a52d5:	85 ff                	test   edi,edi
  7a52d7:	74 15                	je     0x7a52ee
  7a52d9:	8b d7                	mov    edx,edi
  7a52db:	e8 70 6f cd ff       	call   0x47c250
  7a52e0:	84 c0                	test   al,al
  7a52e2:	74 0a                	je     0x7a52ee
  7a52e4:	57                   	push   edi
  7a52e5:	56                   	push   esi
  7a52e6:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  7a52e9:	e8 d2 de ff ff       	call   0x7a31c0
  7a52ee:	c6 45 fc 10          	mov    BYTE PTR [ebp-0x4],0x10
  7a52f2:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  7a52f9:	75 21                	jne    0x7a531c
  7a52fb:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  7a5302:	c6 45 fc 11          	mov    BYTE PTR [ebp-0x4],0x11
  7a5306:	e8 35 7c ff ff       	call   0x79cf40
  7a530b:	68 80 db bc 00       	push   0xbcdb80
  7a5310:	e8 05 d0 0e 00       	call   0x89231a
  7a5315:	83 c4 04             	add    esp,0x4
  7a5318:	c6 45 fc 10          	mov    BYTE PTR [ebp-0x4],0x10
  7a531c:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  7a5321:	c6 45 fc 0f          	mov    BYTE PTR [ebp-0x4],0xf
  7a5325:	e8 d6 8a ff ff       	call   0x79de00
  7a532a:	c6 45 fc 0d          	mov    BYTE PTR [ebp-0x4],0xd
  7a532e:	85 ff                	test   edi,edi
  7a5330:	74 29                	je     0x7a535b
  7a5332:	8d 4f 04             	lea    ecx,[edi+0x4]
  7a5335:	83 ca ff             	or     edx,0xffffffff
  7a5338:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  7a533c:	75 1d                	jne    0x7a535b
  7a533e:	8b 07                	mov    eax,DWORD PTR [edi]
  7a5340:	8b 10                	mov    edx,DWORD PTR [eax]
  7a5342:	8b cf                	mov    ecx,edi
  7a5344:	ff d2                	call   edx
  7a5346:	8d 47 08             	lea    eax,[edi+0x8]
  7a5349:	83 c9 ff             	or     ecx,0xffffffff
  7a534c:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  7a5350:	75 09                	jne    0x7a535b
  7a5352:	8b 17                	mov    edx,DWORD PTR [edi]
  7a5354:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7a5357:	8b cf                	mov    ecx,edi
  7a5359:	ff d0                	call   eax
  7a535b:	8d b3 08 01 00 00    	lea    esi,[ebx+0x108]
  7a5361:	e8 8a 92 01 00       	call   0x7be5f0
  7a5366:	8b 8b 20 01 00 00    	mov    ecx,DWORD PTR [ebx+0x120]
  7a536c:	85 c9                	test   ecx,ecx
  7a536e:	74 1e                	je     0x7a538e
  7a5370:	8b 11                	mov    edx,DWORD PTR [ecx]
  7a5372:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a5375:	ff d0                	call   eax
  7a5377:	8b 8b 20 01 00 00    	mov    ecx,DWORD PTR [ebx+0x120]
  7a537d:	8b 11                	mov    edx,DWORD PTR [ecx]
  7a537f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  7a5382:	ff d0                	call   eax
  7a5384:	c7 83 20 01 00 00 00 	mov    DWORD PTR [ebx+0x120],0x0
  7a538b:	00 00 00 
  7a538e:	8b 83 0c 01 00 00    	mov    eax,DWORD PTR [ebx+0x10c]
  7a5394:	8b 30                	mov    esi,DWORD PTR [eax]
  7a5396:	3b f0                	cmp    esi,eax
  7a5398:	0f 84 b6 00 00 00    	je     0x7a5454
  7a539e:	8b ff                	mov    edi,edi
  7a53a0:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  7a53a3:	85 ff                	test   edi,edi
  7a53a5:	74 60                	je     0x7a5407
  7a53a7:	8b 07                	mov    eax,DWORD PTR [edi]
  7a53a9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7a53ac:	8b 47 74             	mov    eax,DWORD PTR [edi+0x74]
  7a53af:	85 c0                	test   eax,eax
  7a53b1:	74 3b                	je     0x7a53ee
  7a53b3:	83 7f 78 00          	cmp    DWORD PTR [edi+0x78],0x0
  7a53b7:	74 35                	je     0x7a53ee
  7a53b9:	8b 07                	mov    eax,DWORD PTR [edi]
  7a53bb:	83 78 44 01          	cmp    DWORD PTR [eax+0x44],0x1
  7a53bf:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  7a53c2:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7a53c5:	7c 32                	jl     0x7a53f9
  7a53c7:	83 c0 64             	add    eax,0x64
  7a53ca:	50                   	push   eax
  7a53cb:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  7a53ce:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7a53d4:	8b 7d f0             	mov    edi,DWORD PTR [ebp-0x10]
  7a53d7:	83 c7 7c             	add    edi,0x7c
  7a53da:	8d 45 ec             	lea    eax,[ebp-0x14]
  7a53dd:	e8 6e 5f 01 00       	call   0x7bb350
  7a53e2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  7a53e5:	51                   	push   ecx
  7a53e6:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7a53ec:	eb 19                	jmp    0x7a5407
  7a53ee:	83 f8 01             	cmp    eax,0x1
  7a53f1:	7c 06                	jl     0x7a53f9
  7a53f3:	57                   	push   edi
  7a53f4:	e8 f7 8c 01 00       	call   0x7be0f0
  7a53f9:	e8 52 84 01 00       	call   0x7bd850
  7a53fe:	57                   	push   edi
  7a53ff:	e8 08 be 0e 00       	call   0x89120c
  7a5404:	83 c4 04             	add    esp,0x4
  7a5407:	8b 7e 0c             	mov    edi,DWORD PTR [esi+0xc]
  7a540a:	85 ff                	test   edi,edi
  7a540c:	74 12                	je     0x7a5420
  7a540e:	8b 17                	mov    edx,DWORD PTR [edi]
  7a5410:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a5413:	8b cf                	mov    ecx,edi
  7a5415:	ff d0                	call   eax
  7a5417:	8b 17                	mov    edx,DWORD PTR [edi]
  7a5419:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  7a541c:	8b cf                	mov    ecx,edi
  7a541e:	ff d0                	call   eax
  7a5420:	8b 3e                	mov    edi,DWORD PTR [esi]
  7a5422:	3b b3 0c 01 00 00    	cmp    esi,DWORD PTR [ebx+0x10c]
  7a5428:	74 1c                	je     0x7a5446
  7a542a:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7a542d:	89 38                	mov    DWORD PTR [eax],edi
  7a542f:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7a5431:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7a5434:	56                   	push   esi
  7a5435:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  7a5438:	e8 cf bd 0e 00       	call   0x89120c
  7a543d:	83 c4 04             	add    esp,0x4
  7a5440:	ff 8b 10 01 00 00    	dec    DWORD PTR [ebx+0x110]
  7a5446:	8b f7                	mov    esi,edi
  7a5448:	3b bb 0c 01 00 00    	cmp    edi,DWORD PTR [ebx+0x10c]
  7a544e:	0f 85 4c ff ff ff    	jne    0x7a53a0
  7a5454:	8b 8b 0c 01 00 00    	mov    ecx,DWORD PTR [ebx+0x10c]
  7a545a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a545c:	89 09                	mov    DWORD PTR [ecx],ecx
  7a545e:	8b 8b 0c 01 00 00    	mov    ecx,DWORD PTR [ebx+0x10c]
  7a5464:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  7a5467:	c7 83 10 01 00 00 00 	mov    DWORD PTR [ebx+0x110],0x0
  7a546e:	00 00 00 
  7a5471:	3b 83 0c 01 00 00    	cmp    eax,DWORD PTR [ebx+0x10c]
  7a5477:	74 1c                	je     0x7a5495
  7a5479:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  7a5480:	8b 30                	mov    esi,DWORD PTR [eax]
  7a5482:	50                   	push   eax
  7a5483:	e8 84 bd 0e 00       	call   0x89120c
  7a5488:	83 c4 04             	add    esp,0x4
  7a548b:	8b c6                	mov    eax,esi
  7a548d:	3b b3 0c 01 00 00    	cmp    esi,DWORD PTR [ebx+0x10c]
  7a5493:	75 eb                	jne    0x7a5480
  7a5495:	8b b3 5c 01 00 00    	mov    esi,DWORD PTR [ebx+0x15c]
  7a549b:	85 f6                	test   esi,esi
  7a549d:	74 18                	je     0x7a54b7
  7a549f:	e8 5c 1e 03 00       	call   0x7d7300
  7a54a4:	56                   	push   esi
  7a54a5:	e8 62 bd 0e 00       	call   0x89120c
  7a54aa:	83 c4 04             	add    esp,0x4
  7a54ad:	c7 83 5c 01 00 00 00 	mov    DWORD PTR [ebx+0x15c],0x0
  7a54b4:	00 00 00 
  7a54b7:	8d 7b 5c             	lea    edi,[ebx+0x5c]
  7a54ba:	e8 b1 26 df ff       	call   0x597b70
  7a54bf:	8b 83 60 01 00 00    	mov    eax,DWORD PTR [ebx+0x160]
  7a54c5:	33 f6                	xor    esi,esi
  7a54c7:	3b c6                	cmp    eax,esi
  7a54c9:	74 1e                	je     0x7a54e9
  7a54cb:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7a54ce:	8b bb 64 01 00 00    	mov    edi,DWORD PTR [ebx+0x164]
  7a54d4:	51                   	push   ecx
  7a54d5:	e8 d6 53 00 00       	call   0x7aa8b0
  7a54da:	8b 83 60 01 00 00    	mov    eax,DWORD PTR [ebx+0x160]
  7a54e0:	50                   	push   eax
  7a54e1:	e8 26 bd 0e 00       	call   0x89120c
  7a54e6:	83 c4 08             	add    esp,0x8
  7a54e9:	89 b3 60 01 00 00    	mov    DWORD PTR [ebx+0x160],esi
  7a54ef:	89 b3 64 01 00 00    	mov    DWORD PTR [ebx+0x164],esi
  7a54f5:	89 b3 68 01 00 00    	mov    DWORD PTR [ebx+0x168],esi
  7a54fb:	8b 83 4c 01 00 00    	mov    eax,DWORD PTR [ebx+0x14c]
  7a5501:	3b c6                	cmp    eax,esi
  7a5503:	74 09                	je     0x7a550e
  7a5505:	50                   	push   eax
  7a5506:	e8 01 bd 0e 00       	call   0x89120c
  7a550b:	83 c4 04             	add    esp,0x4
  7a550e:	89 b3 4c 01 00 00    	mov    DWORD PTR [ebx+0x14c],esi
  7a5514:	89 b3 50 01 00 00    	mov    DWORD PTR [ebx+0x150],esi
  7a551a:	89 b3 54 01 00 00    	mov    DWORD PTR [ebx+0x154],esi
  7a5520:	8b 8b 0c 01 00 00    	mov    ecx,DWORD PTR [ebx+0x10c]
  7a5526:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a5528:	89 09                	mov    DWORD PTR [ecx],ecx
  7a552a:	8b 8b 0c 01 00 00    	mov    ecx,DWORD PTR [ebx+0x10c]
  7a5530:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  7a5533:	89 b3 10 01 00 00    	mov    DWORD PTR [ebx+0x110],esi
  7a5539:	3b 83 0c 01 00 00    	cmp    eax,DWORD PTR [ebx+0x10c]
  7a553f:	74 15                	je     0x7a5556
  7a5541:	8b 38                	mov    edi,DWORD PTR [eax]
  7a5543:	50                   	push   eax
  7a5544:	e8 c3 bc 0e 00       	call   0x89120c
  7a5549:	83 c4 04             	add    esp,0x4
  7a554c:	8b c7                	mov    eax,edi
  7a554e:	3b bb 0c 01 00 00    	cmp    edi,DWORD PTR [ebx+0x10c]
  7a5554:	75 eb                	jne    0x7a5541
  7a5556:	8b 83 0c 01 00 00    	mov    eax,DWORD PTR [ebx+0x10c]
  7a555c:	50                   	push   eax
  7a555d:	e8 aa bc 0e 00       	call   0x89120c
  7a5562:	8b 83 90 00 00 00    	mov    eax,DWORD PTR [ebx+0x90]
  7a5568:	83 c4 04             	add    esp,0x4
  7a556b:	3b c6                	cmp    eax,esi
  7a556d:	74 09                	je     0x7a5578
  7a556f:	50                   	push   eax
  7a5570:	e8 97 bc 0e 00       	call   0x89120c
  7a5575:	83 c4 04             	add    esp,0x4
  7a5578:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7a557b:	89 b3 90 00 00 00    	mov    DWORD PTR [ebx+0x90],esi
  7a5581:	89 b3 94 00 00 00    	mov    DWORD PTR [ebx+0x94],esi
  7a5587:	89 b3 98 00 00 00    	mov    DWORD PTR [ebx+0x98],esi
  7a558d:	89 7d e4             	mov    DWORD PTR [ebp-0x1c],edi
  7a5590:	c6 45 fc 12          	mov    BYTE PTR [ebp-0x4],0x12
  7a5594:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a5597:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a5599:	50                   	push   eax
  7a559a:	51                   	push   ecx
  7a559b:	8d 75 ec             	lea    esi,[ebp-0x14]
  7a559e:	8b c7                	mov    eax,edi
  7a55a0:	e8 1b eb da ff       	call   0x5540c0
  7a55a5:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  7a55a8:	57                   	push   edi
  7a55a9:	e8 5e bc 0e 00       	call   0x89120c
  7a55ae:	8d 7b 6c             	lea    edi,[ebx+0x6c]
  7a55b1:	83 c4 04             	add    esp,0x4
  7a55b4:	89 7d e4             	mov    DWORD PTR [ebp-0x1c],edi
  7a55b7:	c6 45 fc 13          	mov    BYTE PTR [ebp-0x4],0x13
  7a55bb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a55be:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a55c0:	50                   	push   eax
  7a55c1:	51                   	push   ecx
  7a55c2:	8d 75 ec             	lea    esi,[ebp-0x14]
  7a55c5:	8b c7                	mov    eax,edi
  7a55c7:	e8 54 1b f3 ff       	call   0x6d7120
  7a55cc:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  7a55cf:	57                   	push   edi
  7a55d0:	e8 37 bc 0e 00       	call   0x89120c
  7a55d5:	8d 7b 5c             	lea    edi,[ebx+0x5c]
  7a55d8:	83 c4 04             	add    esp,0x4
  7a55db:	89 7d e4             	mov    DWORD PTR [ebp-0x1c],edi
  7a55de:	c6 45 fc 14          	mov    BYTE PTR [ebp-0x4],0x14
  7a55e2:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a55e5:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a55e7:	50                   	push   eax
  7a55e8:	51                   	push   ecx
  7a55e9:	8d 75 ec             	lea    esi,[ebp-0x14]
  7a55ec:	8b c7                	mov    eax,edi
  7a55ee:	e8 2d 1b f3 ff       	call   0x6d7120
  7a55f3:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  7a55f6:	57                   	push   edi
  7a55f7:	e8 10 bc 0e 00       	call   0x89120c
  7a55fc:	8d 7b 4c             	lea    edi,[ebx+0x4c]
  7a55ff:	83 c4 04             	add    esp,0x4
  7a5602:	89 7d e4             	mov    DWORD PTR [ebp-0x1c],edi
  7a5605:	c6 45 fc 15          	mov    BYTE PTR [ebp-0x4],0x15
  7a5609:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a560c:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a560e:	50                   	push   eax
  7a560f:	51                   	push   ecx
  7a5610:	8d 75 ec             	lea    esi,[ebp-0x14]
  7a5613:	8b c7                	mov    eax,edi
  7a5615:	e8 46 4b d2 ff       	call   0x4ca160
  7a561a:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  7a561d:	57                   	push   edi
  7a561e:	e8 e9 bb 0e 00       	call   0x89120c
  7a5623:	83 c4 04             	add    esp,0x4
  7a5626:	8d 53 2c             	lea    edx,[ebx+0x2c]
  7a5629:	52                   	push   edx
  7a562a:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  7a562e:	e8 ed fa ff ff       	call   0x7a5120
  7a5633:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  7a5637:	8b 4b 14             	mov    ecx,DWORD PTR [ebx+0x14]
  7a563a:	85 c9                	test   ecx,ecx
  7a563c:	74 13                	je     0x7a5651
  7a563e:	8d 41 08             	lea    eax,[ecx+0x8]
  7a5641:	83 ca ff             	or     edx,0xffffffff
  7a5644:	f0 0f c1 10          	lock xadd DWORD PTR [eax],edx
  7a5648:	75 07                	jne    0x7a5651
  7a564a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a564c:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a564f:	ff d2                	call   edx
  7a5651:	c7 43 0c 6c f6 c4 00 	mov    DWORD PTR [ebx+0xc],0xc4f66c
  7a5658:	c7 43 08 78 f8 c0 00 	mov    DWORD PTR [ebx+0x8],0xc0f878
  7a565f:	c7 43 04 4c f6 c4 00 	mov    DWORD PTR [ebx+0x4],0xc4f64c
  7a5666:	c7 03 68 f4 c4 00    	mov    DWORD PTR [ebx],0xc4f468
  7a566c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7a566f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7a5676:	59                   	pop    ecx
  7a5677:	5f                   	pop    edi
  7a5678:	5e                   	pop    esi
  7a5679:	5b                   	pop    ebx
  7a567a:	8b e5                	mov    esp,ebp
  7a567c:	5d                   	pop    ebp
  7a567d:	c2 04 00             	ret    0x4
```

### 201-2 CDoll I+8預清理target完整code：`0x007A57C0..0x007A5BB0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a57c0 <.text+0x3a47c0>:
  7a57c0:	55                   	push   ebp
  7a57c1:	8b ec                	mov    ebp,esp
  7a57c3:	83 e4 f8             	and    esp,0xfffffff8
  7a57c6:	6a ff                	push   0xffffffff
  7a57c8:	68 a9 91 93 00       	push   0x9391a9
  7a57cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7a57d3:	50                   	push   eax
  7a57d4:	83 ec 18             	sub    esp,0x18
  7a57d7:	53                   	push   ebx
  7a57d8:	56                   	push   esi
  7a57d9:	57                   	push   edi
  7a57da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a57df:	33 c4                	xor    eax,esp
  7a57e1:	50                   	push   eax
  7a57e2:	8d 44 24 28          	lea    eax,[esp+0x28]
  7a57e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7a57ec:	8b d9                	mov    ebx,ecx
  7a57ee:	8b 8b 18 01 00 00    	mov    ecx,DWORD PTR [ebx+0x118]
  7a57f4:	33 ff                	xor    edi,edi
  7a57f6:	3b cf                	cmp    ecx,edi
  7a57f8:	74 0d                	je     0x7a5807
  7a57fa:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a57fc:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7a57ff:	ff d2                	call   edx
  7a5801:	89 bb 18 01 00 00    	mov    DWORD PTR [ebx+0x118],edi
  7a5807:	be 01 00 00 00       	mov    esi,0x1
  7a580c:	39 73 1c             	cmp    DWORD PTR [ebx+0x1c],esi
  7a580f:	0f 85 68 01 00 00    	jne    0x7a597d
  7a5815:	6a 38                	push   0x38
  7a5817:	e8 4c ba 0e 00       	call   0x891268
  7a581c:	83 c4 04             	add    esp,0x4
  7a581f:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  7a5823:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  7a5827:	3b c7                	cmp    eax,edi
  7a5829:	74 08                	je     0x7a5833
  7a582b:	50                   	push   eax
  7a582c:	e8 4f fe ff ff       	call   0x7a5680
  7a5831:	eb 02                	jmp    0x7a5835
  7a5833:	33 c0                	xor    eax,eax
  7a5835:	50                   	push   eax
  7a5836:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  7a583a:	c7 44 24 34 ff ff ff 	mov    DWORD PTR [esp+0x34],0xffffffff
  7a5841:	ff 
  7a5842:	50                   	push   eax
  7a5843:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  7a5847:	89 7c 24 24          	mov    DWORD PTR [esp+0x24],edi
  7a584b:	e8 30 4f 00 00       	call   0x7aa780
  7a5850:	89 74 24 30          	mov    DWORD PTR [esp+0x30],esi
  7a5854:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  7a5858:	8b 4b 10             	mov    ecx,DWORD PTR [ebx+0x10]
  7a585b:	8d 53 24             	lea    edx,[ebx+0x24]
  7a585e:	52                   	push   edx
  7a585f:	8d 7e 08             	lea    edi,[esi+0x8]
  7a5862:	89 0e                	mov    DWORD PTR [esi],ecx
  7a5864:	e8 c7 fe ff ff       	call   0x7a5730
  7a5869:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  7a586c:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  7a586f:	8d 43 64             	lea    eax,[ebx+0x64]
  7a5872:	8d 7e 28             	lea    edi,[esi+0x28]
  7a5875:	3b f8                	cmp    edi,eax
  7a5877:	74 21                	je     0x7a589a
  7a5879:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a587c:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a587e:	50                   	push   eax
  7a587f:	51                   	push   ecx
  7a5880:	8d 74 24 28          	lea    esi,[esp+0x28]
  7a5884:	8b c7                	mov    eax,edi
  7a5886:	e8 95 18 f3 ff       	call   0x6d7120
  7a588b:	8d 43 64             	lea    eax,[ebx+0x64]
  7a588e:	50                   	push   eax
  7a588f:	8b c7                	mov    eax,edi
  7a5891:	e8 ba 48 00 00       	call   0x7aa150
  7a5896:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  7a589a:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  7a589e:	83 ec 08             	sub    esp,0x8
  7a58a1:	8b fc                	mov    edi,esp
  7a58a3:	89 64 24 28          	mov    DWORD PTR [esp+0x28],esp
  7a58a7:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  7a58ad:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  7a58b4:	85 d2                	test   edx,edx
  7a58b6:	74 16                	je     0x7a58ce
  7a58b8:	e8 93 69 cd ff       	call   0x47c250
  7a58bd:	84 c0                	test   al,al
  7a58bf:	74 0d                	je     0x7a58ce
  7a58c1:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  7a58c5:	51                   	push   ecx
  7a58c6:	56                   	push   esi
  7a58c7:	8b f7                	mov    esi,edi
  7a58c9:	e8 f2 d8 ff ff       	call   0x7a31c0
  7a58ce:	c6 44 24 38 02       	mov    BYTE PTR [esp+0x38],0x2
  7a58d3:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  7a58da:	75 23                	jne    0x7a58ff
  7a58dc:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  7a58e3:	c6 44 24 38 03       	mov    BYTE PTR [esp+0x38],0x3
  7a58e8:	e8 53 76 ff ff       	call   0x79cf40
  7a58ed:	68 80 db bc 00       	push   0xbcdb80
  7a58f2:	e8 23 ca 0e 00       	call   0x89231a
  7a58f7:	83 c4 04             	add    esp,0x4
  7a58fa:	c6 44 24 38 02       	mov    BYTE PTR [esp+0x38],0x2
  7a58ff:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  7a5904:	c6 44 24 38 01       	mov    BYTE PTR [esp+0x38],0x1
  7a5909:	e8 f2 84 ff ff       	call   0x79de00
  7a590e:	8d 7b 64             	lea    edi,[ebx+0x64]
  7a5911:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  7a5918:	e8 53 22 df ff       	call   0x597b70
  7a591d:	8b 83 98 00 00 00    	mov    eax,DWORD PTR [ebx+0x98]
  7a5923:	33 ff                	xor    edi,edi
  7a5925:	3b c7                	cmp    eax,edi
  7a5927:	74 14                	je     0x7a593d
  7a5929:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a592b:	ff 49 2c             	dec    DWORD PTR [ecx+0x2c]
  7a592e:	50                   	push   eax
  7a592f:	e8 d8 b8 0e 00       	call   0x89120c
  7a5934:	83 c4 04             	add    esp,0x4
  7a5937:	89 bb 98 00 00 00    	mov    DWORD PTR [ebx+0x98],edi
  7a593d:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  7a5944:	ff 
  7a5945:	8b 74 24 1c          	mov    esi,DWORD PTR [esp+0x1c]
  7a5949:	89 7b 1c             	mov    DWORD PTR [ebx+0x1c],edi
  7a594c:	c6 43 20 01          	mov    BYTE PTR [ebx+0x20],0x1
  7a5950:	3b f7                	cmp    esi,edi
  7a5952:	74 29                	je     0x7a597d
  7a5954:	8d 56 04             	lea    edx,[esi+0x4]
  7a5957:	83 c8 ff             	or     eax,0xffffffff
  7a595a:	f0 0f c1 02          	lock xadd DWORD PTR [edx],eax
  7a595e:	75 1d                	jne    0x7a597d
  7a5960:	8b 16                	mov    edx,DWORD PTR [esi]
  7a5962:	8b 02                	mov    eax,DWORD PTR [edx]
  7a5964:	8b ce                	mov    ecx,esi
  7a5966:	ff d0                	call   eax
  7a5968:	8d 4e 08             	lea    ecx,[esi+0x8]
  7a596b:	83 ca ff             	or     edx,0xffffffff
  7a596e:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  7a5972:	75 09                	jne    0x7a597d
  7a5974:	8b 06                	mov    eax,DWORD PTR [esi]
  7a5976:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a5979:	8b ce                	mov    ecx,esi
  7a597b:	ff d2                	call   edx
  7a597d:	8b 83 48 01 00 00    	mov    eax,DWORD PTR [ebx+0x148]
  7a5983:	2b 83 44 01 00 00    	sub    eax,DWORD PTR [ebx+0x144]
  7a5989:	33 f6                	xor    esi,esi
  7a598b:	c1 f8 03             	sar    eax,0x3
  7a598e:	85 c0                	test   eax,eax
  7a5990:	74 3f                	je     0x7a59d1
  7a5992:	8b 8b 44 01 00 00    	mov    ecx,DWORD PTR [ebx+0x144]
  7a5998:	8b 7c f1 04          	mov    edi,DWORD PTR [ecx+esi*8+0x4]
  7a599c:	85 ff                	test   edi,edi
  7a599e:	74 1d                	je     0x7a59bd
  7a59a0:	57                   	push   edi
  7a59a1:	e8 ea 2e 03 00       	call   0x7d8890
  7a59a6:	57                   	push   edi
  7a59a7:	e8 60 b8 0e 00       	call   0x89120c
  7a59ac:	8b 93 44 01 00 00    	mov    edx,DWORD PTR [ebx+0x144]
  7a59b2:	83 c4 04             	add    esp,0x4
  7a59b5:	c7 44 f2 04 00 00 00 	mov    DWORD PTR [edx+esi*8+0x4],0x0
  7a59bc:	00 
  7a59bd:	8b 83 48 01 00 00    	mov    eax,DWORD PTR [ebx+0x148]
  7a59c3:	2b 83 44 01 00 00    	sub    eax,DWORD PTR [ebx+0x144]
  7a59c9:	46                   	inc    esi
  7a59ca:	c1 f8 03             	sar    eax,0x3
  7a59cd:	3b f0                	cmp    esi,eax
  7a59cf:	72 c1                	jb     0x7a5992
  7a59d1:	8b 8b 44 01 00 00    	mov    ecx,DWORD PTR [ebx+0x144]
  7a59d7:	8b 93 48 01 00 00    	mov    edx,DWORD PTR [ebx+0x148]
  7a59dd:	3b ca                	cmp    ecx,edx
  7a59df:	74 20                	je     0x7a5a01
  7a59e1:	8b c2                	mov    eax,edx
  7a59e3:	3b d2                	cmp    edx,edx
  7a59e5:	74 14                	je     0x7a59fb
  7a59e7:	8b 30                	mov    esi,DWORD PTR [eax]
  7a59e9:	89 31                	mov    DWORD PTR [ecx],esi
  7a59eb:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  7a59ee:	89 71 04             	mov    DWORD PTR [ecx+0x4],esi
  7a59f1:	83 c0 08             	add    eax,0x8
  7a59f4:	83 c1 08             	add    ecx,0x8
  7a59f7:	3b c2                	cmp    eax,edx
  7a59f9:	75 ec                	jne    0x7a59e7
  7a59fb:	89 8b 48 01 00 00    	mov    DWORD PTR [ebx+0x148],ecx
  7a5a01:	8b 83 00 01 00 00    	mov    eax,DWORD PTR [ebx+0x100]
  7a5a07:	85 c0                	test   eax,eax
  7a5a09:	74 06                	je     0x7a5a11
  7a5a0b:	50                   	push   eax
  7a5a0c:	e8 df 86 01 00       	call   0x7be0f0
  7a5a11:	8b 83 04 01 00 00    	mov    eax,DWORD PTR [ebx+0x104]
  7a5a17:	8b 38                	mov    edi,DWORD PTR [eax]
  7a5a19:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  7a5a1d:	3b f8                	cmp    edi,eax
  7a5a1f:	0f 84 2b 01 00 00    	je     0x7a5b50
  7a5a25:	eb 04                	jmp    0x7a5a2b
  7a5a27:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  7a5a2b:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  7a5a2e:	85 f6                	test   esi,esi
  7a5a30:	0f 84 cb 00 00 00    	je     0x7a5b01
  7a5a36:	8b 06                	mov    eax,DWORD PTR [esi]
  7a5a38:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7a5a3b:	8b 46 74             	mov    eax,DWORD PTR [esi+0x74]
  7a5a3e:	85 c0                	test   eax,eax
  7a5a40:	0f 84 9c 00 00 00    	je     0x7a5ae2
  7a5a46:	83 7e 78 00          	cmp    DWORD PTR [esi+0x78],0x0
  7a5a4a:	0f 84 92 00 00 00    	je     0x7a5ae2
  7a5a50:	8b 3e                	mov    edi,DWORD PTR [esi]
  7a5a52:	83 7f 44 01          	cmp    DWORD PTR [edi+0x44],0x1
  7a5a56:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  7a5a5a:	0f 8c 8d 00 00 00    	jl     0x7a5aed
  7a5a60:	8d 47 64             	lea    eax,[edi+0x64]
  7a5a63:	50                   	push   eax
  7a5a64:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  7a5a68:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7a5a6e:	8b 87 80 00 00 00    	mov    eax,DWORD PTR [edi+0x80]
  7a5a74:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  7a5a78:	3b c8                	cmp    ecx,eax
  7a5a7a:	73 36                	jae    0x7a5ab2
  7a5a7c:	8b 4f 7c             	mov    ecx,DWORD PTR [edi+0x7c]
  7a5a7f:	8d 54 24 18          	lea    edx,[esp+0x18]
  7a5a83:	3b ca                	cmp    ecx,edx
  7a5a85:	77 2b                	ja     0x7a5ab2
  7a5a87:	8b f2                	mov    esi,edx
  7a5a89:	2b f1                	sub    esi,ecx
  7a5a8b:	c1 fe 02             	sar    esi,0x2
  7a5a8e:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  7a5a94:	75 08                	jne    0x7a5a9e
  7a5a96:	8d 47 7c             	lea    eax,[edi+0x7c]
  7a5a99:	e8 92 1e ff ff       	call   0x797930
  7a5a9e:	8b 87 80 00 00 00    	mov    eax,DWORD PTR [edi+0x80]
  7a5aa4:	85 c0                	test   eax,eax
  7a5aa6:	74 26                	je     0x7a5ace
  7a5aa8:	8b 4f 7c             	mov    ecx,DWORD PTR [edi+0x7c]
  7a5aab:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  7a5aae:	89 10                	mov    DWORD PTR [eax],edx
  7a5ab0:	eb 1c                	jmp    0x7a5ace
  7a5ab2:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  7a5ab8:	75 08                	jne    0x7a5ac2
  7a5aba:	8d 47 7c             	lea    eax,[edi+0x7c]
  7a5abd:	e8 6e 1e ff ff       	call   0x797930
  7a5ac2:	8b 87 80 00 00 00    	mov    eax,DWORD PTR [edi+0x80]
  7a5ac8:	85 c0                	test   eax,eax
  7a5aca:	74 02                	je     0x7a5ace
  7a5acc:	89 30                	mov    DWORD PTR [eax],esi
  7a5ace:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  7a5ad2:	83 87 80 00 00 00 04 	add    DWORD PTR [edi+0x80],0x4
  7a5ad9:	50                   	push   eax
  7a5ada:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7a5ae0:	eb 1b                	jmp    0x7a5afd
  7a5ae2:	83 f8 01             	cmp    eax,0x1
  7a5ae5:	7c 06                	jl     0x7a5aed
  7a5ae7:	56                   	push   esi
  7a5ae8:	e8 03 86 01 00       	call   0x7be0f0
  7a5aed:	8b fe                	mov    edi,esi
  7a5aef:	e8 5c 7d 01 00       	call   0x7bd850
  7a5af4:	56                   	push   esi
  7a5af5:	e8 12 b7 0e 00       	call   0x89120c
  7a5afa:	83 c4 04             	add    esp,0x4
  7a5afd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  7a5b01:	8b 77 0c             	mov    esi,DWORD PTR [edi+0xc]
  7a5b04:	85 f6                	test   esi,esi
  7a5b06:	74 12                	je     0x7a5b1a
  7a5b08:	8b 16                	mov    edx,DWORD PTR [esi]
  7a5b0a:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a5b0d:	8b ce                	mov    ecx,esi
  7a5b0f:	ff d0                	call   eax
  7a5b11:	8b 16                	mov    edx,DWORD PTR [esi]
  7a5b13:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  7a5b16:	8b ce                	mov    ecx,esi
  7a5b18:	ff d0                	call   eax
  7a5b1a:	8b 37                	mov    esi,DWORD PTR [edi]
  7a5b1c:	3b bb 04 01 00 00    	cmp    edi,DWORD PTR [ebx+0x104]
  7a5b22:	74 1c                	je     0x7a5b40
  7a5b24:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  7a5b27:	89 31                	mov    DWORD PTR [ecx],esi
  7a5b29:	8b 17                	mov    edx,DWORD PTR [edi]
  7a5b2b:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7a5b2e:	57                   	push   edi
  7a5b2f:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7a5b32:	e8 d5 b6 0e 00       	call   0x89120c
  7a5b37:	83 c4 04             	add    esp,0x4
  7a5b3a:	ff 8b 08 01 00 00    	dec    DWORD PTR [ebx+0x108]
  7a5b40:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  7a5b44:	3b b3 04 01 00 00    	cmp    esi,DWORD PTR [ebx+0x104]
  7a5b4a:	0f 85 d7 fe ff ff    	jne    0x7a5a27
  7a5b50:	8b 8b 04 01 00 00    	mov    ecx,DWORD PTR [ebx+0x104]
  7a5b56:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a5b58:	89 09                	mov    DWORD PTR [ecx],ecx
  7a5b5a:	8b 8b 04 01 00 00    	mov    ecx,DWORD PTR [ebx+0x104]
  7a5b60:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  7a5b63:	33 ff                	xor    edi,edi
  7a5b65:	89 bb 08 01 00 00    	mov    DWORD PTR [ebx+0x108],edi
  7a5b6b:	3b 83 04 01 00 00    	cmp    eax,DWORD PTR [ebx+0x104]
  7a5b71:	74 15                	je     0x7a5b88
  7a5b73:	8b 30                	mov    esi,DWORD PTR [eax]
  7a5b75:	50                   	push   eax
  7a5b76:	e8 91 b6 0e 00       	call   0x89120c
  7a5b7b:	83 c4 04             	add    esp,0x4
  7a5b7e:	8b c6                	mov    eax,esi
  7a5b80:	3b b3 04 01 00 00    	cmp    esi,DWORD PTR [ebx+0x104]
  7a5b86:	75 eb                	jne    0x7a5b73
  7a5b88:	89 bb 10 01 00 00    	mov    DWORD PTR [ebx+0x110],edi
  7a5b8e:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  7a5b92:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7a5b99:	59                   	pop    ecx
  7a5b9a:	5f                   	pop    edi
  7a5b9b:	5e                   	pop    esi
  7a5b9c:	5b                   	pop    ebx
  7a5b9d:	8b e5                	mov    esp,ebp
  7a5b9f:	5d                   	pop    ebp
  7a5ba0:	c3                   	ret
  7a5ba1:	cc                   	int3
  7a5ba2:	cc                   	int3
  7a5ba3:	cc                   	int3
  7a5ba4:	cc                   	int3
  7a5ba5:	cc                   	int3
  7a5ba6:	cc                   	int3
  7a5ba7:	cc                   	int3
  7a5ba8:	cc                   	int3
  7a5ba9:	cc                   	int3
  7a5baa:	cc                   	int3
  7a5bab:	cc                   	int3
  7a5bac:	cc                   	int3
  7a5bad:	cc                   	int3
  7a5bae:	cc                   	int3
  7a5baf:	cc                   	int3
```

### 201-2 control dispose完整code：`0x004CA660..0x004CA670`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ca660 <.text+0xc9660>:
  4ca660:	8b 49 0c             	mov    ecx,DWORD PTR [ecx+0xc]
  4ca663:	85 c9                	test   ecx,ecx
  4ca665:	74 08                	je     0x4ca66f
  4ca667:	8b 01                	mov    eax,DWORD PTR [ecx]
  4ca669:	8b 10                	mov    edx,DWORD PTR [eax]
  4ca66b:	6a 01                	push   0x1
  4ca66d:	ff d2                	call   edx
  4ca66f:	c3                   	ret
```

### 201-2 control次級release完整code：`0x007A3920..0x007A3930`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a3920 <.text+0x3a2920>:
  7a3920:	85 c9                	test   ecx,ecx
  7a3922:	74 09                	je     0x7a392d
  7a3924:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a3926:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7a3929:	6a 01                	push   0x1
  7a392b:	ff d2                	call   edx
  7a392d:	c3                   	ret
  7a392e:	cc                   	int3
  7a392f:	cc                   	int3
```

### 201-2 control deleting destructor完整code：`0x007A3950..0x007A3980`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a3950 <.text+0x3a2950>:
  7a3950:	55                   	push   ebp
  7a3951:	8b ec                	mov    ebp,esp
  7a3953:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  7a3957:	56                   	push   esi
  7a3958:	8b f1                	mov    esi,ecx
  7a395a:	c7 06 0c 31 c0 00    	mov    DWORD PTR [esi],0xc0310c
  7a3960:	74 09                	je     0x7a396b
  7a3962:	56                   	push   esi
  7a3963:	e8 a4 d8 0e 00       	call   0x89120c
  7a3968:	83 c4 04             	add    esp,0x4
  7a396b:	8b c6                	mov    eax,esi
  7a396d:	5e                   	pop    esi
  7a396e:	5d                   	pop    ebp
  7a396f:	c2 04 00             	ret    0x4
  7a3972:	cc                   	int3
  7a3973:	cc                   	int3
  7a3974:	cc                   	int3
  7a3975:	cc                   	int3
  7a3976:	cc                   	int3
  7a3977:	cc                   	int3
  7a3978:	cc                   	int3
  7a3979:	cc                   	int3
  7a397a:	cc                   	int3
  7a397b:	cc                   	int3
  7a397c:	cc                   	int3
  7a397d:	cc                   	int3
  7a397e:	cc                   	int3
  7a397f:	cc                   	int3
```

### 201-2 handler物件配置與outer owner安裝caller：`0x0048F6CE..0x0048F741`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048f6ce <.text+0x8e6ce>:
  48f6ce:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48f6d1:	39 99 d0 bf 00 00    	cmp    DWORD PTR [ecx+0xbfd0],ebx
  48f6d7:	74 68                	je     0x48f741
  48f6d9:	68 ac 5e 00 00       	push   0x5eac
  48f6de:	e8 85 1b 40 00       	call   0x891268
  48f6e3:	83 c4 04             	add    esp,0x4
  48f6e6:	3b c3                	cmp    eax,ebx
  48f6e8:	74 19                	je     0x48f703
  48f6ea:	e8 61 e6 01 00       	call   0x4add50
  48f6ef:	c7 00 b4 72 c0 00    	mov    DWORD PTR [eax],0xc072b4
  48f6f5:	c7 05 74 a6 d6 00 53 	mov    DWORD PTR ds:0xd6a674,0x46495253
  48f6fc:	52 49 46 
  48f6ff:	8b f8                	mov    edi,eax
  48f701:	eb 02                	jmp    0x48f705
  48f703:	33 ff                	xor    edi,edi
  48f705:	f6 05 f4 2c fd 00 01 	test   BYTE PTR ds:0xfd2cf4,0x1
  48f70c:	75 29                	jne    0x48f737
  48f70e:	83 0d f4 2c fd 00 01 	or     DWORD PTR ds:0xfd2cf4,0x1
  48f715:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  48f71c:	6e c0 00 
  48f71f:	89 1d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,ebx
  48f725:	e8 96 86 02 00       	call   0x4b7dc0
  48f72a:	68 f0 dc bc 00       	push   0xbcdcf0
  48f72f:	e8 e6 2b 40 00       	call   0x89231a
  48f734:	83 c4 04             	add    esp,0x4
  48f737:	be f8 2c fd 00       	mov    esi,0xfd2cf8
  48f73c:	e8 0f 86 02 00       	call   0x4b7d50
```

### 201-2 outer owner安裝helper完整code：`0x004B7D50..0x004B7DC0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b7d50 <.text+0xb6d50>:
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```

### 201-2 outer handler tail dispatch完整code：`0x004B7EC0..0x004B7F00`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b7ec0 <.text+0xb6ec0>:
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2 0c 00             	ret    0xc
  4b7ef2:	cc                   	int3
  4b7ef3:	cc                   	int3
  4b7ef4:	cc                   	int3
  4b7ef5:	cc                   	int3
  4b7ef6:	cc                   	int3
  4b7ef7:	cc                   	int3
  4b7ef8:	cc                   	int3
  4b7ef9:	cc                   	int3
  4b7efa:	cc                   	int3
  4b7efb:	cc                   	int3
  4b7efc:	cc                   	int3
  4b7efd:	cc                   	int3
  4b7efe:	cc                   	int3
  4b7eff:	cc                   	int3
```

### 201-2 handler表consumer完整code：`0x004FDA30..0x004FDAC0`

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004fda30 <.text+0xfca30>:
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
  4fdab3:	cc                   	int3
  4fdab4:	cc                   	int3
  4fdab5:	cc                   	int3
  4fdab6:	cc                   	int3
  4fdab7:	cc                   	int3
  4fdab8:	cc                   	int3
  4fdab9:	cc                   	int3
  4fdaba:	cc                   	int3
  4fdabb:	cc                   	int3
  4fdabc:	cc                   	int3
  4fdabd:	cc                   	int3
  4fdabe:	cc                   	int3
  4fdabf:	cc                   	int3
```

## 附錄C：201-2 RTTI與virtual targets原始資料

COL layout採PE32 MSVC的5 DWORD，欄位為signature、subobject_offset、constructor_displacement、TypeDescriptor VA、Hierarchy VA；name由TypeDescriptor+8讀NUL終止字串。

| vtable VA | vtable[-1] bytes | COL VA | COL原始20bytes | TD/name |
|---|---|---|---|---|
| 0x00C4F67C | `7c fa c7 00` | 0x00C7FA7C | `00 00 00 00 00 00 00 00 00 00 00 00 18 a7 f8 00 90 fa c7 00` | 0x00F8A718 `.?AVCDoll@IS3D@@` |
| 0x00C4F690 | `68 fa c7 00` | 0x00C7FA68 | `00 00 00 00 04 00 00 00 00 00 00 00 18 a7 f8 00 90 fa c7 00` | 0x00F8A718 `.?AVCDoll@IS3D@@` |
| 0x00C4F6B0 | `54 fa c7 00` | 0x00C7FA54 | `00 00 00 00 08 00 00 00 00 00 00 00 18 a7 f8 00 90 fa c7 00` | 0x00F8A718 `.?AVCDoll@IS3D@@` |
| 0x00C4F6C0 | `40 fa c7 00` | 0x00C7FA40 | `00 00 00 00 0c 00 00 00 00 00 00 00 18 a7 f8 00 90 fa c7 00` | 0x00F8A718 `.?AVCDoll@IS3D@@` |
| 0x00C0760C | `48 9f c6 00` | 0x00C69F48 | `00 00 00 00 00 00 00 00 00 00 00 00 64 e2 f7 00 5c 9f c6 00` | 0x00F7E264 `.?AV?$_Ref_count@VCDoll@IS3D@@@tr1@std@@` |

| table/slot | VA | raw bytes | target |
|---|---|---|---|
| 0x00C0C9DC+0x30 | 0x00C0CA0C | `10 19 4d 00` | 0x004D1910 |
| 0x00C4F67C+0x0 | 0x00C4F67C | `f0 4f 7a 00` | 0x007A4FF0 |
| 0x00C4F6B0+0x8 | 0x00C4F6B8 | `c0 57 7a 00` | 0x007A57C0 |
| 0x00C0760C+0x0 | 0x00C0760C | `60 a6 4c 00` | 0x004CA660 |
| 0x00C0760C+0x4 | 0x00C07610 | `20 39 7a 00` | 0x007A3920 |
| 0x00C0760C+0x8 | 0x00C07614 | `50 39 7a 00` | 0x007A3950 |
| 0x00C072B4+0x4 | 0x00C072B8 | `30 da 4f 00` | 0x004FDA30 |

IAT raw DWORD（指向Hint/Name RVA，非runtime函式位址）：

- IAT 0x00BD224C: bytes `32 e4 95 00`, name `EnterCriticalSection`。
- IAT 0x00BD2248: bytes `4a e4 95 00`, name `LeaveCriticalSection`。

## 附錄D：續完版本交付狀態

本次只有離線分析及自己的完整Markdown；無Commit、無Push、無遠端README或Task狀態修改。所有未完成的原生驗收保留為缺口，沒有標記native_complete。完整附錄是有限窗口的原始解碼，不是整個Client生命週期已完整還原的宣告。201-2補充核對main SHA為4998575006af5fa777bd024fe9cf31a7924ce7c0，該版本T08 README退回條目仍未更動。
