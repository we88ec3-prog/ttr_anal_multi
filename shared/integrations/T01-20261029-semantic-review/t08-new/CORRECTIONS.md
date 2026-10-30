# T01 自有勘誤：保留原稿版本

驗收日期：2026-10-29 Asia/Taipei。原件 KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE節區及raw映射見 [target.json](target.json)。每一舊稿的完整路徑、Git blob與SHA256見 [return-items.json](return-items.json)。以下為T01的獨立更正結論，不是改寫原作者來源。

## T08-173：局部寫入值是常數1

7B7FD0的第二集合迴圈由7B7FFE `b9 01 00 00 00` 設ECX=1，7B8003讀node+24到EDX，7B8006 `89 4a 44`寫payload+44。迴圈至7B800E沒有改寫ECX，也沒有間接call。因此該路徑不需要依caller決定存入數值。入口是7B7FD0，7B7FA0是前一函式尾端。其他型別/寫入者全集仍未知。原作者T08-177後續已明示這項更正，但173的舊版本維持FAILED。

## T08-183：名稱索引節點不是已證有序樹

7B8680對string key呼叫5525E0，結合index+20 mask與index+24閾值，從index+10 bucket表取8-byte邊界；必要時更新bucket指標後，EDI=&index+4呼叫719B20。下游只修node+0/+4兩條鏈、釋放字串及node、遞減鏈結容器count，沒有有序樹旋轉／顏色或左右子樹資料流。719B90對此node配置0x28，+8為字串，+24為payload，支持hash-bucket/list描述。

這不推翻183的局部順序：7B8129呼叫manager減量，非零跳過；零時才manager cleanup→heap free→index node erase。需要把「樹」這項來源主張改正並保留正常路徑的精確scope。Actor owner+8/+18的RB樹為別的結構，沒有被此勘誤統一改型。

## T08-187：push位置與manager保存位置

從7F6F50實際函式入口解碼：7F6FBA呼叫7B8180取得manager；7F6FBF `6a 30`推配置大小；7F6FC1 `8b f8`保存manager到EDI；7F6FC3呼叫891268配置wrapper。成功後7F6FDB push EDI、7F6FDC acquire，resource返回EAX最後存至wrapper+2C。7F7021是wrapper為NULL分支，還沒呼叫acquire。修正只涉及地址與ABI來源，並不證明全部配置失敗回復或計數平衡。

## T08-196：主樹條件移除與次樹key移除分開

4DFC90以EAX為owner，4DFC96 `8d 78 08`是LEA：EDI=&owner+8，而非EDI=[owner+8]。4DFC99讀[EDI+4]=owner+C sentinel，遍歷主樹，比較payload+88與stack DWORD參數；匹配才虛擬預清理、deleting call、清payload並erase。

owner+18/1C的次樹屬另一個4DFC30，從ESI+18查找8438C0，payload是直接free，沒有actor+14/+0的多型呼叫。故196從「兩條都刪actor、兩棵樹」導出的共享actor／double-free前提不成立；不能以此宣稱原生既有bug或已證同步策略。原作者197提供正確的兩路區分，但196舊版本維持FAILED。

以上四條的完整指令、分支、callee與反例見 [SEMANTIC-EVIDENCE.md](SEMANTIC-EVIDENCE.md)，並非只採幾個byte抽樣。需修正原稿的狀態仍是NEEDS_FIX；後續來源版本及修復影響範圍必須獨立複驗。
