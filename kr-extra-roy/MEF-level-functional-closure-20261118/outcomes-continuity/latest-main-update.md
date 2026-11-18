# 較新 main 補註：付費完全復活與同場續戰

**較新 main 已增加 Product 184「付款、領取、穿裝備、消耗復活、保存並繼續原戰鬥」的跨模組離線證據；死亡懲罰、Scenario 的特定 Client 入口與指定 v2 操作仍未因此完成。** 本補註採用上游既有收據，沒有重跑它的測試或 Client。

原分析基準仍為 `09799b117f01e577be56dee3e909e1cde25b855f`，原 50 份 pin 不變。補讀的固定 main 為 `7344eeb65198e2dd61684b66cf811021765ed8f5`，功能提交為 `9509a9b1ccd2f04cc4afdd1eaa47fb63b0556df0`。上游文件另明列其分析基準 `578b0bc8d37fd071129671ca4072ba0ed2788da3` 與私有 Server 基準 `f25b49514231be9db1ae442b092e6b76cfe3ed4e`；四種身分沒有混用。

## 1. 新增的成果應計入進度

| 項目 | 較新 main 的證據 | 本包應採用的判讀 |
|---|---|---|
| 道具及效果配置 | Product 184 → Item 184，class 26、堆疊 100；原表全資源 100%、群組 3／4 秒 | 加入付費完全復活的具體產品，不只引用先前掉落 183 或活動 248 |
| 真正付費來源接消耗 | 隔離帳號以現行商城價格購買並領取 184 ×10 及時裝，穿上後進一般狩獵場的合成 instance | 關閉「只用掉落／直接夾具入包驗消耗」的跨模組覆蓋缺口 |
| 兩種既有使用請求 | 兩個上游正流程分別送背包 `C2S 0021` 和已綁快捷 `C2S 0022` | 證明 Server 接收／交易／world adapter 串接；不是兩個 Client UI 都有人操作過 |
| 裝備後資源容量 | 時裝後 HP 500、SP／MP 220；hazard 實際傷害路徑造成倒地，復活回到現裝容量 | 裝備容量和復活計算有交叉證據；初始 SP／MP 與可走地面仍是明示夾具 |
| 同場繼續 | 復活不發生怪、換圖、結果或場景重建；怪物 ID／位置／血量及節點、路線、擊倒 XP、拾取、完成狀態保留 | 支持原地復活承接當前 encounter，沒有重新開一場 |
| 保存 | 重開 asset store 後保留數量 9、錢包、CP、時裝、快捷綁定與冷卻 | 是 store reopen 持久化檢查，不是新增完整遊戲重登或戰鬥中途續接 |

來源為 U01、U02、U03；完整 pin 和選定結果在 [latest-main-update.json](latest-main-update.json)。付費價格是原表／現行候選：10／50／100 張為 16／72／128 Garnet。群組 3 與 CP 書共用持久化鎖定，復活本次期限為 4 秒，CP 書為 1 秒。復活本身不改 Garnet／LeeLoo／Battle Point／CP，沒有新增死亡懲罰退款。[U01、U03]

## 2. 三個關鍵缺口維持原狀

| 原缺口 | 較新來源有沒有閉合？ | 精確原因 |
|---|---|---|
| 完全復活的死亡懲罰／評級恢復 | **沒有** | U01、U03 明列 Action 3 `VALUE=-800`、Action 23 的完整 consumer 語意未建立；SkillCast 437 視聽、死亡懲罰／狩獵評級也未驗證。不能由原表文字或回滿血魔推成全部效果完成 |
| Scenario mode 2 的 class 26 背包直接使用入口 | **沒有** | 新收據是 Table 資料與一般狩獵場 Server 請求測試，沒有新增原生 Client 派送鏈。U04 在較新 main 與原基準逐 byte 相同，仍記 class 26 所選分支只接受 mode 4／9 |
| 指定 v2 玩家實際操作／動畫／恢復控制 | **沒有** | U02 的 `clientExecuted=false`、`tcpExecutedThisBatch=false`、`deployed=false`，U03 的 `clientRuntimeVerified=false`；CS-06 明確待排 |

Scenario mode 2 的界線只針對已核的特定 class 26 背包分支；沒有把它擴大成「Server 主線復活服務不存在」，也沒有聲稱全程式不可能有其他入口。現有主線復活與保存紀錄照原範圍保留。[U04；本子題 S07、S10、S15]

普通副本實際離隊 UI、主線倒地退出按鈕／請求，以及 Raid 主動退出／斷線 CP 政策，亦不屬此次付費復活測試新增的能力。

## 3. 既有收據的範圍與失敗歷史

U02 保留第一次專項測試 2／2 失敗，原因是夾具沒有取得伊希莉亞，穿裝前便失敗；補上既有教學角色授予，沒有修改商品資格檢查。之後專項 2／2 通過，全回歸 576／576 通過；兩個 paid revival case 在完整回歸中亦通過。Release Host 與 Inspector 的既有建置收據為零警告／錯誤。[U02]

以上數字是 **上游記錄**，不是本 agent 跑出的測試結果。私有 TRX 只以 U02 內的路徑／SHA／counter 採用，本 agent 沒有開啟那些私有檔案；沒有把該合成測試稱為新帳號自然遊玩、TCP 或指定 v2 驗收。

本補註核了四個 Git blob 的 commit／blob／SHA／bytes，並交叉核對 U02 的 `sourceReceiptSha256` 等於 U03 實際 bytes 的 SHA：`9665a9144f622b77cf0cd6165f48c6118340345834f57306c77b1d822e2d2037`。U03 自身是上游唯讀 Table 核對收據；本補註沒有重新解碼四份原表，原 50 份基準 pin 也未變。

## 4. 根功能表 L14–19 的更新建議

| 功能 | 應更新的內容 | 不應提升的範圍 |
|---|---|---|
| L14 血魔／冷卻延續 | 復活使用目前裝備容量且保留同一 encounter 有新交叉證據 | 不等於跨節點延續 SC-01 新通過 |
| L15 結果畫面 | 無新結果／返回 UI 證據 | 本次復活刻意沒有結果或重建封包，不可列作結果流程驗收 |
| L16 掉落／拾取 | 多了付費購買／領取後的共用背包消耗串接 | 沒有補掉落特效／Space 拾取的 Client 可見性 |
| L17 經驗／固定獎勵 | 復活保持擊倒 XP 與貨幣／CP；不發懲罰退款 | 主線預告與返回後最終入帳、一般副本實際收據政策不變 |
| L18 再次進場／保存 | 付費卷軸、時裝、快捷、冷卻的 store reopen 有明確資料 | 不等於遊戲重新登入後續在戰鬥中途 |
| L19 死亡／復活／退出 | **增加付費完全復活的兩條跨模組 OFFLINE_SYNTHETIC 正流程覆蓋** | 保留死亡懲罰／評級、Scenario 特定入口、v2 操作與原退出缺口 |

玩家版可寫：「付費領取的完全復活卷軸，也已有一般狩獵場的離線串接；用背包或快捷請求復活後，回到穿裝備後的血魔上限，怪物與關卡進度留在同一場，扣券和冷卻可保存。」緊接註明：「真正按鍵、動畫與重新走動仍待指定 v2；死亡懲罰及評級效果尚未確認。」

## 5. 新來源身份

下列來源全取自補充 commit `7344eeb65198e2dd61684b66cf811021765ed8f5`，沒有 merge 或改寫原件。

| ID | Git 路徑 | Bytes | Git blob | SHA-256 |
|---|---|---:|---|---|
| U01 | `design/scenario-content/CASH-COMPLETE-REVIVAL.md` | 4456 | `045dfcd99df60f285cd7b9c9a2bf718e4471d577` | `0f871c98f1c4d36eabad576277535deadb0b2feb176863d70854bc8143c74638` |
| U02 | `design/scenario-content/cash-revival-validation.json` | 4411 | `3758ebcc76938d0ba8e6e2cc4d9315ccf2d3f9c4` | `33f36497ba79c37c0328b301e6cbaf5eaab8b7b4807be12fe58945e1e4bfcf30` |
| U03 | `governance/client-variants/20261118-cash-shop/revival-source-verification.json` | 1962 | `089d8a2f0c2712fb730b215cdd5b90ab36b0ab55` | `9665a9144f622b77cf0cd6165f48c6118340345834f57306c77b1d822e2d2037` |
| U04 | `design/scenario-content/PHINDOS-GROCER-TRADE.md` | 18436 | `f4308a16eefd0f27640234f0b5f186bf3b82868d` | `d7ee272101ef255560c6340d1b6e1ca49821240bb19a18c30c1641f24808ea2f` |

機器欄位：`git_sources[]` 每列含 `id / commit / path / git_blob / bytes / length / sha256 / use`。U01–U03 是本次新增的三份復活來源；U04 是為確認 Scenario 背包入口文字未改而補核的既有來源。原分析仍從固定 baseline 重驗；根交付驗證器可另逐列重核本清單。
