# 來源、已查範圍及狀態

## 原件與版本

- `Tartaros.bin` SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；所有新主張以其raw機器碼、vtable資料及PE映射為裁決。
- `Event.stp` SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；只重核前輪指定qbase片段，不執行Lua。
- 工作repo `we88ec3-prog/ttr_anal_multi`，固定遠端ref `0d76b827dfda0deb263e2692281ec304747652f8`。main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，無新的上游差異，不建立空merge。
- 前輪surface包尚未推送；它的所有引用是本機已驗SHA，不編造遠端blob/commit。累積發布會保存原文，不改其歷史狀態。

## Git來源與使用範圍

下列path均在上述固定工作ref。來源文字可支持語意復用，不表示本輪把整份報告提升到FULL-PASS。

| path | Git blob | 本輪使用範圍 |
|---|---|---|
| `kr-extra-roy/MEF-capabilities-20261116/audiovisual/report.md` | `9f1d8cf2ed160eb29245859c4460ad64c1d6aeb5` | §1–7：相機owner/Stop/Pop、音樂worker/Stop/fade及native效果；重點§4–6逐段讀取 |
| `kr-extra-roy/MEF-control-flow-20261116/world/report.md` | `c5ef2ba32d3bad0249f73bda930ea51b72a440d7` | 前段公開面、圖片ABI；§5–6 Prolog/Book既有writer/observer；完整圖片下游由本輪BIN再核 |
| `kr-extra-roy/MEF-capabilities-20261116/capability-catalog.md` | `1418bce095699db858c19b523a73613fde41ec9b` | 本對話既有121能力語意基線；本輪用前輪固定矩陣核名稱與address tuple |
| `kr-extra-roy/MEF-A-minimal-spec-20261116/SPEC.md` | `cab38e5ee6f1b20ecc0a8de96e128b110617faeb` | 沿用既有A1規格與精確單次政策，不更改；不是本輪新功能已部署 |
| `kr-extra-roy/MEF-one-shot-followup-20261116/REPORT.md` | `2da37c55922e47815b9041533f6e3070f7df34f3` | 既有B入口排除與CScenarioTalkBox後續來源，直接復用不重掃 |
| `kr-extra-roy/MEF-control-flow-20261116/presentation/report.md` | `83605a7316c394a470eb1aacea3412f71193ba4a` | 前輪固定source中的End/Stop／snapshot生命周期；本輪直接以BIN重核End/Stop和新相機實際consumer |

完整本機檔案SHA和實際來源manifest見 `source-manifest.json`。矩陣引用的其餘R11／R14與world/event報告是先前已讀脈絡，標 `INHERITED`，不稱本輪重新逐字／逐指令查完。

## 本輪直接查證

- 50個列明區間的上下游、normal End與active Stop分流。
- KeyFrame及AttachSceneObj的current/playing/stop/apply；Stop真的阻止所選apply，未把尾呼誤認成續寫。
- world owner對象來源、顯示/慢動作flag及動畫executor、黑邊draw。
- Q圖片建立最後handle、有限/永久hold、tick/alpha/phase/alive、實際release/dtor/erase、main更新與draw來源。
- 音樂functor/thread callback、共享16stream Stop與具體stream釋放。
- Q StopObject、全Q樹DeleteAll、movement query與模型job等待。
- 已知註冊census與前輪qbase片段重新執行驗證；不把此回歸計為新增API。

## 沒有做的事

沒有全量重新反編譯，沒有全STP檔名搜尋，沒有再把OnYes/MapList舊陰性當新題，沒有插入Rebind/任意pointer/新opcode、執行Client或Lua、修改遊戲原件/Server/正式台帳。沒有證明所有computed/inline/DLL註冊，也沒有證明普通world事件普遍可到Lua。

公開交付只包含分析、少量原件節錄、機讀索引與只讀驗證器。探索用的任意中間反組譯沒有混入證據；可發布ASM由精確已驗起訖重建。尚未查明的接口以具體候選及條件保留，不靠「需要實機」一句話略過仍可查的靜態分支。
