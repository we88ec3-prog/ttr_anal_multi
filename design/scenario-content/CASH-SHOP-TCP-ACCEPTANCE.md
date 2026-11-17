# 商城 TCP 正流程與 Host 配置驗證

2026-11-18 接續 [付款與領取](CASH-SHOP-CHECKOUT-AND-CLAIM.md)。實作基準為私有 Server `d3f5cb36aa53e39535626120d8594b3d81145a06`、規劃基準為本庫 `410f5d502b89434bf077c3461e6cecd28ce6a074`。本輪新增 TCP 測試及啟動器商城配置，不改 Client 或商城交易演算法；實機與換版維持暫停。

## TCP 證據的確切範圍

新增 HappyPath `Cash_shop_over_TCP_after_the_new_account_tutorial_and_mainline`，沿既有 `RunNewAccountJourneyAsync` 建立新帳號，經 login／primary handoff、冒險團命名、教學、廣場及主線，再接商城。前段使用既有合成地形與經驗政策，不是本輪重新驗過原版 BND；原版地圖的離線檢查仍引用既有收據。

商城使用 `LocalLoginReceiveGateway`、`LocalLoginReplyExperiment`、正常 `LocalExpeditionJourneyExperiment`、SQLite 與實際 loopback socket。每次重新登入都送原候選 112-byte login，從回覆複製 primary handoff，再從冒險團展示頁選角色進廣場。TCP 由候選 frame encoder 發送，測試讀取實際 `1A68` 出站 frame；沒有直接呼叫商城 session 或領取／穿戴／銀行寫入方法。

測試資金由隔離錢包工具建立 8,200 LeeLoo、7 BP、1,000 Garnet，背包容量採工具的 100 格。這是可追溯的測試前置，不是官方充值服務；本路線只使用少量格位，40 格正常起始容量與背包擴充仍依既有測試。保管箱記錄、時裝及書本則全部由真實 C2S `00AC` 的付款交易產生，沒有 SQL 預置商品。

1. 第一次正常進廣場收到 `00DD=1000`、空 `00E2`。送五列購物車：29769 兩件、5238 兩組各 200 本、27461 一件。出站次序為餘額 `00DD=694`、五筆追加 `00E3`、明列結果 `00DF`；資料庫背包仍空。
2. 關閉該測試連線並等租約釋放後正常重登。初始化恢復 694 和五筆保管箱記錄，按收到的雙鍵逐筆發 `00AD`；實際收到背包 `002C` 與 `00E3` 精確移除。兩件時裝保留不同 GUID，400 本分為 255／145。
3. 發原候選 `0023`，伊希莉亞在 slot 10 依次穿戴兩件時裝。實際收到 `0070` 的 Item 13401 與包含此 Item 的 `00FA` 外觀清單；此處核封包，不宣稱畫面渲染。
4. 普通廣場建立單人隊、選馮德斯村、完成 `0043` 載入並離隊。村莊初始化已發布 `00C2` 倉庫快照；依普通移動封包走到銀行，再送已有的 `0086` 特殊商店請求。每次 `008D` 存取都收到 `002C/00C3`。
5. 舊時裝存第 79 格後取到背包第 10 格，核 GUID 不變，再穿回並把換下件銷毀；145 本存第 78 格，分 100／45 取回，再銷毀這一格。銷毀均收到背包變化及 `0062`。
6. 再次正常重登：保管箱空，已穿時裝恢復，背包只保留 255 本與一件內容點數書；LeeLoo 維持 8,200。主線最新 snapshot_json 與商城操作前逐字相同。

既有 `0010 → 0019` 查詢用來讀完有序 Server 出站佇列，不當成 Client ACK、交易成功或畫面完成。沒有原 Client 執行／附加、封包擷取或公開監聽。

首次跑到銀行時，測試錯將銀行當主線 NPC 劇情互動，等待不到預期回覆；改用既有銀行 `0086` 路徑後整段通過。這是測試操作修正，沒有為測試修改 Server 銀行判定。失敗／成功 TRX 各自留在私有本機 TestResults，未覆寫。

## Host 配置與啟動器

`tools/start-phindos-acceptance-host.ps1` 增加 `-IncludeCashShop`。它先核對公開／私有商品投影都為 SHA `1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd`，再設定兩個商城目錄環境欄與現有裝備模式。健康資訊必須回報相同目錄 SHA 才通過，收據追加 `cashShopCatalogSha256`。

本輪以 `-IncludeCashShop -PreflightOnly -IsolatedPorts` 啟動實際 Release Host，使用自有 preflight SQLite 副本與 15082／18415／18414／18416 的隔離 loopback 監聽。首次副本的舊主線元件不合現行 V2，原錯誤日誌保留；用已檢閱的遷移工具升級這份副本後重跑通過。沒有修改來源資料庫或現行實機存檔。

成功收據為本機 `outputs/cash-host-preflight-df31afd34bed48efb391f4452f053310/receipt.json`，SHA `a350c04bd87930d338441476c5494b4b467c1e38c822efc3679764c12037e409`。`retainedHost=false`，結束後四個隔離埠均無監聽；商城目錄 SHA 相符，其他四條普通狩獵場配置檢查保留。這是 HOST_CONFIGURATION_ONLY；上節 socket 旅程是另一個隔離 gateway 實例，不將兩者合稱原 Client 對實際 Host 已驗收。

## 保留的未完成

後續 [商城道具使用](CASH-SHOP-CONSUMABLES.md) 已在同一 TCP 路線加入 27461 的正常背包使用，最終 CP 5,000 且書已扣除；另補兩本 CP 書及 5238 回復書的正常使用，最新套件為 569 項。上文 566 項與未使用書籍的末狀態保留為當時版本證據，不能視為最新版本仍無法使用。

最終 Host／檢查器 Release 建置各 0 warning、0 error，完整 HappyPath **566/566** 通過。獨立 TCP 案例通過 1 項，完整套件收據 SHA 為 `2413b5d7dd330f736dfdb0023868e71566ea4f9a8cd2f8cbc0df4fd06a741cec`。[摘要收據](cash-shop-tcp-validation.json)保留初次銀行操作失敗、修正通過與最終完整套件各自 TRX hash／計數；原始檔留私有本機 TestResults。

指定 v2 的商城實際開窗、價格選項、結果／保管箱 UI、拖曳與模型顯示仍待 CS-01。限時／促銷、class 30 直接效果、其他特殊商品及時裝 OPTION_LIST／套裝數值仍待開發；未知模型鍵保留。原生 MEF、官方付款與官方 Server 規則不因本輪 socket 通過而成立。正式 REQ／RR 與驗收狀態不自動提升。
