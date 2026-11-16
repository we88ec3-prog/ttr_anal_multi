# V操作、矩陣row及Server回覆界線

原始BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。核對限定根函式至指令邊界的原生視窗，見[契約](contract.json)與[視窗](row-consumer-windows.txt)。既有bulk只作導航，不升整函式FULL-PASS。

546100@5462B4從selected actor+3E8讀row，push為54F270第二參數；54F2F2將[ebp+C]低byte讀AL，key映射column讀CL，81A8E0以row×11+column取WORD。5480E0亦有actor+3E8路徑；549C60有同欄位fallback，但非所有override/UI分支均已閉合。

[KR/TC資源核對](matrix-resource-findings.json)：兩份CharacterMatrices.xml同SHA78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad。各9角色×7matrix共126組，普通鍵row0/1/2/3填6/6/3/0。Isilia67在row0/col7、69在row1/col7、68同時在row0/1的col8；所有col9為0、row2/3特殊欄皆0。完整242KB矩陣投影保持本機CLIENT/evidence/20261108-charge-matrix-row-audit/matrix-rows.json，不附完整XML或原封裝。

這可證明矩陣有三個非空技能列，但不能從Client推導官方Server對67/68/69的回覆row。兩次短V與長V目前同row2仍屬Server候選；不因row3空就杜撰第四組。ForceState12是FSM，不是row12；motion19不是active68。

54F270先檢測0xC0並略過普通技能查表，所以不能把row2/column8空白當作拒絕長V的理由。v38僅移除此Server過度限制，採per-role emission特殊操作資料，不改短V／長V的row2候選政策。放開依使用者要求回基礎並允許移動。

verify_row_consumers.py --workspace-root E:/Tartaros/workspace可重現選定根函式／原始位元組校驗。初版549D20視窗頭落在指令內被assert拒絕，修正為從函式入口解碼後的549D23才通過。沒有Client執行／附加／修改或新provider操作。
