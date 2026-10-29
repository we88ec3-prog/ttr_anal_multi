# T10 原稿逐版本語意審核：第一個已保存檢查點

日期：2026-10-29 Asia/Taipei。審核者：Codex T01 / review_t10。凍結 main `a4d58fd21dd40cfd5cc645a829e52e59b23cecaa`。

本檢查點不是 98 篇全文 FULL-PASS。98 篇來源均已完整讀取並作前置地址／byte 核對（13,689 個 quoted ASM rows 全部與原件相符），核心論述已逐篇整理閱讀；但完整型別、所有偽碼與被呼叫者語意尚未全部閉合。不能將下述 47 份 CFG 或 40 個指令斷言計為 98 篇通過。

原件：KR `E:/Tartaros/workspace/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。讀取 PE headers 取得每節 mapping，沒有套用 flat 假設。沒有執行／附加遊戲、呼叫目標 API 或修改原件。

## 已證實的原稿錯誤與修正提案

### T01-RETURN-T10-007-001 — NEEDS_FIX

- 原稿：`kr-temp-roy/T10/20261027-191139-chatgpt-web-roy-T10-7-runtime-input-merge.md`，原稿 blob／SHA256 見 `decisions.json`。
- 原文：`於 0x5467F1 將 EBX 寫入 caller 提供的 WORD 指標`。
- 反證：`0x5467F1 = 8B 55 10` 是 `mov edx,[ebp+0x10]`，載入輸出指標；真正 store 在 `0x5467F4 = 66 89 1A`，`mov word [edx],bx`。兩者均位於從 `0x546780` 入口遞迴解碼的可達正常路徑。
- 影響：這是指令定位錯誤，輸出 Word、三路 OR 與 byte 優先選擇的主要資料流仍有支持。不能將錯位地址直接重用作 hook／標註或把原稿判為無瑕疵全文通過。
- 修正：保留原稿，勘誤輸出 pointer-load/store 的地址；重新核對相鄰參數與所有偽碼對照，提交新版 blob SHA。
- 複驗條件：新版明列 pointer load `5467F1` 與 store `5467F4`，仍保留 2/3/4→8/80/40、三路回傳 OR 與獨立 byte 優先選擇；未新增 Z/V 語意。

### T01-RETURN-T10-026-001 — NEEDS_FIX

- 原稿：`kr-temp-roy/T10/20261027-205931-chatgpt-web-roy-T10-26-subai-cast-state-machine.md`。
- 原文：`0x549D54 位於 0x549980 起始的 SubAI condition helper，其 0x549E04 ret 0x10 結束`。
- 反證：從 `0x549980` 入口追控制流，正常返回在 `0x549A34`、`0x549C4E`，均是 `C2 10 00`；`0x549C60 = 55 8B EC 83 E4 F8` 為獨立序言。`0x549D54 = E8 17 55 00 00` → `0x54F270` 屬 `0x549C60` 可達本體，不能跨獨立入口歸入前函式。
- 影響：錯誤函式歸屬會污染 caller/callee、參數回溯及 state=4 的寫入者歸屬。`549D54` 後的局部 state=4 寫入不因此消失，但必須由正確入口重新核對。
- 修正：保留舊稿，把兩個獨立入口、各實參及返回分開；重新核對 `549C60`、`549E10` 之間的 slot 讀寫，而非僅改標題。T10-31 對 `549C60` 的後續分析可作交叉線索，不能自動抹除舊版錯誤。
- 複驗條件：新版 blob、完整相關 CFG、正確 caller/argument provenance 與所有受影響主張。

### T01-RETURN-T10-063-001 — NEEDS_FIX

- 原稿：`kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-063-indexed-reset-list-partition.md`。
- 原文：`不在該區間而且 esi <=0x27 的路徑則於 0x6D4CAE 寫 byte [esi+0xFB9004]=0`。
- 反證：`0x6D4C23` 算 `ESI-0x2711`；`0x6D4C29` 比較 `0x270E`；`0x6D4C2F = 77 51` 直接跳 `0x6D4C82`。後者僅有 lazy-init gate／初始化呼叫，正常返回後到 `0x6D4CAE = C6 86 04 90 FB 00 00` 執行 indexed zero store。這條路徑沒有 `ESI<=0x27` 的範圍檢查。完整 loop `6D4C20..6D4CD1` 已展開；`6D4C20` 是前函式內部 loop，不是新的獨立函式序言。
- 對照：`0x6D4CE0` reader 的普通域確有 `ESI<=0x27` guard，但這是另一條讀取路徑，不能搬入 clear loop。T10-13 正確提醒兩者 guard 不同。
- 影響：原稿的 clear 範圍保護敘述錯誤，不能用來證明此 loop 對任意輸入 ID 皆安全。這不是發現遊戲可利用漏洞：上游 list ID 值域仍未證明。
- 修正：移除捏造的本地 guard，回追 list producer 的值域；區分「指令無 guard」與「合法 caller invariant」。禁止把 reader guard 當成 writer guard。
- 複驗條件：新版來源 SHA／blob、完整 clear loop CFG、上游 ID 範圍證據或明示尚未證明；仍不得推測 keyup／Z/V。

### T01-RETURN-T10-062-001 — NEEDS_FIX

- 原稿：`kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-062-lifecycle-reset-dual-branch.md`。
- 原文：第一支「透過 0xFB7C14 與 0xFDF3EC gate 決定呼叫 0x6D0750 或 0x6D1DA0；然後於 0x6D4A9C..0x6D4AC9 清除」。
- 反證：第一支可先依 `FB7C14` 呼叫 `6D0750`；但 `0x6D4A95` 僅測試 `FDF3EC` 並留下 flags，`6D4A9C..6D4AC9` 先清普通 40 bytes。`0x6D4ACE` 才依該 flags 選擇分支，未初始化時 `0x6D4AD9 = E8 C2 D2 FF FF` 呼叫 `6D1DA0`，最後 `6D4AF3` 呼叫 `823850` 清特殊樹。故特殊域初始化不在普通清零之前。
- 影響：清零而非非零 producer 的主旨仍成立；但初始化／普通清零／特殊樹清空的時序不能依原文重建。
- 修正：分開 `FB7C14` 與 `FDF3EC` gate，按實際可達順序列出每條分支，重驗例外／初始化失敗的影響；保留原稿並提供新版 blob SHA。
- 複驗條件：新版精確展示普通 store → 可選特殊初始化 → 特殊樹 clear，且不將 reset selector 命名為 keydown/keyup。

## 使用者要求的階段性收尾

本次停止擴新篇。最終統計以 `decisions.json` 為準：98 個精確來源版本；原稿全文 certified **0**；原版被原生反證否定 **4**；其餘來源 **94 PARTIAL**。其中 **11 個來源**具有 **14 條**已完成的限定主張 FULL-PASS；不能將 11 個來源或 14 條主張報成 11 篇全文通過。

每篇都列出 code block 的來源行號、內容 SHA 與未簽核狀態。`all_affirmative_claims_reviewed=false`、`source_whole_document_certified=false` 全數保留。T10-053/055/056 的附錄存在需由真實 CFG 校正的視窗起點；其來源 caveat 與每條肯定主張仍需逐項裁決，沒有因局部事實通過就簽核整份附錄。

## 可重現產物

- `inspect_sources.py`：讀取所有 98 篇精確 SHA，逐項核對 quoted ASM row 的原始 bytes；不會提升語意狀態。
- `preflight.json`：98 篇來源 SHA256／blob、所有 13,689 個 byte row、來源行號與解碼。byte 一致不能排除敘述錯誤，上列四例就是反證。
- `verify_semantics.py`、`semantic-anchors.json`：PE identity、40 個人工選定的指令／分支／資料流錨點、direct-E8 與 literal census、兩份 XML 原件解析。
- `cfg/*.json`：47 個從已選入口遞迴展開的 reachable instruction/branch graph。間接跳表、EH、called procedure 不會自動展開；這些限制逐份保留。
- `narratives/`：全文分析時使用的去除 code block 閱讀視圖；來源原稿仍為權威。偽碼 block 不能靠這個視圖當成已審。
- `decisions.json`：目前逐篇決議與剩餘工作，PENDING/PARTIAL 不冒充 FULL_PASS。

整合者已將 helper 保存至同批 `support/audit.py` 並改為相對 import，實際40錨點重跑通過。重現仍需原件及Capstone5.0.6；這不是無原件的語意驗證包。
