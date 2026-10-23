# 分工整理完成報告

本輪完成既有成果的有界整理與試交接驗證；未完成原生功能還原，也未進行遊玩測試。

- 原始盤點：105,962檔，31.129 GiB。
- 選入來源：412檔；去重後407份內容。
- 排除：105,550檔；逐檔SHA與原因見shared/manifests/dispositions.jsonl.gz。
- 仍待版本歸屬：選入內容166份。這些是明列未知，不強行歸類。
- 方法項目：104，其中17項待分派；不代表有效函式分母。
- 重新核對412個選入原始來源SHA，無變更。原anal未修改。

## 交接驗證

T08/T09均完成獨立解壓、禁止原anal/原執行檔讀取、任務查詢及竄改偵測。完整歷史引用仍有缺口，沒有把校驗通過當成語意完成。

|版本|任務|狀態|
|---|---|---|
|kr|T01 現有成果來源審核|bounded-review-handoff|
|tc|T01 現有成果來源審核|background-only-native-evidence-missing|
|kr|T02 共用通訊與封包框架|bounded-review-handoff|
|tc|T02 共用通訊與封包框架|background-only-native-evidence-missing|
|kr|T03 登入與角色選擇|bounded-review-handoff|
|tc|T03 登入與角色選擇|background-only-native-evidence-missing|
|kr|T04 角色初始化|bounded-review-handoff|
|tc|T04 角色初始化|background-only-native-evidence-missing|
|kr|T05 廣場進入與移動|bounded-review-handoff|
|tc|T05 廣場進入與移動|background-only-native-evidence-missing|
|kr|T06 地圖與場景資源對應|bounded-review-handoff|
|tc|T06 地圖與場景資源對應|background-only-native-evidence-missing|
|kr|T07 關卡進入與退出|bounded-review-handoff|
|tc|T07 關卡進入與退出|background-only-native-evidence-missing|
|kr|T08 實體生成與移除|bounded-review-handoff|
|tc|T08 實體生成與移除|background-only-native-evidence-missing|
|kr|T09 關卡內移動與同步|bounded-review-handoff|
|tc|T09 關卡內移動與同步|background-only-native-evidence-missing|
|kr|T10 普通攻擊與連段|bounded-review-handoff|
|tc|T10 普通攻擊與連段|background-only-native-evidence-missing|
|kr|T11 技能施放|bounded-review-handoff|
|tc|T11 技能施放|background-only-native-evidence-missing|
|kr|T12 命中、傷害與死亡|bounded-review-handoff|
|tc|T12 命中、傷害與死亡|background-only-native-evidence-missing|
|kr|T13 非玩家實體的行為來源|bounded-review-handoff|
|tc|T13 非玩家實體的行為來源|background-only-native-evidence-missing|
|kr|T14 關卡目標、完成與獎勵|bounded-review-handoff|
|tc|T14 關卡目標、完成與獎勵|background-only-native-evidence-missing|
|kr|T15 遊玩資料保存與恢復|bounded-review-handoff|
|tc|T15 遊玩資料保存與恢復|background-only-native-evidence-missing|

## 工具與重現

讀取/匯出：Python 3.10+標準庫，shared/handoff.py。原生證據保留原工具/版本/位址與限制；本輪不開新原生分析。

下一次來源有變動時：先備份本版，再執行resume_inventory.py增量核對；不可重建全部原生atlas。舊build_handoffs是初版建立程式，後續refine/add/finalize的修改已保存，不要只重跑初版覆蓋現況。

詳盡校驗與容量見REPORT.json；原始CHECKPOINT保存在history/checkpoint-v1.json.gz。

## 整理後容量

- 本機目錄：約 88.5 MiB（含歷史與ZIP）。
- 排除history、exports及快取的分享內容：約 73.32 MiB。
- T08 ZIP：1,560,349 bytes；T09 ZIP：2,234,134 bytes。
