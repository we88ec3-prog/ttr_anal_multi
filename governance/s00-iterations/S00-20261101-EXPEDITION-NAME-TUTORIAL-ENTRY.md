# S00 — 冒險團資料、命名與教學入口的可連測實驗

2026-11-01。接續[舊Server來源分類審查](S00-20261101-LEGACY-SERVER-INTAKE-AUDIT.md)，
以既有REQ-0003／0004／0005和相鄰RR-0002／0009／0010／0008推進工程。
使用者要求參考本地舊Server、核對原程式及來源、分析／規劃回寫本庫，並在玩家
測試時開發更後段，盡量一次驗多步。Client保持不變，僅確認Windows更新bug例外。
沒有操作另一個`as_server_spec`專案。

本輪public branch基於`a71e14e521e99b9f9a3a63c11e0c98c9e5ad6a73`、private
branch基於`8ab97f59c372339ae2f79bd743c707a5aeff255d`，皆為尚待合併的前置PR。
不得把開發分支或本報告當作SPEC STABLE／main正式契約。

## 原程式核對與未知

KR原件SHA256仍
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，唯讀。
沿用前輪E74／既存Ghidra來源，擴充[獨立唯讀核驗器](../verify_legacy_login_sources.py)
與[本輪原件結果](evidence/S00-20261101-EXPEDITION-ENTRY-RECHECK.json)：
19個精確片段吻合、7個有界線性解碼window。沒有執行／附加／修改目標，未呼叫遊戲API，
沒有T01 FULL-PASS或原版Server trace。

- 4B7DFF為shared callback index60→4B8F50；局部見4C13E0建構、4B7D50、4C22C0。
  app60的2+27N形狀與保存反編譯互證；**A0→60仍為新Server假設**，不將空scene崩潰
  路線當正常驗收，更不移植舊Client guard。
- E74已有3E/48B/name+6與4A signed16→F4245/result1／F938F2限定來源。
  本輪重核其中bytes；**官方3E↔4A／4A→6E配對未知**，+2..5不保證0。
- 新增4B7E1F精確bytes：`C7056C30FD0060924B00`，寫FD306C=4B9260，
  相對FD2CFC stride8為6E。4B9260局部見4C4AC0（TUTO）與4B7D50，
  只證有相應consumer能力，不證教學可玩或官方命名後必然流程。
- 新增49319E..4931A8：載EDX=494780並寫main object+398；以已有T02表慣例
  +208/stride10計算index19。494780 prelude見F93934 outstanding counter減1，
  條件分支49481A..494857讀payload+2 DWORD並作時間欄位更新。第一window在早期ret
  截止，第二window明示是條件block而非新函式入口；不宣稱全文CFG已閉合。
- 保存Ghidra `0x494780.c` SHA256
  `4719d343eb05da993365e1fb916b45f27ef08b33b568c2fd416975ff6883d6ad`，
  raw `20261025T182755495890-batch-20261025T184252760385-2688.json` SHA256
  `e3fa676b54d258d87770fe3530773dba717178f58d30045d5643946d4e8e9ce9`。
  C2S10→19採舊Server所用相容性假設與本機monotonic counter，非官方時鐘契約。

## 新Server資料與流程規劃／實作對應

| 項目 | 來源類型與目前實作 | 不升格的界線 |
| --- | --- | --- |
| Account／ExpeditionProfile／owned role indices | Server-owned model，同SQLite transaction驗exact lease與帳號，再讀寫profile/name/角色集合 | 既有一般C03 CharacterId/domain mock不是原生固定角色ID，不混入wire |
| 初始role1/Soma、3/Shubalman | 新Server明示starter policy；先前影片／作者轉述只作參考，首次profile建立時一次持久化 | 不是本次新玩家直接要求、不是原程式強制初值；不grant全9角色 |
| SQLite元件 | 明確offline CLI新增local_expedition_component/profiles/roles，版本1／definition；Host僅驗證 | 不更改global user_version2、不冒充C05的3/4/5遷移，廣泛部署／回復待SFD |
| Full roster | 同profile產生65+53N；name持久值，rawID1/3；header/row數值明示實驗配置 | +2alias、+36/+38=1、row+2A=1與其他0不是官方業務／預設值 |
| 非空展示scene | 同一role集合產生2+27N app60，26B/context全0為實驗配置 | 不使用已知空60崩潰fixture、不做Client guard；目前UI結果未驗 |
| 命名 | 解析48B/+6 NUL UTF16，忽略未知+2..5；1..19碼元／trim/control/Unicode正規化唯一性為Server政策，transaction持久後發positive4A | 不猜負值碼、不假稱官方建角交易，名稱不是新增可操作角色 |
| 教學入口與保活 | 名稱接受後候選4A、6E；C2S10回19+monotonic DWORD；metadata分開記錄 | 送出入口≠Client教學載入、可控角色、任務完成或廣場 |
| 較長正流程連線 | primary交接後用exact lease正常renew一次30分鐘並保存新revision；primary/auxiliary30分鐘上限，primary1MiB預算 | 登入選服grant仍2分鐘；不宣稱長連線恢復／重新登入／多節點已驗收 |

Server密碼、profile實際名稱／DB／舊Server實作不放公開庫。舊accounts.sqlite3、
角色換裝存檔和原始證據不匯入／不覆寫。`SFD-0010`記錄較廣泛的元件遷移、starter／
Unicode政策、PostgreSQL與長Session／world身份整合，非Client未知的新RR替代品。

## 已驗證與準備給使用者的一段

私庫新增第9項HappyPath，真SQLite＋TCP：明確元件初始化、新帳號認證／主線轉移、
profile角色1/3 roster、正常26/24/1F/25/15/DA/D2/A0請求、scene、命名持久、
4A與6E、10/19保活，並獨立查DB確認名稱及revision。這是合成Client行為，
不是原版Client runtime。其餘198方法仍暫緩，沒有故意黏包／錯誤／重播等專項。

完成部署後，下一段人工驗證為：fresh login→兩分鐘內選服→觀察角色展示／命名
UI→輸入簡短新冒險團名→停在教學第一個畫面或第一個錯誤。Agent同步開發下一段
entity／control／collision／任務，不能因發出6E就讓玩家測尚無資料的移動戰鬥。

**目前B0仍只記PRIMARYWORLDINITIALIZATIONPENDING，未回覆虛假的world-ready。**
此輪不代表教學可玩，完整目標仍是新帳號完成新手任務後進廣場。
REQ／RR／GAP／SPEC／CLM／ADR／正式TEST不升格；native admission OFF，規範pin仍
`dd69ec9de353a695d25c6db8e362ff471ea0c137`。

## 本機部署快照

07:23:52 UTC先以SQLite一致性備份保存隔離v2DB，再明確執行expedition component v1初始化；global user_version保持2，未匯入舊存檔。07:23:54新Host啟動health顯示JourneyEnabled=true、所有遊玩計數0、native仍OFF/BLOCKED。這只證服務已就緒，尚無本輪遊戲命名／教學runtime成功。使用者已獲完整連測步驟，Agent繼續後段world初始化。

## 人工實測：展示／命名／教學入口已推進，world資料仍缺

使用者回報輸入測試名稱後命名視窗確認無反應，並提供第一張截圖，能看見兩角色
模型、對應彩色頭像及原生「創立冒險團」視窗。原圖只保留本機，不公開實際名稱，
SHA256 `58925f71fd9dd15a36b680390ae5695dd39eb48b80d3c45a01a290652e8167f5`。
當次07:25:38 UTC已TX175B角色資料／60Bscene，07:25:44 RX14B後Unavailable/CLOSE，
尚無完整3E。舊版沒有opcode metadata，不能將那筆資料逐byte認定為3F。

對照舊metadata曾有8B C2S3F，本輪補為命名前scene-script report可觀察而不關線，
不授予任務進度。另對**已認證primary**只記u16 application_command與payload長度，
不記本文／名稱／grant／密碼；尚未實作的背景要求維持有界連線、明示Unavailable，
不回猜測ACK、不產生狀態修改，也不讓它阻止後續已支援命名。
這些是本機實驗政策，非官方錯誤處理契約。

07:30:46 UTC v2 Host啟動，主線metadata如下：

| UTC | 實際證據與限制 |
| --- | --- |
| 07:32:29 | AUTHACCEPTED，登入回覆TX163；同一指定工作副本／隔離帳號，Client未修改。 |
| 07:32:32 | full roster TX175、scene TX60，PRIMARYEXPEDITIONSCENESENT；後續F5/2B可見。 |
| 07:32:34.8394485 | 已認證header metadata明確觀察C2S3F、8B，命名前被正常記錄，未授予Quest狀態。這是v2的新觀察，不冒稱舊v1的精確opcode已保存。 |
| 07:32:41.288116 | C2S3E/48B；transaction命名後TX8B（4A frame）及TX7B（6E frame），NameResultSent／TutorialEntrySent。 |
| 後續 | 使用者明確回報「命名視窗關閉，出現教學／劇情畫面」。獨立DB唯讀查詢證同fixture名稱非NULL、revision2、owned roles仍2筆，不公開名稱／帳號ID。 |
| 07:32:41–42 | 0C/6B、B0/2B，另CF/4B、9E/2B、95/2B；world initialization未實作的項目明示Pending／Unavailable，沒有假回覆。 |
| 持續 | 10/2B→19 payload6B（raw frame10B）保活持續，包含07:33:10；不能把不斷線當作可玩。 |

使用者隨後回報劇情結束後「錯誤地圖or位置，workspace以前開發也碰過」，並提供
第二張截圖：教學提示、空白人物資料／未見可控人物，背景仍像EXPD展示區；截圖
本身不能確定mapID或精確座標。原圖只保留本機，SHA256
`a61186bac4a69e88d803e860e20456455f689779ccfd66c9ae2ba975fadaa6fa`。
當前Server確實尚無送出完整map/context、actor/control/collision初始化，不能只
改某個座標便宣稱解決，也不使用舊Client zero-scale guard。

第一版Network DLL SHA256
`bb3f5016e0515876470077aaa87be12e2c05970e62ce47e3ab2c7bfbca5bd1a1`，
v2為`4bd009fa6c4e8672579670e91ca8cddd5e48900295c1834bde9eb87b31e6c06e`。
它們當時為本工作分支尚未提交的本機build，不以基準commit假稱含所有改動。
metadata本機定位為`local-login-auth/expedition-journey-runtime-logs/`與
`expedition-journey-v2-runtime-logs/`；原封包未保存。

REQ-0004追加GAME_RUNTIME_OBSERVATION紀錄UI推進與命名阻塞／修正。
新REQ-0010以本次真實world缺漏觀察登記：教學map/actor/control初始化，不與
REQ-0004的角色展示／命名UI混同；沿用RR-0008／scene-flow gap，不新增同義RR。
後續修正分析／規劃見[教學world bootstrap](S00-20261101-TUTORIAL-WORLD-BOOTSTRAP.md)：
目前map資源對應、actor scale欄位、同alias控制、候選序章位置及正常移動回覆；人工結果待回。
原SPEC/RR/GAP/CLM/ADR/TEST不升格，完整教學任務與廣場仍未完成。

使用者另要求「可測時直接以提問卡列出點到哪、詢問測後反應」。使用非同步提問，
玩家回覆不阻擋獨立分析；這是任務協作偏好，不造一筆Server產品需求。
