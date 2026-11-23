# 占點期限前省略重複觀察

2026-11-24。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**，接既有 D06／SP06／OPT04。
沿用 RegionHeld 的同一占點規則，補[區域退休索引](REGION-OBSERVATION-RETIREMENT.md)之後，
未完成占點在靜止期間仍逐次掃描／測距的部分。不改 Client、封包、schema、關卡或獎勵。

## 執行與生命週期

每個 instance 保存上次有效觀察位置，以及目前最早未完成占點的起點／所需秒數。
同位置且尚未到期限時，省略占點的 outside-reset／來源清單掃描；沒有進行中占點且同位置時亦可省略。
到期限仍跑原本宣告順序的清單，不依 dictionary 順序發旗標，也不把等待時間直接當成占點完成。
保留 TimeProvider 單調時間與原 elapsed 比較，沒有將秒數換算成可能溢位的絕對 tick。

角色位置變更立即使快取失效，原 pose callback 仍重設已觀察離區的占點；
即使在兩次 scenario poll 之間離區又返回，也不能沿用舊起點。
canHold=false、主線 Encounter→Portal／演出重設、正式新節點／實際 loop entry 均清除進度與排程。
Fork 複製自己的位置／期限／統計，沿用既有獨立 starts dictionary 與 pending mask；
不可讓規劃副本修改正式 instance。RegionHoldSeconds 仍由目前時計投影，未改顯示進度。
RegionEntered、清場倒數、出口與分支選擇仍在原 ObservePosition 執行；省略範圍只限占點。

新增唯讀 `holdObservationWork`：期限前省略 poll 數、排程建立數、有效占點數與是否有期限。
既有 `regionObservationWork` 保留精確測距及宣告清單的保守比較基準。
這些是 Server 工程統計，不是遊戲流程、CPU 利用率、Client 腳本下放或原生 MEF 自主戰鬥證據。

## 同內容驗證

重用既有 Q119 封門保存版，沒有重存或修改歷史 ZIP：scenario SHA256
`9e65baa388571a3827ce70e36f39597cec4a4771239dee12586f439200979fb5`。
原件 BND、2.5秒占點、局部封門、出口及原 AI／經驗政策保持；工程帳號已準備教學／Q15／Lv15。

- 新增兩個 HappyPath，以獨立原 full-scan 參考模型核對重疊占點、不同期限、離區再入、
  兩 poll 間 pose 離區／返回、演出暫停後重新累計；既有 fork、loop 重設及增援占點測試保持。
- 原控制與保存占點版，各 stop／cap 正常 TCP，共四路；分別5,936／5,984EXP、一次Q119、同隊返村與Q120進度通過。
- 同一檢查器與保存版另分別載入舊 Network `1ed2e334…` 及新 `574b3cf0…`，各走 cap。
  全部1,676則 primary 回包只做既有精確 fixture alias 正規化後完全相同；未擴大忽略欄位或刪除回包。
- 舊／新同路線到 opened 快照，精確區域判定147→54。新版本 holdStarted→beforeDue 為52→52，
  同期間省略計數468→491；到 opened 仍正確設旗標、解除屏障並只送兩筆既有0048。
- 獨立實際時計 Host 走八節點正常 cap 主線，持續占點到2.5秒後通行，5,984EXP、一次Q119、原隊回Map182。
  Host holdStarted→beforeDue 精確判定41→43、省略313→331；即時快照不是每次 pose callback 的全量記錄，
  不能把兩張位置相同的快照推論為期間完全沒有重算。此場保持有效占點且期限前不開門。
- Host 停止後只在 DB／日誌的新副本讀回，累積經驗與Q119的5,880EXP／40熟練度保存正確，原檔 SHA 保持。
  三 Release 零警告／錯誤；812 HappyPath 零失敗／略過。

收據：[hold-deadlines-20261124.receipt.json](../testing/hold-deadlines-20261124.receipt.json)，SHA256
`79025ae513272945228830771fe94b9176851d45f2883cbb1bc5bf7688777ee2`。
初版稽核誤將即時兩快照當成連續靜止，要求 Host 期間零測距；修正該稽核並保留原稿，
重用原場次通過，未改 Server／Host／TCP／TRX 來配合。合成連續靜止的零新增測距斷言保持。

占點／離區語意與回包等價已有工程證據；指定 v2 畫面、自然新帳號、實際 CPU、原生門／碰撞呈現及
其他 MEF 功能未因此升格。未執行遊戲、改原件／現用服務或重跑延後套件，整體 MEF 目標保持開啟。
