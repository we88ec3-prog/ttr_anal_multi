# T12 — KR 戰鬥結果：A01–A04 / B01–B05 BIN-first 大型批次

> 研究日期：2026-10-31 Asia/Taipei；作者：chatgpt-web roy；工作分支：`t12/roy/chatgpt-web`  
> 本批屬 **KR 原版 Client 靜態原生證據**，不執行、附加或修改目標。原稿採主張級範圍，**不主張 T01 FULL-PASS / S00 RR ACCEPTED / Server 已實作 / 原版 Client 已可玩**。  
> 基準：本次開工 `main = t12/roy/chatgpt-web = ac3aa886e9fd20be93b6f841ada66fe22e587aa1`（GitHub compare ahead=0/behind=0）。未修改他人 Task、owner、RR 台帳或 main。

## 1. 本批終點與結論摘要

依 `T12-WORK-PLAN-20261031.md` 定義的 A01–A04 及 B01–B05，本批直接驗證：

- 入口：Client 內部結果分派登記 `0x4ADDEA -> 0x436C40 -> scene.vtable+0x28 -> 0x4B0640 / 0x4C4920`。**內部 command 14/0x0E 已核，socket/frame 外層是否同一 wire opcode 尚須 T02 精確接合**。
- 共用場景結果 consumer `0x4B0640` 在本地角色存在時讀取 `(buffer,length)`，跳過 2-byte header，按 13-byte stride 處理 `floor((length-2)/13)` 筆。`length<2` 以零筆處理；尾端不足一筆的位元組在此函式忽略。不存在完整 packet CRC/上游 buffer capacity 驗證證據。
- row: `+0/WORD sourceID`，`+2/WORD targetID`，`+4/signed BYTE case`，`+5/signed BYTE effect parameter`，`+6/DWORD value`，`+12/signed BYTE secondary effect parameter`；`+10..11` 尚未由本函式直接讀取/命名，保留 unknown。WORD/DWORD 小端讀取為 x86 native memory access 的有界事實。
- source / target 均於 `[0x00FAB138]` 管理的 common actor 樹以 `0x82EF00` 查找。缺任一 actor 會略過該筆；若本地玩家查找失敗則回傳 `0x80004005`。**不能把這裡的 actor lookup 當成傷害裁決或怪物 AI**。
- 9 種 case 真實跳表位於 `0x004B1914`，索引負值或 >8 走下一筆；case 7 直接跳過本筆。case 0/2/4/8 等有不同特效/FrameControl 行為，**資源文字 NORMAL/BLOCKED/CRITICAL 只能支持顯示路徑，不能當成 Server 命中判定公式**。
- 在 actor ID membership 相關條件成立時，case 1 的 `row+6` 會在 buffer 記憶體中被 `NEG` 就地改寫；其後還可能加到全域 `[0x00F942C4]` 並在負值時歸零。此全域不是已證的 actor HP 欄位，不能把變更後的 row 當作 wire bytes。

**靜態完成界線**：A01–A04 為來源/責任/入口基線完成；B02–B05 於「共用結果 consumer 的直接分支與一層主要 callee」完成有界查證。B01「命令表至場景 consumer」已閉合，但 **T02 socket/framing → 此表的跨層完整證據尚未閉合**，需標為 Client 待逆向、不可宣告 B01 全程 FULL-PASS。C/D/E 等後續階段才追終端 HP writer、死亡與深層 callee；這不是本批取得的結論。

## 2. A01 — 正式來源、狀態及重複研究去重

- `AGENTS.md`、`kr/tasks/T12/README.md`、`kr/tasks/T12/task.json`：T12 scope =「戰鬥結果消費與死亡資料；不把顯示結果推成計算公式」；主線 `owner=null`、`state=unclaimed`、`native_complete=false`、`handoff_status=bounded-review-handoff`。本次**沒有**改寫 Task owner 或 claimed，因計畫/研究提交不等於正式認領。
- `research/dispatch/inbox/T12.md`：開工時「目前無待處理的 S00 研究請求」；核對 `research/requests/index.json`，當時共 10 筆，`owner_task=T12` 為零。此為當次 main 快照，未建立私有 RR。
- `shared/verified-knowledge/README.md`：已核既有 FULL-PASS 索引，**未發現可直接替代整條 T12 000E 函式的 FULL-PASS**；不能因此否定歷史有界研究。
- 來源已閱讀：`kr/evidence/0124ca7a9184fc541708d37dee2516ec3d5f7bd788b1bbeb9df8f86399f81f71.txt` (battle-result-route-audit)；`kr/evidence/81a3fe379d433685e342d65c96db6aa78a52e0510f294cc3e338c4e7b63269b6.txt` (battle-result-and-AI-feedback)；`kr/evidence/b031b1f51bb9d8958fbaaa555b45f8b38845abd027e049d064525c747fabac34.txt` (battle-frame-binding report)。它們是定位/歷史解釋來源，**本報告下列 bytes/disassembly 由本次原始 BIN 重新讀出**。
- 共用基礎：`shared/CLIENT-MODIFICATION-POLICY.md` 禁止以 Client patch / fixture 代替原版收發。既有 fixture 的半徑 45/65、傷害 20/35/60、延遲 .2 一律不當原生常數。

## 3. A02 — 原始檔 hash / PE / VA-raw 驗證

| 本次實際讀取的原件 | SHA256 |
|---|---|
| `/mnt/data/Tartaros.bin` | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `/mnt/data/Tartaros.exe` | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |

`file` 與 `objdump -h` 均辨識原生 BIN 為 `PE32 executable, Intel i386, 4 sections`。本次直接讀出的 `objdump` section（以 BIN 為準）：

| 區段 | VA | raw start | virtual size |
|---|---:|---:|---:|
| `.text` | `0x00401000` | `0x00000400` | `0x007D01F0` |
| `.rdata` | `0x00BD2000` | `0x007D0600` | `0x0018E07C` |
| `.data` | `0x00D61000` | `0x0095E800` | `0x0022B800` |
| `.rsrc` | `0x00FE9000` | `0x00B8A000` | `0x0005AF58` |

`.text` 對應 `raw = VA - 0x401000 + 0x400`。精確原生 bytes/映射驗證如下：

| VA | raw | 機器碼節錄 | 作用 |
|---|---:|---|---|
| `0x4ADDEA` | `0xAD1EA` | `C7 40 74 40 6C 43 00` | 登記 `0x436C40` |
| `0x436C40` | `0x36040` | `8B 01 FF 60 28` | scene vtable+28 |
| `0x4B0640` | `0xAFA40` | `55 8B EC 83 E4 F8` | 共用 receiver |
| `0x4B0736` | `0xAFB36` | `8B 45 0C 83 F8 02` | length gate |
| `0x4B0768` | `0xAFB68` | `8B 44 24 38 ... 6B C0 0D` | row*13 |
| `0x4B07AF` | `0xAFBAF` | `0F B7 13` | row sourceID |
| `0x4B0819` | `0xAFC19` | `0F B7 53 02` | row targetID |
| `0x4B0AF0` | `0xAFEF0` | `80 7B 04 01 75 08 8B 43 06 F7 D8 89 43 06` | case 1 in-place negate |
| `0x4B0B62` | `0xAFF62` | `FF 24 85 14 19 4B 00` | jump table |
| `0x4B1914` | `0xB0D14` | `69 0B 4B 00 8B 11 4B 00 EC 0E 4B 00` | table entries |
| `0x4B18D4` | `0xB0CD4` | `E8 07 10 32 00` | call `0x7D28E0` |
| `0x4B18D9` | `0xB0CD9` | `8B 44 24 38 40 89 44 24 38` | row loop increment |

上述 bytes 取自本次原始 BIN，非以 GitHub 的過往 audit JSON 替代。尚未依 T01 的嚴格條件完成全文原生語意審核。

## 4. A03 — 歷史結果與勘誤

- 舊審核支持 000E 每筆 13 bytes、case 0..8、`CMissionField` 與 `CScenarioField / CInfiniteDungeonField` 的場景分派。這些是定位導航；本次在 BIN 核對主要相關地址與 branch。
- **重要勘誤**：歷史 `kr-persistence-20261023/battle-frame-contexts.json` 將 `0x4B18D4` 參數 EDX 總結為固定 0 **不成立**。`0x4B18C7 xor edx,edx` 的入邊可帶 0；case 4 在 `0x4B0E50 mov edx,1` 後跳到 `0x4B18C9`；case 2 在 `0x4B1181 mov edx,2` 後也跳到 `0x4B18C9`，均跳過清零。原 `binding-records` correction 應保留，不能覆蓋原資料冒稱從未錯誤。
- `7ABCD0` 接收數字製作顯示 glyph / panel；`551F20`、`5521D0`、`7AC030` 是效果/顯示消費者的**限定**已研究語意。沒有證據證明 `7ABCD0` 本身就是 HP writer 或命中計算函式。

## 5. A04 — 主責與入口邊界

| 模組/用途 | 來源 | 本 Task 界線 |
|---|---|---|
| socket receive / framing / dispatcher | T02，既有入口 `0x806CF0`、`0x4930E0` | **引用**；確認如何進入 scene table 尚需 T02 對接 |
| Actor 查找、場景物件生命週期 | T08 | T12 只核 result 中 actor id lookup 與其效果 |
| 普攻 C2S | T10 | 不反推 Server 命中演算法 |
| 技能 C2S、消耗與施放 | T11 | 不複製技能 owner |
| T12 業務 consumer | `0x4ADDEA` / `0x436C40` / `0x4B0640` / `0x4C4920` | 本批主線 |
| 角色血量 / 死亡 / 復活 | T12 後續 C/D/E | 本批不可冒稱已找到權威 writer |

## 6. B01 — result command table → scene virtual → receiver

### BIN 可確認路徑

1. `0x4ADD50` 所在初始化區先以 `0xBD5` 次寫入 8-byte 兩欄預設表項；`0x4ADDEA: mov dword ptr [eax+0x74],0x436c40`，後續 `[eax+0x78]` 登記 paired value。`0x74 = 4 + 14*8`，因此表局部索引是 **decimal 14 (0x0E)**。同段 `[eax+0x5C]=0x4AFE60` 對應既有內部 command 11 移動結果的另一 handler；不要混合。
2. `0x436C40: mov eax,[ecx]; jmp [eax+0x28]` 是**純轉送**，不解析 row、不做 HP 計算。
3. 既有 scene vtable/RTTI 研究記錄 `CMissionField -> 0x4B0640`、`CScenarioField / CInfiniteDungeonField -> 0x4C4920`；本次於原生 `0x4C4951` 查到 `call 0x4B0640`，確認 Scenario 類包裝器先執行共用 receiver。
4. `0x4C495B` 檢查共用 receiver return 是否為 0；非零直接離開。成功後才走三槽 Hero AI feedback，最後清除暫存欄位（下節）。

**關鍵分層**：內部表 `0x0E` ≠ 已完整核對的外層 wire framing/connection-domain opcode。`0x4930E0` 另可見 `[ebp+0xC]` 前兩 byte、`[esi+0xB8]` virtual call，**尚未建立從實際 WSARecv/IOCP → 此表項的直接完整 xref**；禁止單靠相同常數寫成完整 socket 結論。此連結是 B01 保留的精確 T02 跨層阻塞，不是原版 Server-only 未知。

### Scenario feedback 差異（原生確認）

`0x4C4963..0x4C497B` 重新計算相同 row 數量；`0x4C4A01` 從 `buffer+4` 起走，每輪 `add edi,0x0D`；`0x4C4A06` 查看 `[edi+2]` (=row+4)；case 0、2、3 會走 `0x4C4A43` 讀兩個 WORD actor id、`0x4C4A51 call 0x54A8F0`。`0x54A8F0` 是三個英雄控制槽的攻擊來源/目標回饋，**不是配置怪物 AI 腦或判定原版怪物攻擊來源**。`0x4C4A85..0x4C4AA0` 清零 `[0xFB7A7C/78/80/84/88]` 暫存結果。其底層 vtable+1C 的所有語意仍依 T08/舊來源範圍，未提升 FULL-PASS。

## 7. B02 — length、stride、byte order、termination

原生 assembly：

~~~asm
4B0736  mov eax,[ebp+0Ch]      ; 傳入 buffer length
4B0739  cmp eax,2
4B073C  jae 4B0742
4B073E  xor edx,edx           ; short packet -> zero rows
4B0742  lea edx,[eax-2]
4B0745  mov eax,4EC4EC4Fh
4B074A  mul edx
4B074C  shr edx,2             ; floor((length-2)/13)
4B075B  test edx,edx
4B075D  je 4B18EC
4B0768  mov eax,[esp+38h]    ; current index
4B0770  imul eax,eax,0Dh
4B077F  lea ebx,[eax+ecx+2] ; row pointer = buffer + 2 + index*13
4B18D9  mov eax,[esp+38h]
4B18DD  inc eax
4B18E2  cmp eax,[esp+34h]
4B18E6  jb 4B0765
~~~ 

前置 `0x4B06F6..0x4B0731` 先查本地 player (global `[F93930]` / `FAB148`)；缺席會記錄訊息並回傳 `0x80004005`。因此 short packet **只保證 row-count 為零**，不是無條件成功（仍受本地 player gate 限制）。此 receiver 沒有看到完整 `length % 13 == 2` 的檢查；尾端不足一筆被忽略，而不是宣布 network 上保證容忍任意 frame 殘片。大 buffer / pointer bounds 由上層保証與否未閉合，不能稱作已安全驗證。

### Row 欄位（有界）

| offset | 讀取方式 | 本批可主張 | 不可外推 |
|---|---|---|---|
| `+0..1` | `0x4B07AF movzx edx,WORD [ebx]` | source actor key | 不是玩家專用 ID |
| `+2..3` | `0x4B0819 movzx edx,WORD [ebx+2]` | target actor key | 不是怪物專用 ID |
| `+4` | `0x4B0B55 movsx eax,BYTE [ebx+4]` | signed case，0..8 | 未證官方 enum 名 |
| `+5` | 多處 `movsx BYTE [ebx+5]` | effect/display 子參數 | 不是固定傷害類別 |
| `+6..9` | `mov [ebx+6]`、`neg`，傳 `7ABCD0` | 32-bit signed effect value consumer | 不等於原版傷害公式/HP |
| `+10..11` | 本 `0x4B0640` 一層未見直接取此段 | unknown / reserved? 不命名 | 不能說原版永遠無用 |
| `+12` | `0x4B0B71`、`0x4B1673` `movsx BYTE [ebx+0Ch]` | secondary display/effect 參數 | 不等於官方 actor type |

## 8. B03 — Actor lookup、失敗路徑、不同 scene

- `0x4B07AF` 和 `0x4B0819` 從 row 取兩個 16-bit key，各呼叫 `0x82EF00` 查 `0xFAB138` common actor 容器。命中時從 tree node `+0x10` 取物件指標；miss 轉 null。
- `0x4B0847` source null：記錄診斷，跳到 `0x4B18D9` 下一筆；`0x4B0864` target null 同樣跳到下一筆。null actor 不是直接讓 receiver 以錯誤碼終止整包。
- `0x4B08B8` 起還依 actor 與 local actor 關係、control slots 等條件處理本機狀態；`0x4B09??–0x4B0B4F` 的會員檢查可能更新額外控制 state。**不宜將整個函式稱為純 UI 呈現**；也不能把該 state 解成已驗證 HP。
- `0x4C4920` scenario/infinite dungeon 類 wrapper 在 common receiver 成功後，針對 case0、2、3 補一層英雄 AI target feedback。此 wrapper 與本地動作/目標選擇有關，不推出怪物 AI 原版 server 計算。
- 待進一步以 vtable/RTTI bytes 逐個主張複驗的精確場景 type label 仍引用歷史 `BATTLE-RESULT-AND-AI-FEEDBACK.md`，命名本身列「部分確認」，本批直接確認的是 receiver/wrapper 二條 code path。

## 9. B04 — case 0..8 原始跳表、主要 consumer

`0x4B0B55` 使用 `movsx` 將 `row+4` 當 signed case；`cmp eax,8; ja 0x4B18D9`，負值當無號比較也會被略過；`0x4B0B62` 的原生 `jmp DWORD PTR [eax*4+0x4B1914]`。本次逐一讀出 9 筆 little-endian DWORD：

| case | target VA | 主要一層消費/分支（本次 BIN 核對） | 證據界線 |
|---:|---|---|---|
| 0 | `0x4B0B69` | `0x5521D0` STRUCK 類效果；`0x7ABCD0` 數值 glyph；本機 effect/control；`0x7D28E0` FrameControl NORMAL 路徑 | display 與 motion，未證 hit formula |
| 1 | `0x4B118B` | `0x551F20` 效果；`row+5` 的 0/1/2 子分支到 `0x49B0D0` / `0x7ABCD0`；隨後其他文字/控制分支 | 前段 membership gate 可能先 negate value |
| 2 | `0x4B0EEC` | `0x551F20`、`0x7ABCD0`、`0x7AC030` 等；`0x4B114E`、`0x4B18D4` 到 `0x7D28E0`，EDX=2 路徑 | 帶 CRITICAL 顯示資源，不推 Server 爆擊機率 |
| 3 | `0x4B0E5A` | `0x545260` 搜控制記錄、`0x49B0D0`、`0x7AC030`；`0x4B0EA4` 進下一 row | 沒看到此分支是 HP/死亡計算 |
| 4 | `0x4B0D14` | `0x551F20`、`0x7AC030`；`0x4B0E1D` FrameControl，`0x4B18D4` 共用尾段 EDX=1 | 帶 BLOCKED 顯示資源，不推真正防禦裁決 |
| 5 | `0x4B15B7` | `row+5` 分支、`0x545260`、`0x49B0D0`、`0x7ABCD0`；可走尾段 motion guard | 子參數 enum 尚未命名 |
| 6 | `0x4B1313` | `0x551F20`、`0x545260`，`row+5` 0/1/2 路徑及 `0x7ABCD0`、`0x5855B0/0x4D6B30` 等文字/效果 | 不推血量或官方 buff enum |
| 7 | `0x4B18D9` | **直接行進下一筆** | 並不代表 Server 不會產生 case7 |
| 8 | `0x4B1673` | `0x5521D0`、`0x7ABCD0`；`0x48A400 / 0x6D89C0` 等路徑；`0x7D28E0` NORMAL 共用 tail | 與 case0 共用部分 tail，不能等同整個 case0 |

關鍵 guard：`0x4B0CD6`、`0x4B0DE5`、`0x4B1116`、`0x4B1871`、`0x4B18AB` 等沿 model `actor+0x15C`、`actor+0x370`、`model+0xAC` 檢查後才呼叫 virtual+0x30 / `0x7D28E0`。某一方向 guard 失敗仍可能走另一方向，不能寫成 source/target 兩邊必定同時播動畫。

### FrameControl 共享尾段的真實多入邊（防止舊錯）

~~~asm
4B0E50  mov edx,1        ; case4
4B0E55  jmp 4B18C9
4B1181  mov edx,2        ; case2
4B1186  jmp 4B18C9
4B18C7  xor edx,edx      ; 其他零路徑
4B18C9  add eax,0B4h
4B18CE  push eax
4B18CF  mov ecx,4
4B18D4  call 7D28E0
~~~ 

`0x4B18D4` 這個**同一個 callsite** 可接收 EDX 0/1/2，不能因局部線性 listing 誤稱固定 0；作用與 `7D28E0` 內部 lookup 詳義見歷史 battle-frame-binding 更正 overlay，仍受本次主張級有限驗證。

## 10. B05 — 原始 wire、in-place 修改與數字顯示之區分

完整關鍵 code：

~~~asm
4B0AD1  movzx edi,WORD PTR [ebx+2] ; 會員條件檢查 target key
...
4B0AEC  test cl,cl
4B0AEE  je 4B0B4F
4B0AF0  cmp BYTE PTR [ebx+4],1
4B0AF4  jne 4B0AFE
4B0AF6  mov eax,DWORD PTR [ebx+6]
4B0AF9  neg eax
4B0AFB  mov DWORD PTR [ebx+6],eax    ; **修改傳入 buffer**
4B0B36  mov ecx,DWORD PTR [ebx+6]
4B0B3F  add DWORD PTR ds:[0F942C4h],ecx
4B0B45  jns 4B0B55
4B0B47  mov DWORD PTR ds:[0F942C4h],esi
~~~ 

條件與結果必須同時寫清：不代表 case1 一定負號化；只有 membership 命中路徑能抵達 `NEG`，並且若 case 不是 1 則不 NEG。其後可能將目前值加至一個全域聚合欄位（低於零時歸零）；**全域名稱、單位與是否是計分/生命值未知**。因此 `7ABCD0` 看到的 `row+6` 可能已不是 wire 原值。必須在 handler 前保留原始 packet snapshot 才能比較 wire/converted；本批並未捕獲真實網路封包或執行遊戲。

## 11. 端到端玩家情境與相容 Server 界線

| 情境/輸入 | 命令/入口 | 具體 Client 行為 | Server 待開發（非原版已證規則） | 未知 |
|---|---|---|---|---|
| 場景下發 1 筆結果，兩 Actor 都在 common tree | internal 0x0E → scene virtual+28 → `0x4B0640` | 解析 13B、case switch、效果/FrameControl/控制 consumer 依條件執行 | 相容 Server 應提供符合該方向與現有狀態的 actor IDs、case、value、效果參數 | 外層 framing、哪個連線/lane、何時觸發 |
| Actor key 已不存在 | 同上 | 該 row 略過，後續 row 可處理 | 設計 actor 存活與送包順序 | 舊封包晚到的 runtime race |
| 沒有本地 player | 同上 | 於 `0x4B071F` log；`0x4B072C` return `0x80004005` | 依相容 Server 流程避免錯誤 phase 收到 result | 登入/場景 gate 的端到端順序 |
| case7、未知/負數 case | 同上 | 無對應 case consumer，該 row 前進 | 不得捏造禁止這些 case 的官方規則 | 其他外層保護/錯誤回報 |
| Scenario wrapper 下 case0/2/3 | `0x4C4920` → common receiver → `0x54A8F0` | 共用結果成功後更新英雄三槽的 source-target feedback | 不由 T12 宣稱官方怪物 AI/目標決策 | 三槽/scene type 動態驗證 |

這一矩陣是 Client 靜態契約，**沒有**獨立驗證 C2S 普攻/技能與此結果回包的時間及對應關係。原版 Server 何時判定命中、傷害公式、死亡裁決屬 Server 待設計/原版不可證；仍可追的 Client HP/死亡 writer 屬 T12 後續 D/E，不能丟給 Server 代替研究。

## 12. 完成檢查、風險與下一入口

| 項目 | 本批狀態 | 可重現依據與剩餘 |
|---|---|---|
| A01 | **完成：來源基線** | GitHub main/README/task/inbox/RR/verified-index + 三個歷史 evidence |
| A02 | **完成** | 原始 KR BIN/EXE SHA；objdump sections；逐位址 raw bytes |
| A03 | **完成：有界勘誤** | 0x4B18D4 EDX 0/1/2、fixture 禁用；不可宣告所有歷史全文複審 |
| A04 | **完成** | T02/T08/T10/T11 responsibility 與 000E 處理入口 |
| B01 | **部分完成** | scene handler 註冊/virtual/consumer 已核；**缺 WSARecv/framing 到 internal table 的完整 xref** |
| B02 | **完成：共用 receiver 直接路徑** | 2/13 長度、floor、signedness、loop、短包/尾數界線 |
| B03 | **完成：共用 receiver 直接路徑** | Actor tree lookup/missing row skip，Scenario 特殊 feedback |
| B04 | **完成：一層主要分支** | 全 9 筆 jump-table 真值、case 直接 consumer、必要 guard；深層 HP/死亡語意另屬後續 |
| B05 | **完成：直接 buffer transformation** | `NEG [ebx+6]` 條件 + 全域累加；尚無真實 wire trace |

### 具體 Client 待逆向（按優先序）

1. **B01/T02 接合**：從 `0x806CF0 WSARecv/IOCP` 到 `0x4930E0` 的哪個 mode/dispatcher，如何取得 scene result table 指標、在哪一 lane 用 `index 0x0E` 呼叫 `0x436C40`；提供完整 caller/virtual target、frame header、length 與錯誤分支。既有 `0x4930E0` 不是自動證明全部中間邊。
2. **B04 深層 consumer**：case1/5/6 的 `0x49B0D0`、`0x7ABCD0`、`0x5855B0` 等下游與 actor writer / effect queue 之間的語意；屬 T12-C/D 下一目標，未假裝本批終端已全部閉合。
3. **T12-D/E**：row 值之外的 HP/status sync writer、死亡 flag/動畫與移除、復活/重新出場接口，明確區分 Server 決策及 Client 可證效果。
4. **觀測限制**：本次沒有原版真實 traffic / runtime capture；沒有從伺服器反推原版 damage formula。若未來得到封包/trace，先保留 receive 前 bytes，再比較 handler 後可能變動的 buffer。

### 方法與非執行限制

本批僅以本地唯讀 `sha256sum`、`file`、`objdump -h`、`objdump -M intel -d --start-address=... --stop-address=...` 及 Python `struct.unpack_from('<I',...)` 查看原始 BIN；分析沒有執行 Tartaros。重要跳表是 9 個 4-byte data entries，位於 `[0x4B1914,0x4B1938)`，**不是函式指令**；`[0x4B18C7,0x4B18D9)` 是多分支共享尾段，不能當成固定 EDX 語意的獨立函式。未聲稱分析完整程式、未修改主線或任何原件。

### 可引用來源（以本次 SHA 適用的版本為限）

- `kr/tasks/T12/{README.md,task.json}`、`AGENTS.md`、`research/dispatch/inbox/T12.md`、`research/requests/index.json`（當次 main `ac3aa886...`）
- `kr/evidence/0124ca7a9184fc541708d37dee2516ec3d5f7bd788b1bbeb9df8f86399f81f71.txt`
- `kr/evidence/81a3fe379d433685e342d65c96db6aa78a52e0510f294cc3e338c4e7b63269b6.txt`
- `kr/evidence/b031b1f51bb9d8958fbaaa555b45f8b38845abd027e049d064525c747fabac34.txt`
- `shared/CLIENT-MODIFICATION-POLICY.md`、`shared/verified-knowledge/README.md`


## 13. B01/B03 追加全 .text 靜態 xref 與第二種 wrapper（同批補充）

為避免只憑歷史 vtable 命名漏看原生其他 consumer，本次對 BIN `.text` 作完整靜態 `objdump -d`，以精確 direct-call 為索引（全文約 120 MiB，僅作本機臨時查詢資料，不上傳 binary）。找到 `0x4ADD50` 初始化入口的直接呼叫，例如 `0x422FB3`、`0x4369D2`、`0x4564F2`、`0x48F6EA`、`0x49530E`、`0x4C46F2`、`0x4C4AC2`；也找到**另一條**共用 result 包裝器：

~~~asm
436B95  mov eax,[ebp+10h]
436B98  mov esi,[ebp+0Ch]
436B9B  mov edi,[ebp+08h]
436B9E  push eax
436B9F  push esi
436BA0  push edi
436BA1  call 4B0640h         ; 共用結果消費
436BAB  test ecx,ecx
436BAD  jne 436C2Bh         ; 只有成功才繼續
436BAF  cmp esi,2
436BB8  add esi,0FFFFFFFEh
436BBB  mov eax,4EC4EC4Fh  ; 同樣的 /13 row-count
436BC0  mul esi
436BC2  shr edx,2
436BC9  add edi,4            ; row+2
436BD0  mov al,[edi+2]       ; case= row+4
436BD3  test al,al
436BD7  sub al,2
436BD9  cmp al,1             ; case0 或 case2/3
436C0D  movzx ecx,WORD [edi]
436C10  movzx edx,WORD [edi-2]
436C1B  call 54A8F0h        ; 三英雄槽回饋
436C23  add edi,0Dh
~~~ 

此 `0x436B70..0x436C3F` 包裝器與 `0x4C4920..0x4C4AB9` 在「common receiver 成功後，對 case0/2/3 呼叫 `0x54A8F0`」方面一致，但**兩者是不同原生函式**：`0x4C4920` 另有 `FB7A7C/78/80` 三個 virtual index 來源的暫存與清理。暫不以缺乏 RTTI 的直接證據替 `0x436B70` 亂命名 Scene 類型，也不把歷史「CMissionField」名稱自動套到它。

**結果**：B03 現在至少可指出 `0x4B0640`、`0x436B70`、`0x4C4920` 三條具體 receiver/包裝路徑；新增 direct-call xref 不等同已閉合 socket/outer frame → scene table，B01 的 T02 依賴仍保留。對其他 Task 的函式、owner、catalog 沒有寫入。
