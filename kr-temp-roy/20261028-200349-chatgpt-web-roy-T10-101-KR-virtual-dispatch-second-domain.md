# T10-101 — KR 多型輸入派送入口、第二事件域與結果鏈表：BIN-first 限定驗證

## 0. 範圍及證據階級

研究時間：2026-10-28 Asia/Taipei；唯讀靜態核對。研究分支為 `t10/roy/chatgpt-web`，main→branch 的 GitHub PR #1 merge commit `0d4324b9195d9bd8ff7ab5037576857b4e227d00`，compare main...branch 顯示 behind=0。此檔為本次**未提交**本地完整研究原稿。使用者未授權新研究 Commit/Push。

KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本地重新 `sha256sum` 驗證。`objdump -h` 核對 `.text` VA `0x00401000` / raw `0x400`, size `0x7D01F0`；`.rdata` VA `0x00BD2000` / raw `0x7D0600`, size `0x18E07C`；`.data` VA `0x00D61000` / raw `0x95E800`, size `0x22B800`。`.text` VA=raw+`0x400C00`，`.rdata` raw=VA-`0x401A00`。以下機器碼由 `objdump -D -Mintel --start-address ... --stop-address ... Tartaros.bin` 直接重讀；以既有 T10-097～100 的 Markdown 作導航，不將舊分析充當本次新的發現。

GitHub 分支查閱 `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、`kr/tasks/T10/README.md` 及 T10-097/098/099/100。T10-100 明列 T10-101 為下一段；搜尋近期 `T10-101`, `T10-104`, `T10-120` 沒有命中，只作輔助而非以搜尋沒結果當證明。分支此次合併完成後已核驗無落後主線變更。

### 原始證據與推論定義
- **原生已確認（靜態）**：以下精確指令 bytes / VA、控制分支、資料指標及限定範圍查找命中。
- **部分確認**：可辨函式表與事件派送，但無類別 RTTI 錨點、無完整實際 caller、也未閉合 network source/sink。
- **unknown**：某一事件 ID 等於普攻 Z、技能連段允許/取消、原生 wire opcode、封包長度、真實 S→C handler、原版 Server 裁決。
- **AI 替代不得引用**：`CHAIN_WINDOW=0.65` 與任何 fixture 自動續段不是原生結論。

## 1. 第一輪 T10-101：`0x5961C0` 本身並非可證的單一攻擊 handler

### 1.1 靜態直接呼叫搜尋（原始 `.text`）

對 `.text` raw `[0x400,0x7D0600)` 每個偏移測試 `E8 <i32 rel>`，以 `instructionVA+5+signed_rel32` 計算目標；這是**位元組候選**掃描而非完整反組譯指令邊界確認。結果：

| 被呼叫目標 VA | `E8 rel32` 候選數 | 例子 | 限制 |
|---|---:|---|---|
| `0x5961C0` | 0 | — | 未見直接 near call，不代表不會被執行；須追虛表 / 間接呼叫 |
| `0x596140` | 1 | `0x59629D` | 函式內明確 callback fallback |
| `0x6D4CE0` | 2 | `0x59624E`、`0x59643F` | **兩個不同事件域**均查詢狀態 |
| `0x761010` | 4 | `0x58B632`, `0x5961EF`, `0x74EBC9`, `0x74ED70` | selector 共用，不能當普攻專屬 |
| `0x74D700` | 125 | `0x59635F`, `0x59657E`, ... | 12-byte node helper 大量共用，非戰鬥佇列特有 |

**重大新增發現（第一手 BIN 指標證據）**：`.rdata` 對 little-endian `c0 61 59 00`（函式 `0x5961C0` 指標）找到 **29 個 DWORD 候選引用**，例如 VA `0xBF70F8`, `0xBF7468`, `0xBF9D80`, `0xBFA9C8`, `0xBFDB18`, `0xBFE0F8`, `0xC1B4D8`, `0xC1B740`, `0xC1C0F0`, `0xC1C310`, `0xC1C6A0`, `0xC1C980`, `0xC1CB40`, `0xC1CD18`, `0xC1CF20`, `0xC1D0F0`, `0xC1D318`, `0xC1D570`, `0xC1D798`, `0xC1D948`, `0xC1DB10`, `0xC1DE80`, `0xC1E1F0`, `0xC1E5C0`, `0xC1E9A0`, `0xC1F080`, `0xC1F3E8`, `0xC1F598`, `0xC1F760`。`.data` 零命中（僅精確指標搜尋）。**這 29 處不是 29 個已證獨立 caller / class**，但相鄰位置顯示連續函式地址，強烈支持多份 vtable/函式表共用此方法。

`0xBF70F8` 附近 DWORD 的原生值（以該地址為中心）：

```text
BF70E8 00595D20
BF70EC 0040ED30
BF70F0 00403DB0
BF70F4 004067E0
BF70F8 005961C0  <-- 本次定位的派送方法地址
BF70FC 005A3950
BF7100 00595E30
BF7104 00595DA0
BF7108 00595EC0
BF710C 0049AE10
BF7110 004234E0
BF7114 00596B80
```

另一處 `0xC1B4D8` 的前後值與此非常相似，但其 `+4` 為 `0x005F5D10`、`+24` 為 `0x005A7530`，而 `0xBF70F8` 相應位置為 `0x005A3950` / `0x004234E0`。這是「共同方法、不同函式表配置」的原始證據，不代表已證實函式表的 RTTI 類別名稱。實際 vptr 基址 / method index 要從 constructors 與虛呼叫 sites 反推；**不能把表內地址 `0xBF70F8` 本身誤稱 vtable 起點**。

### 1.2 第一事件域：普通事件 ID 0..39

`0x5961C0` 用 EBX 保存 owner ECX，以 `0x761010` 取得條件子物件，`EDI=0` 開始逐 ID 呼叫 `0x6D4CE0`。核心新核對的精確 disassembly：

```asm
005961e8  mov ebx,ecx
005961ed  mov eax,ebx
005961ef  call 0x761010
005961f4  xor edi,edi
005961f6  mov [ebp-0x1c],eax
0059623b  cmp dword ptr [0xfb73e8],edi
00596241  setne byte ptr [ebp-0xf]
00596245  mov esi,edi
0059624b  mov [ebp-0x24],edi
0059624e  call 0x6d4ce0
00596253  cmp byte ptr [ebp-0xf],0
00596257  je 0x596267
00596259  cmp edi,0xd
0059625c  je 0x596267
0059625e  cmp edi,0xe
00596261  jne 0x596386
00596267  cmp eax,1
0059626a  jne 0x5962bc
00596273  mov edx,[ecx]
00596275  mov eax,[edx+0xec]
0059627b  push edi
0059627c  call eax
00596299  push 1
0059629b  mov eax,ebx
0059629d  call 0x596140
005962bc  cmp eax,3
005962c5  mov ecx,[ebp-0x1c]
005962ce  mov eax,[edx+0xf0]
005962d4  push edi
005962d5  call eax
00596386  inc edi
00596387  cmp edi,0x28
0059638a  jl 0x596245
```

- `0xFB73E8 != 0` 時僅此派送 loop 允許 ID13/14；不是普遍禁止所有按鍵或整個遊戲的規則。
- `0x6D4CE0` 返回值 `1` / `3` 選不同的 virtual +`0xEC` / +`0xF0` 路徑；這不是「收到 Server opcode=1/3」。
- 第一次命中可由 child、listener 或 owner 回調成功而產生結果 list 寫入（見下節），沒有直接看到 packet builder。

### 1.3 第二事件域：額外 ID 容器 `0xFDF624`，非固定 40 個 ID

**本段增量**：在同一派送方法 `0x596390` 之後，另有全域 lazy initialization 與 linked-list walk；既有 T10-097 只集中於固定 0..39 結果追加，若視整函式只處理固定 40 種輸入會漏掉另一條路徑。

```asm
00596390  test byte ptr [0xfdf3ec],1
0059639e  or dword ptr [0xfdf3ec],edi
005963a7  call 0x6d1da0
005963c0  test byte ptr [0xfdf3ec],1
005963c7  mov eax,[0xfdf624]
005963cc  mov esi,[eax]
005963f9  mov ecx,[0xfdf624]
00596402  cmp esi,ecx
00596404  je 0x5965b6
0059640a  cmp byte ptr [ebp-0xf],0
00596411  mov esi,[eax+0x8]       ; 從容器 node+8 取事件 ID 候選
00596419  cmp esi,0x2af9
0059641f  jb 0x596429
00596421  cmp esi,0x2afa
00596427  jbe 0x59643d
00596429  mov edx,[eax]
0059642e  jmp 0x5965ad
0059643d  xor bl,bl
0059643f  call 0x6d4ce0
00596444  cmp eax,1
005964e3  cmp eax,3
005965a2  mov edx,[ebp-0x18]
005965a5  mov eax,[edx]
005965ad  cmp [ebp-0x18],ecx
005965b0  jne 0x59640a
005965c7  ret 4
```

在 gate byte `[ebp-0xf]` 為 1 時，只有 `0x2AF9..0x2AFA`（含端點）範圍進入後續派送；其他第二域 ID 先 skip。**這不能推出 ID 0x2AF9/0x2AFA 的玩家語義；它們也不是 wire opcode**。兩域共同調用 `0x6D4CE0`，但傳入 register ID 不同：第一域 EDI，第二域 ESI，必須在 callee 正確核對 ABI 才能判定它如何分流高 ID。

第二域發出 vtable callback 仍是 `+0xEC/+0xF0`，結果 append 位於 `0x596570`；資料如下：

```asm
00596454  mov eax,[ecx]
00596456  mov edx,[eax+0xec]
0059645c  push esi
0059645d  call edx
005964b0  mov ecx,[edi+8]
005964b3  mov edx,[ecx]
005964b5  mov eax,[edx+0xf0]
005964bb  push esi
005964bc  call eax
00596540  mov ecx,[edi+8]
00596543  mov eax,[ecx]
00596545  mov edx,[eax+0xf0]
0059654b  push esi
0059654c  call edx
00596570  mov edi,[ebp+8]
00596573  mov esi,[edi]
00596575  mov ecx,[esi+4]
00596578  lea eax,[ebp-0x2c]
0059657b  push eax
0059657c  push ecx
0059657d  push esi
0059657e  call 0x74d700
00596583  mov ecx,[edi+4]
00596596  inc ecx
00596597  mov [edi+4],ecx
0059659a  mov [esi+4],eax
0059659d  mov ecx,[eax+4]
005965a0  mov [ecx],eax
```

第一域對應的 append `0x596351..0x596384`，共同使用 `0x74D700` 配置 12-byte result node。**第二域在 `0x596578` 傳入 local `[ebp-0x2c]`，第一域在 `0x596359` 傳入 `[ebp-0x24]`，所以即使 helper 相同、雙方記錄的事件 ID 來源也不同**。這是事件成功回報列表，未證實其後被網路層消費。

### 1.4 例外 / 否證路徑
- `0x596433` 在 result count 超過邊界時計入錯誤函式 `0x87DB30`（錯誤字串地址 `0xBF2034`）；不代表攻擊封包容量／送出限制。
- `0x5965B6` 清理 SEH stack 並 `ret 4`，回傳沒有明顯布林值，主要可觀察副作用是回呼及追加外部 list。不能把 function return 當 Server ack。
- 與 `0xFB73E8` 相鄰的 `0xFB73B8`、`0xFDF3EC` 是**不同全域地址**，前者 / 後者的 bit0 OR 位於 lazy-initializer 路徑，不得錯認成 `0xFB73E8` nonzero writer。

## 2. 三輪深入規則：本段停點

**實際輪次：第 1 輪 T10-101**。已證實 `0x5961C0` 的 `.rdata` 29 個函式表指標候選（先前缺少的進入方式重要線索），並新核對第二事件域 `0xFDF624`、`0x2AF9..0x2AFA` 特殊 gate、兩個不同事件域共用 callback/result-list 的原生 CFG。此為重要可重現的結構性新發現，達共用 `02` 文件「重大新發現」門檻，故未啟動 `T10-101-2` / `-3`；不把未執行的輪次冒充已分析。

不過 **P0 攻擊封包閉環仍未完成**。不能因辨出虛表／事件結果列表，宣稱玩家按 Z 已發包、收到某 S→C 就開始動作或技能輸入已被取消。進一步的正式研究仍應優先回到玩家可驗證封包鏈；此份原稿只對上述地址與資料流提供已確認結論。

## 3. 玩家情境 × C→S × S→C × 動作效果矩陣

| 玩家情境 | Client gate / producer | C→S | S→C / handler | Client 動作結果 | 證據等級 / 責任 |
|---|---|---|---|---|---|
| 單按 Z 普攻 | 原始 Type0 KeyMapping ID13..16 ↔ Key44..47 已由前段核對；**本段未建立裝置事件到 `0x5961C0` 的連線** | **未知**，未證發送/否定 | **未知** | 本地預播與否未知 | 僅按鍵資源部分確認；Server 判定待開發 |
| 連按 / 長按 / 放開 Z | 沒有在本段核對 key repeat / keyup producer | **未知** | **未知** | 連段時窗、queue、取消未知 | 資訊缺失；不得使用 0.65s |
| 技能施放中再按 Z | `0xFB73E8` gate 對事件 ID 13/14 的有限篩選已確認，**但全域旗標意義及與施放中關係未知** | **未知** | **未知** | 抑制／延遲／取消未知 | 部分確認，不當作技能流程事實 |
| 技能施放中鍵盤／滑鼠移動 | 本段未定位兩套事件 producers | **未知** | **未知** | 移動／停步未知 | 資訊缺失，分開待追 |
| 本地事件 phase1 / phase3 callback 成功 | `0x5961C0` virtual +0xEC / +0xF0、`0x74D700` append | **未證任何 wire 對應** | **未證任何 wire 對應** | 只證實 result list 變化，非動作 | 事件結構原生已確認；業務分類未知 |

## 4. 後續可執行驗證入口

1. **先破 vtable dispatcher 上游**：以 `.rdata` 29 處指向 `0x5961C0` 的 DWORD，各向前尋找真實 table base、constructor 指派、虛呼叫 `CALL [vptr+index]`；重建 `owner ECX` 與 `[ebp+8]` 結果容器的建立者／consumer。特別避免誤把 `0x5961C0` 無直接 E8 call 斷言為不可達。
2. **結果列表消費路徑**：`0x596351` / `0x596570` 寫入 caller-supplied `[ebp+8]`，藉實際 caller 的 stack setup 確立 list 清理、結果循環、是否接 packet builder。不能僅以 `0x74D700` 高重用數宣稱攻擊 queue。
3. **玩家按鍵網路發送**：從原始 KeyMapping 與 DirectInput/WndProc 的 Z down/up/repeat 消費點追到 action controller、packet enqueue、T02 socket sink；確認真正 wire opcode、長度與欄位。高 ID 第二域不要與 MapButton 直接混同。
4. **S→C 反向**：T02 socket framing/dispatcher → 具體 battle handler → local/remote actor motion，對照 T09/T11/T12 的已審核有限結論，不以 AI fixture 補 Server 回包。
5. **施放中輸入**：先找技能 phase 的**非零** writer，再分鍵盤 vs 滑鼠的 movement producer，分別列出本地 gate 和 wire 送出；本段未定位非零 writer。
6. **本地額外驗證需求**：若 GitHub 有其他 Agent 近期新增 T10 原稿，依最新 branch 完整目錄和 Git SHA 去重；若要做動態鍵盤事件／packet capture 須另行明確授權，不能自行執行、patch Client。

## 5. 可重現指令（僅研究者使用）

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -h Tartaros.bin
objdump -D -Mintel --start-address=0x596140 --stop-address=0x596390 Tartaros.bin
objdump -D -Mintel --start-address=0x596390 --stop-address=0x5965ca Tartaros.bin
```

已執行的位元組搜尋方法：遍歷 `.text` 範圍所有 bytes，若 byte=`0xE8` 則 read `<i` signed displacement 判定 `target=VA+5+disp`；另在 `.rdata` 範圍搜尋 `struct.pack('<I',0x5961c0)` 並轉 VA。這些輸出只有候選，必須靠反組譯確認其語義（上文已對核心 CFG 讀取真正指令）。