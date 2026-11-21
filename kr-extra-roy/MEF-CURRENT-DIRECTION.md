# MEF 目前開發方向：Server 提供內容，優先由 MEF 處理

2026-11-22：[旗標後延遲](../design/scenario-content/FLAG-DELAY-SIGNALS.md) 已接正常poll時計、延遲鏈與節點／fork界線。Case693開關達標後1.5秒才開門、頭目階段後0.75秒門檻於下一poll才增援；兩條TCP路線各清理14枚子彈、保存88EXP回原隊伍。665 HappyPath通過；Client／新管理欄位／自然新帳號仍待驗。

2026-11-22：[多機關旗標條件](../design/scenario-content/FLAG-COUNT-CONDITIONS.md) 已接有限固定點、路徑可達性與管理端編排。Case693三開關任選兩個，三組各兩條TCP路線均在第二個後才送0048開兩出口，未按第三個保持未成立；各保存88EXP回原村同隊。662 HappyPath通過；Client、自然新帳號及新管理欄位瀏覽器仍待驗。

2026-11-22：[招式旗標條件](../design/scenario-content/MONSTER-ATTACK-FLAGS.md) 已接怪物選招與接近距離，並使用既有圖路徑分析驗證AI旗標來源。新Case693兩條TCP路線的同一活頭目由真實75%HP旗標切換兩階段招式；每路13枚子彈清理、保存88EXP回原村同隊。658 HappyPath通過；指定v2與CPU移轉仍未宣稱通過。

2026-11-22：[已交付任務條件](../design/scenario-content/QUEST-COMPLETION-SIGNALS.md) 已接正式授權存檔讀取與副本旗標。Case693新候選首圖要求Q2842已交付及消耗機關；兩條TCP正常路線各保存88EXP回原村同隊，655 HappyPath通過。Q2842為入場前準備紀錄；自然交任務、指定v2與新管理欄位瀏覽器操作仍各自待驗。

2026-11-22：[一般狩獵場入場權重](../design/scenario-content/HUNTING-ENTRY-WEIGHTS.md) 已接正常入場與管理端版本／ZIP。Stage462 Case693:694=6:4，每場只選一次並綁來源與run；4條固定選擇TCP路線及管理端實際匯出2條路線通關回村，652 HappyPath通過。這是自有MEF功能，NOT_NATIVE_MEF；分布、指定v2畫面與完整新帳號實機分開待驗。
2026-11-22 網路整合：[完整副本TCP正流程](../design/testing/MEF-INTEGRATED-TCP-ROUTES.md) 兩條Case693分支已經正式登入／primary gateway的真正loopback socket通關回村，含機關、存活頭目階段、每路5枚子彈清理與88EXP保存。此為準備角色及受控制時計、同程序正式Server元件，Client／另行部署Host實機與全新帳號升級仍分開待驗。

2026-11-22 開發整合：[怪物投射物視覺adapter](../design/scenario-content/MONSTER-PROJECTILE-VISUALS.md) 已把既有Server直線飛行接到0094／速度selector／001A生命期；獨立Case693配套兩路正常入口各5枚子彈建立／清除，88EXP通關回村，648 HappyPath通過。效果可見性與速度仍待指定v2人測，未修改Client，碰撞／傷害仍由Server判定。

2026-11-21 開發整合：[Case693 完整副本](../design/scenario-content/MEF-INTEGRATED-DUNGEON.md) 已將計時／依序波次、頭目血量階段、消耗機關、兩條分支與結算串為同一內容；兩條正常廣場建隊至回村的原 BND 離線路線通過，640 HappyPath 通過。自訂 schema／NOT_NATIVE_MEF，指定 v2 實機、TCP 端到端仍待驗，不提高原生容器完成狀態。

**2026-11-18 使用者最新指示；適用 `extra/roy1` 的後續 MEF 分析與規劃。**

本頁是目前研究入口。最新 P0-3～10 深入分析與種類整理在 [MEF-P0-level-execution-20261118](MEF-P0-level-execution-20261118/README.md)；前輪20類關卡全表在 [MEF-level-functional-closure-20261118](MEF-level-functional-closure-20261118/README.md)；能力與執行位置基礎見 [MEF-server-provided-capabilities-20261118](MEF-server-provided-capabilities-20261118/README.md)。歷史包保留原始證據與當時結論；遇到「是否必須還原官方 MEF」「Server 責任是否排除 MEF」「哪些項目阻塞所有自製內容」的方向衝突，依本頁與本輪報告解讀。

## 已確定的目標

1. **MEF 開發屬於 Server 開發。** Server 提供、選擇及管理 MEF 內容；生怪、戰鬥判定、敵群清空、開出口、任務結算、獎勵與進度保存均在此開發範圍。
2. **能用 MEF 處理的優先交給 MEF。** 分析每項功能的規則、排程、執行、觀察、回報與保存，不因標示「Server 負責」就把整項排除於 MEF。
3. **以可實作能力為目標。** 官方 `.mef` 檔案、官方容器與格式復原不再是研究目標，也不作自有 MEF 開發的共同門檻。來源標籤 `NOT_NATIVE_MEF` 僅區分自行設計與原生事實，不表示自有內容不算 MEF 開發。
4. **區分執行位置及實際收益。** Client 執行的 MEF／native 效果可承擔本地排程與運作；Server 執行的 MEF 規則可集中關卡邏輯、減少硬編碼，但不能直接算成 CPU 已移到 Client。節省量須以實際流程量測。
5. **只保留具體接口缺口。** 例如某個普通怪物事件未能傳入 Lua、某個原生指令不回傳物件 ID、現有結算 adapter 尚未讀取新 MEF 規則。不要再用「缺官方 MEF」概括這些不同的工作。

## 歷史結論如何使用

- 既有 BIN／資源證據、ABI、作用對象、生命期與 loader 結論仍可引用。不能因目標改變就把空操作說成有效、把顯示傷害說成扣血，或創造原件未證的 wire。
- 舊版 P2 官方格式搜尋改為**退出本次目標**，不是已復原；既有搜尋紀錄不必重做。
- 舊版普通場景背景 Lua（B）缺口只約束「保持普通場景操控且常駐 Lua」這個 profile；有限 Q 與 Tutorial 的已證入口仍可用。
- 舊版特定 Q119／模型／UI 資源缺口，僅約束真正依賴那些資源的內容；不能阻擋不使用那些資源的新 MEF。
- 既有 Server 功能與驗證收據要復用。新 MEF 還沒接入，不等於整個背包、任務或存檔功能從未實作。

本頁不變更正式 Task owner、RR、T01 驗證、S00 規格狀態或遊玩驗收；原件唯讀及分析與執行分離仍依共用指示。使用者已指定工作分支 `extra/roy1`，不另開分支。

## 最新關卡分析補充

- 已完成20類關卡功能的有界分析；實際67份配置的圖／旗標和BND分層稽核，進度、缺項、優化分列[玩家進度](MEF-level-functional-closure-20261118/PLAYER-PROGRESS.md)。這些包含歷史與候選，不等於67個已部署可玩副本。
- 原生 `CSL.scn` 有保存／讀回seen紀錄的路徑。舊「一次／Client epoch」只足作Server派送預算，不保證重啟後未看或callback必跑；003F也可來自seen-skip。[原件補證](MEF-level-functional-closure-20261118/finite-handoff/report.md)
- Q119清場演出後的地圖／完整點集重建會換代；較早的本地setter不保證保留。沿用已提交Server MEF旗標投影到新快照；只有需要多步演出才新增有限插播hook。
- 現有scenario JSON／typed規則可以直接作MEF開發，不強制新建格式。公開範例缺口、實作缺口、特定Client可見操作與新玩法擴充分開，不能互相代換。

## P0-3～10 深入分析後的採用補充

- 已直接讀固定 Server `e88ac0a` 原碼核對出生、行為／戰鬥、時計、清場與轉場；既有巡邏、追敵、返家、選招、傷害及投射物能力可接 Server MEF。原碼實作、Client 原件、自有設計與實機結果分層記錄。
- 本地 Lua 與封包建立的 CMonster 初始化不同；普通 group writer、signed 速度界線與 Client 原生投射物鏈已補證。group 與 relation key 不同；完整普通 Client 自主 AI／命中下放仍另需接口。[生怪與戰鬥](MEF-P0-level-execution-20261118/actors-combat/report.md)
- 波次 timestamp 換算與 NodeDelay／ClearDelay／RegionHeld 的 elapsed 比較不能一律合成同一公式。主線／一般副本的清場、功能測試場返回及一般副本擊倒經驗處理有各自 gate；較精確原碼結論優先於舊概括。[規則與時計](MEF-P0-level-execution-20261118/rules-scheduling/report.md)
- 補齊公開作者範例；固定輪數可用逐節點展開，同房連戰仍用增援。作者 ID 必須接相容 catalog／selector，不能忽略既有主線 override 的限制。
- Map635 有8格真封口的新候選，會移動出口、縮小半徑；只證所列Server二維地形／overlay。另找到6個門模型的CEventObject狀態consumer，實際motion開關語意與Client動態碰撞仍分開。[門與轉場](MEF-P0-level-execution-20261118/gates-transitions/report.md)
- 最新Portal adapter在有ClearScenes或未預註冊出口時走完整重建；全預註冊且無該演出才走點狀態更新。不能把單次setter路線的限制外推成所有內容禁止ClearScenes。
- [12類MEF](MEF-P0-level-execution-20261118/MEF-TYPES.md)是可組合的玩家用途分類，不是12種原生檔案格式；Server規則、有限Q、Tutorial與原生持續效果依各自條件選用。
