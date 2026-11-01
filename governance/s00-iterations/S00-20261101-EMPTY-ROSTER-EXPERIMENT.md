# S00 — primary 交接後的零角色清單實驗

2026-11-01。接續[已觀察的登入／primary 交接](S00-20261101-LOGIN-REPLY-RUNTIME.md)：
使用者在06:33:01 UTC正常按連接，私庫紀錄 PRIMARYHANDOFFACCEPTED 後停於
PRIMARYAPPLICATIONUNAVAILABLE。這是 REQ-0003／SPEC-CHAR-0001 角色清單階段
的實際開發前提，不是角色畫面或教學成功。

本輪在尚待合併的 PR93 分支 `a88eef6dfe526697cf41da3b9f836d239b562895` 上
建立後續分析分支；私庫基於 PR20 head
`1bc3b4dfa356ecb0f6042d9727fb83e85def5243`。兩個前置 PR 尚未合併 main，
不得把工作分支當作最新正式規範。

## 使用既有來源，不重寫原任務研究

- KR 原件 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- SPEC-CHAR-0001 仍 DRAFT/PARTIAL：full app2 為65B prefix＋53B/row；有早於
  row-count gate 的 header/name 讀取；N=0不保證自動開創角 UI。
- E74 原稿 `kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md`，
  Git blob `f3d4f126c5ce6a60a871189ca44015dc4693b97b`：既有作者的限定指令片段
  4B803F讀+2 DWORD、4B8075..82從+C複製20 WCHAR、4B8926..4B894C計算N、
  4B8AC4..E4在loop後queue C2S24。不是本輪獨立重跑作者 verifier 或 T01 FULL-PASS。
- 保存的 `kr-bulk-roy/<KR SHA>/functions/0x4b7f00.c`，Git blob
  `871c336add31a6ad3ddabce41c1a284bc37c41bb`、派生檔案SHA256
  `f3af6aedb877f9f76964df0878ee8f74472bea4625b0598f2df48c4abc840c55`。
  對應 raw `20261025T182755495890-batch-20261025T184011211323-32.json`
  SHA256 `7ce6221dbdc85ef76658ed1f83f6244eae1c766db0002eff4b3a5cb733604825`。
  偽碼只是既有未逐函式審核資料：讀+36/+38 word、+3A short、+3C byte、
  +3D DWORD，後續可queue C2S15/A0及key2的候選訊息。不能據此指定官方回覆。
- REA 本輪 open 僅確認原件識別；後續 byte query等待未取回可使用的結果，
  之後正常 close。**沒有本輪新的原生 instruction proof**，不以工具啟動當驗收。
  原件與遊戲均未由分析工具執行／附加；仍由使用者控制指定工作副本。

## 實作的精確假設

私庫新增獨立明確開關
`TARTAROS_LOCAL_ROSTER_MODE=LOCAL_WORKING_COPY_EMPTY_ROSTER_CANDIDATE`，
必須搭配既有reply experiment；使用相同SQLite provider，先依轉移後exact lease
做transaction-authorized roster query。非授權或非零角色時明確Unavailable，
不能把真實名單換成空名單，沒有補造角色或角色初值。

| Prefix | 已知／未知界線 | 本機實驗選擇，非官方值 |
| --- | --- | --- |
| +0 u16 | 已有app2 consumer | 2 |
| +2 u32 | 已知copy；業務含義未知 | 既有 ephemeral wire alias |
| +6 u32、+A u16、+34 u16 | context未定義，不宣稱padding | 全部明示0 |
| +C，40B | 已知20 WCHAR name source；不等於Server建名契約 | 新帳號尚無 ExpeditionProfile，以空名稱實驗 |
| +36/+38/+3A u16、+3C u8、+3D u32 | 有界來源讀取；完整語意與合法值集合未知 | 全部明示0 |

因此此回覆是**可關閉的相容性實驗候選**，不是S00核准的正式wire contract。
序列化器要求caller明確提供每個數值，名稱採strict UTF-16且最長19 code units
留NUL，是保守Server政策。不能把zero當原版初始化值，不能因65B完整就說Client安全／UI就緒。

primary送出的inner65B以既有raw frame封成69B，保留metadata事件。
C2S24只作來源界定的後續請求觀察，計數／事件名稱的Completion僅指本地loop後續，
不是正式ACK或角色可用；C2S15/A0不猜回覆，其他app維持Unavailable。
roster mode的auxiliary保持bounded receive，不在第一chunk即關閉；沒有第二次
C02 Claim、沒有推定其身分驗證與未知opcode回覆。

## 驗證與下一個實測

Release Host編譯成功；8個正流程前置通過。新增真SQLite／TCP測試涵蓋新帳號正常
登入→主線交接→transaction確認空名單→收到69B frame→既有geometry inspector確認N=0→
模擬Client送24並由gateway觀察。這是合成Client行為，沒有新增真遊戲roster成功證據。
待使用者fresh login／選服／連接後，核對PRIMARYROSTERSENT、24／其他後續metadata及
實際畫面，再找下一個最小缺口；不要求現在執行停權、壞輸入、過期、重播或故障專項。

REQ-0003既有CODE_ANALYSIS與原runtime前提沿用，沒有在尚未實測時新增假的
GAME_RUNTIME_OBSERVATION。RR-0002／0010與GAP／SPEC／CLM／ADR／正式TEST狀態不變，
native admission仍OFF，規範pin仍`dd69ec9de353a695d25c6db8e362ff471ea0c137`。
接下來仍需角色UI、Expedition命名、真正可操作角色建立、教學與廣場，沒有Client修補。
