# S00：伊莉西亞普攻片長與012A計數界線

接續 REQ-0016 戰鬥優先，v5人測期間離線查證；不更換測試服務，不操作／修改Client。
這一輪有新增程式／來源證據，不是單純等待或宣稱整體目標完成。原始KR SHA仍
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 名目片長不等於取消／命中窗口

沿用已釘 carrier/member 的11份ABF/ASD metadata，本輪追到保存REA/Ghidra函式：

- 7ADE80的有限偽碼：SpliteData讀FileID／FPS／StartFrame／EndFrame／Delay，組成20-byte row，
  再經7B1810的五DWORD copy插入向量。這是讀取／結構的部分來源，未完整重驗大型parser。
- CSpliteMotion的原版vtable C5029C+10=7D8CA0。此getter以current index+110，從+C0向量
  的20-byte row+4取目前FPS。本輪byte重新核對。
- vtable+C=7D8D20，轉至7D9630。已載入分支的7D9630迴圈累計row+C及row+10，
  即上述EndFrame+Delay，寫+10C；不是逐段EndFrame−StartFrame。本輪重核85-byte範圍，
  正常ret及內部條件保留，不把padding當函式體。
- 保存7A87D0偽碼的局部播放支路包含mesh+104倍率×傳入delta×motion virtual10 FPS，
  另外還有lag／frame倍率／repeat分支。因而不能把名目時長宣稱所有實際播放／取消時刻。

7D9630偽碼SHA `cc35fc7172d272d8c28959ae953b69aac3ea713fd25790ffe820a72a2154730d`；
7D8CA0偽碼SHA `17a64fda1bfbd67a2ee93e02ae1508af91fc35c195bbf4d1b5b829481efec7db`；
7ADE80偽碼SHA `3fce621e250e71437b469582a65f5d8910ab546351623bdeb6073cd0b7d29a8f`。
這些由本機保存bulk查詢核對Evidence/pseudo hash；只引用本段限定語意。

| Motion | ASD sum(EndFrame+Delay) | FPS | 無lag、倍率1的名目秒數 |
| --- | --- | --- | --- |
| 101 | 30 | 40 | 0.75 |
| 102 | 50 | 40 | 1.25 |
| 103 | 50 | 40 | 1.25 |
| 104 | 40 | 40 | 1.00 |
| 105 | 46（兩段，含負Delay） | 兩段皆40 | 1.15 |
| 106 | 48（兩段，含負Delay） | 兩段皆40 | 1.20 |
| 107 | 40 | 40 | 1.00 |

v5的Server把七段全部用0.75秒，會在較長片段尚未走完前開始下一動作／待機的可能性明確。
下一版候選對伊莉西亞普攻採用上列各段**名目完整片長**，不再將第一段時間套全部。
這是以有限資料改善Server排程，並非已找到官方取消／buffer／命中時間；impact仍是候選200ms，
102/103的1.25秒不能當官方最早可取消時刻。其他角色／技能仍保留原候選，待各自核對。

108有混合40/12/40/50 FPS與負Delay，不能用sum50/40得到整段時長。即使逐段推名目時間，
仍需完整播放器／segment更新與lag分支才可升格實際時序，本輪未改其時間。

## 012A：不能把除33直接當毫秒契約

545E20的有限接收鏈仍為actor匹配三個控制槽，header8、每row Skill WORD＋signed DWORD，
reset非零清表；wire值除33後寫總／剩餘計數。54F200則每次執行將非零剩餘計數減一。
5452C0呼叫54F200位於後段輸入發送時間／credit gate之前，因此不能由C2S輸入間隔
直接推定該計數的牆鐘頻率。何時呼叫controller update、FPS／暫停／lag影響及UI消費尚未閉合。

本輪**不發012A猜值**，也不以6000/33個計數宣稱一定等於6秒。Server單調時鐘的冷卻權威
保留；Client圖示／input gate的同步列後續，不能假稱v5已恢復冷卻UI。

## 驗證與後續

[檢查器](../inspect_tutorial_combat_sources.py)新增`--animation-timing`，輸出
[14個有限視窗＋11份資源metadata](evidence/S00-20261101-COMBAT-ANIMATION-TIMING.json)。
這是byte／局部結構重核，不是FULL-PASS、官方Server順序或完整傷害／動作裁決。

14個HappyPath案例通過；既有正常旅程採完整第二段時間後續接，並增加受控clock觀察：
排入第二段後850ms仍施放且無待機封包，片段完成後正常停止。這驗Server名目排程，
沒有執行Client或證明取消窗口。208方法／10正向／198暫緩不變。
準備中的修正不部署到正在測試的v5；需與實際戰鬥回報合併安排下一個有用測試段落。

下一步：補segment實際播放／hitlag與取消條件，核對冷卻counter的scheduler／UI使用鏈；
保留原始證據與T10/T11主責，不變更owner／formal admission或normative pin。
異常／重送／競態／恢復／安全與壓測只記待測，現在不執行。
