# KR Bulk 集中品質檢查 — 第十四段（2026-10-29）

**狀態：PARTIAL / DIRECT BIN DATA + CALLBACK / NOT FULL-PASS**

## 1. 第一手原件與方法

原始 `Tartaros.bin`（本地唯讀），實算 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32 x86，ImageBase `0x00400000`；`.text` RVA `0x1000`、raw `0x400`；`.rdata` RVA `0x7D2000`、raw `0x7D0600`。

關鍵：**不同 section 的 VA→raw 換算不同**。對 `.text` 是 `raw=VA-0x00400C00`；對 `.rdata` 是 `raw=VA-0x00401A00`。上一段未真正解碼 72 個 EDI 指向的內容；若誤用 .text 映射將得到無意義位元組。本段已按 .rdata 真正映射取得 NUL 結尾字串。

用 `objdump -D -b binary -m i386 -M intel` 對 `0x0055D7E0–0x0055E2D1` 的原始 .text bytes 反組譯，擷取 72 個 `BF imm32`（`mov edi,imm32`）及其 NUL 結尾 .rdata 字串。72 個 VA 均不同，72 個字串名稱均不同。函式 `0x008DC2F0` 的 `.text` 入口另獨立反組譯。

## 2. 72 個原生字串名稱（依實際指令順序）

01. `wait`
02. `yield`
03. `OnYesTriggered`
04. `OnNoTriggered`
05. `OnNextTalk`
06. `PrologCloseCallback`
07. `OnEndTalk`
08. `WaitForScene`
09. `WaitForCamera`
10. `WaitForProlog`
11. `WaitForBook`
12. `PlayCameraNoWait`
13. `PlayCamera`
14. `SkipCamera`
15. `OpenTalkScene`
16. `OpenAutoTalkScene`
17. `CheckConfirmMessage`
18. `WaitAndCheckConfirmMessage`
19. `StopMusic`
20. `StopMusicWithFadeOut`
21. `WaitForObjectsStop`
22. `ConvSpeedStepToMultiplier`
23. `WalkObject`
24. `WarpObject`
25. `RotateObject`
26. `AniObject`
27. `AniSkip`
28. `SpeedObject`
29. `ShowObject`
30. `FaceObject`
31. `FlashObject`
32. `StopObject`
33. `ClearObjects`
34. `Transition`
35. `FlyingObject`
36. `DelFlyingObject`
37. `StartLoading`
38. `EndLoading`
39. `AttachCamera`
40. `DetachCamera`
41. `MoveCamera`
42. `RotCamera`
43. `DoProlog`
44. `PlaySound`
45. `PlayTalkSound`
46. `FadeOut`
47. `FadeIn`
48. `FadeColor`
49. `CameraEffect`
50. `Book`
51. `Dialogue`
52. `BalloonTalk`
53. `BurstStruck`
54. `NumberPanel`
55. `Sepia`
56. `SlowMotion`
57. `LoadMap`
58. `RestoreMap`
59. `CreateObject`
60. `SetTransitionType`
61. `SetFinalMusic`
62. `HideOriginalObjs`
63. `AllowPoisonForestRaidHack`
64. `Phase1`
65. `Phase2`
66. `Phase3`
67. `Phase4`
68. `RevPhase4`
69. `RevPhase3`
70. `RevPhase2`
71. `RevPhase1`
72. `Register`

重點群組僅為分析者索引，**不是原程式已證實的正式模組分組**：

- 協程／對話：`wait`、`yield`、`OnYesTriggered`、`OnNoTriggered`、`OnNextTalk`、`WaitForScene`、`OpenTalkScene`、`Dialogue`。
- 物件／場景：`WalkObject`、`WarpObject`、`RotateObject`、`AniObject`、`ShowObject`、`CreateObject`、`LoadMap`、`RestoreMap`。
- 鏡頭／聲音：`PlayCamera`、`SkipCamera`、`AttachCamera`、`MoveCamera`、`PlaySound`、`FadeOut`。
- 流程階段：`Phase1`–`Phase4`、`RevPhase4`–`RevPhase1`。
- 特殊字串：`AllowPoisonForestRaidHack`。名稱本身僅能證實此字串存在，不能推論其實際安全性／遊戲用途。

## 3. 具體位址證據

| index | MOV EDI 指令 VA | EDI = .rdata VA | 已驗證字串 |
|---|---|---|---|
| 1 | `0x0055D7FE` | `0x00C1027C` | `wait` |
| 2 | `0x0055D824` | `0x00C10284` | `yield` |
| 3 | `0x0055D84A` | `0x00C0DD40` | `OnYesTriggered` |
| 4 | `0x0055D870` | `0x00C0DD50` | `OnNoTriggered` |
| 5 | `0x0055D896` | `0x00C1028C` | `OnNextTalk` |
| 57 | `0x0055E063` | `0x00C1054C` | `LoadMap` |
| 58 | `0x0055E089` | `0x00C10554` | `RestoreMap` |
| 63 | `0x0055E147` | `0x00C10598` | `AllowPoisonForestRaidHack` |
| 64 | `0x0055E16E` | `0x00C105B4` | `Phase1` |
| 71 | `0x0055E27A` | `0x00C105F8` | `RevPhase1` |
| 72 | `0x0055E2A1` | `0x00C10264` | `Register` |

**完整 72 筆 `mov_va → string_va → 原始字串`** 存在同批次 JSON，供各 Task 依地址或名稱查詢。

## 4. `0x008DC2F0` 原生函式

原生 VA `0x008DC2F0`、.text raw `0x004DB6F0`（按 .text section 公式）。直接位元組：

```asm
008DC2F0  33 C0    xor eax,eax
008DC2F2  C3       ret
008DC2F3  CC       int3
```

`EAX=0` 後立即返回，是 **無條件回傳零的短 stub**，本函式自身沒有副作用。前段中反覆 `push 0x008DC2F0`、`push 0` 然後 `call 0x006F55B0`，已可證實 72 組名稱在該呼叫位址都搭配**相同的 callback pointer**，不是 72 個獨立遊戲功能實作。

## 5. 關鍵的舊假設修正

原來從 `FUN_0055D7E0` 的大量 closure-like 建立，容易猜測 72 個名稱直接綁到各自功能不同的 C callback。**本段原始 bytes 反證了這種解讀**：在已觀察的呼叫參數中，每次都是 `0x008DC2F0`，而該函式只 `xor eax,eax; ret`。因此實際可能是 API 名稱預登錄、腳本替換用占位函式、轉接路徑或其他機制；這幾種**均未驗證**，不得擇一寫成確定的原版架構。

`0x0055E410` / `0x0055E4F0` 仍以其他 callback-like 目標處理 `Rebind`、`DeleteAllObject` 等字串，應與 72 個同源 stub 註冊分別研究。

## 6. 跨 Task 狀態與下一步

- **Client 待逆向**：註冊表的實際用途、72 個名稱何時由 stub 替換或被解譯器呼叫、`0x00FE1EF0` 初始化與生命週期、`0x006F5790` 完整 settable 路徑。可搜尋 `0x008DC2F0` 的其他 xrefs 及 `0x00C1027C` 等字串讀取位置。
- **Server 待開發**：本段沒有新增任何已確認的 Client wire contract，不增列 Server 義務。
- **跨功能待整合**：物件、劇情、鏡頭、場景、音效等 Task 可用此字串索引，但不能將名稱本身當功能已還原。
- **待遊玩驗證**：未執行原遊戲或動態腳本。
- **FULL-PASS**：仍為 PARTIAL；完整 bulk `index.jsonl → functions → raw` 111054 筆 hash 核對仍未完成。

## 7. 輪次

第 1 輪取得完整 72 個真實字串鍵及共同 stub 原生行為，構成重大新發現；本段第 2、3 輪均未啟動。
