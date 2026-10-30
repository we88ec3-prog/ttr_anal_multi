# CK-CLIENT-SCRIPT-REGISTRATION-ZERO-STUB-01 — KR Client 0x008DC2F0 零回傳入口

**判定**：T01 `FULL-PASS`，**僅限本頁列明的三位元組／單一正常入口**；不是原始 QA 報告 FULL-PASS、72 個腳本 API、整體 VM 或 111,054 個反編譯函式驗收。

## 精確主張

在原始 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 中，從 `VA 0x008DC2F0` 以正常 32-bit x86 執行時，先執行 `xor eax,eax`，接著執行 `ret`。正常返回時 `EAX=0`，本函式本體沒有顯式資料記憶體寫入、未讀取參數，沒有任何直接或間接呼叫／條件分支。

```asm
008DC2F0  33 C0    xor eax, eax
008DC2F2  C3       ret
008DC2F3  CC       int3  ; following padding, NOT reached via normal entry
```

原始 PE：ImageBase=0x00400000，.text RVA=0x1000/raw=0x400，故 .text VA→raw=`VA−0x400C00`；入口 raw=`0x004DB6F0`，三個 byte `33 C0 C3` 與後續 `CC` padding 直接在原件確認。CFG 是一個 basic block、正常直接返回。**精確注意**：`ret` 必須讀取 stack 返回位址、增加 ESP；不能說「沒有任何記憶體讀取」或「所有 CPU state 不變」（`xor` 改旗標）。

## 上下游、反例與限制

從 `0x0055D7E0..0x0055E410` 這個直接列舉的 source 範圍，在原始 BIN 找到 72 次 `6A 00 68 F0 C2 8D 00`（`push 0; push 0x8DC2F0`）；`0x0055D7F7` 第一處 `call 0x006F55B0`。這只表明 72 個註冊呼叫點**使用同一個函式指標初始值**，**不是 72 次執行該 stub 的 runtime trace**。是否被 VM 重綁、表中的 closure 如何呼叫、具體遊戲 API 功能、Rebind/DeleteAllObject 的間接指標仍待完整原生及執行期審查。

反例限制：不能把零回傳入口推廣為 caller 無副作用；不得推廣到非入口中途跳入、runtime patch/hook、自我修改、非正常 stack/exception 或另一版本；不能由此確認任何原版 Server 回覆或玩家可玩。

## T01 審核資料

- **Reviewer**：T01／ChatGPT web；**日期**：2026-10-31（Asia/Taipei）
- **來源原稿**：`shared/reviews/KR-BULK-CENTRAL-QA-ROUND-16-20261029.md`，Git blob `a23bb7078fbe7d617f95f3f1a3d5efda3982e5c2`，原稿仍保留 `FULL-PASS CANDIDATE` 歷史標記。
- **相關 source**：第 14 輪完整 72 項 native string pointer JSON，Git blob `0c4b6f7f64fa16568a90cc33873317f12556886e`。
- **精確 CLM**：`CLM-CLIENT-0063`，`NATIVE_VERIFIED`（本項限定）；72 個名稱和註冊只 `CLM-CLIENT-0064 PARTIAL`。
- **獨立驗證**：核對原件完整 SHA、PE section table、3-byte CFG、72 個 callsite push immediate、72 對 EDI/rdata 指標以及原始 round16 的限界聲明；詳 [T01 完整裁決](../../research/handoffs/t01-20261031-extra-roy2-qa/README.md) 和 [可重跑驗證器](../../research/handoffs/t01-20261031-extra-roy2-qa/revalidate.py)。
- **Server 待開發**：本 stub 無直接 wire／Server 需求。
- **跨功能待整合**：Script／Lua／UI／Quest 的介面查找可引用本精確事實，不把 72 字串名當功能實作。
- **待遊玩驗證**：無動態執行／原版 Server 封包／使用者場景測試。

**最終判決：**`FULL_PASS_CLAIM_SCOPED`，只涵蓋 entry 0x008DC2F0→EAX=0/ret；其餘 QA 待 R1/R2/R3。
