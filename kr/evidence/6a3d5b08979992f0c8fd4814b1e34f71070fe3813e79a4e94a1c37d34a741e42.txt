# KR T10 — 普攻候選輸入狀態機、輸入旗標與動作允許表（下一段原始研究）

日期：2026-10-27 Asia/Taipei。任務：KR T10 普通攻擊與連段；使用者補充有 Z 連按與 Z 持續按住兩種操作。**本篇不是已解密的 Z 鍵完整連段規則**。未 Commit／Push；無權變更 task.json / shared catalog。

## 1. 第一手資料與限制

- `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段重新計算）。
- PE32/x86，`.text` VA 0x401000/raw 0x400。反組譯使用 `objdump -Mintel -d --start-address=... --stop-address=...`。採唯讀分析；未執行目標，未改遊戲、資料、封包。
- 先前研究來源：`20261027-182049-chatgpt-web-T10-input-state-machine.md`；GitHub `kr/tasks/T10/README.md`、`task.json`，`AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`。T10 的範圍是輸入、連段、取消；傷害公式由 T12 主責。T10 仍為 `bounded-review-handoff`、未認領。
- 現有直接證據只覆蓋指定 BIN 地址；原函式名稱均用地址標記；尚未做輸入資料全域別名分析和動態實測。

## 2. 新確認：timer 的匯入符號是 timeGetTime

PE import directory 直接列出 `WINMM.dll`, IAT `0x007d25a0`（image RVA+base= `0x00BD25A0`）為 `timeGetTime`。`0x5472B5` 及 `0x5472FF` 呼叫 `[0x00BD25A0]`，因此 `0x547308 cmp eax, 0x1f4` 確為 Windows 多媒體計時值相差 **500 ms** 的判斷。這是上一段「單位尚待確認」的有證據更新。

```asm
5472B5 call dword ptr [0x00BD25A0]    ; WINMM!timeGetTime
5472C0 mov  [esi+4],eax                ; saved tick
5472C3 mov  dword ptr [esi],2          ; phase
...
5472FF call dword ptr [0x00BD25A0]
547305 sub  eax,[esi+4]
547308 cmp  eax,0x1f4                ; elapsed 500 ms
54730D jbe  0x54735e                 ; <=500: return 0 in this route
54730F mov  dword ptr [esi+4],0
547312 mov  edi,3
547317 mov  dword ptr [esi],3
```

**重要證據界限**：timer 與 state machine 真實存在，但未證明其輸入為 Z、未證明 500 ms 是「連段窗口」或「取消窗口」。

## 3. 完整按鍵狀態機可辨識分支表

直接由 `0x547240..0x54736F` 控制流程解碼。輸入 `mode = *(BYTE*)0xFB9014`；持久記錄 `phase=*(DWORD*)esi`、`savedTick=*(DWORD*)(esi+4)`。表列中 `return` 為函式返回 EAX；未命中的路徑通常返回 0。

| 舊 phase | mode / 時間 | 新 phase | return | 直接組語依據 |
|---|---|---|---|---|
| 0 | mode = 1 或 2 | 2；保存 timeGetTime | 1 | 5472A7–5472C9 |
| 0 | 其他 | 0 | 0 | 5472A7–5472AF |
| 1 | mode != 0 | 0；清計時值 | 0 | 5472DB–5472E4 |
| 1 | mode = 0 | 1（原樣） | 0 | 5472DB–54735E |
| 2 | mode = 0 或 3 | 0；清計時值 | 2 | 5472F6–547339 |
| 2 | mode != 0/3 且經過 <=500 ms | 2 | 0 | 5472FF–54730D |
| 2 | mode != 0/3 且經過 >500 ms | 3；清計時值 | 3 | 5472FF–54731D |
| 3 | mode = 0 或 3 | 0；清計時值 | 4 | 54734B–547359 |
| 3 | 其他 | 3 | 0 | 54734B–54735E |

注意：phase=1 在此函式未看到被寫入的新轉換，可能由其他初始化、其他函式或歷史狀態設定；**不要由 phase 1 存在推測按鍵語意**。mode=1/2 與 mode=0/3 只有可觀察數值分類，尚未核出各自的實際 Z 押放含義。

## 4. 狀態返回碼轉成候選輸入位元

`0x546780` 將 `controller+0x5C` 的原 WORD 作為底，再呼叫 `0x547240`，只將 2、3、4 三個返回值映射到新 bit；返回 1 在此處不加入 bit。

```asm
546791 movzx ebx,word ptr [edi+0x5c]
546795 lea esi,[edi+0x40]
5467A4 call 0x547240
5467AD sub eax,2
5467B8 or  ebx,0x40           ; result==4
5467BD or  ebx,0x80           ; result==3
5467C5 or  ebx,0x08           ; result==2
5467CD call 0x546850
5467E0 call 0x546B50
5467EC call 0x546D50
5467F4 mov  word ptr [edx],bx
```

| machine return | `0x546780` 新 OR bit |
|---|---|
| 0 | 無 |
| 1 | 無 |
| 2 | `0x0008` |
| 3 | `0x0080` |
| 4 | `0x0040` |

此表可以重現觀察，但位元不等於已確認的普攻或連段指令。後續 `0x546850`/`0x546B50`/`0x546D50` 的額外方向/指標資訊不應錯歸於這三個 bit。

## 5. 新追查：`0x54F270` 的「輸入 byte → 分類碼 → 條件表」路徑

`0x5462DD call 0x54F270` 的調用點讀取一個由角色相關資料來源導出的 byte（`0x5462B4` 讀 actor+0x3E8；`0x5462BC` 判定另一 byte，`0x5462C3` 以其挑出 byte）。這個 AL **並非**直接傳入 `0x546780` 的 input WORD；不可把兩者硬認成同一欄位。

`0x54F270` 對 AL 的 bit 進行有優先序分類，之後依表取得另一值：

```asm
54F277 test al,0xC0              ; 若任一高兩位已設，直接跳至返回 1
54F284 je  0x54F28E
54F286 test al,0x02              ; bit0 + bit1 => bl=4
54F293 test al,0x04              ; bit0 + bit2 => bl=5
54F2A2 test al,0x04              ; bit1 + bit2 => bl=6
54F2AF mov bl,0x01              ; bit0 => 1
54F2B8 mov bl,0x02              ; bit1 => 2
54F2C0 mov bl,0x03              ; bit2 => 3
54F2C4 test al,0x08             ; bit3 => 7
54F2CC test al,0x10             ; bit4 => 10
54F2D5 movzx ecx,word [esi+2]
54F2DB call 0x40F7F0
54F2E0 call 0x819220
54F2F7 call 0x81A8E0           ; al 與分類碼 bl 參與
54F2FC movzx eax,ax
54F2FF test ax,ax
54F310 call 0x54F4E0
54F317 cmp dword [eax+4],0
54F31D mov eax,ecx             ; 比較結果回傳布林
54F325 mov eax,1               ; 快速容許路徑，含 al bit6/7
```

由此確認**具優先序的狀態／動作候選 gate**，不是直接的 damage 計算：

| AL 條件（按執行優先序） | 暫定分類碼 BL |
|---|---|
| bit0、bit1 | 4 |
| bit0、bit2（先前未匹配） | 5 |
| bit1、bit2（先前未匹配） | 6 |
| bit0 | 1 |
| bit1 | 2 |
| bit2 | 3 |
| bit3 | 7 |
| bit4 | 10 |
| 無匹配，或 bit6/7 提前分支 | 不使用上述分類，返回 1 |

分類碼與角色資料索引被送往 `0x81A8E0`，其回傳 ushort 在 `0x54F4E0` 查表。仍須逆向 `0x81A8E0`、`0x54F4E0` 的語義與來源，才能斷言是否為攻擊、動作可取消、技能覆蓋等。**碼 1..7/10 不等於普攻 1..7/10 段。**

## 6. 新追查：輸入全域的初始化／清除路徑

原 BIN 對地址 `0xFB9014` 的直接絕對位址引用共五處（`.text` raw 範圍搜尋小端 DWORD；不包含 alias/indexed write），對應 `0x547293`、`0x6D088A`、`0x6D1B17`、`0x6D4AB1`、`0x6D4B80`。後四處都是區塊清零/初始化指令，例如：

```asm
6D1A9F lea eax,[ebx+ebx*4]
6D1AA2 shl eax,7
6D1AA5 add eax,0xFB8834      ; 根據引數選擇資料塊
6D1AAA mov [0xFB902C],eax
6D1B00 xor eax,eax
6D1B02 mov [0xFB9004],eax
...
6D1B16 mov [0xFB9014],eax
...
6D1B2F mov [0xFB9028],eax
```

- `0x6D1A70` 依引數設定 `0xFB902C` 指向不同塊，再清理 `0xFB9004..0xFB9028`；它是此全域狀態組的重設線索。
- 尚未找到「將當前按鍵事件寫入 `0xFB9014`」的非零直接寫入指令；很可能透過間接指標或索引寫入，**不能因此斷言沒有更新者**。
- 尤其沒有 Z 的 VK `0x5A` 或 DirectInput DIK_Z 映射證據；不能將 `0xFB9014` 已命名為 Z。

## 7. 原生使用者操作假設與驗證矩陣

| 操作／問題 | 已有直接證據 | 尚缺資料 |
|---|---|---|
| Z 連按 | 使用者確認此操作；原 BIN 有多狀態輸入與 transition 返回碼 | Z 映射、事件模式、動作序號連續性 |
| Z 長按 | 使用者確認此操作；原 BIN 有 >500ms 轉換 | 長按輸入是否屬 0xFB9014、後續自動攻擊觸發點 |
| 兩者合流 | 0x546780 產出 WORD，0x546100 有過濾；0x54F270 處理另一 AL 類別 | 狀態關聯、同一攻擊/動畫/連段消費者 |
| 取消規則 | 0x546100 具角色/狀態 gate，0x54F270 具條件表 | 確定何時可取消、原因、攻擊段數、服務端權限 |
| 0.65 秒 | 僅為歷史自製 CHAIN_WINDOW | 沒有原版依據 |

## 8. 後續完整鏈閉合順序

1. 以 `0xFB902C` 指向的資料塊及 `0xFB9004..0xFB9028` 的間接/索引存取作第一手追蹤，定位按鍵映射配置來源（特別是 Z；檢查 DIK/VK 但不可臆測）。
2. `0x81A8E0` → `0x54F4E0` → actor/animation/action state，核對 `0x54F270` 的分類碼與實際消費者。
3. 找出 Z 重複按下與持續按住是否在本機反覆生產相同指令，或由服務端回覆驅動下一段；最後驗證取消 gate。
4. 跟 T02/T04/T09/T12 主責函式僅引用，無認領不改共享 catalog；由使用者授權時才 Commit。

## 9. 證據級別與更新

**BIN 已確認：** `0xBD25A0`=WINMM!timeGetTime、`0x547240` 的 500ms、狀態轉移表、`0x546780` 的三種 bit 輸出、`0x54F270` 的優先序分類與表格查詢、`0x6D1A70` 的全域陣列重設。

**合理推測：** `0x54F270` 是與目前 actor 的操作／動作可否通過有關的 gate；`0xFB9014` 可能屬可配置輸入狀態集合。

**尚待驗證：** 哪個輸入狀態是 Z、哪些分類碼是普攻、何者控制連段/取消、Z 連按/長按的具體合流、伺服器續段/權限、官方時間窗口。

Git：本段只有本地可下載 Markdown，**未 Commit／Push**。本段雖新增可直接查核證據，仍未聲稱「Z 鍵完整功能鏈已還原」。