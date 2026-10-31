# T14-WP03 — KR 關卡勝敗、結算轉移與中止／重入的原生界線

> 工作日期：2026-11-01（Asia/Taipei）。本稿為 WP03-01～04 的**有界靜態研究交付**；不聲稱原版勝利／失敗／中止算法已完整重建、官方 Server 已驗證、T01 整篇 FULL-PASS，亦不代表已通過原版 Client 可玩驗收。

## 0. 研究基線、方法與完成條件

- Repository：`we88ec3-prog/ttr_anal_multi`，**只提交** `t14/roy/chatgpt-web`。開工分支 head `bbecb1861556ab823e00c62193371f4adbae4b2f`（WP02），當時 main `b1fa730c99dbe2ff29f0ffed8b7a0448d6f4c460`。main 含額外其他 Task 更新，未於本稿合併，不覆寫 T01/S00/其他 Task。
- 原始 KR `Tartaros.bin`：**12,472,320 bytes**、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際重新唯讀 SHA 計算。PE32 i386，ImageBase `0x400000`，`.text` VA `0x401000`、raw `0x400`；該節 `raw = VA-0x401000+0x400`。原始 `Tartaros.exe` 另獨立雜湊，**不得套用 BIN VA**。
- 來源入口：`kr/tasks/T14/{README.md,task.json}`、`research/dispatch/inbox/T14.md`、`research/requests/index.json`；T14 KR 無已公開在 main 的 RR，未擅自建立/認領。此前 task.json 顯示 `analysis-paused-by-user`，本輪依使用者明確要求研究 WP03；不因此自行改 Task metadata。
- 原有正式證據：`kr-temp-roy/T14/WP02-20261031/T14-WP02-OBJECTIVES-EVENTS-PROGRESS-NATIVE.md`（blob `827216ca7b8ce9dc7460b37673e057d4b0753448`）；T14 封存 `kr/evidence/1d78642bfec7b5005988a1c2121404a3daadd2f62ba1e0068f8918b314b1ae99.txt`（blob `909cd378dbe0283355924358d3087c88ff7b49a3`）；T07 `kr/evidence/00c7ff83c85dd8f01e882d82bf2d83fcf6eed2788d3fd60dbd69682b2764d977.txt`（blob `9e53daa87621ddfa8c1dda72490f83c129b71d8d`）。
- 共用 T01 **有界 FULL-PASS**：`shared/verified-knowledge/client-scenario-map-native-reader-and-clear.md` 之 `CK-SCENARIO-MAP-READ-NATIVE-01`（`0x4AA510` 有效 owner/key 正常返回）與 `CK-SCENARIO-MAP-CLEAR-STATE-01`（`0x823850` 正常返回清 sentinel/count）。只復用這兩項精確主張，不把整個 T14/Server 勝負語意升級。
- T01 更正：`C-T01-20261027-04-result-return` 區分 0022/type0 與 TUTO004C 並補上非零角色結果分支；`C-T01-20261028-06-quest-vs-scene` 將 local scenario14 flag、Quest16、script1000/14 分開。其他 T07/T08/T12 方法**只引用主責**，不改其原稿。
- 獨立驗證：從上述 BIN 直接抽原始 bytes；GNU `objdump -D -b binary -m i386 -M intel --adjust-vma` 檢查選定函式與分支指令；精確 `64` 處機器碼指令窗和 `8` 個 0022 dispatch jump-table entry 保存於 `native-window-audit.json`，`verify_wp03_native.py` 重讀原件驗證，**本地結果 64/64、8/8 PASS**。這是「明確片段」驗證，不是全部可達 CFG 或真實封包/執行驗證。
- **研究終點**：WP03-01 找到 Client 可證的結果 writer/consumer；WP03-02 分清怪物清除與結果場景；WP03-03 審查失敗、死亡、超時、放棄與錯誤路徑；WP03-04 重入、重複通知與場景世代。凡缺原生因果證據之處，列 **Client 待逆向** 或 **Server 待開發**，不可偷補猜測。

## 1. WP03-01：一般結果「種類」與「同類結果資料」為兩層不同欄位

### 1.1 登記與 S2C 0022 的八種 type 不是八種勝敗值

場景訊息表 `0x4B7DC0`：`FD2E0C = 0x4B9770`，以 `FD2CFC` 為 base、8-byte slot，`(0xFD2E0C-0xFD2CFC-4)/8 = 0x22`，為**場景管理器**接收表 `0022`（不能與別處同號 C2S opcode 混為同一路）。

原始 BIN 的 `0x4B9770` 指令：
```asm
4B9798 mov eax,[ebp+8]        ; 指向 message
4B979B movsx eax,byte ptr [eax+2]
4B979F cmp eax,7
4B97A2 ja 0x4B996C
4B97A8 jmp dword ptr [eax*4+0x4B9994]
```

精確讀取 **jump table 8 x DWORD**（`VA 0x4B9994`，位於 .text data block，並非可隨意線性反組譯的指令）：

| message+2 類型 | case 地址 | 分配 bytes | constructor | RTTI／原來源名稱 | 本輪可證界線 |
|---:|---|---:|---|---|---|
| 0 | `4B97AF` | `0x6104` | `4B9E30` + vtable `C07374` | `Scene::CScenarioDecision` | 一般 Scenario 結果入口 |
| 1 | `4B984B` | `0xBFAC` | `4BD590` | `Scene::CDuelDecision` | 決鬥結果種類，不是「敗北」 |
| 2 | `4B9820` | `0xBFC4` | `4BC170` | `Scene::CMissionDecision` | 任務結果種類，不是「死亡」 |
| 3 | `4B98A1` | `0xBFA8` | `4C4FB0` | `Scene::CRaidDecision` | Raid 類結果 |
| 4 | `4B9876` | `0xBFA8` | `4C0610` | `Scene::CGvGDuelDecision` | GvG 結果 |
| 5 | `4B98C5` | `0xBFA8` | `453E60` | `Scene::CInfiniteDungeonDecision` | 無盡副本 |
| 6 | `4B98E9` | `0xBFA8` | `434320` | `Scene::CEternalTowerDecision` | 永恆之塔 |
| 7 | `4B990D` | `0xBFA8` | `422440` | `Scene::CDailyDungeonDecision` | 日常地下城 |

型別名稱由已存 Ghidra RTTI/vtable 名稱及 constructor 行為相互對照；本次額外定向讀取 7 個對應反編譯函式，但沒宣稱全部虛擬方法已逐項驗畢。**切勿把 0022/type1 解讀為失敗、type2 解讀為放棄**；那是**結果場景的子類別分派**。

type0 原始可驗證：
```asm
4B97AF push 0x6104
4B97CC call 0x4B9E30
4B97D1 mov [esi],0xC07374
4B97F0 call 0x4B7D50             ; 替換舊場景
4B97FB mov edx,[edi]
4B97FD mov edx,[edx+0x38]       ; 新場景 virtual +38
4B9808 call edx
```
type0 的新場景 `virtual+0x10=0x4C43B0`、`virtual+0x38=0x4C4550` 是先前 T07 保存的有界映射；其他七類的 `virtual+38` 不能直接套用 4C4550 的 Scenario 欄位格式。

### 1.2 0022/type0 的結果 payload 分支（真正的 UI outcome 路徑）

`0x4C4550` 首先要求 `BYTE message+2 == 0`，符合才寫入結果 storage `DAT_00FE18F8`；不符合時是**本 handler 的型別錯誤**，可條件送 2-byte `C2S0019`、返回 `0x80004005`，**絕非已證的戰敗回報**：

```asm
4C4580 cmp byte ptr [esi+2],0
4C4584 je 0x4C45D5
4C4593 cmp dword ptr [0xFBA798],0
4C459A mov eax,0x19
4C45BA call edx                  ; sender, body length 2 (受 transport gate)
4C45BC mov eax,0x80004005      ; error
```

正常接收：
```asm
4C45D5 mov eax,[0xFE18F8]
4C45DA mov ecx,[esi+4]
4C45DD mov [eax+0x24],ecx
4C45E0 mov edx,[esi+8]
4C45E3 mov [eax+0x28],edx
4C45E6 mov ecx,[esi+0xC]
4C45E9 mov [eax+0x2C],ecx
4C45EC mov edx,[esi+0x10]
4C45EF mov [eax+0x30],edx
4C45F2 mov cx,[esi+0x14]
4C45F6 mov [eax+0x34],cx
4C462F push 0xF4297             ; 內部 UI 更新事件
4C463E cmp byte ptr [esi+4],0
4C4643 sete dl
4C4647 call 0x4BA8C0             ; 成立為 1 的 bool 引數
```

因此已讀**至少 22-byte 業務本體**；沒有外層 framing 長度、官方欄位全語意、封包是否還有未讀尾端的證據。`+4` 是 DWORD 複製的起點，但後續 **BYTE +4** 另作零／非零結果畫面路由，**不能據此聲稱整個 DWORD 都是 bool**。`+8` DWORD 中的 `BYTE+9` 影響返回/角色詳情分支，仍非勝利狀態。

下游 `0x5AAE50` 對 `F4297` 呼叫 `0x6BA400`，後者在 `0x6BA624` 對 `[resultStorage+0x24]` 的低位元組作比較：
```asm
6BA4B6 mov ebx,[0xFE18F8]
6BA624 cmp byte ptr [ebx+0x24],0
6BA628 je 0x6BA685
6BA66B mov dword ptr [ebp-0x30],0x15A  ; 非零：字串索引
6BA6BA lea ecx,[ebp-0x30]             ; 零：另一分支
```
零分支在 `0x6BA6C?` 後選 `0x159`（已核函式偽碼 + 原件分支），非零選 `0x15A`。兩者屬**結果文字切換**的有界 native consumer，並未獨立讀出該字串實際的本地化內容，也未取得官方 win/lose enum 值。**只可稱 zero/nonzero UI 路徑；不可自動命名 0=Victory、1=Defeat，更不可將失敗原因映射到死亡/超時**。

### 1.3 進入結果時的 UI 與控制權

`0x4C43B0` 作 Scene::CScenarioDecision 初始化：停止既有過場、清空 checkpoint manager `0x5449A0`，使用 UI manager `pending state=8`（正常 ScenarioField state=7）。本輪原件確證：
```asm
4C4408 push 0
4C440E call 0x5624B0               ; 過場相關控制
4C4470 mov eax,[0xFB76E8]
4C44BF push 0xFB79F0
4C44C4 call 0x5449A0              ; checkpoint cleanup
4C4502 mov eax,8                 ; result UI state
```
`0x4BA8C0` 讀 `0xFAB1C0` 作演出 `_PositionList` 索引，清除/更新 actor 與 controller，建立 `CEmptyController`，`FBA7AC=0` 並設控制器 `+4=1`；**這個「ready」不代表可操作角色、合法出生位置或自動返回城鎮**。結果背景與一般 `S2C0012` 真實地圖不同。

## 2. WP03-02：清怪 vs Scenario 完成 vs 結果畫面

### 2.1 兩條 native 路徑不可合併

```text
TUTO / tutorial:
由 Lua / 4AA4D0 可建 C2S 0040 + WORD scenarioID
               ... 官方 Server 何時接受 / 完成未知 ...
TUTO owner 的 S2C 004C (0x4C4AC0 → 0x4C4F20)
  → [message+2] unsigned WORD
  → map 0xFC0F88、0x4C2880
  → 以 key 更新 value DWORD=1
  → 同 owner 與 Lua thread 有效時 0x4AA510 → IsScenarioEnded(ID)
  → 進一步的 TutorialMain 狀態/過場另需 T07/T16
  ≠ Quest16已完成、獎勵已入帳、一般副本結果頁面

一般 Scenario / mission:
場景管理器 S2C 0022 (0x4B7DC0 → 0x4B9770) [type0]
  → new CScenarioDecision / replace prior Scene
  → 4C43B0 results UI state8 / checkpoint cleanup
  → 4C4550 payload result storage
  → F4297/6BA400 result text & 4BA8C0演出
  → 6BA2C0/F431F/5AAE80 結果 UI 按鈕
  → conditional C2S0033 (returns request)
  ≠ 原本 TUTO 004C flag writer
```

`0x4C4F20` 原生 bytes（取樣跨 1 個完整局部 handler；本輪重新驗）：
```asm
4C4F75 movzx ecx,word ptr [eax+2]
4C4F7C mov eax,0xFC0F88
4C4F84 call 0x4C2880
4C4F89 mov dword ptr [eax],1
4C4F8F xor eax,eax
```

`0x4AA510` 正常返回 getter 透過 `ECX+4` map 讀 DWORD，`0x823850` 清 sentinel/count 由 T01 兩個限定 FULL-PASS 支持；其 FULL-PASS **不保證任何其他 sender、Server 勝敗條件或 Lua lifecycle**。舊 `Event.stp` 的 Lua snapshot 表明 `Tutorial_Part2` 等 `IsScenarioEnded(14) != FALSE(0)`；但不是 pristine runtime 實測。

### 2.2 擊殺、波次／HP0 的證據缺口

已知 T08/T12 的怪物生成、受傷、死亡或移除是**戰鬥物件事件**。本輪 `0022` 結果接收函式 `0x4B9770/4C4550` 沒有直接讀「怪物全部死光」計數或以 0.75 秒當判定；`004C` local writer 也不在其本體讀血量、怪物數或關卡 timer。這只是各**被檢函式內的負面觀察**，不等於整個遊戲不存在其他 Client 目標計數器/Server 事件判定。

**保留 Client 尚未閉合的實質鏈節**：T08/T12 已有個體死亡事件→其上游發送者/事件 ID→任務或 Scenario goal 狀態 writer→該 writer 的接受者/條件→何時收到 004C 或 0022；目前沒有原生生產者／消費者全鏈證明。需要以未來 T08/T12 的 exact SHA、method owner 與 callsite/virtual target 補證，**不是只問 Server 內部算法**。

先前以「HP0後0.75秒通知」「進場預設 scenario14/16 完成」「cluster COUNT＝勝利擊殺數」之 fixture，均禁止升格官方規則。**相容 Server 可以提出明示 ADR 的自訂判定，但不能稱官方復原；Client 必須按已證訊息和狀態方式被驅動**。

## 3. WP03-03：失敗、死亡、超時、取消與異常路徑

### 3.1 可證的三個不同分支

| 事件類別 | 原始 native 入口 / 結果 | 本次分類與不允許的推論 |
| --- | --- | --- |
| 0022 **結果場景模式** | `0x4B979B` 取 signed BYTE +2；table type0～7 對不同 Scene Decision 子類 | 模式分派，**不是**勝負 enum |
| 0022/type0 **結果顯示選擇** | `0x4C463E` 比較 BYTE+4 是否為0；`0x6BA624` 在 resultStore+24 做 zero/nonzero 判斷，字串索引 `159/15A` | 可確定畫面分支，**不能確定 0/1 的正式「勝／敗」命名或結果原因** |
| 0022/type0 **parser type mismatch** | `0x4C4580` 檢查 +2，非0回 `0x80004005` 並可能送 `C2S0019`（2 bytes） | **封包／接收器錯誤**；不是戰敗、放棄、超時、Retry 或未通關 ACK |

此外，`0022/type2` 的 `Scene::CMissionDecision` 走另一個 constructor (`0x4BC170`)，其中額外初始化/關聯 `0x4BC460`；此處有條件發 `0019`、`009F` 或本地 UI `F426C` 的不同分支，必須與一般 Scenario type0 區分。以 `4BC460` 查到的 **message+2 0/2** 和控制器欄位數量判斷不能直接當通用玩家死亡結果；完整 MissionDecision 的正規 outcome/parser 還未逐項驗證。

### 3.2 具體未完成：不能把「未見」等於「不存在」

| 需要調查的玩家情況 | 有限證據/已查入口 | 仍需原生第一手的解除條件 |
| --- | --- | --- |
| 玩家 HP 歸零、全隊死亡 | 已讀 type0 結果 handler、TUTO 004C；未見直接 kill-count 與 HP-death 決策 | T12 HP/death/party defeat producer 的原生 callback/XREF，以及 type0 outcome / other result type consumer／S2C; 此前**不能聲稱死後必送0022** |
| 倒數時間到期 | 0022/+4 UI 分支未解出 timeout reason；未從已檢函式得到 timer/timeout writer | T07/T12/T14 能證時間上游、條件分支、packet builder/receiver；**不能自行給倒數值** |
| 玩家手動放棄／離開關卡 | 已查結果頁 `6BA2C0→F431F→5AAE80`，返回 C2S0033 是**結果 UI**條件發送；未證它是戰鬥中放棄指令 | 追 ScenarioField/FormationController 的放棄按鈕、確認 UI、C2S builder 及 Server 回覆；與已出結果之0033分離 |
| 重新挑戰／重試 | 0022 → CScenarioDecision 屬**結果狀態**；同一處未找到已驗的 retry builder | 追 UI retry button widget/event、每種結果子類 virtual/送出時機、返回新 Scene owner；不能以重复0022當 retry |
| Socket 斷線與重登 | 0022 handler 沒有保存 result transaction/replay token 的已證欄位；單一局部函式不足以排除其他全域來源 | T02 connection lifecycle/重登定位與 T15 保存/交易設計，對照 Client 是否能安全重建 |
| 非法/不符訊息 | 0x4C4550 非0 type 返回 HRESULT error + 可送0019 | 已確認**本函式錯誤**；不能當死亡失敗包，也不能把 0019 視為原生勝敗確認 |

本輪**沒有**把「原版 Server 勝敗算法未知」當作暫停一切 Client 靜態研究的藉口。上表明列尚需 Client 原生 writer/parser/UI 路徑，而原版 Server 的真正判定、進度持久化、交易原子性則是獨立 Server-only 未知。

## 4. WP03-04：重複通知、重新進場、結果返回與生命周期

### 4.1 Tutorial 004C：值覆寫 ≠ Server 交易冪等

同一有效 TUTO owner 中，`0x4C4F20` 不判怪物數、沒有判當前 scenario14 是否正在進行，也沒有可見 compare-and-swap 或結果序號。相同 ID 連收，容器值重寫 `DWORD 1`；這是**被檢 map value 的冪等性**，不能推出封包序列、Lua 後續副作用或 Server 發獎 exactly-once。只要重置路徑 `0x4A8A60→0x823850` 清 map、或 `0x4B7D50` 已撤換 Tutorial owner，原來的 thread/Map 世代就不再保證與舊通知相容。

**限制**：尚未完整枚舉所有其他 writer/alias、分派對 stale packet 的 scene owner gate、佇列及重登 callback。最精確的可證說法是「這個 handler 對此 key 無條件寫1」，不是「每個舊封包都可送達當前 Map」。

### 4.2 一般 0022：重送可走 scene replacement，有副作用

`0x4B9770` 對合法 type0 不在入口自檢一個 Server transaction/epoch；直接配置 `0x6104` 的 `CScenarioDecision`，呼叫 `0x4B7D50`。其原生行為：
```asm
4B7D5F mov ecx,[esi+0x5EAC]   ; 舊場景
4B7D69 mov eax,[ecx]
4B7D6B mov edx,[eax+0x14]
4B7D6E call edx                ; old scene +14
4B7D7E push 1
4B7D80 call edx                ; old scene dtor/virtual0
4B7D82 mov dword ptr [esi+0x5EAC],0
4B7DA7 mov [esi+0x5EAC],edi  ; new scene
4B7DB2 mov eax,[edi]
4B7DB4 mov edx,[eax+0x10]    ; new init
```
`0x4C43B0` 另清理過場/checkpoint，結果演出 `0x4BA8C0` 可重建 EmptyController、切背景。故相同結果封包重複在已安裝／路由仍可達時有**場景生命週期副作用**，不能只把 UI 上的值覆蓋看作無害冪等。**是否實際可重發、Client 是否拒絕舊世代包**須查上游 T02 framing/owner/queue；不能由本函式否定所有防重。

### 4.3 0033：結果頁的返回請求不等於自行完成、重試或回村

`0x6BA2C0` 對指定 UI Click `0x578` 且目標 widget 匹配後，讀 resultStore `+0x29` 送內部 `F431F`；`0x5AAE80`：
- `F431F` 事件的 `+0x14 != 0` → 關閉當前視窗，`0x6BF310` 角色說明，`0x596E00` 顯示另一視窗；**沒有直接送0033**。
- `+0x14 == 0` → 在 `FBA798==0` 時組 2-byte `C2S0033`，有 virtual socket send。
- 角色說明頁的 `0x6BF2A0` 還有特殊的 mode1 確認分支，走 `g_TutoEmployCharQuery` Lua global 等本地 UI 流程；**不是所有確認都發0033**；其他模式下 `0x4A38D0` 可送0033。

```asm
6BA2E6 cmp dword ptr [edx+0x10],0x578
6BA336 movzx ecx,byte ptr [esi+0x29]
5AAEA9 cmp dword ptr [edi+0x10],0xF431F
5AAEB2 cmp dword ptr [edi+0x14],0
5AAED2 call 0x6BF310            ; 非0角色詳情
5AAF0A cmp dword ptr [0xFBA798],0
5AAF11 mov edx,0x33
5AAF27 push 2
6BF2C5 cmp dword ptr [eax+0x5F4C],1
6BF2D5 call 0x6BFAE0            ; 特定 mode1 不走0033
6BF2FA call 0x4A38D0            ; 另一分支的0033 builder
```

0033 **沒有 destination Town/Map、Quest ID 或 retry flag** 的已證業務本體。Server 應先以自己目前的「等待結果返回」階段檢查它（相容 Server 的安全設計要求，不冒稱原版內部算法）；新的城鎮/廣場安裝、位置及角色可控制狀態需要 T07/T08 的**另外訊息與控制器建立**。重試、跳過結果、角色確認等情境不得只用「收到任意0033」一條規則混合。

## 5. 有限原生 XREF 掃描：用途與不能推論的事

為防止把 «只查了一個 handler» 偷換成 «全程式唯一 writer»，本輪以真正的 BIN `.text` bytes 掃 little-endian **直接 4-byte immediate**；只當**定向候選索引**，不是具有指令邊界驗證的所有 xrefs：

| 直接 literal | 命中筆數 | 指定命中地址摘要 | 說明 |
| --- | ---: | --- | --- |
| `0xFC0F88` Tutorial completed-map | 3 | `47B0A3, 47B0BB, 4C4F7D` | 前兩筆可能處理容器生命週期，後者落在 004C writer immediate；別名／間接呼叫都不在 literal 掃描內 |
| `0xFE18F8` result storage ptr | 14 | `4B359B, 4B3606, 4B3661, 4B36B9, 4B36E0, 4C45D6, 506E4B, 508292, 508492, 6BA2FF, 6BA4B8, 6BC0F7, 6BC8F5, 6BC9BD` | 已針對 4C4550 writer、6BA2C0/6BA400 reader 確認。**其餘候選不表示已審所有結果統計、排行、獎勵消費者**；WP05 應追完 |
| `0xF4297` | 2 | `4C4630, 5AAE63` | 符合結果事件發送與 UI 接收；**單值 bytes 也可能在 data 中碰巧出現** |
| `0xF431F` | 3 | `4A992B, 5AAEAC, 6BA33C` | 結果按鍵/分派候選；本輪部分已用 CFG 指令確認 |

**禁止**將零命中、partial xref 或上述 14 命中量當作「不存在其他 consumer/Server 報告」、「所有 writer 唯一」的證據。接續應由 caller/CFG/虛擬表或資料流追索，而非堆命中數。

## 6. 狀態遷移候選與遊玩影響（已知 Client vs Server 設計）

### 已見 Client 事件的必要流程（非官方完整傳輸序列）

| 階段／入口 | 已見本地狀態 | 不可推定 |
| --- | --- | --- |
| 教學開始 `C2S0040` sender | 組4-byte scenario request，本地 map 沒在該函式 reset | Server 接受、怪物生成成功或立刻回 004C |
| 教學 `S2C004C` handler | 本地 map[key]=1；有效 Lua 讀 map，受 TUTO owner/世代影響 | 全部任務/獎勵、Quest16/15 結算、Server 成功公式 |
| Scenario場景 | `S2C005F` 等可建立新場景、Reset/ready 有前置約束 | Scene ready＝擊殺/通關；重建後仍是同一 Lua coroutine |
| 一般 `S2C0022/type0` | Scene Decision + result storage + UI state8，前場景被撤換 | 顯示結果是 Client 本地判勝、Server 一定已持久化 |
| 結果 UI `C2S0033` | 特定按鈕分支、2-byte 返回請求 | 本體含 Town/Map／重試／領獎確認，或發完即能自由移動 |

### 對相容 Server 提出的**設計候選**（不是原生規則）

1. 區分 `scenario_generation`、`current_scene_kind` 與 `result_transaction_id` 作 Server 自己的狀態/去重，避免在初始化清 map 後將舊完成訊息用於新流程。**這是需要 S00 ADR 的方案，不是已證原版封包含這些欄位**。
2. Server 自行掌握經授權的達標來源、死亡、超時、放棄及可提交結果條件；Client 尚未證明的必要 wire/UI 須回 T14/T02 逆向，不可直接補包。
3. 顯示結果/領取獎勵/返回分開：`0022` 只證結果畫面建立，`0033` 只證返回請求；發獎與持久化需要另由 T15/S00 定義交易策略，避免因重複送結果而重發獎勵。
4. 正式 RR/SPEC/GAP/TEST 應由 S00 按唯一台帳整合；本次不自行改主線、其他 Task README 或 RR 状態。

## 7. WP03 四子項的實際完成度與剩餘 Client 補證

| WP03 子項 | 本批經第一手 BIN 證實/交叉來源的範圍 | **研究結案狀態** |
| --- | --- | --- |
| 03-01 勝敗 writer/reader | 0022[type0..7] 的場景入口、type0 的 `resultStore+24/+28/+2C/+30/+34`、zero/nonzero UI consumer `6BA400`、TUTO 004C map/reader | **有界完成**：本地結果 reader/writer 明確；官方勝敗 enum、所有其他 result modes consumer **尚未完成** |
| 03-02 清怪 vs 完成 | 004C handler 不計怪數，0022 另有結果場景，具體事件偏序及各場景 owner/reset 適用條件 | **部分完成**：T08/T12 擊殺/死亡→關卡勝敗的完整生產者—消費者鏈 **尚未閉合** |
| 03-03 失敗/超時/死亡/中止 | 0022 +2 為結果場景 type，+4 是結果 UI 顯示分支；parser error→0019 不算失敗；MissionDecision另有區分 | **部分完成**：正式死亡/失敗/timeout/abort/retry builders、原因欄位與對應 UI **尚未閉合** |
| 03-04 重複/重入 | 004C map 重寫1 vs init clear，0022 scene replacement，有別於結果 UI 的 0033 條件 send；重入潛在副作用已可證 | **有界完成**：局部 lifecycle/風險；全局 queue／stale-packet gate、跨世代交易、重登恢復仍未知 |

**請勿將此項報告的「四小項已研究、技術原稿已提交」描述為「WP03 的所有官方勝負規則已完整驗證」**。本輪核心結果是把結果場景類型、結果 UI 分支、教學旗標與錯誤路徑分開，並把尚未解的死亡/超時/放棄 producer 精確列明。

### 可接續的具體 Client 入口（續 WP03 未解或 WP04/05）

- **優先 Client（WP03 未閉合）**：從 T12 原生 HP/death/party defeat writer、T08 entity death/erase consumer 往回/往下追到 S2C sender/Client goal，確認 `0022` +4 的值來源及完整例外分支；別以「原版 Server 未公開」阻塞仍能做的 Client 靜態路線。
- **一般 Scenario fail/abort/retry**：`0x4C4550`、`0x6BA400`、`0x5AAE80`、`0x6BF2A0` 及 ScenarioField 按鍵分派，尋找與結果 UI 不同的戰鬥中離場/放棄 C2S sender；如找到有直接位址的 native handler，新增完整 CFG/關聯證據。
- **其他結果子類**：`0x4BC460`（Mission Decision）、`0x4BD590`（Duel）、`0x4C4FB0`（Raid）、`0x4C0610`（GvG）等的 +38 virtual handler，以及 type0 以外 payload。不要直接複用 type0「最少22bytes」。
- **Server/跨整合**：T02 frame/dispatch/重放，T07 scene/exit，T15 保存；S00 决定合理重入/去重/放棄政策，待原版 Client 遊玩驗收。
- **WP04**：重點分析真正的 C2S/ S2C 結果/確認交互、上下文和時序；不要預設 C2S 0033 是領獎，也不要視 0019 是輸包失敗或玩家失敗的固定枚舉。

## 8. 驗證重播與來源收據

可在任意平台上拿**同 SHA 的原始 BIN**及本包 `verify_wp03_native.py`、`native-window-audit.json` 執行：
```bash
python verify_wp03_native.py /path/to/Tartaros.bin
```
本次執行結果：`PASS; SHA256=9741d...; 64 bounded windows; 8 switch entries`。驗證腳本只讀原件，驗證的原生 bytes 與 jump-table 指標，不執行或修改 Client；**不驗證任何原版 Server 封包時間、UI runtime、重送實際效果或完整子類函式語意**。

GitHub 來源（報告來源不能取代二進位檢驗）：
- [WP02 原稿](https://github.com/we88ec3-prog/ttr_anal_multi/blob/bbecb1861556ab823e00c62193371f4adbae4b2f/kr-temp-roy/T14/WP02-20261031/T14-WP02-OBJECTIVES-EVENTS-PROGRESS-NATIVE.md)。
- [T14 Scenario14 舊稿原始封存](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/1d78642bfec7b5005988a1c2121404a3daadd2f62ba1e0068f8918b314b1ae99.txt)。
- [T07 Scenario 結果及返回](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/00c7ff83c85dd8f01e882d82bf2d83fcf6eed2788d3fd60dbd69682b2764d977.txt)。
- [T01 map getter/reset 唯一 FULL-PASS 限定](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/verified-knowledge/client-scenario-map-native-reader-and-clear.md)。
- [T01 20261027-04 更正](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/integrations/T01-20261027-04/resolutions.json)、[20261028-06 更正](https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/integrations/T01-20261028-06/resolutions.json)。
