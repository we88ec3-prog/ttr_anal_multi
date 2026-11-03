# S00：廣場主線NPC意圖的原生欄位核對

本輪使用原KR BIN `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
的唯讀PE映射與Capstone5.0.6核對原始bytes。沒有啟動／附加Client或抓包。
[檢查器](../inspect_phindos_npc_intent.py)實際完成5個指令窗口及47項定錨斷言；
[bytes／SHA／全部指令及限制](evidence/S00-20261103-PHINDOS-NPC-INTENT.json)。
這是有限基本區塊及consumer證據，不是544070或5B9340全文語意通過。

## Checkpoint的category與NPC key如何進入I3

544070入口保存checkpoint到ESI；54409E讀WORD+F4、5440A5比較category3。
544127讀WORD+F6並於54412E sign-extend到EDI，544162以此key查500A80。
查詢結果5會進5441E7，其場景mode只容許3／7／23／24，並另經隊伍條件分支。
不是所有category3 NPC都一定進這一條路。

在5442CC分支建立I3，原件可見：

| 原始位址 | 欄位／資料流 |
| --- | --- |
| 5442E5、5442EC | 再讀checkpoint+F6到ECX、+F4到EDX，均sign-extend |
| 544309 | event+10 = F43D9 |
| 544310 | event vtable = C47BE4 |
| 544316 | event+14／field5 = EDI，即NPC key |
| 544319 | event+18／field6 = category |
| 54431C | event+1C／field7 = NPC key |

C47BE4+4指向753B60，getter原件`mov eax,105BF;ret`，
與後述nested consumer要求的型別一致。544334保留event指標供modal helper路線，
5443A5呼叫58B270。完整modal wrapper建構、生命週期及實際回呼傳遞不在本輪閉合範圍；
不把原I3當成可直接交給5B9340的outer事件。

## 確認consumer先本地啟動劇情，再組1C

5B9340選定分支要求outer型別105BD、outer+14值6A7。
5B93A6從outer+18解出nested指標，nested型別須為105BF。
5B93FF取nested+14的NPC key，5B9407查5008B0，
回傳WORD保存在EDI，5B943F／41壓入scene1及該key，5B9447呼叫561760。

此後才組C2S1C：5B945C取nested+18低WORD放body+2；
5B9464取nested+1C低WORD放body+4；5B947D指定6bytes。
既有FBA798非零時不走發送，不能宣稱點擊一定送出。

因此，若該nested物件承接前述I3欄位，NPC10338的source-shaped範例為
`1c 00 03 00 62 28`，兩個欄位是category3與NPC10338，**不是Quest15／scene1**。
這不是抓到的Client封包或官方伺服器序列。
本地561760(key,1)呼叫先於1C發送；不能在收到1C後再次假設尚未啟動第一段。

## Server採用界線

Server可將本地前置已提交、廣場已初始化、角色所有權與自身座標附近的1C/3/10338
列為NPC意圖，再依本連線預期的15/1回報排後續場景。
距離margin3是Server reconciliation選擇，原checkpoint候選radius2保持分開。
0040接受UI狀態與0047(15,2)排程是額外重建策略，並非上述窗口證明的官方應答。

不因1C或3F/value1本身直接完成Quest15、給獎勵、判定Field19勝利或傳送馮德斯村。
本輪沒有遊玩成功、modal完整性或原版相容性驗收，沒有更改既有分析報告／正式規格。
