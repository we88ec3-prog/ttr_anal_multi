# KR T09 — 以全程式 Ghidra 反編譯（kr-bulk-roy）對照：Actor 類別樹、移動公式、表 A 完整 101 項、表 B（各 Scene）

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-27 04:44:28 +08:00`
- Scope: `kr-bulk-roy/9741…/functions/`（111,054 個函式偽碼）＋機器碼對照；範圍＝`4ADD50`、表 A 所有處理函式的分類、CBasicObject／CCharacter／CMonster／CNPC／CEventObject／CDropItem／CBullet 的 vtable、`4CA890`、`4CAD40`、`4CAD60`、`4CAB80`、`4CABE0`、`4CE7F0`、`4AFAF0`、`4B0130`、`4B01C0`、`4AE4D0`、`4B2CD0`、`4AF1F0`
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…T09-bulk-ghidra-crosscheck-table-B-and-scene-enter.md`、`…summary-draft-for-integrator.md`
- Summary: bulk 已涵蓋整份 PE 的 111,054 個函式（`status.json`：`acquisition_complete_review_unverified`）。本輪用它一次補齊：(1) 表 A 全 101 項；(2) 各 Scene 的表 B；(3) **Actor 類別樹與 vtable 槽位**；(4) **移動速度與每幀步進公式**；(5) 多個 S→C 處理的封包格式。同時**修正舊記錄兩處**：`0x94` 建立的是 `CBullet`（非通用 actor）；常數 `C557F8` 是 double 0.01（舊記錄寫 2.0）。

## 狀態標記
【確認】＝機器碼確認（含 `bdis.py` 讀 vtable／常數）；【bulk】＝只見於 Ghidra 偽碼（`confidence: derived`，未獨立核對）；【推測】；【未知】

## 一、修正舊記錄（證據）
1. **索引 0x94（`4AF1F0`）建立的是 `CBullet`**（【確認】）：`FUN_00891268(0x138)` → `FUN_004cbff0`；`4CBFF0` 內 `*obj=CBullet::vftable`（機器碼 vtable `0xC079FC`，`bdis` 讀出其 +0x20=`4CC150`、+0x58=`4CB070`、+0x5C=`4CB130`）。先前稱為「actor 生成記錄」不精確；它會註冊到同一個 `FAB138` map（`4DFF30`），所以子彈物件與角色共用 id 空間。
2. **`C557F8` 是 double 0.01，不是 2.0**（【確認】`struct.unpack('<d', rd(0xC557F8,8))=0.00999999977`）；`4CAD40` 的 `fmul qword [C557F8]` 用的就是它。2.0／4.0 是 `4CA890` 內的**立即數**（`push 0x40000000`／`0x40800000`）。
3. 我先前把 `4CA890` 當成唯一的逐幀函式；實際上它是 **`CBasicObject` vtbl+0x20（Update）**，由子類的 Update 呼叫：`CCharacter::Update=4CDD40` → `4C8580` → `4CA890`（【bulk】：`4C8580` 偽碼第一個呼叫即 `FUN_004ca890`）。`CDropItem` 直接沿用 `4CA890`（vtable `C07C0C` 的 +0x20 為 `4D0340`，其內另呼叫 `4CAD60`；【確認】僅 vtable 值）。

## 二、Actor 類別樹與 vtable（【確認】vtable 內容；類別名稱來自偽碼 RTTI）
| 類別 | vtable | +0x20 Update | +0x44 SetPos | +0x54 MoveBy | +0x58 SetHeading | +0x5C | +0x60 Speed | +0x68 | 配置大小 | 建構 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| CBasicObject | C076AC | 4CA890 | 4CAB80 | 4CABE0 | 4C8C30 | 4C6FE0 | 4CAD40 | 4CC0D0 | — | 4CA730 |
| CCharacter | C07B44 | 4CDD40 | 4C8B90 | 4CABE0 | 4C8C30 | 4C8C40 | 4CAD40 | 4C8DA0 | 0x444 | 4CD6F0 |
| CMonster | C0C9DC | 4D1AE0 | 4C8B90 | 4CABE0 | 4C8C30 | 4C8C40 | 4CAD40 | 4C8DA0 | 0x434 | 4D1710 |
| CNPC | C0CA9C | 4D2890 | 4C8B90 | 4CABE0 | 4C8C30 | 4C8C40 | 4CAD40 | 4C8DA0 | 0x42C | 4D2120 |
| CEventObject | C0C8C4 | 4D1680 | 4C8B90 | 4CABE0 | 4C8C30 | 4C8C40 | 4CAD40 | 4C8DA0 | 0x428 | 4D1060 |
| CDropItem | C07C0C | 4D0340 | 4CAB80 | 4CABE0 | 4D0890 | 4D0930 | 4CAD40 | — | 0x140 | 4CFD10 |
| CBullet | C079FC | 4CC150 | 4CAB80 | 4CABE0 | 4CB070 | 4CB130 | 4CAD40 | — | 0x138 | 4CBFF0 |
- 判斷 vtable 的方式：建構函式內有多個 `mov [reg],imm(C0xxxx)`（含子物件 `[+0xF0]` 的次要 vtable），我逐一以 `rd()` 讀出各候選的槽位，挑出「+0x44 指向 4C8B90/4CAB80、+0x54 指向 4CABE0」的那一個作主 vtable。
- 【bulk】`CBasicObject` 欄位（`4CA730`）：`+0x04 word` id（字典鍵）、`+0x88/+0x8C` 模型、`+0xA0/+0xA4/+0xA8` 位置 float x/y/z、`+0xAC` 位置髒旗標、`+0xB0 byte` 朝向、`+0xB4 float` 初值 1.0、`+0xBC byte`、`+0xC0/+0xC4` 目標、`+0xC8` 步數、`+0xCC float` 速度係數（初值 0）、`+0xD0 int` 速度百分比（初值 100）、`+0xD4` 移動模式、`+0xD8/+0xDC` 殘差。

## 三、位置 API 與每幀移動（【確認】機器碼）
- `vtbl+0x44` SetPosition(float*xy, flag)：若與目前 (+0xA0,+0xA4) 不同則寫入；`flag≠0` 時設 `[+0xAC]=1` 並呼叫 `vtbl+0x38`（位置已變更通知）。`CCharacter／CMonster／CNPC／CEventObject` 的版本 `4C8B90` 先呼叫 `4CAB80`，再在 `[+0x15C]`、`[+0x15C+...]` 的物件存在時以 `vtbl+0x4C` 取得位置通知 3D 子物件（【bulk】）。
- `vtbl+0x54` MoveBy(delta)：候選＝位置＋delta；若 `[0xFAB1D0]≠0` 呼叫 `82CDF0(候選)`；回傳非 0（可通行）才 `SetPosition(候選,1)`；**不可通行則完全不動，沒有沿牆滑動或夾回**（偽碼與先前機器碼讀取一致）。
- `vtbl+0x58` SetHeading：`[+0xB0]=byte`。
- `vtbl+0x60`（`4CAD40`）取速度＝`(float)[+0xD0] × 0.01(double) × [+0xCC]`（機器碼 `4CAD44..4CAD56`）。
- `4CA890`（每個 Update 一次；`dt = 1 / (float)[singleton+0x1360]`，該欄位初值 `0x1E=30` 於 `6E4450` 與 `6DF3D0` 設定；【確認】`4CA8DD..4CA8E7`）：
  - `[+0xD4] ≠ 1`（一般模式）：若 `[+0xE2] bit15`（移動旗標）＝1：`step = speed × dt`，方向＝`(DAT_FB8020[2·h], DAT_FB8024[2·h])`（h＝`byte [+0xE4]`，256 方向表），呼叫 `vtbl+0x54(step×dir)`；再 `4CAD60(dt, 2.0f, 0)`；未移動則 `4CAD60(dt, 4.0f, 0)`。
  - `[+0xD4] = 1`（移向目標）：`delta = (+0xC0,+0xC4) − (+0xA0,+0xA4)`；若 `[+0xC8]≠0`：`step = delta / [+0xC8]`（`sqrt` 後除以步數再正規化乘長度；機器碼 `4CA9DE..4CAA4B`），`vtbl+0x54(step)`，`[+0xC8]--`；若 `[+0xC8]==0`：`vtbl+0x44(target,1)`，`[+0xE8/+0xEC]=target`，若 `|target − pos|² > 4.0` 設殘差，清 `[+0xE2] bit15`，`[+0xD4]=0`。此模式**以幀數計步，不看 dt**。
  - `4CAD60(dt, k, mode)`（殘差消耗）：`R=[+0xD8,+0xDC]`；若 `|R|²>0.01`：`step = dt × k × R`，`R −= step`；若 `|R|²<0.04`（偽碼：`local_c<0.04`）則把餘量一次併入並清零；`mode==0` 走 `vtbl+0x54`，否則 `vtbl+0x44(…,1)`。→ **殘差以每秒 `k` 的比例指數衰減：移動中 k=2.0、靜止 k=4.0**（【確認】公式；`dt=1/30` 為【推測】tick 率，僅因欄位初值為 30，`6DF1B0` 為其讀取函式）。
- 速度參數寫入（S→C 索引 0 `4AFAF0`，【確認】`4CE7F0` 機器碼 case 5／6）：封包 `{word cmd, N×{word actorId, word param, word value}}`（每筆 6 bytes，`(len−2)/6` 筆）→ `CCharacter vtbl+0x2C(param, value)`；`param=5` → `[+0xD0]=(int16)value`；`param=6` → `[+0xCC]=(float)(int16)value`。其他 param（1,2,3,4,0x17,0x19,0x1D,0x1E）見 `4CE7F0`，語意未讀。→ **角色移動速度＝`D0/100 × CC`（座標單位／秒）**；`D0`、`CC` 的數值來源（伺服器）靜態無法知。
- 【bulk】位置×0.1：`4C8580` 對 slot-0 英雄把 `vtbl+0x50` 的座標乘 0.1 傳給聆聽者（音效／相機）物件。→ 3D 世界單位＝本座標空間 ÷10（僅就此一用法；【推測】為通用換算）。

## 四、表 A 處理的重新分類（【bulk】封包長度皆由偽碼 `(len−2)/N`、機器碼未逐一核對）
| 索引 | 處理 | 內容 |
| --- | --- | --- |
| 0x00 | 4AFAF0 | 參數更新：6 B/筆 `{id, param, value}` → `vtbl+0x2C` |
| 0x01、0x16 | 4AFB80 | （舊記錄）位置設定。**0x16 確認同為 4AFB80**（`4ADD50` 中 `in_EAX[0x2D]=4AFB80`） |
| 0x07 | 4AE4D0 | **角色／怪物／NPC／事件物件生成**：26 B/筆；`byte(rec[+0])` 為類型 0=CCharacter(0x444)、1=CMonster(0x434)、6=CNPC(0x42C)、7=CEventObject(0x428)（配置大小取自 `4AE4D0` 偽碼各 case 的 `FUN_00891268(size)`；【bulk】）；位置為 **float** `vtbl+0x44(data+8,1)`；朝向 `vtbl+0x58`；`vtbl+0x5C(dword @data+16)`；`[actor+0x4]=id` |
| 0x0A | 4AF920 | 群組／成員清單（上一份筆記） |
| 0x0B | 4AFE60 | 移動狀態（舊） |
| 0x0C | 4B0130 | 動作更新：3 B/筆 `{word id, sbyte motion}` → `[actor+0xF0]` 物件 `vtbl+8(motion)`；找不到記 "Motion Update: Cannot Found In CharList" |
| 0x0D | 4B01C0 | **技能使用**：9 B/筆 `{word id, byte heading, word skillId, dword param}`；先 `vtbl+0x58(heading)`，用角度表 `FB7C20[heading]` 轉子物件，再呼叫 `4C8A90(skillId,param)`：**把殘差一次併入位置（`vtbl+0x44`）後才執行 `vtbl+0x68`**。這就是先前「4C8A90 唯一呼叫者」的來源（【確認】`4C8A90` 偽碼；呼叫關係【bulk】） |
| 0x18 | 4B2730 | 移向目標（舊） |
| 0x21 | 4B2CD0 | **CDropItem 生成**：31 B/筆；`vtbl+0x44(rec+6)`、`[+0xC0/+0xC4]=rec+14/+18`、`[+0xC8]=0x14`（20 步）、`[+0xD4]=1`（移向目標）；→ 掉落物以 20 幀由出生點移動到目標點 |
| 0x94 | 4AF1F0 | **CBullet 生成**（修正） |
- 其餘索引的處理大小／旗標見附錄；未讀者不下結論。

## 五、各 Scene 表 B（偽碼解析；索引＝(dword 偏移−基底)/2 或 (byte 偏移−0x5EAC)/8）
| 建構函式 | Scene | 條目（索引→處理） |
| --- | --- | --- |
| `422440` | Scene::CDailyDungeonDecision | 0x37→4BC460 |
| `422FF0` | （vtable 設定在呼叫者） | 0x14→4C5930, 0x39→495270, 0x3a→4C58A0, 0x31→4BCA90, 0x3b→4C5590 |
| `424310` | （vtable 設定在呼叫者） | 0x1f→4C5C50, 0x25→4C5C50, 0x62→4246A0, 0x9a→424610 |
| `434320` | Scene::CEternalTowerDecision |  |
| `4369D0` | Scene::CEternalTowerField | 0x14→4C5930, 0xe→436C40 |
| `453E60` | Scene::CInfiniteDungeonDecision |  |
| `4564F0` | Scene::CInfiniteDungeonField | 0x14→4C5930, 0xe→436C40 |
| `4BB4A0` | （vtable 設定在呼叫者） | 0x62→4BB990, 0x1f→4C5C50, 0x25→4C5C50, 0x68→4BC050, 0x6a→4BBFA0, 0x6b→4BBAE0, 0xa9→424610, 0xab→424610 |
| `4BBBA0` | （vtable 設定在呼叫者） | 0x1f→4C5C50, 0x25→4C5C50, 0x68→4BC050, 0x6a→4BBFA0, 0x6b→4BBAE0 |
| `4BC170` | Scene::CMissionDecision | 0x37→4BC460 |
| `4BC6E0` | （vtable 設定在呼叫者） | 0x14→4C5930, 0x39→4BC930, 0x3a→4C58A0, 0x31→4BCA90, 0x3b→4C5590 |
| `4BCB40` | （vtable 設定在呼叫者） | 0x1f→4C5C50, 0x25→4C5C50, 0x62→4BD2F0, 0x9a→424610 |
| `4BD590` | Scene::CDuelDecision |  |
| `4BDBA0` | （vtable 設定在呼叫者） | 0x14→4C5930, 0x110→4BE090, 0x10f→424610, 0x112→4BE170, 0xbc→4BE260 |
| `4BE400` | （vtable 設定在呼叫者） | 0x62→4BEA00, 0xa9→424610, 0xaa→4BED10, 0xab→424610, 0xac→4BEDF0, 0xb4→4BEE10, 0xb5→4BEE90, 0xbe→4BF040, 0xbf→4BF3B0, 0xc0→4BF780 |
| `4C0610` | Scene::CGvGDuelDecision |  |
| `4C13E0` | Scene::CExpedition | 0x4a→4C21D0, 0x68→4C21F0 |
| `4C3220` | （vtable 設定在呼叫者） | 0x13→4C37A0, 0x35→4C3B90, 0x7a→4C3C10, 0x101→4C3D10, 0x102→4C3C30, 0x13b→4C3FB0, 0x104→4C4160, 0x103→4C4090, 0x13c→4C3DF0, 0x13d→4C3ED0 |
| `4C46F0` | Scene::CScenarioField | 0x14→4C5930, 0xe→436C40 |
| `4C4AC0` | Scene::CTutorial | 0x4c→4C4F20 |
| `4C4FB0` | Scene::CRaidDecision | 0x37→4BC460 |
| `4C5520` | （vtable 設定在呼叫者） | 0x14→4C5930, 0x39→4C5610, 0x3a→4C58A0, 0x31→4BCA90, 0x3b→4C5590 |
| `4C5970` | （vtable 設定在呼叫者） | 0x1f→4C5C50, 0x25→4C5C50, 0x62→4C5CB0, 0xa7→424610 |
- Field 類（`4C46F0` CScenarioField、`4369D0` EternalTowerField、`4564F0` InfiniteDungeonField）只有兩項：`0x0E=436C40`、`0x14=4C5930`（兩者皆 `LAB_`，bulk 沒有該位址的偽碼；與表 A 相同值，等於重複設定）。
- 其他 Field 建構（`422FF0`、`4BC6E0`、`4BDBA0`、`4C5520`；vtable 名稱需看其呼叫者）共通：`0x14=4C5930`；`4BC6E0`／`4C5520`／`422FF0` 另有 `0x31=4BCA90`、`0x3A=4C58A0`、`0x3B=4C5590`、`0x39=…`。已讀的 `4C58A0`、`4BCA90`、`4C5590` 皆為發送 `FoxUI` 事件（`FUN_0058AAD0(0xF426A／F4267／F4268)`）的 UI 處理，`4BC930` 設 `[scene+0xBD54/+0xBD58]`；**沒有位置同步相關**（【bulk】）。
- → **T09 的位置同步全走表 A（基底 Scene 建構 `4ADD50`）；Field 類 Scene 的表 B 不覆寫位置相關索引**（依 bulk 解析；`436C40`／`4C5930` 兩個 LAB 未見偽碼，仍以機器碼為準，【未知】內容）。

## 六、附錄：表 A 全 101 項（`4ADD50` 偽碼逐項解析；索引→處理位址；未標 `FUN_` 的 `LAB_` 為無函式界定的位址）
| 索引 | 處理 |
| --- | --- |
| 0x0 | 4AFAF0 |
| 0x1 | 4AFB80 |
| 0x6 | 4B7D30 |
| 0x7 | 4AE4D0 |
| 0x8 | 4AF530 |
| 0xa | 4AF920 |
| 0xb | 4AFE60 |
| 0xc | 4B0130 |
| 0xd | 4B01C0 |
| 0xe | 436C40 |
| 0xf | 4B19D0 |
| 0x10 | 4B1A30 |
| 0x11 | 4B1A70 |
| 0x12 | 4B24F0 |
| 0x14 | 4C5930 |
| 0x15 | 4B2620 |
| 0x16 | 4AFB80 |
| 0x18 | 4B2730 |
| 0x1a | 4B28D0 |
| 0x1b | 4AE380 |
| 0x21 | 4B2CD0 |
| 0x22 | 4B3040 |
| 0x26 | 4B3060 |
| 0x27 | 4B2AF0 |
| 0x28 | 4B1BD0 |
| 0x30 | 4B3760 |
| 0x34 | 4B3090 |
| 0x38 | 4B1BF0 |
| 0x41 | 4B2310 |
| 0x42 | 4B2190 |
| 0x43 | 4B1A90 |
| 0x48 | 4B32E0 |
| 0x49 | 4B3350 |
| 0x4b | 4B34F0 |
| 0x4d | 4B3510 |
| 0x4e | 4B3570 |
| 0x50 | 4B3600 |
| 0x51 | 4B3710 |
| 0x5c | 4B3DA0 |
| 0x5e | 4B3C10 |
| 0x63 | 4B3EE0 |
| 0x6c | 4B4050 |
| 0x6d | 4B40E0 |
| 0x73 | 4B4400 |
| 0x75 | 4B6840 |
| 0x76 | 4B4380 |
| 0x79 | 4B44C0 |
| 0x7f | 4B23C0 |
| 0x82 | 4B44E0 |
| 0x91 | 4B45B0 |
| 0x94 | 4AF1F0 |
| 0x95 | 4B1AB0 |
| 0x96 | 4B1BB0 |
| 0x97 | 4B4CC0 |
| 0x9c | 4B6B90 |
| 0x9e | 4B7200 |
| 0xa4 | 4B4D80 |
| 0xa5 | 4B53F0 |
| 0xaf | 4B03D0 |
| 0xb1 | 4B5900 |
| 0xb6 | 4B5DD0 |
| 0xb7 | 4B5E50 |
| 0xba | 4B49D0 |
| 0xc7 | 4B5FA0 |
| 0xc8 | 4B5F40 |
| 0xc9 | 4B5F80 |
| 0xca | 4B5F10 |
| 0xcb | 4B5F30 |
| 0xcc | 4B5F60 |
| 0xcd | 4B5FD0 |
| 0xce | 4B5FF0 |
| 0xcf | 4B6010 |
| 0xd0 | 4B6030 |
| 0xd8 | 4B6040 |
| 0xdb | 4B6050 |
| 0xeb | 4B6190 |
| 0xec | 4B6200 |
| 0xed | 4B5C10 |
| 0xee | 4B6290 |
| 0x111 | 4B44C0 |
| 0x115 | 4B63E0 |
| 0x116 | 4B6610 |
| 0x117 | 4B6580 |
| 0x118 | 4B67B0 |
| 0x119 | 495270 |
| 0x11d | 4B3060 |
| 0x12a | 4B1A00 |
| 0x136 | 4B6A30 |
| 0x13e | 4AEDB0 |
| 0x13f | 4B1940 |
| 0x145 | 4B6AB0 |
| 0x149 | 4B6D00 |
| 0x14b | 4B6F70 |
| 0x14f | 4B6FF0 |
| 0x151 | 4B72E0 |
| 0x152 | 4B7540 |
| 0x153 | 4B7950 |
| 0x154 | 4B7620 |
| 0x155 | 4B7790 |
| 0x156 | 4B78A0 |
| 0x158 | 4B7BA0 |
- 表 A 有 0xBD5 項，預設 `{4B7D40, BF2375}`；上表為被覆寫的 101 項（含 0x06＝`4B7D30` 的空處理）。與先前 `handler_table.json`（99 項）相比，補上 idx 0x01(4AFB80)、0x16(4AFB80)。

## 差異（對先前記錄）
- 修正：0x94 → CBullet；`C557F8` → 0.01；`4CA890` 是 Update 的一部分，不是獨立入口。
- 新增：Actor 類別樹與 vtable；速度公式；速度參數封包（索引 0 + param 5/6）；索引 0x07／0x0C／0x0D／0x21 的角色；表 A 完整清單；表 B 全部 Scene。
- 確認：`vtbl+0x54` 不可通行就不動；0x16 與 0x01 同一函式。

## 尚未確認
- `[+0xD0]`、`[+0xCC]` 的伺服器端數值；`param` 1–4、0x17、0x19、0x1D、0x1E 的語意。
- `[singleton+0x1360]=30` 是否為更新率（`6DF1B0` 的呼叫者未查）。
- `4D1AE0`（CMonster Update）無偽碼檔（bulk 以 `0x4d1af0` 起算，疑為位址偏移）；CMonster／CNPC 的逐幀是否同樣經 `4C8580` 未驗。
- 英雄的 `[+0xE2] bit15` 與 `[+0xE4]` 何時由 `546100` 輸入寫入（目前只知 0x0B 封包會寫）。
- `436C40`、`4C5930` 的實際處理。
- `.bnd` 一格對應的座標單位（需讀 `.bnd` 檔數值）。

## 建議
- 值得提交：`kr-temp-roy/`（T09；T06/T07 側記：`4F5640` 解析 `MAPLIST/trigger/bound`，`4B9090` GameMode 切換）。
- 下一步（T09）：(1) 讀 `4C8B90` 的子物件通知與 `4CE7F0` 其他 param；(2) 用 bulk 追 `546100` 英雄輸入 → `[+0xE2]/[+0xE4]` 的寫入者（`4CA890` 讀它）；(3) 查 `6DF1B0` 呼叫者確認 30 的含義。
