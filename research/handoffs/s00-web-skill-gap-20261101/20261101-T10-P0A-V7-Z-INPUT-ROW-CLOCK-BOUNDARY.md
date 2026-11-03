# T10 / P0-A — KR v7 Z 連點、放開、000A 多 row 與 Clock/Reset 定向補查（2026-11-01）

> 狀態：**有限原生確認，完整「Z keyup→連段下一段」仍未閉合**。保留原本 T10-116／20261101 row 勘誤原稿；本次不更改 Task、RR、T01 return、owner/catalog、不執行 Client、Server，不以工作副本 0.4 秒／舊 0.65 秒當原版門檻。

## 0. 版本與重現

- S00 精確工作卡：commit `7efc6f5219e05d7042f25f86627cd1b096ec1540` 的 `research/handoffs/s00-web-skill-gap-20261101/FOLLOWUP-02-V7-COMBO-AND-HURT.md`；Git blob `47bff869dca72dcad4bc4a70c8df87295af0d216`。
- 既有 Web 成果：`4064846ff77fbf3884fc84830ed35f60c9d8781d`，3 篇有界報告，S00 後續稱已核七段 BIN 視窗 hash；**該核對不是全文 FULL-PASS**。
- 新對話查核：`main=ac6aac673426459df2a778d20a80c623b8559a92`；`t10/roy/chatgpt-web` 相對 main ahead 3、behind 0，已包含當時最新 main，依 T10 既定規則不產生空 Merge。T10/T11 main 收件箱無待處理 RR；T10 T01 NEEDS_FIX 維持原狀。
- **本輪原始檔實算**：`Tartaros.bin` 長度 12,472,320，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。工具為 LLVM llvm-objdump（x86 Intel）+ Python hashlib/struct；未讀到保存的 Ghidra 專案，不冒充該工具的 decompiler output。PE32 `.text` VA 401000／raw 400，即 raw=VA−400C00；`.rdata` VA BD2000／raw 7D0600，即 raw=VA−401A00；`.data` VA D61000／raw 95E800。
- 之前已證的 `000A` row/selector0 transport 與其來源限定仍沿用：`kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt`，blob `3710f1360acbac739247ffd9cbdb8cee054349c4`。本輪的新增內容主要為 **發包時鐘閘／reset 與與 Z 尚未閉合的界線**。

## 1. 真正的正常路徑：controller update → tutorial input → row → queue

1. `0x5452C0` 控制器更新讀 `[F9423C]`，減 `controller+0x64` 保存差值至 local；同一主迴圈三槽依 `controller+10+12*i` 找主要 actor，并呼叫 `54F200` 遞減已有 timer。
2. `5457A4..5457F9` 的發送閘在真正 append 之前執行：使用 `[FBA7B0]` 比較 20/15/8，選擇 4 個**原件靜態 DWORD**門檻：100、120、180、300；另從 `[FB1318]+BF74` 讀 DWORD 並乘 2，與初選值取較大的 unsigned 值；必須 `controller+0x0C != 0`、`delta > chosen_threshold`、`[FBA7B0] > 0` 才前往 `545824` 組包。這是**應用輸入送出節流**；四個門檻的 clock 單位、FBA7B0 的所有 writer、BF74 的語意均未完整證實。不能稱為 Z combo window，也不能拿來推導每秒傳送次數。
3. `545824/829` 設長度 6、app key `0x000A`，`545887` 將全域 `F93944` 內容複製至 app header +2。此為本地組包；仍依 selector0 connection 才能真正排入 pending/WSASend。
4. **Row A**：`545895` 以 index 0,1,2 遍歷最多三個主要 12-byte slot；有 actor pointer 且 slot enabled 時，以 controller `vtable+0x48(index,&local)` 產生候選（`5458CE`）。已核實 tutorial `CTutorialController` vtable VA `C0FB1C` 的 `+48=C0FB64→548D10`，這是一段直接 `jmp 546100`，`5464B3 ret 8`；對 **該 concrete** 的堆疊 ABI 已證，其他控制器不能直接泛化。
5. `546100` 對 actor/model 先做 gate：`5461F0` 讀 actor+88 WORD、`5461FD cmp 9`，`ja` 早退；hero record 以 `F94304 + model*0x210` 尋址，缺初始化則早退。`54623F` 調 `4C9ED0` 及 actor+158 的特定狀態判定；`546263` 呼叫 `546780` 得到輸入 word／byte 條件；`5462DD` 有條件呼叫 `54F270` 進行技能 availability 判斷。這些 gate **不保證任意 Z 按下都輸出一筆 row**。
6. `546780` 是**三組輸入消費者的合成器**：讀 controller+5C WORD 保存 mask，分別呼叫 `547240`、`546850`、`546B50`、`546D50`；`5467F4` 才將合成 WORD 寫 caller 提供的指標。最後返回位元按各支結果 OR，候選 byte 依先成功的支路回寫（`5467FB/6815/682F`）。不能將多支 OR 理解成「連點次數」或把各 byte 一律叫 Z 方向。
7. `546850` **原生可見** `FB9005..FB9008` 各自比較值 1/2；其 source/更新頻率、值 1/2 是否就是 keydown/keyup，不能僅從比較推定。Z→KeyMapping→具體索引（既有原稿有 Key44→ID13 部分證據）尚未在此完整追到 `546780`，所以**本次不報告 Z 的所有 keyup/hold/fast tap 已被確認**。
8. Row A 的 `R+4` 在 `54590D` 覆寫 row low WORD；row high WORD 是 callback/local def-use；row byte 的 `5458CA` 位址在兩次 push 後，與 `5458FB [esp+38]` 不可無條件視為相同來源。只有 `owner+58 != 0` 的 `5458E9` 有獨立 B0 snapshot writer；`owner+58 == 0` 仍須回溯 ABI/alias。
9. **Row B**：`controller+30..34` 的 8-byte input list 逐筆查 `FAB13C` tree，`controller vtable+44` 作獨立 gate。成功時且 `owner+58==0` 可保留 `R+E4` 到第五 BYTE，另一支經 `545AC8` 改成先擷取的 `R+B0`。現有 `000A` **不作 actor ID 去重**：Row A 和 Row B 是先後兩組 append，均可將 `WORD(R+4)` 寫入第一 WORD。若重複 slot／不同 list key 最後指向相同 R，物理上允許相同第一 WORD 多次出現；**但真實首戰伊莉西亞是否實際同 actor 跨 Row A/B 重複，須看 live owner/list 架構與封包**，不能將此可達結構當成實際重複的證據。
10. `545B38` 只有 `len>6` 才走 `545B71`，向 network selector0 交給 `8069A0→8060D0→806060→queue→WSASend`（條件式）。未 append 任何 row 則本 builder 不送；若成功 append 最多依 `len+5<=0x1000` 逐 row 保護。
11. **更新時鐘及 reset**：`545B45` 寫控制器 `+0x64=[F9423C]`、`545B55` 清 `controller+0x74`，`545B4F` 對 `FBA7B0` 執行 DEC；`545B79` 清 `controller+0x5C` 16-bit aggregate；`545B83` 條件式清 `controller+0x58`。該段必須以 **輸出 buffer len>6** 的 CFG 為條件描述：只走 `545B73` 時不會寫 +64；但仍可能清 +5C/+58。**沒有證據可以把上述每一個 reset 稱作「普通攻擊段數 reset」**。

## 2. 確切原始機器碼（正規指令邊界）

```asm
54532E A1 3C 42 F9 00          mov eax,[F9423C]
545333 89 44 24 28             mov [esp+28],eax
545337 2B 46 64                sub eax,[esi+64]        ; elapsed-like DWORD
5457A4 8B 15 B0 A7 FB 00       mov edx,[FBA7B0]
5457AA 83 FA 14                cmp edx,20
5457AF A1 2C A6 D6 00          mov eax,[D6A62C]       ; 100, when >20
5457B6 83 FA 0F                cmp edx,15
5457BB A1 30 A6 D6 00          mov eax,[D6A630]       ; 120, when 16..20
5457C2 A1 34 A6 D6 00          mov eax,[D6A634]       ; 180, when 9..15
5457C7 83 FA 08                cmp edx,8
5457CC A1 38 A6 D6 00          mov eax,[D6A638]       ; 300, when <=8
5457D1 8B 0D 18 13 FB 00       mov ecx,[FB1318]
5457D7 8B 89 74 BF 00 00       mov ecx,[ecx+BF74]
5457DD 03 C9                   add ecx,ecx
5457DF 3B C8                   cmp ecx,eax
5457E1 0F 47 C1                cmova eax,ecx
5457E4 39 73 0C                cmp [ebx+0C],esi
5457ED 39 44 24 1C             cmp [esp+1C],eax
5457F1 0F 86 86 03 00 00       jbe 545B7D              ; delta <= threshold
5457F7 3B D6                   cmp edx,esi
5457F9 0F 8E 7E 03 00 00       jle 545B7D              ; nonpositive counter
545824 B8 06 00 00 00          mov eax,6
545829 BA 0A 00 00 00          mov edx,0Ah
545895 8B 44 24 14             mov eax,[esp+14]
5458C1 8B 52 48                mov edx,[edx+48]        ; controller virtual48
5458CE FF D2                   call edx
5459B7 8B 44 24 18             mov eax,[esp+18]       ; second loop position
5459BF 8B 72 30                mov esi,[edx+30]        ; extra list
545A60 8B 52 44                mov edx,[edx+44]        ; controller virtual44
545A67 8A 8E E4 00 00 00       mov cl,[esi+E4]
545A70 88 4C 24 30             mov [esp+30],cl
545AA1 74 33                   je 545AD6              ; preserve E4 branch
545AC8 88 5C 24 30             mov [esp+30],bl        ; B0 branch only
545B38 83 3D D0 48 FE 00 06    cmp dword [FE48D0],6
545B45 8B 44 24 28             mov eax,[esp+28]       ; clock snapshot
545B4F FF 0D B0 A7 FB 00       dec dword [FBA7B0]
545B55 C7 46 74 00 00 00 00    mov [esi+74],0
545B5C 89 46 64                mov [esi+64],eax
545B6F 6A 00                   push 0                 ; selector0
545B71 FF D2                   call edx
545B79 66 89 46 5C             mov word [esi+5C],ax ; clear aggregate
545B83 C7 43 58 00 00 00 00    mov dword [ebx+58],0
548D10 55 8B EC 5D E9...       jmp 546100
5461F0 0F B7 87 88 00 00 00    movzx eax,word [edi+88]
5461FD 83 F8 09                cmp eax,9
546263 E8 18 05 00 00          call 546780
5462DD E8 8E 8F 00 00          call 54F270
5467F1 8B 55 10                mov edx,[ebp+10]       ; pointer load
5467F4 66 89 1A                mov word [edx],bx      ; actual store
```

## 3. 玩家正流程／實作交界矩陣

| 情境 | Client local gate | C→S app row | S→C / 動作 | counter/reset/clock | 結論 |
|---|---|---|---|---|---|
| 首戰伊莉西亞正常按 Z | Key44→ID13 僅引述既有局部證據，本輪沒有從 keydown 完全閉合至該 row | 先過 controller+48 / 546100，再可能 append 5-byte Row A | 單按的回包因果仍未知 | 輸出週期受動態門檻約束 | **部分確認** |
| Z 連點／短暫放開後再按 | 未驗全部 keyup/hold latch 和不同 animation phase 的 owner gate | 可能合併／抑制於一個輸出週期，不能聲稱每次發 packet | 101→102→103 未由原件證明 | 無確定官方 combo deadline、counter 位置或自然收尾 reset | **UNKNOWN** |
| 同 actor 多 row | 三槽 + 8-byte list 各有 append，無本函式內的 dedup | row order 先 3 主槽、後額外 list；重複 firstWORD 結構上可行 | Server 對重複 row 的原版裁決未證 | 用 FE48D0 bytes count，非按鍵次數 | **有界結構可證／實際重複未知** |
| 沒有 row／時鐘門檻未達 | `delta<=threshold` 或 FBA7B0<=0 或 owner 缺失 | 本 builder 不送 000A | 不推論 Server 接受或拒絕 | +64 僅在 len>6 分支更新 | **有界 native** |
| 某筆 append 後送出 | len>6，selector0/connection downstream gates | `6+5N`；lowWORD=R+4，高WORD與byte 部分不透明 | 0D/0E 不是已證 ACK pair | +64 更新；+74/+5C/+58 有清理 | **有界 native** |

## 4. 已排除的不正確歸因；精確下一步

- **不可將 `100/120/180/300` 宣告為四段連擊窗口**：原始指令明確在 `000A` 寫頭之前控制發包時機；沒有技能/連段 index 或 animation event 的來源。其單位亦未從 Clock writer 證明。
- `FBA7B0` 用於發送 gate、且每次 len>6 分支 DEC，**不是已證 combo counter**；此全域其他 producer/consumer 待追。controller+5C 是合成 input word 清理，不能直接稱 combo reset。
- `546B50` 可寫 controller+7C/+80，且 `546100` 某些 actor/狀態分支清它們；這條 helper 同時牽涉 `FBA80C` 及空間/輸入設備條件。**現無證據證明 +7C/+80 是 Z 接段編號**，暫不給 gameplay 命名。
- **Client 待逆向**：KeyMapping Z 的具體 source ID / phase writer（1/2 實際意思）→`546780` 的相應分支 → `546100` 的獨立 owner/skill gate → 具體伊莉西亞 actor+158 motion state → `000A` row；其次追 phase/counter 的 writer/readers 和自然 motion 收尾（T09），求得按住、keyup、稍晚再按與下一段的真正因果。
- **Server 待開發/設計**：收到多 row 的順序與權威選擇，攻擊合法性/連段接續屬 Server 策略待 S00 依有界 Client 契約設計；現行 0.4 秒為候選，不能說原版。原版 Server 內部規則未知本身不阻斷前述 Client 靜態補查。
- **待遊玩驗證**：收集使用者正常 Z 按下/放開時間、實際 raw 000A bytes/多 row 與接收 000D 動作序列，可將 local gate 與 S2C 效果對應；本次未啟動 Client、不做併發/異常/壓測。

## 5. 原件可重現視窗（半開，SHA256）

以下由本次相符原始 BIN 計算；byte hash 只是同一性，並非 T01 全文語意審核。

| 主題 | VA [start,end) | SHA256 |
|---|---|---|
| tick/cooldown early | 54532E,545379 | `f616410e1bde18c5f78918a93dda366ddc9724c4e33c99ee2868676cba5081e4` |
| Clock gate | 5457A4,545822 | `3eb380ca4ece41dae91fb3ecd9392a96fb7199b06d36a8b6aa175dc8754f5b34` |
| Row A/B | 545824,545B73 | `5880a188c2356386956945ff2d9fffa6618bc2a9211331a968acc2df1d236bf5` |
| Hero conditional input | 546100,5464B5 | `6361928e9d6d9b17d3c936a3f5d87e5af7384fdb2a8f4a808687ac210beabda5` |
| Three-provider input merge | 546780,546845 | `fc4c61c4e91370b5393a57f34ab778ca9ecb43d8e5376102e9e0b5612960d73a` |
| Sender reset | 545B38,545B9F | `7359c8db0ff0131ed9f939d6f966521fe87a3a131a643913740e3d3270abbcf7` |

另原件 `.data` `D6A62C..D6A63B`（raw `967E2C`）依 little-endian UInt32 為 `100,120,180,300`，不以人工表格猜值。**本段研究目標尚未全部達成，後續依上述精確入口續追**。
