# 演出期間放棄：kind2 與 active-Q Stop 的清理界線

2026-11-24。SOURCE_BACKED_PARTIAL；本批是既有 REA／Ghidra 與原件位元組的接線核對，
不是 Client 操作或新增演出取消功能。前置為[模式2放棄來源](../SCENARIO-ABANDON-REQUEST-20261124/README.md)。
目前 Server 的 Encounter／Portal 與 Q15 戰鬥取消已另有正常工程驗證，本報告不降低或代替它們。

## 1. 新閉合的分支區別

原件 `5978D0` 的確認事件，在 `59790B` 要求事件 `6A7`，經型別處理後於 `59793F` 讀確認 kind：

|原件接點|精確行為|取消整合含義|
|---|---|---|
|`597942..59794D`|ESI=1；kind減1若零走kind1；再減1若零跳`59798C`|kind2直接越過`59794F..597974`的 Stop／關視窗支線|
|`59798C..5979BA`|兩次 owner+5ED8 非零檢查，合格才呼`53BA20`，然後返回|此選定本地分支的直接calls只有兩次owner getter與一次005D sender；沒有先呼`5624B0`|
|`59794F..597974`|其餘 kind 分支可在Q active==1時呼`5624B0(1)`，其後PostMessageW的Msg為0x10|這是另一條包含關視窗請求的分支，不能把它的Stop當作kind2放棄已執行的前置清理|

`597974` 的間接接點另由原 PE import descriptors／lookup thunk／IAT 解到 `PostMessageW`，
不是只依反編譯名稱命名。kind2 仍是既有 `5D 00 00`；不新增 opcode 或要求修改 Client。
**「同一函式有Stop」不足以證明取消路線先Stop。** 此處只排除已選本地分支的直接呼叫，
不宣稱所有未知間接 callback、另一個封包或執行緒都不可能清理，也不提升倒地／演出中按鈕可達性。

## 2. Stop 必須在 End 之前

沿用[演出清理契約](../MEF-control-flow-20261116/presentation/report.md)並重新核對同一原件窗口：

- `5624E7` 清ESI；`56251E..562521` 若M+28為0，跳`562891`而略過主要清理。
- active主段依序呼 `56268B→563FA0` RestoreMap、`562694→563A70` DeleteAllObject、
  `56269D→562B00` EndCameraOverride；尾端 `56288C→561DB0` 才進End。
- 因此已先End、M+28已清零時，再送到Stop不保證補做地圖／Q物件／相機的主要清理。
  輸入mask解除亦不是Stop，003F不是清理或副本業務成功ACK。

本批沒有重做函式全文審核；以上是原件已選 guard／callsite／順序的有界核對。
其它 owner 的音樂、圖片、controller 等仍遵循各自契約，不由這三個callsite擴張成全引擎恢復。

## 3. Server 接線決策

現有取消 adapter 不可只把 CanAbandon 擴成 Intro／EnterScene／ClearScene／ReturnScene，
再沿戰鬥返村直接換圖。[既有換場景分析](../MEF-complete-flow-20261115/scene-cancellation/report.md)
已明確區分005F新field安裝、old exit、controller重建與qco清除，不能用換圖成功代替演出取消。
`CMissionField` 的 [S2C0031→`4BCA90`→`5624B0(0)`](../MEF-entry-lifecycle-events-20261114/lifecycle.md)是已有接點，
但不是當前Scenario field已註冊同一handler的證明；不可因想Stop就向Scenario送它。

演出中取消實作的後續接受條件固定為：

1. 對選定Scenario context證明合法現有Stop入口及其實際receiver／handler前置條件。
2. 需要清理時先在Q active期間Stop，再切換field／初始化目的村，不能先End再補Stop。
3. 明定Stop可能產生的003F與既有敘事提交順序；舊回報不得被算成未完成任務結算，
   已入帳擊倒EXP／拾取物與原任務進度仍保存。不得虛構cancel ACK或wire generation。
4. 沿實際相機／map／actor／input owners檢查收尾；清list不會unwind正在執行的callback，
   對可繼續執行的舊callback要有選定內容的尾端生命週期證據。
5. 正常合成／TCP／獨立Host與指定v2操作分開；沒有遊戲實機證據時不聲稱畫面／輸入恢復通過。

這將「演出取消待確認」收斂成具體接線缺口，並非禁止其它MEF開發的共同gate。
原Encounter／Portal adapter的phase gate與房間保存保持；本批不更改它或開放未證停止序列。

## 4. 證據與重現

[native-boundary.json](native-boundary.json)，SHA256
`4374fe061ec096c1801853faa4b453867e88ff2ba20cc36f6b7cb21b2b6071f8`。
原件 KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
兩個從函式入口解碼的原件窗口共1,363bytes／361指令，沿用前兩包精確raw SHA；
五份保存Ghidra偽碼與原REA Evidence身份逐項驗。
另核真正PE section映射及關視窗分支IAT，前後核對原件SHA保持。
原表與Task owner／catalog／RR／FULL-PASS未改；未重做先前逾時的Ghidra匯入。

```powershell
python -B kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/verify_cleanup_boundary.py --bin E:/Tartaros/workspace/Tartaros.bin --bulk-directory E:/Tartaros/workspace/anal-multi/kr-bulk-roy --capstone-directory E:/Tartaros/workspace/outputs/scenario-abandon-20261124/capstone --output <new-receipt.json>
```

decoder沿用前批既有Capstone5.0.6工作副本，不安裝或調整設定，不執行Client／Lua或附加遊戲。
Server實作沒有變更；812HappyPath／三Release仍是前批占點排程的歷史基準，未冒稱本批新增執行。
本批只執行原件與證據只讀核對、Python語法及文件完整性檢查。整體MEF目標保持開啟。
