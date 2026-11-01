# T10/T11 交界 P0-B — KR 000E 接收實際 virtual dispatch 與 000D 顯式動作（2026-11-01）

> **重要反證與限定範圍：** 原始 Client 的 application key `000E` 入口，在已查明的 tutorial/single/formation 控制器裡，**沒有從該封包 payload 解讀 HP、傷害或 motion 9 的本體**；其具體 virtual+28 或為零回傳，或為清理既有物件。不能把「Server v7 發 0E 傷害／HP」反推成原版 `000E` 必然會自動播放受傷動作。此次只保留 S00 工作卡所述 v7 人測事實，不操作遊戲，不改原件／Server，不更動 T12 傷害公式主責。

## 0. 身分、資料與工具

- S00 工作卡 Git commit `7efc6f5219e05d7042f25f86627cd1b096ec1540`；`FOLLOWUP-02-V7-COMBO-AND-HURT.md` blob `47bff869dca72dcad4bc4a70c8df87295af0d216`，以及其 [v7 人測記錄](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7efc6f5219e05d7042f25f86627cd1b096ec1540/governance/s00-iterations/S00-20261101-V7-PLAYER-RESULT-AND-COMBAT-FIX.md) blob `97150571da271d193d54ea01bc0713106b45dd9e`。
- KR 原始 `Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪實算。PE `.text` raw=VA−`400C00`；`.rdata` raw=VA−`401A00`。用 LLVM llvm-objdump Intel i386、Python struct/hashlib 唯讀驗證。**未取得已保存 Ghidra 工作專案，因此不冒稱 Ghidra 重分析**。
- 已有源界線：`unclassified/evidence/7bafd3143273877097a98dd0c42dc0f1c7e30719d0e86821318db4612473f89f.txt`，blob `a0a294ab559bebd5004ed5b781fdaf0f7cc865fd`，其 0D motion 內容僅作定位，本輪從 BIN 重新查指令；沒有官方 Server source 或 capture。

## 1. Opcode 真實來源：用 dispatcher 所寫的 slot，而非猜同名

`4ADD50` 初始化 S2C application-handler 表，default entries 為 `4B7D40`，對特定 key 覆寫。表佈局中槽 `4 + 8*opcode` 為 function pointer，另一 DWORD 為配套值：

```asm
4ADDC6 C7 40 64 30 01 4B 00  mov dword [eax+64h],4B0130h  ; (64h-4)/8 = 12 = 000C
4ADDD0 C7 40 6C C0 01 4B 00  mov dword [eax+6Ch],4B01C0h  ; (6Ch-4)/8 = 13 = 000D
4ADDEA C7 40 74 40 6C 43 00  mov dword [eax+74h],436C40h  ; (74h-4)/8 = 14 = 000E
436C40 8B 01                mov eax,[ecx]                     ; receiver/controller vptr
436C42 FF 60 28             jmp dword [eax+28h]               ; tail dispatch; **不讀 packet**
8DC2F0 33 C0                xor eax,eax
8DC2F2 C3                   ret
```

**有界結論**：在此表、此 receive layer，`000E` 不是直接的 `4B01C0` 9-byte motion-row parser。它把控制權委派給當時 `ECX` controller 的 `virtual +0x28`，本 wrapper 沒讀 payload/length/HP。仍要透過上游 T02 framing 與實際 controller 生命週期，才能確定 v7 收到的 `0E` 是否是這個 application key namespace、以及當時控制器型別，不能拿編號相同代替 runtime 封包配對。

## 2. 首戰可能用到的 7 張已辨識 controller vtable：slot +28 矩陣

從 KR `.rdata` 精確搜尋 `vtable+44 = 0x546EF0` 的 DWORD 指標，往前推 0x44 作 base，逐一讀 +28、+48；其中 `CTutorialController`、`CSingleController` 與 `CFormationController` 的既有來源名稱由前段 RTTI/原稿導航，**本次以實際 vtable DWORD 與原生函式碼驗證實作，RTTI 名稱不據此提升全文驗收**。

| vtable base (VA) | +28 (000E) | +48（供原 input 對照） | +28 是否讀 000E payload / 播受傷 motion |
|---|---|---|---|
| `C0FB1C`（既有 Tutorial） | `8DC2F0` | `548D10→546100` | **無**：`xor eax,eax; ret` |
| `C0FAC4`（既有 Single） | `5486E0` | `548A20` | **無**：清理 manager 成員，未取任何 app row |
| `C0FA14`（既有 Formation） | `547C80` | `5480A0` | **無**：清理三個 wrapper 成員，未取 packet |
| `C0F944` | `8DC2F0` | `546100` | 同上述 zero stub |
| `C0F99C` | `8DC2F0` | `547230` | 同上述 zero stub |
| `C0FA6C` | `8DC2F0` | `546100` | 同上述 zero stub |
| `BFB5A4` | `5486E0` | `548A20` | 同 Single `5486E0` |

`5486E0` 從 `controller+A0` 刪除／釋放物件（條件式虛析構 +0），`controller+B4` 關聯 tree 使用 `7BEAE0`，再對 `controller+B8` 物件成員做條件式虛析構並清零，最後 `xor eax,eax;ret`；`547C80` 對 `controller+B8` 及 `BC/C0/C4` 類似清理。它們都**沒有**依傳入封包 `HP`、`damage`、`actor ID` 或 `motion` 設定受傷動畫的指令。這些函式更像 controller local cleanup，而非 hit-result consumer；名稱仍須依更高階 caller/end-to-end 複驗。這是直接 BIN 反證，不是「沒搜尋到傷害 opcode 就假設原版沒有受擊動作」。

**P0-B 的對應玩家問題：** v7 Server 送出其自訂的 `000E HP/damage` 不等於原版 Client 在上述 `000E` handler 會播放 Isla Motion9。即使單獨又有別的 HP parser，上述 `000E` 不能被假定為自動 reaction 起點。**本次尚無完整 runtime controller trace，所以不斷言 v7 首戰一定走 Tutorial stub，也不排除另外的狀態同步／擊退／死亡事件入口。**

## 3. 000D：獨立顯式動作資料解析及 Actor consumer

`0x4ADDD0` → `0x4B01C0`，這是另一個 S2C key。原件 `4B01EC..4B0208` 依 payload length 計算 `N=floor((len-2)/9)`（少於一整列不進迴圈），`4B020E` 設 `EDI=payload+5`，每回合 `4B039E` EDI+=9。

對於每個 9-byte application row，以 row start `payload+2+9*i` 表示：

| row 內 offset | size | 原生 consumer | 能確認／限制 |
|---|---:|---|---|
| +0 | 2 | `4B0250 movzx edx,WORD[EDI-3]`，`4B0266` actor tree `FAB138/13C` lookup | actor selector，不等於 000E 傷害目標 |
| +2 | 1 | `4B0290 movzx eax,BYTE[EDI-1]` → actor vtable+58 | status-like byte；語意與 B0 須按具體 actor vtable 追 |
| +3 | 2 | `4B0313 movzx ecx,WORD[EDI]` → `4C8A90` | **顯式 motion-like ID**，需符號／資源交叉證明具體 9 |
| +5 | 4 | `4B030F fld DWORD[EDI+2]` → `4C8A90` | 動作 float parameter；**不是已證的 Server hit time** |

```asm
4B01F8 8D 48 FE                lea ecx,[eax-2]
4B01FB B8 39 8E E3 38          mov eax,38E38E39h
4B0200 F7 E1                   mul ecx                  ; /9 quotient via mul+shift
4B0202 D1 EA                   shr edx,1
4B020E 8B 7D 08                mov edi,[ebp+8]
4B0211 83 C7 05                add edi,5
4B0250 0F B7 57 FD             movzx edx,word [edi-3]
4B0266 E8 95 EC 37 00          call 82EF00              ; actor lookup
4B0290 0F B6 47 FF             movzx eax,byte [edi-1]
4B0296 8B 52 58                mov edx,[edx+58]
4B029C FF D2                   call edx                ; actor::virtual+58(status)
4B0313 0F B7 0F                movzx ecx,word [edi]
4B031A E8 71 87 01 00          call 4C8A90             ; actor consumer
4B039E 83 C7 09                add edi,9
4C8B6B D9 45 0C                fld dword [ebp+0C]
4C8B70 8B 50 68                mov edx,[eax+68]
4C8B74 0F BF 4D 08             movsx ecx,word [ebp+8]
4C8B7E FF D2                   call edx                ; actor virtual+68(motion,float)
```

**動作的真正受理條件：** `4B0275` 若 tree 找不到有效 actor 則先記錄/跳過此 row；有效 actor 才下傳 status byte 和 motion/float。`4C8A90` 先對 actor+d8/dc 的非零預存位移做特殊處理，再檢查 actor+3A8、+370、+15C 的部份控制條件；`4C8B67` 呼叫 actor+F0 結構的虛擬方法 (+8)，最後 `4C8B7E` actor vtable+68。**這是 actor 動作提交入口，不是「任何 motion ID 一定可見」的保證**：還需目標資源/animation gate、其他狀態覆寫及 runtime。

000D row **不含**在這段已驗證 layout 中的 HP 值，也沒有在 `4B01C0..4B03C7` 內證實「000E hit ACK 後一定跟 000D」。兩者是兩個分派的獨立 app message，官方配對、廣播時序、重播和預顯示均未知。

## 4. 伊莉西亞 Motion 9 原件／工作副本的界線

S00 有界資源 metadata（commit `7efc6f5...`）：

- `Character/Cha/Base.stp` → `Cha/Isla.abf`（member SHA256 `ebcb766e13989c480017ff560bcde6738a5d53c5b9bfaceb045b38ab74691e41`），Animation ID `9`、File `Isla_ATTACKED.asd`、Repeat=false、Length=20；
- `Character/Cha/Avatar/04_Isla.stp` → `04_Isla/Asd/Isla_ATTACKED.asd`（member SHA256 `3ee9c851d61bd93d6a733289a3ba93a30debe11a4daabc9010836918fe4a30e6`），FPS 40、StartFrame0、EndFrame20、Delay0，名目 0.5s。

來源 `governance/s00-iterations/evidence/S00-20261101-ISLA-HURT-RESOURCE.json`，blob `ecd4a38410dc967fe22b3e32b0c5cea9c0e52ad4`。**本輪本機並沒有上述 Character/Cha 原始資源包**（只有 `Table.stp`、`Event.stp`）；因此此結論屬「引用 S00 已保存的原始資源 metadata，未在本輪對 Isla 檔實算」，不得冒稱資源獨立重驗。資源動畫存在不等於存在官方硬直時間/霸體/interrupt/invulnerability 或 Client 原生 000E→Motion9 的觸發。

v7 實測「敵人打到玩家而沒有受傷動作」屬 **修改工作副本的人測事實**；Server 擬新增「非致死／待機 Motion9 然後回 idle」是**相容 Server 候選政策**，不能升格原版受擊裁決。若選擇顯式 000D 動作作為 Server 相容實作，需先保證 payload、actor 選取、motion ID 和 Client 接收場景的相容性，並保留 Server 具體 hit→motion 調度為自行設計；不以原版 `000E` 自動觸發作理由。

## 5. S00 可用的有限契約與反證

| 正常情境 | Client 已證 | S00／Server 立即可採用的界線 | 仍 UNKNOWN |
|---|---|---|---|
| 收到 app key 000E | `436C40→controller vtable+28`；Tutorial 為 zero stub、Single/Formation 為 cleanup | **勿假定原版 000E 自動產生傷害動畫**；核實 Server 自訂 HP message 是否用相同 namespace | 000E 在各種 runtime controller 的完整業務意思、與 HP/status 的其他入口 |
| 收到 app key 000D 指定 actor motion | 完整 9-byte rows `u16 actor + u8 status + u16 motion + f32`；actor lookup、vtable+58、`4C8A90→vtable+68` | 可以針對已存在的 actor 發出有界格式的顯式動作消息候選；不能宣稱 000E 的 ACK | Actor vtable+68 的所有 virtual targets、motion9 可見性與前後優先級 |
| 受擊 Motion9 資源 | S00 metadata 限定 Isla_ATTACKED 20 frames/40 FPS | 可作展示候選；**禁止當成官方 hit-stun/hurt-lock 秒數** | 是否在 hit 當下可被播放、是否打斷普攻/技能 |
| 受擊與 Z 連段同時出現 | 已有兩種獨立業務訊息與 local input gates | 保持 hit、motion、skill、combo 狀態分開；由 S00 規劃正流程驗證 | 原版先後順序、打斷/保護窗口、Server 結果判斷 |

**Client 待逆向**：若目標是明確「原版收到哪種損血訊息會自然播放 hurt」，以 `000B/000C` 及另外的 hit/battle-result handlers、actor+68 concrete vtable / animation machine、Client HP/stat writer 的確定 caller/xref 定向補證，必要時納入 T09/T12 主責的已證來源；不能以 Server-only 行為未知停止可查的 Client 靜態路徑。**Server 待開發**：非致死受擊是否自行發 000D/哪個 motion，屬相容決策而非官方規則；傷害公式交 T12。**跨功能待整合**：T02 framing、T08/T09 actor/motion、T12 HP writer。**待遊玩驗證**：原版 Client 的正常 hit 後封包時序、payload、當下 controller type、motion/HP 畫面結果，尚未實際取得。本輪沒有執行 game、無負向/重送/併發/壓測。

## 6. 原始 BIN 可重現半開視窗與 vtable SHA

依 `.text` raw=VA−400C00／`.rdata` raw=VA−401A00 取指定 bytes，SHA256 為：

| 主題 | VA [start,end) | SHA256 |
|---|---|---|
| dispatcher 000C/000D/000E | 4ADDC6,4ADDF1 | `b1f27340fc54fcaf812b017236b67ec8a1b0b181b06f395f52065f1f61291245` |
| 000E vtable forwarding | 436C40,436C45 | `330d07aeacf2d9103182d1a4304782bf56d1816731f174dffc87be14e92d0485` |
| Single +28 | 5486E0,54872E | `5eec57412393a6795a338ff0887394705776df4463a13da381171c4d9efe828f` |
| Formation +28 | 547C80,547CEA | `c46d6e2f95ca6cc7ca86a006fbfc6487c85969fe00d8f3de3cb0c5bfe1bcc51d` |
| Zero-return +28 | 8DC2F0,8DC2F3 | `4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e` |
| 000D parser | 4B01C0,4B03C7 | `392721bb73509fd9f79883d36b6b717d84d6af5cd7c45526cc08bba3fcb50b72` |
| actor motion consumer | 4C8A90,4C8B88 | `668c9780f3596321446c658a216d07567557ad0f191fd0a3adc3bf708169f3af` |
| Tutorial table | C0FB1C,C0FB60 | `e7a7bcabe23fcdb3c1de670a5090bd1429a3afc03d4f073fce4c41785a262eaf` |
| Single table | C0FAC4,C0FB08 | `3a41b3435866e44c4ef7c064b7db67d25913fab2a247cd0efc2051c37a2df9cd` |
| Formation table | C0FA14,C0FA58 | `769e80248cbeb71b97bc1000791421db3c1266e65a881b359af2383cccbf7190` |

本次確認了最影響 v7 受擊 bug 的 **000E≠自動 hurt** 反證，但完整「哪條 Client 原生 damage handler→automatic hurt animation」尚未找到；標記**階段性未完成**，不是 T01 FULL-PASS。不要因此寫成「原版永遠不會受傷」。
