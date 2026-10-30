# E78 — RR-0010 原生靜態收斂：建名載荷未定欄位、F4278 的非專屬來源、正式 S00 結案判準

> 2026-10-31（Asia/Taipei）｜chatgpt-web roy｜KR T03／正式 RR-0010 claim branch `extra/roy1`。以 `main=bf1e15ebcb19c272106627303ab27ecc0b2b3514` 的 `research/requests/index.json` 及 S00 PR #63 審查為起點；新證據從原始 `Tartaros.bin` 直接唯讀比對。**本篇是 E71～E77 研究的終點檢核與可操作 S00 交付，不是假冒原版 Server 交易或正式 RR ACCEPTED。**

原件 `Tartaros.bin` = 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。PE32 x86，ImageBase 0x400000；`.text` VA 0x401000/raw 0x400/size 0x7D0200；`.rdata` VA 0xBD2000/raw 0x7D0600；`.data` VA 0xD61000/raw 0x95E800。**只對 .text 使用 raw=VA−0x400C00**。

## 0. 給 S00 的判定摘要

最新正式 RR-0010 `status=BLOCKED`、`submission=null`；其驗收條件是「新可操作角色的 C2S producer、配對 S2C accepted/rejected、結果到 roster/init 的**正向依賴**」，第5項明確允許若原版 Server 配對不可證，提供精確可解除條件但**不得稱 ACCEPTED**。S00 已在 [RR0010-EXTRA-ROY1-REVIEW](../governance/s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md) 審查 E71～E74，限定接受「遠征隊名稱建立」Client 子流程，保留原本阻塞；E76/E77 再發現 Page ready 與 `app0xB6→F4278→角色紀錄 UI`，這些仍無原版 transaction ordering。

**E78 新成果：** (A) 以原始函式堆疊配置確認 `C2S0x003E` 的 `+2..+5` 沒有可據以指定正式值的 native 來源；21-WCHAR helper 容量耗盡時**清掉目的名稱的首 WCHAR**，呼叫者在送出點沒有依 helper 回傳值阻斷 queue。這是 Client 可證的相容性／資料安全風險，非官方 Server「可接受空名」政策；(B) 查完 `.text` 中 `F4278` 的兩個 4-byte 常量匹配，另一個位於 `0x60B200`，經 RTTI/虛表確定是 **`CPhaseSlot@FUI@@` 的 local event getter**，故 `F4278` **非建角與 S2C0xB6 專用**；(C) 確認 status 1 與 -1/-2/-3 是 Client 本地分支，沒有足夠原生文字／官服追蹤為錯誤碼下「重名」等業務名稱。

**整體 RR-0010 正向的「同一筆原版 Server 創角→回覆→roster」仍無充分證據，不能宣告完成。** 現有環境已證的是可分別到達的 Client producer/consumer 路徑；把它們接成官方序列是未證因果。研究者不修改 `research/requests/index.json`、不冒稱 S00 已 requeue、SUBMITTED/ACCEPTED、T01 FULL-PASS 或 Client 可玩。

## 1. 完整資料流及來源等級（方向與命名空間不可互換）

| 玩家/封包/本地階段 | 有界原生路徑與值 | 必要前提／未知 |
| --- | --- | --- |
| 建立遠征隊身分名稱 UI | `CExpeditionCreateDialog` vtable slot87 `0x671FD0` → confirm local `F4244`／`0x6A7` → `0x672180` | 資源／真實空 roster UI 可見性為 RR-0009，不能由 RTTI 推出 |
| Client name validation | `0x672180..0x6724B1`；UTF-16 取自 `dialog+0xF0` edit，SSO `edit+0x11C<8` 是存放模式，ASCII/非 ASCII 分支、四組本地比較 | 不是 8 字上限、不是完整官方字元/重名政策 |
| C2S 名稱建立 sender | `0x672505..0x67253C`；inner app `3E 00`，**48 bytes**，slot0；UTF-16LE name 由偏移+6 起，21 WCHAR 目的容量（42 bytes），必須 `FBA798==0` 才 enqueue | `+2..+5` **UNKNOWN**；姓名後剩餘 bytes 不保證已清零；T02 外框/Conn/WSASend 未於此證實 |
| 候選 S2C 建名結果 | 有效 EXPD/LOGIN 場景的 `app0x004A` 次表 `0x4C14E1` → handler `0x4C21D0` 讀 `signed WORD payload+2` → local event `F4245` | **未由原版官服 traffic/source 證實 0x003E↔0x004A 的同一 transaction**，handler 本體不在取+2前自行檢查足夠長度 |
| UI result | `F4245→0x5A6886→0x672570`：status=1 將輸入名稱複製至 `F938F2`，進入 `0x5F4910/0x5F4950`／`page+0x144=1`；-1/-2/-3/default 各分支 | local 對話框完成不代表 Server 已創建可操作角色、已持久化或已刷新清單 |
| 角色清單 | `S2C app2→0x4B7F00/0x4B8920`，65B header+53B/row，header+0x0C 名稱也寫 `F938F2`；row `0x4D4150` 設 `record+0x5C=1`；每筆可啟動 C2S 0x26，結尾可啟動 0x24 | 與 0x4A 共享名稱**不代表**固定順序／同筆交易。另一 `0x4E2730` 是 2+53N reader 不可混用 |
| 額外 S2C 角色 UI 候選 | base scene `app0xB6→0x4B5DD0→local F4278(0)→0x5A68D8→0x672F00`；後者讀 `F94304+index*0x210` 的 `+0x5C`，分已有/缺席記錄 UI | B6 handler 不讀額外業務 payload；無證據證明此為新角色建立 ACK 或官服必發事件。相鄰 B7 為不同資料 handler |
| 其它 C2S | `CEmployNewCharacter` 的 `0x6BF2A0→0x4A38D0` 送 `33 00` 2B；選角 builder `0x4A3B80` 送 `42 00 XX YY` 4B | `0x33` **無自訂角色名字/外觀欄位**；`0x42` 是選擇既有角色；不得拿 `S2C0x42/43` 當建角 ACK |

以上是一張**分別證實的 Client 靜態依賴圖**，不是「原版 Server 封包發送順序」；即使同一地點可讀寫 `F938F2` 或本地記錄 `+0x5C`，仍不能把獨立 S2C 消費者連為必然 transaction。

## 2. 新原生證據一：`C2S0x003E` 48-byte 封包的來源、容量及缺值界線

`0x672180` 開頭 `83 E4 F8` 對齊 stack、`0x672194 83 EC 48` 留 0x48 bytes local、後續保存寄存器與 stack cookie。成功路徑 `0x6724B1 mov edi,[esp+0x18]` 取回 dialog；`0x6724D1 cmp [esi+0x11c],8` 選 inline/heap 名稱指標；`0x6724E8` 測本地 lazy init，`0x672505` 開始真正建包。

精確組包片段：
```asm
672505 56                  push esi                   ; UTF-16 source
672506 8D54242A            lea edx,[esp+2Ah]         ; name dest
67250A B93E000000          mov ecx,3Eh
67250F 6A15                push 15h                   ; 21 WCHAR capacity
672511 52                  push edx
672512 66894C242C          mov word [esp+2Ch],cx     ; payload opcode+0
672517 E831092200          call 892E4Dh              ; bounded WCHAR copy
67251C 83C40C              add esp,0Ch
67251F 833D98A7FB0000      cmp dword [FBA798],0
672526 7516                jne 67253Eh               ; no queue
672533 6A30                push 30h                   ; payload len=48
672535 8D542424            lea edx,[esp+24h]         ; payload pointer
672539 52                  push edx
67253A 6A00                push 0                     ; slot0
67253C FFD0                call eax                  ; manager virtual+0x10
```
以 `S=ESP` 在 0x672505 第一個 push 前記：copy dest = `S+0x26`，opcode dest = `S+0x20`，queue pointer = `S+0x20`；所以 **payload+0..1** opcode、**payload+2..5** 為四個尚無合法值來源的 bytes、**payload+6..47** 為 21 個 WCHAR 槽位。該函式沒有對 `+2..+5` 提供一個可由上述控制路徑證實的值。這不等於所有 runtime bytes 必定等於某特定隨機值；**不能當「必須為零／保留欄位／角色 ID」下正式規格**。對未使用 name tail 同理。

`0x892E4D` 的 wchar copy 在 `0x892E87` 取 word、`0x892E8A` 寫 word、`0x892E96` 每次非終止碼位 `dec edi`；容量用完 `0x892E9F` 清空第一個目的 WCHAR，並走錯誤回傳路徑。**呼叫者 `0x67251C` 只做 ESP 清理，隨後直接檢查 `FBA798` 而非 `eax` error**；因此「名稱超長時此 handler 的 queue 點不使用 copy-return 阻止 send」是限定的 Native 結論。是否有更上游 GUI 限長，尚未知，不能說遊戲可實際提交超長名稱。Server 應獨立驗證命名請求，不仰賴 Client 本地 helper 成功。

## 3. 新原生證據二：`F4278` 的第二來源來自 `CPhaseSlot`

對原始 `.text` 0x401000..0xBD1200 尋找 4-byte little-endian `78 42 0F 00`，恰得 **0x4B5E28** 與 **0x60B201** 兩處；這是原始資料的常量匹配，並非窮盡所有 runtime 動態構造／間接 event。

- `0x4B5E25: push 0`、`0x4B5E27: push 0xF4278`、`0x4B5E2C: call 0x58AB80`，屬 base S2C B6 handler 的 local event。
- `0x60B200: B8 78 42 0F 00; C3` = `mov eax, F4278; ret`。`.rdata` `C29F18` 是 MSVC RTTI COL 指標 `C74D00`；COL 的 type descriptor `F84C54` 原生名稱 `.?AVCPhaseSlot@FUI@@`；其 vtable `C29F1C` 的 slot2 `C29F24` 正是 `0x60B200`。另 `0x60B210` 返回相鄰的寬字元 UI label 指標 `C29F00`。
- 故 **`F4278` 至少還可由 `CPhaseSlot` 的 local 類別方法提供**，不是 S2C B6 的唯一產生來源；此外 `F4278` 事件最終落到 Expedition Page `0x5A68D8` 還需頁面 listener、result=0、child owner 及角色索引有效。**不可由 `F4278` 倒推出 Server 建角成功、甚至必然收到 B6**。

上面 RTTI/指標與兩個 literal xref 皆由本輪 E78 checker 從 `Tartaros.bin` 直接核對；`CPhaseSlot` 名稱是 MSVC RTTI 原字串，不是推測暫名。不同 UI event domain 與 wire opcode domain 不可合併。

## 4. 異常、長度、重試與不同 Owner 的獨立反例

1. **成功 status**：`0x6725A2` 從 event+0x14 取本地結果，`0x6725AA` 比較 1；成功才複製輸入名稱 `F938F2`、調整頁面。**Client local accepted** 不等於 Server 實際 transaction commit。
2. **失敗 status**：`0x67264D` 比較 -1、`0x6727AF` 比較 -2、`0x672817` 比較 -3，均有不同訊息/UI 清理；不標成官方「重複名稱」「滿額」「非法字元」等規則。
3. **未送出**：`FBA798 != 0` 時 `0x672526` 跳過 manager queue；即使本地輸入合法，不能說已送上 TCP。
4. **S2C 短包**：`0x4C21D0` 本體 `movsx [payload+2]`，沒有在該函式內保證 `len>=4` 的 guard；安全 synthetic testcase 應自行拒絕短包，但不能說原版 Client 必然安全拒絕。
5. **UI record path**：`0x672F80` 比較 index<=9，`0x672F91` 讀 `record+0x5C`；缺 record 走 placeholder `0x673556→0x673790`。這不表示新角色已透過 `0x33` 或 `0x3E` 建立。
6. **其它 opcode**：`S2C0xB7` handler 與 B6 不同，`S2C0x42/43` 有已證其它副作用；`C2S0x26` 與 `S2C0x26` 同值不證 request/reply。
7. **重試／重名／斷線**：目前只有下層 T02 已證 socket cleanup/queue 邊界；這個 Client constructor/result handler 不能證明官方 Server 有重試上限、冪等鍵或 duplicate code。這些是 Server-only 待決策；如需玩家實際成功/失敗時序，另以合法原版 capture 或經授權相容性運行確認。

## 5. RR-0010 五個驗收條件：完整審查意見，不縮成局部成功

| 正式條件 | E71～E78 的實際交付 | 結論 |
| --- | --- | --- |
| ① 目標 SHA、建構／消費位址、欄位、長度、編碼、scene/slot/frame | C2S3E inner 48B/name+6 UTF-16LE/slot0、scene S2C4A signed word+2、app2 65+53N、B6/F4278；原件 SHA 與指令 verifier。保留 +2..+5、真正 TCP frame/Conn 與 original pairing UNKNOWN | **PARTIAL** |
| ② 正向「建立新角色 request→accepted/rejected→roster/init」、重複建立／斷線 | 各個 Client 支線正向存在；尚無 **同一 original Server transaction** 的完整因果、 playable-character 創建證據、官方 duplicate/retry。無權把串接假設填成 MUST | **NOT CLOSED** |
| ③ Client local/wire/Server 決策、不可拿 42/43 混建角 | 已核 F4244/F4245/F4278、3E/4A/app2/B6/33/42 區別，F4278 再有 PhaseSlot 反例 | **BOUNDED PASS** |
| ④ 僅復用 RR-0002/0007/0008 且不改其 scope | 本篇僅引用；不修改上述 RR 或 T02/T04/T06 原稿與 task owner | **PASS** |
| ⑤ 完整 Markdown、Git blob、陰性/邊界測試、GAP/SPEC 影響或可信外部解除條件 | E71～E78 報告、E78 原件 checker、四類責任與明確 S00 requeue/分題選項。此篇 Git SHA 在實際推送後讀回核對 | **RESEARCH HANDOFF READY；S00 REVIEW REQUIRED** |

**不得將 ③④⑤ 的 PASS 當作 ①② 也通過。** 此任務從設計之初就以 Client 能靜態證明／無法證明的官方跨端契約作界線；正式台帳仍應依 S00 程序保留 `BLOCKED`，除非 S00 修改可達且清楚的終點並依規則重新派工/審查。

## 6. 送交 S00 的具體處理，而不是 Server-only 未知卡住 Client

- **Client 待逆向（T03，尚有可查線索）**：集中對 `CEmployNewCharacter→0x33` 是否為 playable-character recruit 的 UI／scene producer、其後進入 `app2` 的狀態 writer/scene alias、`0x003E+2..5` 欄位必然初始化的其它可達路徑做定向 CFG；T06 提供 matching GUI layout/控制 ID，T04 負責角色可用/招募與出生規則的原生證據，T02 負責 queue→frame→Conn。沒有原版 Server 規則不應停止仍可取的 Client 原件分析。
- **Server 待開發（請 S00 正式收件）**：在現有 `REQ-0003`（角色清單）與 `REQ-0004`（角色 UI 就緒）去重追加 CODE_ANALYSIS 線索 `app2`/B6；另評估**獨立候選「遠征隊身分命名」REQ**，由 S00 判斷與新可操作角色招募是不是同一玩家需求。內部名稱權威、合法性、唯一性/保留字、持久化、提交冪等與重試、失敗 UI 策略屬 **Server-owned ADR/TEST**，不要求原版 Server 內部實作才能開始規劃；但不硬寫 Client 仍 UNKNOWN 的 wire byte 值及 status business enum。
- **跨功能待整合**：S00/REQ/ADR/SPEC/TEST、T03 Login/Expedition、T04 actual playable character、T06 GUI resources、T02 transport、相鄰 RR-0009、RR-0002、RR-0007/8。由 S00 判斷 `GAP-CHAR-0003` 是否拆解「name identity creation」和「unlock/prebuilt character availability」，原研究者不在自己的分支偷改 S00 台帳。
- **待遊玩驗證**：使用者若另行授權原版 Client＋隔離自製 Server 可驗可操作兼容性，但只能標記「synthetic compatibility」；欲證**官方 Server 原版交易**需版本相同、成功/失敗/重名/斷線完整 multi-Conn 合法抓包，或 verified original Server source。
- **可操作解阻條件**：A. 同版 KR 官方 request/result/roster trace 包含 Conn slot、frame、場景與 UI 時戳；B. 原版 Server handler/source；C. 從 BIN 另找到建名/招募結果可達 roster/init 正向 writer（包括 indirect/virtual），並以原始 bytes、CFG、別名證明；D. S00 在不重寫歷史的情形下正式將 RR 的「original transaction 因果」與「Client-only bounded handler」拆成可驗收項，重新 `BLOCKED→QUEUED→CLAIMED→IN_PROGRESS→SUBMITTED→IN_REVIEW`，只有 S00 判斷 `ACCEPTED`。**無 A/B 不等於無法進行 C／Server 自訂需求。**

## 7. 可重現驗證、来源與稽核限制

```bash
sha256sum Tartaros.bin Tartaros.exe
python -B kr-extra-roy/20261031-chatgpt-web-roy-E78-RR0010-verify.py Tartaros.bin
# 預期輸出：RR-0010 E78: PASS 97 read-only original BIN assertions
```

E78 verifier 是延續 E77 的 69 項精確 raw byte／handler-pointer／RTTI／scene-event/role-flag tests，加上 28 項 name-builder/stack、`0x892E4D`、signed result 與 `CPhaseSlot`/F4278 origin assertions，**共 97 項原始 BIN 靜態檢查，本輪本地實際重跑 PASS**。不含原版 Server、Client runtime、TCP 抓包、整個反編譯函式 CFG FULL-PASS；`F4278` 的兩處匹配只對 static 4-byte literal 有效，不表示所有執行期間接來源都被排除。

既有來源不覆寫：E71～E74（創建候選/命名、shared name/roster）、E76（頁面 ready）、E77（B6/role UI）、E75（僅 RR-0002 的 0x26 consumer），以及 S00 [2026-10-31 review](../../governance/s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md)。本篇所有新結論均限於列出的原件位址、資料流與前置條件；未於本輪執行 Client 或修改原檔。
