# 正常主線角色成長與結算：待開發門檻

狀態：設計需求與缺口清單，非已核准的EXP演算法或已完成獎勵系統。

- 持久層區分敘事里程碑、Quest合法完成、獎勵權利、實際入帳與Client發布；不得把舊navigation revision重命名為PAID。
- party experience與role experience是不同來源域；每個grant需明確scope／recipient／數值單位／policy版本，Client獎勵文字僅作資料來源。
- level必須來自明確成長政策與持久狀態；debug為了測試跳轉而補顯示等級，不能回填正常角色或算自然升級驗收。
- Client publication需閉合role初始化、level／EXP相關欄位及HUD／NPC候選更新；005C的未知DWORD不填猜測的當前／門檻EXP。
- 正常交易先確認QuestOutcome合法且提交，再發布狀態／餘額；未綁定reward policy或publication時不得標整條任務正式結算完成。
- 角色初始數值與升級後能力／技能／可用裝備另有政策，不能只把level byte拉高而其餘維持無來源值。
- 非正流程的重送、故障、併發、資安測試仍列待測，不因設計需要而現在執行。

來源與目前第一個level門檻風險：[22任務／30獎勵與角色欄位核對](../../governance/client-variants/20261108-mainline-progression/README.md)。這不撤銷先前到馮德斯的限定人測通過；它阻止將更後續debug路線誤算完整自然主線。
