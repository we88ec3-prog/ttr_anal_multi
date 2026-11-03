# S00：MEF 接收、生怪與 AI 可行性

2026-11-01；使用者要求先以缺檔為工作假說，查轉場是否接收官方 MEF，及能否由 Server 回傳。
缺檔、轉場下載、三隻怪都尚未成為原生已確認需求。這份是有限來源核對與設計判斷，
不是完整網路接收器稽核或 T01 FULL-PASS。沒有修改／執行 Client，也沒有部署新的 Server。

## 已找到的入口與範圍

原始 KR BIN SHA256：
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

- 舊唯讀分析 `anal/MAP-TRIGGER-CONSUMERS.md` 與
  `anal/native-index/map-trigger-consumers-audit.json` 保存六個有邊界函式及 42 個封裝索引核對。
  `4F5640` 是 MapList 表載入，不是 MEF 解譯器。地圖 190 的 TRIGGER 是
  `scenario_town000.mef`，存於 FB74C0 的地圖 ID→字串容器。
- 換圖 `4DF510` 在 `4DF58D` 呼叫 `4F7DF0` 查這個字串。
  **已初始化分支** `4DF592 → 4DF599 → 4DF5B9` 沒有消費回傳字串；
  `4DF5B9` 的 LEA 覆寫 EAX。之後模型／碰撞名稱有實際消費，不能類推 MEF。
  未初始化 helper、別名、間接呼叫及其他模組未窮盡。
- 舊 42 包索引未找到 `.mef` 或表內同名成員；這不是全機、全版本、內嵌或改名資料不存在的證明。
- `005E → 4B3C10 → 540250` 是 TriggerMsgList 的文字提示顯示，不能當作 MEF 下載或 AI 啟動。

本次以 Capstone 5.0.9 重新核對三個有效指令視窗及原始 SHA，見
[有限 byte recheck](evidence/S00-20261101-MEF-CONSUMER-RECHECK.json)。
這只支持精確分支與字串使用，不擴大成「所有接收器不存在」。

## EMF 不是目前可用的 MEF 替代品

既有 REA/Ghidra 保存偽碼 `6D7560`（pseudocode SHA
`db788945d74f390cc347a2f556db823fa141e5443a622a8c13ab3952eb2d7459`）
顯示檔名檢查路徑在 `.gb3` 查找失敗後改用 `.emf`；本次重核 `6D76C0..6D76FB`，
確認改寫字尾並呼叫 `714550`。這不是完整 GB3／EMF parser 格式驗收。

另一保存函式 `79BCE0`（pseudocode SHA
`c9b7bfe59f4b2c9a9010ad6d8f2d2afb4bb26b22756a613f559c1b2a8098ee6a`）
在檔案查找失敗分支拆解路徑、重組並加 `.emf`；重核 `79BDA5..79BDB8` 的字串追加。
偽碼的暫存器 ABI 未完整恢復，不能拿參數推定網路傳輸格式。

MapEffect.stp 的部分 `.emf` 成員為 gzip 包裝，解開後含 Light 名稱。
即使可讀其容器，也沒有證據它等同 `scenario_town000.mef`、波次或怪物 AI 腳本。

## 問題的直接答案

| 問題 | 本輪結論 |
| --- | --- |
| 哪裡接收官方 MEF？ | 尚未定位網路 opcode、handler、檔名／內容接收與 parser 的完整鏈。已找到的是表格檔名查詢。 |
| MEF 內容／傳輸格式？ | UNKNOWN；沒有已確認樣本、magic、版本、長度、分片、壓縮、事件結構或校驗。不能提供可用封包格式。 |
| 轉場是否就是 MEF 下載？ | 未證。原生入場 05/1→09 與地圖初始化有局部證據，但未連到 MEF payload。人測也尚未確定看到完整載入畫面。 |
| 能否讓 Server 回傳 MEF 由原 Client 執行？ | 目前不足以實作／驗收；不能虛構 opcode 或傳任意 blob 期望 Client 解譯。 |
| 能否由 Server 生怪／控制 AI？ | 可以開發 Server 的生成／決策狀態，再使用已核對的物件、移動、動作、命中與死亡訊息；不依賴 Client 收 MEF。官方規則及各訊息時序仍需各自補證。 |

現有本機首戰只有單隻站立怪與簡化命中／扣血，沒有怪物 AI，不能宣稱已恢復原版。
三隻怪來源是使用者提供影片觀察；cluster 的 COUNT1 只描述一次生成定義，沒有閉合總波次。
若未來取得官方 MEF，可研究 **Server 端** 解譯，輸出相同狀態訊息；這仍不代表 Client 有傳檔接口。

## 後續工作界線

優先追怪物建立、位置／動作／命中消費端與發送端，釐清 Server／Client／P2P 權威；
保留官方 Server 持有 MEF 的假說。若找到傳檔候選，需補完整 dispatch→長度界線→
緩衝／解壓→parser→事件執行鏈，才能提出可實作格式。不要用人工延長等待模擬下載。
T10/T11 延續技能／連段缺口工作，AI／波次另由 S00 依主責協調，未擅改 task owner 或正式 RR。
