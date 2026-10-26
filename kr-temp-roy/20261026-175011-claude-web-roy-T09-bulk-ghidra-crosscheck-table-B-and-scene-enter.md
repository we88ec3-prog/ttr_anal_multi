# KR T09 — 對照 kr-bulk-roy（Ghidra 批次反編譯）：表 B 的填入方式、GameMode 切換、進場 C→S 封包 0x0043

- Recorder: `claude-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-26 17:50:11 +08:00`
- Scope: `kr-bulk-roy/9741…/`（20 個 raw batch，共 320 個函式的 Ghidra 偽碼）與機器碼對照：`4BB4A0`、`4BB7B0..4BB801`、`4B9090`（含跳表 `4B9238`、位元組表 `4B924C`）
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 僅靜態；未執行遊戲；原檔未修改
- 接續：`…T09-summary-draft-for-integrator.md` 的缺口「表 B 內容」
- Summary: bulk 是 Ghidra 12.1.4 偽碼（`confidence: derived`），涵蓋 0x42C530–0x7F7190 共 320 個函式，**不含**本任務已讀的移動／碰撞／收發核心（`4AFxxx`、`4CAxxx`、`5452C0`、`546100`、`82CDF0`、`8069A0` 等皆不在內）。本輪只取與 T09 有關的部分並以機器碼核對：(1) 表 B 的填入格式與大小；(2) Square／DuelSquare 的表 B 條目；(3) 進場時 C→S 4 位元組封包；(4) GameMode 切換函式。

## 狀態標記
【確認】＝機器碼確認；【推測】＝合理推出；【未知】＝未確認；【bulk】＝只見於 Ghidra 偽碼、未另以機器碼核對

## 一、bulk 內容盤點（【確認】計數）
- 20 個 raw JSON，每個 `operation: batch_decompile`；`items[].address/pseudocode`；`total=16` 的批次共 320 個；全部 `status: ok`。
- `functions/` 目錄另有 `0x4b9090.c`、`0x4bbb70.c`（與 raw 內相同）。
- 與 T09 相關的地址群：`4B7200..4B9320`（Scene 模式切換／場景建構）、`4BB3E0..4BC1F0`（Square 類建構／進場）、`4F3D80/4F5640`（`MAPLIST`、`trigger`、`bound` 的 XML 解析；屬 T06/T07 側記）、`544020/544860`（送封包薄包裝）、`542CD0..543050`（音效 XML，無關）。
- 偽碼的 `FUN_xxxxxxxx` 位址與我先前記錄一致（例：`FUN_004add50`、`FUN_00404ba0`、`FUN_0082ef00`、`DAT_00fab130`、`DAT_00fba7a4`、`DAT_00fba854`），沒有衝突。

## 二、表 B 填入（`4BB4A0`、`4BBBA0`）（【確認】機器碼）
`4BB4A0..4BB53B`：`memset(esi+0x5EAC, 0, 0x5EA8)`，之後以 `mov [esi+disp], imm` 寫入 {handler, ctx=0xBF2375}。
- 表 B 基底 `+0x5EAC`、每項 8 bytes、總長 `0x5EA8 = 0xBD5×8` → **表 B 與表 A 同為 0xBD5 項**（新確認；先前只知道表 A 的 0xBD5）。
- 索引＝(disp−0x5EAC)/8（我的算術）：
| disp | 索引 | handler |
| --- | --- | --- |
| 0x5FA4 | 0x1F | 4C5C50 |
| 0x5FD4 | 0x25 | 4C5C50 |
| 0x61BC | 0x62 | 4BB990 |
| 0x61EC | 0x68 | 4BC050 |
| 0x61FC | 0x6A | 4BBFA0 |
| 0x6204 | 0x6B | 4BBAE0 |
| 0x63F4 | 0xA9 | 424610 |
| 0x6404 | 0xAB | 424610 |
- `4BBBA0`（CSquare 建構尾段，bulk）是上表去掉 0x62／0xA9／0xAB 三項的子集（【bulk】）；`4BC170`（CMissionDecision，bulk）在索引 `0x81` 設 `4BC460`（偽碼 `in_EAX[0x18ae]`＝+0x62B8；`(0x62B8−0x5EAC)/8=0x81`）。
- 這些是 **Square／DuelSquare／MissionDecision** 的表 B；**Field 類（CScenarioField 等）的表 B 條目不在 bulk 內**，先前記錄的 0x0E=436C40、0x14=4C5930 未被本輪改變。

## 三、GameMode 切換 `4B9090`（【確認】跳表）
- `movsx ecx,[eax+2]; lea eax,[ecx-7]; cmp eax,0x11; ja default; movzx edx,[eax+0x4B924C]; jmp [edx*4+0x4B9238]`。
- 位元組表 `4B924C`（模式 7..0x18）：7→case0；0x15→case1；0x17→case2；0x18→case3；其餘（8..0x14、0x16）→case4＝預設，呼叫 `6EDC70("Invalid GameMode %d")`（不返回）。
- case0/2/3：配置 `0xBD54` 位元組物件並呼叫 `4BBB70`（設 vtable＝`Scene::CSquare`，RTTI 名見 bulk）；case2、3 另寫 `[404BA0()+0x69A8]=0x17／0x18`；case0 寫 7。case1：`4ADD50` + vtable `C06F7C`（`Scene::CDuelSquare`，名稱來源 bulk）+ `4BB4A0`。
- 封包位元組 `[data+2]`（有號 byte）＝模式；`4B9260`（模式 1）、`4B9320`（模式 3＝CMissionRoom）為同族函式（【bulk】）。
- 這是 **S→C 的「場景模式切換」處理**，但哪個表 A 索引指向它，`handler_table.json` 內沒有（我先前只解析 `mov [eax+disp],imm` 形式）。→【未知】。
- 對 T09 的意義：Field 類的模式值（8..0x14、0x16）不在這個函式處理，由其他函式負責（【未知】，不在 bulk）。

## 四、進場 C→S 封包（`4BB540`；`4BBC10` 為同型）（【確認】機器碼 `4BB7CF..4BB7FF`）
- 若 `[0xFBA798]==0`：`word [esp+0x14]=0x0043`、`byte [esp+0x16]=bl`、`byte [esp+0x17]=0x0A`，呼叫 `[0xFBA854] vtbl+0x10(0, buf, 4)`＝4 bytes 封包 `{word 0x0043, byte b, byte 0x0A}`。
- `b` 來源：偽碼為 `*(DAT_00fe1aa0+0x18)` 的低 byte（【bulk】）。
- 同函式先前段（【bulk】）：`FUN_00548540(new 0xC0)` 建立 CController 並呼叫其 vtbl+0x24（已知 `CController` 物件大小＝0xC0）；若已存在（`[0xFBA7AC]==2` 走 `544F50`，否則先 vtbl+0x28 再 delete）→ **CController 於進場時重新建立**（【bulk】，建構位址 `548540` 我尚未用機器碼讀）。
- `4B8F50`（【bulk】）：建立 `0xBD8C` 物件（另一種場景）、送 2 bytes `word 0x00F5`。
- 注意：這是命令字 `0x0043`／`0x00F5`，與 `5452C0` 封包的 `0x000A` 不同；沒有證據顯示 `0x0043` 與移動同步有關（【未知】）。

## 五、Ghidra 偽碼可信度備註
- `4BB540` 偽碼把 4 bytes 封包寫成 `CONCAT13(10, CONCAT12((char)x, 0x43))`，與機器碼逐 byte 一致；`4BB4A0` 偽碼與機器碼完全一致。
- 偽碼的 `local_c`／`ExceptionList`／`atexit` 為編譯器產生的例外處理／靜態初始化樣板，與邏輯無關。

## 差異（對 GitHub 既有記錄）
- 新增：表 B 長度＝0xBD5 項；Square／DuelSquare 的表 B 條目；GameMode 模式 7/0x15/0x17/0x18 的處理與其餘為「Invalid GameMode」。
- 無衝突。

## 尚未確認
- Field 類 Scene 的表 B（需 bulk 未涵蓋的建構函式，如 `CScenarioField` 建構內的 `436C40/4C5930` 設定處）。
- `4B9090` 對應的表 A 索引；模式 8..0x14/0x16 由誰處理。
- `4C5C50`（索引 0x1F、0x25）、`4BB990`（0x62）、`4BC050`（0x68）、`4BBFA0`（0x6A）、`4BBAE0`（0x6B）、`424610`（0xA9/0xAB）的功能（皆在 bulk 內，僅部分尚未讀）。

## 建議
- 值得提交：`kr-temp-roy/`。
- 下一步（T09）：用 bulk 的 `4BB990`／`4BBFA0`／`4BC050`／`4BBAE0` 偽碼確認這些表 B 處理是否涉及位置同步；若無，轉向 bulk 未涵蓋的 Field 類表 B（`436C40`、`4C5930`）。
