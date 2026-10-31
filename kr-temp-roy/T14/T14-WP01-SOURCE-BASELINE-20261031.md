# T14-WP01 — KR 原始資料、歷史主張與 T01 更正的可信基線

- 日期：2026-10-31 18:49 Asia/Taipei（分析資料起始檢查時段）
- Repo：`we88ec3-prog/ttr_anal_multi»
- 工作分支：`t14/roy/chatgpt-web»；本文件只屬 T14
- 研究基準：`main = t14/roy/chatgpt-web = f6eeef02dfa3704aabb45349718cc9da4b35fbe0»，compare `ahead=0, behind=0»（建立本次報告前）
- 工作包：`WP01-01»～`WP01-04»
- 性質：**來源與機器碼局部核對／追溯矩陣；不是 WP02～WP08 研究完成、原版 Server 邏輯認證、T01 FULL-PASS 或實際可玩測試。**
- 動作：唯讀原件和 GitHub；**未執行、附加、patch 原版 Client，未發送封包，未修改 Server 或任何其他 Task 的工作檔案**。

## A. 本次工作範圍、完成判準和結果

| 子項 | 本次作業 | 結果與界線 |
| --- | --- | --- |
| WP01-01 | 查目前 main 與工作分支、T14 README/task.json、AGENTS、派工制度、RR 台帳；列出原件／既存證據入口 | **完成來源盤點**。T14 owner=roy、`state=analysis-paused-by-user»、`analysis_paused_by_user=true»、`native_complete=false»；本次指定 WP01 只授權此基線研究，不擅自重寫 Task 狀態。T14 KR RR 尚無派工；README 沒有具體 NEEDS_FIX/FIXING 退回明細。 |
| WP01-02 | 原始 BIN／EXE SHA256、PE32 架構及 section VA/raw 對應，至少抽原生關鍵入口作 bytes/指令直接核對 | **完成版本與映射及定向 bytes 檢查**；尚非所有函式完整語意驗收。 |
| WP01-03 | 核對 T01 20261027-03／04、20261028-06 與限定主張、更正及共用 FULL-PASS 政策 | **完成 T14 相關限定主張與衝突／不能升格項目矩陣**。前兩批收件有 T14 專屬主張；更多 T07/T16 成果只能有界引用。 |
| WP01-04 | 將 HP0＋0.75 秒、預標 scenario14/16、模擬回包與真實 Client 收發分層 | **完成分類及禁用規則**；本工作包不反向猜測真正勝利門檻。 |

### 唯一任務狀態、RR 和原始交接的界線

- 在起始 `f6eeef0»，`kr/tasks/T14/task.json» 列 owner `roy»、狀態 `analysis-paused-by-user»、原生完成 `false»；`dependencies = T02, T07, T08, T12, T15»。
- `research/dispatch/inbox/T14.md» 為唯讀生成收件箱，文字表示無待處理 S00 研究請求。從本輪解析 `research/requests/index.json» 的「KR、owner_task=T14」篩選亦得 **0 項**；不建立虛構 RR ID、不修改收件箱、不自行標記 CLAIMED／SUBMITTED／ACCEPTED。
- 本次使用者明確要求完成 WP01 並提交至 T14 分支，因此可進行唯讀來源基線調查；這不等於擴大 WP02～08、接受歷史報告所有語意，亦不授權修改主線。
- 已檢閱 `AGENTS.md»、`HANDOFF.md»、`shared/CLIENT-MODIFICATION-POLICY.md» 與 Project `02-PROJECT-SHARED-INSTRUCTIONS.md»；以原始 Client 封包／資源為恢復目標，不用修補 Client 跳過不明判定。

## B. WP01-02：本地原件身份與 PE 直接驗證

本地唯讀原件的 SHA256 是從實際檔案重新計算，而非取舊報告聲稱：

| 項目 | BIN（主要 KR Client 靜態來源） | EXE（另行辨識） |
| --- | --- | --- |
| 檔案 | `Tartaros.bin» | `Tartaros.exe» |
| bytes | 12,472,320 | 2,594,816 |
| SHA256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91» | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f» |
| PE magic／Machine | PE32 / `0x14C» (i386) | PE32 / `0x14C» (i386) |
| ImageBase | `0x00400000» | `0x00400000» |
| PE header raw | `0x120» | `0xF8» |
| Sections | 4 | 4 |
| SizeOfImage | `0x00C44000» | `0x00280000» |

BIN 的 PE section 表（`VA = ImageBase + RVA»）：

| Section | VA 起點 | Raw 起點 | VirtualSize | SizeOfRawData |
| --- | --- | --- | --- | --- |
| .text | `0x00401000» | `0x00000400» | `0x007D01F0» | `0x007D0200» |
| .rdata | `0x00BD2000» | `0x007D0600» | `0x0018E07C» | `0x0018E200» |
| .data | `0x00D61000» | `0x0095E800» | `0x002873D8» | `0x0022B800» |
| .rsrc | `0x00FE9000» | `0x00B8A000» | `0x0005AF58» | `0x0005B000» |

EXE 的 RVA/raw 不能與 BIN 混用：其 .text `RVA=0x1000 raw=0x400 size=0xC5600»、.rdata `RVA=0xC7000 raw=0xC5A00»、.data `RVA=0xE9000 raw=0xE6C00»、.rsrc `RVA=0xF2000 raw=0xEBC00»。BIN `.text» 中此版本地址的映射式為：

`raw_offset = VA - 0x00401000 + 0x00000400»

**反例**：將 `raw=VA-0x401000» 直接代入而漏加 `0x400» 會偏移 0x400 bytes；不能對其他 section、indirect ptr 或所有已存反編譯地址執行未核對的一律平移。T01 20261027-04 已記載 T08 PE 與 flat 視角的映射衝突，相關人員各自保留其原始證據。

隨附使用者提供之資源 carrier 也實際核對 SHA（只證同一份 carrier，不證原始廠商發行版本、展開成員正確性或執行效果）：

- `Event.stp»: 11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b»；與封存 T14 報告所列 carrier SHA 一致。
- `Table.stp»: 5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442»；與封存的 T07 result/table carrier 記載一致。
- 本輪沒有直接把 STP 內容當作已驗證的 Quest/Scenario/Reward 表格原文；成員抽取與可信版本鏈仍待個別證明。

### 最小原始組語重驗（從當前 BIN，非複製反編譯）

使用唯讀原件、PE raw 映射抽出指定 bytes，再以 x86 32-bit objdump 獨立解碼。本次只核對下面的**有限指令窗**，不聲稱完整函式 CFG、所有 caller/consumer 或完整 wire frame 已驗證。

1. **TUTO S→C 004C 關聯的 handler 局部 writer**。`VA 0x004C4F72», `raw 0x000C4372»（相鄰入口 `0x4C4F20 raw 0xC4320»）。原 bytes：

`8b 45 08 0f b7 48 02 8d 55 08 b8 88 0f fc 00 89 4d 08 e8 f7 d8 ff ff c7 00 01 00 00 00 33 c0»

`» 
`0x4C4F72 mov eax, [ebp+8]»
`0x4C4F75 movzx ecx, word ptr [eax+2]»
`0x4C4F7C mov eax, 0xFC0F88»
`0x4C4F84 call 0x4C2880»
`0x4C4F89 mov dword ptr [eax], 1»
`0x4C4F8F xor eax, eax»

**原件確證的有限事實**：傳入 message 的 +2 WORD 經 zero-extend 作 map key，透過 `0x4C2880» 取得儲存位置，然後寫入 DWORD 1。這段指令本身沒有檢查怪物總數、0.75 秒 timer 或獎勵欄位；**不能據此宣稱整個 Client／Server 沒有其他判定**。callback 安裝位置與完整 S→C framing 仍須引用 T07／T02 來源追溯。

2. **查 map 的局部 reader**。`VA 0x004AA510 raw 0x000A9910»，bytes：

`55 8b ec 8d 41 04 8d 55 08 e8 62 83 01 00 8b 00 5d c2 04 00»

反組譯 `lea eax,[ecx+4] → call 0x4C2880 → mov eax,[eax] → ret 4»。此窗足以證 map accessor 的回傳讀取，不直接證完整 Lua adapter 的值域或原版勝利條件；已有 T14 封存來源把缺項插入 0、FE1804 binding 與初始化清除鏈列為**有界結論**。

3. **開始 Scenario 的本機 4-byte sender**。`VA 0x004AA4D0 raw 0x000A98D0»，bytes 中含 `66 8b 4d 08 b8 40 00 00 00 66 89 45 fc 66 89 4d fe»、`push 4»、`call edx»；它裝入 WORD `0x0040» 與 argument WORD。**只證局部 builder／虛擬 call candidate**；不能把此視為「發完 0040 就必定得到 004C/14」的原版 Server 契約。

4. **結果畫面返回 C→S candidate**。`VA 0x004A38D0 raw 0x000A2CD0»，bytes 含 `b8 33 00 00 00 66 89 45 fe»、`push 2» 與 virtual `call edx»；這是使用 WORD `0x0033» 的 2-byte buffer 送出路徑。**完整 socket/framing 與按鈕 gate**仍依 T02、T07 已有限定來源；不等同獎勵確認或結果許可。

## C. WP01-01：T14 正式與歷史來源索引

1. **正式權威入口**：`kr/tasks/T14/{README.md,task.json}»；T01 接收索引 `shared/integrations/T01-20261027-03/»、`T01-20261027-04/»、`T01-20261028-06/»，尤其 `accepted-claims.json»、`resolutions.json»、`pending.json»。
2. **實際仍可存取的封存正文**：「T14 roy：scenario14 完成與教學 Lua 接續」位於 `kr/evidence/1d78642bfec7b5005988a1c2121404a3daadd2f62ba1e0068f8918b314b1ae99.txt»，Git blob `909cd378dbe0283355924358d3087c88ff7b49a3»。定向原生 bytes 原稿在 `kr/evidence/4588fb3ec2f797c4231f0797c68b22a249ab8541d77d5bd48e7d61c23d6f779d.txt»，Git blob `603357b26291eb8af7cee4f07d3e3c55914fe2d7»。後續未知清單 `kr/evidence/40ae4d7e83b591ee48377548309a2a5bee47eeb39f70264789beb8641e8d9b95.txt»。
3. **跨任務結果資料**：T07 一般 Scenario 0022/type0、0033 返回原稿封存在 `kr/evidence/00c7ff83c85dd8f01e882d82bf2d83fcf6eed2788d3fd60dbd69682b2764d977.txt»，Git blob `9e53daa87621ddfa8c1dda72490f83c129b71d8»；相關限定主張以 T01 20261027-04 為準。
4. **歷史路徑的可攜性缺口**：舊主張的原 `kr-temp-roy/T14/T14-SCENARIO14-CONTRACT.md»、`kr-temp-roy/T14/unknowns.md»、`kr-temp-roy/T14/evidence/flag-native-bytes-v1.json» 等作為 `source_paths» 可追溯文字，**目前 GitHub main 對這些精確路徑直接 GET 為 404**；不能假稱原路徑全文已在 repository 中。必要正文應改按 `kr/evidence/<SHA>.txt» 與精確 T01 收據查找，原稿缺段仍須追補。本 Task `task.json» 有 139 筆 evidence_id 及 171 筆 unresolved dependency（後者是歷史引用/缺口登記，**不等於 171 個獨立未分析的函式**）。
5. **README 所列 25 個明示證據連結**如下。已逐一使用 GitHub contents API 確認其至少可取得第一行與 Git blob metadata；這證明檔案存在，**不等於 25 份全文讀完或全部原生已驗證**。

| # | 原索引標題 | 本版 GitHub 固定 SHA 下之證據位置 |
| ---: | --- | --- |
| 01 | SCENE-ENTRY-RESET-AND-READY.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/0bab714e82d96b0f6a4165471fc52531ba4b250f63878e2721bdd706fb8bab37.txt) |
| 02 | QUEST-STATE-NOTIFICATIONS.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/0ef1b842dc4d34ce8bda1944d6556f00862febd2ec98393030ac1518b55d3c22.txt) |
| 03 | tutorial_skill_cast.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt) |
| 04 | tutorial_monster_config.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt) |
| 05 | native-index/quest-state-notifications-audit.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/196ab5cb1f9951b7a2daa1aae318890a04ed9759ffb4748f3cf04132d83cb624.txt) |
| 06 | kr-boundaries-20261022/boundary-records.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt) |
| 07 | tutorial-native-skills-v19.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt) |
| 08 | native-index/scene-controller-audit.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/2d9e26e98fd3c87bff2a1cc8cea2621a445479a2496487499f6e69aac8264fd6.txt) |
| 09 | login_protocol.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt) |
| 10 | MAINLINE-FLOW.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/unclassified/evidence/3a6376c5d84b4f03edc301d4467746680dfa448efb1df1eb5d2c20e278a20690.txt) |
| 11 | 48-tutorial-battle-fixture.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/unclassified/evidence/43aa311555dd6ad2e6843224cf710036c07b390942f7836b58ae9c80de587e59.txt) |
| 12 | account_store.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt) |
| 13 | audit_quest_followup_delivery.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/5160a9ec0027ef0958184177a63ee24c3566b9bec98f3e4adc9ecdabb133a3a1.txt) |
| 14 | MAIN-PROGRAM-FUNCTION-MAP.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt) |
| 15 | new_expedition.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt) |
| 16 | kr-boundaries-20261022/slot-dispositions.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt) |
| 17 | plaza_npcs.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/9a9e396000323e0b7359afeb933922ce3ff40b50a4dedd982ed752b2fe228e49.txt) |
| 18 | NATIVE-BEHAVIOR-MAP.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt) |
| 19 | native-index/method-atlas/summary.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt) |
| 20 | QUEST-FOLLOWUP-DELIVERY.md | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/bff92f470c840f7737652274ebcaaa36aa06c16b9f85e09cd1d1847ea9428be3.txt) |
| 21 | native-index/quest-followup-delivery-audit.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/c0979f6864b1ac8bc5d9844f39c69e04b7587ef0597914c0c04898f65577762b.txt) |
| 22 | audit_quest_state_notifications.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/c297785536d52b20ca6ac0a9ed288520d54ebb864b09c07790089262293ac301.txt) |
| 23 | tutorial_battle.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt) |
| 24 | kr-unified-ledger-20261023/catalog.json | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt) |
| 25 | audit_scene_controllers.py | [GitHub](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/fd26185a16f71126adee2347d1bb9a14152c42669955dc8ad46556d460f3f7c1.txt) |

分類警示：名為 `tutorial_battle.py»、`new_expedition.py»、`login_protocol.py» 等由來源路徑明示為 Python 檔，乃舊本機程式／fixture／稽核線索；只有完成逐一原始證據交叉比對之**精確主張**可作 Client 論據。`unclassified/evidence/» 不可自動標為 KR native。資料來源補證優先鎖定 T14 直接關聯的 004C、0022/0033、Quest 狀態及其 BIN/rules，而不是為數量重新盤點整個遊戲。

## D. WP01-03：T01 限定成果與後續更正矩陣

### 1. T14 名義下已登記的限定主張（逐條從 20261027-03／04 對照）

| 主張 ID | 原登記狀態 | 可引用的有限結論／限制 |
| --- | --- | --- |
| kr-T14-T01-20261027-scenario-flag-writer | 原生已確認 | TUTO的004C/4C4F20讀unsigned WORD body+2，在同一完成項map寫DWORD1並return0；已讀下限4 bytes。handler未直接判怪物數、timer、reward或resume Lua，不可當成已證官方勝利判定。 |
| kr-T14-T01-20261027-same-map-and-reset | 原生已確認 | getter缺項插入0；Lua adapter回number而非boolean。FE1804綁定FC0F84時，reader this+4與writer FC0F88是同map；TUTO init會清此map。RequestStartScenario直接sender沒有flag reset，不能與init清除或exit移除thread混同。 |
| kr-T14-T01-20261027-current-lua-gates | 部分確認 | 當前boot FALSE是number0；Tutorial_Part2 PC20..29等IsScenarioEnded(14)==FALSE，通過後為UI／checkpoint10016／yield／1000,10／1000,12，再招募4。這是帶SHA的現用Lua快照觀察，未認證pristine KR腳本，也不表示已執行後續。 |
| kr-T14-T01-20261027-quest-opcode-domains | 部分確認 | QuestMgr5020B0把5030C0登記到FAB5C4；相對FAB2A0按opcode*8+4計算為0064，而非教學TUTO的004C。15/1開場結束不能因此發完成或獎勵，改opcode也不會補齊達成條件。 |
| kr-T14-T01-20261027-quest15-acceptance | 部分確認 | 對已核SHA的Quest15定義，無AcceptAction且loader預設0；0040/15/result0可同步進行中狀態而不代表完成或獎勵。直接與延後NPC路由須分開；15/1→第二段15/2→無預選自由編隊→Field19的完整觸發仍未閉合，不能沿用第一戰固定leader／容量1。 |
| kr-T14-T01-20261027-official-objective-gap | 資訊缺失 | 官方14／16／15達標輸入、獎勵、exactly-once、持久化及正常副本／村落往返仍缺；同map重寫flag1的值冪等不等於交易或獎勵去重。舊HP0後0.75秒或預標14/16仍屬fixture。 |
| kr-T14-T01-20261027-reconstruction-work | 待補充開發 | 需要在後續獲准工作中補scenario/scene世代、官方或明示重建達標來源、reset後重綁、防重與獎勵／保存政策；本輪只整合已有分析，不啟動服務、改Server或恢復使用者已暫停的T14分析階段。 |
| kr-T14-T01-20261027-04-official-end-to-end-gap | 資訊缺失 | 004E ID來源、0038+5、官方達成／發獎、15/3時機、村落合法位置與反覆旅行仍未閉合；本輪不建立可玩Server、不恢復本對話未授權的T14新分析。 |

**注意**：表格的「原生已確認」是當時 T01 來源限定分類，不是最新版 T01 嚴格的全文 `FULL-PASS»；上表各條須連同 `conditions»、`limitations»、來源 SHA 及後續 corrections 讀取。現有 `shared/verified-knowledge/README.md» 未見 T14 整體關卡／勝敗／獎勵已 FULL-PASS 的項目；不能把「未列入該索引」反推原版完全不存在功能。

### 2. 跨 Task 重要有界介面（非 T14 owner 移交）

| 來源 | 有界情報 | 絕不可推論為 |
| --- | --- | --- |
| T07、T01-20261027-04 `kr-T07-T01-20261027-04-result22» | 一般 Scenario 的 `S2C 0022/type0» 會建立 `CScenarioDecision» 並導入結果場景；state8 結果 UI 不等 state7 場景。讀取下限 22 bytes。 | 原版完整結果 payload、勝利時間點、獎勵或統計所有欄位。 |
| T07 `kr-T07-T01-20261027-04-return33» | 結果按鈕 payload+9 為0可走直接 2-byte `C2S0033»；非0角色索引及非mode1確認還有分支。 | 所有返回鍵都能直接發0033、角色說明等同領獎、官方指定返回座標。 |
| T14/T07 `C-T01-20261027-03-quest-opcode» | QuestMgr `0x5030C0» 登記派發為 `0064»，不能混作 TUTO `004C»。 | 只因看到 Quest15/1 就認定 Quest15 完成。 |
| T07/T14 `C-T01-20261027-04-story-opcode» | `0047» 與 `0045» 在任務/劇情情境不同；`003F» 確認可能早於全部清理。 | 把 003F 當任務獎勵領取 ACK 或 Main 已完整結束。 |
| T16/T14/T07 `C-T01-20261028-06-quest-vs-scene» | Request/Demand、local scenario14 flag、script1000/14、Quest16 完成為不同概念；必要時引用 T16 已錄資源與 Lua 靜態研究。 | Scenario 14 flag=1 直接表示 Quest16 已持久化完成。 |
| T07 `kr-T07-T01-20261027-04-resource-domains» | Quest15／STAGE19／Case103／Map191/192 分別為不同 ID 域；chart 座標不能當作合法 spawn。 | 把 Case、Stage、Quest 或 Map 數字直接互換，或從 cluster COUNT 推官方總擊殺門檻。 |
| T16-T01-20261028-06 KR/TC 資源差異 | 跨版本存在 Reward 欄位差異，TC reward value 非 KR 同值；它是版本隔離例子。 | 將 TC reward value 套回 KR、把任務資料數字直接命名為官方發獎公式。 |

### 3. 重要更正清單與衝突解決（不得回退舊說法）

- `C-T01-20261027-03-quest-opcode»：QuestMgr 的 `0064» 和 TUTO `004C» 各歸其 opcode domain；示例 15/1 的 intro 不保證完成。
- `C-T01-20261027-03-manual-compatibility»：v7 使用者觀察只算相容實作里程碑，不屬原版 Client/Server 成功證據。
- `C-T01-20261027-04-story-opcode»：0047 類訊息和 0045、003F 不能互代。
- `C-T01-20261027-04-result-return»：一般結果 0022/type0 不等教學完成 004C；若角色結果分支有效，也可經確認路徑發 0033，不能強迫 payload+9=0。
- `C-T01-20261027-04-background-not-spawn»：0038+3 是結果背景/演出索引，與地圖選擇、出生座標不同；不能靠 EmptyController 及 ready 宣告可以正常行走。
- `C-T01-20261028-06-quest-vs-scene»：scenario14 flag、script scene、Quest 狀態與後端完成／持久化四個觀念須分離。
- T01-20261027-04 `pending.json» 明示正式發獎、004E ID、0038+5、合法村莊 spawn、雙向旅行未閉合；其 `T14» 段仍保留歷史暫停狀態。
- 2026-10-29 以後的 T01 嚴格全文語意審核多聚焦 T08/T10/T16；不能拿別的 Task 的 FULL-PASS 數字代稱 T14 研究通過。共用知識符合「精確主張／子流程」才准入。

## E. WP01-04：AI 本機策略、原生部分事實與未知嚴格分離

| 玩家情境／聲稱 | 來源／實際狀態 | WP02～WP08 可否當原版規則 |
| --- | --- | --- |
| 「最後一隻怪物 HP=0 後 0.75s 自動宣告 scenario14 完成」 | 舊本機 Server/fixture 規則；T14 archived report 與 README 皆明示它是 AI 替代 | **禁止**，沒有原版成功判定、timer/threshold 及權威端證據。 |
| 「進場先把 scenario14/16 標成完成」 | 舊 AI 預設旗標/相容 workaround | **禁止**，可能直接略過原始等待，不等於已實證完整任務與獎勵。 |
| 原生 TUTO 收到 004C/WORD id 後，同 map 對應 key 寫1 | 本輪 BIN 有限指令窗已核對＋T01 限定原生結論 | **可復用有限部分**：只說 Client 本地 flag writer；wire/framing、合法使用時機及回覆匹配仍需查。 |
| IsScenarioEnded(14) 本地輪詢在 TRUE 情形離開等待 | T14 archived Lua/static 觀察；來源是 current-resource-snapshot，不是 pristine KR 或動態觀察 | **部分確認**，需該 Lua carrier、同一 TUTO世代、有效 thread/controller 等條件。 |
| 發 C2S0040(14) 會導致 Server 一定回 S2C004C(14) | 前半局部 sender 可從 BIN 核對；後半為官方 Server 時序未知 | **不可推定**。 |
| 一般副本收到 S2C0022/type0 顯示結果，按流程可送 C2S0033 | T07 保存的定向結果／返回部分主張，本輪另抽查 4A38D0 的 0033 builder | **僅部分確認**；獎勵 payload 語意、角色分支及返回目的地未知。 |
| Quest15/16 已完成、已發獎、已入帳、重複發獎防護 | 不存在完整原生端到端證據；原版 Server 內部不在 Client 靜態可證範圍 | **不能聲稱完成**；Client wire/handler/UI 繼續追，Server 的判定、持久化與 exactly-once 交 S00/T15 設計。 |

### 真正後續缺口的負責方式

- **Client 待逆向（T14）**：goal/objective/result 實際接收端與原始事件 consumer、勝敗 writer、0022 結果字段及獎勵 UI/狀態連結；區分教學與一般關卡。
- **Client 待逆向（跨 Task）**：T02 的正確 wire/framing/dispatcher、T07 的場景及回城路由、T08 的 Actor 生滅事件與 T12 的傷害/死亡訊號；T14 不重寫它們原稿。
- **Server 待開發（S00/T15 等）**：在已證 Client 接口基礎上定義成功判定資料來源、獎勵計算、重複提交防護、交易/保存；不得編造「官方按 0.75 秒完成」。
- **跨功能待整合**：本地 scenario14 flag、完整 quest story gate、一般結果 UI、返回到城鎮與持久化進度，不能因存在局部函式就宣稱串接成功。
- **待遊玩驗證**：原版 Client + 新相容 Server 的完整清怪、戰鬥結束、結算、返回與重登恢復；本輪沒有任何 runtime 證明。

## F. WP02 建議的首批明確入口與可驗收終點

| 優先 | 入口／來源 | 下一步要閉合的問題 |
| --- | --- | --- |
| P0 | T14 `0x4C4F20 → 0x4C2880»、`0x4AA510»、`0x4AA4D0» | TUTO 接收 owner、scenario flag、Lua consumer、request→reply 的可能或不成立關聯；核對長度/分派域，不猜勝利。 |
| P0 | T07 `0x4B9770 → 0x4C43B0 / 0x4C4550 → 0x5877F0» | 一般關卡結果來源、完整已使用的 0022 payload、UI state8 與 objective/win/fail state 的關係；釐清有無 reward parser。 |
| P0 | T07 `0x4A38D0» 及結果角色分支 | 送 0033 以前的 gate／按鍵路由、是否額外獎勵確認、Server 回覆及返回；不跨入 T07 的城鎮載入主責。 |
| P1 | QuestMgr `0x5020B0/0x5030C0»、T16 story gate | 0064 及 task/scene ID 域不能和 004C 混用；何者是 quest 狀態而非 stage result。 |
| P1 | T08/T12 擊倒／移除訊號 | 找出原生關卡目標 writer 真正收哪些事件，是否來自 Server；別以 HP0、消失通知直接替代勝利判定。 |

**WP01 完成範圍**：來源定位、版本校驗、局部 bytes 及 T01 更正/AI 隔離已完成。WP02 的完整目標事件流、WP03 勝敗規則、WP04 wire 封包、WP05 獎勵內容與其他交接仍未完成。後續研究時若 main 出現 T14 的正式 T01 NEEDS_FIX 或 S00 RR，依新快照與正式優先序調整，不在此自建第二套 RR 台帳。

## G. 核對入口與再現說明

- GitHub 基準檔：「[T14 README](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/tasks/T14/README.md)」、「[T14 task.json](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/tasks/T14/task.json)」、「[T14 派工收件箱](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/research/dispatch/inbox/T14.md)」與「[RR 台帳](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/research/requests/index.json)」。
- T01 有界接受/更正：「[20261027-03](https://github.com/we88ec3-prog/ttr_anal_multi/tree/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/shared/integrations/T01-20261027-03)」、「[20261027-04](https://github.com/we88ec3-prog/ttr_anal_multi/tree/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/shared/integrations/T01-20261027-04)」、「[20261028-06](https://github.com/we88ec3-prog/ttr_anal_multi/tree/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/shared/integrations/T01-20261028-06)」；新嚴格 FULL-PASS 依 `shared/verified-knowledge/README.md» 及 T01 policy。
- 本地重現原件：使用已核對 SHA 的 `Tartaros.bin»，對 section .text 計算 `raw = VA-0x401000+0x400»，以唯讀 raw slice + objdump `-D -b binary -m i386 -M intel --adjust-vma=0x<VA>» 查看。注意切窗不能代替追完整函式控制流程；禁止把 EXE、BIN、KR、TC 地址混套。
- 本報告的原始 BIN、EXE、STP 未上傳 repository；僅提交本 Task 的研究筆記。
