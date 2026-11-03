# S00 GAME_RUNTIME_OBSERVATION：全新測試帳號登入後無回覆

使用者依首次教學測試卡回報：「無法登入，帳密送出後卡住」。
指定Client工作副本SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`，
靜態KR目標SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
Host為已部署v10來源`cd2a7bc70f3cfb92602628137bf65c5df81b0eb2`，loopback驗證，
這不是未修改原版Client或官服交易證據。

## 已觀察的正常登入卡點

在對應測試期間，兩個登入連線各有RX118、AUTHSTARTED、AUTHACCEPTED、
AUTHPROVIDERUNAVAILABLE、CLOSE；**沒有TXSTART／TXCOMPLETED**。
UTC認證成功分別為2026-11-01T17:02:03.7921668Z、17:02:49.8305367Z。
外部精確程序查核確認Host51020／Admin2452存在，authBound及journey=true、Admin200。
健康累積accepted3、replies1、providerUnavailable2含先前成功，不能將累積值全算本輪。
直接讀取metadata JSONL，未記錄原始帳密／封包，公開不含連線識別或帳號名稱。

## 私有Server程式定位與原因

登入credential驗證成功後，LocalLoginReceiveGateway呼叫
LocalLoginReplyExperiment.BuildReplyAsync，再將完整登入name傳給
LocalLobbyHandoffBroker.IssueAsync。該候選明確只接受1..9 printable ASCII顯示字元。
本次S00建立的新fixture為10字元，因此在發回覆前觸發ArgumentException，
gateway廣義catch將它歸為AuthProviderUnavailable，使用者停在登入頁。
這是**Server候選實作限制與測試準備不一致**，不是密碼錯誤或已證Client帳號9字元上限。
未讀取原始封包體，單靠metadata本身也不能辨認例外類型；因果定位另依上述確切程式路徑。

## 已採取的修復與仍未完成項

1. 隔離測試fixture建立工具先檢查3..9 ASCII帳號字元，避免正常首次教學卡片再給出不相容帳號。
2. 保留舊fixture／證據，另建立較短的新fixture，密碼仍為使用者要求的簡單測試值，不公開。
3. 新fixture獨立唯讀baseline確認無profile、角色、裝備、首戰、教學、session或character；
   不改Client、不重啟Host、不遷移或補種進度。
4. LocalDev Release build零警告／錯誤，實際正常建立短fixture成功。
   已另送完整正常教學回饋卡；**Client登入及完整fresh教學結果仍待回**。

這次限制fixture工具，不宣稱解決所有3..32字元一般帳號的相容性。
一般帳號與wire display名稱分離、回覆階段的安全診斷分類及更長名字協定相容性，
仍需後續設計／原生確認；不得直接截斷帳號身分或修改Client遮掩。
本輪非刻意執行邊界／錯誤測試，係正常驗證中發現的缺陷。原先暫緩案例仍不執行。

REQ-0001追加本GAME_RUNTIME_OBSERVATION，狀態仍CANDIDATE；
台帳19REQ／CODE5／RUNTIME25／PLAYER8／APPROVED0。整體goal、Quest結算與獎勵缺口未結案。
