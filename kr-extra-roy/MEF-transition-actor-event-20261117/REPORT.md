# MEF 三項續查：真實轉場、既有世界角色操作、普通結果到 Lua

2026-11-17，沿 `extra/roy1`。基準遠端 `0d76b827dfda0deb263e2692281ec304747652f8`，main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；live compare ahead14／behind0，main已為祖先。未新增工作分支、未修改Client／Server／原始資源／Task owner或正式驗收狀態。

## 1. 交付結果與未達成之處

| 使用者要求 | 本輪已完成的分析成果 | 不能冒稱完成的部分 |
|---|---|---|
| 一：真實普通轉場 | 回讀Case103的原圖表／Cluster；核Map191→192與BOUND；補0008 relation producer→000A控制綁定；形成具體發布偏序與A1位置 | 真正出口key／位置、已採用spawn、當次角色關聯raw值未綁定，不能部署 |
| 二：可靠world actor本地操作 | 選SetActorAvatar，接同一world lookup→metadata/render gate→既有CDoll非同步consumer→退出／可信還原；建立最小參數契約 | 未取得實際avatar descriptor、當次worldID及新舊variant，沒有可見效果驗收 |
| 三：普通世界結果到Lua | 000E→普通field虛分派→Scenario結果wrapper→CAIControl保存→原生actor reader；另排除000D→00DF作Lua／死亡ACK | 已證的是native資料鏈，尚無普通死亡／清組到Lua的合法typed介面 |

**前兩項是可供開發的參數化規格，第三項交付精確阻塞；不是「三個遊戲功能全部可玩」。** 原生MEF首次loader／grammar未證，相容內容均標NOT_NATIVE_MEF。A允許短暫插播，B不中斷操控仍未取得新入口。

## 2. 對先前摘要的必要精確化

早期回報中「000A需要relation」已成立，本輪才把0008全部22-byte欄位及其reset副作用接成可重驗producer，不能把它說成世界spawn封包。早期「SetActorAvatar會改外觀」須保留metadata先改、CDoll可能尚未處理的分支；相同variant也不保證重試失敗載入。

普通結果資料中確實出現worldID pair與native reader，這比「沒有Lua callback所以沒有事件」更精確；但CAIControl目標記憶不是可靠死亡事件queue，更不是普通Lua可觀察結果。`4C96B0`是依關係欄位判定的predicate，不能按直覺稱IsAlive。

## 3. 三份完整原稿

- [TRANSITION.md](TRANSITION.md)：graph／portal／spawn資料邊界、0008逐欄位、000A依賴、轉場偏序、A1掛接點。
- [ACTOR-OPERATION.md](ACTOR-OPERATION.md)：Server可靠身分、typed model來源、一次avatar操作、dirty/apply差異、退出／還原與缺資源。
- [WORLD-EVENTS.md](WORLD-EVENTS.md)：實際接收者、vtable／RTTI、typed native writer-reader、有限註冊比對、00DF意圖及Lua缺邊。

每份原稿都區分本輪原件、舊證據復用、Server候選政策與未知。可讀逐指令原件為 [native-evidence.asm](native-evidence.asm)，精確VA/raw/hex/指令邊界為 [native-evidence.json](native-evidence.json)。

## 4. 開發交接不是僅有敘述

[contracts.json](contracts.json)提供0008／000A／000E／00DF的限定application契約、typed identity及avatar操作限制。

[transition-profile.json](transition-profile.json)保留真正Case/Field/Map關係，未綁定的portal/spawn/session資料為null；有來源但未採用的W3候選獨立標示。偏序不是官服唯一封包順序。

[actor-operation-profile.json](actor-operation-profile.json)明列worldId、lifetime、part、新舊variant、資源及apply/restore入口的前置；未將A1切點鍵直接挪作第二項用途。

[contract.py](contract.py)／[test_contract.py](test_contract.py)為離線模型，不發送封包、不執行腳本。其38項檢查驗格式、順序、null保持、metadata與render gate差異、00DF最後命中規則，不代表原Client負向／故障／遊玩測試。

## 5. 原件與來源核對

直接唯讀原件：KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，以及Table／Event／BoundMap三載體。7個精確member保存carrier／物理位置／解碼hash，只公開選定欄位與資料形狀。Field.stp未重取，兩份公開解出圖表來源以commit/path/blob固定，已經本輪讀取，沒有冒稱本機重新解壓其carrier。

驗證器實際結果見 [verification-result.json](verification-result.json)：19個程式區間、5828 bytes、1648條解碼指令、22個具名錨點、10筆data／RTTI記錄、122個區間內direct transfers、7個原member、4個BND取樣與2個既有候選方塊，38項模型檢查。區間及transfer有重用部分，數量不是新增功能數或全程式覆蓋率。沒有執行Client／Lua／Server，沒有遊玩驗收或T01 FULL-PASS。

## 6. 已查範圍、精確阻塞與下一入口

完整清單在 [READ-SET.md](READ-SET.md)、[SERVER-HANDOFF.md](SERVER-HANDOFF.md)、[NEXT-ANALYSIS.md](NEXT-ANALYSIS.md)。不再重掃已排除的OnYes、Tutorial旗標、Q停步或圖片存活；只有對上述未接邊提供新的typed資料流才追加BIN-first。

本輪保存三個pending研究包的原稿及49個原檔不變，另加本研究包。Git發布狀態與安全套用／讀回方式見 [PUBLICATION.md](PUBLICATION.md)。
