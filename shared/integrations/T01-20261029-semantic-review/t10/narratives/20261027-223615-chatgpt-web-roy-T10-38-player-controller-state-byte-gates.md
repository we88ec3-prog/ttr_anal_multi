# T10-38 — 控制器 index-5 輸入閘門與狀態更新（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新確認的精確分支
1. 【確認】`0x546338` 對全域 byte `[0xFB9009]` 與零比較後使用 `sete al`，故 `esi = (input_index5 == 0)`。先前僅述「參與分支」；現在已釐清極性：**值為零時通過這一層判斷**，不代表 index 5 即鍵位 V 或 pressed。
2. 【確認】actor 指標 `edi` 的 `[edi+0x158]` 必須非零，且其 `+0x30` 必須非零；`0x4C9ED0(edi)` 需回傳 0；還要 `esi!=0` 才進入 `0x546374`。這四個閘門可獨立列為客戶端真實前置條件。
3. 【確認】`0x546394` 呼叫 `actor.vfunc_60`，結果乘以 `0xC55A70` 的浮點常數，作為 `0x545F30` 第二參數；`0x545F30` 第一參數是 `[ebx+0x4]` BYTE，receiver 是 `actor+0xA0`。屬於具有方向／距離參數的狀態查詢，不可直接命名攻擊施放。
4. 【確認】若 `0x545F30` 回傳 0 且 `[controller+0x74]` 為零，將 actor `+0x3A8` 置零；若非零則 `0x5464C0` 產生下一個 BYTE 結果，存 controller `+0x70`，並設 `[ebx+2]` WORD 的 bit 15。此處的 bit 15 由動作分支進行設/清，並非完整鍵盤 pressed 狀態定義。
5. 【確認】若 controller `+0x70 !=0`，`0x54644E` 呼叫 `0x4C90C0(actor,1)`，而 `0x4C90C0` 操作 actor `+0x3A8`，不操作 `+0x3E8`。這是與 selector=5 setter **不同的已知狀態機**。
6. 【確認】`0x546453` 最終用 actor vfunc `+0x58` 回寫某 byte，並將 controller `+0x74` 歸零，構成此 branch 的狀態收尾。尚無 action ID 或實際 motion queue 證據。
## 條件表
| 條件 | 結果 | 證據 |
|---|---|---|
| `[FB9009] != 0` | 跳出此分支 | 0x546338/36C |
| `[actor+158]==0` 或其 `[+30]==0` | 跳出 | 0x546345/357 |
| `0x4C9ED0(actor)!=0` | 跳出 | 0x54635D/366 |
| direction helper 成功/queue slot 非零 | 呼叫 `0x5464C0` | 0x5463CA..0x54642F |
| controller+70 非零 | 呼叫 `0x4C90C0(actor,1)` | 0x546444..44E |
## 邊界
- 【未知】global input index 5 的 key mapping row 或 action code；不推定 Z/V。
- 【未知】這條方向分支是否被攻擊 controller 共同使用，不據此聲稱取消／接段。
- 後續追 vfunc +0x58/+0x60 實際目標與 `0xFB9009` 非零寫入者。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x5462dd–0x546374
[code block separately checked in preflight]

### VA 0x546374–0x54647a
[code block separately checked in preflight]