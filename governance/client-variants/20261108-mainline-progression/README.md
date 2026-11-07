# 正常主線升級／結算缺口：來源核對

這是靜態Server實作與原始資料的風險核對，不是新的人測失敗，亦不以測試跳轉等級補足當正式升級。

[audit.json](audit.json)核對現行22條敘事任務的原始QuestInfo要求與30筆RewardsEtc。原／工作member同SHA5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60；與現行storyv34每條levelRaw／Town相符。19條任務要求超過prototype固定最高顯示等級5，第一條為Q120 level8。這是可接清單的來源門檻風險，不是宣稱已觀察Client每個role record或窮盡腳本內可能更新。

Server目前初始roster的Dword2A為1，World Rebuild固定發布Soma／其他starter5、Isilia2、Pipa1；只有明示debug跳轉套用任務最低顯示等級。敘事里程碑保存不實作角色EXP與升級；直接合成NPC意圖可通過route，但不代表原Client在正常level gate下會產生相同意圖。先前v12抵達馮德斯及v37操作的人測範圍保留，不擴張成整村合法結算／自然升級通過。

## 已知欄位與未知

原始type2獎勵只閉合Client PartyExp顯示、type4閉合Leeloo顯示；其他type保持原始域。金額、收件人、角色／團隊分配、倍數、升級曲線及實際發放adapter未由這些數值證明。沒有RewardsEtc的任務不能自動當零獎勵核准。

[角色資料界線](role-stats-boundary.json)確認5C／4D41A0的payload DWORD4/8/C→record50/58/54，及初始4D4150的DWORD31→record50；這仍未把三欄命名為EXP。level byte3→record8及5C後重算候選另有既有原生證據，不能從level writer直接推導EXP演算法。

本輪原件Table/CharUpgradeInfo.xml SHA156b98ea3aa966c9d3d3591071d9de3bb0db305dc69c2421cc72d5112e4603db為空根CHAR_UPGRADE_INFO。只表示這份member沒有曲線，不代表其他資料／原生程式不存在曲線。沒有為湊可玩進度自造經驗公式、將PartyExp當錢、填入未知DWORD或自動拉高正常等級。

## 接續門檻

1. T04／RR-0014沿已識別role record查有EXP標籤的HUD／角色UI與必要publication consumer。已有5C／roster store不重做全函式掃描。
2. S00明示party／role EXP及等級政策版本；若曲線僅屬官方後端未知，獨立提出Server重建方案，不冒充Client資源。
3. Quest合法目標／交付、獎勵權利、實際入帳、Client發布各自有提交點；先有正式結算條件才授予，敘事結束不自動叫PAID。
4. 正常全新帳號經原Client完成前置、自然達到level gate再進下一主線，與debug進度指定分別驗收。

原始XML／STP／DB不發布；只有選定metadata與唯讀工具。audit_progression.py --workspace-root E:/Tartaros/workspace可核對來源及現行內容；不操作遊戲、不修改角色資料或現行Host。
