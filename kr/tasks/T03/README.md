# T03 登入與角色選擇

## T01 驗收退回事項

### T01-RETURN-T03-006-LAYOUT-001 — READY_FOR_REVIEW

- 原稿：`kr-temp-roy/20261028-223919-chatgpt-web-roy-T03-6-wsasend-completion-boundary.md`；Git blob `28dc1c2e3e962c85e0187d75d219b9da5ec253aa`；SHA256 `81d1bedd74633751c874d571a45ba99ed7eced38081dd31f217debba41eb2e72`，已原樣保存。
- 問題：第78行把 `channel+0xA050` 稱為 WSABUF 位置、`+0xA0B8` 稱為 overlapped context，混淆 API 引數與計數器位置。
- 原始反證：`8068DE lea eax,[esi+A050]`、`8068F3 push eax` 提供 OVERLAPPED；`8068F7 lea ecx,[eax+14]`、`806909 push ecx` 提供 WSABUF 指標，即 connection+A064。`806961/80697A` 計算 +A0B8，`806968/806981` 呼叫 IAT `BD2284=InterlockedIncrement`，並非把 +A0B8 傳給 WSASend 的 OVERLAPPED 引數。
- 修復要求：保留原稿，提供勘誤／新版本與新 blob／SHA；分離 OVERLAPPED、WSABUF 與 atomic-counter 地址，查對第78、124、145、198行等沿用命名，維持 frame-relative 與 connection-relative 基準區別。原稿獨立成立的 return/pending、completion 及業務未知界線保留，不把全部內容判為錯誤。
- 完成條件：T01 對新版本及全部受影響的引數／基準／completion 描述定向複驗後才 RESOLVED；本批只建立精確 R2 退回，不宣稱原稿全文已驗收。

- **2026-10-31 T03 作者勘誤已提交，請 T01 定向複驗（READY_FOR_REVIEW，非 RESOLVED）**：完整修訂版 [T03-6 corrected](../../../kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-W01-T03-6-corrected.md)；新 Git blob `a6dd610f285786906915306eec072b7042821399`；23 處 KR 原始 BIN bytes／PE32 靜態檢查 PASS，驗證器 [verify](../../../kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py)（blob `bd6e98f76b172912e1244f5f77796d8e1b351927`），W01～W04 含逐行修正、來源索引、審核與 Client/Server 界線的 [完整 A 報告](../../../kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-W01-W04-evidence-review.md)（blob `b552078d504daf169f0c08b027f7751fed25eb0a`）。原始報告 `28dc1c2e3e962c85e0187d75d219b9da5ec253aa` 不變。原始 send OVERLAPPED=connection+A050，WSABUF=+A064，InterlockedIncrement counter=+A0B8；recv OVERLAPPED=+A030，WSABUF=+A044。T01 須複驗第78/102/124/145/149/198行、pointer 基準與 completion/dataflow；**只有 T01 可改 RESOLVED**，本次不宣稱 FULL-PASS。

- 驗收來源：[原件 PE import、既有 REA/Ghidra CFG 與 bytes 定向核對](../../../research/handoffs/t01-t03-roy-20261029/r2-evidence.json)；[重現腳本](../../../research/handoffs/t01-t03-roy-20261029/check_r2.py)。

### 2026-10-29 T01 新通道收件（不等於全文通過）

`t03/roy/chatgpt-web@6dc876e84358c1f1ab343ce5b8899006574ddf26` 的 LOGIN-01／02、T03-3～19 共19篇已保留原始 blob、完成有限主張與既有衝突／更正查對。[交接與各篇處置](../../../research/handoffs/t01-t03-roy-20261029/README.md)。T03-18 的 Print Screen／D3DX 更正已連回15～17：局部 stack 事實不自動成為選角回覆／worker parent 來源。所有新原稿全文歷史狀態維持 PENDING，未新增 FULL-PASS；RR／S00 接受與 Task owner 均未改。

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**每次開工必讀**：確認最新 origin/main SHA，先檢查本 README 的 T01 驗收退回與既有主責，再讀 [T03 S00 收件箱](../../../research/dispatch/inbox/T03.md)、[唯一 RR 台帳](../../../research/requests/index.json)、[派工／認領／回報規則](../../../research/dispatch/README.md)。先處理已指派且獲使用者授權的 P0/P1；只在認領變更發布於 main 後才算跨 Agent 已認領。完成研究需提交 Markdown + 精確 Git blob SHA 並更新 RR 為 SUBMITTED，S00 才能結案。**收件箱不會自動喚醒本 Agent**；不變更原有 Task owner、原稿及 T01 退回規則。


狀態：bounded-review-handoff；負責人 roy；定向離線審核進行中。

## 範圍

登入選服選角與連線切換；不決定角色世界內初值

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：官方驗證規則與完整登入順序缺失；本機帳號規則是替代實作
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。官方驗證規則與完整登入順序缺失；本機帳號規則是替代實作
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

目前依賴：T02、T04、T05、T06（初版僅列T02，後續依角色資料、場景與資源界面增列）。先核對SHA及更正，再向整合者登記具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [16-account-character-roster.md](../../../unclassified/evidence/292f798fe04079370dd65d31a03b7cca5a14a84a9524da3903a25d6ff6c10047.txt)
- [09-login-protocol.md](../../../unclassified/evidence/2b1f41d382423fd4cfd24102920730e0af4ccb211b11877a4f72f76faf5692f7.txt)
- [native-index/login-module-command-parser.txt](../../../unclassified/evidence/2cf621bbf71d306f38b21b2bd70fd82a31b92fcebff95912c21cd47c3fd8c951.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [audit_login_module_command_line.py](../../../kr/evidence/31a96a34214d44d09f2c5c6d16066da2bea5a9312a5d7061da19c419af1758a6.txt)
- [native-index/login-module-endpoint-initializer.txt](../../../unclassified/evidence/485041721397e0db11328939517849f8b0755166a326d96881b34284022046de.txt)
- [native-index/login-module-auth-command-000f.txt](../../../unclassified/evidence/4cb0b42cbee49f5e05fff20c2ff5f5eca257c24c0fbe060371bc59ec0e1177e8.txt)
- [06-runtime-login-fix.md](../../../unclassified/evidence/4d4a53d916b03a6766d33001449ed765af88a1cd1088471dc5bd2b4c6e0c72db.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [native-index/login-module-gsp-constructor.txt](../../../unclassified/evidence/5132ac5f0b3be3b23c6873ee0ad08435d0e66c438f7d8929ad457548ea92905c.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/login-module-auth-dispatch.txt](../../../unclassified/evidence/9e426b693565220e79df086be2546a876b57de7e42fee9986121d10f941e8d5b.txt)
- [LOGIN-MODULE-COMMAND-LINE-AND-AUTH.md](../../../kr/evidence/a888e1ad136c9548255924ebd455847b05f6e9ce5e560f8a46d00b2b0826cde9.txt)
- [native-index/login-module-singleton-getter.txt](../../../unclassified/evidence/b110e18c90fc68d61fb96a5c8bb7b97bd1436cd507800942d52a2e0a542e9af0.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/login-module-ip-formatter.txt](../../../unclassified/evidence/c2348e529f4b85b2db1aaa48bc48bbdfe0e252369c2900412f460532a7af5ef9.txt)
- [native-index/login-module-auth-command-00e8.txt](../../../unclassified/evidence/d4184e747c61654be90f36a379cb745f17e882bcf67fdcd266156acb53a84360.txt)
- [native-index/login-module-command-audit.json](../../../kr/evidence/e24230acf525e80f0bc15af6b510eab1aed53b21e7131790c1ca0fc5229d7230.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。

## roy 增量審核（2026-10-24）

已整合身分／指定位置位元組核對與本機替代覆蓋審核；原有結論保留。完整登入、選服、選角及官方後端仍未驗收。

- [輸入SHA與本機實作摘錄](../../evidence/4a5bd1ed63444e64184b9f89c117fd656ea0d25d2821a32af900dc01550fa70f.txt)
- [獨立原生位元組核對](../../evidence/c6adc7cdb2322c3308942c916400b9a4a033ed422fdfbd483a307bbdccb5ce92.txt)
- [有限審核與遊玩缺口](../../evidence/e0b62afa81cceeb79f321bb4f99078d3d7c30df8f9f221d5262f49b5eca6179b.txt)

### 本機登入入口補證

已補得與歷史SHA相符的本機 server 來源。E8/112是該登入回應分支的條件；未證實目前部署或其他入口行為。

- [入口補證與成立條件](../../evidence/3ff02585ce5c57b656f523c3900b16ada0fec3e6a17da0f8dd62904ec607d4ab.txt)

- [單一parser清單與原檔獨立核對；非語意完成驗收](../../evidence/943f31d6340a9c587217c714379145e890c9351db7fb3d14eb1feed3620e7054.txt)

### 新原生parser證據與範圍更正

REA6.5.0/Ghidra12.1.4已對同SHA原檔取得新證據，確認上述mode40/52/54分支與共同旗標寫入；完整helper、認證封包欄位、官方驗證和端到端流程仍未完成。舊827-byte範圍是位元組外包區間，Ghidra body為兩段inclusive範圍，中間3-byte間隔保留在舊清單但不屬此次body。

參照字串中的vector<T> too long及第三marker的中段不是實際比較起點；應查核0xbf2375/0xbfafd8原始位元組，避免引用Ghidra typed-string片段誤認marker。

- [完整REA原始Evidence](../../evidence/f49a85150d89c0a56a97db39a65f7ccb0a6c54b7f95656b783545c74531a5eaf.txt)
- [分支、body範圍、literal起點與限制](../../evidence/a15c2bfd5f748825455fe394fa5e891052be8afe416a7312f9af50d01dfdfe9b.txt)

## roy 認證／結果／選服資料增量

已核對同SHA原生E8/000F的不同字串寬度、轉碼與MD5文字鏈、0x13結果消費者、group/channel格式及register參數。split空token與marker來源亦有新依據。官方驗證、實際切線、完整選角/轉場與世界初值仍未驗收；本機固定值與後端政策保持AI替代標記。

- [原生資料流、欄位與AI／缺失界線](../../evidence/602d11a657a2e8a3dc53cff4664f837d579cd6cb187311b2c4c7070e994887d9.txt)
- [逐項驗收、原始Evidence SHA與限制](../../evidence/21a4fdb1221faa5cda5234257637a36e3e7024897a56ccb4f5eca585d2bc7e15.txt)

## roy 增量：選角UI界面與依賴

依同SHA原生證據整合有限結果；原結論保留，完整登入/選角/切線/世界流程仍未驗收。

- [觀察、成立條件、未知與遊玩影響](../../evidence/fb492350630034ed67084cebd4c046a9701c844905bb8a1049eb79608963f33c.txt)
- [逐項驗收與Evidence定位](../../evidence/f6fa5c69ab356015dedaf4f65b2d40d506400a3095e2e2d4d36c4cdc8854e916.txt)

接口依賴（只引用主責成果）：T02 slot0 connection/send timing; reference only；T04 availability record+5C writer/initial data; reference only；T05 actual plaza/scene transition and response preconditions; reference only；T06 same-version UI resource/control identity and provenance; reference only。

## roy 增量：選服查詢與切線呼叫介面

依同SHA原生證據整合有限結果；原結論保留，完整登入/選角/切線/世界流程仍未驗收。

- [觀察、成立條件、未知與遊玩影響](../../evidence/f395aec4f8fcf3fec73ef57df8cf77182791582b85113eedf56d23441b5aa031.txt)
- [逐項驗收與Evidence定位](../../evidence/9883c777bcdaeee5c106f5c5d1d8980811c552c9991dd451f6de73b3ef4328a1.txt)

接口依賴（只引用主責成果）：T02 selected row+C interface, connection/framing/timing reference only；T04 availability record/initial data provenance reference only；T05 scene transition and response preconditions reference only；T06 same-version UI resource/control identity reference only。

### 目前接續位置

parser/auth、角色UI與選服呼叫介面的有限審核已整合；較早段落的「helper仍未完成」是當時進度，現況以上述增量審核與task.json為準。仍需角色清單到UI業務橋接、F42EF/F4247消費者定位，以及T02/T04/T05/T06依賴回補。完整原生語意與可玩流程仍未驗收。整合者已確認既有roy登記及本輪四項選服方法；確認不等於語意驗收。

## roy 增量：角色清單到UI可用旗標的資料橋接

依同SHA原生證據整合有限結果；原結論保留，完整登入/選角/切線/世界流程仍未驗收。

- [觀察、成立條件、未知與遊玩影響](../../evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt)
- [逐項驗收與Evidence定位](../../evidence/eae13472309c2ee5bbe4b9c3f2f3a1be0692dff54b099cc19ef685843177ab19.txt)

接口依賴（只引用主責成果）：T02 Shared dispatch/table/connection reference only;4B7DC0 corrected toT02 ownership；T04 Actual roster/world initial values and authority; no synthetic value promotion；T05 Scene/command60 and post-selection transition preconditions；T06 Same-version resource presence/control identity; pre-roster lookup prerequisites。

## roy 增量：選角UI更新入口與F4247局部消費者

依同SHA原生證據整合有限結果；原結論保留，完整登入/選角/切線/世界流程仍未驗收。

- [觀察、成立條件、未知與遊玩影響](../../evidence/aa769d397c649ca9d59931b53b074ab0ac2fd599d53082884743e2bd73a4b5a0.txt)
- [逐項驗收與Evidence定位](../../evidence/e02e4e01183dfdb49c00558a66c2f0234a2ca946a12ca2c6ba9ae25cf95f2bb9.txt)

接口依賴（只引用主責成果）：T02 network dispatch/delivery/timing reference only；T04 actual roster/world data authority and initial values；T05 actual scene transition and preconditions；T06 resource/control identity, dialog subscription and display provenance。

## roy 增量：角色清單補證後的全T03缺口與開發交接

依同SHA原生證據整合有限結果；原結論保留，完整登入/選角/切線/世界流程仍未驗收。

- [觀察、成立條件、未知與遊玩影響](../../evidence/2bc7c2d0630718f3610e1e9f1644a5dca853c0cc1f8b969b7dded9c0c0e65915.txt)
- [逐項驗收與Evidence定位](../../evidence/301a256b5796eba01034f3f69b2d75ccc8cfe6b6252467445a1e3a1c89055d37.txt)

接口依賴（只引用主責成果）：T02 network dispatch/delivery/timing reference only；T04 actual roster/world data authority and initial values；T05 actual scene transition and preconditions；T06 resource/control identity, dialog subscription and display provenance。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


## S00 Phase B 設計整合參照（extra/roy1，尚非 T01 原生全文驗收）

2026-10-29：參照 `extra/roy1` 的 E01–E16 SceneList/Lua/教學場景研究，原始 Git blob 完整保留於 `kr-extra-roy/`。S00 只抽取 E06/E08/E13/E16 的有限來源主張，將其與已存在的 T03 登入/選角證據分開；見 [來源整合說明](../../../governance/PHASE-B-T03-EXTRA-ROY1.md)、[跨流程草案](../../../spec/session-account/SPEC-FLOW-0001.md) 與 [場景依賴草案](../../../spec/world/SPEC-SCENE-0001.md)。

**未證明**選角 C2S `0x42` 對應的 S2C 回覆會設定 `(questIdx=1001,sceneIdx=1)`，亦未證首次登入必進教學；E16 對 `0x565720` 的 EndCutScene 重入提供反證。下一項 T03 定向補證為 [RR-0008](../../../governance/T03-S00-AGENT-REQUESTS.md)，不用重新執行整批 E01–E16。這個註記不改 Task owner、原稿、過去 T01 裁定或正式 FULL-PASS 准入。

## T03-B 登入認證工作包 W05～W08（2026-10-31，Client bounded static）

- 完整 KR BIN-first 技術原稿：[T03-B W05～W08](../../../kr-temp-roy/20261031-182406-chatgpt-web-roy-T03-B-W05-W08-auth-BIN-first.md)；Git blob `e5463936b7b48421219c0e0c83d5d4bf9b07b09f`。
- 64 項原始機器碼位置及 PE、vtable、direct-xref、zero-tail 的唯讀驗證器：[T03-B verify.py](../../../kr-temp-roy/20261031-182406-chatgpt-web-roy-T03-B-verify.py)；Git blob `d7f83bb2b8d71e3bcc3d39e2b7ed481cd5773f88`；本輪同版 BIN 實測 PASS。
- 方向／狀態／UNKNOWN 機器交接：[T03-B handoff.json](../../../kr-temp-roy/20261031-182406-chatgpt-web-roy-T03-B-handoff.json)；Git blob `e59efc2d202665c28b285ad1159d009591d96521`。
- W05：`0x6D6300` 物件 constructor 設 mode+8=0x52，vtable+0x30 指向 `0x440790`；本地 0x52→E8/112B，0x54 或其他→000F/214B；**不代表 launcher 總是選此 mode**。
- W06：E8+104..109 仍無直接初始化 writer；全域 FBA808 在 .data virtual-zero tail、7 個直接位址 xref 為讀取；E8 WCTMB CodePage=0。實際六 bytes／執行時 setter/ACP 未閉合。
- W07：LOGIN scene S2C13 status5／0+非空名稱／其它三種結果、S2C7A group cursor 的獨立布局、group 3+10N、local F4243。
- W08：0x13 達局部狀態更新，+90=0 才 F4241，本地事件非 wire；另需 UI gate 才有條件 key0/key2 Connect，**不證官方原版 first S2C/實際配對**。
- 此研究不重複提交 RR-0003（主線正式台帳 `IN_REVIEW`），不變更 `GAP-AUTH-0001 OPEN` 或 `SPEC-AUTH-0001 / SPEC-FLOW-0001 DRAFT/PARTIAL`；T01 FULL-PASS 和 S00 acceptance 尚未取得。完整 Client 靜態研究交付與原版 Server 動態未知明確分流。

## T03-C W09～W12 選服、頻道與多 Conn（2026-10-31）

- **完整 KR BIN-first 研究**：[C W09～W12](../../../kr-temp-roy/20261031-183619-chatgpt-web-roy-T03-C-W09-W12-server-channel-native.md)（原稿 Git blob `499da1dad76d213ce79a938f17ead817d3f0ee00`）；原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原件唯讀核對 113 個指令起點，均 PASS；同目錄另附具代表性 72 處指令的 [驗證器](../../../kr-temp-roy/20261031-183619-chatgpt-web-roy-T03-C-verify.py) 與 [Server handoff JSON](../../../kr-temp-roy/20261031-183619-chatgpt-web-roy-T03-C-handoff.json)。
- **W09**：`S2C13 +1C/+92` 與 `S2C7A +2/+6` 共享 `4C3080`，每 group 3B、每 row 10B；IPv4 `row+4..7`、`row+8` append gate、`row+9` 有效參數、`507610` composite lookup、`507750/5078C0` 0x60 本地 child record。`66B910` 局部 UI 刷新功能可見，但 `F4243` 所有 event listeners 未正向窮盡。
- **W10**：`66C620` 以 local `0x709` (f0 refresh)、`0x70A` (f4 record→`66C090`)、`0x578` (f8 alternative resolver) 各比 control identity；`66C090` 兩次映射與 `F94294` gate，條件符合才可能呼叫 `4957C0`，不是必發 C2S 專用 command。
- **W11**：key1/port 8415→`Client+BF60`；key0/port8416→`+BF64`；key2/port8414→`+BF68`。兩次 Connect 返回有效後，可能清原 key1，再對 key0 本地 enqueue 0x39B app0x0001；不能宣稱原版 Server 已接收。
- **W12**：zero group / row8=0 / NULL mapping / 控件不符 / key0或key2失敗時的本地分支與成功側 Conn cleanup；**此 helper 沒有 timer auto-retry**，全域 retry/取消/回登入 UI 沒有完整閉合，保留 Client 待補查。
- 本次 C 為既定 T03 計畫的有界研究交付，**沒有新增/變更正式 RR 台帳、S00 SPEC 或 GAP**；原主線 `RR-0003=IN_REVIEW`、`RR-0002=BLOCKED`，T01 FULL-PASS 與 Server 可玩仍為獨立驗收。T02 transport與T06 layout維持原 owner。

## T03-D W13～W16 — 遠征隊命名／Account/Expedition/Role 分離（2026-10-31）

- [完整 D BIN-first 研究原稿](../../../kr-temp-roy/20261031-184654-chatgpt-web-roy-T03-D-W13-W16-expedition-native.md)；Git blob `dbbf1537a8d1c784c80b4b7b9a8bba7a6e686e01`，KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本次在原件唯讀重新核對 **121/121 個 native 指令起點**、4 個 vtable slots、3 個 RTTI identity、4 個 direct-E8 caller sets；靜態驗證不等於 T01 FULL-PASS。
- [自足 121-checkpoint 原生驗證器](../../../kr-temp-roy/20261031-184654-chatgpt-web-roy-T03-D-verify.py)；blob `411b1fe354d15f9625201cc4745b3e150344301a`。[S00/T03 交接 JSON](../../../kr-temp-roy/20261031-184654-chatgpt-web-roy-T03-D-handoff.json)；blob `cbd1a949a387446b63dbd1ffd70447143985d04b`。
- **W13：有界部分研究與明確 blocker。** S2C app0x0002 (65+53N) N=0 僅跳 role loop；header+0x0C 的 UTF-16 name 可寫 `F938F2`，非空時 `CExpeditionPage::5A6510` 有條件設 page+0x144 ready；`5A65A0` 更新三個控件。**N=0→真正可見 CExpeditionCreateDialog open/control/scene/resource 正向鏈仍未閉合**，交 T03/T06 繼續；不得稱已驗 GUI 自動開啟。
- **W14：Client 本地建名 sender。** `CExpeditionCreateDialog` vtable slot87 `0x671FD0`、event0x578/button identity/local F4244/0x6A7→name validation→`C2S app0x003E` **48B slot0**，name UTF-16LE+6（容量21 WCHAR）、`+2..5 UNKNOWN`、`FBA798==0` queue gate；不是外框完整 TCP bytes。
- **W15：scene-specific 結果 consumer。** `S2C app0x004A→0x4C21D0` 的 signed WORD+2→local `F4245`→`CExpeditionPage` 和 `0x672570`，status1 寫 `F938F2` / page ready，-1/-2/-3 錯誤各有分支。**原版 Server C2S3E↔S2C4A 交易配對仍 UNKNOWN**，不得推定官方 error enum。
- **W16：三層身份界線。** Account auth、Expedition 名稱 `F938F2`、可操作 Role 陣列 `F94304+slot*0x210` 互不等同；S2C app2 與 app2B 共享 RoleStore，`CEmployNewCharacter→C2S0x33` 是另一類 UI／請求，既有角色選角 `C2S0x42` 也不是建名 ACK。
- 主線正式 RR-0009 仍 `SUBMITTED`、RR-0010 `BLOCKED`；T01、S00、GAP-CHAR-0002/0003、其他 owner 狀態均未因本次作者提交而更改。未執行 Client，未推送 main。下個 E W17～W20 才追 roster 全量/增量/角色 UI；F 工作包追可操作角色的真正建立／招募。

## T03-E W17～W20 — KR 全量／增量角色清單與 UI（2026-10-31）

- **完整本次 BIN-first 原生證據**：[T03-E W17～W20](../../../kr-temp-roy/20261031-T03-E-W17-W20-roster-ui-native.md)；Git blob `5bf17fd8078344bb41a26e8de956b2ec23843731`。原始 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪自原件核對 485/485 個已定位 native instruction bytes；**不是 485 個語意 FULL-PASS 或 Client runtime**。
- [485 項自足原生 verifier](../../../kr-temp-roy/20261031-T03-E-verify.py)；Git blob `f3e8e73a93cb10ea920474ccacd563a3598a0230`。[機器可讀 handoff JSON](../../../kr-temp-roy/20261031-T03-E-handoff.json)；Git blob `eedf0b418e08feef69ef0c2ba307a48d0536fb7f`。
- **W17 full S2C app0x0002**：65B prefix+53N，除 +0x0C Expedition name 外另有多個來源未命名欄位；53B row+0x2E ID<=9 才 `4D4150` 寫 `[F94304]+ID*0x210`（+0x5C=1）；但 full loop **即使 ID>9 仍可能因 gate queue 每筆 C2S0x26(3B)**，最後另可 queue C2S0x24(2B)，並寫本地 `F94240` 16-bit mask。
- **W18 delta S2C app0x002B**：已循 16B network table→singleton vptr→8B業務 table→`4E2730` 正向定位；2B+53N，寫同一 `F94304`（`F8D9E0+0x6924`）角色記錄，但此 handler 不重發 full 的 per-row 26/post24/mask；RoleStore ctor 初始10×0x210、+0x5C=0，writer令1，**兩個 handler 沒有省略 slot 就清全部舊角色的保證**。
- **W19 UI**：S2C B6→local F4278(0)→具條件 CExpeditionPage→`672F00` 讀 role flag，有資料/placeholder 分叉；另 local F42EF→`665150` 的回傳1可只代表 list-hit，**不保證 detail 已填、Client已允許該 role**。
- **W20 選角 gate**：record+0x5C、full mask F94240、列表 hit 與 UI 選角 index 各為不同狀態。玩家控件正確且 index<=9、record flag1 才可達 `4A3B80` C2S0x42；**Server S2C 結果／場景切換另屬 G/T05**。
- **正式 S00 狀態同步**：在研究期間主線 `ac3aa886e9fd20be93b6f841ada66fe22e587aa1` 限定 `RR-0009=ACCEPTED`（只接受 E70 提出的第5條原生 blocker/解除條件，**N0→創角 GUI 仍未證**）；`RR-0010=BLOCKED`、`GAP-CHAR-0002/0003 OPEN`，SPEC仍 DRAFT/PARTIAL，T01 原生 FULL-PASS未授予。本次只同步 main 後提交 T03 分支，不更動 RR/T01/S00 主責或原版 Client。

## T03-F W21～W24 — 可操作角色招募候選、多入口 C2S33、F431F 與結果缺環（2026-11-01）

- [完整本批 BIN-first 研究 Markdown](../../../kr-temp-roy/20261101-014512-chatgpt-web-roy-T03-F-W21-W24-native.md)；原稿 Git blob `51e4ff7a267ffe64a8ed67a4453d1672f3018d63`；同 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本地從原件核507/507個已定位 native指令起點，**不是T01 FULL-PASS**。
- [重跑 verifier（15個exact native code-range SHA + 32個關鍵指令 slices）](../../../kr-temp-roy/20261101-014512-chatgpt-web-roy-T03-F-verify.py)；blob `04daf13a1f38deb245a144f22b01266847819b49`。[Server/T03機器交接 JSON](../../../kr-temp-roy/20261101-014512-chatgpt-web-roy-T03-F-handoff.json)；blob `233bc053cddadae0ec0920b7f3db783ba4b548a0`。未執行Client/Server。
- **W21 重要新正向：C2S app0x0033共有至少三個本地 sender**：`CEmployNewCharacter event0x578 + control identity + Client+5F4C!=1 → 6BF2FA→4A38D0`；`F431F result0 → 5AAE80 inline 33`；`6BA730 param0x0D → 6BA360 inline 33`。三條 payload同為 `33 00`／2B／slot0，受`FBA798==0` manager queue gate；不是已證新人可玩角色建立語意，也不是完整wire frame。`Client+5F4C==1` 原 Employ入口走`6BFAE0` local UI，不走此`4A38D0` sender。
- **W21 本地事件**：`F431F` 至少由`4A98D0`和`6BA2C0`產生，後者讀`[FE18F8]+0x29` 作local result；`5AAE80`消費它。**producer/consumer 的實際scene/listener binding仍缺正向鏈**，F431F不是Server ACK。`6BF310` 角色詳細資料需index<=9、RoleStore`record+5C !=0`及resource/控件有效。
- **W22／W23 仍未閉合**：S2C33初始first-level default、S2C2 full及2B delta共用RoleStore、S2CB6→F4278 UI、S2C4A遠征隊命名結果都已分域核對，**缺可證的同筆C2S新角色建立→專用S2C接受/拒絕→角色record初始化**。重複/取消/斷線/重試完整Client流程未知，不可推原版Server規則。
- **W24 blocker交接**：繼續查F431F事件註冊、FE18F8+29及Client+5F4C writer、6BA730資源/0x0D回呼、S2C33 active scene次級handler、RoleStore revoke/lifecycle；T02/T04/T05/T06按各自owner合作；可靠同KR原官服multiConn trace/verified原服source才能確認官方交易順序。`RR-0010=BLOCKED`、`GAP-CHAR-0003 OPEN`，`RR-0009=ACCEPTED`僅限精確GUI blocker研究；T01/S00正式品質與可玩驗收未提升。
