# T01 — RR-0008 / E68 選角回覆、ScenarioReview、雙鍵 SceneList：R0–R2 有界驗收

2026-10-30（Asia/Taipei）｜T01 / chatgpt-web roy｜原件 KR。**此為定向原生 R2 + R1 整合，不是 E68 全文 FULL-PASS、RR ACCEPTED、SPEC STABLE 或遊玩成功。**

## 1. R0 來源身份

- 開工 `origin/main`：`bc3b7deeda2fefbbc90cd98e660ca5965ae87d79`，驗收後發布基準以 commit parent 為準。
- 作者原稿：`kr-extra-roy/20261030-chatgpt-web-roy-E68-RR0008-selection42-scenario-review-writer-endcutscene-static-closure.md`，Git blob SHA1 `0af10e12b2247f3cd4493086d282044fae249c31`，原文 UTF-8 SHA256 `4e5ab198626cdb772ffc0ea49d5ae1f428d2f12d6547bbffbb919f061cdf52ec`。此檔已在 main，與 RR-0008 的 `dispatch.submission` 完全相符；**未修改／重排／搬移作者原稿**。
- KR `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe`：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。三份由本次實際上傳原件唯讀重新計算；未執行 Client、附加、修改或取得原版 Server 封包。
- PE header 再核對：image base `0x400000`，`.text` VA/raw `0x401000/0x400`，`.rdata` `0xBD2000/0x7D0600`，`.data` `0xD61000/0x95E800`；VA→raw 各減去 `0x400C00`、`0x401A00`、`0x402800`。

## 2. 獨立 BIN-first R2：指令／CFG／資料流／RTTI

本批於原始 BIN 做 21 個精確 byte-start 比對、兩組 RTTI/COL descriptor、五個 `E8 rel32` direct-target 集合、522-byte Event.stp Lua 解碼檢查。詳細 byte 常數及可重跑斷言在同目錄 [revalidate.py](revalidate.py)。有界交叉反組譯觀察如下：

| 原生 VA / bytes | 肯定結論及條件 | 明確不成立的過度推論 |
| --- | --- | --- |
| `4ADF3D c7 80 14 02 00 00 90 21 4B 00` | base scene table 將 `+0x214` slot 指向 `4B2190`，符合先前 T02 active-scene fallback 的**有條件** S2C app42 handler | 不代表任一時刻必有 active scene、也不證選角 ACK |
| `4B21FD 0f bf 76 02`；`4B2206 e8 05 df 04 00`；`50012B 83 f8 14` | `4B2190` 讀 payload+2 signed WORD，呼叫 `500110` 對 `FAB2A0+0x5ED0` 20-WORD 集合尋找/插入 | 這不是角色授權或選角回覆 status |
| `4B2210 3b fb 0f 86 ae 00 00 00`；`4B221C 0f b6 48 01` | `length>4` 才走 subtype，已保存指標指向 payload+4，再+1 讀 payload+5；`len=5` 不足以覆蓋讀取；不同分支可能要求更多欄位 | 僅靜態短包讀取界線，無 runtime crash / Server exploitation 證據 |
| `47D693 68 a0 b2 fa 00` | ScenarioReview UI 呼叫前推入同一 `FAB2A0`；有 UI consumer | UI 集合與 SceneItem+248 不能視為同個物件 |
| `47B143 c7 86 48 02 00 00 ff ff ff ff`；`47B4C9 89 86 48 02 00 00`；`47B2EF 89 83 48 02 00 00` | ChapterItem/SceneItem ctor 各寫 +248 初始值；`47B2EF` 是來源 [EDI]→Review SceneItem+248 的非初始化 writer | 相同 offset 不表示同類別或來自 S2C42 |
| `C02F3C[-1]→C68ACC→F7D864`；`C02D9C[-1]→C68B30→F7D890` | 原始 RTTI 名稱分別 `CScenarioReviewSceneItem@FUI`、`CScenarioReviewChapterItem@FUI` | RTTI 不會證明 selection-to-tutorial wire |
| `47D558 8b 86 48 02 00 00`；`47D55E 89 87 20 01 00 00` | `47D530` 從 source+248 複製到 dest+120；`47D5AF` 經 `47E890` 取得另一 key，`47D5B7` 呼叫 `47B5C0` | 沒有證據是 S2C42 直接複製 |
| `47B5EB 81 bf 48 02 00 00 61 ea 00 00`，`47B63D 8b 8f 48 02 00 00` | `0xEA61` SceneItem 特別分支可避開 loader；其它條件成立後 `47B64A` 可呼叫 `565720` | 不能推斷 0xEA61 是 wire opcode 或首登 |
| `561ED1 8b 47 3c 8b 4f 38`；`561EE8 3b c3 74 1f` | EndCutScene 由 this+38/+3C 與 `47E640` 更新 key，零值分支不呼叫 loader | 這與 Review +248 owner 不是同一 writer |
| `565756 83 7e 28 00`，`56575D c6 86 89 00 00 00 01` | `565720` 檢查活躍 +28，寫入 +89，具重入門檻 | 呼叫不代表成功載入或首次教學 |
| `4A3B91 b8 42 00 00 00`，`4A3B96 66 89 45 fc 88 4d fe 88 55 ff` | 獨立 C2S builder 的本地 4-byte payload（WORD42 + 兩個 BYTE） | 共用「42」數值不能證 S2C42 為 approval |

逐 byte 在已保存 `.text` 範圍掃描 `E8 rel32` 並於候選指令邊界反組譯：`47B2B0 ← 47D36D`；`47B5C0 ← 47D5B7`；`47D530 ← 47D9DA`；`565720 ← 47B64A、561EF3`；`4B2190` 無 `E8` 直接 caller，但有明確 table pointer。這只是**direct E8 候選範圍**，不包括 virtual、indirect、callback、alias 或動態生存週期；不可據此宣稱全域無 writer。

`Event.stp` header `STPD`；`raw [0xA1C010,0xA1C21A)` XOR `FF` 522 byte Lua SHA256 `1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc`，包含 `Quest #1001 / Scene #1`、`function tutorial_start()` 與 `Register(tutorial_start)`。**這是資源鍵，不是 Server wire 1001/1，也不是新角色進場規則。**

## 3. R1 去重、來源收件與審核

- `SRC-0474` 收件 E68 精確 Git blob，`CONFLICT_CHECKED` 只表示來源範圍與既存 claims 查對；**不是** `SPEC_CONSUMABLE`、`NATIVE_VERIFIED` 或全篇 R3。
- 新 `CLM-SCENE-0005` 僅收錄 S2C42 app handler → `FAB2A0` → Review UI bounded 及 length=5 風險；關聯 `CLM-NET-0031`，**不能**把同號 C2S42 配對成官方 S2C ACK。
- 新 `CLM-SCENE-0006` 收錄 RTTI SceneItem 寫入 `+0x248`、`47D530→47B5C0→565720` 的條件性 Review UI 與 `EA61` 例外，不將其說成選角成功 writer。
- 既有 `CLM-SCENE-0004` 已有雙 caller 限定結論，本次補 E68 作 `additional_sources`，仍保留先前證據級別、不繼承品質、不另創同義 claim。`CLM-SCENE-0001..0003` 的資源和索引也不升格為 wire；`CLM-CHAR-0006` 的 C2S42 local layout 不變。
- 暫無針對 E68 **本批所驗肯定主張**的獨立確定反證，故不新設 T03 `NEEDS_FIX`；既有 T03、T10 退回不變。
- T01 允許 RR-0008 從 `SUBMITTED` 經 append-only event 轉為 `IN_REVIEW`，保留 S00 對完整 RR acceptance criteria 的 `ACCEPTED/NEEDS_REVISION` 決議權。T01 `FULL-PASS`、S00 RR `ACCEPTED`、SPEC `STABLE`、Server 實作、可玩驗收**彼此獨立**。

## 4. 已證界線、影響與下一步

影響/供 S00 查閱：`SPEC-SCENE-0001`、`SPEC-FLOW-0001`、`SPEC-CHAR-0001`；`GAP-SCENE-0001`、`GAP-FLOW-0001`、`GAP-CHAR-0001`。本批**不修改**任何 SPEC DRAFT、GAP OPEN、TEST OFFLINE_SYNTHETIC，亦不新增 `shared/verified-knowledge/`。

- **Client 待逆向**：首入場真正 scene-key 的 producer、所有可能間接/virtual alias 與其他業務命令；選角 C2S42 對應原版 S2C 成功/拒絕 opcode、body、各 Conn 順序。RR-0002 繼續 `BLOCKED`，與本 RR 分離。
- **Server 待開發**：登入後角色/場景授權、回覆與首次教學策略，需按可證 Client 介面設計，不能假稱原版政策。
- **跨功能待整合**：T02 framing/active scene → T03 auth/roster/選角 → T05/T07/T16 scene/tutorial。
- **待遊玩驗證**：無同版 KR 原版成功／失敗封包擷取與 runtime trace，亦未啟動 Client。

本次完成的是 E68 指定主張的**有界 T01 R0–R2 驗收**，不是 E68 每個額外子命令、所有間接鏈或整篇報告的 R3 判決。唯讀重跑：`python -B revalidate.py /path/Tartaros.bin /path/Event.stp`。 
