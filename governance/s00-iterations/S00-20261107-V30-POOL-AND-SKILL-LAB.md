# v30 泳池廣場、可移動範圍與技能測試場

## 使用者要求與實機觀察

使用者要求：「請先改用泳池廣場，並確認各廣場有哪些的可移動範圍相同?若相同且有存在.mmt則可以共用.mmt」。另要求 SP/MP 最大值500測試場、其他角色及進階技能可測。
使用者確認 v6「廣場NPC頭上名稱是中文」；廣場黑底僅右上小地圖，3D正常、城鎮正常。冷卻增量修正因資源回復太快尚未完成實機驗收，不能記通過。

## 已部署與驗證

私有 main `6ca94b549e1713aef952eb50e492b3442a867a74`，2026-11-07 07:22:32 UTC啟用v30，PID12116；後續已核對相同Host路徑及HTTP/auth健康。原SQLite先備份；正式規格pin不變。
Host DLL SHA256 `8e04c95fbac33c2637e59152a27f4414e3ab63dfcd0c931e1252d32931623998`。
Network DLL SHA256 `0d2bc2261286cc469c8d43b503b5000aa34d9d0c816a21e637316eb0c3c6a49a`。
64項HappyPath合成通過（59秒，零失敗／略過）、Release publish通過；另用實際Server reader驗證泳池完整BND、出生走廊及12NPC落點。兩項新增TCP測試曾因測試reader丟棄0034而逾時，修正讀取工具後通過，不是掩蓋正式Server逾時。未執行延後測試。

## 泳池廣場

Server廣場由511改1088，MAP/BOUND=`Square03N_Avatar_Pool`。使用韓版原有mmt及texture，這個切換不需新EXE或額外Client資源。
BND SHA256 `8086412206ffe2566427a5ec62d95496ae9a4c8fb2da109e186d5ce067c60765`，version2、1536平方、完整static0/1並明確pin准入。出生900,900有效；3個原NPC落點受阻，只在泳池候選表調整10013至855,940、10014至865,945、10069至845,910，其餘9個保留。是Server安全佈點，不是官方MEF位置。

## 哪些廣場可共用mmt

完整枚舉44份square BND，43份可按現行兩靜態層解析；msquare01有額外layer2，未猜測其語意。逐格比較完整nonzero聯集與世界extent，square001另精確正規化到世界1-unit格；不是只比較1536尺寸。

|完整靜態可移動範圍相同的群組|現有mmt／處理|
|---|---|
|square002、Square02DSakura|兩者均缺mmt，無來源可直接共用|
|square002_TL01、Square02Dsunflower_TL01|兩者均缺mmt，無來源可直接共用|
|Square03D、Square03D_Sakura、Square03N_Fullmoon|前兩者mmt原已相同；新增Fullmoon獨立別名副本|
|Square03N_Avatar_Pool、Square03N_Avatar_Pool_Kr|BND整檔相同；新增Pool_Kr獨立別名副本|

依使用者條件授權，實際只新增 `Map/Minimap/Square03N_Fullmoon.mmt`、`Map/Minimap/Square03N_Avatar_Pool_Kr.mmt`，逐byte複製其群組既有韓版descriptor；原MiniMap.stp未修改，所有舊檔保留。來源／目標hash見[reuse manifest](../client-variants/20261107-square-minimap/reuse-manifest.json)。這兩別名目前未被Map1088使用，實機未測。
原square001沒有匹配其他群組，沒有替它借用泳池mmt。靜態可移動相同不代表動態MEF障礙、裝飾／地標或標記對齊已實機驗證；各別名顯示仍待測。
完整資料與重現工具見[調查報告](../client-variants/20261107-square-minimap/REPORT.md)及[square-bounds-equivalence.json](../client-variants/20261107-square-minimap/square-bounds-equivalence.json)。調查原稿「未修改Client」限子工作範圍，後續主工作新增兩別名以本節與manifest為準。

## 技能測試場

原1000場景保留，新增伊希莉亞500及9角色×3階段共27組手動選擇。網址 `http://127.0.0.1:5082/local-test/progress`；手動選階代替V，真正V按住／釋放／消耗流程尚未實作。測試角色／裝備／技能不寫入帳號所有權與正常主線。
135個槽位中119個允許有限動畫／耗量候選測試，16個來源連結缺失或多階段歧義明確禁用；尚非所有技能完整實作。矩陣變體、特殊鍵、傷害／判定／位移規則仍有缺口，不把名稱近似當映射證據。[候選來源](../client-variants/20261107-role-skills/README.md)、[V有界契約](../client-variants/20261107-charge-skills/README.md)。
MP/SP仍每10秒回復最大值50%，HP每60秒20%；本輪只改測試上限，不冒稱冷卻人測通過。實機短卡已送出，泳池顯示／小地圖與技能測試待使用者回覆；送卡後持續補16個缺口證據。

## 證據界線

這是修改工作副本與loopback Server候選，不是原始Client完整相容驗收；REQ維持CANDIDATE、不提升SPEC／T01 FULL-PASS。原EXE、STP、BND、貼圖、字型和新解包member均留本機，本庫只收metadata、分析與重現工具。

補證已完成：[16技能有界結構檢核](../client-variants/20261107-role-skills/blocked-followup/README.md)重讀41次原／工作member，檢查完整Practice／Active entry及指定ABF／ASD／EFF／輔助表；沒有可獨立閉合的active→motion連結，零項升級，16項仍禁用。本段停止擴搜，不宣稱整個Client不存在映射。

## v30 使用者回饋與延後項目

使用者回覆「泳池正常，但部分NPC位置在不可移動位置，先記著以後再處理」。記錄泳池顯示正常的有限實機結果；NPC安全佈點退回並依使用者要求DEFERRED，尚無明確NPC ID／座標，不要求現在重測。先前Server靜態BND點位檢核不等於實際Client可接近性或全部NPC位置驗收，不覆寫先前合成結果，也不標記全廣場完成。

技能未開放共16個槽位：12個尚未閉合技能ID至動畫／特效的對應、4個有多段候選但階段執行規則未確認。這是測試場的明示保留，並非角色等級不足、資源不足或已證實Client缺檔；完整表與補證見role-skills/blocked-rows.json及blocked-followup。開放119槽也只屬有限動畫／耗量候選，未宣稱所有實戰判定完成。
