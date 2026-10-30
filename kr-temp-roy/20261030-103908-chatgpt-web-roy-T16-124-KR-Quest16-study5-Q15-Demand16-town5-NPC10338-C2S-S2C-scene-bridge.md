# T16-124 — Quest16／⑤：Demand16 → town5／NPC10338 → Quest15 type2 → C→S／S→C／mode2 TalkBox；Pin(d)os 場景邊界（KR BIN-first）

- **研究日期／檔名時間**：`2026-10-30T10:39:08.896836+08:00`，`chatgpt-web roy`。
- **正式段號**：T16-124；依 `t16/roy/chatgpt-web` 已提交的 T16-123（Quest16-④）延續；本段不是 Quest15-①。
- **目標**：在原生 KR Client 的可驗證界線內，完成 Quest16-⑤「已確認 Quest16 前置鍵如何使 Quest15 成為候選、如何經 town5／NPC10338 選中、有哪些 C→S／S→C 路徑及 TalkBox／劇情結果」的端到端靜態條件鏈；不還原原版 Server 決策或宣稱實機可玩。
- **完成評估**：**Client 靜態有界完成**。`0x74(16)`、候選雙重 gate、`0x38` town selector 寫入與重算時機、type2 NPC10338 first selection、NPC `0x1C` 與條件式 `0x3F`、S2C `0x40(15,state0)` → `0xF438B` → mode2 TalkBox，已定位並附 BIN 證據。Server 如何配對與何時傳送、NPC 真實場景觸發及完整 wire framing 未證，**不能**據此稱整條 live gameplay 已閉合。
- **KR 第一手證據**：`/mnt/data/Tartaros.bin` = 12,472,320 B、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` = 11,241,597 B、SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。皆只讀，未執行／修補／提交 binary。
- **PE 位址**：`.text` ImageBase `0x400000`、RVA `0x1000`、raw offset `0x400`，故本段程式碼 `raw = VA - 0x400C00`。下方反組譯均直接自 SHA-核對 `Tartaros.bin`、`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`，不是舊反編譯摘要。
- **GitHub 查證基準**：開工 `origin/main=95363f4ae8c203b6f6c35d586f990117a5274283`；T16 工作分支 ahead11／behind16（隨其他 Agent 變更可變）；T16 S00 RR 收件箱無待處理請求；T01 無本次優先需修復的 ACTIVE 問題，43 筆歷史送審見 Task README；共用已審限定主張為 7 筆，不代表 Quest FULL-PASS。
- **GitHub 同步／提交權限**：此為**同一對話續作**，沿用此前 PR #26 一次性 main→T16 同步，不再自動 merge；使用者本次只授權**完成本研究後提交完整技術原稿至 `t16/roy/chatgpt-web`**，禁止直接合併 main。

---

## A. 研究問題與封閉鏈判準

研究終點依玩家可觀察情境拆解，但不把任一孤立的指標呼叫作為終點：

1. Quest16 的先決/完成鍵何時出現在 Client，是否同時排除 Quest16 自身、使 Quest15 的 `Demand16` 成立？需要原始資料、前置 writer、正負 candidate gate。
2. Quest15 位於 `town=5`，誰提供 town selector，尤其 key16 與 town5 的順序改變對候選重算有何影響？需證明 pointer identity／不同 subtype 分支。
3. 只有在 Quest15 真正列入候選時，NPC10338 的 `type=2` 查詢怎麼取得 quest ID？是否 first-only、是否證明唯一？
4. 玩家對 NPC 互動的本地事件與 C→S application payload 之間有什麼關係？NPC `0x1C`、控制器延後 `0x3F`、先前 `0x36` 模式限制是否區分？
5. 若收到 S→C `0x40(15,state0)`，Client 如何更新本地候選／排除狀態並打開 Quest15 mode2 TalkBox？`0x74` 本身是否已經完成該對話？
6. `Event.stp` 中 Quest #15 / Scene #3 的 `pindos_talkevent` 與 town5／NPC10338 是否可等同？要證明 scene namespace 與 live Server 轉場的界線。

**完成定義**：已證 Client 條件資料流及其效果，保留 Server 封包配對、timing、持久化與 runtime 未知為獨立狀態，不要求不可能由 Client 推出的原版 Server 內部政策。

## B. Quest XML 來源與跨空間 ID，不混用

此節 XML 是沿用 GitHub 中 T16-112／T16-117／T16-118 的先前原始 XML 擷取，對應 QuestInfo 原件的研究摘要；**不是**本次對加密 STPD `Table.stp` 直接再解碼成功。GitHub 大型原 XML evidence 檔先前能確認 blob，但連接器回傳空文字，故保留來源層級。

| 欄位 | Quest16 | Quest15 | 解釋 |
|---|---|---|---|
| Quest ID | 16 | 15 | 都是任務主鍵，不能當成 NPC ID |
| type | 2 | 2 | Native `0x500A00` 篩選 type2 |
| `town` | 0 | **5** | Native `QuestRecord+0x20`、重建候選的 world selector |
| `field` | 18 | 19 | XML 場域號，不可直接視為 town 或地圖 ID |
| `level` | 1 | 1 | Client 候選有等級 gate，資源值是需求值 |
| `giver`／`finisher` | NPC10027 | **NPC10338** | Native `QuestRecord+0x28` 的 giver selector |
| `Demand` | ID14 | **ID16** | 兩者是任務前置 KEY／需求列表比對，不是 Server 回覆時間證據 |
| 附屬獎勵 | type2 value50 | type2 value2800、type4 value468 | QuestInfo 元資料；不得改寫成 Server 實際給獎結果 |

**另三個不同空間**：`Event/SceneList.xml` questIdx15 scene1..4 中的 scene3 `pindos_talkevent`；Lua `LoadMap("town001D.map")` 字串；Lua `CreateObject(...,10047,...)` 中實體 ID10047。**QuestID15、town5、NPC10338、Scene 15/3、地圖 town001D、NPC10047 是不同命名空間**；只有實際 native/資源橋接能讓它們在玩家流程上相連。

## C. 核心狀態記憶體與應用訊息約定

| 項目 | 原生地址／偏移 | 已確認意義與限制 |
|---|---|---|
| QuestOwner | `0xFAB2A0` | 任務候選處理 owner；具體實際 layout 以 caller 執行時此全域物件為基準 |
| 前置鍵 WORD vector | owner `+0x5EB0` begin、`+0x5EB4` end | S2C `0x74` 寫入，`0x72` 清空；不應說它代表原版 DB 已提交完成 |
| 候選 WORD vector | owner `+0x5EC0` begin、`+0x5EC4` end | `0x500240` 重建後供 `0x500A00` 查找 |
| 20-slot 排除表 | owner `+0x5ED0` | 與前置鍵向量不同，還受 `0x40/0x64/0x65` 等維護 |
| QuestRecord `town` | record `+0x20` | XML town gate；本段需 Q15=5 |
| QuestRecord `giver` | record `+0x28` | NPC lookup gate；Q15=10338 |
| QuestRecord `type` | record `+0x04` | 必須=2 才會由 0x500A00 選出 |
| QuestRecord `Demand` | record `+0x10/+0x14` | DWORD 需求 vector，拷貝進 map node 後 node+0x20/+0x24 |
| 全域 world context 基底 | `0x40F060()=0xFAB130` | **返回基底位址本身**，不自動完成任務 |
| 當前 town selector | `[0xFAB130+0x8C]` **= `[0xFAB1BC]`** | 兩種寫法是**同一 DWORD 欄位**，不是兩份狀態！`0x38` 不同 subtype 更新時機不同 |
| S2C `0x74` application | `74 00 10 00`（payload 的最小 4 bytes，ID16） | Index `0x74`；`WORD+2`=16；完整 wire frame 由 T02 解析 |
| S2C `0x38` application | `BYTE+2` subtype；`WORD+3` town key | 部分 subtype 還讀 `WORD+7`，**不可**只用短示例推定所有 subtype payload 長度 |
| C2S `0x1C` | `u16 0x1C, u16 event+0x18, u16 event+0x1C`（6 bytes） | 不以 Q15 的 first candidate 填充 ID；NPC 互動 context |
| C2S `0x3F` | `u16 0x3F, u16 candidateID, u16 auxiliary, u16 1`（8 bytes） | controller gate 才可能送；Q15/aux1 示例 `3F 00 0F 00 01 00 01 00`（條件式） |
| S2C `0x40` | `WORD+2` QuestID、`DWORD+4` state | state0 可產 `0xF438B` event，`0x40(15,state0)` 到 mode2 TalkBox；不能先假設配對 0x3F |

此處所稱 application 訊息編碼，均不冒稱已確定網路 framing；T02 既有分析展示 queue/framing 依連線模式分流（`0x807A70` 與 `0x807830`），含 prefix 且可能有變換。`0xFBA798` sender gate 允許入列不等於 `WSASend` 完成或 Server ACK。

---

## D. 從 Quest16 的 S2C key16 到 Quest15 的「兩次相反方向」候選 gate

**D1. 寫入**：S2C index `0x74` 派送到 `0x503400`。`0x503403` 取得 application payload，`0x50340A` 遞增 2 bytes，`0x50340D` 指向 owner `+0x5EB0` vector，`0x503413` 呼叫 `0x44B4E0` 將 `WORD[payload+2]` 添加到向量。`0x503418 -> 0x40F060`，`0x50341D` 讀 world+0x8C，`0x503425` 重建候選 `0x500240(owner,currentTown)`。該 handler 看不到接取成功、發獎或完成持久化的副作用，不可推論 Server 已經正式完成 Q16。

**D2. 移除本任務**：候選掃描中，`0x5004C4..0x5004E7` 取 owner 前置鍵 vector，對正在遍歷的 QuestID `ESI` 做 WORD 比對；命中會跳 `0x50054A` 避開當前候選。故同一 key16**不只**用於 Q15 `Demand16`，也會過濾 Q16 候選（只限走此掃描路徑的候選，不宣稱整個任務 UI 已隱藏 Q16）。

**D3. 滿足下一任務**：`0x500631..0x50064C` 對候選 QuestRecord 的 Demand vector 取 range，`0x500652..0x5006AE` 對每個 DWORD Demand，在 owner `+0x5EB0/+0x5EB4` WORD key vector 查找；每個 demand 均找到才納入；若 Quest15 `Demand16` 存在且 key16 已加入，則此需求 gate 通過。

**D4. 另外必要的 gate**：`0x500485` 比對 `QuestRecord+0x20` town 與傳入 town selector；`0x500491` 等級；`0x5004A3..0x5004C2` 掃描 20-slot excluded；加上 `D2` 排除已在前置鍵的當前 QuestID。`town=5` 是 Q15 候選的獨立必要條件，故先收到 key16 時仍在 town0 並不會神奇出現 Q15。成功候選才在 `0x5006B0..0x50077A` 追加 WORD QuestID 至 owner+0x5EC0..+0x5EC4。

**D5. 順序反例**：`0x74(16)` 立即以**當下** town selector 重建候選。若此刻 town0，Q15 過不了 town5；若之後 selector 改5但沒有觸發 `0x500240`，不能推論候選已更新。相反地若先 town5，後 `0x74(16)`，重算即可同時檢查 `Demand16`。此是原生 Client 靜態行為，不是 Server 必須採取的唯一推送順序。

## E. 新閉合的 town selector writer：0x38 subtype → 同一欄位、不同重算時機

**E1. handler 註冊**：`0x4ADF2D` 將函式地址 `0x4B1BF0` 放入分派表偏移 `+0x1C4`；已知每個應用 index slot 8B、從 `+4` 起算，`(0x1C4-4)/8=0x38`。這裡稱入站 application index0x38，與 TCP framing opcode（可能由 T02 轉換）分開。

**E2. 入口 subtype**：`0x4B1D13` 取 `BYTE[payload+2]`，計算 `0/2/6` 分支；其餘另走跳轉與其他效果。此 handler 含不少初始化、畫面與場景副作用，不得整體命名為純「town setter」。

**E3. subtype6**：`0x4B1D25` 經減去0、2、4後判 subtype6，`0x4B1D5B` 另讀 `WORD[payload+7]` 給 `0x540980`，再 `0x4B1D6A` 取 `WORD[payload+3]`，`0x4B1D6E` 呼叫 `0x40F060`，`0x4B1D73` 寫 `DWORD[returnedWorld+0x8C]`；分支跳至共用返回側 `0x4B1E0E`，在**這條已查範圍**沒有立即呼叫 `0x500240`。實機其他 callback 是否稍後重算不能以未見推論永不重算。

**E4. subtype0/5**：另一控制流程 `0x4B1EAB..0x4B1EB8` 判定 subtype=0 或5 進 `0x4B1FAE`；沿 `0x4B2050` 使用 `WORD[payload+3]`，`0x4B2094..0x4B2098` 寫絕對地址 `[0xFAB1BC]`，`0x4B20CC` 再讀該值，`0x4B20FD..0x4B2103` 呼叫 `0x500240(QuestOwner,town)`，**在本分支立即重算候選**。其他初始化／scene side effects 仍可存在。

**E5. 指標同一性強證**：`0x40F0B4: mov eax,0xFAB130`，因此 `0xFAB130+0x8C=0xFAB1BC`。**subtype6 的 world+8C 與 subtype0/5 的 absolute FAB1BC 是同一個欄位，不是兩個相似欄位！** 兩者的可觀察差別是本段可證的**後續是否在該 CFG 立即呼叫候選 rebuild**。此明確更正研究中曾暫時分列兩個地址的疑慮。

**E6. 結論對 Quest15**：若 `WORD[payload+3]=5` 且 subtype0/5 分支成立，會更新 selector5 並重建 Q15 候選；若 subtype6 更新5，則至少要另有重算觸發（例如 S2C 0x74 或其他 0x500240 caller），才可保證候選反映 town5；`0x74(16)` 也依當前 selector 重算。未實際捕捉 Server 封包，不知道原版何時送哪個 subtype。

## F. NPC10338：type2 first candidate 與控制器、兩類 C→S 效果

**F1. 事件 gate**：`0x5B9340` 要求 outer event vtable type `0x105BD`（`0x5B937A`）及 action `0x6A7`（`0x5B939A`）。它再檢查 nested event vtable type `0x105BF`（`0x5B93B6`），於 `0x5B93FF` 從 nested event+0x14 取 selector。若該值為 NPC10338，且 Q15 已在 candidate vector，才可沿此條件式路徑選取 Q15。

**F2. type2 first-only**：`0x5B9407` 呼叫 `0x5008B0(owner,selector)`；`0x5008B0 → 0x500A00` 走候選 WORD vector，各 QuestID 經 `0x503D20` 查記錄後，在 `0x500A53` 比對 record+0x28 是否等於 NPC selector，在 `0x500A58` 比對 type==2，符合者收入本地 vector。`0x500922..0x500930` 只返回第一個命中 QuestID 的低16位，無候選則返回0。**除非對全部 QuestInfo 及排序有直接證據，不能說 NPC10338 只有 Q15；只能說 Q15 符合 giver+type2 篩選，並在 first-match 指向 Q15 時回傳15。**

**F3. 控制器與 C→S 0x1C**：`0x5B943F..0x5B9447` 把 `(candidateFirstID,1)` 傳給控制器 `0x561760`，寫控制器的暫存欄位；`0x5B9453..0x5B9485` 建構另一路 6-byte application `1C 00 [WORD nestedEvent+0x18] [WORD nestedEvent+0x1C]`，須 sender gate `[0xFBA798]==0` 才呼叫 sender。這包**不會**直接帶 `candidateFirstID`，不能在 Server 規格誤寫為 `1C questId=15`。

**F4. C→S 0x3F 非立即**：`0x561760` 後的 `0x561DB0`（包括場景 flag、control bit、`controller+0x89`/`+0x28`）存在多條下游；某些分支經 `0x561FA3..0x561FB5` 或 `0x561FD4..0x561FE0` 呼叫 `0x4A39A0`，其 application payload 為 `u16 0x3F, u16 candidateID, u16 secondary, u16 1`（8 bytes），在獨立 gate 才入列。若當時 controller 保存 `[candidateID=15, secondary=1]`，示例 bytes `3F 00 0F 00 01 00 01 00`，**不能宣稱 NPC 點擊一定會立即送這 8 bytes**。

**F5. 非此路徑**：有控制器分支送 `0x565720` 場景／scene map 查找；不保證每次 NPC click 都走 `0x3F`。另 `0x36` mode1 UI producer（`0x636E10`）和 `0x4B3510` 其他訊息處理 producer，**未**由 Quest15 的 mode2 直接證明接取發包。這點保留 T16-122 的反證，不將 opcode 分別扭成同一 player accept。

## G. S2C Quest15 的 native UI 消費：0x40(state0) → event → mode2 TalkBox

**G1. `0x40` handler `0x502270`**：`WORD[payload+2]` 是 QuestID；`DWORD[payload+4]` 是 state。state==0 分支可構造 `0x105B9`、action `0xF438B`、QuestID 在 event+0x14，並維護 owner 20-slot 排除清單、候選重建和後續控制器效果；state==1 走不同通知／UI，非同一 TalkBox 事件。

**G2. event 分派與 UI**：依已在 T16-121 證實的 event action dispatch `0x5B7F80` action index0x27 → `0x5B7FFF` → `0x5B6D20`。`0x5B6D20` 驗 event vtable type `0x105B9`，從 event+0x14 取 QuestID，在 `0x5B6DC6` 查 QuestInfo `0x503D20`，命中有效 record 後於 `0x5B6E21` `push 2` 作 TalkBox mode2，呼叫 `0x636520`。如果 ID==15 且資源存在，TalkBox 保存 QuestID15、giver10338 等欄位。該行為**不等於** `0x3F(15,1)` 的原版必然回覆；它只是 Server/測試 harness 若送入 `0x40(15,0)` 時 Client 的條件行為。

**G3. 狀態位置分離**：owner `+0x5EB0` 鍵向量、owner `+0x5ED0` 排除 20slot、owner `+0x5EC0` 候選向量、TalkBox `+0x80/+0x84/+0x90`（Quest ID／giver／mode），以及 world `+0x8C`，是不同容器，不能用一個 bool “quest15 unlocked” 取代所有 Client 更新。

## H. Event.stp 中的原始 Quest15／Pin(d)os 場景證據（本段直接解碼）

- 原件 STPD，從原始檔的附屬資源 XOR `0xFF` 解碼這個文字 chunk，**不是修改原件**。`-- TTEX Talk Scene File` 片段編碼原檔 byte offset `9182224` 起，`-- Quest #15 / Scene #3 - Function pindos_talkevent` 註解 offset `9182270`，結束 `Register(pindos_talkevent)` 約 offset `9183860`；本地擷取總計 **1636 bytes**，SHA256 `79b563be567ef51cce081a8a843eede14962b3bea5bf8af8b69e65c73d0d1b7e`。
- 直接證實 `Quest #15 / Scene #3` 與 Lua function `pindos_talkevent()`、`LoadMap("town001D.map")`、`SetTransitionType(2)`、`OpenTalkScene(3,18)` 及其他 talk scenes、`Register(pindos_talkevent)`。
- **scene 內 CreateObject(4,10047,...)** 是 scene object/NPC key10047，不等同 Quest15 XML giver NPC10338。不同 ID 並不構成資源錯誤；可能是任務觸發前後不同物件角色，但本段沒有 native/event producer 將兩者直接等同。
- 原資源只能證明**Client 本地劇情腳本可被呼叫時**會載入場景、執行上述 phase/camera/talk；無法由這段 script 證明 `0x74(16)`、`0x38 town5` 或 `0x40(15,0)` **必然**呼叫 `pindos_talkevent`。SceneList 引用、腳本名稱與實際 dispatch/Server 到達時序是分層證據。

以下為原始擷取（保留原始 function 名稱、文字、次序，Windows 行尾規範僅在 Markdown 呈現中可有不同）：

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #15 / Scene #3 - Function pindos_talkevent
function pindos_talkevent()
	SetTransitionType(2)
	SetFinalMusic("BGM003.ogg")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("town001D.map")
	MoveCamera(755.00, 416.00, 57.75)
	RotCamera(5.67, 1.33, 55.00)

	CreateObject(0, 1478, 751.00, 416.00, 128, 0, FALSE, 1, 1)
	CreateObject(1, 1479, 760.00, 416.00, 128, 0, FALSE, 1, 10)
	CreateObject(2, 1480, 755.00, 429.00, 0, 0, FALSE, 1, 19)
	CreateObject(3, 1481, 755.00, 421.00, 128, 0, FALSE, 1, 28)
	CreateObject(4, 10047, 734.00, 744.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM003.ogg")
	PlayCameraNoWait("tutorial_01_18.cam", 0, 0.00, 0.00, 0.00)
	wait(2000)
	OpenTalkScene(3, 18)
	PlayCameraNoWait("tutorial_01_18b.cam", 0, 0.00, 0.00, 0.00)
	wait(1000)
	WalkObject(2, 755.000000, 439.000000, 0.000000, 1, 4, 3)
	wait(1500)
	AniObject(2, 2, 1)
	RotateObject(2, 0, 1)
	wait(1000)
	OpenTalkScene(3, 24)
	PlayCamera("tutorial_01_19.cam", 0, 0.00, 0.00, 0.00)
	OpenTalkScene(3, 20)
	PlayCameraNoWait("tutorial_01_20.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 21)
	PlayCamera("tutorial_01_22.cam", 0, 0.00, 0.00, 0.00)
	ClearObjects()
	PlayCameraNoWait("tutorial_01_21.cam", 0, 0.00, 0.00, 0.00)
	PlayMusic("BGM007.ogg")
	wait(3000)
	FlyingObject("Image/Prologue/Phindous00_1.dds", 50, 35, 100, 9999, 0, 0)
	wait(4000)
	DelFlyingObject()
	DoProlog(1)
	PlayMusic("BGM003.ogg")

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(pindos_talkevent)
```

## I. Client 契約與相容 Server 條件式測試矩陣

| 測試情境／前置 | 建議的應用層測試輸入 | Client 靜態預期 | 未證限制 |
|---|---|---|---|
| 已滿足 Q14，Q16 初始 type2 | world town0；owner key14；候選重建 | Q16 可能進候選；NPC10027 type2 選出16 | 任務排除、等級、其他 gating 仍需成立 |
| Q16 key 下發但仍 town0 | S2C `74 00 10 00` | key16 加入；重建時 Q16 被掃描排除，Q15 因 town !=5 不出現 | 不能稱 Q15 可見；不代表獎勵已給 |
| 先 key16 再 S2C `0x38` subtype0/5 轉 town5 | `BYTE+2∈{0,5}`、`WORD+3=5`，其餘長度按 T02 驗證 | same world+8C 置5、立即重建；Q15 Demand16/town5 可過兩 gate | 初始/場景 side effects 也需守條件；無官方封包 dump |
| 先 key16 再 `0x38` subtype6 轉 town5 | `BYTE+2=6`、`WORD+3=5`、`WORD+7` 需有效 | same world+8C 置5；本分支**沒有立刻**呼叫 0x500240 | 需要其他 rebuild trigger 或下游事件 |
| town5 與 key16 都已就緒 | NPC10338 outer0x105BD action0x6A7 + nested0x105BF selector10338 | 若 Q15 在 candidates 且 first type2 match 則 candidateID15 傳控制器 | 需具體 NPC actor UI producer/runtime，first 順序仍未知 |
| NPC 互動 sender gate 允許 | local sender 0x1C event context two WORDs | queue 6B application，不是 questId15 | Server 解碼 event words 意義由對應 T02/T07 定義 |
| Controller delayed `0x3F` gate 允許 | candidateID15、secondary1 | queue 8B application `3F 00 0F 00 01 00 01 00` | 不保證 NPC 點擊後立即發；0x40 未證是直接回覆 |
| 接收到 Quest15 UI event 的 S2C | index0x40、`WORD+2=15`、`DWORD+4=0` | 產 `0xF438B`, 排除表/候選更新，QuestInfo15 有效時 mode2 TalkBox | 不保證 Server 官方何時送；某些 UI flag/missing record 可阻礙 |
| 0x40 同 ID state1 | index0x40、ID15、state1 | 別條通知/文字流程 | 不等於 mode2；不外推所有 state |
| 世界場景 script | 正式 scene dispatch 選 Quest#15/Scene#3 | 本地 Lua 可 LoadMap town001D 與 camera/talk | **尚未找到**它與 Quest15 NPC interaction 或 0x40 的直接唯一橋 |

**相容 Server 的最小**：應明確選擇（ADR）何時承認 Q16 完成，如何發前置 key16，何時以 S2C 0x38 更新 town/scene selector，是否重傳 snapshot／哪時清空，如何處理 NPC 0x1C context 與可能延後的 0x3F，以及如何觸發 0x40(15,state0) 的 Client UI；保證欄位符合 Client 消費約束。ADR 不是復原官方演算法。S00 才負責正式 SPEC/GAP/TEST 發布；本稿不自行更動全域規格。

## J. 必須維持分離的四種待辦

**J1. Client 待逆向**：`0x38` S2C 不同 subtype 的完整 payload 長度／非典型值和跨入口場景呼叫；NPC10338 真正畫面 actor/UI producer，`event+0x18/+0x1C` 的原始生成者；控制器哪個 runtime state 走 0x3F 或場景；Quest15 的實際接取或交付 UI 鍵回呼與 C2S；`pindos_talkevent` 的 resource SceneList dispatch 是否和某封包/Quest15 GUI 連到一起。以上是 Quest15-①～⑤及全村路徑的待補，不偽稱 Quest16-⑤已涵蓋完整 Quest15。

**J2. Server 待開發**：Q16 完成/獎勵/保存、Q15 Demand16 判定和 town5 開放策略、送 S2C 0x38/0x74/0x40 的條件、NPC context `0x1C` 和可能 `0x3F` 的相容回覆策略、重登重播鍵與 town 狀態。原版 Server 內部規則不從 Client 猜測。

**J3. 跨 Task**：T02 完整 wire framing/入口分派/連線模式；T06/NPC UI callback；T07 場景、town map；T08 resource/scene loading；T03/T04 登入初始 state；T14 關卡勝敗；T15 durable snapshot；S00 SPEC/ADR/GAP/TEST，T01 嚴格逐主張審核。

**J4. 待遊玩驗證**：真正玩家 NPC10338 可見/可點、Q16 完成後 Q15 何時出現、封包動態順序、已給獎、town001D 實際進入、TalkBox 實際顯示與任務接取成功、重登後恢復。Client 靜態可證與遊玩結果是不同驗收。

## K. 主要負面證據、修正與風險

1. **重點修正：world+0x8C = global 0xFAB1BC，絕非兩套欄位**。兩條 S2C `0x38` subtype 路徑的差別是重算時機，不是讀到兩套城鎮。
2. `0x74(16)` 同時是 Q15 `Demand16` 的滿足鍵和 Q16 本身在候選掃描的排除鍵；不能只報告它單方面「解鎖」而忽略 self-exclusion／town gate。
3. NPC10338 **可能有其他 type2 quest**；未全面證明候選唯一，查找返回 *first*，不可宣稱 NPC 點擊必選 Q15。
4. `0x1C` 的兩個 WORD 來自 nested NPC event，不是 Q15；`0x3F` 是控制器條件式延後發出；`0x36` 未證 mode2 接取；分清 producer。
5. `S2C 0x40(15,state0)` 打開 TalkBox 是 Client receiver capability，**不是**經 C2S `0x3F(15)` 的官方配對保證。
6. SceneList questIdx15、Lua Scene3 的 `pindos_talkevent` 和 QuestInfo ID15 關聯有資源名／註解支持，但 `town001D.map` 不是 `town=5` 的明示映射，`CreateObject10047` 不是 NPC10338。
7. 完成研究並將原稿上 Git 不代表 T01 FULL-PASS／S00 RR ACCEPTED／Server 已實作或可玩。

## L. 建議接續：Quest15-①（T16-125 候選，正式段號以遠端新原稿再驗證）

- 重點為 Quest15 XML `type2/town5/field19/NPC10338/Demand16`、`Event.stp` SceneList/Pin(d)os，及「Scene3→真正 NPC→Server state」間未閉合的 bridge，避免重複本段已驗證 Demand16/town writer。
- Quest15-②～⑤ 才逐段打通 NPC actor、操作 sender、S2C consumer、任務後續／村莊 playable；沒有擅自把這些標成 Quest16-⑤未完成原因。
- 本文原稿為完整可重現靜態研究；在獲使用者當次「完成後上 Git」授權之下提交**此 Markdown** 到 `t16/roy/chatgpt-web/kr-temp-roy/`；本地內容生成時不得虛構尚未完成的遠端 commit/blob。GitHub 回讀核對另在對話中回報。

---

## M. 原始 KR BIN 指令證據（逐段真實 bytes、VA/raw/SHA256、呼叫與分支）

以下切片僅引用原始 `Tartaros.bin`；如有一個區間起點不能確定為指令邊界，以起點附近已驗證函式邊界重設。objdump 輸出包括機器碼 bytes；切片 SHA256 是原 BIN 直接 raw bytes SHA，不能僅靠同名函式稱已驗證。每段後附解釋可由上文 D～K 對應。

### M01. Application S2C slot0x38 handler registration

- VA: `0x004ADF2D..0x004ADF3D` (end exclusive); BIN raw `0xAD32D..0xAD33D`; `16` bytes；SHA256 `544b2a0b4b59903f6607120181439c616cc94fe5c154bc0917e819ad3b464ca8`。
- 指令：
```asm
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
```

### M02. 0x38 handler entrance and subtype0/2/6 decision

- VA: `0x004B1BF0..0x004B1D2E` (end exclusive); BIN raw `0xB0FF0..0xB112E`; `318` bytes；SHA256 `33f27f0815bc16dac8a2fad58061d691bb7be6dd2f4124d2055ad3d2e51abfea`。
- 指令：
```asm
  4b1bf0:	55                   	push   ebp
  4b1bf1:	8b ec                	mov    ebp,esp
  4b1bf3:	83 e4 f8             	and    esp,0xfffffff8
  4b1bf6:	6a ff                	push   0xffffffff
  4b1bf8:	68 7c 7d 94 00       	push   0x947d7c
  4b1bfd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b1c03:	50                   	push   eax
  4b1c04:	83 ec 08             	sub    esp,0x8
  4b1c07:	53                   	push   ebx
  4b1c08:	56                   	push   esi
  4b1c09:	57                   	push   edi
  4b1c0a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b1c0f:	33 c4                	xor    eax,esp
  4b1c11:	50                   	push   eax
  4b1c12:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b1c16:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b1c1c:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b1c23:	bf 01 00 00 00       	mov    edi,0x1
  4b1c28:	75 29                	jne    0x4b1c53
  4b1c2a:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4b1c30:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b1c37:	00 
  4b1c38:	e8 53 d0 02 00       	call   0x4dec90
  4b1c3d:	68 30 ce bc 00       	push   0xbcce30
  4b1c42:	e8 d3 06 3e 00       	call   0x89231a
  4b1c47:	83 c4 04             	add    esp,0x4
  4b1c4a:	83 ce ff             	or     esi,0xffffffff
  4b1c4d:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1c51:	eb 03                	jmp    0x4b1c56
  4b1c53:	83 ce ff             	or     esi,0xffffffff
  4b1c56:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b1c5b:	50                   	push   eax
  4b1c5c:	e8 1f be 08 00       	call   0x53da80
  4b1c61:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b1c68:	75 20                	jne    0x4b1c8a
  4b1c6a:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4b1c70:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4b1c74:	e8 17 d0 02 00       	call   0x4dec90
  4b1c79:	68 30 ce bc 00       	push   0xbcce30
  4b1c7e:	e8 97 06 3e 00       	call   0x89231a
  4b1c83:	83 c4 04             	add    esp,0x4
  4b1c86:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1c8a:	f6 05 44 92 fd 00 01 	test   BYTE PTR ds:0xfd9244,0x1
  4b1c91:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4b1c94:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4b1c96:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b1c9b:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  4b1c9e:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  4b1ca1:	89 50 38             	mov    DWORD PTR [eax+0x38],edx
  4b1ca4:	8a 4b 08             	mov    cl,BYTE PTR [ebx+0x8]
  4b1ca7:	88 48 3c             	mov    BYTE PTR [eax+0x3c],cl
  4b1caa:	75 24                	jne    0x4b1cd0
  4b1cac:	09 3d 44 92 fd 00    	or     DWORD PTR ds:0xfd9244,edi
  4b1cb2:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4b1cb9:	00 
  4b1cba:	e8 51 27 0a 00       	call   0x554410
  4b1cbf:	68 c0 df bc 00       	push   0xbcdfc0
  4b1cc4:	e8 51 06 3e 00       	call   0x89231a
  4b1cc9:	83 c4 04             	add    esp,0x4
  4b1ccc:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1cd0:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4b1cd7:	c7 05 54 92 fd 00 00 	mov    DWORD PTR ds:0xfd9254,0x0
  4b1cde:	00 00 00 
  4b1ce1:	75 24                	jne    0x4b1d07
  4b1ce3:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4b1ce9:	c7 44 24 20 03 00 00 	mov    DWORD PTR [esp+0x20],0x3
  4b1cf0:	00 
  4b1cf1:	e8 7a e4 0a 00       	call   0x560170
  4b1cf6:	68 10 d1 bc 00       	push   0xbcd110
  4b1cfb:	e8 1a 06 3e 00       	call   0x89231a
  4b1d00:	83 c4 04             	add    esp,0x4
  4b1d03:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1d07:	6a 00                	push   0x0
  4b1d09:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4b1d0e:	e8 9d 07 0b 00       	call   0x5624b0
  4b1d13:	0f b6 43 02          	movzx  eax,BYTE PTR [ebx+0x2]
  4b1d17:	83 e8 00             	sub    eax,0x0
  4b1d1a:	0f 84 cb 00 00 00    	je     0x4b1deb
  4b1d20:	83 e8 02             	sub    eax,0x2
  4b1d23:	74 5f                	je     0x4b1d84
  4b1d25:	83 e8 04             	sub    eax,0x4
  4b1d28:	0f 85 e0 00 00 00    	jne    0x4b1e0e
```

### M03. 0x38 subtype6: payload+7, payload+3, world+8C

- VA: `0x004B1D2E..0x004B1D84` (end exclusive); BIN raw `0xB112E..0xB1184`; `86` bytes；SHA256 `ff0b77c71b21758e0ec3d5c9f7a1f28047b80d71476991ed166d83a922b3a2d0`。
- 指令：
```asm
  4b1d2e:	f6 05 40 0e fc 00 01 	test   BYTE PTR ds:0xfc0e40,0x1
  4b1d35:	75 24                	jne    0x4b1d5b
  4b1d37:	09 3d 40 0e fc 00    	or     DWORD PTR ds:0xfc0e40,edi
  4b1d3d:	c7 44 24 20 05 00 00 	mov    DWORD PTR [esp+0x20],0x5
  4b1d44:	00 
  4b1d45:	e8 26 ea 08 00       	call   0x540770
  4b1d4a:	68 60 db bc 00       	push   0xbcdb60
  4b1d4f:	e8 c6 05 3e 00       	call   0x89231a
  4b1d54:	83 c4 04             	add    esp,0x4
  4b1d57:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1d5b:	0f b7 53 07          	movzx  edx,WORD PTR [ebx+0x7]
  4b1d5f:	52                   	push   edx
  4b1d60:	bf 48 0e fc 00       	mov    edi,0xfc0e48
  4b1d65:	e8 16 ec 08 00       	call   0x540980
  4b1d6a:	0f b7 73 03          	movzx  esi,WORD PTR [ebx+0x3]
  4b1d6e:	e8 ed d2 f5 ff       	call   0x40f060
  4b1d73:	89 b0 8c 00 00 00    	mov    DWORD PTR [eax+0x8c],esi
  4b1d79:	83 ce ff             	or     esi,0xffffffff
  4b1d7c:	8d 7e 02             	lea    edi,[esi+0x2]
  4b1d7f:	e9 8a 00 00 00       	jmp    0x4b1e0e
```

### M04. 0x38 subtype0/5 selector branch

- VA: `0x004B1EAB..0x004B1ECE` (end exclusive); BIN raw `0xB12AB..0xB12CE`; `35` bytes；SHA256 `4c1b7cfb56768a4349ba0105f90fc7640e29b42a167f45afb32264a75f48a510`。
- 指令：
```asm
  4b1eab:	8a 43 02             	mov    al,BYTE PTR [ebx+0x2]
  4b1eae:	84 c0                	test   al,al
  4b1eb0:	0f 84 f8 00 00 00    	je     0x4b1fae
  4b1eb6:	3c 05                	cmp    al,0x5
  4b1eb8:	0f 84 f0 00 00 00    	je     0x4b1fae
  4b1ebe:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  4b1ec5:	75 24                	jne    0x4b1eeb
  4b1ec7:	09 3d 60 0f fc 00    	or     DWORD PTR ds:0xfc0f60,edi
  4b1ecd:	c7       	mov    DWORD PTR [esp+0x20],0xf
  4b1ed4:	 
```

### M05. 0x38 subtype0/5: absolute world current town write and candidate rebuild

- VA: `0x004B2050..0x004B2108` (end exclusive); BIN raw `0xB1450..0xB1508`; `184` bytes；SHA256 `5f51e1479408ea6cb2d431a34578eb3ea66ba3b3622b067924bae4b6c4018e47`。
- 指令：
```asm
  4b2050:	0f b7 4b 03          	movzx  ecx,WORD PTR [ebx+0x3]
  4b2054:	51                   	push   ecx
  4b2055:	bf 48 0e fc 00       	mov    edi,0xfc0e48
  4b205a:	e8 e1 e9 08 00       	call   0x540a40
  4b205f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b2066:	75 25                	jne    0x4b208d
  4b2068:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b206f:	c7 44 24 20 0b 00 00 	mov    DWORD PTR [esp+0x20],0xb
  4b2076:	00 
  4b2077:	e8 14 cc 02 00       	call   0x4dec90
  4b207c:	68 30 ce bc 00       	push   0xbcce30
  4b2081:	e8 94 02 3e 00       	call   0x89231a
  4b2086:	83 c4 04             	add    esp,0x4
  4b2089:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b208d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b2094:	0f b7 53 03          	movzx  edx,WORD PTR [ebx+0x3]
  4b2098:	89 15 bc b1 fa 00    	mov    DWORD PTR ds:0xfab1bc,edx
  4b209e:	75 25                	jne    0x4b20c5
  4b20a0:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b20a7:	c7 44 24 20 0c 00 00 	mov    DWORD PTR [esp+0x20],0xc
  4b20ae:	00 
  4b20af:	e8 dc cb 02 00       	call   0x4dec90
  4b20b4:	68 30 ce bc 00       	push   0xbcce30
  4b20b9:	e8 5c 02 3e 00       	call   0x89231a
  4b20be:	83 c4 04             	add    esp,0x4
  4b20c1:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b20c5:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b20cc:	8b 35 bc b1 fa 00    	mov    esi,DWORD PTR ds:0xfab1bc
  4b20d2:	75 29                	jne    0x4b20fd
  4b20d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b20db:	c7 44 24 20 0d 00 00 	mov    DWORD PTR [esp+0x20],0xd
  4b20e2:	00 
  4b20e3:	e8 78 dd 04 00       	call   0x4ffe60
  4b20e8:	68 00 cf bc 00       	push   0xbccf00
  4b20ed:	e8 28 02 3e 00       	call   0x89231a
  4b20f2:	83 c4 04             	add    esp,0x4
  4b20f5:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b20fc:	ff 
  4b20fd:	56                   	push   esi
  4b20fe:	68 a0 b2 fa 00       	push   0xfab2a0
  4b2103:	e8 38 e1 04 00       	call   0x500240
```

### M06. world 0xFAB130 returned from 0x40F060

- VA: `0x0040F0B4..0x0040F0C9` (end exclusive); BIN raw `0xE4B4..0xE4C9`; `21` bytes；SHA256 `2074e95c0ace1597af354227968a91312acb5419f25e1823a70ac53342d64ff7`。
- 指令：
```asm
  40f0b4:	b8 30 b1 fa 00       	mov    eax,0xfab130
  40f0b9:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  40f0bd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  40f0c4:	59                   	pop    ecx
  40f0c5:	8b e5                	mov    esp,ebp
  40f0c7:	5d                   	pop    ebp
  40f0c8:	c3                   	ret
```

### M07. S2C 0x74 app u16 prerequisite insertion + town-dependent rebuild

- VA: `0x00503400..0x00503432` (end exclusive); BIN raw `0x102800..0x102832`; `50` bytes；SHA256 `cf7ba5ab73d9e69346b714c15548280c18cad07818ee32cb5c99109e061e48a7`。
- 指令：
```asm
  503400:	55                   	push   ebp
  503401:	8b ec                	mov    ebp,esp
  503403:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503406:	56                   	push   esi
  503407:	8b f1                	mov    esi,ecx
  503409:	57                   	push   edi
  50340a:	83 c0 02             	add    eax,0x2
  50340d:	8d be b0 5e 00 00    	lea    edi,[esi+0x5eb0]
  503413:	e8 c8 80 f4 ff       	call   0x44b4e0
  503418:	e8 43 bc f0 ff       	call   0x40f060
  50341d:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  503423:	50                   	push   eax
  503424:	56                   	push   esi
  503425:	e8 16 ce ff ff       	call   0x500240
  50342a:	5f                   	pop    edi
  50342b:	33 c0                	xor    eax,eax
  50342d:	5e                   	pop    esi
  50342e:	5d                   	pop    ebp
  50342f:	c2 0c 00             	ret    0xc
```

### M08. S2C 0x72 prerequisite reset + rebuild

- VA: `0x005033B0..0x005033FB` (end exclusive); BIN raw `0x1027B0..0x1027FB`; `75` bytes；SHA256 `422cf1e3967e43039f9012f08ec1d70a407bc4742e9bdb3356126bba1961adb5`。
- 指令：
```asm
  5033b0:	56                   	push   esi
  5033b1:	8b f1                	mov    esi,ecx
  5033b3:	8b 8e b4 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eb4]
  5033b9:	57                   	push   edi
  5033ba:	8b be b0 5e 00 00    	mov    edi,DWORD PTR [esi+0x5eb0]
  5033c0:	3b f9                	cmp    edi,ecx
  5033c2:	74 1e                	je     0x5033e2
  5033c4:	8b c1                	mov    eax,ecx
  5033c6:	2b c1                	sub    eax,ecx
  5033c8:	53                   	push   ebx
  5033c9:	d1 f8                	sar    eax,1
  5033cb:	8d 1c 00             	lea    ebx,[eax+eax*1]
  5033ce:	53                   	push   ebx
  5033cf:	51                   	push   ecx
  5033d0:	57                   	push   edi
  5033d1:	e8 1a df 38 00       	call   0x8912f0
  5033d6:	83 c4 0c             	add    esp,0xc
  5033d9:	03 df                	add    ebx,edi
  5033db:	89 9e b4 5e 00 00    	mov    DWORD PTR [esi+0x5eb4],ebx
  5033e1:	5b                   	pop    ebx
  5033e2:	e8 79 bc f0 ff       	call   0x40f060
  5033e7:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5033ed:	50                   	push   eax
  5033ee:	56                   	push   esi
  5033ef:	e8 4c ce ff ff       	call   0x500240
  5033f4:	5f                   	pop    edi
  5033f5:	33 c0                	xor    eax,eax
  5033f7:	5e                   	pop    esi
  5033f8:	c2 0c 00             	ret    0xc
```

### M09. candidate town+level+excluded+already-key filtering

- VA: `0x00500455..0x005004F0` (end exclusive); BIN raw `0xFF855..0xFF8F0`; `155` bytes；SHA256 `4cfc591bba2c0e98580748e94bfcd76b8cedd7f6f45436ed842f7d48c058308e`。
- 指令：
```asm
  500455:	3b ca                	cmp    ecx,edx
  500457:	74 2c                	je     0x500485
  500459:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  50045c:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  50045f:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  500463:	51                   	push   ecx
  500464:	8d 48 04             	lea    ecx,[eax+0x4]
  500467:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  50046b:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  50046f:	e8 cc b0 f4 ff       	call   0x44b540
  500474:	39 38                	cmp    DWORD PTR [eax],edi
  500476:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  50047a:	0f 94 c0             	sete   al
  50047d:	84 c0                	test   al,al
  50047f:	0f 84 c5 00 00 00    	je     0x50054a
  500485:	8b 53 20             	mov    edx,DWORD PTR [ebx+0x20]
  500488:	3b 55 0c             	cmp    edx,DWORD PTR [ebp+0xc]
  50048b:	0f 85 b9 00 00 00    	jne    0x50054a
  500491:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  500494:	3b 44 24 18          	cmp    eax,DWORD PTR [esp+0x18]
  500498:	0f 8f ac 00 00 00    	jg     0x50054a
  50049e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5004a1:	33 c0                	xor    eax,eax
  5004a3:	81 c1 d0 5e 00 00    	add    ecx,0x5ed0
  5004a9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5004b0:	0f b7 11             	movzx  edx,WORD PTR [ecx]
  5004b3:	3b d6                	cmp    edx,esi
  5004b5:	0f 84 8f 00 00 00    	je     0x50054a
  5004bb:	40                   	inc    eax
  5004bc:	83 c1 02             	add    ecx,0x2
  5004bf:	83 f8 14             	cmp    eax,0x14
  5004c2:	7c ec                	jl     0x5004b0
  5004c4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5004c7:	8b 88 b4 5e 00 00    	mov    ecx,DWORD PTR [eax+0x5eb4]
  5004cd:	8b 80 b0 5e 00 00    	mov    eax,DWORD PTR [eax+0x5eb0]
  5004d3:	3b c1                	cmp    eax,ecx
  5004d5:	74 12                	je     0x5004e9
  5004d7:	0f b7 10             	movzx  edx,WORD PTR [eax]
  5004da:	3b d6                	cmp    edx,esi
  5004dc:	74 07                	je     0x5004e5
  5004de:	83 c0 02             	add    eax,0x2
  5004e1:	3b c1                	cmp    eax,ecx
  5004e3:	75 f2                	jne    0x5004d7
  5004e5:	3b c1                	cmp    eax,ecx
  5004e7:	75 61                	jne    0x50054a
  5004e9:	3b df                	cmp    ebx,edi
  5004eb:	73 36                	jae    0x500523
  5004ed:	8b 44 24           	mov    eax,DWORD PTR [esp+0x44]
```

### M10. candidate demand vector and prerequisite vector equality gate

- VA: `0x00500631..0x005006B0` (end exclusive); BIN raw `0xFFA31..0xFFAB0`; `127` bytes；SHA256 `116b9e9704f2aec24b4fa10502b835a32a1b028c56f2ab5077a46137a8938af4`。
- 指令：
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

### M11. candidate success appended to WORD list

- VA: `0x005006B0..0x0050077E` (end exclusive); BIN raw `0xFFAB0..0xFFB7E`; `206` bytes；SHA256 `2394fefd5e66f649acbb0a9eecb89cdf59be1adc005b7615ee38626e324b9d9e`。
- 指令：
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
  5006ed:	3d fe ff ff 7f       	cmp    eax,0x7ffffffe
  5006f2:	0f 87 c8 00 00 00    	ja     0x5007c0
  5006f8:	2b ca                	sub    ecx,edx
  5006fa:	40                   	inc    eax
  5006fb:	d1 f9                	sar    ecx,1
  5006fd:	3b c1                	cmp    eax,ecx
  5006ff:	76 20                	jbe    0x500721
  500701:	8b d1                	mov    edx,ecx
  500703:	d1 ea                	shr    edx,1
  500705:	bb ff ff ff 7f       	mov    ebx,0x7fffffff
  50070a:	2b da                	sub    ebx,edx
  50070c:	3b d9                	cmp    ebx,ecx
  50070e:	73 04                	jae    0x500714
  500710:	33 c9                	xor    ecx,ecx
  500712:	eb 02                	jmp    0x500716
  500714:	03 ca                	add    ecx,edx
  500716:	3b c8                	cmp    ecx,eax
  500718:	0f 42 c8             	cmovb  ecx,eax
  50071b:	51                   	push   ecx
  50071c:	e8 7f af f4 ff       	call   0x44b6a0
  500721:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500724:	85 c0                	test   eax,eax
  500726:	74 52                	je     0x50077a
  500728:	8b 16                	mov    edx,DWORD PTR [esi]
  50072a:	66 8b 0c 7a          	mov    cx,WORD PTR [edx+edi*2]
  50072e:	66 89 08             	mov    WORD PTR [eax],cx
  500731:	eb 47                	jmp    0x50077a
  500733:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  500736:	3b c1                	cmp    eax,ecx
  500738:	75 36                	jne    0x500770
  50073a:	8b 16                	mov    edx,DWORD PTR [esi]
  50073c:	2b c2                	sub    eax,edx
  50073e:	d1 f8                	sar    eax,1
  500740:	3d fe ff ff 7f       	cmp    eax,0x7ffffffe
  500745:	77 79                	ja     0x5007c0
  500747:	2b ca                	sub    ecx,edx
  500749:	40                   	inc    eax
  50074a:	d1 f9                	sar    ecx,1
  50074c:	3b c1                	cmp    eax,ecx
  50074e:	76 20                	jbe    0x500770
  500750:	8b d1                	mov    edx,ecx
  500752:	d1 ea                	shr    edx,1
  500754:	bb ff ff ff 7f       	mov    ebx,0x7fffffff
  500759:	2b da                	sub    ebx,edx
  50075b:	3b d9                	cmp    ebx,ecx
  50075d:	73 04                	jae    0x500763
  50075f:	33 c9                	xor    ecx,ecx
  500761:	eb 02                	jmp    0x500765
  500763:	03 ca                	add    ecx,edx
  500765:	3b c8                	cmp    ecx,eax
  500767:	0f 42 c8             	cmovb  ecx,eax
  50076a:	51                   	push   ecx
  50076b:	e8 30 af f4 ff       	call   0x44b6a0
  500770:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500773:	85 c0                	test   eax,eax
  500775:	74 03                	je     0x50077a
  500777:	66 89 38             	mov    WORD PTR [eax],di
  50077a:	83 46 04 02          	add    DWORD PTR [esi+0x4],0x2
```

### M12. first type2 candidate returned or zero

- VA: `0x005008B0..0x00500944` (end exclusive); BIN raw `0xFFCB0..0xFFD44`; `148` bytes；SHA256 `aeee21cd72e41936104913bf9baa86f11b09632e77fa568f145237f67f62928c`。
- 指令：
```asm
  5008b0:	55                   	push   ebp
  5008b1:	8b ec                	mov    ebp,esp
  5008b3:	83 e4 f8             	and    esp,0xfffffff8
  5008b6:	6a ff                	push   0xffffffff
  5008b8:	68 28 88 90 00       	push   0x908828
  5008bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5008c3:	50                   	push   eax
  5008c4:	83 ec 18             	sub    esp,0x18
  5008c7:	56                   	push   esi
  5008c8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5008cd:	33 c4                	xor    eax,esp
  5008cf:	50                   	push   eax
  5008d0:	8d 44 24 20          	lea    eax,[esp+0x20]
  5008d4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5008da:	33 f6                	xor    esi,esi
  5008dc:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5008e0:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  5008e4:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5008e8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  5008ec:	50                   	push   eax
  5008ed:	51                   	push   ecx
  5008ee:	52                   	push   edx
  5008ef:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  5008f3:	e8 08 01 00 00       	call   0x500a00
  5008f8:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  5008fc:	3b 44 24 10          	cmp    eax,DWORD PTR [esp+0x10]
  500900:	75 20                	jne    0x500922
  500902:	3b c6                	cmp    eax,esi
  500904:	74 09                	je     0x50090f
  500906:	50                   	push   eax
  500907:	e8 00 09 39 00       	call   0x89120c
  50090c:	83 c4 04             	add    esp,0x4
  50090f:	33 c0                	xor    eax,eax
  500911:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500915:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50091c:	59                   	pop    ecx
  50091d:	5e                   	pop    esi
  50091e:	8b e5                	mov    esp,ebp
  500920:	5d                   	pop    ebp
  500921:	c3                   	ret
  500922:	8b 08                	mov    ecx,DWORD PTR [eax]
  500924:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  500927:	50                   	push   eax
  500928:	e8 df 08 39 00       	call   0x89120c
  50092d:	83 c4 04             	add    esp,0x4
  500930:	66 8b c6             	mov    ax,si
  500933:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500937:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50093e:	59                   	pop    ecx
  50093f:	5e                   	pop    esi
  500940:	8b e5                	mov    esp,ebp
  500942:	5d                   	pop    ebp
  500943:	c3                   	ret
```

### M13. candidate type2 and giver selector lookup

- VA: `0x00500A00..0x00500A7D` (end exclusive); BIN raw `0xFFE00..0xFFE7D`; `125` bytes；SHA256 `7249341812963eb07e7eff57ed46c249bb791275e54364b6265debf16c55a929`。
- 指令：
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
```

### M14. outer NPC event->nested 0x105BF->type2 selection->controller+0x1C

- VA: `0x005B9340..0x005B9498` (end exclusive); BIN raw `0x1B8740..0x1B8898`; `344` bytes；SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`。
- 指令：
```asm
  5b9340:	55                   	push   ebp
  5b9341:	8b ec                	mov    ebp,esp
  5b9343:	6a ff                	push   0xffffffff
  5b9345:	68 b7 73 94 00       	push   0x9473b7
  5b934a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9350:	50                   	push   eax
  5b9351:	83 ec 0c             	sub    esp,0xc
  5b9354:	56                   	push   esi
  5b9355:	57                   	push   edi
  5b9356:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b935b:	33 c5                	xor    eax,ebp
  5b935d:	50                   	push   eax
  5b935e:	8d 45 f4             	lea    eax,[ebp-0xc]
  5b9361:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b9367:	8b f1                	mov    esi,ecx
  5b9369:	8b 3d 80 25 bd 00    	mov    edi,DWORD PTR ds:0xbd2580
  5b936f:	85 f6                	test   esi,esi
  5b9371:	74 22                	je     0x5b9395
  5b9373:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9375:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b9378:	ff d2                	call   edx
  5b937a:	3d bd 05 01 00       	cmp    eax,0x105bd
  5b937f:	75 04                	jne    0x5b9385
  5b9381:	8b c6                	mov    eax,esi
  5b9383:	eb 12                	jmp    0x5b9397
  5b9385:	6a 00                	push   0x0
  5b9387:	68 c0 1f bf 00       	push   0xbf1fc0
  5b938c:	68 18 21 bf 00       	push   0xbf2118
  5b9391:	6a 00                	push   0x0
  5b9393:	ff d7                	call   edi
  5b9395:	33 c0                	xor    eax,eax
  5b9397:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b939a:	81 f9 a7 06 00 00    	cmp    ecx,0x6a7
  5b93a0:	0f 85 f2 00 00 00    	jne    0x5b9498
  5b93a6:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b93a9:	85 f6                	test   esi,esi
  5b93ab:	74 20                	je     0x5b93cd
  5b93ad:	8b 06                	mov    eax,DWORD PTR [esi]
  5b93af:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b93b2:	8b ce                	mov    ecx,esi
  5b93b4:	ff d2                	call   edx
  5b93b6:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b93bb:	74 12                	je     0x5b93cf
  5b93bd:	6a 00                	push   0x0
  5b93bf:	68 c0 1f bf 00       	push   0xbf1fc0
  5b93c4:	68 18 21 bf 00       	push   0xbf2118
  5b93c9:	6a 00                	push   0x0
  5b93cb:	ff d7                	call   edi
  5b93cd:	33 f6                	xor    esi,esi
  5b93cf:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b93d6:	75 27                	jne    0x5b93ff
  5b93d8:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b93df:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5b93e6:	e8 75 6a f4 ff       	call   0x4ffe60
  5b93eb:	68 00 cf bc 00       	push   0xbccf00
  5b93f0:	e8 25 8f 2d 00       	call   0x89231a
  5b93f5:	83 c4 04             	add    esp,0x4
  5b93f8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b93ff:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b9402:	ba a0 b2 fa 00       	mov    edx,0xfab2a0
  5b9407:	e8 a4 74 f4 ff       	call   0x5008b0
  5b940c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5b9413:	0f b7 f8             	movzx  edi,ax
  5b9416:	75 27                	jne    0x5b943f
  5b9418:	b8 01 00 00 00       	mov    eax,0x1
  5b941d:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  5b9423:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5b9426:	e8 45 6d fa ff       	call   0x560170
  5b942b:	68 10 d1 bc 00       	push   0xbcd110
  5b9430:	e8 e5 8e 2d 00       	call   0x89231a
  5b9435:	83 c4 04             	add    esp,0x4
  5b9438:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b943f:	6a 01                	push   0x1
  5b9441:	57                   	push   edi
  5b9442:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5b9447:	e8 14 83 fa ff       	call   0x561760
  5b944c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5b9453:	b8 1c 00 00 00       	mov    eax,0x1c
  5b9458:	66 89 45 e8          	mov    WORD PTR [ebp-0x18],ax
  5b945c:	66 8b 4e 18          	mov    cx,WORD PTR [esi+0x18]
  5b9460:	66 89 4d ea          	mov    WORD PTR [ebp-0x16],cx
  5b9464:	66 8b 56 1c          	mov    dx,WORD PTR [esi+0x1c]
  5b9468:	66 89 55 ec          	mov    WORD PTR [ebp-0x14],dx
  5b946c:	0f 85 e1 00 00 00    	jne    0x5b9553
  5b9472:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5b9478:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b947a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b947d:	6a 06                	push   0x6
  5b947f:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9482:	52                   	push   edx
  5b9483:	6a 00                	push   0x0
  5b9485:	ff d0                	call   eax
  5b9487:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b948a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b9491:	59                   	pop    ecx
  5b9492:	5f                   	pop    edi
  5b9493:	5e                   	pop    esi
  5b9494:	8b e5                	mov    esp,ebp
  5b9496:	5d                   	pop    ebp
  5b9497:	c3                   	ret
```

### M15. Controller 0x561760 argument saving

- VA: `0x005618D7..0x005618F8` (end exclusive); BIN raw `0x160CD7..0x160CF8`; `33` bytes；SHA256 `48d0703f36f7653d15ae81c2562b2f18285036e7f74baf1c542a28e0f2617124`。
- 指令：
```asm
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad      	or     DWORD PTR ds:0xfaadd4,esi
```

### M16. Controller deferred route selector and gate

- VA: `0x00561DB0..0x00561E02` (end exclusive); BIN raw `0x1611B0..0x161202`; `82` bytes；SHA256 `e9d43d42129dc10b14215e2c400e6126a60459e853dbe060eb62ac25b77153e1`。
- 指令：
```asm
  561db0:	55                   	push   ebp
  561db1:	8b ec                	mov    ebp,esp
  561db3:	83 e4 f8             	and    esp,0xfffffff8
  561db6:	6a ff                	push   0xffffffff
  561db8:	68 64 fc 93 00       	push   0x93fc64
  561dbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561dc3:	50                   	push   eax
  561dc4:	83 ec 10             	sub    esp,0x10
  561dc7:	53                   	push   ebx
  561dc8:	56                   	push   esi
  561dc9:	57                   	push   edi
  561dca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  561dcf:	33 c4                	xor    eax,esp
  561dd1:	50                   	push   eax
  561dd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  561dd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561ddc:	8b f9                	mov    edi,ecx
  561dde:	33 f6                	xor    esi,esi
  561de0:	80 bf 89 00 00 00 00 	cmp    BYTE PTR [edi+0x89],0x0
  561de7:	0f 84 73 01 00 00    	je     0x561f60
  561ded:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561df0:	0f 84 aa 00 00 00    	je     0x561ea0
  561df6:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561df9:	e8 52 24 ed ff       	call   0x434250
  561dfe:	bb 01 00 00        	mov    ebx,0x1
```

### M17. Controller conditional C2S 0x3F caller

- VA: `0x00561F8A..0x00561FEE` (end exclusive); BIN raw `0x16138A..0x1613EE`; `100` bytes；SHA256 `18b583accaa94bee9e0a9fd2d6923ab2ddc5544c3a7beba3740261f262df796a`。
- 指令：
```asm
  561f8a:	e8 11 b1 f4 ff       	call   0x4ad0a0
  561f8f:	6a ff                	push   0xffffffff
  561f91:	51                   	push   ecx
  561f92:	e8 99 92 f3 ff       	call   0x49b230
  561f97:	83 c4 04             	add    esp,0x4
  561f9a:	e8 b1 0b f4 ff       	call   0x4a2b50
  561f9f:	3b c3                	cmp    eax,ebx
  561fa1:	75 4e                	jne    0x561ff1
  561fa3:	e8 d8 26 eb ff       	call   0x414680
  561fa8:	8b 4f 3c             	mov    ecx,DWORD PTR [edi+0x3c]
  561fab:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561fae:	51                   	push   ecx
  561faf:	52                   	push   edx
  561fb0:	e8 eb 19 f4 ff       	call   0x4a39a0
  561fb5:	eb 3a                	jmp    0x561ff1
  561fb7:	8d 5f 3c             	lea    ebx,[edi+0x3c]
  561fba:	8d 77 74             	lea    esi,[edi+0x74]
  561fbd:	53                   	push   ebx
  561fbe:	e8 7d be 15 00       	call   0x6bde40
  561fc3:	50                   	push   eax
  561fc4:	56                   	push   esi
  561fc5:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  561fc9:	e8 c2 48 ed ff       	call   0x436890
  561fce:	57                   	push   edi
  561fcf:	e8 cc 03 00 00       	call   0x5623a0
  561fd4:	e8 a7 26 eb ff       	call   0x414680
  561fd9:	8b 03                	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                   	push   eax
  561fdf:	51                   	push   ecx
  561fe0:	e8 bb 19 f4 ff       	call   0x4a39a0
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00        	mov    ebx,0x1
```

### M18. C2S 0x3F builder and sender gate

- VA: `0x004A39A0..0x004A39EE` (end exclusive); BIN raw `0xA2DA0..0xA2DEE`; `78` bytes；SHA256 `46b77671cb9cf57bc96484c5ae9ce6ed408d97eb69c67ec55833803cdb80822e`。
- 指令：
```asm
  4a39a0:	55                   	push   ebp
  4a39a1:	8b ec                	mov    ebp,esp
  4a39a3:	83 ec 08             	sub    esp,0x8
  4a39a6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a39ad:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4a39b1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  4a39b5:	b8 3f 00 00 00       	mov    eax,0x3f
  4a39ba:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  4a39be:	b8 01 00 00 00       	mov    eax,0x1
  4a39c3:	66 89 4d fa          	mov    WORD PTR [ebp-0x6],cx
  4a39c7:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  4a39cb:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a39cf:	75 15                	jne    0x4a39e6
  4a39d1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a39d7:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a39d9:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a39dc:	6a 08                	push   0x8
  4a39de:	8d 45 f8             	lea    eax,[ebp-0x8]
  4a39e1:	50                   	push   eax
  4a39e2:	6a 00                	push   0x0
  4a39e4:	ff d2                	call   edx
  4a39e6:	8b e5                	mov    esp,ebp
  4a39e8:	5d                   	pop    ebp
  4a39e9:	c2 08 00             	ret    0x8
  4a39ec:	cc                   	int3
  4a39ed:	cc                   	int3
```

### M19. S2C 0x40 state0 event/quest side-effects

- VA: `0x00502270..0x005023B2` (end exclusive); BIN raw `0x101670..0x1017B2`; `322` bytes；SHA256 `a9654a42ed1279c7aa266114119fe8e8aa2aab520325ecb59aebfb8e08581249`。
- 指令：
```asm
  502270:	55                   	push   ebp
  502271:	8b ec                	mov    ebp,esp
  502273:	6a ff                	push   0xffffffff
  502275:	68 a8 41 94 00       	push   0x9441a8
  50227a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502280:	50                   	push   eax
  502281:	81 ec a4 00 00 00    	sub    esp,0xa4
  502287:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50228c:	33 c5                	xor    eax,ebp
  50228e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  502291:	53                   	push   ebx
  502292:	56                   	push   esi
  502293:	57                   	push   edi
  502294:	50                   	push   eax
  502295:	8d 45 f4             	lea    eax,[ebp-0xc]
  502298:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50229e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5022a1:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  5022a4:	33 ff                	xor    edi,edi
  5022a6:	89 8d 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],ecx
  5022ac:	3b c7                	cmp    eax,edi
  5022ae:	0f 85 16 04 00 00    	jne    0x5026ca
  5022b4:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5022bb:	75 24                	jne    0x5022e1
  5022bd:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  5022c4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5022c7:	e8 b4 51 08 00       	call   0x587480
  5022cc:	68 c0 cc bc 00       	push   0xbcccc0
  5022d1:	e8 44 00 39 00       	call   0x89231a
  5022d6:	83 c4 04             	add    esp,0x4
  5022d9:	83 ce ff             	or     esi,0xffffffff
  5022dc:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5022df:	eb 03                	jmp    0x5022e4
  5022e1:	83 ce ff             	or     esi,0xffffffff
  5022e4:	6a 18                	push   0x18
  5022e6:	e8 7d ef 38 00       	call   0x891268
  5022eb:	83 c4 04             	add    esp,0x4
  5022ee:	3b c7                	cmp    eax,edi
  5022f0:	74 1e                	je     0x502310
  5022f2:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  5022f5:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5022f8:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5022fb:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5022fe:	c7 40 10 81 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4281
  502305:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50230b:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  50230e:	eb 02                	jmp    0x502312
  502310:	33 c0                	xor    eax,eax
  502312:	50                   	push   eax
  502313:	e8 38 87 08 00       	call   0x58aa50
  502318:	83 c4 04             	add    esp,0x4
  50231b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502322:	75 23                	jne    0x502347
  502324:	b8 01 00 00 00       	mov    eax,0x1
  502329:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
  502355:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  502359:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  50235c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  50235f:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  502362:	c7 40 10 8b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438b
  502369:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50236f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502372:	eb 02                	jmp    0x502376
  502374:	33 c0                	xor    eax,eax
  502376:	50                   	push   eax
  502377:	e8 d4 86 08 00       	call   0x58aa50
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
```

### M20. S2C 0x40 state0 event+quest ID dataflow

- VA: `0x0050232F..0x005023AA` (end exclusive); BIN raw `0x10172F..0x1017AA`; `123` bytes；SHA256 `471189d1ed324d5b11892a0db1bf591b5411319ade9d7d2a56c751bd22910065`。
- 指令：
```asm
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
  502355:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  502359:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  50235c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  50235f:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  502362:	c7 40 10 8b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438b
  502369:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50236f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502372:	eb 02                	jmp    0x502376
  502374:	33 c0                	xor    eax,eax
  502376:	50                   	push   eax
  502377:	e8 d4 86 08 00       	call   0x58aa50
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e      	mov    esi,DWORD PTR [esi+0x5eac]
```

### M21. S2C 0x40 to F438B event/UI mode2 lookup

- VA: `0x005B6D20..0x005B6E5F` (end exclusive); BIN raw `0x1B6120..0x1B625F`; `319` bytes；SHA256 `ba77b541db2c32eb21c1ce303a90aae0606843d98f1a4b94e01fcd9867888bf6`。
- 指令：
```asm
  5b6d20:	55                   	push   ebp
  5b6d21:	8b ec                	mov    ebp,esp
  5b6d23:	83 e4 f8             	and    esp,0xfffffff8
  5b6d26:	6a ff                	push   0xffffffff
  5b6d28:	68 2c 93 94 00       	push   0x94932c
  5b6d2d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6d33:	50                   	push   eax
  5b6d34:	83 ec 10             	sub    esp,0x10
  5b6d37:	53                   	push   ebx
  5b6d38:	56                   	push   esi
  5b6d39:	57                   	push   edi
  5b6d3a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6d3f:	33 c4                	xor    eax,esp
  5b6d41:	50                   	push   eax
  5b6d42:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6d46:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6d4c:	8b f1                	mov    esi,ecx
  5b6d4e:	8b fa                	mov    edi,edx
  5b6d50:	85 f6                	test   esi,esi
  5b6d52:	74 26                	je     0x5b6d7a
  5b6d54:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6d56:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6d59:	ff d2                	call   edx
  5b6d5b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6d60:	75 04                	jne    0x5b6d66
  5b6d62:	8b de                	mov    ebx,esi
  5b6d64:	eb 16                	jmp    0x5b6d7c
  5b6d66:	6a 00                	push   0x0
  5b6d68:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6d6d:	68 18 21 bf 00       	push   0xbf2118
  5b6d72:	6a 00                	push   0x0
  5b6d74:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6d7a:	33 db                	xor    ebx,ebx
  5b6d7c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6d83:	75 29                	jne    0x5b6dae
  5b6d85:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6d8c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6d93:	00 
  5b6d94:	e8 c7 90 f4 ff       	call   0x4ffe60
  5b6d99:	68 00 cf bc 00       	push   0xbccf00
  5b6d9e:	e8 77 b5 2d 00       	call   0x89231a
  5b6da3:	83 c4 04             	add    esp,0x4
  5b6da6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6dad:	ff 
  5b6dae:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6db1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6db7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6dbb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6dbf:	51                   	push   ecx
  5b6dc0:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6dc4:	8b ce                	mov    ecx,esi
  5b6dc6:	e8 55 cf f4 ff       	call   0x503d20
  5b6dcb:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6dce:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6dd2:	3b c6                	cmp    eax,esi
  5b6dd4:	74 6c                	je     0x5b6e42
  5b6dd6:	8d 70 10             	lea    esi,[eax+0x10]
  5b6dd9:	85 f6                	test   esi,esi
  5b6ddb:	74 65                	je     0x5b6e42
  5b6ddd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6de4:	75 29                	jne    0x5b6e0f
  5b6de6:	b8 01 00 00 00       	mov    eax,0x1
  5b6deb:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6df1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6df5:	e8 96 7e f2 ff       	call   0x4dec90
  5b6dfa:	68 30 ce bc 00       	push   0xbcce30
  5b6dff:	e8 16 b5 2d 00       	call   0x89231a
  5b6e04:	83 c4 04             	add    esp,0x4
  5b6e07:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6e0e:	ff 
  5b6e0f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6e12:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6e17:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6e1a:	52                   	push   edx
  5b6e1b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e21:	6a 02                	push   0x2
  5b6e23:	50                   	push   eax
  5b6e24:	e8 f7 f6 07 00       	call   0x636520
  5b6e29:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6e2f:	51                   	push   ecx
  5b6e30:	e8 db 31 19 00       	call   0x74a010
  5b6e35:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e3b:	52                   	push   edx
  5b6e3c:	57                   	push   edi
  5b6e3d:	e8 be ff fd ff       	call   0x596e00
  5b6e42:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6e46:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6e4d:	59                   	pop    ecx
  5b6e4e:	5f                   	pop    edi
  5b6e4f:	5e                   	pop    esi
  5b6e50:	5b                   	pop    ebx
  5b6e51:	8b e5                	mov    esp,ebp
  5b6e53:	5d                   	pop    ebp
  5b6e54:	c3                   	ret
  5b6e55:	cc                   	int3
  5b6e56:	cc                   	int3
  5b6e57:	cc                   	int3
  5b6e58:	cc                   	int3
  5b6e59:	cc                   	int3
  5b6e5a:	cc                   	int3
  5b6e5b:	cc                   	int3
  5b6e5c:	cc                   	int3
  5b6e5d:	cc                   	int3
  5b6e5e:	cc                   	int3
```

### M22. TalkBox mode and quest/giver record initialization

- VA: `0x00636520..0x006365E0` (end exclusive); BIN raw `0x235920..0x2359E0`; `192` bytes；SHA256 `c660d5bb0bde8077fb2f7636be3b5eaf5eed7b7d3da7f0c7c0ac5474893bee30`。
- 指令：
```asm
  636520:	55                   	push   ebp
  636521:	8b ec                	mov    ebp,esp
  636523:	83 e4 f8             	and    esp,0xfffffff8
  636526:	6a ff                	push   0xffffffff
  636528:	68 32 92 94 00       	push   0x949232
  63652d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636533:	50                   	push   eax
  636534:	83 ec 28             	sub    esp,0x28
  636537:	53                   	push   ebx
  636538:	56                   	push   esi
  636539:	57                   	push   edi
  63653a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63653f:	33 c4                	xor    eax,esp
  636541:	50                   	push   eax
  636542:	8d 44 24 38          	lea    eax,[esp+0x38]
  636546:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63654c:	8b f1                	mov    esi,ecx
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
  6365b0:	6a 24                	push   0x24
  6365b2:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  6365b6:	e8 ad ac 25 00       	call   0x891268
  6365bb:	83 c4 04             	add    esp,0x4
  6365be:	3b c3                	cmp    eax,ebx
  6365c0:	0f 84 85 01 00 00    	je     0x63674b
  6365c6:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6365ca:	89 00                	mov    DWORD PTR [eax],eax
  6365cc:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41            	mov    BYTE PTR [ecx+0x20],0x1
```

### M23. Alternate controller scene-oriented branch, not same as C2S

- VA: `0x00561ED1..0x00561F1B` (end exclusive); BIN raw `0x1612D1..0x16131B`; `74` bytes；SHA256 `094ffab761503c38d7a9dd2bc35bd2acf6a3bfbed0cb04cc601992487d8f45ac`。
- 指令：
```asm
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00 00       	call   0x565720
  561ef8:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
  561f0b:	f6 05 c0 0f fc 00 01 	test   BYTE PTR ds:0xfc0fc0,0x1
  561f12:	75 25                	jne    0x561f39
  561f14:	83 0d c0 0f fc 00 01 	or     DWORD PTR ds:0xfc0fc0,0x1
```

## N. 研究結論與證據分級一覽

| 研究主張 | 原生／來源 | 等級 |
|---|---|---|
| `0x74(16)` 加入前置鍵，立即按 current town 重建 | 503400/503418/503425 | **BIN 直接** |
| key16 使 Quest15 Demand16 gate 通過，並在本次候選掃描排除 Quest16 本身 | 5004C4/500652；QuestInfo 先前 XML | **BIN 直接 + 既有原件擷取** |
| S2C 0x38 subtype6/0/5 分支寫的是同一 world selector，只有部分分支立即 rebuild | 4B1D73、4B2098、4B2103、40F0B4 | **BIN 直接** |
| town5+key16 與其他 gate 允許後 Quest15 可以進入 candidate list | 500240/500652 + XML Quest15 | **條件式 Client 靜態結論** |
| NPC10338 nested事件可 type2 篩到 Q15，但 first-only、非全表唯一證明 | 5B9407、5008B0/500A00 | **條件式 Client 靜態結論** |
| NPC local0x1C 與 controller deferred0x3F 是不同路徑 | 5B9453、561DB0、4A39A0 | **BIN 直接、場景條件未全解** |
| S2C0x40(15,state0) 能派送 F438B 開啟 mode2 TalkBox | 502270、5B6D20、636520；T16-121 event dispatch | **BIN 直接 + 已有原稿** |
| `pindos_talkevent` 為 Quest#15/Scene#3，載入 town001D 地圖並使用 object10047 | Event.stp XOR-FF 原文 | **直接原件片段** |
| 原版 Server 從 Q16 完成發 0x74 並在 town5 對 0x3F 回 0x40 | 無官方收發 trace/Server code | **未證，不可主張** |
| Quest15 在真實 Client 中可順利從 NPC10338 接取、跑 Scene3 並保存 | 無可用執行 trace | **待遊玩驗證** |

**Quest16 五項交接狀態**：① T16-118 resource/dependency Client bounded complete；② T16-119～121 NPC route+mode2 Client bounded complete；③ T16-122 C→S Client bounded complete；④ T16-123 S→C/state Client bounded complete；⑤ **T16-124 Q16→Q15 candidate/NPC/packet/UI/scenario static bounded complete**。本次完成 Q16 五研究**各自的有界 Client 靜態目標**，不表示 Quest15 五研究已完成，也不表示原版 Server 正確運作。
