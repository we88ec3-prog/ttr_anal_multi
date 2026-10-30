# E61 — KR T03 RR-0002：角色名單、選角 C→S 與 S→C 候選的 BIN-first 有界證據和未閉合回覆

> **研究狀態：階段性原生調查，RR-0002 整體靜態目標尚未閉合。** 本稿不得當成「選角 S→C 成功／失敗回覆已證」或「登入角色已進入廣場」。使用者指定所有研究技術原稿與工作提交都歸 `extra/roy1`，未開設其它研究分支。正式 RR 台帳的狀態屬共享 `main` 權威紀錄，與技術研究分支分離。請勿因報告完成即標為 S00 ACCEPTED／T01 FULL-PASS。

## 0. 來源、任務與研究終點

- KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新執行唯讀 SHA256 檢查；未執行、修補或連線原版 Client。
- PE32 x86，`.text` VA `0x401000`、raw `0x400`、size `0x7D01F0`，本次反組譯由 BIN 原始 bytes `[0x400:0x7D05F0]` 裁取後 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`；只對 `.text` 有 `raw=VA-0x400C00`。**不要拿這個公式換算 `.rdata` 或 `.data`。**
- RR `question`：Which C2S selection fields and S2C reply fields/order does original Client require? Preserve unknown values; reuse T02/T04 contracts.
- RR `acceptance_criteria`：Complete command2 header fields, role record authority and initialization prerequisites, actual selection request+responses and scene transition with scoped evidence and relevant Client tests. GAP-CHAR-0001.
- 專責界線：T03 業務封包／角色 UI；T02 framing/IOCP/connection，T04 真實角色狀態、T05 真正世界轉場、T06 UI 資源身份只引用來源不主張已自行驗完。原版 Server 內部認證／角色權威決策未提供原件。
- 本研究沿用受限來源：`kr/evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt`（已打包局部 roster 審核）、`unclassified/evidence/292f798fe04079370dd65d31a03b7cca5a14a84a9524da3903a25d6ff6c10047.txt`（含舊有本機合成 Server 和截圖觀察，**不是官方封包規格**）、`kr-temp-roy/20261028-204757-chatgpt-web-roy-T03-3-command42-selection-callback.md`、T02 RR-0007/E60（callback 路由）；本次新增獨立 BIN 指令核對與負向排除，未把舊原稿全部升級 FULL-PASS。
- T03 README 既有 `T01-RETURN-T03-006-LAYOUT-001 — NEEDS_FIX`（WSABUF／OVERLAPPED／A0B8 命名混淆）尚未修復；本 RR 依使用者指定優先，沒有修改或解除它。

## 1. 玩家端完整目標與已證／未知矩陣

| 事件 | Native 正證 | 必要限制／負向證據 | 層級 |
|---|---|---|---|
| 伺服器提供角色初始化資料 | `S2C app cmd=0x0002` 的第一層 table slot → `0x4B7F00`；`0x4B8923..4B89B2` 由 `(length-65)//53` 遍歷 `payload+0x41`，角色 ID byte `row+0x2E`，`ID<=9` 且 record pointer 非零時 `0x4D4150` | `length>=65` 本身不保證前部多個較高 offset 的早期讀取安全；沒有身分權威和端點綁定證據 | N：有界資料 flow |
| 角色記錄寫入 UI 可用旗標 | `0x4D4154` `record+0x5C=1`；`+0x0C` 寫 UTF-16 NUL 名稱、另寫 `+4/+8/+50/+D4/+DC` | `0x4D4150` UTF-16 迴圈沒有明確最大字元界限；來源必須含有效 NUL 且有足夠目的空間 | N：有界 copy |
| 選角確認本地 C2S payload | `0x4A3B80` 建 `42 00 XX YY`，送 manager `virtual+0x10(key=0,&buffer,length=4)` | `FBA798==0` gate；本地 enqueue 不等於 WSASend/wire；`XX/YY` 不能自行命名成官方角色 ID、世界或模式 | N：本地請求 |
| UI 選角入口一 | `0x5F46D0` `0x70A` event、control identity、index 範圍、`record+0x5C` 可用後調 `0x4A3B80(index,0)` | event ID `0x70A` 不是 wire opcode；data pointer／UI control 有先決狀態；呼叫成功不等於 Server 允許 | N：條件路徑 |
| UI 選角入口二 | 同函式 `0x578` 部分控件分支 `0x4A3B80(savedIndex,0／2)`，並設 `receiver+0xCC=1` | 同函式內分支未同樣檢查 `record+5C`；不能合併成入口一的所有前提 | N：不同 caller |
| UI 選角入口三 | `0x673DA0` `event+0x10==0x578` 且 `event+8==receiver+DC control+0x20` 時 `0x4A3B80(receiver+D8,0)` | 另一支 `receiver+C0` 導致本地 `F42EF` 事件，與 C→S 發送不可混淆 | N：另一入口 |
| 可接收 S2C command0x42 | 第一層 fallback／active scene／base table index `0x42→0x4B2190`；`0x4B2190` 以 payload+2 的 signed WORD 操作清單／狀態 | 沒有連到 C2S 0x42 的選角批准、角色進入世界 writer；負向查對直接入口與 callee | N：候選排除界線 |
| 可接收 S2C command0x43 | base table index `0x43→0x4B1A90`；它走 `0x40F060(6)→0x4DFD40` | 它是本地型別6相關資料／效果移除工作，不能由 request+1 推成選角成功回覆 | N：候選排除界線 |
| 正式選角批准／拒絕 S2C | **未確認正向 opcode／最小長度／狀態／角色身份和次序** | 現有 0x42/0x43 候選各有其它已證用途；需辨識真正的高階 stage/state writer 或合法原版互動 trace | **U：RR-0002 核心未閉合** |
| 實際進入場景 | `0x47B5C0` 條件下以 `object+0x248` 和外部 arg 呼叫 `0x565720`；這條也與 EndCutScene 的再用路徑共存 | **沒有證**「收到選角回覆 → 寫入 object+248 → 選定 `(questIdx,sceneIdx)`」；`1001/1` XML 值不是 wire payload | U：另需 RR-0008/T05 |

N 指 first-hand BIN 中限定分支的事實；C 是舊資料的有界共識；U 是目前尚未由 Client 原生完成的跨邊界條件。合成 Python fixture、帳號角色授權、固定 1..9 擁有權、暫定廣場成功碼都不是 native MUST。

## 2. `0x0002` 長表頭與 53-byte 記錄的正向資料流

### 2.1 `0x4B7F00` 不是「只有角色清單」的單用途 handler

`0x4B7F00` 是第一層 app command2 覆寫的專用 handler，但前段還讀多個全域和來源 offset（如 `+2/+0x0C/+0x36/+0x38/+0x3A/+0x3C`），更新初始化欄位。`0x4B8923` 在 `[ebp+0xC]` 傳來的長度 `<0x41` 時把 row count 設成 0；否則對 `n=(len-65)` 乘 `0x3521CFB3`，用乘法高位轉換實作除 `53`，再從 `payload+0x6F` 讀角色 ID（因為實際 row 首地址 `payload+0x41`，其 `+0x2E` 為 `+0x6F`）。`0x4B8A0E add edi,0x35` 每筆前進53。**長度為0的角色列表只是在迴圈不執行，不能證明前面各欄位讀取對截短 payload 安全。**

- `0x4B8992` 從 record+0x2E 讀 unsigned role index，`cmp eax,9` 只做上界，不證 Server 接受所有0..9。
- `0x4B899A` `index*0x210`、`0x4B89A0 add [F94304]` 定位 record slot；不允許未給來源就臆造 `0xF94304` 如何與其它所有角色表 alias。
- `0x4B89A8 lea edx,[edi-0x2E]` 精確回指本筆 row 首 byte；`0x4B89AD call 0x4D4150` 把 row 存入 slot。
- `0x4B89E1..4B8A00` 對該角色 ID 組 WORD `0x0026` + ID（3-byte C2S、key0），但受 FBA798 控制；它並非「Server 已批准選角」。
- `0x4B8A02..4B8A16` 的角色 bitmask 只按 `ID-1` 左移，再在 `0x4B8A60` 存 `F94240`；上界 check 放在 copy 前但位移的地方沒有相同 guard，不能將行為等同安全地驗證 ID1..9。
- `0x4B8A9C call 0x4E5FB0` 是 roster 後 rank／UI 效果相關方法，不是已證「切換場景」，其具體 UI 控件仍屬 T06。
- 本 handler 後面還有多個 key0 短命令和一筆 key2 訊息，故收到 cmd2 不等於某單一固定首包或全部 bootstrap 完成。

### 2.2 `0x4D4150` 53-byte row 欄位與應用記錄映射

| 原始 row offset | native 寫入目的 | 何者已知／不可偷猜 |
|---|---|---|
| `+0x00` | `record+0x0C` UTF-16 NUL terminated | 無 bounded-copy 的明確 word 上限；合法 row 必須在足夠來源內終止 |
| `+0x2A` DWORD | `record+0x08` DWORD | 值可能用於等級等系統，但此處不確認官方初值 |
| `+0x2E` BYTE | `record+0x04` DWORD | UI role index 的本地目的；並用來選擇 `index *0x210` |
| `+0x2F` BYTE | `record+0xD4` DWORD | 此處只有欄位 copy，可見原生語意未知 |
| `+0x30` BYTE | `record+0xDC` DWORD | 同上 |
| `+0x31` DWORD | `record+0x50` DWORD | 不對齊讀取，最高到來源 `+0x34`；不能憑合成 fixture 填全零 |
| always | `record+0x5C=1` | 是 Client UI 可用 flag，不代表 Server 取得角色授權的完整判斷 |

舊程式的本機 fixture 曾合成 `LocalHero/等級1/特定角色 ID` 並觀察灰色頭像變彩色、模型顯示，但『廣場按鈕仍無反應』；該觀察可作否證：「清單旗標已設，不保證選角／場景可玩」，並非本輪重新執行原版 Client 的 runtime 證據。來源是 `unclassified/evidence/292f798...txt`，需保留當次所用修改 Client／測試 Server 的差異。

### 2.3 另一個清單入口不能冒充同一 wire layout

`0x4E2730` 是同樣 `0x4D4150` 的另一個 caller，但用 `length>=2` 後 `floor((length-2)/53)` 及 `payload+2` 起始逐筆讀 row，並從 `client+0x6924` 選 record 基底。入口透過 `receiver+0x15C` 等間接方法到達；**不能把 2-byte prefix 與 cmd2 的65-byte prefix 混為同一個 payload 格式，更不能用無直接 CALL 來否定虛擬可達性。**

## 3. `0x0042` C→S selection 的三個 UI producer 與 guard

`0x4A3B80` 從 `[ebp+8]`、`[ebp+0xC]` 各取最低 BYTE，與 16-bit `0x42` 組成 `42 00 XX YY`；只有 `dword [0xFBA798]==0` 才 call `[manager vptr+0x10]`，push `4`、push `&buffer`、push `0`，`ret8`。未證 `XX` 等同 DB character ID 或畫面上顯示之個別角色等級。合成輸入例 `XX=1,YY=0` 的 payload `42 00 01 00` 只供測試 C2S builder geometry；沒有原版 Server 回應配對。

`0x5F46D0` 的 `0x70A` 分支 `0x5F477E` 要求事件 control identity 與某個 UI 物件的 `+0x20` 相符、選出的 local index 在上界且對應 record+0x5C 非零，隨後 `0x5F47F5` call `0x4A3B80`；`0x578` 分支又可使用保留的 `receiver+0xC8` index、不同的第二 byte（0/2）與 `receiver+0xCC` 本地旗標。不能把不同分支的 guard 無條件合併。`0x673DA0` 的 `0x578`/`receiver+0xDC` control identity match 使用 `receiver+0xD8`，第二 byte為0，沒有出現相同+5C gate；另外 C0 控件分支僅產生 `0xF42EF` **本地 UI 事件**，不能認作 S2C／C2S opcode。

下層 T02 已證 `vtable+0x10` 可進 Manager send queue/framing，仍可能 backpressure、conn 不存在、WSASend pending。**此處只證本地 send request 的入口，不是封包已到達 Server。**

## 4. S→C command `0x0042/0x0043` 的 handler：負向限定查證

### 4.1 場景次表沒有 `0x42` 不代表整個 Client 沒有

T02/E60 的原生路由需要有效 decoded payload、lane2 callback、ActiveScene + 正確 vptr 方可進場景分派。登入場景第二表 `0x4C3220` 不直接覆寫 `0x42`；但基底 handler 表 `0x4ADD50` 在 `0x4ADF3D` 對 `(0x214-4)/8=0x42` 寫 `0x4B2190`，在 `0x4ADE31` 對 `(0x21C-4)/8=0x43` 寫 `0x4B1A90`。這兩個是**真正可經 table 派送的 S2C app command 候選**，不能以其存在判斷有選角成功配對。

### 4.2 `0x4B2190`（S2C 0x42）的已證輸入副作用

它從 `[payload+2]` 讀 `signed WORD`（`0x4B21FD`），調用 `0x500110` 處理表／容器；若 `[ebp+0xC]` 長度 `>4`，從 `payload+5` 讀一 BYTE 做 `byte-1` switch（上界 `<=10`），然後沿跳表調整 payload cursor／所需長度，部分路徑檢查 `[esi]==9` 並可能 `0x53D840` 傳遞資料到另一集合。流程最後回0。**沒在該函式可見直接 CFG 內呼叫 `0x47B5C0`、`0x565720` 或設定角色世界啟用完成狀態；但不得將無直接呼叫誇成全域沒有間接轉場。**

檢查提醒：跳轉表位於 `.text` 函式尾部 `0x4B22E0..0x4B230B`；那是 switch target DWORD 不是合法連續 x86 指令，附錄只列主函式至 `ret0xC`，不要把 data 虛構成程式執行。

### 4.3 `0x4B1A90`（S2C 0x43）的已證副作用

真正入口 `0x4B1A90` 僅 `push6`、`call0x40F060`（取某類 singleton/object）、`mov ecx,eax`、`call0x4DFD40` 然後 `xor eax,eax; ret 0xC`；`0x4DFD40` 遍歷一個帶有 `+4` 類型的容器，配合時間／可用成員及執行虛呼叫，移除或重置符合類型的物件。這不能被直接解讀成「選角成功」或「進世界」；它有與選角不同的有界效果。也不代表外部不會另發此 command。

**因此：未證 S2C 的 opcode `0x42` 是 C2S `0x42` 的合法回覆，更未證 `0x43` 或舊合成 fixture 的 `0x69` 是批准訊息。** 需要真正的角色選角結果所依附的 handler／狀態 writer 與時間因果，不能單從整數相同、相鄰或命名猜測。

## 5. Scene／First tutorial 交界，嚴格限於引證

`extra/roy1` E06/E08/E13/E16 已記錄 XML `(questIdx=1001, sceneIdx=1)→tutorial_start`、相關 `.seq` 及兩個 `(questIdx,sceneIdx)` 查表 reader。當次原生 E16 還證 `0x565720` 有兩個 direct E8 caller：`0x47B64A` 與 `0x561EF3`；`0x47B5C0` 檢查 object+`0x248 == 0xEA61` 的特殊路徑或將 object+`0x248` 和外部 arg 傳到 `0x565720`，但 `0x561EF3` 是 EndCutScene 回收／重入。這是「查表讀場景」的 *consumer*，不是「Server 選角成功 writer」。因此不可以把 `1001/1` 或 `0xEA61` 塞入任意 S2C 欄位，聲稱能強迫第一次進教學。更精確的上游 writer 與 scene key 依 RR-0008/T05；本 RR-0002 保留必要相依，不代替它驗收。

## 6. 反例與結案判準／精確未解

### 已排除的輕率假說

1. **「顯示彩色可選角色即已能進世界」不成立**：role record+5C 寫入的本地必要條件不包含世界/場景初始化的整個流程；既有修改環境的 UI 測試也觀察到未可進入廣場。
2. **「C2S 42 的回覆必定 S2C 43」未證**：0x43 的原生 handler 是 type6 related object removal，沒有正向配對證據。
3. **「只看 LOGIN scene table 沒有 42，所以 S2C42 不存在」錯誤**：base scene table 0x42 確實對應 0x4B2190。
4. **「0x42 reply 看到資料更新代表選角批准」未證**：`0x4B2190` 是帶可變子項的容器操作，未證更新選角批准或場景。
5. **「65-byte prefix 的補齊值都可以填零」未證**：長函式前段讀取 header fields、部分資源及全域狀態，合成伺服器不應把填零當官方契約。
6. **「所有 UI click 都經 record+5C guard」錯誤**：三個 0x4A3B80 direct caller 的前置 guard 不完全相同。

### 尚不能以目前證據宣告完整的 RR acceptance

- **Client 待逆向**：真正選角批准／拒絕回覆的 opcode、payload byte ranges、方向、Conn/lane、最小長度；哪個 S2C handler 將它轉成本地選角接受 state；`0x47B5C0` 的 object+0x248 writer 是否由此 state 驅動。當前已沿 `4B2190/4B1A90` 的直接 caller/callee、base/scene tables、C2S 全部三個直接 caller、roster 兩入口追查；未有可肯定的 pairing。**不是聲稱所有 Client 直接／間接路徑不存在**。
- **Server 待開發**：角色擁有權與角色資訊權威、選角申請的授權、拒絕時狀態處理及何種 S2C 內容滿足已確認 Client consumer；不能自行模仿舊本機「LocalHero、ID1、全零其餘欄位」冒稱官方。
- **跨功能待整合**：T02 E57～E60 的 framing/dispatcher（應確認來源 blob）、T04 角色初值與可用權威、T05 場景世界轉入、T06 UI 實際資源、RR-0008 初次教學／script key writer；本段不修改他們的原稿。
- **待遊玩驗證**：需獲明確授權並取得合法的原版 Client 實際連線執行 trace，記錄選角前後的 key/Conn、實際已解 frame、命令與場景前後 state；沒有這份證據不能從本地 Server 的合成輸出回推原版 Server 策略。

### 下一步解除條件與研究方向

1. 對 `0x47B5C0` state+0x248 的**正向 writer**（不是僅直接 `0x248` bytes 搜尋，該 displacement 過度普遍）建立 owner identity、memory alias 和實際 inbound caller；需從 scene object constructor/virtual callbacks 做 pointer provenance。
2. 對 base scene `0x4ADD50` 的全表與登入場景 `0x4C3220` 的次表依確切槽位分類與角色進入／選角結果真正相關的非 42／43 命令；排除資源效果系統或 UI 同值事件的誤判。
3. 查`0x4B2190` 的 `0x500110→0x53D840` 資料容器是否有可證的角色/場景狀態 consumer；若始終只觸及效果／通知表，縮小候選。
4. 查 T04/T05 已驗證的角色/場景可用狀態 writer 與 S2C callback xref，而不是以 request+1 或固定 tutorial 1001/1 代替。
5. 若上述靜態正向 writer/consumer 確實無法確立回覆配對，列出查證入口及允許的 Runtime trace 錨點給 S00；**目前 RR 應保持 `IN_PROGRESS` 或精確 `BLOCKED`，不能自行宣稱整體目標完成並 SUBMITTED。**

## 7. 給 T01／S00 的有限規格及測試需求

| 欄位／測試 | 可採用的限定 native 事實 | 不可擅自升格事項 |
|---|---|---|
| `SPEC-CHAR-0001` C2S | local `42 00 XX YY`，length4、vtable send key0、FBA798 gate、三種 caller | 不是原版 Server selection approval order；未知 XX 身分語意 |
| `SPEC-CHAR-0001` roster | cmd2 限定 length>=65 後依53-byte row 遍歷，row+2E role index，record+5C flag | prefix全欄位合法性與任意合法角色初值仍未知 |
| `SPEC-FLOW-0001` S2C candidate | 0x42/0x43 的 base scene handlers/有限輸入副作用已可定位 | 不得把其中一個寫為選角成功／錯誤 MUST |
| `SPEC-SCENE-0001` | `0x47B5C0→0x565720` 是有條件的場景雙鍵 caller、EndCutScene 另有再入 | 不是選角後必啟動 `tutorial_start` 的證據 |
| TEST synthetic | `42 00 01 00`、valid NUL terminated 53-byte row、`len=65+53N` 可以當格式測試材料 | **synthetic != 原版抓包**；沒有連線與場景 runtime 正證不能算可玩／相容驗收 |

## 8. 工具重現與驗證界線

```bash
sha256sum Tartaros.bin
python -c "from pathlib import Path; b=Path('Tartaros.bin').read_bytes(); Path('text.bin').write_bytes(b[0x400:0x400+0x7d01f0])"
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4A3B80 --stop-address=0x4A3BC0 text.bin
```

附錄所有反組譯都基於上述原始 `.text` byte 裁切。函式界限只按確定的 prologue、ret、INT3 及既有條件 jump 分界截取；含機器碼／未知 helper 語意，不依反編譯器類別猜測改名。表內的 synthetic bytes 僅是由已證幾何建立的人工向量，不是 runtime 封包。

### A.1 `0x4A3B80` C2S 42 實際 4-byte builder

- `.text` VA `0x004A3B80..0x004A3BBF`；raw `0x000A2F80..0x000A2FBF`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2 08 00             	ret    0x8
  4a3bbd:	cc                   	int3
  4a3bbe:	cc                   	int3
  4a3bbf:	cc                   	int3
```

### A.2 `0x5F46D0` UI 0x70A/0x578 串角色可用旗標及兩種第二 byte

- `.text` VA `0x005F46D0..0x005F490F`；raw `0x001F3AD0..0x001F3D0F`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  5f46d0:	55                   	push   ebp
  5f46d1:	8b ec                	mov    ebp,esp
  5f46d3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5f46d6:	56                   	push   esi
  5f46d7:	8b f1                	mov    esi,ecx
  5f46d9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  5f46dc:	81 e9 78 05 00 00    	sub    ecx,0x578
  5f46e2:	0f 84 17 01 00 00    	je     0x5f47ff
  5f46e8:	81 e9 92 01 00 00    	sub    ecx,0x192
  5f46ee:	0f 84 8a 00 00 00    	je     0x5f477e
  5f46f4:	49                   	dec    ecx
  5f46f5:	0f 85 08 02 00 00    	jne    0x5f4903
  5f46fb:	8b 8e 84 00 00 00    	mov    ecx,DWORD PTR [esi+0x84]
  5f4701:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5f4704:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f4707:	0f 85 f6 01 00 00    	jne    0x5f4903
  5f470d:	8b 81 cc 00 00 00    	mov    eax,DWORD PTR [ecx+0xcc]
  5f4713:	85 c0                	test   eax,eax
  5f4715:	74 0f                	je     0x5f4726
  5f4717:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  5f471d:	85 c0                	test   eax,eax
  5f471f:	74 05                	je     0x5f4726
  5f4721:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  5f4724:	eb 03                	jmp    0x5f4729
  5f4726:	83 c8 ff             	or     eax,0xffffffff
  5f4729:	40                   	inc    eax
  5f472a:	6a 18                	push   0x18
  5f472c:	89 86 c8 00 00 00    	mov    DWORD PTR [esi+0xc8],eax
  5f4732:	e8 31 cb 29 00       	call   0x891268
  5f4737:	83 c4 04             	add    esp,0x4
  5f473a:	85 c0                	test   eax,eax
  5f473c:	0f 84 0c 01 00 00    	je     0x5f484e
  5f4742:	8b b6 c8 00 00 00    	mov    esi,DWORD PTR [esi+0xc8]
  5f4748:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  5f474b:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f4752:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f4759:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f4760:	c7 40 10 46 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4246
  5f4767:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  5f476d:	8b f0                	mov    esi,eax
  5f476f:	e8 2c 03 e1 ff       	call   0x404aa0
  5f4774:	e8 a7 b8 15 00       	call   0x750020
  5f4779:	5e                   	pop    esi
  5f477a:	5d                   	pop    ebp
  5f477b:	c2 04 00             	ret    0x4
  5f477e:	8b 8e 84 00 00 00    	mov    ecx,DWORD PTR [esi+0x84]
  5f4784:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  5f4787:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  5f478a:	0f 85 73 01 00 00    	jne    0x5f4903
  5f4790:	8b 81 cc 00 00 00    	mov    eax,DWORD PTR [ecx+0xcc]
  5f4796:	85 c0                	test   eax,eax
  5f4798:	74 0f                	je     0x5f47a9
  5f479a:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  5f47a0:	85 c0                	test   eax,eax
  5f47a2:	74 05                	je     0x5f47a9
  5f47a4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  5f47a7:	eb 03                	jmp    0x5f47ac
  5f47a9:	83 c8 ff             	or     eax,0xffffffff
  5f47ac:	40                   	inc    eax
  5f47ad:	89 86 c8 00 00 00    	mov    DWORD PTR [esi+0xc8],eax
  5f47b3:	e8 e8 03 e1 ff       	call   0x404ba0
  5f47b8:	8b 88 24 69 00 00    	mov    ecx,DWORD PTR [eax+0x6924]
  5f47be:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f47c4:	83 f8 09             	cmp    eax,0x9
  5f47c7:	0f 87 36 01 00 00    	ja     0x5f4903
  5f47cd:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  5f47d3:	03 c1                	add    eax,ecx
  5f47d5:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  5f47d9:	0f 84 24 01 00 00    	je     0x5f4903
  5f47df:	85 c0                	test   eax,eax
  5f47e1:	0f 84 1c 01 00 00    	je     0x5f4903
  5f47e7:	e8 94 fe e1 ff       	call   0x414680
  5f47ec:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f47f2:	6a 00                	push   0x0
  5f47f4:	50                   	push   eax
  5f47f5:	e8 86 f3 ea ff       	call   0x4a3b80
  5f47fa:	5e                   	pop    esi
  5f47fb:	5d                   	pop    ebp
  5f47fc:	c2 04 00             	ret    0x4
  5f47ff:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5f4802:	8b 8e bc 00 00 00    	mov    ecx,DWORD PTR [esi+0xbc]
  5f4808:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f480b:	75 52                	jne    0x5f485f
  5f480d:	6a 14                	push   0x14
  5f480f:	e8 54 ca 29 00       	call   0x891268
  5f4814:	83 c4 04             	add    esp,0x4
  5f4817:	85 c0                	test   eax,eax
  5f4819:	74 33                	je     0x5f484e
  5f481b:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  5f4821:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f4828:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f482f:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f4836:	c7 40 10 48 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4248
  5f483d:	8b f0                	mov    esi,eax
  5f483f:	e8 5c 02 e1 ff       	call   0x404aa0
  5f4844:	e8 d7 b7 15 00       	call   0x750020
  5f4849:	5e                   	pop    esi
  5f484a:	5d                   	pop    ebp
  5f484b:	c2 04 00             	ret    0x4
  5f484e:	33 f6                	xor    esi,esi
  5f4850:	e8 4b 02 e1 ff       	call   0x404aa0
  5f4855:	e8 c6 b7 15 00       	call   0x750020
  5f485a:	5e                   	pop    esi
  5f485b:	5d                   	pop    ebp
  5f485c:	c2 04 00             	ret    0x4
  5f485f:	8b 96 b4 00 00 00    	mov    edx,DWORD PTR [esi+0xb4]
  5f4865:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  5f4868:	75 16                	jne    0x5f4880
  5f486a:	80 be cc 00 00 00 00 	cmp    BYTE PTR [esi+0xcc],0x0
  5f4871:	0f 85 8c 00 00 00    	jne    0x5f4903
  5f4877:	e8 04 fe e1 ff       	call   0x414680
  5f487c:	6a 00                	push   0x0
  5f487e:	eb 70                	jmp    0x5f48f0
  5f4880:	8b 8e c0 00 00 00    	mov    ecx,DWORD PTR [esi+0xc0]
  5f4886:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  5f4889:	75 4a                	jne    0x5f48d5
  5f488b:	6a 14                	push   0x14
  5f488d:	e8 d6 c9 29 00       	call   0x891268
  5f4892:	83 c4 04             	add    esp,0x4
  5f4895:	85 c0                	test   eax,eax
  5f4897:	74 2e                	je     0x5f48c7
  5f4899:	8b f0                	mov    esi,eax
  5f489b:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  5f48a1:	c7 40 04 ff ff ff ff 	mov    DWORD PTR [eax+0x4],0xffffffff
  5f48a8:	c7 40 08 ff ff ff ff 	mov    DWORD PTR [eax+0x8],0xffffffff
  5f48af:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  5f48b6:	c7 40 10 fe 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43fe
  5f48bd:	e8 de 29 e1 ff       	call   0x4072a0
  5f48c2:	5e                   	pop    esi
  5f48c3:	5d                   	pop    ebp
  5f48c4:	c2 04 00             	ret    0x4
  5f48c7:	33 c0                	xor    eax,eax
  5f48c9:	8b f0                	mov    esi,eax
  5f48cb:	e8 d0 29 e1 ff       	call   0x4072a0
  5f48d0:	5e                   	pop    esi
  5f48d1:	5d                   	pop    ebp
  5f48d2:	c2 04 00             	ret    0x4
  5f48d5:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  5f48db:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  5f48de:	75 23                	jne    0x5f4903
  5f48e0:	80 be cc 00 00 00 00 	cmp    BYTE PTR [esi+0xcc],0x0
  5f48e7:	75 1a                	jne    0x5f4903
  5f48e9:	e8 92 fd e1 ff       	call   0x414680
  5f48ee:	6a 02                	push   0x2
  5f48f0:	8b 86 c8 00 00 00    	mov    eax,DWORD PTR [esi+0xc8]
  5f48f6:	50                   	push   eax
  5f48f7:	e8 84 f2 ea ff       	call   0x4a3b80
  5f48fc:	c6 86 cc 00 00 00 01 	mov    BYTE PTR [esi+0xcc],0x1
  5f4903:	5e                   	pop    esi
  5f4904:	5d                   	pop    ebp
  5f4905:	c2 04 00             	ret    0x4
  5f4908:	cc                   	int3
  5f4909:	cc                   	int3
  5f490a:	cc                   	int3
  5f490b:	cc                   	int3
  5f490c:	cc                   	int3
  5f490d:	cc                   	int3
  5f490e:	cc                   	int3
  5f490f:	cc                   	int3
```

### A.3 `0x673DA0` 第三個 C2S caller 與 F42EF local event

- `.text` VA `0x00673DA0..0x00673F61`；raw `0x002731A0..0x00273361`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  673da0:	55                   	push   ebp
  673da1:	8b ec                	mov    ebp,esp
  673da3:	6a ff                	push   0xffffffff
  673da5:	68 3c 62 91 00       	push   0x91623c
  673daa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  673db0:	50                   	push   eax
  673db1:	56                   	push   esi
  673db2:	57                   	push   edi
  673db3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  673db8:	33 c5                	xor    eax,ebp
  673dba:	50                   	push   eax
  673dbb:	8d 45 f4             	lea    eax,[ebp-0xc]
  673dbe:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  673dc4:	8b f1                	mov    esi,ecx
  673dc6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  673dc9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  673dcc:	81 f9 78 05 00 00    	cmp    ecx,0x578
  673dd2:	0f 85 ea 00 00 00    	jne    0x673ec2
  673dd8:	8b 8e c0 00 00 00    	mov    ecx,DWORD PTR [esi+0xc0]
  673dde:	8b 49 20             	mov    ecx,DWORD PTR [ecx+0x20]
  673de1:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  673de4:	3b c1                	cmp    eax,ecx
  673de6:	0f 85 a1 00 00 00    	jne    0x673e8d
  673dec:	6a 18                	push   0x18
  673dee:	e8 75 d4 21 00       	call   0x891268
  673df3:	83 c4 04             	add    esp,0x4
  673df6:	83 cf ff             	or     edi,0xffffffff
  673df9:	85 c0                	test   eax,eax
  673dfb:	74 27                	je     0x673e24
  673dfd:	8b b6 d8 00 00 00    	mov    esi,DWORD PTR [esi+0xd8]
  673e03:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  673e06:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  673e09:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  673e0c:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  673e13:	c7 40 10 ef 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42ef
  673e1a:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  673e20:	8b f0                	mov    esi,eax
  673e22:	eb 02                	jmp    0x673e26
  673e24:	33 f6                	xor    esi,esi
  673e26:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  673e2d:	75 23                	jne    0x673e52
  673e2f:	83 0d d0 ad fa 00 01 	or     DWORD PTR ds:0xfaadd0,0x1
  673e36:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  673e3d:	e8 4e 9b 0d 00       	call   0x74d990
  673e42:	68 70 cc bc 00       	push   0xbccc70
  673e47:	e8 ce e4 21 00       	call   0x89231a
  673e4c:	83 c4 04             	add    esp,0x4
  673e4f:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  673e52:	8b 0d d4 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bd4
  673e58:	85 c9                	test   ecx,ecx
  673e5a:	74 0b                	je     0x673e67
  673e5c:	8b 11                	mov    edx,DWORD PTR [ecx]
  673e5e:	8b 82 5c 01 00 00    	mov    eax,DWORD PTR [edx+0x15c]
  673e64:	56                   	push   esi
  673e65:	ff d0                	call   eax
  673e67:	85 f6                	test   esi,esi
  673e69:	0f 84 e0 00 00 00    	je     0x673f4f
  673e6f:	8b 16                	mov    edx,DWORD PTR [esi]
  673e71:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  673e74:	6a 01                	push   0x1
  673e76:	8b ce                	mov    ecx,esi
  673e78:	ff d0                	call   eax
  673e7a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  673e7d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  673e84:	59                   	pop    ecx
  673e85:	5f                   	pop    edi
  673e86:	5e                   	pop    esi
  673e87:	8b e5                	mov    esp,ebp
  673e89:	5d                   	pop    ebp
  673e8a:	c2 04 00             	ret    0x4
  673e8d:	8b 8e dc 00 00 00    	mov    ecx,DWORD PTR [esi+0xdc]
  673e93:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  673e96:	0f 85 b3 00 00 00    	jne    0x673f4f
  673e9c:	e8 df 07 da ff       	call   0x414680
  673ea1:	8b 96 d8 00 00 00    	mov    edx,DWORD PTR [esi+0xd8]
  673ea7:	6a 00                	push   0x0
  673ea9:	52                   	push   edx
  673eaa:	e8 d1 fc e2 ff       	call   0x4a3b80
  673eaf:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  673eb2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  673eb9:	59                   	pop    ecx
  673eba:	5f                   	pop    edi
  673ebb:	5e                   	pop    esi
  673ebc:	8b e5                	mov    esp,ebp
  673ebe:	5d                   	pop    ebp
  673ebf:	c2 04 00             	ret    0x4
  673ec2:	81 f9 87 03 00 00    	cmp    ecx,0x387
  673ec8:	0f 85 81 00 00 00    	jne    0x673f4f
  673ece:	6a 14                	push   0x14
  673ed0:	e8 93 d3 21 00       	call   0x891268
  673ed5:	83 c4 04             	add    esp,0x4
  673ed8:	83 cf ff             	or     edi,0xffffffff
  673edb:	85 c0                	test   eax,eax
  673edd:	74 1e                	je     0x673efd
  673edf:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  673ee5:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  673ee8:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  673eeb:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  673ef2:	c7 40 10 47 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4247
  673ef9:	8b f0                	mov    esi,eax
  673efb:	eb 02                	jmp    0x673eff
  673efd:	33 f6                	xor    esi,esi
  673eff:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  673f06:	75 23                	jne    0x673f2b
  673f08:	b8 01 00 00 00       	mov    eax,0x1
  673f0d:	09 05 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,eax
  673f13:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  673f16:	e8 75 9a 0d 00       	call   0x74d990
  673f1b:	68 70 cc bc 00       	push   0xbccc70
  673f20:	e8 f5 e3 21 00       	call   0x89231a
  673f25:	83 c4 04             	add    esp,0x4
  673f28:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  673f2b:	8b 0d d4 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bd4
  673f31:	85 c9                	test   ecx,ecx
  673f33:	74 0b                	je     0x673f40
  673f35:	8b 01                	mov    eax,DWORD PTR [ecx]
  673f37:	8b 90 5c 01 00 00    	mov    edx,DWORD PTR [eax+0x15c]
  673f3d:	56                   	push   esi
  673f3e:	ff d2                	call   edx
  673f40:	85 f6                	test   esi,esi
  673f42:	74 0b                	je     0x673f4f
  673f44:	8b 06                	mov    eax,DWORD PTR [esi]
  673f46:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  673f49:	6a 01                	push   0x1
  673f4b:	8b ce                	mov    ecx,esi
  673f4d:	ff d2                	call   edx
  673f4f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  673f52:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  673f59:	59                   	pop    ecx
  673f5a:	5f                   	pop    edi
  673f5b:	5e                   	pop    esi
  673f5c:	8b e5                	mov    esp,ebp
  673f5e:	5d                   	pop    ebp
  673f5f:	c2 04 00             	ret    0x4
```

### A.4 `0x4B8920` cmd2 length/row cursor/record copy/26 sender

- `.text` VA `0x004B8920..0x004B8AA2`；raw `0x000B7D20..0x000B7EA2`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4b8920:	83 ce ff             	or     esi,0xffffffff
  4b8923:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8926:	83 f9 41             	cmp    ecx,0x41
  4b8929:	73 04                	jae    0x4b892f
  4b892b:	33 c9                	xor    ecx,ecx
  4b892d:	eb 13                	jmp    0x4b8942
  4b892f:	83 c1 bf             	add    ecx,0xffffffbf
  4b8932:	b8 b3 cf 21 35       	mov    eax,0x3521cfb3
  4b8937:	f7 e1                	mul    ecx
  4b8939:	2b ca                	sub    ecx,edx
  4b893b:	d1 e9                	shr    ecx,1
  4b893d:	03 ca                	add    ecx,edx
  4b893f:	c1 e9 05             	shr    ecx,0x5
  4b8942:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  4b8949:	00 
  4b894a:	85 c9                	test   ecx,ecx
  4b894c:	0f 84 ce 00 00 00    	je     0x4b8a20
  4b8952:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  4b8956:	83 c7 6f             	add    edi,0x6f
  4b8959:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4b895d:	bb 1d 00 00 00       	mov    ebx,0x1d
  4b8962:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8969:	75 27                	jne    0x4b8992
  4b896b:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8972:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b8979:	e8 12 8c 02 00       	call   0x4e1590
  4b897e:	68 80 cc bc 00       	push   0xbccc80
  4b8983:	e8 92 99 3d 00       	call   0x89231a
  4b8988:	83 c4 04             	add    esp,0x4
  4b898b:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8992:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b8995:	83 f8 09             	cmp    eax,0x9
  4b8998:	77 1b                	ja     0x4b89b5
  4b899a:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4b89a0:	03 05 04 43 f9 00    	add    eax,DWORD PTR ds:0xf94304
  4b89a6:	74 0d                	je     0x4b89b5
  4b89a8:	8d 57 d2             	lea    edx,[edi-0x2e]
  4b89ab:	8b f0                	mov    esi,eax
  4b89ad:	e8 9e b7 01 00       	call   0x4d4150
  4b89b2:	83 ce ff             	or     esi,0xffffffff
  4b89b5:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b89bc:	75 14                	jne    0x4b89d2
  4b89be:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  4b89c5:	68 10 cf bc 00       	push   0xbccf10
  4b89ca:	e8 4b 99 3d 00       	call   0x89231a
  4b89cf:	83 c4 04             	add    esp,0x4
  4b89d2:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b89d9:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b89dc:	ba 26 00 00 00       	mov    edx,0x26
  4b89e1:	66 89 54 24 18       	mov    WORD PTR [esp+0x18],dx
  4b89e6:	88 44 24 1a          	mov    BYTE PTR [esp+0x1a],al
  4b89ea:	75 16                	jne    0x4b8a02
  4b89ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b89f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b89f4:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b89f7:	6a 03                	push   0x3
  4b89f9:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  4b89fd:	52                   	push   edx
  4b89fe:	6a 00                	push   0x0
  4b8a00:	ff d0                	call   eax
  4b8a02:	0f b6 0f             	movzx  ecx,BYTE PTR [edi]
  4b8a05:	49                   	dec    ecx
  4b8a06:	ba 01 00 00 00       	mov    edx,0x1
  4b8a0b:	66 d3 e2             	shl    dx,cl
  4b8a0e:	83 c7 35             	add    edi,0x35
  4b8a11:	66 09 54 24 14       	or     WORD PTR [esp+0x14],dx
  4b8a16:	ff 4c 24 10          	dec    DWORD PTR [esp+0x10]
  4b8a1a:	0f 85 42 ff ff ff    	jne    0x4b8962
  4b8a20:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8a27:	75 2b                	jne    0x4b8a54
  4b8a29:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8a30:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x1e
  4b8a37:	1e 00 00 00 
  4b8a3b:	e8 50 8b 02 00       	call   0x4e1590
  4b8a40:	68 80 cc bc 00       	push   0xbccc80
  4b8a45:	e8 d0 98 3d 00       	call   0x89231a
  4b8a4a:	83 c4 04             	add    esp,0x4
  4b8a4d:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8a54:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8a5b:	66 8b 44 24 14       	mov    ax,WORD PTR [esp+0x14]
  4b8a60:	66 a3 40 42 f9 00    	mov    ds:0xf94240,ax
  4b8a66:	bf 01 00 00 00       	mov    edi,0x1
  4b8a6b:	75 2a                	jne    0x4b8a97
  4b8a6d:	09 3d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,edi
  4b8a73:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x1f
  4b8a7a:	1f 00 00 00 
  4b8a7e:	e8 0d 8b 02 00       	call   0x4e1590
  4b8a83:	68 80 cc bc 00       	push   0xbccc80
  4b8a88:	e8 8d 98 3d 00       	call   0x89231a
  4b8a8d:	83 c4 04             	add    esp,0x4
  4b8a90:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8a97:	b9 e0 d9 f8 00       	mov    ecx,0xf8d9e0
  4b8a9c:	e8 0f d5 02 00       	call   0x4e5fb0
  4b8aa1:	f6 05      	test   BYTE PTR ds:0xfb1314,0x1
```

### A.5 `0x4D4150` 單筆 53B 角色來源→角色 record 映射

- `.text` VA `0x004D4150..0x004D419C`；raw `0x000D3550..0x000D359C`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4d4150:	57                   	push   edi
  4d4151:	8d 7e 0c             	lea    edi,[esi+0xc]
  4d4154:	c7 46 5c 01 00 00 00 	mov    DWORD PTR [esi+0x5c],0x1
  4d415b:	8b c2                	mov    eax,edx
  4d415d:	2b fa                	sub    edi,edx
  4d415f:	90                   	nop
  4d4160:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4d4163:	66 89 0c 07          	mov    WORD PTR [edi+eax*1],cx
  4d4167:	83 c0 02             	add    eax,0x2
  4d416a:	66 85 c9             	test   cx,cx
  4d416d:	75 f1                	jne    0x4d4160
  4d416f:	0f b6 42 2e          	movzx  eax,BYTE PTR [edx+0x2e]
  4d4173:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  4d4176:	0f b6 4a 2f          	movzx  ecx,BYTE PTR [edx+0x2f]
  4d417a:	89 8e d4 00 00 00    	mov    DWORD PTR [esi+0xd4],ecx
  4d4180:	0f b6 42 30          	movzx  eax,BYTE PTR [edx+0x30]
  4d4184:	89 86 dc 00 00 00    	mov    DWORD PTR [esi+0xdc],eax
  4d418a:	8b 4a 31             	mov    ecx,DWORD PTR [edx+0x31]
  4d418d:	89 4e 50             	mov    DWORD PTR [esi+0x50],ecx
  4d4190:	8b 52 2a             	mov    edx,DWORD PTR [edx+0x2a]
  4d4193:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  4d4196:	b8 01 00 00 00       	mov    eax,0x1
  4d419b:	5f                   	pop    edi
  4d419c:	c3                   	ret
```

### A.6 `0x4E2730` alternative prefix2+53-byte row source

- `.text` VA `0x004E2730..0x004E27A1`；raw `0x000E1B30..0x000E1BA1`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4e2730:	55                   	push   ebp
  4e2731:	8b ec                	mov    ebp,esp
  4e2733:	51                   	push   ecx
  4e2734:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4e2737:	56                   	push   esi
  4e2738:	8b f1                	mov    esi,ecx
  4e273a:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4e273d:	83 f8 02             	cmp    eax,0x2
  4e2740:	73 04                	jae    0x4e2746
  4e2742:	33 c9                	xor    ecx,ecx
  4e2744:	eb 13                	jmp    0x4e2759
  4e2746:	8d 48 fe             	lea    ecx,[eax-0x2]
  4e2749:	b8 b3 cf 21 35       	mov    eax,0x3521cfb3
  4e274e:	f7 e1                	mul    ecx
  4e2750:	2b ca                	sub    ecx,edx
  4e2752:	d1 e9                	shr    ecx,1
  4e2754:	03 ca                	add    ecx,edx
  4e2756:	c1 e9 05             	shr    ecx,0x5
  4e2759:	85 c9                	test   ecx,ecx
  4e275b:	74 35                	je     0x4e2792
  4e275d:	53                   	push   ebx
  4e275e:	57                   	push   edi
  4e275f:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4e2762:	83 c7 02             	add    edi,0x2
  4e2765:	8b d9                	mov    ebx,ecx
  4e2767:	0f b6 47 2e          	movzx  eax,BYTE PTR [edi+0x2e]
  4e276b:	83 f8 09             	cmp    eax,0x9
  4e276e:	77 1a                	ja     0x4e278a
  4e2770:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4e2776:	03 86 24 69 00 00    	add    eax,DWORD PTR [esi+0x6924]
  4e277c:	74 0c                	je     0x4e278a
  4e277e:	8b d7                	mov    edx,edi
  4e2780:	8b f0                	mov    esi,eax
  4e2782:	e8 c9 19 ff ff       	call   0x4d4150
  4e2787:	8b 75 fc             	mov    esi,DWORD PTR [ebp-0x4]
  4e278a:	83 c7 35             	add    edi,0x35
  4e278d:	4b                   	dec    ebx
  4e278e:	75 d7                	jne    0x4e2767
  4e2790:	5f                   	pop    edi
  4e2791:	5b                   	pop    ebx
  4e2792:	8b ce                	mov    ecx,esi
  4e2794:	e8 17 38 00 00       	call   0x4e5fb0
  4e2799:	33 c0                	xor    eax,eax
  4e279b:	5e                   	pop    esi
  4e279c:	8b e5                	mov    esp,ebp
  4e279e:	5d                   	pop    ebp
  4e279f:	c2 0c 00             	ret    0xc
```

### A.7 `0x4ADD50` 基底 scene callback table 建構前後

- `.text` VA `0x004ADD50..0x004AE064`；raw `0x000AD150..0x000AD464`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
  4addac:	c7 40 04 f0 fa 4a 00 	mov    DWORD PTR [eax+0x4],0x4afaf0
  4addb3:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4addb6:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4addb9:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4addbc:	c7 40 5c 60 fe 4a 00 	mov    DWORD PTR [eax+0x5c],0x4afe60
  4addc3:	89 48 60             	mov    DWORD PTR [eax+0x60],ecx
  4addc6:	c7 40 64 30 01 4b 00 	mov    DWORD PTR [eax+0x64],0x4b0130
  4addcd:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  4addd0:	c7 40 6c c0 01 4b 00 	mov    DWORD PTR [eax+0x6c],0x4b01c0
  4addd7:	89 48 70             	mov    DWORD PTR [eax+0x70],ecx
  4addda:	c7 80 7c 05 00 00 d0 	mov    DWORD PTR [eax+0x57c],0x4b03d0
  4adde1:	03 4b 00 
  4adde4:	89 88 80 05 00 00    	mov    DWORD PTR [eax+0x580],ecx
  4addea:	c7 40 74 40 6c 43 00 	mov    DWORD PTR [eax+0x74],0x436c40
  4addf1:	89 48 78             	mov    DWORD PTR [eax+0x78],ecx
  4addf4:	c7 80 fc 09 00 00 40 	mov    DWORD PTR [eax+0x9fc],0x4b1940
  4addfb:	19 4b 00 
  4addfe:	89 88 00 0a 00 00    	mov    DWORD PTR [eax+0xa00],ecx
  4ade04:	c7 40 7c d0 19 4b 00 	mov    DWORD PTR [eax+0x7c],0x4b19d0
  4ade0b:	89 88 80 00 00 00    	mov    DWORD PTR [eax+0x80],ecx
  4ade11:	c7 80 84 00 00 00 30 	mov    DWORD PTR [eax+0x84],0x4b1a30
  4ade18:	1a 4b 00 
  4ade1b:	89 88 88 00 00 00    	mov    DWORD PTR [eax+0x88],ecx
  4ade21:	c7 80 8c 00 00 00 70 	mov    DWORD PTR [eax+0x8c],0x4b1a70
  4ade28:	1a 4b 00 
  4ade2b:	89 88 90 00 00 00    	mov    DWORD PTR [eax+0x90],ecx
  4ade31:	c7 80 1c 02 00 00 90 	mov    DWORD PTR [eax+0x21c],0x4b1a90
  4ade38:	1a 4b 00 
  4ade3b:	89 88 20 02 00 00    	mov    DWORD PTR [eax+0x220],ecx
  4ade41:	c7 80 94 00 00 00 f0 	mov    DWORD PTR [eax+0x94],0x4b24f0
  4ade48:	24 4b 00 
  4ade4b:	89 88 98 00 00 00    	mov    DWORD PTR [eax+0x98],ecx
  4ade51:	c7 80 a4 00 00 00 30 	mov    DWORD PTR [eax+0xa4],0x4c5930
  4ade58:	59 4c 00 
  4ade5b:	89 88 a8 00 00 00    	mov    DWORD PTR [eax+0xa8],ecx
  4ade61:	c7 80 ac 00 00 00 20 	mov    DWORD PTR [eax+0xac],0x4b2620
  4ade68:	26 4b 00 
  4ade6b:	89 88 b0 00 00 00    	mov    DWORD PTR [eax+0xb0],ecx
  4ade71:	89 90 b4 00 00 00    	mov    DWORD PTR [eax+0xb4],edx
  4ade77:	89 88 b8 00 00 00    	mov    DWORD PTR [eax+0xb8],ecx
  4ade7d:	c7 80 c4 00 00 00 30 	mov    DWORD PTR [eax+0xc4],0x4b2730
  4ade84:	27 4b 00 
  4ade87:	89 88 c8 00 00 00    	mov    DWORD PTR [eax+0xc8],ecx
  4ade8d:	c7 80 d4 00 00 00 d0 	mov    DWORD PTR [eax+0xd4],0x4b28d0
  4ade94:	28 4b 00 
  4ade97:	89 88 d8 00 00 00    	mov    DWORD PTR [eax+0xd8],ecx
  4ade9d:	c7 80 dc 00 00 00 80 	mov    DWORD PTR [eax+0xdc],0x4ae380
  4adea4:	e3 4a 00 
  4adea7:	89 88 e0 00 00 00    	mov    DWORD PTR [eax+0xe0],ecx
  4adead:	c7 80 3c 01 00 00 f0 	mov    DWORD PTR [eax+0x13c],0x4b2af0
  4adeb4:	2a 4b 00 
  4adeb7:	89 88 40 01 00 00    	mov    DWORD PTR [eax+0x140],ecx
  4adebd:	c7 80 44 02 00 00 e0 	mov    DWORD PTR [eax+0x244],0x4b32e0
  4adec4:	32 4b 00 
  4adec7:	89 88 48 02 00 00    	mov    DWORD PTR [eax+0x248],ecx
  4adecd:	c7 80 0c 01 00 00 d0 	mov    DWORD PTR [eax+0x10c],0x4b2cd0
  4aded4:	2c 4b 00 
  4aded7:	89 88 10 01 00 00    	mov    DWORD PTR [eax+0x110],ecx
  4adedd:	c7 80 14 01 00 00 40 	mov    DWORD PTR [eax+0x114],0x4b3040
  4adee4:	30 4b 00 
  4adee7:	89 88 18 01 00 00    	mov    DWORD PTR [eax+0x118],ecx
  4adeed:	c7 80 34 01 00 00 60 	mov    DWORD PTR [eax+0x134],0x4b3060
  4adef4:	30 4b 00 
  4adef7:	89 88 38 01 00 00    	mov    DWORD PTR [eax+0x138],ecx
  4adefd:	c7 80 ec 08 00 00 60 	mov    DWORD PTR [eax+0x8ec],0x4b3060
  4adf04:	30 4b 00 
  4adf07:	89 88 f0 08 00 00    	mov    DWORD PTR [eax+0x8f0],ecx
  4adf0d:	c7 80 44 01 00 00 d0 	mov    DWORD PTR [eax+0x144],0x4b1bd0
  4adf14:	1b 4b 00 
  4adf17:	89 88 48 01 00 00    	mov    DWORD PTR [eax+0x148],ecx
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
  4adf6d:	c7 80 4c 02 00 00 50 	mov    DWORD PTR [eax+0x24c],0x4b3350
  4adf74:	33 4b 00 
  4adf77:	89 88 50 02 00 00    	mov    DWORD PTR [eax+0x250],ecx
  4adf7d:	c7 80 5c 02 00 00 f0 	mov    DWORD PTR [eax+0x25c],0x4b34f0
  4adf84:	34 4b 00 
  4adf87:	89 88 60 02 00 00    	mov    DWORD PTR [eax+0x260],ecx
  4adf8d:	c7 80 6c 02 00 00 10 	mov    DWORD PTR [eax+0x26c],0x4b3510
  4adf94:	35 4b 00 
  4adf97:	89 88 70 02 00 00    	mov    DWORD PTR [eax+0x270],ecx
  4adf9d:	c7 80 74 02 00 00 70 	mov    DWORD PTR [eax+0x274],0x4b3570
  4adfa4:	35 4b 00 
  4adfa7:	89 88 78 02 00 00    	mov    DWORD PTR [eax+0x278],ecx
  4adfad:	c7 80 84 02 00 00 00 	mov    DWORD PTR [eax+0x284],0x4b3600
  4adfb4:	36 4b 00 
  4adfb7:	89 88 88 02 00 00    	mov    DWORD PTR [eax+0x288],ecx
  4adfbd:	c7 80 8c 02 00 00 10 	mov    DWORD PTR [eax+0x28c],0x4b3710
  4adfc4:	37 4b 00 
  4adfc7:	89 88 90 02 00 00    	mov    DWORD PTR [eax+0x290],ecx
  4adfcd:	c7 80 a4 04 00 00 f0 	mov    DWORD PTR [eax+0x4a4],0x4af1f0
  4adfd4:	f1 4a 00 
  4adfd7:	89 88 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],ecx
  4adfdd:	c7 80 f4 02 00 00 10 	mov    DWORD PTR [eax+0x2f4],0x4b3c10
  4adfe4:	3c 4b 00 
  4adfe7:	89 88 f8 02 00 00    	mov    DWORD PTR [eax+0x2f8],ecx
  4adfed:	c7 80 e4 02 00 00 a0 	mov    DWORD PTR [eax+0x2e4],0x4b3da0
  4adff4:	3d 4b 00 
  4adff7:	89 88 e8 02 00 00    	mov    DWORD PTR [eax+0x2e8],ecx
  4adffd:	c7 80 84 01 00 00 60 	mov    DWORD PTR [eax+0x184],0x4b3760
  4ae004:	37 4b 00 
  4ae007:	89 88 88 01 00 00    	mov    DWORD PTR [eax+0x188],ecx
  4ae00d:	c7 80 1c 03 00 00 e0 	mov    DWORD PTR [eax+0x31c],0x4b3ee0
  4ae014:	3e 4b 00 
  4ae017:	89 88 20 03 00 00    	mov    DWORD PTR [eax+0x320],ecx
  4ae01d:	c7 80 64 03 00 00 50 	mov    DWORD PTR [eax+0x364],0x4b4050
  4ae024:	40 4b 00 
  4ae027:	89 88 68 03 00 00    	mov    DWORD PTR [eax+0x368],ecx
  4ae02d:	c7 80 6c 03 00 00 e0 	mov    DWORD PTR [eax+0x36c],0x4b40e0
  4ae034:	40 4b 00 
  4ae037:	89 88 70 03 00 00    	mov    DWORD PTR [eax+0x370],ecx
  4ae03d:	c7 80 b4 03 00 00 80 	mov    DWORD PTR [eax+0x3b4],0x4b4380
  4ae044:	43 4b 00 
  4ae047:	89 88 b8 03 00 00    	mov    DWORD PTR [eax+0x3b8],ecx
  4ae04d:	c7 80 9c 03 00 00 00 	mov    DWORD PTR [eax+0x39c],0x4b4400
  4ae054:	44 4b 00 
  4ae057:	89 88 a0 03 00 00    	mov    DWORD PTR [eax+0x3a0],ecx
  4ae05d:	c7 80 cc 03 00 00 c0 	mov    DWORD PTR [eax+0x3cc],0x4b44c0
  4ae064:	44   
```

### A.8 `0x4B2190` 已證 S2C 42 handler（止於 ret，不包含 switch data）

- `.text` VA `0x004B2190..0x004B22DC`；raw `0x000B1590..0x000B16DC`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c 00             	ret    0xc
```

### A.9 `0x4B1A90` 已證 S2C 43 handler

- `.text` VA `0x004B1A90..0x004B1AAF`；raw `0x000B0E90..0x000B0EAF`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4b1a90:	6a 06                	push   0x6
  4b1a92:	e8 c9 d5 f5 ff       	call   0x40f060
  4b1a97:	8b c8                	mov    ecx,eax
  4b1a99:	e8 a2 e2 02 00       	call   0x4dfd40
  4b1a9e:	33 c0                	xor    eax,eax
  4b1aa0:	c2 0c 00             	ret    0xc
  4b1aa3:	cc                   	int3
  4b1aa4:	cc                   	int3
  4b1aa5:	cc                   	int3
  4b1aa6:	cc                   	int3
  4b1aa7:	cc                   	int3
  4b1aa8:	cc                   	int3
  4b1aa9:	cc                   	int3
  4b1aaa:	cc                   	int3
  4b1aab:	cc                   	int3
  4b1aac:	cc                   	int3
  4b1aad:	cc                   	int3
  4b1aae:	cc                   	int3
  4b1aaf:	cc                   	int3
```

### A.10 `0x4DFD40` S2C43 下游 effect/state object removal path

- `.text` VA `0x004DFD40..0x004DFE89`；raw `0x000DF140..0x000DF289`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfe01:	ff d2                	call   edx
  4dfe03:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfe06:	85 c9                	test   ecx,ecx
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
```

### A.11 `0x47B5C0` 另一條 scene double-key consumer

- `.text` VA `0x0047B5C0..0x0047B69F`；raw `0x0007A9C0..0x0007AA9F`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

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
  47b69c:	64 89 0d 00    	mov    DWORD PTR fs:0x0,ecx
```

### A.12 `0x4B7F00` S2C cmd2 初期 payload field writer

- `.text` VA `0x004B7F00..0x004B823F`；raw `0x000B7300..0x000B763F`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4b7f00:	55                   	push   ebp
  4b7f01:	8b ec                	mov    ebp,esp
  4b7f03:	83 e4 f8             	and    esp,0xfffffff8
  4b7f06:	6a ff                	push   0xffffffff
  4b7f08:	68 86 4d 94 00       	push   0x944d86
  4b7f0d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b7f13:	50                   	push   eax
  4b7f14:	83 ec 68             	sub    esp,0x68
  4b7f17:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f1c:	33 c4                	xor    eax,esp
  4b7f1e:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4b7f22:	53                   	push   ebx
  4b7f23:	56                   	push   esi
  4b7f24:	57                   	push   edi
  4b7f25:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f2a:	33 c4                	xor    eax,esp
  4b7f2c:	50                   	push   eax
  4b7f2d:	8d 44 24 78          	lea    eax,[esp+0x78]
  4b7f31:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b7f37:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b7f3a:	33 db                	xor    ebx,ebx
  4b7f3c:	83 ce ff             	or     esi,0xffffffff
  4b7f3f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b7f46:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4b7f4a:	75 27                	jne    0x4b7f73
  4b7f4c:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b7f53:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b7f5a:	e8 31 96 02 00       	call   0x4e1590
  4b7f5f:	68 80 cc bc 00       	push   0xbccc80
  4b7f64:	e8 b1 a3 3d 00       	call   0x89231a
  4b7f69:	83 c4 04             	add    esp,0x4
  4b7f6c:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b7f73:	33 c0                	xor    eax,eax
  4b7f75:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax
  4b7f7a:	b8 8c 38 f9 00       	mov    eax,0xf9388c
  4b7f7f:	c7 44 24 48 07 00 00 	mov    DWORD PTR [esp+0x48],0x7
  4b7f86:	00 
  4b7f87:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  4b7f8b:	8d 50 02             	lea    edx,[eax+0x2]
  4b7f8e:	8b ff                	mov    edi,edi
  4b7f90:	66 8b 08             	mov    cx,WORD PTR [eax]
  4b7f93:	83 c0 02             	add    eax,0x2
  4b7f96:	66 3b cb             	cmp    cx,bx
  4b7f99:	75 f5                	jne    0x4b7f90
  4b7f9b:	2b c2                	sub    eax,edx
  4b7f9d:	d1 f8                	sar    eax,1
  4b7f9f:	50                   	push   eax
  4b7fa0:	68 8c 38 f9 00       	push   0xf9388c
  4b7fa5:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  4b7fa9:	e8 b2 a1 f4 ff       	call   0x402160
  4b7fae:	bb 08 00 00 00       	mov    ebx,0x8
  4b7fb3:	39 5c 24 48          	cmp    DWORD PTR [esp+0x48],ebx
  4b7fb7:	72 0d                	jb     0x4b7fc6
  4b7fb9:	8b 4c 24 34          	mov    ecx,DWORD PTR [esp+0x34]
  4b7fbd:	51                   	push   ecx
  4b7fbe:	e8 49 92 3d 00       	call   0x89120c
  4b7fc3:	83 c4 04             	add    esp,0x4
  4b7fc6:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b7fcd:	75 2b                	jne    0x4b7ffa
  4b7fcf:	b8 01 00 00 00       	mov    eax,0x1
  4b7fd4:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b7fda:	89 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],eax
  4b7fe1:	e8 aa 6c 02 00       	call   0x4dec90
  4b7fe6:	68 30 ce bc 00       	push   0xbcce30
  4b7feb:	e8 2a a3 3d 00       	call   0x89231a
  4b7ff0:	83 c4 04             	add    esp,0x4
  4b7ff3:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b7ffa:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8001:	c7 05 b0 a7 fb 00 1e 	mov    DWORD PTR ds:0xfba7b0,0x1e
  4b8008:	00 00 00 
  4b800b:	75 2b                	jne    0x4b8038
  4b800d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8014:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x2
  4b801b:	02 00 00 00 
  4b801f:	e8 6c 95 02 00       	call   0x4e1590
  4b8024:	68 80 cc bc 00       	push   0xbccc80
  4b8029:	e8 ec a2 3d 00       	call   0x89231a
  4b802e:	83 c4 04             	add    esp,0x4
  4b8031:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8038:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b803f:	8b 57 02             	mov    edx,DWORD PTR [edi+0x2]
  4b8042:	89 15 30 39 f9 00    	mov    DWORD PTR ds:0xf93930,edx
  4b8048:	75 2b                	jne    0x4b8075
  4b804a:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8051:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x3
  4b8058:	03 00 00 00 
  4b805c:	e8 2f 95 02 00       	call   0x4e1590
  4b8061:	68 80 cc bc 00       	push   0xbccc80
  4b8066:	e8 af a2 3d 00       	call   0x89231a
  4b806b:	83 c4 04             	add    esp,0x4
  4b806e:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8075:	6a 14                	push   0x14
  4b8077:	8d 47 0c             	lea    eax,[edi+0xc]
  4b807a:	50                   	push   eax
  4b807b:	6a 15                	push   0x15
  4b807d:	68 f2 38 f9 00       	push   0xf938f2
  4b8082:	e8 77 bf 3d 00       	call   0x893ffe
  4b8087:	83 c4 10             	add    esp,0x10
  4b808a:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8091:	75 2b                	jne    0x4b80be
  4b8093:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b809a:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x4
  4b80a1:	04 00 00 00 
  4b80a5:	e8 e6 94 02 00       	call   0x4e1590
  4b80aa:	68 80 cc bc 00       	push   0xbccc80
  4b80af:	e8 66 a2 3d 00       	call   0x89231a
  4b80b4:	83 c4 04             	add    esp,0x4
  4b80b7:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b80be:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b80c5:	0f b7 4f 38          	movzx  ecx,WORD PTR [edi+0x38]
  4b80c9:	89 0d 08 42 f9 00    	mov    DWORD PTR ds:0xf94208,ecx
  4b80cf:	75 2b                	jne    0x4b80fc
  4b80d1:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b80d8:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x5
  4b80df:	05 00 00 00 
  4b80e3:	e8 a8 94 02 00       	call   0x4e1590
  4b80e8:	68 80 cc bc 00       	push   0xbccc80
  4b80ed:	e8 28 a2 3d 00       	call   0x89231a
  4b80f2:	83 c4 04             	add    esp,0x4
  4b80f5:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b80fc:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8103:	0f b7 57 36          	movzx  edx,WORD PTR [edi+0x36]
  4b8107:	89 15 0c 42 f9 00    	mov    DWORD PTR ds:0xf9420c,edx
  4b810d:	75 2b                	jne    0x4b813a
  4b810f:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8116:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x6
  4b811d:	06 00 00 00 
  4b8121:	e8 6a 94 02 00       	call   0x4e1590
  4b8126:	68 80 cc bc 00       	push   0xbccc80
  4b812b:	e8 ea a1 3d 00       	call   0x89231a
  4b8130:	83 c4 04             	add    esp,0x4
  4b8133:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b813a:	66 83 7f 3a 00       	cmp    WORD PTR [edi+0x3a],0x0
  4b813f:	0f 95 c0             	setne  al
  4b8142:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8149:	a2 10 42 f9 00       	mov    ds:0xf94210,al
  4b814e:	75 2b                	jne    0x4b817b
  4b8150:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8157:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x7
  4b815e:	07 00 00 00 
  4b8162:	e8 29 94 02 00       	call   0x4e1590
  4b8167:	68 80 cc bc 00       	push   0xbccc80
  4b816c:	e8 a9 a1 3d 00       	call   0x89231a
  4b8171:	83 c4 04             	add    esp,0x4
  4b8174:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b817b:	33 c9                	xor    ecx,ecx
  4b817d:	38 4f 3c             	cmp    BYTE PTR [edi+0x3c],cl
  4b8180:	0f 94 c1             	sete   cl
  4b8183:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b818a:	89 0d 88 42 f9 00    	mov    DWORD PTR ds:0xf94288,ecx
  4b8190:	75 27                	jne    0x4b81b9
  4b8192:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8199:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b81a0:	e8 eb 93 02 00       	call   0x4e1590
  4b81a5:	68 80 cc bc 00       	push   0xbccc80
  4b81aa:	e8 6b a1 3d 00       	call   0x89231a
  4b81af:	83 c4 04             	add    esp,0x4
  4b81b2:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b81b9:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b81c0:	8b 57 3d             	mov    edx,DWORD PTR [edi+0x3d]
  4b81c3:	89 15 8c 42 f9 00    	mov    DWORD PTR ds:0xf9428c,edx
  4b81c9:	75 2b                	jne    0x4b81f6
  4b81cb:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b81d2:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x9
  4b81d9:	09 00 00 00 
  4b81dd:	e8 ae 93 02 00       	call   0x4e1590
  4b81e2:	68 80 cc bc 00       	push   0xbccc80
  4b81e7:	e8 2e a1 3d 00       	call   0x89231a
  4b81ec:	83 c4 04             	add    esp,0x4
  4b81ef:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b81f6:	f6 05 08 5b fe 00 01 	test   BYTE PTR ds:0xfe5b08,0x1
  4b81fd:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4b8204:	00 
  4b8205:	c6 05 63 43 f9 00 00 	mov    BYTE PTR ds:0xf94363,0x0
  4b820c:	c7 05 5f 43 f9 00 00 	mov    DWORD PTR ds:0xf9435f,0x0
  4b8213:	00 00 00 
  4b8216:	f3 0f 11 05 64 43 f9 	movss  DWORD PTR ds:0xf94364,xmm0
  4b821d:	00 
  4b821e:	75 30                	jne    0x4b8250
  4b8220:	83 0d 08 5b fe 00 01 	or     DWORD PTR ds:0xfe5b08,0x1
  4b8227:	68 e8 5a fe 00       	push   0xfe5ae8
  4b822c:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xa
  4b8233:	0a 00 00 00 
  4b8237:	e8 04 ca 0c 00       	call   0x584c40
  4b823c:	68 80 f3 bc        	push   0xbcf380
```

### A.13 `0x4E5FB0` 可用清單之後 rank UI effects/limits

- `.text` VA `0x004E5FB0..0x004E613C`；raw `0x000E53B0..0x000E553C`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4e5fb0:	55                   	push   ebp
  4e5fb1:	8b ec                	mov    ebp,esp
  4e5fb3:	6a ff                	push   0xffffffff
  4e5fb5:	68 44 e3 91 00       	push   0x91e344
  4e5fba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4e5fc0:	50                   	push   eax
  4e5fc1:	83 ec 30             	sub    esp,0x30
  4e5fc4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4e5fc9:	33 c5                	xor    eax,ebp
  4e5fcb:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4e5fce:	53                   	push   ebx
  4e5fcf:	56                   	push   esi
  4e5fd0:	57                   	push   edi
  4e5fd1:	50                   	push   eax
  4e5fd2:	8d 45 f4             	lea    eax,[ebp-0xc]
  4e5fd5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4e5fdb:	8b f9                	mov    edi,ecx
  4e5fdd:	33 f6                	xor    esi,esi
  4e5fdf:	89 75 d0             	mov    DWORD PTR [ebp-0x30],esi
  4e5fe2:	8b 8f 24 69 00 00    	mov    ecx,DWORD PTR [edi+0x6924]
  4e5fe8:	89 7d c8             	mov    DWORD PTR [ebp-0x38],edi
  4e5feb:	e8 a0 e5 fe ff       	call   0x4d4590
  4e5ff0:	8b d8                	mov    ebx,eax
  4e5ff2:	89 5d cc             	mov    DWORD PTR [ebp-0x34],ebx
  4e5ff5:	3b de                	cmp    ebx,esi
  4e5ff7:	0f 84 24 01 00 00    	je     0x4e6121
  4e5ffd:	f6 05 a8 1c fc 00 01 	test   BYTE PTR ds:0xfc1ca8,0x1
  4e6004:	75 26                	jne    0x4e602c
  4e6006:	83 0d a8 1c fc 00 01 	or     DWORD PTR ds:0xfc1ca8,0x1
  4e600d:	68 a0 e5 bc 00       	push   0xbce5a0
  4e6012:	89 35 ac 1c fc 00    	mov    DWORD PTR ds:0xfc1cac,esi
  4e6018:	89 35 b0 1c fc 00    	mov    DWORD PTR ds:0xfc1cb0,esi
  4e601e:	89 35 b4 1c fc 00    	mov    DWORD PTR ds:0xfc1cb4,esi
  4e6024:	e8 f1 c2 3a 00       	call   0x89231a
  4e6029:	83 c4 04             	add    esp,0x4
  4e602c:	8b 35 ac 1c fc 00    	mov    esi,DWORD PTR ds:0xfc1cac
  4e6032:	8b 0d b0 1c fc 00    	mov    ecx,DWORD PTR ds:0xfc1cb0
  4e6038:	2b ce                	sub    ecx,esi
  4e603a:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  4e603f:	f7 e9                	imul   ecx
  4e6041:	c1 fa 03             	sar    edx,0x3
  4e6044:	8b c2                	mov    eax,edx
  4e6046:	c1 e8 1f             	shr    eax,0x1f
  4e6049:	03 c2                	add    eax,edx
  4e604b:	48                   	dec    eax
  4e604c:	8d 0c c0             	lea    ecx,[eax+eax*8]
  4e604f:	8d 4c 8e 04          	lea    ecx,[esi+ecx*4+0x4]
  4e6053:	39 19                	cmp    DWORD PTR [ecx],ebx
  4e6055:	76 06                	jbe    0x4e605d
  4e6057:	48                   	dec    eax
  4e6058:	83 e9 24             	sub    ecx,0x24
  4e605b:	eb f6                	jmp    0x4e6053
  4e605d:	8d 14 c0             	lea    edx,[eax+eax*8]
  4e6060:	0f b6 1c 96          	movzx  ebx,BYTE PTR [esi+edx*4]
  4e6064:	39 9f cc 68 00 00    	cmp    DWORD PTR [edi+0x68cc],ebx
  4e606a:	0f 84 a2 00 00 00    	je     0x4e6112
  4e6070:	e8 2b eb f1 ff       	call   0x404ba0
  4e6075:	83 b8 4c 5f 00 00 00 	cmp    DWORD PTR [eax+0x5f4c],0x0
  4e607c:	0f 84 90 00 00 00    	je     0x4e6112
  4e6082:	6a 6c                	push   0x6c
  4e6084:	e8 df b1 3a 00       	call   0x891268
  4e6089:	8b f0                	mov    esi,eax
  4e608b:	83 c4 04             	add    esp,0x4
  4e608e:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  4e6091:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4e6098:	85 f6                	test   esi,esi
  4e609a:	74 4b                	je     0x4e60e7
  4e609c:	e8 8f 6f fe ff       	call   0x4cd030
  4e60a1:	68 48 cf c0 00       	push   0xc0cf48
  4e60a6:	8d 7d d4             	lea    edi,[ebp-0x2c]
  4e60a9:	e8 92 94 f9 ff       	call   0x47f540
  4e60ae:	83 c4 04             	add    esp,0x4
  4e60b1:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4e60b5:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  4e60b9:	c7 45 d0 01 00 00 00 	mov    DWORD PTR [ebp-0x30],0x1
  4e60c0:	72 04                	jb     0x4e60c6
  4e60c2:	8b 10                	mov    edx,DWORD PTR [eax]
  4e60c4:	eb 02                	jmp    0x4e60c8
  4e60c6:	8b d0                	mov    edx,eax
  4e60c8:	6a 00                	push   0x0
  4e60ca:	6a 19                	push   0x19
  4e60cc:	6a 64                	push   0x64
  4e60ce:	56                   	push   esi
  4e60cf:	b9 19 00 00 00       	mov    ecx,0x19
  4e60d4:	e8 b7 dd 06 00       	call   0x553e90
  4e60d9:	8b 7d c8             	mov    edi,DWORD PTR [ebp-0x38]
  4e60dc:	c7 06 70 d1 c0 00    	mov    DWORD PTR [esi],0xc0d170
  4e60e2:	89 5e 68             	mov    DWORD PTR [esi+0x68],ebx
  4e60e5:	eb 02                	jmp    0x4e60e9
  4e60e7:	33 f6                	xor    esi,esi
  4e60e9:	6a 00                	push   0x0
  4e60eb:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4e60f2:	e8 d9 cd f3 ff       	call   0x422ed0
  4e60f7:	50                   	push   eax
  4e60f8:	b8 02 00 00 00       	mov    eax,0x2
  4e60fd:	8b ce                	mov    ecx,esi
  4e60ff:	e8 dc d5 06 00       	call   0x5536e0
  4e6104:	f6 45 d0 01          	test   BYTE PTR [ebp-0x30],0x1
  4e6108:	74 08                	je     0x4e6112
  4e610a:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4e610d:	e8 3e cb f1 ff       	call   0x402c50
  4e6112:	8b 45 cc             	mov    eax,DWORD PTR [ebp-0x34]
  4e6115:	89 87 d0 68 00 00    	mov    DWORD PTR [edi+0x68d0],eax
  4e611b:	89 9f cc 68 00 00    	mov    DWORD PTR [edi+0x68cc],ebx
  4e6121:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4e6124:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4e612b:	59                   	pop    ecx
  4e612c:	5f                   	pop    edi
  4e612d:	5e                   	pop    esi
  4e612e:	5b                   	pop    ebx
  4e612f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4e6132:	33 cd                	xor    ecx,ebp
  4e6134:	e8 c8 ae 3a 00       	call   0x891001
  4e6139:	8b e5                	mov    esp,ebp
  4e613b:	5d                   	pop    ebp
  4e613c:	c3                   	ret
```

### A.14 `0x4930E0` T02 inlet lane2 requirement

- `.text` VA `0x004930E0..0x0049316F`；raw `0x000924E0..0x0009256F`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
```

## 9. 靜態直接 CALL 交叉掃描與不能過度推斷的負向證據

對整段原生 `.text` 每個 byte offset 以 `E8 rel32` 計算可能 CALL 目的地。這是**候選 byte scan**；實際指令邊界須由上述入口反組譯確認；同一份二進位可能包含資料及重疊假陽性。`0x4B2190/0x4B1A90` 不出現在 direct E8 caller 是因這裡採**handler table data pointer** 分派，不代表不可達；`0x4E2730` 同理有 receiver virtual entry。

- Target `0x4A3B80` direct E8 candidates (3): `0x5F47F5`, `0x5F48F7`, `0x673EAA`.

- Target `0x4D4150` direct E8 candidates (2): `0x4B89AD`, `0x4E2782`.

- Target `0x4E2730` direct E8 candidates (0): none in byte pattern; check vtable/indirect path.

- Target `0x4E5FB0` direct E8 candidates (2): `0x4B8A9C`, `0x4E2794`.

- Target `0x4B2190` direct E8 candidates (0): none in byte pattern; check vtable/indirect path.

- Target `0x4B1A90` direct E8 candidates (0): none in byte pattern; check vtable/indirect path.

- Target `0x47B5C0` direct E8 candidates (1): `0x47D5B7`.

- Target `0x565720` direct E8 candidates (2): `0x47B64A`, `0x561EF3`.

- Target `0x4DFD40` direct E8 candidates (8): `0x4B1A39`, `0x4B1A79`, `0x4B1A99`, `0x4B1B16`, `0x4B1B4E`, `0x4B1B8A`, `0x4B1BB9`, `0x4B1BD9`.

## 10. 交付結論：**有界 E61 已保存，RR-0002 仍未完成**

目前 Client 原生靜態資料能可靠交付 C→S `0x42` 4-byte builder、不同 UI 前置、S→C `0x02` 角色清單資料流及兩個 S→C `0x42/0x43` handler 的負向界線。然而 RR-0002 要求**實際回覆欄位、兩方向配對與 scene transition**，仍沒有正向 writer/handler 鏈。不能因完成 E61、檔案很長、或舊合成測試曾顯示角色，就自行將請求轉為 `SUBMITTED`。此結果上傳 `extra/roy1` 後，可按 Git blob 由後續研究者接續，狀態 `IN_PROGRESS`；待上述必要條件閉合，另附完整補充原稿後再提出正式審查。

