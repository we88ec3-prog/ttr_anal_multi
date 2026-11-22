# 主線循環管理與經驗政策配套

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
接續 [正常主線循環通關](STORY-STRUCTURED-LOOP-TCP-ROUTES.md)。本文件定義本批開發契約；
通過的工程及人工證據分開追加，草稿／實作存在不代表 Client 已驗收。

## 專用 profile 與預覽

普通主線工作台維持原樣，繼續拒絕循環草稿。另設 `story-q119-loops`，
啟動時以絕對路徑及 SHA 固定原主線、原 BND、循環候選與經驗政策。
profile 身分涵蓋原主線、候選、AI、政策、任務及原 BND SHA。
僅編輯 Q119；保留現有敘事來源、房間數／地圖／初始模型綁定與角色資源延續規則。
可修改有效循環輪數或保存停用循環的新版本，但不將任意地圖／格式變更混入主線發布。

每次驗證都以修改後合併主線及 AI 再核對原經驗政策，不只驗證範本。
顯示完整路線經驗上下界：逐訪初始／順序／計時波擊殺＋逐訪清場＋一次通關＋一次固定任務獎勵。
`completionExperience` 僅指通關部分；固定任務獎勵以 `storyRewards` 明確標示。
`storyRewards` 包含 quest、fixedExperience、experiencePolicySha256、scope=`ONCE_PER_QUEST_COMPLETION`。
界限不能超過既有 int 結算範圍；不以循環次數重複發固定任務獎勵。
原候選三輪上限：4～8訪、總經驗5932～5972；改四輪：4～10訪、5932～5992。
停用循環仍是原四房，總經驗5932，仍須攜帶固定政策與一次性獎勵 metadata。

## 不可變版本 ZIP

沿用既有 draft／revision basename、scenario-bundle schema、固定 ZIP timestamp，
新增 `<stem>.story-experience.json` 原政策 bytes，檔案 SHA 必須等於 profile 的政策 SHA。
manifest 增加 `experiencePolicy:{file,sha256}` 及 `storyRewards`；
`experienceBounds` 包含完整 minimum／maximum、completion、maximumNodeVisits，
interpretation=`STORY_TOTAL_PER_VISIT_PLUS_FIXED_QUEST_ONCE`。
即使保存停用循環版本，上述政策與獎勵欄位仍不可省略。
AI／關卡／政策及 manifest 共四檔。舊三檔狩獵／RAID 配套格式保持。

部署設定包含精確關卡及 AI 路徑／SHA、原主線 SHA、主線循環 mode，
以及本 ZIP 經驗政策路徑／SHA。原主線與 BND 仍是 Host 既有固定來源，不複製原件至 ZIP。
成對讀取器只接受指定 profile、draft／revision 精確 basename、逐檔 SHA、
由內容獨立重算的迴圈／獎勵界限與完整設定字典；不執行任意環境設定或腳本。
回傳設定將關卡／AI／政策 placeholder 解析為同一配套目錄絕對路徑。
管理預覽不能寫草稿；發布只下載既有保存版本，不能默默切到最新或修改歷史版本。

## 本批驗收範圍

正流程涵蓋三輪／四輪／停用循環配套、預覽不寫入、保存及不可變歷史 ZIP、
獨立成對讀取及實際部署版本的正常 NPC／編成／戰鬥／結果／回村。
Host 與 Admin 各使用隔離 DB 副本與 loopback 埠，完成後停止自己的 PID／路徑。
指定 v2 人工、自然新帳號、原生 MEF／Client 自主 AI 仍分開待驗；
不跑重送、重登、敗退、故障、安全、併發或壓測。

## 已完成工程驗收

三個 Release（Host、Inspector、Admin）皆零警告／錯誤；745/745 HappyPath 全通過，零略過，
其中新增三個正流程核對三輪、四輪、停用循環的總獎勵、確定性四檔 ZIP、獨立讀取、
政策原 bytes 與解析後路徑。舊狩獵／RAID 三檔配套的正流程仍在完整套件內通過。
TRX SHA256 `851339488f23546344876eb16f5cd216d8ca52df2bf2f59288fd87817c24ba1e`。
管理端前端腳本另通過 `node --check`；這是語法檢查，不是視覺／人工操作驗收。

隔離 Admin 以真 HTTP 完成預覽、保存三個版本及下載各版本 ZIP，預覽前後草稿筆數不變。
後續保存後，之前版本下載仍逐 byte 相同。經驗政策原件保持 SHA
`60ca18e680aecec6218f96b5d6d09baf781ff6e81ef7812f9372f4a2d90940ee`，
三份配套都由獨立 profile 讀取器驗證四檔、manifest、重算界限及設定字典。

| 保存版本 | 循環 | 最大訪問 | 完整 EXP 界限 | 下載配套正常 TCP |
|---|---|---:|---|---|
| r1 | 原三輪 | 8 | 5932～5972 | 上限8訪／5972 |
| r2 | 四輪 | 10 | 5932～5992 | 停止4訪／5932、上限10訪／5992 |
| r3 | 停用 | 4 | 5932 | 4訪／5932 |

四條 TCP 路線都用 ZIP 實際關卡、AI 及政策 bytes；不是以預設 AI 代替已保存 AI。
原 NPC、編成及劇情回報、原 BND 走位／戰鬥、一次結果／結算、同隊回村與下一任務保持。

r2 停止／上限與 r3 普通路線再各部署到獨立完整 Host，以真實排程通過4／10／4訪。
health 核對 manifest／關卡／合併圖／共用 AI／政策及動態最大訪問數，
停用版本的主線循環字典確實為空。唯讀 DB 獨立核對戰鬥52／112／52 EXP、
Q119 任務交易各一筆5880 EXP及40精通，合計5932／5992／5932，回村map182、原隊伍及Q120。
準備教學／Q15，Host 另準備Lv15，不是假稱自然新帳號全主線。
三個 Host／隔離 Admin 皆已停止，來源 DB SHA 不變，未替換現用服務／Client。
驗證器處理缺省0清場獎勵後重跑完整上限路線；沒有改任務獎勵或以失敗收據作通過。

[交付交叉核對收據](story-loop-workbench-delivery-validation.json) SHA256
`439028a9265fc86d2f026aad63f92934c3e7263da5b4cec84552c50fc1777ba4`，
包含三份固定版本 manifest、四條 TCP、三個真實 Host 及完整 HappyPath SHA。
先前核心／設定、來源 TCP 與 Host 收據保持原樣，不回填當時未完成項。

本批關閉「主線循環工作台／政策配套」工程缺項。指定 v2 人工、逐項資源延續、
自然新帳號全主線、原生 MEF 傳入／載入與 Client 自主 AI 仍未證明；整體目標維持進行中。
