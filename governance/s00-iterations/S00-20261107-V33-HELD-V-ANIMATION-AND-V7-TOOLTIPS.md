# v31人測結果、v33 V動畫與Client v7說明翻譯

## 使用者回饋

使用者回覆v31短卡「123測試都通過」：Tab配置／X圖示變化、兩次短V升階，以及伊希莉亞配置0/LV6 X扣45SP40MP。這是修改v6工作副本、loopback v31的有限人測結果，不是完整技能／原生Client或正式V政策通過。
新增問題：V應有動畫，另一種變化記得按住V而非兩短按；技能說明仍韓文，要求技能及Tab/V說明一起調整；部分角色技能尚未全開。89項未開動作／多段規則清單維持，不隱藏或升為完成。

## V說明與動畫核對

[原文／資源契約](../client-variants/20261107-v-charge-correction/README.md)：KR原文分兩條：一次短按進集氣，集氣中再按一次進二次集氣；持續按住則進氣發散。長按0x80不是直接tier2的證據，放開0x40也不等於清tier。
九角色18/FORCE01及20/FORCE03是單次，19/FORCE02 Repeat=true；有ASD／效果SHA。source17群組值不是蓄氣state。成功短V可用18/20、長V用19作**明示Server動畫候選**，不冒充已閉合官方active→motion dispatcher。
18在本機actor時可能促成00DF任務事件：v33空場僅對param10精確callback不提交正常主線，且不頻繁重送18。19只送一次，由原資源自行循環，release0x40送idle停止。

## v33實作與部署

保留v32 MEF承接內容層；私有main `4d8e432380813d1945f6f5c71e23b265b325ff42`，79項HappyPath通過1分鐘、0失敗／略過，Release publish通過。2026-11-07台灣20:21啟用，PID34148；核對舊v31 loopback Host與路徑後一次換版，隔離SQLite先備份，沒有中途部署v32反覆斷線。
Host DLL SHA256 `35538b9713ed18d7ba163bac6d522bd9ab038210a80b9ae7ff5ac976df775c01`；Network `46358ce67a6fca73fa7afc7f584bfe9d1120773cf80c9d934cb56a033d61b2d0`。

- 成功短V播放當前角色單次18／20，依素材名義片長重開輸入，不更動已驗階段與type7費用候選。失敗不扣款或製造移動鎖。
- 目前矩陣有配置的基礎／進階1長V路徑播放循環19，放開停止、不清tier、不發獎／假SP回復。空場最多10秒watchdog是Server預覽保護，不是官方持續／回復週期。
- 額外發布長V Practice level1，普通技能等級與三個special Practice不重複相加。既有冷卻active-ID/deadline不重建。
- MEF兩圖事件與AI JSON現已從外部exactSHA檔載入；health實際回報兩個PINNED_EXTERNAL_SERVER_JSON及nativeMef=false。原生MEF reader仍unsupported，不送Client MEF blob。

SP轉換量／節奏、V時效／施放後退階及完整狀態規則仍未完成；全域MP/SP10秒50%回復與長V獎勵分開，不能把全域回復當V完成。

## Client v7：技能／特性／Tab／V中文說明

使用者已持續授權翻譯配套調整，無須另問。保留原件與全部舊版，直接由原遊戲目錄啟動新 `Tartaros.ip-zh-tw-v7.exe`，不用CMD。
[讀取入口證據](../client-variants/20261107-skill-description-read-path/README.md)找到SkillExplain consumer52FC50與PracticeExplain529D50的兩個直接literal；v5包已翻譯，這兩入口仍讀原檔，屬同類direct-path問題。另查出14列殘韓，並未猜測舊merge留下原因。

新增三檔：

|檔案|來源／範圍|SHA256|
|---|---|---|
|Tartaros.ip-zh-tw-v7.exe|v6副本，只改兩個等長路徑literal，23實際byte|937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec|
|TC_UI/SkillExplainText7.xml|沿用核准v5中文，補Skill243文字|c0b340d0c52257a08fd759d14fb7e8711fb78ca2e520ac384508875edba04f03|
|TC_UI/PracticeDescription7.xml|補13列文字／NAME，含9角色Tab進階切換199..207|76168490f133b3b32fb6fdd4231bb0b8da05f84afe1d6c1b57c4bd6504e1331e|

14列均按原ID/level/結構對齊只修顯示文字；8280 XML節點獨立比對，其他欄位／ID／level保持，兩結果恰與對應台版member逐byte一致。EXE大小12487680、PE及程式碼區、兩字串外所有byte不變；92既有檔與台版來源hash不變。751顯示字元兩字型均無缺字；不修改字型、fcs.flu、pack.gms或場景資源。

原TC長V字樣「持續點選」仍保留；原KR操作語意是**持續按住**，本次另有文件說明，不為此重製v8或覆寫已完成v7。文字翻譯不代表Server技能全部完成／台韓數值完全一致。

[交付與限制](../client-variants/20261107-variant-v7/DELIVERY.md)、[建置manifest](../client-variants/20261107-variant-v7/build-manifest.json)、[獨立靜態複核](../client-variants/20261107-variant-v7/independent-static-check.json)。EXE/XML/font原件及輸出留本機，不推Git。

## 目前驗收

v31三項按使用者回覆通過；v33新增動畫／held/release、外部場景定義與Client v7說明實機待測。整合短卡已送：先中文說明及V短／長按，再正常兩圖清怪、出口Z，停結果頁。除非使用者另停，測試期間持續完成MEF與回饋的來源／規劃整合。
T01／SPEC／REQ不因上述候選與合成通過自行升APPROVED或FULL-PASS。
