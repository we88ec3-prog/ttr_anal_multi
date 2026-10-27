# T06 地圖與場景資源對應

狀態：bounded-review-handoff；負責人 roy（進行中）。

## 範圍

地圖 ID、資源查詢及資源版本；不推定波次與 MEF 執行器

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：資源與程式精確 build 配對、波次及座標來源未確認
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。資源與程式精確 build 配對、波次及座標來源未確認
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：版本共用證據。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-phase1-20261022/focused-profile/mcp-evidence/06-function-4f3d80.json](../../../kr/evidence/0bf0d7ed73da6fa5ee0732df39dc110334acb802fd626a6ac4bf083567177c26.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [audit_map_state_consumers.py](../../../kr/evidence/21107ee7b8eeadf517f7a8cc268a0d4a6d3e64003a50563dff1f47a23a097984.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/map-trigger-consumers-audit.json](../../../kr/evidence/272bcb3f233d28886f425035bed0b215e7e3880a8af3fe6cf6f1958fce3d8eab.txt)
- [MAP-STATE-RESOURCE-AND-DRAW-CONSUMERS.md](../../../kr/evidence/35addc0a92053ffcfdd7fd2d34ddeb4ee3d2945aff848609667107e6bfeb8bbd.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/05-function-56cd10.json](../../../kr/evidence/4577cd9500168f40ee28f6e18816e6501e4867d443e27f905b2f60625653ca39.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [MAPFLOW-CLUSTER-LOADING.md](../../../kr/evidence/57e031e3f88af5a9963d955b84ae1c883fa4d25fcaea382ba0ff652117c405e5.txt)
- [kr-phase1-20261022/semantic-records.json](../../../kr/evidence/622c03c8f35e217e0799ca787b550ebad648b9767cbb2bc8f2c74da71d75a65d.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/09-function-4caf10.json](../../../kr/evidence/6a087875d16bb25aa9e93b53df79dd449bde7f21c09e048e2b21031765186730.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/10-function-4d0dd0.json](../../../kr/evidence/8d941b3113cec9dddc3e57657e52b0b0673c82aaec72d60e7174b4855d8fad4a.txt)
- [native-index/mapflow-cluster-loading-audit.json](../../../kr/evidence/990413230baf61d90508ad4b57ec2401b6549216235d371dc2d09006f0a51923.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/08-function-4f7df0.json](../../../kr/evidence/af75e8a81e45941f4663199d2cdfe712e5dfcde53593763e1d7c41bdfa3de745.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/11-function-4ca060.json](../../../kr/evidence/b00db972ba10bcf17f0ae57f4803ed27a8cd9f3f5318b439bbc8c6ffa46f11a2.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [audit_map_trigger_consumers.py](../../../kr/evidence/c01c9d6fd8ca2d63f0c42e3ea835da5217905294065d4852fdc8fe2a723d8d7e.txt)
- [native-index/map-state-consumers-audit.json](../../../kr/evidence/c32490ae1cc0837a4ae7abebc00f8748df12292b983b253f4f7ea47eddbbc478.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/03-function-4f4960.json](../../../kr/evidence/c65a9906af8223a3b13ae8b12ea94cae4719ad2ad20ca9e74c968d3447dea738.txt)
- [native-index/map-id-string-map-subscript.txt](../../../unclassified/evidence/c6d2ca5f5abb2176ddd052a591be5116957fffe7d3d430a809ee5bf126f9a29a.txt)
- [native-index/map-change-trigger-name-lookup.txt](../../../unclassified/evidence/c8647f2a305dd504321cb05517607233c8b2e3f612f4edc1b8a69a8d6a66dafc.txt)
- [audit_mapflow_cluster_loading.py](../../../kr/evidence/d39547d41b8c9c17115c24f233c310ac6bcd71e3fff8efd98cc0144fd68794b8.txt)
- [native-index/drawing-batch-state-consumer.txt](../../../unclassified/evidence/d49bacaca6547a24d501deba185f735ff51521765f39671665574d59a0a409ad.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/04-function-4f5640.json](../../../kr/evidence/ed2173b1df5e91bf59cbfc1dc27e1573cef4d4857b751bfe26439cc9c56719b4.txt)
- [MAP-TRIGGER-CONSUMERS.md](../../../kr/evidence/f64b15cd263a69a2396bc643ae10802323233c24f663efa6df89c427e3bb31e2.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/07-function-4df510.json](../../../kr/evidence/fe1ba4d04bb33dff43a045c3eaa6e32cf60ae4aca0867623b48768dc8028bf2a.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。

## roy 城鎮切換增量（2026-10-25）

已核對目前資源表與40封裝索引；94個名稱候選都有同名FLD/BND索引，僅表示資源存在。Town/TownType/World範圍不同，不能把Town ID當Map ID。現有本機地圖固定511與Town5 context／合成座標分開記為AI替代；原版build配對、各城鎮對應、出生點及可玩切換仍未驗收。

- [資源候選矩陣與範圍](../../evidence/fb41bd6f4ed7fad6a934d3583bed0c177429b38e7dd1447312a9a3173331e194.txt)
- [本機固定廣場實作片段及SHA](../../evidence/740be2f5be54bb14c68669b025c5c73c408a5f242f6f49204e4a61cc21a3095c.txt)
- [有界驗收檢查](../../evidence/eac56d897318a08319726c96cc8cd996ff5ec11c2e6697fd4ba0efe6343f13da.txt)

使用者記憶（尚未原生核對）：廣場為頻道共用；城鎮為組隊進入；任務地圖為組隊、多小關卡、完成／BOSS後結算回城鎮。不得把此記憶當成原生確認。
- [使用者記憶原始記錄](../../evidence/21bc73caab51940ad59e2c2369309e4f7059fb342952b800871ccadc7e93e874.txt)

### 首要目標更正：最初城鎮1／2

依使用者後續指示，先處理最初城鎮1／2。Map182/town001D及183/town002D目前是有精確資源資料的候選，尚未證實與Town1/2關聯。活動廣場是換地圖或更換裝飾，使用者亦不確定，維持「使用者記憶／未知」，列次要查證。

- [城鎮1／2接續規格及阻塞](../../evidence/ffa6505d2b3362e3c2da3cd29c3eb536bd2c443adcfff3fbd7375112fb1970cd.txt)
- [原檔位元組與既有REA範圍核對](../../evidence/1534c1d72d9ab354b7f4b13f0e668b1b00c094ddc5d6145bf430d39da591c8b4.txt)
- [使用者首要目標及活動廣場記憶](../../evidence/92ed839f1d328ea66937e41ed193abf06273598a11a77d1da16f0d6f267c34cf.txt)

新REA查詢已完成且關閉：4F7DF0/4DF510指令與body相符；profile由停用X86 Function Callee Purge改為default。4F7DF0偽碼有helper參數差異，不接受其ABI推定。見[新舊原生證據比對](../../evidence/cdcaa5fd991d5d8844b0adb677c405d05c24ee8b8a7fcf5a078731706ab429a7.txt)。

### roy 表格基準補強

現行Table封裝與本機manifest不一致，但已找到精確符合其長度／MD5宣告的唯讀備份候選，且五張本任務使用表的解碼內容相同。Map182/183值未因這項核對改變。這是unsigned本機manifest一致性，並非發行方真實性或可玩驗收；先前current archive來源紀錄保留。見[原表來源與逐表比對](../../evidence/721375e1396fad206cb714be82c2afdd056c2569ecb9ed8527675e08b541f02c.txt)、[七檔manifest一致性](../../evidence/15041a218cea85f596f9ef3684fcc7d373a60c6b39348485dbe8367609104a8d.txt)。

### roy Town欄位與資源準備接口

已核對Town標題DDS、World／Type／NPC membership及Portal effect key。540A40→541C00資源清單鏈有原生依據；它不等於實體出生或Map182/183對照。TYPE及Warptown效果不作實例／目的地政策解讀。Sound/Buff/Actor等初始化路線只辨識表名以排除，未展開玩法。見[逐項有界驗收與未解限制](../../evidence/044a9f005a5708314608974869ea55e0320e779e3d5be263d940ce6b17876029.txt)、[Town欄位審核](../../evidence/dc7287b73a48d3ec587d342408bfd90b78e39a6aa56c169aea90e376ac9103f3.txt)、[初始化路線紀錄](../../evidence/80ff716008fb159e5d47e9c522a9319127fdd248c8fac497de10b1640b25b36c.txt)。

原生selector介面澄清：4DF510偽碼的float型別不能拿來決定ID編碼；實際DWORD／整數key路徑有原檔byte核對，182/183保留整數位元。完整簽名及Town對照仍未證，見[selector scalar核對](../../evidence/53ad1634deb42277d3776e3a2d07f2a8f7504c75b4c4e5e38a958ebdacb525cc.txt)。

使用者已確認優先恢復馮德斯村（Phindous）與爾斯梅勒村（Alsmeer），此為目標確認，不是原生Map ID證據。見[目標確認](../../evidence/f7009e5208e7d49e7ea5e990532ff2fdbf6524efaa0f3602d810fbada7e5c593.txt)。

4A16F0註冊ChangeMap並將4A0AC0存入FE1784；4A1F50→4A23E0以FISTP將數值轉DWORD後callback，4A0AC0轉送至4DF510。另一4C32E0路徑取FB906C；其已觀察直接writer54F850屬config初始化並清零，不能視為Town1/2目的地。計算型writer／腳本實際使用與完整ABI未驗收，未證兩村對應Map182/183。 見[腳本橋接](../../evidence/0062ba01befff72c87c08a4188d422a842f69fbd2b3f8bbf18f362d270307bff.txt)、[config路徑限制](../../evidence/12c325efe9dbe2d7b25d821926b76c1deaea2ab91a171d4174325fc8e0fe11bb.txt)。這批介面證據不代表可玩切換驗收。

原始QuestInfo的Quest117 town=1，Event Scene117/1 funcName=Phindous_LittleTrouble，其函式含LoadMap("town001D.fld")；Quest138 town=2，Scene138/1 Alsmeer_Barley_Boss_After含LoadMap("town002D.fld")。這是故事資源關聯，補強馮德斯／爾斯梅勒候選；另有跨town類別使用同模型的反例，不能把Quest town當通用實體Map映射。Event亦符合相同unsigned manifest長度／MD5，SHA另存；一般進城目的地及合法出生仍未證。 見[故事資源關聯及反例](../../evidence/fb41a42d53f87960828fac834aad8a53928c4066eea2ccc1ff293c900f8108ee.txt)。座標及RestoreMap不作一般出生／回城規則。

補充lookup的有限限制：4DF58D以FB74C0查trigger；僅在4DF599 JNZ→4DF5B9分支，EAX於4DF5B9被覆寫，期間沒有另一個明確使用返回EAX的指令。查表本身不能作MEF載入／執行證據；不推及初始化分支、helper副作用或全客戶端不存在MEF。 見[原始分支及限制](../../evidence/dceee02f7359d47c407719ebf0546b1d66d83cd240f5322f1987ff1b1382d16f.txt)。

Q LoadMap/RestoreMap工具偽碼分別綁563C40/563FA0；LoadMap偽碼呈現檔名拆解，原檔563D18/563D34將FAB178複製至物件+34。RestoreMap於564085/564090/564095將物件+34作為FB74B0 MAP查詢key，後續56434D/564353再次保存FAB178。另5607D0偽碼讀questIdx/sceneIdx/funcName。這是過場資源介面的有界觀察，非完整ABI、normalTown1/2→Map182/183綁定、任務回城政策或可玩驗收。 見[選定過場資源介面及逐項限制](../../evidence/8584d231471efcfaf00efe80f798ea76e322c8ec9a25037fe69941634f458acb.txt)。原始批次父檔只作來源追溯，未選方法仍未審核；不改其他任務主責。

共用FLD資源helper補充：7C1E00已選分支：檔名比較不同→7C200F→virtual+4呼叫7C2016；同名時7C1FFD/7C2000檢查stack+8，非零走強制載入、零走取消並跳過7C2016。韓文原始診斷字串與分支吻合。普通4DF510到達4DF787時傳1，Q LoadMap/RestoreMap分別在563D45/56435C傳0。這是同檔名重載決策的有界證據，不把0/1認成town/mission/party種類；另普通Map路徑的BOUND查詢仍是獨立已觀察介面。 見[逐分支、原文日誌與條件](../../evidence/10eda4c2917b42119c3badfb7a7062e3e3718b8ebc834a7385b0b5bb24217b8d.txt)。不以此證明完整碰撞／控制器轉場、兩村後端映射或合法出生。


欄位模型快取資源介面（部分確認）：原BIN中7F552A寫C50CB4，raw RTTI為IS3D::CFieldObjectCacheSimple；該表+8=7F54D0（已選偽碼保存filename字串），+0C=7F5540。7F5540早期資源查詢子集：7F5820提供.gb3字串、7F5834呼叫append helper；7F5884提供MAP_OBJ、7F588E呼叫716740。只驗收靜態類別綁定及這段資源查詢，不把保存檔名當完成載入，不推兩村runtime路徑、gb3到emf實際解析或Town/Map配對。 見[來源、條件及限制](../../evidence/9d539ec04bc2f7a221fabe8e3ed4c4fda3d0b01169febdab5dadc53a1630d7f8.txt)。


同Map重送路徑（部分確認）：4DF53E以DWORD比較manager+48與selector，相同時4DF541跳4DFA13；正常函式內路徑不經三個4F7DF0查詢callsite、7C1E00模型callsite或4DF1A0 BOUND callsite，最後4DFA9A返回。不同時4DF54E先寫快取，再進資源查詢。故重送同selector不能視為已證的完整重新載入，快取更新亦不能當載入成功。 不排除helper間接作用、例外、外部快取變更或caller行為；不證失敗重試／ready／可玩。見[原始指令與局部CFG核對](../../evidence/d6aa019345c65976c6d86741a7004feb0b891a1c58d0d8b48c7a0484e6e78f11.txt)。


完整資源路徑候選（部分確認）：兩村FLD快取清單37／39項均有原始FCS記錄；在明列的archive-parent+member namespace候選及有條件.gb3→.emf候選下，完整目錄／檔名與三個原封裝索引相符，選定payload SHA已保存。這是條件式候選存在觀察，不驗收engine mount、MO3 consumer、遞迴依賴或實際載入；不是Town1/2正常Map配對或可玩完成率。 見[逐項記錄與條件](../../evidence/4ad44dea9e5c18c4780e6d55debc383a5249310f07f3da9613cfdd16d406206e.txt)。早期MO3漏選紀錄保留，由兩筆獨立原始FCS補查佐證；不把早期空集合誤讀成檔案不存在。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


2026-10-27 整合更正入口：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。Case／STAGE／Map與結果背景不互換，PositionList不當spawn；原方法主責與任務狀態保留。實際遠端接續基準見批次收據。


2026-10-27 接續來源更正：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)，含早期網路／map／碰撞筆記的去重與限定，實際接續SHA見收據。
