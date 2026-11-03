# W5-02 — KR Client 角色屬性增量 S2C 0x005C → RoleStore → Quest 候選重算（BIN-first）

> 2026-11-02｜chatgpt-web roy｜既有 extra/roy2 分支｜本稿為 W5 尚未完成項目的**新定向 Client 靜態研究進展**，不是 W5 全項完成、T01 FULL-PASS、S00 APPROVED、Server 已實作或原版 Client 可玩驗收。原始 Client/Server/DB 未修改／執行／附加；未做負向／重播／重登／併發／故障／壓測。技能授予、角色招募和裝備取得仍列明阻斷，不用推測填補。

## 0. 目標與來源

- 上一批 W5 來源：kr-extra-roy/20261102-152650-chatgpt-web-roy-W5-Character-Quest-Rewards-Native-Partial.md（Git blob c5f7779b6d92ead61401577dde650f4f12401d9f），W5 機讀表 blob bd0f07c707aeeb12bda0e90423ef387241e48713。
- 原始 KR Tartaros.bin，12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**，本輪重讀原件確實吻合。PE32/i386，ImageBase 0x400000，.text VA 0x401000、raw 0x400、VirtualSize 0x7D01F0；此 section 的 VA→raw=VA−0x400C00。
- 工作切面：完成「增量角色資料是哪個原生 S2C、按什麼條件寫入哪些角色欄位、如何觸發下一 Quest 候選重算」；交叉核 T03-E 的 53-byte full/delta row。尋找尚缺的獲得技能／裝備／招募交易時不能把**能力屬性更新**當成這些交易。
- 既存主責證據：T03-E W17–W20 (t03/roy/chatgpt-web, blob 5bf17fd8078344bb41a26e8de956b2ec23843731)；T16-124 (blob 79d147affae5e54b688876a1a1ae9765a6edfbaa) 和 T16-128 (blob bddbc8f94c32a3a69a43537be0631f7be3cb9a79) 的 town／QuestOwner 候選流程；上一 W5 的 Quest reward 1..6 欄位分派不變。主責 Task、原稿、正式 RR/REQ/APPROVED 均不更動。
- 本輪直接從本機原始 BIN 在已知入口 objdump 定向反組譯 0x4ADD50、0x4ADFED、0x4B3DA0、0x4D41A0、0x4D4150、0x61C7C0，並以唯讀 Python 核對**64 處 machine-code prefix、四組 direct E8 caller/target 及 14 個欄位幾何**，PASS。這是限定原生指令／局部 CFG 證據，不是所有間接 caller 的窮舉，不代表 Client 實機 S2C wire 已抓到。

## 1. 新確認的 S2C app 0x005C：真正 handler 註冊、角色索引與候選重算

### 1.1 Register table → opcode 0x005C，無同號域混用

0x4ADD50 對該 Client callback 表依每條 **8 bytes** 初始化，handler 在 slot 的 +4（其正常建構基底由 0x4ADD50/相關初始化路徑限定）。在 0x4ADFED，原件指令把 0x4B3DA0 寫入 [EAX+0x2E4]。相對該表 handler 基底 +4，**(0x2E4−4)/8 = 0x5C**，因此是此 Client callback 表的 S2C application **0x005C**。不能與場景管理器的另一張 0x4B7DC0 表、與同號 C2S 或外層 frame marker 混同。

~~~asm
4ADD55 BE D5 0B 00 00          mov esi,0xBD5        ; table entry count
4ADD60 C7 42 FC 40 7D 4B 00   mov [edx-4],0x4B7D40 ; default callback
4ADD67 89 0A                   mov [edx],ecx
4ADD69 83 C2 08                add edx,8
4ADFED C7 80 E4 02 00 00 A0 3D 4B 00
                                  mov [eax+0x2E4],0x4B3DA0
~~~

注意：對此表靜態寫入的函式指標歸屬已證，不保證每個執行時 scene/Conn 都啟用此 handler；仍要經 T02 frame/scene/dispatcher/lane 及 Client owner 生效。

### 1.2 S2C 0x005C handler 的正向判定

~~~asm
4B3DCA 8B 75 08                mov esi,[ebp+8]        ; decoded application payload
4B3DCD E8 CE 0D F5 FF          call 0x404BA0         ; Client owner
4B3DD2 8B 88 24 69 00 00      mov ecx,[eax+0x6924]  ; shared RoleStore base
4B3DD8 0F B6 46 02             movzx eax,byte [esi+2] ; role slot index
4B3DDC 83 F8 09                cmp eax,9             ; <=9 only
4B3DE1 69 C0 10 02 00 00      imul eax,eax,0x210    ; slot stride
4B3DE7 03 C8                   add ecx,eax
4B3DE9 83 79 5C 00             cmp dword [ecx+0x5C],0 ; record valid
4B3DF3 8B C6                   mov eax,esi
4B3DF5 E8 A6 03 02 00          call 0x4D41A0         ; record field writer
4B3DFA E8 61 B2 F5 FF          call 0x40F060         ; World owner getter
4B3DFF 8B B0 8C 00 00          mov esi,[eax+0x8C]    ; current town/context selector
4B3E38 56                      push esi
4B3E39 68 A0 B2 FA 00          push 0xFAB2A0        ; QuestOwner
4B3E3E E8 FD C3 04 00          call 0x500240         ; rebuild Quest candidate list
~~~

**可證控制流**：只有 payload+2 的 index<=9，且 selected RoleStore record+0x5C!=0，且 owner/pointer 有效，才呼叫 0x4D41A0 更新 14 欄位。若此局部不滿足條件則跳至 0x4B3DFA；**候選重算 0x500240 是這些分支後的共用路徑**。函式沒有在其本體寫 QuestOwner+5EB0 前置 key；不能拿 0x005C 替代 S2C 0x46/74/6F。

「此角色等級改變導致下一 Quest 出現」只能說**角色資料改變後有一次重建候選的原生入口**。究竟哪個角色欄位用作等級/力量/HP/EXP，需追 0x500240 與角色 record 的讀取和 source mapping，不能自行命名或填公式。

## 2. S2C 0x005C 的實際 RoleStore 欄位 Writer 契約

在 0x4D41A0，EAX 是 decoded app payload base，ECX 是經上述 index/presence gate 取得的角色 record。每個 typed 數值依原始 x86 load 的寬度擴成 DWORD 寫入 record。偏移**相對 decoded app 起點**；不是 TCP frame 偏移或 memory owner+0x6924 的相對位移。

| S2C0x5C app offset | Type / 長度 | record offset | 機器碼 load/store | 業務名 |
| --- | --- | --- | --- | --- |
| +0..1 | LE16 opcode | dispatcher | 0x4ADFED callback table | 0x005C |
| +2 | u8 role index | select record via index*0x210, <=9 | 4B3DD8–4B3DE9 | role slot |
| +3 | u8 | +0x08 | 4D41A0 / 4D41A4 | UNKNOWN |
| +4..7 | u32 LE | +0x50 | 4D41A7 / 4D41AA | UNKNOWN |
| +8..11 | u32 LE | +0x58 | 4D41AD / 4D41B0 | UNKNOWN |
| +12..15 | u32 LE | +0x54 | 4D41B3 / 4D41B6 | UNKNOWN |
| +16..17 | u16 LE | +0x40 | 4D41B9 / 4D41BD | UNKNOWN |
| +18..19 | u16 LE | +0x48 | 4D41C0 / 4D41C4 | UNKNOWN |
| +20..21 | u16 LE | +0x44 | 4D41C7 / 4D41CB | UNKNOWN |
| +22..23 | u16 LE | +0x60 | 4D41CE / 4D41D2 | UNKNOWN |
| +24..25 | u16 LE | +0x64 | 4D41D5 / 4D41D9 | UNKNOWN |
| +26..27 | u16 LE | +0x68 | 4D41DC / 4D41E0 | UNKNOWN |
| +28..29 | u16 LE | +0x6C | 4D41E3 / 4D41E7 | UNKNOWN |
| +30..31 | u16 LE | +0x70 | 4D41EA / 4D41EE | UNKNOWN |
| +32..33 | u16 LE | +0x74 | 4D41F1 / 4D41F5 | UNKNOWN |
| +34 | u8 | +0xD4 | 4D41F8 / 4D41FC | UNKNOWN |
| +35.. | 本函式未見讀取 | 未證 | 不可冒充保留零 | UNKNOWN |

**至少讀至 +34，所以已讀前綴需 35 bytes。** 不是由此證明官方完整封包長度恆為35，也未證在呼叫此 writer 前有完整的 per-field buffer bound。新 Server 正常合成 emitter 應保守提供完整資料並遵循 T02 framing 大小上限（此為 Server 自訂兼容設計，不是原版官方策略），不要把未證的其它欄位全寫為固定0。

原始關鍵片段：

~~~asm
4D41A0 0F B6 50 03          movzx edx,byte [eax+3]
4D41A4 89 51 08             mov [ecx+8],edx
4D41A7 8B 50 04             mov edx,[eax+4]
4D41AA 89 51 50             mov [ecx+0x50],edx
4D41AD 8B 50 08             mov edx,[eax+8]
4D41B0 89 51 58             mov [ecx+0x58],edx
4D41B3 8B 50 0C             mov edx,[eax+0xC]
4D41B6 89 51 54             mov [ecx+0x54],edx
4D41B9 0F B7 50 10          movzx edx,word [eax+0x10]
4D41BD 89 51 40             mov [ecx+0x40],edx
4D41F1 0F B7 50 20          movzx edx,word [eax+0x20]
4D41F5 89 51 74             mov [ecx+0x74],edx
4D41F8 0F B6 40 22          movzx eax,byte [eax+0x22]
4D41FC 89 81 D4 00 00 00    mov [ecx+0xD4],eax
4D4202 B8 01 00 00 00       mov eax,1
~~~

## 3. 角色全量／增量 53B row 與 0x005C 是同一個 RoleStore，卻是兩種不同 schema

舊 T03-E：S2C0x0002 的 header 65B + N*53B，row 起於 app+65；S2C0x002B header 2B + N*53B，row 起於 app+2；兩者定向直接 E8 caller：4B89AD→4D4150、4E2782→4D4150，record pointer 都由 F94304 / Client owner+0x6924 派生。**本輪新增**：從 0x4D4150 原件直接抽出完整正向 field store：

| 53B row-relative | Native format | 同一 RoleStore 目的 | 來源指令 |
| --- | --- | --- | --- |
| +0..+0x29 | UTF-16 文字，拷貝直到 NUL | record+0x0C 起 | 4D4160..416D |
| +0x2A..0x2D | u32 LE | record+0x08 | 4D4190 / 4193 |
| +0x2E | u8 role index (<=9 gate in caller) | record+0x04 | 4D416F / 4173 |
| +0x2F | u8 | record+0xD4 | 4D4176 / 417A |
| +0x30 | u8 | record+0xDC | 4D4180 / 4184 |
| +0x31..0x34 | u32 LE | record+0x50 | 4D418A / 418D |
| 本地 | record exists flag | record+0x5C=1 | 4D4154 |

此表的 UTF-16 copy 依 NUL 終止，這段 4D4160 loop 本身未見獨立的 **最多21個 code units** 上界檢查；為正常相容資料，Server 應在 row 前0x2A bytes 內包含合適 NUL、與 T03 契約比對，而不是直接把 53B 任意資料當字串。這是**Server 選定安全產生規則**，不等於原版 Client 有安全拒絕能力。

**三個確實重疊的 field provenance**：
- 全量/增量 53B row +0x2A DWORD 和 S2C0x5C +3 BYTE 都寫同一 **record+0x08**（不同寬度，不能宣稱兩者可互換）；
- 53B row +0x31 DWORD 與 0x5C +4 DWORD 同寫 **record+0x50**；
- 53B row +0x2F BYTE 與 0x5C +34 BYTE 同寫 **record+0xD4**。
因此 0x005C 是**已存在角色的局部數值更新接口**，**不是**新角色列記錄序列化的同義版，更沒有 53B row 的 UTF-16 名稱 writer 或將 record+0x5C 從0設1。尤其不能用它「招募」原先不存在的角色。

## 4. 技能、裝備與招募取得：這次確定能排除哪些錯誤假設

- **技能**：0x61C7C0 consumer 的前置 0x61C829/82C 限 index<=9，0x61C835 乘0x210 再用全域 [F94304] 取得角色 record，0x61C841 要求 record+0x5C != 0；但其後移到 record+0xFC 相關的矩陣/配置資料，再到 0x61C900 查 WORD skills 及 0x61CA4A/CA52 的角色 vtable+0x19C。0x005C 的 14 個 writer **沒有寫 record+0xFC 的向量/矩陣**。因此不能由 0x005C 推論已學得技能，更不能把 0x005C 的 u16 fields 直接叫技能 ID。上游真正 skill grant packet/Writer 仍須 T11/原件定向追查。
- **裝備**：0x005C 的數值欄位更新可能影響角色能力顯示，但沒有找到此 handler 的 item instance、inventory list、equip slot、item transaction writer。0x4B44E0 等相鄰 handler 是另一個不同的 opcode／記憶體 owner，不能僅因數字排列就誤指為裝備獲得。仍需從 inventory 物件建構、相應 UI、C2S Equip 事件及 S2C 更新 handler 閉合。
- **招募**：新角色取得至少應有 Server 權威擁有權與 Client record 由 absent→present 的可追來源。這條 0x005C 原生有 present flag gate，但本體**不改 present flag**；因此它不能在本已查正向路徑讓原先不存在的角色可用。S2C0x0002/0x002B 可寫 RoleStore 並在 +5C 設1，但「招募請求→對端成功回覆→擁有權」因果尚未由 Client/原始 Server 對應實證。E81 本地 F431F/CEmployNewCharacter 也不等價於招募。
- **任務**：0x005C 的後段總是按現有 town 呼叫 QuestOwner 0x500240，**並不自行新增 completed QuestID 或發獎**。要讓 Quest15→Quest117 候選出現，仍需 0x46/0x74/0x6F 的合法 prerequisite key15、Town1 selector/其他本地 gate；若先前 Client 已具正確前置鍵，0x005C 可成為**另一個候選重算 trigger**，但是否官方真正在此時送出需 runtime/來源證據。

## 5. Server 待開發（不是把 Client 未知推給後端）

| 玩家情境 | 已證 Client 相容介面 | Server 必須自訂並實作的責任 | Client 尚未證的阻斷 |
| --- | --- | --- | --- |
| 已擁有角色的能力數值變化 | S2C0x005C：index+2，14欄位，已讀至+34，存在 flag 才更新；其後 Quest 候選重算 | Server 保持角色 ownership/attribute snapshot 和 rev；決定何時送對應 **native-reviewed DTO** | 數值業務名、來源公式、哪次事件造成變動、實際 wire/scene gate |
| 新增／招募角色 | 0x0002/0x002B 53B row 可建立/更新 local available record | 招募授權／成本／條件／角色帳號擁有權／DB 寫入 | 取得/成功封包與角色 UI 的因果配對 |
| 技能學習 | skill matrix reader 要求角色 record valid、讀 role+0xFC 資料 | Server-owned unlocked skills、技能版本與載入 | skill grant/learn opcode + writer + UI/裝備介面 |
| 裝備取得／穿戴 | 有角色數值更新，不是 item acquisition | Inventory 和 equipped-instance 持久化，角色 slot ownership、reward claim | inventory/equipment S2C/C2S schema 及客戶端 ItemStore/界面 writer |
| 進下一 Quest | S2C0x005C 後 500240，既有 0x46/0x74/0x6F 及 0x38 town gate | Server 保存完成鍵／獎勵分開交易；合法時序/候選重建/任務持久化 | 角色欄位的等級語意、實際 Client 進村/下一 Q 可視序列 |

不直接修改正式 REQ/GAP：S00 應從 W5-01 與本 W5-02 去重，將可執行的相容 Server-only 持久化/任務同步設計為正式開發要求，保留未知 Client opcode 作來源補證，不標 source gate approved。

## 6. 下一段 Client 靜態研究應接的位置／嚴格狀態

1. **技能 Writer 追索**：從 RoleStore+0xFC（與 0x61C7C0 的讀者）反向定位所有 store/alias；對 0x61CAC0/0x61D540、0x819220/0x81A8E0 的資料來源作上游，不把 UI matrix 讀者當取得事件。
2. **裝備／背包**：先確定 ItemStore owner、角色欄位與接收 callback table 的實際 producer，再對 item acquire / equip/un-equip 分別編明確方向/長度；不能由相鄰 opcode 猜名字。
3. **招募**：追 0x4D4150 之外的 record+0x5C writer/ctor、招募 UI 事件與可能產生的 C2S、S2C0x2B 中角色新增的先決；區分「招募」「建立角色」「選角」三個 domain。
4. **下一任務**：繼續找 0x500240 對角色 level/context 的精確 reader，判斷 0x005C 哪個 record 欄位會影響候選，避免 Server 單靠 Scene(15,3) 更新進度。
5. **待遊玩驗證**：原版 KR Client 收合法 0x5C 後角色頁、任務候選與同版 S2C 2B 的 UI 交互；本輪 NOT_RUN。

**本輪研究狀態：W5-02 bounded Client source supplement 已交付；W5整體 PARTIAL。** 來源資料與真遊戲封包、Client state 與 Server durable commit、T01 證據審核、S00 規格採用，以及實際玩家可玩互不替代。
