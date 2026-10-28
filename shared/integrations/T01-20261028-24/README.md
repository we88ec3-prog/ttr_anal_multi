# T01-20261028-24：第五批原稿主張限定驗收（10 份）

> **重要狀態區別**：以下的 FULL-PASS 是原稿中**已明確證實的有界技術／來源稽核主張**之逐項覆核。對於只引述 T01 稽核原件的 SHA／XML root/prototype 記錄，標註為 **A 級二手 manifest record verification**，而非本輪直接重解未提供的 STP。對於原始 BIN 位元組／call/xref，標為 **B 級本輪第一手**。這並非 ten task-level native_complete，也不能將缺少的官方 Quest16→Quest15 server state 證據當成已解。若 FULL-PASS 定義須獨立重驗原始 STP 內所有 resource bytes，本批的 A 級部分必須另行重驗、不能當作 S 級。

## 來源與檢查步驟

- 原件唯讀：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，均本地以 SHA256 實際重核。
- KR .text VA 0x401000/raw 0x400，因此 .text VA → raw = VA - 0x400C00；其它區段獨立映射。
- 對每份原稿至少 3 項確認位址、opcode、資料指標或直接 E8 下游；Python `/mnt/data/t01_batch5_checks.py` 共 **40/40 raw-byte asserts passed**。另外獨立全 .text bytes 重掃 E8 call candidate：`0x504740=1`、`0x505570=1`、`0x6F4A50=15`、`0x6F4DD0=3`，呼叫點數量及集合與 T16-56 一致。所有 raw E8 scan 僅聲稱 byte candidate，非已證 CFG boundary。
- GitHub `main` 十份原稿全部重新 fetch，其 blob SHA 與 T01-07 索引比對 10/10 一致。另讀 `shared/integrations/T01-20261028-06/resource-source-audit.json`、`pending.json` 與 `NEXT-QUERIES.md`；這些記錄支持 A 級來源資料／待查的存在，而不能取代資源二進位正文。
- KR 原始 KeyMapping 的可讀證據檔 `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt` 亦已對 Type0/Type1 字面配置交叉閱讀。對 10 份不重複 T01-20/21/22/23 的 40 份。
- **排除未通過候選** T08-196（第二索引 owner 偏移需釐清）與 T08-200（lower_bound 不保證 key equality）仍未 FULL-PASS，本批不計數。對這些不能因本批其他原稿通過就自動升級。

## 十份原稿逐項裁決

### 1. T10-081 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md](../../../kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md)
- **Git blob SHA**：`882743a9197fff2a5a1d7c189c5d301c8a9da8a4`
- **本份所有有界的肯定主張及精確分級**：可讀 KR KeyMapping 基本表 Type0 與 Type1 中 Key/MapButton/ModKey 的原始 XML 字面對應；Extra 使用 105xx/110xx 不同 ID domain；原始載入入口位址成立。
- **交叉證據**：原始正式 kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt：Type0 MapButton 13–16=Key 44–47/ModKey0；Type1 另有 10/11/12=44/46/47；0x6D08F0=55；0x6D4DE8=8B450C、0x6D4DEB=8B5D08。
- **不能升格的限制**：DIK Z/X/C/V 只是慣例；實際輸入 producer、目前玩家設定與完整 runtime keyboard semantics 未知。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 2. T16-41 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md)
- **Git blob SHA**：`709dc7206d8ef70024a2f77de79d86ce3c557cc7`
- **本份所有有界的肯定主張及精確分級**：這是 T01 來源稽核對 Lua 成員存在、來源 SHA、封裝 offset 與保存的 Lua 靜態驗證資訊的**A 級引用**；原稿明言不是本輪重解 Lua 函式。BIN script bridge 入口存在。
- **交叉證據**：resource-source-audit.json: TutorialBase SHA 26e5fe… raw 10645520 size1416；TutorialMain SHA 662f84… raw10647568 size5480；原始 BIN 0x4A89C0、0x4A8A60、0x6F4A50、0x6F4DD0 均有 x86 55 8B EC 入口。
- **不能升格的限制**：A級 manifest 引用不等於本批獨立開啟原始 Lua bytecode；協程成功判定、server writer 全為 U。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 3. T16-42 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md)
- **Git blob SHA**：`97773d959e623df88dec3a4506ebd83c8ac9c115`
- **本份所有有界的肯定主張及精確分級**：QuestInfo/QuestTalk/ScenarioBookContents 的 SHA、XML 根節點與 children 數量是從 T01 來源稽核 record 引用；QuestInfo/QuestTalk 有不同本地 reader 入口與路徑常數。
- **交叉證據**：source-audit.json 保存 QuestInfo 4798/QuestTalk 4322/ScenarioBook 426 根 children 記錄；KR BIN 0x50478B=B9 48 DB C0 00；0x5055B8=B9 5C DB C0 00；0x5043E9/0x5043EF E8 targets 正確。
- **不能升格的限制**：children!=唯一任務數；本批未讀完整 QuestInfo XML，不證 Quest15/16 ID、NPC、前置條件。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 4. T16-43 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md)
- **Git blob SHA**：`2feafd823d0de32ec1b2503df9fa2a9c2b3c1856`
- **本份所有有界的肯定主張及精確分級**：驗證其本質是『逐箭頭缺口清單』：T01 pending 和 NEXT-QUERIES 實際列出 scenario14→TUTO、Quest16→Quest15、角色/帳號恢復缺口；BIN 裡確有 Lua loader、命名 Quest 節點，原稿沒有把這些當後端完成。
- **交叉證據**：pending.json backend_gaps 三筆原文一致；NEXT-QUERIES.md 主題一致；0x4A8A60=55 8B EC；0x53FD84 push HasQuest 位址；0x53FD92 push HasCompletableQuest 位址。
- **不能升格的限制**：並未驗證假設 A/B/C 的真實性；T14/T07/T15 server-side 行為仍 unknown。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 5. T16-49 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md)
- **Git blob SHA**：`0df285c934581b93bb2339320a2c8a6e69772675`
- **本份所有有界的肯定主張及精確分級**：PE 段資訊、七個 native 入口位址與檔案版本定錨；資源 SHA 是 T01 audit metadata 而非本機重新解包。
- **交叉證據**：KR BIN sha256 9741d197…、EXE 03771b8e…；0x4A89C0、0x4A8A60、0x4A8B90、0x504740、0x505570、0x6F4A50、0x6F4DD0 均取原始 bytes 確認 55 8B EC；.text/.rdata/.data/.rsrc section 來源符合 PE。
- **不能升格的限制**：不宣稱取得或執行 Table.stp/Event.stp；Quest15/16 欄位與 server persist unknown。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 6. T16-50 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md)
- **Git blob SHA**：`bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564`
- **本份所有有界的肯定主張及精確分級**：可重現的 Lua loader 0x6F4A50 有本地字串拷貝、後續 0x714770 call／非零分支，0x6F4DD0 是另一獨立命名查找入口；原稿明言僅局部線性 ASM，不是完整協程 CFG。
- **交叉證據**：0x6F4A50 55 8B EC 83 E4 F8；0x6F4A80 8A 08（讀一 byte）；0x6F4A99 E8 D2 FC 01 00→0x714770；0x6F4DD0 55 8B EC。
- **不能升格的限制**：未追完 LuaVM 每一條返值與所有間接虛函式實作，不由 client bridge 推出 server 成功。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 7. T16-51 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md)
- **Git blob SHA**：`d6591307065c066485ec3e312aafe69b38c72448`
- **本份所有有界的肯定主張及精確分級**：QuestInfo 候選 reader 0x504740 與 QuestTalk 0x505570 是不同函式，分別使用不同具名資源路徑常數、下游 0x72EE30；原稿自己明確是 local resource read，不是 Quest completed server writer。
- **交叉證據**：0x504740、0x505570 入口 55 8B EC 83 E4 F8；0x50478B=B9 48 DB C0 00；0x5055B8=B9 5C DB C0 00；0x5043E9→0x504740、0x5043EF→0x505570。
- **不能升格的限制**：沒有完整 QuestInfo id15/16，不能判定 prerequisite 或 NPC；不外推 persisted quest state。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 8. T16-52 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md)
- **Git blob SHA**：`84e4f83eff35ed0c0da23880fe54553bd065b2ef`
- **本份所有有界的肯定主張及精確分級**：端到端矩陣的局部肯定內容為『客戶端存在 Lua loader、兩個 reader』；server authority 與 mission14/Quest15/16 全都被明確列為 unknown 而非已實作。
- **交叉證據**：0x4A8A60 native 55 8B EC；0x5043E9 call 0x504740、0x5043EF call 0x505570；T01-06 pending.json 真有 scenario14/Quest16→Quest15/relogin 缺口條目。
- **不能升格的限制**：Quest 16 completed/Quest 15 available 不作任何正面成功宣稱；此份屬證據缺口交接文件。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 9. T16-56 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md)
- **Git blob SHA**：`f6c7a0bb219c11c561e6463a7ae121bf6a41b4f2`
- **本份所有有界的肯定主張及精確分級**：對四個 native 函式的全部 E8 rel32 raw-byte 候選集合完全重掃：0x504740 一處、0x505570 一處、0x6F4A50 十五處、0x6F4DD0 三處；與原稿逐址完全一致，且原稿明言不等於 CFG 可達。
- **交叉證據**：全段 .text raw scan: 0x504740 ←0x5043E9；0x505570 ←0x5043EF；0x6F4A50 ←0x48B11D/12C/13B,0x48CA11/4D,0x4A89B6,0x4A8A36,0x4A8B64,0x55D7C2,0x560796/A2/AE/BA,0x561C7D,0x5659D9；0x6F4DD0 ←0x4A8A46,0x4A8B74,0x5615D8。
- **不能升格的限制**：raw byte hit 不是指令邊界證明，Lua scenario 與官方 Server 狀態全都 unknown。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


### 10. T16-60 — FULL-PASS（原稿肯定主張限定）
- **原稿**：[kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md)
- **Git blob SHA**：`b91b766bbfd2272dae446c428c600ccaeaec1fa7`
- **本份所有有界的肯定主張及精確分級**：跨 T16-57/58/59 的**有界證據矩陣**：HasQuest 等是本地命名節點查找線索，RequestStartScenario 存在 native 函式註冊，兩個 reader 同 caller，均不代表 Quest16 官方完成。
- **交叉證據**：0x53FD84/92/A2 三組 push 地址；0x4AB8F8 push 0xD6AD68；0x4AB909 push 0x4AC9E0；0x5043E9/EF 連續 reader calls；本次 BIN byte checks all matched。
- **不能升格的限制**：Lua request 參數是否 scenario14、Server 成功 ACK、Quest15 可接及重登狀態均是未解；不把跨文檔摘要當成完整實作。
- **裁決**：有界正面主張與所引用來源／原生位址相符；文件列出的 unknown 不被宣告解決。


## 最重要的交接限制

- 這十份涵蓋 **resource source-audit、Lua loader、Quest reader、server authority 不足的證據契約**；並不是十個已完成的遊戲功能。來源稽核 T01-06 的 manifest 是 A 級證據，獨立重解原始 Event.stp／Table.stp 不在本輪執行證據中。
- Quest16 已完成、Quest15 可接、scenario14 勝利、Quest/角色狀態寫入及重登恢復，沒有本輪可直接支援的正面原生／server 證據，全部保留 UNKNOWN。沒有修改任何原稿、owner、catalog、client 或 Task-level status。
- 前四批 document-scope 報告列 40 份不重複；此批新增十份，合計 **50 份 document-scope 的有界主張驗收紀錄**。這個數字**不代表 50 份完整可實作的 end-to-end 原生遊戲鏈**。
- 後續應先補真正 STP、QuestInfo id15/16、Lua raw chunk 及 server request/reply/persistence 來源；T08 的雙樹 payload 共享或重複 key 問題不能繞過原生同一性證據。

## 重驗命令

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
python /mnt/data/t01_batch5_checks.py
objdump -d -Mintel --start-address=0x6f4a50 --stop-address=0x6f4bb8 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x5043e0 --stop-address=0x504400 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x53fd70 --stop-address=0x53fdb0 /mnt/data/Tartaros.bin
```
