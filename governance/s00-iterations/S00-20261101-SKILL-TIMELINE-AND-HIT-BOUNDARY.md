# S00：技能名目片長與命中時間的不同證據

REQ-0016 戰鬥優先續查；目前使用者 v6 結果卡尚待回覆，沒有替換服務或操作 Client。
本輪仍不能聲稱找到官方命中時刻，但縮小了動畫分段與效果 Delay 的使用界線，
並修正兩個伊莉西亞技能的 Server 名目時長。不是完整技能／教學驗收。

## 分段播放來源

原始 KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
引用既存 REA/Ghidra 結果並核對原檔限定範圍，沒有重新全量反編譯：

- CSpliteMotion vtable `C5029C+20 → 7DA4D0`；getter +10 的 `7D8CA0`
  讀目前 index+110 對應20-byte row的FPS，沿用前輪核對。
- `7DA4D0` 以 row EndFrame+Delay 的累計範圍選段，呼叫 `7DA460`。
  `7DA460` 寫目前 index+110，扣去前段的EndFrame+Delay，並轉到模型分段更新。
  本輪有界 bytes：`7DA4D0..7DA59D`（205B）、`7DA460..7DA4CA`（106B），皆至ret。
  `7DA47F` 寫index的來源是ESI；不要只憑偽碼的隱含暫存器命名建立ABI。
- 先前 `7A87D0` 局部播放鏈以當前FPS×delta×倍率推進，仍有hitlag、補償、
  repeat及更新步長影響。這次只推中立倍率、無lag、連續時間近似的名目片長。

偽碼SHA：`7DA4D0`=`7fa25d19f4ad1c03729e36deafcf34b94a16559fa0fb325e383495ecb5cddb71`；
`7DA460`=`141cac30d39262bc4e568d62de0e1ac7f394a8b1eebecad34c09f0f3d319c906`。
沒有把大型播放器與所有下游或正式取消／命中窗口升為FULL-PASS。

| 動作 | 各段 EndFrame+Delay / FPS | 名目秒數 | Server候選更正 |
| --- | --- | --- | --- |
| 108／X | 8/40 + 4/12 + 8/40 + 30/50 | 4/3≈1.333333 | 由1.34改為4/3 |
| 109／Z+C | 39/40 | 0.975 | 由1.08改為39/40 |

兩者不是從ABF Length一律除40，也不是官方最早取消時刻。前輪報告對108混合FPS的
限制仍保留；本輪只新增分段getter／選段鏈，將「名目片長」收窄到上表可用推導。
實際畫面、hitlag與有限更新步長下可能不同。其他角色的候選尚未由這份表驗證。

## 為何沒有將200ms改成效果Delay

唯讀釘住的 `Character/Cha/Avatar/04_Isla.stp` 中，選查的101／108 ASD只描述
AnimationHeader、AnimationData、SpliteData、Effect、Sound等；`Cha/Isla.abf` 對應
Animation為屬性記錄。這些有限記錄不是官方傷害判定表，也不是整套資源不存在判定資料。

Effect/Effect.stp SHA `ef0c4fae74c5660aaea7cbe0919549c20db2fd248c81f829aeb7616a11b300ec`。
由ASD的Effect參照可讀到：

| member | SHA256 | Element數／Delay原值 |
| --- | --- | --- |
| Effect/Character/C_Isla-BasisAttack01.eff | 0b8eed6cc1c72be4d1d43f2a3407cc6ab51ff90d37a28aaa2ae962ff8a09b124 | 3個，皆4 |
| Effect/Character/C_Isla-BasisWslash01.eff | b124fdee5bd0710a99e55a5eb26967e272988185551a99a65a9a0e7161aca42c | 36個，Delay含3/7/8/9/10/11/17/21/22/23/24/25/29/30/31/32/33 |

這些Element帶模型檔／倍率／位置旋轉，屬視覺效果資料。Delay的引擎時基及與官方
判定producer的配對尚未閉合，不能因出現多個Delay就生成多次傷害，或把4當4ms／4秒。
SkillActiveTable的29/30/31 level1只有已列的ACTIVEINFO與ATTACK數值，Practice檔的
49/50/52屬學習條件與SkillLevel映射；這次選查沒有建立官方impact時間欄位。
BLT/Blt2子彈資料也未建立這三個技能的發射／命中對應，不能擅自套用。

因此Server固定200ms命中仍明列重建政策，尚未以假精確的效果時間取代。
T10/T11/T12下一步需提供：判定producer或官方同版事件證據、各技能的擊數／時刻、
技能／motion／effect的精確映射、clock與hitlag／取消關係。

## 可重現與驗證

`governance/inspect_tutorial_combat_sources.py --animation-timing --skill-timeline`
在指定workspace、原BIN及capstone路徑下輸出新JSON。此輪結果為
[16個限定指令視窗與13份資源metadata](evidence/S00-20261101-SKILL-TIMELINE-AND-EFFECT-BOUNDARY.json)，
包含原檔SHA、carrier/member SHA、工具版本、有效指令邊界、視覺Delay集合；不公開原資產。

15個HappyPath cases通過，既有TCP「受傷→一次X→Z全滅→返回→蘋果取得」仍通過；
既有正常動作案例增加Z+C空揮後1秒回待機的檢查，能攔住舊1.08秒Server鎖定。
這是候選排程／正常TCP合成驗證，不證明Client畫面、官方取消時刻或完整戰鬥順暢度。
208方法／10正向／198暫緩不變，沒有執行異常／競態／恢復／安全／壓測。
未換版、未改Client／DB schema；REQ-0017出口及完整新帳號→廣場仍未完成。
normative pin、formal admission、Task owner與APPROVED狀態不變。
