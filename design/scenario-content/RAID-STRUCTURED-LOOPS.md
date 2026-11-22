# RAID 動態循環與單次外部結算

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。接續
[獨立 Host 五圖通關](../testing/RAID-SEPARATE-HOST-ROUTES.md)及
[一般狩獵場循環](GENERIC-HUNTING-LOOPS.md)。分析基準
`9dd3ecc588c314cc4806b9aa03c7da691c4228d4`，私有 Server 基準
`4f7f1b092f57a743b37037d14c722c5a6ec4f3b0`。
這是既有 scenario schema 的 RAID adapter 擴充，沒有原生 `.mef` 新格式、傳檔 opcode 或 Client 自主 AI 主張。

## 來源與路線

保留三份固定 RAID 原定義與 15 張原 BND。另存候選，只增加正常互動停止條件、
每輪重置旗標與兩房循環；地圖／chart、原路線目標、最低等級、必要頭目及外部獎勵規則保持。

| RAID | Stage / Case | 循環兩房 | 結束後接回 | 通關書 |
|---|---|---|---|---|
| 1 | 50 / 88 | 1 → 4 | 7 → 9 → 10 | 2274 ×1 |
| 2 | 51 / 89 | 1 → 3 | 7 → 9 → 10 | 2275 ×1 |
| 3 | 52 / 90 | 1 → 3 | 6 → 9 → 10 | 2276 ×1 |

實際 node/map 與來源 SHA 以三份候選為準；此表不得取代原資料核對。

- [RAID 1 候選](phindos-raid1-stage50-case88-loop.scenario.json)：`503325bdd295c5937b15750732449732120e8c50523851eaadafc5d0bc5e6b65`。
- [RAID 2 候選](alsmeer-raid2-stage51-case89-loop.scenario.json)：`e46c568ddf0752c39a286415af73cf4adb96f74aff63c25a91f1cdacf9d86e1f`。
- [RAID 3 候選](rotrua-raid3-stage52-case90-loop.scenario.json)：`af688fb278f5a0eea0a78ee47d5badb895bef268b64ab8a86836f65652be5000`。
- [工作台 manifest](raid-loop-workbench-profiles.json)：`e709dff51b3a1c4847b54a0e5b35c1dfba52f02a6601b9d6d5529e1f677a4b58`。

第一房清怪產生 `raidN-circuit-clear`，第二房出口要求該旗標。
每次重入第一房清除此旗標，所以前輪清怪不能開啟後輪出口。
第二房出口附近有既有 `CheckpointInteracted` 語意的可選互動，key 81／82／83，
產生整場保留的 `raidN-leave-circuit`。未操作時繼續循環，正常操作時離開；
不是指定第幾輪停止，也不由測試 API 注入旗標。出口清怪與必要頭目條件仍生效。
這只證明 Server 的互動條件，Client 的提示／操作可見性另待實機。

來源預設最多三輪（包含第一輪），最多 9 次房間訪問。管理端另存四輪版本，最多 11 次。
第一輪正常互動提前離開為 5 次；達上限後接回三間原後段房間，最後才全場結算。
每訪有新 visit identity、生怪與波次／機關生命週期；沿用既有同場角色資源與背包。
沿用 disjoint loop／DAG body／4096 狀態界限檢查，不開放巢狀、任意 Story 或自訂未登記 Case。

## 編輯、版本及部署契約

一般 RAID profile 保持原 identity 及匯出內容。新的 `raid-1-loops` 至 `raid-3-loops`
具有獨立 profile SHA，從固定候選推導 header／latch／body；可改上限、停止／重置旗標、
停用整段循環。更換 body、地圖、原始出口目標、必要頭目或外部獎勵均不在此 profile 可編範圍。
停用時移除 `structuredLoops`，不是填空陣列；另存新版本，舊版本與舊 ZIP bytes 保持。

共用編輯能力介面提供循環形狀，沿用既有表單／JSON、只讀預覽、保存、歷史及三檔配套匯出。
預覽不寫草稿或發布服務。RAID 沒有普通擊殺／通關 EXP，因此普通 EXP 欄位保留 null，
不能以 null 當作零 EXP 宣稱普通獎勵分析。顯示的是通關經驗書產品、數量與每場一次範圍。

既有 `LOCAL_SCENARIO_AUTHORING_BUNDLE_V1_NOT_NATIVE_MEF` 僅於啟用 RAID 循環時增加：

```json
{
  "externalRewards": {
    "kind": "CHALLENGE_BOOK_CP_V1", "raid": 1, "product": 2274,
    "quantity": 1, "scope": "ONCE_PER_SUCCESSFUL_RUN"
  },
  "routeBounds": {
    "maximumNodeVisits": 11,
    "interpretation": "EXTERNAL_REWARDS_ONCE_PER_SUCCESSFUL_RUN"
  }
}
```

上例只節錄獎勵欄位；完整配套另有 `structuredLoops` 正式 preview 物件陣列與來源／版本資訊，不能直接使用此節錄作配套輸入。
RAID 循環不附普通 `experienceBounds`；狩獵場原有 EXP bounds 保持。
reader 重新驗證 profile、draft/revision、三檔固定檔名、來源／AI SHA、BND、完整 settings、
loop preview、書／CP政策及訪問上限，並拒絕不符 metadata。設定只作資料匯入，不執行腳本。
停用版本沒有上述 loop metadata，reader 仍重新算出 5 次訪問。

Host 只有明確 `TARTAROS_LOCAL_STRUCTURED_LOOPS_MODE=LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF`
才接納 RAID 循環。health `localChallengeRoutes` 回報 structuredLoops／maximumNodeVisits 與實際來源／AI。
啟動器 `-RaidLoopProfile` 必須搭配 RAID ID、保存配套 manifest 絕對路徑及 SHA，先以固定候選 profile
驗包再載入該版；不自動改現行服務。一般 RAID 與舊狩獵配套路徑保持。

CP 與書仍由既有 challenge settlement 管理；不能在 node 設普通 EXP 或地面掉落。
通關只交付一筆一本書；返回廣場前發布背包，再清理 RAID 隊伍。
RAID 正常回廣場與一般狩獵場同隊回村是不同 adapter，不能互換驗收主張。

## 證據與限制

結果索引見 [RAID 循環完整路線驗證](../testing/RAID-LOOP-COMPLETE-ROUTES.md)。
同程序 TCP 的 test clock／只讀 diagnostic 可證明 visit、重置及實際 runtime 決策；
獨立 Host 真實時間只透過正常 socket 操作，從載圖／chart／結果與唯讀 DB 核對。
後者的 loopDecisions 是 driver 依正常輸入及回覆推導，不能冒充內部診斷快照。

波次、頭目階段、機關、兩分支、結算與同隊回村的完整一般副本仍以
[Case693 整合交付](../testing/INTEGRATED-DUNGEON-DELIVERY.md)及
[獨立 Host 通關](../testing/SEPARATE-HOST-DUNGEON-COMPLETION.md)為準。
本輪沒有把這些元素虛構加入 RAID 候選。
指定 v2、自然新帳號、Client 自主生怪／AI、原生 MEF、巢狀循環及其他 adapter 維持未完成。
重送、重登、故障、併發、安全、壓測維持待測，沒有因正流程通過而結案。
