# MEF R12：NPC、商店與出口互動點的完整控制流程

研究基準：2026-11-16（Asia/Taipei）；倉庫 we88ec3-prog/ttr_anal_multi，工作分支 `extra/roy1`，前輪 `f8f2c8bdbb984a7571e7bd7591941f1ddda08889`。開工時 main 為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；比較 main...extra/roy1 是 ahead 9／behind 0，main 已包含在祖先鏈，未新增分支、未執行空合併。本輪僅新增研究與節錄，未修改 Client、Server、原始資源、正式 RR 或 Task owner。

## 1. 研究目標及實質進展

上一輪 [MEF 能力手冊](20261116-113220-chatgpt-web-roy1-MEF-capabilities.md) 已覆蓋七個正常 Lua namespace 的 121 個 binding 名稱、75 個 qbase helper，以及角色、對白、鏡頭、音訊、UI、NPC 與商店。此次按照使用者的最新方向，以「**.mef／相容新內容實際能使 Client 做什麼**」為分析目標，不要求普通戰鬥完全由 MEF 接替 Server。

本輪新增一條可完整追到玩家操作結果的能力：**Server 下發互動點集合、Server 或 Lua 改變既有點狀態、Client 依位置／輸入與類別啟動 NPC／商店／教學 UI 或選定的網路回報**。其中此前能力總表未完整列出的 S2C `0048` 6-byte 更新格式、與 Lua setter 共用的 native 路徑、以及 C2S `001C` 的有界發送條件是本輪新增的核心證據。

這條功能鏈說明 MEF 可以控制「何時可與某個既有 NPC、商店或出口互動」，但並未證明它能透過相同方法新建／搬移互動點，或直接修改 Server 貨幣／裝備／任務資料。

## 2. 原件身分與方法

核心 KR `Tartaros.bin`，SHA-256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386，image base `0x00400000`，原件 `.text` 從 VA `0x00401000`、raw `0x00000400` 開始。Tartaros.exe SHA-256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；Event.stp `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；Table.stp `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。本輪直接讀取並核實這些原件的身分，對上述新 Native 鏈以 BIN-first 原始位元組、objdump、call／data flow 核對。

[25 個精確 VA／raw／hex 節錄](MEF-checkpoint-20261116/evidence.json) 與 [唯讀重驗程式](MEF-checkpoint-20261116/verify_evidence.py) 保存有限來源，不發佈完整 BIN／EXE／STP、解包腳本或可部署遊戲內容。原件固定來源不是全程式完整語義證明，證據鏈以本稿列出的 caller、consumer 與條件為界。

## 3. 一條完整的功能流程

~~~text
Server 編排合法點集合（待開發）
   │
   └─ S2C 0027 → 4B2AF0 → 5449A0 清舊點 → 543700 逐 row 建立新點
         │      存 point category/key/XY/radius/flags/enabled
         ├─ S2C 0048 → 4B32E0 ─┐
         └─ 正式 Lua           │
            Tutorial.SetCheckPointStatus
               → 4A9460 ──────┴─→ 544940 第一個 (category,key)
                                        → 543B30 改 point+0x105
         ↓
      544730 範圍／input／狀態 → 544A00 選互動點
         ↓
      vtable +0x64 = 544070
         ├─ category 3：NPC／對話資料與 UI
         ├─ category 2：ShopNo→ShopInfo→NPC／TalkBox／買賣或強化
         ├─ category 4、5：特定 Tutorial／page 分支
         └─ 某些 fallback：544020 → C2S 001C（6 bytes application）
         ↓
    Server 依當次服務／進度回覆並持久化，正常場景再入時重建集合
~~~

其中 `lb.CreateObjectEx` 放置世界角色的模型／表現，`Q.CreateObject` 管理演出專用角色，與 `0027` 的可互動 point 完全是不同容器。只有可見模型不會自動產生互動點；只有點沒有正確 NPC／ShopInfo／page context 也不保證功能 UI 可用。

## 4. S2C 0027：Server 需要發布完整的互動點集合

原 dispatcher initializer `0x4ADEAD` 將 `0x4B2AF0` 寫入 table offset `0x13C`，按 8-byte entry 得到 application opcode `0x0027`。handler `0x4B2B60` 先經 `0x5449A0` 清除舊 vector，`0x4B2B6A..0x4B2B85` 由訊息長度計算 `floor((length - 2)/18)`，沒有另一個整數 count。每筆 `0x12=18` bytes；`0x4B2BAE..D5` 將轉換值傳入 `0x543700` 建立 point。

| Row 相對位移 | 實際型別與資料 | Point 欄位／意義 |
|---|---|---|
| `+0x00` | WORD key | `+0xF6`；類別內識別，不等於世界 EntityId |
| `+0x02` | signed BYTE category | `+0xF4` WORD；類別決定本地分派 |
| `+0x03` | BYTE initial enabled | `+0x105`；建議明確 0／1 |
| `+0x04` | FLOAT x | `+0xA0`；不猜世界單位 |
| `+0x08` | FLOAT y | `+0xA4` |
| `+0x0C` | FLOAT radius | `+0xFC`；部分類別有調整 |
| `+0x10` | BYTE tail0 | `+0x100`；與觸發模式有關，具體列舉仍未知 |
| `+0x11` | BYTE tail1 | `+0xF8`；本地顯示相關分支，完整語義仍未知 |

完整 application 長度應為 `2+18*N`；這不含未在本輪分析的底層 TCP framing。原 handler 可能忽略不足整列的尾端，這不是可靠擴充機制。**重送 0027 是全量替換**，新集合必須包含當時仍需要的出口、NPC、商店、教程點等；只下發一家新店可能使其他互動點消失。

## 5. S2C 0048：可直接更新既有點，無須重送 0027

同一 dispatcher initializer `0x4ADEBD` 寫入 table `+0x244` 的 handler `0x4B32E0`，對應 `0x0048`。`0x4B3324..0x4B333F` 的 application 讀取已閉合為：

~~~text
offset  size  field
0x00     2    opcode = 0x0048
0x02     2    key (WORD)
0x04     1    category (BYTE)
0x05     1    status (BYTE)
total    6    application bytes
~~~

handler 把 `global point vector (FB79F0)` 與參數送入 `0x544940`。**它不包含 X、Y、radius、點數或模型資料**；不建立新點、不變更位置。此 handler 本身沒有額外的明顯長度驗證；Server 發送完整六位元組是必要條件。

## 6. Server 與 Lua 都能呼叫同一個 native setter

`Tutorial.SetCheckPointStatus(key, category, status)` 的原生位置是 `0x4A9460`；`0x4A94A5..B6` 最終與 S2C `0048` 的 `0x4B3333..3B` 呼叫同一個 `0x544940`。該函式走 point vector，依 `point+0xF6` 的 low WORD key 與 `point+0xF4` 的 signed category 比對；找到**第一筆**就停止，未找到靜默返回，不執行 upsert。命中後呼 `0x543B30`，把 low BYTE status 寫至 `point+0x105`，並依特定 point category 更新畫面／標記。

例如 category 0 的一條表現路徑在 `0x543BC2..C7` **精確比較 status==1**，category 4 的禁用路徑在 `0x543FC3..C9` 比 status==0。因此兼容內容工具應規範狀態值為 0／1，不要讓 arbitrary nonzero 表示各處都能正常啟動。

### 安全的順序／資料契約

1. 已有合法場景資料時，先下發完整 `0027`。
2. 在同一個版本／場景中，使用 `0048` 或正式 Lua setter 更新 `(category,key)`。
3. 不要建立重複 `(category,key)`，因為 native 只改第一個命中點。
4. 重送 `0027` 要帶最新的 enabled 快照，否則會覆蓋先前 Lua／0048 改動。
5. Server 保存權威的任務進度、商店開放條件等；Client enabled 是本地呈現狀態，不是資料庫完成證據。

## 7. 玩家在 Client 怎麼觸發這些點

`0x544730` 首先檢查 `point+0x105` 是否可用，再以 `+0xA0/+0xA4` 和 radius `+0xFC` 做距離比較，並參考觸發模式 `+0x100`、輸入狀態及 `+0x104` 既有範圍狀態。`0x544A00` 負責選取候選點，另有 controller、UI gate；存在且 enabled 並不等於任何情境都能點擊。

point 原生 vtable `0xC0F7FC+0x64` 指向 `0x544070`。這個 consumer 依類別走不同的分支：`0x54409E` category 3、`0x5443C0` category 4、`0x544401` category 5、`0x544478` category 2。category 2 查 ShopNo→ShopInfo→NPC/Town 的舊研究路徑，可到普通買賣與裝備強化原版 UI；category 3 使用 NPC 對話／表格路徑。並非所有 UI event 都存在可從任意 Lua 發出的公開 binding。

一些 fallback 於 `0x54470C` 呼 `0x544020`，在送出 guard 未封鎖時組裝 `C2S 001C` 六位元組 application：

~~~text
WORD 0x001C | WORD category | WORD key
~~~

**此路線只是部分條件下的回報**；商店與 NPC 可以先走本地 UI／對話分支而沒有相同的 001C。Server 不可把 001C 寫成「所有互動必定先送出」的統一請求。

## 8. 以能力為中心的實際用途

| 玩家需求 | 既有 Client／MEF 可做部分 | Server 必須實作或提供 |
|---|---|---|
| 場景中出現 NPC | `lb.CreateObjectEx` 建模型與世界 actor；Q 可另做走位／對白 | 模型與合法 XY、持久 NPC identity、場景進出同步 |
| NPC 暫時不能對話，劇情後開放 | category 3 已存在點可使用 Lua setter 或 0048 設 enabled | 0027 中的正確 NPC point 與條件、任務狀態與再入保存 |
| 商店先關閉後開門 | category 2 point 的 key 是 ShopNo，Lua setter／0048 可切狀態 | 店面資料、Town/NPC、貨單、服務結果、資產與重送控制 |
| 解除出口鎖定 | 已存在出口 point 的狀態可改，顯示亦有對應 native 分支 | 合法轉場、任務前置、目標 map 與存檔 |
| 操作提示及特殊教程 | category 4/5 有對應 context 分支，Lua 可編排教學效果 | 教學與 scenario 結果／進度、場景狀態、連線結果 |
| 直接變更售價、扣款或強化結果 | **未證明 Lua setter 具有此能力**；本地 UI 會顯示服務畫面 | Server 交易授權、價錢、消耗、裝備結果、背包／金錢、原子持久化 |

相關新細節已另整理為 [Server 開發交接](MEF-checkpoint-20261116/server-handoff.md)，沿用既有 `REQ-0019`／`REQ-0021` 但不自建正式 RR。

## 9. 與整個 MEF 流程的關係、未知與驗收

此支線接續 R11 已核的完整生命週期：**內容版本／依賴 → launcher／資源可見性 → 可達 SceneList／Tutorial 入口 → prepass 雙 VM → 正式 coroutine → 已存在的 script/native binding → NPC／對白／鏡頭／互動點 → 原生狀態觀察／清理／End → Server 對帳保存。**

原版 `MapList.TRIGGER → 官方 .mef 文件首次開啟／格式／executor` 尚未閉合，不能把 `0027`／`0048` 說成傳送 `.mef` 檔案的 opcode，也不能僅把 Lua 檔改名為 `.mef` 就當作原生 loader 已驗證。相容新內容必須使用已證可達入口與合法資源／actor／UI context。這條缺口保留為**Client 待逆向**，但不阻擋本輪已證的互動點控制能力透過 Server／既有 Lua 入口做整合。

- **Server 待開發**：發布完整 point snapshot、發送 delta、合法點字典與 XY/radius、劇情前置、服務／交易／轉場、重連狀態恢復及持久化。
- **跨功能待整合**：新內容 caller、prepass/formal、同場景更新順序、共享 UI owner 與取消。
- **Client 待逆向**：真正原生 MEF 入口／grammar；任何想新增而本輪未證明的任意 point 產生器或腳本可回傳服務結果接口。
- **待遊玩驗證**：合法場景首次 0027→0048／Lua 啟用→玩家靠近→原 UI／C2S→Server 業務完成→換場後重新下發的正常流程；本輪沒有啟動或修改 Client／Lua／Server。

[靜態驗證結果](MEF-checkpoint-20261116/verification-result.json) 只驗明確節錄的原件與協定形狀，不等同 T01 FULL-PASS、RR ACCEPTED、可部署新腳本或遊玩完成。
