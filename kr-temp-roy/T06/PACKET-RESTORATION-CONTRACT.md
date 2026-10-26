# 兩村切換的原版客戶端封包契約（待整合）

目的：供伺服器端開發審閱，優先保留原版客戶端，不靠場景／控制器修補恢復流程。本文件不是可直接發送的完整封包序列，也不是遊玩驗收。

基準：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。執行／附加遊戲與目標 API 限制維持；主程式其他修改依[全任務政策](../../shared/CLIENT-MODIFICATION-POLICY.md)先提出具體方案。

## 可引用的原生介面與限制

| 訊息 | 已觀察介面 | 本案用途與尚缺條件 |
|---|---|---|
| S2C `0012` | T07 `4B24F0` 先清除 actor／重置控制器，讀 DWORD +2 傳入 T06 `4DF510` | 實體 Map selector；整數 DWORD，不是偽碼所示 float。先建立的 managed actors 可能被清掉；這只給局部順序限制，沒有證明官方完整序列。 |
| S2C `0038` mode 0 | 既有報告：WORD +3 經 `540A40` 準備 Town 資源，另有標題／狀態處理 | Town context 與 physical Map selector 是不同欄位；不是兩者對照表。完整封包其他欄位未在本文件驗收，不生成其發送樣本。 |
| S2C `005F` | T07 `4B99C0` 依 BYTE +2 選場景、交 `4B7D50` 安裝 | 原 type 6 是 `CDuelField`，既有教學修補不適用原版；type 7 對應預設分支 `4B9B3B`，不能抄用 `0069` 的數字。Town-specific 場景／控制器需 T07 驗收。 |
| S2C `0069` | 歷史廣場實驗聲稱 handler `4B9090`、scene 7 進入 `4BBB70` | 目前只引用歷史說法，不把 fixture 註解當新驗收的原生 Town constructor。其 request/reply 關聯與尾兩 byte 的 1/1 為實驗假設。需 T07 既有原生證據補足。 |
| S2C `0014` | T07 `4C5930` 轉目前場景 virtual +2C；已驗證 Scenario 路徑有 ready 寫入 | 不能推所有場景相同，不能直接當成城鎮就緒或任意發送順序。 |
| 玩家初值／建立／控制 | 依賴 T04／T07／T09 | 不沿用 fixture 的 900/900、1000/1000、Town5、固定 plaza 511；合法兩村 spawn、bounds、控制權及 actor 排程未驗收。 |

來源與範圍：`evidence/town-map-interface-dependency.json`、`evidence/packet-scene-type-domain-distinction-v1.json`，以及共用原生報告 `anal/SCENE-ENTRY-RESET-AND-READY.md`、`anal/MAP-ENTRY-FADE-AND-MUSIC.md`。場景核心只引用 T07，不在 T06 重新定義。

## 兩村資料候選

| 使用者確認名稱 | Town context 候選 | 已確認 MapList key／資源 | 原版正常進城配對 |
|---|---:|---|---|
| 馮德斯村 | 1 | 182 → `town001D`／BOUND `town001` | 未驗證；故事資源關聯不能替代官方後端進城配對。 |
| 爾斯梅勒村 | 2 | 183 → `town002D`／BOUND `town002` | 未驗證；同上。 |

`evidence/town12-map-selector-body-samples-v1.json` 只保存 `0012` 的六位元組訊息本體樣本，供檢查 DWORD 編碼。它們是分析者依已觀察欄位合成，不是擷取的官方封包；不含連線 framing、加密、序號，不可當作可獨立送出的完整網路封包。

## 伺服器端後續開發／驗收缺口

1. 將 Town context 與 physical Map selector 分開建模。兩村候選對照如需作重建配置，必須標為重建政策，不冒充原版規則；目前不自動套入服務。
2. T07 補足正確 town 場景／控制器、`0069` 與 `005F` 的職責，以及與地圖重設、ready 的必要順序。
3. T04／T09 補足合法 spawn 與碰撞／移動初值；位置不從 camera、劇情站位或舊合成座標補猜。
4. 後端明確處理隊伍實例、切城請求、玩家／NPC 重建、回城與狀態保存。使用者記憶仍單獨標記，不直接視為原生規則。
5. 驗收使用原件 SHA 相符的客戶端，分清 IP／Windows 相容／翻譯副本差異與任何遊玩行為 patch；必須先確認沒有沿用行為 patch，再談原版流程相容。
6. 實際連線、發包與可玩驗收仍未執行；現有限制下只交付靜態證據、離線樣本及待開發規格。

## 舊成果的處理

詳細修補依賴與對應資料缺口見 [CLIENT-PATCH-DEPENDENCIES.md](CLIENT-PATCH-DEPENDENCIES.md)。除了教學場景攔截，舊廣場 generator 還包含角色描述略過、商城負分類略過與背包計數器清零，不能僅排除場景 patch 就宣稱原版流程已驗收。

`anal/login_protocol.py` 的 `0x42 → 0x43/0x69`、尾 byte 1/1、固定 Map511，以及舊廣場／教學可玩紀錄都屬歷史實驗範圍。`make_tutorial_transition_probe.py` 的原版分支攔截屬客戶端行為修改。不能因舊畫面可玩，推論未修改原版客戶端的兩村封包流程已完成。

## 重送相同 Map selector 的限制（待整合）

原始4DF510在4DF53E比較manager+48的DWORD；相同時跳4DFA13，局部正常流程不經MAP/BOUND查詢、7C1E00模型呼叫或4DF1A0碰撞呼叫。不同時4DF54E先更新快取，再查資源。故不能把重送相同0012視為已證的完整重新載入手段，也不能把快取值已更新視為載入成功。

原始bytes、完整函式指令位址比對、same-ID可達指令與calls見evidence/map-repeat-branch-v1.json。此結論只限函式內顯式路徑，不排除被呼叫helper的間接作用、例外或caller行為；未觀察到runtime失敗或重試。T07 scene/reset順序仍待其主責證據。
