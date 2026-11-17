# Server 開發交接：完整功能、內容契約與原生界線

日期：2026-11-17。這份交接是 `extra/roy1` 的研究產物；由S00沿既有流程去重及整合，不新增正式REQ號、不認領其他Task、不改接受狀態。本repo保存分析與規格，本輪沒有修改或執行Server程式。

## 1. 從現有成果接續

[main功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md)已記錄外部關卡定義、波次／區域／計時旗標、出口與手動互動、巡邏、場景狀態及市場等成果，並分開標示合成、工程與人測。不能把本輪建議寫成「Server全部未實作」。本輪新增需求應對照 [requirements index](../../design/requirements/index.json) 的 `REQ-0019`／`REQ-0021`，以及既有 `SPEC-FLOW-0001`、`SPEC-SCENE-0001`、`SPEC-CHAR-0001`、相關GAP／TEST，確認是採用、補充還是新增實作。

目標仍是原版Client正常玩法。Server決定傷害、HP／死亡、怪物群、通關、任務、掉落、資產與保存；內容可描述觸發條件與演出，但不能繞過這些權威。Client本地Q actor、world entity、prepass slot、model ID、ShopNo及checkpoint key不共用一個ID空間。[既有world identity](../MEF-world-identity-scene-interaction-20261117/REPORT.md)、[本輪query來源](events/observation-catalog.json)

## 2. 可交付開發項目

以下列號只供本文件引用，**不是正式REQ／RR號**。

| 候選工作 | 玩家情境及Server行為 | 已確認Client界面 | 需要補足與完成條件 |
|---|---|---|---|
| S-A 內容版本與預驗 | 玩家進入關卡前選到與Client版本匹配的完整內容；錯誤配置在派發前被發現 | 固定121綁定的ABI、實際SceneList／SEQ與既有loader | 接本包只讀預驗與資源manifest；綁完整selector、typed IDs、hash及owner；只有ABI PASS仍禁止標ready |
| S-B 執行與排他 | 有限演出按正常流程啟動，結束後恢復互動；重複請求不產生重複業務結果 | 既有 `0047` 有限Q入口、seen／busy等限制；普通B入口未證 | 在現有內容執行器中保存Client context、instance、內容版本與run狀態；既有A1一次政策維持。發出命令、Client回覆與Server完成分欄，不杜撰新ACK |
| S-C 權威事件 | 清除某波、血量門檻、互動Z、區域／計時條件觸發下一段 | 既有Server封包／點位adapter；16個Lua query沒有任意world群組死亡契約 | 接既有旗標與wave機制；事件含實例、實體generation／群組、順序及來源，避免用本地固定角色query作清組；僅向已證入口派發 |
| S-D 狀態與收尾 | 演出後玩家控制、相機、可見性、點位與後續內容正常 | Q End、圖片替換、camera Stop／Detach／Pop、全Q樹與資源引用各有自己的owner | 為內容列清理責任和合法執行時機；同run與跨run分開；沒有原生cleanup ACK時只能記未知／逾時或已允許的降級政策，不能假造恢復成功 |
| S-E 任務與獎勵 | 玩家正常接取、進關、清場、出口Z、結算與返回；完成及獎勵持久化 | 沿用主線已證對話／scene／result及資產回覆；演出結束不等於任務達成 | 接既有REQ-0019／0021流程；維持穩定任務ID與合法前置、恰當的重登政策；不能靠畫面消失、003F或無producer回值直接發獎 |
| S-F NPC與服務 | 村落NPC能開正確商店／銀行／強化等服務，交易及外觀依Server結果更新 | 已有UI／point／ShopNo等consumer；其UI入口不是業務規則 | 復用已實作市場／交易／銀行；補未完成強化、裝備能力與正式配置；扣款、道具、資格、價格及保存屬Server開發，不等原版Server算法 |
| S-G 內容與原檔交付 | 客戶端啟動時取得所需且匹配的內容版本 | 既有更新器／本機資源loader的有限證據 | 使用已證交付時機、版本與選取規則；不發明MEF下載opcode、不因能下載就宣稱原MEF parser存在；原資源與工作副本分開 |
| S-H 可觀測與驗收 | 可以說清哪個功能真的成功、哪段仍待測 | Client可觀察值與原生UI／狀態有界；部分原生流程無結果token | 以既有日誌記run、typed IDs、原檔／內容hash、wire與Server決策；原生、SYN、工程、人測各自結果，不以timeout或預期時間充當Client ACK |

這些都是Server開發或內容整合需求；原生封包欄位、合法入口或Lua出口仍未知的部分繼續由Client研究負責。兩種責任不可互相代替。

## 3. 內容載入契約應保存哪些資料

建議沿目前外部關卡schema擴充以下概念，而不是立刻建立另一套平行格式。本表是設計欄位，不是官方MEF record，也不是新增wire欄位。

| 概念 | 用途與檢查 |
|---|---|
| content identity／version | 對應可審查的內容版本、SHA與Client target；不使用修改時間作唯一身份 |
| selected native tuple | 已存在且驗證的quest／scene或其他合法selector；記錄同名、多variant與seen政策；示意值不可部署 |
| typed reference | 分開 Q slot、world EntityId、model／action、map／field／BND、point category/key、ShopNo、talk key；必要時附實例／generation |
| call plan | 精確API、引數個數／型別／順序、native來源；讀結果時註明本地query語義和歧義 |
| dependency manifest | 原carrier hash、member、selected variant、依賴角色與狀態；表格引用與實際payload分開 |
| prepass/formal effects | 同一helper在資源收集與正式執行的差異、slot低位alias及模型集合；不要執行原Lua來猜清單 |
| ownership contract | 本段持有的Q樹、camera、圖片、音樂、world可見性、map備份等；哪些API會改共享owner |
| event/result policy | Server權威事件的來源與提交條件；原生query／本地終點不能無條件轉為業務成功 |
| restore/handoff | 在End前可執行的清理偏序、下一段允許條件、未知處理與現有Client epoch政策 |
| validation records | 原件核對、只讀資料檢查、Server工程結果、允許的人測版本各自保存 |

`abi/validate_calls.py`可直接作最前端的工具組件；本輪未把它包裝成部署器。資源預驗保留 `ready=false`；完整檔案與場景／owner綁定未完成以前，不把它接成自動發布開關。

## 4. 開發時必須吸收的原生細節

**數值開關不能一律傳Lua true。** 一般整數marshaller把boolean轉0，`ScenarioTalkTable.open`第三參數卻採Lua truthiness，數字0也為真。工具須按每API型別送值；不要只在Server或內容編輯器的型別層都寫成bool。[ABI分析](abi/report.md)

**回傳值不能一律當成功。** 121 closure的EAX=1是Lua結果槽數；104個binding沒有建立新值。16個觀察query加lb.DoFile才明確push number；lb.DoFile的0又混合開檔失敗／執行成功。`Tutorial.IsCharacterAvailable`甚至忽略參數、固定第三個roster entry，不能選任意角色；`GetLeaderPosN`的0也混合有效座標與無領隊／無效selector。[ABI](abi/report.md)、[事件分析](events/report.md)

**圖片新建是替換策略。** `56496A→564A60`在allocation前取消舊Q追蹤圖；不應再要求兩個連續永久Q圖都留存。取消和實際manager回收分開，也不能由取消推導所有共享owner圖都被清掉。[勘誤](reuse/errata.json)

**模型預載層與實際doll引用要分開。** Start(B)的level3 replace先於B正式callback，DeleteAllObject亦會替換該層，但同resource仍可能由doll或其他層持有，後續doll工作也有回載。設計不得把這些API當只處理上一run的無副作用操作，也不能反向宣稱每次切段都必定卸載／失敗。依最新[重用分析](reuse/report.md)落實owner與資源契約。

## 5. 供實作者使用的驗收出口

正常旅程以「玩家能進入內容、看到預期效果、維持／恢復輸入、完成權威條件、操作出口、正確提交並返回」驗收；每個新增功能列出真實場景與版本。現有已通過項直接引用，不要求重跑整個Server或所有非正常情境。

本輪的schema／lexer／生命周期合成反例只驗分析工具與已證語義，不是遊戲runtime測試。依專案現行優先序，正常流程之外的重送、故障、併發與壓測先保存為契約或待測清單；本輪沒有啟動這些Server行為測試。

若需要保留新Server狀態機，其run／generation是Server自行設計的權威欄位；除非已有wire證據，不能期待原Client自動回傳它。若Client沒有原生成功或收尾ACK，Server可記「已發起」「原生回覆已觀察」「業務已提交」「等待／未知」，不能只用計時器把前者升格為全部完成。

## 6. 明確移交的四類未完成

| 類型 | 仍需處理 |
|---|---|
| Client待逆向 | 原MEF首次reader／grammar／executor、普通場景不接管控制器的首次入口B、ordinary world typed結果到Lua的出口、部分資源variant／callback與中斷後owner鏈 |
| Server待開發 | 上表S-A至S-H中尚未被現有實作涵蓋的規則、資料與接口整合；由S00去重，不重建主線台帳 |
| 跨功能待整合 | 已知API與真實依賴、合法scene、prepass/formal、owner及現有adapter組合；同一內容跨run的版本與seen政策 |
| 待遊玩驗證 | 指定Client版本的正常入口、視聽效果、輸入恢復、NPC／點位、出口與結算；靜態或SYN結果不能代替 |

任一Client缺口的存在，都不把已知本地視聽／Q演出功能歸零，也不阻擋Server可獨立完成的普通戰鬥、波次與任務開發。
