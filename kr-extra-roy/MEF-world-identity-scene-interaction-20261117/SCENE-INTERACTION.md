# 場景與互動：field、map、世界物件、point、ready 的完整分層契約

本稿承接 [總報告](REPORT.md) 與 [世界身分](WORLD-IDENTITY-EVENTS.md)。原始 KR BIN、資源與固定來源見 [source-manifest.json](source-manifest.json)。此處「完整」指所選正常路徑從入口到具體資料消費與退出條件，不是官方 Server 時序、所有 map 或所有 MEF 功能已還原。

## 1. 最重要的結論：五種「換圖」不是同一個動作

| 動作 | 實際 owner／效果 | 不能省略的其他部分 |
|---|---|---|
| S2C 005F | 更換 current field 的類別、controller kind 與 UI page | 不保證清 qco、world tree、所有 point／資源，也不是一個含完整場景快照的資料包 |
| S2C 0012 | 先清 point、reset controller，再用 u32 mapKey 呼 world map loader | 同 MapID 也先清上述資料；不保證完整世界清空、所有依賴成功、所有操作恢復 |
| `lb.ChangeMap(mapKey)` | 直接呼同一個 world map loader `4DF510` | 沒有 0012 的 point/controller 前置，不能直接當完全等效的替代 |
| `Q.LoadMap(path)`／`RestoreMap()` | 演出用視覺地圖與單份 camera/map backup | 不更新同一份 world mapKey／BOUND／minimap／actors／points，不是普通轉場的完整 rollback |
| `lb.LoadMinimap(mapKey)` | 按 BOUND 查 descriptor／texture／symbols，操作既有 UI 元件 | 不安裝 field、不建 world actor、不卡控 point 合法位置 |

這五個層次與 loading、Q input wait 又互相獨立。正確整合必須明定自己在改哪一層，而非「畫面已變」就判全部成功。

## 2. 005F：field 物件安裝先於新 controller/page 初始化

此鏈直接復用 [既有 scene-cancellation](../MEF-complete-flow-20261115/scene-cancellation/report.md)；不重新掃所有場景類型。

`005F → 4B99C0` 先更新 GameInfo mode、建立新 field，再由 `4B7D50` 呼舊 field `v+14` exit、`v+0(1)` deleting destructor，清舊 pointer，於 `4B7DA7` 安裝新 field，`4B7DBC` 才呼新 `v+10` init。

所核普通配對：
- subtype2：CScenarioField／vtable C073B4，controller kind3 Formation，UI state7。
- subtype4：CMissionField／vtable C0705C，controller kind2 Single，UI state5。

同 kind 可以 reset/reuse controller，不同 kind 才另走建立／釋放。Scenario exit 的直接 target 是空函式；兩個 field 的 deleting destructor `4C5940` 本身不關共用 Lua VM。Mission exit 有其他集合及動態 callback，不能把「沒有 direct Q Stop」擴張成所有 indirect 路徑絕無作用。

**可用結論是 005F 本身不提供舊 qco 已取消的保證。** 相容 Server 必須先安排自己的 run 結束政策，避免舊腳本於新 field 下繼續操作同名 key。UI `F4355` 只是另一套 queue，不能當取消或 ready ACK。

## 3. 0012 與 lb.ChangeMap：同一 loader，不同前置

本輪完整核對 handler `4B24F0..4B2566`：

```text
S2C0012
  → 5449A0 清共用 checkpoint 集合
  → 544F50 reset 當前 controller
  → 從 application+2 讀 DWORD mapKey
  → 40F060 取得 world owner
  → 4DF510(world, mapKey)
  → return 0x100
```

view 至少須有6個 bytes；這是 handler 的欄位存取下限，不是官方 pcap 宣稱。正常前提包括有效 controller、world 與相容資源。`544F50` 重設三槽及部分欄位／時間；不表示清除所有 owner、busy 或 input mask。

`lb.ChangeMap → 4A0AC0` 則直接以整數參數呼 `4DF510`，沒有先呼上述兩個清理。這不是「名字相同但大概差不多」：在同 MapID 分支中，差異會直接保留下來。

### 3.1 同 MapID 的精確反例

`4DF53E` 比較 `W+48` 與 incoming mapKey，相同直接跳 `4DFA13` 的音樂處理，**不走 graphics／BOUND／minimap 載入段**。但 0012 的 point clear/controller reset 已經在此之前完成。

所以重送同 MapID 的 0012：
- 已清掉原 points 與控制槽；
- 不重新載入這次的 map/bounds/minimap；
- 不保證修復先前資源載入失敗；
- 仍需按權威快照重發 points／適當重綁。

`lb.ChangeMap` 在同 ID 時則沒有那兩個前置清理。**兩者不能互換作為完整 reset。**

上述是 native 呼叫順序的靜態推導，並非已觀察玩家掉點或卡住的實機結果。

## 4. 4DF510：MapKey、TRIGGER、MAP、BOUND 各自如何消費

`W=&FAB130`，current mapKey 在 `W+48=FAB178`。不同 ID 時，`4DF54E` 先寫 current key，再進入資源工作；因此讀到新 key 不代表資源已成功。

| 資料 | 本輪原件的 reader 與 consumer |
|---|---|
| TRIGGER | `4DF585` receiver FB74C0，`4DF58D → 4F7DF0`。該返回值沒有在這段接到已識別 file/Lua loader；不能因查到 `.mef` 名稱就稱首次執行已還原。 |
| MAP | `4DF622` receiver FB74B0，`4DF62A → 4F7DF0`；依另外的資料前後綴組成資源名，與 W+4C cache 比較，必要時 `4DF787 → 7C1E00`。 |
| BOUND | `4DF9B4` 以 FB74D0 查名稱，`4DF9C7 → 4DF1A0`；組 `Map/BoundMap/<name>.bnd` 交既有 loader。 |
| Minimap | `4DF9FA → 56CD10`，以既有元件 FDF3C4 及 mapKey 選 BOUND 對應 `.mmt`／符號；不是重新建一個任意 minimap 元件。 |
| Music | 同 MapID early branch與正常尾端都能到音樂操作；音樂開始不代表場景全部 ready。 |

`7C1E00` 會以圖形 basename 組 `.fld`，選定原生載入物件；本輪只核到指定可讀窗口及有關來源，不把此函式所有異步工作與任意資源成功一起升格完成。不同 mapKey 但同 basename 的 graphics cache，與「完全相同 mapKey」的 early branch 亦不同；前者後續仍可走 BOUND/minimap。

底層 archive 的虛擬 member 路徑例如 `BoundMap/...`，呼叫字串帶 `Map/BoundMap/...` 屬資源選路問題；不能把字串前綴不同直接當成檔案缺失。原始資源選路／優先序沿用既有研究，本輪不修改或重新打包 STP。

## 5. Q.LoadMap／RestoreMap 的「還原」到底還原哪一層

### 5.1 LoadMap 是視覺切換與單份備份

`563C40` 的輸入是路徑字串。`563CC9..563CE3` 複製相機資料的 **11個DWORD** 到 M+30 指向的備份；`563D34` 將 world current mapKey 保存到 M+34。處理檔名後 `563D45 → 7C1E00(flag0)`。

此函式沒有呼 `4DF510`。因此不能把它當成 0012 或 lb.ChangeMap 的相同動作；BOUND、minimap、points、世界實體與 current mapKey 不是這個備份中的完整快照。

### 5.2 RestoreMap 不回寫 world current mapKey

`563FA0` 依保存的 M+34 查 map 資源並處理相關音樂；在重新載圖前，`56434D..564353` 又將 **當時 W+48** 寫入 M+34，然後 `56435C → 7C1E00(flag0)`，再恢復 camera backup。

這證明：
- 只有一份 mapKey／camera backup，沒有這裡可用的巢狀 map stack。
- Restore 不把舊 mapKey 寫回 W+48。
- 若中間另發生普通 map change，重複 Restore 的備份語義可能變化；不能盲目重試當作可逆交易。
- 「視覺回到原圖」不是 actors、控制關聯、collision、minimap、points、Server 節點全部回復。

原正常 `Q.End` 與 active Stop 也有不同清理條件；先 End 再 Stop 不是補救所有資源的通用手段。A 類最小內容仍應避免不需要的 Q map 操作。

## 6. Loading bracket、ready、Q wait：三條不同鏈

### 6.1 0023／0024 是前端 loading 狀態

完整前端 initializer `493170` 的已查 stores：
- `[C+438]=494860`，index `(438−208)/16 = 0x23`。
- `[C+448]=494A90`，index `0x24`。

`494860` 在 `49488C` 設 `C+BFD4=1`。`494A90` 在 `494BE2` 清為0，再呼原 native 後續；其中 `4E0590` 本輪核定是**待用音樂的處理**，不是世界 ID 或 actor ready ACK。

`4930E0` 前端 callback 在 handler 返回 `0x100` 且 loading flag非零時，選另一返回結果供上游消費。這屬訊息消費排程，不是 Server 收到「地圖已完整成功」；勿把 handler return 值當 wire 回覆。

### 6.2 0014 經 field 虛函式落到共同 ready

原件 table／vtable 接點已閉合：
- common primary `field+A4=4C5930`，opcode `(A4−4)/8=0x14`。
- Mission／Scenario secondary `field+5F4C=4C5930`，同樣是0x14。
- `4C5930` tail-call current field `v+2C`。
- Scenario：`v+2C=4C4910 → 4B2570`。
- Mission：`v+2C=4230F0 → 4B2570`，另有 F4262 UI 事件。
- `4B259D` 先設 current controller+4=1。
- `4B25CE` 檢查 Q active；只有 inactive 才於 `4B25FA` 清 `FB8830` 的 **mask0x1**。

這些選定 handler 不讀額外 body，故在已證正常分派下2-byte opcode足以提供其欄位需求；不把它寫成任何不完整 context 都安全的命令。

### 6.3 不能與 Q 的 00EB 混用

| 行為 | 有關狀態 | 不會順帶處理 |
|---|---|---|
| 0023／0024 | CClient loading欄位與前端處理條件 | 不等於 controller有可用actor，不是 point snapshot ACK |
| 0014 | controller+4、Q inactive時清mask1 | 不清mask2、不停止Q、不清qco、不清controller+58 |
| 00EB | 原生Q等待對話／mask2解除 | 不建actor、不清loading欄、不設完整field ready、不撤銷Q active |
| Q End | Q active及條件式003F／等待／cleanup | 不保證所有input owner和native效果已恢復 |

mask1、mask2、其他UI mask與controller+58都分開保存。本輪沒有宣稱已找全所有輸入 mask writer；只證明表中consumer不是互相替代。Server 不能只送「某個ready」就把整場景標可玩，也不能用固定毫秒 delay 假設這些前置均已完成。

## 7. 互動點的正向鏈與地圖代數

既有 0027、0048 與 Lua setter 直接復用，並以本輪 `point_clear`、`point_lookup_setter`、`point_set_status`、`checkpoint_delta_packet` 重核其接點：

```text
正確場景／點資料
  → 0027 全量安裝 (category,key,enabled,XY,radius,mode,tail)
  → 0048 或正式 Lua SetCheckPointStatus
  → 第一個相符 point 的 status 與類別專屬視覺
  → 距離／輸入／候選／page gate
  → 原 NPC／Shop／Tutorial／出口分支
  → 必要時原 C2S 意圖 → Server 權威處理
```

主要契約：
- 0027 是全量替換，不是單點新增；0012也會清此集合。
- 0048／Lua setter不新增missing點，也不改位置。
- 先delta後snapshot，前者可能無效或被覆寫。
- `(category,key)` 重複時只改第一筆，內容工具應拒絕。
- 001C是部分fallback的意圖，格式只含category/key；不是所有NPC／Shop都必經，也沒有目標map／run generation。
- 同數值key在新地圖出現時，舊delta仍可能命中；native格式沒有場景代數。後端要在自己的發送佇列／session狀態擋掉過期操作，不能擅自添加Client不讀的token。

一次開門不等於完成轉場。Server仍須核對出口合法性、對應目的地、角色／points快照、通關與持久化；這是開發需求，不是要MEF自行判定全部戰鬥。

## 8. 有來源的 Field19 例子與資料界線

本輪只讀 Table/Event 的索引與四個選定member，不做全量資源解包。

| typed key | 原表選定屬性 |
|---|---|
| Map182 | MAP=town001D；BOUND=town001；TRIGGER=town001.mef |
| Map191 | MAP=scenario_pathofpindus01D；BOUND=scenario_pathofpindus01；TRIGGER=S_pathofpindus01.mef |
| Map192 | MAP=scenario_pathofpindus02D；BOUND=scenario_pathofpindus02；TRIGGER=S_pathofpindus02.mef |
| Case103 | STAGE=19；MAPFLOW=CHART_S_pathofpindus_01.xml；CLUSTER=CLUST_S_pathofpindus_01.xml |

前稿 [W2-FIELD19-RESULT-01.json](../W2-FIELD19-RESULT-01.json) 已記 node1/2→Map191/192；這項關係本輪**復用**，沒有從完整 graph 重新推得。附帶 Table/Event 索引中未找到那兩個 exact chart/cluster filename，不等於所有 Client 資源都缺失。已找到兩份scenario BND並固定hash，**沒有在本輪重新求合法出生座標或證明portal key**。

所以可以交付有來源的 map資源選路與排序規格；不能以Quest15、Field19、Case103、Map191碰巧相關，就把它們混用為同一數字ID。實際出口→目的地→出生點的最後資料綁定，應回用W2/W3原始圖表與bounds證據；尚未取得的精確carrier與合法值保留待綁定，而不是要求猜值。

## 9. 可實作的順序是偏序，不冒充官方固定封包序列

以下是相容Server設計，原件僅支持其必要依賴：

1. 選定合法field/controller/page與資源版本，處理當前Q run及共享owner。
2. 決定舊world實體的保留／移除政策；不要假設0012或005F必定已清全世界。
3. 需要普通map載入時，先完成0012；之後才重建本場景point與所需控制關聯。
4. world actor須在S2C000A引用前存在，relation record也須存在；點須在0048／Lua setter前存在。
5. 按合法phase使用loading bracket及0014，另行處理Q End／00EB；不以任一handler回值冒充全部ACK。
6. Server以自己的instance與權威資料接續服務／通關／保存，實機驗收畫面、操控與狀態。

0038等其他流程封包與角色資料發布不因本輪省略重做而失效；本稿不捏造全新官方seq。正常流程驗收、尚未綁定的真實資料、以及精確Client未知分列 [SERVER-HANDOFF.md](SERVER-HANDOFF.md) 與 [NEXT-ANALYSIS.md](NEXT-ANALYSIS.md)。
