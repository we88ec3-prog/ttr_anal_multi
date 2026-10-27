# KR T09 — 每 tick 順序：490FE0 → 封包泵 804740 → 4E0060（先送輸入幀 5452C0、再逐一 actor Update）

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-27 14:20:07 +08:00`
- Scope: `490FE0`（CClient vtbl+0x30）、`4E0060`、`4E13F0`；`491C90..491CBB`、`4E0060..4E00C6` 機器碼；vtable 掃描（`mov r,[r+0x20]; call r` 慣用式）
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…T09-bulk-tick-rate-hero-driven-by-server-echo-and-actor-id-type.md`（缺口：每 tick 迴圈位置、`vtbl+0x98` 呼叫者）
- Summary: 找到每 tick 迴圈。`490FE0` 每次被呼叫：處理斷線 → 每 60 s 的 0x00A7 心跳 → `[0xF9423C]=timeGetTime()` → 各子系統 → **`804740` 封包泵（所有 S→C 處理在此執行）** → 固定計時的 0x0010 封包 → `40F060()` 取得 holder → **`4E0060`**：先呼叫 ctrl `vtbl+0x2C`（＝`5452C0`，建立並送出 C→S 輸入幀），**再**對 actor map 逐一呼叫 `vtbl+0x20`（Update；CCharacter→`4CDD40`→`4C8580`→`4CA890`）。`vtbl+0x98`（`4CAF10`）在全程式沒有虛擬呼叫者。

## 狀態標記
【確認】＝機器碼確認；【bulk】＝只見於 Ghidra 偽碼；【推測】；【未知】

## 一、`4E0060`（holder::UpdateAll，ECX＝holder `0xFAB130`）（【確認】機器碼 `4E0060..4E00C6`）
1. `if (holder[+0xAC] > [C5566C]) ctrl[+0x58] = 1`（`4E008C..4E00A8`；`C5566C` 的值未讀；`holder+0xAC` 在 `4BB540` 等處以 `0x3DCCCCCD`＝0.1 設過，見 bulk `4B0640` 偽碼）。
2. `call [ctrl.vtbl+0x2C]`（`4E00AD..4E00B0`）＝**`5452C0`**（先前確認為 CController vtbl+0x2C，建立並送出輸入幀）。
3. `4E13F0(first, end, 0)`（`4E00C1`）：中序走訪 `holder+0xC` 起的 actor map，對每個節點值 `call [obj.vtbl+0x20]`（【bulk】`4E13F0` 偽碼；機器碼層我只核對呼叫點）。
4. 其後（【bulk】）：若 `DAT_00FB73E8≠0`，把 `DAT_00FB76E8` 的 `+0xC/+0x10/+0x14`（相機位置）×0.1 傳給聆聽者物件；`6D6ED0(holder+0xD0)`。
- 唯一呼叫者：`0x491CB6`（在 `490FE0` 內；機器碼 `491CAF call 40F060; mov ecx,eax; call 4E0060`），條件 `[client+0xBFCC]==0`（`491CA7` `cmp [edi+0xBFCC], esi`，esi＝0）。

## 二、`490FE0`（CClient vtbl+0x30）單次呼叫順序（【bulk】偽碼；關鍵片段機器碼核對）
1. 取 `DAT_00FBA858`（連線管理）臨界區，掃描連線表：若 `[conn+0xA0AC]≠0` 視為斷線，記錄 `"[%d] Disconnected.\n"` 並從清單移除。
2. 每 `0x78` 次呼叫 `fflush(DAT_00FBA804)`（記錄檔）。
3. 若 `DAT_00FD8C00≠0` 且距上次 ≥ 60000 ms（`59999 < now − last`）：送 **2 bytes `0x00A7`**（`[0xFBA854] vtbl+0x10(0,buf,2)`；`DAT_00FBA798==0` 才送）。
4. 各子系統 tick（`6D8E50`、`6D9F00`、`80C8A0/80CA10`、…、`58A250`、`490D40`、`490E20` 等）；視 `DAT_00FBA80C` 狀態呼叫 Scene `vtbl+0xC/+0x10/+4/+8`。
5. `DAT_00F9423C = timeGetTime()`（**這就是 5452C0 內讀的節流時間戳**；先前未知的 `[0xF9423C]` 在此更新）。
6. 截圖（PrintScreen 鍵 `GetAsyncKeyState(0x2C)`）等非遊戲邏輯。
7. **`804740(client+0x140)` 封包泵**：從收包雙緩衝取出並分派（S→C 表 A/表 B 處理）。
8. 若 `DAT_00F93934 < 5`（一般狀態）：
   - `[client+0xBF68]`（偽碼 `piVar4[0x2FDA]`）為倒數毫秒：若 `< 0x22` → 重設為 **4000**、送 **2 bytes `0x0010`**、記 `timeGetTime` 於 `[client+0xBF64]`、`[404BA0()+0x5F54]++`；否則 `-= 0x21`（機器碼 `491C9E add eax,-0x21; mov [edi+0xBF68],eax`）。→ 每次呼叫扣 33 ms，約每 4 s 送一次 0x0010（用途【未知】，像延遲量測／保活；`0x5F54` 為計數）。
   - 若 `[client+0xBFCC]==0`：**`4E0060`**（上節）→ `489C60/489530`、`434130` 物件 `vtbl+0x14`、`550EC0`…
   - 其餘 UI／特效／音效更新；若 `[client+0xBFCC]==0` 再跑 `48A1D0/55AF80/56CF10/…/561520/…`。
   - 最後 `804A40`（或 `804C70`，視 `[client+0x1D0]` byte）與 `804FC0`：**網路送出側處理**（`804A40` 等的內容未讀；【推測】為排空送出佇列）。
- 「扣 33」與 `6D9870` 結尾的 `Sleep(0x21)`（33 ms）互相吻合（【推測】主迴圈約 30 次/秒）；`+0x1360=30` 與 33 ms 一致。呼叫 `490FE0` 的外層迴圈（經 `vtbl+0x30`）未找到，頻率仍是【推測】。

## 三、整體時序（【確認】順序；頻率【推測】）
```
每個主迴圈 tick（約 33 ms）
  490FE0
   ├ 斷線掃描 / 0xA7 心跳(60s)
   ├ F9423C = timeGetTime()
   ├ 804740  收包並派發 S→C 處理（0x0B 移動狀態、0x01 位置、0x18 目標…）
   ├ 0x10 計時封包（~4s）
   └ 4E0060
       ├ ctrl.vtbl+0x2C = 5452C0 ：讀輸入(546100) → 組 C→S 輸入幀 → 送出
       └ 逐 actor vtbl+0x20 Update ：CCharacter→4CDD40→4C8580→4CA890
              （[E2 bit15] 依剛才 0x0B 設定；沿 [E4] 朝向前進一步 speed/30；殘差消耗）
  804A40 / 804FC0  網路送出處理
```
- 含意：**同一 tick 內，伺服器剛送來的 0x0B 先被套用，再由 `5452C0` 讀取本機輸入並送出，最後才推進 actor 位置**；因此 `546100`／`5452C0` 讀到的 `[+0xE2]/[ctrl+0x74]` 等是「本 tick 收包之後」的狀態。

## 四、`vtbl+0x98`（`4CAF10`）（【確認】全程式掃描）
- 以 capstone 反組譯整個 `.text`（2,447,526 條指令），找 `mov r,[r2+0x98]; call r`：命中 41 個函式（`599A80`、`5CE830`、`6D5410…`、`73A620`、`750970…`、`7F84E0…`、`83D190`、`864E70`、`872BF0`、`87B5F0`、`87C480..87D840`），**沒有任何一個位於 `0x4C0000–0x4D3000` 的 actor／場景範圍或 `0x540000–0x548000` 的 CController 範圍**；`4CAF10` 也不在這些函式的靜態呼叫圖中（無 `call 0x4CAF10`）。→ 無證據顯示它被用在英雄移動（結論：【確認】無虛擬呼叫者於 actor 範圍；【推測】屬 CBasicObject 的殘留方法）。
- 對 `+0x20` 的同樣掃描得 248 個函式；真正 `for_each Update` 迴圈只有 `4E13F0`（被 `4E0060` 呼叫）。

## 五、側記（非 T09；可歸 T02/網路）
- `4957C0`（連線）：向 `[0xFBA854] vtbl+0x18(host, port, kind, 2)` 連兩條：port **0x20E0（8416）** 與 **0x20DE（8414）**；任一失敗記 "Failed to connect game server"／"Failed to connect bridge server"；成功後送 **0x39 bytes** 的 `cmd 1` 登入封包（內容含 `[404BA0()+0x67E0]` dword、兩個 10 字元寬字串 `+0x67E4/+0x67FA`、byte `+0x6898`、字串 `+0x6899`、dword `+0x68A0`）。偽碼；未做機器碼核對。
- `4C4750`／`4BB540`：場景進入時重新建立 CController（`547390` size 200 或 `548540` size 0xC0，視 `DAT_00FBA7AC`＝3 或其他）。`4C4920`（CScenarioField vtbl+0x28）與 `4B0640`（31 KB）處理戰鬥結果類封包（13 B/筆 `{id,target,type,amount…}` 含傷害數字顯示），**與位置無關**。

## 差異（對先前記錄）
- 新增：每 tick 順序；`[0xF9423C]` 的寫入者；0x10／0xA7 兩種定時封包；`vtbl+0x98` 無呼叫者。
- 修正：先前把 `5452C0` 描述為獨立的「幀組裝」入口；實際它由 `4E0060` 在每 tick 呼叫且**先於** actor Update。

## 尚未確認
- `C5566C` 的值；`ctrl[+0x58]` 的用途（`4AF920` 也設 `[ctrl+4]`）。
- 呼叫 `490FE0` 的外層迴圈與其節流；`804A40/804C70/804FC0` 內容；`0x0010` 封包用途。
- `5452C0` 輸出幀開頭 4 bytes（`word 0x000A` 之後的殘值）；本輪未動。
- 其餘 `[client+0xBFCC]`（跳過 `4E0060` 的條件）的寫入者。

## 建議
- 值得提交：`kr-temp-roy/`（T09，並供 T02 網路主題使用）。
- 下一步（T09）：(1) 讀 `804740` 之後的 `804A40/804FC0` 與 `[client+0xBFCC]` 寫入者；(2) 回頭解 `5452C0` 開頭 4 bytes 與 `C5566C`；(3) 把 `4CA890` 步進公式＋`4B2730` 的 steps 換算成「幀」與「秒」。
