# KR T03 CExpeditionDialog／選角請求界面 — 待整合

來源為同一原始 KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；REA6.5.0／Ghidra12.1.4，Python3.10.6用於獨立PE／RTTI位元組核對。沒有執行、附加遊戲，沒有修改原anal、資源、帳號或存檔。

## 身分與範圍

舊16號報告只給出「角色UI673EAA呼叫4A3B80」線索。本輪先確認673EAA是位於673DA0的CALL4A3B80，再以Ghidra incoming DATA reference定位vtable slot C35AA8。歷史index只提供table候選，獨立原檔核對vtable C3594C、COL C77F7C、TypeDescriptor F865C4及raw type-name，並與REA read_bytes結果交叉相符，確定為`.?AVCExpeditionDialog@FUI@@`。

這不是從檔名或日期猜的UI類別；也不是看到CExpeditionDialog就宣稱所有相關欄位皆為正式遠征隊／廣場規則。方法只認領T03 UI界面；其他42呼叫點與世界內資料維持原主責。

## Control與事件分支

672AE0建構函式寫該vtable並初始化member pointers，未在該body找到control ID綁定；672DC0/672E50為不同的生命週期callback。672BE0的assembly顯示：

| 配對輸入 | native位置 | 可確認的範圍 |
|---|---|---|
| ID12000＋物件+C0目的位置 | 672C08–672C15 | 交615FC0 helper的ID／指標配對；不是人類按鈕名稱的證明 |
| ID18000＋物件+DC目的位置 | 672CF0–672CFD | 同一helper配對；資源實際存在性及畫面文字尚未驗收 |

673DA0事件handler：event+10為0x578時，若source ID(event+8)等於+C0 control的+20，建立FoxUI event F42EF並帶+D8；若等於+DC control的+20，先呼叫414680，再以+D8及0呼叫4A3B80。event0x387另建F4247事件。只看到其中一個source ID，不足以把所有點擊都命名為進廣場。

4A3B80的payload為uint16 command42＋兩個uint8；只有全域FBA798==0時，經FBA854 virtual+10以slot0送4 bytes。該sender還有5F47F5、5F48F7呼叫點，本輪僅保留引用，不替其他場景定義語意。FBA798的完整來源／業務含義及執行值未查證，不能擅自改零。

## 選中描述值與可用資料

672F00的assembly明確以unsigned index<=9查F94304＋index*210。記錄+5C非零才得到記錄指標；非零資料分支在673171把選中描述值寫入dialog+D8。傳入描述值0時先取現有+D8；672E50在其關閉條件成立時會清+D8。

不存在可用記錄時走673790及另一組UI呈現路徑。原始body與多段inclusive ranges全部保留；這裡沒有把整個span或pseudocode行數當完成率。672F00還含字串／統計呈現與多個virtual UI-state calls；未把未恢復的GUI方法名稱補猜成正式Show/Enable含義。

**成立條件／限制**：+5C是此UI消費路徑的條件，不能由此認證原始角色取得政策。T04仍負責記錄建立、旗標來源與世界初值。handler與42 sender本身沒有再次檢查+5C；因此不能把這個UI條件當server授權規則，或保證任何非正常事件都被阻止。

## 遊玩影響與後續開發

- 固定fixture把頭像變彩色，只能與這條「有資料才更新描述值」路徑相對照，不能證明角色初始化或世界進入完成。新證據指出須核對資料+5C、control ID／資源、當前+D8、事件類別／source ID及sender gate；本輪沒有量測它們的執行值。
- 新原生證據不能支持`42 → 43/69即廣場成功`的整組配對。43移除type6物件的既有更正仍有效；T05負責實際廣場前置條件／轉場，T04負責角色世界資料，T02負責slot0連線／傳輸時序。
- 若要補相容後端，先取得對應帳號可用角色與選角／切線時序的規格；不要複製固定角色／初值，也不要為讓畫面前進而猜成功回應或改client全域旗標。

目前仍缺：ID12000/18000在原始同版本資源中的實際標籤／存在性、完整資料來源、事件通知F42EF/F4247的業務消費者，以及後端如何決定選角後的下一場景。這些缺口逐項保留於PLAYABLE-FLOW-GAPS與unknowns，不以UI界面小成果驗收整段可玩流程。
