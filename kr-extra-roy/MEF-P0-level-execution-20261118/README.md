# P0-3～10：關卡 MEF 執行能力與內容閉合

日期：2026-11-18（Asia/Taipei）。工作分支：`extra/roy1`。本輪接續使用者指定的八個 P0 項目，並將目前 MEF 能力按玩家用途整理為可組合的類型。

| 使用者編號 | 前輪功能 ID | 本輪主題 | 詳細證據 |
|---|---|---|---|
| P0-3 | L03 | 生怪、world 身分與初始化 | [生怪／戰鬥](actors-combat/report.md) |
| P0-4 | L04 | 輸入、動作、HP、死亡與投射物 | [生怪／戰鬥](actors-combat/report.md) |
| P0-5 | L05 | 定時／順序增援與空場起步 | [規則與時計](rules-scheduling/report.md) |
| P0-6 | L06 | 波清、頭目與完整清場門檻 | [規則與時計](rules-scheduling/report.md) |
| P0-7 | L07 | 有限分支、重複展開與條件擴充 | [規則與時計](rules-scheduling/report.md) |
| P0-8 | L08 | 精確時計、延遲與派送次序 | [規則與時計](rules-scheduling/report.md) |
| P0-9 | L10 | 可封路候選、模型與碰撞界線 | [門與轉場](gates-transitions/report.md) |
| P0-10 | L13 | 出口意圖、換圖及點集重建 | [門與轉場](gates-transitions/report.md) |

## 閱讀入口

- [REPORT.md](REPORT.md)：整合結論、新證據、舊概括的精確收斂及開發落點。
- [P0-PROGRESS.md](P0-PROGRESS.md)：八項進度、已閉合內容與仍需開發／整合的部分。
- [MEF-TYPES.md](MEF-TYPES.md)：12 類玩家用途與四條執行路線；不是原生檔案格式分類。
- [acceptance-plan.json](acceptance-plan.json)：本輪開始前建立的靜態研究終點與舊功能 ID 對照。
- [mef-types.json](mef-types.json)：121 個正常 binding 的主要用途映射，保留 4 個 stub 及無有效 count 的接口。
- [SOURCE-NOTES.md](SOURCE-NOTES.md)：來源、版本、私有 Server 原碼與原件的使用界線。
- [REVIEW-NOTES.md](REVIEW-NOTES.md)：整合時修正的精確條件、交叉檢閱與靜態驗證範圍。
- [verification-result.json](verification-result.json)：來源與各子題的可重跑驗證結果。

## 方向與完成狀態

MEF 是 Server 開發的一部分。現有 scenario、MonsterBehavior 及交易／保存服務是可沿用基礎；合適的本地演出與原生更新交給 Client。研究終點是可實作功能鏈、精確條件及具體剩餘接口，不等待官方 `.mef` 格式。

本包保存原件補證、實際 Server 原碼的有界分析、自製內容候選與接口契約。Client 原生事實、現有 Server 實作、作者設計、實際遊玩是不同證據層次；普通 Client 自主敵方 AI、通用事件到 Lua、真正動態門碰撞等尚未閉合的接口不因分類表而升格。

完整原始 BIN／STP、完整解包資源及私有 Server 原碼不在本包。沒有執行 Client、Lua、Server、資料庫或部署，也沒有改動正式 RR／owner／T01／S00 狀態。

## 重跑

使用相符的分析 repo、唯讀原件與指定版本 Server 來源目錄：

```sh
python -B kr-extra-roy/MEF-P0-level-execution-20261118/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --server-sources /absolute/path/server-source-snapshot \
  --receipt /absolute/path/verification-result.json
```

`--receipt` 指向外部位置可保留本包原收據。只有來源／分析工具被執行；不啟動目標程式。
