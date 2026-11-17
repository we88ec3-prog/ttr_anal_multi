# 商城強化保護材料的付費使用

2026-11-18；分析基準 `9509a9b1ccd2f04cc4afdd1eaa47fb63b0556df0`，私有 Server 基準 `5dfe848e8a63c4eb5de1fc7cf18fde39432a15b3`。本批補來源與付款取得後的強化串接驗證，沿用既有 Server 強化實作，沒有 Client、TCP、換版或故障測試。

## 原表及適用品級

[唯讀驗證器](../../governance/client-variants/20261118-cash-shop/verify_protection.py)檢查 Table.stp 與 reader 身份，再核 Product、ItemTable2、CashProduct 和 ItemLevelupInfoSet 的固定 member SHA。[來源收據](../../governance/client-variants/20261118-cash-shop/protection-source-verification.json) SHA-256 `8bb0d368f2a35f8ba2c34dcd419e6c3c8e7905995dcebae9b53a31cb63ee2121`。來源只讀，未發布完整遊戲 member。

| Product → Item | Grade／SafetyMode | 原商城數量：價格（Garnet） |
|---|---|---|
| 5523 → 5489 | 1／mode 2 | 1：11；11：112 |
| 5524 → 5490 | 2／mode 2 | 1：16；11：160 |
| 5525 → 5491 | 3／mode 2 | 1：21；11：208 |
| 5526 → 5492 | 4／mode 2 | 1：26；11：256 |
| 5527 → 5493 | 5／mode 2 | 1：30；11：304 |
| 27484 → 7659 | 無 GRADE 元素／mode 3 | 1：141 |

六種皆 class 33、堆疊上限 100。SafetyModeRequireSet 1～5 的 mode 2 各需 Item 5489～5493 一件；第 6 組另用 5494。mode 3 六組皆需 7659 一件。LevelupInfoSet 1／2 的 Rank 2／3 都選 SafetyID 1，符合目前前兩村 E 級裝備的實作。Grade、Rank、LevelupInfoSet 與 SafetyID 仍是不同欄位；未建立適用裝備及費用／能力資料前，不把 5524～5527 當成 E 級替代材料，也不由 Grade 數值推算所有 RankSet。

此次讀取的 ItemLevelupInfoSet 雖宣告 euc-kr，固定 hash 的實際 bytes 可嚴格解為 UTF-8；直接用 ElementTree bytes 或 cp949 解碼會失敗。驗證器對該精確 member 使用 utf-8-sig，保留來源宣告與原件，不使用忽略錯字或取代字元。

mode 2 防破壞、可能降 0～2 級且有安全級下限；mode 3 防破壞、不降級。兩者目標最高 +15。原文沒有三種降級的權重；現行 Server 等權抽樣仍是 `SERVER_DESIGN_CHOICE`。請求、成功率、成本與結果 adapter 沿[鐵匠裝備強化](BLACKSMITH-EQUIPMENT-ENHANCEMENT.md)，本輪未新增 opcode 或改判定規則。

## 付款→強化→倉庫→穿戴的合成證據

私有 `CashProtectionPositiveTests.cs` 四個 HappyPath case 將 mode 2／3 各配成功與原破壞區間的固定抽樣；後者是正常機率結果，並非故障注入。

1. 已取得伊希莉亞的隔離冒險團，配置 1,000 Garnet／30,000 LeeLoo。商城買 5523 ×11（112）與 27484 兩列各一（282），領取後保管箱清空、Garnet 606，背包實際合併為 11／2 件。
2. 普通馮德斯鐵匠入口買 Product 2722，花 3,700 LeeLoo。鍊石 151 ×100 由明示的隔離 loot fixture 提供，非本輪自然取得；正常材料路線已有[獨立證據](PHINDOS-REFINE-MATERIAL-ROUTE.md)。
3. 經 `00A1` adapter 逐級成功到 +7，再帶 primary 2 或 3 嘗試 +8。八次強化合計費用 5,386、材料 68。成功為 +8；抽中原破壞區間時 mode 2 抽降兩級為 +5，mode 3 保留 +7。始終為同一 GUID／查詢鍵，沒有裝備刪除回覆。
4. 每次保護嘗試只扣所選材料一件；另一種保持原量。最後 LeeLoo 20,914、Garnet 606、Battle Point 7、鍊石 32。重開 store 後仍保存裝備等級及資產。
5. 同件裝備存倉、取回，建立第二村正常世界後穿戴，核對裝備身分與強化等級。這是 store／world／session 串接，不是實際 Client 旅行或本輪新增 TCP 證據。

專項 4／4 通過；完整 HappyPath 與 build 收據見 [驗證索引](cash-protection-validation.json)。本輪沒有產品修正，不把既有功能重新宣稱為新增實作。

完整 HappyPath 為 580／580 通過，TRX SHA-256 `c5701a64bf0f936a0d8bc0f2fef3f8b3bb47b9fbeff3cc687799444d505398ec`；Release Host 與檢查器均零警告／錯誤。實機與換版暫停，這些結果不證明指定 v2 相容。

## GAME_RUNTIME_OBSERVATION：CS-07 與後續缺口

沒有新增實機問題。CS-07 已列正常付費測試批次，實機與換版暫停。之後用可消耗隔離裝備驗付款／領取、鐵匠選單、成本、材料、結果、保留／降級、存倉及重登穿戴；不要求實機一定抽中某種結果，記錄實際結果再比對。顯示、選單值及原服結果碼仍待驗。

5524～5527 的付款資料已存在，但其相應高品級裝備取得、資格、費用、材料、強化能力與穿戴路線仍未開發完成。沿 SFD-0018 與既有強化工作接續，不擴寫為六種商城材料全功能完成；機率公平性、重送、併發等依既有待測清單延後。
