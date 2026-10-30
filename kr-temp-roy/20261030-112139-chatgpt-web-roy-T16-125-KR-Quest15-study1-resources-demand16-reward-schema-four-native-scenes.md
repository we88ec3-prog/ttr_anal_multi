# T16-125 — Quest15／①：資源前置、QuestInfo parser→Record→候選、獎勵欄位映射與四段原生劇情腳本（KR BIN-first）

- 作者：`chatgpt-web roy`，生成時刻 `2026-10-30T11:21:39.135415+08:00`，正式段號 **T16-125**（接 T16-124）。
- **研究定位**：Quest15 **五項中的 ① 資源／前置與資源消費路徑**；②NPC真正互動、③完整 C→S、④S→C/UI、⑤Quest15後續與村莊可玩，仍為各自後續研究。此次沒有把「Quest15 全部完成／真實可玩」納入 ①。
- **靜態目標**：核對 Quest15 的 ID/type/town/field/level/giver/finisher/subtype/Demand 等資料來源、直接辨認 Scene 1–4 中關聯 NPC、map 與 callback，追查 BIN QuestInfo loader 如何保存 Demand/reward 等欄位、誰消費這些欄位，以便為接下來 ②～⑤ 建立精確 Client 邊界。
- **判定**：**Quest15-① 的 Client 資源＋載入／記憶體消費有界完成**；Quest15 的某些獎勵實際數值在本次可取得原始證據不足，仍分級為「先前筆記聲稱、待直取原件複核」。這個資料缺口不妨礙已證的資源 schema／Demand gate，也不能以推測填補。
- KR 原件 SHA256：`Tartaros.bin` `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Table.stp` `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`Event.stp` `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。四檔本次均實際存在並重新雜湊。**原件唯讀，未啟動/patch。**
- PE `.text` raw 映射：ImageBase `0x400000`、`.text` RVA `0x1000` / raw `0x400`，因此 text raw = VA `-0x400C00`；`.rdata` VA `0xBD2000` / raw `0x7D0600`。本次將原始 text bytes 按此映射送入 x86-32 objdump；所有附錄切片均有 VA/raw/length/hash。
- GitHub：工作分支 `t16/roy/chatgpt-web`。當次開工檢查 main `057fa32ff2ef5c347e7b30d269a18a5fcba5daa8`，分支 ahead12/behind27（主線持續變更；同一 ChatGPT 對話**不再次自動 main→T16 Merge**）。此值為研究開工時間的 snapshot，而非宣稱提交時仍是最新。
- `main` 的 T16 收件箱 **無 S00 RR**；T01 README 有 **`T01-RETURN-T16-117-Q16-MODE2-C2S36-001 — NEEDS_FIX`**。後者已在 T16-121/122 原稿有反證，但須保留117舊稿並另外正式 erratum＋READY_FOR_REVIEW（T01 再複驗），本段因使用者明確指定 Quest15-① 而**記錄延後，不虛稱已修復**。T01 的其它43筆為歷史處置；不可用整篇 FULL-PASS 替代本段。
- `shared/verified-knowledge/README.md` 已查，只含既有的限域已審子主張，不包含整個 Q15；按 02/03 政策復用 T16-118、124 的有界事實並在本段定向回到 BIN／Event 原件補證。
- **本原稿屬提交前內容**。GitHub commit 和 blob SHA 以提交後連接器遠端讀回為準；不在原稿中預填不存在的 hash。

## 1. 驗收問題與實際結論

| ① 必須回答 | 本次結果 | 界線 |
|---|---|---|
| Quest15 主要 XML 欄位與 `Demand16` | **先前 Git 原始 XML 擷取的逐字片段＋此次 native parser/consumer 對欄位的機械碼驗證** | `Table.stp` 是 STPD 容器，本次未重新成功提取 `QuestInfo.xml` 全檔；不能稱 Quest15 全局唯一或所有獎勵已複驗 |
| `Demands/Demand` 在記憶體的布局 | **已證**：loader 讀 `id` 數值為 DWORD vector，透過 `0x5064D0` 搬移，consumer 每 DWORD 與 owner 前置 WORD key 比較 | 允許 Q15 candidate 的必要條件，不是 Server 官方法規 |
| 獎勵種類在 native record 的映射 | **已證**：type2→record+0x88，type4→record+0x7C；6-entry 原生 jump table | schema 可證、特定 Q15 值需原 XML 直接再確認；不等於實際給獎 |
| Q15 的原生劇情腳本、NPC/場景資源 | **直接 Event.stp XOR-FF 原始 bytes 擷取**四段 Scene1–4；Scene1/2 `CreateObject NPC10338`，Scene3 `10047` | 只代表資源腳本內容，不代表原版 Server 已切場景或玩家已接任務 |
| `town5` / `Demand16` 最後誰使用 | **已證**：owner 候選重建、前置 key gating、town selector 等；`0x500A00` type2+giver filter 在上段已證，本段定向交叉核驗 | 仍需等級/排除/重算時機及候選 first-order 等 gate，不能聲稱自動接取成功 |

## 2. 來源分級、不可混同的命名空間

### 2.1 Quest15 XML：先前完整來源的**有限擷取**，非本輪 Table 重新解包

T16-118 保留的、來自早期 T16-112／T16-117 分析的 XML 逐字片段：

```xml
<Quest id="15" type="2" town="5" field="19" level="1" giver="10338" finisher="10338" subtype="1" subject="핀더스 마을로">
  <Demands><Demand id="16" /></Demands>
</Quest>
```

原版 Git evidence index：`kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`，先前 blob `1c86c9ce4f2422f84269ed9eb641202fedb9fb63`。本輪 connector 試讀時雖回傳此 blob SHA，但其 `content` 仍為空；故**上面是有出處的早期擷取，不冒稱本輪已讀大原件內容**。該有限擷取顯示 Quest15 `id15,type2,town5,field19,level1,giver/finisher10338,subtype1,Demand16`；沒有在這段中明列 `RewardsEtc`。

**重要資料品質區分**：T16-124 摘要表另曾列出 Quest15 `Reward type2 value2800、type4 value468`；本次在可直接讀取的 XML 擷取內未見其 `<RewardsEtc>` 節點，也未能解包 Table 原始 XML 全文來確證這兩個值到底屬該 Quest 的 RewardsEtc、另一段 data、或之前的外部摘要。因此這兩個**數字屬「前段報告記錄、原件未在本段重新確證」**；不捏造 `<Reward>` XML 行、也不把 value2800／468 當成 Server 支付內容。本段可**獨立驗證 parser type2/type4 會落在哪個 record offset**。

「Quest15」任務鍵、「NPC10338」任務 giver、「town5」候選的世界 selector、「field19」XML 欄位、SceneList `(questIdx15,scene1..4)`、Lua `OpenTalkScene(3,x)`、地圖 `Square03D.fld`／`town001D.map`，是多個不同索引／命名空間。相同數字並非連線證據；本段對 Lua 中的原生 `CreateObject(...,10338,...)` 是**資源與 giver 值相符**的新直接交叉證據，但還不足以證明 runtime 點擊事件的具體 producer。

### 2.2 Event.stp 原件 XOR-FF 可直接閱讀；Table.stp 不同

兩檔頭四 bytes 均為 ASCII `STPD`；`Event.stp` 嵌有大量原始 Lua/字串區域，可在**局部區域逐 byte XOR 0xFF** 後讀到完整 `-- Quest #15 / Scene #n` 與函式正文。此處的 decoded offset 是 **Event.stp 原始容器 file offset**，不是 PE 虛擬位址，也不是 Lua bytecode 的 memory VA。`Table.stp` 同樣有 STPD header，但 QuestInfo XML 內容不是這種簡單整檔 XOR-FF 即得，不能將 Event 可讀能力推廣為已成功 Table 解包。

## 3. Quest15 四段原生 Scene 腳本逐檔證據（本輪從 Event.stp 直接擷取）

| 場景 | Lua 函式 | Event 原 raw 範圍 | 解碼長度/SHA256 | 地圖／NPC 資源 |
|---|---|---|---|---|
| 1 | `Square_Tutorial01` | `0x96943E..0x969685` | 583 bytes; `ff7cdb9556a8043d2cec7f23dc4f4a4c83340857102867ba540ca4619dbc6764` | Square03D.fld；NPC10338=True，物件10047=False |
| 2 | `scenario_tuto1_1` | `0x96883E..0x968C2F` | 1009 bytes; `92350b2327a7f6f3a127402bd1f9a33065758d11126be53d72528fae027edb8d` | Square03D.fld；NPC10338=True，物件10047=False |
| 3 | `pindos_talkevent` | `0x8C1C3E..0x8C2256` | 1560 bytes; `81746ec045328fb0abdf9dbe4eba4023d653e851463db3d0a714bafec9cffe91` | town001D.map；NPC10338=False，物件10047=True |
| 4 | `scenario_tuto2_1` | `0x96903E..0x9691B8` | 378 bytes; `9afbe28bfb9c9713fd132726a5814f65aaf4e3baae7046676bac44518f214a3e` | 無 LoadMap；NPC10338=False，物件10047=False |

**本段新增的關鍵負正對照**：Scene1、Scene2 的 Lua `CreateObject(...,10338,...)` 與 QuestInfo `giver=finisher=10338` 符合，且都呼叫 `LoadMap("Square03D.fld")`。Scene3 改用 `LoadMap("town001D.map")` 並建立不同 object ID `10047`，因此不能把 Scene3 的10047叫作 Quest15 giver，也不能用 town5 的整數 5 直接等號 town001D 的地圖名。Scene4 主要是轉場狀態，沒有前兩段的 NPC10338 建立。

### Scene 1 — `Square_Tutorial01`

- 原始 STPD 容器 offset `0x96943E`，XOR-FF 解碼至 `0x969685`（end exclusive）；SHA256 `ff7cdb9556a8043d2cec7f23dc4f4a4c83340857102867ba540ca4619dbc6764`。

```lua
-- Quest #15 / Scene #1 - Function Square_Tutorial01
function Square_Tutorial01()
	SetTransitionType(2)
	LoadMap("Square03D.fld")
	CreateObject(1, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	OpenTalkScene(3, 22)
	Q.DeleteAllObject()
	RestoreMap()
end
```

### Scene 2 — `scenario_tuto1_1`

- 原始 STPD 容器 offset `0x96883E`，XOR-FF 解碼至 `0x968C2F`（end exclusive）；SHA256 `92350b2327a7f6f3a127402bd1f9a33065758d11126be53d72528fae027edb8d`。

```lua
-- Quest #15 / Scene #2 - Function scenario_tuto1_1
function scenario_tuto1_1()
	SetTransitionType(2)
	LoadMap("Square03D.fld")
	CreateObject(0, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	CreateObject(1, 1478, 864.00, 1032.00, 128, 0, FALSE, 1, 1)
	CreateObject(2, 1479, 869.00, 1027.00, 128, 0, FALSE, 1, 10)
	CreateObject(3, 1480, 869.00, 1042.00, 0, 0, FALSE, 1, 19)
	CreateObject(4, 1481, 874.00, 1032.00, 128, 0, FALSE, 1, 28)
	OpenTalkScene(3, 15)
	OpenTalkScene(3, 16)
	OpenTalkScene(3, 17)
	OpenTalkScene(3, 25)
	Q.DeleteAllObject()
	RestoreMap()
end
```

### Scene 3 — `pindos_talkevent`

- 原始 STPD 容器 offset `0x8C1C3E`，XOR-FF 解碼至 `0x8C2256`（end exclusive）；SHA256 `81746ec045328fb0abdf9dbe4eba4023d653e851463db3d0a714bafec9cffe91`。

```lua
-- Quest #15 / Scene #3 - Function pindos_talkevent
function pindos_talkevent()
	SetTransitionType(2)
	LoadMap("town001D.map")
	CreateObject(0, 1478, 751.00, 416.00, 128, 0, FALSE, 1, 1)
	CreateObject(1, 1479, 760.00, 416.00, 128, 0, FALSE, 1, 10)
	CreateObject(2, 1480, 755.00, 429.00, 0, 0, FALSE, 1, 19)
	CreateObject(3, 1481, 755.00, 421.00, 128, 0, FALSE, 1, 28)
	CreateObject(4, 10047, 734.00, 744.00, 0, 0, FALSE, 0, 0)
	OpenTalkScene(3, 18)
	OpenTalkScene(3, 24)
	OpenTalkScene(3, 20)
	OpenTalkScene(3, 21)
	ClearObjects()
	DoProlog(1)
	Q.DeleteAllObject()
	RestoreMap()
end
```

### Scene 4 — `scenario_tuto2_1`

- 原始 STPD 容器 offset `0x96903E`，XOR-FF 解碼至 `0x9691B8`（end exclusive）；SHA256 `9afbe28bfb9c9713fd132726a5814f65aaf4e3baae7046676bac44518f214a3e`。

```lua
-- Quest #15 / Scene #4 - Function scenario_tuto2_1
function scenario_tuto2_1()
	SetTransitionType(0)
	LoadMap("")
	Q.DeleteAllObject()
	RestoreMap()
end
```

### 3.5 劇情腳本與任務發布者之間的證據邊界

- **可確證**：四段 `Quest #15 / Scene #n` comment／function、兩段 Lua 在場景中建立物件 ID10338、Scene3 載入 town001D 地圖並建立10047、Scene4 與前3段配置不同。
- **不能確證**：`SceneList.xml questIdx15` 由哪個原始 Server business opcode 選到四段之一；`CreateObject10338` 在實機一定成為可點擊 NPC；`OpenTalkScene(3,18)` 裡的 `3` 是否等於 Quest type3；QuestID15 的前置 key 已判定後必然呼叫哪個 Lua；原版 Server 自動核發場景結果。
- **命名精度**：`OpenTalkScene(3,18/24/20/21)` 是 Lua 函式呼叫的**兩個直接參數**，不自動把第二參數當 quest id 或把第一參數當 quest type。

## 4. 原生 QuestInfo loader：可由 BIN 支持的資料映射

### 4.1 XML 檔名與 parser 入口

`0x504780` 讀取 `0xC0DB48` 的 `Table/QuestInfo.xml` 字串並呼叫 `0x72EE30`，再於 `0x504831` 查 `QuestInfo` 根節點。原始 `.rdata` 中 `0xC0DB94`=`subtype`、`0xC0DB9C`=`level`、`0xC0DBA4`=`giver`、`0xC0DBAC`=`finisher`、`0xC0DBB8`=`town`、`0xC0DBC0`=`field`、`0xC0DBC8`=`subject`、`0xC0DBF8`=`Demands`、`0xC0DC00`=`Demand`、`0xC0DC08`=`RewardsEtc`、`0xC0DC14`=`Reward`、`0xC0DC1C`=`value`。字串來源依 PE `.rdata` 映射實際讀出，不是模型自行取名。

XML numeric parse 分段經 `0x7300A0` 查 attribute，再用 `0x8917B4` 將文字轉為整數；沒有 attribute 時多個分支寫零，缺欄位不能被當作任意任務存在。原始 `0x4FF920` 初始化 QuestRecord 多個 scalar =0，包括後續 reward slots；因此若未 parse 的 reward type，不應沿用其它任務舊值。

### 4.2 Demand vector 自 XML 穿越記憶體複製

`0x504BC5..0x504CBD` 使用 XML `Demands`/`Demand`、`id`、`0x8917B4` 數字解碼，元素每次增 `4` bytes，形成 `QuestRecord+0x10` DWORD vector；`0x5053FB..0x50542D` 準備 record 臨時物件並呼叫 `0x5064D0` 搬移至 map 插入物件。`0x506509..0x506517` 以 `[src+0x10]` 和 `[dst+0x10]` 呼叫 `0x7E8A90` vector copy；`0x503D20` 以 DWORD Quest key 在 QuestInfo map 中搜尋；`0x500652` 在找到的 map node 中以 `[node+0x20]..[node+0x24]` 讀 demand（因 node+0x10 起為 record payload）。

**資料寬度**：Demand key 是 **DWORD**；owner `+0x5EB0/+0x5EB4` 前置向量是 **WORD**。`0x500690 movzx ebx,WORD PTR [eax]`、`0x500693 cmp ebx,esi` 以零擴展 WORD 與需求 DWORD 比較。對 Quest15 的 Demand16=16，此寬度映射本身無歧義；若後續任務需求 ID 超過 WORD 可表示範圍，不得未證就說 client 支援全值域。

### 4.3 Reward type 映射：type4 真正落在 +0x7C，而非 +0x88

`0x504CCD..0x504D23` 先查 `RewardsEtc`/`Reward`，每一 Reward 的 `type` 解碼成 EBX，`value` 解碼成 EAX。`0x504D96 lea ecx,[ebx-1]`，`0x504D99 cmp ecx,5` 後跳 `jmp [0x505554 + ecx*4]`。BIN 直接讀得表：

| Reward type | switch target | 寫入臨時 record stack offset | 換算 QuestRecord relative offset |
|---|---|---|---|
| 1 | `0x504DE2` | `esp+0xE4` | `+0x80` |
| **2** | **`0x504DF4`** | **`esp+0xEC`** | **`+0x88`** |
| 3 | `0x504DEB` | `esp+0xE8` | `+0x84` |
| **4** | **`0x504DFD`** | **`esp+0xE0`** | **`+0x7C`** |
| 5 | `0x504E06` | `esp+0xF0` | `+0x8C` |
| 6 | `0x504E0F` | `esp+0xF4` | `+0x90` |

以上換算只在該函式存活且使用「record temp base = esp+0x64」的觀察點成立，並由 `0x506596..0x5065E6` 明確把 `src+0x78..0x90` 個別 DWORD 複製到 `dest+same` 來獨立核對。若資料有 `<Reward type="2" value="2800"/>` 和 `<Reward type="4" value="468"/>`，正常解析後**條件式**分別使 record+0x88=2800、record+0x7C=468；**本次不能由 parser 分支反推出 Quest15 確實擁有這兩項 XML 節點**，亦不可把 2800 或 468 當作 Client 已發獎。

**額外反例**：type0 或 type7+ 不會在此 switch 進入 1..6 的賦值 case；因 `lea ecx,[ebx-1]` 與 `cmp ecx,5 / ja 0x504E16`，不應把所有 Reward type 解析成同一欄位。

### 4.4 Map copy、壽命與讀者

`0x4FF920` 初始化 temp QuestRecord；`0x5053FB` 調 `0x5064D0` copy；`0x506310` 將 QuestInfo 記錄插入 map；`0x503D20` 進行 ID key 查找。copy helper 還移轉 `+0x4C` 小字串、`+0x68` 輔助資料、Demand vector 及 rewards scalar；因此不能只複製 ID/type/town 等 scalar 就聲稱得到可被 UI/候選消費的有效 QuestInfo 記錄。相關函式可能有配置失敗／例外路徑，本段只對**正常成功**做 schema 結論，不保證每次資源載入一定成功。

## 5. 來源到玩家候選：Quest15 的必要條件與反例

### 5.1 `Demand16` 與 key16 的有界條件

S→C index0x74 由 T16-123 已確認 `0x503400` 逐筆插入 WORD key，並呼叫 `0x500240` 重建候選。`0x500652..0x5006AE` 每次從 QuestInfo map 找 Demand vector，要求每一個 DWORD Demand 在 owner `+0x5EB0..+0x5EB4` WORD key vector 中找到；若缺 `16`，Q15 應被排除；若包含 `16`，該個 demand gate 通過，**還不足以證明候選入列成功**。`0x5004C4` 附近另排除已在前置 key 清單內的 quest 自身；因此 key16 的效果還包含 Q16 本身在特定重算路徑的自我排除。

### 5.2 Town/level/排除與重算時機

先前 T16-124 直接 BIN 調查：Quest15 資源 town5；Client 世界 owner selector `0x40F060()+0x8C = 0xFAB1BC`，S→C index `0x38` 某些 subtype 可寫 selector5。**先送 `0x74(16)` 且當下仍 town0**，可能在重算時排除 Q15；後續 selector 切 town5 但若該 subtype 未重算，也不會立刻保證出現。反之 town5 已在狀態中，`0x74(16)` 再觸發重建，兩 gate 才可能同時通過；依然要看 `level1`、20-slot exclusions、先前 key 等。這是 Client 靜態 if/else 分支，不等於 Server 必須採行單一時序。

### 5.3 `giver10338` 的 type2 NPC 候選

已驗 T16-124：NPC 事件 outer `0x105BD` action `0x6A7`、nested `0x105BF` 之 `+0x14` 為 giver selector；`0x5B9340→0x5008B0→0x500A00` 遍歷 candidate vector，依 `QuestRecord+0x28` giver 與 `QuestRecord+0x04` type2 篩選；**返回第一個命中者的 WORD key**，不是強制 ID15；不能把 `Scene1/2 CreateObject10338` 直接等同這條 native event 已在 runtime 觸發。此次 ① 只建立資料／資源→consumer 結構，NPC實際點擊派送是 ②。

## 6. Player／Server 介面矩陣（為後續②～⑤建立可測邊界）

| 情境 | Client 原生所需輸入或狀態 | 已確認的 Client 結果 | 尚待補證／不能說 |
|---|---|---|---|
| Quest15 初始資源載入 | QuestInfo XML parser 成功建立 id15 record | type2、Demand vector/selector fields 可供 map lookup | Table 原 XML 本輪未重讀，載入成功時機及全表唯一性 |
| 尚未 key16，town5 | 前置 WORD vector 不含16 | Q15 Demand16 gate 失敗 | 其他 UI 個別路徑不代表同一候選結果 |
| key16，town0 | key16 存在但 selector town0 | Q15 town gate 不能通過 | 不等於 Server 尚未完成任務 |
| key16，town5，重算 | town5、前置16、level/exclusions 都允許 | Q15 **可**加入 candidate WORD vector | first type2 match 若有別的任務可能不是15 |
| Lua Quest15 Scene1/2 被正式派送 | 需尚未查明的 runtime script selection | 腳本自述 Quest15，產生 NPC10338 in Square03D | 不等於玩家 NPC click 已送出 C→S |
| Lua Quest15 Scene3 被正式派送 | 需 Script dispatch 及資源可用 | 載入 town001D，場景中使用 object10047、Prolog 等 | object10047≠giver10338；不得聲稱 town5 即 town001D |
| NPC10338 玩家點擊 | 特定 native event/selector/候選狀態 | 由上一段可條件式回傳 first type2 候選 ID15 | 完整事件 producer、0x1C/0x3F 時序、Server 反應仍屬Quest15②③ |
| 若收到 S→C 0x40(15,state0) | 由 T16-121/124 已定位 | `0xF438B`→mode2 TalkBox（必要條件下） | 不能證明原版 Server 是在接受 `0x3F(15)` 後必然發送，屬④ |
| Quest15 被正式判完成／轉場 | 要求正式 Server policy、scene state及其他跨 Task | ①沒有這條實際 runtime 路徑結論 | T07/T14/T15/Server 設計／待遊玩驗證 |

## 7. 反證、修正、責任分配

**原生已確認（本輪增量）**：四段 Quest15 Lua 腳本的原始 XOR-FF bytes/offset/hash；Scene1/2 直接 `CreateObject10338`、Scene3 `CreateObject10047`；parser `type=4` 對應 `record+0x7C` 而 type2 對應 `+0x88`；六項 reward switch target 並且 copy helper 複製這些 scalar；Demand DWORD vector 與 owner WORD list 的比對。

**繼承並有限復用**：早期有來源 QuestInfo XML Q15 片段與 T16-118 記錄的 Demand schema；T16-124 的 `0x38` town selector、Q15 NPC conditional event、`0x40` UI/C2S／S2C 邊界。不把該摘要再宣稱為本輪新破解原件。

**Client 待逆向**：`SceneList.xml` 的 native dispatch 與 Scene1–4 的實際觸發對應、NPC10338 runtime actor→事件 producer、true UI list/point-click callback、Quest15的真正 accept/turnin C→S、Quest15 S→C 各狀態通知/結果與 reward UI、NPC與地圖名稱之 script/context 橋。請在 Quest15-②～⑤ 以新 BIN evidence 追；本段只構建①必要的資料結構與資源。

**Server 待開發**：任務鍵16/Quest15前置條件、town selector5的發布策略、任務接受/完成/給獎/存檔；不要從 Client 的 reward metadata 推斷官方 Server 內部 DB 交易或對 C2S 的必然 ACK。

**跨 Task 待整合**：T02 完整 framing/入站邊界、T07 劇情場景 runtime dispatch、T14 quest success/scene completion、T15 持久化、T03/T04 登入 snapshot、T01 返修正式提報。S00 只形成 DRAFT 的相容契約，非 Server 執行程式。

**待遊玩驗證**：真實 NPC 出現位置與點擊時序、Quest15 解鎖後能否點擊、mode2 UI 真實畫面、獎勵數值實際變化、Scene1–4 實際播放次序、保存／重登恢復。

**重要修正**：不能沿用 T16-117 D.1/D.3「mode2 TalkBox 操作會直接 `F4402→0x636E10→0x36(QID16)`」的已被 T01 退回錯誤主張；T16-121/122 已建立 mode1/2 分支、`0x36` 另一個 producer，本稿與 Quest15 後續一律遵守此反證。正式 T01 erratum／固定 ID 由後續作業另行提交，此次使用者明確指定先 Quest15-①，不以本報取代修復提交。

## 8. 可接續的研究問題與下一正式段入口

Quest15-① 此處的 Client 原件研究足以回答**資源/前置/schema/腳本中 giver 的直接引用**，故標記有界完成，不是對「所有 Quest15 reward 值已重新拿到原始 XML」的更廣主張。仍有兩類解除條件：①取得可按任務 ID15 定向提取的原始 `Table/QuestInfo.xml`，比較 Q15 奬勵數值 2800/468 是否真正屬於該節點；②取得 Event.stp `SceneList.xml` 的直接全文或 Scene dispatch 具體函式以建立四段 Lua 的 runtime 索引。

**下一段（以遠端已提交段號為準）：T16-126／Quest15-②**，從 Scene1/2 Lua `CreateObject10338`、npc event builder、控制器與 type2 first candidate，往 UI 真正點擊事件與 talk box 的 caller 溯源。若 T01 NEEDS_FIX 高優先仍存在，另先補 T16-117 指名 erratum 並在 T16 分支文件提供 T01 可審的新 Git blob。Quest15 ③C→S、④S→C/status/UI、⑤後續完整城鎮/劇情尚未完成。

## 9. 附錄 A：由原始 KR BIN 重驗的反組譯切片與 SHA256

以下每段均為 `Tartaros.bin` 經 VA→raw 映射的第一手靜態證據，保留重要分支、真實 bytes、caller/callee 與負證：跳表 `.rdata/.text` 等數據不當作指令。被覆述的任務 ID15/16 數值來自先前有來源的 XML 局部摘錄，不把 BIN 的通用 parser 虛構成硬編碼 ID15 的函式。

### QuestRecord 初始化與零值 reward slots

- VA `0x004FF920..0x004FFA12` (右界不含)，raw `0xFED20..0xFEE12`，242 bytes，SHA256 `f02a1b845667bdd3608d4009ba8b15b810a13379db4344f168bc0c4e4c1d1ca1`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  4ff920:	55                   	push   ebp
  4ff921:	8b ec                	mov    ebp,esp
  4ff923:	6a ff                	push   0xffffffff
  4ff925:	68 36 b4 90 00       	push   0x90b436
  4ff92a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ff930:	50                   	push   eax
  4ff931:	83 ec 10             	sub    esp,0x10
  4ff934:	56                   	push   esi
  4ff935:	57                   	push   edi
  4ff936:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ff93b:	33 c5                	xor    eax,ebp
  4ff93d:	50                   	push   eax
  4ff93e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ff941:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ff947:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4ff94a:	33 ff                	xor    edi,edi
  4ff94c:	89 3e                	mov    DWORD PTR [esi],edi
  4ff94e:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  4ff951:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  4ff954:	89 7e 0c             	mov    DWORD PTR [esi+0xc],edi
  4ff957:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  4ff95a:	89 7e 14             	mov    DWORD PTR [esi+0x14],edi
  4ff95d:	89 7e 18             	mov    DWORD PTR [esi+0x18],edi
  4ff960:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4ff963:	89 7e 20             	mov    DWORD PTR [esi+0x20],edi
  4ff966:	89 7e 24             	mov    DWORD PTR [esi+0x24],edi
  4ff969:	89 7e 28             	mov    DWORD PTR [esi+0x28],edi
  4ff96c:	89 7e 2c             	mov    DWORD PTR [esi+0x2c],edi
  4ff96f:	89 7e 30             	mov    DWORD PTR [esi+0x30],edi
  4ff972:	89 7e 34             	mov    DWORD PTR [esi+0x34],edi
  4ff975:	89 7e 38             	mov    DWORD PTR [esi+0x38],edi
  4ff978:	89 7e 3c             	mov    DWORD PTR [esi+0x3c],edi
  4ff97b:	89 7e 40             	mov    DWORD PTR [esi+0x40],edi
  4ff97e:	89 7e 44             	mov    DWORD PTR [esi+0x44],edi
  4ff981:	89 7e 48             	mov    DWORD PTR [esi+0x48],edi
  4ff984:	33 c0                	xor    eax,eax
  4ff986:	c7 46 60 07 00 00 00 	mov    DWORD PTR [esi+0x60],0x7
  4ff98d:	89 7e 5c             	mov    DWORD PTR [esi+0x5c],edi
  4ff990:	66 89 46 4c          	mov    WORD PTR [esi+0x4c],ax
  4ff994:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4ff998:	6a 30                	push   0x30
  4ff99a:	89 7e 70             	mov    DWORD PTR [esi+0x70],edi
  4ff99d:	e8 c6 18 39 00       	call   0x891268
  4ff9a2:	83 c4 04             	add    esp,0x4
  4ff9a5:	3b c7                	cmp    eax,edi
  4ff9a7:	74 6a                	je     0x4ffa13
  4ff9a9:	89 46 6c             	mov    DWORD PTR [esi+0x6c],eax
  4ff9ac:	89 00                	mov    DWORD PTR [eax],eax
  4ff9ae:	8b 46 6c             	mov    eax,DWORD PTR [esi+0x6c]
  4ff9b1:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4ff9b4:	8b 46 6c             	mov    eax,DWORD PTR [esi+0x6c]
  4ff9b7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4ff9ba:	8b 4e 6c             	mov    ecx,DWORD PTR [esi+0x6c]
  4ff9bd:	c6 41 2c 01          	mov    BYTE PTR [ecx+0x2c],0x1
  4ff9c1:	8b 56 6c             	mov    edx,DWORD PTR [esi+0x6c]
  4ff9c4:	c6 42 2d 01          	mov    BYTE PTR [edx+0x2d],0x1
  4ff9c8:	89 7e 78             	mov    DWORD PTR [esi+0x78],edi
  4ff9cb:	89 7e 7c             	mov    DWORD PTR [esi+0x7c],edi
  4ff9ce:	89 be 80 00 00 00    	mov    DWORD PTR [esi+0x80],edi
  4ff9d4:	89 be 84 00 00 00    	mov    DWORD PTR [esi+0x84],edi
  4ff9da:	89 be 88 00 00 00    	mov    DWORD PTR [esi+0x88],edi
  4ff9e0:	89 be 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],edi
  4ff9e6:	89 be 90 00 00 00    	mov    DWORD PTR [esi+0x90],edi
  4ff9ec:	89 be 94 00 00 00    	mov    DWORD PTR [esi+0x94],edi
  4ff9f2:	89 be 98 00 00 00    	mov    DWORD PTR [esi+0x98],edi
  4ff9f8:	89 be 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],edi
  4ff9fe:	8b c6                	mov    eax,esi
  4ffa00:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ffa03:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ffa0a:	59                   	pop    ecx
  4ffa0b:	5f                   	pop    edi
  4ffa0c:	5e                   	pop    esi
  4ffa0d:	8b e5                	mov    esp,ebp
  4ffa0f:	5d                   	pop    ebp
  4ffa10:	c2 04              	ret    0x4
```

### QuestInfo XML 載入與根節點

- VA `0x00504780..0x005048AF` (右界不含)，raw `0x103B80..0x103CAF`，303 bytes，SHA256 `84c9c1b3d259e428c0b08e5f1d3616dd54332088566606b988f2049bce3bb4b1`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84 24 64 02 00 00 	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	ff ff ff ff 
  50485b:	83 c4 04             	add    esp,0x4
  50485e:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  504865:	94 23 bf 00 
  504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  504870:	72 10                	jb     0x504882
  504872:	8b 84 24 78 01 00 00 	mov    eax,DWORD PTR [esp+0x178]
  504879:	50                   	push   eax
  50487a:	e8 8d c9 38 00       	call   0x89120c
  50487f:	83 c4 04             	add    esp,0x4
  504882:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  504889:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504890:	0f 00 00 00 
  504894:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50489b:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  5048a2:	00 
  5048a3:	e8 98 97 22 00       	call   0x72e040
  5048a8:	33 c0                	xor    eax,eax
  5048aa:	e9 29 0c 00 00       	jmp    0x5054d8
```

### XML 基本 attributes 與數字解析

- VA `0x005048BE..0x005049A0` (右界不含)，raw `0x103CBE..0x103DA0`，226 bytes，SHA256 `5546ddb7d1a079a42b222113665a74fafe776db1a74a742f8e6ff01264a05ffd`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  5048be:	8b ff                	mov    edi,edi
  5048c0:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  5048c4:	51                   	push   ecx
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5048ce:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5048d5:	01 
  5048d6:	8b 11                	mov    edx,DWORD PTR [ecx]
  5048d8:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5048db:	ff d0                	call   eax
  5048dd:	8d 78 44             	lea    edi,[eax+0x44]
  5048e0:	68 d0 d1 be 00       	push   0xbed1d0
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  5048ea:	bb 10 00 00 00       	mov    ebx,0x10
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f3:	83 c0 30             	add    eax,0x30
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74 0b                	je     0x50490c
  504901:	50                   	push   eax
  504902:	e8 ad ce 38 00       	call   0x8917b4
  504907:	83 c4 04             	add    esp,0x4
  50490a:	eb 02                	jmp    0x50490e
  50490c:	33 c0                	xor    eax,eax
  50490e:	68 08 b8 bf 00       	push   0xbfb808
  504913:	89 44 24 68          	mov    DWORD PTR [esp+0x68],eax
  504917:	e8 84 b7 22 00       	call   0x7300a0
  50491c:	85 c0                	test   eax,eax
  50491e:	74 19                	je     0x504939
  504920:	83 c0 30             	add    eax,0x30
  504923:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504926:	72 02                	jb     0x50492a
  504928:	8b 00                	mov    eax,DWORD PTR [eax]
  50492a:	85 c0                	test   eax,eax
  50492c:	74 0b                	je     0x504939
  50492e:	50                   	push   eax
  50492f:	e8 80 ce 38 00       	call   0x8917b4
  504934:	83 c4 04             	add    esp,0x4
  504937:	eb 02                	jmp    0x50493b
  504939:	33 c0                	xor    eax,eax
  50493b:	68 94 db c0 00       	push   0xc0db94
  504940:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
  504944:	e8 57 b7 22 00       	call   0x7300a0
  504949:	85 c0                	test   eax,eax
  50494b:	74 19                	je     0x504966
  50494d:	83 c0 30             	add    eax,0x30
  504950:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504953:	72 02                	jb     0x504957
  504955:	8b 00                	mov    eax,DWORD PTR [eax]
  504957:	85 c0                	test   eax,eax
  504959:	74 0b                	je     0x504966
  50495b:	50                   	push   eax
  50495c:	e8 53 ce 38 00       	call   0x8917b4
  504961:	83 c4 04             	add    esp,0x4
  504964:	eb 02                	jmp    0x504968
  504966:	33 c0                	xor    eax,eax
  504968:	68 9c db c0 00       	push   0xc0db9c
  50496d:	89 44 24 70          	mov    DWORD PTR [esp+0x70],eax
  504971:	e8 2a b7 22 00       	call   0x7300a0
  504976:	85 c0                	test   eax,eax
  504978:	74 19                	je     0x504993
  50497a:	83 c0 30             	add    eax,0x30
  50497d:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504980:	72 02                	jb     0x504984
  504982:	8b 00                	mov    eax,DWORD PTR [eax]
  504984:	85 c0                	test   eax,eax
  504986:	74 0b                	je     0x504993
  504988:	50                   	push   eax
  504989:	e8 26 ce 38 00       	call   0x8917b4
  50498e:	83 c4 04             	add    esp,0x4
  504991:	eb 02                	jmp    0x504995
  504993:	33 c0                	xor    eax,eax
  504995:	68 a4 db c0 00       	push   0xc0dba4
  50499a:	89 44 24 74          	mov    DWORD PTR [esp+0x74],eax
  50499e:	e8 fd          	call   0x7300a0
```

### XML town/field/subject 與記憶體 locals

- VA `0x005049C2..0x00504AD8` (右界不含)，raw `0x103DC2..0x103ED8`，278 bytes，SHA256 `d6946996ea384498d55ca657f362ce42610dd9d8971bb8b9eed5a0fa9e1f8594`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  5049c2:	68 ac db c0 00       	push   0xc0dbac
  5049c7:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  5049ce:	e8 cd b6 22 00       	call   0x7300a0
  5049d3:	85 c0                	test   eax,eax
  5049d5:	74 19                	je     0x5049f0
  5049d7:	83 c0 30             	add    eax,0x30
  5049da:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5049dd:	72 02                	jb     0x5049e1
  5049df:	8b 00                	mov    eax,DWORD PTR [eax]
  5049e1:	85 c0                	test   eax,eax
  5049e3:	74 0b                	je     0x5049f0
  5049e5:	50                   	push   eax
  5049e6:	e8 c9 cd 38 00       	call   0x8917b4
  5049eb:	83 c4 04             	add    esp,0x4
  5049ee:	eb 02                	jmp    0x5049f2
  5049f0:	33 c0                	xor    eax,eax
  5049f2:	68 b8 db c0 00       	push   0xc0dbb8
  5049f7:	89 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],eax
  5049fe:	e8 9d b6 22 00       	call   0x7300a0
  504a03:	85 c0                	test   eax,eax
  504a05:	74 19                	je     0x504a20
  504a07:	83 c0 30             	add    eax,0x30
  504a0a:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504a0d:	72 02                	jb     0x504a11
  504a0f:	8b 00                	mov    eax,DWORD PTR [eax]
  504a11:	85 c0                	test   eax,eax
  504a13:	74 0b                	je     0x504a20
  504a15:	50                   	push   eax
  504a16:	e8 99 cd 38 00       	call   0x8917b4
  504a1b:	83 c4 04             	add    esp,0x4
  504a1e:	eb 02                	jmp    0x504a22
  504a20:	33 c0                	xor    eax,eax
  504a22:	68 c0 db c0 00       	push   0xc0dbc0
  504a27:	89 84 24 88 00 00 00 	mov    DWORD PTR [esp+0x88],eax
  504a2e:	e8 6d b6 22 00       	call   0x7300a0
  504a33:	85 c0                	test   eax,eax
  504a35:	74 19                	je     0x504a50
  504a37:	83 c0 30             	add    eax,0x30
  504a3a:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504a3d:	72 02                	jb     0x504a41
  504a3f:	8b 00                	mov    eax,DWORD PTR [eax]
  504a41:	85 c0                	test   eax,eax
  504a43:	74 0b                	je     0x504a50
  504a45:	50                   	push   eax
  504a46:	e8 69 cd 38 00       	call   0x8917b4
  504a4b:	83 c4 04             	add    esp,0x4
  504a4e:	eb 02                	jmp    0x504a52
  504a50:	33 c0                	xor    eax,eax
  504a52:	68 c8 db c0 00       	push   0xc0dbc8
  504a57:	89 84 24 8c 00 00 00 	mov    DWORD PTR [esp+0x8c],eax
  504a5e:	e8 3d b6 22 00       	call   0x7300a0
  504a63:	85 c0                	test   eax,eax
  504a65:	74 0c                	je     0x504a73
  504a67:	39 58 44             	cmp    DWORD PTR [eax+0x44],ebx
  504a6a:	8d 48 30             	lea    ecx,[eax+0x30]
  504a6d:	72 06                	jb     0x504a75
  504a6f:	8b 09                	mov    ecx,DWORD PTR [ecx]
  504a71:	eb 02                	jmp    0x504a75
  504a73:	33 c9                	xor    ecx,ecx
  504a75:	8b c1                	mov    eax,ecx
  504a77:	c7 44 24 5c 0f 00 00 	mov    DWORD PTR [esp+0x5c],0xf
  504a7e:	00 
  504a7f:	c7 44 24 58 00 00 00 	mov    DWORD PTR [esp+0x58],0x0
  504a86:	00 
  504a87:	c6 44 24 48 00       	mov    BYTE PTR [esp+0x48],0x0
  504a8c:	8d 70 01             	lea    esi,[eax+0x1]
  504a8f:	90                   	nop
  504a90:	8a 10                	mov    dl,BYTE PTR [eax]
  504a92:	40                   	inc    eax
  504a93:	84 d2                	test   dl,dl
  504a95:	75 f9                	jne    0x504a90
  504a97:	2b c6                	sub    eax,esi
  504a99:	50                   	push   eax
  504a9a:	51                   	push   ecx
  504a9b:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  504a9f:	e8 cc df ef ff       	call   0x402a70
  504aa4:	8d 4c 24 48          	lea    ecx,[esp+0x48]
  504aa8:	51                   	push   ecx
  504aa9:	8d 84 24 b4 00 00 00 	lea    eax,[esp+0xb4]
  504ab0:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x2
  504ab7:	02 
  504ab8:	e8 73 b6 f3 ff       	call   0x440130
  504abd:	83 c4 04             	add    esp,0x4
  504ac0:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  504ac7:	01 
  504ac8:	39 5c 24 5c          	cmp    DWORD PTR [esp+0x5c],ebx
  504acc:	72 0d                	jb     0x504adb
  504ace:	8b 54 24 48          	mov    edx,DWORD PTR [esp+0x48]
  504ad2:	52                   	push   edx
  504ad3:	e8 34 c7 38 00       	call   0x89120c
```

### AcceptAction/CompleteAction 尋找

- VA `0x00504ADF..0x00504BC5` (右界不含)，raw `0x103EDF..0x103FC5`，230 bytes，SHA256 `4af8c744057cfe28bebfaddf910e316b4f03f7092c1903c3c5e30505a43a9e50`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504adf:	bf d0 db c0 00       	mov    edi,0xc0dbd0
  504ae4:	8b c6                	mov    eax,esi
  504ae6:	e8 75 98 22 00       	call   0x72e360
  504aeb:	85 c0                	test   eax,eax
  504aed:	74 63                	je     0x504b52
  504aef:	8d 78 44             	lea    edi,[eax+0x44]
  504af2:	68 08 b8 bf 00       	push   0xbfb808
  504af7:	e8 a4 b5 22 00       	call   0x7300a0
  504afc:	85 c0                	test   eax,eax
  504afe:	74 19                	je     0x504b19
  504b00:	83 c0 30             	add    eax,0x30
  504b03:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b06:	72 02                	jb     0x504b0a
  504b08:	8b 00                	mov    eax,DWORD PTR [eax]
  504b0a:	85 c0                	test   eax,eax
  504b0c:	74 0b                	je     0x504b19
  504b0e:	50                   	push   eax
  504b0f:	e8 a0 cc 38 00       	call   0x8917b4
  504b14:	83 c4 04             	add    esp,0x4
  504b17:	eb 02                	jmp    0x504b1b
  504b19:	33 c0                	xor    eax,eax
  504b1b:	68 e0 db c0 00       	push   0xc0dbe0
  504b20:	89 84 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],eax
  504b27:	e8 74 b5 22 00       	call   0x7300a0
  504b2c:	85 c0                	test   eax,eax
  504b2e:	74 19                	je     0x504b49
  504b30:	83 c0 30             	add    eax,0x30
  504b33:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b36:	72 02                	jb     0x504b3a
  504b38:	8b 00                	mov    eax,DWORD PTR [eax]
  504b3a:	85 c0                	test   eax,eax
  504b3c:	74 0b                	je     0x504b49
  504b3e:	50                   	push   eax
  504b3f:	e8 70 cc 38 00       	call   0x8917b4
  504b44:	83 c4 04             	add    esp,0x4
  504b47:	eb 02                	jmp    0x504b4b
  504b49:	33 c0                	xor    eax,eax
  504b4b:	89 84 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],eax
  504b52:	bf e8 db c0 00       	mov    edi,0xc0dbe8
  504b57:	8b c6                	mov    eax,esi
  504b59:	e8 02 98 22 00       	call   0x72e360
  504b5e:	85 c0                	test   eax,eax
  504b60:	74 63                	je     0x504bc5
  504b62:	8d 78 44             	lea    edi,[eax+0x44]
  504b65:	68 08 b8 bf 00       	push   0xbfb808
  504b6a:	e8 31 b5 22 00       	call   0x7300a0
  504b6f:	85 c0                	test   eax,eax
  504b71:	74 19                	je     0x504b8c
  504b73:	83 c0 30             	add    eax,0x30
  504b76:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b79:	72 02                	jb     0x504b7d
  504b7b:	8b 00                	mov    eax,DWORD PTR [eax]
  504b7d:	85 c0                	test   eax,eax
  504b7f:	74 0b                	je     0x504b8c
  504b81:	50                   	push   eax
  504b82:	e8 2d cc 38 00       	call   0x8917b4
  504b87:	83 c4 04             	add    esp,0x4
  504b8a:	eb 02                	jmp    0x504b8e
  504b8c:	33 c0                	xor    eax,eax
  504b8e:	68 e0 db c0 00       	push   0xc0dbe0
  504b93:	89 84 24 ac 00 00 00 	mov    DWORD PTR [esp+0xac],eax
  504b9a:	e8 01 b5 22 00       	call   0x7300a0
  504b9f:	85 c0                	test   eax,eax
  504ba1:	74 19                	je     0x504bbc
  504ba3:	83 c0 30             	add    eax,0x30
  504ba6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504ba9:	72 02                	jb     0x504bad
  504bab:	8b 00                	mov    eax,DWORD PTR [eax]
  504bad:	85 c0                	test   eax,eax
  504baf:	74 0b                	je     0x504bbc
  504bb1:	50                   	push   eax
  504bb2:	e8 fd cb 38 00       	call   0x8917b4
  504bb7:	83 c4 04             	add    esp,0x4
  504bba:	eb 02                	jmp    0x504bbe
  504bbc:	33 c0                	xor    eax,eax
  504bbe:	89 84 24 ac 00 00 00 	mov    DWORD PTR [esp+0xac],eax
```

### Demands->Demand id 數值與 DWORD vector

- VA `0x00504BC5..0x00504CCD` (右界不含)，raw `0x103FC5..0x1040CD`，264 bytes，SHA256 `d0af28e9668b0fdfcbe1e0062be95e0f90e657735923060e19a6ead3a73f6d35`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504bc5:	68 f8 db c0 00       	push   0xc0dbf8
  504bca:	8b c6                	mov    eax,esi
  504bcc:	e8 0f 97 22 00       	call   0x72e2e0
  504bd1:	85 c0                	test   eax,eax
  504bd3:	0f 84 f4 00 00 00    	je     0x504ccd
  504bd9:	bf 00 dc c0 00       	mov    edi,0xc0dc00
  504bde:	e8 7d 97 22 00       	call   0x72e360
  504be3:	8b d8                	mov    ebx,eax
  504be5:	85 db                	test   ebx,ebx
  504be7:	0f 84 e0 00 00 00    	je     0x504ccd
  504bed:	8d 49 00             	lea    ecx,[ecx+0x0]
  504bf0:	8b b3 94 00 00 00    	mov    esi,DWORD PTR [ebx+0x94]
  504bf6:	8d 7b 44             	lea    edi,[ebx+0x44]
  504bf9:	3b f7                	cmp    esi,edi
  504bfb:	74 27                	je     0x504c24
  504bfd:	8d 49 00             	lea    ecx,[ecx+0x0]
  504c00:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504c04:	8d 46 14             	lea    eax,[esi+0x14]
  504c07:	72 02                	jb     0x504c0b
  504c09:	8b 00                	mov    eax,DWORD PTR [eax]
  504c0b:	68 d0 d1 be 00       	push   0xbed1d0
  504c10:	50                   	push   eax
  504c11:	e8 9b f0 38 00       	call   0x893cb1
  504c16:	83 c4 08             	add    esp,0x8
  504c19:	85 c0                	test   eax,eax
  504c1b:	74 51                	je     0x504c6e
  504c1d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504c20:	3b f7                	cmp    esi,edi
  504c22:	75 dc                	jne    0x504c00
  504c24:	33 f6                	xor    esi,esi
  504c26:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504c2a:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  504c2e:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  504c32:	3b c8                	cmp    ecx,eax
  504c34:	73 58                	jae    0x504c8e
  504c36:	8b d1                	mov    edx,ecx
  504c38:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  504c3c:	3b ca                	cmp    ecx,edx
  504c3e:	77 4e                	ja     0x504c8e
  504c40:	8b f2                	mov    esi,edx
  504c42:	2b f1                	sub    esi,ecx
  504c44:	c1 fe 02             	sar    esi,0x2
  504c47:	3b 44 24 7c          	cmp    eax,DWORD PTR [esp+0x7c]
  504c4b:	75 16                	jne    0x504c63
  504c4d:	b9 01 00 00 00       	mov    ecx,0x1
  504c52:	8d 44 24 74          	lea    eax,[esp+0x74]
  504c56:	e8 e5 15 1d 00       	call   0x6d6240
  504c5b:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504c5f:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  504c63:	85 c0                	test   eax,eax
  504c65:	74 49                	je     0x504cb0
  504c67:	8b 0c b1             	mov    ecx,DWORD PTR [ecx+esi*4]
  504c6a:	89 08                	mov    DWORD PTR [eax],ecx
  504c6c:	eb 3e                	jmp    0x504cac
  504c6e:	85 f6                	test   esi,esi
  504c70:	74 b2                	je     0x504c24
  504c72:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504c76:	8d 46 30             	lea    eax,[esi+0x30]
  504c79:	72 02                	jb     0x504c7d
  504c7b:	8b 00                	mov    eax,DWORD PTR [eax]
  504c7d:	85 c0                	test   eax,eax
  504c7f:	74 a3                	je     0x504c24
  504c81:	50                   	push   eax
  504c82:	e8 2d cb 38 00       	call   0x8917b4
  504c87:	83 c4 04             	add    esp,0x4
  504c8a:	8b f0                	mov    esi,eax
  504c8c:	eb 98                	jmp    0x504c26
  504c8e:	3b 44 24 7c          	cmp    eax,DWORD PTR [esp+0x7c]
  504c92:	75 12                	jne    0x504ca6
  504c94:	b9 01 00 00 00       	mov    ecx,0x1
  504c99:	8d 44 24 74          	lea    eax,[esp+0x74]
  504c9d:	e8 9e 15 1d 00       	call   0x6d6240
  504ca2:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504ca6:	85 c0                	test   eax,eax
  504ca8:	74 06                	je     0x504cb0
  504caa:	89 30                	mov    DWORD PTR [eax],esi
  504cac:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504cb0:	83 c0 04             	add    eax,0x4
  504cb3:	89 44 24 78          	mov    DWORD PTR [esp+0x78],eax
  504cb7:	bf 00 dc c0 00       	mov    edi,0xc0dc00
  504cbc:	8b c3                	mov    eax,ebx
  504cbe:	e8 fd 96 22 00       	call   0x72e3c0
  504cc3:	8b d8                	mov    ebx,eax
  504cc5:	85 db                	test   ebx,ebx
  504cc7:	0f 85 23 ff ff ff    	jne    0x504bf0
```

### RewardsEtc/Reward 節點選取

- VA `0x00504CCD..0x00504D30` (右界不含)，raw `0x1040CD..0x104130`，99 bytes，SHA256 `1c3cb27c1fe785f2e69028ff7e8712db67609cef69cc3f4f77bf4ed7b2d50df5`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504ccd:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  504cd1:	8b 72 18             	mov    esi,DWORD PTR [edx+0x18]
  504cd4:	85 f6                	test   esi,esi
  504cd6:	0f 84 54 01 00 00    	je     0x504e30
  504cdc:	bf 10 00 00 00       	mov    edi,0x10
  504ce1:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  504ce4:	8d 46 20             	lea    eax,[esi+0x20]
  504ce7:	72 02                	jb     0x504ceb
  504ce9:	8b 00                	mov    eax,DWORD PTR [eax]
  504ceb:	68 08 dc c0 00       	push   0xc0dc08
  504cf0:	50                   	push   eax
  504cf1:	e8 bb ef 38 00       	call   0x893cb1
  504cf6:	83 c4 08             	add    esp,0x8
  504cf9:	85 c0                	test   eax,eax
  504cfb:	74 0c                	je     0x504d09
  504cfd:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  504d00:	85 f6                	test   esi,esi
  504d02:	75 dd                	jne    0x504ce1
  504d04:	e9 27 01 00 00       	jmp    0x504e30
  504d09:	85 f6                	test   esi,esi
  504d0b:	0f 84 1f 01 00 00    	je     0x504e30
  504d11:	bf 14 dc c0 00       	mov    edi,0xc0dc14
  504d16:	8b c6                	mov    eax,esi
  504d18:	e8 43 96 22 00       	call   0x72e360
  504d1d:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  504d21:	85 c0                	test   eax,eax
  504d23:	0f 84 07 01 00 00    	je     0x504e30
  504d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
```

### Reward type/value 數值 decode 與 jump dispatch

- VA `0x00504D30..0x00504DA5` (右界不含)，raw `0x104130..0x1041A5`，117 bytes，SHA256 `1d96ba391b160f270d19eb9946eea8b4d5e2e9907bf3c440266f6b42f4c37c82`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504d30:	8b b0 94 00 00 00    	mov    esi,DWORD PTR [eax+0x94]
  504d36:	8d 78 44             	lea    edi,[eax+0x44]
  504d39:	bb 10 00 00 00       	mov    ebx,0x10
  504d3e:	3b f7                	cmp    esi,edi
  504d40:	74 23                	je     0x504d65
  504d42:	39 5e 28             	cmp    DWORD PTR [esi+0x28],ebx
  504d45:	8d 46 14             	lea    eax,[esi+0x14]
  504d48:	72 02                	jb     0x504d4c
  504d4a:	8b 00                	mov    eax,DWORD PTR [eax]
  504d4c:	68 08 b8 bf 00       	push   0xbfb808
  504d51:	50                   	push   eax
  504d52:	e8 5a ef 38 00       	call   0x893cb1
  504d57:	83 c4 08             	add    esp,0x8
  504d5a:	85 c0                	test   eax,eax
  504d5c:	74 47                	je     0x504da5
  504d5e:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504d61:	3b f7                	cmp    esi,edi
  504d63:	75 dd                	jne    0x504d42
  504d65:	33 db                	xor    ebx,ebx
  504d67:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  504d6a:	3b f7                	cmp    esi,edi
  504d6c:	74 26                	je     0x504d94
  504d6e:	8b ff                	mov    edi,edi
  504d70:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504d74:	8d 46 14             	lea    eax,[esi+0x14]
  504d77:	72 02                	jb     0x504d7b
  504d79:	8b 00                	mov    eax,DWORD PTR [eax]
  504d7b:	68 1c dc c0 00       	push   0xc0dc1c
  504d80:	50                   	push   eax
  504d81:	e8 2b ef 38 00       	call   0x893cb1
  504d86:	83 c4 08             	add    esp,0x8
  504d89:	85 c0                	test   eax,eax
  504d8b:	74 37                	je     0x504dc4
  504d8d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504d90:	3b f7                	cmp    esi,edi
  504d92:	75 dc                	jne    0x504d70
  504d94:	33 c0                	xor    eax,eax
  504d96:	8d 4b ff             	lea    ecx,[ebx-0x1]
  504d99:	83 f9 05             	cmp    ecx,0x5
  504d9c:	77 78                	ja     0x504e16
  504d9e:	ff 24 8d 54 55 50 00 	jmp    DWORD PTR [ecx*4+0x505554]
```

### Reward string parsing / switch six setters

- VA `0x00504DA5..0x00504E30` (右界不含)，raw `0x1041A5..0x104230`，139 bytes，SHA256 `0f4ca9418f84343e94fe85592799a1a94b2e1965b7b30f2c21a2a43177aa4670`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504da5:	85 f6                	test   esi,esi
  504da7:	74 bc                	je     0x504d65
  504da9:	39 5e 44             	cmp    DWORD PTR [esi+0x44],ebx
  504dac:	8d 46 30             	lea    eax,[esi+0x30]
  504daf:	72 02                	jb     0x504db3
  504db1:	8b 00                	mov    eax,DWORD PTR [eax]
  504db3:	85 c0                	test   eax,eax
  504db5:	74 ae                	je     0x504d65
  504db7:	50                   	push   eax
  504db8:	e8 f7 c9 38 00       	call   0x8917b4
  504dbd:	83 c4 04             	add    esp,0x4
  504dc0:	8b d8                	mov    ebx,eax
  504dc2:	eb a3                	jmp    0x504d67
  504dc4:	85 f6                	test   esi,esi
  504dc6:	74 cc                	je     0x504d94
  504dc8:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504dcc:	8d 46 30             	lea    eax,[esi+0x30]
  504dcf:	72 02                	jb     0x504dd3
  504dd1:	8b 00                	mov    eax,DWORD PTR [eax]
  504dd3:	85 c0                	test   eax,eax
  504dd5:	74 bd                	je     0x504d94
  504dd7:	50                   	push   eax
  504dd8:	e8 d7 c9 38 00       	call   0x8917b4
  504ddd:	83 c4 04             	add    esp,0x4
  504de0:	eb b4                	jmp    0x504d96
  504de2:	89 84 24 e4 00 00 00 	mov    DWORD PTR [esp+0xe4],eax
  504de9:	eb 2b                	jmp    0x504e16
  504deb:	89 84 24 e8 00 00 00 	mov    DWORD PTR [esp+0xe8],eax
  504df2:	eb 22                	jmp    0x504e16
  504df4:	89 84 24 ec 00 00 00 	mov    DWORD PTR [esp+0xec],eax
  504dfb:	eb 19                	jmp    0x504e16
  504dfd:	89 84 24 e0 00 00 00 	mov    DWORD PTR [esp+0xe0],eax
  504e04:	eb 10                	jmp    0x504e16
  504e06:	89 84 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],eax
  504e0d:	eb 07                	jmp    0x504e16
  504e0f:	89 84 24 f4 00 00 00 	mov    DWORD PTR [esp+0xf4],eax
  504e16:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  504e1a:	bf 14 dc c0 00       	mov    edi,0xc0dc14
  504e1f:	e8 9c 95 22 00       	call   0x72e3c0
  504e24:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  504e28:	85 c0                	test   eax,eax
  504e2a:	0f 85 00 ff ff ff    	jne    0x504d30
```

### Reward 結尾及下一 XML section

- VA `0x00504E30..0x00504E71` (右界不含)，raw `0x104230..0x104271`，65 bytes，SHA256 `e842cb24b1efb8a35192e00036fe582d190f75c267586867c11ab29b19dec0ba`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  504e30:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  504e34:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  504e37:	85 f6                	test   esi,esi
  504e39:	74 28                	je     0x504e63
  504e3b:	bf 10 00 00 00       	mov    edi,0x10
  504e40:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  504e43:	8d 46 20             	lea    eax,[esi+0x20]
  504e46:	72 02                	jb     0x504e4a
  504e48:	8b 00                	mov    eax,DWORD PTR [eax]
  504e4a:	68 24 dc c0 00       	push   0xc0dc24
  504e4f:	50                   	push   eax
  504e50:	e8 5c ee 38 00       	call   0x893cb1
  504e55:	83 c4 08             	add    esp,0x8
  504e58:	85 c0                	test   eax,eax
  504e5a:	74 09                	je     0x504e65
  504e5c:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  504e5f:	85 f6                	test   esi,esi
  504e61:	75 dd                	jne    0x504e40
  504e63:	33 f6                	xor    esi,esi
  504e65:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  504e69:	85 f6                	test   esi,esi
  504e6b:	0f 84 b3 03 00 00    	je     0x505224
```

### QuestRecord 暫存複製並插入 QuestInfo map

- VA `0x005053FB..0x00505452` (右界不含)，raw `0x1047FB..0x104852`，87 bytes，SHA256 `0bc6ae0c5d9a9d135f5b288bba61c714f33ed243dc1c3479bcc61a7069a41d33`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  5053fb:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  5053ff:	8d 94 24 a8 01 00 00 	lea    edx,[esp+0x1a8]
  505406:	89 8c 24 a4 01 00 00 	mov    DWORD PTR [esp+0x1a4],ecx
  50540d:	52                   	push   edx
  50540e:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  505412:	e8 b9 10 00 00       	call   0x5064d0
  505417:	8b 74 24 3c          	mov    esi,DWORD PTR [esp+0x3c]
  50541b:	8d 84 24 a4 01 00 00 	lea    eax,[esp+0x1a4]
  505422:	50                   	push   eax
  505423:	8b ce                	mov    ecx,esi
  505425:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x8
  50542c:	08 
  50542d:	e8 de 0e 00 00       	call   0x506310
  505432:	50                   	push   eax
  505433:	56                   	push   esi
  505434:	8d 74 24 48          	lea    esi,[esp+0x48]
  505438:	e8 33 0b 00 00       	call   0x505f70
  50543d:	8d 8c 24 a8 01 00 00 	lea    ecx,[esp+0x1a8]
  505444:	51                   	push   ecx
  505445:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x1
  50544c:	01 
  50544d:	e8 6e f1 ff ff       	call   0x5045c0
```

### QuestRecord 複製函式前半：含 Demand vector

- VA `0x005064D0..0x00506596` (右界不含)，raw `0x1058D0..0x105996`，198 bytes，SHA256 `9d5019fe98de13a288af8e41e6b2166d38f25da47d976bcce42089c613d78399`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  5064d0:	55                   	push   ebp
  5064d1:	8b ec                	mov    ebp,esp
  5064d3:	6a ff                	push   0xffffffff
  5064d5:	68 83 d5 90 00       	push   0x90d583
  5064da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5064e0:	50                   	push   eax
  5064e1:	56                   	push   esi
  5064e2:	57                   	push   edi
  5064e3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5064e8:	33 c5                	xor    eax,ebp
  5064ea:	50                   	push   eax
  5064eb:	8d 45 f4             	lea    eax,[ebp-0xc]
  5064ee:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5064f4:	8b f9                	mov    edi,ecx
  5064f6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5064f9:	8b 07                	mov    eax,DWORD PTR [edi]
  5064fb:	89 06                	mov    DWORD PTR [esi],eax
  5064fd:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  506500:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  506503:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  506506:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  506509:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  50650c:	8d 4f 10             	lea    ecx,[edi+0x10]
  50650f:	51                   	push   ecx
  506510:	8d 56 10             	lea    edx,[esi+0x10]
  506513:	52                   	push   edx
  506514:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  506517:	e8 74 25 2e 00       	call   0x7e8a90
  50651c:	33 c0                	xor    eax,eax
  50651e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  506521:	8b 4f 20             	mov    ecx,DWORD PTR [edi+0x20]
  506524:	89 4e 20             	mov    DWORD PTR [esi+0x20],ecx
  506527:	8b 57 24             	mov    edx,DWORD PTR [edi+0x24]
  50652a:	89 56 24             	mov    DWORD PTR [esi+0x24],edx
  50652d:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  506530:	89 4e 28             	mov    DWORD PTR [esi+0x28],ecx
  506533:	8b 57 2c             	mov    edx,DWORD PTR [edi+0x2c]
  506536:	89 56 2c             	mov    DWORD PTR [esi+0x2c],edx
  506539:	8b 4f 30             	mov    ecx,DWORD PTR [edi+0x30]
  50653c:	89 4e 30             	mov    DWORD PTR [esi+0x30],ecx
  50653f:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  506542:	89 56 34             	mov    DWORD PTR [esi+0x34],edx
  506545:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  506548:	89 4e 38             	mov    DWORD PTR [esi+0x38],ecx
  50654b:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  50654e:	89 56 3c             	mov    DWORD PTR [esi+0x3c],edx
  506551:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  506554:	89 4e 40             	mov    DWORD PTR [esi+0x40],ecx
  506557:	8b 57 44             	mov    edx,DWORD PTR [edi+0x44]
  50655a:	89 56 44             	mov    DWORD PTR [esi+0x44],edx
  50655d:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  506560:	89 4e 48             	mov    DWORD PTR [esi+0x48],ecx
  506563:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  506566:	6a ff                	push   0xffffffff
  506568:	89 41 10             	mov    DWORD PTR [ecx+0x10],eax
  50656b:	50                   	push   eax
  50656c:	8d 47 4c             	lea    eax,[edi+0x4c]
  50656f:	33 d2                	xor    edx,edx
  506571:	c7 41 14 07 00 00 00 	mov    DWORD PTR [ecx+0x14],0x7
  506578:	50                   	push   eax
  506579:	66 89 11             	mov    WORD PTR [ecx],dx
  50657c:	e8 5f c1 ef ff       	call   0x4026e0
  506581:	8d 4f 68             	lea    ecx,[edi+0x68]
  506584:	8d 46 68             	lea    eax,[esi+0x68]
  506587:	51                   	push   ecx
  506588:	50                   	push   eax
  506589:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  50658d:	e8 fe 3c 0c 00       	call   0x5ca290
  506592:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
```

### QuestRecord 複製函式後半：reward scalar

- VA `0x00506596..0x005065F1` (右界不含)，raw `0x105996..0x1059F1`，91 bytes，SHA256 `3f419d158dfe654dd8d3d809c95ed3d0ef1ef023a9b088ebb33e6f692cd37044`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  506596:	8b 57 78             	mov    edx,DWORD PTR [edi+0x78]
  506599:	89 56 78             	mov    DWORD PTR [esi+0x78],edx
  50659c:	8b 47 7c             	mov    eax,DWORD PTR [edi+0x7c]
  50659f:	89 46 7c             	mov    DWORD PTR [esi+0x7c],eax
  5065a2:	8b 8f 80 00 00 00    	mov    ecx,DWORD PTR [edi+0x80]
  5065a8:	89 8e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ecx
  5065ae:	8b 97 84 00 00 00    	mov    edx,DWORD PTR [edi+0x84]
  5065b4:	89 96 84 00 00 00    	mov    DWORD PTR [esi+0x84],edx
  5065ba:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  5065c0:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  5065c6:	8b 8f 8c 00 00 00    	mov    ecx,DWORD PTR [edi+0x8c]
  5065cc:	89 8e 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],ecx
  5065d2:	8b 97 90 00 00 00    	mov    edx,DWORD PTR [edi+0x90]
  5065d8:	81 c7 94 00 00 00    	add    edi,0x94
  5065de:	57                   	push   edi
  5065df:	8d 86 94 00 00 00    	lea    eax,[esi+0x94]
  5065e5:	50                   	push   eax
  5065e6:	89 96 90 00 00 00    	mov    DWORD PTR [esi+0x90],edx
  5065ec:	e8 1f 00 00 00       	call   0x506610
```

### QuestInfo map 查找（DWORD key）

- VA `0x00503D20..0x00503D88` (右界不含)，raw `0x103120..0x103188`，104 bytes，SHA256 `1e4eb6de69c98af78c54b9f442adafb9394981f108044de1233a7cf4bba051ff`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  503d20:	55                   	push   ebp
  503d21:	8b ec                	mov    ebp,esp
  503d23:	51                   	push   ecx
  503d24:	53                   	push   ebx
  503d25:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  503d28:	56                   	push   esi
  503d29:	8b f1                	mov    esi,ecx
  503d2b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  503d2e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  503d31:	80 b9 b5 00 00 00 00 	cmp    BYTE PTR [ecx+0xb5],0x0
  503d38:	75 1e                	jne    0x503d58
  503d3a:	57                   	push   edi
  503d3b:	8b 3b                	mov    edi,DWORD PTR [ebx]
  503d3d:	8d 49 00             	lea    ecx,[ecx+0x0]
  503d40:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  503d43:	7d 05                	jge    0x503d4a
  503d45:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  503d48:	eb 04                	jmp    0x503d4e
  503d4a:	8b d1                	mov    edx,ecx
  503d4c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d4e:	80 b9 b5 00 00 00 00 	cmp    BYTE PTR [ecx+0xb5],0x0
  503d55:	74 e9                	je     0x503d40
  503d57:	5f                   	pop    edi
  503d58:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  503d5b:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  503d5e:	3b d1                	cmp    edx,ecx
  503d60:	74 16                	je     0x503d78
  503d62:	8b 33                	mov    esi,DWORD PTR [ebx]
  503d64:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  503d67:	7c 0f                	jl     0x503d78
  503d69:	8d 4d 08             	lea    ecx,[ebp+0x8]
  503d6c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d6e:	5e                   	pop    esi
  503d6f:	89 08                	mov    DWORD PTR [eax],ecx
  503d71:	5b                   	pop    ebx
  503d72:	8b e5                	mov    esp,ebp
  503d74:	5d                   	pop    ebp
  503d75:	c2 04 00             	ret    0x4
  503d78:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  503d7b:	8d 4d fc             	lea    ecx,[ebp-0x4]
  503d7e:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d80:	5e                   	pop    esi
  503d81:	89 08                	mov    DWORD PTR [eax],ecx
  503d83:	5b                   	pop    ebx
  503d84:	8b e5                	mov    esp,ebp
  503d86:	5d                   	pop    ebp
  503d87:	c2               	ret    0x4
```

### Quest candidate 重建前置遍歷

- VA `0x00500317..0x00500356` (右界不含)，raw `0xFF717..0xFF756`，63 bytes，SHA256 `0dfacc3a3ffd0c14a1645499180b931807651f00102e12622a09865660d45a27`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  500317:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  50031a:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500320:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500323:	8b 08                	mov    ecx,DWORD PTR [eax]
  500325:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  500329:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  50032d:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  500331:	3b c8                	cmp    ecx,eax
  500333:	0f 84 83 02 00 00    	je     0x5005bc
  500339:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  50033d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500340:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  500344:	33 f6                	xor    esi,esi
  500346:	83 c3 10             	add    ebx,0x10
  500349:	f6 05 90 93 fb 00 01 	test   BYTE PTR ds:0xfb9390,0x1
  500350:	0f 85 b2 00 00 00    	jne    0x500408
```

### Demand vector consumer / QuestOwner WORD 前置鍵比對

- VA `0x00500631..0x005006B0` (右界不含)，raw `0xFFA31..0xFFAB0`，127 bytes，SHA256 `116b9e9704f2aec24b4fa10502b835a32a1b028c56f2ab5077a46137a8938af4`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  500631:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  500635:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  500639:	52                   	push   edx
  50063a:	8d 44 24 28          	lea    eax,[esp+0x28]
  50063e:	8b ce                	mov    ecx,esi
  500640:	e8 db 36 00 00       	call   0x503d20
  500645:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  500649:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  50064c:	0f 84 2c 01 00 00    	je     0x50077e
  500652:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  500655:	2b 50 20             	sub    edx,DWORD PTR [eax+0x20]
  500658:	33 ff                	xor    edi,edi
  50065a:	c1 fa 02             	sar    edx,0x2
  50065d:	85 d2                	test   edx,edx
  50065f:	74 4f                	je     0x5006b0
  500661:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  500664:	8b 8e b4 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eb4]
  50066a:	8b b6 b0 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eb0]
  500670:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  500673:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  500677:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  50067b:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  50067f:	3b c1                	cmp    eax,ecx
  500681:	0f 84 f7 00 00 00    	je     0x50077e
  500687:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  50068b:	8b 36                	mov    esi,DWORD PTR [esi]
  50068d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500690:	0f b7 18             	movzx  ebx,WORD PTR [eax]
  500693:	3b de                	cmp    ebx,esi
  500695:	74 07                	je     0x50069e
  500697:	83 c0 02             	add    eax,0x2
  50069a:	3b c1                	cmp    eax,ecx
  50069c:	75 f2                	jne    0x500690
  50069e:	3b c1                	cmp    eax,ecx
  5006a0:	0f 84 d8 00 00 00    	je     0x50077e
  5006a6:	83 44 24 18 04       	add    DWORD PTR [esp+0x18],0x4
  5006ab:	47                   	inc    edi
  5006ac:	3b fa                	cmp    edi,edx
  5006ae:	72 cb                	jb     0x50067b
```

### Demand 通過後候選 WORD append 入口

- VA `0x005006B0..0x005006F0` (右界不含)，raw `0xFFAB0..0xFFAF0`，64 bytes，SHA256 `17efb2fb0c0255f30385ad981b4860370005c39448c226d7a2eaedc3a0c85128`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  5006b0:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5006b3:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  5006b7:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  5006ba:	8b 86 c4 5e 00 00    	mov    eax,DWORD PTR [esi+0x5ec4]
  5006c0:	81 c6 c0 5e 00 00    	add    esi,0x5ec0
  5006c6:	8d 54 24 18          	lea    edx,[esp+0x18]
  5006ca:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  5006ce:	3b d0                	cmp    edx,eax
  5006d0:	73 61                	jae    0x500733
  5006d2:	8b 16                	mov    edx,DWORD PTR [esi]
  5006d4:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  5006d8:	3b d1                	cmp    edx,ecx
  5006da:	77 57                	ja     0x500733
  5006dc:	8b f9                	mov    edi,ecx
  5006de:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  5006e1:	2b fa                	sub    edi,edx
  5006e3:	d1 ff                	sar    edi,1
  5006e5:	3b c1                	cmp    eax,ecx
  5006e7:	75 38                	jne    0x500721
  5006e9:	2b c2                	sub    eax,edx
  5006eb:	d1 f8                	sar    eax,1
  5006ed:	3d fe ff         	cmp    eax,0x7ffffffe
```

### type2/giver local candidate selector

- VA `0x00500A00..0x00500A80` (右界不含)，raw `0xFFE00..0xFFE80`，128 bytes，SHA256 `1884dfd79468a0d60197950f309a373be3a6bade794fb9efc6b4306560b35055`。由原始 BIN 直接反組譯；不得把函式起點以外的截斷指令解釋為獨立語義。

```asm
  500a00:	55                   	push   ebp
  500a01:	8b ec                	mov    ebp,esp
  500a03:	83 ec 0c             	sub    esp,0xc
  500a06:	53                   	push   ebx
  500a07:	57                   	push   edi
  500a08:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a0b:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  500a11:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500a17:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500a1a:	3b d8                	cmp    ebx,eax
  500a1c:	74 57                	je     0x500a75
  500a1e:	56                   	push   esi
  500a1f:	90                   	nop
  500a20:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  500a23:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  500a29:	8d 4d fc             	lea    ecx,[ebp-0x4]
  500a2c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a2f:	51                   	push   ecx
  500a30:	8d 45 f8             	lea    eax,[ebp-0x8]
  500a33:	8b ce                	mov    ecx,esi
  500a35:	e8 e6 32 00 00       	call   0x503d20
  500a3a:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500a3d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500a40:	74 05                	je     0x500a47
  500a42:	83 c0 10             	add    eax,0x10
  500a45:	eb 02                	jmp    0x500a49
  500a47:	33 c0                	xor    eax,eax
  500a49:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a4c:	85 c0                	test   eax,eax
  500a4e:	74 1c                	je     0x500a6c
  500a50:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  500a53:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  500a56:	75 14                	jne    0x500a6c
  500a58:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500a5c:	75 0e                	jne    0x500a6c
  500a5e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500a61:	8d 45 fc             	lea    eax,[ebp-0x4]
  500a64:	e8 a7 32 f4 ff       	call   0x443d10
  500a69:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a6c:	83 c3 02             	add    ebx,0x2
  500a6f:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  500a72:	75 ac                	jne    0x500a20
  500a74:	5e                   	pop    esi
  500a75:	5f                   	pop    edi
  500a76:	5b                   	pop    ebx
  500a77:	8b e5                	mov    esp,ebp
  500a79:	5d                   	pop    ebp
  500a7a:	c2 0c 00             	ret    0xc
  500a7d:	cc                   	int3
  500a7e:	cc                   	int3
  500a7f:	cc                   	int3
```

### Reward switch 表：這是 6-entry 數據而非可執行指令

- VA `0x00505554`，raw `0x104954`，24 bytes SHA256 `42121164a8411e3bee8473bd227ae709de13b7cecd8937ffad233ac25b4741e2`，raw hex `e2 4d 50 00 f4 4d 50 00 eb 4d 50 00 fd 4d 50 00 06 4e 50 00 0f 4e 50 00`。
- 小端六 DWORD: `0x504DE2`, `0x504DF4`, `0x504DEB`, `0x504DFD`, `0x504E06`, `0x504E0F`.
- 對應 type1–6，位置順序已由 `0x504D96` 的 `(type-1)` index 與 switch case 交叉驗證。

## 10. 本段交付審核與最終狀態

- [x] 獨立重算四個原件 SHA256，確定非 TC／AI fixture。
- [x] 確認上段 T16-124 後的正式 T16-125 研究目標是 Quest15①，未誤編 Quest15 ID 作為正式段號。
- [x] 直接由 Event.stp 讀 Quest15 四段 Script，記錄原始 offset、hash、NPC10338 正反對照及 Stage3/4 分流。
- [x] 原生 quest XML loader/constructor/Demand 讀者/map copy/reward case/parser 反證完整鏈節均附實際 bytes。
- [x] 「原始 XML 未重讀／Quest15 reward 2800/468 本次不能確證」限制標記。
- [x] 分出 Client 待逆向、Server 待開發、跨 Task 待整合、待遊玩驗證。
- [x] 本段不以未知 Server 演算法為由阻止 ① 的 Client 靜態有界完成。
- [ ] T01 返回 T16-117 正式 erratum：目前仍 `NEEDS_FIX`，未擅自改 main 台帳或代表 T01 裁決。
- [ ] T01 FULL-PASS（只有 T01 審核才能升格）；S00 SPEC STABLE／真實可玩驗收也未進行。

**正式結語**：**Quest15-①／T16-125：Client 靜態有界完成**。T16-125 不是 Quest15-②～⑤，也不是 T01 FULL-PASS；源 XML 未重讀的精確數值限制保留，供未來增量補證。
