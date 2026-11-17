# 商城時裝的 SP／MP 容量

2026-11-18 接續 [商城消耗品](CASH-SHOP-CONSUMABLES.md)，基準為分析庫 `1c8d66f3a0b64051dad456d190092c0423e6a68d`、私有 Server `17c299c18f6f00983bc06d8409ca4e1954dce381`。本輪將已可購買、領取與替換的時裝接入資源容量；原始 Client 保持唯讀，實機及換版仍暫停。

## 逐件來源與相容服策略

[唯讀驗證器](../../governance/client-variants/20261118-cash-shop/verify_equipment_capacity.py)從固定 SHA 的 Table.stp 讀 Product／ItemTable2／StatusList，並核對既有商城目錄的精確 SHA。目錄中 864 個不同的可穿戴 Item 都逐一檢查 OPTION_LIST：恰為 status 12／value 120 與 status 13／value 120，沒有其他 OPTION。StatusList 的 12、13 分別是 SP 增加、MP 增加。[完整計數與映射 hash](../../governance/client-variants/20261118-cash-shop/equipment-capacity-verification.json)

| 來源 | 固定 SHA-256 |
|---|---|
| Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| ItemTable2.xml | `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2` |
| StatusList.xml | `9be878f847ab75401bf8bd81d943773d3e98ec05bbc36364f4cf8f6c00a70161` |
| 已投影商城目錄 | `1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd` |

Server 候選採逐件、固定值加到目前容量：一件各加 120，兩個不同裝備格各穿一件則各加 240。相同格位替換只計新件，庫存／保管箱／倉庫不計入。沒有把這些值加到六項攻防，也沒有將套裝加成混進來。這是明確的 SERVER_DESIGN_CHOICE；來源證明欄位、名稱及原值，沒有提升為官方完整資源公式已復原。

`LocalCashShopOffer.EquipmentResources` 依上述完整有界集合提供容量值，與原角色／格位資格一起從目錄衍生。已存裝備仍只保存原 Product、GUID 與 metadata，重讀時根據同一目錄重新建立 rule／容量，不新增持久化表或更改商城價格目錄。Host 必須維持原商城目錄配置；未載目錄不會由未知 Product 猜時裝資格。

## 面板、戰鬥與返回

`LocalEquipmentStats` 保留原六項攻防，另帶獨立的資源容量結構。所有正常戰鬥建立點原已傳入裝備合計，現在同時帶入容量。SP／MP 上限是現有角色／技能容量再加目前已穿加成，初次戰鬥從相同上限開始；HP 在本批時裝沒有新增值。輸出以已用 `005C` WORD 容量範圍封頂，這個表示限制不是官服平衡規則。

角色面板 `005C` 的 +18／+20 寫 SP／MP 上限。穿戴目前場上角色時，先發布裝備／外觀與角色面板，再用既有 `0034` typed resources 發布一致的 HP／SP／MP。替其他已擁有角色換裝只更新該角色資料，不覆蓋場上 actor 的資源。普通廣場／村莊沿既有滿資源策略處理穿脫；卸裝後發布較低上限與封頂值。

場景重建以已穿裝備重新合計。`0034` 使用 SP kind 3、MP kind 4，最大值與絕對值一致；actor 的 100% 條仍是正規化值，不因上限 220 就發 220%。既有換圖 continuity 保存並驗證相同角色／容量，保留已消耗資源與冷卻，不把過圖當回滿。40% 活動回復書及 100% 商城回復書使用新的各自上限，保留原冷卻與原子道具消耗。

## 正常驗證

實際付款取得的兩件 Product 29769／Item 13401 在同格替換，正常 TCP 回覆的面板與 `0034` 均為 SP／MP 220；再次登入也回復 220。替換兩件同款不疊成 340。另一條已付商品存取路線在重開資料庫後卸裝，面板與 typed resources 回到 100，原 GUID 回包，再穿回後恢復 220。

單件／雙件合成戰鬥分別有 220／340 上限，攻擊加成仍為零。將 HP／SP／MP 125／25／85 的狀態帶到下一個戰鬥實例，保留相同已消耗值；活動回復之書按新上限各加 40%，商城回復書再回滿，actor 正規化條回到 100%。這些是候選 Server 的工程／TCP 驗證，指定 v2 的面板、HUD 與實際技能操作仍待 CS-03。

套裝、附魔、其他來源裝備與所有官方比例尚未完成；時限及其他特殊商品亦沿原待辦。當前 864 個 Item 的有限來源集合不代表所有歷史／其他版本裝備都採相同值。正式 REQ／RR、原生格式與實機驗收狀態不因本輪自動提升。

Release Host 與檢查器建置均為 0 warning／0 error；完整 `Category=HappyPath` 為 **571/571** 通過。[工程收據](cash-equipment-capacity-validation.json)保存實際 TRX 計數與 SHA。來源驗證覆蓋上述 864 個 Item，戰鬥案例是單件／雙件合成狀態，TCP 案例使用實際付款取得的同格時裝；這些範圍不互相代替。
