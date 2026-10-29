# T16-092 — 三個 native function-root 正常控制流 CFG 複驗

建立時間 `2026-10-29T21:44:09.711276+08:00`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

保留歷史原稿：`kr-temp-roy/20261028-204341-chatgpt-web-roy-T16-92-KR-Quest-global-owner-and-real-read-consumers.md`；blob `bd044356f64dd859fe898477d443414a468f4b85`。通知：`T01-RETURN-T16-092-6df3bb2c`。

## 原始根、CFG 與控制流核對

| root | 正常可達指令 | 分支 | 呼叫 | indirect unresolved | decoding overlap / window bound errors |
|---|---:|---:|---:|---:|---:|
| `0x0062E490` | 335 | 43 | 41 | 0 | 0 |
| `0x005B6BE0` | 91 | 7 | 10 | 0 | 0 |
| `0x0062F640` | 90 | 9 | 8 | 0 | 0 |

逐指令、raw bytes、所有正常直接邊與呼叫位址見 `rooted-cfg/root-0062E490.json`、`root-005B6BE0.json`、`root-0062F640.json`；以根為起點，追 conditional/direct jump 分支與正常 fallthrough；call 視為 opaque callee、從返回後繼續。

## 被退回指令及其前後位址（原始 BIN 再核對）

```asm
0x62E5CD: 50                         push eax
0x62E5CE: 8D 45 C8                   lea eax,[ebp-0x38]
0x62E659: 56                         push esi
0x62E65A: E8 71 B8 12 00             call 0x759ED0
0x5B6CCF: 8B 53 14                   mov edx,[ebx+0x14]  ; covers 5B6CD0
0x62F700: C7 45 FC FF FF FF FF       mov dword [ebp-4],-1 ; covers 62F706
0x62F70A: 8B 35 4C 11 FB 00         mov esi,[0xFB114C]
```

- `0x5B6CD0`、`0x62F706` 是有效指令的**內部位元組**，不應單獨當成指令。
- `0x62E5CD`、`0x62E659` 本身確實是指令起點，但舊稿的語義／下一個 call 位址須修正，不能把 push 命名為 call。
- `0x62E490` 裡 `0x62E579` 和 `0x62E5D6` 可達地呼叫 `0x503D20`；`0x5B6BE0` 裡 `0x5B6C86` 是可達 `call 0x503D20`；`0x62F640` 裡 `0x62F719` 可達同一 lookup。上述僅支持**本地 Quest 靜態 owner→查找→讀取者**，不建立 wire opcode 或 Quest 動態結果的結論。

## 本輪可回溯反證及 T01 復驗界線

在三個入口界線內，所有沿正常顯式分支與順序前進的可達位元組均具有唯一指令起點（無 overlap）、直接邊已收錄或合理有界，且全部重建指令的 bytes 與原 BIN raw 逐條一致。未聲稱處理 Windows SEH runtime 的隱式路徑、跨函式 callee、例外、與原版 Server 行為。

本次已修正四個座標及重建三根正常 CFG；**T01 狀態仍 NEEDS_FIX**，未得到 T01 獨立重驗，不自行變更為 READY_FOR_REVIEW 或 RESOLVED。