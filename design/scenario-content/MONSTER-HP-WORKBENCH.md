# 怪物最大 HP 圖形編輯與副本交付

2026-11-23。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
接續[完整整合副本](MEF-INTEGRATED-DUNGEON.md)與[交付入口](../testing/INTEGRATED-DUNGEON-DELIVERY.md)，
補上既有 spawn `maximumHealth` 在二維工作台缺少的編輯欄位。沒有新增原生格式、opcode 或 Client 修改。

在 `/admin/scenarios` 選取初始、依序增援或定時增援的怪物，於「這隻怪物的最大 HP」
輸入整數，按「套用物件參數」後保存新版本。欄位允許 1～1,000,000；留空會刪除該怪物的
`maximumHealth`，恢復既有成長／AI 規則。只改選取出生定義，不改共用 AI 或其他怪物。
這是共用編輯元件；本批實際驗證普通 Case693，未外推 Story／RAID 人測或必要頭目身分編輯。

既有 Server 優先序為：出生定義明確 HP → 關卡指定成長等級 → 已解析的 AI profile。
清空欄位不是固定改成 60；本批入口怪物使用 `integrated-projectile-v1`，繼承值為 80。
這項優先序原本已存在，這次沒有改成長引擎或副本血量平衡基線。

## 保存版本與通關

來源為 `phindos-stage462-case693-flag-delay.scenario.json`，SHA256
`c0b22c412c8cca7889bc24167c9802b85199558974226c3d5a99f68a8d38ca6a`；
配套 `integrated-attack-flags.monster-behavior.json` 原始 SHA256
`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
在獨立 SQLite／Admin 工作副本建立 r1，實際瀏覽器操作保存 r2，再清空三個 HP 保存 r3。

| 選取的出生定義 | r2 明確 HP | r3 欄位 | r3 實際觀察 HP |
|---|---:|---|---:|
| node10 初始，model1004，416/392 | 120 | 移除 | 80 |
| node1 依序增援，model1022，360/388 | 72 | 移除 | 60 |
| node1 定時增援，model1022，392/376 | 84 | 移除 | 60 |

三個歷史 ZIP 各重讀兩次並核對 response SHA、manifest 與 scenario／AI；完成後再重讀確認
歷史不變。瀏覽器表單將 AI 的 LF 換為 CRLF，因此只主張內容語意相同，實際不同 SHA 分開保存。
編輯器既有套用流程另加入三個 `aiProfile:null`；比較器只正規化這三個欄位與本批 HP，其他內容相同。

r2／r3 各兩條完整 TCP 分支：正式登入、廣場建隊、進村、選關、原 BND 移動／戰鬥，
機關11／31／33、波次與頭目階段、分支、結算，各保存 88 EXP、返回原村同一隊伍。
各版本另以獨立部署 Host、真實時間完成六房通關與 SQLite 資產核對；只讀診斷觀察上述
三個怪物首次出現時的 HP，沒有測試時計、直接遊戲 Handle／Poll 或 Client 操作。
這些觀察不是 Client ACK，TCP 準備帳號也不是自然新帳號主線全程。

第一次 r3 Host 已正常通關，但驗證器錯將入口預期設為 60；該紀錄保留，修正預期後
另做 r3 Host 通關確認 80／60／60。另一次提供不存在 BND 目錄的啟動失敗也保留，未當通過。
成功 TCP 路線與 r2 Host 沒有重跑；恢復模式逐項重驗保留檔案，再補缺少的 Host 觀察。

## 驗證與界線

[機器可讀收據](hp-editor-validation.json) 綁定三版配套、四 TCP、兩個最終 Host、
三類出生 HP、畫面 SHA、Web 腳本、CSP／SRI、DLL、TRX 與隔離程序停止紀錄。
收據 SHA256：`f57e57c88dae216e0bc7f458238b52a9998d76033ecbdec8c72d1bc3552264be`。
三個 Release 建置零警告／錯誤，JavaScript 語法檢查與 **782/782 HappyPath** 通過，零失敗／略過。
這次 UI 修改以實際瀏覽器保存及交付驗證，沒有增加鏡像實作的單元測試。

私有重現工具：`start-hp-editor-inspection.py`、`check-hp-editor-delivery.py`、`audit-hp-editor.py`。
本機工作資料位於 `E:/Tartaros/workspace/outputs/hp-editor-workbench-20261123` 與
`E:/Tartaros/workspace/outputs/hp-editor-delivery-final-20261123`；原始資源、種子資料庫及現用服務不變。
僅自己的隔離 Host／Admin 被停止，沒有替換使用者服務。

`GAME_RUNTIME_OBSERVATION`：本批沒有指定 v2 人測結果。機關顯示、頭目增援、兩分支與
結果回村仍待人測；數值錯誤／邊界、重送、重連、併發、故障、安全與壓測仍依既有安排待測。
原生 MEF 容器、Client 自主生怪／完整 AI 移交沒有提高驗收狀態；其餘 MEF 功能仍分項追蹤。
