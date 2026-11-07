# v39準備：後續主線共用AI資料接線

## 問題與修改

v38的外部MonsterBehavior設定僅透過PhindosBridge交給Map191/192；後續主線InitializeStoryNode未傳behavior，仍採embedded預設。因此即使改外部設定，也不會影響後續主線遭遇。
新增可選node.aiProfile，預設legacy-melee-v1；Host把同一已核SHA的catalog交入story configuration，啟動時逐node解析，World進場／劇情後重建均使用該profile。診斷回報catalog SHA及目前node選用名稱。
[資料契約](../../design/runtime-content/STORY-AI-PROFILE-CANDIDATE.md)供其他Server實作者使用；這是明示Server候選，不改Client，不新增MEF傳輸／原生parser，也不把所有怪物改成Client決策。
現行storyv34、任務／地圖／出生位置／角色／AIJSON與各SHA均不改。主線保存版本、舊歷史及新帳號流程保持。

## 檢核與待測

初次整批100項為99通過1失敗：新fixture沒有提供已完成教學的角色2，ApplyProgressDebug正確拒絕；補齊正常前置，未放寬production保護。其後該整合案例單獨通過141ms，最終整批100項Category=HappyPath通過50秒，0失敗／略過。
新案例不只是catalog roundtrip：走NPC→劇情→編隊→進場劇情重建，再確認HP90及命中後血條3333、指定怪物motion108、玩家受5點傷害的血條9900，避免Host／World接線被漏掉仍顯示綠燈。另一案例覆蓋既有33個node缺欄位時的預設相容。
這只覆蓋共用AI參數接線。逐物種AI、事件／波次、生怪安全距離、原生MEF與87項技能映射仍未完成。
v38短卡仍待回，這批先建置／上Git，不為未改預設數值的接線工作中斷使用者當前測試。啟用與實機驗收另記，不把程式已準備當已部署。
