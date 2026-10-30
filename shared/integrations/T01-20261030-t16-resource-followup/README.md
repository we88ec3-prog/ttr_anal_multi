# T01 第二輪：KR T16 TutorialBase source recovery、隊列 gate 與 callback 原始反證重審

審核日期：2026-10-30（Asia/Taipei）。基準 main `075411db2978b17c864ec4df6694126d306c8351`；版別 KR；T16 作者勘誤仍留在 `t16/roy/chatgpt-web`，**本輪沒有合併其分支或改寫原作者原稿**。

**這一輪額外解除 16 筆精確通知；總計 43 筆中 27 筆 `RESOLVED`、16 筆 `READY_FOR_REVIEW`。** 先前 11 筆的裁決原文留於 [上一批](../T01-20261030-t16-followup/README.md)。本次不是 T16 報告全文 FULL-PASS、quest 封包語意、S00 規格驗收或遊戲可玩認證。

## A. TutorialBase.lua 14 筆來源身份退回：RESOLVED（僅引用／來源層）

精確通知：`T16-045`、`T16-046`、`T16-048`、`T16-049`、`T16-052`、`T16-054`、`T16-056`、`T16-060`、`T16-061`、`T16-062`、`T16-063`、`T16-064`、`T16-067`、`T16-068`（每筆固定通知尾碼 `89ddf3e8`）。完整 old/new blob 與處置見 [第二輪通知快照](notice-review.json)。

- 原稿沿用錯誤 56 位雜湊 `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`，不能作為 SHA256 來源 ID；14 篇原稿的每次引用均已按 Git 原始 blob 查閱。
- 本次以**使用者提供的實體 `Event.stp`** 再次驗證：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Event/TutorialBase.lua` 成員位於容器 offset `10645520`，長度 `1416`，容器 bytes XOR FF 後為 Lua5.1 bytecode。成員 SHA256 **`26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`**，6 prototypes、72 instruction words；對應 `Event/TutorialMain.lua` 亦已驗證但不是上述 14 項的必要結案條件。
- **歷史 `kr/evidence/<錯誤 SHA>.txt` 404 是當時錯誤路徑/連結結果**，不是原始 `Event.stp` 沒有該成員的證明。作者 14 篇 erratum 均明確更正引用與 404 的語意限制，原稿舊版不改寫。
- 每個通知的問題是**來源身份 SHA/不可得推論**，不是「已驗證所有 TutorialBase callback 的功能」。因此**僅此 14 通知解除**；Lua 全部原型的語意、Quest16→Quest15 事件、Server 回覆/C→S/S→C 與 UI 效果維持 unknown。

## B. 0xA0A4 vs 0xA078：1 筆 RESOLVED（T16-069）

`T01-RETURN-T16-069-CONT02-C11`：原稿 scenario matrix 第 67 行稱 `A0A4` 為 queue-count gate；作者新 erratum SHA `f6a35543d5f74c1ac01d05aff2cfc4cd11548a24` 已改成 signed 值/佇列 admission gate。T01 由 KR BIN 檢核 `0x8060FA` signed comparison、`0x804AF0/0x804AFC/0x804B13` ±5/reset、`0x8060A1/0x8060A2` 鏈表 count ++，`0x806275` count --；有限 producer/consumer 對上。**不能**將 send-buffer success 當作 OS wire send、Server ACK；`A0A4` 業務意義 unknown。詳見 [原生逐指令核對](native-evidence-and-resource-boundaries.md)。

## C. T16-026：1 筆 RESOLVED（撤回 T01 自己的錯誤反證）

`T01-RETURN-T16-026-c26518b1` 原說「`0x4AEDB0` 在 `0x4AEDAF` 的 `add` 指令內，不能是入口」。這是**從錯誤鄰接位置線性掃描造成的 T01 原始反證錯誤**。

- 原件 `0x4ADD88` 指令 `C7 80 F4 09 00 00 B0 ED 4A 00` 寫入 `[eax+0x9F4]=0x4AEDB0`，明確安裝 callable callback。
- `0x4AEDB0: 55 8B EC` 開始獨立 x86 函式序言；`0x4AF1E7: C2 0C 00` 為 `ret 0xC`；作者 root 入口補證另見 `rooted-cfg/T16-026-rooted-cfg-addendum.md`（Git blob `c22ce563cfd2734ffaac6f8e91fa0f184e2d4443`）。
- **T01 撤回其錯誤反證，解除這一筆沒有成立的退回；不代表已逐一驗收全部 callback branch、原始 325 行報告的每個獨立主張，也不能叫它 Quest-specific handler。**

## D. 仍待複驗 16 筆

- `T01-RETURN-T16-092-6df3bb2c`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-001-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-009-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-020-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-021-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-022-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-029-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-030-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-031-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-033-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-034-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-036-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-040-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-050-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-051-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。
- `T01-RETURN-T16-065-c26518b1`：rooted-CFG 全可達 edges、影響到的舊附錄主張與來源 callback/ABI 仍待更全面驗證；本輪未因原生座標局部正確而升為 FULL-PASS。

下一批建議先處理所有 16 篇根 CFG：作者本地完整 JSON/line-crosswalk 尚未推至 Git，需請作者／使用者提供 **`20261029-220621-chatgpt-web-roy-T16-T01-returns-phase3.zip`**（含原始 `root-*.json`、跨指令窗口和 71 call/jmp）；T01 仍須以 KR BIN 獨立核對，不能只接受 JSON 自述。另見 [需要的原件與非缺件判定](RESOURCE-REQUESTS.md)。

## E. 獨立驗證、責任界線

- 本次 verified scope：14 份歷史原稿的錯誤 SHA 及 14 份作者修正的唯一來源身份；一條 queue gate/鏈表 producer-consumer；一條原生 callback 登錄對舊 T01 反證的推翻。
- 原件 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，.text VA `401000` raw `400`，故 .text raw=VA-`400C00`；本輪所有靜態欄位地址僅適用此 KR 版本。
- **Client 待逆向**：Quest 的真正雙向封包 ID、方向別 payload、NPC/選角/任務 state 更新、Tutorial Lua callable bridge。
- **Server 待開發**：任務前置／完成／失敗/保存規則；由 S00 的 ADR/SPEC 獨立設計，不暗示官方 Server 內部邏輯。
- **跨功能待整合**：T16 ↔ T02/T03/T06/T07/T14/T15。
- **遊玩待驗證**：沒有執行原始 Client，沒有 wire capture 或 ACK；不升 SPEC STABLE、RR ACCEPTED、NATIVE_VERIFIED、source FULL_PASS。
- 審核主責：T01 / ChatGPT-web roy。最新 43 筆固定 ID 在 [notice-review.json](notice-review.json)，原 Task T16 保留全部舊稿及新作者勘誤 blob 身分。