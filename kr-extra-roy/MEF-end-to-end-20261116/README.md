# MEF 端到端流程研究包（2026-11-16）

本包接續 `extra/roy1` 的八輪 MEF 研究。基準為 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，原本機研究的 merge 父提交為 `b0bf6bb5986f9c849fcfac4e16db42f0a1cf960c`；公開版本的來源與合併父鏈可透過下列提交重驗。

公開來源 carrier 使用同 tree 的 R8 `dda39a65ca483f2b4539c6feb74e05dfcdbf7ac8` 與 merge `15819c892c0a9a23924704daa5883615a09626bf`。上段保留原本機研究時間線；[發布對照](publication-note.md) 說明 metadata 與來源 pin 更新，乾淨 clone 不依賴未公開的本機 commits。

**[先讀完整主報告](../20261116-040128-chatgpt-web-roy1-MEF-end-to-end.md)**。它整合檔案交付、SceneList／0047 選取、雙 VM、依賴工作、parser／executor、coroutine、物件、等待、取消、End、003F／00EB 與再入。**[Server 開發交接](server-handoff.md)** 將可實作需求與 Client 待逆向分開；不另建正式 RR／REQ 台帳。

## 本輪新增原件結論

| 分題 | 新閉合的有界鏈 | 明確保留的限制 |
|---|---|---|
| [entry](entry/report.md) | prepass 同步 Register；正式 Register → coroutine.create → list；CLOSURE／RETURN upvalue 保存與 GC 強參照；lexical phase 的時序前提；非零 quest End gate | 新 caller 是 `CONDITIONAL_DESIGN_NOT_NATIVE_MEF`；原生 MapList first loader caller 未證；Register 沒有完整預載成功 ACK |
| [runner](runner/report.md) | Lua debug hook 的五種 VM producer；新 thread 欄位與 registry 差異；兩個 input API 真實 marshaller、mask／鍵位表效果；Q 公開面來源索引 | hook 不提供獨立 frame pump；mask `0x2` 與 controller+58 是不同 owner；public surface 讀集不是全程式 alias-complete 陰性 |
| [world](world/report.md) | 固定 Tutorial CActor 建立、F000 幾何 observer、DeleteObject(240) 真實 world erase；鍵位選擇 UI → controller+134 → 原版 Lua 等待 | 固定 key、實際 Tutorial context；非任意 EntityId、敵人 HP／死亡／清組 observer；重名可能讓 getter 觀察其他物件 |

普通戰鬥全面替代尚缺：合法背景 Lua runner、可供腳本／Server 使用的穩定 typed world identity、具對象／群組語意的結果 observer。它們不能由 Server 猜造 Client 介面補齊。發布、排程、狀態對帳、取消與持久化則明列為 Server 開發需求。

## 檔案索引與證據分級

| 檔案 | 用途 |
|---|---|
| [publication-provenance.json](publication-provenance.json) | 原本機與公開同 tree 提交對照；R9 來源 pins 的發布修訂 |
| [source-manifest.json](source-manifest.json) | 原件 SHA／大小、共享指示、Git 同步基準、三組驗證入口與限制 |
| [artifact-manifest.json](artifact-manifest.json) | 本輪完整稿件與證據檔 SHA-256；排除自身與總控生成結果以避免循環 hash |
| [prior-analysis-index.json](prior-analysis-index.json) | 八輪主稿與實際重用原稿的 commit／blob／內容 pins、已更正的舊結論 |
| [governance-source-pins.json](governance-source-pins.json) | 開工查核的治理、共用驗證、Task／RR／退回來源；不更動 owner 或台帳 |
| [requirement-context.json](requirement-context.json) | 既有 REQ-0019／REQ-0021 的選定需求關聯，不複製成新台帳 |
| [flow-contract.json](flow-contract.json) | 14 個階段、19 條有條件關係、5 類失敗邊界的分析索引；不是 native MEF schema |
| 各分題 `native-windows.json`／`.asm` | 新增原件 bytes、VA／PE raw mapping、hash、指令邊界與可讀 disassembly |
| 各分題 source／Lua／contract JSON | 固定來源、選定原版 bytecode operands、producer／consumer 與反例 |
| [verify_evidence.py](verify_evidence.py) | 總控：原件身分、Git pins、交付完整性、連結、流程分級及三分題核對；可重跑 R6–R8 |
| [verification-result.json](verification-result.json) | 本輪實際總控輸出，包含 subgroup 計數與基線重跑結果 |
| [R6 結果](previous-r6-verification.json)／[R7 結果](previous-r7-verification.json)／[R8 結果](previous-r8-verification.json) | 本輪實際重跑既有證據包所得完整輸出；不是把歷史 PASS 字樣直接搬過來 |

新增結論以本輪原件為依據；舊稿只在固定版本、限定主張範圍復用。bulk C 僅用導航。未知原生入口與 ordinary gameplay 整合仍標未完成；無新可部署遊戲資源、原 BIN／STP 或完整解包 member。

## 本輪核對規模

各組只計自己的保存範圍，重疊視窗未去重；不是全程式覆蓋率。

| 分題 | Native records | Code windows | 指令 records | 固定 Git pins | 另外核對 |
|---|---:|---:|---:|---:|---|
| entry | 42 | 31 | 2,560 | 27 | 47 anchors、28 direct calls、23 bindings、169 selected Lua words、21狀態／33條件邊 |
| runner | 43 | 31 | 1,741 | 154 | 5個hook targets、40個關鍵指令、63個既有Q bindings索引 |
| world | 84 | 55 | 3,927 | 44 | 8個實際bindings、4個原版Lua prototypes、8,354項核對 |

## 唯讀重驗

需求：Python 3.12、Git、支援 PE32 i386 的 GNU objdump、來源 manifest 指定的 Git objects，以及原始證據檔。部分來源位於 sparse checkout 之外，驗證器讀固定 Git object；不自動 fetch。缺少 pin 或原件時會失敗，不以新來源靜默替代。

將下列 `/path/to/...` 改為實際路徑；這些是命令列路徑占位符，沒有對遊戲執行：

```bash
python -B kr-extra-roy/MEF-end-to-end-20261116/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --originals /path/to/project_sources \
  --recheck-prior
```

原件目錄需含 `02-Tartaros.bin`、`01-Tartaros.exe`、`06-Event.stp`、`07-Table.stp`、`09-02-PROJECT-SHARED-INSTRUCTIONS.md`，內容身分必須與 manifest 相同。檔名前綴來自本輪實際提供的附件。Coroutine 原 bytes 取自固定 Git carrier；啟用 `--recheck-prior` 時只寫到自動清理的暫存目錄，不回寫 Git／原件。

不加 `--recheck-prior` 時仍重驗本輪三分題、所有本輪 source pins 與證據完整性；R6–R8 只驗保存的結果檔身分，不宣稱在該次重跑。結果的 `previous_rounds.*.rechecked_this_run` 會明示差別。

本輪實際執行含 `--recheck-prior`。R6 原有 40 個 artifact／184 個 commit-path pins，R7 為 37／245，R8 為 37／232，皆 PASS。這些計數各自屬於包內檢查範圍，不代表三輪完全沒有重疊，更不是全程式覆蓋率。

## PASS 代表什麼

PASS 表示列明的原件 bytes、Lua 當資料解析、source pins、視窗反組譯、特定關係與交付一致性核對通過。它不代表所有語意已由獨立審查者驗證，也不是 T01 FULL-PASS、RR ACCEPTED、SPEC STABLE、Server 已實作或玩家正常流程已驗收。

本輪沒有執行或附加 Client，沒有執行 Lua／Server，沒有發送測試封包，沒有修改原始遊戲程式與資源。流程設計可以供相容開發接續；正式審查、實作與遊玩驗證各自保留狀態。
