# T01 — 合併 T16 工作分支並限定原生複核（2026-10-31，KR）

## 目標與 Git 合併身份

- Repository: `we88ec3-prog/ttr_anal_multi`; T01 工作目標固定 `main`；來源分支 `t16/roy/chatgpt-web`。
- 合併前 main: `ca265c5b9ee49e29b2138eabd5edf52e477148e5`；T16 branch: `a0ebcef7ebfb8a5cb6460360b95eca231423804b`；比較：`diverged`，ahead `13`、behind `426`（只代表歷史，不代表所有來源內容未進 main）。
- 採真正 **雙父 Merge Commit**：第一父為上述 main，第二父為 T16 HEAD；合併樹以主線為基底，只加入主線缺少的 T16-134 來源及本 T01 收件紀錄。未改動 T16 分支、來源原稿及其他 Task。
- **README 衝突裁決**：保留 `main` 的 `kr/tasks/T16/README.md`，不採來源分支落後的 `READY_FOR_REVIEW` 版本。固定通知 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 在 main 已由 T01 於 2026-10-30 限定複驗為 `RESOLVED`，不得倒退；此結案仍非全文 FULL-PASS。

## R0 來源逐檔比對與去重

本次分支比較列出的 T16-126～133 八篇、Quest16 補充與 T16-117 作者勘誤，**共十份文件均已存在於合併前 main，且逐檔 Git blob SHA 完全一致**；它們已有 `research/handoffs/t01-20261030-t16-quest15-quest16-bounded/README.md` 與 `SRC-0483～0492` 的限定收件／主張登錄。此次**不重複新增或覆寫**既有來源／SRC／CLM；歷史結論保持原狀。

**唯一新增 T16 技術原稿**：
- `kr-temp-roy/20261031-154318-chatgpt-web-roy-T16-134-KR-Quest15-C2S-S2C-scene-trigger-causality.md`
- 來源 Git blob SHA: `991fa3fbbb89622e264eaceb138725d597629e28`；來源 UTF-8 SHA256: `d66008c474d2d598edfa7a63c6dc9d0199f5bd772efc2156c69cbec4e441360f`。
- 收件項：`SRC-0590`；目前僅 `REGISTERED`，沒有自動產生 `CLM-*`、`NATIVE_VERIFIED` 或全文 `FULL-PASS`。
- 本稿與前段 T16-126～133 的有界結論相互補強，但完整 upstream/downstream、alias、原版 Server wire/ACK、實際 Table SceneList row 和真實場景執行仍有必要界線。

## 第一手核對：靜態原件與限定 R2

本輪用上傳的實體原件唯讀核對：
- `Tartaros.bin`：12,472,320 B，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- `Tartaros.exe`：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- `Event.stp`：11,241,597 B，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`
- `Table.stp`：5,248,784 B，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`
- PE32/.text VA `0x401000` / raw `0x400`，故 .text raw=VA−`0x400C00`；.rdata VA `0xBD2000` / raw `0x7D0600`。

經本次獨立 `objdump -D -Mintel` 檢驗的**限定指令起點與原始 bytes**：

| VA | 原始 bytes 及指令語義 | 本輪可證界線 |
| --- | --- | --- |
| `0x422F8E` | `B8 C0 73 FB 00` = `mov eax,0xFB73C0` | `0x422F40` accessor 的回傳指標，不是把 stack args 自動換算成 Quest/scene tuple |
| `0x503095` | `8B 45 08 0F BF 48 04 0F BF 50 02` | application input +4 與 +2 的 **signed WORD**（`movsx`），隨後 push 引數、`ECX=0xFB73C0` 呼叫 `0x561760` |
| `0x636DF8` | `81 7E 10 02 44 0F 00 75 05` | `[ESI+0x10]==0xF4402` 才能走本條 `0x636E10` 路徑 |
| `0x636E7C` | `8B 8F 88 00 00 00 66 8B 11` | `+0x88` 是先取指標後 dereference WORD；不能將該指標本身當 QuestID |
| `0x4B353E` | `66 8B 51 02 B8 36 00 00 00` | 存在另一條獨立 application `0x36` payload producer，來源為 input+2 WORD |
| `0x636BD6` | `83 F8 01 0F 85 A5 00 00 00` | mode==1 受限的 F4402 路徑，mode2 不可無條件套用 |

以上只是明確限定的 first-hand static cross-check，不涵蓋原稿 1551 行全部主張與 every CFG edge。T16-134 把 `0x46`、`0x45`、`0x40`、`0x47` 與 Scene3 間的條件、不等價性區分，方向與既存 T01 部分驗證相容；不得把人工輸入 `0x47(15,3)` 視為原版抓包或認定 Quest15 完成一定執行 Scene3。

## 待驗收工作分類

- **Client 待逆向**：Quest15 真實 QuestInfo action descriptor、Table/SceneList chapter/scene rows、獨立 C2S/ S2C pairing，scene controller deferred callback／重入及 NPC/UI 的完整來源。
- **Server 待開發**：Quest 接受／完成／拒絕／獎勵／進度保存、Server 對應的實際業務策略；不可聲稱是原版 Server 演算法。
- **跨功能待整合**：T02 socket/framing、T07 場景、T14 結算與 T15 保存相依。
- **待遊玩驗證**：真實輸入、封包順序、場景演出與進度持久化。
- 既有 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 的 `RESOLVED`、舊 `CLM-QUEST-0007 REFUTED` 及全部歷史 FULL-PASS 判決**不更動**。

**本次 T01 判定**：Git 來源整合與 R0 身分查核可完成，六處限定 BIN bytes/指令驗證成立；T16-134 **尚無 R3/FULL-PASS**，來源可供後續 R1/R2 提取／查核，但不得直接升格 S00 STABLE 或可玩驗收。
