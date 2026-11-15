# 馮德斯 E 級鍊石材料路線

## 原表與 Server 暫定掉落

KR `Product.xml` 與 `ItemTable2.xml` 核對 Product 281～284 分別對到同號 Item，堆疊上限 255。台版 Product 表分別稱復仇、知識、自然、守護的符石。`ItemRandomCapsule.xml` 中，Item 12714（Product 12981）及 Item 15758（Product 17042／18240）的輸出表含上述四種符石。直接核對同版普通貨單與普通任務物品報酬，未見這兩組箱。反查箱子再由哪些箱提供，前者見於台版 Luckybox 條目，後者見於飾品幸運箱和台版泳池時裝箱。此表證明箱內候選品項，早期一般狩獵場的原廠掉落表仍待確認。 [原表查核與版本](EARLY-EQUIPMENT-DISMANTLE.md)

為讓早期單人流程可以實際製作，Server 暫定下列規則。重複正常入場可再取得。普通與輪替 Case 沿用同一數量。

| Stage／Case | 最終圖／頭目／PRE | 新增每場掉落 |
|---|---|---|
| 462／693、694 | 3438／1086／1 | 復仇的符石 Product 281 ×1 |
| 463／695、696 | 3448／1083／1 | 知識的符石 Product 282 ×1 |
| 464／697、698 | 3459／1084／1 | 自然的符石 Product 283 ×1、守護的符石 Product 284 ×1 |

以終點既有 Product 183 頭目掉落為定位，取相同頭目、PRE、增援群及掉落模型。復活卷軸沿用原有規則。新增的材料使用 Visual 162，普通背包 metadata 欄位皆為 0，需走到落點按 Space，持久化由既有掉落認領交易處理。路線中途怪、其他村莊、教學及單人劇情副本維持各自的掉落設定。此為 Server 自訂經濟規則，原生 MEF 及原廠掉率待查。

驗收 Host 同時選 `-IncludeCombatGrowth -IncludeBluetreeHuntingGround` 時啟用 `TARTAROS_LOCAL_REFINE_GLYPH_DROPS`，另使用既有普通裝備實例鍵支援分解。健康頁以各 Case 報告實際規則。使用預設單案或未開啟設定的 Host 可重現既有掉落收據。 [前兩村一般副本配置](PHINDOS-STAGE-ONE.md)

## 從拾取到製作

正常完成三個狩獵場並拾取四種符石。取得 40 顆結晶石的一條路徑是以正常貨單在馮德斯鐵匠購買 10 件 Product 10848，每件 910 LeeLoo。到 NPC 10015 依序分解，每件給 4 顆 Product 185 與 1 份 Product 18012 碎片。於同 NPC 確認製作 Product 151 一批，另扣 800 LeeLoo、40 顆結晶石與四種符石各一件，保存 10 顆成品。購買、分解與製作共花 9,900 LeeLoo，碎片保留。 [裝備分解](EARLY-EQUIPMENT-DISMANTLE.md) · [製作規格](PHINDOS-REFINE-STONE-CRAFT.md)

離線驗證在 `--fresh-alsmeer-journey` 加 `--check-refine-materials`，使用原版 BND、三個馮德斯狩獵場與正式貨單。先走新帳號入口、正常狩獵場和 Q144，再用該帳號拾得的材料及任務所得回訪馮德斯，走完整買入、分解、製作及正常重登入場。實機待 EQ-B05，鍊石成品可接 EQ-B06 驗證普通 +1。 [批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

兩個全新帳號分別走一般 Case 693／695／697 與輪替 Case 694／696／698。兩途均完成 Q144 並保存於圖 199、Lv.19／333,742 EXP。開始製作前已拾得 281×43、282×15、283×1、284×1，離線腳本以完整普通任務旅程反覆跑狩獵場，因此前兩種累計多於一顆。各分解 10 件、製作 1 批，核對餘額減 9,900、成品 10、碎片 10、材料扣除與重登保存。

| 原版 BND 離線收據 | SHA-256 |
|---|---|
| 一般路線 | `84d2875b1327a5ba8aa0b741f48fb7b12b8985738132a559b493032f9e85bdca` |
| 輪替路線 | `eb45c23338af578b4d6781e2a43967c8b166e836c76eba386250b944c7534fcc` |
