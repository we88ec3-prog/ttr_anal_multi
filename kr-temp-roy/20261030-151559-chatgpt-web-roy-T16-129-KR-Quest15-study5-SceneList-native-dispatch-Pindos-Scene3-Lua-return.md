# T16-129 — Quest15／⑤：SceneList 雙鍵載入／原生場景觸發、Pindos Scene3 Lua／恢復路徑（KR BIN-first）

- 作者：`chatgpt-web roy`；製作時間 `2026-10-30T15:15:59+08:00`；正式段號 **T16-129**（遠端最新已提交 T16-128 之下一段）。
- 使用者授權：完成 Quest15-⑤ 後上 Git，**只可提交 `t16/roy/chatgpt-web`**，不合 main；本地稿本身不預稱 Git 已成功。
- 原件：KR BIN `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Event.stp `11,241,597` bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。二進位均唯讀、不執行／不修補。`Table.stp` 為 STPD 容器，Quest15 全獎勵 XML 尚未在本篇重新取出，沿用 T16-125 的來源分級。
- x86 `.text` raw=`VA-0x400C00`（ImageBase0x400000；RVA0x1000/raw0x400），`.rdata` VA=`raw+0x401A00`（RVA0x7D2000/raw0x7D0600）。避免錯把 literal VA 當 `.text` raw-offset。
- 本輪 GitHub 啟動檢查：main `79eab9b15981d6b9b918ac47dc82cc2906230e3f`，T16 分支對 main `ahead=3／behind=95`（檢查時）；已讀 `AGENTS.md`、T16 README／task.json、dispatch README／T16 inbox、RR 台帳、共用 FULL-PASS 入口；**T16 無 RR**；歷史 T16-117 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 仍 `NEEDS_FIX`（T16-121/122 後續反證不能替代正式 erratum）。使用者特別指定先完成 Quest15-⑤，該 T01 修復另列待辦；本對話先前已執行一次 main→T16 同步，本輪**不再 Merge**。
- 研究終點：查清 Quest15 Scene1..4 如何進原生索引、如何從場景雙鍵查找走到腳本資源載入與 Lua 調用、可由哪些 controller／物件入口進入、有哪些早退／未命中與回場語義，以及在無原版 Server 流量的條件下哪些村莊／後續任務主張不能成立。

## A. 研究結果與精確完成界線

**Client 靜態場景子鏈已閉合（有界）**：`0x560344→0x5607D0` 解析 `Event/SceneList.xml` 的 `SCENESET/SCENE`，以 `questIdx` 與 `sceneIdx` 形成兩個 DWORD 鍵，並保存 `funcName` 腳本名；`0x565720` 使用 **同一個索引結構 `0xFB73C8`** 查兩鍵，在命中後讀出節點字串並交 `0x6F4A50` 載入處理，準備 scene native Lua API；未命中直接早退、不執行所選場景名。**原生觸發入口不只 controller**：另有物件流程 `0x47B2B0 → 物件+0x248 → 0x47B5C0 → 0x565720`；另一條 `0x561EF3` 是 controller gate 後的場景鍵轉移。

**原件直接確認**：Event.stp 中四份含 `-- Quest #15 / Scene #n` 標頭、同名 `function` 與 `Register` 的 Lua，Scene1/2 都 `LoadMap("Square03D.fld")`、建立 ID10338；Scene3 `LoadMap("town001D.map")`，有 ID10047、`OpenTalkScene(3,18/24/20/21)`、`DoProlog(1)`、`Q.DeleteAllObject()`、`RestoreMap()`；Scene4 `SetTransitionType(0)`, `LoadMap("")`, clean/restore。**這四段腳本在資源中存在，且 Client 原生具有 `(questIdx,sceneIdx)→funcName` 查找與 Lua 資源載入能力。**

**不能誇大**：XML `SceneList.xml` 的完整檔案尚未直接從 STPD 解包重讀；`(15,1..4)` 映射係四腳本資源中註解、歷史 T16-108 / 125 的限定索引記錄與 loader schema 交叉支持，不偽稱本輪重新解包全 XML。既有 Client 沒有直接證據證明 Q15 的 `0x46` 完成回覆**必然**選中 `(15,3)`、Server 發放任何獎勵、NPC10338 在實機的場景點擊必能觸發 Scene3、或 `RestoreMap()` 持久化進度。這些屬後續跨 Task／遊玩驗證；本段的有界完成只指**原生場景查找與劇情／恢復腳本可達介面**。

## B. Quest15/Scene 資源逐一直接確認（Event.stp，XOR-FF）

STPD 編碼資源中的可讀 Lua 以 `byte^0xFF` 還原；下列 offset 是**原始 Event.stp 檔案 offset**、end exclusive，SHA 是自每段註解到 `Register(...)` 行末（不含前後容器封裝），非檔案下載版本。資源存在不等於 runtime 順序；`sceneIdx` 1..4 僅為索引而非官方確定播放順序。

| Scene | funcName | raw-offset | 片段長度 | SHA256 | 原生劇情特性 |
|---|---|---|---:|---|---|
| 1 | `Square_Tutorial01` | `0x96943E..0x9696A6` | 616 | `e0a3e5809ea2d39116b4a11adb9e2d3c9173d89c16cdfe8343e8f7f563de5deb` | Square03D、NPC10338、Talk(3,22)、清理／恢復 |
| 2 | `scenario_tuto1_1` | `0x96883E..0x968C4F` | 1041 | `1ba55891d8ef770a868128ba0ebd18fff44524128e70d066b8faf67441f2b012` | Square03D、NPC10338、Talk(3,15/16/17/25) |
| 3 | `pindos_talkevent` | `0x8C1C3E..0x8C2276` | 1592 | `3c848c3f678426bd46899c18cf923688900168e9638d9c8d7a694ebd9b7e09ee` | town001D、物件10047、Talk(3,18/24/20/21)、DoProlog(1) |
| 4 | `scenario_tuto2_1` | `0x96903E..0x9691D8` | 410 | `d6ca315a6eb92441b1271a7e9581328e9a0689afbf95bdca2b0812b53eb4dda2` | 空 LoadMap、TransitionType(0)、清理／恢復 |

### B1. Scene3 「村莊過場」不能等同任務完成後永久定位

Scene3 的 Lua 順序是：`SetTransitionType(2)` → `HideOriginalObjs(1)` → `Phase1` → `LoadMap("town001D.map")` → camera/actor → `Phase2/3/4` → 對話與動畫 → `ClearObjects` → `DoProlog(1)` → `RevPhase4/3/2` → `Q.DeleteAllObject()` → `RestoreMap()` → `RevPhase1()`。**直接字面表明使用村莊地圖作劇情演出，結尾明確執行 RestoreMap**；無 Native S→C 存檔狀態證據，不得將 Scene3 解作「Server 已更改玩家永久城鎮／瞬移至 Pindos」。`OpenTalkScene(3,x)` 的兩個 Lua 引數也不能直接等同 quest ID15、town5 或 3F application opcode。

Scene1/2 的 NPC10338 符合 QuestInfo giver/finisher 既有 XML 擷取（T16-124/125），但 `CreateObject(...,10338,...)` 是 Scene 裡的 actor creation，不等於正式世界的 NPC10338 已綁定任務可接取 UI；Scene3 的10047是不同 actor ID。Scene4 空 map 參數不等於網路 logout/return-to-town message。

## C. 原生 SceneList loader → (questIdx,sceneIdx) 有序索引

- `0x560815 mov ecx,0xC10668` 指向唯讀常數 `Event/SceneList.xml`（raw 0x80EC68，VA0xC10668）；`0x56081A 0x72EE30` 建立檔案讀取／資源物件，`0x560845 0x72F110` 檢查成功；失敗跳 `0x560A26` 清理。
- `0x56087D` 找 `SCENESET`；`0x560897` 找 `SCENE`；迴圈 `0x5608B5` 以 virtual getter 遍歷節點。每節點 `0x5608D9` 查 `questIdx`（VA0xC10688），`0x560911` 查 `sceneIdx`（VA0xC03394），分別透過 `0x8917B4` 轉整數，欠欄位時 fallback 0。這是兩個值獨立解析的正反分支。
- `0x56093D` 查 `funcName`（VA0xC10694），取得字串。`0x560974..0x560999` 把 `questIdx` 和 `sceneIdx` 存入同一個 map node 待插入的兩個 DWORD，字串以獨立字串欄位保存。
- `0x5609A2 push 0xFB73C8`、`0x5609B3 call 0x568950` 建 node，`0x5609C4 call 0x568680` 把 node 插入全域 map；`0x560852..0x56087A` 先清舊 map（`0x565A90` destroy），故 resource reload 會重建索引，並非永遠 append。`0x560A17` 向下一個 SCENE 節點前進，最後清理 XML 暫存字串/例外物件。
- `0x568950` 分配 `0x34` byte map node：`node+0x0c/+0x10` 兩個 DWORD key，`node+0x14` 內嵌字串物件（`0x402BB0`）；`0x568680` 比較有序鍵並插入樹，非散列；重覆鍵路徑需審查，不能自行假設永遠以最新場景蓋掉前一筆。

## D. 索引 consumer `0x565720`：同一鍵空間 → script execution boundary

- 原生 `0x565756` 若 controller `+0x28 != 0`，走提示／早退 `0x565766..0x565778`；`0x56575D` 不論先後把 `controller+0x89=1`。若可繼續，`0x56577D` 從 `(arg1, arg2)` 設 `controller+0x38/0x3C`，`+0x28=1`；初始化其它場景資源／UI 狀態（`0x587480`, `0x74D990`, `0x4E1590` 等），不是單純 map getter。
- `0x5658D0..0x565914` 按兩個 DWORD 有序比較：`[node+0x0C]` 對 `arg1`、`[node+0x10]` 對 `arg2`。`0x565924 cmp edi,edx`，**未命中直接跳 `0x565A65`**（還原 SEH/stack 返回）；不從函式名臆造 fallback Scene。
- 命中時 `0x565953 lea eax,[edi+0x14]` 為內嵌字串，複製/組合腳本資源名稱；`0x5659B5..0x5659BB` 呼叫 `0x55D6A0` 建立 Lua API／狀態，`0x5659D8 push eax; 0x5659D9 call 0x6F4A50` 將選中名稱交給資源載入/執行程序。`0x6F4A50` 本體以 provider `0x714770` 查檔、virtual `+0x2c/+0x38` 讀 bytes，之後 `0x6F7110 / 0x6FE990 / 0x6FE770` 處理 script 和 `0x6F47A0` 後續 VM 執行，存在失敗返回；不能因命中 `funcName` 就保證 Lua 無錯執行、場景必播放到結尾。
- `0x5659DE→0x434250` 另外清某 owner `+0x14`，`0x565A15→0x79D9C0` 和 `0x565A48` 寫全域 `0xFD94B0=2`；這些是場景調度／UI 局部效果，無證據表明 Server quest completion，亦不可把狀態值2當作 Quest15 狀態2。
- Lua 腳本的 `Register(...)`、`SetTransitionType`, `LoadMap`, `OpenTalkScene`, `RestoreMap` 由 Lua resource 與原生 `0x55D6A0` binder name registrations 相互支持，具體 C callback 的每項 side effect 非本段全面重建；本段達成的是 native dispatch→script-load／script code 的有界連結。

## E. 場景 producer 雙入口及額外 writer（新增不同物件的精確邊界）

### E1. Quest controller `0x561ED1` 可有條件選 SceneList

`0x561DE0` 檢查 controller `+0x89`、`+0x28`；在非0分支，`0x561ED1` 從 `controller+0x38` 取 primary（先前 NPC10338 的 type2 candidate 可經 `0x561760` 保存 QID15）、從 `+0x3C` 取 secondary，經 `0x47E640` 轉換／檢查 second key。**只有結果非0**，`0x561EF3` 才 `call 0x565720(primary, secondary)`。`0x47E640` 涉及額外向量比較／索引轉換，不可因 `0x5B9447` 初始 `push 1` 就宣稱必定 Scene1，也不能稱玩家點 NPC 必然啟動 Pindos Scene3。

### E2. 獨立的場景物件 `0x47B2B0 → 0x47B5C0`

- `0x47B480` 建場景物件，`0x47B4C9..0x47B4CF` 將物件 `+0x248/+0x24C` 初始化成 `-1`。
- `0x47B2B0` 取記錄指標 `EDI`，`0x47B2DD mov eax,[edi]`，`0x47B2EF mov [ebx+0x248],eax` 寫物件第一鍵；`0x47B2E6 lea esi,[ebx+0x24c]` 把外部字串從 `[edi+8]` 複製到物件的其它欄位。注意 **`+0x24C` 是字串子物件起點**，不能直接說它是一個 scene ID DWORD。
- `0x47B5C0` 檢查 `object+0x248==0xEA61`：此特例受 `+0x26C` flag 控制，可轉 `0x47B850` 而非查 SceneList；其餘 `0x47B63A` 取 `[ebp+8]` 為第二參數，`0x47B63D` 讀 `object+0x248` 為第一參數，`0x47B64A call 0x565720`。函式結尾還有 `0x47E750` 等其他場景處理。**不能把物件 `+0x248` 混同 QuestOwner+0x... 或 NPC actor+0xF6**。
- 這是一條與 `0x561EF3` 不同的 runtime 入口；暫未直接證出原版 Server 哪條入站訊息把第一鍵15、第二鍵3設入此物件，也不可稱「Scene3 必由 quest-accept UI 直接觸發」。

### E3. 為什麼 `0x38` town5、`0x46` key15 與 Scene3 不能混為同一筆交易

T16-124 的 S→C `0x38` 可更新 **world selector** `0xFAB1BC` 成 town5；T16-128 的 S→C `0x46(15,0)` 在 QuestRecord 存在且 subtype!=3 時可更新 `QuestOwner+0x5EB0` 並產生 `F438C→mode3`；這兩者都不是 `0x565720(15,3)` 的直接 callee。**`0x46` 的 `mode3` 是 TalkBox 的 mode 數值，跟 `SceneIdx=3` 不可等同**。三個數字3/5/15跨命名空間不可互推，Server 相容設計需另保留場景 dispatch 的明確觸發契約／GAP。

## F. Quest15 玩家情境：原生已證效果 vs Server 待定策略

| 玩家情境／輸入 | Client 本輪和既有條件式觀察 | 不可推定／所需證據 |
|---|---|---|
| Q16 完成鍵／Q15 解鎖 | `0x74(16)` 或 `0x6F(bit16)` 更新 owner、`0x38` town5 selector 與 `0x500240` 重算候選 | 不等於自動場景 Scene3；需實際兩鍵調度 |
| 點選 NPC10338 | `F43D9→0x5008B0` type2 first match 可能得到 QID15，`0x1C`／有條件 `0x3F` C→S（T16-126/127） | 不能當成 SceneList 參數已必然設定，也不能預設官方 `0x3F→0x40/46` 配對 |
| S→C `0x40(15,0)` | `F438B`→mode2 TalkBox、exclusion/candidate update（T16-128） | mode2 TalkBox != SceneIdx2；不是開始 Scene2 的直接證據 |
| S→C `0x46(15,0)` | `F438C`→mode3 TalkBox、排除/前置候選寫入（有條件） | mode3 TalkBox != SceneIdx3，不能當作 `pindos_talkevent` 已播 |
| `0x565720(15,1)` 且 map 命中 | 取得 index row funcName，原生資源載入鏈；Scene1 Lua 使用 Square03D、NPC10338 | 檔案執行可能失敗，正式 Server 時序／SceneList full XML 未在本篇重讀 |
| `0x565720(15,2)` 且 map 命中 | Scene2 Lua 具 Square03D 和多名 actor／TalkScene 3/15.. | 不是 Quest15 已接受封包的必要回覆 |
| `0x565720(15,3)` 且 map 命中 | Scene3 Lua 具 town001D、10047、四段 talk、DoProlog1、RestoreMap | 動畫場景用 map 不等於永久 town5；無必然接任務後立即播證據 |
| `0x565720(15,4)` 且 map 命中 | Scene4 `SetTransitionType(0)`＋`LoadMap("")` 與本地 restore | 不是 Server 完成 logout 或後續新 Quest ID |
| 不存在的 scene 雙鍵／script provider 失敗 | `0x565926 → 0x565A65` 無 script；`0x6F4A50` provider failure/VM error path | 不能在 Server 兼容層假設 Client 會 fallback 到 Scene3 |

## G. Server 開發／跨 Task／Client 待逆向／遊玩驗收分層

**Client 原生已確認**：SceneList loader/attributes/map node、consumer two-DWORD key compare、兩條 scene-caller 條件與 key producer、script resource 加載／Lua 接口配置，以及四份 Quest15 的實際 Event.stp 腳本，含 Pindos Scene3 返回清理呼叫。這些是本輪新增的 **Scene 端到端有界子流程**；不是整個遊戲劇情 Server 收發的 FULL-PASS。

**Client 待逆向／剩餘未知**：`0x47B2B0` 的 upstream scene object record 創建者、如何在 live quest completion 後選擇 `(15,3)`、`0x47E640` 的所有分支返回值、`0x6F4A50` 與 `Register(...)` 的精確腳本函式調用細節、`RestoreMap()` native 函式副作用／完整 UI unwind；真正 Quest15 scene 之後的下一個 QuestID／scene index 仍需原始資料或正式 Server 業務消息證據。這些不能全部當作「Server 未知」，前面四類仍有原生靜態後續入口。

**Server 待開發**：發放 key16/Q15候選（`0x74`／`0x6F`／`0x38`）、NPC10338 context 的處理與任務 0x40/46/45/47 回覆策略、對 SceneList 兩鍵觸發的相容通知／劇情選擇、Q15 reward 交易／持久化、Pindos 地圖實際跨場景狀態與重登恢復。原版 Server 的決策無原始證據時由 S00 以 ADR 指定相容策略而非冒稱官方公式。

**跨 Task**：T02 完整 wire framing、initial response route；T07 主責 Scene scheduler、Pindos map/field 載入與 Scene/Stage 切換；T08 resource loader/STPD 解包；T06 UI callback/ NPC actor；T03/T04 登入 snapshot；T14 關卡勝負；T15 完成持久化；T01 精確有界主張審核；S00 SPEC/GAP/TEST，不能由本稿自行宣布正式規格已發布。

**待遊玩驗證**：在原版 Client + 相容 Server 上觀察 Q15 Scene1..4 真實播放次序、NPC10338 真正可接、Scene3 town001D 的地圖/貼圖資源、OpenTalkScene 結果、DoProlog 是否實際完成、RestoreMap 返回時 player position、後續章節可見與重登保存。這些需要 runtime trace／封包及有效相容 Server，不可用 bytes dump 取代。

## H. 原生 C++ 偽碼：只描述證實的條件

```cpp
// types and symbols are illustrative; addresses/conditions confirmed in appendix.
struct SceneKey {{ int32_t questIdx, sceneIdx; }};
std::map<SceneKey, std::string> sceneIndex; // backing: 0xFB73C8
void loadSceneList() {{
    auto xml = openResource("Event/SceneList.xml");
    if (!xml.valid()) return;
    sceneIndex.clear();
    for (auto scene : xml.children("SCENESET").children("SCENE")) {{
        int quest = parseOrZero(scene.attr("questIdx"));
        int idx = parseOrZero(scene.attr("sceneIdx"));
        auto func = scene.attr("funcName");
        sceneIndex.emplace(SceneKey{{quest,idx}},func); // duplicate-key result not claimed
    }}
}}
void maybeEnterScene(Controller* ctl,int quest,int idx) {{
    ctl->inSceneOrPending = true; // actual +0x89/+0x28 detailed in D
    auto it=sceneIndex.find(SceneKey{{quest,idx}});
    if (it==sceneIndex.end()) return;
    prepareSceneLuaCallbacks();
    tryLoadAndExecuteScriptByName(it->second); // failure path exists
    updateSceneLocalUiState();
}}
void onSceneObjectTrigger(SceneObject* o,int sceneIndex) {{
    if(o->questKey==0xEA61) {{ /* distinct 0x47B850 gate */ return; }}
    maybeEnterScene(o->controller, o->questKey, sceneIndex);
}}
```

## I. 原始證據清單（VA→raw，逐切片 SHA256）

每段直接擷取**原始 KR Tartaros.bin** 位元組；`raw=VA-0x400C00`，`end` exclusive。下列 assembly 是 `objdump -D -b binary -m i386 -M intel` 對該相同檔案區間的直接讀取；遇到起點非函式入口仍從明確指令邊界擷取。若切片不包含完整函式，結論只適用文中相鄰已交叉的 CFG 範圍。

### B01. SceneList XML resource loader entry and resource-gate

- VA `0x005607D0..0x0056087D`，BIN raw `0x15FBD0..0x15FC7D`，173 bytes，SHA256 `4ceb084e68d83dabed5b6c7d14a4238b5f32688e2dc189e08216d0ef636accd7`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005607d0 <.data+0x15fbd0>:
  5607d0:	55                   	push   ebp
  5607d1:	8b ec                	mov    ebp,esp
  5607d3:	83 e4 f8             	and    esp,0xfffffff8
  5607d6:	6a ff                	push   0xffffffff
  5607d8:	68 71 2f 92 00       	push   0x922f71
  5607dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5607e3:	50                   	push   eax
  5607e4:	81 ec d8 00 00 00    	sub    esp,0xd8
  5607ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5607ef:	33 c4                	xor    eax,esp
  5607f1:	89 84 24 d0 00 00 00 	mov    DWORD PTR [esp+0xd0],eax
  5607f8:	53                   	push   ebx
  5607f9:	56                   	push   esi
  5607fa:	57                   	push   edi
  5607fb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  560800:	33 c4                	xor    eax,esp
  560802:	50                   	push   eax
  560803:	8d 84 24 e8 00 00 00 	lea    eax,[esp+0xe8]
  56080a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  560810:	8d 44 24 64          	lea    eax,[esp+0x64]
  560814:	50                   	push   eax
  560815:	b9 68 06 c1 00       	mov    ecx,0xc10668
  56081a:	e8 11 e6 1c 00       	call   0x72ee30
  56081f:	33 db                	xor    ebx,ebx
  560821:	89 9c 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],ebx
  560828:	83 bc 24 98 00 00 00 	cmp    DWORD PTR [esp+0x98],0x10
  56082f:	10 
  560830:	8b 8c 24 84 00 00 00 	mov    ecx,DWORD PTR [esp+0x84]
  560837:	73 07                	jae    0x560840
  560839:	8d 8c 24 84 00 00 00 	lea    ecx,[esp+0x84]
  560840:	53                   	push   ebx
  560841:	8d 74 24 68          	lea    esi,[esp+0x68]
  560845:	e8 c6 e8 1c 00       	call   0x72f110
  56084a:	84 c0                	test   al,al
  56084c:	0f 84 d4 01 00 00    	je     0x560a26
  560852:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  560858:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  56085b:	52                   	push   edx
  56085c:	b9 c8 73 fb 00       	mov    ecx,0xfb73c8
  560861:	e8 2a 52 00 00       	call   0x565a90
  560866:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56086b:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  56086e:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  560873:	89 00                	mov    DWORD PTR [eax],eax
  560875:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56087a:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
```

### B02. SCENESET/SCENE traversal and questIdx

- VA `0x0056087D..0x00560911`，BIN raw `0x15FC7D..0x15FD11`，148 bytes，SHA256 `376c667ca2c6a2f1611f6566fe8921aaff0c431f6fbd3ba9fe09f8af18961941`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056087d <.data+0x15fc7d>:
  56087d:	68 7c 06 c1 00       	push   0xc1067c
  560882:	8b c6                	mov    eax,esi
  560884:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  56088a:	e8 51 da 1c 00       	call   0x72e2e0
  56088f:	3b c3                	cmp    eax,ebx
  560891:	0f 84 8f 01 00 00    	je     0x560a26
  560897:	68 8c 33 c0 00       	push   0xc0338c
  56089c:	e8 3f da 1c 00       	call   0x72e2e0
  5608a1:	8b f0                	mov    esi,eax
  5608a3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5608a7:	3b f3                	cmp    esi,ebx
  5608a9:	0f 84 77 01 00 00    	je     0x560a26
  5608af:	eb 04                	jmp    0x5608b5
  5608b1:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  5608b5:	8b 06                	mov    eax,DWORD PTR [esi]
  5608b7:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  5608ba:	8b ce                	mov    ecx,esi
  5608bc:	ff d2                	call   edx
  5608be:	3b c3                	cmp    eax,ebx
  5608c0:	0f 84 51 01 00 00    	je     0x560a17
  5608c6:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  5608cd:	00 
  5608ce:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  5608d2:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  5608d6:	8d 78 44             	lea    edi,[eax+0x44]
  5608d9:	68 88 06 c1 00       	push   0xc10688
  5608de:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x1
  5608e5:	01 
  5608e6:	e8 b5 f7 1c 00       	call   0x7300a0
  5608eb:	3b c3                	cmp    eax,ebx
  5608ed:	74 1e                	je     0x56090d
  5608ef:	83 c0 30             	add    eax,0x30
  5608f2:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5608f6:	72 02                	jb     0x5608fa
  5608f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5608fa:	3b c3                	cmp    eax,ebx
  5608fc:	74 0f                	je     0x56090d
  5608fe:	50                   	push   eax
  5608ff:	e8 b0 0e 33 00       	call   0x8917b4
  560904:	83 c4 04             	add    esp,0x4
  560907:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  56090b:	eb 04                	jmp    0x560911
  56090d:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
```

### B03. sceneIdx/funcName parser

- VA `0x00560911..0x00560974`，BIN raw `0x15FD11..0x15FD74`，99 bytes，SHA256 `198ac0342cad4c3a906db9b91d121efe96f24c246a2b5be562a2226c63c89cd4`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00560911 <.data+0x15fd11>:
  560911:	68 94 33 c0 00       	push   0xc03394
  560916:	e8 85 f7 1c 00       	call   0x7300a0
  56091b:	3b c3                	cmp    eax,ebx
  56091d:	74 1c                	je     0x56093b
  56091f:	83 c0 30             	add    eax,0x30
  560922:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  560926:	72 02                	jb     0x56092a
  560928:	8b 00                	mov    eax,DWORD PTR [eax]
  56092a:	3b c3                	cmp    eax,ebx
  56092c:	74 0d                	je     0x56093b
  56092e:	50                   	push   eax
  56092f:	e8 80 0e 33 00       	call   0x8917b4
  560934:	83 c4 04             	add    esp,0x4
  560937:	8b f0                	mov    esi,eax
  560939:	eb 02                	jmp    0x56093d
  56093b:	33 f6                	xor    esi,esi
  56093d:	68 94 06 c1 00       	push   0xc10694
  560942:	e8 59 f7 1c 00       	call   0x7300a0
  560947:	3b c3                	cmp    eax,ebx
  560949:	74 0d                	je     0x560958
  56094b:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  56094f:	8d 48 30             	lea    ecx,[eax+0x30]
  560952:	72 06                	jb     0x56095a
  560954:	8b 09                	mov    ecx,DWORD PTR [ecx]
  560956:	eb 02                	jmp    0x56095a
  560958:	33 c9                	xor    ecx,ecx
  56095a:	8b c1                	mov    eax,ecx
  56095c:	8d 78 01             	lea    edi,[eax+0x1]
  56095f:	90                   	nop
  560960:	8a 10                	mov    dl,BYTE PTR [eax]
  560962:	40                   	inc    eax
  560963:	3a d3                	cmp    dl,bl
  560965:	75 f9                	jne    0x560960
  560967:	2b c7                	sub    eax,edi
  560969:	50                   	push   eax
  56096a:	51                   	push   ecx
  56096b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56096f:	e8 fc 20 ea ff       	call   0x402a70
```

### B04. binary (questIdx,sceneIdx)+function string record production

- VA `0x00560974..0x005609B8`，BIN raw `0x15FD74..0x15FDB8`，68 bytes，SHA256 `3dd735eece6c06427da087400782503f8a3f355026f001f8ed4956720d09e9bc`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00560974 <.data+0x15fd74>:
  560974:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  560978:	6a ff                	push   0xffffffff
  56097a:	53                   	push   ebx
  56097b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56097f:	51                   	push   ecx
  560980:	bf 0f 00 00 00       	mov    edi,0xf
  560985:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  560989:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  56098d:	89 74 24 50          	mov    DWORD PTR [esp+0x50],esi
  560991:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  560995:	89 5c 24 64          	mov    DWORD PTR [esp+0x64],ebx
  560999:	88 5c 24 54          	mov    BYTE PTR [esp+0x54],bl
  56099d:	e8 9e 26 ea ff       	call   0x403040
  5609a2:	68 c8 73 fb 00       	push   0xfb73c8
  5609a7:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5609ab:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x2
  5609b2:	02 
  5609b3:	e8 98 7f 00 00       	call   0x568950
```

### B05. SceneList red-black tree insertion, temp destruction, iteration

- VA `0x005609B8..0x00560A26`，BIN raw `0x15FDB8..0x15FE26`，110 bytes，SHA256 `c7a2d828cd407f1b16a0e63adada827912aed8ddca64c86fcea8021f36988b7c`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005609b8 <.data+0x15fdb8>:
  5609b8:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  5609bc:	52                   	push   edx
  5609bd:	68 c8 73 fb 00       	push   0xfb73c8
  5609c2:	8b f0                	mov    esi,eax
  5609c4:	e8 b7 7c 00 00       	call   0x568680
  5609c9:	be 10 00 00 00       	mov    esi,0x10
  5609ce:	39 74 24 5c          	cmp    DWORD PTR [esp+0x5c],esi
  5609d2:	72 0d                	jb     0x5609e1
  5609d4:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  5609d8:	50                   	push   eax
  5609d9:	e8 2e 08 33 00       	call   0x89120c
  5609de:	83 c4 04             	add    esp,0x4
  5609e1:	88 9c 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],bl
  5609e8:	89 7c 24 5c          	mov    DWORD PTR [esp+0x5c],edi
  5609ec:	89 5c 24 58          	mov    DWORD PTR [esp+0x58],ebx
  5609f0:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5609f4:	39 74 24 38          	cmp    DWORD PTR [esp+0x38],esi
  5609f8:	72 0d                	jb     0x560a07
  5609fa:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  5609fe:	51                   	push   ecx
  5609ff:	e8 08 08 33 00       	call   0x89120c
  560a04:	83 c4 04             	add    esp,0x4
  560a07:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  560a0b:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  560a0f:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  560a13:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  560a17:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  560a1a:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  560a1e:	3b f3                	cmp    esi,ebx
  560a20:	0f 85 8b fe ff ff    	jne    0x5608b1
```

### B06. scene map loader caller

- VA `0x0056031E..0x0056035B`，BIN raw `0x15F71E..0x15F75B`，61 bytes，SHA256 `abc6f7d0c161088fa5202657211353b984e6299b3cf36145cbe03e8564b5dd46`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056031e <.data+0x15f71e>:
  56031e:	0d 38 74 fb 00       	or     eax,0xfb7438
  560323:	c6 41 11 01          	mov    BYTE PTR [ecx+0x11],0x1
  560327:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  56032b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  560332:	00 
  560333:	f3 0f 11 05 44 74 fb 	movss  DWORD PTR ds:0xfb7444,xmm0
  56033a:	00 
  56033b:	66 c7 05 48 74 fb 00 	mov    WORD PTR ds:0xfb7448,0x1
  560342:	01 00 
  560344:	e8 87 04 00 00       	call   0x5607d0
  560349:	e8 f2 20 00 00       	call   0x562440
  56034e:	f6 05 40 27 fe 00 01 	test   BYTE PTR ds:0xfe2740,0x1
  560355:	75 1d                	jne    0x560374
  560357:	83 0d 40 27    	or     DWORD PTR ds:0xfe2740,0x1
```

### B07. tree node payload: two DWORD and string

- VA `0x00568950..0x005689F4`，BIN raw `0x167D50..0x167DF4`，164 bytes，SHA256 `3b69b0278b10ee48dae8e6e51e77fe0dde54d6cd2f2811e9dc5054899efd7c9e`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00568950 <.data+0x167d50>:
  568950:	55                   	push   ebp
  568951:	8b ec                	mov    ebp,esp
  568953:	6a ff                	push   0xffffffff
  568955:	68 91 6c 91 00       	push   0x916c91
  56895a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  568960:	50                   	push   eax
  568961:	83 ec 18             	sub    esp,0x18
  568964:	53                   	push   ebx
  568965:	56                   	push   esi
  568966:	57                   	push   edi
  568967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56896c:	33 c5                	xor    eax,ebp
  56896e:	50                   	push   eax
  56896f:	8d 45 f4             	lea    eax,[ebp-0xc]
  568972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  568978:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  56897b:	8b f9                	mov    edi,ecx
  56897d:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  568980:	6a 34                	push   0x34
  568982:	e8 e1 88 32 00       	call   0x891268
  568987:	8b f0                	mov    esi,eax
  568989:	33 d2                	xor    edx,edx
  56898b:	83 c4 04             	add    esp,0x4
  56898e:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  568991:	3b f2                	cmp    esi,edx
  568993:	74 76                	je     0x568a0b
  568995:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  568998:	89 06                	mov    DWORD PTR [esi],eax
  56899a:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  56899d:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  5689a0:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  5689a3:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  5689a6:	8d 46 0c             	lea    eax,[esi+0xc]
  5689a9:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  5689ac:	66 89 56 30          	mov    WORD PTR [esi+0x30],dx
  5689b0:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  5689b3:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5689b6:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  5689ba:	3b c2                	cmp    eax,edx
  5689bc:	74 22                	je     0x5689e0
  5689be:	8b 0f                	mov    ecx,DWORD PTR [edi]
  5689c0:	89 08                	mov    DWORD PTR [eax],ecx
  5689c2:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  5689c5:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  5689c8:	8d 48 08             	lea    ecx,[eax+0x8]
  5689cb:	83 c7 08             	add    edi,0x8
  5689ce:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  5689d5:	89 51 10             	mov    DWORD PTR [ecx+0x10],edx
  5689d8:	57                   	push   edi
  5689d9:	88 11                	mov    BYTE PTR [ecx],dl
  5689db:	e8 d0 a1 e9 ff       	call   0x402bb0
  5689e0:	8b c6                	mov    eax,esi
  5689e2:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5689e5:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5689ec:	59                   	pop    ecx
  5689ed:	5f                   	pop    edi
  5689ee:	5e                   	pop    esi
  5689ef:	5b                   	pop    ebx
  5689f0:	8b e5                	mov    esp,ebp
  5689f2:	5d                   	pop    ebp
  5689f3:	c2               	ret    0x4
```

### B08. ordered tree insert and same-key handling

- VA `0x00568680..0x0056870A`，BIN raw `0x167A80..0x167B0A`，138 bytes，SHA256 `58c265881913b671468728942a6460d14bcc33733445811026db8bad227e12b4`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00568680 <.data+0x167a80>:
  568680:	55                   	push   ebp
  568681:	8b ec                	mov    ebp,esp
  568683:	51                   	push   ecx
  568684:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  568687:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  56868a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  56868d:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  568691:	53                   	push   ebx
  568692:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  568695:	57                   	push   edi
  568696:	8b f9                	mov    edi,ecx
  568698:	b1 01                	mov    cl,0x1
  56869a:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  56869d:	75 27                	jne    0x5686c6
  56869f:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  5686a2:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  5686a5:	8b f8                	mov    edi,eax
  5686a7:	3b ca                	cmp    ecx,edx
  5686a9:	7f 4b                	jg     0x5686f6
  5686ab:	7c 08                	jl     0x5686b5
  5686ad:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  5686b0:	3b 48 10             	cmp    ecx,DWORD PTR [eax+0x10]
  5686b3:	7c 41                	jl     0x5686f6
  5686b5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5686b8:	32 c9                	xor    cl,cl
  5686ba:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  5686bd:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5686c1:	74 df                	je     0x5686a2
  5686c3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5686c6:	89 7d 0c             	mov    DWORD PTR [ebp+0xc],edi
  5686c9:	84 c9                	test   cl,cl
  5686cb:	74 3d                	je     0x56870a
  5686cd:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  5686d0:	3b 38                	cmp    edi,DWORD PTR [eax]
  5686d2:	75 2b                	jne    0x5686ff
  5686d4:	56                   	push   esi
  5686d5:	6a 01                	push   0x1
  5686d7:	8d 4d 08             	lea    ecx,[ebp+0x8]
  5686da:	8b c7                	mov    eax,edi
  5686dc:	51                   	push   ecx
  5686dd:	8b fa                	mov    edi,edx
  5686df:	e8 cc 00 00 00       	call   0x5687b0
  5686e4:	8b 10                	mov    edx,DWORD PTR [eax]
  5686e6:	5f                   	pop    edi
  5686e7:	89 13                	mov    DWORD PTR [ebx],edx
  5686e9:	c6 43 04 01          	mov    BYTE PTR [ebx+0x4],0x1
  5686ed:	8b c3                	mov    eax,ebx
  5686ef:	5b                   	pop    ebx
  5686f0:	8b e5                	mov    esp,ebp
  5686f2:	5d                   	pop    ebp
  5686f3:	c2 08 00             	ret    0x8
  5686f6:	8b 00                	mov    eax,DWORD PTR [eax]
  5686f8:	b1 01                	mov    cl,0x1
  5686fa:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  5686fd:	eb be                	jmp    0x5686bd
  5686ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  568702:	e8 99 e7 fc ff       	call   0x536ea0
  568707:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
```

### B09. scene execution map lookup entry with active-state test

- VA `0x00565720..0x0056578E`，BIN raw `0x164B20..0x164B8E`，110 bytes，SHA256 `6fd1483f22342272cb2c767abcda4759ed0c890f16733ae478732172f3a28fd8`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00565720 <.data+0x164b20>:
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
```

### B10. script dispatcher setup and special flags

- VA `0x0056578E..0x005658AC`，BIN raw `0x164B8E..0x164CAC`，286 bytes，SHA256 `cdfc7dbd9dcae708c3c1ca19e7158a997ad5344943602a9b03f89b64165e1092`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056578e <.data+0x164b8e>:
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  56579c:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  5657a3:	00 
  5657a4:	e8 d7 1c 02 00       	call   0x587480
  5657a9:	68 c0 cc bc 00       	push   0xbcccc0
  5657ae:	e8 67 cb 32 00       	call   0x89231a
  5657b3:	83 c4 04             	add    esp,0x4
  5657b6:	83 cf ff             	or     edi,0xffffffff
  5657b9:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657bd:	eb 03                	jmp    0x5657c2
  5657bf:	83 cf ff             	or     edi,0xffffffff
  5657c2:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  5657c9:	75 20                	jne    0x5657eb
  5657cb:	09 1d d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,ebx
  5657d1:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  5657d5:	e8 b6 81 1e 00       	call   0x74d990
  5657da:	68 70 cc bc 00       	push   0xbccc70
  5657df:	e8 36 cb 32 00       	call   0x89231a
  5657e4:	83 c4 04             	add    esp,0x4
  5657e7:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657eb:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  5657f2:	8b 0d bc 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bbc
  5657f8:	8b 15 c0 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bc0
  5657fe:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  565802:	f3 0f 10 44 24 10    	movss  xmm0,DWORD PTR [esp+0x10]
  565808:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  56580c:	f3 0f 11 86 84 00 00 	movss  DWORD PTR [esi+0x84],xmm0
  565813:	00 
  565814:	75 24                	jne    0x56583a
  565816:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  56581c:	c7 44 24 48 02 00 00 	mov    DWORD PTR [esp+0x48],0x2
  565823:	00 
  565824:	e8 67 bd f7 ff       	call   0x4e1590
  565829:	68 80 cc bc 00       	push   0xbccc80
  56582e:	e8 e7 ca 32 00       	call   0x89231a
  565833:	83 c4 04             	add    esp,0x4
  565836:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  56583a:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  565841:	a0 a4 42 f9 00       	mov    al,ds:0xf942a4
  565846:	88 86 88 00 00 00    	mov    BYTE PTR [esi+0x88],al
  56584c:	75 24                	jne    0x565872
  56584e:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  565854:	c7 44 24 48 03 00 00 	mov    DWORD PTR [esp+0x48],0x3
  56585b:	00 
  56585c:	e8 1f 1c 02 00       	call   0x587480
  565861:	68 c0 cc bc 00       	push   0xbcccc0
  565866:	e8 af ca 32 00       	call   0x89231a
  56586b:	83 c4 04             	add    esp,0x4
  56586e:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  565872:	68 58 43 0f 00       	push   0xf4358
  565877:	e8 54 52 02 00       	call   0x58aad0
  56587c:	83 c4 04             	add    esp,0x4
  56587f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  565886:	75 24                	jne    0x5658ac
  565888:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  56588e:	c7 44 24 48 04 00 00 	mov    DWORD PTR [esp+0x48],0x4
  565895:	00 
  565896:	e8 f5 bc f7 ff       	call   0x4e1590
  56589b:	68 80 cc bc 00       	push   0xbccc80
  5658a0:	e8 75 ca 32 00       	call   0x89231a
  5658a5:	83 c4 04             	add    esp,0x4
  5658a8:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
```

### B11. map search two DWORD keys

- VA `0x005658AC..0x0056592C`，BIN raw `0x164CAC..0x164D2C`，128 bytes，SHA256 `ed53b15a0fed7b2dcc01f985aec31d3a02ce6bcfa85b8c414b4d71d5913d8e76`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005658ac <.data+0x164cac>:
  5658ac:	6a 00                	push   0x0
  5658ae:	68 75 23 bf 00       	push   0xbf2375
  5658b3:	8d 4e 44             	lea    ecx,[esi+0x44]
  5658b6:	c6 05 a4 42 f9 00 01 	mov    BYTE PTR ds:0xf942a4,0x1
  5658bd:	e8 ae d1 e9 ff       	call   0x402a70
  5658c2:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  5658c5:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5658c8:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658cc:	75 27                	jne    0x5658f5
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
```

### B12. scene name retrieval and script loader preparation

- VA `0x0056592C..0x005659C8`，BIN raw `0x164D2C..0x164DC8`，156 bytes，SHA256 `b3ef1b71c3bfab000d27db43eb9f289751dc1d5a1c53f04eb720b2da16f27aa5`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056592c <.data+0x164d2c>:
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
```

### B13. script resource load and scene state continuation

- VA `0x005659C8..0x00565A83`，BIN raw `0x164DC8..0x164E83`，187 bytes，SHA256 `01ec877737f7c01cf70789a2f687244ffa9316b73ec75f2f569dee18f624e9da`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005659c8 <.data+0x164dc8>:
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
  565a17:	68 90 0e fc 00       	push   0xfc0e90
  565a1c:	e8 9f 7f 23 00       	call   0x79d9c0
  565a21:	f6 05 d8 94 fd 00 01 	test   BYTE PTR ds:0xfd94d8,0x1
  565a28:	75 1e                	jne    0x565a48
  565a2a:	83 0d d8 94 fd 00 01 	or     DWORD PTR ds:0xfd94d8,0x1
  565a31:	c6 44 24 48 08       	mov    BYTE PTR [esp+0x48],0x8
  565a36:	e8 f5 f9 24 00       	call   0x7b5430
  565a3b:	68 60 e6 bc 00       	push   0xbce660
  565a40:	e8 d5 c8 32 00       	call   0x89231a
  565a45:	83 c4 04             	add    esp,0x4
  565a48:	c7 05 b0 94 fd 00 02 	mov    DWORD PTR ds:0xfd94b0,0x2
  565a4f:	00 00 00 
  565a52:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  565a56:	72 0d                	jb     0x565a65
  565a58:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  565a5c:	51                   	push   ecx
  565a5d:	e8 aa b7 32 00       	call   0x89120c
  565a62:	83 c4 04             	add    esp,0x4
  565a65:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  565a69:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  565a70:	59                   	pop    ecx
  565a71:	5f                   	pop    edi
  565a72:	5b                   	pop    ebx
  565a73:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  565a77:	33 cc                	xor    ecx,esp
  565a79:	e8 83 b5 32 00       	call   0x891001
  565a7e:	8b e5                	mov    esp,ebp
  565a80:	5d                   	pop    ebp
  565a81:	c2 08              	ret    0x8
```

### B14. alternative entity scene lookup trigger

- VA `0x0047B5C0..0x0047B64F`，BIN raw `0x7A9C0..0x7AA4F`，143 bytes，SHA256 `53dd8506239db93db828016e09cadb63b173d026ffd5cd4d32e833282810fa46`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047b5c0 <.data+0x7a9c0>:
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
```

### B15. alternative trigger post-scene effect and cleanup

- VA `0x0047B64F..0x0047B6A9`，BIN raw `0x7AA4F..0x7AAA9`，90 bytes，SHA256 `b8104acd83327d60405dd8e52737dbc87c18d5ec54f2b40570db666875a8b2ff`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047b64f <.data+0x7aa4f>:
  47b64f:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47b656:	75 29                	jne    0x47b681
  47b658:	b8 01 00 00 00       	mov    eax,0x1
  47b65d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47b663:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47b667:	e8 74 26 00 00       	call   0x47dce0
  47b66c:	68 f0 da bc 00       	push   0xbcdaf0
  47b671:	e8 a4 6c 41 00       	call   0x89231a
  47b676:	83 c4 04             	add    esp,0x4
  47b679:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b680:	ff 
  47b681:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [edi+0x24c]
  47b687:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b68d:	52                   	push   edx
  47b68e:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47b693:	e8 b8 30 00 00       	call   0x47e750
  47b698:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b69c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b6a3:	59                   	pop    ecx
  47b6a4:	5f                   	pop    edi
  47b6a5:	5e                   	pop    esi
  47b6a6:	8b e5                	mov    esp,ebp
  47b6a8:	5d                   	pop    ebp
```

### B16. alternative entity key writer from source record

- VA `0x0047B2B0..0x0047B306`，BIN raw `0x7A6B0..0x7A706`，86 bytes，SHA256 `e8700b60722ea0d797bad185c6dd24c7248ceefcfb53100310f86da33d5bb76a`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047b2b0 <.data+0x7a6b0>:
  47b2b0:	55                   	push   ebp
  47b2b1:	8b ec                	mov    ebp,esp
  47b2b3:	6a ff                	push   0xffffffff
  47b2b5:	68 dc ce 91 00       	push   0x91cedc
  47b2ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b2c0:	50                   	push   eax
  47b2c1:	83 ec 08             	sub    esp,0x8
  47b2c4:	53                   	push   ebx
  47b2c5:	56                   	push   esi
  47b2c6:	57                   	push   edi
  47b2c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b2cc:	33 c5                	xor    eax,ebp
  47b2ce:	50                   	push   eax
  47b2cf:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b2d2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b2d8:	8b f9                	mov    edi,ecx
  47b2da:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47b2dd:	8b 07                	mov    eax,DWORD PTR [edi]
  47b2df:	6a ff                	push   0xffffffff
  47b2e1:	6a 00                	push   0x0
  47b2e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  47b2e6:	8d b3 4c 02 00 00    	lea    esi,[ebx+0x24c]
  47b2ec:	51                   	push   ecx
  47b2ed:	8b ce                	mov    ecx,esi
  47b2ef:	89 83 48 02 00 00    	mov    DWORD PTR [ebx+0x248],eax
  47b2f5:	e8 e6 73 f8 ff       	call   0x4026e0
  47b2fa:	56                   	push   esi
  47b2fb:	8d b3 e8 00 00 00    	lea    esi,[ebx+0xe8]
  47b301:	e8 fa c4 2d 00       	call   0x757800
```

### B17. alternative entity default -1 fields

- VA `0x0047B480..0x0047B4F2`，BIN raw `0x7A880..0x7A8F2`，114 bytes，SHA256 `60dac73ef3374d6c15e18302f85e028f0fefd39da6029f1b9c512db20a9490a9`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047b480 <.data+0x7a880>:
  47b480:	55                   	push   ebp
  47b481:	8b ec                	mov    ebp,esp
  47b483:	6a ff                	push   0xffffffff
  47b485:	68 68 9c 91 00       	push   0x919c68
  47b48a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b490:	50                   	push   eax
  47b491:	51                   	push   ecx
  47b492:	53                   	push   ebx
  47b493:	56                   	push   esi
  47b494:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b499:	33 c5                	xor    eax,ebp
  47b49b:	50                   	push   eax
  47b49c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b49f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b4a5:	8b f1                	mov    esi,ecx
  47b4a7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b4aa:	e8 d1 93 2d 00       	call   0x754880
  47b4af:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b4b5:	33 db                	xor    ebx,ebx
  47b4b7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47b4ba:	50                   	push   eax
  47b4bb:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b4c1:	e8 5a 00 30 00       	call   0x77b520
  47b4c6:	83 c8 ff             	or     eax,0xffffffff
  47b4c9:	89 86 48 02 00 00    	mov    DWORD PTR [esi+0x248],eax
  47b4cf:	89 86 4c 02 00 00    	mov    DWORD PTR [esi+0x24c],eax
  47b4d5:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b4dc:	c7 06 3c 2f c0 00    	mov    DWORD PTR [esi],0xc02f3c
  47b4e2:	c7 86 64 02 00 00 07 	mov    DWORD PTR [esi+0x264],0x7
  47b4e9:	00 00 00 
  47b4ec:	89 9e 60 02 00 00    	mov    DWORD PTR [esi+0x260],ebx
```

### B18. controller conditional scene transfer (not unconditional C2S)

- VA `0x00561ED1..0x00561F0B`，BIN raw `0x1612D1..0x16130B`，58 bytes，SHA256 `9c3730eb69f44b32f778ce4a8f4aba5fe9eb59bf29778cdd9b979b5b31b383eb`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561ed1 <.data+0x1612d1>:
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
```

### B19. resource loader and Lua execution backend first half

- VA `0x006F4A50..0x006F4B32`，BIN raw `0x2F3E50..0x2F3F32`，226 bytes，SHA256 `7914400ce0641a13c21ff065bc4127016457648c940ed39ea903b1f69f7bde78`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006f4a50 <.data+0x2f3e50>:
  6f4a50:	55                   	push   ebp
  6f4a51:	8b ec                	mov    ebp,esp
  6f4a53:	83 e4 f8             	and    esp,0xfffffff8
  6f4a56:	81 ec 2c 02 00 00    	sub    esp,0x22c
  6f4a5c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6f4a61:	33 c4                	xor    eax,esp
  6f4a63:	89 84 24 28 02 00 00 	mov    DWORD PTR [esp+0x228],eax
  6f4a6a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4a6d:	53                   	push   ebx
  6f4a6e:	56                   	push   esi
  6f4a6f:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  6f4a73:	57                   	push   edi
  6f4a74:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  6f4a78:	2b d0                	sub    edx,eax
  6f4a7a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6f4a80:	8a 08                	mov    cl,BYTE PTR [eax]
  6f4a82:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  6f4a85:	40                   	inc    eax
  6f4a86:	84 c9                	test   cl,cl
  6f4a88:	75 f6                	jne    0x6f4a80
  6f4a8a:	8d 54 24 30          	lea    edx,[esp+0x30]
  6f4a8e:	68 e0 d1 be 00       	push   0xbed1e0
  6f4a93:	52                   	push   edx
  6f4a94:	be 01 00 00 00       	mov    esi,0x1
  6f4a99:	e8 d2 fc 01 00       	call   0x714770
  6f4a9e:	8b f8                	mov    edi,eax
  6f4aa0:	83 c4 08             	add    esp,0x8
  6f4aa3:	85 ff                	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00    	je     0x6f4bcf
  6f4aab:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4aad:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  6f4ab0:	8b cf                	mov    ecx,edi
  6f4ab2:	ff d2                	call   edx
  6f4ab4:	8b f0                	mov    esi,eax
  6f4ab6:	8d 46 01             	lea    eax,[esi+0x1]
  6f4ab9:	50                   	push   eax
  6f4aba:	e8 7e 91 18 00       	call   0x87dc3d
  6f4abf:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4ac1:	83 c4 04             	add    esp,0x4
  6f4ac4:	8b d8                	mov    ebx,eax
  6f4ac6:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  6f4ac9:	56                   	push   esi
  6f4aca:	8b cf                	mov    ecx,edi
  6f4acc:	ff d0                	call   eax
  6f4ace:	50                   	push   eax
  6f4acf:	53                   	push   ebx
  6f4ad0:	e8 fb 90 1a 00       	call   0x89dbd0
  6f4ad5:	c6 04 1e 00          	mov    BYTE PTR [esi+ebx*1],0x0
  6f4ad9:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4adb:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6f4ade:	83 c4 0c             	add    esp,0xc
  6f4ae1:	8b cf                	mov    ecx,edi
  6f4ae3:	ff d0                	call   eax
  6f4ae5:	83 f8 03             	cmp    eax,0x3
  6f4ae8:	72 48                	jb     0x6f4b32
  6f4aea:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                	jne    0x6f4b32
  6f4aef:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                	jne    0x6f4b32
  6f4af5:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                	jne    0x6f4b32
  6f4afb:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4aff:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4b01:	83 c0 fd             	add    eax,0xfffffffd
  6f4b04:	50                   	push   eax
  6f4b05:	8d 4b 03             	lea    ecx,[ebx+0x3]
  6f4b08:	51                   	push   ecx
  6f4b09:	33 c0                	xor    eax,eax
  6f4b0b:	e8 00 26 00 00       	call   0x6f7110
  6f4b10:	83 c4 08             	add    esp,0x8
  6f4b13:	85 c0                	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00    	jne    0x6f4bb8
  6f4b1b:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b1d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b20:	83 e8 10             	sub    eax,0x10
  6f4b23:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b27:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b2a:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4b2e:	50                   	push   eax
  6f4b2f:	52                   	push   edx
  6f4b30:	eb 57                	jmp    0x6f4b89
```

### B20. script processing and interpreter/cleanup branches

- VA `0x006F4B32..0x006F4BFF`，BIN raw `0x2F3F32..0x2F3FFF`，205 bytes，SHA256 `1e9122962f4a1773f9e25d7fa596bc36431bb9485b811c79b9883d1359588f87`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006f4b32 <.data+0x2f3f32>:
  6f4b32:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4b36:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6f4b38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f4b3c:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f4b40:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6f4b44:	33 c0                	xor    eax,eax
  6f4b46:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  6f4b4a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  6f4b4e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4b52:	51                   	push   ecx
  6f4b53:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f4b58:	8d 44 24 20          	lea    eax,[esp+0x20]
  6f4b5c:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  6f4b60:	c7 44 24 28 e0 70 6f 	mov    DWORD PTR [esp+0x28],0x6f70e0
  6f4b67:	00 
  6f4b68:	e8 23 9e 00 00       	call   0x6fe990
  6f4b6d:	83 c4 04             	add    esp,0x4
  6f4b70:	85 c0                	test   eax,eax
  6f4b72:	75 44                	jne    0x6f4bb8
  6f4b74:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b76:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b79:	83 e8 10             	sub    eax,0x10
  6f4b7c:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b80:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b83:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  6f4b87:	50                   	push   eax
  6f4b88:	51                   	push   ecx
  6f4b89:	68 50 5a 6f 00       	push   0x6f5a50
  6f4b8e:	33 d2                	xor    edx,edx
  6f4b90:	8b c6                	mov    eax,esi
  6f4b92:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  6f4b99:	ff 
  6f4b9a:	e8 d1 9b 00 00       	call   0x6fe770
  6f4b9f:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4ba2:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4ba5:	83 c4 0c             	add    esp,0xc
  6f4ba8:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                	jb     0x6f4bb0
  6f4bad:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4bb0:	85 c0                	test   eax,eax
  6f4bb2:	75 04                	jne    0x6f4bb8
  6f4bb4:	33 f6                	xor    esi,esi
  6f4bb6:	eb 05                	jmp    0x6f4bbd
  6f4bb8:	be 01 00 00 00       	mov    esi,0x1
  6f4bbd:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4bbf:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6f4bc2:	8b cf                	mov    ecx,edi
  6f4bc4:	ff d0                	call   eax
  6f4bc6:	53                   	push   ebx
  6f4bc7:	e8 71 d1 19 00       	call   0x891d3d
  6f4bcc:	83 c4 04             	add    esp,0x4
  6f4bcf:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  6f4bd3:	51                   	push   ecx
  6f4bd4:	8d 94 24 34 01 00 00 	lea    edx,[esp+0x134]
  6f4bdb:	68 9c 26 c4 00       	push   0xc4269c
  6f4be0:	52                   	push   edx
  6f4be1:	e8 49 df 19 00       	call   0x892b2f
  6f4be6:	83 c4 0c             	add    esp,0xc
  6f4be9:	85 f6                	test   esi,esi
  6f4beb:	74 12                	je     0x6f4bff
  6f4bed:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  6f4bf1:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  6f4bf8:	50                   	push   eax
  6f4bf9:	51                   	push   ecx
  6f4bfa:	e8 a1 fb ff ff       	call   0x6f47a0
```

### B21. script registration/configuration in scene callee

- VA `0x0055D6A0..0x0055D718`，BIN raw `0x15CAA0..0x15CB18`，120 bytes，SHA256 `b25defa76710610e62c075561a3add50071955d10c67862d377c89acdd50561e`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055d6a0 <.data+0x15caa0>:
  55d6a0:	55                   	push   ebp
  55d6a1:	8b ec                	mov    ebp,esp
  55d6a3:	51                   	push   ecx
  55d6a4:	53                   	push   ebx
  55d6a5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55d6a8:	56                   	push   esi
  55d6a9:	8d 43 08             	lea    eax,[ebx+0x8]
  55d6ac:	57                   	push   edi
  55d6ad:	50                   	push   eax
  55d6ae:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  55d6b1:	e8 2a 0c 00 00       	call   0x55e2e0
  55d6b6:	83 c4 04             	add    esp,0x4
  55d6b9:	6a 00                	push   0x0
  55d6bb:	68 75 23 bf 00       	push   0xbf2375
  55d6c0:	8d 4b 18             	lea    ecx,[ebx+0x18]
  55d6c3:	e8 a8 53 ea ff       	call   0x402a70
  55d6c8:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6cb:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6cd:	6a 00                	push   0x0
  55d6cf:	68 40 c9 55 00       	push   0x55c940
  55d6d4:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6d7:	e8 d4 7e 19 00       	call   0x6f55b0
  55d6dc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d6df:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d6e1:	bf 30 02 c1 00       	mov    edi,0xc10230
  55d6e6:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d6eb:	e8 a0 80 19 00       	call   0x6f5790
  55d6f0:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6f3:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6f5:	6a 00                	push   0x0
  55d6f7:	68 e0 cc 55 00       	push   0x55cce0
  55d6fc:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6ff:	e8 ac 7e 19 00       	call   0x6f55b0
  55d704:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d707:	8b 32                	mov    esi,DWORD PTR [edx]
  55d709:	bf 40 02 c1 00       	mov    edi,0xc10240
  55d70e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d713:	e8 78 80 19 00       	call   0x6f5790
```

### B22. native Lua OpenTalkScene name binding

- VA `0x0055D9FE..0x0055DA24`，BIN raw `0x15CDFE..0x15CE24`，38 bytes，SHA256 `f7a4fddf92070c14d3601942d4b6d8ddc8b668846490ab79acbeefcfb998ab87`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055d9fe <.data+0x15cdfe>:
  55d9fe:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da03:	8b 30                	mov    esi,DWORD PTR [eax]
  55da05:	6a 00                	push   0x0
  55da07:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da0c:	8b d8                	mov    ebx,eax
  55da0e:	e8 9d 7b 19 00       	call   0x6f55b0
  55da13:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da15:	bf 20 03 c1 00       	mov    edi,0xc10320
  55da1a:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da1f:	e8 6c 7d 19 00       	call   0x6f5790
```

### B23. prereq/candidate state S2C add example:0x74 writer

- VA `0x00503400..0x0050343B`，BIN raw `0x102800..0x10283B`，59 bytes，SHA256 `db33c392226229f8cbaa064f98592fc5a4f9c31b591c4ea0329ebcad9cb61818`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00503400 <.data+0x102800>:
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
  503432:	cc                   	int3
  503433:	cc                   	int3
  503434:	cc                   	int3
  503435:	cc                   	int3
  503436:	cc                   	int3
  503437:	cc                   	int3
  503438:	cc                   	int3
  503439:	cc                   	int3
  50343a:	cc                   	int3
```

### B24. town+candidate rebuilding S2C subtype writer

- VA `0x004B2094..0x004B2110`，BIN raw `0xB1494..0xB1510`，124 bytes，SHA256 `0a8b31e05113be7ef0664d4bb9138452bc4f7eb698f4a968dbec57fa651d5332`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b2094 <.data+0xb1494>:
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
  4b2108:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  4b210f:	75                 	jne    0x4b213a
```

## J. 四份 Lua 原始證據（來自 Event.stp 解碼，不是新寫 script）

### L1. `Quest #15 / Scene #1` — `Square_Tutorial01`

- XOR-FF encoded offset `0x96943E..0x9696A6`，616 bytes，SHA256 `e0a3e5809ea2d39116b4a11adb9e2d3c9173d89c16cdfe8343e8f7f563de5deb`。包含原件的 function 註解與 `Register`，不代表原版 Server 已派送。

```lua
-- Quest #15 / Scene #1 - Function Square_Tutorial01
function Square_Tutorial01()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)

	CreateObject(1, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM040.ogg")
	PlayCameraNoWait("Square_Tutorial01_01.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 22)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(Square_Tutorial01)
```

### L2. `Quest #15 / Scene #2` — `scenario_tuto1_1`

- XOR-FF encoded offset `0x96883E..0x968C4F`，1041 bytes，SHA256 `1ba55891d8ef770a868128ba0ebd18fff44524128e70d066b8faf67441f2b012`。包含原件的 function 註解與 `Register`，不代表原版 Server 已派送。

```lua
-- Quest #15 / Scene #2 - Function scenario_tuto1_1
function scenario_tuto1_1()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(869.00, 1037.00, 171.80)
	RotCamera(0.70, 1.47, 30.00)

	CreateObject(0, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	CreateObject(1, 1478, 864.00, 1032.00, 128, 0, FALSE, 1, 1)
	CreateObject(2, 1479, 869.00, 1027.00, 128, 0, FALSE, 1, 10)
	CreateObject(3, 1480, 869.00, 1042.00, 0, 0, FALSE, 1, 19)
	CreateObject(4, 1481, 874.00, 1032.00, 128, 0, FALSE, 1, 28)

	Phase2()
	Phase3()
	Phase4()

	OpenTalkScene(3, 15)
	OpenTalkScene(3, 16)
	OpenTalkScene(3, 17)
	PlayCameraNoWait("scenario_tuto1_1.cam", 0, 0.00, 0.00, 0.00)
	WarpObject(3, 869.000000, 1038.000000, 0.000000, 0, 1, 1)
	FaceObject(2, 10, 0)
	RotateObject(1, 50, 1)
	RotateObject(4, 206, 1)
	wait(500)
	OpenTalkScene(3, 25)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto1_1)
```

### L3. `Quest #15 / Scene #3` — `pindos_talkevent`

- XOR-FF encoded offset `0x8C1C3E..0x8C2276`，1592 bytes，SHA256 `3c848c3f678426bd46899c18cf923688900168e9638d9c8d7a694ebd9b7e09ee`。包含原件的 function 註解與 `Register`，不代表原版 Server 已派送。

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

### L4. `Quest #15 / Scene #4` — `scenario_tuto2_1`

- XOR-FF encoded offset `0x96903E..0x9691D8`，410 bytes，SHA256 `d6ca315a6eb92441b1271a7e9581328e9a0689afbf95bdca2b0812b53eb4dda2`。包含原件的 function 註解與 `Register`，不代表原版 Server 已派送。

```lua
-- Quest #15 / Scene #4 - Function scenario_tuto2_1
function scenario_tuto2_1()
	SetTransitionType(0)
	SetFinalMusic("")
	HideOriginalObjs(0)
	Phase1()

	LoadMap("")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)


	Phase2()
	Phase3()
	Phase4()


	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto2_1)
```

## K. 最終交付及研究結論

- Quest15 的五項 **①資源 ②NPC/UI ③C→S ④S→C ⑤Scene** 各自已有 T16-125..129 的可回溯 Client 有界研究；**⑤本次完成的嚴格界線是 SceneList.xml 原生 loader→雙鍵 map→查表→Lua resource→四份 Pindos 相關腳本/恢復路徑**。上游 Server 如何選 Scene3、實際 Pindos 村莊可玩、下一條 Quest/玩家存檔仍未閉合，不把有界完成冒稱整個教學主線可玩。
- 下一研究應優先針對 **Client 仍可補證的 `(15,3)` writer／trigger**，或進入 Quest15 之後村莊端到端（按實際 Git 最新段號接續；不得只靠本地段號猜正式分支狀態）；另修復 T16-117 精確 T01 NEEDS_FIX 通知，獨立保留舊原稿＋新勘誤，送 T01 複驗。
- 本地技術原稿完整存於此檔；Git Commit／Git blob／讀回驗證要以提交工具的實際回覆為準，**本檔不預先捏造**。
