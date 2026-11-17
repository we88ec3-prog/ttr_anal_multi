# 普通 Mission／Scenario 一次切點：前輪原稿及 callback 續查完整發布

工作分支 `extra/roy1`；研究基準父提交 `716814e1ba88c1917a90b890a0187642eaca80ef`，main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本次遵照使用者「繼續分析後上 Git」，補交上一輪未提交的完整研究，並保存本輪新結果。不新建 branch、不改 Client／Server／原始資源或正式 RR／owner。

## 研究結論

**A：允許有限插播。** 上一輪已閉合有條件、未部署的同場景靜態鏈：普通場景 → 0047／合法 SceneList 資源 → prepass／正式 Register → native Start 尾段完成 → callback 修改唯一既有 `(category,key)` → End 並立即返回 → 適用等待解除及 controller busy 正常消費。相容新內容不等於官方 MEF grammar；尚未分配新內容或實機驗收。

**B：全程保持正常戰鬥操控。** 本輪追完選定 callback 候選，沒有取得新的正向入口，保留精確證據阻塞而非聲稱全程式不存在。

| 候選 | 原件結果 | 實際限制 |
|---|---|---|
| OnYesTriggered | 普通 Mission／Scenario 對 004E/F43DA 不進該 Lua callback；這項主結論復用 R7，本輪補 inherited switch 與尾段 | Lobby／Tutorial 的成功路線還會排 F4358，不能拿換頁當普通戰鬥解法 |
| OnEndTalk／F434E | 普通頁面確可到 Lua，已識別 producer 是 active Q Stop bulk | 是 Q 已接管後的取消鏈，不是未接管的首次入口 |
| 正常／自動對話完成 | selected-record 必須有效；已識別 open 來源是 Lua binding | 已有 Lua → open → 完成 → Lua 的依賴，未解首次入口 |
| g_CharExplain.GetExplain | 兩個 callsite 的已識別正常 caller 屬遠征、結算、教學頁面 | 不能算正在戰鬥的普通頁面入口 |

OnEndTalk 返回後，native 還要隱藏視窗並清 selected-record；不能將 callback 當成所有 UI 已恢復的訊號。本輪沒有證明所有對話都全面鎖住輸入，也不以這個未查主張否定方案。

[本輪完整技術閱讀版](REPORT.md)包含地址、型別、switch 正反對照、原版 Lua operands、已查範圍及下一條證據入口。正文與原稿一致，只有包內連結改為檔名提示；精確原稿保存在下面的完整研究包。

## 建議的下一步

優先將 A 收斂成最小可實作內容契約：有來源的 scene 雙鍵與 point 身分、只切狀態、不建角色／換圖／動鏡頭、正確 prepass/formal、End 與等待解除。Server 平行處理通關判定、內容及點集合發布、服務、結果對帳與保存。

B 獨立保留。下一個定向入口是 **CScenarioTalkBox+9C 的 concrete-receiver 獨立 writer，或 FE3184／6BD620 的真實間接 caller**，且須由普通場景非 Lua 事件到達；再接資源載入、input/capture 與退出。不要重掃已查 F43DA／F434E literal 或用任意相同 offset 命中充當資料流。

## 完整研究包：25 檔，沒有省略原稿

本目錄的 `research-kit.tar.xz.part01` 至 `part12` 是一份研究專用無損封裝的連續分片，**不是遊戲資源包**。包含：

- `MEF-one-shot-study-20261116/`：上一輪 13 個完整檔案，含 26,968-byte 原稿、Server 交接、原始節錄、全部反組譯、來源、契約及驗證器。
- `MEF-one-shot-callbacks-20261116/`：本輪 12 個完整檔案，含 18,461-byte 原稿、Server 交接、已查範圍、原件及 Lua 節錄與實際驗證結果。

上一輪 native JSON／ASM 的重複地址／hex 文字以窗口 bytes＋逐指令長度／文字無損保存；還原後每個檔案的大小與 SHA-256 必須完全相同。不是根據摘要重新生成技術結論，也不依賴不同版本 disassembler 重造原稿。其餘 23 檔以原 bytes 保存。

取回本目錄全部分片、manifest 和 Python 程式後：

```bash
python -B restore-research.py --out ./restored-mef-research
```

只需 Python 3 標準函式庫；不連網、不讀遊戲原件、不執行包內程式，不覆寫既有目錄。所有檔案先核對通過才輸出。還原後兩個 REPORT.md 的相對證據連結完整可用。[publication-manifest.json](publication-manifest.json) 保存 12 分片及 25 原稿的大小／SHA-256；[restoration-result.json](restoration-result.json) 是本輪實際還原結果：25／25 完全相符。

研究封裝 SHA-256：`b970253d6dee56b6df8e8b8b3a71285e0f320a6364ef5739f602fe869cb4524e`。

## 原件驗證與完成狀態

上一輪 verifier 實際重跑 PASS：42 windows、3,380 條解碼指令。本輪 verifier 實跑 PASS：35 windows、3,836 bytes、1,200 條解碼指令、43 錨點、10 組 switch data、8 組 typed vtable、120 條 direct transfer、12 組 target census；另核原版 qbase 兩個小 callback 及 root binding operands。兩個 verifier 在還原後的檔案上也再次通過，輸出與保存的結果一致。

這些是有界原件／結構一致性檢查，不是全程式無路徑證明、T01 FULL-PASS、RR ACCEPTED、部署、Server 已實作或遊玩驗收。未執行 Client／Lua／Server，未重驗整個歷史 Git source graph。原先研究紀錄中「當時未 push」欄位保留真實歷史；本次發布才是公開交付。

本包**沒有**原始 BIN／EXE／STP、完整解包遊戲 member、可部署新遊戲腳本。原始資源另由持有者提供，唯讀 verifier 的命令與 SHA 見還原後兩輪 README／source-manifest。
