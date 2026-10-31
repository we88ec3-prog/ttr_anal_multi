# E83 勘誤：E82 的 key0 C2S `0x0001 +37..56` 不是固定零

> 與 RR-0003 登入回覆→key0 首包來源補證共同完成。原 E82 報告（已在 main）保留且不覆寫；本勘誤指明原始 BIN 反證、修正後 Byte layout、T01/S00 需要的處理。KR SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；2026-11-01。

## 先前錯誤與真正後續 writer

E82（`kr-extra-roy/20261101-chatgpt-web-roy-E82-RR0001-key0-first-local-payload-byte-layout-and-frame-boundaries.md`，blob `17a86569f1f076ffe69baf00cdb5b76c5aa50b83`）第2節把 57-byte payload **`+37..56` 說成送出時固定零**。原始機器碼 `4958A4..4958B0` 確實先 5 次清零，共20B；但這是暫存初始化，後續 `4958D9..4958EC` 在 `49593D` enqueue 前覆寫同一位置：

```asm
4958A4 89 45 E5                mov [ebp-1Bh],eax    ; EAX=0, payload+37..40
4958A7 89 45 E9                mov [ebp-17h],eax
4958AA 89 45 ED                mov [ebp-13h],eax
4958AD 89 45 F1                mov [ebp-0Fh],eax
4958B0 89 45 F5                mov [ebp-0Bh],eax
4958D9 E8 C2 F2 F6 FF          call 404BA0         ; Client owner getter
4958DE 6A 0A                   push 10             ; source count WCHAR
4958E0 05 FA 67 00 00          add eax,67FAh       ; second WCHAR source
4958E5 50                      push eax
4958E6 8D 4D E5                lea ecx,[ebp-1Bh] ; destination payload+37
4958E9 6A 0A                   push 10             ; dest capacity WCHAR
4958EB 51                      push ecx
4958EC E8 0D E7 3F 00          call 893FFE        ; bounded WCHAR copy
495935 6A 39                   push 57
49593D FF D2                   call edx           ; manager queue slot0
```

## 更正後 57-byte application payload 欄位

| +offset | 長度 | 來源（有界） |
| --- | ---: | --- |
| +0 | 2 | opcode LE16 `0x0001` |
| +2 | 4 | 共享 Client owner `+0x67E0`，由 S2C0x0013 `+0x18` 成功 writer 設定 |
| +6 | 20 | 共享 Client owner `+0x67E4`，自 S2C0x0013 `+2` 成功 name copy，於此再做 10-WCHAR bounded copy |
| +26 | 1 | 1 |
| +27 | 1 | owner `+0x6898`，來自 S2C0x13 `+0x86` |
| +28 | 5 | owner `+0x6899`，來自 S2C0x13 `+0x87` 的 narrow capped string |
| +33 | 4 | owner `+0x68A0`，來自 S2C0x13 `+0x8C` |
| **+37** | **20** | **owner `+0x67FA`，第二 10-WCHAR capped copy；內容 UNKNOWN，絕非已證固定零** |

### 真實限制／更正建議

- 原 E82 verifier 只驗 `4958A4..B0` 的初始化指令，**漏驗後續 `4958D9..EC` 的第二 copy**；其「74 項 byte tests PASS」不會建立完整末態語意。E83 verifier 增加此後續 writer、call target/目的堆疊位址/不變 source 寬度的專項斷言。
- `.text` 搜尋 little-endian DWORD `FA 67 00 00` 只見 `0x4958E1`（唯一 direct displacement site）；**不排除**其它 computed-offset/字串初始化 writer，不能從此判斷 source 全零。
- 請 T01 對 E82 的 `+37..56 fixed zero` 標記此勘誤與 R2 重新核對；請 S00 修訂 `C04-E1` / key0 首包解析規格，禁止 Server 把這20B 寫死零或以其非零當作無效封包。
- 原始 E82 檔案保留 Git 歷史；只以本勘誤和 RR3 E83 報告新增交付。原版 Server 內部 policy 不是本勘誤研究目標。
