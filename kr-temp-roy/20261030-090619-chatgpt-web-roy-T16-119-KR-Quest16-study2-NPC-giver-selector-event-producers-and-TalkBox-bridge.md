# T16-119 — Quest16／②：NPC10027 玩家觸發、type2 giver selector、事件建立、TalkBox 上游（KR BIN-first）

- 作業者：`chatgpt-web roy`；原稿生成時間：`2026-10-30T09:06:19.747503+08:00`；GitHub 工作分支：`t16/roy/chatgpt-web`。
- 本篇正式段號 **T16-119**；前段 T16-118 尚未提交，與本篇一併送往 T16 工作分支（不合入 main）。
- 唯讀第一手 `Tartaros.bin`: 12,472,320 bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`Tartaros.exe`: SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。`Event.stp`: SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- 機器碼地址適用 KR PE32 `.text`，ImageBase=0x400000，Section VA=0x401000，Section raw=0x400；下方 `.text raw=VA−0x400C00`。`0xC0DBxx` XML attribute 字串位於 `.rdata`，不得用 text 的轉換公式。
- 本次基準仍是本對話首次同步結果：`main=c1e4d5e9fda28ebb0cae66996cb092780aa2c6be`，`t16/roy/chatgpt-web=8d45e99cc09b25b1744578fb9a2a4d226f78b5a8`（PR #26）；同對話不再 Merge。準備提交時另獨立核對遠端現況：最新 main 於提交前已推進到 `dbaf50a1dc1ff119e942458f79700bd18e8c7004`，T16 相對 main 可能 behind>0，此狀態**不觸發同對話自動合併**。實際上傳目標僅 T16 分支。
- 本次最新 main 的 T16 inbox 無 RR、README 未有 NEEDS_FIX/FIXING 標題。舊 RR-0005 屬 KR T02，不變更其 owner/status；不改 S00、T01 FULL-PASS、他 Task 原稿。
- 研究終點：釐清 `Quest16.giver=10027` 怎樣連到任務候選、NPC 互動 local event、選取 QuestID 的 UI、TalkBox 及後續 Q16 C→S 的**Client 可證靜態功能鏈**；動態玩家真正點 NPC、特定地圖 spawn、Server 任務裁決及回覆不屬此靜態子題可直接證實的範圍。不能用單純存在某個事件型別代替 QuestID16 具體資料流。

## 1. 執行摘要與分級

### 1.1 新增已核實（相較 T16-117/118）

**A — 釐清兩個 record selector 的原始 XML 屬性來源，而非猜測其功能。** 在 QuestInfo parser `0x504995/0x5049C7` 註冊 `giver/finisher` 字面、`0x5049F2` 註冊 `town`；數字轉換的 `EAX` 存入同一時刻 stack 臨時 record。由 `0x5048C0` record base `ESP+0x64`、`push` 造成的暫時 `ESP-4`、`0x50540D → 0x5064D0` 成員複製可推導：

| 欄位 | 原始讀取 | 接續存入（push 後） | 依穩定 ESP 換算 | record 相對欄位 | Q16 XML 已有值 |
|---|---|---|---|---|---|
| level | `0x504968` push `level` | `0x50499A` 寫 ESP+0x74（正準備讀 `giver`） | ESP+0x70 | `+0x0C` | 1 |
| giver | `0x504995` push `giver`; `0x50499E` lookup | `0x5049C7` 寫 ESP+0x90（正準備讀 `finisher`） | ESP+0x8C | **`+0x28`** | **10027** |
| finisher | `0x5049C2` push `finisher` | `0x5049F7` 寫 ESP+0x94（正準備讀 `town`） | ESP+0x90 | `+0x2C` | 10027 |
| town | `0x5049F2` push `town` | `0x504A27` 寫 ESP+0x88（正準備讀 `field`） | ESP+0x84 | **`+0x20`** | **0** |
| field | `0x504A22` push `field` | `0x504A57` 寫 ESP+0x8C（正準備讀 `subject`） | ESP+0x88 | `+0x24` | 未宣告 |

**驗算**：`0x506521..0x506530` 複製 `source+0x20/+0x24/+0x28` 到同相對 offset；`0x500485` 的 `record+0x20` 比對是 **town selector**，`0x500A53` 的 `record+0x28` 比對是 **giver selector**。當 Quest16 原件有 `town=0,giver=10027,type=2` 時，兩者各自匹配其已證值才可進入 type2 可接候選。注意 `town=0` 不等於場景已經載入。

**B — NPC 互動產生 type2 查詢的已證原生路徑。** `0x544127..0x544162` 將 `WORD [actor/control+0xF6]` 以 signed extension 作 selector，向 `0x500A80(owner=[0xFAB2A0],selector)` 詢問 Client 分類（分支/場景模態也影響輸出）。`0x5B9340` 處理 local `0x105BD` / action `0x6A7`，且其 payload `0x105BF` 時，`0x5B93FF` 的 `payload+0x14` 放在 ECX、`0xFAB2A0` 放在 EDX；`0x5B9407 call 0x5008B0` → `0x5008F3 call 0x500A00` → giver/type2 篩選後回傳首個 `WORD QuestID`（空時 0）。`0x5B9447 call 0x561760` 接收 `EDI=候選QuestID`、`push 1`，於控制器本地狀態/顯示路徑作進一步消費。**在 payload+0x14==10027、owner 正確配置、key14/town/level/exclusion 皆滿足、Q16 成為選取的首個候選時**，這條原生鏈能將 Q16 ID16 送至 Client 控制器；若同 NPC 有其他候選，`first` 不能保證必定是16。

**C — 直接定位本地事件的兩層 producer，並發現 key namespace 易混。** `0x5442CC..0x54431C` 可用控制物件 `+0xF4/+0xF6` 和當前 `EDI` 建立 vptr `0xC47BE4`、`vptr+4` 的 type return `0x105BF`，event `+0x14/+0x18/+0x1C` 分別來自其局部控制流，然後傳入 `0x5854B0` 路徑。`0x5B9850` 處理 `0x105BF` 的 `payload+0x14`，經控制器 `+0x2E8` map 反查通過才建立 vptr `0xC467AC`（type return `0x105B9`）的新 local event，其 `+0x14` **原樣複製 `0x105BF+0x14`**；`0x5B9B10` 則在 `0x105BA` 事件路徑，以 source `+0x18` 建構另一個 `0x105B9` event。兩條路徑都是**通用事件轉換**，不能僅因 type return `0x105B9` 就把它們的 `+0x14` 統稱 QuestID。`0x5B7D4B/0x5B7D59` 是已證 dispatcher callers。

**D — TalkBox 對「真 QuestID」的需求與上游接通條件。** `0x5B6C0C` 確認 type `0x105B9` 後，在 `0x5B6C6E` 讀 event `+0x14`，送進 `0x503D20` 以 **QuestInfo key** 查找；未找到則 `0x5B6D02` 不開此路徑。命中後 `0x5B6CCF..0x5B6CE4` 讀 `record+0x28`（現可證為 giver），將 `event+0x14`、mode `1`、其它 Client 物件傳給 `0x636520`；該 TalkBox 路徑 `0x636550..0x6366D6` 依 mode 取 `0x500F90` record，建立 `TalkBox+0x88` 的 QuestInfo selection。若事件 key 確為16，才有 T16-114 已證後續確認時構造 app payload `36 00 10 00` 的條件式 C→S；**`0x105B9` 的其他來源可帶 NPC ID、未必命中 QuestInfo id16。**

### 1.2 新增反證／仍有的靜態缺口

1. `0x500950` 僅篩 `QuestRecord+0x04 == 1`，不收 Q16 的 `type=2`；`0x500A00` 是 Q16 正確的 native giver/type2 reader。
2. `0x636C93..0x636CDA` TalkBox mode3 在特定情形調 `0x5007D0`，而 `0x5007D0` **先調 type1 `0x500950`，再檢查其 record 的另一個 ID vector**；因此**這一條特定 mode3 事件 producer 不能無條件用來證明 Quest16 type2 的 QID16 事件**。
3. `0x5442CC` 的 `event+0x14` 在此 native path 來自 actor/control selector，但 *actor+0xF6* 的 runtime 實際值是否真是 NPC10027、當時 EDI 在所有分支中來源是否完全一致，仍受當時物件/場景及分支限制。不同 producers 可用同一 event 類型承載不同 key。
4. `0x5B9407` 的 type2 first candidate ID 經 `0x561760` 進入控制端，但**目前尚無可逐指令證明** `0x561760` 一定會產生 `0x105B9(+0x14=16)` 事件，或直接呼叫 `0x5B6C0C`。`0x5B9850` 的 `0x105B9` producer 只複製其輸入事件的 key，不會把返回的首個 QID16 自動改寫進 `+0x14`。這是精確的 Client 靜態缺口，不可當作已閉合。
5. `0x500A80` 只回傳 Client 類別整數，存在 `[0xF9392C]` 的 `1/3/7/0x17/0x18` gate；不能當作 Server 已認可 Quest16 的 accept 狀態碼。`0x1C` 六位元組 NPC 類請求也不能當成 `0x36+QID16`。

## 2. Quest16-② 玩家路徑：有界因果圖

```text
資源 QuestInfo16: id16,type2,town0,giver10027,Demand14
  │      0x504740 parser, 0x5064D0 copy
  ▼
QuestOwner +0x5EB0 WORD key14 (由 S2C 0x74,key14，T16-116)
  │ 0x500240 比 record+0x20 town、level、exclusion、Demand14
  ▼
QuestOwner +0x5EC0 候選 WORD key16（僅其餘 gates 也通過）
  │
  ├── controller / actor `WORD [+0xF6]` → 0x544162 → 0x500A80(owner,selector)
  │     +0x500B20 global mode gate；分流 UI/互動決策
  │
  └── local 0x105BD action6A7 / payload 0x105BF
        event+0x14 = NPC/context selector（實際值視發送來源）
        0x5B93FF → 0x5B9407 0x5008B0
                → 0x500A00 type2 AND record+0x28=giver==selector
                → 首個 QID（若僅 Q16 符合則16；無則0）
              → 0x5B9447 0x561760 controller UI transition
              └─ 同 handler 另一條 independent `0x1C` app payload

另一入口 / local 0x105B9 event (多來源，+0x14 有多個 key namespace)
  → 0x5B6C0C 看 event+0x14 能否命中 QuestInfo map
     ├─ miss: 不建立 QuestInfo TalkBox 路徑
     └─ hit: 0x5B6CD7 取 record+0x28 giver
          → 0x636520 → TalkBox (依 mode 讀 record、選擇項目)
          → 0x636E10 confirm action、selected QuestInfo16 時條件式 `36 00 10 00`

**未核實的關鍵箭頭**：`0x561760 firstID16 → 0x105B9(+0x14=16) → 0x5B6C0C`。
不應拿其他 source `0x105B9(+0x14=10027)` 替代它。
```

## 3. 靜態研究過程、檢索與可重現性

- 從 T16-118 demand／record copy 出發，重建 XML 欄位到 source struct 的寫入次序；特別把 `push attribute literal` 造成 ESP 暫時下移4 bytes 納入對照，辨認 `town +0x20` 與 `giver +0x28`。與 `0x5064D0` member copy、`0x500240` 和 `0x500A00` 兩個 selector consumers 交叉驗證。
- 掃描 `.text` raw 範圍 `[0x400,0x7D0600)` 的 little-endian immediate：`0x105B9` 有90個4-byte出現位置、`0x105BF` 24個；這些是**位元組候選，不全都保證是指令邊界或 constructor**。追 `0x744AE0` (type-return function `mov eax,0x105B9; ret`) 在 `.rdata` 的 vtable `0xC467AC`，再查 constructor 写入；`0x753B60` 為 `0x105BF` type-return，vtable `0xC47BE4`。僅將經已對齊反組譯且具 CFG 的位置作證。
- 同一份 BIN 追 `0x500A80` 的四個直接 caller：`0x4D2422,0x5400A6,0x544162,0x56D09A`，其中本段沿 `0x544162` 到 actor selector、`0x5442CC` event producer；追 `0x5008B0` 的唯一已核對直接 call `0x5B9407`，並延伸 `0x561760` 的入參/狀態寫入。
- 沿 `0x5B7D4B→0x5B9850` 和 `0x5B7D59→0x5B9B10` 檢查兩個 event-source；沿 `0x5B6C0C→0x636520` 查 quest-ID lookups；以 `0x636C84→0x5007D0→0x500950` 作 type1 反證。
- 未使用原版 Client 執行、動態 hook、原版 Server 流量；沒有把 Event.stp 的 `TUTORIAL_PINKOHOUSE` 字串升格成 NPC10027 或 QuestID16 遊玩事件。

## 4. 玩家情境與原生 C→S／S→C 矩陣

| 玩家情境 | Client 本地條件、已證資料 | C→S | S→C | Client 可觀察靜態效果 | 狀態 |
|---|---|---|---|---|---|
| Quest14 key14 已更新 | S2C `0x74 key14` 已由 T16-116 有界確認，level/town/exclusion 合格 | 不必然 | app `74 00 0E 00` 條件式 | `0x500240` 可建立候選 ID16 | 歷史局部原生已確認 |
| NPC/Actor 對應 ID10027 出現於 selector | `actor+F6=10027` 必須實際成立 | 尚未必發 | 無此處必然回覆 | `0x544162` → `0x500A80` type2 分流 | 靜態條件式已確認，實例待執行 |
| local NPC event `0x105BF` 提交 key10027 | event type/action/gate 均成立 | 獨立 `0x1C,u16,u16` 可條件式生成 | 無唯一配對 | `0x5B9407` 按 giver10027→first type2 QuestID，再入 `0x561760` | native 有界；候選排序及事件來源待查 |
| 有 `0x105B9(+14=16)` 的 QuestInfo 選取事件 | exact ID16 必須由 producer 提供、QuestInfo map hit | 無此處立即網路送出 | 無 | `0x5B6C0C → 0x636520` TalkBox 設定 | **條件式**；Q16-specific producer unknown |
| 玩家在 TalkBox 確認已選 QID16 | T16-114 local action6A7、gate未抑制 | `36 00 10 00` 應用 payload (4B) | **未唯一配對** | queue 建構（非證裸 TCP/Server ACK） | 局部歷史已確認，③待追 |
| local event `0x105B9(+14=10027)` | key 為NPC ID，不是 QID | 不必然 | 無 | QuestInfo lookup 按 key10027；不可推為 Q16 16 | **重要反證** |
| Q16 accept / reject / reward | 原始 Server內部決策未知 | ②本篇不定義 | 原生唯一配對未確認 | UI accepted/completable/reward writer 尚需④ | Client 待逆向 / Server 待開發 |

## 5. 四類責任及五子研究狀態

| Quest16 子研究 | T16-119 後狀態 | 精確界線 |
|---|---|---|
| ① 資源與前置 | **T16-118 已完成有界** | loader Demand14 / reward type2 +0x88、town/giver metadata 語意本篇進一步核實 |
| **② NPC 觸發與 UI 選取** | **本次取得具體 native producer/selector 鏈；仍有一個未閉合的 QID16 事件橋，屬階段性未完成** | `actor+F6` / `0x105BF+14` → giver10027 type2 first QID → `0x561760`，與 `0x105B9(QID16)` → TalkBox 各自已證；二者連結尚欠原生直接 writer |
| ③ C→S | 待正式研究 | `0x36,QID16` sender 有界，mode 1/2/3、`0x1C` 個別業務語意及追加請求須補 |
| ④ S→C/status/UI | 待正式研究 | `0x40/0x74` handlers 有界，但 ACK 配對、accepted/rejected、redraw/reward 未閉合 |
| ⑤ Q16→Q15 | 待正式研究 | key16→Demand16 靜態已知；下游 Q15 NPC10338、world 進入未知 |

- **Client 待逆向**：實際 `QuestID16` local event producer（`0x561760` 後的 UI item/widget selection handler 與 `0x105B9` 寫入者）、NPC spawn/actor+F6 key 之上游與 `0x5B6C0C` dispatch binding、獨立 type2 TalkBox 路徑；③④⑤ 須各自補 native。
- **Server 待開發／S00**：判定 Quest14 完成→Quest16 可接、接受/拒絕/交付/獎勵50（類型語意不得猜）、任務狀態持久化/重登、何時下發 `0x74,key14/16`，以及 network framing/order 由既有證據設計相容協定。
- **跨 Task 待整合**：T02 framing/socket；T03/T04 session 角色；T06 NPC/TalkBox UI；T07 場景與 NPC load；T08 actor/scene；T14 教學關卡事件；T15 persistence；不自行修改他人的 owner/catalog/spec。
- **待遊玩驗證**：Npc10027實際出現/點選、候選列表排序、取得 `0x105B9+QID16`、Quest16 接取成功、Server 客觀回覆及馮德斯村轉場，均無原版執行實測。原稿已由 BIN 讀取，但本篇不宣稱 T01 FULL-PASS。

## 6. 下一輪解除阻塞的精確研究問題

- (1) 從 `0x561760` 的 `EBP+0x8=first QID` → `controller+0x38/+0x3C`、UI 屬性/事件 callback/vtable 全面追 `0x105B9` constructor，辨識 event+0x14 的來源何時是 `QuestInfo.id16`。已見 `0x5618E3..0x5618EF` 寫 `[ebx+0x38/+0x3C/+0x28]`，而 *此函式內沒有直接* `vtable 0xC467AC` 的 immediate 寫入；需追後續 UI callback 而不能直接稱沒有該事件。
- (2) 從 `0x5B9850` 的 map `controller+0x2E8` 查找鍵與 `0x5B9B10` 的 105BA 來源，分別驗它們進入 QuestInfo 事件的 key namespace。`0x5B9850` 覆寫了 `0x105B9` type，沒有覆寫 `source+0x14` 的值成 first QID16；不能誤拼接。
- (3) Q16 遊戲實例若有多個 type2 giver10027 候選，查 `QuestOwner+0x5EC0` 排序與 first-result 選取，是否固定由 UI 提供玩家選擇；不可靜態宣稱 NPC 10027 只給 Q16（還共用其他 Quest）。
- (4) 將 Client 內可證 `0x36,QID16`、`0x1C`、S2C `0x40/0x74` 的事件與進度狀態交給③④研究，Server 判定由 S00 規格/ADR，不要求原版 Server 程式。

## 7. 本次從原始 KR BIN 擷取的可重現 machine code

所有切片由 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`、指定 `.text` VA 區間產生，並計算 raw bytes SHA256；span 起訖均注明。函式內跳表資料不能冒稱可執行指令；只有已對齊指令／callers 和 branch 才納入肯定結論。完整切片保留以供 T01 反證。


### S01 XML attribute to record origin: VA `0x005048C0..0x00504A63` / raw `0x103CC0..0x103E63` / 419B / span SHA256 `b4d34300a257adc4093f52062d8c7be2f1d86dda5a249d1ebbd14002f66f6d90`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005048c0 <.data+0x103cc0>:
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
  50499e:	e8 fd b6 22 00       	call   0x7300a0
  5049a3:	85 c0                	test   eax,eax
  5049a5:	74 19                	je     0x5049c0
  5049a7:	83 c0 30             	add    eax,0x30
  5049aa:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5049ad:	72 02                	jb     0x5049b1
  5049af:	8b 00                	mov    eax,DWORD PTR [eax]
  5049b1:	85 c0                	test   eax,eax
  5049b3:	74 0b                	je     0x5049c0
  5049b5:	50                   	push   eax
  5049b6:	e8 f9 cd 38 00       	call   0x8917b4
  5049bb:	83 c4 04             	add    esp,0x4
  5049be:	eb 02                	jmp    0x5049c2
  5049c0:	33 c0                	xor    eax,eax
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
```


### S02 QuestRecord copy structure: VA `0x005064F4..0x0050654E` / raw `0x1058F4..0x10594E` / 90B / span SHA256 `938cee6bf182b4af787a04a16f5b7d95a6b8894cfa6d02eee53a8a2eb26cdfea`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005064f4 <.data+0x1058f4>:
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
```


### S03 town/level/exclusion candidate gate: VA `0x00500465..0x005004DF` / raw `0xFF865..0xFF8DF` / 122B / span SHA256 `b23b96d44a4466e4b83ff5951be63604386390c7c956f7ffe872e51bfbfbc3f3`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500465 <.data+0xff865>:
  500465:	48                   	dec    eax
  500466:	04 8d                	add    al,0x8d
  500468:	44                   	inc    esp
  500469:	24 2c                	and    al,0x2c
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
  5004de:	83               	add    eax,0x2
```


### S04 giver/type2 reader: VA `0x00500A00..0x00500A7B` / raw `0xFFE00..0xFFE7B` / 123B / span SHA256 `73f6bdee58810216f295c9b65596023e45740b38bac68a3b38c1efa0e284bf2c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500a00 <.data+0xffe00>:
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
  500a7a:	c2               	ret    0xc
```


### S05 first type2 ID consumer: VA `0x005008B0..0x00500945` / raw `0xFFCB0..0xFFD45` / 149B / span SHA256 `b8ffddd7102c8b9975ed33be218de99faeb4138029cc3a2c4f78584c2593b687`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005008b0 <.data+0xffcb0>:
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
  500944:	cc                   	int3
```


### S06 event+NPC type2 lookup and u16 ID: VA `0x005B9340..0x005B9498` / raw `0x1B8740..0x1B8898` / 344B / span SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9340 <.data+0x1b8740>:
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


### S07 actor+F6 selector source: VA `0x00544120..0x005441E7` / raw `0x143520..0x1435E7` / 199B / span SHA256 `7950892574e6717be6cff5c535f573b7fdc96fba85b935f8b87f42a40715c6a2`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00544120 <.data+0x143520>:
  544120:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  544127:	0f b7 86 f6 00 00 00 	movzx  eax,WORD PTR [esi+0xf6]
  54412e:	0f bf f8             	movsx  edi,ax
  544131:	75 29                	jne    0x54415c
  544133:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  54413a:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  544141:	00 
  544142:	e8 19 bd fb ff       	call   0x4ffe60
  544147:	68 00 cf bc 00       	push   0xbccf00
  54414c:	e8 c9 e1 34 00       	call   0x89231a
  544151:	83 c4 04             	add    esp,0x4
  544154:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  54415b:	ff 
  54415c:	57                   	push   edi
  54415d:	68 a0 b2 fa 00       	push   0xfab2a0
  544162:	e8 19 c9 fb ff       	call   0x500a80
  544167:	83 f8 05             	cmp    eax,0x5
  54416a:	74 7b                	je     0x5441e7
  54416c:	8b 35 d0 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1bd0
  544172:	8d 44 24 14          	lea    eax,[esp+0x14]
  544176:	50                   	push   eax
  544177:	8d 4e 08             	lea    ecx,[esi+0x8]
  54417a:	8d 44 24 14          	lea    eax,[esp+0x14]
  54417e:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  544182:	e8 39 f7 2f 00       	call   0x8438c0
  544187:	8b 76 0c             	mov    esi,DWORD PTR [esi+0xc]
  54418a:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  54418e:	3b c6                	cmp    eax,esi
  544190:	0f 84 7d 05 00 00    	je     0x544713
  544196:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  544199:	85 c0                	test   eax,eax
  54419b:	0f 84 72 05 00 00    	je     0x544713
  5441a1:	8b 48 40             	mov    ecx,DWORD PTR [eax+0x40]
  5441a4:	3b 48 44             	cmp    ecx,DWORD PTR [eax+0x44]
  5441a7:	0f 84 66 05 00 00    	je     0x544713
  5441ad:	6a 1c                	push   0x1c
  5441af:	e8 b4 d0 34 00       	call   0x891268
  5441b4:	8b f0                	mov    esi,eax
  5441b6:	83 c4 04             	add    esp,0x4
  5441b9:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5441bd:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  5441c4:	00 
  5441c5:	85 f6                	test   esi,esi
  5441c7:	0f 84 26 03 00 00    	je     0x5444f3
  5441cd:	e8 8e ae ec ff       	call   0x40f060
  5441d2:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5441d8:	50                   	push   eax
  5441d9:	8b d7                	mov    edx,edi
  5441db:	8b c6                	mov    eax,esi
  5441dd:	e8 9e fd 20 00       	call   0x753f80
  5441e2:	e9 0e 03 00 00       	jmp    0x5444f5
```


### S08 actor local 105BF event constructor: VA `0x005442CC..0x0054435E` / raw `0x1436CC..0x14375E` / 146B / span SHA256 `8ec1676b813bfee3f05e407a570abcf3b0c6a6d592d8ed076d1059280612a40b`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005442cc <.data+0x1436cc>:
  5442cc:	53                   	push   ebx
  5442cd:	e8 1e 58 ff ff       	call   0x539af0
  5442d2:	e8 e9 11 ec ff       	call   0x4054c0
  5442d7:	6a 20                	push   0x20
  5442d9:	e8 8a cf 34 00       	call   0x891268
  5442de:	83 c4 04             	add    esp,0x4
  5442e1:	85 c0                	test   eax,eax
  5442e3:	74 3e                	je     0x544323
  5442e5:	0f b7 8e f6 00 00 00 	movzx  ecx,WORD PTR [esi+0xf6]
  5442ec:	0f b7 96 f4 00 00 00 	movzx  edx,WORD PTR [esi+0xf4]
  5442f3:	0f bf d2             	movsx  edx,dx
  5442f6:	0f bf c9             	movsx  ecx,cx
  5442f9:	83 cb ff             	or     ebx,0xffffffff
  5442fc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  5442ff:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544302:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  544309:	c7 40 10 d9 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d9
  544310:	c7 00 e4 7b c4 00    	mov    DWORD PTR [eax],0xc47be4
  544316:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544319:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  54431c:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  54431f:	8b f0                	mov    esi,eax
  544321:	eb 05                	jmp    0x544328
  544323:	33 f6                	xor    esi,esi
  544325:	83 cb ff             	or     ebx,0xffffffff
  544328:	e8 73 07 ec ff       	call   0x404aa0
  54432d:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  544333:	50                   	push   eax
  544334:	56                   	push   esi
  544335:	83 ec 1c             	sub    esp,0x1c
  544338:	8b cc                	mov    ecx,esp
  54433a:	89 64 24 3c          	mov    DWORD PTR [esp+0x3c],esp
  54433e:	68 fc d1 be 00       	push   0xbed1fc
  544343:	e8 08 df eb ff       	call   0x402250
  544348:	c7 44 24 4c 03 00 00 	mov    DWORD PTR [esp+0x4c],0x3
  54434f:	00 
  544350:	c7 44 24 38 21 00 00 	mov    DWORD PTR [esp+0x38],0x21
  544357:	00 
  544358:	e8 53 11 04 00       	call   0x5854b0
  54435d:	8b                 	mov    esi,eax
```


### S09 105BF->105B9 local event constructor: VA `0x005B9850..0x005B998F` / raw `0x1B8C50..0x1B8D8F` / 319B / span SHA256 `2e396ed3b309c168029b4ff48fcc3ff8482e99668852c5f25b46a2a6c2c4a2be`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9850 <.data+0x1b8c50>:
  5b9850:	55                   	push   ebp
  5b9851:	8b ec                	mov    ebp,esp
  5b9853:	83 e4 f8             	and    esp,0xfffffff8
  5b9856:	6a ff                	push   0xffffffff
  5b9858:	68 70 36 93 00       	push   0x933670
  5b985d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9863:	50                   	push   eax
  5b9864:	83 ec 20             	sub    esp,0x20
  5b9867:	53                   	push   ebx
  5b9868:	56                   	push   esi
  5b9869:	57                   	push   edi
  5b986a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b986f:	33 c4                	xor    eax,esp
  5b9871:	50                   	push   eax
  5b9872:	8d 44 24 30          	lea    eax,[esp+0x30]
  5b9876:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b987c:	8b f1                	mov    esi,ecx
  5b987e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5b9881:	33 ff                	xor    edi,edi
  5b9883:	3b f7                	cmp    esi,edi
  5b9885:	74 26                	je     0x5b98ad
  5b9887:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9889:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b988c:	ff d2                	call   edx
  5b988e:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b9893:	75 06                	jne    0x5b989b
  5b9895:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5b9899:	eb 16                	jmp    0x5b98b1
  5b989b:	57                   	push   edi
  5b989c:	68 c0 1f bf 00       	push   0xbf1fc0
  5b98a1:	68 18 21 bf 00       	push   0xbf2118
  5b98a6:	57                   	push   edi
  5b98a7:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b98ad:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  5b98b1:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  5b98b5:	83 c6 14             	add    esi,0x14
  5b98b8:	8d 8b e8 02 00 00    	lea    ecx,[ebx+0x2e8]
  5b98be:	56                   	push   esi
  5b98bf:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b98c3:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  5b98c7:	e8 f4 9f 28 00       	call   0x8438c0
  5b98cc:	8b 83 ec 02 00 00    	mov    eax,DWORD PTR [ebx+0x2ec]
  5b98d2:	39 44 24 18          	cmp    DWORD PTR [esp+0x18],eax
  5b98d6:	0f 85 18 02 00 00    	jne    0x5b9af4
  5b98dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5b98e3:	75 26                	jne    0x5b990b
  5b98e5:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  5b98ec:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  5b98f0:	e8 8b db fc ff       	call   0x587480
  5b98f5:	68 c0 cc bc 00       	push   0xbcccc0
  5b98fa:	e8 1b 8a 2d 00       	call   0x89231a
  5b98ff:	83 c4 04             	add    esp,0x4
  5b9902:	83 cf ff             	or     edi,0xffffffff
  5b9905:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  5b9909:	eb 03                	jmp    0x5b990e
  5b990b:	83 cf ff             	or     edi,0xffffffff
  5b990e:	6a 18                	push   0x18
  5b9910:	e8 53 79 2d 00       	call   0x891268
  5b9915:	83 c4 04             	add    esp,0x4
  5b9918:	85 c0                	test   eax,eax
  5b991a:	74 21                	je     0x5b993d
  5b991c:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5b991e:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  5b9921:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  5b9924:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5b992b:	c7 40 10 e0 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43e0
  5b9932:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  5b9938:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  5b993b:	eb 02                	jmp    0x5b993f
  5b993d:	33 c0                	xor    eax,eax
  5b993f:	f6 05 e4 5a fe 00 01 	test   BYTE PTR ds:0xfe5ae4,0x1
  5b9946:	53                   	push   ebx
  5b9947:	50                   	push   eax
  5b9948:	75 2a                	jne    0x5b9974
  5b994a:	b8 01 00 00 00       	mov    eax,0x1
  5b994f:	09 05 e4 5a fe 00    	or     DWORD PTR ds:0xfe5ae4,eax
  5b9955:	68 c4 5a fe 00       	push   0xfe5ac4
  5b995a:	89 44 24 44          	mov    DWORD PTR [esp+0x44],eax
  5b995e:	e8 dd b2 fc ff       	call   0x584c40
  5b9963:	68 90 f3 bc 00       	push   0xbcf390
  5b9968:	e8 ad 89 2d 00       	call   0x89231a
  5b996d:	83 c4 04             	add    esp,0x4
  5b9970:	89 7c 24 40          	mov    DWORD PTR [esp+0x40],edi
  5b9974:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b9978:	50                   	push   eax
  5b9979:	8d 44 24 28          	lea    eax,[esp+0x28]
  5b997d:	b9 c4 5a fe 00       	mov    ecx,0xfe5ac4
  5b9982:	c7 44 24 24 1e 00 00 	mov    DWORD PTR [esp+0x24],0x1e
  5b9989:	00 
  5b998a:	e8 61 a7 fb ff       	call   0x5740f0
```


### S10 105BA->105B9 local event constructor: VA `0x005B9B10..0x005B9C15` / raw `0x1B8F10..0x1B9015` / 261B / span SHA256 `5b1b9344a451f76689fbdc8a869d3b940f410bb8d00909ca2084b7c965d2b00a`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9b10 <.data+0x1b8f10>:
  5b9b10:	55                   	push   ebp
  5b9b11:	8b ec                	mov    ebp,esp
  5b9b13:	6a ff                	push   0xffffffff
  5b9b15:	68 10 36 93 00       	push   0x933610
  5b9b1a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9b20:	50                   	push   eax
  5b9b21:	83 ec 0c             	sub    esp,0xc
  5b9b24:	53                   	push   ebx
  5b9b25:	56                   	push   esi
  5b9b26:	57                   	push   edi
  5b9b27:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b9b2c:	33 c5                	xor    eax,ebp
  5b9b2e:	50                   	push   eax
  5b9b2f:	8d 45 f4             	lea    eax,[ebp-0xc]
  5b9b32:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b9b38:	8b f1                	mov    esi,ecx
  5b9b3a:	33 ff                	xor    edi,edi
  5b9b3c:	3b f7                	cmp    esi,edi
  5b9b3e:	74 25                	je     0x5b9b65
  5b9b40:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9b42:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b9b45:	ff d2                	call   edx
  5b9b47:	3d ba 05 01 00       	cmp    eax,0x105ba
  5b9b4c:	75 05                	jne    0x5b9b53
  5b9b4e:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  5b9b51:	eb 15                	jmp    0x5b9b68
  5b9b53:	57                   	push   edi
  5b9b54:	68 c0 1f bf 00       	push   0xbf1fc0
  5b9b59:	68 18 21 bf 00       	push   0xbf2118
  5b9b5e:	57                   	push   edi
  5b9b5f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b9b65:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  5b9b68:	bb 01 00 00 00       	mov    ebx,0x1
  5b9b6d:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  5b9b73:	75 23                	jne    0x5b9b98
  5b9b75:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  5b9b7b:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5b9b7e:	e8 fd d8 fc ff       	call   0x587480
  5b9b83:	68 c0 cc bc 00       	push   0xbcccc0
  5b9b88:	e8 8d 87 2d 00       	call   0x89231a
  5b9b8d:	83 c4 04             	add    esp,0x4
  5b9b90:	83 ce ff             	or     esi,0xffffffff
  5b9b93:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5b9b96:	eb 03                	jmp    0x5b9b9b
  5b9b98:	83 ce ff             	or     esi,0xffffffff
  5b9b9b:	6a 18                	push   0x18
  5b9b9d:	e8 c6 76 2d 00       	call   0x891268
  5b9ba2:	83 c4 04             	add    esp,0x4
  5b9ba5:	3b c7                	cmp    eax,edi
  5b9ba7:	74 21                	je     0x5b9bca
  5b9ba9:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  5b9bac:	8b 49 18             	mov    ecx,DWORD PTR [ecx+0x18]
  5b9baf:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5b9bb2:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5b9bb5:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5b9bb8:	c7 40 10 e1 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43e1
  5b9bbf:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  5b9bc5:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  5b9bc8:	eb 02                	jmp    0x5b9bcc
  5b9bca:	33 c0                	xor    eax,eax
  5b9bcc:	f6 05 e4 5a fe 00 01 	test   BYTE PTR ds:0xfe5ae4,0x1
  5b9bd3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5b9bd6:	52                   	push   edx
  5b9bd7:	50                   	push   eax
  5b9bd8:	75 23                	jne    0x5b9bfd
  5b9bda:	09 1d e4 5a fe 00    	or     DWORD PTR ds:0xfe5ae4,ebx
  5b9be0:	68 c4 5a fe 00       	push   0xfe5ac4
  5b9be5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5b9be8:	e8 53 b0 fc ff       	call   0x584c40
  5b9bed:	68 90 f3 bc 00       	push   0xbcf390
  5b9bf2:	e8 23 87 2d 00       	call   0x89231a
  5b9bf7:	83 c4 04             	add    esp,0x4
  5b9bfa:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5b9bfd:	8d 45 08             	lea    eax,[ebp+0x8]
  5b9c00:	50                   	push   eax
  5b9c01:	8d 45 ec             	lea    eax,[ebp-0x14]
  5b9c04:	b9 c4 5a fe 00       	mov    ecx,0xfe5ac4
  5b9c09:	c7 45 08 1d 00 00 00 	mov    DWORD PTR [ebp+0x8],0x1d
  5b9c10:	e8 db a4 fb ff       	call   0x5740f0
```


### S11 105B9 event QuestInfo lookup and TalkBox: VA `0x005B6BE0..0x005B6D15` / raw `0x1B5FE0..0x1B6115` / 309B / span SHA256 `57ca7a82c3e20e9cac4a8978bedd70e1542bf643109557f10e45b32e334579ea`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6be0 <.data+0x1b5fe0>:
  5b6be0:	55                   	push   ebp
  5b6be1:	8b ec                	mov    ebp,esp
  5b6be3:	83 e4 f8             	and    esp,0xfffffff8
  5b6be6:	6a ff                	push   0xffffffff
  5b6be8:	68 2c 93 94 00       	push   0x94932c
  5b6bed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6bf3:	50                   	push   eax
  5b6bf4:	83 ec 10             	sub    esp,0x10
  5b6bf7:	53                   	push   ebx
  5b6bf8:	56                   	push   esi
  5b6bf9:	57                   	push   edi
  5b6bfa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6bff:	33 c4                	xor    eax,esp
  5b6c01:	50                   	push   eax
  5b6c02:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6c06:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6c0c:	8b f1                	mov    esi,ecx
  5b6c0e:	8b fa                	mov    edi,edx
  5b6c10:	85 f6                	test   esi,esi
  5b6c12:	74 26                	je     0x5b6c3a
  5b6c14:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6c16:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6c19:	ff d2                	call   edx
  5b6c1b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6c20:	75 04                	jne    0x5b6c26
  5b6c22:	8b de                	mov    ebx,esi
  5b6c24:	eb 16                	jmp    0x5b6c3c
  5b6c26:	6a 00                	push   0x0
  5b6c28:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6c2d:	68 18 21 bf 00       	push   0xbf2118
  5b6c32:	6a 00                	push   0x0
  5b6c34:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6c3a:	33 db                	xor    ebx,ebx
  5b6c3c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6c43:	75 29                	jne    0x5b6c6e
  5b6c45:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6c4c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6c53:	00 
  5b6c54:	e8 07 92 f4 ff       	call   0x4ffe60
  5b6c59:	68 00 cf bc 00       	push   0xbccf00
  5b6c5e:	e8 b7 b6 2d 00       	call   0x89231a
  5b6c63:	83 c4 04             	add    esp,0x4
  5b6c66:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6c6d:	ff 
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```


### S12 TalkBox mode + record selection: VA `0x00636550..0x00636710` / raw `0x235950..0x235B10` / 448B / span SHA256 `c4ae8528d30d36e0e2dff2e5e39dcab837e8846c2c4d355617a0c5f8816d1580`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636550 <.data+0x235950>:
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
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
  6366ed:	8b 17                	mov    edx,DWORD PTR [edi]
  6366ef:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  6366f5:	8b cf                	mov    ecx,edi
  6366f7:	ff d0                	call   eax
  6366f9:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366ff:	8b 11                	mov    edx,DWORD PTR [ecx]
  636701:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636704:	ff d0                	call   eax
  636706:	57                   	push   edi
  636707:	e8 44 f9 ff ff       	call   0x636050
  63670c:	c7 44 24 40    	mov    DWORD PTR [esp+0x40],0x1
  636713:
```


### S13 negative type1 mode3 event producer: VA `0x00636C84..0x00636CFA` / raw `0x236084..0x2360FA` / 118B / span SHA256 `3099070a534bbe39f8a0239dea9968031f3be268fcf9163a577c36de611f0e66`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636c84 <.data+0x236084>:
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
```


### S14 type1-only 5007D0 helper: VA `0x005007D0..0x005008AE` / raw `0xFFBD0..0xFFCAE` / 222B / span SHA256 `40471e5f7b79f250145e8e2d93c167383df5d60d57f8d678d5ecf00414c1e1ac`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005007d0 <.data+0xffbd0>:
  5007d0:	55                   	push   ebp
  5007d1:	8b ec                	mov    ebp,esp
  5007d3:	83 e4 f8             	and    esp,0xfffffff8
  5007d6:	6a ff                	push   0xffffffff
  5007d8:	68 08 6a 90 00       	push   0x906a08
  5007dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5007e3:	50                   	push   eax
  5007e4:	83 ec 18             	sub    esp,0x18
  5007e7:	53                   	push   ebx
  5007e8:	56                   	push   esi
  5007e9:	57                   	push   edi
  5007ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5007ef:	33 c4                	xor    eax,esp
  5007f1:	50                   	push   eax
  5007f2:	8d 44 24 28          	lea    eax,[esp+0x28]
  5007f6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5007fc:	33 f6                	xor    esi,esi
  5007fe:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  500802:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  500806:	89 74 24 1c          	mov    DWORD PTR [esp+0x1c],esi
  50080a:	8d 44 24 14          	lea    eax,[esp+0x14]
  50080e:	50                   	push   eax
  50080f:	51                   	push   ecx
  500810:	52                   	push   edx
  500811:	89 74 24 3c          	mov    DWORD PTR [esp+0x3c],esi
  500815:	e8 36 01 00 00       	call   0x500950
  50081a:	8b 7c 24 18          	mov    edi,DWORD PTR [esp+0x18]
  50081e:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  500822:	2b fb                	sub    edi,ebx
  500824:	c1 ff 02             	sar    edi,0x2
  500827:	85 ff                	test   edi,edi
  500829:	74 32                	je     0x50085d
  50082b:	eb 03                	jmp    0x500830
  50082d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500830:	8b 14 b3             	mov    edx,DWORD PTR [ebx+esi*4]
  500833:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  500836:	2b 42 10             	sub    eax,DWORD PTR [edx+0x10]
  500839:	33 c9                	xor    ecx,ecx
  50083b:	c1 f8 02             	sar    eax,0x2
  50083e:	85 c0                	test   eax,eax
  500840:	74 16                	je     0x500858
  500842:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  500845:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  500848:	39 1a                	cmp    DWORD PTR [edx],ebx
  50084a:	74 35                	je     0x500881
  50084c:	41                   	inc    ecx
  50084d:	83 c2 04             	add    edx,0x4
  500850:	3b c8                	cmp    ecx,eax
  500852:	72 f1                	jb     0x500845
  500854:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  500858:	46                   	inc    esi
  500859:	3b f7                	cmp    esi,edi
  50085b:	72 d3                	jb     0x500830
  50085d:	85 db                	test   ebx,ebx
  50085f:	74 09                	je     0x50086a
  500861:	53                   	push   ebx
  500862:	e8 a5 09 39 00       	call   0x89120c
  500867:	83 c4 04             	add    esp,0x4
  50086a:	33 c0                	xor    eax,eax
  50086c:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  500870:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500877:	59                   	pop    ecx
  500878:	5f                   	pop    edi
  500879:	5e                   	pop    esi
  50087a:	5b                   	pop    ebx
  50087b:	8b e5                	mov    esp,ebp
  50087d:	5d                   	pop    ebp
  50087e:	c2 04 00             	ret    0x4
  500881:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  500885:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  500888:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  50088b:	85 c0                	test   eax,eax
  50088d:	74 09                	je     0x500898
  50088f:	50                   	push   eax
  500890:	e8 77 09 39 00       	call   0x89120c
  500895:	83 c4 04             	add    esp,0x4
  500898:	66 8b c6             	mov    ax,si
  50089b:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  50089f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5008a6:	59                   	pop    ecx
  5008a7:	5f                   	pop    edi
  5008a8:	5e                   	pop    esi
  5008a9:	5b                   	pop    ebx
  5008aa:	8b e5                	mov    esp,ebp
  5008ac:	5d                   	pop    ebp
  5008ad:	c2               	ret    0x4
```


### S15 UI controller first ID writing: VA `0x00561760..0x00561928` / raw `0x160B60..0x160D28` / 456B / span SHA256 `5a84aaccf0d9dd455648653c577f75a1144576f76b28dc79f85632ec310cd802`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561760 <.data+0x160b60>:
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
  561830:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00    	jne    0x5618dc
  56183a:	e8 61 33 ea ff       	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                	je     0x561864
  561848:	e8 53 33 ea ff       	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04 	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                	je     0x561864
  561856:	e8 45 33 ea ff       	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19 	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                	jne    0x5618dc
  561864:	8b 73 78             	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c             	lea    edx,[ebp+0xc]
  56186a:	52                   	push   edx
  56186b:	8d 4b 74             	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14          	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff       	call   0x4364c0
  561877:	39 30                	cmp    DWORD PTR [eax],esi
  561879:	74 5c                	je     0x5618d7
  56187b:	6a 0f                	push   0xf
  56187d:	e8 2e 3d 02 00       	call   0x5855b0
  561882:	8b f0                	mov    esi,eax
  561884:	e8 a7 3a 02 00       	call   0x585330
  561889:	50                   	push   eax
  56188a:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff       	call   0x402250
  561893:	8d 44 24 3c          	lea    eax,[esp+0x3c]
  561897:	50                   	push   eax
  561898:	c7 44 24 6c 01 00 00 	mov    DWORD PTR [esp+0x6c],0x1
  56189f:	00 
  5618a0:	e8 1b e0 ea ff       	call   0x40f8c0
  5618a5:	8b f8                	mov    edi,eax
  5618a7:	e8 84 52 f7 ff       	call   0x4d6b30
  5618ac:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
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
  561927:	c7       	mov    DWORD PTR [esp+0x68],0x3
  56192e:
```


### S16 event dispatch transition: VA `0x005B7C50..0x005B7D61` / raw `0x1B7050..0x1B7161` / 273B / span SHA256 `f112e9bc4672c1a1b40e33b06b0c722d3768cbd692d2391d6a9678a5a76cd6fb`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b7c50 <.data+0x1b7050>:
  5b7c50:	55                   	push   ebp
  5b7c51:	8b ec                	mov    ebp,esp
  5b7c53:	56                   	push   esi
  5b7c54:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5b7c57:	57                   	push   edi
  5b7c58:	56                   	push   esi
  5b7c59:	8b f9                	mov    edi,ecx
  5b7c5b:	e8 80 3d fe ff       	call   0x59b9e0
  5b7c60:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  5b7c63:	05 a6 bd f0 ff       	add    eax,0xfff0bda6
  5b7c68:	83 f8 7c             	cmp    eax,0x7c
  5b7c6b:	0f 87 f1 01 00 00    	ja     0x5b7e62
  5b7c71:	0f b6 80 f4 7e 5b 00 	movzx  eax,BYTE PTR [eax+0x5b7ef4]
  5b7c78:	ff 24 85 68 7e 5b 00 	jmp    DWORD PTR [eax*4+0x5b7e68]
  5b7c7f:	57                   	push   edi
  5b7c80:	e8 3b 0f 00 00       	call   0x5b8bc0
  5b7c85:	5f                   	pop    edi
  5b7c86:	5e                   	pop    esi
  5b7c87:	5d                   	pop    ebp
  5b7c88:	c2 04 00             	ret    0x4
  5b7c8b:	8b c6                	mov    eax,esi
  5b7c8d:	8b f7                	mov    esi,edi
  5b7c8f:	e8 ec f5 ff ff       	call   0x5b7280
  5b7c94:	5f                   	pop    edi
  5b7c95:	5e                   	pop    esi
  5b7c96:	5d                   	pop    ebp
  5b7c97:	c2 04 00             	ret    0x4
  5b7c9a:	57                   	push   edi
  5b7c9b:	e8 20 10 00 00       	call   0x5b8cc0
  5b7ca0:	5f                   	pop    edi
  5b7ca1:	5e                   	pop    esi
  5b7ca2:	5d                   	pop    ebp
  5b7ca3:	c2 04 00             	ret    0x4
  5b7ca6:	57                   	push   edi
  5b7ca7:	e8 64 10 00 00       	call   0x5b8d10
  5b7cac:	5f                   	pop    edi
  5b7cad:	5e                   	pop    esi
  5b7cae:	5d                   	pop    ebp
  5b7caf:	c2 04 00             	ret    0x4
  5b7cb2:	57                   	push   edi
  5b7cb3:	e8 f8 10 00 00       	call   0x5b8db0
  5b7cb8:	5f                   	pop    edi
  5b7cb9:	5e                   	pop    esi
  5b7cba:	5d                   	pop    ebp
  5b7cbb:	c2 04 00             	ret    0x4
  5b7cbe:	57                   	push   edi
  5b7cbf:	e8 9c 10 00 00       	call   0x5b8d60
  5b7cc4:	5f                   	pop    edi
  5b7cc5:	5e                   	pop    esi
  5b7cc6:	5d                   	pop    ebp
  5b7cc7:	c2 04 00             	ret    0x4
  5b7cca:	57                   	push   edi
  5b7ccb:	e8 90 0a 00 00       	call   0x5b8760
  5b7cd0:	5f                   	pop    edi
  5b7cd1:	5e                   	pop    esi
  5b7cd2:	5d                   	pop    ebp
  5b7cd3:	c2 04 00             	ret    0x4
  5b7cd6:	8b 8f 80 02 00 00    	mov    ecx,DWORD PTR [edi+0x280]
  5b7cdc:	51                   	push   ecx
  5b7cdd:	57                   	push   edi
  5b7cde:	e8 1d f1 fd ff       	call   0x596e00
  5b7ce3:	5f                   	pop    edi
  5b7ce4:	5e                   	pop    esi
  5b7ce5:	5d                   	pop    ebp
  5b7ce6:	c2 04 00             	ret    0x4
  5b7ce9:	8b 8f 80 02 00 00    	mov    ecx,DWORD PTR [edi+0x280]
  5b7cef:	e8 1c d7 04 00       	call   0x605410
  5b7cf4:	5f                   	pop    edi
  5b7cf5:	5e                   	pop    esi
  5b7cf6:	5d                   	pop    ebp
  5b7cf7:	c2 04 00             	ret    0x4
  5b7cfa:	8b 8f 80 02 00 00    	mov    ecx,DWORD PTR [edi+0x280]
  5b7d00:	8b 51 28             	mov    edx,DWORD PTR [ecx+0x28]
  5b7d03:	c1 ea 08             	shr    edx,0x8
  5b7d06:	f6 c2 01             	test   dl,0x1
  5b7d09:	0f 84 53 01 00 00    	je     0x5b7e62
  5b7d0f:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b7d11:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  5b7d17:	ff d2                	call   edx
  5b7d19:	5f                   	pop    edi
  5b7d1a:	5e                   	pop    esi
  5b7d1b:	5d                   	pop    ebp
  5b7d1c:	c2 04 00             	ret    0x4
  5b7d1f:	57                   	push   edi
  5b7d20:	e8 ab 13 00 00       	call   0x5b90d0
  5b7d25:	5f                   	pop    edi
  5b7d26:	5e                   	pop    esi
  5b7d27:	5d                   	pop    ebp
  5b7d28:	c2 04 00             	ret    0x4
  5b7d2b:	57                   	push   edi
  5b7d2c:	8b c6                	mov    eax,esi
  5b7d2e:	e8 ed 13 00 00       	call   0x5b9120
  5b7d33:	5f                   	pop    edi
  5b7d34:	5e                   	pop    esi
  5b7d35:	5d                   	pop    ebp
  5b7d36:	c2 04 00             	ret    0x4
  5b7d39:	8b c6                	mov    eax,esi
  5b7d3b:	8b f7                	mov    esi,edi
  5b7d3d:	e8 3e 14 00 00       	call   0x5b9180
  5b7d42:	5f                   	pop    edi
  5b7d43:	5e                   	pop    esi
  5b7d44:	5d                   	pop    ebp
  5b7d45:	c2 04 00             	ret    0x4
  5b7d48:	57                   	push   edi
  5b7d49:	8b ce                	mov    ecx,esi
  5b7d4b:	e8 00 1b 00 00       	call   0x5b9850
  5b7d50:	5f                   	pop    edi
  5b7d51:	5e                   	pop    esi
  5b7d52:	5d                   	pop    ebp
  5b7d53:	c2 04 00             	ret    0x4
  5b7d56:	57                   	push   edi
  5b7d57:	8b ce                	mov    ecx,esi
  5b7d59:	e8 b2 1d 00 00       	call   0x5b9b10
  5b7d5e:	5f                   	pop    edi
  5b7d5f:	5e                   	pop    esi
  5b7d60:	5d                   	pop    ebp
```


## 8. 歷史對照、不可提升的認定

- T16-112/118：QuestInfo16 type2/giver10027/town0/Demand14，與 XML loader 本段重驗衝突為零；不能用資料存在代替 runtime spawn。
- T16-116：`0x74,key14`→owner prerequisites/candidate；本篇沒有把 callback 自動刷新 UI 推定為真。
- T16-117：已修正 type1 `0x500950` 不代表 type2 Q16；本篇新增原始 XML 欄位到 struct selector 的推導，和 `0x544162`/`0x5B9407` sender-side native actor/event evidence。對先前「Quest16 UI 已顯示」的說法仍採限定修正。
- T16-114：若 TalkBox 選中 QuestID16，confirm 生成 app `36 00 10 00`，不表示 Server 已接收/准許，也不證原版任何 ACK timing。
- T01/S00：本篇未送正式原生審核、未被標 FULL-PASS／ACCEPTED／STABLE；完成「發現可核對機器碼與部分 Client 靜態鏈」與真正遊戲可玩分開。


## 9. 追加 native 下游調查（重要反證）：`0x561760` 不是已證的 Quest16 TalkBox 啟動器

這一節在本篇撰寫後，針對第 6 節仍未閉合的 `firstQID16→TalkBox` 箭頭繼續沿著原始 BIN 追查。保留前文首次靜態分析的證據而作限制與更正。

### 9.1 `0x561760` 控制器 `+0x38/+0x3C` 下游不應直接稱為「任務選取 UI」

在 `0x5618E3` 取得函式 stack `[ebp+8]` 與 `[ebp+0xC]`，分別保存 `controller+0x38/+0x3C`，只證明兩個參數的暫存。後續 `0x561760` 構建與查找 `controller+0xC` 的二鍵索引，並可能在 `0x561D7F` 進入 `0x561DB0`。重要的是 `0x561760` 執行開頭已把 `controller+0x89` 清零 (`0x5617C6`)；因此不能假定所有 `0x561DB0` 分支都走相同下游。

`0x561DB0` 附近有**兩條特別重要且互斥的條件式下游**：

- 當 `controller+0x89!=0` 且 `controller+0x28!=0`，在 `0x561ED1..0x561EF3` 先 `0x47E640` 取得新的本地結果／第二鍵，當結果非零才以 `push controller+0x3C; push controller+0x38; call 0x565720`，這個 callee 在歷史 T16-108 為 SceneList `(questIdx,sceneIdx)` 查找／執行的相關入口，而**不是**已證的 QuestInfo TalkBox 選取端。不能用「已選出 firstID16」無條件證明此條件已成立。
- 若 `controller+0x89==0`，`0x561F60..0x5620A9` 檢查 `controller+0x28`、`+0x38`，並可在 `0x561FA3..0x561FB0` 或 `0x561FD4..0x561FE0` 呼叫 `0x4A39A0`，同樣攜帶 `controller+0x38/+0x3C` 兩參數；其實際被 Server 接受、QuestInfo 接取與 UI 開啟的語意**尚未在本篇閉合**。函式末端會清除 `controller+0x38/+0x3C` (`0x562091/0x562094`)。

**對前段描述的更正**：`0x5B9407→0x561760(firstQuestCandidate,1)` 是已確認的本地控制／場景相關過渡，不能把這個 producer 提升為 Quest16 TalkBox 的事件送達或 C→S `0x36` 的直接因果。即使 Q16 是唯一 type2 候選，`QuestID16` 在此被當作一個控制鍵，必須進一步知道 `0x4A39A0`／`0x565720` 的精確使用條件。`Event/SceneList.xml` 在既有 T16-112 全集掃描下沒有 `(questIdx=16,*)`；這是**該原始 SceneList 的範圍負證**，不是全面否定 Q16 劇情或任務，亦不排除控制器其他路徑。

### 9.2 另一條 0x105B9 UI producer 的本地欄位來源，仍無 Q16 唯一配對

`0x6391C0`（同系列 `0x639210`，另有 `0x639840`）在 `0x6391D1..0x6391F9` 建立 0x18 bytes local event（`vptr=0xC467AC`，type `0x105B9`）；**實際 `event+0x14` 來自 `[context+4]+0x84`**，由 `0x6391D1` 取得 `[esi+4]` 後 `0x6391D4 mov ecx,[ecx+84]`；`0x6391F9 mov [eax+14],ecx`。這是另一個可證 `0x105B9` producer，但 `[context+4]+0x84` 究竟是 QuestID16、NPC10027 還是其他 UI key，仍需要其具體 caller/建立者；不得僅因 consumer `0x5B6C0C` 使用 QuestInfo map 就假設所有事件都合法命中。

`0x63656B` 亦會寫 `[edi+0x84]`，但此處 `edi` 為 `0x636520` 的 TalkBox/控制器引數，**尚無證據證實它就是 `0x6391C0` 的 `context+4` 指向的同一物件**。尤其 `0x636520` 由不同 event/mode 進入，不能把兩種 `+0x84` 直接合一。

### 9.3 重新評估 Quest16-② 完成度

本篇已追明 NPC giver selector 和 type2 first candidate 如何進入**控制器／劇情鍵選擇**，也知道 TalkBox 消費 `0x105B9(QID)` 的條件式原生介面，並找到更多 local event producers。然而因為 `0x561760` 的下游事實上還包含 SceneList/scene-style transition，**從 NPC10027 事件走到 QuestInfo ID16 的 UI event 仍欠直接同物件、同鍵值資料流**。因此依專案 02 的「靜態目標達成才完成」規則，**Quest16-② 截至本批仍是階段性未完成；不能宣稱全鏈完成、NPC UI 已顯示或 0x36 已按下**。如需真正完成，後續應追：`0x4A39A0` 帶 QID16 的分支用途／產生的 local `0x105B9`，`0x6391C0` 的 `context+4` UI item 實例、`0x561760` 控制器 `+0x89` writer 及 `0x565720` 的缺 SceneList 回退。這是尚能做的靜態研究，不可僅以缺動態資料推諉。

### 9.4 原始 BIN bytes / assembly（新、可重現）

#### S17: controller deferred downstream `0x561DB0..0x561F60`

VA `0x561db0..0x561f60`; raw `0x1611b0..0x161360`; 432 bytes; slice SHA256 `249f4491e25f146a9c4db1bfb831877e9d881270d683d508d010f78832366b0d`.
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
  561e47:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  561e4e:	75 20                	jne    0x561e70
  561e50:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  561e56:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  561e5a:	e8 21 56 02 00       	call   0x587480
  561e5f:	68 c0 cc bc 00       	push   0xbcccc0
  561e64:	e8 b1 04 33 00       	call   0x89231a
  561e69:	83 c4 04             	add    esp,0x4
  561e6c:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e70:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  561e76:	83 ec 08             	sub    esp,0x8
  561e79:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  561e7d:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  561e81:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  561e85:	d9 1c 24             	fstp   DWORD PTR [esp]
  561e88:	e8 93 7b 02 00       	call   0x589a20
  561e8d:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  561e93:	e8 08 2d ea ff       	call   0x404ba0
  561e98:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  561e9e:	eb 03                	jmp    0x561ea3
  561ea0:	83 ce ff             	or     esi,0xffffffff
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

#### S18: controller alternate downstream `0x561F60..0x5620AA`

VA `0x561f60..0x5620aa`; raw `0x161360..0x1614aa`; 330 bytes; slice SHA256 `f6d8dd5b575ac0665dd943411d8bb7e70644f4923e2ed923bb051da5480b69f8`.
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
  5620a9:	c3                   	ret
```

#### S19: local 0x105B9 widget producer `0x6391C0..0x63925E`

VA `0x6391c0..0x63925e`; raw `0x2385c0..0x23865e`; 158 bytes; slice SHA256 `bdcd58215c829bf0d3d82156306281fba96206ff2dc15206055b8cfc57b7b62b`.
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006391c0 <.data+0x2385c0>:
  6391c0:	56                   	push   esi
  6391c1:	6a 18                	push   0x18
  6391c3:	8b f1                	mov    esi,ecx
  6391c5:	e8 9e 80 25 00       	call   0x891268
  6391ca:	83 c4 04             	add    esp,0x4
  6391cd:	85 c0                	test   eax,eax
  6391cf:	74 32                	je     0x639203
  6391d1:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  6391d4:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  6391da:	83 ca ff             	or     edx,0xffffffff
  6391dd:	8b f0                	mov    esi,eax
  6391df:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  6391e2:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6391e5:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  6391ec:	c7 40 10 ec 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42ec
  6391f3:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  6391f9:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  6391fc:	e8 9f e0 dc ff       	call   0x4072a0
  639201:	5e                   	pop    esi
  639202:	c3                   	ret
  639203:	33 c0                	xor    eax,eax
  639205:	8b f0                	mov    esi,eax
  639207:	e8 94 e0 dc ff       	call   0x4072a0
  63920c:	5e                   	pop    esi
  63920d:	c3                   	ret
  63920e:	cc                   	int3
  63920f:	cc                   	int3
  639210:	56                   	push   esi
  639211:	6a 18                	push   0x18
  639213:	8b f1                	mov    esi,ecx
  639215:	e8 4e 80 25 00       	call   0x891268
  63921a:	83 c4 04             	add    esp,0x4
  63921d:	85 c0                	test   eax,eax
  63921f:	74 32                	je     0x639253
  639221:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  639224:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  63922a:	83 ca ff             	or     edx,0xffffffff
  63922d:	8b f0                	mov    esi,eax
  63922f:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  639232:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  639235:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  63923c:	c7 40 10 eb 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42eb
  639243:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  639249:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  63924c:	e8 4f e0 dc ff       	call   0x4072a0
  639251:	5e                   	pop    esi
  639252:	c3                   	ret
  639253:	33 c0                	xor    eax,eax
  639255:	8b f0                	mov    esi,eax
  639257:	e8 44 e0 dc ff       	call   0x4072a0
  63925c:	5e                   	pop    esi
  63925d:	c3                   	ret
```
