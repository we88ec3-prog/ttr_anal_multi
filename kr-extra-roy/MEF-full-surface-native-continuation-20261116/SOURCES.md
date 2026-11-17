# 固定來源與已讀範圍

Repository `we88ec3-prog/ttr_anal_multi`；本輪公開父提交 `0d76b827dfda0deb263e2692281ec304747652f8`；main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。Git compare回傳ahead14/behind0、merge base等於main。此處指寫入前基線，不預填尚未建立的新commit SHA。

| 路徑（固定於父提交，除另註） | Git blob／額外身份 | 使用與閱讀範圍 |
|---|---|---|
| `kr-extra-roy/MEF-capabilities-20261116/capability-index.json` | `3b51c68dfdb273e34a29bd5cbee429d673699a7e` | 前65行：七命名空間的scope/count；未宣稱重新逐字審閱全JSON語意 |
| `kr-extra-roy/MEF-capabilities-20261116/capability-catalog.md` | `1418bce095699db858c19b523a73613fde41ec9b` | 既有能力域、型別、stub及條件導覽；方法語意沿用既有研究，不以新名稱掃描代替 |
| `kr-extra-roy/MEF-content-contracts-20261116/actors/report.md` | `7ba4ed36797f740ecaa11790782729e446f359ca` | Q actor producer、型別、索引、Delete stub／bulk生命周期相關段落 |
| `kr-extra-roy/MEF-control-flow-20261116/presentation/report.md` | `83605a7316c394a470eb1aacea3412f71193ba4a` | 前160行：End/Stop、相機、地圖、Sepia及owner限制；其餘未重稱本輪驗完 |
| `kr-extra-roy/MEF-A-minimal-spec-20261116/SPEC.md` | `cab38e5ee6f1b20ecc0a8de96e128b110617faeb` | 上輪已交付規格作前提，未修改；本機zip中的檢查程式實際重跑，見previous-a1-rerun |
| `kr-extra-roy/MEF-one-shot-followup-20261116/REPORT.md` | `2da37c55922e47815b9041533f6e3070f7df34f3` | 同對話既有OnYes/OnEndTalk/GetExplain反證與下一入口；本輪不重掃為新發現 |
| `shared/verified-knowledge/README.md`（main） | `710e76a446ff807e4d49c724cbc734fcf21c9481` | 全文准入範圍；局部FULL-PASS不涵蓋本輪整體功能 |
| 已發布研究包內 `MEF-one-shot-study-20261116/verify_evidence.py` | SHA256 `3a7e2751274b9c1cc43f514e8ab13a5b48ff5983251f847334e213baab0381d2` | 經檢閱的data-only STPD/Lua parser，import前核SHA；來源在前述one-shot-followup發布manifest |

本輪第一手：`Tartaros.bin`的PE section與raw machine bytes；`Event.stp`中指定qbase member。兩個hash與member mapping保存於JSON。其他STP只保留前稿來源，不以本輪未讀／未解包的材料產生新主張。

本地Project共享指示已全文讀取；沿用本對話已讀main AGENTS與Client修改政策。沒有新RR認領或改正式台帳。本輪新增scope為raw-backed `.text`的固定registrar／closure sink直接候選、其原指令界線，以及本文列出的native持續效果區間；不是全程式所有alias／DLL／動態closure的閉包。

## 重現範圍與排除項

`audit.py`完整重算121正式＋1預掃描registrar、223 sink candidates並在已解碼的registrar／prefix範圍核實指令起點、11個table registrar直接call、固定tables、46組code window、16anchors、5data windows、15transfers及選定qbase資料。LLVM／其他objdump輸出格式不同時不能改原件湊PASS；應先核工具差異。

已排除：把預掃描stub當實作、把Rebind當背景runner、把Lua標準庫當遊戲功能、把Q角色當網路怪、把End當所有資源清理、把Fade.active0當透明、把native tick當Lua callback。未查盡computed/inlined/DLL路徑，故沒有全程式否定主張。
