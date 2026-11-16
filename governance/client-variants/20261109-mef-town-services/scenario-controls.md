# Tartaros KR｜重建關卡腳本能接替哪些 Server 操作

專案工作筆記，2026-11-09，台北。原版 MEF 已不可取得。研究基準為 KR 原件、研究庫 main `055e40018f35ce741df81364750afc5c0a844b06`、Server main `0f431e4830246193532de8cb40385641151f6d7a`。這裡的「重建關卡腳本」指將原先逐次由 Server 指示的行為交給關卡事件規則或既有 Client 執行器；官方 .mef 的歷史格式與執行端保持未知。原稿工作採唯讀離線查證。此版收錄於研究庫，技術範圍維持原樣。

## 調整後的研究終點

對每項行為回答四個問題，包括誰提供開始條件、誰做中間步驟、哪一方能觀察完成、什麼共享狀態還需要同步。將參數搬到 Server JSON 只能替代逐關硬編碼。若主張可省去 Server 指令，還須指出具體被取代的發包點，以及 Client 在後續沒有同類指令時憑什麼繼續。

目前已能使用原件證實「Client 能執行以下子操作」。仍缺一般戰鬥場載入自製腳本的入口，以及相應事件能否在該場景抵達腳本。因此，表中不把已有 Client 能力計成現成 .mef 支援。原檔樣本不列交付門檻。

## 操作替代矩陣

| 操作 | 能交給腳本／Client 的部分 | 現行 Server 還必須提供、或待閉合的條件 |
|---|---|---|
| 固定劇情、走位、動作、音效、鏡頭、對白 | **已有完整原件實例。** Q119/3 一次選定劇情，既有序列就能建三個演出物件，安排走位、攻擊、受擊、對白及清場。部分 NPC 路徑甚至先本地開始，才通知 Server | Server 或合法本地事件選對起點。現行 Server 已使用 0047 分段啟動；這一例證明可以避免逐項指揮，不能算本輪實際省下的封包。003F 回報可出現在清理路徑 |
| 固定路段上的普通怪移動 | **原生有一次給終點、Client 逐步走完的路徑。** S2C 0018 提供既有 actor、終點與步數，CMonster 更新函式消費。腳本可指定路段目標，Client 執行中間位移 | 尚須決定誰指定新目標、轉向或中斷。v81 的追擊迴圈在有移動時送 0016 位置及 000B 移動狀態，首次開始另送 000C。單段替代需實測，尤其終點、碰撞、朝向、起停、命中時位置 |
| 指定角色追隨另一角色 | Client 已有「指定關聯後，按距離、方向計算追隨」的控制器，同時仍會 C2S 回報輸入 | 一般敵怪被納入該控制清單、目標選擇、仇恨與選招未證。此路徑只能證明指定對象之後的計算能力 |
| 生成與移除 | 演出物件可由 Q 腳本建／刪。另一套 lb 腳本 API 可本地建立真正的 CMonster，加入與網路怪相同的 actor 索引 | lb 呼叫的六參數沒有共享 EntityId 欄位，本地使用自己的計數器；0007 生怪使用來包的 ID。要替代整波生怪須建立同一波／同一實體的身分關聯，確認命中、死亡、移除都指向正確物件 |
| 切換既有出口開／關 | **Lua 的 SetCheckPointStatus 與 S2C 0048 已證匯入同一 setter。** 出口登記後，腳本具備接手狀態切換的能力。距離與按 Z 的本地判斷也有消費端 | 當前 Field19 勝利後的 0027 會建立／發布出口。setter 無法建立缺少的點；須先登記，並取得 Field19 能送到腳本的清怪轉移事件。按 Z 後 Client 仍有 C2S 001C 意圖 |
| 換圖與跨圖流程 | lb.ChangeMap 與 S2C 0012 共用本機 4DF510 地圖載入器。啟動載入是可接替的子操作 | 現有 0012 handler 還會先呼叫其他函式整理前一場狀態。換了畫面後，下一圖需對齊 actor、出口、關卡節點與存檔。未證腳本換圖可取代整個轉場 |
| 波次、清場、分支、何時開門 | 作為重建關卡語意，可由腳本定義「第幾波、哪組怪死完、何時開門、按 Z 去哪裡」。腳本每次接收一個經辨識的條件事件後即可執行後續階段。原教學有實例，收到一次結束旗標，Lua 就能繼續 | 還缺一般副本可靠的死亡／清組觀察和可持續執行的腳本上下文。教學 IsScenarioEnded 讀已寫入的情境旗標，沒有統計全場死怪。將波次規則移入檔案與消除生怪／同步封包是兩項分別可驗的成果 |
| 動態尋敵、選招、命中／HP、戰利品、任務結算 | 腳本可描述條件、選擇表、掉落及獎勵規則。出招動畫可由 Client 播放 | 目前未建立普通敵方自主決策到戰鬥結果回報的完整鏈。收到動作、HP setter 或播放死亡不等於算出命中。權威實體狀態、跨玩家同步、獎勵與持久化須有可核對的提交點；這是相容服設計責任，不用假設原服必然相同 |

固定路線的 0018 只把**中間步進**交給 Client，首個終點仍透過上述封包提供。原生 lb 與 Q 也屬不同 API 及物件生命週期。未證一般副本會因 `_MapList.TRIGGER` 的字串，自動將這些 API 呼叫串起來。

## 第一個試驗選已建立怪物的固定短路段

選馮德斯 Field19／Map191。原表引用 `S_pathofpindus01.mef`。v81 所用的重建定義裡，第一隻模型 1001 生在 (426,385)，依 Server 現行 encounter 配列其實體 ID 是 0x0101。以上是現有測試配置。本輪選 (422,385) 作為分段終點，4 次更新作為可辨識的測試值，沒有將此路段、步數或速度視為官服參數。

| 比對項 | 離線已核對 | 隔離測試場的驗收條件 |
|---|---|---|
| 指令與終點 | 按既有 0018 解析器構造的 application payload 為 `18 00 01 01 00 00 d3 43 00 80 c0 43 04 00`。未發送。X/Y 與步數獨立解碼為 422、385、4；現有第一怪的 actor 建立和 EntityId 保留 | 同一隻怪、同一路段，比較既有逐步位置更新與一次 0018。試驗組移除此路段中間的 0016/000B 重複發送，起停／面向／動畫需要的初始狀態另記。終點後的校正須獨立記錄，避免校正封包製造「看起來正常」 |
| 路段資源 | 附檔 BoundMap 原件精確成員 `BoundMap/scenario_pathofpindus01.bnd`，解碼 SHA-256 `adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58`。依專案既有座標投影每 0.25 單位採樣，17 點共跨 5 格，兩層 DWORD 皆為 0 | 比對起步、畫面上是否連續走到該點、停止、下一次攻擊位置是否與 Server 認知一致。有碰撞的路段分開驗；Client 倒數到 0 時還會走另一條設終點的路徑，長線段不能直接穿越障礙物 |
| 接手範圍 | 證到原生資料列與每幀消費鏈。未執行實機，沒有節省封包的實測數字 | 保留基準／試驗兩組的角色 ID、路段、出站封包及時間、影像，依起始、途中、結束加總封包；畫面與邏輯位置皆一致後，才把固定路段列為替代成功。這個結果不會自動擴張為自主追擊 |

## 第二個目標是把 Field19 的門交給事件

v81 的 `LocalTutorialWorldConnection` 在收到 domain 勝利後，送 0027 建立指定出口；後續主線也有類似發布。可比對的設計是入場就登記關閉的出口，等清場事件抵達後，由本地腳本開門。第一步要證明 map191 的關卡事件執行器能存活到一般戰鬥階段，且清組事件與該 instance／群組相符。第二步才在已登記的同一 key 上比對腳本與 0048 的結果。若只預播了出口特效，或 Server 其實仍送了開門命令，都未通過。

驗收時觀察出口顯示、近距離按 Z 的 001C、未互動時仍留在原圖，以及進下一圖時的雙端節點。教學局部 Lua 與現有場景不能直接充當 map191 的 group-clear 回呼。當普通戰鬥無本地死亡／清組來源時，可先採「一次群組完成通知 → 後續腳本自行開門／演出」作較小的替代單位，此為待開發的相容設計。該通知如何對接既有 Client 需舉證，不指定新 opcode。

## 仍要分析與開發的接口

1. **關卡入口與生命週期。** 對照普通 Field19 的 ready、controller 選定、事件 VM 與結束／清理。確認進入戰鬥後有無可重用的常駐更新或回呼，以及資料可從哪個已知入口傳入。0047 啟動既有劇情與 lb.DoFile 讀指定資源均有實作，兩者是否能在普通副本以同一上下文串接仍未證。
2. **戰鬥事件的身分。** 追單一普通怪從本地或網路建立、分配身分、被鎖定、受擊、死亡到清組的讀寫。RR-0013 限定一般怪的控制來源；已有的 000A 關聯追隨是可復用前提，不能用它代替敵方選目標的證據。
3. **Server 開發需求。** 為替代試驗提供同一 actor 的逐步版與分段版、同步端點、分辨重複建立與出站紀錄；關卡運行器採帶有來源的 stage／group／entity 對照。對世界共享的換圖、命中、獎勵保留提交與查核介面。這些是可驗收的相容服需求，未登記為已驗收規格。
4. **回報兩種進度。** 一種是「關卡檔取代了多少寫死的劇情與波次分支」，另一種是「關閉了哪些原有 Server 指令後，Client 仍完成哪些操作」。每項給出實際資料來源與驗收記錄。

## 核對基準

- KR `Tartaros.bin` SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本輪直接核對 CMonster vtable +20/+44/+54 為 4D1AE0／4C8B90／4CABE0。原件文字節使用 VA−0x400C00 取實檔 bytes，所列窗口與反編譯交叉核對，不升為整函式 FULL-PASS。
- KR `Event.stp` SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` 為 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`BoundMap.stp` 為 `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`。
- [普通怪的控制與更新](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/client-variants/20261108-monster-authority-boundary/README.md) · [指定關聯的本地追隨](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/client-variants/20261108-extra-control-boundary/README.md) · [S2C 0047 的劇情入口](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/s00-iterations/S00-20261102-SCENE-START-CONSUMER.md)
- [現行 Server 的怪物移動與攻擊發送點](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Network/LocalTutorialCombat.cs#L514) · [Field19 開門發送點](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Network/LocalTutorialWorldConnection.cs#L208) · [測試用遭遇／座標來源](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Network/LocalScenarioDefinitions.json)

---

# 附錄　原始資料、呼叫鏈與適用條件

## 固定演出可交給 Client 的實例

我直接解包 KR 資源並查驗原始機器碼。地圖的 `TRIGGER`、劇情鍵 `(questIdx,sceneIdx)`、劇情角色槽位及網路實體鍵各自獨立。以下例子證明現有 Client 可承接的操作，沒有證明官方用哪種格式編排這些操作。

- `Table/SceneList.xml` 列 Q119 的 scene 1 至 5。`Event/SceneList.xml` 的 `(119,3)` 唯一指定 `Phindous_YuriandRazed_Boss`，endBehavior=0。原序列 SHA-256 為 `05abe5f9773c3b0b40d5a849f7d984b4f06f57d2e5a5fe8c931e83ec2d7b857a`。遊戲已有這個場景，重建關卡可用 `playScene(119,3)` 表達開始演出；該命令名稱是假設的重建語法。
- `Phindous_YuriandRazed_Boss.seq` 第9行指定 `mushroom12D.fld`，13至15行用範本1086，在三處建立槽0、1、2。24至26行控制槽0、2走到目的地並等它們停止。接著以六個 `AniObject`、五個 `WalkObject`（全段合計）、三個音效、旋轉與等待，編排三者的互動。第39行只播放 `Stoncken_DEAD.wav`，44、45行讓槽2和0各播放動作11。第47行打開對話(12,11)，53至54行清理劇情物件並還原地圖。
- 應用層 S2C 0047 在 `503098/50309C` 分別讀 payload+4/+2 的有號16位鍵，`5030A7 E8 B4 E6 05 00` 呼叫 `561760`。既有 T16 查明此控制器有忙碌等條件，`565720` 消費 Event 的雙鍵索引；條件未通過須保留未啟動。Q119 場景在本輪未執行。已有場景接入時不需逐條另發音效、鏡頭、固定角色位移或出手動作，不能從以上文字算出實際少了多少封包。
- 經原件 hash 固定後對照 qbase 的已解碼 Lua 5.1 子函式：WalkObject 呼叫 Q.WalkObject 並 yield，AniObject 呼叫 Q.AniObject 並 yield，WaitForObjectsStop 查 Q.IsAllObjectsStopped，Register 經 coroutine.create 註冊。原 BIN `5665B8/5665C9` 註冊 Q.CreateObject 的 binding `568E00`，`566578` 將 callback 設成 `562EC0`，其 `562F48` 分配 0x438、`562F68` 呼叫事件角色建構 `4D0B80`，`5632A0/5632AB` 建立並插入節點。
- Q.WalkObject 的 `566E38` 掛入 `FE27DC→563330`；`566E78/566E89` 註冊名稱與 binding `569340→56AC30`；參數轉換後 `56AE41` 呼叫該指標。`563348/56334F` 從 script owner+18 的樹尋找槽位，若命中並有物件，`56337E` 將目的地送至 `4D0CE0`，可在條件成立時設定演出動作與速度。
- Q.AniObject 的 `566F78` 掛入 `FE27E4→5634E0`；`566FB8/566FC9` 註冊名稱與 binding `569400→56B0E0`。`5634E0` 查同 owner 的槽位，成功且有物件才在 `56351C FF D2` 呼叫其 vtable+68。這和接收網路 000D 的角色動作通道最終有相同種類的動作虛方法，但來源、物件樹與 ID 不同。三個本地角色具備不同演出槽位，未因此在正常世界樹登記成可攻擊敵人。
- 面向實作的區分是，關卡定義可決定此刻播哪幕，Client 收到已知 scene key 後跑這幕演出，正常戰鬥的 HP／死亡／清場／獎勵必須另有可觀察的事件。C2S 003F 是控制器回報，可能早於 coroutine 與 UI 清理，不是清怪或發獎根據。
- 逐條檢查 Q15/1至4 的四份 SEQ 及 Q119/3，均無 `lb.DoFile`、`lb.CreateObjectEx`、`Tutorial.SetCheckPointStatus` 或直接寫戰鬥組清空的呼叫。Q15/4 載入空字串並收尾。另在教學專用 `Event/TutorialMain.lua` 的確有 `SetCheckPointStatus`，part2 的 scenario14 有專用的 request/ended 分支。其權限範圍不能直接移作正常 Field19 的出口。
- 輔助檔案盤點。Event.stp 有1,840個 SEQ，1,837 為 TTEX 文字，3 為編譯 Lua。對文字序列過濾註解、跳過 function 宣告、逐行擷取行首呼叫，再依每檔去重，1,505 檔含 CreateObject、975 檔含 WalkObject、1,031 檔含 AniObject、1,303 檔含 OpenTalkScene。數量只反映靜態行首呼叫，未計編譯腳本或動態轉呼叫。

| 原件 | SHA-256 |
|---|---|
| KR BIN | 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91 |
| Event.stp | 2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b |
| Table.stp | 09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442 |
| Table/SceneList.xml | 1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037 |
| Event/SceneList.xml | 8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25 |
| Event/qbase.lua | d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3 |
| Event/TutorialMain.lua | 662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809 |

[既有 Scene 發起契約](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261031-154318-chatgpt-web-roy-T16-134-KR-Quest15-C2S-S2C-scene-trigger-causality.md) · [本次資源與原件核對器](verify.py)

## Client 接手戰鬥 actor 的生成、位移與換圖

本輪用唯讀 objdump 及 PE 映射核對 KR `Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。地址均為該版本 VA。下列「有替代能力」以實際呼叫與消費者為準，沒有執行遊戲或原始腳本。

### 同種怪物有兩個不同的建立者

- 原生 `lb.CreateObjectEx(model,x,y,scale,direction,attach)` 註冊於 `4A1848`，10..10000 的模型 ID 走 `4A0FFE → 4D1710`，可建立 `CMonster`。位置、朝向取自呼叫方，後經 `4A11B6 → 4DFF30` 加入共同 actor 索引；`attach` 非零時呼叫當前 controller 的 v+4 與 v+10。本輪沒有證據它會使一隻普通怪自主尋敵。這條路可作 Client 建怪實驗，其六個參數沒有外來 EntityId。
- 本機 `4A104F: 66 A1 04 DE F7 00` 讀取 `F7DE04` 的低 WORD，`4A105F: 66 89 46 04` 設 actor ID，`4A11BB: 01 3D 04 DE F7 00` 將計數器加一；`EDI=1` 已在 `4A10A4` 設定。該欄位 PE 檔案內初值 1001，僅指磁碟初值；不能假定任何時刻或每個房間都從 1001 開始。模型 ID 1036 和產生的 EntityId 是兩回事。
- 另一條由 S2C `0007` 的分派表在 `4ADD7E: C7 40 3C D0 E4 4A 00`，同樣呼叫 `4D1710`（`4AE692`）；`4AEB2C: 66 8B 43 FC` 讀輸入列的 ID、`4AEB30: 66 89 46 04` 寫 actor+4，並經 `4AEC03 → 4DFF30` 加入相同索引。`4DFF4C` 取 actor+4 為 key，`4DFF67/4DFF6A` 若既有同 key 則跳到 `4DFF90` 診斷，不替換舊項。反過來，0007 建立路徑也先用 row ID 查既有 actor (`4AE5AC..4AE5B2`)。兩端各自生成、碰巧同模型或同號，都不足以建立可靠共識。可測的下一個接口是以單次場景／生成事件啟動本機建立，讓戰鬥端能把後續移動、受擊、移除精確指向同一個 EntityId，並避免重複生成。
- `Q.CreateObject` 的已查 consumer 建立 `CEventActor`，登記到事件自己的物件表，與上述 `lb` 不同。在此次附檔兩包的 6 個 .lua 中，只在 `Event/qbase.lua` 檢出 CreateObject 字串，未檢出 CreateObjectEx 或 ChangeMap；既有 bytecode 解析已將該次呼叫歸到 Q。6 個成員範圍不能外推至全部腳本。另 `Table/Lua/Tables.lua` 使用兩個全域 DoFile 載入角色說明、語音表，其字面程式碼沒有 `lb.DoFile`。

### 一次給移動目標，Client 可執行中間步進

1. `4ADE7D` 將接收槽 `+C4` 綁到 `4B2730`，依 `4+8×appKey` 得 `0x0018`。`4B275F..4B2775` 計算 `(len-2)/12`，每 12B 小端列為 actor u16、目標 X/Y 各 f32、更新步數 u16。例行 `4B27B9..4B27E9` 查既存 actor，找不到會跳過。有效列在 `4B2825/4B282E/4B2834/4B283A` 寫 `actor+C0/C4/C8/D4`，最後一項設 1。
2. `CMonster` 主 vtable `C0C9DC` 的 +20 = `4D1AE0 → 4C8580`，`4C85AD: E8 DE 22 00 00` 呼叫 `4CA890`。+D4=1 走指定目標支線；+C8>0 取剩餘距離／剩餘步數、作方向正規化、呼叫 actor v+54，然後 `4CAA4D: FF 8E C8 00 00 00` 倒數。CMonster 的 v+54 為 `4CABE0`，其位置候選還要通過地圖檢查 `82CDF0`。+C8=0 時呼叫 v+44，然後清 +E2.8000 和 +D4。CMonster v+44=`4C8B90`。碰撞擋下中間步不會阻止步數倒數，終點另走 v+44。因此測試必須包含通道/牆旁及末端同步；不得把步數當成已知毫秒或用此方法自行決定要追誰。
3. 此鏈可直接做「直線 A→B，Server 下達起始目標後停止逐步送 X/Y，Client 是否自行走完全段」的對照。現有證據足夠設計實驗；尚未在使用者的 Client 上證實省下多少封包，亦未證明原 MEF 是這段的 producer。後續的攻擊時機、改變目標、碰撞判定與戰鬥狀態同步應各自驗，而非將是否看起來移動當成完整 AI 通過。

### 已註冊的本機換圖與 Lua 讀檔入口

`4A16F0` 這項註冊以字串 `ChangeMap`（D6ADB0）綁定 `4A0AC0`；`4A0B1C..4A0B25` 將單一參數及 holder FAB130 傳給 `4DF510`。代表已有在 Client 發起換地圖的程式入口，沒有自動取代任務結算、起始情境綁定與其他玩家同步的證據。另一個 `4A1B50` 註冊 `DoFile`（D6AE14）→`4A1230`。此函式由 `4A125E→714770` 按傳入路徑開資源，v+2C 取大小、v+38 取資料，複製後送 `4A12E7→6F4C20`（Lua 狀態 FDF3C8）。這裡兩個 API 的註冊證據無法自行接成「關卡 TRIGGER 自動執行 DoFile」。沒有對原始 Client、腳本或封包做修改。

**既有證據（本輪交叉驗證）** [T13 的 lb/Q 兩條建立路線與 ABI](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/kr/evidence/33de7cea0ce88d82032b9b4e5fe7689a8acb8e4ef15728d78ba0b96c1e033ec5.txt) · [T09 的 0018 目標位置處理器](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/kr/evidence/4d82eb8203c1d5527a092f4a1c576aa123d34fa15e7d242d79c8ca8d516d114d.txt) · [T13 怪物控制來源研究](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/client-variants/20261108-monster-authority-boundary/README.md)

## 出口的本地設定與網路設定寫入同一處

本輪對照 KR 原始 `Tartaros.bin`（SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）、`Event.stp`（`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`）及 `Table.stp`。使用 PE 節區定位、原始指令與 Lua 5.1 資料核對。直接呼叫清冊只涵蓋此 BIN 的 .text E8 rel32。原件重算兩個函式各自只有兩個直接呼叫點，再以函式入口連續反組譯確認為指令。未涵蓋其他模組、間接調用或內聯。

| 動作 | 原件證據 | 可取代／保留的步驟 |
|---|---|---|
| 新增教學提示點 | Lua 登記 `4AA7C0`、closure `4ABF70`、target `4A9430 → 4A90C0`。查得教學資料列後配置 `0x108`，`4A9148 push 4`、`4A914B call 543700` 建 CCheckPoint。教學點 `1/2` 的位置、半徑及效果在 TutCheckPointList。 | 實際教學腳本可自行建立指定的 category 4 提示點。這個入口固定 4，不能用它建立一般 category 0 出口。 |
| 改變已存在點的開／關狀態 | `4AA878` 登記 target `4A9460` 於 FE1814，`4AA8B8/4AA8C9` 綁定名稱 `SetCheckPointStatus` 與 closure `4ABFD0`。`4ACBF6/4ACD05` 讀取並呼叫該函式指標。`4A94B1/B6` 將管理器 FB79F0 傳入 `544940`。 | 本地 API 接收 key、category、狀態，可直接改點狀態。沒找到既有點時直接返回。 |
| 收到伺服器發來的點狀態更新 | 8-byte dispatch entry function 在 `4+8*opcode`。`4ADEBD` 將 +0x244 設為 4B32E0，opcode 0x0048。`4B3327/332B/332F` 取 +5:u8 狀態、+4:u8 category、+2:u16 key。`4B3336/333B` 使用同一 FB79F0 及相同 `544940`。 | 於已註冊、腳本可到達的點，腳本操作可替代這一個 S2C 狀態更新的 native 效果。不能據此宣稱原服 Field19 曾發 48，亦不能把本地 setter 當作換圖。 |
| 切換一般出口外觀及互動 | `544962..54497B` 比對物件 +F6 key／+F4 category；`54498F/544993` 取 arg3 後呼叫 `543B30`；`543B77` 寫 +105。`543B7D` 分派 category 0，`543BC4` 分狀態 1 與其他值，後續重新選擇 PORTAL 特效。原 _PortalList ID 0、STATE 1/0 分別引用 A_Zone_BasisTeleportA01.eff／B01.eff。`544739` 的互動判斷也讀 +105。 | 同一份資料即可影響本地開關外觀與能否互動。依目前證據，Field19 若要改為本地清怪開門，仍要釐清哪個腳本在哪個控制器收到/算出「本群已清」並能呼叫此 API。 |
| 首次安裝一般出口 | 另一個 `543700` 的 E8 caller 為 `4B2BD5`，來自 `4ADEAD` 的 S2C 0027 註冊。其 `4B2B65` 先清舊集合，再以傳入的 row 建立；不是切換既有點狀態。現行 Field19 實作在出口需要顯示時才發 27/category0、enable1、auto0。 | 直接移除現行 27，當時沒有可供切狀態的點。候選可以進場預先安裝關閉的點，再由本地規則切換；若基於不可見的新增腳本或變更資源，屬另外設計及驗收，不是現行 Client 已做到。這種安排亦不保證總封包數減少。 |
| 玩家在出口按 Z | `544730` 本地檢查 +105、距離平方與互動輸入，category0 radius ×0.8，嚴格小於。在適用的 mode 中 `544070 → 544020` 發 6-byte C2S 001C，內容為 opcode、category、key。 | Client 可獨立判玩家處於範圍且按了互動鍵。001C 無目的圖、怪群、勝利或任務入帳欄。Field19 的圖序、出口 key→下一圖／結果規則可放事件定義；現有一般換圖／結果的相容輸出與合法結果提交仍需另外處理。 |

腳本行為的陽性對照為 `Event/TutorialMain.lua`（`662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`）中教學點 1/2 新增、關閉，以及 NPC 點 10016 關閉。`Event/TutorialBase.lua`（`26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`）之 Proto 0 的 SETTABLE pc1/5/9/10 確認 `PORTAL=0`、`TUTORIAL_POINT=4`、`ST_CLOSE=0`、`ST_OPEN=1`。本輪將上述兩個成員的全部 prototype 指令字與原 STP 解碼結果比對一致。具名教學呼叫不是 Field19 實際呼叫。 `Table/TutCheckPointList.xml` SHA-256 `fe0a7131118ae804897ed8255da00f4cf8bad58bbe8fcc87ca2e5676146a2555`，`Table/_PortalList.xml` SHA-256 `3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56`。

直接 E8 呼叫 `543700` 計兩個：4A914B、4B2BD5。直接 E8 呼叫 `544940` 計兩個：4A94B6、4B333B。目標原件函式窗口 SHA256（結尾地址不含）：`4A9460..4A94C0` 9bdc20e4d57abee81f8bfb9e5b55d9661473d387b8a51bc57569442bebe36d00；`4B32E0..4B3346` 2c59e69568c46f7ad1fe5c7557e15150249ef199b29ce91272f8d0a12c137a91；`544940..54499F` c95d0f95cd0813d2e1f523eaf56f36db43b645e643176d70b7c8f48847487152；`543B6A..543B86` a47cbafe5c60cb4af4680c2b052b89c6dc3bf9bc2383c19d5d4986926e6d19eb；`544730..5447EF` 0f66fd6985d6d4a57f9a1f1dac947de658f4e90a78188cc253335289e8d44223。

[Field19 原生出口與意圖](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/s00-iterations/S00-20261103-FIELD19-PORTAL-GATE.md) ｜ [玩家要求站上按 Z 的修正](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/governance/s00-iterations/S00-20261103-PHINDOS-V14-CORRECTIONS.md) ｜ [Server 實際寫出的 27 與 22](https://github.com/we88ec3-prog/ttr_server_roy/blob/0f431e4830246193532de8cb40385641151f6d7a/src/Tartaros.Protocol/KrPhindosBridgeCandidateProtocol.cs) ｜ [Lua bytecode 與可重查指令](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/shared/integrations/T01-20261029-semantic-review/t16/lua/kr-TutorialBase.lua.json)

教學第一戰另有已證「一次事件，後續本地編排」範例。TutorialMain Part2 在劇情 1000/8 後，PC16–19 請求 Scenario14，PC20–29 輪詢 IsScenarioEnded(14)。實際 getter 在 4AA519 調 4C2880 並於 4AA51E 讀 owner+4 的 scenario 字典值。CTutorial 表 B[4C] 的 4C4F20 從 payload+2 讀 16-bit scenario key，將同字典對應值寫 1。這是該教學控制器的結束事件，並非 Lua 對怪物生命值掃描，不可移作一般 Field19 每群清光通知；一次下發後，後續 Lua 能自己安排演出／教學點。 [Scenario14 教學 Lua 與 004C 原始 consumer](https://github.com/we88ec3-prog/ttr_anal_multi/blob/055e40018f35ce741df81364750afc5c0a844b06/kr-temp-roy/20261030-003535-chatgpt-web-roy-T16-111-KR-Quest14-tutorial-scenario14-C2S-S2C-client-loop-and-S00-boundaries.md)

本輪另查兩個相鄰疑點。遊戲較廣初始化的 48D7DE 呼叫 4A88E0，4A8902、4A8908 登記兩個 checkpoint binding，4A89B6 載入 Event/TutorialBase.lua。命名為 Tutorial 不足以宣告其他模式一定無權使用；仍未證 Field19 的事件會主動執行它。另有名字相似的 `lb.GetObjectCount`，4A1650 將 target 設為 4A0A30，該函式檢查一次性 manager 初始化旗標，已初始化分支（4A0A62 → 4A0A84）直接進 epilogue，未檢查怪群成員或生命值。wrapper 4A1F2C 透過 FE1780 呼叫後在 4A1F32 覆寫 EAX=1。不能從此名字推出可供 Lua 可靠取得「這波存活怪物數」的介面。
