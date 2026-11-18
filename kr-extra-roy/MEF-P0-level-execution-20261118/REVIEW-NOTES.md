# 整合檢閱與驗證範圍

本頁記錄本輪八項 P0 分析的交叉檢閱重點。正式 RR、T01、Task owner 與 S00 的接受狀態仍依原台帳；本包不替任何正式工作線改判。

## 整合時核對及修正的內容

| 重點 | 本包採用的精確結論 | 詳細依據 |
|---|---|---|
| 使用者編號 | P0-3～8 對應 L03～08；P0-9 是 L10，P0-10 是 L13。 | [研究終點](acceptance-plan.json) |
| 生怪設定 | selector 29 寫 group `+90`，不寫 relation key `+9C`；共同 CMonster 類別不代表本地與封包初始化相同。 | [生怪報告](actors-combat/report.md) |
| 正移動速度 | 根整合另對原 BIN 的 `4D1E10..4D1F32` 與兩級分支表核對：selector 6 到 `4D1EB5`，value 使用 MOVSX；selector 29 到 `4D1F0B`。新正速度範圍需處理 `1..32767`。 | [原件證據](actors-combat/native-evidence.json) |
| 投射物畫面 | 原生飛行與資源鍵已找到；目前 Server 飛行規則不等於已有 0094／0000／001A 視覺 mapper。根報告與用途表均保留新 adapter／entity 生命期需求。 | [戰鬥能力契約](actors-combat/capability-contracts.json) |
| 真正清場 | 一般主線與一般副本都等全部敵人移除排送；一般副本另等擊倒經驗 pending 完成；功能場的 ReadyToReturn 範圍較窄。只把敵方飛行列入已證 gate。 | [執行契約](rules-scheduling/execution-contract.json) |
| 固定三輪 | 有限圖逐節點重建；同房不中斷三波用 reinforcements。作者 ID 要登錄相容入口，保留主線 override 限制。例子只有最終 Result，沒有憑空多出獎勵。 | [規則報告](rules-scheduling/report.md) |
| 時計與事件階段 | combat timestamp Add 與 scenario elapsed seconds 是不同計算法；正常位置／RegionEntered 觀察在 combat Poll 後。優化不能默默提前派送。 | [優化契約](rules-scheduling/optimization-contracts.json) |
| 真封口候選 | 檢查整個出口互動圈及必要怪／機關路徑；明示出口移位與半徑縮小。Client 半徑按 BIN 的實際浮點常數及存回值重算，表內 1.6 是近似。 | [幾何證據](gates-transitions/geometry-evidence.json)、[原件補證](gates-transitions/native-proof.md) |
| 門的外觀與碰撞 | 六模型有 state→motion／avatar；仍不命名哪個是開／關。額外 region 掃描不進所選移動回值，因此不把它當成可用物理門。 | [門與轉場](gates-transitions/report.md) |
| 清場劇情與出口重建 | 有 ClearScenes 或未預註冊出口時可走完整重建；全部預註冊且無該演出才只改 status。保留 003F seen-skip 的限制。 | [轉場契約](gates-transitions/contracts.json) |
| MEF 種類 | 12 類是可組合用途，包含 Server 規則／交易保存；不是 12 種官方檔案格式。121 binding 的原作用、4 stub、1 無有效 count 均保留。 | [用途表](MEF-TYPES.md)、[機讀分類](mef-types.json) |

三個子題分別檢閱根報告對其證據的轉述，根整合讀回各子題報告與關鍵證據。檢閱不以既有來源中的 PASS 字樣替代原件／固定來源重驗，也不把 Python 靜態投影寫成執行真正 Server typed loader。

## 可重跑驗證做了什麼

[根 verifier](verify_evidence.py) 先核固定 Git 來源、原件、共享指示與 28 個私有 Server 來源的 bytes／hash／blob，再核交付清單、JSON、Python 語法與本地文件連結。用途分類從固定 binding 輸入重建，八項進度與研究終點逐一核對。三個子題 verifier 各寫新的暫存收據，重新比對原生視窗、來源、作者規則、資源及幾何結果；整合結果保存在 [verification-result.json](verification-result.json)。

歷史 Markdown 的來源身分使用固定 Git object；實際 JSON、schema、helper 和原件仍要求內容一致。這允許更新本輪導航頁，同時不讓作者輸入或證據悄悄改變。

公開交付限定本分析包與兩個導航頁。沒有完整 BIN／STP、完整解包表或完整私有 C#；程式類檔案為本分析的離線 Python 工具及有界原件反組譯。來源原檔與正式關卡未修改。

上述 PASS 只支持有界來源、分析與交付可重現。新內容接入、Server adapter 實作、素材掛載、正常 Client 遊玩與效能量測分別保留在各項剩餘工作；沒有執行 Server、Client、Lua 或資料庫。
