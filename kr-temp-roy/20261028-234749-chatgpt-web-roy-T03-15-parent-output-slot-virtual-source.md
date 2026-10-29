# T03-15 — KR parent+0x140 receive worker 的上游輸出槽與 vtable+0x48 取得路徑

- 研究者：chatgpt-web roy；日期：2026-10-28 23:47:49 Asia/Taipei。
- 唯讀原始 `/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` raw = VA − `0x400C00`，`.text` VA 0x401000 / raw 0x400。
- 範圍：T03；延續 T03-14 的 worker vtable 來源問題；不執行 Client、Server，不修改 BIN，不把測試封包當原生回覆。
- GitHub 工作分支：`t03/roy/chatgpt-web`。研究前 `main` already ancestor (`behind_by=0`)，因此本次不需要新增 merge commit。

## 摘要與新的重要邊界

**新證實：在 `0x49198A` 呼叫 worker 前，父物件並非於本地直接配置，而是經呼叫前本地輸出槽收取。** 在 `0x4918B6` 和 `0x4918FA` 都有 `mov [esp+0x20],ebx` 初始化；對應分支會透過外部物件 `[...+0x10]` 的 **vtable+0x48** 間接方法取得輸出。之後 `0x49197F mov edi,[esp+0x20]`；`0x491983 lea ebx,[edi+0x140]`；`0x49198A call 0x804740`。這比前一段僅將 `parent+0x140` 命名為未知 caller 指標更進一步：**其直接生產者是外部虛擬方法交付的本地結果，而不是這個接收迴圈的新建物件**。具體 vtable+0x48 target 和實際被回傳的父物件型別依然未知；不得將此宣稱為已解出 `0x80486D` 的業務 callback。

另一支 `0x4918DB` 路徑在虛擬方法後還執行 `0x6D7840` 與輸出槽處理；因缺完整別名與 stack tracking，不直接聲稱兩條分支都必定回傳同一類指標。`0x4918C3..0x4918D3` 在另一條路徑另有外部方法介入，必須保留分支差異。尤其 `0x49197F` 先前可見的 `EDI` 來源是 stack output slot，不能根據 `mov slot,ebx` 初值就斷言永遠為零，因為其地址在此前被 push 傳給間接方法。

## 第一輪：原始 callsite／上游暫存資料流

以下摘錄是本輪從 `objdump -D -M intel --section=.text --start-address=0x491800 --stop-address=0x491a40 Tartaros.bin` 的指令。

```asm
491892: 75 47                 jne 0x4918db
491894: 68 98 58 c0 00        push 0xc05898
4918a0: e8 2b 76 00 00        call 0x498ed0
4918a5: 8b 4c 24 3c           mov ecx,[esp+0x3c]
4918a9: 8b 41 10              mov eax,[ecx+0x10]
4918ac: 83 c4 1c              add esp,0x1c
4918af: 8d 4c 24 14           lea ecx,[esp+0x14]
4918b3: 51                    push ecx
4918b4: 53                    push ebx
4918b5: 53                    push ebx
4918b6: 89 5c 24 20           mov [esp+0x20],ebx
4918ba: 8b 10                 mov edx,[eax]
4918bc: 8b 52 48              mov edx,[edx+0x48]
4918bf: 53                    push ebx
4918c0: 50                    push eax
4918c1: ff d2                 call edx
4918c3: 8b 44 24 14           mov eax,[esp+0x14]
4918c7: 53                    push ebx
4918c8: 53                    push ebx
4918c9: 50                    push eax
4918ca: 53                    push ebx
4918cb: 8d 8c 24 4c 01 00 00  lea ecx,[esp+0x14c]
4918d2: 51                    push ecx
4918d3: ff 15 f4 25 bd 00     call dword ptr [0xbd25f4]
4918d9: eb 40                 jmp 0x49191b
4918db: 68 dc 58 c0 00        push 0xc058dc
4918e4: e8 a7 04 f7 ff        call 0x401d90
4918e9: 8b 74 24 3c           mov esi,[esp+0x3c]
4918ed: 8b 46 10              mov eax,[esi+0x10]
4918f0: 83 c4 1c              add esp,0x1c
4918f3: 8d 54 24 14           lea edx,[esp+0x14]
4918f7: 52                    push edx
4918f8: 53                    push ebx
4918f9: 53                    push ebx
4918fa: 89 5c 24 20           mov [esp+0x20],ebx
4918fe: 8b 08                 mov ecx,[eax]
491900: 53                    push ebx
491901: 50                    push eax
491902: 8b 41 48              mov eax,[ecx+0x48]
491905: ff d0                 call eax
491907: 8b 54 24 14           mov edx,[esp+0x14]
49190b: 8d 4c 24 34           lea ecx,[esp+0x34]
49190f: 51                    push ecx
491910: 8b 4e 10              mov ecx,[esi+0x10]
491913: e8 28 5f 24 00        call 0x6d7840
491918: 83 c4 04              add esp,0x4
49191b: 8b 44 24 14           mov eax,[esp+0x14]
49191f: 3b c3                 cmp eax,ebx
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
```

**限定推論**：不同 `esp` 時刻的 stack slot offset 必須依 push/cleanup 重新建模。以上指令證明 `0x49197F` 讀取一個上游呼叫期間可能更新的槽及後續 `+0x140` 取址；不能僅憑此片段絕對確認 `0x4918B3` 的輸出參數與 `0x49197F` 槽是完全相同實體的全部路徑。這仍是下一輪精確 stack SSA 的工作。

## 第二輪：直接呼叫反向引用與非一般入口的否證

對 `.text` raw byte（VA 起點 0x401000）掃描 `E8 rel32` target，得到：

| 查詢目標 | 直接 E8 xref |
|---|---|
| `0x48BE50` | 0 |
| `0x49198A`（指令中間位址，非函式入口） | 0 |
| `0x48C0E6`（函式內部位址） | 0 |
| `0x804740` | 1：`0x49198A` |

這只是**直接 E8 編碼模式的範圍否證**；不能排除 `FF /2` 間接 call、函式指標、註冊 callback 或非標準入口。由於 `0x48BE50` 內原始 `0x48BE90: mov ebx,[ebp+8]`，它消費外部物件，且此輪未見直接 `E8` caller，因此尚無根據將它視為父物件 constructor。回溯應改查其函式指標註冊和虛擬方法實作。

## 第三輪：初始化與持續生命週期交叉驗證

```asm
48c0e0: 8d bb 40 01 00 00     lea edi,[ebx+0x140]
48c0e6: e8 65 85 37 00        call 0x804650
8046d7: 6a 5c                 push 0x5c
8046d9: e8 8a cb 08 00        call 0x891268
8046f7: c7 06 48 17 c5 00     mov [esi],0xc51748
80470f: 89 0d 54 a8 fb 00     mov [0xfba854],ecx
804768: 8b 5d 08              mov ebx,[ebp+8]
804858: 8b 13                 mov edx,[ebx]
80485a: 8b 12                 mov edx,[edx]
80486d: ff d2                 call edx
```

`0xC51748` 寫入 `ESI`（新配置的傳輸物件），不是 `parent+0x140` 的第一 DWORD。上一段已核此邊界；本段的新貢獻是可回溯父物件從虛擬方法/輸出槽流入接收 worker 的上游接口。`0x80486D` 的真正虛擬 target 仍然未知。此輪沒有對虛擬 `+0x48` 實作做定位，沒有偽造函式位址。

## 玩家情境與工程缺口

| 情境 | 已證實 Client 邊界 | 仍未證實 | 分類 |
|---|---|---|---|
| 玩家確認選角 | T03-3 原生 command `42 00 XX YY` 的本地 gate／建構；T03-4..6 共用傳輸 | 原版 S→C 選角回覆 opcode、長度、分派 handler | Client 待逆向 |
| 接收經封裝的資料 | T03-7..9 解框/兩 lane／FC10D0 reader；T03-12 回收 | 接收 worker 具體 `vtable+0` 目標及選角業務分類 | Client 待逆向 |
| 虛擬 source 取得父物件 | 本段 `vtable+0x48` 間接調用／output slot → `parent+0x140` | 物件身分、上游實作及引用/生命週期全貌 | Client 待逆向 |
| Server 規則／角色保存 | 不推測原版規則 | 相容 Server 須依 Client 真實介面實作，細節待確認 | Server 待開發 |
| 選角進入世界 | T05 另管場景切換，T03 需提供確認結果交界 | 未證明 S→C 造成轉場 | 跨功能待整合；待遊玩驗證 |

## 三輪結果與下一段

- **T03-15 第1輪**：從原始 `0x491800..0x491A40` 得到兩條 `vtable+0x48` 取資料與本地 output slot 相關路徑，以及共同 `0x49197F→0x491983→0x49198A` 交接。這是與 T03-14 相比的新上游來源介面。
- **T03-15-2 第2輪**：以原始 `.text` direct rel32 掃描檢驗函式是否存在直接 caller，界定 `0x48BE50` 的間接入口未解、`0x804740` 僅一個直接 caller。
- **T03-15-3 第3輪**：核對 `0x804650` 獨立傳輸 vtable 與 worker 解碼/dispatch 後續，避免把兩者混同；保留回呼實作缺口。
- **停止理由**：第一手原生機器碼找到有界的新上游資料交付介面，並完成三輪的分支／誤認排除；未達完整選角回包或 vtable 實作驗收。
- **T03-16 優先**：從 `0x4918A5`／`0x4918E9` 取得的對象 `+0x10` 與 virtual `+0x48` 作反向 vtable / constructor 查找；精確分析 output slot 和 `0x6D7840` 的 ownership，辨認真正傳入 `0x49197F` 的指標及其 worker vtable。再由 callback 對應選角業務回覆，不猜測 `42→43/69`。