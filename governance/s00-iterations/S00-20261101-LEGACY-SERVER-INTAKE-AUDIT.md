# S00 — 本地舊 Server 收件核驗與下一段測試規劃

2026-11-01。使用者要求參考`E:/Tartaros/workspace/anal`，核對主程式、區分
使用者需求與分析確認的需求，並把相應分析／Server規劃補入本庫；實作仍在
私人`ttr_server_roy`。提到`as_server_spec`的要求已由使用者明確撤回，該專案
未讀寫。本文件是既有REQ/RR的補充審查與工程規劃，不建立平行需求台帳。

## 本次直接使用者指示

- 新帳號正常流程完成新手任務後進入廣場；非正流程測試先保留待測。
- 遊戲由使用者操作；要求測試時，Agent同時分析／開發之後流程，盡量讓一次
  測試涵蓋多個已準備好的步驟，不每改一個小處就要求重新登入。
- 參考舊本地Server，但相應主程式分析和Server規劃必須回寫本庫。
- **不修改Client，唯一例外為確認是Windows更新造成的bug**。詳見
  [最新共用政策](../../shared/CLIENT-MODIFICATION-POLICY.md)。本輪EXE未改，
  指定工作副本SHA256仍`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。

這些是本次對話的直接指示。下列舊文件中的「使用者確認」僅是歷史作者轉述，
不能未經來源核對就新增PLAYER_ADMIN_REQUEST，亦不代表本次Client版本已通過。

## 來源凍結與分類

來源均保持唯讀，沒有執行舊Server、舊測試或Client修補工具，沒有匯入舊帳號／存檔。
公開本庫只保留分析、來源hash及核驗器，不搬入舊Server實作或憑證。

| 本機舊檔 | SHA256 | 可使用範圍 |
| --- | --- | --- |
| `anal/11-channel-bootstrap.md` | `860d595a4d4fc0bf62178d4da090204b2bec6489dfb77604d26fe56a96539e8c` | 靜態caller/header線索；UID1、flags1/1為實驗fixture |
| `anal/12-channel-init-followup.md` | `b954c852c0a7f9687430e6dc0874860e309d16bdbdeee49f827035dedaab9ef1` | 歷史請求序列24/1F/25/15/A0與key2的3001；A0→60原稿已明示是假設 |
| `anal/13-character-crash.md` | `7cd9aeeca00cf845ba7bf7e3a196ca3cb805c4395aa47245290cdb8428f9c9ad` | 歷史空60→EXPD／F5後退出；不能把推測原因當已閉合根因 |
| `anal/15-missing-character-description-probe.md` | `b630a7d3ac698a9ed36a2ce90643b26067c875d4a1e755f34200feccd9953704` | 含char-test EXE guard，屬修改Client診斷；禁止照搬或當本次相容證據 |
| `anal/47-new-expedition-reference.md` | `b79992392f753f314ee9614a07dc390feea4e779278ab5b500409ae231ca31a1` | 歷史影片／需求轉述、命名→教學實驗、後續問題導覽；版本／patch依賴需另核 |
| `anal/login_protocol.py` | `2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e` | 私人舊Server候選builder，不是官方protocol authority |
| `anal/login_test_server.py` | `7385c9a5c1be5b0715ae56b189f6a584677dc657ca892377b545d233206ef35e` | 舊實驗觸發條件／資料流；未執行、不公開實作 |
| `anal/new_expedition.py` | `5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534` | 本地狀態／初始角色／教學fixtures，不能當官方後端規則 |

## 本輪實際主程式核對

原始KR BIN SHA256
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，唯讀。
REA open確認識別；原生instruction查詢沒有回傳可用Evidence，session檢查也沒有
可確認的active provider request或保留record，不把等待當作完成，也未重新啟動目標。
隨後用獨立唯讀PE映射／Capstone5.0.9核驗既有作者片段，沒有呼叫目標API。

- [可重跑核驗器](../verify_legacy_login_sources.py)。Capstone為明確外部依賴，
  本輪使用既有`anal/python_deps`，沒有安裝套件或載入Frida。
- [完整有界結果](evidence/S00-20261101-LEGACY-LOGIN-RECHECK.json)：17/17精確
  位元組片段吻合，另保存4個從指定函式入口到first-ret的線性解碼window。
- 舊E74原稿與已保存Ghidra函式為上下文；本輪重核只支持選定主張，不代表
  原函式全文CFG、所有ABI／state、T01 FULL-PASS或原版Server封包時序。

| 主張 | 分類／本輪核對 | 不能推論 |
| --- | --- | --- |
| app2讀+2 DWORD、+C起20 WCHAR，65B後53N | **BOUNDED_NATIVE_RECHECK**：4B803F、4B8075/77/7D、4B8926等精確bytes吻合 | +2業務定義、完整header預設值、N=0自動創角 |
| shared table index60→4B8F50 | **BOUNDED_NATIVE_RECHECK**：4B7DFF寫FD2FFC=4B8F50；以FD2CFC、stride8得60 | A0一定必須回60、官方交易順序 |
| app60可建角色展示scene並讀27B records | **BOUNDED_STATIC_CROSSCHECK**：4B8F50線性window見4C13E0、4B7D50、4C22C0直接call；4C22C0 prelude與保存Ghidra一致 | 空scene安全、所有角色資源已備妥、完整scene protocol已核准 |
| name sender3E len48、name source+6 | **BOUNDED_NATIVE_RECHECK**：重核E74列出的opcode／length／stack片段；+6完整def-use沿用E74限制 | 未初始化+2..5是0、官方name/create ACK已配對 |
| scene-local4A signed result→F4245、result1處理 | **BOUNDED_NATIVE_RECHECK**：4C14E1／4C21D6／DB／E0、5A689A、672617吻合 | 官方失敗碼語意或Server3E→4A配對 |
| 非空共享名稱影響page+144 | **BOUNDED_STATIC_CROSSCHECK**：5A6510 window見F938F2與+144寫入；並讀E76原稿 | 零角色必有可用命名UI、已證所有顯示／listener gate |
| tutorial consumer有TUTO建構路徑 | **BOUNDED_STATIC_CROSSCHECK**：4B9260 window見4C4AC0與4B7D50 call | 命名後只送6E就完整可玩、出生點／碰撞／任務已完成 |
| 新帳號應擁有角色1/3 | **HISTORICAL_USER_REQUEST_REPORTED／SERVER_EXPERIMENT_POLICY**：舊影片、作者轉述與fixture選擇 | 不能寫成本次直接玩家要求或原程式強制初值；若採用應明示新Server初始配置政策 |
| 空60崩潰以guard避開 | **HISTORICAL_MODIFIED_CLIENT_RUNTIME** | 不能重製guard、不能把該EXE結果當目前未再修改Client通過 |
| 教學移動／戰鬥／任務可走一部分 | **HISTORICAL_RUNTIME＋SERVER_FIXTURE**：各v版本有不同修正與未解 | 不能把整份HANDOFF叫新帳號E2E通過，也不能把AI替代戰鬥當原生恢復 |

## 下一段應實作與驗證的完整片段

以既有REQ-0001..0005與RR-0002／0009／0010／0008去重，不另造官方需求或
解除GAP。私庫後續實作應將新帳號的以下概念分開：Account、ExpeditionProfile
（可持久化名稱）、帳號擁有的固定role index、world entity／Session。既有C03
人造character GUID/name domain測試不能自動當此遊戲的正式角色模型。

1. **Server資料前置**：同一已授權lease／account建立或讀取ExpeditionProfile；
   初始role配置如採1/3，明示為新Server政策並持久化，不硬塞「官方所有角色已擁有」。
   舊accounts.sqlite3／換裝存檔保持唯讀，不匯入當前fixture。
2. **角色資料＋scene候選**：同一權威profile產生full roster與scene record，
   核對同一role集合、名稱／index、必要資源。**禁止重跑已知空60崩潰路線或補Client guard**。
   Scene切換觸發僅能作可關閉的相容性假設，不能冒充已證A0→60官方交易。
3. **命名**：嚴格解析3E/48B與+6字串，保留+2..5未知；以server端獨立名稱／ownership／
   transaction政策保存，再由有界4A consumer候選回覆。命名與新增可操作角色分開。
4. **教學入口與存活**：核對6E／scene／resource gate、教學中的ping/heartbeat與
   初始entity／control／collision；舊900/900、map190/188、AI戰鬥數值不能直接當官方設定。
   先備妥入口後正常流程所需的最少後續回覆，不只送scene就要求玩家重登。
5. **一次人工測試片段**：fresh login→選服→角色/命名畫面→送名稱→進入教學第一畫面。
   只有這些步驟已準備、合成正常前置通過後才請使用者連續驗；Agent在此期間
   繼續處理下一段正常移動／NPC／任務。未備妥的步驟如實記錄，不先稱一次必成功。

本輪另已修正空清單gateway漏接1F/25的正常請求，8正向前置通過，local Host已更新；
使用者不需為此單獨再跑一遍。後續批次流程完成再安排人工驗證。
停權／錯誤／重播／斷線恢復／併發／資安等仍在唯一待測清單暫緩。
