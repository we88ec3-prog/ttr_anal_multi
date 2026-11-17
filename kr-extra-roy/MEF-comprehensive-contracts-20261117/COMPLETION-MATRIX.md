# MEF 全功能範圍與四層完成矩陣

這張表描述功能域，不把每個API當作一個獨立玩法，也不把「名稱已找到」等同完成。121個正常binding逐項對應見 [FUNCTION-INDEX](function-map/FUNCTION-INDEX.md)；本輪完整ABI見 [ABI-CATALOG](abi/ABI-CATALOG.md)。逐名稱索引有15域；下表另涵蓋原格式、儲存與Server等跨域流程，並非重新計算binding分類。既有75個qbase top-level helper及6個return-only／2個yield-only loading helper沿用[前輪盤點](../MEF-full-surface-native-continuation-20261116/REPORT.md)，不是本輪又發現的75項功能。

**「有界已證」表示特定原件與指定路徑可證；仍可有別的未知路徑。** 每個域都必須另外確認真實資料、合法入口、Server業務與指定Client正常流程。4個stub與1個無可靠count producer的名稱保持明示，不靠替它們寫SYN模型變成功能。

## 1. 能力覆蓋與本輪進展

| 功能域 | 已有可復用能力／原生界線 | 本輪新增或精化 | 主要證據 |
|---|---|---|---|
| 原格式、儲存與內容交付 | Lua parser／本機資源loader與更新器的有限鏈已證；原 `.mef` 首次reader／grammar仍未閉合 | 新資料只補依賴及原始selector，不冒稱官方MEF樣本 | [既有parser](../MEF-parser-executor-storage-20261114/parser.md)、[資源](resources/report.md) |
| 正常Lua綁定與型別 | 既有正常121名稱、prepass及語言庫範圍已列 | 121逐項簽章、33 marshaller、44無參數；17新number／104無新binding值；bool與truthiness例外 | [ABI](abi/report.md) |
| 入口、coroutine與流程 | `0047`可進已配置有限Q內容；prepass與正式VM及pump分開 | 重用時的collector／qco／seen／busy與callback次序更精確；B仍未閉合 | [重用](reuse/report.md)、[A1](../MEF-A-minimal-spec-20261116/README.md) |
| Q演出角色 | 建立、移動、轉向、動作、可見性、camera attachment等具體能力已證；單個DeleteObject是stub | API參數正序、整數／float位置；資源引用與doll回載補證 | [actors](../MEF-content-contracts-20261116/actors/report.md)、[追加資源鏈](reuse-followup/report.md) |
| 普通world角色／NPC／avatar | 本地建立CMonster／世界外觀與既有控制鏈有證據；不是Q actor或Server生怪的同一身份 | 16query不足以取得任意world生死／generation；Base補怪物descriptor原件 | [world identity](../MEF-world-identity-scene-interaction-20261117/REPORT.md)、[事件](events/report.md) |
| 鏡頭 | 絕對／相對work、播放、attach／detach、snapshot及參數有界已證 | 6,080 literal引用與5,403 unique path盤點，43次exact miss分出SceneList可選性；不是native開檔失敗率 | [既有視聽](../MEF-capabilities-20261116/audiovisual/report.md)、[camera audit](resources/camera-audit.json) |
| 音樂、音效與語音 | sound base、播放、音樂pool與talk voice等功能可復用；共享pool不是per-run handle | 字串ABI與具體Q119聲音依賴；真payload仍分開檢查 | [視聽](../MEF-capabilities-20261116/audiovisual/report.md)、[資源](resources/report.md) |
| 圖片、fade與畫面狀態 | 圖片／淡入淡出／letterbox等native更新與post-End邊界已有證據 | 更正FlyingObject先取消舊圖；實體回收仍延後；有限效果與替換政策明確 | [勘誤及重用](reuse/report.md) |
| 多句對話、字幕、面板 | 頭像對白、Prolog／Synopsis、字幕與數字面板有各自owner；BalloonTalk是stub | open第三參數truthiness；固定talk vtable／selected writer讀集已完成；查詢不是任務接受 | [對話](../MEF-capabilities-20261116/dialogue-ui/report.md)、[事件](events/report.md) |
| 書本、教學、控制與UI | 書本／Prolog、Tutorial控制槽及UI setter可復用；部分formal參數被忽略，InsertObject是stub | IsCharacterAvailable固定第三roster entry、CheckLeader固定WORD條件；SetUIPage無任意page參數 | [控制](../MEF-capabilities-20261116/control/report.md)、[query表](events/observation-catalog.json) |
| 互動點、出口與服務 | point category/key、NPC／ShopNo與原生UI consumer已有有界證據 | 按各API精確數值／字串契約預驗，避免和EntityId或Q slot混用 | [scene interaction](../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)、[ABI](abi/report.md) |
| 場景、map、minimap與返回 | LoadMap／RestoreMap、map備份、小地圖與transition等具體鏈可復用 | 真實MapList／BND、ZIP MapFlow／Cluster接到Q119資料；同stem多MapID不任選 | [transition](../MEF-transition-actor-event-20261117/TRANSITION.md)、[資源](resources/report.md) |
| 可觀察結果與事件 | 現有time、active、教學、固定人物／leader、camera／prolog／book狀態可讀 | 16個全部定型為number；skip writer在active gate前；無通用world結果bridge | [事件報告](events/report.md) |
| 資源預掃描與部署檢查 | prepass低WORD、first-slot model／action collection與正式執行不同 | 三原STP索引與補充Base／ZIP、literal camera audit；另證Q model key不含PRE、CHA_ABF／fcs.flu選檔鏈；ready仍false | [資源報告](resources/report.md)、[模型選取](resource-selection/report.md) |
| 結束、清理與連續兩段 | Q.End不等於清所有owner；stop／detach／pop／全Q樹範圍不同 | 圖片替換、Start前置模型replace、CDoll獨立引用／回載、pending work與收尾偏序 | [重用](reuse/report.md)、[追加鏈](reuse-followup/report.md) |
| Server關卡與業務 | 主線已具多種外部關卡／旗標／波次／市場能力，不歸零 | 對接ABI、資源、typed事件與owner契約；列增量開發與既有REQ去重 | [handoff](SERVER-HANDOFF.md)、[主線功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md) |

## 2. 每個域的四類未完成

| 域 | Client待逆向 | Server待開發 | 跨功能待整合 | 待遊玩驗證 |
|---|---|---|---|---|
| 原MEF | 真正reader／grammar／executor與可達consumer | 相容內容可用自己的schema；官方格式無須猜造 | 既有交付時機、內容與Client版本 | 指定交付流程實際選檔／載入 |
| ABI／執行 | 新動態binding或替換receiver需另證；B首次入口仍缺 | 內容預驗、run／結果政策、採用既有adapter | 正式與prepass、同VM／pump、鍵與seen政策 | 正常發起、結束及下一段 |
| Q角色 | 具體失敗／取消／新型動作與資源選取缺邊 | 角色演出內容與實例權威關係 | 真model/action/slot、doll resource、camera依賴 | 可見、走位、動作、收尾／重用 |
| world角色 | 普通場景不接管控制器的首次Lua caller、typed EntityId與結果出口；本地建立API本身已有證據 | 生怪、AI、HP／死亡、群組、掉落及同步的尚未完成項 | 普通戰鬥與有限演出之間的映射 | 正常戰鬥、清場及演出不破壞流程 |
| 鏡頭 | 未證頁面／snapshot共享writer、個別parse／選檔差異 | 內容選取及收尾政策 | 相機member、座標域、attach target、owner | 實際鏡頭、控制恢復、下一段 |
| 音訊 | 只補具體必要的選取／終點缺邊，不展開整個音效引擎 | 內容播放與共享pool政策 | 正確payload、voice key／locale與其他owner | 可聽、音量／停止及演出後狀態 |
| 圖片／fade | 未證共享owner、取消中斷與特殊參數分支 | 有限效果／替換規則與版本 | DDS等真資源、時間與manager gate | 出現、自然結束或替換、後續畫面 |
| 對話／面板 | 新頁面auto updater、未證特殊msg／markup／事件 | 任務接受、傷害／擊殺／獎勵權威結果 | talk/display/portrait/voice、page及UI恢復 | 按鍵／自動進句、關閉、後續互動 |
| 書本／Tutorial | 真正尚未知的角色／控制slot語義與callback | 教學／任務進度、合法控制權 | 對應頁面與資源；固定query不作通用條件 | 正常教學、操作恢復、書本退出 |
| 點位／服務 | 尚未知wire／typed consumer仍留Client | 點位狀態、資格、交易、裝備／強化及保存 | 真點位／ShopNo、場景、既有服務接口 | NPC與出口Z、視窗、業務結果 |
| 地圖／返回 | 未證field／BND使用與transition恢復缺邊 | 地圖／instance、前置、結果及返回 | map/field/BND／spawn域、圖序與玩家狀態 | 正常進圖、出口、返回與可操作 |
| 事件query | 普通world typed結果→Lua；query缺失的同run辨識 | 權威事件與去重／generation | getter語義、結果值、合法pump與Server提交 | 符合實際情境的事件順序及結果 |
| 資源／重用 | 實際CHA_ABF cache／mount選檔、失敗state與pending callback等；Q model key不含PRE已有證據 | 發布／版本、排他與未知處理 | 真依賴、CDoll引用、清理偏序、跨run策略 | 第二次內容、自然結束、控制／owner恢復 |

本輪沒有改任何正式驗收狀態。若單個有界研究已完成，應寫明哪份原件、哪些入口／欄位與結果；若某域仍有後續任務，應接具體未閉合鏈，不把階段性停止稱為全部完成。
