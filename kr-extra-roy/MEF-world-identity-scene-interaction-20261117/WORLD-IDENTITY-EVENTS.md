# 世界身分與事件：建立、重綁、狀態、移除及腳本可用邊界

本稿與 [總報告](REPORT.md)、[場景與互動](SCENE-INTERACTION.md) 組成同一交付。原件為 KR BIN `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；來源固定於 [source-manifest.json](source-manifest.json)。以下函式名稱是功能標記，不是原始符號；VA 僅適用此版本。已證舊結論直接復用；本輪新增或精化的內容主要在 §3–5、§8。

## 1. 研究終點與本輪完成程度

目標是讓開發者判斷「腳本操作的是哪個世界物件、它由誰建立、後續封包如何命中、何時真的被移除、哪一類結果可被 Lua 觀察」。不要求腳本自行實作所有戰鬥。

**已閉合的有界 native 鏈**是世界樹、網路／本地建立的身分差異、已知後續操作、S2C 000A 控制關聯、000C 死亡狀態與 001A 移除、受限 Lua 世界刪除的參數投影及不同的控制器清理前置。**尚未閉合**的是普通世界死亡／群清資訊寫入可供 Lua 使用的 typed 事件或 getter，以及本地 Create 的可靠身分回報。不能將本稿稱為「MEF 已接管普通生怪與清場」。

## 2. 六個身分域，禁止靠數值相同互換

| 身分域 | 實際 owner／欄位 | 合法用法與限制 |
|---|---|---|
| world EntityId | `W=&FAB130`，樹 `W+8=FAB138`；node+10 是 actor；actor+4 是 WORD ID | 0007、000C、001A 等 lookup。低 byte 參與 native factory／處理分支，並非任意流水號。 |
| 本地 lb 配號 | `F7DE04` DWORD counter，建立時取低 WORD | 原始值 1001；沒有把本次新 ID push 回 Lua，也沒有已證 Server 配對 ACK。 |
| Q 演出 slot | `M=&FB73C0` 的另一棵樹 `M+1C` | CEventActor；正式 slot DWORD、預掃描 low WORD、actor 內還有 low BYTE 投影。不是 world EntityId。 |
| checkpoint | 共用 manager `FB79F0`；point+F4 category、+F6 key | 由 `(category,key)` 唯一配對；category 2 是 ShopNo、3 是 NPC 的既有資料關係。 |
| S2C 000A 關聯鍵 | `W+18` 的另一個 map；來包 DWORD+2 | 本稿稱 relationKey，只表示此 handler 的實際查找域；不能改稱副本怪物波次／群組。 |
| Server instance／generation | 相容服自己的狀態與排程設計 | 原有訊息及本輪 Lua API 未提供該欄；不得寫成已存在於 wire 的 token。 |

前三項沿用 [既有 world identity](../MEF-world-integration-20261115/identity/report.md) 與 [Q actor](../MEF-content-contracts-20261116/actors/report.md)，必要交點本輪核回 BIN。checkpoint 細節見另一分題。`world_accessor` 與 `world_erase` 原件可核出 W、tree 和 pointer；所有窗口 ID 在 [native-evidence.json](native-evidence.json)。

## 3. 建立後是否真的可以由 Server 命中

### 3.1 網路建立：0007 是 miss-create，不是 upsert

復用已證 `4AE4D0`：handler view 為 2-byte opcode 後 N×26-byte row，先查 row 的 u16 ID。key 已存在便整列跳過，**在比對 model／覆寫 metadata 之前**就離開該列。這不構成採用本地物件、校正模型或成功 ACK。

miss 時按 ID low byte 分派：0→角色 factory、1→CMonster、6→NPC、7→另一類 actor；其餘已查分支走錯誤路徑。這只是該 producer 的條件，不宣稱完整官方 ID 分配規則。後端新增實體必須符合實際型別，還要保留 instance 層級的生命週期。來源：[舊 identity §5](../MEF-world-integration-20261115/identity/report.md)。

### 3.2 本地建立：進同一世界樹，不代表已同步

`lb.CreateObjectEx → 4A0F70` 使用本地計數器配置 actor 身分，之後經 `4DFF30` 插入世界樹。可使用同一索引的後續位置／控制 writer，仍以「Server 已用合法方法確知正確唯一 ID」為前提，不能略過此缺邊。

本輪重新核到 `4A104F..4A1063` 的 counter read 與 `4A11AF..4A11C1` 的遞增；原始 `F7DE04=1001`。有界 literal 掃描僅找固定絕對地址，不涵蓋計算 alias 或執行期修改，因此不能證明 counter 永不被其他路徑重設。計數低 WORD 會截斷，也不能靠「預計第幾隻」維持共享 ID。

唯一鍵碰撞時 `4DFF30` 不取代舊索引；caller 仍能遞增 counter，attach 支線亦可能接到新 pointer。於是「世界樹選到的 A」與「控制器持有的 B」不能僅因 ID 數字相同就視為同一物件。前稿已證此風險，本輪不重算為新發現。

### 3.3 後續操作必須保持 typed lookup

已證 0001／0016 的位置路徑、000B 控制資料、000C state 及 001A erase 都以 world ID lookup 為基礎；它們不因此變成任意型別通用操作。例如 001A 的 low-byte 2/8/9 前置會讀另一類布局，不能把任意本地 CMonster 流水號拿去套用。

內容能較早採用的路線是：**由 Server 按既有流程建立並持有可靠世界 ID，僅把已證的本地外觀／表現操作交腳本**。這是相容設計選項，不是本輪已部署的實體生成方案。

## 4. S2C 000A：控制關聯的精確資料依賴

本輪新增核對 `s2c000a_binding=4AF920..4AFAE5` 與 common registration。注意：這是 **S2C 000A 關聯資料**，不是 C2S 000A 玩家輸入列；opcode 相同不代表方向與格式相同。

| handler view offset | 讀取型別 | 有界意義 |
|---:|---|---|
| +0 | u16 | application opcode |
| +2 | u32 | relationKey，先查 W+18 的既有 record |
| +6 | signed i8 | row count；正數才迭代 |
| +7+4*i | u16 | 要查世界樹的 actor ID |
| +9+4*i | u16 | 關聯 ID；與前者比較後選控制器方法 |

正數 N 的讀取形狀是 `7+4*N` bytes；這不是底層 TCP frame 規格。0..127 僅是非負 signed-byte 編碼範圍，不代表各 controller 可容納127個角色。容量、角色類型及正式資料政策須另依原契約限制，不能用 native 缺 guard 擴充玩法。

原件順序：

1. `4AF920` 先以 relationKey 查 W+18；missing 回 `80004005`，沒有為未來 record 排隊。
2. relationKey 等於 GameInfo+5F50 時，`4AF98E..4AF9A6` 先呼 current controller 的 `v+14` 清理，再呼 `v+C`。
3. 每 row 先查 world actor，miss／null 警告後跳過，不保存晚到事件。
4. 兩個 row ID 不同且屬本機關聯時，呼 `v+8(關聯ID, actor*)`；否則走一般 attach 分支。
5. 一般分支第一列另寫 leader metadata，actor+98 表示此分支的首列狀態；actor+9C 寫 relation record 的 key。符合本機關聯時，呼 `v+4(actor*)`。
6. 尾端本機關聯呼 `v+10`；handler 正常回 `0x100`。

**可直接落到 Server 的必要順序**：關聯 record 已存在 → actor 已建立 → 000A 綁定。反過來先發 000A 再生 actor，不會由後到的 actor 自動補播這次 binding。不能用收到封包的順序猜角色現在必定已受控，也不能把 relationKey 當敵群存活集合。

本輪沒有追盡所有 relation record producer，也沒有由這個欄位證明普通怪物仇恨、隊伍分寶或群清規則；下一條缺邊列在 [NEXT-ANALYSIS.md](NEXT-ANALYSIS.md)。

## 5. `Tutorial.DeleteObject`：新增可用範圍與不可忽略的差異

### 5.1 不是任意 EntityId，也不只硬編碼固定角色

正常 binding 為 `4AB580 → FE1868=4A9FE0 → closure 4AC7D0 → converter 4ACB70`。原件 `4AA009` 讀整數參數的低 BYTE，`4AA00E` 清一個 WORD，`4AA013` 把該 BYTE 放到 WORD 高位，`4AA01C` 再寫低位0。形成：

```text
targetWorldId = (numericArgument & 0xff) << 8
```

之後 `4AA04C..4AA057` 交給同一 `W=&FAB130` 的 `4DFBC0`。**此 native 本體沒有檢查 current controller 必須是 Tutorial kind4**；命名空間並不等於所有方法都受相同 controller 限制。完整入口仍需要正式 VM、有效 World/controller 及合法 A 類 caller。

例子只用來說明整數投影，不是部署鍵：
- 參數240 → ID `0xF000`。
- 參數496也投影為 `0xF000`。
- 直接傳 `0xF000` → ID `0x0000`，不是原本想刪的 ID。
- 不存在能由此公式得到 low-byte 1 的普通 monster ID。

因此可採用的是**低 byte 為0、來源已知的世界 ID 的受限刪除入口**，不能當任意怪物／NPC 刪除器。原版固定角色的使用只是其中一個用例，不是本體寫死的唯一常數。

converter 呼 native 後清 EAX，沒有 push 一個新的成功／ID 值。外層 C closure 的返回數量不是刪除成功 ACK。caller 必須事前確保身分、布局及 owner，不能靠假定 bool 返回作安全檢查。

### 5.2 Lua 直接刪除與 001A，不具相同控制器前置

這是本輪最重要的生命週期精化：

| 路徑 | 進入 `4DFBC0` 之前的實際工作 |
|---|---|
| S2C 001A → `4B28D0` | 除型別前置外，`4B2A56..4B2A89` 比對 controller 三槽 ID；命中任何一槽便呼 `v+14`。所核 Single／Formation 方法會清整個三槽集合，不是只拔目標一槽。 |
| Lua `Tutorial.DeleteObject` | 投影 key 後直接呼 `4DFBC0`；沒有同一段 ID 比對／`v+14` 預先清理。 |
| `4DFBC0` 本身 | 在 `4DFBE2..4DFBF6` 呼三次 `v+1C(index)`，但忽略回值；所核 `545290` 是 getter，不能把這三次呼叫說成控制器解綁。 |

下游 actor cleanup／destructor 可能另有型別專屬作用，本稿不宣稱已排除所有間接引用釋放，也不宣稱實機必然留下 dangling pointer。可成立的結論是：**本輪證據不提供 Lua 刪除與 001A 相同的 controller 清理契約**。相容內容應限於未被控制器持有、身分及型別均已知的目標，或先補一條已證的解綁路徑。

001A 清整槽還意味著：刪除其中一個受控 actor 後，仍存活的其他 actor 可能需要依合法流程重新綁定；不能只以「其他 world key 仍存在」推定操作會自動恢復。這是 Server 的資料與排序需求，不是要求修改 Client。

## 6. 死亡狀態不等於移除，也不等於 Lua 事件

復用並在 `state_packet`、`fsm_transition`、`monster_ctor`、`state_dead_enter/update` 重核：

```text
S2C 000C: opcode + N*(u16 EntityId, i8 state)
  → 4B0130 world lookup
  → actor+F0 secondary FSM v+8
  → CMonster target 4CA060
  → existing state3 CDeadState
  → enter / native update / visual fade
```

`4CA060` 未以「new state == current state」去重。重複 state3 會再次 exit／enter，重設 timer／效果。死亡計數不能將每次 enter 都算成新死亡。死亡顯示的 update 不等於呼 world erase；淡出不等於 ID 已不在樹中。

本輪沒有找到這些選定 native 端點把 `(instance, EntityId, lifetime, reason)` 寫入已註冊普通 Lua observer。舊 R7 的 004C／004E、R14 Tutorial flags、Q stopped、Book／Prolog inactive 都有自己的型別與場景限制，不能挪作普通世界群清。

**精確未閉合點**：已有 world ID／state producer，但缺同一實體資料經原生保存／事件、抵達普通場景中真實 Lua getter 或 callback 的正向連接。這不是說整個 Client 絕無其他方法；範圍只限已列 normal bindings、已識別 callback 與本輪選定函式。

## 7. 移除與整體清理的實際終點

001A 的 handler view 仍是 `4+2*N`；buffer+2 的 WORD 在本題未定業務語義，不猜成count或固定0。查到 actor 後按型別前置、控制器處理，再進 world erase。

`4DFBC0`：查 world key → actor `v+14` cleanup → `v+0(1)` deleting destructor → node+10清零 → `7B6890` erase。CMonster 的具體 slot 由 `C0C9DC`、RTTI、`4D1F80`、`4D18D0` 核定，真正進 heap free，不是只打 diagnostic。這是成功且有效物件路徑，不為 null/corrupt record 宣稱安全容錯。

`4DFE90`：遍歷 world map，對每個有效 actor cleanup/delete，清 tree，再清 controller。它不是 point clear，也不清 Q tree；任意換圖都會呼此函式的全域命題**未成立**。是否使用整體清理，須按實際轉場 producer 與 actor 重用政策決定。

## 8. 可實作功能與完成狀態

| 功能 | 本輪結果 | 尚待條件 |
|---|---|---|
| 操作已知唯一 world ID 的既有角色 | typed world lookup及既有 writer已證；可做外觀等已證 API 整合 | 實際來源 ID、模型／布局、合法入口與實機驗收 |
| 本地生成普通怪並交 Server 接管 | 未完成 | Create不回 ID、typed ID collision、可靠配對；不能靠0007 hit採用 |
| 腳本刪除來源已知 low-byte0 world物件 | 參數→world erase鏈已證 | controller／其他引用前置，無成功ACK，不能擴成monster通用刪除 |
| 000C死亡呈現與001A實際移除 | 有界 native鏈已證，二者不同 | Server權威死亡、去重、群組、獎勵與保存 |
| 普通世界事件→Lua→自動下一波 | 未閉合 | 需要真正typed事件橋與可用執行上下文；不以本地顯示替代 |

以上完成狀態詳列於 [contracts.json](contracts.json)；Server需求與正常流程驗收見 [SERVER-HANDOFF.md](SERVER-HANDOFF.md)。所有推導模型只是離線檢查，不是執行原件。
