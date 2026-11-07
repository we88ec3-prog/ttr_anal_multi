# Client 額外實體追隨控制：既有證據接續界線

這是舊分析的接續核對，不是新發現原生 MEF 或已完成敵方 AI。原件身份、9 個選定區段及4份既有反編譯來源的雜湊見 [metadata.json](metadata.json)。只核對選定綁定與資料流，未將整函式或 T13 升級 FULL-PASS。

## 已有的本地計算能力

1. S→C `000A` 的 `4AF920` 在本機識別值匹配且兩個實體 ID 不同的支線，呼叫控制器 virtual+8。
2. CSingleController／CFormationController 的這個槽均指向 `5451D0`。它將受控實體 ID、關聯實體 ID、零值組成8-byte項目，加入 controller+30 清單。
3. 既有 `5452C0` 遍歷清單，virtual+44→`546EF0` 計算到指定關聯實體的距離與方向，並依目前動作狀態限制修正輸入。原生距離常數為10／70；不是時間或已還原的攻擊規則。
4. 控制輸入由 C→S `000A` 批次發出。上下行同號命令的格式不同，不得套用同一 decoder。

因此「Client 只能被動播放，不能在本地計算行動」太絕對；這份鏈已能計算指定關係的追隨。另一方面，指定追隨對象不是自主尋敵，外發輸入也不等於 Client 有傷害最終裁決權。

## 尚未證明，不能直接部署

- 尚無一般敵方怪物實例證明它在正式副本被分配到這份關係清單。
- 未由這條鏈還原敵人選擇、仇恨、選招、命中、傷害／死亡裁決。
- 未建立 MEF 樣本→接收→解析→行為執行的關係，也未建立官方 Server／房主／P2P 權限。
- 不將 Server 的怪物 ID 任意填進分配封包來宣稱已恢復原生 AI；現行 Server authority 維持。

## RR-0013 下一個有效交界

一般怪物的決策生產者仍是研究目標。若從這條線接續，須提供「具體敵方怪物→關係分配資料／建立者→控制輸入」的實例或來源交界；若轉向技能／目標生產者，應從現有 writer／callback 接續。不要再次尋找已知的額外清單 writer、virtual+44綁定或 actor每幀派送者。

既有來源：本機 `anal/EXTRA-ACTOR-CONTROL.md`、`anal/ACTOR-UPDATE-PIPELINE.md`、`anal/CONTROL-AND-SKILL-SOURCE.md`。原報告保留，不改原 Task 結論。可重跑 `python -B verify.py --workspace-root E:/Tartaros/workspace`；此工具只核對本機原件與既有匯出，不操作遊戲，不傳封包。
