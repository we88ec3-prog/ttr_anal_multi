# S00：Field19候選怪物動畫資源核對

[唯讀檢查器](../inspect_field19_actor_resources.py)與[逐檔SHA／動畫欄位證據](evidence/S00-20261103-FIELD19-ACTOR-RESOURCES.json)。
來源釘定目前Table載體`ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`、ActorList member SHA存證據，以及Monster Base載體`1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957`。沒有執行遊戲或修改資源。

|模型ID／PRE|Actor FILE|SCALE raw|motion4/6|motion101|motion7|
|---|---|---|---|---|---|
|1001／1|00_HokyPoky|110|HokyPoky_MOVE01.gb3|HokyPoky_SKILL01.gb3|HokyPoky_DEAD.gb3|
|1009／1|01_Moose|100|Moose_MOVE01.gb3|Moose_SKILL01.gb3|Moose_DEAD.gb3|
|1004／1|01_Nepenths|100|Nepenths_WAIT01.gb3|Nepenths_SKILL01.gb3|Nepenths_DEAD.gb3|

三者motion1等待、9受傷亦存在，選定18個動畫slot均核對。FrameSpeed均40；沒有GB3完整時間軸／命中時點或AI冷卻復原，不從這個數值直接造官方攻擊秒數。

**1004的4/6都用等待片段**，不應無說明套用移動型怪物的奔跑外觀。候選Server可以將此模型設為定點出手，或選擇另一個有來源cluster；這是重建政策，尚未證原版全部行為。1001的raw SCALE110與另兩者100保留，不宣稱網路比例單位。

ABF列出攻擊Effect參考，但本輪未閉合怪物技能表、射程／碰撞體積、傷害或MEF。現有通用追擊、HP／傷害／攻擊時間皆須維持Server候選標籤。選定ABF有動畫檔名不等於完整相依資產／實際播放相容性驗收。

一般Scenario為kind3 FormationController；現有S2C000A owner及actor/related欄位與控制槽存在，不證明多名隊員的完整AI跟隨、切角或技能同步。在未完成followers實作前，只開放單一已擁有角色的編隊是明示候選限制，不能稱原版三人編隊完成；也不能把此限制說成多人連線未開放，兩者是不同功能。
