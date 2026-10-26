# KR T03 選服呼叫介面審核 — 待整合

來源 Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。REA 6.5.0 / Ghidra 12.1.4，profile 3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece。原始 Evidence：evidence/rea-server-choice-ui-66c090.json，ev_121cd8b34bcf00e4ad7b10bb2cc7e51fab1929ae68b7d2f7c9a32d9533d5b325；檔案 SHA256 9b79a88551a24c1cd7d9ed48b5f19f99025e6b1c5b8e43dc240652e56fe798ca。

## 第一批已觀察的組合語言（後續補查見下文）

- 66C0BC 保存傳入 ECX 到 EDI。stack argument 的 +F0→+CC→+DC→+20 值存為第一選取值，中間 +CC/+DC 空指標會得到 -1；+F0 本身仍需有效。
- 若輸入 EDI=0，66C0F9..66C121 才從同物件 +F4→+CC→+DC→+20 取第二選取值，否則使用傳入值。偽碼沒有顯示這項 ECX 輸入與 fallback，不得只依偽碼重建介面。
- 66C12E..66C141 將兩個選取值分別交給 5078C0 與 507750，receiver 由 FE1B54 取得。EBX 保存前者結果，ESI 保存後者結果。本輪沒有展開這兩個方法，不能替結果命名為官方負載或錯誤碼。
- F94294 非零且 EBX 非零時：ESI=0 直接返回；否則先呼叫414680，PUSH ESI、以 FB1318 載入 ESI 後在66C1A7呼叫 T02 的4957C0。之後重新讀第一選取值寫 D63DCC，空節點寫 -1。
- 未走上述分支時：EBX=0返回，EBX=4或5走另一條訊息／UI路徑；其他 EBX 值仍要求 ESI 非零，再於66C247以相同 PUSH ESI / receiver 方式呼叫4957C0。此路徑將42C530的返回值寫入D63DCC。
- EBX=4/5的路徑組合字串後呼叫58B270(0xCA)，並呼叫 stack argument +F8 所指物件的 virtual+90，參數1；文字、提示含義及 virtual 方法名稱未驗證。

Provider body 為五段 inclusive ranges：66C090..66C2DF、66C2E5..66C38A、66C390..66C42A、66C430..66C47E、66C484..66C4CD。不能把含洞的外包範圍當完整函式位元組。

## 推論、成立條件及限制

這是選取資料經狀態分支轉交連線介面的靜態證據；成立條件包括有效 UI 物件、選取節點及 helper 返回值。不能證明連線成功、endpoint可信、官方伺服器狀態值含義、重試順序或可玩流程。4957C0核心屬T02，僅記錄呼叫介面；沒有重做其socket/framing語意。

caller 66C620、helpers 5078C0/507750/42C530 為後續候選；須核對主責與整合者登記後才展開。F94294的意義／來源、D63DCC後續消費、UI資源標籤仍未知。固定localhost、單頻道與ticket/lease屬本機AI策略，不由此結果獲得官方依據。

## 行政界線（補得確認前的紀錄）

66C090已有本地T03/roy候選登記與原生Evidence，但未見獨立的整合者確認紀錄。本審核保留待整合，登記不是語意驗收或跨分支排他認領。此限制不改寫已觀察的指令結果。

## 目前有效狀態：整合者確認及四項補查

上述行政缺口已由使用者明確確認解除，見evidence/integrator-confirmation-20261025.json。以下補查仍待整合，不因認領確認自動通過驗收。

本節補足前述「尚未展開helpers」與四項候選待登記狀態；先前觀察保留追溯，不應再據其宣稱目前尚未查詢四項方法。

- 66C620：event+10=70A且source對應UI+F4時，從event+18所指物件+20取值放ECX，傳UI receiver為stack argument呼叫66C090；event578且source對應UI+F8時，ECX清零再呼叫，因而走F4選取fallback。兩路先對F4/F0/F8 controls的virtual+90傳0；方法名稱尚未驗證。709只分派66BBD0/66C510，本輪未展開。
- 5078C0與507750均按第一引數匹配群組物件首dword，再按第二引數匹配+40..+44容器中stride60的row首dword；查無群組／row或容器空則回0。前者回row+4的dword；後者回row+C的指標。故66C090中的EBX是所選row+4資料，ESI是同row+C介面指標，不是全然不明的兩個lookup結果。row+4數值0/4/5仍只有控制流程含義，不能命名官方負載／維護／滿員狀態。
- 42C530以EAX收control指標，讀+CC→+DC→+20，中間任一空節點回FFFFFFFF。支持普通切線分支D63DCC保存第一選取值；其後續消費者尚未驗證。

補查Evidence為evidence/rea-server-choice-event-66c620.json、rea-server-choice-state-5078c0.json、rea-server-choice-record-507750.json、rea-server-choice-index-42c530.json。各檔保留原生provider body/assembly/profile與SHA，無目標執行。row來源／寫入、UI標籤與T02連線成功仍是缺口；不能由傳入有效指標提升為官方可連線證明。
