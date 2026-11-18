# 關卡相關 MEF 功能：本輪分析完成與開發交接

**日期：2026-11-18｜工作分支：extra/roy1｜分析基準：09799b117f01e577be56dee3e909e1cde25b855f。**

本輪完成關卡相關 **20 類功能**的現有能力、執行位置、實際內容、生命週期、缺項與優化分析。Server 提供和執行的 MEF 規則也算 MEF；能交給 Client 既有能力的本地演出優先下放。沿用現有配置與服務即可開發，不強制另造格式，也不等待官方 `.mef` 復原。

## 建議閱讀順序

1. [玩家版：各項進度、缺少什麼與改善方向](PLAYER-PROGRESS.md)
2. [完整整合分析與證據邊界](REPORT.md)
3. [開發順序與可驗收交付](DEVELOPMENT-PLAN.md)
4. [20項機讀功能狀態](feature-status.json)／[9項優化計畫](optimization-plan.json)／[本輪分析狀態](status.json)

## 本輪新增的實質成果

- 重新稽核67份實際 scenario：86定義出現、399節點出現，schema 與本輪有限圖／旗標依賴檢查通過；這些包含候選、歷史與示範，不能稱成86個可玩副本。
- 對118個 MapID／74個原件 BND 核1763個配置中心：10個舊範例阻擋點已定位，另有13個可重現通過的具體修正候選。
- 證明Q119三份屏障候選可繞行；出口使用資格仍受旗標控制。點可用、光效、3D門和碰撞不混為一談。
- 閉合原生 `CSL.scn` seen紀錄的保存／讀回：一次／Client epoch不足以保證重播，003F也可能只是原生跳過的回報。
- 接通Q119清場演出後重建／完整點集、不同倒數原點、結算／保存時點；新增確認所選招募視窗的非教學按鈕送0033，保留教學例外。

發布前另核對較新main的復活、容量、消耗與同登入關卡交接成果，見[最新來源補註](LATEST-MAIN-UPDATE.md)；原67檔稽核基準保持不變。

## 四個分析子題

| 子題 | 完整報告 | 主要可重驗產物 |
|---|---|---|
| 規則、敵群、波次、旗標、分支、時計 | [rules-waves](rules-waves/report.md) | 18功能、9 signals、67檔圖／條件稽核、7優化契約 |
| 地圖、機關、出口、屏障、陷阱、巡邏 | [space-mechanisms](space-mechanisms/report.md) | BND連通性、13點修正候選、18步繞路、4 consumer |
| 清場、跨圖延續、結果、獎勵、存檔、退出 | [outcomes-continuity](outcomes-continuity/report.md) | 26轉移、3種結算模式、15正常配置路線、招募分支 |
| 有限演出、重播、Q119具體交接 | [finite-handoff](finite-handoff/report.md) | 9原件窗口、3實際配置變體、5 scene、seen持久化 |

## 完成的層次

分析與證據可重驗；現有實作依據有明確引用。**本輪沒有新增Server／Client部署或玩家通關驗收。** 原本已有的生怪、戰鬥、背包、結算、保存、復活與冷卻等功能繼續復用，不列成從零開發。實際尚缺的接口、內容修正及可見操作逐項列在玩家版和開發計畫。

```bash
python -B kr-extra-roy/MEF-level-functional-closure-20261118/verify_evidence.py --repo /path/to/ttr_anal_multi --sources /path/to/project_sources
```

整包重驗會檢查來源／原件身份、封存檔案、內部連結、20項功能／9項優化對照，以及重新執行四個只讀分析 verifier。收據：[verification-result.json](verification-result.json)。來源：[source-manifest.json](source-manifest.json)；交付清單：[artifact-manifest.json](artifact-manifest.json)；獨立覆核：[REVIEW-NOTES.md](REVIEW-NOTES.md)。本包不是正式RR／FULLPASS／部署宣告。
