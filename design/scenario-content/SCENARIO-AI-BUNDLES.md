# 關卡與怪物 AI 配套草稿

工作台新增 `LOCAL_MONSTER_BEHAVIOR_V1_NOT_NATIVE_MEF` 行為檔編輯。
這是 Server-owned 行為資料，不是 Lua、原生 MEF、Client AI 或外掛執行介面。
沿用既有移速、追擊、血量、招式範圍／冷卻、血量階段與投射物的型別及界線。

每個新草稿版本可同時保存關卡 JSON 與行為 JSON；各自保留原 UTF-8 位元組
及 SHA。兩份內容在同一 SQLite transaction 提交，舊版不能被覆寫。
沒有行為檔的歷史版本仍使用其固定驗證設定的原始 AI，不改寫舊關卡或 profile SHA。
草稿的來源設定仍代表原範本／BND／AI 基準；草稿自訂 AI 的 SHA 另行記錄。

保存允許編輯中的未完成內容，匯出必須通過兩份資料的檢查。工作台 AI 解析
拒絕未知欄位、保留全部基準 AI ID，並檢查新關卡及主線其他節點引用。
可增加新 AI ID、將怪物切換到它，或調整原 ID 的參數。保留 ID 不代表原數值
不可調整；發布仍須檢查整個 Host 的共用 AI 影響與完整配套。
巡邏段、索敵及追擊範圍須以所選 AI 重新通過同一 BND 幾何檢查。

單檔上限 256 KiB。只有關卡管理路由將表單上限提高到 2 MiB，容納兩份
URL-encoded 內容，其餘管理表單限制保持。頁面顯示實際配套 AI SHA 與 profile 數。

## 匯出與發布

工作台可下載關卡、AI 行為檔，或同版配套 ZIP。ZIP 只包含三個固定命名檔：
`.scenario.json`、`.monster-behavior.json`、`.scenario-bundle.json`。
每個名稱由草稿 ID 與版本產生，不接受使用者的檔案路徑。
前兩檔保留該版本內容位元組；清單 schema 為
`LOCAL_SCENARIO_AUTHORING_BUNDLE_V1_NOT_NATIVE_MEF`，明示 `nativeMef: false`，
列出來源設定、草稿版本、檔名、SHA 及現行 Host 設定鍵。
ZIP 固定檔案順序與時間，以便同一工具版本／平台重複匯出核對。

行為檔使用既有 `TARTAROS_LOCAL_MONSTER_BEHAVIOR_PATH` 及
`TARTAROS_LOCAL_MONSTER_BEHAVIOR_SHA256`。關卡鍵依主線／一般 Case 沿用原規則。
ZIP 清單只提供待設定的絕對目錄範本，不直接修改運行中服務或 Client 資源。
完整 Host 預檢、正常入口與指定 v2 實機仍各自驗收；原生 MEF 缺口不因此結案。

## 範例與工程驗證

此範例在 Q119 第一圖第一隻怪引用 `friends-melee-v1`，以原行為複製新增，
設定 37 HP／9 傷害；其餘基準 ID 保留。這是編輯驗證值，不代表使用者的正式
平衡決策，未套用到遊戲 Host。配對主線 SHA 為
`14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c`。

|檔案|SHA-256|
|---|---|
|[關卡](story-q119-friends-ai.scenario.json)|`0d19cda62047a46ce075c9e7709251ea89c05915539290a42de314b10636a563`|
|[行為](story-q119-friends-ai.monster-behavior.json)|`98717bf92b1e249da6e9989fe1592c54b192852083cab6c267ba29baefcb3842`|

2026-11-19 [工程收據](scenario-ai-bundle-validation.json)：Host／檢查器／管理端
Release 最終建置零警告、零錯誤，5 項針對與完整 HappyPath 628／628 通過。
新 AI ID 的 37 HP 已進入 Server 戰鬥實例；9 傷害只核對資料解析，不宣稱
Client 動作或命中驗收。主線與狩獵場配對、AI-only 新版、舊版本與舊草稿匯出
均有工程證據。ZIP 兩份原始 JSON、清單、標頭 SHA 及同版重複下載一致。
匯出的實際主線配套通過共用載入器與原 BND 預檢，管理端已更新，既有草稿
指紋保持，遊戲 Host 未換版；Client 操作／資源變更與遊戲實機均未執行。
預檢器同時回報 `monsterBehaviorSha256` 與 `monsterBehaviorProfiles`，此例核對
為上述行為 SHA 及 5 個 profile；不是僅從輸入參數推定載入版本。

2026-11-19 補充：[單場正常入口工程驗證](../testing/HUNTING-NORMAL-ROUTE-INSPECTION.md)
已完成基準 37 條、自訂 AI 兩條及 81 EXP 匯出版本兩條，共 41 條。
準備帳號通過廣場建隊至同室回村；並非新帳號主線、TCP 或指定 v2 實機。
