# 補證：Q active 對 current controller +58 的實際影響

日期：2026-11-14。此稿為 [events.md](events.md)／[lifecycle.md](lifecycle.md) 的定向補證。原件仍為 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的 KR `Tartaros.bin`；固定反編譯導航 commit 為 `552e05a024505a3773095f951c285216051ce2a1`。

## 結論

**current controller +0x58 會在常規控制封包生成階段，把該通道的控制 word 歸零；它不是單純的選取狀態。** 已沿已知 Single／Formation／Tutorial controller 的實際 vtable methods 閉合到共同 consumer `5452C0`，再到 C2S `000A` 的 5-byte actor control row。

Q active 每次到達 `5615C4` 時寫 DWORD `+58 = 1`。在下一次符合條件的共用控制處理中，該旗標會清除 row 的 `+2:u16`，包含 `0x8000` 移動 bit 與低 15 位按鍵／動作量，同時保留進入 mapper 前的方向 byte。Client **仍可能發出包含零控制 word 的 `000A` row**；這不是停止所有封包、停止收包或停止 world update。

這使「讓 Q active 長期開啟，就能把有限演出當普通戰鬥常駐工作」多了一個已證的行為衝突：Q pump 會持續要求這條控制輸出被中和。仍不能把它擴張成「所有攻擊／技能 opcode、所有本地動畫或所有輸入都被封鎖」。本輪沒有完整動作碼到全部攻擊／技能的固定契約，也沒有實機量測 update 順序及恢復延遲。

## 1. 已證的 writer／reset 和資料寬度

| 動作 | 原件 | 寬度與條件 |
|---|---|---|
| 初始值 | base controller ctor `544C71` 令 EBX=0；`544CE0` 寫 `[EDI+58]=EBX` | DWORD，初始 0 |
| Q writer | `561587` 檢查 scene manager+28；非零進入，`561594` 令 ESI=1；`5615BF` 取 FBA7A4；`5615C4` 寫 `[EAX+58]=ESI` | DWORD，寫 1；writer 位於 scene manager+2C 的停泵檢查之前 |
| 讀取 | `5458D8`、`54593E`；額外 actor 路徑 `545A9D`、`545AAC` | 都是 DWORD 與 0 比較 |
| 中和 control row | `5458E0`、`545955`；額外 actor 路徑 `545AA5`、`545ABF` | 寫 WORD 0 到 row+2，沒有改寫 row 的 EntityId |
| 消費後清除 | `545B7D` 讀；`545B83` 寫 0 | DWORD；到達共用方法正常尾端時清除 |

證據：`native-windows.json` 的 controller-input 群組 P01/P02/P07/P08/P09，原始 VA/raw/hex/hash 俱全。

`+58` 是會被消費清掉的暫時請求，不能說成「寫一次後永遠鎖住」。但 Q active 的既有 update 路徑會再次寫 1，故也不能因為 consumer 最後清零，就推論常駐 Q 不影響下一個控制輸出。

此外，`5452C0` 的最前方若 controller+04 為 0，直接跳 `545B8A`，略過 `545B83` 的 reset。三個具體 subtype 的 v+2C 也有先行 gate。精確說法是**每次到達正常消費尾端會清除**，不是任何狀態下每幀必定清除。[P18]

## 2. 三種 controller 確實匯入同一個 consumer

本輪沿用既有三種 controller 的型別與 vtable，不重做 controller census。只為已知 virtual call 精確讀取 +2C 與 +48 的六個 table entries。

| Controller | vtable | v+2C | 進共用 5452C0 的原件呼叫與 gate |
|---|---:|---:|---|
| CSingleController | C0FAC4 | 548A90 | controller+04 非零後，`548AD2 → 5452C0` |
| CFormationController | C0FA14 | 547F90 | controller+04 非零後，`547FCB → 5452C0` |
| CTutorialController | C0FB1C | 548CB0 | controller+04 及 +DC 均非零後，`548CC7 → 5452C0` |

證據：P03–P05，以及 `native-windows.json` 的 controller-input-data 群組六筆精確 vtable data。Tutorial+DC 是這個 subtype 的額外 gate；不能從共用 callback 存在就略過它。

`5452C0` 除了 controller 啟用、受控 actor 及其 slot 啟用條件，還有 +78 的早退、v+18 的前置處理結果、時間間隔與可送額度等 gate。本稿不把 Q 寫入 +58 說成「無條件立刻送一個停止包」；結論適用於進入常規 `000A` row 產生支線的處理。

## 3. row 歸零之前，mapper 產生的是什麼

共同 consumer 對三個受控 actor slot 呼 controller `v+48(index, row)`。此槽精確解析為：[P14–P16，六筆 vtable data]

| Controller | v+48 | 具體流向 |
|---|---:|---|
| Single | 548A20 | 需要主 actor；一般狀態走 `546100`，另有 motion／controller 欄位的中和支線 |
| Formation | 5480A0 | 對應 slot actor 必須存在；index0 走 `546100`，其他 index 走 `5480E0` |
| Tutorial | 548D10 | tailcall `546100`，前方 v+2C gate 仍適用 |

`546100` 會先把 row+2 清零，保存既有 actor 狀態／方向；其有效 actor、state 能力及角色資料等檢查仍適用。本輪追出與問題直接相關的兩部分：

- `546263 → 546780` 取得 controller+5C 已彙整的按鍵值，並加入 `547240` 的短按／長按狀態結果。`54628F..54629E` 將這個量寫入 row+2 的 **低 15 位**，保留高 bit。沒有在本輪重新解釋全部按鍵到所有攻擊／技能的對照。[P10/P13，固定來源 546780、547240]
- `546374..546440` 用 actor 方向、actor+A0 位置、v+60 速度與移動步進／可行性結果，設定或清除 row+2 的 **0x8000 bit**。這不是從數字猜它的用途，而是從實際方向／速度／位置支線及其 bit writer 判定為此控制通道的移動量。[P11/P12]

因此，共同 consumer 之後把整個 row+2 寫 0，確實同時抹去上述移動 bit 與該通道的按鍵／動作量。可以稱為「控制 row 中和」；不能據此宣稱每種出招來源都會經過它。

## 4. 000A 的 producer → row 過濾 → sender 已閉合

`545829` 令 opcode 值為 `0x000A`，建立 6-byte 初始 send view，後續每個 actor row 為 5 bytes。以下為 Client 的組包 view，不重定義 socket 外層 framing。[P06]

| row 欄位 | 本輪原件證據 |
|---|---|
| +0:u16 EntityId | `54590D..545911` 從 actor+4 寫入 |
| +2:u16 control word | mapper 提供；+58 非零時中和為 0 |
| +4:u8 direction | 正常由 mapper 提供；中和時回復進入 mapper 前的 actor+B0 byte |

對正常產生新 row 的路徑：`5458CE` 呼 mapper，成功後 `5458D8` 看 +58；非零便在 `5458E0` 清 control word、`5458E9` 還原 row 的方向。還會用 mapper 前讀到的 actor+B0 值呼 actor v+58。最後保留正確 EntityId，照常把 5-byte row 放入 buffer。[P07]

對 mapper 沒有新 row 的路徑：若 +58 非零且上次主要控制 word（controller+6A）仍有 `0x8000`，仍可在 `54594F..54598B` 建立控制 word=0、舊方向、同一 EntityId 的 row，經 `5471B0` 加入 buffer。這是具體的停止／中和輸出條件。[P07/P17]

額外 actor 清單的路徑在 `545A99..545B1A` 有相同 +58 判斷和 WORD 歸零。它讀的是該清單選出的 actor，不能直接等同所有世界怪物。[P08]

當 buffer 長度大於初始 6 bytes 時，`545B71` 仍會呼網路 send interface；隨後正常尾端 `545B83` 清 +58。因此**零控制 row 可以真的進入送出資料，不是僅修改一個 UI selection 狀態**。[P09]

## 5. finite Q 與普通戰鬥常駐工作的界線

對 `lifecycle.md` 可以追加的精確判定是：

> 普通場景已能 tick 有限 Q scene，但在 Q active 期間，native pump 會反覆要求中和 current controller 的常規 000A 控制 row。它會清除該 row 的移動 bit 與按鍵／動作量，並可送出零控制 word。因此不能只延長 Q active，就假設仍保留完整普通玩家控制。適合長期處理戰鬥事件的 runtime，尚須有不依賴這個 Q active 副作用的既有啟動／tick 契約，或以實際控制語意證明候選可用。

這項新證據不等於「Client 停止普通戰鬥」：

- 所證是受控 actor 的這條 C2S 控制輸出；沒有證明所有攻擊、技能、UI 操作、其他 opcode 全被阻止。
- mapper 在中和前仍會執行部分計算；不能說本地所有計算、動畫或 network receive 都停了。
- 世界 CMonster 的收到狀態／移動資料及其 update 是其他支線，沒有由這個欄位讀取一併否定。
- consumer 的 reset 是暫時請求的清理，不代表 Q active 的 writer 停止。update 實際先後、第一次／最後一次中和時間，以及恢復輸入時的 delay，仍須在既有生命周期上整合／實機驗證。

Server 需求因此更明確：若要用普通 Client 做長時間關卡事件或群清觀察，不可把有限 Q scene 常駐視為已完成替代；須先選定既有且保持預期控制語意的 runtime 入口。有限演出仍可沿已知 scene 契約使用；本輪沒有提出修改 Client 或新增 Client 不支援 opcode 的方案。

## 6. 查驗範圍、來源與有界限制

沒有以 `+58` 在全 BIN 泛搜，也沒有重做全部 controller census。導航先讀以下 20 個已知 vtable method／base ctor：

`544C40, 545040, 545BA0, 545C50, 545E20, 546EF0, 548730, 547A60, 548A90, 547F90, 548CB0, 4443B0, 547C40, 5486E0, 547C80, 444450, 547CF0, 4447A0, 548030, 4447E0`。

再沿其具體 callsite／virtual target 讀取 10 個 helper：

`5452C0, 548A20, 5480A0, 548D10, 5471B0, 546100, 5480E0, 546780, 545F30, 547240`。

其中 `546EF0` 的 `actor v+58` 是 actor 的虛方法槽，不是 controller 的 DWORD +58，沒有把這種表面相同 offset 當成欄位 reader。

本題 30 個固定來源的 commit／path／Git blob／檔案 SHA-256 已併入 [source-manifest.json](source-manifest.json)，與前面分題重複的來源以角色合併。原件補證已併入 [native-windows.json](native-windows.json)／[native-windows.asm](native-windows.asm) 的 controller-input／controller-input-data 群組：**18 個指令窗口、1,638 bytes，以及六個精確 vtable entries**；source_id 保留 P01–P18 及六個 P- 槽位 ID，每個窗口的反組譯 byte 覆蓋完整，無截斷。三種 subtype 的共用 consumer 呼叫及 v+48 target 另列 [native-relations.json](native-relations.json)。統一唯讀重驗方法見 [README.md](README.md)；`verify_evidence.py` 核對原件 bytes、槽位、直接 call 及固定來源，不執行 Client 或 Lua。

未覆蓋所有可能 writer、其他 controller subtype、每一個外部輸入或所有技能發送管道。結論只適用於上列已閉合的三種 controller／共同控制 row 路徑；不以此有限讀集作全域 xref 完整性主張。
