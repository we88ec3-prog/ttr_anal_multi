# W1 BATCH04 補證：KR BIN 中 Table／Event SceneList 的不同資源路徑

日期 2026-11-02；工作分支 extra/roy1。這是原始 BIN 直接 machine-byte 與 PE 資源字串的限定補證；不執行／修改 Client、不操作 Server，不改 RR／APPROVED，AI/MEF 與連擊不在範圍。

原始 Tartaros.bin 大小 12472320，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。PE .text VA=0x401000/raw=0x400；.rdata VA=0xBD2000/raw=0x7D0600。只對 .text 使用 raw=VA−0x400C00；.rdata 使用自身 section 映射。

## 直接資源字串來源

| BIN file offset | .rdata VA | 原生 NUL 結尾字串 |
|---|---|---|
| 0x8018C8 | 0xC032C8 | Table/SceneList.xml |
| 0x80EC68 | 0xC10668 | Event/SceneList.xml |
| 0x80ECD0 | 0xC106D0 | Event/Sequences/ |
| 0x80ECE4 | 0xC106E4 | .seq |

## 精確指令位址與機器碼

| 程式碼 VA | 原始 bytes | 限定行為 |
|---|---|---|
| 0x47DE85 | B9 C8 32 C0 00 | MOV ECX,0xC032C8；Table SceneList path |
| 0x47DE8A | E8 A1 0F 2B 00 | CALL 0x72EE30 |
| 0x47DEBC | E8 4F 12 2B 00 | CALL 0x72F110，接續 Table 路徑物件 |
| 0x560815 | B9 68 06 C1 00 | MOV ECX,0xC10668；Event SceneList path |
| 0x56081A | E8 11 E6 1C 00 | CALL 0x72EE30 |
| 0x560845 | E8 C6 E8 1C 00 | CALL 0x72F110，接續 Event 路徑物件 |
| 0x56084A | 84 C0 | TEST AL,AL |
| 0x56084C | 0F 84 D4 01 00 00 | JE 0x560A26（helper 返回零） |
| 0x561A8D | 68 D0 06 C1 00 | PUSH 0xC106D0；Event/Sequences/ |
| 0x561ACB | 68 E4 06 C1 00 | PUSH 0xC106E4；.seq 後綴 |
| 0x56592E | 68 D0 06 C1 00 | 另一路亦引用 Event/Sequences/ |

## 資料流及界線

限定可證：原始 Client 有 Table/SceneList.xml 與 Event/SceneList.xml **兩個不同字串**，它們在各自代碼片段成為 path helper 參數；Event 片段在 0x560845 後測試返回值是否為零。另有對 Event/Sequences/ 與 .seq 字面值的字串組合呼叫。0x72EE30 初始化含傳入路徑的物件，0x72F110 對路徑/資源物件做後續操作。這不是完全確定載入成功、解析 XML 及場景播放因果的全文驗證。

上傳 SceneList.xml 長 158269、SHA256 8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25，與 Event/SceneList.xml 在 Event.stp EX v1 宣告的 decodedLength 158269 一致，且 W1 35/35 筆 Scene 與 Event.stp TTEX .seq 原始函式標頭及 MD5 完整吻合。Table/SceneList.xml 在 Table.stp EX 宣告的 decodedLength 則為 65494。**這些不是對加密/壓縮 EX 本身解密後的逐位元組同一性證明**。

可供 S00 版本鎖定的資料是 (questIdx,sceneIdx)→funcName 的 DRAFT 劇情資源映射。不可把這些 Scene keys、endBehavior=0、演出座標、OpenTalkScene 或 DoProlog 當作 Quest 已接受、已合法結算、Reward 發放、存檔成功、可直接世界 spawn。Quest132/5 使用 town002D.fld 只是 Town2 演出橋接，不能代替 Quest132 結算及 Quest133 開放的受信條件。

後續 Client 靜態待查：0x56084A 雙分支、SceneList XML key 解析器及 Event/Sequences 實際 lookup、Quest 主線 C2S 觸發/S2C consumer、6F 完整 snapshot 與 74 增量、Reward type2/3/4 真正 consumer。Server 授權／事務保存由 S00 另設計；T01 逐主張複核，不升格全文 FULL-PASS。
