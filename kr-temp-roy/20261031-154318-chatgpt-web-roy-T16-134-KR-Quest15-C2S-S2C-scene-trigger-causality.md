# T16-134 — Quest15 C→S／S→C 與 Pindos Scene3：原生 Client 因果、控制器欄位、場景 key 分流研究（KR BIN-first）

- 研究者：`chatgpt-web roy`；本地原稿建立 ` 2026-10-31T15:43:18+08:00 `，正式段號 **T16-134**；承接工作分支已有 T16-133（Git blob `72970ebc9b300f3b4911b21909756700d23be53c`）。
- **範圍與完成基準**：追查 Quest15 玩家互動導致的 `0x1C`／`0x3F`／`0x36` Client application producers，S2C `0x40`／`0x45`／`0x46`／`0x47`／`0x74` 對 QuestOwner、控制器及模式 UI 的消費，查明 Scene3 是否從「Quest15 完成」**原生直接／必然**推出，若不行則確認**正確的原生條件式場景入口、必要鍵與相反條件**。原版 Server 封包時序、決策、持久化和未經實測的真實可玩不是本段靜態證據可推導之事，但 Client 仍能查的來源不可推給 Server。
- 原始 KR `Tartaros.bin`：`12472320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp`：`11241597` bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。原件唯讀，未啟動遊戲、未 patch、未推二進位。
- PE section 位址：`.text` ImageBase 0x400000、RVA0x1000、raw0x400，所以 `.text raw=VA−0x400C00`；native `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。
- GitHub 正式開工核對：`main=e1a3c383a046a0514f7eee983bc2fc3173c3a113`（檢查當下）；T16 HEAD `ad70b74e4c3a5ced9e8fde80741a8694b16a1b5e`，compare ahead12/behind396。**同一對話已獲使用者明示執行 main→T16 Merge**（先前 merge SHA `ad70b74...`），依 03 規範本次只讀最新 `main`，**不再自動 Merge**。提交前將再次查 T16 HEAD，研究原稿只推 `t16/roy/chatgpt-web`。
- 最新 main 的 T01 精確退回 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 已為 **RESOLVED（限定勘誤，非 T16-117 全文 FULL-PASS）**；原來的錯誤 mode1→`0x36` 泛化與 TalkBox+0x88=QID 不得再用。T16 inbox 無 S00 待處理 RR；唯一 RR 台帳檢查無 owner_task=T16。主張不冒升 `NATIVE_VERIFIED`／`S00 ACCEPTED`／`SPEC STABLE`。
- 直接依據：前段 T16-127（Q15 C→S；blob `4e8e07719e882b4525481641dce929dd9786b87d`）、T16-128（Q15 S→C/UI；blob `bddbc8f94c32a3a69a43537be0631f7be3cb9a79`）、T16-129（場景；blob `edaaa5a94c56576eba8bf5c2ad5ff65ff6431c80`）、T16-131（controller key；blob `354ec7c6d226a720b74d54f17c289a3b6ca33295`）、T16-132（FIRST/NEXT gate；blob `16550cf62fb2ecbd539e07f568982e1d18d9b942`）、T16-133（四段 Lua；blob `72970ebc9b300f3b4911b21909756700d23be53c`）。**本稿直接重讀 KR BIN 和 Event 原件的指定片段**，避免把前段間接總結冒稱新原始證據。

## 一、研究問題與直接結論

### 靜態研究是否達標：**有界完成**；原版「實際完成 Q15 必播 Scene3」仍是**未證主張**

1. `0x46(QuestID15,substate0)`、`0x47(primary15,secondary3)`、`0x45(QuestID15)`、`0x40(QuestID15,state0)` 是**不同 S2C application handlers**；其 Client 可見副作用不等價，不能把它們說成一個成功 ACK 或同一封包的不同名稱。`0x46` 在 state0 除 local event/F438C 和 Quest cache 更新外**沒有直接呼叫 `0x561760` 或 `0x565720`**；這是一個關鍵反例。其他 callback/異步事件是否另能觸發場景不可由缺 direct CALL 一句排除。
2. `0x45` 在 **QuestRecord+0x44==2** 時傳遞 `(QID,QuestRecord+0x48)` 至 `0x561760`；`0x40 state0` 在 **QuestRecord+0x3C==2** 時傳 `(QID,QuestRecord+0x40)` 至 `0x561760`。兩者各自受 XML record 欄位／查找／狀態 gate 限定；`+0x3C` 與 `+0x44` 是不同 action descriptor，不能混用；**Quest15 完整原始 XML 的相應 type/param 在本次未完整解出**，所以無權斷言某個條件對 Q15 必為真或值3。
3. `0x47` 由 `[pkt+2]`、`[pkt+4]` 取**signed WORD**直接作兩個參數（第一 primary，第二 secondary）給 `0x561760`。**本輪另外直接驗證 `0x422F40` 的本體只初始化並回傳同一個 singleton 指標 `0xFB73C0`；它不讀入這兩個 stack args、不將 `(qid,param)` 轉換成 `(15,3)`**。0x40/45 caller 先 push 兩引數、再呼叫 accessor、再以 ECX=accessor 返回值呼叫 0x561760，是 thiscall 典型用法；此前若把它當成鍵值轉換函式應更正。
4. Quest15 NPC10338 的 type2 有候選時，`0x5B9340` 可藉 `0x5008B0` 取得 ID15，送 `(15,1)` 至 controller，並**獨立**（sender gate允許）建構 C→S `0x1C` 6B，兩個 payload WORD 來自**event+0x18/+0x1C**，不是直接送 QuestID15。`0x3F` 是 controller 延後分支在 gate 允許時送的 8B `(0x3F, primary, secondary, 1)`；`0x36` 有獨立 producer，不能以 mode2 UI 必然按鈕動作推定它發出。Sender gate=0 代表調用 enqueue vfunc，不保證 socket 實際成功、原版 Server 已收到或 ACK。
5. `0x561760` 有 busy gate、特殊狀態早退、scene/normal 模式二分與 `(primary,secondary)` 的條件寫入；`0x561DB0` 在 scene flag 非0時依 **Table/SceneList** 的有序向量 `0x47E640` 求 NEXT；只有 successor≠0 才呼叫 `0x565720`。`0x565720` 對 `(chapter,scene)` 查**Event/SceneList**，命中且資源／VM載入成功才跑腳本。`0x47B5C0` 的 chapter 物件入口另外依 `0x47E890` FIRST 取值；這與 Q15 0x46 state0 不同。
6. **Scene3 原件** `Event.stp`（XOR-FF 解碼）確有 Quest #15/Scene #3 `pindos_talkevent`，載入 `town001D.map`、四次 `OpenTalkScene(3,18/24/20/21)`、`DoProlog(1)` 與最後 `RestoreMap()`；這是**命中正確場景鍵後的 Client 演出**，不是「完成 Q15」或「取得獎勵」、「原版 Server 回 0x47(15,3)」的證據。
7. **Server-only 與 Client unknown 分開**：原版 Server 是否回 0x46 和 0x47、順序、任務前置與獎勵屬 Server 待設計；但 Table/SceneList 的實際 row/順序、Quest15 AcceptAction/CompleteAction type/param、controller busy deferred callback/scene event race 等仍屬原件可研究的 Client／資源缺口（需進一步解包／定位），不能以「Server 未知」掩蓋。

> 研究結論的精確語義：**完成 T16-134「已知業務封包與 Scene3 的條件式因果與不等價」原生 Client 靜態矩陣**；不宣稱完成「官方任務交付後一定播放 Scene3」的 runtime/Server 因果、T01 全文審核、T16 整體可玩驗收。若有人要求『必然進入 Scene3』，須另有真實 Table row／來源 action descriptor、Server 給定的觸發條件以及可玩時序驗證。這些待補證不改寫為官方已知行為。

## 二、玩家情境／opcode／local effect／場景鍵之精確關係

| 時點／Client 條件 | 原生 C→S／S→C application | 必要門檻與資料來源 | 直接 Client 副作用 | Scene3 因果等級／Server 義務 |
|---|---|---|---|---|
| NPC10338 被點／type2 candidate15 存在 | C→S `0x1C` 6B (`1C 00` + nested event兩WORD) | action `F43D9`→`0x105BD/0x105BF` 且 action=0x6A7；`0x5008B0` candidate gate；`0xFBA798==0` | `0x561760(15,1)`、sender vtable+0x10 enqueue attempt | 不是 Accept Quest15，也不指示 Scene3；Server 須定義 NPC context 對應策略 |
| Controller normal deferred | C→S `0x3F` 8B（Q15參數 `(15,1)` 時為 `3F 00 0F 00 01 00 01 00`） | `0x561DB0` normal mode、pending/key、sender gate與其它狀態通過 | 嘗試傳送 scene/controller pair | 不是原版 Server 0x40 或 0x46 ACK 證據；不得固定第三欄參數為 scene3 |
| 任務 UI 獨立 submit producer | C→S `0x36` 4B（QID15 條件輸入 `36 00 0F 00`） | `0x4B3510` 使用 packet+2 的 WORD；`0x636E10` 為另一條具 action/mode gate 的 producer | sender vfunc+0x10 enqueue attempt；mode2 不自動走 mode1 F4402 | 「真的接取／交付」的 Server 端配對須另行定義，不能把全部 senders 當一個 opcode |
| S→C `0x40(15,state0)` | pkt+2=15、DWORD+4=0（示例純 fixture） | QuestInfo map hit；record+0x3C==2 時可走 controller | 其他 state/cache/UI 細節承 T16-123/128；受 action descriptor 2 gate 時送 `(15,record+0x40)` | 不直接固定是 Scene3；未證實 Server 原始回送時機 |
| S→C `0x45(15)` | pkt+2=15（示例純 fixture） | QuestRecord+0x44 `CompleteAction.type==2` | controller `(15,record+0x48)`；==3另建立 F4306；其餘走訊息／通知 | 此是更接近完成 action 的**條件式 scene trigger**，但不保證 Q15 type2 或 param3 |
| S→C `0x46(15,0)` | pkt+2=15、WORD+4=0 | QuestRecord 命中且 record+8!=3 才 append key15 | `0x5000D0` exclusion remove、`0x44B4E0` prereq append（有 gate）、`0x500240` rebuild、事件 F438C→mode3 | **本 handler 沒有直接呼叫 scene controller**，不可拿它作 Scene3 命令 |
| S→C `0x46(15,1..5)` | 非0 substate | 分支分流依類型與 UI 資源 | 文字／事件/通知差異，非 substate0 直接資料寫入 | 不可聲稱完成標記或 Scene3 路徑 |
| S→C `0x47(15,3)` | `47 00 0F 00 03 00`（**人工假設輸入，不是官方抓包**） | signed WORD→`0x561760(15,3)`；busy／特殊 state 等 gate | 更新 controller 條件式 scene/normal 狀態 | **不是直接 `0x565720`**；若進後續 key/scene lookup 且 Event row存在才有 Pindos 路徑 |
| S→C `0x74(15)` 或 `0x6F` snapshot含15 | 單筆 prereq 或 bitmask snapshot | owner+0x5EB0 寫入或覆蓋；rebuild | 影響可接候選，與 Chapter key 不同 namespace | 不代表 Scene3 或官方獎勵交易 |
| Scene key 由 chapter UI 提供 | 無必然 C→S | object+0x248 ChapterIndex 有 FIRST scene；key !=EA61 | `0x47D530→0x47E890→0x47B5C0→0x565720` | 若 Chapter row `(15,[...,3,...])` 真存在，該路徑可以達 Scene3；目前未直接讀到真實 row |
| scene NEXT 遞進 | 可無封包 | `controller+0x89!=0`、`0x47E640` 真實有序 successor 非0 | `0x561DB0→0x565720(chapter, successor)` | 不可將 next 寫死成 old+1、不可不經映射直達 Scene3 |
| Scene3 Lua 內 Prolog/RestoreMap | 無直接可證 Server ACK/發獎指令 | Event pair命中、script/VM callback可用、未被取消 | `DoProlog(1)` 經 native Q.Prolog callback、`RestoreMap` 經間接 callback | 遊玩/回圖/進度權威與成功回應仍待契約設計／測試 |

## 三、資料所有權與事件/控制器鏈（避免相似欄位誤認）

### 3.1 記憶體字段與 Client namespace

| 來源／物件 | 重要欄位 | native 目的 | 禁止直接推論 |
|---|---|---|---|
| NPC event child `0x105BF` | `event+0x14` = giver selector；`+0x18/+0x1C` = 分別 C2S 0x1C 的兩 WORD | `0x5008B0` 選 type2 任務；另建 0x1C | `+0x18` 未證與 QuestID 或 Script scene ID 同值 |
| QuestRecord | `+0x3C/+0x40` | 0x40 類 scene action descriptor (AcceptAction) | 不能與 `+0x44/+0x48` 互換 |
| QuestRecord | `+0x44/+0x48` | 0x45 類 scene action descriptor (CompleteAction) | 不能從 UI mode3 證明 type=2/param=3 |
| QuestOwner | `+0x5EB0/+0x5EB4` | prereq WORD vector、0x74 append、0x6F snapshot/0x46 conditional append | 不是 Server DB 已持久化證據 |
| QuestOwner | `+0x5ED0` | 20-slot exclusion WORD cache；0x40/46不同方向操作 | 不是 quest accepted/failed state singleton |
| World context `0x40F060()` | `+0x8C` = current town selector | candidate rebuild | 不是 Event Scene key 或 town001D map |
| SceneController singleton `0xFB73C0` | `+0x28` busy/active, `+0x38` primary, `+0x3C` secondary, `+0x89` mode/scene flag | 0x561760/0x565720/0x561DB0; FIFO/busy differ | `+0x38=15` 不等於 QID15 已由 Server 正式完成 |
| Chapter object | `+0x248` chapter/table primary | 0x47E890 FIRST | 不自動等於 QuestID 或 NPC ID |
| Event SceneList map | `(primary,secondary) -> funcName` | 0x565720 Lua loader | Event.stp Scene3 註解不等於 runtime selected key |

### 3.2 原生條件因果圖

```text
NPC10338 interaction (0x105BD 6A7 / 0x105BF giver)
      ├─> 0x5008B0 type2 candidate -> QID15 -> 0x561760(15,1)
      └─> 0x1C (event+18,+1C) -> sender queue [gate]
Scene controller normal deferred / pending [condition]
      └─> 0x4A39A0 -> 0x3F(primary,secondary,1) -> sender queue
Quest/UI independent confirm/event [condition]
      └─> 0x4B3510 or mode1 action producer -> 0x36(QID) -> sender queue
                   ┊  Server-side pairing unknown (not a proven arrow)
Inbound S2C 0x40 QID15,state0 ─┐
  [QuestRecord+3C==2]           ├─> 0x561760(QID, record param)
Inbound S2C 0x45 QID15 ────────┘    [only if record+44==2 for 0x45]
Inbound S2C 0x47 (primary,secondary) ─> 0x561760(primary,secondary)
                                           ├─ normal pending → maybe 0x3F
                                           ├─ busy/deferred → other callback
                                           └─ scene path/advance → 0x565720
                                                  └─ Event SceneList pair lookup
                                                       └─ Scene3 script if pair (15,3)
Inbound S2C 0x46 QID15,state0 ─> QuestOwner cache mutate + F438C(mode3)
                                           X no direct 0x561760 call in this handler
Independent chapter-object selection ─> 0x47E890 FIRST ─> 0x565720
Scene active NEXT ─> 0x47E640(table ordered) ─> 0x565720 if next !=0
Scene3 script ─> talks / DoProlog(1) / RestoreMap / RevPhase1
```

### 3.3 新核對：`0x422F40` 是 singleton accessor，不是 scene-key mapper

`0x422F8E` 直接 `mov eax,0xFB73C0` 後返回；在函式內**不存取** caller 剛 push 的 `[esp+...]` 值。`0x50288E` / `0x502440` 的呼叫排列是：先把 `record-param` 與 QuestID 兩個 DWORD push 於 stack，再 call `0x422F40` 取得 `this`、`mov ecx,eax`，立即 `call 0x561760`；所以**原封不動的 stack 參數才是 scene controller 兩鍵來源**。同一區域其他 `(15,3)` 數字只是假設輸入；沒有「0x422F40 將完成 Quest15 轉成 scene3」這件事。可用本稿 S04/S05/S06 原始 bytes 重現。

### 3.4 事件負例與兩個本質不同的完成字眼

- **S2C `0x46` 完成/交付樣式**：native state0 可能 append prerequisite key15 和 mode3 TalkBox，但不保證原版 Server 已付獎，也不會直接跳 `0x565720(15,3)`。它屬 QuestOwner/UI 變更，不能作為 Script Scene3 唯一入口。
- **S2C `0x45` CompleteAction branch**：若 record+0x44==2，能把 record+0x48 當 scene secondary 輸入 controller。此條鏈不等於 `0x46`；對 Quest15 實際 resource type/param 必須要有 QuestInfo 完整元資料才可實例化為 `(15,3)`，否則只能是有界規格選項。
- **S2C `0x47` 明確 pair**：不讀 QuestRecord，但先經 controller 的 gate；不能逕自視為任務完成 ACK。
- **本地 Lua `DoProlog(1)`**：`0x569AD0 → 0x56A430 → indirect callback [0xFE282C]`；目前本段未追出注入 callback 的完整 writer/身分，不能當作原版 Server Quest15 保存／完成。

## 四、偽碼（有條件、有反例；不是官方 Server 邏輯）

```cpp
// 所有符號名暫定，只對可確認的 Client 控制流程作摘要。
void on_s2c_0x46(uint8_t *p, QuestOwner *q) {
  uint16_t qid = u16(p+2), substate = u16(p+4);
  post_event_F4282(qid); // allocation/enqueue may fail
  if (substate == 0) {
    auto rec = q->questInfo.find(qid);
    q->excludedSlots.erase(qid);          // 0x5000D0
    if (rec && rec->subtype != 3) q->prerequisites.append(qid);
    rebuild_candidates(q,current_town);  // 0x500240
    post_event_F438C(qid);                // mode3 if record/UI permit
    // NOTE: no direct call to sceneController(15,3)
  } else {
    notification_or_other_event(substate); // branch-specific, not same updater
  }
}
void on_s2c_0x45(uint8_t *p, QuestOwner *q) {
  int qid = s16(p+2); auto rec=q->questInfo.find(qid); if(!rec)return;
  if(rec->completeAction.type==2) sceneController(qid,rec->completeAction.param);
  else if(rec->completeAction.type==3) post_event_F4306(rec->completeAction.otherField);
  // other UI/locale notifications may continue on some branches
}
void on_s2c_0x47(uint8_t *p) {
  sceneController(s16(p+2),s16(p+4)); // busy/scene/normal gates later
}
void on_scene_next(Controller* c) {
  if(c->modeFlag) {
    auto next=TableSceneList.next(c->primary,c->secondary); // may be 0
    if(next!=0) loadEventSceneIfExists(c->primary,next);
    else resetKeysAsPerNativeBranches(c);
  } else {
    // deferred 0x3F possible only after specified gates
  }
}
```

## 五、原始 Event.stp 實證：Scene3 不能取代 Server ACK

- XOR-FF 後 first-hand `-- Quest #15 / Scene #3 ...` string 在原始檔 offset **`0x8C1C3E`** (`9182270` decimal)，`town001D.map` 在 `9182450`，本稿獨立重讀原件；`Event.stp` 的文本/索引與 `Table.stp` Chapter row 並非同一份資料。
- 腳本中直接可見 `CreateObject(4,10047,...)`、四次 `OpenTalkScene(3,18/24/20/21)`、Prolog 與 RestoreMap；這些是演出，不含原版 Server acceptance 或 reward mutation semantics。

```lua
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

## 六、驗證矩陣與風險（供 S00 Server SPEC / TEST 去重收件）

| 測試條件（僅為待構造 fixture，並非官服抓包） | 期望 Client 原生 branch | 與 Scene3 的關係 | 建議 SPEC/TEST |
|---|---|---|---|
| `0x46(q15,sub0)`，record 存在且 subtype!=3 | exclusion remove、key15 append、candidate rebuild、F438C(mode3) | 不產生立即 Scene3 | 交付與劇情分開；禁止 Server 將二者等同 |
| `0x46(q15,sub0)`，record 不存在/subtype==3 | 不追加 key15，其餘有條件繼續 | 不保證 Scene3 | 缺 record 負測試 |
| `0x45(q15)`，completeAction.type=2,param=3 | `0x561760(15,3)`，再受 busy/scene gate | **條件式**可達後續 scene | type2 分支測試；真 XML 未確認不能硬碼 |
| `0x45(q15)`，completeAction.type=3 | local F4306 event，非前列 controller | 不等於 scene3 | XML action subtype 分支 |
| `0x47(15,3)`，idle但 Controller不在可立即執行狀態 | controller 保存/延後或走 normal C→S 0x3F（依 gate） | 不能立即宣稱播放 | busy/pending/normal split |
| `0x47(15,3)`，scene running/ready, Event map hit | 有條件 Event SceneList 載入 | 僅此 input 直接指定 key3 | 需證 Table/scene key & loader成功 |
| `0x47(15,3)`，busy | delegate 0x6EDB60，skip immediate key write | 不得覆蓋當前 Scene3 | idempotence/deferred replay test |
| chapter FIRST 不存在/空 vector | `0x47E890` 返回0；follow-up不自動補3 | 不得擅自 fallback3 | 缺序列的誤觸發測試 |
| NEXT successor不存在 | NEXT=0→可能清 key，無後續 Lua | 不可 old+1→3 | ordered list終點測試 |
| Script3 callback failure/cancel | Prolog/RestoreMap/RevPhase1 可能不完整 | UI/input不能假保證正常恢復 | 場景恢復異常驗收 |
| S→C `0x6F` 在 `0x46` 之後覆蓋 bitmask | prereq cache 以全量 snapshot 為準 | Scene keys 不應從快照直接猜 | snapshot與delta順序契約 |

**Server 待開發需求（供 S00 登錄候選，未擅自建立 RR／REQ/ADR）**：

- 決定 Quest15 前置 Demand16／world town5／NPC10338 可接條件、拒絕/重試和角色保存；收到 `0x1C`、`0x3F`、`0x36` 後各自以**不同 business event**處理，不能無條件視為完成或簡化成同一封包。
- 規定應何時下發原生 Client 能處理的 `0x40/0x45/0x46/0x47` 和 `0x74/0x6F`，並以明確 SPEC／ADR 列出自己設計的 compatibility policy；**不可聲稱官方一定先 0x46 再0x47 或一定送 0x47(15,3)**。
- 由 Server 權威管理是否發放 Quest15 reward、是否進入 Pindos、重登後 quest snapshot 與劇情重播；離線狀態和場景播放 token 的 atomicity/idempotence 是新 Server 實作問題，並非 BIN 中還原出的官方規則。

**Client 待逆向**：

- `Table.stp` 內 `Table/SceneList.xml` 的原始 chapter key、ordered sceneIdx rows，Quest15 原始 `AcceptAction/CompleteAction` type/param、Quest15 reward/type subtype 欄位仍須解包或從已獲原件的可信 XML 對照；本輪未把這些指定值當作已證。
- `0x6EDB60` 的 queued/deferred pair 如何 replay、`0x565720` miss 時的 global active reset、Scene3 `Q.Prolog`／`Q.RestoreMap` 注入 callback 的完整 writer/target、Lua VM error/cancellation UI unwind 是可繼續追的 native Client 分支；不得僅因缺 Server 就延後有資料可挖的部分。
- T02 的 framing/connection lane 與 application opcode 0x1C/0x3F/0x36 的真正 wire 端映射仍依該 Task 的 verified evidence；本次只證 Client 交 sender+0x10、未做 socket capture。

**跨 Task 待整合**：T02 framing、T07 scene/LoadMap/RestoreMap、T08 NPC actor、T14 stage completion、T15 persistence、T06 UI mode2/3。須交 S00 判定是否提出 RR，不自行修改別的 Task 研究及排程。

**待遊玩驗證**：NPC10338 真的按擊→應用訊息序列、Quest15 accepted/completed 狀態、Scene3 完整播放與返回、地圖/斷線/重登、獎勵/重複請求、失敗 callback。沒有實測或原版 Server 封包實際時序就只能給條件式模型。

## 七、Code xref 驗證方法與函式入口消費負證據

- 各重點區間用有指令對齊的原生 objdump，確認 direct `E8` call target；`0x46` 本體不含直接的 `0x561760` 或 `0x565720` call。**否定限於函式內直接 `E8` call；vtable、事件佇列、間接 handler、後續 UI callback 仍可能再經別的路徑。**
- `0x422F40` 回傳全域 singleton `0xFB73C0` 的 bytes 直接在 S06，沒有引數轉換；`0x45`／`0x40` 的 caller push param、push QID 後 call accessor，再把 EAX 作 thiscall ECX。這是本段與舊研究相比新增的明確語意閉合。
- 不可把 Event `0x105B9` 的 `action F438B`（mode2）與 `F438C`（mode3）、`0x105BF` NPC context 混為同一派送；任務 QID15 與 sceneIdx3、NPC ID10338、field19、town5、map `town001D` 各有 namespace。

| 函式掃描範圍 | 擷取的 direct call 數 | 指向 controller 0x561760 | 指向 scene entry 0x565720 | 指向 prereq append 0x44B4E0 | 指向 candidate rebuild 0x500240 | 指向 event enqueue 0x58AA50 |
|---|---:|---|---|---|---|---|
| 0x46 handler `0x502B40..0x503040` | 44 | no | no | yes | yes | yes |
| 0x47 handler `0x503040..0x5030BF` | 3 | yes | no | no | no | no |
| 0x45 handler `0x5027D0..0x502B40` | 29 | yes | no | no | no | yes |
| 0x40 handler `0x502270..0x5027D0` | 50 | yes | no | no | yes | yes |

**注意**：只列出此區間指令反組譯列的 direct `call 0x...`，不包含間接 call，也不是對整個 12MB 程式的負存在證明；若某函式內還有事件佇列、Lua callback、子函式二次調用，需依真正邊界另查。

## 八、Native bytes／反組譯附錄（全部直接從 BIN）

### S01 — NPC 0x105BD/0x105BF action6A7→type2 candidate QID15 and controller plus separate 0x1C

VA `[0x005B9373,0x005B9498)`；raw `[0x01B8773,0x01B8898)`；293 bytes；SHA256 `67ef78a3bf02036dfcfd44cdb3fd5233507ee72f12e5687c935e42ff0411fc36`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
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

### S02 — controller application 0x3F 8B sender gate and vtable

VA `[0x004A39A0,0x004A39EA)`；raw `[0x00A2DA0,0x00A2DEA)`；74 bytes；SHA256 `3a479a57233bd6f1371bb8948da62d329db1366f228a4896261d2090af9c9456`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

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
  4a39e9:	c2               	ret    0x8
```

### S03 — independent 0x36 4B producer and sender gate

VA `[0x004B3510,0x004B356C)`；raw `[0x00B2910,0x00B296C)`；92 bytes；SHA256 `71b378cac33808dc4419240471935b14535edabd107b8ca1bad0664f8b14793c`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  4b3510:	55                   	push   ebp
  4b3511:	8b ec                	mov    ebp,esp
  4b3513:	51                   	push   ecx
  4b3514:	b8 01 00 00 00       	mov    eax,0x1
  4b3519:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4b351f:	75 13                	jne    0x4b3534
  4b3521:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4b3527:	68 10 cf bc 00       	push   0xbccf10
  4b352c:	e8 e9 ed 3d 00       	call   0x89231a
  4b3531:	83 c4 04             	add    esp,0x4
  4b3534:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b353b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b353e:	66 8b 51 02          	mov    dx,WORD PTR [ecx+0x2]
  4b3542:	b8 36 00 00 00       	mov    eax,0x36
  4b3547:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4b354b:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  4b354f:	75 15                	jne    0x4b3566
  4b3551:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b3557:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b3559:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b355c:	6a 04                	push   0x4
  4b355e:	8d 55 fc             	lea    edx,[ebp-0x4]
  4b3561:	52                   	push   edx
  4b3562:	6a 00                	push   0x0
  4b3564:	ff d0                	call   eax
  4b3566:	33 c0                	xor    eax,eax
  4b3568:	8b e5                	mov    esp,ebp
  4b356a:	5d                   	pop    ebp
  4b356b:	c2               	ret    0xc
```

### S04 — S2C 0x40 QuestInfo record action/type scene-controller branch (subtype2)

VA `[0x005023DC,0x0050244C)`；raw `[0x01017DC,0x010184C)`；112 bytes；SHA256 `57a9fec67592c13b3455e9b646e33622339886347e216641ed0d0c91128d0049`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  5023dc:	0f 84 ca 03 00 00    	je     0x5027ac
  5023e2:	8b 43 3c             	mov    eax,DWORD PTR [ebx+0x3c]
  5023e5:	83 e8 02             	sub    eax,0x2
  5023e8:	74 51                	je     0x50243b
  5023ea:	48                   	dec    eax
  5023eb:	75 5f                	jne    0x50244c
  5023ed:	e8 ce 30 f0 ff       	call   0x4054c0
  5023f2:	6a 18                	push   0x18
  5023f4:	e8 6f ee 38 00       	call   0x891268
  5023f9:	83 c4 04             	add    esp,0x4
  5023fc:	85 c0                	test   eax,eax
  5023fe:	74 2e                	je     0x50242e
  502400:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502403:	83 ca ff             	or     edx,0xffffffff
  502406:	50                   	push   eax
  502407:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50240a:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50240d:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  502414:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  50241b:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502421:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502424:	e8 27 86 08 00       	call   0x58aa50
  502429:	e9 7b 03 00 00       	jmp    0x5027a9
  50242e:	33 c0                	xor    eax,eax
  502430:	50                   	push   eax
  502431:	e8 1a 86 08 00       	call   0x58aa50
  502436:	e9 6e 03 00 00       	jmp    0x5027a9
  50243b:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  50243e:	51                   	push   ecx
  50243f:	57                   	push   edi
  502440:	e8 fb 0a f2 ff       	call   0x422f40
  502445:	8b c8                	mov    ecx,eax
  502447:	e8 14 f3 05 00       	call   0x561760
```

### S05 — S2C 0x45 record+0x44 CompleteAction type and parameter dispatch

VA `[0x005027FB,0x0050289A)`；raw `[0x0101BFB,0x0101C9A)`；159 bytes；SHA256 `bf46ccdcc9f0fa7dcd17d8cec748cc1dbab9c1ed2f3835d9a0a0c088bee561d3`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  5027fb:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5027fe:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  502804:	0f bf 78 02          	movsx  edi,WORD PTR [eax+0x2]
  502808:	8d 4d 90             	lea    ecx,[ebp-0x70]
  50280b:	51                   	push   ecx
  50280c:	8d 45 98             	lea    eax,[ebp-0x68]
  50280f:	8b ce                	mov    ecx,esi
  502811:	89 7d 90             	mov    DWORD PTR [ebp-0x70],edi
  502814:	e8 07 15 00 00       	call   0x503d20
  502819:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  50281c:	8b 5d 98             	mov    ebx,DWORD PTR [ebp-0x68]
  50281f:	3b de                	cmp    ebx,esi
  502821:	0f 84 f9 02 00 00    	je     0x502b20
  502827:	83 c3 10             	add    ebx,0x10
  50282a:	33 f6                	xor    esi,esi
  50282c:	3b de                	cmp    ebx,esi
  50282e:	0f 84 ec 02 00 00    	je     0x502b20
  502834:	8b 43 44             	mov    eax,DWORD PTR [ebx+0x44]
  502837:	83 e8 02             	sub    eax,0x2
  50283a:	74 4d                	je     0x502889
  50283c:	48                   	dec    eax
  50283d:	75 5b                	jne    0x50289a
  50283f:	e8 7c 2c f0 ff       	call   0x4054c0
  502844:	6a 18                	push   0x18
  502846:	e8 1d ea 38 00       	call   0x891268
  50284b:	83 c4 04             	add    esp,0x4
  50284e:	3b c6                	cmp    eax,esi
  502850:	74 2a                	je     0x50287c
  502852:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502855:	83 ca ff             	or     edx,0xffffffff
  502858:	50                   	push   eax
  502859:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50285c:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50285f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  502862:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  502869:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50286f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502872:	e8 d9 81 08 00       	call   0x58aa50
  502877:	e9 a1 02 00 00       	jmp    0x502b1d
  50287c:	33 c0                	xor    eax,eax
  50287e:	50                   	push   eax
  50287f:	e8 cc 81 08 00       	call   0x58aa50
  502884:	e9 94 02 00 00       	jmp    0x502b1d
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
```

### S06 — singleton helper 0x422F40 returns controller pointer, does not transform stack args

VA `[0x00422F40,0x00422FA2)`；raw `[0x0022340,0x00223A2)`；98 bytes；SHA256 `2a37bda966c2cc40b63b7e312e48ea1177b0bf17bf79f76931e45cb5209a2014`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  422f40:	55                   	push   ebp
  422f41:	8b ec                	mov    ebp,esp
  422f43:	6a ff                	push   0xffffffff
  422f45:	68 ae b2 93 00       	push   0x93b2ae
  422f4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  422f50:	50                   	push   eax
  422f51:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  422f56:	33 c5                	xor    eax,ebp
  422f58:	50                   	push   eax
  422f59:	8d 45 f4             	lea    eax,[ebp-0xc]
  422f5c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  422f62:	b8 01 00 00 00       	mov    eax,0x1
  422f67:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  422f6d:	75 1f                	jne    0x422f8e
  422f6f:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  422f75:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  422f7c:	e8 ef d1 13 00       	call   0x560170
  422f81:	68 10 d1 bc 00       	push   0xbcd110
  422f86:	e8 8f f3 46 00       	call   0x89231a
  422f8b:	83 c4 04             	add    esp,0x4
  422f8e:	b8 c0 73 fb 00       	mov    eax,0xfb73c0
  422f93:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  422f96:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  422f9d:	59                   	pop    ecx
  422f9e:	8b e5                	mov    esp,ebp
  422fa0:	5d                   	pop    ebp
  422fa1:	c3                   	ret
```

### S07 — S2C 0x46 handler entry, substate0 gate and F4282 early local event

VA `[0x00502B40,0x00502C1E)`；raw `[0x0101F40,0x010201E)`；222 bytes；SHA256 `71394ae6b6ab94bb29fd722402dace43558271d71b02a817aa3d90de10da4d61`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  502b40:	55                   	push   ebp
  502b41:	8b ec                	mov    ebp,esp
  502b43:	6a ff                	push   0xffffffff
  502b45:	68 27 41 94 00       	push   0x944127
  502b4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502b50:	50                   	push   eax
  502b51:	83 ec 30             	sub    esp,0x30
  502b54:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  502b59:	33 c5                	xor    eax,ebp
  502b5b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  502b5e:	53                   	push   ebx
  502b5f:	56                   	push   esi
  502b60:	57                   	push   edi
  502b61:	50                   	push   eax
  502b62:	8d 45 f4             	lea    eax,[ebp-0xc]
  502b65:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  502b6b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502b72:	89 4d d8             	mov    DWORD PTR [ebp-0x28],ecx
  502b75:	75 28                	jne    0x502b9f
  502b77:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  502b7e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  502b85:	e8 f6 48 08 00       	call   0x587480
  502b8a:	68 c0 cc bc 00       	push   0xbcccc0
  502b8f:	e8 86 f7 38 00       	call   0x89231a
  502b94:	83 c4 04             	add    esp,0x4
  502b97:	83 cf ff             	or     edi,0xffffffff
  502b9a:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  502b9d:	eb 03                	jmp    0x502ba2
  502b9f:	83 cf ff             	or     edi,0xffffffff
  502ba2:	6a 18                	push   0x18
  502ba4:	e8 bf e6 38 00       	call   0x891268
  502ba9:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  502bac:	33 f6                	xor    esi,esi
  502bae:	83 c4 04             	add    esp,0x4
  502bb1:	3b c6                	cmp    eax,esi
  502bb3:	74 1f                	je     0x502bd4
  502bb5:	0f b7 4b 04          	movzx  ecx,WORD PTR [ebx+0x4]
  502bb9:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  502bbc:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  502bbf:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  502bc2:	c7 40 10 82 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4282
  502bc9:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502bcf:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502bd2:	8b f0                	mov    esi,eax
  502bd4:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  502bdb:	75 23                	jne    0x502c00
  502bdd:	b8 01 00 00 00       	mov    eax,0x1
  502be2:	09 05 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,eax
  502be8:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502beb:	e8 a0 ad 24 00       	call   0x74d990
  502bf0:	68 70 cc bc 00       	push   0xbccc70
  502bf5:	e8 20 f7 38 00       	call   0x89231a
  502bfa:	83 c4 04             	add    esp,0x4
  502bfd:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  502c00:	8d 45 e0             	lea    eax,[ebp-0x20]
  502c03:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  502c06:	50                   	push   eax
  502c07:	be 6c 5c f9 00       	mov    esi,0xf95c6c
  502c0c:	e8 4f 16 30 00       	call   0x804260
  502c11:	0f b7 43 04          	movzx  eax,WORD PTR [ebx+0x4]
  502c15:	66 85 c0             	test   ax,ax
  502c18:	0f 85 50 02 00 00    	jne    0x502e6e
```

### S08 — S2C 0x46 substate0 remove exclusion, conditional append prerequisite, candidate rebuild

VA `[0x00502DAA,0x00502DED)`；raw `[0x01021AA,0x01021ED)`；67 bytes；SHA256 `9827499f565c558b4864175ef245199ac7e898b985f7edb384afeeb5ee0019fe`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  502daa:	0f bf 73 02          	movsx  esi,WORD PTR [ebx+0x2]
  502dae:	8b 55 d8             	mov    edx,DWORD PTR [ebp-0x28]
  502db1:	e8 1a d3 ff ff       	call   0x5000d0
  502db6:	85 ff                	test   edi,edi
  502db8:	74 1e                	je     0x502dd8
  502dba:	83 7f 08 03          	cmp    DWORD PTR [edi+0x8],0x3
  502dbe:	74 18                	je     0x502dd8
  502dc0:	0f b7 43 02          	movzx  eax,WORD PTR [ebx+0x2]
  502dc4:	8b 7d d8             	mov    edi,DWORD PTR [ebp-0x28]
  502dc7:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  502dca:	81 c7 b0 5e 00 00    	add    edi,0x5eb0
  502dd0:	8d 45 dc             	lea    eax,[ebp-0x24]
  502dd3:	e8 08 87 f4 ff       	call   0x44b4e0
  502dd8:	e8 83 c2 f0 ff       	call   0x40f060
  502ddd:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502de3:	8b 4d d8             	mov    ecx,DWORD PTR [ebp-0x28]
  502de6:	50                   	push   eax
  502de7:	51                   	push   ecx
  502de8:	e8 53 d4 ff ff       	call   0x500240
```

### S09 — S2C 0x46 QID event action F438C enqueued, nonzero state branch

VA `[0x00502E1E,0x00502E80)`；raw `[0x010221E,0x0102280)`；98 bytes；SHA256 `b716e7c7bd09fc5e38c8933545ad0ba9379ae1735d72c41d527bf92a664357cb`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  502e1e:	83 ce ff             	or     esi,0xffffffff
  502e21:	6a 18                	push   0x18
  502e23:	e8 40 e4 38 00       	call   0x891268
  502e28:	83 c4 04             	add    esp,0x4
  502e2b:	85 c0                	test   eax,eax
  502e2d:	74 2f                	je     0x502e5e
  502e2f:	0f bf 4b 02          	movsx  ecx,WORD PTR [ebx+0x2]
  502e33:	50                   	push   eax
  502e34:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  502e37:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  502e3a:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  502e41:	c7 40 10 8c 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438c
  502e48:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502e4e:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502e51:	e8 fa 7b 08 00       	call   0x58aa50
  502e56:	83 c4 04             	add    esp,0x4
  502e59:	e9 be 01 00 00       	jmp    0x50301c
  502e5e:	33 c0                	xor    eax,eax
  502e60:	50                   	push   eax
  502e61:	e8 ea 7b 08 00       	call   0x58aa50
  502e66:	83 c4 04             	add    esp,0x4
  502e69:	e9 ae 01 00 00       	jmp    0x50301c
  502e6e:	83 f8 01             	cmp    eax,0x1
  502e71:	0f 85 cb 00 00 00    	jne    0x502f42
  502e77:	84 05 d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,al
  502e7d:	75 22                	jne    0x502ea1
  502e7f:	09         	or     DWORD PTR ds:0xfaadd4,eax
```

### S10 — S2C 0x47 two signed WORD fields are passed to controller

VA `[0x00503095,0x005030BF)`；raw `[0x0102495,0x01024BF)`；42 bytes；SHA256 `987fbc8d4bcd525044f70e149a30f4a2a05ec6cc3db22d84aba10769735769b2`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  503095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503098:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  50309c:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  5030a0:	51                   	push   ecx
  5030a1:	52                   	push   edx
  5030a2:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5030a7:	e8 b4 e6 05 00       	call   0x561760
  5030ac:	33 c0                	xor    eax,eax
  5030ae:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5030b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5030b8:	59                   	pop    ecx
  5030b9:	8b e5                	mov    esp,ebp
  5030bb:	5d                   	pop    ebp
  5030bc:	c2 0c 00             	ret    0xc
```

### S11 — S2C 0x74 prerequisite append and rebuild (different from 0x46 scene)

VA `[0x00503400,0x00503430)`；raw `[0x0102800,0x0102830)`；48 bytes；SHA256 `bd2edd0492aa0f77eb0859055ce071dbd56b2c2caf278b79caa5bc5af2db5a19`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

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
  50342f:	c2               	ret    0xc
```

### S12 — scene controller 0x561760 entry/busy/idle branch

VA `[0x00561760,0x00561830)`；raw `[0x0160B60,0x0160C30)`；208 bytes；SHA256 `7d13c9bd4bc61b29c369985a19128ef1859f4c735ec33cfc7c80a4899b99e305`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  561760:	55                   	push   ebp
  561761:	8b ec                	mov    ebp,esp
  561763:	83 e4 f8             	and    esp,0xfffffff8
  561766:	6a ff                	push   0xffffffff
  561768:	68 2c fd 93 00       	push   0x93fd2c
  56176d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561773:	50                   	push   eax
  561774:	83 ec 50             	sub    esp,0x50
  561777:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56177c:	33 c4                	xor    eax,esp
  56177e:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  561782:	53                   	push   ebx
  561783:	56                   	push   esi
  561784:	57                   	push   edi
  561785:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56178a:	33 c4                	xor    eax,esp
  56178c:	50                   	push   eax
  56178d:	8d 44 24 60          	lea    eax,[esp+0x60]
  561791:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561797:	83 3d 18 ab fb 00 00 	cmp    DWORD PTR ds:0xfbab18,0x0
  56179e:	8b d9                	mov    ebx,ecx
  5617a0:	74 20                	je     0x5617c2
  5617a2:	0f 57 c0             	xorps  xmm0,xmm0
  5617a5:	f3 0f 11 05 24 ab fb 	movss  DWORD PTR ds:0xfbab24,xmm0
  5617ac:	00 
  5617ad:	e8 ae d8 ea ff       	call   0x40f060
  5617b2:	f3 0f 10 05 70 59 c5 	movss  xmm0,DWORD PTR ds:0xc55970
  5617b9:	00 
  5617ba:	f3 0f 11 80 ac 00 00 	movss  DWORD PTR [eax+0xac],xmm0
  5617c1:	00 
  5617c2:	83 7b 28 00          	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00 	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                	je     0x5617e9
  5617cf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                   	push   eax
  5617d6:	51                   	push   ecx
  5617d7:	68 ac 06 c1 00       	push   0xc106ac
  5617dc:	e8 7f c3 18 00       	call   0x6edb60
  5617e1:	83 c4 0c             	add    esp,0xc
  5617e4:	e9 9d 05 00 00       	jmp    0x561d86
  5617e9:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00       	mov    esi,0x1
  5617f5:	75 29                	jne    0x561820
  5617f7:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68 00 00 00 	mov    DWORD PTR [esp+0x68],0x0
  561804:	00 
  561805:	e8 46 e0 fe ff       	call   0x54f850
  56180a:	68 80 d5 bc 00       	push   0xbcd580
  56180f:	e8 06 0b 33 00       	call   0x89231a
  561814:	83 c4 04             	add    esp,0x4
  561817:	83 cf ff             	or     edi,0xffffffff
  56181a:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  56181e:	eb 03                	jmp    0x561823
  561820:	83 cf ff             	or     edi,0xffffffff
  561823:	80 3d f1 92 fb 00 00 	cmp    BYTE PTR ds:0xfb92f1,0x0
  56182a:	0f 84 ac 00 00 00    	je     0x5618dc
```

### S13 — scene controller stored key pair+38/+3C and active flag after gates

VA `[0x005618AE,0x00561900)`；raw `[0x0160CAE,0x0160D00)`；82 bytes；SHA256 `bec2be4f628980b490c5851c0c314d2c2bf92d62eca7fe7aba3c96648eff0b70`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  5618ae:	24 3c                	and    al,0x3c
  5618b0:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b7:	ff 
  5618b8:	e8 83 8b f9 ff       	call   0x4fa440
  5618bd:	e8 be 2d eb ff       	call   0x414680
  5618c2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                   	push   ecx
  5618c6:	6a 00                	push   0x0
  5618c8:	e8 d3 20 f4 ff       	call   0x4a39a0
  5618cd:	e8 de 07 00 00       	call   0x5620b0
  5618d2:	e9 af 04 00 00       	jmp    0x561d86
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00  	mov    DWORD PTR [esp+0x68],0x2
  561901:	 
```

### S14 — controller staged NEXT selector and scene entry after valid successor

VA `[0x00561E90,0x00561F00)`；raw `[0x0161290,0x0161300)`；112 bytes；SHA256 `87fec121adf57aba1735c7f3da025e832cb8e921f5d9aa7bc773754f407b52da`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  561e90:	00 00                	add    BYTE PTR [eax],al
  561e92:	00 e8                	add    al,ch
  561e94:	08 2d ea ff 88 98    	or     BYTE PTR ds:0x9888ffea,ch
  561e9a:	c4 68 00             	les    ebp,FWORD PTR [eax+0x0]
  561e9d:	00 eb                	add    bl,ch
  561e9f:	03 83 ce ff f6 05    	add    eax,DWORD PTR [ebx+0x5f6ffce]
  561ea5:	64 0f fc 00          	paddb  mm0,QWORD PTR fs:[eax]
  561ea9:	01 75 25             	add    DWORD PTR [ebp+0x25],esi
  561eac:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  561eb3:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  561eba:	00 
  561ebb:	e8 20 be f1 ff       	call   0x47dce0
  561ec0:	68 f0 da bc 00       	push   0xbcdaf0
  561ec5:	e8 50 04 33 00       	call   0x89231a
  561eca:	83 c4 04             	add    esp,0x4
  561ecd:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
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
  561efc:	64 89 0d 00    	mov    DWORD PTR fs:0x0,ecx
```

### S15 — controller conditional 0x3F and pending-clear routes

VA `[0x00561F70,0x00561FE8)`；raw `[0x0161370,0x01613E8)`；120 bytes；SHA256 `a5651bc30d2bd266ec02c97c6ef69ba8bbf39475a2aea511091d9df8c0d1dc98`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  561f70:	ff                   	(bad)
  561f71:	bb 01 00 00 00       	mov    ebx,0x1
  561f76:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38             	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                	je     0x561fb7
  561f7e:	68 44 03 c1 00       	push   0xc10344
  561f83:	53                   	push   ebx
  561f84:	e8 a7 92 f3 ff       	call   0x49b230
  561f89:	50                   	push   eax
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
  561fe5:	e8 c6 00         	call   0x5620b0
```

### S16 — actual Event scene entry 0x565720 busy gating and pair writer

VA `[0x00565720,0x0056579A)`；raw `[0x0164B20,0x0164B9A)`；122 bytes；SHA256 `ff87367b55f5e8b32a070a4a368dc35c6f7afe7050b252c55d86370af5281c0a`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad      	or     DWORD PTR ds:0xfaadd4,ebx
```

### S17 — Event scene map lookup and Lua resource hit/miss

VA `[0x005658BC,0x00565A1A)`；raw `[0x0164CBC,0x0164E1A)`；350 bytes；SHA256 `67f19f0bc2169aa73726c6a577e30c339623acad36d227f3d9cfcd8cad2fd9eb`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  5658bc:	01 e8                	add    eax,ebp
  5658be:	ae                   	scas   al,BYTE PTR es:[edi]
  5658bf:	d1 e9                	shr    ecx,1
  5658c1:	ff 8b 4e 0c 8b 41    	dec    DWORD PTR [ebx+0x418b0c4e]
  5658c7:	04 80                	add    al,0x80
  5658c9:	78 31                	js     0x5658fc
  5658cb:	00 75 27             	add    BYTE PTR [ebp+0x27],dh
  5658ce:	8b ff                	mov    edi,edi
  5658d0:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  5658d3:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658d6:	3b fa                	cmp    edi,edx
  5658d8:	7f 0a                	jg     0x5658e4
  5658da:	7c 0d                	jl     0x5658e9
  5658dc:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5658df:	39 50 10             	cmp    DWORD PTR [eax+0x10],edx
  5658e2:	7d 05                	jge    0x5658e9
  5658e4:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5658e7:	eb 04                	jmp    0x5658ed
  5658e9:	8b c8                	mov    ecx,eax
  5658eb:	8b 00                	mov    eax,DWORD PTR [eax]
  5658ed:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658f1:	74 dd                	je     0x5658d0
  5658f3:	eb 03                	jmp    0x5658f8
  5658f5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658f8:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  5658fb:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  5658ff:	3b ca                	cmp    ecx,edx
  565901:	74 17                	je     0x56591a
  565903:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  565906:	3b c7                	cmp    eax,edi
  565908:	7f 10                	jg     0x56591a
  56590a:	7c 08                	jl     0x565914
  56590c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56590f:	3b 41 10             	cmp    eax,DWORD PTR [ecx+0x10]
  565912:	7c 06                	jl     0x56591a
  565914:	8d 44 24 18          	lea    eax,[esp+0x18]
  565918:	eb 08                	jmp    0x565922
  56591a:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  56591e:	8d 44 24 10          	lea    eax,[esp+0x10]
  565922:	8b 38                	mov    edi,DWORD PTR [eax]
  565924:	3b fa                	cmp    edi,edx
  565926:	0f 84 39 01 00 00    	je     0x565a65
  56592c:	6a 10                	push   0x10
  56592e:	68 d0 06 c1 00       	push   0xc106d0
  565933:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565937:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  56593e:	00 
  56593f:	c7 44 24 34 00 00 00 	mov    DWORD PTR [esp+0x34],0x0
  565946:	00 
  565947:	c6 44 24 24 00       	mov    BYTE PTR [esp+0x24],0x0
  56594c:	e8 1f d1 e9 ff       	call   0x402a70
  565951:	6a ff                	push   0xffffffff
  565953:	8d 47 14             	lea    eax,[edi+0x14]
  565956:	6a 00                	push   0x0
  565958:	bb 05 00 00 00       	mov    ebx,0x5
  56595d:	50                   	push   eax
  56595e:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  565962:	89 5c 24 54          	mov    DWORD PTR [esp+0x54],ebx
  565966:	e8 65 c5 e9 ff       	call   0x401ed0
  56596b:	6a 04                	push   0x4
  56596d:	68 e4 06 c1 00       	push   0xc106e4
  565972:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565976:	e8 45 c6 e9 ff       	call   0x401fc0
  56597b:	83 7c 24 30 10       	cmp    DWORD PTR [esp+0x30],0x10
  565980:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  565984:	73 04                	jae    0x56598a
  565986:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  56598a:	f6 05 e8 1e fe 00 01 	test   BYTE PTR ds:0xfe1ee8,0x1
  565991:	75 22                	jne    0x5659b5
  565993:	83 0d e8 1e fe 00 01 	or     DWORD PTR ds:0xfe1ee8,0x1
  56599a:	c6 44 24 48 06       	mov    BYTE PTR [esp+0x48],0x6
  56599f:	e8 6c 6c ff ff       	call   0x55c610
  5659a4:	68 90 f2 bc 00       	push   0xbcf290
  5659a9:	e8 6c c9 32 00       	call   0x89231a
  5659ae:	83 c4 04             	add    esp,0x4
  5659b1:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5659b5:	57                   	push   edi
  5659b6:	68 ec 1e fe 00       	push   0xfe1eec
  5659bb:	e8 e0 7c ff ff       	call   0x55d6a0
  5659c0:	bf 10 00 00 00       	mov    edi,0x10
  5659c5:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  5659c8:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                	jae    0x5659d6
  5659d2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5659d8:	50                   	push   eax
  5659d9:	e8 72 f0 18 00       	call   0x6f4a50
  5659de:	e8 6d e8 ec ff       	call   0x434250
  5659e3:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  5659ea:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
  5659f1:	75 22                	jne    0x565a15
  5659f3:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  5659fa:	c6 44 24 48 07       	mov    BYTE PTR [esp+0x48],0x7
  5659ff:	e8 3c 75 23 00       	call   0x79cf40
  565a04:	68 80 db bc 00       	push   0xbcdb80
  565a09:	e8 0c c9 32 00       	call   0x89231a
  565a0e:	83 c4 04             	add    esp,0x4
  565a11:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  565a15:	6a 02                	push   0x2
  565a17:	68 90 0e         	push   0xfc0e90
```

### S18 — chapter object FIRST lookup and bridge, not automatic completion

VA `[0x0047D57E,0x0047D5D1)`；raw `[0x007C97E,0x007C9D1)`；83 bytes；SHA256 `082efb95275e4989e882d0120fe0fbd5990a2696515b559e429b45d297159960`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  47d57e:	05 64 0f fc 00       	add    eax,0xfc0f64
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
  47d5bc:	57                   	push   edi
  47d5bd:	e8 2e f8 ff ff       	call   0x47cdf0
  47d5c2:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5c8:	8b 31                	mov    esi,DWORD PTR [ecx]
  47d5ca:	e8 41 00 00 00       	call   0x47d610
  47d5cf:	8b 8f        	mov    ecx,DWORD PTR [edi+0x100]
```

### S19 — chapter FIRST dispatch normal-vs-special scene key

VA `[0x0047B5C0,0x0047B650)`；raw `[0x007A9C0,0x007AA50)`；144 bytes；SHA256 `f1e2271c7745e373dcda147aefe0fc89ec64f2b0a9f47076d1c8b306bdffdd54`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6       	test   BYTE PTR ds:0xfc0f64,0x1
```

### S20 — native NEXT selector from ordered vector

VA `[0x0047E640,0x0047E800)`；raw `[0x007DA40,0x007DC00)`；448 bytes；SHA256 `0525365d49a7e66101d145e22ec500b9016abf36a0fd65db86f2522d1702770a`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  47e640:	55                   	push   ebp
  47e641:	8b ec                	mov    ebp,esp
  47e643:	6a ff                	push   0xffffffff
  47e645:	68 b8 8a 90 00       	push   0x908ab8
  47e64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e650:	50                   	push   eax
  47e651:	83 ec 14             	sub    esp,0x14
  47e654:	53                   	push   ebx
  47e655:	56                   	push   esi
  47e656:	57                   	push   edi
  47e657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e65c:	33 c5                	xor    eax,ebp
  47e65e:	50                   	push   eax
  47e65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e668:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  47e66b:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  47e66f:	0f 84 86 00 00 00    	je     0x47e6fb
  47e675:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e678:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  47e67b:	8b 07                	mov    eax,DWORD PTR [edi]
  47e67d:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  47e680:	3b c7                	cmp    eax,edi
  47e682:	74 77                	je     0x47e6fb
  47e684:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47e687:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e68a:	51                   	push   ecx
  47e68b:	8d 4e 34             	lea    ecx,[esi+0x34]
  47e68e:	8d 45 08             	lea    eax,[ebp+0x8]
  47e691:	e8 3a e8 0a 00       	call   0x52ced0
  47e696:	8b 76 38             	mov    esi,DWORD PTR [esi+0x38]
  47e699:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e69c:	3b c6                	cmp    eax,esi
  47e69e:	75 11                	jne    0x47e6b1
  47e6a0:	8d 45 10             	lea    eax,[ebp+0x10]
  47e6a3:	e8 f8 ff 01 00       	call   0x49e6a0
  47e6a8:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47e6ab:	3b c7                	cmp    eax,edi
  47e6ad:	75 d5                	jne    0x47e684
  47e6af:	eb 4a                	jmp    0x47e6fb
  47e6b1:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e6b4:	83 c0 14             	add    eax,0x14
  47e6b7:	50                   	push   eax
  47e6b8:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e6bb:	50                   	push   eax
  47e6bc:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e6bf:	e8 cc a3 36 00       	call   0x7e8a90
  47e6c4:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e6cb:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e6ce:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  47e6d1:	2b ca                	sub    ecx,edx
  47e6d3:	c1 f9 02             	sar    ecx,0x2
  47e6d6:	8d 71 ff             	lea    esi,[ecx-0x1]
  47e6d9:	33 c0                	xor    eax,eax
  47e6db:	85 f6                	test   esi,esi
  47e6dd:	74 0f                	je     0x47e6ee
  47e6df:	90                   	nop
  47e6e0:	3b c8                	cmp    ecx,eax
  47e6e2:	76 32                	jbe    0x47e716
  47e6e4:	3b 1c 82             	cmp    ebx,DWORD PTR [edx+eax*4]
  47e6e7:	74 28                	je     0x47e711
  47e6e9:	40                   	inc    eax
  47e6ea:	3b c6                	cmp    eax,esi
  47e6ec:	72 f2                	jb     0x47e6e0
  47e6ee:	85 d2                	test   edx,edx
  47e6f0:	74 09                	je     0x47e6fb
  47e6f2:	52                   	push   edx
  47e6f3:	e8 14 2b 41 00       	call   0x89120c
  47e6f8:	83 c4 04             	add    esp,0x4
  47e6fb:	33 c0                	xor    eax,eax
  47e6fd:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e700:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e707:	59                   	pop    ecx
  47e708:	5f                   	pop    edi
  47e709:	5e                   	pop    esi
  47e70a:	5b                   	pop    ebx
  47e70b:	8b e5                	mov    esp,ebp
  47e70d:	5d                   	pop    ebp
  47e70e:	c2 0c 00             	ret    0xc
  47e711:	40                   	inc    eax
  47e712:	3b c8                	cmp    ecx,eax
  47e714:	77 0a                	ja     0x47e720
  47e716:	68 08 34 bf 00       	push   0xbf3408
  47e71b:	e8 5d f4 3f 00       	call   0x87db7d
  47e720:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  47e723:	85 d2                	test   edx,edx
  47e725:	74 09                	je     0x47e730
  47e727:	52                   	push   edx
  47e728:	e8 df 2a 41 00       	call   0x89120c
  47e72d:	83 c4 04             	add    esp,0x4
  47e730:	8b c6                	mov    eax,esi
  47e732:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e735:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e73c:	59                   	pop    ecx
  47e73d:	5f                   	pop    edi
  47e73e:	5e                   	pop    esi
  47e73f:	5b                   	pop    ebx
  47e740:	8b e5                	mov    esp,ebp
  47e742:	5d                   	pop    ebp
  47e743:	c2 0c 00             	ret    0xc
  47e746:	cc                   	int3
  47e747:	cc                   	int3
  47e748:	cc                   	int3
  47e749:	cc                   	int3
  47e74a:	cc                   	int3
  47e74b:	cc                   	int3
  47e74c:	cc                   	int3
  47e74d:	cc                   	int3
  47e74e:	cc                   	int3
  47e74f:	cc                   	int3
  47e750:	55                   	push   ebp
  47e751:	8b ec                	mov    ebp,esp
  47e753:	6a ff                	push   0xffffffff
  47e755:	68 ec 00 92 00       	push   0x9200ec
  47e75a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e760:	50                   	push   eax
  47e761:	83 ec 3c             	sub    esp,0x3c
  47e764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e769:	33 c5                	xor    eax,ebp
  47e76b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47e76e:	53                   	push   ebx
  47e76f:	56                   	push   esi
  47e770:	50                   	push   eax
  47e771:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e774:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e77a:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47e781:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e784:	89 47 10             	mov    DWORD PTR [edi+0x10],eax
  47e787:	89 4f 14             	mov    DWORD PTR [edi+0x14],ecx
  47e78a:	75 27                	jne    0x47e7b3
  47e78c:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47e793:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e79a:	e8 71 ec 10 00       	call   0x58d410
  47e79f:	68 c0 cd bc 00       	push   0xbccdc0
  47e7a4:	e8 71 3b 41 00       	call   0x89231a
  47e7a9:	83 c4 04             	add    esp,0x4
  47e7ac:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47e7b3:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  47e7b6:	8d 75 d4             	lea    esi,[ebp-0x2c]
  47e7b9:	e8 c2 07 f9 ff       	call   0x40ef80
  47e7be:	bb 08 00 00 00       	mov    ebx,0x8
  47e7c3:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  47e7ca:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  47e7cd:	72 02                	jb     0x47e7d1
  47e7cf:	8b 00                	mov    eax,DWORD PTR [eax]
  47e7d1:	68 dc 32 c0 00       	push   0xc032dc
  47e7d6:	68 80 af fa 00       	push   0xfaaf80
  47e7db:	8b c8                	mov    ecx,eax
  47e7dd:	ba fc 32 c0 00       	mov    edx,0xc032fc
  47e7e2:	e8 29 04 11 00       	call   0x58ec10
  47e7e7:	83 ce ff             	or     esi,0xffffffff
  47e7ea:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47e7ed:	39 5d e8             	cmp    DWORD PTR [ebp-0x18],ebx
  47e7f0:	72 0c                	jb     0x47e7fe
  47e7f2:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  47e7f5:	52                   	push   edx
  47e7f6:	e8 11 2a 41 00       	call   0x89120c
  47e7fb:	83 c4 04             	add    esp,0x4
  47e7fe:	f6 05      	test   BYTE PTR ds:0xfaaf7c,0x1
```

### S21 — Q.RestoreMap native Lua callback uses indirect registration

VA `[0x005697C0,0x00569880)`；raw `[0x0168BC0,0x0168C80)`；192 bytes；SHA256 `e06d5290fa67a41d88e3448223d9f9e90415894ce2d05385864768722a59f0de`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  5697c0:	55                   	push   ebp
  5697c1:	8b ec                	mov    ebp,esp
  5697c3:	6a ff                	push   0xffffffff
  5697c5:	68 c8 83 93 00       	push   0x9383c8
  5697ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5697d0:	50                   	push   eax
  5697d1:	83 ec 0c             	sub    esp,0xc
  5697d4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5697d9:	33 c5                	xor    eax,ebp
  5697db:	50                   	push   eax
  5697dc:	8d 45 f4             	lea    eax,[ebp-0xc]
  5697df:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5697e5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5697e8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5697eb:	33 c0                	xor    eax,eax
  5697ed:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  5697f0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  5697f3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5697f6:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  5697fc:	ff 15 0c 28 fe 00    	call   DWORD PTR ds:0xfe280c
  569802:	b8 01 00 00 00       	mov    eax,0x1
  569807:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  56980a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569811:	59                   	pop    ecx
  569812:	8b e5                	mov    esp,ebp
  569814:	5d                   	pop    ebp
  569815:	c3                   	ret
  569816:	cc                   	int3
  569817:	cc                   	int3
  569818:	cc                   	int3
  569819:	cc                   	int3
  56981a:	cc                   	int3
  56981b:	cc                   	int3
  56981c:	cc                   	int3
  56981d:	cc                   	int3
  56981e:	cc                   	int3
  56981f:	cc                   	int3
  569820:	55                   	push   ebp
  569821:	8b ec                	mov    ebp,esp
  569823:	6a ff                	push   0xffffffff
  569825:	68 c8 83 93 00       	push   0x9383c8
  56982a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569830:	50                   	push   eax
  569831:	83 ec 0c             	sub    esp,0xc
  569834:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569839:	33 c5                	xor    eax,ebp
  56983b:	50                   	push   eax
  56983c:	8d 45 f4             	lea    eax,[ebp-0xc]
  56983f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569845:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569848:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  56984b:	33 c0                	xor    eax,eax
  56984d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569850:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569853:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569856:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  56985c:	ff 15 10 28 fe 00    	call   DWORD PTR ds:0xfe2810
  569862:	b8 01 00 00 00       	mov    eax,0x1
  569867:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  56986a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569871:	59                   	pop    ecx
  569872:	8b e5                	mov    esp,ebp
  569874:	5d                   	pop    ebp
  569875:	c3                   	ret
  569876:	cc                   	int3
  569877:	cc                   	int3
  569878:	cc                   	int3
  569879:	cc                   	int3
  56987a:	cc                   	int3
  56987b:	cc                   	int3
  56987c:	cc                   	int3
  56987d:	cc                   	int3
  56987e:	cc                   	int3
  56987f:	cc                   	int3
```

### S22 — Q.Prolog native Lua callback and unchecked indirect target

VA `[0x00569AD0,0x00569B2C)`；raw `[0x0168ED0,0x0168F2C)`；92 bytes；SHA256 `242004d94c540e53667325e2c6c77699156e133f465319a50124b0ef7d78e0a8`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  569ad0:	55                   	push   ebp
  569ad1:	8b ec                	mov    ebp,esp
  569ad3:	6a ff                	push   0xffffffff
  569ad5:	68 c8 83 93 00       	push   0x9383c8
  569ada:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569ae0:	50                   	push   eax
  569ae1:	83 ec 0c             	sub    esp,0xc
  569ae4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569ae9:	33 c5                	xor    eax,ebp
  569aeb:	50                   	push   eax
  569aec:	8d 45 f4             	lea    eax,[ebp-0xc]
  569aef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569af5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569af8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  569afb:	33 c0                	xor    eax,eax
  569afd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569b00:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569b03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569b06:	8b 0d 2c 28 fe 00    	mov    ecx,DWORD PTR ds:0xfe282c
  569b0c:	51                   	push   ecx
  569b0d:	8d 45 e8             	lea    eax,[ebp-0x18]
  569b10:	e8 1b 09 00 00       	call   0x56a430
  569b15:	83 c4 04             	add    esp,0x4
  569b18:	b8 01 00 00 00       	mov    eax,0x1
  569b1d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  569b20:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569b27:	59                   	pop    ecx
  569b28:	8b e5                	mov    esp,ebp
  569b2a:	5d                   	pop    ebp
  569b2b:	c3                   	ret
```

### S23 — OnEndTalk end-cutscene callback is UI/Lua lifecycle, not task ACK

VA `[0x00568A90,0x00568B50)`；raw `[0x0167E90,0x0167F50)`；192 bytes；SHA256 `f915aa585bde3a134622639bfbe75a6ce923b522eb5d3b06993f5db97fffedcb`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  568a90:	55                   	push   ebp
  568a91:	8b ec                	mov    ebp,esp
  568a93:	6a ff                	push   0xffffffff
  568a95:	68 c8 83 93 00       	push   0x9383c8
  568a9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  568aa0:	50                   	push   eax
  568aa1:	83 ec 0c             	sub    esp,0xc
  568aa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  568aa9:	33 c5                	xor    eax,ebp
  568aab:	50                   	push   eax
  568aac:	8d 45 f4             	lea    eax,[ebp-0xc]
  568aaf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  568ab5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  568ab8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  568abb:	33 c0                	xor    eax,eax
  568abd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  568ac0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  568ac3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  568ac6:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  568acc:	ff 15 80 27 fe 00    	call   DWORD PTR ds:0xfe2780
  568ad2:	b8 01 00 00 00       	mov    eax,0x1
  568ad7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  568ada:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  568ae1:	59                   	pop    ecx
  568ae2:	8b e5                	mov    esp,ebp
  568ae4:	5d                   	pop    ebp
  568ae5:	c3                   	ret
  568ae6:	cc                   	int3
  568ae7:	cc                   	int3
  568ae8:	cc                   	int3
  568ae9:	cc                   	int3
  568aea:	cc                   	int3
  568aeb:	cc                   	int3
  568aec:	cc                   	int3
  568aed:	cc                   	int3
  568aee:	cc                   	int3
  568aef:	cc                   	int3
  568af0:	55                   	push   ebp
  568af1:	8b ec                	mov    ebp,esp
  568af3:	6a ff                	push   0xffffffff
  568af5:	68 d8 87 93 00       	push   0x9387d8
  568afa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  568b00:	50                   	push   eax
  568b01:	83 ec 0c             	sub    esp,0xc
  568b04:	56                   	push   esi
  568b05:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  568b0a:	33 c5                	xor    eax,ebp
  568b0c:	50                   	push   eax
  568b0d:	8d 45 f4             	lea    eax,[ebp-0xc]
  568b10:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  568b16:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  568b19:	33 c0                	xor    eax,eax
  568b1b:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  568b1e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  568b21:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  568b24:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  568b27:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  568b2d:	ff 15 84 27 fe 00    	call   DWORD PTR ds:0xfe2784
  568b33:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  568b36:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  568b39:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  568b3c:	c7 40 08 03 00 00 00 	mov    DWORD PTR [eax+0x8],0x3
  568b43:	dd 18                	fstp   QWORD PTR [eax]
  568b45:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  568b49:	b8 01 00 00 00       	mov    eax,0x1
  568b4e:	8b 4d              	mov    ecx,DWORD PTR [ebp-0xc]
```

### S24 — S2C 0x40/0x45 auxiliary local UI/scene branch and notifier

VA `[0x0050243B,0x005024FA)`；raw `[0x010183B,0x01018FA)`；191 bytes；SHA256 `ffa15c3636efb9fe451788704b242af613b50ba448ef59b79c6e0af8a5d5bcdb`。下列反組譯直接來自固定 SHA 的原始 BIN，若結尾落在指令途中，僅引用有完整 bytes 的指令與已知分支靶點。

```asm
  50243b:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  50243e:	51                   	push   ecx
  50243f:	57                   	push   edi
  502440:	e8 fb 0a f2 ff       	call   0x422f40
  502445:	8b c8                	mov    ecx,eax
  502447:	e8 14 f3 05 00       	call   0x561760
  50244c:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  502452:	8b 11                	mov    edx,DWORD PTR [ecx]
  502454:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  502457:	ff d0                	call   eax
  502459:	8b f8                	mov    edi,eax
  50245b:	85 ff                	test   edi,edi
  50245d:	0f 84 96 00 00 00    	je     0x5024f9
  502463:	8b 17                	mov    edx,DWORD PTR [edi]
  502465:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  502468:	8b cf                	mov    ecx,edi
  50246a:	ff d0                	call   eax
  50246c:	8b 08                	mov    ecx,DWORD PTR [eax]
  50246e:	8b b7 5c 01 00 00    	mov    esi,DWORD PTR [edi+0x15c]
  502474:	89 4d e4             	mov    DWORD PTR [ebp-0x1c],ecx
  502477:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  50247a:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  50247d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  502480:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  502483:	33 c0                	xor    eax,eax
  502485:	3b f0                	cmp    esi,eax
  502487:	74 17                	je     0x5024a0
  502489:	39 87 70 03 00 00    	cmp    DWORD PTR [edi+0x370],eax
  50248f:	74 0f                	je     0x5024a0
  502491:	e8 6a 4c 2a 00       	call   0x7a7100
  502496:	d9 9d 54 ff ff ff    	fstp   DWORD PTR [ebp-0xac]
  50249c:	33 c0                	xor    eax,eax
  50249e:	eb 0b                	jmp    0x5024ab
  5024a0:	0f 57 c0             	xorps  xmm0,xmm0
  5024a3:	f3 0f 11 85 54 ff ff 	movss  DWORD PTR [ebp-0xac],xmm0
  5024aa:	ff 
  5024ab:	d9 85 54 ff ff ff    	fld    DWORD PTR [ebp-0xac]
  5024b1:	66 8b 7f 04          	mov    di,WORD PTR [edi+0x4]
  5024b5:	dc 05 78 5e c5 00    	fadd   QWORD PTR ds:0xc55e78
  5024bb:	83 ec 08             	sub    esp,0x8
  5024be:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  5024c1:	0f b7 d7             	movzx  edx,di
  5024c4:	d8 45 ec             	fadd   DWORD PTR [ebp-0x14]
  5024c7:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  5024ca:	c7 45 d4 98 da c0 00 	mov    DWORD PTR [ebp-0x2c],0xc0da98
  5024d1:	89 45 d8             	mov    DWORD PTR [ebp-0x28],eax
  5024d4:	d9 5d ec             	fstp   DWORD PTR [ebp-0x14]
  5024d7:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  5024da:	d9 e8                	fld1
  5024dc:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  5024df:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  5024e3:	d9 ee                	fldz
  5024e5:	d9 1c 24             	fstp   DWORD PTR [esp]
  5024e8:	51                   	push   ecx
  5024e9:	52                   	push   edx
  5024ea:	e8 51 8c f9 ff       	call   0x49b140
  5024ef:	8d 55 d0             	lea    edx,[ebp-0x30]
  5024f2:	8b c8                	mov    ecx,eax
  5024f4:	e8 27 fa 04 00       	call   0x551f20
  5024f9:	8b               	mov    eax,DWORD PTR [ebx+0x28]
```

## 九、完成判定與下一研究入口

- **T16-134：Quest15 業務 C→S/S→C 與 Scene3 的直接/間接、有條件/不等價的 Client 靜態因果圖 — 有界完成。** 新證據為 `0x422F40` 只回傳 singleton 而不轉換 scene key，以及在同一現版 BIN 逐一比對 S2C `0x40/45/46/47` / C2S `0x1C/3F/36` 的 action descriptor 與現有兩條劇情入口。
- **沒有完成的主張**：「Quest15 真正完成就必定播放 Pindos Scene3」、原版 Server 真實 opcode 配對/發送順序、Q15 record completeAction type/param==2/3、真實 Chapter SceneList ordered row，以及完整可玩性。這些未知須於 T16-135 整合契約及後續原生資源研究時單獨保留；Server-only 政策交 S00，不能再以「未解 Server」阻止有資料可用的 Client 逆向。
- **下一正式段**：T16-135 —— Quest16→Quest15→Pindos 條件式 Client E2E 介面與 Server SPEC handoff；應先查最新 T01/RR、補齊真實 Table/SceneList row 的來源等級；不自動合併 main。
- 此報告只會在實際 GitHub create_file 成功並讀回後取得遠端 Git blob SHA；不預寫虛構的提交狀態。
