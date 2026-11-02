# S00：Field19清怪後必須進出口才換圖／結算

## 使用者執行觀察與需求

主工作流轉交v12人工回饋：已到村、載入介面通過，但清怪後不應直接換下一圖或完成，而須走入出口。此是使用者確認的正流程需求；本文件不捏造另外兩項尚未交付給本子工作流的異常。先前Server「清怪自動下一節點／結果」應修正。

原MEF內容仍未取得，Chart只證node1/map191→node2/map192，沒有出口座標。因此出口位置／啟用規則為明示Server重建政策，Client顯示及走入意圖使用以下原生介面。

## 原生可用入口

[離線檢查器](../inspect_field19_portal_gate.py)／[原件範圍SHA、21項指令／vtable斷言、資源與候選範例](evidence/S00-20261103-FIELD19-PORTAL-GATE.json)。
目標BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；7段完整連續範圍解碼與內部分支落點核對通過。

- 沿既有S00的27註冊／18B-row證據，category0交543700建CCheckPoint，建立portal效果與小地圖記錄。
- row欄位：WORD key、signedBYTE category0、BYTE enable、floatX／Y／radius、BYTE automatic、BYTE auxiliary。27替換整個checkpoint集合，應一次送同場需保留的所有row；不是附加API。
- 543700存automatic到+100、enable到+105；category0把有效觸發半徑改為wireRadius×0.8。C55BA8原常數為0.800000011920929；顯示scale另以wireRadius×0.2334計算，不混為碰撞半徑。
- 544730先檢enable，然後計算玩家至checkpoint距離平方；automatic為0才要求動作鍵，非0可單純走入。有效範圍是**嚴格距離小於半徑**。+104抑制持續停在圈內的重複啟動；離圈清除。
- FormationController的547F90呼叫544A00；後者選最近有效checkpoint，CCheckPoint virtual+64精確指向544070。
- category0在已查普通mode分支到544020，送**C2S001C，6bytes：WORD1C／WORD category／WORD key**。它只是意圖，沒有XY、Map或通關證明。其他global input／controller條件仍需正常初始化，不能保證每個mode皆無條件發送。

## 出口效果來源

原PortalList member SHA `3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56`。
4F7730載入時用 `(ID<<16)|STATE` 索引；constructor543A37..543A5A用 `(auxiliary<<16)|enable` 查同一字典。
故auxiliary0／enable1選 `A_Zone_BasisTeleportA01.eff`，enable0選`A_Zone_BasisTeleportB01.eff`；選定表證明是開／關效果名稱，沒有出生座標。
完整effect相依是否存在與實際顯示未在本輪驗收，不從檔名推AI或MEF。

## 最小Server政策

1. 本節點怪物由Server權威傷害降至0，停止戰鬥決策並標示「已清怪，等出口」，**不換圖、不發22結果**。
2. 發27 category0／enable1／automatic1／auxiliary0。候選wireRadius5，Client有效半徑約4；portal map191為430,385，map192為391,369。兩點均在已釘定BND首兩層為0，且各距候選玩家出生點12單位，不會站在出生點立即觸發。
3. 收到本節點精確1C(category0,key)，再檢Server自己持有的當前pose在有效範圍、仍擁有actor且節點確已權威清怪；Client不提供任意目的地。
4. 第一圖合法出口才保存節點完成／初始化map192；第二圖合法出口才保存第二節點完成／發一般22結果。之後33、15/3、15/4與到村保存仍依現有路線，不以1C直接宣布Quest15完成／發獎。

key1/2、座標、半徑與「清怪後開門」是針對人工需求的重建配置，非官服抓包或已復原MEF；若Server另加位置同步容差，須明示而不改稱原生半徑。可採清怪後才建立出口，避免猜未開門時的原版外觀。

本輪僅來源查核，未操作Client、啟動Host、發包或修改Server檔；實作與人工驗收由主工作流另記。負向、重登、重送、故障等仍列待測，不執行。
