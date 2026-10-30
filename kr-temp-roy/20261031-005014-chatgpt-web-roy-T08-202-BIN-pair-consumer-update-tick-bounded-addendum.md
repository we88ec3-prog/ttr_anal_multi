# T08-202 原生續證：000A Actor/owner、controller pair 消費與移除次序（仍未完整閉合）

2026-10-31，chatgpt-web roy。KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。BIN-first；.text VA 0x401000/raw 0x400，code raw=VA-0x400C00；RTTI/vtable另以.rdata VA 0xBD2000/raw 0x7D0600讀取。本件**只保存新閉合的有界主張與續查界線，不等於整篇T08-202最終完整版已提交或T01 FULL-PASS**。原交接完整201、202前手草稿及本次121,997-byte含原組語窗口的完整版202均另行保存交付，不能由本遠端增補冒充。

## 1. 000A local owner 與雙WORD pair

`4AF920` 經B+2 DWORD找 owner 次級record，B+6 signed BYTE 為筆數，筆 i 為 `B+7+4i` WORD(idA)，`B+9+4i` WORD(idB)；local-owner由 `404BA0()+5F50` 比對。一般分支寫 Actor+98/+9C，i=0更新 record P+4/+8；但 local-owner 且 idA!=idB 時呼叫 controller vtable+8 -> `5451D0`，將 `WORD idA, WORD idB, DWORD 0` 的 **8 bytes** 加入 `controller+30..38` 向量。不能稱 idB 原本就是 pointer；也不等同 Monster 新增。

## 2. 已閉合 pair 第二輪真正 consumer

交接前在 `545390` 第一pass lookup 即停；此次從原BIN追到 `5452C0` 同函式第二pass `5459B7..545B32`。從每筆pair `[entry+0]` WORD idA 走 Actor 主樹精確查找（`5459FC..545A4E`），若無Actor跳過；載 ActorA+E0 DWORD、+E4 BYTE 及 B0 等欄，取 `[entry+2]` WORD idB，經 controller vtable+0x44 呼叫 `546EF0`。六張已知 vtable +0x44 都指向 `546EF0`。

`546EF0` 按 idB 再找 Actor 主樹（`546F81..546FAC`），與 ActorA 的 +A0/+A4 相對位置求距離/角度，更新第三參數所指 5-byte state record 的 WORD flags(+2)、BYTE(+4)；某些分支還會呼叫 ActorA virtual+0x58。**這是有界 Client 本地狀態 consumer，不可直接解讀為Server授予控制權**。

`545AEB..545B13` 條件成立時將ID與狀態形成每筆5-byte record append至 `FE38D0`，count在 `FE48D0`，`count+5<=0x1000`；`545B38..545B71` 在 count>6 時呼叫 `[FBA854]->vtable+0x10(0, FE38D0, count)`。**沒有追到真正WSASend時不可稱作確定C2S wire**。

## 3. 真正update tick和6種類型之差別

`491CAF call 40F060` owner getter → `491CB6 call 4E0060`；這條caller有 `[edi+0xBFCC]==0` gate；`4E009B mov ecx,[0xFBA7A4]`，`4E00AD mov edx,[eax+0x2C]`，`4E00B0 call edx` 進 controller 派生 update slot+2C，owner+AC 浮點門檻可能先改controller+58。

| 控制器 RTTI / vtable | slot+2C 目標 | 有界影響 |
|---|---|---|
| CController / C0F944 | 5452C0 | pair第二pass與狀態consumer |
| CEmptyController / C0F99C | 8DC2F0 | `xor eax,eax; ret`，不消費pair |
| CMissionRoomController / C0FA6C | 548350 | gate後可call 5452C0 |
| CSingleController / C0FAC4 | 548A90 | gate後可call 5452C0 |
| CTutorialController / C0FB1C | 548CB0 | +4/+DC gating後可call 5452C0 |
| CTagController / BFB5A4 | 444670 | 有條件call 5452C0及派生處理 |

單一路徑並未證明所有mode/所有frame的updater都會執行。

## 4. 哪些路徑清Actor槽、哪些只移除Actor/P record

控制器 `545040` 於controller+0C/+18/+24三槽保存 Actor **raw pointer**，slot+14 的 `545210`／Tag `444910` 清理控制槽及相關pair，但不是獨立的Actor樹free。

- **命令26** `4B2A56..4B2A87`：若key匹配controller的三Actor槽之一，先virtual+0x14一次清槽，再`4B2AC2 →4DFBC0`主樹erase。一般`4DFBC0`只調用三次slot+1C getter，並不自行清三槽。
- **命令81** `4B3710→4DFC90`，由WORD OR 0x06000000形成composite key，按照Actor+88從主樹移除；此已驗window沒有相同的slot+14，亦無P+4/+8直接writer。
- **本地索引16 reset** `4B1A30`：先刪type0 Actor（`4DFD40`），後清controller三槽，清 owner+F8，再`4E1070`清次級P樹；不能稱作全Actor reset。
- **指定次級record移除** `4BBAE0→4DFC30`：釋放P及次級node，不直接析構主樹Actor。

P+4/+8 是**數值欄**，不能直接視為 dangling actor pointer。已核直接 writer：`4C6E50`（0007 producer caller `4AEC83`），與 `4AF920` (000A i0); `4C6EA0` 為 Actor+BC read query 而非P欄清除。已涵蓋caller沒有清P+4/+8，不等於global alias writer不存在；也不證實遊戲runtime bug。

## 5. 202 尚未達標的精確靜態研究問題

1. 反查 record P+4/+8 的 **所有** alias/indirect writer；是否有Actor刪除後另一條清零路？目前只確認指定兩條 producer 及已查erase caller的否定範圍。
2. controller+48 H樹、slot14重建／cleanup、000A其他模式與26/81外層caller的完整關聯。需繼續正常入口CFG、可能callee與所有owner類型；不得因一個consumer突破而停。
3. `[FBA854]->+0x10`後續是否確實進T02 socket/framing與真正wire opcode/domain，尚未證實；把Client待逆向與原版Server規則待開發區分。
4. S00目前未向T08派RR；原版Server生成時機／波次不可由本地索引或事件8猜測。動態收包時序另屬待遊玩驗證。

本檔維持 **T08-202研究中的有界新增證據／未完成**，而非宣稱202已完成。既有T01退回需在正式流程中複驗；未自行改README的NEEDS_FIX或RR狀態。原稿完整附錄與BIN組語窗口見本次本機交付檔 `20261031-005014-chatgpt-web-roy-T08-202-supplemented-bounded-static-evidence.md`（尚非本Git路徑檔）。

## 原生關鍵指令（從 KR PE .text 有效VA對位）
```asm
491caf: e8 ac d3 f7 ff        call 0x40f060
491cb6: e8 a5 e3 04 00        call 0x4e0060
4e009b: 8b 0d a4 a7 fb 00     mov ecx, [0xFBA7A4]
4e00ad: 8b 50 2c              mov edx, [eax+0x2C]
4e00b0: ff d2                 call edx
```
