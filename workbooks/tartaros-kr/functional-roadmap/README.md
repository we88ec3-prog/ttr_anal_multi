# Tartaros KR 功能開發規劃

主要入口：[00_開發功能總表.xlsx](00_開發功能總表.xlsx)。

2026-11-13：已同步正常一人建隊進村、原生 .mef 研究界線、v96a～v99 關卡與怪物後端，以及村莊主線、技能和經濟功能進度。開發子步驟與工作副本人測各自統計；06 測試驗收收錄 8 項關卡待測、另列建隊進村及 v99 投射物未開放的人測。見 [06_測試驗收.xlsx](../06_測試驗收.xlsx) 與 [同步紀錄](../update-history/20261113-s00-v96a-v99.json)。

2026-11-07：v34先接爾勒梅斯村Q133～144，90項正流程合成通過，正式結算與人測仍未完成。保留章節編排／ID：ST02的Q131／132為進村前導，Q133～142屬本村；Q143／144列在ST03但仍是本村出村段，Q65才接第三村。ST02/ST03已回填候選程式及待測界線，總表重新彙整，未增加人測通過。銀行等後續功能未開發。

這是依使用者要求建立的功能導向規劃：1份總表、93份功能檔。各功能檔第一張是功能總表，後續每個子功能各一張頁面。村主線依章節列任務清單，每個任務各有接取、逐段劇情、目標、結束、獎勵、保存及換場等步驟。

## 怎麼看與更新

1. 開總表，查看每個功能的開發子項、已實作數、完成度、人測項目與通過率；右側「開啟功能表」是相對檔案連結，請整套下載並保持同資料夾。
2. 各功能檔第一張「功能總表」列子功能清單與進度。點名稱開啟對應頁，例如ST01第一個任務是Quest15，ST02列第2村12個章節任務。
3. 在子頁黃色的「開發狀態」「驗證結果」更新真實結果。頁內與該功能總表的公式會即時重算；驗收列不列入開發分母。
4. 跨檔總表是最近一次彙整快照，須執行`tools/refresh_master.mjs`讀取各檔後更新；不假設93份外部工作簿永遠即時連動。
5. 任務清單數量、名稱、步驟或規劃範圍變更時保留ID，先更新規劃及合併既有進度，勿刪掉整份重建。建立器拒絕覆寫既有工作簿；更新器只動總表統計與時間，保留人工備註。

## 進度定義

- 開發完成度＝已實作的開發步驟／目前列出的開發步驟。未分析、分析中、待開發、開發中皆不算已實作。
- 人測通過率＝明確標為「通過」的工作副本人測項目／已列人測項目。合成通過、部分通過、待改善、原版驗收皆不混算。
- 各層以子步驟數加總，不平均百分比。這是目前拆分粒度的子項比例，不是工時、剩餘天數或原版完整度估算；加入待分析內容會改變分母。
- 初版的已實作子項只依已提交候選程式與既有測試登錄，不表示已部署。人測來源是指定修改工作副本，原版Client仍未驗收。
- 同一完整教學回報可支援多個明確子項；19個人測通過子項不是19次獨立遊玩，也不能與舊06表的8個較粗HP項目相加。

## 收錄範圍與仍未知的部分

- 共用系統：帳號登入、選服頻道、冒險團角色、新手主線、廣場、村莊切換、組隊、戰鬥、怪物AI、物品背包、裝備、倉庫交易、商店製作貨幣、一般任務、劇情、聊天好友、公會、挑戰副本、對戰排名、稱號外觀及Server營運。
- 21個TYPE1村落／區域各有主線、副本、怪物三份功能檔。村序號是規劃排序，不等於TownID；Town5是廣場。其他公共區域由廣場／公會／場景系統承接。
- 主線490筆依SceneList章節成員列出；第1村9筆、第2村12筆。清單順序不是已證實遊玩順序；Town1的77筆全部任務不會全部冒充主線。一般支線目前列共用服務與各村內容盤點，尚未把全QuestInfo當全部已確認待實作主線。
- 9位角色依CharSkill列出325筆技能引用，每個技能一頁，級別留在同一技能範圍。未確認繁中譯名保留原名／ID，不猜正式名稱。
- 副本502筆為Quest.field與Case.STAGE建立的候選；怪物3259筆為這些候選Cluster引用的Actor分類1記錄，跨區可重複，不是3259種唯一怪物。未閉合283個精確資源路徑（300次引用），保留在plan.json，不推定Client缺檔或官方傳檔機制。
- 這份表完整列出本次目前規劃，並非宣稱原版所有功能、封包、所有支線／活動／怪物已枚舉。未知的Server規則及Client必需介面仍分別補設計／補證。
- 非正流程、重登、競態、故障、安全、壓測等只列後續，未在建立工作簿時執行。

## 來源與可重現資料

原始Table載體SHA256：`09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
原始Field載體SHA256：`18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`。
逐member SHA、任務／技能／關卡來源、候選與未知見`plan.json`。不包含原始STP、Client或私人Server程式。

初版開發狀態參考私有Server提交`1473173883b83c7a456e7816470273e81664972a`；人測為v10 `cd2a7bc70f3cfb92602628137bf65c5df81b0eb2`。
[人測證據](https://github.com/we88ec3-prog/ttr_anal_multi/blob/2d2fdc09249a2a594ff379eba332ebbebb58e9c8/governance/s00-iterations/S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)、[合成候選證據](https://github.com/we88ec3-prog/ttr_anal_multi/blob/2d2fdc09249a2a594ff379eba332ebbebb58e9c8/governance/s00-iterations/S00-20261102-SQUARE-NPC-INTERACTION.md)。未提交、未測試的第二段劇情候選未登為完成。

`verification.json`逐頁核對4748個子頁、45500個步驟與所有層級快取統計；`refresh-verification.json`記錄在拋棄式副本修改開發與人測狀態、跨檔更新、保留人工備註及不更動正式檔的驗證。原生超連結另經目標存在性核對；未以Excel桌面逐一點擊或執行遊戲。

## 維護工具

使用Codex bundled Node與`@oai/artifact-tool`，將tools中的mjs與add_navigation.py複製到本次執行目錄，該目錄的node_modules junction指向bundled依賴；勿修改依賴目錄。

```powershell
& '<bundled node.exe>' '<執行目錄>\refresh_master.mjs' `
  '<functional-roadmap 絕對路徑>' '<bundled python.exe>'
python .\tools\verify_workbooks.py .
```

首次建立流程：prepare_plan.py唯讀核對原始資源並產生新plan；build_workbooks.mjs建立尚不存在的檔案；add_navigation.py加原生連結；verify_workbooks.py獨立檢查。引擎的HYPERLINK雖有說明但未實作，故導覽使用原生OOXML超連結，不留錯誤公式。後續只更新既有檔案，不因本工具重設人工進度。

## 功能檔索引

| 功能 | 子功能／內容項目 | 檔案 |
| --- | ---: | --- |
| 帳號與登入 | 5 | [SYS01](SYS01_%E5%B8%B3%E8%99%9F%E8%88%87%E7%99%BB%E5%85%A5.xlsx) |
| 選服與頻道切換 | 5 | [SYS02](SYS02_%E9%81%B8%E6%9C%8D%E8%88%87%E9%A0%BB%E9%81%93%E5%88%87%E6%8F%9B.xlsx) |
| 冒險團與角色 | 7 | [SYS03](SYS03_%E5%86%92%E9%9A%AA%E5%9C%98%E8%88%87%E8%A7%92%E8%89%B2.xlsx) |
| 新手任務主線 | 17 | [TUT](TUT_%E6%96%B0%E6%89%8B%E4%BB%BB%E5%8B%99%E4%B8%BB%E7%B7%9A.xlsx) |
| 廣場進入與互動 | 6 | [SYS04](SYS04_%E5%BB%A3%E5%A0%B4%E9%80%B2%E5%85%A5%E8%88%87%E4%BA%92%E5%8B%95.xlsx) |
| 村莊切換與場景 | 7 | [SYS05](SYS05_%E6%9D%91%E8%8E%8A%E5%88%87%E6%8F%9B%E8%88%87%E5%A0%B4%E6%99%AF.xlsx) |
| 組隊與多人副本 | 9 | [SYS06](SYS06_%E7%B5%84%E9%9A%8A%E8%88%87%E5%A4%9A%E4%BA%BA%E5%89%AF%E6%9C%AC.xlsx) |
| 副本戰鬥共用 | 15 | [SYS07](SYS07_%E5%89%AF%E6%9C%AC%E6%88%B0%E9%AC%A5%E5%85%B1%E7%94%A8.xlsx) |
| 怪物行動基礎 | 10 | [SYS08](SYS08_%E6%80%AA%E7%89%A9%E8%A1%8C%E5%8B%95%E5%9F%BA%E7%A4%8E.xlsx) |
| 物品背包與掉落 | 9 | [SYS09](SYS09_%E7%89%A9%E5%93%81%E8%83%8C%E5%8C%85%E8%88%87%E6%8E%89%E8%90%BD.xlsx) |
| 裝備與能力 | 8 | [SYS10](SYS10_%E8%A3%9D%E5%82%99%E8%88%87%E8%83%BD%E5%8A%9B.xlsx) |
| 倉庫與交易 | 7 | [SYS11](SYS11_%E5%80%89%E5%BA%AB%E8%88%87%E4%BA%A4%E6%98%93.xlsx) |
| 商店製作與貨幣 | 8 | [SYS12](SYS12_%E5%95%86%E5%BA%97%E8%A3%BD%E4%BD%9C%E8%88%87%E8%B2%A8%E5%B9%A3.xlsx) |
| 一般任務共用 | 9 | [SYS13](SYS13_%E4%B8%80%E8%88%AC%E4%BB%BB%E5%8B%99%E5%85%B1%E7%94%A8.xlsx) |
| 劇情動畫共用 | 8 | [SYS14](SYS14_%E5%8A%87%E6%83%85%E5%8B%95%E7%95%AB%E5%85%B1%E7%94%A8.xlsx) |
| 聊天好友與社交 | 7 | [SYS15](SYS15_%E8%81%8A%E5%A4%A9%E5%A5%BD%E5%8F%8B%E8%88%87%E7%A4%BE%E4%BA%A4.xlsx) |
| 公會 | 7 | [SYS16](SYS16_%E5%85%AC%E6%9C%83.xlsx) |
| 挑戰與特殊副本 | 7 | [SYS17](SYS17_%E6%8C%91%E6%88%B0%E8%88%87%E7%89%B9%E6%AE%8A%E5%89%AF%E6%9C%AC.xlsx) |
| 對戰與排名 | 6 | [SYS18](SYS18_%E5%B0%8D%E6%88%B0%E8%88%87%E6%8E%92%E5%90%8D.xlsx) |
| 稱號收藏與外觀 | 6 | [SYS19](SYS19_%E7%A8%B1%E8%99%9F%E6%94%B6%E8%97%8F%E8%88%87%E5%A4%96%E8%A7%80.xlsx) |
| 資料保存與營運 | 9 | [SYS20](SYS20_%E8%B3%87%E6%96%99%E4%BF%9D%E5%AD%98%E8%88%87%E7%87%9F%E9%81%8B.xlsx) |
| 第01村馮德斯主線 | 9 | [ST01](ST01_%E7%AC%AC01%E6%9D%91%E9%A6%AE%E5%BE%B7%E6%96%AF%E4%B8%BB%E7%B7%9A.xlsx) |
| 第01村馮德斯副本內容 | 9 | [DG01](DG01_%E7%AC%AC01%E6%9D%91%E9%A6%AE%E5%BE%B7%E6%96%AF%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第01村馮德斯怪物 | 45 | [MO01](MO01_%E7%AC%AC01%E6%9D%91%E9%A6%AE%E5%BE%B7%E6%96%AF%E6%80%AA%E7%89%A9.xlsx) |
| 第02村Town2主線 | 12 | [ST02](ST02_%E7%AC%AC02%E6%9D%91Town2%E4%B8%BB%E7%B7%9A.xlsx) |
| 第02村Town2副本內容 | 12 | [DG02](DG02_%E7%AC%AC02%E6%9D%91Town2%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第02村Town2怪物 | 61 | [MO02](MO02_%E7%AC%AC02%E6%9D%91Town2%E6%80%AA%E7%89%A9.xlsx) |
| 第03村Town3主線 | 17 | [ST03](ST03_%E7%AC%AC03%E6%9D%91Town3%E4%B8%BB%E7%B7%9A.xlsx) |
| 第03村Town3副本內容 | 18 | [DG03](DG03_%E7%AC%AC03%E6%9D%91Town3%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第03村Town3怪物 | 110 | [MO03](MO03_%E7%AC%AC03%E6%9D%91Town3%E6%80%AA%E7%89%A9.xlsx) |
| 第04村Town4主線 | 16 | [ST04](ST04_%E7%AC%AC04%E6%9D%91Town4%E4%B8%BB%E7%B7%9A.xlsx) |
| 第04村Town4副本內容 | 18 | [DG04](DG04_%E7%AC%AC04%E6%9D%91Town4%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第04村Town4怪物 | 167 | [MO04](MO04_%E7%AC%AC04%E6%9D%91Town4%E6%80%AA%E7%89%A9.xlsx) |
| 第05村Town6主線 | 18 | [ST05](ST05_%E7%AC%AC05%E6%9D%91Town6%E4%B8%BB%E7%B7%9A.xlsx) |
| 第05村Town6副本內容 | 18 | [DG05](DG05_%E7%AC%AC05%E6%9D%91Town6%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第05村Town6怪物 | 160 | [MO05](MO05_%E7%AC%AC05%E6%9D%91Town6%E6%80%AA%E7%89%A9.xlsx) |
| 第06村Town9主線 | 14 | [ST06](ST06_%E7%AC%AC06%E6%9D%91Town9%E4%B8%BB%E7%B7%9A.xlsx) |
| 第06村Town9副本內容 | 15 | [DG06](DG06_%E7%AC%AC06%E6%9D%91Town9%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第06村Town9怪物 | 115 | [MO06](MO06_%E7%AC%AC06%E6%9D%91Town9%E6%80%AA%E7%89%A9.xlsx) |
| 第07村Town10主線 | 26 | [ST07](ST07_%E7%AC%AC07%E6%9D%91Town10%E4%B8%BB%E7%B7%9A.xlsx) |
| 第07村Town10副本內容 | 30 | [DG07](DG07_%E7%AC%AC07%E6%9D%91Town10%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第07村Town10怪物 | 200 | [MO07](MO07_%E7%AC%AC07%E6%9D%91Town10%E6%80%AA%E7%89%A9.xlsx) |
| 第08村Town11主線 | 24 | [ST08](ST08_%E7%AC%AC08%E6%9D%91Town11%E4%B8%BB%E7%B7%9A.xlsx) |
| 第08村Town11副本內容 | 27 | [DG08](DG08_%E7%AC%AC08%E6%9D%91Town11%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第08村Town11怪物 | 159 | [MO08](MO08_%E7%AC%AC08%E6%9D%91Town11%E6%80%AA%E7%89%A9.xlsx) |
| 第09村Town12主線 | 35 | [ST09](ST09_%E7%AC%AC09%E6%9D%91Town12%E4%B8%BB%E7%B7%9A.xlsx) |
| 第09村Town12副本內容 | 32 | [DG09](DG09_%E7%AC%AC09%E6%9D%91Town12%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第09村Town12怪物 | 217 | [MO09](MO09_%E7%AC%AC09%E6%9D%91Town12%E6%80%AA%E7%89%A9.xlsx) |
| 第10村Town13主線 | 45 | [ST10](ST10_%E7%AC%AC10%E6%9D%91Town13%E4%B8%BB%E7%B7%9A.xlsx) |
| 第10村Town13副本內容 | 42 | [DG10](DG10_%E7%AC%AC10%E6%9D%91Town13%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第10村Town13怪物 | 279 | [MO10](MO10_%E7%AC%AC10%E6%9D%91Town13%E6%80%AA%E7%89%A9.xlsx) |
| 第11村Town15主線 | 39 | [ST11](ST11_%E7%AC%AC11%E6%9D%91Town15%E4%B8%BB%E7%B7%9A.xlsx) |
| 第11村Town15副本內容 | 34 | [DG11](DG11_%E7%AC%AC11%E6%9D%91Town15%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第11村Town15怪物 | 191 | [MO11](MO11_%E7%AC%AC11%E6%9D%91Town15%E6%80%AA%E7%89%A9.xlsx) |
| 第12村Town17主線 | 42 | [ST12](ST12_%E7%AC%AC12%E6%9D%91Town17%E4%B8%BB%E7%B7%9A.xlsx) |
| 第12村Town17副本內容 | 40 | [DG12](DG12_%E7%AC%AC12%E6%9D%91Town17%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第12村Town17怪物 | 240 | [MO12](MO12_%E7%AC%AC12%E6%9D%91Town17%E6%80%AA%E7%89%A9.xlsx) |
| 第13村Town18主線 | 23 | [ST13](ST13_%E7%AC%AC13%E6%9D%91Town18%E4%B8%BB%E7%B7%9A.xlsx) |
| 第13村Town18副本內容 | 25 | [DG13](DG13_%E7%AC%AC13%E6%9D%91Town18%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第13村Town18怪物 | 165 | [MO13](MO13_%E7%AC%AC13%E6%9D%91Town18%E6%80%AA%E7%89%A9.xlsx) |
| 第14村Town19主線 | 24 | [ST14](ST14_%E7%AC%AC14%E6%9D%91Town19%E4%B8%BB%E7%B7%9A.xlsx) |
| 第14村Town19副本內容 | 23 | [DG14](DG14_%E7%AC%AC14%E6%9D%91Town19%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第14村Town19怪物 | 148 | [MO14](MO14_%E7%AC%AC14%E6%9D%91Town19%E6%80%AA%E7%89%A9.xlsx) |
| 第15村Town20主線 | 51 | [ST15](ST15_%E7%AC%AC15%E6%9D%91Town20%E4%B8%BB%E7%B7%9A.xlsx) |
| 第15村Town20副本內容 | 48 | [DG15](DG15_%E7%AC%AC15%E6%9D%91Town20%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第15村Town20怪物 | 296 | [MO15](MO15_%E7%AC%AC15%E6%9D%91Town20%E6%80%AA%E7%89%A9.xlsx) |
| 第16村Town21主線 | 11 | [ST16](ST16_%E7%AC%AC16%E6%9D%91Town21%E4%B8%BB%E7%B7%9A.xlsx) |
| 第16村Town21副本內容 | 16 | [DG16](DG16_%E7%AC%AC16%E6%9D%91Town21%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第16村Town21怪物 | 103 | [MO16](MO16_%E7%AC%AC16%E6%9D%91Town21%E6%80%AA%E7%89%A9.xlsx) |
| 第17村Town24主線 | 13 | [ST17](ST17_%E7%AC%AC17%E6%9D%91Town24%E4%B8%BB%E7%B7%9A.xlsx) |
| 第17村Town24副本內容 | 16 | [DG17](DG17_%E7%AC%AC17%E6%9D%91Town24%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第17村Town24怪物 | 78 | [MO17](MO17_%E7%AC%AC17%E6%9D%91Town24%E6%80%AA%E7%89%A9.xlsx) |
| 第18村Town25主線 | 20 | [ST18](ST18_%E7%AC%AC18%E6%9D%91Town25%E4%B8%BB%E7%B7%9A.xlsx) |
| 第18村Town25副本內容 | 24 | [DG18](DG18_%E7%AC%AC18%E6%9D%91Town25%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第18村Town25怪物 | 106 | [MO18](MO18_%E7%AC%AC18%E6%9D%91Town25%E6%80%AA%E7%89%A9.xlsx) |
| 第19村Town26主線 | 16 | [ST19](ST19_%E7%AC%AC19%E6%9D%91Town26%E4%B8%BB%E7%B7%9A.xlsx) |
| 第19村Town26副本內容 | 17 | [DG19](DG19_%E7%AC%AC19%E6%9D%91Town26%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第19村Town26怪物 | 150 | [MO19](MO19_%E7%AC%AC19%E6%9D%91Town26%E6%80%AA%E7%89%A9.xlsx) |
| 第20村Town27主線 | 18 | [ST20](ST20_%E7%AC%AC20%E6%9D%91Town27%E4%B8%BB%E7%B7%9A.xlsx) |
| 第20村Town27副本內容 | 19 | [DG20](DG20_%E7%AC%AC20%E6%9D%91Town27%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第20村Town27怪物 | 144 | [MO20](MO20_%E7%AC%AC20%E6%9D%91Town27%E6%80%AA%E7%89%A9.xlsx) |
| 第21村Town28主線 | 17 | [ST21](ST21_%E7%AC%AC21%E6%9D%91Town28%E4%B8%BB%E7%B7%9A.xlsx) |
| 第21村Town28副本內容 | 19 | [DG21](DG21_%E7%AC%AC21%E6%9D%91Town28%E5%89%AF%E6%9C%AC%E5%85%A7%E5%AE%B9.xlsx) |
| 第21村Town28怪物 | 125 | [MO21](MO21_%E7%AC%AC21%E6%9D%91Town28%E6%80%AA%E7%89%A9.xlsx) |
| 索瑪技能 | 37 | [SK01](SK01_%E7%B4%A2%E7%91%AA%E6%8A%80%E8%83%BD.xlsx) |
| 핑코탱이技能 | 36 | [SK02](SK02_%ED%95%91%EC%BD%94%ED%83%B1%EC%9D%B4%E6%8A%80%E8%83%BD.xlsx) |
| 슈발만技能 | 35 | [SK03](SK03_%EC%8A%88%EB%B0%9C%EB%A7%8C%E6%8A%80%E8%83%BD.xlsx) |
| 이실리아技能 | 36 | [SK04](SK04_%EC%9D%B4%EC%8B%A4%EB%A6%AC%EC%95%84%E6%8A%80%E8%83%BD.xlsx) |
| 아엘로트技能 | 35 | [SK05](SK05_%EC%95%84%EC%97%98%EB%A1%9C%ED%8A%B8%E6%8A%80%E8%83%BD.xlsx) |
| 그래니트技能 | 36 | [SK06](SK06_%EA%B7%B8%EB%9E%98%EB%8B%88%ED%8A%B8%E6%8A%80%E8%83%BD.xlsx) |
| 크로모도技能 | 36 | [SK07](SK07_%ED%81%AC%EB%A1%9C%EB%AA%A8%EB%8F%84%E6%8A%80%E8%83%BD.xlsx) |
| 루코技能 | 37 | [SK08](SK08_%EB%A3%A8%EC%BD%94%E6%8A%80%E8%83%BD.xlsx) |
| 엘핀도스技能 | 37 | [SK09](SK09_%EC%97%98%ED%95%80%EB%8F%84%EC%8A%A4%E6%8A%80%E8%83%BD.xlsx) |
