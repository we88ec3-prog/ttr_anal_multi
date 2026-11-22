# 頭目身分查詢索引

2026-11-23。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。接續全域血量彙總後的頭目查詢待辦；
沿用既有出生身分與判定，不改關卡 schema、平衡、封包或 Client。

## 契約

每場 combat 以 `(model, pre, waveId)` 保存已查詢的頭目成員。第一次查詢掃描當時敵群，
之後只讀這個成員集合；尚未生成的頭目也保留空集合。已通過原驗證的增援加入敵群時，
同時更新所有已查詢的集合，依原出生順序追加，不重用死亡物件身分。

這是**身分索引**，不保存死亡或移除狀態的副本。每次仍讀原 actor 的 HP／RemoveAt，
因此擊倒 callback、死亡動畫等待、投射物造成的延後移除都沿用既有時序。
初次建表和增援登記共用既有敵群發布短鎖；callback 留在鎖外。這不是整體戰鬥併發驗收。

- `waveId=null` 的頭目選擇器仍表示跨初始組及所有波次的 wildcard；具名 wave 必須完全相符。
  此語意與 MonsterDefeated signal 的 null=初始組不同，不能共用錯誤的 key 解釋。
- `BossStatus` 保留第一個符合身分的成員：未生出／存活／死亡待移除／已移除。
- `IsBossDefeated` 保留任一符合成員 HP=0 的判定。第一名仍活、後出生的同身分成員死亡時，
  狀態仍可 ACTIVE，而死亡判定為 true；不把這兩者合成單一快取旗標。
- `ReadyToReturn` 保留任一符合必要頭目的成員 HP=0 且 RemoveAt=null 的 gate。
  全部必要波、總血量、角色存活、原返回時限及投射物仍各自成立後才可返回。
- `ReadyToClearMissionNode` 的全敵群移除檢查、AI／目標／移除遍歷及原擊倒回呼不變。
- 每個 combat 獨立持有索引；換圖或 loop 新訪次由原戰鬥建立流程得到新索引。

## 工程計量

既有 StageOne／Story 唯讀診斷追加 `bossSelectionObservationWork`：

| 欄位 | 計算範圍 |
|---|---|
| queryCount | 這三種查詢真正被呼叫的次數，不計被先前 gate 短路的返回查詢 |
| referenceMemberVisits | 原 FirstOrDefault／Any 成功流程的成員訪問數：命中時為該出生序號，未命中時為當時敵群長度 |
| initializationMemberReads | 每個不同 selector 首次建立時的敵群讀取數 |
| birthSelectorComparisons | 已快取 selector 對每位新出生者的身分比較數 |
| selectedMemberVisits | 查詢實際訪問的已選成員數，包含已死亡成員 |
| cachedSelectors | 此 combat 已查詢的不同身分 selector 數 |

出生序號只供內部計量，不新增 wire 欄位。這些是不等成本的工作項，不能換算為 CPU／吞吐
改善或 Client 卸載；鎖、配置與其餘遍歷也未包含。大量不同 selector 仍有各自首次掃描成本。

## 驗證與限制

[收據](boss-selection-validation.json) SHA256
`c2aceaa5969a6235e93a3fb93f4eb2a5eb7f89c433dda81e6f20383f2aff5073`。

- 四個新增正流程驗 live callback、PRE、重複查詢、空索引後計時出生、精確波／wildcard、
  順序增援、兩種出生順序的 first／any 差異、跨 combat 隔離及實際移除時限。
  第一輪789／790的單一失敗是新增測試讀錯既有移除封包欄位；保留原TRX，修正為001A／
  entity offset4後，最終 **790／790 HappyPath**，零失敗／跳過。未為此變更 runtime。
- 相同 Inspector／相同原BND與整合 flag-delay 內容，分別載入唯讀舊 Network 與新版：
  兩條分支完整 primary／dungeon TCP 回包一致，只正規化既有明確定位的隨機 wireAlias。
  逐出生、頭目狀態／死亡／波數、增援時的存活頭目、旗標、精確延遲與88EXP皆保持。
- 每路頭目房719次查詢：舊選擇器訪問1294成員次，新初始讀1、出生比較3、已選成員讀461；
  這是工作量，不是 CPU 改善數字。其餘房沒有頭目查詢，也沒有初始化 selector。
- 同版獨立真實時計 Host 經正常登入／廣場建隊／進村／六圖／機關／頭目階段／一次結算，
  保存88EXP、原村同隊返回；唯讀SQLite核對，來源DB SHA保持，隔離Host已停止。
- Story 四條測試時計 TCP 控制維持舊停止／三輪5932／5972與新擊倒停止／三輪5936／5984，
  一次Q119／Q120游標及同隊回村；RAID1～3三條原版五圖TCP各發書一次、CP3000並正常回廣場。
  本批沒有新增 Story／RAID 獨立 Host 成果，不能外推普通副本證據。
- Host／Inspect／Admin 三個 Release 建置零警告／錯誤，三份 Python 工具語法檢查通過。
  原件、使用者資料與現用服務保持；沒有操作 Client。

新版 Network SHA256 `7d0315b6b4d6398f62b64cfa0f7d5913ec29e05323e36889abf44ce9b5c7738b`；
舊版 `ec5e6ea9fdb9fda2ab072242ad80431e45c1ccaf7b01a87f7122d2c8cf92f47f`。
私有工具 `check-wave-index-equivalence.py --profile boss` 產生對照，
`audit-boss-selection.py` 可只複驗保留收據，不重跑遊戲。

`GAME_RUNTIME_OBSERVATION`：本批為 OFFLINE_SYNTHETIC／LOOPBACK_TCP 工程結果，沒有新指定v2
畫面／操作觀察。指定 v2、自然新帳號、數值邊界、故障／併發／壓測與既有暫緩項目仍各自待驗。
仍有其他MEF功能工作；不以此索引或通關路線宣稱整體目標完成。
