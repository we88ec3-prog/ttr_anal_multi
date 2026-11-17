# 商城髮型與染髮用品

2026-11-18 接續商城功能。分析基準 `96a2f6e60c36460c193a2be56790f89892379e19`，私有 Server 基準 `553030cbc852d294839abef7f2e7f42dc5020e23`。本批以原件靜態證據接入正常廣場／村莊使用、髮型髮色保存及既有裝備外觀。指定 v2 實機、換版仍暫停。

## 來源與原生欄位

[來源投影工具](../../governance/client-variants/20261118-cash-shop/build_hair_catalog.py)核對原 Table.stp、Character/Cha/Base.stp、Character/Cha/Hair.stp 及既有商城目錄。輸出 [Server 髮型目錄](kr-source.hair-items.json)的 SHA-256 為 `e7c8e069ec33b870f65fe92788b03de5ee638cbeea9be6110d19bbdabaa837ff`，獨立 `.hair-items.json` schema 明示 `NOT_NATIVE_MEF`，不改 Client 資源。

| 載體 | SHA-256 |
|---|---|
| KR BIN | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 指定 v2 | `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c` |
| Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| Character/Cha/Base.stp | `ad5e92f9ef63afa1c2f5849823291c8ae3de7f885ece24fef1b6d771b03a9185` |
| Character/Cha/Hair.stp | `bd99ebd799c5ebdac6b1e71a666294f5ca258ad282ff2d565ea4218554b78efa` |

逐 member 指紋在[來源收據](../../governance/client-variants/20261118-cash-shop/hair-source-verification.json)。90 種現可購染髮 Product 對應 class 38／Action 13；119 種髮型 Product 對應 class 39／Action 14。兩者都是 priority 5、group 6、堆疊上限 100，USE_LIMIT 指定角色。Action 13 的 VALUE 是色號；Action 14 是髮型模型 ID。所有必要 style／variant 都沿九份原角色 Hair.ipk 定位到 Hair.stp；984 份不同原 `.itm` 描述檔逐一驗 root `EquipIdentifier=8`。沒有將商品 Item ID 當髮型模型 ID。

HairItemActionList 對已列出的資料與 ItemUsableTable 交叉吻合；Product 15787／Item 4877／角色 3 在前者沒有列，後者明列 Action 14／31233，對應的原 IPK／描述檔也存在。保留這項缺列，沒有假造補入原表。HairInfo 的 SingleColorHairList 不等於所有缺色號情形；31233 尚有十組現可購染劑的精確色號不存在，逐組記在收據。

REA 字串查詢曾在 300 秒逾時，沒有取得新原生結果；之後使用既有固定 SHA 大量反編譯導覽及本機 Ghidra 12.1.4 PE loader，`-readOnly -noanalysis` 對九個有限視窗反組譯。[來源索引](../../governance/client-variants/20261118-cash-shop/hair-source-index.json)、[指令原文](../../governance/client-variants/20261118-cash-shop/hair-instructions.txt)、[唯讀驗證器](../../governance/client-variants/20261118-cash-shop/verify_hair_native.py)及[原 BIN／v2 收據](../../governance/client-variants/20261118-cash-shop/hair-native-verification.json)保留身份。885 條指令／2,745 bytes 與兩個固定原件相符，17 個限定錨點通過；這不是全文語意 FULL-PASS，也沒有執行、附加 Client 或執行原 Lua。

已存在的 `0070 → 4E2400 → 509A80` 接收鏈在 `509AC7/CB` 讀 payload +3 WORD／+5 byte，寫到角色裝備記錄 +100／+102。`6007D7` 染色前讀同一 +100 髮型，查 HairInfo 單色集合；預覽 `475510` 先由 `6DD0E0` 取得部件類型 8 的現髮型／色號，再依 Action 13／14 替換值，單色重設 0，交給 `6DC180`。因此前述裝備頭部欄位現在可有界定型為髮型與髮色，舊「語意待核」限制在此子範圍獲得補證。

`600AE3` 將此類無額外選項的普通用物送往既有 `4A39F0`，形成八 bytes C2S `0021`（背包種類／格／Product），不增加角色或任意資料欄。角色由 Server 當前已擁有的場上角色決定。既有 `00F9/00FA` 模型列表用 style ID／color variant／secondary 0，最後仍走 `7A7240`；原模型 getter 亦明列類型 8。

## Server 規則與保存

Host 可載 `TARTAROS_LOCAL_HAIR_ITEM_CATALOG_PATH`／`_SHA256`，要求已啟用商城及裝備支援；`-IncludeCashShop` 集中配置會核對公私兩份目錄的 SHA。髮型用途不靠 Product 數字區間推測。

Trade V28 新增 `local_role_hair(account_id,role_index,style,color)`，與帳號背包及已擁有角色外鍵關聯。正常廣場或村莊使用時，同一 SQLite 寫入交易驗 lease、角色、指定背包格、原表資格、色號與 group 6 冷卻，扣一件並保存新狀態；成功提交後發 `0070 → 00F9 → 00FA → 002C → 00B7`。group 6／一秒沿用既有 Server 規則，原表僅證群組。

無已存髮型時，首次使用採該角色原 Hair.ipk 中唯一的具名主預設髮型與色號 0；這是明示的 Server 初始政策，不宣稱還原官方新帳號資料。普通換髮型保留目前可用色號；新髮型為原表單色或缺該精確 variant 時重設 0。染劑要求目標非單色且精確色號存在；不採 native 模型查找的逐級降低 fallback 來冒充選定顏色成功。缺色號與拒絕操作的實機反應仍列待驗。

`0070` 零列長度 6 可只更新頭部，原接收器行數計算不改裝備。之後每次普通換裝、完整裝備快照及模型重建都帶同一已存髮型／色號；外觀列表追加一個部件 8，仍保留武器、護甲和時裝。未載使用目錄時仍能恢復先前已保存的髮型，避免關閉用途配置後把角色清回零。沒有已存髮型的帳號繼續原有零頭部流程。

## 正常驗證與仍待完成

專項從實際付款／領取染劑 6459、普通髮型 6563、單色髮型 4947、預設髮型 6554 及時裝 29769 起始，共付 184、Garnet 816。先把預設 31004 染成色號 5，再換 31014 保留 5；重開資料庫及再跑遷移仍保持。穿上已付時裝後 `0070` 頭部及 `00FA` 保留 31014／5，隨後換單色 31224 重設 0，再換回 31004／0。最後沒有未用背包物品，已穿時裝、LeeLoo／BP／Garnet 均保持。

正常新帳號教學／主線後的 TCP 商城旅程改為原生上限的九列，共付 410、Garnet 1,000→590，第二次登入有九筆保管箱。正常領取後，實際 `0021` 依序得到 31004／5、31014／5、31224／0；接續時裝替換、普通建隊進村、銀行及銷毀，最後正常登入仍保留髮型、熟練度增加 2,000、CP 5,000、主線原快照及其他資產。這是合成碰撞／TCP 工程證據，不替代原版場景／貼圖與操作驗收。

首輪專項發現 JSON 的 byte[] 預設要求 Base64，目錄原投影為數字陣列；讀取改為有 0～255 驗證的數字陣列後再驗。保留兩項初跑失敗 TRX，沒有改目錄或放寬色號。完整原 `.itm`、IPK、STP 和帳號資料不加入 Git。

指定 v2 的確認視窗、頭髮渲染、快捷／使用提示、角色選擇頁及切角、全髮型幾何貼圖、十組缺色號反應仍待 CS-05。當前不開戰鬥中換髮型用途。陰性、故障、重送與壓測保持延後；不以這批來源覆蓋數宣稱整體商城或全外觀實機完成。

最終 Host／檢查器 Release 建置都是 0 warning／0 error；兩個專項 2/2、完整 `Category=HappyPath` **574/574** 通過。[工程收據](cash-hair-validation.json)保存精確 TRX 計數與 SHA，保留首輪讀取錯誤。`-IncludeCashShop -PreflightOnly -IsolatedPorts` 使用前次已停止的隔離資料庫之新副本，實際 Host 載入兩份正確目錄並遷移至 V28。首次結果只留終端，補跑保存 JSON 收據後確認四個隔離埠均無監聽、`retainedHost=false`。這是 Host 配置證據，沒有 Client 連入或替換暫停中的實機 Host。

## S00 GAME_RUNTIME_OBSERVATION：僅穿商城時裝的外觀恢復

證據範圍為 OFFLINE_SYNTHETIC，尚無本批 Client 畫面觀察。實際付款取得的伊希莉亞時裝 29769 已穿在格 10，普通武器／護甲／格 15 均空，且從未使用髮型商品。新建正常廣場、從已保存裝備準備 view 後初始化，`0070` 能還原裝備，但原 `AddEquipmentAppearance` 首次發布只檢查普通格 1／2／15，漏掉獨立時裝，因而沒有含 Item 13401 的 `00FA`。髮型案例因有已存頭髮而不會觸發此缺口，不能用它替代時裝單獨恢復的證據。

修正將首次發布與 parts 建置共用同一個已支援格位集合 `1,2,15,6,7,8,9,10,11`，再加已存髮型；任一可見部件即發布 revision／parts。既有付款／領取／倉庫／銷毀案例增加正常新廣場恢復斷言，修正前 `cash-costume-restore-regression-before-fix.trx` 明確失敗，修正後同案例通過，不靠加入普通裝備或髮型迴避。CS-01 補測「未改髮型、只穿商城時裝」的重登／廣場外觀，指定 v2 尚待驗。最終完整回歸以包含此修正的後續收據為準。

包含此修正的最終收據為 `cash-hair-full-v2.trx`，**574/574** 通過；Host／檢查器重建均零警告與錯誤。最終 Host 亦用同一隔離副本重驗配置，獨立保存 `receipt-final.json`，退出後隔離監聽為 0。前一次全通過及 Host 收據都在工程摘要保留，與修正前／後對照分開。
