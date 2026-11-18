# 關卡有限演出：實際 Q119 交接與可重複遊玩條件

日期：2026-11-18。基準 `09799b117f01e577be56dee3e909e1cde25b855f`，工作分支 `extra/roy1`。本輪直接讀 BIN／Event／Master，分析既有關卡資料與文件；沒有部署內容、執行 Client／Lua／Server、修改玩家存檔或建立新的正式 RR 狀態。

## 1. 可落實的結果

**Q119 清場後開出口，已有可重用的 Server MEF 狀態與完整點集重建路徑；不必多插一段 Q 才能開門。** 要增加清場動畫、數個本地等待或連續特效，可採已證有限 Q 入口，但必須排在正確的地圖世代、內容版本與播放政策中。這是按功能選擇最少負擔的執行方式：MEF 規則處理何時開門，原生 Client 處理點狀態與顯示。

本輪有兩項具體補證：一是把通用「群清後選有限內容」精確接到 Q119 的清場劇情／重建順序；二是沿著正常 End 的 seen 儲存呼叫，閉合 `CSL.scn` 的讀寫和建構時讀回。因此 **收到 003F 不保證內容 callback 曾經執行；重開 Client 也不保證該 scene 未看過。**〔[交接契約](handoff-contract.json)、N01–N09、[既有原件入口](../../MEF-end-to-end-20261116/entry/report.md)〕

## 2. 實際資料已綁定，三份變體保持分開

[content-projection.json](content-projection.json) 重新讀三份固定 Git JSON 和 Event 原件。它是分析投影，不是新增部署配置。

| 身分 | 實際值與來源意義 |
|---|---|
| 任務／關卡 | Quest119；Field26、Case107 |
| 作者節點 | 第4節點，Map635；原敘事來源的 `sourceNode=1`，不能互換 |
| 出生位置 | `(379.5,391.5)` |
| 出口 | category0、key4；`(391.5,391.5)`、半徑6、預先關閉 |
| 初始敵人 | 1001 三隻、1022 一隻 |
| 入場／清場演出 | Q119 scene3／scene4；對應原 SceneList 的已固定路徑與 hash |
| 最後出口動作 | `InteractZ → Result`，不是再跳一個節點 |

`story-q119-clear-scene` 是基本清場配置；`story-q119-owner-continuity` 加保留角色跨節點狀態；`story-q119-node-delay` 再加節點一的5秒旗標和具名增援。**這些檔案是選擇替代關係，沒有自動疊加。** 基本檔不會因另一份配置有 `preserveOwnerAcrossNodes=true` 就自動得到該功能。

Event 的五個 Q119 selector 均唯一，1687 列 SceneList 的原始識別與七個選定 member hash 均固定；Master 的 Event AttachedPackage 指向 Event。原件路徑有效不等於新內容已進入實際發行包，也不能證明鬆散檔案可蓋過既有 provider。本次沒有新增 scene key、沒有改寫原 SEQ。〔[投影](content-projection.json)、[來源](source-manifest.json)〕

## 3. 清場、演出、重建與出口的正確交接

依現有 `STORY-SCENARIO-OVERRIDES` 與原件點集 consumer，Q119 的必要依賴是：

1. 權威 HP 歸零時處理既有擊倒經驗與掉落；所有應移除敵人的訊息先排入更新。
2. MEF 評估清場，包括必要但尚未出場的波次、剩餘投射物與既有勝利／移除等待。成立後進入清場敘事提交 A；內部規則可已 unlock，World 對外仍可因劇情閘門阻擋互動。
3. 跑原 Q119 清場 scene4，依既有正常完成政策核對回報，再作敘事提交 B。
4. 重建同一張 Map635，**以當時已提交旗標重建整組 0027**；已用過的手動互動點依目前狀態停用。
5. loading、field-ready 與 Q waiting 各自完成交接，Server 才接受當前節點／instance 的出口意圖。

A／B 是分析命名，不是新 schema 欄位，也不是最後獎勵交易。擊倒經驗與返回任務結算另由既有服務處理，詳[結果與延續子題](../outcomes-continuity/report.md)。

`0012` 清點、`0027` 全量替換點；`0048` 或 `Tutorial.SetCheckPointStatus` 只改當前第一個匹配點，不建立 missing 點、不改位置。**重建前改開門狀態，重建後可能消失；重建後完整快照已開啟，額外 setter 也不再有關→開變化。** Server 自有世代要綁到排送生命週期，不能往原 wire 塞 Client 沒有讀取的世代欄位。〔[原點集與 ready 證據](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)、[實際關卡來源](../../../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)〕

因此前輪泛用的 `GroupCleared → 0047 → finite Q → setter` 只在**正確點已存在且其後不被換代覆蓋**的配置中成立。Q119 的現有重建路徑應直接投影 Server MEF 已提交狀態；可選的新演出 hook 才排在重建後，且它目前是開發需求，不是既有 schema 欄位。

## 4. 新閉合：已播 scene 可跨 Client 重啟保存

[原件窗口](native-evidence.json) 共9個、2175 bytes、645個指令，另有3個字串和3個 file vtable 接點。N02/N03 是既有 Start／End 的有界重接；N01/N04–N09 是本輪延伸的持久化 consumer。窗口明示完整 body 或有界前綴；外部分支沒有被省略為「不可能」。

| 接點 | 原件行為 | 對關卡設計的意義 |
|---|---|---|
| N03 `561FB7..561FCF` | 非 review、active、quest0 End：取 `M+3C` scene，插入 `M+74` seen 集合後呼 `5623A0` | 正常結束會嘗試保存已看鍵 |
| N04 `5623A8..5623DF` | 以 `CSL.scn`、`wb` 建立 file wrapper，逐集合元素以4 bytes、1項寫入；末尾關閉 | 不能只把 seen 當記憶體內一個 run 的狀態 |
| N01 `5602FD..560349` | 建構 Q manager `M=FB73C0` 的 seen tree；正常初始化呼 `562440` | 新 manager 初始化會進入讀回路徑 |
| N05 `562449..562491` | 同名 `CSL.scn`、`rb`，成功開啟後以4 bytes讀值並插入 `FB7434=M+74` 同一集合 | 成功保存／讀取時，可恢復先前播放紀錄 |
| N06–N09 | 原 file vtable `C44204`，close `+4→713DE0`、read `+10→713E50`、write `+14→713E70`；各方法交接 FILE 欄位與原 CRT 呼叫 | 檔案參數與讀寫的真正 consumer 已相接 |

結論是**存在正常的持久化／恢復路徑**，不是宣稱每個環境都能寫檔成功、讀取損壞檔仍正確、或本輪看到了某位玩家的檔案。沒有讀寫或刪除實際 `CSL.scn`；也沒有要求玩家清除它來規避行為。

### 4.1 seen-skip 的精確條件

N02 的正常 Start 在 Q inactive 後，只有以下條件全部成立才走該跳過分支：`FB92F1 != 0`、`quest=0`、context `+5F4C` 的值屬於 `{4,9,25}`，以及 scene 存在於 `M+74`。`5618C8` 直接呼同一 003F sender，接著進 waiting；正式內容尚未載入。任一條件不成立，**僅代表這個 seen gate 不會跳過**，不代表其他 busy、內容載入、排程、控制權條件已完成。

這裡的 context `+5F4C` 不等於 field packet table 同數字 offset。本包不因數字推導所有遊戲模式名稱，也不聲稱 Q119 的非零 quest 清場 scene 會走 quest0 seen-skip。

### 4.2 對前輪一次性政策的修正

前輪「一次／Client epoch」仍可限制 Server 自己的重送，但 **不足以證明 Client 未看過**：原 `CSL.scn` 可以讀回；SceneList 不含某個候選鍵，也不等於玩家歷史集合沒有該值。Server 不能以新連線、新 process 或版本號直接宣稱 callback 必跑。

非零 quest 確實跳過這一個 seen 判斷，但正常 End 的 `CheckConfirmMessage` 轉換值仍須恰為1才送003F。不能為了自動開門偽造玩家的確認 globals，也不能把任意改 quest 當成完成回報保證。可重用原已確認的敘事政策；新的內容要明定合法完成與選擇行為。〔N02/N03；[既有 callback 證據](../../MEF-end-to-end-20261116/entry/report.md)〕

對可跳過的純演出，MEF 業務旗標與出口可用性應已有權威來源，003F 只作所選流程的進度訊號；若內容必須真的播放，發布前就要證明有效入口／政策，不能把回報當作顯示成功。

## 5. 時鐘不是同一個東西

`ClearDelayElapsed` 從清場／Portal 提交後首次合格 Server 玩家位置起算，排除清場劇情與保存時間。`NodeDelayElapsed` 從節點可戰鬥起算，清場劇情期間經過時間仍計入，但只在合格更新才送事件。Client `Q.wait` 則受 coroutine／Q active／pause 與 Client timer 影響。

所以優化可把**本地純演出**的等待移到有限 Q；權威條件仍依原時計與可提交時機。把業務 delay 原封不動換成同秒數 `wait`，會改變玩家遇到援軍或開門的時刻。具體增援順序、固定點條件與優化等價性見[規則與波次](../rules-waves/report.md)。

## 6. 如何真正減少 Server 工作

| 需求 | 優先路徑 | 收益與限制 |
|---|---|---|
| 同圖重建後出口已可用 | 已有完整0027直接帶正確狀態 | 不增加額外派送；Client 原生處理點與效果 |
| 同一點集只改一個開關 | MEF 一次條件變更→0048 | 6個應用層 bytes；不需建立一個 Q run |
| 一段包含多個等待、淡入淡出、移動或特效 | 一次合法 selector→有限 Client MEF，明確收尾 | 可少掉 Server 逐拍排程；要處理內容依賴、播放與生命期 |
| 持續普通戰鬥並有常駐腳本 | 另選 ordinary background B 開發 | 特定 runner／輸入／取消接口仍缺；不阻擋上面已可行方式 |

quest0 有限插播至少 `0047(6)+003F(8)+00EB(2)=16` 應用層 bytes，尚未計原本可能仍需的0048或傳輸層。對一個簡單開關反而比6 bytes多；沒有量測前不宣稱百分比節省。Server 執行的 MEF 規則同樣是 MEF 開發，能集中內容、減少硬編碼；只有本地執行或實際少做工作才算執行負擔減少。

## 7. 尚缺什麼與下一步

- **既有路徑復用**：直接沿用現有 MEF 配置及關卡／結果服務；只有採用新格式時才加轉接，保留提交與完整快照順序；不要重寫已存在的存檔和發獎服務。
- **新演出需要時才加 hook**：把重建後可插播點做成明確 Server 開發需求，綁 current instance/node/generation、內容發行版本和前一 Q 的交接。現有 schema 沒有這個欄位。
- **播放政策**：具體內容發行要選定可達且符合重播需求的入口；若只是可跳過演出，業務狀態不依賴其 callback。原件已提供的條件就是契約，不改 Client、不偽造完成。
- **玩家正常流程觀察**：選定內容仍需按現行順序確認實際畫面、按鍵恢復及出口使用；本輪完成的是靜態鏈和分析產物，沒有新增執行測試。

可重驗程式會核24個 Git pin、3個原件身份、9個 native 窗口、3個 vtable 槽、7個 member，以及實際三份配置投影；結果見[收據](verification-result.json)。它只比對資料與機器碼，不執行目標。
