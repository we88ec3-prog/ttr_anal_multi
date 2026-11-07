# v31 全角色技能優先：等級、特性、V與Tab

## 本次使用者要求

先處理所有角色技能，參考提供的四份播放清單與伊希莉亞1-35技能展示；使用者追加要求完成V切換、確認Tab作用，並明確指出「技能成長後可透過特性或技能等級改變呈現」。此要求優先於繼續村莊內容。泳池部分NPC不可接近已另外依使用者要求延後，沒有在本輪更動。

先前v30只有第1級／matrix0／Basis候選，不等於完整技能成長。本輪明確區分 learned Practice level、active數值level、Talent SkillScriptLevel、V charge tier、matrix配置，不能混用。

## 已落地與部署

私有main `2ca60bedbdf582ee506d4b54e3289ea00b9e7401`。72項HappyPath通過59秒、0失敗／略過，Release publish通過；本機時間2026-11-07 16:27啟用v31，PID32580。以當前loopback listener及v30 Host路徑核對後換版，SQLite先備份。換版後再次核對v31路徑、auth健康與HTTP實際189組配置。原Client v6／原資源未修改，規格pin及正式批准狀態不變。
Host DLL SHA256 `d248a95d95d784d63d2872ea0acf8ea5888a0364cf102e9a389aca329ad64122`；Network DLL `5b9ba1dd13dd917b1ddad58042f606741bc86dc83f9b3ccc691f965b38b89ab4`。原故事內容與泳池BND hash不變；未跑延後類測試。

第一次整合70通過／1失敗，因舊learned清單斷言未納入新增V與Tab Practice；修正測試預期後71通過。另加實際World V/Tab輸入列、中文名稱與成本、TCP matrix1/LV5接線後，最終72通過。最初非提升權限build只有0錯誤失敗，依本機既有環境使用核准執行後成功；不把它當程式通過證據。

## 已接入

- 九角色×七matrix×三tier，共189配置／945鍵槽；每角色跨matrix有27個distinct六鍵active。保留原matrix0的135欄位；名字來自既有台版active表。
- 1,448個精確成本row：Practice LevelData→SkillLevel TargetSkillID/Value→ActiveInfo對應level。測試頁獨立選learned level，0126與Server耗量同步；缺級不截斷、不猜成最高級。
- 原生有界證據閉合012C allowed matrix lists、012D兩selector setter；只在隔離lab允許0..6並發送選擇。這是測試授權，不是正式特性／任務解鎖。資料中的matrix內建Talent及前置需求亦有保留。
- V短放0x8為col7；prototype按當前col7與原始type7費用由tier0→1→2。索瑪／蘋果／舒博爾／露可／艾芬多絲使用HP，伊希莉亞MP，艾洛特／格芮妮／柯摩托SP。50／90是raw表候選，並非普通type1 cost getter已證規則。
- Tab0x10為col10「轉換角色進階技能」。lab交換兩matrix：頁面選中的matrix與0，若初始0則0／1；使用raw HP10、cooltime300/10秒候選。教學切角是不同context，不把戰鬥Tab泛稱角色切換。官方按鍵至selector的完整Server因果未知，候選使用已證的Client setter。
- 同一combat保留資源／敵人／deadline。冷卻以activeID而非按鍵索引保存，V／Tab只解鎖新active、不重送既有timer。特殊事件不當作物理移動快照，不重建舊強制停步問題。Crmd替代Z用其技能恢復時間，不硬套普攻連段350ms。

## 全角色覆蓋與限制

「可測」指動畫／成本候選，並非完整實戰技能。完整945槽中778有候選、167未開；去重後154種有候選、89種仍缺對應／多階段規則。

|角色|六鍵distinct技能|有動畫候選|仍未開|
|---|---:|---:|---:|
|索瑪|27|14|13|
|蘋果＆坦基|27|14|13|
|舒博爾|27|18|9|
|伊希莉亞|27|19|8|
|艾洛特|27|17|10|
|格芮妮|27|17|10|
|柯摩托|27|18|9|
|露可|27|18|9|
|艾芬多絲|27|19|8|

詳細逐技能／各matrix分布：[summary](../client-variants/20261107-all-matrices/summary.json)、[blocked rows](../client-variants/20261107-all-matrices/blocked-rows.json)。不能因擴成全角色清單就把所有技能標完成。

## 特性與呈現：仍為P0

已讀608個Talent SkillScriptLevel rows；例如伊希莉亞Practice50提高active30數值級，Talent1403另使scriptLevel2／3。原生cache以兩個不同欄位處理，SkillLevel加總、SkillScriptLevel取MAX。Basis／Average／Exper等確實有不同ASD→EFF資源，但哪個scriptLevel對哪個動畫、觸發段數／判定／位移仍未閉合。沒有把普通等級1-3/4-6或Talent level任意對應特效。

目前長按V threshold0x80及longrelease0x40有精確輸入證據，尚未完成氣發散動作、SP恢復量／節奏、有效時間、施技後回落與狀態清理。沒有因longrelease就自動清tier；也沒有憑相近拼字替89種技能指定動畫。完整技能成長／特性呈現**尚未完成**。

## 後續完成條件（依使用者優先序）

1. 89種未開技能逐一補動畫／多段對應；公開逐active清單，維持未確認，不用固定108/109兜底。
2. 將Talent的scriptLevel與呈現／段數／判定／位移建立可追溯規則；明確區分Client可確認資料與需Server重建的執行規則。不能假設一定有Client自主skill→motion分派。
3. 完成長按V、SP回復、charge消耗／時效；補Tab正式解鎖及兩組配置政策。現行lab候選不升正式。
4. 各技能傷害、治療、增益／異常、投射物／召喚、命中範圍及時點逐項實作。現有generic20/35/60傷害不是全技能完成證據；空場先驗動畫、資源與輸入，之後副本驗實戰。
5. 各角色×技能×等級／特性的人測結果分開記錄。合成通過、資源候選、原版／工作副本兼容與完整通關不得合併為同一驗收。

MEF重新搜尋仍依使用者原排程等Server至少60%，本輪沒有重掃或派影片比對給上班中的Web對話。

## 來源與驗收界線

[全矩陣資源候選](../client-variants/20261107-all-matrices/README.md)、[等級／Talent資料](../client-variants/20261107-skill-levels/README.md)、[原生等級讀取鏈](../client-variants/20261107-skill-level-dispatch/README.md)、[V/Tab與012C/012D有界契約](../client-variants/20261107-charge-skills/matrix-selector-contract.json)。來源Task報告中較早「setter未找到」按其當時範圍保留，以後續契約補充，不抹除歷史。

透過作者頁找到另外五個角色清單，九份各27部；[影片來源索引](../client-variants/20261107-all-matrices/video-references.json)。文字工具cache miss後使用瀏覽器，僅核對標題清單及少量示範畫面，**沒有聲稱已逐一看完243部**。影片版本與目前KR完全一致尚未證實，不能以播放清單數量相同當逐技能ID配對證明。

原EXE／STP／ASD／EFF／XML均不推Git，只保留metadata、來源hash、有限指令證據、重現工具及Server規劃。未升級Task native_complete、T01 FULL-PASS、APPROVED REQ或正式SPEC。v31實機短卡已送，結果PENDING_USER，送卡後繼續本文件與證據整合。
