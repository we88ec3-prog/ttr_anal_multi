# 發布前最新 main 來源核對

發布前 fetch 發現 main 由 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa` 更新至 **`7344eeb65198e2dd61684b66cf811021765ed8f5`**。本輪67份scenario及原件分析仍固定在extra/roy1的 `09799b117f01e577be56dee3e909e1cde25b855f`；以下另以最新main的精確Git物件核對，沒有混成新部署，也沒有把main合併進工作分支。

## 與關卡相關、應直接復用的較新成果

| 新紀錄 | 對本輪MEF規劃的更新 | 仍須保留的界線 |
|---|---|---|
| 付費完全復活Product184的跨模組正常串接 | 買入、領取、穿容量時裝、背包／快捷復活、保存及同場續戰已有兩條離線合成證據；不重列從零開發 | 沒有新增Client、TCP或部署；死亡懲罰、評級、Action3／23、SkillCast437視聽與指定v2仍缺 |
| 已穿時裝的SP／MP容量 | 較新候選已把逐件容量帶入角色面板、戰鬥建立、換圖延續、回復與卸裝封頂；既有延續應以實際容量一致為前提 | 864件所選Item的有限集合與相容服策略，不代表全部版本／套裝公式完成；v2面板／HUD待驗 |
| 回復書與CP書 | 100%回復、消耗、背包／快捷總量與跨格保存已有接線；共用冷卻群但每次ready_at依商品秒數 | 不把CP書1秒套到完全復活4秒，也不以畫面倒數替代持久冷卻 |
| 技能熟練度書與餘額 | 道具熟練度入帳、後續學習、登入回填已有證據；standalone快照已同時填Garnet，舊非零Garnet略過限制已解除 | 角色EXP、戰鬥SP、CP、熟練度仍分開；指定v2提示／面板待驗，其他standalone欄位界線保留 |
| RAID1後接一般狩獵場教學 | 較新離線紀錄已補同一次登入：打完挑戰回廣場，再建隊進Stage465；Q2852場景條件與持久進度有交接依據 | 這是較新來源的既有離線紀錄，不是本輪新遊玩；實際動作／提示／正常回村交付仍待SK-P11 |

來源固定於上述main commit：[完全復活專題核對](outcomes-continuity/latest-main-update.md)、[容量](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7344eeb65198e2dd61684b66cf811021765ed8f5/design/scenario-content/CASH-EQUIPMENT-RESOURCE-CAPACITY.md)、[消耗品](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7344eeb65198e2dd61684b66cf811021765ed8f5/design/scenario-content/CASH-SHOP-CONSUMABLES.md)、[熟練度書](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7344eeb65198e2dd61684b66cf811021765ed8f5/design/scenario-content/CASH-SKILL-MASTERY-BOOKS.md)、[技能／同登入交接](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7344eeb65198e2dd61684b66cf811021765ed8f5/design/runtime-content/SKILL-PRACTICE-PROTOCOL.md)。root新增5個精確文檔pin，完全復活分題另保存4個pin（含未變的入口範圍對照），均有blob、bytes、SHA。

## 不能因新紀錄消失的缺項

主線倒地退出按鈕／請求、普通副本內實際離隊UI、戰鬥中途永久checkpoint、真正物理門與Client碰撞、新有限演出的有效重播政策仍按本包各自契約處理。較新完全復活收據是一般狩獵場adapter／SQLite合成；它沒有證明Scenario mode2背包雙擊原生分支，也沒有把所有死亡懲罰效果閉合。

## 執行排程

最新 [S00批次表](https://github.com/we88ec3-prog/ttr_anal_multi/blob/7344eeb65198e2dd61684b66cf811021765ed8f5/design/testing/S00-CONTENT-BATCH-TESTS.md)明列CS系列已備妥待集中排程，**實機與換版仍暫停**。本包維持只讀分析／Git交付，不啟動Client、Server、目標Lua或新部署。日後有可執行排程時，仍先沿既定正常旅程，再比較工作量；本輪不擴張待測項。

這次 freshness review 也確認所觀察main差異沒有改動AGENTS、正式Task派工或共用指示；新增商城細節只採與關卡交接有關部分。來源身份見[source-manifest.json](source-manifest.json)。
