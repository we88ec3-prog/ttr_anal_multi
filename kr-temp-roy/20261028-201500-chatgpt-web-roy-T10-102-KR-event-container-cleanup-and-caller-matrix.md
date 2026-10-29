# T10-102 — KR 事件控制器清理、三個容器與 caller 群組：BIN-first 深度核對

## 0. 來源、範圍與證據分級

研究日期：2026-10-28 Asia/Taipei。`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本次實際重新計算。KR PE32 x86 `.text` VA `0x401000`, raw `0x400`；`.rdata` VA `0xBD2000`, raw `0x7D0600`；`.data` VA `0xD61000`, raw `0x95E800`，詳上一段 T10-101。只使用靜態唯讀 BIN 反組譯，不執行、不 patch、不自動將原版 Server 規則補入。

本段承接 T10-101（多個 vtable 指向 `0x5961C0`，第二事件域及結果列表）。本輪主題：其近鄰清理器 `0x596010/0x5960B0/0x596C90` 是否能閉合 caller、回呼與容器生命週期；並進一步排除錯將清理流程視為玩家普通攻擊取消或網路 ack。對所有結論區分：BIN 已確認、部分關聯、業務語義 unknown。

## 1. 第一輪：以 BIN 追踪 `0x596010` / `0x5960B0` 直接 caller

以原始 `.text` raw `[0x400,0x7D0600)` 逐 byte 搜索 `E8 rel32` 候選，計算 `target = instructionVA + 5 + sign_extend(rel32)`；以下只稱候選直到實際 disassembly 核對指令起點。

| 目標 | 原始 `.text` 直接 E8 候選 | 已核實指令 |
|---|---|---|
| `0x596010` | `0x5A39B9`, `0x5A65CA`, `0x5A714A` | `0x5A39B9: e8 52 26 ff ff` = `call 0x596010` |
| `0x5960B0` | `0x5A3CEC`, `0x5A6746`, `0x5A7456` | `0x5A3CEC: e8 bf 23 ff ff` = `call 0x5960B0` |
| `0x596C90` | `0x595E9F`, `0x59610E` | `0x59610E: e8 7d 0b 00 00` = `call 0x596C90` |
| `0x5961C0` | 0 | 依 T10-101 有多個 `.rdata` vtable function-pointer 候選，非不可達證明 |
| `0x596D70` | 73 | 為不同高重用 helper，並非特有攻擊 producer |

### 1.1 兩組對應的上游 entry

```asm
005a3980 55                     push ebp
005a3981 8b ec                  mov ebp,esp
005a39b7 8b d9                  mov ebx,ecx
005a39b9 e8 52 26 ff ff         call 0x596010
005a39be 33 c0                  xor eax,eax
005a39c0 89 44 24 24            mov [esp+0x24],eax

005a3cc0 55                     push ebp
005a3cc1 8b ec                  mov ebp,esp
005a3cea 8b f1                  mov esi,ecx
005a3cec e8 bf 23 ff ff         call 0x5960b0
005a3cf1 33 ff                  xor edi,edi
005a3cf3 f6 05 7c af fa 00 01  test byte [0xfaaf7c],1
```

`0x5A3980` 與 `0x5A3CC0` 皆先保留 caller ECX，再調用鄰近的兩個清理/控制 entry，之後繼續執行當前 owner 初始化/狀態處理（兩者不等於各自直接發送攻擊封包）。兩邊的 `0xF7FC70` / `0xFAAF7C` lazy-init/gate 均不是上一段 `0xFB73E8` 的非零 writer。不能因 caller 成對或入口相近就宣稱是 Z down/up 成對事件。

### 1.2 `0x596010` 本地工作區路徑

```asm
00596038 8b f1                  mov esi,ecx
0059603a 33 db                  xor ebx,ebx
0059603c 89 5d e4               mov [ebp-0x1c],ebx
0059603f 89 5d e8               mov [ebp-0x18],ebx
00596042 89 5d ec               mov [ebp-0x14],ebx
00596045 c7 45 e0 0c 92 c1 00  mov [ebp-0x20],0xc1920c
00596061 e8 5a 1b 00 00        call 0x597bc0
00596066 8d 8e b4 00 00 00     lea ecx,[esi+0xb4]
0059606d 8b c8                  mov ecx,eax
00596072 e8 c9 3e 01 00        call 0x5a9f40
00596077 56                     push esi
0059607a e8 f1 55 e7 ff        call 0x40b670
```

這是局部容器初始化、`owner+0xB4` 參數、`0x597BC0 → 0x5A9F40` 交互，以及傳 owner 給 `0x40B670` 的可觀測序列。尚未證明該路徑會對 `0x5961C0` 成功結果列表做清理，不能自行稱為 attack input flush。

### 1.3 `0x5960B0` 與 `0x596C90` 的直接關係

```asm
005960F9 68 d4 00 00 00        push 0xd4
005960FE 8d 4d e0               lea ecx,[ebp-0x20]
00596108 e8 d3 34 e7 ff        call 0x4095e0
0059610D 56                     push esi
0059610E e8 7d 0b 00 00        call 0x596c90
```

可確定 `0x5960B0` 經 `0x4095E0` 操作局部工作物件後，將原 owner (`ESI`) 推入並直接進入 `0x596C90`，建立 caller → cleaner 的原始 BIN 連結。此途徑沒有在核實指令窗口觀察到 `WSASend` 或類似 wire opcode builder。

## 2. `0x596C90` 真正遍歷的物件與三個子容器

```asm
00596c94 8b 5d 08               mov ebx,[ebp+8]
00596c99 81 c3 c0 00 00 00     add ebx,0xc0
00596c9f c7 45 08 03 00 00 00  mov [ebp+8],3
00596ca6 8b 7b 04               mov edi,[ebx+4]
00596ca9 8b 37                  mov esi,[edi]
00596cab 3b f7                  cmp esi,edi
00596cad 74 5c                  je 0x596d0b
00596cb0 8b 4e 0c               mov ecx,[esi+0xc]
00596cb3 8b 41 28               mov eax,[ecx+0x28]
00596cb6 c1 e8 08               shr eax,8
00596cb9 a8 01                  test al,1
00596cbb 74 0a                  je 0x596cc7
00596cbd 8b 11                  mov edx,[ecx]
00596cbf 8b 82 d4 00 00 00     mov eax,[edx+0xd4]
00596cc5 ff d0                  call eax
...
00596d20 8b 56 08               mov edx,[esi+8]
00596d23 52                     push edx
00596d24 8b cb                  mov ecx,ebx
00596d26 e8 85 08 2c 00        call 0x8575b0
00596d2b 8b 36                  mov esi,[esi]
00596d2d 57                     push edi
00596d2e e8 d9 a4 2f 00        call 0x89120c
00596d41 89 40 04               mov [eax+4],eax
00596d47 89 00                  mov [eax],eax
00596d4c 89 40 08               mov [eax+8],eax
00596d4f c7 43 08 00 00 00 00  mov dword [ebx+8],0
00596d56 83 c3 10               add ebx,0x10
00596d59 ff 4d 08               dec dword [ebp+8]
00596d5c 0f 85 44 ff ff ff      jne 0x596ca6
```

**有界實質結論**：`0x596C90` 的 EBX 起始 `owner+0xC0`，每輪 +`0x10`，重複三次；因此三個容器區塊起始是 `owner+0xC0`, `owner+0xD0`, `owner+0xE0`。對每個容器經 sentinel/tree iterator 路徑訪問節點，`node+0xC` 是被檢查的物件指標；當該物件 `+0x28` 的 bit8 被設置時，進入該物件的 `vtable+0xD4` 回呼；之後依序釋放/抽除節點並將 sentinel 連結還原，count `[EBX+8]` 歸零。`node+0x21` 的檢查用於樹節點遍歷/終止判斷，與物件 `+0x28` bit8 **不是同一欄位**。

`0x596D26 → 0x8575B0` 是抽除/調整節點的重要 helper，`0x596D2E → 0x89120C` 是釋放節點 helper；所謂三容器清理不等於所有 listener 或全局 phase state 清零。這是 `0x5960B0 → 0x596C90` 可驗證的完整局部控制／回收鏈，而非所請攻擊封包 end-to-end。

## 3. 與 T10-101 `0x5961C0` 的分層及反證

1. T10-101 `0x5961C0` 對事件 ID 篩選，並由 caller-supplied `[ebp+8]` 結果列表追加 12-byte node；本段 `0x596C90` 處理的是 `owner+0xC0` 三組容器，每組 `0x10` stride，**不能未經 pointer provenance 將兩者視為同一容器**。
2. `0x596C90` 受 `obj+0x28 bit8` 門控觸發 `vptr+0xD4`，T10-101/097 的 listener 派送對 `vptr+0xEC / +0xF0` 依 phase 1/3 觸發。不同 vtable slot 與呼叫參數，不能把清理 callback 等同成功/接受攻擊回呼。
3. `0x596010` 的 `owner+0xB4`、`0x596C90` 的 `owner+0xC0..+0xE0`、事件 `owner+0x80` listener 桶及別的子物件 `+0x28` flags 必須按 ECX/ESI/EBX 來源分辨；不可將相同 offset 直接等同。
4. 這條清理支鏈尚未追至 Z/Key44 producer，亦無 T02 socket sink 或 S→C battle handler；**不存在可證實的 wire opcode 或連段時窗結論**。

## 4. 玩家情境與封包結果矩陣

| 玩家情境 | Client 本地已證 | C→S 是否發送 / opcode | S→C handler | 動作效果 / 分工 |
|---|---|---|---|---|
| 按下 Z 普攻 | T10-101 僅 KeyMapping resource 與多型事件派送的局部結構；本段未證 keydown→caller | unknown | unknown | unknown；不可預設 Server ack 前後啟動 |
| 連按/長按/放開 Z | 本段僅 owner 局部清理，未證 key-repeat/keyup producer | unknown | unknown | 連段/取消 unknown；不使用自製 0.65 秒 |
| 施放起手/施放中再次輸入 | 本段 `vptr+0xD4` 是依 bit8 的清理回呼，與技能 phase 關係未證 | unknown | unknown | 延遲、阻斷、排隊 unknown |
| 施放中鍵盤移動/滑鼠移動 | 本段未定位兩個獨立 producer | unknown | unknown | unknown |
| 清理事件容器 | `0x5960B0` 呼叫 `0x596C90`，循環清 `owner+0xC0/+0xD0/+0xE0` 三組 | 沒有由此局部函式鏈證明送包 | 不屬已證 S→C 收包鏈 | 原生已確認的本地容器生命週期；不代表完成玩法驗收 |

## 5. 三輪深入門檻、未解問題與下段入口

**本段第 1 輪**：獲得 `0x5960B0 → 0x596C90` 明確 BIN caller、`owner+0xC0..+0xE0` 三組有界 cleanup、bit8→vtable+0xD4 callback、節點刪除與 count 歸零，是新增的可核對完整局部生命週期鏈，達到「完整且具邊界的功能鏈進展」。故 **T10-102-2/102-3 未啟動**；此僅表示上述狹義主題的門檻，不代表 P0 普攻封包研究已完成。

後續正式 T10-103 最優先：從 `0x5A3980` / `0x5A3CC0` 的真實上游（以及另兩組 caller）核對是何種控制器情境；識別 `0x5961C0` vtable slot 的實際虛呼叫與結果容器 consumer；直接追 `KeyMapping`/DirectInput 來源到 packet builder/queue/sink；由 T02 S→C dispatcher 連回 actor motion，特別比較本地角色與其他玩家；施放中 Z 重複/放開、鍵盤與滑鼠移動須分開評估。不得以本段 cleaner 取代這些未完成的封包鏈。原版 Server 判定/連段合法性只列待開發介面，不假造官方來源。

## 6. 可重現命令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -D -Mintel --start-address=0x596010 --stop-address=0x596140 Tartaros.bin
objdump -D -Mintel --start-address=0x596c90 --stop-address=0x596d70 Tartaros.bin
objdump -D -Mintel --start-address=0x5a3980 --stop-address=0x5a39e0 Tartaros.bin
objdump -D -Mintel --start-address=0x5a3cc0 --stop-address=0x5a3d10 Tartaros.bin
```

本段完整來源為本 Markdown；T10-101 為尚未提交的上一份完整原稿，兩份須一同推送工作分支，原始 BIN/EXE 不提交。