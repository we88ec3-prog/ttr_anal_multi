# KR T16-74 — Quest 接取請求／任務結果的原生名稱與數值對照表，及 wire opcode 證據邊界

- 時間：2026-10-28 18:54:56 Asia/Taipei。研究者：chatgpt-web roy。僅 KR。
- 來源：唯讀 `/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 以 `objdump -h` 本輪重核 PE32 x86：`.text` VA `0x00401000`，raw `0x400`，長度 `0x7D01F0`；`.rdata` VA `0x00BD2000`，raw `0x7D0600`；`.data` VA `0x00D61000`，raw `0x95E800`。逐 section 做 VA/raw 換算。
- 沒有啟動、patch、附加 KR Client；沒有使用 AI fixture 推導正式封包。研究限制：本次並未取得網路流量或 Server 原件。

## 0. 研究任務及前段區別

T16-73／73-2／73-3 的 queue worker `0x804740` 虛方法目標尚未找到。依最新交接的 Client 封包優先規則，本輪改從 Quest 業務名稱與狀態事件反向查證，優先找尋「玩家接取 Quest → Client 傳輸」以及「接受／拒絕／完成 Quest → Client 接收與 UI」兩個方向的原生入口。**此次新增的是具體可追蹤的兩組原始表，而不是 C→S 或 S→C 傳輸閉環。**

## 1. 第 1 輪 T16-74：BIN string → rdata → data cross references

### 1.1 原生字串及映射

| 意義（只取字串表面名稱）| .rdata raw | VA | 表中記錄 raw |
|---|---:|---:|---:|
| `kRequestAcceptQuest` | `0x8174CC` | `0xC18ECC` | `0x963594` |
| `kQuestListChoiceReward` | `0x817508` | `0xC18F08` | `0x963570` |
| `kAcceptedQuest` | `0x814A48` | `0xC16448` | `0x964BBC` |
| `kAcceptQuestFailed` | `0x814A34` | `0xC16434` | `0x964BC8` |
| `kCompletedQuest` | `0x814A24` | `0xC16424` | `0x964BD4` |

原件中不僅存在文字，還存在引用這些文字地址的定長資料記錄。對照候選名稱可形成「接取要求」與「接收結果」兩條具體研究方向；**不代表兩種方向已由實際封包證實**。

### 1.2 資料記錄佈局（每筆 12 bytes）

每筆資料有三個 little-endian dword：`{number, name_ptr, common_ptr}`。在下列已檢視區間，第三欄都為 `0x00C11778`；其意義與所屬 C++ 類別 unknown。

原始 BIN 位元組：

```text
raw 0x963594:
1f 00 00 00 cc 8e c1 00 78 17 c1 00
20 00 00 00 ac 8e c1 00 78 17 c1 00
21 00 00 00 98 8e c1 00 78 17 c1 00
22 00 00 00 8c 8e c1 00 78 17 c1 00

raw 0x964BBC:
11 00 00 00 48 64 c1 00 78 17 c1 00
12 00 00 00 34 64 c1 00 78 17 c1 00
13 00 00 00 24 64 c1 00 78 17 c1 00
14 00 00 00 14 64 c1 00 78 17 c1 00
```

換算範例：raw `0x963594` 是 `.data` 內 VA `0x00D65D94`；raw `0x964BBC` 是 VA `0x00D673BC`。這不是 `.text` 程式位址。

### 1.3 相鄰記錄（原生確立的名稱→表內值）

| 分組 | number | name | record raw |
|---|---:|---|---:|
| A | `0x1A` | `kQuestAwardFailed` | `0x963558` |
| A | `0x1B` | `kQuestListAlredyFull` | `0x963564` |
| A | `0x1C` | `kQuestListChoiceReward` | `0x963570` |
| A | `0x1D` | `kQuestListGiveup` | `0x96357C` |
| A | `0x1E` | `kQuestListAllGiveup` | `0x963588` |
| A | **`0x1F`** | **`kRequestAcceptQuest`** | `0x963594` |
| A | `0x20` | `kProceedScenarioAndLeaveParty` | `0x9635A0` |
| A | `0x21` | `kProceedScenario` | `0x9635AC` |
| B | **`0x11`** | **`kAcceptedQuest`** | `0x964BBC` |
| B | **`0x12`** | **`kAcceptQuestFailed`** | `0x964BC8` |
| B | **`0x13`** | **`kCompletedQuest`** | `0x964BD4` |
| B | `0x14` | `kResignedQuest` | `0x964BE0` |
| B | `0x15` | `kQuestAllGiveUp` | `0x964BEC` |

A/B 只是本研究用的不同表區段標記，尚未依 dispatcher 追證正式的 C→S／S→C 命令域。大小寫、拼字保留 BIN 原文。表內整數可能是 command enum、文字 ID、日誌分類或其他本地索引；**尚未證明是 wire opcode**。

## 2. 第 2 輪 T16-74-2：資料指標 xref 精確掃描與反證

採用完整 BIN 內容的 4-byte little-endian 精確 pattern 比對（只用以蒐集候選，並不預設命中必為合法指令）：

- `0xC18ECC` → 只命中 raw `0x963598`（A table name pointer）
- `0xC18F08` → 只命中 raw `0x963574`
- `0xC16448` → 只命中 raw `0x964BC0`
- `0xC16434` → 只命中 raw `0x964BCC`
- `0xC16424` → 只命中 raw `0x964BD8`

意義：本輪未得到可立即從**單一名稱字串指標**推回程式使用者的額外直接 xref。這**不能**排除程式透過表頭、相對位置、動態索引或間接註冊存取該表；不得以「沒有其他 raw pointer hits」宣稱 Client 沒有接任務功能。

## 3. 第 3 輪 T16-74-3：資料列位址的靜態 direct-reference 排除

掃描與前後相鄰記錄對應的 `.data` VA：
- A `0xD65D88`、`0xD65D94`、`0xD65DA0`
- B `0xD673B0`、`0xD673BC`、`0xD673C8`

整個 BIN 的各指定 4-byte 指標皆為 **0 處精確命中**。這是對這 6 個位址／此比對法成立的有限負結果，並非排除經表基址與索引的使用。因而目前無法從記錄位址直接找出 registry constructor、producer 或 S→C business handler。沒有把其他 Task 的 dispatcher 推論移植為本任務已確認事實。

## 4. 與前段網路路徑的證據隔離

已在先前筆記記錄的通用流程：本地 scenario 4-byte message → 出站 queue → framing → Winsock `WSASend`，以及 `WSARecv` → framing parser → queue worker；本輪只找到新的 **Quest 命名整數表**。尚未出現以下因果連結：

```text
NPC UI click ─?─> A[0x1F] producer ─?─> packet builder ─?─> WSASend
WSARecv ─?─> opcode decode ─?─> B[0x11/0x12/0x13] handler
          ─?─> quest cache writer ─?─> NPC/quest UI
```

A/B 表整數不應用來建構官方 wire 協定或編寫相容 Server 封包。相容 Server 需求屬後續設計：可在證明 Client 的實際封包欄位與回覆 consumer 後實作接受／拒絕、完成通知及後續任務可接狀態；目前資料不足以定出欄位、時序或 Quest16→Quest15 前置。

## 5. 玩家情境證據矩陣

| 情境 | Client gate | C→S | S→C | Client 任務/UI 效果 | Server 待開發 |
|---|---|---|---|---|---|
| NPC 接取 Quest | unknown | `kRequestAcceptQuest` 表內 `0x1F` 已證實；實際發送 opcode/欄位 unknown | 表 B 有 accepted/failed 名稱，handler unknown | unknown | 接任務／拒絕回覆格式須先補 Client 證據 |
| 任務完成 | unknown | unknown | `kCompletedQuest` 表內 `0x13` 已證實；實際收包未知 | cache writer unknown | 完成通知與狀態同步介面待證 |
| Quest16 → Quest15 可接 | unknown | unknown | unknown | unknown | Client 原版資源與可接規則待補 |
| `RequestStartScenario` | `[FBA798]==0`（前段） | local 4-byte type `0x40`，共用網路鏈已查，但正式 wire mapping 未證 | unknown | unknown | 按已確認格式設計，不等於 Server 原版規則 |

## 6. 三輪門檻、停止理由、下一入口

- **T16-74**：找到兩組可定位的原始名稱→數值資料表，並從原生位元組驗證 12-byte record 布局；這是具體新導航證據，但不足以宣稱封包閉環或重大業務功能進展。
- **T16-74-2**：針對五個關鍵原生字串指標做全 BIN xref 掃描，釐清沒有額外 direct name-pointer xref 的有限範圍。
- **T16-74-3**：針對六個表記錄 VA 做全 BIN 靜態引用排除，仍未達重大功能鏈進展。符合三輪門檻後允許結束本正式段號，不假稱 handler 已解出。

下一段 T16-75 建議：搜尋兩組表的共同起點／邊界與登記迴圈（不可只查單筆記錄地址）；由 Quest NPC UI click 的真正 native caller、S→C Quest cache writer 反推 producer/consumer，並與 T02 已確認協定域交叉證明。優先取得具函式呼叫、資料欄位及終點的完整鏈。QuestInfo.xml、TutorialBase.lua 原件未取得，保持待補，不阻止網路方向研究。

## 7. GitHub 與分工

僅將研究筆記放於 `kr-temp-roy/`；T02 socket/framing、T07 場景、T14 結算、T15 持久化各自保留主責。本輪不編輯 owner、task.json、catalog，也不提交 KR 二進位原件。