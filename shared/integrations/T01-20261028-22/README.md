# T01-20261028-22｜第三批 10 份原稿 FULL-PASS（僅文件正面、有界主張）

## 驗收定義與限制

本批不重複前兩批 T01-20 與 T01-21 已驗的 20 份原稿。FULL-PASS 的意義僅是：**對該原稿肯定描述且限定於其可直接觀測範圍的全部實質機器碼／資料流主張完成重新確認**。原稿自己列為 unknown、未閉合、外部資源待取的事項不被列成已完成。本批尤其**沒有**證明 Quest16→Quest15 的 server 完整流程、所有 actor dynamic type、runtime 時序。

### 原始來源與審核方法

- 本輪直接唯讀 `/mnt/data/Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。KR PE32 .text VA=0x00401000/raw=0x400，對應公式 `raw=VA-0x00400C00`；.rdata VA=0x00BD2000/raw=0x007D0600。未啟動、修改或重新編譯遊戲。
- 逐份以 GitHub main 原稿全文及 SHA 定位；使用本地原始 BIN raw-byte assertions，**63/63 項原生指令/位元組核對成立**，涵蓋以下十份各至少四項。並重讀 .rdata CMonster 主 vtable 0xC0C9DC 的七個表項。
- 核對過程中的三條**審核腳本手填預期值**誤差已由 objdump 正確指令界線修正後重驗：`0x53FEC8` 才是 `8B 50 14`；`0x4D1749` 是 `C7 07`（EDI），`0x4D174F` 是 `C7 87`（EDI+0xF0），不是 ESI。這三個是審核腳本初稿偏差，不是 GitHub 原稿的反證。更正後所有 63 項一致。
- 本報告不改他人 Task 原稿、不改 catalog 或 owner、不把 byte-scan candidate 擅自當 runtime 可達 CFG。

## 十份原稿逐項 FULL-PASS 裁決

### 1. T16-57 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-57-KR-condition-name-resolution-node-graph.md`](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-57-KR-condition-name-resolution-node-graph.md)
- Git blob SHA：`1a415a61ed27c2e2abc9ff23be1e821f27839c6d`
- **全部肯定主張與資料流範圍**：HasQuest/HasCompletableQuest/HasScenario 的字串 push 和 0x72E2E0 名稱查找，4 個 0x10 間隔輸出槽；不是 quest server writer。
- **第一手證據**：0x53FD84 push 0xC0F4EC、0x53FD92 push 0xC0F4F8、0x53FDA2 push 0xC0F50C；0x72E2E8 讀 [eax+0x18]，0x72E309 走 node+0x40；0x53FDCE 分派子解析；8/8 native checks。
- **ABI／CFG／callers／callees／資料流限制**：具體 XML 來源、output consumer 與 server quest state 均未知。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 2. T16-59 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-59-KR-QuestInfo-QuestTalk-consecutive-readers.md`](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-59-KR-QuestInfo-QuestTalk-consecutive-readers.md)
- Git blob SHA：`f0edc4812ca0d60bfbd35ed00e79d7498d074b67`
- **全部肯定主張與資料流範圍**：相同 EDI 經 0x5043E9、0x5043EF 連續呼叫兩個 reader；0x504740／0x505570 分別用 0xC0DB48／0xC0DB5C 的字串解析入口。
- **第一手證據**：0x5043E5 push edi，0x5043E9 E8→0x504740，0x5043EE push edi，0x5043EF E8→0x505570；0x50478B mov ecx,0xC0DB48，0x5055B8 mov ecx,0xC0DB5C；8/8 checks。
- **ABI／CFG／callers／callees／資料流限制**：QuestInfo id15/16 的具體規則以及 server writer 未證。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 3. T16-61 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md`](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md)
- Git blob SHA：`d8877384dd938cab6421c67fcc62f451d196ccd5`
- **全部肯定主張與資料流範圍**：Lua wrapper 0x4AC9E0 讀 [FE187C] 再呼叫 0x4ACB70，局部轉整數成功/失敗分支透過同一間接 callback；wrapper EAX=1 不是 Quest 成功旗標。
- **第一手證據**：0x4ACA16 8B0D7C18FE00，0x4ACA20 E8→0x4ACB70，0x4ACA28 B801000000，0x4ACB27 / 0x4ACB61 FF55E8；5/5 checks。
- **ABI／CFG／callers／callees／資料流限制**：參數上游合法性、callback writer 的整體 alias、server 成功與封包仍未證。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 4. T16-62 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md`](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md)
- Git blob SHA：`e9b16c654215aa1567cb66571d721c1ab01eea97`
- **全部肯定主張與資料流範圍**：四個可選命名節點的輸出槽、0x53FEB0 查子欄位並經虛呼叫轉送 0x4A8680 的本地解析鏈；不可視為玩家 quest 進度。
- **第一手證據**：0x53FEB0 55 8B EC 51 56 68 A0 F4 C0 00；0x53FEBA E8→0x72E2E0；0x53FEC8 8B 50 14 取 vtable+0x14；0x53FDCE 為輸出槽呼叫；5/5 checks。
- **ABI／CFG／callers／callees／資料流限制**：完整 XML consumer、間接函式動態身分、Quest writer 仍未知。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 5. T16-63 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md`](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md)
- Git blob SHA：`26c595c295093777a7153426a16757b11eacec19`
- **全部肯定主張與資料流範圍**：0x504370 初始化時配置 0xB8 sentinel，依序用同一 EDI 呼叫兩個 reader；是局部初始化流程而非 server persisted quest state。
- **第一手證據**：0x50439F push 0xB8，0x5043E5 push edi，0x5043E9 E8→0x504740，0x5043EF E8→0x505570；4/4 checks。
- **ABI／CFG／callers／callees／資料流限制**：QuestInfo id15/16 XML 原文與角色 server writer 缺。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 6. T16-64 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md`](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md)
- Git blob SHA：`dee3295e7cdde882aae96b277d224160420608c8`
- **全部肯定主張與資料流範圍**：原稿的各項原生局部證據矩陣可復核，且逐條判定『尚不足以閉合 Quest16→Quest15』，沒有宣稱 Quest 完整完成。
- **第一手證據**：0x4ACA16 讀 callback slot，0x4ACA28 回傳 1；0x53FEB0 本地節點 parser；0x5043E9 XML reader；4/4 checks，與 T16-57/59/61/62 交叉相符。
- **ABI／CFG／callers／callees／資料流限制**：T14/T07/T15 server authority、Lua raw、QuestInfo XML 缺，矩陣的『否』保留；不等於 end-to-end Quest 通過。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 7. T16-68 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md`](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md)
- Git blob SHA：`158ceaa7b548c9216e4b14e2dab80f14a6afa0e7`
- **全部肯定主張與資料流範圍**：callback slot [FE187C]=0x4AA4D0；0x4AA4D0 生成 tag 0x40 + 16 bit 值 4-byte buffer，受 [FBA798] gate 控制並虛呼叫 +0x10；原稿僅確認本地鏈。
- **第一手證據**：0x4AB8B8 C7057C18FE00D0A44A00，0x4AA4D4 cmp [FBA798],0，0x4AA4DF mov eax,0x40，0x4AA4F6 mov edx,[edx+0x10]，0x4AA501 call edx；5/5 checks。
- **ABI／CFG／callers／callees／資料流限制**：socket packet/Quest16 complete/Quest15 prerequisites/relogin 都是 unknown，未補成真。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 8. T08-193 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-103715-chatgpt-web-roy-T08-193-cmonster-removal-vtable-precleanup-closure.md`](../../../kr-temp-roy/20261028-103715-chatgpt-web-roy-T08-193-cmonster-removal-vtable-precleanup-closure.md)
- Git blob SHA：`a5b63c691aefc0bb076283d528f8ea4d912eab4f`
- **全部肯定主張與資料流範圍**：**僅 CMonster 主 vptr 條件個案**：0x4D1749 寫主 vptr 0xC0C9DC；.rdata 主表 +0x14 → 0x4D1F80→0x4C8360，+0x00→0x4D18D0→0x4C7B90；128 項資源欄位掃描 EBX=0x80。
- **第一手證據**：0x4D1749 C7 07 DC C9 C0 00；0x4D174F C7 87 F0 00 00 00 64 CA C0 00；.rdata VA 0xC0C9DC +0=0x4D18D0，+0x14=0x4D1F80（raw PE bytes DWORD）；0x4D1F80 E8→0x4C8360；0x4C8397 BB80000000；7/7 checks + vtable DWORDs。
- **ABI／CFG／callers／callees／資料流限制**：不把 lower_bound 當必然 key equality，不外推所有 actor 的 dynamic vptr、resource owner、pool drain。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 9. T08-194 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-194-bulk-clear-virtual-precleanup.md`](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-194-bulk-clear-virtual-precleanup.md)
- Git blob SHA：`ee3ed3098a9a0a4059f99a0430be4ca151f8e8a0`
- **全部肯定主張與資料流範圍**：0x4DFE90 整表掃描逐 actor 執行 vptr+0x14 然後 vptr+0x00(1)，後接 0x823850 tree cleanup 和全域 [FBA7A4] vptr+0x14 callback，與單件 erase 不同；CMonster 僅條件實例。
- **第一手證據**：0x4DFE94 8B5D08、0x4DFEA2 8B7E10、0x4DFEAB 8B5014、0x4DFEB0 FFD2、0x4DFEB6 6A01、0x4DFEBA FFD2、0x4DFF0A E8→0x823850、0x4DFF0F 8B0DA4A7FB00；9/9 checks。
- **ABI／CFG／callers／callees／資料流限制**：不同派生型別、runtime 競態、未知全域 callback 功能仍然 unknown。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


### 10. T08-195 — FULL-PASS（document-scope）
- 原稿：[`kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-195-child-interface-precleanup-abi.md`](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-195-child-interface-precleanup-abi.md)
- Git blob SHA：`90ed8a670620ebe87c6532ebcda881607d410a8f`
- **全部肯定主張與資料流範圍**：0x4C8360 先處理 actor+0x15C 非空次級 interface child+8 的 vptr+0x08，再檢查 actor+0x364 與 actor+0x164 起 128 格引用槽，僅欄位+0x24 非零時呼叫 0x7BE5F0。
- **第一手證據**：0x4C8365 8B875C010000、0x4C836F 8D4808、0x4C8372 8B01、0x4C8374 8B5008、0x4C8377 FFD2；0x4C838C / 0x4C83AF E8→0x7BE5F0；0x4C8397 BB80000000；8/8 checks。
- **ABI／CFG／callers／callees／資料流限制**：三輪原稿清楚保留 child+8 callback 真正 target 與配置型別未知；不能將 ABI 通過升為所有權完備。
- 裁決：`FULL-PASS (bounded positive claims)`；保留原稿所明示 unknown。


## 橫向反證與交接

1. **T16 文書的『證據矩陣』成功驗收不等於 Quest 業務成功**：T16-64、68 本身判定 Quest16 完成、Quest15 可接及重登保存仍無 server/QuestInfo 原文；此 UNKNOWN 內容持續有效。請勿據文件標籤更動 T16 task-level status。
2. **T08-193 actor 移除用的是動態 vtable 條件**：已由具體 CMonster constructor + 原始 .rdata 表取得一種可確認的實作；不論是 registry tree lookup lower_bound/key equality、不同 derived vptr 或更多物件引用來源都不能由此補完。
3. **T08-194 actor cleanup 的雙 vcall 與 0x823850 tree-node cleanup 為不同階段**；最後的 FBA7A4 vcall 尚無業務型別。禁止將其命名為『廣播角色死亡』。
4. **T08-195 8-byte base-adjust**：vptr 來源是 `[child+8]`，不是 actor 主 vptr 或 child 裸指標；其虛函式真正覆寫仍未解，不可稱已追完 child ownership。
5. 其餘未列入本批的 T08/T10/T16 原稿仍待逐份審核；先前 T01-013～018 的 partial 審核不得自動升格。
6. 本次成功記錄的是第三批 **10 份原稿正面主張 FULL-PASS**；自前兩批共累積 30 份不同原稿有 document-scope 驗收報告。此數字**不代表** 30 條遊戲功能鏈全都 native-complete。

## 靜態複核入口

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x53fd70 --stop-address=0x53fe25 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x72e2e0 --stop-address=0x72e31e /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x504370 --stop-address=0x504410 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4aca00 --stop-address=0x4aca3c /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4c8360 --stop-address=0x4c83c0 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4dfe90 --stop-address=0x4dff23 /mnt/data/Tartaros.bin
```
