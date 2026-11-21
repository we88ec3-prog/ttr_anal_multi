# 怪物投射物視覺 adapter

2026-11-22，Server-owned MEF 行為配套，NOT_NATIVE_MEF。來源為
[P0 actors/combat](../../kr-extra-roy/MEF-P0-level-execution-20261118/actors-combat/report.md)
第4～5節及其54個原件視窗；原KR BIN與指定v2對應視窗一致。這是封包呈現接線，
不修改Client，不把畫面物件當成命中／傷害權威。

## 契約

既有 MonsterBehavior V1 的 attack.projectile 可加可選 `visual`：`type` 僅接受
已核對有主體效果的1或43，`scale` 預設1，範圍(0,8]。兩者ground／impact宣告為空。
沒有visual時維持既有無子彈封包的Server直線投射物。新欄位在舊內容省略，不變更
原有配套SHA；新增配套使用新檔名。

第一版只用方向mode0：前搖完成且Server flight成功建立時，送0094建立子彈，
然後0000 selector5=100／selector6=整數speed。視覺開啟時speed必須為正整數；
既有非視覺speed不受此新增限制。這是本專案數值映射，Client frame divisor仍會
影響畫面步進，速度一致性待人測；duration不能校準方向速度。

0094為2+24*n：row source u16、bullet u16、metadataType u16、visualType u16、
起點X/Y signed16、scale f32、direction u8、durationMs u16、mode u8、兩個u16。
第一版兩Type相同、後兩欄為0，duration取min(最大壽命,距離/速度)向上取整毫秒。
起點四捨五入到整數；使用此配套的地形與出生座標須在signed16可表達範圍。
沒有以0000其他selector校正位置：CBullet consumer只處理5／6。

每個戰鬥instance有獨立flight→bullet映射，ID使用low byte2的256個槽，與怪物
low byte1、玩家low byte0分開。同一槽在舊001A已排入有序輸出後才重用。
普通飛行不逐tick發位置；Server命中、碰地形、距離／壽命到期、玩家死亡或場景
取消後送001A清除，來源死亡後已射出的飛行仍完成。原生duration到期不會自行
刪除方向子彈。換圖不得把舊flight／映射帶入新combat。

## 交付與驗收

本輪另收緊既有怪物 `nativeMovementSpeed` 為1..32767，因實際selector5／6消費者
使用有號16位元；公開與Server內嵌schema同步，包含既有projectile／damageForm欄位。

已提供獨立的 [關卡稿](phindos-stage462-case693-integrated-projectiles.scenario.json)
與 [AI配套](integrated-projectiles.monster-behavior.json)，SHA分別為
`29f4e12f69e849d39835f0d1317a1d94c1b0c0798361d49f745f4fe84c6d1ebc`、
`eaf55a1723fff3ba3b5cf52c9286e6d7e7f1264bb1049b15b732cbca49903864`。
只把入口怪換成80HP固定砲台，觸發距離128、5傷害、speed60、最大距離256、
半徑2、壽命5、Type43；全部為本專案配置，不宣稱原版物種招式。

原版BND兩路正常入口各有5個0094與5個匹配001A，節點轉場無殘留，兩路均保留
波次／頭目階段／機關，保存88EXP並返回同村原隊伍。舊整合稿兩路也重驗通過，
保持零0094。實際隔離Host已載入上述配對；目前商城測試服務未替換。
公開schema與私有schema位元組相同，12份新舊行為文件驗證通過。

私有啟動腳本新增 `-IncludeIntegratedProjectileVisuals`，自動選整合版並核對兩庫
關卡及AI雜湊。私有 `check-mef-integrated-dungeon.py --projectile-visuals` 可重驗
兩路、每枚子彈與來源ID、型別2、不殘留、配套SHA、機關帳本及結算。

靜態核對採54個既有原件視窗和每條instruction bytes，原BIN與指定v2相同；
原Table與現Table的Blt2成員同SHA
`8fbc0c8d7ad5b43189f0858adff2d22a2945734dd553813027df1d614913bde0`。
native-evidence.json SHA為
`e4f88884ebf3a261d69fc592ea6a3c4376dca9e2cea5995eef382feff2364b7d`。
沒有把這項有界核對升為T01全文FULL-PASS或Client遊玩證據。

Typed loader、JSON schema、行為配套匯出、Server前搖／飛行／生命期及封包列需一起
驗證；保持Server原有碰撞、傷害與清場等待。先做正流程：前搖後出生、飛行命中、
地形／距離／壽命正常收尾、來源死亡後尾段及場景清理。重送／併發／故障等維持
待測。指定v2的效果掛載、可見性、方向及速度需使用者實機操作，不能由綠色測試
宣稱已通過，也不聲稱已降低現行Server CPU或網路量。

最終Release Host／檢查器／管理端零警告／零錯誤，**648/648 HappyPath通過**。
前兩輪各647通過／1項預期hex補零錯誤；實際26-byte mapper符合原件，預期值以獨立
struct欄位布局重建後單項及完整套件通過。失敗TRX仍保留，不當成通過。
完整來源與驗證雜湊見[機器可讀收據](monster-projectile-visuals-validation.json)。
