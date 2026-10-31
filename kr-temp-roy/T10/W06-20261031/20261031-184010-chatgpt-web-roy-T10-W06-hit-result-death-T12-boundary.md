# T10-W06 — KR 000E 戰鬥結果、000F 技能不可用、001A 物件消失與 T12 跨功能證據（BIN-first）

2026-10-31 Asia/Taipei，chatgpt-web roy。**本輪有界結論**：已從原始 KR BIN 驗證 S2C 000E 的 13-byte 結果列、雙 actor 查找、9 個子類型分支、在某條分支中對接收資料原地反號及累計、場景派生 handler、000F 不可使用技能、001A 物件移除。**沒有**證明某個 Z／Z+X 操作的 C2S 000A 必然得到這些回覆，也未證原版 Server 命中公式、確切扣血、死亡或復活時序。這是 T10 與 T12 的 Client 證據交接，非 T12 全程結案。

## 0. 來源、權威與作業基準

- 原始只讀 KR `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本次本機再核對。未運行、修改、注入或連線原版 Client。沒有原版 Server trace。
- PE32 x86，.text VA `401000` raw `400`，VA−raw `400C00`；.rdata VA `BD2000` raw `7D0600`。使用 GNU objdump Intel＋Python raw bytes、SHA256、little endian pointer，沒有把 AI fixture 當 native。
- 開工 main `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`；T10 branch `71d2856b3ac383d5c0e78653b645656db3f14da1`。compare ahead10、behind0，已包含最新 main，不需產生無內容 merge。仍使用 `t10/roy/chatgpt-web`，不新增分支、不改 main。
- 查閱 AGENTS、T10/T12 README（T10 七項 T01 退回仍未 RESOLVED）、S00 派工 README、T10 inbox（無待處理 RR）、唯一 research/requests/index.json、shared verified knowledge、Client 改動政策。依當次 W06 授權，只提交 T10 範圍的分析，不改 T12 owner、RR、catalog 或既有原稿。
- 本報告同目錄保留 `W06-native-audit.json`（24個原件窗口 SHA256、93個經 objdump 指令邊界核實的 byte anchors、1 個原始 nine-entry dispatch table）與 `verify-native.py`。這些校驗只驗證原件內容一致，不是 T01 對全部 CFG／語意的 FULL-PASS，不是玩法驗收。

## 1. 玩家戰鬥 C→S 與 S→C 之間的真實分界

由 W03：Type0 Z logical13=bit0、X logical14=bit1、C logical15=bit2；短按與 held 都可以 OR 同一 controller WORD。Z+X→0x03、Z+C→0x05、X+C→0x06，SkillMatrix 依序選 col4/5/6；不是兩鍵各送一個技能。C2S `000A` app payload 是 `6+5×N` bytes，只有 N≥1 的 builder 路徑才呼叫 selector0 manager virtual+10；controller/actor/matrix/queue/socket 都有 gate。

收包有界路徑（既有 T02/T10-110/W04，原件在相關窗口重查）：
~~~text
WinSock recv completion / connection gate
 -> 807B40 framed packet handling
 -> 807E50 copy decoded app payload to record+8
 -> 8040A0 queue append; 804740 / 804100 category & alternate-bucket drain
 -> receiver callback 4930E0, category2 and active state
 -> 4ADD50 8-byte per-key handler table
   key0B -> 4AFE60 (actor status/movement 8-byte rows)
   key0D -> 4B01C0 (actor status 9-byte rows)
   key0E -> 436C40 -> field vtable+28 -> 4B0640 or 4C4920
   key0F -> 4B19D0 -> controller vtable+3C -> candidate 545C50
   key1A -> 4B28D0 -> delete/registry remove
~~~
**這是 Client 確定的多條條件式 consumer，而非某一 C2S 000A 的完整原版 Server ACK／結算 mapping。** app key、frame prefix、connection selector、Server 私有規則是不同層。

## 2. 000E 真正的 field dispatch 與 13-byte row

原件 `4ADDEA mov [eax+0x74],0x436C40`；8-byte handler slot 的 `base+4+8*14=base+0x74`，故 key14/0x000E 是 `436C40`。`436C40 mov eax,[ecx]; jmp DWORD[eax+0x28]`，透過當前 field vtable 分流；已知 CMissionField vtable+28 = `4B0640`，CScenarioField/CInfiniteDungeonField 候選 +28=`4C4920`。本輪的 `4C4951 call 4B0640` 進一步驗證後兩種場景先用共通 result handler 再額外消費，同一個 row 不必送兩封包。

`4B0736` 讀長度 L；L<2 時 count0，否則：
~~~asm
4B0742 lea edx,[eax-2]
4B0745 mov eax,0x4EC4EC4F
4B074A mul edx
4B074C shr edx,2          ; floor((L-2)/13)
4B0770 imul eax,eax,0xD  ; 13-byte row stride
4B077F lea ebx,[eax+ecx+2]
~~~
所以 app buffer 布局是首2 bytes key+後面 N 筆13-byte row；L=15一筆、L=28兩筆。尾部非完整13 bytes在此 loop count 中會被截斷；不是外層已證安全驗證。

| 13-byte row offset | Data | 第一手直接讀取 | 只可確認的用途 |
|---:|---|---|---|
| 0 | u16 LE | 4B07AF、4B09A0、各 case | 第一個 actor map key；也會與 controlled actor slots 比對 |
| 2 | u16 LE | 4B0819、4B0A20、各 case | 第二個 actor map key；某些 case 改用此 ID 找受影響的 slot |
| 4 | u8/s8 | 4B095C / 4B0B55 | 原生 switch index 0～8；並在部分路徑比較0/1/2 |
| 5 | s8 | 4B0B7A、4B118B、4B1313、4B15DA | 各 subtype 的附加顯示／效果分支 |
| 6 | i32 LE | 4B0AF6、4B0B36、4B0BF7 等 | 數字／效果／累計值；不可自命名官方 damage formula |
| 10..11 | 2 bytes | 此處主要 handler 未定位到單獨 direct讀 | 仍未知；不能稱永久保留或全局不讀 |
| 12 | s8 | 4B0B71、4B1673 | 某些 subtype 的額外效果參數 |

第一手 source/target actor lookup：`4B07AF movzx EDX,WORD[EBX]`、`4B0819 movzx EDX,WORD[EBX+2]`，兩次都走 `FAB138 / 82EF00` ordered tree、sentinel `FAB13C`、node+0x10 actor pointer。缺第一個 object → `4B0852` log/skip this row；缺第二個 → `4B0868` log/skip。前置 `4B06F6..4B0731` 還用 `F93930` 在 `FAB148` 查 local identity/tree，沒有相符 owner 會以 EAX=0x80004005 早退；所以收到 result 不代表已準備好所有角色物件。

## 3. 九路 case table：從真正 bytes 解碼，不能把 case index 當普攻連段數

`4B0B55 movsx eax,BYTE [ebx+4]`；`4B0B59 cmp eax,8`；超出 0..8→`4B18D9`；`4B0B62 jmp DWORD[eax*4+0x4B1914]`。

| subtype | native table target | 本輪原生確認的處理分支 |
|---:|---|---|
| 0 | `4B0B69` | row+5/+12 和雙 actor 供 49B140→5521D0 位置／呈現；可條件調用 545260 slot lookup、49B0D0→7ABCD0；寫 victim-like actor+40C/410/414 |
| 1 | `4B118B` | row+5 驅動子分流，準備不同 UI/文字/effect payload，使用 49B0D0 和 7ABCD0 |
| 2 | `4B0EEC` | 位置效果／visual，部分 actor+40C/410/414 更新及 slot lookup |
| 3 | `4B0E5A` | 按第1/第2 actor slot 存在與否，分別使用 7AC030 的0或2參數 |
| 4 | `4B0D14` | 另一組 actor+40C/410/414 更新、49B0D0→7AC030等效果 |
| 5 | `4B15B7` | row+5 值0/1/2進不同 feedback、文字和 7ABCD0／attached effect |
| 6 | `4B1313` | row+5 多重分支及 row+6 value 的數字呈現／7ABCD0 |
| 7 | `4B18D9` | **該 subtype 在此 Mission handler 直接跳到共通下一筆**，沒有此 case 專屬 effect |
| 8 | `4B1673` | row+5/+12，角色 slot 與 effect fields、數字/附屬效果等 |

**重要區分**：4B1914..4B1937 是 9×DWORD 分派資料，objdump 直線反組譯會顯示無意義的 IMUL/ADD，「不能」把那裡當真實執行的 x86 程式。各個 subtype 0..8 的正式命名無符號證據；它們**不是**技能ID、普攻第一～九段、官方傷害類型、死亡狀態等已證語意。Subtype7 的直接跳過只限定這個 handler，不代表其它場景／其他 S2C 永不做效果。

## 4. 新的結果欄位突變：某些情境收到的 +6 被原地取負並累加

在 `4B098A..4B0B55`，某些 subtype 0/1/2 和 controller 的三個 actor slot、`FAB134` 持有的 u16 ID list 比對，再決定是否使用 local global counter。原生：
~~~asm
4B0AF0 cmp BYTE [ebx+4],1
4B0AF6 mov eax,DWORD[ebx+6]
4B0AF9 neg eax
4B0AFB mov DWORD[ebx+6],eax     ; 注意：改寫已解析的 row 自身
4B0B36 mov ecx,DWORD[ebx+6]
4B0B3F add DWORD[F942C4],ecx
4B0B45 jns 4B0B55
4B0B47 mov DWORD[F942C4],0
~~~
**結果**：若上述 slot/list gate 成立且 subtype=1，某次 000E payload+6 的 i32 會在 Client 用於後續 subtype case 之前**直接被修改**；之後可累計至 F942C4，結果為 signed-negative 時被設0。F942C4 的業務意義（HP? UI分數? tally?）目前不明，不能宣稱它是 actor 生命值；也不能以顯示為負的數字回推 Server 原始傳值必為負。和 Client 的 in-memory effect/統計資料分開保存 raw wire capture，避免雙重取負。

## 5. Client 直接寫 actor 效果狀態 != 直接扣 HP

000E 的部分 subtype 在 `4B0BAB/4B0BB7/4B0BC1`、`4B0D7F/4B0D8B/4B0D91`、`4B0F57/4B0F63/4B0F69`、`4B16BB/4B16C1/4B16CB` 等位址寫 actor+0x40C/0x410/0x414（多為0/6的值，及 effect state）。此函式在本次視窗**未直接**對 actor+3C8/3CC/3D0 等 resource-like 欄位做 store，不能據此當作完整的「HP減掉傳入傷害」公式。這只是**4B0640 直接 writer 的否定**；其後的 `49B0D0`、`7ABCD0`、`7AC030`、`5521D0`、`7D28E0`、`6D89C0` 可能有更多 actor/fx 狀態間接處理。本輪沒有對所有 callee 的最終具體 vtable 及實例完整審核，絕不外推全 Client 無傷害／死亡狀態。
 
從實際呼叫可分：
- `4B0B91 call49B140→4B0B97 call5521D0` 是 result 顯示/位置情境，依 row+5/+12 等額外參數。
- `4B0BF2 call49B0D0→4B0BFC call7ABCD0`、其他 case 同樣用 row+6 和局部參數分流，確有 outcome/feedback emitter。
- `4B0DE0 call7AC030`（EAX=1）、`4B0E9F call7AC030`（EAX=0）、`4B0EE2 call7AC030`（EAX=2）代表此 effect helper 的不同參數，不是三段攻擊。
- `7D28E0` 特效必須 actor+15C / actor+370 / attached+AC 等 guard 有效；缺少附屬元件時此特效可不出現，不能把沒有特效推成 Server 沒處理結果。
- 另有本地條件比較 actor+9C 與 F93930（`4B08B8`），不能未查角色實例就自稱所有遠端 actor 同本地效果。

**T12 設計重要反例**：既有 45/65 命中半徑、20/35/60 數值、延遲0.2 為 AI fixture，不是原版傷害/受擊/死亡計算法；本次 000E 顯示結果函式不把它們提升為 native。

## 6. Scenario / InfiniteDungeon 場景確有獨立 consumer，但沒有額外 Server 傷害判定

`4C4920` 的派生場景 vtable+28：
~~~asm
4C494E push [caller arg]
4C4950 push P
4C4951 call 4B0640             ; FIRST shared base result consumer
4C495B cmp eax,ebx
4C495D jne 4C4AA6             ; error branch skips extension
4C496F mov eax,0x4EC4EC4F     ; result 13-byte row count again
4C4974 mul esi
4C4978 shr esi,2
4C49B4 call controller vtable+1C for actor slots 0,1,2
4C49BA / 4C49D3 / 4C49EC store FB7A7C / FB7A78 / FB7A80
4C4A01 add edi,4               ; current row+2
4C4A06 mov al,[edi+2]          ; row+4 subtype
4C4A43 movzx ecx,WORD[edi]    ; second actor ID
4C4A46 movzx edx,WORD[edi-2]  ; first actor ID
4C4A51 call 54A8F0             ; subtype0/2/3, controller/actor gate
4C4A56 add edi,0xD
~~~
`54A8F0` 查 controller 三 slot、角色狀態與目標，部分 branch 更新本地 feedback/target pointer。**這是收同一個000E後的 Client 場景額外處理**，不是 Server 送兩包、不代表多一次命中裁決，也不能自稱所有場景同路。CMissionField 只有基底0x4B0640，其他兩類有這個 extension 的候選 vtable 路徑。

## 7. 000F「技能不可用」提示不能冒充完整 000A ACK

應用 key15/0x000F handler `4B19D0` 透過 `FBA7A4 controller vtable+0x3C`；已知候選實作 `545C50`。`545C7B mov eax,15;545C80 cmp WORD[callback arg],ax` 確保該命令；`545C8F cmp BYTE[P+7],0`，非0時音效服務的原版標記 **CANNOT_USE_SKILL**；`545D0C cmp BYTE[P+7],1`，符合時按 `P+8 bit0/bit2/bit4` 再走不同提示/文字 helper。因此 Client **確有處理「技能不能用」的 UI／音效支鏈**；但還欠 P+2..+6 意義、P+7 value1之外 enum，以及它是否與某一次 C2S000A action/mask 一對一綁定。不能直接把所有0x000F都叫「Z+X傷害被Server拒絕」。本段也未完整審外層最短長度，Server 不該只送 WORD 而假定 P+8 可安全使用。

## 8. 001A 物件移除與「死亡」不同

原生 `4B28D0` 先計算 `N=floor((L−4)/2)`（L>=4），P+4 起每筆 u16 actor key；`4B295C` 取 key，`FAB138/82EF00` 查 actor，失敗可 log 跳下一筆。命中時依 actor type byte/attached state/ratio 有條件清除 visual，類型2/8/9 的 `4B2A25..4B2A51` 還可能呼叫 `4CC8B0`。`4B2A56..4B2A87` 依受控 controller 是否持有此 actor 可調 virtual+0x14；**`4B2ABD→4B2AC2 call 4DFBC0` 移除 actor map/index**，4DFBC0 另有物件 virtual+0x14/+0 callback、node+10 clear 和 map erase。

這證明收到001A可令物件從 Client actor registry 消失，**卻沒有證明它是「被普攻打死才發」或死亡處理唯一方式**。可能是離開可視範圍、換圖、地圖清理等；死亡狀態可能先在 map 上保留 actor。故不可用「已解析001A」冒稱死亡、復活/掉落結算已完成；真正 HP<=0、death clip state、重生或消失的完整 Client writer 和 Server 對應資料仍是 T12 的關鍵缺口。

## 9. 玩家情境×Client×C→S×S→C×效果×責任

| 玩家／事件 | Client 本地判斷 | C→S | S→C 有界觀察 | Client 動作/效果 | 分工 |
|---|---|---|---|---|---|
| Type0 Z 普攻短按／持按 | phase1/2 OR mask1；matrix/CD、actor gate | 000A只有有 row/connection 才可能發送 | **本次是否回000E未知** | 預播、命中/擊退/HP 未證 | T10/T11/T12 |
| Z+X/Z+C/X+C | mask3/5/6、matrix4/5/6 | 同000A，一個 mask並非兩筆單鍵 row | 與000E的直接 correlation未知 | 連段/效果身份未證 | T10/T11 |
| 收到000E，兩 actor ID都存在 | network+current scene route | 非此handler主責 | 13byte row＋subtype0..8 | 可顯示結果、設 effects；不必直接寫 HP | Client bounded，T12 |
| 000E actor missing | actor tree lookup fail | 不證玩家沒按鍵 | 跳過此 row，其它 rows繼續 | 此 row無目標 effect | 有界 negative |
| 000E subtype1 及 local ID list gate | 可反號 row+6，F942C4 accumulate/clamp | 不自動多發 C2S | 同一已收到 row | UI顯示數值可能與原值不同 | W06新增 |
| 000E subtype7 | switch index7 | 無新C2S | 直接跳下一 row | 此 Mission branch無case effect | 有界 negative |
| Scenario/InfiniteDungeon 000E subtype0/2/3 | base處理後追加local controller slots gate | 不需第二包 | 同一000E row | 54A8F0 feedback/target候選 | Scene-specific |
| 000F P+7非0 | controller slot+3C | 非本次000A直接回證 | CANNOT_USE_SKILL / hint | 無法施放提示，不等於完整Server拒絕協定 | Client UI |
| 001A actor ID 存在 | actor type+attachments + controller guard | 不涉及攻擊發送 | 2byte ID list | registry remove，原因不明 | T12 |
| 角色 HP 變零／死亡／復活 | 未見確切健康 writer / actor state machine | unknown | 000E/001A不可單獨等同 | 死亡/復活動畫與生成未知 | Client待逆向/T12 |

## 10. 未完成的具體 Client 路徑與 Server 開發界線

**Client 已確認**：000E field+0x28 route、13byte rows、九路 subtype、actor map存在性、row+6 特定變號與 global accumulator、效果狀態寫入及 Scenario extension；000F技能不可用、001A物件移除是獨立的 app consumers。**不能把這些消費端直接視為本地命中計算**。

**Client 待逆向**：（a）沿 `49B0D0→7ABCD0`、`7AC030`、`7D28E0`、`5521D0`、`6D89C0` 深入 actor subtype / actual animation state writer / UI consumer，確認 real HP、死亡狀態 writer；（b）000E row+10/+11 是否有後續或場景間接讀者；（c）W03 C2S000A row mask/actor→哪一個000E row 對應、何時接收，還需行為 ID 與 Server channel/response 消費者；（d）F93930 local actor identity、actor+9C、不同 scene/instance 的真正來源；（e）000F欄位P+2..+8與 skill cast cause、正式失敗 enum；（f）獨立生命週期 S2C死亡/復活/生成與001A的關係。**不能只因缺原版Server就停止上述可靜態追的Client路徑**；這些欠證的項目在本輪保持未閉合狀態。

**Server 待開發**：相容 Server 須裁決動作、命中、傷害、角色生命狀態、移除/重生與對附近玩家廣播，並供給 Client 能解析的精確結果消息。但原版Server實際公式、000E結果值如何計算、row+10/+11、傷害/死亡/拒絕回覆各自時機仍未證；S00依 REQ/SPEC/GAP/ADR/TEST 流程去重整合，不能用 AI fixture 命中半徑45/65、固定傷害20/35/60或delay0.2假充原版規則。

**跨功能待整合**：T02收發、T09角色動作、T10按鍵/連段、T11可用性/冷卻、T12命中/死亡、S00 Server規格。**待遊玩驗證**：NOT_RUN（無KR真實Server socket、Client runtime hit/death animation、HP delta replay）。T01 FULL-PASS、RR ACCEPTED、S00 SPEC STABLE、真正Server playable各自獨立，不因本 commit 生效。

**W06交付狀態**：本輪所要求的「T10普攻與T12結果消費分界」得到可驗證的 native interface、反例及具體 Client 下一入口；但完整的一次技能從動作→命中→扣血→死亡→復活尚未閉合，故**原生結果處理子鏈已交付、完整 gameplay 仍待續**。

## 11. 可追溯的原生/舊來源

本報告同目錄附 JSON+只讀驗證器，BIN sha 強制檢查、原始程式窗口24個與93條 instruction bytes、4B1914九筆跳轉表原始little-endian校驗。原件資訊也可用 `objdump -D -Mintel --start-address=0x4b0640 --stop-address=0x4b1912 Tartaros.bin` 重現（注意 0x4B1914後是資料）。

既有有界文稿：`kr/evidence/0124ca7a9184fc541708d37dee2516ec3d5f7bd788b1bbeb9df8f86399f81f71.txt` Git blob bad6176b400a4ac0154762ac20501122a0081e74（T12結果route）；`unclassified/evidence/41fa17caac92ad6409c7de8bc4aa770123b0b0671b54a16ad035dce179ea11d7.txt` blob 9697f43ae371d668c88fa79a46424d1af6ab5c63（000E handler）；`kr/evidence/401e0526feff1cb6f88298a2b5ec7bed454705259fd5846c0f80283664c5ff0d.txt` blob dda5fbadd5341ff139209d004f014ae3e735ad31（000F/001A限定）；`unclassified/evidence/00723626cc0ae186c8b8745497c9599a33f3ee9e06ec40c472b79d33fcc18a5d.txt` blob d5ad765e06335bf7f97fca877416962557078a67（54A8F0 feedback）。

W03 combo/000A：`kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md` blob 0d17362eb300ab8ea002c3d6380d5a41039665bc；W04 S2C：`kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md` blob 8e915daab064177490d5de0b3f193810a5de2f41；W05 timer：`kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-skillmatrix-resource-timing-T11-handoff.md` blob b3c0f31db311cce06f3a87fcbbf4f938171ce972。

本文的 result/case/effect 是研究描述性假名，不是原版 Server/C++ 符號。