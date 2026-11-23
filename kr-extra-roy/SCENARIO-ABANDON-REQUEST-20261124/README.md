# Scenario 放棄確認到既有離隊請求

同日接續：[演出取消清理界線](../SCENARIO-PRESENTATION-ABANDON-20261124/README.md)
確認kind2跳過同函式另一條Stop／關視窗分支；不得把005D sender證據升格為已清除active Q。
兩窗口／五份REA來源另核，保留本報告原結論及戰鬥取消成果。

2026-11-24接續：[一般主線取消返村實作](../../design/scenario-content/STORY-ABANDON-RETURN.md)
已補Encounter／Portal及工程倒地取消、同連線NPC重開。下方原接線計畫保留為來源分析時狀態；
Q15橋接、播放中演出及指定v2原生倒地操作仍未完成，不因Server通過自動閉合。

2026-11-24。原KR唯讀、有界原件指令與已保存REA/Ghidra偽碼交叉核對。
這次補的是主線模式2可選確認路徑，不把既有RAID模式9的0031提示誤當主線退出。
不宣稱倒地實機入口、整個函式FULL-PASS或原服回村／獎勵政策已閉合。

## 新確認的有限路徑

1. `597380` 的控制項值 `2AF9`，在`FB73E8==0`時呼叫`5974D0(page,2AF9)`。
   `FB73E8!=0`另走`562320`，不能宣稱所有場景階段都會開退出視窗。
2. `5974D0` 讀當前mode `F9392C`。mode2使用`5978A8[0]=0`、
   `[597894+0*4]=597689`，進入明確Scenario分支。
   `597689`比較參數2AF9；相符時`597692`設確認kind2、`597697`使用訊息ID24h。
3. 原件編譯訊息表唯一紀錄`24 00 00 00 6C 8E C1 00 78 17 C1 00`，
   ID36的key指標`C18E6C`指向`kGiveupScenario\0`。第三指標是預設文字，不能稱型別。
   這不是以XML第36列猜ID。根Table.stp已是商城工作副本SHAea2af30c，未當原表來源。
4. 此路徑建立`F43FF`的FXUIEventI1，payload保存kind2，經既有CFh確認視窗交付。
   共用`5A4310`的F43FF到`5978D0`；Scenario `5AFE70→59BD80→5A4310`已有保存來源。
5. `5978D0`要求確認事件tag6A7h；原event payload為kind2時進`59798C`。
   `41A4D0()`返回owner的`+5ED8`必須非零才呼`53BA20`。此欄位本批未命名；
   不把它直接宣稱為party ID、任務或生命值。外層dispatch及倒地輸入可達性仍須另閉合。
6. `53BA4B..53BA6D`原件明確寫u16命令005D、尾byte0，送長度3到既有虛表+10h槽：
   **`5D 00 00`**。原偽碼把局部4-byte高位顯示為未知，不影響只送前三bytes；
   新核對的機器碼直接確認第三byte為0。不新增任何opcode。

這足以把「模式2放棄確認有條件連到既有離隊sender」記為SOURCE_BACKED_PARTIAL。
仍不足以說指定v2倒地時按哪顆鍵、按鈕名稱與座標、當前owner欄位滿足或畫面可操作均通過。
此前只有隊伍sender證據；不再把005D說成完全沒有Scenario來源，也不因此刪除剩餘玩家驗收。

## 證據與重現

[native-sources.json](native-sources.json)，SHA256
`750823d6a5a37e0e56cc20c5d6633ee5f7cb4c902a5b4886f50639a779e0eb77`。
固定原件SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
七個保存函式的偽碼SHA、原REA Evidence ID與raw SHA逐項核對；沿用原未整函式審核狀態，
沒有改Task owner、catalog、RR或FULL-PASS。原件四段從函式入口解碼、排除padding／switch資料表，
另以獨立PE section映射檢查jump表與訊息表；沒有只看裸數字命中就命名欄位。

使用既有Ghidra附帶Capstone5.0.6 wheel，SHA
`761c3deae00b22ac697081cdae1383bb90659dd0d79387a09cf5bdbb22b17064`，
只解出到本任務outputs的套件副本，不安裝或修改系統。decoder DLL SHA記在收據。
新解碼不是新Ghidra語意分析；REA/Ghidra偽碼沿已保存證據，不重做先前會逾時的原件匯入。

```powershell
python -B kr-extra-roy/SCENARIO-ABANDON-REQUEST-20261124/verify_sources.py --bin E:/Tartaros/workspace/Tartaros.bin --bulk-directory E:/Tartaros/workspace/anal-multi/kr-bulk-roy --capstone-directory E:/Tartaros/workspace/outputs/scenario-abandon-20261124/capstone --output E:/Tartaros/workspace/outputs/scenario-abandon-20261124/native-sources.json
```

驗證器前後核對原件SHA，沒有遊戲執行／附加、Client修改、Lua或原資料夾不明腳本執行。
初版工具假設sender直接call[eax+10]，原件實際取槽到EDX後callEDX；另修正key含NUL長度、
排除函式尾jump表及收據path/hash處理。保留的最終結果重新讀原件，沒有改變遊戲碼配合驗證器。

## Server接續規劃

Server現有005D處理主要回普通狩獵場／大廳。`ReturnToUnpartiedTown`未對主線戰鬥定義取消返村；
不能讓共用離隊先關room、再得到空轉場。後續須接完整主線取消交易與scene生命週期，
不是把0031/0或0043提交清場當退出替代。

- 接受既有005D/00時核對目前租約、唯一隊員／owner、可取消的主線階段，區分原Q15橋接與一般主線。
- 先處理保存中的任務提交，保留已入帳擊倒EXP、已取得物品、已完成主線；未完成通關獎勵不發。
- 取消當代演出、戰鬥、投射物、地面物件與輸入；依既有村莊初始化發布已提交資產與主線游標。
- 明確選定離隊後的村莊／隊伍政策，與首次到村自動私密隊、普通副本離隊政策一致追溯。
- 正常TCP及獨立Host證明取消後無空白場景、可互動NPC、可正常重開未完成主線；
  不把重開單次任務誤稱重登／故障套件。倒地按鍵／owner欄位和指定v2另外保留待驗。

已收到且通過Server身分驗證的既有請求可獨立接此adapter；原生倒地輸入尚未閉合不是所有Server
開發的共同gate。本批只交付來源及具體接線需求，尚未宣稱主線退出實作完成。
