# T16-132 — Quest15／Pindos：FIRST／NEXT 劇情啟動、控制器重入、停播、無腳本與 UI 事件的條件式原生流程（KR BIN-first）

- 研究作者：`chatgpt-web roy`，本地生成時間：`2026-10-30T17:07:39.776541+08:00`（Asia/Taipei）。正式段號 **T16-132**，接已驗證 T16-131（Git blob `354ec7c6d226a720b74d54f17c289a3b6ca33295`）。
- **本稿研究目標**：T16-only 的 `NPC／玩家事件或任務狀態 → FIRST／NEXT → (chapter,scene) → Event SceneList／Lua → 下一場或停止`；追清控制器 `+0x28/+0x38/+0x3C/+0x89` 的 writer／reset，UI 分支 `0xEA61`、單一選項事件、busy／miss／no-next。非通用 STP 解包、地圖生命週期、Server 程式或 S00 派工。
- **原始證據**：只讀 `/mnt/data/Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` 11,241,597 bytes、SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` 5,248,784 bytes、SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。**此段新肯定結論以 BIN 第一手指令為依據**；Event 四幕腳本與索引內容只限 T16-125/129/130 已有的直接原件引用。原始 EXE/STP/BIN 未執行、未 patch、未上傳。
- PE .text VA base=`0x401000`、raw pointer=`0x400`，故本稿 `.text raw=VA-0x400C00`（section 內），原生 x86 bytes 以同一 Tartaros.bin 取得。下方所有切片取已定位指令的開始地址；結尾如恰截在指令內，以相鄰 CFG 為限，不視為有效指令。
- **GitHub 開工檢查**：最新 main 在開工時為 `bc3b7deeda2fefbbc90cd98e660ca5965ae87d79`，T16 branch ahead8/behind148。已查 `AGENTS.md`、T16 README/task.json、`research/dispatch` inbox、RR index、shared FULL-PASS 索引。T16 無 S00 RR。唯一未在 main 結案的 T01 notice 是 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001`：**main 仍 NEEDS_FIX**；T16 作者已於相同對話先提交勘誤 `da76339b9cc008f58acc60d1a6269ae172da85fb`，且工作分支 README 更新 `READY_FOR_REVIEW` commit `bc03bec793303432fb6fe0ee20ce44019213f548`，**不等於 T01 RESOLVED**。T16-132 此次由使用者明確指定且授權 Commit／Push；只推 `t16/roy/chatgpt-web`，不再自動 main→T16 Merge，不推 main。
- **先前成果復用**：T16-129 的 Event SceneList `(questIdx,sceneIdx)→funcName`、T16-130 的 Table SceneList chapter FIRST/NEXT、T16-131 的 NPC candidate／入站 `0x47` 與 controller writer 已有 BIN 證據，故本稿不將它們重新描述成「首次發現」。新增重點在**各種 stop/re-entry 互斥條件及事件/清理 side effects**。GitHub 對原有原稿的獨立 T01 FULL-PASS 尚未做，不宣稱本稿 FULL-PASS 或 S00 Accepted。

## A. 核心結果與明確研究終點

**本次已可由 Client 靜態原生碼閉合的有界機制：**

1. **章節物件入口**：`0x47D530` 把 scene object `+0x248`（章節/primary key）存到互動 context `+0x120`，從 **Table** ChapterIndex `0xFC0F68` 呼叫 `0x47E890` 選 FIRST，立即將選到的 scene 值交 `0x47B5C0`；後者如果物件鍵不是特殊值 `0xEA61`，呼叫 `0x565720(primary,firstScene)`，後續再進 event lookup。**若 FIRST 返回 0，caller 仍將 0 傳入**：這個函式沒有證明 0 必定匹配合法 Event SceneList。
2. **特殊物件鍵是不同控制流**：`0x47B5EB..0x47B606`：`object+0x248==0xEA61` 時檢查 `object+0x26C`，若為 0 才執行 `0x47B850`，並跳過這一次普通 `0x565720`；若非零直接跳至共同結尾。不能說「任何 chapter 物件點擊都開 Pindos 劇情」。
3. **控制器啟動 gate**：`0x565720` 在**讀入 chapter/scene**後先寫 `controller+0x89=1` (`0x56575D`)，**再測試** `controller+0x28` 是否已有進行中狀態。busy 時 `0x565766..0x565778` 將兩參數送給 `0x6EDB60` 並離開，不覆寫 `+0x38/+0x3C`；idle 時 `0x565785/+0x565788/+0x56578B` 依次寫 primary、scene 與 active=1。**新增重要反例：busy 分支也先改 `+0x89`，不可推論 busy 對控制器無副作用。** `0x6EDB60` 的所有外部效果未由此函式可證。
4. **Event SceneList 命中／失敗**：`0x5658C2..0x565926` 將 `(primary,scene)` 對 map 比對；查不到就直接跳到 `0x565A65` epilogue；查到才 `0x5659B5..0x5659D9` 以選定 `funcName` 與 Lua 資源呼叫 `0x6F4A50`。**新增重要反例：在已寫 `+0x28=1,+0x38/+0x3C` 的 idle 情況下，`0x565926` miss 只跳 epilogue，局部沒有將這三欄清0；不能稱「找不到腳本就恢復為 idle」。是否由其他稍後 callback 清理，需獨立證據。**
5. **NEXT 推進 gate**：`0x561DB0` 先測 `controller+0x89`。非零 branch 再看 active=`+0x28`：若 active 非零，在 `0x561DF6` 清 active，完成局部回報／視覺狀態回復，再以 `0x47E640(chapter,oldScene)` 查 successor；若 active 已是 0，略過前半段，但仍可進 NEXT。`0x561EE5` 先把 successor 寫回 `+0x3C`；只在 successor 非 0 時 `0x561EF3` 呼叫 `0x565720(chapter,newScene)`。**不是 oldScene+1**；需 Table SceneList row 定義順序。
6. **尾端/無後繼**：`0x47E640` 回傳0→`0x561F0B`，部分共同通知後在 `0x561F47/4A` 把 `controller+0x38/+0x3C` 清零；該分支**不會**呼叫新 Lua。`+0x28` 先前可能於 `0x561DF6` 清零，但 `+0x89` 在本函式未直接重設；不要將所有欄位稱為完全 reset。
7. **非場景模式與可能出站**：`+0x89==0` 時，active非零分支清 active；若主鍵 `+0x38!=0`，在 `0x561F79..0x561FB5` 依額外狀態判斷可能呼叫 `0x4A39A0(primary,scene)`（C→S application `0x3F` producer，參見 T16-122/127）；若主鍵==0，`0x561FB7..0x561FE5` 先走另一個本地處理器 `0x5623A0`，然後可呼叫 `0x4A39A0`；最後 `0x562091/94` 清 primary/scene。**不能把任一分支都說成「觸發下一幕」或「必然發送」。**
8. **兩個可證的 `0x561DB0` call site**：`0x561D7F` 在 `0x561760` 的 map candidate miss branch 可同步呼叫它；`0x56288C` 於另一條重設／事件生命週期路徑執行多個 Client 狀態清理後呼叫它（這是**實際 callsite**，不是臆造 Lua `RestoreMap` 的直接 callback）。因此 NEXT 的觸發不一定就是 Lua `RestoreMap()` 返回當下。缺少綁定到 Quest15 Scene3 的 runtime callback 時序，不能把這兩者強行視為同一件事。
9. **單選與多選 UI 分支**：`0x47D810` 只有當 `[0xFB7258]` 指標有效且 `[+0x2C]-[+0x28]` 對齊後恰 `4 bytes` 時，走 `0x47D9CE→0x47D530→FIRST`；其他非單選條件進入**另一個事件** `0xF4421` 的建構/發布路徑，而不是一律立即進場。`0x47D530` FIRST 之後還有與 NPC/Quest 狀態有關的 `0x47D610`／`0x503440` 等後續處理，但它們不能倒推出 Server Quest15 完成或 Scene3 固定順序。
10. **重複/中斷邊界**：busy 入口會將輸入 pair 送 `0x6EDB60`，不是默默覆寫；`0x565720` 的 `+0x89` 在 busy 時可能已為 1；SceneList miss 不會在本地 epilogue 清 active；NEXT 無後繼才在另一條路徑清鍵。以上三種狀態不能用同一個「失敗就 reset」相容策略代替原生 Client 事實。

**研究狀態**：T16-132 作為「Client 原生觸發、FIRST/NEXT 排程、事件/UI 分流、失敗與停止 gate」之**有界靜態研究目標已達成**。但 Pindos `(15,3)` 在實際 `Table/SceneList.xml` 中的序列位置尚缺第一手 row；原版 Server 是否使 Quest15 播放 Scene3、`RestoreMap` 全 native 副作用、真實事件 poll/腳本生命週期與可玩性都**沒有**在本段閉合。不得混淆本研究有界完成與全 Pindos 端到端完成。

## B. 既有資料的前置條件與不等價鍵域

- `QuestInfo.id=15`、`Event/SceneList.xml questIdx=15`、`Table/SceneList.xml CHAPTER.chapterIdx`、`town=5`、NPC10338、Scene3 腳本物件10047，**語義不同**；只有在實際傳入 key 相同且 Map row 命中時才能沿用相同數字。
- `0x47E890` 不等於固定返回 scene index1；它取得對應章節 scene vector 的第一個值，若沒有 row/序列為空則返回0。
- `0x47E640` 不做 `sceneIdx++`，而是依 TableSceneList 既有 ordered vector 定位 current 然後回傳 successor，找不到／到尾返回0。
- `0x565720` 參數/欄位屬「本地劇情控制鍵」，不自帶 Server 任務接受／交付成功語意。
- Scene3 原生 Event STP `(15,3)→pindos_talkevent` 為 T16-125/129 證據，**這不是**可觀測到 `FIRST/NEXT(15)=3` 的 runtime trace，也不是 Server 命令。

## C. 新增正反測試矩陣（只是假設條件輸入，未執行遊戲）

| 情境 | 必要條件／入口 | 直接原生效果 | 反證／不可斷言 |
|---|---|---|---|
| NPC Quest15 candidate | T16-131 `0x5008B0` 第一候選為15，事件type/action通過 | `0x561760(15,1)`；idle 可以保存鍵、產生後續有界排程 | 不是立即呼叫 `Event/SceneList(15,3)`，不保證原版 Server回覆 |
| S→C `0x47` 兩鍵 | handler 讀 payload+2/+4 | 進 `0x561760(keyA,keyB)`，需走 idle/non-special gate | 不等於直接進 Lua；Server request↔reply 未證 |
| 章節單選物件、FIRST 存在 | `0x47D810` unique4B、物件 key 非 EA61 | `0x47D530→0x47E890→0x47B5C0→0x565720` | FIRST 不保證是3；quest ID 不保證與 chapter key 同值 |
| 章節 UI 多於一選項 | `0x47D810` 非 4B 且全域指標有效 | 建立 action `0xF4421` 的獨立 UI event path | 不能當作 FIRST 立即啟動 |
| 特殊章節鍵 EA61 | `+0x248==0xEA61, +0x26C==0` | 呼叫 `0x47B850`，跳過一般 `0x565720` | 不知 `0x47B850` 完整外部效果；不保證 Scene3 |
| 特殊鍵 EA61 已標記 | `+0x26C!=0` | 直接共同收尾，不做普通場景載入 | 不能當作沒判斷重複，確有 gate |
| controller idle → script pair exists | `+0x28==0`；Event map 有 pair | 保存+38/+3C，active=1，呼叫 Lua loader | 可能仍有 VM/資源錯誤；不保證畫面成功 |
| controller idle → script pair missing | `+0x28==0`；Event map 無 pair | 保存+38/+3C，active=1；`0x565926` 直接 return | **沒有局部 active 清零**；不能說安全重試或恢復 |
| controller busy → scene request | `+0x28!=0` | `+0x89` 先設1，再轉 `0x6EDB60`，不覆寫鍵 | 不是 no-op，不保證等候順序或解鎖 |
| controller scene NEXT success | `+0x89!=0`，NEXT找到非0 | `+0x3C` 更新，`0x565720` 嘗試載入下一幕 | 除非 ChapterTable 存實值，不能預言 sceneIdx |
| controller scene NEXT end | `+0x89!=0`，NEXT返回0 | 共用通知後清+38/+3C，沒有新的 Lua 執行 | 不能證明 Server 進度已保存 |
| controller non-scene finish/notify | `+0x89==0, +0x28!=0` | 視 primary/其他 gate 有條件 `0x4A39A0`，最後清鍵 | 不是 NEXT scene、不是 Server accept/ack |
| controller double request while busy | 相鄰 `0x561760`/`0x565720` 分支任一 busy | 都走 `0x6EDB60`，但兩入口對+0x89 寫入的值不同 | 不可合併成同一去重/queue policy |
| Task data Scene3 unknown | 真正 TableSceneList rows 尚未解包 | 不能固定 scene1→2→3→4，僅提供 conditional match | 統一由 S00 協調是否補原始 row，T16 不分派外 Task |

## D. 精確的本地狀態機偽碼（只表達已證路徑）

```cpp
// 這是 source-based PSEUDOCODE，並非官方 Client source。
void SceneEntryPseudo(int primary, int scene) {
    sceneController.flag89 = 1;        // 0x56575D: even on busy
    if (sceneController.active28 != 0) {
        OtherEventPath_6EDB60(primary,scene); // effects not established
        return;
    }
    sceneController.primary38 = primary;
    sceneController.scene3C = scene;
    sceneController.active28 = 1;
    const auto* row = EventSceneListLookup(primary,scene);
    if (!row) return; // no local state reset seen in 0x565926→0x565A65
    LuaLoader_6F4A50(row->funcName); // success/failure afterward is separate
}
void SceneAdvancePseudo(SceneController* ctl) {
    if (ctl->flag89) {
       if (ctl->active28) { ctl->active28=0; /* local presentation cleanup */ }
       int next = TableSceneListNext(ctl->primary38,ctl->scene3C);
       ctl->scene3C = next;
       if(next != 0) { SceneEntryPseudo(ctl->primary38,next); return; }
       ctl->primary38=ctl->scene3C=0; // 0x561F47/4A
    } else if(ctl->active28) {
       ctl->active28=0;
       // some branches can send an outbound application 0x3F;
       // others run local stage cleanup; no NEXT is called here.
       ctl->primary38=ctl->scene3C=0;
    } else {
       ctl->primary38=ctl->scene3C=0;
    }
}
```

## E. 逐項研究證據等級與缺口

- **本次 BIN 已確認**：`0x47D530/0x47E890/0x47B5C0` chapter FIRST 的直接 caller；EA61/26C 特殊路；`0x47D810` 單選與非單選事件分流；`0x565720` 先改+89再測 active、idle 時保存 key/active；Event map miss 沒有本地 reset；`0x561DB0` flag+89 NEXT 與 non-scene 兩條不同分支；NEXT=0 清主鍵/scene；實際同步 caller `0x561D7F/0x56288C`。
- **沿用較早有界原始證據**：T16-125 Scene 四份 Event.stp Lua；T16-129 Event SceneList parser、`0x6F4A50` 的函式名載入；T16-130 Table SceneList FIRST/NEXT vector reader；T16-131 NPC/S2C scene key writer。上述不升格為整篇 FULL-PASS。
- **Client 待逆向**：`0x6EDB60` 實際事件排程/失敗策略、`0xF4421` 發布後的 consumer 與選項回呼、`0x47B850` 特殊 chapter callback、`0x565720` Lua loader 失敗後是否另有全域 reset；這些如影響與 Quest15 的直接因果，應後續定向查證，不得憑單一 caller 稱已必然完成播放。
- **Server 待開發**：任務接取／劇情鍵權威決策、場景狀態重連/回填、成功/拒絕/解鎖策略由相容 Server 規格自行決定。不得宣稱原版 Server 必定發 `0x47(15,3)`。
- **跨功能待整合**：`Table/SceneList.xml` 實際 rows／排序、場景資源存在性、UI 事件 hub 和 Lua/地圖副作用；T16 只標記所需原始輸入與可觀測界面，不建立/分配其他 Task/RR。
- **待遊玩驗證**：原版 Client NPC10338 點擊後是否命中 Quest15 candidate；實際 `(primary,sceneIdx)` trace；Scene3 是否連續播放；中斷/重入後 UI 是否留下 scene key；原版 Server 或相容 Server 測試與真實 packet capture 均未執行。
- **T01 審核**：本次有界靜態完成不等於 T01 原生 FULL-PASS、main README `NEEDS_FIX` 已結案。T16 作者勘誤待正式 T01 複驗。

## F. 接續建議（不代替 S00 派工）

- T16-133：四幕 Quest15 Lua 的 `OpenTalkScene`／`DoProlog`／`RevPhase1` 與 **任務/UI 原生 consumer**，特別查 NEXT 的原生 callback 是否來自腳本命令或其他事件；本稿不把 `RestoreMap()` 假設為 `0x56288C` 的直接呼叫者。
- T16-134：業務 C→S 0x1C/0x3F/0x36 與 S→C 0x40/0x45/0x46/0x47/0x6F/0x74 的必要條件／事件來源矩陣。保留官方 request-reply pairing unknown。
- T16-135：引入確實可驗證的 Table SceneList row 後，才能將 Quest15 Scene3 順序與原版 Client 可玩性設成可驗收主張；否則只整合條件式契約及精確缺口。

## G. Native evidence appendix (first-hand BIN slices; VA, raw, SHA-256 and objdump)

本附錄由下列起點直接向原始 KR BIN 擷取機器碼，全部 `.text` raw=VA−0x400C00，每筆列實際 bytes SHA256 並完整保存 disassembly。這是 repo 可離線復現的證據；函式名稱僅為研究暫名。切片最後可能截斷下一指令，**只引用已完整反組譯的指令**。`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=... --stop-address=... Tartaros.bin` 為可重現流程。

### G01. Scene object FIRST writer and call

- VA `[0x0047D530,0x0047D5F8)`; raw `[0x7C930,0x7C9F8)`; 200 bytes; **SHA256 `aed007a244e9e261b6eda3cc31ddaa6df8588c7eeaad11c38b80ea204727c65a`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047d530 <.data+0x7c930>:
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
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
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
```

### G02. Scene object branch EA61 versus normal Event dispatch

- VA `[0x0047B5C0,0x0047B6A9)`; raw `[0x7A9C0,0x7AAA9)`; 233 bytes; **SHA256 `d7218ab5ea6c49f3d3d1609d593d5c5c3f0152b7d251c578b90b20b8d7454e29`**.

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

### G03. Chapter widget one-selection vs independent UI action F4421

- VA `[0x0047D86A,0x0047D910)`; raw `[0x7CC6A,0x7CD10)`; 166 bytes; **SHA256 `badbcd69ef10dc463b9d816aa1b543b16789f6efe1e7fdeab82edf9783ef9a53`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047d86a <.data+0x7cc6a>:
  47d86a:	a1 58 72 fb 00       	mov    eax,ds:0xfb7258
  47d86f:	3b c3                	cmp    eax,ebx
  47d871:	0f 84 5d 01 00 00    	je     0x47d9d4
  47d877:	8b 48 2c             	mov    ecx,DWORD PTR [eax+0x2c]
  47d87a:	2b 48 28             	sub    ecx,DWORD PTR [eax+0x28]
  47d87d:	83 e1 fc             	and    ecx,0xfffffffc
  47d880:	83 f9 04             	cmp    ecx,0x4
  47d883:	0f 84 45 01 00 00    	je     0x47d9ce
  47d889:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  47d890:	75 1e                	jne    0x47d8b0
  47d892:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  47d898:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47d89b:	e8 e0 9b 10 00       	call   0x587480
  47d8a0:	68 c0 cc bc 00       	push   0xbcccc0
  47d8a5:	e8 70 4a 41 00       	call   0x89231a
  47d8aa:	83 c4 04             	add    esp,0x4
  47d8ad:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47d8b0:	6a 18                	push   0x18
  47d8b2:	e8 b1 39 41 00       	call   0x891268
  47d8b7:	83 c4 04             	add    esp,0x4
  47d8ba:	3b c3                	cmp    eax,ebx
  47d8bc:	74 1d                	je     0x47d8db
  47d8be:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  47d8c1:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  47d8c4:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  47d8c7:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  47d8ca:	c7 40 10 21 44 0f 00 	mov    DWORD PTR [eax+0x10],0xf4421
  47d8d1:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  47d8d7:	8b f0                	mov    esi,eax
  47d8d9:	eb 02                	jmp    0x47d8dd
  47d8db:	33 f6                	xor    esi,esi
  47d8dd:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  47d8e4:	75 23                	jne    0x47d909
  47d8e6:	83 0d d0 ad fa 00 01 	or     DWORD PTR ds:0xfaadd0,0x1
  47d8ed:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  47d8f4:	e8 97 00 2d 00       	call   0x74d990
  47d8f9:	68 70 cc bc 00       	push   0xbccc70
  47d8fe:	e8 17 4a 41 00       	call   0x89231a
  47d903:	83 c4 04             	add    esp,0x4
  47d906:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47d909:	8b 15 d4 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bd4
  47d90f:	52                   	push   edx
```

### G04. Chapter widget action dispatch and unique-first callsite

- VA `[0x0047D9A6,0x0047D9E0)`; raw `[0x7CDA6,0x7CDE0)`; 58 bytes; **SHA256 `fd733fafea49bf51a4e07b8149ee4b39ff7780e35eb697a283eb514057d8052d`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047d9a6 <.data+0x7cda6>:
  47d9a6:	68 cf 00 00 00       	push   0xcf
  47d9ab:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d9b2:	e8 b9 d8 10 00       	call   0x58b270
  47d9b7:	83 c4 44             	add    esp,0x44
  47d9ba:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d9bd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d9c4:	59                   	pop    ecx
  47d9c5:	5f                   	pop    edi
  47d9c6:	5e                   	pop    esi
  47d9c7:	5b                   	pop    ebx
  47d9c8:	8b e5                	mov    esp,ebp
  47d9ca:	5d                   	pop    ebp
  47d9cb:	c2 08 00             	ret    0x8
  47d9ce:	50                   	push   eax
  47d9cf:	e8 1c c1 0b 00       	call   0x539af0
  47d9d4:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47d9d7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47d9da:	e8 51 fb ff ff       	call   0x47d530
  47d9df:	8b               	mov    ecx,DWORD PTR [ebp-0xc]
```

### G05. Controller initial busy mode and other event path

- VA `[0x00561797,0x00561823)`; raw `[0x160B97,0x160C23)`; 140 bytes; **SHA256 `78658d92e54beca9a67465705f4ea8f02d51d55b98080419866941576b44187c`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561797 <.data+0x160b97>:
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
```

### G06. Controller writes primary/scene/active after gates

- VA `[0x005618DC,0x00561927)`; raw `[0x160CDC,0x160D27)`; 75 bytes; **SHA256 `fd571372a7841538c4fcbb6b121c3a5e96e71d62cb58f6e9b00fff19fceb408f`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005618dc <.data+0x160cdc>:
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 	mov    DWORD PTR [esp+0x68],0x2
  561901:	00 
  561902:	e8 79 5b 02 00       	call   0x587480
  561907:	68 c0 cc bc 00       	push   0xbcccc0
  56190c:	e8 09 0a 33 00       	call   0x89231a
  561911:	83 c4 04             	add    esp,0x4
  561914:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561918:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  56191f:	75 24                	jne    0x561945
  561921:	09 35 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,esi
```

### G07. Controller record not found callback: sync stage advance

- VA `[0x00561D2A,0x00561DA5)`; raw `[0x16112A,0x1611A5)`; 123 bytes; **SHA256 `844c80edbd2f6061a4cbe70868d92d331339e039076423f511065a9e1cb278a4`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561d2a <.data+0x16112a>:
  561d2a:	c6 44 24 68 07       	mov    BYTE PTR [esp+0x68],0x7
  561d2f:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  561d33:	c7 05 b0 94 fd 00 02 	mov    DWORD PTR ds:0xfd94b0,0x2
  561d3a:	00 00 00 
  561d3d:	3b f3                	cmp    esi,ebx
  561d3f:	74 29                	je     0x561d6a
  561d41:	8d 4e 04             	lea    ecx,[esi+0x4]
  561d44:	83 ca ff             	or     edx,0xffffffff
  561d47:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  561d4b:	75 1d                	jne    0x561d6a
  561d4d:	8b 06                	mov    eax,DWORD PTR [esi]
  561d4f:	8b 10                	mov    edx,DWORD PTR [eax]
  561d51:	8b ce                	mov    ecx,esi
  561d53:	ff d2                	call   edx
  561d55:	8d 46 08             	lea    eax,[esi+0x8]
  561d58:	83 c9 ff             	or     ecx,0xffffffff
  561d5b:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  561d5f:	75 09                	jne    0x561d6a
  561d61:	8b 16                	mov    edx,DWORD PTR [esi]
  561d63:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  561d66:	8b ce                	mov    ecx,esi
  561d68:	ff d0                	call   eax
  561d6a:	39 7c 24 34          	cmp    DWORD PTR [esp+0x34],edi
  561d6e:	72 16                	jb     0x561d86
  561d70:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561d74:	51                   	push   ecx
  561d75:	e8 92 f4 32 00       	call   0x89120c
  561d7a:	83 c4 04             	add    esp,0x4
  561d7d:	eb 07                	jmp    0x561d86
  561d7f:	8b cb                	mov    ecx,ebx
  561d81:	e8 2a 00 00 00       	call   0x561db0
  561d86:	8b 4c 24 60          	mov    ecx,DWORD PTR [esp+0x60]
  561d8a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561d91:	59                   	pop    ecx
  561d92:	5f                   	pop    edi
  561d93:	5e                   	pop    esi
  561d94:	5b                   	pop    ebx
  561d95:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  561d99:	33 cc                	xor    ecx,esp
  561d9b:	e8 61 f2 32 00       	call   0x891001
  561da0:	8b e5                	mov    esp,ebp
  561da2:	5d                   	pop    ebp
  561da3:	c2 08              	ret    0x8
```

### G08. Scene advance gated by flag+89 and active reset

- VA `[0x00561DB0,0x00561E48)`; raw `[0x1611B0,0x161248)`; 152 bytes; **SHA256 `2eed249bed9d9b8acf364aac5acd3c6e389cbfc4c6f267f4a993c2b9138bb81c`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561db0 <.data+0x1611b0>:
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
  561dfe:	bb 01 00 00 00       	mov    ebx,0x1
  561e03:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561e06:	84 1d d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,bl
  561e0c:	75 25                	jne    0x561e33
  561e0e:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  561e14:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e18:	e8 63 25 19 00       	call   0x6f4380
  561e1d:	68 d0 e6 bc 00       	push   0xbce6d0
  561e22:	e8 f3 04 33 00       	call   0x89231a
  561e27:	83 c4 04             	add    esp,0x4
  561e2a:	83 ce ff             	or     esi,0xffffffff
  561e2d:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e31:	eb 03                	jmp    0x561e36
  561e33:	83 ce ff             	or     esi,0xffffffff
  561e36:	68 ec 06 c1 00       	push   0xc106ec
  561e3b:	6a 00                	push   0x0
  561e3d:	68 c8 f3 fd 00       	push   0xfdf3c8
  561e42:	e8 59 b2 f4 ff       	call   0x4ad0a0
  561e47:	f6       	test   BYTE PTR ds:0xfaadd4,0x1
```

### G09. Scene NEXT selector, zero handling, new scene entry

- VA `[0x00561EA3,0x00561F0B)`; raw `[0x1612A3,0x16130B)`; 104 bytes; **SHA256 `9a1fcc2a5bd82d4226f95dd9566254cf64c282a58b2d549e719b69198ea5e2ea`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561ea3 <.data+0x1612a3>:
  561ea3:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  561eaa:	75 25                	jne    0x561ed1
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
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
```

### G10. Scene NEXT end clears keys, no new Lua

- VA `[0x00561F0B,0x00561F60)`; raw `[0x16130B,0x161360)`; 85 bytes; **SHA256 `2b3fa7b7083145946f242a3f08c80734d30e87ef078768743e74eda01c5bbb22`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561f0b <.data+0x16130b>:
  561f0b:	f6 05 c0 0f fc 00 01 	test   BYTE PTR ds:0xfc0fc0,0x1
  561f12:	75 25                	jne    0x561f39
  561f14:	83 0d c0 0f fc 00 01 	or     DWORD PTR ds:0xfc0fc0,0x1
  561f1b:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  561f22:	00 
  561f23:	e8 28 6f 17 00       	call   0x6d8e50
  561f28:	68 b0 db bc 00       	push   0xbcdbb0
  561f2d:	e8 e8 03 33 00       	call   0x89231a
  561f32:	83 c4 04             	add    esp,0x4
  561f35:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561f39:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  561f3c:	50                   	push   eax
  561f3d:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  561f42:	e8 e9 74 17 00       	call   0x6d9430
  561f47:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  561f4a:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
  561f4d:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561f51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f58:	59                   	pop    ecx
  561f59:	5f                   	pop    edi
  561f5a:	5e                   	pop    esi
  561f5b:	5b                   	pop    ebx
  561f5c:	8b e5                	mov    esp,ebp
  561f5e:	5d                   	pop    ebp
  561f5f:	c3                   	ret
```

### G11. Non-scene finish 0x3F branch and separate local-state behavior

- VA `[0x00561F60,0x005620A9)`; raw `[0x161360,0x1614A9)`; 329 bytes; **SHA256 `43629ad8f066fbe8a843a690cb20120df8fe8bce28509f31d8973788aef5ba9c`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561f60 <.data+0x161360>:
  561f60:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00    	je     0x562091
  561f69:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff       	call   0x434250
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
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00 00       	mov    ebx,0x1
  561fef:	33 f6                	xor    esi,esi
  561ff1:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  561ff8:	75 28                	jne    0x562022
  561ffa:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  562000:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  562007:	00 
  562008:	e8 73 23 19 00       	call   0x6f4380
  56200d:	68 d0 e6 bc 00       	push   0xbce6d0
  562012:	e8 03 03 33 00       	call   0x89231a
  562017:	83 c4 04             	add    esp,0x4
  56201a:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  562021:	ff 
  562022:	68 ec 06 c1 00       	push   0xc106ec
  562027:	56                   	push   esi
  562028:	68 c8 f3 fd 00       	push   0xfdf3c8
  56202d:	e8 6e b0 f4 ff       	call   0x4ad0a0
  562032:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  562039:	75 28                	jne    0x562063
  56203b:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  562041:	c7 44 24 28 05 00 00 	mov    DWORD PTR [esp+0x28],0x5
  562048:	00 
  562049:	e8 32 54 02 00       	call   0x587480
  56204e:	68 c0 cc bc 00       	push   0xbcccc0
  562053:	e8 c2 02 33 00       	call   0x89231a
  562058:	83 c4 04             	add    esp,0x4
  56205b:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  562062:	ff 
  562063:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  562069:	83 ec 08             	sub    esp,0x8
  56206c:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  562070:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  562074:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  562078:	d9 1c 24             	fstp   DWORD PTR [esp]
  56207b:	e8 a0 79 02 00       	call   0x589a20
  562080:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  562086:	e8 15 2b ea ff       	call   0x404ba0
  56208b:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  562091:	89 77 38             	mov    DWORD PTR [edi+0x38],esi
  562094:	89 77 3c             	mov    DWORD PTR [edi+0x3c],esi
  562097:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  56209b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5620a2:	59                   	pop    ecx
  5620a3:	5f                   	pop    edi
  5620a4:	5e                   	pop    esi
  5620a5:	5b                   	pop    ebx
  5620a6:	8b e5                	mov    esp,ebp
  5620a8:	5d                   	pop    ebp
```

### G12. Controller separate scene entry flag mutation before busy test

- VA `[0x00565720,0x0056579C)`; raw `[0x164B20,0x164B9C)`; 124 bytes; **SHA256 `38f256a811f311bb17744f6e924c11318a9154b001b1af2e51b9c2dc1d42314c`**.

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
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
```

### G13. Scene entry early local event/status, map lookup

- VA `[0x00565872,0x0056592C)`; raw `[0x164C72,0x164D2C)`; 186 bytes; **SHA256 `072a164464b85162e854e3d85b5d2e0aa068a1a6938ab867949dc14db255a52a`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00565872 <.data+0x164c72>:
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

### G14. Event map hit Lua loader name and resource call

- VA `[0x0056592C,0x005659E3)`; raw `[0x164D2C,0x164DE3)`; 183 bytes; **SHA256 `385132cc922e14607427d84ca09a6bbe6b764b6f6a5c5cc189b53564441ce0ef`**.

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
  5659c8:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                	jae    0x5659d6
  5659d2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5659d8:	50                   	push   eax
  5659d9:	e8 72 f0 18 00       	call   0x6f4a50
  5659de:	e8 6d e8 ec ff       	call   0x434250
```

### G15. Event map miss epilogue lacks local controller reset

- VA `[0x00565A48,0x00565A81)`; raw `[0x164E48,0x164E81)`; 57 bytes; **SHA256 `954eb15aa5169df5c0221c80cbed4c99132b01ff2365178208fa74e30f00007f`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00565a48 <.data+0x164e48>:
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
```

### G16. Second stage advance caller after lifecycle reset

- VA `[0x0056284A,0x005628B1)`; raw `[0x161C4A,0x161CB1)`; 103 bytes; **SHA256 `ca878a6231fcf4eb3d29f56c679a47f48bb22bfc65abf05f979791dcc0cca4c5`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056284a <.data+0x161c4a>:
  56284a:	83 25 30 88 fb 00 fd 	and    DWORD PTR ds:0xfb8830,0xfffffffd
  562851:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  562858:	75 24                	jne    0x56287e
  56285a:	09 3d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,edi
  562860:	c7 44 24 40 0c 00 00 	mov    DWORD PTR [esp+0x40],0xc
  562867:	00 
  562868:	e8 63 0b ff ff       	call   0x5533d0
  56286d:	68 00 d1 bc 00       	push   0xbcd100
  562872:	e8 a3 fa 32 00       	call   0x89231a
  562877:	83 c4 04             	add    esp,0x4
  56287a:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  56287e:	b8 58 73 fb 00       	mov    eax,0xfb7358
  562883:	e8 b8 0e ff ff       	call   0x553740
  562888:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56288c:	e8 1f f5 ff ff       	call   0x561db0
  562891:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  562895:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  56289c:	59                   	pop    ecx
  56289d:	5f                   	pop    edi
  56289e:	5e                   	pop    esi
  56289f:	5b                   	pop    ebx
  5628a0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5628a4:	33 cc                	xor    ecx,esp
  5628a6:	e8 56 e7 32 00       	call   0x891001
  5628ab:	8b e5                	mov    esp,ebp
  5628ad:	5d                   	pop    ebp
  5628ae:	c2 04 00             	ret    0x4
```

### G17. Chapter context FIRST and post-call UI consumers

- VA `[0x0047D5A3,0x0047D5F8)`; raw `[0x7C9A3,0x7C9F8)`; 85 bytes; **SHA256 `b9329e98fed24f0f129622b6430672e5c47720a47460c59874b7f6b4c625ba4e`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047d5a3 <.data+0x7c9a3>:
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
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
```

### G18. Widget repeat/current chapter pointer and candidate list

- VA `[0x0047D6A5,0x0047D6F7)`; raw `[0x7CAA5,0x7CAF7)`; 82 bytes; **SHA256 `21f6a8ac9fa8844b7290f7ba64860664e461bf73be8e80cf5bb46990688429fa`**.

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047d6a5 <.data+0x7caa5>:
  47d6a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  47d6a9:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  47d6ad:	2b ce                	sub    ecx,esi
  47d6af:	c1 f9 02             	sar    ecx,0x2
  47d6b2:	33 c0                	xor    eax,eax
  47d6b4:	49                   	dec    ecx
  47d6b5:	74 19                	je     0x47d6d0
  47d6b7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  47d6bd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d6c0:	8b 1c 86             	mov    ebx,DWORD PTR [esi+eax*4]
  47d6c3:	40                   	inc    eax
  47d6c4:	3b 13                	cmp    edx,DWORD PTR [ebx]
  47d6c6:	0f 84 bc 00 00 00    	je     0x47d788
  47d6cc:	3b c1                	cmp    eax,ecx
  47d6ce:	72 f0                	jb     0x47d6c0
  47d6d0:	8b 97 1c 01 00 00    	mov    edx,DWORD PTR [edi+0x11c]
  47d6d6:	8d 44 24 0c          	lea    eax,[esp+0xc]
  47d6da:	42                   	inc    edx
  47d6db:	50                   	push   eax
  47d6dc:	8d 44 24 14          	lea    eax,[esp+0x14]
  47d6e0:	8d 8f 0c 01 00 00    	lea    ecx,[edi+0x10c]
  47d6e6:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  47d6ea:	e8 d1 61 3c 00       	call   0x8438c0
  47d6ef:	8b 00                	mov    eax,DWORD PTR [eax]
  47d6f1:	3b 87 10 01 00 00    	cmp    eax,DWORD PTR [edi+0x110]
```

## H. 研究結論／GitHub 提交驗證

本稿僅宣告 **T16-132 的 T16 職責內「觸發／NEXT 排程／本地場景/UI 分流」有界 Client 靜態目標**完成；不是完整 Quest15→Pindos 可玩、Table SceneList 真實 rows 已解、Server 官方邏輯已知或 T01 FULL-PASS。完整 Pindos E2E 仍待 T16-133～135。

Git Commit SHA、遠端 Git blob 與工作分支狀態請以提交工具後的獨立遠端讀回為準，本地稿不預先填入未發生的提交。
