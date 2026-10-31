# E84 — RR-0007：KR S2C 外層命令表的雙分派分流、LOGI 場景 gate 與新 Server 相容交接

> 2026-11-01（Asia/Taipei）｜T02 / chatgpt-web roy｜KR 原始 BIN-first。研究範圍為 RR-0007 的 **Client 收包 → 命令分派 → T03 登入／角色名單／選角相關處理器的前置條件**。本稿是已提交 E60 的追加驗證與欠缺部分，**不覆蓋 E60、E59、E79 原件，亦不宣稱 T01 FULL-PASS／S00 ACCEPTED／Client 已成功連線**。不建立新分支；使用既有 RR-0007 認領分支，合併後整合到 main。

## 1. 原件與權威、任務終點

- `research/requests/index.json` 於開工之 `main=ec16f88347deeef894fa9fdebd3791fefe61da2c`：RR-0007，owner T02，`IN_REVIEW`，原本已完成 `SUBMITTED` E60，提交 Git blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`，T01 已完成限定 R2、S00 尚未判 `ACCEPTED`。此輪不是重新認領或擅改台帳；不修改 `research/dispatch/inbox` 生成檔。
- 原始 KR `Tartaros.bin`，大小 **12,472,320** bytes，SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**。PE32 x86 ImageBase `0x400000`；`.text` VA `0x401000`、raw `0x400`、raw size `0x7D0200`；該 section 內的轉址為 `file offset = VA − 0x400C00`。`.rdata` 另依 PE section table，不可套用該轉址。
- 直接由原始 BIN 定向反組譯及 PE `.rdata` vtable 解參照。驗證器 `E84-RR0007-verify.py` **50 項明確有界斷言 PASS**，並由原始 `.text` 範圍解析函式內的 `mov edx,imm32 / mov [eax+disp32],edx` 表槽覆寫樣式。**僅此已知指令樣式、已辨識函式範圍，非全程動態 alias 或完整 x86 CFG 枚舉**。
- E60 已定位 `0x806CF0 → 0x807B40 → 0x8040A0/FC10D0 → 0x804740 → 0x4930E0` 的有界收包與命令路徑。E59（RR-0006）已定位 `0x2633` 壓縮解碼、`0x22D7` 標記、checksum fail 與 node/pool。此輪**不重做已通過的底層發現**，而是從 `0x493170` 的指令級表格建立繼續追到多處不同命令 owner。

### 本次實際補上的斷點

E60 著重 `0x494360 → FD2CF8` 的通用命令入口，卻未呈現外層命令表存在**一批覆寫成另一種路由**；E79（RR-0010）後來找到 `0x002B → 0x4943B0 → F8D9E0 → 0x4E2730`。本輪回到原始表格建構，核實通用命令與分歧命令的精確 index、槽位初始化、不同 singleton/records、場景前提及邊界。這是「是否經 LOGI scene」的關鍵分流，不只是再發現一個 handler。

## 2. Client callback 外層條件不變：不要顛倒 BE8C 的位置

原始指令：

```asm
4930E4 mov eax,[ebp+0Ch]     ; decoded app pointer
4930ED movzx edi,word [eax]  ; 先讀 command WORD
4930F6 test ebx,ebx         ; ebx=[ebp+10h] length
4930F8 jne 493105          ; length!=0
493105 mov eax,[ebp+14h]     ; lane
493108 sub eax,2
49310B jne 493154          ; only lane2 forwards
493120 mov edx,[esi+0B8h]  ; pointer/vtable
493129 mov edx,[edx+4]
49312C push edi             ; app command
49312D lea ecx,[esi+0B8h]
493133 push ebx             ; length
493134 push eax             ; app ptr
493135 call edx
49313F cmp edi,100h         ; handler return
493147 cmp dword [esi+0BE8Ch],0
493150 mov byte [ebp-1],1 ; only if return100h AND BE8C!=0
```

對長度的觀察很重要：**函式在測試長度非零之前先解參考 application WORD**；不提供該函式本體具有 `n>=2` 守衛的證據。新 Server 應自行保護至少完整 opcode、frame 與場景相關長度，不能以原版 Client 顯示「有處理器」就推稱 malformed input 必然安全。`BE8C!=0` 是在 handler **返回後**決定本 callback 最終布林結果；它不是所有處理器的前置開關。其他 framing/pool 前提引用 E59，不把錯 checksum 當作有上層業務 callback。

## 3. `0x493170` 外層 16-byte 表格：預設入口和 `0x002B` 覆寫

`0x48C027 lea eax,[ebx−8] → 0x48C02A call 0x493170` 是此表格建構的實際 callsite。函式 `0x493170` 在正常有效 object pointer 路徑中建立：

```asm
493173 mov edi,494360h           ; 通用轉送器
493178 xor ebx,ebx
49317A lea edx,[eax+210h]
493180 mov esi,0BD5h            ; 3029 槽
493185 mov ecx,0BF2375h         ; metadata
493190 mov [edx−8],edi          ; slot handler at eax+208+16*i
493193 mov [edx−4],ebx
493196 mov [edx],ecx
493198 add edx,10h              ; stride 16
49319B dec esi
49319C jne 493190
493370...                        ; 後續按部分 index 覆寫 handler
49337A mov [eax+4B8h],edx       ; (4B8−208)/10h = 0x2B
```

從原始函式範圍內的已知 `mov edx,imm32` 緊接 `mov [eax+offset],edx` 形式抽取，辨識 **195 個唯一的 index 覆寫紀錄**（部分可能由同類型指令的不同編碼完成，故不能宣稱全函式總 override 數恰為195）。以下是有證據的必要子集，不是由命令名稱推測：

| S2C application WORD index | 外層 16-byte 表格此樣式下的 handler | 第二個 owner／scene gate | 有界結果 |
|---|---|---|---|
| `0x0002` | 預設 `0x494360` | `FD2CF8` 的 command2 直接 override `0x4B7F00` | 完整角色清單；不必通過 generic 的 current-scene-null gate |
| `0x0013` | 預設 `0x494360` | `FD2CF8` generic `0x4B7EC0` → 有效 LOGIN scene 第二層 `0x4C37A0` | 登入結果；需 LOGIN scene／handler |
| `0x007A` | 預設 `0x494360` | 同上，LOGIN 次表 `0x4C3C10` | 頻道清單；和 0x13 是不同 payload layout |
| `0x0042`／`0x0043` | 預設 `0x494360` | generic scene path → base scene `0x4B2190`／`0x4B1A90`（如該場景保留原基類槽） | 可接收 handler 不等於選角批准 ACK |
| `0x0069` | 預設 `0x494360` | 後續有效 scene 的 handler／base | subtype7 切場景見 T03 E67/E80；不能把它當 0x42 reply |
| **`0x002B`** | **明確覆寫 `0x4943B0`** | **不同 `F8D9E0` singleton → `0x4E2730`** | 增量角色 record 更新；不依 LOGIN 次級 `0x13/0x7A` 表 |

**指令樣式的陰性界線**：沒有看到上列某命令的「已辨識格式 override」，只代表本函式該樣式的表槽保持初始預設；本輪另定向檢視關鍵命令的實際存取，不能用全段 raw `BA 89 90` matching 宣稱已排除自修改代碼或任何 runtime table patch。`493170` 大表對惡意負值 command 未在此函式提供安全 bounds proof；下游 signed WORD 索引（如下）更不能視作安全的未受信封包 validator。

## 4. 兩個 singleton 的**方向完全不同**；vtable+4 的結果也不同

### 4.1 通用 `0x494360` → `FD2CF8` → `0x4FDA30`

```asm
494376 mov dword [FD2CF8],C06EB4h
49438A call 4B7DC0         ; lazy init shared command table
49439C mov ecx,FD2CF8h
4943A1 mov eax,[FD2CF8]
4943A6 mov edx,[eax+4]      ; C06EB4+4 = 4FDA30, from PE .rdata
4943AA jmp edx

4B7DC0 mov eax,FD2D00h
4B7DC5 mov edx,4B7EC0h      ; default to current-scene forwarding
4B7DD0 mov [eax−4],edx
4B7DD5 add eax,8           ; 8-byte table stride
4B7DDF mov dword [FD2D0C],4B7F00h  ; index 2 override

4FDA3B movsx edi,cx        ; sign extends the application WORD
4FDA3E mov eax,[esi+edi*8+4]
4FDA45 test eax,eax
4FDA49 mov eax,[esi]        ; handler missing → vtable+0C fallback
4FDA4E mov eax,[eax+0Ch]
```

`0x4B7EC0` 在 `FD2CF8 +0x5EAC` **current-scene 指標**為 NULL 時記錄及 return0，非 NULL 才跳 current scene `vptr+4`。第一層 `app2` 覆寫直接命中 `0x4B7F00`，不等於任何 scene 都能安全完成角色清單，因為它自己的資料、資源和下游仍有限制。

### 4.2 特殊 `0x4943B0` → `F8D9E0` → `0x4E2730`

```asm
494416 mov eax,[F8D9E0]
49441D mov edx,[eax+4]
494420 mov ecx,F8D9E0h
494425 call edx            ; 此物件的 vtable+4，非 FD2CF8 的函式

4E1DA0 ...
4E1E3F mov dword [eax+15Ch],4E2730h
4E273D cmp eax,2          ; length < 2 → 0 full record
4E2746 lea ecx,[eax−2]
4E2749 mov eax,3521CFB3h ; divide-by-53 optimized
4E2759 test ecx,ecx
4E275F mov edi,[ebp+8]    ; app payload pointer
4E2762 add edi,2          ; prefix 2B
4E2767 movzx eax,byte [edi+2Eh]
4E276B cmp eax,9          ; only <=9 direct guard
4E2770 imul eax,eax,210h
4E2782 call 4D4150       ; record writer
4E278A add edi,35h       ; 53-byte stride
4E2794 call 4E5FB0       ; downstream shared record effects
```

對 F8D9E0 的相應表槽計算：`0x15C = 4 + 0x2B * 8`。`4E2730` 與全角色列表 `4B7F00` 走**不同入口**，但在資料結構上共用角色記錄陣列，參見 E79 的 native record owner 地址別名證據（`F8D9E0+0x6924 == F94304`）。在當前函式可證的是增量更新支路；**原版 Server 是否因 C2S 0x33 招募後回 S2C 0x2B** 並無同一 session pairing 證據，不能以存在 handler 當作官方因果。若新 Server 採此更新路徑，需自訂 ADR 及實際 Client 相容測試。

## 5. LOGIN 二層場景 gate：精確 slot、失敗情境、允許的推論

```asm
4B7EC3 cmp dword [ecx+5EACh],0
4B7ECA je 4B7EDA          ; no current scene → no forward
4B7ECC mov ecx,[ecx+5EACh]
4B7ED2 mov eax,[ecx]
4B7ED4 mov eax,[eax+4]
4B7ED8 jmp eax

; LOGIN scene vtable C072FC+4 = 4C4670
4C4679 movsx edi,ax
4C467E mov ebx,[esi+edi*8+5EACh]    ; this is now SCENE object's own table
4C4685 test ebx,ebx
4C4694 call 4FDA30                     ; absent override → base dispatch
4C46A0 mov edx,[esi+edi*8+5EB0h]    ; registered handler metadata
4C46C5 call ebx                        ; nonzero scene override

4C323B mov [scene+5F44h],4C37A0h   ; (5F44−5EAC)/8=13h
4C325B mov [scene+627Ch],4C3C10h   ; (627C−5EAC)/8=7Ah
```

因此 `S2C 0x0013`（status `payload+0x16`；0 且非空 UTF-16 name 是有界成功處理、5/其它是不同失敗路徑）以及 `0x007A`（count `payload+2`, cursor `payload+6`）都**必須**通過有效 LOGIN scene 的第二級表和其內部資料前提，不能因 0x4930E0 已進入就宣稱 UI 會更新。對 `0x42` / `0x43`，LOGIN scene 沒有自身覆寫時可回基類表，但該表的 UI/list side effects **不是** C2S 同命令號 ACK，選角後 scene subtype/轉場交給 T03 RR-0002/0008。

有界負面情境矩陣：

| 輸入／狀態 | 原生能證 | 新 Server 應測試但尚非實際遊玩證據 |
|---|---|---|
| frame header 未收齊、黏包 | E59：parser 累積/compact，足完整 frame 才分配 node | 分段、多 frame、重傳/斷線，有獨立 TCP 流緩衝 |
| checksum fail / 0x2633 inflate fail | E59：不投遞正長度 business node、pool 回收；不等於必斷線 | 失敗只 log 並阻止進行業務，勿故意測未可信 malformed Client crash |
| app 0x13，非 LOGIN scene | generic scene pointer / scene vtable gate，LOGIN 次表不可直接套用 | 只在該場景和資料容量就緒時送登入回覆 |
| app 0x02，無有效 current scene | 外層 generic 和 FD2CF8 直接 handler 的路由不受 `4B7EC0` null scene gate 約束 | 仍需單獨測試角色資料指標、資源和 UI；不推自動 ready |
| app 0x2B，角色紀錄長度不足2 | 4E2730 走 zero-record 路徑仍呼叫 4E5FB0 | 新 Server fail-closed、不要送無效短包；Client 原生不保證 safe reject |
| app 0x2B，ID 0 或 >9 | `<=9` 直接判斷；ID0 **未被此 guard 排除** | Server 建議限定 ID1..9；非「原版官方唯一合法 ID」 |
| app 0x42，收到同 opcode 的 S2C | base 0x4B2190 state/list 更新而非已證選角場景轉換 | 不可把回覆 0x42 假設為選角 ACK；需要 T03 合成測試 |

## 6. 上下游與驗收矩陣：哪些是 RR7 已補齊、哪些仍是其他 RR

| RR7 驗收對象 | 已有 E60／E59 + 本輪 E84 的實證 | 狀態 |
|---|---|---|
| decoded frame / 0x4930E0 lane2 / handler dispatch | E60 指令及本輪 bytes/BE8C 後置 gate 再驗 | **限定 Client static 完成** |
| first-layer table 實體、場景 fallback、LOGIN+0x13/7A | FD2CF8→4FDA30→4B7EC0→4C4670；次表 index +8，app2 直接覆寫 | **限定 Client static 完成** |
| 不同命令 owner，避免誤將 global updates 視為 scene-local | **本輪新增 `493170` 外層表 3029 slots、0x2B override、4943B0→F8D9E0、4E2730** | **限定 Client static 完成** |
| 0x2633 / 0x22D7 / 0x727190 / checksum / pool | E59（RR6）具第一手限定原稿；本輪交叉引用並定位對接點 | **跨 RR evidence 已存在，非 E84 重做原件整段** |
| 真正選角批准 opcode／選角後 World scene writer | T03 RR2/RR8 另負責；不存在可據以稱 0x42/0x43 ACK 的新正向證據 | **不得在 T02 scope 硬填** |
| 原版 Server 第一個登入回覆、各 Conn wire 時序／政策 | 不屬 Client 命令路由可直接觀測的 peer behavior | **Server 待開發與待遊玩驗證，不是停止 T02 靜態研究的藉口** |

### 四種交接分類

- **Client 待逆向**：更進一步確認 `Client+B8` 處理物件在所有動態 scene/owner 的唯一型別、外層 command table patch alias、故障時是否有其它通知；這些不得由當前 E8/inline table pattern 的陰性結果宣稱全程不存在。選角 UI/scene writer 依 T03 RR2/8，及 C2S 33 ↔ S2C 2B 實際 pairing 依 T03 RR10 留待合成驗證。
- **Server 待開發**：以分版本契約/有效場景輸出 0x13/0x7A/app2/app2B；先依測試控制收發 frame/解碼（RR1/4/6），校驗 status、roster count、role record、text length，安全拒絕未知和負 index，不能憑表槽就許可未授權角色。
- **跨功能待整合**：T02 E59/E60、T03 RR3/E83、RR2/E80、T04 角色 record、T05 Scene、S00 `SPEC-NET-0001/0003`、`SPEC-AUTH-0001`、`SPEC-CHAR-0001`、`GAP-NET-0003`。提出正式測試候選供 S00 去重：`DISPATCH-LANE2-NONZERO`、`DISPATCH-LOGIN-SCENE-GATE`、`DISPATCH-ROSTER-DIRECT`、`DISPATCH-0x2B-ALTERNATE`、`DISPATCH-BAD-CHECKSUM-NO-BUSINESS`、`DISPATCH-0x42-NOT-ACK`。
- **待遊玩驗證**：同版原版 Client + 自製隔離 Server，明確記錄 socket、lane、outer marker、application opcode、scene lifecycle、UI 結果；沒有本輪實機執行或原版 Server 原始 trace，不把單一合成回覆當官服順序。

**本輪交付聲明**：RR-0007 已經有 E60 正式 `SUBMITTED→IN_REVIEW`；本輪對 E60 未列明的路由差異補上完整 native/report/verifier，提供 T01/S00 做整體研究驗收。此研究者不會自改為 `ACCEPTED`、不會把 SPEC 變 `STABLE`，不會新增 branch 或覆寫其它 Task 來源。

## 7. 重現

```bash
python -B kr-extra-roy/20261101-chatgpt-web-roy-E84-RR0007-verify.py Tartaros.bin
# 50 bounded original-BIN assertions; PASS for SHA256 9741d197...
# no Client run, no original Server trace, no FULL-PASS claim
```

相鄰權威來源：E60 (`2ca02f3870d79d3217abf39b8651c43226eb77d6`)、E59（RR6：`c7c1474b6b3cf928b8031e17fad7761c488d9b18`）、E79（RR10）、T01 對 E60 的 R2 限定複核。原件地址／位元組以本篇附帶驗證器及開工時 SHA 判斷；歷史原稿不在本輪修改。