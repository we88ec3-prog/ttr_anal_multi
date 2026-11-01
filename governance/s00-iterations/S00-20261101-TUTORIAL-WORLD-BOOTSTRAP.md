# S00 — 劇情後錯誤地圖／玩家初始化

來源為使用者正常遊玩後回報與截圖，接續
[REQ-0010 收件紀錄](S00-20261101-EXPEDITION-NAME-TUTORIAL-ENTRY.md)。
需求通道為 **GAME_RUNTIME_OBSERVATION**，不是從舊 fixture 推導使用者需求。
本輪仍屬 CANDIDATE、SOURCE_BACKED_PARTIAL；正式 SPEC／RR／GAP／ADR 不升格。

## 觀察與原因範圍

命名已成功，劇情後有教學提示但沒有完整人物／頭像，背景異常。截圖無法證明
map ID 或實際座標；舊 Server 的相似紀錄也不能替代此次 Client 內部狀態。
當時私庫確實只提供 scene／name／tutorial entry，未提供 map、actor、metadata、
control，故初始化缺漏是直接可修的 Server 問題。不能只調座標就宣稱通過。

## 舊資料核對及本次限定原生證據

原始 KR BIN SHA256 為
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
使用既存 Ghidra 原稿按址選讀並以唯讀 PE／Capstone 5.0.9 核對。
REA 前次請求沒有可用結果，這裡明示為靜態補查，不冒稱 REA 全函式審核。
[可重現驗證器](../verify_legacy_login_sources.py) 與
[33 個片段、12 個 bounded decode windows](evidence/S00-20261101-TUTORIAL-WORLD-RECHECK.json)
只支持下列有限事實，**不是 T01 FULL-PASS 或官方封包配對／順序**：

- 基本 handler 的 +3C／44／54／04／84／94／2E4 stores 分別指向
  4AE4D0／4AF530／4AF920／4AFAF0／4B1A30／4B24F0／4B3DA0。
  沿用已有 base+4、stride8 範圍，對應候選 app7／8／A／0／10／12／5C。
- 4AE4D0 的 cursor 為 payload+6，26B record 起點為 payload+2。
  4AEB5B 取 cursor+A（record+14）的 float，傳入 actor virtual+5C。
  CCharacter ctor4CD728 設 vtable C07B44，其 +5C 指向4C8C40。
  4C8CAD 保存此 scalar 至 actor+B4，4C8CCC 在模型路徑乘此 scalar。
  因而這個 float 是**縮放乘數，不是 Z／高度**。位置 XY 另交 virtual+44。
- 舊 `anal/login_protocol.py` 將第三 float 寫0，舊控制工具還明載依賴 Client
  zero-scale guard。這是歷史 fixture／修改版結果，不能照搬為原生需求。
  本輪 Server 寫中性 multiplier1，不改 Client，不使用 guard。
- 4AF920 讀 account alias+2、signed count+6、entity pairs+7；同 ID pair 可走
  直接綁定路徑。4B24F0 清控制後讀 payload+2 map context。先 map 再建角／綁定
  為本輪 Server 實驗順序，不是官方順序證據。

資料來源是 `kr-bulk-roy/<上述SHA>/functions/0x4ae4d0.c`、`0x4af530.c`、
`0x4af920.c`、`0x4b24f0.c`、`0x4c8c40.c`、`0x4cd6f0.c` 等既存原稿；
原稿仍保留 saved-unreviewed 的完整函式限制。不能將此次局部鏈升格為全文驗收。

目前工作區 Table.stp 唯讀解出 `Table/_MapList.xml`：

| 項目 | SHA256／內容 |
| --- | --- |
| Table.stp | ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c |
| 解出 XML | cd47d8ca42f4297f6584a2c0c8807ae76352e3b353855b3989f660e64fd27f8c |
| 唯讀 extractor `anal/stp_resources.py` | b47f343d9ab4fdc667939023c0c2fa577975ef3b07c848249a25bbcd1aea0a9d |
| ID188 | MAP town000D、TRIGGER town000.mef、BOUND town000 |
| ID190 | MAP town000D、TRIGGER scenario_town000.mef、BOUND scenario_town000 |

XML 沒有50018這一列；不能從舊幾何表別名推定它有碰撞／trigger。
資源版本以以上 archive SHA 為限，沒有假稱與原始 BIN 是已驗證的官方配套。
舊 `anal/47-new-expedition-reference.md` 的 v5→v9 逐次修正與190 blocked／188 clear
是**歷史修改版 runtime**。本輪以188作步行候選，初始231/144、序章後275/144
為 Server 實驗選點，尚未證明官方出生點。沒有執行舊 runtime probe 或修改資源。

## Server 修正與下一段實測

私庫在 `a73261e71fae777b5bb553109225fd25baca85e7` 上建立獨立 opt-in
`LOCAL_WORKING_COPY_TUTORIAL_WORLD_CANDIDATE`，只允許既有 journey route。
預設仍關閉；正式 spec pin 維持 `dd69ec9de353a695d25c6db8e362ff471ea0c137`。

1. 已認證 connection 的0C/6B只選擇自有角色；B0/2B第一次提供188、reset、metadata、
   actor（scale1）、stats、parameters、control、stats及6個timing候選回覆。
2. metadata／actor／control共用交接取得的 ephemeral wire alias，不使用舊固定帳號1，
   不將 C03 GUID 截短；entity256限定當前 connection。
3. 精確3F1000/1/1僅一次恢復275/144、control／speed／timing。不授予任務進度、
   不持久化 Quest completion；先收到事件再B0亦保留狀態。
4. 限單一自有 entity 的正常0A/11B、flags0或8000，回0B方向／移動與0C動畫。
   來源為既有 movement consumer 限定結論及舊候選，不信任 client tick為權威時鐘。
   目前沒有 Server collision／權威座標同步；不儲存估算位置、不支援移動後切角。
   不能據此聲稱多人 world authority 或完整教學完成。

數值、角色等級、速度、timing credits與事件→回覆關係都是 Server prototype policy，
不是官方平衡／任務規則。未知 CF／9E／95保持觀察，不猜 ACK。
純來源207個 xUnit方法仍9個正流程／198個暫緩；其中旅程 Theory兩列（world OFF/ON），
因此本次執行**10個 positive cases通過**。真 TCP／SQLite case驗證同alias、owned role、
map188、actor scale1、intro座標、正常移動／停止與保活；不等同遊戲畫面通過。

08:04:16 UTC獨立輸出 Host啟用（先確認無進行中 primary，不中斷人工測試）。
部署Network DLL SHA256 `90223ba8cbe9dbbba63fcaac2f088c462304d3a0ac6e4ae7af1a1234b621123e`，
Protocol DLL `40b2d32b28a7d0489f1cfbd2d1207fddf57421ead5951e7f15ae01beb89ad415`；
這是基於上述私庫commit的本輪working-tree build，不將基準commit冒稱為新版實作。
Client EXE與資源皆未修改。已用非同步結果卡通知使用者正常登入→劇情結束→
看人物／頭像→方向鍵到第一T標記→下一段提示就停；不跳教學、不切角。
**人工結果尚待回報**。完整教學任務、戰鬥及廣場仍待開發／驗收。

停權、異常封包、重送／重登、競態、故障、安全與壓測仍列待測，未執行。
